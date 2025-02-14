





#include "CR_Common.h"
#include <strings.h>


#define ERR_MSTACC_NOTFND  1

#define MIN(x,y) (( (x) < (y) ) ? (x) : (y))
#define MAX(x,y) (( (x) > (y) ) ? (x) : (y))

#define CORPACTTRADE 19

#define IV_SUCCESS 0
#define IV_CRITCAL_ERROR_IND 1
#define IV_NO_DATA_FOUND_ERR 2
#define IV_COLUMN_NULL_ERR  3
#define IV_PARAM_LEN 201
#define IV_PRODTYPE_LEN 4
#define IV_DESC_LEN  22
#define IV_STRING_LEN 31
#define IV_CLT_LEN 34
#define IV_DLCD_LEN 2
#define IV_DLTYPE_LEN 3
#define IV_TO_BASIS_MAX  99999999999999.9999
#define IV_REC_COMMIT_CNT 5
#define COMMIT_COUNT_F 5 
#define IV_GRP_LEN 51
#define IV_PASS_PARAM_LEN 1000
#define DEL_RW_NO 2000

#define IV_VERWITH_LEN 25


#define RNDDEC 4



#define MORE_THAN_ONE_ROW_FOUND	30
#define MST_CLI_SAME				31
	

#define PAGELENGTH 58
/* OPT:AIX -START*/
#ifdef BUFFER_LEN
#undef BUFFER_LEN
#endif
/* OPT:AIX - End*/
#define BUFFER_LEN  60

#define DR_CR_IND '0'
#define CREDIT_IND_A '1'


#define CUSTODYFEE 1
#define TXNFEE 2
#define ADM_CUST_FEE_IND 3
#define ADM_TXN_FEE_IND 4
#define AMEND_FEE_IND 5
#define FREECAFEE 6
#define VPCAFEE 7
#define CASH_DIV_FEE 8
#define IV_BONDINT_FEE 9
#define REPAIRFEE 10
#define LATETXNFEE 11
#define DELV_TXN_FEE 12
#define TURNAROUNDTXNFEE 13
#define IV_BOOKTRF_FEE 14 
#define VOLDISCOUNTFEE 15
#define TAXFEE         16
#define MANUALDEALFEE   25	
#define ANNUALMNTFEE   26	
#define EDUCESSFEE   28	
#define VIBERFREEFEE   30 
#define VIBERVPFEE     31 
#define UNDERBILLING 98
#define OVERBILLING 99
#define SPECIALBILLING 99999
#define MINFEECODE 99998
#define EXCESSCREDITFEE  99997 
#define CASH_ITEMS  99996
#define SETTALGEFEE 50
#define BOG_MSG_FEE 51        
#define DEPOFEE 17
#define BUCK_TXN_FEE 27
#define MUTUALFUND_TXN_FEE 29 
#define MAXFEECODE 99995 
#define BOND_RDM_FEE 61 
#define PUT_FEE 62 
#define CALL_FEE 63 
#define PTC_FEE 		64 
#define PART_BOND_RDM_FEE 65
#define PART_PUT_FEE 66
#define PART_CALL_FEE 67 
#define PART_PTC_FEE 68 /* vinay kalaskar */
#define PUT_CALL_FEE 69
#define MANDATORY_CA_FEE 70 /*shailesh*/
#define VOLUNTARY_CA_FEE 71
#define SEBI_AUC 34 /* Added by chitrlekha for kotak ISKB_1901 */
#define ANNUALMINFEE 99994 /*added by shruthi kumbla for ISKB_1737*/
#define PERLINE_SECURITY 33 /* Added for kotak ISKB_1737 */

#define INDIVIDUAL_BILLS 'A'
#define CONSOLE_POS_IND 'B'
#define CONSOLE_BILL_IND 'C'
#define CONSOLE_MINFEE_IND 'D'

#define	STATUS_UAUTH				"UU"
#define	STATUS_DEL_UAUTH			"DU"
#define	STATUS_AUTH					"AA"

typedef struct {
    char proc_data[100];
    char param_flag[50];
    double fees_qty;
    double chrg_quant;
	char Treps_flag[3];
    } IV_DATA_STRUCT_H;

typedef struct {
    char proc_data[100];
    char param_flag[50];
    double fees_qty;
    double chrg_quant;
	 double h_chrg;
	 char Treps_flag[3];
	} IV_DEAL_DATA_STRUCT_H;


typedef struct {
	char (*client)[APL_CLIENT_LENGTH];
	long no_of_clt;
	} CLIENT_STRUCT_H;

typedef struct {
	char map_type[21];
	char nation_code[APL_CTRY_CODE_LEN];
	char map_val[5];
	char map_desc[41];
	} PRO_SGENSTAT_STRUCT;

typedef struct {
	char b_prev_date[APL_DATE_LEN];
	char b_upto_date[APL_DATE_LEN];
	char b_processdt[APL_DATE_LEN];
	char b_dlv_date[APL_DATE_LEN];
	char generate_ind;
	char ae_ind;
	char last_dlv_date[APL_DATE_LEN];
	char archival_dt[APL_DATE_LEN];
	char last_rpt_date[APL_DATE_LEN];
	char b_gen_ind;
	} SYS_IVCONTROLPARAM_STRUCT;

typedef struct {
        short i_bl_prv_date;
        short i_bl_upto_date;
        short i_bill_deal_date;
        short i_bl_dlv_date;
        short i_generate_flag;
        short i_clt_gen_flg;
        short i_lst_dlv_date;
        short i_arch_date;
        short i_lst_rpt_date;
        short i_b_gen_flag;
       } I_SYS_IVCONTROLPARAM_STRUCT;

