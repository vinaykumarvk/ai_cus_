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
/*****************************************************************************
 *
 * Module Name         :        Deal
 *
 * File Name           :        DL_Interface.h
 *
 * Description         :        Contains Structure Variable Definitions
 *                              for all Structures Related to Maintenance
 *
 *
 *            Version Control Block
 *
 * Date        Version   Author           Description             RFS No.
 * ---------   --------  ---------------  ----------------------- ---------
 * 23/11/2006  1.20      Amol Kulkarni    Depo Upload
 * -------------------------------------------------------------------------
 * 09-Jun-2010 1.0.1.13  Naren V          NSDL DP Ins File Format ISKB_3298
 *                                        Changes - Variable  Len
 *                                        changes were incorporat
 *                                        ed accordingly based on
 *                                        NSDL depository revised
 *                                        file formats.
 *****************************************************************************/


#include"CO_LenConstdef.h"

#ifndef DEAL_HEADER_INCLUDED
#define DEAL_HEADER_INCLUDED
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

#define HASIZE 5  /* Added For Jost Array Changes - Priyanka B - 12052015 */

typedef struct  {
char h_indentity_no[17];
char h_dlt[20];
char h_dealcd[5];
char h_instr_isin[13];
double h_qty;
char h_hdat_countclt[13];
double h_amt;
char h_setldt[20];
char h_locindentity_no[17];
char h_ext_clhclient[13];
} DL_DEAL_HDAT_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_fail_cd[3];
char h_custinfo[71];
char h_failinfo[36];
char h_access_stamp[20];
int h_subfailreas_cd;
} DL_DEAL_FAIL_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_dlt[20];
char h_setldt[20];
double h_pr;
char h_ex_arena[3];
double h_amt;
double h_custodycomm;
double h_brokercomm;
double h_stx_comm;
double h_oth_comm;
char h_instrdate[20];
char h_moneydate[20];
double h_qty;
char h_domcpclt_cd[11];
char h_isspotdl[2];
double h_origquantity;
double h_origamount;
char h_dlfromord[2];
char h_entry[2];
char h_reapired_ind[2];
char h_domcp_custodyclt[11];
char h_countclt[16];
char h_countcltnm[66];
char h_clientof[66];
char h_custinfo[71];
char h_fx_reqd[2];
char h_ispymtlocal[2];
char h_verfied_with[26];
double h_diffamount;
char h_brkrno[13];
char h_fail_cd[3];
char h_failinfo[36];
char h_ispart_[2];
double h_fx_rt;
int h_amend_count;
int h_number_a;
char h_report_at_eom_ind[2];
char h_billdate[20];
char h_locindentity_no[17];
char h_instruct_person[36];
double h_rec_int_000;
char h_dealcd[2];
char h_instr_code[13]; //Kalyan
char h_currencycode[4];
char h_classofdl[3];
char h_origindentity_no[17];
char h_newdt[20];
char h_maker[15];
char h_maker_dt[20];
char h_deal_status[3];
char h_access_stamp[20];
char h_info1[261];
char h_loccode[5];
char h_reginstr_ind[2];
char h_pos_stat[4];
char h_status_reg[2];
char h_confdate[20];
char h_matchindentity_no[17];
char h_markfaildate[20];
char h_candropdate[20];
char h_checker[15];
char h_checker_dt[20];
char h_instrconv_ind[2];
char h_ndsbldate[20];
char h_lrdltype[3];
char h_ndsdate[20];
char h_ublckdate[20];
double h_delta_000;
double h_delta_001;
double h_delta_002;
char h_delrecdate[20];
char h_lastregdate[20];
char h_lr_chkdate[20];
char h_lr_confdate[20];
char h_lr_instrdate[20];
double h_regmsgquantity;
char h_tmpoutdate[20];
char h_tmpretdate[20];
char h_transmitdate[20];
double h_complquantity;
double h_lostquantity;
double h_marktrfquantity;
double h_mcomplquantity;
double h_outregquantity;
double h_pendregquantity;
double h_retregquantity;
double h_stampquantity;
double h_tempoutquantity;
double h_tempretquantity;
double h_valdeedquantity;
char h_hostdate[20];
char h_lr_ndsbldate[20];
char h_lr_ndsdate[20];
char h_lr_ublckdate[20];
int h_number_b;
char h_clt_reqdel_flag[2];
char h_mod_hispos_ind[2];
char h_updhispos_date[20];
char h_cash_client[11];
double h_cpamt;
char h_msg_stat[51];
int h_subfailreas_cd;
char h_allow_part_s[2];
char h_locchng_flg[2];
char h_comm_indentity_no[17];
char h_instruct_personnm[66];
char h_clientofcode[11];
char h_inter_med_person[36];
char h_inter_med_personnm[66];
char h_fxccy[4];
char h_uniq_ident_no[15];
int h_548cnt;
char h_exp_setl_date[20];
char h_related_indentity_no[21];
char h_misinfo[201];/*modified by siva.ganapathi for ISKB - 2263*/
/* new fields added - HDFCDL_003 - Sundar */
char h_settlement_no[DL_SETTLEMENT_NO_LEN];
char h_mkt_type[DL_MKT_TYPE_LEN];
char h_clh_flg[DL_CLH_FLG_LEN];
double h_interest;                     /*CSGL changes from int to double by rahul*/
double h_net_amt;
char h_payin_dt[APL_DATE_LEN];
char h_payout_dt[APL_DATE_LEN];
double h_demat_qty;
char h_contract_req[DL_CONTRACT_REQ_LEN];
char h_excum_flg[DL_EXCUM_FLG_LEN];
char h_crn_no[DL_CRN_NO_LEN];
char h_interfii_flg[DL_INTERFII_FLG_LEN];
char h_pay_mode[DL_PAY_MODE_LEN];
char h_dl_secstatus[DL_DL_SECSTATUS_LEN];
char h_dl_mnystatus[DL_DL_MNYSTATUS_LEN];
double h_avail_qty;
double h_allot_qty;
double h_shortage_qty;
char h_cln_depoacc[DL_CLN_DEPOACC_LEN];
char h_pltopl_flg[DL_PLTOPL_FLG_LEN];
char h_orig_status[DL_ORIG_STATUS_LEN];
char h_map_failcode[DL_MAP_FAILCODE_LEN];
char h_match_failcode[DL_MATCH_FAILCODE_LEN];
char h_is_matched[DL_IS_MATCHED_LEN];
char h_exch_code[4];
char h_contract_cd[17];
char  h_r_delay[2];
char  h_sebi_reported[2];
char  h_r_sett_code[2];
char  h_r_trans_code[3];
char  h_r_type[3];
char  h_repo_date[APL_DATE_LEN];
/* new fields added - HDFCDL_003 - Sundar */
double h_comm_amt;     /**** For Detailed Bill printing : vinay kalaskar  *****/
char h_mf_seqno[6];   /*** For Billgeneration :vinay kalaskar ****/
/*Retro from HDFC by Ekta for Interoperability Starts*/
char h_trd_exch[4]; 
char h_trd_setl_no[16];
char h_trd_mkt_type[4];
/*Retro from HDFC by Ekta for Interoperability Ends*/
/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
double h_stamp_duty;
/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */

