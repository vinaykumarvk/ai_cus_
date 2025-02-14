
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "CR_RstOrd.pc"
};


static unsigned int sqlctx = 311611;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
5,0,0,1,215,0,4,166,0,0,9,2,0,1,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,
0,0,2,4,0,0,1,5,0,0,1,5,0,0,
56,0,0,2,170,0,4,196,0,0,6,2,0,1,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,1,5,0,0,1,5,
0,0,
95,0,0,3,83,0,4,370,0,0,3,2,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,
122,0,0,4,134,0,3,391,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
153,0,0,5,104,0,2,406,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
184,0,0,6,86,0,4,434,0,0,3,2,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,
211,0,0,7,143,0,5,446,0,0,7,7,0,1,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,
};


#line 1 "CR_RstOrd.pc"








#include "CO_HostStructdef.h"
/* EXEC SQL INCLUDE SQLCA.H;
 */ 
#line 1 "/oracle/app/product/11.1.0.7client/precomp/public/SQLCA.H"
/*
 * $Header:   //psliapps/cvltarch/ctmain/INTLCUST/INTLCUST/SOURCE/BE/CR_RstOrd.c-arc   1.0.1.0   09 Aug 2012 14:25:44   IN065615  $ sqlca.h 
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

#line 11 "CR_RstOrd.pc"

int CR_Proc_OrdExecRst(	char *chr_p_client,
							char *p_dealident,
							char *p_deal_access_stamp,
							char *p_ord_access_stamp,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	struct sqlca sqlca;
	DL_DEAL_OTH_STRUCT_H	*l_dl_deal_oth_struct_hb		=	NULL;
	DL_DEALAUDIT_STRUCT_H *l_dl_dealaudit_struct_hb			=	NULL;
	INTL_ENV_DATA_STRUCT_H	*l_intl_env_data_h				=	NULL;
	char		chr_l_buf[BUFFER_LEN]							=	APL_NULL_STRING;
	char		chr_l_h_trd_access_stamp[APL_DATE_LEN]	=	APL_NULL_STRING;
	char		chr_l_h_trd_inputdt[APL_DATE_LEN]			=	APL_NULL_STRING;
	char		chr_l_h_trd_origrefno[APL_TXNREFNO_LEN]	=	APL_NULL_STRING;
	char		chr_l_h_trd_confdt[APL_DATE_LEN]			=	APL_NULL_STRING;
	char		chr_l_h_ord_rowid[APL_ROWID_LEN]			=	APL_NULL_STRING;
	char		chr_l_h_ord_access_stamp[APL_DATE_LEN]	=	APL_NULL_STRING;
	char		chr_l_h_ord_buysellflg[APL_FLAG_LENGTH]		=	APL_NULL_STRING;
	char		chr_l_access_stamp[APL_DATE_LEN]			=	APL_NULL_STRING;
	char		chr_l_ord_status[RECORD_STAT_LEN]		=	APL_NULL_STRING;
	char		chr_l_lastexecdt[APL_DATE_LEN]				=	APL_NULL_STRING;
	char		int_l_exist_a										=	APL_NULL_CHAR;
	char		chr_l_auth										=	APL_NULL_CHAR;
	char		chr_l_del											=	APL_NULL_CHAR;
	char		chr_l_cancel										=	APL_NULL_CHAR;
	char		chr_l_exec										=	APL_NULL_CHAR;
	char		chr_l_exectyp									=	APL_NULL_CHAR;
	char		chr_l_expire										=	APL_NULL_CHAR;
	double	l_h_trd_quantity									=	0;
	
	double	l_h_trd_orig_qty							=	0;
	double	l_h_trd_cost								=	0;
	double	l_h_ord_execquantity							=	0;
	double	dbl_l_brkgcomm									=	0;
	double	l_old_quantity									=	0;
	double	l_old_limitcost							=	0;
	double	l_limitcost								=	0;
	short		l_i_trd_qty									=	0;
	
	short		l_i_trd_origqty							=	0;
	short		l_i_trd_inputdt							=	0; 
	short		l_i_trd_access_stamp						=	0;
	short		l_i_trd_origrefno							= 	0;
	short		l_i_trd_confdt								=	0;
	short		l_i_trd_price								=	0;
	short		l_i_ord_execqty							=	0;
	short		l_i_ord_rowid								=	0;
	short		l_i_ord_buysellflg						=	0;
	short		l_i_ord_access_stamp						=	0;
	short		int_l_condexists_A								=	0;
	short		int_l_error_flg									=	APL_SUCCESS;

	#ifdef APL_THREADS
		APL_SET_CONTEXT;
		EXEC SQL CONTEXT USE :my_ctx_local;
	#endif

	

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE,
						"Entering processtion CR_Proc_OrdExecRst\n",
						NULL,
						p_intl_envdatastruct_h );
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(	chr_l_buf,
					"The client is : %s\n",
					chr_p_client );
		CO_ProcMonitor( 	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(	chr_l_buf,
					"The trade refno is : %s\n",
					p_dealident );
		CO_ProcMonitor( 	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(	chr_l_buf,
					"The Access Stamp of Trade Record is : %s\n",
					p_deal_access_stamp );
		CO_ProcMonitor( 	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(	chr_l_buf,
					"The Access Stamp of Order Record is : %s\n",
					p_ord_access_stamp );
		CO_ProcMonitor( 	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
	}

	

	/* EXEC SQL VAR	chr_l_h_trd_access_stamp IS STRING; */ 
