

   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include "CO_HostStructdef.h"





int MT_Mod_WTaxRt(MT_WHTRATE_STRUCT_H    *p_mt_whtrate_struct_h,
               INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
               DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
				  )
{

   APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entering processtion CBUpdWtrFn",NULL,p_intl_env_data_struct_h_e);
	}



	

	if(!strlen(p_mt_whtrate_struct_h->h_nationcode))
   APL_DATA_MISSING("Country Code", APL_NULL_STRING, APL_NULL_STRING)

   if(!strlen(p_mt_whtrate_struct_h->h_prodateype))
   APL_DATA_MISSING("Product Type", APL_NULL_STRING, APL_NULL_STRING)


   if(strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_INPUT))
	{
     	if(!strlen(p_mt_whtrate_struct_h->h_access_stamp))
      APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, APL_NULL_STRING)
	}

 	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	APL_GOBACK_FAIL







	if(strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_DELETE))
	{
		if ((p_mt_whtrate_struct_h->h_custodytaxrt < 0.0) || (p_mt_whtrate_struct_h->h_custodytaxrt > 100.000))
		{
			 CO_InsertErr(
								l_debug_info_ptr,
								ERR_WHT_SHLD_BETN_0_AND_100,   
								p_mt_whtrate_struct_h->h_nationcode,
								p_mt_whtrate_struct_h->h_prodateype,
								APL_NULL_STRING,
								__LINE__,
								__FILE__
								);

			APL_GOBACK_FAIL
		}
	}


	if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_INPUT))
   {
			if (APL_SUCCESS == MT_Chk_WHTax(p_mt_whtrate_struct_h->h_nationcode,p_mt_whtrate_struct_h->h_prodateype,'N',l_debug_info_ptr))
			{
				MT_Mod_DBWTaxRt(p_mt_whtrate_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
	}

	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_MODIFY))
	{
			if (APL_SUCCESS == MT_Chk_WHTax(p_mt_whtrate_struct_h->h_nationcode,p_mt_whtrate_struct_h->h_prodateype,'Y',l_debug_info_ptr))
			{
				MT_Mod_DBWTaxRt(p_mt_whtrate_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
	}

	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_DELETE))
	{
			if (APL_SUCCESS == MT_Chk_WHTax(p_mt_whtrate_struct_h->h_nationcode,p_mt_whtrate_struct_h->h_prodateype,'Y',l_debug_info_ptr))
			{
				MT_Mod_DBWTaxRt(p_mt_whtrate_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
    }

	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_AUTHORISE))
	{
			if (APL_SUCCESS == MT_Chk_WHTax(p_mt_whtrate_struct_h->h_nationcode,p_mt_whtrate_struct_h->h_prodateype,'Y',l_debug_info_ptr))
			{
				MT_Mod_DBWTaxRt(p_mt_whtrate_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
    }
	else if(!strcmp(p_intl_env_data_struct_h_e->h_mode,APL_FUNC_RESET))
	{
			if (APL_SUCCESS == MT_Chk_WHTax(p_mt_whtrate_struct_h->h_nationcode,p_mt_whtrate_struct_h->h_prodateype,'Y',l_debug_info_ptr))
			{
				MT_Mod_DBWTaxRt(p_mt_whtrate_struct_h, p_intl_env_data_struct_h_e, l_debug_info_ptr);
			}
    }






   if(APL_FAILURE == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_SUCCESS
   else APL_GOBACK_FAIL


   RETURN_SUCCESS :
   {
   	APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion MT_Mod_WTaxRt successfully",NULL,p_intl_env_data_struct_h_e);
		}
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
   	APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting processtion MT_Mod_WTaxRt with failure",NULL,p_intl_env_data_struct_h_e);
		}
      return(APL_FAILURE);
   }

}

