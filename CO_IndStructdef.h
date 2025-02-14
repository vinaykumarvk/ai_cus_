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
 * Module Name         :		Maintenance
 *
 * File Name           :		CO_IndStructdef.h
 *
 * Description         :		Contains Indicator Structure Variable Definitions
 *										for all Structures Related to Maintenance
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description			RFS No.
 * ---------   --------	 ---------------  ---------------------	-----------
 *	10/10/2005		1.0		Smita Bhat				New File				 HDFCMT_003
 *  14/12/2005   1.3        Manik Trivedi        Indicator Structure  HDFCMT_008 
 *  16/12/2005   1.4        Anil                Indicator Structure  HDFCMT_009 
 *  20/12/2005   1.5        Dnyanesh            Indicator Structure  HDFCMT_012 
 *  21/12/2005   1.7        Dnyanesh            Indicator Structure  HDFCMT_014 
 *  21/12/2005   1.8        Dnyanesh            Indicator Structure  HDFCMT_007 
 *  26/12/2005   1.9       Sonali           	Indicator Structure  HDFCMT_013 
 *  26/12/2005   1.10       Sonali           	Indicator Structure  HDFCMT_016 
 *  03/01/2005	  1.11		 Smita Bhat				Ind Structure			HDFCMT_003
 *  													Changes for Instrument
 *  15/12/2005   1.12         Kouser Begum	    Contains Indicator Structure Variable	         HDFCMT_001
 *  10/01/2006	  1.13	      Pradeep					Indicator Structure	HDFCMT_017
 *  30/12/2005    1.14          Kouser Begum          Indicator Structure                         HDFCMT_010                                                          
 *  26/12/2005    1.15          Kouser Begum          Indicator Structure  HDFCMT_011 
 *  06/01/2006		1.16			Pradeep				Indicator Structure 	HDFCMT_004 
 *   07/01/2006   1.15        Sundar              Indicator Structure  HDFCMT_GFU
 *   08/02/2006	1.16			Smita Bhat				Changed Ind Variables		HDFCCA Base Version
 *   21/02/2006   1.19        Kouser Begum      New Maintenance          KB_001
 *	23/11/2006	1.20			Amol Kulkarni		Depo Upload			
 *********************************************************************/

















typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_instr_code;
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



/*
typedef struct {
	short	i_dlrep_sequencenum;
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dealcd;
	short	i_dlt;
	short	i_setldt;
	short	i_qty;
	short	i_instr_code;
	short	i_currencycode;
	short	i_domcpclt_cd;
	short	i_classofdl;
	short	i_pr;
	short	i_ex_arena;
	short	i_isspotdl;
	short	i_entry;
	short	i_newdt;
	short	i_maker;
	short	i_maker_dt;
	short	i_deal_status;
	short	i_access_stamp;
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
	short 	i_instr_name;
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
} DL_DEALREPAIR_STRUCT_I;
*/

typedef struct {
   short i_dl_client;
   short i_indentity_no;
   short i_amt;
   short i_instr_code;
   short i_qty;
   short i_setldt;
   short i_classofdl;
   short i_dealcd;
   short i_origindentity_no;
   short i_locindentity_no;
   short i_domcpclt_cd;
   short i_countclt;
   short i_countcltnm;
   short i_instrdate;
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
	short	i_frm_instr_code;
	short	i_dl_client;
	short	i_to_instrurity;
	short i_conv_dt;
} DL_INSTRUMENTCONV_STRUCT_I;

typedef struct {
	short	i_indentity_no;
	short	i_dl_client;
	short	i_dl_class;
	short i_instr_code;
	short i_loccode;
	short i_qty;
} DL_INSTRUMENTCONV_REP_TEMP_STRUCT_I;

/* By Harvinder Singh for RFS_CLN_MAP_001 Date - 7/3/2007 */
 typedef struct{
 	short i_cln_code;
 	short i_cln_master;
 	short i_wi_login;
 	short i_login_rights;
 	short i_auto_auth;
	short i_authorizer;
 	short i_maker;
 	short i_access_stamp;
 }WI_CLIENT_MAP_STRUCT_I;


typedef struct {
	short	i_dl_client;
	short	i_indentity_no;
	short	i_dealcd;
	short	i_dlt;
	short	i_setldt;
	short	i_instr_code;
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
	short	i_access_stamp;
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
	short	i_instr_code;
	short	i_amt;
	short	i_pr;
	short	i_newdt;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
	short	i_countcltnm;
	short	i_misdeal_status;
	short	i_countclt;
	short	i_maker;
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
	short	i_instr_code;
	short	i_open_pr;
	short	i_closing_pr;
} MT_MTHLYMKTPRC_STRUCT_I;




typedef struct {
	short	i_prdt;
	short	i_instr_code;
	short	i_closing_pr;
	short	i_updtmode;
	short	i_access_stamp;
	short	i_maker;
	short	i_maker_dt;
	short	i_mkrtpr_stat;
	short	i_checker;
	short	i_checker_dt;
} MT_DLYMKTPRC_STRUCT_I;




typedef struct {
	short	i_ibbsclt;
	short	i_cash_bal;
} DL_CASHBAL_STRUCT_I;




typedef struct {
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
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
	short	i_access_stamp;
	short	i_brokercomm;
	short	i_tax_amount;
	short	i_reset_ind;
	short	i_orderindentity_no;
} OR_EXECORDER_STRUCT_I;




typedef struct {
	short	i_instr_code;
	short	i_loccode;
	short	i_dl_client;
	short	i_access_stamp;
	short	i_status_pos;
	short	i_stsafekeep_pos;
	short	i_safekeep_pos;
	short	i_nval_rec;
	short	i_nval_del;
	short	i_val_rec;
	short	i_val_del;
 short i_dp_rec;
 short i_dp_del;
 short i_block_type;
} DL_SAFEK_STRUCT_I;

typedef struct {
   short     i_dl_client;
   short     i_instr_code;
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
	short	i_access_stamp;
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


/* Kouser - Client Master Maintenance - RFSNo - HDFCMT_001  */
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
	short	i_access_stamp;
	short	i_holdings;
    	short   i_schsequence_num;
	short	i_iso_msg_format;
	short	i_validate_flag;
        short i_cln_msg_resp_cons54x;
        short i_cln_msg_gen_rec_dp; 
        short i_maker; 
        short i_maker_dt; 
        short i_checker; 
        short i_checker_dt;
        short i_status; 
} MT_MSGADDRESS_STRUCT_I;

