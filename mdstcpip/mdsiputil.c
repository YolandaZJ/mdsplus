#include "mdsip.h"
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define xxxxUNIX_SERVER

static unsigned char message_id = 1;
Message *GetMdsMsg(SOCKET sock, int *status);
#ifdef _WIN32
Message *GetMdsMsgOOB(SOCKET sock, int *status);
#endif
int SendMdsMsg(SOCKET sock, Message *m, int oob);

static int initialized = 0;
static void FlipHeader(MsgHdr *header);
static void FlipData(Message *m);

static char ClientType(void)
{
  static char ctype = 0;
  if (!ctype)
  {
    union { int i;
            char  c[sizeof(double)];
            float x;
            double d;
          } client_test;
    client_test.x = 1.;
    if (client_test.i == 0x4080) {
      client_test.d=12345678;
      if(client_test.c[5])
       ctype = VMSG_CLIENT;
      else
      ctype = VMS_CLIENT;
    }
    else if (client_test.i == 0x3F800000)
      ctype = IEEE_CLIENT;
    else
      ctype = CRAY_CLIENT;
    client_test.i = 1;
    if (!client_test.c[0]) ctype |= BigEndian;
  }
  return ctype;
}

struct descrip *MakeDescripWithLength(struct descrip *in_descrip, char dtype, int length, char ndims, int *dims, void *ptr)
{
  int i;
  in_descrip->dtype = dtype;
  in_descrip->ndims = ndims;
  in_descrip->length = length;
  for (i=0;i<ndims;i++) in_descrip->dims[i] = dims[i];
  for (i=ndims; i<MAX_DIMS; i++) in_descrip->dims[i] = 0;
  in_descrip->ptr = ptr;
  return in_descrip;
}

struct descrip *MakeDescrip(struct descrip *in_descrip, char dtype, char ndims, int *dims, void *ptr)
{
  int i;
  in_descrip->dtype = dtype;
  in_descrip->ndims = ndims;
  in_descrip->length = 0;
  for (i=0;i<ndims;i++) in_descrip->dims[i] = dims[i];
  for (i=ndims; i<MAX_DIMS; i++) in_descrip->dims[i] = 0;
  in_descrip->ptr = ptr;
  return in_descrip;
}

short ArgLen(struct descrip *d)
{
  short len;
  switch (d->dtype)
  {
    case DTYPE_CSTRING :  len = d->length ? d->length : (d->ptr ? strlen(d->ptr) : 0); break;
    case DTYPE_UCHAR   :
    case DTYPE_CHAR    :  len = sizeof(char); break;
    case DTYPE_USHORT  :
    case DTYPE_SHORT   :  len = sizeof(short); break;
    case DTYPE_ULONG   :  
    case DTYPE_LONG    :  len = sizeof(long); break;
    case DTYPE_FLOAT   :  len = sizeof(float); break;
    case DTYPE_DOUBLE  :  len = sizeof(double); break;
    case DTYPE_COMPLEX :  len = sizeof(float) * 2; break;
  }
  return len;
}


#ifdef _WIN32
typedef struct _EventThread {
	SOCKET sock;
	HANDLE thread_handle;
	DWORD  thread_id;
	int    eventid;
	int    event_count;
	struct _EventThread *next;
} EventThread;

static EventThread *eThreads = NULL;

unsigned long WINAPI MdsDispatchEvent(SOCKET sock);
#endif

