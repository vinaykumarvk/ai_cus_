













 
typedef struct {
				char client[APL_CLIENT_LENGTH];
				long service_cd;
				int inden_num;
				char pymnt_clt[APL_CLIENT_LENGTH_GL];
				double pymnt_amount;
				char pymnt_currencycode[APL_CCYCODE_LEN];
				char pymnt_dt[APL_DATE_LEN];
				char bill_date[APL_DATE_LEN];  //ISKB430_08 --shailesh 03-12-2007
				double bill_amt; //shailesh ISKB-430-08
				double os_amt; //shailesh ISKB-430-08
				double tot_os_amt; //shailesh ISKB-430-08
				long old_service_cd;
				char h_tot_srv;
				char adjust;
				char purge_recall_ind;
				char first_service_pymt;
				char ae_dt[APL_DATE_LEN];
				char bpymt_access_stamp[APL_DATE_LEN];
				char	adjust_entry[2];
				char cheque_det[100];					 /* added by Vedavati HDFCIV_006 */ 
				char tds_amt[21];						 /* added by Vedavati HDFCIV_006 */ 
	       } IV_CLIENT_PYMT_STRUCT_H;
