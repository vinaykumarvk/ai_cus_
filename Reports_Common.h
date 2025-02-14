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
 * Module Name         :		Maintenance
 *
 * File Name           :		Reports_Common.h
 *
 * Description         :		Contains Definitions related to Masters.
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author           Description			RFS No.
 * ---------   --------	 ---------------  ------------------	---------
 * 16/08/2006   1.0			vinay kalaskar		
 * 21/12/2011   1.1      Gouse         Program is modified
 *                                        to change the exist
 *                                        ing macro definitin
 *                                        by calling  the  db
 *                                        connect funtion wit
 *                                        h the database ind.
 * 01/04/2022   1.2       kotubabu       Linux Migratin        Kotak Implementation
 *********************************************************************/
   
#ifndef COMMON_HEADER_INCLUDED
#define COMMON_HEADER_INCLUDED
#include	"stdio_64.h"
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include "Intellect_Interface.h"
#include "Intellect_Common_A.h"

int G_SYS_ACCOUNT_LEN;

#define APL_LOGFILE_DESC "LOG FILE"

/*Commented by kotubabu for Linux Migration
#define OS_SUN */
#define OS_LINUX 


#define  APL_EMU_CCYCODE				"EUR"
#define  APL_GRD_CCYCODE				"GRD"
#define	APL_ORA_MSG_LENGTH			70
#define 	APL_NO_DATA_FILE				"NONE"

#define	APL_YES_IND						"Y"
#define	APL_NO_IND						"N"
#define	APL_YES_FLAG					'Y'	
#define	APL_NO_FLAG						'N'	
#define	APL_NOT_AN_ERROR				0

#define	APL_SUCCESS						1
#define	APL_FAILURE						0
#define	APL_RECS_EXIST					2

#define	APL_NULL_STRING		"\0"	/** Null string **/
#define	APL_NULL_CHAR		'\0'	/** Null Character **/
#define	APL_OUT_FILE		stdout	/** file pointer for screen **/
#define	APL_GOBACK_SUCCESS			goto RETURN_SUCCESS;
#define	APL_GOBACK_FAIL				goto RETURN_FAILURE;
#define	APL_USER_SYSTEM				"SYSTEM"
#define  APL_RESTARTDATA_LENGTH  	51

#define	APL_STS_AUTH					"AA"
#define	APL_STATUS_UNAUTH				"UU"
#define	APL_STATUS_SMIUNAUTH			"SU"
#define	APL_STATUS_SMIAUTH			"SA"
#define  APL_STATUS_CQ           	"CQ"
#define  APL_STATUS_CD           	"CD"
#define  APL_STATUS_MANUNAUTH    	"MU"


#define	ACTION_NEW_IND					"I"
#define	ACTION_MOD_IND					"M"
#define	ACTION_DEL_IND					"D"

#define APL_ONLINE_IND "O"	/** Online mode , refer pro_sys_date**/
#define APL_EOD_IND    "E"	/** EOD mode , refer pro_sys_date**/
#define APL_BOD_IND    "B"	/** BOD mode , refer pro_sys_date**/

#define DATA_FIELD_SEPRTR 				''
#define DATA_VALUE_SEPRTR 				''
#define ERR_FLD_SEP 						'|'
#define ERR_REC_SEP 						'#'

#define AUDIT_DATA_FIELD_SEPRTR ""
#define AUDIT_DATA_VALUE_SEPRTR ""

#define APL_BTCH_STATUS_LEN			16
#define APL_COMPLETED_STATUS			"completed"
#define APL_STARTED_STATUS				"started"

#define APL_REP_DESC "REPORT FILE"

char *strtok_r(char *s1, const char *s2, char **lasts);


/** Macro for freeing any pointer allocated by calloc or malloc **/
#define	APL_FREE(l_debug)\
			if (l_debug != NULL)\
			{\
				free(l_debug);\
				l_debug = NULL;\
			}


/** Checks whether the memory allocation failed by calloc or malloc , if failed record into debug list and retun failure**/

