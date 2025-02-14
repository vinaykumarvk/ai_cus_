

 
   
   
   
   
   
   
   
   
   
   
   

#include "IV_InterFace.h"
#include "CA_InterFace.h"
#include "Intellect_Common.h"
#include "CO_HostStructdef.h"
//AIX - Warnings Removal
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
  void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
  void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value);	

int IV_Proc_BaseNoPopulate(MS_BASENO_STRUCT_H *p_ms_baseno_struct_h, char *chr_p_param_str)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_BaseNoPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"BASEID",(char *)p_ms_baseno_struct_h->baseid);
        CO_Rtv_DataString(chr_p_param_str,"CONTACT_DETAILS",(char *)p_ms_baseno_struct_h->contact_details);
        CO_Rtv_DataChar(chr_p_param_str,"SWIFT_TLX_GCN",&(p_ms_baseno_struct_h->swift_tlx_gcn));
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ms_baseno_struct_h->access_stamp);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_BaseNoPopulate \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_BaseNoPopulate \n",NULL,NULL);
	return 1;
*/
} 


int IV_Proc_CntrlParamPopulate(IV_CNTRL_PARAM_STRUCT_H *p_iv_cntrl_param_struct_h, char *chr_p_param_str)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_CntrlParamPopulate \n",NULL,NULL);


	CO_Rtv_DataString(chr_p_param_str,"B_PREV_DATE",(char *)p_iv_cntrl_param_struct_h->b_prev_date);
	CO_Rtv_DataString(chr_p_param_str,"B_UPTO_DATE",(char *)p_iv_cntrl_param_struct_h->b_upto_date);
	CO_Rtv_DataString(chr_p_param_str,"B_PROCESSDT",(char *)p_iv_cntrl_param_struct_h->b_processdt);
	CO_Rtv_DataString(chr_p_param_str,"B_DLV_DATE",(char *)p_iv_cntrl_param_struct_h->b_dlv_date);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_CntrlParamPopulate \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_CntrlParamPopulate \n",NULL,NULL);
	return 1;
*/
} 



int IV_Proc_IVAccPopulate(IV_CLIENT_STRUCT *p_iv_client_struct_b, char *chr_p_param_str)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_IVAccPopulate \n",NULL,NULL);


	CO_Rtv_DataString(chr_p_param_str,"COMM_A",(char *)p_iv_client_struct_b->comm_a);
	CO_Rtv_DataString(chr_p_param_str,"PAYACC_A",(char *)p_iv_client_struct_b->payacc_a);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_iv_client_struct_b->maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_iv_client_struct_b->maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_iv_client_struct_b->access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_iv_client_struct_b->checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_iv_client_struct_b->checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"COMM_B",(char *)p_iv_client_struct_b->comm_b);
	CO_Rtv_DataString(chr_p_param_str,"COMM_C",(char *)p_iv_client_struct_b->comm_c);
	CO_Rtv_DataString(chr_p_param_str,"COMM_D",(char *)p_iv_client_struct_b->comm_d);
	CO_Rtv_DataString(chr_p_param_str,"COMM_E",(char *)p_iv_client_struct_b->comm_e);
	CO_Rtv_DataString(chr_p_param_str,"COMM_F",(char *)p_iv_client_struct_b->comm_f);
	CO_Rtv_DataString(chr_p_param_str,"COMM_G",(char *)p_iv_client_struct_b->comm_g);
	CO_Rtv_DataString(chr_p_param_str,"COMM_H",(char *)p_iv_client_struct_b->comm_h);
	CO_Rtv_DataString(chr_p_param_str,"COMM_I",(char *)p_iv_client_struct_b->comm_i);
	CO_Rtv_DataString(chr_p_param_str,"TAX_ACC",(char *)p_iv_client_struct_b->tax_acc);
	CO_Rtv_DataString(chr_p_param_str,"PAYACC_B",(char *)p_iv_client_struct_b->payacc_b);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_IVAccPopulate \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_IVAccPopulate \n",NULL,NULL);
	return 1;
*/
} 


