














#include<MS_Swift.h>
/*#include<CR_Header_C.h>*/ 
#include<DL_Interface.h>

#define	NOPROC	"MNP"
#define	REJECT	"RJT"
#define	REPAIR	"RPR"	





#define SYS_NO_DATA                             2
#define SYS_RETURN_NO_DATA_FOUND                goto LBL_EXIT_NO_DATA;





typedef struct message_struct {
char                    msg_tag[6];
char                    qual[20];
char                    int_val[70];
char                    sequence[10];
char                    description[8000];
char			block_no[100];	
struct message_struct   *h_next;
} MESSAGE_STRUCT;

typedef struct{
char                    h_swift_msg_no[11];
char                    h_sequence[51];
char                    h_msg_tag[101];
char                    chr_h_qualifier[201];
char                    chr_h_val[51];
char                    h_wrapper_name[26];
char                    h_function_mode[36];
char                    h_proc_name[21];
char                    h_msg_name[7];
char			h_block_no[51];
}H_DSWRAPPERMAP_STRUCT;

typedef struct{
short   	         i_swift_msg_no;
short                    i_sequence;
short                    i_msg_tag;
short                    i_qualifier;
short                    i_val;
short                    i_wrapper_name;
short                    i_function_mode;
short                    i_proc_name;
short                    i_msg_name;
short                    i_block_no;
}I_DSWRAPPERMAP_STRUCT;


typedef struct{
char                    h_msg_name[7];
char                    chr_h_val[2];
char                    h_field_type[51];
char                    h_label[51];
char                    h_msg_tag[201];
char                    chr_h_qualifier[501];
char                    h_sequence[101];
char                    h_static_val[51];
char                    h_val_type[51];
int                     h_srl_num;
char			h_block_no[101];
char			h_repeat[2];
char			h_query[4001];
}H_DSPARAMMAP_STRUCT;

typedef struct{
short                   i_msg_name;
short                   i_val;
short                   i_field_type;
short                   i_label;
short                   i_msg_tag;
short                   i_qualifier;
short                   i_sequence;
short                   i_static_val;
short                   i_val_type;
short                   i_srl_num;
short                   i_block_no;
short                   i_repeat;
short                   i_query;
}I_DSPARAMMAP_STRUCT;




typedef struct holdings_struct {
char                    client[11];
char                    sec_isin[13];
char                    holding_type[70];
char                    quantity[20];
struct holdings_struct  *h_next;
} HOLDINGS_STRUCT;


typedef struct{
char                    swift_msg_no[11];
char                    sequence[11];
char                    tag_qualifier[51];
int                     sr_no;
int                     block_main_seq;
int                     inter_block_seq;
char                    parent[51];
char                    occurence_val[101];
}H_SEQUENCEMAP_STRUCT;

typedef struct{
short                   swift_msg_no;
short                   sequence;
short                   tag_qualifier;
short                   sr_no;
short                   block_main_seq;
short                   inter_block_seq;
short                   parent;
short                   occurence_val;
}I_SEQUENCEMAP_STRUCT;


typedef struct h_dfvalidatemap_struct {
char                    h_msg_name[7];
char                    h_field_name[50];
char                    h_typeofvldt[4];
char                    h_reqd[2];
char                    h_field_type[50];
char                    h_msg_tag[50];
char                    chr_h_qualifier[100];
char                    h_sequence[20];
char                    h_val_type[50];
char                    h_static_val[50];
char                    h_block_no[50];
char                    h_repeat[2];
char                    h_failreas[81];
char                    h_query[4000];
char			h_nation_code[3];
}DFVALIDATEMAP_STRUCT_H;


typedef struct i_dfvalidatemap_struct {
short                    i_msg_name;
short                    i_field_name;
short                    i_typeofvldt;
short                    i_reqd;
short                    i_field_type;
short                    i_msg_tag;
short                    i_qualifier;
short                    i_sequence;
short                    i_val_type;
short                    i_static_val;
short                    i_block_no;
short                    i_repeat;
short                    i_reas;
short                    i_query;
short                    i_nation_code;
}DFVALIDATEMAP_STRUCT_I;


typedef struct {
int		h_sequence_num;
char		h_swift_msg_no[7];
char		h_dl_client[11];
char		h_indentity_no[17];
char		h_msgfunc_code[4];
char		chr_h_param_str[4001];
char		h_deal_status[3];
char 		h_creater[15];
char 		h_create_dt[20];
char     h_authoriser[15];
char     h_authoriserdt[20];
char     h_timestamp[20];
char 		h_rprsts[3];
} CMSGREPAIR_STRUCT_H;



