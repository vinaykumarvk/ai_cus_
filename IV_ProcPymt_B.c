




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"
#include "IV_Pymt.h"


//changes for ISKB_430_08 shailesh 03-12-2007
/* OPT:AIX int IV_Mod_DelCustPymt(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a,  */
int IV_Mod_DelCustPymt( IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
		    const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
		    int *int_p_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	


//shailesh ISKB-430-08
double 	l_dbl_conf_amt= 0.0;
double l_dbl_conf_amt_1 = 0.0;
double l_dbl_bill_amt = 0.0;

	extern int IV_Mod_IVPymtRowLock(IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDETDel(const IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa, 
				      const char l_markorpurge, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymt(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	int int_l_status = 0;
	IV_CHEQUE_STRUCT l_iv_cheque_struct;
	IV_CHEQUE_DET_STRUCT l_iv_cheque_det_structa;
	IV_CLIENT_PYMT_STRUCT_H l_iv_client_pymt_struct_h = *p_iv_client_pymt_struct_h_a;
	IV_CHEQUE_A_STRUCT 	 l_iv_cheque_a_struct;

	memset(l_iv_cheque_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.dateof_payment, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.bill_date, APL_NULL_CHAR, APL_DATE_LEN);//shailesh 171007
	memset(l_iv_cheque_struct.b_ccycd, APL_NULL_CHAR, APL_CCYCODE_LEN);
	memset(l_iv_cheque_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_cheque_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_cheque_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.pymt_clt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.ae_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.cheque_det, APL_NULL_CHAR, 100);		
	memset(l_iv_cheque_struct.tds_amt, APL_NULL_CHAR, 21);			
	
	l_iv_cheque_struct.inden_num = 0;
	l_iv_cheque_struct.pay_seq = 0;
	l_iv_cheque_struct.status_pymt = NULL;
	l_iv_cheque_struct.conf_amt = 0.0;
	l_iv_cheque_struct.proc_num = 0;
	//shailesh 251007 ISKB_430_08

	l_iv_cheque_struct.bill_amt = 0;
	l_iv_cheque_struct.os_amt = 0;
	l_iv_cheque_struct.tot_os_amt = 0;
	l_iv_cheque_struct.pymt_ind = NULL;


	strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
	strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
	strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date); 
	strcpy(l_iv_cheque_struct.access_stamp, l_iv_client_pymt_struct_h.bpymt_access_stamp);
	strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det);	
	strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);			

	l_iv_cheque_struct.inden_num = l_iv_client_pymt_struct_h.inden_num;
	l_iv_cheque_struct.pymt_ind = l_iv_client_pymt_struct_h.h_tot_srv;

	int_l_status = 0;

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

			sprintf(chr_l_buffer1, "%d", l_iv_client_pymt_struct_h.inden_num); //AIX - Warnings Removal

			CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_NOTFND, 
				       l_iv_client_pymt_struct_h.pymnt_dt, 
				       l_iv_client_pymt_struct_h.client, 
				       chr_l_buffer1, __LINE__, __FILE__);

			*int_p_retstat = IV_CRITCAL_ERROR_IND;

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
		//Commented by siva.ganapathi 