#define	APL_MALLOC_FAIL(pointer)\
			if (pointer == NULL)\
			{\
				CO_InsertErr(l_debug_info_ptr,\
									ERR_NO_MEMORY,\
									APL_NULL_STRING,\
									APL_NULL_STRING,\
									APL_NULL_STRING,\
									__LINE__,\
									__FILE__);\
				goto RETURN_FAILURE;\
			}
			
/***** Common function to be used for country condition checks *********/

short l_cond_exists;
#define IF_COND_EXISTS(main_fun, cond_fun) \
       if(CO_Chk_CntryEnabled( main_fun,\
                                                       cond_fun,\
                                                       &l_cond_exists,\
                                                       l_debug_info_ptr\
                                                       ) == APL_FAILURE)\
       {\
               CO_ProcMonitor(APL_OUT_FILE,"Failed in CO_Chk_CntryEnabled",NULL,NULL);\
               APL_GOBACK_FAIL\
       }\
       if(l_cond_exists == 1)
			
/***** Common function to be used for country condition checks HDFCIV_004 Rohit *********/
#define IF_COND_NOT_EXISTS(main_fun, cond_fun) \
       l_cond_exists = 0;\
       if(CO_Chk_CntryEnabled( main_fun,\
                                                       cond_fun,\
                                                       &l_cond_exists,\
                                                       l_debug_info_ptr\
                                                       ) == APL_FAILURE)\
       {\
               CO_ProcMonitor(APL_OUT_FILE,"Failed in CO_Chk_CntryEnabled",NULL,NULL);\
               APL_GOBACK_FAIL\
       }\
       if(l_cond_exists != 1)

/** Checks whether the memory allocation failed by calloc or malloc , if failed record into debug list and Mark The transaction as failed**/			
#define	APL_MALLOC_FAIL_LOC_A(pointer)\
			if (pointer == NULL)\
			{\
				CO_InsertErr(l_debug_info_ptr,\
									ERR_NO_MEMORY,\
									APL_NULL_STRING,\
									APL_NULL_STRING,\
									APL_NULL_STRING,\
									__LINE__,\
									__FILE__);\
				Proc_MarkFailProcess(h_ora_rowid, l_debug_info_ptr);\
				continue;\
			}



/** This macro can be used to insert new node in debug list to indicate one mandatory feid is missing **/
#define	APL_DATA_MISSING(h_key1,h_key2,h_key3)\
			CO_InsertErr(l_debug_info_ptr,\
								ERR_MAND_DATA_MISSING,\
								h_key1,\
								h_key2,\
								h_key3,\
								__LINE__,\
								__FILE__);
			
/** This macro can be used whether the sql query retuened any error ,after inserting new node to debug list it returns failure **/			
#define	IS_ANY_ORA_ERROR\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
				CO_InsertOraErr(l_debug_info_ptr,\
										sqlca.sqlerrm.sqlerrmc,\
										chr_buffer,\
										APL_NULL_STRING,\
										APL_NULL_STRING,\
										__LINE__,\
										__FILE__);\
				goto RETURN_FAILURE;\
			}


/** Macro inserts new node in debug list for sql error, then return failure, it also checks for no_data_found **/
#define	IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(error_code,h_key1,h_key2,h_key3)\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
				CO_InsertOraErr(l_debug_info_ptr,\
										sqlca.sqlerrm.sqlerrmc,\
										chr_buffer,\
										APL_NULL_STRING,\
										APL_NULL_STRING,\
										__LINE__,\
										__FILE__);\
				goto RETURN_FAILURE;\
			}\
			else\
			if (sqlca.sqlcode == 1403)\
			{\
				CO_InsertErr(l_debug_info_ptr,\
									error_code,\
									h_key1,\
									h_key2,\
									h_key3,\
									__LINE__,\
									__FILE__);\
				goto RETURN_FAILURE;\
			}



/** Macro inserts new node in debug list for sql error, then return failure, it also checks for duplicate data **/
#define	IS_ANY_ORA_ERROR_AND_DUPLICATE(error_code,h_key1,h_key2,h_key3)\
			if (sqlca.sqlcode == -1)\
			{\
				CO_InsertErr(l_debug_info_ptr,\
									error_code,\
									h_key1,\
									h_key2,\
									h_key3,\
									__LINE__,\
									__FILE__);\
				goto RETURN_FAILURE;\
			}\
			else\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
				CO_InsertOraErr(l_debug_info_ptr,\
										sqlca.sqlerrm.sqlerrmc,\
										chr_buffer,\
										APL_NULL_STRING,\
										APL_NULL_STRING,\
										__LINE__,\
										__FILE__);\
				goto RETURN_FAILURE;\
			}



