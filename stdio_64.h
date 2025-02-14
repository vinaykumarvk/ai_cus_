/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to
 *    Polaris Software Lab Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
/*********************************************************************
 *
 * Module Name         :      10G Migration
 *
 * File Name           :      stdio_64.h
 *
 * Description         :      Changed For 10G  Migration /64 Bit Compilation
 *
 *
 *
 *     Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ---------------  --------------    -----------
 * 10/01/2006              Bageshri S        10GM   
 *
 *********************************************************************/





#ifndef	_FILE64_H
 #define	_FILE64_H
 
 #pragma ident	"@(#)file64.h	1.15	05/06/08 SMI"
#include <stdio.h> 
 /* For Linux OS Comment below for other uncomment below 3 lines */
/* #include <synch.h> 
#include <stdio_tag.h>
#include <wchar_impl.h> */
 
 #ifdef	__cplusplus
 extern "C" {
 #endif
 
 #ifndef	_MBSTATE_T
 #define	_MBSTATE_T
 typedef __mbstate_t	mbstate_t;
 #endif
 
 #define	rmutex_t	mutex_t
 
 #ifdef	_LP64
 
 struct __FILE_TAG {
 	unsigned char	*_ptr;	/* next character from/to here in buffer */
 	unsigned char	*_base;	/* the buffer */
 	unsigned char	*_end;	/* the end of the buffer */
 	ssize_t		_cnt;	/* number of available characters in buffer */
 	int		_file;	/* UNIX System file descriptor */
 	unsigned int	_flag;	/* the state of the stream */
 	/* rmutex_t	_lock; */	/* lock for this structure */ /* For Linux OS Comment this */
 	mbstate_t	_state;	/* mbstate_t */
 	char		__fill[32];	/* filler to bring size to 128 bytes */
 };
 
 #else
 
 /*
  * Stuff missing from our 32-bit FILE struct.
  */
 struct xFILEdata {
 	/* uintptr_t	_magic;*/ /* Check: magic number, must be first */ /* For Linux Comment this */
 	unsigned char	*_end;	/* the end of the buffer */
 	/* rmutex_t	_lock;*/	/* lock for this structure */ /* For Linux Comment this */
 	mbstate_t	_state;	/* mbstate_t */
 };
 
 #define	XFILEINITIALIZER	{ 0, NULL, RECURSIVEMUTEX, DEFAULTMBSTATE }
 
 #endif	/*	_LP64	*/
 
 #ifdef	__cplusplus
 }
 #endif
 
 #endif	/* _FILE64_H */

#include <stdio.h>
