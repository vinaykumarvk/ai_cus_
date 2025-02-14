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
	short	i_indentity_no;
	short	i_securitycd;
	short	i_ctclt;
	short	i_dbclt;
	short	i_domcpclt_cd;
	short	i_qty;
	short	i_dtfld;
	short	i_r_code;
	short	i_ord_ind;
	short	i_lrdltype;
	short	i_dealcd;
	short	i_reset_ind;
} DL_LOCALREPPROC_STRUCT_I;




typedef struct {
	short	i_dlrep_sequencenum;
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dealcd;
	short	i_dlt;
	short	i_setldt;
	short	i_qty;
	short	i_securitycd;
	short	i_currencycode;
	short	i_domcpclt_cd;
	short	i_classofdl;
	short	i_pr;
	short	i_ex_arena;
	short	i_isspotdl;
	short	i_entry;
	short	i_newdt;
	short	i_creater;
	short	i_create_dt;
	short	i_deal_status;
	short	i_timestamp;
	short	i_amt;
	short	i_domcp_custodyclt;
	short	i_countclt;
	short	i_countcltnm;
	short	i_clientof;
	short	i_info1;
	short	i_fx_reqd;
	short	i_custodycomm;
	short	i_brokercomm;
	short	i_stex_comm;
	short	i_oth_comm;
	short	i_loccode;
	short	i_status_pos;
	short 	i_secdetail;
	short	i_cltname;
	short	i_domesticcp_clr_name;
	short i_brkrno;
	short i_cash_client;
	short i_allow_part_s;
	short	i_instruct_person;
	short i_clientofcode;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_locindentity_no;
	short i_uniq_ident_no;
	short i_related_indentity_no;
	short i_delrecdate; 
	/*Retro from HDFCby Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
} DL_DEALREPAIR_STRUCT_I;


typedef struct {
   short i_dl_client;
   short i_indentity_no;
   short i_amt;
   short i_securitycd;
   short i_qty;
   short i_setldt;
   short i_classofdl;
   short i_dealcd;
   short i_origindentity_no;
   short i_locindentity_no;
   short i_domcpclt_cd;
   short i_countclt;
   short i_countcltnm;
   short i_secdate;
   short i_moneydate;
   short i_ispart_;
   short i_origquantity;
   short i_dlt;
   short i_failreas_cd;
   short i_entry;
   short i_resetdt;
   short i_msg_stat;
   short i_clientof;
   short i_instruct_person;
   short i_instruct_personnm;
   short i_clientofcode;
   short i_inter_med_person;
   short i_inter_med_personnm;
	short i_mod_hispos_ind;
	short i_loccode;
}DL_DEALRST_STRUCT_I;



typedef struct {
	short	i_frm_seccd;
	short	i_dl_client;
	short	i_to_security;
	short i_conv_dt;
} DL_INSTRUMENTCONV_STRUCT_I;

typedef struct {
	short	i_indentity_no;
	short	i_dl_client;
	short	i_dl_class;
	short i_securitycd;
	short i_loccode;
	short i_qty;
} DL_INSTRUMENTCONV_REP_TEMP_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dealcd;
	short	i_dlt;
	short	i_setldt;
	short	i_securitycd;
	short	i_currencycode;
	short	i_amt;
	short	i_domcpclt_cd;
	short	i_domcp_custodyclt;
	short	i_ex_arena;
	short	i_newdt;
	short	i_hostdate;
	short	i_moneydate;
	short	i_domcp_custodygl;
	short	i_cltibbs;
	short	i_valuedate;
	short	i_classofent;
	short	i_timestamp;
	short	i_procnum;
	short	i_custodycomm;
	short	i_brokercomm;
	short	i_stx_comm;
	short	i_oth_comm;
} DL_DEALCLIENTIMG_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_domcpclt_cd;
	short	i_dealcd;
	short	i_setldt;
	short	i_qty;
	short	i_securitycd;
	short	i_amt;
	short	i_pr;
	short	i_newdt;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_countcltnm;
	short	i_misdeal_status;
	short	i_countclt;
	short	i_creater;
	short i_info;
	short i_place_of_deal;
	short i_market_flag;
	short i_description;
	short i_dealdt;
	short i_clientofcode;
	short i_clientof;
	short i_instruct_person;
	short i_instruct_personnm;
	short i_deal_class;
	short i_trrf_ident;
	short i_comm_ident;
	short i_pool_ident;
	short i_send_msg_ind;
	short i_party_con;
	short i_uniq_ident_no;
	short i_proc_num;
	short i_nameof_file;
	short i_dsn_ident;
} DL_MISDEAL_STRUCT_I;




typedef struct {
	short	i_securitycd;
	short	i_open_pr;
	short	i_closing_pr;
} MT_MTHLYMKTPRC_STRUCT_I;




typedef struct {
	short	i_prdt;
	short	i_securitycd;
	short	i_closing_pr;
	short	i_updtmode;
	short	i_timestamp;
	short	i_creater;
	short	i_create_dt;
	short	i_mkrtpr_stat;
	short	i_authoriser;
	short	i_authoriserdt;
} MT_DLYMKTPRC_STRUCT_I;




typedef struct {
	short	i_ibbsclt;
	short	i_cash_bal;
} DL_CASHBAL_STRUCT_I;




typedef struct {
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_stx_client;
	short	i_commn_client;
	short	i_tpymt_client;
	short	i_texp_client;
	short	i_bnk_client;
} MT_CLIENT_ENTRIES_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dlt;
	short	i_setldt;
	short	i_qty;
	short	i_pr;
	short	i_execdate;
	short	i_timestamp;
	short	i_brokercomm;
	short	i_tax_amount;
	short	i_reset_ind;
	short	i_orderindentity_no;
} OR_EXECORDER_STRUCT_I;



/*
typedef struct {
	short	i_securitycd;
	short	i_loccode;
	short	i_dl_client;
	short	i_timestamp;
	short	i_status_pos;
	short	i_stsafekeep_pos;
	short	i_safekeep_pos;
	short	i_nval_rec;
	short	i_nval_del;
	short	i_val_rec;
	short	i_val_del;
} DL_SAFEK_STRUCT_I;
*/
typedef struct {
   short     i_dl_client;
   short     i_securitycd;
   short     i_st_reg_no;
   short     i_loccode;
   short     i_val_rec;
   short     i_val_del;
   short     i_safekeep_pos;
   short     i_new_old_ind;
   short     i_new_dt;
}DL_RUSAFEK_STRUCT_I;



typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_srl_no;
	short	i_reg_st_cd;
	short	i_txndate;
	short	i_qty;
	short	i_timestamp;
	short	i_quantitymoved;
	short	i_quantitymanifld;
	short	i_dtcltfor;
	short	i_prcsmrdate;
	short	i_status_prc;
	short	i_prcstldate;
	short	i_smramount;
} DL_REGDET_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_trail_for;
	short	i_processdetail;
	short	i_proc_usr;
	short	i_subprocess;
	short	i_logdate;
	short	i_failreas_cd;
	short	i_qty;
	short	i_dlfromord;
	short	i_subfailreas_cd;
} DL_DEALAUDIT_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_msg_ident_no;
	short	i_addrsequence_num;
	short	i_swift_tlx_gcn;
	short	i_priority_ind;
	short	i_gcn_addr;
	short	i_swift_addr;
	short	i_infolex;
	short	i_schedule;
	short	i_comb_msg;
	short	i_fax_addr;
	short	i_identify;
	short	i_timestamp;
	short	i_holdings;
    	short   i_schsequence_num;
	short	i_iso_msg_format;
	short	i_validate_flag;
} MT_MSGADDRESS_STRUCT_I;