/** Macro inserts new node in debug list for sql error, then return failure, it also checks for no_data_found **/

#define	IS_ANY_ORA_ERROR_CURSOR\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
				CO_InsertOraErr(l_debug_info_ptr,\
										sqlca.sqlerrm.sqlerrmc,\
										chr_buffer,\
										APL_NULL_STRING,\
										APL_NULL_STRING,\
										__LINE__,\
										__FILE__);\
				goto RETURN_FAILURE;\
			}\
			else\
			if (sqlca.sqlcode == 1403)\
			{\
				break;\
			}


/** it also checks for no_data_found **/
#define	APL_ZERO_RESULT_SET (sqlca.sqlcode==1403)



/** Macro inserts new node in debug list for sql error, then contnues, it also checks for duplicate data **/
#define	IS_ANY_ORA_ERROR_AND_DUPLICATE_CONTINUE(error_code,h_key1,h_key2,h_key3)\
			if (sqlca.sqlcode == -1)\
			{\
				CO_InsertErr(l_debug_info_ptr,\
									error_code,\
									h_key1,\
									h_key2,\
									h_key3,\
									__LINE__,\
									__FILE__);\
									continue;\
			}\
			else\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
				CO_InsertOraErr(l_debug_info_ptr,\
										sqlca.sqlerrm.sqlerrmc,\
										chr_buffer,\
										APL_NULL_STRING,\
										APL_NULL_STRING,\
										__LINE__,\
										__FILE__);\
										continue;\
			}




/** Macro checks in debug list for any fatal errors, if found returns failure **/
#define	IS_ANY_ERROR_FATAL\
			if (CO_ChkFatalErr(*l_debug_info_ptr) == APL_SUCCESS)\
				APL_GOBACK_FAIL



#define	APL_INSERT_ERROR_EOD_STARTED\
			CO_InsertErr(l_debug_info_ptr,\
								ERR_EOD_STARTED,\
								APL_NULL_STRING,\
								APL_NULL_STRING,\
								APL_NULL_STRING,\
								__LINE__,\
								__FILE__);

#define	APL_INSERT_ERROR_BOD_NOT_OVER\
			CO_InsertErr(l_debug_info_ptr,\
								E_BOD_NOT_OVER,\
								APL_NULL_STRING,\
								APL_NULL_STRING,\
								APL_NULL_STRING,\
								__LINE__,\
								__FILE__);

#define	APL_INSERT_ERROR_DATA_INTG(h_key1,h_key2,h_key3)\
			CO_InsertErr(l_debug_info_ptr,\
								ERR_DATA_INTEGRITY,\
								h_key1,\
								h_key2,\
								h_key3,\
								__LINE__,\
								__FILE__);


/** Macro checks whether the system is online at present **/
#define APL_IS_ONLINE ( (CO_Upd_AudLog_Chk_SysOnline(p_intlenv_data_struct_h,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,l_debug_info_ptr) == APL_SUCCESS) && (CO_ChkClientAuth(IDL_handle,l_debug_info_ptr) == APL_SUCCESS) )

/* Change variable name Rohit HDFC_GN */
#define NON_DCE_APL_IS_ONLINE ( (CO_Upd_AudLog_Chk_SysOnline(p_intlenv_data_struct_h,chr_l_audit_data,chr_l_data_key,chr_h_comments,l_debug_info_ptr) == APL_SUCCESS)  )

#define CHECK_EXISTANCE_OF_ERROR\
	  (CO_ChkErr(*l_debug_info_ptr)==APL_FAILURE)



#define	IS_ANY_ORA_ERROR_AUDIT\
			if (sqlca.sqlcode < 0)\
			{\
				char	chr_buffer[KEY_LENGTH];\
				ltoa_r(abs(sqlca.sqlcode),chr_buffer,KEY_LENGTH-1);\
				CO_InsertErr(l_debug_info_ptr,\
									ERR_DB_CANT_LOG_AUDIT,\
									chr_buffer,\
									p_intlenv_data_struct_h->usr,\
									chr_sys_date_time,\
									__LINE__,\
									__FILE__);\
				goto RETURN_FAILURE;\
			}

