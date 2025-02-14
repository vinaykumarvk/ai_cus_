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
 * File Name           :		Intellect_Common.h
 *
 * Description         :		Contains Definitions related to Masters.
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author           Description			RFS No.
 * ---------   --------	 ---------------  ------------------	---------
 * 10/10/2005   1.2			Smita Bhat			New File				HDFCMT_003
 *
 * 10/10/2005   1.4			ANILKUMAR			Added Audit Trail	HDFCMT_002,HDFCMT_005,HDFCMT_006
 * 														Related Dfns
 *
 * 03/01/2006	 1.5			Smita Bhat			Changed for Instrument	HDFCMT_003
 * 15/12/2005	1.6       Kouser Begum       Contain Macro Description for field in Client. 	HDFCMT_001					
 * 18/01/2006   1.7		  Smita Bhat	     Changes related to CA		Base Version for CA	   * 06/02/2006   1.8       Kouser Begum      Changes related Instrument Master - HDFCMT_003   * 06/02/2006   1.9       Kouser Begum      Added New Macro for HDFC - New Requirement 			                                                                        HDFCMT_003	
 * 28/02/2006   1.15      Kouser Begum      Added New Column for Daily
 *                                          Regulatory Reports             INT_REP_001 
 * 20/07/2011   1.0.1.5   Shweta Shinde     ISKB_4802 : New Core banking changes -- -GL & CASA changes
 * 18/10/2011            Sana Bhatkar     Retro done for AIX mig for ISKB_4802 : New Core banking changes -- -GL & CASA changes
 * 24/03/2022   1.16     kotubabu          Linux Migration    Kotak Implementation
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
#define	APL_STS_CLOSE					"CA" /**added by Swapnil for allowing Freezed client. isolve no ISKB_2188**/

#define	ACTION_NEW_IND					"I"
#define	ACTION_MOD_IND					"M"
#define	ACTION_DEL_IND					"D"

#define APL_ONLINE_IND "O"	/** Online mode , refer pro_sys_date**/
#define APL_EOD_IND    "E"	/** EOD mode , refer pro_sys_date**/
#define APL_BOD_IND    "B"	/** BOD mode , refer pro_sys_date**/


/** Following the modes for the system to perform. this will be passed from FE to BE in environ_data**/
#define	APL_FUNC_INPUT		"INP"	/** Input Mode **/
#define	APL_FUNC_MODIFY		"MOD"	/** Modify Mode **/
#define	APL_FUNC_DELETE		"DEL"	/** Delete Mode **/
#define	APL_FUNC_REVERSE	"REV"	/** Reverse Mode **/
#define	APL_FUNC_FREEZE		"FRZ"	/** Freeze Mode **/
#define	APL_FUNC_UNFREEZE	"UFR"	/** Unfreeze Mode **/
#define	APL_FUNC_AUTHORISE	"AUT"	/** Authorise Mode **/
#define	APL_FUNC_RESET		"RES"	/** Reset Mode **/
#define	APL_FUNC_APPROVE	"APR"	/** Approve Mode **/
#define	APL_FUNC_GENERATE	"GEN"	/** Generation Mode **/
#define APL_FUNC_REPAIR        "RPR"   /** Repair Mode **/
#define APL_FUNC_OVERRIDE       "OVR"   /** Override Mode **/

/** End of the modes for the system to perform.**/

/* - Smita Commented - HDFCMT_003  **/
#define	APL_INSTRU_BOND				"BON"
#define	APL_INSTRU_SHARE				"SHS"
#define	APL_INSTRU_FMT					"FMT"
#define	APL_INSTRU_RIGHTS				"RTS"
#define	APL_INSTRU_WARRANTS			"WTS"

/*Changes for CA Base Version - Smita*/
#define	APL_INSTRU_RIGHTS				"RTS"
/*Changes for CA Base Version - Smita*/
#define	APL_INSTRU_REGD				"RG"
#define	APL_INSTRU_BEAR				"BR"

#define APL_FRQENCY_CD_ANNUAL			"A"
#define APL_FRQENCY_CD_SEMIANNUAL	"S"
#define APL_FRQENCY_CD_MONTHLY		"M"
#define APL_FRQENCY_CD_QUARTERLY		"Q"
#define APL_FRQENCY_CD_OTHERCASE		"X"

#define APL_FUNC_MRK_DVP "DVP" /*Chirag*/

