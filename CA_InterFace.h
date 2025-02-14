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
 * Module Name         :      Corporate Actions
 *
 * File Name           :      CA_Interface.h
 *
 * Description         :      Contains Structure Variables & Extern fns Related to CA
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author           Description        RFS No.
 * ---------   --------  ---------------  ------------------   ---------
 * 20/01/2006   1.2        Pradeep        New File          HDFCCA_015
 * 20/01/2006   1.3        Smita Bhat	  Added Structures  HDFCCA_027
 *										  			  for Event Table
 *	22/06/2006   1.6			Smita Bhat	  Changed Entitlement
 *													  Structure				HDFCCA_001,HDFCCA_002,HDFCCA_017
 *  02/03/2006  1.7        Vaibhav           CA_NIS_ALLOTMENT
 *************************************************************************/
#include "CO_LenConstdef.h"   

#ifndef CA_HEADER_INCLUDED
#define CA_HEADER_INCLUDED
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
#define CA_INFO_NUMLEN (5)
#define CA_INFO_LEN (1751)
#define A_ADDRESS_LEN (241)
#define A_PAYMNTINST_LEN (51)
#define CA_FUNC_CD_LEN APL_FUNC_NAME_LENGTH
#define A_KEYVAL_LEN (35)
#define CORP_ID_LEN (21)
#define EVT_CLASS_ (3)
#define CA_INFOTCLASS_LEN (5)
#define A_OTH_PROC_LEN (106)
#define A_LEN_BATCH_NO (5)

/*Smita - Changed Structure for Event Table - HDFCCA_027*/
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
	char h_bk_build_ind[CA_BK_BUILD_IND_LEN]; /*Added by Vaibhav RFSNO:HDFCCA_013*/
	char h_attach_corp_id[CA_ATTACH_CORP_ID_LEN]; 
	char h_source[CA_SOURCE_LEN];
	double h_new_safek_rt2;
	double h_tick_size;
	double h_issue_size;   /* changes done by punnamchander for ISKB_4994 - jul 08/08/2011 */
	double h_qib_margin;
	int h_market_lot;
	int h_max_rtl_qty;
	int h_min_qty;
	char h_lead_mgr[CA_LEAD_MGR_LEN];
	char h_synd_membr[CA_SYND_MEMBR_LEN];
	char h_co_mgr[CA_CO_MGR_LEN];
	double h_lwr_limit;
	double h_upr_limit;
        double h_fract_qty_bal;
        double h_fract_qty_recd;
		char h_bilav_id[CA_BILAV_ID_LEN];   //Added by Arunachalam for CS0074500 - New Bilav File upload changes
} CA_CAEVENT_STRUCT_H;
/*Smita - Changed Structure for Event Table - HDFCCA_027*     /

/*Smita - HDFCCA_001,HDFCCA_002,HDFCCA_017 - Changed Structure for CAENTITLEMENT */
typedef struct  {
char h_corp_id[CA_CORP_ID_LEN];
char h_dl_client[CA_CLN_CODE_LEN];
double h_entitl_pos;
char h_entitl_ccy[CA_CA_CURRENCY_LEN];
double h_instr_inc_bal;
double h_amount_recd;
double h_quantity_due;
double h_quantity_recd;
char h_nrepdate2[APL_DATE_LEN];
char h_nrepdate3[APL_DATE_LEN];
char h_sent550date[APL_DATE_LEN];
char h_entitl_stat[MT_STATUS_LEN];
char h_stat_date[APL_DATE_LEN];
char h_maker[MT_MAKER_LEN];
char h_maker_dt[APL_DATE_LEN];
char h_checker[MT_CHECKER_LEN];
char h_checker_dt[APL_DATE_LEN];
char h_access_stamp[APL_DATE_LEN];
double h_tax_rate; 
double h_fract_due;
double h_fract_rcvd;
} CA_CAENTITLEMENT_STRUCT_H;
/*Smita - HDFCCA_001,HDFCCA_002,HDFCCA_017 - Changed Structure for CAENTITLEMENT */

