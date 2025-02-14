














typedef struct {
	char client[APL_CLIENT_LENGTH];
	char b_ccycd[APL_CCYCODE_LEN];
	char fees_ccy[APL_CCYCODE_LEN];
	char send_to_master_ind;
	char b_gen_ind;
	double minimumfee;
	char minimumfee_to;
	char min_hld_adj;
	char bcustsetup_access_stamp[APL_DATE_LEN];
	char dir_db_ind;
	char spl_clt_cd[7];
	char comm_clt[APL_CLIENT_LENGTH];
	char rec_clt[APL_CLIENT_LENGTH_GL]; /* Bageshri HDFCIV_001*/
	char information[241];
	double total_osamount;		/* Bageshri HDFCIV_001*/
	char default_feeclt[APL_CLIENT_LENGTH];
	double comm_tax_amt;
	char vat_cd[51]; 
	char vat_note[121];	 
	char oblg_lvl[21];				 /* Bageshri HDFCIV_001*/
	char oblg_typ[21];
	int pay_in_day;
	int pay_out_day;
	char b_freq;
	double pay_out_lmt;
	char dvp_ind;
	char acc_typ;
	char pay_in_acc[APL_CLIENT_LENGTH_GL];
	char pay_out_acc[APL_CLIENT_LENGTH_GL];
	char acc_code1[APL_CLIENT_LENGTH_GL];
	char acc_code2[APL_CLIENT_LENGTH_GL];
	char acc_code2desc[66];
	char oblig_rep_flg[3];
	char calc_basis;
	char portfolio_eval;
	char nav_ind;
	char ann_fee_month[16];
	char cln_supermst[APL_CLIENT_LENGTH];
	char bnk_acc[APL_CLIENT_LENGTH_GL];  /******************/
	char maximumfee_to;
	char max_hld_adj;
	double txnminfee;
	double txnmaxfee;
	double maximumfee; /* Bageshri */
	char lst_bill_dt[APL_DATE_LEN];/* vinay */
	char pymt_acc[APL_CLIENT_LENGTH_GL]; /* Bageshri */
        char bnk_fcy_acc[APL_CLIENT_LENGTH_GL]; /* YOG 211206 */
	char dir_db_date[3]; /* Bageshri HB_IV_001 START */
	char b_basis[4];
	char b_dlv_date[APL_DATE_LEN];
	int rep_pay_in_day;
	int rep_pay_out_day;
	char b_basis_cust[4]; /* Bageshri HB_IV_001 END */
	double ann_min_chrg;/*added by shruthi kumbla for ISKB_1737*/
} IV_CLIENTPARAM_STRUCT;

typedef struct {
	char client[APL_CLIENT_LENGTH];
	long service_cd;
	char parameter_cd[IV_PARAM_LEN];
	double minimumfee;
	double nil_fees;
	double maximum_fee;
	char fees_base[IV_STRING_LEN];
	char chrg_base[IV_STRING_LEN];
	char fees_class;
	char chrg_clas;
	char bcustsetup_access_stamp[APL_DATE_LEN];
	char dealadm_feeccy[APL_CCYCODE_LEN];
	char bill_acc[APL_CLIENT_LENGTH_GL];		/* Bageshri HDFCIV_001*/
	char lst_bill_date[APL_DATE_LEN];/* vinay */
	char b_freq;
	char incld_in_ann_min_fee;/*added by shruthi kumbla for ISKB_1737*/
         char pls_month[4]; /* Added for kotak ISKB_1737 */
	char apl_frm_date[9]; /* Added for kotak ISKB_1737 */
} IV_CLIENTSERVDEP_STRUCT_H;

typedef struct {
	char client[APL_CLIENT_LENGTH];
	long service_cd;
	char proc_data_val[IV_PARAM_LEN];
	char group_id[IV_GRP_LEN];
	double frm_cbase;
	double frm_fbase;
	double toc_base;  /* Added for Billing Structure Upload */
	double schdl_fee;
	char fee_type;
	char bcustsetup_access_stamp[APL_DATE_LEN]; 
	char apl_frm_date[9]; /* Added for kotak ISKB_1737 */
} IV_CUSTFEE_STRUCT_H;