typedef struct {
 short	i_dl_client; 
 short	i_cln_sebi_reg_no; 
 short	i_cln_sebi_reg_dt; 
 short	i_cln_sebi_reg_expdt; 
 short	i_cln_rbi_reg_no;
 short	i_cln_rbi_reg_dt; 
 short	i_cln_rbi_reg_expdt; 
 short	i_cln_mapinid; 
 short	i_cln_ucc_code; 
 short	i_access_stamp; 
 short	i_maker; 
 short	i_maker_dt; 
 short	i_checker; 
 short	i_checker_dt; 
 short   i_status;
 short   i_sebi_sub_acc;
} MT_REGDETAILS_STRUCT_I;
/* Kouser - Client Master Maintenance - RFSNo - HDFCMT_001 */


typedef struct {
	short	i_currencycode;
	short	i_denom_currencycode;
	short	i_rtdt;
	short	i_exchgrt;
	short	i_rate_buy;
	short	i_sellae_rate;
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
	short	i_status;
} MT_EXCHRATE_STRUCT_I;

/*Smita - HDFCMT_003 - Instrument Master Maintenance */
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
	/*Smita - Commeneted Effective Date & Cut Off Time - HDFCMT_003 
	short i_instr_pc_effdt;
	short i_instr_pc_cutofftime;
	*/
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
	short i_instr_sub_type;
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
} MT_INSTRUMENT_RED_DEP_STRUCT_I;

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
	short i_scrip_code; /* Added  by rahul6 For T0 End */
} MT_INSTRUMENT_EXCH_STRUCT_I;

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
} MT_INSTRUMENT_CR_AGENCY_STRUCT_I;

typedef struct{
	short i_instr_code;
	short i_instr_seq_num;
	short i_pc_flag;
	short i_pc_date;
	short i_pc_notice_date;
	/*Smita - Added Effective Date & Cut Off Time - HDFCMT_003 */
	short i_instr_pc_effdt;
	short i_instr_pc_cutofftime;
	/*Smita - Added Effective Date & Cut Off Time - HDFCMT_003 */
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
} MT_INSTRUMENT_PC_STRUCT_I;

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
} MT_INSTRUMENT_PART_RED_STRUCT_I;

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
	short i_ptc_bal_val;
} MT_INSTRUMENT_PTC_STRUCT_I;

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
} MT_INSTRUMENT_RESET_STRUCT_I;

/*Added Indicator Structure for Credit Rating Agency Master*/
typedef struct {
		short i_agency_code;
		short i_agency_name;
		short i_agency_addr1;
		short i_agency_addr2;
		short i_agency_city;
		short i_agency_state;
		short i_addr_cnt;
		short i_addr_pin;
		short i_agency_tel;
		short i_agency_fax;
		short i_agency_email;
		short i_maker;
		short i_maker_dt;
		short i_access_stamp;
		short i_checker;
		short i_checker_dt;
		short i_status;
	} MT_CR_AGENCY_STRUCT_I;

typedef struct {
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
                
	} MT_CR_AGENCY_DET_STRUCT_I;

/*Smita - HDFCMT_003 - Instrument Master Maintenance */

/* Kouser  - HDFCMT_010 - Depository Participant Maintenance */

typedef struct{
        short i_depo_code;
        short i_depo_part_code;
        short i_depo_part_contact1;
        short i_depo_part_add_1;
        short i_depo_part_add_2;
        short i_depo_part_add_city;
        short i_depo_part_add_state;
        short i_depo_part_add_cnt;
        short i_depo_part_add_pin;
        short i_depo_part_tel;
        short i_depo_part_fax;
        short i_depo_part_email;
        short i_maker;
        short i_maker_dt;
        short i_access_stamp;
        short i_checker;
        short i_checker_dt;
        short i_status;
        short i_depo_name;/* Added By Gouse for Depo Participant Name in Depo Participant Master - by Gouse */
}MT_DEPO_PART_STRUCT_I;

typedef struct{
        short i_depo_code;
        short i_depo_part_code;
        short i_exch_code;
        short i_cc_id;
        short i_cm_cc_id;
        short i_cln_id;
        short i_dp_id;
        short i_maker;
        short i_maker_dt;
        short i_access_stamp;
        short i_checker;
        short i_checker_dt;
        short i_status;
}MT_EXCH_DEPO_STRUCT_I;

/* Kouser  - HDFCMT_010 - Depository Participant Maintenance */


typedef struct {
	short	i_loccode;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_access_stamp;
	short	i_status_pos;
	short	i_manifld_ind;
	short	i_status;
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
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
	short	i_status;
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
	short	i_instr_code;
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
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
	short	i_maker;
	short	i_maker_dt;
	short i_access_stamp;
	short i_status_ind;
	short i_checker;
	short i_checker_dt;
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
	short i_access_stamp;
	short i_pend_ind;
	short i_weeklystmt;
	short i_validate_flag;
 /* Kouser - Client Master Maintenance - RFSNo - HDFCMT_001 */
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
} MT_SCHDET_STRUCT_I;

typedef struct {
	short	i_dl_client;
	short	i_cln_exch_code;
	short	i_cln_exch_map_code;
	short	i_cln_hdfc_cm_id;
	short	i_access_stamp;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
 short i_cln_exchseq_num;
	short	i_status;
        short   i_slb_exch_map_code;     /* SLB CHGS Ashish 01-04-2008 */
}MT_CLTEXCHMAP_STRUCT_I;

/*Added by Prateek on 22052014 for ISKB_198(FPI Maintenance)-START*/

typedef struct {
	short	i_dl_client;
	short	i_nsdl_grp_id;
	short	i_nsdl_grp_name;
	short	i_customer_id;
	short	i_holders;
	short	i_other_holders;
	short	i_kyc_exp_dt;
	short	i_remark;
	short	i_access_stamp;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_cln_exchseq_num;
	short	i_status;
}MT_CLTFPIMAP_STRUCT_I;

/*Added by Prateek on 22052014 for ISKB_198(FPI Maintenance)-END*/

/* Kouser - Client Master Maintenance - RFSNo - HDFCMT_001 */

typedef struct {
	short	i_dl_client;
	short	i_cln_depo_code;
	short	i_cln_depo_map_clnt_id;
	short	i_cln_depo_map_dp_id;
	short	i_access_stamp;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
    short   i_cln_deposeq_num;
	short	i_status;
	short   i_cmbp_id; /*ADDED BY SIMAR FOR PMS UPLOAD ISKB_12434 */
}MT_CLTDEPOMAP_STRUCT_I;

