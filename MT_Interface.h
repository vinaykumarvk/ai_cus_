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
 * File Name           :			MT_Interface.h
 *
 * Description         :			Contains Structure Definitions for all
 *											Masters.	
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description			RFS No.
 * ---------   --------	 ---------------  -------------------		----------
 *	10/10/2005	1.0			Smita Bhat			New File					HDFCMT_003
 *
 *	10/11/2005	1.0			ANIL					Added Structure Defn	HDFCMT_002,HDFCMT_005,HDFCMT_006
 *															for Company,
 *															Instruction Slip,
 *															Client Instrument.
     14/12/2005 1.5         Manik Trivedi     Changes Related To Settlement Calender HDFCMT_008 
     16/12/2005 1.6         Anil              Daily Quotations HDFCMT_009 
     20/12/2005 1.7         Dnyanesh          Daily Float Rate		 HDFCMT_012 
     23/12/2005 1.8         Dnyanesh          No Delivery Master		 HDFCMT_007 
     24/12/2005 1.9         Sonali    		    Float rate Instrument		 HDFCMT_013 
     26/12/2005 1.10         Sonali    		 Static Data	 		 HDFCMT_016 
	  03/01/2005 1.12			Smita Bhat			 Changes in Instrument	HDFCMT_003
	  														 after Client Discussion
 *   15/10/2005	1.12	  Kouser Begum      Contains Structure Definitions				
 *   10/01/2006	1.14		Pradeep				Structure definition for	HDFCMT_017 
 *   														Index Fund Master	
 *   30/12/2005 1.15      Kouser Begum      Structure Definition for Depository Participant  HDFCMT_010     
 *   26/12/2005 1.16      Kouser Begum      Structure Definition for Credit Rating Agency    HDFCMT_011     
 *   06/01/2006 1.17      Pradeep           Structure Definition for Party Master		HDFCMT_004
 *    07/01/2006 1.17          Sundar           Vendor Maintenance   HDFMT_GFU
 *    08/02/2006 1.18			Smita Bhat		Chgs related to Col Names						HDFCCA Base Version
 *    23/02/2006 1.19	  Kouser Begum 		New Maintenance for
 *                                           Client Additional Details     KB_001
 *********************************************************************/
 
#include "CO_LenConstdef.h"
   
   
   
   
   
   
   
   
   
   

#ifndef MT_HEADER_INCLUDED
#define MT_HEADER_INCLUDED
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
 /* OPT:AIX #define IV_PARAM_LEN (201)
#define IV_STRING_LEN (31)
#define IV_GRP_LEN (51) */
#define MAX_KEY_VAL_LEN (30)
#define MAX_FLD_NAMERR_LEN (20)
#define MAX_FLD_VAL_LEN (151)
#define CHAR_DATA_TYPE (1)
#define NUM_DATA_TYPE (2)
#define INSTRUMENT_TBL (1)
#define CACCOUNT_TBL (2)
#define CLOCATION_TBL (3)
#define CTRADE_EXISTS (4)
#define CTRADE_REFNO (5)

#define GN_USERID_LEN 16
#define GN_REC_MODE_LEN 4
#define GN_ENTITY_NAME_LEN 101
#define GN_KEY_VALUE_LEN 501
#define GN_AUDIT_DATA_LEN 4001
#define GN_COMMENTS_LEN 501 
#define GN_DATA_FIELD_SEPRTR '' 
#define GN_DATA_VALUE_SEPRTR '' 

#define IV_INSTR_PARAM_CD "INSTRUMENT"	/* Bageshri for updating Instrument ALL group for Billing */
#define IV_INSTR_GRP_PARAM_CD "ALL" /* Bageshri for updating Instrument ALL group for Billing */
#define MT_SET_EXCH_CODE_LEN 11  //Added for INTEROPERABILITY - 12174

typedef struct  {
char h_currencycode[4];
char h_denom_currencycode[4];
char h_rtdt[20];
double h_exchgrt;
double h_rate_buy;
double h_sellae_rate;
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];/*Smita - Changed Col Var Name - HDFCCA Base Version*/
} MT_EXCHRATE_STRUCT_H;
typedef struct  {
char h_loccode[5];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_pos_stat[4];
char h_manifld_ind[2];
char h_status[3];/*Smita - Changed Col Var Name - HDFCCA Base Version*/
char h_locdetail[31];
char h_physical_ind[2];
char h_iso_loccode[5];
char h_avail_flag[5];
char h_depo[4];
} MT_LOCATION_STRUCT_H;
typedef struct  {
char h_holi_dt[20];
char h_holi_class[3];
char h_h_reas[31];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];/*Smita - Changed Col Var Name - HDFCCA Base Version*/
char h_hol_flag[2];
char h_old_holi_class[3];
char h_old_h_reas[31];
char h_old_hol_flag[2];
char h_bank_ind[2];
char h_exch_code[4];
} MT_HOLIDAY_STRUCT_H;
typedef struct  {
char h_currencycode[4];
char h_ccydetail[41];
char h_maker[15];
int h_dec_len;
char h_maker_dt[20];
char h_access_stamp[20];
char h_gl_cd[4];
} DL_CURRENCY_STRUCT_H;
typedef struct  {
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_stx_client[11];
char h_commn_client[11];
char h_tpymt_client[11];
char h_texp_client[11];
char h_bnk_client[11];
} MT_CLIENT_ENTRIES_STRUCT_H;
typedef struct  {
char h_nationcode[3];
char h_prodateype[3];
double h_custodytaxrt;
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_status_ind[3];
char h_checker[21];
char h_checker_dt[20];
} MT_WHTRATE_STRUCT_H;

/* Kouser - HDFCMT_001 - Client Master Maintenance  */
typedef struct  {
char h_dl_client[11];
char h_currencycode[4];
char h_our_their_ind[2];
char h_iscc_ind[2];
char h_instr_isinuseflg[2];
char h_clnt_class[5];
char h_regclr_name[81];
char h_clt_class[3];
char h_billableflag[2];
char h_classofclt[2];
char h_vtbclient[11];
char h_cltreg[13];
char h_cltmemo[201];
char h_internal_clt[21];
char h_posdt[20];
char h_base_id[7];
int h_count_swf_mon;
int h_tlxmonth_cnt;
int h_count_swf_yr;
int h_tlxyr_cnt;
char h_mstclt[11];
char h_clnt_clr_name[131];
char h_ibbsclient[11];
char h_clt_brk_all[2];
char h_shortclr_name[13];
char h_ord_clt[2];
char h_spotdlflg[2];
char h_fx_sell_flag[2];
char h_fx_buy_flag[2];
char h_fx_inc_flag[2];
char h_newdt[20];
char h_brnchcode[4];
char h_nationcode[3];
char h_fmt_rptflag[2];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_uniq_gcustody_id[13];
char h_cltprdcd[6];
char h_domestic[2];
char h_part_flg[2];
char h_allow_regflag[2];
char h_regsetlflg[2];
char h_reg_bcl_ind[2];
char h_clt_status[3];
char h_clhclient[16];
char h_taxable_ind[2];
char brk_cd[13];
char h_tax_id[11];
char h_contactinfo[61];
char h_extclhclient[13];
char h_clt_grp[5];
char h_sat_oper_cd[11];
int  h_tolerance_val;
char h_authbunch_ind[2];
char h_fxpurchasecurrency[4];
char h_fxsalecurrency[4];
char h_single548_support_ind[2];
char h_stat_tran_flag[2];
char h_trad_sett_flag[2];
char h_rhts_ret[2];
char h_valcredit[2];
char h_keep_fracredit_flag[2]; 
char h_auto_canc_ind[2];
char h_cltdetail[201];
char h_generate_flag[2];
char h_cln_add_2[61];
char h_cln_add_city[21];
char h_cln_add_state[21];
char h_cln_add_pin[11];
char h_cln_tel[21];
char h_cln_fax[21];
char h_cln_email[61];
char h_cln_cntact1[66];
char h_cln_cntact2[66];
char h_cln_sebi_ctg[5];
char h_cln_pan[21]; 
double h_cln_tds_rate;
char h_cln_glb_cust[11];
char h_cln_start_dl[2];
char h_cln_bcn_req[2];
char h_cln_def_cr_agency[7];
char h_cln_cust_id_ent[21];
int h_cln_mst_ind;
char h_cln_sign_memo[201];
char h_cln_sign_img[501];
/* Ramya - start */
char h_cln_sebi_subcat[5];
char h_cln_country[3];
char h_clncity_desc[21];
/* Ramya - end */
} MT_CLIENT_STRUCT_H;

