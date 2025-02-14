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
 * Module Name         :	
 *
 * File Name           :
 *
 * Description         :	
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *					
 *
 *********************************************************************/












 
#include "CR_Common.h"
#include "CR_Header_D.h"
#include "CR_Header_A.h"
#include "CR_Header_E.h"
#include "DL_Interface.h"
#include "MT_Interface.h" 



typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_securitycd[9];
	char	h_loccode[5];
	char	h_st_reg_no[21];
	double	h_qty;
	double	h_amt;
	char	h_dealcd[2];
	char	h_deal_dt[20];
	char	h_secdate[20];
}DEAL_RU_STRUCT_H;
typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_securitycd[9];
	char	h_ctclt[4];
	char	h_dbclt[4];
	char	h_domcpclt_cd[11];
	double	h_qty;
	int	h_dtfld;
	int	h_r_code;
	char	h_ord_ind[2];
	char	h_lrdltype[3];
	char	h_dealcd[2];
	char	h_reset_ind[2];
} DL_LOCALREPPROC_STRUCT_H;




/*
typedef struct {
	int	h_dlrep_sequencenum;
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_dealcd[2];
	char	h_dlt[20];
	char	h_setldt[20];
	double	h_qty;
	char	h_securitycd[9];
	char	h_currencycode[4];
	char	h_domcpclt_cd[11];
	char	h_classofdl[3];
	double	h_pr;
	char	h_ex_arena[3];
	char	h_isspotdl[2];
	char	h_entry[2];
	char	h_newdt[20];
	char	h_creater[15];
	char	h_create_dt[20];
	char	h_deal_status[3];
	char	h_timestamp[20];
	double	h_amt;
	char	h_domcp_custodyclt[11];
	char	h_countclt[16];
	char	h_countcltnm[66];
	char	h_clientof[66];
	char	h_info1[261];
	char	h_fx_reqd[2];
	double	h_custodycomm;
	double	h_brokercomm;
	double	h_stex_comm;
	double	h_oth_comm;
	char	h_loccode[5];
	char	h_pos_stat[4];
	char	h_secdetail[121];
	char	h_cltname[66];
	char	h_domesticcp_clr_name[66];
	char  h_brkrno[13];
	char  h_cash_client[11];
	char h_allow_part_s[2];
   char	h_instruct_person[36];
	char	h_clientofcode[11];
	char	h_inter_med_person[36];
	char	h_inter_med_personnm[66];
	char	h_fxccy[4];
	char	h_locindentity_no[17];
	char	h_uniq_ident_no[12];
	char    h_related_indentity_no[21];
	char h_delrecdate[20]; 
	
} DL_DEALREPAIR_STRUCT_H;
*/


typedef struct {
	char h_dl_client[11];
	char h_indentity_no[17];
	double h_amt;
	char h_securitycd[9];
	double h_qty;
	char h_setldt[20];
	char h_classofdl[3];
	char h_dealcd[2];
	char h_origindentity_no[17];
	char h_locindentity_no[17];
	char h_domcpclt_cd[11];
 	char h_countclt[16];
	char h_countcltnm[66];
	char h_secdate[20];
	char h_moneydate[20];
	char h_ispart_[2];
	double h_origquantity;
	char h_dlt[20];
	char h_fail_cd[3];
	char h_entry[2];
	char h_resetdt[20];
	char h_msg_stat[51];
   char h_clientof[66];
   char    h_instruct_person[36];
   char    h_instruct_personnm[66];
	char h_clientofcode[11];
	char h_inter_med_person[36];
	char h_inter_med_personnm[66];
	char h_mod_hispos_ind[2];
	char h_loccode[APL_LOCNCODE_LENGTH];
}DL_DEALRST_STRUCT_H;



typedef struct {
	char	h_frm_seccd[9];
	char	h_dl_client[11];
	char	h_to_security[9];
	char  h_conv_dt[20];
} DL_INSTRUMENTCONV_STRUCT_H;