typedef struct  {
char h_corp_id[21];
char h_dl_client[11];
int h_pymt_srl_nbr;
char h_pymt_dt[20];
char h_pymt_currency[4];
double h_curr_pymt;
double h_quantity_recd;
double h_tax_rate;
char h_pymt_inst[51];
char h_handoff_date[20];
char h_txn_indentity_no[17];
char h_billdate[20];
char h_loccode[5];
double h_tax_amount;
double h_other_chrgs;
char h_pymt_stat[3];
char h_stat_date[20];
char h_new_dt[20];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_clt_pass_flg[2];
char h_clt_batch_no[10];
double h_quantity_paid;
double h_taxable_dividend;
double h_fract_qty_bal;
double h_fract_qty_recd;
char h_cpa_reported[3];
double h_writeoff_amount;
double h_net_amount; //Changes done by Sunny for CS0020637
} CA_CACHEQUE_STRUCT_H;

typedef struct  {
char h_instr_code[9];
char h_dl_client[11];
char h_ca_event[3];
char h_decl_date[20];
int h_evt_nbr;
char h_instr_parent[9];
char h_corp_id[21];
double h_total_quantity;
double h_takeupquantity;
double h_lapsequenceuantity;
char h_loccode[5];
int h_sub_base_quantity;
double h_sub_new_quantity;
char h_sub_currency[4];
double h_sub_pr;
char h_info_nbr[5];
char h_evt_stat[3];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_pymt_dt[20];
char h_transmit_date[20];
} CA_CARTSPROC_STRUCT_H;
typedef struct  {
char h_instr_code[9];
char h_dl_client[11];
char h_ca_event[3];
int h_evt_nbr;
char h_access_stamp[20];
char h_decl_date[20];
char h_checker[15];
char h_checker_dt[20];
char h_pymt_dt[20];
} CA_RHTS_SUTH_STRUCT_H;
typedef struct  {
char h_info_nbr[9];
char h_info_1[1751];
char h_info_2[1751];
char h_info_3[1751];
char h_info_4[1751];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_info_class[CA_INFOTCLASS_LEN];
} CA_CANOTE_STRUCT_H;
typedef struct  {
char h_corp_id[21];
double h_entitl_pos;
double h_quantity_due;
double h_amount_due;
char h_pymt_dt[20];
double h_cur_quantity_due;
double h_cur_amount_due;
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_pymt_stat[3];
char h_access_stamp[20];
char h_new_dt[20];
double h_quantity_paid;
double h_taxable_dividend;
char h_loccode[5];
} CA_CAGLPYMT_STRUCT_H;
typedef struct  {
char h_corp_id[21];
char h_access_stamp[20];
} CA_CAEVNT_AUT_STRUCT_H;
typedef struct  {
char h_corp_id[21];
char h_dl_client[11];
char h_access_stamp[20];
} CA_CAENTL_AUT_STRUCT_H;
typedef struct  {
char h_corp_id[21];
char h_dl_client[11];
int h_pymt_srl_nbr;
char h_access_stamp[20];
} CA_CAPYMT_AUT_STRUCT_H;
/* Vaibhav - HDFCCA_015 - CA_Allotment */
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_cln_code[CA_CLN_CODE_LEN];
	char h_canrefno[CA_CANREFNO_LEN];
	char h_candate[APL_DATE_LEN];
	char h_canrecdate[APL_DATE_LEN];
	double h_qtyshallot;
	char h_blockflg[CA_BLOCKFLG_LEN];
	double h_price;
	double h_mmpaid;
	double h_money_payable;
	double h_amountpay;
	char h_lastdatetime[APL_DATE_LEN];
	char h_clastdatetime[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_hf_date[21];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
	char h_processed_date[21];
}CA_NIS_ALLOTMENT_STRUCT_H;
/* Vaibhav - HDFCCA_015 - CA_Allotment */
/*Added by Chirag on 25/02/2006 for NIS BIDDING*/
typedef struct{
   char h_corp_id[21];
   char h_cln_code[11];
   int h_brevno;
   char h_applfrmno[11];
   char h_depo_code[5];
   char h_depo_cln_id[21];
   char h_dp_id[21];
   char h_bdate[APL_DATE_LEN];
   double h_bqty1;
   double h_brate1;
   double h_bqty2;
   double h_brate2;
   double h_bqty3;
   double h_brate3;
   char h_filegenflg[2];
   char h_paycomm[101];
   char h_maker[15];
   char h_maker_dt[APL_DATE_LEN];
   char h_checker[15];
   char h_checker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_status[3];
   char h_synd_membr[11];
   double h_mmpaynw;
	char h_hf_date[21];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
	char h_processed_date[21];
}CA_NIS_BID_STRUCT_H;
/*Added by Chirag on 25/02/2006 for NIS BIDDING*/