int IV_Proc_CustOthPopulate(IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h, char *chr_p_param_str)
{

   CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_CustOthPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *) p_iv_client_othserv_struct_h->client);
	CO_Rtv_DataLong(chr_p_param_str,"SERVICE_CD",(long *)&(p_iv_client_othserv_struct_h->service_cd));
	CO_Rtv_DataString(chr_p_param_str,"SERVICE_DET",(char *) p_iv_client_othserv_struct_h->service_det);
	CO_Rtv_DataString(chr_p_param_str,"B_PERIOD",(char *) p_iv_client_othserv_struct_h->b_prd);
	CO_Rtv_DataInt(chr_p_param_str,"INDEN_NUM",(int *)&(p_iv_client_othserv_struct_h->inden_num));
	CO_Rtv_DataDbl(chr_p_param_str,"SERVICE_QTY",&(p_iv_client_othserv_struct_h->quantity));
	CO_Rtv_DataDbl(chr_p_param_str,"SCHDL_FEE",&(p_iv_client_othserv_struct_h->fees));
	CO_Rtv_DataString(chr_p_param_str,"B_CCYCD",(char *) p_iv_client_othserv_struct_h->b_ccycd);
	CO_Rtv_DataChar(chr_p_param_str,"PURGE_RECALL_FLAG",&(p_iv_client_othserv_struct_h->purge_recall_ind));
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *) p_iv_client_othserv_struct_h->access_stamp);
	
APL_GOBACK_SUCCESS // AIX - Warnings removal
	
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_CustOthPopulate \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_CustOthPopulate \n",NULL,NULL);
	return 1;
*/
} 


 int IV_Proc_RowIDPtrPopulate(char *p_ora_rowid,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_RowIDPtrPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"MSG_ROWID",p_ora_rowid);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_RowIDPtrPopulate \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_RowIDPtrPopulate \n",NULL,NULL);
        return 1;
*/
}



