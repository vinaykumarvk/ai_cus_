














#ifndef MESSAGERR_H
#define MESSAGERR_H

#include "CR_Common.h"


extern FILE *l_data_file;



#define MSTMTCONFMSGNO            1
#define MADVRECDELMSGNO           2
#define MCORPACTIONSMSGNO         3
#define MHOLDINGSMSGNO            4
#define MSTMTTRANMSGNO            5
#define MSTMTPENDINGMSGNO         6
#define MCASHPROJMSGNO            7
#define MREGISTRATIONMSGNO        8
#define MCANBLOCKTRDMSGNO         9
#define MORDEREXPMSGNO            10
#define MFAILADVICEMSGNO          11
#define MMANUALMSGNO              12
#define MDATERANGEMSGNO           13
#define MEOMTELEXMSGNO            13
#define MBILLSMSGNO               15
#define MTELEXMSGNO               13
#define MTRDCONFRPTMSGNO          14
#define MPORTFOLRATIOMSGNO        16          
#define MVTBMESSAGENO             17       
#define MORDEXECANMSGNO           18
#define MVTBCANCELMSGNO           19
#define MCANCELMSGNO              20
#define MSETLPROBMSGNO            21
#define MCORPACTIONSSMMSGNO       31

#define MNOSTROACCMSGNO           32

#define MBROKERMSGNO            35
#define MALLGDETMSG             36
#define MINTRAPOSADV            37
#define MAXSWIFTLEN  1650
#define ENDFIELD 65


#define MAXSWIFTLENISO15022 9550

        


#define IPRICELEN 25
#define APL_FUNC_REL "RSL"
#define APL_FUNC_RSND "RSN"


#define MAX_TAGS 700 /** tux changed to 600 .... i learned a lot of things at memory , Changed to 700 on 30/05/2012***/



extern fpos_t g_cur_pos;
extern fpos_t g_prev_pos;
extern int int_fnoopen;
extern int int_clsstat;

extern fpos_t g_curr_rec_start;        
extern fpos_t g_prev_rec_start;        
extern int int_g_curr_rec_no;           
 


#define  MS_MSGNO_592              "592"
#define  I_MSGNO_521          "521"
#define  I_MSGNO_522          "522"
#define  I_MSGNO_523          "523"
#define  I_MSGNO_520          "520"


#define  I_MSGNO_530          "530"
#define  I_MSGNO_532          "532"
#define  I_MSGNO_544          "544"
#define  I_MSGNO_546          "546" 




#define	EMU_EFFD_8	"20010101"
#define	EMU_MNVA	"0,01"
#define	EMU_EFFD_6	"010101"
#define	EMU_EFFD_T_6	"010101"      





#define FTP_ADD1        "LONIF"
#define FTP_ADD2        "XNYPW"




#define  MSG_FLG_53X                  "A"
#define  MSG_FLG_572                  "B"

#define  MSG_FLG_539                  "C" 

#define  MSG_FLG_52X_EURO                             "E"
#define       MS_CRF_52XN02                                   "35"

#define  MSG_RESET   "R"   
#define  MSG_INTERMEDIATE  "I"   
#define  FLG_WITTAXREP     "W"   

#define  MSG_FLG_WEEKLY_STM       "Z" 
#define  MSG_FLG_WEEKLY_INTM       "X" 
#define  RESET_FLG       "P" 



#define DEAL_REPAIR_SEQNAME          "INMTRADEREP"
#define DEALFRMORD_FAILCODE            "90"
#define DEALFRMORD_VERWITH             "MT521/MT523"
#define DEALFRMORD_VERWITH_NEW         "MT541/MT543"
#define LINERR_LENGTH                   40
#define EXARENA                       "2"
#define H_EURO_DUMMY_CLI              "991566"
#define PARAM_STR_LEN            	400
#define ISO_LINERR_LENGTH              50 
#define ISO_FILERR_LINERR_LENGTH         100


#define  I_MSGNO_540          "540"
#define  I_MSGNO_541          "541"
#define  I_MSGNO_542          "542"
#define  I_MSGNO_543          "543"




