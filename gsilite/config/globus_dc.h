/* globus_dc.h.  Generated by configure.  */
/* globus_dc.h.in.  Generated from configure.in by autoheader.  */
/* rcsid = $Header$ */

#ifndef NEXUS_DC_H
#define NEXUS_DC_H

#include <memory.h>

/* EXTERN_C_BEGIN and EXTERN_C_END should surround any prototypes.
   .h files that are included by nexus.h.  This will
   This will allow C++ codes to include this header to properly link
   against the library.
*/
#ifndef EXTERN_C_BEGIN
#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif
#endif

#ifndef NEXUS_GLOBAL
#ifdef NEXUS_DEFINE_GLOBALS
#define NEXUS_GLOBAL
#else
#define NEXUS_GLOBAL extern
#endif
#endif

#ifndef NEXUS_TRUE
#define	NEXUS_TRUE		1
#define	NEXUS_FALSE		0
#endif

/**********************************************************************/

/*
 * little endian, with unsigned
 *  8 bit byte
 *  8 bit char
 * 16 bit short
 * 32 bit integer
 * 32 bit long
 * 32 bit pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 * 64 bit long long
 */
#define NEXUS_DC_FORMAT_32BIT_LE	0

/*
 * big endian, with unsigned
 *  8 bit byte
 *  8 bit char
 * 16 bit short
 * 32 bit integer
 * 32 bit long
 * 32 bit pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 * 64 bit long long
 */
#define NEXUS_DC_FORMAT_32BIT_BE	1

/*
 * little endian, with unsigned
 *  8 bit byte
 *  8 bit char
 * 16 bit short
 * 32 bit integer
 * 64 bit long
 * 64 bit pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 * 64 bit long long
 */
#define NEXUS_DC_FORMAT_64BIT_LE	2

/*
 * big endian, with unsigned
 *  8 bit byte
 *  8 bit char
 * 16 bit short
 * 32 bit integer
 * 64 bit long
 * 64 bit pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 */
#define NEXUS_DC_FORMAT_64BIT_BE	3

/*
 * big endian, with unsigned?
 *  8 bit byte
 *  8 bit char
 * 64 bit short
 * 64 bit integer
 * 64 bit long
 * 64 bit pointer
 * 32 bit Cray float
 * 64 bit Cray double
 */
#define NEXUS_DC_FORMAT_CRAYC90		4

/*
 * big endian, without unsigned
 *  8 bit byte
 * 16 bit char
 * 16 bit short
 * 32 bit integer
 * 64 bit long
 * no pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 * 64 bit long long
 */
#define NEXUS_DC_FORMAT_JAVA		5

/*
 * big endian, with unsigned?
 *  8 bit byte
 *  8 bit char
 * 32 bit short
 * 64 bit integer
 * 64 bit long
 * 64 bit pointer
 * 32 bit IEEE float
 * 64 bit IEEE double
 * 64 bit long long
 */
#define NEXUS_DC_FORMAT_CRAYT3E		6

#define NEXUS_DC_FORMAT_LAST		7

#define NEXUS_DC_FORMAT_UNKNOWN	99

#define GLOBUS_DC_FORMAT_LOCAL 0

/* #undef GLOBUS_DC_FORMAT_32BIT_BE */

#define GLOBUS_DC_FORMAT_32BIT_LE 1

/* #undef GLOBUS_DC_FORMAT_64BIT_BE */

/* #undef GLOBUS_DC_FORMAT_64BIT_LE */

/* #undef GLOBUS_DC_FORMAT_CRAYC90 */

/* #undef GLOBUS_DC_FORMAT_CRAYT3E */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* The size of a `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of a `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

#if    GLOBUS_DC_FORMAT_LOCAL==NEXUS_DC_FORMAT_32BIT_BE \
    || GLOBUS_DC_FORMAT_LOCAL==NEXUS_DC_FORMAT_32BIT_LE
#define NEXUS_DC_MAX_U_INT 0xFFFFFFFF
#define NEXUS_DC_MAX_U_LONG 0xFFFFFFFF

#elif GLOBUS_DC_FORMAT_LOCAL==NEXUS_DC_FORMAT_JAVA

