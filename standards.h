/* @(#)44  1.10.1.18  src/bos/usr/include/standards.h, incstd, bos530, 0426A_530 6/18/04 15:48:10 */
/*
 * COMPONENT_NAME: (INCSTD) Standard Include Files
 *
 * FUNCTIONS: 
 *
 * ORIGINS: 27
 *
 * (C) COPYRIGHT International Business Machines Corp. 1995
 * All Rights Reserved
 * Licensed Materials - Property of IBM
 *
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

/* KOTAK AIX Migration Changes - Santosh Saggam - START 
 *
 * Changes had to be made to the system supplied <standards.h> as proc compiler 
 * doesn't support #warning and #error directives. Please refer the below given URL's for more info.
 *
 * http://stackoverflow.com/questions/14698/how-to-make-proc-cope-with-warning-directives
 * http://telinit0.blogspot.com/2009/08/standardsh-problem-after-upgrading-to.html
 *
 * KOTAK AIX Migration Changes - Santosh Saggam - END */

#ifndef _H_STANDARDS
#define _H_STANDARDS

#define _AIXVERSION_430  1
#define _AIXVERSION_431  1
#define _AIXVERSION_434  1
#define _AIXVERSION_510  1
#define _AIXVERSION_520  1
#define _AIXVERSION_530  1
#define _AIXVERSION_610  1

/* These directives must be processed in the current order when compiled with 
 * cc or they will not work correctly.
 */

/* If _XOPEN_SOURCE is defined without a value, or with a value less
 * than 500 (UNIX98), then set a value, so that #if statements will 
 * work properly.
 */
#ifdef _XOPEN_SOURCE
#if ((_XOPEN_SOURCE + 0) < 500)
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE	1
#endif
#endif

#if defined(_UNIX03) || (_XOPEN_SOURCE==600)
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE   600
#undef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED     1
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#undef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#if defined(_UNIX98) || (_XOPEN_SOURCE==500)
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE   500
#undef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED     1
#endif

#ifdef _UNIX95
#undef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED     1
#endif

#if (_XOPEN_SOURCE_EXTENDED==1)
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE	1
#endif /* _XOPEN_SOURCE */
#endif /* _XOPEN_SOURCE_EXTENDED */

#ifdef _XOPEN_SOURCE
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif
#endif

#ifdef _POSIX_SOURCE
#ifndef _ANSI_SOURCE
#define _ANSI_SOURCE
#endif
#endif

#ifdef _ANSI_SOURCE
#ifndef _ANSI_C_SOURCE
#define _ANSI_C_SOURCE
#endif
#endif

#ifdef _ALL_SOURCE
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE	600
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif
#ifndef _ANSI_SOURCE
#define _ANSI_SOURCE
#endif
#ifndef _ANSI_C_SOURCE
#define _ANSI_C_SOURCE
#endif
#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif
#ifdef _LONG_LONG
#ifndef _LARGE_FILE_API
#define _LARGE_FILE_API
#endif
#endif
#endif

#if (!defined (_XOPEN_SOURCE)) &&  (!defined (_POSIX_SOURCE)) && (!defined (_ANSI_C_SOURCE))
#define _XOPEN_SOURCE  600
#define _XOPEN_SOURCE_EXTENDED 1
#define _POSIX_SOURCE
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif
#define _ANSI_SOURCE
#ifndef _ANSI_C_SOURCE
#define _ANSI_C_SOURCE
#endif
#ifdef _LONG_LONG
#ifndef _LARGE_FILE_API
#define _LARGE_FILE_API
#endif
#endif
#ifndef _ALL_SOURCE
#define _ALL_SOURCE
#endif
#endif

#ifdef _POSIX_SOURCE
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199506L
#endif 
#endif

/* 
 * Handle the use of the restrict keyword in non-C99 compilers
 */
#if ((__STDC_VERSION__ >= 199901L) || defined(__C99_RESTRICT))
#define __restrict__ restrict
#else
#define __restrict__ 
#endif

/* 
 * Determine when C99 interfaces and definitions are allowed to be exposed
 *  - if _POSIX_C_SOURCE is newer than 1995 
 *  - if a C99 compiler is being used outside of the UNIX98 namespace
 */
#if !(defined _ISOC99_SOURCE) && !(defined _NOISOC99_SOURCE)
#if (_POSIX_C_SOURCE > 199506L) || \
    ((__STDC_VERSION__ >= 199901L) && \
     ((!defined _XOPEN_SOURCE) || (_XOPEN_SOURCE > 500)))
#define _ISOC99_SOURCE
#endif 
#endif

#endif /* _H_STANDARDS */