int  MdsEventAst(SOCKET sock, char *eventnam, void (*astadr)(), void *astprm, void **eventid)
{
#ifdef _WIN32
  EventThread *et;
#endif

  struct descrip eventnamarg;
  struct descrip infoarg;
  struct descrip ansarg;
  MdsEventInfo info;
  int size = sizeof(info);
  int status;
#ifdef _WIN32
  for (et=eThreads; eThreads && et->sock != sock; et = et->next);
  if (et == NULL) {
	  et =  (EventThread *)malloc(sizeof(EventThread));
      et->sock = sock;
	  et->event_count = 0;
	  et->next = eThreads;
	  et->thread_handle = NULL;
	  eThreads = et;
  }
#endif
  info.astadr = (void (*)(void *,int ,char *))astadr;
  info.astprm = astprm;
  status = MdsValue(sock, EVENTASTREQUEST, MakeDescrip((struct descrip *)&eventnamarg,DTYPE_CSTRING,0,0,eventnam), 
			      MakeDescrip((struct descrip *)&infoarg,DTYPE_UCHAR,1,&size,&info),
			      (struct descrip *)&ansarg, (struct descrip *)NULL);
  if ((status & 1) && (ansarg.dtype == DTYPE_LONG)) {
    *eventid = *(void **)ansarg.ptr;
#ifdef _WIN32
    et->eventid = *(int *)ansarg.ptr;
    if (et->thread_handle == NULL)
    et->thread_handle = CreateThread((LPSECURITY_ATTRIBUTES)NULL, 0, (LPTHREAD_START_ROUTINE)MdsDispatchEvent, (LPVOID)sock, (DWORD)NULL, &et->thread_id);
    et->event_count++;
#endif
  }
  if (ansarg.ptr) free(ansarg.ptr);
  return status;
}

int  MdsEventCan(SOCKET sock, void *eventid)
{
#ifdef _WIN32
  EventThread *et, *prev;
#endif
  struct descrip eventarg;
  struct descrip ansarg = {0,0,0,0};
  int status = MdsValue(sock, EVENTCANREQUEST, MakeDescrip((struct descrip *)&eventarg,DTYPE_LONG,0,0,&eventid), 
			      (struct descrip *)&ansarg, (struct descrip *)NULL);
  if (ansarg.ptr) free(ansarg.ptr);
#ifdef _WIN32
  for (prev=NULL,et=eThreads; et && (et->sock != sock); prev = et,et = et->next);
  if (et) {
	et->event_count--;
	if (et->event_count == 0)
		TerminateThread(et->thread_handle, 0);
      if (prev)
		  prev->next = et->next;
	  else
		  eThreads = et->next;
  }
#endif
  return status;
}

#ifndef _WIN32
void MdsDispatchEvent(SOCKET sock)
#else
unsigned long WINAPI MdsDispatchEvent(SOCKET sock)
#endif
{
  int status;
  Message  *m;
#ifndef _WIN32
  if ((m = GetMdsMsg(sock,&status)) != 0)
#else
  while ((m = GetMdsMsgOOB(sock,&status)) != 0)
#endif
  {
    if (status == 1 && m->h.msglen == (sizeof(MsgHdr) + sizeof(MdsEventInfo)))
    {
      MdsEventInfo *event = (MdsEventInfo *)m->bytes;
      (*event->astadr)(event->astprm, event->eventid, event->data);
    }
#ifdef MULTINET
    sys$qiow(0,sock,IO$_SETMODE | IO$M_ATTNAST,0,0,0,MdsDispatchEvent,sock,0,0,0,0);
#endif
  }
#ifdef _WIN32
  return 0;
#endif
}