typedef struct {
	char client[APL_CLIENT_LENGTH];
	char b_ccycd[APL_CCYCODE_LEN];
	char send_to_master_ind;
	char b_gen_ind;
	double minimumfee;
	char date_of_input[APL_DATE_LEN];
	char minimumfee_to;
	char min_hld_adj;
	char maker[15];
	char maker_dt[APL_DATE_LEN];
	char access_stamp[APL_DATE_LEN];
	char dir_db_ind;
	char stat_ind;
	char spl_clt_cd[7];
	char comm_clt[APL_CLIENT_LENGTH];
	char rec_clt[APL_CLIENT_LENGTH_GL];  /* Bageshri HDFCIV_001*/
	char information[241];
	char default_feeclt[APL_CLIENT_LENGTH]; /* Bageshri HDFCIV_001*/
	double total_osamount;
	char last_pymt_date[APL_DATE_LEN];
	char last_pymt_ccy[APL_CCYCODE_LEN];
	double last_pymt_amt;
	double last_lost_amt;
	char checker[15];
	char checker_dt[APL_DATE_LEN];
	double comm_tax_amt;
	char fees_ccy[APL_CCYCODE_LEN];
	char vat_cd[51];  		
	char vat_note[121];  
	char oblg_lvl[21];			/* Bageshri HDFCIV_001*/
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
	char calc_basis;            /* Bageshri HDFCIV_001*********End*/
	char portfolio_eval;  /* HDFCIV_004 AVG Portfolio */
	char nav_ind;  /* HDFCIV_004 NAV */
	char ann_fee_month[16]; /* HDFCIV_004 Annual Maintenance Fee */
	char cln_supermst[APL_CLIENT_LENGTH];  	/* Bageshri HDFCIV_001*/
	char bnk_acc[APL_CLIENT_LENGTH_GL];     /* Bageshri HDFCIV_001*/
	/*char summary_rep[2];  	commented by Bageshri HDFCIV_001*/
	char maximumfee_to;/*vinay*/
	char max_hld_adj;
	double txnminfee;
	double txnmaxfee;
	double maximumfee;/*******/
	char lst_bill_dt[APL_DATE_LEN];/* vinay */
	char pymt_acc[APL_CLIENT_LENGTH_GL];  /* Bageshri */
        char bnk_fcy_acc[APL_CLIENT_LENGTH_GL]; /* YOG 211206 */
	char dir_db_date[3];/** vinay **/
	char b_basis[4];/** Bageshri  HB_IV_001 START **/
	char b_dlv_date[APL_DATE_LEN];
	int rep_pay_in_day;
	int rep_pay_out_day;
	char b_basis_cust[4];/** Bageshri  HB_IV_001 END **/
	double ann_min_chrg;/*added by shruthi kumbla for ISKB_1737*/

	} IV_CLIENTSETUP_STRUCT;

typedef struct {
	short i_dl_client;
	short i_bl_currencycode;
	short i_send_to_master_ind;
	short i_b_gen_flag;
	short i_minimumfee;
	short i_new_dt;
	short i_minimumfee_to;
	short i_min_hld_adj;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_dir_db_flag;
	short i_stat_ind;
	short i_spl_clt_cd;
	short i_comm_clt;
	short i_rec_clt;
	short i_footinfo;
	short i_def_fee_clt;
	short i_tot_os_amount;
	short i_lst_pymt_dt;
	short i_lst_pm_currencycode;
	short i_lst_pm_amount;
	short i_lstdlosamount;
	short i_checker;
	short i_checker_dt;
	short i_comm_tax_amount;
	short i_fee_currencycode;
	short i_vat_cd; 		
	short i_vatfootinfo;		
	short i_oblg_lvl;		/* Bageshri HDFCIV_001*/
	short i_oblg_typ;
	short i_pay_in_day;
	short i_pay_out_day;
	short i_b_freq;
	short i_pay_out_lmt;
	short i_dvp_ind;
	short i_acc_typ;
	short i_pay_in_acc;
	short i_pay_out_acc;
	short i_acc_code1;
	short i_acc_code2;
	short i_acc_code2desc;
	short i_oblig_rep_flg;
	short i_calc_basis;
	short i_portfolio_eval;	/* Bageshri HDFCIV_001*END*/
	short i_nav_ind;
	short i_ann_fee_month;
	short i_cln_supermst; 	/* Bageshri HDFCIV_001*/
	short i_bnk_acc;   /* Bageshri HDFCIV_001*/
	/*short i_summary_rep;     commented by Bageshri HDFCIV_001*/
	short i_maximumfee_to;/*vinay*/
	short i_max_hld_adj;
	short i_txnminfee;
	short i_txnmaxfee;
	short i_maximumfee;/*********/
	short i_lst_bill_dt;/* vinay */
	short i_pymt_acc;    /* Bageshri */
        short i_bnk_fcy_acc; /* YOG 211206 */
	short i_dir_db_date; /*** vinay ***/
	short i_b_basis; /*** Bageshri  HB_IV_001 START ***/
	short i_b_dlv_date;    
	short i_rep_pay_in_day;
	short i_rep_pay_out_day;
	short i_b_basis_cust; /*** Bageshri  HB_IV_001 END ***/
	short i_ann_min_chrg;/*added by shruthi kumbla for ISKB_1737*/
     } I_IV_CLIENTSETUP_STRUCT;


typedef struct {
	long service_cd;
	char service_det[IV_DESC_LEN];
	char fees_class;
    double minimum_fee;
	char std_feeind;
	char mastsub_ind;
    char access_stamp[APL_DATE_LEN];
	char valid_fee_class;
    char b_client[APL_CLIENT_LENGTH_GL];
   	char in_on_gen;
	char status[3];
	char maker[APL_USERID_LEN];
	char maker_dt[APL_DATE_LEN];
	char checker[APL_USERID_LEN];
	char checker_dt[APL_DATE_LEN];
	} IV_SERV_MAST_STRUCT;

typedef struct {
	short i_service_cd;
	short i_serv_detail;
	short i_fee_class;
	short i_minimum_fee;
	short i_std_feeind;
	short i_mastsub_ind;
	short i_access_stamp;
	short i_valid_fee_class;
	short i_b_dl_client;
	short i_in_on_gen;
	short i_status;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
       } I_IV_SERV_MAST_STRUCT;

