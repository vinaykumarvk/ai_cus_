









#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 




int CR_Proc_LocChg(DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h, \
		char cseqno[17],
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b, \
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int int_error_flag = APL_SUCCESS;

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE, "Entered processtion CR_Proc_LocChg. \
			Mandatory validations will be carried out now\n",\
			NULL, p_intl_env_data_struct_h_b);
	}


	
	if (!strlen(p_dl_locnchg_struct_h->h_dl_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if ((!strlen(p_dl_locnchg_struct_h->h_sequenceno)) && (strcmp(p_intl_env_data_struct_h_b->h_mode,
					APL_FUNC_INPUT)))
	{
		APL_DATA_MISSING("Sequence No.", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(p_dl_locnchg_struct_h->h_dlt))
	{
		APL_DATA_MISSING("Trade Date", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(p_dl_locnchg_struct_h->h_setldt))
	{
		APL_DATA_MISSING("Settlement Date", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (p_dl_locnchg_struct_h->h_qty ==0)
	{
		APL_DATA_MISSING("Quantity", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(p_dl_locnchg_struct_h->h_instr_code))
	{
		APL_DATA_MISSING("Instrurity Code", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}


	
	if (!strlen(p_dl_locnchg_struct_h->h_sendmsg_ind))
	{
		APL_DATA_MISSING("Send Message Flag", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(p_dl_locnchg_struct_h->h_billable_flag))
	{
		APL_DATA_MISSING("Billable Flag", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(p_dl_locnchg_struct_h->h_setl))
	{
		APL_DATA_MISSING("Settle Flag", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	//if(strcmp(p_dl_locnchg_struct_h->h_change,"L") == APL_NULL_STRING)  /*changes by amish */
  if(strcmp(p_dl_locnchg_struct_h->h_change,"L") == 0) // AIX - Warnings
	{
		if (!strlen(p_dl_locnchg_struct_h->h_frm_loc))
		{
			APL_DATA_MISSING("From Location", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}

		
		if (!strlen(p_dl_locnchg_struct_h->h_to_location))
		{
			APL_DATA_MISSING("To Location", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
	}

	//if(strcmp(p_dl_locnchg_struct_h->h_change,"B") == APL_NULL_STRING) /*changes by amish */
	if(strcmp(p_dl_locnchg_struct_h->h_change,"B") == 0) //AIX Warning
	{
		if (!strlen(p_dl_locnchg_struct_h->h_frm_type))
		{
			APL_DATA_MISSING("From TYPE", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}

		
		if (!strlen(p_dl_locnchg_struct_h->h_to_type))
		{
			APL_DATA_MISSING("To TYPE", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
	}
	
	if ((!strlen(p_dl_locnchg_struct_h->h_access_stamp)) && (strcmp(p_intl_env_data_struct_h_b->h_mode,APL_FUNC_INPUT)))
	{
		APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

		
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered Input Mode of CR_Proc_LocChg. Validating the Data Now.\n", NULL, p_intl_env_data_struct_h_b); 
		}

		

		if(APL_FAILURE == CO_Chk_AccValid(p_dl_locnchg_struct_h->h_dl_client,\
					'Y',\
					'C',\
					'C',\
					NULL,\
					'Y',\
					'N',\
					'N',\
					'N',\
					l_debug_info_ptr))
		{
			int_error_flag = APL_FAILURE;	
		}

		 
		if (p_dl_locnchg_struct_h->h_qty < 0 )               
		{
			CO_InsertErr( l_debug_info_ptr,
					ERR_VALUE_CANT_NEGATIVE,
					"Trade Quantity",
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
		}

		

		if (APL_FAILURE == CO_Chk_InstrValid(p_dl_locnchg_struct_h->h_instr_code,
						'Y',
						'Y',
						'N',
						'N',
						NULL,
						NULL,
						l_debug_info_ptr))
		{
			int_error_flag = APL_FAILURE;
		}

		/* OPT:AIX if(strcmp(p_dl_locnchg_struct_h->h_change,"L") == APL_NULL_STRING)  changes by amish */
		if(strcmp(p_dl_locnchg_struct_h->h_change,"L") == 0)  /*changes by amish */
		{
			if (!strcmp(p_dl_locnchg_struct_h->h_frm_loc,p_dl_locnchg_struct_h->h_to_location))
			{
				CO_InsertErr( l_debug_info_ptr,
						ERR_LOCN_SAME,   	
						APL_NULL_STRING,
						APL_NULL_STRING,
						APL_NULL_STRING,
						__LINE__,
						__FILE__);

				int_error_flag = APL_FAILURE;
			}

			if (APL_FAILURE == MT_Chk_Loc(p_dl_locnchg_struct_h->h_frm_loc,
								'Y',
								'Y',
								APL_NULL_CHAR,
								l_debug_info_ptr))
					{
						int_error_flag=APL_FAILURE;
					}
							
	
	
			if (APL_FAILURE == MT_Chk_Loc(p_dl_locnchg_struct_h->h_to_location,
								'Y',
								'Y',
								APL_NULL_CHAR,
								l_debug_info_ptr))
					{
						int_error_flag=APL_FAILURE;
					}
        }
		
		
		/* OPT:AIX if(strcmp(p_dl_locnchg_struct_h->h_change,"B") == 0) changes by amish */
		if(strcmp(p_dl_locnchg_struct_h->h_change,"B") == 0)  /*changes by amish */
		{
			if (!strcmp(p_dl_locnchg_struct_h->h_frm_type,p_dl_locnchg_struct_h->h_to_type))
			{
				CO_InsertErr( l_debug_info_ptr,
						ERR_LOCN_SAME,   	
						APL_NULL_STRING,
						APL_NULL_STRING,
						APL_NULL_STRING,
						__LINE__,
						__FILE__);

				int_error_flag = APL_FAILURE;
			}
        }
	
	
							
	
	if (strstr("YN",p_dl_locnchg_struct_h->h_setl) == NULL)
	{
		
			CO_InsertErr( l_debug_info_ptr,
					ERR_INVALID_DATAVAL,   	
					"Settle Flag Invalid",
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
	}

	
	if (strstr("YN",p_dl_locnchg_struct_h->h_billable_flag) == NULL)
	{
		
			CO_InsertErr( l_debug_info_ptr,
					ERR_INVALID_DATAVAL,   	
					"Billable Flag ",
					"Invalid ",
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
	}

	
	if (strstr("YN",p_dl_locnchg_struct_h->h_sendmsg_ind) == NULL)
	{
		
			CO_InsertErr( l_debug_info_ptr,
					ERR_INVALID_DATAVAL,   	
					"Send Message Flag ",
					" Invalid ",
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
	}

		
  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}

	

	if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered Input Mode of CBUpdLocchgfn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		if(APL_FAILURE == CR_Mod_LocChg(p_dl_locnchg_struct_h, cseqno, p_intl_env_data_struct_h_b, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	
	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered Modify Mode of CBUpdLocchgfn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		if(APL_FAILURE == CR_Mod_LocChg(p_dl_locnchg_struct_h, cseqno, p_intl_env_data_struct_h_b, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

 

	

	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered Delete Mode of CBUpdLocchgfn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		if(APL_FAILURE == CR_Mod_LocChg(p_dl_locnchg_struct_h, cseqno, p_intl_env_data_struct_h_b, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

 

	

	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_AUTHORISE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorise h_mode of CBUpdLocchgfn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		if(APL_FAILURE == CR_Mod_LocChg(p_dl_locnchg_struct_h, cseqno, p_intl_env_data_struct_h_b, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}

			APL_GOBACK_SUCCESS;
	}

	else
		{
		APL_GOBACK_FAIL
		}

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :

		{

		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Success in CBUpdLocchgfn. Quitting program.\n" , NULL, p_intl_env_data_struct_h_b);

			}
		return(APL_SUCCESS);
		}

	RETURN_FAILURE :

		{
		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Failed in CR_Proc_LocChg. Quitting Program. \n", NULL, p_intl_env_data_struct_h_b);
			}
		return(APL_FAILURE); // AIX - Warnigs Removal
		}

}




int CR_Proc_LocChgInitTrd(SYS_DL_DEAL_STRUCT_H *l_sys_dl_deal_struct_hl,
							DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h_a,
							char p_cdealcode[3],
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
		char chr_sys_access_stamp[APL_DATE_LEN], p_dt[APL_DATE_LEN]; 
		short int_l_cond = 0;

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered CR_Proc_LocChgInitTrd.\n", NULL, NULL); 
		}

		strcpy(l_sys_dl_deal_struct_hl->h_dl_client, p_dl_locnchg_struct_h_a->h_dl_client); 
		if(!strcmp(p_cdealcode, "DF"))
				strcpy(l_sys_dl_deal_struct_hl->h_indentity_no, p_dl_locnchg_struct_h_a->h_df_txnr_iden);
		else
				strcpy(l_sys_dl_deal_struct_hl->h_indentity_no, p_dl_locnchg_struct_h_a->h_rf_dl_ident);

		strcpy(l_sys_dl_deal_struct_hl->h_dlt, p_dl_locnchg_struct_h_a->h_dlt); 
		strcpy(l_sys_dl_deal_struct_hl->h_setldt, p_dl_locnchg_struct_h_a->h_setldt); 

		l_sys_dl_deal_struct_hl->h_qty = p_dl_locnchg_struct_h_a->h_qty; 
		strcpy(l_sys_dl_deal_struct_hl->h_domcpclt_cd, l_mt_core_sys_params_struct_h.custody_clt_cd); 
		strcpy(l_sys_dl_deal_struct_hl->h_isspotdl, "N"); 
		l_sys_dl_deal_struct_hl->h_origquantity = p_dl_locnchg_struct_h_a->h_qty; 

		strcpy(l_sys_dl_deal_struct_hl->h_dlfromord, "N"); 
		strcpy(l_sys_dl_deal_struct_hl->h_entry, "G"); 
		strcpy(l_sys_dl_deal_struct_hl->h_reapired_ind, "N"); 
		strcpy(l_sys_dl_deal_struct_hl->h_domcp_custodyclt, l_mt_core_sys_params_struct_h.custody_clt_cd); 
		strcpy(l_sys_dl_deal_struct_hl->h_countclt, APL_NULL_STRING); 
		if(CO_Rtv_FldValChar("CLN_NAME", "MT_CLIENT", "CLN_CODE",
							/* OPT:AIX l_mt_core_sys_params_struct_h.custody_clt_cd, */
							(char *)l_mt_core_sys_params_struct_h.custody_clt_cd, 
							l_sys_dl_deal_struct_hl->h_countcltnm,
							l_debug_info_ptr) == APL_FAILURE)
		{
			APL_GOBACK_FAIL;
		}
		strcpy(l_sys_dl_deal_struct_hl->h_clientof, APL_NULL_STRING); 
		strcpy(l_sys_dl_deal_struct_hl->h_fx_reqd, "N");  
		strcpy(l_sys_dl_deal_struct_hl->h_ispymtlocal, "Y");

		strcpy(l_sys_dl_deal_struct_hl->h_reginstr_ind, "Y");
		strcpy(l_sys_dl_deal_struct_hl->h_ispart_, "N"); 

		

		if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_LOCNCHG",
															"LOCREFNO_NULL",
															&int_l_cond,
															l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (!int_l_cond)
		{
			strcpy(l_sys_dl_deal_struct_hl->h_locindentity_no, l_sys_dl_deal_struct_hl->h_indentity_no); 
		}
		else
		{
			strcpy(l_sys_dl_deal_struct_hl->h_locindentity_no, APL_NULL_STRING); 
		}

		if(!strcmp(p_cdealcode, "DF"))
		{
			l_sys_dl_deal_struct_hl->h_dealcd[0] = DEALCD_DF; 
			strcpy(l_sys_dl_deal_struct_hl->h_loccode, p_dl_locnchg_struct_h_a->h_frm_loc);
		}
		else
		{
			l_sys_dl_deal_struct_hl->h_dealcd[0] = DEALCD_RF; 
			strcpy(l_sys_dl_deal_struct_hl->h_loccode, p_dl_locnchg_struct_h_a->h_to_location);
		}

		strcpy(l_sys_dl_deal_struct_hl->h_instr_code, p_dl_locnchg_struct_h_a->h_instr_code); 
		strcpy(l_sys_dl_deal_struct_hl->h_origindentity_no,l_sys_dl_deal_struct_hl->h_indentity_no); 
		strcpy(l_sys_dl_deal_struct_hl->h_maker, p_dl_locnchg_struct_h_a->h_checker); 
		strcpy(l_sys_dl_deal_struct_hl->h_checker, p_dl_locnchg_struct_h_a->h_checker); 
		strcpy(l_sys_dl_deal_struct_hl->h_info1, p_dl_locnchg_struct_h_a->h_infos);
		strcpy(l_sys_dl_deal_struct_hl->h_instrconv_ind, "N");
		strcpy(l_sys_dl_deal_struct_hl->h_clt_reqdel_flag, "N"); 

	if (CO_RtvSysDtTime(chr_sys_access_stamp, l_debug_info_ptr) != APL_SUCCESS) 
		{ 
			APL_GOBACK_FAIL 
		} 
	 
	strcpy(l_sys_dl_deal_struct_hl->h_access_stamp, chr_sys_access_stamp);
	strcpy(l_sys_dl_deal_struct_hl->h_maker_dt, chr_sys_access_stamp);
	strcpy(l_sys_dl_deal_struct_hl->h_checker_dt, chr_sys_access_stamp);

	if (CO_RtvSysDt(p_dt, l_debug_info_ptr) != APL_SUCCESS) 
		{ 
			APL_GOBACK_FAIL 
		} 
	 

	 
	if(CR_Proc_LocChgPosStat(l_sys_dl_deal_struct_hl, p_dl_locnchg_struct_h_a->h_instr_code, l_debug_info_ptr) 
							!= APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}
	
	if(!strcmp(p_cdealcode, "DF"))
	{
		if(CR_Chk_LocChgTrdStat(l_sys_dl_deal_struct_hl, p_dl_locnchg_struct_h_a, p_dt, l_debug_info_ptr)
				!= APL_SUCCESS)
		{
			APL_GOBACK_FAIL;
		}
	}
	else
	{
		if(!strcmp(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_CONF))
		{
			strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_dt);
			strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_CONF);
		}
		else if(!strcmp(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_SETL))
		{
			strcpy(l_sys_dl_deal_struct_hl->h_instrdate,p_dt);
			strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_dt);
			strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_SETL);
		}
	}

	if(!strcmp(p_dl_locnchg_struct_h_a->h_billable_flag,"N"))
	{
		strcpy(l_sys_dl_deal_struct_hl->h_classofdl,NONBILLDEAL);
		if(!strcmp(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_SETL))
		{
			strcpy(l_sys_dl_deal_struct_hl->h_candropdate, p_dt);
		}
	}
	else
		strcpy(l_sys_dl_deal_struct_hl->h_classofdl,NORMALDEAL);

	RETURN_SUCCESS :

		{

		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Success in CR_Proc_LocChgInitTrd. Quitting program.\n" , NULL, NULL);

			}
		return(APL_SUCCESS);
		}
	APL_GOBACK_SUCCESS;

	RETURN_FAILURE :

		{
		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Failed in CR_Proc_LocChgInitTrd. Quitting Program. \n", NULL, NULL);
			}
		return(APL_FAILURE); // AIX - Warnings Removal
		}
	}




int CR_Chk_LocChgTrdStat(SYS_DL_DEAL_STRUCT_H *l_sys_dl_deal_struct_hl, 
						DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h_a, 
						char *p_ctodays_date, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	char chr_p_from_manifold[2], chr_p_to_manifold[2];
	double p_avail_sett_posn;
	int int_p_enuf_vdp_posn, int_p_diff;

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered CR_Chk_LocChgTrdStat.\n", NULL, NULL); 
		}


	if(!strcmp(p_dl_locnchg_struct_h_a->h_setl ,"N")) 
	{
		if(DL_Chk_VDPPos(p_dl_locnchg_struct_h_a->h_dl_client,
							 p_dl_locnchg_struct_h_a->h_instr_code,
							 p_dl_locnchg_struct_h_a->h_frm_loc,
							 l_sys_dl_deal_struct_hl->h_pos_stat,
							 p_dl_locnchg_struct_h_a->h_qty,
							 p_ctodays_date,
							 &int_p_enuf_vdp_posn,
							 l_debug_info_ptr
							 ) == APL_FAILURE)
		{
			APL_GOBACK_FAIL;
		}
		if(int_p_enuf_vdp_posn == APL_SUCCESS)
		{
			strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_ctodays_date);
			strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_CONF);
			strcpy(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_CONF);
			APL_GOBACK_SUCCESS;
		}
	}

	
	
	if(!strcmp(p_dl_locnchg_struct_h_a->h_setl,"Y"))
	{
		
		if(CO_Rtv_FldValChar("manifld_ind", "mt_location", "location_cd",
							p_dl_locnchg_struct_h_a->h_frm_loc, chr_p_from_manifold,
							l_debug_info_ptr) == APL_FAILURE)
		{
			APL_GOBACK_FAIL;
		}
		if(CO_Rtv_FldValChar("manifld_ind", "mt_location", "location_cd",
							p_dl_locnchg_struct_h_a->h_to_location, chr_p_to_manifold,
							l_debug_info_ptr) == APL_FAILURE)
		{
			APL_GOBACK_FAIL;
		}
		
		if(!strcmp(chr_p_from_manifold,"N") && !strcmp(chr_p_to_manifold,"N"))
		{
		
			if(strcmp(p_dl_locnchg_struct_h_a->h_change,"L")==0)
			{	
				if(DL_Proc_PosCalc(p_dl_locnchg_struct_h_a->h_dl_client,
								  p_dl_locnchg_struct_h_a->h_instr_code,
								  p_dl_locnchg_struct_h_a->h_frm_loc,
								  APL_NULL_STRING,
								  APL_NULL_STRING,
								  APL_NULL_STRING,
								  &p_avail_sett_posn,"FREE",
								  l_debug_info_ptr)==APL_FAILURE)			
				{
					APL_GOBACK_FAIL;
				}
			}
			
			

			if(p_dl_locnchg_struct_h_a->h_qty <= p_avail_sett_posn)
			{
				if(CO_Pro_DateComp(p_dl_locnchg_struct_h_a->h_setldt, p_ctodays_date, &int_p_diff,
						l_debug_info_ptr) == APL_FAILURE)
				{
						APL_GOBACK_FAIL;
				}
				
				if(int_p_diff >= 0)
				{
					strcpy(l_sys_dl_deal_struct_hl->h_instrdate, p_ctodays_date);
					strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_ctodays_date);
					strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_SETL);
					strcpy(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_SETL);
					APL_GOBACK_SUCCESS;
				}
				
					strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_ctodays_date);
					strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_CONF);
					strcpy(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_CONF);
					APL_GOBACK_SUCCESS;
			}
		   if(strcmp(p_dl_locnchg_struct_h_a->h_change,"L")==0) //chgs by amish
			{
				if(DL_Chk_VDPPos(p_dl_locnchg_struct_h_a->h_dl_client,
							 p_dl_locnchg_struct_h_a->h_instr_code,
							 p_dl_locnchg_struct_h_a->h_frm_loc,
							 APL_NULL_STRING,
							 p_dl_locnchg_struct_h_a->h_qty,
							 p_ctodays_date,
							 &int_p_enuf_vdp_posn,
							 l_debug_info_ptr
							 ) == APL_FAILURE)
				{
					APL_GOBACK_FAIL;
				}
			}
			if(int_p_enuf_vdp_posn == APL_SUCCESS)
			{
				strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_ctodays_date);
				strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_CONF);
				strcpy(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_CONF);
				APL_GOBACK_SUCCESS;
			}
		}
		else
		{
	      if(strcmp(p_dl_locnchg_struct_h_a->h_change,"L")==0)
			{	
				if(DL_Chk_VDPPos(p_dl_locnchg_struct_h_a->h_dl_client,
							 p_dl_locnchg_struct_h_a->h_instr_code,
							 p_dl_locnchg_struct_h_a->h_frm_loc,
							 APL_NULL_STRING,
							 p_dl_locnchg_struct_h_a->h_qty,
							 p_ctodays_date,
							 &int_p_enuf_vdp_posn,
							 l_debug_info_ptr
							 ) == APL_FAILURE)
				{
				APL_GOBACK_FAIL;
				}
			}
			if(int_p_enuf_vdp_posn == APL_SUCCESS)
			{
				strcpy(l_sys_dl_deal_struct_hl->h_confdate, p_ctodays_date);
				strcpy(l_sys_dl_deal_struct_hl->h_deal_status, STATUS_CONF);
				strcpy(p_dl_locnchg_struct_h_a->h_dealstat, STATUS_CONF);
				APL_GOBACK_SUCCESS;
			}
		}
	}
	APL_GOBACK_SUCCESS;

	RETURN_SUCCESS :

		{

		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Success in CR_Chk_LocChgTrdStat. Quitting program.\n" , NULL, NULL);

			}
		return(APL_SUCCESS);
		}

	RETURN_FAILURE :

		{
		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Failed in CR_Chk_LocChgTrdStat. Quitting Program. \n", NULL, NULL);
			}
		return(APL_FAILURE); // AIX - Warnings Removal
		}
}
