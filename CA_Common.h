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
 * File Name           :      CA_Common.h
 *
 * Description         :      Contains Structure Variables & Extern fns Related to CA
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author           Description        RFS No.
 * ---------   --------  ---------------  ------------------   ---------
 * 18/01/2006   1.2        Smita Bhat        New File          Base Version
 * 20/01/2006   1.4		   Smita Bhat		 Added Structures  HDFCCA_027
 *											 			 for EVENT Table
 *	22/06/2006	 1.10			Smita Bhat		 Changed Entitlement 
 *														 Structure				HDFCCA_001,HDFCCA_002,HDFCCA_017
    03/03/2006   1.11        Vaibhav           CA_NIS_ALLOTMENT
 *************************************************************************/
  


#ifndef	MODULE_CA
#define	MODULE_CA
#include	"CA_InterFace.h"
#include "MT_Interface.h"
#include "DL_Interface.h"
#include "CO_Commdef.h"
#include "CR_Common.h"



#define	EVT_BOND_REDMP	"RD"
#define	EVT_BOND		"BI"
#define	EVT_CASH_DIV		"CD"
#define  EVT_DECR_VAL  "DV"
#define	EVT_STOK_DIV	"SD"
#define	EVT_RHTS		"RT"
#define	EVT_BONUS			"BO"
#define	EVT_MEETING		"SM"
#define	EVT_SPLIT		"SP"
#define	EVT_OFFER		"OP"
#define  EVT_REDOM "RN"
#define	EVT_OTH		"OT"
#define  EVT_NM_CHNG "NM" /*Smita - HDFCCA_027 - Name Change Event*/
#define  EVT_BUY_BACK "BB" /*Smita - HDFCCA_009 - Buy Back Event*/
#define  EVT_NS "NS"
#define  EVT_CV "CV"
#define  EVT_CAP_RED "CR" /*Smita - HDFCCA_004 - Capital Reduction Event*/
#define EVT_BONUS_DEMER "DM"  /* Demerger Event */ /* ISKB-373:  ASHISH 06-12-2007 */

/*Smita - HDFCCA_004 - Capital Reduction Event*/
#define RED_TYP_UNITS "U"
#define RED_TYP_FACEVAL "F"
#define RED_TYP_BOTH "B"
/*Smita - HDFCCA_004 - Capital Reduction Event*/

#define CA_BONUS_IND        "BONUS"
#define CA_BONDRD_IND    "REDMPT"
#define RTS_ISSUE       "RIGHTS"
#define STOCK_DIVIDEND     "STKDIV"
#define STOCK_SPLIT        "STKSPL"
#define REV_STOCK_SPLIT    "STKSPR"  /*** RVSL ***/
#define AMALGAMATION			"AMALGM"	 /*** AMAL ***/
#define TAKEOVER				"TKOVER"	/*** TAKO ***/
#define OFFER_PRIVELEGE    "OFFPR"
#define LOCN_CHANGE        "LOCCHG"
#define RTS_PROC  "RTSPRO"
#define CACV_IND	"CNV"	/** Please Use this as indicator for CV when while doing payment changes -- Biju **/
#define CACR_IND	"CAPRED"  /** Please Use this as indicator for CR when while doing payment changes -- Biju **/

#define CA_RT_APPL_IND	"CARTAP"	/** Biju For Rights Application **/
#define CA_RT_ALLOT_IND	"CARTAL"	/** Biju For Rights Allotment **/
#define CA_BB_ALLOT_IND	"CABBAL"	/** Biju For Buy Back Allot **/
#define CA_IPO_ALLOT_IND	"CAIPAL"	/** Biju For Ipo Allot **/
#define CA_PUTCALL_IND	"CAPCDL" /** For Put Call Deals **/



#define	STATUS_RDY_INT	"IN"
#define	STATUS_MSG_SENT			"SN"
#define  STATUS_RDY_APP          "RA"
#define	STATUS_RDY_ENTL			"RE"
#define	STATUS_RDY_PYMT			"RP"
#define	STATUS_MSG_PAID_CLSD		"CP"	
#define	STATUS_PART_PAID		"PP"
#define	STATUS_REV_UAUTH		"RU"
#define	STATUS_REVERSED			"RV"
#define  STATUS_WITHDRAWN      "WI"
#define	STATUS_FROZ_UAUTH_A		"FU"
#define	STATUS_FROZ_IN	"FI"
#define	STATUS_FROZ_RE	"FE"
#define	STATUS_UNFRZ_UAUTH	"ZU"
#define	STATUS_DEL_UNAUTH		"DU"
#define	STATUS_DELETED_A			"DL"
#define  STATUS_DELETED    "DD"
#define	STATUS_CHNG_RDY_INT		"IU"
#define  STATUS_FROZ_SN  "FS"



#define	STATUS_CHNG_PAID_CLSD		"UP"
#define	STATUS_CHNG_RDY_PYMT			"RH"
#define	STATUS_CHNG_PART_PAID		"PU"
#define	STATUS_FROZ_RP		"FR"
#define	STATUS_FROZ_PP		"FP"


#define  ENTL_BASE_DL    "T"
#define  ENTL_BASE_SETL    "S"
#define  ENTL_BASE_REG     "R"

#define	RATIO_IND				"R"	
#define	AMT_IND			"A"	
#define	RATE_IND			 	"R"	
#define	PERCEN_IND			 	"P"	


#define	CASH_IND					"C"
#define  DISRGD_IND             "D"
#define  FRACT_DISP_RNDOFF           "R"
#define  FRACT_DISP_STDRND     "S"
#define  FRACT_DISP_IND		      "F"


#define FRACT_DISP_REDOM   "B"


#define FUNC_AREA_REDENOM		"REDEN"



