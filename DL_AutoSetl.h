













 
#define  APL_MAXREASON_SIZE 101
#define  APL_FILENAME_LENGTH 13
#define  FILENAME_LEN_B 17
#define APL_MAXLINE_SIZE 350
#define COMMIT_COUNT_A 20
#define BUFF_SIZE 110
#define BRK_CD_LEN 13
#define  COMMIT_COUNT_G 5
#define  PAGELENGTH 55
#define  QUANTITY_LEN  26
#define  AMOUNT_LEN_B  19
#define  CNAME_LEN_A 66
#define  INSTR_NAME_LEN_D  131
 /* OPT:AIX - Start */
 #ifdef FILE_NAME_LEN
 #undef FILE_NAME_LEN
 #endif
 /* OPT:AIX - End*/
#define  FILE_NAME_LEN 30
#define  SEPARATOR "|"
/* OPT:AIX - Start */
#ifdef AMOUNT_LEN_B
#undef  AMOUNT_LEN_B
#endif
/* OPT:AIX - End*/
#define  AMOUNT_LEN_B  18
#define  LCL_FEED_SIZE 1000
#define  LCL_ISIN_LEN 13

typedef struct {
		long int 	h_rec_no;	
       		char     	h_ord_no[13];
       		char     	h_domestic_cp[7];
       		char     	h_dealcd[2];
       		double     	h_pr;
       		char     	h_dlt[APL_DATE_LEN];
       		char     	h_instr_isin[13];
		char		h_dl_client[12];
       		double     	h_qty;
       		double     	h_dl_val;
       		char     	h_ccy[4];
       		char     	h_settldate[APL_DATE_LEN];
       		double     	h_brokercomm;
       		char     	h_cln_code[11];
       		char     	h_auto_setl_dt[20];
       		char     	h_file_name[FILENAME_LEN_B];
       		char     	h_systemdt[APL_DATE_LEN];
       		char     	h_status_ind[6];
       		char     	h_failreas[APL_MAXREASON_SIZE];
       		char     	h_proc_ind[2];
       		char     	h_status_proc[2];
		} DL_AUTOBRKSETTL_STRUCT_H;

typedef struct {
		short		i_rec_no;	
       		short     	i_ord_no;
       		short     	i_domestic_cp;
       		short     	i_dealcd;
       		short     	i_pr;
       		short     	i_dlt;
       		short     	i_instr_isin;
		short		i_dl_client;
       		short      	i_qty;
       		short     	i_dl_val;
       		short     	i_ccy;
       		short     	i_settldate;
       		short     	i_brokercomm;
       		short     	i_client;
       		short     	i_auto_setl_dt;
       		short     	i_nameof_file;
       		short     	i_systemdt;
       		short     	i_status_ind;
       		short     	i_reas;
       		short     	i_proc_ind;
       		short     	i_status_proc;
		} DL_AUTOBRKSETTL_STRUCT_I;