#define  APL_DEAL_DF           		"1"
#define  APL_DEAL_RF           		"2"
#define  APL_DEAL_DVP          		"3"
#define  APL_DEAL_RVP          		"4"
#define  APL_DEAL_CD           		"5"
#define  APL_DEAL_CR           		"6"
#define  APL_DEAL_DCD          		"7"
#define  APL_DEAL_RCR          		"8"

#define  S_MSG_SCH               	"MS_SCH"
#define  S_MSG_SCH_HOLDG         	"MS_SCHHoldg"
#define  S_MSG_SCH_PENDG         	"MS_SCHPendg"
#define  S_MSG_SCH_TRANS         	"MS_SCHTrans"
#define	APL_ROWID_LEN					19

#define	APL_NULL_TIME					" 12:00:00"

#define  APL_CONDID_LEN					31
#define  APL_MAINFUNCAREA_LEN 		21 


#define  ST_MAN_MSG   					9000001
#define  EN_MAN_MSG   					9999999

#define  ST_BLDLV_MSG   				7000001
#define  EN_BLDLV_MSG   				9000000

#define  ST_FM_MSG   					1
#define  EN_FM_MSG   					7000000

/*OPT AIX -START
#ifdef DATA_FIELD_SEPRTR
#undef DATA_FIELD_SEPRTR
#endif
OPT AIX -END*/

#define DATA_FIELD_SEPRTR 				''
#define DATA_VALUE_SEPRTR 				''
#define ERR_FLD_SEP 						'|'
#define ERR_REC_SEP 						'#'

/* Sonali , Audit log */
#define AUDIT_DATA_FIELD_SEPRTR ""
#define AUDIT_DATA_VALUE_SEPRTR ""
/*********************/


#define APL_CUBK_BROKER					'B'
#define APL_CUBK_CUSTOMER				'C'
#define APL_CUBK_ALL						'A'


#define APL_BTCH_STATUS_LEN			16
#define APL_COMPLETED_STATUS			"completed"
#define APL_STARTED_STATUS				"started"


#define MS_CCS_T1							"T1"
#define MS_CCS_T2							"T2"
#define MS_CCS_T3							"T3"
#define MS_CCS_T4							"T4"
#define MS_CCS_FC							"FC"
#define MS_CCS_CN							"CN"
#define MS_CCS_RL							"RL"
#define MS_CCS_SC							"SC"
#define MS_CCS_SR							"SR"
#define MS_CCS_II							"II"
#define MS_CCS_IP							"IP"
#define MS_CCS_IF							"IF"
#define MS_CCS_IC							"IC"
#define MS_CCS_IS							"IS"
#define MS_CCS_IX							"IX"
#define MS_CCS_XS							"XS"
#define MS_CCS_XD							"XD"
#define MS_CCS_X3							"X3"
#define MS_CCS_XX							"XX"


#define CONV_FROM_TRL      			"TRL"
#define CONV_TO_TRY        			"TRY"
#define CONV_AMT           			1000000
#define CONV_QTY           			1000

/*Smita - HDFCMT_003 - Instrument Master Maintenance*/
#define APL_EXARENA						"1"
#define APL_ORDER_CLASS					"1"
#define APL_TIPO_INV						"03"
#define APL_PROD_TYPE					"1"

/***** For PROD_CLASS Enhancement : vinay kalaskar ******/

#define APL_PROD_SHS_TYPE           "1"
#define APL_PROD_BON_TYPE           "2"

/********************************************************/

#define APL_PARTY_IPA					"I"
#define APL_PARTY_REG					"R"

#define APL_INSTRUMENT_CHILD_CNT	 	7

#define APL_MASTER_IND					"M"
#define APL_CHILD_IND					"C"
/*Smita - HDFCMT_003 - Instrument Related Changes - Defined Common Macros*/
#define APL_COUNTRY_CODE				"IN"
#define APL_DEF_COUNTRY_CODE			"XX"
/*Smita - HDFCMT_003 - Instrument Related Changes - Defined Common Macros*/

#define APL_PC_DAILY						"D"
#define APL_PC_PUT						"P"
#define APL_PC_CALL						"C"

#define APL_SEMICOLON_IND				";"

