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
 * Module Name         :	
 *
 * File Name           :
 *
 * Description         :	
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *					
 *
 *********************************************************************/

   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CR_Header_C.h>

#define S_DATE_LENGTH		11



int MT_Mod_Sec(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval;
	short							int_l_condexists;
	char							chr_l_field_val[40];
	DEAL_ORD_STRUCT_H	*l_deal_ord_struct_h = NULL;
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	char							chr_l_sys_date[S_DATE_LENGTH];
	int							int_l_diff;
	char							chr_iexist,chr_ideleted,chr_ifrozen;
	char							chr_l_row_id_sec[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
	int 							int_l_holiday_flg = 0;		


	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_Sec \n",NULL,p_intl_env_data_struct_h_d);

	memset(chr_l_row_id_sec,APL_NULL_CHAR,sizeof(chr_l_row_id_sec));

	if (strlen(p_mt_instrument_struct_h_a->h_securitycd) == 0)
		APL_DATA_MISSING("SECURITY CODE",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_currencycode) == 0)
		APL_DATA_MISSING("CURRENCY CODE",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strcmp(l_mt_core_sys_params_struct_h.loc_proc_ind,"Y") == 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_loccode) == 0)
			APL_DATA_MISSING("LOCATION CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (p_mt_instrument_struct_h_a->h_nominal_val <= 0)
		CO_InsertErr(l_debug_info_ptr,ERR_VAL_SHLDBERR_POS,"NOMINAL_VAL",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	if (strlen(p_mt_instrument_struct_h_a->h_regbrflag) == 0)
		APL_DATA_MISSING("REG/BR",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_mother_sec_ind) == 0)
		APL_DATA_MISSING("MOTHER SECURITY FLG",APL_NULL_STRING,APL_NULL_STRING)
	if (strlen(p_mt_instrument_struct_h_a->h_ex_arena) == 0)
		APL_DATA_MISSING("EX_ARENA",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_listed_ind) == 0)
		APL_DATA_MISSING("LISTED FLAG",APL_NULL_STRING,APL_NULL_STRING)
	
	if (p_mt_instrument_struct_h_a->h_threshold_qty < 0)
		CO_InsertErr(l_debug_info_ptr,ERR_VALUE_CANT_NEGATIVE,"THRESHOLD_QTY",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
		if (strlen(p_mt_instrument_struct_h_a->h_timestamp) == 0)
			APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
	if (p_mt_instrument_struct_h_a->h_total_pdcapital < 0)
		CO_InsertErr(l_debug_info_ptr,ERR_VALUE_CANT_NEGATIVE,"TOTAL_PDCAPITAL",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	if (strlen(p_mt_instrument_struct_h_a->h_new_issue) == 0)
		APL_DATA_MISSING("NEW ISSUE",APL_NULL_STRING,APL_NULL_STRING)



	strcpy(chr_mainfuncarea,"SEC_MAINT");
	strcpy(chr_l_condid,"CHK_CLSCODE_FOR_GR");
	
	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_classcd) == 0)
			APL_DATA_MISSING("INVESTMENT GROUP CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	strcpy(chr_mainfuncarea,"SEC_MAINT");
	strcpy(chr_l_condid,"BOG_CODE");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if(int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_cmp_code) == 0)
			APL_DATA_MISSING("BOG CODE",APL_NULL_STRING,APL_NULL_STRING)
		
		else if (strlen(p_mt_instrument_struct_h_a->h_cmp_code) != 5)
			CO_InsertErr(l_debug_info_ptr,ERR_BOGCODE_EQL5CHAR,p_mt_instrument_struct_h_a->h_cmp_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	}



	strcpy(chr_mainfuncarea, "SEC_MAINT");
	strcpy(chr_l_condid, "CERTOFOWNFLG_FOR_EG");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_cert_of_own_flag) == 0)
			APL_DATA_MISSING("CERT_OF_OWN_IND",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (strlen(p_mt_instrument_struct_h_a->h_secdetail) == 0)
		APL_DATA_MISSING("SECURITY DESC",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_sec_isin) == 0)
		APL_DATA_MISSING("SEC_ISIN",APL_NULL_STRING,APL_NULL_STRING)
	else if (strlen(p_mt_instrument_struct_h_a->h_sec_isin) < 12)
		CO_InsertErr(l_debug_info_ptr,ERR_ISINCD_CANT_LESS_12CHAR,p_mt_instrument_struct_h_a->h_sec_isin,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	if (strlen(p_mt_instrument_struct_h_a->h_tipo_inv) == 0)
		APL_DATA_MISSING("TIPO_INV",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_typeofsec) == 0)
		APL_DATA_MISSING("SECURITY_TYPE",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_prodateype) == 0)
		APL_DATA_MISSING("PROD_CLASS",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_instrument_struct_h_a->h_secdealcd) == 0)
		APL_DATA_MISSING("SECTOR CODE",APL_NULL_STRING,APL_NULL_STRING)




	
	strcpy(chr_mainfuncarea, "SEC_MAINT");
	strcpy(chr_l_condid, "CLASSCD");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_classcd) == 0)
			APL_DATA_MISSING("CLASSCD",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if ((strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_WARRANTS) != 0))
	{
		if (p_mt_instrument_struct_h_a->h_lst_inc_rate < 0)
			CO_InsertErr(l_debug_info_ptr,ERR_VALUE_CANT_NEGATIVE,"LAST INCOME RATE",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
	
		if (((strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_FMT) == 0)) &&
			 (strcmp(p_mt_instrument_struct_h_a->h_disct_flag,"N") == 0))
		{ 
			if (p_mt_instrument_struct_h_a->h_inc_rate <= 0)
				CO_InsertErr(l_debug_info_ptr,ERR_VAL_SHLDBERR_POS,"EARNINGS_RATE",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	if ((strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_WARRANTS) != 0))
	{
		if ((strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_FMT) == 0))
	   {
			if (strlen(p_mt_instrument_struct_h_a->h_disct_flag) == 0)
				APL_DATA_MISSING("DISCT_IND",APL_NULL_STRING,APL_NULL_STRING)
			if (strlen(p_mt_instrument_struct_h_a->h_issue_date) == 0)
				APL_DATA_MISSING("ISSUE DT",APL_NULL_STRING,APL_NULL_STRING)

			if (strlen(p_mt_instrument_struct_h_a->h_mature_date) == 0)
				APL_DATA_MISSING("MATURE DT ",APL_NULL_STRING,APL_NULL_STRING)
		}
		
		if (strlen(p_mt_instrument_struct_h_a->h_ca_addrdet) == 0)
			APL_DATA_MISSING("CA_ADDRDET",APL_NULL_STRING,APL_NULL_STRING)

		if (strlen(p_mt_instrument_struct_h_a->h_ca_clr_name) == 0)
			APL_DATA_MISSING("CA_NAME",APL_NULL_STRING,APL_NULL_STRING)

	}


	
	if (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_BOND) == 0 )
	{
		 
       int_l_condexists = 0;
       strcpy(chr_mainfuncarea, "SEC_MAINT");
       strcpy(chr_l_condid, "LST_PAY_DT_ENB");

       int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
       if (int_retval != APL_SUCCESS)
           APL_GOBACK_FAIL

       if (!int_l_condexists)
         {	
		 		if (strlen(p_mt_instrument_struct_h_a->h_lst_pymt_dt) == 0)
					APL_DATA_MISSING("LAST_PAY_DATE",APL_NULL_STRING,APL_NULL_STRING)
			}
	}
		

	if (strcmp(p_mt_instrument_struct_h_a->h_mother_sec_ind,"N") == 0)
	{
		if (strlen(p_mt_instrument_struct_h_a->h_parent_sec) == 0)
			APL_DATA_MISSING("PARENT_SEC",APL_NULL_STRING,APL_NULL_STRING)
	}


	if ((strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_WARRANTS) != 0))
	{
		if ((strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_FMT) == 0))
		{
			if (strcmp(p_mt_instrument_struct_h_a->h_disct_flag,"N") == 0)
			{
				if (strlen(p_mt_instrument_struct_h_a->h_interest_class) == 0)
					APL_DATA_MISSING("INTEREST_TYPE",APL_NULL_STRING,APL_NULL_STRING)
				if (strlen(p_mt_instrument_struct_h_a->h_frq_code) == 0)
					APL_DATA_MISSING("FREQ_CODE",APL_NULL_STRING,APL_NULL_STRING)
				if (strlen(p_mt_instrument_struct_h_a->h_int_clttyp) == 0)
					APL_DATA_MISSING("CLT_CLASS",APL_NULL_STRING,APL_NULL_STRING)
				if (strlen(p_mt_instrument_struct_h_a->h_nxt_pymt_dt) == 0)
					APL_DATA_MISSING("NEXT PAY DT",APL_NULL_STRING,APL_NULL_STRING)
			}
	
			if (strcmp(p_mt_instrument_struct_h_a->h_disct_flag,"Y") == 0)
			{
				if (strlen(p_mt_instrument_struct_h_a->h_taxonmat_ind) == 0)
					APL_DATA_MISSING("TAXONMAT_IND",APL_NULL_STRING,APL_NULL_STRING)
			}
		}
	}
		
     
  strcpy(chr_mainfuncarea,"SEC_MAINT");
  strcpy(chr_l_condid,"MIN_DENOM_DISABLE");

  int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
  if (int_retval != APL_SUCCESS)
     APL_GOBACK_FAIL

  if (int_l_condexists == 0)
  {
	if (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_FMT) == 0)
	{
		if (p_mt_instrument_struct_h_a->h_minfmtdlquantity <= 0)
			CO_InsertErr(l_debug_info_ptr,ERR_VAL_SHLDBERR_POS,"MIN_FMT_DL_QTY",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
	}
  }
	
	if (strcmp(l_mt_core_sys_params_struct_h.no_stxdl_ind,"N") == 0)
	{
		if (strcmp(p_mt_instrument_struct_h_a->h_ex_arena,EX_ARENA_STX) != 0)
			CO_InsertErr(l_debug_info_ptr,ERR_INVALID_ARGUMENT,"EX_ARENA",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
	}
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if ((strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && (strcmp(p_mt_instrument_struct_h_a->h_typeofsec,APL_INSTRU_WARRANTS) != 0))
	{
		if (strlen(p_mt_instrument_struct_h_a->h_issue_date) != 0)
		{
			if (CO_Pro_DateComp(chr_l_sys_date,p_mt_instrument_struct_h_a->h_issue_date,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL

			if (int_l_diff > 0)
				CO_InsertErr(l_debug_info_ptr,ERR_DATE_CANT_GRT_TODAY,"ISSUE DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}

		if ((strlen(p_mt_instrument_struct_h_a->h_issue_date) != 0) && (strlen(p_mt_instrument_struct_h_a->h_lst_pymt_dt) != 0))
		{
			if (CO_Pro_DateComp(p_mt_instrument_struct_h_a->h_lst_pymt_dt,p_mt_instrument_struct_h_a->h_issue_date,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL

			if (int_l_diff > 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ISSUEDT_CANT_GRTR_LASTPAYDT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	
		if ((strlen(p_mt_instrument_struct_h_a->h_nxt_pymt_dt) != 0) && (strlen(p_mt_instrument_struct_h_a->h_lst_pymt_dt) != 0))
		{
			if (CO_Pro_DateComp(p_mt_instrument_struct_h_a->h_lst_pymt_dt,p_mt_instrument_struct_h_a->h_nxt_pymt_dt,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL

			if (int_l_diff <= 0)
				CO_InsertErr(l_debug_info_ptr,ERR_LASTPAYDT_CANT_GRTR_NXTPAYDT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}

		if ((strlen(p_mt_instrument_struct_h_a->h_mature_date) != 0) && (strlen(p_mt_instrument_struct_h_a->h_issue_date) != 0))
		{
			if (CO_Pro_DateComp(p_mt_instrument_struct_h_a->h_mature_date,p_mt_instrument_struct_h_a->h_issue_date,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL

			if (int_l_diff > 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ISSUEDT_CANT_GRTR_MATURITYDT,"ISSUE DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	
		if (strlen(p_mt_instrument_struct_h_a->h_lst_pymt_dt) != 0)
		{
		
		}
	
		if ((strlen(p_mt_instrument_struct_h_a->h_issue_date) != 0) && (strlen(p_mt_instrument_struct_h_a->h_nxt_pymt_dt) != 0))
		{
			if (CO_Pro_DateComp(p_mt_instrument_struct_h_a->h_issue_date,p_mt_instrument_struct_h_a->h_nxt_pymt_dt,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL
	
			if (int_l_diff < 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ISSUEDT_CANT_GRTR_NXTPAYDT,"NEXT PAY DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	
		if ((strlen(p_mt_instrument_struct_h_a->h_mature_date) != 0) && (strlen(p_mt_instrument_struct_h_a->h_nxt_pymt_dt) != 0))
		{
			if (CO_Pro_DateComp(p_mt_instrument_struct_h_a->h_mature_date,p_mt_instrument_struct_h_a->h_nxt_pymt_dt,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
				APL_GOBACK_FAIL
	
			if (int_l_diff > 0)
				CO_InsertErr(l_debug_info_ptr,ERR_SEC_NXTPYDT_CANT_GRTR_MATURITYDT,"NEXT PAY DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}

	
	if ( strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind, "Y") == 0 ) 
	{
		if (strcmp(p_mt_instrument_struct_h_a->h_ipo_ind,"Y") == 0)
		{
			if (strlen(p_mt_instrument_struct_h_a->h_ipo_valid_date) == 0)
			{
				APL_DATA_MISSING("IPO VALID DATE", APL_NULL_STRING, APL_NULL_STRING)
			}
			else
			{
				int_l_holiday_flg = 0;

				if (CO_Chk_Holiday(p_mt_instrument_struct_h_a->h_ipo_valid_date, &int_l_holiday_flg, l_debug_info_ptr,APL_NULL_STRING) == APL_FAILURE)
				{
					APL_GOBACK_FAIL
				}
				
				if ( int_l_holiday_flg )
				{
					CO_InsertWarning(l_debug_info_ptr, ERR_DATE_IS_HOLIDAY, "IPO Valid Date", APL_NULL_STRING, APL_NULL_STRING, __LINE__,  __FILE__);
				}
				
				if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

				if (strlen(p_mt_instrument_struct_h_a->h_ipo_valid_date) != 0)
				{
					if (CO_Pro_DateComp(chr_l_sys_date, p_mt_instrument_struct_h_a->h_ipo_valid_date, &int_l_diff, l_debug_info_ptr) != APL_SUCCESS)
						APL_GOBACK_FAIL

					if (int_l_diff <= 0)
						CO_InsertErr(l_debug_info_ptr, ERR_DATE_CANT_LESS_TODAY, "IPO VALID DATE", APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__);
				}
			}
		}
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	strcpy(p_mt_instrument_struct_h_a->h_chng_lst_flag,APL_NULL_STRING);
	
	strcpy(p_mt_instrument_struct_h_a->h_chgsec_isin,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h_a->h_chgcreater,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h_a->h_chng_cd,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h_a->h_oldlstpydate,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h_a->h_updlstpydate,APL_NULL_STRING);
	
	if (strcmp(p_mt_instrument_struct_h_a->h_mother_sec_ind,"Y") == 0)
		strcpy(p_mt_instrument_struct_h_a->h_parent_sec,APL_NULL_STRING);

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Security is %s \n",p_mt_instrument_struct_h_a->h_securitycd);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
	}
	
	if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
	{
		chr_iexist = 'N';

		int_retval = CO_Chk_SecValid(p_mt_instrument_struct_h_a->h_securitycd,chr_iexist,NULL,NULL,NULL,NULL,NULL,l_debug_info_ptr);

	}
	else if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
	{
		
		int_retval = CR_Rtv_SecChrVal(p_mt_instrument_struct_h_a->h_securitycd,"ROWID",chr_l_field_val,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		strcpy(chr_l_row_id_sec,chr_l_field_val);

		
		int_retval = CR_Rtv_SecChrVal(p_mt_instrument_struct_h_a->h_securitycd,"access_stamp",chr_l_field_val,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if (strcmp(chr_l_field_val,p_mt_instrument_struct_h_a->h_timestamp) != 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}

		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_SecValid(p_mt_instrument_struct_h_a->h_securitycd,chr_iexist,NULL,chr_ideleted,chr_ifrozen,NULL,NULL,l_debug_info_ptr);

	}

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Chk_SecDet(p_mt_instrument_struct_h_a,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	

	l_deal_ord_struct_h = (DEAL_ORD_STRUCT_H *)calloc(1,sizeof(DEAL_ORD_STRUCT_H));
	APL_MALLOC_FAIL(l_deal_ord_struct_h)

	int_retval = MT_Rtv_DLOrdFldVal(p_mt_instrument_struct_h_a->h_classcd,l_deal_ord_struct_h,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	

	strcpy(p_mt_instrument_struct_h_a->h_allow_rf,l_deal_ord_struct_h->h_allow_rf);
	strcpy(p_mt_instrument_struct_h_a->h_allow_rvp,l_deal_ord_struct_h->h_allow_rvp);
	strcpy(p_mt_instrument_struct_h_a->h_allow_df,l_deal_ord_struct_h->h_allow_df);
	strcpy(p_mt_instrument_struct_h_a->h_allow_dvp,l_deal_ord_struct_h->h_allow_dvp);
	strcpy(p_mt_instrument_struct_h_a->h_order_class,l_deal_ord_struct_h->h_order_class);
	int_retval = CR_Mod_Sec(p_mt_instrument_struct_h_a,chr_l_row_id_sec,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_FREE(l_deal_ord_struct_h)
		
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_Sec \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_Sec \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}




 int MT_Mod_SecOth(char *p_sec_code,char *p_sec_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	short							int_l_condexists;
	char							chr_l_field_val[40];
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	DEAL_ORD_STRUCT_H	*l_deal_ord_struct_h = NULL;
	char							chr_iexist,chr_iauthorised,chr_ideleted,chr_ifrozen;
	char							chr_l_row_id_sec[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_SecOth \n",NULL,p_intl_env_data_struct_h_d);

	memset(chr_l_row_id_sec,APL_NULL_CHAR,sizeof(chr_l_row_id_sec));

	if (strlen(p_sec_code) == 0)
		APL_DATA_MISSING("SECURITY CODE",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_sec_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Security Code is %s \n",p_sec_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h_d->usr);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Country Code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	}

	
	int_retval = CR_Rtv_SecChrVal(p_sec_code,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_sec,chr_l_field_val);
	
	
	int_retval = CR_Rtv_SecChrVal(p_sec_code,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,p_sec_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_DELETE) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_SecValid(p_sec_code,chr_iexist,NULL,chr_ideleted,chr_ifrozen,NULL,NULL,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	
		

		int_retval = CR_Rtv_SecChrVal(p_sec_code,"tiposec",chr_l_field_val,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
		
		if ((strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && (strcmp(chr_l_field_val,APL_INSTRU_WARRANTS) != 0))
		{
			int_retval = CR_Chk_SecEvent(p_sec_code,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
			{
				CO_InsertErr(l_debug_info_ptr,ERR_EVNTEXIST_CANT_DEL,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}

		if (strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0)
		{
			int_retval = CR_Chk_SecOrd(p_sec_code,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
				CO_InsertErr(l_debug_info_ptr,ERR_ORDEXIST_CANT_DEL_SEC,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}
		
		int_retval = CR_Chk_ChldSec(p_sec_code,l_debug_info_ptr);

		if (int_retval == APL_SUCCESS)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_CHILDSECEXIST_CANTDEL_SEC,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		
		int_retval = CR_Chk_SecTrd(p_sec_code,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_TRDEXIST_CANT_DEL_SEC,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecPos(p_sec_code,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_PYMNTTRDEXIST_CANT_DEL_SEC,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		strcpy(chr_mainfuncarea, "SEC_MAINT");
		strcpy(chr_l_condid, "SEC_IN_LRSFK_CANTDEL");

		int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if (int_l_condexists > 0)
		{
			int_retval = CR_Chk_SecLRRpt(p_sec_code,l_debug_info_ptr);
			if (int_retval == APL_RECS_EXIST)
			{
				CO_InsertErr(l_debug_info_ptr,ERR_LOCALREP_POSN_EXIST_CANTDEL_SEC,p_sec_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"AEVENTIMG",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Event Image Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"ALOGAUTOEVNT",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Log AutoEvnt Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"ARIGHTSPRO",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"RightsProcessing Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"AALERT",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Alert Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"CDLYMKTPRC",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"DlyMarketPrice Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"ABACKSETL",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"BackDatedSettlement Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"CLOCNCHG",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Location Change Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL

		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"CMISTXN",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Missing Txns",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_SecCodeUnique(p_sec_code,"CTRDACCIMG",p_intl_env_data_struct_h_d,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_SECEXIST_CANTDEL,"Acct Entries Recs",p_sec_code,APL_NULL_STRING,__LINE__,__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
	}

	if ((strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_RESET) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_AUTHORISE) == 0))
	{
		chr_iexist ='Y';
		chr_iauthorised = 'N';

		int_retval = CO_Chk_SecValid(p_sec_code,chr_iexist,chr_iauthorised,NULL,NULL,NULL,NULL,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		int_retval = CR_Chk_SecMkrChkr(p_sec_code,p_intl_env_data_struct_h_d->usr,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_FREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_SecValid(p_sec_code,chr_iexist,chr_iauthorised,chr_ideleted,chr_ifrozen,NULL,NULL,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_UNFREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'Y';
	
		int_retval = CO_Chk_SecValid(p_sec_code,chr_iexist,NULL,chr_ideleted,chr_ifrozen,NULL,NULL,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	

	l_deal_ord_struct_h = (DEAL_ORD_STRUCT_H *)calloc(1,sizeof(DEAL_ORD_STRUCT_H));
	APL_MALLOC_FAIL(l_deal_ord_struct_h)
	
	int_retval = CR_Rtv_SecChrVal(p_sec_code,"clscode",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = MT_Rtv_DLOrdFldVal(chr_l_field_val,l_deal_ord_struct_h,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Mod_SecDet(p_sec_code,chr_l_row_id_sec,l_deal_ord_struct_h,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_SecOth \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_SecOth \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}



int MT_Rtv_DLOrdFldVal(char *p_cls_code,DEAL_ORD_STRUCT_H *p_deal_ord_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	char				chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char				chr_l_condid[APL_CONDID_LEN];
	short				int_l_condexists;
	int				int_retval;
	char				chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		if (strlen(p_cls_code) != 0)
		{
			memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
			sprintf(chr_l_buf,"Classification h_code is %s \n",p_cls_code);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
		}
	}
	
	strcpy(p_deal_ord_struct_h->h_allow_rf,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_rvp,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_df,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_dvp,"Y");
	strcpy(p_deal_ord_struct_h->h_order_class,"A");
	
	strcpy(chr_mainfuncarea, "SEC_MAINT");
	strcpy(chr_l_condid, "ORDER_TYPE_FOR_RU");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_cls_code, "MIN") == 0)
		{
			strcpy(p_deal_ord_struct_h->h_allow_dvp,"N");
			strcpy(p_deal_ord_struct_h->h_allow_rvp,"N");
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
		}
	}
	memset(chr_mainfuncarea,NULL,APL_MAINFUNCAREA_LEN);
	memset(chr_l_condid,NULL,APL_CONDID_LEN);
	int_l_condexists = 0;

	strcpy(chr_mainfuncarea, "TRADE_MAINT");
	strcpy(chr_l_condid, "NTRD_NODLT");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
      if (strcmp(p_cls_code, "NTRD") == 0)
      {
         strcpy(p_deal_ord_struct_h->h_allow_df,"N");
			strcpy(p_deal_ord_struct_h->h_allow_dvp,"N");
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
		}
   }	
	memset(chr_mainfuncarea,NULL,APL_MAINFUNCAREA_LEN);
   memset(chr_l_condid,NULL,APL_CONDID_LEN);
   int_l_condexists = 0;

	strcpy(chr_mainfuncarea, "SEC_MAINT");
	strcpy(chr_l_condid, "ORDER_TYPE_FOR_TR");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_cls_code, "HS") != 0)
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
	}
	
	APL_GOBACK_SUCCESS	

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		return(APL_FAILURE);
	}
}