#define NEXUS_DC_MAX_U_INT 0x7FFFFFFF
#define NEXUS_DC_MAX_U_LONG 0x7FFFFFFFFFFFFFFF

#else

#define NEXUS_DC_MAX_U_INT 0xFFFFFFFF
#define NEXUS_DC_MAX_U_LONG 0xFFFFFFFFFFFFFFFF

#endif

#define NEXUS_DC_MAX_U_LONG_LONG 0xFFFFFFFFFFFFFFFF

#define globus_dc_format() \
    (GLOBUS_DC_FORMAT_LOCAL)

#define nexus_dc_is_valid_format(Format) \
    (((Format) >= 0) && ((Format) < NEXUS_DC_FORMAT_LAST))

/**********************************************************************/

typedef unsigned char nexus_byte_t;

/**********************************************************************/

enum
{
    NEXUS_DC_DATATYPE_BYTE,
    NEXUS_DC_DATATYPE_CHAR,
    NEXUS_DC_DATATYPE_U_CHAR,
    NEXUS_DC_DATATYPE_SHORT,
    NEXUS_DC_DATATYPE_U_SHORT,
    NEXUS_DC_DATATYPE_INT,
    NEXUS_DC_DATATYPE_U_INT,
    NEXUS_DC_DATATYPE_LONG,
    NEXUS_DC_DATATYPE_U_LONG,
    NEXUS_DC_DATATYPE_FLOAT,
    NEXUS_DC_DATATYPE_DOUBLE,
    NEXUS_DC_DATATYPE_LONG_LONG,
    NEXUS_DC_DATATYPE_U_LONG_LONG
};

/**********************************************************************/

#define NEXUS_DC_SwapByte(a, b) \
{ \
    (a) ^= (b); \
    (b) ^= (a); \
    (a) ^= (b); \
}

/**********************************************************************/

#define NEXUS_DC_SIZEOF(TYPE, count) \
    (unsigned long)((count) * sizeof(TYPE))

#define nexus_dc_sizeof_byte(count) NEXUS_DC_SIZEOF(unsigned char, count)
#define nexus_dc_sizeof_char(count) NEXUS_DC_SIZEOF(char, count)
#define nexus_dc_sizeof_u_char(count) NEXUS_DC_SIZEOF(unsigned char, count)
#define nexus_dc_sizeof_short(count) NEXUS_DC_SIZEOF(short, count)
#define nexus_dc_sizeof_u_short(count) NEXUS_DC_SIZEOF(unsigned short, count)
#define nexus_dc_sizeof_int(count) NEXUS_DC_SIZEOF(int, count)
#define nexus_dc_sizeof_u_int(count) NEXUS_DC_SIZEOF(unsigned int, count)
#define nexus_dc_sizeof_long(count) NEXUS_DC_SIZEOF(long, count)
#define nexus_dc_sizeof_u_long(count) NEXUS_DC_SIZEOF(unsigned long, count)
#define nexus_dc_sizeof_float(count) NEXUS_DC_SIZEOF(float, count)
#define nexus_dc_sizeof_double(count) NEXUS_DC_SIZEOF(double, count)
#define nexus_dc_sizeof_long_long(count) NEXUS_DC_SIZEOF(long long, count)
#define nexus_dc_sizeof_u_long_long(count) NEXUS_DC_SIZEOF(unsigned long long, count)

/**********************************************************************/

#define NEXUS_DC_PUT(TYPE, buffer, data, count) \
{ \
    unsigned long c = NEXUS_DC_SIZEOF(TYPE, count); \
    memcpy(*(buffer), data, c); \
    *(buffer) += c; \
}

#define nexus_dc_put_byte(buffer, data, count) \
    NEXUS_DC_PUT(unsigned char, buffer, data, count)
#define nexus_dc_put_char(buffer, data, count) \
    NEXUS_DC_PUT(char, buffer, data, count)
#define nexus_dc_put_u_char(buffer, data, count) \
    NEXUS_DC_PUT(unsigned char, buffer, data, count)
#define nexus_dc_put_short(buffer, data, count) \
    NEXUS_DC_PUT(short, buffer, data, count)