/* Added by RAHUL for adding CSGL - Starts */
   
   char h_dpm_trans_ref_no[17];
   double h_other_charges;
   char h_csgl_trade_type[21];
/* Added by RAHUL for adding CSGL - END */

} SYS_DL_DEAL_STRUCT_H;

/* Gouse - Single Prematch [Start] */
typedef struct{
	char h_dl_client[DL_CLIENT_CD_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	char h_confdate[APL_DATE_LEN];
	char h_exp_settl_date[APL_DATE_LEN];
	char h_verified_with[DL_VERIFIED_WITH_LEN];
	char h_info1[DL_INFO1_LEN];
	double h_diffamount;
	char h_ispartial[DL_ISPARTIAL_LEN];
	char h_broker_ord_no[DL_PM_BROKER_CD_LEN];
	char h_orig_identiy_no[DL_IDENTIY_NO_LEN];
	char h_loc_ref_no[DL_IDENTIY_NO_LEN];
	double h_newquantity;
	double h_newamount;
	double h_cpamt;
	char h_brok_cmbp_id[DL_BRK_CMBP_ID_LEN];
	char h_brok_dp_id[DL_BRK_DP_ID_LEN];
	char h_cp_dp_id[DL_CP_DP_ID_LEN];
	char h_cp_client_id[DL_CP_CLIENT_ID_LEN];
	char h_mkt_type[DL_MKT_TYPE_LEN];
	char h_location_cd[DL_LOCATION_CD_LEN];
	char h_execution_date[APL_DATE_LEN];
	char h_dp_instr_flag[DL_GENDP_FLG_LEN];
	char h_inter_dp_flag[DL_INTERDP_FLG_LEN];
	char h_defer_sec_sett_flg[DL_SEC_SETT_FLG_LEN];
	char h_defer_mon_sett_flg[DL_MON_SETT_FLG_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
}DL_SINGLE_PREMATCH_STRUCT_H;
/* Gouse - Single Prematch [End] */


/** Added by Vijay For SLB Reversal HB_03_001 **/
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_dlt[20];
char h_setldt[20];
double h_pr;
char h_ex_arena[3];
double h_amt;
double h_custodycomm;
double h_brokercomm;
double h_stx_comm;
double h_oth_comm;
char h_instrdate[20];
char h_moneydate[20];
double h_qty;
char h_domcpclt_cd[11];
char h_isspotdl[2];
double h_origquantity;
double h_origamount;
char h_dlfromord[2];
char h_entry[2];
char h_reapired_ind[2];
char h_domcp_custodyclt[11];
char h_countclt[16];
char h_countcltnm[66];
char h_clientof[66];
char h_custinfo[71];
char h_fx_reqd[2];
char h_ispymtlocal[2];
char h_verfied_with[26];
double h_diffamount;
char h_brkrno[13];
char h_fail_cd[3];
char h_failinfo[36];
char h_ispart_[2];
double h_fx_rt;
int h_amend_count;
int h_number_a;
char h_report_at_eom_ind[2];
char h_billdate[20];
char h_locindentity_no[17];
char h_instruct_person[36];
double h_rec_int_000;
char h_dealcd[2];
char h_instr_code[9];
char h_currencycode[4];
char h_classofdl[3];
char h_origindentity_no[17];
char h_newdt[20];
char h_maker[15];
char h_maker_dt[20];
char h_deal_status[3];
char h_access_stamp[20];
char h_info1[261];
char h_loccode[5];
char h_reginstr_ind[2];
char h_pos_stat[4];
char h_status_reg[2];
char h_confdate[20];
char h_matchindentity_no[17];
char h_markfaildate[20];
char h_candropdate[20];
char h_checker[15];
char h_checker_dt[20];
char h_instrconv_ind[2];
char h_ndsbldate[20];
char h_lrdltype[3];
char h_ndsdate[20];
char h_ublckdate[20];
double h_delta_000;
double h_delta_001;
double h_delta_002;
char h_delrecdate[20];
char h_lastregdate[20];
char h_lr_chkdate[20];
char h_lr_confdate[20];
char h_lr_instrdate[20];
double h_regmsgquantity;
char h_tmpoutdate[20];
char h_tmpretdate[20];
char h_transmitdate[20];
double h_complquantity;
double h_lostquantity;
double h_marktrfquantity;
double h_mcomplquantity;
double h_outregquantity;
double h_pendregquantity;
double h_retregquantity;
double h_stampquantity;
double h_tempoutquantity;
double h_tempretquantity;
double h_valdeedquantity;
char h_hostdate[20];
char h_lr_ndsbldate[20];
char h_lr_ndsdate[20];
char h_lr_ublckdate[20];
int h_number_b;
char h_clt_reqdel_flag[2];
char h_mod_hispos_ind[2];
char h_updhispos_date[20];
char h_cash_client[11];
double h_cpamt;
char h_msg_stat[51];
int h_subfailreas_cd;
char h_allow_part_s[2];
char h_locchng_flg[2];
char h_comm_indentity_no[17];
char h_instruct_personnm[66];
char h_clientofcode[11];
char h_inter_med_person[36];
char h_inter_med_personnm[66];
char h_fxccy[4];
char h_uniq_ident_no[15];
int h_548cnt;
char h_exp_setl_date[20];
char h_related_indentity_no[21];
char h_misinfo[201];/*modified by siva.ganapathi for ISKB - 2263*/
/* new fields added - HDFCDL_003 - Sundar */
char h_settlement_no[DL_SETTLEMENT_NO_LEN];
char h_mkt_type[DL_MKT_TYPE_LEN];
char h_clh_flg[DL_CLH_FLG_LEN];
double h_interest; /* Data type changed by ASHISH 01-10-2007 */
double h_net_amt;
char h_payin_dt[APL_DATE_LEN];
char h_payout_dt[APL_DATE_LEN];
double h_demat_qty;
char h_contract_req[DL_CONTRACT_REQ_LEN];
char h_excum_flg[DL_EXCUM_FLG_LEN];
char h_crn_no[DL_CRN_NO_LEN];
char h_interfii_flg[DL_INTERFII_FLG_LEN];
char h_pay_mode[DL_PAY_MODE_LEN];
char h_dl_secstatus[DL_DL_SECSTATUS_LEN];
char h_dl_mnystatus[DL_DL_MNYSTATUS_LEN];
double h_avail_qty;
double h_allot_qty;
double h_shortage_qty;
char h_cln_depoacc[DL_CLN_DEPOACC_LEN];
char h_pltopl_flg[DL_PLTOPL_FLG_LEN];
char h_orig_status[DL_ORIG_STATUS_LEN];
char h_map_failcode[DL_MAP_FAILCODE_LEN];
char h_match_failcode[DL_MATCH_FAILCODE_LEN];
char h_is_matched[DL_IS_MATCHED_LEN];
char h_exch_code[4];
char h_contract_cd[17];
char  h_r_delay[2];
char  h_sebi_reported[2];
char  h_r_sett_code[2];
char  h_r_trans_code[3];
char  h_r_type[3];
char  h_repo_date[APL_DATE_LEN];
double h_comm_amt;
char h_mf_seqno[6];
char h_rev_leg_date[20];
/*Retro from HDFC by Ekta for Interoperability Starts*/
char h_trd_exch[4]; 
char h_trd_setl_no[16];
char h_trd_mkt_type[4];
/*Retro from HDFC by Ekta for Interoperability Ends*/
/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
double h_stamp_duty;
/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
} SYS_DL_DEAL_REV_STRUCT_H;
/** SLB Reversal HB_03_001 ENDS **/

typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_locindentity_no[17];
char h_brkrno[13];
char h_clt_reqdel_flag[2];
char h_access_stamp[20];
char h_dealcd[2];
char h_dlt[20];
char h_setldt[20];
char h_classofdl[3];
char h_lrdltype[3];
double h_amt;
double h_pr;
char h_domcpclt_cd[11];
char h_custinfo[71];
char h_lr_ndsdate[20];
} DL_DEAL_OTH_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_confdate[20];
char h_verfied_with[26];
double h_diffamount;
char h_info1[261];
char h_ispart_[2];
char h_brkrno[13];
double h_newquantity;
double h_newamount;
char h_newindentity_no[17];
char h_newlocindentity_no[17];
char h_access_stamp[20];
double h_grossamount;
double h_cpamt;
char h_comm_indentity_no[17];
char h_exp_setl_date[20];
} DL_DEAL_PMTDET_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_dlt[20];
char h_setldt[20];
double h_pr;
double h_amt;
char h_domcp_custodyclt[11];
char h_countclt[16];
char h_countcltnm[66];
char h_cust_chgind[2];
char h_access_stamp[20];
} DL_DEAL_PMTCHG_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_ndsdate[20];
char h_access_stamp[20];
} DL_DEAL_NDS_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_ispart_[2];
double h_newquantity;
double h_newamount;
char h_newindentity_no[17];
char h_instrdate[20];
char h_moneydate[20];
double h_pr;
double h_brokercomm;
char h_sel_forreg[2];
double h_pendregquantity;
double h_marktrfquantity;
double h_rec_int_000;
double h_mcomplquantity;
double h_delta_000;
double h_delta_001;
double h_delta_002;
char h_access_stamp[20];
} DL_DEAL_SSTDET_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
int h_srl_no;
char h_reg_st_cd[2];
char h_txndate[20];
double h_qty;
char h_access_stamp[20];
double h_quantitymoved;
double h_quantitymanifld;
char h_dtcltfor[20];
char h_prcsmrdate[20];
char h_status_prc[2];
char h_prcstldate[20];
double h_smramount;
} DL_REGDET_STRUCT_H;
typedef struct  {
int h_element_cnt;
int *h_srl_no;
double *h_qty;
char *h_access_stamp;
} REQDETAILS_STRUCT_H;
typedef struct  {
int h_noelements_cltt_arr;
char h_frm_instr_code[9];
char h_to_instrurity[9];
char *h_cltt_arr;
} DL_INSTRUMENTCONV_OTH_STRUCT_H;
typedef struct  {
char h_prdt[20];
char h_instr_code[9];
double h_closing_pr;
char h_updtmode[2];
char h_access_stamp[20];
char h_maker[15];
char h_maker_dt[20];
char h_mkrtpr_stat[3];
char h_checker[15];
char h_checker_dt[20];
} MT_DLYMKTPRC_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_domcpclt_cd[11];
char h_dealcd[2];
char h_setldt[20];
double h_qty;
char h_instr_code[9];
double h_amt;
double h_pr;
char h_newdt[20];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_countcltnm[66];
char h_misdeal_status[3];
char h_countclt[11];
char h_maker[15];
char h_info[351];
char h_place_of_deal[5];
char h_market_flag[5];
char h_description[31];
char h_dealdt[20];
char h_clientofcode[11];
char h_clientof[66];
char h_instruct_person[11];
char h_instruct_personnm[66];
char h_deal_class[6];
char h_trrf_ident[17];
char h_comm_ident[17];
char h_pool_ident[17];
char h_send_msg_ind;
char h_party_con[141];
char h_uniq_ident_no[12];
int h_proc_num;
char h_nameof_file[31];
char h_dsn_ident[12];
} DL_MISDEAL_STRUCT_H;
typedef struct  {
char h_oldinstr_code[9];
char h_newinstr_code[9];
char h_newinstr_isincode[13];
char h_listed_ind[2];
char h_access_stamp[20];
} DL_INSTRUMENTCHG_STRUCT2_H;
typedef struct  {
char h_dl_client[11];
char h_orderindentity_no[17];
char h_buy_sell_flag[2];
char h_orderdate[20];
double h_orderquantity;
char h_limit_ind[2];
char h_isgte_ind[2];
char h_all_none_ind[2];
char h_ex_arena[3];
char h_ord_stat[3];
char h_instr_code[9];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_expirydate[20];
double h_limitpr;
char h_canceleddate[20];
double h_execquantity;
char h_candropdate[20];
char h_broker_cd[11];
char h_locindentity_no[17];
char h_lrdltype[3];
char h_lr_chkdate[20];
char h_lr_ublckdate[20];
char h_ublckdate[20];
char h_lastexecdate[20];
char h_lastdeal[17];
} OR_ORDERDETAILS_STRUCT_H;
typedef struct  {
int h_element_cnt;
char h_access_stamp[20];
double *h_qty;
double *h_pr;
double *h_brokercomm;
} ORDERDETAILS_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_orderindentity_no[17];
char h_dlt[20];
char h_setldt[20];
char h_classofdl[3];
char h_gen_fxadv_ind[2];
char h_loccode[5];
char h_isspotdl[2];
char h_domcpclt_cd[11];
char h_dealcd[2];
char h_tax_amount[2];
char h_ispymtlocal[2];
char h_pos_stat[4];
char h_confdate[20];
char h_ex_arena[3];
double h_stex_comm;
double h_oth_comm;
double h_qty;
double h_brokercomm;
double h_amt;
double h_pr;
char h_brkrno[13];
} DEAL_EXECDET_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_sequenceno[17];
char h_instr_code[9];
char h_dlt[20];
char h_setldt[20];
char h_infos[261];
char h_frm_loc[5];
char h_to_location[5];
char h_sendmsg_ind[2];
char h_billable_flag[2];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_newdt[20];
double h_qty;
char h_df_txnr_iden[17];
char h_rf_dl_ident[17];
char h_dealstat[3];
char h_loc_chng_stat[3];
char h_access_stamp[20];
char h_setl[2];
char h_uniq_ident_no[12];
char h_dfsettdate[20];
char h_rfsettdate[20];
char h_frm_type[2];
char h_to_type[2];
char h_change[2];
char h_unblock_date[20];
char h_trans_type[10]; 
} DL_LOCNCHG_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_blck_no[3];
char h_stat_qual[5];
char h_stat_reas[7];
char h_failreas_qual[7];
char h_failreas_cd[5];
char h_info[36];
char h_fail_cd[3];
int h_subfailreas_cd;
char h_access_stamp[20];
} DL_MULT_REAS_CODES_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_instr_code[9];
char h_loccode[5];
double h_qty;
char h_locindentity_no_rf[17];
char h_locindentity_no_df[17];
} REG_TRF_STRUCT_H;


