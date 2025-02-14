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
 * Module Name         :	Maintenance
 *
 * File Name           :	Intellect_Interface.h
 *
 * Description         :	This file contains definitions for Macros Common	
 *									for the System.
 *           
 *
 *            Version Control Block
 *
 * Date        Version    Author        Description	       RFS No.
 * ---------   --------	 -------------  ---------------------  --------
 * 10/10/2005	1.0      Smita Bhat     New File	       HDFCMT_003
 * 28/02/2006	1.9      Kouser Begum	Added New Column for Intellect
 *                                      Reports                INT_REP_001
 * -------------------------------------------------------------------------
 * 09-Jun-2010 1.0.1.4   Naren V        NSDL DP Ins File Format ISKB_3298
 *                                      Changes - Variable  Len
 *                                      changes were incorporat
 *                                      ed accordingly based on
 *                                      NSDL depository revised
 *                                      file formats.
 * 18/10/2011            Sana Bhatkar   New Core Banking    Retro done for AIX mig for ISKB_4802
 *		                        Account No Size 
 *				        Change		
 ***************************************************************************/
   

#ifndef PORT_SUN
	#define PORT_SUN
	char *ltoa(long);
#endif

#ifndef COMMON_INTERFACEHEADER_INCLUDED
#define COMMON_INTERFACEHEADER_INCLUDED
#ifndef IDL_DOUBLERR_USED
#define IDL_DOUBLERR_USED
#endif
#ifndef IDLBASE_H
#endif
#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#endif
#define CODE_LENGTH (7)
#define KEY_LENGTH (20)
#define MSG_LENGTH (80)
#define PATH_LENGTH (250)
#define APL_DEBUG_YES (1)
#define APL_DEBUG_NO (0)
#define OK (2)
#define NOT_OK (3)
#define ERROR (4)
#define WARNING (5)
#define APL_MAX_ERRORS (15)
#define APL_USERID_LEN (100) //AIX -change
#define APL_FUNC_LEN (4)
#define APL_FUNC_NAME_LENGTH (61)
#define APL_FLAG_LENGTH (2)
#define APL_INSTRUMENTCODE_LEN (9)

/* For Billing Services HDFCIV_003 Vinay kalaskar */
#define APL_CLIENT_LENGTH (11)
/* Retro done for AIX migration */
/*#define APL_CLIENT_LENGTH_GL (24)*/
#define APL_CLIENT_LENGTH_GL (29)  /*Changed by Shweta --05072011 --Kotak Ench --ISKB_4802 --To change Account Number Size*/

#define APL_IBANACC_LEN (31)
#define APL_NOTE_LEN (261)
#define APL_TXNREFNO_LEN (17)
#define APL_UNIQUE_REF_NUM_LEN (17)
#define APL_LOCNCODE_LENGTH (5)
#define APL_CCYCODE_LEN (4)
#define APL_CTRY_CODE_LEN (3)
#define APL_STATUS_LEN (3)
#define APL_INSTRU_TYPE_LEN (4)
#define APL_DATE_LEN (20)
#define APL_SUB_FUN_LEN (4)
#define APL_UUID_LEN (37)
#define APL_PRODTYPE_LEN (3)
#define APL_REPNAME_LENGTH (16)
#define APL_CLNREPNAME_LENGTH (31)/*Sonali, Reports*/
#define APL_REPDESC_LENGTH (31)
#define APL_CLNREPDESC_LENGTH (31)/*Sonali,Reports*/
#define APL_BATCH_KEY_LEN (41)
#define APL_BATCH_PROGNAME_LEN (41)
#define APL_LOGFILE_DESC "LOG FILE"
#define APL_HOFF_FILE_DESC "HANDOFF"
#define APL_PAGE_SIZE (80)
#define APL_SRN_LEN (21)
#define	APL_ISIN_LEN	(13)
#define	APL_GFCID_LEN		(13)
#define	APL_BIC_CODE_LEN	(13)
/*Smita - HDFCMT_003*/
#define APL_SQLSTMT_LEN (100)
#define APL_SQLSTMT_APPEND_LEN (100)
#define APL_FIELD_VAL (100)
/*Smita - HDFCMT_003*/

/* #define APL_DP_BATCH_NO_LEN (9) ** ISKB_2447 **  ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
#define APL_DP_BATCH_NO_LEN   (10)

/**Biju - Added Macros for Entering/Exit and File Close -- Begin**/
#define APL_LINE_LEN 100
/*AIX Warnings Removal*/
#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 1
#define INTL_IF_DEBUG if(DEBUG)
/** Macro for printing entered function for debug purpose **/
#define APL_FUNCTION_ENTER(fp) \
		 {\
			 	char l_line[APL_LINE_LEN];\
			 	sprintf(l_line,"Entered Function\t\t|%s|",__func__);\
			 	INTL_IF_DEBUG\
			 		CO_ProcMonitor(fp,l_line,NULL,NULL);\
		 }

/** Macro for printing return function with successfor debug purpose **/
#define APL_FUNCTION_RET_SUCCESS(fp) \
		 {\
			 	char l_line[APL_LINE_LEN];\
			 	sprintf(l_line,"Success From Function\t\t|%s|",__func__);\
			 	INTL_IF_DEBUG\
			 		CO_ProcMonitor(fp,l_line,NULL,NULL);\
			 	return APL_SUCCESS;\
		 }


/** Macro for printing return function with failure for debug purpose **/	
#define APL_FUNCTION_RET_FAILURE(fp) \
		 {\
			 	char l_line[APL_LINE_LEN];\
			 	sprintf(l_line,"Failure From Function\t\t|%s|",__func__);\
			 	INTL_IF_DEBUG\
			 		CO_ProcMonitor(fp,l_line,NULL,NULL);\
			 	return APL_FAILURE;\
		 }