#define	APL_INVALID_CASE_VAL(value_to_set,h_key1,h_key2,h_key3)\
				CO_InsertErr(l_debug_info_ptr,\
									ERR_VAL_NF,\
									h_key1,\
									h_key2,\
									h_key3,\
									__LINE__,\
									__FILE__);\
			value_to_set=APL_FAILURE;



/******* For Reports By : vinay kalaskar **************/

typedef struct {
	char	report_id[11];
	char	image_path[501];
	char 	page_header[2001];
	int 	page_hdr_brk;
	char  page_hdr_align[21];
	char	gen_query[4001];
	char 	before_title[2001];
	int 	before_title_brk;
	char  before_title_align[21];
	char 	before_title1[2001];
	int 	before_title1_brk;
	char  before_title1_align[21];
	char 	before_title2[2001];
	int 	before_title2_brk;
	char  before_title2_align[21];
	char 	before_title3[2001];
	int 	before_title3_brk;
	char  before_title3_align[21];
	char	report_title[2001];
	int 	report_title_brk;
	char  report_title_align[21];
	char	after_title[2001];
	int 	after_title_brk;
	char  after_title_align[21];
	int 	no_of_columns;
	int	no_of_tables;
	char	page_footer[2001];
	int 	page_footer_brk;
	char  page_footer_align[21];
	int 	table_brk;
	char	client_flag[3];
	char  mst_sub_query[4001];
	char  default_query[4001];
	char  delete_flag[3];
	char  paging_flag[3];
	char  print_type[3];
	int  main_page_recs;
	int  next_page_recs;
	char letter_flag[3];
	char header_query[4001];
	char header_data[4001];
	int  header_brk;
	char header_data_align[21];
	char header_query1[4001];
	char default_query1[4001];
	char disclaimer[4001];
	char report_type[10];
	char report_lbl_param[2001];
	char mandatory_cols[201];
	char no_of_params[3];
	char letter_grp_query[4001];
	char letter_grp_flag[10];
	char maker[15];
	char maker_dt[21];
	char checker[15];
	char checker_dt[21];
	char access_stamp[21];
	char status[3];
	
} REPORT_MAIN_STRUCT_H;

typedef struct {

	short	report_id;
	short	image_path;
	short	page_header;
	short	page_hdr_brk;
	short page_hdr_align;
	short	gen_query;
	short	before_title;
	short	before_title_brk;
	short before_title_align;
	short	before_title1;
	short	before_title1_brk;
	short before_title1_align;
	short	before_title2;
	short	before_title2_brk;
	short before_title2_align;
	short	before_title3;
	short	before_title3_brk;
	short before_title3_align;
	short	report_title;
	short	report_title_brk;
	short report_title_align;
	short	after_title;
	short	after_title_brk;
	short after_title_align;
	short	no_of_columns;
	short	no_of_tables;
	short	sub_rpt_flag;
	short	sub_rpt_grp;
	short	page_footer;
	short	page_footer_brk;
	short page_footer_align;
	short	table_brk;
	short	param_string;
	short client_flag;
	short mst_sub_query;
	short default_query;
	short  delete_flag;
	short  paging_flag;
	short  print_type;
	short  main_page_recs;
	short  next_page_recs;
	short letter_flag;
	short header_query;
	short header_data;
	short header_brk;
	short header_data_align;
	short header_query1;
	short default_query1;
	short disclaimer;
	short report_type;
	short report_lbl_param;
	short mandatory_cols;
	short no_of_params;
	short letter_grp_query;
	short letter_grp_flag;
	short maker;
	short maker_dt;
	short checker;
	short checker_dt;
	short access_stamp;
	short status;

} REPORT_MAIN_STRUCT_I;