/*Added by Chirag on 25/02/2006 for NIS Application*/
typedef struct{
   char h_corp_id[21];
   char h_cln_code[11];
   char h_applncode[11];
   char h_depo_code[5];
   char h_depo_cln_id[21];
   char h_dp_id[21];
   char h_synd_membr[11];
   char h_adate[APL_DATE_LEN];
   double h_aqty;
   double h_arate;
   double h_mmpaid;
   char h_filegenflg[2];
   char h_paycomm[101];
   char h_maker[15];
   char h_maker_dt[APL_DATE_LEN];
   char h_checker[15];
   char h_checker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_status[3];
   int h_brevno;
   char h_bk_build_ind[2];
   char h_alloted[2];  
   char h_hf_date[21];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
	char h_processed_date[21];
}CA_NIS_APPLICATION_STRUCT_H;
/*Added by Chirag on 25/02/2006 for NIS Application*/
/*Vaibhav CA_APPLICATION*/
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_cln_code[CA_CLN_CODE_LEN];
	char h_application_date[APL_DATE_LEN];
	double h_applied_qty;
	double h_avl_qty;
	double h_addqty_app;
	double h_price;
	double h_amt_payable;
	double h_amt_due;
	char h_remark[CA_REMARK_LEN];
	char h_status[MT_STATUS_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_depo_code[MT_DEPO_CODE_LEN];
	char h_depo_cln_id[CA_DEPO_CLN_ID_LEN];
	char h_dp_id[MT_DP_ID_LEN];
	char h_cln_refno[CA_CLN_REFNO_LEN];
	int h_cln_srno;
	char h_hf_date[APL_DATE_LEN];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
	char h_processed_date[APL_DATE_LEN];
}CA_APPLICATION_STRUCT_H;    /*Vaibhav CA_APPLICATION*/
/* Open offer */
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_cln_code[CA_CLN_CODE_LEN];
	int h_cln_srno;
	char h_depo_code[MT_DEPO_CODE_LEN];
	double h_applied_qty;
	double h_moved_qty;
	double h_price;
}CA_APPLICATION_CABL_STRUCT_H;    /*Vaibhav CA_APPLICATION*/

