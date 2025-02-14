




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"



int IV_Proc_ServMnt(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, 
	       const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Proc_NewServ(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ChgServ(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_DelServ(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_AutServ(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
	
	extern int IV_Proc_ResServ(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	char chr_l_buffer1[BUFFER_LEN];
	char chr_l_usermode;
	int int_l_retstat = 0;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct = *p_iv_serv_mast_struct_a;

	

	memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer1, "%ld", l_iv_serv_mast_struct.service_cd);

	if ( !strlen(chr_l_buffer1) )
	{
		APL_DATA_MISSING("Service Code", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("User Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	chr_l_usermode = NULL;

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	    strcpy(l_iv_serv_mast_struct.status,"UU");	
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	    strcpy(l_iv_serv_mast_struct.status,"AA");	
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	    strcpy(l_iv_serv_mast_struct.status,"DU");	
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE) )
	{
		chr_l_usermode = 'A';

	    if(!strcmp(l_iv_serv_mast_struct.status,"DU"))/***** 12/02/2008 : Vinay *******/
	    	strcpy(l_iv_serv_mast_struct.status,"DU");
	    else
	    	strcpy(l_iv_serv_mast_struct.status,"AA");	
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET) )
	{
		chr_l_usermode = 'R';
	    strcpy(l_iv_serv_mast_struct.status,"AA");	
	}



	if ( chr_l_usermode != 'I' ) 
	{
		if ( !strlen(l_iv_serv_mast_struct.access_stamp) )
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					  APL_NULL_STRING)

			APL_GOBACK_FAIL
		}
	}
	else
	{
		if ( l_iv_serv_mast_struct.service_cd <= 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SERVCODE_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		if ( !strlen(l_iv_serv_mast_struct.service_det) )
		{
			APL_DATA_MISSING("Serv. Desc.", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( (l_iv_serv_mast_struct.fees_class != 'P') && 
		     (l_iv_serv_mast_struct.fees_class != 'U') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_FEE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	/*	if ( !strcmp(l_mt_core_sys_params_struct_h.sub_clt_proc, APL_YES_IND) )
		{
			if ( (l_iv_serv_mast_struct.mastsub_ind != 'M') && 
			     (l_iv_serv_mast_struct.mastsub_ind != 'S') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCTYPE_INVALID, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}
		else
		{
			l_iv_serv_mast_struct.mastsub_ind = 'M';
		}
	
	*/

		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%lf", l_iv_serv_mast_struct.minimum_fee);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Minimum Fee", APL_NULL_STRING, 
					  APL_NULL_STRING)

			APL_GOBACK_FAIL
		}
		else if ( l_iv_serv_mast_struct.minimum_fee < 0.0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_MINFEE_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	} 

	int_l_retstat = 0;

	strcpy(l_iv_serv_mast_struct.maker,p_intl_envdatastruct_h->usr);

	if ( chr_l_usermode == 'I' )
	{
		if ( APL_FAILURE == IV_Proc_NewServ(&l_iv_serv_mast_struct, &int_l_retstat, 
					       l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'M' )
	{
		if ( APL_FAILURE == IV_Proc_ChgServ(&l_iv_serv_mast_struct, &int_l_retstat, 
					       l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'D' )
	{
		if ( APL_FAILURE == IV_Proc_DelServ(&l_iv_serv_mast_struct, &int_l_retstat, 
					       l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'A' )
	{
		if ( APL_FAILURE == IV_Proc_AutServ(&l_iv_serv_mast_struct, &int_l_retstat, 
					       l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'R' )
	{
		if ( APL_FAILURE == IV_Proc_ResServ(&l_iv_serv_mast_struct, &int_l_retstat, 
					       l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}



	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_ServMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_ServMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
