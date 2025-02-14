

#define IPO_DEBUG 1
#define IPO_IF_DEBUG if(IPO_DEBUG) 

#define IPO_REPT_PAGERR_SIZE 75 
#define IPO_RPT_CRT_DEAL "%-12s\t%-20s\n"
#define IPO_RPT_UPD_DEAL "%-12s\t%-20s%20s\n"
#define IPO_RPT_DEL_DEAL "%-12s\t%-20s\n"
#define IPO_RPT_DEL_DEAL_REAS "%-12s\t%-20s\t%20s\n"
#define IPO_RPT_REJ_DEAL "%-12s\t%-20s\t%-100s\n"
#define IPO_RPT_REJ_SAT "%-12s\t%-20s\t%-12s\t%-12s\t%-12s\t%-100s\n"
#define IPO_RPT_UPD_SAT "%-12s\t%-20s\t%-12s\t%-12s\t%-11s\t%-12s\t%-12s\t\t%-11s\t%-30s\n"

#define IPO_ACCOUNT 	"CLIENT"
#define IPO_REF		"IDENTITY"
#define	IPO_QTY		"QTY"
#define	IPO_DOM_CP	"DOMESTIC CP"
#define	IPO_CP_DESC	"CP DESCRIPTION"
#define	IPO_CP_ACC	"CP ACCOUNT"
#define	IPO_SAT_ACC	"SAT ACCOUNT"
#define	IPO_SAT_CODE	"SAT CODE"
#define IPO_OPER_CODE 	"OPERATOR CODE"
#define	IPO_DEAL_DT	"TD"
#define	IPO_SETTL_DT	"SD"
#define	IPO_ISIN	"INSTR_ISIN"
#define	IPO_INSTRU_DESC	"INSTRUMENT"
#define	IPO_COUNTER_VALUE	"COUNTERVALUE"
#define	IPO_PRICE	"IPO PRICE"
#define IPO_COMMITSIZE 20
#define IPO_BUFSIZE 	50
#define SAT_NOTE3_FLD "A/AIPO"
#define IPO_BT_DEAL "29"
#define IPO_NORM_DEAL "28"
#define IPO_FILERR_SEP	','
#define IPO_FILERR_SEP_STRING ","
#define IPO_MAKERR_DEAL "UCT"
#define IPO_MODIFY_TRADE "UMT"
#define IPO_MODIFY_SAT "UMS"
#define IPO_MODIFY_BOTH "UMB"
#define IPO_MAN_FLD_CNT 15
#define IPO_DEAL_CODE "3"
#define IPO_LINERR_LENGTH 500
#define SAT_ACCOUNT_LEN 12
#define SAT_OPER_CODE_LEN 11
#define SAT_COMMITSIZE 20
#define OPERATOR_CODE   "OPER_CODE"
#define SERIAL_NUMBER   "SRL_NO"
#define SAT_CODE        "SAT_CODE"
#define SAT_ACCOUNT     "SAT_ACC"
#define SHORT_NAME      "SHRT_NAME"
#define ISIN            "INSTR_ISIN"
#define BAL_CD_INDENT    "BAL_CODE"
#define SETTLEMENT_DATE "SETL_DT"
#define QUANTITY        "QTY"


typedef struct{
char h_oper_cd[12];
char h_srl_no[11];
char h_sat_cd[12];
char h_sat_clt[12];
char h_instr_shortnm[16];
char h_instr_isin[13];
char h_bal_cd[5];
char h_setldt[9];
double h_qty;
}DL_SAT_REC_STRUCT_H;

typedef struct {
	int h_clt_pos;
	int h_ident_pos;
	int h_quantity_pos;
	int h_domestic_cp_pos;
	int h_cp_detail_pos;
	int h_cp_clt_pos;
	int h_satclt_pos;
	int h_sat_cd_pos;
	int h_oper_cd_pos;
	int h_dldt_pos;
	int h_setldt_pos;
	int h_instr_isin_pos;
	int h_instr_name_pos;
	int h_counter_val_pos;
	int h_ipo_pr_pos;
}DL_IPO_HEADER_POS_STRUCT_H;

typedef struct {
char h_dl_client[APL_CLIENT_LENGTH];
char h_indentity_no[17];
double h_qty;
char h_domestic_cp[66];
char h_cp_detail[50];
char h_cp_clt[APL_CLIENT_LENGTH];
char h_satclt[SAT_ACCOUNT_LEN+1]; /* Bageshri -- 10GM */
char h_sat_cd[SAT_ACCOUNT_LEN+1];
char h_oper_cd[SAT_OPER_CODE_LEN+1];	
char h_dlt[APL_DATE_LEN];
char h_setldt[APL_DATE_LEN];
char h_instr_isin[13];
char h_instr_name[9];
double h_counter_val;
double h_pr;
}DL_DEAL_IPO_STRUCT_H;
