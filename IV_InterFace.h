

 
   
   
   
   
   
   
   
   
   
   
   

#ifndef IV_HEADER_INCLUDED
#define IV_HEADER_INCLUDED
#ifndef IDL_DOUBLERR_USED
#define IDL_DOUBLERR_USED
#endif
#ifndef IDLBASE_H
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#endif
#ifndef COMMON_INTERFACEHEADER_INCLUDED
#include <Intellect_Interface.h>
#endif

#define IV_IDENTIRY_NO_LEN 17    /* ASHISH 29-03-2007 */

/****** JC - RFS_MS_001 -- Start ******/
#define MA_CLN_CODE_LEN 11
#define MA_CA_FLAG_LEN 2
#define MA_DL_FLAG_LEN 2
#define MA_CORP_ID_LEN 21
#define MA_DL_REF_NO_LEN 21
#define MA_MESSAGE_TXT_LEN 4001
#define MA_MAKER_LEN 15
#define MA_CHECKER_LEN 15
#define MA_STATUS_LEN 3
#define MA_MSG_SEQ_NO_LEN 11
#define MA_MSG_INDICATOR_LEN 2
#define MA_ADDRESS_CLN_LEN 11
#define MA_MANMSG_SEQNO 11
/****** JC - RFS_MS_001 -- End ******/

typedef struct  {
char baseid[7];
char contact_details[15];
char swift_tlx_gcn;
char access_stamp[20];
} MS_BASENO_STRUCT_H;
typedef struct  {
char client[11];
long service_cd;
int inden_num;
char pymnt_clt[APL_CLIENT_LENGTH_GL];    /* Bageshri -- HDFC Log 97 */                  /* length changed by Vedavati for HDFCIV_006*/
double pymnt_amount;
char pymnt_currencycode[4];
char pymnt_dt[20];
char bill_date[20]; //shailesh 251007   - ISKB_430_08 Chgs
double bill_amt;//ISKB_430_08 Chgs
double os_amt;//ISKB_430_08 Chgs
double tot_os_amt;//shailesh 251007  ISKB_430_08
long old_service_cd;
char h_tot_srv;
char adjust;
char purge_recall_ind;
char first_service_pymt;
char ae_dt[20];
char bpymt_access_stamp[20];
char	adjust_entry[2];
char cheque_det[100];					 /* added by Vedavati HDFCIV_006 */ 
char tds_amt[21];						 /* added by Vedavati HDFCIV_006 */ 
} IV_CLIENT_PYMT_STRUCT_H;
typedef struct  {
char comm_a[11];
char payacc_a[11];
char maker[15];
char maker_dt[20];
char access_stamp[20];
char checker[15];
char checker_dt[15];
char comm_b[11];
char comm_c[11];
char comm_d[11];
char comm_e[11];
char comm_f[11];
char comm_g[11];
char comm_h[11];
char comm_i[11];
char tax_acc[11];
char payacc_b[11];
} IV_CLIENT_STRUCT;

/************** Vedavati HDFCIV_002 ******************/
typedef struct {
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
        char h_mcsclh[APL_CLIENT_LENGTH_GL]; /* KB_5878(MCS) charuta */
        char h_mcssetac[APL_CLIENT_LENGTH_GL];  /* KB_5878(MCS) charuta */
		char h_taxacc[APL_CLIENT_LENGTH_GL];/* KB_9306 Chitrlekha */
        /***************************/
}IV_CLIENTGL_STRUCT_H;

typedef struct  {
long service_cd;
char service_det[22];
char fees_class;
double minimum_fee;
char std_feeind;
char mastsub_ind;
char access_stamp[20];
char valid_fee_class;
char b_client[APL_CLIENT_LENGTH_GL];  /* Bageshri -- HDFC Log 97 */
char in_on_gen;
char status[3];
char maker[APL_USERID_LEN];  /* Bageshri -- HDFC Log 97 */
char maker_dt[APL_DATE_LEN];
char checker[APL_USERID_LEN];  /* Bageshri -- HDFC Log 97 */
char checker_dt[APL_DATE_LEN];
} IV_SERV_MAST_STRUCT;