typedef struct {
	char	report_id[11];
	int	table_id;
	char	table_hdr[2001];
	int	table_hdr_brk;
	char  table_hdr_align[21];
	char	before_table[2001];
	int	before_table_brk;
	char  before_table_align[21];
	char	column_hdr[4001];
	int	col_hdr_brk;
	char	after_table[2001];
	int	after_table_brk;
	char  after_table_align[21];
	char	table_query[4001];
	char	table_query1[4001];
	char	table_query2[4001];
	int	no_of_columns;
	char  criteria_col1_query[4001];
	char  criteria_col1_name[201];
	int   criteria_col1_pos;
	char  criteria_col2_query[4001];
	char  criteria_col2_name[201];
	int   criteria_col2_pos;
	char  criteria_col3_query[4001];
	char  criteria_col3_name[201];
	int   criteria_col3_pos;
	int   tot_criteria_cols;
	char	table_footer[2001];
	int	table_footer_brk;
	char  table_footer_align[21];
	char  grand_total_flag[3];
	char  group_query[4001];
	char  group_desc[4001];
	char  group_pos[11];
	char  delete_flag[3];
	   	char comx_criteria_query[4001];
	char comx_criteria_label[4001];
	char comx_criteria_pos[101];
	char footer_query[4001];
	char footer_data[4001];
	int  footer_data_brk;
	char footer_data_align[21];
	char complex_criteria[4001];
	char multiple_col_flag[2];
	char multiple_col_header[4001];
	char multiple_colspan_sep[2001];
	char comx_criteria_query1[4001];
	char footer_query1[4001];
	char report_type[10];
	char maker[15];
	char maker_dt[21];
	char checker[15];
	char checker_dt[21];
	char access_stamp[21];
	char status[3];
	char record_count_query[4001];
	char record_count_query1[4001];
	char format_col_pos[501];
	char more_qry_flag[3];
	char table_query3[4001];
	char table_query4[4001];
	char table_query5[4001];
		
} REPORT_DETAILS_STRUCT_H;

typedef struct {
	short	report_id;
	short	table_id;
	short	table_hdr;
	short	table_hdr_brk;
	short table_hdr_align;
	short	before_table;
	short	before_table_brk;
	short before_table_align;
	short	column_hdr;
	short	col_hdr_brk;
	short	after_table;
	short	after_table_brk;
	short after_table_align;
	short	table_query;
	short	table_query1;
	short	table_query2;
	short	no_of_columns;
	short criteria_col1_query;
	short criteria_col1_name;
	short criteria_col1_pos;
	short criteria_col2_query;
	short criteria_col2_name;
	short criteria_col2_pos;
	short criteria_col3_query;
	short criteria_col3_name;
	short criteria_col3_pos;
   short tot_criteria_cols;
	short	table_footer;
	short table_footer_brk;
	short table_footer_align;
	short grand_total_flag;	
	short group_query;
	short group_desc;
	short group_pos;
	short  delete_flag;
	short comx_criteria_query;
	short comx_criteria_label;
	short comx_criteria_pos;
	short footer_query;
	short footer_data;
	short footer_data_brk;
	short footer_data_align;
	short complex_criteria;
	short multiple_col_flag;
	short multiple_col_header;
	short multiple_colspan_sep;
	short comx_criteria_query1;
	short footer_query1;
	short report_type;
	short maker;
	short maker_dt;
	short checker;
	short checker_dt;
	short access_stamp;
	short status;
	short record_count_query;
	short record_count_query1;
	short format_col_pos;
	short more_qry_flag;
	short table_query3;
	short table_query4;
	short table_query5;
		
} REPORT_DETAILS_STRUCT_I;


typedef struct {
   char  report_name[51];
   char  report_desc[31];
   char  report_date[20];
   int   report_width;
   char  task_desc[61];
   char  fe_be_ind[2];
   char  usr[14];
} INTL_REPT_STRUCT_H ;


/**************************************************************/


/** Macro checks if debug flag is yes/no, if yes it returns true **/
#define APL_IF_DEBUG\
		if( ( (!l_debug_info_ptr) || (*l_debug_info_ptr)==NULL)?APL_DEBUG_YES:((*l_debug_info_ptr)->debug_ind))

#ifdef APL_THREADS
#ifndef PURE_C_SOURCE
typedef	struct	{
	sql_context	ctx;
	short			status_ind;
	}	SYS_ORA_CTX;

