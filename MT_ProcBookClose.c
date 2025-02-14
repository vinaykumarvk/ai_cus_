







#define PURE_C_SOURCE
#include "CO_HostStructdef.h"



int CR_Proc_BkClose(	BCL_TRF_STRUCT_H *p_bcl_trf_struct_h,
					INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{

	

	char		chr_l_buf[BUFFER_LEN]					= APL_NULL_STRING;
	char		chr_l_canregflg[APL_FLAG_LENGTH]		= APL_NULL_STRING;
	char		chr_l_regbrind_a[REG_BR_IND_LEN]		= APL_NULL_STRING;

	int		int_l_error_flag						= APL_SUCCESS;

	short		l_iflag								= 0;

	double	l_av_quantity								= 0.0;

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE, 
						"Entered Function CR_Proc_BkClose\n",
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Account is : %s\n", 
						p_bcl_trf_struct_h->h_dl_client);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Instrurity Code is : %s\n", 
						p_bcl_trf_struct_h->h_instr_code);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LOcation Code is : %s\n", 
						p_bcl_trf_struct_h->h_loccode);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Qty of Instrurities is : %f\n", 
						p_bcl_trf_struct_h->h_qty);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The SI chr_flag is : %s\n", 
						p_bcl_trf_struct_h->h_bclreg_ind);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LocRefNo for RECEIVE_FREE is : %s\n", 
						p_bcl_trf_struct_h->h_locindentity_no_rf);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LocRefNo for DELV_FREE is : %s\n", 
						p_bcl_trf_struct_h->h_locindentity_no_df);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
	}

	
	

	if (!strlen(p_bcl_trf_struct_h->h_dl_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_bcl_trf_struct_h->h_instr_code))
	{
		APL_DATA_MISSING("Instrode", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	if ((l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y') &&
		 (!strlen(p_bcl_trf_struct_h->h_loccode)))
	{
		APL_DATA_MISSING("Locncode", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	}
		
	if (!p_bcl_trf_struct_h->h_qty)
	{
		APL_DATA_MISSING("Qty Of Instrs.", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_LOCREFNO",
														"LOCREFNO_NOT_NULL",
														&l_iflag,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if ((l_iflag) && (!strlen(p_bcl_trf_struct_h->h_locindentity_no_rf)))
	{
		APL_DATA_MISSING("LocRefNo RF", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if ((l_iflag) && (!strlen(p_bcl_trf_struct_h->h_locindentity_no_df)))
	{
		APL_DATA_MISSING("LocRefNo DF", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	if (APL_FAILURE == int_l_error_flag) APL_GOBACK_FAIL

	

	

	if (APL_FAILURE == CO_Chk_AccValid(	p_bcl_trf_struct_h->h_dl_client,
												'Y',
												'C',
												NULL,
												NULL,
												'Y',
												'N',
												'N',
												'N',
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}


	

	if (APL_FAILURE == CO_Chk_InstrValid(	p_bcl_trf_struct_h->h_instr_code,
												'Y',
												'Y',
												'N',
												'N',
												NULL,
												'N',
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
	

	if (l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y')
	{
		if (APL_FAILURE == MT_Chk_Loc(	p_bcl_trf_struct_h->h_loccode,
													'Y',
													'Y',
													'N',
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	
	
	if (APL_FAILURE == MT_Rtv_AccFldVal(	p_bcl_trf_struct_h->h_dl_client,
													"canregflg",
													chr_l_canregflg,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (chr_l_canregflg[0] == 'N')
	{
		if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_ACCOUNT_CANT_REGSTR,
														p_bcl_trf_struct_h->h_dl_client,
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ))
		{
			APL_GOBACK_FAIL
		}
		int_l_error_flag = APL_FAILURE;
	}

	

	if (APL_FAILURE == CR_Rtv_InstrChrVal(	p_bcl_trf_struct_h->h_instr_code,
													"regbrind",
													chr_l_regbrind_a,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (!strcmp(chr_l_regbrind_a, APL_INSTRU_BEAR))
	{
		if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_NOTREGDINSTR,
														p_bcl_trf_struct_h->h_instr_code,
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ))
		{
			APL_GOBACK_FAIL
		}
		int_l_error_flag = APL_FAILURE;
	}

	

	

	if (p_bcl_trf_struct_h->h_bclreg_ind[0] == REG_BCL_IND)
	{
		if (APL_FAILURE == CR_Rtv_PosRegBkCl(	p_bcl_trf_struct_h->h_dl_client,
														p_bcl_trf_struct_h->h_instr_code,
														p_bcl_trf_struct_h->h_loccode,
														&l_av_quantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}
	else
	{
		if (APL_FAILURE == CR_Rtv_PosBkCl(	p_bcl_trf_struct_h->h_dl_client,
														p_bcl_trf_struct_h->h_instr_code,
														p_bcl_trf_struct_h->h_loccode,
														&l_av_quantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	if (l_av_quantity < p_bcl_trf_struct_h->h_qty)
	{
		if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DEAL_NENUFPOSN,
														p_bcl_trf_struct_h->h_dl_client,
														p_bcl_trf_struct_h->h_instr_code,
														p_bcl_trf_struct_h->h_loccode,
														__LINE__,
														__FILE__ ))
		{
			APL_GOBACK_FAIL
		}
		int_l_error_flag = APL_FAILURE;
	}

	

	l_iflag = 0;
	if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_LOCREFNO",
														"LOCREFNO_UNIQUE",
														&l_iflag,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (l_iflag)
	{
		l_iflag = 0;
		if (APL_FAILURE == DL_Chk_LRRefTrd(	APL_NULL_STRING,
															APL_NULL_STRING,
															p_bcl_trf_struct_h->h_locindentity_no_rf,
															&l_iflag,
															l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (l_iflag)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_LOCREFNO_EXIST,
															p_bcl_trf_struct_h->h_locindentity_no_rf,
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flag = APL_FAILURE;
		}

		l_iflag = 0;
		if (APL_FAILURE == DL_Chk_LRRefTrd(	APL_NULL_STRING,
															APL_NULL_STRING,
															p_bcl_trf_struct_h->h_locindentity_no_df,
															&l_iflag,
															l_debug_info_ptr ))
		{	
			APL_GOBACK_FAIL
		}

		if (l_iflag)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_LOCREFNO_EXIST,
															p_bcl_trf_struct_h->h_locindentity_no_df,
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{	
				APL_GOBACK_FAIL
			}
			int_l_error_flag = APL_FAILURE;
		}
	}

	

	if (APL_FAILURE == int_l_error_flag) APL_GOBACK_FAIL

	if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_FAIL

	

	if (APL_FAILURE == CR_Mod_BkCl(	p_bcl_trf_struct_h,
												p_intl_envdatastruct_h,
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
	
	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CR_Proc_BkClose with success\n",
							NULL,
							NULL);
		}
      return(APL_SUCCESS);

   RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CR_Proc_BkClose with errors\n",
							NULL,
							NULL);
		}
      return(APL_FAILURE);

}