typedef struct {
	char client[APL_CLIENT_LENGTH];
	long service_cd;
	char parameter_cd[IV_PARAM_LEN];
	char apl_frm_date[9];/*added by Monica for ISKB_1737*/
	} IV_CLIENTPARAM_STRUCT_H;

typedef struct {
	long service_cd;
	char comm_clt[APL_CLIENT_LENGTH];
	}IV_COMM_CLIENT_STRUCT_H;

typedef struct {
	char comm_clt[APL_CLIENT_LENGTH];
	char dc_flag;
	double fcy_amount;
	char f_ccy[APL_CCYCODE_LEN];
	double report_amt;
	char rep_currency[APL_CCYCODE_LEN];
	double lcl_amt;
	char lcy[APL_CCYCODE_LEN];
	char f_ccy_incl;
	long service_cd;
	}IV_COMM_AMT_STRUCT_H;

typedef struct {
	char client[APL_CLIENT_LENGTH];
	char ibbs_clt[APL_CLIENT_LENGTH];
	char mst_clt[APL_CLIENT_LENGTH];
	char dir_db_ind;
	char nation_cd[3];
	char cust_bl_currency[APL_CCYCODE_LEN];
	}IV_CLIENTDET_STRUCT_H;

typedef struct {
	char cust_bl_currency[APL_CCYCODE_LEN];
	char rec_currency[APL_CCYCODE_LEN];
	}MT_CCY_STRUCT_H;

typedef struct {
	double exch_rate1;
	double exch_rate2;
	double exch_rate3;
	double exch_rate4;
	}EXGRT_STRUCT_H;

typedef struct {
        short i_dl_client;
        short i_service_cd;
        short i_parameter_cd;
		short i_apl_frm_date;/*added by Monica for ISKB_1737*/
       } I_IV_CLIENTPARAM_STRUCT;
		

typedef struct {
	char client[APL_CLIENT_LENGTH];
	long service_cd;
	char fees_base[IV_STRING_LEN];
	char chrg_base[IV_STRING_LEN];
	char chrg_clas;
	char fees_class;
	double minimumfee;
	double nil_fees;
	double maximum_fee;
	char dealadm_feeccy[APL_CCYCODE_LEN];
/***************** Accounting Entries  vinay kalaskar HDFCIV_005 ***********************/
	char bill_acc[APL_CLIENT_LENGTH_GL];
	char lst_bill_dt[APL_DATE_LEN];/* vinay */
	char b_freq;/* vinay */
	char incld_in_ann_min_fee;/*added by shruthi kumbla for ISKB_1737*/
	char pls_month[4]; /* Added for kotak ISKB_1737 */
	char apl_frm_date[9]; /* Added for kotak ISKB_1737 */
	} IV_CLIENT_SERV_BASIS_STRUCT;
	
	

typedef struct {
         short i_dl_client;
         short i_service_cd;
         short i_fees_base;
         short i_chrg_base;
         short i_charge_class;
         short i_fee_class;
         short i_minimumfee;
         short i_nil_fees;
         short i_maximum_fee;
			short i_txnadmfeecurrencycode;
/***************** Accounting Entries  vinay kalaskar HDFCIV_005 ***********************/
		   short i_bill_acc;
			short i_lst_bill_dt;/* vinay */
			short i_b_freq;/* vinay */
			short i_incld_in_ann_min_fee;/*added by shruthi kumbla for ISKB_1737*/
			short i_pls_month;  /* Added for kotak ISKB_1737 */
			short i_apl_frm_date; /* Added for kotak ISKB_1737 */
        } I_IV_CLIENT_SERV_BASIS_STRUCT;


typedef struct {
        long service_cd;
        char fees_base[IV_STRING_LEN];
	char iv_cond[5];
        char chrg_base[IV_STRING_LEN];
        char chrg_vl_clas;
        char fees_val_class;
        } IV_SERV_BASIS_STRUCT;

typedef struct {
         short i_service_cd;
         short i_fees_base;
         short i_iv_cond;
         short i_chrg_base;
         short i_charge_value_class;
         short i_fee_value_class;
        } I_IV_SERV_BASIS_STRUCT;

typedef struct {
        char dateof_billing[APL_DATE_LEN];
        char client[APL_CLIENT_LENGTH];
        long service_cd;
        char cons_flag;
        char parameter_cd[IV_PARAM_LEN];
        char proc_data_val[IV_PARAM_LEN];
        double comm_amt;
        double chrg_quant;
        char b_ccycd[APL_CCYCODE_LEN];
        double fees_qty;
        char master_clt[APL_CLIENT_LENGTH];
        char group_id[51];
    } IV_DEAL_STRUCT;

typedef struct {
      short i_bill_date;
      short i_dl_client;
      short i_service_cd;
      short i_cons_flag;
      short i_parameter_cd;
      short i_proc_data_val;
      short i_cm_amount;
      short i_charge_quantity;
      short i_bl_currencycode;
      short i_fee_quantity;
      short i_mstclt;
      short i_group_id;
     } I_IV_DEAL_STRUCT;

typedef struct {
        char dateof_billing[APL_DATE_LEN];
        char client[APL_CLIENT_LENGTH];
        long service_cd;
        char cons_flag;
        char parameter_cd[IV_PARAM_LEN];
        double comm_amt;
        char proc_data_val[IV_PARAM_LEN];
        double schdl_fee;
        double chrg_quant;
        char b_ccycd[APL_CCYCODE_LEN];
        double fees_qty;
        char master_clt[APL_CLIENT_LENGTH];
        char group_id[51];
    } IV_DEAL_FEE_STRUCT;

typedef struct {
      short i_bill_date;
      short i_dl_client;
      short i_service_cd;
      short i_cons_flag;
      short i_parameter_cd;
      short i_cm_amount;
      short i_proc_data_val;
      short i_schdl_fee;
      short i_charge_quantity;
      short i_bl_currencycode;
      short i_fee_quantity;
      short i_mstclt;
      short i_group_id;
     } I_IV_DEAL_FEE_STRUCT;