#line 114 "CR_RstOrd.pc"

	/* EXEC SQL VAR	chr_l_h_trd_inputdt 		IS STRING; */ 
#line 115 "CR_RstOrd.pc"

	/* EXEC SQL VAR	chr_l_h_trd_origrefno 	IS STRING; */ 
#line 116 "CR_RstOrd.pc"

	/* EXEC SQL VAR	chr_l_h_trd_confdt			IS STRING; */ 
#line 117 "CR_RstOrd.pc"

	/* EXEC SQL VAR	chr_l_h_ord_rowid 			IS STRING; */ 
#line 118 "CR_RstOrd.pc"

	/* EXEC SQL VAR 	chr_l_h_ord_access_stamp	IS STRING; */ 
#line 119 "CR_RstOrd.pc"

	/* EXEC SQL VAR 	chr_l_h_ord_buysellflg	IS STRING; */ 
#line 120 "CR_RstOrd.pc"


	sqlca.sqlcode = 0;

	

	if ( !strlen(chr_p_client) )
	{
		APL_DATA_MISSING(	"Account",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( !strlen(p_dealident) )
	{
		APL_DATA_MISSING(	"Ref. Number",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( !strlen(p_deal_access_stamp) )
	{
		APL_DATA_MISSING(	"Access Stamp Of Trd",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( !strlen(p_ord_access_stamp) )
	{
		APL_DATA_MISSING(	"Access Stamp of Ord",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	
	

	/* EXEC SQL SELECT 	QTY,
							DATEOF_INPUT,
							ACCESS_STAMP,
							ORIG_REFNO,
							VAL_FDT,
							COST,
							ORIG_QTY
				INTO		:l_h_trd_quantity:l_i_trd_qty,
							:chr_l_h_trd_inputdt:l_i_trd_inputdt,
							:chr_l_h_trd_access_stamp:l_i_trd_access_stamp,
							:chr_l_h_trd_origrefno:l_i_trd_origrefno,
							:chr_l_h_trd_confdt:l_i_trd_confdt,
							:l_h_trd_cost:l_i_trd_price,
							:l_h_trd_orig_qty:l_i_trd_origqty
				FROM		DL_DEAL
				WHERE		CLIENT	=	:chr_p_client
				AND		IDENTIY_NO		=	:p_dealident	
				FOR		UPDATE OF ACCESS_STAMP; */ 
#line 183 "CR_RstOrd.pc"

{
#line 166 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 166 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 166 "CR_RstOrd.pc"
 sqlstm.stmt = "select QTY ,DATEOF_INPUT ,ACCESS_STAMP ,ORIG_REFNO ,VAL_FDT \
,COST ,ORIG_QTY into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b13  fro\
m DL_DEAL where (CLIENT=:b14 and IDENTIY_NO=:b15) for update of ACCESS_STAMP ";
#line 166 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 166 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )5;
#line 166 "CR_RstOrd.pc"
 sqlstm.selerr = (unsigned short)1;
#line 166 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 166 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)&l_h_trd_quantity;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)&l_i_trd_qty;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)chr_l_h_trd_inputdt;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )20;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)&l_i_trd_inputdt;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)chr_l_h_trd_access_stamp;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)&l_i_trd_access_stamp;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)chr_l_h_trd_origrefno;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[3] = (unsigned long )17;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[3] = (         short *)&l_i_trd_origrefno;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)chr_l_h_trd_confdt;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[4] = (         short *)&l_i_trd_confdt;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&l_h_trd_cost;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[5] = (         short *)&l_i_trd_price;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)&l_h_trd_orig_qty;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[6] = (         short *)&l_i_trd_origqty;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)chr_p_client;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[7] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[7] = (         short *)0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_dealident;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhstl[8] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqindv[8] = (         short *)0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 166 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 166 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 166 "CR_RstOrd.pc"
}

#line 183 "CR_RstOrd.pc"


	IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(	ERR_DEAL_NF,
														chr_p_client,
														p_dealident,
														APL_NULL_STRING );

	if ( l_i_trd_price == -1 )
	{
		l_h_trd_cost = 0;
	}

	
	/* EXEC SQL SELECT 	ROWID,
							EXEC_QTY,
							ACCESS_STAMP,
							BUY_SELL_IND
				INTO		:chr_l_h_ord_rowid:l_i_ord_rowid,
							:l_h_ord_execquantity:l_i_ord_execqty,
							:chr_l_h_ord_access_stamp:l_i_ord_access_stamp,
							:chr_l_h_ord_buysellflg:l_i_ord_buysellflg
				FROM		OR_ORDERDETAILS
				WHERE		CLIENT	=	:chr_p_client
				AND		ORD_REFNO	=	:chr_l_h_trd_origrefno
				FOR		UPDATE OF ACCESS_STAMP; */ 
#line 207 "CR_RstOrd.pc"

{
#line 196 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 196 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 196 "CR_RstOrd.pc"
 sqlstm.stmt = "select ROWID ,EXEC_QTY ,ACCESS_STAMP ,BUY_SELL_IND into :b0:\
b1,:b2:b3,:b4:b5,:b6:b7  from OR_ORDERDETAILS where (CLIENT=:b8 and ORD_REFNO=\
:b9) for update of ACCESS_STAMP ";
#line 196 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 196 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )56;
#line 196 "CR_RstOrd.pc"
 sqlstm.selerr = (unsigned short)1;
#line 196 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 196 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)chr_l_h_ord_rowid;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )19;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)&l_i_ord_rowid;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&l_h_ord_execquantity;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)&l_i_ord_execqty;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)chr_l_h_ord_access_stamp;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)&l_i_ord_access_stamp;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)chr_l_h_ord_buysellflg;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[3] = (unsigned long )2;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[3] = (         short *)&l_i_ord_buysellflg;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)chr_p_client;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[4] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[4] = (         short *)0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)chr_l_h_trd_origrefno;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhstl[5] = (unsigned long )17;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqindv[5] = (         short *)0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 196 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 196 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 196 "CR_RstOrd.pc"
}

#line 207 "CR_RstOrd.pc"


	IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(	ERR_ORD_NOTFND,
														chr_p_client,
														chr_l_h_trd_origrefno,
														APL_NULL_STRING );

	if ( l_i_ord_execqty == -1 )
	{
		l_h_ord_execquantity = 0;
	}

	

	if ( strcmp( chr_l_h_trd_access_stamp, p_deal_access_stamp ) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_ACCESSSTAMP_CHGD,
														"Trade",
														chr_p_client,
														p_dealident,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( strcmp( chr_l_h_ord_access_stamp, p_ord_access_stamp ) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_ACCESSSTAMP_CHGD,
														"Order",
														chr_p_client,
														chr_l_h_trd_origrefno,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	

	if ( strlen(chr_l_h_trd_confdt) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DEAL_CONF,
														chr_p_client,
														p_dealident,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}
	
	

	if( l_h_trd_quantity != l_h_trd_orig_qty )
	{
		if (APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
													  ERR_DEAL_PARTCONF,
													  chr_p_client,
													  p_dealident,
													  APL_NULL_STRING,
													  __LINE__,
													  __FILE__))
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg	= APL_FAILURE;
	}

	

	int_l_exist_a 		= 	'Y';
	chr_l_auth  		= 	NULL;
	chr_l_del			=	'N';
	chr_l_cancel		=	NULL;
	chr_l_exec		=	'Y';
	chr_l_exectyp	=	NULL;
	chr_l_expire		=	NULL;

	if ( APL_FAILURE == CR_Chk_Ord(	chr_p_client,
											   chr_l_h_trd_origrefno,
												int_l_exist_a,
												chr_l_auth,
												chr_l_del,
												chr_l_cancel,
												chr_l_exec,
												chr_l_exectyp,
												chr_l_expire,
												l_debug_info_ptr ) )
	{
		int_l_error_flg = APL_FAILURE;
	}

	if ( l_h_trd_quantity > l_h_ord_execquantity )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY, 
														"Trd QTY > Exec QTY",
														chr_p_client,
														chr_l_h_trd_origrefno,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL;
	}

	

	  

	l_dl_deal_oth_struct_hb = (DL_DEAL_OTH_STRUCT_H*)calloc(1,sizeof(DL_DEAL_OTH_STRUCT_H));
	APL_MALLOC_FAIL(l_dl_deal_oth_struct_hb);

	l_intl_env_data_h = (INTL_ENV_DATA_STRUCT_H*)calloc(1,sizeof(INTL_ENV_DATA_STRUCT_H) );
	APL_MALLOC_FAIL(l_intl_env_data_h);

	

	strcpy(l_intl_env_data_h->usr, p_intl_envdatastruct_h->usr);
	strcpy(l_intl_env_data_h->h_mode, APL_FUNC_DELETE );
	strcpy(l_intl_env_data_h->processtion, p_intl_envdatastruct_h->processtion );
	strcpy(l_intl_env_data_h->auth_req, p_intl_envdatastruct_h->auth_req );
	strcpy(l_intl_env_data_h->subprocess, ORDEXECRESET );
	strcpy(l_intl_env_data_h->h_process, APL_NULL_STRING );	

	strcpy( l_dl_deal_oth_struct_hb->h_dl_client, chr_p_client );
	strcpy( l_dl_deal_oth_struct_hb->h_indentity_no,	 p_dealident );
	strcpy( l_dl_deal_oth_struct_hb->h_locindentity_no,	APL_NULL_STRING ); 
	strcpy( l_dl_deal_oth_struct_hb->h_brkrno, 	APL_NULL_STRING );
	l_dl_deal_oth_struct_hb->h_clt_reqdel_flag[0] = 'N';
	l_dl_deal_oth_struct_hb->h_clt_reqdel_flag[1] = '\0';
	strcpy( l_dl_deal_oth_struct_hb->h_access_stamp, p_deal_access_stamp );

	if ( APL_FAILURE == DL_Proc_TrdOth( 	l_dl_deal_oth_struct_hb,
												  	l_intl_env_data_h,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	

	/* EXEC SQL SELECT 	ACCESS_STAMP 
				INTO	 	:chr_l_h_trd_access_stamp:l_i_trd_access_stamp
				FROM		DL_DEAL
				WHERE		CLIENT	=	:chr_p_client
				AND		IDENTIY_NO		=	:p_dealident; */ 
#line 374 "CR_RstOrd.pc"

{
#line 370 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 370 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 370 "CR_RstOrd.pc"
 sqlstm.stmt = "select ACCESS_STAMP into :b0:b1  from DL_DEAL where (CLIENT=\
:b2 and IDENTIY_NO=:b3)";
#line 370 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 370 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )95;
#line 370 "CR_RstOrd.pc"
 sqlstm.selerr = (unsigned short)1;
#line 370 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 370 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)chr_l_h_trd_access_stamp;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )20;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)&l_i_trd_access_stamp;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)chr_p_client;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_dealident;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 370 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 370 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 370 "CR_RstOrd.pc"
}

#line 374 "CR_RstOrd.pc"


	IS_ANY_ORA_ERROR;

	strcpy( l_intl_env_data_h->h_mode, APL_FUNC_AUTHORISE );
	strcpy( l_intl_env_data_h->usr, APL_USER_SYSTEM );
	strcpy( l_dl_deal_oth_struct_hb->h_access_stamp, chr_l_h_trd_access_stamp );

	if ( APL_FAILURE == DL_Proc_TrdOth( 	l_dl_deal_oth_struct_hb,
												  	l_intl_env_data_h,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	

	/* EXEC SQL INSERT INTO OR_HISEXECORDER
				SELECT 	* 
				FROM		OR_EXECORDER 
				WHERE		CLIENT		= :chr_p_client
				AND		IDENTIY_NO			= :p_dealident
				AND		ORD_REFNO	= :chr_l_h_trd_origrefno
				AND		EXEC_DATE		= :chr_l_h_trd_inputdt; */ 
#line 397 "CR_RstOrd.pc"

{
#line 391 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 391 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 391 "CR_RstOrd.pc"
 sqlstm.stmt = "insert into OR_HISEXECORDER  select *  from OR_EXECORDER whe\
re (((CLIENT=:b0 and IDENTIY_NO=:b1) and ORD_REFNO=:b2) and EXEC_DATE=:b3)";
#line 391 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 391 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )122;
#line 391 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 391 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)chr_p_client;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_dealident;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)chr_l_h_trd_origrefno;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )17;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)chr_l_h_trd_inputdt;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqindv[3] = (         short *)0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 391 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 391 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 391 "CR_RstOrd.pc"
}

#line 397 "CR_RstOrd.pc"


	IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(	ERR_ORD_NOTFND,
														"Ord Exec. Recs",
														chr_p_client,
														chr_l_h_trd_origrefno );

	

	/* EXEC SQL DELETE OR_EXECORDER 
				WHERE		CLIENT		=	:chr_p_client
				AND		IDENTIY_NO			=	:p_dealident 
				AND		ORD_REFNO	=	:chr_l_h_trd_origrefno
				AND		EXEC_DATE		=	:chr_l_h_trd_inputdt; */ 
#line 410 "CR_RstOrd.pc"

{
#line 406 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 406 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 406 "CR_RstOrd.pc"
 sqlstm.stmt = "delete  from OR_EXECORDER  where (((CLIENT=:b0 and IDENTIY_N\
O=:b1) and ORD_REFNO=:b2) and EXEC_DATE=:b3)";
#line 406 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 406 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )153;
#line 406 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 406 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)chr_p_client;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_dealident;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)chr_l_h_trd_origrefno;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )17;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)chr_l_h_trd_inputdt;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqindv[3] = (         short *)0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 406 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 406 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 406 "CR_RstOrd.pc"
}

#line 410 "CR_RstOrd.pc"


	IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(	ERR_ORD_NOTFND,
														"Ord Exec. Recs",
														chr_p_client,
														chr_l_h_trd_origrefno );
	 
	

	if ( APL_FAILURE == CO_RtvSysDtTime( chr_l_access_stamp,
															l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( l_h_ord_execquantity == l_h_trd_quantity )
	{
		strcpy( chr_l_ord_status, STATUS_AUTH );
		strcpy( chr_l_lastexecdt, APL_NULL_STRING );
	}
	else
	{
		strcpy( chr_l_ord_status, STATUS_PART_EXEC );

		/* EXEC SQL SELECT 	MAX(EXEC_DATE) 
					INTO		:chr_l_lastexecdt
					FROM 		OR_EXECORDER
					WHERE		CLIENT		=	:chr_p_client
					AND		ORD_REFNO	=	:chr_l_h_trd_origrefno; */ 
#line 438 "CR_RstOrd.pc"

{
#line 434 "CR_RstOrd.pc"
  struct sqlexd sqlstm;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqlvsn = 12;
#line 434 "CR_RstOrd.pc"
  sqlstm.arrsiz = 9;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqladtp = &sqladt;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqltdsp = &sqltds;
#line 434 "CR_RstOrd.pc"
  sqlstm.stmt = "select max(EXEC_DATE) into :b0  from OR_EXECORDER where (CL\
IENT=:b1 and ORD_REFNO=:b2)";
#line 434 "CR_RstOrd.pc"
  sqlstm.iters = (unsigned int  )1;
#line 434 "CR_RstOrd.pc"
  sqlstm.offset = (unsigned int  )184;
#line 434 "CR_RstOrd.pc"
  sqlstm.selerr = (unsigned short)1;
#line 434 "CR_RstOrd.pc"
  sqlstm.cud = sqlcud0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqlety = (unsigned short)4352;
#line 434 "CR_RstOrd.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)chr_l_lastexecdt;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstl[0] = (unsigned long )20;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqindv[0] = (         short *)0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstv[1] = (unsigned char  *)chr_p_client;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstl[1] = (unsigned long )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqindv[1] = (         short *)0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqharm[1] = (unsigned long )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstv[2] = (unsigned char  *)chr_l_h_trd_origrefno;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhstl[2] = (unsigned long )17;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqindv[2] = (         short *)0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqharm[2] = (unsigned long )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 434 "CR_RstOrd.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 434 "CR_RstOrd.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 434 "CR_RstOrd.pc"
}

#line 438 "CR_RstOrd.pc"


		IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(	ERR_REC_NOTFND,
															"Ord. Exec. Dtls",
															chr_p_client,
															chr_l_h_trd_origrefno );
	}

	/* EXEC SQL UPDATE OR_ORDERDETAILS 
				SET	EXEC_QTY			=  EXEC_QTY - :l_h_trd_quantity,
						ACCESS_STAMP	=	:chr_l_access_stamp,
						CHECKER			=	:p_intl_envdatastruct_h->usr,
						CHECKER_DT		=	:chr_l_access_stamp,
						ORD_STAT	=	:chr_l_ord_status,
						LAST_EXEC_DATE		=	:chr_l_lastexecdt
				WHERE	ROWID				=	:chr_l_h_ord_rowid; */ 
#line 453 "CR_RstOrd.pc"

{
#line 446 "CR_RstOrd.pc"
 struct sqlexd sqlstm;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqlvsn = 12;
#line 446 "CR_RstOrd.pc"
 sqlstm.arrsiz = 9;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqladtp = &sqladt;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqltdsp = &sqltds;
#line 446 "CR_RstOrd.pc"
 sqlstm.stmt = "update OR_ORDERDETAILS  set EXEC_QTY=(EXEC_QTY-:b0),ACCESS_S\
TAMP=:b1,CHECKER=:b2,CHECKER_DT=:b1,ORD_STAT=:b4,LAST_EXEC_DATE=:b5 where ROWI\
D=:b6";
#line 446 "CR_RstOrd.pc"
 sqlstm.iters = (unsigned int  )1;
#line 446 "CR_RstOrd.pc"
 sqlstm.offset = (unsigned int  )211;
#line 446 "CR_RstOrd.pc"
 sqlstm.cud = sqlcud0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 446 "CR_RstOrd.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)&l_h_trd_quantity;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)chr_l_access_stamp;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[1] = (unsigned long )20;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)(p_intl_envdatastruct_h->usr);
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[2] = (unsigned long )15;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[2] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)chr_l_access_stamp;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[3] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)chr_l_ord_status;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[4] = (unsigned long )3;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[4] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)chr_l_lastexecdt;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[5] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)chr_l_h_ord_rowid;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhstl[6] = (unsigned long )19;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqindv[6] = (         short *)0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 446 "CR_RstOrd.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 446 "CR_RstOrd.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 446 "CR_RstOrd.pc"
}

#line 453 "CR_RstOrd.pc"


	

	l_dl_dealaudit_struct_hb = (DL_DEALAUDIT_STRUCT_H*)calloc(1,sizeof(DL_DEALAUDIT_STRUCT_H));
	APL_MALLOC_FAIL(l_dl_dealaudit_struct_hb);

	strcpy(l_dl_dealaudit_struct_hb->h_dl_client, chr_p_client);
	strcpy(l_dl_dealaudit_struct_hb->h_indentity_no,   chr_l_h_trd_origrefno);
	l_dl_dealaudit_struct_hb->h_trail_for[0] = ORD_TRAIL_FOR;
	l_dl_dealaudit_struct_hb->h_trail_for[1] = '\0';
	strcpy(l_dl_dealaudit_struct_hb->h_processdetail, p_intl_envdatastruct_h->processtion);
	strcpy(l_dl_dealaudit_struct_hb->h_proc_usr, p_intl_envdatastruct_h->usr);
	strcpy(l_dl_dealaudit_struct_hb->h_subprocess, APL_NULL_STRING);
	strcpy(l_dl_dealaudit_struct_hb->h_logdate, APL_NULL_STRING);
	strcpy(l_dl_dealaudit_struct_hb->h_fail_cd, APL_NULL_STRING);
	l_dl_dealaudit_struct_hb->h_qty = l_h_trd_quantity;
	l_dl_dealaudit_struct_hb->h_dlfromord[0] = 'N';
	l_dl_dealaudit_struct_hb->h_dlfromord[1] = '\0';

	if ( APL_FAILURE == CR_Mod_CLHAudTrail( l_dl_dealaudit_struct_hb,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	} 	

	

	if ( APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_MAINT",
														"UPDATE_ACCBAL",
														&int_l_condexists_A,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( int_l_condexists_A > 0 && ( chr_l_h_ord_buysellflg[0] == SELL_IND ) )
	{
		l_limitcost = l_h_trd_cost * 100;
		dbl_l_brkgcomm	= 0;
		l_old_quantity	=	0;
		l_old_limitcost = 0;

		if ( APL_FAILURE == CR_Mod_CustCashBal(	chr_p_client,
														&l_h_trd_quantity,
														&l_old_quantity,
														&l_limitcost,
														&l_old_limitcost,
														'S',
														&dbl_l_brkgcomm,
														l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}	
	}

	  APL_GOBACK_SUCCESS //AIX Warning Removal
	RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE,
							"Leaving processtion CR_Proc_OrdExecRst with success\n",
							l_debug_info_ptr,
							p_intl_envdatastruct_h );
		}
		APL_FREE(l_dl_deal_oth_struct_hb);
		APL_FREE(l_dl_dealaudit_struct_hb);
		APL_FREE(l_intl_env_data_h);
		return(APL_SUCCESS);

	RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE,
							"Leaving processtion CR_Proc_OrdExecRst with failure\n",
							l_debug_info_ptr,
							p_intl_envdatastruct_h );
		}
		APL_FREE(l_dl_deal_oth_struct_hb);
		APL_FREE(l_dl_dealaudit_struct_hb);
		APL_FREE(l_intl_env_data_h);
		return(APL_FAILURE);
}
