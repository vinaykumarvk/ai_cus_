




#define PURE_C_SOURCE

#include "stdio_64.h"
#include <stdlib.h>
#include <string.h>

#include "IV_Control_A.h"
#include "IV_Setup.h"


int IV_Upd_ControlParamMnt(const IV_CNTRL_PARAM_STRUCT_H *p_iv_cntrl_param_struct_h_a, 
		    const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		    DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int CO_RtvSysDt(char *chr_l_sys_date, 
				    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int CO_Pro_DateComp(char *chr_l_from_date, char *chr_l_to_date, 
				int *int_l_diff, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCNTLPARAM(SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				    int *int_l_retstat, 
				    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_NewIVCNTLPARAM(const SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_LockIVCNTLPARAM(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int BBDbIsBetweenGenAndDlvDt(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int CO_Chk_Holiday(char *chr_l_holi_date, int *int_l_exist, 
				    DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *p_exch_code);

	extern int IV_Mod_IVBCNTLPARAMMnt(const SYS_IVCONTROLPARAM_STRUCT *l_sys_ivcntlparam_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVOTHSRV_IVPrd(const char *l_prevbluptodate, 
					    const char *l_newbluptodate, 
					    int *int_l_retstat, 
					    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_usermode = NULL;
	char chr_l_sys_date[APL_DATE_LEN];
	int int_l_retstat = 0, int_l_diff = 0, int_l_exist = 0;
   short int_l_condexists = 0;
	SYS_IVCONTROLPARAM_STRUCT l_sys_ivcntlparam_struct, l_sys_ivcontrolparam_struct_old;

	if ( !strlen(p_iv_cntrl_param_struct_h_a->b_upto_date) )
	{
		APL_DATA_MISSING("Bill Upto Dt.", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(p_iv_cntrl_param_struct_h_a->b_dlv_date) )
	{
		APL_DATA_MISSING("Bill Delivery Dt.", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(p_iv_cntrl_param_struct_h_a->b_processdt) )
	{
		APL_DATA_MISSING("Bill Processing Dt.", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("User Mode", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}

	if ( (chr_l_usermode == 'I') && !strlen(p_iv_cntrl_param_struct_h_a->b_prev_date) )
	{
		APL_DATA_MISSING("Prev. Bill Dt.", APL_NULL_STRING, 
				  APL_NULL_STRING)

		APL_GOBACK_FAIL
	}

	memset(l_sys_ivcontrolparam_struct_old.b_prev_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.b_processdt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.b_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.archival_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.last_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcontrolparam_struct_old.last_rpt_date, APL_NULL_CHAR, APL_DATE_LEN);

	l_sys_ivcontrolparam_struct_old.generate_ind = NULL;
	l_sys_ivcontrolparam_struct_old.ae_ind = NULL;
	l_sys_ivcontrolparam_struct_old.b_gen_ind = NULL;

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Rtv_IVCNTLPARAM(&l_sys_ivcontrolparam_struct_old, &int_l_retstat, 
					     l_debug_info_ptr) )
	{
		if ( (int_l_retstat == IV_COLUMN_NULL_ERR) && (chr_l_usermode == 'I') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLCNTRL_PARAM_EXIST, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		else if ( (int_l_retstat == IV_NO_DATA_FOUND_ERR) && 
			  (chr_l_usermode == 'M') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLCNTRL_PARAM_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'I' )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_BILLCNTRL_PARAM_EXIST, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	memset(chr_l_sys_date, APL_NULL_CHAR, APL_DATE_LEN);

	int_l_retstat = 0;

	if ( APL_FAILURE == CO_RtvSysDt(chr_l_sys_date, l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	memset(l_sys_ivcntlparam_struct.b_prev_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.b_upto_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.b_processdt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.b_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.archival_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.last_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_sys_ivcntlparam_struct.last_rpt_date, APL_NULL_CHAR, APL_DATE_LEN);

	l_sys_ivcntlparam_struct.generate_ind = NULL;
	l_sys_ivcntlparam_struct.ae_ind = NULL;
	l_sys_ivcntlparam_struct.b_gen_ind = NULL;

	strcpy(l_sys_ivcntlparam_struct.b_prev_date, p_iv_cntrl_param_struct_h_a->b_prev_date);
	strcpy(l_sys_ivcntlparam_struct.b_upto_date, p_iv_cntrl_param_struct_h_a->b_upto_date);
	strcpy(l_sys_ivcntlparam_struct.b_processdt, p_iv_cntrl_param_struct_h_a->b_processdt);
	strcpy(l_sys_ivcntlparam_struct.b_dlv_date, p_iv_cntrl_param_struct_h_a->b_dlv_date);

   if ( APL_FAILURE == CO_Chk_CntryEnabled("BILL_PARAM", "NO_CHK_PROC_NEXT", &int_l_condexists, l_debug_info_ptr) )
      {
        APL_GOBACK_FAIL
      }

	if ( chr_l_usermode == 'I' )
	{
		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_prev_date, 
						 chr_l_sys_date, &int_l_diff, 
						 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_LASTBILLDT_CANT_IN_FUTURE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(chr_l_sys_date, 
						 l_sys_ivcntlparam_struct.b_upto_date, 
						 &int_l_diff, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_NXTBILLDT_CANT_PAST, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_prev_date, 
						 l_sys_ivcntlparam_struct.b_upto_date,&int_l_diff,
						 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff <= 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_NXTBILLDT_CANT_LESS_LASTBILLDT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_prev_date, 
						 l_sys_ivcntlparam_struct.b_processdt, 
						 &int_l_diff, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff <= 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PROCDT_LESS_LASTBILLDT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_processdt, 
						 l_sys_ivcntlparam_struct.b_upto_date,&int_l_diff,
						 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}


		if (( int_l_diff < 0 ) && (int_l_condexists == 0))
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PROCDT_GRTR_NXTBILLDT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		int_l_exist = 0;

		if ( APL_FAILURE == CO_Chk_Holiday(l_sys_ivcntlparam_struct.b_processdt, 
						     &int_l_exist, l_debug_info_ptr,APL_NULL_STRING) )
		{
			if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}

		if ( int_l_exist )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLPROCDT_CANT_HOLIDAY, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_upto_date, 
						 l_sys_ivcntlparam_struct.b_dlv_date,&int_l_diff,
						 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLDELVDT_CANT_LESS_NXTBILLDT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		l_sys_ivcntlparam_struct.generate_ind = 'N';
		l_sys_ivcntlparam_struct.ae_ind = 'N';
		l_sys_ivcntlparam_struct.b_gen_ind = 'N';

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_NewIVCNTLPARAM(&l_sys_ivcntlparam_struct, &int_l_retstat, 
						     l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL 
		}

	}
	else if ( chr_l_usermode == 'M' )
	{
		if ( APL_FAILURE == IV_Mod_LockIVCNTLPARAM(l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if (strcmp(l_sys_ivcntlparam_struct.b_prev_date, l_sys_ivcontrolparam_struct_old.b_prev_date))
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PRVBILLDT_CANT_MODIFY, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

		if ( APL_FAILURE == IV_Rtv_Bill_FrmGendt_DlvDt(l_debug_info_ptr) )
		{
			if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}

			

			int_l_diff = 0;

			if (APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_prev_date, 
							l_sys_ivcntlparam_struct.b_upto_date,
							&int_l_diff, l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}

			if ( int_l_diff <= 0 )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_NXTBILLDT_CANT_LESS_LASTBILLDT, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			

			int_l_diff = 0;

			if ( APL_FAILURE == 
					CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_prev_date, 
						     l_sys_ivcntlparam_struct.b_processdt, 
						     &int_l_diff, l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}

			if ( int_l_diff <= 0 )
			{
				CO_InsertErr(l_debug_info_ptr,ERR_PROCDT_LESS_LASTBILLDT,
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			if (APL_FAILURE == 
					CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_processdt, 
						     l_sys_ivcntlparam_struct.b_upto_date, 
						     &int_l_diff, l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}
         
			if (( int_l_diff < 0 ) && (int_l_condexists == 0))
			{
				CO_InsertErr(l_debug_info_ptr, ERR_PROCDT_GRTR_NXTBILLDT,
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			

			int_l_exist = 0;

			if ( APL_FAILURE == 
				CO_Chk_Holiday(l_sys_ivcntlparam_struct.b_processdt, 
						 &int_l_exist, l_debug_info_ptr,APL_NULL_STRING) )
			{
				if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}
			}

			if ( int_l_exist )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLPROCDT_CANT_HOLIDAY, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}
		else 
		{
			if ( strcmp(l_sys_ivcntlparam_struct.b_upto_date, 
				    l_sys_ivcontrolparam_struct_old.b_upto_date) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BTWGENDELV_CANTMOD_NXTBILLDT, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			if ( strcmp(l_sys_ivcntlparam_struct.b_processdt, 
				    l_sys_ivcontrolparam_struct_old.b_processdt) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BTWNGENDELV_CANTMOD_PROCDT, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

		} 

		

		int_l_diff = 0;

		if ( APL_FAILURE == CO_Pro_DateComp(l_sys_ivcntlparam_struct.b_upto_date, 
						 l_sys_ivcntlparam_struct.b_dlv_date, &int_l_diff,
						 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( int_l_diff < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLDELVDT_CANT_LESS_NXTBILLDT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVBCNTLPARAMMnt(&l_sys_ivcntlparam_struct, 
							&int_l_retstat, 
							l_debug_info_ptr) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLCNTRL_PARAM_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if (strcmp(l_sys_ivcntlparam_struct.b_upto_date, l_sys_ivcontrolparam_struct_old.b_upto_date))
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
					IV_Mod_IVOTHSRV_IVPrd(
						l_sys_ivcontrolparam_struct_old.b_upto_date, 
						l_sys_ivcntlparam_struct.b_upto_date, 
						&int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
				{
					APL_GOBACK_FAIL
				}
			}
		}

	} 

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Upd_ControlParamMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Upd_ControlParamMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