typedef struct {
	char	  h_indentity_no[17];
	char	  h_dl_client[11];
	char	  h_dl_class[3];
	char    h_securitycd[9];
	char    h_loccode[5];
	double  h_qty;
} DL_INSTRUMENTCONV_REP_TEMP_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_dealcd[2];
	char	h_dlt[20];
	char	h_setldt[20];
	char	h_securitycd[9];
	char	h_currencycode[4];
	double	h_amt;
	char	h_domcpclt_cd[11];
	char	h_domcp_custodyclt[11];
	char	h_ex_arena[3];
	char	h_newdt[20];
	char	h_hostdate[20];
	char	h_moneydate[20];
	char	h_domcp_custodygl[11];
	char	h_cltibbs[11];
	char	h_valuedate[20];
	char	h_classofent[2];
	char	h_timestamp[20];
	int	h_procnum;
	double	h_custodycomm;
	double	h_brokercomm;
	double	h_stx_comm;
	double	h_oth_comm;
} DL_DEALCLIENTIMG_STRUCT_H;



typedef struct {
	char	h_securitycd[9];
	double	h_open_pr;
	double	h_closing_pr;
} MT_MTHLYMKTPRC_STRUCT_H;



typedef struct {
	char	h_ibbsclt[11];
	double	h_cash_bal;
} DL_CASHBAL_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_dlt[20];
	char	h_setldt[20];
	double	h_qty;
	double	h_pr;
	char	h_execdate[20];
	char	h_timestamp[20];
	double	h_brokercomm;
	char	h_tax_amount[2];
	char	h_reset_ind[2];
	char	h_orderindentity_no[17];
} OR_EXECORDER_STRUCT_H;



/*
typedef struct {
	char	h_securitycd[9];
	char	h_loccode[5];
	char	h_dl_client[11];
	char	h_timestamp[20];
	char	h_pos_stat[4];
	double	h_stsafekeep_pos;
	double	h_safekeep_pos;
	double	h_nval_rec;
	double	h_nval_del;
	double	h_val_rec;
	double	h_val_del;
} DL_SAFEK_STRUCT_H;
*/
typedef struct {
	char		h_dl_client[11];
	char		h_securitycd[9];
	char		h_st_reg_no[21];
	char		h_loccode[5];
	double	h_val_rec;
	double	h_val_del;
	double	h_safekeep_pos;
	char		h_new_old_ind[2];
	char		h_new_dt[20];
}DL_RUSAFEK_STRUCT_H;



typedef struct {
   char  h_positdate[20];
	char  h_dl_client[11];
	char  h_securitycd[9];
   char  h_loccode[5];
	char  h_st_reg_no[21];
   double   h_safekeep_pos;
   double   h_val_rec;
   double   h_val_del;
} DL_RUHISSAFEK_STRUCT_H;



typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_trail_for[2];
	char	h_processdetail[61];
	char	h_proc_usr[15];
	char	h_subprocess[4];
	char	h_logdate[20];
	char	h_fail_cd[3];
	double	h_qty;
	char	h_dlfromord[2];
	int	h_subfailreas_cd;
} DL_DEALAUDIT_STRUCT_H;



typedef struct {
	char	h_fail_cd[3];
	char	h_faildetail[33];
	char	h_interdetail[51];
	char	h_mapword[21];
	int	h_subfailreas_cd;
	char	h_status_qual_ind[5];
	char	h_status_cd[7];
	char	h_reason_ql[7];
	char	h_reason_cd[5];
	char	h_support_ind[1];
} PRO_FAILCODES_STRUCT_H;




typedef struct {
	char	h_ct_clt[4];
	char	h_lr_detail[46];
	char	h_clt_type[3];
	char	h_clt_own[4];
	char	h_flag[2];
	char	h_own_ind[2];
} DL_LOCALREPCLIENT_STRUCT_H;