int IV_Proc_BillPayPopulate(long *p_newseqnum, IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_BillPayPopulate\n",NULL,NULL);
	
	CO_Rtv_DataLong(chr_p_param_str,"NEW_SEQ_NUM",p_newseqnum); // AIX - Warnings removal
	CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_iv_client_pymt_struct_h->client);
	printf("Param :|%s|\n",chr_p_param_str);
	CO_Rtv_DataLong(chr_p_param_str,"IVCHEQUE_SERVICE_CD",(long *)&(p_iv_client_pymt_struct_h->service_cd));//shailesh ISKB_430_08  
	if(p_iv_client_pymt_struct_h->service_cd == 0)
	CO_Rtv_DataLong(chr_p_param_str,"SERVICE_CD",(long *)&(p_iv_client_pymt_struct_h->service_cd));
	CO_Rtv_DataInt(chr_p_param_str,"INDEN_NUM",(int *)&(p_iv_client_pymt_struct_h->inden_num));
	CO_Rtv_DataString(chr_p_param_str,"PYMT_CLT",(char *)p_iv_client_pymt_struct_h->pymnt_clt);
	CO_Rtv_DataString(chr_p_param_str,"CUSTSUS",(char *)p_iv_client_pymt_struct_h->pymnt_clt);	/* added by Vedavati HDFCIV_006 */ 


	CO_Rtv_DataString(chr_p_param_str,"B_CCYCD",(char *)p_iv_client_pymt_struct_h->pymnt_currencycode);
	CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",(char *)p_iv_client_pymt_struct_h->pymnt_dt);
	CO_Rtv_DataString(chr_p_param_str,"BILL_DATE",(char *)p_iv_client_pymt_struct_h->bill_date);//shailesh --ISKB_430_08
	CO_Rtv_DataDbl(chr_p_param_str,"BILL_AMT",&(p_iv_client_pymt_struct_h->bill_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"OS_AMT",&(p_iv_client_pymt_struct_h->os_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"TOT_OS_AMT",&(p_iv_client_pymt_struct_h->tot_os_amt));//shailesh  --ISKB_430_08
	CO_Rtv_DataLong(chr_p_param_str,"OLD_SERV_CODE",(long *)&(p_iv_client_pymt_struct_h->old_service_cd));
	CO_Rtv_DataChar(chr_p_param_str,"PYMT_CLASS",&(p_iv_client_pymt_struct_h->h_tot_srv));
		if(p_iv_client_pymt_struct_h->h_tot_srv == 'T')//shailesh  --ISKB_430_08
				CO_Rtv_DataDbl(chr_p_param_str,"CONF_AMT",&(p_iv_client_pymt_struct_h->pymnt_amount));
		else if(p_iv_client_pymt_struct_h->h_tot_srv == 'S')
		{
			CO_Rtv_DataDbl(chr_p_param_str,"SERVICE_AMT",&(p_iv_client_pymt_struct_h->pymnt_amount));
		}
	CO_Rtv_DataChar(chr_p_param_str,"ADJUST",&(p_iv_client_pymt_struct_h->adjust));
	CO_Rtv_DataChar(chr_p_param_str,"PURGE_RECALL_IND",&(p_iv_client_pymt_struct_h->purge_recall_ind));
	CO_Rtv_DataChar(chr_p_param_str,"FIRST_SRV_CODE",&(p_iv_client_pymt_struct_h->first_service_pymt));
	CO_Rtv_DataString(chr_p_param_str,"AE_DT",(char *)p_iv_client_pymt_struct_h->ae_dt);
	CO_Rtv_DataString(chr_p_param_str,"IVCHEQUE_ACCESS_STAMP",(char *)p_iv_client_pymt_struct_h->bpymt_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"ADJUST_ENTRY",(char *)p_iv_client_pymt_struct_h->adjust_entry);
	CO_Rtv_DataString(chr_p_param_str,"CHEQUE_DET",(char *)(p_iv_client_pymt_struct_h->cheque_det));		/* added by Vedavati HDFCIV_006 */ 
	CO_Rtv_DataString(chr_p_param_str,"TDS_AMT",(char *)(p_iv_client_pymt_struct_h->tds_amt));/* added by Vedavati HDFCIV_006 */ 
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_iv_client_pymt_struct_h->bpymt_access_stamp); /* added by Vedavati HDFCIV_006 */ 

	
	
	
APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_BillPayPopulate \n",NULL,NULL);
		return APL_SUCCESS;

/* AIX - Warnings removal
RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_BillPayPopulate \n",NULL,NULL);
		return 1;
*/
}

int IV_Proc_BillServRDPopulate(IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_b, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value);	
	CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_BillServRDPopulate\n",NULL,NULL);

	CO_Rtv_DataLong(chr_p_param_str,"SERVICE_CD",(long *)&(p_iv_serv_mast_struct_b->service_cd));
	CO_Rtv_DataString(chr_p_param_str,"SERVICE_DET",(char *)p_iv_serv_mast_struct_b->service_det);
	CO_Rtv_DataChar(chr_p_param_str,"FEES_CLASS",&(p_iv_serv_mast_struct_b->fees_class));
	CO_Rtv_DataDbl(chr_p_param_str,"MINIMUM_FEE",&(p_iv_serv_mast_struct_b->minimum_fee));
	CO_Rtv_DataChar(chr_p_param_str,"STD_FEEIND",&(p_iv_serv_mast_struct_b->std_feeind));
	CO_Rtv_DataChar(chr_p_param_str,"MASTSUB_IND",&(p_iv_serv_mast_struct_b->mastsub_ind));
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_iv_serv_mast_struct_b->access_stamp);
	CO_Rtv_DataChar(chr_p_param_str,"VALID_FEE_CLASS",&(p_iv_serv_mast_struct_b->valid_fee_class));
	CO_Rtv_DataString(chr_p_param_str,"B_CLIENT",(char *)p_iv_serv_mast_struct_b->b_client);
	CO_Rtv_DataChar(chr_p_param_str,"IN_ON_GEN",&(p_iv_serv_mast_struct_b->in_on_gen));
	CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_iv_serv_mast_struct_b->status);

APL_GOBACK_SUCCESS // AIX - Warnings removal
RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_BillServRDPopulate \n",NULL,NULL);
		return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_BillServRDPopulate \n",NULL,NULL);
		return 1;