#define	MSGCD_LEN			7	
#define	REV_MSG_BOND_RDMP	"556R02"	
#define	REV_MSG_DIV		"554R01"	
#define	REV_MSG_STOCK		"555R01"	
#define	EVT_REV_MSGNO		"551R01"
#define	EVT_OPREV_MSGNO	"552R01"
#define	A_ENTITL_REV_MSG_NO	"551R02"
#define	EVT_OTREV_MSGNO	"564R91"
#define EVT_REV_MSGNO_SM_EVT	"560R01"  /* Added by VaibhavK for KOTAK_UAT I-Solve:362 */
#define EVT_REV_MSGNO_BB_EVT    "552R01" /* Added by VaibhavK for KOTAK_UAT Buy_Back cancellation messages */


#define	CA_ALERT_CODE_LEN		21
	/** Changed By Biju -- HDFCCA_005**/
#define  CA_ALERT_ADDN_INFO_LEN 51
	/** Changed By Biju -- HDFCCA_005**/
#define  AUTO_EVT_WAIT_PERIOD 7
#define 	A_INSTR_NAME_LEN 131
#define 	A_CNAME_LEN  66

#define	CA_WriteAlert(p_alert_struct,chr_p_funccode,p_alert_cd,chr_p_ca_id,chr_p_client,p_instr_code)\
{\
	memset(p_alert_struct,NULL,sizeof(CA_CANOTIFY_STRUCT_H));\
	strcpy(p_alert_struct->h_processcode,	chr_p_funccode);\
	strcpy(p_alert_struct->h_alert_code,	p_alert_cd);\
	strcpy(p_alert_struct->h_corp_id,		chr_p_ca_id);\
	strcpy(p_alert_struct->h_dl_client,	chr_p_client);\
	strcpy(p_alert_struct->h_instr_code,		p_instr_code);\
	if (CA_Alert(p_alert_struct,l_debug_info_ptr) == APL_FAILURE)\
		APL_GOBACK_FAIL\
	memset(p_alert_struct,NULL,sizeof(CA_CANOTIFY_STRUCT_H));\
}



typedef struct {
	char		h_deal_date[APL_DATE_LEN];
	char		h_processcode[CA_FUNC_CD_LEN];
	char		h_alert_code[CA_ALERT_CODE_LEN];
	char		h_corp_id[CORP_ID_LEN];
	char		h_dl_client[APL_CLIENT_LENGTH];
	char		h_instr_code[APL_INSTRUMENTCODE_LEN];
	int		h_pymt_srl_nbr;
	char		h_additional_info[CA_ALERT_ADDN_INFO_LEN];
} CA_CANOTIFY_STRUCT_H;




typedef  struct {
      char  h_instr_code[APL_INSTRUMENTCODE_LEN];
      char  h_evt_class[EVT_CLASS_];
      char  h_pymt_dt[APL_DATE_LEN];
      char  h_corp_id[CORP_ID_LEN];
                  }  CA_CALOGAUTOEVENT_STRUCT_H;


typedef  struct {
      short i_instr_code;
      short i_evt_class;
      short i_pymt_dt;
      short i_corp_id;
                  }  CA_CALOGAUTOEVENT_STRUCT_I;



typedef  struct   {
      short  i_nation_code;
      short  i_typeofinstr;
      short  i_prodateype;
      short  i_evt_class;
      short  i_no_days_pymtdt;
      short  i_exdate_no_days;
                  }  CA_AUTOEVT_STRUCT_I;


/*Smita - HDFCCA_027 - Changed Indicator Structure for CAEVENT */
typedef struct {
	short	i_corp_id;
	short	i_instr_code;
	short	i_evt_class;
	short	i_decl_date;
	short	i_evt_nbr;
	short i_priority;
	short	i_preliminary_flag;
	short	i_ca_currency;
	short	i_ex_date;
	short	i_rec_date;
	short	i_pymt_dt;
	short	i_respons_date;
	short	i_expire_date;
	short	i_pp_date;
	short	i_proxy_date;
	short	i_meet_date;
	short	i_start_date;
	short	i_effect_date;
	short	i_proc_oth;
	short	i_op_evt_class;
	short	i_respons_date_openend;
	short	i_expire_date_openend;
	short	i_evt_send_msg_ind;
	short	i_entl_send_msg_ind;
	short	i_pymt_send_msg_ind;
	short	i_earnings;
	short	i_earnings_rt;
	short	i_res_instr_code;
	short	i_new_safek_quantity;
	short	i_old_safek_quantity;
	short	i_disp_of_fract;
	short	i_f_pr;
	short	i_sub_base_quantity;
	short	i_sub_new_quantity;
	short	i_sub_pr;
	short	i_rights_class;
	short	i_new_safek_quantity_rt;
	short	i_contactinfo;
	short	i_amount_due;
	short	i_amount_recd;
	short	i_quantity_due;
	short	i_quantity_recd;
	short	i_evt_msg_count;
	short	i_evt_clt_cnt;
	short	i_entl_msg_cnt;
	short	i_entl_clt_cnt;
	short	i_count_acs_pend;
	short	i_nrepdate1;
	short	i_follmsg1date;
	short	i_follmsg2date;
	short	i_info_nbr;
	short	i_entinfo_no;
	short	i_evt_stat;
	short	i_stat_date;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_access_stamp;
	short i_dealfrom_dt;
	short i_dealto_dt;
	short i_subs_date;
	short i_posting_date;
	short i_over_subscrp;
	short i_div_class;
	short	i_redem_rt;
   short i_nser_info;
   short i_nrep_date_a;
   short i_comp_info1;
   short i_inco_info1;
   short i_buyresp_date;
   short i_sellresp_date;
	short i_wwwaddr;
	short i_txnr_info1; 
	short i_reqd_cert_ind; 
	short	i_ex_dt_bse;
	short	i_bc_from_date;
	short	i_bc_to_date;
	short	i_res_instr_code_2;
	short	i_trans_dt;
	short	i_cln_code;
	short	i_prev_inst_date;
	short	i_next_inst_date;
	short	i_inst_start_period;
	short	i_inst_end_period;
	short	i_last_ptc_date;
	short	i_allotment_letter;
	short	i_redem_option;
	short	i_inst_amount;
	short	i_send_split;
	short	i_cmp_code;
	short	i_res_cmp_code;
	short	i_exch_code;
	short	i_premium;
	short	i_face_value;
	short	i_interest_type;
	short	i_ratio_rcv2;
	short	i_ratio_hld2;
	short i_depo_part_code;
	short i_depo_code;
	short i_bk_build_ind;        /* Added By Vaibhav HDFCCA_013*/
	short i_attach_corp_id;
   short i_source;
   short i_new_safek_rt2;
	short i_tick_size;
	short i_issue_size;
	short i_qib_margin;
	short i_market_lot;
	short i_max_rtl_qty;
	short i_min_qty;
	short i_lead_mgr;
	short i_synd_membr;
	short i_co_mgr;     
	short i_lwr_limit;
	short i_upr_limit;
        short i_fract_qty_bal;
        short i_fract_qty_recd;
		short i_bilav_id;       /* Added by Arunachalam for CS0074500 - New Bilav file upload */
} CA_CAEVENT_STRUCT_I;
/*Smita - HDFCCA_027 - Changed Indicator Structure for CAEVENT *     /

/*Smita - HDFCCA_001,HDFCCA_002,HDFCCA_017z - Changed Indicator Structure for CAENTITLEMENT */
typedef struct {
	short	i_corp_id;
	short	i_dl_client;
	short	i_entitl_pos;
	short	i_entitl_ccy;
	short	i_instr_inc_bal;
	short	i_amount_recd;
	short	i_quantity_due;
	short	i_quantity_recd;
	short	i_nrepdate2;
	short	i_nrepdate3;
	short	i_sent550date;
	short	i_entitl_stat;
	short	i_stat_date;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_access_stamp;
	short	i_tax_rate;
	short i_fract_due;
	short i_fract_rcvd;
} CA_CAENTITLEMENT_STRUCT_I;
/*Smita - HDFCCA_001,HDFCCA_002,HDFCCA_017 - Changed Indicator Structure for CAENTITLEMENT */