typedef struct {
	char	h_dealclass[3];
	char	h_dealcd[2];
	int	h_dtfld;
	char	h_status_active[2];
	char	h_dtname[11];
	char	h_indname[13];
	char	h_debit_flag[4];
	char	h_debit_ind_100[11];
	char	h_credit_flag[4];
	char	h_credit_ind_100[11];
	char	h_desc[66];
	char	h_info[66];
	char	h_iv_cond[201];
	char	h_local_iv_cond[201];
	char  h_desc_a[21];
	char  h_desc_b[21];
} DL_LOCALREPSPEC_STRUCT_H;




typedef struct {
	char	h_dltype[3];
	char	h_dlesc[36];
	char	h_nds_blk[2];
	char	h_nds_ind[2];
	char	h_dealcdmtx[5];
	char	h_clttype[4];
	char	h_block[2];
	char	h_new[2];
	char	h_clt_brk_all[2];
	char	h_deal_class_cd[5];
} DL_LOCALREPDEALTYPE_STRUCT_H;




typedef struct {
	char	h_nation[3];
	char	h_reg_st_cd[2];
	char	h_regstdetail[41];
	char	h_pos_stat[4];
	char	h_updatepos[2];
	char	h_reg_aud_fun[4];
	char	h_man_stat[2];
	char	h_reg_short[7];
	char	h_new_reg_a[2];
	char	h_newt_reg_b[2];
	char	h_fldupdate[21];
	char	h_prev_reg[2];
} DL_REGCYCLE_STRUCT_H;




typedef struct {
	char	h_oldsecuritycd[9];
	char	h_newsecuritycd[9];
	char	h_creater[15];
	char	h_authoriser[15];
} DL_INSTRUMENTCHG_STRUCT_H;




typedef struct {
	char	h_mapclass[21];
	char	h_mapvalue[11];
	char	h_map_val[5];
} PRO_GMATCHVALUE_STRUCT_H;




typedef struct {
	char	h_securitycd[9];
	char	h_ct_clt[4];
	char	h_dl_client[11];
	double	h_openbalance;
	double	h_closing_bal;
	char	h_domcpclt_cd[11];
	char	h_lstsecdate[20];
} DL_LOCALREPSAFEK_STRUCT_H;




typedef struct {
	int	h_client_name;
	char	h_lr_dt[20];
	char	h_info[66];
} DL_LOCALREPDATES_STRUCT_H;



typedef struct {
	char	h_securitycd[9];
	char	h_positdate[20];
	char	h_loccode[5];
	char	h_dl_client[11];
	char	h_pos_stat[4];
	double	h_stsafekeep_pos;
	double	h_safekeep_pos;
	double	h_nval_rec;
	double	h_nval_del;
	double	h_val_rec;
	double	h_val_del;
   double h_dp_rec;
   double h_dp_del;
	 char   h_block_type[5];
} DL_HISSAFEK_STRUCT_H;