typedef struct {
        char dateof_billing[APL_DATE_LEN];
        char client[APL_CLIENT_LENGTH];
        double nil_fees_adj;
        double minimumfee_adj;
        double maximum_fee_adj;
        double comm_amt;
        char b_ccycd[APL_CCYCODE_LEN];
        char cons_flag;
        long service_cd;
        char master_clt[APL_CLIENT_LENGTH];
		char incld_in_ann_min_fee;
    } IV_SERVICE_CHRG_STRUCT;

typedef struct {
	char frm_ccycd[APL_CCYCODE_LEN];
	char to_currency[APL_CCYCODE_LEN];
	double exchg_rt;
	char dateof_billing[APL_DATE_LEN];
	} IV_EXCHANGERATE_STRUCT;

typedef struct {
	char dateof_billing[APL_DATE_LEN];
        char client[APL_CLIENT_LENGTH];
 	char instr_code[APL_INSTRUMENTCODE_LEN];
        char parameter_cd[IV_PARAM_LEN];
        char proc_data_val[IV_PARAM_LEN];
	double mkrtpr;
        char b_ccycd[APL_CCYCODE_LEN];
	double safekeep_pos;
        char cons_flag;
	double exchg_rt;
    } IV_CLIENTHOLDING_STRUCT;	

typedef struct {
        short i_bill_date;
        short i_dl_client;
        short i_instr_code;
        short i_parameter_cd;
        short i_proc_data_val;
        short i_mktpr;
        short i_bl_currencycode;
        short i_safekeep_pos;
        short i_cons_flag;
        short i_exch_rt;
    } I_IV_CLIENTHOLDING_STRUCT;

typedef struct {
                 char process_name[40];
                 char start_dt[APL_DATE_LEN];
                 char status_ind[15];
                 char proc_init[40];
                 char processing_status[APL_CLIENT_LENGTH];
                 char usr[APL_USERID_LEN];
                 char eod_bod_ind;
                 char stat_det[71];
               } SYS_BATCHPROC_STRUCT_H;

typedef struct {
                 short int i_progclr_name;
                 short int i_startdt;
                 short int i_status_ind;
                 short int i_proc_init;
                 short int i_restart_info;
                 short int i_user;
                 short int i_eod_bod_flag;
                 short int i_stat_det;
               } SYS_BATCHPROC_STRUCT_I;

typedef struct {
                 long service_cd;
                 char client[APL_CLIENT_LENGTH];
                 char dateof_doc[APL_DATE_LEN];
                 int inden_num;
                 double service_amt;
                 double run_balance;
                 double out_stand_amt;
                 char class_ind;
                 char b_ccycd[APL_CCYCODE_LEN];
               } IV_LEDGER_STRUCT;

typedef struct {
                 short int i_service_cd;
                 short int i_dl_client;
                 short int i_doc_date;
                 short int i_sequence_num;
                 short int i_srv_amount;
                 short int i_run_balance;
                 short int i_os_amount;
                 short int i_class_ind;
                 short int i_bl_currencycode;
               } I_IV_LEDGER_STRUCT;

typedef struct {
                 char client[APL_CLIENT_LENGTH];
                 char dateof_payment[APL_DATE_LEN];
		         int inden_num;
                 char b_ccycd[APL_CCYCODE_LEN];
                 double conf_amt;
                 int pay_seq;
                 char maker[APL_USERID_LEN];
                 char maker_dt[APL_DATE_LEN];
                 char access_stamp[APL_DATE_LEN];
                 char status_pymt;
                 char checker[APL_USERID_LEN];
                 char checker_dt[APL_DATE_LEN];
		 char pymt_clt[APL_CLIENT_LENGTH_GL];  /* Bageshri -- HDFC Log 97 */					/* length changed from APL_CLIENT_LENGTH to APL_CLIENT_LENGTH_GL by HDFCIV_006 */	/* Bageshri Fix 28/05/2007 */
		 char ae_dt[APL_DATE_LEN];
                 int  proc_num;
		 			char	adjust_entry[2];
					char cheque_det[100];               /* added by Vedavati HDFCIV_006 */
					char tds_amt[21];                   /* added by Vedavati HDFCIV_006 */
					 char bill_date[APL_DATE_LEN];//shailesh ISKB_430_08  --03-12-2007
						double bill_amt;
						double os_amt;	
						double tot_os_amt;
						long service_cd; 
						char pymt_ind;//To indicate total wise,service-wise,direct-debit--//shailesh ISKB_430_08
               } IV_CHEQUE_STRUCT;

typedef struct {
                 short int i_dl_client;
                 short int i_pymt_dt;
		         short int i_sequence_num;
                 short int i_bl_currencycode;
                 short int i_pm_amount;
                 short int i_aut_sequencenum;
                 short int i_maker;
                 short int i_maker_dt;
                 short int i_access_stamp;
                 short int i_pymt_status;
                 short int i_checker;
                 short int i_checker_dt;
		 short int i_pymt_ac;
		 short int i_clt_gendt;
                 short int i_proc_num;
					short	i_adjust_entry;
					short int i_cheque_det;      /* added by Vedavati HDFCIV_006 */
					short int i_tds_amt;         /* added by Vedavati HDFCIV_006 */
					short int i_bill_date;//ISKB_430_08 Chgs
					short int i_bill_amt;//ISKB_430_08 Chgs
					short int i_os_amt;//ISKB_430_08 Chgs
					short int i_tot_os_amt;//ISKB_430_08 Chgs
					short int i_service_cd;//ISKB_430_08 Chgs
					short i_pymt_ind;//ISKB_430_08 Chgs
               } I_IV_CHEQUE_STRUCT;

typedef struct {
                 char client[APL_CLIENT_LENGTH];
                 int inden_num;
                 char dateof_payment[APL_DATE_LEN];
		         long service_cd;
                 double service_amt;
                 char status_paydet;
				 char bill_date[APL_DATE_LEN];//ISKB_430_08 Chgs
				 double bill_amt;//ISKB_430_08 Chgs
				 double os_amt;//ISKB_430_08 Chgs
				 double tot_os_amt;//ISKB_430_08 Chgs
               } IV_CHEQUE_DET_STRUCT;