#define nexus_dc_put_u_short(buffer, data, count) \
    NEXUS_DC_PUT(unsigned short, buffer, data, count)
#define nexus_dc_put_int(buffer, data, count) \
    NEXUS_DC_PUT(int, buffer, data, count)
#define nexus_dc_put_u_int(buffer, data, count) \
    NEXUS_DC_PUT(unsigned int, buffer, data, count)
#define nexus_dc_put_long(buffer, data, count) \
    NEXUS_DC_PUT(long, buffer, data, count)
#define nexus_dc_put_u_long(buffer, data, count) \
    NEXUS_DC_PUT(unsigned long, buffer, data, count)
#define nexus_dc_put_float(buffer, data, count) \
    NEXUS_DC_PUT(float, buffer, data, count)
#define nexus_dc_put_double(buffer, data, count) \
    NEXUS_DC_PUT(double, buffer, data, count)
#define nexus_dc_put_long_long(buffer, data, count) \
    NEXUS_DC_PUT(long long, buffer, data, count)
#define nexus_dc_put_u_long_long(buffer, data, count) \
    NEXUS_DC_PUT(unsigned long long, buffer, data, count)
/**********************************************************************/

#define nexus_dc_is_native_byte(format) (NEXUS_TRUE)

#define nexus_dc_get_byte(buffer, data, count, format) \
{ \
    unsigned long c = (count); \
    memcpy(data, *(buffer), c); \
    *(buffer) += c; \
}

#define nexus_dc_check_lost_precision_byte(buffer, count, format) (-1)

/**********************************************************************/