typedef struct {
	short	i_currencycode;
	short	i_denom_currencycode;
	short	i_rtdt;
	short	i_exchgrt;
	short	i_rate_buy;
	short	i_sellae_rate;
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_exchg_stat;
} MT_EXCHRATE_STRUCT_I;




typedef struct {
	short	i_securitycd;
	short	i_currencycode;
	short	i_loccode;
	short	i_nominal_val;
	short	i_regbrflag;
	short	i_allow_rf;
	short	i_allow_rvp;
	short	i_allow_df;
	short	i_allow_dvp;
	short	i_order_class;
	short	i_mother_sec_ind;
	short	i_ex_arena;
	short	i_listed_ind;
	short	i_newdt;
	short	i_threshold_qty;
	short	i_newcreater;
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_total_pdcapital;
	short	i_sec_stat;
	short	i_new_issue;
	short	i_newauthoriser;
	short	i_chng_lst_flag;
	short	i_cert_of_own_flag;
	short	i_secdetail;
	short	i_sec_isin;
	short	i_tipo_inv;
	short	i_typeofsec;
	short	i_parent_sec;
	short	i_prodateype;
	short	i_secdealcd;
	short	i_cmp_code;
	short	i_classcd;
	short	i_new_cd;
	short	i_chgsec_isin;
	short	i_issue_date;
	short	i_chgcreater;
	short	i_ca_clr_name;
	short	i_chng_cd;
	short	i_mature_date;
	short	i_interest_class;
	short	i_inc_rate;
	short	i_frq_code;
	short	i_int_clttyp;
	short	i_lst_pymt_dt;
	short	i_lst_inc_rate;
	short	i_nxt_pymt_dt;
	short	i_oldlstpydate;
	short	i_updlstpydate;
	short	i_taxonmat_ind;
	short	i_disct_flag;
	short	i_ca_addrdet;
	short i_minfmtdlquantity;
	short i_lrsetldt1;
	short i_lrsetldt2;
	short i_short_clr_name;
	short i_ipo_ind;
	short i_ipo_valid_date;
	short i_lrsetldt3;
} MT_INSTRUMENT_STRUCT_I;