#define  I_RJT          "010"
#define  I_RPR          "020"
#define  I_NEW_STP      "030"
#define  I_CANC_STP     "040"
#define  I_MSGNO_54S_RJT      "050"
#define  I_MSGNO_54S_STP      "060"
#define  I_MSGNO_548N02       "080"
#define  I_MSGNO_548N01       "100"





#define START_ADDINFO   ":16R:ADDINFO"
#define END_ADDINFO   ":16S:ADDINFO"
#define START_OTHRPRTY   ":16R:OTHRPRTY"
#define END_OTHRPRTY   ":16S:OTHRPRTY"

#define MEOR_MACRO    ":95P::MEOR//"
#define MERERR_MACRO      ":95P::MERE//"

#define  DEAL_PREMATCHED     "The Trade is prematched."
#define  REJREAS_CONFDEAL_MOD   "The Confirmed Trade is Modified."
#define  DEAL_GENERATED      "The Trade is Generated."





typedef struct{ 
 char				msg_tag[6]; 
 int				identity_no;
 char				info_elem[31];
 char				info_type;
 char          head_cont_newline;
 char				msg_tag_cond[201];
 int           srl_num;
 char          print_cd;
     }  MS_TAG_ELM_STRUCT_H;

typedef struct{
 short i_msg_tag;
 short i_sequence_no;
 short i_info_elem;
 short i_data_class;
 short i_sequence_cat;
 short i_tag_iv_cond;
 short i_srl_num;
 short i_print_cd;
     }  MS_MAP_TAG_STRUCT_H;


typedef struct{
 int 				 identity_no;
 char				 ind[3];
 int				 par_seqno;
 char				 seq_condition[201];
 int				 sequence_rep_no;
 int				 child_sequence_rep_no;
     }  MS_SEQ_ELM_STRUCT_H;


typedef struct{ 
 char				 msg_tag[6];
 char				 h_data_val[201];
 int				 identity_no;
 int				 REP_NO;
 int				 PAR_REP_NO;
 char				 head_cont_newline;
 int            srl_num;
 char				 print_cd;
     }  MS_VAL_ELM_STRUCT_H;



typedef struct {
 char				 link_val[201];
 double                          link_tag;
 char				 inc_iv_cond[201];
 char                            res_iv_cond[201];
 double                          PREV_VAL;
     }  MS_CALC_ELM_STRUCT_H;

typedef struct {
 char				 link_val[201];
 char				 link_tag[501];
 double				 NUM_VAL;
     }  MS_STATIC_VAL;

typedef struct{
 char				 client[11];
 char				 message_ind[61];
 char				 swift_msg_no[7];
 char				 maker[15];
 char				 maker_dt[APL_DATE_LEN];
 char				 status_ind;
 char				 msg_in_out_ind;
 char				 msg[31];
 char                            contact_details[201];
 char                            contact_details1[201];
 char                            baseid[7];
 char				 message_class;
 char                         swift_msg_ident[17];
 char				 checker[APL_USERID_LEN];
 char				 checker_dt[APL_DATE_LEN];
 char				 access_stamp[APL_DATE_LEN];
    } MS_MSGLOG_STRUCT;

typedef struct{
 short int client;
 short int message_ind;
 short int swift_msg_no;
 short int maker;
 short int maker_dt;
 short int status_ind;
 short int msg_in_out_ind;
 short int msg;
 short int contact_details;
 short int contact_details1;
 short int baseid;
 short int message_class;
 short int swift_msg_ident;
 short int checker;
 short int checker_dt;
 short int access_stamp;
    } MS_MSGLOG_I_STRUCT;

typedef struct{
 char  				 proc_init[61];
 char			   	 swift_msg_rep[61];
 char                            client[11];
 char 				 generate_dt[APL_DATE_LEN];
    } MS_MSGSTAT_STRUCT; 



 typedef struct {
                char  h_deal_code[2];
                char  swift_msg_no[4];
                char  setl_dt[20];
                char  indentity_no[17];
                char  addindentity_no[17];
                char  dl_dt[20];
                char  dl_loc[5];
                char  instr_name[121];
                char  instr_code[9];
                char  inst_client[11];
                char  inst_clnt_clr_name[66];
                char  cp_clt[16];
                char  countclt_cname[66];
                char  domestic_cpclt[11];
                char  domcpclt_cd_cname[66];
                char  clientof[36];
                char  currency_code[4];
                double   amount;
                char     info[266];
					 char gl_client[11];
					 char dl_class[3];
                }MS_52X_STRUCT_H;


