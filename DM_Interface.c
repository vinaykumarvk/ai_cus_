
#include <DM_Interface.h>

/*
int Populate_ASSETHOLDING_VW(ASSETHOLDING_VW_STRUCT_H *p_assetholding_vw_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
}

*/




int Populate_AUDIT_LOG(AUDIT_LOG_STRUCT_H *p_audit_log_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"USR",p_audit_log_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"MOD",p_audit_log_struct_h -> h_mod);
	CO_Rtv_DataString(p_param_data,"FUNCTION",p_audit_log_struct_h -> h_function);
	CO_Rtv_DataString(p_param_data,"AUTH_REQ",p_audit_log_struct_h -> h_auth_req);
	CO_Rtv_DataString(p_param_data,"SUBPROCESS",p_audit_log_struct_h -> h_subprocess);
	CO_Rtv_DataString(p_param_data,"ACTION",p_audit_log_struct_h -> h_action);
	CO_Rtv_DataString(p_param_data,"START_TIME",p_audit_log_struct_h -> h_start_time);
	CO_Rtv_DataString(p_param_data,"END_TIME",p_audit_log_struct_h -> h_end_time);
}






int Populate_BACK_GN_ENTITY_PICKLIST(BACK_GN_ENTITY_PICKLIST_STRUCT_H *p_back_gn_entity_picklist_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_back_gn_entity_picklist_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_back_gn_entity_picklist_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_back_gn_entity_picklist_struct_h -> h_picklist_query);
}






int Populate_BACK_MT_CLIENT(BACK_MT_CLIENT_STRUCT_H *p_back_mt_client_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_back_mt_client_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_CURRENCY",p_back_mt_client_struct_h -> h_cln_currency);
	CO_Rtv_DataString(p_param_data,"CLN_OUR_THEIR_IND",p_back_mt_client_struct_h -> h_cln_our_their_ind);
	CO_Rtv_DataString(p_param_data,"CLN_ISCC_IND",p_back_mt_client_struct_h -> h_cln_iscc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_USE_ISIN_IND",p_back_mt_client_struct_h -> h_cln_use_isin_ind);
	CO_Rtv_DataString(p_param_data,"CLN_TYPE",p_back_mt_client_struct_h -> h_cln_type);
	CO_Rtv_DataString(p_param_data,"CLN_REG_NAME",p_back_mt_client_struct_h -> h_cln_reg_name);
	CO_Rtv_DataString(p_param_data,"CLN_CLAS",p_back_mt_client_struct_h -> h_cln_clas);
	CO_Rtv_DataString(p_param_data,"CLN_BILLABLEIND",p_back_mt_client_struct_h -> h_cln_billableind);
	CO_Rtv_DataString(p_param_data,"CLN_CLASS",p_back_mt_client_struct_h -> h_cln_class);
	CO_Rtv_DataString(p_param_data,"CLN_VTB_CLIENT",p_back_mt_client_struct_h -> h_cln_vtb_client);
	CO_Rtv_DataString(p_param_data,"CLN_REG",p_back_mt_client_struct_h -> h_cln_reg);
	CO_Rtv_DataString(p_param_data,"CLN_MEMO",p_back_mt_client_struct_h -> h_cln_memo);
	CO_Rtv_DataString(p_param_data,"CLN_INTERNAL",p_back_mt_client_struct_h -> h_cln_internal);
	CO_Rtv_DataString(p_param_data,"CLN_POS_DT",p_back_mt_client_struct_h -> h_cln_pos_dt);
	CO_Rtv_DataString(p_param_data,"CLN_BASE_ID",p_back_mt_client_struct_h -> h_cln_base_id);
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_SWF_MON",(int *) &(p_back_mt_client_struct_h -> h_cln_count_swf_mon));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_TLX_MON",(int *) &(p_back_mt_client_struct_h -> h_cln_count_tlx_mon));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_SWF_YR",(int *) &(p_back_mt_client_struct_h -> h_cln_count_swf_yr));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_TLX_YR",(int *) &(p_back_mt_client_struct_h -> h_cln_count_tlx_yr));
	CO_Rtv_DataString(p_param_data,"CLN_MASTER",p_back_mt_client_struct_h -> h_cln_master);
	CO_Rtv_DataString(p_param_data,"CLN_NAME",p_back_mt_client_struct_h -> h_cln_name);
	CO_Rtv_DataString(p_param_data,"CLN_GL_ACCOUNT",p_back_mt_client_struct_h -> h_cln_gl_account);
	CO_Rtv_DataString(p_param_data,"CLN_BRK_ALL",p_back_mt_client_struct_h -> h_cln_brk_all);
	CO_Rtv_DataString(p_param_data,"CLN_SHORTNM",p_back_mt_client_struct_h -> h_cln_shortnm);
	CO_Rtv_DataString(p_param_data,"CLN_ORD_CLT",p_back_mt_client_struct_h -> h_cln_ord_clt);
	CO_Rtv_DataString(p_param_data,"CLN_SPOT_DL_IND",p_back_mt_client_struct_h -> h_cln_spot_dl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_SELL_IND",p_back_mt_client_struct_h -> h_cln_fx_sell_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_BUY_IND",p_back_mt_client_struct_h -> h_cln_fx_buy_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_INC_IND",p_back_mt_client_struct_h -> h_cln_fx_inc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DATEOF_INPUT",p_back_mt_client_struct_h -> h_cln_dateof_input);
	CO_Rtv_DataString(p_param_data,"CLN_BRNCHCODE",p_back_mt_client_struct_h -> h_cln_brnchcode);
	CO_Rtv_DataString(p_param_data,"CLN_CNTRY_CODE",p_back_mt_client_struct_h -> h_cln_cntry_code);
	CO_Rtv_DataString(p_param_data,"CLN_FMT_RPTIND",p_back_mt_client_struct_h -> h_cln_fmt_rptind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_back_mt_client_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_back_mt_client_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_back_mt_client_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_back_mt_client_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_back_mt_client_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"CLN_UNIQ_GCUSTODY_ID",p_back_mt_client_struct_h -> h_cln_uniq_gcustody_id);
	CO_Rtv_DataString(p_param_data,"CLN_CLTPROD_CD",p_back_mt_client_struct_h -> h_cln_cltprod_cd);
	CO_Rtv_DataString(p_param_data,"CLN_DOMICILE",p_back_mt_client_struct_h -> h_cln_domicile);
	CO_Rtv_DataString(p_param_data,"CLN_PARTIAL_IND_C",p_back_mt_client_struct_h -> h_cln_partial_ind_c);
	CO_Rtv_DataString(p_param_data,"CLN_ALLOW_REGIND",p_back_mt_client_struct_h -> h_cln_allow_regind);
	CO_Rtv_DataString(p_param_data,"CLN_REG_SETL_IND",p_back_mt_client_struct_h -> h_cln_reg_setl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_REG_BCL_IND",p_back_mt_client_struct_h -> h_cln_reg_bcl_ind);
	CO_Rtv_DataString(p_param_data,"STATUS",p_back_mt_client_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"CLN_CLH",p_back_mt_client_struct_h -> h_cln_clh);
	CO_Rtv_DataString(p_param_data,"CLN_TAXABLE_IND",p_back_mt_client_struct_h -> h_cln_taxable_ind);
	CO_Rtv_DataString(p_param_data,"CLN_BRK_CD",p_back_mt_client_struct_h -> h_cln_brk_cd);
	CO_Rtv_DataString(p_param_data,"CLN_TAX_ID",p_back_mt_client_struct_h -> h_cln_tax_id);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_1",p_back_mt_client_struct_h -> h_cln_add_1);
	CO_Rtv_DataString(p_param_data,"CLN_EXT_CLH",p_back_mt_client_struct_h -> h_cln_ext_clh);
	CO_Rtv_DataString(p_param_data,"CLN_GRP",p_back_mt_client_struct_h -> h_cln_grp);
	CO_Rtv_DataString(p_param_data,"CLN_SAT_OPER_CD",p_back_mt_client_struct_h -> h_cln_sat_oper_cd);
	CO_Rtv_DataInt(p_param_data,"CLN_TOLERANCE",(int *) &(p_back_mt_client_struct_h -> h_cln_tolerance));
	CO_Rtv_DataString(p_param_data,"CLN_AUTHBUNCH_IND",p_back_mt_client_struct_h -> h_cln_authbunch_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_BUY_CCY",p_back_mt_client_struct_h -> h_cln_fx_buy_ccy);
	CO_Rtv_DataString(p_param_data,"CLN_FX_SELL_CCY",p_back_mt_client_struct_h -> h_cln_fx_sell_ccy);
	CO_Rtv_DataString(p_param_data,"CLN_SINGLE548_SUPPORT_IND",p_back_mt_client_struct_h -> h_cln_single548_support_ind);
	CO_Rtv_DataString(p_param_data,"CLN_STAT_DL_IND",p_back_mt_client_struct_h -> h_cln_stat_dl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DEAL_SETL_IND",p_back_mt_client_struct_h -> h_cln_deal_setl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_RHTS_RET",p_back_mt_client_struct_h -> h_cln_rhts_ret);
	CO_Rtv_DataString(p_param_data,"CLN_VALCREDIT",p_back_mt_client_struct_h -> h_cln_valcredit);
	CO_Rtv_DataString(p_param_data,"CLN_FRACT_IND",p_back_mt_client_struct_h -> h_cln_fract_ind);
	CO_Rtv_DataString(p_param_data,"CLN_AUTO_CANC_IND",p_back_mt_client_struct_h -> h_cln_auto_canc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DESC",p_back_mt_client_struct_h -> h_cln_desc);
	CO_Rtv_DataString(p_param_data,"CLN_GENERATE_IND",p_back_mt_client_struct_h -> h_cln_generate_ind);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_2",p_back_mt_client_struct_h -> h_cln_add_2);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_CITY",p_back_mt_client_struct_h -> h_cln_add_city);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_STATE",p_back_mt_client_struct_h -> h_cln_add_state);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_PIN",p_back_mt_client_struct_h -> h_cln_add_pin);
	CO_Rtv_DataString(p_param_data,"CLN_TEL",p_back_mt_client_struct_h -> h_cln_tel);
	CO_Rtv_DataString(p_param_data,"CLN_FAX",p_back_mt_client_struct_h -> h_cln_fax);
	CO_Rtv_DataString(p_param_data,"CLN_EMAIL",p_back_mt_client_struct_h -> h_cln_email);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT1",p_back_mt_client_struct_h -> h_cln_contact1);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT2",p_back_mt_client_struct_h -> h_cln_contact2);
	CO_Rtv_DataString(p_param_data,"CLN_SEBICTG",p_back_mt_client_struct_h -> h_cln_sebictg);
	CO_Rtv_DataString(p_param_data,"CLN_PAN",p_back_mt_client_struct_h -> h_cln_pan);
	CO_Rtv_DataDbl(p_param_data,"CLN_TDS_RT",&(p_back_mt_client_struct_h -> h_cln_tds_rt));
	CO_Rtv_DataString(p_param_data,"CLN_GLB_CUST",p_back_mt_client_struct_h -> h_cln_glb_cust);
	CO_Rtv_DataString(p_param_data,"CLN_START_DL",p_back_mt_client_struct_h -> h_cln_start_dl);
	CO_Rtv_DataString(p_param_data,"CLN_BCN_REQD",p_back_mt_client_struct_h -> h_cln_bcn_reqd);
	CO_Rtv_DataString(p_param_data,"CLN_DEF_CR_AGENCY",p_back_mt_client_struct_h -> h_cln_def_cr_agency);
	CO_Rtv_DataString(p_param_data,"CLN_CUST_IDENT",p_back_mt_client_struct_h -> h_cln_cust_ident);
	CO_Rtv_DataInt(p_param_data,"CLN_MST_IND",(int *) &(p_back_mt_client_struct_h -> h_cln_mst_ind));
	CO_Rtv_DataString(p_param_data,"CLN_SIGN_MEMO",p_back_mt_client_struct_h -> h_cln_sign_memo);
}






int Populate_CAARCHCHEQUE(CAARCHCHEQUE_STRUCT_H *p_caarchcheque_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caarchcheque_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caarchcheque_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SEQNUM_PAY",(int *) &(p_caarchcheque_struct_h -> h_seqnum_pay));
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caarchcheque_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"PAYMENT_CCY",p_caarchcheque_struct_h -> h_payment_ccy);
	CO_Rtv_DataDbl(p_param_data,"CURR_PYMT",&(p_caarchcheque_struct_h -> h_curr_pymt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caarchcheque_struct_h -> h_quantity_received));
	CO_Rtv_DataDbl(p_param_data,"TAX_RATE",&(p_caarchcheque_struct_h -> h_tax_rate));
	CO_Rtv_DataString(p_param_data,"PAYMENT_INFO",p_caarchcheque_struct_h -> h_payment_info);
	CO_Rtv_DataString(p_param_data,"HF_DATE",p_caarchcheque_struct_h -> h_hf_date);
	CO_Rtv_DataString(p_param_data,"DEAL_IDENTITY_NO",p_caarchcheque_struct_h -> h_deal_identity_no);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_caarchcheque_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_caarchcheque_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"TAX_AMOUNT",&(p_caarchcheque_struct_h -> h_tax_amount));
	CO_Rtv_DataDbl(p_param_data,"OTHER_CHRGS",&(p_caarchcheque_struct_h -> h_other_chrgs));
	CO_Rtv_DataString(p_param_data,"STAT_PYMT",p_caarchcheque_struct_h -> h_stat_pymt);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caarchcheque_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_caarchcheque_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caarchcheque_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caarchcheque_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caarchcheque_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caarchcheque_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caarchcheque_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"AE_PASSIND",p_caarchcheque_struct_h -> h_ae_passind);
	CO_Rtv_DataString(p_param_data,"CLT_SEQNUM",p_caarchcheque_struct_h -> h_clt_seqnum);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_PAID",&(p_caarchcheque_struct_h -> h_quantity_paid));
	CO_Rtv_DataDbl(p_param_data,"TAXABLE_DIVIDEND",&(p_caarchcheque_struct_h -> h_taxable_dividend));
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DATE",p_caarchcheque_struct_h -> h_archival_date);
}






int Populate_CAARCHCLAIM(CAARCHCLAIM_STRUCT_H *p_caarchclaim_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caarchclaim_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caarchclaim_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"ELIG_ENTITL_POS",&(p_caarchclaim_struct_h -> h_elig_entitl_pos));
	CO_Rtv_DataString(p_param_data,"CCY_FOR_ENTITL",p_caarchclaim_struct_h -> h_ccy_for_entitl);
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_BAL",&(p_caarchclaim_struct_h -> h_instr_inc_bal));
	CO_Rtv_DataDbl(p_param_data,"RECEIVED_AMT",&(p_caarchclaim_struct_h -> h_received_amt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caarchclaim_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caarchclaim_struct_h -> h_quantity_received));
	CO_Rtv_DataString(p_param_data,"NREP_DATE_B",p_caarchclaim_struct_h -> h_nrep_date_b);
	CO_Rtv_DataString(p_param_data,"NREP_DATE_C",p_caarchclaim_struct_h -> h_nrep_date_c);
	CO_Rtv_DataString(p_param_data,"DATEFORSEND550",p_caarchclaim_struct_h -> h_dateforsend550);
	CO_Rtv_DataString(p_param_data,"STATUS_ENTITL",p_caarchclaim_struct_h -> h_status_entitl);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caarchclaim_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caarchclaim_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caarchclaim_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caarchclaim_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caarchclaim_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caarchclaim_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"CUSTODYTAX_RATE",&(p_caarchclaim_struct_h -> h_custodytax_rate));
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DATE",p_caarchclaim_struct_h -> h_archival_date);
}






int Populate_CAARCHMESGLNK(CAARCHMESGLNK_STRUCT_H *p_caarchmesglnk_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DATE",p_caarchmesglnk_struct_h -> h_archival_date);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caarchmesglnk_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"PRELIMINARY_FLAG",p_caarchmesglnk_struct_h -> h_preliminary_flag);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caarchmesglnk_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_caarchmesglnk_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_caarchmesglnk_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"TYPEOF_MSG_LNK",p_caarchmesglnk_struct_h -> h_typeof_msg_lnk);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSGREFNO",p_caarchmesglnk_struct_h -> h_swift_msgrefno);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_caarchmesglnk_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_caarchmesglnk_struct_h -> h_information);
}






int Populate_CAARCHNOTE(CAARCHNOTE_STRUCT_H *p_caarchnote_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_caarchnote_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"INFO_1",p_caarchnote_struct_h -> h_info_1);
	CO_Rtv_DataString(p_param_data,"INFO_2",p_caarchnote_struct_h -> h_info_2);
	CO_Rtv_DataString(p_param_data,"INFO_3",p_caarchnote_struct_h -> h_info_3);
	CO_Rtv_DataString(p_param_data,"INFO_4",p_caarchnote_struct_h -> h_info_4);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caarchnote_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caarchnote_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caarchnote_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"TYPEOF_INFO",p_caarchnote_struct_h -> h_typeof_info);
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DATE",p_caarchnote_struct_h -> h_archival_date);
}






int Populate_CAARCHRTSPROC(CAARCHRTSPROC_STRUCT_H *p_caarchrtsproc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_caarchrtsproc_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caarchrtsproc_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_caarchrtsproc_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"DECLARE_DT",p_caarchrtsproc_struct_h -> h_declare_dt);
	CO_Rtv_DataInt(p_param_data,"EVNT_INDNT",(int *) &(p_caarchrtsproc_struct_h -> h_evnt_indnt));
	CO_Rtv_DataString(p_param_data,"INSTR_PARENT",p_caarchrtsproc_struct_h -> h_instr_parent);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caarchrtsproc_struct_h -> h_corp_id);
	CO_Rtv_DataDbl(p_param_data,"TOTAL_QUANTITY",&(p_caarchrtsproc_struct_h -> h_total_quantity));
	CO_Rtv_DataDbl(p_param_data,"TAKEUP_QUANTITY",&(p_caarchrtsproc_struct_h -> h_takeup_quantity));
	CO_Rtv_DataDbl(p_param_data,"LAPSE_QTY",&(p_caarchrtsproc_struct_h -> h_lapse_qty));
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_caarchrtsproc_struct_h -> h_location_cd);
	CO_Rtv_DataInt(p_param_data,"SUB_BASE_QUANTITY",(int *) &(p_caarchrtsproc_struct_h -> h_sub_base_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_NEW_QUANTITY",&(p_caarchrtsproc_struct_h -> h_sub_new_quantity));
	CO_Rtv_DataString(p_param_data,"SUB_CURRENCY",p_caarchrtsproc_struct_h -> h_sub_currency);
	CO_Rtv_DataDbl(p_param_data,"SUB_PR",&(p_caarchrtsproc_struct_h -> h_sub_pr));
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_caarchrtsproc_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"EVENT_STATUS",p_caarchrtsproc_struct_h -> h_event_status);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caarchrtsproc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caarchrtsproc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caarchrtsproc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caarchrtsproc_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caarchrtsproc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caarchrtsproc_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_caarchrtsproc_struct_h -> h_trans_date);
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DATE",p_caarchrtsproc_struct_h -> h_archival_date);
}






int Populate_CAAUTOEVENT(CAAUTOEVENT_STRUCT_H *p_caautoevent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION_CD",p_caautoevent_struct_h -> h_nation_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_TYPE",p_caautoevent_struct_h -> h_instr_type);
	CO_Rtv_DataString(p_param_data,"PROD_CLASS",p_caautoevent_struct_h -> h_prod_class);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_caautoevent_struct_h -> h_ca_event);
	CO_Rtv_DataInt(p_param_data,"PAY_DT_DAYS",(int *) &(p_caautoevent_struct_h -> h_pay_dt_days));
	CO_Rtv_DataInt(p_param_data,"EXDATE_DAYS",(int *) &(p_caautoevent_struct_h -> h_exdate_days));
}






int Populate_CABACKSETTLE(CABACKSETTLE_STRUCT_H *p_cabacksettle_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEALDT",p_cabacksettle_struct_h -> h_dealdt);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_cabacksettle_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_cabacksettle_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_cabacksettle_struct_h -> h_instrument_dt);
	/* Kalyan --- Added for WEB MODULE -- IMPACT TO BE CHECKED DURING DATA MIGRATION */
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_cabacksettle_struct_h -> h_identity_no);
	/* until here */
}






int Populate_CACHEQUE(CACHEQUE_STRUCT_H *p_cacheque_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_cacheque_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_cacheque_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SEQNUM_PAY",(int *) &(p_cacheque_struct_h -> h_seqnum_pay));
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_cacheque_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"PAYMENT_CCY",p_cacheque_struct_h -> h_payment_ccy);
	CO_Rtv_DataDbl(p_param_data,"CURR_PYMT",&(p_cacheque_struct_h -> h_curr_pymt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_cacheque_struct_h -> h_quantity_received));
	CO_Rtv_DataDbl(p_param_data,"TAX_RATE",&(p_cacheque_struct_h -> h_tax_rate));
	CO_Rtv_DataString(p_param_data,"PAYMENT_INFO",p_cacheque_struct_h -> h_payment_info);
	CO_Rtv_DataString(p_param_data,"HF_DATE",p_cacheque_struct_h -> h_hf_date);
	CO_Rtv_DataString(p_param_data,"DEAL_IDENTITY_NO",p_cacheque_struct_h -> h_deal_identity_no);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_cacheque_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_cacheque_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"TAX_AMOUNT",&(p_cacheque_struct_h -> h_tax_amount));
	CO_Rtv_DataDbl(p_param_data,"OTHER_CHRGS",&(p_cacheque_struct_h -> h_other_chrgs));
	CO_Rtv_DataString(p_param_data,"STAT_PYMT",p_cacheque_struct_h -> h_stat_pymt);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_cacheque_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_cacheque_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_cacheque_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_cacheque_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_cacheque_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_cacheque_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_cacheque_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"AE_PASSIND",p_cacheque_struct_h -> h_ae_passind);
	CO_Rtv_DataString(p_param_data,"CLT_SEQNUM",p_cacheque_struct_h -> h_clt_seqnum);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_PAID",&(p_cacheque_struct_h -> h_quantity_paid));
	CO_Rtv_DataDbl(p_param_data,"TAXABLE_DIVIDEND",&(p_cacheque_struct_h -> h_taxable_dividend));
}






int Populate_CACHEQUEMG(CACHEQUEMG_STRUCT_H *p_cachequemg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_cachequemg_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_cachequemg_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SEQNUM_PAY",(int *) &(p_cachequemg_struct_h -> h_seqnum_pay));
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_cachequemg_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"PAYMENT_CCY",p_cachequemg_struct_h -> h_payment_ccy);
	CO_Rtv_DataDbl(p_param_data,"CURR_PYMT",&(p_cachequemg_struct_h -> h_curr_pymt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_cachequemg_struct_h -> h_quantity_received));
	CO_Rtv_DataDbl(p_param_data,"TAX_RATE",&(p_cachequemg_struct_h -> h_tax_rate));
	CO_Rtv_DataString(p_param_data,"PAYMENT_INFO",p_cachequemg_struct_h -> h_payment_info);
	CO_Rtv_DataString(p_param_data,"HF_DATE",p_cachequemg_struct_h -> h_hf_date);
	CO_Rtv_DataString(p_param_data,"DEAL_IDENTITY_NO",p_cachequemg_struct_h -> h_deal_identity_no);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_cachequemg_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_cachequemg_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"TAX_AMOUNT",&(p_cachequemg_struct_h -> h_tax_amount));
	CO_Rtv_DataDbl(p_param_data,"OTHER_CHRGS",&(p_cachequemg_struct_h -> h_other_chrgs));
	CO_Rtv_DataString(p_param_data,"STAT_PYMT",p_cachequemg_struct_h -> h_stat_pymt);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_cachequemg_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_cachequemg_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_cachequemg_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_cachequemg_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_cachequemg_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_cachequemg_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_cachequemg_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"AE_PASSIND",p_cachequemg_struct_h -> h_ae_passind);
	CO_Rtv_DataString(p_param_data,"CLT_SEQNUM",p_cachequemg_struct_h -> h_clt_seqnum);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_PAID",&(p_cachequemg_struct_h -> h_quantity_paid));
	CO_Rtv_DataDbl(p_param_data,"TAXABLE_DIVIDEND",&(p_cachequemg_struct_h -> h_taxable_dividend));
}






int Populate_CACHGEVENT(CACHGEVENT_STRUCT_H *p_cachgevent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_cachgevent_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_cachgevent_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"CURR_CLT",p_cachgevent_struct_h -> h_curr_clt);
}






int Populate_CAENTITLEMENT(CAENTITLEMENT_STRUCT_H *p_caentitlement_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caentitlement_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caentitlement_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"ELIG_ENTITL_POS",&(p_caentitlement_struct_h -> h_elig_entitl_pos));
	CO_Rtv_DataString(p_param_data,"CCY_FOR_ENTITL",p_caentitlement_struct_h -> h_ccy_for_entitl);
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_BAL",&(p_caentitlement_struct_h -> h_instr_inc_bal));
	CO_Rtv_DataDbl(p_param_data,"RECEIVED_AMT",&(p_caentitlement_struct_h -> h_received_amt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caentitlement_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caentitlement_struct_h -> h_quantity_received));
	CO_Rtv_DataString(p_param_data,"NREP_DATE_B",p_caentitlement_struct_h -> h_nrep_date_b);
	CO_Rtv_DataString(p_param_data,"NREP_DATE_C",p_caentitlement_struct_h -> h_nrep_date_c);
	CO_Rtv_DataString(p_param_data,"DATEFORSEND550",p_caentitlement_struct_h -> h_dateforsend550);
	CO_Rtv_DataString(p_param_data,"STATUS_ENTITL",p_caentitlement_struct_h -> h_status_entitl);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caentitlement_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caentitlement_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caentitlement_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caentitlement_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caentitlement_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caentitlement_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"CUSTODYTAX_RATE",&(p_caentitlement_struct_h -> h_custodytax_rate));
}






int Populate_CAENTITLEMENTMG(CAENTITLEMENTMG_STRUCT_H *p_caentitlementmg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caentitlementmg_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caentitlementmg_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"ELIG_ENTITL_POS",&(p_caentitlementmg_struct_h -> h_elig_entitl_pos));
	CO_Rtv_DataString(p_param_data,"CCY_FOR_ENTITL",p_caentitlementmg_struct_h -> h_ccy_for_entitl);
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_BAL",&(p_caentitlementmg_struct_h -> h_instr_inc_bal));
	CO_Rtv_DataDbl(p_param_data,"RECEIVED_AMT",&(p_caentitlementmg_struct_h -> h_received_amt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caentitlementmg_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caentitlementmg_struct_h -> h_quantity_received));
	CO_Rtv_DataString(p_param_data,"NREP_DATE_B",p_caentitlementmg_struct_h -> h_nrep_date_b);
	CO_Rtv_DataString(p_param_data,"NREP_DATE_C",p_caentitlementmg_struct_h -> h_nrep_date_c);
	CO_Rtv_DataString(p_param_data,"DATEFORSEND550",p_caentitlementmg_struct_h -> h_dateforsend550);
	CO_Rtv_DataString(p_param_data,"STATUS_ENTITL",p_caentitlementmg_struct_h -> h_status_entitl);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caentitlementmg_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caentitlementmg_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caentitlementmg_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caentitlementmg_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caentitlementmg_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caentitlementmg_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"CUSTODYTAX_RATE",&(p_caentitlementmg_struct_h -> h_custodytax_rate));
}






int Populate_CAENTITLMENT_VER(CAENTITLMENT_VER_STRUCT_H *p_caentitlment_ver_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_caentitlment_ver_struct_h -> h_nation_code);
	CO_Rtv_DataString(p_param_data,"INSTR_INC_IND",p_caentitlment_ver_struct_h -> h_instr_inc_ind);
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_caentitlment_ver_struct_h -> h_instr_isin);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caentitlment_ver_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_caentitlment_ver_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"EX_DATE",p_caentitlment_ver_struct_h -> h_ex_date);
	CO_Rtv_DataString(p_param_data,"REC_DATE",p_caentitlment_ver_struct_h -> h_rec_date);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caentitlment_ver_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caentitlment_ver_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"GROSS_NET_INCOME",p_caentitlment_ver_struct_h -> h_gross_net_income);
	CO_Rtv_DataString(p_param_data,"CCY_FOR_ENTITL",p_caentitlment_ver_struct_h -> h_ccy_for_entitl);
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_RATE",&(p_caentitlment_ver_struct_h -> h_instr_inc_rate));
	CO_Rtv_DataDbl(p_param_data,"EARNINGS",&(p_caentitlment_ver_struct_h -> h_earnings));
	CO_Rtv_DataDbl(p_param_data,"ELIG_ENTITL_POS",&(p_caentitlment_ver_struct_h -> h_elig_entitl_pos));
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_BAL",&(p_caentitlment_ver_struct_h -> h_instr_inc_bal));
	CO_Rtv_DataDbl(p_param_data,"CUSTODY_TAX_RT",&(p_caentitlment_ver_struct_h -> h_custody_tax_rt));
	CO_Rtv_DataString(p_param_data,"STATUS_ENTITL",p_caentitlment_ver_struct_h -> h_status_entitl);
}






int Populate_CAEVENT(CAEVENT_STRUCT_H *p_caevent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caevent_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_caevent_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_caevent_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"DECLARE_DT",p_caevent_struct_h -> h_declare_dt);
	CO_Rtv_DataInt(p_param_data,"EVNT_INDNT",(int *) &(p_caevent_struct_h -> h_evnt_indnt));
	CO_Rtv_DataString(p_param_data,"PRELIMINARY_FLAG",p_caevent_struct_h -> h_preliminary_flag);
	CO_Rtv_DataString(p_param_data,"CA_CURRENCY",p_caevent_struct_h -> h_ca_currency);
	CO_Rtv_DataString(p_param_data,"EX_DATE",p_caevent_struct_h -> h_ex_date);
	CO_Rtv_DataString(p_param_data,"REC_DATE",p_caevent_struct_h -> h_rec_date);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caevent_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"RESPONSE_DATE",p_caevent_struct_h -> h_response_date);
	CO_Rtv_DataString(p_param_data,"EXPIRY_DATE",p_caevent_struct_h -> h_expiry_date);
	CO_Rtv_DataString(p_param_data,"PART_PYMT_DT",p_caevent_struct_h -> h_part_pymt_dt);
	CO_Rtv_DataString(p_param_data,"PROXY_DATE",p_caevent_struct_h -> h_proxy_date);
	CO_Rtv_DataString(p_param_data,"MEETING_DATE",p_caevent_struct_h -> h_meeting_date);
	CO_Rtv_DataString(p_param_data,"START_DATE",p_caevent_struct_h -> h_start_date);
	CO_Rtv_DataString(p_param_data,"EFFECTIVE_DATE",p_caevent_struct_h -> h_effective_date);
	CO_Rtv_DataString(p_param_data,"PROC_OTH",p_caevent_struct_h -> h_proc_oth);
	CO_Rtv_DataString(p_param_data,"OP_EVT_CLASS",p_caevent_struct_h -> h_op_evt_class);
	CO_Rtv_DataString(p_param_data,"RESP_DT_OPND",p_caevent_struct_h -> h_resp_dt_opnd);
	CO_Rtv_DataString(p_param_data,"EXP_DT_OPEN_IND",p_caevent_struct_h -> h_exp_dt_open_ind);
	CO_Rtv_DataString(p_param_data,"EVT_SEND_MSG_IND",p_caevent_struct_h -> h_evt_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"ENTL_SEND_MSG_IND",p_caevent_struct_h -> h_entl_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"PYMT_SEND_MSG_IND",p_caevent_struct_h -> h_pymt_send_msg_ind);
	CO_Rtv_DataDbl(p_param_data,"EARNINGS",&(p_caevent_struct_h -> h_earnings));
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_RATE",&(p_caevent_struct_h -> h_instr_inc_rate));
	CO_Rtv_DataString(p_param_data,"RES_INSTR_CODE",p_caevent_struct_h -> h_res_instr_code);
	CO_Rtv_DataInt(p_param_data,"NEW_SAFEK_QTY",(int *) &(p_caevent_struct_h -> h_new_safek_qty));
	CO_Rtv_DataInt(p_param_data,"OLD_STK_QTY",(int *) &(p_caevent_struct_h -> h_old_stk_qty));
	CO_Rtv_DataString(p_param_data,"DISP_OF_FRACT",p_caevent_struct_h -> h_disp_of_fract);
	CO_Rtv_DataDbl(p_param_data,"FRACT_PR",&(p_caevent_struct_h -> h_fract_pr));
	CO_Rtv_DataInt(p_param_data,"SUB_BASE_QUANTITY",(int *) &(p_caevent_struct_h -> h_sub_base_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_NEW_QUANTITY",&(p_caevent_struct_h -> h_sub_new_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_PR",&(p_caevent_struct_h -> h_sub_pr));
	CO_Rtv_DataString(p_param_data,"RHTS_CLASS",p_caevent_struct_h -> h_rhts_class);
	CO_Rtv_DataDbl(p_param_data,"NEW_SAFEK_RT",&(p_caevent_struct_h -> h_new_safek_rt));
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS",p_caevent_struct_h -> h_contact_details);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT_BAL",&(p_caevent_struct_h -> h_amount_bal));
	CO_Rtv_DataDbl(p_param_data,"RECEIVED_AMT",&(p_caevent_struct_h -> h_received_amt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caevent_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caevent_struct_h -> h_quantity_received));
	CO_Rtv_DataInt(p_param_data,"EVT_MSG_COUNT",(int *) &(p_caevent_struct_h -> h_evt_msg_count));
	CO_Rtv_DataInt(p_param_data,"EVT_CLT_CNT",(int *) &(p_caevent_struct_h -> h_evt_clt_cnt));
	CO_Rtv_DataInt(p_param_data,"ENTL_MSG_CNT",(int *) &(p_caevent_struct_h -> h_entl_msg_cnt));
	CO_Rtv_DataInt(p_param_data,"ENTL_CLT_CNT",(int *) &(p_caevent_struct_h -> h_entl_clt_cnt));
	CO_Rtv_DataInt(p_param_data,"COUNT_ACS_PEND",(int *) &(p_caevent_struct_h -> h_count_acs_pend));
	CO_Rtv_DataString(p_param_data,"NREP_DATE_A",p_caevent_struct_h -> h_nrep_date_a);
	CO_Rtv_DataString(p_param_data,"MSG_FOLLOWDAYS1",p_caevent_struct_h -> h_msg_followdays1);
	CO_Rtv_DataString(p_param_data,"MSG_FOLLOWDAYS2",p_caevent_struct_h -> h_msg_followdays2);
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_caevent_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"ENTITL_INFONO",p_caevent_struct_h -> h_entitl_infono);
	CO_Rtv_DataString(p_param_data,"EVENT_STATUS",p_caevent_struct_h -> h_event_status);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caevent_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caevent_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caevent_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caevent_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caevent_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caevent_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_DATE",p_caevent_struct_h -> h_deal_frm_date);
	CO_Rtv_DataString(p_param_data,"DEAL_TO_DATE",p_caevent_struct_h -> h_deal_to_date);
	CO_Rtv_DataString(p_param_data,"SUBSCR_DATE",p_caevent_struct_h -> h_subscr_date);
	CO_Rtv_DataString(p_param_data,"POST_DATE",p_caevent_struct_h -> h_post_date);
	CO_Rtv_DataString(p_param_data,"OVER_SUBSCRP",p_caevent_struct_h -> h_over_subscrp);
	CO_Rtv_DataString(p_param_data,"DIVIDEND_TYPE",p_caevent_struct_h -> h_dividend_type);
	CO_Rtv_DataDbl(p_param_data,"REDEM_RT",&(p_caevent_struct_h -> h_redem_rt));
	CO_Rtv_DataString(p_param_data,"NSER_E_INFO",p_caevent_struct_h -> h_nser_e_info);
	CO_Rtv_DataString(p_param_data,"NSER_B_INFO",p_caevent_struct_h -> h_nser_b_info);
	CO_Rtv_DataString(p_param_data,"COMP_INFO_A",p_caevent_struct_h -> h_comp_info_a);
	CO_Rtv_DataString(p_param_data,"INCO_INFO_A",p_caevent_struct_h -> h_inco_info_a);
	CO_Rtv_DataString(p_param_data,"RESPONSEDT_BUY",p_caevent_struct_h -> h_responsedt_buy);
	CO_Rtv_DataString(p_param_data,"SELL_RESP_DATE",p_caevent_struct_h -> h_sell_resp_date);
	CO_Rtv_DataString(p_param_data,"WWWADDR",p_caevent_struct_h -> h_wwwaddr);
	CO_Rtv_DataString(p_param_data,"TXNR_INFO_A",p_caevent_struct_h -> h_txnr_info_a);
	CO_Rtv_DataString(p_param_data,"REQD_CERTIFY",p_caevent_struct_h -> h_reqd_certify);
}






int Populate_CAEVENTMG(CAEVENTMG_STRUCT_H *p_caeventmg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caeventmg_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_caeventmg_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_caeventmg_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"DECLARE_DT",p_caeventmg_struct_h -> h_declare_dt);
	CO_Rtv_DataInt(p_param_data,"EVNT_INDNT",(int *) &(p_caeventmg_struct_h -> h_evnt_indnt));
	CO_Rtv_DataString(p_param_data,"PRELIMINARY_FLAG",p_caeventmg_struct_h -> h_preliminary_flag);
	CO_Rtv_DataString(p_param_data,"CA_CURRENCY",p_caeventmg_struct_h -> h_ca_currency);
	CO_Rtv_DataString(p_param_data,"EX_DATE",p_caeventmg_struct_h -> h_ex_date);
	CO_Rtv_DataString(p_param_data,"REC_DATE",p_caeventmg_struct_h -> h_rec_date);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caeventmg_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"RESPONSE_DATE",p_caeventmg_struct_h -> h_response_date);
	CO_Rtv_DataString(p_param_data,"EXPIRY_DATE",p_caeventmg_struct_h -> h_expiry_date);
	CO_Rtv_DataString(p_param_data,"PART_PYMT_DT",p_caeventmg_struct_h -> h_part_pymt_dt);
	CO_Rtv_DataString(p_param_data,"PROXY_DATE",p_caeventmg_struct_h -> h_proxy_date);
	CO_Rtv_DataString(p_param_data,"MEETING_DATE",p_caeventmg_struct_h -> h_meeting_date);
	CO_Rtv_DataString(p_param_data,"START_DATE",p_caeventmg_struct_h -> h_start_date);
	CO_Rtv_DataString(p_param_data,"EFFECTIVE_DATE",p_caeventmg_struct_h -> h_effective_date);
	CO_Rtv_DataString(p_param_data,"PROC_OTH",p_caeventmg_struct_h -> h_proc_oth);
	CO_Rtv_DataString(p_param_data,"OP_EVT_CLASS",p_caeventmg_struct_h -> h_op_evt_class);
	CO_Rtv_DataString(p_param_data,"RESP_DT_OPND",p_caeventmg_struct_h -> h_resp_dt_opnd);
	CO_Rtv_DataString(p_param_data,"EXP_DT_OPEN_IND",p_caeventmg_struct_h -> h_exp_dt_open_ind);
	CO_Rtv_DataString(p_param_data,"EVT_SEND_MSG_IND",p_caeventmg_struct_h -> h_evt_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"ENTL_SEND_MSG_IND",p_caeventmg_struct_h -> h_entl_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"PYMT_SEND_MSG_IND",p_caeventmg_struct_h -> h_pymt_send_msg_ind);
	CO_Rtv_DataDbl(p_param_data,"EARNINGS",&(p_caeventmg_struct_h -> h_earnings));
	CO_Rtv_DataDbl(p_param_data,"INSTR_INC_RATE",&(p_caeventmg_struct_h -> h_instr_inc_rate));
	CO_Rtv_DataString(p_param_data,"RES_INSTR_CODE",p_caeventmg_struct_h -> h_res_instr_code);
	CO_Rtv_DataInt(p_param_data,"NEW_SAFEK_QTY",(int *) &(p_caeventmg_struct_h -> h_new_safek_qty));
	CO_Rtv_DataInt(p_param_data,"OLD_STK_QTY",(int *) &(p_caeventmg_struct_h -> h_old_stk_qty));
	CO_Rtv_DataString(p_param_data,"DISP_OF_FRACT",p_caeventmg_struct_h -> h_disp_of_fract);
	CO_Rtv_DataDbl(p_param_data,"FRACT_PR",&(p_caeventmg_struct_h -> h_fract_pr));
	CO_Rtv_DataInt(p_param_data,"SUB_BASE_QUANTITY",(int *) &(p_caeventmg_struct_h -> h_sub_base_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_NEW_QUANTITY",&(p_caeventmg_struct_h -> h_sub_new_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_PR",&(p_caeventmg_struct_h -> h_sub_pr));
	CO_Rtv_DataString(p_param_data,"RHTS_CLASS",p_caeventmg_struct_h -> h_rhts_class);
	CO_Rtv_DataDbl(p_param_data,"NEW_SAFEK_RT",&(p_caeventmg_struct_h -> h_new_safek_rt));
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS",p_caeventmg_struct_h -> h_contact_details);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT_BAL",&(p_caeventmg_struct_h -> h_amount_bal));
	CO_Rtv_DataDbl(p_param_data,"RECEIVED_AMT",&(p_caeventmg_struct_h -> h_received_amt));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caeventmg_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_RECEIVED",&(p_caeventmg_struct_h -> h_quantity_received));
	CO_Rtv_DataInt(p_param_data,"EVT_MSG_COUNT",(int *) &(p_caeventmg_struct_h -> h_evt_msg_count));
	CO_Rtv_DataInt(p_param_data,"EVT_CLT_CNT",(int *) &(p_caeventmg_struct_h -> h_evt_clt_cnt));
	CO_Rtv_DataInt(p_param_data,"ENTL_MSG_CNT",(int *) &(p_caeventmg_struct_h -> h_entl_msg_cnt));
	CO_Rtv_DataInt(p_param_data,"ENTL_CLT_CNT",(int *) &(p_caeventmg_struct_h -> h_entl_clt_cnt));
	CO_Rtv_DataInt(p_param_data,"COUNT_ACS_PEND",(int *) &(p_caeventmg_struct_h -> h_count_acs_pend));
	CO_Rtv_DataString(p_param_data,"NREP_DATE_A",p_caeventmg_struct_h -> h_nrep_date_a);
	CO_Rtv_DataString(p_param_data,"MSG_FOLLOWDAYS1",p_caeventmg_struct_h -> h_msg_followdays1);
	CO_Rtv_DataString(p_param_data,"MSG_FOLLOWDAYS2",p_caeventmg_struct_h -> h_msg_followdays2);
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_caeventmg_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"ENTITL_INFONO",p_caeventmg_struct_h -> h_entitl_infono);
	CO_Rtv_DataString(p_param_data,"EVENT_STATUS",p_caeventmg_struct_h -> h_event_status);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_caeventmg_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_caeventmg_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caeventmg_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caeventmg_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caeventmg_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caeventmg_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_DATE",p_caeventmg_struct_h -> h_deal_frm_date);
	CO_Rtv_DataString(p_param_data,"DEAL_TO_DATE",p_caeventmg_struct_h -> h_deal_to_date);
	CO_Rtv_DataString(p_param_data,"SUBSCR_DATE",p_caeventmg_struct_h -> h_subscr_date);
	CO_Rtv_DataString(p_param_data,"POST_DATE",p_caeventmg_struct_h -> h_post_date);
	CO_Rtv_DataString(p_param_data,"OVER_SUBSCRP",p_caeventmg_struct_h -> h_over_subscrp);
	CO_Rtv_DataString(p_param_data,"DIVIDEND_TYPE",p_caeventmg_struct_h -> h_dividend_type);
	CO_Rtv_DataDbl(p_param_data,"REDEM_RT",&(p_caeventmg_struct_h -> h_redem_rt));
	CO_Rtv_DataString(p_param_data,"NSER_E_INFO",p_caeventmg_struct_h -> h_nser_e_info);
	CO_Rtv_DataString(p_param_data,"NSER_B_INFO",p_caeventmg_struct_h -> h_nser_b_info);
	CO_Rtv_DataString(p_param_data,"COMP_INFO_A",p_caeventmg_struct_h -> h_comp_info_a);
	CO_Rtv_DataString(p_param_data,"INCO_INFO_A",p_caeventmg_struct_h -> h_inco_info_a);
	CO_Rtv_DataString(p_param_data,"RESPONSEDT_BUY",p_caeventmg_struct_h -> h_responsedt_buy);
	CO_Rtv_DataString(p_param_data,"SELL_RESP_DATE",p_caeventmg_struct_h -> h_sell_resp_date);
	CO_Rtv_DataString(p_param_data,"WWWADDR",p_caeventmg_struct_h -> h_wwwaddr);
	CO_Rtv_DataString(p_param_data,"TXNR_INFO_A",p_caeventmg_struct_h -> h_txnr_info_a);
	CO_Rtv_DataString(p_param_data,"REQD_CERTIFY",p_caeventmg_struct_h -> h_reqd_certify);
}






int Populate_CAGLPYMT(CAGLPYMT_STRUCT_H *p_caglpymt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_caglpymt_struct_h -> h_corp_id);
	CO_Rtv_DataDbl(p_param_data,"ELIG_ENTITL_POS",&(p_caglpymt_struct_h -> h_elig_entitl_pos));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_BAL",&(p_caglpymt_struct_h -> h_quantity_bal));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT_BAL",&(p_caglpymt_struct_h -> h_amount_bal));
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_caglpymt_struct_h -> h_dateof_payment);
	CO_Rtv_DataDbl(p_param_data,"CURR_QTY_BAL",&(p_caglpymt_struct_h -> h_curr_qty_bal));
	CO_Rtv_DataDbl(p_param_data,"CUR_AMT_BAL",&(p_caglpymt_struct_h -> h_cur_amt_bal));
	CO_Rtv_DataString(p_param_data,"MAKER",p_caglpymt_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_caglpymt_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_caglpymt_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_caglpymt_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STAT_PYMT",p_caglpymt_struct_h -> h_stat_pymt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_caglpymt_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_caglpymt_struct_h -> h_date_of_input);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY_PAID",&(p_caglpymt_struct_h -> h_quantity_paid));
	CO_Rtv_DataDbl(p_param_data,"TAXABLE_DIVIDEND",&(p_caglpymt_struct_h -> h_taxable_dividend));
}






int Populate_CALOGAUTOEVENT(CALOGAUTOEVENT_STRUCT_H *p_calogautoevent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_calogautoevent_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_calogautoevent_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_calogautoevent_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_calogautoevent_struct_h -> h_corp_id);
}






int Populate_CAMESGLINK(CAMESGLINK_STRUCT_H *p_camesglink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_camesglink_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"PRELIMINARY_FLAG",p_camesglink_struct_h -> h_preliminary_flag);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_camesglink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_camesglink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_camesglink_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"TYPEOF_MSG_LNK",p_camesglink_struct_h -> h_typeof_msg_lnk);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSGREFNO",p_camesglink_struct_h -> h_swift_msgrefno);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_camesglink_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_camesglink_struct_h -> h_information);
}






int Populate_CANOTE(CANOTE_STRUCT_H *p_canote_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_canote_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"INFO_1",p_canote_struct_h -> h_info_1);
	CO_Rtv_DataString(p_param_data,"INFO_2",p_canote_struct_h -> h_info_2);
	CO_Rtv_DataString(p_param_data,"INFO_3",p_canote_struct_h -> h_info_3);
	CO_Rtv_DataString(p_param_data,"INFO_4",p_canote_struct_h -> h_info_4);
	CO_Rtv_DataString(p_param_data,"MAKER",p_canote_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_canote_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_canote_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"TYPEOF_INFO",p_canote_struct_h -> h_typeof_info);
}






int Populate_CANOTIFY(CANOTIFY_STRUCT_H *p_canotify_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEALDT",p_canotify_struct_h -> h_dealdt);
	CO_Rtv_DataString(p_param_data,"TASK_CD",p_canotify_struct_h -> h_task_cd);
	CO_Rtv_DataString(p_param_data,"NOTIFY_CD",p_canotify_struct_h -> h_notify_cd);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_canotify_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_canotify_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_canotify_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"SEQNUM_PAY",(int *) &(p_canotify_struct_h -> h_seqnum_pay));
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_canotify_struct_h -> h_information);
}






int Populate_CAREPLY(CAREPLY_STRUCT_H *p_careply_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_careply_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_careply_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"RESPONSE_DT",p_careply_struct_h -> h_response_dt);
	CO_Rtv_DataString(p_param_data,"RES_MSG_DATE",p_careply_struct_h -> h_res_msg_date);
	CO_Rtv_DataString(p_param_data,"PYMT_MSG_DATE",p_careply_struct_h -> h_pymt_msg_date);
	CO_Rtv_DataString(p_param_data,"INSTR_MSGREFNO",p_careply_struct_h -> h_instr_msgrefno);
	CO_Rtv_DataDbl(p_param_data,"INSTR_HOLD",&(p_careply_struct_h -> h_instr_hold));
	CO_Rtv_DataString(p_param_data,"SEND_RESP_IND",p_careply_struct_h -> h_send_resp_ind);
	CO_Rtv_DataString(p_param_data,"STAT_CD",p_careply_struct_h -> h_stat_cd);
	CO_Rtv_DataString(p_param_data,"MAKER",p_careply_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_careply_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_careply_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_careply_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_careply_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_careply_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_careply_struct_h -> h_date_of_input);
}






int Populate_CAREPLYSPLIT(CAREPLYSPLIT_STRUCT_H *p_careplysplit_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SRL_NUM",(int *) &(p_careplysplit_struct_h -> h_srl_num));
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_careplysplit_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_careplysplit_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"HOLDING_AMT",&(p_careplysplit_struct_h -> h_holding_amt));
	CO_Rtv_DataString(p_param_data,"INSTR_MSGREFNO",p_careplysplit_struct_h -> h_instr_msgrefno);
	CO_Rtv_DataString(p_param_data,"SEND_RESP_IND",p_careplysplit_struct_h -> h_send_resp_ind);
	CO_Rtv_DataString(p_param_data,"STAT_CD",p_careplysplit_struct_h -> h_stat_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_careplysplit_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_careplysplit_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CA_OPTCD",p_careplysplit_struct_h -> h_ca_optcd);
}






int Populate_CARTSPROC(CARTSPROC_STRUCT_H *p_cartsproc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_cartsproc_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_cartsproc_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_cartsproc_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"DECLARE_DT",p_cartsproc_struct_h -> h_declare_dt);
	CO_Rtv_DataInt(p_param_data,"EVNT_INDNT",(int *) &(p_cartsproc_struct_h -> h_evnt_indnt));
	CO_Rtv_DataString(p_param_data,"INSTR_PARENT",p_cartsproc_struct_h -> h_instr_parent);
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_cartsproc_struct_h -> h_corp_id);
	CO_Rtv_DataDbl(p_param_data,"TOTAL_QUANTITY",&(p_cartsproc_struct_h -> h_total_quantity));
	CO_Rtv_DataDbl(p_param_data,"TAKEUP_QUANTITY",&(p_cartsproc_struct_h -> h_takeup_quantity));
	CO_Rtv_DataDbl(p_param_data,"LAPSE_QTY",&(p_cartsproc_struct_h -> h_lapse_qty));
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_cartsproc_struct_h -> h_location_cd);
	CO_Rtv_DataInt(p_param_data,"SUB_BASE_QUANTITY",(int *) &(p_cartsproc_struct_h -> h_sub_base_quantity));
	CO_Rtv_DataDbl(p_param_data,"SUB_NEW_QUANTITY",&(p_cartsproc_struct_h -> h_sub_new_quantity));
	CO_Rtv_DataString(p_param_data,"SUB_CURRENCY",p_cartsproc_struct_h -> h_sub_currency);
	CO_Rtv_DataDbl(p_param_data,"SUB_PR",&(p_cartsproc_struct_h -> h_sub_pr));
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_cartsproc_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"EVENT_STATUS",p_cartsproc_struct_h -> h_event_status);
	CO_Rtv_DataString(p_param_data,"MAKER",p_cartsproc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_cartsproc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_cartsproc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_cartsproc_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_cartsproc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_cartsproc_struct_h -> h_dateof_payment);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_cartsproc_struct_h -> h_trans_date);
}






int Populate_CASECEVENT(CASECEVENT_STRUCT_H *p_casecevent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_TYPE",p_casecevent_struct_h -> h_instr_type);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_casecevent_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"PAYOUT_FLAG",p_casecevent_struct_h -> h_payout_flag);
	CO_Rtv_DataString(p_param_data,"ENTITL_BASE",p_casecevent_struct_h -> h_entitl_base);
	CO_Rtv_DataString(p_param_data,"RATIO_PERC_IND",p_casecevent_struct_h -> h_ratio_perc_ind);
	CO_Rtv_DataString(p_param_data,"AMOUNT_RATIO_FLG",p_casecevent_struct_h -> h_amount_ratio_flg);
	CO_Rtv_DataString(p_param_data,"AUTO_DLCRT_IND",p_casecevent_struct_h -> h_auto_dlcrt_ind);
	CO_Rtv_DataString(p_param_data,"SNDMSG_TO_ALLMAST",p_casecevent_struct_h -> h_sndmsg_to_allmast);
	CO_Rtv_DataString(p_param_data,"GEN_ENRAREP_IND",p_casecevent_struct_h -> h_gen_enrarep_ind);
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE_A",(int *) &(p_casecevent_struct_h -> h_enra_lapse_a));
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE_B",(int *) &(p_casecevent_struct_h -> h_enra_lapse_b));
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE_C",(int *) &(p_casecevent_struct_h -> h_enra_lapse_c));
}






int Populate_CASTATUS(CASTATUS_STRUCT_H *p_castatus_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_castatus_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_castatus_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"STAT_CD",p_castatus_struct_h -> h_stat_cd);
	CO_Rtv_DataString(p_param_data,"DETAIL",p_castatus_struct_h -> h_detail);
	CO_Rtv_DataString(p_param_data,"MAKER",p_castatus_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_castatus_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_castatus_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INSTR_MSGREFNO",p_castatus_struct_h -> h_instr_msgrefno);
	CO_Rtv_DataString(p_param_data,"CA_OPTCD",p_castatus_struct_h -> h_ca_optcd);
	CO_Rtv_DataDbl(p_param_data,"INSTR_HOLD",&(p_castatus_struct_h -> h_instr_hold));
}






int Populate_CASYSTEMPARAMS(CASYSTEMPARAMS_STRUCT_H *p_casystemparams_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITL_BASE",p_casystemparams_struct_h -> h_entitl_base);
	CO_Rtv_DataString(p_param_data,"AMOUNT_RATIO_FLG",p_casystemparams_struct_h -> h_amount_ratio_flg);
	CO_Rtv_DataString(p_param_data,"RATIO_PERC_IND_BO",p_casystemparams_struct_h -> h_ratio_perc_ind_bo);
	CO_Rtv_DataString(p_param_data,"RATIO_PERC_IND_SD",p_casystemparams_struct_h -> h_ratio_perc_ind_sd);
	CO_Rtv_DataString(p_param_data,"RATIO_PERC_IND_RHTS",p_casystemparams_struct_h -> h_ratio_perc_ind_rhts);
	CO_Rtv_DataString(p_param_data,"CREATE_TRD_BO_IND",p_casystemparams_struct_h -> h_create_trd_bo_ind);
	CO_Rtv_DataString(p_param_data,"CREATE_TRD_SD_IND",p_casystemparams_struct_h -> h_create_trd_sd_ind);
	CO_Rtv_DataString(p_param_data,"CREATE_TRD_RTS_IND",p_casystemparams_struct_h -> h_create_trd_rts_ind);
	CO_Rtv_DataString(p_param_data,"CREATE_TRD_RD_IND",p_casystemparams_struct_h -> h_create_trd_rd_ind);
	CO_Rtv_DataString(p_param_data,"CREATE_TRD_SPLIT_IND",p_casystemparams_struct_h -> h_create_trd_split_ind);
	CO_Rtv_DataString(p_param_data,"SNDMSG_TO_ALLMAST",p_casystemparams_struct_h -> h_sndmsg_to_allmast);
	CO_Rtv_DataString(p_param_data,"CREATE_EVNT_BOND_INT",p_casystemparams_struct_h -> h_create_evnt_bond_int);
	CO_Rtv_DataInt(p_param_data,"BOND_INT_NO_DAYS_PAY_DT",(int *) &(p_casystemparams_struct_h -> h_bond_int_no_days_pay_dt));
	CO_Rtv_DataString(p_param_data,"CREATE_EVNT_MMI_INT",p_casystemparams_struct_h -> h_create_evnt_mmi_int);
	CO_Rtv_DataInt(p_param_data,"MMI_INT_NO_DAYS_PAY_DT",(int *) &(p_casystemparams_struct_h -> h_mmi_int_no_days_pay_dt));
	CO_Rtv_DataString(p_param_data,"CREATE_EVNT_BOND_RD",p_casystemparams_struct_h -> h_create_evnt_bond_rd);
	CO_Rtv_DataInt(p_param_data,"BOND_RD_NO_DAYS_MAT_DT",(int *) &(p_casystemparams_struct_h -> h_bond_rd_no_days_mat_dt));
	CO_Rtv_DataString(p_param_data,"CREATE_EVNT_MMI_RD",p_casystemparams_struct_h -> h_create_evnt_mmi_rd);
	CO_Rtv_DataInt(p_param_data,"MMI_RD_NO_DAYS_MAT_DT",(int *) &(p_casystemparams_struct_h -> h_mmi_rd_no_days_mat_dt));
	CO_Rtv_DataInt(p_param_data,"BOND_EXDT_NO_DAYS",(int *) &(p_casystemparams_struct_h -> h_bond_exdt_no_days));
	CO_Rtv_DataInt(p_param_data,"MMI_EXDT_NO_DAYS",(int *) &(p_casystemparams_struct_h -> h_mmi_exdt_no_days));
	CO_Rtv_DataString(p_param_data,"GEN_ENRAREP_IND",p_casystemparams_struct_h -> h_gen_enrarep_ind);
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE1",(int *) &(p_casystemparams_struct_h -> h_enra_lapse1));
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE2",(int *) &(p_casystemparams_struct_h -> h_enra_lapse2));
	CO_Rtv_DataInt(p_param_data,"ENRA_LAPSE3",(int *) &(p_casystemparams_struct_h -> h_enra_lapse3));
}




/*

int Populate_CA_ENTITLEMENTREP(CA_ENTITLEMENTREP_STRUCT_H *p_ca_entitlementrep_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}



*/


int Populate_CA_EVENTMESGSEND(CA_EVENTMESGSEND_STRUCT_H *p_ca_eventmesgsend_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CORP_ID",p_ca_eventmesgsend_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ca_eventmesgsend_struct_h -> h_client);
}





/*
int Populate_CA_EXDTHLD1_VEW(CA_EXDTHLD1_VEW_STRUCT_H *p_ca_exdthld1_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
}

*/



/*
int Populate_CA_EXDTHLD2_VEW(CA_EXDTHLD2_VEW_STRUCT_H *p_ca_exdthld2_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
}
*/




/*
int Populate_CIMS_ACC_VEW(CIMS_ACC_VEW_STRUCT_H *p_cims_acc_vew_struct_h,char * p_param_data)
{
	
	
	
	
}


*/



int Populate_COMMON_BASE_QUERY_MAPPING(COMMON_BASE_QUERY_MAPPING_STRUCT_H *p_common_base_query_mapping_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_base_query_mapping_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY",p_common_base_query_mapping_struct_h -> h_base_query);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY1",p_common_base_query_mapping_struct_h -> h_base_query1);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY2",p_common_base_query_mapping_struct_h -> h_base_query2);
	CO_Rtv_DataString(p_param_data,"HEADER_FIELDS",p_common_base_query_mapping_struct_h -> h_header_fields);
	CO_Rtv_DataString(p_param_data,"PRIMARY_KEY_COLUMNS",p_common_base_query_mapping_struct_h -> h_primary_key_columns);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY",p_common_base_query_mapping_struct_h -> h_hashmap_query);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY1",p_common_base_query_mapping_struct_h -> h_hashmap_query1);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY2",p_common_base_query_mapping_struct_h -> h_hashmap_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_base_query_mapping_struct_h -> h_datatypes);
	CO_Rtv_DataString(p_param_data,"LINK",p_common_base_query_mapping_struct_h -> h_link);
}






int Populate_COMMON_BASE_QUERY_MAPPING_BACK(COMMON_BASE_QUERY_MAPPING_BACK_STRUCT_H *p_common_base_query_mapping_back_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_base_query_mapping_back_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY",p_common_base_query_mapping_back_struct_h -> h_base_query);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY1",p_common_base_query_mapping_back_struct_h -> h_base_query1);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY2",p_common_base_query_mapping_back_struct_h -> h_base_query2);
	CO_Rtv_DataString(p_param_data,"HEADER_FIELDS",p_common_base_query_mapping_back_struct_h -> h_header_fields);
	CO_Rtv_DataString(p_param_data,"PRIMARY_KEY_COLUMNS",p_common_base_query_mapping_back_struct_h -> h_primary_key_columns);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY",p_common_base_query_mapping_back_struct_h -> h_hashmap_query);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY1",p_common_base_query_mapping_back_struct_h -> h_hashmap_query1);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY2",p_common_base_query_mapping_back_struct_h -> h_hashmap_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_base_query_mapping_back_struct_h -> h_datatypes);
	CO_Rtv_DataString(p_param_data,"LINK",p_common_base_query_mapping_back_struct_h -> h_link);
}






int Populate_COMMON_BASE_QUERY_MAPPING_BAK(COMMON_BASE_QUERY_MAPPING_BAK_STRUCT_H *p_common_base_query_mapping_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_base_query_mapping_bak_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY",p_common_base_query_mapping_bak_struct_h -> h_base_query);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY1",p_common_base_query_mapping_bak_struct_h -> h_base_query1);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY2",p_common_base_query_mapping_bak_struct_h -> h_base_query2);
	CO_Rtv_DataString(p_param_data,"HEADER_FIELDS",p_common_base_query_mapping_bak_struct_h -> h_header_fields);
	CO_Rtv_DataString(p_param_data,"PRIMARY_KEY_COLUMNS",p_common_base_query_mapping_bak_struct_h -> h_primary_key_columns);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY",p_common_base_query_mapping_bak_struct_h -> h_hashmap_query);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY1",p_common_base_query_mapping_bak_struct_h -> h_hashmap_query1);
	CO_Rtv_DataString(p_param_data,"HASHMAP_QUERY2",p_common_base_query_mapping_bak_struct_h -> h_hashmap_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_base_query_mapping_bak_struct_h -> h_datatypes);
	CO_Rtv_DataString(p_param_data,"LINK",p_common_base_query_mapping_bak_struct_h -> h_link);
}






int Populate_COMMON_ENTITY_PROC(COMMON_ENTITY_PROC_STRUCT_H *p_common_entity_proc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_entity_proc_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PROCEDURE_NAME",p_common_entity_proc_struct_h -> h_procedure_name);
	CO_Rtv_DataString(p_param_data,"WRAPPER_NAME",p_common_entity_proc_struct_h -> h_wrapper_name);
	CO_Rtv_DataString(p_param_data,"ENTITY_MODE",p_common_entity_proc_struct_h -> h_entity_mode);
}






int Populate_COMMON_ENTITY_PROC_230106(COMMON_ENTITY_PROC_230106_STRUCT_H *p_common_entity_proc_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_entity_proc_230106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PROCEDURE_NAME",p_common_entity_proc_230106_struct_h -> h_procedure_name);
	CO_Rtv_DataString(p_param_data,"WRAPPER_NAME",p_common_entity_proc_230106_struct_h -> h_wrapper_name);
	CO_Rtv_DataString(p_param_data,"ENTITY_MODE",p_common_entity_proc_230106_struct_h -> h_entity_mode);
}






int Populate_COMMON_ENTITY_PROC_BAK(COMMON_ENTITY_PROC_BAK_STRUCT_H *p_common_entity_proc_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_entity_proc_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PROCEDURE_NAME",p_common_entity_proc_bak_struct_h -> h_procedure_name);
	CO_Rtv_DataString(p_param_data,"WRAPPER_NAME",p_common_entity_proc_bak_struct_h -> h_wrapper_name);
	CO_Rtv_DataString(p_param_data,"ENTITY_MODE",p_common_entity_proc_bak_struct_h -> h_entity_mode);
}






int Populate_COMMON_GRID_MAPPING(COMMON_GRID_MAPPING_STRUCT_H *p_common_grid_mapping_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_grid_mapping_struct_h -> h_grid_indicator);
	CO_Rtv_DataString(p_param_data,"GRID_CLASS_NAME",p_common_grid_mapping_struct_h -> h_grid_class_name);
	CO_Rtv_DataString(p_param_data,"GRID_NAME",p_common_grid_mapping_struct_h -> h_grid_name);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY",p_common_grid_mapping_struct_h -> h_grid_query);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY1",p_common_grid_mapping_struct_h -> h_grid_query1);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY2",p_common_grid_mapping_struct_h -> h_grid_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_grid_mapping_struct_h -> h_datatypes);
}






int Populate_COMMON_GRID_MAPPING_230106(COMMON_GRID_MAPPING_230106_STRUCT_H *p_common_grid_mapping_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_grid_mapping_230106_struct_h -> h_grid_indicator);
	CO_Rtv_DataString(p_param_data,"GRID_CLASS_NAME",p_common_grid_mapping_230106_struct_h -> h_grid_class_name);
	CO_Rtv_DataString(p_param_data,"GRID_NAME",p_common_grid_mapping_230106_struct_h -> h_grid_name);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY",p_common_grid_mapping_230106_struct_h -> h_grid_query);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY1",p_common_grid_mapping_230106_struct_h -> h_grid_query1);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY2",p_common_grid_mapping_230106_struct_h -> h_grid_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_grid_mapping_230106_struct_h -> h_datatypes);
}






int Populate_COMMON_GRID_MAPPING_BAK(COMMON_GRID_MAPPING_BAK_STRUCT_H *p_common_grid_mapping_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_grid_mapping_bak_struct_h -> h_grid_indicator);
	CO_Rtv_DataString(p_param_data,"GRID_CLASS_NAME",p_common_grid_mapping_bak_struct_h -> h_grid_class_name);
	CO_Rtv_DataString(p_param_data,"GRID_NAME",p_common_grid_mapping_bak_struct_h -> h_grid_name);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY",p_common_grid_mapping_bak_struct_h -> h_grid_query);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY1",p_common_grid_mapping_bak_struct_h -> h_grid_query1);
	CO_Rtv_DataString(p_param_data,"GRID_QUERY2",p_common_grid_mapping_bak_struct_h -> h_grid_query2);
	CO_Rtv_DataString(p_param_data,"DATATYPES",p_common_grid_mapping_bak_struct_h -> h_datatypes);
}






int Populate_COMMON_SEARCH_FORM_MAP(COMMON_SEARCH_FORM_MAP_STRUCT_H *p_common_search_form_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_search_form_map_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_search_form_map_struct_h -> h_func_mode);
	CO_Rtv_DataInt(p_param_data,"FIELD_NO",(int *) &(p_common_search_form_map_struct_h -> h_field_no));
	CO_Rtv_DataString(p_param_data,"FIELD_NAME",p_common_search_form_map_struct_h -> h_field_name);
	CO_Rtv_DataString(p_param_data,"FIELD_DB",p_common_search_form_map_struct_h -> h_field_db);
	CO_Rtv_DataString(p_param_data,"CONTROL_TYPE",p_common_search_form_map_struct_h -> h_control_type);
	CO_Rtv_DataString(p_param_data,"GLOBALPICKLIST_NAME",p_common_search_form_map_struct_h -> h_globalpicklist_name);
	CO_Rtv_DataInt(p_param_data,"FIELD_LENGTH",(int *) &(p_common_search_form_map_struct_h -> h_field_length));
	CO_Rtv_DataInt(p_param_data,"DECIMAL_LENGTH",(int *) &(p_common_search_form_map_struct_h -> h_decimal_length));
}






int Populate_COMMON_SEARCH_FORM_MAP_230106(COMMON_SEARCH_FORM_MAP_230106_STRUCT_H *p_common_search_form_map_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_search_form_map_230106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_search_form_map_230106_struct_h -> h_func_mode);
	CO_Rtv_DataInt(p_param_data,"FIELD_NO",(int *) &(p_common_search_form_map_230106_struct_h -> h_field_no));
	CO_Rtv_DataString(p_param_data,"FIELD_NAME",p_common_search_form_map_230106_struct_h -> h_field_name);
	CO_Rtv_DataString(p_param_data,"FIELD_DB",p_common_search_form_map_230106_struct_h -> h_field_db);
	CO_Rtv_DataString(p_param_data,"CONTROL_TYPE",p_common_search_form_map_230106_struct_h -> h_control_type);
	CO_Rtv_DataString(p_param_data,"GLOBALPICKLIST_NAME",p_common_search_form_map_230106_struct_h -> h_globalpicklist_name);
	CO_Rtv_DataInt(p_param_data,"FIELD_LENGTH",(int *) &(p_common_search_form_map_230106_struct_h -> h_field_length));
	CO_Rtv_DataInt(p_param_data,"DECIMAL_LENGTH",(int *) &(p_common_search_form_map_230106_struct_h -> h_decimal_length));
}






int Populate_COMMON_SEARCH_FORM_MAP_BAK(COMMON_SEARCH_FORM_MAP_BAK_STRUCT_H *p_common_search_form_map_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_search_form_map_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_search_form_map_bak_struct_h -> h_func_mode);
	CO_Rtv_DataInt(p_param_data,"FIELD_NO",(int *) &(p_common_search_form_map_bak_struct_h -> h_field_no));
	CO_Rtv_DataString(p_param_data,"FIELD_NAME",p_common_search_form_map_bak_struct_h -> h_field_name);
	CO_Rtv_DataString(p_param_data,"FIELD_DB",p_common_search_form_map_bak_struct_h -> h_field_db);
	CO_Rtv_DataString(p_param_data,"CONTROL_TYPE",p_common_search_form_map_bak_struct_h -> h_control_type);
	CO_Rtv_DataString(p_param_data,"GLOBALPICKLIST_NAME",p_common_search_form_map_bak_struct_h -> h_globalpicklist_name);
	CO_Rtv_DataInt(p_param_data,"FIELD_LENGTH",(int *) &(p_common_search_form_map_bak_struct_h -> h_field_length));
	CO_Rtv_DataInt(p_param_data,"DECIMAL_LENGTH",(int *) &(p_common_search_form_map_bak_struct_h -> h_decimal_length));
}






int Populate_COMMON_VIEW_FORM_MAP(COMMON_VIEW_FORM_MAP_STRUCT_H *p_common_view_form_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_view_form_map_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_view_form_map_struct_h -> h_func_mode);
	CO_Rtv_DataString(p_param_data,"WHERE_CLAUSE",p_common_view_form_map_struct_h -> h_where_clause);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_view_form_map_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"ORDERBY_CLAUSE",p_common_view_form_map_struct_h -> h_orderby_clause);
	CO_Rtv_DataString(p_param_data,"CASE_STRING_MAP",p_common_view_form_map_struct_h -> h_case_string_map);
	CO_Rtv_DataString(p_param_data,"FORM_TO_CALL",p_common_view_form_map_struct_h -> h_form_to_call);
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_view_form_map_struct_h -> h_grid_indicator);
}






int Populate_COMMON_VIEW_FORM_MAP_230106(COMMON_VIEW_FORM_MAP_230106_STRUCT_H *p_common_view_form_map_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_view_form_map_230106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_view_form_map_230106_struct_h -> h_func_mode);
	CO_Rtv_DataString(p_param_data,"WHERE_CLAUSE",p_common_view_form_map_230106_struct_h -> h_where_clause);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_view_form_map_230106_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"ORDERBY_CLAUSE",p_common_view_form_map_230106_struct_h -> h_orderby_clause);
	CO_Rtv_DataString(p_param_data,"CASE_STRING_MAP",p_common_view_form_map_230106_struct_h -> h_case_string_map);
	CO_Rtv_DataString(p_param_data,"FORM_TO_CALL",p_common_view_form_map_230106_struct_h -> h_form_to_call);
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_view_form_map_230106_struct_h -> h_grid_indicator);
}






int Populate_COMMON_VIEW_FORM_MAP_BAK(COMMON_VIEW_FORM_MAP_BAK_STRUCT_H *p_common_view_form_map_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_common_view_form_map_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"FUNC_MODE",p_common_view_form_map_bak_struct_h -> h_func_mode);
	CO_Rtv_DataString(p_param_data,"WHERE_CLAUSE",p_common_view_form_map_bak_struct_h -> h_where_clause);
	CO_Rtv_DataString(p_param_data,"BASE_QUERY_ID",p_common_view_form_map_bak_struct_h -> h_base_query_id);
	CO_Rtv_DataString(p_param_data,"ORDERBY_CLAUSE",p_common_view_form_map_bak_struct_h -> h_orderby_clause);
	CO_Rtv_DataString(p_param_data,"CASE_STRING_MAP",p_common_view_form_map_bak_struct_h -> h_case_string_map);
	CO_Rtv_DataString(p_param_data,"FORM_TO_CALL",p_common_view_form_map_bak_struct_h -> h_form_to_call);
	CO_Rtv_DataString(p_param_data,"GRID_INDICATOR",p_common_view_form_map_bak_struct_h -> h_grid_indicator);
}






int Populate_CO_STATIC_DATA(CO_STATIC_DATA_STRUCT_H *p_co_static_data_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CODE_IDENT",p_co_static_data_struct_h -> h_code_ident);
	CO_Rtv_DataString(p_param_data,"CODE_VALUE",p_co_static_data_struct_h -> h_code_value);
	CO_Rtv_DataString(p_param_data,"CODE_DESC",p_co_static_data_struct_h -> h_code_desc);
	CO_Rtv_DataString(p_param_data,"COUNTRY_CODE",p_co_static_data_struct_h -> h_country_code);
}






int Populate_CO_STATIC_DATA_BAK(CO_STATIC_DATA_BAK_STRUCT_H *p_co_static_data_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CODE_IDENT",p_co_static_data_bak_struct_h -> h_code_ident);
	CO_Rtv_DataString(p_param_data,"CODE_VALUE",p_co_static_data_bak_struct_h -> h_code_value);
	CO_Rtv_DataString(p_param_data,"CODE_DESC",p_co_static_data_bak_struct_h -> h_code_desc);
	CO_Rtv_DataString(p_param_data,"COUNTRY_CODE",p_co_static_data_bak_struct_h -> h_country_code);
}






int Populate_CSCAENT(CSCAENT_STRUCT_H *p_cscaent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_TYPE",p_cscaent_struct_h -> h_instr_type);
	CO_Rtv_DataString(p_param_data,"DEALTYPE",p_cscaent_struct_h -> h_dealtype);
	CO_Rtv_DataString(p_param_data,"CURR_FLAG",p_cscaent_struct_h -> h_curr_flag);
	CO_Rtv_DataString(p_param_data,"CLASSCD",p_cscaent_struct_h -> h_classcd);
	CO_Rtv_DataString(p_param_data,"DR_CLT_GL",p_cscaent_struct_h -> h_dr_clt_gl);
	CO_Rtv_DataString(p_param_data,"CLT_GL",p_cscaent_struct_h -> h_clt_gl);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_cscaent_struct_h -> h_narrative);
}






int Populate_CSCODE(CSCODE_STRUCT_H *p_cscode_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAP_TYPE",p_cscode_struct_h -> h_map_type);
	CO_Rtv_DataString(p_param_data,"CLASS",p_cscode_struct_h -> h_class);
	CO_Rtv_DataString(p_param_data,"MAP_DESC",p_cscode_struct_h -> h_map_desc);
}






int Populate_CURRENCY_CONV_REPORT(CURRENCY_CONV_REPORT_STRUCT_H *p_currency_conv_report_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_currency_conv_report_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_currency_conv_report_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_currency_conv_report_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_currency_conv_report_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"NOMINAL_VALUE",&(p_currency_conv_report_struct_h -> h_nominal_value));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_currency_conv_report_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"NVALRECEIVE",&(p_currency_conv_report_struct_h -> h_nvalreceive));
	CO_Rtv_DataDbl(p_param_data,"NVALDELIVER",&(p_currency_conv_report_struct_h -> h_nvaldeliver));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_currency_conv_report_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_currency_conv_report_struct_h -> h_val_del));
	CO_Rtv_DataDbl(p_param_data,"CHNG_NOMPR",&(p_currency_conv_report_struct_h -> h_chng_nompr));
	CO_Rtv_DataDbl(p_param_data,"CHNG_POS",&(p_currency_conv_report_struct_h -> h_chng_pos));
	CO_Rtv_DataDbl(p_param_data,"CHNG_NVALREC",&(p_currency_conv_report_struct_h -> h_chng_nvalrec));
	CO_Rtv_DataDbl(p_param_data,"CHNG_NVALDEL",&(p_currency_conv_report_struct_h -> h_chng_nvaldel));
	CO_Rtv_DataDbl(p_param_data,"CHNG_VALREC",&(p_currency_conv_report_struct_h -> h_chng_valrec));
	CO_Rtv_DataDbl(p_param_data,"CHNG_VALDEL",&(p_currency_conv_report_struct_h -> h_chng_valdel));
}






int Populate_DEAL_COUNT(DEAL_COUNT_STRUCT_H *p_deal_count_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"GENERATE_DATE",p_deal_count_struct_h -> h_generate_date);
	CO_Rtv_DataDbl(p_param_data,"DEAL_COUNT",&(p_deal_count_struct_h -> h_deal_count));
}






int Populate_DEAL_EVNTIDLINK(DEAL_EVNTIDLINK_STRUCT_H *p_deal_evntidlink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_deal_evntidlink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_deal_evntidlink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_deal_evntidlink_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSGREFNO",p_deal_evntidlink_struct_h -> h_swift_msgrefno);
	CO_Rtv_DataString(p_param_data,"EVENT_ID",p_deal_evntidlink_struct_h -> h_event_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_deal_evntidlink_struct_h -> h_access_stamp);
}






int Populate_DEAL_LOCALREP_VEW(DEAL_LOCALREP_VEW_STRUCT_H *p_deal_localrep_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_deal_localrep_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_deal_localrep_vew_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_deal_localrep_vew_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_deal_localrep_vew_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_deal_localrep_vew_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_deal_localrep_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_deal_localrep_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_deal_localrep_vew_struct_h -> h_dl_class);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_deal_localrep_vew_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_deal_localrep_vew_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_deal_localrep_vew_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_deal_localrep_vew_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_deal_localrep_vew_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_deal_localrep_vew_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_deal_localrep_vew_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_deal_localrep_vew_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_deal_localrep_vew_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_deal_localrep_vew_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_deal_localrep_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"SETL_IDEN_NO",&(p_deal_localrep_vew_struct_h -> h_setl_iden_no));
}






int Populate_DL_ARCHDEAL(DL_ARCHDEAL_STRUCT_H *p_dl_archdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_archdeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_archdeal_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_archdeal_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_archdeal_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_archdeal_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_archdeal_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_archdeal_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_archdeal_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_archdeal_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_archdeal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_archdeal_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_archdeal_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_archdeal_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_archdeal_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_archdeal_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_archdeal_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_archdeal_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_archdeal_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_archdeal_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_archdeal_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_archdeal_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_archdeal_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_archdeal_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_archdeal_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_archdeal_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_archdeal_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_archdeal_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_archdeal_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_archdeal_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_archdeal_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_archdeal_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_archdeal_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_archdeal_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_archdeal_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_archdeal_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_archdeal_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_archdeal_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_archdeal_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_archdeal_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_archdeal_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_archdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_archdeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_archdeal_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_archdeal_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_archdeal_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_archdeal_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_archdeal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_archdeal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_archdeal_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_archdeal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_archdeal_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_archdeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_archdeal_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_archdeal_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_archdeal_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_archdeal_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_archdeal_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_archdeal_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_archdeal_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_archdeal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_archdeal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_archdeal_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_archdeal_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_archdeal_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_archdeal_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_archdeal_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_archdeal_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_archdeal_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_archdeal_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_archdeal_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_archdeal_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_archdeal_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_archdeal_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_archdeal_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_archdeal_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_archdeal_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_archdeal_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_archdeal_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_archdeal_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_archdeal_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_archdeal_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_archdeal_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_archdeal_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_archdeal_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_archdeal_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_archdeal_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_archdeal_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_archdeal_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_archdeal_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_archdeal_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_archdeal_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_archdeal_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_archdeal_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_archdeal_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_archdeal_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_archdeal_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_archdeal_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_archdeal_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_archdeal_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_archdeal_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_archdeal_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_archdeal_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_archdeal_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_archdeal_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_archdeal_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_archdeal_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_archdeal_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_archdeal_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_archdeal_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_archdeal_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_archdeal_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_archdeal_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_archdeal_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_archdeal_struct_h -> h_informaton);
	CO_Rtv_DataString(p_param_data,"CLNT_NAME",p_dl_archdeal_struct_h -> h_clnt_name);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPNAME",p_dl_archdeal_struct_h -> h_domestic_cpname);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYNM",p_dl_archdeal_struct_h -> h_domcp_custodynm);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_dl_archdeal_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_archdeal_struct_h -> h_closing_date);
}






int Populate_DL_ARCHDLAUDIT(DL_ARCHDLAUDIT_STRUCT_H *p_dl_archdlaudit_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archdlaudit_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archdlaudit_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"TRAIL_FOR",p_dl_archdlaudit_struct_h -> h_trail_for);
	CO_Rtv_DataString(p_param_data,"TASK_DESC",p_dl_archdlaudit_struct_h -> h_task_desc);
	CO_Rtv_DataString(p_param_data,"PROC_USR",p_dl_archdlaudit_struct_h -> h_proc_usr);
	CO_Rtv_DataString(p_param_data,"SUBPROCESS",p_dl_archdlaudit_struct_h -> h_subprocess);
	CO_Rtv_DataString(p_param_data,"PROC_DATE",p_dl_archdlaudit_struct_h -> h_proc_date);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_archdlaudit_struct_h -> h_failreason_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_archdlaudit_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_archdlaudit_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_archdlaudit_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_archdlaudit_struct_h -> h_dateof_input);
}






int Populate_DL_ARCHMSGLINK(DL_ARCHMSGLINK_STRUCT_H *p_dl_archmsglink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_archmsglink_struct_h -> h_closing_date);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archmsglink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archmsglink_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_archmsglink_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_archmsglink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_archmsglink_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_archmsglink_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_archmsglink_struct_h -> h_inden_num));
	CO_Rtv_DataInt(p_param_data,"DL_REP_IDENTNO",(int *) &(p_dl_archmsglink_struct_h -> h_dl_rep_identno));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_archmsglink_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_archmsglink_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_archmsglink_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_archmsglink_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_archmsglink_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"PSETPARTY",p_dl_archmsglink_struct_h -> h_psetparty);
	CO_Rtv_DataString(p_param_data,"PLACE_CD",p_dl_archmsglink_struct_h -> h_place_cd);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_archmsglink_struct_h -> h_narrative);
}






int Populate_DL_ARCHMSGLINKDET(DL_ARCHMSGLINKDET_STRUCT_H *p_dl_archmsglinkdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_archmsglinkdet_struct_h -> h_closing_date);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_archmsglinkdet_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"SEQUENCE_NAME",p_dl_archmsglinkdet_struct_h -> h_sequence_name);
	CO_Rtv_DataString(p_param_data,"LINK_VAL",p_dl_archmsglinkdet_struct_h -> h_link_val);
	CO_Rtv_DataString(p_param_data,"LINK_TAG",p_dl_archmsglinkdet_struct_h -> h_link_tag);
	CO_Rtv_DataInt(p_param_data,"MSG_TAG_REP_NO",(int *) &(p_dl_archmsglinkdet_struct_h -> h_msg_tag_rep_no));
	CO_Rtv_DataInt(p_param_data,"MSG_LINE_NO",(int *) &(p_dl_archmsglinkdet_struct_h -> h_msg_line_no));
	CO_Rtv_DataString(p_param_data,"MSG_TAG",p_dl_archmsglinkdet_struct_h -> h_msg_tag);
}






int Populate_DL_ARCHREGDET(DL_ARCHREGDET_STRUCT_H *p_dl_archregdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archregdet_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archregdet_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_archregdet_struct_h -> h_srl_no));
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_archregdet_struct_h -> h_reg_st_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DT",p_dl_archregdet_struct_h -> h_deal_dt);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY",&(p_dl_archregdet_struct_h -> h_quantity));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_archregdet_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"MOVED_QTY",&(p_dl_archregdet_struct_h -> h_moved_qty));
	CO_Rtv_DataDbl(p_param_data,"MANIFOLD_QTY",&(p_dl_archregdet_struct_h -> h_manifold_qty));
	CO_Rtv_DataString(p_param_data,"DT_CLIENT_FOR",p_dl_archregdet_struct_h -> h_dt_client_for);
	CO_Rtv_DataString(p_param_data,"PRC_SMR_DATE",p_dl_archregdet_struct_h -> h_prc_smr_date);
	CO_Rtv_DataString(p_param_data,"STATUS_PRC",p_dl_archregdet_struct_h -> h_status_prc);
	CO_Rtv_DataString(p_param_data,"PRC_SETL_DATE",p_dl_archregdet_struct_h -> h_prc_setl_date);
	CO_Rtv_DataDbl(p_param_data,"AMR_AMOUNT",&(p_dl_archregdet_struct_h -> h_amr_amount));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_archregdet_struct_h -> h_dateof_input);
}






int Populate_DL_ARCHREGPAR(DL_ARCHREGPAR_STRUCT_H *p_dl_archregpar_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archregpar_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archregpar_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_archregpar_struct_h -> h_srl_no));
	CO_Rtv_DataInt(p_param_data,"PARENT_SRLNO",(int *) &(p_dl_archregpar_struct_h -> h_parent_srlno));
	CO_Rtv_DataDbl(p_param_data,"PARENT_QTY",&(p_dl_archregpar_struct_h -> h_parent_qty));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_archregpar_struct_h -> h_dateof_input);
}






int Populate_DL_ARCHRUHISDEAL(DL_ARCHRUHISDEAL_STRUCT_H *p_dl_archruhisdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archruhisdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_archruhisdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_archruhisdeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_archruhisdeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_archruhisdeal_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_archruhisdeal_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_archruhisdeal_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_archruhisdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_archruhisdeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_archruhisdeal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_archruhisdeal_struct_h -> h_dateof_input);
}






int Populate_DL_ARCHSAFEK(DL_ARCHSAFEK_STRUCT_H *p_dl_archsafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_archsafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"POSIT_DATE",p_dl_archsafek_struct_h -> h_posit_date);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_archsafek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_archsafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_archsafek_struct_h -> h_status_pos);
	CO_Rtv_DataDbl(p_param_data,"START_SAFEK",&(p_dl_archsafek_struct_h -> h_start_safek));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_archsafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"NVALRECEIVE",&(p_dl_archsafek_struct_h -> h_nvalreceive));
	CO_Rtv_DataDbl(p_param_data,"NVALDELIVER",&(p_dl_archsafek_struct_h -> h_nvaldeliver));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_archsafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_archsafek_struct_h -> h_val_del));
}






int Populate_DL_AUTOSETTHUFMT(DL_AUTOSETTHUFMT_STRUCT_H *p_dl_autosetthufmt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"TYPEOF_FILE",p_dl_autosetthufmt_struct_h -> h_typeof_file);
	CO_Rtv_DataString(p_param_data,"FIELD_NAME",p_dl_autosetthufmt_struct_h -> h_field_name);
	CO_Rtv_DataInt(p_param_data,"START_POS",(int *) &(p_dl_autosetthufmt_struct_h -> h_start_pos));
	CO_Rtv_DataInt(p_param_data,"LENGTH",(int *) &(p_dl_autosetthufmt_struct_h -> h_length));
	CO_Rtv_DataString(p_param_data,"INFOTYPE",p_dl_autosetthufmt_struct_h -> h_infotype);
}






int Populate_DL_AUTOSETTHUWRK(DL_AUTOSETTHUWRK_STRUCT_H *p_dl_autosetthuwrk_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLASS",p_dl_autosetthuwrk_struct_h -> h_class);
	CO_Rtv_DataString(p_param_data,"FROM_PER",p_dl_autosetthuwrk_struct_h -> h_from_per);
	CO_Rtv_DataString(p_param_data,"TO_PER",p_dl_autosetthuwrk_struct_h -> h_to_per);
	CO_Rtv_DataString(p_param_data,"MAIN_OUR",p_dl_autosetthuwrk_struct_h -> h_main_our);
	CO_Rtv_DataString(p_param_data,"DELNAME",p_dl_autosetthuwrk_struct_h -> h_delname);
	CO_Rtv_DataString(p_param_data,"DET",p_dl_autosetthuwrk_struct_h -> h_det);
	CO_Rtv_DataString(p_param_data,"SUB_OUR",p_dl_autosetthuwrk_struct_h -> h_sub_our);
	CO_Rtv_DataString(p_param_data,"SUB_SUBNAME",p_dl_autosetthuwrk_struct_h -> h_sub_subname);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_autosetthuwrk_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"SEC_NAME",p_dl_autosetthuwrk_struct_h -> h_sec_name);
	CO_Rtv_DataString(p_param_data,"INSTR_SEQ",p_dl_autosetthuwrk_struct_h -> h_instr_seq);
	CO_Rtv_DataInt(p_param_data,"TYPEOFINSTR",(int *) &(p_dl_autosetthuwrk_struct_h -> h_typeofinstr));
	CO_Rtv_DataString(p_param_data,"INSTR_TEXT",p_dl_autosetthuwrk_struct_h -> h_instr_text);
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_dl_autosetthuwrk_struct_h -> h_instr_isin);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_dl_autosetthuwrk_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"DEALCODE",p_dl_autosetthuwrk_struct_h -> h_dealcode);
	CO_Rtv_DataString(p_param_data,"DEALNAME",p_dl_autosetthuwrk_struct_h -> h_dealname);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_autosetthuwrk_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_autosetthuwrk_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"MAIN_CP",p_dl_autosetthuwrk_struct_h -> h_main_cp);
	CO_Rtv_DataString(p_param_data,"SUB_CP",p_dl_autosetthuwrk_struct_h -> h_sub_cp);
	CO_Rtv_DataInt(p_param_data,"QUANTITY_RECEIVED",(int *) &(p_dl_autosetthuwrk_struct_h -> h_quantity_received));
	CO_Rtv_DataInt(p_param_data,"QUANTITY_DEL",(int *) &(p_dl_autosetthuwrk_struct_h -> h_quantity_del));
	CO_Rtv_DataInt(p_param_data,"DEAL_IN",(int *) &(p_dl_autosetthuwrk_struct_h -> h_deal_in));
	CO_Rtv_DataInt(p_param_data,"DEAL_OUT",(int *) &(p_dl_autosetthuwrk_struct_h -> h_deal_out));
	CO_Rtv_DataInt(p_param_data,"OTC_POS",(int *) &(p_dl_autosetthuwrk_struct_h -> h_otc_pos));
	CO_Rtv_DataInt(p_param_data,"NOMINAL_VALUE",(int *) &(p_dl_autosetthuwrk_struct_h -> h_nominal_value));
	CO_Rtv_DataString(p_param_data,"PARTNER_A",p_dl_autosetthuwrk_struct_h -> h_partner_a);
	CO_Rtv_DataInt(p_param_data,"QUANTITY_A",(int *) &(p_dl_autosetthuwrk_struct_h -> h_quantity_a));
	CO_Rtv_DataString(p_param_data,"OTHER_A",p_dl_autosetthuwrk_struct_h -> h_other_a);
	CO_Rtv_DataString(p_param_data,"PARTNER_B",p_dl_autosetthuwrk_struct_h -> h_partner_b);
	CO_Rtv_DataInt(p_param_data,"QUANTITY_B",(int *) &(p_dl_autosetthuwrk_struct_h -> h_quantity_b));
	CO_Rtv_DataString(p_param_data,"OTHER_B",p_dl_autosetthuwrk_struct_h -> h_other_b);
	CO_Rtv_DataString(p_param_data,"PARTNER_C",p_dl_autosetthuwrk_struct_h -> h_partner_c);
	CO_Rtv_DataInt(p_param_data,"QUANTITY_C",(int *) &(p_dl_autosetthuwrk_struct_h -> h_quantity_c));
	CO_Rtv_DataString(p_param_data,"OTHER_C",p_dl_autosetthuwrk_struct_h -> h_other_c);
	CO_Rtv_DataString(p_param_data,"INDICATOR",p_dl_autosetthuwrk_struct_h -> h_indicator);
	CO_Rtv_DataString(p_param_data,"REAS",p_dl_autosetthuwrk_struct_h -> h_reas);
	CO_Rtv_DataInt(p_param_data,"MISMATCH",(int *) &(p_dl_autosetthuwrk_struct_h -> h_mismatch));
	CO_Rtv_DataString(p_param_data,"ACT_CLT",p_dl_autosetthuwrk_struct_h -> h_act_clt);
	CO_Rtv_DataString(p_param_data,"ACT_IDENTITYNO",p_dl_autosetthuwrk_struct_h -> h_act_identityno);
	CO_Rtv_DataInt(p_param_data,"REC_NO",(int *) &(p_dl_autosetthuwrk_struct_h -> h_rec_no));
	CO_Rtv_DataInt(p_param_data,"IDEN_NO",(int *) &(p_dl_autosetthuwrk_struct_h -> h_iden_no));
}






int Populate_DL_CASHBAL(DL_CASHBAL_STRUCT_H *p_dl_cashbal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"GL_CLT",p_dl_cashbal_struct_h -> h_gl_clt);
	CO_Rtv_DataDbl(p_param_data,"CASH_BAL",&(p_dl_cashbal_struct_h -> h_cash_bal));
}






int Populate_DL_CASHCLT(DL_CASHCLT_STRUCT_H *p_dl_cashclt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_cashclt_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_cashclt_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"GL_ACCOUNT",p_dl_cashclt_struct_h -> h_gl_account);
	CO_Rtv_DataString(p_param_data,"DEFAULT_CCY",p_dl_cashclt_struct_h -> h_default_ccy);
	CO_Rtv_DataString(p_param_data,"IBAN_CLT",p_dl_cashclt_struct_h -> h_iban_clt);
	CO_Rtv_DataString(p_param_data,"ADDITION_ACC",p_dl_cashclt_struct_h -> h_addition_acc);
}






int Populate_DL_CCSFAILMSG(DL_CCSFAILMSG_STRUCT_H *p_dl_ccsfailmsg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ccsfailmsg_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_ccsfailmsg_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"REPORT_DT",p_dl_ccsfailmsg_struct_h -> h_report_dt);
	CO_Rtv_DataString(p_param_data,"REAS",p_dl_ccsfailmsg_struct_h -> h_reas);
	CO_Rtv_DataString(p_param_data,"REPORT_IND",p_dl_ccsfailmsg_struct_h -> h_report_ind);
}






int Populate_DL_CCSPENDTXN(DL_CCSPENDTXN_STRUCT_H *p_dl_ccspendtxn_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MSG_CLASS",p_dl_ccspendtxn_struct_h -> h_msg_class);
	CO_Rtv_DataString(p_param_data,"IDENTITY",p_dl_ccspendtxn_struct_h -> h_identity);
	CO_Rtv_DataString(p_param_data,"TLC_DEAL_TYPE",p_dl_ccspendtxn_struct_h -> h_tlc_deal_type);
	CO_Rtv_DataString(p_param_data,"DEAL_CODE",p_dl_ccspendtxn_struct_h -> h_deal_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ccspendtxn_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_dl_ccspendtxn_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"CLNT_IDENT",p_dl_ccspendtxn_struct_h -> h_clnt_ident);
	CO_Rtv_DataString(p_param_data,"BRK",p_dl_ccspendtxn_struct_h -> h_brk);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_ccspendtxn_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_ccspendtxn_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_ccspendtxn_struct_h -> h_currency_cd);
	CO_Rtv_DataInt(p_param_data,"AMT",(int *) &(p_dl_ccspendtxn_struct_h -> h_amt));
	CO_Rtv_DataString(p_param_data,"SIGNATURE",p_dl_ccspendtxn_struct_h -> h_signature);
	CO_Rtv_DataInt(p_param_data,"GL_CLT",(int *) &(p_dl_ccspendtxn_struct_h -> h_gl_clt));
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_ccspendtxn_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_ccspendtxn_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_ccspendtxn_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_ccspendtxn_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"MKRT_DL_CLASS",p_dl_ccspendtxn_struct_h -> h_mkrt_dl_class);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_ccspendtxn_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_ccspendtxn_struct_h -> h_failreason_cd);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_ccspendtxn_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_ccspendtxn_struct_h -> h_fail_det);
	CO_Rtv_DataInt(p_param_data,"FAILREASON_INDEX",(int *) &(p_dl_ccspendtxn_struct_h -> h_failreason_index));
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_ccspendtxn_struct_h -> h_narrative);
	CO_Rtv_DataString(p_param_data,"ACTUAL_SETLDT",p_dl_ccspendtxn_struct_h -> h_actual_setldt);
	CO_Rtv_DataString(p_param_data,"PROCESSDT",p_dl_ccspendtxn_struct_h -> h_processdt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_ccspendtxn_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_dl_ccspendtxn_struct_h -> h_status_ind);
	CO_Rtv_DataInt(p_param_data,"IDEN_NO",(int *) &(p_dl_ccspendtxn_struct_h -> h_iden_no));
}






int Populate_DL_CLHTR(DL_CLHTR_STRUCT_H *p_dl_clhtr_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_clhtr_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_clhtr_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"REC_DEL",p_dl_clhtr_struct_h -> h_rec_del);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_clhtr_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_clhtr_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"ACT_DVP",p_dl_clhtr_struct_h -> h_act_dvp);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_clhtr_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_clhtr_struct_h -> h_cp_clt);
}






int Populate_DL_COPYHISTORY(DL_COPYHISTORY_STRUCT_H *p_dl_copyhistory_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_copyhistory_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_copyhistory_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_copyhistory_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_copyhistory_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_copyhistory_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_copyhistory_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_copyhistory_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_copyhistory_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_copyhistory_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_copyhistory_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_copyhistory_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_copyhistory_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_copyhistory_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_copyhistory_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_copyhistory_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_copyhistory_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_copyhistory_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_copyhistory_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_copyhistory_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_copyhistory_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_copyhistory_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_copyhistory_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_copyhistory_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_copyhistory_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_copyhistory_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_copyhistory_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_copyhistory_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_copyhistory_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_copyhistory_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_copyhistory_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_copyhistory_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_copyhistory_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_copyhistory_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_copyhistory_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_copyhistory_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_copyhistory_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_copyhistory_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_copyhistory_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_copyhistory_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_copyhistory_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_copyhistory_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_copyhistory_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_copyhistory_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_copyhistory_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_copyhistory_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_copyhistory_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_copyhistory_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_copyhistory_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_copyhistory_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_copyhistory_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_copyhistory_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_copyhistory_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_copyhistory_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_copyhistory_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_copyhistory_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_copyhistory_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_copyhistory_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_copyhistory_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_copyhistory_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_copyhistory_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_copyhistory_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_copyhistory_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_copyhistory_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_copyhistory_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_copyhistory_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_copyhistory_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_copyhistory_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_copyhistory_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_copyhistory_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_copyhistory_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_copyhistory_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_copyhistory_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_copyhistory_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_copyhistory_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_copyhistory_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_copyhistory_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_copyhistory_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_copyhistory_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_copyhistory_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_copyhistory_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_copyhistory_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_copyhistory_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_copyhistory_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_copyhistory_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_copyhistory_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_copyhistory_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_copyhistory_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_copyhistory_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_copyhistory_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_copyhistory_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_copyhistory_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_copyhistory_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_copyhistory_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_copyhistory_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_copyhistory_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_copyhistory_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_copyhistory_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_copyhistory_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_copyhistory_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_copyhistory_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_copyhistory_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_copyhistory_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_copyhistory_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_copyhistory_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_copyhistory_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_copyhistory_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_copyhistory_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_copyhistory_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_copyhistory_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_copyhistory_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_copyhistory_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_copyhistory_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_copyhistory_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_copyhistory_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_copyhistory_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_copyhistory_struct_h -> h_informaton);
}






int Populate_DL_CURRENCY(DL_CURRENCY_STRUCT_H *p_dl_currency_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_currency_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"CURRENCY_DESC",p_dl_currency_struct_h -> h_currency_desc);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_currency_struct_h -> h_maker);
	CO_Rtv_DataInt(p_param_data,"DEC_LEN",(int *) &(p_dl_currency_struct_h -> h_dec_len));
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_currency_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_currency_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"GL_CD",p_dl_currency_struct_h -> h_gl_cd);
}






int Populate_DL_CURRENCY_VEW(DL_CURRENCY_VEW_STRUCT_H *p_dl_currency_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_currency_vew_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"CURRENCY_DESC",p_dl_currency_vew_struct_h -> h_currency_desc);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_currency_vew_struct_h -> h_maker);
	CO_Rtv_DataInt(p_param_data,"DEC_LEN",(int *) &(p_dl_currency_vew_struct_h -> h_dec_len));
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_currency_vew_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_currency_vew_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"GL_CD",p_dl_currency_vew_struct_h -> h_gl_cd);
}






int Populate_DL_DEAL(DL_DEAL_STRUCT_H *p_dl_deal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_deal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_deal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_deal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_deal_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_deal_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_deal_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_deal_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_deal_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_deal_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_deal_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_deal_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_deal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_deal_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_deal_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_deal_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_deal_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_deal_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_deal_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_deal_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_deal_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_deal_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_deal_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_deal_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_deal_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_deal_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_deal_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_deal_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_deal_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_deal_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_deal_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_deal_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_deal_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_deal_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_deal_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_deal_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_deal_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_deal_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_deal_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_deal_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_deal_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_deal_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_deal_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_deal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_deal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_deal_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_deal_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_deal_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_deal_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_deal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_deal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_deal_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_deal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_deal_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_deal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_deal_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_deal_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_deal_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_deal_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_deal_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_deal_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_deal_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_deal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_deal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_deal_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_deal_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_deal_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_deal_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_deal_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_deal_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_deal_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_deal_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_deal_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_deal_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_deal_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_deal_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_deal_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_deal_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_deal_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_deal_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_deal_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_deal_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_deal_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_deal_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_deal_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_deal_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_deal_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_deal_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_deal_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_deal_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_deal_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_deal_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_deal_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_deal_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_deal_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_deal_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_deal_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_deal_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_deal_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_deal_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_deal_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_deal_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_deal_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_deal_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_deal_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_deal_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_deal_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_deal_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_deal_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_deal_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_deal_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_deal_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_deal_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_deal_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_deal_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_deal_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_deal_struct_h -> h_informaton);
}






int Populate_DL_DEALAUDIT(DL_DEALAUDIT_STRUCT_H *p_dl_dealaudit_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_dealaudit_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_dealaudit_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"TRAIL_FOR",p_dl_dealaudit_struct_h -> h_trail_for);
	CO_Rtv_DataString(p_param_data,"TASK_DESC",p_dl_dealaudit_struct_h -> h_task_desc);
	CO_Rtv_DataString(p_param_data,"PROC_USR",p_dl_dealaudit_struct_h -> h_proc_usr);
	CO_Rtv_DataString(p_param_data,"SUBPROCESS",p_dl_dealaudit_struct_h -> h_subprocess);
	CO_Rtv_DataString(p_param_data,"PROC_DATE",p_dl_dealaudit_struct_h -> h_proc_date);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_dealaudit_struct_h -> h_failreason_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_dealaudit_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_dealaudit_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_dealaudit_struct_h -> h_sub_fail_cd));
}






int Populate_DL_DEALCLIENTIMG(DL_DEALCLIENTIMG_STRUCT_H *p_dl_dealclientimg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_dealclientimg_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_dealclientimg_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_dealclientimg_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_dealclientimg_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_dealclientimg_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_dealclientimg_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_dealclientimg_struct_h -> h_currency_cd);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_dealclientimg_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_dealclientimg_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_dealclientimg_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_dealclientimg_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_dealclientimg_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_dealclientimg_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_dealclientimg_struct_h -> h_money_setl_dt);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYGL",p_dl_dealclientimg_struct_h -> h_domcp_custodygl);
	CO_Rtv_DataString(p_param_data,"CLT_GL",p_dl_dealclientimg_struct_h -> h_clt_gl);
	CO_Rtv_DataString(p_param_data,"VALUEDT",p_dl_dealclientimg_struct_h -> h_valuedt);
	CO_Rtv_DataString(p_param_data,"TYPEOF_ENT",p_dl_dealclientimg_struct_h -> h_typeof_ent);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_dealclientimg_struct_h -> h_access_stamp);
	CO_Rtv_DataInt(p_param_data,"PROCNUM",(int *) &(p_dl_dealclientimg_struct_h -> h_procnum));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_dealclientimg_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_dealclientimg_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_dealclientimg_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_dealclientimg_struct_h -> h_oth_comm));
}






int Populate_DL_DEALDET(DL_DEALDET_STRUCT_H *p_dl_dealdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_dealdet_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_dealdet_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"REPORTDT",p_dl_dealdet_struct_h -> h_reportdt);
	CO_Rtv_DataString(p_param_data,"FLAG",p_dl_dealdet_struct_h -> h_flag);
	CO_Rtv_DataString(p_param_data,"STAT_DET",p_dl_dealdet_struct_h -> h_stat_det);
}






int Populate_DL_DEALREPAIR(DL_DEALREPAIR_STRUCT_H *p_dl_dealrepair_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"DL_REP_IDENTNO",(int *) &(p_dl_dealrepair_struct_h -> h_dl_rep_identno));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_dealrepair_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_dealrepair_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_dealrepair_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_dealrepair_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_dealrepair_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_dealrepair_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_dealrepair_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_dealrepair_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_dealrepair_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_dealrepair_struct_h -> h_dl_class);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_dealrepair_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_dealrepair_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_dealrepair_struct_h -> h_spottrd_ind);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_dealrepair_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_dealrepair_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_dealrepair_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_dealrepair_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_dealrepair_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_dealrepair_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_dealrepair_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_dealrepair_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_dealrepair_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_dealrepair_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_dealrepair_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_dealrepair_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_dealrepair_struct_h -> h_fx_reqd);
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_dealrepair_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_dealrepair_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_dealrepair_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_dealrepair_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_dealrepair_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_dealrepair_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_dl_dealrepair_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"CLT_NAME",p_dl_dealrepair_struct_h -> h_clt_name);
	CO_Rtv_DataString(p_param_data,"DOMESTICCP_NAME",p_dl_dealrepair_struct_h -> h_domesticcp_name);
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_dealrepair_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_dealrepair_struct_h -> h_gl_client);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_dealrepair_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_dealrepair_struct_h -> h_instruct_person);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_dealrepair_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_dealrepair_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_dealrepair_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_dealrepair_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_dealrepair_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_dealrepair_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_dealrepair_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_dealrepair_struct_h -> h_del_rec_date);
}






int Populate_DL_DEALRST(DL_DEALRST_STRUCT_H *p_dl_dealrst_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_dealrst_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_dealrst_struct_h -> h_identiy_no);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_dealrst_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_dealrst_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_dealrst_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_dealrst_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_dealrst_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_dealrst_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_dealrst_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_dealrst_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_dealrst_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_dealrst_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_dealrst_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_dealrst_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_dealrst_struct_h -> h_money_setl_dt);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_dealrst_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_dealrst_struct_h -> h_orig_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_dealrst_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_dealrst_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_dealrst_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"RESET_DT",p_dl_dealrst_struct_h -> h_reset_dt);
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_dealrst_struct_h -> h_msg_stat);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_dealrst_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_dealrst_struct_h -> h_instruct_person);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_dealrst_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_dealrst_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_dealrst_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_dealrst_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_dealrst_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_dealrst_struct_h -> h_location_cd);
}






int Populate_DL_DEPOPROCESSING(DL_DEPOPROCESSING_STRUCT_H *p_dl_depoprocessing_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEPO_LOC",p_dl_depoprocessing_struct_h -> h_depo_loc);
	CO_Rtv_DataString(p_param_data,"DEPO_DET",p_dl_depoprocessing_struct_h -> h_depo_det);
	CO_Rtv_DataString(p_param_data,"OMNIBUS_CLIENT",p_dl_depoprocessing_struct_h -> h_omnibus_client);
	CO_Rtv_DataString(p_param_data,"IND_54X",p_dl_depoprocessing_struct_h -> h_ind_54x);
	CO_Rtv_DataString(p_param_data,"VP_IND",p_dl_depoprocessing_struct_h -> h_vp_ind);
	CO_Rtv_DataString(p_param_data,"DEAL_537IND",p_dl_depoprocessing_struct_h -> h_deal_537ind);
	CO_Rtv_DataString(p_param_data,"DEAL_548IND",p_dl_depoprocessing_struct_h -> h_deal_548ind);
	CO_Rtv_DataString(p_param_data,"VAL_UNIQUE_IDENTITY",p_dl_depoprocessing_struct_h -> h_val_unique_identity);
}






int Populate_DL_EOMDEAL(DL_EOMDEAL_STRUCT_H *p_dl_eomdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_eomdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_eomdeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_eomdeal_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_eomdeal_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_eomdeal_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_eomdeal_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_eomdeal_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_eomdeal_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_eomdeal_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_eomdeal_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_eomdeal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_eomdeal_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_eomdeal_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_eomdeal_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_eomdeal_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_eomdeal_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_eomdeal_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_eomdeal_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_eomdeal_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_eomdeal_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_eomdeal_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_eomdeal_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_eomdeal_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_eomdeal_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_eomdeal_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_eomdeal_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_eomdeal_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_eomdeal_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_eomdeal_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_eomdeal_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_eomdeal_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_eomdeal_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_eomdeal_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_eomdeal_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_eomdeal_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_eomdeal_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_eomdeal_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_eomdeal_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_eomdeal_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_eomdeal_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_eomdeal_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_eomdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomdeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_eomdeal_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_eomdeal_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_eomdeal_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_eomdeal_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_eomdeal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_eomdeal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_eomdeal_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_eomdeal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_eomdeal_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_eomdeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_eomdeal_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_eomdeal_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_eomdeal_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_eomdeal_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_eomdeal_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_eomdeal_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_eomdeal_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_eomdeal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_eomdeal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_eomdeal_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_eomdeal_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_eomdeal_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_eomdeal_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_eomdeal_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_eomdeal_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_eomdeal_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_eomdeal_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_eomdeal_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_eomdeal_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_eomdeal_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_eomdeal_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_eomdeal_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_eomdeal_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_eomdeal_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_eomdeal_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_eomdeal_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_eomdeal_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_eomdeal_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_eomdeal_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_eomdeal_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_eomdeal_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_eomdeal_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_eomdeal_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_eomdeal_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_eomdeal_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_eomdeal_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_eomdeal_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_eomdeal_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_eomdeal_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_eomdeal_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_eomdeal_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_eomdeal_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_eomdeal_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_eomdeal_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_eomdeal_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_eomdeal_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_eomdeal_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_eomdeal_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_eomdeal_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_eomdeal_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_eomdeal_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_eomdeal_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_eomdeal_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_eomdeal_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_eomdeal_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_eomdeal_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_eomdeal_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_eomdeal_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_eomdeal_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_eomdeal_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_eomdeal_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_eomdeal_struct_h -> h_informaton);
}






int Populate_DL_EOMSAFEK(DL_EOMSAFEK_STRUCT_H *p_dl_eomsafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomsafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_eomsafek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomsafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_eomsafek_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_eomsafek_struct_h -> h_status_pos);
	CO_Rtv_DataDbl(p_param_data,"START_SAFEK",&(p_dl_eomsafek_struct_h -> h_start_safek));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_eomsafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"NVALRECEIVE",&(p_dl_eomsafek_struct_h -> h_nvalreceive));
	CO_Rtv_DataDbl(p_param_data,"NVALDELIVER",&(p_dl_eomsafek_struct_h -> h_nvaldeliver));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_eomsafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_eomsafek_struct_h -> h_val_del));
}






int Populate_DL_EOMSTM_ADJ_VEW(DL_EOMSTM_ADJ_VEW_STRUCT_H *p_dl_eomstm_adj_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomstm_adj_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomstm_adj_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_eomstm_adj_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_eomstm_adj_vew_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_eomstm_adj_vew_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_eomstm_adj_vew_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_eomstm_adj_vew_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_eomstm_adj_vew_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_eomstm_adj_vew_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_eomstm_adj_vew_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_eomstm_adj_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_eomstm_adj_vew_struct_h -> h_report_at_eom_ind);
}






int Populate_DL_EOMSTM_CURR_VEW(DL_EOMSTM_CURR_VEW_STRUCT_H *p_dl_eomstm_curr_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomstm_curr_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomstm_curr_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_eomstm_curr_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_eomstm_curr_vew_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_eomstm_curr_vew_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_eomstm_curr_vew_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_eomstm_curr_vew_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_eomstm_curr_vew_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_eomstm_curr_vew_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_eomstm_curr_vew_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_eomstm_curr_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_eomstm_curr_vew_struct_h -> h_report_at_eom_ind);
}






int Populate_DL_EOMSTM_FAIL_VEW(DL_EOMSTM_FAIL_VEW_STRUCT_H *p_dl_eomstm_fail_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomstm_fail_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomstm_fail_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_eomstm_fail_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_eomstm_fail_vew_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_eomstm_fail_vew_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_eomstm_fail_vew_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_eomstm_fail_vew_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_eomstm_fail_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_eomstm_fail_vew_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_eomstm_fail_vew_struct_h -> h_deal_cd);
}






int Populate_DL_EOMSTM_PEND_VEW(DL_EOMSTM_PEND_VEW_STRUCT_H *p_dl_eomstm_pend_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_eomstm_pend_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_eomstm_pend_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_eomstm_pend_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_eomstm_pend_vew_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_eomstm_pend_vew_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_eomstm_pend_vew_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_eomstm_pend_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_eomstm_pend_vew_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_eomstm_pend_vew_struct_h -> h_deal_cd);
}






int Populate_DL_FUTURE_VDP_VEW(DL_FUTURE_VDP_VEW_STRUCT_H *p_dl_future_vdp_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_future_vdp_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_future_vdp_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_future_vdp_vew_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_future_vdp_vew_struct_h -> h_status_pos);
	CO_Rtv_DataInt(p_param_data,"VDP_POS",(int *) &(p_dl_future_vdp_vew_struct_h -> h_vdp_pos));
	CO_Rtv_DataString(p_param_data,"VDP_DATE",p_dl_future_vdp_vew_struct_h -> h_vdp_date);
}






int Populate_DL_HISDEAL(DL_HISDEAL_STRUCT_H *p_dl_hisdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hisdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hisdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_hisdeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_hisdeal_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_hisdeal_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_hisdeal_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_hisdeal_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_hisdeal_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_hisdeal_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_hisdeal_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_hisdeal_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_hisdeal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_hisdeal_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_hisdeal_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_hisdeal_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_hisdeal_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_hisdeal_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_hisdeal_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_hisdeal_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_hisdeal_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_hisdeal_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_hisdeal_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_hisdeal_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_hisdeal_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_hisdeal_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_hisdeal_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_hisdeal_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_hisdeal_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_hisdeal_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_hisdeal_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_hisdeal_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_hisdeal_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_hisdeal_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_hisdeal_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_hisdeal_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_hisdeal_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_hisdeal_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_hisdeal_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_hisdeal_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_hisdeal_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_hisdeal_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_hisdeal_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_hisdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_hisdeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_hisdeal_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_hisdeal_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_hisdeal_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_hisdeal_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_hisdeal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_hisdeal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_hisdeal_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_hisdeal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_hisdeal_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_hisdeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_hisdeal_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_hisdeal_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_hisdeal_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_hisdeal_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_hisdeal_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_hisdeal_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_hisdeal_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_hisdeal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_hisdeal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_hisdeal_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_hisdeal_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_hisdeal_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_hisdeal_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_hisdeal_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_hisdeal_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_hisdeal_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_hisdeal_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_hisdeal_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_hisdeal_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_hisdeal_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_hisdeal_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_hisdeal_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_hisdeal_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_hisdeal_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_hisdeal_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_hisdeal_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_hisdeal_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_hisdeal_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_hisdeal_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_hisdeal_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_hisdeal_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_hisdeal_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_hisdeal_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_hisdeal_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_hisdeal_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_hisdeal_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_hisdeal_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_hisdeal_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_hisdeal_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_hisdeal_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_hisdeal_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_hisdeal_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_hisdeal_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_hisdeal_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_hisdeal_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_hisdeal_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_hisdeal_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_hisdeal_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_hisdeal_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_hisdeal_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_hisdeal_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_hisdeal_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_hisdeal_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_hisdeal_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_hisdeal_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_hisdeal_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_hisdeal_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_hisdeal_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_hisdeal_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_hisdeal_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_hisdeal_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_hisdeal_struct_h -> h_informaton);
	CO_Rtv_DataString(p_param_data,"CLNT_NAME",p_dl_hisdeal_struct_h -> h_clnt_name);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPNAME",p_dl_hisdeal_struct_h -> h_domestic_cpname);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYNM",p_dl_hisdeal_struct_h -> h_domcp_custodynm);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_dl_hisdeal_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_hisdeal_struct_h -> h_closing_date);
}






int Populate_DL_HISDEALSAUDIT(DL_HISDEALSAUDIT_STRUCT_H *p_dl_hisdealsaudit_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hisdealsaudit_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hisdealsaudit_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"TRAIL_FOR",p_dl_hisdealsaudit_struct_h -> h_trail_for);
	CO_Rtv_DataString(p_param_data,"TASK_DESC",p_dl_hisdealsaudit_struct_h -> h_task_desc);
	CO_Rtv_DataString(p_param_data,"PROC_USR",p_dl_hisdealsaudit_struct_h -> h_proc_usr);
	CO_Rtv_DataString(p_param_data,"SUBPROCESS",p_dl_hisdealsaudit_struct_h -> h_subprocess);
	CO_Rtv_DataString(p_param_data,"PROC_DATE",p_dl_hisdealsaudit_struct_h -> h_proc_date);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_hisdealsaudit_struct_h -> h_failreason_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_hisdealsaudit_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_hisdealsaudit_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_hisdealsaudit_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_hisdealsaudit_struct_h -> h_dateof_input);
}






int Populate_DL_HISDEAL_VEW(DL_HISDEAL_VEW_STRUCT_H *p_dl_hisdeal_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hisdeal_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hisdeal_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_hisdeal_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_hisdeal_vew_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_hisdeal_vew_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_hisdeal_vew_struct_h -> h_deal_stat);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_hisdeal_vew_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_hisdeal_vew_struct_h -> h_deal_cd);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_hisdeal_vew_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_hisdeal_vew_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_hisdeal_vew_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_hisdeal_vew_struct_h -> h_setl_date);
}






int Populate_DL_HISMSGLINK(DL_HISMSGLINK_STRUCT_H *p_dl_hismsglink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_hismsglink_struct_h -> h_closing_date);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hismsglink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hismsglink_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_hismsglink_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_hismsglink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_hismsglink_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_hismsglink_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_hismsglink_struct_h -> h_inden_num));
	CO_Rtv_DataInt(p_param_data,"DL_REP_IDENTNO",(int *) &(p_dl_hismsglink_struct_h -> h_dl_rep_identno));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_hismsglink_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_hismsglink_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_hismsglink_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_hismsglink_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_hismsglink_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"PSETPARTY",p_dl_hismsglink_struct_h -> h_psetparty);
	CO_Rtv_DataString(p_param_data,"PLACE_CD",p_dl_hismsglink_struct_h -> h_place_cd);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_hismsglink_struct_h -> h_narrative);
}






int Populate_DL_HISMSGLINKDET(DL_HISMSGLINKDET_STRUCT_H *p_dl_hismsglinkdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_hismsglinkdet_struct_h -> h_closing_date);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_hismsglinkdet_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"SEQUENCE_NAME",p_dl_hismsglinkdet_struct_h -> h_sequence_name);
	CO_Rtv_DataString(p_param_data,"LINK_VAL",p_dl_hismsglinkdet_struct_h -> h_link_val);
	CO_Rtv_DataString(p_param_data,"LINK_TAG",p_dl_hismsglinkdet_struct_h -> h_link_tag);
	CO_Rtv_DataInt(p_param_data,"MSG_TAG_REP_NO",(int *) &(p_dl_hismsglinkdet_struct_h -> h_msg_tag_rep_no));
	CO_Rtv_DataInt(p_param_data,"MSG_LINE_NO",(int *) &(p_dl_hismsglinkdet_struct_h -> h_msg_line_no));
	CO_Rtv_DataString(p_param_data,"MSG_TAG",p_dl_hismsglinkdet_struct_h -> h_msg_tag);
}






int Populate_DL_HISMULT_REAS_CODES(DL_HISMULT_REAS_CODES_STRUCT_H *p_dl_hismult_reas_codes_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_dl_hismult_reas_codes_struct_h -> h_closing_date);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hismult_reas_codes_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hismult_reas_codes_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"STAT_BLCKNO",(int *) &(p_dl_hismult_reas_codes_struct_h -> h_stat_blckno));
	CO_Rtv_DataString(p_param_data,"STAT_QUAL",p_dl_hismult_reas_codes_struct_h -> h_stat_qual);
	CO_Rtv_DataString(p_param_data,"STATUS_CD",p_dl_hismult_reas_codes_struct_h -> h_status_cd);
	CO_Rtv_DataString(p_param_data,"REASON_QL",p_dl_hismult_reas_codes_struct_h -> h_reason_ql);
	CO_Rtv_DataString(p_param_data,"REASON_CD",p_dl_hismult_reas_codes_struct_h -> h_reason_cd);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_hismult_reas_codes_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_hismult_reas_codes_struct_h -> h_failreason_cd);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_hismult_reas_codes_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_hismult_reas_codes_struct_h -> h_access_stamp);
}






int Populate_DL_HISREGDET(DL_HISREGDET_STRUCT_H *p_dl_hisregdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hisregdet_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hisregdet_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_hisregdet_struct_h -> h_srl_no));
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_hisregdet_struct_h -> h_reg_st_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DT",p_dl_hisregdet_struct_h -> h_deal_dt);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY",&(p_dl_hisregdet_struct_h -> h_quantity));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_hisregdet_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"MOVED_QTY",&(p_dl_hisregdet_struct_h -> h_moved_qty));
	CO_Rtv_DataDbl(p_param_data,"MANIFOLD_QTY",&(p_dl_hisregdet_struct_h -> h_manifold_qty));
	CO_Rtv_DataString(p_param_data,"DT_CLIENT_FOR",p_dl_hisregdet_struct_h -> h_dt_client_for);
	CO_Rtv_DataString(p_param_data,"PRC_SMR_DATE",p_dl_hisregdet_struct_h -> h_prc_smr_date);
	CO_Rtv_DataString(p_param_data,"STATUS_PRC",p_dl_hisregdet_struct_h -> h_status_prc);
	CO_Rtv_DataString(p_param_data,"PRC_SETL_DATE",p_dl_hisregdet_struct_h -> h_prc_setl_date);
	CO_Rtv_DataDbl(p_param_data,"AMR_AMOUNT",&(p_dl_hisregdet_struct_h -> h_amr_amount));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_hisregdet_struct_h -> h_dateof_input);
}






int Populate_DL_HISREGPAR(DL_HISREGPAR_STRUCT_H *p_dl_hisregpar_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hisregpar_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_hisregpar_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_hisregpar_struct_h -> h_srl_no));
	CO_Rtv_DataInt(p_param_data,"PARENT_SRLNO",(int *) &(p_dl_hisregpar_struct_h -> h_parent_srlno));
	CO_Rtv_DataDbl(p_param_data,"PARENT_QTY",&(p_dl_hisregpar_struct_h -> h_parent_qty));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_hisregpar_struct_h -> h_dateof_input);
}




/*

int Populate_DL_HISREPIRE_VEW(DL_HISREPIRE_VEW_STRUCT_H *p_dl_hisrepire_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
}
*/





int Populate_DL_HISSAFEK(DL_HISSAFEK_STRUCT_H *p_dl_hissafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_hissafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"POSIT_DATE",p_dl_hissafek_struct_h -> h_posit_date);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_hissafek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_hissafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_hissafek_struct_h -> h_status_pos);
	CO_Rtv_DataDbl(p_param_data,"START_SAFEK",&(p_dl_hissafek_struct_h -> h_start_safek));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_hissafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"NVALRECEIVE",&(p_dl_hissafek_struct_h -> h_nvalreceive));
	CO_Rtv_DataDbl(p_param_data,"NVALDELIVER",&(p_dl_hissafek_struct_h -> h_nvaldeliver));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_hissafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_hissafek_struct_h -> h_val_del));
}






int Populate_DL_INSTRUMENTCHG(DL_INSTRUMENTCHG_STRUCT_H *p_dl_instrumentchg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"OLD_INSTR_CODE",p_dl_instrumentchg_struct_h -> h_old_instr_code);
	CO_Rtv_DataString(p_param_data,"NEW_SECCD",p_dl_instrumentchg_struct_h -> h_new_seccd);
	CO_Rtv_DataString(p_param_data,"FRM_DATE",p_dl_instrumentchg_struct_h -> h_frm_date);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_instrumentchg_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_instrumentchg_struct_h -> h_checker);
}






int Populate_DL_INSTRUMENTCONV(DL_INSTRUMENTCONV_STRUCT_H *p_dl_instrumentconv_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"FRM_INSTR_CODE",p_dl_instrumentconv_struct_h -> h_frm_instr_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_instrumentconv_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"TO_SECURITY",p_dl_instrumentconv_struct_h -> h_to_security);
	CO_Rtv_DataString(p_param_data,"CHNG_DT",p_dl_instrumentconv_struct_h -> h_chng_dt);
}






int Populate_DL_INSTRUMENTCONV_REP_TEMP(DL_INSTRUMENTCONV_REP_TEMP_STRUCT_H *p_dl_instrumentconv_rep_temp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_instrumentconv_rep_temp_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_instrumentconv_rep_temp_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DEAL_TYPE",p_dl_instrumentconv_rep_temp_struct_h -> h_deal_type);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_instrumentconv_rep_temp_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_instrumentconv_rep_temp_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_instrumentconv_rep_temp_struct_h -> h_qty));
}






int Populate_DL_INSTRUMENTCONV_TEMP(DL_INSTRUMENTCONV_TEMP_STRUCT_H *p_dl_instrumentconv_temp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_instrumentconv_temp_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_instrumentconv_temp_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_instrumentconv_temp_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_dl_instrumentconv_temp_struct_h -> h_ord_refno);
}






int Populate_DL_IPOAUDIT(DL_IPOAUDIT_STRUCT_H *p_dl_ipoaudit_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NAMEOF_FILE",p_dl_ipoaudit_struct_h -> h_nameof_file);
	CO_Rtv_DataInt(p_param_data,"SRLNUM",(int *) &(p_dl_ipoaudit_struct_h -> h_srlnum));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ipoaudit_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_ipoaudit_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_dl_ipoaudit_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"UPLDDATE",p_dl_ipoaudit_struct_h -> h_uplddate);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_ipoaudit_struct_h -> h_info);
}






int Populate_DL_LOCALREPCLIENT(DL_LOCALREPCLIENT_STRUCT_H *p_dl_localrepclient_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CREDIT_CLT",p_dl_localrepclient_struct_h -> h_credit_clt);
	CO_Rtv_DataString(p_param_data,"LR_DET",p_dl_localrepclient_struct_h -> h_lr_det);
	CO_Rtv_DataString(p_param_data,"CLT_TYPE",p_dl_localrepclient_struct_h -> h_clt_type);
	CO_Rtv_DataString(p_param_data,"CLIENT_OWN",p_dl_localrepclient_struct_h -> h_client_own);
	CO_Rtv_DataString(p_param_data,"FLAG",p_dl_localrepclient_struct_h -> h_flag);
	CO_Rtv_DataString(p_param_data,"OWN_IND",p_dl_localrepclient_struct_h -> h_own_ind);
}






int Populate_DL_LOCALREPCLIENTMA(DL_LOCALREPCLIENTMA_STRUCT_H *p_dl_localrepclientma_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CREDIT_CLT",p_dl_localrepclientma_struct_h -> h_credit_clt);
	CO_Rtv_DataString(p_param_data,"LR_DET",p_dl_localrepclientma_struct_h -> h_lr_det);
	CO_Rtv_DataString(p_param_data,"CLT_TYPE",p_dl_localrepclientma_struct_h -> h_clt_type);
	CO_Rtv_DataString(p_param_data,"CLIENT_OWN",p_dl_localrepclientma_struct_h -> h_client_own);
	CO_Rtv_DataString(p_param_data,"FLAG",p_dl_localrepclientma_struct_h -> h_flag);
	CO_Rtv_DataString(p_param_data,"OWN_IND",p_dl_localrepclientma_struct_h -> h_own_ind);
}






int Populate_DL_LOCALREPDATES(DL_LOCALREPDATES_STRUCT_H *p_dl_localrepdates_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"CLR_NAME",(int *) &(p_dl_localrepdates_struct_h -> h_clr_name));
	CO_Rtv_DataString(p_param_data,"LR_DT",p_dl_localrepdates_struct_h -> h_lr_dt);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_localrepdates_struct_h -> h_info);
}






int Populate_DL_LOCALREPDEALTYPE(DL_LOCALREPDEALTYPE_STRUCT_H *p_dl_localrepdealtype_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEAL_CLASS",p_dl_localrepdealtype_struct_h -> h_deal_class);
	CO_Rtv_DataString(p_param_data,"DEAL_DET",p_dl_localrepdealtype_struct_h -> h_deal_det);
	CO_Rtv_DataString(p_param_data,"NDS_BLK",p_dl_localrepdealtype_struct_h -> h_nds_blk);
	CO_Rtv_DataString(p_param_data,"NDS_IND",p_dl_localrepdealtype_struct_h -> h_nds_ind);
	CO_Rtv_DataString(p_param_data,"DEAL_CD_MTX",p_dl_localrepdealtype_struct_h -> h_deal_cd_mtx);
	CO_Rtv_DataString(p_param_data,"CLTTYPE",p_dl_localrepdealtype_struct_h -> h_clttype);
	CO_Rtv_DataString(p_param_data,"BLOCK",p_dl_localrepdealtype_struct_h -> h_block);
	CO_Rtv_DataString(p_param_data,"NEW",p_dl_localrepdealtype_struct_h -> h_new);
	CO_Rtv_DataString(p_param_data,"CLT_BRK_ALL",p_dl_localrepdealtype_struct_h -> h_clt_brk_all);
	CO_Rtv_DataString(p_param_data,"DEAL_CLASS_CD",p_dl_localrepdealtype_struct_h -> h_deal_class_cd);
}






int Populate_DL_LOCALREPPROC(DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_localrepproc_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_localrepproc_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localrepproc_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDITCLIENT",p_dl_localrepproc_struct_h -> h_creditclient);
	CO_Rtv_DataString(p_param_data,"DEBIT_CLT",p_dl_localrepproc_struct_h -> h_debit_clt);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localrepproc_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_localrepproc_struct_h -> h_qty));
	CO_Rtv_DataInt(p_param_data,"DT_FIELD",(int *) &(p_dl_localrepproc_struct_h -> h_dt_field));
	CO_Rtv_DataInt(p_param_data,"R_CODE",(int *) &(p_dl_localrepproc_struct_h -> h_r_code));
	CO_Rtv_DataString(p_param_data,"ORD_IND",p_dl_localrepproc_struct_h -> h_ord_ind);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_localrepproc_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_localrepproc_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"RESET_IND",p_dl_localrepproc_struct_h -> h_reset_ind);
}






int Populate_DL_LOCALREPPROC2(DL_LOCALREPPROC2_STRUCT_H *p_dl_localrepproc2_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localrepproc2_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDITCLIENT",p_dl_localrepproc2_struct_h -> h_creditclient);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_localrepproc2_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_localrepproc2_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localrepproc2_struct_h -> h_domestic_cpclt);
}






int Populate_DL_LOCALREPPROC3(DL_LOCALREPPROC3_STRUCT_H *p_dl_localrepproc3_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localrepproc3_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDITCLIENT",p_dl_localrepproc3_struct_h -> h_creditclient);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_localrepproc3_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localrepproc3_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_dl_localrepproc3_struct_h -> h_instr_isin);
}






int Populate_DL_LOCALREPROCMA(DL_LOCALREPROCMA_STRUCT_H *p_dl_localreprocma_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_localreprocma_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_localreprocma_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localreprocma_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDITCLIENT",p_dl_localreprocma_struct_h -> h_creditclient);
	CO_Rtv_DataString(p_param_data,"DEBIT_CLT",p_dl_localreprocma_struct_h -> h_debit_clt);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localreprocma_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_localreprocma_struct_h -> h_qty));
	CO_Rtv_DataInt(p_param_data,"DT_FIELD",(int *) &(p_dl_localreprocma_struct_h -> h_dt_field));
	CO_Rtv_DataInt(p_param_data,"R_CODE",(int *) &(p_dl_localreprocma_struct_h -> h_r_code));
	CO_Rtv_DataString(p_param_data,"ORD_IND",p_dl_localreprocma_struct_h -> h_ord_ind);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_localreprocma_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_localreprocma_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"RESET_IND",p_dl_localreprocma_struct_h -> h_reset_ind);
}






int Populate_DL_LOCALREPSAFEK(DL_LOCALREPSAFEK_STRUCT_H *p_dl_localrepsafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localrepsafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDIT_CLT",p_dl_localrepsafek_struct_h -> h_credit_clt);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_localrepsafek_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"OPENBALANCE",&(p_dl_localrepsafek_struct_h -> h_openbalance));
	CO_Rtv_DataDbl(p_param_data,"CLOSING_BAL",&(p_dl_localrepsafek_struct_h -> h_closing_bal));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localrepsafek_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"LAST_INSTR_DATE",p_dl_localrepsafek_struct_h -> h_last_instr_date);
}






int Populate_DL_LOCALREPSAFEKMA(DL_LOCALREPSAFEKMA_STRUCT_H *p_dl_localrepsafekma_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_localrepsafekma_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CREDIT_CLT",p_dl_localrepsafekma_struct_h -> h_credit_clt);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_localrepsafekma_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"OPENBALANCE",&(p_dl_localrepsafekma_struct_h -> h_openbalance));
	CO_Rtv_DataDbl(p_param_data,"CLOSING_BAL",&(p_dl_localrepsafekma_struct_h -> h_closing_bal));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_localrepsafekma_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"LAST_INSTR_DATE",p_dl_localrepsafekma_struct_h -> h_last_instr_date);
}






int Populate_DL_LOCALREPSPEC(DL_LOCALREPSPEC_STRUCT_H *p_dl_localrepspec_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEALCLASS",p_dl_localrepspec_struct_h -> h_dealclass);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_localrepspec_struct_h -> h_deal_cd);
	CO_Rtv_DataInt(p_param_data,"DT_FIELD",(int *) &(p_dl_localrepspec_struct_h -> h_dt_field));
	CO_Rtv_DataString(p_param_data,"STATUS_ACTIVE",p_dl_localrepspec_struct_h -> h_status_active);
	CO_Rtv_DataString(p_param_data,"DT_NAME",p_dl_localrepspec_struct_h -> h_dt_name);
	CO_Rtv_DataString(p_param_data,"IND_NAME",p_dl_localrepspec_struct_h -> h_ind_name);
	CO_Rtv_DataString(p_param_data,"DEBIT_IND",p_dl_localrepspec_struct_h -> h_debit_ind);
	CO_Rtv_DataString(p_param_data,"DEBIT_IND_100",p_dl_localrepspec_struct_h -> h_debit_ind_100);
	CO_Rtv_DataString(p_param_data,"CREDIT_IND",p_dl_localrepspec_struct_h -> h_credit_ind);
	CO_Rtv_DataString(p_param_data,"CREDIT_IND_100",p_dl_localrepspec_struct_h -> h_credit_ind_100);
	CO_Rtv_DataString(p_param_data,"DET",p_dl_localrepspec_struct_h -> h_det);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_localrepspec_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"COND",p_dl_localrepspec_struct_h -> h_cond);
	CO_Rtv_DataString(p_param_data,"LCL_CONDITION",p_dl_localrepspec_struct_h -> h_lcl_condition);
	CO_Rtv_DataString(p_param_data,"DESC_A",p_dl_localrepspec_struct_h -> h_desc_a);
	CO_Rtv_DataString(p_param_data,"DESC_B",p_dl_localrepspec_struct_h -> h_desc_b);
}






int Populate_DL_LOCALREPSPECMA(DL_LOCALREPSPECMA_STRUCT_H *p_dl_localrepspecma_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEALCLASS",p_dl_localrepspecma_struct_h -> h_dealclass);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_localrepspecma_struct_h -> h_deal_cd);
	CO_Rtv_DataInt(p_param_data,"DT_FIELD",(int *) &(p_dl_localrepspecma_struct_h -> h_dt_field));
	CO_Rtv_DataString(p_param_data,"STATUS_ACTIVE",p_dl_localrepspecma_struct_h -> h_status_active);
	CO_Rtv_DataString(p_param_data,"DT_NAME",p_dl_localrepspecma_struct_h -> h_dt_name);
	CO_Rtv_DataString(p_param_data,"IND_NAME",p_dl_localrepspecma_struct_h -> h_ind_name);
	CO_Rtv_DataString(p_param_data,"DEBIT_IND",p_dl_localrepspecma_struct_h -> h_debit_ind);
	CO_Rtv_DataString(p_param_data,"DEBIT_IND_100",p_dl_localrepspecma_struct_h -> h_debit_ind_100);
	CO_Rtv_DataString(p_param_data,"CREDIT_IND",p_dl_localrepspecma_struct_h -> h_credit_ind);
	CO_Rtv_DataString(p_param_data,"CREDIT_IND_100",p_dl_localrepspecma_struct_h -> h_credit_ind_100);
	CO_Rtv_DataString(p_param_data,"DET",p_dl_localrepspecma_struct_h -> h_det);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_localrepspecma_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"COND",p_dl_localrepspecma_struct_h -> h_cond);
	CO_Rtv_DataString(p_param_data,"LCL_CONDITION",p_dl_localrepspecma_struct_h -> h_lcl_condition);
	CO_Rtv_DataString(p_param_data,"DESC_A",p_dl_localrepspecma_struct_h -> h_desc_a);
	CO_Rtv_DataString(p_param_data,"DESC_B",p_dl_localrepspecma_struct_h -> h_desc_b);
}






int Populate_DL_LOCNCHG(DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_locnchg_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDEN_NO",p_dl_locnchg_struct_h -> h_iden_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_locnchg_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_locnchg_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_locnchg_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"DETAILS",p_dl_locnchg_struct_h -> h_details);
	CO_Rtv_DataString(p_param_data,"FRM_LOC",p_dl_locnchg_struct_h -> h_frm_loc);
	CO_Rtv_DataString(p_param_data,"TO_LOCATION",p_dl_locnchg_struct_h -> h_to_location);
	CO_Rtv_DataString(p_param_data,"SENDMSG_IND",p_dl_locnchg_struct_h -> h_sendmsg_ind);
	CO_Rtv_DataString(p_param_data,"BILLABLE_IND",p_dl_locnchg_struct_h -> h_billable_ind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_locnchg_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_locnchg_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_locnchg_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_locnchg_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_locnchg_struct_h -> h_dateof_input);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_locnchg_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DF_TXNR_IDEN",p_dl_locnchg_struct_h -> h_df_txnr_iden);
	CO_Rtv_DataString(p_param_data,"RF_DL_IDENT",p_dl_locnchg_struct_h -> h_rf_dl_ident);
	CO_Rtv_DataString(p_param_data,"DEALSTAT",p_dl_locnchg_struct_h -> h_dealstat);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_STAT",p_dl_locnchg_struct_h -> h_loc_chng_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_locnchg_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"SETL",p_dl_locnchg_struct_h -> h_setl);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_locnchg_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataString(p_param_data,"DF_SETLDATE",p_dl_locnchg_struct_h -> h_df_setldate);
	CO_Rtv_DataString(p_param_data,"RF_SETL_DATE",p_dl_locnchg_struct_h -> h_rf_setl_date);
}






int Populate_DL_MAROCLEAR(DL_MAROCLEAR_STRUCT_H *p_dl_maroclear_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"TEMP1",p_dl_maroclear_struct_h -> h_temp1);
	CO_Rtv_DataString(p_param_data,"TEMP2",p_dl_maroclear_struct_h -> h_temp2);
	CO_Rtv_DataString(p_param_data,"TEMP3",p_dl_maroclear_struct_h -> h_temp3);
	CO_Rtv_DataString(p_param_data,"TEMP4",p_dl_maroclear_struct_h -> h_temp4);
	CO_Rtv_DataString(p_param_data,"TEMP5",p_dl_maroclear_struct_h -> h_temp5);
	CO_Rtv_DataString(p_param_data,"TEMP6",p_dl_maroclear_struct_h -> h_temp6);
	CO_Rtv_DataString(p_param_data,"TEMP7",p_dl_maroclear_struct_h -> h_temp7);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_maroclear_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"BROKERCOMM",(int *) &(p_dl_maroclear_struct_h -> h_brokercomm));
	CO_Rtv_DataString(p_param_data,"BROKER_IDENTITY",p_dl_maroclear_struct_h -> h_broker_identity);
	CO_Rtv_DataInt(p_param_data,"GROSS_AMOUNT",(int *) &(p_dl_maroclear_struct_h -> h_gross_amount));
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_dl_maroclear_struct_h -> h_instr_isin);
	CO_Rtv_DataInt(p_param_data,"NET_AMOUNT",(int *) &(p_dl_maroclear_struct_h -> h_net_amount));
	CO_Rtv_DataInt(p_param_data,"COST",(int *) &(p_dl_maroclear_struct_h -> h_cost));
	CO_Rtv_DataInt(p_param_data,"QTY",(int *) &(p_dl_maroclear_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"REC_DEL",p_dl_maroclear_struct_h -> h_rec_del);
	CO_Rtv_DataString(p_param_data,"MCL_REF",p_dl_maroclear_struct_h -> h_mcl_ref);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_maroclear_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"UPLOAD_DATE",p_dl_maroclear_struct_h -> h_upload_date);
	CO_Rtv_DataInt(p_param_data,"ERROR_CD",(int *) &(p_dl_maroclear_struct_h -> h_error_cd));
}






int Populate_DL_MISDEAL(DL_MISDEAL_STRUCT_H *p_dl_misdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_misdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_misdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_misdeal_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_misdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_misdeal_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_misdeal_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_misdeal_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_misdeal_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_misdeal_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_misdeal_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_misdeal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_misdeal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_misdeal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_misdeal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_misdeal_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"MIS_DL_STAT",p_dl_misdeal_struct_h -> h_mis_dl_stat);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_misdeal_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_misdeal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_misdeal_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"PLACEOF_DEAL",p_dl_misdeal_struct_h -> h_placeof_deal);
	CO_Rtv_DataString(p_param_data,"MRKT_IND",p_dl_misdeal_struct_h -> h_mrkt_ind);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_misdeal_struct_h -> h_narrative);
	CO_Rtv_DataString(p_param_data,"DEALDT",p_dl_misdeal_struct_h -> h_dealdt);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_misdeal_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_misdeal_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_misdeal_struct_h -> h_instruct_person);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_misdeal_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"DEAL_CLS",p_dl_misdeal_struct_h -> h_deal_cls);
	CO_Rtv_DataString(p_param_data,"DEAL_RF_IDENT",p_dl_misdeal_struct_h -> h_deal_rf_ident);
	CO_Rtv_DataString(p_param_data,"COMMIDENT",p_dl_misdeal_struct_h -> h_commident);
	CO_Rtv_DataString(p_param_data,"POOL_REF",p_dl_misdeal_struct_h -> h_pool_ref);
	CO_Rtv_DataString(p_param_data,"SEND_MSG_IND",p_dl_misdeal_struct_h -> h_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"PARTY_CON",p_dl_misdeal_struct_h -> h_party_con);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_misdeal_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"PROC_NUM",(int *) &(p_dl_misdeal_struct_h -> h_proc_num));
	CO_Rtv_DataString(p_param_data,"NAMEOF_FILE",p_dl_misdeal_struct_h -> h_nameof_file);
	CO_Rtv_DataString(p_param_data,"DSN_REFCD",p_dl_misdeal_struct_h -> h_dsn_refcd);
}






int Populate_DL_MSGLINK(DL_MSGLINK_STRUCT_H *p_dl_msglink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_msglink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_msglink_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_msglink_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_msglink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_msglink_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_msglink_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_msglink_struct_h -> h_inden_num));
	CO_Rtv_DataInt(p_param_data,"DL_REP_IDENTNO",(int *) &(p_dl_msglink_struct_h -> h_dl_rep_identno));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_msglink_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_msglink_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_msglink_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_msglink_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_msglink_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"PSETPARTY",p_dl_msglink_struct_h -> h_psetparty);
	CO_Rtv_DataString(p_param_data,"PLACE_CD",p_dl_msglink_struct_h -> h_place_cd);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_msglink_struct_h -> h_narrative);
}






int Populate_DL_MSGLINKDET(DL_MSGLINKDET_STRUCT_H *p_dl_msglinkdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_msglinkdet_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"SEQUENCE_NAME",p_dl_msglinkdet_struct_h -> h_sequence_name);
	CO_Rtv_DataString(p_param_data,"LINK_VAL",p_dl_msglinkdet_struct_h -> h_link_val);
	CO_Rtv_DataString(p_param_data,"LINK_TAG",p_dl_msglinkdet_struct_h -> h_link_tag);
	CO_Rtv_DataInt(p_param_data,"MSG_TAG_REP_NO",(int *) &(p_dl_msglinkdet_struct_h -> h_msg_tag_rep_no));
	CO_Rtv_DataInt(p_param_data,"MSG_LINE_NO",(int *) &(p_dl_msglinkdet_struct_h -> h_msg_line_no));
	CO_Rtv_DataString(p_param_data,"MSG_TAG",p_dl_msglinkdet_struct_h -> h_msg_tag);
}






int Populate_DL_MSGLINK_INC536_VEW(DL_MSGLINK_INC536_VEW_STRUCT_H *p_dl_msglink_inc536_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_msglink_inc536_vew_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_msglink_inc536_vew_struct_h -> h_information);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_msglink_inc536_vew_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_msglink_inc536_vew_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_msglink_inc536_vew_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_msglink_inc536_vew_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_msglink_inc536_vew_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_msglink_inc536_vew_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_msglink_inc536_vew_struct_h -> h_message_det_e);
}






int Populate_DL_MULT_REAS_CODES(DL_MULT_REAS_CODES_STRUCT_H *p_dl_mult_reas_codes_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_mult_reas_codes_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_mult_reas_codes_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"STAT_BLCKNO",(int *) &(p_dl_mult_reas_codes_struct_h -> h_stat_blckno));
	CO_Rtv_DataString(p_param_data,"STAT_QUAL",p_dl_mult_reas_codes_struct_h -> h_stat_qual);
	CO_Rtv_DataString(p_param_data,"STATUS_CD",p_dl_mult_reas_codes_struct_h -> h_status_cd);
	CO_Rtv_DataString(p_param_data,"REASON_QL",p_dl_mult_reas_codes_struct_h -> h_reason_ql);
	CO_Rtv_DataString(p_param_data,"REASON_CD",p_dl_mult_reas_codes_struct_h -> h_reason_cd);
	CO_Rtv_DataString(p_param_data,"INFO",p_dl_mult_reas_codes_struct_h -> h_info);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_mult_reas_codes_struct_h -> h_failreason_cd);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_mult_reas_codes_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_mult_reas_codes_struct_h -> h_access_stamp);
}






int Populate_DL_NOTES_VEW(DL_NOTES_VEW_STRUCT_H *p_dl_notes_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_notes_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_notes_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_notes_vew_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"INFO2",p_dl_notes_vew_struct_h -> h_info2);
	CO_Rtv_DataString(p_param_data,"INFO3",p_dl_notes_vew_struct_h -> h_info3);
	CO_Rtv_DataString(p_param_data,"INFO4",p_dl_notes_vew_struct_h -> h_info4);
}






int Populate_DL_PAST_VDP_VEW(DL_PAST_VDP_VEW_STRUCT_H *p_dl_past_vdp_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_past_vdp_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_past_vdp_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_past_vdp_vew_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_past_vdp_vew_struct_h -> h_status_pos);
	CO_Rtv_DataInt(p_param_data,"STAT_CONF_POS",(int *) &(p_dl_past_vdp_vew_struct_h -> h_stat_conf_pos));
}





/*
int Populate_DL_PER_PORTFOLIO_VEW(DL_PER_PORTFOLIO_VEW_STRUCT_H *p_dl_per_portfolio_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
}
*/





int Populate_DL_PREV_EOM_SAFEK_VEW(DL_PREV_EOM_SAFEK_VEW_STRUCT_H *p_dl_prev_eom_safek_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_prev_eom_safek_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_dl_prev_eom_safek_vew_struct_h -> h_b_ccycd);
	CO_Rtv_DataString(p_param_data,"FEES_CCY",p_dl_prev_eom_safek_vew_struct_h -> h_fees_ccy);
	CO_Rtv_DataString(p_param_data,"SEND_TO_MASTER_IND",p_dl_prev_eom_safek_vew_struct_h -> h_send_to_master_ind);
	CO_Rtv_DataString(p_param_data,"B_GEN_IND",p_dl_prev_eom_safek_vew_struct_h -> h_b_gen_ind);
	CO_Rtv_DataDbl(p_param_data,"BC_MINIMUMFEE",&(p_dl_prev_eom_safek_vew_struct_h -> h_bc_minimumfee));
	CO_Rtv_DataString(p_param_data,"MINIMUMFEE_TO",p_dl_prev_eom_safek_vew_struct_h -> h_minimumfee_to);
	CO_Rtv_DataString(p_param_data,"MIN_HLD_ADJ",p_dl_prev_eom_safek_vew_struct_h -> h_min_hld_adj);
	CO_Rtv_DataString(p_param_data,"DIR_DB_IND",p_dl_prev_eom_safek_vew_struct_h -> h_dir_db_ind);
	CO_Rtv_DataString(p_param_data,"SPL_CLT_CD",p_dl_prev_eom_safek_vew_struct_h -> h_spl_clt_cd);
	CO_Rtv_DataString(p_param_data,"COMM_CLT",p_dl_prev_eom_safek_vew_struct_h -> h_comm_clt);
	CO_Rtv_DataString(p_param_data,"REC_CLT",p_dl_prev_eom_safek_vew_struct_h -> h_rec_clt);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_prev_eom_safek_vew_struct_h -> h_information);
	CO_Rtv_DataString(p_param_data,"DEFAULT_FEECLT",p_dl_prev_eom_safek_vew_struct_h -> h_default_feeclt);
	CO_Rtv_DataDbl(p_param_data,"TOTAL_OSAMOUNT",&(p_dl_prev_eom_safek_vew_struct_h -> h_total_osamount));
	CO_Rtv_DataDbl(p_param_data,"COMM_TAX_AMT",&(p_dl_prev_eom_safek_vew_struct_h -> h_comm_tax_amt));
	CO_Rtv_DataString(p_param_data,"CA_IDENTNAME",p_dl_prev_eom_safek_vew_struct_h -> h_ca_identname);
	CO_Rtv_DataString(p_param_data,"CURRENT_DATE",p_dl_prev_eom_safek_vew_struct_h -> h_current_date);
	CO_Rtv_DataInt(p_param_data,"BS_SERVICE_CD",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_bs_service_cd));
	CO_Rtv_DataString(p_param_data,"FEES_BASE",p_dl_prev_eom_safek_vew_struct_h -> h_fees_base);
	CO_Rtv_DataString(p_param_data,"CHRG_BASE",p_dl_prev_eom_safek_vew_struct_h -> h_chrg_base);
	CO_Rtv_DataString(p_param_data,"CHRG_CLAS",p_dl_prev_eom_safek_vew_struct_h -> h_chrg_clas);
	CO_Rtv_DataString(p_param_data,"FEES_CLASS",p_dl_prev_eom_safek_vew_struct_h -> h_fees_class);
	CO_Rtv_DataDbl(p_param_data,"MINIMUMFEE",&(p_dl_prev_eom_safek_vew_struct_h -> h_minimumfee));
	CO_Rtv_DataDbl(p_param_data,"NIL_FEES",&(p_dl_prev_eom_safek_vew_struct_h -> h_nil_fees));
	CO_Rtv_DataDbl(p_param_data,"MAXIMUM_FEE",&(p_dl_prev_eom_safek_vew_struct_h -> h_maximum_fee));
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_dl_prev_eom_safek_vew_struct_h -> h_parameter_cd);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_dl_prev_eom_safek_vew_struct_h -> h_proc_data_val);
	CO_Rtv_DataInt(p_param_data,"SCHDL_FEE",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_schdl_fee));
	CO_Rtv_DataInt(p_param_data,"FRM_CBASE",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_frm_cbase));
	CO_Rtv_DataInt(p_param_data,"TOC_BASE",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_toc_base));
	CO_Rtv_DataInt(p_param_data,"FRM_FBASE",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_frm_fbase));
	CO_Rtv_DataInt(p_param_data,"TOF_BASE",(int *) &(p_dl_prev_eom_safek_vew_struct_h -> h_tof_base));
	CO_Rtv_DataString(p_param_data,"SERVICE_DET",p_dl_prev_eom_safek_vew_struct_h -> h_service_det);
}






int Populate_DL_REGCYCLE(DL_REGCYCLE_STRUCT_H *p_dl_regcycle_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION",p_dl_regcycle_struct_h -> h_nation);
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_regcycle_struct_h -> h_reg_st_cd);
	CO_Rtv_DataString(p_param_data,"REG_ST_DESC",p_dl_regcycle_struct_h -> h_reg_st_desc);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_regcycle_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"MOD_DEALPOS",p_dl_regcycle_struct_h -> h_mod_dealpos);
	CO_Rtv_DataString(p_param_data,"REG_AUD_FUN",p_dl_regcycle_struct_h -> h_reg_aud_fun);
	CO_Rtv_DataString(p_param_data,"MAN_STAT",p_dl_regcycle_struct_h -> h_man_stat);
	CO_Rtv_DataString(p_param_data,"REG_SHORT",p_dl_regcycle_struct_h -> h_reg_short);
	CO_Rtv_DataString(p_param_data,"NEW_REG_A",p_dl_regcycle_struct_h -> h_new_reg_a);
	CO_Rtv_DataString(p_param_data,"NEWT_REG_B",p_dl_regcycle_struct_h -> h_newt_reg_b);
	CO_Rtv_DataString(p_param_data,"FLD_UP_DATE",p_dl_regcycle_struct_h -> h_fld_up_date);
	CO_Rtv_DataString(p_param_data,"PREV_REG",p_dl_regcycle_struct_h -> h_prev_reg);
}






int Populate_DL_REGDET(DL_REGDET_STRUCT_H *p_dl_regdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_regdet_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_regdet_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_regdet_struct_h -> h_srl_no));
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_regdet_struct_h -> h_reg_st_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DT",p_dl_regdet_struct_h -> h_deal_dt);
	CO_Rtv_DataDbl(p_param_data,"QUANTITY",&(p_dl_regdet_struct_h -> h_quantity));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_regdet_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"MOVED_QTY",&(p_dl_regdet_struct_h -> h_moved_qty));
	CO_Rtv_DataDbl(p_param_data,"MANIFOLD_QTY",&(p_dl_regdet_struct_h -> h_manifold_qty));
	CO_Rtv_DataString(p_param_data,"DT_CLIENT_FOR",p_dl_regdet_struct_h -> h_dt_client_for);
	CO_Rtv_DataString(p_param_data,"PRC_SMR_DATE",p_dl_regdet_struct_h -> h_prc_smr_date);
	CO_Rtv_DataString(p_param_data,"STATUS_PRC",p_dl_regdet_struct_h -> h_status_prc);
	CO_Rtv_DataString(p_param_data,"PRC_SETL_DATE",p_dl_regdet_struct_h -> h_prc_setl_date);
	CO_Rtv_DataDbl(p_param_data,"AMR_AMOUNT",&(p_dl_regdet_struct_h -> h_amr_amount));
}






int Populate_DL_REGPAR(DL_REGPAR_STRUCT_H *p_dl_regpar_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_regpar_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_regpar_struct_h -> h_identiy_no);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_regpar_struct_h -> h_srl_no));
	CO_Rtv_DataInt(p_param_data,"PARENT_SRLNO",(int *) &(p_dl_regpar_struct_h -> h_parent_srlno));
	CO_Rtv_DataDbl(p_param_data,"PARENT_QTY",&(p_dl_regpar_struct_h -> h_parent_qty));
}






int Populate_DL_REG_STATISTICS_VEW(DL_REG_STATISTICS_VEW_STRUCT_H *p_dl_reg_statistics_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_reg_statistics_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_reg_statistics_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_reg_statistics_vew_struct_h -> h_reg_st_cd);
	CO_Rtv_DataInt(p_param_data,"SRL_NO",(int *) &(p_dl_reg_statistics_vew_struct_h -> h_srl_no));
	CO_Rtv_DataDbl(p_param_data,"QUANTITY",&(p_dl_reg_statistics_vew_struct_h -> h_quantity));
	CO_Rtv_DataString(p_param_data,"TO_DATE",p_dl_reg_statistics_vew_struct_h -> h_to_date);
	CO_Rtv_DataString(p_param_data,"FRM_DATE",p_dl_reg_statistics_vew_struct_h -> h_frm_date);
	CO_Rtv_DataInt(p_param_data,"DATE_DIFF",(int *) &(p_dl_reg_statistics_vew_struct_h -> h_date_diff));
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_reg_statistics_vew_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_reg_statistics_vew_struct_h -> h_instr_code);
}






int Populate_DL_REG_STATUS_VEW(DL_REG_STATUS_VEW_STRUCT_H *p_dl_reg_status_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REG_ST_QTY",(int *) &(p_dl_reg_status_vew_struct_h -> h_reg_st_qty));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_reg_status_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_reg_status_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"REG_ST_CD",p_dl_reg_status_vew_struct_h -> h_reg_st_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_reg_status_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_reg_status_vew_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_reg_status_vew_struct_h -> h_lcl_identno);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_reg_status_vew_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_reg_status_vew_struct_h -> h_last_reg_date);
}





/*
int Populate_DL_REPIRE_VEW(DL_REPIRE_VEW_STRUCT_H *p_dl_repire_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
}
*/





int Populate_DL_RUARCHSAFEK(DL_RUARCHSAFEK_STRUCT_H *p_dl_ruarchsafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"POSIT_DATE",p_dl_ruarchsafek_struct_h -> h_posit_date);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ruarchsafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_ruarchsafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_ruarchsafek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_ruarchsafek_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_ruarchsafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_ruarchsafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_ruarchsafek_struct_h -> h_val_del));
}






int Populate_DL_RUCLIENT(DL_RUCLIENT_STRUCT_H *p_dl_ruclient_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ruclient_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CLIENT_NAME",p_dl_ruclient_struct_h -> h_client_name);
	CO_Rtv_DataString(p_param_data,"SYN_CLIENT",p_dl_ruclient_struct_h -> h_syn_client);
	CO_Rtv_DataString(p_param_data,"CLTTYP",p_dl_ruclient_struct_h -> h_clttyp);
	CO_Rtv_DataString(p_param_data,"CLT_TYP",p_dl_ruclient_struct_h -> h_clt_typ);
	CO_Rtv_DataInt(p_param_data,"BASECLT",(int *) &(p_dl_ruclient_struct_h -> h_baseclt));
	CO_Rtv_DataString(p_param_data,"CLIENT_OPDT",p_dl_ruclient_struct_h -> h_client_opdt);
	CO_Rtv_DataString(p_param_data,"CLIENT_CLOSE_DT",p_dl_ruclient_struct_h -> h_client_close_dt);
	CO_Rtv_DataString(p_param_data,"NOSTR_CLTPID",p_dl_ruclient_struct_h -> h_nostr_cltpid);
	CO_Rtv_DataString(p_param_data,"NOSTR_CLTTYP",p_dl_ruclient_struct_h -> h_nostr_clttyp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_ruclient_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_ruclient_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_ruclient_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_ruclient_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_ruclient_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_ruclient_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"RU_CLIENT_STAT",p_dl_ruclient_struct_h -> h_ru_client_stat);
}






int Populate_DL_RUDEAL(DL_RUDEAL_STRUCT_H *p_dl_rudeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_rudeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_rudeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_rudeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_rudeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_rudeal_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_rudeal_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_rudeal_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_rudeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_rudeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_rudeal_struct_h -> h_instrument_dt);
}






int Populate_DL_RUDEAL_TMP(DL_RUDEAL_TMP_STRUCT_H *p_dl_rudeal_tmp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_rudeal_tmp_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_rudeal_tmp_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_rudeal_tmp_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_rudeal_tmp_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_rudeal_tmp_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_rudeal_tmp_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_rudeal_tmp_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_rudeal_tmp_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_rudeal_tmp_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_rudeal_tmp_struct_h -> h_instrument_dt);
}






int Populate_DL_RUHISDEAL(DL_RUHISDEAL_STRUCT_H *p_dl_ruhisdeal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ruhisdeal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_ruhisdeal_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_ruhisdeal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_ruhisdeal_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_ruhisdeal_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_ruhisdeal_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_ruhisdeal_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_ruhisdeal_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_ruhisdeal_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_ruhisdeal_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_ruhisdeal_struct_h -> h_dateof_input);
}






int Populate_DL_RUHISSAFEK(DL_RUHISSAFEK_STRUCT_H *p_dl_ruhissafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"POSIT_DATE",p_dl_ruhissafek_struct_h -> h_posit_date);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_ruhissafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_ruhissafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_ruhissafek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_ruhissafek_struct_h -> h_st_reg_no);
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_ruhissafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_ruhissafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_ruhissafek_struct_h -> h_val_del));
}






int Populate_DL_RUINSTRUMENT(DL_RUINSTRUMENT_STRUCT_H *p_dl_ruinstrument_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_ruinstrument_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"SEC_NM",p_dl_ruinstrument_struct_h -> h_sec_nm);
	CO_Rtv_DataString(p_param_data,"SNM_IND",p_dl_ruinstrument_struct_h -> h_snm_ind);
	CO_Rtv_DataString(p_param_data,"STAT_REG_NO",p_dl_ruinstrument_struct_h -> h_stat_reg_no);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_OPDT",p_dl_ruinstrument_struct_h -> h_instrument_opdt);
	CO_Rtv_DataString(p_param_data,"SEC_CLDATE",p_dl_ruinstrument_struct_h -> h_sec_cldate);
	CO_Rtv_DataString(p_param_data,"SEC_CLS",p_dl_ruinstrument_struct_h -> h_sec_cls);
	CO_Rtv_DataInt(p_param_data,"BASEINSTRUMENT",(int *) &(p_dl_ruinstrument_struct_h -> h_baseinstrument));
	CO_Rtv_DataString(p_param_data,"TYPEOFINSTR",p_dl_ruinstrument_struct_h -> h_typeofinstr);
	CO_Rtv_DataString(p_param_data,"PR_CODE",p_dl_ruinstrument_struct_h -> h_pr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_ruinstrument_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_ruinstrument_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_ruinstrument_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_ruinstrument_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_ruinstrument_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_ruinstrument_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"RU_INSTR_STAT",p_dl_ruinstrument_struct_h -> h_ru_instr_stat);
}






int Populate_DL_RULOCATION(DL_RULOCATION_STRUCT_H *p_dl_rulocation_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"LOC",p_dl_rulocation_struct_h -> h_loc);
	CO_Rtv_DataString(p_param_data,"LOC_NAME",p_dl_rulocation_struct_h -> h_loc_name);
	CO_Rtv_DataString(p_param_data,"SYN_LOCATION",p_dl_rulocation_struct_h -> h_syn_location);
	CO_Rtv_DataString(p_param_data,"LICENSE_NO",p_dl_rulocation_struct_h -> h_license_no);
	CO_Rtv_DataString(p_param_data,"LOC_TYPE",p_dl_rulocation_struct_h -> h_loc_type);
	CO_Rtv_DataString(p_param_data,"DEPO_CD",p_dl_rulocation_struct_h -> h_depo_cd);
	CO_Rtv_DataInt(p_param_data,"BASELOCATION",(int *) &(p_dl_rulocation_struct_h -> h_baselocation));
	CO_Rtv_DataString(p_param_data,"LOC_OPDATE",p_dl_rulocation_struct_h -> h_loc_opdate);
	CO_Rtv_DataString(p_param_data,"LOC_CLOSE_DT",p_dl_rulocation_struct_h -> h_loc_close_dt);
	CO_Rtv_DataString(p_param_data,"NOSTR_CLTPID",p_dl_rulocation_struct_h -> h_nostr_cltpid);
	CO_Rtv_DataString(p_param_data,"NOSTR_CLTTYP",p_dl_rulocation_struct_h -> h_nostr_clttyp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_rulocation_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_rulocation_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_rulocation_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_rulocation_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_rulocation_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_rulocation_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"RU_LOC_STAT",p_dl_rulocation_struct_h -> h_ru_loc_stat);
}






int Populate_DL_RUPRODUCT(DL_RUPRODUCT_STRUCT_H *p_dl_ruproduct_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PR_CODE",p_dl_ruproduct_struct_h -> h_pr_code);
	CO_Rtv_DataString(p_param_data,"PR_DET",p_dl_ruproduct_struct_h -> h_pr_det);
	CO_Rtv_DataString(p_param_data,"MT_CURRENCY",p_dl_ruproduct_struct_h -> h_mt_currency);
	CO_Rtv_DataString(p_param_data,"DAY_DATE",p_dl_ruproduct_struct_h -> h_day_date);
	CO_Rtv_DataString(p_param_data,"DAY_YEAR",p_dl_ruproduct_struct_h -> h_day_year);
	CO_Rtv_DataString(p_param_data,"PRD_TYPE",p_dl_ruproduct_struct_h -> h_prd_type);
	CO_Rtv_DataString(p_param_data,"INTTYPE",p_dl_ruproduct_struct_h -> h_inttype);
	CO_Rtv_DataString(p_param_data,"LOC",p_dl_ruproduct_struct_h -> h_loc);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_ruproduct_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_ruproduct_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_ruproduct_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_ruproduct_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_ruproduct_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_ruproduct_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"STATUS_PROD",p_dl_ruproduct_struct_h -> h_status_prod);
}






int Populate_DL_RUSAFEK(DL_RUSAFEK_STRUCT_H *p_dl_rusafek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_rusafek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_rusafek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"ST_REG_NO",p_dl_rusafek_struct_h -> h_st_reg_no);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_rusafek_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_rusafek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_rusafek_struct_h -> h_val_del));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_rusafek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataString(p_param_data,"NEW_OLD_IND",p_dl_rusafek_struct_h -> h_new_old_ind);
	CO_Rtv_DataString(p_param_data,"NEW_DT",p_dl_rusafek_struct_h -> h_new_dt);
}






int Populate_DL_RUSRN(DL_RUSRN_STRUCT_H *p_dl_rusrn_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"STAT_REG_NO",p_dl_rusrn_struct_h -> h_stat_reg_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_rusrn_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_dl_rusrn_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NUM",p_dl_rusrn_struct_h -> h_identiy_num);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_rusrn_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_rusrn_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_rusrn_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_rusrn_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_rusrn_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_rusrn_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"SRN_STAT",p_dl_rusrn_struct_h -> h_srn_stat);
}






int Populate_DL_SAFEK(DL_SAFEK_STRUCT_H *p_dl_safek_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_safek_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_safek_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_safek_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_safek_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_safek_struct_h -> h_status_pos);
	CO_Rtv_DataDbl(p_param_data,"START_SAFEK",&(p_dl_safek_struct_h -> h_start_safek));
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_dl_safek_struct_h -> h_safekeep_pos));
	CO_Rtv_DataDbl(p_param_data,"NVALRECEIVE",&(p_dl_safek_struct_h -> h_nvalreceive));
	CO_Rtv_DataDbl(p_param_data,"NVALDELIVER",&(p_dl_safek_struct_h -> h_nvaldeliver));
	CO_Rtv_DataDbl(p_param_data,"VAL_REC",&(p_dl_safek_struct_h -> h_val_rec));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEL",&(p_dl_safek_struct_h -> h_val_del));
}






int Populate_DL_SAFEK_VEW(DL_SAFEK_VEW_STRUCT_H *p_dl_safek_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_safek_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_safek_vew_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_safek_vew_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SAFEKEEP_POS",(int *) &(p_dl_safek_vew_struct_h -> h_safekeep_pos));
}




/*

int Populate_DL_SECTORWISE_HOLD_VEW(DL_SECTORWISE_HOLD_VEW_STRUCT_H *p_dl_sectorwise_hold_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
}
*/





int Populate_DL_SETLRPT(DL_SETLRPT_STRUCT_H *p_dl_setlrpt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_setlrpt_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"NAMEOF_FILE",p_dl_setlrpt_struct_h -> h_nameof_file);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_setlrpt_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_setlrpt_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_RF_IDENT_NO",p_dl_setlrpt_struct_h -> h_deal_rf_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_setlrpt_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_setlrpt_struct_h -> h_amount));
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_setlrpt_struct_h -> h_currency_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_setlrpt_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_setlrpt_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_setlrpt_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MESSAGE_STAT",p_dl_setlrpt_struct_h -> h_message_stat);
	CO_Rtv_DataString(p_param_data,"REJECT_REASON",p_dl_setlrpt_struct_h -> h_reject_reason);
	CO_Rtv_DataString(p_param_data,"REPORT_DT",p_dl_setlrpt_struct_h -> h_report_dt);
	CO_Rtv_DataString(p_param_data,"REPORT_IND",p_dl_setlrpt_struct_h -> h_report_ind);
	CO_Rtv_DataInt(p_param_data,"DEAL_NO",(int *) &(p_dl_setlrpt_struct_h -> h_deal_no));
}






int Populate_DL_SETLRPT_VEW(DL_SETLRPT_VEW_STRUCT_H *p_dl_setlrpt_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_setlrpt_vew_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_setlrpt_vew_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_setlrpt_vew_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_setlrpt_vew_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"DEAL_NO",(int *) &(p_dl_setlrpt_vew_struct_h -> h_deal_no));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_setlrpt_vew_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_setlrpt_vew_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_setlrpt_vew_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_setlrpt_vew_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_setlrpt_vew_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_setlrpt_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_setlrpt_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_RF_IDENT_NO",p_dl_setlrpt_vew_struct_h -> h_deal_rf_ident_no);
	CO_Rtv_DataString(p_param_data,"REJECT_REASON",p_dl_setlrpt_vew_struct_h -> h_reject_reason);
	CO_Rtv_DataString(p_param_data,"REPORT_DT",p_dl_setlrpt_vew_struct_h -> h_report_dt);
	CO_Rtv_DataString(p_param_data,"REPORT_IND",p_dl_setlrpt_vew_struct_h -> h_report_ind);
	CO_Rtv_DataString(p_param_data,"MESSAGE_STAT",p_dl_setlrpt_vew_struct_h -> h_message_stat);
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_dl_setlrpt_vew_struct_h -> h_nation_code);
	CO_Rtv_DataString(p_param_data,"CURRENT_DATE",p_dl_setlrpt_vew_struct_h -> h_current_date);
}






int Populate_DL_SFEREJ(DL_SFEREJ_STRUCT_H *p_dl_sferej_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_sferej_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_sferej_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_sferej_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"NAMEOF_FILE",p_dl_sferej_struct_h -> h_nameof_file);
	CO_Rtv_DataString(p_param_data,"SFE_PROC_DATA",p_dl_sferej_struct_h -> h_sfe_proc_data);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_sferej_struct_h -> h_uniq_ident_no);
}






int Populate_DL_SMI_PENDTXN(DL_SMI_PENDTXN_STRUCT_H *p_dl_smi_pendtxn_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_smi_pendtxn_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_smi_pendtxn_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_smi_pendtxn_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_smi_pendtxn_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_smi_pendtxn_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_smi_pendtxn_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_smi_pendtxn_struct_h -> h_setl_date);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_smi_pendtxn_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_smi_pendtxn_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_smi_pendtxn_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_smi_pendtxn_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_smi_pendtxn_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_smi_pendtxn_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_smi_pendtxn_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_smi_pendtxn_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_smi_pendtxn_struct_h -> h_verfied_with);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_smi_pendtxn_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_smi_pendtxn_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"IN_FAVOUROF",p_dl_smi_pendtxn_struct_h -> h_in_favourof);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_smi_pendtxn_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"NET_SETL_VALUE",&(p_dl_smi_pendtxn_struct_h -> h_net_setl_value));
	CO_Rtv_DataDbl(p_param_data,"GROSS_SETLVALUE",&(p_dl_smi_pendtxn_struct_h -> h_gross_setlvalue));
	CO_Rtv_DataString(p_param_data,"DEAL_STAGE",p_dl_smi_pendtxn_struct_h -> h_deal_stage);
	CO_Rtv_DataString(p_param_data,"SMI_REQUEST_TYPE",p_dl_smi_pendtxn_struct_h -> h_smi_request_type);
	CO_Rtv_DataString(p_param_data,"SMI_REJECT_REASON",p_dl_smi_pendtxn_struct_h -> h_smi_reject_reason);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_smi_pendtxn_struct_h -> h_access_stamp);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_smi_pendtxn_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_smi_pendtxn_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_smi_pendtxn_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_smi_pendtxn_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_smi_pendtxn_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_smi_pendtxn_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_smi_pendtxn_struct_h -> h_val_fdt);
}






int Populate_DL_SMI_TMP_TRADE(DL_SMI_TMP_TRADE_STRUCT_H *p_dl_smi_tmp_trade_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_smi_tmp_trade_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_smi_tmp_trade_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_smi_tmp_trade_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_smi_tmp_trade_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_smi_tmp_trade_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_smi_tmp_trade_struct_h -> h_ex_arena);
	CO_Rtv_DataDbl(p_param_data,"AMOUNT",&(p_dl_smi_tmp_trade_struct_h -> h_amount));
	CO_Rtv_DataDbl(p_param_data,"CUSTODYCOMM",&(p_dl_smi_tmp_trade_struct_h -> h_custodycomm));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_smi_tmp_trade_struct_h -> h_brokercomm));
	CO_Rtv_DataDbl(p_param_data,"STX_COMM",&(p_dl_smi_tmp_trade_struct_h -> h_stx_comm));
	CO_Rtv_DataDbl(p_param_data,"OTH_COMM",&(p_dl_smi_tmp_trade_struct_h -> h_oth_comm));
	CO_Rtv_DataString(p_param_data,"INSTRUMENT_DT",p_dl_smi_tmp_trade_struct_h -> h_instrument_dt);
	CO_Rtv_DataString(p_param_data,"MONEY_SETL_DT",p_dl_smi_tmp_trade_struct_h -> h_money_setl_dt);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_smi_tmp_trade_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_smi_tmp_trade_struct_h -> h_domestic_cpclt);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_smi_tmp_trade_struct_h -> h_spottrd_ind);
	CO_Rtv_DataDbl(p_param_data,"ORIG_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_orig_qty));
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMOUNT",&(p_dl_smi_tmp_trade_struct_h -> h_orig_amount));
	CO_Rtv_DataString(p_param_data,"DEAL_FRM_ORD",p_dl_smi_tmp_trade_struct_h -> h_deal_frm_ord);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_smi_tmp_trade_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REAPIRED_IND",p_dl_smi_tmp_trade_struct_h -> h_reapired_ind);
	CO_Rtv_DataString(p_param_data,"DOMCP_CUSTODYCLT",p_dl_smi_tmp_trade_struct_h -> h_domcp_custodyclt);
	CO_Rtv_DataString(p_param_data,"CP_CLT",p_dl_smi_tmp_trade_struct_h -> h_cp_clt);
	CO_Rtv_DataString(p_param_data,"CP_CLTNAME",p_dl_smi_tmp_trade_struct_h -> h_cp_cltname);
	CO_Rtv_DataString(p_param_data,"CLIENTOF",p_dl_smi_tmp_trade_struct_h -> h_clientof);
	CO_Rtv_DataString(p_param_data,"CLIENT_NOTE",p_dl_smi_tmp_trade_struct_h -> h_client_note);
	CO_Rtv_DataString(p_param_data,"FX_REQD",p_dl_smi_tmp_trade_struct_h -> h_fx_reqd);
	CO_Rtv_DataString(p_param_data,"PAYLOC_IND",p_dl_smi_tmp_trade_struct_h -> h_payloc_ind);
	CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_smi_tmp_trade_struct_h -> h_verfied_with);
	CO_Rtv_DataDbl(p_param_data,"AMT_DIFFER",&(p_dl_smi_tmp_trade_struct_h -> h_amt_differ));
	CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_smi_tmp_trade_struct_h -> h_brk_no);
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_dl_smi_tmp_trade_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAIL_DET",p_dl_smi_tmp_trade_struct_h -> h_fail_det);
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_B",p_dl_smi_tmp_trade_struct_h -> h_partial_ind_b);
	CO_Rtv_DataDbl(p_param_data,"FX_RT",&(p_dl_smi_tmp_trade_struct_h -> h_fx_rt));
	CO_Rtv_DataInt(p_param_data,"AMEND_COUNT",(int *) &(p_dl_smi_tmp_trade_struct_h -> h_amend_count));
	CO_Rtv_DataInt(p_param_data,"NUMBER_A",(int *) &(p_dl_smi_tmp_trade_struct_h -> h_number_a));
	CO_Rtv_DataString(p_param_data,"REPORT_AT_EOM_IND",p_dl_smi_tmp_trade_struct_h -> h_report_at_eom_ind);
	CO_Rtv_DataString(p_param_data,"DATEOFBILLING",p_dl_smi_tmp_trade_struct_h -> h_dateofbilling);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_dl_smi_tmp_trade_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSON",p_dl_smi_tmp_trade_struct_h -> h_instruct_person);
	CO_Rtv_DataDbl(p_param_data,"REC_INT_000",&(p_dl_smi_tmp_trade_struct_h -> h_rec_int_000));
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_smi_tmp_trade_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_smi_tmp_trade_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_smi_tmp_trade_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_smi_tmp_trade_struct_h -> h_dl_class);
	CO_Rtv_DataString(p_param_data,"ORIG_REFNO",p_dl_smi_tmp_trade_struct_h -> h_orig_refno);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_smi_tmp_trade_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_smi_tmp_trade_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_smi_tmp_trade_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_smi_tmp_trade_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_smi_tmp_trade_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_smi_tmp_trade_struct_h -> h_info1);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_smi_tmp_trade_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"REGINSTR_IND",p_dl_smi_tmp_trade_struct_h -> h_reginstr_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_smi_tmp_trade_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"STATUS_REG",p_dl_smi_tmp_trade_struct_h -> h_status_reg);
	CO_Rtv_DataString(p_param_data,"VAL_FDT",p_dl_smi_tmp_trade_struct_h -> h_val_fdt);
	CO_Rtv_DataString(p_param_data,"COMPREFNO",p_dl_smi_tmp_trade_struct_h -> h_comprefno);
	CO_Rtv_DataString(p_param_data,"DATEOF_MARKFAIL",p_dl_smi_tmp_trade_struct_h -> h_dateof_markfail);
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_dl_smi_tmp_trade_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_smi_tmp_trade_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_smi_tmp_trade_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INSTRCONV_IND",p_dl_smi_tmp_trade_struct_h -> h_instrconv_ind);
	CO_Rtv_DataString(p_param_data,"NDS_BLK_DT",p_dl_smi_tmp_trade_struct_h -> h_nds_blk_dt);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_dl_smi_tmp_trade_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"NDS_DATE",p_dl_smi_tmp_trade_struct_h -> h_nds_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_dl_smi_tmp_trade_struct_h -> h_unblk_date);
	CO_Rtv_DataDbl(p_param_data,"DELTA_000",&(p_dl_smi_tmp_trade_struct_h -> h_delta_000));
	CO_Rtv_DataDbl(p_param_data,"DELTA_001",&(p_dl_smi_tmp_trade_struct_h -> h_delta_001));
	CO_Rtv_DataDbl(p_param_data,"DELTA_003",&(p_dl_smi_tmp_trade_struct_h -> h_delta_003));
	CO_Rtv_DataString(p_param_data,"DEL_REC_DATE",p_dl_smi_tmp_trade_struct_h -> h_del_rec_date);
	CO_Rtv_DataString(p_param_data,"LAST_REG_DATE",p_dl_smi_tmp_trade_struct_h -> h_last_reg_date);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_dl_smi_tmp_trade_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_VALDATE",p_dl_smi_tmp_trade_struct_h -> h_lr_valdate);
	CO_Rtv_DataString(p_param_data,"LRINSTR_DATE",p_dl_smi_tmp_trade_struct_h -> h_lrinstr_date);
	CO_Rtv_DataDbl(p_param_data,"REG_MSG_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_reg_msg_qty));
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DT",p_dl_smi_tmp_trade_struct_h -> h_tmp_out_dt);
	CO_Rtv_DataString(p_param_data,"TMP_OUT_DATE",p_dl_smi_tmp_trade_struct_h -> h_tmp_out_date);
	CO_Rtv_DataString(p_param_data,"TRANS_DATE",p_dl_smi_tmp_trade_struct_h -> h_trans_date);
	CO_Rtv_DataDbl(p_param_data,"TOT_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_tot_qty));
	CO_Rtv_DataDbl(p_param_data,"QTY_LOST",&(p_dl_smi_tmp_trade_struct_h -> h_qty_lost));
	CO_Rtv_DataDbl(p_param_data,"MRK_DL_FAILQTY",&(p_dl_smi_tmp_trade_struct_h -> h_mrk_dl_failqty));
	CO_Rtv_DataDbl(p_param_data,"DL_COMPLETEQTY",&(p_dl_smi_tmp_trade_struct_h -> h_dl_completeqty));
	CO_Rtv_DataDbl(p_param_data,"OUT_REG_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_out_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"PEND_REG_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_pend_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"RET_REG_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_ret_reg_qty));
	CO_Rtv_DataDbl(p_param_data,"STAMP_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_stamp_qty));
	CO_Rtv_DataDbl(p_param_data,"TEMP_OUT_QUANTITY",&(p_dl_smi_tmp_trade_struct_h -> h_temp_out_quantity));
	CO_Rtv_DataDbl(p_param_data,"TEMP_RET_QUANTITY",&(p_dl_smi_tmp_trade_struct_h -> h_temp_ret_quantity));
	CO_Rtv_DataDbl(p_param_data,"VAL_DEED_QTY",&(p_dl_smi_tmp_trade_struct_h -> h_val_deed_qty));
	CO_Rtv_DataString(p_param_data,"HOST_DATE",p_dl_smi_tmp_trade_struct_h -> h_host_date);
	CO_Rtv_DataString(p_param_data,"LRNDS_BILLDT",p_dl_smi_tmp_trade_struct_h -> h_lrnds_billdt);
	CO_Rtv_DataString(p_param_data,"LRNDS_DATE",p_dl_smi_tmp_trade_struct_h -> h_lrnds_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_dl_smi_tmp_trade_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataInt(p_param_data,"NUMBER_B",(int *) &(p_dl_smi_tmp_trade_struct_h -> h_number_b));
	CO_Rtv_DataString(p_param_data,"CLT_REQDEL_IND",p_dl_smi_tmp_trade_struct_h -> h_clt_reqdel_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_IND",p_dl_smi_tmp_trade_struct_h -> h_mod_hispos_ind);
	CO_Rtv_DataString(p_param_data,"MOD_HISPOS_DATE",p_dl_smi_tmp_trade_struct_h -> h_mod_hispos_date);
	CO_Rtv_DataString(p_param_data,"GL_CLIENT",p_dl_smi_tmp_trade_struct_h -> h_gl_client);
	CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_smi_tmp_trade_struct_h -> h_cp_amt));
	CO_Rtv_DataString(p_param_data,"MSG_STAT",p_dl_smi_tmp_trade_struct_h -> h_msg_stat);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_dl_smi_tmp_trade_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"PARTIAL_IND_A",p_dl_smi_tmp_trade_struct_h -> h_partial_ind_a);
	CO_Rtv_DataString(p_param_data,"LOC_CHNG_IND",p_dl_smi_tmp_trade_struct_h -> h_loc_chng_ind);
	CO_Rtv_DataString(p_param_data,"COMM_IDENT_NO",p_dl_smi_tmp_trade_struct_h -> h_comm_ident_no);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_PERSONNM",p_dl_smi_tmp_trade_struct_h -> h_instruct_personnm);
	CO_Rtv_DataString(p_param_data,"CLIENTOF_CD",p_dl_smi_tmp_trade_struct_h -> h_clientof_cd);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSON",p_dl_smi_tmp_trade_struct_h -> h_inter_med_person);
	CO_Rtv_DataString(p_param_data,"INTER_MED_PERSONNM",p_dl_smi_tmp_trade_struct_h -> h_inter_med_personnm);
	CO_Rtv_DataString(p_param_data,"FXCCY",p_dl_smi_tmp_trade_struct_h -> h_fxccy);
	CO_Rtv_DataString(p_param_data,"UNIQ_IDENT_NO",p_dl_smi_tmp_trade_struct_h -> h_uniq_ident_no);
	CO_Rtv_DataInt(p_param_data,"CNT_548",(int *) &(p_dl_smi_tmp_trade_struct_h -> h_cnt_548));
	CO_Rtv_DataString(p_param_data,"EXP_SETLDATE",p_dl_smi_tmp_trade_struct_h -> h_exp_setldate);
	CO_Rtv_DataString(p_param_data,"RELATED_IDENT_NO",p_dl_smi_tmp_trade_struct_h -> h_related_ident_no);
	CO_Rtv_DataString(p_param_data,"INFORMATON",p_dl_smi_tmp_trade_struct_h -> h_informaton);
}






int Populate_DL_SUMFUTURE_VDP_VEW(DL_SUMFUTURE_VDP_VEW_STRUCT_H *p_dl_sumfuture_vdp_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_sumfuture_vdp_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_sumfuture_vdp_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_sumfuture_vdp_vew_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_dl_sumfuture_vdp_vew_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"VDP_DATE",p_dl_sumfuture_vdp_vew_struct_h -> h_vdp_date);
	CO_Rtv_DataInt(p_param_data,"VDP_POS",(int *) &(p_dl_sumfuture_vdp_vew_struct_h -> h_vdp_pos));
}






int Populate_DL_TMPMSGLINK(DL_TMPMSGLINK_STRUCT_H *p_dl_tmpmsglink_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_tmpmsglink_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_dl_tmpmsglink_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_dl_tmpmsglink_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_dl_tmpmsglink_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_dl_tmpmsglink_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_dl_tmpmsglink_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_tmpmsglink_struct_h -> h_inden_num));
	CO_Rtv_DataInt(p_param_data,"DL_REP_IDENTNO",(int *) &(p_dl_tmpmsglink_struct_h -> h_dl_rep_identno));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_dl_tmpmsglink_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_dl_tmpmsglink_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_dl_tmpmsglink_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_dl_tmpmsglink_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_dl_tmpmsglink_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"PSETPARTY",p_dl_tmpmsglink_struct_h -> h_psetparty);
	CO_Rtv_DataString(p_param_data,"PLACE_CD",p_dl_tmpmsglink_struct_h -> h_place_cd);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_tmpmsglink_struct_h -> h_narrative);
}






int Populate_DL_TMPMSGLINKDET(DL_TMPMSGLINKDET_STRUCT_H *p_dl_tmpmsglinkdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_dl_tmpmsglinkdet_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"SEQUENCE_NAME",p_dl_tmpmsglinkdet_struct_h -> h_sequence_name);
	CO_Rtv_DataString(p_param_data,"LINK_VAL",p_dl_tmpmsglinkdet_struct_h -> h_link_val);
	CO_Rtv_DataString(p_param_data,"LINK_TAG",p_dl_tmpmsglinkdet_struct_h -> h_link_tag);
	CO_Rtv_DataInt(p_param_data,"MSG_TAG_REP_NO",(int *) &(p_dl_tmpmsglinkdet_struct_h -> h_msg_tag_rep_no));
	CO_Rtv_DataInt(p_param_data,"MSG_LINE_NO",(int *) &(p_dl_tmpmsglinkdet_struct_h -> h_msg_line_no));
	CO_Rtv_DataString(p_param_data,"MSG_TAG",p_dl_tmpmsglinkdet_struct_h -> h_msg_tag);
}






int Populate_DL_WEEKTXNBAL(DL_WEEKTXNBAL_STRUCT_H *p_dl_weektxnbal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_weektxnbal_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_weektxnbal_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"PREV_GEN_DATE",p_dl_weektxnbal_struct_h -> h_prev_gen_date);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_BAL",&(p_dl_weektxnbal_struct_h -> h_closing_bal));
}






int Populate_DW_ARESPONSE_VEW(DW_ARESPONSE_VEW_STRUCT_H *p_dw_aresponse_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_aresponse_vew_struct_h -> h_details1);
}






int Populate_DW_CACHEQUE_VEW(DW_CACHEQUE_VEW_STRUCT_H *p_dw_cacheque_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_cacheque_vew_struct_h -> h_details1);
	CO_Rtv_DataString(p_param_data,"DETAILS2",p_dw_cacheque_vew_struct_h -> h_details2);
}




/*

int Populate_DW_CAEVENT_VEW(DW_CAEVENT_VEW_STRUCT_H *p_dw_caevent_vew_struct_h,char * p_param_data)
{
	
	
	
	
}

*/




int Populate_DW_CANOTE_VEW(DW_CANOTE_VEW_STRUCT_H *p_dw_canote_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_canote_vew_struct_h -> h_details1);
	CO_Rtv_DataString(p_param_data,"DETAILS2",p_dw_canote_vew_struct_h -> h_details2);
	CO_Rtv_DataString(p_param_data,"DETAILS3",p_dw_canote_vew_struct_h -> h_details3);
	CO_Rtv_DataString(p_param_data,"DETAILS4",p_dw_canote_vew_struct_h -> h_details4);
	CO_Rtv_DataString(p_param_data,"DETAILS5",p_dw_canote_vew_struct_h -> h_details5);
	CO_Rtv_DataString(p_param_data,"DETAILS6",p_dw_canote_vew_struct_h -> h_details6);
}






int Populate_DW_DLDEAL_VEW(DW_DLDEAL_VEW_STRUCT_H *p_dw_dldeal_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_dldeal_vew_struct_h -> h_details1);
	CO_Rtv_DataString(p_param_data,"DETAILS2",p_dw_dldeal_vew_struct_h -> h_details2);
	CO_Rtv_DataString(p_param_data,"ALTERNATE_CURRCD",p_dw_dldeal_vew_struct_h -> h_alternate_currcd);
	CO_Rtv_DataString(p_param_data,"DETAILS3",p_dw_dldeal_vew_struct_h -> h_details3);
	CO_Rtv_DataString(p_param_data,"DETAILS4",p_dw_dldeal_vew_struct_h -> h_details4);
	CO_Rtv_DataString(p_param_data,"DETAILS5",p_dw_dldeal_vew_struct_h -> h_details5);
	CO_Rtv_DataString(p_param_data,"DETAILS6",p_dw_dldeal_vew_struct_h -> h_details6);
	CO_Rtv_DataString(p_param_data,"DETAILS7",p_dw_dldeal_vew_struct_h -> h_details7);
	CO_Rtv_DataString(p_param_data,"DETAILS8",p_dw_dldeal_vew_struct_h -> h_details8);
	CO_Rtv_DataString(p_param_data,"DETAILS9",p_dw_dldeal_vew_struct_h -> h_details9);
}






int Populate_DW_DLSAFEK_VEW(DW_DLSAFEK_VEW_STRUCT_H *p_dw_dlsafek_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_dlsafek_vew_struct_h -> h_details1);
}






/*int Populate_DW_MTCLIENT_VEW(DW_MTCLIENT_VEW_STRUCT_H *p_dw_mtclient_vew_struct_h,char * p_param_data)
{
	
	
	
	
}
*/





int Populate_DW_MTDAILY_MKT_PRICE_VEW(DW_MTDAILY_MKT_PRICE_VEW_STRUCT_H *p_dw_mtdaily_mkt_price_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DETAILS1",p_dw_mtdaily_mkt_price_vew_struct_h -> h_details1);
}





/*
int Populate_DW_MTINSTRUMENT_VEW(DW_MTINSTRUMENT_VEW_STRUCT_H *p_dw_mtinstrument_vew_struct_h,char * p_param_data)
{
	
	
	
	
}
*/






int Populate_GN_AUDIT_LOG(GN_AUDIT_LOG_STRUCT_H *p_gn_audit_log_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"USERID",p_gn_audit_log_struct_h -> h_userid);
	CO_Rtv_DataString(p_param_data,"REC_MODE",p_gn_audit_log_struct_h -> h_rec_mode);
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_audit_log_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"KEY_VALUE",p_gn_audit_log_struct_h -> h_key_value);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_gn_audit_log_struct_h -> h_audit_data);
	CO_Rtv_DataString(p_param_data,"LOG_TIME",p_gn_audit_log_struct_h -> h_log_time);
	CO_Rtv_DataString(p_param_data,"COMMENTS",p_gn_audit_log_struct_h -> h_comments);
}






int Populate_GN_AUDIT_MAP(GN_AUDIT_MAP_STRUCT_H *p_gn_audit_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_audit_map_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_gn_audit_map_struct_h -> h_audit_data);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_audit_map_struct_h -> h_key_data);
	CO_Rtv_DataString(p_param_data,"KEY_GRID_DATA",p_gn_audit_map_struct_h -> h_key_grid_data);
}






int Populate_GN_AUDIT_MAP_230106(GN_AUDIT_MAP_230106_STRUCT_H *p_gn_audit_map_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_audit_map_230106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_gn_audit_map_230106_struct_h -> h_audit_data);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_audit_map_230106_struct_h -> h_key_data);
}






int Populate_GN_AUDIT_MAP_BAK(GN_AUDIT_MAP_BAK_STRUCT_H *p_gn_audit_map_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_audit_map_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_gn_audit_map_bak_struct_h -> h_audit_data);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_audit_map_bak_struct_h -> h_key_data);
}






int Populate_GN_AUDIT_MAP_DUMMY(GN_AUDIT_MAP_DUMMY_STRUCT_H *p_gn_audit_map_dummy_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_audit_map_dummy_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_gn_audit_map_dummy_struct_h -> h_audit_data);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_audit_map_dummy_struct_h -> h_key_data);
}






int Populate_GN_COMMON_STATUS(GN_COMMON_STATUS_STRUCT_H *p_gn_common_status_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_common_status_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_common_status_struct_h -> h_key_data);
	CO_Rtv_DataString(p_param_data,"ENTITY_CAPTION",p_gn_common_status_struct_h -> h_entity_caption);
	CO_Rtv_DataString(p_param_data,"KEY_COLUMN",p_gn_common_status_struct_h -> h_key_column);
}






int Populate_GN_COMMON_STATUS_BAK(GN_COMMON_STATUS_BAK_STRUCT_H *p_gn_common_status_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_common_status_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"KEY_DATA",p_gn_common_status_bak_struct_h -> h_key_data);
	CO_Rtv_DataString(p_param_data,"ENTITY_CAPTION",p_gn_common_status_bak_struct_h -> h_entity_caption);
	CO_Rtv_DataString(p_param_data,"KEY_COLUMN",p_gn_common_status_bak_struct_h -> h_key_column);
}






int Populate_GN_CRITERIA_PICKLIST(GN_CRITERIA_PICKLIST_STRUCT_H *p_gn_criteria_picklist_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_gn_criteria_picklist_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_gn_criteria_picklist_struct_h -> h_picklist_query);
}






int Populate_GN_ENTITY_PICKLIST(GN_ENTITY_PICKLIST_STRUCT_H *p_gn_entity_picklist_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_entity_picklist_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_gn_entity_picklist_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_gn_entity_picklist_struct_h -> h_picklist_query);
}






int Populate_GN_ENTITY_PICKLIST_230106(GN_ENTITY_PICKLIST_230106_STRUCT_H *p_gn_entity_picklist_230106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_entity_picklist_230106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_gn_entity_picklist_230106_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_gn_entity_picklist_230106_struct_h -> h_picklist_query);
}






int Populate_GN_ENTITY_PICKLIST_300106(GN_ENTITY_PICKLIST_300106_STRUCT_H *p_gn_entity_picklist_300106_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_entity_picklist_300106_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_gn_entity_picklist_300106_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_gn_entity_picklist_300106_struct_h -> h_picklist_query);
}






int Populate_GN_ENTITY_PICKLIST_BAK(GN_ENTITY_PICKLIST_BAK_STRUCT_H *p_gn_entity_picklist_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ENTITY_NAME",p_gn_entity_picklist_bak_struct_h -> h_entity_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_NAME",p_gn_entity_picklist_bak_struct_h -> h_picklist_name);
	CO_Rtv_DataString(p_param_data,"PICKLIST_QUERY",p_gn_entity_picklist_bak_struct_h -> h_picklist_query);
}






/*int Populate_INVOICE_SYSTEMPARAM(INVOICE_SYSTEMPARAM_STRUCT_H *p_invoice_systemparam_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"B_CCY",p_invoice_systemparam_struct_h -> h_b_ccy);
	CO_Rtv_DataString(p_param_data,"B_BASIS",p_invoice_systemparam_struct_h -> h_b_basis);
	CO_Rtv_DataInt(p_param_data,"LATE_DL_DAYS_A",(int *) &(p_invoice_systemparam_struct_h -> h_late_dl_days_a));
	CO_Rtv_DataInt(p_param_data,"ALLOWED_WRT_OFF_AMT",(int *) &(p_invoice_systemparam_struct_h -> h_allowed_wrt_off_amt));
	CO_Rtv_DataInt(p_param_data,"DB_TXNRCD",(int *) &(p_invoice_systemparam_struct_h -> h_db_txnrcd));
	CO_Rtv_DataInt(p_param_data,"CRED_TXNRCD",(int *) &(p_invoice_systemparam_struct_h -> h_cred_txnrcd));
	CO_Rtv_DataInt(p_param_data,"VAL_DAYS",(int *) &(p_invoice_systemparam_struct_h -> h_val_days));
	CO_Rtv_DataInt(p_param_data,"PERIODFOR_ARCH",(int *) &(p_invoice_systemparam_struct_h -> h_periodfor_arch));
	CO_Rtv_DataInt(p_param_data,"PYMT_GEN_DATE",(int *) &(p_invoice_systemparam_struct_h -> h_pymt_gen_date));
	CO_Rtv_DataString(p_param_data,"STATUS_PYMT",p_invoice_systemparam_struct_h -> h_status_pymt);
	CO_Rtv_DataString(p_param_data,"LATETIME_A",p_invoice_systemparam_struct_h -> h_latetime_a);
	CO_Rtv_DataInt(p_param_data,"LATE_DL_DAYS_B",(int *) &(p_invoice_systemparam_struct_h -> h_late_dl_days_b));
	CO_Rtv_DataString(p_param_data,"LATETIME_B",p_invoice_systemparam_struct_h -> h_latetime_b);
	CO_Rtv_DataInt(p_param_data,"LATE_DL_DAYS_C",(int *) &(p_invoice_systemparam_struct_h -> h_late_dl_days_c));
	CO_Rtv_DataString(p_param_data,"LATETIME_C",p_invoice_systemparam_struct_h -> h_latetime_c);
	CO_Rtv_DataInt(p_param_data,"LATE_DL_DAYS_D",(int *) &(p_invoice_systemparam_struct_h -> h_late_dl_days_d));
	CO_Rtv_DataString(p_param_data,"LATETIME_D",p_invoice_systemparam_struct_h -> h_latetime_d);
}
*/






int Populate_IV_ARCHCHEQUE(IV_ARCHCHEQUE_STRUCT_H *p_iv_archcheque_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archcheque_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_iv_archcheque_struct_h -> h_dateof_payment);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_archcheque_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_archcheque_struct_h -> h_b_ccycd);
	CO_Rtv_DataDbl(p_param_data,"CONF_AMT",&(p_iv_archcheque_struct_h -> h_conf_amt));
	CO_Rtv_DataInt(p_param_data,"PAY_SEQ",(int *) &(p_iv_archcheque_struct_h -> h_pay_seq));
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_archcheque_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_archcheque_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_archcheque_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_PYMT",p_iv_archcheque_struct_h -> h_status_pymt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_archcheque_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_archcheque_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"PYMT_CLT",p_iv_archcheque_struct_h -> h_pymt_clt);
	CO_Rtv_DataString(p_param_data,"AE_DT",p_iv_archcheque_struct_h -> h_ae_dt);
	CO_Rtv_DataInt(p_param_data,"PROC_NUM",(int *) &(p_iv_archcheque_struct_h -> h_proc_num));
	CO_Rtv_DataString(p_param_data,"ADJUST_ENTRY",p_iv_archcheque_struct_h -> h_adjust_entry);
}






int Populate_IV_ARCHCLIENTHOLDING(IV_ARCHCLIENTHOLDING_STRUCT_H *p_iv_archclientholding_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_archclientholding_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archclientholding_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_iv_archclientholding_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_archclientholding_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_archclientholding_struct_h -> h_proc_data_val);
	CO_Rtv_DataDbl(p_param_data,"MKRTPR",&(p_iv_archclientholding_struct_h -> h_mkrtpr));
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_iv_archclientholding_struct_h -> h_currency_cd);
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_iv_archclientholding_struct_h -> h_safekeep_pos));
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_archclientholding_struct_h -> h_cons_flag);
	CO_Rtv_DataDbl(p_param_data,"EXCHG_RT",&(p_iv_archclientholding_struct_h -> h_exchg_rt));
}






int Populate_IV_ARCHEXCHANGERATE(IV_ARCHEXCHANGERATE_STRUCT_H *p_iv_archexchangerate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"FRM_CCYCD",p_iv_archexchangerate_struct_h -> h_frm_ccycd);
	CO_Rtv_DataString(p_param_data,"TO_CURRENCY",p_iv_archexchangerate_struct_h -> h_to_currency);
	CO_Rtv_DataDbl(p_param_data,"EXCHG_RT",&(p_iv_archexchangerate_struct_h -> h_exchg_rt));
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_archexchangerate_struct_h -> h_dateof_billing);
}






int Populate_IV_ARCHEXTRASERVICE(IV_ARCHEXTRASERVICE_STRUCT_H *p_iv_archextraservice_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archextraservice_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_archextraservice_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"B_UPTO_DATE",p_iv_archextraservice_struct_h -> h_b_upto_date);
	CO_Rtv_DataDbl(p_param_data,"SERVICE_QTY",&(p_iv_archextraservice_struct_h -> h_service_qty));
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_archextraservice_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_archextraservice_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_archextraservice_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"SERVICE_DET",p_iv_archextraservice_struct_h -> h_service_det);
	CO_Rtv_DataDbl(p_param_data,"SCHDL_FEE",&(p_iv_archextraservice_struct_h -> h_schdl_fee));
	CO_Rtv_DataString(p_param_data,"SERVICE_STAT",p_iv_archextraservice_struct_h -> h_service_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_archextraservice_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_archextraservice_struct_h -> h_checker_dt);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_archextraservice_struct_h -> h_inden_num));
}






int Populate_IV_ARCHLEDGER(IV_ARCHLEDGER_STRUCT_H *p_iv_archledger_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_archledger_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archledger_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_DOC",p_iv_archledger_struct_h -> h_dateof_doc);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_archledger_struct_h -> h_inden_num));
	CO_Rtv_DataDbl(p_param_data,"SERVICE_AMT",&(p_iv_archledger_struct_h -> h_service_amt));
	CO_Rtv_DataDbl(p_param_data,"RUN_BALANCE",&(p_iv_archledger_struct_h -> h_run_balance));
	CO_Rtv_DataDbl(p_param_data,"OUT_STAND_AMT",&(p_iv_archledger_struct_h -> h_out_stand_amt));
	CO_Rtv_DataString(p_param_data,"CLASS_IND",p_iv_archledger_struct_h -> h_class_ind);
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_archledger_struct_h -> h_b_ccycd);
}






int Populate_IV_ARCHOUTSTANDINGAMT(IV_ARCHOUTSTANDINGAMT_STRUCT_H *p_iv_archoutstandingamt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archoutstandingamt_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_archoutstandingamt_struct_h -> h_dateof_billing);
	CO_Rtv_DataDbl(p_param_data,"B_OUTS_AMOUNT",&(p_iv_archoutstandingamt_struct_h -> h_b_outs_amount));
}






int Populate_IV_ARCHSERVICECHG(IV_ARCHSERVICECHG_STRUCT_H *p_iv_archservicechg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_archservicechg_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archservicechg_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"NIL_FEES_ADJ",&(p_iv_archservicechg_struct_h -> h_nil_fees_adj));
	CO_Rtv_DataDbl(p_param_data,"MINIMUMFEE_ADJ",&(p_iv_archservicechg_struct_h -> h_minimumfee_adj));
	CO_Rtv_DataDbl(p_param_data,"MAXIMUM_FEE_ADJ",&(p_iv_archservicechg_struct_h -> h_maximum_fee_adj));
	CO_Rtv_DataDbl(p_param_data,"COMM_AMT",&(p_iv_archservicechg_struct_h -> h_comm_amt));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_archservicechg_struct_h -> h_b_ccycd);
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_archservicechg_struct_h -> h_cons_flag);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_archservicechg_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_iv_archservicechg_struct_h -> h_master_clt);
}






int Populate_IV_ARCHTRANSACTION(IV_ARCHTRANSACTION_STRUCT_H *p_iv_archtransaction_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_archtransaction_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_archtransaction_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_archtransaction_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_archtransaction_struct_h -> h_cons_flag);
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_archtransaction_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_archtransaction_struct_h -> h_proc_data_val);
	CO_Rtv_DataDbl(p_param_data,"COMM_AMT",&(p_iv_archtransaction_struct_h -> h_comm_amt));
	CO_Rtv_DataDbl(p_param_data,"CHRG_QUANT",&(p_iv_archtransaction_struct_h -> h_chrg_quant));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_archtransaction_struct_h -> h_b_ccycd);
	CO_Rtv_DataDbl(p_param_data,"FEES_QTY",&(p_iv_archtransaction_struct_h -> h_fees_qty));
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_iv_archtransaction_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"GROUP_ID",p_iv_archtransaction_struct_h -> h_group_id);
}






int Populate_IV_BILL(IV_BILL_STRUCT_H *p_iv_bill_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_bill_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_bill_struct_h -> h_dateof_billing);
	CO_Rtv_DataInt(p_param_data,"IV_SEQNO",(int *) &(p_iv_bill_struct_h -> h_iv_seqno));
}






int Populate_IV_CHEQUE(IV_CHEQUE_STRUCT_H *p_iv_cheque_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_cheque_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_iv_cheque_struct_h -> h_dateof_payment);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_cheque_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_cheque_struct_h -> h_b_ccycd);
	CO_Rtv_DataDbl(p_param_data,"CONF_AMT",&(p_iv_cheque_struct_h -> h_conf_amt));
	CO_Rtv_DataInt(p_param_data,"PAY_SEQ",(int *) &(p_iv_cheque_struct_h -> h_pay_seq));
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_cheque_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_cheque_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_cheque_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_PYMT",p_iv_cheque_struct_h -> h_status_pymt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_cheque_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_cheque_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"PYMT_CLT",p_iv_cheque_struct_h -> h_pymt_clt);
	CO_Rtv_DataString(p_param_data,"AE_DT",p_iv_cheque_struct_h -> h_ae_dt);
	CO_Rtv_DataInt(p_param_data,"PROC_NUM",(int *) &(p_iv_cheque_struct_h -> h_proc_num));
	CO_Rtv_DataString(p_param_data,"ADJUST_ENTRY",p_iv_cheque_struct_h -> h_adjust_entry);
}






int Populate_IV_CHEQUE_DET(IV_CHEQUE_DET_STRUCT_H *p_iv_cheque_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_cheque_det_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_cheque_det_struct_h -> h_inden_num));
	CO_Rtv_DataString(p_param_data,"DATEOF_PAYMENT",p_iv_cheque_det_struct_h -> h_dateof_payment);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_cheque_det_struct_h -> h_service_cd));
	CO_Rtv_DataDbl(p_param_data,"SERVICE_AMT",&(p_iv_cheque_det_struct_h -> h_service_amt));
	CO_Rtv_DataString(p_param_data,"STATUS_PAYDET",p_iv_cheque_det_struct_h -> h_status_paydet);
}






int Populate_IV_CLIENT(IV_CLIENT_STRUCT_H *p_iv_client_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"COMM_A",p_iv_client_struct_h -> h_comm_a);
	CO_Rtv_DataString(p_param_data,"PAYACC_A",p_iv_client_struct_h -> h_payacc_a);
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_client_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_client_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_client_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_client_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_client_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"COMM_B",p_iv_client_struct_h -> h_comm_b);
	CO_Rtv_DataString(p_param_data,"COMM_C",p_iv_client_struct_h -> h_comm_c);
	CO_Rtv_DataString(p_param_data,"COMM_D",p_iv_client_struct_h -> h_comm_d);
	CO_Rtv_DataString(p_param_data,"COMM_E",p_iv_client_struct_h -> h_comm_e);
	CO_Rtv_DataString(p_param_data,"COMM_F",p_iv_client_struct_h -> h_comm_f);
	CO_Rtv_DataString(p_param_data,"COMM_G",p_iv_client_struct_h -> h_comm_g);
	CO_Rtv_DataString(p_param_data,"COMM_H",p_iv_client_struct_h -> h_comm_h);
	CO_Rtv_DataString(p_param_data,"COMM_I",p_iv_client_struct_h -> h_comm_i);
	CO_Rtv_DataString(p_param_data,"TAX_ACC",p_iv_client_struct_h -> h_tax_acc);
	CO_Rtv_DataString(p_param_data,"PAYACC_B",p_iv_client_struct_h -> h_payacc_b);
}






int Populate_IV_CLIENTFEE(IV_CLIENTFEE_STRUCT_H *p_iv_clientfee_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_clientfee_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_clientfee_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_clientfee_struct_h -> h_proc_data_val);
	CO_Rtv_DataString(p_param_data,"GROUP_ID",p_iv_clientfee_struct_h -> h_group_id);
	CO_Rtv_DataDbl(p_param_data,"SCHDL_FEE",&(p_iv_clientfee_struct_h -> h_schdl_fee));
	CO_Rtv_DataDbl(p_param_data,"FRM_CBASE",&(p_iv_clientfee_struct_h -> h_frm_cbase));
	CO_Rtv_DataDbl(p_param_data,"TOC_BASE",&(p_iv_clientfee_struct_h -> h_toc_base));
	CO_Rtv_DataDbl(p_param_data,"FRM_FBASE",&(p_iv_clientfee_struct_h -> h_frm_fbase));
	CO_Rtv_DataDbl(p_param_data,"TOF_BASE",&(p_iv_clientfee_struct_h -> h_tof_base));
	CO_Rtv_DataString(p_param_data,"SERVICE_STAT",p_iv_clientfee_struct_h -> h_service_stat);
}






int Populate_IV_CLIENTHOLDING(IV_CLIENTHOLDING_STRUCT_H *p_iv_clientholding_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_clientholding_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_clientholding_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_iv_clientholding_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_clientholding_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_clientholding_struct_h -> h_proc_data_val);
	CO_Rtv_DataDbl(p_param_data,"MKRTPR",&(p_iv_clientholding_struct_h -> h_mkrtpr));
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_iv_clientholding_struct_h -> h_currency_cd);
	CO_Rtv_DataDbl(p_param_data,"SAFEKEEP_POS",&(p_iv_clientholding_struct_h -> h_safekeep_pos));
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_clientholding_struct_h -> h_cons_flag);
	CO_Rtv_DataDbl(p_param_data,"EXCHG_RT",&(p_iv_clientholding_struct_h -> h_exchg_rt));
}






int Populate_IV_CLIENTPARAM(IV_CLIENTPARAM_STRUCT_H *p_iv_clientparam_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_clientparam_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_clientparam_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_clientparam_struct_h -> h_parameter_cd);
}






int Populate_IV_CLIENTSETUP(IV_CLIENTSETUP_STRUCT_H *p_iv_clientsetup_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_clientsetup_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_clientsetup_struct_h -> h_b_ccycd);
	CO_Rtv_DataString(p_param_data,"SEND_TO_MASTER_IND",p_iv_clientsetup_struct_h -> h_send_to_master_ind);
	CO_Rtv_DataString(p_param_data,"B_GEN_IND",p_iv_clientsetup_struct_h -> h_b_gen_ind);
	CO_Rtv_DataDbl(p_param_data,"MINIMUMFEE",&(p_iv_clientsetup_struct_h -> h_minimumfee));
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_iv_clientsetup_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MINIMUMFEE_TO",p_iv_clientsetup_struct_h -> h_minimumfee_to);
	CO_Rtv_DataString(p_param_data,"MIN_HLD_ADJ",p_iv_clientsetup_struct_h -> h_min_hld_adj);
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_clientsetup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_clientsetup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_clientsetup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"DIR_DB_IND",p_iv_clientsetup_struct_h -> h_dir_db_ind);
	CO_Rtv_DataString(p_param_data,"STAT_IND",p_iv_clientsetup_struct_h -> h_stat_ind);
	CO_Rtv_DataString(p_param_data,"SPL_CLT_CD",p_iv_clientsetup_struct_h -> h_spl_clt_cd);
	CO_Rtv_DataString(p_param_data,"COMM_CLT",p_iv_clientsetup_struct_h -> h_comm_clt);
	CO_Rtv_DataString(p_param_data,"REC_CLT",p_iv_clientsetup_struct_h -> h_rec_clt);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_iv_clientsetup_struct_h -> h_information);
	CO_Rtv_DataString(p_param_data,"DEFAULT_FEECLT",p_iv_clientsetup_struct_h -> h_default_feeclt);
	CO_Rtv_DataDbl(p_param_data,"TOTAL_OSAMOUNT",&(p_iv_clientsetup_struct_h -> h_total_osamount));
	CO_Rtv_DataString(p_param_data,"LAST_PYMT_DATE",p_iv_clientsetup_struct_h -> h_last_pymt_date);
	CO_Rtv_DataString(p_param_data,"LAST_PYMT_CCY",p_iv_clientsetup_struct_h -> h_last_pymt_ccy);
	CO_Rtv_DataDbl(p_param_data,"LAST_PYMT_AMT",&(p_iv_clientsetup_struct_h -> h_last_pymt_amt));
	CO_Rtv_DataDbl(p_param_data,"LAST_LOST_AMT",&(p_iv_clientsetup_struct_h -> h_last_lost_amt));
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_clientsetup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_clientsetup_struct_h -> h_checker_dt);
	CO_Rtv_DataDbl(p_param_data,"COMM_TAX_AMT",&(p_iv_clientsetup_struct_h -> h_comm_tax_amt));
	CO_Rtv_DataString(p_param_data,"FEES_CCY",p_iv_clientsetup_struct_h -> h_fees_ccy);
	CO_Rtv_DataString(p_param_data,"VAT_CD",p_iv_clientsetup_struct_h -> h_vat_cd);
	CO_Rtv_DataString(p_param_data,"VAT_NOTE",p_iv_clientsetup_struct_h -> h_vat_note);
}






int Populate_IV_CLIENT_SERV_BASIS(IV_CLIENT_SERV_BASIS_STRUCT_H *p_iv_client_serv_basis_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_client_serv_basis_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_client_serv_basis_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"FEES_BASE",p_iv_client_serv_basis_struct_h -> h_fees_base);
	CO_Rtv_DataString(p_param_data,"CHRG_BASE",p_iv_client_serv_basis_struct_h -> h_chrg_base);
	CO_Rtv_DataString(p_param_data,"CHRG_CLAS",p_iv_client_serv_basis_struct_h -> h_chrg_clas);
	CO_Rtv_DataString(p_param_data,"FEES_CLASS",p_iv_client_serv_basis_struct_h -> h_fees_class);
	CO_Rtv_DataDbl(p_param_data,"MINIMUMFEE",&(p_iv_client_serv_basis_struct_h -> h_minimumfee));
	CO_Rtv_DataDbl(p_param_data,"NIL_FEES",&(p_iv_client_serv_basis_struct_h -> h_nil_fees));
	CO_Rtv_DataDbl(p_param_data,"MAXIMUM_FEE",&(p_iv_client_serv_basis_struct_h -> h_maximum_fee));
	CO_Rtv_DataString(p_param_data,"DEALADM_FEECCY",p_iv_client_serv_basis_struct_h -> h_dealadm_feeccy);
}






int Populate_IV_DATA_GRP(IV_DATA_GRP_STRUCT_H *p_iv_data_grp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_data_grp_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"GROUP_PRM_CD",p_iv_data_grp_struct_h -> h_group_prm_cd);
	CO_Rtv_DataString(p_param_data,"GROUP_MEM_VAL",p_iv_data_grp_struct_h -> h_group_mem_val);
}






int Populate_IV_DEAL(IV_DEAL_STRUCT_H *p_iv_deal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_deal_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_deal_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_deal_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_deal_struct_h -> h_cons_flag);
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_deal_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_deal_struct_h -> h_proc_data_val);
	CO_Rtv_DataDbl(p_param_data,"COMM_AMT",&(p_iv_deal_struct_h -> h_comm_amt));
	CO_Rtv_DataDbl(p_param_data,"CHRG_QUANT",&(p_iv_deal_struct_h -> h_chrg_quant));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_deal_struct_h -> h_b_ccycd);
	CO_Rtv_DataDbl(p_param_data,"FEES_QTY",&(p_iv_deal_struct_h -> h_fees_qty));
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_iv_deal_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"GROUP_ID",p_iv_deal_struct_h -> h_group_id);
}






int Populate_IV_DEAL_FEE(IV_DEAL_FEE_STRUCT_H *p_iv_deal_fee_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_deal_fee_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_deal_fee_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_deal_fee_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_deal_fee_struct_h -> h_cons_flag);
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_deal_fee_struct_h -> h_parameter_cd);
	CO_Rtv_DataDbl(p_param_data,"COMM_AMT",&(p_iv_deal_fee_struct_h -> h_comm_amt));
	CO_Rtv_DataString(p_param_data,"PROC_DATA_VAL",p_iv_deal_fee_struct_h -> h_proc_data_val);
	CO_Rtv_DataDbl(p_param_data,"SCHDL_FEE",&(p_iv_deal_fee_struct_h -> h_schdl_fee));
	CO_Rtv_DataDbl(p_param_data,"CHRG_QUANT",&(p_iv_deal_fee_struct_h -> h_chrg_quant));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_deal_fee_struct_h -> h_b_ccycd);
	CO_Rtv_DataDbl(p_param_data,"FEES_QTY",&(p_iv_deal_fee_struct_h -> h_fees_qty));
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_iv_deal_fee_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"GROUP_ID",p_iv_deal_fee_struct_h -> h_group_id);
}






int Populate_IV_DEAL_TYPE(IV_DEAL_TYPE_STRUCT_H *p_iv_deal_type_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION_CD",p_iv_deal_type_struct_h -> h_nation_cd);
	CO_Rtv_DataInt(p_param_data,"DL_CLASS",(int *) &(p_iv_deal_type_struct_h -> h_dl_class));
}






int Populate_IV_EXCHANGERATE(IV_EXCHANGERATE_STRUCT_H *p_iv_exchangerate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"FRM_CCYCD",p_iv_exchangerate_struct_h -> h_frm_ccycd);
	CO_Rtv_DataString(p_param_data,"TO_CURRENCY",p_iv_exchangerate_struct_h -> h_to_currency);
	CO_Rtv_DataDbl(p_param_data,"EXCHG_RT",&(p_iv_exchangerate_struct_h -> h_exchg_rt));
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_exchangerate_struct_h -> h_dateof_billing);
}






int Populate_IV_LEDGER(IV_LEDGER_STRUCT_H *p_iv_ledger_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_ledger_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_ledger_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_DOC",p_iv_ledger_struct_h -> h_dateof_doc);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_ledger_struct_h -> h_inden_num));
	CO_Rtv_DataDbl(p_param_data,"SERVICE_AMT",&(p_iv_ledger_struct_h -> h_service_amt));
	CO_Rtv_DataDbl(p_param_data,"RUN_BALANCE",&(p_iv_ledger_struct_h -> h_run_balance));
	CO_Rtv_DataDbl(p_param_data,"OUT_STAND_AMT",&(p_iv_ledger_struct_h -> h_out_stand_amt));
	CO_Rtv_DataString(p_param_data,"CLASS_IND",p_iv_ledger_struct_h -> h_class_ind);
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_ledger_struct_h -> h_b_ccycd);
}





/*
int Populate_IV_LEDGER_VW(IV_LEDGER_VW_STRUCT_H *p_iv_ledger_vw_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
*/





int Populate_IV_OUTSTANDINGAMT(IV_OUTSTANDINGAMT_STRUCT_H *p_iv_outstandingamt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_outstandingamt_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_outstandingamt_struct_h -> h_dateof_billing);
	CO_Rtv_DataDbl(p_param_data,"B_OUTS_AMOUNT",&(p_iv_outstandingamt_struct_h -> h_b_outs_amount));
}






int Populate_IV_SELCLIENT(IV_SELCLIENT_STRUCT_H *p_iv_selclient_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_selclient_struct_h -> h_client);
}






int Populate_IV_SERVICE_CHRG(IV_SERVICE_CHRG_STRUCT_H *p_iv_service_chrg_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATEOF_BILLING",p_iv_service_chrg_struct_h -> h_dateof_billing);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_service_chrg_struct_h -> h_client);
	CO_Rtv_DataDbl(p_param_data,"NIL_FEES_ADJ",&(p_iv_service_chrg_struct_h -> h_nil_fees_adj));
	CO_Rtv_DataDbl(p_param_data,"MINIMUMFEE_ADJ",&(p_iv_service_chrg_struct_h -> h_minimumfee_adj));
	CO_Rtv_DataDbl(p_param_data,"MAXIMUM_FEE_ADJ",&(p_iv_service_chrg_struct_h -> h_maximum_fee_adj));
	CO_Rtv_DataDbl(p_param_data,"COMM_AMT",&(p_iv_service_chrg_struct_h -> h_comm_amt));
	CO_Rtv_DataString(p_param_data,"B_CCYCD",p_iv_service_chrg_struct_h -> h_b_ccycd);
	CO_Rtv_DataString(p_param_data,"CONS_FLAG",p_iv_service_chrg_struct_h -> h_cons_flag);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_service_chrg_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_iv_service_chrg_struct_h -> h_master_clt);
}






int Populate_IV_SERV_BASIS(IV_SERV_BASIS_STRUCT_H *p_iv_serv_basis_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_serv_basis_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"FEES_BASE",p_iv_serv_basis_struct_h -> h_fees_base);
	CO_Rtv_DataString(p_param_data,"IV_COND",p_iv_serv_basis_struct_h -> h_iv_cond);
	CO_Rtv_DataString(p_param_data,"CHRG_BASE",p_iv_serv_basis_struct_h -> h_chrg_base);
	CO_Rtv_DataString(p_param_data,"CHRG_VL_CLAS",p_iv_serv_basis_struct_h -> h_chrg_vl_clas);
	CO_Rtv_DataString(p_param_data,"FEES_VAL_CLASS",p_iv_serv_basis_struct_h -> h_fees_val_class);
}






int Populate_IV_SERV_DEPEND(IV_SERV_DEPEND_STRUCT_H *p_iv_serv_depend_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_serv_depend_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"PARAMETER_CD",p_iv_serv_depend_struct_h -> h_parameter_cd);
	CO_Rtv_DataString(p_param_data,"INFO_TYPE",p_iv_serv_depend_struct_h -> h_info_type);
	CO_Rtv_DataInt(p_param_data,"INFO_WIDTH",(int *) &(p_iv_serv_depend_struct_h -> h_info_width));
	CO_Rtv_DataInt(p_param_data,"INFO_DEC",(int *) &(p_iv_serv_depend_struct_h -> h_info_dec));
	CO_Rtv_DataString(p_param_data,"IV_COND",p_iv_serv_depend_struct_h -> h_iv_cond);
	CO_Rtv_DataString(p_param_data,"VALIDATE_PROC",p_iv_serv_depend_struct_h -> h_validate_proc);
	CO_Rtv_DataString(p_param_data,"HELP_FUNCTION",p_iv_serv_depend_struct_h -> h_help_function);
}






int Populate_IV_SERV_MAST(IV_SERV_MAST_STRUCT_H *p_iv_serv_mast_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_serv_mast_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"SERVICE_DET",p_iv_serv_mast_struct_h -> h_service_det);
	CO_Rtv_DataString(p_param_data,"FEES_CLASS",p_iv_serv_mast_struct_h -> h_fees_class);
	CO_Rtv_DataDbl(p_param_data,"MINIMUM_FEE",&(p_iv_serv_mast_struct_h -> h_minimum_fee));
	CO_Rtv_DataString(p_param_data,"STD_FEEIND",p_iv_serv_mast_struct_h -> h_std_feeind);
	CO_Rtv_DataString(p_param_data,"MASTSUB_IND",p_iv_serv_mast_struct_h -> h_mastsub_ind);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_serv_mast_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"VALID_FEE_CLASS",p_iv_serv_mast_struct_h -> h_valid_fee_class);
	CO_Rtv_DataString(p_param_data,"B_CLIENT",p_iv_serv_mast_struct_h -> h_b_client);
}






int Populate_IV_SERV_OTH(IV_SERV_OTH_STRUCT_H *p_iv_serv_oth_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_iv_serv_oth_struct_h -> h_client);
	CO_Rtv_DataInt(p_param_data,"SERVICE_CD",(int *) &(p_iv_serv_oth_struct_h -> h_service_cd));
	CO_Rtv_DataString(p_param_data,"B_UPTO_DATE",p_iv_serv_oth_struct_h -> h_b_upto_date);
	CO_Rtv_DataDbl(p_param_data,"SERVICE_QTY",&(p_iv_serv_oth_struct_h -> h_service_qty));
	CO_Rtv_DataString(p_param_data,"MAKER",p_iv_serv_oth_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_iv_serv_oth_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_iv_serv_oth_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"SERVICE_DET",p_iv_serv_oth_struct_h -> h_service_det);
	CO_Rtv_DataDbl(p_param_data,"SCHDL_FEE",&(p_iv_serv_oth_struct_h -> h_schdl_fee));
	CO_Rtv_DataString(p_param_data,"SERVICE_STAT",p_iv_serv_oth_struct_h -> h_service_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_iv_serv_oth_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_iv_serv_oth_struct_h -> h_checker_dt);
	CO_Rtv_DataInt(p_param_data,"INDEN_NUM",(int *) &(p_iv_serv_oth_struct_h -> h_inden_num));
}





/*
int Populate_IV_SUPERVISIONFEEGRP_VEW(IV_SUPERVISIONFEEGRP_VEW_STRUCT_H *p_iv_supervisionfeegrp_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

*/




int Populate_MASTATUS(MASTATUS_STRUCT_H *p_mastatus_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_STATCD",p_mastatus_struct_h -> h_instr_statcd);
	CO_Rtv_DataString(p_param_data,"STATUS_QUAL_IND",p_mastatus_struct_h -> h_status_qual_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_CD",p_mastatus_struct_h -> h_status_cd);
	CO_Rtv_DataString(p_param_data,"REASON_QL",p_mastatus_struct_h -> h_reason_ql);
	CO_Rtv_DataString(p_param_data,"REASON_CD",p_mastatus_struct_h -> h_reason_cd);
	CO_Rtv_DataString(p_param_data,"STATUS_DET",p_mastatus_struct_h -> h_status_det);
	CO_Rtv_DataString(p_param_data,"SUPPORT_IND",p_mastatus_struct_h -> h_support_ind);
}






int Populate_MAUDIT_TRACK(MAUDIT_TRACK_STRUCT_H *p_maudit_track_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_maudit_track_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_maudit_track_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_maudit_track_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"AUDIT_DATA",p_maudit_track_struct_h -> h_audit_data);
}






int Populate_MHLP_CODE(MHLP_CODE_STRUCT_H *p_mhlp_code_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MHLP_CODE",p_mhlp_code_struct_h -> h_mhlp_code);
	CO_Rtv_DataString(p_param_data,"LCL_BRKCD",p_mhlp_code_struct_h -> h_lcl_brkcd);
	CO_Rtv_DataString(p_param_data,"LCL_OPCD",p_mhlp_code_struct_h -> h_lcl_opcd);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_mhlp_code_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"MASTER_CLT",p_mhlp_code_struct_h -> h_master_clt);
	CO_Rtv_DataString(p_param_data,"CUSTODIAN_CLT",p_mhlp_code_struct_h -> h_custodian_clt);
	CO_Rtv_DataString(p_param_data,"MANUAL_IND",p_mhlp_code_struct_h -> h_manual_ind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mhlp_code_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mhlp_code_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mhlp_code_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mhlp_code_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"MHLP_STAT",p_mhlp_code_struct_h -> h_mhlp_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mhlp_code_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"LCL_BRK_MAST",p_mhlp_code_struct_h -> h_lcl_brk_mast);
}






int Populate_MMARKETRATE_VW(MMARKETRATE_VW_STRUCT_H *p_mmarketrate_vw_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mmarketrate_vw_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mmarketrate_vw_struct_h -> h_price_date);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mmarketrate_vw_struct_h -> h_closing_pr));
	CO_Rtv_DataString(p_param_data,"DIR_INDIR_FXQT_IND",p_mmarketrate_vw_struct_h -> h_dir_indir_fxqt_ind);
}






int Populate_MS_ARCHMSGLOG(MS_ARCHMSGLOG_STRUCT_H *p_ms_archmsglog_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_archmsglog_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"MESSAGE_IND",p_ms_archmsglog_struct_h -> h_message_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_archmsglog_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ms_archmsglog_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ms_archmsglog_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_ms_archmsglog_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_ms_archmsglog_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"MSG",p_ms_archmsglog_struct_h -> h_msg);
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS",p_ms_archmsglog_struct_h -> h_contact_details);
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS1",p_ms_archmsglog_struct_h -> h_contact_details1);
	CO_Rtv_DataString(p_param_data,"BASEID",p_ms_archmsglog_struct_h -> h_baseid);
	CO_Rtv_DataString(p_param_data,"MESSAGE_CLASS",p_ms_archmsglog_struct_h -> h_message_class);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_IDENT",p_ms_archmsglog_struct_h -> h_swift_msg_ident);
}






int Populate_MS_ARCHMSGSTAT(MS_ARCHMSGSTAT_STRUCT_H *p_ms_archmsgstat_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROC_INIT",p_ms_archmsgstat_struct_h -> h_proc_init);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_REP",p_ms_archmsgstat_struct_h -> h_swift_msg_rep);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_archmsgstat_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"GENERATE_DT",p_ms_archmsgstat_struct_h -> h_generate_dt);
}






int Populate_MS_BASE(MS_BASE_STRUCT_H *p_ms_base_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"BASEID",p_ms_base_struct_h -> h_baseid);
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS",p_ms_base_struct_h -> h_contact_details);
	CO_Rtv_DataString(p_param_data,"SWIFT_TLX_GCN",p_ms_base_struct_h -> h_swift_tlx_gcn);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ms_base_struct_h -> h_access_stamp);
}






int Populate_MS_DETAILSMAP(MS_DETAILSMAP_STRUCT_H *p_ms_detailsmap_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MESSAGE_CLASS",p_ms_detailsmap_struct_h -> h_message_class);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_detailsmap_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MSG_TAG",p_ms_detailsmap_struct_h -> h_msg_tag);
	CO_Rtv_DataInt(p_param_data,"IDENTITY_NO",(int *) &(p_ms_detailsmap_struct_h -> h_identity_no));
	CO_Rtv_DataString(p_param_data,"INFO_TYPE",p_ms_detailsmap_struct_h -> h_info_type);
	CO_Rtv_DataString(p_param_data,"INFO_ELEM",p_ms_detailsmap_struct_h -> h_info_elem);
	CO_Rtv_DataString(p_param_data,"HEAD_CONT_NEWLINE",p_ms_detailsmap_struct_h -> h_head_cont_newline);
	CO_Rtv_DataString(p_param_data,"MSG_TAG_COND",p_ms_detailsmap_struct_h -> h_msg_tag_cond);
	CO_Rtv_DataInt(p_param_data,"SRL_NUM",(int *) &(p_ms_detailsmap_struct_h -> h_srl_num));
	CO_Rtv_DataString(p_param_data,"PRINT_CD",p_ms_detailsmap_struct_h -> h_print_cd);
}






int Populate_MS_HISMSGSTAT(MS_HISMSGSTAT_STRUCT_H *p_ms_hismsgstat_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROC_INIT",p_ms_hismsgstat_struct_h -> h_proc_init);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_REP",p_ms_hismsgstat_struct_h -> h_swift_msg_rep);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_hismsgstat_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"GENERATE_DT",p_ms_hismsgstat_struct_h -> h_generate_dt);
	CO_Rtv_DataString(p_param_data,"DATEOF_DROP",p_ms_hismsgstat_struct_h -> h_dateof_drop);
}






int Populate_MS_INMSGRP(MS_INMSGRP_STRUCT_H *p_ms_inmsgrp_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"SRL_NUM",(int *) &(p_ms_inmsgrp_struct_h -> h_srl_num));
	CO_Rtv_DataString(p_param_data,"REPORT_DT",p_ms_inmsgrp_struct_h -> h_report_dt);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_inmsgrp_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"NAMEOF_FILE",p_ms_inmsgrp_struct_h -> h_nameof_file);
	CO_Rtv_DataString(p_param_data,"MESSAGE_STAT",p_ms_inmsgrp_struct_h -> h_message_stat);
	CO_Rtv_DataString(p_param_data,"REJECT_REASON",p_ms_inmsgrp_struct_h -> h_reject_reason);
	CO_Rtv_DataString(p_param_data,"REPORT_IND",p_ms_inmsgrp_struct_h -> h_report_ind);
	CO_Rtv_DataString(p_param_data,"SETL_DT",p_ms_inmsgrp_struct_h -> h_setl_dt);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_inmsgrp_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"SFE_IDENTITY_NO",p_ms_inmsgrp_struct_h -> h_sfe_identity_no);
}






int Populate_MS_MSGCRF(MS_MSGCRF_STRUCT_H *p_ms_msgcrf_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_msgcrf_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MSG_MAP_NO",p_ms_msgcrf_struct_h -> h_msg_map_no);
	CO_Rtv_DataString(p_param_data,"ISO_MSG_NO",p_ms_msgcrf_struct_h -> h_iso_msg_no);
}






int Populate_MS_MSGENT(MS_MSGENT_STRUCT_H *p_ms_msgent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_msgent_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"PROC_INIT",p_ms_msgent_struct_h -> h_proc_init);
	CO_Rtv_DataInt(p_param_data,"SWIFT_MSG_SEQNO",(int *) &(p_ms_msgent_struct_h -> h_swift_msg_seqno));
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_msgent_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INFO_FILE",p_ms_msgent_struct_h -> h_info_file);
	CO_Rtv_DataInt(p_param_data,"SWIFT_COUNT",(int *) &(p_ms_msgent_struct_h -> h_swift_count));
	CO_Rtv_DataInt(p_param_data,"TELEX_COUNT",(int *) &(p_ms_msgent_struct_h -> h_telex_count));
	CO_Rtv_DataInt(p_param_data,"FAX_COUNT",(int *) &(p_ms_msgent_struct_h -> h_fax_count));
	CO_Rtv_DataInt(p_param_data,"GCN_COUNT",(int *) &(p_ms_msgent_struct_h -> h_gcn_count));
	CO_Rtv_DataInt(p_param_data,"CLTS_COUNT",(int *) &(p_ms_msgent_struct_h -> h_clts_count));
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_ms_msgent_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"AUTO_TRAN_IND",p_ms_msgent_struct_h -> h_auto_tran_ind);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_ms_msgent_struct_h -> h_proc_data);
}






int Populate_MS_MSGLOG(MS_MSGLOG_STRUCT_H *p_ms_msglog_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_msglog_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"MESSAGE_IND",p_ms_msglog_struct_h -> h_message_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_msglog_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ms_msglog_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ms_msglog_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_ms_msglog_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_ms_msglog_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"MSG",p_ms_msglog_struct_h -> h_msg);
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS",p_ms_msglog_struct_h -> h_contact_details);
	CO_Rtv_DataString(p_param_data,"CONTACT_DETAILS1",p_ms_msglog_struct_h -> h_contact_details1);
	CO_Rtv_DataString(p_param_data,"BASEID",p_ms_msglog_struct_h -> h_baseid);
	CO_Rtv_DataString(p_param_data,"MESSAGE_CLASS",p_ms_msglog_struct_h -> h_message_class);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_IDENT",p_ms_msglog_struct_h -> h_swift_msg_ident);
}






int Populate_MS_MSGSTAT(MS_MSGSTAT_STRUCT_H *p_ms_msgstat_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROC_INIT",p_ms_msgstat_struct_h -> h_proc_init);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_REP",p_ms_msgstat_struct_h -> h_swift_msg_rep);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_msgstat_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"GENERATE_DT",p_ms_msgstat_struct_h -> h_generate_dt);
}






int Populate_MS_MSG_SETL_VEW(MS_MSG_SETL_VEW_STRUCT_H *p_ms_msg_setl_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DATE_OF_INPUT",p_ms_msg_setl_vew_struct_h -> h_date_of_input);
	CO_Rtv_DataString(p_param_data,"MSG_IN_OUT_IND",p_ms_msg_setl_vew_struct_h -> h_msg_in_out_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_msg_setl_vew_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"INFORMATION",p_ms_msg_setl_vew_struct_h -> h_information);
	CO_Rtv_DataInt(p_param_data,"DEAL_NO",(int *) &(p_ms_msg_setl_vew_struct_h -> h_deal_no));
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_A",p_ms_msg_setl_vew_struct_h -> h_message_det_a);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_B",p_ms_msg_setl_vew_struct_h -> h_message_det_b);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_C",p_ms_msg_setl_vew_struct_h -> h_message_det_c);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_D",p_ms_msg_setl_vew_struct_h -> h_message_det_d);
	CO_Rtv_DataString(p_param_data,"MESSAGE_DET_E",p_ms_msg_setl_vew_struct_h -> h_message_det_e);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_ms_msg_setl_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_ms_msg_setl_vew_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_RF_IDENT_NO",p_ms_msg_setl_vew_struct_h -> h_deal_rf_ident_no);
	CO_Rtv_DataString(p_param_data,"REJECT_REASON",p_ms_msg_setl_vew_struct_h -> h_reject_reason);
	CO_Rtv_DataString(p_param_data,"REPORT_DT",p_ms_msg_setl_vew_struct_h -> h_report_dt);
	CO_Rtv_DataString(p_param_data,"REPORT_IND",p_ms_msg_setl_vew_struct_h -> h_report_ind);
	CO_Rtv_DataString(p_param_data,"MESSAGE_STAT",p_ms_msg_setl_vew_struct_h -> h_message_stat);
	CO_Rtv_DataString(p_param_data,"CURRENT_DATE",p_ms_msg_setl_vew_struct_h -> h_current_date);
}






int Populate_MS_SEQUENCEMAP(MS_SEQUENCEMAP_STRUCT_H *p_ms_sequencemap_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SWIFT_MSG_NO",p_ms_sequencemap_struct_h -> h_swift_msg_no);
	CO_Rtv_DataString(p_param_data,"MESSAGE_CLASS",p_ms_sequencemap_struct_h -> h_message_class);
	CO_Rtv_DataInt(p_param_data,"IDENTITY_NO",(int *) &(p_ms_sequencemap_struct_h -> h_identity_no));
	CO_Rtv_DataString(p_param_data,"SEQ_IND",p_ms_sequencemap_struct_h -> h_seq_ind);
	CO_Rtv_DataInt(p_param_data,"PAR_SEQNO",(int *) &(p_ms_sequencemap_struct_h -> h_par_seqno));
	CO_Rtv_DataString(p_param_data,"SEQ_CONDITION",p_ms_sequencemap_struct_h -> h_seq_condition);
}






int Populate_MT_ARCHDLYMKTPRC(MT_ARCHDLYMKTPRC_STRUCT_H *p_mt_archdlymktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mt_archdlymktprc_struct_h -> h_price_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_archdlymktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_archdlymktprc_struct_h -> h_closing_pr));
	CO_Rtv_DataString(p_param_data,"MODIFYMODE",p_mt_archdlymktprc_struct_h -> h_modifymode);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_archdlymktprc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_archdlymktprc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"MRKTPR_STAT",p_mt_archdlymktprc_struct_h -> h_mrktpr_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_archdlymktprc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_archdlymktprc_struct_h -> h_checker_dt);
}






int Populate_MT_CLIENT(MT_CLIENT_STRUCT_H *p_mt_client_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_client_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_CURRENCY",p_mt_client_struct_h -> h_cln_currency);
	CO_Rtv_DataString(p_param_data,"CLN_OUR_THEIR_IND",p_mt_client_struct_h -> h_cln_our_their_ind);
	CO_Rtv_DataString(p_param_data,"CLN_ISCC_IND",p_mt_client_struct_h -> h_cln_iscc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_USE_ISIN_IND",p_mt_client_struct_h -> h_cln_use_isin_ind);
	CO_Rtv_DataString(p_param_data,"CLN_TYPE",p_mt_client_struct_h -> h_cln_type);
	CO_Rtv_DataString(p_param_data,"CLN_REG_NAME",p_mt_client_struct_h -> h_cln_reg_name);
	CO_Rtv_DataString(p_param_data,"CLN_CLAS",p_mt_client_struct_h -> h_cln_clas);
	CO_Rtv_DataString(p_param_data,"CLN_BILLABLEIND",p_mt_client_struct_h -> h_cln_billableind);
	CO_Rtv_DataString(p_param_data,"CLN_CLASS",p_mt_client_struct_h -> h_cln_class);
	CO_Rtv_DataString(p_param_data,"CLN_VTB_CLIENT",p_mt_client_struct_h -> h_cln_vtb_client);
	CO_Rtv_DataString(p_param_data,"CLN_REG",p_mt_client_struct_h -> h_cln_reg);
	CO_Rtv_DataString(p_param_data,"CLN_MEMO",p_mt_client_struct_h -> h_cln_memo);
	CO_Rtv_DataString(p_param_data,"CLN_INTERNAL",p_mt_client_struct_h -> h_cln_internal);
	CO_Rtv_DataString(p_param_data,"CLN_POS_DT",p_mt_client_struct_h -> h_cln_pos_dt);
	CO_Rtv_DataString(p_param_data,"CLN_BASE_ID",p_mt_client_struct_h -> h_cln_base_id);
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_SWF_MON",(int *) &(p_mt_client_struct_h -> h_cln_count_swf_mon));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_TLX_MON",(int *) &(p_mt_client_struct_h -> h_cln_count_tlx_mon));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_SWF_YR",(int *) &(p_mt_client_struct_h -> h_cln_count_swf_yr));
	CO_Rtv_DataInt(p_param_data,"CLN_COUNT_TLX_YR",(int *) &(p_mt_client_struct_h -> h_cln_count_tlx_yr));
	CO_Rtv_DataString(p_param_data,"CLN_MASTER",p_mt_client_struct_h -> h_cln_master);
	CO_Rtv_DataString(p_param_data,"CLN_NAME",p_mt_client_struct_h -> h_cln_name);
	CO_Rtv_DataString(p_param_data,"CLN_GL_ACCOUNT",p_mt_client_struct_h -> h_cln_gl_account);
	CO_Rtv_DataString(p_param_data,"CLN_BRK_ALL",p_mt_client_struct_h -> h_cln_brk_all);
	CO_Rtv_DataString(p_param_data,"CLN_SHORTNM",p_mt_client_struct_h -> h_cln_shortnm);
	CO_Rtv_DataString(p_param_data,"CLN_ORD_CLT",p_mt_client_struct_h -> h_cln_ord_clt);
	CO_Rtv_DataString(p_param_data,"CLN_SPOT_DL_IND",p_mt_client_struct_h -> h_cln_spot_dl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_SELL_IND",p_mt_client_struct_h -> h_cln_fx_sell_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_BUY_IND",p_mt_client_struct_h -> h_cln_fx_buy_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_INC_IND",p_mt_client_struct_h -> h_cln_fx_inc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DATEOF_INPUT",p_mt_client_struct_h -> h_cln_dateof_input);
	CO_Rtv_DataString(p_param_data,"CLN_BRNCHCODE",p_mt_client_struct_h -> h_cln_brnchcode);
	CO_Rtv_DataString(p_param_data,"COUNTRY",p_mt_client_struct_h -> h_country);
	CO_Rtv_DataString(p_param_data,"CLN_FMT_RPTIND",p_mt_client_struct_h -> h_cln_fmt_rptind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_client_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_client_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_client_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_client_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_client_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"CLN_UNIQ_GCUSTODY_ID",p_mt_client_struct_h -> h_cln_uniq_gcustody_id);
	CO_Rtv_DataString(p_param_data,"CLN_CLTPROD_CD",p_mt_client_struct_h -> h_cln_cltprod_cd);
	CO_Rtv_DataString(p_param_data,"CLN_DOMICILE",p_mt_client_struct_h -> h_cln_domicile);
	CO_Rtv_DataString(p_param_data,"CLN_PARTIAL_IND",p_mt_client_struct_h -> h_cln_partial_ind);
	CO_Rtv_DataString(p_param_data,"CLN_ALLOW_REGIND",p_mt_client_struct_h -> h_cln_allow_regind);
	CO_Rtv_DataString(p_param_data,"CLN_REG_SETL_IND",p_mt_client_struct_h -> h_cln_reg_setl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_REG_BCL_IND",p_mt_client_struct_h -> h_cln_reg_bcl_ind);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_client_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"CLN_CLH",p_mt_client_struct_h -> h_cln_clh);
	CO_Rtv_DataString(p_param_data,"CLN_TAXABLE_IND",p_mt_client_struct_h -> h_cln_taxable_ind);
	CO_Rtv_DataString(p_param_data,"CLN_BRK_CD",p_mt_client_struct_h -> h_cln_brk_cd);
	CO_Rtv_DataString(p_param_data,"CLN_TAX_ID",p_mt_client_struct_h -> h_cln_tax_id);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_1",p_mt_client_struct_h -> h_cln_add_1);
	CO_Rtv_DataString(p_param_data,"CLN_EXT_CLH",p_mt_client_struct_h -> h_cln_ext_clh);
	CO_Rtv_DataString(p_param_data,"CLN_GRP",p_mt_client_struct_h -> h_cln_grp);
	CO_Rtv_DataString(p_param_data,"CLN_SAT_OPER_CD",p_mt_client_struct_h -> h_cln_sat_oper_cd);
	CO_Rtv_DataInt(p_param_data,"CLN_TOLERANCE",(int *) &(p_mt_client_struct_h -> h_cln_tolerance));
	CO_Rtv_DataString(p_param_data,"CLN_AUTHBUNCH_IND",p_mt_client_struct_h -> h_cln_authbunch_ind);
	CO_Rtv_DataString(p_param_data,"CLN_FX_BUY_CCY",p_mt_client_struct_h -> h_cln_fx_buy_ccy);
	CO_Rtv_DataString(p_param_data,"CLN_FX_SELL_CCY",p_mt_client_struct_h -> h_cln_fx_sell_ccy);
	CO_Rtv_DataString(p_param_data,"CLN_SINGLE548_SUPPORT_IND",p_mt_client_struct_h -> h_cln_single548_support_ind);
	CO_Rtv_DataString(p_param_data,"CLN_STAT_DL_IND",p_mt_client_struct_h -> h_cln_stat_dl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DEAL_SETL_IND",p_mt_client_struct_h -> h_cln_deal_setl_ind);
	CO_Rtv_DataString(p_param_data,"CLN_RHTS_RET",p_mt_client_struct_h -> h_cln_rhts_ret);
	CO_Rtv_DataString(p_param_data,"CLN_VALCREDIT",p_mt_client_struct_h -> h_cln_valcredit);
	CO_Rtv_DataString(p_param_data,"CLN_FRACT_IND",p_mt_client_struct_h -> h_cln_fract_ind);
	CO_Rtv_DataString(p_param_data,"CLN_AUTO_CANC_IND",p_mt_client_struct_h -> h_cln_auto_canc_ind);
	CO_Rtv_DataString(p_param_data,"CLN_DESC",p_mt_client_struct_h -> h_cln_desc);
	CO_Rtv_DataString(p_param_data,"CLN_GENERATE_IND",p_mt_client_struct_h -> h_cln_generate_ind);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_2",p_mt_client_struct_h -> h_cln_add_2);
	CO_Rtv_DataString(p_param_data,"CITY",p_mt_client_struct_h -> h_city);
	CO_Rtv_DataString(p_param_data,"STATE",p_mt_client_struct_h -> h_state);
	CO_Rtv_DataString(p_param_data,"CLN_ADD_PIN",p_mt_client_struct_h -> h_cln_add_pin);
	CO_Rtv_DataString(p_param_data,"CLN_TEL",p_mt_client_struct_h -> h_cln_tel);
	CO_Rtv_DataString(p_param_data,"CLN_FAX",p_mt_client_struct_h -> h_cln_fax);
	CO_Rtv_DataString(p_param_data,"CLN_EMAIL",p_mt_client_struct_h -> h_cln_email);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT1",p_mt_client_struct_h -> h_cln_contact1);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT2",p_mt_client_struct_h -> h_cln_contact2);
	CO_Rtv_DataString(p_param_data,"CLN_SEBICTG",p_mt_client_struct_h -> h_cln_sebictg);
	CO_Rtv_DataString(p_param_data,"CLN_PAN",p_mt_client_struct_h -> h_cln_pan);
	CO_Rtv_DataDbl(p_param_data,"CLN_TDS_RT",&(p_mt_client_struct_h -> h_cln_tds_rt));
	CO_Rtv_DataString(p_param_data,"CLN_GLB_CUST",p_mt_client_struct_h -> h_cln_glb_cust);
	CO_Rtv_DataString(p_param_data,"CLN_START_DL",p_mt_client_struct_h -> h_cln_start_dl);
	CO_Rtv_DataString(p_param_data,"CLN_BCN_REQD",p_mt_client_struct_h -> h_cln_bcn_reqd);
	CO_Rtv_DataString(p_param_data,"CLN_DEF_CR_AGENCY",p_mt_client_struct_h -> h_cln_def_cr_agency);
	CO_Rtv_DataString(p_param_data,"CLN_CUST_IDENT",p_mt_client_struct_h -> h_cln_cust_ident);
	CO_Rtv_DataInt(p_param_data,"CLN_MST_IND",(int *) &(p_mt_client_struct_h -> h_cln_mst_ind));
	CO_Rtv_DataString(p_param_data,"CLN_SIGN_MEMO",p_mt_client_struct_h -> h_cln_sign_memo);
	 /* Ramya - start */
    CO_Rtv_DataString(p_param_data,"CLN_SEBI_SUBCAT",p_mt_client_struct_h -> h_cln_sebi_subcat);
    CO_Rtv_DataString(p_param_data,"CLN_COUNTRY",p_mt_client_struct_h -> h_cln_country);
    CO_Rtv_DataString(p_param_data,"CLNCITY_DESC",p_mt_client_struct_h -> h_clncity_desc);
        /* Ramya - end */
	
}





/*
int Populate_MT_CLIENTLST_VEW(MT_CLIENTLST_VEW_STRUCT_H *p_mt_clientlst_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


*/



int Populate_MT_CLIENT_DEPO(MT_CLIENT_DEPO_STRUCT_H *p_mt_client_depo_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_mt_client_depo_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_client_depo_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"SAFEKEEP_POS",(int *) &(p_mt_client_depo_struct_h -> h_safekeep_pos));
}






int Populate_MT_CLIENT_ENTRIES(MT_CLIENT_ENTRIES_STRUCT_H *p_mt_client_entries_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_client_entries_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_client_entries_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_client_entries_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STX_CLIENT",p_mt_client_entries_struct_h -> h_stx_client);
	CO_Rtv_DataString(p_param_data,"COMM_CLT",p_mt_client_entries_struct_h -> h_comm_clt);
	CO_Rtv_DataString(p_param_data,"TPAY_CLIENT",p_mt_client_entries_struct_h -> h_tpay_client);
	CO_Rtv_DataString(p_param_data,"TEXP_CLIENT",p_mt_client_entries_struct_h -> h_texp_client);
	CO_Rtv_DataString(p_param_data,"CUSTODY_CLT",p_mt_client_entries_struct_h -> h_custody_clt);
}






int Populate_MT_CLI_DEPO_MAP(MT_CLI_DEPO_MAP_STRUCT_H *p_mt_cli_depo_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_cli_depo_map_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_DEPO_CODE",p_mt_cli_depo_map_struct_h -> h_cln_depo_code);
	CO_Rtv_DataString(p_param_data,"CLN_DEPO_MAP_CLIENT_ID",p_mt_cli_depo_map_struct_h -> h_cln_depo_map_client_id);
	CO_Rtv_DataString(p_param_data,"CLN_DEPO_MAP_DP_ID",p_mt_cli_depo_map_struct_h -> h_cln_depo_map_dp_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cli_depo_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cli_depo_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cli_depo_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cli_depo_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cli_depo_map_struct_h -> h_checker_dt);
	CO_Rtv_DataInt(p_param_data,"CLN_SEQ_NUM",(int *) &(p_mt_cli_depo_map_struct_h -> h_cln_seq_num));
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cli_depo_map_struct_h -> h_status);
}






int Populate_MT_CLI_EXCH_MAP(MT_CLI_EXCH_MAP_STRUCT_H *p_mt_cli_exch_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_cli_exch_map_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_EXCH_CODE",p_mt_cli_exch_map_struct_h -> h_cln_exch_code);
	CO_Rtv_DataString(p_param_data,"CLN_EXCH_MAP_CODE",p_mt_cli_exch_map_struct_h -> h_cln_exch_map_code);
	CO_Rtv_DataString(p_param_data,"CLN_HDFC_CM_ID",p_mt_cli_exch_map_struct_h -> h_cln_hdfc_cm_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cli_exch_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cli_exch_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cli_exch_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cli_exch_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cli_exch_map_struct_h -> h_checker_dt);
	CO_Rtv_DataInt(p_param_data,"CLN_SEQ_NUM",(int *) &(p_mt_cli_exch_map_struct_h -> h_cln_seq_num));
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cli_exch_map_struct_h -> h_status);
}






int Populate_MT_CLN_INST_MAP(MT_CLN_INST_MAP_STRUCT_H *p_mt_cln_inst_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_cln_inst_map_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_cln_inst_map_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CLN_INSTR_CODE",p_mt_cln_inst_map_struct_h -> h_cln_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cln_inst_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cln_inst_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cln_inst_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cln_inst_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cln_inst_map_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cln_inst_map_struct_h -> h_status);
}






int Populate_MT_CLTDEPO(MT_CLTDEPO_STRUCT_H *p_mt_cltdepo_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_mt_cltdepo_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DEPO_LOC",p_mt_cltdepo_struct_h -> h_depo_loc);
	CO_Rtv_DataString(p_param_data,"CLIENT_TYPE",p_mt_cltdepo_struct_h -> h_client_type);
	CO_Rtv_DataString(p_param_data,"SEGR_CLIENT_NO",p_mt_cltdepo_struct_h -> h_segr_client_no);
	CO_Rtv_DataString(p_param_data,"AGREE_ID",p_mt_cltdepo_struct_h -> h_agree_id);
	CO_Rtv_DataString(p_param_data,"DATE_AGREE",p_mt_cltdepo_struct_h -> h_date_agree);
	CO_Rtv_DataString(p_param_data,"DEPO_BR_CD",p_mt_cltdepo_struct_h -> h_depo_br_cd);
	CO_Rtv_DataString(p_param_data,"DEPO_GL_CLT",p_mt_cltdepo_struct_h -> h_depo_gl_clt);
	CO_Rtv_DataString(p_param_data,"DEPO_CLT",p_mt_cltdepo_struct_h -> h_depo_clt);
	CO_Rtv_DataString(p_param_data,"REG_CERT_NO",p_mt_cltdepo_struct_h -> h_reg_cert_no);
	CO_Rtv_DataString(p_param_data,"REG_CERT_SER",p_mt_cltdepo_struct_h -> h_reg_cert_ser);
	CO_Rtv_DataString(p_param_data,"REG_CERT_DATE",p_mt_cltdepo_struct_h -> h_reg_cert_date);
	CO_Rtv_DataString(p_param_data,"ISSUE_AUTHORITY",p_mt_cltdepo_struct_h -> h_issue_authority);
}






int Populate_MT_COMMON_SYS_PARAMS(MT_COMMON_SYS_PARAMS_STRUCT_H *p_mt_common_sys_params_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CA_IDENTNAME",p_mt_common_sys_params_struct_h -> h_ca_identname);
	CO_Rtv_DataString(p_param_data,"CA_ADDRESS",p_mt_common_sys_params_struct_h -> h_ca_address);
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_mt_common_sys_params_struct_h -> h_nation_code);
	CO_Rtv_DataString(p_param_data,"BRNCH_CD",p_mt_common_sys_params_struct_h -> h_brnch_cd);
	CO_Rtv_DataString(p_param_data,"DOM_CCY",p_mt_common_sys_params_struct_h -> h_dom_ccy);
	CO_Rtv_DataString(p_param_data,"DOM_INSTRUMENT",p_mt_common_sys_params_struct_h -> h_dom_instrument);
	CO_Rtv_DataString(p_param_data,"GL_INTERFACE_MOD_IND",p_mt_common_sys_params_struct_h -> h_gl_interface_mod_ind);
	CO_Rtv_DataString(p_param_data,"BILL_MODULE_IND",p_mt_common_sys_params_struct_h -> h_bill_module_ind);
	CO_Rtv_DataString(p_param_data,"CA_MODULE_IND",p_mt_common_sys_params_struct_h -> h_ca_module_ind);
	CO_Rtv_DataString(p_param_data,"F_FILE_PATH",p_mt_common_sys_params_struct_h -> h_f_file_path);
	CO_Rtv_DataString(p_param_data,"B_FILE_PATH",p_mt_common_sys_params_struct_h -> h_b_file_path);
	CO_Rtv_DataInt(p_param_data,"MONTHSFOR_ARCH",(int *) &(p_mt_common_sys_params_struct_h -> h_monthsfor_arch));
	CO_Rtv_DataString(p_param_data,"EI_SMI_IND",p_mt_common_sys_params_struct_h -> h_ei_smi_ind);
	CO_Rtv_DataString(p_param_data,"CCS_IND",p_mt_common_sys_params_struct_h -> h_ccs_ind);
	CO_Rtv_DataString(p_param_data,"OFFICE_FOR_BOOKING",p_mt_common_sys_params_struct_h -> h_office_for_booking);
}






int Populate_MT_COMPANY(MT_COMPANY_STRUCT_H *p_mt_company_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CMP_CODE",p_mt_company_struct_h -> h_cmp_code);
	CO_Rtv_DataString(p_param_data,"CMP_NAME",p_mt_company_struct_h -> h_cmp_name);
	CO_Rtv_DataString(p_param_data,"CMP_SHORTNM",p_mt_company_struct_h -> h_cmp_shortnm);
	CO_Rtv_DataString(p_param_data,"CMP_OLDNAME",p_mt_company_struct_h -> h_cmp_oldname);
	CO_Rtv_DataString(p_param_data,"CMP_ADD1",p_mt_company_struct_h -> h_cmp_add1);
	CO_Rtv_DataString(p_param_data,"CMP_ADD2",p_mt_company_struct_h -> h_cmp_add2);
	CO_Rtv_DataString(p_param_data,"CITY",p_mt_company_struct_h -> h_city);
	CO_Rtv_DataString(p_param_data,"STATE",p_mt_company_struct_h -> h_state);
	CO_Rtv_DataString(p_param_data,"COUNTRY",p_mt_company_struct_h -> h_country);
	CO_Rtv_DataString(p_param_data,"CMP_ADD_PIN",p_mt_company_struct_h -> h_cmp_add_pin);
	CO_Rtv_DataString(p_param_data,"CMP_TEL",p_mt_company_struct_h -> h_cmp_tel);
	CO_Rtv_DataString(p_param_data,"CMP_FAX",p_mt_company_struct_h -> h_cmp_fax);
	CO_Rtv_DataString(p_param_data,"CMP_WEBADD",p_mt_company_struct_h -> h_cmp_webadd);
	CO_Rtv_DataString(p_param_data,"CMP_SWF_NAME",p_mt_company_struct_h -> h_cmp_swf_name);
	CO_Rtv_DataString(p_param_data,"CMP_SECNM",p_mt_company_struct_h -> h_cmp_secnm);
	CO_Rtv_DataString(p_param_data,"CMP_SEC_EMAIL",p_mt_company_struct_h -> h_cmp_sec_email);
	CO_Rtv_DataString(p_param_data,"CMP_MDNM",p_mt_company_struct_h -> h_cmp_mdnm);
	CO_Rtv_DataString(p_param_data,"CMP_INDUSTRYCD",p_mt_company_struct_h -> h_cmp_industrycd);
	CO_Rtv_DataString(p_param_data,"CMP_SECTORCD",p_mt_company_struct_h -> h_cmp_sectorcd);
	CO_Rtv_DataString(p_param_data,"CMP_REMARKS",p_mt_company_struct_h -> h_cmp_remarks);
	CO_Rtv_DataDbl(p_param_data,"CMP_AUTHCAPITAL",&(p_mt_company_struct_h -> h_cmp_authcapital));
	CO_Rtv_DataDbl(p_param_data,"CMP_ISSUEDCAPITAL",&(p_mt_company_struct_h -> h_cmp_issuedcapital));
	CO_Rtv_DataDbl(p_param_data,"CMP_TPCAPITAL",&(p_mt_company_struct_h -> h_cmp_tpcapital));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_company_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_company_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_company_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_company_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_company_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_company_struct_h -> h_status);
}






/*int Populate_MT_CORE_SYS_PARAMS(MT_CORE_SYS_PARAMS_STRUCT_H *p_mt_core_sys_params_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PART_CONFIRM",p_mt_core_sys_params_struct_h -> h_part_confirm);
	CO_Rtv_DataString(p_param_data,"MANIFLD_PRINT_IND",p_mt_core_sys_params_struct_h -> h_manifld_print_ind);
	CO_Rtv_DataString(p_param_data,"PROC_SPOT_DL_IND",p_mt_core_sys_params_struct_h -> h_proc_spot_dl_ind);
	CO_Rtv_DataString(p_param_data,"GSETL_IND",p_mt_core_sys_params_struct_h -> h_gsetl_ind);
	CO_Rtv_DataString(p_param_data,"SUB_CLT_PROC",p_mt_core_sys_params_struct_h -> h_sub_clt_proc);
	CO_Rtv_DataString(p_param_data,"ORD_PROC_IND",p_mt_core_sys_params_struct_h -> h_ord_proc_ind);
	CO_Rtv_DataString(p_param_data,"NO_STXDL_IND",p_mt_core_sys_params_struct_h -> h_no_stxdl_ind);
	CO_Rtv_DataString(p_param_data,"LOC_PROC_IND",p_mt_core_sys_params_struct_h -> h_loc_proc_ind);
	CO_Rtv_DataString(p_param_data,"AE_IND",p_mt_core_sys_params_struct_h -> h_ae_ind);
	CO_Rtv_DataString(p_param_data,"PROC_PR_FEED_IND",p_mt_core_sys_params_struct_h -> h_proc_pr_feed_ind);
	CO_Rtv_DataString(p_param_data,"DIR_INDIR_FXQT_IND",p_mt_core_sys_params_struct_h -> h_dir_indir_fxqt_ind);
	CO_Rtv_DataString(p_param_data,"PROC_REG_IND",p_mt_core_sys_params_struct_h -> h_proc_reg_ind);
	CO_Rtv_DataString(p_param_data,"PART_REG_IND",p_mt_core_sys_params_struct_h -> h_part_reg_ind);
	CO_Rtv_DataInt(p_param_data,"AMOUNT_DECIMAL_LEN",(int *) &(p_mt_core_sys_params_struct_h -> h_amount_decimal_len));
	CO_Rtv_DataInt(p_param_data,"QTY_DEC_LEN",(int *) &(p_mt_core_sys_params_struct_h -> h_qty_dec_len));
	CO_Rtv_DataInt(p_param_data,"MIN_CLT_LEN",(int *) &(p_mt_core_sys_params_struct_h -> h_min_clt_len));
	CO_Rtv_DataInt(p_param_data,"ALLOWED_AMTDIFF",(int *) &(p_mt_core_sys_params_struct_h -> h_allowed_amtdiff));
	CO_Rtv_DataInt(p_param_data,"AUTO_INACTIVE_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_auto_inactive_days));
	CO_Rtv_DataInt(p_param_data,"ODD_LOT_QTY",(int *) &(p_mt_core_sys_params_struct_h -> h_odd_lot_qty));
	CO_Rtv_DataInt(p_param_data,"PROC_START_NO",(int *) &(p_mt_core_sys_params_struct_h -> h_proc_start_no));
	CO_Rtv_DataInt(p_param_data,"END_PROC_NO",(int *) &(p_mt_core_sys_params_struct_h -> h_end_proc_no));
	CO_Rtv_DataDbl(p_param_data,"CUSTODY_TAX_RT",&(p_mt_core_sys_params_struct_h -> h_custody_tax_rt));
	CO_Rtv_DataDbl(p_param_data,"FX_TAX_RT",&(p_mt_core_sys_params_struct_h -> h_fx_tax_rt));
	CO_Rtv_DataDbl(p_param_data,"COMM_TAX_RT",&(p_mt_core_sys_params_struct_h -> h_comm_tax_rt));
	CO_Rtv_DataDbl(p_param_data,"PAIDUPCAPITAL_LIMIT",&(p_mt_core_sys_params_struct_h -> h_paidupcapital_limit));
	CO_Rtv_DataString(p_param_data,"OP_OTH_STX_ERROR",p_mt_core_sys_params_struct_h -> h_op_oth_stx_error);
	CO_Rtv_DataString(p_param_data,"OP_OTH_TRD_ERROR",p_mt_core_sys_params_struct_h -> h_op_oth_trd_error);
	CO_Rtv_DataInt(p_param_data,"STX_REC_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_stx_rec_dl_days));
	CO_Rtv_DataInt(p_param_data,"STX_DEL_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_stx_del_dl_days));
	CO_Rtv_DataInt(p_param_data,"OTH_REC_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_oth_rec_dl_days));
	CO_Rtv_DataInt(p_param_data,"OTH_DEL_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_oth_del_dl_days));
	CO_Rtv_DataInt(p_param_data,"SPOT_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_spot_dl_days));
	CO_Rtv_DataInt(p_param_data,"SPOT_OTH_DL_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_spot_oth_dl_days));
	CO_Rtv_DataString(p_param_data,"CUSTODY_CLT_CD",p_mt_core_sys_params_struct_h -> h_custody_clt_cd);
	CO_Rtv_DataString(p_param_data,"BROKERAGE_CD",p_mt_core_sys_params_struct_h -> h_brokerage_cd);
	CO_Rtv_DataString(p_param_data,"BRNCH_USD_CLT",p_mt_core_sys_params_struct_h -> h_brnch_usd_clt);
	CO_Rtv_DataString(p_param_data,"VTB_CLT_CODE",p_mt_core_sys_params_struct_h -> h_vtb_clt_code);
	CO_Rtv_DataString(p_param_data,"VTB_CLT_NAME",p_mt_core_sys_params_struct_h -> h_vtb_clt_name);
	CO_Rtv_DataString(p_param_data,"VTB_IDENTITY",p_mt_core_sys_params_struct_h -> h_vtb_identity);
	CO_Rtv_DataString(p_param_data,"VDP_IND",p_mt_core_sys_params_struct_h -> h_vdp_ind);
	CO_Rtv_DataDbl(p_param_data,"CUSTODY_COMM_RT",&(p_mt_core_sys_params_struct_h -> h_custody_comm_rt));
	CO_Rtv_DataDbl(p_param_data,"STK_EXG_COMM_RT",&(p_mt_core_sys_params_struct_h -> h_stk_exg_comm_rt));
	CO_Rtv_DataString(p_param_data,"MS_53X_ONLINE_EOD_IND",p_mt_core_sys_params_struct_h -> h_ms_53x_online_eod_ind);
	CO_Rtv_DataInt(p_param_data,"AUCTION_DATE_DAYS",(int *) &(p_mt_core_sys_params_struct_h -> h_auction_date_days));
}
*/






int Populate_MT_CR_AGENCY(MT_CR_AGENCY_STRUCT_H *p_mt_cr_agency_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"AGENCY_CODE",p_mt_cr_agency_struct_h -> h_agency_code);
	CO_Rtv_DataString(p_param_data,"AGENCY_NAME",p_mt_cr_agency_struct_h -> h_agency_name);
	CO_Rtv_DataString(p_param_data,"AGENCY_ADD_1",p_mt_cr_agency_struct_h -> h_agency_add_1);
	CO_Rtv_DataString(p_param_data,"AGENCY_ADD_2",p_mt_cr_agency_struct_h -> h_agency_add_2);
	CO_Rtv_DataString(p_param_data,"CITY",p_mt_cr_agency_struct_h -> h_city);
	CO_Rtv_DataString(p_param_data,"STATE",p_mt_cr_agency_struct_h -> h_state);
	CO_Rtv_DataString(p_param_data,"COUNTRY",p_mt_cr_agency_struct_h -> h_country);
	CO_Rtv_DataString(p_param_data,"AGENCY_ADD_PIN",p_mt_cr_agency_struct_h -> h_agency_add_pin);
	CO_Rtv_DataString(p_param_data,"AGENCY_TEL",p_mt_cr_agency_struct_h -> h_agency_tel);
	CO_Rtv_DataString(p_param_data,"AGENCY_FAX",p_mt_cr_agency_struct_h -> h_agency_fax);
	CO_Rtv_DataString(p_param_data,"AGENCY_EMAIL",p_mt_cr_agency_struct_h -> h_agency_email);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cr_agency_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cr_agency_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cr_agency_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cr_agency_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cr_agency_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cr_agency_struct_h -> h_status);
}






int Populate_MT_CR_AGENCY_DET(MT_CR_AGENCY_DET_STRUCT_H *p_mt_cr_agency_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"AGENCY_CODE",p_mt_cr_agency_det_struct_h -> h_agency_code);
	CO_Rtv_DataString(p_param_data,"RATING_CODE",p_mt_cr_agency_det_struct_h -> h_rating_code);
	CO_Rtv_DataString(p_param_data,"RATING_DESC",p_mt_cr_agency_det_struct_h -> h_rating_desc);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cr_agency_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cr_agency_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cr_agency_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cr_agency_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cr_agency_det_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cr_agency_det_struct_h -> h_access_stamp);
	CO_Rtv_DataInt(p_param_data,"CR_SEQ_NUM",(int *) &(p_mt_cr_agency_det_struct_h -> h_cr_seq_num));
}






int Populate_MT_CR_AGENCY_DET_BKUP(MT_CR_AGENCY_DET_BKUP_STRUCT_H *p_mt_cr_agency_det_bkup_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"AGENCY_CODE",p_mt_cr_agency_det_bkup_struct_h -> h_agency_code);
	CO_Rtv_DataString(p_param_data,"RATING_CODE",p_mt_cr_agency_det_bkup_struct_h -> h_rating_code);
	CO_Rtv_DataString(p_param_data,"RATING_DESC",p_mt_cr_agency_det_bkup_struct_h -> h_rating_desc);
}






int Populate_MT_DAILY_FLOAT_RATE(MT_DAILY_FLOAT_RATE_STRUCT_H *p_mt_daily_float_rate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"BENCHMARK_CODE",p_mt_daily_float_rate_struct_h -> h_benchmark_code);
	CO_Rtv_DataString(p_param_data,"RATE_DATE",p_mt_daily_float_rate_struct_h -> h_rate_date);
	CO_Rtv_DataDbl(p_param_data,"FLOAT_RATE",&(p_mt_daily_float_rate_struct_h -> h_float_rate));
	CO_Rtv_DataDbl(p_param_data,"STD_DEVIATION",&(p_mt_daily_float_rate_struct_h -> h_std_deviation));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_daily_float_rate_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_daily_float_rate_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_daily_float_rate_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_daily_float_rate_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_daily_float_rate_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_daily_float_rate_struct_h -> h_status);
}






int Populate_MT_DAILY_QUOT(MT_DAILY_QUOT_STRUCT_H *p_mt_daily_quot_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_daily_quot_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_daily_quot_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"QUOT_DATE",p_mt_daily_quot_struct_h -> h_quot_date);
	CO_Rtv_DataDbl(p_param_data,"QUOT_PREV_DATE",&(p_mt_daily_quot_struct_h -> h_quot_prev_date));
	CO_Rtv_DataDbl(p_param_data,"OPEN_AT",&(p_mt_daily_quot_struct_h -> h_open_at));
	CO_Rtv_DataDbl(p_param_data,"HIGH_AT",&(p_mt_daily_quot_struct_h -> h_high_at));
	CO_Rtv_DataDbl(p_param_data,"LOW_AT",&(p_mt_daily_quot_struct_h -> h_low_at));
	CO_Rtv_DataDbl(p_param_data,"CLOSE_AT",&(p_mt_daily_quot_struct_h -> h_close_at));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_daily_quot_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_daily_quot_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_daily_quot_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_daily_quot_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_daily_quot_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_daily_quot_struct_h -> h_status);
}






int Populate_MT_DEPO_PART(MT_DEPO_PART_STRUCT_H *p_mt_depo_part_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_mt_depo_part_struct_h -> h_depo_code);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_CODE",p_mt_depo_part_struct_h -> h_depo_part_code);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_CONTACT",p_mt_depo_part_struct_h -> h_depo_part_contact);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_ADD1",p_mt_depo_part_struct_h -> h_depo_part_add1);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_ADD2",p_mt_depo_part_struct_h -> h_depo_part_add2);
	CO_Rtv_DataString(p_param_data,"CITY",p_mt_depo_part_struct_h -> h_city);
	CO_Rtv_DataString(p_param_data,"STATE",p_mt_depo_part_struct_h -> h_state);
	CO_Rtv_DataString(p_param_data,"COUNTRY",p_mt_depo_part_struct_h -> h_country);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_ADD_PIN",p_mt_depo_part_struct_h -> h_depo_part_add_pin);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_TEL",p_mt_depo_part_struct_h -> h_depo_part_tel);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_FAX",p_mt_depo_part_struct_h -> h_depo_part_fax);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_EMAIL",p_mt_depo_part_struct_h -> h_depo_part_email);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_depo_part_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_depo_part_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_depo_part_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_depo_part_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_depo_part_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_depo_part_struct_h -> h_status);
 CO_Rtv_DataString(p_param_data,"DEPO_NAME",p_mt_depo_part_struct_h -> h_depo_name); /* Depo Participant Name in Depo Participant Master - by Gouse */
}






int Populate_MT_DLYMKTPRC(MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mt_dlymktprc_struct_h -> h_price_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_dlymktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_dlymktprc_struct_h -> h_closing_pr));
	CO_Rtv_DataString(p_param_data,"MODIFYMODE",p_mt_dlymktprc_struct_h -> h_modifymode);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_dlymktprc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_dlymktprc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_dlymktprc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"MKRTPR_STAT",p_mt_dlymktprc_struct_h -> h_mkrtpr_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_dlymktprc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_dlymktprc_struct_h -> h_checker_dt);
}






int Populate_MT_EOMMTHLYMKTPRC(MT_EOMMTHLYMKTPRC_STRUCT_H *p_mt_eommthlymktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_eommthlymktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"OPEN_PR",&(p_mt_eommthlymktprc_struct_h -> h_open_pr));
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_eommthlymktprc_struct_h -> h_closing_pr));
}






int Populate_MT_EOMSYSDATE(MT_EOMSYSDATE_STRUCT_H *p_mt_eomsysdate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CURRENT_DATE",p_mt_eomsysdate_struct_h -> h_current_date);
	CO_Rtv_DataString(p_param_data,"EOD_IND",p_mt_eomsysdate_struct_h -> h_eod_ind);
}






int Populate_MT_EXCHRATE(MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_mt_exchrate_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"DENOM_CCY",p_mt_exchrate_struct_h -> h_denom_ccy);
	CO_Rtv_DataString(p_param_data,"RATE_DATE",p_mt_exchrate_struct_h -> h_rate_date);
	CO_Rtv_DataDbl(p_param_data,"EXCHGRT",&(p_mt_exchrate_struct_h -> h_exchgrt));
	CO_Rtv_DataDbl(p_param_data,"RATE_BUY",&(p_mt_exchrate_struct_h -> h_rate_buy));
	CO_Rtv_DataDbl(p_param_data,"SELL_RT",&(p_mt_exchrate_struct_h -> h_sell_rt));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_exchrate_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_exchrate_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_exchrate_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_exchrate_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_exchrate_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"EXCHG_STAT",p_mt_exchrate_struct_h -> h_exchg_stat);
}






int Populate_MT_FLRATE_INSTRUMENT(MT_FLRATE_INSTRUMENT_STRUCT_H *p_mt_flrate_instrument_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_flrate_instrument_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"RESET_OPTION",p_mt_flrate_instrument_struct_h -> h_reset_option);
	CO_Rtv_DataString(p_param_data,"DAILY_COMPOUND",p_mt_flrate_instrument_struct_h -> h_daily_compound);
	CO_Rtv_DataString(p_param_data,"EXCL_HOLIDAYS",p_mt_flrate_instrument_struct_h -> h_excl_holidays);
	CO_Rtv_DataInt(p_param_data,"INT_PAY_DAYS",(int *) &(p_mt_flrate_instrument_struct_h -> h_int_pay_days));
	CO_Rtv_DataString(p_param_data,"COMPOUNDING_WDAYS",p_mt_flrate_instrument_struct_h -> h_compounding_wdays);
	CO_Rtv_DataDbl(p_param_data,"FLOOR_RATE",&(p_mt_flrate_instrument_struct_h -> h_floor_rate));
	CO_Rtv_DataDbl(p_param_data,"CAP_RATE",&(p_mt_flrate_instrument_struct_h -> h_cap_rate));
	CO_Rtv_DataInt(p_param_data,"PREFD_SEQ",(int *) &(p_mt_flrate_instrument_struct_h -> h_prefd_seq));
	CO_Rtv_DataDbl(p_param_data,"BASE_MARGIN",&(p_mt_flrate_instrument_struct_h -> h_base_margin));
	CO_Rtv_DataString(p_param_data,"MIBOR_CODE",p_mt_flrate_instrument_struct_h -> h_mibor_code);
	CO_Rtv_DataString(p_param_data,"FIXED_BENCH",p_mt_flrate_instrument_struct_h -> h_fixed_bench);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_flrate_instrument_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_flrate_instrument_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_flrate_instrument_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_flrate_instrument_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_flrate_instrument_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_flrate_instrument_struct_h -> h_status);
}






int Populate_MT_GRPDETAILS(MT_GRPDETAILS_STRUCT_H *p_mt_grpdetails_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_TYPE",p_mt_grpdetails_struct_h -> h_cln_type);
	CO_Rtv_DataString(p_param_data,"CLN_EMAIL",p_mt_grpdetails_struct_h -> h_cln_email);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT1",p_mt_grpdetails_struct_h -> h_cln_contact1);
	CO_Rtv_DataString(p_param_data,"CLN_CONTACT2",p_mt_grpdetails_struct_h -> h_cln_contact2);
	CO_Rtv_DataString(p_param_data,"CLN_SEBICTG",p_mt_grpdetails_struct_h -> h_cln_sebictg);
	CO_Rtv_DataString(p_param_data,"CLN_PAN",p_mt_grpdetails_struct_h -> h_cln_pan);
	CO_Rtv_DataString(p_param_data,"CLN_DEF_CR_AGENCY",p_mt_grpdetails_struct_h -> h_cln_def_cr_agency);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_grpdetails_struct_h -> h_cln_code);
}






int Populate_MT_HISDLYMKTPRC(MT_HISDLYMKTPRC_STRUCT_H *p_mt_hisdlymktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mt_hisdlymktprc_struct_h -> h_price_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_hisdlymktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_hisdlymktprc_struct_h -> h_closing_pr));
	CO_Rtv_DataString(p_param_data,"MODIFYMODE",p_mt_hisdlymktprc_struct_h -> h_modifymode);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_hisdlymktprc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_hisdlymktprc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"MKRTPR_STAT",p_mt_hisdlymktprc_struct_h -> h_mkrtpr_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_hisdlymktprc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_hisdlymktprc_struct_h -> h_checker_dt);
}






int Populate_MT_HOLIDAY(MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"HOLIDAY_AT",p_mt_holiday_struct_h -> h_holiday_at);
	CO_Rtv_DataString(p_param_data,"HOLIDAY_DATE",p_mt_holiday_struct_h -> h_holiday_date);
	CO_Rtv_DataString(p_param_data,"HOLIDAY_REAS",p_mt_holiday_struct_h -> h_holiday_reas);
	CO_Rtv_DataString(p_param_data,"HOLIDAY_TYPE",p_mt_holiday_struct_h -> h_holiday_type);
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_holiday_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_holiday_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_holiday_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_holiday_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_holiday_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_holiday_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_holiday_struct_h -> h_status);
}






int Populate_MT_IDENTMNT(MT_IDENTMNT_STRUCT_H *p_mt_identmnt_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"IDENTITY_CD",p_mt_identmnt_struct_h -> h_identity_cd);
	CO_Rtv_DataString(p_param_data,"CLT_DESC",p_mt_identmnt_struct_h -> h_clt_desc);
	CO_Rtv_DataString(p_param_data,"BRKCD",p_mt_identmnt_struct_h -> h_brkcd);
	CO_Rtv_DataString(p_param_data,"DSN_CD",p_mt_identmnt_struct_h -> h_dsn_cd);
}






int Populate_MT_INDEX_FUND(MT_INDEX_FUND_STRUCT_H *p_mt_index_fund_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INDEX_FUND_NUM",p_mt_index_fund_struct_h -> h_index_fund_num);
	CO_Rtv_DataString(p_param_data,"INDEX_FUND_NAME",p_mt_index_fund_struct_h -> h_index_fund_name);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_index_fund_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_index_fund_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_index_fund_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_index_fund_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_index_fund_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_index_fund_struct_h -> h_status);
}






int Populate_MT_INDEX_FUNDDET(MT_INDEX_FUNDDET_STRUCT_H *p_mt_index_funddet_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"INDEX_SEQ_NUM",(int *) &(p_mt_index_funddet_struct_h -> h_index_seq_num));
	CO_Rtv_DataString(p_param_data,"INDEX_FUND_NUM",p_mt_index_funddet_struct_h -> h_index_fund_num);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_index_funddet_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_index_funddet_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_index_funddet_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_index_funddet_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_index_funddet_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_index_funddet_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_index_funddet_struct_h -> h_status);
}






int Populate_MT_INSL_ENTRY(MT_INSL_ENTRY_STRUCT_H *p_mt_insl_entry_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_mt_insl_entry_struct_h -> h_depo_code);
	CO_Rtv_DataString(p_param_data,"DEPO_PART_CODE",p_mt_insl_entry_struct_h -> h_depo_part_code);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_insl_entry_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"TRANS_TYPE",p_mt_insl_entry_struct_h -> h_trans_type);
	CO_Rtv_DataString(p_param_data,"SLIP_SERIES",p_mt_insl_entry_struct_h -> h_slip_series);
	CO_Rtv_DataInt(p_param_data,"SR_NO_FROM",(int *) &(p_mt_insl_entry_struct_h -> h_sr_no_from));
	CO_Rtv_DataInt(p_param_data,"SR_NO_TO",(int *) &(p_mt_insl_entry_struct_h -> h_sr_no_to));
	CO_Rtv_DataInt(p_param_data,"SR_AVL_QTY",(int *) &(p_mt_insl_entry_struct_h -> h_sr_avl_qty));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_insl_entry_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_insl_entry_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_insl_entry_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_insl_entry_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_insl_entry_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_insl_entry_struct_h -> h_status);
}






int Populate_MT_INSTRUMENT(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_instrument_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_mt_instrument_struct_h -> h_currency_cd);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_mt_instrument_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"NOMINAL_VALUE",&(p_mt_instrument_struct_h -> h_nominal_value));
	CO_Rtv_DataString(p_param_data,"REG_BR_IND",p_mt_instrument_struct_h -> h_reg_br_ind);
	CO_Rtv_DataString(p_param_data,"ALLOW_RF",p_mt_instrument_struct_h -> h_allow_rf);
	CO_Rtv_DataString(p_param_data,"ALLOW_RVP",p_mt_instrument_struct_h -> h_allow_rvp);
	CO_Rtv_DataString(p_param_data,"ALLOW_DF",p_mt_instrument_struct_h -> h_allow_df);
	CO_Rtv_DataString(p_param_data,"ALLOW_DVP",p_mt_instrument_struct_h -> h_allow_dvp);
	CO_Rtv_DataString(p_param_data,"ORD_TYPE",p_mt_instrument_struct_h -> h_ord_type);
	CO_Rtv_DataString(p_param_data,"MOTHER_SEC_IND",p_mt_instrument_struct_h -> h_mother_sec_ind);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_mt_instrument_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"LISTED_IND",p_mt_instrument_struct_h -> h_listed_ind);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_mt_instrument_struct_h -> h_dateof_input);
	CO_Rtv_DataInt(p_param_data,"THRESHOLD_QTY",(int *) &(p_mt_instrument_struct_h -> h_threshold_qty));
	CO_Rtv_DataString(p_param_data,"NEW_MAKER",p_mt_instrument_struct_h -> h_new_maker);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_instrument_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_instrument_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_instrument_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_instrument_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_instrument_struct_h -> h_checker_dt);
	CO_Rtv_DataDbl(p_param_data,"TOTAL_PDCAPITA",&(p_mt_instrument_struct_h -> h_total_pdcapita));
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_instrument_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"NEW_ISSUE",p_mt_instrument_struct_h -> h_new_issue);
	CO_Rtv_DataString(p_param_data,"NEW_CHECKER",p_mt_instrument_struct_h -> h_new_checker);
	CO_Rtv_DataString(p_param_data,"CHNG_LST_IND",p_mt_instrument_struct_h -> h_chng_lst_ind);
	CO_Rtv_DataString(p_param_data,"CERT_OF_OWN_IN",p_mt_instrument_struct_h -> h_cert_of_own_in);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_mt_instrument_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_mt_instrument_struct_h -> h_instr_isin);
	CO_Rtv_DataString(p_param_data,"TIPO_INV",p_mt_instrument_struct_h -> h_tipo_inv);
	CO_Rtv_DataString(p_param_data,"INSTR_TYPE",p_mt_instrument_struct_h -> h_instr_type);
	CO_Rtv_DataString(p_param_data,"INSTR_PARENT",p_mt_instrument_struct_h -> h_instr_parent);
	CO_Rtv_DataString(p_param_data,"PROD_CLASS",p_mt_instrument_struct_h -> h_prod_class);
	CO_Rtv_DataString(p_param_data,"SEC_DL_CODE",p_mt_instrument_struct_h -> h_sec_dl_code);
	CO_Rtv_DataString(p_param_data,"CLASSCD",p_mt_instrument_struct_h -> h_classcd);
	CO_Rtv_DataString(p_param_data,"NEW_CD",p_mt_instrument_struct_h -> h_new_cd);
	CO_Rtv_DataString(p_param_data,"CHNG_ISIN",p_mt_instrument_struct_h -> h_chng_isin);
	CO_Rtv_DataString(p_param_data,"ISSUE_DATE",p_mt_instrument_struct_h -> h_issue_date);
	CO_Rtv_DataString(p_param_data,"CHG_MKR",p_mt_instrument_struct_h -> h_chg_mkr);
	CO_Rtv_DataString(p_param_data,"CA_NAME",p_mt_instrument_struct_h -> h_ca_name);
	CO_Rtv_DataString(p_param_data,"CHNG_CD",p_mt_instrument_struct_h -> h_chng_cd);
	CO_Rtv_DataString(p_param_data,"MATURE_DT",p_mt_instrument_struct_h -> h_mature_dt);
	CO_Rtv_DataString(p_param_data,"INT_TYP",p_mt_instrument_struct_h -> h_int_typ);
	CO_Rtv_DataDbl(p_param_data,"INSTR_INT_RATE",&(p_mt_instrument_struct_h -> h_instr_int_rate));
	CO_Rtv_DataString(p_param_data,"FREQ_CODE",p_mt_instrument_struct_h -> h_freq_code);
	CO_Rtv_DataString(p_param_data,"INT_ACCTYP",p_mt_instrument_struct_h -> h_int_acctyp);
	CO_Rtv_DataString(p_param_data,"LAST_PYMT_DATE",p_mt_instrument_struct_h -> h_last_pymt_date);
	CO_Rtv_DataInt(p_param_data,"LAST_INCOM_RT",(int *) &(p_mt_instrument_struct_h -> h_last_incom_rt));
	CO_Rtv_DataString(p_param_data,"NEXT_PAY_DATE",p_mt_instrument_struct_h -> h_next_pay_date);
	CO_Rtv_DataString(p_param_data,"OLD_LST_PAYDT",p_mt_instrument_struct_h -> h_old_lst_paydt);
	CO_Rtv_DataString(p_param_data,"MOD_LAST_PAYDT",p_mt_instrument_struct_h -> h_mod_last_paydt);
	CO_Rtv_DataString(p_param_data,"TAXONMAT_IND",p_mt_instrument_struct_h -> h_taxonmat_ind);
	CO_Rtv_DataString(p_param_data,"DISCT_IND",p_mt_instrument_struct_h -> h_disct_ind);
	CO_Rtv_DataString(p_param_data,"CA_ADDRDET",p_mt_instrument_struct_h -> h_ca_addrdet);
	CO_Rtv_DataInt(p_param_data,"MIN_FMT_DL_QTY",(int *) &(p_mt_instrument_struct_h -> h_min_fmt_dl_qty));
	CO_Rtv_DataString(p_param_data,"LR_SETL_DATE_A",p_mt_instrument_struct_h -> h_lr_setl_date_a);
	CO_Rtv_DataString(p_param_data,"LR_SETL_DATE_B",p_mt_instrument_struct_h -> h_lr_setl_date_b);
	CO_Rtv_DataString(p_param_data,"INSTR_SHORTNM",p_mt_instrument_struct_h -> h_instr_shortnm);
	CO_Rtv_DataString(p_param_data,"IPO_IND",p_mt_instrument_struct_h -> h_ipo_ind);
	CO_Rtv_DataString(p_param_data,"VALID_IPO_DATE",p_mt_instrument_struct_h -> h_valid_ipo_date);
	CO_Rtv_DataString(p_param_data,"LR_SETL_DATE_C",p_mt_instrument_struct_h -> h_lr_setl_date_c);
	CO_Rtv_DataString(p_param_data,"CMP_CODE",p_mt_instrument_struct_h -> h_cmp_code);
	CO_Rtv_DataString(p_param_data,"INSTR_REG_CODE",p_mt_instrument_struct_h -> h_instr_reg_code);
	CO_Rtv_DataString(p_param_data,"INSTR_SWF_NAME",p_mt_instrument_struct_h -> h_instr_swf_name);
	CO_Rtv_DataString(p_param_data,"INSTR_PRIV_PLACED",p_mt_instrument_struct_h -> h_instr_priv_placed);
	CO_Rtv_DataString(p_param_data,"INSTR_CRISIL_CODE",p_mt_instrument_struct_h -> h_instr_crisil_code);
	CO_Rtv_DataString(p_param_data,"INSTR_IS_SECURED",p_mt_instrument_struct_h -> h_instr_is_secured);
	CO_Rtv_DataString(p_param_data,"INSTR_SECURED_DT",p_mt_instrument_struct_h -> h_instr_secured_dt);
	CO_Rtv_DataInt(p_param_data,"INSTR_TOT_NOM_VAL",(int *) &(p_mt_instrument_struct_h -> h_instr_tot_nom_val));
	CO_Rtv_DataString(p_param_data,"INSTR_PC_IND",p_mt_instrument_struct_h -> h_instr_pc_ind);
	CO_Rtv_DataString(p_param_data,"INSTR_PART_RD_FLG",p_mt_instrument_struct_h -> h_instr_part_rd_flg);
	CO_Rtv_DataString(p_param_data,"INSTR_RESET_FLG",p_mt_instrument_struct_h -> h_instr_reset_flg);
	CO_Rtv_DataString(p_param_data,"INSTR_EXDT_LOA",p_mt_instrument_struct_h -> h_instr_exdt_loa);
	CO_Rtv_DataString(p_param_data,"INSTR_FST_PYMT_DT",p_mt_instrument_struct_h -> h_instr_fst_pymt_dt);
	CO_Rtv_DataDbl(p_param_data,"INSTR_DIV_RATE",&(p_mt_instrument_struct_h -> h_instr_div_rate));
	CO_Rtv_DataString(p_param_data,"INSTR_IS_DEMAT",p_mt_instrument_struct_h -> h_instr_is_demat);
	CO_Rtv_DataString(p_param_data,"INSTR_REMARK",p_mt_instrument_struct_h -> h_instr_remark);
	CO_Rtv_DataInt(p_param_data,"INSTRSHUT_PERIOD",(int *) &(p_mt_instrument_struct_h -> h_instrshut_period));
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN_NAME",p_mt_instrument_struct_h -> h_instr_isin_name);
	CO_Rtv_DataString(p_param_data,"INSTR_ATTACHED",p_mt_instrument_struct_h -> h_instr_attached);
	CO_Rtv_DataString(p_param_data,"INSTR_DETACH_DT",p_mt_instrument_struct_h -> h_instr_detach_dt);
}






int Populate_MT_INSTR_EXCH_DET(MT_INSTR_EXCH_DET_STRUCT_H *p_mt_instr_exch_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_instr_exch_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_instr_exch_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_instr_exch_det_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"SCRIP_GRP",p_mt_instr_exch_det_struct_h -> h_scrip_grp);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_mt_instr_exch_det_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"EXCH_INSTR_CODE",p_mt_instr_exch_det_struct_h -> h_exch_instr_code);
	CO_Rtv_DataString(p_param_data,"LISTING_STATUS",p_mt_instr_exch_det_struct_h -> h_listing_status);
	CO_Rtv_DataString(p_param_data,"LISTING_DATE",p_mt_instr_exch_det_struct_h -> h_listing_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_instr_exch_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_instr_exch_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_instr_exch_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_instr_exch_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_instr_exch_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_instr_exch_det_struct_h -> h_status);
}






int Populate_MT_INSTR_RATING_DET(MT_INSTR_RATING_DET_STRUCT_H *p_mt_instr_rating_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_instr_rating_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_instr_rating_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"CR_AGENCY_CODE",p_mt_instr_rating_det_struct_h -> h_cr_agency_code);
	CO_Rtv_DataString(p_param_data,"RATING_CODE",p_mt_instr_rating_det_struct_h -> h_rating_code);
	CO_Rtv_DataString(p_param_data,"EFFDT_FR",p_mt_instr_rating_det_struct_h -> h_effdt_fr);
	CO_Rtv_DataString(p_param_data,"EFFDT_TO",p_mt_instr_rating_det_struct_h -> h_effdt_to);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_instr_rating_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_instr_rating_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_instr_rating_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_instr_rating_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_instr_rating_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_instr_rating_det_struct_h -> h_status);
}






int Populate_MT_LOCATION(MT_LOCATION_STRUCT_H *p_mt_location_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_mt_location_struct_h -> h_location_cd);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_location_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_location_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_location_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_location_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_location_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_POS",p_mt_location_struct_h -> h_status_pos);
	CO_Rtv_DataString(p_param_data,"MANIFLD_IND",p_mt_location_struct_h -> h_manifld_ind);
	CO_Rtv_DataString(p_param_data,"LOC_STATUS",p_mt_location_struct_h -> h_loc_status);
	CO_Rtv_DataString(p_param_data,"LOCATION_DESC",p_mt_location_struct_h -> h_location_desc);
	CO_Rtv_DataString(p_param_data,"PHYSICAL_IND",p_mt_location_struct_h -> h_physical_ind);
	CO_Rtv_DataString(p_param_data,"ISO_LOCNCD",p_mt_location_struct_h -> h_iso_locncd);
	CO_Rtv_DataString(p_param_data,"AVAIL_IND",p_mt_location_struct_h -> h_avail_ind);
	CO_Rtv_DataString(p_param_data,"DEPO",p_mt_location_struct_h -> h_depo);
}






/*int Populate_MT_MESSAGE_SYS_PARAMS(MT_MESSAGE_SYS_PARAMS_STRUCT_H *p_mt_message_sys_params_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SND_MSG_TO_ALLMAST",p_mt_message_sys_params_struct_h -> h_snd_msg_to_allmast);
	CO_Rtv_DataString(p_param_data,"MSG569_PREMATCH_IND",p_mt_message_sys_params_struct_h -> h_msg569_prematch_ind);
	CO_Rtv_DataInt(p_param_data,"ALLOWED_TLX_LEN",(int *) &(p_mt_message_sys_params_struct_h -> h_allowed_tlx_len));
	CO_Rtv_DataInt(p_param_data,"ALLOWED_RETENSION_PRD",(int *) &(p_mt_message_sys_params_struct_h -> h_allowed_retension_prd));
	CO_Rtv_DataString(p_param_data,"GEN_FX_ADV_IND",p_mt_message_sys_params_struct_h -> h_gen_fx_adv_ind);
	CO_Rtv_DataString(p_param_data,"SWIFT_CD",p_mt_message_sys_params_struct_h -> h_swift_cd);
	CO_Rtv_DataString(p_param_data,"GCN_CD",p_mt_message_sys_params_struct_h -> h_gcn_cd);
	CO_Rtv_DataString(p_param_data,"AUTO_MSG_RPR_IND",p_mt_message_sys_params_struct_h -> h_auto_msg_rpr_ind);
	CO_Rtv_DataString(p_param_data,"REG_FOLLOW_MSG_IND",p_mt_message_sys_params_struct_h -> h_reg_follow_msg_ind);
	CO_Rtv_DataInt(p_param_data,"MSG_FOLLOW_DAYS1",(int *) &(p_mt_message_sys_params_struct_h -> h_msg_follow_days1));
	CO_Rtv_DataInt(p_param_data,"MSG_FOLLOW_DAYS2",(int *) &(p_mt_message_sys_params_struct_h -> h_msg_follow_days2));
	CO_Rtv_DataString(p_param_data,"MS_VTB_MSG_ADDR",p_mt_message_sys_params_struct_h -> h_ms_vtb_msg_addr);
	CO_Rtv_DataInt(p_param_data,"RESPONSE_DAYS",(int *) &(p_mt_message_sys_params_struct_h -> h_response_days));
	CO_Rtv_DataString(p_param_data,"CCS_INT_IND",p_mt_message_sys_params_struct_h -> h_ccs_int_ind);
	CO_Rtv_DataString(p_param_data,"LINE_IND",p_mt_message_sys_params_struct_h -> h_line_ind);
}
*/






int Populate_MT_MKTPRC_GEN_VEW(MT_MKTPRC_GEN_VEW_STRUCT_H *p_mt_mktprc_gen_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mt_mktprc_gen_vew_struct_h -> h_price_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_mktprc_gen_vew_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_mktprc_gen_vew_struct_h -> h_closing_pr));
}






int Populate_MT_MSGADDRESS(MT_MSGADDRESS_STRUCT_H *p_mt_msgaddress_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_msgaddress_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_NO",p_mt_msgaddress_struct_h -> h_cln_msg_no);
	CO_Rtv_DataInt(p_param_data,"CLN_SEQ_NUM",(int *) &(p_mt_msgaddress_struct_h -> h_cln_seq_num));
	CO_Rtv_DataString(p_param_data,"CLN_MSG_TYP",p_mt_msgaddress_struct_h -> h_cln_msg_typ);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_PRIORITY",p_mt_msgaddress_struct_h -> h_cln_msg_priority);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_GCN_ADDR",p_mt_msgaddress_struct_h -> h_cln_msg_gcn_addr);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_SWF_ADDR",p_mt_msgaddress_struct_h -> h_cln_msg_swf_addr);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_TLX_ADDR",p_mt_msgaddress_struct_h -> h_cln_msg_tlx_addr);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_CATEGORY",p_mt_msgaddress_struct_h -> h_cln_msg_category);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_CONSMSG",p_mt_msgaddress_struct_h -> h_cln_msg_consmsg);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_FAX",p_mt_msgaddress_struct_h -> h_cln_msg_fax);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_REFER",p_mt_msgaddress_struct_h -> h_cln_msg_refer);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_msgaddress_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_NOHOLDINGS",p_mt_msgaddress_struct_h -> h_cln_msg_noholdings);
	CO_Rtv_DataInt(p_param_data,"CLN_MSG_SCHSEQ_NUM",(int *) &(p_mt_msgaddress_struct_h -> h_cln_msg_schseq_num));
	CO_Rtv_DataString(p_param_data,"CLN_MSG_ISO15022FORMAT",p_mt_msgaddress_struct_h -> h_cln_msg_iso15022format);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_EVALUATE_FLG",p_mt_msgaddress_struct_h -> h_cln_msg_evaluate_flg);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_RESP_CONS54X",p_mt_msgaddress_struct_h -> h_cln_msg_resp_cons54x);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_GEN_REC_DP",p_mt_msgaddress_struct_h -> h_cln_msg_gen_rec_dp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_msgaddress_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_msgaddress_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_msgaddress_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_msgaddress_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_msgaddress_struct_h -> h_status);
}




/*

int Populate_MT_MSGADDRESS_VEW(MT_MSGADDRESS_VEW_STRUCT_H *p_mt_msgaddress_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

*/




int Populate_MT_MTHLYMKTPRC(MT_MTHLYMKTPRC_STRUCT_H *p_mt_mthlymktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_mthlymktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"OPEN_PR",&(p_mt_mthlymktprc_struct_h -> h_open_pr));
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_mthlymktprc_struct_h -> h_closing_pr));
}






int Populate_MT_NO_DELV(MT_NO_DELV_STRUCT_H *p_mt_no_delv_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_no_delv_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_no_delv_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"NO_DEL_FROM",p_mt_no_delv_struct_h -> h_no_del_from);
	CO_Rtv_DataString(p_param_data,"NO_DEL_TO",p_mt_no_delv_struct_h -> h_no_del_to);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_mt_no_delv_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"CARRY_FW_STLNO",p_mt_no_delv_struct_h -> h_carry_fw_stlno);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_no_delv_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_no_delv_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_no_delv_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_no_delv_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_no_delv_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_no_delv_struct_h -> h_status);
}






int Populate_MT_PARTY(MT_PARTY_STRUCT_H *p_mt_party_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PTY_CODE",p_mt_party_struct_h -> h_pty_code);
	CO_Rtv_DataString(p_param_data,"PTY_NAME",p_mt_party_struct_h -> h_pty_name);
	CO_Rtv_DataString(p_param_data,"PTY_SHORTNM",p_mt_party_struct_h -> h_pty_shortnm);
	CO_Rtv_DataString(p_param_data,"PTY_MAPINID",p_mt_party_struct_h -> h_pty_mapinid);
	CO_Rtv_DataString(p_param_data,"PTY_TYPE",p_mt_party_struct_h -> h_pty_type);
	CO_Rtv_DataString(p_param_data,"PTY_ADD1",p_mt_party_struct_h -> h_pty_add1);
	CO_Rtv_DataString(p_param_data,"PTY_ADD2",p_mt_party_struct_h -> h_pty_add2);
	CO_Rtv_DataString(p_param_data,"CITY",p_mt_party_struct_h -> h_city);
	CO_Rtv_DataString(p_param_data,"STATE",p_mt_party_struct_h -> h_state);
	CO_Rtv_DataString(p_param_data,"COUNTRY",p_mt_party_struct_h -> h_country);
	CO_Rtv_DataString(p_param_data,"PTY_ADD_PIN",p_mt_party_struct_h -> h_pty_add_pin);
	CO_Rtv_DataString(p_param_data,"PTY_TEL",p_mt_party_struct_h -> h_pty_tel);
	CO_Rtv_DataString(p_param_data,"PTY_FAX",p_mt_party_struct_h -> h_pty_fax);
	CO_Rtv_DataString(p_param_data,"PTY_EMAIL",p_mt_party_struct_h -> h_pty_email);
	CO_Rtv_DataString(p_param_data,"PTY_CONTACT1",p_mt_party_struct_h -> h_pty_contact1);
	CO_Rtv_DataString(p_param_data,"PTY_CONTACT2",p_mt_party_struct_h -> h_pty_contact2);
	CO_Rtv_DataString(p_param_data,"PTY_SWF_NAME",p_mt_party_struct_h -> h_pty_swf_name);
	CO_Rtv_DataString(p_param_data,"PTY_SWF_ADD",p_mt_party_struct_h -> h_pty_swf_add);
	CO_Rtv_DataString(p_param_data,"PTY_SEBI_REG_NO",p_mt_party_struct_h -> h_pty_sebi_reg_no);
	CO_Rtv_DataString(p_param_data,"PTY_PAN",p_mt_party_struct_h -> h_pty_pan);
	CO_Rtv_DataString(p_param_data,"PTY_LC_NAME",p_mt_party_struct_h -> h_pty_lc_name);
	CO_Rtv_DataString(p_param_data,"PTY_LC_ADD",p_mt_party_struct_h -> h_pty_lc_add);
	CO_Rtv_DataString(p_param_data,"PTY_LC_TEL",p_mt_party_struct_h -> h_pty_lc_tel);
	CO_Rtv_DataString(p_param_data,"PTY_LC_EMAIL",p_mt_party_struct_h -> h_pty_lc_email);
	CO_Rtv_DataString(p_param_data,"PTY_LC_FAX",p_mt_party_struct_h -> h_pty_lc_fax);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_party_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_party_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_party_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_party_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_party_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_party_struct_h -> h_status);
}






int Populate_MT_PC_DET(MT_PC_DET_STRUCT_H *p_mt_pc_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_pc_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_pc_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"PC_FLAG",p_mt_pc_det_struct_h -> h_pc_flag);
	CO_Rtv_DataString(p_param_data,"PC_DATE",p_mt_pc_det_struct_h -> h_pc_date);
	CO_Rtv_DataString(p_param_data,"PC_NOTICE_DATE",p_mt_pc_det_struct_h -> h_pc_notice_date);
	CO_Rtv_DataString(p_param_data,"INSTR_PC_EFFDT",p_mt_pc_det_struct_h -> h_instr_pc_effdt);
	CO_Rtv_DataString(p_param_data,"INSTR_PC_CUTOFFTIME",p_mt_pc_det_struct_h -> h_instr_pc_cutofftime);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_pc_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_pc_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_pc_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_pc_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_pc_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_pc_det_struct_h -> h_status);
}






int Populate_MT_PTC_DET(MT_PTC_DET_STRUCT_H *p_mt_ptc_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_ptc_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_ptc_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"PTC_DT",p_mt_ptc_det_struct_h -> h_ptc_dt);
	CO_Rtv_DataInt(p_param_data,"PTC_PRIN_AMT",(int *) &(p_mt_ptc_det_struct_h -> h_ptc_prin_amt));
	CO_Rtv_DataInt(p_param_data,"PTC_INT_AMT",(int *) &(p_mt_ptc_det_struct_h -> h_ptc_int_amt));
	CO_Rtv_DataInt(p_param_data,"PTC_VALUE",(int *) &(p_mt_ptc_det_struct_h -> h_ptc_value));
	CO_Rtv_DataString(p_param_data,"PTC_PAID_FLG",p_mt_ptc_det_struct_h -> h_ptc_paid_flg);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_ptc_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_ptc_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_ptc_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_ptc_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_ptc_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_ptc_det_struct_h -> h_status);
}






int Populate_MT_PTY_DEPO_MAP(MT_PTY_DEPO_MAP_STRUCT_H *p_mt_pty_depo_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PTY_CODE",p_mt_pty_depo_map_struct_h -> h_pty_code);
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_mt_pty_depo_map_struct_h -> h_depo_code);
	CO_Rtv_DataString(p_param_data,"PTY_DEPO_MAP_CLIENT_ID",p_mt_pty_depo_map_struct_h -> h_pty_depo_map_client_id);
	CO_Rtv_DataString(p_param_data,"PTY_DEPO_MAP_DP_ID",p_mt_pty_depo_map_struct_h -> h_pty_depo_map_dp_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_pty_depo_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_pty_depo_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_pty_depo_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_pty_depo_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_pty_depo_map_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_pty_depo_map_struct_h -> h_status);
}






int Populate_MT_PTY_EXCH_CLN_MAP(MT_PTY_EXCH_CLN_MAP_STRUCT_H *p_mt_pty_exch_cln_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PTY_CODE",p_mt_pty_exch_cln_map_struct_h -> h_pty_code);
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_pty_exch_cln_map_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_pty_exch_cln_map_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"PTY_EXCH_CLN_MAP_CODE",p_mt_pty_exch_cln_map_struct_h -> h_pty_exch_cln_map_code);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_pty_exch_cln_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_pty_exch_cln_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_pty_exch_cln_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_pty_exch_cln_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_pty_exch_cln_map_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_pty_exch_cln_map_struct_h -> h_status);
}






int Populate_MT_PTY_EXCH_MAP(MT_PTY_EXCH_MAP_STRUCT_H *p_mt_pty_exch_map_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PTY_CODE",p_mt_pty_exch_map_struct_h -> h_pty_code);
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_pty_exch_map_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"PTY_EXCH_MAP_CODE",p_mt_pty_exch_map_struct_h -> h_pty_exch_map_code);
	CO_Rtv_DataString(p_param_data,"PTY_CMBP_ID",p_mt_pty_exch_map_struct_h -> h_pty_cmbp_id);
	CO_Rtv_DataString(p_param_data,"PTY_CCCM_ID",p_mt_pty_exch_map_struct_h -> h_pty_cccm_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_pty_exch_map_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_pty_exch_map_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_pty_exch_map_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_pty_exch_map_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_pty_exch_map_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_pty_exch_map_struct_h -> h_status);
}






int Populate_MT_RBI_MONITORY(MT_RBI_MONITORY_STRUCT_H *p_mt_rbi_monitory_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_rbi_monitory_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"RBI_INSTR_CODE",p_mt_rbi_monitory_struct_h -> h_rbi_instr_code);
	CO_Rtv_DataDbl(p_param_data,"TPCAPITAL",&(p_mt_rbi_monitory_struct_h -> h_tpcapital));
	CO_Rtv_DataDbl(p_param_data,"SNG_FII_LIMIT",&(p_mt_rbi_monitory_struct_h -> h_sng_fii_limit));
	CO_Rtv_DataDbl(p_param_data,"OVR_FII_LIMIT",&(p_mt_rbi_monitory_struct_h -> h_ovr_fii_limit));
	CO_Rtv_DataDbl(p_param_data,"SNG_NRIOCB_LIMIT",&(p_mt_rbi_monitory_struct_h -> h_sng_nriocb_limit));
	CO_Rtv_DataDbl(p_param_data,"OVR_NRIOCB_LIMIT",&(p_mt_rbi_monitory_struct_h -> h_ovr_nriocb_limit));
	CO_Rtv_DataString(p_param_data,"CAUTION_FLG",p_mt_rbi_monitory_struct_h -> h_caution_flg);
	CO_Rtv_DataDbl(p_param_data,"CAUTION_FII",&(p_mt_rbi_monitory_struct_h -> h_caution_fii));
	CO_Rtv_DataDbl(p_param_data,"CAUTION_NRIOCB",&(p_mt_rbi_monitory_struct_h -> h_caution_nriocb));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_rbi_monitory_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_rbi_monitory_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_rbi_monitory_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_rbi_monitory_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_rbi_monitory_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_rbi_monitory_struct_h -> h_status);
}






int Populate_MT_RED_DET(MT_RED_DET_STRUCT_H *p_mt_red_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_red_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_red_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"RED_DT",p_mt_red_det_struct_h -> h_red_dt);
	CO_Rtv_DataInt(p_param_data,"RED_PCT",(int *) &(p_mt_red_det_struct_h -> h_red_pct));
	CO_Rtv_DataDbl(p_param_data,"RED_VALUE",&(p_mt_red_det_struct_h -> h_red_value));
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_red_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_red_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_red_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_red_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_red_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_red_det_struct_h -> h_status);
}






int Populate_MT_RED_DP_DET(MT_RED_DP_DET_STRUCT_H *p_mt_red_dp_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_red_dp_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_red_dp_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"RD_CLIENT_ID",p_mt_red_dp_det_struct_h -> h_rd_client_id);
	CO_Rtv_DataString(p_param_data,"RD_DP_ID",p_mt_red_dp_det_struct_h -> h_rd_dp_id);
	CO_Rtv_DataString(p_param_data,"RD_DEPO_CODE",p_mt_red_dp_det_struct_h -> h_rd_depo_code);
	CO_Rtv_DataString(p_param_data,"IPA_CODE",p_mt_red_dp_det_struct_h -> h_ipa_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_red_dp_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_red_dp_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_red_dp_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_red_dp_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_red_dp_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_red_dp_det_struct_h -> h_status);
}






int Populate_MT_REGDETAILS(MT_REGDETAILS_STRUCT_H *p_mt_regdetails_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_regdetails_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_SEBI_REG_NO",p_mt_regdetails_struct_h -> h_cln_sebi_reg_no);
	CO_Rtv_DataString(p_param_data,"CLN_SEBI_REG_DT",p_mt_regdetails_struct_h -> h_cln_sebi_reg_dt);
	CO_Rtv_DataString(p_param_data,"CLN_SEBI_REG_EXPDT",p_mt_regdetails_struct_h -> h_cln_sebi_reg_expdt);
	CO_Rtv_DataString(p_param_data,"CLN_RBI_REG_NO",p_mt_regdetails_struct_h -> h_cln_rbi_reg_no);
	CO_Rtv_DataString(p_param_data,"CLN_RBI_REG_DT",p_mt_regdetails_struct_h -> h_cln_rbi_reg_dt);
	CO_Rtv_DataString(p_param_data,"CLN_RBI_REG_EXPDT",p_mt_regdetails_struct_h -> h_cln_rbi_reg_expdt);
	CO_Rtv_DataString(p_param_data,"CLN_MAPINID",p_mt_regdetails_struct_h -> h_cln_mapinid);
	CO_Rtv_DataString(p_param_data,"CLN_UCC_CODE",p_mt_regdetails_struct_h -> h_cln_ucc_code);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_regdetails_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_regdetails_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_regdetails_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_regdetails_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_regdetails_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_regdetails_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"SEBI_SUB_ACC",p_mt_regdetails_struct_h -> h_sebi_sub_acc);
}






int Populate_MT_RESET_DET(MT_RESET_DET_STRUCT_H *p_mt_reset_det_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_reset_det_struct_h -> h_instr_code);
	CO_Rtv_DataInt(p_param_data,"INSTR_SEQ_NUM",(int *) &(p_mt_reset_det_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(p_param_data,"RESET_DT",p_mt_reset_det_struct_h -> h_reset_dt);
	CO_Rtv_DataInt(p_param_data,"RESET_RATE",(int *) &(p_mt_reset_det_struct_h -> h_reset_rate));
	CO_Rtv_DataString(p_param_data,"RESET_FRDT",p_mt_reset_det_struct_h -> h_reset_frdt);
	CO_Rtv_DataString(p_param_data,"RESET_TODT",p_mt_reset_det_struct_h -> h_reset_todt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_reset_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_reset_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_reset_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_reset_det_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_reset_det_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_reset_det_struct_h -> h_status);
}






int Populate_MT_SCHDET(MT_SCHDET_STRUCT_H *p_mt_schdet_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_schdet_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CLN_MSG_NO",p_mt_schdet_struct_h -> h_cln_msg_no);
	CO_Rtv_DataInt(p_param_data,"CLN_SEQ_NUM",(int *) &(p_mt_schdet_struct_h -> h_cln_seq_num));
	CO_Rtv_DataString(p_param_data,"CLN_SCH_EOM",p_mt_schdet_struct_h -> h_cln_sch_eom);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_GEN_ON_DAY",p_mt_schdet_struct_h -> h_cln_sch_gen_on_day);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_NOPOSTXNFLG",p_mt_schdet_struct_h -> h_cln_sch_nopostxnflg);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_ZEROMOV",p_mt_schdet_struct_h -> h_cln_sch_zeromov);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_MSGOPTION",p_mt_schdet_struct_h -> h_cln_sch_msgoption);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_DEPO_STAT",p_mt_schdet_struct_h -> h_cln_sch_depo_stat);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_schdet_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_NOPEND",p_mt_schdet_struct_h -> h_cln_sch_nopend);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_WEEKSTM",p_mt_schdet_struct_h -> h_cln_sch_weekstm);
	CO_Rtv_DataString(p_param_data,"CLN_SCH_EVALUATE_FLG",p_mt_schdet_struct_h -> h_cln_sch_evaluate_flg);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_schdet_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_schdet_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_schdet_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_schdet_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_schdet_struct_h -> h_status);
}






int Populate_MT_SCHDET_TEMP(MT_SCHDET_TEMP_STRUCT_H *p_mt_schdet_temp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"T_ROW_ID",p_mt_schdet_temp_struct_h -> h_t_row_id);
	CO_Rtv_DataString(p_param_data,"DEALDT",p_mt_schdet_temp_struct_h -> h_dealdt);
}




/*

int Populate_MT_SCHDET_VEW(MT_SCHDET_VEW_STRUCT_H *p_mt_schdet_vew_struct_h,char * p_param_data)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
}
*/





int Populate_MT_SETTL_CAL(MT_SETTL_CAL_STRUCT_H *p_mt_settl_cal_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_settl_cal_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"SETTL_NO",p_mt_settl_cal_struct_h -> h_settl_no);
	CO_Rtv_DataString(p_param_data,"CC_ID",p_mt_settl_cal_struct_h -> h_cc_id);
	CO_Rtv_DataString(p_param_data,"SETTL_TYPE",p_mt_settl_cal_struct_h -> h_settl_type);
	CO_Rtv_DataString(p_param_data,"START_DATE",p_mt_settl_cal_struct_h -> h_start_date);
	CO_Rtv_DataString(p_param_data,"END_DATE",p_mt_settl_cal_struct_h -> h_end_date);
	CO_Rtv_DataString(p_param_data,"NSDL_DEADLINE_DT",p_mt_settl_cal_struct_h -> h_nsdl_deadline_dt);
	CO_Rtv_DataString(p_param_data,"NSDL_DEADLINE_TM",p_mt_settl_cal_struct_h -> h_nsdl_deadline_tm);
	CO_Rtv_DataString(p_param_data,"PAY_IN_DT",p_mt_settl_cal_struct_h -> h_pay_in_dt);
	CO_Rtv_DataString(p_param_data,"PAY_OUT_DT",p_mt_settl_cal_struct_h -> h_pay_out_dt);
	CO_Rtv_DataString(p_param_data,"AUCTION_DT",p_mt_settl_cal_struct_h -> h_auction_dt);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_settl_cal_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_settl_cal_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_settl_cal_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_settl_cal_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_settl_cal_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_settl_cal_struct_h -> h_status);
}






int Populate_MT_TEMPMKTPRC(MT_TEMPMKTPRC_STRUCT_H *p_mt_tempmktprc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PRICE_DATE",p_mt_tempmktprc_struct_h -> h_price_date);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_mt_tempmktprc_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"CLOSING_PR",&(p_mt_tempmktprc_struct_h -> h_closing_pr));
	CO_Rtv_DataString(p_param_data,"MODIFYMOD",p_mt_tempmktprc_struct_h -> h_modifymod);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_tempmktprc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_tempmktprc_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_tempmktprc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"MKRTPR_STAT",p_mt_tempmktprc_struct_h -> h_mkrtpr_stat);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_tempmktprc_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_tempmktprc_struct_h -> h_checker_dt);
}






int Populate_MT_WHTRATE(MT_WHTRATE_STRUCT_H *p_mt_whtrate_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION_CD",p_mt_whtrate_struct_h -> h_nation_cd);
	CO_Rtv_DataString(p_param_data,"PROD_CLASS",p_mt_whtrate_struct_h -> h_prod_class);
	CO_Rtv_DataDbl(p_param_data,"CUSTODYTAXRT",&(p_mt_whtrate_struct_h -> h_custodytaxrt));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_whtrate_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_whtrate_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_whtrate_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_mt_whtrate_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_whtrate_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_whtrate_struct_h -> h_checker_dt);
}






int Populate_OR_ARCHEXEC(OR_ARCHEXEC_STRUCT_H *p_or_archexec_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_archexec_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_or_archexec_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_or_archexec_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_or_archexec_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_or_archexec_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_or_archexec_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EXEC_DATE",p_or_archexec_struct_h -> h_exec_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_archexec_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_or_archexec_struct_h -> h_brokercomm));
	CO_Rtv_DataString(p_param_data,"TAX",p_or_archexec_struct_h -> h_tax);
	CO_Rtv_DataString(p_param_data,"RESET_IND",p_or_archexec_struct_h -> h_reset_ind);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_archexec_struct_h -> h_ord_refno);
}






int Populate_OR_ARCHORDERS(OR_ARCHORDERS_STRUCT_H *p_or_archorders_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_archorders_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_archorders_struct_h -> h_ord_refno);
	CO_Rtv_DataString(p_param_data,"BUY_SELL_IND",p_or_archorders_struct_h -> h_buy_sell_ind);
	CO_Rtv_DataString(p_param_data,"ORD_DATE",p_or_archorders_struct_h -> h_ord_date);
	CO_Rtv_DataDbl(p_param_data,"ORD_QTY",&(p_or_archorders_struct_h -> h_ord_qty));
	CO_Rtv_DataString(p_param_data,"LIMIT_IND",p_or_archorders_struct_h -> h_limit_ind);
	CO_Rtv_DataString(p_param_data,"ISGTE_IND",p_or_archorders_struct_h -> h_isgte_ind);
	CO_Rtv_DataString(p_param_data,"ALL_NONE_IND",p_or_archorders_struct_h -> h_all_none_ind);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_or_archorders_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"ORD_STAT",p_or_archorders_struct_h -> h_ord_stat);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_or_archorders_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_or_archorders_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_or_archorders_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_archorders_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_or_archorders_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_or_archorders_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"EXP_DATE",p_or_archorders_struct_h -> h_exp_date);
	CO_Rtv_DataDbl(p_param_data,"LIMIT_PR",&(p_or_archorders_struct_h -> h_limit_pr));
	CO_Rtv_DataString(p_param_data,"DATEOF_CANCEL",p_or_archorders_struct_h -> h_dateof_cancel);
	CO_Rtv_DataDbl(p_param_data,"EXEC_QTY",&(p_or_archorders_struct_h -> h_exec_qty));
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_or_archorders_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_or_archorders_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_or_archorders_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_or_archorders_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_or_archorders_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_or_archorders_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_or_archorders_struct_h -> h_unblk_date);
	CO_Rtv_DataString(p_param_data,"LAST_EXEC_DATE",p_or_archorders_struct_h -> h_last_exec_date);
	CO_Rtv_DataString(p_param_data,"LAST_DL_DATE",p_or_archorders_struct_h -> h_last_dl_date);
	CO_Rtv_DataString(p_param_data,"CLNT_NAME",p_or_archorders_struct_h -> h_clnt_name);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_or_archorders_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_or_archorders_struct_h -> h_closing_date);
}






int Populate_OR_EXECORDER(OR_EXECORDER_STRUCT_H *p_or_execorder_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_execorder_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_or_execorder_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_or_execorder_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_or_execorder_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_or_execorder_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_or_execorder_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EXEC_DATE",p_or_execorder_struct_h -> h_exec_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_execorder_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_or_execorder_struct_h -> h_brokercomm));
	CO_Rtv_DataString(p_param_data,"TAX",p_or_execorder_struct_h -> h_tax);
	CO_Rtv_DataString(p_param_data,"RESET_IND",p_or_execorder_struct_h -> h_reset_ind);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_execorder_struct_h -> h_ord_refno);
}






int Populate_OR_HISEXECORDER(OR_HISEXECORDER_STRUCT_H *p_or_hisexecorder_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_hisexecorder_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_or_hisexecorder_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_or_hisexecorder_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_or_hisexecorder_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_or_hisexecorder_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_or_hisexecorder_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EXEC_DATE",p_or_hisexecorder_struct_h -> h_exec_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_hisexecorder_struct_h -> h_access_stamp);
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_or_hisexecorder_struct_h -> h_brokercomm));
	CO_Rtv_DataString(p_param_data,"TAX",p_or_hisexecorder_struct_h -> h_tax);
	CO_Rtv_DataString(p_param_data,"RESET_IND",p_or_hisexecorder_struct_h -> h_reset_ind);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_hisexecorder_struct_h -> h_ord_refno);
}






int Populate_OR_HISORDER(OR_HISORDER_STRUCT_H *p_or_hisorder_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_hisorder_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_hisorder_struct_h -> h_ord_refno);
	CO_Rtv_DataString(p_param_data,"BUY_SELL_IND",p_or_hisorder_struct_h -> h_buy_sell_ind);
	CO_Rtv_DataString(p_param_data,"ORD_DATE",p_or_hisorder_struct_h -> h_ord_date);
	CO_Rtv_DataDbl(p_param_data,"ORD_QTY",&(p_or_hisorder_struct_h -> h_ord_qty));
	CO_Rtv_DataString(p_param_data,"LIMIT_IND",p_or_hisorder_struct_h -> h_limit_ind);
	CO_Rtv_DataString(p_param_data,"ISGTE_IND",p_or_hisorder_struct_h -> h_isgte_ind);
	CO_Rtv_DataString(p_param_data,"ALL_NONE_IND",p_or_hisorder_struct_h -> h_all_none_ind);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_or_hisorder_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"ORD_STAT",p_or_hisorder_struct_h -> h_ord_stat);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_or_hisorder_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_or_hisorder_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_or_hisorder_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_hisorder_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_or_hisorder_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_or_hisorder_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"EXP_DATE",p_or_hisorder_struct_h -> h_exp_date);
	CO_Rtv_DataDbl(p_param_data,"LIMIT_PR",&(p_or_hisorder_struct_h -> h_limit_pr));
	CO_Rtv_DataString(p_param_data,"DATEOF_CANCEL",p_or_hisorder_struct_h -> h_dateof_cancel);
	CO_Rtv_DataDbl(p_param_data,"EXEC_QTY",&(p_or_hisorder_struct_h -> h_exec_qty));
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_or_hisorder_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_or_hisorder_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_or_hisorder_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_or_hisorder_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_or_hisorder_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_or_hisorder_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_or_hisorder_struct_h -> h_unblk_date);
	CO_Rtv_DataString(p_param_data,"LAST_EXEC_DATE",p_or_hisorder_struct_h -> h_last_exec_date);
	CO_Rtv_DataString(p_param_data,"LAST_DL_DATE",p_or_hisorder_struct_h -> h_last_dl_date);
	CO_Rtv_DataString(p_param_data,"CLNT_NAME",p_or_hisorder_struct_h -> h_clnt_name);
	CO_Rtv_DataString(p_param_data,"INSTR_NAME",p_or_hisorder_struct_h -> h_instr_name);
	CO_Rtv_DataString(p_param_data,"CLOSING_DATE",p_or_hisorder_struct_h -> h_closing_date);
}






int Populate_OR_ORDERDETAILS(OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_orderdetails_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_orderdetails_struct_h -> h_ord_refno);
	CO_Rtv_DataString(p_param_data,"BUY_SELL_IND",p_or_orderdetails_struct_h -> h_buy_sell_ind);
	CO_Rtv_DataString(p_param_data,"ORD_DATE",p_or_orderdetails_struct_h -> h_ord_date);
	CO_Rtv_DataDbl(p_param_data,"ORD_QTY",&(p_or_orderdetails_struct_h -> h_ord_qty));
	CO_Rtv_DataString(p_param_data,"LIMIT_IND",p_or_orderdetails_struct_h -> h_limit_ind);
	CO_Rtv_DataString(p_param_data,"ISGTE_IND",p_or_orderdetails_struct_h -> h_isgte_ind);
	CO_Rtv_DataString(p_param_data,"ALL_NONE_IND",p_or_orderdetails_struct_h -> h_all_none_ind);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_or_orderdetails_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"ORD_STAT",p_or_orderdetails_struct_h -> h_ord_stat);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_or_orderdetails_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_or_orderdetails_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_or_orderdetails_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_orderdetails_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_or_orderdetails_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_or_orderdetails_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"EXP_DATE",p_or_orderdetails_struct_h -> h_exp_date);
	CO_Rtv_DataDbl(p_param_data,"LIMIT_PR",&(p_or_orderdetails_struct_h -> h_limit_pr));
	CO_Rtv_DataString(p_param_data,"DATEOF_CANCEL",p_or_orderdetails_struct_h -> h_dateof_cancel);
	CO_Rtv_DataDbl(p_param_data,"EXEC_QTY",&(p_or_orderdetails_struct_h -> h_exec_qty));
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_or_orderdetails_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_or_orderdetails_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_or_orderdetails_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_or_orderdetails_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_or_orderdetails_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_or_orderdetails_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_or_orderdetails_struct_h -> h_unblk_date);
	CO_Rtv_DataString(p_param_data,"LAST_EXEC_DATE",p_or_orderdetails_struct_h -> h_last_exec_date);
	CO_Rtv_DataString(p_param_data,"LAST_DL_DATE",p_or_orderdetails_struct_h -> h_last_dl_date);
}






int Populate_OR_ORD_LR_VEW(OR_ORD_LR_VEW_STRUCT_H *p_or_ord_lr_vew_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_or_ord_lr_vew_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"ORD_REFNO",p_or_ord_lr_vew_struct_h -> h_ord_refno);
	CO_Rtv_DataString(p_param_data,"BUY_SELL_IND",p_or_ord_lr_vew_struct_h -> h_buy_sell_ind);
	CO_Rtv_DataString(p_param_data,"ORD_DATE",p_or_ord_lr_vew_struct_h -> h_ord_date);
	CO_Rtv_DataInt(p_param_data,"ORD_QTY",(int *) &(p_or_ord_lr_vew_struct_h -> h_ord_qty));
	CO_Rtv_DataString(p_param_data,"LIMIT_IND",p_or_ord_lr_vew_struct_h -> h_limit_ind);
	CO_Rtv_DataString(p_param_data,"ISGTE_IND",p_or_ord_lr_vew_struct_h -> h_isgte_ind);
	CO_Rtv_DataString(p_param_data,"ALL_NONE_IND",p_or_ord_lr_vew_struct_h -> h_all_none_ind);
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_or_ord_lr_vew_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"ORD_STAT",p_or_ord_lr_vew_struct_h -> h_ord_stat);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_or_ord_lr_vew_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_or_ord_lr_vew_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_or_ord_lr_vew_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_or_ord_lr_vew_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_or_ord_lr_vew_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_or_ord_lr_vew_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"EXP_DATE",p_or_ord_lr_vew_struct_h -> h_exp_date);
	CO_Rtv_DataDbl(p_param_data,"LIMIT_PR",&(p_or_ord_lr_vew_struct_h -> h_limit_pr));
	CO_Rtv_DataString(p_param_data,"DATEOF_CANCEL",p_or_ord_lr_vew_struct_h -> h_dateof_cancel);
	CO_Rtv_DataInt(p_param_data,"EXEC_QTY",(int *) &(p_or_ord_lr_vew_struct_h -> h_exec_qty));
	CO_Rtv_DataString(p_param_data,"ALLOW_DROPDT",p_or_ord_lr_vew_struct_h -> h_allow_dropdt);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_or_ord_lr_vew_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"LCL_IDENTNO",p_or_ord_lr_vew_struct_h -> h_lcl_identno);
	CO_Rtv_DataString(p_param_data,"LR_DL_CLASS",p_or_ord_lr_vew_struct_h -> h_lr_dl_class);
	CO_Rtv_DataString(p_param_data,"LR_CHECK_DATE",p_or_ord_lr_vew_struct_h -> h_lr_check_date);
	CO_Rtv_DataString(p_param_data,"LR_UNBLK_DATE",p_or_ord_lr_vew_struct_h -> h_lr_unblk_date);
	CO_Rtv_DataString(p_param_data,"UNBLK_DATE",p_or_ord_lr_vew_struct_h -> h_unblk_date);
	CO_Rtv_DataString(p_param_data,"LAST_EXEC_DATE",p_or_ord_lr_vew_struct_h -> h_last_exec_date);
	CO_Rtv_DataString(p_param_data,"LAST_DL_DATE",p_or_ord_lr_vew_struct_h -> h_last_dl_date);
}






int Populate_PLAN_TABLE(PLAN_TABLE_STRUCT_H *p_plan_table_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"STATEMENT_ID",p_plan_table_struct_h -> h_statement_id);
	CO_Rtv_DataString(p_param_data,"TIMESTAMP",p_plan_table_struct_h -> h_timestamp);
	CO_Rtv_DataString(p_param_data,"REMARKS",p_plan_table_struct_h -> h_remarks);
	CO_Rtv_DataString(p_param_data,"OPERATION",p_plan_table_struct_h -> h_operation);
	CO_Rtv_DataString(p_param_data,"OPTIONS",p_plan_table_struct_h -> h_options);
	CO_Rtv_DataString(p_param_data,"OBJECT_NODE",p_plan_table_struct_h -> h_object_node);
	CO_Rtv_DataString(p_param_data,"OBJECT_OWNER",p_plan_table_struct_h -> h_object_owner);
	CO_Rtv_DataString(p_param_data,"OBJECT_NAME",p_plan_table_struct_h -> h_object_name);
	CO_Rtv_DataInt(p_param_data,"OBJECT_INSTANCE",(int *) &(p_plan_table_struct_h -> h_object_instance));
	CO_Rtv_DataString(p_param_data,"OBJECT_TYPE",p_plan_table_struct_h -> h_object_type);
	CO_Rtv_DataString(p_param_data,"OPTIMIZER",p_plan_table_struct_h -> h_optimizer);
	CO_Rtv_DataInt(p_param_data,"SEARCH_COLUMNS",(int *) &(p_plan_table_struct_h -> h_search_columns));
	CO_Rtv_DataInt(p_param_data,"ID",(int *) &(p_plan_table_struct_h -> h_id));
	CO_Rtv_DataInt(p_param_data,"PARENT_ID",(int *) &(p_plan_table_struct_h -> h_parent_id));
	CO_Rtv_DataInt(p_param_data,"POSITION",(int *) &(p_plan_table_struct_h -> h_position));
	CO_Rtv_DataInt(p_param_data,"COST",(int *) &(p_plan_table_struct_h -> h_cost));
	CO_Rtv_DataInt(p_param_data,"CARDINALITY",(int *) &(p_plan_table_struct_h -> h_cardinality));
	CO_Rtv_DataInt(p_param_data,"BYTES",(int *) &(p_plan_table_struct_h -> h_bytes));
	CO_Rtv_DataString(p_param_data,"OTHER_TAG",p_plan_table_struct_h -> h_other_tag);
	CO_Rtv_DataString(p_param_data,"PARTITION_START",p_plan_table_struct_h -> h_partition_start);
	CO_Rtv_DataString(p_param_data,"PARTITION_STOP",p_plan_table_struct_h -> h_partition_stop);
	CO_Rtv_DataInt(p_param_data,"PARTITION_ID",(int *) &(p_plan_table_struct_h -> h_partition_id));
	
	CO_Rtv_DataString(p_param_data,"DISTRIBUTION",p_plan_table_struct_h -> h_distribution);
	CO_Rtv_DataInt(p_param_data,"CPU_COST",(int *) &(p_plan_table_struct_h -> h_cpu_cost));
	CO_Rtv_DataInt(p_param_data,"IO_COST",(int *) &(p_plan_table_struct_h -> h_io_cost));
	CO_Rtv_DataInt(p_param_data,"TEMP_SPACE",(int *) &(p_plan_table_struct_h -> h_temp_space));
}






int Populate_PRO_ACCTENT(PRO_ACCTENT_STRUCT_H *p_pro_acctent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MODULE_IND",p_pro_acctent_struct_h -> h_module_ind);
	CO_Rtv_DataString(p_param_data,"BRNCH_CD",p_pro_acctent_struct_h -> h_brnch_cd);
	CO_Rtv_DataString(p_param_data,"INDEN_NUM",p_pro_acctent_struct_h -> h_inden_num);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_pro_acctent_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CURR_CD",p_pro_acctent_struct_h -> h_curr_cd);
	CO_Rtv_DataDbl(p_param_data,"FCCY_AMT",&(p_pro_acctent_struct_h -> h_fccy_amt));
	CO_Rtv_DataDbl(p_param_data,"EXCHG_RT",&(p_pro_acctent_struct_h -> h_exchg_rt));
	CO_Rtv_DataDbl(p_param_data,"LCL_AMOUNT",&(p_pro_acctent_struct_h -> h_lcl_amount));
	CO_Rtv_DataString(p_param_data,"VAL_DATE",p_pro_acctent_struct_h -> h_val_date);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_pro_acctent_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"SPL_CLT_CD",p_pro_acctent_struct_h -> h_spl_clt_cd);
	CO_Rtv_DataString(p_param_data,"DB_CR_IND",p_pro_acctent_struct_h -> h_db_cr_ind);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_pro_acctent_struct_h -> h_narrative);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_acctent_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"PROC_NUM",p_pro_acctent_struct_h -> h_proc_num);
	CO_Rtv_DataDbl(p_param_data,"REPORT_AMT",&(p_pro_acctent_struct_h -> h_report_amt));
	CO_Rtv_DataDbl(p_param_data,"REPORT_CLT",&(p_pro_acctent_struct_h -> h_report_clt));
	CO_Rtv_DataDbl(p_param_data,"REPORT_TAX",&(p_pro_acctent_struct_h -> h_report_tax));
	CO_Rtv_DataDbl(p_param_data,"REPORT_SER",&(p_pro_acctent_struct_h -> h_report_ser));
	CO_Rtv_DataDbl(p_param_data,"REP_EXG_RT",&(p_pro_acctent_struct_h -> h_rep_exg_rt));
	CO_Rtv_DataString(p_param_data,"REC_REFER",p_pro_acctent_struct_h -> h_rec_refer);
	CO_Rtv_DataString(p_param_data,"BATCH_DATE",p_pro_acctent_struct_h -> h_batch_date);
	CO_Rtv_DataString(p_param_data,"DEAL_IDENT",p_pro_acctent_struct_h -> h_deal_ident);
}






int Populate_PRO_CNTRY_SYS_PARAMS(PRO_CNTRY_SYS_PARAMS_STRUCT_H *p_pro_cntry_sys_params_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAIN_FUN",p_pro_cntry_sys_params_struct_h -> h_main_fun);
	CO_Rtv_DataString(p_param_data,"COND_FUN",p_pro_cntry_sys_params_struct_h -> h_cond_fun);
	CO_Rtv_DataString(p_param_data,"NATION",p_pro_cntry_sys_params_struct_h -> h_nation);
}






int Populate_PRO_COMMON_REPORT(PRO_COMMON_REPORT_STRUCT_H *p_pro_common_report_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"REPORT_NAME",p_pro_common_report_struct_h -> h_report_name);
	CO_Rtv_DataString(p_param_data,"REPORT_DESC",p_pro_common_report_struct_h -> h_report_desc);
	CO_Rtv_DataString(p_param_data,"REPORT_DATE",p_pro_common_report_struct_h -> h_report_date);
	CO_Rtv_DataInt(p_param_data,"REPORT_WIDTH",(int *) &(p_pro_common_report_struct_h -> h_report_width));
	CO_Rtv_DataString(p_param_data,"TASK_DESC",p_pro_common_report_struct_h -> h_task_desc);
	CO_Rtv_DataString(p_param_data,"FE_BE_IND",p_pro_common_report_struct_h -> h_fe_be_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_common_report_struct_h -> h_usr);
	
}






int Populate_PRO_DAEMON_STATUS(PRO_DAEMON_STATUS_STRUCT_H *p_pro_daemon_status_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_daemon_status_struct_h -> h_proc_name);
	CO_Rtv_DataInt(p_param_data,"STATUS_IND",(int *) &(p_pro_daemon_status_struct_h -> h_status_ind));
}






int Populate_PRO_EURO_TEMP(PRO_EURO_TEMP_STRUCT_H *p_pro_euro_temp_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_pro_euro_temp_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_pro_euro_temp_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_pro_euro_temp_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(p_param_data,"GRD_POS",&(p_pro_euro_temp_struct_h -> h_grd_pos));
	CO_Rtv_DataDbl(p_param_data,"UROUNDED_EUR",&(p_pro_euro_temp_struct_h -> h_urounded_eur));
	CO_Rtv_DataDbl(p_param_data,"EUR_AFTER_RND",&(p_pro_euro_temp_struct_h -> h_eur_after_rnd));
	CO_Rtv_DataString(p_param_data,"DF_IDENTNO",p_pro_euro_temp_struct_h -> h_df_identno);
	CO_Rtv_DataString(p_param_data,"RF_IDENT_NO",p_pro_euro_temp_struct_h -> h_rf_ident_no);
	CO_Rtv_DataString(p_param_data,"PROC_AREA",p_pro_euro_temp_struct_h -> h_proc_area);
	CO_Rtv_DataDbl(p_param_data,"ORIG_AMT",&(p_pro_euro_temp_struct_h -> h_orig_amt));
	CO_Rtv_DataDbl(p_param_data,"NEW_AMOUNT",&(p_pro_euro_temp_struct_h -> h_new_amount));
	CO_Rtv_DataString(p_param_data,"INFO",p_pro_euro_temp_struct_h -> h_info);
}






int Populate_PRO_FAILCODES(PRO_FAILCODES_STRUCT_H *p_pro_failcodes_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"FAILREASON_CD",p_pro_failcodes_struct_h -> h_failreason_cd);
	CO_Rtv_DataString(p_param_data,"FAILREASON_DET",p_pro_failcodes_struct_h -> h_failreason_det);
	CO_Rtv_DataString(p_param_data,"FAIL_DESC",p_pro_failcodes_struct_h -> h_fail_desc);
	CO_Rtv_DataString(p_param_data,"MAPWORD",p_pro_failcodes_struct_h -> h_mapword);
	CO_Rtv_DataInt(p_param_data,"SUB_FAIL_CD",(int *) &(p_pro_failcodes_struct_h -> h_sub_fail_cd));
	CO_Rtv_DataString(p_param_data,"STATUS_QUAL_IND",p_pro_failcodes_struct_h -> h_status_qual_ind);
	CO_Rtv_DataString(p_param_data,"STATUS_CD",p_pro_failcodes_struct_h -> h_status_cd);
	CO_Rtv_DataString(p_param_data,"REASON_QL",p_pro_failcodes_struct_h -> h_reason_ql);
	CO_Rtv_DataString(p_param_data,"REASON_CD",p_pro_failcodes_struct_h -> h_reason_cd);
	CO_Rtv_DataString(p_param_data,"SUPPORT_IND",p_pro_failcodes_struct_h -> h_support_ind);
}






int Populate_PRO_GMATCHVALUE(PRO_GMATCHVALUE_STRUCT_H *p_pro_gmatchvalue_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAPTYPE",p_pro_gmatchvalue_struct_h -> h_maptype);
	CO_Rtv_DataString(p_param_data,"MAPVALUE",p_pro_gmatchvalue_struct_h -> h_mapvalue);
	CO_Rtv_DataString(p_param_data,"MAP_VAL",p_pro_gmatchvalue_struct_h -> h_map_val);
}






int Populate_PRO_GRACCTENT(PRO_GRACCTENT_STRUCT_H *p_pro_gracctent_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MODULE_IND",p_pro_gracctent_struct_h -> h_module_ind);
	CO_Rtv_DataString(p_param_data,"PROC_NUM",p_pro_gracctent_struct_h -> h_proc_num);
	CO_Rtv_DataString(p_param_data,"BATCH_DATE",p_pro_gracctent_struct_h -> h_batch_date);
	CO_Rtv_DataString(p_param_data,"TYPEOFINSTR",p_pro_gracctent_struct_h -> h_typeofinstr);
	CO_Rtv_DataString(p_param_data,"REC_CLASS",p_pro_gracctent_struct_h -> h_rec_class);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_gracctent_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_pro_gracctent_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_pro_gracctent_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_pro_gracctent_struct_h -> h_currency_cd);
	CO_Rtv_DataInt(p_param_data,"DEAL_AMOUNT",(int *) &(p_pro_gracctent_struct_h -> h_deal_amount));
	CO_Rtv_DataString(p_param_data,"VAL_DT",p_pro_gracctent_struct_h -> h_val_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_pro_gracctent_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DB_CR_IND",p_pro_gracctent_struct_h -> h_db_cr_ind);
	CO_Rtv_DataString(p_param_data,"SPLGR_CLT_CD",p_pro_gracctent_struct_h -> h_splgr_clt_cd);
	CO_Rtv_DataString(p_param_data,"STATISTIC",p_pro_gracctent_struct_h -> h_statistic);
	CO_Rtv_DataString(p_param_data,"TRANS_BOG",p_pro_gracctent_struct_h -> h_trans_bog);
	CO_Rtv_DataInt(p_param_data,"QUANTITY_ITEMS",(int *) &(p_pro_gracctent_struct_h -> h_quantity_items));
	CO_Rtv_DataString(p_param_data,"OFFSET_CLIENT",p_pro_gracctent_struct_h -> h_offset_client);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_pro_gracctent_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"NATIONALITY",p_pro_gracctent_struct_h -> h_nationality);
	CO_Rtv_DataString(p_param_data,"INSTR_ISIN",p_pro_gracctent_struct_h -> h_instr_isin);
	CO_Rtv_DataString(p_param_data,"SPECIAL_TAX",p_pro_gracctent_struct_h -> h_special_tax);
	CO_Rtv_DataString(p_param_data,"IDENTIY_NO",p_pro_gracctent_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"AUTO_REC_IND",p_pro_gracctent_struct_h -> h_auto_rec_ind);
	CO_Rtv_DataString(p_param_data,"NOTE_A",p_pro_gracctent_struct_h -> h_note_a);
	CO_Rtv_DataString(p_param_data,"NOTE_B",p_pro_gracctent_struct_h -> h_note_b);
	CO_Rtv_DataInt(p_param_data,"FCCY_AMT",(int *) &(p_pro_gracctent_struct_h -> h_fccy_amt));
	CO_Rtv_DataInt(p_param_data,"MIS_SPRD",(int *) &(p_pro_gracctent_struct_h -> h_mis_sprd));
	CO_Rtv_DataInt(p_param_data,"AE_RATE",(int *) &(p_pro_gracctent_struct_h -> h_ae_rate));
	CO_Rtv_DataString(p_param_data,"POSITION",p_pro_gracctent_struct_h -> h_position);
	CO_Rtv_DataString(p_param_data,"SEQUENCE",p_pro_gracctent_struct_h -> h_sequence);
	CO_Rtv_DataString(p_param_data,"REAS_CD",p_pro_gracctent_struct_h -> h_reas_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_IDENT",p_pro_gracctent_struct_h -> h_deal_ident);
	CO_Rtv_DataInt(p_param_data,"REPORT_AMT",(int *) &(p_pro_gracctent_struct_h -> h_report_amt));
	CO_Rtv_DataInt(p_param_data,"LCL_AMT",(int *) &(p_pro_gracctent_struct_h -> h_lcl_amt));
}






int Populate_PRO_GSEQNUM(PRO_GSEQNUM_STRUCT_H *p_pro_gseqnum_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SEQUENCE_NAME",p_pro_gseqnum_struct_h -> h_sequence_name);
	CO_Rtv_DataInt(p_param_data,"LAST_USEDNUM",(int *) &(p_pro_gseqnum_struct_h -> h_last_usednum));
	CO_Rtv_DataString(p_param_data,"RECYCLE_IND",p_pro_gseqnum_struct_h -> h_recycle_ind);
	CO_Rtv_DataInt(p_param_data,"SEQ_STEPBY",(int *) &(p_pro_gseqnum_struct_h -> h_seq_stepby));
	CO_Rtv_DataInt(p_param_data,"SEQ_START",(int *) &(p_pro_gseqnum_struct_h -> h_seq_start));
	CO_Rtv_DataInt(p_param_data,"LAST_SEQNUM",(int *) &(p_pro_gseqnum_struct_h -> h_last_seqnum));
	CO_Rtv_DataString(p_param_data,"SEQ_ATTRB_A",p_pro_gseqnum_struct_h -> h_seq_attrb_a);
	CO_Rtv_DataString(p_param_data,"SEQ_ATTRB_B",p_pro_gseqnum_struct_h -> h_seq_attrb_b);
	CO_Rtv_DataString(p_param_data,"SEQ_ATTRB_C",p_pro_gseqnum_struct_h -> h_seq_attrb_c);
}






int Populate_PRO_GSHELPID(PRO_GSHELPID_STRUCT_H *p_pro_gshelpid_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_pro_gshelpid_struct_h -> h_nation_code);
	CO_Rtv_DataString(p_param_data,"NAMEOF_FORM",p_pro_gshelpid_struct_h -> h_nameof_form);
	CO_Rtv_DataInt(p_param_data,"HELP_IND",(int *) &(p_pro_gshelpid_struct_h -> h_help_ind));
}






int Populate_PRO_GSSPLVAL(PRO_GSSPLVAL_STRUCT_H *p_pro_gssplval_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAIN_FUN",p_pro_gssplval_struct_h -> h_main_fun);
	CO_Rtv_DataString(p_param_data,"SUB_PROCESS",p_pro_gssplval_struct_h -> h_sub_process);
	CO_Rtv_DataString(p_param_data,"FIELD_VAL",p_pro_gssplval_struct_h -> h_field_val);
	CO_Rtv_DataString(p_param_data,"NATION",p_pro_gssplval_struct_h -> h_nation);
}






int Populate_PRO_HDAT_STATIC(PRO_HDAT_STATIC_STRUCT_H *p_pro_hdat_static_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MEM_IDENT",p_pro_hdat_static_struct_h -> h_mem_ident);
	CO_Rtv_DataString(p_param_data,"INSTRUCT_CLT",p_pro_hdat_static_struct_h -> h_instruct_clt);
	CO_Rtv_DataString(p_param_data,"BRKCD",p_pro_hdat_static_struct_h -> h_brkcd);
	CO_Rtv_DataString(p_param_data,"ALTERNATE_BIDCD",p_pro_hdat_static_struct_h -> h_alternate_bidcd);
	CO_Rtv_DataString(p_param_data,"DETAIL",p_pro_hdat_static_struct_h -> h_detail);
	CO_Rtv_DataString(p_param_data,"MTCH_INFO",p_pro_hdat_static_struct_h -> h_mtch_info);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_hdat_static_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_pro_hdat_static_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_pro_hdat_static_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_pro_hdat_static_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_pro_hdat_static_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_pro_hdat_static_struct_h -> h_access_stamp);
}






int Populate_PRO_MQNAMES(PRO_MQNAMES_STRUCT_H *p_pro_mqnames_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"QUEUE_NAME",p_pro_mqnames_struct_h -> h_queue_name);
	CO_Rtv_DataString(p_param_data,"RPLY_QUEUE_NAME",p_pro_mqnames_struct_h -> h_rply_queue_name);
	CO_Rtv_DataString(p_param_data,"EVENT_CLASS",p_pro_mqnames_struct_h -> h_event_class);
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_pro_mqnames_struct_h -> h_nation_code);
}






int Populate_PRO_MQ_DATA(PRO_MQ_DATA_STRUCT_H *p_pro_mq_data_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"EVENT_CLASS",p_pro_mq_data_struct_h -> h_event_class);
	CO_Rtv_DataString(p_param_data,"BUSS_DATE",p_pro_mq_data_struct_h -> h_buss_date);
	CO_Rtv_DataInt(p_param_data,"IDENTITY_NO",(int *) &(p_pro_mq_data_struct_h -> h_identity_no));
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_mq_data_struct_h -> h_status_ind);
	
}






int Populate_PRO_MSGCONV(PRO_MSGCONV_STRUCT_H *p_pro_msgconv_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"CLIENT",p_pro_msgconv_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"SETL_EFFECTIVE_DATE",p_pro_msgconv_struct_h -> h_setl_effective_date);
	CO_Rtv_DataString(p_param_data,"STAT_EFF_DATE",p_pro_msgconv_struct_h -> h_stat_eff_date);
	CO_Rtv_DataString(p_param_data,"CA_EFFECTIVE_DT",p_pro_msgconv_struct_h -> h_ca_effective_dt);
	CO_Rtv_DataString(p_param_data,"STMSG_EFFECT_DATE",p_pro_msgconv_struct_h -> h_stmsg_effect_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_pro_msgconv_struct_h -> h_access_stamp);
}






int Populate_PRO_REQUEST_BATCH(PRO_REQUEST_BATCH_STRUCT_H *p_pro_request_batch_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REQUEST_SEQ",(int *) &(p_pro_request_batch_struct_h -> h_request_seq));
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_request_batch_struct_h -> h_proc_name);
	CO_Rtv_DataString(p_param_data,"PROC_AREA",p_pro_request_batch_struct_h -> h_proc_area);
	CO_Rtv_DataString(p_param_data,"ENVIRON_DATA",p_pro_request_batch_struct_h -> h_environ_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_pro_request_batch_struct_h -> h_proc_data);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_request_batch_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_request_batch_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"ERROR_DET",p_pro_request_batch_struct_h -> h_error_det);
}






int Populate_PRO_REQUEST_CA(PRO_REQUEST_CA_STRUCT_H *p_pro_request_ca_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REQUEST_SEQ",(int *) &(p_pro_request_ca_struct_h -> h_request_seq));
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_request_ca_struct_h -> h_proc_name);
	CO_Rtv_DataString(p_param_data,"ENVIRON_DATA",p_pro_request_ca_struct_h -> h_environ_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_pro_request_ca_struct_h -> h_proc_data);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_request_ca_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_request_ca_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"ERROR_DET",p_pro_request_ca_struct_h -> h_error_det);
}






int Populate_PRO_REQUEST_DEAL(PRO_REQUEST_DEAL_STRUCT_H *p_pro_request_deal_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REQUEST_SEQ",(int *) &(p_pro_request_deal_struct_h -> h_request_seq));
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_request_deal_struct_h -> h_proc_name);
	CO_Rtv_DataString(p_param_data,"ENVIRON_DATA",p_pro_request_deal_struct_h -> h_environ_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_pro_request_deal_struct_h -> h_proc_data);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_request_deal_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_request_deal_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"ERROR_DET",p_pro_request_deal_struct_h -> h_error_det);
	CO_Rtv_DataInt(p_param_data,"SMP_ID",(int *) &(p_pro_request_deal_struct_h -> h_smp_id));
	CO_Rtv_DataString(p_param_data,"SMP_IND",p_pro_request_deal_struct_h -> h_smp_ind);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_pro_request_deal_struct_h -> h_access_stamp);
}






int Populate_PRO_REQUEST_IV(PRO_REQUEST_IV_STRUCT_H *p_pro_request_iv_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REQUEST_SEQ",(int *) &(p_pro_request_iv_struct_h -> h_request_seq));
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_request_iv_struct_h -> h_proc_name);
	CO_Rtv_DataString(p_param_data,"ENVIRON_DATA",p_pro_request_iv_struct_h -> h_environ_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_pro_request_iv_struct_h -> h_proc_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_A",p_pro_request_iv_struct_h -> h_proc_data_a);
	CO_Rtv_DataString(p_param_data,"PROC_DATA_B",p_pro_request_iv_struct_h -> h_proc_data_b);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_request_iv_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_request_iv_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"ERROR_DET",p_pro_request_iv_struct_h -> h_error_det);
}






int Populate_PRO_REQUEST_MT(PRO_REQUEST_MT_STRUCT_H *p_pro_request_mt_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"REQUEST_SEQ",(int *) &(p_pro_request_mt_struct_h -> h_request_seq));
	CO_Rtv_DataString(p_param_data,"PROC_NAME",p_pro_request_mt_struct_h -> h_proc_name);
	CO_Rtv_DataString(p_param_data,"ENVIRON_DATA",p_pro_request_mt_struct_h -> h_environ_data);
	CO_Rtv_DataString(p_param_data,"PROC_DATA",p_pro_request_mt_struct_h -> h_proc_data);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_pro_request_mt_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"USR",p_pro_request_mt_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"ERROR_DET",p_pro_request_mt_struct_h -> h_error_det);
}






int Populate_PRO_REQUEST_UPLOAD(PRO_REQUEST_UPLOAD_STRUCT_H *p_pro_request_upload_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"UPLD_ID",(int *) &(p_pro_request_upload_struct_h -> h_upld_id));
	
}






int Populate_PRO_SGENSTAT(PRO_SGENSTAT_STRUCT_H *p_pro_sgenstat_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAP_TYPE",p_pro_sgenstat_struct_h -> h_map_type);
	CO_Rtv_DataString(p_param_data,"MAP_VAL",p_pro_sgenstat_struct_h -> h_map_val);
	CO_Rtv_DataString(p_param_data,"MAP_DESC",p_pro_sgenstat_struct_h -> h_map_desc);
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_pro_sgenstat_struct_h -> h_nation_code);
}






int Populate_PRO_SGENSTAT_BAK(PRO_SGENSTAT_BAK_STRUCT_H *p_pro_sgenstat_bak_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"MAP_TYPE",p_pro_sgenstat_bak_struct_h -> h_map_type);
	CO_Rtv_DataString(p_param_data,"MAP_VAL",p_pro_sgenstat_bak_struct_h -> h_map_val);
	CO_Rtv_DataString(p_param_data,"MAP_DESC",p_pro_sgenstat_bak_struct_h -> h_map_desc);
	CO_Rtv_DataString(p_param_data,"NATION_CODE",p_pro_sgenstat_bak_struct_h -> h_nation_code);
}






int Populate_PRO_SYS_DATE(PRO_SYS_DATE_STRUCT_H *p_pro_sys_date_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"SYS_DATE",p_pro_sys_date_struct_h -> h_sys_date);
	CO_Rtv_DataString(p_param_data,"EOD_IND",p_pro_sys_date_struct_h -> h_eod_ind);
}






int Populate_PRO_TEMP_MQDATA(PRO_TEMP_MQDATA_STRUCT_H *p_pro_temp_mqdata_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"EVENT_CLASS",p_pro_temp_mqdata_struct_h -> h_event_class);
	CO_Rtv_DataInt(p_param_data,"IDENTITY_NO",(int *) &(p_pro_temp_mqdata_struct_h -> h_identity_no));
	
}






int Populate_SYS_BATCHPROC(SYS_BATCHPROC_STRUCT_H *p_sys_batchproc_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROCESS_NAME",p_sys_batchproc_struct_h -> h_process_name);
	CO_Rtv_DataString(p_param_data,"STARTDATE",p_sys_batchproc_struct_h -> h_startdate);
	CO_Rtv_DataString(p_param_data,"STATUS_IND",p_sys_batchproc_struct_h -> h_status_ind);
	CO_Rtv_DataString(p_param_data,"PROC_INIT",p_sys_batchproc_struct_h -> h_proc_init);
	CO_Rtv_DataString(p_param_data,"PROCESSING_STATUS",p_sys_batchproc_struct_h -> h_processing_status);
	CO_Rtv_DataString(p_param_data,"USR",p_sys_batchproc_struct_h -> h_usr);
	CO_Rtv_DataString(p_param_data,"EOD_BOD_IND",p_sys_batchproc_struct_h -> h_eod_bod_ind);
	CO_Rtv_DataString(p_param_data,"STAT_DET",p_sys_batchproc_struct_h -> h_stat_det);
	CO_Rtv_DataString(p_param_data,"PROCESS_DESC",p_sys_batchproc_struct_h -> h_process_desc);
	CO_Rtv_DataInt(p_param_data,"PROC_ID",(int *) &(p_sys_batchproc_struct_h -> h_proc_id));
	CO_Rtv_DataString(p_param_data,"PROC_ENDFLG",p_sys_batchproc_struct_h -> h_proc_endflg);
}






int Populate_SYS_BATCHSTREAM(SYS_BATCHSTREAM_STRUCT_H *p_sys_batchstream_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"PROCESS_NO",(int *) &(p_sys_batchstream_struct_h -> h_process_no));
	CO_Rtv_DataString(p_param_data,"PROCESS_NAME",p_sys_batchstream_struct_h -> h_process_name);
	CO_Rtv_DataString(p_param_data,"PROC_IND",p_sys_batchstream_struct_h -> h_proc_ind);
	CO_Rtv_DataString(p_param_data,"TASK_CD",p_sys_batchstream_struct_h -> h_task_cd);
}






int Populate_SYS_BATCH_CNTRL(SYS_BATCH_CNTRL_STRUCT_H *p_sys_batch_cntrl_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"PROCESS_NAME",p_sys_batch_cntrl_struct_h -> h_process_name);
	CO_Rtv_DataString(p_param_data,"PRE_PROCESS",p_sys_batch_cntrl_struct_h -> h_pre_process);
	CO_Rtv_DataString(p_param_data,"MISMATCH",p_sys_batch_cntrl_struct_h -> h_mismatch);
}






int Populate_SYS_IVCONTROLPARAM(SYS_IVCONTROLPARAM_STRUCT_H *p_sys_ivcontrolparam_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"B_PREV_DATE",p_sys_ivcontrolparam_struct_h -> h_b_prev_date);
	CO_Rtv_DataString(p_param_data,"B_UPTO_DATE",p_sys_ivcontrolparam_struct_h -> h_b_upto_date);
	CO_Rtv_DataString(p_param_data,"B_PROCESSDT",p_sys_ivcontrolparam_struct_h -> h_b_processdt);
	CO_Rtv_DataString(p_param_data,"B_DLV_DATE",p_sys_ivcontrolparam_struct_h -> h_b_dlv_date);
	CO_Rtv_DataString(p_param_data,"GENERATE_IND",p_sys_ivcontrolparam_struct_h -> h_generate_ind);
	CO_Rtv_DataString(p_param_data,"AE_IND",p_sys_ivcontrolparam_struct_h -> h_ae_ind);
	CO_Rtv_DataString(p_param_data,"LAST_DLV_DATE",p_sys_ivcontrolparam_struct_h -> h_last_dlv_date);
	CO_Rtv_DataString(p_param_data,"ARCHIVAL_DT",p_sys_ivcontrolparam_struct_h -> h_archival_dt);
	CO_Rtv_DataString(p_param_data,"LAST_RPT_DATE",p_sys_ivcontrolparam_struct_h -> h_last_rpt_date);
	CO_Rtv_DataString(p_param_data,"B_GEN_IND",p_sys_ivcontrolparam_struct_h -> h_b_gen_ind);
}






int Populate_TEMP12(TEMP12_STRUCT_H *p_temp12_struct_h,char * p_param_data)
{
	CO_Rtv_DataString(p_param_data,"FLD1",p_temp12_struct_h -> h_fld1);
	CO_Rtv_DataString(p_param_data,"FLD2",p_temp12_struct_h -> h_fld2);
	CO_Rtv_DataString(p_param_data,"FLD3",p_temp12_struct_h -> h_fld3);
}






int Populate_TT(TT_STRUCT_H *p_tt_struct_h,char * p_param_data)
{
	CO_Rtv_DataDbl(p_param_data,"FLD1",&(p_tt_struct_h -> h_fld1));
}






int Populate_YEARLY_AE(YEARLY_AE_STRUCT_H *p_yearly_ae_struct_h,char * p_param_data)
{
	CO_Rtv_DataInt(p_param_data,"YR",(int *) &(p_yearly_ae_struct_h -> h_yr));
	CO_Rtv_DataInt(p_param_data,"MONTH",(int *) &(p_yearly_ae_struct_h -> h_month));
	CO_Rtv_DataDbl(p_param_data,"INVOICE",&(p_yearly_ae_struct_h -> h_invoice));
	CO_Rtv_DataDbl(p_param_data,"PAYMENTS",&(p_yearly_ae_struct_h -> h_payments));
}