#define APL_INSTRU_PTC					"PT"
#define APL_INSTRU_BOND_VALUE_BASED	"BD"
#define APL_INSTRU_SUB_SHARE			"EQ"
#define APL_INSTRU_PREF_SHARE			"PR"
#define APL_INSTRU_SUB_WARRANTS		"WR"
#define APL_INSTRU_DEBENTURES			"DB"
#define APL_INSTRU_SUB_BOND			"DB"
#define APL_INSTRU_SUB_FMT				"FM"
#define APL_INSTRU_LOYALTY_COUPONS	"LC"
#define APL_INSTRU_GOVT_BOND			"GB"
#define APL_INSTRU_GOVT_PAPERS		"GP"
#define APL_INSTRU_MISCELLANEOUS	   "MS"
#define APL_INSTRU_UNIT	   			"UN"
#define APL_INSTRU_SECU_PREM_NOTE	"SP"
#define APL_INSTRU_FIXED_DEPO_RCP	"FD"
#define APL_INSTRU_BOND_QNTY_BASED	"BN"
#define APL_INSTRU_EXS_EQUITY_CD		"EX"
#define APL_INSTRU_RIGHTS_FORM		"RF"
#define APL_INSTRU_SAVINGS_CERT		"SC"
#define APL_INSTRU_CERT_OF_DEPO		"CD"
#define APL_INSTRU_COMM_PAPER			"CP"
#define APL_INSTRU_PRIVATE_PLACED	"PP"
#define APL_INSTRU_ALLOT_LETTER		"AL"
#define APL_INSTRU_PROMISSORY_NOTE	"PN"
#define APL_INSTRU_DEMATERIALISE		"DM"
#define APL_INSTRU_DEMAT				"DE"
#define APL_INSTRU_COUNTER_RCP		"CR"
#define APL_INSTRU_SGL_VALUE_BONDS	"SG"
#define APL_INSTRU_CERT_OF_HOLD		"CH"
#define APL_INSTRU_FRAC_COUPONS		"FC"
#define APL_INSTRU_GOVT_SEC			"GS"
#define APL_INSTRU_PTC              "PT"
/*Smita - HDFCMT_003 - Instrument Master Maintenance*/

/* Kouser - HDFCMT_003 - Instrument Master Maintenance */

#define APL_INSTRU_FIXED            "F"
#define APL_INSTRU_FLOATING         "L"

/* Kouser - HDFCMT_003 - Instrument Master Maintenance */

/* Client Master Maintenance - HDFCMT_001 - Kouser */
#define APL_CLIENT_CHILD_CNT		     	         5
#define APL_SWIFT_ADDRESS			              "S"
#define APL_CLIENT_OURTHEIR_IND                 "O" 
#define APL_CLIENT_ISCC_IND                     "N" 
#define APL_CLIENT_USE_IND                      "N" 
#define APL_CLIENT_BILL_IND                     "N" 
#define APL_CLIENT_BRKALL_IND                   "C" 
#define APL_CLIENT_SPOT_IND                     "N" 
#define APL_CLIENT_SELL_IND                     "N" 
#define APL_CLIENT_BUY_IND                      "N"
#define APL_CLIENT_INC_IND                      "N" 
#define APL_CLIENT_FMTRPT_IND                   "N" 
#define APL_CLIENT_PARTIAL_IND                  "N" 
#define APL_CLIENT_ALLREG_IND                   "N" 
#define APL_CLIENT_SETL_IND                     "N" 
#define APL_CLIENT_BCL_IND                      "N" 
#define APL_CLIENT_SUPPORT_IND                  "N" 
#define APL_CLIENT_DL_IND                       "N" 
#define APL_CLIENT_STARTDL_IND                  "N"
#define APL_CLIENT_MSGTYPE                      "S" 

/* Added by Dnyanesh */
char *strtok_r(char *s1, const char *s2, char **lasts);

/* Client Master Maintenance - HDFCMT_001 - Kouser */

/**** BCN ***/

#define STATUS_OVERRIDE          		"OR"
#define STATUS_REPAIR           			"RR"
#define  APL_ENTRY_FLG_SYS             "S"
#define  APL_CLNGRP_FII               	"FII"
#define  APL_CAUTION_FLG_NRIOCB       	"Y"
#define  APL_CLNGRP_NRI               	"NRI"
#define  APL_CAUTION_FLG_Y             "Y"
#define  APL_INTER_FII_IND             "N"
#define  APL_PARTY_TYPE_IND            "B"
#define APL_FUNC_SEBI						"SEB"
//Changes done by Sunny to show failure reason of swift SEBI to note column of deal repair start
#define  APL_ENTRY_SEBI     "T"
#define  APL_UPLD_ENTRY     "U"
//Changes done by Sunny to show failure reason of swift SEBI to note column of deal end
/************/


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
			if (sqlca.sqlcode < 0 )\
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