typedef struct  {
char client[11];
long service_cd;/* For Other Services HDFCIV_008 vinay kalaskar */
char service_det[22];
char b_prd[20];
int inden_num;
double quantity;
double fees;
char b_ccycd[4];
char purge_recall_ind;
char access_stamp[20];
} IV_CLIENT_OTHSERV_STRUCT_H;
typedef struct  {
char b_prev_date[20];
char b_upto_date[20];
char b_processdt[20];
char b_dlv_date[20];
} IV_CNTRL_PARAM_STRUCT_H;
typedef char line_string[51];
typedef struct  {
char client[11];
char contact_details[15];
char priority_ind;
line_string h_line[200];
char maker[15];
char maker_dt[20];
} MS_MANMSG_STRUCT_H;
/************Praveen**********/
typedef struct  {
int sequence_no;
char identitylist[3900];
char client[11];
} IV_BUCKET_TXN_STRUCT;
/********** vinay kalaskar ********/
typedef struct  {
char mf_seqno[6];
char identitylist[3900];
char clientlist[3900];
} IV_MUTUAL_FUND_STRUCT;
/************************************/

/***** JC - RFS_MS_001 -- Start *****/
typedef struct{
        char h_cln_code[MA_CLN_CODE_LEN];
        char h_ca_flag[MA_CA_FLAG_LEN];
        char h_dl_flag[MA_DL_FLAG_LEN];
        char h_corp_id[MA_CORP_ID_LEN];
        char h_dl_ref_no[MA_DL_REF_NO_LEN];
        char h_message_txt[MA_MESSAGE_TXT_LEN];
        char h_maker[MA_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[MA_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_access_stamp[APL_DATE_LEN];
        char h_status[MA_STATUS_LEN];
        char h_msg_seq_no[MA_MSG_SEQ_NO_LEN];
        char h_msg_indicator[MA_MSG_INDICATOR_LEN];
	char h_address_cln[MA_ADDRESS_CLN_LEN];
	char h_manmsg_seqno[MA_MANMSG_SEQNO];
}MANUAL_MESSAGE_STRUCT_H;
/***** JC - RFS_MS_001 -- End *****/

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

extern int wrp_I_UpdBasenoFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_BASENO_STRUCT_H *p_ms_baseno_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlPaymentMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a,
     int *p_newseqnum,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlAccMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_STRUCT *p_iv_client_struct,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlServMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlOthServMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_I_UpdMsgStat(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_ora_rowid,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlCtrlParamMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CNTRL_PARAM_STRUCT_H *p_iv_cntrl_param_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_Imanmsg(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_MANMSG_STRUCT_H *p_ms_manmsg_struct_h_a,
     char chr_startflag,
     int *int_msgsrno,
     char corp_id[21],
     char event_id[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_I_AuthResetDelete(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     int int_p_msgsrno,
     char chr_p_msgno_a[4],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct BILL_MAINT_v1_0_epv_t {
int (*wrp_I_UpdBasenoFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_BASENO_STRUCT_H *p_ms_baseno_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlPaymentMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_PYMT_STRUCT_H *p_iv_client_pymt_struct_h_a,
     int *p_newseqnum,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlAccMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_STRUCT *p_iv_client_struct,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlServMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_SERV_MAST_STRUCT *p_iv_serv_mast_struct_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlOthServMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENT_OTHSERV_STRUCT_H *p_iv_client_othserv_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_I_UpdMsgStat)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_ora_rowid,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlCtrlParamMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CNTRL_PARAM_STRUCT_H *p_iv_cntrl_param_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_Imanmsg)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_MANMSG_STRUCT_H *p_ms_manmsg_struct_h_a,
     char chr_startflag,
     int *int_msgsrno,
     char corp_id[21],
     char event_id[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_I_AuthResetDelete)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     int int_p_msgsrno,
     char chr_p_msgno_a[4],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
} BILL_MAINT_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