*/
}

int IV_Proc_ManMsgPopulate(char *chr_startflag,long *int_msgsrno,char *corp_id,char *event_id,MS_MANMSG_STRUCT_H *p_ms_manmsg_struct_h, char *chr_p_param_str, char *p_param_str2, char *p_param_str3)
{
	char chr_p_str_temp[8000];
	char chr_l_str_temp[51];
	char chr_l_search_lbl[10];
	int int_l_int_loop;
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	CO_ProcMonitor(APL_OUT_FILE,"Entered  IV_Proc_ManMsgPopulate\n",NULL,NULL);

	 memset(chr_p_str_temp,NULL,8000);

	for(int_l_int_loop = 1; (int_l_int_loop < 61); int_l_int_loop ++ )
	{
		strcpy(chr_l_search_lbl,APL_NULL_STRING);
		sprintf(chr_l_search_lbl,"L%d",int_l_int_loop);
		memset(chr_l_str_temp,APL_NULL_CHAR,51);
		CO_Rtv_DataString(chr_p_param_str,chr_l_search_lbl, (char *)chr_l_str_temp);
		//strcpy(p_ms_manmsg_struct_h->h_line+(int_l_int_loop-1),chr_l_str_temp);
		strcpy((char *)(p_ms_manmsg_struct_h->h_line+int_l_int_loop-1),chr_l_str_temp);
	}
	for(int_l_int_loop = 61; (int_l_int_loop < 131); int_l_int_loop ++)
   {
      strcpy(chr_l_search_lbl,APL_NULL_STRING);
      sprintf(chr_l_search_lbl,"L%d",int_l_int_loop);
      memset(chr_l_str_temp,APL_NULL_CHAR,51);
      CO_Rtv_DataString(p_param_str2,chr_l_search_lbl, (char *)chr_l_str_temp);
      //strcpy(p_ms_manmsg_struct_h->h_line+(int_l_int_loop-1),chr_l_str_temp);
      strcpy((char *)(p_ms_manmsg_struct_h->h_line+int_l_int_loop-1),chr_l_str_temp);
   }
   for(int_l_int_loop = 131; (int_l_int_loop < 201); int_l_int_loop ++)
   {
      strcpy(chr_l_search_lbl,APL_NULL_STRING);
      sprintf(chr_l_search_lbl,"L%d",int_l_int_loop);
      memset(chr_l_str_temp,APL_NULL_CHAR,51);
      CO_Rtv_DataString(p_param_str3,chr_l_search_lbl, (char *)chr_l_str_temp);
      //strcpy(p_ms_manmsg_struct_h->h_line+(int_l_int_loop-1),chr_l_str_temp);
      strcpy((char *)(p_ms_manmsg_struct_h->h_line+int_l_int_loop-1),chr_l_str_temp);
   }	


	 
	 
	 

	 

	 CO_Rtv_DataChar(chr_p_param_str,"START_FLAG",chr_startflag); 	
	 CO_Rtv_DataLong(chr_p_param_str,"INP_MSG_SEQ_NO",int_msgsrno);
	 CO_Rtv_DataString(chr_p_param_str,"CORP_ID",corp_id);
	 CO_Rtv_DataString(chr_p_param_str,"EVENT_ID",event_id);
	 CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ms_manmsg_struct_h->client);
	 CO_Rtv_DataString(chr_p_param_str,"CONTACT_DETAILS",(char *)p_ms_manmsg_struct_h->contact_details);
	 CO_Rtv_DataChar(chr_p_param_str,"PRIORITY_IND",&(p_ms_manmsg_struct_h->priority_ind));
	 CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ms_manmsg_struct_h->maker);
	 CO_Rtv_DataString(chr_p_param_str,"MAKER_DATE",(char *)p_ms_manmsg_struct_h->maker_dt);

APL_GOBACK_SUCCESS // AIX - Warnings  removal

RETURN_SUCCESS:
	 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_ManMsgPopulate \n",NULL,NULL);
		 return APL_SUCCESS;