typedef struct {
 short i_grp_class;
 short i_grp_email;
 short i_grp_contct1;
 short i_grp_contct2;
 short i_grp_sebi_ctg;
 short i_grp_pan;
 short i_grp_agency;
 short i_grp_code;
}MT_CLTGRPMAP_STRUCT_I;

/* Kouser - Client Master Maintenance - RFSNo - HDFCMT_001 */

 /* Kouser - Maintenance - RFSNo - KB_001 */

 typedef struct {
 short i_cln_code;
 short i_acc_opn_dt;
 short i_acc_actv_dt;
 short i_acc_cls_dt;
 short i_cert_pub_acc;
 short i_fund_acc_mgr;
 short i_spf_flg;
 short i_spf_det;
 short i_access_stamp;
 short i_maker;
 short i_maker_dt;
 short i_checker;
 short i_checker_dt;
 short i_status;
 short i_tolerance_limit;
 /*CHITRLEKHA Client Additional Details STARTS*/
 short i_effective_dt;	
 short i_sec_cert_pub_acc;
 short i_fatca1;	
 short i_fatca2;	
 short i_fatca3;	
 /*CHITRLEKHA Client Additional Details ENDS*/
 /*PANITH CSGL STARTS*/
 short i_lei_number;
 short i_ckyc_number;
 short i_lei_date;
 short i_lei_exp_date;
 /*PANITH CSGL ENDS*/
 }MT_CLN_ADDLN_DET_STRUCT_I;

 /* Kouser - Maintenance - RFSNo - KB_001 */

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
	short	i_instr_isinuseflg;
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
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
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
	short i_authbunch_ind;
	short i_fxpurchasecurrency;
	short i_fxsalecurrency;
	short i_single548_support_ind;
	short i_stat_tran_flag;
	short i_trad_sett_flag;
   short i_rhts_ret;   
   short i_valcredit;
	short i_keep_fracredit_flag; 
 short i_auto_canc_ind; 
	short i_cltdetail;
	short i_generate_flag;
  short i_cln_add_2;
 short i_cln_add_city;
 short i_cln_add_state;
 short i_cln_add_pin;
 short i_cln_tel;
 short i_cln_fax;
 short i_cln_email;
 short i_cln_cntact1;
 short i_cln_cntact2;  
 short i_cln_sebi_ctg;
 short i_cln_pan;
 short i_cln_tds_rate;
 short i_cln_glb_cust;
 short i_cln_start_dl;
 short i_cln_bcn_req;
 short i_cln_def_cr_agency;
 short i_cln_cust_id_ent;
 short i_cln_mst_ind;
 short i_cln_sign_memo;
 short i_cln_sign_img;
  /* Ramya - start */
 short i_cln_sebi_subcat;
 short i_cln_country;
 short i_clncity_desc;
 /* Ramya - end */
} MT_CLIENT_STRUCT_I;

/*Chirag Client Cloning 070606*/
typedef struct {
short i_dl_to_client;
short i_dl_frm_client;
short i_clnt_clr_name;
}MT_CLIENT_CLN_STRUCT_I;

/*Chirag Client Cloning 070606*/


typedef struct {
	short	i_currencycode;
	short	i_ccydetail;
	short	i_maker;
	short	i_dec_len;
	short	i_maker_dt;
	short	i_access_stamp;
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
	short	i_oldinstr_code;
	short	i_newinstr_code;
	short	i_maker;
	short	i_checker;
} DL_INSTRUMENTCHG_STRUCT_I;




typedef struct {
	short	i_mapclass;
	short	i_mapvalue;
	short	i_map_val;
} PRO_GMATCHVALUE_STRUCT_I;




typedef struct {
	short	i_instr_code;
	short	i_ct_clt;
	short	i_dl_client;
	short	i_openbalance;
	short	i_closing_bal;
	short	i_domcpclt_cd;
	short	i_lst_instr_date;
} DL_LOCALREPSAFEK_STRUCT_I;




typedef struct {
	short	i_client_name;
	short	i_lr_dt;
	short	i_info;
} DL_LOCALREPDATES_STRUCT_I;




typedef struct {
	short	i_dl_client;
	short	i_sequenceno;
	short	i_instr_code;
	short	i_dlt;
	short	i_setldt;
	short	i_infos;
	short	i_frm_loc;
	short	i_to_location;
	short	i_sendmsg_ind;
	short	i_billable_flag;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_newdt;
	short	i_qty;
	short	i_df_txnr_iden;
	short	i_rf_dl_ident;
	short	i_dealstat;
	short	i_loc_chng_stat;
	short	i_access_stamp;
	short	i_setl;
	short   i_uniq_ident_no;
	short   i_dfsettdate;
	short   i_rfsettdate;
	short   i_frm_type;
	short   i_to_type;
	short   i_change;
	short   i_unblock_date;
	short   i_trans_type;
} DL_LOCNCHG_STRUCT_I;




typedef struct {
	short	i_instr_code;
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
	short	i_instr_code;
	short	i_closing_pr;
	short	i_updtmode;
	short	i_maker;
	short	i_maker_dt;
	short	i_mkrtpr_stat;
	short	i_checker;
	short	i_checker_dt;
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
	short	i_instrdate;
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
	short	i_instr_code;
	short	i_currencycode;
	short	i_classofdl;
	short	i_origindentity_no;
	short	i_maker;
	short	i_maker_dt;
	short	i_deal_status;
	short	i_info1;
	short	i_loccode;
	short	i_reginstr_ind;
	short	i_status_pos;
	short	i_status_reg;
	short	i_confdate;
	short	i_matchindentity_no;
	short	i_markfaildate;
	short	i_candropdate;
	short	i_checker;
	short	i_checker_dt;
	short	i_instrconv_ind;
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
	short	i_lr_instrdate;
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
	short	i_instr_name;
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
	short	i_instr_code;
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
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
	short	i_instr_name;
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
	short	i_access_stamp;
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
	short	i_instrdate;
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
	short	i_instr_code;
	short	i_currencycode;
	short	i_classofdl;
	short	i_origindentity_no;
	short	i_newdt;
	short	i_maker;
	short	i_maker_dt;
	short	i_deal_status;
	short	i_access_stamp;
	short	i_info1;
	short	i_loccode;
	short	i_reginstr_ind;
	short	i_status_pos;
	short	i_status_reg;
	short	i_confdate;
	short	i_matchindentity_no;
	short	i_markfaildate;
	short	i_candropdate;
	short	i_checker;
	short	i_checker_dt;
	short	i_instrconv_ind;
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
	short	i_lr_instrdate;
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
	short i_minstr_isinfo;
	/* new fields added - HDFCDL_003 - Sundar */
	short i_settlement_no;
	short i_mkt_type;
	short i_clh_flg;
	short i_interest;
	short i_net_amt;
	short i_payin_dt;
	short i_payout_dt;
	short i_demat_qty;
	short i_contract_req;
	short i_excum_flg;
	short i_crn_no;
	short i_interfii_flg;
	short i_pay_mode;
	short i_dl_secstatus;
	short i_dl_mnystatus;
	short i_avail_qty;
	short i_allot_qty;
	short i_shortage_qty;
	short i_cln_depoacc;
	short i_pltopl_flg;
	short i_orig_status;
	short i_map_failcode;
	short i_match_failcode;
	short i_is_matched;
	short i_exch_code;
	short i_contract_cd;
   short i_r_delay;
   short i_sebi_reported;
   short i_r_sett_code;
   short i_r_trans_code;
   short i_r_type;
   short i_repo_date;
	short i_comm_amt;   /***** For Detailed bill printing : vinay kalaskar ****/
	short i_mf_seqno;  /***** For BillGeneration :vinay kalaskar **********/
	/*Retro from HDFC by Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */ 
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
	
	/* Added by RAHUL for adding CSGL - Starts */
	
	short i_dpm_trans_ref_no;
	short i_other_charges;
	short i_csgl_trade_type;
	/* Added by RAHUL for adding CSGL - END */
	
} SYS_DL_DEAL_STRUCT_I;
	/* new fields added - HDFCDL_003 - Sundar */
