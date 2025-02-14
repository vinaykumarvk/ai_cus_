




#define PURE_C_SOURCE

#include "stdio_64.h"
#include <string.h> 
#include <stdlib.h> 
#include "IV_Control_A.h"
#include "IV_Control.h"


//AIX - Warnings Removal
int IV_Upd_CustMnt( IV_CLIENTPARAM_STRUCT *l_iv_clientparam_struct, 
	        INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
	       DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *chr_p_param_str)
{
	

	int IV_Chk_APACode(char *l_apacode, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);//AIX - Warnings Removal

	/*extern int IV_Rtv_MastAcc(const char *chr_l_client, char *chr_l_mstacc, */
	extern int IV_Rtv_MastAcc(char *chr_l_client, char *chr_l_mstacc, 
				 int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client, 
				     const IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_Bill_FrmGendt_DlvDt(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int CO_Chk_AccValid(char *chr_l_client, char int_l_exist, char l_cubk, 
			       char l_orderac, char l_mastclt, char l_auth, 
			       char l_del, char l_frozen, char l_closed, 
			       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int GDBValCcy(char *l_blccycode, char l_type, char int_l_exist, 
			     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkIsMasterBillable(const char *chr_l_client, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkRecAcc(const char *l_blccycode, const char *chr_l_recacc, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkCommAcc(const char *chr_l_client, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkUpdBICcy(const char *chr_l_client, int *int_l_retstat, 
				  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_ChkCanDelAccount(const char *chr_l_client, int *int_l_retstat, 
				   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCUSTSETUPMkrChkr(const char *chr_l_client, 
					const char *l_access_stamp, 
					const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPNew(const IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPChg(const IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
				     int *int_l_retstat, 
				     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPLockRow(const char *chr_l_client, 
					 const char *l_access_stamp, 
					 int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCUSTPARAMAllServ(const char *chr_l_client, 
					    int *int_l_retstat, 
					    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_DelIVCSTFEEAnySlabIsExist(const char *chr_l_client, 
					       int *int_l_retstat, 
					       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVSRVBasisAllServDel(const char *chr_l_client, 
					   int *int_l_retstat, 
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETPAccDel(const char *chr_l_client, 
					    const char *l_access_stamp, 
					    const char l_markorpurge, 
					    int *int_l_retstat, 
					    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Chk_OblgDet(const char *chr_l_client, 
			const char *chr_mast_grp_acc, 
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


	

	char chr_l_purgeacc = 'N', chr_l_newrecord = 'N';
	char chr_l_ismstacc, chr_l_betgenanddlvdt, chr_l_usermode;
	char chr_l_buffer[BUFFER_LEN], chr_l_mstacc[APL_CLIENT_LENGTH];
	char chr_l_actionflag = NULL, chr_l_sys_date[APL_DATE_LEN];
	int int_l_retstat = 0;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;
	IV_CLIENTSETUP_STRUCT l_iv_clientsetup_struct_new;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_mast_struct; /* Bageshri For Obligation Level validation */
	short int_l_cond_exists = 0;
	short l_IBBSCondExists=0;  
   char chr_l_supermstacc[APL_CLIENT_LENGTH];	/* Super Master Account ST1.0 */	

   char l_setup_client[APL_CLIENT_LENGTH] = APL_NULL_STRING;

	memset(chr_l_mstacc, APL_NULL_CHAR, APL_CLIENT_LENGTH);

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
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE) )
	{
		chr_l_usermode = 'A';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET) )
	{
		chr_l_usermode = 'R';
	}


	Alert("chr_l_usermode :|%c|\n",chr_l_usermode);

	if ( !strlen(l_iv_clientparam_struct->client) )	
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING)
	}
	/* Added for Client Billing Setup Upload * - Start */
	if(!strcmp(p_intl_envdatastruct_h->h_process,"U"))
	{
		if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
		  chr_l_usermode = 'I';
		else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
		  chr_l_usermode = 'M';
		else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
		  chr_l_usermode = 'D';
	}
	/* Added for Client Billing Setup Upload - End */

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( !strlen(l_iv_clientparam_struct->b_ccycd) )	
		{
			APL_DATA_MISSING("Billing Currency Code", 
					  APL_NULL_STRING, APL_NULL_STRING)
		}

		if ( !strlen(l_iv_clientparam_struct->fees_ccy) ) 
		{
			APL_DATA_MISSING("Fee Currency Code", 
					  APL_NULL_STRING, APL_NULL_STRING)
		}

		if ( (l_iv_clientparam_struct->send_to_master_ind  != 'M') &&
		     (l_iv_clientparam_struct->send_to_master_ind != 'S')&&
		     (l_iv_clientparam_struct->send_to_master_ind != 'G') )	
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SNDVAL_S_M, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		if ( (l_iv_clientparam_struct->b_gen_ind != 'M') && 
		     (l_iv_clientparam_struct->b_gen_ind != 'S') )	
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLTO_SORM, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer, "%lf", l_iv_clientparam_struct->minimumfee);

		if ( !strlen(chr_l_buffer) )
		{
			APL_DATA_MISSING("Minimum Fee", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}
		memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer, "%lf", l_iv_clientparam_struct->maximumfee); /* Bageshri */

		if ( !strlen(chr_l_buffer) )
		{
			APL_DATA_MISSING("Maximum Fee", APL_NULL_STRING,
					APL_NULL_STRING)
		}

		memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer, "%lf", l_iv_clientparam_struct->txnmaxfee); /* Bageshri */

		if ( !strlen(chr_l_buffer) )
		{
			APL_DATA_MISSING("Txn Minimum Fee", APL_NULL_STRING,
					APL_NULL_STRING)
		}

		memset(chr_l_buffer, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer, "%lf", l_iv_clientparam_struct->txnmaxfee); /* Bageshri */

		if ( !strlen(chr_l_buffer) )
		{
			APL_DATA_MISSING("Txn Maximum Fee", APL_NULL_STRING,
					APL_NULL_STRING)
		}
		if ( (l_iv_clientparam_struct->dir_db_ind != 'Y') && 
		     (l_iv_clientparam_struct->dir_db_ind != 'N') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_DIRDR, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		

		if ( !strcmp(l_iv_clientparam_struct->client, 
			     l_mt_core_sys_params_struct_h.custody_clt_cd) && 
		     !strlen(l_iv_clientparam_struct->default_feeclt) )
		{
			APL_DATA_MISSING("Default Fee Acc.", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

	} 

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( (chr_l_usermode == 'M') && !strlen(p_intl_envdatastruct_h->h_process) )
	{
		APL_DATA_MISSING("Action Flag", APL_NULL_STRING, 
				  APL_NULL_STRING)	
	}

	if ( (chr_l_usermode == 'D') || (chr_l_usermode == 'A') || (chr_l_usermode == 'R') || 
	     ((chr_l_usermode == 'M') && 
	      !strcmp(p_intl_envdatastruct_h->h_process, ACTION_MOD_IND)) )
	{
		if ( !strlen(l_iv_clientparam_struct->bcustsetup_access_stamp) )
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( chr_l_usermode == 'M' )
	{
		if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_NEW_IND) )
		{
			chr_l_actionflag = 'I';
		}
		else if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_MOD_IND) )
		{
			chr_l_actionflag = 'M';
		}
	}

	/* Added for Masters Upload - Starts */
	if (strcmp(p_intl_envdatastruct_h->h_process,"U" ) == 0)
	{
		if ( chr_l_usermode == 'I' )
				chr_l_actionflag = 'I';	
		else if ( chr_l_usermode == 'M' )
				chr_l_actionflag = 'M';	
	}
	/* Added  for Masters Upload - Ends */		
		

	if ( (chr_l_usermode == 'I') || 
	     ((chr_l_usermode == 'M') && (chr_l_actionflag == 'I')) )
	{
		chr_l_newrecord = 'Y';
	}


	int_l_retstat = 0;

	Alert("Entering IV_Rtv_MastAcc -- :|%s|\n",l_iv_clientparam_struct->client);

	if ( APL_FAILURE == IV_Rtv_MastAcc(l_iv_clientparam_struct->client, chr_l_mstacc, 
					  &int_l_retstat, l_debug_info_ptr) )
	{
		if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_FND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		}

		APL_GOBACK_FAIL
	}
	else
	{
		if ( !strcmp(l_iv_clientparam_struct->client, chr_l_mstacc) )
		{
			chr_l_ismstacc = 'Y';
			strcpy(chr_l_supermstacc, chr_l_mstacc);	/* Assign Master Account As Super Master Account -- ST1.0 */
		}
		else
		{
			chr_l_ismstacc = 'N';
		
			/* Retrieve Super-Master Account ie Master's Master Account -- ST1.0 */	
			int_l_retstat = 0;

			Alert("Entering IV_Rtv_MastAcc -- :|%s|\n",chr_l_mstacc);

			if ( APL_FAILURE == IV_Rtv_MastAcc(chr_l_mstacc, chr_l_supermstacc,
					  &int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_FND, 
				       chr_l_mstacc, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
				}

				APL_GOBACK_FAIL
			}
		}
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		if ( chr_l_ismstacc == 'Y' )
		{
			if ( (l_iv_clientparam_struct->minimumfee_to != 'Y') &&
			     (l_iv_clientparam_struct->minimumfee_to != 'N') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MINFEE_CONSO_VALID,
					       APL_NULL_STRING, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       __LINE__, __FILE__);
			}
			if ( (l_iv_clientparam_struct->maximumfee_to != 'Y') &&
					(l_iv_clientparam_struct->maximumfee_to != 'N') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MAXFEE_CONSO_VALID,
						APL_NULL_STRING,
						APL_NULL_STRING, APL_NULL_STRING,
						__LINE__, __FILE__);
			}

			if ( l_iv_clientparam_struct->b_gen_ind != 'S' )
			{
				CO_InsertErr(l_debug_info_ptr, 
					       ERR_MSTACC_BILLTYPE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			if ( l_iv_clientparam_struct->send_to_master_ind != 'S' )
			{
				CO_InsertErr(l_debug_info_ptr, 
					       ERR_MSTACC_BILLTYPE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}
		}
		else
		{
			if ( l_iv_clientparam_struct->minimumfee_to != 'N' )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MINCONSO_VALID, 
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING,  __LINE__, 
						__FILE__);
			}
			if ( l_iv_clientparam_struct->maximumfee_to != 'N' )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MAXCONSO_VALID,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING,  __LINE__,
						__FILE__);
			}

			if ( l_iv_clientparam_struct->b_gen_ind == 'M' ) 
			{
				if ( l_iv_clientparam_struct->dir_db_ind != 'N' )
				{
					CO_InsertErr(l_debug_info_ptr, 
							ERR_INVALID_DIRDR, 
							APL_NULL_STRING, 
							APL_NULL_STRING, 
							APL_NULL_STRING, 
							__LINE__, __FILE__);
				}
			}

		} 

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( l_iv_clientparam_struct->b_gen_ind == 'S' )
		{
			if ( (l_iv_clientparam_struct->min_hld_adj != 'Y') && 
					(l_iv_clientparam_struct->min_hld_adj != 'N') )
			{
				CO_InsertErr(l_debug_info_ptr, 
						ERR_MINFEE_HLD_VALID, 
						APL_NULL_STRING, 
						APL_NULL_STRING, 
						APL_NULL_STRING, 
						__LINE__, __FILE__);
			}


		}

		if ( !strcmp(l_iv_clientparam_struct->client,			/* Bageshri HDFCIV_001*/
					l_mt_core_sys_params_struct_h.custody_clt_cd) )
		{
			if ( !strlen(l_iv_clientparam_struct->rec_clt) )
			{
				APL_DATA_MISSING("Receivable Account", 
						APL_NULL_STRING, 
						APL_NULL_STRING)
			}
		}

		if(strcmp(g_mt_commonsys_params_struct_h.nation_code,"IN"))
		{
			if ( !strcmp(l_iv_clientparam_struct->client, 
						l_mt_core_sys_params_struct_h.custody_clt_cd) || 
					(l_iv_clientparam_struct->b_gen_ind == 'S') )
			{
				if ( !strlen(l_iv_clientparam_struct->comm_clt) )
				{
					APL_DATA_MISSING("Commission Account", 
							APL_NULL_STRING, 
							APL_NULL_STRING)
				}
			}

			if ( !strcmp(l_iv_clientparam_struct->client, 
						l_mt_core_sys_params_struct_h.custody_clt_cd) )
			{
				if ( !strlen(l_iv_clientparam_struct->spl_clt_cd) )
				{
					APL_DATA_MISSING("APA Code", APL_NULL_STRING, 
							APL_NULL_STRING)
				}

			}
		}

		else
		{
			if ( (l_iv_clientparam_struct->b_freq != 'A')&&(l_iv_clientparam_struct->b_freq != 'M')&&(l_iv_clientparam_struct->b_freq != 'Q')&&(l_iv_clientparam_struct->b_freq != 'S'))
			{
				APL_DATA_MISSING("Billing Frequency", APL_NULL_STRING, 
						APL_NULL_STRING)
			}

			if ( (l_iv_clientparam_struct->dvp_ind != 'Y') && 
					(l_iv_clientparam_struct->dvp_ind != 'N') )
			{
				APL_DATA_MISSING("DVP Flag", APL_NULL_STRING, 
						APL_NULL_STRING)
			}

			/*if ( (l_iv_clientparam_struct->acc_typ == 'C')&&(l_iv_clientparam_struct->acc_typ == 'E')&&(l_iv_clientparam_struct->acc_typ == 'F')&&(l_iv_clientparam_struct->acc_typ == 'N')&&(l_iv_clientparam_struct->acc_typ == 'R') )
			  {
			  APL_DATA_MISSING("Account Type", APL_NULL_STRING, 
			  APL_NULL_STRING)
			  }*/

		}
		/***************************/
		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

	} 

	

	int_l_retstat = 0;

	strcpy(l_setup_client,l_iv_clientparam_struct->client);

	Alert("Entering IV_Rtv_IVCUSTSETUP :|%s|\n",l_setup_client);

	if ( APL_FAILURE == IV_Rtv_IVCUSTSETUP(l_setup_client, 
					      &l_iv_cltsetup_struct, &int_l_retstat, 
					      l_debug_info_ptr) )
	{
		Alert("Inside Failure Of IV_Rtv_IVCUSTSETUP :|%d|\n",int_l_retstat);

		if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
		{
			APL_GOBACK_FAIL
		}
		else if ( (int_l_retstat == IV_NO_DATA_FOUND_ERR) && 
			  (chr_l_newrecord == 'N') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLPARAM_NOTFND, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		else if ((int_l_retstat == IV_COLUMN_NULL_ERR) && (chr_l_newrecord == 'Y'))
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLPARAM_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_newrecord == 'Y' )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_BILLPARAM_EXISTS, 
			       APL_NULL_STRING, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);

		APL_GOBACK_FAIL
	}

	Alert("Entering IV_Rtv_Bill_FrmGendt_DlvDt \n");

	if ( APL_SUCCESS == IV_Rtv_Bill_FrmGendt_DlvDt(l_debug_info_ptr) )
	{
		chr_l_betgenanddlvdt = 'Y';
	}
	else
	{
		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
		else
		{
			chr_l_betgenanddlvdt = 'N';
		}
	}

     

	if ( chr_l_newrecord == 'N' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == 
			IV_Mod_IVBCUSTSETUPLockRow(l_iv_clientparam_struct->client, 
					 l_iv_clientparam_struct->bcustsetup_access_stamp, 
					 &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		char chr_l_buffer1[BUFFER_LEN];

		
		Alert("Entering CO_Chk_AccValid :|%s|\n",l_setup_client);

		if ( APL_FAILURE == CO_Chk_AccValid(l_setup_client, 'Y', 
					        NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
					        l_debug_info_ptr) )
		{
			if ( APL_FAILURE == CO_ChkErr(*l_debug_info_ptr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_FND, 
					       APL_NULL_STRING, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       __LINE__, __FILE__);
			}

			APL_GOBACK_FAIL
		}

		if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'M') )
		{
			if ( l_iv_cltsetup_struct.stat_ind == 'D' )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCOUNT_MARKEDFORDEL, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		if ( APL_FAILURE == CO_Chk_CcyValid(l_iv_clientparam_struct->b_ccycd, 
						'M', 'Y', l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		

		if ( APL_FAILURE == CO_Chk_CcyValid(l_iv_clientparam_struct->fees_ccy, 
						'M', 'Y', l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( !strcmp(l_iv_clientparam_struct->client, 
			     l_mt_core_sys_params_struct_h.custody_clt_cd) )
		{
			if ( l_iv_clientparam_struct->b_gen_ind != 'S' )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INTRNL_BILLTYPE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			if ( l_iv_clientparam_struct->send_to_master_ind != 'S' )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INTRNL_BILLTYPE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}
		}

		if ( (l_iv_clientparam_struct->b_gen_ind == 'M') || 
		     (l_iv_clientparam_struct->send_to_master_ind == 'M') )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_ChkIsMasterBillable(l_iv_clientparam_struct->client, 
						   &int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_SUCCESS )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_MSTACC_NOTBILL, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);
				}

				APL_GOBACK_FAIL
			}

		} 

		if ( l_iv_clientparam_struct->minimumfee < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE, 
				       "Minimum Fee", APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		
		if ( l_iv_clientparam_struct->maximumfee < 0 )  /* Bageshri */
		{
			CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE,
					"Maximum Fee", APL_NULL_STRING,
					APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		if ( l_iv_clientparam_struct->txnminfee < 0 )  /* Bageshri */
		{
			CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE,
					"Minimum Fee per Txn", APL_NULL_STRING,
					APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( l_iv_clientparam_struct->txnmaxfee < 0 )  /* Bageshri */
		{
			CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE,
					"Maximum Fee per Txn", APL_NULL_STRING,
					APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		/*added by shruthi kumbla for ISKB_1737 start*/
		Alert("Annual min charge |%lf|",l_iv_clientparam_struct->ann_min_chrg);
		Alert("fees_ccy |%s|", l_iv_clientparam_struct->fees_ccy);
		
		if ( l_iv_clientparam_struct->ann_min_chrg < 0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE, 
				       "Annual Minimum Charge", APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		/*added by shruthi kumbla for ISKB_1737 end*/
		if(!strcmp(g_mt_commonsys_params_struct_h.nation_code,"IN"))	/* Bageshri HDFCIV_001*/
		{
		if ( l_iv_clientparam_struct->pay_out_lmt < 0 )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_AMT_CANTNEGATIVE, 
						   "Part Pay Out Amount", APL_NULL_STRING, 
						   APL_NULL_STRING, __LINE__, __FILE__);

				APL_GOBACK_FAIL
			}

		}
	
		/*********** Commented by Bageshri **********************/
		/******* not needed as comm_clt is dropdown type *******/

		/*if ( !strcmp(l_iv_clientparam_struct->client, 
			     l_mt_core_sys_params_struct_h.custody_clt_cd) || 
		     (l_iv_clientparam_struct->b_gen_ind == 'S') )
		{
			int int_l_temp = atoi(l_iv_clientparam_struct->comm_clt);

			int_l_retstat = 0;

			if ( (int_l_temp < 1) || (int_l_temp > 9) || 
			    (APL_FAILURE == IV_ChkCommAcc(l_iv_clientparam_struct->comm_clt,
							  &int_l_retstat, 
							  l_debug_info_ptr)) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INVALID_COMMACC, 
					      APL_NULL_STRING, APL_NULL_STRING, 
					      APL_NULL_STRING, __LINE__, 
					      __FILE__);
			}
		}*/
		/*********************************************************/

      
      if(APL_FAILURE == CO_Chk_CntryEnabled("BILL_ACC_ENTRIES",
                                          "FLEXCUBE_CASHACC",
                                          &l_IBBSCondExists,
                                          l_debug_info_ptr))
      {
         APL_GOBACK_FAIL
      }

      if ( strlen(l_iv_clientparam_struct->rec_clt) && !l_IBBSCondExists )
		{
		  if(strcmp(g_mt_commonsys_params_struct_h.nation_code,"IN"))
			if( strlen(l_iv_clientparam_struct->rec_clt) != APL_CLIENT_LENGTH-1 )	/* Bageshri HDFCIV_001*/
			{
				CO_InsertErr(l_debug_info_ptr,ERR_BILLACC_LEN_10DIGITS,
									APL_NULL_STRING,APL_NULL_STRING,
									APL_NULL_STRING,__LINE__,__FILE__);
				APL_GOBACK_FAIL
			}
	
			int_l_retstat = 0;

			
			int_l_cond_exists = 0;
			if(CO_Chk_CntryEnabled("CBP_MNT",
										"ACREC_IBBS_NO_VAL",
										&int_l_cond_exists,
										l_debug_info_ptr)==APL_FAILURE)
			{
				APL_GOBACK_FAIL
			}
			if(int_l_cond_exists == 0)
 			{
				if(strcmp(g_mt_commonsys_params_struct_h.nation_code,"IN"))	/* Bageshri HDFCIV_001*/
		   	if (APL_FAILURE == 
						 IV_ChkRecAcc(l_iv_clientparam_struct->b_ccycd, 
							      l_iv_clientparam_struct->rec_clt, 
							      &int_l_retstat, l_debug_info_ptr))
				{
					; 
				}
			}
		}

		if ( strlen(l_iv_clientparam_struct->spl_clt_cd) )
		{
			if ( APL_FAILURE == 
					IV_Chk_APACode(l_iv_clientparam_struct->spl_clt_cd, 
						      l_debug_info_ptr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INVALID_APACODE,  
					       APL_NULL_STRING, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       __LINE__, __FILE__);
			}
		}
		/* Bageshri for Obligation Details validation*/
		IF_COND_EXISTS("IV_CLIENT","OBLG_LVL")
		{
			if(!strcmp(l_iv_clientparam_struct->oblg_lvl,"GROUP")||!strcmp(l_iv_clientparam_struct->oblg_lvl,"MASTER"))
			{
				if(!strcmp(l_iv_clientparam_struct->oblg_lvl,"MASTER"))
				{
					int_l_retstat = 0;

				if(!strcmp(l_iv_clientparam_struct->client,chr_l_mstacc))
				{
						CO_InsertErr(l_debug_info_ptr, ERR_MAST_OBLG_LVL_SELF,  
								chr_l_mstacc, 
								APL_NULL_STRING, APL_NULL_STRING,
								__LINE__, __FILE__);

						APL_GOBACK_FAIL

				}

					if ( APL_FAILURE == IV_Rtv_IVCUSTSETUP(chr_l_mstacc, 
								&l_iv_cltsetup_mast_struct, &int_l_retstat, 
								l_debug_info_ptr) )
					{
						if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
						{
							APL_GOBACK_FAIL
						}
						else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR)  
						{
							CO_InsertErr(l_debug_info_ptr, ERR_NO_MAST_BILL_DET, 
									chr_l_mstacc, APL_NULL_STRING, 
									APL_NULL_STRING, __LINE__, __FILE__);

							APL_GOBACK_FAIL
						}
					}

					if ( APL_FAILURE == IV_Chk_OblgDet(l_iv_clientparam_struct->client,
								chr_l_mstacc,
								l_debug_info_ptr) )
					{
						CO_InsertErr(l_debug_info_ptr, ERR_NO_MAST_OBLG_DET,  
								chr_l_mstacc, 
								APL_NULL_STRING, APL_NULL_STRING,
								__LINE__, __FILE__);

						APL_GOBACK_FAIL

					}
				}
				if(!strcmp(l_iv_clientparam_struct->oblg_lvl,"GROUP"))
				{
					int_l_retstat = 0;

				if(!strcmp(l_iv_clientparam_struct->client,chr_l_supermstacc))
				{
						CO_InsertErr(l_debug_info_ptr, ERR_MAST_OBLG_LVL_SELF,  
								chr_l_mstacc, 
								APL_NULL_STRING, APL_NULL_STRING,
								__LINE__, __FILE__);

						APL_GOBACK_FAIL

				}

					if ( APL_FAILURE == IV_Rtv_IVCUSTSETUP(chr_l_supermstacc, 
								&l_iv_cltsetup_mast_struct, &int_l_retstat, 
								l_debug_info_ptr) )
					{
						if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
						{
							APL_GOBACK_FAIL
						}
						else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR)  
						{
							CO_InsertErr(l_debug_info_ptr, ERR_NO_GROUP_BILL_DET, 
									chr_l_supermstacc, APL_NULL_STRING, 
									APL_NULL_STRING, __LINE__, __FILE__);

							APL_GOBACK_FAIL
						}
					}

					if ( APL_FAILURE == IV_Chk_OblgDet(l_iv_clientparam_struct->client,
								chr_l_supermstacc,
								l_debug_info_ptr) )
					{
						CO_InsertErr(l_debug_info_ptr, ERR_NO_GROUP_OBLG_DET,  
								chr_l_supermstacc, 
								APL_NULL_STRING, APL_NULL_STRING,
								__LINE__, __FILE__);

						APL_GOBACK_FAIL

					}
				}
			}
		}
		/**************************** Bageshri END **********************/

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( chr_l_newrecord == 'N' )
		{
			l_iv_clientsetup_struct_new = l_iv_cltsetup_struct;
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.client, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);

			memset(l_iv_clientsetup_struct_new.b_ccycd, APL_NULL_CHAR, 
			       APL_CCYCODE_LEN);

			l_iv_clientsetup_struct_new.send_to_master_ind = NULL;

			l_iv_clientsetup_struct_new.b_gen_ind = NULL;

			l_iv_clientsetup_struct_new.minimumfee = 0.0;
			
			l_iv_clientsetup_struct_new.maximumfee = 0.0;  /* Bageshri */

			l_iv_clientsetup_struct_new.txnminfee = 0.0;  /* Bageshri */

			l_iv_clientsetup_struct_new.txnmaxfee = 0.0;  /* Bageshri */

			memset(l_iv_clientsetup_struct_new.date_of_input, APL_NULL_CHAR, 
			       APL_DATE_LEN);

			l_iv_clientsetup_struct_new.minimumfee_to = NULL;

			l_iv_clientsetup_struct_new.min_hld_adj = NULL;

			l_iv_clientsetup_struct_new.maximumfee_to = NULL;

			l_iv_clientsetup_struct_new.max_hld_adj = NULL;

			memset(l_iv_clientsetup_struct_new.maker, APL_NULL_CHAR, 
			       APL_USERID_LEN);

			memset(l_iv_clientsetup_struct_new.maker_dt, APL_NULL_CHAR, 
			       APL_DATE_LEN);

			memset(l_iv_clientsetup_struct_new.access_stamp, APL_NULL_CHAR, 
			       APL_DATE_LEN);

			l_iv_clientsetup_struct_new.dir_db_ind = NULL;

			l_iv_clientsetup_struct_new.stat_ind = NULL;

			memset(l_iv_clientsetup_struct_new.spl_clt_cd, APL_NULL_CHAR, 7);

			memset(l_iv_clientsetup_struct_new.comm_clt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);

			memset(l_iv_clientsetup_struct_new.rec_clt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL);	/*bageshri */

			memset(l_iv_clientsetup_struct_new.information, APL_NULL_CHAR, 241);

			memset(l_iv_clientsetup_struct_new.default_feeclt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);

			l_iv_clientsetup_struct_new.total_osamount = 0.0;

			memset(l_iv_clientsetup_struct_new.last_pymt_date, APL_NULL_CHAR, 
			       APL_DATE_LEN);

			memset(l_iv_clientsetup_struct_new.last_pymt_ccy, APL_NULL_CHAR, 
			       APL_CCYCODE_LEN);

			l_iv_clientsetup_struct_new.last_pymt_amt = 0.0;

			l_iv_clientsetup_struct_new.last_lost_amt = 0.0;

			memset(l_iv_clientsetup_struct_new.checker, APL_NULL_CHAR, 
			       APL_USERID_LEN);

			memset(l_iv_clientsetup_struct_new.checker_dt, APL_NULL_CHAR, 
			       APL_DATE_LEN);

			l_iv_clientsetup_struct_new.comm_tax_amt = 0.0;

			memset(l_iv_clientsetup_struct_new.fees_ccy, APL_NULL_CHAR, 
			       APL_CCYCODE_LEN); 
			
			memset(l_iv_clientsetup_struct_new.vat_cd, APL_NULL_CHAR, 51); 

			memset(l_iv_clientsetup_struct_new.vat_note, APL_NULL_CHAR, 121); 

			/*****************  Bageshri HDFCIV_001 *******************/

			memset(l_iv_clientsetup_struct_new.oblg_lvl, APL_NULL_CHAR, 21);

			memset(l_iv_clientsetup_struct_new.oblg_typ, APL_NULL_CHAR, 21);

			l_iv_clientsetup_struct_new.pay_in_day = 0;
			l_iv_clientsetup_struct_new.pay_out_day = 0;
			l_iv_clientsetup_struct_new.b_freq = NULL;
			l_iv_clientsetup_struct_new.pay_out_lmt = 0.0;
			l_iv_clientsetup_struct_new.dvp_ind = NULL;
			l_iv_clientsetup_struct_new.acc_typ = NULL;
			l_iv_clientsetup_struct_new.calc_basis = NULL;
			l_iv_clientsetup_struct_new.portfolio_eval = NULL;	
			l_iv_clientsetup_struct_new.nav_ind = NULL;	

			memset(l_iv_clientsetup_struct_new.pay_in_acc, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL);

			memset(l_iv_clientsetup_struct_new.pay_out_acc, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL); 

			memset(l_iv_clientsetup_struct_new.acc_code1, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL); 

			memset(l_iv_clientsetup_struct_new.acc_code2, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL); 

			memset(l_iv_clientsetup_struct_new.acc_code2desc, APL_NULL_CHAR, 
			       66); 
			memset(l_iv_clientsetup_struct_new.oblig_rep_flg, APL_NULL_CHAR, 
			       3);
			memset(l_iv_clientsetup_struct_new.ann_fee_month, APL_NULL_CHAR, 
			       16);
			memset(l_iv_clientsetup_struct_new.cln_supermst, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);
			memset(l_iv_clientsetup_struct_new.bnk_acc, APL_NULL_CHAR,
					APL_CLIENT_LENGTH_GL);
			
			/** Added by YOG on 221206 - Start **/
			
			memset(l_iv_clientsetup_struct_new.bnk_fcy_acc, APL_NULL_CHAR,
					APL_CLIENT_LENGTH_GL);

			/** Added by YOG on 221206 - End **/
			
			memset(l_iv_clientsetup_struct_new.pymt_acc, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL);
			/*****************  Bageshri HDFCIV_001 END *******************/
			/*****************  Bageshri HB_IV_001 START *******************/
			memset(l_iv_clientsetup_struct_new.dir_db_date, APL_NULL_CHAR, 3);
			memset(l_iv_clientsetup_struct_new.b_basis, APL_NULL_CHAR, 4);
			memset(l_iv_clientsetup_struct_new.b_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);

			l_iv_clientsetup_struct_new.rep_pay_in_day = 0;
			l_iv_clientsetup_struct_new.rep_pay_out_day = 0;
			memset(l_iv_clientsetup_struct_new.b_basis_cust, APL_NULL_CHAR, 4);
			/*****************  Bageshri HB_IV_001 END  *******************/
		} 

		strcpy(l_iv_clientsetup_struct_new.client, l_iv_clientparam_struct->client);
		strcpy(l_iv_clientsetup_struct_new.b_ccycd, l_iv_clientparam_struct->b_ccycd);
		strcpy(l_iv_clientsetup_struct_new.fees_ccy, l_iv_clientparam_struct->fees_ccy);
		l_iv_clientsetup_struct_new.send_to_master_ind = l_iv_clientparam_struct->send_to_master_ind;
		l_iv_clientsetup_struct_new.b_gen_ind = l_iv_clientparam_struct->b_gen_ind;
		l_iv_clientsetup_struct_new.minimumfee = l_iv_clientparam_struct->minimumfee;
		strcpy(l_iv_clientsetup_struct_new.maker, p_intl_envdatastruct_h->usr);
		l_iv_clientsetup_struct_new.minimumfee_to = l_iv_clientparam_struct->minimumfee_to;
		l_iv_clientsetup_struct_new.min_hld_adj = l_iv_clientparam_struct->min_hld_adj;
		l_iv_clientsetup_struct_new.dir_db_ind = l_iv_clientparam_struct->dir_db_ind;

		/****************** Bageshri HDFCIV_001 ***********************/
		strcpy(l_iv_clientsetup_struct_new.oblg_lvl, l_iv_clientparam_struct->oblg_lvl);
		strcpy(l_iv_clientsetup_struct_new.oblg_typ, l_iv_clientparam_struct->oblg_typ);
		l_iv_clientsetup_struct_new.pay_in_day = l_iv_clientparam_struct->pay_in_day;
		l_iv_clientsetup_struct_new.pay_out_day = l_iv_clientparam_struct->pay_out_day;
		l_iv_clientsetup_struct_new.b_freq = l_iv_clientparam_struct->b_freq;
		l_iv_clientsetup_struct_new.dvp_ind = l_iv_clientparam_struct->dvp_ind;
		l_iv_clientsetup_struct_new.acc_typ = l_iv_clientparam_struct->acc_typ;
		l_iv_clientsetup_struct_new.calc_basis = l_iv_clientparam_struct->calc_basis;
		l_iv_clientsetup_struct_new.portfolio_eval = l_iv_clientparam_struct->portfolio_eval;
		l_iv_clientsetup_struct_new.nav_ind = l_iv_clientparam_struct->nav_ind;
		l_iv_clientsetup_struct_new.maximumfee = l_iv_clientparam_struct->maximumfee; 
		l_iv_clientsetup_struct_new.maximumfee_to = l_iv_clientparam_struct->maximumfee_to;
		l_iv_clientsetup_struct_new.max_hld_adj = l_iv_clientparam_struct->max_hld_adj;
		l_iv_clientsetup_struct_new.txnminfee = l_iv_clientparam_struct->txnminfee;
		l_iv_clientsetup_struct_new.txnmaxfee = l_iv_clientparam_struct->txnmaxfee;
		l_iv_clientsetup_struct_new.rep_pay_in_day = l_iv_clientparam_struct->rep_pay_in_day;
		l_iv_clientsetup_struct_new.rep_pay_out_day = l_iv_clientparam_struct->rep_pay_out_day;
		l_iv_clientsetup_struct_new.ann_min_chrg = l_iv_clientparam_struct->ann_min_chrg;/*added by shruthi kumbla for ISKB_1737*/

		/*************************************************/

	/* Added for Client Billing Setup Upload - Start */	
		if(!strcmp(p_intl_envdatastruct_h->h_process,"U"))
	{
			  l_iv_clientsetup_struct_new.stat_ind = 'A';
	
			CO_Rtv_DataString(chr_p_param_str,"CHECKER",l_iv_clientsetup_struct_new.checker);
			CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",l_iv_clientsetup_struct_new.checker_dt);
			CO_Rtv_DataString(chr_p_param_str,"MAKER",l_iv_clientsetup_struct_new.maker);
			CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",l_iv_clientsetup_struct_new.maker_dt);
			
	}	
	/* Added for Client Billing Setup Upload - End */	
	

		if ( chr_l_newrecord == 'Y' )
		{
			l_iv_clientsetup_struct_new.total_osamount = 0.0;

			l_iv_clientsetup_struct_new.last_pymt_amt = 0.0;

			l_iv_clientsetup_struct_new.last_lost_amt = 0.0;
		
			strcpy(l_iv_clientsetup_struct_new.cln_supermst, chr_l_supermstacc);/* ST1.0 */
		}

		if ( strlen(l_iv_clientparam_struct->spl_clt_cd) )
		{
			strcpy(l_iv_clientsetup_struct_new.spl_clt_cd, 
			       l_iv_clientparam_struct->spl_clt_cd);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.spl_clt_cd, APL_NULL_CHAR, 7);

			
		}

		if ( strlen(l_iv_clientparam_struct->comm_clt) )
		{
			strcpy(l_iv_clientsetup_struct_new.comm_clt, l_iv_clientparam_struct->comm_clt);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.comm_clt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);

			
		}

		if ( strlen(l_iv_clientparam_struct->rec_clt) )
		{
			strcpy(l_iv_clientsetup_struct_new.rec_clt, l_iv_clientparam_struct->rec_clt);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.rec_clt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH_GL);	/* Bageshri HDFCIV_001*/
			
		}

		if ( strlen(l_iv_clientparam_struct->information) )
		{
			strcpy(l_iv_clientsetup_struct_new.information, 
			       l_iv_clientparam_struct->information);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.information, APL_NULL_CHAR, 241);

			
		}
		

		if ( strlen(l_iv_clientparam_struct->vat_cd) )
		{
			strcpy(l_iv_clientsetup_struct_new.vat_cd, 
			       l_iv_clientparam_struct->vat_cd);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.vat_cd, APL_NULL_CHAR, 51);

		}

		if ( strlen(l_iv_clientparam_struct->vat_note) )
		{
			strcpy(l_iv_clientsetup_struct_new.vat_note, 
			       l_iv_clientparam_struct->vat_note);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.vat_note, APL_NULL_CHAR, 121);

		}
		

		if ( strlen(l_iv_clientparam_struct->default_feeclt) )
		{
			strcpy(l_iv_clientsetup_struct_new.default_feeclt, 
			       l_iv_clientparam_struct->default_feeclt);

			

			int_l_retstat = IV_SUCCESS;

			if ( APL_FAILURE == 
				IV_ChkDelFeeAcc(l_iv_clientparam_struct->client, 
						l_iv_clientparam_struct->default_feeclt, 
						&int_l_retstat, l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_DFLT_FEEACC_NOTFND, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);

					APL_GOBACK_FAIL

					
				}

				APL_GOBACK_FAIL
			}
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.default_feeclt, APL_NULL_CHAR, 
			       APL_CLIENT_LENGTH);

			
		}

		sprintf(chr_l_buffer1, "%lf", l_iv_clientparam_struct->comm_tax_amt);

		if ( !strlen(chr_l_buffer1) )
		{
			l_iv_clientsetup_struct_new.comm_tax_amt = 0.0;
		}
		else
		{
			l_iv_clientsetup_struct_new.comm_tax_amt = l_iv_clientparam_struct->comm_tax_amt;
		}

		/******************  Bageshri HDFCIV_001 *************/

		if ( strlen(l_iv_clientparam_struct->oblg_lvl) )
		{
			strcpy(l_iv_clientsetup_struct_new.oblg_lvl, 
			       l_iv_clientparam_struct->oblg_lvl);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.oblg_lvl, APL_NULL_CHAR, 21);

		}
		if ( strlen(l_iv_clientparam_struct->oblg_typ) )
		{
			strcpy(l_iv_clientsetup_struct_new.oblg_typ, 
			       l_iv_clientparam_struct->oblg_typ);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.oblg_typ, APL_NULL_CHAR, 21);

		}
		sprintf(chr_l_buffer1, "%lf", l_iv_clientparam_struct->pay_out_lmt);

		if ( !strlen(chr_l_buffer1) )
		{
			l_iv_clientsetup_struct_new.pay_out_lmt = 0.0;		}
		else
		{
			l_iv_clientsetup_struct_new.pay_out_lmt = l_iv_clientparam_struct->pay_out_lmt;
		}

		if ( strlen(l_iv_clientparam_struct->pay_in_acc) )
		{
			strcpy(l_iv_clientsetup_struct_new.pay_in_acc, 
			       l_iv_clientparam_struct->pay_in_acc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.pay_in_acc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

			
		}
		if ( strlen(l_iv_clientparam_struct->pay_out_acc) )
		{
			strcpy(l_iv_clientsetup_struct_new.pay_out_acc, 
			       l_iv_clientparam_struct->pay_out_acc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.pay_out_acc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

			
		}
		if ( strlen(l_iv_clientparam_struct->acc_code1) )
		{
			strcpy(l_iv_clientsetup_struct_new.acc_code1, 
			       l_iv_clientparam_struct->acc_code1);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.acc_code1, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

			
		}
		if ( strlen(l_iv_clientparam_struct->acc_code2) )
		{
			strcpy(l_iv_clientsetup_struct_new.acc_code2, 
			       l_iv_clientparam_struct->acc_code2);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.acc_code2, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);

			
		}
		if ( strlen(l_iv_clientparam_struct->acc_code2desc) )
		{
			strcpy(l_iv_clientsetup_struct_new.acc_code2desc, 
			       l_iv_clientparam_struct->acc_code2desc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.acc_code2desc, APL_NULL_CHAR, 66);

			
		}
			if ( strlen(l_iv_clientparam_struct->oblig_rep_flg) )
		{
			strcpy(l_iv_clientsetup_struct_new.oblig_rep_flg, 
			       l_iv_clientparam_struct->oblig_rep_flg);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.ann_fee_month, APL_NULL_CHAR, 16);
		}

		if ( strlen(l_iv_clientparam_struct->ann_fee_month) )
		{
			strcpy(l_iv_clientsetup_struct_new.ann_fee_month, 
			       l_iv_clientparam_struct->ann_fee_month);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.ann_fee_month, APL_NULL_CHAR, 16);
		}

		if ( strlen(l_iv_clientparam_struct->cln_supermst) )
		{
			strcpy(l_iv_clientsetup_struct_new.cln_supermst, 
			       l_iv_clientparam_struct->cln_supermst);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.cln_supermst, APL_NULL_CHAR,APL_CLIENT_LENGTH);
		}

		if ( strlen(l_iv_clientparam_struct->bnk_acc) )
		{
			strcpy(l_iv_clientsetup_struct_new.bnk_acc,
					l_iv_clientparam_struct->bnk_acc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.bnk_acc, APL_NULL_CHAR,APL_CLIENT_LENGTH_GL);
		}

		/*** Added by YOG for BNK_FCY_ACC maintainance for WebModule on 221206 - Start ***/
		
		if ( strlen(l_iv_clientparam_struct->bnk_fcy_acc) )
		{
		
			strcpy(l_iv_clientsetup_struct_new.bnk_fcy_acc,
					l_iv_clientparam_struct->bnk_fcy_acc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.bnk_fcy_acc, APL_NULL_CHAR,APL_CLIENT_LENGTH_GL);
		}

		/*** Added by YOG for BNK_FCY_ACC maintainance for WebModule on 221206 - End ***/
		
		
		if ( strlen(l_iv_clientparam_struct->pymt_acc) )
		{
			strcpy(l_iv_clientsetup_struct_new.pymt_acc, 
			       l_iv_clientparam_struct->pymt_acc);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.pymt_acc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
		}

		/*****************  Bageshri HDFCIV_001 END *******************/
		/*****************  Bageshri HB_IV_001 START *******************/
		if ( strlen(l_iv_clientparam_struct->dir_db_date) )
		{
			strcpy(l_iv_clientsetup_struct_new.dir_db_date, 
			       l_iv_clientparam_struct->dir_db_date);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.dir_db_date, APL_NULL_CHAR, 3);
		}
		if ( strlen(l_iv_clientparam_struct->b_basis) )
		{
			strcpy(l_iv_clientsetup_struct_new.b_basis, 
			       l_iv_clientparam_struct->b_basis);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.b_basis, APL_NULL_CHAR, 4);
		}
		if ( strlen(l_iv_clientparam_struct->b_dlv_date) )
		{
			strcpy(l_iv_clientsetup_struct_new.b_dlv_date, 
			       l_iv_clientparam_struct->b_dlv_date);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.b_dlv_date, APL_NULL_CHAR, APL_DATE_LEN);
		}
		if ( strlen(l_iv_clientparam_struct->b_basis_cust) )
		{
			strcpy(l_iv_clientsetup_struct_new.b_basis_cust, 
			       l_iv_clientparam_struct->b_basis_cust);
		}
		else
		{
			memset(l_iv_clientsetup_struct_new.b_basis_cust, APL_NULL_CHAR, 4);
		}
		/*****************  Bageshri HB_IV_001 END *******************/

		if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'M') )
		{
			if ( !strcmp(l_iv_cltsetup_struct.last_pymt_date, " ") )
			{
				memset(l_iv_clientsetup_struct_new.last_pymt_date, 
				       APL_NULL_CHAR, APL_DATE_LEN);
			}

			if ( !strcmp(l_iv_cltsetup_struct.last_pymt_ccy, " ") )
			{
				memset(l_iv_clientsetup_struct_new.last_pymt_ccy, 
				       APL_NULL_CHAR, APL_CCYCODE_LEN);
			}

			if ( !strcmp(l_iv_cltsetup_struct.checker, " ") )
			{
				memset(l_iv_clientsetup_struct_new.checker, 
				       APL_NULL_CHAR, 15);/*modified by shruthi kumbla for ISKB_1737 as fees_ccy value was changing to null */
			}

			if ( !strcmp(l_iv_cltsetup_struct.checker_dt, " ") )
			{
				memset(l_iv_clientsetup_struct_new.checker_dt, 
				       APL_NULL_CHAR, APL_DATE_LEN);
			}

		} 

	} 

	if ( chr_l_newrecord == 'Y' )
	{
		int_l_retstat = 0;
                /* Added for Client Billing Setup Upload * - Start */ 
	        if (strcmp(p_intl_envdatastruct_h->h_process,"U"))
                {
                    l_iv_clientsetup_struct_new.stat_ind = 'U';
                    strcpy(l_iv_clientsetup_struct_new.checker, APL_NULL_STRING);
                    strcpy(l_iv_clientsetup_struct_new.checker_dt, APL_NULL_STRING);
                }
                /* Added for Client Billing Setup Upload - End */

		if (APL_FAILURE == IV_Mod_IVBCUSTSETUPNew(&l_iv_clientsetup_struct_new, 
						     &int_l_retstat, l_debug_info_ptr))
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'M') )
	{
		

		if ( l_iv_cltsetup_struct.stat_ind == 'D' )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ACCOUNT_MARKEDFORDEL, 
				       l_iv_cltsetup_struct.client, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( strcmp(l_iv_clientsetup_struct_new.b_ccycd, 
			    l_iv_cltsetup_struct.b_ccycd) 
		  || strcmp(l_iv_clientsetup_struct_new.fees_ccy, 
			    l_iv_cltsetup_struct.fees_ccy) ) 
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == 
					IV_ChkUpdBICcy(l_iv_clientparam_struct->client, 
						     &int_l_retstat, l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}

		

		if ( (l_iv_cltsetup_struct.dir_db_ind == 'N') &&
		     (l_iv_clientsetup_struct_new.dir_db_ind == 'Y') )
		{
			if ( l_iv_cltsetup_struct.total_osamount > 0.0 )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_DIRDR_NALLOW_FORACC_OSAMT, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		if ( chr_l_betgenanddlvdt == 'Y' )
		{
			if ( (l_iv_clientsetup_struct_new.send_to_master_ind != 
						l_iv_cltsetup_struct.send_to_master_ind) || 
			     (l_iv_clientsetup_struct_new.b_gen_ind != 
						l_iv_cltsetup_struct.b_gen_ind) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BTWNGENDELV_CANTCHG_BILLSND, 
				               APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
			else if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVBCUSTSETUPChg(&l_iv_clientsetup_struct_new,
						      &int_l_retstat, 
						      l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}

			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'D' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_ChkCanDelAccount(l_iv_clientparam_struct->client, 
						    &int_l_retstat, 
						    l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == 
				IV_Mod_IVBCUSTSETPAccDel(l_iv_clientparam_struct->client, 
					l_iv_clientparam_struct->bcustsetup_access_stamp, 
					'M', &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'A' )
	{
		

		if ( l_iv_cltsetup_struct.stat_ind == 'A' )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_MSG_ACCOUNT_AUTH, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		/* Added for Client Billing Setup Upload * - Start */
                if (strcmp(p_intl_envdatastruct_h->h_process,"U" ) != 0)
                {
		if ( !strcmp(l_iv_cltsetup_struct.maker, p_intl_envdatastruct_h->usr) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
                 }
                 /* Added for Client Billing Setup Upload - End */

		if ( l_iv_cltsetup_struct.stat_ind == 'D' )
		{
			chr_l_purgeacc = 'Y';

		     

			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_IVCUSTPARAMAllServ(l_iv_clientparam_struct->client, 
						 	 &int_l_retstat, 
						 	 l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
				{
					APL_GOBACK_FAIL
				}
			}

			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_IVSRVBasisAllServDel(l_iv_cltsetup_struct.client, 
							&int_l_retstat, 
							l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
				{
					APL_GOBACK_FAIL
				}
			}

			int_l_retstat = 0;

			if ( APL_FAILURE == 
				IV_Mod_IVBCUSTSETPAccDel(l_iv_cltsetup_struct.client, 
						l_iv_cltsetup_struct.access_stamp, 
						'P', &int_l_retstat, l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
		else if ( l_iv_cltsetup_struct.stat_ind == 'U' )
		{
			

			

			


		}
	}
	else if ( chr_l_usermode == 'R' )
	{

		if ( l_iv_cltsetup_struct.stat_ind == 'U' )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ACCNOT_MARKEDFORDEL, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		if ( !strcmp(l_iv_cltsetup_struct.maker, p_intl_envdatastruct_h->usr) )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	}

	if ( (chr_l_newrecord == 'N') && (chr_l_purgeacc == 'N') )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == 
				IV_Mod_IVCUSTSETUPMkrChkr(l_iv_clientparam_struct->client, 
					l_iv_clientparam_struct->bcustsetup_access_stamp, 
					p_intl_envdatastruct_h, &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Upd_CustMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
 IV_Upd_CustMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}


int IV_Chk_APACode(char *p_apa_code, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) //AIX - Warnings Removal
{
	if ( strlen(p_apa_code) == 6 )
	{
		APL_GOBACK_SUCCESS
	}
	else
	{
		APL_GOBACK_FAIL
	}

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Chk_APACode().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
 IV_Chk_APACode().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