typedef struct {
                  char     swift_msg_no[4];
                  char     indentity_no[17];
                  char     rel_indentity_no[17];
                  char     vtb_client[11];
                  char     instr_code[9];
                  char     instr_name[36];
                  double   quantity;
                  char     setl_date[20];
                  char     deal_date[20];
                  char     cp_clt[11];
                }MS_53X_STRUCT_H;



typedef  struct   {
                   char     client[11];
                   char     clnt_name[66];
                   double   quantity;
                   }MS_REP_STRUCT_H;



 typedef struct {
                char  can_swift_msg_no[17];
                char  txn_indentity_no[17];
                char  deal_cd[4];
                char  txn_class[2];
                char  txn_date[20];
                char  txn_clt[11];
                char  txn_clnt_clr_name[36];
                char  dl_dt[20];
                char  instr_isin_no[36];
                char  instr_name[36];
                char  instr_class_val[36];
                char  domestic_cp[11];
                char  domcpdetail[36];
                char  currency_value[36];
                }MS_59X_STRUCT_H;

typedef struct {
						char h_dl_client[APL_CLIENT_LENGTH];
						char h_indentity_no[APL_TXNREFNO_LEN];
						char h_locindentity_no[APL_TXNREFNO_LEN];
						char h_verfied_with[26];
						double h_diffamount;
						double h_amt;
						char h_info1[261];
						char h_custinfo[71];
						char h_failinfo[261];
						char h_brkrno[36];
						char h_deal_status[3];
						char h_access_stamp[APL_DATE_LEN];
					} DEAL_DET_STRUCT_H;

typedef struct {
						short int i_dl_client;
						short int i_indentity_no;
						short int i_locindentity_no;
						short int i_verfied_with;
						short int i_diffamount;
						short int i_amt;
						short int i_info1;
						short int i_custinfo;
						short int i_failinfo;
						short int i_brkrno;
						short int i_deal_status;
						short int i_access_stamp;
					} DEAL_DET_STRUCT_I;



typedef struct {
						char h_dl_client[APL_CLIENT_LENGTH];
						char h_indentity_no[APL_TXNREFNO_LEN];
						char h_msg_in_out_ind[2];
						char h_swift_msg_no[7];
						char h_new_dt[APL_DATE_LEN];
						char h_information[31];
						int h_sequence_num;
						int h_dlrep_sequencenum;
						char h_message_det_a[2001];
						char h_message_det_b[2001];
						char h_message_det_c[2001];
						char h_message_det_d[2001];
						char h_message_det_e[2001];
						char  h_psetparty[161];
						char  h_place_cd[5];
						char  h_description[41];
					} DL_MSGLINK_STRUCT_H;

typedef struct {
						short int i_dl_client;
						short int i_indentity_no;
						short int i_msg_in_out_ind;
						short int i_swift_msg_no;
						short int i_new_dt;
						short int i_information;
						short int i_sequence_num;
						short int i_dlrep_sequencenum;
						short int i_message_det_a;
						short int i_message_det_b;
						short int i_message_det_c;
						short int i_message_det_d;
						short int i_message_det_e;
						short int i_psetparty;
						short int i_place_cd;
						short int i_description;
					} DL_MSGLINK_STRUCT_I;

typedef struct {
						int h_sequence_num;
						char h_sequence_name[6];
						char h_link_val[6];
						char h_link_msg_tag[51];
						int h_msg_tag_rep_no;
						int h_msg_line_no;
						char    h_msg_tag[6];	
					} DL_MSGLINKDET_STRUCT_H;

typedef struct {
						short int i_sequence_num;
						short int i_sequence_name;
						short int i_link_val;
						short int i_link_msg_tag;
						short int i_msg_tag_rep_no;
						short int i_msg_line_no;
						short int i_msg_tag;
					} DL_MSGLINKDET_STRUCT_I;