/* By Harvinder Singh for RFS_CLN_MAP_001 Date - 7/3/2007 */
typedef struct{
char h_cln_code[21];
char h_cln_master[21];
char h_wi_login[21];
char h_login_rights[21];
char h_auto_auth[2];
char h_authorizer[21];
char h_maker[21];
char h_access_stamp[20];
}WI_CLIENT_MAP_STRUCT_H;


/*Chirag Client Cloning 070606*/
typedef struct {
char h_dl_to_client[11];
char h_dl_frm_client[11];
char h_clnt_clr_name[131];
}MT_CLIENT_CLN_STRUCT_H;

/*Chirag Client Cloning 070606*/

typedef struct {
char h_dl_client[11];
char h_cln_sebi_reg_no[21];
char h_cln_sebi_reg_dt[20];
char h_cln_sebi_reg_expdt[20];
char h_cln_rbi_reg_no[21];
char h_cln_rbi_reg_dt[20];
char h_cln_rbi_reg_expdt[20];
char h_cln_mapinid[13];
char h_cln_ucc_code[13];
char h_access_stamp[20];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
char h_sebi_sub_acc[16]; /* By Harvinder Singh -- ISKB 1266 -- Date 13May2008 */
}MT_REGDETAILS_STRUCT_H;

typedef struct  {
char h_dl_client[11];
char h_msg_ident_no[3];
int  h_addrsequence_num;
char h_swift_tlx_gcn[2];
char h_priority_ind[2];
char h_gcn_addr[6];
char h_swift_addr[201];
char h_infolex[201];
char h_schedule[5];
char h_comb_msg[2];
char h_fax_addr[15];
char h_identify[41];
char h_access_stamp[20];
char h_holdings[2];
int  h_schsequence_num;
char h_iso_msg_format[2];
char h_validate_flag[4];
char h_cln_msg_resp_cons54x[2];
char h_cln_msg_gen_rec_dp[2];
char h_maker[15];
char h_maker_dt[20]; 
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
} MT_MSGADDRESS_STRUCT_H;

typedef struct  {
char h_dl_client[11];
char h_msg_ident_no[3];
int h_schsequence_num;
char h_eom_msg_ind[2];
char h_generate_day[8];
char h_pos_txn_ind[2];
char h_nil_mov_ind[2];
char h_msg_opt[2];
char h_loc_stat[2];
char h_access_stamp[20];
char h_pend_ind[2];
char h_weeklystmt[2];
char h_validate_flag[9];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
} MT_SCHDET_STRUCT_H;

typedef struct  {
char h_dl_client[11];
char h_cln_exch_code[4];
char h_cln_exch_map_code[21];
char h_cln_hdfc_cm_id[21];
char h_access_stamp[20];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
int  h_cln_exchseq_num;
char h_status[3];
char h_slb_exch_map_code[21];  /* SLB CHGS Ashish 01-04-2008 */
} MT_CLTEXCHMAP_STRUCT_H;

typedef struct {
char h_dl_client[11];
char h_cln_depo_code[5];
char h_cln_depo_map_clnt_id[21];
char h_cln_depo_map_dp_id[21];
char h_access_stamp[20];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
int h_cln_deposeq_num;
char h_status[3];
char h_cmbp_id[12]; /*ADDED BY SIMAR FOR PMS UPLOAD ISKB_12434 */
} MT_CLTDEPOMAP_STRUCT_H;

/*Added by Prateek on 19052014 for ISKB_198(FPI Maintenance)-START*/
typedef struct  {
char h_dl_client[11];
//char h_cln_name[131];
char h_nsdl_grp_id[11];
char h_nsdl_grp_name[51];
char h_customer_id[41]; 
char h_holders[21];
char h_other_holders[2];
char h_kyc_exp_dt[20];
char h_remark[251];
char h_access_stamp[20];
char h_maker[21];
char h_maker_dt[20];
char h_checker[21];
char h_checker_dt[20];
int  h_cln_exchseq_num;
char h_status[3];
} MT_CLTFPIMAP_STRUCT_H;
/*Added by Prateek on 19052014 for ISKB_198(FPI Maintenance)-END*/

typedef struct {
char h_grp_class[3];
char h_grp_email[61];
char h_grp_contct1[66];
char h_grp_contct2[66];
char h_grp_sebictg[5];
char h_grp_pan[21];
char h_grp_agency[7];
char h_grp_code[11];
} MT_CLTGRPMAP_STRUCT_H;

/* Kouser - HDFCMT_001 - Client Master Maintenance  */

/* Kouser - KB_001  - Maintenance */

 typedef struct{
 char h_cln_code[MT_CLN_CODE_LEN];
 char h_acc_opn_dt[APL_DATE_LEN];
 char h_acc_actv_dt[APL_DATE_LEN];
 char h_acc_cls_dt[APL_DATE_LEN];
 char h_cert_pub_acc[MT_CERT_PUB_ACC_LEN];
 char h_fund_acc_mgr[MT_FUND_ACC_MGR_LEN];
 char h_spf_flg[MT_SPF_FLG_LEN];
 char h_spf_det[MT_SPF_DET_LEN];
 char h_access_stamp[APL_DATE_LEN];
 char h_maker[MT_MAKER_LEN];
 char h_maker_dt[APL_DATE_LEN];
 char h_checker[MT_CHECKER_LEN];
 char h_checker_dt[APL_DATE_LEN];
 char h_status[MT_STATUS_LEN];
 double h_tolerance_limit;
  /*CHITRLEKHA Client Additional Details STARTS*/
 char h_effective_dt[APL_DATE_LEN];
 char h_sec_cert_pub_acc[MT_SEC_CERT_PUB_ACC_LEN];
 char h_fatca1[MT_FATCA1];
 char h_fatca2[MT_FATCA2];
 char h_fatca3[MT_FATCA3];
  /*CHITRLEKHA Client Additional Details ENDS*/
  /*PANITH CSGL STARTS*/
  char h_lei_number[MT_LEI_NUMBER];
  char h_ckyc_number[MT_CKYC_NUMBER];
  char h_lei_date[APL_DATE_LEN];
  char h_lei_exp_date[APL_DATE_LEN];
  /*PANITH CSGL ENDS*/
 }MT_CLN_ADDLN_DET_STRUCT_H;				

