







#define PURE_C_SOURCE
#include "CO_HostStructdef.h"



int CBDoRegnFn(	REG_TRF_STRUCT_H *p_reg_trf_struct_h,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

	

	char chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;

	BCL_TRF_STRUCT_H l_bcl_trf_struct_h;


	

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE, 
						"Entered Function CBDoRegnFn\n",
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Account is : %s\n", 
						p_reg_trf_struct_h->h_dl_client);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Instrurity Code is : %s\n", 
						p_reg_trf_struct_h->h_instr_code);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LOcation Code is : %s\n", 
						p_reg_trf_struct_h->h_loccode);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Qty of Instrurities is : %f\n", 
						p_reg_trf_struct_h->h_qty);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LocRefNo for RECEIVE_FREE is : %s\n", 
						p_reg_trf_struct_h->h_locindentity_no_rf);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The LocRefNo for DELV_FREE is : %s\n", 
						p_reg_trf_struct_h->h_locindentity_no_df);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
	}

	
	

	

	memset(&l_bcl_trf_struct_h, NULL, sizeof(BCL_TRF_STRUCT_H));
	strcpy(l_bcl_trf_struct_h.h_dl_client, p_reg_trf_struct_h->h_dl_client);
	strcpy(l_bcl_trf_struct_h.h_instr_code, p_reg_trf_struct_h->h_instr_code);
	strcpy(l_bcl_trf_struct_h.h_loccode, p_reg_trf_struct_h->h_loccode);
	l_bcl_trf_struct_h.h_qty = p_reg_trf_struct_h->h_qty;
	l_bcl_trf_struct_h.h_bclreg_ind[0] = REG_BCL_IND;
	l_bcl_trf_struct_h.h_bclreg_ind[1] = '\0';
	strcpy(l_bcl_trf_struct_h.h_locindentity_no_rf, p_reg_trf_struct_h->h_locindentity_no_rf);
	strcpy(l_bcl_trf_struct_h.h_locindentity_no_df, p_reg_trf_struct_h->h_locindentity_no_df);
	
	

	if (APL_FAILURE == CR_Proc_BkClose(	&l_bcl_trf_struct_h,
											p_intl_envdatastruct_h,
											l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
	
	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CBDoRegnFn with success\n",
							NULL,
							NULL);
		}
      return(APL_SUCCESS);

   RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CBDoRegnFn with errors\n",
							NULL,
							NULL);
		}
      return(APL_FAILURE);

}