static SOCKET ConnectToPort(char *host, char *service)
{
  int status;
  SOCKET s;
  static struct sockaddr_in sin;
  struct hostent *hp;
  struct servent *sp;
  static int one=1;
  long sendbuf = 32768,recvbuf = 32768;

  hp = gethostbyname(host);
#ifdef _WIN32
  if ((hp == NULL) && (WSAGetLastError() == WSANOTINITIALISED))
  {
	  WSADATA wsaData;
	  WORD wVersionRequested;
	  wVersionRequested = MAKEWORD(1,1);
	  WSAStartup(wVersionRequested,&wsaData);
	  hp = gethostbyname(host);
  }
#endif
  if (hp == NULL)
  {
    int addr = inet_addr(host);
    if (addr != 0xffffffff)
    hp = gethostbyaddr((void *) &addr, (int) sizeof(addr), AF_INET);
  }
  if (hp == NULL)
  {
    printf("Error in MDSplus ConnectToPort: %s unknown\n",host);
    return INVALID_SOCKET;
  }
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == INVALID_SOCKET) return INVALID_SOCKET;
  if (atoi(service) == 0)
  {
    sp = getservbyname(service,"tcp");
    if (sp != NULL)
      sin.sin_port = sp->s_port;
    else
    {
      char *port = getenv(service);
      port = (port == NULL) ? "8000" : port;
      sin.sin_port = htons((short)atoi(port));
    }
  }
  else
    sin.sin_port = htons((short)atoi(service));
  if (sin.sin_port == 0)
  {
    printf("Error in MDSplus ConnectToPort: Unknown service: %s\nSet environment variable %s if port is known\n",service,service);
    return INVALID_SOCKET;
  }
  sin.sin_family = AF_INET;
  memcpy(&sin.sin_addr, hp->h_addr_list[0], hp->h_length);
  status = connect(s, (struct sockaddr *)&sin, sizeof(sin));
  if (status < 0)
  {
    perror("Error in connect to service\n");
    return INVALID_SOCKET;
  }
  else
  {
    int status;
    Message *m;
#ifdef _WIN32
	static char user[128];
	int bsize=128;
	char *user_p = GetUserName(user,&bsize) ? user : "Windows User";
#else
    static char user[L_cuserid];
    char *user_p;
    user_p = (cuserid(user) && strlen(user)) ? user : "?";
#endif
    m = malloc(sizeof(MsgHdr) + strlen(user_p));
    m->h.client_type = 0;
    m->h.length = strlen(user_p);
    m->h.msglen = sizeof(MsgHdr) + m->h.length;
    m->h.dtype = DTYPE_CSTRING;
    m->h.ndims = 0;
    memcpy(m->bytes,user_p,m->h.length);
    status = SendMdsMsg(s,m,0);
    free(m);
    if (status & 1)
    {
      m = GetMdsMsg(s,&status);
      if (!(status & 1))
      {
        printf("Error in MDSplus ConnectToPort connect to service\n");
        return INVALID_SOCKET;
      }
      else
      {
        if (!m->h.status)
        {
          printf("MDSplus ConnectToPort: Access denied\n");
          free(m);
          DisconnectFromMds(s);
          return INVALID_SOCKET;
        }
      }
    }
    else
    {
      printf("MDSplus ConnectToPort: Error in user verification\n");
      return INVALID_SOCKET;
    }
  }
  setsockopt(s, SOL_SOCKET,SO_RCVBUF,(void *)&recvbuf,sizeof(recvbuf));
  setsockopt(s, SOL_SOCKET,SO_SNDBUF,(void *)&sendbuf,sizeof(sendbuf));
#ifndef _WIN32
  setsockopt(s, SOL_SOCKET,SO_OOBINLINE,(void *)&one,sizeof(one));
#endif
  setsockopt(s, IPPROTO_TCP, TCP_NODELAY, (void *)&one, sizeof(one));
#ifdef MULTINET
  sys$qiow(0,s,IO$_SETMODE | IO$M_ATTNAST,0,0,0,MdsDispatchEvent,s,0,0,0,0);
#endif
  return s;
}

SOCKET  ConnectToMds(char *host)
{
  char hostpart[256] = {0};
  char portpart[256] = {0};
  sscanf(host,"%[^:]:%s",hostpart,portpart);
  if (strlen(portpart) == 0)
    strcpy(portpart,"mdsip");
  return ConnectToPort(hostpart,portpart);
}

SOCKET  ConnectToMdsEvents(char *host)
{
  char hostpart[256] = {0};
  char portpart[256] = {0};
  sscanf(host,"%[^:]:%s",hostpart,portpart);
  if (strlen(portpart) == 0)
    strcpy(portpart,"mdsipe");
  return ConnectToPort(host, "mdsipe");
}