typedef struct {
short		i_sequence_num;
short		i_swift_msg_no;
short		i_dl_client;
short		i_indentity_no;
short		i_msgfunc_code;
short		i_proc_data;
short		i_deal_status;
short    i_creater;
short 	i_create_dt;
short 	i_authoriser;
short 	i_authoriserdt;
short 	i_timestamp;
short 	i_rprsts;
}CMSGREPAIR_STRUCT_I;



/*
typedef struct
{
char h_dl_client[11];
char h_indentity_no[17];
char h_securitycd[9];
char h_swift_msg_no[7];
char h_received_on[21];
char h_msg_func[36];
char h_mis_info[201];
char h_nameof_file[71];
char h_failure_reason[2001];
char h_report_ind[2];
char h_message_stat[4];
char h_rec_from_sent_to[51];
char h_msg_refno[36];
char h_msg_in_out_ind[2];
char h_trd_ca[2];
char h_evt_class[4];
char h_corp_id[21];

}DF_COMMON_MSGRPT_STRUCT_H;

typedef struct
{
short i_dl_client;
short i_indentity_no;
short i_securitycd;
short i_msg_name;
short i_received_on;
short i_msg_func;
short i_mis_info;
short i_nameof_file;
short i_failure_reason;
short i_report_ind;
short i_message_stat;
short i_rec_from_sent_to;
short i_msg_refno;
short i_msg_in_out_ind;
short i_trd_ca;
short i_evt_class;
short i_corp_id;

}DF_COMMON_MSGRPT_STRUCT_I;
*/
typedef struct
{
	short i_account;
	short i_ref_no;
	short i_secode;
	short i_msg_no;
	short i_received_on;
	short i_msg_func;
	short i_mis_info;
	short i_file_name;
	short i_failure_reason;
	short i_rep_flg;
	short i_msgsts;
	short i_rec_from_sent_to;
	short i_msg_refno;
	short i_in_out;
	short i_trd_ca;
	short i_event_type;
	short i_ca_id;
}DF_COMMON_MSGRPT_STRUCT_I;



typedef struct {
char                    client[11];
char                    security_cd[9];
double                    AGGR;
double                   TAVI;
double                  PENR;
double                    PEND;
double                    BLOK;
char                    DESC[201];
double                    CAGGR;
double                   CTAVI;
double                  CPENR;
double                    CPEND;
double                    CBLOK;
char  chr_date[20];
char agent[11];
char rstatus[3];
char STDATE[20];
}H_RSTAT_STRUCT;

typedef struct {
        short client ;
        short  security_cd;
        short  aggr;
        short  tavi;
        short penr;
        short pend ;
        short blok ;
        short detail;
        short caggr;
        short ctavi;
        short spenr;
        short spend;
        short cblok;
        short chr_date;
        short agent;
        short rstatus;
	short stdate;

}I_RSTAT_STRUCT;

typedef struct {
char                   client[11];
char                    security_cd[9];
double                    AGGR;
double                   TAVI;
double                  PENR;
double                    PEND;
double                    BLOK;
}H_RSAFEK_STRUCT;

typedef struct {
short   client ;
short   security_cd;
short   aggr;
short   tavi;
short   penr;
short   pend ;
short   blok ;
}I_RSAFEK_STRUCT;

typedef struct {
	char  h_dl_client[11];
	char  h_indentity_no[17];
	char  h_trail_for[2];
	char  h_processdetail[61];
	char  h_proc_usr[15];
	char  h_subprocess[4];
	char  h_logdate[20];
	char  h_fail_cd[3];
	double   h_qty;
	char  h_dlfromord[2];
	int   h_subfailreas_cd;
} DL_DEALAUDIT_STRUCT_H;



typedef struct {
	char  h_fail_cd[3];
	char  h_faildetail[33];
	char  h_interdetail[51];
	char  h_mapword[21];
	int   h_subfailreas_cd;
	char  h_status_qual_ind[5];
	char  h_status_cd[7];
	char  h_reason_ql[7];
	char  h_reason_cd[5];
	char  h_support_ind[1];
} PRO_FAILCODES_STRUCT_H;

extern int CDBGetFailcode( MESSAGE_STRUCT **p_message_list,
                           char           *p_tag,
                           char           *p_sequence,
                           char           *p_failreas_cd,
                           char           *p_subfailcode,
                           char           *p_block_no,
                           DEBUG_INFO_STRUCT_H   **l_debug_info_ptr);

