
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "Daemon_MT_DM.pc"
};


static unsigned int sqlctx = 2252451;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,69,0,5,130,0,0,0,0,0,1,0,
20,0,0,2,167,0,4,148,0,0,1,0,0,1,0,2,5,0,0,
39,0,0,3,0,0,29,157,0,0,0,0,0,1,0,
54,0,0,4,56,0,5,161,0,0,1,1,0,1,0,1,5,0,0,
73,0,0,5,0,0,29,163,0,0,0,0,0,1,0,
88,0,0,6,133,0,4,166,0,0,8,1,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,1,5,0,0,
135,0,0,7,0,0,29,818,0,0,0,0,0,1,0,
150,0,0,8,0,0,31,822,0,0,0,0,0,1,0,
165,0,0,9,83,0,5,828,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
188,0,0,10,0,0,29,831,0,0,0,0,0,1,0,
203,0,0,11,0,0,31,842,0,0,0,0,0,1,0,
218,0,0,12,70,0,5,850,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
241,0,0,13,76,0,5,855,0,0,1,1,0,1,0,1,5,0,0,
260,0,0,14,0,0,29,859,0,0,0,0,0,1,0,
};


#line 1 "Daemon_MT_DM.pc"
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
 * Module Name         :	 				Maintenance
 *
 * File Name           :					Daemon_MT_DM.pc
 *
 * Description         :					Contains all Wrapper Functions for
	*												different Units in Maintenance.
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author         Description					RFS No.
 * ---------   --------	 --------------  -----------------			----------
 *  
 *********************************************************************/
   
#include "stdio_64.h"
#include <unistd.h>
#include "DM_Interface.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
/* EXEC SQL INCLUDE SQLCA;
 */ 
#line 1 "/icustody/oracle/ora10g/precomp/public/SQLCA.H"
/*
 * $Header:   D:/Migration_Temp_Files/MIGProjectDatabase/archives/INTLCUST/SOURCE/BE/Daemon_MT_DM.c-arc   1.0   Oct 04 2011 13:20:40   Administrator  $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

#line 41 "Daemon_MT_DM.pc"
PRO_REQUEST_MT_STRUCT_H		*l_request_mt = (PRO_REQUEST_MT_STRUCT_H  *)NULL;
DEBUG_INFO_STRUCT_H 			**l_debug_info_ptr ;
DEBUG_INFO_STRUCT_H         *l_debug_info_struct_h_tmp=NULL; 
main(int argc,char **argv)
{
	char 								chr_h_error_desc[4000];
	char l_rowid[APL_ROWID_LEN] = APL_NULL_STRING;
	short i_rowid		=	0;
	PRO_REQUEST_MT_STRUCT_I		*i_request_mt = (PRO_REQUEST_MT_STRUCT_I  *)NULL;
	INTL_ENV_DATA_STRUCT_H		*p_intlenv_data_struct_h = (INTL_ENV_DATA_STRUCT_H  *)NULL;
	int l_sleep_seconds =0,l_sleep_microseconds = 0;
	char l_data_fld_sep_str[2];
	int int_ret_val;

/** Variables **/
	MT_INSTRUMENT_STRUCT_H 	*l_mt_instrument_struct_h 	= 	(MT_INSTRUMENT_STRUCT_H *)NULL;
	MT_HOLIDAY_STRUCT_H 		*l_mt_holiday_struct_h	 	=	(MT_HOLIDAY_STRUCT_H		*)NULL;
	MT_NO_DELV_STRUCT_H 		*l_mt_no_delv_struct_h 		=  (MT_NO_DELV_STRUCT_H 	*)NULL;
	MT_COMPANY_STRUCT_H 		*l_mt_company_struct_h 		=  (MT_COMPANY_STRUCT_H 	*)NULL;
	MT_SETTL_CAL_STRUCT_H 	*l_mt_settl_cal_struct_h 	=  (MT_SETTL_CAL_STRUCT_H 	*)NULL;
	MT_RBI_MONITORY_STRUCT_H 	*l_mt_rbi_monitory_struct_h 	=	(MT_RBI_MONITORY_STRUCT_H 	*)NULL;
	MT_PTC_DET_STRUCT_H 		*l_mt_ptc_det_struct_h 		=  (MT_PTC_DET_STRUCT_H 	*)NULL;
	MT_RED_DET_STRUCT_H 		*l_mt_red_det_struct_h 		=  (MT_RED_DET_STRUCT_H 	*)NULL;
	MT_PC_DET_STRUCT_H 		*l_mt_pc_det_struct_h 		=  (MT_PC_DET_STRUCT_H 		*)NULL;
	MT_RESET_DET_STRUCT_H 	*l_mt_reset_det_struct_h 	=  (MT_RESET_DET_STRUCT_H 	*)NULL;
	MT_DAILY_FLOAT_RATE_STRUCT_H *l_mt_daily_float_rate_struct_h =  (MT_DAILY_FLOAT_RATE_STRUCT_H *)NULL;
	MT_FLRATE_INSTRUMENT_STRUCT_H *l_mt_flrate_instrument_struct_h =  (MT_FLRATE_INSTRUMENT_STRUCT_H *)NULL;
	MT_PARTY_STRUCT_H 		*l_mt_party_struct_h 		=  (MT_PARTY_STRUCT_H 		*)NULL;
	MT_PTY_BANKDET_STRUCT_H	*l_mt_pty_bankdet_struct_h =  (MT_PTY_BANKDET_STRUCT_H *)NULL;
	MT_PTY_FUND_DET_STRUCT_H	*l_mt_pty_fund_det_struct_h =  (MT_PTY_FUND_DET_STRUCT_H *)NULL;
	MT_INSTR_EXCH_DET_STRUCT_H *l_mt_instr_exch_det_struct_h =  (MT_INSTR_EXCH_DET_STRUCT_H *)NULL;
	CAENTITLEMENT_STRUCT_H 	*l_caentitlement_struct_h 	=  (CAENTITLEMENT_STRUCT_H *)NULL;
	MT_INSL_ENTRY_STRUCT_H 	*l_mt_insl_entry_struct_h 	=  (MT_INSL_ENTRY_STRUCT_H *)NULL;
	MT_CR_AGENCY_STRUCT_H 	*l_mt_cr_agency_struct_h 	=  (MT_CR_AGENCY_STRUCT_H 	*)NULL;
	MT_EXCH_DEPO_STRUCT_H 	*l_mt_exch_depo_struct_h 	=  (MT_EXCH_DEPO_STRUCT_H 	*)NULL;
	MT_RED_DP_DET_STRUCT_H	*l_mt_red_dp_det_struct_h 	=  (MT_RED_DP_DET_STRUCT_H *)NULL;
	MT_INSTR_RATING_DET_STRUCT_H	*l_mt_instr_rating_det_struct_h =  (MT_INSTR_RATING_DET_STRUCT_H *)NULL;
	MT_PTY_EXCH_CLN_MAP_STRUCT_H 	*l_mt_pty_exch_cln_map_struct_h =  (MT_PTY_EXCH_CLN_MAP_STRUCT_H *)NULL;
	MT_CLN_INST_MAP_STRUCT_H 	*l_mt_cln_inst_map_struct_h 			=  (MT_CLN_INST_MAP_STRUCT_H *)NULL;
	MT_CLIENT_STRUCT_H 		*l_mt_client_struct_h 		=  (MT_CLIENT_STRUCT_H 		*)NULL;
	MT_CLI_EXCH_MAP_STRUCT_H *l_mt_cli_exch_map_struct_h =  (MT_CLI_EXCH_MAP_STRUCT_H *)NULL;
	MT_CLI_DEPO_MAP_STRUCT_H	*l_mt_cli_depo_map_struct_h =  (MT_CLI_DEPO_MAP_STRUCT_H *)NULL;
	MT_PTY_EXCH_MAP_STRUCT_H 	*l_mt_pty_exch_map_struct_h =  (MT_PTY_EXCH_MAP_STRUCT_H *)NULL;
	MT_DEPO_PART_STRUCT_H		*l_mt_depo_part_struct_h =  (MT_DEPO_PART_STRUCT_H *)NULL;
	MT_PTY_DEPO_MAP_STRUCT_H   *l_mt_pty_depo_map_struct_h = (MT_PTY_DEPO_MAP_STRUCT_H *)NULL;
	DL_DEAL_STRUCT_H           *l_dl_deal_struct_h = (DL_DEAL_STRUCT_H *)NULL;
	DL_SAFEK_STRUCT_H          *l_dl_safek_struct_h = (DL_SAFEK_STRUCT_H *)NULL;
	CAEVENT_STRUCT_H 				*l_caevent_struct_h	=	(CAEVENT_STRUCT_H *)NULL;
	/**MT_EXCH_DEPO_STRUCT_H      *l_mt_exch_depo_struct_h = (MT_EXCH_DEPO_STRUCT_H *)NULL;**/
	MT_REGDETAILS_STRUCT_H  *l_mt_regdetails_struct_h = (MT_REGDETAILS_STRUCT_H *)NULL;