/** Macro for Closing file **/
#define APL_CLOSE_FILE(fp) \
		 	if(fp != (FILE *)NULL && fp != APL_OUT_FILE)fclose(fp);

/** Printing Alerts **/
#ifdef PC_COMPILE 
		 void Alert(char *dummy,...)
		 {
			 /** Dummy Function Definition -- Biju **/
		 }
#else
#define Alert(...) \
		 {\
			 	char l_line[APL_LINE_LEN];\
			 	char l_line2[APL_LINE_LEN + 100];\
			 	sprintf(l_line,__VA_ARGS__);\
			 	sprintf(l_line2,"Alert : [%s] : Function [%s] Line [%d]\n",l_line,__func__,__LINE__);\
			 	INTL_IF_DEBUG\
			 		CO_ProcMonitor(APL_OUT_FILE,l_line2,NULL,NULL);\
		 }
#endif




/**Biju - Added Macros for Entering/Exit and File Close -- End**/

#define APL_COUNTACC_LEN (16)
typedef enum {h_typeof_rpt,
type_msg,
h_typeof_upldfile,
h_typeof_manmsg,
h_typeof_hf_file} FILE_TYPE;
typedef struct pipe_type {
void (* pull)(
#ifdef IDL_PROTOTYPES
char *buf,
int esize,
int *ecount
#endif
);
void (* push)(
#ifdef IDL_PROTOTYPES
char *buf,
int  ecount
#endif
);
void (* alloc)(
#ifdef IDL_PROTOTYPES
int bsize,
char **buf,
int *bcount
#endif
);
} pipe_type;
typedef struct error_struct {
int h_err_warn;
int h_code;
char h_key1[20];
char h_key2[20];
char h_key3[20];
char h_file[50];
int h_line;
int ok_ind;
int h_ctx_no;
int debug_ind;
char *msg;
struct error_struct *h_next;
} DEBUG_INFO_STRUCT_H;
typedef struct  {
char usr[15];
char h_mode[4];
char processtion[61];
char auth_req[2];
char subprocess[4];
char h_process[2];
} INTL_ENV_DATA_STRUCT_H;
typedef struct  {
char part_confirm[2];
char manifld_print_ind[2];
char proc_spot_dl_ind[2];
char gsetl_ind[2];
char sub_clt_proc[2];
char ord_proc_ind[2];
char no_stxdl_ind[2];
char loc_proc_ind[2];
char ae_ind[2];
char proc_pr_feed_ind[2];
char dir_indir_fxqt_ind[2];
char proc_reg_ind[2];
char part_reg_ind[2];
int amount_decimal_len;
int qty_dec_len;
int min_clt_len;
int allowed_amtdiff;
int auto_inactive_days;
int odd_lot_qty;
int proc_start_no;
int end_proc_no;
double custody_tax_rt;
double fx_tax_rt;
double comm_tax_rt;
double paidupcapital_limit;
char op_oth_stx_error[3];
char op_oth_trd_error[3];
int stx_rec_dl_days;
int stx_del_dl_days;
int oth_rec_dl_days;
int oth_del_dl_days;
int spot_dl_days;
int spot_oth_dl_days;
char custody_clt_cd[11];
char brokerage_cd[11];
char brnch_usd_clt[11];
char vtb_clt_code[11];
char vtb_clt_name[41];
char vtb_identity[41];
char vdp_ind[2];
double custody_comm_rt;
double stk_exg_comm_rt;
char ms_53x_online_eod_ind[2];
double brokerage;
double sttrate;
} MT_CORE_SYS_PARAMS_STRUCT_H;
typedef struct  {
char b_ccy[4];
char b_basis[4];
int late_dl_days_a;
int allowed_wrt_off_amt;
int db_txnrcd;
int cred_txnrcd;
int val_days;
int periodfor_arch;
int	pymt_gen_date;
char	status_pymt[2];
char latetime_a[6];
int late_dl_days_b;
char latetime_b[6];
int late_dl_days_c;
char latetime_c[6];
int late_dl_days_d;
char latetime_d[6];
int acc_digits;
} INVOICE_SYSTEMPARAM_STRUCT_H;
typedef struct  {
char snd_msg_to_allmast[2];
char msg569_prematch_ind[2];
int allowed_tlx_len;
int allowed_retension_prd;
char gen_fx_adv_ind[2];
char swift_cd[12];
char gcn_cd[6];
char auto_msg_rpr_ind[2];
char reg_follow_msg_ind[2];
int msg_follow_days1;
int msg_follow_days2;
char ms_vtb_msg_addr[12];
int response_days;
char ccs_int_ind[2];
char line_ind[4];
} MT_MESSAGE_SYS_PARAMS_STRUCT_H;
typedef struct  {
char ca_identname[41];
char ca_address[321];
char nation_code[3];
char brnch_cd[4];
char dom_ccy[4];
char dom_instrument[5];
char gl_interface_mod_ind[2];
char bill_module_ind[2];
char ca_module_ind[2];
char f_file_path[61];
char b_file_path[61];
int monthsfor_arch;
char ei_smi_ind[2];
char ccs_ind[2];
char office_for_booking[9];
char installed_at_bank[3];
char cust_code[4]; /* New Col Added related to Intellect Reports - Kouser - INT_REP_001 */
} MT_COMMON_SYS_PARAMS_STRUCT_H;
#ifdef __cplusplus
    }
#endif

#endif