#ifndef CONTEXT_MANAGE
extern	const	SYS_ORA_CTX			l_sys_ora_ctx[];
#endif

#define	APL_SET_CONTEXT\
			sql_context	my_ctx_local;\
			my_ctx_local = l_sys_ora_ctx[(*l_debug_info_ptr)->h_ctx_no].ctx;

#define  APL_RAISE_NO_CTX\
         {\
         CO_InsertErr(l_debug_info_ptr,\
                        ERR_NO_DR_CTX,\
                        APL_NULL_STRING,\
                        APL_NULL_STRING,\
                        APL_NULL_STRING,\
                        __LINE__,\
                        __FILE__);\
         CO_InsertMsg(*l_debug_info_ptr);\
         goto RETURN_FAILURE;\
         }
			
#endif 
#endif 

#define APL_EPSILON 1e-4
#define APL_DOUBLE_EQUAL(x,y) ((fabs((double)((x)-(y)))) < APL_EPSILON)
#define APL_DOUBLE_LESS(x,y)  ((double)((x)-(y)) < -APL_EPSILON)

#define CHECK_ACL(user,chr_func,h_res,chr_log) if(CO_Chk_Acl(user,chr_func,h_res)==APL_FAILURE)\
{\
		fprintf(chr_log,"CheckAcl returned failure\n");\
		APL_GOBACK_FAIL\
		}\
	if(*(h_res)==APL_SUCCESS)\
		fprintf(chr_log,"Acl successfull perm granted\n");\
	else {\
		fprintf(chr_log,"Acl successfull perm denied\n");\
		APL_GOBACK_FAIL\
		}

#define	APL_PASSWD_LEN	100

/* Retrofit done by Gouse for Back End Encryption & Decryption of DB User Name & Password Starts here */


/** Macro gets details for system login, like database username and password **/
/* #define APL_FETCH_DB_LOGIN_DETAILS(chr_inifile,chr_custody_id_b,chr_db_id,chr_db_pwd,chr_logfile,l_debug_info_ptr) {\
	if(CO_ReadToken(chr_inifile,"INTL_CUSTODY_ID",chr_custody_id_b,l_debug_info_ptr)==APL_FAILURE) {\
		CO_ProcMonitor(chr_logfile,"could not get chr_custody_id_c from chr_inifile..quitting\n",l_debug_info_ptr, NULL);\
		APL_GOBACK_FAIL\
		}\
	if(CO_GetDbCMCon(chr_custody_id_b,chr_db_id,chr_db_pwd)==APL_FAILURE){\
		CO_ProcMonitor(chr_logfile,"Could not get db id/chr_pwd .. quitting\n",l_debug_info_ptr, NULL);\
		APL_GOBACK_FAIL\
		}\
	if(CO_Rls_Context()==APL_FAILURE) {\
		CO_ProcMonitor(chr_logfile,"Could not release context.. exitting\n",l_debug_info_ptr, NULL);\
		APL_GOBACK_FAIL\
		}\
	} ** Commented and redefined for Web Intellect Encryption - Decryption Changes ** Naren V */

#define APL_FETCH_DB_LOGIN_DETAILS(chr_inifile,chr_custody_id_b,chr_db_id,chr_db_pwd,chr_logfile,l_debug_info_ptr) {\
     if(CO_GetDbCMCon(chr_custody_id_b,chr_db_id,chr_db_pwd)==APL_FAILURE){\
	CO_ProcMonitor(chr_logfile,"\n Could not get db id/chr_pwd .. quitting \n",l_debug_info_ptr, NULL);\
	APL_GOBACK_FAIL\
     }\
	}

/* Retrofit done by Gouse for Back End Encryption & Decryption of DB User Name & Password Ends here */


#define APL_GREATER(a,b) ( (double)(a) -(double)(b) >= APL_EPSILON )



#define APL_GREATER_EQUAL(a,b) ( (double)(a) -(double)(b) > -APL_EPSILON )



#define APL_LESS(a,b) (   (double)(b) -(double)(a)  >= APL_EPSILON )



#define APL_LESS_EQUAL(a,b) (   (double)(b) -(double)(a)  > -APL_EPSILON )

#endif