/* typedef struct {
						char h_corp_id[21];
						char h_preliminary_flag[2];
						char h_dl_client[APL_CLIENT_LENGTH];
						char h_swift_msg_no[7];
						char h_msg_in_out_ind[2];
						char h_link_class[3];
						char h_swift_msgrefno[APL_TXNREFNO_LEN];
						char h_new_dt[APL_DATE_LEN];
						char h_information[31];
					} CAMESGLINK_STRUCT_H; PJ */

typedef struct {
						char h_corp_id[21];
						char h_preliminary_flag[2];
						char h_dl_client[11];
						char h_swift_msg_no[7];
						char h_msg_in_out_ind[2];
						char h_link_class[3];
						char h_swift_msgrefno[17];
						char h_new_dt[20];
						char h_information[31];
					} CAMESGLINK_STRUCT_H;

typedef struct {
						short int i_corp_id;
						short int i_preliminary_flag;
						short int i_dl_client;
						short int i_swift_msg_no;
						short int i_msg_in_out_ind;
						short int i_link_class;
						short int i_msgindentity_no;
						short int i_new_dt;
						short int i_information;
					} CAMESGLINK_STRUCT_I;





typedef struct {
                char  h_deal_code[2];
                char  swift_msg_no[4];
                char  setl_dt[20];
                char  indentity_no[17];
                char  addindentity_no[17];
                char  dl_dt[20];
                char  dl_loc[5];
                char  instr_name[121];
                char  instr_code[9];
                char  inst_client[36];
                char  inst_clnt_clr_name[66];
                char  cp_clt[16];
                char  countclt_cname[66];
                char  domestic_cpclt[11];
                char  domcpclt_cd_cname[66];
                char  clientof[36];
                char  currency_code[4];
                double   amount;
                char     info[266];
                char gl_client[11];
                char dl_class[3];
					 char fx_adv_ind[2];
					 double brokercomm;
					 char partial_ind_a[2];
					 char  place_cd[5];
					 char  description[41];
					 char    psetparty[161];
					 int   count;		
					 char	clientof_cname[66];
                char interprty[36];
                char interprtynm[66];
                char ex_arena[2];
                char fxccy[4];
                char loc_chng_ind[2]; 
                char lcl_identno[17]; 
					 int h_stld_loc;
					 char h_related_indentity_no[21];
                }MS_54X_STRUCT_H;

typedef struct {
                char  h_deal_code[2];
                char  swift_msg_no[4];
                char  setl_dt[20];
                char  indentity_no[17];
                char  addindentity_no[17];
                char  dl_dt[20];
                char  dl_loc[5];
                char  instr_name[121];
                char  instr_code[9];
                char  inst_client[36];
                char  inst_clnt_clr_name[66];
                char  cp_clt[16];
                char  countclt_cname[66];
                char  domestic_cpclt[11];
                char  domcpclt_cd_cname[66];
                char  clientof[36];
                char  currency_code[4];
                double   amount;
                char     info[266];
                char gl_client[11];
                char dl_class[3];
					 char fx_adv_ind[2];
					 double brokercomm;
					 char partial_ind_a[2];
					 char  place_cd[5];
                char  description[41];
                char    psetparty[161];
                int   count; 	
					 char clientof_cname[66];
                char interprty[36];
                char interprtynm[66];
                char ex_arena[2];
                char fxccy[4];
                char h_rpr_ind[2];
                char manual_ind_dl_flg[2];
                char loc_chng_ind[2]; 
                char lcl_identno[17]; 
					 int h_stld_loc;
					 char h_related_indentity_no[21];
                }MS_INC_MSG_STRUCT_H;


typedef struct {
					 char				 sequence_name[6];
					 char           link_val[6];
					 char           link_tag[51];
					 char           msg_tag[6];
				   }  MS_INC_LINKINFO_STRUCT_H;		


typedef  struct
            {
            int  h_failreason_cd;
            char h_596no1_data[400];
            int new_ind;
            int canc_ind;
            char h_instr_typeval[40];
            char paramcurrency[40];
            int no_of_dl;
            }MS_GEN_STRUCT_H;