/** Variables **/


	p_intlenv_data_struct_h =  (INTL_ENV_DATA_STRUCT_H *)calloc(1,sizeof(INTL_ENV_DATA_STRUCT_H));
	APL_MALLOC_FAIL(p_intlenv_data_struct_h);
	memset(p_intlenv_data_struct_h,NULL,sizeof(INTL_ENV_DATA_STRUCT_H));
	l_request_mt =  (PRO_REQUEST_MT_STRUCT_H *)calloc(1,sizeof(PRO_REQUEST_MT_STRUCT_H));
	APL_MALLOC_FAIL(l_request_mt);
	memset(l_request_mt,NULL,sizeof(PRO_REQUEST_MT_STRUCT_H));
	i_request_mt =  (PRO_REQUEST_MT_STRUCT_I *)calloc(1,sizeof(PRO_REQUEST_MT_STRUCT_I));
	APL_MALLOC_FAIL(i_request_mt);
	memset(i_request_mt,NULL,sizeof(PRO_REQUEST_MT_STRUCT_I));
	if ( ( l_debug_info_struct_h_tmp = (DEBUG_INFO_STRUCT_H *)calloc(1,sizeof(DEBUG_INFO_STRUCT_H)) ) == NULL )
		APL_GOBACK_FAIL ;
	if ( ( (l_debug_info_ptr) = (DEBUG_INFO_STRUCT_H **)calloc(1,sizeof(DEBUG_INFO_STRUCT_H *)) ) == NULL )	
		APL_GOBACK_FAIL ;
	if ( argc != 2)
	{
		printf("\n Invalid sleep time for daemon ... \n ");
		APL_GOBACK_FAIL
	}
	else
	{
		printf("\n ******************  Server Started With Sleep Time :%s:****************\n",argv[1]);
		sscanf(argv[1],"%d.%d",&l_sleep_seconds,&l_sleep_microseconds);
		printf("sleep time |%d|%d|\n",l_sleep_seconds,l_sleep_microseconds);
		l_sleep_microseconds = l_sleep_microseconds * 10000;	
	}
	if(CO_Get_DBConnect(l_debug_info_ptr) == APL_FAILURE)
	{
		printf("Failed|||\n");
		APL_GOBACK_FAIL
	}
	if ( CO_RtvSysParams(l_debug_info_ptr) == APL_FAILURE)
	{
		printf("\nReturned unsuccessfully from CO_RtvSysParams processtion\n");
		APL_GOBACK_FAIL
	}
	/* EXEC SQL UPDATE PRO_DAEMON_STATUS SET STATUS = 1 where PROC_NAME = 'Daemon_MT_DM'; */ 
#line 130 "Daemon_MT_DM.pc"

{
#line 130 "Daemon_MT_DM.pc"
 struct sqlexd sqlstm;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.sqlvsn = 12;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.arrsiz = 0;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.sqladtp = &sqladt;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.sqltdsp = &sqltds;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.stmt = "update PRO_DAEMON_STATUS  set STATUS=1 where PROC_NAME='Daem\
on_MT_DM'";
#line 130 "Daemon_MT_DM.pc"
 sqlstm.iters = (unsigned int  )1;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.offset = (unsigned int  )5;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.cud = sqlcud0;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 130 "Daemon_MT_DM.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 130 "Daemon_MT_DM.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 130 "Daemon_MT_DM.pc"
}

#line 130 "Daemon_MT_DM.pc"

	IS_ANY_ORA_ERROR;
	l_data_fld_sep_str[0] = DATA_FIELD_SEPRTR;
	l_data_fld_sep_str[1] = APL_NULL_CHAR;
	while(1)
	{
		CO_FreeErrLst(l_debug_info_ptr);
		CO_FreeErrLst(&l_debug_info_struct_h_tmp);
		memset(l_rowid,'\0',sizeof(l_rowid));
		memset(l_request_mt,0,sizeof(l_request_mt));
		memset(i_request_mt,0,sizeof(l_request_mt));
	   memset(p_intlenv_data_struct_h,NULL,sizeof(INTL_ENV_DATA_STRUCT_H));
		i_rowid = 0;
		if(l_sleep_seconds != 0)
		{
			sleep(l_sleep_seconds);
		}
		usleep(l_sleep_microseconds);
		/* EXEC SQL SELECT ROWID INTO :l_rowid:i_rowid from pro_request_mt_dm where 
		REQUEST_SEQ = (SELECT MIN(REQUEST_SEQ) FROM pro_request_mt_dm WHERE STATUS = '0') and rownum < 2 FOR UPDATE NOWAIT; */ 
#line 149 "Daemon_MT_DM.pc"

{
#line 148 "Daemon_MT_DM.pc"
  struct sqlexd sqlstm;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqlvsn = 12;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.arrsiz = 1;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqladtp = &sqladt;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqltdsp = &sqltds;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.stmt = "select ROWID into :b0:b1  from pro_request_mt_dm where (REQ\
UEST_SEQ=(select min(REQUEST_SEQ)  from pro_request_mt_dm where STATUS='0') an\
d rownum<2) for update nowait ";
#line 148 "Daemon_MT_DM.pc"
  sqlstm.iters = (unsigned int  )1;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.offset = (unsigned int  )20;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.selerr = (unsigned short)1;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.cud = sqlcud0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)l_rowid;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[0] = (unsigned long )19;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqindv[0] = (         short *)&i_rowid;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 148 "Daemon_MT_DM.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 148 "Daemon_MT_DM.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 148 "Daemon_MT_DM.pc"
}

