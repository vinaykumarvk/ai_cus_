




#define PURE_C_SOURCE

#include "stdio_64.h"
#include <string.h> 
#include <stdlib.h>
#include <sqlca.h>
#include "IV_Control_A.h"
#include "IV_Control.h"



int IV_Upd_CustFeeMnt(const IV_CUSTFEE_STRUCT_H *l_iv_custfee_struct_h, 
		  const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		  DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int CO_Chk_AccValid(char *chr_l_client, char int_l_exist, char l_cubk, 
			       char l_orderac, char l_mastclt, char l_auth, 
			       char l_del, char l_frozen, char l_closed, 
			       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Chk_Account(const char *chr_l_client, char *chr_l_statusflg, 
				 int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client, 
				     IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVSRVCHRGDel(long l_servcode, 
				   IV_SERV_MAST_STRUCT *l_iv_serv_mast_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_NewIVCUSTFEE(const IV_CLIENTFEE_STRUCT_H *l_iv_clientfee_struct_hc, 
					const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCUSTFEEChg(const IV_CLIENTFEE_STRUCT_H *l_iv_clientfee_struct_hc, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_DelIVCUSTFEEMarkSlab(const IV_CLIENTFEE_STRUCT_H *l_iv_clientfee_struct_hc, 
					   int *int_l_retstat, 
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCUSTSETUPMkrChkr(const char *chr_l_client, 
					const char *l_access_stamp, 
					const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPLockRow(const char *chr_l_client, 
					 const char *l_access_stamp, 
					 int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkServDepncy(const char *chr_l_client, 
				     const long l_servcode, const char *chr_l_apl_frm_date, int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Chk_Basis(const char *chr_l_client, const long l_servcode, const char *chr_l_apl_frm_date,
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_PurgeSlabSpecial(const char *chr_l_client,const char *chr_l_apl_frm_date, int *int_l_retstat,
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);   /* Added apl_frm_date by monica for kotak ISKB_1737 */

	extern int IV_ChkParamVal(const char *p_client, const long p_servcode, const char *chr_l_apl_frm_date,
				  const char *p_paramval, int *int_p_retstat, 
				  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_usermode, chr_l_buffer[BUFFER_LEN];
	char chr_l_actionflag = NULL;
	int int_l_retstat = 0;
	IV_CLIENTFEE_STRUCT_H l_iv_clientfee_struct_hc;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;
	INTL_ENV_DATA_STRUCT_H l_intl_env_datastruct_h = *p_intl_envdatastruct_h;

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}

		

	if ( !strlen(l_iv_custfee_struct_h->client) )
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING)
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%ld", l_iv_custfee_struct_h->service_cd);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("Service Code", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%lf", l_iv_custfee_struct_h->frm_cbase);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("From Charge Basis", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%lf", l_iv_custfee_struct_h->frm_fbase);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("From Fee Basis", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(l_iv_custfee_struct_h->bcustsetup_access_stamp) )
	{
		APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( (chr_l_usermode != 'D') && !strlen(p_intl_envdatastruct_h->h_process) )
	{
		APL_DATA_MISSING("Action Flag", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( chr_l_usermode != 'D' )
	{
		if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_NEW_IND) )
		{
			chr_l_actionflag = 'I';
		}
		else if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_MOD_IND) )
		{
			chr_l_actionflag = 'M';
		}
		else if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_DEL_IND) )
		{
			

			chr_l_actionflag = 'D';
		}
	}

    /* Added for Billing Fee Upload - Starts */
	if ( strcmp(p_intl_envdatastruct_h->h_process,"U")==0)
	{
		if ( chr_l_usermode == 'I')
			chr_l_actionflag = 'I';
		else if ( chr_l_usermode == 'M')
			chr_l_actionflag = 'M';
		else if ( chr_l_usermode == 'D')
			chr_l_actionflag = 'D';
	}
	/* Added for Billing Fee Upload - Ends */
	if ( ((chr_l_usermode == 'I') || (chr_l_usermode == 'M')) && 
	     (chr_l_actionflag != 'D') ) 
	{
		memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer, "%lf", l_iv_custfee_struct_h->schdl_fee);

		if ( !strlen(chr_l_buffer) )
		{
			APL_DATA_MISSING("Fee", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		if ( l_iv_custfee_struct_h->schdl_fee < 0.0 ) 
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SCHFEE_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( APL_FAILURE == CO_Chk_AccValid((char *)l_iv_custfee_struct_h->client, 'Y',
						NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
						l_debug_info_ptr) )//AIX Migration Changes
		{
			if ( APL_FAILURE == CO_ChkErr(*l_debug_info_ptr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_FND, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			APL_GOBACK_FAIL
		}

		int_l_retstat = 0;

                if ( APL_FAILURE ==
                                IV_Rtv_IVCUSTSETUP((char *)l_iv_custfee_struct_h->client,
                                                  &l_iv_cltsetup_struct, &int_l_retstat,
                                                  l_debug_info_ptr) )//AIX Migration Changes
                {
                        if ( int_l_retstat != IV_COLUMN_NULL_ERR )
                        {
                                APL_GOBACK_FAIL
                        }
                }

                if ( l_iv_cltsetup_struct.stat_ind == 'D' )
                {
                        CO_InsertErr(l_debug_info_ptr, ERR_ACCOUNT_MARKEDFORDEL,
                                       APL_NULL_STRING, APL_NULL_STRING,
                                       APL_NULL_STRING, __LINE__, __FILE__);

                        APL_GOBACK_FAIL
                }

		

		switch( l_iv_custfee_struct_h->service_cd )
		{
			

			case MAXFEECODE:
			case MINFEECODE:
			case OVERBILLING:
			case UNDERBILLING:
			case SPECIALBILLING:
			case EXCESSCREDITFEE:
					     CO_InsertErr(l_debug_info_ptr, 
							    ERR_INVALID_SERVCODE, 
							    APL_NULL_STRING, 
							    APL_NULL_STRING, 
							    APL_NULL_STRING, 
							    __LINE__, __FILE__);

					     APL_GOBACK_FAIL

			default:
				 break;
		}

		int_l_retstat = 0;

                if ( APL_FAILURE ==
                        IV_Rtv_IVSRVCHRGDel(l_iv_custfee_struct_h->service_cd, &l_iv_serv_mast_struct, 
					 &int_l_retstat, l_debug_info_ptr) )
                {
			

			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
                        else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
                        {
                                CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			        APL_GOBACK_FAIL
                        }
		}

		int_l_retstat = 0;

		Alert(" apl_frm_date : %s",l_iv_custfee_struct_h->apl_frm_date);

		if ( (chr_l_actionflag != 'D') && 
		     (APL_FAILURE == IV_ChkServDepncy(l_iv_custfee_struct_h->client, 
						       l_iv_custfee_struct_h->service_cd, 
							   l_iv_custfee_struct_h->apl_frm_date, 
						       &int_l_retstat, 
						       l_debug_info_ptr)) )
		{
			if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				char chr_l_buffer[BUFFER_LEN];

				memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);

				sprintf(chr_l_buffer, "%ld", l_iv_custfee_struct_h->service_cd);

				CO_InsertErr(l_debug_info_ptr, ERR_SERVDEP_NOTFND, 
					       chr_l_buffer,  APL_NULL_STRING, 
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			APL_GOBACK_FAIL
		}

		int_l_retstat = 0;

		Alert(" apl_frm_date : %s",l_iv_custfee_struct_h->apl_frm_date);

		if ( (chr_l_actionflag != 'D') &&
		     (APL_FAILURE == IV_Chk_Basis(l_iv_custfee_struct_h->client, 
						  l_iv_custfee_struct_h->service_cd, l_iv_custfee_struct_h->apl_frm_date, /*added by Monica for ISKB_1737*/
						  &int_l_retstat, l_debug_info_ptr)) )
		{
			if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				char chr_l_buffer[BUFFER_LEN];

				memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);

				sprintf(chr_l_buffer, "%ld", l_iv_custfee_struct_h->service_cd);

				CO_InsertErr(l_debug_info_ptr, ERR_SRVBASIS_NOTFND, 
					       chr_l_buffer, APL_NULL_STRING, 
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			APL_GOBACK_FAIL
		}

		

		if ( chr_l_actionflag != 'D' )
		{
			int_l_retstat = IV_SUCCESS;

			if ( APL_FAILURE == IV_ChkParamVal(l_iv_custfee_struct_h->client, 
							  l_iv_custfee_struct_h->service_cd,l_iv_custfee_struct_h->apl_frm_date, /*added by Monica for ISKB_1737*/
							  l_iv_custfee_struct_h->proc_data_val,
							  &int_l_retstat, 
							  l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}

	} 

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Mod_IVBCUSTSETUPLockRow(l_iv_custfee_struct_h->client, 
					 l_iv_custfee_struct_h->bcustsetup_access_stamp, 
					 &int_l_retstat, l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	strcpy(l_iv_clientfee_struct_hc.client, l_iv_custfee_struct_h->client);
	l_iv_clientfee_struct_hc.service_cd = l_iv_custfee_struct_h->service_cd;
	l_iv_clientfee_struct_hc.frm_cbase = l_iv_custfee_struct_h->frm_cbase;
	l_iv_clientfee_struct_hc.frm_fbase = l_iv_custfee_struct_h->frm_fbase;
	if ( strcmp(p_intl_envdatastruct_h->h_process,"U")==0)
	    l_iv_clientfee_struct_hc.toc_base = l_iv_custfee_struct_h->toc_base;
	else
	l_iv_clientfee_struct_hc.toc_base = 0;
	l_iv_clientfee_struct_hc.tof_base = 0;
	l_iv_clientfee_struct_hc.service_stat = NULL;
	strcpy(l_iv_clientfee_struct_hc.apl_frm_date, l_iv_custfee_struct_h->apl_frm_date);

	Alert(" apl_frm_date : %s",l_iv_clientfee_struct_hc.apl_frm_date);

	if ( strlen(l_iv_custfee_struct_h->proc_data_val) )
	{
		strcpy(l_iv_clientfee_struct_hc.proc_data_val, l_iv_custfee_struct_h->proc_data_val);
		strcpy(l_iv_clientfee_struct_hc.group_id, l_iv_custfee_struct_h->group_id);
	}
	else
	{
		strcpy(l_iv_clientfee_struct_hc.proc_data_val, APL_NULL_STRING);
		strcpy(l_iv_clientfee_struct_hc.group_id, APL_NULL_STRING);
	}

	

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		l_iv_clientfee_struct_hc.schdl_fee = l_iv_custfee_struct_h->schdl_fee;
	}
	else
	{
		l_iv_clientfee_struct_hc.schdl_fee = 0;
	}

	l_iv_clientfee_struct_hc.fee_type=l_iv_custfee_struct_h->fee_type; /*** vinay ****/

	

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( chr_l_actionflag == 'I' )
		{
			int_l_retstat = 0;

			

			
			
			if ( APL_FAILURE == IV_Mod_NewIVCUSTFEE(&l_iv_clientfee_struct_hc,&l_intl_env_datastruct_h,&int_l_retstat,l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
		else if ( chr_l_actionflag == 'M' )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == IV_Mod_IVCUSTFEEChg(&l_iv_clientfee_struct_hc, 
							    &int_l_retstat, 
							    l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
		else if ( chr_l_actionflag == 'D' )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_DelIVCUSTFEEMarkSlab(&l_iv_clientfee_struct_hc, &int_l_retstat,
							l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_FEE_SLAB_NOTFND, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);
				}

				APL_GOBACK_FAIL
			}

			int_l_retstat = 0;

			if (APL_FAILURE == 
				IV_PurgeSlabSpecial(l_iv_clientfee_struct_hc.client,l_iv_clientfee_struct_hc.apl_frm_date,
						      &int_l_retstat, l_debug_info_ptr))    /* Added apl_frm_date by monica for kotak ISKB_1737 */
			{
				APL_GOBACK_FAIL
			}

		} 
	}
	else if ( chr_l_usermode == 'D' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_DelIVCUSTFEEMarkSlab(&l_iv_clientfee_struct_hc, 
							    &int_l_retstat, 
							    l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_FEE_SLAB_NOTFND, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			APL_GOBACK_FAIL
		}

        /* Added for Billing Fee Upload - Starts */
		if (strcmp(p_intl_envdatastruct_h->h_process,"U")==0)
		{
			int_l_retstat = 0;
			Alert("PPD: calling IV_PurgeSlabSpecial func for permanant delete");
			
			if (APL_FAILURE == 
				IV_PurgeSlabSpecial(l_iv_clientfee_struct_hc.client,l_iv_clientfee_struct_hc.apl_frm_date, 
							  &int_l_retstat, l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}
		}
		/* Added for Billing Fee Upload - Ends */
		
		memset(l_intl_env_datastruct_h.h_mode, APL_NULL_CHAR, 4);

		strcpy(l_intl_env_datastruct_h.h_mode, APL_FUNC_MODIFY);

	     
	}

	/* Added for Billing Fee Upload - Starts */
	if( strcmp(p_intl_envdatastruct_h->h_process,"U") != 0)
	{
	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Mod_IVCUSTSETUPMkrChkr(l_iv_custfee_struct_h->client, 
				     l_iv_custfee_struct_h->bcustsetup_access_stamp, 
				     &l_intl_env_datastruct_h, &int_l_retstat, l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}
	}
	/* Added for Billing Fee Upload - Ends */

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of IV_Upd_CustFeeMnt()\n", 
                     (DEBUG_INFO_STRUCT_H **)NULL, &l_intl_env_datastruct_h); //AIX Warning Removal Changes
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of IV_Upd_CustFeeMnt().\n", 
                     (DEBUG_INFO_STRUCT_H **)NULL , &l_intl_env_datastruct_h);//AIX Warning Removal Changes
		}

		return APL_FAILURE;
}