/* Gouse - Single Prematch [Start] */
typedef struct{
        short i_dl_client;
        short i_identiy_no;
        short i_confdate;
	short i_exp_settl_date;
        short i_verified_with;
        short i_info1;
	short i_diffamount;
        short i_ispartial;
        short i_broker_ord_no;
	short i_orig_identiy_no;
	short i_loc_ref_no;
        short i_newquantity;
        short i_newamount;
        short i_cpamt;
	short i_brok_cmbp_id;
	short i_brok_dp_id;
//	short i_broker_dp_id;
//	short i_broker_cmbp_id;
	short i_cp_dp_id;
	short i_cp_client_id;
	short i_mkt_type;
	short i_location_cd;
	short i_execution_date;
	short i_dp_instr_flag;
	short i_inter_dp_flag;
//	short i_loc_cd;
//	short i_exec_dt;
//	short i_dp_instr_flg;
//	short i_inter_dp_flg;
	short i_defer_sec_sett_flg;
	short i_defer_mon_sett_flg;
        short i_maker;
        short i_maker_dt;
        short i_access_stamp;
        short i_checker;
        short i_checker_dt;
        short i_status;
}DL_SINGLE_PREMATCH_STRUCT_I;
/* Gouse - Single Prematch [End] */

typedef struct
{
	short	i_dl_client;
	short i_instr_code;
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
       short h_instr_isin;
       short h_qty;
}DL_CLHCRI_STRUCT_I;



typedef struct
{
	short	i_instr_code;
	short	i_ctclt;
	short	i_dl_client;
	short	i_qty;
	short	i_domcpclt_cd;
} DL_LOCALREPPROC2_STRUCT_I;



typedef struct
{
	short i_instr_code;
	short i_ctclt;
	short i_qty;
	short i_domcpclt_cd;
	short i_instr_isin;
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
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
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
   short i_maker;
   short i_maker_dt;
	short i_checker;
   short i_checker_dt;
   short i_access_stamp;
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
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
   short i_newdt;
   short i_prodstatus_ind;
} MT_RUPROD_STRUCT_I;



typedef struct {
   short i_stat_reg_no;
	short i_instr_code;
	short i_instr_name;
	short i_identiy_num;
	short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
   short i_newdt;
   short i_srnstatus_ind;
} MT_RUSRN_STRUCT_I;



typedef struct {
   short i_instr_code;
	short i_instr_nm;
short i_snm_ind;
short i_stat_reg_no;
	short i_instr_opdate;
	short i_instrcldate;
	short i_instr_cldate;
	short i_baseinstrument;
   short i_instr_class;
short i_pr_code;
	short i_maker;
	short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
short i_newdt;
   short i_ruinstrstatus_ind;
} MT_RUINSTR_STRUCT_I;

	







typedef struct {
	short i_positdate;
	short i_dl_client;
   short i_instr_code;
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
    short i_maker;
    short i_maker_dt;
    short i_checker;
    short i_checker_dt;
    short i_mhlp_stat;
    short i_access_stamp;
    short i_lbrk_mstclt;
 } MHLP_CODE_STRUCT_I;

typedef struct {
	short i_dl_client;
	short i_setl_eff_date;
   short i_stat_eff_date;
   short i_ca_eff_date;
   short i_stmsg_eff_date;
   short i_access_stamp;
}MS_MSGCONV_STRUCT_I;



typedef struct {
   short i_dl_client;
   short i_indentity_no;
   short i_instr_code;
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
   short i_instr_code;
   short i_ct_clt;
   short i_dl_client;
   short i_openbalance;
   short i_closing_bal;
   short i_domcpclt_cd;
   short i_lst_instr_date;
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
short i_access_stamp;
} DL_MULT_REAS_CODES_STRUCT_I;

typedef struct  {
short i_mem_ident;
short i_instr_clt;
short i_brkcd;
short i_alternate_bidcd;
short i_detailription;
short i_mtch_detail;
short i_status_ind;
short i_maker;
short i_maker_dt;
short i_checker;
short i_checker_dt;
short i_access_stamp;
} PRO_HDAT_STATIC_STRUCT_I;
 typedef struct {
short i_cmp_code;
short i_cmp_name;
short i_cmp_shortnm;
short i_cmp_old_name;
short i_cmp_add1;
short i_cmp_add2;
short i_cmp_add_city;
short i_cmp_add_state;
short i_cmp_add_cnt;
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
short i_cmp_maker;
short i_cmp_maker_dt;
short i_access_stamp;
short i_cmp_checker;
short i_cmp_checker_dt;
short i_cmp_status;
} MT_COMPANY_STRUCT_I;
/* ANIL HDFCMT_005 client_instrument */
typedef struct {
short i_cln_code;
short i_instr_code;
short i_cln_instr_code;
short i_maker;
short i_maker_dt;
short i_access_stamp;
short i_checker;
short i_checker_dt;
short i_status;
} MT_CLN_INSTR_STRUCT_I;

