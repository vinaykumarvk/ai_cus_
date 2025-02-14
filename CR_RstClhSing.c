


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CO_HostStructdef.h>



int CR_Proc_CLHRstSingle(char *chr_p_client,char *chr_p_refno,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int			int_retval;
	char			chr_iexist,chr_icubk,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed;
	char			chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Proc_CLHRstSingle \n",NULL,p_intl_env_data_struct_h_d);

	if (strlen(chr_p_client) == 0)
		APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_refno) == 0)
		APL_DATA_MISSING("REFERENCE NO",APL_NULL_STRING,APL_NULL_STRING)
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Trade Account is %s \n",chr_p_client);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Trade identity No is %s \n",chr_p_refno);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	}
	
	chr_iexist = 'Y';
	chr_icubk = 'C';
	chr_iauthorised = 'Y';
	chr_ideleted = 'N';
	chr_ifrozen = 'N';
	chr_iclosed = 'N';
		
	int_retval = CO_Chk_AccValid(chr_p_client,chr_iexist,chr_icubk,NULL,NULL,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Proc_DBCLHRstSingle(chr_p_client,chr_p_refno,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
		
   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_CLHRstSingle \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_CLHRstSingle \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}