typedef struct {
	char	h_prdt[20];
	char	h_securitycd[9];
	double	h_closing_pr;
	char	h_updtmode[2];
	char    h_creater[15];
	char	h_create_dt[20];
	char	h_mkrtpr_stat[3];
	char	h_authoriser[15];
	char	h_authoriserdt[20];
} MT_HISDLYMKTPRC_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_newdt[20];
	char	h_dlt[20];
	char	h_setldt[20];
	double	h_pr;
	char	h_ex_arena[3];
	double	h_amt;
	double	h_custodycomm;
	double	h_brokercomm;
	double	h_stx_comm;
	double	h_oth_comm;
	char	h_secdate[20];
	char	h_moneydate[20];
	double	h_qty;
	char	h_domcpclt_cd[11];
	char	h_isspotdl[2];
	double	h_origquantity;
	double	h_origamount;
	char	h_dlfromord[2];
	char	h_entry[2];
	char	h_reapired_ind[2];
	char	h_domcp_custodyclt[11];
	char	h_countclt[16];
	char	h_countcltnm[66];
	char	h_clientof[66];
	char	h_custinfo[71];
	char	h_fx_reqd[2];
	char	h_ispymtlocal[2];
	char	h_verfied_with[26];
	double	h_diffamount;
	char	h_brkrno[13];
	char	h_fail_cd[3];
	char	h_failinfo[36];
	char	h_ispart_[2];
	double	h_fx_rt;
	int	h_amend_count;
	int	h_number_a;
	char	h_report_at_eom_ind[2];
	char	h_billdate[20];
	char	h_locindentity_no[17];
	char	h_instruct_person[36];
	double	h_rec_int_000;
	char	h_dealcd[2];
	char	h_securitycd[9];
	char	h_currencycode[4];
	char	h_classofdl[3];
	char	h_origindentity_no[17];
	char	h_creater[15];
	char	h_create_dt[20];
	char	h_deal_status[3];
	char	h_info1[261];
	char	h_loccode[5];
	char	h_regsec_ind[2];
	char	h_pos_stat[4];
	char	h_status_reg[2];
	char	h_confdate[20];
	char	h_matchindentity_no[17];
	char	h_markfaildate[20];
	char	h_candropdate[20];
	char	h_authoriser[15];
	char	h_authoriserdt[20];
	char	h_secconv_ind[2];
	char	h_ndsbldate[20];
	char	h_lrdltype[3];
	char	h_ndsdate[20];
	char	h_ublckdate[20];
	double	h_delta_000;
	double	h_delta_001;
	double	h_delta_002;
	char	h_delrecdate[20];
	char	h_lastregdate[20];
	char	h_lr_chkdate[20];
	char	h_lr_confdate[20];
	char	h_lr_secdate[20];
	double	h_regmsgquantity;
	char	h_tmpoutdate[20];
	char	h_tmpretdate[20];
	char	h_transmitdate[20];
	double	h_complquantity;
	double	h_lostquantity;
	double	h_marktrfquantity;
	double	h_mcomplquantity;
	double	h_outregquantity;
	double	h_pendregquantity;
	double	h_retregquantity;
	double	h_stampquantity;
	double	h_tempoutquantity;
	double	h_tempretquantity;
	double	h_valdeedquantity;
	char	h_hostdate[20];
	char	h_lr_ndsbldate[20];
	char	h_clnt_clr_name[66];
	char	h_lr_ndsdate[20];
	char	h_secdetail[131];
	char	h_lr_ublckdate[20];
	char	h_domestic_cpclr_name[66];
	char	h_domcp_custodynm[66];
	int	h_number_b;
	char	h_closedate[20];
	char	h_clt_reqdel_flag[2];
	char	h_mod_hispos_ind[2];
	char    h_instruct_personnm[66];
        char    h_clientofcode[11];
	char    h_inter_med_person[36];
	char    h_inter_med_personnm[66];
	char    h_fxccy[4];
} DL_HISDEAL_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_orderindentity_no[17];
	char	h_buy_sell_flag[2];
	char	h_orderdate[20];
	double	h_orderquantity;
	char	h_limit_ind[2];
	char	h_isgte_ind[2];
	char	h_all_none_ind[2];
	char	h_ex_arena[3];
	char	h_ord_stat[3];
	char	h_securitycd[9];
	char	h_creater[15];
	char	h_create_dt[20];
	char	h_timestamp[20];
	char	h_authoriser[15];
	char	h_authoriserdt[20];
	char	h_expirydate[20];
	double	h_limitpr;
	char	h_canceleddate[20];
	double	h_execquantity;
	char	h_candropdate[20];
	char	h_broker_cd[11];
	char	h_locindentity_no[17];
	char	h_lrdltype[3];
	char	h_lr_chkdate[20];
	char	h_lr_ublckdate[20];
	char	h_ublckdate[20];
	char	h_lastexecdate[20];
	char	h_lastdeal[17];
	char	h_clnt_clr_name[66];
	char	h_secdetail[131];
	char	h_closedate[20];
} OR_HISORDER_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_dlt[20];
	char	h_setldt[20];
	double	h_qty;
	double	h_pr;
	char	h_execdate[20];
	char	h_timestamp[20];
	double	h_brokercomm;
	char	h_tax_amount[2];
	char	h_reset_ind[2];
	char	h_orderindentity_no[17];
} OR_HISEXECORDER_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	int	h_srl_no;
	char	h_newdt[20];
	char	h_reg_st_cd[2];
	char	h_txndate[20];
	double	h_qty;
	double	h_quantitymoved;
	double	h_quantitymanifld;
	char	h_dtcltfor[20];
	char	h_prcsmrdate[20];
	char	h_status_prc[2];
	char	h_prcstldate[20];
	double	h_smramount;
	int	h_parent_srlno;
} DL_HISREGDET_STRUCT_H;




