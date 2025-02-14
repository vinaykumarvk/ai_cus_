












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int CR_Mod_Loc (MT_LOCATION_STRUCT_H *p_mt_location_struct_h_c, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  int int_error_flag = APL_SUCCESS;
  
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_Loc. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }
   if (l_mt_core_sys_params_struct_h.loc_proc_ind[0] =='N')
	{
             CO_InsertErr(
                        l_debug_info_ptr,
                        ERR_DATA_INTEGRITY,
            				
                        "Locn Not Supported",
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__
                        ) ;
                  APL_GOBACK_FAIL
	}


  if (!strlen(p_mt_location_struct_h_c->h_loccode)) {APL_DATA_MISSING("Location Code",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  
	if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT) || !strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
  if (!strlen(p_mt_location_struct_h_c->h_manifld_ind)) {APL_DATA_MISSING("Manifold Flag",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  if (0 ==p_mt_location_struct_h_c->h_locdetail) {APL_DATA_MISSING("Location Description",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}

	}

  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(p_mt_location_struct_h_c->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
 	}

  
/**** Check for Physical Flag is not required ......
  if ((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT)) || (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY)))
	{
	if (!strlen(p_mt_location_struct_h_c->h_physical_ind)) {APL_DATA_MISSING("Physical Flag",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
 	}
***********/
   

  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       {
       APL_GOBACK_FAIL
       }

  
 

  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}





  if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of CR_Mod_Loc.Going for updation\n",
		NULL,p_intl_envdatastruct_h);
 }
	CR_Mod_DBLoc(p_mt_location_struct_h_c ,p_intl_envdatastruct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       		{
       		APL_GOBACK_FAIL
       		}
	}
 				

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
	

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of CR_Mod_Loc.Going for updation after validating location\n",
		NULL,p_intl_envdatastruct_h);
 }

	   {
	    CR_Mod_DBLoc(p_mt_location_struct_h_c ,p_intl_envdatastruct_h ,l_debug_info_ptr);
	   }
  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       		{
       		APL_GOBACK_FAIL
       		}
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
	{
	

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of CR_Mod_Loc.Going for updation after validating location\n",
		NULL,p_intl_envdatastruct_h);
 }


  	if (APL_SUCCESS ==  MT_Chk_Loc(p_mt_location_struct_h_c->h_loccode,'Y',NULL,'N',l_debug_info_ptr))
	   {
	    if (APL_SUCCESS == CR_Chk_InstrAtLoc(p_mt_location_struct_h_c->h_loccode,l_debug_info_ptr))
		{
	    	if (APL_SUCCESS == CR_Chk_PosAtLoc(p_mt_location_struct_h_c->h_loccode,l_debug_info_ptr))
		   {
	    	   if (APL_SUCCESS == CR_Chk_TrdAtLoc(p_mt_location_struct_h_c->h_loccode,l_debug_info_ptr))
		   	{
	    	   	CR_Mod_DBLoc(p_mt_location_struct_h_c ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		   	}
		   else if(CO_InsertErr(
			l_debug_info_ptr,
			ERR_LOCN_CANT_DEL, 
			"Safekeeping Table",
			APL_NULL_STRING,
			APL_NULL_STRING,
			__LINE__,
			__FILE__
			) != APL_SUCCESS)
			APL_GOBACK_FAIL
			int_error_flag = APL_FAILURE;
	      	    }	
		else if(CO_InsertErr(
			l_debug_info_ptr,
			ERR_LOCN_CANT_DEL, 
			"Safekeeping Table",
			APL_NULL_STRING,
			APL_NULL_STRING,
			__LINE__,
			__FILE__
			) != APL_SUCCESS)
			APL_GOBACK_FAIL
			int_error_flag = APL_FAILURE;
	      	  }	
		else if(CO_InsertErr(
		l_debug_info_ptr,
		ERR_LOCN_CANT_DEL, 
		"Instrurities Table",
		APL_NULL_STRING,
		APL_NULL_STRING,
		__LINE__,
		__FILE__
		) != APL_SUCCESS)
		APL_GOBACK_FAIL
		int_error_flag = APL_FAILURE;
	    }

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	    {
       	    APL_GOBACK_FAIL
       	    }
	 }

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
	{

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of CR_Mod_Loc.Going for updation after validating location\n",
		NULL,p_intl_envdatastruct_h);
 }

	

  	if (APL_SUCCESS ==  MT_Chk_Loc(p_mt_location_struct_h_c->h_loccode,'Y','N',NULL,l_debug_info_ptr))
           {
	   if(APL_SUCCESS == CR_Chk_LocMkrChkr(p_mt_location_struct_h_c->h_loccode,p_intl_envdatastruct_h->usr,l_debug_info_ptr)) 
		{
		CR_Mod_DBLoc(p_mt_location_struct_h_c ,p_intl_envdatastruct_h ,l_debug_info_ptr);
	      	}
		else
  	   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	{
       	    	APL_GOBACK_FAIL
       	    	}
            }
            else
  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	    {
       	    APL_GOBACK_FAIL
       	    }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
	{

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of CR_Mod_Loc.Going for updation after validating location\n",
		NULL,p_intl_envdatastruct_h);
 }

	

  	if (APL_SUCCESS ==  MT_Chk_Loc(p_mt_location_struct_h_c->h_loccode,'Y','N',NULL,l_debug_info_ptr))
           {
	   if(APL_SUCCESS == CR_Chk_LocMkrChkr(p_mt_location_struct_h_c->h_loccode,p_intl_envdatastruct_h->usr,l_debug_info_ptr)) 
		{
		CR_Mod_DBLoc(p_mt_location_struct_h_c ,p_intl_envdatastruct_h ,l_debug_info_ptr);
	      	}
		else
  	   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	{
       	    	APL_GOBACK_FAIL
       	    	}
            }
            else
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
  CO_ProcMonitor(APL_OUT_FILE, "Success in CR_Mod_Loc.Getting out!!\n",
		NULL,p_intl_envdatastruct_h);
 }
	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Failed in CR_Mod_Loc. Chucking out!!\n",
		NULL,p_intl_envdatastruct_h);
 }
	return(APL_FAILURE);
	}

} 
