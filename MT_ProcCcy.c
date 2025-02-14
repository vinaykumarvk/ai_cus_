

   
   
   
   
   
   
   
   
   
   
   
   





#define PURE_C_SOURCE
#include "CO_HostStructdef.h"





int CR_Mod_Ccy( DL_CURRENCY_STRUCT_H   *p_dl_currency_struct_h,
                INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
                DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
				  )
{

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entering processtion CBUpdCcyFn",NULL,p_intl_env_data_struct_h_e);
	}





	if(!strlen(p_dl_currency_struct_h->h_currencycode))
   APL_DATA_MISSING("Currency", APL_NULL_STRING, APL_NULL_STRING)

   if(!strlen(p_dl_currency_struct_h->h_ccydetail))
   APL_DATA_MISSING("Currency Description", APL_NULL_STRING, APL_NULL_STRING)

   if(!strlen(p_dl_currency_struct_h->h_gl_cd))
   APL_DATA_MISSING("IBBS Code", APL_NULL_STRING, APL_NULL_STRING)


   if(strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_INPUT))
	{
     	if(!strlen(p_dl_currency_struct_h->h_access_stamp))
      APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, APL_NULL_STRING)
	}

 	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	APL_GOBACK_FAIL







	if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_INPUT))
   {
			if (APL_SUCCESS == CO_Chk_CcyValid(p_dl_currency_struct_h->h_currencycode,'M','N',l_debug_info_ptr))
			{
				CR_Mod_DBCcy(p_dl_currency_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
				if (!strcmp(p_dl_currency_struct_h->h_currencycode, g_mt_commonsys_params_struct_h.dom_ccy))
				{
					if (APL_FAILURE == CR_Mod_ExgRtNew(p_intl_env_data_struct_h_e, l_debug_info_ptr))
					{
						APL_GOBACK_FAIL
					}
				}
			}
			else if(APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}
	}

	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_MODIFY))
	{
			if (APL_SUCCESS == CO_Chk_CcyValid(p_dl_currency_struct_h->h_currencycode,'M','Y',l_debug_info_ptr))
			{
				CR_Mod_DBCcy(p_dl_currency_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
			else if(APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}
	}

	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_DELETE))
	{
			if (APL_SUCCESS == CO_Chk_CcyValid(p_dl_currency_struct_h->h_currencycode,'M','Y',l_debug_info_ptr))
			{
				if (APL_SUCCESS == CR_Chk_CanCCYDel(p_dl_currency_struct_h->h_currencycode, l_debug_info_ptr))
				{
					CR_Mod_DBCcy(p_dl_currency_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
				}
			}

         else if(APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr))
			{
              APL_GOBACK_FAIL
			}
    }






   if(APL_FAILURE == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_SUCCESS
   else APL_GOBACK_FAIL


   RETURN_SUCCESS :
   {
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion CR_Mod_Ccy successfully",NULL,p_intl_env_data_struct_h_e);
		}
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion CR_Mod_Ccy with failure",NULL,p_intl_env_data_struct_h_e);
		}
      return(APL_FAILURE);
   }

}



int CR_Mod_ExgRtNew(	INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	
	MT_EXCHRATE_STRUCT_H l_mt_exchrate_struct_h;
	INTL_ENV_DATA_STRUCT_H l_intl_env_data_h;
	char	chr_l_today[APL_DATE_LEN]	= APL_NULL_STRING;
	char	chr_l_acc_st[APL_DATE_LEN]	= APL_NULL_STRING;

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entering processtion CBInsExrFn",NULL,p_intl_envdatastruct_h);
	}

	memset(&l_mt_exchrate_struct_h, NULL, sizeof(MT_EXCHRATE_STRUCT_H));
	memset(&l_intl_env_data_h, NULL, sizeof(INTL_ENV_DATA_STRUCT_H));

	

	if (APL_FAILURE == CO_RtvSysDt(chr_l_today, l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}

	

	strcpy(l_mt_exchrate_struct_h.h_currencycode, g_mt_commonsys_params_struct_h.dom_ccy);
	strcpy(l_mt_exchrate_struct_h.h_denom_currencycode, g_mt_commonsys_params_struct_h.dom_ccy);
	strcpy(l_mt_exchrate_struct_h.h_rtdt, chr_l_today);
	l_mt_exchrate_struct_h.h_exchgrt = 1.0;
	l_mt_exchrate_struct_h.h_rate_buy = 1.0;
	l_mt_exchrate_struct_h.h_sellae_rate = 1.0;
	strcpy(l_mt_exchrate_struct_h.h_status, STATUS_UAUTH);/*Smita - Changed h_exchg_stat to h_status - HDFCCA_Base Version*/


	

	strcpy(l_intl_env_data_h.usr, p_intl_envdatastruct_h->usr);
	strcpy(l_intl_env_data_h.h_mode, APL_FUNC_INPUT);
	strcpy(l_intl_env_data_h.processtion, "EXCHANGERATE MAINTENANCE");
	strcpy(l_intl_env_data_h.auth_req, p_intl_envdatastruct_h->auth_req);
	strcpy(l_intl_env_data_h.subprocess, APL_NULL_STRING);
	strcpy(l_intl_env_data_h.h_process, APL_NULL_STRING);

	

	if (APL_FAILURE == CR_Mod_ExgRt(	&l_mt_exchrate_struct_h,
												&l_intl_env_data_h,
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (APL_FAILURE == CR_Rtv_ExgRtAccStamp(	chr_l_acc_st,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	strcpy(l_mt_exchrate_struct_h.h_status, STATUS_AUTH);/*Smita - Changed h_exchg_stat to h_status -HDFCCA_BaseVer*/
	strcpy(l_mt_exchrate_struct_h.h_access_stamp, chr_l_acc_st);

	

	strcpy(l_intl_env_data_h.usr, "SYSTEM");
	strcpy(l_intl_env_data_h.h_mode, APL_FUNC_AUTHORISE);
	strcpy(l_intl_env_data_h.processtion, "EXCHANGERATE MAINTENANCE");
	strcpy(l_intl_env_data_h.auth_req, p_intl_envdatastruct_h->auth_req);
	strcpy(l_intl_env_data_h.subprocess, APL_NULL_STRING);
	strcpy(l_intl_env_data_h.h_process, APL_NULL_STRING);

	

	if (APL_FAILURE == CR_Mod_ExgRt(	&l_mt_exchrate_struct_h,
												&l_intl_env_data_h,
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion CR_Mod_ExgRtNew successfully",NULL,p_intl_envdatastruct_h);
		}
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion CR_Mod_ExgRtNew with failure",NULL,p_intl_envdatastruct_h);
		}
      return(APL_FAILURE);
   }

}