/****************************************************************************************************/

typedef struct
{
	char h_account[11];
	char h_ref_no[17];
	char h_secode[9];
	char h_msg_no[7];
	char h_received_on[20];
	char h_msg_func[36];
	char h_mis_info[201];
	char h_file_name[71];
	char h_failure_reason[4001];
	char h_rep_flg[2];
	char h_msgsts[4];
	char h_rec_from_sent_to[51];
	char h_msg_refno[36];
	char h_in_out[2];
	char h_trd_ca[2];
	char h_event_type[3];
	char h_ca_id[21];
}DF_COMMON_MSGRPT_STRUCT_H;

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
	/*********** New Fields Added by sundar - 090506************/
	char h_exch_code[4];      
	char 	h_mkt_type[4];
	char	h_interfii_flg[2];
	char	h_clh_flg[2];
	char	h_settlement_no[16];
	char 	h_payin_dt[APL_DATE_LEN];
	char	h_payout_dt[APL_DATE_LEN];
	double h_net_amt;
	/*********** New Fields Added by sundar - 090506************/
	/*Retro from HDFC by Ekta for Interoperability Starts*/
	char h_trd_exch[4]; 
	char h_trd_setl_no[16];
	char h_trd_mkt_type[4];
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	double h_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
   char h_dpm_trans_ref_no[17];
   double h_other_charges;
   char h_csgl_trade_type[21];
}DL_DEALREPAIR_STRUCT_H;
/**********************************************************************************************/