typedef struct {
	char	h_dl_client[11];
	char	h_indentity_no[17];
	char	h_newdt[20];
	char	h_trail_for[2];
	char	h_processdetail[61];
	char	h_proc_usr[15];
	char	h_subprocess[4];
	char	h_logdate[20];
	char	h_fail_cd[3];
	double	h_qty;
	char	h_dlfromord[2];
	int	h_subfailreas_cd;
} DL_HISDEALSAUDIT_STRUCT_H;

typedef struct
{
	char	h_dl_client[11];
	char 	h_securitycd[9];
	char	h_rec_del[2];
	double	h_qty;
	double	h_amt;
	char	h_act_dvp[2];
	char  h_classofdl[2];
	char  h_countclt[16];
} DL_CLHTR_STRUCT_H;


typedef struct
{
       double h_sequence_num;
       char   h_sys_dt[11];
       char   h_set_dt[11];
       char   h_dl_client[APL_CLIENT_LENGTH];
       char   h_clh_client[16];
       char   h_countclt[APL_COUNTACC_LEN];
       char   h_sec_isin[13];
       double h_qty;
}DL_CLHCRI_STRUCT_H;



typedef struct
{
	char 		h_securitycd[APL_INSTRUMENTCODE_LEN];
	char		h_ctclt[4];
	char		h_dl_client[APL_CLIENT_LENGTH];
	double	h_qty;
	char		h_domcpclt_cd[APL_CLIENT_LENGTH];
} DL_LOCALREPPROC2_STRUCT_H;


typedef struct
{
	char     h_securitycd[APL_INSTRUMENTCODE_LEN];
	char     h_ctclt[14];
	double   h_qty;
	char     h_domcpclt_cd[APL_CLIENT_LENGTH];
	char		h_sec_isin[13];
}	DL_LOCALREPPROC3_STRUCT_H;
	

typedef struct {
   char  h_dl_client[11];
   char  h_indentity_no[17];
   char  h_securitycd[9];
   char  h_ctclt[5];
   char  h_dbclt[5];
   char  h_domcpclt_cd[11];
   double   h_qty;
   int   h_dtfld;
   int   h_r_code;
   char  h_ord_ind[2];
   char  h_lrdltype[3];
   char  h_dealcd[2];
   char  h_reset_ind[2];
} DL_LOCALREPROCMA_STRUCT_H;



typedef struct {
   char  h_ct_clt[5];
   char  h_lr_detail[46];
   char  h_clt_type[3];
   char  h_clt_own[4];
   char  h_flag[2];
   char  h_own_ind[2];
} DL_LOCALREPCLIENTMA_STRUCT_H;



typedef struct {
   char  h_dealclass[3];
   char  h_dealcd[2];
   int   h_dtfld;
   char  h_status_active[2];
   char  h_dtname[11];
   char  h_indname[13];
   char  h_debit_flag[5];
   char  h_debit_ind_100[11];
   char  h_credit_flag[5];
   char  h_credit_ind_100[11];
   char  h_desc[66];
   char  h_info[66];
   char  h_iv_cond[201];
   char  h_local_iv_cond[201];
   char  h_desc_a[21];
   char  h_desc_b[21];
} DL_LOCALREPSPECMA_STRUCT_H;



typedef struct {
   char  h_securitycd[9];
   char  h_ct_clt[5];
   char  h_dl_client[11];
   double   h_openbalance;
   double   h_closing_bal;
   char  h_domcpclt_cd[11];
   char  h_lstsecdate[20];
} DL_LOCALREPSAFEKMA_STRUCT_H;

 #include "CR_Header_B.h" 