typedef struct {
	char	entitl_base[2];
	char	amount_ratio_flg[2];
	char	ratio_pct_ind_bonus[2];
	char	ratio_pct_ind_sd[2];
	char	ratio_pct_ind_rights[2];
	char	new_dl_bo_ind[2];
	char	new_dl_sd_ind[2];
	char	new_dl_rts_ind[2];
	char	new_dl_rd_ind[2];
	char	new_dl_split_ind[2];
	char	sndmsg_to_allmast[2];
	char	new_evt_bond_int[2];
	int	bond_int_no_days_pay_dt;
	char	new_evt_mmi_int[2];
	int	mmi_int_no_days_pay_dt;
	char	new_evt_bond_rd[2];
	int	bond_rd_no_days_mat_date;
	char	new_evt_mmi_rd[2];
	int	mmi_rd_no_days_mat_date;
	int	bond_exdate_no_days;
	int	mmi_exdate_no_days;
	char	gen_enrarep_ind[2];
	int	h_enra_lapse_a;
	int	h_enra_lapse_b;
	int	i_enra_lapse_c;
} CASYSTEMPARAMS_STRUCT_H;



typedef struct {
	short	i_part__conf;
	short	i_manifld_print_ind;
	short	i_process_spot_deals;
	short	i_global_setlment;
	short	i_sub_cltt_processing;
	short	i_ord_proc_ind;
	short	i_non_stx_deal_processing;
	short	i_loc_processing;
	short	i_cltt_entries_flg;
	short	i_process_pr_feed_flg;
	short	i_dir_indir_fxqt_ind;
	short	i_proc_reg_ind;
	short	i_part__reg_flg;
	short	i_amount_dec_length;
	short	i_qty_dec_len;
	short	i_min_cltt_length;
	short	i_max_amount_diff;
	short	i_auto_inactive_days;
	short	i_odd_lot_qty;
	short	i_proc_start_no;
	short	i_end_proc_no;
	short	i_witholding_tax_rt;
	short	i_fx_tax_rt;
	short	i_commission_tax_rt;
	short	i_paidupcapital_limit;
	short	i_err_cond_op_stx_deals;
	short	i_err_cond_op_other_deals;
	short	i_no_days_stx_recv_deals;
	short	i_no_days_stx_deliver_deals;
	short	i_no_days_other_recv_deals;
	short	i_no_days_other_deliver_deals;
	short	i_no_days_spot_deals;
	short	i_no_days_spot_other_deals;
	short	i_citibank_cltt_code;
	short	i_brkrage_cltt_code;
	short	i_ny_branch_usd_cltt;
	short	i_vtb_cltt_code;
	short	i_vtb_cltt_name;
	short	i_vtb_identify;
	short	i_vdp_flag;
	short i_citibank_comm_rt;
	short	i_safek_exch_comm_rt;
	short i_send_53x_online_eod;
 short i_brokerage;
 short i_sttrate;
} MT_CORE_SYS_PARAMS_STRUCT_I;




typedef struct {
	short	i_entitl_base;
	short	i_amt_rt_ind;
	short	i_ratio_pct_ind_bonus;
	short	i_ratio_pct_ind_sd;
	short	i_ratio_pct_ind_rights;
	short	i_new_dl_bo_ind;
	short	i_new_dl_sd_ind;
	short	i_new_dl_rts_ind;
	short	i_new_dl_rd_ind;
	short	i_new_dl_split_ind;
	short	i_evtmsg_all_mstclt;
	short	i_new_evt_bond_int;
	short	i_bond_int_no_days_pymt_dt;
	short	i_new_evt_mmi_int;
	short	i_mmi_int_no_days_pymt_dt;
	short	i_new_evt_bond_rd;
	short	i_bond_rd_no_days_mat_date;
	short	i_new_evt_mmi_rd;
	short	i_mmi_rd_no_days_mat_date;
	short	i_bond_exdate_no_days;
	short	i_mmi_exdate_no_days;
	short	i_gen_enrarep_ind;
	short	i_enra_lapse_a;
	short	i_enra_lapse_b;
	short	i_enra_lapse_c;
} CASYSTEMPARAMS_STRUCT_I;