#line 149 "Daemon_MT_DM.pc"
	
		if (sqlca.sqlcode == -54)
		{
			continue;
		}
		IS_ANY_ORA_ERROR
		if (sqlca.sqlcode == 1403)
		{
			/* EXEC SQL COMMIT; */ 
#line 157 "Daemon_MT_DM.pc"

{
#line 157 "Daemon_MT_DM.pc"
   struct sqlexd sqlstm;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.sqlvsn = 12;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.arrsiz = 1;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.sqladtp = &sqladt;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.sqltdsp = &sqltds;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.iters = (unsigned int  )1;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.offset = (unsigned int  )39;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.cud = sqlcud0;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 157 "Daemon_MT_DM.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 157 "Daemon_MT_DM.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 157 "Daemon_MT_DM.pc"
}

#line 157 "Daemon_MT_DM.pc"

			IS_ANY_ORA_ERROR;
			continue;
		}
		/* EXEC SQL UPDATE pro_request_mt_dm SET STATUS = '1' where ROWID=:l_rowid; */ 
#line 161 "Daemon_MT_DM.pc"

{
#line 161 "Daemon_MT_DM.pc"
  struct sqlexd sqlstm;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqlvsn = 12;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.arrsiz = 1;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqladtp = &sqladt;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqltdsp = &sqltds;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.stmt = "update pro_request_mt_dm  set STATUS='1' where ROWID=:b0";
#line 161 "Daemon_MT_DM.pc"
  sqlstm.iters = (unsigned int  )1;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.offset = (unsigned int  )54;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.cud = sqlcud0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)l_rowid;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[0] = (unsigned long )19;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqindv[0] = (         short *)0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 161 "Daemon_MT_DM.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 161 "Daemon_MT_DM.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 161 "Daemon_MT_DM.pc"
}

#line 161 "Daemon_MT_DM.pc"

		IS_ANY_ORA_ERROR
		/* EXEC SQL COMMIT; */ 
#line 163 "Daemon_MT_DM.pc"

{
#line 163 "Daemon_MT_DM.pc"
  struct sqlexd sqlstm;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.sqlvsn = 12;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.arrsiz = 1;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.sqladtp = &sqladt;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.sqltdsp = &sqltds;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.iters = (unsigned int  )1;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.offset = (unsigned int  )73;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.cud = sqlcud0;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 163 "Daemon_MT_DM.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 163 "Daemon_MT_DM.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 163 "Daemon_MT_DM.pc"
}

#line 163 "Daemon_MT_DM.pc"

		IS_ANY_ORA_ERROR
		
		/* EXEC SQL SELECT *
		INTO :l_request_mt:i_request_mt
		from pro_request_mt_dm where ROWID=:l_rowid FOR UPDATE NOWAIT; */ 
#line 168 "Daemon_MT_DM.pc"

{
#line 166 "Daemon_MT_DM.pc"
  struct sqlexd sqlstm;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqlvsn = 12;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.arrsiz = 8;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqladtp = &sqladt;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqltdsp = &sqltds;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.stmt = "select * into :s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11\
:s12 ,:s13:s14   from pro_request_mt_dm where ROWID=:b2 for update nowait ";
#line 166 "Daemon_MT_DM.pc"
  sqlstm.iters = (unsigned int  )1;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.offset = (unsigned int  )88;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.selerr = (unsigned short)1;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.cud = sqlcud0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)&l_request_mt->h_request_seq;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[0] = (         short *)&i_request_mt->i_request_seq;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[1] = (unsigned char  *)l_request_mt->h_proc_name;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[1] = (unsigned long )101;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[1] = (         short *)&i_request_mt->i_proc_name;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[1] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[2] = (unsigned char  *)l_request_mt->h_environ_data;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[2] = (unsigned long )2001;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[2] = (         short *)&i_request_mt->i_environ_data;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[2] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[3] = (unsigned char  *)l_request_mt->h_proc_data;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[3] = (unsigned long )4001;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[3] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[3] = (         short *)&i_request_mt->i_proc_data;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[3] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[3] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[3] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[3] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[4] = (unsigned char  *)l_request_mt->h_status_ind;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[4] = (unsigned long )3;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[4] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[4] = (         short *)&i_request_mt->i_status_ind;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[4] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[4] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[4] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[4] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[5] = (unsigned char  *)l_request_mt->h_usr;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[5] = (unsigned long )15;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[5] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[5] = (         short *)&i_request_mt->i_usr;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[5] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[5] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[5] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[5] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[6] = (unsigned char  *)l_request_mt->h_error_det;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[6] = (unsigned long )4001;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[6] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[6] = (         short *)&i_request_mt->i_error_det;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[6] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[6] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[6] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[6] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstv[7] = (unsigned char  *)l_rowid;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhstl[7] = (unsigned long )19;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqhsts[7] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqindv[7] = (         short *)0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqinds[7] = (         int  )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqharm[7] = (unsigned long )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqadto[7] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqtdso[7] = (unsigned short )0;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 166 "Daemon_MT_DM.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 166 "Daemon_MT_DM.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 166 "Daemon_MT_DM.pc"
}