/* byte,char,u_char,short,u_short,int,u_int,long,u_long,float,double,long long,u_long_long */
NEXUS_GLOBAL int nexus_dc_sizeof_remote_table[][13]
#ifdef NEXUS_DEFINE_GLOBALS
= {
  {1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 8, 8, 8}, /* NEXUS_DC_FORMAT_32BIT_LE */
  {1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 8, 8, 8}, /* NEXUS_DC_FORMAT_32BIT_BE */
  {1, 1, 1, 2, 2, 4, 4, 8, 8, 4, 8, 8, 8}, /* NEXUS_DC_FORMAT_64BIT_LE */
  {1, 1, 1, 2, 2, 4, 4, 8, 8, 4, 8, 8, 8}, /* NEXUS_DC_FORMAT_64BIT_BE */
  {1, 1, 1, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, /* NEXUS_DC_FORMAT_CRAYC90  */
  {1, 2, 2, 2, 2, 4, 4, 8, 8, 4, 8, 8, 8}, /* NEXUS_DC_FORMAT_JAVA     */
  {1, 1, 1, 4, 4, 8, 8, 8, 8, 4, 8, 8, 8}  /* NEXUS_DC_FORMAT_T3E      */
}
#endif
;

#define nexus_dc_sizeof_remote_byte(count, format) \
    (nexus_dc_sizeof_remote_table[format][0] * (count))

#define nexus_dc_sizeof_remote_char(count, format) \
    (nexus_dc_sizeof_remote_table[format][1] * (count))

#define nexus_dc_sizeof_remote_u_char(count, format) \
    (nexus_dc_sizeof_remote_table[format][2] * (count))

#define nexus_dc_sizeof_remote_short(count, format) \
    (nexus_dc_sizeof_remote_table[format][3] * (count))

#define nexus_dc_sizeof_remote_u_short(count, format) \
    (nexus_dc_sizeof_remote_table[format][4] * (count))

#define nexus_dc_sizeof_remote_int(count, format) \
    (nexus_dc_sizeof_remote_table[format][5] * (count))

#define nexus_dc_sizeof_remote_u_int(count, format) \
    (nexus_dc_sizeof_remote_table[format][6] * (count))

#define nexus_dc_sizeof_remote_long(count, format) \
    (nexus_dc_sizeof_remote_table[format][7] * (count))

#define nexus_dc_sizeof_remote_u_long(count, format) \
    (nexus_dc_sizeof_remote_table[format][8] * (count))

#define nexus_dc_sizeof_remote_float(count, format) \
    (nexus_dc_sizeof_remote_table[format][9] * (count))

#define nexus_dc_sizeof_remote_double(count, format) \
    (nexus_dc_sizeof_remote_table[format][10] * (count))

#define nexus_dc_sizeof_remote_long_long(count, format) \
    (nexus_dc_sizeof_remote_table[format][11] * (count))

#define nexus_dc_sizeof_remote_u_long_long(count, format) \
    (nexus_dc_sizeof_remote_table[format][12] * (count))
/**********************************************************************/

EXTERN_C_BEGIN

extern int	nexus_dc_is_native_char(int format);
extern int	nexus_dc_is_native_u_char(int format);
extern int	nexus_dc_is_native_short(int format);
extern int	nexus_dc_is_native_u_short(int format);
extern int	nexus_dc_is_native_int(int format);
extern int	nexus_dc_is_native_u_int(int format);
extern int	nexus_dc_is_native_long(int format);
extern int	nexus_dc_is_native_u_long(int format);
extern int	nexus_dc_is_native_float(int format);
extern int	nexus_dc_is_native_double(int format);
extern int      nexus_dc_is_native_long_long(int format);
extern int      nexus_dc_is_native_u_long_long(int format);

extern void	nexus_dc_get_char(nexus_byte_t **buffer,
				  char *data,
				  unsigned long count,
				  int format);
extern void	nexus_dc_get_u_char(nexus_byte_t **buffer,
				    unsigned char *data,
				    unsigned long count,
				    int format);
extern void	nexus_dc_get_short(nexus_byte_t **buffer,
				   short *data,
				   unsigned long count,
				   int format);
extern void	nexus_dc_get_u_short(nexus_byte_t **buffer,
				     unsigned short *data,
				     unsigned long count,
				     int format);
extern void	nexus_dc_get_int(nexus_byte_t **buffer,
				 int *data,
				 unsigned long count,
				 int format);
extern void	nexus_dc_get_u_int(nexus_byte_t **buffer,
				   unsigned int *data,
				   unsigned long count,
				   int format);
extern void	nexus_dc_get_long(nexus_byte_t **buffer,
				  long *data,
				  unsigned long count,
				  int format);
extern void	nexus_dc_get_u_long(nexus_byte_t **buffer,
				    unsigned long *data,
				    unsigned long count,
				    int format);
extern void	nexus_dc_get_float(nexus_byte_t **buffer,
				   float *data,
				   unsigned long count,
				   int format);
extern void	nexus_dc_get_double(nexus_byte_t **buffer,
				    double *data,
				    unsigned long count,
				    int format);
extern void     nexus_dc_get_long_long(nexus_byte_t **buffer,
                                       long long *data,
                                       unsigned long count,
                                       int format);
extern void     nexus_dc_get_u_long_long(nexus_byte_t **buffer,
                                         unsigned long long *data,
                                         unsigned long count,
                                         int format);


extern int	nexus_dc_check_lost_precision_char(nexus_byte_t *buffer,
						   unsigned long count,
						   int format);
extern int	nexus_dc_check_lost_precision_u_char(nexus_byte_t *buffer,
						     unsigned long count,
						     int format);
extern int	nexus_dc_check_lost_precision_short(nexus_byte_t *buffer,
						    unsigned long count,
						    int format);
extern int	nexus_dc_check_lost_precision_u_short(nexus_byte_t *buffer,
						      unsigned long count,
						      int format);
extern int	nexus_dc_check_lost_precision_int(nexus_byte_t *buffer,
						  unsigned long count,
						  int format);
extern int	nexus_dc_check_lost_precision_u_int(nexus_byte_t *buffer,
						    unsigned long count,
						    int format);
extern int	nexus_dc_check_lost_precision_long(nexus_byte_t *buffer,
						   unsigned long count,
						   int format);
extern int	nexus_dc_check_lost_precision_u_long(nexus_byte_t *buffer,
						     unsigned long count,
						     int format);
extern int	nexus_dc_check_lost_precision_float(nexus_byte_t *buffer,
						    unsigned long count,
						    int format);
extern int	nexus_dc_check_lost_precision_double(nexus_byte_t *buffer,
						     unsigned long count,
						     int format);
extern int      nexus_dc_check_lost_precision_long_long(nexus_byte_t *buffer,
                                                        unsigned long count,
                                                        int format);
extern int      nexus_dc_check_lost_precision_u_long_long(nexus_byte_t *buffer,
                                                          unsigned long count,
                                                          int format);
EXTERN_C_END


/*
 * Backward compatibility
 */
#define NEXUS_DC_FORMAT_LOCAL GLOBUS_DC_FORMAT_LOCAL
#define nexus_dc_format() globus_dc_format()

/*
 * Forward compatibility :-)
 */
#define globus_dc_sizeof_char      nexus_dc_sizeof_char
#define globus_dc_sizeof_u_char    nexus_dc_sizeof_u_char
#define globus_dc_sizeof_byte      nexus_dc_sizeof_byte
#define globus_dc_sizeof_short     nexus_dc_sizeof_short
#define globus_dc_sizeof_u_short   nexus_dc_sizeof_u_short
#define globus_dc_sizeof_int       nexus_dc_sizeof_int
#define globus_dc_sizeof_u_int     nexus_dc_sizeof_u_int
#define globus_dc_sizeof_long      nexus_dc_sizeof_long
#define globus_dc_sizeof_long_long nexus_dc_sizeof_long_long
#define globus_dc_sizeof_u_long    nexus_dc_sizeof_u_long
#define globus_dc_sizeof_float     nexus_dc_sizeof_float
#define globus_dc_sizeof_double    nexus_dc_sizeof_double

#define globus_dc_sizeof_remote_char      nexus_dc_sizeof_remote_char
#define globus_dc_sizeof_remote_u_char    nexus_dc_sizeof_remote_u_char
#define globus_dc_sizeof_remote_byte      nexus_dc_sizeof_remote_byte
#define globus_dc_sizeof_remote_short     nexus_dc_sizeof_remote_short
#define globus_dc_sizeof_remote_u_short   nexus_dc_sizeof_remote_u_short
#define globus_dc_sizeof_remote_int       nexus_dc_sizeof_remote_int
#define globus_dc_sizeof_remote_u_int     nexus_dc_sizeof_remote_u_int
#define globus_dc_sizeof_remote_long      nexus_dc_sizeof_remote_long
#define globus_dc_sizeof_remote_long_long nexus_dc_sizeof_remote_long_long
#define globus_dc_sizeof_remote_u_long    nexus_dc_sizeof_remote_u_long
#define globus_dc_sizeof_remote_float     nexus_dc_sizeof_remote_float
#define globus_dc_sizeof_remote_double    nexus_dc_sizeof_remote_double

#define globus_dc_put_char      nexus_dc_put_char
#define globus_dc_put_u_char    nexus_dc_put_u_char
#define globus_dc_put_byte      nexus_dc_put_byte
#define globus_dc_put_short     nexus_dc_put_short
#define globus_dc_put_u_short   nexus_dc_put_u_short
#define globus_dc_put_int       nexus_dc_put_int
#define globus_dc_put_u_int     nexus_dc_put_u_int
#define globus_dc_put_long      nexus_dc_put_long
#define globus_dc_put_long_long nexus_dc_put_long_long
#define globus_dc_put_u_long    nexus_dc_put_u_long
#define globus_dc_put_float     nexus_dc_put_float
#define globus_dc_put_double    nexus_dc_put_double

#define globus_dc_get_char      nexus_dc_get_char
#define globus_dc_get_u_char    nexus_dc_get_u_char
#define globus_dc_get_byte      nexus_dc_get_byte
#define globus_dc_get_short     nexus_dc_get_short
#define globus_dc_get_u_short   nexus_dc_get_u_short
#define globus_dc_get_int       nexus_dc_get_int
#define globus_dc_get_u_int     nexus_dc_get_u_int
#define globus_dc_get_long      nexus_dc_get_long
#define globus_dc_get_long_long nexus_dc_get_long_long
#define globus_dc_get_u_long    nexus_dc_get_u_long
#define globus_dc_get_float     nexus_dc_get_float
#define globus_dc_get_double    nexus_dc_get_double

#endif /* NEXUS_DC_H */
