




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"
#include "Intellect_Common.h"
#include "IV_OthServices.h"



int IV_Mod_NewOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a, 
		  const SYS_IVCONTROLPARAM_STRUCT *p_sys_ivcontrolparam_struct, const char p_isstdfee, 
		  const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		  int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Rtv_IVOTHSRV(IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVOTHSRVMaxSeqNum(
				const IV_SERV_OTH_STRUCT *p_iv_serv_oth_struct, 
				int *p_maxseqnum, int *int_p_retstat, 
				DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVOTHSRVNew(
				      const IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct,
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0, int_l_maxseqnum = 0, int_l_newseqnum = 0;
	IV_SERV_OTH_STRUCT l_iv_serv_oth_struct;
	IV_CLIENT_OTHSERV_STRUCT_H l_iv_client_othserv_struct_h;

	l_iv_client_othserv_struct_h = *p_iv_client_othserv_struct_h_a;

	memset(l_iv_serv_oth_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_serv_oth_struct.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.service_det, APL_NULL_CHAR, IV_DESC_LEN);
	memset(l_iv_serv_oth_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.access_stamp, APL_NULL_CHAR,APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);

	l_iv_serv_oth_struct.service_qty = 0.0;
	l_iv_serv_oth_struct.schdl_fee = 0.0;
	l_iv_serv_oth_struct.inden_num = 0;
	l_iv_serv_oth_struct.service_stat = NULL;

	strcpy(l_iv_serv_oth_struct.client, l_iv_client_othserv_struct_h.client);
	strcpy(l_iv_serv_oth_struct.b_upto_date, p_sys_ivcontrolparam_struct->b_upto_date);

	l_iv_serv_oth_struct.service_cd = l_iv_client_othserv_struct_h.service_cd;
 

	if ( ( p_isstdfee == 'N' ) || ( l_iv_serv_oth_struct.service_cd == CUSTODYFEE ) ) /* Bageshri For NAV */
	{
		int_l_status = 0;

		if (APL_FAILURE == IV_Rtv_IVOTHSRV(&l_iv_serv_oth_struct, 
						       &int_l_status, l_debug_info_ptr))
		{
			if ( int_l_status == IV_CRITCAL_ERROR_IND )
			{
				*int_p_retstat = int_l_status;

				APL_GOBACK_FAIL
			}
			else if ( int_l_status == IV_COLUMN_NULL_ERR )
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;

				CO_InsertErr(l_debug_info_ptr, ERR_SERV_EXISTS, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				

				APL_GOBACK_FAIL
			}
		}
		else 
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERV_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING,
				       APL_NULL_STRING, __LINE__, __FILE__);

			

			APL_GOBACK_FAIL
		}

		int_l_newseqnum = 1;
	}
	else 
	{
		if ( (l_iv_serv_oth_struct.service_cd == UNDERBILLING) || 
		     (l_iv_serv_oth_struct.service_cd == OVERBILLING) || 
		     (l_iv_serv_oth_struct.service_cd == SPECIALBILLING) )
		{
			int_l_status = 0;

			if ( APL_FAILURE == 
				IV_Rtv_IVOTHSRVMaxSeqNum(&l_iv_serv_oth_struct, 
							     &int_l_maxseqnum, 
							     &int_l_status, 
							     l_debug_info_ptr) )
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;

				APL_GOBACK_FAIL
			}

			int_l_newseqnum = int_l_maxseqnum + 1;
		}
		else
		{
			int_l_newseqnum = 1;
		}
	}

	memset(l_iv_serv_oth_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_serv_oth_struct.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.service_det, APL_NULL_CHAR, IV_DESC_LEN);
	memset(l_iv_serv_oth_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.access_stamp, APL_NULL_CHAR,APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);

	strcpy(l_iv_serv_oth_struct.client, l_iv_client_othserv_struct_h.client);
	strcpy(l_iv_serv_oth_struct.b_upto_date, p_sys_ivcontrolparam_struct->b_upto_date);
	strcpy(l_iv_serv_oth_struct.service_det, l_iv_client_othserv_struct_h.service_det);

	l_iv_serv_oth_struct.service_cd = l_iv_client_othserv_struct_h.service_cd;
	l_iv_serv_oth_struct.service_qty = l_iv_client_othserv_struct_h.quantity;
	l_iv_serv_oth_struct.schdl_fee = l_iv_client_othserv_struct_h.fees;

	strcpy(l_iv_serv_oth_struct.maker, p_intl_envdatastruct_h->usr);

	if ( !strcmp(p_intl_envdatastruct_h->auth_req, APL_NO_IND) && 
	     (p_sys_ivcontrolparam_struct->generate_ind == 'N') )
	{
		l_iv_serv_oth_struct.service_stat = 'A';

		strcpy(l_iv_serv_oth_struct.checker, p_intl_envdatastruct_h->usr);

	     
	}
	else
	{
		l_iv_serv_oth_struct.service_stat = 'U';
	}

	l_iv_serv_oth_struct.inden_num = int_l_newseqnum;

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVOTHSRVNew(&l_iv_serv_oth_struct, &int_l_status, 
						l_debug_info_ptr) )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Mod_NewOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Mod_NewOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