#line 168 "Daemon_MT_DM.pc"

		IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(ERR_REC_NOTFND,"pro_request_mt_dm","FATAL ERR","ROWID");
		strcat(l_request_mt -> h_environ_data,l_data_fld_sep_str);
		strcat(l_request_mt -> h_proc_data,l_data_fld_sep_str);
		strcat(l_request_mt -> h_error_det,l_data_fld_sep_str);
	
		int_ret_val = CO_Rtv_EnvStruct(p_intlenv_data_struct_h,l_request_mt -> h_environ_data);
		if (strlen(l_request_mt -> h_error_det) != 0)
		{
			int_ret_val = CO_Rtv_ErrStruct(l_request_mt -> h_error_det,l_debug_info_ptr);
		}

		if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_INSTRUMENT") == 0)
		{
			INTL_WARNING;
			l_mt_instrument_struct_h =  (MT_INSTRUMENT_STRUCT_H *)calloc(1,sizeof(MT_INSTRUMENT_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_instrument_struct_h);
			memset(l_mt_instrument_struct_h,NULL,sizeof(MT_INSTRUMENT_STRUCT_H));
			int_ret_val = Populate_MT_INSTRUMENT(l_mt_instrument_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_INSTRUMENT\n",NULL,NULL);
			if((MT_UpdMT_INSTRUMENT(l_mt_instrument_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTRUMENTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTRUMENTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_instrument_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_HOLIDAY") == 0)
		{
			INTL_WARNING;
			l_mt_holiday_struct_h =  (MT_HOLIDAY_STRUCT_H *)calloc(1,sizeof(MT_HOLIDAY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_holiday_struct_h);
			memset(l_mt_holiday_struct_h,NULL,sizeof(MT_HOLIDAY_STRUCT_H));
			int_ret_val = Populate_MT_HOLIDAY(l_mt_holiday_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_HOLIDAY\n",NULL,NULL);
			if((MT_UpdMT_HOLIDAY(l_mt_holiday_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_HOLIDAYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_HOLIDAYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_holiday_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_NO_DELV") == 0)
		{
			INTL_WARNING;
			l_mt_no_delv_struct_h =  (MT_NO_DELV_STRUCT_H *)calloc(1,sizeof(MT_NO_DELV_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_no_delv_struct_h);
			memset(l_mt_no_delv_struct_h,NULL,sizeof(MT_NO_DELV_STRUCT_H));
			int_ret_val = Populate_MT_NO_DELV(l_mt_no_delv_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_NO_DELV\n",NULL,NULL);
			if((MT_UpdMT_NO_DELV(l_mt_no_delv_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_NO_DELVSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_NO_DELVFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_no_delv_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_COMPANY") == 0)
		{
			INTL_WARNING;
			l_mt_company_struct_h =  (MT_COMPANY_STRUCT_H *)calloc(1,sizeof(MT_COMPANY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_company_struct_h);
			memset(l_mt_company_struct_h,NULL,sizeof(MT_COMPANY_STRUCT_H));
			int_ret_val = Populate_MT_COMPANY(l_mt_company_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_COMPANY\n",NULL,NULL);
			if((MT_UpdMT_COMPANY(l_mt_company_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_COMPANYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_COMPANYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_company_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_SETTL_CAL") == 0)
		{
			INTL_WARNING;
			l_mt_settl_cal_struct_h =  (MT_SETTL_CAL_STRUCT_H *)calloc(1,sizeof(MT_SETTL_CAL_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_settl_cal_struct_h);
			memset(l_mt_settl_cal_struct_h,NULL,sizeof(MT_SETTL_CAL_STRUCT_H));
			int_ret_val = Populate_MT_SETTL_CAL(l_mt_settl_cal_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_SETTL_CAL\n",NULL,NULL);
			if((MT_UpdMT_SETTL_CAL(l_mt_settl_cal_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_SETTL_CALSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_SETTL_CALFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_settl_cal_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_RBI_MONITORY") == 0)
		{
			INTL_WARNING;
			l_mt_rbi_monitory_struct_h =  (MT_RBI_MONITORY_STRUCT_H *)calloc(1,sizeof(MT_RBI_MONITORY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_rbi_monitory_struct_h);
			memset(l_mt_rbi_monitory_struct_h,NULL,sizeof(MT_RBI_MONITORY_STRUCT_H));
			int_ret_val = Populate_MT_RBI_MONITORY(l_mt_rbi_monitory_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_RBI_MONITORY\n",NULL,NULL);
			if((MT_UpdMT_RBI_MONITORY(l_mt_rbi_monitory_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RBI_MONITORYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RBI_MONITORYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_rbi_monitory_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTC_DET") == 0)
		{
			INTL_WARNING;
			l_mt_ptc_det_struct_h =  (MT_PTC_DET_STRUCT_H *)calloc(1,sizeof(MT_PTC_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_ptc_det_struct_h);
			memset(l_mt_ptc_det_struct_h,NULL,sizeof(MT_PTC_DET_STRUCT_H));
			int_ret_val = Populate_MT_PTC_DET(l_mt_ptc_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTC_DET\n",NULL,NULL);
			if((MT_UpdMT_PTC_DET(l_mt_ptc_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTC_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTC_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_ptc_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_RED_DET") == 0)
		{
			INTL_WARNING;
			l_mt_red_det_struct_h =  (MT_RED_DET_STRUCT_H *)calloc(1,sizeof(MT_RED_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_red_det_struct_h);
			memset(l_mt_red_det_struct_h,NULL,sizeof(MT_RED_DET_STRUCT_H));
			int_ret_val = Populate_MT_RED_DET(l_mt_red_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_RED_DET\n",NULL,NULL);
			if((MT_UpdMT_RED_DET(l_mt_red_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RED_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RED_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_red_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PC_DET") == 0)
		{
			INTL_WARNING;
			l_mt_pc_det_struct_h =  (MT_PC_DET_STRUCT_H *)calloc(1,sizeof(MT_PC_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_pc_det_struct_h);
			memset(l_mt_pc_det_struct_h,NULL,sizeof(MT_PC_DET_STRUCT_H));
			int_ret_val = Populate_MT_PC_DET(l_mt_pc_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PC_DET\n",NULL,NULL);
			if((MT_UpdMT_PC_DET(l_mt_pc_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PC_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PC_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_pc_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_RESET_DET") == 0)
		{
			INTL_WARNING;
			l_mt_reset_det_struct_h =  (MT_RESET_DET_STRUCT_H *)calloc(1,sizeof(MT_RESET_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_reset_det_struct_h);
			memset(l_mt_reset_det_struct_h,NULL,sizeof(MT_RESET_DET_STRUCT_H));
			int_ret_val = Populate_MT_RESET_DET(l_mt_reset_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_RESET_DET\n",NULL,NULL);
			if((MT_UpdMT_RESET_DET(l_mt_reset_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RESET_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RESET_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_reset_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_DAILY_FLOAT_RATE") == 0)
		{
			INTL_WARNING;
			l_mt_daily_float_rate_struct_h =  (MT_DAILY_FLOAT_RATE_STRUCT_H *)calloc(1,sizeof(MT_DAILY_FLOAT_RATE_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_daily_float_rate_struct_h);
			memset(l_mt_daily_float_rate_struct_h,NULL,sizeof(MT_DAILY_FLOAT_RATE_STRUCT_H));
			int_ret_val = Populate_MT_DAILY_FLOAT_RATE(l_mt_daily_float_rate_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_DAILY_FLOAT_RATE\n",NULL,NULL);
			if((MT_UpdMT_DAILY_FLOAT_RATE(l_mt_daily_float_rate_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR)) {
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_DAILY_FLOAT_RATESUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_DAILY_FLOAT_RATEFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_daily_float_rate_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_FLRATE_INSTRUMENT") == 0)
		{
			INTL_WARNING;
			l_mt_flrate_instrument_struct_h =  (MT_FLRATE_INSTRUMENT_STRUCT_H *)calloc(1,sizeof(MT_FLRATE_INSTRUMENT_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_flrate_instrument_struct_h);
			memset(l_mt_flrate_instrument_struct_h,NULL,sizeof(MT_FLRATE_INSTRUMENT_STRUCT_H));
			int_ret_val = Populate_MT_FLRATE_INSTRUMENT(l_mt_flrate_instrument_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_FLRATE_INSTRUMENT\n",NULL,NULL);
			if((MT_UpdMT_FLRATE_INSTRUMENT(l_mt_flrate_instrument_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_FLRATE_INSTRUMENTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_FLRATE_INSTRUMENTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_flrate_instrument_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PARTY") == 0)
		{
			INTL_WARNING;
			l_mt_party_struct_h =  (MT_PARTY_STRUCT_H *)calloc(1,sizeof(MT_PARTY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_party_struct_h);
			memset(l_mt_party_struct_h,NULL,sizeof(MT_PARTY_STRUCT_H));
			int_ret_val = Populate_MT_PARTY(l_mt_party_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PARTY\n",NULL,NULL);
			if((MT_UpdMT_PARTY(l_mt_party_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PARTYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PARTYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_party_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTY_BANKDET") == 0)
		{
			INTL_WARNING;
			l_mt_pty_bankdet_struct_h =  (MT_PTY_BANKDET_STRUCT_H *)calloc(1,sizeof(MT_PTY_BANKDET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_pty_bankdet_struct_h);
			memset(l_mt_pty_bankdet_struct_h,NULL,sizeof(MT_PTY_BANKDET_STRUCT_H));
			int_ret_val = Populate_MT_PTY_BANKDET(l_mt_pty_bankdet_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTY_BANKDET\n",NULL,NULL);
			if((MT_UpdMT_PTY_BANKDET(l_mt_pty_bankdet_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_BANKDETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_BANKDETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_pty_bankdet_struct_h);
		}
      else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTY_FUND_DET") == 0)
      {
         /* ADD BY ASP, FOR PARTY FUND DETAILS DATA MAGRATION, 07SEP-06*/
         INTL_WARNING;
         l_mt_pty_fund_det_struct_h =  (MT_PTY_FUND_DET_STRUCT_H *)calloc(1,sizeof(MT_PTY_FUND_DET_STRUCT_H));
         APL_MALLOC_FAIL_LOC_A(l_mt_pty_fund_det_struct_h);
         memset(l_mt_pty_fund_det_struct_h,NULL,sizeof(MT_PTY_FUND_DET_STRUCT_H));
         int_ret_val = Populate_MT_PTY_FUND_DET(l_mt_pty_fund_det_struct_h,l_request_mt -> h_proc_data);
         CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTY_FUND_DET\n",NULL,NULL);
         if((MT_UpdMT_PTY_FUND_DET(l_mt_pty_fund_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
         {
            CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_FUND_DETSUCCESS \n",NULL,NULL);
            int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
         else
         {CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY__FUND_DETFAILURE \n",NULL,NULL);
             int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
         }
         APL_FREE(l_mt_pty_fund_det_struct_h);
         /*END OF FUND DET*/
      }
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_INSTR_EXCH_DET") == 0)
		{
			INTL_WARNING;
			l_mt_instr_exch_det_struct_h =  (MT_INSTR_EXCH_DET_STRUCT_H *)calloc(1,sizeof(MT_INSTR_EXCH_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_instr_exch_det_struct_h);
			memset(l_mt_instr_exch_det_struct_h,NULL,sizeof(MT_INSTR_EXCH_DET_STRUCT_H));
			int_ret_val = Populate_MT_INSTR_EXCH_DET(l_mt_instr_exch_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_INSTR_EXCH_DET\n",NULL,NULL);
			if((MT_UpdMT_INSTR_EXCH_DET(l_mt_instr_exch_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTR_EXCH_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTR_EXCH_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_instr_exch_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_CAENTITLEMENT") == 0)
		{
			INTL_WARNING;
			l_caentitlement_struct_h =  (CAENTITLEMENT_STRUCT_H *)calloc(1,sizeof(CAENTITLEMENT_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_caentitlement_struct_h);
			memset(l_caentitlement_struct_h,NULL,sizeof(CAENTITLEMENT_STRUCT_H));
			int_ret_val = Populate_CAENTITLEMENT(l_caentitlement_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdCAENTITLEMENT\n",NULL,NULL);
			if((MT_UpdCAENTITLEMENT(l_caentitlement_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdCAENTITLEMENTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdCAENTITLEMENTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_caentitlement_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_INSL_ENTRY") == 0)
		{
			INTL_WARNING;
			l_mt_insl_entry_struct_h =  (MT_INSL_ENTRY_STRUCT_H *)calloc(1,sizeof(MT_INSL_ENTRY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_insl_entry_struct_h);
			memset(l_mt_insl_entry_struct_h,NULL,sizeof(MT_INSL_ENTRY_STRUCT_H));
			int_ret_val = Populate_MT_INSL_ENTRY(l_mt_insl_entry_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_INSL_ENTRY\n",NULL,NULL);
			if((MT_UpdMT_INSL_ENTRY(l_mt_insl_entry_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSL_ENTRYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSL_ENTRYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_insl_entry_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_CR_AGENCY") == 0)
		{
			INTL_WARNING;
			l_mt_cr_agency_struct_h =  (MT_CR_AGENCY_STRUCT_H *)calloc(1,sizeof(MT_CR_AGENCY_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_cr_agency_struct_h);
			memset(l_mt_cr_agency_struct_h,NULL,sizeof(MT_CR_AGENCY_STRUCT_H));
			int_ret_val = Populate_MT_CR_AGENCY(l_mt_cr_agency_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_CR_AGENCY\n",NULL,NULL);
			if((MT_UpdMT_CR_AGENCY(l_mt_cr_agency_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CR_AGENCYSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CR_AGENCYFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_cr_agency_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_EXCH_DEPO") == 0)
		{
			INTL_WARNING;
			l_mt_exch_depo_struct_h =  (MT_EXCH_DEPO_STRUCT_H *)calloc(1,sizeof(MT_EXCH_DEPO_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_exch_depo_struct_h);
			memset(l_mt_exch_depo_struct_h,NULL,sizeof(MT_EXCH_DEPO_STRUCT_H));
			int_ret_val = Populate_MT_EXCH_DEPO(l_mt_exch_depo_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_EXCH_DEPO\n",NULL,NULL);
			if((MT_UpdMT_EXCH_DEPO(l_mt_exch_depo_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_EXCH_DEPOSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_EXCH_DEPOFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_exch_depo_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_RED_DP_DET") == 0)
		{
			INTL_WARNING;
			l_mt_red_dp_det_struct_h =  (MT_RED_DP_DET_STRUCT_H *)calloc(1,sizeof(MT_RED_DP_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_red_dp_det_struct_h);
			memset(l_mt_red_dp_det_struct_h,NULL,sizeof(MT_RED_DP_DET_STRUCT_H));
			int_ret_val = Populate_MT_RED_DP_DET(l_mt_red_dp_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_RED_DP_DET\n",NULL,NULL);
			if((MT_UpdMT_RED_DP_DET(l_mt_red_dp_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RED_DP_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_RED_DP_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_red_dp_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_INSTR_RATING_DET") == 0)
		{
			INTL_WARNING;
			l_mt_instr_rating_det_struct_h =  (MT_INSTR_RATING_DET_STRUCT_H *)calloc(1,sizeof(MT_INSTR_RATING_DET_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_instr_rating_det_struct_h);
			memset(l_mt_instr_rating_det_struct_h,NULL,sizeof(MT_INSTR_RATING_DET_STRUCT_H));
			int_ret_val = Populate_MT_INSTR_RATING_DET(l_mt_instr_rating_det_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_INSTR_RATING_DET\n",NULL,NULL);
			if((MT_UpdMT_INSTR_RATING_DET(l_mt_instr_rating_det_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR)) {
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTR_RATING_DETSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_INSTR_RATING_DETFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_instr_rating_det_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTY_EXCH_CLN_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_pty_exch_cln_map_struct_h =  (MT_PTY_EXCH_CLN_MAP_STRUCT_H *)calloc(1,sizeof(MT_PTY_EXCH_CLN_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_pty_exch_cln_map_struct_h);
			memset(l_mt_pty_exch_cln_map_struct_h,NULL,sizeof(MT_PTY_EXCH_CLN_MAP_STRUCT_H));
			int_ret_val = Populate_MT_PTY_EXCH_CLN_MAP(l_mt_pty_exch_cln_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTY_EXCH_CLN_MAP\n",NULL,NULL);
			if((MT_UpdMT_PTY_EXCH_CLN_MAP(l_mt_pty_exch_cln_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR)) {
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_EXCH_CLN_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_EXCH_CLN_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_pty_exch_cln_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_CLN_INST_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_cln_inst_map_struct_h =  (MT_CLN_INST_MAP_STRUCT_H *)calloc(1,sizeof(MT_CLN_INST_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_cln_inst_map_struct_h);
			memset(l_mt_cln_inst_map_struct_h,NULL,sizeof(MT_CLN_INST_MAP_STRUCT_H));
			int_ret_val = Populate_MT_CLN_INST_MAP(l_mt_cln_inst_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_CLN_INST_MAP\n",NULL,NULL);
			if((MT_UpdMT_CLN_INST_MAP(l_mt_cln_inst_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLN_INST_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLN_INST_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_cln_inst_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_CLIENT") == 0)
		{
			INTL_WARNING;
			l_mt_client_struct_h =  (MT_CLIENT_STRUCT_H *)calloc(1,sizeof(MT_CLIENT_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_client_struct_h);
			memset(l_mt_client_struct_h,NULL,sizeof(MT_CLIENT_STRUCT_H));
			int_ret_val = Populate_MT_CLIENT(l_mt_client_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_CLIENT\n",NULL,NULL);
			if((MT_UpdMT_CLIENT(l_mt_client_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLIENTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLIENTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_client_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_CLI_EXCH_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_cli_exch_map_struct_h =  (MT_CLI_EXCH_MAP_STRUCT_H *)calloc(1,sizeof(MT_CLI_EXCH_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_cli_exch_map_struct_h);
			memset(l_mt_cli_exch_map_struct_h,NULL,sizeof(MT_CLI_EXCH_MAP_STRUCT_H));
			int_ret_val = Populate_MT_CLI_EXCH_MAP(l_mt_cli_exch_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_CLI_EXCH_MAP\n",NULL,NULL);
			if((MT_UpdMT_CLI_EXCH_MAP(l_mt_cli_exch_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLI_EXCH_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLI_EXCH_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_cli_exch_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_CLI_DEPO_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_cli_depo_map_struct_h =  (MT_CLI_DEPO_MAP_STRUCT_H *)calloc(1,sizeof(MT_CLI_DEPO_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_cli_depo_map_struct_h);
			memset(l_mt_cli_depo_map_struct_h,NULL,sizeof(MT_CLI_DEPO_MAP_STRUCT_H));
			int_ret_val = Populate_MT_CLI_DEPO_MAP(l_mt_cli_depo_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_CLI_DEPO_MAP\n",NULL,NULL);
			if((MT_UpdMT_CLI_DEPO_MAP(l_mt_cli_depo_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLI_DEPO_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_CLI_DEPO_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_cli_depo_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTY_EXCH_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_pty_exch_map_struct_h =  (MT_PTY_EXCH_MAP_STRUCT_H *)calloc(1,sizeof(MT_PTY_EXCH_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_pty_exch_map_struct_h);
			memset(l_mt_pty_exch_map_struct_h,NULL,sizeof(MT_PTY_EXCH_MAP_STRUCT_H));
			int_ret_val = Populate_MT_PTY_EXCH_MAP(l_mt_pty_exch_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTY_EXCH_MAP\n",NULL,NULL);
			if((MT_UpdMT_PTY_EXCH_MAP(l_mt_pty_exch_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_EXCH_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_EXCH_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_pty_exch_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_DEPO_PART") == 0)
		{
			INTL_WARNING;
			l_mt_depo_part_struct_h =  (MT_DEPO_PART_STRUCT_H *)calloc(1,sizeof(MT_DEPO_PART_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_depo_part_struct_h);
			memset(l_mt_depo_part_struct_h,NULL,sizeof(MT_DEPO_PART_STRUCT_H));
			int_ret_val = Populate_MT_DEPO_PART(l_mt_depo_part_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_DEPO_PART\n",NULL,NULL);
			if((MT_UpdMT_DEPO_PART(l_mt_depo_part_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_DEPO_PARTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_DEPO_PARTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_depo_part_struct_h);
		}
		/******************** Added By Sundar ******************************/
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_PTY_DEPO_MAP") == 0)
		{
			INTL_WARNING;
			l_mt_pty_depo_map_struct_h =  (MT_PTY_DEPO_MAP_STRUCT_H *)calloc(1,sizeof(MT_PTY_DEPO_MAP_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_mt_pty_depo_map_struct_h);
			memset(l_mt_pty_depo_map_struct_h,NULL,sizeof(MT_PTY_DEPO_MAP_STRUCT_H));
			int_ret_val = Populate_MT_PTY_DEPO_MAP(l_mt_pty_depo_map_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_PTY_DEPO_MAP\n",NULL,NULL);
			if((MT_UpdMT_PTY_DEPO_MAP(l_mt_pty_depo_map_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_DEPO_MAPSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_PTY_DEPO_MAPFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_mt_pty_depo_map_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_DL_DEAL") == 0)
		{
			INTL_WARNING;
			l_dl_deal_struct_h =  (DL_DEAL_STRUCT_H *)calloc(1,sizeof(DL_DEAL_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_dl_deal_struct_h);
			memset(l_dl_deal_struct_h,NULL,sizeof(DL_DEAL_STRUCT_H));
			int_ret_val = Populate_DL_DEAL(l_dl_deal_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdDL_DEAL\n",NULL,NULL);
			if((MT_UpdDL_DEAL(l_dl_deal_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdDL_DEALSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdDL_DEALFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_dl_deal_struct_h);
		}


		else if (strcmp(l_request_mt -> h_proc_name,"wrp_DL_SAFEK") == 0)
		{
			INTL_WARNING;
			l_dl_safek_struct_h =  (DL_SAFEK_STRUCT_H *)calloc(1,sizeof(DL_SAFEK_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_dl_safek_struct_h);
			memset(l_dl_safek_struct_h,NULL,sizeof(DL_SAFEK_STRUCT_H));
			int_ret_val = Populate_DL_SAFEK(l_dl_safek_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdDL_SAFEK\n",NULL,NULL);
			if((MT_UpdDL_SAFEK(l_dl_safek_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR)) 
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdDL_SAFEKSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdDL_SAFEKFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_dl_safek_struct_h);
		}
		else if (strcmp(l_request_mt -> h_proc_name,"wrp_CAEVENT") == 0)
		{
			INTL_WARNING;
			l_caevent_struct_h =  (CAEVENT_STRUCT_H *)calloc(1,sizeof(CAEVENT_STRUCT_H));
			APL_MALLOC_FAIL_LOC_A(l_caevent_struct_h);
			memset(l_caevent_struct_h,NULL,sizeof(CAEVENT_STRUCT_H));
			int_ret_val = Populate_CAEVENT(l_caevent_struct_h,l_request_mt -> h_proc_data);
			CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdCAEVENT\n",NULL,NULL);
			if((MT_UpdCAEVENT(l_caevent_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
			{
				CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdCAEVENTSUCCESS \n",NULL,NULL);
				int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
			else
			{CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdCAEVENTFAILURE \n",NULL,NULL);
				int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
			}
			APL_FREE(l_caevent_struct_h);
		}
     	else if (strcmp(l_request_mt -> h_proc_name,"wrp_MT_REGDETAILS") == 0)
      {
       //ADD BY ASP, FOR REGDETAILS - 01sep
       INTL_WARNING;
       l_mt_regdetails_struct_h = (MT_REGDETAILS_STRUCT_H *)calloc(1,sizeof(MT_REGDETAILS_STRUCT_H));
       APL_MALLOC_FAIL_LOC_A(l_mt_regdetails_struct_h);
       memset(l_mt_regdetails_struct_h,NULL,sizeof(MT_REGDETAILS_STRUCT_H));
       int_ret_val = Populate_MT_REGDETAILS(l_mt_regdetails_struct_h,l_request_mt -> h_proc_data);
       CO_ProcMonitor(APL_OUT_FILE,"Now calling MT_UpdMT_REGDETAILS\n",NULL,NULL);
       if((MT_UpdMT_REGDETAILS(l_mt_regdetails_struct_h,l_debug_info_ptr) == APL_SUCCESS) && (CHECK_EXISTANCE_OF_ERROR))
       {
          CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_REGDETAILSSUCCESS \n",NULL,NULL);
          int_ret_val = Batch_Proc_MarkSuccessProcess(l_rowid,chr_h_error_desc);}
       else
       {CO_ProcMonitor(APL_OUT_FILE,"Returned from MT_UpdMT_REGDETAILSYFAILURE \n",NULL,NULL);
          int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
       }
       APL_FREE(l_mt_regdetails_struct_h);
      }



		
		
		
		/******************** Added By Sundar ******************************/
		else
		{
			INTL_WARNING
				int_ret_val = CO_InsertErr(l_debug_info_ptr,
						FUNC_NF,
						APL_NULL_STRING,
						APL_NULL_STRING,
						APL_NULL_STRING,
						__LINE__,
						__FILE__);
			int_ret_val = Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);
		}
		CO_FreeErrLst(l_debug_info_ptr);
	}
	APL_GOBACK_SUCCESS;
RETURN_SUCCESS:
   /* EXEC SQL COMMIT ; */ 
#line 818 "Daemon_MT_DM.pc"

{
#line 818 "Daemon_MT_DM.pc"
   struct sqlexd sqlstm;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.sqlvsn = 12;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.arrsiz = 8;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.sqladtp = &sqladt;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.sqltdsp = &sqltds;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.iters = (unsigned int  )1;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.offset = (unsigned int  )135;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.cud = sqlcud0;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 818 "Daemon_MT_DM.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 818 "Daemon_MT_DM.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 818 "Daemon_MT_DM.pc"
}

#line 818 "Daemon_MT_DM.pc"

    CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Maintenance Daemon\n",l_debug_info_ptr,NULL);
    exit(0);
RETURN_FAILURE:
   /* EXEC SQL ROLLBACK; */ 
#line 822 "Daemon_MT_DM.pc"

{
#line 822 "Daemon_MT_DM.pc"
   struct sqlexd sqlstm;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.sqlvsn = 12;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.arrsiz = 8;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.sqladtp = &sqladt;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.sqltdsp = &sqltds;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.iters = (unsigned int  )1;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.offset = (unsigned int  )150;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.cud = sqlcud0;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 822 "Daemon_MT_DM.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 822 "Daemon_MT_DM.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 822 "Daemon_MT_DM.pc"
}

#line 822 "Daemon_MT_DM.pc"

    CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Maintenance Daemon\n",NULL,NULL);
    exit(-1);
}
int Batch_Proc_MarkSuccessProcess(char *p_ora_rowid,char *p_return_value)
{
	/* EXEC SQL UPDATE pro_request_mt_dm set STATUS = '2',ERROR_DET='SUCCESS'||:p_return_value
	where rowid=:p_ora_rowid; */ 
#line 829 "Daemon_MT_DM.pc"

{
#line 828 "Daemon_MT_DM.pc"
 struct sqlexd sqlstm;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqlvsn = 12;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.arrsiz = 8;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqladtp = &sqladt;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqltdsp = &sqltds;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.stmt = "update pro_request_mt_dm  set STATUS='2',ERROR_DET=('SUCCESS\
'||:b0) where rowid=:b1";
#line 828 "Daemon_MT_DM.pc"
 sqlstm.iters = (unsigned int  )1;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.offset = (unsigned int  )165;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.cud = sqlcud0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_return_value;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhstl[0] = (unsigned long )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_ora_rowid;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhstl[1] = (unsigned long )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 828 "Daemon_MT_DM.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 828 "Daemon_MT_DM.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 828 "Daemon_MT_DM.pc"
}

#line 829 "Daemon_MT_DM.pc"

	IS_ANY_ORA_ERROR;
	/* EXEC SQL COMMIT ; */ 
#line 831 "Daemon_MT_DM.pc"

{
#line 831 "Daemon_MT_DM.pc"
 struct sqlexd sqlstm;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.sqlvsn = 12;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.arrsiz = 8;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.sqladtp = &sqladt;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.sqltdsp = &sqltds;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.iters = (unsigned int  )1;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.offset = (unsigned int  )188;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.cud = sqlcud0;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 831 "Daemon_MT_DM.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 831 "Daemon_MT_DM.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 831 "Daemon_MT_DM.pc"
}

#line 831 "Daemon_MT_DM.pc"

	IS_ANY_ORA_ERROR;
	S_NON_DCE_ERASE_DUMMY_WARNING;
RETURN_SUCCESS :
	return(APL_SUCCESS);
RETURN_FAILURE :
	return(APL_FAILURE);
}
int Proc_MarkFailProcess(char *p_ora_rowid, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   short int_ret_val  =  0;
   /* EXEC SQL ROLLBACK ; */ 
#line 842 "Daemon_MT_DM.pc"

{
#line 842 "Daemon_MT_DM.pc"
   struct sqlexd sqlstm;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.sqlvsn = 12;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.arrsiz = 8;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.sqladtp = &sqladt;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.sqltdsp = &sqltds;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.iters = (unsigned int  )1;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.offset = (unsigned int  )203;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.cud = sqlcud0;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 842 "Daemon_MT_DM.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 842 "Daemon_MT_DM.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 842 "Daemon_MT_DM.pc"
}

#line 842 "Daemon_MT_DM.pc"

   IS_ANY_ORA_ERROR;
   int_ret_val = APL_FAILURE;
   S_NON_DCE_ERASE_DUMMY_WARNING;
   int_ret_val = CO_Rtv_ErrString(l_debug_info_ptr,l_request_mt -> h_error_det );
	printf("Error |%s|\n",l_request_mt -> h_error_det);
   if(strlen(l_request_mt -> h_error_det )>0)
   {
     /* EXEC SQL update  pro_request_mt_dm set STATUS = '3',ERROR_DET=:l_request_mt -> h_error_det
					      where rowid=:p_ora_rowid; */ 
#line 851 "Daemon_MT_DM.pc"

{
#line 850 "Daemon_MT_DM.pc"
     struct sqlexd sqlstm;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqlvsn = 12;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.arrsiz = 8;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqladtp = &sqladt;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqltdsp = &sqltds;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.stmt = "update pro_request_mt_dm  set STATUS='3',ERROR_DET=:b0 w\
here rowid=:b1";
#line 850 "Daemon_MT_DM.pc"
     sqlstm.iters = (unsigned int  )1;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.offset = (unsigned int  )218;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.cud = sqlcud0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqlety = (unsigned short)256;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.occurs = (unsigned int  )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhstv[0] = (unsigned char  *)(l_request_mt->h_error_det);
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhstl[0] = (unsigned long )4001;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhsts[0] = (         int  )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqindv[0] = (         short *)0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqinds[0] = (         int  )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqharm[0] = (unsigned long )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqadto[0] = (unsigned short )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqtdso[0] = (unsigned short )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhstv[1] = (unsigned char  *)p_ora_rowid;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhstl[1] = (unsigned long )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqhsts[1] = (         int  )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqindv[1] = (         short *)0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqinds[1] = (         int  )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqharm[1] = (unsigned long )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqadto[1] = (unsigned short )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqtdso[1] = (unsigned short )0;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqphsv = sqlstm.sqhstv;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqphsl = sqlstm.sqhstl;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqphss = sqlstm.sqhsts;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqpind = sqlstm.sqindv;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqpins = sqlstm.sqinds;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqparm = sqlstm.sqharm;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqparc = sqlstm.sqharc;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqpadto = sqlstm.sqadto;
#line 850 "Daemon_MT_DM.pc"
     sqlstm.sqptdso = sqlstm.sqtdso;
#line 850 "Daemon_MT_DM.pc"
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 850 "Daemon_MT_DM.pc"
}

#line 851 "Daemon_MT_DM.pc"

   }
   else
   {
     /* EXEC SQL update  pro_request_mt_dm set STATUS = '2',ERROR_DET='SUCCESS'
					      where rowid=:p_ora_rowid; */ 
#line 856 "Daemon_MT_DM.pc"

{
#line 855 "Daemon_MT_DM.pc"
     struct sqlexd sqlstm;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqlvsn = 12;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.arrsiz = 8;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqladtp = &sqladt;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqltdsp = &sqltds;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.stmt = "update pro_request_mt_dm  set STATUS='2',ERROR_DET='SUCC\
ESS' where rowid=:b0";
#line 855 "Daemon_MT_DM.pc"
     sqlstm.iters = (unsigned int  )1;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.offset = (unsigned int  )241;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.cud = sqlcud0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqlety = (unsigned short)256;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.occurs = (unsigned int  )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqhstv[0] = (unsigned char  *)p_ora_rowid;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqhstl[0] = (unsigned long )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqhsts[0] = (         int  )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqindv[0] = (         short *)0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqinds[0] = (         int  )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqharm[0] = (unsigned long )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqadto[0] = (unsigned short )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqtdso[0] = (unsigned short )0;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqphsv = sqlstm.sqhstv;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqphsl = sqlstm.sqhstl;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqphss = sqlstm.sqhsts;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqpind = sqlstm.sqindv;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqpins = sqlstm.sqinds;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqparm = sqlstm.sqharm;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqparc = sqlstm.sqharc;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqpadto = sqlstm.sqadto;
#line 855 "Daemon_MT_DM.pc"
     sqlstm.sqptdso = sqlstm.sqtdso;
#line 855 "Daemon_MT_DM.pc"
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 855 "Daemon_MT_DM.pc"
}

#line 856 "Daemon_MT_DM.pc"

   }
  IS_ANY_ORA_ERROR;
   /* EXEC SQL COMMIT; */ 
#line 859 "Daemon_MT_DM.pc"

{
#line 859 "Daemon_MT_DM.pc"
   struct sqlexd sqlstm;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.sqlvsn = 12;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.arrsiz = 8;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.sqladtp = &sqladt;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.sqltdsp = &sqltds;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.iters = (unsigned int  )1;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.offset = (unsigned int  )260;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.cud = sqlcud0;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 859 "Daemon_MT_DM.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 859 "Daemon_MT_DM.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 859 "Daemon_MT_DM.pc"
}

#line 859 "Daemon_MT_DM.pc"

   IS_ANY_ORA_ERROR;
   S_NON_DCE_ERASE_DUMMY_WARNING;
RETURN_SUCCESS :
   return(APL_SUCCESS);
RETURN_FAILURE :
   return(APL_FAILURE);
}