typedef struct {
	short	i_b_ccy;
	short	i_b_basis;
	short	i_late_dl_days_a;
	short	i_max_write_off_amount;
	short	i_db_txnrcd;
	short	i_cred_txnrcd;
	short	i_val_days;
	short	i_periodfor_arch;
	short i_pymt_gen_day;
	short	i_pymt_status;
	short i_latetime_a;
	short i_late_dl_days_b;
	short i_latetime_b;
	short i_late_dl_days_c;
	short i_latetime_c;
	short i_late_dl_days_d;
	short i_latetime_d;
} INVOICE_SYSTEMPARAM_STRUCT_I;




typedef struct {
	short	i_evt_msg_all_mast_cltt;
	short	i_mt596_for_conf_flg;
	short	i_allowed_tlx_len;
	short	i_allowed_retension_prd;
	short	i_gen_fx_adv_flag;
	short	i_swift_cd;
	short	i_gcn_cd;
	short	i_auto_msg_rpr_flag;
	short	i_reg_foll_up_msg_flag;
	short	i_msg_follow_days1;
	short	i_msg_follow_days2;
	short	i_vtb_swift_contactinfo;
	short i_response_days;
	short i_ccs_int_flag;
	short i_line_ind;
} MT_MESSAGE_SYS_PARAMS_STRUCT_I;




typedef struct {
	short	i_ca_identclr_name;
	short	i_ca_address;
	short	i_nation_code;
	short	i_brnch_cd;
	short	i_domestic_curr_cd;
 	short	i_dom_instrument;
	short	i_gl_interface_mod_ind;
	short	i_bill_module_flag;
	short	i_ca_module_flag;
	short	i_f_file_path;
	short	i_b_file_path;
	short	i_monthsfor_arch;
	short i_ei_smi_ind;       
   short i_ccs_flag;       
   short i_office_for_booking;     
   short i_installed_at_bank;     
  short i_cust_code;
} MT_COMMON_SYS_PARAMS_STRUCT_I;



typedef struct {
  char  module_ind;
  char brnch_cd[4];
  char inden_num[11];
/*char client[24]; */
  char client[29]; /*Changed by Shweta -- ISKB_4802 -- 20072011*/
  char curr_cd[4];
  double fccy_amt;
  double exchg_rt;
  double lcl_amount;
  char val_date[9];
  char deal_cd[4];
  char spl_clt_cd[9];
  char db_cr_ind;
  char description[101];
  char status_ind;
  char proc_num[10];
  double report_amt;
  double report_clt;
  double report_tax;
  double report_ser;
  double rep_exg_rt;
  char rec_refer;
  char proc_dt[20];
  char deal_ident[51];
  char leg_ind[11];
  char acc_type[2];
  char passed_through[2];
  char api_request_id[26];
  char api_status[11];
  char api_reason_code[11];
  char api_reason_desc[251];
  char finacle_tran_id[51];
  char finacle_tran_date[26];
}   PRO_ACCTENT_STRUCT_H;

typedef struct {
  short i_module_ind;
  short i_brnch_cd;
  short i_sequence_num;
  short i_dl_client;
  short i_curr_cd;
  short i_fcy_amt;
  short i_exch_rt;
  short i_lcy_amount;
  short i_value_date;
  short i_deal_cd;
  short i_spl_clt_cd;
  short i_db_cr_flag;
  short i_description;
  short i_status_ind;
  short i_proc_num;
  short i_rep_amount;
  short i_report_clt;
  short i_report_tax;
  short i_report_ser;
  short i_rexae_rate;
  short i_rec_identify;
  short i_batch_dt;
  short i_deal_ident;
  short i_leg_ind;
  short i_acc_type;
  short i_passed_through;
  short i_api_request_id;
  short i_api_status;
  short i_api_reason_code;
  short i_api_reason_desc;
  short i_finacle_tran_id;
  short i_finacle_tran_date;
  }   PRO_ACCTENT_STRUCT_I;