typedef struct{
                        char    msg[MAXSWIFTLENISO15022];
                        char    sfeindentity_no[11];
                        } EI_MQ_INC_STRUCT_H;

typedef struct{
						char h_sfe_indentity_no[11];
						char	h_res_cd[3];
						char	h_res_str[50];
              } H_MQ_INC_RESP;

typedef struct{
						short i_sfe_indentity_no;
						short i_reas_cd;
						short i_rec_str;
                        } I_MQ_INC_RESP;

typedef struct {
						char deal_rf_ident_no[17];
						char instr_code[9];
						double amount;
						double quantity;
						char deal_cd[2];
						char currency_cd[4];
					} MS_536_STRUCT_H;

typedef struct {
                  short int deal_rf_ident_no;
                  short int instr_code;
                  short int amount;
                  short int quantity;
                  short int deal_cd;
                  short int currency_cd;
					} MS_536_STRUCT_I;

typedef struct {
						char client[APL_CLIENT_LENGTH];
						char deal_rf_ident_no[17];
						char instr_code[9];
						double amount;
						double quantity;
						char deal_cd[2];
						char currency_cd[4];
                	char  deal_date[20];
                	char  setl_date[20];
						char h_stat_qual[5];
						char stat_cd[5];
						char reason_cd[5];
						char client_note[71];
						char fail_det[36];
						char access_stamp[20];
						char val_unique_identity[2];
						char depo_loc[5];
                	char domestic_cpclt[11];
                	char domcpclt_cd_cname[66];
					} MS_537_STRUCT_H;

typedef struct {
						short int client;
                  short int deal_rf_ident_no;
                  short int instr_code;
                  short int amount;
                  short int quantity;
                  short int deal_cd;
                  short int currency_cd;
						short int deal_date;
						short int setl_date;
						short int stat_cd;
						short int h_stat_qual;
						short int reason_cd;
						short int client_note;
						short int fail_det;
						short int access_stamp;
					} MS_537_STRUCT_I;


typedef struct {
						char  	h_swift_msg_no[4];
						char		h_nameof_file[51];
						char		h_dl_client[11];
						char		h_indentity_no[17];
						char		h_trrf_indentity_no[17];
						char		h_instr_code[9];				
						double 	h_amt;
						char		h_currencycode[4];
						double	h_qty;
						char		h_dealcd[2];
						char		h_instrdate[20];
						char		h_message_stat[4];
						char		h_reject_reason[151];
						char		h_rep_dt[20];
						char		h_report_ind[2];
						int	   h_deal_no;
					} H_DL_SETLRPT_STRUCT;

typedef struct {
						short  int 	i_swift_msg_no;
						short	 int 	i_nameof_file;
						short  int	i_dl_client;
						short  int	i_indentity_no;
						short  int	i_trrf_indentity_no;
						short  int	i_instr_code;				
						short  int 	i_amt;
						short	 int	i_currencycode;
						short  int	i_qty;
						short  int	i_dealcd;
						short  int	i_instrdate;
						short  int	i_message_stat;
						short  int	i_reject_reason;
						short  int	i_rep_dt;
						short  int	i_report_ind;
						short  int	i_deal_no;
					} I_DL_SETLRPT_STRUCT;



typedef struct {
		int h_sequence_num;
		char h_sequence_name[6];
		char h_link_val[6];
		char h_link_msg_tag[51];
		int h_msg_tag_rep_no;
		int h_msg_line_no;
		char    h_msg_tag[6];
		struct CMSGLINKDET_LIST_STRUCT_H *h_next;		
	} CMSGLINKDET_LIST_STRUCT_H;

typedef struct {
		short int i_sequence_num;
		short int i_sequence_name;
		short int i_link_val;
		short int i_link_msg_tag;
		short int i_msg_tag_rep_no;
		short int i_msg_line_no;
		short int i_msg_tag;
		} CMSGLINKDET_LIST_STRUCT_I;


extern int MS_Mod_MsgStat(MS_MSGSTAT_STRUCT,int *,DEBUG_INFO_STRUCT_H **);
#endif
