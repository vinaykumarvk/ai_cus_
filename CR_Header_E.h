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












 


typedef struct {
		short	i_dl_client;
		short  i_indentity_no;
		short  i_locindentity_no;
		short  i_brkrno;
		short  i_clt_reqdel_flag;
		short  i_timestamp;
		short  i_dealcd;
      short  i_dlt;
      short  i_setldt;
      short  i_classofdl;
      short  i_lrdltype;
      short  i_amt;
      short  i_pr;
      short  i_domcpclt_cd;
		short  i_custinfo;
		short  i_lr_ndsdate;
} DL_DEAL_OTH_STRUCT_I;

typedef struct {
	char h_ora_rowid[APL_ROWID_LEN];
	char h_dl_client[APL_CLIENT_LENGTH];
	char h_indentity_no[APL_TXNREFNO_LEN];
	char h_securitycd[APL_INSTRUMENTCODE_LEN];
	char h_lrdltype[3];
	char h_dealcd[2];
	double h_qty;
	char h_dlfromord[2];
	char h_confdate[APL_DATE_LEN];
	char h_secdate[APL_DATE_LEN];
	char h_authoriserdt[APL_DATE_LEN];
	char h_ndsdate[APL_DATE_LEN];
	char h_ublckdate[APL_DATE_LEN];
	char h_ndsbldate[APL_DATE_LEN];
	char h_lr_confdate[APL_DATE_LEN];
	char h_lr_secdate[APL_DATE_LEN];
	char h_lr_chkdate[APL_DATE_LEN];
	char h_lr_ndsdate[APL_DATE_LEN];
	char h_lr_ublckdate[APL_DATE_LEN];
	char h_lr_ndsbldate[APL_DATE_LEN];
	char h_domcpclt_cd[APL_CLIENT_LENGTH];
	char h_deal_status[APL_STATUS_LEN];
	char h_closedate[APL_DATE_LEN];
} LRSTRUCT_H;


typedef struct {
	short i_ora_rowid;
	short i_dl_client;
	short i_indentity_no;
	short i_securitycd;
	short i_lrdltype;
	short i_dealcd;
	short i_qty;
	short i_dlfromord;
	short i_confdate;
	short i_secdate;
	short i_authoriserdt;
	short i_ndsdate;
	short i_ublckdate;
	short i_ndsbldate;
	short i_lr_confdate;
	short i_lr_secdate;
	short i_lr_chkdate;
	short i_lr_ndsdate;
	short i_lr_ublckdate;
	short i_lr_ndsbldate;
	short i_domcpclt_cd;
	short i_deal_status;
	short i_closedate;
} LRSTRUCT_I;

typedef struct {
	char		h_ora_rowid[APL_ROWID_LEN];
 	char 		h_dl_client[APL_CLIENT_LENGTH];
	char		h_orderindentity_no[APL_TXNREFNO_LEN];
	char		h_securitycd[APL_INSTRUMENTCODE_LEN];
	char		h_lrdltype[3];
	char		h_buy_sell_flag[APL_FLAG_LENGTH];
	double	h_orderquantity;
	char		h_authoriserdt[APL_DATE_LEN];
	char		h_ublckdate[APL_DATE_LEN];
 	char		h_lr_chkdate[APL_DATE_LEN];
	char		h_lr_ublckdate[APL_DATE_LEN];
	char		h_broker_cd[APL_CLIENT_LENGTH];
	char		h_expirydate[APL_DATE_LEN];
	double	h_execquantity;
	char		h_isgte_ind[APL_FLAG_LENGTH];
	char		h_ord_stat[APL_STATUS_LEN];
	char		h_closedate[APL_DATE_LEN];
}	LR_ORDSTRUCT_H;

typedef struct {

	short		i_ora_rowid;
 	short		i_dl_client;
	short		i_orderindentity_no;
	short		i_securitycd;
	short		i_lrdltype;
	short		i_buy_sell_flag;
	short		i_orderquantity;
	short		i_authoriserdt;
	short		i_ublckdate;
 	short		i_lr_chkdate;
	short		i_lr_ublckdate;
	short		i_broker_cd;
	short		i_expirydate;
	short		i_execquantity;
	short		i_isgte_ind;
	short		i_ord_stat;
	short		i_closedate;
}	LR_ORDSTRUCT_I;


typedef struct {
	char	h_setldt[20];
	char	h_confdate[20];
	char	h_typeofsec[4];
	char 	h_iposel_ind[2];
	char 	h_securitycd[APL_INSTRUMENTCODE_LEN];
	char 	h_selsetldt[3];
} DL_DEAL_AMT_STRUCT_H;

typedef struct 
{
	char		h_allow_rf[2];
	char		h_allow_rvp[2];
	char		h_allow_df[2];
	char 		h_allow_dvp[2];
	char		h_order_class[2];
}DEAL_ORD_STRUCT_H;

typedef struct 
{
	short 	i_allow_rf;
	short 	i_allow_rvp;
	short 	i_allow_df;
	short 	i_allow_dvp;
	short		i_order_class;
}DEAL_ORD_STRUCT_I;