typedef struct {
	short	i_loccode;
	short	i_creater;
	short	i_create_dt;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_timestamp;
	short	i_status_pos;
	short	i_manifld_ind;
	short	i_loc_status;
	short	i_locdetail;
	short	i_physical_ind;
   short i_iso_loccode;
	short i_avail_flag;
   short i_depo; 
} MT_LOCATION_STRUCT_I;




typedef struct {
	short   i_holi_dt;
	short	i_holi_class;
	short	i_h_reas;
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_h_stat;
	short	i_hol_flag;
	short i_old_holi_class;
	short i_old_h_reas;
	short i_old_hol_flag;
	short i_bank_ind;
	short i_exch_code;
} MT_HOLIDAY_STRUCT_I;




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
} OR_ORDERDETAILS_STRUCT_I;




typedef struct {
	short	i_nationcode;
	short	i_prodateype;
	short	i_custodytaxrt;
	short	i_creater;
	short	i_create_dt;
	short i_timestamp;
	short i_status_ind;
	short i_authoriser;
	short i_authoriserdt;
} MT_WHTRATE_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_msg_ident_no;
	short	i_schsequence_num;
	short	i_eom_msg_ind;
	short	i_generate_day;
	short	i_pos_txn_ind;
	short	i_nil_mov_ind;
	short	i_msg_opt;
	short	i_loc_stat;
	short i_timestamp;
	short i_pend_ind;
	short i_weeklystmt;
	short i_validate_flag;
} MT_SCHDET_STRUCT_I;





typedef struct {
	short i_dl_client;
	short i_ibbsclient;
  	short i_currencycode;
	short i_defcurrency_flg;
	short i_ibanclient;
	short i_addnlclient;
}DL_CASHACC_STRUCT_I;