int  GetAnswerInfo(SOCKET sock, char *dtype, short *length, char *ndims, int *dims,
 int *numbytes, void * *dptr)
{
  int status;
  Message *m;
  int i;
  *numbytes = 0;
  m = GetMdsMsg(sock, &status);
  if (status != 1) return 0;
  if (m->h.ndims)
  {
    *numbytes = m->h.length;
    for (i=0;i<m->h.ndims;i++)
    {
#ifdef __CRAY
      dims[i] = i % 2 ? m->h.dims[i/2] & 0xffffffff : m->h.dims[i/2] >> 32;
#else
      dims[i] = m->h.dims[i];
#endif
      *numbytes *= dims[i];
#ifdef DEBUG
      printf("dim[%d] = %d\n",i,dims[i]);
#endif
    }
    for (i=m->h.ndims;i < MAX_DIMS; i++)
      dims[i] = 0;
  }
  else
  {
    *numbytes = m->h.length;
    for (i=0;i<MAX_DIMS;i++)
      dims[i] = 0;
  }
  if ((int)(sizeof(MsgHdr) + *numbytes) != m->h.msglen)
  {
    *numbytes = 0;
    return 0;
  }
  *dtype = m->h.dtype;
  *length = m->h.length;
  *ndims = m->h.ndims;
  *dptr = m->bytes;
  return m->h.status;
}

int  DisconnectFromMds(SOCKET sock)
{
  int status;
  shutdown(sock,2);
  status = close(sock) == 0;
#ifdef __MSDOS__
  WSACleanup();
#endif
  return status;
}

int  SendArg(SOCKET sock, unsigned char idx, char dtype, unsigned char nargs, short length, char ndims,
int *dims, char *bytes)
{
  int status;
  int msglen;
  int i;
  int nbytes = length;
  Message *m;
  for (i=0;i<ndims;i++)
    nbytes *= dims[i];
  msglen = sizeof(MsgHdr) + nbytes;
  m = malloc(msglen);
  m->h.client_type = 0;
  m->h.msglen = msglen;
  m->h.message_id = message_id;
  m->h.descriptor_idx = idx;
  m->h.dtype = dtype;
  m->h.nargs = nargs;
  m->h.length = length;
  m->h.ndims = ndims;
#ifdef __CRAY
  for (i=0;i<4;i++)
    m->h.dims[i] = ((ndims > i * 2) ? (dims[i * 2] << 32) : 0) | ((ndims > (i * 2 + 1)) ? (dims[i * 2 + 1]) : 0); 
#else
  for (i=0;i<MAX_DIMS;i++) m->h.dims[i] = i < ndims ? dims[i] : 0;
#endif
  memcpy(m->bytes,bytes,nbytes);
  status = SendMdsMsg(sock, m, 0);
  if (idx == (nargs -1)) message_id++;
  free(m);
  return status;
}

int SendMdsMsg(SOCKET sock, Message *m, int oob)
{
  char *bptr = (char *)m;
  int bytes_to_send = m->h.msglen;
  if ((m->h.client_type & SwapEndianOnServer) != 0)
  {
    if (Endian(m->h.client_type) != Endian(ClientType()))
    {
      FlipData(m);
      FlipHeader(&m->h);
    }
  }
  else
    m->h.client_type = ClientType();
  while (bytes_to_send > 0)
  {
    int bytes_this_time = min(bytes_to_send,BUFSIZ);
    int bytes_sent;
    bytes_sent = send(sock, bptr, bytes_this_time, oob);
    if (bytes_sent <= 0)
      return 0;
    else
    {
      bytes_to_send -= bytes_sent;
      bptr += bytes_sent;
    }
  }
  return 1;
}

static void FlipBytes(int n, char *ptr)
{
  int i;
  for (i=0;i<n/2;i++)
  {
    char tmp = ptr[i];
    ptr[i] = ptr[n - i - 1];
    ptr[n - i - 1] = tmp;
  }
}
  
static void FlipHeader(MsgHdr *header)
{
  int i;
#ifdef __CRAY
#define Flip32(n) n = ((n >> 24) & 0xff) | ((n >> 8) & 0xff00) | ((n << 8) & 0xff0000) | ((n << 24) & 0xff000000)
#define Flip16(n) n = ((n >> 8) & 0xff) | ((n << 8) & 0xff00)
  Flip32(header->msglen);
  Flip32(header->status);
  Flip16(header->length);
  for (i=0;i<MAX_DIMS;i++) FlipBytes(4,((char *)header->dims)+4*i);
#else
  FlipBytes(4,(char *)&header->msglen);
  FlipBytes(4,(char *)&header->status);
  FlipBytes(2,(char *)&header->length);
  for (i=0;i<MAX_DIMS;i++) FlipBytes(sizeof(header->dims[i]),(char *)&header->dims[i]);
#endif
}

