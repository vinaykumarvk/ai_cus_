
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "CoChk_DlyQtions.pc"
};


static unsigned int sqlctx = 18641459;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,113,0,4,79,0,0,4,3,0,1,0,2,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
36,0,0,2,106,0,4,86,0,0,4,3,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
};


#line 1 "CoChk_DlyQtions.pc"
/*copyright 2005 Polaris Software Lab Limited. All rights reserved.
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
 * Module Name         : MASTERS MAINTAINANCE
 *
 * File Name           : CoChk_DlyQtions.pc
 *
 * Description         : This file contains validations for Daily Quotations in different modes
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 * 26/11/2005   1.0           ANIL          NEW FILE  RFS NO HDFCMT_009
 *
 *********************************************************************/

#include "CO_HostStructdef.h"
#include "sqlca.h"

int MTValDlyQtionsFn(char *p_exch_code,char *p_instr_code,char *p_quot_date,char p_exist,char p_auth,char p_del,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   struct sqlca sqlca;
   char chr_p_pcstatus[3];
   short l_Status;
   int int_exist;
   int int_error_flag = APL_SUCCESS;

#ifdef APL_THREADS
    APL_SET_CONTEXT
    EXEC SQL CONTEXT USE :my_ctx_local;
#endif

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function MTValDlyQtionsFn\n",NULL,NULL);
 }

  l_Status =0;
  int_exist =0;

  memset(chr_p_pcstatus,NULL,3);

  if (!strlen(p_exch_code))
        {
        APL_DATA_MISSING("Exchange Code", APL_NULL_STRING, APL_NULL_STRING);
        int_error_flag = APL_FAILURE;
        }
  if (!strlen(p_instr_code))
        {
        APL_DATA_MISSING("Instrument Code", APL_NULL_STRING, APL_NULL_STRING);
        int_error_flag = APL_FAILURE;
        }
  if (!strlen(p_quot_date))
        {
        APL_DATA_MISSING("Quote Date", APL_NULL_STRING, APL_NULL_STRING);
        int_error_flag = APL_FAILURE;
        }

  if (int_error_flag == APL_FAILURE)
        {
//AIX- Warnings Removal
        int_error_flag = APL_FAILURE;
        APL_GOBACK_FAIL
        }

  /* EXEC SQL SELECT NVL(COUNT(*),0) into int_exist
                FROM MT_DAILY_QUOT
                WHERE EXCH_CODE =:p_exch_code
                AND   INSTR_CODE =:p_instr_code
                AND   QUOT_DATE =:p_quot_date; */ 
#line 83 "CoChk_DlyQtions.pc"

{
#line 79 "CoChk_DlyQtions.pc"
  struct sqlexd sqlstm;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqlvsn = 12;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.arrsiz = 4;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqladtp = &sqladt;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqltdsp = &sqltds;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.stmt = "select NVL(count(*) ,0) into :b0  from MT_DAILY_QUOT where \
((EXCH_CODE=:b1 and INSTR_CODE=:b2) and QUOT_DATE=:b3)";
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.iters = (unsigned int  )1;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.offset = (unsigned int  )5;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.selerr = (unsigned short)1;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.cud = sqlcud0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqlety = (unsigned short)4352;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)&int_exist;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[0] = (         short *)0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[1] = (unsigned char  *)p_exch_code;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[1] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[1] = (         short *)0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[1] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[2] = (unsigned char  *)p_instr_code;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[2] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[2] = (         short *)0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[2] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[3] = (unsigned char  *)p_quot_date;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[3] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[3] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[3] = (         short *)0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[3] = (         int  )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[3] = (unsigned long )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[3] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[3] = (unsigned short )0;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 79 "CoChk_DlyQtions.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 79 "CoChk_DlyQtions.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 79 "CoChk_DlyQtions.pc"
}

#line 83 "CoChk_DlyQtions.pc"

                IS_ANY_ORA_ERROR

  /* EXEC SQL SELECT STATUS into :chr_p_pcstatus:l_Status
                FROM MT_DAILY_QUOT
                WHERE EXCH_CODE =:p_exch_code
                AND   INSTR_CODE =:p_instr_code
                AND   QUOT_DATE =:p_quot_date; */ 
#line 90 "CoChk_DlyQtions.pc"

{
#line 86 "CoChk_DlyQtions.pc"
  struct sqlexd sqlstm;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqlvsn = 12;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.arrsiz = 4;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqladtp = &sqladt;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqltdsp = &sqltds;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.stmt = "select STATUS into :b0:b1  from MT_DAILY_QUOT where ((EXCH_\
CODE=:b2 and INSTR_CODE=:b3) and QUOT_DATE=:b4)";
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.iters = (unsigned int  )1;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.offset = (unsigned int  )36;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.selerr = (unsigned short)1;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.cud = sqlcud0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqlety = (unsigned short)4352;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)chr_p_pcstatus;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[0] = (unsigned long )3;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[0] = (         short *)&l_Status;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[1] = (unsigned char  *)p_exch_code;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[1] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[1] = (         short *)0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[1] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[2] = (unsigned char  *)p_instr_code;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[2] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[2] = (         short *)0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[2] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstv[3] = (unsigned char  *)p_quot_date;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhstl[3] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqhsts[3] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqindv[3] = (         short *)0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqinds[3] = (         int  )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqharm[3] = (unsigned long )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqadto[3] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqtdso[3] = (unsigned short )0;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 86 "CoChk_DlyQtions.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 86 "CoChk_DlyQtions.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 86 "CoChk_DlyQtions.pc"
}

#line 90 "CoChk_DlyQtions.pc"

                IS_ANY_ORA_ERROR
  chr_p_pcstatus[2] = '\0' ;
  if (p_exist =='Y')
        {
        if (int_exist == 0)
           {
                        if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_NOTFND,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
           }
        }
   if (p_exist =='N')
        {
        if (int_exist != 0)
           {
                if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_EXISTS,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
           }
        }

  if (int_error_flag == APL_FAILURE)
        {
        APL_GOBACK_FAIL
        }
   if (p_auth =='N')
        {
        if (!strcmp(chr_p_pcstatus,STATUS_AUTH))
           {
                        if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_AUTHORIZED,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
           }
       }

    if (p_auth =='Y')
        {
        if (strcmp(chr_p_pcstatus,STATUS_AUTH))
           {
                        if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_NOT_AUTHORIZED,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
           }
        }
    if (p_del =='N')
        {
        if (!strcmp(chr_p_pcstatus,STATUS_DEL_UAUTH))
              {
                        if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_MARKED_DEL,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
              }
        }
if (p_del =='Y')
        {
        if (strcmp(chr_p_pcstatus,STATUS_DEL_UAUTH))
           {
                        if(CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DAILYQUOTATION_NOTMARKED_DEL,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        int_error_flag = APL_FAILURE;
           }
        }
if (int_error_flag == APL_FAILURE)
        {
        APL_GOBACK_FAIL
        }
   else APL_GOBACK_SUCCESS
 RETURN_SUCCESS :
        {
    APL_IF_DEBUG
         {
  CO_ProcMonitor(APL_OUT_FILE, "Success in MTValDlyQtionsFn Getting out\n",NULL,NULL);
         }
        return(APL_SUCCESS);
       }
RETURN_FAILURE :
        {
     APL_IF_DEBUG
          {
  CO_ProcMonitor(APL_OUT_FILE, "Failed in MTValDlyQtionsFn Going out\n",NULL,NULL);
          }
  return(APL_FAILURE);
        }
}