typedef struct {
	char  h_module_ind[2];
	char  h_proc_num[6];
	char  h_batch_dt[20];
 	char  h_instr_class[2];
	char  h_rec_class[4];
	char  h_status_ind[2];
	char  h_entry[4];
	char  h_dl_client[11];
	char  h_currencycode[4];
	double h_trans_amt;
	char  h_value_date[20];
	char  h_deal_cd[4];
	char  h_db_cr_flag[2];
	char  h_splgr_clt_cd[11];
	char  h_statistic[5];
	char  h_trans_bog[6];
	long int h_quantity_items;
	char  h_offset_client[11];
	char  h_broker_cd[6];
	char  h_nationality[4];
 	char  h_instr_isin[13];
	char  h_special_tax[21];
	char  h_indentity_no[11];
	char  h_auto_rec_flag[11];
	char  h_note_a[33];
	char  h_note_b[33];
	double h_fcy_amt;
	int   h_mis_sprd;
	double h_rt;
	char  h_safekeep_pos[2];
	char  h_sequence[6];
	char  h_reas_cd[5];
	char  h_deal_ident[31];
	double h_rep_amount;
	double h_lcy_amount;
} PRO_GRACCTENT_STRUCT_H;
																																			
																																			
typedef struct {
	short i_module_ind;
	short i_proc_num;
	short i_batch_dt;
 	short i_instr_class;
	short i_rec_class;
	short i_status_ind;
	short i_entry;
	short i_dl_client;
	short i_currencycode;
	short i_trans_amt;
	short i_value_date;
	short i_deal_cd;
	short i_db_cr_flag;
	short i_splgr_clt_cd;
	short i_statistic;
	short i_trans_bog;
	short i_quantity_items;
	short i_offset_client;
	short i_broker_cd;
	short i_nationality;
 	short i_instr_isin;
	short i_special_tax;
	short i_indentity_no;
	short i_auto_rec_flag;
	short i_note_a;
	short i_note_b;
	short i_fcy_amt;
	short i_mis_sprd;
	short i_rt;
	short i_safekeep_pos;
	short i_sequence;
	short i_reas_cd;
	short i_deal_ident;
	short i_rep_amount;
	short i_lcy_amount;
} PRO_GRACCTENT_STRUCT_I;
	
typedef struct {
  char  module_ind;
  char brnch_cd[4];
  char inden_num[11];
  char client[24];
  char curr_cd[4];
  double fccy_amt;
  double exchg_rt;
  double lcl_amount;
  char val_date[9];
  char deal_cd[4];
  char spl_clt_cd[9];
  char db_cr_ind;
  char description[101];
  char status_ind;
  char proc_num[10];
  double report_amt;
  double report_clt;
  double report_tax;
  double report_ser;
  double rep_exg_rt;
  char rec_refer;
  char proc_dt[20];
  char deal_ident[51];
  char leg_ind[11];
  char acc_type[2];
  char passed_through[2];
  char api_request_id[26];
  char api_status[11];
  char api_reason_code[11];
  char api_reason_desc[251];
  char finacle_tran_id[51];
  char finacle_tran_date[26];
}   PRO_ACCTENT_PASSCLT_STRUCT_H;

typedef struct {
  short i_module_ind;
  short i_brnch_cd;
  short i_sequence_num;
  short i_dl_client;
  short i_curr_cd;
  short i_fcy_amt;
  short i_exch_rt;
  short i_lcy_amount;
  short i_value_date;
  short i_deal_cd;
  short i_spl_clt_cd;
  short i_db_cr_flag;
  short i_description;
  short i_status_ind;
  short i_proc_num;
  short i_rep_amount;
  short i_report_clt;
  short i_report_tax;
  short i_report_ser;
  short i_rexae_rate;
  short i_rec_identify;
  short i_batch_dt;
  short i_deal_ident;
  short i_leg_ind;
  short i_acc_type;
  short i_passed_through;
  short i_api_request_id;
  short i_api_status;
  short i_api_reason_code;
  short i_api_reason_desc;
  short i_finacle_tran_id;
  short i_finacle_tran_date;
}   PRO_ACCTENT_PASSCLT_STRUCT_I;


typedef struct {
  char  module_ind;
  char brnch_cd[4];
  char inden_num[11];
  char client[24];
  char curr_cd[4];
  double fccy_amt;
  double exchg_rt;
  double lcl_amount;
  char val_date[9];
  char deal_cd[4];
  char spl_clt_cd[9];
  char db_cr_ind;
  char description[101];
  char status_ind;
  char proc_num[10];
  double report_amt;
  double report_clt;
  double report_tax;
  double report_ser;
  double rep_exg_rt;
  char rec_refer;
  char proc_dt[20];
  char deal_ident[51];
  char leg_ind[11];
  char acc_type[2];
  char passed_through[2];
  char api_request_id[26];
  char api_status[11];
  char api_reason_code[11];
  char api_reason_desc[251];
  char finacle_tran_id[51];
  char finacle_tran_date[26];
  }   PRO_ACCTENT_PASSGL_STRUCT_H;

