









#define PURE_C_SOURCE
#include "MS_Swift.h"
#include "CO_HostStructdef.h"



int DL_Proc_TrdOth(DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_c,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

	

	int 		int_l_error_flag 							= APL_SUCCESS;
	int		int_l_ival									= 0;
	int		int_l_sentflg								= 0;
  short      int_l_exist_a                          = 0;  // AIX - Warnings removal
	int	 	int_l_ruclscodechk							= 0; 
	char 		chr_l_loc_manif_flag[APL_FLAG_LENGTH] 	= APL_NULL_STRING;
	char 		chr_l_manif_delrecdt[APL_DATE_LEN] 	= APL_NULL_STRING;
	char 		chr_l_entrytype[APL_FLAG_LENGTH] 			= APL_NULL_STRING;
	char 		chr_l_transmitdt[APL_DATE_LEN] 		= APL_NULL_STRING;
	char 		chr_l_trdfromord[APL_FLAG_LENGTH] 		= APL_NULL_STRING;
	char 		chr_l_confdt[APL_DATE_LEN] 				= APL_NULL_STRING;
	char 		chr_l_conf_flag								= NULL;
	char 		chr_l_trd_locncode[APL_LOCNCODE_LENGTH] = APL_NULL_STRING;
	char 		chr_l_be_access_stamp[APL_DATE_LEN] 	= APL_NULL_STRING;
	char 		chr_l_rowid_A[APL_ROWID_LEN]			 	= APL_NULL_STRING;
	char 		int_l_domcpac[APL_CLIENT_LENGTH] 		= APL_NULL_STRING;
	char 		int_l_countacc[11] 		= APL_NULL_STRING;
	char 		chr_l_instrcode_a[APL_INSTRUMENTCODE_LEN] 			= APL_NULL_STRING;
	char 		chr_l_posn_status[STATUS_POS_LEN]	= APL_NULL_STRING;
	char 		chr_l_trcode_a[APL_FLAG_LENGTH] 				= APL_NULL_STRING;
	char 		chr_l_incdec_flag							= NULL;
	char 		chr_l_failcode_A[FAILREAS_CD_LEN]			= APL_NULL_STRING;
	char 		chr_l_trd_status[APL_STATUS_LEN] 		= APL_NULL_STRING;
	char 		chr_l_subfun[APL_SUB_FUN_LEN] 			= APL_NULL_STRING;
	char 		chr_l_ccycode[APL_CCYCODE_LEN] 		= APL_NULL_STRING;
	char     chr_l_maker[APL_USERID_LEN] 			= APL_NULL_STRING;
	char		chr_l_posn_type[4] 						= APL_NULL_STRING;
	char		chr_l_chr_flag								= NULL;
	char		chr_l_custreqddelflg[APL_FLAG_LENGTH]	= APL_NULL_STRING;
	char		chr_l_buf[BUFFER_LEN]						= APL_NULL_STRING;
	char		chr_l_settledt_a[APL_DATE_LEN]			= APL_NULL_STRING;
	char		chr_l_vdpdate_a[APL_DATE_LEN]				= APL_NULL_STRING;
	char		chr_l_msgno[MS_MSGNO_LEN]					= APL_NULL_STRING;
	char 		chr_l_countacc_typeofacc[APL_FLAG_LENGTH]	= APL_NULL_STRING;
	char		chr_l_acct_typeofacc[APL_FLAG_LENGTH]		= APL_NULL_STRING;
	char 		chr_l_main_func_area[APL_MAINFUNCAREA_LEN]	= APL_NULL_STRING;
	char		chr_l_sub_func[APL_SUB_FUN_LEN]		= APL_NULL_STRING;
	char 		chr_l_mac_date_time[APL_DATE_LEN]		= APL_NULL_STRING;
	int		int_l_exists_flg							= 0;
	short		l_locrefno_exists						= 0;
	double	l_avquantity 									= 0.0;	
	double 	l_quantity    								= 0.0;
   char		chr_param_str[201] 						= APL_NULL_STRING;  
	char     chr_l_condid[APL_CONDID_LEN] = APL_NULL_STRING; 
   short    int_l_condexists = 0;
   DL_DEAL_RSTPMT_STRUCT_H *l_dl_deal_rstpmt_struct_h;
   char     chr_l_access_stamp[APL_DATE_LEN] = APL_NULL_STRING;   
	
	double l_subfailreason_cd =0;

   int   int_p_smieligibility_flg = 0;
   char  chr_l_be_locncode[APL_LOCNCODE_LENGTH] = APL_NULL_STRING;
   char  chr_l_be_trdt[20]                   = APL_NULL_STRING;
   char  chr_l_be_typeoftrd[3]               = APL_NULL_STRING;
   char  chr_l_be_instrcode[APL_INSTRUMENTCODE_LEN]     = APL_NULL_STRING;
   char  chr_l_be_locnchng_flg[2]            = APL_NULL_STRING;
   char  chr_l_be_trade_status[3]            = APL_NULL_STRING;

   
   char     chr_l_temp_origrefno[17]             = APL_NULL_STRING;

	DL_DEALAUDIT_STRUCT_H l_dl_dealaudit_struct_h;
	char chr_l_cubk_exttrd[2]            = APL_NULL_STRING; 
   short    l_ext_trd_check = 0;
	char l_block_type[5] = APL_NULL_STRING;

	/* PJ Audit trail for CA Deals*/
	GN_AUDIT_LOG_STRUCT_H	*p_gn_audit_log_struct_h = NULL;
	CA_GN_AUDIT_LOG_STRUCT_H *p_ca_gn_audit_log_struct_h = NULL;
	char  chr_h_entity_name[100] = APL_NULL_STRING;

	

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE, "Entered Function CBUpdTrdOthFn", NULL, p_intl_envdatastruct_h);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "The Account is : %s", p_dl_deal_oth_struct_h_c->h_dl_client);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, p_intl_envdatastruct_h);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "The RefNo is   : %s", p_dl_deal_oth_struct_h_c->h_indentity_no);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, p_intl_envdatastruct_h);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "The LocRefNo is : %s", p_dl_deal_oth_struct_h_c->h_locindentity_no);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, p_intl_envdatastruct_h);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "The BrokerNo is : %s", p_dl_deal_oth_struct_h_c->h_brkrno);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, p_intl_envdatastruct_h);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "The Cust Req. Del. Flag is : %s", p_dl_deal_oth_struct_h_c->h_clt_reqdel_flag);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, p_intl_envdatastruct_h);
	}

	
	if (!strcmp(p_intl_envdatastruct_h->h_mode,BOG_SEQ_RST_MODE))
	{
		if (APL_FAILURE == DL_Proc_BOGSeqRst(p_dl_deal_oth_struct_h_c->h_locindentity_no,
									 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
		else
			APL_GOBACK_SUCCESS
	}
	
	
	
   l_dl_deal_rstpmt_struct_h = (DL_DEAL_RSTPMT_STRUCT_H *)calloc(1,sizeof(DL_DEAL_RSTPMT_STRUCT_H));
    APL_MALLOC_FAIL(l_dl_deal_rstpmt_struct_h);
	/* PJ SP */ 
	p_gn_audit_log_struct_h = (GN_AUDIT_LOG_STRUCT_H*)calloc(1,sizeof(GN_AUDIT_LOG_STRUCT_H));
	APL_MALLOC_FAIL(p_gn_audit_log_struct_h);
	p_ca_gn_audit_log_struct_h = (CA_GN_AUDIT_LOG_STRUCT_H*)calloc(1,sizeof(CA_GN_AUDIT_LOG_STRUCT_H));
	APL_MALLOC_FAIL(p_ca_gn_audit_log_struct_h);   /* PJ */

	strcpy(l_dl_deal_rstpmt_struct_h->p_ora_rowid, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_maker, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_cltstmp_cmp, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_loccode, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_status_ind, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_dt, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_orefretval, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_delrecdate, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_instrdate, APL_NULL_STRING);
	strcpy(l_dl_deal_rstpmt_struct_h->p_moneydate, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_instr_code, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_currencycode, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_posnstatus_ind, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_dealcd, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_failreas_cd, APL_NULL_STRING);
   strcpy(l_dl_deal_rstpmt_struct_h->p_dlfromord, APL_NULL_STRING);
   l_dl_deal_rstpmt_struct_h->p_quantity =0;

   

	

	if (!strlen(p_dl_deal_oth_struct_h_c->h_dl_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_dl_deal_oth_struct_h_c->h_indentity_no))
	{
		APL_DATA_MISSING("Ref No", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 


	if ((!strlen(p_dl_deal_oth_struct_h_c->h_locindentity_no))  && (!strcmp(p_intl_envdatastruct_h->h_mode, BOG_MODE)))             
	{
		APL_DATA_MISSING("Loc Ref No", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_dl_deal_oth_struct_h_c->h_access_stamp))
	{
		APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	if (APL_FAILURE == int_l_error_flag) APL_GOBACK_FAIL


	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"rowid",
													chr_l_rowid_A,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}



   if ( strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind,"Y") == 0 )
   {
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "locncode",
                                          chr_l_be_locncode,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "trdt",
                                          chr_l_be_trdt,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "typeoftrd",
                                          chr_l_be_typeoftrd,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "instr_code",
                                          chr_l_be_instrcode,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "locnchng_flg",
                                          chr_l_be_locnchng_flg,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "trade_status",
                                          chr_l_be_trade_status,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
      if (EI_Chk_SMIElg(chr_l_be_locncode,
                                chr_l_be_trdt,
                                chr_l_be_typeoftrd,
                                chr_l_be_instrcode,
                                chr_l_be_locnchng_flg,
                                chr_l_rowid_A,
                                &int_p_smieligibility_flg,
                                p_intl_envdatastruct_h,
                                l_debug_info_ptr
                                ) == APL_FAILURE)
      {
         CO_ProcMonitor(APL_OUT_FILE,"Failure from SMI_CheckSMIEligibility", NULL,p_intl_envdatastruct_h);
         APL_GOBACK_FAIL;
      }
   }

	
   if ( (int_p_smieligibility_flg) &&
		  (strcmp(chr_l_be_trade_status,"SA") == 0) &&
        (strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind,"Y") == 0) )
	;
	else
	{
	 	printf("*********** Before Tuxy Changes *********\n");//AIX - Warnings Removal
		if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"access_stamp",
														chr_l_be_access_stamp,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	 	printf("*********** Adter Tuxy Changes ********* %s %s \n", p_intl_envdatastruct_h->usr, p_intl_envdatastruct_h->h_mode);//AIX - Warnings Removal
		/**** Added by TUXY ....added user system since system means trade comes from  message ***/
		/* PJ condition added for split system authorize not to consider access stamp */
		if((strcmp(p_intl_envdatastruct_h->usr,"SYSTEM") == 0 && strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE)==0 )
				|| (strcmp(p_intl_envdatastruct_h->usr,"SYSTEM") == 0 && strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE) == 0)
				) /** Skiping check message is from **/
			printf("\n Skipping AccessStamp Check");
		else
		{
			if (strcmp(chr_l_be_access_stamp, p_dl_deal_oth_struct_h_c->h_access_stamp))
			{
				CO_InsertErr(	l_debug_info_ptr,
						ERR_ACCESSSTAMP_CHGD,
						p_dl_deal_oth_struct_h_c->h_dl_client,
						p_dl_deal_oth_struct_h_c->h_indentity_no,
						APL_NULL_STRING,
						__LINE__,
						__FILE__ );
				APL_GOBACK_FAIL
			}
		}
	}
	