/* AIX - Warnings  removal
RETURN_FAILURE:
	 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_ManMsgPopulate \n",NULL,NULL);
		 return 1;
*/
}
	
int IV_Proc_AuthRDPopulate(int *int_p_msgsrno, char *chr_p_msgno_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_AuthRDPopulate \n",NULL,NULL);

	CO_Rtv_DataInt(chr_p_param_str,"SWIFT_MSG_SEQNO",int_p_msgsrno);
	CO_Rtv_DataString(chr_p_param_str,"SWIFT_MSG_NO",chr_p_msgno_a);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:
	 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_AuthRDPopulate \n",NULL,NULL);
		  return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
	 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_AuthRDPopulate \n",NULL,NULL);
		  return 1;
*/
}

int   IV_Proc_FtNtPopulate(CA_CANOTE_STRUCT_H *p_ca_canote_struct_h,char *chr_p_param_str)
{
   void  CO_Rtv_DataLongString(char *chr_p_str, char *p_lbl,char *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered IV_Proc_FtNtPopulate \n",NULL,NULL);
         CO_Rtv_DataLongString(chr_p_param_str,"INFO_SEQ",(char *)p_ca_canote_struct_h->h_info_nbr);
         CO_Rtv_DataLongString(chr_p_param_str,"INFO_1",(char *)p_ca_canote_struct_h->h_info_1);
         CO_Rtv_DataLongString(chr_p_param_str,"INFO_2",(char *)p_ca_canote_struct_h->h_info_2);
         CO_Rtv_DataLongString(chr_p_param_str,"INFO_3",(char *)p_ca_canote_struct_h->h_info_3);
         CO_Rtv_DataLongString(chr_p_param_str,"INFO_4",(char *)p_ca_canote_struct_h->h_info_4);
         CO_Rtv_DataLongString(chr_p_param_str,"MAKER",(char *)p_ca_canote_struct_h->h_maker);
         CO_Rtv_DataLongString(chr_p_param_str,"MAKER_DT",(char *)p_ca_canote_struct_h->h_maker_dt);
         CO_Rtv_DataLongString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_canote_struct_h->h_access_stamp);
		
	 CO_Rtv_DataLongString(chr_p_param_str,"TYPEOF_INFO",(char *)p_ca_canote_struct_h->h_info_class);

APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_FtNtPopulate \n",NULL,NULL);
        return APL_SUCCESS; // AIX - Warnings removal
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_FtNtPopulate \n",NULL,NULL);
        return 1;
*/
}
/**************************** Vedavati HDFCIV_002 ***********************************************/
int Populate_IV_CLIENTGL(IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
       
        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_IV_CLIENTGL  \n",NULL,NULL);
	
	printf("ParamString inside Populate_IV_CLIENTGL: %s",p_param_data);	
	
	CO_Rtv_DataString(p_param_data,"ROUTAC_A",(char *)p_iv_clientgl_struct_h->h_routac_a);
	CO_Rtv_DataString(p_param_data,"ROUTAC_B",(char *)p_iv_clientgl_struct_h->h_routac_b);
	CO_Rtv_DataString(p_param_data,"CUSTSUS",(char *)p_iv_clientgl_struct_h->h_custsus);
	CO_Rtv_DataString(p_param_data,"NSECLH",(char *)p_iv_clientgl_struct_h->h_nseclh);
	CO_Rtv_DataString(p_param_data,"BSECLH",(char *)p_iv_clientgl_struct_h->h_bseclh);
    CO_Rtv_DataString(p_param_data,"MCSCLH",(char *)p_iv_clientgl_struct_h->h_mcsclh);	/* Charuta : MCS KB 5878  */
	CO_Rtv_DataString(p_param_data,"NSESETAC",(char *)p_iv_clientgl_struct_h->h_nsesetac);
	CO_Rtv_DataString(p_param_data,"BSESETAC",(char *)p_iv_clientgl_struct_h->h_bsesetac);
	CO_Rtv_DataString(p_param_data,"MCSSETAC",(char *)p_iv_clientgl_struct_h->h_mcssetac);   /* Charuta : MCS KB 5878  */
	CO_Rtv_DataString(p_param_data,"RTGSSETAC",(char *)p_iv_clientgl_struct_h->h_rtgssetac);
	CO_Rtv_DataString(p_param_data,"FORTRT",(char *)p_iv_clientgl_struct_h->h_fortrt);
	CO_Rtv_DataString(p_param_data,"CMSRT",(char *)p_iv_clientgl_struct_h->h_cmsrt);
	CO_Rtv_DataString(p_param_data,"NSRSETAC",(char *)p_iv_clientgl_struct_h->h_nsrsetac);
	CO_Rtv_DataString(p_param_data,"BROK_PAY",(char *)p_iv_clientgl_struct_h->h_brok_pay);
	CO_Rtv_DataString(p_param_data,"STT_PAY",(char *)p_iv_clientgl_struct_h->h_stt_pay);
	CO_Rtv_DataString(p_param_data,"TDS_PAY",(char *)p_iv_clientgl_struct_h->h_tds_pay);
	CO_Rtv_DataString(p_param_data,"TDS_REC",(char *)p_iv_clientgl_struct_h->h_tds_rec);
	CO_Rtv_DataString(p_param_data,"PAYACC",(char *)p_iv_clientgl_struct_h->h_payacc);
	CO_Rtv_DataString(p_param_data,"PAY1ACC",(char *)p_iv_clientgl_struct_h->h_payacc1);
        CO_Rtv_DataString(p_param_data,"CASUS",(char *)p_iv_clientgl_struct_h->h_casus);
        CO_Rtv_DataString(p_param_data,"TOLERACC",(char *)p_iv_clientgl_struct_h->h_toleracc);
        CO_Rtv_DataString(p_param_data,"MAKER",(char *)p_iv_clientgl_struct_h->h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",(char *)p_iv_clientgl_struct_h->h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",(char *)p_iv_clientgl_struct_h->h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",(char *)p_iv_clientgl_struct_h->h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",(char *)p_iv_clientgl_struct_h->h_checker_dt);
	CO_Rtv_DataString(p_param_data,"RECACC",(char *)p_iv_clientgl_struct_h->h_recacc);  /* Bageshri -- HDFC Log 97 */
       CO_Rtv_DataString(p_param_data,"TAXACCOUNT",(char *)p_iv_clientgl_struct_h->h_taxacc);  /* TAXACCOUNT added by chitrlekha for tax deduction KB_9306 */
         
APL_GOBACK_SUCCESS // AIX - Warnings removal

	RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_IV_CLIENTGL \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_IV_CLIENTGL \n",NULL,NULL);
        return 1;
*/
}
/*************************************************************************/
/***********************************PRAVEEN HDFCIV_004*******************************/
int IV_Proc_BucketTxn(IV_BUCKET_TXN_STRUCT *p_ivBucketTxn_struct, char *chr_p_param_str)
{
	 void  CO_Rtv_DataLongString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	     
    CO_ProcMonitor(APL_OUT_FILE,"Entered  IV_Proc_BucketTxn \n",NULL,NULL);

    CO_Rtv_DataInt(chr_p_param_str,"SEQUENCE_NO",(int *)&p_ivBucketTxn_struct->sequence_no);
	 	CO_Rtv_DataString(chr_p_param_str,"IDENTITYLIST",(char *)p_ivBucketTxn_struct->identitylist);
		CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ivBucketTxn_struct->client);