typedef struct {
	short	i_dl_client;
	short	i_currencycode;
	short	i_our_their_ind;
	short	i_iscc_ind;
	short	i_sec_isinuseflg;
	short	i_clnt_class;
	short	i_regclr_name;
	short	i_clt_class;
	short	i_billableflag;
	short	i_classofclt;
	short	i_vtbclient;
	short	i_cltreg;
	short	i_cltmemo;
	short	i_internal_clt;
	short i_posdt;
	short	i_base_id;
	short	i_count_swf_mon;
	short	i_tlxmonth_cnt;
	short	i_count_swf_yr;
	short	i_tlxyr_cnt;
	short	i_mstclt;
	short	i_clnt_clr_name;
	short	i_ibbsclient;
	short	i_clt_brk_all;
	short	i_shortclr_name;
	short	i_ord_clt;
	short	i_spotdlflg;
	short	i_fx_sell_flag;
	short	i_fx_buy_flag;
	short	i_fx_inc_flag;
	short	i_newdt;
	short	i_brnchcode;
	short	i_nationcode;
	short	i_fmt_rptflag;
	short	i_creater;
	short	i_create_dt;
	short	i_timestamp;
	short	i_authoriser;
	short	i_authoriser_dt;
	short	i_uniq_gcustody_id;
	short	i_cltprdcd;
	short	i_domestic;
	short	i_part_flg;
	short	i_allow_regflag;
	short	i_regsetlflg;
	short	i_reg_bcl_ind;
	short	i_clt_status;
	short	i_clhclient;
	short	i_taxable_ind;
	short	i_brk_cd;
	short	i_tax_id;
	short	i_contactinfo;
        short   i_extclhclient;
	short i_clt_grp;
	short i_sat_oper_cd;
	short i_tolerance_val;
	short i_authbunch_flag;
	short i_fxpurchasecurrency;
	short i_fxsalecurrency;
	short i_single548_support_ind;
	short i_stat_tran_flag;
	short i_trad_sett_flag;
   short i_rhts_ret;   
   short i_valcredit;
	short i_keep_fracredit_flag; 
   short i_auto_canc_flag; 
	short i_cltdetail;
	short i_generate_flag;
} MT_CLIENT_STRUCT_I;




typedef struct {
	short	i_currencycode;
	short	i_ccydetail;
	short	i_creater;
	short	i_dec_len;
	short	i_create_dt;
	short	i_timestamp;
	short	i_gl_cd;
} DL_CURRENCY_STRUCT_I;




typedef struct {
	short	i_failreas_cd;
	short	i_faildetail;
	short	i_interdetail;
	short	i_mapword;
	short	i_subfailreas_cd;
	short	i_status_qual_ind;
	short	i_status_cd;
	short	i_reason_ql;
	short	i_reason_cd;
	short	i_support_ind;
} PRO_FAILCODES_STRUCT_I;




typedef struct {
	short	i_ct_clt;
	short	i_lr_detail;
	short	i_clt_type;
	short	i_clt_own;
	short	i_flag;
	short	i_own_ind;
} DL_LOCALREPCLIENT_STRUCT_I;




typedef struct {
	short	i_dealclass;
	short	i_dealcd;
	short	i_dtfld;
	short	i_status_active;
	short	i_dtname;
	short	i_indname;
	short	i_debit_flag;
	short	i_debit_ind_100;
	short	i_credit_flag;
	short	i_credit_ind_100;
	short	i_desc;
	short	i_info;
	short	i_iv_cond;
	short	i_local_iv_cond;
	short i_desc_a;
	short i_desc_b;
} DL_LOCALREPSPEC_STRUCT_I;




typedef struct {
	short	i_dltype;
	short	i_dlesc;
	short	i_nds_blk;
	short	i_nds_ind;
	short	i_dealcdmtx;
	short	i_clttype;
	short	i_block;
	short	i_new;
	short	i_clt_brk_all;
	short	i_deal_class_cd;
} DL_LOCALREPDEALTYPE_STRUCT_I;




typedef struct {
	short	i_nation;
	short	i_reg_st_cd;
	short	i_regstdetail;
	short	i_status_pos;
	short	i_updatepos;
	short	i_reg_aud_fun;
	short	i_man_stat;
	short	i_reg_short;
	short	i_new_reg_a;
	short	i_newt_reg_b;
	short	i_fldupdate;
	short	i_prev_reg;
} DL_REGCYCLE_STRUCT_I;




typedef struct {
	short	i_oldsecuritycd;
	short	i_newsecuritycd;
	short	i_creater;
	short	i_authoriser;
} DL_INSTRUMENTCHG_STRUCT_I;




