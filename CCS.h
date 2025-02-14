













 


#define MESSAGERR_LENGTH	600	
#define INMSG_LENGTH 22			
#define QUEUE_MANAGER_LEN	49
#define QUEUE_LEN	49
#define BUFFER_LENGTH 801



#define APL_BOOKING_OFFICE_LEN  9
#define APL_MESSAGE_TYPE_LEN 3
#define APL_REFERENCE_LENGTH 15 
#define APL_TLC_TRD_TYPE_LEN  2
#define APL_DEAL_CODE_LEN 3
/* OPT:AIX */
#ifdef  APL_INSTRUMENTCODE_LEN
#undef APL_INSTRUMENTCODE_LEN
#endif
#define APL_INSTRUMENTCODE_LEN 9 
#define APL_QTY_LEN 12
#define APL_AMT_LEN  19
#define APL_SIGN_LEN 2
#define APL_CASH_ACC_LEN 15
#define APL_MKT_DEAL_TYPE_LEN 3
#define APL_FAILCODE_LEN 3
#define APL_SUBFAILCODE 2
#define APL_FAILCODE_SEQ_LEN 4 
#define APL_NARRATIVE_LEN 71
/* OPT:AIX */
#ifdef APL_STATUS_LEN
#undef APL_STATUS_LEN
#endif
#define APL_STATUS_LEN 2
#define APL_SEQNO_LEN 7
#define APL_PARAM_LEN		4001
#define APL_ENVIRON_LEN		2001
#define APL_FUNCNAME_LENGTH	101
#define APL_FAILNOTE_LEN 211
#define APL_DEPOSITORY_LEN 4
#define APL_STATUS_QUAL_LEN 5 
#define APL_STATUS_CODE_LEN 7 
#define APL_REAS_QUAL_LEN 7 
#define APL_REAS_CODE_LEN 5 
#define APL_DT_LEN 9



#define ENV_CRD_RL	"USERIDCCSMODECRDRLFUNCTIONNAMECREDITRELEASE"


typedef struct{
			char	msg[MESSAGERR_LENGTH];
			char	status_ind[2];
			} EI_MQ_DATA_STRUCT_H;

typedef struct{
			char msg[INMSG_LENGTH];
			char status_ind[2];
			} EI_MQ_INCMSG_STRUCT_H;

typedef struct {
         char office_for_booking[APL_BOOKING_OFFICE_LEN];
         char msg_class[APL_MESSAGE_TYPE_LEN];
         char identity[APL_REFERENCE_LENGTH];
         char tlc_deal_type[APL_TLC_TRD_TYPE_LEN];
         char deal_code[APL_DEAL_CODE_LEN];
         char client[APL_CLIENT_LENGTH];
         char master_clt[APL_CLIENT_LENGTH];
         char clnt_ident [APL_TXNREFNO_LEN];
         char brk[APL_CLIENT_LENGTH];
         char instr_code[APL_INSTRUMENTCODE_LEN];
         double quantity;
         char currency_cd[APL_CCYCODE_LEN];
         double amount;
         char signature[APL_SIGN_LEN];
         char gl_clt[APL_CASH_ACC_LEN];
         char deal_date[APL_DT_LEN];
         char setl_date[APL_DT_LEN];
         char exp_setldate[APL_DT_LEN];
         char location_cd[APL_LOCNCODE_LENGTH];
         char mkrt_dl_class[APL_MKT_DEAL_TYPE_LEN];
         char cp_clt[APL_COUNTACC_LEN]; 
         
 
         char failreason_cd[APL_FAILCODE_LEN];
         int  sub_fail_cd; 
         char fail_det[71];
         int  failreason_index;
         char description[APL_NARRATIVE_LEN];
         char actual_setldt[APL_DT_LEN];
         char processdt[APL_DT_LEN];
         char access_stamp[APL_DT_LEN];
         char status_ind[APL_STATUS_LEN];
         char iden_no[APL_SEQNO_LEN];
         char depo[APL_DEPOSITORY_LEN];
	 char currencycodecurr[APL_CCYCODE_LEN];
         char status_qual_ind[APL_STATUS_QUAL_LEN];
         char status_cd[APL_STATUS_CODE_LEN];
         char reason_ql[APL_REAS_QUAL_LEN];
         char reason_cd[APL_REAS_CODE_LEN];
	 char h_cust_ext_ind[2]; 
                   }DL_CCSMSG_STRUCT_H;


typedef struct {
			short office_for_booking;
         short msg_class;
         short identity;
         short tlc_deal_type;
         short deal_code;
         short client;
         short master_clt;
         short clnt_ident;
         short brk;
         short instr_code;
         short quantity;
         short currency_cd;
         short amount;
         short signature;
         short gl_clt;
         short deal_date;
         short setl_date;
         short exp_setldate;
         short location_cd;
         short mkrt_dl_class;
         short cp_clt;
         short failreason_cd;
         short  sub_fail_cd;
         short fail_det;
         short  failreason_index;
         short description;
         short actual_setldt;
         short processdt;
         short access_stamp;
         short status_ind;
         short iden_no;
         short depo;
	 		short currencycodecurr;
         short status_qual_ind;
         short status_cd;
         short reason_ql;
			short reason_cd;
			short h_cust_ext_ind;
                   }DL_CCSMSG_STRUCT_I;