static void FlipData(Message *m)
{
  int num = 1;
  int i;
  char *ptr;
  int dims[MAX_DIMS];
  for (i=0;i<MAX_DIMS;i++)
  {
#ifdef __CRAY
    dims[i] = i % 2 ? m->h.dims[i/2] & 0xffffffff : m->h.dims[i/2] >> 32;
#else
    dims[i] = m->h.dims[i];
#endif
  }
  if (m->h.ndims) for (i=0;i<m->h.ndims;i++) num *= dims[i];
#ifdef DEBUG
  printf("num to flip = %d\n",num);
#endif
  switch (m->h.dtype)
  {
#ifndef __CRAY
    case DTYPE_FLOAT:   
    case DTYPE_DOUBLE:
    case DTYPE_COMPLEX:
#endif
    case DTYPE_USHORT:
    case DTYPE_SHORT:  
    case DTYPE_ULONG:
    case DTYPE_LONG:  for (i=0,ptr=m->bytes;i<num;i++,ptr += m->h.length) FlipBytes(m->h.length,ptr); break;
  }
}

Message *GetMdsMsg(SOCKET sock, int *status)
{
  static MsgHdr header;
  static Message *msg = 0;
  int msglen = 0;
/*
  static struct timeval timer = {10,0};
  int tablesize = FD_SETSIZE;
*/
  int nbytes;
  int selectstat=0;
  char *bptr = (char *)&header;
  fd_set readfds;
  fd_set exceptfds;
  int bytes_remaining = sizeof(MsgHdr);
  FD_ZERO(&readfds);
  FD_SET(sock,&readfds);
  FD_ZERO(&exceptfds);
  FD_SET(sock,&exceptfds);
  *status = 0;
  if (msg)
  {
    free(msg);
    msg = 0;
  }
/*
#ifdef MULTINET
  while (((msglen == 0) || bytes_remaining) && 
          (lib$ast_in_prog() || ((selectstat = select(tablesize, &readfds, 0, &exceptfds, &timer)) > 0)))
#else
  while (((msglen == 0) || bytes_remaining) && 
          ((selectstat = select(tablesize, &readfds, 0, &exceptfds, &timer)) != 0))
#endif
*/
  while (bytes_remaining > 0)
  {
    unsigned short flags = 0;
    if (selectstat == -1 && errno == 4) continue;
    if (msglen == 0)
    {
      nbytes = recv(sock, bptr, bytes_remaining, flags);
      if (nbytes == 0)
      {
        *status = 0;
        return 0;
      }
      else if (nbytes > 0)
      {
        bytes_remaining -= nbytes;
        bptr += nbytes;
        if (bytes_remaining == 0)
        {
          if ( Endian(header.client_type) != Endian(ClientType()) ) FlipHeader(&header);
#ifdef DEBUG
          printf("msglen = %d\nstatus = %d\nlength = %d\nnargs = %d\ndescriptor_idx = %d\nmessage_id = %d\ndtype = %d\n",
               header.msglen,header.status,header.length,header.nargs,header.descriptor_idx,header.message_id,header.dtype);
          printf("client_type = %d\nndims = %d\n",header.client_type,header.ndims);
#endif
          if (CType(header.client_type) > CRAY_CLIENT || header.ndims > MAX_DIMS)
          {
            *status = 0;
            return 0;
          }  
          msglen = header.msglen;
          bytes_remaining = msglen - sizeof(MsgHdr);
          msg = malloc(msglen);
          msg->h = header;
          bptr = msg->bytes;
        }
      }
      else
      {
        perror("MDSplus GETMSG recv error");
        printf("errno = %d\n",errno);
      }
    }
    else
    {
      int bytes_this_time = min(bytes_remaining,BUFSIZ);
      nbytes = recv(sock, bptr, bytes_this_time, flags);
#ifdef DEBUG
      {int i;
      for (i=0;i<nbytes;i++)
        printf("byte(%d) = 0x%x\n",i,bptr[i]);
      }
#endif
      if (nbytes > 0)
      {
        bytes_remaining -= nbytes;
        bptr += nbytes;
      }
      else
      {
	*status = 0;
        return 0;
      }
    }
  }
  if (msglen && !bytes_remaining)
  {
    if (Endian(header.client_type) != Endian(ClientType())) FlipData(msg);
    *status = 1;
  }
  else
  {
    perror("Select problem");
  }
  return msg;
}

