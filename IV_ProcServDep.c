




#define PURE_C_SOURCE

#include "stdio_64.h"
#include <string.h> 
#include <stdlib.h>
#include <sqlca.h>
#include "IV_Control_A.h"
#include "IV_Control.h"



int IV_CustServDepncy(const IV_CLIENTSERVDEP_STRUCT_H *p_iv_clientservdep_struct_h, 
		      const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		      DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Chk_FeeChargeType(const long l_servcode, 
					   const char *l_chargebasis, 
					   const char *l_feebasis, 
					   const char l_chargetype, 
					   const char l_feetype, 
					   int *int_l_retstat, 
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int CO_Chk_AccValid(char *p_client, char p_exist, char p_cubk, 
			       char p_orderac, char p_mastclt, char p_auth, 
			       char p_del, char p_frozen, char p_closed, 
			       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVSRVCHRGDel(long p_serv_code, 
				IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_c, 
				int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client, 
				     IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_AddNewCustServDet(
				const IV_CLIENTSERVDEP_STRUCT_H *l_iv_clientservdep_struct_h,
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_ChgCustServDet(
				const IV_CLIENTSERVDEP_STRUCT_H *l_iv_clientservdep_struct_h,
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_DelCustServDet(const char *chr_l_client, 
				     const long l_servcode, const char *chr_l_apl_frm_date, int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);/*added by monica for ISKB_1737*/

	extern int IV_Mod_IVCUSTSETUPMkrChkr(const char *chr_l_client, 
				const char *l_access_stamp, 
				const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPLockRow(const char *chr_l_client, 
					 const char *l_access_stamp, 
					 int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char  chr_l_actionflag = NULL;
	char chr_l_usermode, chr_l_buffer[BUFFER_LEN];
	int int_l_retstat = 0;
	long l_AdmServCode = 0L;
	//IV_CLIENTSERVDEP_STRUCT_H l_iv_clientservdep_struct_h;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;
	INTL_ENV_DATA_STRUCT_H l_intl_env_datastruct_h = *p_intl_envdatastruct_h;

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}

	

	if ( !strlen(p_iv_clientservdep_struct_h->client) )
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING)
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%ld", p_iv_clientservdep_struct_h->service_cd);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("Service Code", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}

	
	if ( (!strcmp(p_intl_envdatastruct_h->h_process, ACTION_NEW_IND ) ) || ( !strcmp( p_intl_envdatastruct_h->h_process, ACTION_MOD_IND) ) )
	{
   	if ((strlen(p_iv_clientservdep_struct_h->dealadm_feeccy)) && (p_iv_clientservdep_struct_h->service_cd != ADM_TXN_FEE_IND))
   	{
      	CO_InsertErr(l_debug_info_ptr, ERR_TXN_FEERR_ONLY_TXN_ADM, APL_NULL_STRING, APL_NULL_STRING, APL_NULL_STRING, __LINE__, __FILE__);
   	}

		
		if ( (p_iv_clientservdep_struct_h->service_cd == ADM_TXN_FEE_IND) && ( !strlen(p_iv_clientservdep_struct_h->dealadm_feeccy)))
		{
				APL_DATA_MISSING("Service Fee Currency for Transaction Adm Fee", APL_NULL_STRING, APL_NULL_STRING)
		}
   }
   fprintf(APL_OUT_FILE, "The chr_value now is : %s",p_iv_clientservdep_struct_h->dealadm_feeccy);
  
   

	if ( (strlen(p_iv_clientservdep_struct_h->fees_base)) && 
	     (strlen(p_iv_clientservdep_struct_h->chrg_base)) )
	{
		if ( (p_iv_clientservdep_struct_h->fees_class != 'S') &&
		     (p_iv_clientservdep_struct_h->fees_class != 'T') )
		{
			APL_DATA_MISSING("Fee Type", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		if ( (p_iv_clientservdep_struct_h->chrg_clas != 'S') &&
			  (p_iv_clientservdep_struct_h->chrg_clas != 'T') )
		{
			APL_DATA_MISSING("Charge Type", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%lf", p_iv_clientservdep_struct_h->minimumfee);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("Minimum Fee", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}
	else if ( p_iv_clientservdep_struct_h->minimumfee < 0.0 )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_MINFEE_GRTR_ZERO, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);	
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%lf", p_iv_clientservdep_struct_h->nil_fees);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("Nil Fee", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}
	else if ( p_iv_clientservdep_struct_h->nil_fees < 0.0 )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_NILFEE_GRTR_ZERO, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);	
	}

	memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
	sprintf(chr_l_buffer, "%lf", p_iv_clientservdep_struct_h->maximum_fee);

	if ( !strlen(chr_l_buffer) )
	{
		APL_DATA_MISSING("Maximum Fee", APL_NULL_STRING, 
				  APL_NULL_STRING)
	}
	else if ( p_iv_clientservdep_struct_h->maximum_fee < 0.0 )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_MAXFEE_GTR_ZERO, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);	
	}

	if ( !strlen(p_iv_clientservdep_struct_h->bcustsetup_access_stamp) )
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
    /* Added for Billing Service Upload - Start */
	if ( strcmp(p_intl_envdatastruct_h->h_process,"U") == 0 )
	{
		if ( chr_l_usermode == 'I' )
			chr_l_actionflag = 'I';
		else if ( chr_l_usermode == 'M' )
			chr_l_actionflag = 'M';
		else if ( chr_l_usermode == 'D' )
			chr_l_actionflag = 'D';
	}
    /* Added for Billing Service Upload - End */	

	

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( APL_FAILURE == CO_Chk_AccValid((char *)p_iv_clientservdep_struct_h->client, 'Y',//AIX - Warnings Removal
						NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
						l_debug_info_ptr) )
		{
			if ( APL_FAILURE == CO_ChkErr(*l_debug_info_ptr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_FND, 
					       (char *)APL_NULL_STRING, //AIX - Warnings Removal
					       (char *)p_iv_clientservdep_struct_h->client, 
					       APL_NULL_STRING, 
					       __LINE__, __FILE__);
			}

			APL_GOBACK_FAIL
		}
		
		int_l_retstat = 0;

		if ( APL_FAILURE == 
				IV_Rtv_IVCUSTSETUP((char *)p_iv_clientservdep_struct_h->client, //AIX - Warnings Removal
						  &l_iv_cltsetup_struct, &int_l_retstat, 
						  l_debug_info_ptr) )
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

		/* HDFCIV001 Bageshri */
		if (strlen(p_iv_clientservdep_struct_h->chrg_base) == 0)
			strcpy((char *)p_iv_clientservdep_struct_h->chrg_base," ");	//AIX - Warnings Removal
		
		if (strlen(p_iv_clientservdep_struct_h->fees_base) == 0)
			strcpy((char *)p_iv_clientservdep_struct_h->fees_base," ");	//AIX - Warnings Removal

		if( ( chr_l_actionflag != 'D' ) &&
		    ( strcmp(p_iv_clientservdep_struct_h->chrg_base," ") != 0 ) && 
		    ( strcmp(p_iv_clientservdep_struct_h->fees_base," ") != 0 ) )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
					IV_Chk_FeeChargeType(
						p_iv_clientservdep_struct_h->service_cd, 
						p_iv_clientservdep_struct_h->chrg_base,
						p_iv_clientservdep_struct_h->fees_base, 
						p_iv_clientservdep_struct_h->chrg_clas, 
						p_iv_clientservdep_struct_h->fees_class, 
						&int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_SUCCESS )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_INVALID_CHRGFEE_TYPE, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);
				}
				else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_INVALID_CHRGFEE_BASIS, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);
				}

				APL_GOBACK_FAIL

			} 

		} 

		switch( p_iv_clientservdep_struct_h->service_cd )
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

		if (APL_FAILURE == 
			IV_Rtv_IVSRVCHRGDel(p_iv_clientservdep_struct_h->service_cd, 
					&l_iv_serv_mast_struct, &int_l_retstat, l_debug_info_ptr))
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
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == 
			IV_Mod_IVBCUSTSETUPLockRow(p_iv_clientservdep_struct_h->client, 
			      p_iv_clientservdep_struct_h->bcustsetup_access_stamp, 
			      &int_l_retstat, l_debug_info_ptr) )	
	{
		APL_GOBACK_FAIL
	}

	

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( chr_l_actionflag == 'I' )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_AddNewCustServDet(p_iv_clientservdep_struct_h, &int_l_retstat,
						  l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
		else if ( chr_l_actionflag == 'M' )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
					IV_Mod_ChgCustServDet(p_iv_clientservdep_struct_h, 
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
				IV_Mod_DelCustServDet(p_iv_clientservdep_struct_h->client, 
						  p_iv_clientservdep_struct_h->service_cd, 
						  p_iv_clientservdep_struct_h->apl_frm_date,/*added by monica for ISKB_1737*/
						  &int_l_retstat, l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}

			

			if ( p_iv_clientservdep_struct_h->service_cd == CUSTODYFEE )
			{
				l_AdmServCode = ADM_CUST_FEE_IND;
			}
			else if ( p_iv_clientservdep_struct_h->service_cd == TXNFEE )
			{
				l_AdmServCode = ADM_TXN_FEE_IND;
			}

			if ( (l_AdmServCode == ADM_CUST_FEE_IND) || 
			     (l_AdmServCode == ADM_TXN_FEE_IND) )
			{
				int_l_retstat = 0;

				if ( APL_FAILURE == IV_Mod_DelCustServDet(
						     p_iv_clientservdep_struct_h->client,
						     l_AdmServCode,p_iv_clientservdep_struct_h->apl_frm_date, &int_l_retstat, /*added by monica for ISKB_1737*/
						     l_debug_info_ptr) )
				{
					

					if ( int_l_retstat != IV_NO_DATA_FOUND_ERR )
					{
						APL_GOBACK_FAIL
					}
				}
			}

		} 
	}
	else if ( chr_l_usermode == 'D' )
	{ 
		int_l_retstat = 0;

		if ( APL_FAILURE == 
				IV_Mod_DelCustServDet(p_iv_clientservdep_struct_h->client, 
						  p_iv_clientservdep_struct_h->service_cd, 
						  p_iv_clientservdep_struct_h->apl_frm_date, /*added by monica for ISKB_1737*/
						  &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		

		

		if ( p_iv_clientservdep_struct_h->service_cd == CUSTODYFEE )
		{
			l_AdmServCode = ADM_CUST_FEE_IND;
		}
		else if ( p_iv_clientservdep_struct_h->service_cd == TXNFEE )
		{
			l_AdmServCode = ADM_TXN_FEE_IND;
		}

		if ( (l_AdmServCode == ADM_CUST_FEE_IND) || 
		     (l_AdmServCode == ADM_TXN_FEE_IND) )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_DelCustServDet(p_iv_clientservdep_struct_h->client, 
						  l_AdmServCode,p_iv_clientservdep_struct_h->apl_frm_date,&int_l_retstat, /*added by monica for ISKB_1737*/
						  l_debug_info_ptr) )
			{
				

				if ( int_l_retstat != IV_NO_DATA_FOUND_ERR )
				{
					APL_GOBACK_FAIL
				}
			}
		}

		memset(l_intl_env_datastruct_h.h_mode, APL_NULL_CHAR, 4);

		strcpy(l_intl_env_datastruct_h.h_mode, APL_FUNC_MODIFY);

	     
	}

	/* Added for Billing Dependency Upload - Starts */
	if( strcmp(p_intl_envdatastruct_h->h_process,"U") != 0)
	{
	int_l_retstat = 0;

	if (APL_FAILURE == 
		IV_Mod_IVCUSTSETUPMkrChkr(p_iv_clientservdep_struct_h->client, 
				 p_iv_clientservdep_struct_h->bcustsetup_access_stamp, 
				 &l_intl_env_datastruct_h, &int_l_retstat, l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}
	}
	/* Added for Billing Dependency Upload - Ends */

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:
//AIX - Warnings Removal
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of IV_CustServDepncy().\n",                              (DEBUG_INFO_STRUCT_H **)NULL, &l_intl_env_datastruct_h);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of IV_CustServDepncy().\n",                                    (DEBUG_INFO_STRUCT_H **)NULL, &l_intl_env_datastruct_h);
		}

		return APL_FAILURE;
}