int IV_Mod_ChgOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a, 
		  const SYS_IVCONTROLPARAM_STRUCT *p_sys_ivcontrolparam_struct, 
		  const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		  int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVOTHSRVLock(IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct, 
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVOTHSRV(
				      const IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct,
				      const char l_blgenflag, 
				      const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_usermode;
	int int_l_status = 0;
	IV_SERV_OTH_STRUCT l_iv_serv_oth_struct;
	IV_CLIENT_OTHSERV_STRUCT_H l_iv_client_othserv_struct_h = *p_iv_client_othserv_struct_h_a;

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}

	memset(l_iv_serv_oth_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_serv_oth_struct.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.service_det, APL_NULL_CHAR, IV_DESC_LEN);
	memset(l_iv_serv_oth_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);

	strcpy(l_iv_serv_oth_struct.client, l_iv_client_othserv_struct_h.client);
	strcpy(l_iv_serv_oth_struct.b_upto_date, p_sys_ivcontrolparam_struct->b_upto_date);
	strcpy(l_iv_serv_oth_struct.access_stamp, l_iv_client_othserv_struct_h.access_stamp);

	l_iv_serv_oth_struct.service_cd = l_iv_client_othserv_struct_h.service_cd;
	l_iv_serv_oth_struct.inden_num = l_iv_client_othserv_struct_h.inden_num;

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVOTHSRVLock(&l_iv_serv_oth_struct, &int_l_status, 
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

			CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( l_iv_serv_oth_struct.service_stat == 'D' )
	{
		if ( chr_l_usermode == 'M' )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_DELETED, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		else if ( chr_l_usermode == 'D' )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_DELETED, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	l_iv_serv_oth_struct.service_qty = p_iv_client_othserv_struct_h_a->quantity;
	l_iv_serv_oth_struct.schdl_fee = p_iv_client_othserv_struct_h_a->fees;

	strcpy(l_iv_serv_oth_struct.service_det, p_iv_client_othserv_struct_h_a->service_det);

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVOTHSRV(&l_iv_serv_oth_struct, 
						p_sys_ivcontrolparam_struct->generate_ind, 
						p_intl_envdatastruct_h, &int_l_status, 
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
IV_Mod_ChgOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Mod_ChgOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



int IV_Mod_AuthOthServ(const IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a, 
		   const SYS_IVCONTROLPARAM_STRUCT *p_sys_ivcontrolparam_struct, 
		   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		   int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVOTHSRVLock(IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct, 
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVOTHSRV(
				      const IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct,
				      const char l_blgenflag, 
				      const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVOTHSRVDel(
				      const IV_SERV_OTH_STRUCT *l_iv_serv_oth_struct,
				      int *int_p_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	IV_CLIENT_OTHSERV_STRUCT_H l_iv_client_othserv_struct_h = *p_iv_client_othserv_struct_h_a;
	IV_SERV_OTH_STRUCT l_iv_serv_oth_struct;

	memset(l_iv_serv_oth_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_serv_oth_struct.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.service_det, APL_NULL_CHAR, IV_DESC_LEN);
	memset(l_iv_serv_oth_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_serv_oth_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_serv_oth_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);

	strcpy(l_iv_serv_oth_struct.client, l_iv_client_othserv_struct_h.client);
	strcpy(l_iv_serv_oth_struct.b_upto_date, p_sys_ivcontrolparam_struct->b_upto_date);
	strcpy(l_iv_serv_oth_struct.access_stamp, l_iv_client_othserv_struct_h.access_stamp);

	l_iv_serv_oth_struct.service_cd = l_iv_client_othserv_struct_h.service_cd;
	l_iv_serv_oth_struct.inden_num = l_iv_client_othserv_struct_h.inden_num;

	int_l_status = 0;

	if ( APL_FAILURE == IV_Mod_IVOTHSRVLock(&l_iv_serv_oth_struct, &int_l_status, 
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

			CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	if ( l_iv_serv_oth_struct.service_stat == 'A' )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_AUTHORIZED, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}
	else if ( !strcmp(l_iv_serv_oth_struct.maker, p_intl_envdatastruct_h->usr) )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	if ( (l_iv_serv_oth_struct.service_stat == 'U') || 
	     ((l_iv_serv_oth_struct.service_stat == 'D') && 
	      (l_iv_client_othserv_struct_h.purge_recall_ind == 'R')) )
	{
		int_l_status = 0;

		if ( APL_FAILURE == IV_Mod_IVOTHSRV(&l_iv_serv_oth_struct, 
							p_sys_ivcontrolparam_struct->generate_ind, 
							p_intl_envdatastruct_h, &int_l_status, 
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
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}
	}
	else if ( (l_iv_serv_oth_struct.service_stat == 'D') && 
		  (l_iv_client_othserv_struct_h.purge_recall_ind == 'P') )
	{
		int_l_status = 0;

		if (APL_FAILURE == IV_Mod_IVOTHSRVDel(&l_iv_serv_oth_struct, 
						       &int_l_status, l_debug_info_ptr))
		{
			if ( int_l_status == IV_CRITCAL_ERROR_IND )
			{
				*int_p_retstat = int_l_status;

				APL_GOBACK_FAIL
			}
			else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;

				CO_InsertErr(l_debug_info_ptr, ERR_OTHRSERV_NOTFND, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	} 

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Mod_AuthOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Mod_AuthOthServ().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
