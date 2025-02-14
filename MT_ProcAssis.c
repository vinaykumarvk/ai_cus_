






#define PURE_C_SOURCE
#include <CO_HostStructdef.h>



int CR_Mod_AssisCd(MHLP_CODE_STRUCT_H *p_mhlp_code_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int         int_retval = 0;
   char        chr_l_field_val[40] = APL_NULL_STRING;
	char        chr_l_row_id_assis[APL_ROWID_LEN+1];
	char			chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char			chr_l_lbrk_mstacc[APL_CLIENT_LENGTH] = APL_NULL_STRING;


	APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Mod_AssisCd \n",NULL,p_intl_env_data_struct_h_d);
		
	if(strlen(p_mhlp_code_struct_h->h_mhlp_code) == 0)
		APL_DATA_MISSING("MHLP_CODE",APL_NULL_STRING,APL_NULL_STRING);
	
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Assis h_code is :%s: \n",p_mhlp_code_struct_h->h_mhlp_code);
  	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if(strlen(p_mhlp_code_struct_h->h_custodian_clt) == 0)
		APL_DATA_MISSING("CUSTODIAN_CLT",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Custodian is :%s: \n",p_mhlp_code_struct_h->h_custodian_clt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if(!strcmp(p_mhlp_code_struct_h->h_custodian_clt,l_mt_core_sys_params_struct_h.custody_clt_cd) && 
		(strlen(p_mhlp_code_struct_h->h_dl_client)==0))
			APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Accoutn is :%s: \n",p_mhlp_code_struct_h->h_dl_client);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if((strlen(p_mhlp_code_struct_h->h_dl_client) > 0) && (strlen(p_mhlp_code_struct_h->h_mstclt) == 0) )
		APL_DATA_MISSING("MASTER_CLT",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Master Account is :%s: \n",p_mhlp_code_struct_h->h_mstclt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if(strlen(p_mhlp_code_struct_h->h_lcl_brkcd)==0) 
		APL_DATA_MISSING("LCL_BRKCD",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"LBRK_CODE is :%s: \n",p_mhlp_code_struct_h->h_lcl_brkcd);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if(strlen(p_mhlp_code_struct_h->h_lcl_opcd)==0) 
   	APL_DATA_MISSING("LCL_OPCD",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"LBRK_OP_CODE is :%s: \n",p_mhlp_code_struct_h->h_lcl_opcd);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if(strlen(p_mhlp_code_struct_h->h_manual_ind_intn)==0 )
   	APL_DATA_MISSING("MANUAL_IND",APL_NULL_STRING,APL_NULL_STRING);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"MANUAL_INTN is :%s: \n",p_mhlp_code_struct_h->h_manual_ind_intn);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if ( (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) &&
      	(strlen(p_mhlp_code_struct_h->h_access_stamp) == 0) )
   	APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING);

	
	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
	{
		CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Rtv_AssisFldVal to obtain ROWID in Modify mode",NULL,NULL);
			
		int_retval = DL_Rtv_AssisFldVal(p_mhlp_code_struct_h->h_mhlp_code,p_mhlp_code_struct_h->h_lcl_brkcd,"ROWID",chr_l_field_val,l_debug_info_ptr);

		if(int_retval!=APL_SUCCESS)
			APL_GOBACK_FAIL

		strcpy(chr_l_row_id_assis,chr_l_field_val);

		CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Rtv_AssisFldVal to the access stamp  in Modify mode",NULL,NULL);

		int_retval = DL_Rtv_AssisFldVal(p_mhlp_code_struct_h->h_mhlp_code,p_mhlp_code_struct_h->h_lcl_brkcd,"access_stamp",chr_l_field_val,l_debug_info_ptr);

		if(int_retval!=APL_SUCCESS)
      	APL_GOBACK_FAIL

		if (strcmp(chr_l_field_val,p_mhlp_code_struct_h->h_access_stamp) != 0)
     	{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mhlp_code_struct_h->h_mhlp_code,p_mhlp_code_struct_h->h_lcl_brkcd,APL_NULL_STRING,__LINE__,__FILE__);

			APL_GOBACK_FAIL
		}

	}

	if(APL_FAILURE == DL_Rtv_MastAcc(p_mhlp_code_struct_h->h_lcl_brkcd,
												  chr_l_lbrk_mstacc, 
												  l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}

	
	strcpy(p_mhlp_code_struct_h->h_lbrk_mstclt,chr_l_lbrk_mstacc);


	
	CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Chk_AssisDET to check the  validity of the data ",NULL,NULL);

	int_retval = DL_Chk_AssisDET(p_mhlp_code_struct_h,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Mod_AssisCd to update the table in any mode",NULL,NULL);

	int_retval = DL_Mod_AssisCd(p_mhlp_code_struct_h,chr_l_row_id_assis,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

  	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CDBUpdAssisFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CDBUpdAssisFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}





int CR_Mod_AssisCdOth(char *p_assis_code, char *p_lbrk_code,char *chr_p_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int         int_retval = 0;
   char        chr_l_field_val[40] = APL_NULL_STRING;
   char        chr_l_row_id_assis[APL_ROWID_LEN+1];
   char        chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
   char        chr_l_lbrk_mstacc[APL_CLIENT_LENGTH] = APL_NULL_STRING;


   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Mod_AssisCdOth \n",NULL,p_intl_env_data_struct_h_d);

   if(strlen(p_assis_code) == 0)
      APL_DATA_MISSING("MHLP_CODE",APL_NULL_STRING,APL_NULL_STRING);

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Assis h_code is :%s: \n",p_assis_code);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if(strlen(p_lbrk_code) == 0)
      APL_DATA_MISSING("LOCAL BROKER",APL_NULL_STRING,APL_NULL_STRING);

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Broker is :%s: \n",p_lbrk_code);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Rtv_AssisFldVal to obtain ROWID in Authorise,Delete mode",NULL,NULL);

   int_retval = DL_Rtv_AssisFldVal(p_assis_code,p_lbrk_code,"ROWID",chr_l_field_val,l_debug_info_ptr);

   if(int_retval!=APL_SUCCESS)
   	APL_GOBACK_FAIL

   strcpy(chr_l_row_id_assis,chr_l_field_val);

	
	CO_ProcMonitor(APL_OUT_FILE,"Calling DL_Rtv_AssisFldVal to obtain the access stamp in Delete/Authorise mode",NULL,NULL);

	int_retval = DL_Rtv_AssisFldVal(p_assis_code,p_lbrk_code,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	
   if(int_retval!=APL_SUCCESS)
   	APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_access_stamp) != 0)
   {
   	CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_assis_code,p_lbrk_code,APL_NULL_STRING,__LINE__,__FILE__);

      APL_GOBACK_FAIL
	}

	if (APL_FAILURE == DL_Chk_AssisOTH(p_assis_code,p_lbrk_code,p_intl_env_data_struct_h_d,l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
      APL_GOBACK_FAIL


	int_retval = DL_Mod_AssisOTH(p_assis_code,p_lbrk_code,chr_l_row_id_assis,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_AssisCdOth SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_AssisCdOth FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
	}

}	