extern int CDBGetNotes( MESSAGE_STRUCT  **p_message_list,
                        char            *p_tag,
                        char            *p_qual,
                        char            *p_sequence,
                        char            *p_value,
                        char            *p_description,
                        char            *p_block_no,
                        DEBUG_INFO_STRUCT_H    **l_debug_info_ptr);

extern int CDBFailMsgValidation( MESSAGE_STRUCT **p_message_list,
                                 char           *p_tag,
                                 char           *p_sequence,
                                 char           *p_block_no,
                                 DEBUG_INFO_STRUCT_H   **l_debug_info_ptr);

extern int CPopulateMisInfo(  MESSAGE_STRUCT   **p_message_list,
                              char             *p_misinfo,
                              DEBUG_INFO_STRUCT_H     **l_debug_info_ptr );



extern int CDBFailReasChk( MESSAGE_STRUCT    **p_message_list,
                           char              *p_msg_no,
                           char              *chr_p_client,
                           char              *chr_p_refno,
                           DEBUG_INFO_STRUCT_H      **l_debug_info_ptr );

extern int CDBDelTrdInRpr( char           *chr_p_client,
                           char           *chr_p_refno,
                           char           *int_p_retval,
                           DEBUG_INFO_STRUCT_H   **l_debug_info_ptr);





extern int ProcessMessage_54x(MESSAGE_STRUCT **p_message_list, char *p_message_path, FILE *fl_log,char *p_msg_no,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int InsCmsgLinkFn(char *p_str_client,char *p_str_refno,char *p_str_filename,char *p_str_msg_no,long p_lng_rpr_seq_num,DEBUG_INFO_STRUCT_H **l_debug_info_ptr); 

extern int InsComm_MsgRptFn(MESSAGE_STRUCT **p_msg_list,char *p_str_msg_name,char *p_str_fail_reason,char *p_str_msg_sts,char *p_str_filename,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int  InsCmsgRepairFn(char *p_str_client,char *p_str_refno,char *p_str_paramstr,char *p_str_msg_name, long  p_lng_rpr_seq_num,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DoValidateFn(char *p_str_msg_name, MESSAGE_STRUCT **p_msg_list,FILE *fl_log,char *p_str_msg_filename,char *p_str_status,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GetSubFunFn(MESSAGE_STRUCT **p_message_list,char *p_str_msg_name, char *p_str_val);
/*
extern int CDBPrtlSSTDetFn(DL_DEAL_SSTDET_STRUCT_H *l_dl_dealsstdet_struct_h,char *p_str_eventid,INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
*/



extern int ProcessMessage_548(MESSAGE_STRUCT **p_message_list, char *p_message_path, FILE *fl_log,char *p_msg_no,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int Get_misinfo(MESSAGE_STRUCT **p_msg_list, char *chr_p_filename,char *p_msg_name,  char *p_str_misinfo,char *p_str_funcmode ,char *p_mis_msg_name,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DFparse_error(char * p_err_desc, MESSAGE_STRUCT **p_msg_list,char *chr_p_filename, char *p_message_name,DEBUG_INFO_STRUCT_H **l_debug_info_ptr );  

extern int Update_Tables (char *p_str_mis_info , char *p_str_rprflg ,char *p_error_desc,  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int Parse_Error(char * p_err_desc, char *p_str_mis_info,char *chr_p_filename, char *p_message_name,DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
/*
extern int CPopulateAudTrl(char *chr_p_param_str, DL_DEALAUDIT_STRUCT_H *p_AudTrlStruct);
*/
extern int CPopulateDfCommonMsgrptStruct(char * p_str_misinfo, DF_COMMON_MSGRPT_STRUCT_H *p_df_common_msgrptStruct);

extern int CPopulateCmsglinkStruct(char *p_str_misinfo, DL_MSGLINK_STRUCT_H *p_cmsglinkStruct);

extern int CPopulateCmsglinkdetStruct(char *p_str_misinfo , DL_MSGLINKDET_STRUCT_H *p_cmsglinkdetStruct);

extern int CPopulateCmsgRepairStruct(char *p_str_misinfo,CMSGREPAIR_STRUCT_H *p_CmsgRepairStruct);



extern int GetMultiParamString(MESSAGE_STRUCT **l_message_list,
        char *chr_l_param_str,
        char *l_msg_name,
        DEBUG_INFO_STRUCT_H **l_debug_info_ptr,FILE *fp_log);
extern int GetTagCount(
    		MESSAGE_STRUCT   **p_message_list,
       	char*            p_tag,
       	char*            p_qual,
       	char*            p_sequence,
       	char*            p_block_no,
       	int*             p_tcount);
extern int DoRecon(MESSAGE_STRUCT **l_message_list,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,FILE *fp_log);