/* BCN - HDFCDL_004 - Sundar */

typedef struct  {
	char h_contract_cd[DL_CONTRACT_CD_LEN];
	char h_mkt_type[DL_MKT_TYPE_LEN];
	char h_tran_type[5];
	char h_dl_date[APL_DATE_LEN];
	double h_dl_price;
	double h_brokercomm;
	char h_exch_cd[DL_EXCH_CD_LEN];
	char h_deal_cd[DL_DEAL_CD_LEN];
	char h_clh_flg[DL_CLH_FLG_LEN];
	char h_sebi_reg_no[DL_SEBI_REG_NO_LEN];
	char h_broker_cd[DL_BROKER_CD_LEN];
	char h_client_cd[DL_CLIENT_CD_LEN];
	double h_qty;
	char h_instr_cd[DL_INSTR_CD_LEN];
	char h_settlement_no[DL_SETTLEMENT_NO_LEN];
	double h_dl_amt;
	double h_brokerage_amt;
	double h_stt_amt;
	double h_settlment_amt;
	char h_dl_ref_no[DL_DL_REF_NO_LEN];
	char h_inter_fii_flg[DL_INTER_FII_FLG_LEN];
	char h_sebi_reported[DL_SEBI_REPORTED_LEN];
	char h_entry[DL_ENTRY_LEN];
	char h_repaired_ind[DL_REPAIRED_IND_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
	char h_sett_dt[APL_DATE_LEN];
	char h_narrative[DL_NARRATIVE_LEN];
	char h_off_market[2];
	char h_counter_pty[11];
	char h_r_trans_code[3];
	char h_r_sett_code[2];
	char h_r_delay[2];
	char h_r_type[3];
	char h_repo_date[APL_DATE_LEN];
	char h_ammend_dt[APL_DATE_LEN];
/*Abhijeet Added 2 new Fields For Fail Code -HDFCDL_004*/
	char h_failreason_cd[3];
	int h_sub_fail_cd;	
	/* Kouser - Added 1 field For RegReport - HDFCMT_OO4 */
	char h_lr_valdate[APL_DATE_LEN];
	/*Vedavati Added 2 fields for 548 Message*/
	char h_addr_frm[17];
	char h_addr_to[17];
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	double h_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
}DL_BCN_STRUCT_H;

typedef struct{
	char h_client[DL_CLIENT_LEN];
	char h_identiy_no[DL_IDENTIY_NO_LEN];
	double h_qty;
	char h_dp_id[DL_DP_ID_LEN];
	char h_access_stamp[APL_DATE_LEN];
}DL_BIFDET_STRUCT_H;


/**************ADDED BY AMISH***************/
/**********TAKE OVER*********************/
typedef struct{
	char h_ref_no[17];
	char h_ci_no[17];
	char h_instr_cd[9];
	double h_qty;
	char h_phy_flg[2];
	double h_takeover_qty;
	char h_depository[11];
	char h_status[3];
	char h_maker[DL_MAKER_LEN];   /* changes by amish --10/05 */
	char h_makerdt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checkerdt[APL_DATE_LEN];
	char h_accesstamp[APL_DATE_LEN];/* changes end */
	char h_comments[80];
	char h_serial_no[9];
}DL_TAKEOVER_STRUCT_H;

typedef struct
{
	char h_takeover_date[20];
	char h_cln_code[11];
//	char h_ref_no[16]; updated the size to 17 by siva.ganapathi for ISKB_3636
	char h_ref_no[17];
	char h_takeover_comments[81];
}DL_TAKEOVER_SEQ_STRUCT_H;	
/*************MARK SHORTAGE*************/

typedef struct{
	char h_settlement_no[16];
	char h_dl_client[11];
	char h_dl_ref_no[17];
	char h_instr_code[9];
	double h_qty;
	double h_avail_qty;
	double h_allot_qty;
	double h_shortage_qty;
	char h_pool_trans[2];
	char h_status[3];
	char h_access_stamp[20];
	char h_checker[DL_CHECKER_LEN]; /* CHANGES BY AMISH --16/05 */
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_depo_cd[9]; /* change by amish -24/05 */
	char h_dp_id[21];
	int h_filebatch_no;/* change by amish -25/05 */
	char h_mkt_type[DL_MKT_TYPE_LEN]; //T1 Settlement changes CS0083803
	char h_exch_code[DL_EXCH_CODE_LEN]; //T1 Settlement changes CS0083803
}DL_MARKSHORTAGE_STRUCT_H;



/*************SQARE OFF*************************/
typedef struct{
	char h_exch_code[DL_EXCH_CODE_LEN];
	char h_settlemt_no[DL_SETTLEMT_NO_LEN];
	char h_payin_dt[APL_DATE_LEN];
	char h_payout_dt[APL_DATE_LEN];
	char h_dl_ref_no[DL_DL_REF_NO_LEN];
	char h_cln_code[DL_CLN_CODE_LEN];
	char h_sqoff_ref_no[DL_SQOFF_REF_NO_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	double h_deal_qty;
	double h_bal_qty;
	double h_sqoff_qty;
	double h_sqoff_amt;
	char h_bank_code[DL_BANK_CODE_LEN];
	char h_chq_no[DL_CHQ_NO_LEN];
	char h_chq_dt[APL_DATE_LEN];
	double h_prn_amt;
	char h_ca_ref_no[DL_CA_REF_NO_LEN];
	double h_ca_amt;
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
	char h_deal_cd[2]; /* change by amish -24/05 */
}DL_SQOFF_STRUCT_H;

/*********ADDED BY AMISH************************/
/**********MARK SHORTAGE************************/

/***************Pool Account Dump Maintenance - Sundar ***********************************/
typedef struct{
	int h_seq_no;
	int h_filebatch_no;
	char h_benef_acctype[DL_BENEF_ACCTYPE_LEN];
	double h_qty;
	char h_mkt_type[DL_MKT_TYPE_LEN];
	char h_settlemt_no[DL_SETTLEMT_NO_LEN];
	char h_bl_lc_code[DL_BL_LC_CODE_LEN];
	char h_icrel_date[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_depo_code[9];
	char h_exch_code[4];
	char h_dp_id[20];
}DL_POOLACCDMP_STRUCT_H;

/***************Pool Account Dump Maintenance - vinay ***********************************/
typedef struct{
	char h_file_name[101];
	char h_upld_date[APL_DATE_LEN];
	int h_batch_no;
	char h_f_code[5];
	int h_filelinkinfo;/** 17-05-2006 ** vinay kalaskar **/
}POOLACDET_STRUCT_H;
/****************************************************************************************/

/***************Pool Account Dump Maintenance - Sundar ***********************************/
extern int wrp_DL_MarkShortage(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_MARKSHORTAGE_STRUCT_H *p_dl_markshortage_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/**************TAKE OVER*****************/
int (*wrp_DL_Proc_TKOVER)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_TAKEOVER_STRUCT_H *l_dl_takeover_struct_h,
	 DL_TAKEOVER_SEQ_STRUCT_H *l_dl_takeover_seq_struct_h,
     char *p_stregno,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

typedef struct{
	char h_order_no[DL_ORDER_NO_LEN];
	char h_exchg_code[DL_EXCHG_CODE_LEN];
	char h_cln_code[DL_CLN_CODE_LEN];
	char h_instr_code[DL_INSTR_CODE_LEN];
	char h_broker_cd[DL_BROKER_CD_LEN];
	double h_qty;
	char h_settl_no[DL_SETTL_NO_LEN];
	double h_dl_price;
	double h_dl_amt;
	char h_deal_date[APL_DATE_LEN];
	char h_mkt_type[DL_MKT_TYPE_LEN];
	char h_scrip_grp[DL_SCRIP_GRP_LEN];
	char h_creation_type[DL_CREATION_TYPE_LEN];
	char h_deal_ref_no[DL_DEAL_REF_NO_LEN];
	char h_buy_sell_flg[DL_BUY_SELL_FLG_LEN];
	char h_matched[DL_MATCHED_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	int  h_filelinkinfo;
	int  h_rowsequence;
	char h_is_nodelv[DL_IS_NODELV_LEN];/* For no delivery Process By: vinay */
	char h_nodelv_repdate[APL_DATE_LEN];/* For no delivery Process By: vinay */
	char h_order_data[DL_ORDER_DATA_LEN];/* For no delivery Process By: vinay */
	char h_exch_instr_code[DL_EXCH_INSTR_CODE_LEN];/*For Exchange Instrument Code: Rahul */
	char h_cp_code [21];  /* Chages by rahul6 for T0 Enhancement */
}DL_EXCHGORD_UPLD_STRUCT_H;

typedef struct{
	char h_dealfield[31];
	char h_comp_field[31];
	char h_apltol[2];
	int h_lmt;
	char h_exchng[4];
	char h_usefield[2];
	char h_proc_ind[2];
	char h_failreason_cd[3];
	int h_sub_fail_cd;

}MATCHING_MASTER_STRUCT_H;

typedef struct{
char h_client[13];
char h_exch_code[4];
char h_settlement_no[16];
char h_mkt_type[4];
char h_instr_code[9];
char h_brk_no[13];
char h_deal_cd[2];
char h_deal_date[20];
char h_identiy_no[17];
double h_brokercomm;
}DL_DEAL_BRKG_STRUCT_H;

typedef struct{
	char h_client[11];
	char h_identiy_no[17];
	char h_deal_date[20];
	double h_cost;
	char h_exch_code[4];
	double h_amount;
	double h_brokercomm;
	double h_stx_comm;
	double h_purchase;
	double h_sale;
	double h_net_amt;
	double h_qty;
	char h_brk_no[13];
	char h_deal_cd[2];
	char h_instr_code[9];
	char h_settlement_no[16];
	char h_mkt_type[4];
	char h_payable_acc[31];
	char h_start_date[20];
	char h_end_date[20];
	char h_pay_out_dt[20];
	char h_pay_in_dt[20];
	char h_cln_name[66];
	char h_cln_add_1[61];
	char h_cln_add_2[61];
	char h_cln_add_pin[11];
	char h_city[21];
	double h_stamp_duty;/* SNOW- CS0046501 Changes by Shradha for Stamp Duty Enh.*/
}SYS_DL_FUNDOBL_STRUCT_H;

typedef struct{
	char h_client[13];
	char h_identiy_no[17];
	char h_deal_date[20];
	double h_cost;
	char h_exch_code[4];
	double h_amount;
	double h_brokercomm;
	double h_stx_comm;
	double h_qty;
	char h_brk_no[13];
	char h_brk_name[66];
	char h_deal_cd[2];
	char h_instr_code[9];
	char h_settlement_no[16];
	char h_mkt_type[4];
	char h_deal_link_no[21];
	char h_oblg_type[3];
	char h_acc_ent_ind[2];
	double h_net_amt;
	char h_clh_flg[DL_CLH_FLG_LEN];
}DL_OBLG_ACC_ENT_STRUCT_H;

/* HDFCDL_015 Wrapper function of dl_sqoff - sundar */

typedef struct{
	char h_dl_client[DL_DL_CLIENT_LEN];
	char h_dl_ref_no[DL_DL_REF_NO_LEN];
	char h_broker_dpid[DL_BROKER_DPID_LEN];
	char h_broker_cmbpid[DL_BROKER_CMBPID_LEN];
	char h_cp_dpid[DL_CP_DPID_LEN];
	char h_cp_clnid[DL_CP_CLNID_LEN];
	char h_gendp_flg[DL_GENDP_FLG_LEN];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_mkt_type[4];
	double h_qty;
	char h_exec_dt[APL_DATE_LEN];
	char h_client_id[21];
	char h_dp_id[21];
	char h_dpgend;
}DL_DPGEN_DET_STRUCT_H;

/*Code Added by Amol*/
typedef struct{
	char h_obgdaybuyvol[16];
	char h_obgdaysalvol[16];
	char h_obgdaybuyamt[22];
	char h_obgdaysalamt[22];
	char h_obgcumbuyvol[16];
	char h_obgcumsalvol[16];
	char h_obgcumbuyamt[22];
	char h_obgcumsalamt[22];
	char h_obgsetlno[8];
	char h_obgtmbrncode[3];
	char h_obgdate[9];
	char h_obgcupcode[13];
	char h_obgsecsymbol[11];
	char h_obgsecseries[3];
	char h_obgseccode[7];
	char h_obgtmcode[6];
	char h_obgcuscode[6];
	char h_obgsetltype[4];
	char h_obgndflag[2];
	char h_obgfnlobg[2];
}DL_NSC_OBL_STRUCT_H;

typedef struct{

	int h_system_seq_no;
	char h_file_batch_no[6];
	char h_instr_code[9];
	char h_benefactyp[7];
	int h_benef_accposn;
	char h_mkt_type[3];
	char h_settlemt_no[16];
	char h_bl_lc_code[7];
	char h_depo_code[9];
	char h_maker[DL_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[DL_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[DL_STATUS_LEN];
}DL_POOLACCRECS_STRUCT_H;

typedef struct{
   char h_transfer_ref_no[DL_TRANSFER_REF_NO_LEN];
   char h_from_client[DL_FROM_CLIENT_LEN];
   char h_to_client[DL_TO_CLIENT_LEN];
   char h_custody_internal[DL_CUSTODY_INTERNAL_LEN];
   char h_cp_custo[DL_CP_CUSTO_LEN];
   char h_cp_dp_id[DL_CP_DP_ID_LEN];
   char h_cp_client_id[DL_CP_CLIENT_ID_LEN];
   char h_status[DL_STATUS_LEN];
   char h_maker[DL_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_checker[DL_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
}DL_INTR_SCH_STRUCT_H;

typedef struct{
   char h_transfer_ref_no[DL_TRANSFER_REF_NO_LEN];
   char h_instr_code[DL_INSTR_CODE_LEN];
   char h_depo_code[DL_DEPO_CODE_LEN];
   double h_qty;
   double h_bal_qty;
   char h_transfer_dt[APL_DATE_LEN];
   char h_status[DL_STATUS_LEN];
   char h_maker[DL_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_checker[DL_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
}DL_INTR_SCH_DET_STRUCT_H;


typedef struct{
   char h_blk_ref_no[DL_BLK_REF_NO_LEN];
   char h_client[DL_CLIENT_LEN];
   char h_remarks[DL_REMARKS_LEN];
   char h_status[DL_STATUS_LEN];
   char h_maker[DL_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_checker[DL_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
}DL_BLK_SEC_STRUCT_H;

typedef struct{
   char h_blk_ref_no[DL_BLK_REF_NO_LEN];
   char h_instr_code[DL_INSTR_CODE_LEN];
   char h_depo_code[DL_DEPO_CODE_LEN];
   char h_blk_date[APL_DATE_LEN];
   char h_blk_type[DL_BLK_TYPE_LEN];
   double h_qty;
   double h_bal_qty;
   char h_un_blk_date[APL_DATE_LEN];
   double h_un_blk_qty;
   char h_custo_ref_no[DL_CUSTO_REF_NO_LEN];
   char h_status[DL_STATUS_LEN];
   char h_maker[DL_MAKER_LEN];
   char h_maker_dt[APL_DATE_LEN];
   char h_access_stamp[APL_DATE_LEN];
   char h_checker[DL_CHECKER_LEN];
   char h_checker_dt[APL_DATE_LEN];
}DL_BLK_SEC_DET_STRUCT_H;


typedef struct{
	  char h_settlement_no[16];
	  char h_instr_cd[9];
	  double h_aggr_qty;
	  double h_agg_amt;
	  char h_mkt_type[4];
	  char h_deal_cd[2];
	  char h_deal_dt[APL_DATE_LEN];
	  char h_status[DL_STATUS_LEN];
	  char h_exch_code[4];
	 }DL_EXCHOBLIGATION_STRUCT_H;

	 typedef struct{
		  char h_settlement_no[16];
		  char h_instr_cd[9];
		  char h_deal_cd[2];
		  char h_status[DL_STATUS_LEN];
		  char h_failcode[3];
		  char h_comments[501];
		  char h_mkt_type[4];
		  char h_exch_code[4];
		 }DL_EXCHRECON_RPT_STRUCT_H;

	typedef struct{
		char     h_batch_no[APL_DP_BATCH_NO_LEN];
		/* char  h_serial_no[6]; ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
		char     h_serial_no[7];
		char     h_trans_flg[2];
		char     h_internal_ref_no[21];
		char     h_trans_type[4];
		/* int   h_dpm_trans_no; ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
		long     h_dpm_trans_no;
	}DL_UPDDPINST_STRUCT_H;

	typedef struct{
		int       h_record_type;
		char      h_branch_cd[7];
		int       h_line_no;
		char      h_trans_type[4];
		/* int    h_dpm_transaction_no; ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
		long      h_dpm_transaction_no;
		int       h_ord_stat_from;
		int       h_ord_stat_to;
		char      h_stat_chng_user[9];
		int       h_cancel_stat_from;
		int       h_cancel_stat_to;
		char      h_stat_chng_dt[21];
		char      h_client_cd[9];
		char      h_isin[13];
		double    h_qty;
		char      h_mkt_type[4];
		char      h_settlement_no[16];
		char      h_exec_dt[21];
		char      h_other_dpid[9];
		char      h_other_client[9];
		char      h_benf_acc_ctgry[3];
		char      h_other_cmbp_id[9];
		/* char   h_internal_ref_no[21]; ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
		char      h_internal_ref_no[36]; 
	}DL_INST_COD_STRUCT_H;

/*Code Added by Amol 03082006*/
typedef struct{
	char h_instr_code[9];
	char h_buy_qty[10];
	char h_buy_val[12];
	char h_sell_qty[10];
	char h_sell_val[12];
	char h_net_qty[11];
	char h_net_val[13];
	char h_std_rate[9];
	char h_net_std_diff[13];
	char h_std_rate_diff[13];
	char h_net_amt[13];
	char h_cfqty[11];
	char h_calldivflag[2];
	char h_calldivamt[9];
	char h_bank_qty[11];
	char h_bank_val[13];
	char h_settlement_no[16];
	char h_mkt_type[4];
	char h_deal_dt[9];
}DL_BSE_OBL_STRUCT_H;

/*Code Added by Amol 15092006*/
typedef struct{
	 char h_rec_type[3];
	 char h_line_no[10];
	 char h_branch_cd[7];
	 char h_ben_acc_no[9];
	 char h_ben_cat[3];
	 char h_isin[13];
	 char h_ben_acc_type[3];
	 /* char h_ben_acc_pos[16];  ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
	 char h_ben_acc_pos[19]; /* Increased the length as per the revised NSDL file format */
	 char h_cc_id[9];
	 char h_mkt_type[3];
	 char h_setl_no[8];
	 char h_blflag[2];
	 char h_blcode[3];
	 char h_lock_rel_date[9];
	 char h_filler[17];		 
	 char h_dp_id[5];
	 char h_upl_date[APL_DATE_LEN];
	 char h_status[DL_STATUS_LEN];
	 char h_comments[501];
}DL_UPL_SOH_STRUCT_H;

/*Code Added by Amol 30102006*/
typedef struct{
	 char h_instr_code[9];
	 char h_posit_date[APL_DATE_LEN];
	 char h_location_cd[5];
	 char h_client[11];
	 char h_status[DL_STATUS_LEN];
	 double h_start_safek;
	 double h_safekeep_pos;
	 double h_nvalreceive;
	 double h_nvaldeliver;
	 double h_val_rec;
	 double h_val_del;
	 double h_dp_rec;
	 double h_dp_del;
	 char h_block_type[5];
}HISSAFEK_STRUCT_H;

/*Code Added by Amol 21112006*/
typedef struct{
	 char h_line_ind[3];
	 char h_dp_id[9];
	 char h_client_cd[9];
	 char h_upl_date[APL_DATE_LEN];
	 char h_status[DL_STATUS_LEN];
}CDSL_UPL_A_STRUCT_H;

/*Code Added by Amol 21112006*/
typedef struct{
	 char h_line_ind[3];
	 char h_isin[13];
	 char h_cur_bal[23];
	 char h_free_bal[23];
	 char h_emark_bal[23];
	 char h_pledge_bal[23];
	 char h_remat_pend[23];
	 char h_isin_name[21];
	 char h_isin_desc[101];
	 char h_issuer_name[101];
	 char h_issuer_add1[31];
	 char h_issuer_add2[31];
	 char h_issuer_add3[31];
	 char h_issuer_city[26];
	 char h_issuer_state[26];
	char h_pin_cd[26];
	 char h_upl_date[APL_DATE_LEN];
}CDSL_UPL_B_STRUCT_H;

/*Code Added by Amol 21112006*/
typedef struct{
	 char h_client[11];
	 char h_instr_code[9];
	 char h_qty[23];
	 char h_upl_date[APL_DATE_LEN];
	 char h_status[DL_STATUS_LEN];
	 char h_dp_id[5];
	 char h_block_type[5];
}DL_HOLD_UPL_STRUCT_H;

/***** JC - ISKB 487 -- Start *****/
typedef struct  {
char h_dl_client[MT_CLN_CODE_LEN];
char h_identiy_no[DL_IDENTIY_NO_LEN];
double h_price;
double h_amt;
double h_net_amt;
double h_qty;
char h_maker[DL_MAKER_LEN];
char h_maker_dt[20];
char h_status[DL_STATUS_LEN];
char h_access_stamp[20];
char h_checker[DL_CHECKER_LEN];
char h_checker_dt[20];
} DL_DEAL_DECI_ADJ_STRUCT_H;
/***** JC - ISKB 487 -- End *****/

/* Following Added For Host Array Changes - 12052015 - Priyanka B. - Start */

typedef struct{
        char h_client[HASIZE][13];
        char h_identiy_no[HASIZE][17];
        char h_deal_date[HASIZE][20];
        double h_cost[HASIZE];
        char h_exch_code[HASIZE][4];
        double h_amount[HASIZE];
        double h_brokercomm[HASIZE];
        double h_stx_comm[HASIZE];
        double h_qty[HASIZE];
        char h_brk_no[HASIZE][13];
        char h_brk_name[HASIZE][66];
        char h_deal_cd[HASIZE][2];
        char h_instr_code[HASIZE][9];
        char h_settlement_no[HASIZE][16];
        char h_mkt_type[HASIZE][4];
        char h_deal_link_no[HASIZE][21];
        char h_oblg_type[HASIZE][3];
        char h_acc_ent_ind[HASIZE][2];
        double h_net_amt[HASIZE];
        char h_clh_flg[HASIZE][DL_CLH_FLG_LEN];
        char hvDealClass[HASIZE][3];
        char hvExArena[HASIZE][3];
        double h_payin_day[HASIZE];
        double h_payout_day[HASIZE];
		double h_stamp_duty[HASIZE];
     //Added by Azhar K. for API NRI Accounting Entries - START
	char h_deal_stat[HASIZE][3];
	char h_instrdate[HASIZE][20];
	char h_moneydate[HASIZE][20];
	double h_pendregquantity[HASIZE];
	double h_marktrfquantity[HASIZE];
	double h_rec_int_000[HASIZE];
	double h_mcomplquantity[HASIZE];
	double h_delta_000[HASIZE];
	double h_delta_001[HASIZE];
	double h_delta_002[HASIZE];
	char h_access_stamp[HASIZE][20];
	char h_cln_type[HASIZE][2];
     //Added by Azhar K. for API NRI Accounting Entries - END
}DL_OBLG_ACC_ENT_HSTRUCT_H;

typedef struct{
short i_client[HASIZE];
short i_identiy_no[HASIZE];
short i_deal_date[HASIZE];
short i_cost[HASIZE];
short i_exch_code[HASIZE];
short i_amount[HASIZE];
short i_brokercomm[HASIZE];
short i_stx_comm[HASIZE];
short i_qty[HASIZE];
short i_brk_no[HASIZE];
short i_brk_name[HASIZE];
short i_deal_cd[HASIZE];
short i_instr_code[HASIZE];
short i_settlement_no[HASIZE];
short i_mkt_type[HASIZE];
short i_deal_link_no[HASIZE];
short i_oblg_type[HASIZE];
short i_acc_ent_ind[HASIZE];
short i_net_amt[HASIZE];
short i_clh_flg[HASIZE];
short i_DealClass[HASIZE];
short i_ExArena[HASIZE];
short i_payin_day[HASIZE];
short i_payout_day[HASIZE];
short i_stamp_duty[HASIZE];
//Added by Azhar K. for API NRI Accounting Entries - START
short i_deal_stat[HASIZE];
short i_instrdate[HASIZE];
short i_moneydate[HASIZE];
short i_pendregquantity[HASIZE];
short i_marktrfquantity[HASIZE];
short i_rec_int_000[HASIZE];
short i_mcomplquantity[HASIZE];
short i_delta_000[HASIZE];
short i_delta_001[HASIZE];
short i_delta_002[HASIZE];
short i_access_stamp[HASIZE];
short i_cln_type[HASIZE];
//Added by Azhar K. for API NRI Accounting Entries - END
}DL_OBLG_ACC_ENT_HSTRUCT_I;


/* Following Added For Host Array Changes - 12052015 - Priyanka B. - End */

int (*wrp_DLUpdSqOffFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		DL_SQOFF_STRUCT_H *p_dl_sqoff_struct_h,
		char *p_stregno,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);


extern int wrp_CDBUpdTrdFailFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_FAIL_STRUCT_H *p_dl_deal_fail_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_GBGenTrdFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_a,
     int *int_p_trdrepseqnum,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdTrdOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdPmtDetFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdPMTChgFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTCHG_STRUCT_H *p_dl_deal_pmtchg_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdNdsFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_NDS_STRUCT_H *p_dl_deal_nds_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdSSTDetFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
     char *p_event_id_str,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CRUDBUpdSSTDetFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
     char *p_ruevent_id_str,
     char *p_srn_param_str,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBRstPmTFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_client,
     char *p_indentity_no,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBRstSStFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_client,
     char *p_indentity_no,
     char *chr_p_action,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdRegnFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_REGDET_STRUCT_H *p_dl_regdet_struct_h,
     REQDETAILS_STRUCT_H *p_reqdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBRstRegnFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_REGDET_STRUCT_H *p_dl_regdet_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBInpInstrConvFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdMktPrcFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdMisFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h,
     char cmistxnident[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBInstrChgCdFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_INSTRUMENTCHG_STRUCT2_H *l_dl_instrumentchg_struct2_ha,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdOrdFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b,
     char p_orderident[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBRstOrdExecFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_dealident,
     char *p_deal_access_stamp,
     char *p_ord_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdOrdtFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_b,
     ORDERDETAILS_STRUCT_H *p_orderdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdLocChgFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h,
     char cseqno[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBRstClhSFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *chr_p_refno,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBDoRegnFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     REG_TRF_STRUCT_H *p_reg_trf_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CRUDBUpdPmtDetFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
     char *p_stregno,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct core_trade_v1_0_epv_t {
int (*wrp_CDBUpdTrdFailFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_FAIL_STRUCT_H *p_dl_deal_fail_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_GBGenTrdFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_a,
     int *int_p_trdrepseqnum,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdTrdOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdPmtDetFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdPMTChgFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTCHG_STRUCT_H *p_dl_deal_pmtchg_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdNdsFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_NDS_STRUCT_H *p_dl_deal_nds_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdSSTDetFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
     char *p_event_id_str,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CRUDBUpdSSTDetFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
     char *p_ruevent_id_str,
     char *p_srn_param_str,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBRstPmTFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_client,
     char *p_indentity_no,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBRstSStFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_client,
     char *p_indentity_no,
     char *chr_p_action,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdRegnFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_REGDET_STRUCT_H *p_dl_regdet_struct_h,
     REQDETAILS_STRUCT_H *p_reqdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBRstRegnFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_REGDET_STRUCT_H *p_dl_regdet_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBInpInstrConvFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdMktPrcFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdMisFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h,
     char cmistxnident[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBInstrChgCdFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_INSTRUMENTCHG_STRUCT2_H *l_dl_instrumentchg_struct2_ha,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdOrdFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b,
     char p_orderident[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBRstOrdExecFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_dealident,
     char *p_deal_access_stamp,
     char *p_ord_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdOrdtFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_b,
     ORDERDETAILS_STRUCT_H *p_orderdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdLocChgFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h,
     char cseqno[17],
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBRstClhSFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *chr_p_refno,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_MTUpdIntrScheFn)(
#ifdef IDL_PROTOTYPES
      handle_t IDL_handle,
      DL_INTR_SCH_STRUCT_H *p_dl_intr_sch_struct_h,
      char *p_transfer_no,
      INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
      DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
      );

int (*wrp_MTUpdIntrScheDetFn)(
#ifdef IDL_PROTOTYPES
      handle_t IDL_handle,
      DL_INTR_SCH_DET_STRUCT_H *p_dl_intr_sch_det_struct_h,
      char *p_access_stamp,
      INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
      DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_CBDoRegnFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     REG_TRF_STRUCT_H *p_reg_trf_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CRUDBUpdPmtDetFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
     char *p_stregno,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_HDFCDLBifDetFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		DL_BIFDET_STRUCT_H *p_dl_bifdet_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_DLUpdBCNFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		DL_BCN_STRUCT_H *p_dl_bcn_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_HDFCPoolAccDumpFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		DL_POOLACCDMP_STRUCT_H *p_dl_poolaccdmp_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
} core_trade_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