typedef struct {
	char p_ora_rowid[APL_ROWID_LEN];
	char p_creater[APL_USERID_LEN];
	char p_cltstmp_cmp[APL_DATE_LEN];
	char p_loccode[APL_LOCNCODE_LENGTH];
	char p_status_ind[APL_STATUS_LEN];
	double p_quantity;
	char p_dt[APL_DATE_LEN];
	char p_orefretval[APL_TXNREFNO_LEN];
	char p_delrecdate[APL_DATE_LEN];
	char p_secdate[APL_DATE_LEN];
	char p_moneydate[APL_DATE_LEN];
	char p_securitycd[APL_INSTRUMENTCODE_LEN];
	char p_currencycode[APL_CCYCODE_LEN];
	char p_posnstatus_ind[4];
	char p_dealcd[APL_FLAG_LENGTH];
	char p_failreas_cd[3];
	char p_dlfromord[APL_FLAG_LENGTH];
} DL_DEAL_RSTPMT_STRUCT_H;

typedef struct {
  char p_ora_rowid[APL_ROWID_LEN];
  char p_securitycd[APL_INSTRUMENTCODE_LEN];
  char p_loccode[APL_LOCNCODE_LENGTH];
  char p_client[APL_CLIENT_LENGTH];
  char p_indentity_no[APL_TXNREFNO_LEN];
  char p_creater[APL_USERID_LEN];
  char p_cltstmp_cmp[APL_DATE_LEN];
  char p_status_reg[APL_FLAG_LENGTH];
  char p_setldt[APL_DATE_LEN];
  char p_secdate[APL_DATE_LEN];
  char p_moneydate[APL_DATE_LEN];
  char p_updhispos_date[APL_DATE_LEN];
  char p_dealcd[APL_FLAG_LENGTH];
  char p_isspotdl[APL_FLAG_LENGTH];
  char p_secconv_ind[APL_FLAG_LENGTH];
  char p_report_at_eom_ind[APL_FLAG_LENGTH];
  char p_mod_hispos_ind[APL_FLAG_LENGTH];
  char p_status_ind[4];
  char p_ex_arena[3];
  char p_failreas_cd[3];
  char p_dlfromord[APL_FLAG_LENGTH];
  double p_quantity; 
  double p_recinto000; 
  double p_pendregquantity;
  double p_mcomplquantity;
  double p_complquantity;
  double p_delta_000;
  double p_delta_001;
  double p_delta_003;
} DL_DEAL_RSTSST_STRUCT_H;

typedef struct
{
	short i_frm_seccd;
	short i_to_security;
	short i_noelements_cltt_arr;
	short i_cltt_arr;
} DL_INSTRUMENTCONV_OTH_STRUCT_I;

typedef struct {
	char 	h_dl_client[APL_CLIENT_LENGTH];
	char	h_indentity_no[APL_TXNREFNO_LEN];
	char	h_tktclass[APL_FLAG_LENGTH];
	char	h_dupl[APL_FLAG_LENGTH];
	char	h_timestamp[APL_DATE_LEN];
} DL_MANIFLD_STRUCT_H;

typedef struct {
	char 	h_dl_client[APL_CLIENT_LENGTH];
	char	h_indentity_no[APL_TXNREFNO_LEN];
	char	h_tktclass[APL_FLAG_LENGTH];
	char	h_dupl[APL_FLAG_LENGTH];
	int	h_srl_no;
	double	h_qty;
} DL_MANIPRNT_STRUCT_H;

typedef struct {
	char		h_dl_client[APL_CLIENT_LENGTH];
	char		h_securitycd[APL_INSTRUMENTCODE_LEN];
	char		h_loccode[APL_LOCNCODE_LENGTH];
	double	h_qty;
	char		h_bclreg_ind[APL_FLAG_LENGTH];
	char		h_locindentity_no_rf[APL_TXNREFNO_LEN];
	char		h_locindentity_no_df[APL_TXNREFNO_LEN];
} BCL_TRF_STRUCT_H;

typedef struct {
	char 		p_ora_rowid[APL_ROWID_LEN];
	char 		p_cltstmp_cmp[APL_DATE_LEN];
	char 		p_entry[2];
	char 		p_delrecdate[APL_DATE_LEN];
	char 		p_secdate[APL_DATE_LEN];
	char 		p_moneydate[APL_DATE_LEN];
	char 		p_dealcd[2];
	char 		p_dlfromord[2];
	char 		p_failreas_cd[3];
	double   p_quantity;
	double 	p_tempoutquantity;
	double 	p_tempretquantity;
}DL_DEAL_OTH_MANP_RST_STRUCT_H;

typedef struct {
	char	report_name[51];
	char	report_desc[APL_REPDESC_LENGTH];
	char	report_date[APL_DATE_LEN];
	int	report_width;
	char	task_desc[61];
	char	fe_be_ind[APL_FLAG_LENGTH];
	char	usr[APL_USERID_LEN];
} INTL_REPT_STRUCT_H ;

