




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"
#include "IV_Pymt.h"



int IV_Proc_PymtMnt(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
		  int *p_newseqnum, const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		  DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Chk_PymtDt(const char *l_pymntdate, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client, 
				    IV_CLIENTSETUP_STRUCT *l_iv_clientsetup_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
 
	extern int IV_Chk_CustEntitlement(const IV_CLIENTSETUP_STRUCT *p_iv_clientsetup_struct_a, 
				   int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Chk_PymtAcc(const int l_pymntclt, const char *l_blccycode,
				  int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVSRVCHRGDel(long l_servcode, 
				    IV_SERV_MAST_STRUCT *l_iv_servmast_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_NewCustPymt(const IV_CLIENT_PYMT_STRUCT_H *l_iv_client_pymt_struct_h, 
				   int *int_l_newseqnum, 
				   const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
        
        //shailesh   ISKB_430_08
	extern int IV_Mod_ChgCustPymt(const IV_CLIENT_PYMT_STRUCT_H *l_iv_client_pymt_struct_h, 
				   int *int_l_newseqnum, 		
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_DelCustPymt(const IV_CLIENT_PYMT_STRUCT_H *l_iv_client_pymt_struct_h, 
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_AuthCustPymt(const IV_CLIENT_PYMT_STRUCT_H *l_iv_client_pymt_struct_h,
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int  IV_GetStatus(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
				char *p_status,int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
	

	char chr_l_buffer1[BUFFER_LEN];
	char chr_l_usermode, chr_l_statusflag, chr_l_actionflag;
	int int_l_retstat = 0;
	char l_status ;/*Added by siva.ganapathi for ISKB_2222 on 11-05-2009*/
	IV_CLIENT_PYMT_STRUCT_H l_iv_client_pymt_struct_h = *p_iv_client_pymt_struct_h_a;
	IV_SERV_MAST_STRUCT l_iv_serv_mast_struct;
	IV_CHEQUE_STRUCT l_iv_cheque_struct;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Maker", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	//printf("Mode is %c",p_intl_envdatastruct_h->h_mode); Changes done for AIX Migration
	printf("Mode is %s",p_intl_envdatastruct_h->h_mode);
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

	printf("\n chr_l_usermode is %c",chr_l_usermode);

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		if ( !strlen(p_intl_envdatastruct_h->h_process) )
		{
			APL_DATA_MISSING("Action Flag", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	} 
          printf("IV_ProcPymt.c Amount : |%lf|\n",p_iv_client_pymt_struct_h_a->pymnt_amount);

	/*ST*/
	/*
	printf("IV_ProcPymt.c Account : |%s|\n",p_iv_client_pymt_struct_h_a->client);
	printf("IV_ProcPymt.c Amount : |%lf|\n",p_iv_client_pymt_struct_h_a->pymnt_amount);
	printf("IV_ProcPymt.c Indicator : |%c|\n",p_iv_client_pymt_struct_h_a->h_tot_srv);
	printf("IV_ProcPymt.c Account : |%s|\n",l_iv_client_pymt_struct_h.client);
	printf("IV_ProcPymt.c Amount : |%lf|\n",l_iv_client_pymt_struct_h.pymnt_amount);
	printf("IV_ProcPymt.c Indicator : |%c|\n",l_iv_client_pymt_struct_h.h_tot_srv);
	printf("IV_ProcPymt.c TDS : |%s|\n",p_iv_client_pymt_struct_h_a->tds_amt);
	printf("IV_ProcPymt.c Cheque : |%s|\n",p_iv_client_pymt_struct_h_a->cheque_det);
	*/
	/*Added by siva.ganapathi for ISKB_2222 on 11/05/2009 --- started*/
        printf("\n user mode is ::::: %c",chr_l_usermode);
	printf("\n action is %s",p_intl_envdatastruct_h->h_process);
	if(chr_l_usermode == 'A')
	{
			/*added by siva.ganapathi === To get the status of the record*/
			printf("\n before calling IV_GetStatus() function ");
			if ( APL_FAILURE == IV_GetStatus(&l_iv_client_pymt_struct_h, 
										&l_status,
										&int_l_retstat, 
										l_debug_info_ptr) )
				
			{
					APL_GOBACK_FAIL
			}
			
			printf("\n status of the record is %c",l_status);
	}
        /*Added by siva.ganapathi for ISKB_2222 on 11/05/2009 --- Ended*/

	if ( !strlen(l_iv_client_pymt_struct_h.client) )
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING)
	}
        //shailesh   ISKB_430_08
	if ( chr_l_usermode == 'M' || chr_l_usermode == 'I')
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

	if ( (chr_l_usermode == 'D') || (chr_l_usermode == 'A') || 
	    ((chr_l_usermode == 'M') && chr_l_actionflag != 'I') )
	{
		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%d", l_iv_client_pymt_struct_h.inden_num);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Sequence Number", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}
                //shailesh   ISKB_430_08
		Alert(" l_iv_client_pymt_struct_h.pymt_class = [%c]",l_iv_client_pymt_struct_h.h_tot_srv);
		if ( l_iv_client_pymt_struct_h.inden_num <= 0 && l_iv_client_pymt_struct_h.h_tot_srv == 'S')
		{
			CO_InsertErr(l_debug_info_ptr, ERR_SEQNO_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			
		}

	   
		if ( !strlen(l_iv_client_pymt_struct_h.bpymt_access_stamp) && l_iv_client_pymt_struct_h.h_tot_srv == 'S') 
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}
		
	}

	int_l_retstat = 0;

	if ( !strlen(l_iv_client_pymt_struct_h.pymnt_dt) )
	{
		APL_DATA_MISSING("Payment Date", APL_NULL_STRING, 
				 APL_NULL_STRING)
	}
	else if ( APL_FAILURE == IV_Chk_PymtDt(l_iv_client_pymt_struct_h.pymnt_dt, 
					       &int_l_retstat, l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
		sprintf(chr_l_buffer1, "%lf", l_iv_client_pymt_struct_h.pymnt_amount);

		if ( !strlen(chr_l_buffer1) )
		{
			APL_DATA_MISSING("Payment Amount", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}

		if ( !strlen(l_iv_client_pymt_struct_h.pymnt_currencycode) )
		{
			APL_DATA_MISSING("Payment Currency", APL_NULL_STRING, 
					 APL_NULL_STRING)
		}

		if ( (l_iv_client_pymt_struct_h.h_tot_srv != 'T') && 
		     (l_iv_client_pymt_struct_h.h_tot_srv != 'S') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_TOTAL_SERVICE_PAY_IN, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			
		}

		if ( l_iv_client_pymt_struct_h.adjust != 'Y' )
		{
			l_iv_client_pymt_struct_h.adjust = 'N';
		}
	}

	if ( p_iv_client_pymt_struct_h_a->h_tot_srv == 'S' )
	{
		if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
		{
			memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
			printf("\n before ltoa_r.. serv h_code is |%ld|\n",l_iv_client_pymt_struct_h.service_cd); //AIX - Warnings Removal
			ltoa_r(l_iv_client_pymt_struct_h.service_cd, chr_l_buffer1, 
			       BUFFER_LEN - 1);

			if ( !strlen(chr_l_buffer1) )
			{
				APL_DATA_MISSING("Service Code", 
						 APL_NULL_STRING, 
						 APL_NULL_STRING)
			}
			else if (  (l_iv_client_pymt_struct_h.service_cd == 
							OVERBILLING) 
				|| (l_iv_client_pymt_struct_h.service_cd == 
							EXCESSCREDITFEE)
				|| (l_iv_client_pymt_struct_h.service_cd == 
							VOLDISCOUNTFEE) )
			
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INVALID_SERVCODE, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);
			}
		}

		if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'M') )
		{
			memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);
			ltoa_r(l_iv_client_pymt_struct_h.old_service_cd, chr_l_buffer1, 
			       BUFFER_LEN - 1);

			if ( !strlen(chr_l_buffer1) )
			{
				APL_DATA_MISSING("Prev. Serv. Code", 
						 APL_NULL_STRING, 
						 APL_NULL_STRING)
			}
		}

		if ( (chr_l_usermode == 'I') || 
		     ((chr_l_usermode == 'M') && (chr_l_actionflag == 'M')) )
		{
			if ( (l_iv_client_pymt_struct_h.first_service_pymt != 'Y') && 
			     (l_iv_client_pymt_struct_h.first_service_pymt != 'N') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_FIRSTSERV_PAYMNTVAL, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				
			}

			if ( l_iv_client_pymt_struct_h.first_service_pymt == 'N' )
			{
				memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);

				sprintf(chr_l_buffer1, "%ld", 
					l_iv_client_pymt_struct_h.service_cd);

				if ( !strlen(chr_l_buffer1) )
				{
					APL_DATA_MISSING("Sequence Number", 
							  APL_NULL_STRING, 
							  APL_NULL_STRING)
				}
				else if ( l_iv_client_pymt_struct_h.inden_num <= 0 )
				{
					CO_InsertErr(l_debug_info_ptr, 
						       ERR_SEQNO_GRTR_ZERO, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);

				     
				}


			}

		} 

	} 

	if ( chr_l_usermode == 'A' )
	{
			
		//shailesh   ISKB_430_08 The purge indicator in not used 
		/*if ( (l_iv_client_pymt_struct_h.purge_recall_ind != 'P') && 
		     (l_iv_client_pymt_struct_h.purge_recall_ind != 'R') )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PURGE_RECALL_PR, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			
		}*/
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Rtv_IVCUSTSETUP(l_iv_client_pymt_struct_h.client, 
					      &l_iv_cltsetup_struct, &int_l_retstat, 
					      l_debug_info_ptr) )
	{
		if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
		{
			APL_GOBACK_FAIL
		}
		else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
				       APL_NULL_STRING, APL_NULL_STRING,
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}

	

	if ( strcmp(l_iv_client_pymt_struct_h.pymnt_currencycode, l_iv_cltsetup_struct.b_ccycd) )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_INVALID_PAYCCY, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		

		APL_GOBACK_FAIL
	}

	int_l_retstat = 0;

	if ( APL_FAILURE == IV_Chk_CustEntitlement(&l_iv_cltsetup_struct, &int_l_retstat, 
					     l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}
/* Added by vishal for ISKB_1737 Billing Enhancement Start*/
	if ( !strcmp(p_intl_envdatastruct_h->subprocess,"GFU"))
	{
		if(!strlen(l_iv_client_pymt_struct_h.bill_date))
		{
			APL_DATA_MISSING("Bill Date", APL_NULL_STRING, APL_NULL_STRING)
		}
		
		if ( !strlen(l_iv_client_pymt_struct_h.pymnt_dt) )
	{
		APL_DATA_MISSING("Payment Date", APL_NULL_STRING, 
				 APL_NULL_STRING)
	}
	
	
	
	
		if(l_iv_client_pymt_struct_h.bill_amt==0)
		{
			CO_InsertErr(l_debug_info_ptr, ERR_ZERO_BILL_AMT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
                APL_GOBACK_FAIL
		}
		
		if(l_iv_client_pymt_struct_h.pymnt_amount>l_iv_client_pymt_struct_h.bill_amt)
               {
                        
				CO_InsertErr(l_debug_info_ptr, ERR_PYMTAMT_GRT_BILLAMT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
                     APL_GOBACK_FAIL
                }

		if(l_iv_client_pymt_struct_h.h_tot_srv=='T')
		{
				if(l_iv_client_pymt_struct_h.pymnt_amount!=l_iv_client_pymt_struct_h.bill_amt)
               {
                        
				CO_InsertErr(l_debug_info_ptr, ERR_BILL_CNF_AMT_EQ, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
                     APL_GOBACK_FAIL
                }

		}
		/*Added for ISKB_1737 July_2016 - Pallavi Changed below condition*/
		if((l_iv_client_pymt_struct_h.h_tot_srv!='T') && ( l_iv_client_pymt_struct_h.h_tot_srv!='S'))
		{
		CO_InsertErr(l_debug_info_ptr, ERR_INVALID_PYMTYPE, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
                     APL_GOBACK_FAIL
		}
			/*Added for ISKB_1737 July_2016*/
	}
/* Added by vishal for ISKB_1737 Billing Enhancement End*/	
	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') )
	{
		int int_temppymntacc = 0;

	
	
	if(strcmp(g_mt_commonsys_params_struct_h.nation_code,"IN"))	/* Vedavati HDFCIV_006  */
	{	
		
		printf("the pymt_account is :%s\n",l_iv_client_pymt_struct_h.pymnt_clt);
		if ( strlen(l_iv_client_pymt_struct_h.pymnt_clt) != 1 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_INVALID_PAYMNT, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		else
		{
			sscanf(l_iv_client_pymt_struct_h.pymnt_clt, "%d", &int_temppymntacc);

			if ( (int_temppymntacc != 1) && (int_temppymntacc != 2) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_INVALID_PAYMNT, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Chk_PymtAcc(int_temppymntacc, 
						  l_iv_client_pymt_struct_h.pymnt_currencycode,
						  &int_l_retstat, l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_FIRST, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				
			}
			else if ( int_l_retstat == IV_COLUMN_NULL_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_NOTAUTHORIZED, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				
			}

			APL_GOBACK_FAIL

		} 
	}
		printf(" the mode flag is :|%c|\n" ,chr_l_usermode);
		printf(" the action flag is : |%c|\n" ,chr_l_actionflag);

		if ( l_iv_client_pymt_struct_h.h_tot_srv == 'S' )
		{
			l_iv_serv_mast_struct.service_cd = l_iv_client_pymt_struct_h.service_cd;

			int_l_retstat = 0;
			/*below function related to IV_SERV_MAST   shailesh 16-11-2007*/
			if ( APL_FAILURE == 
				IV_Rtv_IVSRVCHRGDel(l_iv_client_pymt_struct_h.service_cd, 
						 &l_iv_serv_mast_struct, &int_l_retstat,
						 l_debug_info_ptr) )
			{
				if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
				{
					APL_GOBACK_FAIL
				}
				else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
				{
					CO_InsertErr(l_debug_info_ptr,ERR_INVALID_SERVCODE,
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       APL_NULL_STRING, 
						       __LINE__, __FILE__);

					

					APL_GOBACK_FAIL
				}

			} 
		}
		else 
		{
			if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'I') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_SERVPYMNT_NOTALLOWED, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				

				APL_GOBACK_FAIL
			}
			else if ( (chr_l_usermode == 'M') && (chr_l_actionflag == 'D') )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_DEL_TOTPYMT_NOTALLOWED, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				

				APL_GOBACK_FAIL
			}
		}
		
		if ( chr_l_actionflag != 'D' )
		if ( l_iv_client_pymt_struct_h.pymnt_amount <= 0.0 )
		{
			CO_InsertErr(l_debug_info_ptr, ERR_PAYAMT_GRTR_ZERO, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

	} 

	/*
	printf("IV_ProcPymt.c1 TDS : |%s|\n",p_iv_client_pymt_struct_h_a->tds_amt);
	printf("IV_ProcPymt.c1 Cheque : |%s|\n",p_iv_client_pymt_struct_h_a->cheque_det);
   */
        //shailesh   ISKB_430_08  04-12-2007
   	Alert("\n shailesh 	l_iv_client_pymt_struct_h.bill_amt=[%lf]",l_iv_client_pymt_struct_h.bill_amt);
	Alert("\n shailesh 	l_iv_client_pymt_struct_h.os_amt=[%lf]",l_iv_client_pymt_struct_h.os_amt);
	Alert("\n shailesh 	l_iv_client_pymt_struct_h.tot_os_amt=[%lf]",l_iv_client_pymt_struct_h.tot_os_amt);
	

	if ( chr_l_usermode == 'I' )
	{
		printf("\n User mode is 'I' ===> action flag is  %c",chr_l_actionflag);
                //shailesh  --ISKB_430_08
		if ( chr_l_actionflag == 'I' )
		{
		int_l_retstat = 0;
		
		if ( APL_FAILURE == IV_Mod_NewCustPymt(&l_iv_client_pymt_struct_h, 
						    p_newseqnum, p_intl_envdatastruct_h, 
						    &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
			
		}

		if( ( chr_l_actionflag == 'M' )||( chr_l_actionflag == 'D' ))/*Modified by siva.ganapathi for ISKB_2222 on 11/05/2009*/
		{
		int_l_retstat = 0;
		
			if ( APL_FAILURE == IV_Mod_ChgCustPymt(&l_iv_client_pymt_struct_h, 
								p_newseqnum,
							    p_intl_envdatastruct_h, 
							    &int_l_retstat, 
							    l_debug_info_ptr) )
		
		{
			APL_GOBACK_FAIL
		}
			
		}
/*Commented by siva.ganapathi for ISKB_2222 on 11/05/2009*/
//		if ( chr_l_actionflag == 'D' )
//		{
//		int_l_retstat = 0;
//
//		if ( APL_FAILURE == IV_Mod_DelCustPymt(&l_iv_client_pymt_struct_h, 
//						    p_intl_envdatastruct_h, &int_l_retstat, 
//						    l_debug_info_ptr) )
//		{
//			APL_GOBACK_FAIL
//		}
//		}
	}
	else if ( chr_l_usermode == 'M' )
	{
		printf("\n User mode is 'M' ===> action flag is  %c",chr_l_actionflag);
		if ( chr_l_actionflag == 'I' )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == IV_Mod_NewCustPymt(&l_iv_client_pymt_struct_h, 
							    p_newseqnum, 
							    p_intl_envdatastruct_h, 
							    &int_l_retstat, 
							    l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
		else if ( (chr_l_actionflag == 'M') || (chr_l_actionflag == 'D') )
		{
			int_l_retstat = 0;

			if ( APL_FAILURE == IV_Mod_ChgCustPymt(&l_iv_client_pymt_struct_h, 
								p_newseqnum,
							    p_intl_envdatastruct_h, 
							    &int_l_retstat, 
							    l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
			Alert("\n  p_newseqnum = [%d]",*p_newseqnum);
		}
	}
/*Modified  by siva.ganapathi for ISKB_2222 on 11/05/2009 --- started*/
	else if ( chr_l_usermode == 'D' )
	{
		printf("\n User mode is 'D' before calling the function IV_Mod_ChgCustPymt()");
		int_l_retstat = 0;

//		if ( APL_FAILURE == IV_Mod_DelCustPymt(&l_iv_client_pymt_struct_h, 
//						    p_intl_envdatastruct_h, &int_l_retstat, 
//						    l_debug_info_ptr) )
//		{
//			APL_GOBACK_FAIL
//		}
			
			if ( APL_FAILURE == IV_Mod_ChgCustPymt(&l_iv_client_pymt_struct_h, 
								p_newseqnum,
							    p_intl_envdatastruct_h, 
							    &int_l_retstat, 
						    l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else if ( chr_l_usermode == 'A' )
	{
		printf("\n User mode is 'M' ===>  status of the record is %c",l_status);
		if (l_status == 'U')
		{
		int_l_retstat = 0;
		Alert("\n l_iv_client_pymt_struct_h.h_tot_srv = [%c] ",l_iv_client_pymt_struct_h.h_tot_srv);
		
		if ( APL_FAILURE == IV_Mod_AuthCustPymt(&l_iv_client_pymt_struct_h, 
						     p_intl_envdatastruct_h, &int_l_retstat, 
						     l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
		else if (l_status == 'D')
		{	
			printf("\n Beforee1111 deleting the record");
			if ( APL_FAILURE == IV_Mod_DelCustPymt(&l_iv_client_pymt_struct_h, 
								p_intl_envdatastruct_h, &int_l_retstat, 
								l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
		}
	}
		
	strcpy((char *)p_iv_client_pymt_struct_h_a->bpymt_access_stamp,l_iv_client_pymt_struct_h.bpymt_access_stamp);//Changes done for AIX Migration
	
	if(*p_newseqnum == 0)	
	*p_newseqnum = l_iv_client_pymt_struct_h.inden_num;
	
	Alert("*p_newseqnum = [%d]",*p_newseqnum);
		
	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of IV_Proc_PymtMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of IV_Proc_PymtMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
