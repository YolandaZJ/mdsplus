#include        "tclsysdef.h"
#include <string.h>
#include <ncidef.h>

/**********************************************************************
* TCL_DIRECTORY_TAG.C --
*
* TclDirectoryTag:  Perform directory of all of the tags
*
* History:
*  16-Jan-1998  TRG  Create.  Ported from original mds code.
*
************************************************************************/

	/****************************************************************
	 * TclDirectoryTag:
	 * Perform directory of all of the tags
	 ****************************************************************/
int TclDirectoryTag(void *ctx, char **error, char **output)
{
  int sub_total;
  int grand_total;
  char *nodename;
  char text[400];
  void *ctx1;
  char *tagnam=0;
  int path=cli_present(ctx, "PATH") & 1;

  *output=strdup("");
  sub_total = grand_total = 0;
  while (cli_get_value(ctx, "TAG", &tagnam) & 1 && (strlen(tagnam) < 24)) {
    ctx1 = 0;
    sub_total = 0;
    sprintf(text,"\nTag listing for %s\n\n",tagnam);
    tclAppendOutput(output, text);
    while ((nodename = TreeFindTagWild(tagnam, 0, &ctx1))) {
      if (path) {
	NCI_ITM itmlist[] = {{0, NciFULLPATH, 0, 0},{0, 0, 0, 0}};
	int nid;
	TreeFindNode(nodename,&nid);
	TreeGetNci(nid,itmlist);
	if (itmlist[0].pointer) {
	  char *info=malloc(strlen(nodename)+strlen(itmlist[0].pointer)+100);
	  sprintf(info,"%s%.*s = %s\n",nodename, 40-strlen(nodename),
		  "                                               ",
		  itmlist[0].pointer);
	  tclAppendOutput(output,info);
	  free(info);
	  free(itmlist[0].pointer);
	}
      } else {
	sprintf(text,"%s\n",nodename);
	tclAppendOutput(output, text);
      }
      sub_total++;
      mdsdclFlushOutput(*output);
    }
    TreeFindTagEnd(&ctx1);
    grand_total += sub_total;
    sprintf(text, "Total of %d tags\n", sub_total);
    tclAppendOutput(output, text);
    if (tagnam)
      free(tagnam);
  }
  if (grand_total != sub_total) {
    sprintf(text, "Grand Total of %d tags\n", sub_total);
    tclAppendOutput(output,text);
  }
  return 1;
}
