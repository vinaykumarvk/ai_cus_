






#define PURE_C_SOURCE 
#include "CO_HostStructdef.h" 


int CR_Mod_HDATStat (PRO_HDAT_STATIC_STRUCT_H *p_pro_hdat_static_struct_h_a, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  int int_error_flag = APL_SUCCESS;

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_HDATStat. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  

  if (!strlen(p_pro_hdat_static_struct_h_a->h_mem_ident)) {APL_DATA_MISSING("Member ID",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}




  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(p_pro_hdat_static_struct_h_a->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  	if (!strlen(p_pro_hdat_static_struct_h_a->h_status_ind)) {APL_DATA_MISSING("Status",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}

 	}

   

  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
        APL_GOBACK_FAIL
        }




  if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (APL_SUCCESS ==MT_Chk_HDATStatic(p_pro_hdat_static_struct_h_a->h_mem_ident,"N",APL_NULL_STRING,APL_NULL_STRING,l_debug_info_ptr))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_HDAT(p_pro_hdat_static_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}
 				

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
	

	if (APL_SUCCESS ==MT_Chk_HDATStatic(p_pro_hdat_static_struct_h_a->h_mem_ident,"Y",APL_NULL_STRING,APL_NULL_STRING,l_debug_info_ptr))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_HDAT(p_pro_hdat_static_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
	{
	

	if (APL_SUCCESS ==MT_Chk_HDATStatic(p_pro_hdat_static_struct_h_a->h_mem_ident,"Y",APL_NULL_STRING,"N",l_debug_info_ptr))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_HDAT(p_pro_hdat_static_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	 }

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
	{
	

	if (APL_SUCCESS ==MT_Chk_HDATStatic(p_pro_hdat_static_struct_h_a->h_mem_ident,"Y","N",APL_NULL_STRING,l_debug_info_ptr))
		{
		if (APL_SUCCESS ==CR_Chk_HDATMkrChkr(p_pro_hdat_static_struct_h_a->h_mem_ident,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	       	   APL_GOBACK_FAIL
	    	           }
			CR_Mod_HDAT(p_pro_hdat_static_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
			}
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
	{
	

	if (APL_SUCCESS ==MT_Chk_HDATStatic(p_pro_hdat_static_struct_h_a->h_mem_ident,"Y",APL_NULL_STRING,"Y",l_debug_info_ptr))
		{
		if (APL_SUCCESS ==CR_Chk_HDATMkrChkr(p_pro_hdat_static_struct_h_a->h_mem_ident,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	   	   APL_GOBACK_FAIL
	    	   	   }
			CR_Mod_HDAT(p_pro_hdat_static_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
			}
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

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Successfully leaving CR_Mod_HDATStat\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Mod_HDATStat unsuccessfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_FAILURE);
	}
}

 