typedef struct {
	short	i_mapclass;
	short	i_mapvalue;
	short	i_map_val;
} PRO_GMATCHVALUE_STRUCT_I;




typedef struct {
	short	i_securitycd;
	short	i_ct_clt;
	short	i_dl_client;
	short	i_openbalance;
	short	i_closing_bal;
	short	i_domcpclt_cd;
	short	i_lstsecdate;
} DL_LOCALREPSAFEK_STRUCT_I;




typedef struct {
	short	i_client_name;
	short	i_lr_dt;
	short	i_info;
} DL_LOCALREPDATES_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_sequenceno;
	short	i_securitycd;
	short	i_dlt;
	short	i_setldt;
	short	i_infos;
	short	i_frm_loc;
	short	i_to_location;
	short	i_sendmsg_ind;
	short	i_billable_flag;
	short	i_creater;
	short	i_create_dt;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_newdt;
	short	i_qty;
	short	i_df_txnr_iden;
	short	i_rf_dl_ident;
	short	i_dealstat;
	short	i_loc_chng_stat;
	short	i_timestamp;
	short	i_setl;
	short   i_uniq_ident_no;
	short   i_dfsettdate;
	short   i_rfsettdate;
} DL_LOCNCHG_STRUCT_I;




typedef struct {
	short	i_securitycd;
	short	i_positdate;
	short	i_loccode;
	short	i_dl_client;
	short	i_status_pos;
	short	i_stsafekeep_pos;
	short	i_safekeep_pos;
	short	i_nval_rec;
	short	i_nval_del;
	short	i_val_rec;
	short	i_val_del;
} DL_HISSAFEK_STRUCT_I;




