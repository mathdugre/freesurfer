/*
  @(#)macros.h  1.9
  12/12/95
*/
/*------------------------------------------------------------------------
      File Name:  macros.h

         Author:  Bruce Fischl

        Created:  Jan. 1994

    Description:  

------------------------------------------------------------------------*/
#ifndef MACROS_H
#define MACROS_H

#include "const.h"
#include "utils.h"
#include "math.h"

#ifndef UCHAR
#define UCHAR        unsigned char
#endif

#ifndef UINT
#define UINT         unsigned int
#endif

#define ISOPTION(c)  ((c) == '-')

/* these are defined in hipl_format.h */
#ifndef MIN
#define MIN(a,b)     ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b)     ((a) >= (b) ? (a) : (b))
#endif

#define EVEN(n)      ((((n) / 2) * 2) == n)
#define ODD(n)       (!EVEN(n))

#define RADIANS(deg) (2.0 * PI * (double)(deg)) / (360.0)
#define DEGREES(rad) ((360.0 * (double)(rad)) / (2.0 * PI))
#define NDEGREES(rad) (DEGREES(normAngle(rad)))

#ifndef SPARC
#define FZERO(f)     (fabs(f) < 0.00000001F)
#define iszero(f)   (FZERO(f))
#else
#define FZERO(f)     (iszero(f))
#endif

#define ISINT(f)      ((float)((int)f) == f)
#define FEQUAL(f1,f2) (FZERO(f1-f2))

#ifndef SQR
#define SQR(a)   ((a)*(a))
#endif

#define FSIGN(f)   (FZERO(f) ? 0.0f : (f < 0.0f) ? -1.0f : 1.0f)
#include <stdlib.h>
#include <string.h>

#define STRALLOC(str)   ((char *)calloc(strlen(str)+1, sizeof(char)))
#define STRCPALLOC(str) strcpy(STRALLOC(str), str)

#ifdef LINUX
#define exp2(f)     pow(2.0,(f))
#define log2(f)     (log(f) / log(2.0))
#endif

#ifdef _MSDOS
#include <math.h>
#define exp2(f)     pow(2.0,(f))
#define log2(f)     (log(f) / log(2.0))
#ifndef M_E
#define M_E 2.718282 /* exp(1) */
#endif
#ifndef M_PI
#define M_PI  3.141593
#endif

#endif

#define ISPOW2(n)   (exp2((float)nint(log2((float)n))) == (float)n)

#ifdef INT32B
#undef INT32B
#endif

#define INT32B  long

#ifndef SGN
#define SGN(x)  (((x) < 0) ? -1 : 1)
#endif
#ifndef ABS
#define ABS(x)  (((x) < 0) ? x : -x)
#endif

#endif