typedef struct {
	short	i_corp_id;
	short	i_dl_client;
	short	i_pymt_srl_nbr;
	short	i_pymt_dt;
	short	i_pymt_currency;
	short	i_curr_pymt;
	short	i_quantity_recd;
	short	i_tax_rate;
	short	i_pymt_inst;
	short	i_handoff_date;
	short	i_txn_indentity_no;
	short	i_billdate;
	short	i_loccode;
	short	i_tax_amount;
	short	i_other_chrgs;
	short	i_pymt_stat;
	short	i_stat_date;
	short	i_new_dt;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_access_stamp;
	short i_clt_pass_flg;
	short i_clt_batch_no;
	short i_quantity_paid;
	short i_taxable_dividend;
	short i_fract_qty_bal;
	short i_fract_qty_recd;
	short i_cpa_reported;
	short i_writeoff_amount;
	short i_net_amount;//Changes done by Sunny for CS0020637
} CA_CACHEQUE_STRUCT_I;






typedef struct {
	short	i_instr_code;
	short	i_dl_client;
	short	i_ca_event;
	short	i_decl_date;
	short	i_evt_nbr;
	short	i_instr_parent;
	short	i_corp_id;
	short	i_total_quantity;
	short	i_takeupquantity;
	short	i_lapsequenceuantity;
	short	i_loccode;
	short	i_sub_base_quantity;
	short	i_sub_new_quantity;
	short	i_sub_currency;
	short	i_sub_pr;
	short	i_info_nbr;
	short	i_evt_stat;
	short	i_maker;
	short	i_maker_dt;
	short	i_checker;
	short	i_checker_dt;
	short	i_access_stamp;
	short	i_pymt_dt;
	short i_transmit_date;
} CA_CARTSPROC_STRUCT_I;




typedef struct {
	short	i_info_nbr;
	short	i_info_1;
	short	i_info_2;
	short	i_info_3;
	short	i_info_4;
	short	i_maker;
	short	i_maker_dt;
	short	i_access_stamp;
	short i_info_class;
} CA_CANOTE_STRUCT_I;




typedef struct {
	short	i_deal_date;
	short	i_processcode;
	short	i_alert_code;
	short	i_corp_id;
	short	i_dl_client;
	short	i_instr_code;
	short	i_pymt_srl_nbr;
	short i_additional_info;
} CA_CANOTIFY_STRUCT_I;




typedef struct {
	short	i_typeofinstr;
	short	i_ca_event;
	short	i_pymtout_ind;
	short	i_entitl_base;
	short	i_rt_pct_ind;
	short	i_amt_rt_ind;
	short	i_new_dl_ind[APL_FLAG_LENGTH];
	short	i_evtmsg_all_mstclt[APL_FLAG_LENGTH];
	short	i_gen_enrarep_ind[APL_FLAG_LENGTH];
	short	i_enra_lapse_a;
	short	i_enra_lapse_b;
	short	i_enra_lapse_c;
        short   i_closure_dt_days;  /*Added By Santhoshi for PEG-CA-ENH-2.3  - retro by Sana Bhatkar*/
} CA_CASECEVENT_STRUCT_I;



typedef struct {
   short i_corp_id;
   short i_entitl_pos;
   short i_quantity_due;
   short i_amount_due;
   short i_pymt_dt;
   short i_cur_quantity_due;
   short i_cur_amount_due;
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_pymt_stat;
   short i_access_stamp;
   short i_new_dt;
   short i_quantity_paid;
	short i_taxable_dividend;
	short i_loccode;
} CA_CAGLPYMT_STRUCT_I;


typedef	struct	{
	char		h_evt_class[EVT_CLASS_];
	char		h_rec_date[APL_DATE_LEN];
	char		h_instr_code[APL_INSTRUMENTCODE_LEN];
	int		h_new_safek_quantity;
	int		h_old_safek_quantity;
	double	h_entl_instr_inc_bal;
	double	h_entl_amt_recd;
	double	h_entl_quantity_due;
	double	h_entl_quantity_recd;
	double	h_evt_instr_inc_bal;
	double	h_evt_amt_recd;
	double	h_evt_quantity_due;
	double	h_evt_quantity_recd;
	char		h_evt_stat[APL_STATUS_LEN];
	char		h_entitl_stat[APL_STATUS_LEN];
   int      h_entl_msg_cnt;
   int      h_entl_clt_cnt;
	double	h_entitl_pos;
						} CA_CHK_DET_STRUCT_H;

