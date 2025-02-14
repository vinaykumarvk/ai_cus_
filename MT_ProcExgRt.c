












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int CR_Mod_ExgRt (MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int int_error_flag = APL_SUCCESS;



APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_ExgRt. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  if ((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT)) || (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY)))
	 {
  if (!strlen(p_mt_exchrate_struct_h->h_denom_currencycode)) {APL_DATA_MISSING("Denom Currency Code",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_exchrate_struct_h->h_currencycode)) {APL_DATA_MISSING("Currency Code",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_exchrate_struct_h->h_rtdt)) {APL_DATA_MISSING("Exchange Rate Date",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
  if (0 ==p_mt_exchrate_struct_h->h_exchgrt) {APL_DATA_MISSING("Exchange Rate",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
	 }


  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(p_mt_exchrate_struct_h->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_exchrate_struct_h->h_status)) {APL_DATA_MISSING("Status",APL_NULL_STRING,APL_NULL_STRING)
	int_error_flag = APL_FAILURE;}
 	}



  if (int_error_flag == APL_FAILURE)
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Exiting CR_Mod_ExgRt. Mandatory Data Missing\n",
		NULL,p_intl_envdatastruct_h);
 }

	APL_GOBACK_FAIL
	}

if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   {
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Error on entering the CR_Mod_ExgRt. Exiting\n",
		NULL,p_intl_envdatastruct_h);
 }

	//fprintf(APL_OUT_FILE, "");  commented for AIX - Warnings Removal
   APL_GOBACK_FAIL
   }



  if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Input Mode of CR_Mod_ExgRt. Going for currency validations\n",
		NULL,p_intl_envdatastruct_h);
 }

  	if (APL_SUCCESS ==  CO_Chk_CcyValid(p_mt_exchrate_struct_h->h_currencycode,'M','Y',
					l_debug_info_ptr))
        	{ 
  		if (APL_SUCCESS ==  CO_Chk_CcyValid(p_mt_exchrate_struct_h->h_denom_currencycode,
						'M','Y',l_debug_info_ptr))
	   		{
	   		CR_Mod_DBExgRt(p_mt_exchrate_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   				{
   				APL_GOBACK_FAIL
   				}
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Success in Input\n",
		NULL,p_intl_envdatastruct_h);
 }
			}
		}
	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   		APL_GOBACK_FAIL
   		}
	}
 				

  else if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Modify Mode of CR_Mod_ExgRt. Going for check of existence of exchange rate\n",
		NULL,p_intl_envdatastruct_h);
 }
	if (APL_SUCCESS == MT_Chk_ExgRt(p_mt_exchrate_struct_h->h_currencycode,
					p_mt_exchrate_struct_h->h_denom_currencycode,
					p_mt_exchrate_struct_h->h_rtdt,'Y',NULL,
					l_debug_info_ptr))
	   {
	    CR_Mod_DBExgRt(p_mt_exchrate_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
	   }
	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   		APL_GOBACK_FAIL
   		}
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Success in Modifying the exchange rate \n",
		NULL,p_intl_envdatastruct_h);
 }
	}
       	
  else if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, 
"Entered Authorise Mode of CR_Mod_ExgRt. Going for check of existence of exchange rate & if the user can authorise\n",
		NULL,p_intl_envdatastruct_h);
 }

	

   	if (APL_SUCCESS == MT_Chk_ExgRt(p_mt_exchrate_struct_h->h_currencycode,
					p_mt_exchrate_struct_h->h_denom_currencycode,
					p_mt_exchrate_struct_h->h_rtdt,
					'Y','N',l_debug_info_ptr))
           {
	   if (APL_SUCCESS == CR_Chk_ExgRtMkrChkr(p_mt_exchrate_struct_h->h_currencycode,
						p_mt_exchrate_struct_h->h_denom_currencycode,
						p_mt_exchrate_struct_h->h_rtdt,
						p_intl_envdatastruct_h->usr,l_debug_info_ptr)) 
		{
		CR_Mod_DBExgRt(p_mt_exchrate_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
	      	}
	    if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   		APL_GOBACK_FAIL
   		}
            }
       if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   		APL_GOBACK_FAIL
   		}
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Success in Authorizing the exchange rate \n",
		NULL,p_intl_envdatastruct_h);
 }
	}

  APL_GOBACK_SUCCESS
  RETURN_SUCCESS :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Update successful. chucking out of CR_Mod_DBExgRt\n",
		NULL,p_intl_envdatastruct_h);
 }
	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Update failed. chucking out of CR_Mod_DBExgRt\n",
		NULL,p_intl_envdatastruct_h);
 }

	//	fprintf(APL_OUT_FILE, ""); commented for AIX-warnings removal
	return(APL_FAILURE);
	}

} 