typedef struct {
                 short int i_dl_client;
                 short int i_sequence_num;
                 short int i_pymt_dt;
		         short int i_service_cd;
                 short int i_srv_amount;
                 short int i_pymtdet_status;
				 short int i_bill_date;//ISKB_430_08 Chgs
				 short int i_bill_amt;//ISKB_430_08 Chgs
				 short int i_os_amt;//ISKB_430_08 Chgs
				 short int i_tot_os_amt;//ISKB_430_08 Chgs

               } I_IV_CHEQUE_DET_STRUCT;



typedef struct {
                 char client[APL_CLIENT_LENGTH];
                 long service_cd;
                 char b_upto_date[APL_DATE_LEN];
                 double service_qty;
                 char maker[APL_USERID_LEN];
                 char maker_dt[APL_DATE_LEN];
                 char access_stamp[APL_DATE_LEN];
                 char service_det[IV_DESC_LEN];
                 double schdl_fee;
                 char service_stat;
                 char checker[APL_USERID_LEN];
                 char checker_dt[APL_DATE_LEN];
		 int  inden_num;
               } IV_SERV_OTH_STRUCT;

typedef struct {
                 short int i_dl_client;
                 short int i_service_cd;
                 short int i_bl_upto_date;
                 short int i_serv_detail;
                 short int i_serv_quantity;
                 short int i_schdl_fee;
                 short int i_maker;
                 short int i_maker_dt;
                 short int i_access_stamp;
                 short int i_service_stat;
                 short int i_checker;
                 short int i_checker_dt;
                 short int i_sequence_num;
               } I_IV_SERV_OTH_STRUCT;


typedef struct {
                 char client[APL_CLIENT_LENGTH];
                 long service_cd;
                 char proc_data_val[IV_PARAM_LEN];
                 char group_id[IV_GRP_LEN];
                 double schdl_fee;
                 double frm_cbase;
                 double toc_base;
                 double frm_fbase;
                 double tof_base;
                 char service_stat;
		 char fee_type;
				char apl_frm_date[9]; /* Added for kotak ISKB_1737 */
               } IV_CLIENTFEE_STRUCT_H;

typedef struct {
                 short int i_dl_client;
                 short int i_service_cd;
                 short int i_proc_data_val;
                 short int i_group_id;
                 short int i_schdl_fee;
                 short int i_frm_cbase;
                 short int i_toc_base;
                 short int i_frm_fbase;
                 short int i_tof_base;
                 short int i_service_stat;
		 short int i_fee_type;
				short int i_apl_frm_date; /* Added for kotak ISKB_1737 */
               } I_IV_CLIENTFEE_STRUCT;


typedef struct {
               char  baseid[7];
               char  contact_details[201];	//Size changed from 15 to 201 by Sana
               char  swift_tlx_gcn;
               char  access_stamp[APL_DATE_LEN];
               }MS_BASENO_STRUCT_H;

typedef struct {
               short i_baseid;
               short i_contactinfo;
               short i_swift_tlx_gcn;
               short i_access_stamp;
               }MS_BASENO_STRUCT_I;


typedef struct {
		char swift_msg_no[7];
		char proc_init[61];
		long swift_msg_seqno;
		char client[APL_CLIENT_LENGTH];
                char info_file[31];
                long  swift_count;
                long  telex_count;
                long  fax_count;
                long  gcn_count;   
                long  clts_count;   
                char status_ind[2];
                char auto_tran_ind[2];
                char proc_data[201];
                char rowid[APL_ROWID_LEN];
	      }MS_MSGENT_STRUCT;

typedef struct {
            int  h_srl_num;
            char h_rep_dt[APL_DATE_LEN];
            char h_swift_msg_no[4];
            char h_nameof_file[31];
            char h_message_stat[4];
            char h_reject_reason[81];
            char h_report_ind;
				char h_setl_dt[APL_DATE_LEN];        
            char h_dl_client[APL_CLIENT_LENGTH];			
            char h_sfe_indentity_no[11];
         } MS_INMSGRP_STRUCT_H;

typedef struct {
            short i_srl_num;
            short i_rep_dt;
            short i_swift_msg_no;
            short i_nameof_file;
            short i_message_stat;
            short i_reject_reason;
            short i_report_ind;
				short i_setl_dt;                     
				short i_dl_client;								
            short i_sfe_indentity_no;
         } MS_INMSGRP_STRUCT_I;

typedef struct {
      char h_dl_client[11];
      char h_indentity_no[17];
      char h_rep_dt[APL_DATE_LEN];
      char h_failreas[4000];
      char h_report_ind;
   } DL_CCSFAILMSG_STRUCT_H;

typedef struct {
      short i_dl_client;
      short i_indentity_no;
      short i_rep_dt;
      short i_reas;
      short i_report_ind;
   } DL_CCSFAILMSG_STRUCT_I;

typedef struct {
		short i_swift_msg_no;
		short i_proc_init;
		short i_msg_sequence_no;
		short i_dl_client;
                short i_info_file;
                short i_swift_count;
                short i_telex_count;
                short i_no_of_fax_addr;
                short i_no_of_gcn_addr;   
                short i_no_of_clts;   
                short i_status_ind;
                short i_auto_tran_flag;
                short i_proc_data;
                short i_ora_rowid;
	      }I_MS_MSGENT_STRUCT;

typedef struct {
char	comm_a[APL_CLIENT_LENGTH];
char	payacc_a[APL_CLIENT_LENGTH];
char	maker[APL_USERID_LEN];
char	maker_dt[APL_DATE_LEN];
char	access_stamp[APL_DATE_LEN];
char	checker[APL_USERID_LEN];
char	checker_dt[APL_USERID_LEN];
char	comm_b[APL_CLIENT_LENGTH];
char	comm_c[APL_CLIENT_LENGTH];
char	comm_d[APL_CLIENT_LENGTH];
char	comm_e[APL_CLIENT_LENGTH];
char	comm_f[APL_CLIENT_LENGTH];
char	comm_g[APL_CLIENT_LENGTH];
char	comm_h[APL_CLIENT_LENGTH];
char	comm_i[APL_CLIENT_LENGTH];
char	tax_acc[APL_CLIENT_LENGTH];
char	payacc_b[APL_CLIENT_LENGTH];
}  IV_CLIENT_STRUCT;