typedef	struct	{
	short	i_evt_class;
	short	i_rec_date;
	short	i_instr_code;
	short	i_new_safek_quantity;
	short	i_old_safek_quantity;
	short	i_entl_instr_inc_bal;
	short	i_entl_amt_recd;
	short	i_entl_quantity_due;
	short	i_entl_quantity_recd;
	short	i_evt_instr_inc_bal;
	short	i_evt_amt_recd;
	short	i_evt_quantity_due;
	short	i_evt_quantity_recd;
	short	i_evt_stat;
	short	i_entitl_stat;
   short i_entl_msg_cnt;
   short i_entl_clt_cnt;
   short i_entitl_pos;
						} CA_CHK_DET_STRUCT_I;
/*vaibhav - CA_NIS_Allotment - HDFCCA_015*/
typedef struct{
	short i_corp_id;
	short i_cln_code;
	short i_canrefno;
	short i_candate;
	short i_canrecdate;
	short i_qtyshallot;
	short i_blockflg;
	short i_price;
	short i_mmpaid;
	short i_money_payable;
	short i_amountpay;
	short i_lastdatetime;
	short i_clastdatetime;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_status;
	short i_hf_date;
	short i_clt_seqnum;
	short i_ae_passind;
	short i_processed_date;
}CA_NIS_ALLOTMENT_STRUCT_I;
/*vaibhav - CA_NIS_Allotment - HDFCCA_015*/
/*Added by Chirag for HDFCCA_016  for NIS BIDDING*/
typedef struct{
      short i_corp_id;
      short i_cln_code;
      short i_brevno;
      short i_applfrmno;
      short i_depo_code;
      short i_depo_cln_id;
      short i_dp_id;
      short i_bdate;
      short i_bqty1;
      short i_brate1;
      short i_bqty2;
      short i_brate2;
      short i_bqty3;
      short i_brate3;
      short i_filegenflg;
      short i_paycomm;
      short i_maker;
      short i_maker_dt;
      short i_checker;
      short i_checker_dt;
      short i_access_stamp;
      short i_status;
      short i_synd_membr;
      short i_mmpaynw;
		short i_hf_date;
		short i_clt_seqnum;
		short i_ae_passind;
		short i_processed_date;
}CA_NIS_BID_STRUCT_I;

typedef struct{
   short i_corp_id;
   short i_cln_code;
   short i_applncode;
   short i_depo_code;
   short i_depo_cln_id;
   short i_dp_id;
   short i_synd_membr;
   short i_adate;
   short i_aqty;
   short i_arate;
   short i_mmpaid;
   short i_filegenflg;
   short i_paycomm;
   short i_maker;
   short i_maker_dt;
   short i_checker;
   short i_checker_dt;
   short i_access_stamp;
   short i_status;
   short i_brevno;
   short i_bk_build_ind;
   short i_alloted;   
	short i_hf_date;
	short i_clt_seqnum;
	short i_ae_passind;
	short i_processed_date;
}CA_NIS_APPLICATION_STRUCT_I;
/*Added by Chirag for HDFCCA_016  for NIS BIDDING*/
/*Vaibhav CA_APPLICATION*/
typedef struct{
	short i_corp_id;
	short i_cln_code;
	short i_application_date;
	short i_applied_qty;
	short i_avl_qty;
	short i_addqty_app;
	short i_price;
	short i_amt_payable;
	short i_amt_due;
	short i_remark;
	short i_status;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_depo_code;
	short i_depo_cln_id;
	short i_dp_id;
	short i_cln_refno;
	short i_cln_srno;
	short i_hf_date;
	short i_clt_seqnum;
	short i_ae_passind;
	short i_processed_date;
}CA_APPLICATION_STRUCT_I;
/*Vaibhav CA_APPLICATION*/
/* Open Offer */
typedef struct{
	short i_corp_id;
	short i_cln_code;
	short i_depo_code;
	short i_cln_srno;
	short i_applied_qty;
	short i_moved_qty;
	short i_price;
}CA_APPLICATION_CABL_STRUCT_I;
/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/
typedef struct{
	short i_corp_id;
	short i_cln_code;
	short i_ca_event;
	short i_allot_dt;
	short i_alloted_qty;
	short i_add_allot_qty;
	short i_amt_pay;
	short i_amt_rec;
	short i_typeof_info;
	short i_maker;
	short i_maker_dt;
	short i_checker;
	short i_checker_dt;
	short i_access_stamp;
	short i_status;
	short i_hf_date;
	short i_clt_seqnum;
	short i_ae_passind;
	short i_processed_date;
	short i_depo_cd;
	short i_dp_id;
	short i_cln_id;
	short i_amt_payable;	/* 23-01-2007 4 New Col. Added By Chirag For RT */ 
	short i_addqty_app;
	short i_applied_qty; 
	short i_orig_depo_cd;
}CA_RTBB_ALLOTMENT_STRUCT_I;
/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/
/*Added by Vaibhav for CA_PUTCALL_APP*/
typedef struct{
	short i_instr_code;
	short i_cln_code;
	short i_notice_date;
	short i_instr_type;
	short i_value_date;
	short i_avl_qty;
	short i_put_call_qty;
	short i_put_call_value;
	short i_put_call_rate;
	short i_status;
	short i_maker;
	short i_maker_dt;
	short i_access_stamp;
	short i_checker;
	short i_checker_dt;
	short i_info_seq;
	short i_pymt_send_msg_ind;
	short i_processed_date;
	short i_r_corp_id;
	short i_hf_date;
	short i_clt_seqnum;
	short i_ae_passind;
}CA_PUTCALL_APP_STRUCT_I;
/*Added by Vaibhav for CA_PUTCALL_APP*/


