














#define PURE_C_SOURCE 
#include "CO_HostStructdef.h" 


int CR_Mod_Hol (MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  int int_error_flag = APL_SUCCESS;

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_Hol. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  

  if (!strlen(p_mt_holiday_struct_h_a->h_holi_dt)) {APL_DATA_MISSING("Holiday Date",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_holiday_struct_h_a->h_holi_class)) {APL_DATA_MISSING("Holiday Type",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_holiday_struct_h_a->h_h_reas)) {APL_DATA_MISSING("Holiday Reason",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}




  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(p_mt_holiday_struct_h_a->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
		/*Smita - Changed h_stat to h_status - HDFCCA_Base Version*/
  	if (!strlen(p_mt_holiday_struct_h_a->h_status)) {APL_DATA_MISSING("Status",APL_NULL_STRING,APL_NULL_STRING);
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
	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a->h_holi_dt,"N",APL_NULL_STRING,APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_DBHol(p_mt_holiday_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}
 				

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
	

	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a->h_holi_dt,"Y",APL_NULL_STRING,APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_DBHol(p_mt_holiday_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
	{
	

	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a->h_holi_dt,"Y",APL_NULL_STRING,"N",l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
		{
        	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   {
     	   	   APL_GOBACK_FAIL
	    	   }
		CR_Mod_DBHol(p_mt_holiday_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	 }

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
	{
	

	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	       	   APL_GOBACK_FAIL
	    	           }
			CR_Mod_DBHol(p_mt_holiday_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
			}
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
	{
	

	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a->h_holi_dt,"Y",APL_NULL_STRING,"Y",l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a->h_exch_code))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	   	   APL_GOBACK_FAIL
	    	   	   }
			CR_Mod_DBHol(p_mt_holiday_struct_h_a ,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
  CO_ProcMonitor(APL_OUT_FILE, "Successfully leaving CR_Mod_Hol\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Mod_Hol unsuccessfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_FAILURE);
	}
}

 
int CR_Mod_WklyHol (MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a_b, MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_h, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  int int_error_flag = APL_SUCCESS;

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_WklyHol. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  

  if (!strlen(p_mt_holiday_struct_h_a_b->h_holi_dt)) {APL_DATA_MISSING("Holiday Date",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_holiday_struct_h_a_b->h_holi_class)) {APL_DATA_MISSING("Holiday Type",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_holiday_struct_h_a_b->h_h_reas)) {APL_DATA_MISSING("Holiday Reason",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}




  
  if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
  {
    if (!strlen(p_mt_holiday_struct_h_h->h_holi_class)) {APL_DATA_MISSING("Holiday Type",APL_NULL_STRING,APL_NULL_STRING);
     int_error_flag = APL_FAILURE;}
    if (!strlen(p_mt_holiday_struct_h_h->h_h_reas)) {APL_DATA_MISSING("Holiday Reason",APL_NULL_STRING,APL_NULL_STRING);
  	  int_error_flag = APL_FAILURE;}
  }







  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(p_mt_holiday_struct_h_a_b->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  	if (!strlen(p_mt_holiday_struct_h_a_b->h_status)) {APL_DATA_MISSING("Status",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}


			

  if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
  {
	if (!strlen(p_mt_holiday_struct_h_h->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  if (!strlen(p_mt_holiday_struct_h_h->h_status)) {APL_DATA_MISSING("Status",APL_NULL_STRING,APL_NULL_STRING);
  	int_error_flag = APL_FAILURE;}
  }



 	}

   

  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}




  if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	    {
     	    APL_GOBACK_FAIL
	    }
   
   if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
   {
   	CR_Mod_DBWklyHol(p_mt_holiday_struct_h_a_b, p_mt_holiday_struct_h_h, p_intl_envdatastruct_h, l_debug_info_ptr);
   }
   else
   {
		CR_Mod_WklyHolSngl(p_mt_holiday_struct_h_a_b, p_intl_envdatastruct_h, l_debug_info_ptr);
   }
   
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

/*added BY AMISH  05/05*/
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
	{
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	    {
     	    APL_GOBACK_FAIL
	    }

      	CR_Mod_DBWklyHol(p_mt_holiday_struct_h_a_b, p_mt_holiday_struct_h_h, p_intl_envdatastruct_h, l_debug_info_ptr);
//   if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
//   {
//   	CR_Mod_DBWklyHol(p_mt_holiday_struct_h_a_b, p_mt_holiday_struct_h_h, p_intl_envdatastruct_h, l_debug_info_ptr);
//   }
//   else
//   {
//		CR_Mod_WklyHolSngl(p_mt_holiday_struct_h_a_b, p_intl_envdatastruct_h, l_debug_info_ptr);
//   }
   
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}

				
/*CHGS BY AMISH */

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
	{
	

   
   if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
   {
	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a_b->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code) && APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_h->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code))
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a_b->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_h->h_exch_code) && APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_h->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_h->h_exch_code))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	   	   APL_GOBACK_FAIL
	    	   	   }
			CR_Mod_DBWklyHol(p_mt_holiday_struct_h_a_b, p_mt_holiday_struct_h_h, p_intl_envdatastruct_h, l_debug_info_ptr);
			}
		}
   }
   else
   {
	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a_b->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code))
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a_b->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   {
     	   	   APL_GOBACK_FAIL
	    	   }
			CR_Mod_WklyHolSngl(p_mt_holiday_struct_h_a_b, p_intl_envdatastruct_h, l_debug_info_ptr);
			}	
		}
   } 
   
     	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
     	    APL_GOBACK_FAIL
	   }
	}

  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
	{
   
   if (strlen(p_mt_holiday_struct_h_h->h_holi_dt))
   {
	

	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a_b->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code) && APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_h->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code))
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a_b->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code) && APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_h->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code))
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	   	   APL_GOBACK_FAIL
	    	   	   }
			CR_Mod_DBWklyHol(p_mt_holiday_struct_h_a_b, p_mt_holiday_struct_h_h, p_intl_envdatastruct_h, l_debug_info_ptr);
			}
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
	}
   else
   {
	if (APL_SUCCESS ==MT_Chk_Hol(p_mt_holiday_struct_h_a_b->h_holi_dt,"Y","N",APL_NULL_STRING,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code)) 
		{
		if (APL_SUCCESS ==CR_Chk_HolMkrChkr(p_mt_holiday_struct_h_a_b->h_holi_dt,p_intl_envdatastruct_h->usr,l_debug_info_ptr,p_mt_holiday_struct_h_a_b->h_exch_code)) 
			{
        		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       	   	   	   {
     	   	   	   APL_GOBACK_FAIL
	    	   	   }
			CR_Mod_WklyHolSngl(p_mt_holiday_struct_h_a_b, p_intl_envdatastruct_h, l_debug_info_ptr);
			}
		}
       	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
           {
     	    APL_GOBACK_FAIL
	   }
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
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Mod_WklyHol successfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Mod_WklyHol unsuccessfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_FAILURE);
	}
 }