/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/
typedef struct{
	char h_corp_id[CA_CORP_ID_LEN];
	char h_cln_code[CA_CLN_CODE_LEN];
	char h_ca_event[CA_CA_EVENT_LEN];
	char h_allot_dt[APL_DATE_LEN];
	double h_alloted_qty;
	double h_add_allot_qty;
	double h_amt_pay;
	double h_amt_rec;
	char h_typeof_info[CA_TYPEOF_INFO_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_hf_date[21];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
	char h_processed_date[21];
	char h_depo_cd[MT_DEPO_CODE_LEN];
	char h_dp_id[MT_DP_ID_LEN];
	char h_cln_id[CA_DEPO_CLN_ID_LEN];
	double h_amt_payable; /* 23-01-2007 4 New Col. Added By Chirag For RT */
   double h_addqty_app;
   double h_applied_qty;	
	char h_orig_depo_cd[MT_DEPO_CODE_LEN];
}CA_RTBB_ALLOTMENT_STRUCT_H;
/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/
/*Added by Vaibhav for CA_PUTCALL_APP*/
typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_cln_code[CA_CLN_CODE_LEN];
	char h_notice_date[APL_DATE_LEN];
	char h_instr_type[MT_INSTR_TYPE_LEN];
	char h_value_date[APL_DATE_LEN];
	double h_avl_qty;
	double h_put_call_qty;
	double h_put_call_value;
	double h_put_call_rate;
	char h_status[MT_STATUS_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_info_seq[CA_INFO_SEQ_LEN];
	char h_pymt_send_msg_ind[CA_PYMT_SEND_MSG_IND_LEN];
	char h_processed_date[APL_DATE_LEN];
	char h_r_corp_id[CA_CORP_ID_LEN];
	char h_hf_date[21];
	char h_clt_seqnum[10];
	char h_ae_passind[2];
}CA_PUTCALL_APP_STRUCT_H;
/*Added by Vaibhav for CA_PUTCALL_APP*/
typedef struct{
	char h_on_date[APL_DATE_LEN];
	char h_calc_date[APL_DATE_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_cln_code[MT_CLN_CODE_LEN];
	double h_intrate;
	double h_safek;
	double h_facevalue;
	double h_baseamount;
	double h_interest;
	double h_gain_safek;
	double h_gain_amount;
	double h_gain_int;
}CADAILY_FLOATINTEREST_STRUCT_H;
/** Added By Biju Float Instrument calculation **/

extern int wrp_A_BUpdRightsFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CARTSPROC_STRUCT_H *l_ca_cartsproc_struct_h_ptr,
     int *int_p_result,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_A_BAuthRightsFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_RHTS_SUTH_STRUCT_H *p_ca_rhts_suth_struct_h,
     int *int_p_result,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
extern int wrp_A_DbAuthEventFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVNT_AUT_STRUCT_H *p_ca_caevnt_aut_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbUpdEventFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbAuthPymtFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAPYMT_AUT_STRUCT_H *p_ca_capymt_aut_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbUpdPymtFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CACHEQUE_STRUCT_H *p_ca_cacheque_struct_h_d,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_UpdFootNote(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CANOTE_STRUCT_H *p_ca_canote_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbUpdEntitlFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAENTITLEMENT_STRUCT_H *p_ca_caentitlement_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbAuthEntitlFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAENTL_AUT_STRUCT_H *p_ca_caentl_aut_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_DbUpdGlobalPymtFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAGLPYMT_STRUCT_H *p_ca_caglpymt_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_A_RedenomEvtMntFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct corporate_action_v1_0_epv_t {
int (*wrp_A_BUpdRightsFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CARTSPROC_STRUCT_H *l_ca_cartsproc_struct_h_ptr,
     int *int_p_result,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_A_BAuthRightsFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_RHTS_SUTH_STRUCT_H *p_ca_rhts_suth_struct_h,
     int *int_p_result,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
int (*wrp_A_DbAuthEventFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVNT_AUT_STRUCT_H *p_ca_caevnt_aut_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbUpdEventFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbAuthPymtFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAPYMT_AUT_STRUCT_H *p_ca_capymt_aut_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbUpdPymtFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CACHEQUE_STRUCT_H *p_ca_cacheque_struct_h_d,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_UpdFootNote)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CANOTE_STRUCT_H *p_ca_canote_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbUpdEntitlFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAENTITLEMENT_STRUCT_H *p_ca_caentitlement_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbAuthEntitlFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAENTL_AUT_STRUCT_H *p_ca_caentl_aut_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_DbUpdGlobalPymtFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAGLPYMT_STRUCT_H *p_ca_caglpymt_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_RedenomEvtMntFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* Pradeep - HDFCCA_015 - CA_Allotment */
int (*wrp_A_AllotmentFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		CA_ALLOT_STRUCT_H *p_ca_allotment_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_A_PutcallFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		CA_PUTCALL_APP_STRUCT *p_ca_putcall_app_struct;
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
} corporate_action_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