typedef struct {
 short   i_comm_a;
 short   i_ac_pymt1;
 short   i_maker;
 short   i_maker_dt;
 short   i_access_stamp;
 short   i_checker;
 short   i_checker_dt;
 short   i_comm_b;
 short   i_comm_c;
 short   i_comm_d;
 short   i_comm_e;
 short   i_comm_f;
 short   i_comm_g;
 short   i_comm_h;
 short   i_comm_i;
 short   i_tax_acc;
 short   i_ac_pymt2;
}  I_IV_CLIENT_STRUCT;

typedef struct{
					char		client[APL_CLIENT_LENGTH];
					char		clnt_name[66];
					char		master_clt[APL_CLIENT_LENGTH];
					char		mst_clnt_clr_name[66];
					char		h_uniq_gcustody_id[13];
					char		clt_prd_code[6];
					char		bl_frm_date[APL_DATE_LEN];
					char		bl_to_date[APL_DATE_LEN];
					char		h_bill_ccy[4];
					double	fx_rt;
					double	minimum_fee;
					double	h_total_deal_fee;
					double	h_deal_fee;
					double	h_deal_adm_fee;
					double	h_deal_amd_fee;
					double	h_deal_rep_fee;
					double	h_deal_lat_fee;
					double	h_deal_del_fee;
					double	h_deal_trnar_fee;
					double	h_deal_int_fee;
					double	h_nil_sfk_fee;
					double	h_minimum_sfk_fee;
					double	h_total_fsfk_fee;
					double	h_sfk_fee;
					double	h_sfk_adm_fee;
					double	h_total_cafee;
					double	h_fee_cafee;
					double	pymt_ca_fee;
					double	h_cash_div_fee;
					double	h_bond_intr_fee;
					double	h_other_fee;
					double	h_over_bill;
					double	h_under_bill;
					double	h_custody_tax;
					double	h_spl_bill;
					double	h_total_fee;
					double	prv_os_amount;
					double	total_osamount;
					double	h_deal_vol;
					double	asset_under_cust;
					}IV_GPSS_STRUCT_H;

/******************* Vedavati HDFCIV_002 *****************************/