/*ANIL HDFCMT_006 Instruction Slip */
typedef struct  {
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
short i_checker;
short i_checker_dt;
short i_access_stamp;
short i_status;
} MT_INSL_ENTRY_STRUCT_I;


/* Manik Trivedi, HDFCMT_008 */

typedef struct
{
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
}
MT_SETTLCAL_STRUCT_I;

/* Anil, HDFCMT_009 */

typedef struct  {
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
} MT_DLYQTIONS_STRUCT_I;

/* HDFCMT_012 Daily Float Rate - Dnyanesh*/

typedef struct
{
   short i_benchmark_code;
   short i_rate_date;
   short i_float_rate1;
   short i_float_rate2;
   short i_float_rate3;
   short i_std_deviation;
   short i_maker;
   short i_maker_dt;
   short i_access_stamp;
   short i_checker;
   short i_checker_dt;
   short i_status;
}
MT_DLFLRATE_STRUCT_I;

/* HDFCMT_014 RBI Monitory Details - Dnyanesh*/

typedef struct
{
	short   i_instr_code;
	short   i_rbi_instr_code;
	short   i_tpcapital;
	short   i_sng_fii_limit;
	short   i_ovr_fii_limit;
	short   i_sng_nriocb_limit;
	short   i_ovr_nriocb_limit;
	short   i_caution_flg;
	short   i_caution_fii;
	short   i_caution_nriocb;
	short   i_maker;
	short   i_maker_dt;
	short   i_access_stamp;
	short   i_checker;
	short   i_checker_dt;
	short   i_status;
        short   i_def_cln_type;
	short   i_far; /*added by rahul6 for T0*/
}
MT_RBIMONDET_STRUCT_I;

/* HDFCMT_007 No Delivery Details - Dnyanesh*/
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

/*HDFCMT_013 Float Rate Instrument - Sonali */

typedef struct
{
   short     i_instr_code;
   short     i_daily_compound;
   short     i_excl_holidays;
   short     i_int_pay_days;
   short     i_compounding_wdays;
   short     i_floor_rate;
   short     i_cap_rate;
   short     i_prefd_seq;
   short     i_default_float_rate;
   short     i_benchmark_code;
   short     i_base_margin;
   short     i_fixed_bench;
   short     i_maker;
   short     i_maker_dt;
   short     i_access_stamp;
   short     i_checker;
   short     i_checker_dt;
   short     i_status;
}
MT_FLRATEINST_STRUCT_I;

/*HDFCMT_013 Float Rate Instrument - Sonali */

/*HDFCMT_016 Static Master - Sonali*/
typedef struct{
	short i_code_ident;
	short i_code_value;
	short i_code_desc;
	short i_country_code;
}CO_STATIC_DATA_STRUCT_I;
/*HDFCMT_016 Static Master - Sonali*/

/* HDFCMT_017 INDEX FUND MASTER Pradeep */
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
/* HDFCMT_017 INDEX FUND MASTER Pradeep */

/* HDFCMT_004 - Party Master - Pradeep */
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
}MT_PARTY_STRUCT_I;

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
	short i_pty_sebi_reg_no1;/* Kouser - HDFCMT_004 - New Cols */
	short i_pty_sebi_reg_no2;/* SebiRegNo1,SebiRegNo2 Added */
}MT_PTY_EXCH_MAP_STRUCT_I;

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
/*Abhijeet (20/05/2006) 2 new Field CMBP_ID and EXCH_CODE added*/
        short i_exch_code;
        short i_cmbp_id;       
}MT_PTY_DEPO_MAP_STRUCT_I;

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

/* HDFCMT_GFU Vendor Maintenance - Sundar */