/* Kouser - KB_001  - Maintenance */

typedef struct  {
char client_code[9];
char client_reference_no[51];
int market_type;
char deal_date[20];
char received_date[20];
char buy_sale[2];
char clh_dvp[11];
char instrument_code[9];
char instrument_type[3];
char scrip_group[3];
char party_code[21];
char exchange_code[4];
char counter_party[21];
char counter_party_custodian[21];
char settlement_party[21];
double brokerage_rate;
double deal_rate;
char unit[4];
double brokerage;
char sebi_applicable[2];
char street_registered[2];
double demat_qty;
char contract_required[2];
char matching_date[20];
char settlement_no[20];
char settlement_date[20];
char payin_date[20];
char payout_date[20];
double quantity;
double interest;
double gross_value;
double net_value;
double net_rate;
char sebi_no[21];
double stt_amount;
char benefit_status[21];
char lot_category[11];
char bcfrom[20];
char bcto[20];
char Stt_net_value[21];
char gisn_no[11];
char gbsn_no[11];
} DEAL_STRUCT_H;

typedef struct  {
char h_dl_client[11];
char h_currencycode[4];
char h_ibbsclient[11];
char h_defcurrency_flg[2];
char h_ibanclient[31];
char h_addnlclient[31];
} DL_CASHACC_STRUCT_H;

/*Smita - HDFCMT_003 - Instrument Master Maintenance*/
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
	int  h_threshold_qty;
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
	double  h_last_incom_rt;
	char h_next_pay_date[APL_DATE_LEN];
	char h_old_lst_paydt[APL_DATE_LEN];
	char h_mod_last_paydt[MT_MOD_LAST_PAYDT_LEN];
	char h_taxonmat_ind[MT_TAXONMAT_IND_LEN];
	char h_disct_ind[MT_DISCT_IND_LEN];
	char h_ca_addrdet[MT_CA_ADDRDET_LEN];
	double h_min_fmt_dl_qty;
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
	double h_instr_tot_nom_val;
	char h_instr_pc_ind[MT_INSTR_PC_IND_LEN];
/*	Smita - Commented Effective Date & CutOff Time - HDFCMT_003 
 	char h_instr_pc_effdt[APL_DATE_LEN];
	char h_instr_pc_cutofftime[APL_DATE_LEN];
*/
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
 char h_instr_sub_type[MT_INSTR_TYPE_LEN];
 	//Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- Start 
	char h_instr_tier_1[2];
	char h_instr_tier_2[2];
	// Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- End 
        /* Added  by Gouse For Decimal Length of MF- Start - 31/10/2011 */
        int h_dec_len_mf;
        /* Added  by Gouse For Decimal Length of MF- End - 31/10/2011 */
        //Retro from ICICI for CLM by Bhuvana -- Start 
	   char h_instr_corporate_grp[201];
	   double h_instr_diluted_ratio_new;
	   double h_instr_diluted_ratio_old;
       //Retro from ICICI for CLM by Bhuvana -- ENDS */  
}MT_INSTRUMENT_STRUCT_H;

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
}MT_INSTRUMENT_RED_DEP_STRUCT_H;

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
	char h_scrip_code[13]; /* Chages by rahul6 for T0 Enhancement */
} MT_INSTRUMENT_EXCH_STRUCT_H;

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
} MT_INSTRUMENT_CR_AGENCY_STRUCT_H;

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_pc_flag[MT_PC_FLAG_LEN];
	char h_pc_date[APL_DATE_LEN];
	char h_pc_notice_date[APL_DATE_LEN];
	/*Smita - Added Effective Date & Cut Off Time in this structure - HSFCMT_003*/
	char h_instr_pc_effdt[APL_DATE_LEN];
	char h_instr_pc_cutofftime[APL_DATE_LEN];
	/*Smita - Added Effective Date & Cut Off Time in this structure - HSFCMT_003*/
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
} MT_INSTRUMENT_PC_STRUCT_H;

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_red_dt[APL_DATE_LEN];
	double h_red_pct;
	double h_red_value;
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
} MT_INSTRUMENT_PART_RED_STRUCT_H;

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_ptc_dt[APL_DATE_LEN];
	double h_ptc_prin_amt;
	double h_ptc_int_amt;
	double h_ptc_value;
	char h_ptc_paid_flg[MT_PTC_PAID_FLG_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
 double h_ptc_bal_val;
} MT_INSTRUMENT_PTC_STRUCT_H;

typedef struct{
	char h_instr_code[MT_INSTR_CODE_LEN];
	int h_instr_seq_num;
	char h_reset_dt[APL_DATE_LEN];
	double h_reset_rate;
	char h_reset_frdt[APL_DATE_LEN];
	char h_reset_todt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
} MT_INSTRUMENT_RESET_STRUCT_H;

/*Structure Added for Credit Rating Agency*/
typedef struct {
char h_agency_code[MT_CR_AGENCY_CODE_LEN];
char h_agency_name[61];
char h_agency_addr1[61];
char h_agency_addr2[61];
char h_agency_city[4];
char h_agency_state[3];
char h_aadr_cnt[3];
char h_addr_pin[11];
char h_agency_tel[21];
char h_agency_fax[21];
char h_agency_email[61];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
}	MT_CR_AGENCY_STRUCT_H;

typedef struct {
char h_agency_code[MT_CR_AGENCY_CODE_LEN];
char h_rating_code[7];
char h_rating_desc[41];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
char h_access_stamp[20];
int h_cr_seq_num; 
} MT_CR_AGENCY_DET_STRUCT_H;

/*Smita - HDFCMT_003 - Instrument Master Maintenance*/


/* Kouser - Depository Participant - HDFCMT_010  */