#ifdef _WIN32
Message *GetMdsMsgOOB(SOCKET sock, int *status)
{
  static MsgHdr header;
  static Message *msg = 0;
  int msglen = 0;
  static struct timeval timer = {10,0};

  int tablesize = FD_SETSIZE;

  int nbytes;
  int selectstat=0;
  char last;
  char *bptr = (char *)&header;
  fd_set readfds;
  fd_set exceptfds;
  int bytes_remaining = sizeof(MsgHdr);
    unsigned short flags = MSG_OOB;
	DWORD oob_data;
	int stat;
  FD_ZERO(&readfds);
  FD_SET(sock,&readfds);
  FD_ZERO(&exceptfds);
  FD_SET(sock,&exceptfds);
  *status = 0;
  if (msg)
  {
    free(msg);
    msg = 0;
  }

  selectstat = select(tablesize, 0, 0, &exceptfds, NULL);
  if (selectstat == SOCKET_ERROR) {
      perror("GETMSGOOB select error");
      printf(" errno = %d\n",errno);
	  *status = 0;
	  return 0;
  }
  nbytes = recv(sock, &last, 1, flags);
  if (nbytes == SOCKET_ERROR) {
      perror("GETMSGOOB first recv error");
      printf("errno = %d\n",errno);
	  *status = 0;
	  return 0;
  }
  stat = 	ioctlsocket(sock,SIOCATMARK,&oob_data);
  if (stat == SOCKET_ERROR) {
      perror("GETMSGOOB IOCTL error");
      printf("errno = %d\n",errno);
	  *status = 0;
	  return 0;
  }
  while (bytes_remaining > 1) 
  {
    if (selectstat == -1 && errno == 4) continue;
    if (msglen == 0)
    {
        nbytes = recv(sock, bptr, bytes_remaining, 0);
      if (nbytes == 0)
	  { 
        *status = 0;
        return 0;
      }
      else if (nbytes > 0)
      {
        bytes_remaining -= nbytes;
        bptr += nbytes;
        if (bytes_remaining == 0)
        {
          if ( Endian(header.client_type) != Endian(ClientType()) ) FlipHeader(&header);
#ifdef DEBUG
          printf("msglen = %d\nstatus = %d\nlength = %d\nnargs = %d\ndescriptor_idx = %d\nmessage_id = %d\ndtype = %d\n",
               header.msglen,header.status,header.length,header.nargs,header.descriptor_idx,header.message_id,header.dtype);
          printf("client_type = %d\nndims = %d\n",header.client_type,header.ndims);
#endif
          if (CType(header.client_type) > CRAY_CLIENT || header.ndims > MAX_DIMS)
          {
            *status = 0;
            return 0;
          }  
          msglen = header.msglen;
          bytes_remaining = msglen - sizeof(MsgHdr);
          msg = malloc(msglen);
          msg->h = header;
          bptr = msg->bytes;
        }
      }
      else
      {
        perror("GETMSGOOB recv error");
        printf("errno = %d\n",errno);
      }
    }
    else
    {
      int bytes_this_time = min(bytes_remaining,BUFSIZ);
      nbytes = recv(sock, bptr, bytes_this_time, 0);
#ifdef DEBUG
      {int i;
      for (i=0;i<nbytes;i++)
        printf("byte(%d) = 0x%x\n",i,bptr[i]);
      }
#endif
      if (nbytes > 0)
      {
        bytes_remaining -= nbytes;
        bptr += nbytes;
      }
      else
      {
	*status = 0;
        return 0;
      }
    }
  }
  if (msglen && (bytes_remaining==1))
  {
	*bptr = last;
    if ( Endian(header.client_type) != Endian(ClientType()) ) FlipData(msg);
    *status = 1;
  }
  else
  {
    perror("Select problem");
  }
  return msg;
}
#endif