typedef	struct	{
	char		corp_id[CORP_ID_LEN];
	char		client[APL_CLIENT_LENGTH];
	double	curr_pymt;
	double	quantity_received;
	double	quantity_paid;
						}	CA_CHK_PYMT_STRUCT_H;
typedef struct {
	char		h_dl_client		[APL_CLIENT_LENGTH];
	char		h_dlt			[APL_DATE_LEN];
	char		h_delrecdate		[APL_DATE_LEN];
	double	h_pr;
	char		h_ex_arena		[3];
	double	h_amt;
	double	h_qty;
	char		h_dealcd			[APL_FLAG_LENGTH];
	char		h_instr_code			[APL_INSTRUMENTCODE_LEN];
	char		h_currencycode		[APL_CCYCODE_LEN];
	char		h_classofdl		[APL_STATUS_LEN];
	char		h_deal_status	[APL_STATUS_LEN];
	char		h_info1			[261];
	char		h_loccode		[APL_LOCNCODE_LENGTH];
	char		h_reginstr_ind		[APL_FLAG_LENGTH];
	char		h_pos_stat	[4];
	char		h_status_reg		[APL_FLAG_LENGTH];
	char		h_lrdltype		[APL_STATUS_LEN];
	double	h_delta_000;
	double	h_delta_001;
	double	h_delta_002;
	char		h_setldt		[APL_DATE_LEN];
	char		h_indentity_no			[APL_TXNREFNO_LEN];
	char		h_fail_cd[3];	
	char		h_ndsbldate[APL_DATE_LEN];
	char 		h_cash_client[APL_CLIENT_LENGTH];
	double	h_oth_comm;
	double   h_brokercomm;
	/** Added By Biju **/
	char  h_r_delay[2];
	char  h_r_sett_code[2];
	char  h_r_trans_code[3];
	char  h_r_type[3];
	char  h_misinfo[201];/*modified by siva.ganapathi for ISKB - 2263*/
	/** Added By Biju **/
} CA_DEAL_STRUCT_H;

typedef struct {
			char h_corp_id[CORP_ID_LEN];	
		   char h_instr_code[APL_INSTRUMENTCODE_LEN];
	   	char h_evt_class[EVT_CLASS_];
		   char h_decl_date[APL_DATE_LEN];
			int  h_evt_nbr;
			char h_evt_stat[APL_STATUS_LEN];
			} ARCH_RPT_STRUCT_H;

typedef struct {
			short i_corp_id;	
		   short i_instr_code;
	   	short i_evt_class;
		   short i_decl_date;
			short i_evt_nbr;
			short i_evt_stat;
			} ARCH_RPT_STRUCT_I;

typedef struct {
			char 	h_dl_client[APL_CLIENT_LENGTH];	
			char 	h_clnt_clr_name[CNAME_LEN_A];	
		   char 	h_instr_code[APL_INSTRUMENTCODE_LEN];
		   char 	h_instr_name[INSTR_NAME_LEN_D];
			char	 h_orderindentity_no[APL_TXNREFNO_LEN];	
	   	double h_orderquantity;
	   	double h_execquantity;
		   char h_orderdate[APL_DATE_LEN];
			} PEND_ORD_RPT_STRUCT_H;

typedef struct {
			short i_dl_client;	
			short i_clnt_clr_name;	
		   short i_instr_code;
		   short i_instr_name;
			short i_orderindentity_no;	
	   	short i_orderquantity;
	   	short	i_execquantity;
		   short i_orderdate;
			} PEND_ORD_RPT_STRUCT_I;


 typedef struct {
                       char            h_corp_id[CORP_ID_LEN];
                       char            h_aentle_client[APL_CLIENT_LENGTH];
                       char            h_instr_swift_msgidentiy_no[APL_TXNREFNO_LEN];
                       double  h_posn;
                       char            h_send_resp_ind[2];
                       char            h_stat_cd[FAILREAS_CD_LEN];
                       char            h_access_stamp[APL_DATE_LEN];
                       char            h_srl_num[5];
                       char            h_ca_optcd[9];  
                       } CA_CUST_INSTR_STRUCT_H;


extern	int CA_Mod_EventAuth(  CA_CAEVNT_AUT_STRUCT_H    *p_ca_caevnt_aut_struct_h,
                     				INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                     				DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  				);

extern	int CA_Mod_Event(  CA_CAEVENT_STRUCT_H    *p_ca_caevent_struct_h,
                     INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                     DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  );
extern	int	CA_ChkInstr( char *p_instr_code,
										char *p_res_instr_code,
										char *p_op_ind,
										DEBUG_INFO_STRUCT_H	**l_debug_info_ptr
										);	
			
extern	int	CA_Mod_EventRec(	CA_CAEVENT_STRUCT_H	*p_ca_caevent_struct_h,
											CA_CAEVENT_STRUCT_I	*p_ca_caevent_struct_i,
											char					*rowid,
											DEBUG_INFO_STRUCT_H		**l_debug_info_ptr
											);
extern	int 	CA_CheckStatus( char						*corp_id,
										char						*client,	
										char						*location_cd,	
				      			   CA_CHK_DET_STRUCT_H		*p_ca_chk_det_struct_h,	
				      			   CA_CHK_DET_STRUCT_I		*p_ca_chk_det_struct_i,	
										INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
										DEBUG_INFO_STRUCT_H 			 **l_debug_info_ptr
									);
extern	int	CA_Mod_Pymt(CA_CACHEQUE_STRUCT_H	*l_ca_cachequeimg_struct_h,
											CA_CACHEQUE_STRUCT_I	*l_ca_cachequeimg_struct_i,
											char					*rowid,
											DEBUG_INFO_STRUCT_H		**l_debug_info_ptr
											);

extern	int	CA_Chk_SumPymt(	CA_CHK_PYMT_STRUCT_H	*p_val_sum_pymt_struct,
										   CA_CHK_DET_STRUCT_H 	*p_ca_chk_det_struct_h,
					                  INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
											DEBUG_INFO_STRUCT_H			**l_debug_info_ptr
								 			);
extern	int CA_Mod_PymtAuth( CA_CAPYMT_AUT_STRUCT_H    *p_ca_capymt_aut_struct_h,
                    INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                    DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  );
