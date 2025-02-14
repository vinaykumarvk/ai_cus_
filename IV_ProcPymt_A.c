//ISKB-430_07_08 shailesh The IV_CHEQUE_DET is not used ,only IV_CHEQUE and IV_CHEQUE_A are used




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"
#include "IV_Pymt.h"



int IV_Mod_NewCustPymt(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
		    int *p_newseqnum, const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		    int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVPymtRowLock(IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDETNew(const IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymt(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVPymtMaxSeqNum(const char *l_pymntdate, 
					    const char *chr_l_client, 
					    int *int_l_maxpymntseqnum, 
					    int *int_l_retstat, 
					    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtNew(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	int int_l_maxpymntseqnum = 0, int_l_newpymntseqnum = 0;

	double l_dbl_bill_amt = 0.0 ;//shailesh   ISKB_430_08 --03-12-2007
	double l_dbl_tot_os_amt =0.0;
	double l_dbl_os_amt =0.0;
	char *l_chr_billdate_1;
	double l_dbl_conf_amt = 0.0;
	double l_dbl_conf_amt_1 = 0.0;
	int l_int_pymt_done =0;
	int l_int_inden_num =0;
	int l_int_t_pymt_exist = 0;
	int l_int_ivcheque_exist = 0;
	double l_dbl_s_bill_amt = 0.0;
	double l_dbl_s_paid_amt = 0.0;
	int l_int_s_pymt_exist =0;
	char l_status ;/*added by shruthi Kumbla for 1737*/

	l_chr_billdate_1 =APL_NULL_STRING;//shailesh ISKB-430

	IV_CHEQUE_STRUCT l_iv_cheque_struct;
	IV_CLIENT_PYMT_STRUCT_H l_iv_client_pymt_struct_h = *p_iv_client_pymt_struct_h_a;
	IV_CHEQUE_A_STRUCT l_iv_cheque_a_struct;

	memset(l_iv_cheque_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.dateof_payment, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.bill_date, APL_NULL_CHAR, APL_CLIENT_LENGTH); //shailesh 251007 ISKB_430_08
	memset(l_iv_cheque_struct.b_ccycd, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.maker, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.maker_dt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.access_stamp, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.checker, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.checker_dt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.pymt_clt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.ae_dt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.cheque_det, APL_NULL_CHAR, 100);		/* added by Vedavati HDFCIV_006 */
	memset(l_iv_cheque_struct.tds_amt, APL_NULL_CHAR, 21);		/* added by Vedavati HDFCIV_006 */
	memset(l_iv_cheque_struct.adjust_entry,APL_NULL_CHAR,2);	/* Added For UAT Fix */

	l_iv_cheque_struct.inden_num = 0;
	l_iv_cheque_struct.pay_seq = 0;
	l_iv_cheque_struct.conf_amt = 0.0;
	l_iv_cheque_struct.proc_num = 0;

	strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
	strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
	strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date); //shailesh 171007  251007

	strcpy(l_iv_cheque_struct.pymt_clt, l_iv_client_pymt_struct_h.pymnt_clt);		/* ST */
	strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det);	/* added by Vedavati HDFCIV_006 */ 
	strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);			/* added by Vedavati HDFCIV_006 */ 
	Alert("adjust_entry before = |%s|",l_iv_client_pymt_struct_h.adjust_entry);
	fflush(stdout);
	strcpy(l_iv_cheque_struct.adjust_entry, l_iv_client_pymt_struct_h.adjust_entry);
	Alert("adjust_entry after = |%s|",l_iv_cheque_struct.adjust_entry);
	fflush(stdout);

        //shailesh   ISKB_430_08 --03-12-2007
	/*if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) && 
	     !strcmp(p_intl_envdatastruct_h->h_process, ACTION_NEW_IND) )
	{
		if ( (l_iv_client_pymt_struct_h.h_tot_srv == 'S') && 
		     (l_iv_client_pymt_struct_h.first_service_pymt == 'Y') )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERVPYMNT_NOTALLOWED, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

		     

			APL_GOBACK_FAIL
		}
	}*/

//shailesh   ISKB_430_08 --03-12-2007
//The if condition deleted
//since now the first payment ind is not used

		if ( l_iv_cheque_struct.status_pymt == 'A' )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_AUTHORIZED, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
		else if ( l_iv_cheque_struct.status_pymt == 'D' )
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_MARKEDDEL, APL_NULL_STRING,
				       APL_NULL_STRING, APL_NULL_STRING, 
				       __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}

		

//shailesh   ISKB_430_08 --03-12-2007
//currently  only l_dbl_bill_amt is *imp* 
//l_dbl_conf_amt_1,l_dbl_conf_amt may be used later
//Calculating the actual bill amount[for all services]  for the selected bill date 
if (APL_FAILURE == IV_Calc_BillAmt(l_iv_client_pymt_struct_h.client,l_iv_client_pymt_struct_h.bill_date,
																	&l_dbl_conf_amt,
					&l_dbl_conf_amt_1,&l_dbl_bill_amt,&int_l_status,l_debug_info_ptr))
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;
				APL_GOBACK_FAIL
			}
			//shailesh ISKB-430
if (APL_FAILURE == IV_GetIndenNum(l_iv_client_pymt_struct_h.client, 
											  l_iv_client_pymt_struct_h.bill_date,
											  l_iv_client_pymt_struct_h.pymnt_dt,
											  l_iv_client_pymt_struct_h.h_tot_srv,
											  l_iv_client_pymt_struct_h.service_cd,
											  &l_int_inden_num,	
										      &int_l_status, l_debug_info_ptr))
		{

			Alert("\n cannot calculate INDEN_NUM");
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			APL_GOBACK_FAIL
		}

//shailesh ISKB-430
		if(l_iv_client_pymt_struct_h.h_tot_srv == 'S')
		{
		l_int_t_pymt_exist=0;
		if (APL_FAILURE == IV_IVPymt_T_Exist(l_iv_client_pymt_struct_h.client, 					   
										l_iv_client_pymt_struct_h.bill_date,
											&l_int_t_pymt_exist,
	                                       &int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
		}
		if(l_int_t_pymt_exist)
			{
			CO_InsertErr(l_debug_info_ptr,ERR_PAYMENTALREADYDONE, 
	       APL_NULL_STRING, APL_NULL_STRING, 
	       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}

		if (APL_FAILURE == IV_Calc_S_BillAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_bill_amt,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate bill amount");
			APL_GOBACK_FAIL
			}

		if (APL_FAILURE == IV_Calc_S_PaidAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_paid_amt,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate paid amount for that service amount");
			APL_GOBACK_FAIL
			}
	        //shailesh ISKB-430
		if( l_dbl_s_bill_amt == l_dbl_s_paid_amt)
			{
			Alert("\n Payment for this service is already done");
			CO_InsertErr(l_debug_info_ptr,ERR_PAYMENT_S_ALREADYDONE, 
	       APL_NULL_STRING, APL_NULL_STRING, 
	       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}
			printf("l_dbl_s_paid_amt value is |%f|",l_dbl_s_paid_amt);
			fflush(stdout);
			printf("l_dbl_s_l_dbl_s_bill_amt value is |%f|",l_dbl_s_bill_amt);
			fflush(stdout);
			printf("l_dbl_l_iv_client_pymt_struct_h.pymnt_amount value is |%f|",l_iv_client_pymt_struct_h.pymnt_amount);
			fflush(stdout);

		//if( l_dbl_s_bill_amt < (l_dbl_s_paid_amt+l_iv_client_pymt_struct_h.pymnt_amount))
			if( APL_DOUBLE_LESS(l_dbl_s_bill_amt,(l_dbl_s_paid_amt+l_iv_client_pymt_struct_h.pymnt_amount)) )
			{
			Alert("\n Payment for this service EXCEEDS THE ACTUAL BILL AMT FOR THIS SERVICE");
			CO_InsertErr(l_debug_info_ptr,ERR_PAY_GREATERTHAN_BILL, 
	       APL_NULL_STRING, APL_NULL_STRING, 
	       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}
		

		//copy the record in iv_cheque_det structure

//shailesh ISKB-430_08
//copy the record in iv_cheque_struct
strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date);
strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
strcpy(l_iv_cheque_struct.b_ccycd, l_iv_client_pymt_struct_h.pymnt_currencycode);
strcpy(l_iv_cheque_struct.pymt_clt, l_iv_client_pymt_struct_h.pymnt_clt);
strcpy(l_iv_cheque_struct.maker, p_intl_envdatastruct_h->usr);
strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det); 
strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);

l_iv_cheque_struct.inden_num = l_int_inden_num;
l_iv_cheque_struct.pay_seq = 0;
l_iv_cheque_struct.proc_num = 0;
l_iv_cheque_struct.pymt_ind = 'S';

l_iv_cheque_struct.service_cd=l_iv_client_pymt_struct_h.service_cd;
l_iv_cheque_struct.bill_amt = l_dbl_s_bill_amt;

l_iv_cheque_struct.conf_amt = l_iv_client_pymt_struct_h.pymnt_amount;


l_iv_cheque_struct.os_amt =l_dbl_s_bill_amt - (l_dbl_s_paid_amt+l_iv_client_pymt_struct_h.pymnt_amount) ;

Alert("\n l_iv_cheque_struct.os_amt = [%lf]",l_iv_cheque_struct.os_amt);
l_iv_cheque_struct.tot_os_amt = 0;
//shailesh ISKB-430-08
if (APL_FAILURE == IV_Mod_IVPymtNew(&l_iv_cheque_struct, &int_l_status,l_debug_info_ptr))
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
	}
}

		
else  //ELSE FOR PAYMENT MODE

		if(l_iv_client_pymt_struct_h.h_tot_srv == 'T')				
		{
			//check for wheteher payment done or not
			//if (not done populate the iv_cheque structure and insert int iv_cheque with service cd as 0 )
		l_int_t_pymt_exist=0;
		if (APL_FAILURE == IV_IVPymt_T_Exist(l_iv_client_pymt_struct_h.client, 					   
										l_iv_client_pymt_struct_h.bill_date,
											&l_int_t_pymt_exist,
	                                       &int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
		}
		if(l_int_t_pymt_exist)
			{
			CO_InsertErr(l_debug_info_ptr,ERR_PAYMENTALREADYDONE, 
	       APL_NULL_STRING, APL_NULL_STRING, 
	       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}
		
		if (APL_FAILURE == IV_IVPymt_S_Exist(l_iv_client_pymt_struct_h.client, 					   
										l_iv_client_pymt_struct_h.bill_date,
											&l_int_s_pymt_exist,
	                                       &int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
		}
		//shailesh ISKB-430-08
		if(l_int_s_pymt_exist)
			{
			Alert("\n Payment Mode for this billing date is service-wise");
			CO_InsertErr(l_debug_info_ptr, ERR_PAYMENTSTARTEDSERVICEWISE, 
	       APL_NULL_STRING, APL_NULL_STRING, 
	       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}
		
		strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
		strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date);//shailesh ISKB-430-08
		strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
		strcpy(l_iv_cheque_struct.b_ccycd, l_iv_client_pymt_struct_h.pymnt_currencycode);
		strcpy(l_iv_cheque_struct.pymt_clt, l_iv_client_pymt_struct_h.pymnt_clt);
		strcpy(l_iv_cheque_struct.maker, p_intl_envdatastruct_h->usr);
		strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det); 
		strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);

		l_iv_cheque_struct.inden_num = l_int_inden_num;
		l_iv_cheque_struct.pay_seq = 0;
		l_iv_cheque_struct.pymt_ind = 'T';
		l_iv_cheque_struct.proc_num = 0;
		l_iv_cheque_struct.service_cd=0;
		l_iv_cheque_struct.bill_amt = l_dbl_bill_amt;
		l_iv_cheque_struct.conf_amt = l_iv_client_pymt_struct_h.pymnt_amount;
		l_iv_cheque_struct.os_amt = 0;
		l_iv_cheque_struct.tot_os_amt = 0;
	if (APL_FAILURE == IV_Mod_IVPymtNew(&l_iv_cheque_struct, &int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
		}


		}

else		//ELSE FOR PAYMENT MODE
		{

		Alert("\n payment mode not selected");
		APL_GOBACK_FAIL
		}

	//FINALLY UPDATING   THE  IV_CHEQUE_A TABLE
	memset(l_iv_cheque_a_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_a_struct.bill_date, APL_NULL_CHAR, APL_CLIENT_LENGTH);

if (APL_FAILURE == IV_Calc_BillAmt(l_iv_client_pymt_struct_h.client,l_iv_client_pymt_struct_h.bill_date,
																	&l_dbl_conf_amt,
					&l_dbl_conf_amt_1,&l_dbl_bill_amt,&int_l_status,l_debug_info_ptr))
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;
				APL_GOBACK_FAIL
			}

	strcpy(l_iv_cheque_a_struct.client, l_iv_client_pymt_struct_h.client);
	strcpy(l_iv_cheque_a_struct.bill_date, l_iv_client_pymt_struct_h.bill_date); 
	l_iv_cheque_a_struct.bill_amt = l_dbl_bill_amt;
	if (APL_FAILURE == IV_Mod_IVCHEQUE_A(l_iv_cheque_a_struct,&int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
		}

/*ISKB_1737 Payment Upload changes to authorize uploaded record  - starts - shruthi kumbla*/
if ( (!strcmp(p_intl_envdatastruct_h->subprocess, "GFU"))&&(!strcmp(p_intl_envdatastruct_h->auth_req, "N")) )
{
	Alert("\n authorizing uploaded record having status |%c|",l_iv_cheque_struct.status_pymt);

	int int_l_retstat = 0;
	if ( APL_FAILURE == IV_GetStatus(&l_iv_client_pymt_struct_h, 
										&l_status,
										&int_l_retstat, 
										l_debug_info_ptr) )
				
			{
					APL_GOBACK_FAIL
			}
			
			Alert("\n status of the record is %c",l_status);

	if (l_status=='U')
	{
	
		int_l_retstat = 0;
		
		
		if ( APL_FAILURE == IV_Mod_AuthCustPymt(&l_iv_client_pymt_struct_h, 
						     p_intl_envdatastruct_h, &int_l_retstat, 
						     l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
}
	/*ISKB_1737 Payment Upload changes to authorize uploaded record  - ends - shruthi kumbla*/

	strcpy((char *)p_iv_client_pymt_struct_h_a->bpymt_access_stamp,l_iv_cheque_struct.access_stamp); //Changes done for AIX Migration
	
	//*p_newseqnum = int_l_newpymntseqnum;
	*p_newseqnum = l_int_inden_num;
	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of IV_Mod_NewCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of IV_Mod_NewCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}


// changes for ISKB_430_08 shailesh -03-12-2007
int IV_Mod_ChgCustPymt(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
			int *p_newseqnum,
		    const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		    int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVPymtRowLock(IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVPymtDET(IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDETDelRow(
					const IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa,
					int *int_l_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDETNew(const IV_CHEQUE_DET_STRUCT *p_iv_cheque_det_struct, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDET(const IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa, 
				      int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymt(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymt_S(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_actionflag,chr_l_usermode;
	int int_l_status = 0;
	double l_newtotpymntamount = 0.0;
        //shailesh ISKB-430-08
	double l_dbl_servtotos_amt =0.0;

	double l_dbl_prevamt_s =0.0;

	double l_dbl_s_bill_amt =0.0;

	double l_dbl_s_paid_amt =0.0;

	double l_dbl_service_amt =0.0;

	double l_dbl_conf_amt = 0.0;
    double l_dbl_conf_amt_1 =0.0;
	double l_dbl_bill_amt = 0.0;

	IV_CHEQUE_STRUCT l_iv_cheque_struct;
	IV_CHEQUE_DET_STRUCT l_iv_cheque_det_structa;
	IV_CLIENT_PYMT_STRUCT_H l_iv_client_pymt_struct_h = *p_iv_client_pymt_struct_h_a;
        //shailesh ISKB-430-08
	IV_CHEQUE_A_STRUCT l_iv_cheque_a_struct;

	if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_MOD_IND) )
	{
		chr_l_actionflag = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_DEL_IND) )
	{
		chr_l_actionflag = 'D';
	}

	/*Added by siva.ganapathi for ISKB_2222 on 11/05/2009 --- started*/
	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}

	if ( chr_l_usermode == 'M' || chr_l_usermode == 'I')
	{
		if ( !strcmp(p_intl_envdatastruct_h->h_process, ACTION_DEL_IND))
		{
			chr_l_actionflag = 'R';
		}
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}

	if(chr_l_usermode == 'D')
	{
			chr_l_actionflag = 'R';
	}
	printf("\n User Mode is  is %s",p_intl_envdatastruct_h->h_mode);
	printf("\n action is %s",p_intl_envdatastruct_h->h_process);
        /*Added by siva.ganapathi for ISKB_2222 on 11/05/2009 --- Ended*/
	memset(l_iv_cheque_struct.dateof_payment, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.client, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.b_ccycd, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.maker, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.checker, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.pymt_clt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.ae_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.cheque_det, APL_NULL_CHAR, 100);		/* added by Vedavati HDFCIV_006 */
	memset(l_iv_cheque_struct.tds_amt, APL_NULL_CHAR, 21);		/* added by Vedavati HDFCIV_006 */


	l_iv_cheque_struct.inden_num = 0;
	l_iv_cheque_struct.pay_seq = 0;
	l_iv_cheque_struct.conf_amt = 0.0;
	l_iv_cheque_struct.proc_num = 0;
	l_iv_cheque_struct.status_pymt = NULL;
	l_iv_cheque_struct.pymt_ind = NULL;//shailesh ISKB-430-08

	strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
	strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
	strcpy(l_iv_cheque_struct.access_stamp, l_iv_client_pymt_struct_h.bpymt_access_stamp);
	strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det);	 
	strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);	
	strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date);	
	


	l_iv_cheque_struct.inden_num = l_iv_client_pymt_struct_h.inden_num;

	int_l_status = 0;

        /*Modified by siva.ganapathi for ISKB_2222 on 11/05/2009 --- started*/
	printf("\n chr_l_actionflag is %c",chr_l_actionflag);
	if(chr_l_actionflag == 'R')/*Modified by siva*/
	{	
		Alert("\n Before Calling IV_Mod_IVPymt_S() function");
		if ( APL_FAILURE == IV_Mod_IVPymt_S(&l_iv_cheque_struct, p_intl_envdatastruct_h, 
					    &int_l_status, l_debug_info_ptr) )
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
	}
	else
	{	
		
	Alert("l_iv_client_pymt_struct_h.h_tot_srv  =  [%c]",l_iv_client_pymt_struct_h.h_tot_srv);
	//shailesh ISKB-430-08
	l_iv_cheque_struct.pymt_ind = l_iv_client_pymt_struct_h.h_tot_srv;
	Alert("l_iv_cheque_struct.pymt_ind  =  [%c]",l_iv_cheque_struct.pymt_ind);

	if ( APL_FAILURE == IV_Mod_IVPymtRowLock(&l_iv_cheque_struct, &int_l_status, 
						l_debug_info_ptr) )
	{
		if ( int_l_status == IV_CRITCAL_ERROR_IND )
		{
			*int_p_retstat = int_l_status;

			APL_GOBACK_FAIL
		}
		else if ( int_l_status == IV_NO_DATA_FOUND_ERR )
		{
			char chr_l_buffer1[BUFFER_LEN];

			memset(chr_l_buffer1, APL_NULL_CHAR, BUFFER_LEN);

			sprintf(chr_l_buffer1, "%d", l_iv_client_pymt_struct_h.inden_num);

			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_NOTFND, 
				       l_iv_cheque_struct.dateof_payment, l_iv_cheque_struct.dateof_payment, 
				       chr_l_buffer1, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
//shailesh 19022008
strcpy(l_iv_cheque_struct.access_stamp, l_iv_client_pymt_struct_h.bpymt_access_stamp);
	if ( l_iv_cheque_struct.status_pymt == 'A' )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_AUTHORIZED, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}
	else if ( l_iv_cheque_struct.status_pymt == 'D' )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_MARKEDDEL, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		APL_GOBACK_FAIL
	}
//shailesh ISKB-430-08
//shailesh 180208
if ( l_iv_client_pymt_struct_h.h_tot_srv == 'S' )
	{
if (APL_FAILURE == IV_Calc_S_BillAmt(l_iv_client_pymt_struct_h.client, 
									l_iv_client_pymt_struct_h.bill_date,
									l_iv_client_pymt_struct_h.service_cd,
									&l_dbl_s_bill_amt,
									&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate bill amount");
			APL_GOBACK_FAIL
			}

if (APL_FAILURE == IV_Calc_S_PaidAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_paid_amt,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate paid amount for that service amount");
			APL_GOBACK_FAIL
			}
	}
	if ( l_iv_client_pymt_struct_h.h_tot_srv == 'S' )
	{
		int_l_status = 0;

		memset(l_iv_cheque_det_structa.dateof_payment, APL_NULL_CHAR, APL_DATE_LEN);
		memset(l_iv_cheque_det_structa.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);

		l_iv_cheque_det_structa.inden_num = 0;
		l_iv_cheque_det_structa.service_amt = 0.0;
		l_iv_cheque_det_structa.service_cd = 0.0;
	//	l_iv_cheque_det_structa.status_paydet = NULL; shailesh 12-11-2007
		l_iv_cheque_det_structa.status_paydet = 'U';

		strcpy(l_iv_cheque_det_structa.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
		strcpy(l_iv_cheque_det_structa.client, l_iv_client_pymt_struct_h.client);
		strcpy(l_iv_cheque_det_structa.bill_date, l_iv_client_pymt_struct_h.bill_date);
		l_iv_cheque_det_structa.inden_num = l_iv_client_pymt_struct_h.inden_num;

		if (( chr_l_actionflag == 'D' )||( chr_l_actionflag == 'M' ))
			l_iv_cheque_det_structa.service_cd = l_iv_client_pymt_struct_h.service_cd;

	

		int_l_status = 0;
		l_newtotpymntamount=1;
		if ( (chr_l_actionflag == 'D') && !l_newtotpymntamount )//later
		{
			*int_p_retstat = IV_CRITCAL_ERROR_IND;

			CO_InsertErr(l_debug_info_ptr, ERR_SERV_NO_DEL_PAY, 
				       APL_NULL_STRING, APL_NULL_STRING,
				       APL_NULL_STRING, __LINE__, __FILE__);

			

			APL_GOBACK_FAIL
		}
//shailesh ISKB-430-08
l_iv_cheque_struct.service_cd = l_iv_client_pymt_struct_h.service_cd;
l_iv_cheque_struct.conf_amt = l_iv_client_pymt_struct_h.pymnt_amount;
l_iv_cheque_struct.status_pymt = 'U';

Alert("\n test 1 l_iv_client_pymt_struct_h.pymnt_amount = [%lf] ",l_iv_client_pymt_struct_h.pymnt_amount);

Alert("\n test 2 l_iv_cheque_struct.conf_amt = [%lf] ",l_iv_cheque_struct.conf_amt);


l_iv_cheque_struct.os_amt = l_iv_cheque_struct.bill_amt -  l_iv_cheque_struct.conf_amt;
Alert("\n 301107  l_iv_cheque_struct.bill_amt = [%lf]",l_iv_cheque_struct.bill_amt);
Alert("\n 301107  l_iv_cheque_struct.conf_amt = [%lf]",l_iv_cheque_struct.conf_amt);
Alert("\n 301107  l_iv_cheque_struct.os_amt = [%lf]",l_iv_cheque_struct.os_amt);

l_iv_cheque_struct.tot_os_amt = 0;
			
int_l_status =0;
strcpy(l_iv_cheque_struct.pymt_clt, l_iv_client_pymt_struct_h.pymnt_clt);

	/* ST1.0 */
	strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det);
	strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);

	strcpy(l_iv_cheque_struct.adjust_entry, l_iv_client_pymt_struct_h.adjust_entry);
	l_iv_cheque_struct.bill_amt = l_dbl_s_bill_amt;
	l_dbl_service_amt = l_iv_cheque_struct.conf_amt;
if ( chr_l_actionflag == 'M' )
{
	int_l_status = 0;

        //shailesh ISKB-430-08
	if ( APL_FAILURE == IV_GetPrevAmt_S(l_iv_cheque_struct,&l_dbl_prevamt_s, 
					    &int_l_status, l_debug_info_ptr) )
	{
		
			APL_GOBACK_FAIL
		
	}
	Alert("l_dbl_s_bill_amt = [%lf]",l_dbl_s_bill_amt);
	Alert("l_dbl_s_paid_amt = [%lf]",l_dbl_s_paid_amt);
	Alert("l_dbl_prevamt_s = [%lf]",l_dbl_prevamt_s);
	Alert("l_dbl_service_amt = [%lf]",l_dbl_service_amt);
//shailesh ISKB-430-08
if(l_dbl_s_bill_amt < (l_dbl_s_paid_amt - l_dbl_prevamt_s + l_dbl_service_amt ) )
	{
		Alert("\n Payment for this service EXCEEDS THE ACTUAL BILL AMT FOR THIS SERVICE");
		CO_InsertErr(l_debug_info_ptr,ERR_PAY_GREATERTHAN_BILL, 
				      APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
		APL_GOBACK_FAIL
			
	}
	
	printf("\n:IV_ProcPymt_A.c::   l_dbl_s_bill_amt = [%lf]",l_dbl_s_bill_amt);
	printf("\n:IV_ProcPymt_A.c::   l_dbl_prevamt_s = [%lf]",l_dbl_prevamt_s);
	printf("\n:IV_ProcPymt_A.c::   l_dbl_service_amt = [%lf]",l_dbl_service_amt);
	printf("\n:IV_ProcPymt_A.c::   l_iv_client_pymt_struct_h.pymnt_amount = [%lf]",l_iv_client_pymt_struct_h.pymnt_amount);


	l_iv_cheque_struct.os_amt = l_dbl_s_bill_amt-(l_dbl_s_paid_amt-l_dbl_prevamt_s+l_dbl_service_amt);

	printf("\n:IV_ProcPymt_A.c::  l_iv_cheque_struct.os_amt = [%lf]",l_iv_cheque_struct.os_amt);


	//l_iv_cheque_struct.os_amt =l_dbl_s_bill_amt - (l_dbl_s_paid_amt+l_iv_client_pymt_struct_h.pymnt_amount);

	l_iv_cheque_struct.bill_amt = l_dbl_s_bill_amt;//shailesh 150208

	if ( APL_FAILURE == IV_Mod_IVPymt_S(&l_iv_cheque_struct, p_intl_envdatastruct_h, 
					    &int_l_status, l_debug_info_ptr) )
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
}

	if ( chr_l_actionflag == 'D')
		{
		int_l_status = 0;

		if ( APL_FAILURE == IV_Mod_DelCustPymt(&l_iv_client_pymt_struct_h, 
						    p_intl_envdatastruct_h, &int_l_status, 
						    l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
		}


	}
	else //ELSE FOR PAYMENT MODE shailesh ISKB-430-08
	if ( l_iv_client_pymt_struct_h.h_tot_srv == 'T' )
	{
		Alert("\n INSIDE TOTALMODE FILE::IV_ProcPymt_A.c ");
		Alert("\n l_iv_cheque_struct.inden_num = [%d] ",l_iv_cheque_struct.inden_num);
		l_iv_cheque_struct.inden_num = l_iv_client_pymt_struct_h.inden_num;
		strcpy(l_iv_cheque_struct.cheque_det,l_iv_client_pymt_struct_h.cheque_det);
		if ( APL_FAILURE == IV_Mod_IVPymt_T(&l_iv_cheque_struct, p_intl_envdatastruct_h, 
					    &int_l_status, l_debug_info_ptr) )
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
			
	
	}

		

	//FINALLY UPDATING   THE  IV_CHEQUE_A TABLE -shailesh ISKB-430-08

	//In total mode only cheque detail can be modified,so actually updating iv_cheque_a is not
	//required

if(l_iv_client_pymt_struct_h.h_tot_srv == 'S')
	{
		if (APL_FAILURE == IV_Calc_BillAmt(l_iv_client_pymt_struct_h.client,l_iv_client_pymt_struct_h.bill_date,
																	&l_dbl_conf_amt,
					&l_dbl_conf_amt_1,&l_dbl_bill_amt,&int_l_status,l_debug_info_ptr))
			{
				*int_p_retstat = IV_CRITCAL_ERROR_IND;
				APL_GOBACK_FAIL
			}
			


                                //shailesh ISKB-430-08
				memset(l_iv_cheque_a_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
				memset(l_iv_cheque_a_struct.bill_date, APL_NULL_CHAR, APL_CLIENT_LENGTH);
				strcpy(l_iv_cheque_a_struct.client, l_iv_client_pymt_struct_h.client);
				strcpy(l_iv_cheque_a_struct.bill_date, l_iv_client_pymt_struct_h.bill_date); 
				l_iv_cheque_a_struct.bill_amt = l_dbl_bill_amt;
				Alert("\n After modofying  updating/inserting in IV_CHEQUE_A");
				Alert("\n l_iv_cheque_a_struct.bill_amt =  [%lf]",l_iv_cheque_a_struct.bill_amt);

				if (APL_FAILURE == IV_Mod_IVCHEQUE_A(l_iv_cheque_a_struct,&int_l_status,l_debug_info_ptr))
					{
					*int_p_retstat = IV_CRITCAL_ERROR_IND;

					APL_GOBACK_FAIL
				    }
	}

	Alert("\n l_iv_cheque_struct.inden_num = [%d]",l_iv_cheque_struct.inden_num);
	Alert("\n *p_newseqnum = [%d]",*p_newseqnum);
		
	*p_newseqnum = l_iv_cheque_struct.inden_num;//shailesh ISKB-430-08
	 strcpy((char *)p_iv_client_pymt_struct_h_a->bpymt_access_stamp,l_iv_cheque_struct.access_stamp);/* vinay */ //Changes done for AIX Migration
	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	}
        /*Modifed by siva.ganapathi for ISKB_2222 on 11/05/2009 --- Ended*/
	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of IV_Mod_ChgCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of IV_Mod_ChgCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