typedef struct{
	short i_vendor_code;
	short i_vendor_name;
	short i_add_line1;
	short i_add_line2;
	short i_country_code;
	short i_state_code;
	short i_city_code;
	short i_pin_code;
	short i_fax_no;
	short i_tel_no;
	short i_web_address;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_GFU_VENDOR_SETUP_STRUCT_I;

typedef struct{
	short i_vendor_id;
	short i_function_id;
	short i_file_type;
	short i_copy_exist;
	short i_delimeter;
	short i_ref_no;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_skip_line;
	short i_format_line;
	short i_header_pos;
	short i_header_chk;
	short i_module_name;	/** Added by Sana for GFU Setup **/
}MT_GFU_FORMAT_SETUP_STRUCT_I;

typedef struct{
	short i_ref_no;
	short i_excel_field_name;
	short i_excel_reference_value;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_GFU_EXCEL_SETUP_STRUCT_I;

typedef struct{
	short i_ref_no;
	short i_txt_field_name;
	short i_start_pos;
	short i_end_pos;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_GFU_TXT_SETUP_STRUCT_I;

typedef struct{
	short i_ref_no;
	short i_csv_field_name;
	short i_csv_reference_value;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}MT_GFU_CSV_SETUP_STRUCT_I;

/* HDFCMT_GFU Vendor Maintenance - Sundar */

/* Bageshri  - MT Party Fund Details 27/04/06 */

typedef struct{
	short i_pty_code;
	short i_pay_in_day;
	short i_pay_out_day;
	short i_acc_typ;
	short i_pay_in_acc;
	short i_pay_out_acc;
	short i_acc_code1;
	short i_acc_code2;
	short i_acc_code2desc;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_pty_bnk_acc;
}MT_PTY_FUND_DET_STRUCT_I;

 /* Bageshri  - MT Party Fund Details 27/04/06 */


/************************************ DL_REPAIR STRUCTURE *******************************************/
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
	/************** New fields Added by sundar - 090506 *************************/
	short i_exch_code;
	short mkt_type;
	short i_interfii_flg;
	short i_clh_flg;
	short i_settlement_no;
	short i_payin_dt;
	short i_payout_dt;
	short i_net_amt;
	/************** New fields Added by sundar - 090506 *************************/
	/*Retro from HDFCby Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
	short i_dpm_trans_ref_no;
	short i_other_charges;
	short i_csgl_trade_type;
}DL_DEALREPAIR_STRUCT_I;

/*******************************************************************************************************/


typedef struct{
	short i_client;
	short i_identiy_no;
	short i_qty;
	short i_dp_id;
	short i_access_stamp;
}DL_BIFDET_STRUCT_I;


/* HDFCDL_004 BCN Maintenance  - Sundar */
typedef struct{
	short i_contract_cd;
	short i_mkt_type;
	short i_tran_type;
	short i_dl_date;
	short i_dl_price;
	short i_brokercomm;
	short i_exch_cd;
	short i_deal_cd;
	short i_clh_flg;
	short i_sebi_reg_no;
	short i_broker_cd;
	short i_client_cd;
	short i_qty;
	short i_instr_cd;
	short i_settlement_no;
	short i_dl_amt;
	short i_brokerage_amt;
	short i_stt_amt;
	short i_settlment_amt;
	short i_dl_ref_no;
	short i_inter_fii_flg;
	short i_sebi_reported;
	short i_entry;
	short i_repaired_ind;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_sett_dt;
	short i_narrative;
	short i_off_market;
	short i_counter_pty;
	short i_r_trans_code;
	short i_r_sett_code;
	short i_r_delay;
	short i_r_type;
	short i_repo_date;
  /* added by abhijeet 19/04*/
	short i_failreason_cd;
	short i_sub_fail_cd;
	/* Kouser - Add 1 field for RegReport */
	short i_lr_valdate;
	/*Vedavati added for 548 Mesage*/
	short i_addr_frm;
	short i_addr_to;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
}DL_BCN_STRUCT_I;
/* HDFCDL_004 BCN Maintenance  - Sundar */


/***********************ADDED BY AMISH *********/
/*********TAKE OVER**************************/
typedef struct{
	short i_ref_no;
	short i_ci_no;
	short i_instr_cd;
	short i_qty;
	short i_phy_flg;
	short i_takeover_qty;
	short i_depository;
	short i_status;
	short i_maker;
	short i_makerdt;
	short i_checker;
	short i_checkerdt;
	short i_accesstamp;
	short i_comments;
	short i_serial_no;
}DL_TAKEOVER_STRUCT_I;

typedef struct
{
	short i_takeover_date;
	short i_cln_code;
	short i_ref_no;
	short i_takeover_comments;
}DL_TAKEOVER_SEQ_STRUCT_I;	

/***********MARK SHORTAGE*********/

typedef struct{
	short i_settlement_no;
	short i_dl_client;
	short i_dl_ref_no;
	short i_instr_code;
	short i_qty;
	short i_avail_qty;
	short i_allot_qty;
	short i_shortage_qty;
	short i_pool_trans;
	short i_status;
	short i_access_stamp;
	short i_checker;
	short i_maker;
	short i_maker_dt;
	short i_checker_dt;
	short i_depo_cd; /* changes by amish -24/05 */
	short i_dp_id;
	short i_filebatch_no; /* changes by amish -25/05 */
	short i_mkt_type; //T1 Settlement changes CS0083803
	short i_exch_code; //T1 Settlement changes CS0083803
}DL_MARKSHORTAGE_STRUCT_I;


/* HDFCDL_015  DL_Sqoff - Sundar */

typedef struct{
	short i_exch_code;
	short i_settlemt_no;
	short i_payin_dt;
	short i_payout_dt;
	short i_dl_ref_no;
	short i_cln_code;
	short i_sqoff_ref_no;
	short i_instr_code;
	short i_deal_qty;
	short i_bal_qty;
	short i_sqoff_qty;
	short i_sqoff_amt;
	short i_bank_code;
	short i_chq_no;
	short i_chq_dt;
	short i_prn_amt;
	short i_ca_ref_no;
	short i_ca_amt;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_status;
	short i_deal_cd; /* changes by amish -24/05 */
}DL_SQOFF_STRUCT_I;
/* HDFCDL_015  DL_Sqoff - Sundar */

typedef struct{
   short i_dealfield;
   short i_comp_field;
   short i_apltol;
   short i_lmt;
   short i_exchng;
   short i_usefield;
   short i_proc_ind;
	short i_failreason_cd;
	short i_sub_fail_cd;

}MATCHING_MASTER_STRUCT_I;

typedef struct{
short i_client;
short i_exch_code;
short i_settlement_no;
short i_mkt_type;
short i_instr_code;
short i_brk_no;
short i_deal_cd;
short i_deal_date;
short i_identiy_no;
short i_brokercomm;
}DL_DEAL_BRKG_STRUCT_I;

typedef struct{
	short i_order_no;
	short i_exchg_code;
	short i_cln_code;
	short i_instr_code;
	short i_broker_cd;
	short i_qty;
	short i_settl_no;
	short i_dl_price;
	short i_dl_amt;
	short i_deal_date;
	short i_mkt_type;
	short i_scrip_grp;
	short i_creation_type;
	short i_deal_ref_no;
	short i_buy_sell_flg;
	short i_matched;
	short i_access_stamp;
	short i_status;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_filelinkinfo;
	short i_rowsequence;
	short i_is_nodelv;/*For no Delivery Process By: vinay */
	short i_nodelv_repdate;/*For no Delivery Process By: vinay */
	short i_order_data;/*For no Delivery Process By: vinay */
	short i_exch_instr_code;/*For Exchange Instrument Code: Rahul */
	short i_cp_code ;  /* Chages by rahul6 for T0 Enhancement */
}DL_EXCHGORD_UPLD_STRUCT_I;

typedef struct{
short i_client;
short i_identiy_no;
short i_deal_date;
short i_cost;
short i_exch_code;
short i_amount;
short i_brokercomm;
short i_stx_comm;
short i_purchase;
short i_sale;
short i_net_amt;
short i_qty;
short i_brk_no;
short i_deal_cd;
short i_instr_code;
short i_settlement_no;
short i_mkt_type;
short i_payable_acc;
short i_start_date;
short i_end_date;
short i_pay_out_dt;
short i_pay_in_dt;
short i_cln_name;
short i_cln_add_1;
short i_cln_add_2;
short i_cln_add_pin;
short i_city;
short i_stamp_duty;
}
SYS_DL_FUNDOBL_STRUCT_I;

typedef struct{
short i_client;
short i_identiy_no;
short i_deal_date;
short i_cost;
short i_exch_code;
short i_amount;
short i_brokercomm;
short i_stx_comm;
short i_qty;
short i_brk_no;
short i_brk_name;
short i_deal_cd;
short i_instr_code;
short i_settlement_no;
short i_mkt_type;
short i_deal_link_no;
short i_oblg_type;
short i_acc_ent_ind;
short i_net_amt;
short i_clh_flg;
}DL_OBLG_ACC_ENT_STRUCT_I;

typedef struct{
	short i_dl_client;
	short i_dl_ref_no;
	short i_broker_dpid;
	short i_broker_cmbpid;
	short i_cp_dpid;
	short i_cp_clnid;
	short i_gendp_flg;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_mkt_type;
	short i_qty;
	short i_exec_dt;
	short i_client_id;
	short i_dp_id;
	short i_dpgend;
}DL_DPGEN_DET_STRUCT_I;

/*Added by Amol*/
typedef struct{
	short i_obgdaybuyvol;
	short i_obgdaysalvol;
	short i_obgdaybuyamt;
	short i_obgdaysalamt;
	short i_obgcumbuyvol;
	short i_obgcumsalvol;
	short i_obgcumbuyamt;
	short i_obgcumsalamt;
	short i_obgsetlno;
	short i_obgtmbrncode;
	short i_obgdate;
	short i_obgcupcode;
	short i_obgsecsymbol;
	short i_obgsecseries;
	short i_obgseccode;
	short i_obgtmcode;
	short i_obgcuscode;
	short i_obgsetltype;
	short i_obgndflag;
	short i_obgfnlobg;
}DL_NSC_OBL_STRUCT_I;

typedef struct{
	short i_system_seq_no;
	short i_file_batch_no;
	short i_instr_code;
	short i_benefactyp;
	short i_benef_accposn;
	short i_mkt_type;
	short i_settlemt_no;
	short i_bl_lc_code;
	short i_depo_code;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_status;
}DL_POOLACCRECS_STRUCT_I;

typedef struct{
   short i_blk_ref_no;
   short i_client;
   short i_remarks;
   short i_status;
   short i_maker;
   short i_maker_dt;
   short i_access_stamp;
   short i_checker;
   short i_checker_dt;
}DL_BLK_SEC_STRUCT_I;

typedef struct{
   short i_blk_ref_no;
   short i_instr_code;
   short i_depo_code;
   short i_blk_date;
   short i_blk_type;
   short i_qty;
   short i_bal_qty;
   short i_un_blk_date;
   short i_un_blk_qty;
   short i_custo_ref_no;
   short i_status;
   short i_maker;
   short i_maker_dt;
   short i_access_stamp;
   short i_checker;
   short i_checker_dt;
}DL_BLK_SEC_DET_STRUCT_I;

typedef struct{
   short i_transfer_ref_no;
   short i_from_client;
   short i_to_client;
   short i_custody_internal;
   short i_cp_custo;
   short i_cp_dp_id;
   short i_cp_client_id;
   short i_status;
   short i_maker;
   short i_maker_dt;
   short i_access_stamp;
   short i_checker;
   short i_checker_dt;
}DL_INTR_SCH_STRUCT_I;

typedef struct{
   short i_transfer_ref_no;
   short i_instr_code;
   short i_depo_code;
   short i_qty;
   short i_bal_qty;
   short i_transfer_dt;
   short i_status;
   short i_maker;
   short i_maker_dt;
   short i_access_stamp;
   short i_checker;
   short i_checker_dt;
}DL_INTR_SCH_DET_STRUCT_I;

typedef struct{
short i_settlement_no;
short i_instr_cd;
short i_aggr_qty;
short i_agg_amt;
short i_mkt_type;
short i_deal_cd;
short i_deal_dt;
short i_status;
short i_exch_code;
}DL_EXCHOBLIGATION_STRUCT_I;
	
typedef struct{
short i_settlement_no;
short i_instr_cd;
short i_deal_cd;
short i_status;
short i_failcode;
short i_comments;
short i_mkt_type;
short i_exch_code;
}DL_EXCHRECON_RPT_STRUCT_I;

/*********** Pool Account Dump Maintenance *********************************/

typedef struct{
	short i_seq_no;
	short i_filebatch_no;
	short i_benef_acctype;
	short i_qty;
	short i_mkt_type;
	short i_settlemt_no;
	short i_bl_lc_code;
	short i_icrel_date;
	short i_access_stamp;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_status;
	short i_instr_code;
	short i_depo_code;
	short i_exch_code;
	short i_dp_id;
}DL_POOLACCDMP_STRUCT_I;

/*********** Pool Account Dump Maintenance  vinay *********************************/

typedef struct{
	short i_file_name;
	short i_upld_date;
	short i_batch_no;
	short i_f_code;
	short i_filelinkinfo;
}POOLACDET_STRUCT_I;

/*****************************************************************************/

typedef struct{
	short i_batch_no;
	short i_serial_no;
	short i_trans_flg;
	short i_internal_ref_no;
	short i_trans_type;
	short i_dpm_trans_no;
}DL_UPDDPINST_STRUCT_I;


typedef struct{
	short i_record_type;
	short i_branch_cd;
	short i_line_no;
	short i_trans_type;
	short i_dpm_transaction_no;
	short i_ord_stat_from;
	short i_ord_stat_to;
	short i_stat_chng_dt;
	short i_client_cd;
	short i_isin;
	short i_qty;
	short i_mkt_type;
	short i_settlement_no;
	short i_exec_dt;
	short i_other_dpid;
	short i_other_client;
	short i_benf_acc_ctgry;
	short i_other_cmbp_id;
	short i_internal_ref_no;
}DL_INST_COD_STRUCT_I;

typedef struct{
	short i_on_date;
	short i_calc_date;
	short i_instr_code;
	short i_cln_code;
	short i_intrate;
	short i_safek;
	short i_facevalue;
	short i_baseamt;
	short i_interest;
	short i_gain_safek;
	short i_gain_amount;
	short i_gain_int;
}CADAILY_FLOATINTEREST_STRUCT_I;
/** added By Biju **/

/*Code Added by Amol 03082006*/
typedef struct{
	short i_instr_code;
	short i_buy_qty;
	short i_buy_val;
	short i_sell_qty;
	short i_sell_val;
	short i_net_qty;
	short i_net_val;
	short i_std_rate;
	short i_net_std_diff;
	short i_std_rate_diff;
	short i_net_amt;
	short i_cfqty;
	short i_calldivflag;
	short i_calldivamt;
	short i_bank_qty;
	short i_bank_val;
	short i_settlement_no;
	short i_mkt_type;
	short i_deal_dt;
}DL_BSE_OBL_STRUCT_I;

/*Code Added by Amol 15092006*/
typedef struct{
	 short i_rec_type;
	 short i_line_no;
	 short i_branch_cd;
	 short i_ben_acc_no;
	 short i_ben_cat;
	 short i_isin;
	 short i_ben_acc_type;
	 short i_ben_acc_pos;
	 short i_cc_id;
	 short i_mkt_type;
	 short i_setl_no;
	 short i_blflag;
	 short i_blcode;
	 short i_lock_rel_date;
	 short i_filler;
	 short i_dp_id;
	 short i_upl_date;
	 short i_status;
	 short i_comments;
}DL_UPL_SOH_STRUCT_I;

/*Code Added by Amol 30102006*/
typedef struct{
	 short i_instr_code;
	 short i_posit_date;
	 short i_location_cd;
	 short i_client;
	 short i_status;
	 short i_start_safek;
	 short i_safekeep_pos;
	 short i_nvalreceive;
	 short i_nvaldeliver;
	 short i_val_rec;
	 short i_val_del;
	 short i_dp_rec;
	 short i_dp_del;
	 short i_block_type;
}HISSAFEK_STRUCT_I;

/*Code Added by Amol 21112006*/
typedef struct{
	 short i_line_ind;
	 short i_dp_id;
	 short i_client_cd;
	 short i_upl_date;
	short i_status;
}CDSL_UPL_A_STRUCT_I;

/*Code Added by Amol 21112006*/
typedef struct{
	 short i_line_ind;
	 short i_isin;
	 short i_cur_bal;
	 short i_free_bal;
	 short i_emark_bal;
	 short i_pledge_bal;
	 short i_remat_pend;
	 short i_isin_name;
	 short i_isin_desc;
	 short i_issuer_name;
	 short i_issuer_add1;
	 short i_issuer_add2;
	 short i_issuer_add3;
	 short i_issuer_city;
	 short i_issuer_state;
	 short i_pin_cd;
	 short i_upl_date;
}CDSL_UPL_B_STRUCT_I;

/*Code Added by Amol 21112006*/
typedef struct{
	 short i_client;
	 short i_instr_code;
	 short i_qty;
	 short i_upl_date;
	 short i_status;
 	 short i_dp_id;
	 short i_block_type;
}DL_HOLD_UPL_STRUCT_I;

/*Code Added by Amitk 05-03-2007*/

/***** JC - RFS_MS_001 -- Start *****/
typedef struct{
        short i_cln_code;
        short i_ca_flag;
        short i_dl_flag;
        short i_corp_id;
        short i_dl_ref_no;
        short i_message_txt;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_access_stamp;
        short i_status;
        short i_msg_seq_no;
        short i_msg_indicator;
	short i_address_cln;
	short i_manmsg_seqno;
}MANUAL_MESSAGE_STRUCT_I;
/***** JC - RFS_MS_001 -- End *****/

typedef struct {
	short i_proc_num;
	short i_val_date;
	short i_account;
	short i_client_cd;
	short i_acc_type;
	short i_clh_flg;
	short i_exch_cd;
	short i_dc_ind;
	short i_amount;
	short i_narrative;
	short i_brnch_cd;
	short i_bank_sys;
}  PRO_GEFUENT_STRUCT_I;

/***** JC - ISKB 487 -- Start *****/
typedef struct {
	short	i_dl_client;
	short	i_identiy_no;
	short	i_price;
	short	i_amt;
	short i_net_amt;
	short i_qty;
	short	i_maker;
	short	i_maker_dt;
	short	i_status;
	short	i_access_stamp;
	short	i_checker;
	short	i_checker_dt;
} DL_DEAL_DECI_ADJ_STRUCT_I;
/***** JC - ISKB 487 -- End *****/
/**** Rohit - Margin Upload Enhancement *****/
typedef struct{
		short i_upld_datetime;
		short i_upld_filename;
		short i_scrip_symbol;
		short i_exch_instr_code;
		short i_scrip_grp;
		short i_isin;
		short i_security_var;
		short i_index_var;
		short i_var_rate;
		short i_elm_rate;
		short i_additional_rate;
		short i_tot_rate;
		short i_instr_code;
}VARELM_UPLOAD_NSE_STRUCT_I;

typedef struct{
		short i_upld_datetime;
		short i_upld_filename;
		short i_sr_no;
		short i_scrip_code;
		short i_scrip_name;
		short i_isin;
		short i_var_per;
		short i_fivar_per;
		short i_processon;
		short i_appli_on;
		short i_var_rate;
		short i_elm_per;
		short i_elm_rate;
		short i_tot_varelm;
		short i_instr_code;
}VARELM_UPLOAD_BSE_STRUCT_I;
/**** Rohit - Margin Upload Enhancement End *****/

/** Added By Vijay For SLB REversal HB_03_001 **/
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
	short	i_instrdate;
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
	short	i_instr_code;
	short	i_currencycode;
	short	i_classofdl;
	short	i_origindentity_no;
	short	i_newdt;
	short	i_maker;
	short	i_maker_dt;
	short	i_deal_status;
	short	i_access_stamp;
	short	i_info1;
	short	i_loccode;
	short	i_reginstr_ind;
	short	i_status_pos;
	short	i_status_reg;
	short	i_confdate;
	short	i_matchindentity_no;
	short	i_markfaildate;
	short	i_candropdate;
	short	i_checker;
	short	i_checker_dt;
	short	i_instrconv_ind;
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
	short	i_lr_instrdate;
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
	short i_minstr_isinfo;
	/* new fields added - HDFCDL_003 - Sundar */
	short i_settlement_no;
	short i_mkt_type;
	short i_clh_flg;
	short i_interest;
	short i_net_amt;
	short i_payin_dt;
	short i_payout_dt;
	short i_demat_qty;
	short i_contract_req;
	short i_excum_flg;
	short i_crn_no;
	short i_interfii_flg;
	short i_pay_mode;
	short i_dl_secstatus;
	short i_dl_mnystatus;
	short i_avail_qty;
	short i_allot_qty;
	short i_shortage_qty;
	short i_cln_depoacc;
	short i_pltopl_flg;
	short i_orig_status;
	short i_map_failcode;
	short i_match_failcode;
	short i_is_matched;
	short i_exch_code;
	short i_contract_cd;
   short i_r_delay;
   short i_sebi_reported;
   short i_r_sett_code;
   short i_r_trans_code;
   short i_r_type;
   short i_repo_date;
	short i_comm_amt;
	short i_mf_seqno;
   short i_rev_leg_date;
   /*Retro from HDFC by Ekta for Interoperability Starts*/
	short i_trd_exch; 
	short i_trd_setl_no;
	short i_trd_mkt_type;
	/*Retro from HDFCby Ekta for Interoperability Ends*/
	/* Added by Shradha for adding Stamp Duty - CS0046502 Starts */
	short i_stamp_duty;
	/* Added by Shradha for adding Stamp Duty - CS0046502 Ends */
} SYS_DL_DEAL_REV_STRUCT_I;
/** Vijay For SLB REversal HB_03_001 **/