/* ISKB 1023 Chirag 01-Apr-2008 */
	if(strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE) == 0 && strcmp(p_intl_envdatastruct_h->usr,"SYSTEM") == 0)
	{

			  if(APL_FAILURE == DL_Chk_Trade_Status(p_dl_deal_oth_struct_h_c->h_dl_client,
											  p_dl_deal_oth_struct_h_c->h_indentity_no,
											  l_debug_info_ptr))
			  {
						 CO_InsertErr(	l_debug_info_ptr,
											  ERR_INVALID_TRD_STATUS,
											  p_dl_deal_oth_struct_h_c->h_dl_client,
											  p_dl_deal_oth_struct_h_c->h_indentity_no,
											  APL_NULL_STRING,
											  __LINE__,
											  __FILE__ );
						 APL_GOBACK_FAIL
			  }	
	}
	
/* ISKB 1023 Chirag 01-Apr-2008 */

	if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"settledt",
													chr_l_settledt_a,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"trcode",
													chr_l_trcode_a,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}
	 
	 

	if (l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y')
	{
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"locncode",
														chr_l_trd_locncode,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		

		if (APL_FAILURE == MT_Chk_Loc(  chr_l_trd_locncode,
													'Y',
													'Y',
													NULL,
													l_debug_info_ptr ))
		{
			int_l_error_flag = APL_FAILURE;
		}
	}
	
	 

	if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"domcpac",
													int_l_domcpac,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	
	if(int_p_smieligibility_flg==0)
	{
      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                          p_dl_deal_oth_struct_h_c->h_indentity_no,
                                          "typeoftrd",
                                          chr_l_be_typeoftrd,
                                          l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
	}

	
	IF_COND_EXISTS("DL_DEAL","DOMCPAC")
	{
		if ( APL_FAILURE == CO_Chk_AccValid( int_l_domcpac,
													'Y',
													'B',
													NULL,
													NULL,
													'Y',
													'N',
													'N',
													'N',
													l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}

	}
	
      strcpy(chr_l_main_func_area, "TRD_MAINT");
      strcpy(chr_l_condid, "EXT_TRD_CNTAC_ALWD");
      l_ext_trd_check = 0;

      if ( APL_FAILURE == CO_Chk_CntryEnabled( chr_l_main_func_area,
	                                           chr_l_condid,
                                              &l_ext_trd_check,
                                              l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL
		}

	
	IF_COND_EXISTS("DL_DEAL","DOMCPAC")
	{	
	if((strcmp(l_mt_core_sys_params_struct_h.custody_clt_cd,int_l_domcpac)==0) || (l_ext_trd_check==0))
	{

		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"countacc",
														int_l_countacc,
														l_debug_info_ptr ))
		{	
			APL_GOBACK_FAIL
		}

		

		if (strlen(int_l_countacc) )
		{
			if ( APL_FAILURE == CO_Chk_AccValid( int_l_countacc,
														'Y',
														'C',
														'C',
														NULL,
														'Y',
														'N',
														'N',
														'N',
														l_debug_info_ptr ) )
			{
				int_l_error_flag = APL_FAILURE;
			}
		}
	}
	}	
	
	      

	if (!strcmp(p_intl_envdatastruct_h->h_mode, BOG_MODE))
	{
		if (APL_FAILURE == DL_Chk_DLDet(  p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													'Y',
													NULL,
													'N',
													'Y',
													NULL,
													'N',
													'N',
													NULL,
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		
		
		strcpy(chr_l_main_func_area,"BOGTXN");
		strcpy(chr_l_sub_func,"LOC");
		if (APL_FAILURE == CO_Chk_SplVal( chr_l_main_func_area, chr_l_sub_func, chr_l_trd_locncode, &int_l_exists_flg, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		else
		{
			if (int_l_exists_flg == 0)
			{
				CO_InsertErr( l_debug_info_ptr, ERR_INVALID_LOCATION, chr_l_trd_locncode, APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__);
			}
		}
		
		
		if (APL_FAILURE == DL_Chk_LRRefTrd( p_dl_deal_oth_struct_h_c->h_dl_client, p_dl_deal_oth_struct_h_c->h_indentity_no, p_dl_deal_oth_struct_h_c->h_locindentity_no, &l_locrefno_exists, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		else
		{
			if (l_locrefno_exists != 0)
			{
				CO_InsertErr( l_debug_info_ptr, ERR_BOGREFNO_CANT_EMPTY, p_dl_deal_oth_struct_h_c->h_locindentity_no, APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__);
			}
		}

		
		
		if ((chr_l_trcode_a[0] == DEALCD_RF || chr_l_trcode_a[0] == DEALCD_RVP || chr_l_trcode_a[0] == DEALCD_CR || chr_l_trcode_a[0] == DEALCD_RCR) && (!strcmp(int_l_domcpac, l_mt_core_sys_params_struct_h.custody_clt_cd)) )
		{
			CO_InsertErr( l_debug_info_ptr, ERR_DOMCP_CANT_BE_INTRNLACC, APL_NULL_STRING, APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__ );
		}
		if((strcmp(l_mt_core_sys_params_struct_h.custody_clt_cd,int_l_domcpac)==0) || (l_ext_trd_check == 0))	
		{
			if(strlen(int_l_countacc))
			{
				
				if (APL_FAILURE == MT_Rtv_AccFldVal( p_dl_deal_oth_struct_h_c->h_dl_client, "typeofacc", chr_l_acct_typeofacc, l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}

				if (APL_FAILURE == MT_Rtv_AccFldVal( int_l_countacc, "typeofacc", chr_l_countacc_typeofacc, l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}	

				
		
				if ((chr_l_trcode_a[0] == DEALCD_DF || chr_l_trcode_a[0] == DEALCD_DVP ||chr_l_trcode_a[0] == DEALCD_CD || chr_l_trcode_a[0] == DEALCD_DCD) && (!strcmp(int_l_domcpac, l_mt_core_sys_params_struct_h.custody_clt_cd)) )
					if (!strcmp(chr_l_countacc_typeofacc, chr_l_acct_typeofacc))
					{
						CO_InsertErr( l_debug_info_ptr, ERR_TYPEOFCLI_OF_ACCT_AND_CUST_SAME, APL_NULL_STRING, APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__ );
					}

			}
		}
	}

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"trdfromord",
													chr_l_trdfromord,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE))
	{
		if (APL_FAILURE == DL_Chk_DLDet(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													'Y', 
													NULL,
													'N', 
													NULL, 
													NULL,
													'N', 
													'N', 
													NULL,
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}	

		if (l_mt_core_sys_params_struct_h.manifld_print_ind[0] == 'Y')
		{
			if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
															p_dl_deal_oth_struct_h_c->h_indentity_no,
															"delrecdt",
															chr_l_manif_delrecdt,
															l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
			if (strlen(chr_l_manif_delrecdt))					
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_MANIFLD_PRINTED,
																p_dl_deal_oth_struct_h_c->h_dl_client,
																p_dl_deal_oth_struct_h_c->h_indentity_no,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ))
				{
					APL_GOBACK_FAIL
				}
				int_l_error_flag = APL_FAILURE;
			}
		}

		

		if ( strcmp( p_intl_envdatastruct_h->subprocess, ORDEXECRESET ) )
		{
			memset(chr_l_entrytype,APL_NULL_CHAR,APL_FLAG_LENGTH);
			if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
															p_dl_deal_oth_struct_h_c->h_indentity_no,
															"entrytype",
															chr_l_entrytype,
															l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
         
         if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                                             p_dl_deal_oth_struct_h_c->h_indentity_no,
                                             "origrefno",
                                             chr_l_temp_origrefno,
                                             l_debug_info_ptr ))
         {
            APL_GOBACK_FAIL
         }
			/*
			 * Commented by Amit on 21082006 
			 * To allow deletion for system generated deals
			 *
			if ( (chr_l_entrytype[0] == 'G') && !( (chr_l_trdfromord[0] == 'Y') && (strcmp(chr_l_temp_origrefno,p_dl_deal_oth_struct_h_c->h_indentity_no) == 0) )  && strcmp(p_intl_envdatastruct_h -> usr,"SYSTEM"))
				{
					if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_APL_GEN_CANTDEL,
																p_dl_deal_oth_struct_h_c->h_dl_client,
																p_dl_deal_oth_struct_h_c->h_indentity_no,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ))
					{
						APL_GOBACK_FAIL
					}
					int_l_error_flag = APL_FAILURE;
				 }
			*/
		}

		if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"transmitdt",
														chr_l_transmitdt,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_MAINT",
															"SEND_592",
															&int_l_exist_a,
															l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}


 
		if ( !(int_l_exist_a) && strlen(chr_l_transmitdt))
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_REP_TO_CLH_CANTDEL,
															p_dl_deal_oth_struct_h_c->h_dl_client,
															p_dl_deal_oth_struct_h_c->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flag = APL_FAILURE;
		}
		
		if (l_mt_core_sys_params_struct_h.ord_proc_ind[0] == 'Y')
		{
			if (chr_l_trdfromord[0] == 'Y')
			{
				if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
																p_dl_deal_oth_struct_h_c->h_indentity_no,
																"confdt",
																chr_l_confdt,
																l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}
				if (strlen(chr_l_confdt))
				{
					if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																	ERR_DEAL_NO_DEL_CONFFROMORD,
																	p_dl_deal_oth_struct_h_c->h_dl_client,
																	p_dl_deal_oth_struct_h_c->h_indentity_no,
																	APL_NULL_STRING,
																	__LINE__,
																	__FILE__ ))
					{
						APL_GOBACK_FAIL
					}
					int_l_error_flag = APL_FAILURE;
				}
			}	
		}
	}


	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET)) || (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE)))
	{
		if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET))
		{
			chr_l_chr_flag = 'Y';
		}
		else
		{
			chr_l_chr_flag = NULL;
		}

		if((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE)) 
			&& (!strcmp(p_intl_envdatastruct_h->subprocess, "ACK")) 
			&& (strcmp(g_mt_commonsys_params_struct_h.ccs_ind,"Y") == 0 ))
		{

			      if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
            			                              p_dl_deal_oth_struct_h_c->h_indentity_no,
      		         	                           "trade_status",
                        	         		         chr_l_be_trade_status,
                           			               l_debug_info_ptr ))
      			{
         			APL_GOBACK_FAIL
      			}		
				
					if((strcmp(chr_l_be_trade_status,APL_STATUS_CQ)!=0) && (strcmp(chr_l_be_trade_status,APL_STATUS_CD)!=0))
					{
						if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
																		p_dl_deal_oth_struct_h_c->h_indentity_no,
																		"failcode",
																		chr_l_failcode_A,
																		l_debug_info_ptr ))
						{
								APL_GOBACK_FAIL
						}

						

						if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
																		p_dl_deal_oth_struct_h_c->h_indentity_no,
																		"trdfromord",
																		chr_l_trdfromord,
																		l_debug_info_ptr ))
						{
							APL_GOBACK_FAIL
						}
   					

   					if (APL_FAILURE == DL_Rtv_TrdNumVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                  					                     p_dl_deal_oth_struct_h_c->h_indentity_no,
                                 					      "qty",
                                       					&l_quantity,
                                       					l_debug_info_ptr ))
   					{
      					APL_GOBACK_FAIL
   					}

						strcpy(p_intl_envdatastruct_h->processtion, "CCS Acknowledgement Received - Not Processed");
   					memset (&l_dl_dealaudit_struct_h,NULL,sizeof(DL_DEALAUDIT_STRUCT_H));
   					strcpy(l_dl_dealaudit_struct_h.h_dl_client, p_dl_deal_oth_struct_h_c->h_dl_client);
   					strcpy(l_dl_dealaudit_struct_h.h_indentity_no, p_dl_deal_oth_struct_h_c->h_indentity_no);
   					strcpy(l_dl_dealaudit_struct_h.h_trail_for, "T");
   					strcpy(l_dl_dealaudit_struct_h.h_processdetail, p_intl_envdatastruct_h->processtion);
   					strcpy(l_dl_dealaudit_struct_h.h_proc_usr, p_intl_envdatastruct_h->usr);
   					strcpy(chr_l_subfun, p_intl_envdatastruct_h->subprocess);
   					strcpy(l_dl_dealaudit_struct_h.h_fail_cd, chr_l_failcode_A);
   					l_dl_dealaudit_struct_h.h_qty = l_quantity;
   					strcpy(l_dl_dealaudit_struct_h.h_dlfromord, chr_l_trdfromord);
   					if ( APL_FAILURE == CO_RtvMachDtTime(chr_l_mac_date_time, l_debug_info_ptr) )
   					{
       					APL_GOBACK_FAIL
   					}
      				strcpy(l_dl_dealaudit_struct_h.h_logdate, chr_l_mac_date_time);
   					if (strlen(chr_l_failcode_A)!=0)
   					{
      					if (APL_FAILURE == DL_Rtv_TrdNumVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
                     					                     p_dl_deal_oth_struct_h_c->h_indentity_no,
                                    					      "subfailcode",
                                          					&l_subfailreason_cd,
                                          					l_debug_info_ptr ))
      					{
         					APL_GOBACK_FAIL
      					}

      					l_dl_dealaudit_struct_h.h_subfailreas_cd =(int)l_subfailreason_cd;
						}

   						if (APL_FAILURE == CR_Mod_CLHAudTrail(&l_dl_dealaudit_struct_h, l_debug_info_ptr))
   						{
      						APL_GOBACK_FAIL
   						}
							APL_GOBACK_SUCCESS
				}
		}
		if (APL_FAILURE == DL_Chk_DLDet(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													'Y',
													'N', 
													chr_l_chr_flag, 
													NULL, 
													NULL, 
													NULL, 
													NULL, 
													NULL,
													l_debug_info_ptr ))
		{
			int_l_error_flag = APL_FAILURE;
		}

		
		if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"maker",
														chr_l_maker,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
     
      if ((!strcmp(p_intl_envdatastruct_h->usr, chr_l_maker)) && (strcmp(p_intl_envdatastruct_h->processtion,"Trade - CCS Manual Release"))
				)
		{
			
			if ( strcmp(chr_l_maker,"SYSTEM") != 0 && strcmp(p_intl_envdatastruct_h->usr ,"SYSTEM") != 0 )
			{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_MAKER_CHECKER_SAME,
															p_dl_deal_oth_struct_h_c->h_dl_client,
															p_dl_deal_oth_struct_h_c->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flag = APL_FAILURE;
		}
	}
	}


	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, ALERT_MODE))
	{
		if (APL_FAILURE == DL_Chk_DLDet(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													'Y',
													NULL,
													'N', 
													NULL, 
													NULL, 
													NULL, 
													NULL, 
													NULL,
													l_debug_info_ptr ))
		{
			int_l_error_flag = APL_FAILURE;
		}
	}

	
	

	if (chr_l_trdfromord[0] == 'Y')
	{
		if ( APL_FAILURE == CO_Chk_AccValid(	p_dl_deal_oth_struct_h_c->h_dl_client, 
													'Y', 
													'C', 
													'B', 
													NULL, 
													'Y', 
													'N', 
													'N', 
													'N', 
													l_debug_info_ptr ) )
   	{
      	int_l_error_flag = APL_FAILURE;
   	}
	}
	else
	{
		if (APL_FAILURE == CO_Chk_AccValid( p_dl_deal_oth_struct_h_c->h_dl_client,
												  'Y',
													'C',
													NULL,
													NULL,
													'Y',
													'N',
													'N',
													'N',
													l_debug_info_ptr))
		{
			int_l_error_flag = APL_FAILURE;
		}
	}
	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"instr_code",
													chr_l_instrcode_a,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if ( APL_FAILURE == CO_Chk_InstrValid(	chr_l_instrcode_a, 
												'Y', 
												'Y', 
												'N', 
												'N', 
												NULL, 
												'N', 
												l_debug_info_ptr ) )
   {
      int_l_error_flag = APL_FAILURE;
   }
	
	

	if (APL_FAILURE == DL_Chk_TrCdInstr(  chr_l_instrcode_a,
                                       chr_l_trcode_a[0],
                                       &chr_l_chr_flag,
                                       l_debug_info_ptr ))
   {
      APL_GOBACK_FAIL
   }

   if (chr_l_chr_flag == 'N')
   {
      if (APL_FAILURE == CO_InsertErr(  l_debug_info_ptr,
                                          ERR_DEAL_DEALTYP_NVALFORINSTR_A,
                                          chr_l_instrcode_a,
                                          APL_NULL_STRING,
                                          APL_NULL_STRING,
                                          __LINE__,
                                          __FILE__ ))
      {
         APL_GOBACK_FAIL
      }
      int_l_error_flag = APL_FAILURE;
   }

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"ccycode",
													chr_l_ccycode,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if ( APL_FAILURE == CO_Chk_CcyValid(	chr_l_ccycode, 
												'M', 
												'Y', 
												l_debug_info_ptr ) )
   {
      int_l_error_flag = APL_FAILURE;
   }
	

	

	if (APL_FAILURE == int_l_error_flag) APL_GOBACK_FAIL

	if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_FAIL

	printf("RU CHECK: instr_code=(%s)\n",chr_l_instrcode_a);
	if (APL_FAILURE == DL_Proc_RstPmtSkip(chr_l_instrcode_a, &int_l_ruclscodechk , l_debug_info_ptr))
		APL_GOBACK_FAIL   
	printf("RU CHECK: int_l_ruclscodechk=(%d)\n",int_l_ruclscodechk);

	

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"posn_status",
													chr_l_posn_status,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}
		
	

	if (APL_FAILURE == DL_Rtv_TrdNumVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"qty",
													&l_quantity,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'N')
	{
		memset(chr_l_trd_locncode, NULL, 5);
	}
	if(CA_Rtv_Block_Type(  p_dl_deal_oth_struct_h_c -> h_indentity_no,
				p_dl_deal_oth_struct_h_c -> h_classofdl,
				chr_l_trcode_a,
				l_block_type,
				l_debug_info_ptr) == APL_FAILURE)
	{
			APL_GOBACK_FAIL
	}
	if (APL_FAILURE == DL_Proc_PosLock(	p_dl_deal_oth_struct_h_c->h_dl_client,
													chr_l_instrcode_a,
													chr_l_trd_locncode,
													chr_l_posn_status,l_block_type,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
			
	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"confdt",
													chr_l_confdt,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
													p_dl_deal_oth_struct_h_c->h_indentity_no,
													"trade_status",
													chr_l_trd_status,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	

	if ((strlen(chr_l_confdt)) &&
		 ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET) && (VAL_DELIVER_DEAL(chr_l_trcode_a[0]) || chr_l_trcode_a[0]=='5' || chr_l_trcode_a[0]=='7')) ||
		  (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) && (VAL_RECDEAL(chr_l_trcode_a[0]) || chr_l_trcode_a[0]=='6' || chr_l_trcode_a[0]=='8'))))
	{
		

		l_avquantity = 0;
		if (APL_FAILURE == DL_Chk_AvlPos(	p_dl_deal_oth_struct_h_c->h_dl_client,
														chr_l_instrcode_a,
														chr_l_trd_locncode,
														'Y','N','N','Y','Y','N','N','N',
														l_block_type,
														&l_avquantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (l_avquantity < l_quantity)
		{
			if( int_l_ruclscodechk==1 )   
			{
			
			}
			else
			{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_DEAL_NENUFPOSN,
									p_dl_deal_oth_struct_h_c->h_dl_client,
									p_dl_deal_oth_struct_h_c->h_indentity_no,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
			}
		}

		

		int_l_ival = 0;
		if (APL_FAILURE == CO_Pro_DateComp(	chr_l_confdt,
													chr_l_settledt_a,
													&int_l_ival,
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (int_l_ival < 0)
		{
			strcpy(chr_l_vdpdate_a, chr_l_confdt);
		}
		else
		{
			strcpy(chr_l_vdpdate_a, chr_l_settledt_a);
		}
		if (APL_FAILURE == DL_Chk_VDPPos(	p_dl_deal_oth_struct_h_c->h_dl_client,
													chr_l_instrcode_a,
													chr_l_trd_locncode,												
													chr_l_posn_status,
													l_quantity,
													chr_l_vdpdate_a,
													&int_l_ival,
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}
	
	if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_FAIL

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"failcode",
														chr_l_failcode_A,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"trdfromord",
														chr_l_trdfromord,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}


	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE)) || (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET)))
	{
		if (strlen(chr_l_confdt)) chr_l_conf_flag = 'C';
		else chr_l_conf_flag = 'U';

		if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE))
			chr_l_incdec_flag = 'D';
		else
			chr_l_incdec_flag = 'I';

		if(CA_Rtv_Block_Type(  p_dl_deal_oth_struct_h_c->h_indentity_no,
										p_dl_deal_oth_struct_h_c->h_classofdl,
										chr_l_trcode_a,
					l_block_type,
					l_debug_info_ptr) == APL_FAILURE)
		{
				APL_GOBACK_FAIL
		}

		if (APL_FAILURE == DL_Mod_Posn(	p_dl_deal_oth_struct_h_c->h_dl_client,
														chr_l_instrcode_a,
														chr_l_trd_locncode,
														chr_l_posn_status,
														chr_l_conf_flag,
														chr_l_trcode_a[0],
														&l_quantity,	
														chr_l_incdec_flag,l_block_type,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

 
         strcpy(chr_l_main_func_area, "TRD_PMT_CHK");
         strcpy(chr_l_condid, "RU_REG_CHK");
         int_l_condexists = 0;

         if ( APL_SUCCESS != CO_Chk_CntryEnabled( chr_l_main_func_area,
	                                                   chr_l_condid,
                                                &int_l_condexists,
                                                l_debug_info_ptr ) )
			{
				APL_GOBACK_FAIL
			}
         if ( int_l_condexists > 0 )
         {
				strcpy(l_dl_deal_rstpmt_struct_h->p_instr_code,chr_l_instrcode_a);
            strcpy(l_dl_deal_rstpmt_struct_h->p_loccode,chr_l_trd_locncode);
				strcpy(l_dl_deal_rstpmt_struct_h->p_dealcd,chr_l_trcode_a);
             if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
																 p_dl_deal_oth_struct_h_c->h_indentity_no,
																 "access_stamp",
																 chr_l_access_stamp,
																 l_debug_info_ptr ))
	    		 {
		   		 APL_GOBACK_FAIL
				 }
           strcpy(l_dl_deal_rstpmt_struct_h->p_cltstmp_cmp,chr_l_access_stamp);

					printf("***************************************************\n");

				if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE )  )
				{
					printf("RU :CHK Delete Mode\n");
					if (CRUDBRstPmtFn(p_dl_deal_oth_struct_h_c->h_dl_client,
										p_dl_deal_oth_struct_h_c->h_indentity_no,
										l_dl_deal_rstpmt_struct_h,
										p_dl_deal_oth_struct_h_c->h_access_stamp,
										l_debug_info_ptr
										) == APL_FAILURE)
					{	APL_GOBACK_FAIL	}
				}
				else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET )  )
				{
					printf("RU :CHK Reset Mode\n");
					if (CRUResetTradeDelFn(p_dl_deal_oth_struct_h_c->h_dl_client,
											  	p_dl_deal_oth_struct_h_c->h_indentity_no,
											  	l_dl_deal_rstpmt_struct_h,
											  	p_dl_deal_oth_struct_h_c->h_access_stamp,
											  	l_debug_info_ptr
											 	) == APL_FAILURE)
					{	APL_GOBACK_FAIL	}
				}
         }

 



	if (APL_FAILURE == DL_Mod_DLPos(	p_dl_deal_oth_struct_h_c, 
													chr_l_rowid_A,
													p_intl_envdatastruct_h,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}


	

	
	memset (&l_dl_dealaudit_struct_h,NULL,sizeof(DL_DEALAUDIT_STRUCT_H));
	strcpy(l_dl_dealaudit_struct_h.h_dl_client, p_dl_deal_oth_struct_h_c->h_dl_client);
	strcpy(l_dl_dealaudit_struct_h.h_indentity_no, p_dl_deal_oth_struct_h_c->h_indentity_no);
	strcpy(l_dl_dealaudit_struct_h.h_trail_for, "T");
	strcpy(l_dl_dealaudit_struct_h.h_processdetail, p_intl_envdatastruct_h->processtion);
	strcpy(l_dl_dealaudit_struct_h.h_proc_usr, p_intl_envdatastruct_h->usr);
	strcpy(chr_l_subfun, p_intl_envdatastruct_h->subprocess);
	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE))
	{
		if (p_dl_deal_oth_struct_h_c->h_clt_reqdel_flag[0] == 'Y')
		{
			strcpy(chr_l_subfun, CUST_DEL_IND);
		}
		else
		{
			strcpy(chr_l_subfun, USERDELETE);
		}
	}

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET))
	{
		strcpy(chr_l_subfun, RESETDELETE);
	}

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE))
	{
		if (!strcmp(chr_l_trd_status, STATUS_DEL_UAUTH))
		{
			strcpy(chr_l_subfun, AUTH_DEL_IDENT);
		}
		else
		{
			strcpy(chr_l_subfun, APL_NULL_STRING);
		}
	}
	
	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_APPROVE))
	{
		if (!strcmp(chr_l_trd_status, APL_STATUS_SMIUNAUTH))
		{
			strcpy(chr_l_subfun, AUTH_RPR_INDENT);
		}
		else
		{
			strcpy(chr_l_subfun, APL_NULL_STRING);
		}
	}

	if (!strcmp(p_intl_envdatastruct_h->h_mode, ALERT_MODE))
	{
		strcpy(chr_l_subfun, APL_NULL_STRING);
	}

	if (!strcmp(p_intl_envdatastruct_h->h_mode, BOG_MODE))   
	{
		strcpy(chr_l_subfun, APL_NULL_STRING);
	}

	strcpy(l_dl_dealaudit_struct_h.h_subprocess, chr_l_subfun);

	

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) && 
		  !strcmp(l_dl_dealaudit_struct_h.h_proc_usr, APL_USER_SYSTEM) )
	{
		if ( APL_FAILURE == CO_RtvMachDtTime(chr_l_mac_date_time, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
		strcpy(l_dl_dealaudit_struct_h.h_logdate, chr_l_mac_date_time);
	}
	else
	{
		strcpy(l_dl_dealaudit_struct_h.h_logdate, APL_NULL_STRING);
	}

	strcpy(l_dl_dealaudit_struct_h.h_fail_cd, chr_l_failcode_A);
	l_dl_dealaudit_struct_h.h_qty = l_quantity;
	strcpy(l_dl_dealaudit_struct_h.h_dlfromord, chr_l_trdfromord);
	if (strlen(chr_l_failcode_A)!=0)
	{
		if (APL_FAILURE == DL_Rtv_TrdNumVal(  p_dl_deal_oth_struct_h_c->h_dl_client,
														p_dl_deal_oth_struct_h_c->h_indentity_no,
														"subfailcode",
														&l_subfailreason_cd,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		l_dl_dealaudit_struct_h.h_subfailreas_cd =(int)l_subfailreason_cd;

	} 	
		
	
	if (APL_FAILURE == CR_Mod_CLHAudTrail(&l_dl_dealaudit_struct_h, l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}	 	

	
	/* PJ Insert into GN_AUDIT_LOG */
	if(	strcmp(p_dl_deal_oth_struct_h_c->h_classofdl,"20") == 0 
                        || strcmp(p_dl_deal_oth_struct_h_c->h_classofdl,"19") == 0 
			|| strcmp(p_dl_deal_oth_struct_h_c->h_classofdl,"18") == 0
                        || strcmp(p_dl_deal_oth_struct_h_c->h_classofdl,"17") == 0
	  )
	{
	strcpy(p_gn_audit_log_struct_h->h_userid,p_intl_envdatastruct_h->usr );
	strcpy(p_gn_audit_log_struct_h->h_rec_mode, p_intl_envdatastruct_h->h_mode);
	strcpy(chr_h_entity_name,"DL_DEAL");
	strcpy(p_gn_audit_log_struct_h->h_entity_name, chr_h_entity_name);
	strcpy(p_gn_audit_log_struct_h->h_log_time, APL_NULL_STRING);
	strcpy(p_gn_audit_log_struct_h->h_comments, "CORPORATE ACTION TRADE");
		
	strcpy(p_ca_gn_audit_log_struct_h->h_dl_client,p_dl_deal_oth_struct_h_c->h_dl_client);
	strcpy(p_ca_gn_audit_log_struct_h->h_cln_refno,p_dl_deal_oth_struct_h_c->h_indentity_no);
	/*strcpy(p_ca_gn_audit_log_struct_h->h_instr_code,p_dl_deal_oth_struct_h_c->h_instr_code); */
	strcpy(p_ca_gn_audit_log_struct_h->h_deal_cd,p_dl_deal_oth_struct_h_c->h_dealcd);
	/*p_ca_gn_audit_log_struct_h->h_qty = p_dl_deal_oth_struct_h_c->h_qty; */
	p_ca_gn_audit_log_struct_h->h_amount = p_dl_deal_oth_struct_h_c->h_amt;
	strcpy(p_ca_gn_audit_log_struct_h->h_deal_date,p_dl_deal_oth_struct_h_c->h_dlt);
	strcpy(p_ca_gn_audit_log_struct_h->h_setl_date,p_dl_deal_oth_struct_h_c->h_setldt);
	
		if ( APL_FAILURE ==  CA_InsAudLog( 	p_gn_audit_log_struct_h, p_ca_gn_audit_log_struct_h,
				l_debug_info_ptr) ) 
		{
			APL_GOBACK_FAIL;
		}
	}

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE))
	{
	

         if (APL_FAILURE==EI_Mod_MQData(p_dl_deal_oth_struct_h_c->h_dl_client,
                                        p_dl_deal_oth_struct_h_c->h_indentity_no,
                                        NULL,
                                        NULL,
                                        "B",
                                         l_debug_info_ptr))
                     APL_GOBACK_FAIL


		if (!strcmp(chr_l_trd_status, STATUS_DEL_UAUTH) || 
			 !strcmp(chr_l_trd_status, STATUS_SMI_DELUAUTH) ||
			 !strcmp(chr_l_trd_status, STATUS_SMI_DELAUTH)   )
		{
			if (APL_FAILURE == DL_Rtv_TrdChrVal(	p_dl_deal_oth_struct_h_c->h_dl_client,
															p_dl_deal_oth_struct_h_c->h_indentity_no,
															"custreqddelflg",
															chr_l_custreqddelflg,
															l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
			
			/**if (chr_l_custreqddelflg[0] == 'Y')
			{**/
				
				memset(chr_param_str,APL_NULL_CHAR,201);
            if ( APL_FAILURE == GBDbInsIMSGENT( MS_MSGNO_596P,
                                                p_dl_deal_oth_struct_h_c->h_indentity_no,
                                                p_dl_deal_oth_struct_h_c->h_dl_client,
																'Y',
																chr_param_str,
                                                l_debug_info_ptr ) )
            {
               APL_GOBACK_FAIL;
            }
			/**}**/


			
              

			if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_MAINT",
																"SEND_592",
																&int_l_exist_a,
																l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}

			if(int_l_exist_a)
			{
				if (strlen(chr_l_confdt))
				{


        

         

					strcpy(chr_l_msgno,MS_MSGNO_52X);

		

				if (APL_FAILURE == MS_Chk_MsgAlrdySent(	chr_l_msgno,
																p_dl_deal_oth_struct_h_c->h_indentity_no,
																p_dl_deal_oth_struct_h_c->h_dl_client,
																LOCK_REC_IND,
																&int_l_sentflg,
																l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}

				
				
				 if (int_l_sentflg == SENT_IND && chr_l_custreqddelflg[0] == 'Y' )
				{
					if (APL_FAILURE == GBDbInsIMSGENT(	MS_MSGNO_592,
																	p_dl_deal_oth_struct_h_c->h_indentity_no,
																	p_dl_deal_oth_struct_h_c->h_dl_client,
																	'Y',
																	APL_NULL_STRING,
																	l_debug_info_ptr ))
					{
						APL_GOBACK_FAIL
					}
				}

	 
			}
			}
				if (APL_FAILURE == CR_Proc_MvToHisTrd(	p_dl_deal_oth_struct_h_c->h_dl_client,
																p_dl_deal_oth_struct_h_c->h_indentity_no,
																l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}
			
		}
	}
	
	
	APL_GOBACK_SUCCESS


	

   RETURN_SUCCESS :
	free(l_dl_deal_rstpmt_struct_h);
	free(p_gn_audit_log_struct_h);
	free(p_ca_gn_audit_log_struct_h);
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,
						"Leaving Function DL_Proc_TrdOth successfully",
						NULL,
						p_intl_envdatastruct_h);
      return(APL_SUCCESS);

   RETURN_FAILURE :
	free(l_dl_deal_rstpmt_struct_h);
	free(p_gn_audit_log_struct_h);
	free(p_ca_gn_audit_log_struct_h);
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,
						"Leaving Function DL_Proc_TrdOth with errors",
						NULL,
						p_intl_envdatastruct_h);
      return(APL_FAILURE);

}

