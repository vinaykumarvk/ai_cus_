/*
 *   COPYRIGHT NOTICE
 *   
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *   
 *   These materials are confidential and proprietary to
 *   Polaris Software Lab Limited and no part of these materials should
 *   be reproduced, published, transmitted or distributed in any form or
 *   by any means, electronic, mechanical, photocopying, recording or
 *   otherwise, or stored in any information storage or retrieval system
 *   of any nature nor should the materials be disclosed to third parties
 *   or used in any other manner for which this is not authorized, without
 *   the prior express written authorization of Polaris Software Lab Limited.
 */
/*******************************************************************************
 *  
 *    Module Name         :         Billing Module 
 *    
 *    File Name           :         IV_ProcOthServ.c
 *    
 *                Version Control Block
 *     
 *    Date        Version     Author              Description     RFS No.
 *   ---------   --------  ---------------  ----------------------------------
 *   08/12/2010   1.0.1.2   Siva Ganapathi  	Changes done for ISKB_2470 --
 *						safekeeping charges of a NAV based client
 *******************************************************************************/

#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"
#include "Intellect_Common.h"
#include "IV_OthServices.h"



int IV_Proc_OthServMnt(const IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a, 
		  const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		  DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int CO_Chk_AccValid(char *chr_l_client, char int_l_exist, char l_cubk, 
			       char l_orderac, char l_mastclt, char l_auth, 
			       char p_del, char l_frozen, char l_closed, 
			       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client, 
				     IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCNTLPARAM(SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVSRVCHRGDel(long l_serv_code, 
				    IV_SERV_MAST_STRUCT *l_iv_servmast_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkBillPeriod(const char *l_billprd, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVOTHSRVAnyRow(
					IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct, 
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_NewOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *l_iv_client_othserv_struct_h, 
				 const SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				 const char l_isstdfee, 
				 const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				 int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_ChgOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *l_iv_client_othserv_struct_h, 
				 const SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				 const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				 int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_AuthOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *l_iv_client_othserv_struct_h, 
				  const SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				  const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				  int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_buffer1[BUFFER_LEN], chr_l_temp_bill_prd[APL_DATE_LEN];
	char chr_l_usermode, chr_l_actionflag, *chr_l_last = (char *)NULL;
	int int_l_retstat = 0;
	IV_CLIENT_OTHSERV_STRUCT_H l_iv_client_othserv_struct_h = *p_iv_client_othserv_struct_h_a;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;
	SYS_IVCONTROLPARAM_STRUCT l_sys_ivcntlparam_struct;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;
	IV_SERV_OTH_STRUCT l_iv_serv_oth_structb_a;

	

	if ( !strlen(l_iv_client_othserv_struct_h.client) )
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING)	
	}

	memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer1, "%ld", l_iv_client_othserv_struct_h.service_cd);

	if ( !strlen(chr_l_buffer1) )
	{
		APL_DATA_MISSING("Service Code", APL_NULL_STRING, 
				  APL_NULL_STRING)	
	}

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE) )
	{
		chr_l_usermode = 'A';
	}

	chr_l_actionflag = NULL;

	if ( chr_l_usermode == 'M' )
	{
		if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_NEW_IND) )
		{
			chr_l_actionflag = 'I';
		}
		else if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_MOD_IND) )
		{
			chr_l_actionflag = 'M';
		}
	}

	if ( !((chr_l_usermode == 'I') || 
	       ((chr_l_usermode == 'M') && (chr_l_actionflag == 'I'))) )
	{
		if ( !strlen(l_iv_client_othserv_struct_h.access_stamp) )
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%d", l_iv_client_othserv_struct_h.inden_num);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Seq. Num.", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}
	}
	else
	{
		l_iv_client_othserv_struct_h.inden_num = 0;
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( !strlen(p_intl_envdatastruct_h->auth_req) )
		{
			APL_DATA_MISSING("Auth. Req. Flag", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%lf", l_iv_client_othserv_struct_h.quantity);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Qty. Service", APL_NULL_STRING, 
					  APL_NULL_STRING)	
		}

		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%lf", l_iv_client_othserv_struct_h.fees);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Fee", APL_NULL_STRING,APL_NULL_STRING)	
		}

		
		if ( ( (l_iv_client_othserv_struct_h.service_cd == SPECIALBILLING) || (l_iv_client_othserv_struct_h.service_cd == CASH_ITEMS ))&&
			!strlen(l_iv_client_othserv_struct_h.service_det) )
		
		{
			APL_DATA_MISSING("Serv. Desc.", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}
/* ISKB_1737 Starts */
if (strlen(l_iv_client_othserv_struct_h.service_det) == 0 )
{
APL_DATA_MISSING("Serv. Desc.", APL_NULL_STRING,
APL_NULL_STRING)
}/* ISKB_1737 Ends */

        /*Pallavi Starts ISKB_1737 Starts*/
	Alert("l_iv_client_othserv_struct_h.service_cd..|%d|",l_iv_client_othserv_struct_h.service_cd);
	Alert("l_iv_client_othserv_struct_h.quantity..|%lf|",l_iv_client_othserv_struct_h.quantity);
        Alert("l_iv_client_othserv_struct_h.b_prd..|%s|",l_iv_client_othserv_struct_h.b_prd);	
        if((l_iv_client_othserv_struct_h.service_cd!=98) && (l_iv_client_othserv_struct_h.service_cd!=99))
	{
	if((l_iv_client_othserv_struct_h.quantity) <=  0)
	{
		CO_InsertErr(l_debug_info_ptr, ERR_SRVCE_QTY_SHLD_GRT_THAN_0, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	 }
	}
	if((l_iv_client_othserv_struct_h.service_cd==98) ||(l_iv_client_othserv_struct_h.service_cd==99))
	{
		if (strlen(l_iv_client_othserv_struct_h.b_prd) == 0 )
		{
			APL_DATA_MISSING("Billing Period.", APL_NULL_STRING,
			APL_NULL_STRING)
		}
	}

	/*Pallavi Starts ISKB_1737 Ends*/
		/*Retrofitted from IB1185 by Anjaneyulu for ISKB_1737 start*/
	if(strlen(l_iv_client_othserv_struct_h.service_det) > 21)
	  {
		 Alert(" service_det : %d \n", strlen(l_iv_client_othserv_struct_h.service_det));
	CO_InsertErr(l_debug_info_ptr, ERR_LARGER_SIZE, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);
	
		APL_GOBACK_FAIL
	  }
	  /*Retrofitted from IB1185 by Anjaneyulu for ISKB_1737 end */ 
	} 
	
	if ( chr_l_usermode == 'A' )
	{
		if ( (l_iv_client_othserv_struct_h.purge_recall_ind != 'P') && 
		     (l_iv_client_othserv_struct_h.purge_recall_ind != 'R') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PURGE_RECALL_PR, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	

	if ( !strcmp(l_iv_client_othserv_struct_h.client, l_mt_core_sys_params_struct_h.custody_clt_cd) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_OTHERSERV_CANT_DEFINEFOR_INTRNLACC, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	if ( APL_FAILURE == CO_Chk_AccValid(l_iv_client_othserv_struct_h.client, 'Y', NULL, NULL, 
					NULL, NULL, NULL, NULL, NULL, l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Rtv_IVCUSTSETUP(l_iv_client_othserv_struct_h.client, 
					      &l_iv_cltsetup_struct, &int_l_retstat, 
					      l_debug_info_ptr) )
	{
		if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
		{
			APL_GOBACK_FAIL
		}
		else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLPARAM_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( l_iv_cltsetup_struct.stat_ind != 'A' )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_ACCOUNT_UNAUTH, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}
	else if ( ( strcmp(l_iv_client_othserv_struct_h.b_ccycd, l_iv_cltsetup_struct.fees_ccy) ) &&
				  ( (l_iv_client_othserv_struct_h.service_cd == UNDERBILLING ) ||
				     (l_iv_client_othserv_struct_h.service_cd == OVERBILLING ) ||
				     (l_iv_client_othserv_struct_h.service_cd == SPECIALBILLING ) )) /* Bageshri for NAV */
	{
		CO_InsertErr(l_debug_info_ptr, ERR_OTHRSRVCCY_INVALID, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Rtv_IVSRVCHRGDel(l_iv_client_othserv_struct_h.service_cd, 
					     &l_iv_serv_mast_struct, &int_l_retstat, 
					     l_debug_info_ptr) )
	{
		if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
		{
			APL_GOBACK_FAIL
		}
		else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
				       APL_NULL_STRING, APL_NULL_STRING,
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Rtv_IVCNTLPARAM(&l_sys_ivcntlparam_struct, &int_l_retstat, 
					     l_debug_info_ptr) )
	{
		if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
		{
			APL_GOBACK_FAIL
		}
		else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLCNTRL_PARAM_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING,
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( (chr_l_usermode == 'I') || 
	     ((chr_l_usermode == 'M') && (chr_l_actionflag == 'I')) )
	{
		if ( l_iv_serv_mast_struct.std_feeind == 'Y' )
		{
			if ( (l_iv_client_othserv_struct_h.service_cd != UNDERBILLING) && 
			     (l_iv_client_othserv_struct_h.service_cd != OVERBILLING) && 
			     (l_iv_client_othserv_struct_h.service_cd != SPECIALBILLING) &&  
			     (l_iv_client_othserv_struct_h.service_cd != CUSTODYFEE) ) /* Bageshri for NAV */
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			if ( ( l_iv_client_othserv_struct_h.service_cd == SPECIALBILLING ) || 
			     ( l_iv_client_othserv_struct_h.service_cd == CUSTODYFEE ) ) /* Bageshri for NAV */
			{
				if ( !strlen(l_iv_client_othserv_struct_h.service_det) )
				{
					APL_DATA_MISSING("Serv. Desc.", 
							  APL_NULL_STRING, 
							  APL_NULL_STRING)

					APL_GOBACK_FAIL
				}
			}
			else if ( !strlen(l_iv_client_othserv_struct_h.b_prd) )
			{
				APL_DATA_MISSING("Bill Period", APL_NULL_STRING,
						  APL_NULL_STRING)

				APL_GOBACK_FAIL
			}

		} 

		if ( (l_iv_client_othserv_struct_h.service_cd == UNDERBILLING) || 
		     (l_iv_client_othserv_struct_h.service_cd == OVERBILLING) )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_ChkBillPeriod(l_iv_client_othserv_struct_h.b_prd, 
					      &int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr, ERR_UB_OB_NA,
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);
				}

				APL_GOBACK_FAIL
			}
		}

	} 

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
         /*Modified by siva.ganapathi for ISKB_2470 on 07-Dec-2010 -- started*/
         //printf("\n SERVICE CODE is %d",l_iv_client_othserv_struct_h.service_cd); Chnages done for AIX Migration
         printf("\n SERVICE CODE is %ld",l_iv_client_othserv_struct_h.service_cd);
			fflush(stdout);

        	if (((l_iv_client_othserv_struct_h.service_cd != UNDERBILLING) &&
		     (l_iv_client_othserv_struct_h.service_cd != OVERBILLING) && 
                     (l_iv_client_othserv_struct_h.quantity <= 0.0) && (l_iv_client_othserv_struct_h.service_cd != CUSTODYFEE)) ||
                    ((l_iv_client_othserv_struct_h.service_cd == CUSTODYFEE) && (l_iv_client_othserv_struct_h.quantity < 0.0)))	
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SERV_POS_QTY, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
        /*Modified by siva.ganapathi for ISKB_2470 on 07-Dec-2010 -- Ended*/

		if ( (l_iv_serv_mast_struct.std_feeind == 'Y') && 
			  (l_iv_client_othserv_struct_h.service_cd != CUSTODYFEE) && 
		     (l_iv_client_othserv_struct_h.fees <= 0.0) ) /* Bageshri for NAV */
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SCHFEE_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( l_iv_client_othserv_struct_h.service_cd == UNDERBILLING )
		{
			memset(chr_l_temp_bill_prd, APL_NULL_CHAR, APL_DATE_LEN);

			strcpy(chr_l_temp_bill_prd, l_iv_client_othserv_struct_h.b_prd);

			strcpy(chr_l_temp_bill_prd, strtok_r(chr_l_temp_bill_prd, " ", 
			       &chr_l_last));

			memset(l_iv_client_othserv_struct_h.service_det, APL_NULL_CHAR, 
			       IV_DESC_LEN);

			strcpy(l_iv_client_othserv_struct_h.service_det, chr_l_temp_bill_prd);

			strcat(l_iv_client_othserv_struct_h.service_det, " UNDER BILL");
		}
		else if ( l_iv_client_othserv_struct_h.service_cd == OVERBILLING )
		{
			memset(chr_l_temp_bill_prd, APL_NULL_CHAR, APL_DATE_LEN);

			strcpy(chr_l_temp_bill_prd, l_iv_client_othserv_struct_h.b_prd);

			strcpy(chr_l_temp_bill_prd, strtok_r(chr_l_temp_bill_prd, " ", 
			       &chr_l_last));

			memset(l_iv_client_othserv_struct_h.service_det, APL_NULL_CHAR, 
			       IV_DESC_LEN);

			strcpy(l_iv_client_othserv_struct_h.service_det, chr_l_temp_bill_prd);

			strcat(l_iv_client_othserv_struct_h.service_det, " OVER BILL");
		}
		/*Retrofitted from IB1185 by Anjaneyulu for ISKB_1737 start*/
		else if ( l_iv_serv_mast_struct.std_feeind == 'N' && (l_iv_client_othserv_struct_h.service_cd != CASH_ITEMS ))
		
		{
			memset(l_iv_client_othserv_struct_h.service_det, APL_NULL_CHAR, 
			       IV_DESC_LEN);

			strcpy(l_iv_client_othserv_struct_h.service_det, l_iv_serv_mast_struct.service_det);
		}
		/*Retrofitted from IB1185 by Anjaneyulu for ISKB_1737 end*/
		if ( l_iv_serv_mast_struct.std_feeind == 'Y' )
		{
			if( ( l_iv_client_othserv_struct_h.service_cd != SPECIALBILLING ) &&
			  (l_iv_client_othserv_struct_h.service_cd != CUSTODYFEE) ) /* Bageshri for NAV */
			{
				l_iv_client_othserv_struct_h.quantity = 0.0;
			}
		}
		else
		{
			l_iv_client_othserv_struct_h.fees = 0.0;
		}

	} 

	if ( (l_iv_client_othserv_struct_h.service_cd == OVERBILLING) && 
	     ((chr_l_usermode == 'I') || (chr_l_usermode == 'M')) )
	{
		l_iv_client_othserv_struct_h.fees = -l_iv_client_othserv_struct_h.fees;
	}

	if ( !(chr_l_usermode == 'I') && 
	     !((chr_l_usermode == 'M') && (chr_l_actionflag == 'I')) )
	{
		memset(l_iv_serv_oth_structb_a.client, APL_NULL_CHAR, 
		       APL_CLIENT_LENGTH);
		memset(l_iv_serv_oth_structb_a.b_upto_date, APL_NULL_CHAR, 
		       APL_DATE_LEN);
		memset(l_iv_serv_oth_structb_a.maker, APL_NULL_CHAR, 
		       APL_USERID_LEN);
		memset(l_iv_serv_oth_structb_a.maker_dt, APL_NULL_CHAR, 
		       APL_DATE_LEN);
		memset(l_iv_serv_oth_structb_a.access_stamp, APL_NULL_CHAR, 
		       APL_DATE_LEN);
		memset(l_iv_serv_oth_structb_a.service_det, APL_NULL_CHAR, 
		       IV_DESC_LEN);
		memset(l_iv_serv_oth_structb_a.checker, APL_NULL_CHAR, 
		       APL_USERID_LEN);
		memset(l_iv_serv_oth_structb_a.checker_dt, APL_NULL_CHAR, 
		       APL_DATE_LEN);

		l_iv_serv_oth_structb_a.service_cd = 0L;
		l_iv_serv_oth_structb_a.service_qty = 0.0;
		l_iv_serv_oth_structb_a.schdl_fee = 0.0;
		l_iv_serv_oth_structb_a.service_stat = NULL;
		l_iv_serv_oth_structb_a.inden_num = 0;

		strcpy(l_iv_serv_oth_structb_a.client, l_iv_client_othserv_struct_h.client);
		strcpy(l_iv_serv_oth_structb_a.b_upto_date, l_sys_ivcntlparam_struct.b_upto_date);
		strcpy(l_iv_serv_oth_structb_a.access_stamp, 
		       l_iv_client_othserv_struct_h.access_stamp);

		l_iv_serv_oth_structb_a.service_cd = l_iv_client_othserv_struct_h.service_cd;
		l_iv_serv_oth_structb_a.inden_num = l_iv_client_othserv_struct_h.inden_num;

		int_l_retstat = 0;

		if (APL_FAILURE == 
				IV_Rtv_IVOTHSRVAnyRow(&l_iv_serv_oth_structb_a, 
							  &int_l_retstat, 
							  l_debug_info_ptr))
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
                	        CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_NOTFND,
	                                       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		if ( strcmp(l_iv_serv_oth_structb_a.access_stamp, 
			    l_iv_client_othserv_struct_h.access_stamp) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	} 

	if ( l_sys_ivcntlparam_struct.generate_ind == 'Y' )
	{
		CO_InsertWarning(l_debug_info_ptr, ERR_RGENBILLS_FORACCOUNT, APL_NULL_STRING, 
				 APL_NULL_STRING, APL_NULL_STRING, 
				 __LINE__, __FILE__);
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

     

	if ( (chr_l_usermode == 'I') || 
	     ((chr_l_usermode == 'M') && (chr_l_actionflag == 'I')) )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_NewOthServ(&l_iv_client_othserv_struct_h, &l_sys_ivcntlparam_struct,
						  l_iv_serv_mast_struct.std_feeind, 
						  p_intl_envdatastruct_h, &int_l_retstat, 
						  l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}	
	}
	else if ( ((chr_l_usermode == 'M') && (chr_l_actionflag == 'M')) || 
		  (chr_l_usermode == 'D') ) 
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_ChgOthServ(&l_iv_client_othserv_struct_h, &l_sys_ivcntlparam_struct,
						  p_intl_envdatastruct_h, &int_l_retstat, 
						  l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}	
	}
	else if ( chr_l_usermode == 'A' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_AuthOthServ(&l_iv_client_othserv_struct_h, 
						   &l_sys_ivcntlparam_struct, p_intl_envdatastruct_h, 
						   &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}	
	}

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_OthServMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_OthServMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
