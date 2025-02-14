/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to 
 *    Polaris Software Lab Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or 
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
/*********************************************************************
 *
 * Module Name         :			Maintenence
 *
 * File Name           :			DM_Interface.h
 *
 * Description         :			Contains Structure Definitions for Data Migration
 *											
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description			RFS No.
 * ---------   --------	 ---------------  -------------------		----------
 * 
 ***********************************************************************************************************/
#include "stdio_64.h"
#include <CO_LenConstdef.h>
#define APL_LINE_LEN 100
#define BT_DEBUG 1
#define BT_IF_DEBUG if(BT_DEBUG)
#define APL_FUNCTION_ENTER(fp)\
{\
   char l_line[APL_LINE_LEN];\
   sprintf(l_line,"Entered Function\t\t|%s|",__func__);\
   BT_IF_DEBUG\
      CO_ProcMonitor(fp,l_line,NULL,NULL);\
}

#define APL_FUNCTION_RET_SUCCESS(fp)\
{\
   char l_line[APL_LINE_LEN];\
   sprintf(l_line,"Success From Function\t\t|%s|",__func__);\
   BT_IF_DEBUG\
      CO_ProcMonitor(fp,l_line,NULL,NULL);\
   return APL_SUCCESS;\
}

#define APL_FUNCTION_RET_FAILURE(fp)\
{\
   char l_line[APL_LINE_LEN];\
   sprintf(l_line,"Failure From Function\t\t|%s|",__func__);\
   BT_IF_DEBUG\
      CO_ProcMonitor(fp,l_line,NULL,NULL);\
   return APL_FAILURE;\
}



#define APL_CLOSE_FILE(fp) \
   if(fp != (FILE *)NULL)fclose(fp);

#define WARNING (5)
#define OK (2)
#define NOT_OK (3)
#define APL_MAX_ERRORS (15)
#define APL_DEBUG_YES (1)
#define APL_DATE_LEN 20
#define  APL_NULL_STRING      "\0"  /** Null string **/
#define  APL_NULL_CHAR     '\0'  /** Null Character **/
#define  APL_OUT_FILE      stdout   /** file pointer for screen **/
#define  APL_GOBACK_SUCCESS         goto RETURN_SUCCESS;
#define  APL_GOBACK_FAIL            goto RETURN_FAILURE;
#define  APL_SUCCESS                1
#define  APL_FAILURE                0
#define  APL_RECS_EXIST             2
#define ERR_NO_MEMORY	391
#define KEY_LENGTH	20
#define ERR_REC_NOTFND	3
#define APL_NOT_AN_ERROR	0
#define FUNC_NF		803
#define KEY_LENGTH	20
#define APL_ORA_MSG_LENGTH	70

#define  APL_ROWID_LEN              19

#define  APL_NULL_TIME              " 12:00:00"

#define  APL_CONDID_LEN             21
#define  APL_MAINFUNCAREA_LEN       21


#define  ST_MAN_MSG                 9000001
#define  EN_MAN_MSG                 9999999

#define  ST_BLDLV_MSG               7000001
#define  EN_BLDLV_MSG               9000000

#define  ST_FM_MSG                  1
#define  EN_FM_MSG                  7000000


#define DATA_FIELD_SEPRTR           '^A'
#define DATA_VALUE_SEPRTR           '^B'
#define ERR_FLD_SEP                 '|'
#define ERR_REC_SEP                 '#'

/* Sonali , Audit log */
#define AUDIT_DATA_FIELD_SEPRTR "^A"
#define AUDIT_DATA_VALUE_SEPRTR "^B"






typedef struct{
   char h_corp_id[CA_CORP_ID_LEN];
   char h_instr_code[MT_INSTR_CODE_LEN];
   char h_evt_class[CA_CA_EVENT_LEN];
   char h_decl_date[APL_DATE_LEN];
   int h_evt_nbr;
   int h_priority;
   char h_preliminary_flag[CA_PRELIMINARY_FLAG_LEN];
   char h_ca_currency[CA_CA_CURRENCY_LEN];
   char h_ex_date[APL_DATE_LEN];
   char h_rec_date[APL_DATE_LEN];
   char h_pymt_dt[APL_DATE_LEN];
   char h_respons_date[APL_DATE_LEN];
   char h_expire_date[APL_DATE_LEN];
   char h_pp_date[APL_DATE_LEN];
   char h_proxy_date[APL_DATE_LEN];
   char h_meet_date[APL_DATE_LEN];
   char h_start_date[APL_DATE_LEN];
   char h_effect_date[APL_DATE_LEN];
   char h_proc_oth[CA_PROC_OTH_LEN];
   char h_op_evt_class[CA_OP_EVT_CLASS_LEN];
   char h_respons_date_openend[CA_RESP_DT_OPND_LEN];
   char h_expire_date_openend[CA_EXP_DT_OPEN_IND_LEN];
   char h_evt_send_msg_ind[CA_EVT_SEND_MSG_IND_LEN];
   char h_entl_send_msg_ind[CA_ENTL_SEND_MSG_IND_LEN];
   char h_pymt_send_msg_ind[CA_PYMT_SEND_MSG_IND_LEN];
   double h_earnings;
   double h_earnings_rt;
   char h_res_instr_code[MT_INSTR_CODE_LEN];
   int h_new_safek_quantity;
   int h_old_safek_quantity;
   char h_disp_of_fract[CA_DISP_OF_FRACT_LEN];
   double h_f_pr;
   int h_sub_base_quantity;
   double h_sub_new_quantity;
   double h_sub_pr;
   char h_rights_class[CA_RHTS_CLASS_LEN];
   double h_new_safek_quantity_rt;
   char h_contactinfo[CA_CONTACT_DETAILS_LEN];
   double h_amount_due;
   double h_amount_recd;
   double h_quantity_due;
   double h_quantity_recd;
   int h_evt_msg_count;
   int h_evt_clt_cnt;
   int h_entl_msg_cnt;
   int h_entl_clt_cnt;
   int h_count_acs_pend;
   char h_nrepdate1[APL_DATE_LEN];
   char h_follmsg1date[APL_DATE_LEN];
   char h_follmsg2date[APL_DATE_LEN];
   char h_info_nbr[CA_INFO_SEQ_LEN];
   char h_entinfo_no[CA_ENTITL_INFONO_LEN];
   char h_evt_stat[MT_STATUS_LEN];
   char h_stat_date[APL_DATE_LEN];
   char h_maker[MT_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_checker[MT_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_dealfrom_dt[APL_DATE_LEN];
   char h_dealto_dt[APL_DATE_LEN];
   char h_subs_date[APL_DATE_LEN];
   char h_posting_date[APL_DATE_LEN];
   char h_over_subscrp[CA_OVER_SUBSCRP_LEN];
   char h_div_class[CA_DIVIDEND_TYPE_LEN];
   double h_redem_rt;
   char h_nser_info[CA_NSER_E_INFO_LEN];
   char h_nrep_date_a[CA_NSER_B_INFO_LEN];
   char h_comp_info1[CA_COMP_INFO_A_LEN];
   char h_inco_info1[CA_INCO_INFO_A_LEN];
   char h_buyresp_date[APL_DATE_LEN];
   char h_sellresp_date[APL_DATE_LEN];
   char h_wwwaddr[CA_WWWADDR_LEN];
   char h_txnr_info1[CA_TXNR_INFO_A_LEN];
   char h_reqd_cert_ind[CA_REQD_CERTIFY_LEN];
   char h_ex_dt_bse[APL_DATE_LEN];
   char h_bc_from_date[APL_DATE_LEN];
   char h_bc_to_date[APL_DATE_LEN];
   char h_res_instr_code_2[MT_INSTR_CODE_LEN];
   char h_trans_dt[APL_DATE_LEN];
   char h_cln_code[CA_CLN_CODE_LEN];
   char h_prev_inst_date[APL_DATE_LEN];
   char h_next_inst_date[APL_DATE_LEN];
   char h_inst_start_period[APL_DATE_LEN];
   char h_inst_end_period[APL_DATE_LEN];
   char h_last_ptc_date[APL_DATE_LEN];
   char h_allotment_letter[CA_ALLOTMENT_LETTER_LEN];
   char h_redem_option[CA_REDEM_OPTION_LEN];
   double h_inst_amount;
   char h_send_split[CA_SEND_SPLIT_LEN];
   char h_cmp_code[MT_CMP_CODE_LEN];
   char h_res_cmp_code[MT_CMP_CODE_LEN];
   char h_exch_code[MT_EXCH_CODE_LEN];
   double h_premium;
   double h_face_value;
   char h_interest_type[CA_INTEREST_TYPE_LEN];
   int h_ratio_rcv2;
   int h_ratio_hld2;
   char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
   char h_depo_code[MT_DEPO_CODE_LEN];
   char h_bk_build_ind[2];
/*   double h_first_call;
   double h_second_call;*/
   char h_attach_corp_id[21];
   char h_source[2];
   double h_new_safek_rt2;
}CAEVENTMG_STRUCT_H;
typedef struct{
   short i_corp_id;
   short i_instr_code;
   short i_evt_class;
   short i_decl_date;
   short i_evt_nbr;
   short i_priority;
   short i_preliminary_flag;
   short i_ca_currency;
   short i_ex_date;
   short i_rec_date;
   short i_pymt_dt;
   short i_respons_date;
   short i_expire_date;
   short i_pp_date;
   short i_proxy_date;
   short i_meet_date;
   short i_start_date;
   short i_effect_date;
   short i_proc_oth;
   short i_op_evt_class;
   short i_respons_date_openend;
   short i_expire_date_openend;
   short i_evt_send_msg_ind;
   short i_entl_send_msg_ind;
   short i_pymt_send_msg_ind;
   short i_earnings;
   short i_earnings_rt;
   short i_res_instr_code;
   short i_new_safek_quantity;
   short i_old_safek_quantity;
   short i_disp_of_fract;
   short i_f_pr;
   short i_sub_base_quantity;
   short i_sub_new_quantity;
   short i_sub_pr;
   short i_rights_class;
   short i_new_safek_quantity_rt;
   short i_contactinfo;
   short i_amount_due;
   short i_amount_recd;
   short i_quantity_due;
   short i_quantity_recd;
   short i_evt_msg_count;
   short i_evt_clt_cnt;
   short i_entl_msg_cnt;
   short i_entl_clt_cnt;
   short i_count_acs_pend;
   short i_nrepdate1;
   short i_follmsg1date;
   short i_follmsg2date;
   short i_info_nbr;
   short i_entinfo_no;
   short i_evt_stat;
   short i_stat_date;
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
   short i_dealfrom_dt;
   short i_dealto_dt;
   short i_subs_date;
   short i_posting_date;
   short i_over_subscrp;
   short i_div_class;
   short i_redem_rt;
   short i_nser_info;
   short i_nrep_date_a;
   short i_comp_info1;
   short i_inco_info1;
   short i_buyresp_date;
   short i_sellresp_date;
   short i_wwwaddr;
   short i_txnr_info1;
   short i_reqd_cert_ind;
   short i_ex_dt_bse;
   short i_bc_from_date;
   short i_bc_to_date;
   short i_res_instr_code_2;
   short i_trans_dt;
   short i_cln_code;
   short i_prev_inst_date;
   short i_next_inst_date;
   short i_inst_start_period;
   short i_inst_end_period;
   short i_last_ptc_date;
   short i_allotment_letter;
   short i_redem_option;
   short i_inst_amount;
   short i_send_split;
   short i_cmp_code;
   short i_res_cmp_code;
   short i_exch_code;
   short i_premium;
   short i_face_value;
   short i_interest_type;
   short i_ratio_rcv2;
   short i_ratio_hld2;
   short i_depo_part_code;
   short i_depo_code;
   short i_bk_build_ind;
   short i_first_call;
   short i_second_call;
   short i_attach_corp_id;
   short i_source;
   short i_new_safek_rt2;
}CAEVENTMG_STRUCT_I;



/*
typedef struct{
	
	
	
	
	
	
	
	
	
}ASSETHOLDING_VW_STRUCT_H;
*/
typedef struct{
	short i_instr_code;
	short i_client;
	short i_clt_class;
	short i_master_clt;
	short i_clnt_name;
	short i_mrkt_val;
	short i_exchgrt;
	short i_dir_indir_fxqt_ind;
	short i_currency_cd;
}ASSETHOLDING_VW_STRUCT_I;







#define AU_USR_LEN 15
#define AU_MOD_LEN 4
#define AU_FUNCTION_LEN 61
#define AU_AUTH_REQ_LEN 2
#define AU_SUBPROCESS_LEN 4
#define AU_ACTION_LEN 2


typedef struct{
	char h_usr[AU_USR_LEN];
	char h_mod[AU_MOD_LEN];
	char h_function[AU_FUNCTION_LEN];
	char h_auth_req[AU_AUTH_REQ_LEN];
	char h_subprocess[AU_SUBPROCESS_LEN];
	char h_action[AU_ACTION_LEN];
	char h_start_time[APL_DATE_LEN];
	char h_end_time[APL_DATE_LEN];
}AUDIT_LOG_STRUCT_H;
typedef struct{
	short i_usr;
	short i_mod;
	short i_function;
	short i_auth_req;
	short i_subprocess;
	short i_action;
	short i_start_time;
	short i_end_time;
}AUDIT_LOG_STRUCT_I;







#define BA_ENTITY_NAME_LEN 51
#define BA_PICKLIST_NAME_LEN 51
#define BA_PICKLIST_QUERY_LEN 1001
typedef struct{
	char h_entity_name[BA_ENTITY_NAME_LEN];
	char h_picklist_name[BA_PICKLIST_NAME_LEN];
	char h_picklist_query[BA_PICKLIST_QUERY_LEN];
}BACK_GN_ENTITY_PICKLIST_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_picklist_name;
	short i_picklist_query;
}BACK_GN_ENTITY_PICKLIST_STRUCT_I;







#define BA_CLN_CODE_LEN 11
#define BA_CLN_CURRENCY_LEN 4
#define BA_CLN_OUR_THEIR_IND_LEN 2
#define BA_CLN_ISCC_IND_LEN 2
#define BA_CLN_USE_ISIN_IND_LEN 2
#define BA_CLN_TYPE_LEN 3
#define BA_CLN_REG_NAME_LEN 81
#define BA_CLN_CLAS_LEN 3
#define BA_CLN_BILLABLEIND_LEN 2
#define BA_CLN_CLASS_LEN 2
#define BA_CLN_VTB_CLIENT_LEN 11
#define BA_CLN_REG_LEN 13
#define BA_CLN_MEMO_LEN 201
#define BA_CLN_INTERNAL_LEN 21

#define BA_CLN_BASE_ID_LEN 7




#define BA_CLN_MASTER_LEN 11
#define BA_CLN_NAME_LEN 66
#define BA_CLN_GL_ACCOUNT_LEN 11
#define BA_CLN_BRK_ALL_LEN 2
#define BA_CLN_SHORTNM_LEN 13
#define BA_CLN_ORD_CLT_LEN 2
#define BA_CLN_SPOT_DL_IND_LEN 2
#define BA_CLN_FX_SELL_IND_LEN 2
#define BA_CLN_FX_BUY_IND_LEN 2
#define BA_CLN_FX_INC_IND_LEN 2

#define BA_CLN_BRNCHCODE_LEN 4
#define BA_CLN_CNTRY_CODE_LEN 3
#define BA_CLN_FMT_RPTIND_LEN 2
#define BA_MAKER_LEN 15


#define BA_CHECKER_LEN 15

#define BA_CLN_UNIQ_GCUSTODY_ID_LEN 13
#define BA_CLN_CLTPROD_CD_LEN 6
#define BA_CLN_DOMICILE_LEN 2
#define BA_CLN_PARTIAL_IND_C_LEN 2
#define BA_CLN_ALLOW_REGIND_LEN 2
#define BA_CLN_REG_SETL_IND_LEN 2
#define BA_CLN_REG_BCL_IND_LEN 2
#define BA_STATUS_LEN 3
#define BA_CLN_CLH_LEN 16
#define BA_CLN_TAXABLE_IND_LEN 2
#define BA_CLN_BRK_CD_LEN 13
#define BA_CLN_TAX_ID_LEN 11
#define BA_CLN_ADD_1_LEN 61
#define BA_CLN_EXT_CLH_LEN 13
#define BA_CLN_GRP_LEN 5
#define BA_CLN_SAT_OPER_CD_LEN 11

#define BA_CLN_AUTHBUNCH_IND_LEN 2
#define BA_CLN_FX_BUY_CCY_LEN 4
#define BA_CLN_FX_SELL_CCY_LEN 4
#define BA_CLN_SINGLE548_SUPPORT_IND_LEN 2
#define BA_CLN_STAT_DL_IND_LEN 2
#define BA_CLN_DEAL_SETL_IND_LEN 2
#define BA_CLN_RHTS_RET_LEN 2
#define BA_CLN_VALCREDIT_LEN 2
#define BA_CLN_FRACT_IND_LEN 2
#define BA_CLN_AUTO_CANC_IND_LEN 2
#define BA_CLN_DESC_LEN 201
#define BA_CLN_GENERATE_IND_LEN 2
#define BA_CLN_ADD_2_LEN 61
#define BA_CLN_ADD_CITY_LEN 21
#define BA_CLN_ADD_STATE_LEN 21
#define BA_CLN_ADD_PIN_LEN 11
#define BA_CLN_TEL_LEN 21
#define BA_CLN_FAX_LEN 21
#define BA_CLN_EMAIL_LEN 61
#define BA_CLN_CONTACT1_LEN 66
#define BA_CLN_CONTACT2_LEN 66
#define BA_CLN_SEBICTG_LEN 5
#define BA_CLN_PAN_LEN 21

#define BA_CLN_GLB_CUST_LEN 11
#define BA_CLN_START_DL_LEN 2
#define BA_CLN_BCN_REQD_LEN 2
#define BA_CLN_DEF_CR_AGENCY_LEN 7
#define BA_CLN_CUST_IDENT_LEN 21

#define BA_CLN_SIGN_MEMO_LEN 201
typedef struct{
	char h_cln_code[BA_CLN_CODE_LEN];
	char h_cln_currency[BA_CLN_CURRENCY_LEN];
	char h_cln_our_their_ind[BA_CLN_OUR_THEIR_IND_LEN];
	char h_cln_iscc_ind[BA_CLN_ISCC_IND_LEN];
	char h_cln_use_isin_ind[BA_CLN_USE_ISIN_IND_LEN];
	char h_cln_type[BA_CLN_TYPE_LEN];
	char h_cln_reg_name[BA_CLN_REG_NAME_LEN];
	char h_cln_clas[BA_CLN_CLAS_LEN];
	char h_cln_billableind[BA_CLN_BILLABLEIND_LEN];
	char h_cln_class[BA_CLN_CLASS_LEN];
	char h_cln_vtb_client[BA_CLN_VTB_CLIENT_LEN];
	char h_cln_reg[BA_CLN_REG_LEN];
	char h_cln_memo[BA_CLN_MEMO_LEN];
	char h_cln_internal[BA_CLN_INTERNAL_LEN];
	char h_cln_pos_dt[APL_DATE_LEN];
	char h_cln_base_id[BA_CLN_BASE_ID_LEN];
	int h_cln_count_swf_mon;
	int h_cln_count_tlx_mon;
	int h_cln_count_swf_yr;
	int h_cln_count_tlx_yr;
	char h_cln_master[BA_CLN_MASTER_LEN];
	char h_cln_name[BA_CLN_NAME_LEN];
	char h_cln_gl_account[BA_CLN_GL_ACCOUNT_LEN];
	char h_cln_brk_all[BA_CLN_BRK_ALL_LEN];
	char h_cln_shortnm[BA_CLN_SHORTNM_LEN];
	char h_cln_ord_clt[BA_CLN_ORD_CLT_LEN];
	char h_cln_spot_dl_ind[BA_CLN_SPOT_DL_IND_LEN];
	char h_cln_fx_sell_ind[BA_CLN_FX_SELL_IND_LEN];
	char h_cln_fx_buy_ind[BA_CLN_FX_BUY_IND_LEN];
	char h_cln_fx_inc_ind[BA_CLN_FX_INC_IND_LEN];
	char h_cln_dateof_input[APL_DATE_LEN];
	char h_cln_brnchcode[BA_CLN_BRNCHCODE_LEN];
	char h_cln_cntry_code[BA_CLN_CNTRY_CODE_LEN];
	char h_cln_fmt_rptind[BA_CLN_FMT_RPTIND_LEN];
	char h_maker[BA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[BA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_cln_uniq_gcustody_id[BA_CLN_UNIQ_GCUSTODY_ID_LEN];
	char h_cln_cltprod_cd[BA_CLN_CLTPROD_CD_LEN];
	char h_cln_domicile[BA_CLN_DOMICILE_LEN];
	char h_cln_partial_ind_c[BA_CLN_PARTIAL_IND_C_LEN];
	char h_cln_allow_regind[BA_CLN_ALLOW_REGIND_LEN];
	char h_cln_reg_setl_ind[BA_CLN_REG_SETL_IND_LEN];
	char h_cln_reg_bcl_ind[BA_CLN_REG_BCL_IND_LEN];
	char h_status[BA_STATUS_LEN];
	char h_cln_clh[BA_CLN_CLH_LEN];
	char h_cln_taxable_ind[BA_CLN_TAXABLE_IND_LEN];
	char h_cln_brk_cd[BA_CLN_BRK_CD_LEN];
	char h_cln_tax_id[BA_CLN_TAX_ID_LEN];
	char h_cln_add_1[BA_CLN_ADD_1_LEN];
	char h_cln_ext_clh[BA_CLN_EXT_CLH_LEN];
	char h_cln_grp[BA_CLN_GRP_LEN];
	char h_cln_sat_oper_cd[BA_CLN_SAT_OPER_CD_LEN];
	int h_cln_tolerance;
	char h_cln_authbunch_ind[BA_CLN_AUTHBUNCH_IND_LEN];
	char h_cln_fx_buy_ccy[BA_CLN_FX_BUY_CCY_LEN];
	char h_cln_fx_sell_ccy[BA_CLN_FX_SELL_CCY_LEN];
	char h_cln_single548_support_ind[BA_CLN_SINGLE548_SUPPORT_IND_LEN];
	char h_cln_stat_dl_ind[BA_CLN_STAT_DL_IND_LEN];
	char h_cln_deal_setl_ind[BA_CLN_DEAL_SETL_IND_LEN];
	char h_cln_rhts_ret[BA_CLN_RHTS_RET_LEN];
	char h_cln_valcredit[BA_CLN_VALCREDIT_LEN];
	char h_cln_fract_ind[BA_CLN_FRACT_IND_LEN];
	char h_cln_auto_canc_ind[BA_CLN_AUTO_CANC_IND_LEN];
	char h_cln_desc[BA_CLN_DESC_LEN];
	char h_cln_generate_ind[BA_CLN_GENERATE_IND_LEN];
	char h_cln_add_2[BA_CLN_ADD_2_LEN];
	char h_cln_add_city[BA_CLN_ADD_CITY_LEN];
	char h_cln_add_state[BA_CLN_ADD_STATE_LEN];
	char h_cln_add_pin[BA_CLN_ADD_PIN_LEN];
	char h_cln_tel[BA_CLN_TEL_LEN];
	char h_cln_fax[BA_CLN_FAX_LEN];
	char h_cln_email[BA_CLN_EMAIL_LEN];
	char h_cln_contact1[BA_CLN_CONTACT1_LEN];
	char h_cln_contact2[BA_CLN_CONTACT2_LEN];
	char h_cln_sebictg[BA_CLN_SEBICTG_LEN];
	char h_cln_pan[BA_CLN_PAN_LEN];
	double h_cln_tds_rt;
	char h_cln_glb_cust[BA_CLN_GLB_CUST_LEN];
	char h_cln_start_dl[BA_CLN_START_DL_LEN];
	char h_cln_bcn_reqd[BA_CLN_BCN_REQD_LEN];
	char h_cln_def_cr_agency[BA_CLN_DEF_CR_AGENCY_LEN];
	char h_cln_cust_ident[BA_CLN_CUST_IDENT_LEN];
	int h_cln_mst_ind;
	char h_cln_sign_memo[BA_CLN_SIGN_MEMO_LEN];
}BACK_MT_CLIENT_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_currency;
	short i_cln_our_their_ind;
	short i_cln_iscc_ind;
	short i_cln_use_isin_ind;
	short i_cln_type;
	short i_cln_reg_name;
	short i_cln_clas;
	short i_cln_billableind;
	short i_cln_class;
	short i_cln_vtb_client;
	short i_cln_reg;
	short i_cln_memo;
	short i_cln_internal;
	short i_cln_pos_dt;
	short i_cln_base_id;
	short i_cln_count_swf_mon;
	short i_cln_count_tlx_mon;
	short i_cln_count_swf_yr;
	short i_cln_count_tlx_yr;
	short i_cln_master;
	short i_cln_name;
	short i_cln_gl_account;
	short i_cln_brk_all;
	short i_cln_shortnm;
	short i_cln_ord_clt;
	short i_cln_spot_dl_ind;
	short i_cln_fx_sell_ind;
	short i_cln_fx_buy_ind;
	short i_cln_fx_inc_ind;
	short i_cln_dateof_input;
	short i_cln_brnchcode;
	short i_cln_cntry_code;
	short i_cln_fmt_rptind;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_cln_uniq_gcustody_id;
	short i_cln_cltprod_cd;
	short i_cln_domicile;
	short i_cln_partial_ind_c;
	short i_cln_allow_regind;
	short i_cln_reg_setl_ind;
	short i_cln_reg_bcl_ind;
	short i_status;
	short i_cln_clh;
	short i_cln_taxable_ind;
	short i_cln_brk_cd;
	short i_cln_tax_id;
	short i_cln_add_1;
	short i_cln_ext_clh;
	short i_cln_grp;
	short i_cln_sat_oper_cd;
	short i_cln_tolerance;
	short i_cln_authbunch_ind;
	short i_cln_fx_buy_ccy;
	short i_cln_fx_sell_ccy;
	short i_cln_single548_support_ind;
	short i_cln_stat_dl_ind;
	short i_cln_deal_setl_ind;
	short i_cln_rhts_ret;
	short i_cln_valcredit;
	short i_cln_fract_ind;
	short i_cln_auto_canc_ind;
	short i_cln_desc;
	short i_cln_generate_ind;
	short i_cln_add_2;
	short i_cln_add_city;
	short i_cln_add_state;
	short i_cln_add_pin;
	short i_cln_tel;
	short i_cln_fax;
	short i_cln_email;
	short i_cln_contact1;
	short i_cln_contact2;
	short i_cln_sebictg;
	short i_cln_pan;
	short i_cln_tds_rt;
	short i_cln_glb_cust;
	short i_cln_start_dl;
	short i_cln_bcn_reqd;
	short i_cln_def_cr_agency;
	short i_cln_cust_ident;
	short i_cln_mst_ind;
	short i_cln_sign_memo;
}BACK_MT_CLIENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11


#define CA_PAYMENT_CCY_LEN 4



#define CA_PAYMENT_INFO_LEN 51

#define CA_DEAL_IDENTITY_NO_LEN 17

#define CA_LOCATION_CD_LEN 5


#define CA_STAT_PYMT_LEN 3


#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15


#define CA_AE_PASSIND_LEN 2
#define CA_CLT_SEQNUM_LEN 10 



typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	int h_seqnum_pay;
	char h_dateof_payment[APL_DATE_LEN];
	char h_payment_ccy[CA_PAYMENT_CCY_LEN];
	double h_curr_pymt;
	double h_quantity_received;
	double h_tax_rate;
	char h_payment_info[CA_PAYMENT_INFO_LEN];
	char h_hf_date[APL_DATE_LEN];
	char h_deal_identity_no[CA_DEAL_IDENTITY_NO_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_location_cd[CA_LOCATION_CD_LEN];
	double h_tax_amount;
	double h_other_chrgs;
	char h_stat_pymt[CA_STAT_PYMT_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_ae_passind[CA_AE_PASSIND_LEN];
	char h_clt_seqnum[CA_CLT_SEQNUM_LEN];
	double h_quantity_paid;
	double h_taxable_dividend;
	char h_archival_date[APL_DATE_LEN];
}CAARCHCHEQUE_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_seqnum_pay;
	short i_dateof_payment;
	short i_payment_ccy;
	short i_curr_pymt;
	short i_quantity_received;
	short i_tax_rate;
	short i_payment_info;
	short i_hf_date;
	short i_deal_identity_no;
	short i_dateofbilling;
	short i_location_cd;
	short i_tax_amount;
	short i_other_chrgs;
	short i_stat_pymt;
	short i_processed_date;
	short i_date_of_input;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_ae_passind;
	short i_clt_seqnum;
	short i_quantity_paid;
	short i_taxable_dividend;
	short i_archival_date;
}CAARCHCHEQUE_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11

#define CA_CCY_FOR_ENTITL_LEN 4







#define CA_STATUS_ENTITL_LEN 3

#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15




typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	double h_elig_entitl_pos;
	char h_ccy_for_entitl[CA_CCY_FOR_ENTITL_LEN];
	double h_instr_inc_bal;
	double h_received_amt;
	double h_quantity_bal;
	double h_quantity_received;
	char h_nrep_date_b[APL_DATE_LEN];
	char h_nrep_date_c[APL_DATE_LEN];
	char h_dateforsend550[APL_DATE_LEN];
	char h_status_entitl[CA_STATUS_ENTITL_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_custodytax_rate;
	char h_archival_date[APL_DATE_LEN];
}CAARCHCLAIM_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_elig_entitl_pos;
	short i_ccy_for_entitl;
	short i_instr_inc_bal;
	short i_received_amt;
	short i_quantity_bal;
	short i_quantity_received;
	short i_nrep_date_b;
	short i_nrep_date_c;
	short i_dateforsend550;
	short i_status_entitl;
	short i_processed_date;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_custodytax_rate;
	short i_archival_date;
}CAARCHCLAIM_STRUCT_I;








#define CA_CORP_ID_LEN 21
#define CA_PRELIMINARY_FLAG_LEN 2
#define CA_CLIENT_LEN 11
#define CA_SWIFT_MSG_NO_LEN 7
#define CA_MSG_IN_OUT_IND_LEN 2
#define CA_TYPEOF_MSG_LNK_LEN 3
#define CA_SWIFT_MSGREFNO_LEN 17

#define CA_INFORMATION_LEN 31
typedef struct{
	char h_archival_date[APL_DATE_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
	char h_preliminary_flag[CA_PRELIMINARY_FLAG_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_swift_msg_no[CA_SWIFT_MSG_NO_LEN];
	char h_msg_in_out_ind[CA_MSG_IN_OUT_IND_LEN];
	char h_typeof_msg_lnk[CA_TYPEOF_MSG_LNK_LEN];
	char h_swift_msgrefno[CA_SWIFT_MSGREFNO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[CA_INFORMATION_LEN];
}CAARCHMESGLNK_STRUCT_H;
typedef struct{
	short i_archival_date;
	short i_corp_id;
	short i_preliminary_flag;
	short i_client;
	short i_swift_msg_no;
	short i_msg_in_out_ind;
	short i_typeof_msg_lnk;
	short i_swift_msgrefno;
	short i_date_of_input;
	short i_information;
}CAARCHMESGLNK_STRUCT_I;







#define CA_INFO_SEQ_LEN 9 
#define CA_INFO_1_LEN 1751
#define CA_INFO_2_LEN 1751
#define CA_INFO_3_LEN 1751
#define CA_INFO_4_LEN 1751
#define CA_MAKER_LEN 15


#define CA_TYPEOF_INFO_LEN 5

typedef struct{
	char h_info_seq[CA_INFO_SEQ_LEN];
	char h_info_1[CA_INFO_1_LEN];
	char h_info_2[CA_INFO_2_LEN];
	char h_info_3[CA_INFO_3_LEN];
	char h_info_4[CA_INFO_4_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_typeof_info[CA_TYPEOF_INFO_LEN];
	char h_archival_date[APL_DATE_LEN];
}CAARCHNOTE_STRUCT_H;
typedef struct{
	short i_info_seq;
	short i_info_1;
	short i_info_2;
	short i_info_3;
	short i_info_4;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_typeof_info;
	short i_archival_date;
}CAARCHNOTE_STRUCT_I;







#define CA_INSTR_CODE_LEN 9
#define CA_CLIENT_LEN 11
#define CA_CA_EVENT_LEN 3


#define CA_INSTR_PARENT_LEN 9
#define CA_CORP_ID_LEN 21



#define CA_LOCATION_CD_LEN 5


#define CA_SUB_CURRENCY_LEN 4

#define CA_INFO_SEQ_LEN 5
#define CA_EVENT_STATUS_LEN 3
#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15





typedef struct{
	char h_instr_code[CA_INSTR_CODE_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	char h_declare_dt[APL_DATE_LEN];
	int h_evnt_indnt;
	char h_instr_parent[CA_INSTR_PARENT_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
	double h_total_quantity;
	double h_takeup_quantity;
	double h_lapse_qty;
	char h_location_cd[CA_LOCATION_CD_LEN];
	int h_sub_base_quantity;
	double h_sub_new_quantity;
	char h_sub_currency[CA_SUB_CURRENCY_LEN];
	double h_sub_pr;
	char h_info_seq[CA_INFO_SEQ_LEN];
	char h_event_status[CA_EVENT_STATUS_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	char h_archival_date[APL_DATE_LEN];
}CAARCHRTSPROC_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_client;
	short i_ca_event;
	short i_declare_dt;
	short i_evnt_indnt;
	short i_instr_parent;
	short i_corp_id;
	short i_total_quantity;
	short i_takeup_quantity;
	short i_lapse_qty;
	short i_location_cd;
	short i_sub_base_quantity;
	short i_sub_new_quantity;
	short i_sub_currency;
	short i_sub_pr;
	short i_info_seq;
	short i_event_status;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_payment;
	short i_trans_date;
	short i_archival_date;
}CAARCHRTSPROC_STRUCT_I;







#define CA_NATION_CD_LEN 3
#define CA_INSTR_TYPE_LEN 4
#define CA_PROD_CLASS_LEN 3
#define CA_CA_EVENT_LEN 3


typedef struct{
	char h_nation_cd[CA_NATION_CD_LEN];
	char h_instr_type[CA_INSTR_TYPE_LEN];
	char h_prod_class[CA_PROD_CLASS_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	int h_pay_dt_days;
	int h_exdate_days;
}CAAUTOEVENT_STRUCT_H;
typedef struct{
	short i_nation_cd;
	short i_instr_type;
	short i_prod_class;
	short i_ca_event;
	short i_pay_dt_days;
	short i_exdate_days;
}CAAUTOEVENT_STRUCT_I;








#define CA_CLIENT_LEN 11
#define CA_INSTR_CODE_LEN 9

typedef struct{
	char h_dealdt[APL_DATE_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_instr_code[CA_INSTR_CODE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_identity_no[4000]; //Added by Kalyan
}CABACKSETTLE_STRUCT_H;
typedef struct{
	short i_dealdt;
	short i_client;
	short i_instr_code;
	short i_instrument_dt;
	short i_identity_no; // Added by Kalyan
}CABACKSETTLE_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11


#define CA_PAYMENT_CCY_LEN 4



#define CA_PAYMENT_INFO_LEN 51

#define CA_DEAL_IDENTITY_NO_LEN 17

#define CA_LOCATION_CD_LEN 5


#define CA_STAT_PYMT_LEN 3


#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15


#define CA_AE_PASSIND_LEN 2
#define CA_CLT_SEQNUM_LEN 10 


typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	int h_seqnum_pay;
	char h_dateof_payment[APL_DATE_LEN];
	char h_payment_ccy[CA_PAYMENT_CCY_LEN];
	double h_curr_pymt;
	double h_quantity_received;
	double h_tax_rate;
	char h_payment_info[CA_PAYMENT_INFO_LEN];
	char h_hf_date[APL_DATE_LEN];
	char h_deal_identity_no[CA_DEAL_IDENTITY_NO_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_location_cd[CA_LOCATION_CD_LEN];
	double h_tax_amount;
	double h_other_chrgs;
	char h_stat_pymt[CA_STAT_PYMT_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_ae_passind[CA_AE_PASSIND_LEN];
	char h_clt_seqnum[CA_CLT_SEQNUM_LEN];
	double h_quantity_paid;
	double h_taxable_dividend;
}CACHEQUE_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_seqnum_pay;
	short i_dateof_payment;
	short i_payment_ccy;
	short i_curr_pymt;
	short i_quantity_received;
	short i_tax_rate;
	short i_payment_info;
	short i_hf_date;
	short i_deal_identity_no;
	short i_dateofbilling;
	short i_location_cd;
	short i_tax_amount;
	short i_other_chrgs;
	short i_stat_pymt;
	short i_processed_date;
	short i_date_of_input;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_ae_passind;
	short i_clt_seqnum;
	short i_quantity_paid;
	short i_taxable_dividend;
}CACHEQUE_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11


#define CA_PAYMENT_CCY_LEN 4



#define CA_PAYMENT_INFO_LEN 51

#define CA_DEAL_IDENTITY_NO_LEN 17

#define CA_LOCATION_CD_LEN 5


#define CA_STAT_PYMT_LEN 3


#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15


#define CA_AE_PASSIND_LEN 2
#define CA_CLT_SEQNUM_LEN 10 


typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	int h_seqnum_pay;
	char h_dateof_payment[APL_DATE_LEN];
	char h_payment_ccy[CA_PAYMENT_CCY_LEN];
	double h_curr_pymt;
	double h_quantity_received;
	double h_tax_rate;
	char h_payment_info[CA_PAYMENT_INFO_LEN];
	char h_hf_date[APL_DATE_LEN];
	char h_deal_identity_no[CA_DEAL_IDENTITY_NO_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_location_cd[CA_LOCATION_CD_LEN];
	double h_tax_amount;
	double h_other_chrgs;
	char h_stat_pymt[CA_STAT_PYMT_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_ae_passind[CA_AE_PASSIND_LEN];
	char h_clt_seqnum[CA_CLT_SEQNUM_LEN];
	double h_quantity_paid;
	double h_taxable_dividend;
}CACHEQUEMG_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_seqnum_pay;
	short i_dateof_payment;
	short i_payment_ccy;
	short i_curr_pymt;
	short i_quantity_received;
	short i_tax_rate;
	short i_payment_info;
	short i_hf_date;
	short i_deal_identity_no;
	short i_dateofbilling;
	short i_location_cd;
	short i_tax_amount;
	short i_other_chrgs;
	short i_stat_pymt;
	short i_processed_date;
	short i_date_of_input;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_ae_passind;
	short i_clt_seqnum;
	short i_quantity_paid;
	short i_taxable_dividend;
}CACHEQUEMG_STRUCT_I;







#define CA_CORP_ID_LEN 21

#define CA_CURR_CLT_LEN 11
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_curr_clt[CA_CURR_CLT_LEN];
}CACHGEVENT_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_date_of_input;
	short i_curr_clt;
}CACHGEVENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11

#define CA_CCY_FOR_ENTITL_LEN 4







#define CA_STATUS_ENTITL_LEN 3

#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15



typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	double h_elig_entitl_pos;
	char h_ccy_for_entitl[CA_CCY_FOR_ENTITL_LEN];
	double h_instr_inc_bal;
	double h_received_amt;
	double h_quantity_bal;
	double h_quantity_received;
	char h_nrep_date_b[APL_DATE_LEN];
	char h_nrep_date_c[APL_DATE_LEN];
	char h_dateforsend550[APL_DATE_LEN];
	char h_status_entitl[CA_STATUS_ENTITL_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_custodytax_rate;
}CAENTITLEMENT_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_elig_entitl_pos;
	short i_ccy_for_entitl;
	short i_instr_inc_bal;
	short i_received_amt;
	short i_quantity_bal;
	short i_quantity_received;
	short i_nrep_date_b;
	short i_nrep_date_c;
	short i_dateforsend550;
	short i_status_entitl;
	short i_processed_date;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_custodytax_rate;
}CAENTITLEMENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11

#define CA_CCY_FOR_ENTITL_LEN 4







#define CA_STATUS_ENTITL_LEN 3

#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15



typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	double h_elig_entitl_pos;
	char h_ccy_for_entitl[CA_CCY_FOR_ENTITL_LEN];
	double h_instr_inc_bal;
	double h_received_amt;
	double h_quantity_bal;
	double h_quantity_received;
	char h_nrep_date_b[APL_DATE_LEN];
	char h_nrep_date_c[APL_DATE_LEN];
	char h_dateforsend550[APL_DATE_LEN];
	char h_status_entitl[CA_STATUS_ENTITL_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_custodytax_rate;
}CAENTITLEMENTMG_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_elig_entitl_pos;
	short i_ccy_for_entitl;
	short i_instr_inc_bal;
	short i_received_amt;
	short i_quantity_bal;
	short i_quantity_received;
	short i_nrep_date_b;
	short i_nrep_date_c;
	short i_dateforsend550;
	short i_status_entitl;
	short i_processed_date;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_custodytax_rate;
}CAENTITLEMENTMG_STRUCT_I;







#define CA_NATION_CODE_LEN 3
#define CA_INSTR_INC_IND_LEN 4
#define CA_INSTR_ISIN_LEN 13
#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11




#define CA_GROSS_NET_INCOME_LEN 2
#define CA_CCY_FOR_ENTITL_LEN 4





#define CA_STATUS_ENTITL_LEN 3
typedef struct{
	char h_nation_code[CA_NATION_CODE_LEN];
	char h_instr_inc_ind[CA_INSTR_INC_IND_LEN];
	char h_instr_isin[CA_INSTR_ISIN_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_ex_date[APL_DATE_LEN];
	char h_rec_date[APL_DATE_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_gross_net_income[CA_GROSS_NET_INCOME_LEN];
	char h_ccy_for_entitl[CA_CCY_FOR_ENTITL_LEN];
	double h_instr_inc_rate;
	double h_earnings;
	double h_elig_entitl_pos;
	double h_instr_inc_bal;
	double h_custody_tax_rt;
	char h_status_entitl[CA_STATUS_ENTITL_LEN];
}CAENTITLMENT_VER_STRUCT_H;
typedef struct{
	short i_nation_code;
	short i_instr_inc_ind;
	short i_instr_isin;
	short i_corp_id;
	short i_client;
	short i_ex_date;
	short i_rec_date;
	short i_dateof_payment;
	short i_maker_dt;
	short i_gross_net_income;
	short i_ccy_for_entitl;
	short i_instr_inc_rate;
	short i_earnings;
	short i_elig_entitl_pos;
	short i_instr_inc_bal;
	short i_custody_tax_rt;
	short i_status_entitl;
}CAENTITLMENT_VER_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_INSTR_CODE_LEN 9
#define CA_CA_EVENT_LEN 3


#define CA_PRELIMINARY_FLAG_LEN 2
#define CA_CA_CURRENCY_LEN 4










#define CA_PROC_OTH_LEN 106
#define CA_OP_EVT_CLASS_LEN 3
#define CA_RESP_DT_OPND_LEN 2
#define CA_EXP_DT_OPEN_IND_LEN 2
#define CA_EVT_SEND_MSG_IND_LEN 2
#define CA_ENTL_SEND_MSG_IND_LEN 2
#define CA_PYMT_SEND_MSG_IND_LEN 2


#define CA_RES_INSTR_CODE_LEN 9


#define CA_DISP_OF_FRACT_LEN 2




#define CA_RHTS_CLASS_LEN 2

#define CA_CONTACT_DETAILS_LEN 241












#define CA_INFO_SEQ_LEN 9 
#define CA_ENTITL_INFONO_LEN 5
#define CA_EVENT_STATUS_LEN 3

#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15






#define CA_OVER_SUBSCRP_LEN 2
#define CA_DIVIDEND_TYPE_LEN 2

#define CA_NSER_E_INFO_LEN 5
#define CA_NSER_B_INFO_LEN 5
#define CA_COMP_INFO_A_LEN 5
#define CA_INCO_INFO_A_LEN 5


#define CA_WWWADDR_LEN 101
#define CA_TXNR_INFO_A_LEN 5
#define CA_REQD_CERTIFY_LEN 2
typedef struct{
   char h_corp_id[CA_CORP_ID_LEN];
   char h_instr_code[MT_INSTR_CODE_LEN];
   char h_evt_class[CA_CA_EVENT_LEN];
   char h_decl_date[APL_DATE_LEN];
   int h_evt_nbr;
   int h_priority;
   char h_preliminary_flag[CA_PRELIMINARY_FLAG_LEN];
   char h_ca_currency[CA_CA_CURRENCY_LEN];
   char h_ex_date[APL_DATE_LEN];
   char h_rec_date[APL_DATE_LEN];
   char h_pymt_dt[APL_DATE_LEN];
   char h_respons_date[APL_DATE_LEN];
   char h_expire_date[APL_DATE_LEN];
   char h_pp_date[APL_DATE_LEN];
   char h_proxy_date[APL_DATE_LEN];
   char h_meet_date[APL_DATE_LEN];
   char h_start_date[APL_DATE_LEN];
   char h_effect_date[APL_DATE_LEN];
   char h_proc_oth[CA_PROC_OTH_LEN];
   char h_op_evt_class[CA_OP_EVT_CLASS_LEN];
   char h_respons_date_openend[CA_RESP_DT_OPND_LEN];
   char h_expire_date_openend[CA_EXP_DT_OPEN_IND_LEN];
   char h_evt_send_msg_ind[CA_EVT_SEND_MSG_IND_LEN];
   char h_entl_send_msg_ind[CA_ENTL_SEND_MSG_IND_LEN];
   char h_pymt_send_msg_ind[CA_PYMT_SEND_MSG_IND_LEN];
   double h_earnings;
   double h_earnings_rt;
   char h_res_instr_code[MT_INSTR_CODE_LEN];
   int h_new_safek_quantity;
   int h_old_safek_quantity;
   char h_disp_of_fract[CA_DISP_OF_FRACT_LEN];
   double h_f_pr;
   int h_sub_base_quantity;
   double h_sub_new_quantity;
   double h_sub_pr;
   char h_rights_class[CA_RHTS_CLASS_LEN];
   double h_new_safek_quantity_rt;
   char h_contactinfo[CA_CONTACT_DETAILS_LEN];
   double h_amount_due;
   double h_amount_recd;
   double h_quantity_due;
   double h_quantity_recd;
   int h_evt_msg_count;
   int h_evt_clt_cnt;
   int h_entl_msg_cnt;
   int h_entl_clt_cnt;
   int h_count_acs_pend;
   char h_nrepdate1[APL_DATE_LEN];
   char h_follmsg1date[APL_DATE_LEN];
   char h_follmsg2date[APL_DATE_LEN];
   char h_info_nbr[CA_INFO_SEQ_LEN];
   char h_entinfo_no[CA_ENTITL_INFONO_LEN];
   char h_evt_stat[MT_STATUS_LEN];
   char h_stat_date[APL_DATE_LEN];
   char h_maker[MT_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_checker[MT_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_dealfrom_dt[APL_DATE_LEN];
   char h_dealto_dt[APL_DATE_LEN];
   char h_subs_date[APL_DATE_LEN];
   char h_posting_date[APL_DATE_LEN];
   char h_over_subscrp[CA_OVER_SUBSCRP_LEN];
   char h_div_class[CA_DIVIDEND_TYPE_LEN];
   double h_redem_rt;
   char h_nser_info[CA_NSER_E_INFO_LEN];
   char h_nrep_date_a[CA_NSER_B_INFO_LEN];
   char h_comp_info1[CA_COMP_INFO_A_LEN];
   char h_inco_info1[CA_INCO_INFO_A_LEN];
   char h_buyresp_date[APL_DATE_LEN];
   char h_sellresp_date[APL_DATE_LEN];
   char h_wwwaddr[CA_WWWADDR_LEN];
   char h_txnr_info1[CA_TXNR_INFO_A_LEN];
   char h_reqd_cert_ind[CA_REQD_CERTIFY_LEN];
   char h_ex_dt_bse[APL_DATE_LEN];
   char h_bc_from_date[APL_DATE_LEN];
   char h_bc_to_date[APL_DATE_LEN];
   char h_res_instr_code_2[MT_INSTR_CODE_LEN];
   char h_trans_dt[APL_DATE_LEN];
   char h_cln_code[CA_CLN_CODE_LEN];
   char h_prev_inst_date[APL_DATE_LEN];
   char h_next_inst_date[APL_DATE_LEN];
   char h_inst_start_period[APL_DATE_LEN];
   char h_inst_end_period[APL_DATE_LEN];
   char h_last_ptc_date[APL_DATE_LEN];
   char h_allotment_letter[CA_ALLOTMENT_LETTER_LEN];
   char h_redem_option[CA_REDEM_OPTION_LEN];
   double h_inst_amount;
   char h_send_split[CA_SEND_SPLIT_LEN];
   char h_cmp_code[MT_CMP_CODE_LEN];
   char h_res_cmp_code[MT_CMP_CODE_LEN];
   char h_exch_code[MT_EXCH_CODE_LEN];
   double h_premium;
   double h_face_value;
   char h_interest_type[CA_INTEREST_TYPE_LEN];
   int h_ratio_rcv2;
   int h_ratio_hld2;
   char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
   char h_depo_code[MT_DEPO_CODE_LEN];
   char h_bk_build_ind[2];
/*   double h_first_call;
   double h_second_call;*/
   char h_attach_corp_id[21];
   char h_source[2];
   double h_new_safek_rt2;
}CAEVENT_STRUCT_H;
typedef struct{
   short i_corp_id;
   short i_instr_code;
   short i_evt_class;
   short i_decl_date;
   short i_evt_nbr;
   short i_priority;
   short i_preliminary_flag;
   short i_ca_currency;
   short i_ex_date;
   short i_rec_date;
   short i_pymt_dt;
   short i_respons_date;
   short i_expire_date;
   short i_pp_date;
   short i_proxy_date;
   short i_meet_date;
   short i_start_date;
   short i_effect_date;
   short i_proc_oth;
   short i_op_evt_class;
   short i_respons_date_openend;
   short i_expire_date_openend;
   short i_evt_send_msg_ind;
   short i_entl_send_msg_ind;
   short i_pymt_send_msg_ind;
   short i_earnings;
   short i_earnings_rt;
   short i_res_instr_code;
   short i_new_safek_quantity;
   short i_old_safek_quantity;
   short i_disp_of_fract;
   short i_f_pr;
   short i_sub_base_quantity;
   short i_sub_new_quantity;
   short i_sub_pr;
   short i_rights_class;
   short i_new_safek_quantity_rt;
   short i_contactinfo;
   short i_amount_due;
   short i_amount_recd;
   short i_quantity_due;
   short i_quantity_recd;
   short i_evt_msg_count;
   short i_evt_clt_cnt;
   short i_entl_msg_cnt;
   short i_entl_clt_cnt;
   short i_count_acs_pend;
   short i_nrepdate1;
   short i_follmsg1date;
   short i_follmsg2date;
   short i_info_nbr;
   short i_entinfo_no;
   short i_evt_stat;
   short i_stat_date;
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
   short i_dealfrom_dt;
   short i_dealto_dt;
   short i_subs_date;
   short i_posting_date;
   short i_over_subscrp;
   short i_div_class;
   short i_redem_rt;
   short i_nser_info;
   short i_nrep_date_a;
   short i_comp_info1;
   short i_inco_info1;
   short i_buyresp_date;
   short i_sellresp_date;
   short i_wwwaddr;
   short i_txnr_info1;
   short i_reqd_cert_ind;
   short i_ex_dt_bse;
   short i_bc_from_date;
   short i_bc_to_date;
   short i_res_instr_code_2;
   short i_trans_dt;
   short i_cln_code;
   short i_prev_inst_date;
   short i_next_inst_date;
   short i_inst_start_period;
   short i_inst_end_period;
   short i_last_ptc_date;
   short i_allotment_letter;
   short i_redem_option;
   short i_inst_amount;
   short i_send_split;
   short i_cmp_code;
   short i_res_cmp_code;
   short i_exch_code;
   short i_premium;
   short i_face_value;
   short i_interest_type;
   short i_ratio_rcv2;
   short i_ratio_hld2;
   short i_depo_part_code;
   short i_depo_code;
   short i_bk_build_ind;
   short i_first_call;
   short i_second_call;
   short i_attach_corp_id;
   short i_source;
   short i_new_safek_rt2;
}CAEVENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_INSTR_CODE_LEN 9
#define CA_CA_EVENT_LEN 3


#define CA_PRELIMINARY_FLAG_LEN 2
#define CA_CA_CURRENCY_LEN 4










#define CA_PROC_OTH_LEN 106
#define CA_OP_EVT_CLASS_LEN 3
#define CA_RESP_DT_OPND_LEN 2
#define CA_EXP_DT_OPEN_IND_LEN 2
#define CA_EVT_SEND_MSG_IND_LEN 2
#define CA_ENTL_SEND_MSG_IND_LEN 2
#define CA_PYMT_SEND_MSG_IND_LEN 2


#define CA_RES_INSTR_CODE_LEN 9


#define CA_DISP_OF_FRACT_LEN 2




#define CA_RHTS_CLASS_LEN 2

#define CA_CONTACT_DETAILS_LEN 241












#define CA_INFO_SEQ_LEN 5
#define CA_ENTITL_INFONO_LEN 5
#define CA_EVENT_STATUS_LEN 3

#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15






#define CA_OVER_SUBSCRP_LEN 2
#define CA_DIVIDEND_TYPE_LEN 2

#define CA_NSER_E_INFO_LEN 5
#define CA_NSER_B_INFO_LEN 5
#define CA_COMP_INFO_A_LEN 5
#define CA_INCO_INFO_A_LEN 5


#define CA_WWWADDR_LEN 101
#define CA_TXNR_INFO_A_LEN 5
#define CA_REQD_CERTIFY_LEN 2






#define CA_CORP_ID_LEN 21






#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15

#define CA_STAT_PYMT_LEN 3




typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	double h_elig_entitl_pos;
	double h_quantity_bal;
	double h_amount_bal;
	char h_dateof_payment[APL_DATE_LEN];
	double h_curr_qty_bal;
	double h_cur_amt_bal;
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_stat_pymt[CA_STAT_PYMT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_date_of_input[APL_DATE_LEN];
	double h_quantity_paid;
	double h_taxable_dividend;
}CAGLPYMT_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_elig_entitl_pos;
	short i_quantity_bal;
	short i_amount_bal;
	short i_dateof_payment;
	short i_curr_qty_bal;
	short i_cur_amt_bal;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_stat_pymt;
	short i_access_stamp;
	short i_date_of_input;
	short i_quantity_paid;
	short i_taxable_dividend;
}CAGLPYMT_STRUCT_I;







#define CA_INSTR_CODE_LEN 9
#define CA_CA_EVENT_LEN 3

#define CA_CORP_ID_LEN 21
typedef struct{
	char h_instr_code[CA_INSTR_CODE_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
}CALOGAUTOEVENT_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_ca_event;
	short i_dateof_payment;
	short i_corp_id;
}CALOGAUTOEVENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_PRELIMINARY_FLAG_LEN 2
#define CA_CLIENT_LEN 11
#define CA_SWIFT_MSG_NO_LEN 7
#define CA_MSG_IN_OUT_IND_LEN 2
#define CA_TYPEOF_MSG_LNK_LEN 3
#define CA_SWIFT_MSGREFNO_LEN 17

#define CA_INFORMATION_LEN 31
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_preliminary_flag[CA_PRELIMINARY_FLAG_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_swift_msg_no[CA_SWIFT_MSG_NO_LEN];
	char h_msg_in_out_ind[CA_MSG_IN_OUT_IND_LEN];
	char h_typeof_msg_lnk[CA_TYPEOF_MSG_LNK_LEN];
	char h_swift_msgrefno[CA_SWIFT_MSGREFNO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[CA_INFORMATION_LEN];
}CAMESGLINK_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_preliminary_flag;
	short i_client;
	short i_swift_msg_no;
	short i_msg_in_out_ind;
	short i_typeof_msg_lnk;
	short i_swift_msgrefno;
	short i_date_of_input;
	short i_information;
}CAMESGLINK_STRUCT_I;







#define CA_INFO_SEQ_LEN  9
#define CA_INFO_1_LEN 1751
#define CA_INFO_2_LEN 1751
#define CA_INFO_3_LEN 1751
#define CA_INFO_4_LEN 1751
#define CA_MAKER_LEN 15


#define CA_TYPEOF_INFO_LEN 5
typedef struct{
	char h_info_seq[CA_INFO_SEQ_LEN];
	char h_info_1[CA_INFO_1_LEN];
	char h_info_2[CA_INFO_2_LEN];
	char h_info_3[CA_INFO_3_LEN];
	char h_info_4[CA_INFO_4_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_typeof_info[CA_TYPEOF_INFO_LEN];
}CANOTE_STRUCT_H;
typedef struct{
	short i_info_seq;
	short i_info_1;
	short i_info_2;
	short i_info_3;
	short i_info_4;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_typeof_info;
}CANOTE_STRUCT_I;








#define CA_TASK_CD_LEN 61
#define CA_NOTIFY_CD_LEN 21
#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11
#define CA_INSTR_CODE_LEN 9

#define CA_INFORMATION_LEN 51
typedef struct{
	char h_dealdt[APL_DATE_LEN];
	char h_task_cd[CA_TASK_CD_LEN];
	char h_notify_cd[CA_NOTIFY_CD_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_instr_code[CA_INSTR_CODE_LEN];
	int h_seqnum_pay;
	char h_information[CA_INFORMATION_LEN];
}CANOTIFY_STRUCT_H;
typedef struct{
	short i_dealdt;
	short i_task_cd;
	short i_notify_cd;
	short i_corp_id;
	short i_client;
	short i_instr_code;
	short i_seqnum_pay;
	short i_information;
}CANOTIFY_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11



#define CA_INSTR_MSGREFNO_LEN 17

#define CA_SEND_RESP_IND_LEN 2
#define CA_STAT_CD_LEN 3
#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15

#define CA_STATUS_IND_LEN 3


typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_response_dt[APL_DATE_LEN];
	char h_res_msg_date[APL_DATE_LEN];
	char h_pymt_msg_date[APL_DATE_LEN];
	char h_instr_msgrefno[CA_INSTR_MSGREFNO_LEN];
	double h_instr_hold;
	char h_send_resp_ind[CA_SEND_RESP_IND_LEN];
	char h_stat_cd[CA_STAT_CD_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status_ind[CA_STATUS_IND_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_date_of_input[APL_DATE_LEN];
}CAREPLY_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_response_dt;
	short i_res_msg_date;
	short i_pymt_msg_date;
	short i_instr_msgrefno;
	short i_instr_hold;
	short i_send_resp_ind;
	short i_stat_cd;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status_ind;
	short i_access_stamp;
	short i_date_of_input;
}CAREPLY_STRUCT_I;








#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 21

#define CA_INSTR_MSGREFNO_LEN 17
#define CA_SEND_RESP_IND_LEN 2
#define CA_STAT_CD_LEN 3
#define CA_STATUS_IND_LEN 3

#define CA_CA_OPTCD_LEN 9
typedef struct{
	int h_srl_num;
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	double h_holding_amt;
	char h_instr_msgrefno[CA_INSTR_MSGREFNO_LEN];
	char h_send_resp_ind[CA_SEND_RESP_IND_LEN];
	char h_stat_cd[CA_STAT_CD_LEN];
	char h_status_ind[CA_STATUS_IND_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_ca_optcd[CA_CA_OPTCD_LEN];
}CAREPLYSPLIT_STRUCT_H;
typedef struct{
	short i_srl_num;
	short i_corp_id;
	short i_client;
	short i_holding_amt;
	short i_instr_msgrefno;
	short i_send_resp_ind;
	short i_stat_cd;
	short i_status_ind;
	short i_access_stamp;
	short i_ca_optcd;
}CAREPLYSPLIT_STRUCT_I;







#define CA_INSTR_CODE_LEN 9
#define CA_CLIENT_LEN 11
#define CA_CA_EVENT_LEN 3


#define CA_INSTR_PARENT_LEN 9
#define CA_CORP_ID_LEN 21



#define CA_LOCATION_CD_LEN 5


#define CA_SUB_CURRENCY_LEN 4

#define CA_INFO_SEQ_LEN 5
#define CA_EVENT_STATUS_LEN 3
#define CA_MAKER_LEN 15

#define CA_CHECKER_LEN 15




typedef struct{
	char h_instr_code[CA_INSTR_CODE_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	char h_declare_dt[APL_DATE_LEN];
	int h_evnt_indnt;
	char h_instr_parent[CA_INSTR_PARENT_LEN];
	char h_corp_id[CA_CORP_ID_LEN];
	double h_total_quantity;
	double h_takeup_quantity;
	double h_lapse_qty;
	char h_location_cd[CA_LOCATION_CD_LEN];
	int h_sub_base_quantity;
	double h_sub_new_quantity;
	char h_sub_currency[CA_SUB_CURRENCY_LEN];
	double h_sub_pr;
	char h_info_seq[CA_INFO_SEQ_LEN];
	char h_event_status[CA_EVENT_STATUS_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[CA_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
}CARTSPROC_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_client;
	short i_ca_event;
	short i_declare_dt;
	short i_evnt_indnt;
	short i_instr_parent;
	short i_corp_id;
	short i_total_quantity;
	short i_takeup_quantity;
	short i_lapse_qty;
	short i_location_cd;
	short i_sub_base_quantity;
	short i_sub_new_quantity;
	short i_sub_currency;
	short i_sub_pr;
	short i_info_seq;
	short i_event_status;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_payment;
	short i_trans_date;
}CARTSPROC_STRUCT_I;







#define CA_INSTR_TYPE_LEN 4
#define CA_CA_EVENT_LEN 3
#define CA_PAYOUT_FLAG_LEN 2
#define CA_ENTITL_BASE_LEN 2
#define CA_RATIO_PERC_IND_LEN 2
#define CA_AMOUNT_RATIO_FLG_LEN 2
#define CA_AUTO_DLCRT_IND_LEN 2
#define CA_SNDMSG_TO_ALLMAST_LEN 2
#define CA_GEN_ENRAREP_IND_LEN 2



typedef struct{
	char h_instr_type[CA_INSTR_TYPE_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	char h_payout_flag[CA_PAYOUT_FLAG_LEN];
	char h_entitl_base[CA_ENTITL_BASE_LEN];
	char h_ratio_perc_ind[CA_RATIO_PERC_IND_LEN];
	char h_amount_ratio_flg[CA_AMOUNT_RATIO_FLG_LEN];
	char h_auto_dlcrt_ind[CA_AUTO_DLCRT_IND_LEN];
	char h_sndmsg_to_allmast[CA_SNDMSG_TO_ALLMAST_LEN];
	char h_gen_enrarep_ind[CA_GEN_ENRAREP_IND_LEN];
	int h_enra_lapse_a;
	int h_enra_lapse_b;
	int h_enra_lapse_c;
}CASECEVENT_STRUCT_H;
typedef struct{
	short i_instr_type;
	short i_ca_event;
	short i_payout_flag;
	short i_entitl_base;
	short i_ratio_perc_ind;
	short i_amount_ratio_flg;
	short i_auto_dlcrt_ind;
	short i_sndmsg_to_allmast;
	short i_gen_enrarep_ind;
	short i_enra_lapse_a;
	short i_enra_lapse_b;
	short i_enra_lapse_c;
}CASECEVENT_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11
#define CA_STAT_CD_LEN 3
#define CA_DETAIL_LEN 211
#define CA_MAKER_LEN 15


#define CA_INSTR_MSGREFNO_LEN 17
#define CA_CA_OPTCD_LEN 9

typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
	char h_stat_cd[CA_STAT_CD_LEN];
	char h_detail[CA_DETAIL_LEN];
	char h_maker[CA_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_instr_msgrefno[CA_INSTR_MSGREFNO_LEN];
	char h_ca_optcd[CA_CA_OPTCD_LEN];
	double h_instr_hold;
}CASTATUS_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
	short i_stat_cd;
	short i_detail;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_instr_msgrefno;
	short i_ca_optcd;
	short i_instr_hold;
}CASTATUS_STRUCT_I;







#define CA_ENTITL_BASE_LEN 2
#define CA_AMOUNT_RATIO_FLG_LEN 2
#define CA_RATIO_PERC_IND_BO_LEN 2
#define CA_RATIO_PERC_IND_SD_LEN 2
#define CA_RATIO_PERC_IND_RHTS_LEN 2
#define CA_CREATE_TRD_BO_IND_LEN 2
#define CA_CREATE_TRD_SD_IND_LEN 2
#define CA_CREATE_TRD_RTS_IND_LEN 2
#define CA_CREATE_TRD_RD_IND_LEN 2
#define CA_CREATE_TRD_SPLIT_IND_LEN 2
#define CA_SNDMSG_TO_ALLMAST_LEN 2
#define CA_CREATE_EVNT_BOND_INT_LEN 2

#define CA_CREATE_EVNT_MMI_INT_LEN 2

#define CA_CREATE_EVNT_BOND_RD_LEN 2

#define CA_CREATE_EVNT_MMI_RD_LEN 2



#define CA_GEN_ENRAREP_IND_LEN 2



typedef struct{
	char h_entitl_base[CA_ENTITL_BASE_LEN];
	char h_amount_ratio_flg[CA_AMOUNT_RATIO_FLG_LEN];
	char h_ratio_perc_ind_bo[CA_RATIO_PERC_IND_BO_LEN];
	char h_ratio_perc_ind_sd[CA_RATIO_PERC_IND_SD_LEN];
	char h_ratio_perc_ind_rhts[CA_RATIO_PERC_IND_RHTS_LEN];
	char h_create_trd_bo_ind[CA_CREATE_TRD_BO_IND_LEN];
	char h_create_trd_sd_ind[CA_CREATE_TRD_SD_IND_LEN];
	char h_create_trd_rts_ind[CA_CREATE_TRD_RTS_IND_LEN];
	char h_create_trd_rd_ind[CA_CREATE_TRD_RD_IND_LEN];
	char h_create_trd_split_ind[CA_CREATE_TRD_SPLIT_IND_LEN];
	char h_sndmsg_to_allmast[CA_SNDMSG_TO_ALLMAST_LEN];
	char h_create_evnt_bond_int[CA_CREATE_EVNT_BOND_INT_LEN];
	int h_bond_int_no_days_pay_dt;
	char h_create_evnt_mmi_int[CA_CREATE_EVNT_MMI_INT_LEN];
	int h_mmi_int_no_days_pay_dt;
	char h_create_evnt_bond_rd[CA_CREATE_EVNT_BOND_RD_LEN];
	int h_bond_rd_no_days_mat_dt;
	char h_create_evnt_mmi_rd[CA_CREATE_EVNT_MMI_RD_LEN];
	int h_mmi_rd_no_days_mat_dt;
	int h_bond_exdt_no_days;
	int h_mmi_exdt_no_days;
	char h_gen_enrarep_ind[CA_GEN_ENRAREP_IND_LEN];
	int h_enra_lapse1;
	int h_enra_lapse2;
	int h_enra_lapse3;
}CASYSTEMPARAMS_STRUCT_H;
typedef struct{
	short i_entitl_base;
	short i_amount_ratio_flg;
	short i_ratio_perc_ind_bo;
	short i_ratio_perc_ind_sd;
	short i_ratio_perc_ind_rhts;
	short i_create_trd_bo_ind;
	short i_create_trd_sd_ind;
	short i_create_trd_rts_ind;
	short i_create_trd_rd_ind;
	short i_create_trd_split_ind;
	short i_sndmsg_to_allmast;
	short i_create_evnt_bond_int;
	short i_bond_int_no_days_pay_dt;
	short i_create_evnt_mmi_int;
	short i_mmi_int_no_days_pay_dt;
	short i_create_evnt_bond_rd;
	short i_bond_rd_no_days_mat_dt;
	short i_create_evnt_mmi_rd;
	short i_mmi_rd_no_days_mat_dt;
	short i_bond_exdt_no_days;
	short i_mmi_exdt_no_days;
	short i_gen_enrarep_ind;
	short i_enra_lapse1;
	short i_enra_lapse2;
	short i_enra_lapse3;
}CASYSTEMPARAMS_STRUCT_I;





































/*
typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}CA_ENTITLEMENTREP_STRUCT_H;
*/
typedef struct{
	short i_corp_id;
	short i_instr_code;
	short i_ca_event;
	short i_declare_dt;
	short i_evnt_indnt;
	short i_ex_date;
	short i_rec_date;
	short i_dateof_payment;
	short i_earnings;
	short i_instr_inc_rate;
	short i_res_instr_code;
	short i_new_safek_qty;
	short i_old_stk_qty;
	short i_disp_of_fract;
	short i_fract_pr;
	short i_new_safek_rt;
	short i_client;
	short i_elig_entitl_pos;
	short i_instr_inc_bal;
	short i_quantity_bal;
	short i_custodytax_rate;
	short i_payout_flag;
	short i_ratio_perc_ind;
	short i_amount_ratio_flg;
	short i_nominal_value;
	short i_instr_type;
	short i_instr_name;
	short i_res_instr_name;
	short i_clnt_name;
	short i_contact_details;
	short i_custodytaxrt;
}CA_ENTITLEMENTREP_STRUCT_I;







#define CA_CORP_ID_LEN 21
#define CA_CLIENT_LEN 11
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_client[CA_CLIENT_LEN];
}CA_EVENTMESGSEND_STRUCT_H;
typedef struct{
	short i_corp_id;
	short i_client;
}CA_EVENTMESGSEND_STRUCT_I;















/*
typedef struct{
	
	
	
	
	
	
	
	
	
}CA_EXDTHLD1_VEW_STRUCT_H;
*/
typedef struct{
	short i_client;
	short i_master_clt;
	short i_clnt_name;
	short i_quant;
	short i_instr_code;
	short i_deal_safe;
	short i_dealdate;
	short i_instr_dt;
	short i_deal_cd;
}CA_EXDTHLD1_VEW_STRUCT_I;















/*
typedef struct{
	
	
	
	
	
	
	
	
	
}CA_EXDTHLD2_VEW_STRUCT_H;
*/
typedef struct{
	short i_client;
	short i_master_clt;
	short i_clnt_name;
	short i_quant;
	short i_instr_code;
	short i_deal_safe;
	short i_dealdate;
	short i_instr_dt;
	short i_deal_cd;
}CA_EXDTHLD2_VEW_STRUCT_I;









/*

typedef struct{
	
	
	
	
}CIMS_ACC_VEW_STRUCT_H;
*/
typedef struct{
	short i_details1;
	short i_details2;
	short i_details3;
	short i_details4;
}CIMS_ACC_VEW_STRUCT_I;







#define CO_BASE_QUERY_ID_LEN 6
#define CO_BASE_QUERY_LEN 4001
#define CO_BASE_QUERY1_LEN 4001
#define CO_BASE_QUERY2_LEN 4001
#define CO_HEADER_FIELDS_LEN 701
#define CO_PRIMARY_KEY_COLUMNS_LEN 301
#define CO_HASHMAP_QUERY_LEN 4001
#define CO_HASHMAP_QUERY1_LEN 4001
#define CO_HASHMAP_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
#define CO_LINK_LEN 2
typedef struct{
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_base_query[CO_BASE_QUERY_LEN];
	char h_base_query1[CO_BASE_QUERY1_LEN];
	char h_base_query2[CO_BASE_QUERY2_LEN];
	char h_header_fields[CO_HEADER_FIELDS_LEN];
	char h_primary_key_columns[CO_PRIMARY_KEY_COLUMNS_LEN];
	char h_hashmap_query[CO_HASHMAP_QUERY_LEN];
	char h_hashmap_query1[CO_HASHMAP_QUERY1_LEN];
	char h_hashmap_query2[CO_HASHMAP_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
	char h_link[CO_LINK_LEN];
}COMMON_BASE_QUERY_MAPPING_STRUCT_H;
typedef struct{
	short i_base_query_id;
	short i_base_query;
	short i_base_query1;
	short i_base_query2;
	short i_header_fields;
	short i_primary_key_columns;
	short i_hashmap_query;
	short i_hashmap_query1;
	short i_hashmap_query2;
	short i_datatypes;
	short i_link;
}COMMON_BASE_QUERY_MAPPING_STRUCT_I;







#define CO_BASE_QUERY_ID_LEN 6
#define CO_BASE_QUERY_LEN 4001
#define CO_BASE_QUERY1_LEN 4001
#define CO_BASE_QUERY2_LEN 4001
#define CO_HEADER_FIELDS_LEN 701
#define CO_PRIMARY_KEY_COLUMNS_LEN 301
#define CO_HASHMAP_QUERY_LEN 4001
#define CO_HASHMAP_QUERY1_LEN 4001
#define CO_HASHMAP_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
#define CO_LINK_LEN 2
typedef struct{
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_base_query[CO_BASE_QUERY_LEN];
	char h_base_query1[CO_BASE_QUERY1_LEN];
	char h_base_query2[CO_BASE_QUERY2_LEN];
	char h_header_fields[CO_HEADER_FIELDS_LEN];
	char h_primary_key_columns[CO_PRIMARY_KEY_COLUMNS_LEN];
	char h_hashmap_query[CO_HASHMAP_QUERY_LEN];
	char h_hashmap_query1[CO_HASHMAP_QUERY1_LEN];
	char h_hashmap_query2[CO_HASHMAP_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
	char h_link[CO_LINK_LEN];
}COMMON_BASE_QUERY_MAPPING_BACK_STRUCT_H;
typedef struct{
	short i_base_query_id;
	short i_base_query;
	short i_base_query1;
	short i_base_query2;
	short i_header_fields;
	short i_primary_key_columns;
	short i_hashmap_query;
	short i_hashmap_query1;
	short i_hashmap_query2;
	short i_datatypes;
	short i_link;
}COMMON_BASE_QUERY_MAPPING_BACK_STRUCT_I;







#define CO_BASE_QUERY_ID_LEN 6
#define CO_BASE_QUERY_LEN 4001
#define CO_BASE_QUERY1_LEN 4001
#define CO_BASE_QUERY2_LEN 4001
#define CO_HEADER_FIELDS_LEN 701
#define CO_PRIMARY_KEY_COLUMNS_LEN 301
#define CO_HASHMAP_QUERY_LEN 4001
#define CO_HASHMAP_QUERY1_LEN 4001
#define CO_HASHMAP_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
#define CO_LINK_LEN 2
typedef struct{
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_base_query[CO_BASE_QUERY_LEN];
	char h_base_query1[CO_BASE_QUERY1_LEN];
	char h_base_query2[CO_BASE_QUERY2_LEN];
	char h_header_fields[CO_HEADER_FIELDS_LEN];
	char h_primary_key_columns[CO_PRIMARY_KEY_COLUMNS_LEN];
	char h_hashmap_query[CO_HASHMAP_QUERY_LEN];
	char h_hashmap_query1[CO_HASHMAP_QUERY1_LEN];
	char h_hashmap_query2[CO_HASHMAP_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
	char h_link[CO_LINK_LEN];
}COMMON_BASE_QUERY_MAPPING_BAK_STRUCT_H;
typedef struct{
	short i_base_query_id;
	short i_base_query;
	short i_base_query1;
	short i_base_query2;
	short i_header_fields;
	short i_primary_key_columns;
	short i_hashmap_query;
	short i_hashmap_query1;
	short i_hashmap_query2;
	short i_datatypes;
	short i_link;
}COMMON_BASE_QUERY_MAPPING_BAK_STRUCT_I;







#define CO_ENTITY_NAME_LEN 51
#define CO_PROCEDURE_NAME_LEN 31
#define CO_WRAPPER_NAME_LEN 51
#define CO_ENTITY_MODE_LEN 11
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_procedure_name[CO_PROCEDURE_NAME_LEN];
	char h_wrapper_name[CO_WRAPPER_NAME_LEN];
	char h_entity_mode[CO_ENTITY_MODE_LEN];
}COMMON_ENTITY_PROC_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_procedure_name;
	short i_wrapper_name;
	short i_entity_mode;
}COMMON_ENTITY_PROC_STRUCT_I;







#define CO_ENTITY_NAME_LEN 51
#define CO_PROCEDURE_NAME_LEN 31
#define CO_WRAPPER_NAME_LEN 51
#define CO_ENTITY_MODE_LEN 11
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_procedure_name[CO_PROCEDURE_NAME_LEN];
	char h_wrapper_name[CO_WRAPPER_NAME_LEN];
	char h_entity_mode[CO_ENTITY_MODE_LEN];
}COMMON_ENTITY_PROC_230106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_procedure_name;
	short i_wrapper_name;
	short i_entity_mode;
}COMMON_ENTITY_PROC_230106_STRUCT_I;







#define CO_ENTITY_NAME_LEN 51
#define CO_PROCEDURE_NAME_LEN 31
#define CO_WRAPPER_NAME_LEN 51
#define CO_ENTITY_MODE_LEN 11
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_procedure_name[CO_PROCEDURE_NAME_LEN];
	char h_wrapper_name[CO_WRAPPER_NAME_LEN];
	char h_entity_mode[CO_ENTITY_MODE_LEN];
}COMMON_ENTITY_PROC_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_procedure_name;
	short i_wrapper_name;
	short i_entity_mode;
}COMMON_ENTITY_PROC_BAK_STRUCT_I;







#define CO_GRID_INDICATOR_LEN 41
#define CO_GRID_CLASS_NAME_LEN 401
#define CO_GRID_NAME_LEN 41
#define CO_GRID_QUERY_LEN 4001
#define CO_GRID_QUERY1_LEN 4001
#define CO_GRID_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
typedef struct{
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
	char h_grid_class_name[CO_GRID_CLASS_NAME_LEN];
	char h_grid_name[CO_GRID_NAME_LEN];
	char h_grid_query[CO_GRID_QUERY_LEN];
	char h_grid_query1[CO_GRID_QUERY1_LEN];
	char h_grid_query2[CO_GRID_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
}COMMON_GRID_MAPPING_STRUCT_H;
typedef struct{
	short i_grid_indicator;
	short i_grid_class_name;
	short i_grid_name;
	short i_grid_query;
	short i_grid_query1;
	short i_grid_query2;
	short i_datatypes;
}COMMON_GRID_MAPPING_STRUCT_I;







#define CO_GRID_INDICATOR_LEN 41
#define CO_GRID_CLASS_NAME_LEN 401
#define CO_GRID_NAME_LEN 41
#define CO_GRID_QUERY_LEN 4001
#define CO_GRID_QUERY1_LEN 4001
#define CO_GRID_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
typedef struct{
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
	char h_grid_class_name[CO_GRID_CLASS_NAME_LEN];
	char h_grid_name[CO_GRID_NAME_LEN];
	char h_grid_query[CO_GRID_QUERY_LEN];
	char h_grid_query1[CO_GRID_QUERY1_LEN];
	char h_grid_query2[CO_GRID_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
}COMMON_GRID_MAPPING_230106_STRUCT_H;
typedef struct{
	short i_grid_indicator;
	short i_grid_class_name;
	short i_grid_name;
	short i_grid_query;
	short i_grid_query1;
	short i_grid_query2;
	short i_datatypes;
}COMMON_GRID_MAPPING_230106_STRUCT_I;







#define CO_GRID_INDICATOR_LEN 41
#define CO_GRID_CLASS_NAME_LEN 401
#define CO_GRID_NAME_LEN 41
#define CO_GRID_QUERY_LEN 4001
#define CO_GRID_QUERY1_LEN 4001
#define CO_GRID_QUERY2_LEN 4001
#define CO_DATATYPES_LEN 4001
typedef struct{
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
	char h_grid_class_name[CO_GRID_CLASS_NAME_LEN];
	char h_grid_name[CO_GRID_NAME_LEN];
	char h_grid_query[CO_GRID_QUERY_LEN];
	char h_grid_query1[CO_GRID_QUERY1_LEN];
	char h_grid_query2[CO_GRID_QUERY2_LEN];
	char h_datatypes[CO_DATATYPES_LEN];
}COMMON_GRID_MAPPING_BAK_STRUCT_H;
typedef struct{
	short i_grid_indicator;
	short i_grid_class_name;
	short i_grid_name;
	short i_grid_query;
	short i_grid_query1;
	short i_grid_query2;
	short i_datatypes;
}COMMON_GRID_MAPPING_BAK_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4

#define CO_FIELD_NAME_LEN 51
#define CO_FIELD_DB_LEN 101
#define CO_CONTROL_TYPE_LEN 26
#define CO_GLOBALPICKLIST_NAME_LEN 26


typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	int h_field_no;
	char h_field_name[CO_FIELD_NAME_LEN];
	char h_field_db[CO_FIELD_DB_LEN];
	char h_control_type[CO_CONTROL_TYPE_LEN];
	char h_globalpicklist_name[CO_GLOBALPICKLIST_NAME_LEN];
	int h_field_length;
	int h_decimal_length;
}COMMON_SEARCH_FORM_MAP_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_field_no;
	short i_field_name;
	short i_field_db;
	short i_control_type;
	short i_globalpicklist_name;
	short i_field_length;
	short i_decimal_length;
}COMMON_SEARCH_FORM_MAP_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4

#define CO_FIELD_NAME_LEN 51
#define CO_FIELD_DB_LEN 101
#define CO_CONTROL_TYPE_LEN 26
#define CO_GLOBALPICKLIST_NAME_LEN 26


typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	int h_field_no;
	char h_field_name[CO_FIELD_NAME_LEN];
	char h_field_db[CO_FIELD_DB_LEN];
	char h_control_type[CO_CONTROL_TYPE_LEN];
	char h_globalpicklist_name[CO_GLOBALPICKLIST_NAME_LEN];
	int h_field_length;
	int h_decimal_length;
}COMMON_SEARCH_FORM_MAP_230106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_field_no;
	short i_field_name;
	short i_field_db;
	short i_control_type;
	short i_globalpicklist_name;
	short i_field_length;
	short i_decimal_length;
}COMMON_SEARCH_FORM_MAP_230106_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4

#define CO_FIELD_NAME_LEN 51
#define CO_FIELD_DB_LEN 101
#define CO_CONTROL_TYPE_LEN 26
#define CO_GLOBALPICKLIST_NAME_LEN 26


typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	int h_field_no;
	char h_field_name[CO_FIELD_NAME_LEN];
	char h_field_db[CO_FIELD_DB_LEN];
	char h_control_type[CO_CONTROL_TYPE_LEN];
	char h_globalpicklist_name[CO_GLOBALPICKLIST_NAME_LEN];
	int h_field_length;
	int h_decimal_length;
}COMMON_SEARCH_FORM_MAP_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_field_no;
	short i_field_name;
	short i_field_db;
	short i_control_type;
	short i_globalpicklist_name;
	short i_field_length;
	short i_decimal_length;
}COMMON_SEARCH_FORM_MAP_BAK_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4
#define CO_WHERE_CLAUSE_LEN 4001
#define CO_BASE_QUERY_ID_LEN 6
#define CO_ORDERBY_CLAUSE_LEN 4001
#define CO_CASE_STRING_MAP_LEN 21
#define CO_FORM_TO_CALL_LEN 41
#define CO_GRID_INDICATOR_LEN 21
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	char h_where_clause[CO_WHERE_CLAUSE_LEN];
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_orderby_clause[CO_ORDERBY_CLAUSE_LEN];
	char h_case_string_map[CO_CASE_STRING_MAP_LEN];
	char h_form_to_call[CO_FORM_TO_CALL_LEN];
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
}COMMON_VIEW_FORM_MAP_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_where_clause;
	short i_base_query_id;
	short i_orderby_clause;
	short i_case_string_map;
	short i_form_to_call;
	short i_grid_indicator;
}COMMON_VIEW_FORM_MAP_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4
#define CO_WHERE_CLAUSE_LEN 4001
#define CO_BASE_QUERY_ID_LEN 6
#define CO_ORDERBY_CLAUSE_LEN 4001
#define CO_CASE_STRING_MAP_LEN 21
#define CO_FORM_TO_CALL_LEN 41
#define CO_GRID_INDICATOR_LEN 21
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	char h_where_clause[CO_WHERE_CLAUSE_LEN];
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_orderby_clause[CO_ORDERBY_CLAUSE_LEN];
	char h_case_string_map[CO_CASE_STRING_MAP_LEN];
	char h_form_to_call[CO_FORM_TO_CALL_LEN];
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
}COMMON_VIEW_FORM_MAP_230106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_where_clause;
	short i_base_query_id;
	short i_orderby_clause;
	short i_case_string_map;
	short i_form_to_call;
	short i_grid_indicator;
}COMMON_VIEW_FORM_MAP_230106_STRUCT_I;







#define CO_ENTITY_NAME_LEN 26
#define CO_FUNC_MODE_LEN 4
#define CO_WHERE_CLAUSE_LEN 4001
#define CO_BASE_QUERY_ID_LEN 6
#define CO_ORDERBY_CLAUSE_LEN 4001
#define CO_CASE_STRING_MAP_LEN 21
#define CO_FORM_TO_CALL_LEN 41
#define CO_GRID_INDICATOR_LEN 21
typedef struct{
	char h_entity_name[CO_ENTITY_NAME_LEN];
	char h_func_mode[CO_FUNC_MODE_LEN];
	char h_where_clause[CO_WHERE_CLAUSE_LEN];
	char h_base_query_id[CO_BASE_QUERY_ID_LEN];
	char h_orderby_clause[CO_ORDERBY_CLAUSE_LEN];
	char h_case_string_map[CO_CASE_STRING_MAP_LEN];
	char h_form_to_call[CO_FORM_TO_CALL_LEN];
	char h_grid_indicator[CO_GRID_INDICATOR_LEN];
}COMMON_VIEW_FORM_MAP_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_func_mode;
	short i_where_clause;
	short i_base_query_id;
	short i_orderby_clause;
	short i_case_string_map;
	short i_form_to_call;
	short i_grid_indicator;
}COMMON_VIEW_FORM_MAP_BAK_STRUCT_I;







#define CO_CODE_IDENT_LEN 21
#define CO_CODE_VALUE_LEN 21
#define CO_CODE_DESC_LEN 41
#define CO_COUNTRY_CODE_LEN 3
typedef struct{
	char h_code_ident[CO_CODE_IDENT_LEN];
	char h_code_value[CO_CODE_VALUE_LEN];
	char h_code_desc[CO_CODE_DESC_LEN];
	char h_country_code[CO_COUNTRY_CODE_LEN];
}CO_STATIC_DATA_STRUCT_H;
typedef struct{
	short i_code_ident;
	short i_code_value;
	short i_code_desc;
	short i_country_code;
}CO_STATIC_DATA_STRUCT_I;







#define CO_CODE_IDENT_LEN 21
#define CO_CODE_VALUE_LEN 21
#define CO_CODE_DESC_LEN 41
#define CO_COUNTRY_CODE_LEN 3
typedef struct{
	char h_code_ident[CO_CODE_IDENT_LEN];
	char h_code_value[CO_CODE_VALUE_LEN];
	char h_code_desc[CO_CODE_DESC_LEN];
	char h_country_code[CO_COUNTRY_CODE_LEN];
}CO_STATIC_DATA_BAK_STRUCT_H;
typedef struct{
	short i_code_ident;
	short i_code_value;
	short i_code_desc;
	short i_country_code;
}CO_STATIC_DATA_BAK_STRUCT_I;







#define CS_INSTR_TYPE_LEN 4
#define CS_DEALTYPE_LEN 2
#define CS_CURR_FLAG_LEN 2
#define CS_CLASSCD_LEN 5
#define CS_DR_CLT_GL_LEN 11
#define CS_CLT_GL_LEN 11
#define CS_NARRATIVE_LEN 61
typedef struct{
	char h_instr_type[CS_INSTR_TYPE_LEN];
	char h_dealtype[CS_DEALTYPE_LEN];
	char h_curr_flag[CS_CURR_FLAG_LEN];
	char h_classcd[CS_CLASSCD_LEN];
	char h_dr_clt_gl[CS_DR_CLT_GL_LEN];
	char h_clt_gl[CS_CLT_GL_LEN];
	char h_narrative[CS_NARRATIVE_LEN];
}CSCAENT_STRUCT_H;
typedef struct{
	short i_instr_type;
	short i_dealtype;
	short i_curr_flag;
	short i_classcd;
	short i_dr_clt_gl;
	short i_clt_gl;
	short i_narrative;
}CSCAENT_STRUCT_I;







#define CS_MAP_TYPE_LEN 21
#define CS_CLASS_LEN 2
#define CS_MAP_DESC_LEN 51
typedef struct{
	char h_map_type[CS_MAP_TYPE_LEN];
	char h_class[CS_CLASS_LEN];
	char h_map_desc[CS_MAP_DESC_LEN];
}CSCODE_STRUCT_H;
typedef struct{
	short i_map_type;
	short i_class;
	short i_map_desc;
}CSCODE_STRUCT_I;







#define CU_MASTER_CLT_LEN 11
#define CU_CLIENT_LEN 11
#define CU_INSTR_CODE_LEN 9
#define CU_LOCATION_CD_LEN 5












typedef struct{
	char h_master_clt[CU_MASTER_CLT_LEN];
	char h_client[CU_CLIENT_LEN];
	char h_instr_code[CU_INSTR_CODE_LEN];
	char h_location_cd[CU_LOCATION_CD_LEN];
	double h_nominal_value;
	double h_safekeep_pos;
	double h_nvalreceive;
	double h_nvaldeliver;
	double h_val_rec;
	double h_val_del;
	double h_chng_nompr;
	double h_chng_pos;
	double h_chng_nvalrec;
	double h_chng_nvaldel;
	double h_chng_valrec;
	double h_chng_valdel;
}CURRENCY_CONV_REPORT_STRUCT_H;
typedef struct{
	short i_master_clt;
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_nominal_value;
	short i_safekeep_pos;
	short i_nvalreceive;
	short i_nvaldeliver;
	short i_val_rec;
	short i_val_del;
	short i_chng_nompr;
	short i_chng_pos;
	short i_chng_nvalrec;
	short i_chng_nvaldel;
	short i_chng_valrec;
	short i_chng_valdel;
}CURRENCY_CONV_REPORT_STRUCT_I;









typedef struct{
	char h_generate_date[APL_DATE_LEN];
	double h_deal_count;
}DEAL_COUNT_STRUCT_H;
typedef struct{
	short i_generate_date;
	short i_deal_count;
}DEAL_COUNT_STRUCT_I;







#define DE_SWIFT_MSG_NO_LEN 7
#define DE_CLIENT_LEN 11
#define DE_IDENTIY_NO_LEN 17
#define DE_SWIFT_MSGREFNO_LEN 17
#define DE_EVENT_ID_LEN 17

typedef struct{
	char h_swift_msg_no[DE_SWIFT_MSG_NO_LEN];
	char h_client[DE_CLIENT_LEN];
	char h_identiy_no[DE_IDENTIY_NO_LEN];
	char h_swift_msgrefno[DE_SWIFT_MSGREFNO_LEN];
	char h_event_id[DE_EVENT_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
}DEAL_EVNTIDLINK_STRUCT_H;
typedef struct{
	short i_swift_msg_no;
	short i_client;
	short i_identiy_no;
	short i_swift_msgrefno;
	short i_event_id;
	short i_access_stamp;
}DEAL_EVNTIDLINK_STRUCT_I;







#define DE_CLIENT_LEN 11
#define DE_DOMESTIC_CPCLT_LEN 11
#define DE_CP_CLT_LEN 11
#define DE_LR_DL_CLASS_LEN 3
#define DE_DEAL_STAT_LEN 3
#define DE_IDENTIY_NO_LEN 17
#define DE_INSTR_CODE_LEN 9
#define DE_DL_CLASS_LEN 3

#define DE_DEAL_CD_LEN 2


#define DE_CHECKER_LEN 15


#define DE_DEAL_FRM_ORD_LEN 2
#define DE_CP_CLTNAME_LEN 66

#define DE_EX_ARENA_LEN 3

typedef struct{
	char h_client[DE_CLIENT_LEN];
	char h_domestic_cpclt[DE_DOMESTIC_CPCLT_LEN];
	char h_cp_clt[DE_CP_CLT_LEN];
	char h_lr_dl_class[DE_LR_DL_CLASS_LEN];
	char h_deal_stat[DE_DEAL_STAT_LEN];
	char h_identiy_no[DE_IDENTIY_NO_LEN];
	char h_instr_code[DE_INSTR_CODE_LEN];
	char h_dl_class[DE_DL_CLASS_LEN];
	double h_qty;
	char h_deal_cd[DE_DEAL_CD_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_checker[DE_CHECKER_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_deal_frm_ord[DE_DEAL_FRM_ORD_LEN];
	char h_cp_cltname[DE_CP_CLTNAME_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_ex_arena[DE_EX_ARENA_LEN];
	double h_setl_iden_no;
}DEAL_LOCALREP_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_domestic_cpclt;
	short i_cp_clt;
	short i_lr_dl_class;
	short i_deal_stat;
	short i_identiy_no;
	short i_instr_code;
	short i_dl_class;
	short i_qty;
	short i_deal_cd;
	short i_instrument_dt;
	short i_val_fdt;
	short i_checker;
	short i_nds_date;
	short i_dateof_input;
	short i_deal_frm_ord;
	short i_cp_cltname;
	short i_access_stamp;
	short i_ex_arena;
	short i_setl_iden_no;
}DEAL_LOCALREP_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3

#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
#define DL_CLNT_NAME_LEN 130 
#define DL_DOMESTIC_CPNAME_LEN 66
#define DL_DOMCP_CUSTODYNM_LEN 66
#define DL_INSTR_NAME_LEN 131

#define MF_SEQNO_LEN 6

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
	double h_comm_amt;/*** For detailed Bill Printing : vinay kalaskar ******/
	char h_mf_seqno[MF_SEQNO_LEN];/**** For BillGeneration : vinay kalaskar ****/
	char h_clnt_name[DL_CLNT_NAME_LEN];
	char h_domestic_cpname[DL_DOMESTIC_CPNAME_LEN];
	char h_domcp_custodynm[DL_DOMCP_CUSTODYNM_LEN];
	char h_instr_name[DL_INSTR_NAME_LEN];
	char h_closing_date[APL_DATE_LEN];
}DL_ARCHDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
	short i_comm_amt;/**** For Detailed Bill Printing : vinay kalaskar ****/
	short i_mf_seqno;/**** For BillGeneration :vinay kalaskar ******/
	short i_clnt_name;
	short i_domestic_cpname;
	short i_domcp_custodynm;
	short i_instr_name;
	short i_closing_date;
}DL_ARCHDEAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_TRAIL_FOR_LEN 2
#define DL_TASK_DESC_LEN 61
#define DL_PROC_USR_LEN 15
#define DL_SUBPROCESS_LEN 4

#define DL_FAILREASON_CD_LEN 3

#define DL_DEAL_FRM_ORD_LEN 2


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_trail_for[DL_TRAIL_FOR_LEN];
	char h_task_desc[DL_TASK_DESC_LEN];
	char h_proc_usr[DL_PROC_USR_LEN];
	char h_subprocess[DL_SUBPROCESS_LEN];
	char h_proc_date[APL_DATE_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	double h_qty;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	int h_sub_fail_cd;
	char h_dateof_input[APL_DATE_LEN];
}DL_ARCHDLAUDIT_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_trail_for;
	short i_task_desc;
	short i_proc_usr;
	short i_subprocess;
	short i_proc_date;
	short i_failreason_cd;
	short i_qty;
	short i_deal_frm_ord;
	short i_sub_fail_cd;
	short i_dateof_input;
}DL_ARCHDLAUDIT_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7

#define DL_INFORMATION_LEN 31


#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 2001
#define DL_MESSAGE_DET_C_LEN 2001
#define DL_MESSAGE_DET_D_LEN 2001
#define DL_MESSAGE_DET_E_LEN 2001
#define DL_PSETPARTY_LEN 161
#define DL_PLACE_CD_LEN 5
#define DL_NARRATIVE_LEN 41
typedef struct{
	char h_closing_date[APL_DATE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[DL_INFORMATION_LEN];
	int h_inden_num;
	int h_dl_rep_identno;
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
	char h_psetparty[DL_PSETPARTY_LEN];
	char h_place_cd[DL_PLACE_CD_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
}DL_ARCHMSGLINK_STRUCT_H;
typedef struct{
	short i_closing_date;
	short i_client;
	short i_identiy_no;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_date_of_input;
	short i_information;
	short i_inden_num;
	short i_dl_rep_identno;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_psetparty;
	short i_place_cd;
	short i_narrative;
}DL_ARCHMSGLINK_STRUCT_I;









#define DL_SEQUENCE_NAME_LEN 6
#define DL_LINK_VAL_LEN 6
#define DL_LINK_TAG_LEN 51


#define DL_MSG_TAG_LEN 6
typedef struct{
	char h_closing_date[APL_DATE_LEN];
	int h_inden_num;
	char h_sequence_name[DL_SEQUENCE_NAME_LEN];
	char h_link_val[DL_LINK_VAL_LEN];
	char h_link_tag[DL_LINK_TAG_LEN];
	int h_msg_tag_rep_no;
	int h_msg_line_no;
	char h_msg_tag[DL_MSG_TAG_LEN];
}DL_ARCHMSGLINKDET_STRUCT_H;
typedef struct{
	short i_closing_date;
	short i_inden_num;
	short i_sequence_name;
	short i_link_val;
	short i_link_tag;
	short i_msg_tag_rep_no;
	short i_msg_line_no;
	short i_msg_tag;
}DL_ARCHMSGLINKDET_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_REG_ST_CD_LEN 2







#define DL_STATUS_PRC_LEN 2



typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	char h_deal_dt[APL_DATE_LEN];
	double h_quantity;
	char h_access_stamp[APL_DATE_LEN];
	double h_moved_qty;
	double h_manifold_qty;
	char h_dt_client_for[APL_DATE_LEN];
	char h_prc_smr_date[APL_DATE_LEN];
	char h_status_prc[DL_STATUS_PRC_LEN];
	char h_prc_setl_date[APL_DATE_LEN];
	double h_amr_amount;
	char h_dateof_input[APL_DATE_LEN];
}DL_ARCHREGDET_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_reg_st_cd;
	short i_deal_dt;
	short i_quantity;
	short i_access_stamp;
	short i_moved_qty;
	short i_manifold_qty;
	short i_dt_client_for;
	short i_prc_smr_date;
	short i_status_prc;
	short i_prc_setl_date;
	short i_amr_amount;
	short i_dateof_input;
}DL_ARCHREGDET_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17




typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	int h_parent_srlno;
	double h_parent_qty;
	char h_dateof_input[APL_DATE_LEN];
}DL_ARCHREGPAR_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_parent_srlno;
	short i_parent_qty;
	short i_dateof_input;
}DL_ARCHREGPAR_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21


#define DL_DEAL_CD_LEN 2



typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_qty;
	double h_amount;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
}DL_ARCHRUHISDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_qty;
	short i_amount;
	short i_deal_cd;
	short i_deal_date;
	short i_instrument_dt;
	short i_dateof_input;
}DL_ARCHRUHISDEAL_STRUCT_I;







#define DL_INSTR_CODE_LEN 9

#define DL_LOCATION_CD_LEN 5
#define DL_CLIENT_LEN 11
#define DL_STATUS_POS_LEN 4






typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_posit_date[APL_DATE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	double h_start_safek;
	double h_safekeep_pos;
	double h_nvalreceive;
	double h_nvaldeliver;
	double h_val_rec;
	double h_val_del;
	double h_dp_rec;
	double h_dp_del;
	char   h_block_type[5];
}DL_ARCHSAFEK_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_posit_date;
	short i_location_cd;
	short i_client;
	short i_status_pos;
	short i_start_safek;
	short i_safekeep_pos;
	short i_nvalreceive;
	short i_nvaldeliver;
	short i_val_rec;
	short i_val_del;
   short i_dp_rec;
   short i_dp_del;
	short i_block_type;
}DL_ARCHSAFEK_STRUCT_I;







#define DL_TYPEOF_FILE_LEN 11
#define DL_FIELD_NAME_LEN 31


#define DL_INFOTYPE_LEN 2
typedef struct{
	char h_typeof_file[DL_TYPEOF_FILE_LEN];
	char h_field_name[DL_FIELD_NAME_LEN];
	int h_start_pos;
	int h_length;
	char h_infotype[DL_INFOTYPE_LEN];
}DL_AUTOSETTHUFMT_STRUCT_H;
typedef struct{
	short i_typeof_file;
	short i_field_name;
	short i_start_pos;
	short i_length;
	short i_infotype;
}DL_AUTOSETTHUFMT_STRUCT_I;







#define DL_CLASS_LEN 9


#define DL_MAIN_OUR_LEN 7
#define DL_DELNAME_LEN 37
#define DL_DET_LEN 4
#define DL_SUB_OUR_LEN 7
#define DL_SUB_SUBNAME_LEN 37
#define DL_INSTR_CODE_LEN 5
#define DL_SEC_NAME_LEN 16
#define DL_INSTR_SEQ_LEN 3

#define DL_INSTR_TEXT_LEN 2
#define DL_INSTR_ISIN_LEN 13

#define DL_DEALCODE_LEN 3
#define DL_DEALNAME_LEN 14
#define DL_IDENTIY_NO_LEN 7
#define DL_INFO_LEN 7
#define DL_MAIN_CP_LEN 7
#define DL_SUB_CP_LEN 7






#define DL_PARTNER_A_LEN 16

#define DL_OTHER_A_LEN 16
#define DL_PARTNER_B_LEN 16

#define DL_OTHER_B_LEN 16
#define DL_PARTNER_C_LEN 16

#define DL_OTHER_C_LEN 16
#define DL_INDICATOR_LEN 2
#define DL_REAS_LEN 101

#define DL_ACT_CLT_LEN 11
#define DL_ACT_IDENTITYNO_LEN 17


typedef struct{
	char h_class[DL_CLASS_LEN];
	char h_from_per[APL_DATE_LEN];
	char h_to_per[APL_DATE_LEN];
	char h_main_our[DL_MAIN_OUR_LEN];
	char h_delname[DL_DELNAME_LEN];
	char h_det[DL_DET_LEN];
	char h_sub_our[DL_SUB_OUR_LEN];
	char h_sub_subname[DL_SUB_SUBNAME_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_sec_name[DL_SEC_NAME_LEN];
	char h_instr_seq[DL_INSTR_SEQ_LEN];
	int h_typeofinstr;
	char h_instr_text[DL_INSTR_TEXT_LEN];
	char h_instr_isin[DL_INSTR_ISIN_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_dealcode[DL_DEALCODE_LEN];
	char h_dealname[DL_DEALNAME_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_info[DL_INFO_LEN];
	char h_main_cp[DL_MAIN_CP_LEN];
	char h_sub_cp[DL_SUB_CP_LEN];
	int h_quantity_received;
	int h_quantity_del;
	int h_deal_in;
	int h_deal_out;
	int h_otc_pos;
	int h_nominal_value;
	char h_partner_a[DL_PARTNER_A_LEN];
	int h_quantity_a;
	char h_other_a[DL_OTHER_A_LEN];
	char h_partner_b[DL_PARTNER_B_LEN];
	int h_quantity_b;
	char h_other_b[DL_OTHER_B_LEN];
	char h_partner_c[DL_PARTNER_C_LEN];
	int h_quantity_c;
	char h_other_c[DL_OTHER_C_LEN];
	char h_indicator[DL_INDICATOR_LEN];
	char h_reas[DL_REAS_LEN];
	int h_mismatch;
	char h_act_clt[DL_ACT_CLT_LEN];
	char h_act_identityno[DL_ACT_IDENTITYNO_LEN];
	int h_rec_no;
	int h_iden_no;
}DL_AUTOSETTHUWRK_STRUCT_H;
typedef struct{
	short i_class;
	short i_from_per;
	short i_to_per;
	short i_main_our;
	short i_delname;
	short i_det;
	short i_sub_our;
	short i_sub_subname;
	short i_instr_code;
	short i_sec_name;
	short i_instr_seq;
	short i_typeofinstr;
	short i_instr_text;
	short i_instr_isin;
	short i_processed_date;
	short i_dealcode;
	short i_dealname;
	short i_identiy_no;
	short i_info;
	short i_main_cp;
	short i_sub_cp;
	short i_quantity_received;
	short i_quantity_del;
	short i_deal_in;
	short i_deal_out;
	short i_otc_pos;
	short i_nominal_value;
	short i_partner_a;
	short i_quantity_a;
	short i_other_a;
	short i_partner_b;
	short i_quantity_b;
	short i_other_b;
	short i_partner_c;
	short i_quantity_c;
	short i_other_c;
	short i_indicator;
	short i_reas;
	short i_mismatch;
	short i_act_clt;
	short i_act_identityno;
	short i_rec_no;
	short i_iden_no;
}DL_AUTOSETTHUWRK_STRUCT_I;







#define DL_GL_CLT_LEN 11

typedef struct{
	char h_gl_clt[DL_GL_CLT_LEN];
	double h_cash_bal;
}DL_CASHBAL_STRUCT_H;
typedef struct{
	short i_gl_clt;
	short i_cash_bal;
}DL_CASHBAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_CURRENCY_CD_LEN 4
#define DL_GL_ACCOUNT_LEN 11
#define DL_DEFAULT_CCY_LEN 2
#define DL_IBAN_CLT_LEN 31
#define DL_ADDITION_ACC_LEN 31
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_gl_account[DL_GL_ACCOUNT_LEN];
	char h_default_ccy[DL_DEFAULT_CCY_LEN];
	char h_iban_clt[DL_IBAN_CLT_LEN];
	char h_addition_acc[DL_ADDITION_ACC_LEN];
}DL_CASHCLT_STRUCT_H;
typedef struct{
	short i_client;
	short i_currency_cd;
	short i_gl_account;
	short i_default_ccy;
	short i_iban_clt;
	short i_addition_acc;
}DL_CASHCLT_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_REAS_LEN 4001
#define DL_REPORT_IND_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_report_dt[APL_DATE_LEN];
	char h_reas[DL_REAS_LEN];
	char h_report_ind[DL_REPORT_IND_LEN];
}DL_CCSFAILMSG_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_report_dt;
	short i_reas;
	short i_report_ind;
}DL_CCSFAILMSG_STRUCT_I;







#define DL_MSG_CLASS_LEN 3
#define DL_IDENTITY_LEN 12
#define DL_TLC_DEAL_TYPE_LEN 2
#define DL_DEAL_CODE_LEN 3
#define DL_CLIENT_LEN 11
#define DL_MASTER_CLT_LEN 11
#define DL_CLNT_IDENT_LEN 17
#define DL_BRK_LEN 11
#define DL_INSTR_CODE_LEN 9

#define DL_CURRENCY_CD_LEN 4

#define DL_SIGNATURE_LEN 2




#define DL_LOCATION_CD_LEN 5
#define DL_MKRT_DL_CLASS_LEN 3
#define DL_CP_CLT_LEN 11
#define DL_FAILREASON_CD_LEN 3

#define DL_FAIL_DET_LEN 71

#define DL_NARRATIVE_LEN 211



#define DL_STATUS_IND_LEN 2

typedef struct{
	char h_msg_class[DL_MSG_CLASS_LEN];
	char h_identity[DL_IDENTITY_LEN];
	char h_tlc_deal_type[DL_TLC_DEAL_TYPE_LEN];
	char h_deal_code[DL_DEAL_CODE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_master_clt[DL_MASTER_CLT_LEN];
	char h_clnt_ident[DL_CLNT_IDENT_LEN];
	char h_brk[DL_BRK_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	double h_qty;
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	int h_amt;
	char h_signature[DL_SIGNATURE_LEN];
	int h_gl_clt;
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_exp_setldate[APL_DATE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_mkrt_dl_class[DL_MKRT_DL_CLASS_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	int h_sub_fail_cd;
	char h_fail_det[DL_FAIL_DET_LEN];
	int h_failreason_index;
	char h_narrative[DL_NARRATIVE_LEN];
	char h_actual_setldt[APL_DATE_LEN];
	char h_processdt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_ind[DL_STATUS_IND_LEN];
	int h_iden_no;
}DL_CCSPENDTXN_STRUCT_H;
typedef struct{
	short i_msg_class;
	short i_identity;
	short i_tlc_deal_type;
	short i_deal_code;
	short i_client;
	short i_master_clt;
	short i_clnt_ident;
	short i_brk;
	short i_instr_code;
	short i_qty;
	short i_currency_cd;
	short i_amt;
	short i_signature;
	short i_gl_clt;
	short i_deal_date;
	short i_setl_date;
	short i_exp_setldate;
	short i_location_cd;
	short i_mkrt_dl_class;
	short i_cp_clt;
	short i_failreason_cd;
	short i_sub_fail_cd;
	short i_fail_det;
	short i_failreason_index;
	short i_narrative;
	short i_actual_setldt;
	short i_processdt;
	short i_access_stamp;
	short i_status_ind;
	short i_iden_no;
}DL_CCSPENDTXN_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_REC_DEL_LEN 2


#define DL_ACT_DVP_LEN 2
#define DL_DL_CLASS_LEN 2
#define DL_CP_CLT_LEN 12
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_rec_del[DL_REC_DEL_LEN];
	double h_qty;
	double h_amount;
	char h_act_dvp[DL_ACT_DVP_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
}DL_CLHTR_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_rec_del;
	short i_qty;
	short i_amount;
	short i_act_dvp;
	short i_dl_class;
	short i_cp_clt;
}DL_CLHTR_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3






























#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
	double h_comm_amt;/**** For Detailed bill Printing : vinay kalaskar ***/
	char h_mf_seqno[MF_SEQNO_LEN];/**** For BillGeneration : vinay kalaskar ***/
}DL_COPYHISTORY_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
	short i_comm_amt;/**** For Detailed Bill Printing : vinay kalaskar ***/
	short i_mf_seqno;/**** For BillGeneration : vinay kalaskar ***/
}DL_COPYHISTORY_STRUCT_I;







#define DL_CURRENCY_CD_LEN 4
#define DL_CURRENCY_DESC_LEN 41
#define DL_MAKER_LEN 15



#define DL_GL_CD_LEN 4
typedef struct{
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_currency_desc[DL_CURRENCY_DESC_LEN];
	char h_maker[DL_MAKER_LEN];
	int h_dec_len;
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_gl_cd[DL_GL_CD_LEN];
}DL_CURRENCY_STRUCT_H;
typedef struct{
	short i_currency_cd;
	short i_currency_desc;
	short i_maker;
	short i_dec_len;
	short i_maker_dt;
	short i_access_stamp;
	short i_gl_cd;
}DL_CURRENCY_STRUCT_I;







#define DL_CURRENCY_CD_LEN 4
#define DL_CURRENCY_DESC_LEN 41
#define DL_MAKER_LEN 15



#define DL_GL_CD_LEN 4
typedef struct{
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_currency_desc[DL_CURRENCY_DESC_LEN];
	char h_maker[DL_MAKER_LEN];
	int h_dec_len;
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_gl_cd[DL_GL_CD_LEN];
}DL_CURRENCY_VEW_STRUCT_H;
typedef struct{
	short i_currency_cd;
	short i_currency_desc;
	short i_maker;
	short i_dec_len;
	short i_maker_dt;
	short i_access_stamp;
	short i_gl_cd;
}DL_CURRENCY_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3






























#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
}DL_DEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
	/*Retro from HDFC by Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
}DL_DEAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_TRAIL_FOR_LEN 2
#define DL_TASK_DESC_LEN 61
#define DL_PROC_USR_LEN 15
#define DL_SUBPROCESS_LEN 4

#define DL_FAILREASON_CD_LEN 3

#define DL_DEAL_FRM_ORD_LEN 2

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_trail_for[DL_TRAIL_FOR_LEN];
	char h_task_desc[DL_TASK_DESC_LEN];
	char h_proc_usr[DL_PROC_USR_LEN];
	char h_subprocess[DL_SUBPROCESS_LEN];
	char h_proc_date[APL_DATE_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	double h_qty;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	int h_sub_fail_cd;
}DL_DEALAUDIT_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_trail_for;
	short i_task_desc;
	short i_proc_usr;
	short i_subprocess;
	short i_proc_date;
	short i_failreason_cd;
	short i_qty;
	short i_deal_frm_ord;
	short i_sub_fail_cd;
}DL_DEALAUDIT_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_CD_LEN 2


#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4

#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_EX_ARENA_LEN 3



#define DL_DOMCP_CUSTODYGL_LEN 11
#define DL_CLT_GL_LEN 11

#define DL_TYPEOF_ENT_LEN 2






typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	double h_amount;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_host_date[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	char h_domcp_custodygl[DL_DOMCP_CUSTODYGL_LEN];
	char h_clt_gl[DL_CLT_GL_LEN];
	char h_valuedt[APL_DATE_LEN];
	char h_typeof_ent[DL_TYPEOF_ENT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	int h_procnum;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
}DL_DEALCLIENTIMG_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_cd;
	short i_deal_date;
	short i_setl_date;
	short i_instr_code;
	short i_currency_cd;
	short i_amount;
	short i_domestic_cpclt;
	short i_domcp_custodyclt;
	short i_ex_arena;
	short i_dateof_input;
	short i_host_date;
	short i_money_setl_dt;
	short i_domcp_custodygl;
	short i_clt_gl;
	short i_valuedt;
	short i_typeof_ent;
	short i_access_stamp;
	short i_procnum;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
}DL_DEALCLIENTIMG_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_FLAG_LEN 5
#define DL_STAT_DET_LEN 41
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_reportdt[APL_DATE_LEN];
	char h_flag[DL_FLAG_LEN];
	char h_stat_det[DL_STAT_DET_LEN];
}DL_DEALDET_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_reportdt;
	short i_flag;
	short i_stat_det;
}DL_DEALDET_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_CD_LEN 2



#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_DL_CLASS_LEN 3

#define DL_EX_ARENA_LEN 3
#define DL_SPOTTRD_IND_LEN 2
#define DL_ENTRY_LEN 2

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3


#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_INFO1_LEN 261
#define DL_FX_REQD_LEN 2




#define DL_LOCATION_CD_LEN 5
#define DL_STATUS_POS_LEN 4
#define DL_INSTR_NAME_LEN 121
#define DL_CLT_NAME_LEN 66
#define DL_DOMESTICCP_NAME_LEN 66
#define DL_BRK_NO_LEN 13
#define DL_GL_CLIENT_LEN 11
#define DL_PARTIAL_IND_A_LEN 2
#define DL_INSTRUCT_PERSON_LEN 36
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_LCL_IDENTNO_LEN 17
#define DL_UNIQ_IDENT_NO_LEN 15
#define DL_RELATED_IDENT_NO_LEN 21

typedef struct{
	int h_dl_rep_identno;
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_qty;
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_amount;
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_instr_name[DL_INSTR_NAME_LEN];
	char h_clt_name[DL_CLT_NAME_LEN];
	char h_domesticcp_name[DL_DOMESTICCP_NAME_LEN];
	char h_brk_no[DL_BRK_NO_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_del_rec_date[APL_DATE_LEN];
}DL_DEALREPAIR_STRUCT_H;
typedef struct{
	short i_dl_rep_identno;
	short i_client;
	short i_identiy_no;
	short i_deal_cd;
	short i_deal_date;
	short i_setl_date;
	short i_qty;
	short i_instr_code;
	short i_currency_cd;
	short i_domestic_cpclt;
	short i_dl_class;
	short i_cost;
	short i_ex_arena;
	short i_spottrd_ind;
	short i_entry;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_amount;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_info1;
	short i_fx_reqd;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_location_cd;
	short i_status_pos;
	short i_instr_name;
	short i_clt_name;
	short i_domesticcp_name;
	short i_brk_no;
	short i_gl_client;
	short i_partial_ind_a;
	short i_instruct_person;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_lcl_identno;
	short i_uniq_ident_no;
	short i_related_ident_no;
	short i_del_rec_date;
}DL_DEALREPAIR_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_INSTR_CODE_LEN 9


#define DL_DL_CLASS_LEN 3
#define DL_DEAL_CD_LEN 2
#define DL_ORIG_REFNO_LEN 17
#define DL_LCL_IDENTNO_LEN 17
#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66


#define DL_PARTIAL_IND_B_LEN 2


#define DL_FAILREASON_CD_LEN 3
#define DL_ENTRY_LEN 2

#define DL_MSG_STAT_LEN 51
#define DL_CLIENTOF_LEN 66
#define DL_INSTRUCT_PERSON_LEN 36
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_MOD_HISPOS_IND_LEN 2
#define DL_LOCATION_CD_LEN 5
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	double h_amount;
	char h_instr_code[DL_INSTR_CODE_LEN];
	double h_qty;
	char h_setl_date[APL_DATE_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_orig_qty;
	char h_deal_date[APL_DATE_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reset_dt[APL_DATE_LEN];
	char h_msg_stat[DL_MSG_STAT_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
}DL_DEALRST_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_amount;
	short i_instr_code;
	short i_qty;
	short i_setl_date;
	short i_dl_class;
	short i_deal_cd;
	short i_orig_refno;
	short i_lcl_identno;
	short i_domestic_cpclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_partial_ind_b;
	short i_orig_qty;
	short i_deal_date;
	short i_failreason_cd;
	short i_entry;
	short i_reset_dt;
	short i_msg_stat;
	short i_clientof;
	short i_instruct_person;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_mod_hispos_ind;
	short i_location_cd;
}DL_DEALRST_STRUCT_I;







#define DL_DEPO_LOC_LEN 5
#define DL_DEPO_DET_LEN 13
#define DL_OMNIBUS_CLIENT_LEN 11
#define DL_IND_54X_LEN 3
#define DL_VP_IND_LEN 2
#define DL_DEAL_537IND_LEN 2
#define DL_DEAL_548IND_LEN 2
#define DL_VAL_UNIQUE_IDENTITY_LEN 2
typedef struct{
	char h_depo_loc[DL_DEPO_LOC_LEN];
	char h_depo_det[DL_DEPO_DET_LEN];
	char h_omnibus_client[DL_OMNIBUS_CLIENT_LEN];
	char h_ind_54x[DL_IND_54X_LEN];
	char h_vp_ind[DL_VP_IND_LEN];
	char h_deal_537ind[DL_DEAL_537IND_LEN];
	char h_deal_548ind[DL_DEAL_548IND_LEN];
	char h_val_unique_identity[DL_VAL_UNIQUE_IDENTITY_LEN];
}DL_DEPOPROCESSING_STRUCT_H;
typedef struct{
	short i_depo_loc;
	short i_depo_det;
	short i_omnibus_client;
	short i_ind_54x;
	short i_vp_ind;
	short i_deal_537ind;
	short i_deal_548ind;
	short i_val_unique_identity;
}DL_DEPOPROCESSING_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3






























#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
}DL_EOMDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
}DL_EOMDEAL_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_CLIENT_LEN 11

#define DL_STATUS_POS_LEN 4






typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	double h_start_safek;
	double h_safekeep_pos;
	double h_nvalreceive;
	double h_nvaldeliver;
	double h_val_rec;
	double h_val_del;
   double h_dp_rec;
   double h_dp_del;
	 char   h_block_type[5];
}DL_EOMSAFEK_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_location_cd;
	short i_client;
	short i_access_stamp;
	short i_status_pos;
	short i_start_safek;
	short i_safekeep_pos;
	short i_nvalreceive;
	short i_nvaldeliver;
	short i_val_rec;
	short i_val_del;
   short i_dp_rec;
	short i_dp_del;
	short i_block_type;
}DL_EOMSAFEK_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_CD_LEN 2






#define DL_EX_ARENA_LEN 3
#define DL_REPORT_AT_EOM_IND_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	double h_amount;
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
}DL_EOMSTM_ADJ_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_identiy_no;
	short i_deal_cd;
	short i_deal_date;
	short i_setl_date;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_amount;
	short i_ex_arena;
	short i_report_at_eom_ind;
}DL_EOMSTM_ADJ_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_CD_LEN 2






#define DL_EX_ARENA_LEN 3
#define DL_REPORT_AT_EOM_IND_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	double h_amount;
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
}DL_EOMSTM_CURR_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_identiy_no;
	short i_deal_cd;
	short i_deal_date;
	short i_setl_date;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_amount;
	short i_ex_arena;
	short i_report_at_eom_ind;
}DL_EOMSTM_CURR_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_IDENTIY_NO_LEN 17


#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_FAILREASON_CD_LEN 3
#define DL_EX_ARENA_LEN 3

#define DL_DEAL_CD_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	double h_qty;
	double h_amount;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
}DL_EOMSTM_FAIL_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_identiy_no;
	short i_qty;
	short i_amount;
	short i_domestic_cpclt;
	short i_failreason_cd;
	short i_ex_arena;
	short i_setl_date;
	short i_deal_cd;
}DL_EOMSTM_FAIL_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_IDENTIY_NO_LEN 17


#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_EX_ARENA_LEN 3

#define DL_DEAL_CD_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	double h_qty;
	double h_amount;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
}DL_EOMSTM_PEND_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_identiy_no;
	short i_qty;
	short i_amount;
	short i_domestic_cpclt;
	short i_ex_arena;
	short i_setl_date;
	short i_deal_cd;
}DL_EOMSTM_PEND_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_STATUS_POS_LEN 4


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	int h_vdp_pos;
	char h_vdp_date[APL_DATE_LEN];
}DL_FUTURE_VDP_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_status_pos;
	short i_vdp_pos;
	short i_vdp_date;
}DL_FUTURE_VDP_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3






























#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
#define DL_CLNT_NAME_LEN 130 
#define DL_DOMESTIC_CPNAME_LEN 66
#define DL_DOMCP_CUSTODYNM_LEN 66
#define DL_INSTR_NAME_LEN 131

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
	double h_comm_amt;/**** For Detailed Bill Printing : vinay kalaskar ***/
	char h_mf_seqno[MF_SEQNO_LEN];/**** For BillGeneration : vinay kalaskar ***/
	char h_clnt_name[DL_CLNT_NAME_LEN];
	char h_domestic_cpname[DL_DOMESTIC_CPNAME_LEN];
	char h_domcp_custodynm[DL_DOMCP_CUSTODYNM_LEN];
	char h_instr_name[DL_INSTR_NAME_LEN];
	char h_closing_date[APL_DATE_LEN];
}DL_HISDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
	short i_comm_amt;/**** For Detailed Bill Printing : vinay kalaskar ***/
	short i_mf_seqno;/**** For BillGeneration : vinay kalaskar ***/
	short i_clnt_name;
	short i_domestic_cpname;
	short i_domcp_custodynm;
	short i_instr_name;
	short i_closing_date;
}DL_HISDEAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_TRAIL_FOR_LEN 2
#define DL_TASK_DESC_LEN 61
#define DL_PROC_USR_LEN 15
#define DL_SUBPROCESS_LEN 4

#define DL_FAILREASON_CD_LEN 3

#define DL_DEAL_FRM_ORD_LEN 2


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_trail_for[DL_TRAIL_FOR_LEN];
	char h_task_desc[DL_TASK_DESC_LEN];
	char h_proc_usr[DL_PROC_USR_LEN];
	char h_subprocess[DL_SUBPROCESS_LEN];
	char h_proc_date[APL_DATE_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	double h_qty;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	int h_sub_fail_cd;
	char h_dateof_input[APL_DATE_LEN];
}DL_HISDEALSAUDIT_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_trail_for;
	short i_task_desc;
	short i_proc_usr;
	short i_subprocess;
	short i_proc_date;
	short i_failreason_cd;
	short i_qty;
	short i_deal_frm_ord;
	short i_sub_fail_cd;
	short i_dateof_input;
}DL_HISDEALSAUDIT_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9


#define DL_DEAL_STAT_LEN 3

#define DL_DEAL_CD_LEN 2

#define DL_CURRENCY_CD_LEN 4
#define DL_LCL_IDENTNO_LEN 17

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	double h_qty;
	char h_deal_cd[DL_DEAL_CD_LEN];
	double h_amount;
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_setl_date[APL_DATE_LEN];
}DL_HISDEAL_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_deal_date;
	short i_instrument_dt;
	short i_deal_stat;
	short i_qty;
	short i_deal_cd;
	short i_amount;
	short i_currency_cd;
	short i_lcl_identno;
	short i_setl_date;
}DL_HISDEAL_VEW_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7

#define DL_INFORMATION_LEN 31


#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 2001
#define DL_MESSAGE_DET_C_LEN 2001
#define DL_MESSAGE_DET_D_LEN 2001
#define DL_MESSAGE_DET_E_LEN 2001
#define DL_PSETPARTY_LEN 161
#define DL_PLACE_CD_LEN 5
#define DL_NARRATIVE_LEN 41
typedef struct{
	char h_closing_date[APL_DATE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[DL_INFORMATION_LEN];
	int h_inden_num;
	int h_dl_rep_identno;
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
	char h_psetparty[DL_PSETPARTY_LEN];
	char h_place_cd[DL_PLACE_CD_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
}DL_HISMSGLINK_STRUCT_H;
typedef struct{
	short i_closing_date;
	short i_client;
	short i_identiy_no;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_date_of_input;
	short i_information;
	short i_inden_num;
	short i_dl_rep_identno;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_psetparty;
	short i_place_cd;
	short i_narrative;
}DL_HISMSGLINK_STRUCT_I;









#define DL_SEQUENCE_NAME_LEN 6
#define DL_LINK_VAL_LEN 6
#define DL_LINK_TAG_LEN 51


#define DL_MSG_TAG_LEN 6
typedef struct{
	char h_closing_date[APL_DATE_LEN];
	int h_inden_num;
	char h_sequence_name[DL_SEQUENCE_NAME_LEN];
	char h_link_val[DL_LINK_VAL_LEN];
	char h_link_tag[DL_LINK_TAG_LEN];
	int h_msg_tag_rep_no;
	int h_msg_line_no;
	char h_msg_tag[DL_MSG_TAG_LEN];
}DL_HISMSGLINKDET_STRUCT_H;
typedef struct{
	short i_closing_date;
	short i_inden_num;
	short i_sequence_name;
	short i_link_val;
	short i_link_tag;
	short i_msg_tag_rep_no;
	short i_msg_line_no;
	short i_msg_tag;
}DL_HISMSGLINKDET_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_STAT_QUAL_LEN 5
#define DL_STATUS_CD_LEN 7
#define DL_REASON_QL_LEN 7
#define DL_REASON_CD_LEN 5
#define DL_INFO_LEN 36
#define DL_FAILREASON_CD_LEN 3


typedef struct{
	char h_closing_date[APL_DATE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_stat_blckno;
	char h_stat_qual[DL_STAT_QUAL_LEN];
	char h_status_cd[DL_STATUS_CD_LEN];
	char h_reason_ql[DL_REASON_QL_LEN];
	char h_reason_cd[DL_REASON_CD_LEN];
	char h_info[DL_INFO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	int h_sub_fail_cd;
	char h_access_stamp[APL_DATE_LEN];
}DL_HISMULT_REAS_CODES_STRUCT_H;
typedef struct{
	short i_closing_date;
	short i_client;
	short i_identiy_no;
	short i_stat_blckno;
	short i_stat_qual;
	short i_status_cd;
	short i_reason_ql;
	short i_reason_cd;
	short i_info;
	short i_failreason_cd;
	short i_sub_fail_cd;
	short i_access_stamp;
}DL_HISMULT_REAS_CODES_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_REG_ST_CD_LEN 2







#define DL_STATUS_PRC_LEN 2



typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	char h_deal_dt[APL_DATE_LEN];
	double h_quantity;
	char h_access_stamp[APL_DATE_LEN];
	double h_moved_qty;
	double h_manifold_qty;
	char h_dt_client_for[APL_DATE_LEN];
	char h_prc_smr_date[APL_DATE_LEN];
	char h_status_prc[DL_STATUS_PRC_LEN];
	char h_prc_setl_date[APL_DATE_LEN];
	double h_amr_amount;
	char h_dateof_input[APL_DATE_LEN];
}DL_HISREGDET_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_reg_st_cd;
	short i_deal_dt;
	short i_quantity;
	short i_access_stamp;
	short i_moved_qty;
	short i_manifold_qty;
	short i_dt_client_for;
	short i_prc_smr_date;
	short i_status_prc;
	short i_prc_setl_date;
	short i_amr_amount;
	short i_dateof_input;
}DL_HISREGDET_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17




typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	int h_parent_srlno;
	double h_parent_qty;
	char h_dateof_input[APL_DATE_LEN];
}DL_HISREGPAR_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_parent_srlno;
	short i_parent_qty;
	short i_dateof_input;
}DL_HISREGPAR_STRUCT_I;












/*
typedef struct{
	
	
	
	
	
	
}DL_HISREPIRE_VEW_STRUCT_H;
*/
typedef struct{
	short i_posit_date;
	short i_instr_code;
	short i_loc_valt;
	short i_depo_loc;
	short i_for_valt;
	short i_for_depo;
}DL_HISREPIRE_VEW_STRUCT_I;







#define DL_INSTR_CODE_LEN 9

#define DL_LOCATION_CD_LEN 5
#define DL_CLIENT_LEN 11
#define DL_STATUS_POS_LEN 4






typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_posit_date[APL_DATE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	double h_start_safek;
	double h_safekeep_pos;
	double h_nvalreceive;
	double h_nvaldeliver;
	double h_val_rec;
	double h_val_del;
  double h_dp_rec;
   double h_dp_del;
	 char   h_block_type[5];
}DL_HISSAFEK_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_posit_date;
	short i_location_cd;
	short i_client;
	short i_status_pos;
	short i_start_safek;
	short i_safekeep_pos;
	short i_nvalreceive;
	short i_nvaldeliver;
	short i_val_rec;
	short i_val_del;
   short i_dp_rec;
   short i_dp_del;
	short i_block_type;
}DL_HISSAFEK_STRUCT_I;







#define DL_OLD_INSTR_CODE_LEN 9
#define DL_NEW_SECCD_LEN 9

#define DL_MAKER_LEN 15
#define DL_CHECKER_LEN 15
typedef struct{
	char h_old_instr_code[DL_OLD_INSTR_CODE_LEN];
	char h_new_seccd[DL_NEW_SECCD_LEN];
	char h_frm_date[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_checker[DL_CHECKER_LEN];
}DL_INSTRUMENTCHG_STRUCT_H;
typedef struct{
	short i_old_instr_code;
	short i_new_seccd;
	short i_frm_date;
	short i_maker;
	short i_checker;
}DL_INSTRUMENTCHG_STRUCT_I;







#define DL_FRM_INSTR_CODE_LEN 9
#define DL_CLIENT_LEN 11
#define DL_TO_SECURITY_LEN 9

typedef struct{
	char h_frm_instr_code[DL_FRM_INSTR_CODE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_to_security[DL_TO_SECURITY_LEN];
	char h_chng_dt[APL_DATE_LEN];
}DL_INSTRUMENTCONV_STRUCT_H;
typedef struct{
	short i_frm_instr_code;
	short i_client;
	short i_to_security;
	short i_chng_dt;
}DL_INSTRUMENTCONV_STRUCT_I;







#define DL_IDENTIY_NO_LEN 17
#define DL_CLIENT_LEN 11
#define DL_DEAL_TYPE_LEN 3
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5

typedef struct{
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_deal_type[DL_DEAL_TYPE_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	double h_qty;
}DL_INSTRUMENTCONV_REP_TEMP_STRUCT_H;
typedef struct{
	short i_identiy_no;
	short i_client;
	short i_deal_type;
	short i_instr_code;
	short i_location_cd;
	short i_qty;
}DL_INSTRUMENTCONV_REP_TEMP_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ORD_REFNO_LEN 17
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_ord_refno[DL_ORD_REFNO_LEN];
}DL_INSTRUMENTCONV_TEMP_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_ord_refno;
}DL_INSTRUMENTCONV_TEMP_STRUCT_I;







#define DL_NAMEOF_FILE_LEN 41

#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_STATUS_IND_LEN 3

#define DL_INFO_LEN 101
typedef struct{
	char h_nameof_file[DL_NAMEOF_FILE_LEN];
	int h_srlnum;
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_status_ind[DL_STATUS_IND_LEN];
	char h_uplddate[APL_DATE_LEN];
	char h_info[DL_INFO_LEN];
}DL_IPOAUDIT_STRUCT_H;
typedef struct{
	short i_nameof_file;
	short i_srlnum;
	short i_client;
	short i_identiy_no;
	short i_status_ind;
	short i_uplddate;
	short i_info;
}DL_IPOAUDIT_STRUCT_I;







#define DL_CREDIT_CLT_LEN 4
#define DL_LR_DET_LEN 46
#define DL_CLT_TYPE_LEN 3
#define DL_CLIENT_OWN_LEN 4
#define DL_FLAG_LEN 2
#define DL_OWN_IND_LEN 2
typedef struct{
	char h_credit_clt[DL_CREDIT_CLT_LEN];
	char h_lr_det[DL_LR_DET_LEN];
	char h_clt_type[DL_CLT_TYPE_LEN];
	char h_client_own[DL_CLIENT_OWN_LEN];
	char h_flag[DL_FLAG_LEN];
	char h_own_ind[DL_OWN_IND_LEN];
}DL_LOCALREPCLIENT_STRUCT_H;
typedef struct{
	short i_credit_clt;
	short i_lr_det;
	short i_clt_type;
	short i_client_own;
	short i_flag;
	short i_own_ind;
}DL_LOCALREPCLIENT_STRUCT_I;







#define DL_CREDIT_CLT_LEN 5
#define DL_LR_DET_LEN 46
#define DL_CLT_TYPE_LEN 3
#define DL_CLIENT_OWN_LEN 4
#define DL_FLAG_LEN 2
#define DL_OWN_IND_LEN 2
typedef struct{
	char h_credit_clt[DL_CREDIT_CLT_LEN];
	char h_lr_det[DL_LR_DET_LEN];
	char h_clt_type[DL_CLT_TYPE_LEN];
	char h_client_own[DL_CLIENT_OWN_LEN];
	char h_flag[DL_FLAG_LEN];
	char h_own_ind[DL_OWN_IND_LEN];
}DL_LOCALREPCLIENTMA_STRUCT_H;
typedef struct{
	short i_credit_clt;
	short i_lr_det;
	short i_clt_type;
	short i_client_own;
	short i_flag;
	short i_own_ind;
}DL_LOCALREPCLIENTMA_STRUCT_I;









#define DL_INFO_LEN 66
typedef struct{
	int h_clr_name;
	char h_lr_dt[APL_DATE_LEN];
	char h_info[DL_INFO_LEN];
}DL_LOCALREPDATES_STRUCT_H;
typedef struct{
	short i_clr_name;
	short i_lr_dt;
	short i_info;
}DL_LOCALREPDATES_STRUCT_I;







#define DL_DEAL_CLASS_LEN 3
#define DL_DEAL_DET_LEN 36
#define DL_NDS_BLK_LEN 2
#define DL_NDS_IND_LEN 2
#define DL_DEAL_CD_MTX_LEN 5
#define DL_CLTTYPE_LEN 4
#define DL_BLOCK_LEN 2
#define DL_NEW_LEN 2
#define DL_CLT_BRK_ALL_LEN 2
#define DL_DEAL_CLASS_CD_LEN 5
typedef struct{
	char h_deal_class[DL_DEAL_CLASS_LEN];
	char h_deal_det[DL_DEAL_DET_LEN];
	char h_nds_blk[DL_NDS_BLK_LEN];
	char h_nds_ind[DL_NDS_IND_LEN];
	char h_deal_cd_mtx[DL_DEAL_CD_MTX_LEN];
	char h_clttype[DL_CLTTYPE_LEN];
	char h_block[DL_BLOCK_LEN];
	char h_new[DL_NEW_LEN];
	char h_clt_brk_all[DL_CLT_BRK_ALL_LEN];
	char h_deal_class_cd[DL_DEAL_CLASS_CD_LEN];
}DL_LOCALREPDEALTYPE_STRUCT_H;
typedef struct{
	short i_deal_class;
	short i_deal_det;
	short i_nds_blk;
	short i_nds_ind;
	short i_deal_cd_mtx;
	short i_clttype;
	short i_block;
	short i_new;
	short i_clt_brk_all;
	short i_deal_class_cd;
}DL_LOCALREPDEALTYPE_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_CREDITCLIENT_LEN 4
#define DL_DEBIT_CLT_LEN 4
#define DL_DOMESTIC_CPCLT_LEN 11



#define DL_ORD_IND_LEN 2
#define DL_LR_DL_CLASS_LEN 3
#define DL_DEAL_CD_LEN 2
#define DL_RESET_IND_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_creditclient[DL_CREDITCLIENT_LEN];
	char h_debit_clt[DL_DEBIT_CLT_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	double h_qty;
	int h_dt_field;
	int h_r_code;
	char h_ord_ind[DL_ORD_IND_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_reset_ind[DL_RESET_IND_LEN];
}DL_LOCALREPPROC_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_creditclient;
	short i_debit_clt;
	short i_domestic_cpclt;
	short i_qty;
	short i_dt_field;
	short i_r_code;
	short i_ord_ind;
	short i_lr_dl_class;
	short i_deal_cd;
	short i_reset_ind;
}DL_LOCALREPPROC_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_CREDITCLIENT_LEN 4
#define DL_CLIENT_LEN 11

#define DL_DOMESTIC_CPCLT_LEN 11
typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_creditclient[DL_CREDITCLIENT_LEN];
	char h_client[DL_CLIENT_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
}DL_LOCALREPPROC2_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_creditclient;
	short i_client;
	short i_qty;
	short i_domestic_cpclt;
}DL_LOCALREPPROC2_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_CREDITCLIENT_LEN 14

#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_INSTR_ISIN_LEN 13
typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_creditclient[DL_CREDITCLIENT_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_instr_isin[DL_INSTR_ISIN_LEN];
}DL_LOCALREPPROC3_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_creditclient;
	short i_qty;
	short i_domestic_cpclt;
	short i_instr_isin;
}DL_LOCALREPPROC3_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_CREDITCLIENT_LEN 5
#define DL_DEBIT_CLT_LEN 5
#define DL_DOMESTIC_CPCLT_LEN 11



#define DL_ORD_IND_LEN 2
#define DL_LR_DL_CLASS_LEN 3
#define DL_DEAL_CD_LEN 2
#define DL_RESET_IND_LEN 2
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_creditclient[DL_CREDITCLIENT_LEN];
	char h_debit_clt[DL_DEBIT_CLT_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	double h_qty;
	int h_dt_field;
	int h_r_code;
	char h_ord_ind[DL_ORD_IND_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_reset_ind[DL_RESET_IND_LEN];
}DL_LOCALREPROCMA_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_creditclient;
	short i_debit_clt;
	short i_domestic_cpclt;
	short i_qty;
	short i_dt_field;
	short i_r_code;
	short i_ord_ind;
	short i_lr_dl_class;
	short i_deal_cd;
	short i_reset_ind;
}DL_LOCALREPROCMA_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_CREDIT_CLT_LEN 4
#define DL_CLIENT_LEN 11


#define DL_DOMESTIC_CPCLT_LEN 11

typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_credit_clt[DL_CREDIT_CLT_LEN];
	char h_client[DL_CLIENT_LEN];
	double h_openbalance;
	double h_closing_bal;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_last_instr_date[APL_DATE_LEN];
}DL_LOCALREPSAFEK_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_credit_clt;
	short i_client;
	short i_openbalance;
	short i_closing_bal;
	short i_domestic_cpclt;
	short i_last_instr_date;
}DL_LOCALREPSAFEK_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_CREDIT_CLT_LEN 5
#define DL_CLIENT_LEN 11


#define DL_DOMESTIC_CPCLT_LEN 11

typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_credit_clt[DL_CREDIT_CLT_LEN];
	char h_client[DL_CLIENT_LEN];
	double h_openbalance;
	double h_closing_bal;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_last_instr_date[APL_DATE_LEN];
}DL_LOCALREPSAFEKMA_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_credit_clt;
	short i_client;
	short i_openbalance;
	short i_closing_bal;
	short i_domestic_cpclt;
	short i_last_instr_date;
}DL_LOCALREPSAFEKMA_STRUCT_I;







#define DL_DEALCLASS_LEN 3
#define DL_DEAL_CD_LEN 2

#define DL_STATUS_ACTIVE_LEN 2
#define DL_DT_NAME_LEN 11
#define DL_IND_NAME_LEN 13
#define DL_DEBIT_IND_LEN 4
#define DL_DEBIT_IND_100_LEN 11
#define DL_CREDIT_IND_LEN 4
#define DL_CREDIT_IND_100_LEN 11
#define DL_DET_LEN 66
#define DL_INFO_LEN 66
#define DL_COND_LEN 201
#define DL_LCL_CONDITION_LEN 201
#define DL_DESC_A_LEN 21
#define DL_DESC_B_LEN 21
typedef struct{
	char h_dealclass[DL_DEALCLASS_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	int h_dt_field;
	char h_status_active[DL_STATUS_ACTIVE_LEN];
	char h_dt_name[DL_DT_NAME_LEN];
	char h_ind_name[DL_IND_NAME_LEN];
	char h_debit_ind[DL_DEBIT_IND_LEN];
	char h_debit_ind_100[DL_DEBIT_IND_100_LEN];
	char h_credit_ind[DL_CREDIT_IND_LEN];
	char h_credit_ind_100[DL_CREDIT_IND_100_LEN];
	char h_det[DL_DET_LEN];
	char h_info[DL_INFO_LEN];
	char h_cond[DL_COND_LEN];
	char h_lcl_condition[DL_LCL_CONDITION_LEN];
	char h_desc_a[DL_DESC_A_LEN];
	char h_desc_b[DL_DESC_B_LEN];
}DL_LOCALREPSPEC_STRUCT_H;
typedef struct{
	short i_dealclass;
	short i_deal_cd;
	short i_dt_field;
	short i_status_active;
	short i_dt_name;
	short i_ind_name;
	short i_debit_ind;
	short i_debit_ind_100;
	short i_credit_ind;
	short i_credit_ind_100;
	short i_det;
	short i_info;
	short i_cond;
	short i_lcl_condition;
	short i_desc_a;
	short i_desc_b;
}DL_LOCALREPSPEC_STRUCT_I;







#define DL_DEALCLASS_LEN 3
#define DL_DEAL_CD_LEN 2

#define DL_STATUS_ACTIVE_LEN 2
#define DL_DT_NAME_LEN 11
#define DL_IND_NAME_LEN 13
#define DL_DEBIT_IND_LEN 5
#define DL_DEBIT_IND_100_LEN 11
#define DL_CREDIT_IND_LEN 5
#define DL_CREDIT_IND_100_LEN 11
#define DL_DET_LEN 66
#define DL_INFO_LEN 66
#define DL_COND_LEN 201
#define DL_LCL_CONDITION_LEN 201
#define DL_DESC_A_LEN 21
#define DL_DESC_B_LEN 21
typedef struct{
	char h_dealclass[DL_DEALCLASS_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	int h_dt_field;
	char h_status_active[DL_STATUS_ACTIVE_LEN];
	char h_dt_name[DL_DT_NAME_LEN];
	char h_ind_name[DL_IND_NAME_LEN];
	char h_debit_ind[DL_DEBIT_IND_LEN];
	char h_debit_ind_100[DL_DEBIT_IND_100_LEN];
	char h_credit_ind[DL_CREDIT_IND_LEN];
	char h_credit_ind_100[DL_CREDIT_IND_100_LEN];
	char h_det[DL_DET_LEN];
	char h_info[DL_INFO_LEN];
	char h_cond[DL_COND_LEN];
	char h_lcl_condition[DL_LCL_CONDITION_LEN];
	char h_desc_a[DL_DESC_A_LEN];
	char h_desc_b[DL_DESC_B_LEN];
}DL_LOCALREPSPECMA_STRUCT_H;
typedef struct{
	short i_dealclass;
	short i_deal_cd;
	short i_dt_field;
	short i_status_active;
	short i_dt_name;
	short i_ind_name;
	short i_debit_ind;
	short i_debit_ind_100;
	short i_credit_ind;
	short i_credit_ind_100;
	short i_det;
	short i_info;
	short i_cond;
	short i_lcl_condition;
	short i_desc_a;
	short i_desc_b;
}DL_LOCALREPSPECMA_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDEN_NO_LEN 17
#define DL_INSTR_CODE_LEN 9


#define DL_DETAILS_LEN 261
#define DL_FRM_LOC_LEN 5
#define DL_TO_LOCATION_LEN 5
#define DL_SENDMSG_IND_LEN 2
#define DL_BILLABLE_IND_LEN 2
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_DF_TXNR_IDEN_LEN 17
#define DL_RF_DL_IDENT_LEN 17
#define DL_DEALSTAT_LEN 3
#define DL_LOC_CHNG_STAT_LEN 3

#define DL_SETL_LEN 2
#define DL_UNIQ_IDENT_NO_LEN 15


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_iden_no[DL_IDEN_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_details[DL_DETAILS_LEN];
	char h_frm_loc[DL_FRM_LOC_LEN];
	char h_to_location[DL_TO_LOCATION_LEN];
	char h_sendmsg_ind[DL_SENDMSG_IND_LEN];
	char h_billable_ind[DL_BILLABLE_IND_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	double h_qty;
	char h_df_txnr_iden[DL_DF_TXNR_IDEN_LEN];
	char h_rf_dl_ident[DL_RF_DL_IDENT_LEN];
	char h_dealstat[DL_DEALSTAT_LEN];
	char h_loc_chng_stat[DL_LOC_CHNG_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_setl[DL_SETL_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	char h_df_setldate[APL_DATE_LEN];
	char h_rf_setl_date[APL_DATE_LEN];
}DL_LOCNCHG_STRUCT_H;
typedef struct{
	short i_client;
	short i_iden_no;
	short i_instr_code;
	short i_deal_date;
	short i_setl_date;
	short i_details;
	short i_frm_loc;
	short i_to_location;
	short i_sendmsg_ind;
	short i_billable_ind;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_dateof_input;
	short i_qty;
	short i_df_txnr_iden;
	short i_rf_dl_ident;
	short i_dealstat;
	short i_loc_chng_stat;
	short i_access_stamp;
	short i_setl;
	short i_uniq_ident_no;
	short i_df_setldate;
	short i_rf_setl_date;
}DL_LOCNCHG_STRUCT_I;







#define DL_TEMP1_LEN 11
#define DL_TEMP2_LEN 23
#define DL_TEMP3_LEN 2
#define DL_TEMP4_LEN 32
#define DL_TEMP5_LEN 24
#define DL_TEMP6_LEN 11
#define DL_TEMP7_LEN 87
#define DL_CLIENT_LEN 25

#define DL_BROKER_IDENTITY_LEN 12

#define DL_INSTR_ISIN_LEN 13



#define DL_REC_DEL_LEN 2
#define DL_MCL_REF_LEN 11
#define DL_DEAL_DATE_LEN 11
#define DL_UPLOAD_DATE_LEN 11

typedef struct{
	char h_temp1[DL_TEMP1_LEN];
	char h_temp2[DL_TEMP2_LEN];
	char h_temp3[DL_TEMP3_LEN];
	char h_temp4[DL_TEMP4_LEN];
	char h_temp5[DL_TEMP5_LEN];
	char h_temp6[DL_TEMP6_LEN];
	char h_temp7[DL_TEMP7_LEN];
	char h_client[DL_CLIENT_LEN];
	int h_brokercomm;
	char h_broker_identity[DL_BROKER_IDENTITY_LEN];
	int h_gross_amount;
	char h_instr_isin[DL_INSTR_ISIN_LEN];
	int h_net_amount;
	int h_cost;
	int h_qty;
	char h_rec_del[DL_REC_DEL_LEN];
	char h_mcl_ref[DL_MCL_REF_LEN];
	char h_deal_date[DL_DEAL_DATE_LEN];
	char h_upload_date[DL_UPLOAD_DATE_LEN];
	int h_error_cd;
}DL_MAROCLEAR_STRUCT_H;
typedef struct{
	short i_temp1;
	short i_temp2;
	short i_temp3;
	short i_temp4;
	short i_temp5;
	short i_temp6;
	short i_temp7;
	short i_client;
	short i_brokercomm;
	short i_broker_identity;
	short i_gross_amount;
	short i_instr_isin;
	short i_net_amount;
	short i_cost;
	short i_qty;
	short i_rec_del;
	short i_mcl_ref;
	short i_deal_date;
	short i_upload_date;
	short i_error_cd;
}DL_MAROCLEAR_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_DEAL_CD_LEN 2


#define DL_INSTR_CODE_LEN 9





#define DL_CHECKER_LEN 15

#define DL_CP_CLTNAME_LEN 66
#define DL_MIS_DL_STAT_LEN 3
#define DL_CP_CLT_LEN 11
#define DL_MAKER_LEN 15
#define DL_INFO_LEN 351
#define DL_PLACEOF_DEAL_LEN 5
#define DL_MRKT_IND_LEN 5
#define DL_NARRATIVE_LEN 31

#define DL_CLIENTOF_CD_LEN 11
#define DL_CLIENTOF_LEN 66
#define DL_INSTRUCT_PERSON_LEN 11
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_DEAL_CLS_LEN 6
#define DL_DEAL_RF_IDENT_LEN 17
#define DL_COMMIDENT_LEN 17
#define DL_POOL_REF_LEN 17
#define DL_SEND_MSG_IND_LEN 2
#define DL_PARTY_CON_LEN 141
#define DL_UNIQ_IDENT_NO_LEN 15

#define DL_NAMEOF_FILE_LEN 31
#define DL_DSN_REFCD_LEN 12
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_qty;
	char h_instr_code[DL_INSTR_CODE_LEN];
	double h_amount;
	double h_cost;
	char h_dateof_input[APL_DATE_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_mis_dl_stat[DL_MIS_DL_STAT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_info[DL_INFO_LEN];
	char h_placeof_deal[DL_PLACEOF_DEAL_LEN];
	char h_mrkt_ind[DL_MRKT_IND_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
	char h_dealdt[APL_DATE_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_deal_cls[DL_DEAL_CLS_LEN];
	char h_deal_rf_ident[DL_DEAL_RF_IDENT_LEN];
	char h_commident[DL_COMMIDENT_LEN];
	char h_pool_ref[DL_POOL_REF_LEN];
	char h_send_msg_ind[DL_SEND_MSG_IND_LEN];
	char h_party_con[DL_PARTY_CON_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_proc_num;
	char h_nameof_file[DL_NAMEOF_FILE_LEN];
	char h_dsn_refcd[DL_DSN_REFCD_LEN];
}DL_MISDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_domestic_cpclt;
	short i_deal_cd;
	short i_setl_date;
	short i_qty;
	short i_instr_code;
	short i_amount;
	short i_cost;
	short i_dateof_input;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_cp_cltname;
	short i_mis_dl_stat;
	short i_cp_clt;
	short i_maker;
	short i_info;
	short i_placeof_deal;
	short i_mrkt_ind;
	short i_narrative;
	short i_dealdt;
	short i_clientof_cd;
	short i_clientof;
	short i_instruct_person;
	short i_instruct_personnm;
	short i_deal_cls;
	short i_deal_rf_ident;
	short i_commident;
	short i_pool_ref;
	short i_send_msg_ind;
	short i_party_con;
	short i_uniq_ident_no;
	short i_proc_num;
	short i_nameof_file;
	short i_dsn_refcd;
}DL_MISDEAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7

#define DL_INFORMATION_LEN 31


#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 2001
#define DL_MESSAGE_DET_C_LEN 2001
#define DL_MESSAGE_DET_D_LEN 2001
#define DL_MESSAGE_DET_E_LEN 2001
#define DL_PSETPARTY_LEN 161
#define DL_PLACE_CD_LEN 5
#define DL_NARRATIVE_LEN 41
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[DL_INFORMATION_LEN];
	int h_inden_num;
	int h_dl_rep_identno;
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
	char h_psetparty[DL_PSETPARTY_LEN];
	char h_place_cd[DL_PLACE_CD_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
}DL_MSGLINK_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_date_of_input;
	short i_information;
	short i_inden_num;
	short i_dl_rep_identno;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_psetparty;
	short i_place_cd;
	short i_narrative;
}DL_MSGLINK_STRUCT_I;








#define DL_SEQUENCE_NAME_LEN 6
#define DL_LINK_VAL_LEN 6
#define DL_LINK_TAG_LEN 51


#define DL_MSG_TAG_LEN 6
typedef struct{
	int h_inden_num;
	char h_sequence_name[DL_SEQUENCE_NAME_LEN];
	char h_link_val[DL_LINK_VAL_LEN];
	char h_link_tag[DL_LINK_TAG_LEN];
	int h_msg_tag_rep_no;
	int h_msg_line_no;
	char h_msg_tag[DL_MSG_TAG_LEN];
}DL_MSGLINKDET_STRUCT_H;
typedef struct{
	short i_inden_num;
	short i_sequence_name;
	short i_link_val;
	short i_link_tag;
	short i_msg_tag_rep_no;
	short i_msg_line_no;
	short i_msg_tag;
}DL_MSGLINKDET_STRUCT_I;








#define DL_INFORMATION_LEN 31
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7
#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 4001
#define DL_MESSAGE_DET_C_LEN 4001
#define DL_MESSAGE_DET_D_LEN 4001
#define DL_MESSAGE_DET_E_LEN 4001
typedef struct{
	char h_date_of_input[APL_DATE_LEN];
	char h_information[DL_INFORMATION_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
}DL_MSGLINK_INC536_VEW_STRUCT_H;
typedef struct{
	short i_date_of_input;
	short i_information;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
}DL_MSGLINK_INC536_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_STAT_QUAL_LEN 5
#define DL_STATUS_CD_LEN 7
#define DL_REASON_QL_LEN 7
#define DL_REASON_CD_LEN 5
#define DL_INFO_LEN 36
#define DL_FAILREASON_CD_LEN 3


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_stat_blckno;
	char h_stat_qual[DL_STAT_QUAL_LEN];
	char h_status_cd[DL_STATUS_CD_LEN];
	char h_reason_ql[DL_REASON_QL_LEN];
	char h_reason_cd[DL_REASON_CD_LEN];
	char h_info[DL_INFO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	int h_sub_fail_cd;
	char h_access_stamp[APL_DATE_LEN];
}DL_MULT_REAS_CODES_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_stat_blckno;
	short i_stat_qual;
	short i_status_cd;
	short i_reason_ql;
	short i_reason_cd;
	short i_info;
	short i_failreason_cd;
	short i_sub_fail_cd;
	short i_access_stamp;
}DL_MULT_REAS_CODES_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INFO1_LEN 261
#define DL_INFO2_LEN 261
#define DL_INFO3_LEN 261
#define DL_INFO4_LEN 261
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_info2[DL_INFO2_LEN];
	char h_info3[DL_INFO3_LEN];
	char h_info4[DL_INFO4_LEN];
}DL_NOTES_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_info1;
	short i_info2;
	short i_info3;
	short i_info4;
}DL_NOTES_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_STATUS_POS_LEN 4

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	int h_stat_conf_pos;
}DL_PAST_VDP_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_status_pos;
	short i_stat_conf_pos;
}DL_PAST_VDP_VEW_STRUCT_I;













/*
typedef struct{
	
	
	
	
	
	
	
}DL_PER_PORTFOLIO_VEW_STRUCT_H;
*/
typedef struct{
	short i_master_clt;
	short i_instrument;
	short i_position;
	short i_mkrt_pr;
	short i_portfolio_amt;
	short i_total_portfolio;
	short i_equity_bond;
}DL_PER_PORTFOLIO_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_B_CCYCD_LEN 4
#define DL_FEES_CCY_LEN 4
#define DL_SEND_TO_MASTER_IND_LEN 2
#define DL_B_GEN_IND_LEN 2

#define DL_MINIMUMFEE_TO_LEN 2
#define DL_MIN_HLD_ADJ_LEN 2
#define DL_DIR_DB_IND_LEN 2
#define DL_SPL_CLT_CD_LEN 7
#define DL_COMM_CLT_LEN 11
#define DL_REC_CLT_LEN 11
#define DL_INFORMATION_LEN 241
#define DL_DEFAULT_FEECLT_LEN 11


#define DL_CA_IDENTNAME_LEN 41


#define DL_FEES_BASE_LEN 31
#define DL_CHRG_BASE_LEN 31
#define DL_CHRG_CLAS_LEN 2
#define DL_FEES_CLASS_LEN 2



#define DL_PARAMETER_CD_LEN 201

#define DL_PROC_DATA_VAL_LEN 201





#define DL_SERVICE_DET_LEN 21
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_b_ccycd[DL_B_CCYCD_LEN];
	char h_fees_ccy[DL_FEES_CCY_LEN];
	char h_send_to_master_ind[DL_SEND_TO_MASTER_IND_LEN];
	char h_b_gen_ind[DL_B_GEN_IND_LEN];
	double h_bc_minimumfee;
	char h_minimumfee_to[DL_MINIMUMFEE_TO_LEN];
	char h_min_hld_adj[DL_MIN_HLD_ADJ_LEN];
	char h_dir_db_ind[DL_DIR_DB_IND_LEN];
	char h_spl_clt_cd[DL_SPL_CLT_CD_LEN];
	char h_comm_clt[DL_COMM_CLT_LEN];
	char h_rec_clt[DL_REC_CLT_LEN];
	char h_information[DL_INFORMATION_LEN];
	char h_default_feeclt[DL_DEFAULT_FEECLT_LEN];
	double h_total_osamount;
	double h_comm_tax_amt;
	char h_ca_identname[DL_CA_IDENTNAME_LEN];
	char h_current_date[APL_DATE_LEN];
	int h_bs_service_cd;
	char h_fees_base[DL_FEES_BASE_LEN];
	char h_chrg_base[DL_CHRG_BASE_LEN];
	char h_chrg_clas[DL_CHRG_CLAS_LEN];
	char h_fees_class[DL_FEES_CLASS_LEN];
	double h_minimumfee;
	double h_nil_fees;
	double h_maximum_fee;
	char h_parameter_cd[DL_PARAMETER_CD_LEN];
	int h_service_cd;
	char h_proc_data_val[DL_PROC_DATA_VAL_LEN];
	int h_schdl_fee;
	int h_frm_cbase;
	int h_toc_base;
	int h_frm_fbase;
	int h_tof_base;
	char h_service_det[DL_SERVICE_DET_LEN];
}DL_PREV_EOM_SAFEK_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_b_ccycd;
	short i_fees_ccy;
	short i_send_to_master_ind;
	short i_b_gen_ind;
	short i_bc_minimumfee;
	short i_minimumfee_to;
	short i_min_hld_adj;
	short i_dir_db_ind;
	short i_spl_clt_cd;
	short i_comm_clt;
	short i_rec_clt;
	short i_information;
	short i_default_feeclt;
	short i_total_osamount;
	short i_comm_tax_amt;
	short i_ca_identname;
	short i_current_date;
	short i_bs_service_cd;
	short i_fees_base;
	short i_chrg_base;
	short i_chrg_clas;
	short i_fees_class;
	short i_minimumfee;
	short i_nil_fees;
	short i_maximum_fee;
	short i_parameter_cd;
	short i_service_cd;
	short i_proc_data_val;
	short i_schdl_fee;
	short i_frm_cbase;
	short i_toc_base;
	short i_frm_fbase;
	short i_tof_base;
	short i_service_det;
}DL_PREV_EOM_SAFEK_VEW_STRUCT_I;







#define DL_NATION_LEN 3
#define DL_REG_ST_CD_LEN 2
#define DL_REG_ST_DESC_LEN 41
#define DL_STATUS_POS_LEN 4
#define DL_MOD_DEALPOS_LEN 2
#define DL_REG_AUD_FUN_LEN 4
#define DL_MAN_STAT_LEN 2
#define DL_REG_SHORT_LEN 7
#define DL_NEW_REG_A_LEN 2
#define DL_NEWT_REG_B_LEN 2
#define DL_FLD_UP_DATE_LEN 21
#define DL_PREV_REG_LEN 2
typedef struct{
	char h_nation[DL_NATION_LEN];
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	char h_reg_st_desc[DL_REG_ST_DESC_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_mod_dealpos[DL_MOD_DEALPOS_LEN];
	char h_reg_aud_fun[DL_REG_AUD_FUN_LEN];
	char h_man_stat[DL_MAN_STAT_LEN];
	char h_reg_short[DL_REG_SHORT_LEN];
	char h_new_reg_a[DL_NEW_REG_A_LEN];
	char h_newt_reg_b[DL_NEWT_REG_B_LEN];
	char h_fld_up_date[DL_FLD_UP_DATE_LEN];
	char h_prev_reg[DL_PREV_REG_LEN];
}DL_REGCYCLE_STRUCT_H;
typedef struct{
	short i_nation;
	short i_reg_st_cd;
	short i_reg_st_desc;
	short i_status_pos;
	short i_mod_dealpos;
	short i_reg_aud_fun;
	short i_man_stat;
	short i_reg_short;
	short i_new_reg_a;
	short i_newt_reg_b;
	short i_fld_up_date;
	short i_prev_reg;
}DL_REGCYCLE_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_REG_ST_CD_LEN 2







#define DL_STATUS_PRC_LEN 2


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	char h_deal_dt[APL_DATE_LEN];
	double h_quantity;
	char h_access_stamp[APL_DATE_LEN];
	double h_moved_qty;
	double h_manifold_qty;
	char h_dt_client_for[APL_DATE_LEN];
	char h_prc_smr_date[APL_DATE_LEN];
	char h_status_prc[DL_STATUS_PRC_LEN];
	char h_prc_setl_date[APL_DATE_LEN];
	double h_amr_amount;
}DL_REGDET_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_reg_st_cd;
	short i_deal_dt;
	short i_quantity;
	short i_access_stamp;
	short i_moved_qty;
	short i_manifold_qty;
	short i_dt_client_for;
	short i_prc_smr_date;
	short i_status_prc;
	short i_prc_setl_date;
	short i_amr_amount;
}DL_REGDET_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	int h_srl_no;
	int h_parent_srlno;
	double h_parent_qty;
}DL_REGPAR_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_srl_no;
	short i_parent_srlno;
	short i_parent_qty;
}DL_REGPAR_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_REG_ST_CD_LEN 2





#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTR_CODE_LEN 9
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	int h_srl_no;
	double h_quantity;
	char h_to_date[APL_DATE_LEN];
	char h_frm_date[APL_DATE_LEN];
	int h_date_diff;
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
}DL_REG_STATISTICS_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_reg_st_cd;
	short i_srl_no;
	short i_quantity;
	short i_to_date;
	short i_frm_date;
	short i_date_diff;
	short i_lcl_identno;
	short i_instr_code;
}DL_REG_STATISTICS_VEW_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_REG_ST_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_DEAL_CD_LEN 2
#define DL_LCL_IDENTNO_LEN 17


typedef struct{
	int h_reg_st_qty;
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_reg_st_cd[DL_REG_ST_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	double h_qty;
	char h_last_reg_date[APL_DATE_LEN];
}DL_REG_STATUS_VEW_STRUCT_H;
typedef struct{
	short i_reg_st_qty;
	short i_client;
	short i_identiy_no;
	short i_reg_st_cd;
	short i_instr_code;
	short i_deal_cd;
	short i_lcl_identno;
	short i_qty;
	short i_last_reg_date;
}DL_REG_STATUS_VEW_STRUCT_I;











/*
typedef struct{
	
	
	
	
	
}DL_REPIRE_VEW_STRUCT_H;
*/
typedef struct{
	short i_instr_code;
	short i_loc_valt;
	short i_depo_loc;
	short i_for_valt;
	short i_for_depo;
}DL_REPIRE_VEW_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21



typedef struct{
	char h_posit_date[APL_DATE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_safekeep_pos;
	double h_val_rec;
	double h_val_del;
}DL_RUARCHSAFEK_STRUCT_H;
typedef struct{
	short i_posit_date;
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_safekeep_pos;
	short i_val_rec;
	short i_val_del;
}DL_RUARCHSAFEK_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_CLIENT_NAME_LEN 71
#define DL_SYN_CLIENT_LEN 6
#define DL_CLTTYP_LEN 3
#define DL_CLT_TYP_LEN 3



#define DL_NOSTR_CLTPID_LEN 21
#define DL_NOSTR_CLTTYP_LEN 21
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_RU_CLIENT_STAT_LEN 3
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_client_name[DL_CLIENT_NAME_LEN];
	char h_syn_client[DL_SYN_CLIENT_LEN];
	char h_clttyp[DL_CLTTYP_LEN];
	char h_clt_typ[DL_CLT_TYP_LEN];
	int h_baseclt;
	char h_client_opdt[APL_DATE_LEN];
	char h_client_close_dt[APL_DATE_LEN];
	char h_nostr_cltpid[DL_NOSTR_CLTPID_LEN];
	char h_nostr_clttyp[DL_NOSTR_CLTTYP_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_ru_client_stat[DL_RU_CLIENT_STAT_LEN];
}DL_RUCLIENT_STRUCT_H;
typedef struct{
	short i_client;
	short i_client_name;
	short i_syn_client;
	short i_clttyp;
	short i_clt_typ;
	short i_baseclt;
	short i_client_opdt;
	short i_client_close_dt;
	short i_nostr_cltpid;
	short i_nostr_clttyp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_input;
	short i_ru_client_stat;
}DL_RUCLIENT_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21


#define DL_DEAL_CD_LEN 2


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_qty;
	double h_amount;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
}DL_RUDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_qty;
	short i_amount;
	short i_deal_cd;
	short i_deal_date;
	short i_instrument_dt;
}DL_RUDEAL_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21


#define DL_DEAL_CD_LEN 2


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_qty;
	double h_amount;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
}DL_RUDEAL_TMP_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_qty;
	short i_amount;
	short i_deal_cd;
	short i_deal_date;
	short i_instrument_dt;
}DL_RUDEAL_TMP_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21


#define DL_DEAL_CD_LEN 2



typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_qty;
	double h_amount;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
}DL_RUHISDEAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_qty;
	short i_amount;
	short i_deal_cd;
	short i_deal_date;
	short i_instrument_dt;
	short i_dateof_input;
}DL_RUHISDEAL_STRUCT_I;








#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_ST_REG_NO_LEN 21



typedef struct{
	char h_posit_date[APL_DATE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	double h_safekeep_pos;
	double h_val_rec;
	double h_val_del;
}DL_RUHISSAFEK_STRUCT_H;
typedef struct{
	short i_posit_date;
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_st_reg_no;
	short i_safekeep_pos;
	short i_val_rec;
	short i_val_del;
}DL_RUHISSAFEK_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_SEC_NM_LEN 71
#define DL_SNM_IND_LEN 76
#define DL_STAT_REG_NO_LEN 21


#define DL_SEC_CLS_LEN 4

#define DL_TYPEOFINSTR_LEN 4
#define DL_PR_CODE_LEN 4
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_RU_INSTR_STAT_LEN 3
typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_sec_nm[DL_SEC_NM_LEN];
	char h_snm_ind[DL_SNM_IND_LEN];
	char h_stat_reg_no[DL_STAT_REG_NO_LEN];
	char h_instrument_opdt[APL_DATE_LEN];
	char h_sec_cldate[APL_DATE_LEN];
	char h_sec_cls[DL_SEC_CLS_LEN];
	int h_baseinstrument;
	char h_typeofinstr[DL_TYPEOFINSTR_LEN];
	char h_pr_code[DL_PR_CODE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_ru_instr_stat[DL_RU_INSTR_STAT_LEN];
}DL_RUINSTRUMENT_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_sec_nm;
	short i_snm_ind;
	short i_stat_reg_no;
	short i_instrument_opdt;
	short i_sec_cldate;
	short i_sec_cls;
	short i_baseinstrument;
	short i_typeofinstr;
	short i_pr_code;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_input;
	short i_ru_instr_stat;
}DL_RUINSTRUMENT_STRUCT_I;







#define DL_LOC_LEN 5
#define DL_LOC_NAME_LEN 71
#define DL_SYN_LOCATION_LEN 6
#define DL_LICENSE_NO_LEN 21
#define DL_LOC_TYPE_LEN 3
#define DL_DEPO_CD_LEN 26



#define DL_NOSTR_CLTPID_LEN 21
#define DL_NOSTR_CLTTYP_LEN 21
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_RU_LOC_STAT_LEN 3
typedef struct{
	char h_loc[DL_LOC_LEN];
	char h_loc_name[DL_LOC_NAME_LEN];
	char h_syn_location[DL_SYN_LOCATION_LEN];
	char h_license_no[DL_LICENSE_NO_LEN];
	char h_loc_type[DL_LOC_TYPE_LEN];
	char h_depo_cd[DL_DEPO_CD_LEN];
	int h_baselocation;
	char h_loc_opdate[APL_DATE_LEN];
	char h_loc_close_dt[APL_DATE_LEN];
	char h_nostr_cltpid[DL_NOSTR_CLTPID_LEN];
	char h_nostr_clttyp[DL_NOSTR_CLTTYP_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_ru_loc_stat[DL_RU_LOC_STAT_LEN];
}DL_RULOCATION_STRUCT_H;
typedef struct{
	short i_loc;
	short i_loc_name;
	short i_syn_location;
	short i_license_no;
	short i_loc_type;
	short i_depo_cd;
	short i_baselocation;
	short i_loc_opdate;
	short i_loc_close_dt;
	short i_nostr_cltpid;
	short i_nostr_clttyp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_input;
	short i_ru_loc_stat;
}DL_RULOCATION_STRUCT_I;







#define DL_PR_CODE_LEN 4
#define DL_PR_DET_LEN 21
#define DL_MT_CURRENCY_LEN 4
#define DL_DAY_DATE_LEN 4
#define DL_DAY_YEAR_LEN 4
#define DL_PRD_TYPE_LEN 4
#define DL_INTTYPE_LEN 4
#define DL_LOC_LEN 5
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_STATUS_PROD_LEN 3
typedef struct{
	char h_pr_code[DL_PR_CODE_LEN];
	char h_pr_det[DL_PR_DET_LEN];
	char h_mt_currency[DL_MT_CURRENCY_LEN];
	char h_day_date[DL_DAY_DATE_LEN];
	char h_day_year[DL_DAY_YEAR_LEN];
	char h_prd_type[DL_PRD_TYPE_LEN];
	char h_inttype[DL_INTTYPE_LEN];
	char h_loc[DL_LOC_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_status_prod[DL_STATUS_PROD_LEN];
}DL_RUPRODUCT_STRUCT_H;
typedef struct{
	short i_pr_code;
	short i_pr_det;
	short i_mt_currency;
	short i_day_date;
	short i_day_year;
	short i_prd_type;
	short i_inttype;
	short i_loc;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_input;
	short i_status_prod;
}DL_RUPRODUCT_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_ST_REG_NO_LEN 21
#define DL_LOCATION_CD_LEN 5



#define DL_NEW_OLD_IND_LEN 2

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_st_reg_no[DL_ST_REG_NO_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	double h_val_rec;
	double h_val_del;
	double h_safekeep_pos;
	char h_new_old_ind[DL_NEW_OLD_IND_LEN];
	char h_new_dt[APL_DATE_LEN];
}DL_RUSAFEK_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_st_reg_no;
	short i_location_cd;
	short i_val_rec;
	short i_val_del;
	short i_safekeep_pos;
	short i_new_old_ind;
	short i_new_dt;
}DL_RUSAFEK_STRUCT_I;







#define DL_STAT_REG_NO_LEN 21
#define DL_INSTR_CODE_LEN 9
#define DL_INSTR_NAME_LEN 51
#define DL_IDENTIY_NUM_LEN 11
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15



#define DL_SRN_STAT_LEN 3
typedef struct{
	char h_stat_reg_no[DL_STAT_REG_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_instr_name[DL_INSTR_NAME_LEN];
	char h_identiy_num[DL_IDENTIY_NUM_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_srn_stat[DL_SRN_STAT_LEN];
}DL_RUSRN_STRUCT_H;
typedef struct{
	short i_stat_reg_no;
	short i_instr_code;
	short i_instr_name;
	short i_identiy_num;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_dateof_input;
	short i_srn_stat;
}DL_RUSRN_STRUCT_I;







#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_CLIENT_LEN 11

#define DL_STATUS_POS_LEN 4





/*
typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	double h_start_safek;
	double h_safekeep_pos;
	double h_nvalreceive;
	double h_nvaldeliver;
	double h_val_rec;
	double h_val_del;
	double h_dp_rec;
	double h_dp_del;
	char   h_block_type[5];
}DL_SAFEK_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_location_cd;
	short i_client;
	short i_access_stamp;
	short i_status_pos;
	short i_start_safek;
	short i_safekeep_pos;
	short i_nvalreceive;
	short i_nvaldeliver;
	short i_val_rec;
	short i_val_del;
	short i_dp_rec;
	short i_dp_del;
	short i_block_type;
}DL_SAFEK_STRUCT_I;
*/







#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_CLIENT_LEN 11

typedef struct{
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_client[DL_CLIENT_LEN];
	int h_safekeep_pos;
}DL_SAFEK_VEW_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_location_cd;
	short i_client;
	short i_safekeep_pos;
}DL_SAFEK_VEW_STRUCT_I;















/*
typedef struct{
	
	
	
	
	
	
	
	
	
}DL_SECTORWISE_HOLD_VEW_STRUCT_H;
*/
typedef struct{
	short i_instr_dl_code;
	short i_instr_code;
	short i_currency_cd;
	short i_client;
	short i_nation_cd;
	short i_total_pos;
	short i_mrkt_val;
	short i_exchgrt;
	short i_dir_indir_fxqt_ind;
}DL_SECTORWISE_HOLD_VEW_STRUCT_I;







#define DL_SWIFT_MSG_NO_LEN 4
#define DL_NAMEOF_FILE_LEN 51
#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_RF_IDENT_NO_LEN 17
#define DL_INSTR_CODE_LEN 9

#define DL_CURRENCY_CD_LEN 4

#define DL_DEAL_CD_LEN 2

#define DL_MESSAGE_STAT_LEN 4
#define DL_REJECT_REASON_LEN 151

#define DL_REPORT_IND_LEN 2

typedef struct{
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_nameof_file[DL_NAMEOF_FILE_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_rf_ident_no[DL_DEAL_RF_IDENT_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	double h_amount;
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	double h_qty;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instrument_dt[APL_DATE_LEN];
	char h_message_stat[DL_MESSAGE_STAT_LEN];
	char h_reject_reason[DL_REJECT_REASON_LEN];
	char h_report_dt[APL_DATE_LEN];
	char h_report_ind[DL_REPORT_IND_LEN];
	int h_deal_no;
}DL_SETLRPT_STRUCT_H;
typedef struct{
	short i_swift_msg_no;
	short i_nameof_file;
	short i_client;
	short i_identiy_no;
	short i_deal_rf_ident_no;
	short i_instr_code;
	short i_amount;
	short i_currency_cd;
	short i_qty;
	short i_deal_cd;
	short i_instrument_dt;
	short i_message_stat;
	short i_reject_reason;
	short i_report_dt;
	short i_report_ind;
	short i_deal_no;
}DL_SETLRPT_STRUCT_I;








#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7
#define DL_INFORMATION_LEN 31

#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 4001
#define DL_MESSAGE_DET_C_LEN 4001
#define DL_MESSAGE_DET_D_LEN 4001
#define DL_MESSAGE_DET_E_LEN 4001
#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_RF_IDENT_NO_LEN 17
#define DL_REJECT_REASON_LEN 151

#define DL_REPORT_IND_LEN 2
#define DL_MESSAGE_STAT_LEN 4
#define DL_NATION_CODE_LEN 3

typedef struct{
	char h_date_of_input[APL_DATE_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_information[DL_INFORMATION_LEN];
	int h_deal_no;
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_rf_ident_no[DL_DEAL_RF_IDENT_NO_LEN];
	char h_reject_reason[DL_REJECT_REASON_LEN];
	char h_report_dt[APL_DATE_LEN];
	char h_report_ind[DL_REPORT_IND_LEN];
	char h_message_stat[DL_MESSAGE_STAT_LEN];
	char h_nation_code[DL_NATION_CODE_LEN];
	char h_current_date[APL_DATE_LEN];
}DL_SETLRPT_VEW_STRUCT_H;
typedef struct{
	short i_date_of_input;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_information;
	short i_deal_no;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_client;
	short i_identiy_no;
	short i_deal_rf_ident_no;
	short i_reject_reason;
	short i_report_dt;
	short i_report_ind;
	short i_message_stat;
	short i_nation_code;
	short i_current_date;
}DL_SETLRPT_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17

#define DL_NAMEOF_FILE_LEN 31
#define DL_SFE_PROC_DATA_LEN 31
#define DL_UNIQ_IDENT_NO_LEN 15
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_nameof_file[DL_NAMEOF_FILE_LEN];
	char h_sfe_proc_data[DL_SFE_PROC_DATA_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
}DL_SFEREJ_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_dateof_input;
	short i_nameof_file;
	short i_sfe_proc_data;
	short i_uniq_ident_no;
}DL_SFEREJ_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DEAL_CD_LEN 2
#define DL_DL_CLASS_LEN 3
#define DL_EX_ARENA_LEN 3


#define DL_LOCATION_CD_LEN 5
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_INFO1_LEN 261
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_VERFIED_WITH_LEN 26
#define DL_DEAL_STAT_LEN 3
#define DL_CP_CLTNAME_LEN 66
#define DL_IN_FAVOUROF_LEN 66



#define DL_DEAL_STAGE_LEN 2
#define DL_SMI_REQUEST_TYPE_LEN 2
#define DL_SMI_REJECT_REASON_LEN 201


#define DL_COMM_IDENT_NO_LEN 17
#define DL_MAKER_LEN 15

#define DL_CHECKER_LEN 15


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_ex_arena[DL_EX_ARENA_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_in_favourof[DL_IN_FAVOUROF_LEN];
	double h_qty;
	double h_net_setl_value;
	double h_gross_setlvalue;
	char h_deal_stage[DL_DEAL_STAGE_LEN];
	char h_smi_request_type[DL_SMI_REQUEST_TYPE_LEN];
	char h_smi_reject_reason[DL_SMI_REJECT_REASON_LEN];
	char h_access_stamp[APL_DATE_LEN];
	int h_sub_fail_cd;
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_val_fdt[APL_DATE_LEN];
}DL_SMI_PENDTXN_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_cd;
	short i_dl_class;
	short i_ex_arena;
	short i_deal_date;
	short i_setl_date;
	short i_location_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_domestic_cpclt;
	short i_cp_clt;
	short i_info1;
	short i_failreason_cd;
	short i_fail_det;
	short i_verfied_with;
	short i_deal_stat;
	short i_cp_cltname;
	short i_in_favourof;
	short i_qty;
	short i_net_setl_value;
	short i_gross_setlvalue;
	short i_deal_stage;
	short i_smi_request_type;
	short i_smi_reject_reason;
	short i_access_stamp;
	short i_sub_fail_cd;
	short i_comm_ident_no;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_val_fdt;
}DL_SMI_PENDTXN_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17



#define DL_EX_ARENA_LEN 3








#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_SPOTTRD_IND_LEN 2


#define DL_DEAL_FRM_ORD_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REAPIRED_IND_LEN 2
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_CLIENT_NOTE_LEN 71
#define DL_FX_REQD_LEN 2
#define DL_PAYLOC_IND_LEN 2
#define DL_VERFIED_WITH_LEN 26

#define DL_BRK_NO_LEN 13
#define DL_FAILREASON_CD_LEN 3
#define DL_FAIL_DET_LEN 36
#define DL_PARTIAL_IND_B_LEN 2



#define DL_REPORT_AT_EOM_IND_LEN 2

#define DL_LCL_IDENTNO_LEN 17
#define DL_INSTRUCT_PERSON_LEN 36

#define DL_DEAL_CD_LEN 2
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DL_CLASS_LEN 3
#define DL_ORIG_REFNO_LEN 17

#define DL_MAKER_LEN 15

#define DL_DEAL_STAT_LEN 3

#define DL_INFO1_LEN 261
#define DL_LOCATION_CD_LEN 5
#define DL_REGINSTR_IND_LEN 2
#define DL_STATUS_POS_LEN 4
#define DL_STATUS_REG_LEN 2

#define DL_COMPREFNO_LEN 17


#define DL_CHECKER_LEN 15

#define DL_INSTRCONV_IND_LEN 2

#define DL_LR_DL_CLASS_LEN 3






























#define DL_CLT_REQDEL_IND_LEN 2
#define DL_MOD_HISPOS_IND_LEN 2

#define DL_GL_CLIENT_LEN 11

#define DL_MSG_STAT_LEN 51

#define DL_PARTIAL_IND_A_LEN 2
#define DL_LOC_CHNG_IND_LEN 2
#define DL_COMM_IDENT_NO_LEN 17
#define DL_INSTRUCT_PERSONNM_LEN 66
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_UNIQ_IDENT_NO_LEN 15


#define DL_RELATED_IDENT_NO_LEN 21
#define DL_INFORMATON_LEN 201
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_cost;
	char h_ex_arena[DL_EX_ARENA_LEN];
	double h_amount;
	double h_custodycomm;
	double h_brokercomm;
	double h_stx_comm;
	double h_oth_comm;
	char h_instrument_dt[APL_DATE_LEN];
	char h_money_setl_dt[APL_DATE_LEN];
	double h_qty;
	char h_domestic_cpclt[DL_DOMESTIC_CPCLT_LEN];
	char h_spottrd_ind[DL_SPOTTRD_IND_LEN];
	double h_orig_qty;
	double h_orig_amount;
	char h_deal_frm_ord[DL_DEAL_FRM_ORD_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_reapired_ind[DL_REAPIRED_IND_LEN];
	char h_domcp_custodyclt[DL_DOMCP_CUSTODYCLT_LEN];
	char h_cp_clt[DL_CP_CLT_LEN];
	char h_cp_cltname[DL_CP_CLTNAME_LEN];
	char h_clientof[DL_CLIENTOF_LEN];
	char h_client_note[DL_CLIENT_NOTE_LEN];
	char h_fx_reqd[DL_FX_REQD_LEN];
	char h_payloc_ind[DL_PAYLOC_IND_LEN];
	char h_verfied_with[DL_VERFIED_WITH_LEN];
	double h_amt_differ;
	char h_brk_no[DL_BRK_NO_LEN];
	char h_failreason_cd[DL_FAILREASON_CD_LEN];
	char h_fail_det[DL_FAIL_DET_LEN];
	char h_partial_ind_b[DL_PARTIAL_IND_B_LEN];
	double h_fx_rt;
	int h_amend_count;
	int h_number_a;
	char h_report_at_eom_ind[DL_REPORT_AT_EOM_IND_LEN];
	char h_dateofbilling[APL_DATE_LEN];
	char h_lcl_identno[DL_LCL_IDENTNO_LEN];
	char h_instruct_person[DL_INSTRUCT_PERSON_LEN];
	double h_rec_int_000;
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_currency_cd[DL_CURRENCY_CD_LEN];
	char h_dl_class[DL_DL_CLASS_LEN];
	char h_orig_refno[DL_ORIG_REFNO_LEN];
	char h_dateof_input[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_deal_stat[DL_DEAL_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_info1[DL_INFO1_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_reginstr_ind[DL_REGINSTR_IND_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_status_reg[DL_STATUS_REG_LEN];
	char h_val_fdt[APL_DATE_LEN];
	char h_comprefno[DL_COMPREFNO_LEN];
	char h_dateof_markfail[APL_DATE_LEN];
	char h_allow_dropdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_instrconv_ind[DL_INSTRCONV_IND_LEN];
	char h_nds_blk_dt[APL_DATE_LEN];
	char h_lr_dl_class[DL_LR_DL_CLASS_LEN];
	char h_nds_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	double h_delta_000;
	double h_delta_001;
	double h_delta_003;
	char h_del_rec_date[APL_DATE_LEN];
	char h_last_reg_date[APL_DATE_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_valdate[APL_DATE_LEN];
	char h_lrinstr_date[APL_DATE_LEN];
	double h_reg_msg_qty;
	char h_tmp_out_dt[APL_DATE_LEN];
	char h_tmp_out_date[APL_DATE_LEN];
	char h_trans_date[APL_DATE_LEN];
	double h_tot_qty;
	double h_qty_lost;
	double h_mrk_dl_failqty;
	double h_dl_completeqty;
	double h_out_reg_qty;
	double h_pend_reg_qty;
	double h_ret_reg_qty;
	double h_stamp_qty;
	double h_temp_out_quantity;
	double h_temp_ret_quantity;
	double h_val_deed_qty;
	char h_host_date[APL_DATE_LEN];
	char h_lrnds_billdt[APL_DATE_LEN];
	char h_lrnds_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	int h_number_b;
	char h_clt_reqdel_ind[DL_CLT_REQDEL_IND_LEN];
	char h_mod_hispos_ind[DL_MOD_HISPOS_IND_LEN];
	char h_mod_hispos_date[APL_DATE_LEN];
	char h_gl_client[DL_GL_CLIENT_LEN];
	double h_cp_amt;
	char h_msg_stat[DL_MSG_STAT_LEN];
	int h_sub_fail_cd;
	char h_partial_ind_a[DL_PARTIAL_IND_A_LEN];
	char h_loc_chng_ind[DL_LOC_CHNG_IND_LEN];
	char h_comm_ident_no[DL_COMM_IDENT_NO_LEN];
	char h_instruct_personnm[DL_INSTRUCT_PERSONNM_LEN];
	char h_clientof_cd[DL_CLIENTOF_CD_LEN];
	char h_inter_med_person[DL_INTER_MED_PERSON_LEN];
	char h_inter_med_personnm[DL_INTER_MED_PERSONNM_LEN];
	char h_fxccy[DL_FXCCY_LEN];
	char h_uniq_ident_no[DL_UNIQ_IDENT_NO_LEN];
	int h_cnt_548;
	char h_exp_setldate[APL_DATE_LEN];
	char h_related_ident_no[DL_RELATED_IDENT_NO_LEN];
	char h_informaton[DL_INFORMATON_LEN];
	double h_comm_amt;/**** For Detailed Bill Printing : vinay kalaskar ***/
	char h_mf_seqno[MF_SEQNO_LEN];/**** For BillGeneration : vinay kalaskar ***/
}DL_SMI_TMP_TRADE_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_cost;
	short i_ex_arena;
	short i_amount;
	short i_custodycomm;
	short i_brokercomm;
	short i_stx_comm;
	short i_oth_comm;
	short i_instrument_dt;
	short i_money_setl_dt;
	short i_qty;
	short i_domestic_cpclt;
	short i_spottrd_ind;
	short i_orig_qty;
	short i_orig_amount;
	short i_deal_frm_ord;
	short i_entry;
	short i_reapired_ind;
	short i_domcp_custodyclt;
	short i_cp_clt;
	short i_cp_cltname;
	short i_clientof;
	short i_client_note;
	short i_fx_reqd;
	short i_payloc_ind;
	short i_verfied_with;
	short i_amt_differ;
	short i_brk_no;
	short i_failreason_cd;
	short i_fail_det;
	short i_partial_ind_b;
	short i_fx_rt;
	short i_amend_count;
	short i_number_a;
	short i_report_at_eom_ind;
	short i_dateofbilling;
	short i_lcl_identno;
	short i_instruct_person;
	short i_rec_int_000;
	short i_deal_cd;
	short i_instr_code;
	short i_currency_cd;
	short i_dl_class;
	short i_orig_refno;
	short i_dateof_input;
	short i_maker;
	short i_maker_dt;
	short i_deal_stat;
	short i_access_stamp;
	short i_info1;
	short i_location_cd;
	short i_reginstr_ind;
	short i_status_pos;
	short i_status_reg;
	short i_val_fdt;
	short i_comprefno;
	short i_dateof_markfail;
	short i_allow_dropdt;
	short i_checker;
	short i_checker_dt;
	short i_instrconv_ind;
	short i_nds_blk_dt;
	short i_lr_dl_class;
	short i_nds_date;
	short i_unblk_date;
	short i_delta_000;
	short i_delta_001;
	short i_delta_003;
	short i_del_rec_date;
	short i_last_reg_date;
	short i_lr_check_date;
	short i_lr_valdate;
	short i_lrinstr_date;
	short i_reg_msg_qty;
	short i_tmp_out_dt;
	short i_tmp_out_date;
	short i_trans_date;
	short i_tot_qty;
	short i_qty_lost;
	short i_mrk_dl_failqty;
	short i_dl_completeqty;
	short i_out_reg_qty;
	short i_pend_reg_qty;
	short i_ret_reg_qty;
	short i_stamp_qty;
	short i_temp_out_quantity;
	short i_temp_ret_quantity;
	short i_val_deed_qty;
	short i_host_date;
	short i_lrnds_billdt;
	short i_lrnds_date;
	short i_lr_unblk_date;
	short i_number_b;
	short i_clt_reqdel_ind;
	short i_mod_hispos_ind;
	short i_mod_hispos_date;
	short i_gl_client;
	short i_cp_amt;
	short i_msg_stat;
	short i_sub_fail_cd;
	short i_partial_ind_a;
	short i_loc_chng_ind;
	short i_comm_ident_no;
	short i_instruct_personnm;
	short i_clientof_cd;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short i_cnt_548;
	short i_exp_setldate;
	short i_related_ident_no;
	short i_informaton;
	short i_comm_amt;/**** For Deatiled Bill Printing : vinay kalaskar ***/
	short i_mf_seqno;/**** For BillGeneration : vinay kalaskar ***/
}DL_SMI_TMP_TRADE_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_LOCATION_CD_LEN 5
#define DL_STATUS_POS_LEN 4


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_status_pos[DL_STATUS_POS_LEN];
	char h_vdp_date[APL_DATE_LEN];
	int h_vdp_pos;
}DL_SUMFUTURE_VDP_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_location_cd;
	short i_status_pos;
	short i_vdp_date;
	short i_vdp_pos;
}DL_SUMFUTURE_VDP_VEW_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7

#define DL_INFORMATION_LEN 31


#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 2001
#define DL_MESSAGE_DET_C_LEN 2001
#define DL_MESSAGE_DET_D_LEN 2001
#define DL_MESSAGE_DET_E_LEN 2001
#define DL_PSETPARTY_LEN 161
#define DL_PLACE_CD_LEN 5
#define DL_NARRATIVE_LEN 41
typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_msg_in_out_ind[DL_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[DL_SWIFT_MSG_NO_LEN];
	char h_date_of_input[APL_DATE_LEN];
	char h_information[DL_INFORMATION_LEN];
	int h_inden_num;
	int h_dl_rep_identno;
	char h_message_det_a[DL_MESSAGE_DET_A_LEN];
	char h_message_det_b[DL_MESSAGE_DET_B_LEN];
	char h_message_det_c[DL_MESSAGE_DET_C_LEN];
	char h_message_det_d[DL_MESSAGE_DET_D_LEN];
	char h_message_det_e[DL_MESSAGE_DET_E_LEN];
	char h_psetparty[DL_PSETPARTY_LEN];
	char h_place_cd[DL_PLACE_CD_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
}DL_TMPMSGLINK_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_date_of_input;
	short i_information;
	short i_inden_num;
	short i_dl_rep_identno;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_psetparty;
	short i_place_cd;
	short i_narrative;
}DL_TMPMSGLINK_STRUCT_I;








#define DL_SEQUENCE_NAME_LEN 6
#define DL_LINK_VAL_LEN 6
#define DL_LINK_TAG_LEN 51


#define DL_MSG_TAG_LEN 6
typedef struct{
	int h_inden_num;
	char h_sequence_name[DL_SEQUENCE_NAME_LEN];
	char h_link_val[DL_LINK_VAL_LEN];
	char h_link_tag[DL_LINK_TAG_LEN];
	int h_msg_tag_rep_no;
	int h_msg_line_no;
	char h_msg_tag[DL_MSG_TAG_LEN];
}DL_TMPMSGLINKDET_STRUCT_H;
typedef struct{
	short i_inden_num;
	short i_sequence_name;
	short i_link_val;
	short i_link_tag;
	short i_msg_tag_rep_no;
	short i_msg_line_no;
	short i_msg_tag;
}DL_TMPMSGLINKDET_STRUCT_I;







#define DL_CLIENT_LEN 11
#define DL_INSTR_CODE_LEN 9


typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_prev_gen_date[APL_DATE_LEN];
	double h_closing_bal;
}DL_WEEKTXNBAL_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_prev_gen_date;
	short i_closing_bal;
}DL_WEEKTXNBAL_STRUCT_I;







#define DW_DETAILS1_LEN 194
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
}DW_ARESPONSE_VEW_STRUCT_H;
typedef struct{
	short i_details1;
}DW_ARESPONSE_VEW_STRUCT_I;







#define DW_DETAILS1_LEN 173
#define DW_DETAILS2_LEN 231
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
	char h_details2[DW_DETAILS2_LEN];
}DW_CACHEQUE_VEW_STRUCT_H;
typedef struct{
	short i_details1;
	short i_details2;
}DW_CACHEQUE_VEW_STRUCT_I;










/*
typedef struct{
	
	
	
	
}DW_CAEVENT_VEW_STRUCT_H;
*/
typedef struct{
	short i_details1;
	short i_details2;
	short i_details3;
	short i_details4;
}DW_CAEVENT_VEW_STRUCT_I;







#define DW_DETAILS1_LEN 56
#define DW_DETAILS2_LEN 1751
#define DW_DETAILS3_LEN 1751
#define DW_DETAILS4_LEN 1751
#define DW_DETAILS5_LEN 1751
#define DW_DETAILS6_LEN 53
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
	char h_details2[DW_DETAILS2_LEN];
	char h_details3[DW_DETAILS3_LEN];
	char h_details4[DW_DETAILS4_LEN];
	char h_details5[DW_DETAILS5_LEN];
	char h_details6[DW_DETAILS6_LEN];
}DW_CANOTE_VEW_STRUCT_H;
typedef struct{
	short i_details1;
	short i_details2;
	short i_details3;
	short i_details4;
	short i_details5;
	short i_details6;
}DW_CANOTE_VEW_STRUCT_I;







#define DW_DETAILS1_LEN 219
#define DW_DETAILS2_LEN 306
#define DW_ALTERNATE_CURRCD_LEN 31
#define DW_DETAILS3_LEN 266
#define DW_DETAILS4_LEN 261
#define DW_DETAILS5_LEN 176
#define DW_DETAILS6_LEN 200
#define DW_DETAILS7_LEN 214
#define DW_DETAILS8_LEN 131
#define DW_DETAILS9_LEN 105
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
	char h_details2[DW_DETAILS2_LEN];
	char h_alternate_currcd[DW_ALTERNATE_CURRCD_LEN];
	char h_details3[DW_DETAILS3_LEN];
	char h_details4[DW_DETAILS4_LEN];
	char h_details5[DW_DETAILS5_LEN];
	char h_details6[DW_DETAILS6_LEN];
	char h_details7[DW_DETAILS7_LEN];
	char h_details8[DW_DETAILS8_LEN];
	char h_details9[DW_DETAILS9_LEN];
}DW_DLDEAL_VEW_STRUCT_H;
typedef struct{
	short i_details1;
	short i_details2;
	short i_alternate_currcd;
	short i_details3;
	short i_details4;
	short i_details5;
	short i_details6;
	short i_details7;
	short i_details8;
	short i_details9;
}DW_DLDEAL_VEW_STRUCT_I;







#define DW_DETAILS1_LEN 195
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
}DW_DLSAFEK_VEW_STRUCT_H;
typedef struct{
	short i_details1;
}DW_DLSAFEK_VEW_STRUCT_I;










/*
typedef struct{
	
	
	
	
}DW_MTCLIENT_VEW_STRUCT_H;
*/
typedef struct{
	short i_details1;
	short i_details2;
	short i_details3;
	short i_details4;
}DW_MTCLIENT_VEW_STRUCT_I;







#define DW_DETAILS1_LEN 134
typedef struct{
	char h_details1[DW_DETAILS1_LEN];
}DW_MTDAILY_MKT_PRICE_VEW_STRUCT_H;
typedef struct{
	short i_details1;
}DW_MTDAILY_MKT_PRICE_VEW_STRUCT_I;










/*
typedef struct{
	
	
	
	
}DW_MTINSTRUMENT_VEW_STRUCT_H;
*/
typedef struct{
	short i_details1;
	short i_details2;
	short i_details3;
	short i_details4;
}DW_MTINSTRUMENT_VEW_STRUCT_I;







#define GN_USERID_LEN 16
#define GN_REC_MODE_LEN 4
#define GN_ENTITY_NAME_LEN 101
#define GN_KEY_VALUE_LEN 501
#define GN_AUDIT_DATA_LEN 4001

#define GN_COMMENTS_LEN 501
typedef struct{
	char h_userid[GN_USERID_LEN];
	char h_rec_mode[GN_REC_MODE_LEN];
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_key_value[GN_KEY_VALUE_LEN];
	char h_audit_data[GN_AUDIT_DATA_LEN];
	char h_log_time[APL_DATE_LEN];
	char h_comments[GN_COMMENTS_LEN];
}GN_AUDIT_LOG_STRUCT_H;
typedef struct{
	short i_userid;
	short i_rec_mode;
	short i_entity_name;
	short i_key_value;
	short i_audit_data;
	short i_log_time;
	short i_comments;
}GN_AUDIT_LOG_STRUCT_I;







#define GN_ENTITY_NAME_LEN 101
#define GN_AUDIT_DATA_LEN 4001
#define GN_KEY_DATA_LEN 501
#define GN_KEY_GRID_DATA_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_audit_data[GN_AUDIT_DATA_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
	char h_key_grid_data[GN_KEY_GRID_DATA_LEN];
}GN_AUDIT_MAP_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_audit_data;
	short i_key_data;
	short i_key_grid_data;
}GN_AUDIT_MAP_STRUCT_I;







#define GN_ENTITY_NAME_LEN 101
#define GN_AUDIT_DATA_LEN 4001
#define GN_KEY_DATA_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_audit_data[GN_AUDIT_DATA_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
}GN_AUDIT_MAP_230106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_audit_data;
	short i_key_data;
}GN_AUDIT_MAP_230106_STRUCT_I;







#define GN_ENTITY_NAME_LEN 101
#define GN_AUDIT_DATA_LEN 4001
#define GN_KEY_DATA_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_audit_data[GN_AUDIT_DATA_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
}GN_AUDIT_MAP_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_audit_data;
	short i_key_data;
}GN_AUDIT_MAP_BAK_STRUCT_I;







#define GN_ENTITY_NAME_LEN 101
#define GN_AUDIT_DATA_LEN 4001
#define GN_KEY_DATA_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_audit_data[GN_AUDIT_DATA_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
}GN_AUDIT_MAP_DUMMY_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_audit_data;
	short i_key_data;
}GN_AUDIT_MAP_DUMMY_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_KEY_DATA_LEN 501
#define GN_ENTITY_CAPTION_LEN 501
#define GN_KEY_COLUMN_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
	char h_entity_caption[GN_ENTITY_CAPTION_LEN];
	char h_key_column[GN_KEY_COLUMN_LEN];
}GN_COMMON_STATUS_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_key_data;
	short i_entity_caption;
	short i_key_column;
}GN_COMMON_STATUS_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_KEY_DATA_LEN 501
#define GN_ENTITY_CAPTION_LEN 501
#define GN_KEY_COLUMN_LEN 501
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_key_data[GN_KEY_DATA_LEN];
	char h_entity_caption[GN_ENTITY_CAPTION_LEN];
	char h_key_column[GN_KEY_COLUMN_LEN];
}GN_COMMON_STATUS_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_key_data;
	short i_entity_caption;
	short i_key_column;
}GN_COMMON_STATUS_BAK_STRUCT_I;







#define GN_PICKLIST_NAME_LEN 51
#define GN_PICKLIST_QUERY_LEN 4001
typedef struct{
	char h_picklist_name[GN_PICKLIST_NAME_LEN];
	char h_picklist_query[GN_PICKLIST_QUERY_LEN];
}GN_CRITERIA_PICKLIST_STRUCT_H;
typedef struct{
	short i_picklist_name;
	short i_picklist_query;
}GN_CRITERIA_PICKLIST_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_PICKLIST_NAME_LEN 51
#define GN_PICKLIST_QUERY_LEN 1001
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_picklist_name[GN_PICKLIST_NAME_LEN];
	char h_picklist_query[GN_PICKLIST_QUERY_LEN];
}GN_ENTITY_PICKLIST_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_picklist_name;
	short i_picklist_query;
}GN_ENTITY_PICKLIST_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_PICKLIST_NAME_LEN 51
#define GN_PICKLIST_QUERY_LEN 1001
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_picklist_name[GN_PICKLIST_NAME_LEN];
	char h_picklist_query[GN_PICKLIST_QUERY_LEN];
}GN_ENTITY_PICKLIST_230106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_picklist_name;
	short i_picklist_query;
}GN_ENTITY_PICKLIST_230106_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_PICKLIST_NAME_LEN 51
#define GN_PICKLIST_QUERY_LEN 1001
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_picklist_name[GN_PICKLIST_NAME_LEN];
	char h_picklist_query[GN_PICKLIST_QUERY_LEN];
}GN_ENTITY_PICKLIST_300106_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_picklist_name;
	short i_picklist_query;
}GN_ENTITY_PICKLIST_300106_STRUCT_I;







#define GN_ENTITY_NAME_LEN 51
#define GN_PICKLIST_NAME_LEN 51
#define GN_PICKLIST_QUERY_LEN 1001
typedef struct{
	char h_entity_name[GN_ENTITY_NAME_LEN];
	char h_picklist_name[GN_PICKLIST_NAME_LEN];
	char h_picklist_query[GN_PICKLIST_QUERY_LEN];
}GN_ENTITY_PICKLIST_BAK_STRUCT_H;
typedef struct{
	short i_entity_name;
	short i_picklist_name;
	short i_picklist_query;
}GN_ENTITY_PICKLIST_BAK_STRUCT_I;







#define IN_B_CCY_LEN 4
#define IN_B_BASIS_LEN 4







#define IN_STATUS_PYMT_LEN 2
#define IN_LATETIME_A_LEN 6

#define IN_LATETIME_B_LEN 6

#define IN_LATETIME_C_LEN 6

#define IN_LATETIME_D_LEN 6
/*
typedef struct{
	char h_b_ccy[IN_B_CCY_LEN];
	char h_b_basis[IN_B_BASIS_LEN];
	int h_late_dl_days_a;
	int h_allowed_wrt_off_amt;
	int h_db_txnrcd;
	int h_cred_txnrcd;
	int h_val_days;
	int h_periodfor_arch;
	int h_pymt_gen_date;
	char h_status_pymt[IN_STATUS_PYMT_LEN];
	char h_latetime_a[IN_LATETIME_A_LEN];
	int h_late_dl_days_b;
	char h_latetime_b[IN_LATETIME_B_LEN];
	int h_late_dl_days_c;
	char h_latetime_c[IN_LATETIME_C_LEN];
	int h_late_dl_days_d;
	char h_latetime_d[IN_LATETIME_D_LEN];
}INVOICE_SYSTEMPARAM_STRUCT_H;
typedef struct{
	short i_b_ccy;
	short i_b_basis;
	short i_late_dl_days_a;
	short i_allowed_wrt_off_amt;
	short i_db_txnrcd;
	short i_cred_txnrcd;
	short i_val_days;
	short i_periodfor_arch;
	short i_pymt_gen_date;
	short i_status_pymt;
	short i_latetime_a;
	short i_late_dl_days_b;
	short i_latetime_b;
	short i_late_dl_days_c;
	short i_latetime_c;
	short i_late_dl_days_d;
	short i_latetime_d;
}INVOICE_SYSTEMPARAM_STRUCT_I;*/







#define IV_CLIENT_LEN 11


#define IV_B_CCYCD_LEN 4


#define IV_MAKER_LEN 15


#define IV_STATUS_PYMT_LEN 2
#define IV_CHECKER_LEN 15

#define IV_PYMT_CLT_LEN 11


#define IV_ADJUST_ENTRY_LEN 2
typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	int h_inden_num;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	double h_conf_amt;
	int h_pay_seq;
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_pymt[IV_STATUS_PYMT_LEN];
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_pymt_clt[IV_PYMT_CLT_LEN];
	char h_ae_dt[APL_DATE_LEN];
	int h_proc_num;
	char h_adjust_entry[IV_ADJUST_ENTRY_LEN];
}IV_ARCHCHEQUE_STRUCT_H;
typedef struct{
	short i_client;
	short i_dateof_payment;
	short i_inden_num;
	short i_b_ccycd;
	short i_conf_amt;
	short i_pay_seq;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_status_pymt;
	short i_checker;
	short i_checker_dt;
	short i_pymt_clt;
	short i_ae_dt;
	short i_proc_num;
	short i_adjust_entry;
}IV_ARCHCHEQUE_STRUCT_I;








#define IV_CLIENT_LEN 11
#define IV_INSTR_CODE_LEN 9
#define IV_PARAMETER_CD_LEN 201
#define IV_PROC_DATA_VAL_LEN 201

#define IV_CURRENCY_CD_LEN 4

#define IV_CONS_FLAG_LEN 2

typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	char h_instr_code[IV_INSTR_CODE_LEN];
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	double h_mkrtpr;
	char h_currency_cd[IV_CURRENCY_CD_LEN];
	double h_safekeep_pos;
	char h_cons_flag[IV_CONS_FLAG_LEN];
	double h_exchg_rt;
}IV_ARCHCLIENTHOLDING_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_instr_code;
	short i_parameter_cd;
	short i_proc_data_val;
	short i_mkrtpr;
	short i_currency_cd;
	short i_safekeep_pos;
	short i_cons_flag;
	short i_exchg_rt;
}IV_ARCHCLIENTHOLDING_STRUCT_I;







#define IV_FRM_CCYCD_LEN 4
#define IV_TO_CURRENCY_LEN 4


typedef struct{
	char h_frm_ccycd[IV_FRM_CCYCD_LEN];
	char h_to_currency[IV_TO_CURRENCY_LEN];
	double h_exchg_rt;
	char h_dateof_billing[APL_DATE_LEN];
}IV_ARCHEXCHANGERATE_STRUCT_H;
typedef struct{
	short i_frm_ccycd;
	short i_to_currency;
	short i_exchg_rt;
	short i_dateof_billing;
}IV_ARCHEXCHANGERATE_STRUCT_I;







#define IV_CLIENT_LEN 11



#define IV_MAKER_LEN 15


#define IV_SERVICE_DET_LEN 22

#define IV_SERVICE_STAT_LEN 2
#define IV_CHECKER_LEN 15


typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_b_upto_date[APL_DATE_LEN];
	double h_service_qty;
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_service_det[IV_SERVICE_DET_LEN];
	double h_schdl_fee;
	char h_service_stat[IV_SERVICE_STAT_LEN];
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	int h_inden_num;
}IV_ARCHEXTRASERVICE_STRUCT_H;
typedef struct{
	short i_client;
	short i_service_cd;
	short i_b_upto_date;
	short i_service_qty;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_service_det;
	short i_schdl_fee;
	short i_service_stat;
	short i_checker;
	short i_checker_dt;
	short i_inden_num;
}IV_ARCHEXTRASERVICE_STRUCT_I;








#define IV_CLIENT_LEN 11





#define IV_CLASS_IND_LEN 2
#define IV_B_CCYCD_LEN 4
typedef struct{
	int h_service_cd;
	char h_client[IV_CLIENT_LEN];
	char h_dateof_doc[APL_DATE_LEN];
	int h_inden_num;
	double h_service_amt;
	double h_run_balance;
	double h_out_stand_amt;
	char h_class_ind[IV_CLASS_IND_LEN];
	char h_b_ccycd[IV_B_CCYCD_LEN];
}IV_ARCHLEDGER_STRUCT_H;
typedef struct{
	short i_service_cd;
	short i_client;
	short i_dateof_doc;
	short i_inden_num;
	short i_service_amt;
	short i_run_balance;
	short i_out_stand_amt;
	short i_class_ind;
	short i_b_ccycd;
}IV_ARCHLEDGER_STRUCT_I;







#define IV_CLIENT_LEN 11


typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_dateof_billing[APL_DATE_LEN];
	double h_b_outs_amount;
}IV_ARCHOUTSTANDINGAMT_STRUCT_H;
typedef struct{
	short i_client;
	short i_dateof_billing;
	short i_b_outs_amount;
}IV_ARCHOUTSTANDINGAMT_STRUCT_I;








#define IV_CLIENT_LEN 11




#define IV_B_CCYCD_LEN 4
#define IV_CONS_FLAG_LEN 2

#define IV_MASTER_CLT_LEN 11
typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	double h_nil_fees_adj;
	double h_minimumfee_adj;
	double h_maximum_fee_adj;
	double h_comm_amt;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	char h_cons_flag[IV_CONS_FLAG_LEN];
	int h_service_cd;
	char h_master_clt[IV_MASTER_CLT_LEN];
}IV_ARCHSERVICECHG_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_nil_fees_adj;
	short i_minimumfee_adj;
	short i_maximum_fee_adj;
	short i_comm_amt;
	short i_b_ccycd;
	short i_cons_flag;
	short i_service_cd;
	short i_master_clt;
}IV_ARCHSERVICECHG_STRUCT_I;








#define IV_CLIENT_LEN 11

#define IV_CONS_FLAG_LEN 2
#define IV_PARAMETER_CD_LEN 201
#define IV_PROC_DATA_VAL_LEN 201


#define IV_B_CCYCD_LEN 4

#define IV_MASTER_CLT_LEN 11
#define IV_GROUP_ID_LEN 51
typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_cons_flag[IV_CONS_FLAG_LEN];
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	double h_comm_amt;
	double h_chrg_quant;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	double h_fees_qty;
	char h_master_clt[IV_MASTER_CLT_LEN];
	char h_group_id[IV_GROUP_ID_LEN];
}IV_ARCHTRANSACTION_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_service_cd;
	short i_cons_flag;
	short i_parameter_cd;
	short i_proc_data_val;
	short i_comm_amt;
	short i_chrg_quant;
	short i_b_ccycd;
	short i_fees_qty;
	short i_master_clt;
	short i_group_id;
}IV_ARCHTRANSACTION_STRUCT_I;







#define IV_CLIENT_LEN 11


typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_dateof_billing[APL_DATE_LEN];
	int h_iv_seqno;
}IV_BILL_STRUCT_H;
typedef struct{
	short i_client;
	short i_dateof_billing;
	short i_iv_seqno;
}IV_BILL_STRUCT_I;







#define IV_CLIENT_LEN 11


#define IV_B_CCYCD_LEN 4


#define IV_MAKER_LEN 15


#define IV_STATUS_PYMT_LEN 2
#define IV_CHECKER_LEN 15

#define IV_PYMT_CLT_LEN 11


#define IV_ADJUST_ENTRY_LEN 2
typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_dateof_payment[APL_DATE_LEN];
	int h_inden_num;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	double h_conf_amt;
	int h_pay_seq;
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_pymt[IV_STATUS_PYMT_LEN];
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_pymt_clt[IV_PYMT_CLT_LEN];
	char h_ae_dt[APL_DATE_LEN];
	int h_proc_num;
	char h_adjust_entry[IV_ADJUST_ENTRY_LEN];
}IV_CHEQUE_STRUCT_H;
typedef struct{
	short i_client;
	short i_dateof_payment;
	short i_inden_num;
	short i_b_ccycd;
	short i_conf_amt;
	short i_pay_seq;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_status_pymt;
	short i_checker;
	short i_checker_dt;
	short i_pymt_clt;
	short i_ae_dt;
	short i_proc_num;
	short i_adjust_entry;
}IV_CHEQUE_STRUCT_I;







#define IV_CLIENT_LEN 11




#define IV_STATUS_PAYDET_LEN 2
typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_inden_num;
	char h_dateof_payment[APL_DATE_LEN];
	int h_service_cd;
	double h_service_amt;
	char h_status_paydet[IV_STATUS_PAYDET_LEN];
}IV_CHEQUE_DET_STRUCT_H;
typedef struct{
	short i_client;
	short i_inden_num;
	short i_dateof_payment;
	short i_service_cd;
	short i_service_amt;
	short i_status_paydet;
}IV_CHEQUE_DET_STRUCT_I;







#define IV_COMM_A_LEN 11
#define IV_PAYACC_A_LEN 11
#define IV_MAKER_LEN 15


#define IV_CHECKER_LEN 15

#define IV_COMM_B_LEN 11
#define IV_COMM_C_LEN 11
#define IV_COMM_D_LEN 11
#define IV_COMM_E_LEN 11
#define IV_COMM_F_LEN 11
#define IV_COMM_G_LEN 11
#define IV_COMM_H_LEN 11
#define IV_COMM_I_LEN 11
#define IV_TAX_ACC_LEN 11
#define IV_PAYACC_B_LEN 11
typedef struct{
	char h_comm_a[IV_COMM_A_LEN];
	char h_payacc_a[IV_PAYACC_A_LEN];
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_comm_b[IV_COMM_B_LEN];
	char h_comm_c[IV_COMM_C_LEN];
	char h_comm_d[IV_COMM_D_LEN];
	char h_comm_e[IV_COMM_E_LEN];
	char h_comm_f[IV_COMM_F_LEN];
	char h_comm_g[IV_COMM_G_LEN];
	char h_comm_h[IV_COMM_H_LEN];
	char h_comm_i[IV_COMM_I_LEN];
	char h_tax_acc[IV_TAX_ACC_LEN];
	char h_payacc_b[IV_PAYACC_B_LEN];
}IV_CLIENT_STRUCT_H;
typedef struct{
	short i_comm_a;
	short i_payacc_a;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_comm_b;
	short i_comm_c;
	short i_comm_d;
	short i_comm_e;
	short i_comm_f;
	short i_comm_g;
	short i_comm_h;
	short i_comm_i;
	short i_tax_acc;
	short i_payacc_b;
}IV_CLIENT_STRUCT_I;







#define IV_CLIENT_LEN 11

#define IV_PROC_DATA_VAL_LEN 201
#define IV_GROUP_ID_LEN 51





#define IV_SERVICE_STAT_LEN 2
typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	char h_group_id[IV_GROUP_ID_LEN];
	double h_schdl_fee;
	double h_frm_cbase;
	double h_toc_base;
	double h_frm_fbase;
	double h_tof_base;
	char h_service_stat[IV_SERVICE_STAT_LEN];
}IV_CLIENTFEE_STRUCT_H;
typedef struct{
	short i_client;
	short i_service_cd;
	short i_proc_data_val;
	short i_group_id;
	short i_schdl_fee;
	short i_frm_cbase;
	short i_toc_base;
	short i_frm_fbase;
	short i_tof_base;
	short i_service_stat;
}IV_CLIENTFEE_STRUCT_I;








#define IV_CLIENT_LEN 11
#define IV_INSTR_CODE_LEN 9
#define IV_PARAMETER_CD_LEN 201
#define IV_PROC_DATA_VAL_LEN 201

#define IV_CURRENCY_CD_LEN 4

#define IV_CONS_FLAG_LEN 2

typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	char h_instr_code[IV_INSTR_CODE_LEN];
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	double h_mkrtpr;
	char h_currency_cd[IV_CURRENCY_CD_LEN];
	double h_safekeep_pos;
	char h_cons_flag[IV_CONS_FLAG_LEN];
	double h_exchg_rt;
}IV_CLIENTHOLDING_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_instr_code;
	short i_parameter_cd;
	short i_proc_data_val;
	short i_mkrtpr;
	short i_currency_cd;
	short i_safekeep_pos;
	short i_cons_flag;
	short i_exchg_rt;
}IV_CLIENTHOLDING_STRUCT_I;







#define IV_CLIENT_LEN 11

#define IV_PARAMETER_CD_LEN 201
typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
}IV_CLIENTPARAM_STRUCT_H;
typedef struct{
	short i_client;
	short i_service_cd;
	short i_parameter_cd;
}IV_CLIENTPARAM_STRUCT_I;







#define IV_CLIENT_LEN 11
#define IV_B_CCYCD_LEN 4
#define IV_SEND_TO_MASTER_IND_LEN 2
#define IV_B_GEN_IND_LEN 2


#define IV_MINIMUMFEE_TO_LEN 2
#define IV_MIN_HLD_ADJ_LEN 2
#define IV_MAKER_LEN 15


#define IV_DIR_DB_IND_LEN 2
#define IV_STAT_IND_LEN 2
#define IV_SPL_CLT_CD_LEN 7
#define IV_COMM_CLT_LEN 11
#define IV_REC_CLT_LEN 11
#define IV_INFORMATION_LEN 241
#define IV_DEFAULT_FEECLT_LEN 11


#define IV_LAST_PYMT_CCY_LEN 4


#define IV_CHECKER_LEN 15


#define IV_FEES_CCY_LEN 4
#define IV_VAT_CD_LEN 51
#define IV_VAT_NOTE_LEN 121
typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_b_ccycd[IV_B_CCYCD_LEN];
	char h_send_to_master_ind[IV_SEND_TO_MASTER_IND_LEN];
	char h_b_gen_ind[IV_B_GEN_IND_LEN];
	double h_minimumfee;
	char h_date_of_input[APL_DATE_LEN];
	char h_minimumfee_to[IV_MINIMUMFEE_TO_LEN];
	char h_min_hld_adj[IV_MIN_HLD_ADJ_LEN];
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_dir_db_ind[IV_DIR_DB_IND_LEN];
	char h_stat_ind[IV_STAT_IND_LEN];
	char h_spl_clt_cd[IV_SPL_CLT_CD_LEN];
	char h_comm_clt[IV_COMM_CLT_LEN];
	char h_rec_clt[IV_REC_CLT_LEN];
	char h_information[IV_INFORMATION_LEN];
	char h_default_feeclt[IV_DEFAULT_FEECLT_LEN];
	double h_total_osamount;
	char h_last_pymt_date[APL_DATE_LEN];
	char h_last_pymt_ccy[IV_LAST_PYMT_CCY_LEN];
	double h_last_pymt_amt;
	double h_last_lost_amt;
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	double h_comm_tax_amt;
	char h_fees_ccy[IV_FEES_CCY_LEN];
	char h_vat_cd[IV_VAT_CD_LEN];
	char h_vat_note[IV_VAT_NOTE_LEN];
}IV_CLIENTSETUP_STRUCT_H;
typedef struct{
	short i_client;
	short i_b_ccycd;
	short i_send_to_master_ind;
	short i_b_gen_ind;
	short i_minimumfee;
	short i_date_of_input;
	short i_minimumfee_to;
	short i_min_hld_adj;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_dir_db_ind;
	short i_stat_ind;
	short i_spl_clt_cd;
	short i_comm_clt;
	short i_rec_clt;
	short i_information;
	short i_default_feeclt;
	short i_total_osamount;
	short i_last_pymt_date;
	short i_last_pymt_ccy;
	short i_last_pymt_amt;
	short i_last_lost_amt;
	short i_checker;
	short i_checker_dt;
	short i_comm_tax_amt;
	short i_fees_ccy;
	short i_vat_cd;
	short i_vat_note;
}IV_CLIENTSETUP_STRUCT_I;







#define IV_CLIENT_LEN 11

#define IV_FEES_BASE_LEN 31
#define IV_CHRG_BASE_LEN 31
#define IV_CHRG_CLAS_LEN 2
#define IV_FEES_CLASS_LEN 2



#define IV_DEALADM_FEECCY_LEN 4
typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_fees_base[IV_FEES_BASE_LEN];
	char h_chrg_base[IV_CHRG_BASE_LEN];
	char h_chrg_clas[IV_CHRG_CLAS_LEN];
	char h_fees_class[IV_FEES_CLASS_LEN];
	double h_minimumfee;
	double h_nil_fees;
	double h_maximum_fee;
	char h_dealadm_feeccy[IV_DEALADM_FEECCY_LEN];
}IV_CLIENT_SERV_BASIS_STRUCT_H;
typedef struct{
	short i_client;
	short i_service_cd;
	short i_fees_base;
	short i_chrg_base;
	short i_chrg_clas;
	short i_fees_class;
	short i_minimumfee;
	short i_nil_fees;
	short i_maximum_fee;
	short i_dealadm_feeccy;
}IV_CLIENT_SERV_BASIS_STRUCT_I;







#define IV_PARAMETER_CD_LEN 31
#define IV_GROUP_PRM_CD_LEN 31
#define IV_GROUP_MEM_VAL_LEN 31
typedef struct{
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_group_prm_cd[IV_GROUP_PRM_CD_LEN];
	char h_group_mem_val[IV_GROUP_MEM_VAL_LEN];
}IV_DATA_GRP_STRUCT_H;
typedef struct{
	short i_parameter_cd;
	short i_group_prm_cd;
	short i_group_mem_val;
}IV_DATA_GRP_STRUCT_I;








#define IV_CLIENT_LEN 11

#define IV_CONS_FLAG_LEN 2
#define IV_PARAMETER_CD_LEN 201
#define IV_PROC_DATA_VAL_LEN 201


#define IV_B_CCYCD_LEN 4

#define IV_MASTER_CLT_LEN 11
#define IV_GROUP_ID_LEN 51
typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_cons_flag[IV_CONS_FLAG_LEN];
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	double h_comm_amt;
	double h_chrg_quant;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	double h_fees_qty;
	char h_master_clt[IV_MASTER_CLT_LEN];
	char h_group_id[IV_GROUP_ID_LEN];
}IV_DEAL_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_service_cd;
	short i_cons_flag;
	short i_parameter_cd;
	short i_proc_data_val;
	short i_comm_amt;
	short i_chrg_quant;
	short i_b_ccycd;
	short i_fees_qty;
	short i_master_clt;
	short i_group_id;
}IV_DEAL_STRUCT_I;








#define IV_CLIENT_LEN 11

#define IV_CONS_FLAG_LEN 2
#define IV_PARAMETER_CD_LEN 201

#define IV_PROC_DATA_VAL_LEN 201


#define IV_B_CCYCD_LEN 4

#define IV_MASTER_CLT_LEN 11
#define IV_GROUP_ID_LEN 51
typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_cons_flag[IV_CONS_FLAG_LEN];
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	double h_comm_amt;
	char h_proc_data_val[IV_PROC_DATA_VAL_LEN];
	double h_schdl_fee;
	double h_chrg_quant;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	double h_fees_qty;
	char h_master_clt[IV_MASTER_CLT_LEN];
	char h_group_id[IV_GROUP_ID_LEN];
}IV_DEAL_FEE_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_service_cd;
	short i_cons_flag;
	short i_parameter_cd;
	short i_comm_amt;
	short i_proc_data_val;
	short i_schdl_fee;
	short i_chrg_quant;
	short i_b_ccycd;
	short i_fees_qty;
	short i_master_clt;
	short i_group_id;
}IV_DEAL_FEE_STRUCT_I;







#define IV_NATION_CD_LEN 3

typedef struct{
	char h_nation_cd[IV_NATION_CD_LEN];
	int h_dl_class;
}IV_DEAL_TYPE_STRUCT_H;
typedef struct{
	short i_nation_cd;
	short i_dl_class;
}IV_DEAL_TYPE_STRUCT_I;







#define IV_FRM_CCYCD_LEN 4
#define IV_TO_CURRENCY_LEN 4


typedef struct{
	char h_frm_ccycd[IV_FRM_CCYCD_LEN];
	char h_to_currency[IV_TO_CURRENCY_LEN];
	double h_exchg_rt;
	char h_dateof_billing[APL_DATE_LEN];
}IV_EXCHANGERATE_STRUCT_H;
typedef struct{
	short i_frm_ccycd;
	short i_to_currency;
	short i_exchg_rt;
	short i_dateof_billing;
}IV_EXCHANGERATE_STRUCT_I;








#define IV_CLIENT_LEN 11





#define IV_CLASS_IND_LEN 2
#define IV_B_CCYCD_LEN 4
typedef struct{
	int h_service_cd;
	char h_client[IV_CLIENT_LEN];
	char h_dateof_doc[APL_DATE_LEN];
	int h_inden_num;
	double h_service_amt;
	double h_run_balance;
	double h_out_stand_amt;
	char h_class_ind[IV_CLASS_IND_LEN];
	char h_b_ccycd[IV_B_CCYCD_LEN];
}IV_LEDGER_STRUCT_H;
typedef struct{
	short i_service_cd;
	short i_client;
	short i_dateof_doc;
	short i_inden_num;
	short i_service_amt;
	short i_run_balance;
	short i_out_stand_amt;
	short i_class_ind;
	short i_b_ccycd;
}IV_LEDGER_STRUCT_I;





















/*

typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}IV_LEDGER_VW_STRUCT_H;
*/
typedef struct{
	short i_current_date;
	short i_ca_identname;
	short i_dateof_doc;
	short i_dir_indir_fxqt_ind;
	short i_b_ccycd;
	short i_service_cd;
	short i_client;
	short i_gl_ccy;
	short i_service_det;
	short i_master_clt;
	short i_clnt_name;
	short i_out_stand_amt;
	short i_total_osamount;
	short i_total_rep_osamount;
	short i_rep_os_amount;
	short i_exchg;
}IV_LEDGER_VW_STRUCT_I;







#define IV_CLIENT_LEN 11


typedef struct{
	char h_client[IV_CLIENT_LEN];
	char h_dateof_billing[APL_DATE_LEN];
	double h_b_outs_amount;
}IV_OUTSTANDINGAMT_STRUCT_H;
typedef struct{
	short i_client;
	short i_dateof_billing;
	short i_b_outs_amount;
}IV_OUTSTANDINGAMT_STRUCT_I;







#define IV_CLIENT_LEN 11
typedef struct{
	char h_client[IV_CLIENT_LEN];
}IV_SELCLIENT_STRUCT_H;
typedef struct{
	short i_client;
}IV_SELCLIENT_STRUCT_I;








#define IV_CLIENT_LEN 11




#define IV_B_CCYCD_LEN 4
#define IV_CONS_FLAG_LEN 2

#define IV_MASTER_CLT_LEN 11
typedef struct{
	char h_dateof_billing[APL_DATE_LEN];
	char h_client[IV_CLIENT_LEN];
	double h_nil_fees_adj;
	double h_minimumfee_adj;
	double h_maximum_fee_adj;
	double h_comm_amt;
	char h_b_ccycd[IV_B_CCYCD_LEN];
	char h_cons_flag[IV_CONS_FLAG_LEN];
	int h_service_cd;
	char h_master_clt[IV_MASTER_CLT_LEN];
	char h_incld_in_ann_min_fee[IV_CONS_FLAG_LEN];
}IV_SERVICE_CHRG_STRUCT_H;
typedef struct{
	short i_dateof_billing;
	short i_client;
	short i_nil_fees_adj;
	short i_minimumfee_adj;
	short i_maximum_fee_adj;
	short i_comm_amt;
	short i_b_ccycd;
	short i_cons_flag;
	short i_service_cd;
	short i_master_clt;
	short i_incld_in_ann_min_fee;
}IV_SERVICE_CHRG_STRUCT_I;








#define IV_FEES_BASE_LEN 31
#define IV_IV_COND_LEN 5
#define IV_CHRG_BASE_LEN 31
#define IV_CHRG_VL_CLAS_LEN 2
#define IV_FEES_VAL_CLASS_LEN 2
typedef struct{
	int h_service_cd;
	char h_fees_base[IV_FEES_BASE_LEN];
	char h_iv_cond[IV_IV_COND_LEN];
	char h_chrg_base[IV_CHRG_BASE_LEN];
	char h_chrg_vl_clas[IV_CHRG_VL_CLAS_LEN];
	char h_fees_val_class[IV_FEES_VAL_CLASS_LEN];
}IV_SERV_BASIS_STRUCT_H;
typedef struct{
	short i_service_cd;
	short i_fees_base;
	short i_iv_cond;
	short i_chrg_base;
	short i_chrg_vl_clas;
	short i_fees_val_class;
}IV_SERV_BASIS_STRUCT_I;








#define IV_PARAMETER_CD_LEN 31
#define IV_INFO_TYPE_LEN 16


#define IV_IV_COND_LEN 31
#define IV_VALIDATE_PROC_LEN 31
#define IV_HELP_FUNCTION_LEN 31
typedef struct{
	int h_service_cd;
	char h_parameter_cd[IV_PARAMETER_CD_LEN];
	char h_info_type[IV_INFO_TYPE_LEN];
	int h_info_width;
	int h_info_dec;
	char h_iv_cond[IV_IV_COND_LEN];
	char h_validate_proc[IV_VALIDATE_PROC_LEN];
	char h_help_function[IV_HELP_FUNCTION_LEN];
}IV_SERV_DEPEND_STRUCT_H;
typedef struct{
	short i_service_cd;
	short i_parameter_cd;
	short i_info_type;
	short i_info_width;
	short i_info_dec;
	short i_iv_cond;
	short i_validate_proc;
	short i_help_function;
}IV_SERV_DEPEND_STRUCT_I;








#define IV_SERVICE_DET_LEN 21
#define IV_FEES_CLASS_LEN 2

#define IV_STD_FEEIND_LEN 2
#define IV_MASTSUB_IND_LEN 2

#define IV_VALID_FEE_CLASS_LEN 2
#define IV_B_CLIENT_LEN 11
typedef struct{
	int h_service_cd;
	char h_service_det[IV_SERVICE_DET_LEN];
	char h_fees_class[IV_FEES_CLASS_LEN];
	double h_minimum_fee;
	char h_std_feeind[IV_STD_FEEIND_LEN];
	char h_mastsub_ind[IV_MASTSUB_IND_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_valid_fee_class[IV_VALID_FEE_CLASS_LEN];
	char h_b_client[IV_B_CLIENT_LEN];
}IV_SERV_MAST_STRUCT_H;
typedef struct{
	short i_service_cd;
	short i_service_det;
	short i_fees_class;
	short i_minimum_fee;
	short i_std_feeind;
	short i_mastsub_ind;
	short i_access_stamp;
	short i_valid_fee_class;
	short i_b_client;
}IV_SERV_MAST_STRUCT_I;







#define IV_CLIENT_LEN 11



#define IV_MAKER_LEN 15


#define IV_SERVICE_DET_LEN 22

#define IV_SERVICE_STAT_LEN 2
#define IV_CHECKER_LEN 15


typedef struct{
	char h_client[IV_CLIENT_LEN];
	int h_service_cd;
	char h_b_upto_date[APL_DATE_LEN];
	double h_service_qty;
	char h_maker[IV_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_service_det[IV_SERVICE_DET_LEN];
	double h_schdl_fee;
	char h_service_stat[IV_SERVICE_STAT_LEN];
	char h_checker[IV_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	int h_inden_num;
}IV_SERV_OTH_STRUCT_H;
typedef struct{
	short i_client;
	short i_service_cd;
	short i_b_upto_date;
	short i_service_qty;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_service_det;
	short i_schdl_fee;
	short i_service_stat;
	short i_checker;
	short i_checker_dt;
	short i_inden_num;
}IV_SERV_OTH_STRUCT_I;























/*
typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}IV_SUPERVISIONFEEGRP_VEW_STRUCT_H;
*/
typedef struct{
	short i_master_clt;
	short i_mastdesc;
	short i_client;
	short i_clnt_name;
	short i_dateof_input;
	short i_instr_code;
	short i_instr_prtval;
	short i_dom_prt_value;
	short i_sec_ccy;
	short i_domestic_ccy;
	short i_clt_exgrt;
	short i_cltfee_cd;
	short i_mastexgrt;
	short i_master_feeccy;
	short i_ca_identname;
	short i_current_date;
	short i_quart_num;
}IV_SUPERVISIONFEEGRP_VEW_STRUCT_I;







#define MA_INSTR_STATCD_LEN 3
#define MA_STATUS_QUAL_IND_LEN 5
#define MA_STATUS_CD_LEN 7
#define MA_REASON_QL_LEN 7
#define MA_REASON_CD_LEN 5
#define MA_STATUS_DET_LEN 101
#define MA_SUPPORT_IND_LEN 2
typedef struct{
	char h_instr_statcd[MA_INSTR_STATCD_LEN];
	char h_status_qual_ind[MA_STATUS_QUAL_IND_LEN];
	char h_status_cd[MA_STATUS_CD_LEN];
	char h_reason_ql[MA_REASON_QL_LEN];
	char h_reason_cd[MA_REASON_CD_LEN];
	char h_status_det[MA_STATUS_DET_LEN];
	char h_support_ind[MA_SUPPORT_IND_LEN];
}MASTATUS_STRUCT_H;
typedef struct{
	short i_instr_statcd;
	short i_status_qual_ind;
	short i_status_cd;
	short i_reason_ql;
	short i_reason_cd;
	short i_status_det;
	short i_support_ind;
}MASTATUS_STRUCT_I;








#define MA_MAKER_DT_LEN 13
#define MA_CHECKER_DT_LEN 13
#define MA_AUDIT_DATA_LEN 51
typedef struct{
	char h_access_stamp[APL_DATE_LEN];
	char h_maker_dt[MA_MAKER_DT_LEN];
	char h_checker_dt[MA_CHECKER_DT_LEN];
	char h_audit_data[MA_AUDIT_DATA_LEN];
}MAUDIT_TRACK_STRUCT_H;
typedef struct{
	short i_access_stamp;
	short i_maker_dt;
	short i_checker_dt;
	short i_audit_data;
}MAUDIT_TRACK_STRUCT_I;







#define MH_MHLP_CODE_LEN 13
#define MH_LCL_BRKCD_LEN 11
#define MH_LCL_OPCD_LEN 11
#define MH_CLIENT_LEN 11
#define MH_MASTER_CLT_LEN 11
#define MH_CUSTODIAN_CLT_LEN 11
#define MH_MANUAL_IND_LEN 2
#define MH_MAKER_LEN 15

#define MH_CHECKER_LEN 15

#define MH_MHLP_STAT_LEN 3

#define MH_LCL_BRK_MAST_LEN 11
typedef struct{
	char h_mhlp_code[MH_MHLP_CODE_LEN];
	char h_lcl_brkcd[MH_LCL_BRKCD_LEN];
	char h_lcl_opcd[MH_LCL_OPCD_LEN];
	char h_client[MH_CLIENT_LEN];
	char h_master_clt[MH_MASTER_CLT_LEN];
	char h_custodian_clt[MH_CUSTODIAN_CLT_LEN];
	char h_manual_ind[MH_MANUAL_IND_LEN];
	char h_maker[MH_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MH_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_mhlp_stat[MH_MHLP_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_lcl_brk_mast[MH_LCL_BRK_MAST_LEN];
}MHLP_CODE_STRUCT_H;
typedef struct{
	short i_mhlp_code;
	short i_lcl_brkcd;
	short i_lcl_opcd;
	short i_client;
	short i_master_clt;
	short i_custodian_clt;
	short i_manual_ind;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_mhlp_stat;
	short i_access_stamp;
	short i_lcl_brk_mast;
}MHLP_CODE_STRUCT_I;







#define MM_INSTR_CODE_LEN 9


#define MM_DIR_INDIR_FXQT_IND_LEN 2
typedef struct{
	char h_instr_code[MM_INSTR_CODE_LEN];
	char h_price_date[APL_DATE_LEN];
	double h_closing_pr;
	char h_dir_indir_fxqt_ind[MM_DIR_INDIR_FXQT_IND_LEN];
}MMARKETRATE_VW_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_price_date;
	short i_closing_pr;
	short i_dir_indir_fxqt_ind;
}MMARKETRATE_VW_STRUCT_I;







#define MS_CLIENT_LEN 11
#define MS_MESSAGE_IND_LEN 61
#define MS_SWIFT_MSG_NO_LEN 7
#define MS_MAKER_LEN 15

#define MS_STATUS_IND_LEN 2
#define MS_MSG_IN_OUT_IND_LEN 2
#define MS_MSG_LEN 31
#define MS_CONTACT_DETAILS_LEN 15
#define MS_CONTACT_DETAILS1_LEN 15
#define MS_BASEID_LEN 7
#define MS_MESSAGE_CLASS_LEN 2
#define MS_SWIFT_MSG_IDENT_LEN 17
typedef struct{
	char h_client[MS_CLIENT_LEN];
	char h_message_ind[MS_MESSAGE_IND_LEN];
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_maker[MS_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_status_ind[MS_STATUS_IND_LEN];
	char h_msg_in_out_ind[MS_MSG_IN_OUT_IND_LEN];
	char h_msg[MS_MSG_LEN];
	char h_contact_details[MS_CONTACT_DETAILS_LEN];
	char h_contact_details1[MS_CONTACT_DETAILS1_LEN];
	char h_baseid[MS_BASEID_LEN];
	char h_message_class[MS_MESSAGE_CLASS_LEN];
	char h_swift_msg_ident[MS_SWIFT_MSG_IDENT_LEN];
}MS_ARCHMSGLOG_STRUCT_H;
typedef struct{
	short i_client;
	short i_message_ind;
	short i_swift_msg_no;
	short i_maker;
	short i_maker_dt;
	short i_status_ind;
	short i_msg_in_out_ind;
	short i_msg;
	short i_contact_details;
	short i_contact_details1;
	short i_baseid;
	short i_message_class;
	short i_swift_msg_ident;
}MS_ARCHMSGLOG_STRUCT_I;







#define MS_PROC_INIT_LEN 61
#define MS_SWIFT_MSG_REP_LEN 61
#define MS_CLIENT_LEN 11

typedef struct{
	char h_proc_init[MS_PROC_INIT_LEN];
	char h_swift_msg_rep[MS_SWIFT_MSG_REP_LEN];
	char h_client[MS_CLIENT_LEN];
	char h_generate_dt[APL_DATE_LEN];
}MS_ARCHMSGSTAT_STRUCT_H;
typedef struct{
	short i_proc_init;
	short i_swift_msg_rep;
	short i_client;
	short i_generate_dt;
}MS_ARCHMSGSTAT_STRUCT_I;







#define MS_BASEID_LEN 7
#define MS_CONTACT_DETAILS_LEN 15
#define MS_SWIFT_TLX_GCN_LEN 2

typedef struct{
	char h_baseid[MS_BASEID_LEN];
	char h_contact_details[MS_CONTACT_DETAILS_LEN];
	char h_swift_tlx_gcn[MS_SWIFT_TLX_GCN_LEN];
	char h_access_stamp[APL_DATE_LEN];
}MS_BASE_STRUCT_H;
typedef struct{
	short i_baseid;
	short i_contact_details;
	short i_swift_tlx_gcn;
	short i_access_stamp;
}MS_BASE_STRUCT_I;







#define MS_MESSAGE_CLASS_LEN 2
#define MS_SWIFT_MSG_NO_LEN 7
#define MS_MSG_TAG_LEN 6

#define MS_INFO_TYPE_LEN 2
#define MS_INFO_ELEM_LEN 31
#define MS_HEAD_CONT_NEWLINE_LEN 2
#define MS_MSG_TAG_COND_LEN 201

#define MS_PRINT_CD_LEN 2
typedef struct{
	char h_message_class[MS_MESSAGE_CLASS_LEN];
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_msg_tag[MS_MSG_TAG_LEN];
	int h_identity_no;
	char h_info_type[MS_INFO_TYPE_LEN];
	char h_info_elem[MS_INFO_ELEM_LEN];
	char h_head_cont_newline[MS_HEAD_CONT_NEWLINE_LEN];
	char h_msg_tag_cond[MS_MSG_TAG_COND_LEN];
	int h_srl_num;
	char h_print_cd[MS_PRINT_CD_LEN];
}MS_DETAILSMAP_STRUCT_H;
typedef struct{
	short i_message_class;
	short i_swift_msg_no;
	short i_msg_tag;
	short i_identity_no;
	short i_info_type;
	short i_info_elem;
	short i_head_cont_newline;
	short i_msg_tag_cond;
	short i_srl_num;
	short i_print_cd;
}MS_DETAILSMAP_STRUCT_I;







#define MS_PROC_INIT_LEN 61
#define MS_SWIFT_MSG_REP_LEN 61
#define MS_CLIENT_LEN 11


typedef struct{
	char h_proc_init[MS_PROC_INIT_LEN];
	char h_swift_msg_rep[MS_SWIFT_MSG_REP_LEN];
	char h_client[MS_CLIENT_LEN];
	char h_generate_dt[APL_DATE_LEN];
	char h_dateof_drop[APL_DATE_LEN];
}MS_HISMSGSTAT_STRUCT_H;
typedef struct{
	short i_proc_init;
	short i_swift_msg_rep;
	short i_client;
	short i_generate_dt;
	short i_dateof_drop;
}MS_HISMSGSTAT_STRUCT_I;









#define MS_SWIFT_MSG_NO_LEN 4
#define MS_NAMEOF_FILE_LEN 31
#define MS_MESSAGE_STAT_LEN 4
#define MS_REJECT_REASON_LEN 81
#define MS_REPORT_IND_LEN 2

#define MS_CLIENT_LEN 11
#define MS_SFE_IDENTITY_NO_LEN 11
typedef struct{
	int h_srl_num;
	char h_report_dt[APL_DATE_LEN];
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_nameof_file[MS_NAMEOF_FILE_LEN];
	char h_message_stat[MS_MESSAGE_STAT_LEN];
	char h_reject_reason[MS_REJECT_REASON_LEN];
	char h_report_ind[MS_REPORT_IND_LEN];
	char h_setl_dt[APL_DATE_LEN];
	char h_client[MS_CLIENT_LEN];
	char h_sfe_identity_no[MS_SFE_IDENTITY_NO_LEN];
}MS_INMSGRP_STRUCT_H;
typedef struct{
	short i_srl_num;
	short i_report_dt;
	short i_swift_msg_no;
	short i_nameof_file;
	short i_message_stat;
	short i_reject_reason;
	short i_report_ind;
	short i_setl_dt;
	short i_client;
	short i_sfe_identity_no;
}MS_INMSGRP_STRUCT_I;







#define MS_SWIFT_MSG_NO_LEN 7
#define MS_MSG_MAP_NO_LEN 3
#define MS_ISO_MSG_NO_LEN 7
typedef struct{
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_msg_map_no[MS_MSG_MAP_NO_LEN];
	char h_iso_msg_no[MS_ISO_MSG_NO_LEN];
}MS_MSGCRF_STRUCT_H;
typedef struct{
	short i_swift_msg_no;
	short i_msg_map_no;
	short i_iso_msg_no;
}MS_MSGCRF_STRUCT_I;







#define MS_SWIFT_MSG_NO_LEN 7
#define MS_PROC_INIT_LEN 61

#define MS_CLIENT_LEN 11
#define MS_INFO_FILE_LEN 31





#define MS_STATUS_IND_LEN 2
#define MS_AUTO_TRAN_IND_LEN 2
#define MS_PROC_DATA_LEN 201
typedef struct{
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_proc_init[MS_PROC_INIT_LEN];
	int h_swift_msg_seqno;
	char h_client[MS_CLIENT_LEN];
	char h_info_file[MS_INFO_FILE_LEN];
	int h_swift_count;
	int h_telex_count;
	int h_fax_count;
	int h_gcn_count;
	int h_clts_count;
	char h_status_ind[MS_STATUS_IND_LEN];
	char h_auto_tran_ind[MS_AUTO_TRAN_IND_LEN];
	char h_proc_data[MS_PROC_DATA_LEN];
}MS_MSGENT_STRUCT_H;
typedef struct{
	short i_swift_msg_no;
	short i_proc_init;
	short i_swift_msg_seqno;
	short i_client;
	short i_info_file;
	short i_swift_count;
	short i_telex_count;
	short i_fax_count;
	short i_gcn_count;
	short i_clts_count;
	short i_status_ind;
	short i_auto_tran_ind;
	short i_proc_data;
}MS_MSGENT_STRUCT_I;







#define MS_CLIENT_LEN 11
#define MS_MESSAGE_IND_LEN 61
#define MS_SWIFT_MSG_NO_LEN 7
#define MS_MAKER_LEN 15

#define MS_STATUS_IND_LEN 2
#define MS_MSG_IN_OUT_IND_LEN 2
#define MS_MSG_LEN 31
#define MS_CONTACT_DETAILS_LEN 15
#define MS_CONTACT_DETAILS1_LEN 15
#define MS_BASEID_LEN 7
#define MS_MESSAGE_CLASS_LEN 2
#define MS_SWIFT_MSG_IDENT_LEN 17
typedef struct{
	char h_client[MS_CLIENT_LEN];
	char h_message_ind[MS_MESSAGE_IND_LEN];
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_maker[MS_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_status_ind[MS_STATUS_IND_LEN];
	char h_msg_in_out_ind[MS_MSG_IN_OUT_IND_LEN];
	char h_msg[MS_MSG_LEN];
	char h_contact_details[MS_CONTACT_DETAILS_LEN];
	char h_contact_details1[MS_CONTACT_DETAILS1_LEN];
	char h_baseid[MS_BASEID_LEN];
	char h_message_class[MS_MESSAGE_CLASS_LEN];
	char h_swift_msg_ident[MS_SWIFT_MSG_IDENT_LEN];
}MS_MSGLOG_STRUCT_H;
typedef struct{
	short i_client;
	short i_message_ind;
	short i_swift_msg_no;
	short i_maker;
	short i_maker_dt;
	short i_status_ind;
	short i_msg_in_out_ind;
	short i_msg;
	short i_contact_details;
	short i_contact_details1;
	short i_baseid;
	short i_message_class;
	short i_swift_msg_ident;
}MS_MSGLOG_STRUCT_I;







#define MS_PROC_INIT_LEN 61
#define MS_SWIFT_MSG_REP_LEN 61
#define MS_CLIENT_LEN 11

typedef struct{
	char h_proc_init[MS_PROC_INIT_LEN];
	char h_swift_msg_rep[MS_SWIFT_MSG_REP_LEN];
	char h_client[MS_CLIENT_LEN];
	char h_generate_dt[APL_DATE_LEN];
}MS_MSGSTAT_STRUCT_H;
typedef struct{
	short i_proc_init;
	short i_swift_msg_rep;
	short i_client;
	short i_generate_dt;
}MS_MSGSTAT_STRUCT_I;








#define MS_MSG_IN_OUT_IND_LEN 2
#define MS_SWIFT_MSG_NO_LEN 7
#define MS_INFORMATION_LEN 31

#define MS_MESSAGE_DET_A_LEN 2001
#define MS_MESSAGE_DET_B_LEN 4001
#define MS_MESSAGE_DET_C_LEN 4001
#define MS_MESSAGE_DET_D_LEN 4001
#define MS_MESSAGE_DET_E_LEN 4001
#define MS_CLIENT_LEN 11
#define MS_IDENTIY_NO_LEN 17
#define MS_DEAL_RF_IDENT_NO_LEN 17
#define MS_REJECT_REASON_LEN 151

#define MS_REPORT_IND_LEN 2
#define MS_MESSAGE_STAT_LEN 4

typedef struct{
	char h_date_of_input[APL_DATE_LEN];
	char h_msg_in_out_ind[MS_MSG_IN_OUT_IND_LEN];
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_information[MS_INFORMATION_LEN];
	int h_deal_no;
	char h_message_det_a[MS_MESSAGE_DET_A_LEN];
	char h_message_det_b[MS_MESSAGE_DET_B_LEN];
	char h_message_det_c[MS_MESSAGE_DET_C_LEN];
	char h_message_det_d[MS_MESSAGE_DET_D_LEN];
	char h_message_det_e[MS_MESSAGE_DET_E_LEN];
	char h_client[MS_CLIENT_LEN];
	char h_identiy_no[MS_IDENTIY_NO_LEN];
	char h_deal_rf_ident_no[MS_DEAL_RF_IDENT_NO_LEN];
	char h_reject_reason[MS_REJECT_REASON_LEN];
	char h_report_dt[APL_DATE_LEN];
	char h_report_ind[MS_REPORT_IND_LEN];
	char h_message_stat[MS_MESSAGE_STAT_LEN];
	char h_current_date[APL_DATE_LEN];
}MS_MSG_SETL_VEW_STRUCT_H;
typedef struct{
	short i_date_of_input;
	short i_msg_in_out_ind;
	short i_swift_msg_no;
	short i_information;
	short i_deal_no;
	short i_message_det_a;
	short i_message_det_b;
	short i_message_det_c;
	short i_message_det_d;
	short i_message_det_e;
	short i_client;
	short i_identiy_no;
	short i_deal_rf_ident_no;
	short i_reject_reason;
	short i_report_dt;
	short i_report_ind;
	short i_message_stat;
	short i_current_date;
}MS_MSG_SETL_VEW_STRUCT_I;







#define MS_SWIFT_MSG_NO_LEN 7
#define MS_MESSAGE_CLASS_LEN 2

#define MS_SEQ_IND_LEN 3

#define MS_SEQ_CONDITION_LEN 201
typedef struct{
	char h_swift_msg_no[MS_SWIFT_MSG_NO_LEN];
	char h_message_class[MS_MESSAGE_CLASS_LEN];
	int h_identity_no;
	char h_seq_ind[MS_SEQ_IND_LEN];
	int h_par_seqno;
	char h_seq_condition[MS_SEQ_CONDITION_LEN];
}MS_SEQUENCEMAP_STRUCT_H;
typedef struct{
	short i_swift_msg_no;
	short i_message_class;
	short i_identity_no;
	short i_seq_ind;
	short i_par_seqno;
	short i_seq_condition;
}MS_SEQUENCEMAP_STRUCT_I;








#define MT_INSTR_CODE_LEN 13 

#define MT_MODIFYMODE_LEN 2
#define MT_MAKER_LEN 15

#define MT_MRKTPR_STAT_LEN 3
#define MT_CHECKER_LEN 15

typedef struct{
	char h_price_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_closing_pr;
	char h_modifymode[MT_MODIFYMODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_mrktpr_stat[MT_MRKTPR_STAT_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
}MT_ARCHDLYMKTPRC_STRUCT_H;
typedef struct{
	short i_price_date;
	short i_instr_code;
	short i_closing_pr;
	short i_modifymode;
	short i_maker;
	short i_maker_dt;
	short i_mrktpr_stat;
	short i_checker;
	short i_checker_dt;
}MT_ARCHDLYMKTPRC_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_CURRENCY_LEN 4
#define MT_CLN_OUR_THEIR_IND_LEN 2
#define MT_CLN_ISCC_IND_LEN 2
#define MT_CLN_USE_ISIN_IND_LEN 2
#define MT_CLN_TYPE_LEN 5
#define MT_CLN_REG_NAME_LEN 81
#define MT_CLN_CLAS_LEN 3
#define MT_CLN_BILLABLEIND_LEN 2
#define MT_CLN_CLASS_LEN 2
#define MT_CLN_VTB_CLIENT_LEN 11
#define MT_CLN_REG_LEN 13
#define MT_CLN_MEMO_LEN 201
#define MT_CLN_INTERNAL_LEN 21

#define MT_CLN_BASE_ID_LEN 7




#define MT_CLN_MASTER_LEN 11
#define MT_CLN_NAME_LEN 66
#define MT_CLN_GL_ACCOUNT_LEN 11
#define MT_CLN_BRK_ALL_LEN 2
#define MT_CLN_SHORTNM_LEN 13
#define MT_CLN_ORD_CLT_LEN 2
#define MT_CLN_SPOT_DL_IND_LEN 2
#define MT_CLN_FX_SELL_IND_LEN 2
#define MT_CLN_FX_BUY_IND_LEN 2
#define MT_CLN_FX_INC_IND_LEN 2

#define MT_CLN_BRNCHCODE_LEN 4
#define MT_COUNTRY_LEN 3
#define MT_CLN_FMT_RPTIND_LEN 2
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_CLN_UNIQ_GCUSTODY_ID_LEN 13
#define MT_CLN_CLTPROD_CD_LEN 6
#define MT_CLN_DOMICILE_LEN 2
#define MT_CLN_PARTIAL_IND_LEN 2
#define MT_CLN_ALLOW_REGIND_LEN 2
#define MT_CLN_REG_SETL_IND_LEN 2
#define MT_CLN_REG_BCL_IND_LEN 2
#define MT_STATUS_LEN 3
#define MT_CLN_CLH_LEN 16
#define MT_CLN_TAXABLE_IND_LEN 2
#define MT_CLN_BRK_CD_LEN 13
#define MT_CLN_TAX_ID_LEN 11
#define MT_CLN_ADD_1_LEN 61
#define MT_CLN_EXT_CLH_LEN 13
#define MT_CLN_GRP_LEN 5
#define MT_CLN_SAT_OPER_CD_LEN 11

#define MT_CLN_AUTHBUNCH_IND_LEN 2
#define MT_CLN_FX_BUY_CCY_LEN 4
#define MT_CLN_FX_SELL_CCY_LEN 4
#define MT_CLN_SINGLE548_SUPPORT_IND_LEN 2
#define MT_CLN_STAT_DL_IND_LEN 2
#define MT_CLN_DEAL_SETL_IND_LEN 2
#define MT_CLN_RHTS_RET_LEN 2
#define MT_CLN_VALCREDIT_LEN 2
#define MT_CLN_FRACT_IND_LEN 2
#define MT_CLN_AUTO_CANC_IND_LEN 2
#define MT_CLN_DESC_LEN 201
#define MT_CLN_GENERATE_IND_LEN 2
#define MT_CLN_ADD_2_LEN 61
#define MT_CITY_LEN 21
#define MT_STATE_LEN 21
#define MT_CLN_ADD_PIN_LEN 11
#define MT_CLN_TEL_LEN 21
#define MT_CLN_FAX_LEN 21
#define MT_CLN_EMAIL_LEN 61
#define MT_CLN_CONTACT1_LEN 66
#define MT_CLN_CONTACT2_LEN 66
#define MT_CLN_SEBICTG_LEN 5
#define MT_CLN_PAN_LEN 21

#define MT_CLN_GLB_CUST_LEN 11
#define MT_CLN_START_DL_LEN 2
#define MT_CLN_BCN_REQD_LEN 2
#define MT_CLN_DEF_CR_AGENCY_LEN 7
#define MT_CLN_CUST_IDENT_LEN 21

#define MT_CLN_SIGN_MEMO_LEN 201

typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_currency[MT_CLN_CURRENCY_LEN];
	char h_cln_our_their_ind[MT_CLN_OUR_THEIR_IND_LEN];
	char h_cln_iscc_ind[MT_CLN_ISCC_IND_LEN];
	char h_cln_use_isin_ind[MT_CLN_USE_ISIN_IND_LEN];
	char h_cln_type[MT_CLN_TYPE_LEN];
	char h_cln_reg_name[MT_CLN_REG_NAME_LEN];
	char h_cln_clas[MT_CLN_CLAS_LEN];
	char h_cln_billableind[MT_CLN_BILLABLEIND_LEN];
	char h_cln_class[MT_CLN_CLASS_LEN];
	char h_cln_vtb_client[MT_CLN_VTB_CLIENT_LEN];
	char h_cln_reg[MT_CLN_REG_LEN];
	char h_cln_memo[MT_CLN_MEMO_LEN];
	char h_cln_internal[MT_CLN_INTERNAL_LEN];
	char h_cln_pos_dt[APL_DATE_LEN];
	char h_cln_base_id[MT_CLN_BASE_ID_LEN];
	int h_cln_count_swf_mon;
	int h_cln_count_tlx_mon;
	int h_cln_count_swf_yr;
	int h_cln_count_tlx_yr;
	char h_cln_master[MT_CLN_MASTER_LEN];
	char h_cln_name[MT_CLN_NAME_LEN];
	char h_cln_gl_account[MT_CLN_GL_ACCOUNT_LEN];
	char h_cln_brk_all[MT_CLN_BRK_ALL_LEN];
	char h_cln_shortnm[MT_CLN_SHORTNM_LEN];
	char h_cln_ord_clt[MT_CLN_ORD_CLT_LEN];
	char h_cln_spot_dl_ind[MT_CLN_SPOT_DL_IND_LEN];
	char h_cln_fx_sell_ind[MT_CLN_FX_SELL_IND_LEN];
	char h_cln_fx_buy_ind[MT_CLN_FX_BUY_IND_LEN];
	char h_cln_fx_inc_ind[MT_CLN_FX_INC_IND_LEN];
	char h_cln_dateof_input[APL_DATE_LEN];
	char h_cln_brnchcode[MT_CLN_BRNCHCODE_LEN];
	char h_country[MT_COUNTRY_LEN];
	char h_cln_fmt_rptind[MT_CLN_FMT_RPTIND_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_cln_uniq_gcustody_id[MT_CLN_UNIQ_GCUSTODY_ID_LEN];
	char h_cln_cltprod_cd[MT_CLN_CLTPROD_CD_LEN];
	char h_cln_domicile[MT_CLN_DOMICILE_LEN];
	char h_cln_partial_ind[MT_CLN_PARTIAL_IND_LEN];
	char h_cln_allow_regind[MT_CLN_ALLOW_REGIND_LEN];
	char h_cln_reg_setl_ind[MT_CLN_REG_SETL_IND_LEN];
	char h_cln_reg_bcl_ind[MT_CLN_REG_BCL_IND_LEN];
	char h_status[MT_STATUS_LEN];
	char h_cln_clh[MT_CLN_CLH_LEN];
	char h_cln_taxable_ind[MT_CLN_TAXABLE_IND_LEN];
	char h_cln_brk_cd[MT_CLN_BRK_CD_LEN];
	char h_cln_tax_id[MT_CLN_TAX_ID_LEN];
	char h_cln_add_1[MT_CLN_ADD_1_LEN];
	char h_cln_ext_clh[MT_CLN_EXT_CLH_LEN];
	char h_cln_grp[MT_CLN_GRP_LEN];
	char h_cln_sat_oper_cd[MT_CLN_SAT_OPER_CD_LEN];
	int h_cln_tolerance;
	char h_cln_authbunch_ind[MT_CLN_AUTHBUNCH_IND_LEN];
	char h_cln_fx_buy_ccy[MT_CLN_FX_BUY_CCY_LEN];
	char h_cln_fx_sell_ccy[MT_CLN_FX_SELL_CCY_LEN];
	char h_cln_single548_support_ind[MT_CLN_SINGLE548_SUPPORT_IND_LEN];
	char h_cln_stat_dl_ind[MT_CLN_STAT_DL_IND_LEN];
	char h_cln_deal_setl_ind[MT_CLN_DEAL_SETL_IND_LEN];
	char h_cln_rhts_ret[MT_CLN_RHTS_RET_LEN];
	char h_cln_valcredit[MT_CLN_VALCREDIT_LEN];
	char h_cln_fract_ind[MT_CLN_FRACT_IND_LEN];
	char h_cln_auto_canc_ind[MT_CLN_AUTO_CANC_IND_LEN];
	char h_cln_desc[MT_CLN_DESC_LEN];
	char h_cln_generate_ind[MT_CLN_GENERATE_IND_LEN];
	char h_cln_add_2[MT_CLN_ADD_2_LEN];
	char h_city[MT_CITY_LEN];
	char h_state[MT_STATE_LEN];
	char h_cln_add_pin[MT_CLN_ADD_PIN_LEN];
	char h_cln_tel[MT_CLN_TEL_LEN];
	char h_cln_fax[MT_CLN_FAX_LEN];
	char h_cln_email[MT_CLN_EMAIL_LEN];
	char h_cln_contact1[MT_CLN_CONTACT1_LEN];
	char h_cln_contact2[MT_CLN_CONTACT2_LEN];
	char h_cln_sebictg[MT_CLN_SEBICTG_LEN];
	char h_cln_pan[MT_CLN_PAN_LEN];
	double h_cln_tds_rt;
	char h_cln_glb_cust[MT_CLN_GLB_CUST_LEN];
	char h_cln_start_dl[MT_CLN_START_DL_LEN];
	char h_cln_bcn_reqd[MT_CLN_BCN_REQD_LEN];
	char h_cln_def_cr_agency[MT_CLN_DEF_CR_AGENCY_LEN];
	char h_cln_cust_ident[MT_CLN_CUST_IDENT_LEN];
	int h_cln_mst_ind;
	char h_cln_sign_memo[MT_CLN_SIGN_MEMO_LEN];
	char h_cln_sign_img[501];	
	 /* Ramya - start */
    char h_cln_sebi_subcat[MT_CLN_SEBI_SUBCAT_LEN];
    char h_cln_country[MT_CLN_COUNTRY_LEN];
    char h_clncity_desc[MT_CLNCITY_DESC_LEN];
    /* Ramya - end */
}MT_CLIENT_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_currency;
	short i_cln_our_their_ind;
	short i_cln_iscc_ind;
	short i_cln_use_isin_ind;
	short i_cln_type;
	short i_cln_reg_name;
	short i_cln_clas;
	short i_cln_billableind;
	short i_cln_class;
	short i_cln_vtb_client;
	short i_cln_reg;
	short i_cln_memo;
	short i_cln_internal;
	short i_cln_pos_dt;
	short i_cln_base_id;
	short i_cln_count_swf_mon;
	short i_cln_count_tlx_mon;
	short i_cln_count_swf_yr;
	short i_cln_count_tlx_yr;
	short i_cln_master;
	short i_cln_name;
	short i_cln_gl_account;
	short i_cln_brk_all;
	short i_cln_shortnm;
	short i_cln_ord_clt;
	short i_cln_spot_dl_ind;
	short i_cln_fx_sell_ind;
	short i_cln_fx_buy_ind;
	short i_cln_fx_inc_ind;
	short i_cln_dateof_input;
	short i_cln_brnchcode;
	short i_country;
	short i_cln_fmt_rptind;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_cln_uniq_gcustody_id;
	short i_cln_cltprod_cd;
	short i_cln_domicile;
	short i_cln_partial_ind;
	short i_cln_allow_regind;
	short i_cln_reg_setl_ind;
	short i_cln_reg_bcl_ind;
	short i_status;
	short i_cln_clh;
	short i_cln_taxable_ind;
	short i_cln_brk_cd;
	short i_cln_tax_id;
	short i_cln_add_1;
	short i_cln_ext_clh;
	short i_cln_grp;
	short i_cln_sat_oper_cd;
	short i_cln_tolerance;
	short i_cln_authbunch_ind;
	short i_cln_fx_buy_ccy;
	short i_cln_fx_sell_ccy;
	short i_cln_single548_support_ind;
	short i_cln_stat_dl_ind;
	short i_cln_deal_setl_ind;
	short i_cln_rhts_ret;
	short i_cln_valcredit;
	short i_cln_fract_ind;
	short i_cln_auto_canc_ind;
	short i_cln_desc;
	short i_cln_generate_ind;
	short i_cln_add_2;
	short i_city;
	short i_state;
	short i_cln_add_pin;
	short i_cln_tel;
	short i_cln_fax;
	short i_cln_email;
	short i_cln_contact1;
	short i_cln_contact2;
	short i_cln_sebictg;
	short i_cln_pan;
	short i_cln_tds_rt;
	short i_cln_glb_cust;
	short i_cln_start_dl;
	short i_cln_bcn_reqd;
	short i_cln_def_cr_agency;
	short i_cln_cust_ident;
	short i_cln_mst_ind;
	short i_cln_sign_memo;
	short i_cln_sign_img;
}MT_CLIENT_STRUCT_I;

















































/*
typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}MT_CLIENTLST_VEW_STRUCT_H;*/
typedef struct{
	short i_client;
	short i_dateof_input;
	short i_domestic;
	short i_clt_status;
	short i_iscc_ind;
	short i_use_isin_ind;
	short i_clt_clas;
	short i_billableind;
	short i_clt_class;
	short i_master_clt;
	short i_clnt_name;
	short i_gl_account;
	short i_clt_brk_all;
	short i_shrtname;
	short i_ord_clt;
	short i_spot_dl_ind;
	short i_fx_sell_ind;
	short i_fx_buy_ind;
	short i_fx_inc_ind;
	short i_brnchcode;
	short i_nation_cd;
	short i_fmt_rptind;
	short i_partial_ind_c;
	short i_allow_regind;
	short i_reg_setl_ind;
	short i_reg_bcl_ind;
	short i_clh_clt;
	short i_cltreg;
	short i_vtb_client;
	short i_msg_ident_no;
	short i_swift_tlx_gcn;
	short i_pos_dt;
	short i_priority_ind;
	short i_gcn_addr;
	short i_swift_addr;
	short i_telex_addr;
	short i_schedule;
	short i_comb_msg;
	short i_identify;
	short i_iso_msg_format;
	short i_rec_stat_det;
	short i_domestic_det;
	short i_msg_det;
}MT_CLIENTLST_VEW_STRUCT_I;







#define MT_CLIENT_LEN 11
#define MT_INSTR_CODE_LEN 9

typedef struct{
	char h_client[MT_CLIENT_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_safekeep_pos;
}MT_CLIENT_DEPO_STRUCT_H;
typedef struct{
	short i_client;
	short i_instr_code;
	short i_safekeep_pos;
}MT_CLIENT_DEPO_STRUCT_I;







#define MT_MAKER_LEN 15


#define MT_STX_CLIENT_LEN 11
#define MT_COMM_CLT_LEN 11
#define MT_TPAY_CLIENT_LEN 11
#define MT_TEXP_CLIENT_LEN 11
#define MT_CUSTODY_CLT_LEN 11
typedef struct{
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_stx_client[MT_STX_CLIENT_LEN];
	char h_comm_clt[MT_COMM_CLT_LEN];
	char h_tpay_client[MT_TPAY_CLIENT_LEN];
	char h_texp_client[MT_TEXP_CLIENT_LEN];
	char h_custody_clt[MT_CUSTODY_CLT_LEN];
}MT_CLIENT_ENTRIES_STRUCT_H;
typedef struct{
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_stx_client;
	short i_comm_clt;
	short i_tpay_client;
	short i_texp_client;
	short i_custody_clt;
}MT_CLIENT_ENTRIES_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_DEPO_CODE_LEN 5
#define MT_CLN_DEPO_MAP_CLIENT_ID_LEN 21
#define MT_CLN_DEPO_MAP_DP_ID_LEN 21

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15


#define MT_STATUS_LEN 3
#define MT_CMBP_ID_LEN 12 /*ADDED BY SIMAR FOR PMS UPLOAD ISKB_12434 */
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_depo_code[MT_CLN_DEPO_CODE_LEN];
	char h_cln_depo_map_client_id[MT_CLN_DEPO_MAP_CLIENT_ID_LEN];
	char h_cln_depo_map_dp_id[MT_CLN_DEPO_MAP_DP_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	int h_cln_seq_num;
	char h_status[MT_STATUS_LEN];
	char h_cmbp_id[MT_CMBP_ID_LEN]; /*ADDED BY SIMAR FOR PMS UPLOAD ISKB_12434 */
}MT_CLI_DEPO_MAP_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_depo_code;
	short i_cln_depo_map_client_id;
	short i_cln_depo_map_dp_id;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_cln_seq_num;
	short i_status;
	short i_cmbp_id;
}MT_CLI_DEPO_MAP_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_EXCH_CODE_LEN 4
#define MT_CLN_EXCH_MAP_CODE_LEN 21
#define MT_CLN_HDFC_CM_ID_LEN 21

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15


#define MT_STATUS_LEN 3
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_exch_code[MT_CLN_EXCH_CODE_LEN];
	char h_cln_exch_map_code[MT_CLN_EXCH_MAP_CODE_LEN];
	char h_cln_hdfc_cm_id[MT_CLN_HDFC_CM_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	int h_cln_seq_num;
	char h_status[MT_STATUS_LEN];
}MT_CLI_EXCH_MAP_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_exch_code;
	short i_cln_exch_map_code;
	short i_cln_hdfc_cm_id;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_cln_seq_num;
	short i_status;
}MT_CLI_EXCH_MAP_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_INSTR_CODE_LEN 9
#define MT_CLN_INSTR_CODE_LEN 21
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_cln_instr_code[MT_CLN_INSTR_CODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_CLN_INST_MAP_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_instr_code;
	short i_cln_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_CLN_INST_MAP_STRUCT_I;







#define MT_CLIENT_LEN 11
#define MT_DEPO_LOC_LEN 5
#define MT_CLIENT_TYPE_LEN 2
#define MT_SEGR_CLIENT_NO_LEN 11
#define MT_AGREE_ID_LEN 11

#define MT_DEPO_BR_CD_LEN 12
#define MT_DEPO_GL_CLT_LEN 11
#define MT_DEPO_CLT_LEN 11
#define MT_REG_CERT_NO_LEN 26
#define MT_REG_CERT_SER_LEN 26

#define MT_ISSUE_AUTHORITY_LEN 26
typedef struct{
	char h_client[MT_CLIENT_LEN];
	char h_depo_loc[MT_DEPO_LOC_LEN];
	char h_client_type[MT_CLIENT_TYPE_LEN];
	char h_segr_client_no[MT_SEGR_CLIENT_NO_LEN];
	char h_agree_id[MT_AGREE_ID_LEN];
	char h_date_agree[APL_DATE_LEN];
	char h_depo_br_cd[MT_DEPO_BR_CD_LEN];
	char h_depo_gl_clt[MT_DEPO_GL_CLT_LEN];
	char h_depo_clt[MT_DEPO_CLT_LEN];
	char h_reg_cert_no[MT_REG_CERT_NO_LEN];
	char h_reg_cert_ser[MT_REG_CERT_SER_LEN];
	char h_reg_cert_date[APL_DATE_LEN];
	char h_issue_authority[MT_ISSUE_AUTHORITY_LEN];
}MT_CLTDEPO_STRUCT_H;
typedef struct{
	short i_client;
	short i_depo_loc;
	short i_client_type;
	short i_segr_client_no;
	short i_agree_id;
	short i_date_agree;
	short i_depo_br_cd;
	short i_depo_gl_clt;
	short i_depo_clt;
	short i_reg_cert_no;
	short i_reg_cert_ser;
	short i_reg_cert_date;
	short i_issue_authority;
}MT_CLTDEPO_STRUCT_I;







#define MT_CA_IDENTNAME_LEN 41
#define MT_CA_ADDRESS_LEN 321
#define MT_NATION_CODE_LEN 3
#define MT_BRNCH_CD_LEN 4
#define MT_DOM_CCY_LEN 4
#define MT_DOM_INSTRUMENT_LEN 5
#define MT_GL_INTERFACE_MOD_IND_LEN 2
#define MT_BILL_MODULE_IND_LEN 2
#define MT_CA_MODULE_IND_LEN 2
#define MT_F_FILE_PATH_LEN 61
#define MT_B_FILE_PATH_LEN 61

#define MT_EI_SMI_IND_LEN 2
#define MT_CCS_IND_LEN 2
#define MT_OFFICE_FOR_BOOKING_LEN 9
typedef struct{
	char h_ca_identname[MT_CA_IDENTNAME_LEN];
	char h_ca_address[MT_CA_ADDRESS_LEN];
	char h_nation_code[MT_NATION_CODE_LEN];
	char h_brnch_cd[MT_BRNCH_CD_LEN];
	char h_dom_ccy[MT_DOM_CCY_LEN];
	char h_dom_instrument[MT_DOM_INSTRUMENT_LEN];
	char h_gl_interface_mod_ind[MT_GL_INTERFACE_MOD_IND_LEN];
	char h_bill_module_ind[MT_BILL_MODULE_IND_LEN];
	char h_ca_module_ind[MT_CA_MODULE_IND_LEN];
	char h_f_file_path[MT_F_FILE_PATH_LEN];
	char h_b_file_path[MT_B_FILE_PATH_LEN];
	int h_monthsfor_arch;
	char h_ei_smi_ind[MT_EI_SMI_IND_LEN];
	char h_ccs_ind[MT_CCS_IND_LEN];
	char h_office_for_booking[MT_OFFICE_FOR_BOOKING_LEN];
}MT_COMMON_SYS_PARAMS_STRUCT_H;
typedef struct{
	short i_ca_identname;
	short i_ca_address;
	short i_nation_code;
	short i_brnch_cd;
	short i_dom_ccy;
	short i_dom_instrument;
	short i_gl_interface_mod_ind;
	short i_bill_module_ind;
	short i_ca_module_ind;
	short i_f_file_path;
	short i_b_file_path;
	short i_monthsfor_arch;
	short i_ei_smi_ind;
	short i_ccs_ind;
	short i_office_for_booking;
}MT_COMMON_SYS_PARAMS_STRUCT_I;







#define MT_CMP_CODE_LEN 11
#define MT_CMP_NAME_LEN 66
#define MT_CMP_SHORTNM_LEN 13
#define MT_CMP_OLDNAME_LEN 66
#define MT_CMP_ADD1_LEN 61
#define MT_CMP_ADD2_LEN 61
#define MT_CITY_LEN 4
#define MT_STATE_LEN 3
#define MT_COUNTRY_LEN 3
#define MT_CMP_ADD_PIN_LEN 11
#define MT_CMP_TEL_LEN 21
#define MT_CMP_FAX_LEN 21
#define MT_CMP_WEBADD_LEN 61
#define MT_CMP_SWF_NAME_LEN 21
#define MT_CMP_SECNM_LEN 41
#define MT_CMP_SEC_EMAIL_LEN 61
#define MT_CMP_MDNM_LEN 41
#define MT_CMP_INDUSTRYCD_LEN 4
#define MT_CMP_SECTORCD_LEN 4
#define MT_CMP_REMARKS_LEN 201



#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_cmp_code[MT_CMP_CODE_LEN];
	char h_cmp_name[MT_CMP_NAME_LEN];
	char h_cmp_shortnm[MT_CMP_SHORTNM_LEN];
	char h_cmp_oldname[MT_CMP_OLDNAME_LEN];
	char h_cmp_add1[MT_CMP_ADD1_LEN];
	char h_cmp_add2[MT_CMP_ADD2_LEN];
	char h_city[MT_CITY_LEN];
	char h_state[MT_STATE_LEN];
	char h_country[MT_COUNTRY_LEN];
	char h_cmp_add_pin[MT_CMP_ADD_PIN_LEN];
	char h_cmp_tel[MT_CMP_TEL_LEN];
	char h_cmp_fax[MT_CMP_FAX_LEN];
	char h_cmp_webadd[MT_CMP_WEBADD_LEN];
	char h_cmp_swf_name[MT_CMP_SWF_NAME_LEN];
	char h_cmp_secnm[MT_CMP_SECNM_LEN];
	char h_cmp_sec_email[MT_CMP_SEC_EMAIL_LEN];
	char h_cmp_mdnm[MT_CMP_MDNM_LEN];
	char h_cmp_industrycd[MT_CMP_INDUSTRYCD_LEN];
	char h_cmp_sectorcd[MT_CMP_SECTORCD_LEN];
	char h_cmp_remarks[MT_CMP_REMARKS_LEN];
	double h_cmp_authcapital;
	double h_cmp_issuedcapital;
	double h_cmp_tpcapital;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_COMPANY_STRUCT_H;
typedef struct{
	short i_cmp_code;
	short i_cmp_name;
	short i_cmp_shortnm;
	short i_cmp_oldname;
	short i_cmp_add1;
	short i_cmp_add2;
	short i_city;
	short i_state;
	short i_country;
	short i_cmp_add_pin;
	short i_cmp_tel;
	short i_cmp_fax;
	short i_cmp_webadd;
	short i_cmp_swf_name;
	short i_cmp_secnm;
	short i_cmp_sec_email;
	short i_cmp_mdnm;
	short i_cmp_industrycd;
	short i_cmp_sectorcd;
	short i_cmp_remarks;
	short i_cmp_authcapital;
	short i_cmp_issuedcapital;
	short i_cmp_tpcapital;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_COMPANY_STRUCT_I;







#define MT_PART_CONFIRM_LEN 2
#define MT_MANIFLD_PRINT_IND_LEN 2
#define MT_PROC_SPOT_DL_IND_LEN 2
#define MT_GSETL_IND_LEN 2
#define MT_SUB_CLT_PROC_LEN 2
#define MT_ORD_PROC_IND_LEN 2
#define MT_NO_STXDL_IND_LEN 2
#define MT_LOC_PROC_IND_LEN 2
#define MT_AE_IND_LEN 2
#define MT_PROC_PR_FEED_IND_LEN 2
#define MT_DIR_INDIR_FXQT_IND_LEN 2
#define MT_PROC_REG_IND_LEN 2
#define MT_PART_REG_IND_LEN 2












#define MT_OP_OTH_STX_ERROR_LEN 3
#define MT_OP_OTH_TRD_ERROR_LEN 3






#define MT_CUSTODY_CLT_CD_LEN 11
#define MT_BROKERAGE_CD_LEN 11
#define MT_BRNCH_USD_CLT_LEN 11
#define MT_VTB_CLT_CODE_LEN 11
#define MT_VTB_CLT_NAME_LEN 41
#define MT_VTB_IDENTITY_LEN 41
#define MT_VDP_IND_LEN 2


#define MT_MS_53X_ONLINE_EOD_IND_LEN 2
/*

typedef struct{
	char h_part_confirm[MT_PART_CONFIRM_LEN];
	char h_manifld_print_ind[MT_MANIFLD_PRINT_IND_LEN];
	char h_proc_spot_dl_ind[MT_PROC_SPOT_DL_IND_LEN];
	char h_gsetl_ind[MT_GSETL_IND_LEN];
	char h_sub_clt_proc[MT_SUB_CLT_PROC_LEN];
	char h_ord_proc_ind[MT_ORD_PROC_IND_LEN];
	char h_no_stxdl_ind[MT_NO_STXDL_IND_LEN];
	char h_loc_proc_ind[MT_LOC_PROC_IND_LEN];
	char h_ae_ind[MT_AE_IND_LEN];
	char h_proc_pr_feed_ind[MT_PROC_PR_FEED_IND_LEN];
	char h_dir_indir_fxqt_ind[MT_DIR_INDIR_FXQT_IND_LEN];
	char h_proc_reg_ind[MT_PROC_REG_IND_LEN];
	char h_part_reg_ind[MT_PART_REG_IND_LEN];
	int h_amount_decimal_len;
	int h_qty_dec_len;
	int h_min_clt_len;
	int h_allowed_amtdiff;
	int h_auto_inactive_days;
	int h_odd_lot_qty;
	int h_proc_start_no;
	int h_end_proc_no;
	double h_custody_tax_rt;
	double h_fx_tax_rt;
	double h_comm_tax_rt;
	double h_paidupcapital_limit;
	char h_op_oth_stx_error[MT_OP_OTH_STX_ERROR_LEN];
	char h_op_oth_trd_error[MT_OP_OTH_TRD_ERROR_LEN];
	int h_stx_rec_dl_days;
	int h_stx_del_dl_days;
	int h_oth_rec_dl_days;
	int h_oth_del_dl_days;
	int h_spot_dl_days;
	int h_spot_oth_dl_days;
	char h_custody_clt_cd[MT_CUSTODY_CLT_CD_LEN];
	char h_brokerage_cd[MT_BROKERAGE_CD_LEN];
	char h_brnch_usd_clt[MT_BRNCH_USD_CLT_LEN];
	char h_vtb_clt_code[MT_VTB_CLT_CODE_LEN];
	char h_vtb_clt_name[MT_VTB_CLT_NAME_LEN];
	char h_vtb_identity[MT_VTB_IDENTITY_LEN];
	char h_vdp_ind[MT_VDP_IND_LEN];
	double h_custody_comm_rt;
	double h_stk_exg_comm_rt;
	char h_ms_53x_online_eod_ind[MT_MS_53X_ONLINE_EOD_IND_LEN];
	int h_auction_date_days;
}MT_CORE_SYS_PARAMS_STRUCT_H;
typedef struct{
	short i_part_confirm;
	short i_manifld_print_ind;
	short i_proc_spot_dl_ind;
	short i_gsetl_ind;
	short i_sub_clt_proc;
	short i_ord_proc_ind;
	short i_no_stxdl_ind;
	short i_loc_proc_ind;
	short i_ae_ind;
	short i_proc_pr_feed_ind;
	short i_dir_indir_fxqt_ind;
	short i_proc_reg_ind;
	short i_part_reg_ind;
	short i_amount_decimal_len;
	short i_qty_dec_len;
	short i_min_clt_len;
	short i_allowed_amtdiff;
	short i_auto_inactive_days;
	short i_odd_lot_qty;
	short i_proc_start_no;
	short i_end_proc_no;
	short i_custody_tax_rt;
	short i_fx_tax_rt;
	short i_comm_tax_rt;
	short i_paidupcapital_limit;
	short i_op_oth_stx_error;
	short i_op_oth_trd_error;
	short i_stx_rec_dl_days;
	short i_stx_del_dl_days;
	short i_oth_rec_dl_days;
	short i_oth_del_dl_days;
	short i_spot_dl_days;
	short i_spot_oth_dl_days;
	short i_custody_clt_cd;
	short i_brokerage_cd;
	short i_brnch_usd_clt;
	short i_vtb_clt_code;
	short i_vtb_clt_name;
	short i_vtb_identity;
	short i_vdp_ind;
	short i_custody_comm_rt;
	short i_stk_exg_comm_rt;
	short i_ms_53x_online_eod_ind;
	short i_auction_date_days;
}MT_CORE_SYS_PARAMS_STRUCT_I;*/







#define MT_AGENCY_CODE_LEN 9
#define MT_AGENCY_NAME_LEN 61
#define MT_AGENCY_ADD_1_LEN 61
#define MT_AGENCY_ADD_2_LEN 61
#define MT_CITY_LEN 4
#define MT_STATE_LEN 3
#define MT_COUNTRY_LEN 3
#define MT_AGENCY_ADD_PIN_LEN 11
#define MT_AGENCY_TEL_LEN 21
#define MT_AGENCY_FAX_LEN 21
#define MT_AGENCY_EMAIL_LEN 61
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_agency_code[MT_AGENCY_CODE_LEN];
	char h_agency_name[MT_AGENCY_NAME_LEN];
	char h_agency_add_1[MT_AGENCY_ADD_1_LEN];
	char h_agency_add_2[MT_AGENCY_ADD_2_LEN];
	char h_city[MT_CITY_LEN];
	char h_state[MT_STATE_LEN];
	char h_country[MT_COUNTRY_LEN];
	char h_agency_add_pin[MT_AGENCY_ADD_PIN_LEN];
	char h_agency_tel[MT_AGENCY_TEL_LEN];
	char h_agency_fax[MT_AGENCY_FAX_LEN];
	char h_agency_email[MT_AGENCY_EMAIL_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_CR_AGENCY_STRUCT_H;
typedef struct{
	short i_agency_code;
	short i_agency_name;
	short i_agency_add_1;
	short i_agency_add_2;
	short i_city;
	short i_state;
	short i_country;
	short i_agency_add_pin;
	short i_agency_tel;
	short i_agency_fax;
	short i_agency_email;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_CR_AGENCY_STRUCT_I;







#define MT_AGENCY_CODE_LEN 9
#define MT_RATING_CODE_LEN 7
#define MT_RATING_DESC_LEN 41
#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3


typedef struct{
	char h_agency_code[MT_AGENCY_CODE_LEN];
	char h_rating_code[MT_RATING_CODE_LEN];
	char h_rating_desc[MT_RATING_DESC_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_access_stamp[APL_DATE_LEN];
	int h_cr_seq_num;
}MT_CR_AGENCY_DET_STRUCT_H;
typedef struct{
	short i_agency_code;
	short i_rating_code;
	short i_rating_desc;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_access_stamp;
	short i_cr_seq_num;
}MT_CR_AGENCY_DET_STRUCT_I;







#define MT_AGENCY_CODE_LEN 9
#define MT_RATING_CODE_LEN 7
#define MT_RATING_DESC_LEN 41
typedef struct{
	char h_agency_code[MT_AGENCY_CODE_LEN];
	char h_rating_code[MT_RATING_CODE_LEN];
	char h_rating_desc[MT_RATING_DESC_LEN];
}MT_CR_AGENCY_DET_BKUP_STRUCT_H;
typedef struct{
	short i_agency_code;
	short i_rating_code;
	short i_rating_desc;
}MT_CR_AGENCY_DET_BKUP_STRUCT_I;







#define MT_BENCHMARK_CODE_LEN 9



#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_benchmark_code[MT_BENCHMARK_CODE_LEN];
	char h_rate_date[APL_DATE_LEN];
	double h_float_rate;
	double h_std_deviation;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_DAILY_FLOAT_RATE_STRUCT_H;
typedef struct{
	short i_benchmark_code;
	short i_rate_date;
	short i_float_rate;
	short i_std_deviation;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_DAILY_FLOAT_RATE_STRUCT_I;







#define MT_EXCH_CODE_LEN 4
#define MT_INSTR_CODE_LEN 9






#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_quot_date[APL_DATE_LEN];
	double h_quot_prev_date;
	double h_open_at;
	double h_high_at;
	double h_low_at;
	double h_close_at;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_DAILY_QUOT_STRUCT_H;
typedef struct{
	short i_exch_code;
	short i_instr_code;
	short i_quot_date;
	short i_quot_prev_date;
	short i_open_at;
	short i_high_at;
	short i_low_at;
	short i_close_at;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_DAILY_QUOT_STRUCT_I;







#define MT_DEPO_CODE_LEN 5
#define MT_DEPO_PART_CODE_LEN 21
#define MT_DEPO_PART_CONTACT_LEN 66
#define MT_DEPO_PART_ADD1_LEN 66
#define MT_DEPO_PART_ADD2_LEN 66
#define MT_CITY_LEN 4
#define MT_STATE_LEN 3
#define MT_COUNTRY_LEN 3
#define MT_DEPO_PART_ADD_PIN_LEN 11
#define MT_DEPO_PART_TEL_LEN 21
#define MT_DEPO_PART_FAX_LEN 21
#define MT_DEPO_PART_EMAIL_LEN 61
#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
#define MT_DEPO_NAME_LEN 136 /* Added By Gouse for Depo Participant Name in Depo Participant Master*/
typedef struct{
	char h_depo_code[MT_DEPO_CODE_LEN];
	char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
	char h_depo_part_contact[MT_DEPO_PART_CONTACT_LEN];
	char h_depo_part_add1[MT_DEPO_PART_ADD1_LEN];
	char h_depo_part_add2[MT_DEPO_PART_ADD2_LEN];
	char h_city[MT_CITY_LEN];
	char h_state[MT_STATE_LEN];
	char h_country[MT_COUNTRY_LEN];
	char h_depo_part_add_pin[MT_DEPO_PART_ADD_PIN_LEN];
	char h_depo_part_tel[MT_DEPO_PART_TEL_LEN];
	char h_depo_part_fax[MT_DEPO_PART_FAX_LEN];
	char h_depo_part_email[MT_DEPO_PART_EMAIL_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
    char h_depo_name[MT_DEPO_NAME_LEN]; /*Added By Gouse for Depo Participant Name in Depo Participant Master*/
}MT_DEPO_PART_STRUCT_H;
typedef struct{
	short i_depo_code;
	short i_depo_part_code;
	short i_depo_part_contact;
	short i_depo_part_add1;
	short i_depo_part_add2;
	short i_city;
	short i_state;
	short i_country;
	short i_depo_part_add_pin;
	short i_depo_part_tel;
	short i_depo_part_fax;
	short i_depo_part_email;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_status;
    short i_depo_name; /* Added By Gouse for Depo Participant Name in Depo Participant Master */
}MT_DEPO_PART_STRUCT_I;








#define MT_INSTR_CODE_LEN 9

#define MT_MODIFYMODE_LEN 2

#define MT_MAKER_LEN 15

#define MT_MKRTPR_STAT_LEN 3
#define MT_CHECKER_LEN 15

typedef struct{
	char h_price_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_closing_pr;
	char h_modifymode[MT_MODIFYMODE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_mkrtpr_stat[MT_MKRTPR_STAT_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
}MT_DLYMKTPRC_STRUCT_H;
typedef struct{
	short i_price_date;
	short i_instr_code;
	short i_closing_pr;
	short i_modifymode;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_mkrtpr_stat;
	short i_checker;
	short i_checker_dt;
}MT_DLYMKTPRC_STRUCT_I;







#define MT_INSTR_CODE_LEN 9


typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_open_pr;
	double h_closing_pr;
}MT_EOMMTHLYMKTPRC_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_open_pr;
	short i_closing_pr;
}MT_EOMMTHLYMKTPRC_STRUCT_I;








#define MT_EOD_IND_LEN 2
typedef struct{
	char h_current_date[APL_DATE_LEN];
	char h_eod_ind[MT_EOD_IND_LEN];
}MT_EOMSYSDATE_STRUCT_H;
typedef struct{
	short i_current_date;
	short i_eod_ind;
}MT_EOMSYSDATE_STRUCT_I;







#define MT_CURRENCY_CD_LEN 4
#define MT_DENOM_CCY_LEN 4




#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_EXCHG_STAT_LEN 3
typedef struct{
	char h_currency_cd[MT_CURRENCY_CD_LEN];
	char h_denom_ccy[MT_DENOM_CCY_LEN];
	char h_rate_date[APL_DATE_LEN];
	double h_exchgrt;
	double h_rate_buy;
	double h_sell_rt;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_exchg_stat[MT_EXCHG_STAT_LEN];
}MT_EXCHRATE_STRUCT_H;
typedef struct{
	short i_currency_cd;
	short i_denom_ccy;
	short i_rate_date;
	short i_exchgrt;
	short i_rate_buy;
	short i_sell_rt;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_exchg_stat;
}MT_EXCHRATE_STRUCT_I;







#define MT_INSTR_CODE_LEN 9
#define MT_RESET_OPTION_LEN 2
#define MT_DAILY_COMPOUND_LEN 2
#define MT_EXCL_HOLIDAYS_LEN 2

#define MT_COMPOUNDING_WDAYS_LEN 2




#define MT_MIBOR_CODE_LEN 9
#define MT_FIXED_BENCH_LEN 2
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_reset_option[MT_RESET_OPTION_LEN];
	char h_daily_compound[MT_DAILY_COMPOUND_LEN];
	char h_excl_holidays[MT_EXCL_HOLIDAYS_LEN];
	int h_int_pay_days;
	char h_compounding_wdays[MT_COMPOUNDING_WDAYS_LEN];
	double h_floor_rate;
	double h_cap_rate;
	int h_prefd_seq;
	double h_base_margin;
	char h_mibor_code[MT_MIBOR_CODE_LEN];
	char h_fixed_bench[MT_FIXED_BENCH_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_FLRATE_INSTRUMENT_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_reset_option;
	short i_daily_compound;
	short i_excl_holidays;
	short i_int_pay_days;
	short i_compounding_wdays;
	short i_floor_rate;
	short i_cap_rate;
	short i_prefd_seq;
	short i_base_margin;
	short i_mibor_code;
	short i_fixed_bench;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_FLRATE_INSTRUMENT_STRUCT_I;







#define MT_CLN_TYPE_LEN 5
#define MT_CLN_EMAIL_LEN 61
#define MT_CLN_CONTACT1_LEN 66
#define MT_CLN_CONTACT2_LEN 66
#define MT_CLN_SEBICTG_LEN 5
#define MT_CLN_PAN_LEN 21
#define MT_CLN_DEF_CR_AGENCY_LEN 7
#define MT_CLN_CODE_LEN 11
typedef struct{
	char h_cln_type[MT_CLN_TYPE_LEN];
	char h_cln_email[MT_CLN_EMAIL_LEN];
	char h_cln_contact1[MT_CLN_CONTACT1_LEN];
	char h_cln_contact2[MT_CLN_CONTACT2_LEN];
	char h_cln_sebictg[MT_CLN_SEBICTG_LEN];
	char h_cln_pan[MT_CLN_PAN_LEN];
	char h_cln_def_cr_agency[MT_CLN_DEF_CR_AGENCY_LEN];
	char h_cln_code[MT_CLN_CODE_LEN];
}MT_GRPDETAILS_STRUCT_H;
typedef struct{
	short i_cln_type;
	short i_cln_email;
	short i_cln_contact1;
	short i_cln_contact2;
	short i_cln_sebictg;
	short i_cln_pan;
	short i_cln_def_cr_agency;
	short i_cln_code;
}MT_GRPDETAILS_STRUCT_I;








#define MT_INSTR_CODE_LEN 9

#define MT_MODIFYMODE_LEN 2
#define MT_MAKER_LEN 15

#define MT_MKRTPR_STAT_LEN 3
#define MT_CHECKER_LEN 15

typedef struct{
	char h_price_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_closing_pr;
	char h_modifymode[MT_MODIFYMODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_mkrtpr_stat[MT_MKRTPR_STAT_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
}MT_HISDLYMKTPRC_STRUCT_H;
typedef struct{
	short i_price_date;
	short i_instr_code;
	short i_closing_pr;
	short i_modifymode;
	short i_maker;
	short i_maker_dt;
	short i_mkrtpr_stat;
	short i_checker;
	short i_checker_dt;
}MT_HISDLYMKTPRC_STRUCT_I;







#define MT_HOLIDAY_AT_LEN 2

#define MT_HOLIDAY_REAS_LEN 41
#define MT_HOLIDAY_TYPE_LEN 3
#define MT_EXCH_CODE_LEN 4
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_holiday_at[MT_HOLIDAY_AT_LEN];
	char h_holiday_date[APL_DATE_LEN];
	char h_holiday_reas[MT_HOLIDAY_REAS_LEN];
	char h_holiday_type[MT_HOLIDAY_TYPE_LEN];
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_HOLIDAY_STRUCT_H;
typedef struct{
	short i_holiday_at;
	short i_holiday_date;
	short i_holiday_reas;
	short i_holiday_type;
	short i_exch_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_HOLIDAY_STRUCT_I;







#define MT_IDENTITY_CD_LEN 6
#define MT_CLT_DESC_LEN 66
#define MT_BRKCD_LEN 13
#define MT_DSN_CD_LEN 5
typedef struct{
	char h_identity_cd[MT_IDENTITY_CD_LEN];
	char h_clt_desc[MT_CLT_DESC_LEN];
	char h_brkcd[MT_BRKCD_LEN];
	char h_dsn_cd[MT_DSN_CD_LEN];
}MT_IDENTMNT_STRUCT_H;
typedef struct{
	short i_identity_cd;
	short i_clt_desc;
	short i_brkcd;
	short i_dsn_cd;
}MT_IDENTMNT_STRUCT_I;







#define MT_INDEX_FUND_NUM_LEN 4
#define MT_INDEX_FUND_NAME_LEN 51
#define MT_MAKER_LEN 16


#define MT_CHECKER_LEN 16

#define MT_STATUS_LEN 3
typedef struct{
	char h_index_fund_num[MT_INDEX_FUND_NUM_LEN];
	char h_index_fund_name[MT_INDEX_FUND_NAME_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INDEX_FUND_STRUCT_H;
typedef struct{
	short i_index_fund_num;
	short i_index_fund_name;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_INDEX_FUND_STRUCT_I;








#define MT_INDEX_FUND_NUM_LEN 4
#define MT_INSTR_CODE_LEN 9
#define MT_MAKER_LEN 16


#define MT_CHECKER_LEN 16

#define MT_STATUS_LEN 3
typedef struct{
	int h_index_seq_num;
	char h_index_fund_num[MT_INDEX_FUND_NUM_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INDEX_FUNDDET_STRUCT_H;
typedef struct{
	short i_index_seq_num;
	short i_index_fund_num;
	short i_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_INDEX_FUNDDET_STRUCT_I;







#define MT_DEPO_CODE_LEN 5
#define MT_DEPO_PART_CODE_LEN 21
#define MT_CLN_CODE_LEN 11
#define MT_TRANS_TYPE_LEN 4
#define MT_SLIP_SERIES_LEN 6



#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_depo_code[MT_DEPO_CODE_LEN];
	char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_trans_type[MT_TRANS_TYPE_LEN];
	char h_slip_series[MT_SLIP_SERIES_LEN];
	int h_sr_no_from;
	int h_sr_no_to;
	int h_sr_avl_qty;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INSL_ENTRY_STRUCT_H;
typedef struct{
	short i_depo_code;
	short i_depo_part_code;
	short i_cln_code;
	short i_trans_type;
	short i_slip_series;
	short i_sr_no_from;
	short i_sr_no_to;
	short i_sr_avl_qty;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_INSL_ENTRY_STRUCT_I;







#define MT_INSTR_CODE_LEN 9
#define MT_CURRENCY_CD_LEN 4
#define MT_LOCATION_CD_LEN 5

#define MT_REG_BR_IND_LEN 3
#define MT_ALLOW_RF_LEN 2
#define MT_ALLOW_RVP_LEN 2
#define MT_ALLOW_DF_LEN 2
#define MT_ALLOW_DVP_LEN 2
#define MT_ORD_TYPE_LEN 2
#define MT_MOTHER_SEC_IND_LEN 2
#define MT_EX_ARENA_LEN 3
#define MT_LISTED_IND_LEN 2


#define MT_NEW_MAKER_LEN 15
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15


#define MT_STATUS_LEN 3
#define MT_NEW_ISSUE_LEN 2
#define MT_NEW_CHECKER_LEN 15
#define MT_CHNG_LST_IND_LEN 2
#define MT_CERT_OF_OWN_IN_LEN 2
#define MT_INSTR_NAME_LEN 131
#define MT_INSTR_ISIN_LEN 13
#define MT_TIPO_INV_LEN 3
#define MT_INSTR_TYPE_LEN 4
#define MT_INSTR_PARENT_LEN 9
#define MT_PROD_CLASS_LEN 3
#define MT_SEC_DL_CODE_LEN 4
#define MT_CLASSCD_LEN 5
#define MT_NEW_CD_LEN 9
#define MT_CHNG_ISIN_LEN 13

#define MT_CHG_MKR_LEN 15
#define MT_CA_NAME_LEN 61
#define MT_CHNG_CD_LEN 9

#define MT_INT_TYP_LEN 2

#define MT_FREQ_CODE_LEN 2
#define MT_INT_ACCTYP_LEN 2




#define MT_MOD_LAST_PAYDT_LEN 2
#define MT_TAXONMAT_IND_LEN 2
#define MT_DISCT_IND_LEN 2
#define MT_CA_ADDRDET_LEN 181



#define MT_INSTR_SHORTNM_LEN 16
#define MT_IPO_IND_LEN 2


#define MT_CMP_CODE_LEN 11
#define MT_INSTR_REG_CODE_LEN 11
#define MT_INSTR_SWF_NAME_LEN 21
#define MT_INSTR_PRIV_PLACED_LEN 2
#define MT_INSTR_CRISIL_CODE_LEN 7
#define MT_INSTR_IS_SECURED_LEN 2


#define MT_INSTR_PC_IND_LEN 2
#define MT_INSTR_PART_RD_FLG_LEN 2
#define MT_INSTR_RESET_FLG_LEN 2



#define MT_INSTR_IS_DEMAT_LEN 2
#define MT_INSTR_REMARK_LEN 101

#define MT_INSTR_ISIN_NAME_LEN 21
#define MT_INSTR_ATTACHED_LEN 9

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_currency_cd[MT_CURRENCY_CD_LEN];
	char h_location_cd[MT_LOCATION_CD_LEN];
	double h_nominal_value;
	char h_reg_br_ind[MT_REG_BR_IND_LEN];
	char h_allow_rf[MT_ALLOW_RF_LEN];
	char h_allow_rvp[MT_ALLOW_RVP_LEN];
	char h_allow_df[MT_ALLOW_DF_LEN];
	char h_allow_dvp[MT_ALLOW_DVP_LEN];
	char h_ord_type[MT_ORD_TYPE_LEN];
	char h_mother_sec_ind[MT_MOTHER_SEC_IND_LEN];
	char h_ex_arena[MT_EX_ARENA_LEN];
	char h_listed_ind[MT_LISTED_IND_LEN];
	char h_dateof_input[APL_DATE_LEN];
	int h_threshold_qty;
	char h_new_maker[MT_NEW_MAKER_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	double h_total_pdcapita;
	char h_status[MT_STATUS_LEN];
	char h_new_issue[MT_NEW_ISSUE_LEN];
	char h_new_checker[MT_NEW_CHECKER_LEN];
	char h_chng_lst_ind[MT_CHNG_LST_IND_LEN];
	char h_cert_of_own_in[MT_CERT_OF_OWN_IN_LEN];
	char h_instr_name[MT_INSTR_NAME_LEN];
	char h_instr_isin[MT_INSTR_ISIN_LEN];
	char h_tipo_inv[MT_TIPO_INV_LEN];
	char h_instr_type[MT_INSTR_TYPE_LEN];
	char h_instr_parent[MT_INSTR_PARENT_LEN];
	char h_prod_class[MT_PROD_CLASS_LEN];
	char h_sec_dl_code[MT_SEC_DL_CODE_LEN];
	char h_classcd[MT_CLASSCD_LEN];
	char h_new_cd[MT_NEW_CD_LEN];
	char h_chng_isin[MT_CHNG_ISIN_LEN];
	char h_issue_date[APL_DATE_LEN];
	char h_chg_mkr[MT_CHG_MKR_LEN];
	char h_ca_name[MT_CA_NAME_LEN];
	char h_chng_cd[MT_CHNG_CD_LEN];
	char h_mature_dt[APL_DATE_LEN];
	char h_int_typ[MT_INT_TYP_LEN];
	double h_instr_int_rate;
	char h_freq_code[MT_FREQ_CODE_LEN];
	char h_int_acctyp[MT_INT_ACCTYP_LEN];
	char h_last_pymt_date[APL_DATE_LEN];
	int h_last_incom_rt;
	char h_next_pay_date[APL_DATE_LEN];
	char h_old_lst_paydt[APL_DATE_LEN];
	char h_mod_last_paydt[MT_MOD_LAST_PAYDT_LEN];
	char h_taxonmat_ind[MT_TAXONMAT_IND_LEN];
	char h_disct_ind[MT_DISCT_IND_LEN];
	char h_ca_addrdet[MT_CA_ADDRDET_LEN];
	int h_min_fmt_dl_qty;
	char h_lr_setl_date_a[APL_DATE_LEN];
	char h_lr_setl_date_b[APL_DATE_LEN];
	char h_instr_shortnm[MT_INSTR_SHORTNM_LEN];
	char h_ipo_ind[MT_IPO_IND_LEN];
	char h_valid_ipo_date[APL_DATE_LEN];
	char h_lr_setl_date_c[APL_DATE_LEN];
	char h_cmp_code[MT_CMP_CODE_LEN];
	char h_instr_reg_code[MT_INSTR_REG_CODE_LEN];
	char h_instr_swf_name[MT_INSTR_SWF_NAME_LEN];
	char h_instr_priv_placed[MT_INSTR_PRIV_PLACED_LEN];
	char h_instr_crisil_code[MT_INSTR_CRISIL_CODE_LEN];
	char h_instr_is_secured[MT_INSTR_IS_SECURED_LEN];
	char h_instr_secured_dt[APL_DATE_LEN];
	int h_instr_tot_nom_val;
	char h_instr_pc_ind[MT_INSTR_PC_IND_LEN];
	char h_instr_part_rd_flg[MT_INSTR_PART_RD_FLG_LEN];
	char h_instr_reset_flg[MT_INSTR_RESET_FLG_LEN];
	char h_instr_exdt_loa[APL_DATE_LEN];
	char h_instr_fst_pymt_dt[APL_DATE_LEN];
	double h_instr_div_rate;
	char h_instr_is_demat[MT_INSTR_IS_DEMAT_LEN];
	char h_instr_remark[MT_INSTR_REMARK_LEN];
	int h_instrshut_period;
	char h_instr_isin_name[MT_INSTR_ISIN_NAME_LEN];
	char h_instr_attached[MT_INSTR_ATTACHED_LEN];
	char h_instr_detach_dt[APL_DATE_LEN];
	//Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- Start 
	char h_instr_tier_1[2];
	char h_instr_tier_2[2];
	// Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- End 
        /* Added  by Gouse For Decimal Length of MF- Start - 31/10/2011 */
        int h_dec_len_mf;                          
        /* Added  by Gouse For Decimal Length of MF- End - 31/10/2011 */
		//Retro from ICICI for CLM by Bhuvana
	char h_instr_corporate_grp[201];
	double h_instr_diluted_ratio_new;
	double h_instr_diluted_ratio_old;
	//Retro from ICICI for CLM by Bhuvana
}MT_INSTRUMENT_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_currency_cd;
	short i_location_cd;
	short i_nominal_value;
	short i_reg_br_ind;
	short i_allow_rf;
	short i_allow_rvp;
	short i_allow_df;
	short i_allow_dvp;
	short i_ord_type;
	short i_mother_sec_ind;
	short i_ex_arena;
	short i_listed_ind;
	short i_dateof_input;
	short i_threshold_qty;
	short i_new_maker;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_total_pdcapita;
	short i_status;
	short i_new_issue;
	short i_new_checker;
	short i_chng_lst_ind;
	short i_cert_of_own_in;
	short i_instr_name;
	short i_instr_isin;
	short i_tipo_inv;
	short i_instr_type;
	short i_instr_parent;
	short i_prod_class;
	short i_sec_dl_code;
	short i_classcd;
	short i_new_cd;
	short i_chng_isin;
	short i_issue_date;
	short i_chg_mkr;
	short i_ca_name;
	short i_chng_cd;
	short i_mature_dt;
	short i_int_typ;
	short i_instr_int_rate;
	short i_freq_code;
	short i_int_acctyp;
	short i_last_pymt_date;
	short i_last_incom_rt;
	short i_next_pay_date;
	short i_old_lst_paydt;
	short i_mod_last_paydt;
	short i_taxonmat_ind;
	short i_disct_ind;
	short i_ca_addrdet;
	short i_min_fmt_dl_qty;
	short i_lr_setl_date_a;
	short i_lr_setl_date_b;
	short i_instr_shortnm;
	short i_ipo_ind;
	short i_valid_ipo_date;
	short i_lr_setl_date_c;
	short i_cmp_code;
	short i_instr_reg_code;
	short i_instr_swf_name;
	short i_instr_priv_placed;
	short i_instr_crisil_code;
	short i_instr_is_secured;
	short i_instr_secured_dt;
	short i_instr_tot_nom_val;
	short i_instr_pc_ind;
	short i_instr_part_rd_flg;
	short i_instr_reset_flg;
	short i_instr_exdt_loa;
	short i_instr_fst_pymt_dt;
	short i_instr_div_rate;
	short i_instr_is_demat;
	short i_instr_remark;
	short i_instrshut_period;
	short i_instr_isin_name;
	short i_instr_attached;
	short i_instr_detach_dt;
	//Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- Start 
	short i_instr_tier_1;
	short i_instr_tier_2;
	// Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- End 
        /* Added  by Gouse For Decimal Length of MF- Start - 31/10/2011 */
        short i_dec_len_mf;   
        /* Added  by Gouse For Decimal Length of MF- End - 31/10/2011 */
       short i_instr_corporate_grp;
       short i_instr_diluted_ratio_new;
       short i_instr_diluted_ratio_old;
}MT_INSTRUMENT_STRUCT_I;

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_instr_corporate_grp[201];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	
}MT_INST_CORP_GRP_STRUCT_H;

typedef struct{
	short i_instr_code;
	short i_instr_corporate_grp;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	
}MT_INST_CORP_GRP_STRUCT_I;






#define MT_INSTR_CODE_LEN 9

#define MT_EXCH_CODE_LEN 4
#define MT_SCRIP_GRP_LEN 3
#define MT_MKT_TYPE_LEN 3
#define MT_EXCH_INSTR_CODE_LEN 9
#define MT_LISTING_STATUS_LEN 4


#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_scrip_grp[MT_SCRIP_GRP_LEN];
	char h_mkt_type[MT_MKT_TYPE_LEN];
	char h_exch_instr_code[MT_EXCH_INSTR_CODE_LEN];
	char h_listing_status[MT_LISTING_STATUS_LEN];
	char h_listing_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INSTR_EXCH_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_exch_code;
	short i_scrip_grp;
	short i_mkt_type;
	short i_exch_instr_code;
	short i_listing_status;
	short i_listing_date;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_INSTR_EXCH_DET_STRUCT_I;







#define MT_INSTR_CODE_LEN 9

#define MT_CR_AGENCY_CODE_LEN 7
#define MT_RATING_CODE_LEN 6



#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_cr_agency_code[MT_CR_AGENCY_CODE_LEN];
	char h_rating_code[MT_RATING_CODE_LEN];
	char h_effdt_fr[APL_DATE_LEN];
	char h_effdt_to[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INSTR_RATING_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_cr_agency_code;
	short i_rating_code;
	short i_effdt_fr;
	short i_effdt_to;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_INSTR_RATING_DET_STRUCT_I;







#define MT_LOCATION_CD_LEN 5
#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15


#define MT_STATUS_POS_LEN 4
#define MT_MANIFLD_IND_LEN 2
#define MT_LOC_STATUS_LEN 3
#define MT_LOCATION_DESC_LEN 31
#define MT_PHYSICAL_IND_LEN 2
#define MT_ISO_LOCNCD_LEN 5
#define MT_AVAIL_IND_LEN 5
#define MT_DEPO_LEN 4
typedef struct{
	char h_location_cd[MT_LOCATION_CD_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_pos[MT_STATUS_POS_LEN];
	char h_manifld_ind[MT_MANIFLD_IND_LEN];
	char h_loc_status[MT_LOC_STATUS_LEN];
	char h_location_desc[MT_LOCATION_DESC_LEN];
	char h_physical_ind[MT_PHYSICAL_IND_LEN];
	char h_iso_locncd[MT_ISO_LOCNCD_LEN];
	char h_avail_ind[MT_AVAIL_IND_LEN];
	char h_depo[MT_DEPO_LEN];
}MT_LOCATION_STRUCT_H;
typedef struct{
	short i_location_cd;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_status_pos;
	short i_manifld_ind;
	short i_loc_status;
	short i_location_desc;
	short i_physical_ind;
	short i_iso_locncd;
	short i_avail_ind;
	short i_depo;
}MT_LOCATION_STRUCT_I;







#define MT_SND_MSG_TO_ALLMAST_LEN 2
#define MT_MSG569_PREMATCH_IND_LEN 2


#define MT_GEN_FX_ADV_IND_LEN 2
#define MT_SWIFT_CD_LEN 12
#define MT_GCN_CD_LEN 6
#define MT_AUTO_MSG_RPR_IND_LEN 2
#define MT_REG_FOLLOW_MSG_IND_LEN 2


#define MT_MS_VTB_MSG_ADDR_LEN 12

#define MT_CCS_INT_IND_LEN 2
#define MT_LINE_IND_LEN 4
/*
typedef struct{
	char h_snd_msg_to_allmast[MT_SND_MSG_TO_ALLMAST_LEN];
	char h_msg569_prematch_ind[MT_MSG569_PREMATCH_IND_LEN];
	int h_allowed_tlx_len;
	int h_allowed_retension_prd;
	char h_gen_fx_adv_ind[MT_GEN_FX_ADV_IND_LEN];
	char h_swift_cd[MT_SWIFT_CD_LEN];
	char h_gcn_cd[MT_GCN_CD_LEN];
	char h_auto_msg_rpr_ind[MT_AUTO_MSG_RPR_IND_LEN];
	char h_reg_follow_msg_ind[MT_REG_FOLLOW_MSG_IND_LEN];
	int h_msg_follow_days1;
	int h_msg_follow_days2;
	char h_ms_vtb_msg_addr[MT_MS_VTB_MSG_ADDR_LEN];
	int h_response_days;
	char h_ccs_int_ind[MT_CCS_INT_IND_LEN];
	char h_line_ind[MT_LINE_IND_LEN];
}MT_MESSAGE_SYS_PARAMS_STRUCT_H;
typedef struct{
	short i_snd_msg_to_allmast;
	short i_msg569_prematch_ind;
	short i_allowed_tlx_len;
	short i_allowed_retension_prd;
	short i_gen_fx_adv_ind;
	short i_swift_cd;
	short i_gcn_cd;
	short i_auto_msg_rpr_ind;
	short i_reg_follow_msg_ind;
	short i_msg_follow_days1;
	short i_msg_follow_days2;
	short i_ms_vtb_msg_addr;
	short i_response_days;
	short i_ccs_int_ind;
	short i_line_ind;
}MT_MESSAGE_SYS_PARAMS_STRUCT_I;*/








#define MT_INSTR_CODE_LEN 9

typedef struct{
	char h_price_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_closing_pr;
}MT_MKTPRC_GEN_VEW_STRUCT_H;
typedef struct{
	short i_price_date;
	short i_instr_code;
	short i_closing_pr;
}MT_MKTPRC_GEN_VEW_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_MSG_NO_LEN 3

#define MT_CLN_MSG_TYP_LEN 2
#define MT_CLN_MSG_PRIORITY_LEN 2
#define MT_CLN_MSG_GCN_ADDR_LEN 6
#define MT_CLN_MSG_SWF_ADDR_LEN 12
#define MT_CLN_MSG_TLX_ADDR_LEN 12
#define MT_CLN_MSG_CATEGORY_LEN 5
#define MT_CLN_MSG_CONSMSG_LEN 2
#define MT_CLN_MSG_FAX_LEN 15
#define MT_CLN_MSG_REFER_LEN 41

#define MT_CLN_MSG_NOHOLDINGS_LEN 2

#define MT_CLN_MSG_ISO15022FORMAT_LEN 2
#define MT_CLN_MSG_EVALUATE_FLG_LEN 4
#define MT_CLN_MSG_RESP_CONS54X_LEN 2
#define MT_CLN_MSG_GEN_REC_DP_LEN 2
#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_msg_no[MT_CLN_MSG_NO_LEN];
	int h_cln_seq_num;
	char h_cln_msg_typ[MT_CLN_MSG_TYP_LEN];
	char h_cln_msg_priority[MT_CLN_MSG_PRIORITY_LEN];
	char h_cln_msg_gcn_addr[MT_CLN_MSG_GCN_ADDR_LEN];
	char h_cln_msg_swf_addr[MT_CLN_MSG_SWF_ADDR_LEN];
	char h_cln_msg_tlx_addr[MT_CLN_MSG_TLX_ADDR_LEN];
	char h_cln_msg_category[MT_CLN_MSG_CATEGORY_LEN];
	char h_cln_msg_consmsg[MT_CLN_MSG_CONSMSG_LEN];
	char h_cln_msg_fax[MT_CLN_MSG_FAX_LEN];
	char h_cln_msg_refer[MT_CLN_MSG_REFER_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_cln_msg_noholdings[MT_CLN_MSG_NOHOLDINGS_LEN];
	int h_cln_msg_schseq_num;
	char h_cln_msg_iso15022format[MT_CLN_MSG_ISO15022FORMAT_LEN];
	char h_cln_msg_evaluate_flg[MT_CLN_MSG_EVALUATE_FLG_LEN];
	char h_cln_msg_resp_cons54x[MT_CLN_MSG_RESP_CONS54X_LEN];
	char h_cln_msg_gen_rec_dp[MT_CLN_MSG_GEN_REC_DP_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_MSGADDRESS_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_msg_no;
	short i_cln_seq_num;
	short i_cln_msg_typ;
	short i_cln_msg_priority;
	short i_cln_msg_gcn_addr;
	short i_cln_msg_swf_addr;
	short i_cln_msg_tlx_addr;
	short i_cln_msg_category;
	short i_cln_msg_consmsg;
	short i_cln_msg_fax;
	short i_cln_msg_refer;
	short i_access_stamp;
	short i_cln_msg_noholdings;
	short i_cln_msg_schseq_num;
	short i_cln_msg_iso15022format;
	short i_cln_msg_evaluate_flg;
	short i_cln_msg_resp_cons54x;
	short i_cln_msg_gen_rec_dp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_MSGADDRESS_STRUCT_I;
























/*
typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}MT_MSGADDRESS_VEW_STRUCT_H;
*/
typedef struct{
	short i_client;
	short i_msg_ident_no;
	short i_contactseq;
	short i_swift_tlx_gcn;
	short i_priority_ind;
	short i_gcn_addr;
	short i_swift_addr;
	short i_telex_addr;
	short i_schedule;
	short i_comb_msg;
	short i_fax_addr;
	short i_identify;
	short i_access_stamp;
	short i_holdings;
	short i_schiden_no;
	short i_iso_msg_format;
	short i_validate_ind;
	short i_generate_ind;
}MT_MSGADDRESS_VEW_STRUCT_I;







#define MT_INSTR_CODE_LEN 9


typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_open_pr;
	double h_closing_pr;
}MT_MTHLYMKTPRC_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_open_pr;
	short i_closing_pr;
}MT_MTHLYMKTPRC_STRUCT_I;







#define MT_EXCH_CODE_LEN 4
#define MT_INSTR_CODE_LEN 9


#define MT_MKT_TYPE_LEN 4
#define MT_CARRY_FW_STLNO_LEN 12
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_no_del_from[APL_DATE_LEN];
	char h_no_del_to[APL_DATE_LEN];
	char h_mkt_type[MT_MKT_TYPE_LEN];
	char h_carry_fw_stlno[MT_CARRY_FW_STLNO_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_NO_DELV_STRUCT_H;
typedef struct{
	short i_exch_code;
	short i_instr_code;
	short i_no_del_from;
	short i_no_del_to;
	short i_mkt_type;
	short i_carry_fw_stlno;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_NO_DELV_STRUCT_I;







#define MT_PTY_CODE_LEN 11
#define MT_PTY_NAME_LEN 66
#define MT_PTY_SHORTNM_LEN 13
#define MT_PTY_MAPINID_LEN 13
#define MT_PTY_TYPE_LEN 2
#define MT_PTY_ADD1_LEN 61
#define MT_PTY_ADD2_LEN 61
#define MT_CITY_LEN 21
#define MT_STATE_LEN 21
#define MT_COUNTRY_LEN 21
#define MT_PTY_ADD_PIN_LEN 11
#define MT_PTY_TEL_LEN 21
#define MT_PTY_FAX_LEN 21
#define MT_PTY_EMAIL_LEN 61
#define MT_PTY_CONTACT1_LEN 66
#define MT_PTY_CONTACT2_LEN 66
#define MT_PTY_SWF_NAME_LEN 21
#define MT_PTY_SWF_ADD_LEN 12
#define MT_PTY_SEBI_REG_NO_LEN 21
#define MT_PTY_PAN_LEN 21
#define MT_PTY_LC_NAME_LEN 66
#define MT_PTY_LC_ADD_LEN 201
#define MT_PTY_LC_TEL_LEN 21
#define MT_PTY_LC_EMAIL_LEN 61
#define MT_PTY_LC_FAX_LEN 21
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 21

#define MT_STATUS_LEN 3
#define MT_PTY_BIC_CODE_LEN 14
#define MT_SET_EXCH_CODE_LEN 11  //Added for INTEROPERABILITY - 12174
typedef struct{
	char h_pty_code[MT_PTY_CODE_LEN];
	char h_pty_name[MT_PTY_NAME_LEN];
	char h_pty_shortnm[MT_PTY_SHORTNM_LEN];
	char h_pty_mapinid[MT_PTY_MAPINID_LEN];
	char h_pty_type[MT_PTY_TYPE_LEN];
	char h_pty_add1[MT_PTY_ADD1_LEN];
	char h_pty_add2[MT_PTY_ADD2_LEN];
	char h_city[MT_CITY_LEN];
	char h_state[MT_STATE_LEN];
	char h_country[MT_COUNTRY_LEN];
	char h_pty_add_pin[MT_PTY_ADD_PIN_LEN];
	char h_pty_tel[MT_PTY_TEL_LEN];
	char h_pty_fax[MT_PTY_FAX_LEN];
	char h_pty_email[MT_PTY_EMAIL_LEN];
	char h_pty_contact1[MT_PTY_CONTACT1_LEN];
	char h_pty_contact2[MT_PTY_CONTACT2_LEN];
	char h_pty_swf_name[MT_PTY_SWF_NAME_LEN];
	char h_pty_swf_add[MT_PTY_SWF_ADD_LEN];
	char h_pty_sebi_reg_no[MT_PTY_SEBI_REG_NO_LEN];
	char h_pty_pan[MT_PTY_PAN_LEN];
	char h_pty_lc_name[MT_PTY_LC_NAME_LEN];
	char h_pty_lc_add[MT_PTY_LC_ADD_LEN];
	char h_pty_lc_tel[MT_PTY_LC_TEL_LEN];
	char h_pty_lc_email[MT_PTY_LC_EMAIL_LEN];
	char h_pty_lc_fax[MT_PTY_LC_FAX_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
        char h_set_exch_code[MT_SET_EXCH_CODE_LEN];    //Added for INTEROPERABILITY - 12174
		char h_csgl_apl[2];
}MT_PARTY_STRUCT_H;
typedef struct{
	short i_pty_code;
	short i_pty_name;
	short i_pty_shortnm;
	short i_pty_mapinid;
	short i_pty_type;
	short i_pty_add1;
	short i_pty_add2;
	short i_city;
	short i_state;
	short i_country;
	short i_pty_add_pin;
	short i_pty_tel;
	short i_pty_fax;
	short i_pty_email;
	short i_pty_contact1;
	short i_pty_contact2;
	short i_pty_swf_name;
	short i_pty_swf_add;
	short i_pty_sebi_reg_no;
	short i_pty_pan;
	short i_pty_lc_name;
	short i_pty_lc_add;
	short i_pty_lc_tel;
	short i_pty_lc_email;
	short i_pty_lc_fax;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
        short i_set_exch_code;     //Added for INTEROPERABILITY - 12174
		short i_csgl_apl;
}MT_PARTY_STRUCT_I;







#define MT_INSTR_CODE_LEN 9

#define MT_PC_FLAG_LEN 2




#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_pc_flag[MT_PC_FLAG_LEN];
	char h_pc_date[APL_DATE_LEN];
	char h_pc_notice_date[APL_DATE_LEN];
	char h_instr_pc_effdt[APL_DATE_LEN];
	char h_instr_pc_cutofftime[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_PC_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_pc_flag;
	short i_pc_date;
	short i_pc_notice_date;
	short i_instr_pc_effdt;
	short i_instr_pc_cutofftime;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_PC_DET_STRUCT_I;







#define MT_INSTR_CODE_LEN 9





#define MT_PTC_PAID_FLG_LEN 2

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_ptc_dt[APL_DATE_LEN];
	int h_ptc_prin_amt;
	int h_ptc_int_amt;
	int h_ptc_value;
	char h_ptc_paid_flg[MT_PTC_PAID_FLG_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_PTC_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_ptc_dt;
	short i_ptc_prin_amt;
	short i_ptc_int_amt;
	short i_ptc_value;
	short i_ptc_paid_flg;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_PTC_DET_STRUCT_I;







#define MT_PTY_CODE_LEN 11
#define MT_DEPO_CODE_LEN 5
#define MT_PTY_DEPO_MAP_CLIENT_ID_LEN 21
#define MT_PTY_DEPO_MAP_DP_ID_LEN 21

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 21

#define MT_STATUS_LEN 3
typedef struct{
	char h_pty_code[MT_PTY_CODE_LEN];
	char h_depo_code[MT_DEPO_CODE_LEN];
	char h_pty_depo_map_client_id[MT_PTY_DEPO_MAP_CLIENT_ID_LEN];
	char h_pty_depo_map_dp_id[MT_PTY_DEPO_MAP_DP_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_PTY_DEPO_MAP_STRUCT_H;
typedef struct{
	short i_pty_code;
	short i_depo_code;
	short i_pty_depo_map_client_id;
	short i_pty_depo_map_dp_id;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_PTY_DEPO_MAP_STRUCT_I;







#define MT_PTY_CODE_LEN 11
#define MT_EXCH_CODE_LEN 5
#define MT_CLN_CODE_LEN 11
#define MT_PTY_EXCH_CLN_MAP_CODE_LEN 21

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 21

#define MT_STATUS_LEN 3
typedef struct{
	char h_pty_code[MT_PTY_CODE_LEN];
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_pty_exch_cln_map_code[MT_PTY_EXCH_CLN_MAP_CODE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_PTY_EXCH_CLN_MAP_STRUCT_H;
typedef struct{
	short i_pty_code;
	short i_exch_code;
	short i_cln_code;
	short i_pty_exch_cln_map_code;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_PTY_EXCH_CLN_MAP_STRUCT_I;







#define MT_PTY_CODE_LEN 11
#define MT_EXCH_CODE_LEN 4
#define MT_PTY_EXCH_MAP_CODE_LEN 21
#define MT_PTY_CMBP_ID_LEN 21
#define MT_PTY_CCCM_ID_LEN 21

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 21

#define MT_STATUS_LEN 3
typedef struct{
	char h_pty_code[MT_PTY_CODE_LEN];
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_pty_exch_map_code[MT_PTY_EXCH_MAP_CODE_LEN];
	char h_pty_cmbp_id[MT_PTY_CMBP_ID_LEN];
	char h_pty_cccm_id[MT_PTY_CCCM_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_PTY_EXCH_MAP_STRUCT_H;
typedef struct{
	short i_pty_code;
	short i_exch_code;
	short i_pty_exch_map_code;
	short i_pty_cmbp_id;
	short i_pty_cccm_id;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_PTY_EXCH_MAP_STRUCT_I;







#define MT_INSTR_CODE_LEN 9
#define MT_RBI_INSTR_CODE_LEN 21





#define MT_CAUTION_FLG_LEN 2


#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_rbi_instr_code[MT_RBI_INSTR_CODE_LEN];
	double h_tpcapital;
	double h_sng_fii_limit;
	double h_ovr_fii_limit;
	double h_sng_nriocb_limit;
	double h_ovr_nriocb_limit;
	char h_caution_flg[MT_CAUTION_FLG_LEN];
	double h_caution_fii;
	double h_caution_nriocb;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_RBI_MONITORY_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_rbi_instr_code;
	short i_tpcapital;
	short i_sng_fii_limit;
	short i_ovr_fii_limit;
	short i_sng_nriocb_limit;
	short i_ovr_nriocb_limit;
	short i_caution_flg;
	short i_caution_fii;
	short i_caution_nriocb;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_RBI_MONITORY_STRUCT_I;







#define MT_INSTR_CODE_LEN 9





#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_red_dt[APL_DATE_LEN];
	int h_red_pct;
	double h_red_value;
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_RED_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_red_dt;
	short i_red_pct;
	short i_red_value;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_RED_DET_STRUCT_I;







#define MT_INSTR_CODE_LEN 9

#define MT_RD_CLIENT_ID_LEN 21
#define MT_RD_DP_ID_LEN 21
#define MT_RD_DEPO_CODE_LEN 21
#define MT_IPA_CODE_LEN 11
#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_rd_client_id[MT_RD_CLIENT_ID_LEN];
	char h_rd_dp_id[MT_RD_DP_ID_LEN];
	char h_rd_depo_code[MT_RD_DEPO_CODE_LEN];
	char h_ipa_code[MT_IPA_CODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_RED_DP_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_rd_client_id;
	short i_rd_dp_id;
	short i_rd_depo_code;
	short i_ipa_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_RED_DP_DET_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_SEBI_REG_NO_LEN 21


#define MT_CLN_RBI_REG_NO_LEN 21


#define MT_CLN_MAPINID_LEN 13
#define MT_CLN_UCC_CODE_LEN 13

#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_sebi_reg_no[MT_CLN_SEBI_REG_NO_LEN];
	char h_cln_sebi_reg_dt[APL_DATE_LEN];
	char h_cln_sebi_reg_expdt[APL_DATE_LEN];
	char h_cln_rbi_reg_no[MT_CLN_RBI_REG_NO_LEN];
	char h_cln_rbi_reg_dt[APL_DATE_LEN];
	char h_cln_rbi_reg_expdt[APL_DATE_LEN];
	char h_cln_mapinid[MT_CLN_MAPINID_LEN];
	char h_cln_ucc_code[MT_CLN_UCC_CODE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_sebi_sub_acc[8];
}MT_REGDETAILS_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_sebi_reg_no;
	short i_cln_sebi_reg_dt;
	short i_cln_sebi_reg_expdt;
	short i_cln_rbi_reg_no;
	short i_cln_rbi_reg_dt;
	short i_cln_rbi_reg_expdt;
	short i_cln_mapinid;
	short i_cln_ucc_code;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_sebi_sub_acc;
}MT_REGDETAILS_STRUCT_I;







#define MT_INSTR_CODE_LEN 9






#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_reset_dt[APL_DATE_LEN];
	int h_reset_rate;
	char h_reset_frdt[APL_DATE_LEN];
	char h_reset_todt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_RESET_DET_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_reset_dt;
	short i_reset_rate;
	short i_reset_frdt;
	short i_reset_todt;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_RESET_DET_STRUCT_I;







#define MT_CLN_CODE_LEN 11
#define MT_CLN_MSG_NO_LEN 3

#define MT_CLN_SCH_EOM_LEN 2
#define MT_CLN_SCH_GEN_ON_DAY_LEN 8
#define MT_CLN_SCH_NOPOSTXNFLG_LEN 2
#define MT_CLN_SCH_ZEROMOV_LEN 2
#define MT_CLN_SCH_MSGOPTION_LEN 2
#define MT_CLN_SCH_DEPO_STAT_LEN 2

#define MT_CLN_SCH_NOPEND_LEN 2
#define MT_CLN_SCH_WEEKSTM_LEN 2
#define MT_CLN_SCH_EVALUATE_FLG_LEN 9
#define MT_MAKER_LEN 15

#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_cln_code[MT_CLN_CODE_LEN];
	char h_cln_msg_no[MT_CLN_MSG_NO_LEN];
	int h_cln_seq_num;
	char h_cln_sch_eom[MT_CLN_SCH_EOM_LEN];
	char h_cln_sch_gen_on_day[MT_CLN_SCH_GEN_ON_DAY_LEN];
	char h_cln_sch_nopostxnflg[MT_CLN_SCH_NOPOSTXNFLG_LEN];
	char h_cln_sch_zeromov[MT_CLN_SCH_ZEROMOV_LEN];
	char h_cln_sch_msgoption[MT_CLN_SCH_MSGOPTION_LEN];
	char h_cln_sch_depo_stat[MT_CLN_SCH_DEPO_STAT_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_cln_sch_nopend[MT_CLN_SCH_NOPEND_LEN];
	char h_cln_sch_weekstm[MT_CLN_SCH_WEEKSTM_LEN];
	char h_cln_sch_evaluate_flg[MT_CLN_SCH_EVALUATE_FLG_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_SCHDET_STRUCT_H;
typedef struct{
	short i_cln_code;
	short i_cln_msg_no;
	short i_cln_seq_num;
	short i_cln_sch_eom;
	short i_cln_sch_gen_on_day;
	short i_cln_sch_nopostxnflg;
	short i_cln_sch_zeromov;
	short i_cln_sch_msgoption;
	short i_cln_sch_depo_stat;
	short i_access_stamp;
	short i_cln_sch_nopend;
	short i_cln_sch_weekstm;
	short i_cln_sch_evaluate_flg;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_SCHDET_STRUCT_I;







#define MT_T_ROW_ID_LEN 19

typedef struct{
	char h_t_row_id[MT_T_ROW_ID_LEN];
	char h_dealdt[APL_DATE_LEN];
}MT_SCHDET_TEMP_STRUCT_H;
typedef struct{
	short i_t_row_id;
	short i_dealdt;
}MT_SCHDET_TEMP_STRUCT_I;


















/*

typedef struct{
	
	
	
	
	
	
	
	
	
	
	
	
	
}MT_SCHDET_VEW_STRUCT_H;
*/
typedef struct{
	short i_client;
	short i_msg_ident_no;
	short i_schiden_no;
	short i_eom_msg_ind;
	short i_generate_day;
	short i_pos_txn_ind;
	short i_nil_mov_ind;
	short i_msg_opt;
	short i_loc_stat;
	short i_access_stamp;
	short i_pend_ind;
	short i_weeklystmt;
	short i_validate_ind;
}MT_SCHDET_VEW_STRUCT_I;







#define MT_EXCH_CODE_LEN 4
#define MT_SETTL_NO_LEN 12
#define MT_CC_ID_LEN 9
#define MT_SETTL_TYPE_LEN 4



#define MT_NSDL_DEADLINE_TM_LEN 9



#define MT_MAKER_LEN 15


#define MT_CHECKER_LEN 15

#define MT_STATUS_LEN 3
typedef struct{
	char h_exch_code[MT_EXCH_CODE_LEN];
	char h_settl_no[MT_SETTL_NO_LEN];
	char h_cc_id[MT_CC_ID_LEN];
	char h_settl_type[MT_SETTL_TYPE_LEN];
	char h_start_date[APL_DATE_LEN];
	char h_end_date[APL_DATE_LEN];
	char h_nsdl_deadline_dt[APL_DATE_LEN];
	char h_nsdl_deadline_tm[MT_NSDL_DEADLINE_TM_LEN];
	char h_pay_in_dt[APL_DATE_LEN];
	char h_pay_out_dt[APL_DATE_LEN];
	char h_auction_dt[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_SETTL_CAL_STRUCT_H;
typedef struct{
	short i_exch_code;
	short i_settl_no;
	short i_cc_id;
	short i_settl_type;
	short i_start_date;
	short i_end_date;
	short i_nsdl_deadline_dt;
	short i_nsdl_deadline_tm;
	short i_pay_in_dt;
	short i_pay_out_dt;
	short i_auction_dt;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_SETTL_CAL_STRUCT_I;








#define MT_INSTR_CODE_LEN 9

#define MT_MODIFYMOD_LEN 2

#define MT_MAKER_LEN 15

#define MT_MKRTPR_STAT_LEN 3
#define MT_CHECKER_LEN 15

typedef struct{
	char h_price_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	double h_closing_pr;
	char h_modifymod[MT_MODIFYMOD_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_mkrtpr_stat[MT_MKRTPR_STAT_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
}MT_TEMPMKTPRC_STRUCT_H;
typedef struct{
	short i_price_date;
	short i_instr_code;
	short i_closing_pr;
	short i_modifymod;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_mkrtpr_stat;
	short i_checker;
	short i_checker_dt;
}MT_TEMPMKTPRC_STRUCT_I;







#define MT_NATION_CD_LEN 3
#define MT_PROD_CLASS_LEN 3

#define MT_MAKER_LEN 15


#define MT_STATUS_IND_LEN 3
#define MT_CHECKER_LEN 21

typedef struct{
	char h_nation_cd[MT_NATION_CD_LEN];
	char h_prod_class[MT_PROD_CLASS_LEN];
	double h_custodytaxrt;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status_ind[MT_STATUS_IND_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
}MT_WHTRATE_STRUCT_H;
typedef struct{
	short i_nation_cd;
	short i_prod_class;
	short i_custodytaxrt;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_status_ind;
	short i_checker;
	short i_checker_dt;
}MT_WHTRATE_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_IDENTIY_NO_LEN 17







#define OR_TAX_LEN 2
#define OR_RESET_IND_LEN 2
#define OR_ORD_REFNO_LEN 17
typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_identiy_no[OR_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_qty;
	double h_cost;
	char h_exec_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_brokercomm;
	char h_tax[OR_TAX_LEN];
	char h_reset_ind[OR_RESET_IND_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
}OR_ARCHEXEC_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_qty;
	short i_cost;
	short i_exec_date;
	short i_access_stamp;
	short i_brokercomm;
	short i_tax;
	short i_reset_ind;
	short i_ord_refno;
}OR_ARCHEXEC_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_ORD_REFNO_LEN 17
#define OR_BUY_SELL_IND_LEN 2


#define OR_LIMIT_IND_LEN 2
#define OR_ISGTE_IND_LEN 2
#define OR_ALL_NONE_IND_LEN 2
#define OR_EX_ARENA_LEN 3
#define OR_ORD_STAT_LEN 3
#define OR_INSTR_CODE_LEN 9
#define OR_MAKER_LEN 15


#define OR_CHECKER_LEN 15






#define OR_BROKER_CD_LEN 11
#define OR_LCL_IDENTNO_LEN 17
#define OR_LR_DL_CLASS_LEN 3




#define OR_LAST_DL_DATE_LEN 17
#define OR_CLNT_NAME_LEN 66
#define OR_INSTR_NAME_LEN 131

typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
	char h_buy_sell_ind[OR_BUY_SELL_IND_LEN];
	char h_ord_date[APL_DATE_LEN];
	double h_ord_qty;
	char h_limit_ind[OR_LIMIT_IND_LEN];
	char h_isgte_ind[OR_ISGTE_IND_LEN];
	char h_all_none_ind[OR_ALL_NONE_IND_LEN];
	char h_ex_arena[OR_EX_ARENA_LEN];
	char h_ord_stat[OR_ORD_STAT_LEN];
	char h_instr_code[OR_INSTR_CODE_LEN];
	char h_maker[OR_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[OR_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_exp_date[APL_DATE_LEN];
	double h_limit_pr;
	char h_dateof_cancel[APL_DATE_LEN];
	double h_exec_qty;
	char h_allow_dropdt[APL_DATE_LEN];
	char h_broker_cd[OR_BROKER_CD_LEN];
	char h_lcl_identno[OR_LCL_IDENTNO_LEN];
	char h_lr_dl_class[OR_LR_DL_CLASS_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	char h_last_exec_date[APL_DATE_LEN];
	char h_last_dl_date[OR_LAST_DL_DATE_LEN];
	char h_clnt_name[OR_CLNT_NAME_LEN];
	char h_instr_name[OR_INSTR_NAME_LEN];
	char h_closing_date[APL_DATE_LEN];
}OR_ARCHORDERS_STRUCT_H;
typedef struct{
	short i_client;
	short i_ord_refno;
	short i_buy_sell_ind;
	short i_ord_date;
	short i_ord_qty;
	short i_limit_ind;
	short i_isgte_ind;
	short i_all_none_ind;
	short i_ex_arena;
	short i_ord_stat;
	short i_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_exp_date;
	short i_limit_pr;
	short i_dateof_cancel;
	short i_exec_qty;
	short i_allow_dropdt;
	short i_broker_cd;
	short i_lcl_identno;
	short i_lr_dl_class;
	short i_lr_check_date;
	short i_lr_unblk_date;
	short i_unblk_date;
	short i_last_exec_date;
	short i_last_dl_date;
	short i_clnt_name;
	short i_instr_name;
	short i_closing_date;
}OR_ARCHORDERS_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_IDENTIY_NO_LEN 17







#define OR_TAX_LEN 2
#define OR_RESET_IND_LEN 2
#define OR_ORD_REFNO_LEN 17
typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_identiy_no[OR_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_qty;
	double h_cost;
	char h_exec_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_brokercomm;
	char h_tax[OR_TAX_LEN];
	char h_reset_ind[OR_RESET_IND_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
}OR_EXECORDER_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_qty;
	short i_cost;
	short i_exec_date;
	short i_access_stamp;
	short i_brokercomm;
	short i_tax;
	short i_reset_ind;
	short i_ord_refno;
}OR_EXECORDER_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_IDENTIY_NO_LEN 17







#define OR_TAX_LEN 2
#define OR_RESET_IND_LEN 2
#define OR_ORD_REFNO_LEN 17
typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_identiy_no[OR_IDENTIY_NO_LEN];
	char h_deal_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
	double h_qty;
	double h_cost;
	char h_exec_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	double h_brokercomm;
	char h_tax[OR_TAX_LEN];
	char h_reset_ind[OR_RESET_IND_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
}OR_HISEXECORDER_STRUCT_H;
typedef struct{
	short i_client;
	short i_identiy_no;
	short i_deal_date;
	short i_setl_date;
	short i_qty;
	short i_cost;
	short i_exec_date;
	short i_access_stamp;
	short i_brokercomm;
	short i_tax;
	short i_reset_ind;
	short i_ord_refno;
}OR_HISEXECORDER_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_ORD_REFNO_LEN 17
#define OR_BUY_SELL_IND_LEN 2


#define OR_LIMIT_IND_LEN 2
#define OR_ISGTE_IND_LEN 2
#define OR_ALL_NONE_IND_LEN 2
#define OR_EX_ARENA_LEN 3
#define OR_ORD_STAT_LEN 3
#define OR_INSTR_CODE_LEN 9
#define OR_MAKER_LEN 15


#define OR_CHECKER_LEN 15






#define OR_BROKER_CD_LEN 11
#define OR_LCL_IDENTNO_LEN 17
#define OR_LR_DL_CLASS_LEN 3




#define OR_LAST_DL_DATE_LEN 17
#define OR_CLNT_NAME_LEN 66
#define OR_INSTR_NAME_LEN 131

typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
	char h_buy_sell_ind[OR_BUY_SELL_IND_LEN];
	char h_ord_date[APL_DATE_LEN];
	double h_ord_qty;
	char h_limit_ind[OR_LIMIT_IND_LEN];
	char h_isgte_ind[OR_ISGTE_IND_LEN];
	char h_all_none_ind[OR_ALL_NONE_IND_LEN];
	char h_ex_arena[OR_EX_ARENA_LEN];
	char h_ord_stat[OR_ORD_STAT_LEN];
	char h_instr_code[OR_INSTR_CODE_LEN];
	char h_maker[OR_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[OR_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_exp_date[APL_DATE_LEN];
	double h_limit_pr;
	char h_dateof_cancel[APL_DATE_LEN];
	double h_exec_qty;
	char h_allow_dropdt[APL_DATE_LEN];
	char h_broker_cd[OR_BROKER_CD_LEN];
	char h_lcl_identno[OR_LCL_IDENTNO_LEN];
	char h_lr_dl_class[OR_LR_DL_CLASS_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	char h_last_exec_date[APL_DATE_LEN];
	char h_last_dl_date[OR_LAST_DL_DATE_LEN];
	char h_clnt_name[OR_CLNT_NAME_LEN];
	char h_instr_name[OR_INSTR_NAME_LEN];
	char h_closing_date[APL_DATE_LEN];
}OR_HISORDER_STRUCT_H;
typedef struct{
	short i_client;
	short i_ord_refno;
	short i_buy_sell_ind;
	short i_ord_date;
	short i_ord_qty;
	short i_limit_ind;
	short i_isgte_ind;
	short i_all_none_ind;
	short i_ex_arena;
	short i_ord_stat;
	short i_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_exp_date;
	short i_limit_pr;
	short i_dateof_cancel;
	short i_exec_qty;
	short i_allow_dropdt;
	short i_broker_cd;
	short i_lcl_identno;
	short i_lr_dl_class;
	short i_lr_check_date;
	short i_lr_unblk_date;
	short i_unblk_date;
	short i_last_exec_date;
	short i_last_dl_date;
	short i_clnt_name;
	short i_instr_name;
	short i_closing_date;
}OR_HISORDER_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_ORD_REFNO_LEN 17
#define OR_BUY_SELL_IND_LEN 2


#define OR_LIMIT_IND_LEN 2
#define OR_ISGTE_IND_LEN 2
#define OR_ALL_NONE_IND_LEN 2
#define OR_EX_ARENA_LEN 3
#define OR_ORD_STAT_LEN 3
#define OR_INSTR_CODE_LEN 9
#define OR_MAKER_LEN 15


#define OR_CHECKER_LEN 15






#define OR_BROKER_CD_LEN 11
#define OR_LCL_IDENTNO_LEN 17
#define OR_LR_DL_CLASS_LEN 3




#define OR_LAST_DL_DATE_LEN 17
typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
	char h_buy_sell_ind[OR_BUY_SELL_IND_LEN];
	char h_ord_date[APL_DATE_LEN];
	double h_ord_qty;
	char h_limit_ind[OR_LIMIT_IND_LEN];
	char h_isgte_ind[OR_ISGTE_IND_LEN];
	char h_all_none_ind[OR_ALL_NONE_IND_LEN];
	char h_ex_arena[OR_EX_ARENA_LEN];
	char h_ord_stat[OR_ORD_STAT_LEN];
	char h_instr_code[OR_INSTR_CODE_LEN];
	char h_maker[OR_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[OR_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_exp_date[APL_DATE_LEN];
	double h_limit_pr;
	char h_dateof_cancel[APL_DATE_LEN];
	double h_exec_qty;
	char h_allow_dropdt[APL_DATE_LEN];
	char h_broker_cd[OR_BROKER_CD_LEN];
	char h_lcl_identno[OR_LCL_IDENTNO_LEN];
	char h_lr_dl_class[OR_LR_DL_CLASS_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	char h_last_exec_date[APL_DATE_LEN];
	char h_last_dl_date[OR_LAST_DL_DATE_LEN];
}OR_ORDERDETAILS_STRUCT_H;
typedef struct{
	short i_client;
	short i_ord_refno;
	short i_buy_sell_ind;
	short i_ord_date;
	short i_ord_qty;
	short i_limit_ind;
	short i_isgte_ind;
	short i_all_none_ind;
	short i_ex_arena;
	short i_ord_stat;
	short i_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_exp_date;
	short i_limit_pr;
	short i_dateof_cancel;
	short i_exec_qty;
	short i_allow_dropdt;
	short i_broker_cd;
	short i_lcl_identno;
	short i_lr_dl_class;
	short i_lr_check_date;
	short i_lr_unblk_date;
	short i_unblk_date;
	short i_last_exec_date;
	short i_last_dl_date;
}OR_ORDERDETAILS_STRUCT_I;







#define OR_CLIENT_LEN 11
#define OR_ORD_REFNO_LEN 17
#define OR_BUY_SELL_IND_LEN 2


#define OR_LIMIT_IND_LEN 2
#define OR_ISGTE_IND_LEN 2
#define OR_ALL_NONE_IND_LEN 2
#define OR_EX_ARENA_LEN 3
#define OR_ORD_STAT_LEN 3
#define OR_INSTR_CODE_LEN 9
#define OR_MAKER_LEN 15


#define OR_CHECKER_LEN 15






#define OR_BROKER_CD_LEN 11
#define OR_LCL_IDENTNO_LEN 17
#define OR_LR_DL_CLASS_LEN 3




#define OR_LAST_DL_DATE_LEN 17
typedef struct{
	char h_client[OR_CLIENT_LEN];
	char h_ord_refno[OR_ORD_REFNO_LEN];
	char h_buy_sell_ind[OR_BUY_SELL_IND_LEN];
	char h_ord_date[APL_DATE_LEN];
	int h_ord_qty;
	char h_limit_ind[OR_LIMIT_IND_LEN];
	char h_isgte_ind[OR_ISGTE_IND_LEN];
	char h_all_none_ind[OR_ALL_NONE_IND_LEN];
	char h_ex_arena[OR_EX_ARENA_LEN];
	char h_ord_stat[OR_ORD_STAT_LEN];
	char h_instr_code[OR_INSTR_CODE_LEN];
	char h_maker[OR_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[OR_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_exp_date[APL_DATE_LEN];
	double h_limit_pr;
	char h_dateof_cancel[APL_DATE_LEN];
	int h_exec_qty;
	char h_allow_dropdt[APL_DATE_LEN];
	char h_broker_cd[OR_BROKER_CD_LEN];
	char h_lcl_identno[OR_LCL_IDENTNO_LEN];
	char h_lr_dl_class[OR_LR_DL_CLASS_LEN];
	char h_lr_check_date[APL_DATE_LEN];
	char h_lr_unblk_date[APL_DATE_LEN];
	char h_unblk_date[APL_DATE_LEN];
	char h_last_exec_date[APL_DATE_LEN];
	char h_last_dl_date[OR_LAST_DL_DATE_LEN];
}OR_ORD_LR_VEW_STRUCT_H;
typedef struct{
	short i_client;
	short i_ord_refno;
	short i_buy_sell_ind;
	short i_ord_date;
	short i_ord_qty;
	short i_limit_ind;
	short i_isgte_ind;
	short i_all_none_ind;
	short i_ex_arena;
	short i_ord_stat;
	short i_instr_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_exp_date;
	short i_limit_pr;
	short i_dateof_cancel;
	short i_exec_qty;
	short i_allow_dropdt;
	short i_broker_cd;
	short i_lcl_identno;
	short i_lr_dl_class;
	short i_lr_check_date;
	short i_lr_unblk_date;
	short i_unblk_date;
	short i_last_exec_date;
	short i_last_dl_date;
}OR_ORD_LR_VEW_STRUCT_I;







#define PL_STATEMENT_ID_LEN 31

#define PL_REMARKS_LEN 81
#define PL_OPERATION_LEN 31
#define PL_OPTIONS_LEN 31
#define PL_OBJECT_NODE_LEN 129
#define PL_OBJECT_OWNER_LEN 31
#define PL_OBJECT_NAME_LEN 31

#define PL_OBJECT_TYPE_LEN 31
#define PL_OPTIMIZER_LEN 256







#define PL_OTHER_TAG_LEN 256
#define PL_PARTITION_START_LEN 256
#define PL_PARTITION_STOP_LEN 256


#define PL_DISTRIBUTION_LEN 31



typedef struct{
	char h_statement_id[PL_STATEMENT_ID_LEN];
	char h_timestamp[APL_DATE_LEN];
	char h_remarks[PL_REMARKS_LEN];
	char h_operation[PL_OPERATION_LEN];
	char h_options[PL_OPTIONS_LEN];
	char h_object_node[PL_OBJECT_NODE_LEN];
	char h_object_owner[PL_OBJECT_OWNER_LEN];
	char h_object_name[PL_OBJECT_NAME_LEN];
	int h_object_instance;
	char h_object_type[PL_OBJECT_TYPE_LEN];
	char h_optimizer[PL_OPTIMIZER_LEN];
	int h_search_columns;
	int h_id;
	int h_parent_id;
	int h_position;
	int h_cost;
	int h_cardinality;
	int h_bytes;
	char h_other_tag[PL_OTHER_TAG_LEN];
	char h_partition_start[PL_PARTITION_START_LEN];
	char h_partition_stop[PL_PARTITION_STOP_LEN];
	int h_partition_id;
	
	char h_distribution[PL_DISTRIBUTION_LEN];
	int h_cpu_cost;
	int h_io_cost;
	int h_temp_space;
}PLAN_TABLE_STRUCT_H;
typedef struct{
	short i_statement_id;
	short i_timestamp;
	short i_remarks;
	short i_operation;
	short i_options;
	short i_object_node;
	short i_object_owner;
	short i_object_name;
	short i_object_instance;
	short i_object_type;
	short i_optimizer;
	short i_search_columns;
	short i_id;
	short i_parent_id;
	short i_position;
	short i_cost;
	short i_cardinality;
	short i_bytes;
	short i_other_tag;
	short i_partition_start;
	short i_partition_stop;
	short i_partition_id;
	short i_other;
	short i_distribution;
	short i_cpu_cost;
	short i_io_cost;
	short i_temp_space;
}PLAN_TABLE_STRUCT_I;







#define PR_MODULE_IND_LEN 2
#define PR_BRNCH_CD_LEN 4
#define PR_INDEN_NUM_LEN 11 
#define PR_CLIENT_LEN 11
#define PR_CURR_CD_LEN 4



#define PR_VAL_DATE_LEN 9
#define PR_DEAL_CD_LEN 4
#define PR_SPL_CLT_CD_LEN 9
#define PR_DB_CR_IND_LEN 2
#define PR_NARRATIVE_LEN 101
#define PR_STATUS_IND_LEN 2
#define PR_PROC_NUM_LEN 10 





#define PR_REC_REFER_LEN 2

#define PR_DEAL_IDENT_LEN 51
typedef struct{
	char h_module_ind[PR_MODULE_IND_LEN];
	char h_brnch_cd[PR_BRNCH_CD_LEN];
	char h_inden_num[PR_INDEN_NUM_LEN];
	char h_client[PR_CLIENT_LEN];
	char h_curr_cd[PR_CURR_CD_LEN];
	double h_fccy_amt;
	double h_exchg_rt;
	double h_lcl_amount;
	char h_val_date[PR_VAL_DATE_LEN];
	char h_deal_cd[PR_DEAL_CD_LEN];
	char h_spl_clt_cd[PR_SPL_CLT_CD_LEN];
	char h_db_cr_ind[PR_DB_CR_IND_LEN];
	char h_narrative[PR_NARRATIVE_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_proc_num[PR_PROC_NUM_LEN];
	double h_report_amt;
	double h_report_clt;
	double h_report_tax;
	double h_report_ser;
	double h_rep_exg_rt;
	char h_rec_refer[PR_REC_REFER_LEN];
	char h_batch_date[APL_DATE_LEN];
	char h_deal_ident[PR_DEAL_IDENT_LEN];
	char leg_ind[11];
	char acc_type[2];
}PRO_ACCTENT_STRUCT_H;
typedef struct{
	short i_module_ind;
	short i_brnch_cd;
	short i_inden_num;
	short i_client;
	short i_curr_cd;
	short i_fccy_amt;
	short i_exchg_rt;
	short i_lcl_amount;
	short i_val_date;
	short i_deal_cd;
	short i_spl_clt_cd;
	short i_db_cr_ind;
	short i_narrative;
	short i_status_ind;
	short i_proc_num;
	short i_report_amt;
	short i_report_clt;
	short i_report_tax;
	short i_report_ser;
	short i_rep_exg_rt;
	short i_rec_refer;
	short i_batch_date;
	short i_deal_ident;
	short i_leg_ind;
	short i_acc_type;
}PRO_ACCTENT_STRUCT_I;







#define PR_MAIN_FUN_LEN 21
#define PR_COND_FUN_LEN 21
#define PR_NATION_LEN 3
typedef struct{
	char h_main_fun[PR_MAIN_FUN_LEN];
	char h_cond_fun[PR_COND_FUN_LEN];
	char h_nation[PR_NATION_LEN];
}PRO_CNTRY_SYS_PARAMS_STRUCT_H;
typedef struct{
	short i_main_fun;
	short i_cond_fun;
	short i_nation;
}PRO_CNTRY_SYS_PARAMS_STRUCT_I;







#define PR_REPORT_NAME_LEN 31
#define PR_REPORT_DESC_LEN 31


#define PR_TASK_DESC_LEN 61
#define PR_FE_BE_IND_LEN 2
#define PR_USR_LEN 15

typedef struct{
	char h_report_name[PR_REPORT_NAME_LEN];
	char h_report_desc[PR_REPORT_DESC_LEN];
	char h_report_date[APL_DATE_LEN];
	int h_report_width;
	char h_task_desc[PR_TASK_DESC_LEN];
	char h_fe_be_ind[PR_FE_BE_IND_LEN];
	char h_usr[PR_USR_LEN];
	
}PRO_COMMON_REPORT_STRUCT_H;
typedef struct{
	short i_report_name;
	short i_report_desc;
	short i_report_date;
	short i_report_width;
	short i_task_desc;
	short i_fe_be_ind;
	short i_usr;
	short i_linkto_file;
}PRO_COMMON_REPORT_STRUCT_I;







#define PR_PROC_NAME_LEN 41

typedef struct{
	char h_proc_name[PR_PROC_NAME_LEN];
	int h_status_ind;
}PRO_DAEMON_STATUS_STRUCT_H;
typedef struct{
	short i_proc_name;
	short i_status_ind;
}PRO_DAEMON_STATUS_STRUCT_I;







#define PR_INSTR_CODE_LEN 9
#define PR_CLIENT_LEN 11
#define PR_LOCATION_CD_LEN 5



#define PR_DF_IDENTNO_LEN 17
#define PR_RF_IDENT_NO_LEN 17
#define PR_PROC_AREA_LEN 6


#define PR_INFO_LEN 51
typedef struct{
	char h_instr_code[PR_INSTR_CODE_LEN];
	char h_client[PR_CLIENT_LEN];
	char h_location_cd[PR_LOCATION_CD_LEN];
	double h_grd_pos;
	double h_urounded_eur;
	double h_eur_after_rnd;
	char h_df_identno[PR_DF_IDENTNO_LEN];
	char h_rf_ident_no[PR_RF_IDENT_NO_LEN];
	char h_proc_area[PR_PROC_AREA_LEN];
	double h_orig_amt;
	double h_new_amount;
	char h_info[PR_INFO_LEN];
}PRO_EURO_TEMP_STRUCT_H;
typedef struct{
	short i_instr_code;
	short i_client;
	short i_location_cd;
	short i_grd_pos;
	short i_urounded_eur;
	short i_eur_after_rnd;
	short i_df_identno;
	short i_rf_ident_no;
	short i_proc_area;
	short i_orig_amt;
	short i_new_amount;
	short i_info;
}PRO_EURO_TEMP_STRUCT_I;







#define PR_FAILREASON_CD_LEN 3
#define PR_FAILREASON_DET_LEN 33
#define PR_FAIL_DESC_LEN 51
#define PR_MAPWORD_LEN 21

#define PR_STATUS_QUAL_IND_LEN 5
#define PR_STATUS_CD_LEN 7
#define PR_REASON_QL_LEN 7
#define PR_REASON_CD_LEN 5
#define PR_SUPPORT_IND_LEN 2
typedef struct{
	char h_failreason_cd[PR_FAILREASON_CD_LEN];
	char h_failreason_det[PR_FAILREASON_DET_LEN];
	char h_fail_desc[PR_FAIL_DESC_LEN];
	char h_mapword[PR_MAPWORD_LEN];
	int h_sub_fail_cd;
	char h_status_qual_ind[PR_STATUS_QUAL_IND_LEN];
	char h_status_cd[PR_STATUS_CD_LEN];
	char h_reason_ql[PR_REASON_QL_LEN];
	char h_reason_cd[PR_REASON_CD_LEN];
	char h_support_ind[PR_SUPPORT_IND_LEN];
}PRO_FAILCODES_STRUCT_H;
typedef struct{
	short i_failreason_cd;
	short i_failreason_det;
	short i_fail_desc;
	short i_mapword;
	short i_sub_fail_cd;
	short i_status_qual_ind;
	short i_status_cd;
	short i_reason_ql;
	short i_reason_cd;
	short i_support_ind;
}PRO_FAILCODES_STRUCT_I;







#define PR_MAPTYPE_LEN 21
#define PR_MAPVALUE_LEN 11
#define PR_MAP_VAL_LEN 5
typedef struct{
	char h_maptype[PR_MAPTYPE_LEN];
	char h_mapvalue[PR_MAPVALUE_LEN];
	char h_map_val[PR_MAP_VAL_LEN];
}PRO_GMATCHVALUE_STRUCT_H;
typedef struct{
	short i_maptype;
	short i_mapvalue;
	short i_map_val;
}PRO_GMATCHVALUE_STRUCT_I;







#define PR_MODULE_IND_LEN 2
#define PR_PROC_NUM_LEN 10 

#define PR_TYPEOFINSTR_LEN 2
#define PR_REC_CLASS_LEN 4
#define PR_STATUS_IND_LEN 2
#define PR_ENTRY_LEN 4
#define PR_CLIENT_LEN 11
#define PR_CURRENCY_CD_LEN 4


#define PR_DEAL_CD_LEN 4
#define PR_DB_CR_IND_LEN 2
#define PR_SPLGR_CLT_CD_LEN 11
#define PR_STATISTIC_LEN 5
#define PR_TRANS_BOG_LEN 6

#define PR_OFFSET_CLIENT_LEN 11
#define PR_BROKER_CD_LEN 6
#define PR_NATIONALITY_LEN 4
#define PR_INSTR_ISIN_LEN 13
#define PR_SPECIAL_TAX_LEN 21
#define PR_IDENTIY_NO_LEN 11
#define PR_AUTO_REC_IND_LEN 11
#define PR_NOTE_A_LEN 33
#define PR_NOTE_B_LEN 33



#define PR_POSITION_LEN 2
#define PR_SEQUENCE_LEN 6
#define PR_REAS_CD_LEN 5
#define PR_DEAL_IDENT_LEN 31


typedef struct{
	char h_module_ind[PR_MODULE_IND_LEN];
	char h_proc_num[PR_PROC_NUM_LEN];
	char h_batch_date[APL_DATE_LEN];
	char h_typeofinstr[PR_TYPEOFINSTR_LEN];
	char h_rec_class[PR_REC_CLASS_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_entry[PR_ENTRY_LEN];
	char h_client[PR_CLIENT_LEN];
	char h_currency_cd[PR_CURRENCY_CD_LEN];
	int h_deal_amount;
	char h_val_dt[APL_DATE_LEN];
	char h_deal_cd[PR_DEAL_CD_LEN];
	char h_db_cr_ind[PR_DB_CR_IND_LEN];
	char h_splgr_clt_cd[PR_SPLGR_CLT_CD_LEN];
	char h_statistic[PR_STATISTIC_LEN];
	char h_trans_bog[PR_TRANS_BOG_LEN];
	int h_quantity_items;
	char h_offset_client[PR_OFFSET_CLIENT_LEN];
	char h_broker_cd[PR_BROKER_CD_LEN];
	char h_nationality[PR_NATIONALITY_LEN];
	char h_instr_isin[PR_INSTR_ISIN_LEN];
	char h_special_tax[PR_SPECIAL_TAX_LEN];
	char h_identiy_no[PR_IDENTIY_NO_LEN];
	char h_auto_rec_ind[PR_AUTO_REC_IND_LEN];
	char h_note_a[PR_NOTE_A_LEN];
	char h_note_b[PR_NOTE_B_LEN];
	int h_fccy_amt;
	int h_mis_sprd;
	int h_ae_rate;
	char h_position[PR_POSITION_LEN];
	char h_sequence[PR_SEQUENCE_LEN];
	char h_reas_cd[PR_REAS_CD_LEN];
	char h_deal_ident[PR_DEAL_IDENT_LEN];
	int h_report_amt;
	int h_lcl_amt;
}PRO_GRACCTENT_STRUCT_H;
typedef struct{
	short i_module_ind;
	short i_proc_num;
	short i_batch_date;
	short i_typeofinstr;
	short i_rec_class;
	short i_status_ind;
	short i_entry;
	short i_client;
	short i_currency_cd;
	short i_deal_amount;
	short i_val_dt;
	short i_deal_cd;
	short i_db_cr_ind;
	short i_splgr_clt_cd;
	short i_statistic;
	short i_trans_bog;
	short i_quantity_items;
	short i_offset_client;
	short i_broker_cd;
	short i_nationality;
	short i_instr_isin;
	short i_special_tax;
	short i_identiy_no;
	short i_auto_rec_ind;
	short i_note_a;
	short i_note_b;
	short i_fccy_amt;
	short i_mis_sprd;
	short i_ae_rate;
	short i_position;
	short i_sequence;
	short i_reas_cd;
	short i_deal_ident;
	short i_report_amt;
	short i_lcl_amt;
}PRO_GRACCTENT_STRUCT_I;







#define PR_SEQUENCE_NAME_LEN 21

#define PR_RECYCLE_IND_LEN 2



#define PR_SEQ_ATTRB_A_LEN 21
#define PR_SEQ_ATTRB_B_LEN 21
#define PR_SEQ_ATTRB_C_LEN 21
typedef struct{
	char h_sequence_name[PR_SEQUENCE_NAME_LEN];
	int h_last_usednum;
	char h_recycle_ind[PR_RECYCLE_IND_LEN];
	int h_seq_stepby;
	int h_seq_start;
	int h_last_seqnum;
	char h_seq_attrb_a[PR_SEQ_ATTRB_A_LEN];
	char h_seq_attrb_b[PR_SEQ_ATTRB_B_LEN];
	char h_seq_attrb_c[PR_SEQ_ATTRB_C_LEN];
}PRO_GSEQNUM_STRUCT_H;
typedef struct{
	short i_sequence_name;
	short i_last_usednum;
	short i_recycle_ind;
	short i_seq_stepby;
	short i_seq_start;
	short i_last_seqnum;
	short i_seq_attrb_a;
	short i_seq_attrb_b;
	short i_seq_attrb_c;
}PRO_GSEQNUM_STRUCT_I;







#define PR_NATION_CODE_LEN 3
#define PR_NAMEOF_FORM_LEN 51

typedef struct{
	char h_nation_code[PR_NATION_CODE_LEN];
	char h_nameof_form[PR_NAMEOF_FORM_LEN];
	int h_help_ind;
}PRO_GSHELPID_STRUCT_H;
typedef struct{
	short i_nation_code;
	short i_nameof_form;
	short i_help_ind;
}PRO_GSHELPID_STRUCT_I;







#define PR_MAIN_FUN_LEN 21
#define PR_SUB_PROCESS_LEN 21
#define PR_FIELD_VAL_LEN 21
#define PR_NATION_LEN 3
typedef struct{
	char h_main_fun[PR_MAIN_FUN_LEN];
	char h_sub_process[PR_SUB_PROCESS_LEN];
	char h_field_val[PR_FIELD_VAL_LEN];
	char h_nation[PR_NATION_LEN];
}PRO_GSSPLVAL_STRUCT_H;
typedef struct{
	short i_main_fun;
	short i_sub_process;
	short i_field_val;
	short i_nation;
}PRO_GSSPLVAL_STRUCT_I;







#define PR_MEM_IDENT_LEN 13
#define PR_INSTRUCT_CLT_LEN 15
#define PR_BRKCD_LEN 13
#define PR_ALTERNATE_BIDCD_LEN 13
#define PR_DETAIL_LEN 66
#define PR_MTCH_INFO_LEN 66
#define PR_STATUS_IND_LEN 3
#define PR_MAKER_LEN 15

#define PR_CHECKER_LEN 15


typedef struct{
	char h_mem_ident[PR_MEM_IDENT_LEN];
	char h_instruct_clt[PR_INSTRUCT_CLT_LEN];
	char h_brkcd[PR_BRKCD_LEN];
	char h_alternate_bidcd[PR_ALTERNATE_BIDCD_LEN];
	char h_detail[PR_DETAIL_LEN];
	char h_mtch_info[PR_MTCH_INFO_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_maker[PR_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[PR_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
}PRO_HDAT_STATIC_STRUCT_H;
typedef struct{
	short i_mem_ident;
	short i_instruct_clt;
	short i_brkcd;
	short i_alternate_bidcd;
	short i_detail;
	short i_mtch_info;
	short i_status_ind;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
}PRO_HDAT_STATIC_STRUCT_I;







#define PR_QUEUE_NAME_LEN 49
#define PR_RPLY_QUEUE_NAME_LEN 49
#define PR_EVENT_CLASS_LEN 3
#define PR_NATION_CODE_LEN 3
typedef struct{
	char h_queue_name[PR_QUEUE_NAME_LEN];
	char h_rply_queue_name[PR_RPLY_QUEUE_NAME_LEN];
	char h_event_class[PR_EVENT_CLASS_LEN];
	char h_nation_code[PR_NATION_CODE_LEN];
}PRO_MQNAMES_STRUCT_H;
typedef struct{
	short i_queue_name;
	short i_rply_queue_name;
	short i_event_class;
	short i_nation_code;
}PRO_MQNAMES_STRUCT_I;







#define PR_EVENT_CLASS_LEN 3


#define PR_STATUS_IND_LEN 2

typedef struct{
	char h_event_class[PR_EVENT_CLASS_LEN];
	char h_buss_date[APL_DATE_LEN];
	int h_identity_no;
	char h_status_ind[PR_STATUS_IND_LEN];
	
}PRO_MQ_DATA_STRUCT_H;
typedef struct{
	short i_event_class;
	short i_buss_date;
	short i_identity_no;
	short i_status_ind;
	short i_info;
}PRO_MQ_DATA_STRUCT_I;







#define PR_CLIENT_LEN 11





typedef struct{
	char h_client[PR_CLIENT_LEN];
	char h_setl_effective_date[APL_DATE_LEN];
	char h_stat_eff_date[APL_DATE_LEN];
	char h_ca_effective_dt[APL_DATE_LEN];
	char h_stmsg_effect_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
}PRO_MSGCONV_STRUCT_H;
typedef struct{
	short i_client;
	short i_setl_effective_date;
	short i_stat_eff_date;
	short i_ca_effective_dt;
	short i_stmsg_effect_date;
	short i_access_stamp;
}PRO_MSGCONV_STRUCT_I;








#define PR_PROC_NAME_LEN 101
#define PR_PROC_AREA_LEN 101
#define PR_ENVIRON_DATA_LEN 2001
#define PR_PROC_DATA_LEN 4001
#define PR_STATUS_IND_LEN 3
#define PR_USR_LEN 15
#define PR_ERROR_DET_LEN 4001
typedef struct{
	int h_request_seq;
	char h_proc_name[PR_PROC_NAME_LEN];
	char h_proc_area[PR_PROC_AREA_LEN];
	char h_environ_data[PR_ENVIRON_DATA_LEN];
	char h_proc_data[PR_PROC_DATA_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_usr[PR_USR_LEN];
	char h_error_det[PR_ERROR_DET_LEN];
}PRO_REQUEST_BATCH_STRUCT_H;
typedef struct{
	short i_request_seq;
	short i_proc_name;
	short i_proc_area;
	short i_environ_data;
	short i_proc_data;
	short i_status_ind;
	short i_usr;
	short i_error_det;
}PRO_REQUEST_BATCH_STRUCT_I;








#define PR_PROC_NAME_LEN 101
#define PR_ENVIRON_DATA_LEN 2001
#define PR_PROC_DATA_LEN 4001
#define PR_STATUS_IND_LEN 3
#define PR_USR_LEN 15
#define PR_ERROR_DET_LEN 4001
typedef struct{
	int h_request_seq;
	char h_proc_name[PR_PROC_NAME_LEN];
	char h_environ_data[PR_ENVIRON_DATA_LEN];
	char h_proc_data[PR_PROC_DATA_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_usr[PR_USR_LEN];
	char h_error_det[PR_ERROR_DET_LEN];
}PRO_REQUEST_CA_STRUCT_H;
typedef struct{
	short i_request_seq;
	short i_proc_name;
	short i_environ_data;
	short i_proc_data;
	short i_status_ind;
	short i_usr;
	short i_error_det;
}PRO_REQUEST_CA_STRUCT_I;








#define PR_PROC_NAME_LEN 101
#define PR_ENVIRON_DATA_LEN 2001
#define PR_PROC_DATA_LEN 4001
#define PR_STATUS_IND_LEN 3
#define PR_USR_LEN 15
#define PR_ERROR_DET_LEN 4001

#define PR_SMP_IND_LEN 16

typedef struct{
	int h_request_seq;
	char h_proc_name[PR_PROC_NAME_LEN];
	char h_environ_data[PR_ENVIRON_DATA_LEN];
	char h_proc_data[PR_PROC_DATA_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_usr[PR_USR_LEN];
	char h_error_det[PR_ERROR_DET_LEN];
	int h_smp_id;
	char h_smp_ind[PR_SMP_IND_LEN];
	char h_access_stamp[APL_DATE_LEN];
}PRO_REQUEST_DEAL_STRUCT_H;
typedef struct{
	short i_request_seq;
	short i_proc_name;
	short i_environ_data;
	short i_proc_data;
	short i_status_ind;
	short i_usr;
	short i_error_det;
	short i_smp_id;
	short i_smp_ind;
	short i_access_stamp;
}PRO_REQUEST_DEAL_STRUCT_I;








#define PR_PROC_NAME_LEN 101
#define PR_ENVIRON_DATA_LEN 2001
#define PR_PROC_DATA_LEN 4001
#define PR_PROC_DATA_A_LEN 4001
#define PR_PROC_DATA_B_LEN 4001
#define PR_STATUS_IND_LEN 3
#define PR_USR_LEN 15
#define PR_ERROR_DET_LEN 4001
typedef struct{
	int h_request_seq;
	char h_proc_name[PR_PROC_NAME_LEN];
	char h_environ_data[PR_ENVIRON_DATA_LEN];
	char h_proc_data[PR_PROC_DATA_LEN];
	char h_proc_data_a[PR_PROC_DATA_A_LEN];
	char h_proc_data_b[PR_PROC_DATA_B_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_usr[PR_USR_LEN];
	char h_error_det[PR_ERROR_DET_LEN];
}PRO_REQUEST_IV_STRUCT_H;
typedef struct{
	short i_request_seq;
	short i_proc_name;
	short i_environ_data;
	short i_proc_data;
	short i_proc_data_a;
	short i_proc_data_b;
	short i_status_ind;
	short i_usr;
	short i_error_det;
}PRO_REQUEST_IV_STRUCT_I;








#define PR_PROC_NAME_LEN 101
#define PR_ENVIRON_DATA_LEN 2001
#define PR_PROC_DATA_LEN 4001
#define PR_STATUS_IND_LEN 3
#define PR_USR_LEN 15
#define PR_ERROR_DET_LEN 4001
typedef struct{
	int h_request_seq;
	char h_proc_name[PR_PROC_NAME_LEN];
	char h_environ_data[PR_ENVIRON_DATA_LEN];
	char h_proc_data[PR_PROC_DATA_LEN];
	char h_status_ind[PR_STATUS_IND_LEN];
	char h_usr[PR_USR_LEN];
	char h_error_det[PR_ERROR_DET_LEN];
}PRO_REQUEST_MT_STRUCT_H;
typedef struct{
	short i_request_seq;
	short i_proc_name;
	short i_environ_data;
	short i_proc_data;
	short i_status_ind;
	short i_usr;
	short i_error_det;
}PRO_REQUEST_MT_STRUCT_I;









typedef struct{
	int h_upld_id;
	
}PRO_REQUEST_UPLOAD_STRUCT_H;
typedef struct{
	short i_upld_id;
	short i_upld_data;
}PRO_REQUEST_UPLOAD_STRUCT_I;







#define PR_MAP_TYPE_LEN 21
#define PR_MAP_VAL_LEN 21
#define PR_MAP_DESC_LEN 41
#define PR_NATION_CODE_LEN 3
typedef struct{
	char h_map_type[PR_MAP_TYPE_LEN];
	char h_map_val[PR_MAP_VAL_LEN];
	char h_map_desc[PR_MAP_DESC_LEN];
	char h_nation_code[PR_NATION_CODE_LEN];
}PRO_SGENSTAT_STRUCT_H;
typedef struct{
	short i_map_type;
	short i_map_val;
	short i_map_desc;
	short i_nation_code;
}PRO_SGENSTAT_STRUCT_I;







#define PR_MAP_TYPE_LEN 21
#define PR_MAP_VAL_LEN 21
#define PR_MAP_DESC_LEN 41
#define PR_NATION_CODE_LEN 3
typedef struct{
	char h_map_type[PR_MAP_TYPE_LEN];
	char h_map_val[PR_MAP_VAL_LEN];
	char h_map_desc[PR_MAP_DESC_LEN];
	char h_nation_code[PR_NATION_CODE_LEN];
}PRO_SGENSTAT_BAK_STRUCT_H;
typedef struct{
	short i_map_type;
	short i_map_val;
	short i_map_desc;
	short i_nation_code;
}PRO_SGENSTAT_BAK_STRUCT_I;








#define PR_EOD_IND_LEN 2
typedef struct{
	char h_sys_date[APL_DATE_LEN];
	char h_eod_ind[PR_EOD_IND_LEN];
}PRO_SYS_DATE_STRUCT_H;
typedef struct{
	short i_sys_date;
	short i_eod_ind;
}PRO_SYS_DATE_STRUCT_I;







#define PR_EVENT_CLASS_LEN 3


typedef struct{
	char h_event_class[PR_EVENT_CLASS_LEN];
	int h_identity_no;
	
}PRO_TEMP_MQDATA_STRUCT_H;
typedef struct{
	short i_event_class;
	short i_identity_no;
	short i_info;
}PRO_TEMP_MQDATA_STRUCT_I;







#define SY_PROCESS_NAME_LEN 41

#define SY_STATUS_IND_LEN 16
#define SY_PROC_INIT_LEN 41
#define SY_PROCESSING_STATUS_LEN 51
#define SY_USR_LEN 15
#define SY_EOD_BOD_IND_LEN 2
#define SY_STAT_DET_LEN 71
#define SY_PROCESS_DESC_LEN 61

#define SY_PROC_ENDFLG_LEN 2
typedef struct{
	char h_process_name[SY_PROCESS_NAME_LEN];
	char h_startdate[APL_DATE_LEN];
	char h_status_ind[SY_STATUS_IND_LEN];
	char h_proc_init[SY_PROC_INIT_LEN];
	char h_processing_status[SY_PROCESSING_STATUS_LEN];
	char h_usr[SY_USR_LEN];
	char h_eod_bod_ind[SY_EOD_BOD_IND_LEN];
	char h_stat_det[SY_STAT_DET_LEN];
	char h_process_desc[SY_PROCESS_DESC_LEN];
	int h_proc_id;
	char h_proc_endflg[SY_PROC_ENDFLG_LEN];
}SYS_BATCHPROC_STRUCT_H;
typedef struct{
	short i_process_name;
	short i_startdate;
	short i_status_ind;
	short i_proc_init;
	short i_processing_status;
	short i_usr;
	short i_eod_bod_ind;
	short i_stat_det;
	short i_process_desc;
	short i_proc_id;
	short i_proc_endflg;
}SYS_BATCHPROC_STRUCT_I;








#define SY_PROCESS_NAME_LEN 41
#define SY_PROC_IND_LEN 2
#define SY_TASK_CD_LEN 61
typedef struct{
	int h_process_no;
	char h_process_name[SY_PROCESS_NAME_LEN];
	char h_proc_ind[SY_PROC_IND_LEN];
	char h_task_cd[SY_TASK_CD_LEN];
}SYS_BATCHSTREAM_STRUCT_H;
typedef struct{
	short i_process_no;
	short i_process_name;
	short i_proc_ind;
	short i_task_cd;
}SYS_BATCHSTREAM_STRUCT_I;







#define SY_PROCESS_NAME_LEN 41
#define SY_PRE_PROCESS_LEN 41
#define SY_MISMATCH_LEN 41
typedef struct{
	char h_process_name[SY_PROCESS_NAME_LEN];
	char h_pre_process[SY_PRE_PROCESS_LEN];
	char h_mismatch[SY_MISMATCH_LEN];
}SYS_BATCH_CNTRL_STRUCT_H;
typedef struct{
	short i_process_name;
	short i_pre_process;
	short i_mismatch;
}SYS_BATCH_CNTRL_STRUCT_I;











#define SY_GENERATE_IND_LEN 2
#define SY_AE_IND_LEN 2



#define SY_B_GEN_IND_LEN 2
typedef struct{
	char h_b_prev_date[APL_DATE_LEN];
	char h_b_upto_date[APL_DATE_LEN];
	char h_b_processdt[APL_DATE_LEN];
	char h_b_dlv_date[APL_DATE_LEN];
	char h_generate_ind[SY_GENERATE_IND_LEN];
	char h_ae_ind[SY_AE_IND_LEN];
	char h_last_dlv_date[APL_DATE_LEN];
	char h_archival_dt[APL_DATE_LEN];
	char h_last_rpt_date[APL_DATE_LEN];
	char h_b_gen_ind[SY_B_GEN_IND_LEN];
}SYS_IVCONTROLPARAM_STRUCT_H;
typedef struct{
	short i_b_prev_date;
	short i_b_upto_date;
	short i_b_processdt;
	short i_b_dlv_date;
	short i_generate_ind;
	short i_ae_ind;
	short i_last_dlv_date;
	short i_archival_dt;
	short i_last_rpt_date;
	short i_b_gen_ind;
}SYS_IVCONTROLPARAM_STRUCT_I;







#define TE_FLD1_LEN 21
#define TE_FLD2_LEN 31
#define TE_FLD3_LEN 41
typedef struct{
	char h_fld1[TE_FLD1_LEN];
	char h_fld2[TE_FLD2_LEN];
	char h_fld3[TE_FLD3_LEN];
}TEMP12_STRUCT_H;
typedef struct{
	short i_fld1;
	short i_fld2;
	short i_fld3;
}TEMP12_STRUCT_I;








typedef struct{
	double h_fld1;
}TT_STRUCT_H;
typedef struct{
	short i_fld1;
}TT_STRUCT_I;











typedef struct{
	int h_yr;
	int h_month;
	double h_invoice;
	double h_payments;
}YEARLY_AE_STRUCT_H;
typedef struct{
	short i_yr;
	short i_month;
	short i_invoice;
	short i_payments;
}YEARLY_AE_STRUCT_I;





/*ASSETHOLDING_VW_STRUCT_H *l_assetholding_vw_struct_h;*/
AUDIT_LOG_STRUCT_H *l_audit_log_struct_h;
BACK_GN_ENTITY_PICKLIST_STRUCT_H *l_back_gn_entity_picklist_struct_h;
BACK_MT_CLIENT_STRUCT_H *l_back_mt_client_struct_h;
CAARCHCHEQUE_STRUCT_H *l_caarchcheque_struct_h;
CAARCHCLAIM_STRUCT_H *l_caarchclaim_struct_h;
CAARCHMESGLNK_STRUCT_H *l_caarchmesglnk_struct_h;
CAARCHNOTE_STRUCT_H *l_caarchnote_struct_h;
CAARCHRTSPROC_STRUCT_H *l_caarchrtsproc_struct_h;
CAAUTOEVENT_STRUCT_H *l_caautoevent_struct_h;
CABACKSETTLE_STRUCT_H *l_cabacksettle_struct_h;
CACHEQUEMG_STRUCT_H *l_cachequemg_struct_h;
CACHEQUE_STRUCT_H *l_cacheque_struct_h;
CACHGEVENT_STRUCT_H *l_cachgevent_struct_h;
CAENTITLEMENTMG_STRUCT_H *l_caentitlementmg_struct_h;
CAENTITLEMENT_STRUCT_H *l_caentitlement_struct_h;
CAENTITLMENT_VER_STRUCT_H *l_caentitlment_ver_struct_h;
CAEVENTMG_STRUCT_H *l_caeventmg_struct_h;
CAEVENT_STRUCT_H *l_caevent_struct_h;
CAGLPYMT_STRUCT_H *l_caglpymt_struct_h;
CALOGAUTOEVENT_STRUCT_H *l_calogautoevent_struct_h;
CAMESGLINK_STRUCT_H *l_camesglink_struct_h;
CANOTE_STRUCT_H *l_canote_struct_h;
CANOTIFY_STRUCT_H *l_canotify_struct_h;
CAREPLYSPLIT_STRUCT_H *l_careplysplit_struct_h;
CAREPLY_STRUCT_H *l_careply_struct_h;
CARTSPROC_STRUCT_H *l_cartsproc_struct_h;
CASECEVENT_STRUCT_H *l_casecevent_struct_h;
CASTATUS_STRUCT_H *l_castatus_struct_h;
CASYSTEMPARAMS_STRUCT_H *l_casystemparams_struct_h;
/*CA_ENTITLEMENTREP_STRUCT_H *l_ca_entitlementrep_struct_h;*/
CA_EVENTMESGSEND_STRUCT_H *l_ca_eventmesgsend_struct_h;
/*CA_EXDTHLD1_VEW_STRUCT_H *l_ca_exdthld1_vew_struct_h;*/
/*CA_EXDTHLD2_VEW_STRUCT_H *l_ca_exdthld2_vew_struct_h;*/
/*CIMS_ACC_VEW_STRUCT_H *l_cims_acc_vew_struct_h;*/
COMMON_BASE_QUERY_MAPPING_BACK_STRUCT_H *l_common_base_query_mapping_back_struct_h;
COMMON_BASE_QUERY_MAPPING_BAK_STRUCT_H *l_common_base_query_mapping_bak_struct_h;
COMMON_BASE_QUERY_MAPPING_STRUCT_H *l_common_base_query_mapping_struct_h;
COMMON_ENTITY_PROC_230106_STRUCT_H *l_common_entity_proc_230106_struct_h;
COMMON_ENTITY_PROC_BAK_STRUCT_H *l_common_entity_proc_bak_struct_h;
COMMON_ENTITY_PROC_STRUCT_H *l_common_entity_proc_struct_h;
COMMON_GRID_MAPPING_230106_STRUCT_H *l_common_grid_mapping_230106_struct_h;
COMMON_GRID_MAPPING_BAK_STRUCT_H *l_common_grid_mapping_bak_struct_h;
COMMON_GRID_MAPPING_STRUCT_H *l_common_grid_mapping_struct_h;
COMMON_SEARCH_FORM_MAP_230106_STRUCT_H *l_common_search_form_map_230106_struct_h;
COMMON_SEARCH_FORM_MAP_BAK_STRUCT_H *l_common_search_form_map_bak_struct_h;
COMMON_SEARCH_FORM_MAP_STRUCT_H *l_common_search_form_map_struct_h;
COMMON_VIEW_FORM_MAP_230106_STRUCT_H *l_common_view_form_map_230106_struct_h;
COMMON_VIEW_FORM_MAP_BAK_STRUCT_H *l_common_view_form_map_bak_struct_h;
COMMON_VIEW_FORM_MAP_STRUCT_H *l_common_view_form_map_struct_h;
CO_STATIC_DATA_BAK_STRUCT_H *l_co_static_data_bak_struct_h;
CO_STATIC_DATA_STRUCT_H *l_co_static_data_struct_h;
CSCAENT_STRUCT_H *l_cscaent_struct_h;
CSCODE_STRUCT_H *l_cscode_struct_h;
CURRENCY_CONV_REPORT_STRUCT_H *l_currency_conv_report_struct_h;
DEAL_COUNT_STRUCT_H *l_deal_count_struct_h;
DEAL_EVNTIDLINK_STRUCT_H *l_deal_evntidlink_struct_h;
DEAL_LOCALREP_VEW_STRUCT_H *l_deal_localrep_vew_struct_h;
DL_ARCHDEAL_STRUCT_H *l_dl_archdeal_struct_h;
DL_ARCHDLAUDIT_STRUCT_H *l_dl_archdlaudit_struct_h;
DL_ARCHMSGLINKDET_STRUCT_H *l_dl_archmsglinkdet_struct_h;
DL_ARCHMSGLINK_STRUCT_H *l_dl_archmsglink_struct_h;
DL_ARCHREGDET_STRUCT_H *l_dl_archregdet_struct_h;
DL_ARCHREGPAR_STRUCT_H *l_dl_archregpar_struct_h;
DL_ARCHRUHISDEAL_STRUCT_H *l_dl_archruhisdeal_struct_h;
DL_ARCHSAFEK_STRUCT_H *l_dl_archsafek_struct_h;
DL_AUTOSETTHUFMT_STRUCT_H *l_dl_autosetthufmt_struct_h;
DL_AUTOSETTHUWRK_STRUCT_H *l_dl_autosetthuwrk_struct_h;
DL_CASHBAL_STRUCT_H *l_dl_cashbal_struct_h;
DL_CASHCLT_STRUCT_H *l_dl_cashclt_struct_h;
DL_CCSFAILMSG_STRUCT_H *l_dl_ccsfailmsg_struct_h;
DL_CCSPENDTXN_STRUCT_H *l_dl_ccspendtxn_struct_h;
DL_CLHTR_STRUCT_H *l_dl_clhtr_struct_h;
DL_COPYHISTORY_STRUCT_H *l_dl_copyhistory_struct_h;
DL_CURRENCY_STRUCT_H *l_dl_currency_struct_h;
DL_CURRENCY_VEW_STRUCT_H *l_dl_currency_vew_struct_h;
DL_DEALAUDIT_STRUCT_H *l_dl_dealaudit_struct_h;
DL_DEALCLIENTIMG_STRUCT_H *l_dl_dealclientimg_struct_h;
DL_DEALDET_STRUCT_H *l_dl_dealdet_struct_h;
DL_DEALREPAIR_STRUCT_H *l_dl_dealrepair_struct_h;
DL_DEALRST_STRUCT_H *l_dl_dealrst_struct_h;
DL_DEAL_STRUCT_H *l_dl_deal_struct_h;
DL_DEPOPROCESSING_STRUCT_H *l_dl_depoprocessing_struct_h;
DL_EOMDEAL_STRUCT_H *l_dl_eomdeal_struct_h;
DL_EOMSAFEK_STRUCT_H *l_dl_eomsafek_struct_h;
DL_EOMSTM_ADJ_VEW_STRUCT_H *l_dl_eomstm_adj_vew_struct_h;
DL_EOMSTM_CURR_VEW_STRUCT_H *l_dl_eomstm_curr_vew_struct_h;
DL_EOMSTM_FAIL_VEW_STRUCT_H *l_dl_eomstm_fail_vew_struct_h;
DL_EOMSTM_PEND_VEW_STRUCT_H *l_dl_eomstm_pend_vew_struct_h;
DL_FUTURE_VDP_VEW_STRUCT_H *l_dl_future_vdp_vew_struct_h;
DL_HISDEALSAUDIT_STRUCT_H *l_dl_hisdealsaudit_struct_h;
DL_HISDEAL_STRUCT_H *l_dl_hisdeal_struct_h;
DL_HISDEAL_VEW_STRUCT_H *l_dl_hisdeal_vew_struct_h;
DL_HISMSGLINKDET_STRUCT_H *l_dl_hismsglinkdet_struct_h;
DL_HISMSGLINK_STRUCT_H *l_dl_hismsglink_struct_h;
DL_HISMULT_REAS_CODES_STRUCT_H *l_dl_hismult_reas_codes_struct_h;
DL_HISREGDET_STRUCT_H *l_dl_hisregdet_struct_h;
DL_HISREGPAR_STRUCT_H *l_dl_hisregpar_struct_h;
/*DL_HISREPIRE_VEW_STRUCT_H *l_dl_hisrepire_vew_struct_h;*/
DL_HISSAFEK_STRUCT_H *l_dl_hissafek_struct_h;
DL_INSTRUMENTCHG_STRUCT_H *l_dl_instrumentchg_struct_h;
DL_INSTRUMENTCONV_REP_TEMP_STRUCT_H *l_dl_instrumentconv_rep_temp_struct_h;
DL_INSTRUMENTCONV_STRUCT_H *l_dl_instrumentconv_struct_h;
DL_INSTRUMENTCONV_TEMP_STRUCT_H *l_dl_instrumentconv_temp_struct_h;
DL_IPOAUDIT_STRUCT_H *l_dl_ipoaudit_struct_h;
DL_LOCALREPCLIENTMA_STRUCT_H *l_dl_localrepclientma_struct_h;
DL_LOCALREPCLIENT_STRUCT_H *l_dl_localrepclient_struct_h;
DL_LOCALREPDATES_STRUCT_H *l_dl_localrepdates_struct_h;
DL_LOCALREPDEALTYPE_STRUCT_H *l_dl_localrepdealtype_struct_h;
DL_LOCALREPPROC2_STRUCT_H *l_dl_localrepproc2_struct_h;
DL_LOCALREPPROC3_STRUCT_H *l_dl_localrepproc3_struct_h;
DL_LOCALREPPROC_STRUCT_H *l_dl_localrepproc_struct_h;
DL_LOCALREPROCMA_STRUCT_H *l_dl_localreprocma_struct_h;
DL_LOCALREPSAFEKMA_STRUCT_H *l_dl_localrepsafekma_struct_h;
DL_LOCALREPSAFEK_STRUCT_H *l_dl_localrepsafek_struct_h;
DL_LOCALREPSPECMA_STRUCT_H *l_dl_localrepspecma_struct_h;
DL_LOCALREPSPEC_STRUCT_H *l_dl_localrepspec_struct_h;
DL_LOCNCHG_STRUCT_H *l_dl_locnchg_struct_h;
DL_MAROCLEAR_STRUCT_H *l_dl_maroclear_struct_h;
DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h;
DL_MSGLINKDET_STRUCT_H *l_dl_msglinkdet_struct_h;
DL_MSGLINK_INC536_VEW_STRUCT_H *l_dl_msglink_inc536_vew_struct_h;
DL_MSGLINK_STRUCT_H *l_dl_msglink_struct_h;
DL_MULT_REAS_CODES_STRUCT_H *l_dl_mult_reas_codes_struct_h;
DL_NOTES_VEW_STRUCT_H *l_dl_notes_vew_struct_h;
DL_PAST_VDP_VEW_STRUCT_H *l_dl_past_vdp_vew_struct_h;
/*DL_PER_PORTFOLIO_VEW_STRUCT_H *l_dl_per_portfolio_vew_struct_h;*/
DL_PREV_EOM_SAFEK_VEW_STRUCT_H *l_dl_prev_eom_safek_vew_struct_h;
DL_REGCYCLE_STRUCT_H *l_dl_regcycle_struct_h;
DL_REGDET_STRUCT_H *l_dl_regdet_struct_h;
DL_REGPAR_STRUCT_H *l_dl_regpar_struct_h;
DL_REG_STATISTICS_VEW_STRUCT_H *l_dl_reg_statistics_vew_struct_h;
DL_REG_STATUS_VEW_STRUCT_H *l_dl_reg_status_vew_struct_h;
/*DL_REPIRE_VEW_STRUCT_H *l_dl_repire_vew_struct_h;*/
DL_RUARCHSAFEK_STRUCT_H *l_dl_ruarchsafek_struct_h;
DL_RUCLIENT_STRUCT_H *l_dl_ruclient_struct_h;
DL_RUDEAL_STRUCT_H *l_dl_rudeal_struct_h;
DL_RUDEAL_TMP_STRUCT_H *l_dl_rudeal_tmp_struct_h;
DL_RUHISDEAL_STRUCT_H *l_dl_ruhisdeal_struct_h;
DL_RUHISSAFEK_STRUCT_H *l_dl_ruhissafek_struct_h;
DL_RUINSTRUMENT_STRUCT_H *l_dl_ruinstrument_struct_h;
DL_RULOCATION_STRUCT_H *l_dl_rulocation_struct_h;
DL_RUPRODUCT_STRUCT_H *l_dl_ruproduct_struct_h;
DL_RUSAFEK_STRUCT_H *l_dl_rusafek_struct_h;
DL_RUSRN_STRUCT_H *l_dl_rusrn_struct_h;
DL_SAFEK_STRUCT_H *l_dl_safek_struct_h;
DL_SAFEK_VEW_STRUCT_H *l_dl_safek_vew_struct_h;
/*DL_SECTORWISE_HOLD_VEW_STRUCT_H *l_dl_sectorwise_hold_vew_struct_h;*/
DL_SETLRPT_STRUCT_H *l_dl_setlrpt_struct_h;
DL_SETLRPT_VEW_STRUCT_H *l_dl_setlrpt_vew_struct_h;
DL_SFEREJ_STRUCT_H *l_dl_sferej_struct_h;
DL_SMI_PENDTXN_STRUCT_H *l_dl_smi_pendtxn_struct_h;
DL_SMI_TMP_TRADE_STRUCT_H *l_dl_smi_tmp_trade_struct_h;
DL_SUMFUTURE_VDP_VEW_STRUCT_H *l_dl_sumfuture_vdp_vew_struct_h;
DL_TMPMSGLINKDET_STRUCT_H *l_dl_tmpmsglinkdet_struct_h;
DL_TMPMSGLINK_STRUCT_H *l_dl_tmpmsglink_struct_h;
DL_WEEKTXNBAL_STRUCT_H *l_dl_weektxnbal_struct_h;
DW_ARESPONSE_VEW_STRUCT_H *l_dw_aresponse_vew_struct_h;
DW_CACHEQUE_VEW_STRUCT_H *l_dw_cacheque_vew_struct_h;
/*DW_CAEVENT_VEW_STRUCT_H *l_dw_caevent_vew_struct_h;*/
DW_CANOTE_VEW_STRUCT_H *l_dw_canote_vew_struct_h;
DW_DLDEAL_VEW_STRUCT_H *l_dw_dldeal_vew_struct_h;
DW_DLSAFEK_VEW_STRUCT_H *l_dw_dlsafek_vew_struct_h;
/*DW_MTCLIENT_VEW_STRUCT_H *l_dw_mtclient_vew_struct_h;*/
DW_MTDAILY_MKT_PRICE_VEW_STRUCT_H *l_dw_mtdaily_mkt_price_vew_struct_h;
/*DW_MTINSTRUMENT_VEW_STRUCT_H *l_dw_mtinstrument_vew_struct_h;*/
GN_AUDIT_LOG_STRUCT_H *l_gn_audit_log_struct_h;
GN_AUDIT_MAP_230106_STRUCT_H *l_gn_audit_map_230106_struct_h;
GN_AUDIT_MAP_BAK_STRUCT_H *l_gn_audit_map_bak_struct_h;
GN_AUDIT_MAP_DUMMY_STRUCT_H *l_gn_audit_map_dummy_struct_h;
GN_AUDIT_MAP_STRUCT_H *l_gn_audit_map_struct_h;
GN_COMMON_STATUS_BAK_STRUCT_H *l_gn_common_status_bak_struct_h;
GN_COMMON_STATUS_STRUCT_H *l_gn_common_status_struct_h;
GN_CRITERIA_PICKLIST_STRUCT_H *l_gn_criteria_picklist_struct_h;
GN_ENTITY_PICKLIST_230106_STRUCT_H *l_gn_entity_picklist_230106_struct_h;
GN_ENTITY_PICKLIST_300106_STRUCT_H *l_gn_entity_picklist_300106_struct_h;
GN_ENTITY_PICKLIST_BAK_STRUCT_H *l_gn_entity_picklist_bak_struct_h;
GN_ENTITY_PICKLIST_STRUCT_H *l_gn_entity_picklist_struct_h;
/*INVOICE_SYSTEMPARAM_STRUCT_H *l_invoice_systemparam_struct_h;*/
IV_ARCHCHEQUE_STRUCT_H *l_iv_archcheque_struct_h;
IV_ARCHCLIENTHOLDING_STRUCT_H *l_iv_archclientholding_struct_h;
IV_ARCHEXCHANGERATE_STRUCT_H *l_iv_archexchangerate_struct_h;
IV_ARCHEXTRASERVICE_STRUCT_H *l_iv_archextraservice_struct_h;
IV_ARCHLEDGER_STRUCT_H *l_iv_archledger_struct_h;
IV_ARCHOUTSTANDINGAMT_STRUCT_H *l_iv_archoutstandingamt_struct_h;
IV_ARCHSERVICECHG_STRUCT_H *l_iv_archservicechg_struct_h;
IV_ARCHTRANSACTION_STRUCT_H *l_iv_archtransaction_struct_h;
IV_BILL_STRUCT_H *l_iv_bill_struct_h;
IV_CHEQUE_DET_STRUCT_H *l_iv_cheque_det_struct_h;
IV_CHEQUE_STRUCT_H *l_iv_cheque_struct_h;
IV_CLIENTFEE_STRUCT_H *l_iv_clientfee_struct_h;
IV_CLIENTHOLDING_STRUCT_H *l_iv_clientholding_struct_h;
IV_CLIENTPARAM_STRUCT_H *l_iv_clientparam_struct_h;
IV_CLIENTSETUP_STRUCT_H *l_iv_clientsetup_struct_h;
IV_CLIENT_SERV_BASIS_STRUCT_H *l_iv_client_serv_basis_struct_h;
IV_CLIENT_STRUCT_H *l_iv_client_struct_h;
IV_DATA_GRP_STRUCT_H *l_iv_data_grp_struct_h;
IV_DEAL_FEE_STRUCT_H *l_iv_deal_fee_struct_h;
IV_DEAL_STRUCT_H *l_iv_deal_struct_h;
IV_DEAL_TYPE_STRUCT_H *l_iv_deal_type_struct_h;
IV_EXCHANGERATE_STRUCT_H *l_iv_exchangerate_struct_h;
IV_LEDGER_STRUCT_H *l_iv_ledger_struct_h;
/*IV_LEDGER_VW_STRUCT_H *l_iv_ledger_vw_struct_h;*/
IV_OUTSTANDINGAMT_STRUCT_H *l_iv_outstandingamt_struct_h;
IV_SELCLIENT_STRUCT_H *l_iv_selclient_struct_h;
IV_SERVICE_CHRG_STRUCT_H *l_iv_service_chrg_struct_h;
IV_SERV_BASIS_STRUCT_H *l_iv_serv_basis_struct_h;
IV_SERV_DEPEND_STRUCT_H *l_iv_serv_depend_struct_h;
IV_SERV_MAST_STRUCT_H *l_iv_serv_mast_struct_h;
IV_SERV_OTH_STRUCT_H *l_iv_serv_oth_struct_h;
/*IV_SUPERVISIONFEEGRP_VEW_STRUCT_H *l_iv_supervisionfeegrp_vew_struct_h;*/
MASTATUS_STRUCT_H *l_mastatus_struct_h;
MAUDIT_TRACK_STRUCT_H *l_maudit_track_struct_h;
MHLP_CODE_STRUCT_H *l_mhlp_code_struct_h;
MMARKETRATE_VW_STRUCT_H *l_mmarketrate_vw_struct_h;
MS_ARCHMSGLOG_STRUCT_H *l_ms_archmsglog_struct_h;
MS_ARCHMSGSTAT_STRUCT_H *l_ms_archmsgstat_struct_h;
MS_BASE_STRUCT_H *l_ms_base_struct_h;
MS_DETAILSMAP_STRUCT_H *l_ms_detailsmap_struct_h;
MS_HISMSGSTAT_STRUCT_H *l_ms_hismsgstat_struct_h;
MS_INMSGRP_STRUCT_H *l_ms_inmsgrp_struct_h;
MS_MSGCRF_STRUCT_H *l_ms_msgcrf_struct_h;
MS_MSGENT_STRUCT_H *l_ms_msgent_struct_h;
MS_MSGLOG_STRUCT_H *l_ms_msglog_struct_h;
MS_MSGSTAT_STRUCT_H *l_ms_msgstat_struct_h;
MS_MSG_SETL_VEW_STRUCT_H *l_ms_msg_setl_vew_struct_h;
MS_SEQUENCEMAP_STRUCT_H *l_ms_sequencemap_struct_h;
MT_ARCHDLYMKTPRC_STRUCT_H *l_mt_archdlymktprc_struct_h;
/*MT_CLIENTLST_VEW_STRUCT_H *l_mt_clientlst_vew_struct_h;*/
MT_CLIENT_DEPO_STRUCT_H *l_mt_client_depo_struct_h;
MT_CLIENT_ENTRIES_STRUCT_H *l_mt_client_entries_struct_h;
MT_CLIENT_STRUCT_H *l_mt_client_struct_h;
MT_CLI_DEPO_MAP_STRUCT_H *l_mt_cli_depo_map_struct_h;
MT_CLI_EXCH_MAP_STRUCT_H *l_mt_cli_exch_map_struct_h;
MT_CLN_INST_MAP_STRUCT_H *l_mt_cln_inst_map_struct_h;
MT_CLTDEPO_STRUCT_H *l_mt_cltdepo_struct_h;
MT_COMMON_SYS_PARAMS_STRUCT_H *l_mt_common_sys_params_struct_h;
MT_COMPANY_STRUCT_H *l_mt_company_struct_h;
/*MT_CORE_SYS_PARAMS_STRUCT_H *l_mt_core_sys_params_struct_h;*/
MT_CR_AGENCY_DET_BKUP_STRUCT_H *l_mt_cr_agency_det_bkup_struct_h;
MT_CR_AGENCY_DET_STRUCT_H *l_mt_cr_agency_det_struct_h;
MT_CR_AGENCY_STRUCT_H *l_mt_cr_agency_struct_h;
MT_DAILY_FLOAT_RATE_STRUCT_H *l_mt_daily_float_rate_struct_h;
MT_DAILY_QUOT_STRUCT_H *l_mt_daily_quot_struct_h;
MT_DEPO_PART_STRUCT_H *l_mt_depo_part_struct_h;
MT_DLYMKTPRC_STRUCT_H *l_mt_dlymktprc_struct_h;
MT_EOMMTHLYMKTPRC_STRUCT_H *l_mt_eommthlymktprc_struct_h;
MT_EOMSYSDATE_STRUCT_H *l_mt_eomsysdate_struct_h;
MT_EXCHRATE_STRUCT_H *l_mt_exchrate_struct_h;
MT_FLRATE_INSTRUMENT_STRUCT_H *l_mt_flrate_instrument_struct_h;
MT_GRPDETAILS_STRUCT_H *l_mt_grpdetails_struct_h;
MT_HISDLYMKTPRC_STRUCT_H *l_mt_hisdlymktprc_struct_h;
MT_HOLIDAY_STRUCT_H *l_mt_holiday_struct_h;
MT_IDENTMNT_STRUCT_H *l_mt_identmnt_struct_h;
MT_INDEX_FUNDDET_STRUCT_H *l_mt_index_funddet_struct_h;
MT_INDEX_FUND_STRUCT_H *l_mt_index_fund_struct_h;
MT_INSL_ENTRY_STRUCT_H *l_mt_insl_entry_struct_h;
MT_INSTRUMENT_STRUCT_H *l_mt_instrument_struct_h;
MT_INSTR_EXCH_DET_STRUCT_H *l_mt_instr_exch_det_struct_h;
MT_INSTR_RATING_DET_STRUCT_H *l_mt_instr_rating_det_struct_h;
MT_LOCATION_STRUCT_H *l_mt_location_struct_h;
/*MT_MESSAGE_SYS_PARAMS_STRUCT_H *l_mt_message_sys_params_struct_h;*/
MT_MKTPRC_GEN_VEW_STRUCT_H *l_mt_mktprc_gen_vew_struct_h;
MT_MSGADDRESS_STRUCT_H *l_mt_msgaddress_struct_h;
/*MT_MSGADDRESS_VEW_STRUCT_H *l_mt_msgaddress_vew_struct_h;*/
MT_MTHLYMKTPRC_STRUCT_H *l_mt_mthlymktprc_struct_h;
MT_NO_DELV_STRUCT_H *l_mt_no_delv_struct_h;
MT_PARTY_STRUCT_H *l_mt_party_struct_h;
MT_PC_DET_STRUCT_H *l_mt_pc_det_struct_h;
MT_PTC_DET_STRUCT_H *l_mt_ptc_det_struct_h;
MT_PTY_DEPO_MAP_STRUCT_H *l_mt_pty_depo_map_struct_h;
MT_PTY_EXCH_CLN_MAP_STRUCT_H *l_mt_pty_exch_cln_map_struct_h;
MT_PTY_EXCH_MAP_STRUCT_H *l_mt_pty_exch_map_struct_h;
MT_RBI_MONITORY_STRUCT_H *l_mt_rbi_monitory_struct_h;
MT_RED_DET_STRUCT_H *l_mt_red_det_struct_h;
MT_RED_DP_DET_STRUCT_H *l_mt_red_dp_det_struct_h;
MT_REGDETAILS_STRUCT_H *l_mt_regdetails_struct_h;
MT_RESET_DET_STRUCT_H *l_mt_reset_det_struct_h;
MT_SCHDET_STRUCT_H *l_mt_schdet_struct_h;
MT_SCHDET_TEMP_STRUCT_H *l_mt_schdet_temp_struct_h;
/*MT_SCHDET_VEW_STRUCT_H *l_mt_schdet_vew_struct_h;*/
MT_SETTL_CAL_STRUCT_H *l_mt_settl_cal_struct_h;
MT_TEMPMKTPRC_STRUCT_H *l_mt_tempmktprc_struct_h;
MT_WHTRATE_STRUCT_H *l_mt_whtrate_struct_h;
OR_ARCHEXEC_STRUCT_H *l_or_archexec_struct_h;
OR_ARCHORDERS_STRUCT_H *l_or_archorders_struct_h;
OR_EXECORDER_STRUCT_H *l_or_execorder_struct_h;
OR_HISEXECORDER_STRUCT_H *l_or_hisexecorder_struct_h;
OR_HISORDER_STRUCT_H *l_or_hisorder_struct_h;
OR_ORDERDETAILS_STRUCT_H *l_or_orderdetails_struct_h;
OR_ORD_LR_VEW_STRUCT_H *l_or_ord_lr_vew_struct_h;
PLAN_TABLE_STRUCT_H *l_plan_table_struct_h;
PRO_ACCTENT_STRUCT_H *l_pro_acctent_struct_h;
PRO_CNTRY_SYS_PARAMS_STRUCT_H *l_pro_cntry_sys_params_struct_h;
PRO_COMMON_REPORT_STRUCT_H *l_pro_common_report_struct_h;
PRO_DAEMON_STATUS_STRUCT_H *l_pro_daemon_status_struct_h;
PRO_EURO_TEMP_STRUCT_H *l_pro_euro_temp_struct_h;
PRO_FAILCODES_STRUCT_H *l_pro_failcodes_struct_h;
PRO_GMATCHVALUE_STRUCT_H *l_pro_gmatchvalue_struct_h;
PRO_GRACCTENT_STRUCT_H *l_pro_gracctent_struct_h;
PRO_GSEQNUM_STRUCT_H *l_pro_gseqnum_struct_h;
PRO_GSHELPID_STRUCT_H *l_pro_gshelpid_struct_h;
PRO_GSSPLVAL_STRUCT_H *l_pro_gssplval_struct_h;
PRO_HDAT_STATIC_STRUCT_H *l_pro_hdat_static_struct_h;
PRO_MQNAMES_STRUCT_H *l_pro_mqnames_struct_h;
PRO_MQ_DATA_STRUCT_H *l_pro_mq_data_struct_h;
PRO_MSGCONV_STRUCT_H *l_pro_msgconv_struct_h;
PRO_REQUEST_BATCH_STRUCT_H *l_pro_request_batch_struct_h;
PRO_REQUEST_CA_STRUCT_H *l_pro_request_ca_struct_h;
PRO_REQUEST_DEAL_STRUCT_H *l_pro_request_deal_struct_h;
PRO_REQUEST_IV_STRUCT_H *l_pro_request_iv_struct_h;
PRO_REQUEST_MT_STRUCT_H *l_pro_request_mt_struct_h;
PRO_REQUEST_UPLOAD_STRUCT_H *l_pro_request_upload_struct_h;
PRO_SGENSTAT_BAK_STRUCT_H *l_pro_sgenstat_bak_struct_h;
PRO_SGENSTAT_STRUCT_H *l_pro_sgenstat_struct_h;
PRO_SYS_DATE_STRUCT_H *l_pro_sys_date_struct_h;
PRO_TEMP_MQDATA_STRUCT_H *l_pro_temp_mqdata_struct_h;
SYS_BATCHPROC_STRUCT_H *l_sys_batchproc_struct_h;
SYS_BATCHSTREAM_STRUCT_H *l_sys_batchstream_struct_h;
SYS_BATCH_CNTRL_STRUCT_H *l_sys_batch_cntrl_struct_h;
SYS_IVCONTROLPARAM_STRUCT_H *l_sys_ivcontrolparam_struct_h;
TEMP12_STRUCT_H *l_temp12_struct_h;
TT_STRUCT_H *l_tt_struct_h;
YEARLY_AE_STRUCT_H *l_yearly_ae_struct_h;

/** Added Only for Data Migration **/

typedef struct error_struct {
	int h_err_warn;
	int h_code;
	char h_key1[20];
	char h_key2[20];
	char h_key3[20];
	char h_file[50];
	int h_line;
	int ok_ind;
	int h_ctx_no;
	int debug_ind;
	char *msg;
	struct error_struct *h_next;
} DEBUG_INFO_STRUCT_H;


typedef struct  {
	char usr[15];
	char h_mode[4];
	char processtion[61];
	char auth_req[2];
	char subprocess[4];
	char h_process[2];
} INTL_ENV_DATA_STRUCT_H;


#define  IS_ANY_ORA_ERROR \
	if (sqlca.sqlcode < 0)\
{\
	char  chr_buffer[KEY_LENGTH];\
	ltoa_r(sqlca.sqlcode,chr_buffer,KEY_LENGTH-1);\
	sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
	CO_InsertOraErr(l_debug_info_ptr,\
			sqlca.sqlerrm.sqlerrmc,\
			chr_buffer,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	goto RETURN_FAILURE;\
}

#define INTL_WARNING \
{\
	CO_InsertWarning( &l_debug_info_struct_h_tmp,\
			APL_NOT_AN_ERROR,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	CO_OkWarning(l_debug_info_struct_h_tmp);\
	l_debug_info_struct_h_tmp->h_next = *l_debug_info_ptr;\
	*l_debug_info_ptr = l_debug_info_struct_h_tmp;\
}

#define  APL_FREE(l_debug) \
	if (l_debug != NULL)\
{\
	free(l_debug);\
	l_debug = NULL;\
}
#define  APL_MALLOC_FAIL(pointer) \
	if (pointer == NULL)\
{\
	CO_InsertErr(l_debug_info_ptr,\
			ERR_NO_MEMORY,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	goto RETURN_FAILURE;\
}

#define  APL_MALLOC_FAIL_LOC_A(pointer) \
	if (pointer == NULL)\
{\
	CO_InsertErr(l_debug_info_ptr,\
			ERR_NO_MEMORY,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	Proc_MarkFailProcess(l_rowid, l_debug_info_ptr);\
	continue;\
}
#define  APL_DATA_MISSING(h_key1,h_key2,h_key3) \
	CO_InsertErr(l_debug_info_ptr,\
			ERR_MAND_DATA_MISSING,\
			h_key1,\
			h_key2,\
			h_key3,\
			__LINE__,\
			__FILE__);
#define  IS_ANY_ORA_ERROR \
	if (sqlca.sqlcode < 0)\
{\
	char  chr_buffer[KEY_LENGTH];\
	ltoa_r(sqlca.sqlcode,chr_buffer,KEY_LENGTH-1);\
	sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
	CO_InsertOraErr(l_debug_info_ptr,\
			sqlca.sqlerrm.sqlerrmc,\
			chr_buffer,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	goto RETURN_FAILURE;\
}


#define  S_NON_DCE_ERASE_DUMMY_WARNING \
{\
	if (*l_debug_info_ptr != NULL) \
	{\
		l_debug_info_struct_h_tmp =  (*l_debug_info_ptr)->h_next;\
		free(*l_debug_info_ptr);\
		*l_debug_info_ptr = l_debug_info_struct_h_tmp;\
	}\
}

#define  IS_ANY_ORA_ERROR_AND_ZERO_RESULTSET(error_code,h_key1,h_key2,h_key3) \
if (sqlca.sqlcode < 0)\
{\
	char  chr_buffer[KEY_LENGTH];\
	ltoa_r(sqlca.sqlcode,chr_buffer,KEY_LENGTH-1);\
	sqlca.sqlerrm.sqlerrmc[APL_ORA_MSG_LENGTH] = '\0';\
	CO_InsertOraErr(l_debug_info_ptr,\
			sqlca.sqlerrm.sqlerrmc,\
			chr_buffer,\
			APL_NULL_STRING,\
			APL_NULL_STRING,\
			__LINE__,\
			__FILE__);\
	goto RETURN_FAILURE;\
}\
else if (sqlca.sqlcode == 1403)\
{\
	CO_InsertErr(l_debug_info_ptr,\
			error_code,\
			h_key1,\
			h_key2,\
			h_key3,\
			__LINE__,\
			__FILE__);\
	goto RETURN_FAILURE;\
}

#define CHECK_EXISTANCE_OF_ERROR \
	(CO_ChkErr(*l_debug_info_ptr)==APL_FAILURE)
