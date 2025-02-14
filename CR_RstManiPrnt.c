












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int CR_Proc_MPRst (char *p_client,
						char *p_indentity_no,
						char *chr_p_action,
						char *serialno,
						FILE *p_logfile,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{


  DL_DEAL_OTH_MANP_RST_STRUCT_H  *l_dl_deal_oth_manp_rst_struct_h;

  int int_error_flag =APL_SUCCESS;

  l_dl_deal_oth_manp_rst_struct_h = (DL_DEAL_OTH_MANP_RST_STRUCT_H *)malloc(sizeof(DL_DEAL_OTH_MANP_RST_STRUCT_H));


 	CO_ProcMonitor(p_logfile, " Entered CR_Proc_MPRst in c_srstmp.c. Going For mandatory daa check\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);

	if (!strlen(p_client)) {APL_DATA_MISSING("Account",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  	if (!strlen(p_indentity_no)) {APL_DATA_MISSING("Reference Number",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 
  	if (!strlen(chr_p_action)) {APL_DATA_MISSING("Action",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 
	
	
 	CO_ProcMonitor(p_logfile, " CR_Proc_MPRst mandatory data check over\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }


  CR_Rtv_MPRst(p_client,p_indentity_no,serialno,p_logfile,l_dl_deal_oth_manp_rst_struct_h,l_debug_info_ptr); 
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }


  

  if ((!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_dlfromord,"N")) 
	  && (!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_entry,"G"))) 
	  {
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DEAL_SYSGEN_CANT_RST, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	  }

 	CO_ProcMonitor(p_logfile, " Trade errors if any For system Gen trade:\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

  

  if (((!strcmp(chr_p_action,"R"))|| (!strcmp(chr_p_action,"O"))
		|| (!strcmp(chr_p_action,"T"))) &&
	  ((!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_dealcd,"1")) 
	  || (!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_dealcd,"3")))) 
	  {
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DLVRTRD_CANT_RESET, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	  }

  if ((!strcmp(chr_p_action,"D")) && 
	  ((!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_dealcd,"2")) 
	  || (!strcmp(l_dl_deal_oth_manp_rst_struct_h->p_dealcd,"4")))) 
	  {
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_RECVTRD_CANT_RESET, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	  }

 	CO_ProcMonitor(p_logfile, " Trade errors if any for Recieve/deliver trade:\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

  

  if (((!strcmp(chr_p_action,"R"))|| (!strcmp(chr_p_action,"D"))) 
	  && (!strlen(l_dl_deal_oth_manp_rst_struct_h->p_delrecdate))) 
	  {
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DEAL_MANIFLD_NPRINT, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	  }

 	CO_ProcMonitor(p_logfile, " Trade errors if manifold not printed:\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }
	
  if (((!strcmp(chr_p_action,"O"))|| (!strcmp(chr_p_action,"T"))) 
	  && (!strlen(l_dl_deal_oth_manp_rst_struct_h->p_instrdate)))
	  {
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DEAL_NSETL, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	  }
	
	if ((!strcmp(chr_p_action,"O")) && (l_dl_deal_oth_manp_rst_struct_h->p_tempoutquantity <= 0))
	{
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DEAL_MANIFLD_NPRINT, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
	}

	if ((!strcmp(chr_p_action,"T")) && (l_dl_deal_oth_manp_rst_struct_h->p_tempretquantity <= 0))
	{
	  if(CO_InsertErr(
             	l_debug_info_ptr,
               ERR_DEAL_MANIFLD_NPRINT, 
				   
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
               __LINE__,
               __FILE__
               ) != APL_SUCCESS)
      APL_GOBACK_FAIL
		
	}

 	CO_ProcMonitor(p_logfile, " Trade errors if trade is settled:\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

 	CO_ProcMonitor(p_logfile, "About to call CR_Proc_DBMPRst\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
  		if (APL_FAILURE == CR_Proc_DBMPRst(p_client,
													p_indentity_no,
													chr_p_action,
													serialno,
													p_logfile,
													l_dl_deal_oth_manp_rst_struct_h,
													p_intl_envdatastruct_h,
													l_debug_info_ptr))
				{
 					CO_ProcMonitor(p_logfile, " Failure in CDBManPrntFn in c_dbrsmp.pc:\n", 
							l_debug_info_ptr, p_intl_envdatastruct_h);

     				{APL_GOBACK_FAIL }
				}

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }


  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
 	CO_ProcMonitor(p_logfile, "Leaving CR_Proc_MPRst in c_srstmp.c. SUCCESS!!\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
	free(l_dl_deal_oth_manp_rst_struct_h); 
	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
 	CO_ProcMonitor(p_logfile, "Leaving CR_Proc_MPRst in c_srstmp.c. FAILED!\n", 
				l_debug_info_ptr, p_intl_envdatastruct_h);
	free(l_dl_deal_oth_manp_rst_struct_h); 
	return(APL_FAILURE);
	}
}