typedef struct{
        char h_depo_code[MT_DEPO_CODE_LEN];
        char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
        char h_depo_part_contact1[MT_DEPO_PART_CONTACT1_LEN];
        char h_depo_part_add_1[MT_DEPO_PART_ADD_1_LEN];
        char h_depo_part_add_2[MT_DEPO_PART_ADD_2_LEN];
        char h_depo_part_add_city[MT_DEPO_PART_ADD_CITY_LEN];
        char h_depo_part_add_state[MT_DEPO_PART_ADD_STATE_LEN];
        char h_depo_part_add_cnt[MT_DEPO_PART_ADD_CNT_LEN];
        char h_depo_part_add_pin[MT_DEPO_PART_ADD_PIN_LEN];
        char h_depo_part_tel[MT_DEPO_PART_TEL_LEN];
        char h_depo_part_fax[MT_DEPO_PART_FAX_LEN];
        char h_depo_part_email[MT_DEPO_PART_EMAIL_LEN];
        char h_maker[MT_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_access_stamp[APL_DATE_LEN];
        char h_checker[MT_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_status[MT_STATUS_LEN];
        char h_depo_name[MT_DEPO_NAME_LEN];/* Depo Participant Name in Depo Participant Master - by Gouse */
}MT_DEPO_PART_STRUCT_H;

 typedef struct{
        char h_depo_code[MT_DEPO_CODE_LEN];
        char h_depo_part_code[MT_DEPO_PART_CODE_LEN];
        char h_exch_code[MT_EXCH_CODE_LEN];
        char h_cc_id[MT_CC_ID_LEN];
        char h_cm_cc_id[MT_CM_CC_ID_LEN];
        char h_cln_id[MT_CLN_ID_LEN];
        char h_dp_id[MT_DP_ID_LEN];
        char h_maker[MT_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_access_stamp[APL_DATE_LEN];
        char h_checker[MT_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_status[MT_STATUS_LEN];
}MT_EXCH_DEPO_STRUCT_H;


/* Kouser - Depository Participant - HDFCMT_010  */

typedef struct  {
char client[11];
char b_ccycd[4];
char fees_ccy[4];
char send_to_master_ind;
char b_gen_ind;
double minimumfee;
char minimumfee_to;
char min_hld_adj;
char bcustsetup_access_stamp[20];
char dir_db_ind;
char spl_clt_cd[7];
char comm_clt[11];
char rec_clt[APL_CLIENT_LENGTH_GL];  /* Bageshri HDFCIV_001*/
char information[241];
double total_osamount;		/* Bageshri HDFCIV_001*/
char default_feeclt[11];
double comm_tax_amt;
char vat_cd[51]; 		
char vat_note[121]; 
char oblg_lvl[21];			/** Bageshri  HDFCIV_001 **/
char oblg_typ[21];
int pay_in_day;
int pay_out_day;
char b_freq;
double pay_out_lmt;
char dvp_ind;
char acc_typ;
char pay_in_acc[APL_CLIENT_LENGTH_GL];
char pay_out_acc[APL_CLIENT_LENGTH_GL];
char acc_code1[APL_CLIENT_LENGTH_GL];
char acc_code2[APL_CLIENT_LENGTH_GL];
char acc_code2desc[66];
char oblig_rep_flg[3];
char calc_basis;
char portfolio_eval;
char nav_ind;
char ann_fee_month[16];
char cln_supermst[APL_CLIENT_LENGTH];
char bnk_acc[APL_CLIENT_LENGTH_GL];   /** Bageshri  HDFCIV_001 *END*/
char maximumfee_to;
char max_hld_adj;
double txnminfee;
double txnmaxfee;
double maximumfee;  /* Bageshri */
char lst_bill_dt[APL_DATE_LEN];/* Bageshri */
char pymt_acc[APL_CLIENT_LENGTH_GL];/* Bageshri */
char bnk_fcy_acc[APL_CLIENT_LENGTH_GL];   /* YOG 211206 */
char dir_db_date[3];/** vinay **/
char b_basis[4];/** Bageshri  HB_IV_001 START **/
char b_dlv_date[APL_DATE_LEN];
int rep_pay_in_day;
int rep_pay_out_day;
char b_basis_cust[4];/** Bageshri  HB_IV_001 END **/
double ann_min_chrg;/*added by shruthi kumbla for ISKB_1737*/
} IV_CLIENTPARAM_STRUCT;

typedef struct  {
char client[11];
long service_cd;	/* Bageshri  HDFCIV_001  */
char parameter_cd[201];
double minimumfee;
double nil_fees;
double maximum_fee;
char fees_base[31];
char chrg_base[31];
char fees_class;
char chrg_clas;
char bcustsetup_access_stamp[20];
char dealadm_feeccy[4];
char bill_acc[APL_CLIENT_LENGTH_GL];			/** Bageshri  HDFCIV_001 **/
char lst_bill_dt[APL_DATE_LEN];/* vinay */
char b_freq;/* vinay */
char incld_in_ann_min_fee;/*added by shruthi kumbla for ISKB_1737*/
char pls_month[4]; /* Added for kotak ISKB_1737 */
char apl_frm_date[9]; /* Added for kotak ISKB_1737 */
} IV_CLIENTSERVDEP_STRUCT_H;
typedef struct  {
char client[11];
long service_cd;	/* Bageshri  HDFCIV_001  */
char proc_data_val[201];
char group_id[51];
double frm_cbase;
double frm_fbase;
double toc_base;  /* Added for Billing Structure Upload */
double schdl_fee;
char fee_type;
char bcustsetup_access_stamp[20];
char apl_frm_date[9]; /* Added for Kotak ISKB_1737 */
} IV_CUSTFEE_STRUCT_H;
typedef struct  {
char h_typeofinstr[4];
char h_ca_event[3];
char h_pymtout_ind[2];
char h_entitl_base[2];
char h_ratio_perc_ind[2];
char h_amt_rt_ind[2];
char h_new_dl_ind[2];
char h_evtmsg_all_mstclt[2];
char h_gen_enrarep_ind[2];
int h_enra_lapse_a;
int h_enra_lapse_b;
int h_enra_lapse_c;
int h_closure_dt_days; /*retro by Sana Bhatkar - Added by Santhoshi for PEG-CA-ENH-2.3*/
} CA_CASECEVENT_STRUCT_H;
typedef struct  {
char h_nation_code[3];
char h_typeofinstr[4];
char h_prodateype[3];
char h_evt_class[3];
int h_no_days_pymtdt;
int h_exdate_no_days;
} CA_AUTOEVENT_STRUCT_H;
typedef struct  {
char h_fld_val[30];
char p_link_val[20];
int table_clr_name;
int info_type;
} RTV_VAL_STRUCT;
typedef struct  {
char h_dl_client[11];
char h_cltnm[71];
char h_synclt[6];
char h_clttyp[3];
char h_clt_typ[3];
int h_baseclt;
char h_cltopdt[20];
char h_cltcldt[20];
char h_nostr_cltptyp[21];
char h_nostr_clttyp[21];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_newdt[20];
char h_cltstatus[3];
} MT_RUCLIENT_STRUCT_H;
typedef struct  {
char h_loc[5];
char h_locm[71];
char h_syn_location[6];
char h_license_no[21];
char h_loc_class[3];
char h_depo_cd[26];
int h_baseloc;
char h_locopdate[20];
char h_loccldate[20];
char h_nostr_cltptyp[21];
char h_nostr_clttyp[21];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_newdt[20];
char h_rulocstatus_ind[3];
} MT_RULOC_STRUCT_H;
typedef struct  {
char h_pr_code[4];
char h_prdetail[21];
char h_ccy[4];
char h_daydate[4];
char h_day_yr[4];
char h_prdateyp[4];
char h_intclass[4];
char h_loc[5];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_newdt[20];
char h_prodstatus_ind[3];
} MT_RUPROD_STRUCT_H;
typedef struct  {
char h_stat_reg_no[21];
char h_instr_code[9];
char h_instr_name[51];
char h_identiy_num[11];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_newdt[20];
char h_srnstatus_ind[3];
} MT_RUSRN_STRUCT_H;
typedef struct  {
char h_instr_code[9];
char h_instr_nm[71];
char h_snm_ind[76];
char h_stat_reg_no[21];
char h_instr_opdate[20];
char h_instrcldate[20];
char h_instr_cldate[4];
int h_baseinstrument;
char h_instr_class[4];
char h_pr_code[4];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
char h_newdt[20];
char h_ruinstrstatus_ind[3];
} MT_RUINSTR_STRUCT_H;
typedef struct  {
char h_mhlp_code[13];
char h_lcl_brkcd[11];
char h_lcl_opcd[11];
char h_dl_client[11];
char h_mstclt[11];
char h_custodian_clt[11];
char h_manual_ind_intn[2];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_mhlp_stat[3];
char h_access_stamp[20];
char h_lbrk_mstclt[11];
} MHLP_CODE_STRUCT_H;
typedef struct  {
char h_dl_client[11];
char h_setl_eff_date[20];
char h_stat_eff_date[20];
char h_ca_eff_date[20];
char h_stmsg_eff_date[20];
char h_access_stamp[20];
} MS_MSGCONV_STRUCT_H;
typedef struct  {
char h_mem_ident[13];
char h_instr_clt[11];
char h_brkcd[13];
char h_alternate_bidcd[13];
char h_detailription[66];
char h_mtch_detail[66];
char h_status_ind[3];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_access_stamp[20];
} PRO_HDAT_STATIC_STRUCT_H;

/* ANIL HDFCMT_002 Company */
typedef struct {
char h_cmp_code[11];
char h_cmp_name[66];
char h_cmp_shortnm[13];
char h_cmp_oldname[66];
char h_cmp_add1[61];
char h_cmp_add2[61];
char h_cmp_add_city[4];
char h_cmp_add_state[3];
char h_cmp_add_cnt[3];
char h_cmp_add_pin[11];
char h_cmp_tel[21];
char h_cmp_fax[21];
char h_cmp_webadd[61];
char h_cmp_swf_name[21];
char h_cmp_secnm[41];
char h_cmp_sec_email[61];
char h_cmp_mdnm[41];
char h_cmp_industrycd[4];
char h_cmp_sectorcd[4];
char h_cmp_remarks[201];
double h_cmp_authcapital;
double h_cmp_issuedcapital;
double h_cmp_tpcapital;
char h_cmp_maker[15];
char h_cmp_maker_dt[20];
char h_access_stamp[20];
char h_cmp_checker[15];
char h_cmp_checker_dt[20];
char h_cmp_status[3];
} MT_COMPANY_STRUCT_H;
/* ANIL HDFCMT_002 Company */

/* ANIL HDFCMT_005 client_instrument */
typedef struct {
char h_cln_code[11];
char h_instr_code[9];
char h_cln_instr_code[21];
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
} MT_CLN_INSTR_STRUCT_H;
/* ANIL HDFCMT_005 client_instrument */

/* HDFCMT_006 ANIL INSTRUCTION SLIP */
typedef struct  {
char h_depo_code[5];
char h_depo_part_code[21];
char h_cln_code[11];
char h_trans_type[4];
char h_slip_series[6];
int h_sr_no_from;
int h_sr_no_to;
int h_sr_avl_qty;
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
} MT_INSL_ENTRY_STRUCT_H;
/* HDFCMT_006 ANIL INSTRUCTION SLIP */

/* HDFCMT_008 SETTLEMENT CALENDAR MANIK */

typedef struct
{
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
}
MT_SETTLCAL_STRUCT_H;

/* HDFCMT_008 SETTLEMENT CALENDAR MANIK */

/* HDFCMT_009 DAILY QUOTATIONS ANIL */
typedef struct
{
char h_exch_code[4];
char h_instr_code[9];
char h_quot_date[20];
double h_quot_prev_date;
double h_open_at;
double h_high_at;
double h_low_at;
double h_close_at;
char h_maker[15];
char h_maker_dt[20];
char h_access_stamp[20];
char h_checker[15];
char h_checker_dt[20];
char h_status[3];
} MT_DLYQTIONS_STRUCT_H;
/* HDFCMT_009 DAILY QUOTATIONS ANIL */

/* HDFCMT_012 Daily Float Rate - Dnyanesh*/
typedef struct
{
  char   h_benchmark_code[MT_BENCHMARKCODE_LEN];
   char   h_rate_date[APL_DATE_LEN];
   double h_float_rate1;
   double h_float_rate2;
   double h_float_rate3;
   double h_std_deviation;
   char   h_maker[MT_MAKER_LEN];
   char   h_maker_dt[APL_DATE_LEN];
   char   h_access_stamp[APL_DATE_LEN];
   char   h_checker[MT_CHECKER_LEN];
   char   h_checker_dt[APL_DATE_LEN];
   char   h_status[MT_STATUS_LEN];
}
MT_DLFLRATE_STRUCT_H;

/* HDFCMT_014 RBI Monitory Details - Dnyanesh*/

typedef struct
{
	char   h_instr_code[MT_INSTR_CODE_LEN];
	char   h_rbi_instr_code[MT_RBI_INSTR_CODE_LEN];
	double h_tpcapital;
	double h_sng_fii_limit;
	double h_ovr_fii_limit;
	double h_sng_nriocb_limit;
	double h_ovr_nriocb_limit;
	char  h_caution_flg[2];
	double h_caution_fii;
	double h_caution_nriocb;
	char   h_maker[MT_MAKER_LEN];
	char   h_maker_dt[APL_DATE_LEN];
	char   h_access_stamp[APL_DATE_LEN];
	char   h_checker[MT_CHECKER_LEN];
	char   h_checker_dt[APL_DATE_LEN];
	char   h_status[MT_STATUS_LEN];
        char   h_def_cln_type[MT_DEF_CLN_TYPE_LEN];//Added by Shyam
	char   h_far[2]; /* Chages for T0 Enhancement */
}
MT_RBIMONDET_STRUCT_H;


/* HDFCMT_007 No Delivery Details - Dnyanesh*/
typedef struct
{
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
}
MT_NO_DELV_STRUCT_H;


/*HDFCMT_013 Float Rate Instrument - Sonali */
typedef struct
{
   char     h_instr_code[MT_INSTR_CODE_LEN];
   char     h_daily_compound[2];
   char     h_excl_holidays[2];
   int      h_int_pay_days;
   char     h_compounding_wdays[2];
   double   h_floor_rate;
   double   h_cap_rate;
   char     h_prefd_seq[15];
   char     h_default_float_rate[2];
   char     h_benchmark_code[MT_MIBOR_CODE_LEN];
   double   h_base_margin;
   char     h_fixed_bench[2];
   char     h_maker[MT_MAKER_LEN];
   char     h_maker_dt[APL_DATE_LEN];
   char     h_access_stamp[APL_DATE_LEN];
   char     h_checker[MT_CHECKER_LEN];
   char     h_checker_dt[APL_DATE_LEN];
   char     h_status[MT_STATUS_LEN];
}
MT_FLRATEINST_STRUCT_H;

/*HDFCMT_013 Float Rate Instrument - Sonali */

/*HDFCMT_016 Static Data*/
typedef struct{
	char h_code_ident[CO_CODE_IDENT_LEN];
	char h_code_value[CO_CODE_VALUE_LEN];
	char h_code_desc[CO_CODE_DESC_LEN];
	char h_country_code[CO_COUNTRY_CODE_LEN];
}CO_STATIC_DATA_STRUCT_H;
/*HDFCMT_016 Static Data*/

/* HDFCMT_017 INDEX FUND MASTER PRADEEP */

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
	int  h_index_seq_num;
	char h_index_fund_num[MT_INDEX_FUND_NUM_LEN];
	char h_instr_code[MT_INSTR_CODE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_INDEX_FUNDDET_STRUCT_H;

/* HDFCMT_004 - Party Master - Pradeep */

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
	char h_pty_bic_code[MT_PTY_BIC_CODE_LEN];
	char h_set_exch_code[MT_SET_EXCH_CODE_LEN];     //Added for INTEROPERABILITY - 12174
	char h_csgl_apl[2];
}MT_PARTY_STRUCT_H;

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
   char h_pty_sebi_reg_no1[MT_PTY_SEBI_REG_NO_LEN];/* Kouser - HDFCMT_004 - New Cols */
   char h_pty_sebi_reg_no2[MT_PTY_SEBI_REG_NO_LEN];/* SebiRegNo1,SebiRegNo2 Added */
}MT_PTY_EXCH_MAP_STRUCT_H;

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
        char h_exch_code[MT_EXCH_CODE_LEN];
        char h_cmbp_id[MT_PTY_CMBP_ID_LEN];
}MT_PTY_DEPO_MAP_STRUCT_H;

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

/* HDFCMT_GFU  Vendor Maintenance - Sundar */

typedef struct{
	char h_vendor_code[MT_VENDOR_CODE_LEN];
	char h_vendor_name[MT_VENDOR_NAME_LEN];
	char h_add_line1[MT_ADD_LINE1_LEN];
	char h_add_line2[MT_ADD_LINE2_LEN];
	char h_country_code[MT_COUNTRY_CODE_LEN];
	char h_state_code[MT_STATE_CODE_LEN];
	char h_city_code[MT_CITY_CODE_LEN];
	char h_pin_code[MT_PIN_CODE_LEN];
	char h_fax_no[MT_FAX_NO_LEN];
	char h_tel_no[MT_TEL_NO_LEN];
	char h_web_address[MT_WEB_ADDRESS_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_GFU_VENDOR_SETUP_STRUCT_H;

typedef struct{
	char h_ref_no[MT_REF_NO_LEN];
	char h_excel_field_name[MT_EXCEL_FIELD_NAME_LEN];
	char h_excel_reference_value[MT_EXCEL_REFERENCE_VALUE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_GFU_EXCEL_SETUP_STRUCT_H;

typedef struct{
	char h_ref_no[MT_REF_NO_LEN];
	char h_txt_field_name[MT_TXT_FIELD_NAME_LEN];
	int h_start_pos;
	int h_end_pos;
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_GFU_TXT_SETUP_STRUCT_H;

/* HDFCMT_GFU  Vendor Maintenance - Sundar */

/* HDFCMT_GFU  Vendor Maintenance - Sundar */

typedef struct{
	char h_vendor_id[MT_VENDOR_ID_LEN];
	char h_function_id[MT_FUNCTION_ID_LEN];
	char h_file_type[MT_FILE_TYPE_LEN];
	char h_copy_exist[MT_COPY_EXIST_LEN];
	char h_delimeter[MT_DELIMETER_LEN];
	char h_ref_no[MT_REF_NO_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_skip_line[21];
	int  h_format_line;
	int  h_header_pos;
	char h_header_chk[2];
	char h_module_name[21];	/** Added By Sana For GFU Setup **/
	char h_skip_ind[21];/*Added by Sharanya for Margin Upload **/
	char h_char_ind[21];/*Added by Sharanya for Margin Upload **/
	char h_unique_key[61];/*Added by Sharanya for Margin Upload **/
	char h_read_from_file[61];/*Added by Sharanya for Margin Upload **/
}MT_GFU_FORMAT_SETUP_STRUCT_H;

typedef struct{
	char h_ref_no[MT_REF_NO_LEN];
	char h_csv_field_name[MT_CSV_FIELD_NAME_LEN];
	char h_csv_reference_value[MT_CSV_REFERENCE_VALUE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_access_stamp[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
}MT_GFU_CSV_SETUP_STRUCT_H;

/* blob data */
 typedef struct {
 long len;
 unsigned char arr[1];
 } type_raw;

/* HDFCMT_GFU  Vendor Maintenance - Sundar */

/* Bageshri  - MT Party Fund Details 27/04/06 */

typedef struct{
	char h_pty_code[MT_PTY_CODE_LEN];
   int h_pay_in_day;
	int h_pay_out_day;
	char h_acc_typ;
	char h_pay_in_acc[APL_CLIENT_LENGTH_GL];
	char h_pay_out_acc[APL_CLIENT_LENGTH_GL];
	char h_acc_code1[APL_CLIENT_LENGTH_GL];
	char h_acc_code2[APL_CLIENT_LENGTH_GL];
	char h_acc_code2desc[66];
	char h_access_stamp[APL_DATE_LEN];
	char h_maker[MT_MAKER_LEN];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[MT_CHECKER_LEN];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[MT_STATUS_LEN];
	char h_pty_bnk_acc[APL_CLIENT_LENGTH_GL];
}MT_PTY_FUND_DET_STRUCT_H;

/* Bageshri  - MT Party Fund Details 27/04/06 */
/* PJ */
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
	char h_dl_client[APL_CLIENT_LENGTH];
	char h_cln_refno[17];
	char h_instr_code[9];
	char h_deal_cd[2];
	double h_qty;
	double h_amount;
	char h_deal_date[APL_DATE_LEN];
	char h_payin_date[APL_DATE_LEN];
	char h_payout_date[APL_DATE_LEN];
	char h_setl_date[APL_DATE_LEN];
}CA_GN_AUDIT_LOG_STRUCT_H;
typedef struct{
		char h_upld_datetime[APL_DATE_LEN];
		char h_upld_filename[51];
		char h_scrip_symbol[3];
		char h_exch_instr_code[13];
		char h_scrip_grp[3];
		char h_isin[13];
		double h_security_var;
		double h_index_var;
		double h_var_rate;
		double h_elm_rate;
		double h_additional_rate;
		double h_tot_rate;
		char h_instr_code[13];
}VARELM_UPLOAD_NSE_STRUCT_H;
typedef struct{
		char h_upld_datetime[APL_DATE_LEN];
		char h_upld_filename[51];
		char h_sr_no[6];
		char h_scrip_code[7];
		char h_scrip_name[13];
		char h_isin[13];
		double h_var_per;
		double h_fivar_per;
		char h_processon[9];
		char h_appli_on[9];
		double h_var_rate;
		double h_elm_per;
		double h_elm_rate;
		double h_tot_varelm;
		char h_instr_code[13];
}VARELM_UPLOAD_BSE_STRUCT_H;

extern int wrp_CBUpdCcyFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_CURRENCY_STRUCT_H *p_dl_currency_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdExrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdLocFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_LOCATION_STRUCT_H *p_mt_location_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdHolFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdWklyOffFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a_b,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CDBUpdAenFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLIENT_ENTRIES_STRUCT_H *p_mt_client_entries_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdWtrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_WHTRATE_STRUCT_H *p_mt_whtrate_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBCpyAccAddrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     char *chr_p_to_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBCpyAccSchFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     char *chr_p_to_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBCpyAccMemoFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccMemoFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_memo,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccSchFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_SCHDET_STRUCT_H *p_mt_schdet_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccAddrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_MSGADDRESS_STRUCT_H *p_mt_msgaddress_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccCashFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAccOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */

extern int wrp_CBUpdAccRegFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_REGDETAILS_STRUCT_H *p_mt_regdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,  
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr 
#endif
);

extern int wrp_CBUpdAccExchMapFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLTEXCHMAP_STRUCT_H *p_mt_cltexchmap_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

extern int wrp_CBUpdAccDepoMapFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLTDEPOMAP_STRUCT_H *p_mt_cltdepomap_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */

/* Kouser - RFSNo - KB_001 - Maintenance */

extern int wrp_MT_ClnAddLnDetFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLN_ADDLN_DET_STRUCT_H *p_mt_cln_addln_det_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* Kouser - RFSNo - KB_001 - Maintenance */

extern int wrp_CBUpdInstrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdInstrOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_instr_code,
     char *p_instr_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlCustMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENTPARAM_STRUCT *l_iv_clientparam_struct,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlCustServDepncy(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENTSERVDEP_STRUCT_H *p_iv_clientservdep_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_BBlCustFeeMnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CUSTFEE_STRUCT_H *l_iv_custfee_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_GBInsReptFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_repname,
     char *p_repdesc,
     int p_repwidateh,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_GBReprintFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_rep_name,
     char *p_prn_name,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_UpdateCommonSysParams(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_COMMON_SYS_PARAMS_STRUCT_H *p_mt_common_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_UpdateCoreSysParams(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CORE_SYS_PARAMS_STRUCT_H *p_mt_core_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_UpdateMessageSysParams(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_MESSAGE_SYS_PARAMS_STRUCT_H *p_mt_message_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_UpdateBillSysParams(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     INVOICE_SYSTEMPARAM_STRUCT_H *p_invoice_systemparam_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_A_InputAutoEvnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_A_UpdateAutoEvnt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_A_UpdateAsecevt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_A_InputAsecevt(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_GetFieldVal(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     RTV_VAL_STRUCT *p_rtv_val_struct,
     char p_field_val[151],
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
extern int wrp_CBUpdCustFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdCustOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRLocFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRLocOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_rrloc,
     char *chr_p_rrloc_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRProdFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRProdOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_rrprod,
     char *chr_p_rrprod_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRSRNFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdRRInstrFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUINSTR_STRUCT_H *p_mt_ruinstr_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAssisFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MHLP_CODE_STRUCT_H *l_mhlp_code_struct_hc,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdAssisOthFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_assiscode,
     char *chr_p_lbrkcode,
     char *p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_CBUpdMsgConv(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_MSGCONV_STRUCT_H *p_ms_msgconv_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct core_maint_v1_0_epv_t {
int (*wrp_CBUpdCcyFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_CURRENCY_STRUCT_H *p_dl_currency_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdExrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdLocFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_LOCATION_STRUCT_H *p_mt_location_struct_h_c,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdHolFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdWklyOffFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a_b,
     MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CDBUpdAenFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLIENT_ENTRIES_STRUCT_H *p_mt_client_entries_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdWtrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_WHTRATE_STRUCT_H *p_mt_whtrate_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_e,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBCpyAccAddrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     char *chr_p_to_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBCpyAccSchFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     char *chr_p_to_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBCpyAccMemoFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_from_acct,
     char *chr_p_to_acct,
     char *chr_p_from_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccMemoFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_memo,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccSchFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_SCHDET_STRUCT_H *p_mt_schdet_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccAddrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_MSGADDRESS_STRUCT_H *p_mt_msgaddress_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccCashFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAccOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */

int (*wrp_CBUpdAccRegFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_REGDETAILS_STRUCT_H *p_mt_regdetails_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

int (*wrp_CBUpdAccExchMapFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLTEXCHMAP_STRUCT_H *p_mt_cltexchmap_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

int (*wrp_CBUpdAccDepoMapFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLTDEPOMAP_STRUCT_H *p_mt_cltdepomap_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */

/* Kouser - RFSNo - KB_001 - Maintenance */


int (*wrp_MT_ClnAddLnDetFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CLN_ADDLN_DET_STRUCT_H *p_mt_cln_addln_det_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

int (*wrp_CBUpdInstrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdInstrOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_instr_code,
     char *p_instr_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlCustMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENTPARAM_STRUCT *l_iv_clientparam_struct,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlCustServDepncy)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CLIENTSERVDEP_STRUCT_H *p_iv_clientservdep_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_BBlCustFeeMnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     IV_CUSTFEE_STRUCT_H *l_iv_custfee_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_GBInsReptFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_repname,
     char *p_repdesc,
     int p_repwidateh,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_GBReprintFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_rep_name,
     char *p_prn_name,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_UpdateCommonSysParams)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_COMMON_SYS_PARAMS_STRUCT_H *p_mt_common_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_UpdateCoreSysParams)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_CORE_SYS_PARAMS_STRUCT_H *p_mt_core_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_UpdateMessageSysParams)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_MESSAGE_SYS_PARAMS_STRUCT_H *p_mt_message_sys_params_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_UpdateBillSysParams)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     INVOICE_SYSTEMPARAM_STRUCT_H *p_invoice_systemparam_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_A_InputAutoEvnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_A_UpdateAutoEvnt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_a,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_A_UpdateAsecevt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_A_InputAsecevt)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_b,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_GetFieldVal)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     RTV_VAL_STRUCT *p_rtv_val_struct,
     char p_field_val[151],
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h
#endif
);
int (*wrp_CBUpdCustFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdCustOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_acct,
     char *chr_p_acct_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRLocFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRLocOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_rrloc,
     char *chr_p_rrloc_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRProdFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_b,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRProdOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_rrprod,
     char *chr_p_rrprod_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRSRNFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdRRInstrFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_RUINSTR_STRUCT_H *p_mt_ruinstr_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAssisFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MHLP_CODE_STRUCT_H *l_mhlp_code_struct_hc,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdAssisOthFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_assiscode,
     char *chr_p_lbrkcode,
     char *p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_CBUpdMsgConv)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MS_MSGCONV_STRUCT_H *p_ms_msgconv_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_MTUpdCompanyFn)(
    #ifdef IDL_PROTOTYPES
   handle_t IDL_handle,
   MT_COMPANY_STRUCT_H *p_mt_company_struct_h_a,
    INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);

/* ANIL HDFCMT_005 client_instrument */
int (*wrp_MTUpdClnInstFn)(
#ifdef IDL_PROTOTYPES
   handle_t IDL_handle,
   MT_CLN_INSTR_STRUCT_H *p_mt_cln_instr_struct_h,
    INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* ANIL HDFCMT_005 client_instrument */

/* HDFCMT_006 ANIL INSTRUCTION SLIP */
int (*wrp_MTUpdInslEntryFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_INSL_ENTRY_STRUCT_H *p_mt_insl_entry_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* HDFCMT_006 ANIL INSTRUCTION SLIP */

/* HDFCMT_008 SETTLEMENT CALENDAR MANIK */
int (*wrp_MTUpdSettlcalFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_SETTLCAL_STRUCT_H *p_mt_settlcal_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* HDFCMT_008 SETTLEMENT CALENDAR MANIK */
/* HDFCMT_009 ANIL DAILY QUOTATIONS*/
int (*wrp_MTUpdDailyQuotFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     MT_DLYQTIONS_STRUCT_H *p_mt_dlyqtions_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* HDFCMT_009 ANIL DAILY QUOTATIONS*/
/* HDFCMT_012 Daily Float Rate - Dnyanesh*/
int (*wrp_MTUpdDlFlRateFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_DLFLRATE_STRUCT_H *p_mt_dlflrate_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
/* HDFCMT_012 Daily Float Rate - Dnyanesh*/

/* HDFCMT_014 RBI Monitory Details - Dnyanesh*/
int (*wrp_MTUpdRBIMonDetFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_RBIMONDET_STRUCT_H *p_mt_rbimondet_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
/* HDFCMT_014 RBI Monitory Details - Dnyanesh*/

/* HDFCMT_007 No Delivery Details - Dnyanesh*/
int (*wrp_MTUpdNoDlvDetFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_NO_DELV_STRUCT_H *p_mt_no_delv_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
/* HDFCMT_007 No Delivery Details - Dnyanesh*/
/* HDFCMT_013 Float Rate Instrument - Sonali*/
int (*wrp_MTUpdFloatRateInstFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_FLRATEINST_STRUCT_H *p_mt_flrateinst_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
										      );
/* HDFCMT_013 Float Rate Instrument- Sonali*/

/* HDFCMT_016 Static Data- Sonali*/
int (*wrp_MTUpdStaticDataFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		CO_STATIC_DATA_STRUCT_H *p_co_static_data_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
/* HDFCMT_016 Static Data- Sonali*/
										      );
/* HDFCMT_017 INDEX FUND MASTER PRADEEP */
int (*wrp_MTUpdIndexFundFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_INDEX_FUND_STRUCT_H *p_mt_index_fund_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_MTUpdIndexFundDetFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_INDEX_FUNDDET_STRUCT_H *p_mt_index_funddet_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
/* HDFCMT_017 INDEX FUND MASTER PRADEEP */

/* HDFCMT_010 - Depository Participant - Kouser */

 int (*wrp_MTUpdDepoPartFn)(
      #ifdef IDL_PROTOTYPES
      handle_t IDL_handle,
      MT_DEPO_PART_STRUCT_H *p_mt_depo_part_struct_h,
      INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
      DEBUG_INFO_STRUCT_H **l_debug_info_ptr
      #endif
      );

 int (*wrp_MTUpdExchDepoFn)(
      #ifdef IDL_PROTOTYPES
      handle_t IDL_handle,
      MT_EXCH_DEPO_STRUCT_H *p_mt_exch_depo_struct_h,
      INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
      DEBUG_INFO_STRUCT_H **l_debug_info_ptr
      #endif
      );
 
/* HDFCMT_010 - Depository Participant - Kouser*/

/* HDFCMT_011 - Credit Rating Agency Details - Kouser*/

   int (*wrp_MTUpdCrAgencyFn)(
   #ifdef IDL_PROTOTYPES
   handle_t IDL_handle,
   MT_CR_AGENCY_STRUCT_H *p_mt_cr_agency_struct_h,
   INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
   DEBUG_INFO_STRUCT_H **l_debug_info_ptr
   #endif
 );
 int (*wrp_MTUpdCrAgencyDetFn)(
       #ifdef IDL_PROTOTYPES
       handle_t IDL_handle,
       MT_CR_AGENCY_DET_STRUCT_H *p_mt_cr_agency_det_struct_h,
       INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
       DEBUG_INFO_STRUCT_H **l_debug_info_ptr
       #endif
    );
/* HDFCMT_011 - Credit Rating Agency Details - Kouser*/

/* Pradeep - HDFCMT_004 - Party Master */
 int (*wrp_MTUpdPartyFn)(
#ifdef IDL_PROTOTYPES
		 handle_t IDL_handle,
		 MT_PARTY_STRUCT_H *p_mt_party_struct_h,
		 INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		 DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		 );
 int (*wrp_MTUpdPartyExchMapFn)(
#ifdef IDL_PROTOTYPES
		 handle_t IDL_handle,
		 MT_PTY_EXCH_MAP_STRUCT_H *p_mt_pty_exch_map_struct_h,
		 INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		 DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		 );
 int (*wrp_MTUpdPartyDepoMapFn)(
#ifdef IDL_PROTOTYPES
		 handle_t IDL_handle,
		 MT_PTY_DEPO_MAP_STRUCT_H *p_mt_pty_depo_map_struct_h,
		 INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		 DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		 );
 int (*wrp_MTUpdPartyExchClnMapFn)(
#ifdef IDL_PROTOTYPES
		 handle_t IDL_handle,
		 MT_PTY_EXCH_CLN_MAP_STRUCT_H *p_mt_pty_exch_cln_map_struct_h,
		 INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		 DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		 );
 /* HDFCMT_004 Party Master Pradeep */

  /* HDFCMT_GFU Vendor maintenance - Sundar */

int (*wrp_MTUpdVendorMaintFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_GFU_VENDOR_SETUP_STRUCT_H *p_mt_gfu_vendor_setup_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_MTUpdGfuFormSetupFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_GFU_FORMAT_SETUP_STRUCT_H *p_mt_gfu_format_setup_struct_H,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
int (*wrp_MTUpdGfuExcelSetupFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_GFU_EXCEL_SETUP_STRUCT_H *p_mt_gfu_excel_setup_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);
int (*wrp_MTUpdGfuTxtSetupFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_GFU_TXT_SETUP_STRUCT_H *p_mt_gfu_txt_setup_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

int (*wrp_MTUpdGfuCsvSetupFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_GFU_CSV_SETUP_STRUCT_H *p_mt_gfu_csv_setup_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

		
/* HDFCMT_GFU Vendor maintenance - Sundar */

/* Bageshri  - MT Party Fund Details 27/04/06 */

int (*wrp_MTUpdPartyFundDetFn)(
#ifdef IDL_PROTOTYPES
		handle_t IDL_handle,
		MT_PTY_FUND_DET_STRUCT_H *p_mt_pty_fund_det_struct_h,
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
		);

/* Bageshri  - MT Party Fund Details 27/04/06 */

} core_maint_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