extern	int	CA_ModPymt(  CA_CACHEQUE_STRUCT_H   *p_ca_cacheque_struct_h,
 					                 INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
  	         			           DEBUG_INFO_STRUCT_H         **l_debug_info_ptr,
								   char                     *chr_p_param_str
                  				);

extern	int	CA_Mod_NewTrade(	CA_DEAL_STRUCT_H			*p_atrade,
							INTL_ENV_DATA_STRUCT_H	*p_intlenv_data_struct_h,
							char						*p_txn_ref_no,
							DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);
/** Prototype Changed -- HDFCCA_036 Biju **/
extern	int	CA_ChkPosition(	char 		*p_instr_code,
						char		*chr_p_client,
						char		*p_location,
						double	p_quantity,
						char		*p_posn_status,
						char		*p_trade_status,	
						double	*p_delta_000,		
						double	*p_delta_001,		
		double	*p_delta_003,
		char *p_block_type,
		char *p_evt_type,
		char *p_op_evt_class,
						DEBUG_INFO_STRUCT_H	**l_debug_info_ptr
						);

extern	int CA_ChkAcc(	char						*chr_p_client,
									MT_CLIENT_STRUCT_H		*p_mt_client_struct_h,
									int						*int_p_result,
									DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);

/*-Changes for Base Version - CA -Smita - Changed Fn Name */
extern	int CA_ChkInstrument(	char						*p_instr_code,
								MT_INSTRUMENT_STRUCT_H	*p_mt_instrument_struct_h,
								int						*int_p_result,
								DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);

extern	int CA_RtvInstrEvnt(char						*p_typeofinstr,
								char						*p_event_type,
								CA_CASECEVENT_STRUCT_H	*p_ca_casecevent_struct_h,
								DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);

extern	int CA_CO_InstrUpd(	CA_CAEVENT_STRUCT_H		*p_ca_caevent_struct_h,
								MT_INSTRUMENT_STRUCT_H	*p_mt_instrument_struct_h,
								DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);
/*Changed by siva.gana[pathi for ISKB_3110 on 30/11/2009 --- started*/
extern	int CA_RtvNxtPayDt(	char					*p_nxt_pay_date,
									char					*p_mature_dt,
									char           *p_fst_pay_dt,
									char					*p_frq_cd,
									char					*p_new_date,
									DEBUG_INFO_STRUCT_H		**l_debug_info_ptr);
/*Changed by siva.gana[pathi for ISKB_3110 on 30/11/2009 == Ended*/
extern	int	 CA_Mod_FootNote(  CA_CANOTE_STRUCT_H    *p_ca_canote_struct_h,
                     INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                     DEBUG_INFO_STRUCT_H         **l_debug_info_ptr);

extern	int	CA_GenCARefNo(	char 		   *chr_p_ca_id,
						  				const char	*p_instr_code,
						  				const char	*p_ce_type,
						  				const char	*p_decl_date,
						  				const	int	*p_evnt_nbr,
										DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
										);

extern int CA_Mod_Entitl(CA_CAENTITLEMENT_STRUCT_H   *p_ca_caentitlement_struct_h,
                           INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                           DEBUG_INFO_STRUCT_H         **l_debug_info_ptr);

extern int CA_Mod_AuthEntitl(CA_CAENTL_AUT_STRUCT_H  *p_ca_caentl_aut_struct_h,
                            INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                            DEBUG_INFO_STRUCT_H         **l_debug_info_ptr);

extern	int CA_Alert	(	CA_CANOTIFY_STRUCT_H		*p_ca_canotify_struct_h,
									DEBUG_INFO_STRUCT_H		**l_debug_info_ptr);