typedef struct {
  short i_module_ind;
  short i_brnch_cd;
  short i_sequence_num;
  short i_dl_client;
  short i_curr_cd;
  short i_fcy_amt;
  short i_exch_rt;
  short i_lcy_amount;
  short i_value_date;
  short i_deal_cd;
  short i_spl_clt_cd;
  short i_db_cr_flag;
  short i_description;
  short i_status_ind;
  short i_proc_num;
  short i_rep_amount;
  short i_report_clt;
  short i_report_tax;
  short i_report_ser;
  short i_rexae_rate;
  short i_rec_identify;
  short i_batch_dt;
  short i_deal_ident;
  short i_leg_ind;
  short i_acc_type;
  short i_passed_through;
  short i_api_request_id;
  short i_api_status;
  short i_api_reason_code;
  short i_api_reason_desc;
  short i_finacle_tran_id;
  short i_finacle_tran_date;
}   PRO_ACCTENT_PASSGL_STRUCT_I;


#ifndef	RTV_SYSTEM_DATA
	extern	const	MT_CORE_SYS_PARAMS_STRUCT_H		l_mt_core_sys_params_struct_h;
	extern	const	MT_COMMON_SYS_PARAMS_STRUCT_H		g_mt_commonsys_params_struct_h;
	extern	const	CASYSTEMPARAMS_STRUCT_H				g_a_params;
	extern	const	INVOICE_SYSTEMPARAM_STRUCT_H		l_invoice_systemparam_struct_h;
	extern	const	MT_MESSAGE_SYS_PARAMS_STRUCT_H	l_mt_message_sys_params_struct_h;
#endif


/** Macro checks if debug flag is yes/no, if yes it returns true **/
/*#define APL_IF_DEBUG\
		if( ( (!l_debug_info_ptr) || (*l_debug_info_ptr)==NULL)?APL_DEBUG_YES:((*l_debug_info_ptr)->debug_ind)) */

#define APL_IF_DEBUG\
	   if (1==1) 

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
	/* if(CO_ReadToken(chr_inifile,"INTL_CUSTODY_ID",chr_custody_id_b,l_debug_info_ptr)==APL_FAILURE) {\
		CO_ProcMonitor(chr_logfile,"could not get chr_custody_id_c from chr_inifile..quitting\n",l_debug_info_ptr, NULL);\
		APL_GOBACK_FAIL\
		}\
	if(CO_GetDbCMCon(chr_custody_id_b,chr_db_id,chr_db_pwd)==APL_FAILURE){\
		CO_ProcMonitor(chr_logfile,"Could not get db id/chr_pwd .. quitting\n",l_debug_info_ptr, NULL);\
		APL_GOBACK_FAIL\
		}\
	/* if(CO_Rls_Context()==APL_FAILURE) {\
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

/* OPT:AIX 
#ifdef SETTLEMENT
#undef SETTLEMENT
#endif*/

#define SETTLEMENT "C"
#define CORPORATE_ACT_IND "A"
#define GR_DUMMYCLI "D"
#define BILLABLE_DEAL_IND   'B'  
 #define BILLABLE_DEAL_INSTR_LEG   'S'  
#define ENTRY_MANUAL_IND                    'M'       

#define  MS_MSGNO_52X              "52x"           
#define  MS_MSGNO_586 					"586"
#define  MS_MSGNO_538              				"538"  
#define  MS_SWIFT_BOG_NO      "54B"
#define  MS_MSGNO_540					"540"				 
#define  MS_MSGNO_541					"541"				 
#define  MS_MSGNO_542					"542"				 
#define  MS_MSGNO_543					"543"				 



#define    MORE_THAN_ONE_ROW                   -2112
#define MORE_THAN_ONE_ROW_FOUND        30


#define  MS_MSGNO_52XN01					"52xN02"				 
#define  MS_MSGNO_54XN02					"54xN02"	
#define APL_INSTRU_MTF              "MTF" /* Added by Gouse for Kotak - Instrument Master Maintenance - 01/11/2011  */

#endif