typedef struct{
        /* Bageshri -- HDFC Log 97 */
	char h_routac_a[APL_CLIENT_LENGTH_GL];
	char h_routac_b[APL_CLIENT_LENGTH_GL];
	char h_custsus[APL_CLIENT_LENGTH_GL];
	char h_nseclh[APL_CLIENT_LENGTH_GL];
	char h_bseclh[APL_CLIENT_LENGTH_GL];
	char h_nsesetac[APL_CLIENT_LENGTH_GL];
	char h_bsesetac[APL_CLIENT_LENGTH_GL];
	char h_rtgssetac[APL_CLIENT_LENGTH_GL];
	char h_fortrt[APL_CLIENT_LENGTH_GL];
	char h_cmsrt[APL_CLIENT_LENGTH_GL];
	char h_nsrsetac[APL_CLIENT_LENGTH_GL];
	char h_brok_pay[APL_CLIENT_LENGTH_GL];
	char h_stt_pay[APL_CLIENT_LENGTH_GL];
	char h_tds_pay[APL_CLIENT_LENGTH_GL];
	char h_tds_rec[APL_CLIENT_LENGTH_GL];
	char h_maker[APL_USERID_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[APL_USERID_LEN];
	char h_checker_dt[APL_DATE_LEN];
        char h_payacc[APL_CLIENT_LENGTH_GL];
        char h_payacc1[APL_CLIENT_LENGTH_GL];
        char h_casus[APL_CLIENT_LENGTH_GL];
        char h_toleracc[APL_CLIENT_LENGTH_GL];
        char h_recacc[APL_CLIENT_LENGTH_GL];
        char h_mcsclh[APL_CLIENT_LENGTH_GL]; /* KB_5878 Charuta */
        char h_mcssetac[APL_CLIENT_LENGTH_GL]; /* KB_5878 Charuta */
		char h_taxacc[APL_CLIENT_LENGTH_GL]; /* TAXACCOUNT added by chitrlekha for tax deduction KB_9306 */
        /****************************/
}IV_CLIENTGL_STRUCT_H;
typedef struct{
	short i_routac_a;
	short i_routac_b;
	short i_custsus;
	short i_nseclh;
	short i_bseclh;
	short i_nsesetac;
	short i_bsesetac;
	short i_rtgssetac;
	short i_fortrt;
	short i_cmsrt;
	short i_nsrsetac;
	short i_brok_pay;
	short i_stt_pay;
	short i_tds_pay;
	short i_tds_rec;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
        short i_payacc;
        short i_payacc1;
        short i_casus;
        short i_toleracc;
        short i_recacc;  /* Bageshri -- HDFC Log 97 */
        short i_mcsclh;  /* KB_5878 charuta */
	short i_mcssetac; /* KB_5878 charuta */
	short i_taxacc; /* TAXACCOUNT added by chitrlekha for tax deduction KB_9306 */
}IV_CLIENTGL_STRUCT_I;
/**********************************************************/
/* HDFCIV_004 PJ */
typedef struct {
	        char bill_dt[APL_DATE_LEN];
			  char client[APL_CLIENT_LENGTH];
			  long serv_code;
			  char settle_dt[APL_DATE_LEN];
			  double settle_qty;
			  double cm_amt;
			  char cons_ind;
			  char bl_ccycode[APL_CCYCODE_LEN];
			  char mstacc[APL_CLIENT_LENGTH];
			  char param_val[IV_PARAM_LEN];
			  char secode[APL_INSTRUMENTCODE_LEN];
			  double mktprice;
			  double exch_rate;
			  char identiy_no[17];
			  } blocdeptransac_struct;
typedef struct {
	        short i_bill_dt;
			  short i_client;
			  short i_serv_code;
			  short i_settle_dt;
			  short i_settle_qty;
			  short i_cm_amt;
			  short i_cons_ind;
			  short i_bl_ccycode;
			  short i_mstacc;
			  short i_param_val;
			  short i_secode;
			  short i_mktprice;
			  short i_exch_rate;
			  short i_identiy_no;
			 } i_blocdeptransac_struct;
typedef struct {
	        int sequence_no;
			  char identitylist[3900];
				char client[11];
          }IV_BUCKET_TXN_STRUCT;

/******** For MutualFund : vinay kalaskar **********/

typedef struct 
{
	char mf_seqno[6];
	char identitylist[3900];
	char clientlist[3900];
}IV_MUTUAL_FUND_STRUCT;

/**************************************************/

/* Bageshri 18/06/2007 : HDFC UAT Fix for detailed custody charges - START*/

typedef struct {
			char client[APL_CLIENT_LENGTH];
			long serv_code;
			char instr_code[APL_INSTRUMENTCODE_LEN];
			char bill_from_dt[APL_DATE_LEN];
			char bill_to_dt[APL_DATE_LEN];
			double qty;
			double mktprice;
			double cust_chrg;
			char bill_dt[APL_DATE_LEN];
			double exch_rate;
			char fee_ccycode[APL_CCYCODE_LEN];
			char port_eval;
			char mstacc[APL_CLIENT_LENGTH];
			double schdl_fee;
			char loc_code[5];
			char instr_sub_type[4];
			double portfolio;
			double feesccy_exch_rt;/*added by shruthi Kumbla for ISKB_1901*/
			  } ivcustprint_struct;

typedef struct {
			short i_client;
			short i_serv_code;
			short i_instr_code;
			short i_bill_from_dt;
			short i_bill_to_dt;
			short i_qty;
			short i_mktprice;
			short i_cust_chrg;
			short i_exch_rate;
			short i_fee_ccycode;
			short i_port_eval;
			short i_mstacc;
			short i_schdl_fee;
			short i_loc_code;
			short i_instr_sub_type;
			 } i_ivcustprint_struct;

/* Bageshri 18/06/2007 : HDFC UAT Fix for detailed custody charges - END */


/*******ASHISH 29-03-2007 IV_NRI_TDS *****START*********/
typedef struct{
        char h_client_code[APL_CLIENT_LENGTH];  /* Bageshri -- HDFC Log 97 */
        char h_identiry_no[17];
        char h_deal_date[APL_DATE_LEN];
        double h_gross_amt;
        double h_tds_amt;
        char h_maker[APL_USERID_LEN];  /* Bageshri -- HDFC Log 97 */
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[APL_USERID_LEN];  /* Bageshri -- HDFC Log 97 */
        char h_checker_dt[APL_DATE_LEN];
        char h_status[3];
        char h_access_stamp[20];
}IV_NRI_TDS_STRUCT_H;

/*******ASHISH 29-03-2007 IV_NRI_TDS *****END*********/

/**************ASHISH 29-03-2007***** IV_NRI_TDS START**********/
typedef struct{
        short i_client_code;
        short i_identiry_no;
        short i_deal_date;
        short i_gross_amt;
        short i_tds_amt;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_status;
        short i_access_stamp;
}IV_NRI_TDS_STRUCT_I;

/**************ASHISH 29-03-2007***** IV_NRI_TDS END**********/
/*****SHAILESH   ISKB_430*********04-12-2007*********************/
typedef struct {
                 char client[APL_CLIENT_LENGTH];
                 char bill_date[APL_DATE_LEN];
				 double bill_amt;
				 double os_amt;	
				 double unauth_pymt;
				 double  auth_pymt;
               }IV_CHEQUE_A_STRUCT;

typedef struct {
                 short  i_client;
                 short  i_bill_date;
				 short  i_bill_amt;
				 short  i_os_amt;	
				 short  i_unauth_pymt;
				 short  i_auth_pymt;
               }I_IV_CHEQUE_A_STRUCT;	

/*****SHAILESH   ISKB_430******************************/

/*added by siva.ganapathi for Annexures-- started*/

typedef struct {
                 char h_client[APL_CLIENT_LENGTH];
				 char h_identiy_no[17];
                 char h_bill_date[APL_DATE_LEN];
				 double h_depo_trans_fee;
				 double h_late_trans_fee;	
				 char h_depo_late_flag[2];
               }IV_DEAL_OTHFEE_STRUCT_H;

typedef struct {
                 short i_client;
				 short i_identiy_no;
                 short i_bill_date;
				 short i_depo_trans_fee;
				 short i_late_trans_fee;	
				 short i_depo_late_flag;
               }IV_DEAL_OTHFEE_STRUCT_I;

/*added by siva.ganapathi for Annexures -- ended*/
extern char chr_g_bl_sys_dt[APL_DATE_LEN];
extern char chr_g_bl_upto_dt[APL_DATE_LEN];
extern char chr_g_bl_prv_dt[APL_DATE_LEN];
extern char chr_g_bl_proc_dt[APL_DATE_LEN];
extern char chr_g_def_fee_acc[APL_CLIENT_LENGTH];
extern char chr_regen_flg;
extern char chr_g_bill_dep[4];
extern char chr_g_bl_ccycode[APL_CCYCODE_LEN];
extern char chr_g_fee_ccycode[APL_CCYCODE_LEN];        
extern  double g_exchg_rt_fee_bl; 
extern int int_g_ccy_decimallen; 
extern int int_g_blccy_decimallen;
extern char chr_g_bl_gen;
extern char chr_g_country[APL_CTRY_CODE_LEN];
extern char chr_g_cb_code[APL_CLIENT_LENGTH];
extern long  g_late_txn_days;
extern char chr_g_restart_client[APL_CLIENT_LENGTH];
extern int int_bl_err_level;
extern int int_g_diff;
/*extern SYS_IVCONTROLPARAM_STRUCT g_sys_ivcontrolparam_struct;*/
extern SYS_BATCHPROC_STRUCT_H l_sys_batchproc_struct_hb;
extern SYS_BATCHPROC_STRUCT_I l_sys_batchproc_struct_i;
extern char chr_g_batch_in_proc_rowid[APL_ROWID_LEN];
extern short int_i_batch_in_proc_rowid;
extern FILE *fp;
extern FILE *TechRep;
extern int int_g_viber_condexists; 
extern int  IV_Proc_CalculateBills(char **,DEBUG_INFO_STRUCT_H **);

extern int  IV_Rtv_ParamVal(char *, char *,long ,int *,DEBUG_INFO_STRUCT_H **);

extern int  IV_Chk_Grp(char *, char *, char **,char *,int,char *,char *,int *,DEBUG_INFO_STRUCT_H **);   /*Modified by Monica for ISKB_1737*/
extern int  IV_Rtv_ExchRate(char *,char *,char *,double *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_Fee(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_FeeParam(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_FeeSetup(char *,int *,DEBUG_INFO_STRUCT_H **, char); 
extern int  IV_Chk_MktPrc(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_OthSrv(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_CcySetup(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_GenCustodyChgs(char *,char *,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_GenTxnCharges(char *,char *,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_OtherCharges(char *,char *,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_ConsolidatedCharges(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_MinFeeAdjust(char ,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_TransactionFn(char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Rtv_GetServBasis(char *,long ,IV_CLIENT_SERV_BASIS_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_CalcFee(char *,char *,long,char *,char *,char *,double,double,char,char,double *, IV_DATA_STRUCT_H *,char,char *,char *,char *,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_SubCharges(char *,long,IV_DEAL_STRUCT * ,char,char,char,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_GrpMember(char *,long,char *,char *,int *,int *,DEBUG_INFO_STRUCT_H **);  /* Added by monica for kotak ISKB_1737 */
extern int IV_Chk_IsFeeExists(char *,long,int *,int *,DEBUG_INFO_STRUCT_H **);
extern int IV_Rtv_GetMasterAcc(char *,char *,DEBUG_INFO_STRUCT_H **);
extern int IV_Mod_DelSelaAccounts(int *, DEBUG_INFO_STRUCT_H **); 
                  

extern int  IV_Rtv_IVCNTLPARAM(SYS_IVCONTROLPARAM_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Rtv_IVSRVCHRGDel(long,IV_SERV_MAST_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  BBSelBCUSTPARAM(char *,long,IV_CLIENTPARAM_STRUCT_H *,int *,DEBUG_INFO_STRUCT_H **);
extern int  BBSelBCUSTSETUP(char *,IV_CLIENTSETUP_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  BBSelBSRVBASIS(char *,long,IV_CLIENT_SERV_BASIS_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_IVSRVCHRGNew(char *,char *,double, double, double, double,
                               char *,char,long,char *,char,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_TotIVSERVCHARGE(char *,char,double *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_MinFeeIVSERVCHARGE(char *,double *,int *,DEBUG_INFO_STRUCT_H **);

extern int  BBInsBTRANSAC(char *,char *,long,char,char *,char *,double,double,char *,double,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Rtv_IVTRANSAC(char *,char,long,char *,IV_DEAL_STRUCT *,int *,DEBUG_INFO_STRUCT_H **);
extern int  BBDbInsBACCTSAFEK(char *,char *,char *,char *,char *, double ,
                             char *,double,char,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_ConIVACCTSAFEK(int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Rtv_NewIVACCTSAFEK(char *,int *, DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_IVEXCHRTNew(char *,char *,char *, double ,
							  int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_CalcTxnServFee(char *,long ,double ,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_CalcNoAmend(char *,double *,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_GenerateBill(char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_DelBillDet(char *,char ,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_CalcNoTrd(char *,char *,double *,char,char,char,char *,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Proc_CalcCountervalue(char *,char *,double *,char,char *,int *,DEBUG_INFO_STRUCT_H **);

extern int  IV_Mod_Num1DLTrade(char *,char,double,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Mod_Num2DLTrade(char *,char,double,int *,DEBUG_INFO_STRUCT_H **);
extern int  UpdBillDtForExcTrade(char *,double,char *,char,int *,DEBUG_INFO_STRUCT_H **);
extern int  IV_Chk_PosnExistTrd(char *,int *,DEBUG_INFO_STRUCT_H **);

char *strtok_r(char *s1, const char *s2, char **lasts); /* PJ */
extern int  IV_Proc_CalcNoLateTxns(char *,double *, int *, DEBUG_INFO_STRUCT_H **);
extern int  BBInsBLOCDEPTRANSAC(char *,char *,long,char *,double,double,char,char *,char *,char *,char *,double,double,char *,int *,DEBUG_INFO_STRUCT_H **); /* PJ */

extern int val_perTxnIV_DEAL(char *,long,char,char *,char *,int *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int val_perTxnIV_DEAL_UPDATE(char *,long,char,char *,char *,double,double,char *,double,char *,char *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_Mod_DL_DEAL_UPDATE(char *,char *,double,int *, DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_chk_BillFreq(char *,long,int *,int *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int val_MF_IV_DEAL_UPDATE(char *,long,char,char *,char *,double,double,char *,double,
					char *,char *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int MF_IV_Mod_IVSRVCHRGNew(char *,char *,double,double,double,double,char *,char,long,char *,char,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_Proc_CalcMFTxnFee(char *,long,double,double,char *,char *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_PutCallTradeCnt(char *,double *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_PartPutChrg(char *,double *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_PtcAmountCalc(char *,char *,double *,int *,DEBUG_INFO_STRUCT_H **);/*vinay*/
extern int IV_New_CustPrint(char *,char *,char *,char *,double,double,double,char *,double,char *,char,char
*,double,char *,char *,double,double,int *,DEBUG_INFO_STRUCT_H **);/*added by shruthi kumbla for ISKB_1901*/