extern int CA_CO_ModInstrRev( char * p_event_type,
                  char * p_instr_code,
                  char * p_sys_date_time,
                  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CA_Mod_UpdGlobalPymt( CA_CAGLPYMT_STRUCT_H    *p_ca_caglpymt_struct_h,
                     INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                     DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  );

extern int CA_ChkSumGlPymt( CA_CAGLPYMT_STRUCT_H *p_ca_caglpymt_struct_h,
						  INTL_ENV_DATA_STRUCT_H    *p_intlenv_data_struct_h,
						  DEBUG_INFO_STRUCT_H			  **l_debug_info_ptr
						);

extern int	CA_ChkNoUUEntitl(char * chr_p_ca_id,
								  DEBUG_INFO_STRUCT_H **l_debug_info_ptr
								 );

extern int 	CA_RtvEvnt(  char *chr_p_ca_id,
 						CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h,
 						CA_CAEVENT_STRUCT_I *p_ca_caevent_struct_i,
						char *p_ora_rowid,
			 		   INTL_ENV_DATA_STRUCT_H  * p_intlenv_data_struct_h, 
						DEBUG_INFO_STRUCT_H **	 l_debug_info_ptr
         		 );


extern int	CA_RtvGblPymtRec(char					*chr_p_ca_id,
								CA_CAGLPYMT_STRUCT_H	*p_ca_caglpymt_struct_h,
								CA_CAGLPYMT_STRUCT_I	*p_globalpymt_struct_i,
								char					*p_ora_rowid,
								DEBUG_INFO_STRUCT_H		**l_debug_info_ptr
								);

extern int  CA_Mod_NewGblPymt  ( FILE  *p_flogfile,
										char	**argv,
										char  *chr_p_ca_id,
										char  *chr_p_access_stamp,
										char	*chr_p_sys_date,				
										char	*p_sys_date_time,
										INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
										DEBUG_INFO_STRUCT_H		 **l_debug_info_ptr
                 			 ); 

extern int  CA_Archive  ( 	FILE  *p_flogfile,
							char  **argv,
                     char  *pro_sys_date,
                     char  *chr_sys_date_time,
							INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
							DEBUG_INFO_STRUCT_H		 **l_debug_info_ptr
                 		 ); 

extern int CA_Arch_Report( char * pro_sys_date,
							char ** argv,
							int  *total_arch_arr,
							FILE * p_flogfile,
							INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
							DEBUG_INFO_STRUCT_H		 **l_debug_info_ptr
						 );

extern int  CA_ArchMsgs(		FILE  *p_flogfile,
							char  **argv,
                     char  *pro_sys_date,
                     char  *chr_sys_date_time,
					   	INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
                     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



 
#define MSG_NO_ENT_CD_SD_BO_SP 	 "551N02"
#define MSG_NO_ENT_BI       "554N02"
#define MSG_NO_ENT_RT          "550N01"
#define MSG_NO_ENT_RD          "556N01"
#define MSG_NO_ENT_OP			 "552N02"

#define MSG_NO_ENT_CHG_CD_SD_BO_SP 	  "551C05"
#define MSG_NO_ENT_CHG_BI       "554C02"
#define MSG_NO_ENT_CHG_RT          "550C01"
#define MSG_NO_ENT_CHG_RD          "556C01"
#define MSG_NO_ENT_CHG_OP			  "552C02"

#define MSG_NO_ENT_REV_CD_SD_BO_SP "551R03"
#define MSG_NO_ENT_REV_OP          "552R03"
#define MSG_NO_ENT_REV_BI          "554R02"
#define MSG_NO_ENT_REV_RT          "550R01"
#define MSG_NO_ENT_REV_RD          "556R01"

#define STATUS_PENDING "NP"

extern	int 	CA_CheckEntl( char						*chr_p_ca_id,
									char						*chr_p_client, 
								   CA_CHK_DET_STRUCT_H		*p_ca_chk_det_struct_h,
				     	      	INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
									DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  		);

extern int   CA_Mod_EntitlRec(   CA_CAENTITLEMENT_STRUCT_H   *p_ca_caentitlement_struct_h,
                           CA_CAENTITLEMENT_STRUCT_I   *p_ca_caentitlement_struct_i,
                           char                 *p_ora_rowid,
                           DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                        );

#define ALERT_EVT_UAUTH "A_EVNT_UNAUTH"
#define ALERT_ENTL_UAUTH "A_ENT_UNAUTH"
#define ALERT_EVT_FRZ    "A_EVNT_FROZEN"
#define ALRT_CD_EVNTUNIN   "A_EVNT_PINT"
#define ALERT_ENTL_NOTGEN  "A_ENT_PSTRECDT"
#define ALERT_PYMT_NOTPROC  "A_PYMT_PENPROC"
#define BIDS_CONF_FILE_START     "A_NO_ALERTS"
#define 	ALERT_INSTR_UAUTH    "A_INSTRU_UNAUTH"
#define 	ALERT_INSTR_NOTFND   		"A_INSTRU_NF"
#define 	ALERT_PAST_RECDT  	"A_ENT_PSTRECDT"
#define 	AMENDHSN  		"A_NEG_POSITIONS"
#define 	BIDS_CONF_FILES_MAX  	 	"A_NO_POSITIONS"
#define	ALERT_PYMT_UAUTH	"A_PYMT_UNAUTH"
#define  ALERT_TRDT_AFT_RECDT          "A_TRD_AFTER_REC_DT"
#define ALERT_ENTL_FRZ "A_ENT_FROZEN"
#define 	BIDS_OTHR_FILES_MAX  	"A_ENT_NORECMAN"
#define 	BIDS_OTHR_FILE_START  	"A_ENT_NORDYPMT"
#define  ALRT_CD_UNAUTHENT     "A_UNAUTHENT_F"
#define  ALRT_CD_UNAUTHACC     "A_UNAUTHACC_F"
/*Smita - HDFCCA_027 - Name Change Event */
#define 	ALERT_CMP_UAUTH    		"A_CMP_UNAUTH"
#define 	ALERT_CMP_NOTFND   		"A_CMP_NF"
/*Smita - HDFCCA_027 - Name Change Event */

/*Smita - HDFCCA_009 - Buy Back Event */
#define 	ALERT_DP_UAUTH    		"A_DP_UNAUTH"
#define 	ALERT_DP_NOTFND   		"A_DP_NF"
#define  ALERT_DEPO_INVALID		"A_DEPO_INVALID"
/*Smita - HDFCCA_027 - Name Change Event */

#define INSERT_GLOB_PYMT_WARNING_ENT \
		CO_InsertWarning(l_debug_info_ptr,W_ENT_GLB_PYMT_EXIST,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

#define INSERT_GLOB_PYMT_WARNING_PAY \
		CO_InsertWarning(l_debug_info_ptr,W_PAY_GLB_PYMT_EXIST,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

extern	int  CA_Proc_GenrateAlerts ( 	FILE               *p_flogfile,
										INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
										DEBUG_INFO_STRUCT_H		 **l_debug_info_ptr
                 		 			); 
extern int	CA_RtvGblPymtRec(char					*chr_p_ca_id,
								CA_CAGLPYMT_STRUCT_H	*p_ca_caglpymt_struct_h,
								CA_CAGLPYMT_STRUCT_I	*p_globalpymt_struct_i,
								char					*p_ora_rowid,
								DEBUG_INFO_STRUCT_H		**l_debug_info_ptr
								);

extern int 	CA_RtvEvnt(  char *chr_p_ca_id,
 						CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h,
 						CA_CAEVENT_STRUCT_I *p_ca_caevent_struct_i,
						char *p_ora_rowid,
			 		   INTL_ENV_DATA_STRUCT_H  * p_intlenv_data_struct_h, 
						DEBUG_INFO_STRUCT_H **	 l_debug_info_ptr
         		 );

extern int	CA_ChkNoUUEntitl(char * chr_p_ca_id,
								  DEBUG_INFO_STRUCT_H **l_debug_info_ptr
								 );

extern int CA_ChkSumGlPymt( CA_CAGLPYMT_STRUCT_H *p_ca_caglpymt_struct_h,
						  INTL_ENV_DATA_STRUCT_H    *p_intlenv_data_struct_h,
						  DEBUG_INFO_STRUCT_H			  **l_debug_info_ptr
						);

extern	int CA_Rpt_GenPendOrders(
                       char *p_instr_code,
                       char *chr_p_ca_id,
                       char *p_pay_date, 
                       char *p_sys_date, 
                       FILE * pnd_ord_rept_file,
                       FILE * p_flogfile,
                       INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
                       DEBUG_INFO_STRUCT_H **l_debug_info_ptr
                   );


extern int CA_Proc_RedenominationEventMnt(
									CA_CAEVENT_STRUCT_H    *p_ca_caevent_struct_h,
                     		INTL_ENV_DATA_STRUCT_H   *p_intlenv_data_struct_h,
                     		DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
                  		  );


/** LR Deal Types **/

#define REDOM_LR_DEAL_MO_DEL	"16"
#define REDOM_LR_DEAL_MO_REC	"16"
#define REDOM_LR_DEAL			"16"


#define RT_LR_DEAL_MO_DEL	"15"
#define RT_LR_DEAL_MO_REC	"15"
#define RT_LR_DEAL_PO_DEL	"15"
#define RT_LR_DEAL_PO_REC	"15"
#define RT_LR_DEAL			"16"


#define RD_LR_DEAL_MO_DEL	"11"
#define RD_LR_DEAL_MO_REC	"11"
#define RD_LR_DEAL_PO_DEL	"11"
#define RD_LR_DEAL_PO_REC	"11"


#define SD_LR_DEAL_MO_BR_DEL	"02"
#define SD_LR_DEAL_MO_BR_REC	"02"
#define SD_LR_DEAL_MO_RG_DEL	"04"
#define SD_LR_DEAL_MO_RG_REC	"04"


#define RTP_LR_DEAL_MO_DEL	"16"
#define RTP_LR_DEAL_MO_REC	"16"
#define RTP_LR_DEAL		"16"

#define SP_LR_DEAL_MO_DEL	"06"
#define SP_LR_DEAL_MO_REC	"07"
#define SP_LR_DEAL		"13"




#define SD_LR_DEAL_IN_DEL	"05"
#define SD_LR_DEAL_IN_REC	"05"
#define BO_LR_DEAL_IN_DEL	"07"
#define BO_LR_DEAL_IN_REC	"07"
#define RT_LR_DEAL_IN_DEL	"05"
#define RT_LR_DEAL_IN_REC	"05"
#define SP_SP_LR_DEAL_IN_DEL	"15"
#define SP_SR_LR_DEAL_IN_DEL	"15"
#define SP_MG_LR_DEAL_IN_DEL	"16"
#define SP_TO_LR_DEAL_IN_DEL	"16"
#define SP_AM_LR_DEAL_IN_DEL	"16"
#define SP_LR_DEAL_IN_REC	"07"

#define CR_LR_DEAL_IN_DEL	"15"
#define CR_LR_DEAL_IN_REC	"07"
#define CV_LR_DEAL_IN_DEL	"08"
#define CV_LR_DEAL_IN_REC	"06"

#define BB_LR_DEAL_IN_DEL	"11"
#define BB_LR_DEAL_IN_REC	"11"
#define IPO_LR_DEAL_IN_DEL	"02"
#define IPO_LR_DEAL_IN_REC	"02"
#define RD_LR_DEAL_IN_DEL "08"
#define RD_LR_DEAL_IN_REC "08"
#define PC_LR_DEAL_IN_DEL "08"
#define PC_LR_DEAL_IN_REC "08"
/* Retro done By Darrel Viegas for ISKB_455 (Temporary ISIN processing enh KOTAK) on 10/06/2014 - Start */	

#define CV_CONV_TYPE_BO_DM_RT_SEBI_DEL "15"
/* Commented and Rewritten by Prateek on 27112014 for ISKB_455(Temp ISIN UAT Fix - Transaction code for Deliver deals of AM,WTC event should be 15 and Transaction codes for receive deals for RT,WTC should be 07 -START
#define CV_CONV_TYPE_AM_SEBI_DEL "16"
#define CV_CONV_TYPE_WTC_SEBI_DEL "08"
#define CV_CONV_TYPE_RT_WTC_SEBI_REC "05"*/
#define CV_CONV_TYPE_AM_SEBI_DEL "15"
#define CV_CONV_TYPE_WTC_SEBI_DEL "15"
#define CV_CONV_TYPE_RT_WTC_SEBI_REC "07"
/* Commented and Rewritten by Prateek on 27112014 for ISKB_455(Temp ISIN UAT Fix - Transaction code for Deliver deals of AM,WTC event should be 15 and Transaction codes for receive deals for RT,WTC should be 07*/
#define CV_CONV_TYPE_BO_AM_DM_SEBI_REC "07"
#define EVT_SPLITS_AM "AM"
#define EVT_CV_RTS "RTS"
#define EVT_WTC_CONV "WTC"


/* Retro done By Darrel Viegas for ISKB_455 (Temporary ISIN processing enh KOTAK) on 10/06/2014 - End */	


#define DEL_DEAL (!strcmp(p_deal_type, APL_DEAL_DF) || !strcmp(p_deal_type, APL_DEAL_DVP) || !strcmp(p_deal_type,APL_NO_IND))
#define REC_DEAL (!strcmp(p_deal_type, APL_DEAL_RF) || !strcmp(p_deal_type, APL_DEAL_RVP) || !strcmp(p_deal_type,APL_YES_IND))


/** LR DEAL TYPE -- Biju**/
#define CA_R_DELAY "P"
#define CA_R_SETT_CODE "J"
#define CA_R_TYPE "00"

/** LR DEAL TYPE -- Biju**/
#define S_REG_RETFRMTRANSFER    '4'
#define S_REG_OUTTOTRANSFER     '2'
#define S_REG_COMPLETED         'C'
#define APL_NSDL_DEPO   "NSDL"
#define CA_DEAL_CONF_STAT "Y"
/* Biju SP */
#define CA_DEAL_STATUS_CONF_IND "CC"
#define CA_DEAL_STATUS_AUT_IND  "AA"
#define CA_DEAL_STATUS_SETL_IND "CS"


#endif
