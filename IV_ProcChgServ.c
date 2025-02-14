




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"



int IV_Proc_NewServ(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, int *int_p_retstat, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

	extern int IV_Mod_IVSRVNew(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
	

	int int_l_status = 0;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct = *p_iv_serv_mast_struct_a;

	l_iv_serv_mast_struct.std_feeind = 'N';

	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);

	int_l_status = 0;
	

	if ( APL_FAILURE == IV_Mod_IVSRVNew(&l_iv_serv_mast_struct, 
										&int_l_status, 
										l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \n IV_Proc_NewServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of \nIV_Proc_NewServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



int IV_Proc_ChgServ(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, int *int_p_retstat, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVSRVLock(IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistServFeeStruct(const long l_servcode, int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVSRV(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;

	memset(l_iv_serv_mast_struct.service_det, APL_NULL_CHAR, 22);
	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_mast_struct.b_client, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

	l_iv_serv_mast_struct.service_cd = p_iv_serv_mast_struct_a->service_cd;
	l_iv_serv_mast_struct.fees_class = NULL;
	l_iv_serv_mast_struct.minimum_fee = 0.0;
	l_iv_serv_mast_struct.mastsub_ind = NULL;
	l_iv_serv_mast_struct.std_feeind = NULL;
	l_iv_serv_mast_struct.valid_fee_class = NULL;
	l_iv_serv_mast_struct.in_on_gen = NULL;

	strcpy(l_iv_serv_mast_struct.access_stamp, p_iv_serv_mast_struct_a->access_stamp);
	strcpy(l_iv_serv_mast_struct.maker, p_iv_serv_mast_struct_a->maker);

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVSRVLock(&l_iv_serv_mast_struct, &int_l_status, 
					      l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( strcmp(p_iv_serv_mast_struct_a->access_stamp, 
			l_iv_serv_mast_struct.access_stamp) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				   APL_NULL_STRING, APL_NULL_STRING, 
				   APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	if ( l_iv_serv_mast_struct.std_feeind == 'Y' ) 
	{
		/*if ( (p_iv_serv_mast_struct_a->service_cd != SPECIALBILLING) && 
		      strlen(p_iv_serv_mast_struct_a->b_client) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_CANT_DEFINE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}*/

		if ( strcmp(l_iv_serv_mast_struct.service_det, p_iv_serv_mast_struct_a->service_det) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SERVDESC_NOTCHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			APL_GOBACK_FAIL
		}
	}

	memset(l_iv_serv_mast_struct.service_det, APL_NULL_CHAR, 22);
	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_mast_struct.b_client, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

	strcpy(l_iv_serv_mast_struct.service_det, p_iv_serv_mast_struct_a->service_det);
	strcpy(l_iv_serv_mast_struct.access_stamp, p_iv_serv_mast_struct_a->access_stamp);

	l_iv_serv_mast_struct.service_cd = p_iv_serv_mast_struct_a->service_cd;
	l_iv_serv_mast_struct.minimum_fee = p_iv_serv_mast_struct_a->minimum_fee;
	l_iv_serv_mast_struct.mastsub_ind = p_iv_serv_mast_struct_a->mastsub_ind;
	l_iv_serv_mast_struct.std_feeind = l_iv_serv_mast_struct.std_feeind;
	l_iv_serv_mast_struct.in_on_gen = p_iv_serv_mast_struct_a->in_on_gen;

	if ( l_iv_serv_mast_struct.valid_fee_class == ' ' )
	{
		l_iv_serv_mast_struct.valid_fee_class = NULL;
	}

	if ( strlen(p_iv_serv_mast_struct_a->b_client) )
	{
		strcpy(l_iv_serv_mast_struct.b_client, p_iv_serv_mast_struct_a->b_client);
	}

/*	Since Fee Type define at client level, no check require	-	Rohit	*/
/*
	if ( l_iv_serv_mast_struct.fees_class != p_iv_serv_mast_struct_a->fees_class )
	{
		int_l_status = 0;

		if ( APL_FAILURE == 
				IV_Proc_ExistServFeeStruct(p_iv_serv_mast_struct_a->service_cd, 
						      &int_l_status, l_debug_info_ptr) )
		{
			if ( int_l_status == IV_CRITCAL_ERROR_IND )
			{
				*int_p_retstat = int_l_status;

				APL_GOBACK_FAIL
			}
		}
		else
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERV_FEE_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( (l_iv_serv_mast_struct.std_feeind == 'Y') && 
		     (l_iv_serv_mast_struct.valid_fee_class != 'B') )
		
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_FEETYPE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
*/
	l_iv_serv_mast_struct.fees_class = p_iv_serv_mast_struct_a->fees_class;

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVSRV(&l_iv_serv_mast_struct, &int_l_status, 
					     l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_ChgServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_ChgServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



int IV_Proc_DelServ(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, int *int_p_retstat, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVSRVLock(IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistServFeeStruct(const long l_servcode, int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOsAmt(const long l_servcode, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOthServAcc(const long l_servcode, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVSRVDel(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	int p_servcode = 0;
	char p_access_stamp[20] = APL_NULL_STRING;

	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;

	memset(l_iv_serv_mast_struct.service_det, APL_NULL_CHAR, 22);
	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_mast_struct.b_client, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

	p_servcode = p_iv_serv_mast_struct_a->service_cd;
	strcpy(p_access_stamp,p_iv_serv_mast_struct_a->access_stamp);

	p_servcode = p_iv_serv_mast_struct_a->service_cd;
	strcpy(p_access_stamp,p_iv_serv_mast_struct_a->access_stamp);


	l_iv_serv_mast_struct.service_cd = p_servcode;
	l_iv_serv_mast_struct.fees_class = NULL;
	l_iv_serv_mast_struct.minimum_fee = 0.0;
	l_iv_serv_mast_struct.std_feeind = NULL;
	l_iv_serv_mast_struct.mastsub_ind = NULL;
	l_iv_serv_mast_struct.valid_fee_class = NULL;
	l_iv_serv_mast_struct.in_on_gen = NULL;

	strcpy(l_iv_serv_mast_struct.access_stamp, p_access_stamp);
	strcpy(l_iv_serv_mast_struct.status, p_iv_serv_mast_struct_a->status);

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVSRVLock(&l_iv_serv_mast_struct, &int_l_status, 
					      l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( strcmp(p_iv_serv_mast_struct_a->access_stamp, 
			l_iv_serv_mast_struct.access_stamp) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				   APL_NULL_STRING, APL_NULL_STRING, 
				   APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	if ( l_iv_serv_mast_struct.std_feeind == 'Y' ) 
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_SERV_STANDARD, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	if ( APL_FAILURE == IV_Proc_ExistServFeeStruct(p_servcode, &int_l_status, 
						  l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
	}
	else
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_SERV_FEE_EXISTS, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	if ( APL_FAILURE == IV_Proc_ExistOsAmt(p_servcode, &int_l_status, l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
	}
	else
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_OSAMT_GRTR_ZERO, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	if ( APL_FAILURE == IV_Proc_ExistOthServAcc(p_servcode, &int_l_status, 
					       l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
	}
	else
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_SERV_NO_BILL, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	strcpy(l_iv_serv_mast_struct.maker, p_iv_serv_mast_struct_a->maker);

	if ( APL_FAILURE == IV_Mod_IVSRVDel(&l_iv_serv_mast_struct, &int_l_status, 
					     l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_DelServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_DelServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}


int IV_Proc_AutServ(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, int *int_p_retstat, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVSRVLock(IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistServFeeStruct(const long l_servcode, int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOsAmt(const long l_servcode, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOthServAcc(const long l_servcode, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVSRVAut(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	//SP 26-06-2007 to allow Auth of bill_service_code
	extern int IV_Mod_IVServUpdate(const long l_servcode,char *p_b_client,
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	int p_servcode = 0;
	char p_access_stamp[20] = APL_NULL_STRING;
	char p_b_client[24]= APL_NULL_STRING;

	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;

	memset(l_iv_serv_mast_struct.service_det, APL_NULL_CHAR, 22);
	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_mast_struct.b_client, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

	p_servcode = p_iv_serv_mast_struct_a->service_cd;
	strcpy(p_access_stamp,p_iv_serv_mast_struct_a->access_stamp);

	l_iv_serv_mast_struct.service_cd = p_servcode;
	l_iv_serv_mast_struct.fees_class = NULL;
	l_iv_serv_mast_struct.minimum_fee = 0.0;
	l_iv_serv_mast_struct.std_feeind = NULL;
	l_iv_serv_mast_struct.mastsub_ind = NULL;
	l_iv_serv_mast_struct.valid_fee_class = NULL;
	l_iv_serv_mast_struct.in_on_gen = NULL;

	strcpy(l_iv_serv_mast_struct.access_stamp, p_access_stamp);
	strcpy(l_iv_serv_mast_struct.status, p_iv_serv_mast_struct_a->status);

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVSRVLock(&l_iv_serv_mast_struct, &int_l_status, 
					      l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( strcmp(p_iv_serv_mast_struct_a->access_stamp, 
			l_iv_serv_mast_struct.access_stamp) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				   APL_NULL_STRING, APL_NULL_STRING, 
				   APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	if ( l_iv_serv_mast_struct.fees_class != p_iv_serv_mast_struct_a->fees_class )
	{
	//SP
	strcpy(p_b_client,p_iv_serv_mast_struct_a->b_client);
	int_l_status = 0;

		if ( APL_FAILURE == 
                                IV_Mod_IVServUpdate(p_servcode,p_b_client,
						      &int_l_status, l_debug_info_ptr) )
		{
			if ( int_l_status == IV_CRITCAL_ERROR_IND )
			{
				*int_p_retstat = int_l_status;

				APL_GOBACK_FAIL
			}
				APL_GOBACK_FAIL
                }/* SP 26-06-2007
		else
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERV_FEE_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
                }*/
		}

                int_l_status = 0;


	strcpy(l_iv_serv_mast_struct.checker, p_iv_serv_mast_struct_a->maker);

	if ( APL_FAILURE == IV_Mod_IVSRVAut(&l_iv_serv_mast_struct, &int_l_status, 
					     l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_AutServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_AutServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}


int IV_Proc_ResServ(const IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a, int *int_p_retstat, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVSRVLock(IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistServFeeStruct(const long l_servcode, int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOsAmt(const long l_servcode, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ExistOthServAcc(const long l_servcode, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVSRVRes(const IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	int p_servcode = 0;
	char p_access_stamp[20] = APL_NULL_STRING;

	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;

	memset(l_iv_serv_mast_struct.service_det, APL_NULL_CHAR, 22);
	memset(l_iv_serv_mast_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_mast_struct.b_client, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

	p_servcode = p_iv_serv_mast_struct_a->service_cd;
	strcpy(p_access_stamp,p_iv_serv_mast_struct_a->access_stamp);

	l_iv_serv_mast_struct.service_cd = p_servcode;
	l_iv_serv_mast_struct.fees_class = NULL;
	l_iv_serv_mast_struct.minimum_fee = 0.0;
	l_iv_serv_mast_struct.std_feeind = NULL;
	l_iv_serv_mast_struct.mastsub_ind = NULL;
	l_iv_serv_mast_struct.valid_fee_class = NULL;
	l_iv_serv_mast_struct.in_on_gen = NULL;

	strcpy(l_iv_serv_mast_struct.access_stamp, p_access_stamp);
	strcpy(l_iv_serv_mast_struct.status, p_iv_serv_mast_struct_a->status);

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVSRVLock(&l_iv_serv_mast_struct, &int_l_status, 
					      l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( strcmp(p_iv_serv_mast_struct_a->access_stamp, 
			l_iv_serv_mast_struct.access_stamp) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				   APL_NULL_STRING, APL_NULL_STRING, 
				   APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	if ( l_iv_serv_mast_struct.std_feeind == 'Y' ) 
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_SERV_STANDARD, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

	if ( l_iv_serv_mast_struct.fees_class != p_iv_serv_mast_struct_a->fees_class )
	{
		int_l_status = 0;

		if ( APL_FAILURE == 
				IV_Proc_ExistServFeeStruct(p_iv_serv_mast_struct_a->service_cd, 
						      &int_l_status, l_debug_info_ptr) )
		{
			if ( int_l_status == IV_CRITCAL_ERROR_IND )
			{
				*int_p_retstat = int_l_status;

				APL_GOBACK_FAIL
			}
		}
		else
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERV_FEE_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	}

	int_l_status = 0;

	strcpy(l_iv_serv_mast_struct.maker, p_iv_serv_mast_struct_a->maker);	

	if ( APL_FAILURE == IV_Mod_IVSRVRes(&l_iv_serv_mast_struct, &int_l_status, 
					     l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_ResServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_ResServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