//	else if ( l_iv_cheque_struct.status_pymt == 'D' )
//	{
//		*int_p_retstat = IV_CRITCAL_ERROR_IND;
//
//		CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_MARKEDDEL, APL_NULL_STRING, 
//			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
//			       __FILE__);
//
//		
//
//		APL_GOBACK_FAIL
//	}
//
	if ( l_iv_client_pymt_struct_h.h_tot_srv == 'S' )
	{
        //shailesh ISKB-430-08	
	if ( APL_FAILURE == IV_Del_IVPymt_S(&l_iv_cheque_struct, p_intl_envdatastruct_h, 
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
	else if(l_iv_client_pymt_struct_h.h_tot_srv == 'T' )//ELSE FOR PAYMENT MODE 
	{

			if ( APL_FAILURE == IV_Del_IVPymt_T(&l_iv_cheque_struct, p_intl_envdatastruct_h, 
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
	else//success from IV_Del_IVPymt_T - shailesh ISKB-430-08
		{
		if (APL_FAILURE == IV_Del_IVCHEQUE_A(l_iv_client_pymt_struct_h.client,l_iv_client_pymt_struct_h.bill_date,
											&int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;
		APL_GOBACK_FAIL
		}
		else//success from IV_Del_IVCHEQUE_A
			{
					APL_GOBACK_SUCCESS
			}
		}

	}



//FINALLY UPDATING   THE  IV_CHEQUE_A TABLE
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

	if (APL_FAILURE == IV_Mod_IVCHEQUE_A(l_iv_cheque_a_struct,&int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
	}


	strcpy(p_iv_client_pymt_struct_h_a->bpymt_access_stamp,l_iv_cheque_struct.access_stamp);/* vinay */
	
	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Mod_DelCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Mod_DelCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}

//changes for ISKB_430_08 shailesh 03-12-2007

/* OPT:AIX int IV_Mod_AuthCustPymt(const IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a,  */
int IV_Mod_AuthCustPymt( IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a, 
		     const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, int *int_p_retstat, 
		     DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	extern int IV_Mod_IVPymtRowLock(IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				       int *int_l_retstat, 
				       DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDETDel(const IV_CHEQUE_DET_STRUCT *l_iv_cheque_det_structa, 
				      const char l_markorpurge, int *int_l_retstat, 
				      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymtDel(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int BBDbRemBPAYMENTDETRows(
					const IV_CHEQUE_DET_STRUCT *p_iv_cheque_det_struct_a,
					int *int_p_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVLEDGERMaxPymtSeqNum(const char *chr_l_client, 
						const char *chr_l_sys_date, 
						int *int_l_maxseqnum, 
						int *int_l_retstat, 
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);	

	extern int CO_RtvSysDt(char *chr_l_sys_date, 
				    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVCUSTSETUP(char *chr_l_client_a, 
				    IV_CLIENTSETUP_STRUCT *l_iv_clientsetup_struct, 
				    int *int_l_retstat,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_ConvToFxFn(char *l_fromccy, char *l_toccy, char *l_domccy, 
			      char *chr_l_sys_date, double *l_exchgrt, 
			      int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_AuthTotPymt(const char *chr_l_client, 
				   const double l_pymntamt, 
				   const char *l_pymntccycode, 
				   const int l_ledgseqnum, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_AuthServPymt(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				    const int l_ledgseqnum, int *int_l_retstat, 
				    DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVLEDGERNew(const IV_LEDGER_STRUCT *l_iv_ledger_struct, 
				  int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVLEDGERCrAmt(const char *chr_l_client, 
					   double *l_totcreditamount, 
					   int *int_l_retstat, 
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Proc_PassCreditLedgerEntry(const char *chr_l_client, 
					   const char *chr_l_sys_date, 
					   const double l_totcreditamount, 
					   const char *l_pymntccycode, 
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVPymt(const IV_CHEQUE_STRUCT *l_iv_cheque_struct, 
				   const INTL_ENV_DATA_STRUCT_H *l_intl_env_data_h, 
				   int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVBCUSTSETUPAmt(const IV_CLIENTSETUP_STRUCT *l_iv_cltsetup_struct, 
					 int *int_l_retstat, 
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_BYRACT(const int l_year, const int l_month, 
				 const char l_typeofentry, const double l_amt, 
				 int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


	extern int IV_Mod_IVPymtDETAuth(
					const IV_CHEQUE_DET_STRUCT *p_iv_cheque_det_struct_a,
					int *int_p_retstat, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	


	char chr_l_sys_date_mm[3], chr_l_sys_date_yyyy[5];
	char chr_l_sys_date[APL_DATE_LEN], chr_l_temp_sys_date[APL_DATE_LEN];
	char l_AuthInpMod = 'N', l_AuthDel = 'N', *chr_l_last = (char *)NULL;
	int int_l_status = 0;
	int int_l_maxledgseqnum = 0, int_l_newautseqnum = 0;
	double l_newtotosamount = 0.0, l_currcreditamount = 0.0, l_totcreditamount = 0.0;
	double l_exchgrt = 0.0, l_rempososamount = 0.0, l_effpymntamount = 0.0;
	double l_yearlypymntamount = 0.0, l_temp_pymntamount = 0.0;
	double l_oldtotosamount = 0.0;

        //shailesh ISKB-430-08
	double l_dbl_s_bill_amt = 0.0;
	double l_dbl_s_paid_amt = 0.0;

	double l_dbl_conf_amt = 0.0;
    double l_dbl_conf_amt_1= 0.0;
	double l_dbl_bill_amt = 0.0;
	double l_dbl_s_authpaid =0.0;
	int l_int_payseq =0;
	int int_l_retstat = 0;


	IV_CHEQUE_STRUCT l_iv_cheque_struct;
	IV_LEDGER_STRUCT l_iv_ledger_struct;
	IV_CLIENTSETUP_STRUCT l_iv_cltsetup_struct;
	IV_CHEQUE_DET_STRUCT l_iv_cheque_det_structa;
	IV_CLIENT_PYMT_STRUCT_H l_iv_client_pymt_struct_h = *p_iv_client_pymt_struct_h_a;

	IV_CHEQUE_A_STRUCT 	 l_iv_cheque_a_struct;

	memset(l_iv_cheque_struct.client, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.dateof_payment, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.b_ccycd, APL_NULL_CHAR, APL_CCYCODE_LEN);
	memset(l_iv_cheque_struct.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_cheque_struct.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_cheque_struct.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.pymt_clt, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_cheque_struct.ae_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_cheque_struct.cheque_det, APL_NULL_CHAR, 100);		/* added by Vedavati HDFCIV_006 */ 
	memset(l_iv_cheque_struct.tds_amt, APL_NULL_CHAR, 21);			/* added by Vedavati HDFCIV_006 */ 

	l_iv_cheque_struct.inden_num = 0L;
	l_iv_cheque_struct.pay_seq = 0;
	l_iv_cheque_struct.conf_amt = 0.0;
	l_iv_cheque_struct.proc_num = 0;
	l_iv_cheque_struct.status_pymt = NULL;
	l_iv_cheque_struct.pymt_ind = NULL;

	strcpy(l_iv_cheque_struct.client, l_iv_client_pymt_struct_h.client);
	strcpy(l_iv_cheque_struct.dateof_payment, l_iv_client_pymt_struct_h.pymnt_dt);
	strcpy(l_iv_cheque_struct.access_stamp, l_iv_client_pymt_struct_h.bpymt_access_stamp);
	strcpy(l_iv_cheque_struct.cheque_det, l_iv_client_pymt_struct_h.cheque_det);	
	strcpy(l_iv_cheque_struct.tds_amt, l_iv_client_pymt_struct_h.tds_amt);			
	strcpy(l_iv_cheque_struct.bill_date, l_iv_client_pymt_struct_h.bill_date);	
	l_iv_cheque_struct.inden_num = l_iv_client_pymt_struct_h.inden_num;


	l_iv_cheque_struct.pymt_ind = l_iv_client_pymt_struct_h.h_tot_srv;
	int_l_status = 0;
	printf("\n before calling the IV_Mod_IVPymtRowLock() function in IV_Mod_AuthCustPymt() function");
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
				       l_iv_client_pymt_struct_h.pymnt_dt, 
				       l_iv_client_pymt_struct_h.client, 
				       chr_l_buffer1, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
//shailesh 19022008
;
/*modified by shruthi kumbla for ISKB_1737 start*/
if ( (strcmp(p_intl_envdatastruct_h->subprocess, "GFU"))&&(strcmp(p_intl_envdatastruct_h->auth_req, "N")) )
strcpy(l_iv_cheque_struct.access_stamp, l_iv_client_pymt_struct_h.bpymt_access_stamp);
/*modified by shruthi kumbla for ISKB_1737 end*/
if ( l_iv_cheque_struct.status_pymt == 'A' )
	{
		CO_InsertErr(l_debug_info_ptr, ERR_PAYMNT_AUTHORIZED, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);
		


		APL_GOBACK_FAIL
	}
        /*Modified by siva.ganapathi for ISKB_2222 on 11/05/2009 --- started*/
	else if ( l_iv_cheque_struct.status_pymt == 'D' )
	{
		l_AuthDel = 'Y';
		printf("\n status of the record is  ======== Delete");
		printf("\n Before deleting the record");
			
			if ( APL_FAILURE == IV_Mod_DelCustPymt(&l_iv_client_pymt_struct_h, 
								p_intl_envdatastruct_h, &int_l_retstat, 
								l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL
			}
	}
        /*Mopdified by siva.ganapathi for ISKB_2222 on 11/05/2009 --- Ended*/
	else 
	{
		l_AuthInpMod = 'Y';
	}


Alert("l_AuthInpMod   ---  = [%c]",l_AuthInpMod);
/*modified by shruthi kumbla for ISKB_1737 start*/
if ( (!strcmp(p_intl_envdatastruct_h->subprocess, "GFU"))&&(!strcmp(p_intl_envdatastruct_h->auth_req, "N")) )
			strcpy(l_iv_cheque_struct.checker,"SYSTEM");
	else
			strcpy(l_iv_cheque_struct.checker,p_intl_envdatastruct_h->usr);

	if ( !strcmp(l_iv_cheque_struct.maker, l_iv_cheque_struct.checker) )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, APL_NULL_STRING, 
			       APL_NULL_STRING, APL_NULL_STRING, __LINE__, 
			       __FILE__);

		

		APL_GOBACK_FAIL
	}

/*modified by shruhti kumbla for ISKB_1737 end*/
        //shailesh ISKB-430-08
	if(l_AuthInpMod == 'Y')
	{

			strcpy(l_iv_cheque_struct.dateof_payment,l_iv_client_pymt_struct_h.pymnt_dt);

			strcpy(l_iv_cheque_struct.client,l_iv_client_pymt_struct_h.client);

			strcpy(l_iv_cheque_struct.bill_date,l_iv_client_pymt_struct_h.bill_date);

			l_iv_cheque_struct.inden_num = l_iv_client_pymt_struct_h.inden_num;

			l_iv_cheque_struct.status_pymt = 'A';

			//TO GET THE PAY_SEQ value (column in IV_CHEQUE)
//indicates the order of authorization

			if (APL_FAILURE == IV_GetPaySeq(l_iv_client_pymt_struct_h.client,
											&l_int_payseq,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n FILE :: IV_ProcPymt_B.c cannot calculate payseq ");
			APL_GOBACK_FAIL
			}
		     Alert("\n --------l_int_payseq  = [%d]",l_int_payseq);
			l_iv_cheque_struct.pay_seq = l_int_payseq;
		
		if ( l_iv_client_pymt_struct_h.h_tot_srv == 'S' )
		{
		
			l_iv_cheque_struct.service_cd = l_iv_client_pymt_struct_h.service_cd;

			int_l_status = 0;

		
		
		if (APL_FAILURE == IV_Calc_S_BillAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_bill_amt,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate bill amount");
			APL_GOBACK_FAIL
			}
		
		Alert("\n --------l_dbl_s_bill_amt  = [%lf]",l_dbl_s_bill_amt);
		if (APL_FAILURE == IV_Calc_S_PaidAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_paid_amt,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate paid amount for that service amount");
			APL_GOBACK_FAIL
			}
		Alert("\n --------l_dbl_s_paid_amt  = [%lf]",l_dbl_s_paid_amt);
	   if(l_dbl_s_bill_amt < l_dbl_s_paid_amt) //to check whether payment amount is more than bill amount for that servcie for selected billing period
			{
			Alert("\n Payment for this service EXCEEDS THE ACTUAL BILL AMT FOR THIS SERVICE");
			CO_InsertErr(l_debug_info_ptr,ERR_PAY_GREATERTHAN_BILL, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);
			APL_GOBACK_FAIL
			}

		//To assign the values to OS_AMT and BILL_AMT columns of IV_CHEQUE table 
		//authorized service_payment for the particular billing period will be calculated --(l_dbl_s_authpaid)
		//BILL_AMT will be  (l_dbl_s_bill_amt -  l_dbl_s_authpaid) -->[l_dbl_temp]
		//OS_AMT will be     l_dbl_temp - l_iv_client_pymt_struct_h.conf_amt
		if (APL_FAILURE == IV_Calc_S_AuthPaidAmt(l_iv_client_pymt_struct_h.client, 
											l_iv_client_pymt_struct_h.bill_date,
											l_iv_client_pymt_struct_h.service_cd,
											&l_dbl_s_authpaid,
											&int_l_status,l_debug_info_ptr))
			{
			Alert("\n cannot calculate authorized paid amount for that service amount");
			APL_GOBACK_FAIL
			}
		   Alert("\n --------l_dbl_s_authpaid  = [%lf]",l_dbl_s_authpaid);
		
		l_iv_cheque_struct.bill_amt =  l_dbl_s_bill_amt - l_dbl_s_authpaid;
		l_iv_cheque_struct.os_amt   =  l_iv_cheque_struct.bill_amt - l_iv_cheque_struct.conf_amt;
		l_iv_cheque_struct.pay_seq   =  l_int_payseq;
		if ( APL_FAILURE == IV_Auth_S_IVPymt(&l_iv_cheque_struct,p_intl_envdatastruct_h,&int_l_status, 
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
		}//ELSE FOR  PAYMENT MODE - shailesh ISKB-430-08
		else if ( l_iv_client_pymt_struct_h.h_tot_srv == 'T' )
		{

		if ( APL_FAILURE == IV_Auth_T_IVPymt(&l_iv_cheque_struct,p_intl_envdatastruct_h,&int_l_status, 
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
			
			APL_GOBACK_FAIL
	
		}

	   } 
	   else
		{
		   Alert("\n The payment mode is not present");
		   APL_GOBACK_FAIL
		}

		int_l_status = 0;

	if ( APL_FAILURE == CO_RtvSysDt(chr_l_sys_date, l_debug_info_ptr) )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
	}

	int_l_status = 0;

//FINALLY UPDATING   THE  IV_CHEQUE_A TABLE
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

	if (APL_FAILURE == IV_Mod_IVCHEQUE_A(l_iv_cheque_a_struct,&int_l_status,l_debug_info_ptr))
		{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		APL_GOBACK_FAIL
	    }


//shailesh ISKB-430-08
//Now the IV_CLIENTSETUP TABLE has to be updated for values of OS amount
//	and Last payment date

Alert("\n Before updating the IV_CLIENTSETUP TABLE ");
Alert("\n l_iv_cheque_struct.conf_amt = [%lf]",l_iv_cheque_struct.conf_amt);
Alert("\n l_iv_cheque_struct.client = [%s]",l_iv_cheque_struct.client);
Alert("\n l_iv_cheque_struct.dateof_payment = [%s]",l_iv_cheque_struct.dateof_payment);



//shailesh ISKB-430-08
if ( APL_FAILURE == IV_CLTSETUP_update(l_iv_cheque_struct.client,
										  l_iv_cheque_struct.dateof_payment,
										  l_iv_cheque_struct.conf_amt,
										  l_iv_cheque_struct.b_ccycd,									
						                  &int_l_status, 
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

				CO_InsertErr(l_debug_info_ptr,ERR_CANNOTUPDATECLIENTSETUP, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	
	}//enf of if --l_AuthInpMod
	strcpy(p_iv_client_pymt_struct_h_a->bpymt_access_stamp,l_iv_cheque_struct.access_stamp);/* vinay */
	
	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Mod_AuthCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Mod_AuthCustPymt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