typedef struct {
	short	i_prdt;
	short	i_securitycd;
	short	i_closing_pr;
	short	i_updtmode;
	short	i_creater;
	short	i_create_dt;
	short	i_mkrtpr_stat;
	short	i_authoriser;
	short	i_authoriserdt;
} MT_HISDLYMKTPRC_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_newdt;
	short	i_dlt;
	short	i_setldt;
	short	i_pr;
	short	i_ex_arena;
	short	i_amt;
	short	i_custodycomm;
	short	i_brokercomm;
	short	i_stx_comm;
	short	i_oth_comm;
	short	i_secdate;
	short	i_moneydate;
	short	i_qty;
	short	i_domcpclt_cd;
	short	i_isspotdl;
	short	i_origquantity;
	short	i_origamount;
	short	i_dlfromord;
	short	i_entry;
	short	i_reapired_ind;
	short	i_domcp_custodyclt;
	short	i_countclt;
	short	i_countcltnm;
	short	i_clientof;
	short	i_custinfo;
	short	i_fx_reqd;
	short	i_ispymtlocal;
	short	i_verfied_with;
	short	i_diffamount;
	short	i_brkrno;
	short	i_failreas_cd;
	short	i_failinfo;
	short	i_ispart_;
	short	i_fx_rt;
	short	i_amend_count;
	short	i_number_a;
	short	i_report_at_eom_ind;
	short	i_billdate;
	short	i_locindentity_no;
	short	i_instruct_person;
	short	i_rec_int_000;
	short	i_dealcd;
	short	i_securitycd;
	short	i_currencycode;
	short	i_classofdl;
	short	i_origindentity_no;
	short	i_creater;
	short	i_create_dt;
	short	i_deal_status;
	short	i_info1;
	short	i_loccode;
	short	i_regsec_ind;
	short	i_status_pos;
	short	i_status_reg;
	short	i_confdate;
	short	i_matchindentity_no;
	short	i_markfaildate;
	short	i_candropdate;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_secconv_ind;
	short	i_ndsbldate;
	short	i_lrdltype;
	short	i_ndsdate;
	short	i_ublckdate;
	short	i_delta_000;
	short	i_delta_001;
	short	i_delta_003;
	short	i_delrecdate;
	short	i_lastregdate;
	short	i_lr_chkdate;
	short	i_lr_confdate;
	short	i_lr_secdate;
	short	i_regmsgquantity;
	short	i_tmpoutdate;
	short	i_tmpretdate;
	short	i_transmitdate;
	short	i_complquantity;
	short	i_lostquantity;
	short	i_marktrfquantity;
	short	i_mcomplquantity;
	short	i_outregquantity;
	short	i_pendregquantity;
	short	i_retregquantity;
	short	i_stampquantity;
	short	i_tempoutquantity;
	short	i_tempretquantity;
	short	i_valdeedquantity;
	short	i_hostdate;
	short	i_lr_ndsbldate;
	short	i_clnt_clr_name;
	short	i_lr_ndsdate;
	short	i_secdetail;
	short	i_lr_ublckdate;
	short	i_domestic_cpclr_name;
	short	i_domcp_custodynm;
	short	i_number_b;
	short	i_closedate;
	short	i_clt_reqdel_flag;
	short	i_mod_hispos_ind;
   short i_instruct_personnm;
   short i_clientofcode;
   short i_inter_med_person;
   short i_inter_med_personnm;
   short i_fxccy;
} DL_HISDEAL_STRUCT_I;




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
	short	i_clnt_clr_name;
	short	i_secdetail;
	short	i_closedate;
} OR_HISORDER_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dlt;
	short	i_setldt;
	short	i_qty;
	short	i_pr;
	short	i_execdate;
	short	i_timestamp;
	short	i_brokercomm;
	short	i_tax_amount;
	short	i_reset_ind;
	short	i_orderindentity_no;
} OR_HISEXECORDER_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_srl_no;
	short	i_newdt;
	short	i_reg_st_cd;
	short	i_txndate;
	short	i_qty;
	short	i_quantitymoved;
	short	i_quantitymanifld;
	short	i_dtcltfor;
	short	i_prcsmrdate;
	short	i_status_prc;
	short	i_prcstldate;
	short	i_smramount;
} DL_HISREGDET_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_newdt;
	short	i_trail_for;
	short	i_processdetail;
	short	i_proc_usr;
	short	i_subprocess;
	short	i_logdate;
	short	i_failreas_cd;
	short	i_qty;
	short	i_dlfromord;
	short	i_subfailreas_cd;
} DL_HISDEALSAUDIT_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dlt;
	short	i_setldt;
	short	i_pr;
	short	i_ex_arena;
	short	i_amt;
	short	i_custodycomm;
	short	i_brokercomm;
	short	i_stx_comm;
	short	i_oth_comm;
	short	i_secdate;
	short	i_moneydate;
	short	i_qty;
	short	i_domcpclt_cd;
	short	i_isspotdl;
	short	i_origquantity;
	short	i_origamount;
	short	i_dlfromord;
	short	i_entry;
	short	i_reapired_ind;
	short	i_domcp_custodyclt;
	short	i_countclt;
	short	i_countcltnm;
	short	i_clientof;
	short	i_custinfo;
	short	i_fx_reqd;
	short	i_ispymtlocal;
	short	i_verfied_with;
	short	i_diffamount;
	short	i_brkrno;
	short	i_failreas_cd;
	short	i_failinfo;
	short	i_ispart_;
	short	i_fx_rt;
	short	i_amend_count;
	short	i_number_a;
	short	i_report_at_eom_ind;
	short	i_billdate;
	short	i_locindentity_no;
	short	i_instruct_person;
	short	i_rec_int_000;
	short	i_dealcd;
	short	i_securitycd;
	short	i_currencycode;
	short	i_classofdl;
	short	i_origindentity_no;
	short	i_newdt;
	short	i_creater;
	short	i_create_dt;
	short	i_deal_status;
	short	i_timestamp;
	short	i_info1;
	short	i_loccode;
	short	i_regsec_ind;
	short	i_status_pos;
	short	i_status_reg;
	short	i_confdate;
	short	i_matchindentity_no;
	short	i_markfaildate;
	short	i_candropdate;
	short	i_authoriser;
	short	i_authoriserdt;
	short	i_secconv_ind;
	short	i_ndsbldate;
	short	i_lrdltype;
	short	i_ndsdate;
	short	i_ublckdate;
	short	i_delta_000;
	short	i_delta_001;
	short	i_delta_003;
	short	i_delrecdate;
	short	i_lastregdate;
	short	i_lr_chkdate;
	short	i_lr_confdate;
	short	i_lr_secdate;
	short	i_regmsgquantity;
	short	i_tmpoutdate;
	short	i_tmpretdate;
	short	i_transmitdate;
	short	i_complquantity;
	short	i_lostquantity;
	short	i_marktrfquantity;
	short	i_mcomplquantity;
	short	i_outregquantity;
	short	i_pendregquantity;
	short	i_retregquantity;
	short	i_stampquantity;
	short	i_tempoutquantity;
	short	i_tempretquantity;
	short	i_valdeedquantity;
	short	i_hostdate;
	short	i_lr_ndsbldate;
	short	i_lr_ndsdate;
	short	i_lr_ublckdate;
	short	i_number_b;
	short	i_clt_reqdel_flag;
	short	i_mod_hispos_ind;
	short	i_updhispos_date;
	short	i_cash_client;
	short i_cpamt;
	short i_msg_stat;
	short	i_subfailreas_cd;
	short i_allow_part_s;
	short i_locchng_flg;
	short i_comm_indentity_no;
  	short i_instruct_personnm;
	short i_clientofcode;
	short i_inter_med_person;
	short i_inter_med_personnm;
	short i_fxccy;
	short i_uniq_ident_no;
	short cnt_548;
	short i_exp_setl_date;
	short i_related_indentity_no;
	short i_msec_isinfo;
	/*Retrofrom HDFC by Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
} SYS_DL_DEAL_STRUCT_I;

typedef struct
{
	short	i_dl_client;
	short i_securitycd;
	short i_rec_del;
	short i_qty;
	short i_amt;
	short i_act_dvp;
	short i_classofdl;
	short i_countclt;
} DL_CLHTR_STRUCT_I;


typedef struct
{
       short h_sequence_num;
       short h_sys_dt;
       short h_set_dt;
       short h_dl_client;
       short h_ext_clh_clt;
       short h_countclt;
       short h_sec_isin;
       short h_qty;
}DL_CLHCRI_STRUCT_I;



typedef struct
{
	short	i_securitycd;
	short	i_ctclt;
	short	i_dl_client;
	short	i_qty;
	short	i_domcpclt_cd;
} DL_LOCALREPPROC2_STRUCT_I;



typedef struct
{
	short i_securitycd;
	short i_ctclt;
	short i_qty;
	short i_domcpclt_cd;
	short i_sec_isin;
}  DL_LOCALREPPROC3_STRUCT_I;




typedef struct {
   short i_dl_client;
   short i_cltnm;
   short i_synclt;
   short i_clttyp;
   short i_clt_typ;
   short i_baseclt;
   short i_cltopdt;
   short i_cltcldt;
   short i_nostr_cltptyp;
   short i_nostr_clttyp;
   short i_creater;
   short i_create_dt;
   short i_authoriser;
   short i_authoriserdt;
   short i_timestamp;
   short i_newdt;
   short i_cltstatus;
} MT_RUCLIENT_STRUCT_I;





typedef struct {
   short i_loc;
	short i_locm;
	short i_syn_location;
	short i_license_no;
	short i_loc_class;
	short i_depo_cd;
	short i_baseloc;
	short i_locopdate;
   short i_loccldate;
   short i_nostr_cltptyp;
   short i_nostr_clttyp;
   short i_creater;
   short i_create_dt;
	short i_authoriser;
   short i_authoriserdt;
   short i_timestamp;
   short i_newdt;
   short i_rulocstatus_ind;
} MT_RULOC_STRUCT_I;





typedef struct {
   short i_pr_code;
	short i_prdetail;
	short i_ccy;
   short i_daydate;
   short i_day_yr;
   short i_prdateyp;
   short i_intclass;
   short i_loc;
   short i_creater;
   short i_create_dt;
   short i_authoriser;
   short i_authoriserdt;
   short i_timestamp;
   short i_newdt;
   short i_prodstatus_ind;
} MT_RUPROD_STRUCT_I;



typedef struct {
   short i_stat_reg_no;
	short i_securitycd;
	short i_secdetail;
	short i_identiy_num;
	short i_creater;
   short i_create_dt;
   short i_authoriser;
   short i_authoriserdt;
   short i_timestamp;
   short i_newdt;
   short i_srnstatus_ind;
} MT_RUSRN_STRUCT_I;



typedef struct {
   short i_securitycd;
	short i_sec_nm;
	short i_snm_ind;
	short i_stat_reg_no;
	short i_secopdate;
	short i_seccldate;
	short i_sec_cldate;
	short i_basesecurity;
   short i_sec_class;
	short i_pr_code;
	short i_creater;
	short i_create_dt;
   short i_authoriser;
   short i_authoriserdt;
   short i_timestamp;
   short i_newdt;
   short i_rusecstatus_ind;
} MT_RUSEC_STRUCT_I;

	







typedef struct {
	short i_positdate;
	short i_dl_client;
   short i_securitycd;
   short i_loccode;
	short i_st_reg_no;
   short i_safekeep_pos;
   short i_val_rec;
   short i_val_del;
} DL_RUHISSAFEK_STRUCT_I;




typedef struct {
    short i_mhlp_code;
    short i_lcl_brkcd;
    short i_lcl_opcd;
    short i_dl_client;
    short i_mstclt;
    short i_custodian_clt;
    short i_manual_ind_intn;
    short i_creater;
    short i_create_dt;
    short i_authoriser;
    short i_authoriserdt;
    short i_mhlp_stat;
    short i_timestamp;
    short i_lbrk_mstclt;
 } MHLP_CODE_STRUCT_I;

typedef struct {
	short i_dl_client;
	short i_setl_eff_date;
   short i_stat_eff_date;
   short i_ca_eff_date;
   short i_stmsg_eff_date;
   short i_timestamp;
}MS_MSGCONV_STRUCT_I;



typedef struct {
   short i_dl_client;
   short i_indentity_no;
   short i_securitycd;
   short i_ctclt;
   short i_dbclt;
   short i_domcpclt_cd;
   short i_qty;
   short i_dtfld;
   short i_r_code;
   short i_ord_ind;
   short i_lrdltype;
   short i_dealcd;
   short i_reset_ind;
} DL_LOCALREPROCMA_STRUCT_I;



typedef struct {
   short i_dealclass;
   short i_dealcd;
   short i_dtfld;
   short i_status_active;
   short i_dtname;
   short i_indname;
   short i_debit_flag;
   short i_debit_ind_100;
   short i_credit_flag;
   short i_credit_ind_100;
   short i_desc;
   short i_info;
   short i_iv_cond;
   short i_local_iv_cond;
	short i_desc_a;
	short i_desc_b;
} DL_LOCALREPSPECMA_STRUCT_I;



typedef struct {
   short i_ct_clt;
   short i_lr_detail;
   short i_clt_type;
   short i_clt_own;
   short i_flag;
   short i_own_ind;
} DL_LOCALREPCLIENTMA_STRUCT_I;



typedef struct {
   short i_securitycd;
   short i_ct_clt;
   short i_dl_client;
   short i_openbalance;
   short i_closing_bal;
   short i_domcpclt_cd;
   short i_lstsecdate;
} DL_LOCALREPSAFEKMA_STRUCT_I;

typedef struct  {
short i_dl_client;
short i_indentity_no;
short i_block_no;
short i_stat_qual;
short i_stat_reas;
short i_reason_ql;
short i_reason_cd;
short i_info;
short i_failreas_cd;
short i_subfailreas_cd;
short i_timestamp;
} DL_MULT_REAS_CODES_STRUCT_I;

typedef struct  {
short i_mem_ident;
short i_instr_clt;
short i_brkcd;
short i_alternate_bidcd;
short i_detailription;
short i_mtch_detail;
short i_status_ind;
short i_creater;
short i_create_dt;
short i_authoriser;
short i_authoriserdt;
short i_timestamp;
} PRO_HDAT_STATIC_STRUCT_I;