typedef struct {
	char	h_tx_fromdate[APL_DATE_LEN];
	char	h_tx_todate[APL_DATE_LEN];
	char	h_livehist_ind[APL_FLAG_LENGTH];
	char	h_dlhf_dir[61];
	char	h_code_fromdt[APL_DATE_LEN];
	char	h_code_todt[APL_DATE_LEN];
	char	h_code_handoff_dir[61];
	char	h_in_fromdate[APL_DATE_LEN];
	char	h_in_todate[APL_DATE_LEN];
	char	h_hf_dir[61];
	char	h_tx_code_in_flg[APL_FLAG_LENGTH];
}MT_EOM_TAX_STRUCT_H;



typedef struct {
	char h_run_dt[APL_DATE_LEN];
	char h_daily_ind[APL_FLAG_LENGTH];
	char h_genoperreport_ind[APL_FLAG_LENGTH];
	char h_gencustoperreport_ind[APL_FLAG_LENGTH];
	char h_genmainoperreport_ind[APL_FLAG_LENGTH];
	char h_gendlybalreport_ind[APL_FLAG_LENGTH];
	char h_updlocrepposn_ind[APL_FLAG_LENGTH];
	char h_lastlrdt[APL_DATE_LEN];
	char h_sysdt[APL_DATE_LEN];
	char h_rst_tday_ind;
	char h_rst_ind;
} PO_LR_STRUCT_H;

typedef struct {
	char	h_dl_client[APL_CLIENT_LENGTH]; 
	char	h_domcpclt_cd[APL_CLIENT_LENGTH]; 
	char	h_countclt[APL_COUNTACC_LEN]; 
	char	h_lrdltype[3];
	char	h_deal_status[APL_STATUS_LEN];
	char	h_indentity_no[APL_TXNREFNO_LEN];
	char	h_securitycd[APL_INSTRUMENTCODE_LEN];
	char	h_classofdl[3];
	double	h_qty;
	char	h_dealcd[2];
	char	h_secdate[APL_DATE_LEN];
	char	h_confdate[APL_DATE_LEN];
	char	h_authoriser[APL_USERID_LEN];
	char	h_ndsdate[APL_DATE_LEN];
	char	h_newdt[APL_DATE_LEN];
	char	h_dlfromord[APL_FLAG_LENGTH];
	char	h_countcltnm[66];
	char	h_timestamp[APL_DATE_LEN];
   char  h_ex_arena[3];
	double h_setl_sequence_no;
} DEAL_LR_STRUCT_H;

typedef struct {
	short	i_dl_client; 
	short	i_domcpclt_cd;
	short	i_countclt;
	short	i_lrdltype;
	short	i_deal_status;
	short	i_indentity_no;
	short	i_securitycd;
	short	i_classofdl;
	short	i_qty;
	short	i_dealcd;
	short	i_secdate;
	short	i_confdate;
	short	i_authoriser;
	short	i_ndsdate;
	short	i_newdt;
	short	i_dlfromord;
	short	i_countcltnm;
	short	i_timestamp;
   short i_ex_arena;
	short i_setl_sequence_no;
} DEAL_LR_STRUCT_I;



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
} LR_ORD_STRUCT_H;



typedef struct {
	short	i_dl_client;
	short	i_orderindentity_no;
	short	i_buy_sell_flag;
	short	i_orderdate;
	short	i_orderquantity;
	short	i_limit_ind;
	short	i_isgte_ind;
	short	i_all_none_ind;
	short	i_ex_arena;
	short	i_ord_stat;
	short	i_securitycd;
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_expirydate;
	short	i_limitpr;
	short	i_canceleddate;
	short	i_execquantity;
	short	i_candropdate;
	short	i_broker_cd;
	short	i_locindentity_no;
	short	i_lrdltype;
	short	i_lr_chkdate;
	short	i_lr_ublckdate;
	short	i_ublckdate;
	short	i_lastexecdate;
	short	i_lastdeal;
} LR_ORD_STRUCT_I;

typedef struct {
        char h_temp1[11];
        char h_temp2[23];
        char h_temp3[2];
        char h_temp4[32];
        char h_temp5[24];
        char h_temp6[11];
        char h_temp7[87];
        char h_dl_client[25];
        double h_brokercomm;
        char h_broker_identity[12];
        double h_grossamount;
        char h_sec_isin[13];
        double h_netamount;
        double h_pr;
        double h_qty;
        char h_rec_del[2];
        char h_mcl_ref[11];
	char h_dlt[APL_DATE_LEN];
	char h_upld_date[APL_DATE_LEN];
	int h_error_cd;
} DL_DEAL_MARCLR_STRUCT_H;

typedef struct {
        short i_temp1;
        short i_temp2;
        short i_temp3;
        short i_temp4;
        short i_temp5;
        short i_temp6;
        short i_temp7;
        short i_dl_client;
        short i_brokercomm;
        short i_broker_identity;
        short i_grossamount;
        short i_sec_isin;
        short i_netamount;
        short i_pr;
        short i_qty;
        short i_rec_del;
        short i_mcl_ref;
	short i_dlt;
	short i_upld_date;
	short i_error_cd;
} DL_DEAL_MARCLR_STRUCT_I;