APL_GOBACK_SUCCESS // AIX - Warnings rmoval

RETURN_SUCCESS:
	 
	   CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_BucketTxn \n",NULL,NULL);
      return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
      CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_BucketTxn \n",NULL,NULL);
      return 1;	
*/
}

/********************* vinay kalaskar ****************************/

int IV_Proc_MutualFund(IV_MUTUAL_FUND_STRUCT *p_ivMutualFund_struct, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	     
   CO_ProcMonitor(APL_OUT_FILE,"Entered  IV_Proc_MutualFund \n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"MF_SEQNO",(char *)p_ivMutualFund_struct->mf_seqno);
	CO_Rtv_DataString(chr_p_param_str,"IDENTITYLIST",(char *)p_ivMutualFund_struct->identitylist);
	CO_Rtv_DataString(chr_p_param_str,"CLIENTLIST",(char *)p_ivMutualFund_struct->clientlist);
	
APL_GOBACK_SUCCESS // AIX - Warnings removal

RETURN_SUCCESS:
	 
	   CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of IV_Proc_MutualFund \n",NULL,NULL);
      return APL_SUCCESS;
/* AIX - Warnings removal
RETURN_FAILURE:
      CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of IV_Proc_MutualFund \n",NULL,NULL);
      return 1;	
*/
}
/************************************************************************/

/***** JC - RFS_MS_001 -- Start *****/
int Populate_MANUAL_MESSAGE(MANUAL_MESSAGE_STRUCT_H *p_manual_message_struct_h, MS_MANMSG_STRUCT_H *p_ms_manmsg_struct_h, char *event_id,char * p_param_data,char * p_param_data2)
{
	char chr_p_str_temp[8000];
	char chr_l_str_temp[51];
	int int_l_int_loop;
	char chr_l_search_lbl[10];

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_MANUAL_MESSAGE \n",NULL,NULL);

	memset(chr_p_str_temp,NULL,8000);

        CO_Rtv_DataString(p_param_data,"CLN_CODE",p_manual_message_struct_h -> h_cln_code);
        CO_Rtv_DataString(p_param_data,"CORPORATE_ACTION",p_manual_message_struct_h -> h_ca_flag);
        CO_Rtv_DataString(p_param_data,"DL_FLAG",p_manual_message_struct_h -> h_dl_flag);
        CO_Rtv_DataString(p_param_data,"CORP_ID",p_manual_message_struct_h -> h_corp_id);
        CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_manual_message_struct_h -> h_dl_ref_no);
        CO_Rtv_DataString(p_param_data,"MSG_TXT",p_manual_message_struct_h -> h_message_txt);
        CO_Rtv_DataString(p_param_data,"MAKER",p_manual_message_struct_h -> h_maker);
        CO_Rtv_DataString(p_param_data,"MAKER_DT",p_manual_message_struct_h -> h_maker_dt);
        CO_Rtv_DataString(p_param_data,"CHECKER",p_manual_message_struct_h -> h_checker);
        CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_manual_message_struct_h -> h_checker_dt);
        CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_manual_message_struct_h -> h_access_stamp);
        CO_Rtv_DataString(p_param_data,"STATUS",p_manual_message_struct_h -> h_status);
        CO_Rtv_DataString(p_param_data,"SWIFT_MSG_SEQNO",p_manual_message_struct_h -> h_msg_seq_no);
        CO_Rtv_DataString(p_param_data,"MSG_INDICATOR",p_manual_message_struct_h -> h_msg_indicator);
        CO_Rtv_DataString(p_param_data,"ADDRESS_CLN",p_manual_message_struct_h -> h_address_cln);
        CO_Rtv_DataString(p_param_data,"MANMSG_SEQNO",p_manual_message_struct_h -> h_manmsg_seqno);
	CO_Rtv_DataString(p_param_data,"EVENT_ID",event_id);

	for(int_l_int_loop = 1; (int_l_int_loop < 201); int_l_int_loop ++ )
	{
		strcpy(chr_l_search_lbl,APL_NULL_STRING);
		sprintf(chr_l_search_lbl,"L%d",int_l_int_loop);
		memset(chr_l_str_temp,APL_NULL_CHAR,51);
		CO_Rtv_DataString(p_param_data, chr_l_search_lbl, (char *)chr_l_str_temp);
		//strcpy(p_ms_manmsg_struct_h->h_line+(int_l_int_loop-1),chr_l_str_temp);
		strcpy((char *)(p_ms_manmsg_struct_h->h_line+int_l_int_loop-1),chr_l_str_temp);
	}

	printf("\n****************************************************************\n");
	printf("CLN_CODE	-- |%s|\n", p_manual_message_struct_h -> h_cln_code);
	printf("CA_FLAG		-- |%s|\n", p_manual_message_struct_h -> h_ca_flag);
	printf("DL_FLAG		-- |%s|\n", p_manual_message_struct_h -> h_dl_flag);
	printf("CORP_ID		-- |%s|\n", p_manual_message_struct_h -> h_corp_id);
	printf("DL_REF_NO	-- |%s|\n", p_manual_message_struct_h -> h_dl_ref_no);
	printf("MSG_TXT		-- |%s|\n", p_manual_message_struct_h -> h_message_txt);
	printf("MAKER		-- |%s|\n", p_manual_message_struct_h -> h_maker);
	printf("MAKER_DT	-- |%s|\n", p_manual_message_struct_h -> h_maker_dt);
	printf("CHECKER		-- |%s|\n", p_manual_message_struct_h -> h_checker);
	printf("CHECKER_DT	-- |%s|\n", p_manual_message_struct_h -> h_checker_dt);
	printf("ACCESS_STAMP	-- |%s|\n", p_manual_message_struct_h -> h_access_stamp);
	printf("STATUS		-- |%s|\n", p_manual_message_struct_h -> h_status);
	printf("SWIFT_MSG_SEQNO -- |%s|\n", p_manual_message_struct_h -> h_msg_seq_no);
	printf("MSG_INDICATOR	-- |%s|\n", p_manual_message_struct_h -> h_msg_indicator);
	printf("ADDRESS_CLN	-- |%s|\n", p_manual_message_struct_h -> h_address_cln);
	printf("MANMSG_SEQNO	-- |%s|\n", p_manual_message_struct_h -> h_manmsg_seqno);
	printf("EVENT_ID	-- |%s|\n", event_id);
	printf("LINE[0]		-- |%s|\n", p_ms_manmsg_struct_h->h_line[0]);
	printf("LINE[1]		-- |%s|\n", p_ms_manmsg_struct_h->h_line[1]);
	printf("****************************************************************\n");

