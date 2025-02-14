












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int CR_Proc_MrktPr (MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h, 
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

	char chr_p_now[APL_DATE_LEN] = APL_NULL_STRING;
	int int_p_date_diff;


APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_ExgRt. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }



  if (!strlen(p_mt_dlymktprc_struct_h->h_instr_code)) 
  		APL_DATA_MISSING("Instrurity Code",APL_NULL_STRING,APL_NULL_STRING);
  if (!strlen(p_mt_dlymktprc_struct_h->h_prdt)) 
		APL_DATA_MISSING("Price Date",APL_NULL_STRING,APL_NULL_STRING);
  if (0 ==p_mt_dlymktprc_struct_h->h_closing_pr) 
		APL_DATA_MISSING("Market Price",APL_NULL_STRING,APL_NULL_STRING);



  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
  {
	  if (!strlen(p_mt_dlymktprc_struct_h->h_access_stamp)) 
			APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  }

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
  {
     APL_GOBACK_FAIL
  }

  

  if ( APL_FAILURE == CO_RtvSysDt( chr_p_now, l_debug_info_ptr ) )
  {
     APL_GOBACK_FAIL
  }
	
  

  if ( APL_FAILURE == CO_Pro_DateComp(	p_mt_dlymktprc_struct_h->h_prdt,
												chr_p_now,
												&int_p_date_diff,
												l_debug_info_ptr))
  {		
		APL_GOBACK_FAIL
  }

  if (int_p_date_diff <0)
  {
 		if(CO_InsertErr(	l_debug_info_ptr,
                           ERR_DATE_CANT_FUTURE,
									
                           APL_NULL_STRING,
                           APL_NULL_STRING,
                           APL_NULL_STRING,
                           __LINE__,
                           __FILE__
                           ) != APL_SUCCESS)
      APL_GOBACK_FAIL
  }

  

  if (APL_FAILURE ==CO_Chk_InstrValid( p_mt_dlymktprc_struct_h->h_instr_code,
                                 'Y','Y',
                                 APL_NULL_STRING,
                                 APL_NULL_STRING,
                                 APL_NULL_STRING,
                                 APL_NULL_STRING,
                                 l_debug_info_ptr))
  {
  		APL_GOBACK_FAIL
  }


 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
  {
  		APL_GOBACK_FAIL
  }

 

 if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
 {
 	if (APL_FAILURE == CR_Proc_MkrtPrAuth(p_mt_dlymktprc_struct_h->h_prdt,
													p_mt_dlymktprc_struct_h->h_instr_code,
													p_intl_envdatastruct_h->usr,
													p_intl_envdatastruct_h->h_mode,
													l_debug_info_ptr))
   {
     		APL_GOBACK_FAIL	
  	}
 }

 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
  {
  		APL_GOBACK_FAIL
  }


 

 if (APL_FAILURE == CR_Mod_MkrtPr(p_mt_dlymktprc_struct_h ,
												p_intl_envdatastruct_h ,
												l_debug_info_ptr))
  {
      APL_GOBACK_FAIL	
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
      CO_ProcMonitor(APL_OUT_FILE, 
					"Success in CBUpdMrktPrcFn.Getting out!!\n",
					NULL,
					p_intl_envdatastruct_h);
    }
	 return(APL_SUCCESS);
	}

  RETURN_FAILURE :
	{

    APL_IF_DEBUG
    {
    CO_ProcMonitor(APL_OUT_FILE, 
				"Failed in CBUpdMrktPrcFn. Chucking out!!\n",
				NULL,
				p_intl_envdatastruct_h);
    }
	return(APL_FAILURE);
	}

} 