APL_GOBACK_SUCCESS // AIX - Warning removal

	RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_MANUAL_MESSAGE \n",NULL,NULL);
        return APL_SUCCESS;
/* AIX - Warning removal
	RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_MANUAL_MESSAGE \n",NULL,NULL);
        return 1;
*/
}
/***** JC - RFS_MS_001 -- End *****/

/******************** ASHISH 29-03-2007 ********** START ****************/
int Populate_IV_NRI_TDS(IV_NRI_TDS_STRUCT_H *p_iv_nri_tds_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

        CO_Rtv_DataString(p_param_data,"CLIENT_CODE",p_iv_nri_tds_struct_h -> h_client_code);
        CO_Rtv_DataString(p_param_data,"IDENTIRY_NO",p_iv_nri_tds_struct_h -> h_identiry_no);
        CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_iv_nri_tds_struct_h -> h_deal_date);
        CO_Rtv_DataDbl(p_param_data,"GROSS_AMT",&(p_iv_nri_tds_struct_h -> h_gross_amt));
        CO_Rtv_DataDbl(p_param_data,"TDS_AMT",&(p_iv_nri_tds_struct_h -> h_tds_amt));
        CO_Rtv_DataString(p_param_data,"MAKER",p_iv_nri_tds_struct_h -> h_maker);
        CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_nri_tds_struct_h -> h_maker_dt);
        CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_nri_tds_struct_h -> h_checker);
        CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_nri_tds_struct_h -> h_checker_dt);
        CO_Rtv_DataString(p_param_data,"STATUS",p_iv_nri_tds_struct_h -> h_status);
        CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_nri_tds_struct_h -> h_access_stamp);

APL_GOBACK_SUCCESS // AIX - Warnings rmeoval

RETURN_SUCCESS:
	 
	   CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_IV_NRI_TDS \n",NULL,NULL);
      return APL_SUCCESS;
/* AIX - Warnings rmeoval
RETURN_FAILURE:
      CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_IV_NRI_TDS \n",NULL,NULL);
      return 1;	
*/
}

/******************** ASHISH 29-03-2007 ********** END ****************/
