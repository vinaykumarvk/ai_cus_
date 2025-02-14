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












 
#ifndef EXTENDED_HEADER_INCLUDED
#define EXTENDED_HEADER_INCLUDED

extern int CO_Chk_CodeValid( 
								   char          *p_code_typ, 
									char          *p_code_val, 
									char          *chr_p_country_code, 
									DEBUG_INFO_STRUCT_H  **l_debug_info_ptr
								 );



extern int CR_Mod_ExgRt (MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h_a,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Mod_DBExgRt (MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h_a,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int MT_Chk_ExgRt(char *p_ccycode,char *p_denomccycode,char *p_date,char p_pcexist,char p_pcauth,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_ExgRtMkrChkr(char *p_currency,char *p_denom_currency,char *p_date,char *p_user,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CO_Chk_CcyValid(char *p_ccycode,char p_type,char p_exist,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);   



extern int CR_Mod_Loc (MT_LOCATION_STRUCT_H *p_mt_location_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Mod_DBLoc (MT_LOCATION_STRUCT_H *p_mt_location_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int MT_Chk_Loc(char *p_loccode,char p_pcexist,char p_pcauth,char p_pcdel,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_LocMkrChkr(char *p_location,char *p_user,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_SecAtLoc(char *p_location,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_PosAtLoc(char *p_location,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_PymtAtLoc(char *p_location,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_TrdAtLoc(char *p_location,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Mod_Hol (MT_HOLIDAY_STRUCT_H *,INTL_ENV_DATA_STRUCT_H *,DEBUG_INFO_STRUCT_H **);
extern int CR_Mod_WklyHol (MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a_b, MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_h, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Mod_DBHol (MT_HOLIDAY_STRUCT_H *,INTL_ENV_DATA_STRUCT_H *,DEBUG_INFO_STRUCT_H **);
extern int CR_Mod_DBWklyHol (MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_a_b, MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_h, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int MT_Chk_Hol(char *p_holi_date,char *int_pcexist,char *pcauth,char *p_pcdel,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *p_exch_code);
extern int CR_Chk_HolMkrChkr(char *p_holi_date,char *p_user,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *p_exch_code);



extern int CR_Mod_Ccy( DL_CURRENCY_STRUCT_H   *p_dl_currency_struct_h,
							  INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
						  DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
							);

extern int CR_Chk_CanCCYDel( char          *p_ccycode,
				   DEBUG_INFO_STRUCT_H  **l_debug_info_ptr
				 );


extern int CR_Mod_DBCcy( DL_CURRENCY_STRUCT_H   *p_dl_currency_struct_h,
				   INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
			DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
		      );





extern int MT_Mod_WTaxRt(MT_WHTRATE_STRUCT_H    *p_mt_whtrate_struct_h,
							 INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
							 DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
						   );


extern int MT_Mod_DBWTaxRt( MT_WHTRATE_STRUCT_H    *p_mt_whtrate_struct_h,
								INTL_ENV_DATA_STRUCT_H   *p_intl_env_data_struct_h_e,
							   DEBUG_INFO_STRUCT_H         **l_debug_info_ptr
							 );


extern int MT_Chk_WHTax(char *p_cntrycode, char *p_prodateype, char p_pcexist,
							  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Mod_AE( MT_CLIENT_ENTRIES_STRUCT_H    *p_mt_client_entries_struct_h_a,
							   INTL_ENV_DATA_STRUCT_H      *p_intl_env_data_struct_h_e,
								DEBUG_INFO_STRUCT_H            **l_debug_info_ptr
							 );





extern int CR_Mod_DBCashAcc(DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha,char *p_row_id, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Chk_Acc(MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h_b, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SubAcc(char *chr_p_acct, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAccMsgAddrDel(char *chr_p_acct, char *p_msg_num, int p_addrseq_num, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_AccSchDel(char *chr_p_acct, char *p_msg_num, char *p_msgoption, int p_schseq_num, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccAuth(char *chr_p_acct, char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAccMemo(char *chr_p_acct,char *p_row_id_cltt,char *chr_p_memo, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_DBAccMsgAddrCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *p_row_id_to_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Mod_DBCashAcc(DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha, char *p_row_id_cltt, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CR_Proc_DBAccSchCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *p_row_id_to_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_DBAccMemoCpy(char *chr_p_from_acct, char *chr_p_to_acct, char *p_row_id_to_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAccSch(MT_SCHDET_STRUCT_H *l_mt_schdet_struct_ha_a,char *p_row_id_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAccMsgAddr(MT_MSGADDRESS_STRUCT_H *l_mt_msgaddress_struct_h,char *p_row_id_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAccOth(char *chr_p_acct,char *p_row_id_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_DBAcc(MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h_b,char *p_row_id_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int MT_Rtv_AccFldVal(char *chr_p_acct, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CR_Rtv_CashAccFldVal(char *chr_p_acct,char *p_ibbsclt,char *p_currencycode,char *p_defflg,char *p_nondefflg,char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccMsgAddr(char *chr_p_acct,char *chr_p_msgno_a,int p_addrseq_num,char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_AccSchFldVal(char *chr_p_acct,char *chr_p_msgno_a,char *p_msgoption,int p_schseq_num,char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccEntl(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccIVSetup(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccTrd(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccPos(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccOrd(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccDomPtyTrd(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_AccBrkOrd(char *chr_p_acct,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_AccSchDupl(char *chr_p_acct,char *chr_p_msgno_a,int int_paddrseq_num,char *p_msgoption,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Chk_CashAccDupl(DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha,DL_CASHACC_STRUCT_I *l_dl_cashacc_struct_i_ptr,char p_ind,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CR_Chk_AccMsgAddrDupl(MT_MSGADDRESS_STRUCT_H *l_mt_msgaddress_struct_h,MT_MSGADDRESS_STRUCT_I *l_mt_msgaddress_struct_i_ptr,char p_ind,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_AccMsgAddrCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_time_stamp,char *chr_p_to_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_AccSchCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_time_stamp,char *chr_p_to_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_AccMemoCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_AccMemo(char *chr_p_acct,char *chr_p_memo,char *chr_p_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_AccSch(MT_SCHDET_STRUCT_H *l_mt_schdet_struct_ha_a,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_AccMsgAddr(MT_MSGADDRESS_STRUCT_H *l_mt_msgaddress_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_Acc(MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h_b,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_AccOth(char *chr_p_acct,char *chr_p_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CO_Chk_AccValid(char *p_client,char p_exist,char p_cubk,char p_orderac,char p_mastclt,char p_auth,char p_del,char p_frozen,char p_closed,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int IV_Rtv_Bill_FrmGendt_DlvDt(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);





extern int DL_Proc_PosCalc(       char *p_client, 
									char *p_mt_instrument_struct_h, 
									char *p_location, 
									char *p_posnstatus, 
									char *p_date, 
									char *p_type, 
									double *h_l_retposn, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_VDPPocCalc(        char *chr_p_startdt,
									char *chr_p_enddt,
									char *chr_p_client,
									char *p_securitycd,
									char *p_location,
									char *p_status_ind,
									double *p_start_qty,
									double *p_calc_qty,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );                  

extern int DL_Chk_VDPPos(        char     *chr_p_client,
									char     *p_securitycd, 
									char     *p_location, 
									char     *p_status_ind,
									double  p_quantity,
									char   *p_dt, 
									int    *int_p_enuf,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Mod_Posn(       char *p_client, 
									char *p_mt_instrument_struct_h, 
									char *p_location, 
									char *p_posnstatus, 
									char p_postype, 
									char p_trcode, 
									double *p_qty, 
									char p_incdec, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_CLHAudTrail(      DL_DEALAUDIT_STRUCT_H *p_dl_dealaudit_struct_h, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_PosLock(      char *p_client,
									char *p_secode,
									char *p_locncode,
									char *p_posnstatus,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
 
extern int DL_Chk_AvlPos(      char *p_client,
									char *p_secode,
									char *p_locncode,
									char p_incconf,
									double *p_availqty,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
 
extern int DL_Chk_TrCdSec(      char *p_securitycd, 
									char p_dealcd, 
									char *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Chk_FXAcc(     char *p_client, 
										char p_trcode, 
										char *p_fxrqflg, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Chk_LRRefTrd(    char *chr_p_client,
										char *chr_p_refno,
										char *p_locident, 
										short *p_locrefexists, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Rtv_TrdRprChrVal(   int *int_p_trdrepseqnum,
										char *p_ind,
										char *int_p_retval,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_MvToHisAud(      char *chr_p_client, 
									char *chr_p_refno, 
									char    p_dealordflg,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Proc_MvToHisTrd(      char *chr_p_client, 
									char* chr_p_refno, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Proc_MvToHisReg(      char *chr_p_client, 
									char* chr_p_refno, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Proc_MvToHisOrd(      char *chr_p_client, 
									char* p_orderident, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Rtv_TrdChrVal(      char *p_client, 
									char *p_indentity_no, 
									char *p_ind, 
									char *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Rtv_TrdNumVal(      char *p_client, 
									char *p_indentity_no, 
									char *p_ind, 
									double *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Chk_DLDet(         char *p_client, 
									char *p_ident, 
									char p_exist, 
									char p_auth, 
									char p_del, 
									char p_conf, 
									char p_parconf, 
									char p_secsetl, 
									char p_moneysetl,
									char p_manifld, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Rtv_DLDropToHis(     char            *p_secdate,
										char            *p_moneydate,
										char            *p_posnstatus,
										char             p_trcode,
										double  *p_mcomplqty,
										double  *p_complqty,
										double  *p_qty,
										char            *p_candropdate_a,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Proc_TrdOth(       DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_c,
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Mod_DLPos(      DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_a,
									char *p_ora_rowid,  
									INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
 
extern int DL_Mod_DLFailReas(     DL_DEAL_FAIL_STRUCT_H *p_dl_deal_fail_struct_h,
										INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,        
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Proc_Trd(  SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_a, 
								int *int_p_trdrepseqnum, 
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
 
extern int DL_Mod_DL( SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h,
								char *p_ora_rowid,
								int *int_p_trdrepseqnum,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );
 
extern int DL_Mod_NDS( DL_DEAL_NDS_STRUCT_H *p_dl_deal_nds_struct_h_a, 
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
								DEBUG_INFO_STRUCT_H             **l_debug_info_ptr );

extern int CO_Round(     double chr_p_val,
							int      p_prec,
							double *int_p_retval);

extern int CO_ToStr(  double chr_p_val,
								int      p_totlen,
								int      p_declen,
								char    *int_p_retval);

extern int CO_Trim(        char  *p_in_str,
									char  p_char_to_be_removed,
									char  p_left_right_ind,
									char  *p_out_str,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int   CO_Rtv_Time( unsigned long *p_seconds, long *p_microsecs); 
															

extern int CO_Pro_LocRec(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Con_Db(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Mod_Batch_Status(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int CO_Rtv_FldValChar(   char *p_target_fld, 
										char *p_table, 
										char *p_source_fld, 
										char *p_fld_value, 
										char *int_p_retval, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Rtv_FldValNum(    char *p_target_fld, 
										char *p_table, 
										char *p_source_fld, 
										char *p_fld_value, 
										double *int_p_retval, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Mod_DLPmt(      DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
										INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Mod_DLPmtChng(      DL_DEAL_PMTCHG_STRUCT_H *p_dl_deal_pmtdet_struct_h_d,
										INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Mod_DLRegStat(                DL_REGDET_STRUCT_H *p_dl_regdet_struct_h_a,
										REQDETAILS_STRUCT_H *p_reqdetails_struct_h_a,
										INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_PosChkMod(          DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
					char *p_securitycd,
				      char *p_location,
					     char *p_status_ind,
					    char *p_dealcd,
					   short p_isecdate,
					     char *p_old_status,
					    double p_quantity,
					   char  p_chk_or_upd,
					     int *p_success_flg,
					    DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Proc_DLSetlSing(      DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,
                   char            *p_eventid,
					    INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CO_Rtv_RptFileName(     char *p_rep_st,
					char *p_rep_desc,
				      int   p_repwidateh,
					     char *p_funcdesc,
										char **argv,
					    FILE **p_file_handle,
					   DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Prnt_AmtHdr_WrRpt(     FILE *fp,
											DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Prnt_UnMtHdr(    FILE *fp,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Prnt_AmtFmt_WrRpt(     FILE *fp,
										  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Prnt_UnMtFmt(    FILE *fp);

extern int DL_Mod_AutMtDel(      DL_DEAL_AMT_STRUCT_H *p_dl_deal_amt_struct_h,
					     char  p_recdelflg,
					    FILE *p_fp_match,
					   FILE *p_fp_unmatch,
					     FILE *p_logfile,
					    int  *p_no_match,
					   int  *p_no_unmatch,
					     char *chr_p_now,
					    char **argv,
					   INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_AutMt(                  DL_DEAL_AMT_STRUCT_H *p_dl_deal_amt_struct_h,
						char **argv,
						FILE *p_logfile,
					   INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						   DEBUG_INFO_STRUCT_H **l_debug_info_ptr);





extern int CR_Mod_Sec(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a,char *p_row_id_sec,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_SecDet(char *p_sec_code,char *p_row_id_sec,DEAL_ORD_STRUCT_H *p_deal_ord_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecDet(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_ChldSec(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_SecMkrChkr(char *p_sec_code,char *p_user,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_SecChrVal(char *p_sec_code,char *p_link_val,char *p_field_val,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecEvent(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecTrd(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_SecOrd(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_SecPos(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int CR_Chk_SecPosPosnstat(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecLRRpt(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecPymtTrd(char *p_sec_code,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int MT_Mod_Sec(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h_a,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int MT_Mod_SecOth(char *p_sec_code,char *p_sec_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int MT_Rtv_DLOrdFldVal(char *p_cls_code,DEAL_ORD_STRUCT_H *p_deal_ord_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecISINUnique(char *p_sec_code,char *chr_p_isin,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecCodeUnique(char *p_sec_code,char *p_table_name,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CR_Mod_NewSecConv(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_SecConv(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,char *p_row_id_from_sec,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecConvCyclic(char *p_from_sec,char *p_row_id_to_sec,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecConvClass(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,char *p_row_id_from_sec,char *p_row_id_to_sec,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecConvOrd(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_VerPymtTrd(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Proc_DBSecConvAuth(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_PosSecConv(char *p_from_sec,char *p_parri_passu_flg,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_TrdSecConv(char *p_from_sec,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_OrdSecConv(char *p_from_sec,char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_SecIn(char *p_from_sec,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBProcessTradeRecFn(char *p_from_sec,SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_d,SYS_DL_DEAL_STRUCT_I *p_sys_dl_deal_struct_i_b,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_OrdSecConv(char *p_from_sec,OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_a,OR_ORDERDETAILS_STRUCT_I *p_or_orderdetails_struct_i,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_PosSecConv(char *p_from_sec,int *p_ident_count,char *p_parri_passu_flg,FILE *p_instr_conv_rpt_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DL_SAFEK_STRUCT_H *p_dl_safek_struct_h,DL_SAFEK_STRUCT_I *p_dl_safek_struct_i,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CR_Prnt_SecConvRptHdr(FILE *p_instr_conv_rpt_file,char *p_from_sec,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CR_Prnt_SecConvRptFtr(FILE *p_instr_conv_rpt_file,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CR_Prnt_SecConvRpt(FILE *p_instr_conv_rpt_file,char *p_from_sec,char *p_trade_type,char *chr_p_client,char *chr_p_refno,double p_quantity,char *p_location,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CA_DatabaseConnect(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CA_Proc_Final(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CA_LockRec(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



int     DL_Prnt_MPRecDelS(    DL_MANIFLD_STRUCT_H *p_dl_maniprnt_struct_h,
							char *chr_l_now,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int     DL_Prnt_MPTempS(    DL_MANIFLD_STRUCT_H *p_dl_maniprnt_struct_h,
							REQDETAILS_STRUCT_H *p_reqdetails_struct_h_b,
							char *chr_l_now,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int     DL_Prnt_MPRecDelB(    DL_MANIFLD_STRUCT_H *p_dl_maniprnt_struct_h,
							char *chr_l_now,
							char **argv,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int     DL_Prnt_MPTempB(    DL_MANIFLD_STRUCT_H *p_dl_maniprnt_struct_h,
							char *chr_l_now,
							char **argv,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int DL_Proc_MPPrnt(       DL_MANIPRNT_STRUCT_H               *p_dl_maniprnt_struct_h,
									char                                            *chr_p_now,
									FILE                                            *p_logfile,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

int DL_Proc_MP(        DL_MANIFLD_STRUCT_H *p_dl_maniprnt_struct_h,
						REQDETAILS_STRUCT_H *p_reqdetails_struct_h_b,
						char    **argv,
						FILE *p_logfile,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



int     DL_Proc_GbSetl(     char                                            *p_stx_secdate,
						char                                            *p_stx_moneydate,
						char                                            *p_oth_secdate,
						char                                            *p_oth_moneydate,
						char                                            **argv,
						char                                    *chr_l_sectype,
						char                 *chr_l_trdtypeind,
						char                 *p_trade_status,
						char                 *chr_p_confdt,
						char                 *p_location,
                    char                 *p_settle_no,
                    char                 *p_mkttype,
                                                char                 *p_deal_dt, //PMS
						FILE                                            *p_logfile,
						FILE                                            *p_gsf_repfile,
						FILE                                            *p_gss_repfile,
						INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );




extern int DL_Mod_DLRegStat( DL_REGDET_STRUCT_H               *p_dl_regdet_struct_h,
								REQDETAILS_STRUCT_H         *p_reqdetails_struct_h,
								INTL_ENV_DATA_STRUCT_H      *p_intl_env_data_struct_h,
								DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

extern int DL_Proc_DLRegStat(        DL_REGDET_STRUCT_H                *p_dl_regdet_struct_h,
									INTL_ENV_DATA_STRUCT_H      *p_intl_env_data_struct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

extern int DL_Proc_Reg(     char            *chr_p_client,
										char            *chr_p_refno,
										char            *p_delrecdate,
										char            *p_txndate,
										double  *p_quantity,
										double  *p_qtymoved,
										char            p_regstcode,
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
										DEBUG_INFO_STRUCT_H    **l_debug_info_ptr );




extern int CR_Proc_DLPmtRst ( char *p_client,
								char *p_indentity_no,
								char *chr_p_time_stamp,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Rtv_DLPmtRst(      char *p_client,
									char *p_indentity_no,
									DL_DEAL_RSTPMT_STRUCT_H *l_dl_deal_rstpmt_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CR_Proc_DLSetlRst ( char *p_client,
								char *p_indentity_no,
								char *chr_p_action,
								char *chr_p_time_stamp,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_DLSetlRst(DL_DEAL_RSTSST_STRUCT_H *l_dl_deal_rstsst_struct_h,
						      char *chr_p_action,char *chr_p_time_stamp,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Proc_DLSetlTxnRst(DL_DEAL_RSTSST_STRUCT_H *l_dl_deal_rstsst_struct_h,
					int *p_flag,char *chr_p_time_stamp,
					int,
					INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Proc_DLSetlPosRst(    DL_DEAL_RSTSST_STRUCT_H *l_dl_deal_rstsst_struct_h,
						int *p_flag,char *chr_p_time_stamp,
					INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Rtv_DLSetlRst(     char *p_client,
					char *p_indentity_no,
					DL_DEAL_RSTSST_STRUCT_H *l_dl_deal_rstsst_struct_h,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CDBStRstLcnChkFn(char *chr_p_client,
			char *chr_p_refno,
			char *p_loccode,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Chk_MsgSnt(     char *p_msg_no,
					char *chr_p_key,
					char *p_client,
					char *p_settledate,
					INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CO_DB_Connection_O(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DoFinalProcessingFn1(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int LockRecFn1(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_ClrHs_po(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_ClrHs_cz(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_ClrHs_hu(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Clh_DlFn(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBEodProFn(char **argv,FILE *p_ptr_ini_file,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CBRecsInClhTrFn(char *chr_p_client,char *p_securitycd,char *p_recdel,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int CDBGenClEntryTrFn(FILE *p_ptr_clh_tr_file,char *chr_p_client,char *p_countclt,char *p_dbcltt,char *p_securitycd,char *p_newissue,char *p_crcltt,double p_quantity,char *p_conf_date,char *p_recdel,char *p_typeofdeal,double chr_p_amount,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CDBGenBrkEntryTrFn(FILE *p_ptr_clh_tr_file,char *chr_p_client,char *p_dbcltt,char *p_countclt,char *p_securitycd,char *p_newissue,double p_quantity,FILE *p_ptr_log_file,int p_flg_typ_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Prnt_ClhRpt_Hdr_cz(FILE *p_ptr_clh_rpt_file,char *p_file_type,int p_page_no,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Prnt_ClhRpt_cz(FILE *p_ptr_clh_rpt_file,char *p_isin,char *p_dealcd,double chr_p_amount,double p_quantity,char *p_ourtheir,char *chr_p_refno,char *p_internal_txn,char *chr_p_confdt,char *p_setldt,char *p_verwith,char *p_clhclient,char *p_custreg,char *p_domcpac,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int WriteReportHeaderForHuFn(FILE *p_ptr_clh_file,int p_page_no,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int WriteReportDetailsForHuFn(FILE *p_ptr_clh_rpt_file,char *chr_p_refno,char *chr_p_client,double p_quantity,double chr_p_amount,char *chr_p_cname,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int WriteCustReportHeaderForTrFn(FILE *p_ptr_clh_rpt_file,int p_page_no,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int WriteBrokReportHeaderForTrFn(FILE *p_ptr_clh_rpt_file,int p_page_no, int p_reptype, FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int WriteErrorReportHeaderForTrFn(FILE *p_ptr_clh_rpt_file,int p_page_no,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int WriteCustReportDetailsForTrFn(FILE *p_ptr_clh_rpt_file,char *chr_p_client,char *p_clhclient,char *p_securitycd,char *p_newissue,char *p_conf_date,double p_quantity,char *p_recdel,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int WriteBrokReportDetailsForTrFn(FILE *p_ptr_clh_rpt_file,char *p_domcpac,char *p_clhclient,char *chr_p_refno,char *p_securitycd,char *p_newissue,char *p_conf_date,char *p_dealcd,double p_quantity, char *chr_p_amount, FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int WriteErrorReportDetailsForTrFn(FILE *p_ptr_clh_rpt_file,char *chr_p_client,char *chr_p_refno,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CO_DB_Connection_A(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOD_Mod_HisPosBkSetl(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_BkSetl(char **argv, FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Commit(void);



extern int CR_Proc_CLHRstSingle(char *chr_p_client,char *chr_p_refno,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_DBCLHRstSingle(char *chr_p_client,char *chr_p_refno,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CR_Proc_MrktPr ( MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h, 
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_MkrtPr(     MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h,
										INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_MkrtPrAuth(    char *p_dt,
										char *p_securitycd,
										char *p_user,
										char *p_mode,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int DL_Mod_MisTxn(  DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h, 
								char *cmistxnident,
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_MisTxnr( DL_MISDEAL_STRUCT_H *p_dl_misdeal_struct_h, 
								char *p_mistxnident, 
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_MisTxnrAuth(     char *chr_p_client, 
										char *chr_p_refno, 
										char *p_user,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_MisTxnrRefNo(      char *p_mistxnident, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_MsgAddr(    char *p_h_client, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CO_DB_Connection_B(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_DBCLHRstGlobal(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Prnt_CLHRstRptGlobal(FILE *p_clh_rst_rpt_file,char *chr_p_client,char *chr_p_refno,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CO_DB_Connection_C(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int MT_Proc_INAAcc(FILE *p_ptr_log_file,char **argv,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_TrdHisTrd(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Prnt_ClosedINAAccRpt(FILE *p_cls_inactive_cltts_rpt_file,char *chr_p_acct,char *p_cltt_name,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Prnt_OpenINAAccRpt(FILE *p_inactive_cltts_rpt_file,char *chr_p_acct,char *p_cltt_name,char *p_desc,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_CPEntlForAcc(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_BillSetupForAcc(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_SafekForAcc(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_TrdWithDomCP(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_SubAccForAcc(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Chk_OrdForAcc(char *chr_p_acct,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CR_Proc_SecCdChg(        DL_INSTRUMENTCHG_STRUCT2_H       *l_dl_instrumentchg_struct2_ha,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

extern int CR_Rtv_SecChngDet(      char    *p_oldsecode,
									char    *chr_p_time_stamp,
									char    *p_chgmaker,
									char    *p_listedflg,
									DEBUG_INFO_STRUCT_H    **l_debug_info_ptr);

extern int CR_Proc_SecChngMkrChr(      char    *p_securitycd,
									char    *p_user,
									DEBUG_INFO_STRUCT_H    **l_debug_info_ptr);

extern int CR_Mod_SecChngDet(       DL_INSTRUMENTCHG_STRUCT2_H       *l_dl_instrumentchg_struct2_ha,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );



extern int DL_Proc_SecCodeLock(      DL_INSTRUMENTCHG_STRUCT2_H               *l_dl_instrumentchg_struct2_ha,
									FILE                                            *p_logfile,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );                                       
extern int DL_Mod_SecCode(       DL_INSTRUMENTCHG_STRUCT2_H               *l_dl_instrumentchg_struct2_ha,
									FILE                                            *p_logfile,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

extern int DL_Proc_SecCodeChg(      char    *old_sec_cd,
									char    **argv,
									FILE    *p_logfile,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );
						


extern int DL_Proc_AccEntRst(char *p_dt,char *p_batch_no,FILE *p_ptr_log_file,char **argv,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Proc_AccEntWrRpt(FILE *p_cltt_entries_rst_rpt_file,char *chr_p_acct,char *chr_p_refno,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Rtv_OrdRefNo(     char    *chr_p_client,
										char    *p_orderident,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Mod_Ord(  OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b,
								char *p_orderident,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Chk_Ord( char *p_client, 
								char *p_indentity_no, 
								char p_exist, 
								char p_auth, 
								char p_del, 
								char p_cancel,
								char p_exec,
								char p_exectyp,
								char p_expire,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );


extern int CR_Mod_CustCashBal(      char            *chr_p_client,
									double  *p_quantity,
									double  *p_oldqty,
									double  *p_lmtprc,
									double  *p_oldlmtprc,
									char            p_buysellflg,
									double  *p_brkgcomm,
									DEBUG_INFO_STRUCT_H    **l_debug_info_ptr );


extern int CR_Chk_CustCashBal(      char            *chr_p_client,
									double  *p_quantity,
									double  *p_lmtprc,
									short           *int_p_retval,
									DEBUG_INFO_STRUCT_H    **l_debug_info_ptr );


extern int CR_Rtv_OrdChrVal(      char *chr_p_client, 
									char *chr_p_refno, 
									char *p_ind, 
									char *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CR_Rtv_OrdNumVal(      char *chr_p_client, 
									char *chr_p_refno, 
									char *p_ind,    
									double *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int CR_Mod_DBOrd( OR_ORDERDETAILS_STRUCT_H         *p_or_orderdetails_struct_h_b,
								char                                            *p_ora_rowid,
								INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );


extern int DL_Chk_Pos(       char    *chr_p_client,
									char    *p_securitycd,
									char    *p_loccode,
									double *p_quantity,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );




extern int CR_Proc_OrdExecRst(     char *chr_p_client,
										char *p_dealident,
										char *p_deal_access_stamp,
										char *p_ord_access_stamp,
										INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



extern int CR_Mod_OrdExec( DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_b,
								ORDERDETAILS_STRUCT_H         *p_orderdetails_struct_h,
								INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr );

extern int CR_Proc_OrdExec(        DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_a,
					ORDERDETAILS_STRUCT_H      *p_orderdetails_struct_h,
									char                                            *p_ora_rowid,
					INTL_ENV_DATA_STRUCT_H   *p_intl_envdatastruct_h,
					DEBUG_INFO_STRUCT_H         **l_debug_info_ptr );

extern int CR_Rtv_OrdTrd(      DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_a,
					INTL_ENV_DATA_STRUCT_H   *p_intl_envdatastruct_h,
				DEBUG_INFO_STRUCT_H         **l_debug_info_ptr );



extern int CR_Rtv_CCYFldVal(      char *p_currencycode, 
									char *p_ind,    
									int *int_p_retval, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CR_Proc_LocChg(       DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h,
									char *cseqno,
									INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_LocChgInitTrd(    SYS_DL_DEAL_STRUCT_H *l_sys_dl_deal_struct_hl,
										DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h_a,
										char p_cdealcode[3],
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_LocChgTrdStat(      SYS_DL_DEAL_STRUCT_H *l_sys_dl_deal_struct_hl, 
									DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h_a, 
									char *p_ctodays_date, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_LocChg(      DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h_a,
									char *p_locchgseqno, 
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_LocChgMkrChkr(char *chr_p_client, 
										char *p_seqno, 
										char *p_user,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LocChgRefNo(   char *p_locchgseqno, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LocChgTrdRefNo(    char *p_dfident,
										char *p_rfident, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_LocChgPosStat(     SYS_DL_DEAL_STRUCT_H *l_sys_dl_deal_struct_hl, 
										char *p_securitycd, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern  int CBDoRegnFn( REG_TRF_STRUCT_H *p_reg_trf_struct_h,
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_BkClose(   BCL_TRF_STRUCT_H *p_bcl_trf_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Rtv_PosBkCl(      char *chr_p_client, 
									char *p_securitycd, 
									char *p_loccode,
									double *p_quantity,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_PosRegBkCl(      char *chr_p_client, 
									char *p_securitycd, 
									char *p_loccode,
									double *p_quantity,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_RefNoBkClTrd(      char *chr_p_now, 
									char *chr_p_refno,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Rtv_TrdBkCl(      BCL_TRF_STRUCT_H *p_bcl_trf_struct_h,
									char p_recdel_flg,
									char *chr_p_now,
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CR_Mod_BkCl(  BCL_TRF_STRUCT_H *p_bcl_trf_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



int DL_Mod_AccEntNew(     char    *p_batch_no,
							PRO_ACCTENT_STRUCT_H       *p_pro_acctent_struct_h_a,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int DL_Proc_DateFmt(     char    *p_sdate,
							char    *p_tdate,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int DL_Rtv_OthFrmOrd(     char *p_batch_no,
							char *p_deal_rowid,
							FILE *p_logfile,
							char **argv,
							int  *p_runseq,
							double *p_dct,
							double *p_cct,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CDBPassRevFn(       char *p_batch_no,
						char *p_ora_rowid,
						FILE *p_logfile,
						char **argv,
						int  *p_runseq,
						double *p_dct,
						double *p_cct, 
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CDBPassNewFn(       char *p_batch_no,
						char *p_deal_rowid,
						char p_fresh_chg_ent,
						FILE *p_logfile,
						char **argv,
						int  *p_runseq,
						double *p_dct,
						double *p_cct,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Rtv_NewAccEnt(      char *p_batch_no,
							FILE *p_logfile,
							char **argv,
							int  *p_runseq,
							double *p_dct,
							double *p_cct,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Rtv_ChngStatus(     char *p_ora_rowid,
							char *p_deal_rowid,
							char *p_passrevchg_entry,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CR_Proc_AccEnt(     char *p_batch_no,
							FILE *p_logfile,
							char **argv,
							int  *p_runseq,
							double *p_dct,
							double *p_cct,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Proc_AccEnt(      char **argv,
							FILE *p_repfile,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



int CDBGenGrAccFn(   char *p_acdate,
							char p_tiposec,
							char **argv,
							FILE *p_repfile,
							FILE *p_logfile,
						   INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
		     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
	
int CDBGenTrdAccFn(     char *p_deal_rowid,
							char *p_batch_no,
							int *p_runseq,
							char chr_p_sectype,
							double *p_dct,
							double *p_cct,
							FILE *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
		     DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Upd_IGrAcctEnt( PRO_GRACCTENT_STRUCT_H *p_pro_gracctent_struct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Pro_GrAccRep(   char *chr_p_batchno,
								char *p_batch_date,
								char p_mod_ident,
								char **argv,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr); 




extern int EOM_Mod_ExpBondDel(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int CO_DB_Connection_D(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int EOM_Prnt_ExpBondDelRptHdr(FILE *p_del_exp_bond_rpt_file,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Prnt_ExpBondNonDelRptHdr(FILE *p_notdel_exp_bond_rpt_file,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CO_DB_Connection_E(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

extern int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOM_Proc_EvtHoff(char **argv,FILE *p_ptr_ini_file,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOM_Proc_TaxEvtHoff(char *p_tx_fromdate,char *p_tx_todate,char *p_tx_livehist_flg,char *p_tx_handoff_dir,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOM_Proc_CDEvtHoff(char *p_cd_fromdate,char *p_cd_todate,char *p_cd_handoff_dir,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOM_Proc_BIEvtHoff(char *p_in_fromdate,char *p_in_todate,char *p_in_handoff_dir,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Prnt_CDRptHdr(FILE *p_cash_dividend_rpt_file,char *p_cd_fromdate,char *p_cd_todate,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Prnt_BIRptHdr(FILE *p_bond_int_rpt_file,char *p_in_fromdate,char *p_in_todate,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Prnt_TaxRptHdr(FILE *p_tx_hoff_rpt_file,char *p_tx_fromdate,char *p_tx_todate,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Prnt_SecRptHdr(FILE *p_sfk_hoff_rpt_file,char *p_tx_fromdate,char *p_tx_todate,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int EOD_DBProc_SqNoRst(FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_DB_Connection_F(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int EOM_Proc_DBSqNoRst(FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_DB_Connection_G(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EOY_Proc_DBSqNoRst(FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_DB_Connection_H(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int IV_Rtv_NxtBussDt(char *p_next_date,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



int CO_DB_Connection_I(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int MT_Rtv_AccDet_B(char **argv, FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int MT_Prnt_AccDetRpt(FILE *p_ptr_cust_det_file,MT_CLIENT_STRUCT_H p_mt_client_struct_h,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CO_Proc_RePrint( char *p_rep_name, 
								char *p_prn_name, 
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Proc_DBRptIns(        INTL_REPT_STRUCT_H *p_intl_rept_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

extern int CO_Proc_RptIns( char *p_repname,
								char *p_repdesc,
								int p_repwidateh,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



extern int DL_Chk_TrdCanDrop(   char    *p_candropdate,
										char    *chr_p_client,
										char    *chr_p_refno,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



extern int EOM_Proc_MCL( char *p_asofdate, 
								char **argv,
								FILE *p_logfile,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int EOM_Proc_MCLMnthlyMktPr(        FILE *p_repfile,
						FILE *p_logfile,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int EOM_Proc_MCLTrdOrd(     char *p_asofdate,
							char **argv,
							FILE *p_repfile,
							FILE *p_logfile,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int EOM_Proc_MCLDlyMktPr(        char *p_asofdate,
						FILE *p_repfile,
						FILE *p_logfile,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int EOM_Proc_MCLPos(      FILE *p_repfile,
							FILE *p_logfile,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int EOM_Proc_MCLMisTxn(     char *p_asofdate,
							FILE *p_repfile,
							FILE *p_logfile,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );

int EOM_Proc_MCLLocChg(     char *p_asofdate,
							FILE *p_repfile,
							FILE *p_logfile,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr );



extern int DL_Proc_EOMArch(        char **argv,
									FILE *p_logfile,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



int DL_Proc_MTFRpt(
						char **argv,
						FILE *p_logfile,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int DL_Proc_AgeMTFRpt(
						FILE *p_fp_ageodmtf,
						FILE *p_logfile,
						char *p_today,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int DL_Prnt_FailTxRptHdr(    FILE *fp, char *p_today);
int DL_Prnt_AgeMTFHdr(  FILE *fp, int p_age_days_l, int p_age_days_u, char *p_today);
int DL_Prnt_AgeMTFRpt(FILE *fp, SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_b, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int DL_Prnt_FailTxRpt(   FILE *fp, 
								FILE *p_logfile,
								char *p_today,
								SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_b,
								SYS_DL_DEAL_STRUCT_I *p_sys_dl_deal_struct_i,
								char *l_zero_flag,
								char *l_footer_flag,
								char *l_grand_tot_flag,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int DL_Prnt_FailDetTxRptHdr(FILE *fp, char *chr_p_client,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr); 
int DL_Prnt_FailTxRptFtr(FILE *fp, double p_amount_sum, double p_qty_sum, char *l_grand_tot_flag);
int DL_Prnt_MTFRptHdr( FILE *fp, int p_position);



int CO_DB_Connection_J(char *p_username,char *p_passwd,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int CO_Proc_Exit(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,int p_flg);

int CO_Proc_BtchLock(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
extern int DL_Rtv_SetlCashFl_Rpt(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Prnt_SetlCashFl_RptHdr(FILE *p_ptr_settl_cash_rpt_file,char *p_dt, FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int DL_Prnt_SetlCashFl_Rpt(FILE *p_ptr_settl_cash_rpt_file,char *p_prev_domcpac,double p_inflow,double p_outflow,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int DL_Prnt_SetlCashFl_RptSumm(FILE *p_ptr_settl_cash_rpt_file,double p_tot_inflow,double p_tot_outflow,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);




extern int CDBLRMainFn( char                                            **argv, 
								FILE                                            *p_logfile,
								char                 *chr_p_err_filedesc,
								FILE                 *l_errrpt_repfile, 
								INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
								DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);
			
extern int CDBLRDlyProcFn(      PO_LR_STRUCT_H *p_po_lr_struct_h, 
									char                 **argv,
									FILE                                            *p_logfile,
									char                 *chr_p_err_filedesc,
									FILE                 *l_errrpt_repfile, 
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBSfkUpdateFn(      PO_LR_STRUCT_H *p_po_lr_struct_h, 
									FILE                                            *p_logfile, 
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBUpdLRPROCFn(      PO_LR_STRUCT_H    *p_po_lr_struct_h,
								   FILE                                                 *p_logfile,
									INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
									DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBMatchExistsFn(    PO_LR_STRUCT_H *p_po_lr_struct_h, 
										DEAL_LR_STRUCT_H       *p_deal_lr_struct_h,
										DEAL_LR_STRUCT_I               *p_deal_lr_struct_i,
										DL_LOCALREPSPEC_STRUCT_H               *p_dl_localrepspec_struct_h_a,
										FILE                                            *p_logfile, 
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
										DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBPassOrdEntryFn(   PO_LR_STRUCT_H *p_po_lr_struct_h, 
										LR_ORD_STRUCT_H       *p_lr_ord_struct_h,
										LR_ORD_STRUCT_I               *p_lr_ord_struct_i_a,
										DL_LOCALREPSPEC_STRUCT_H               *p_dl_localrepspec_struct_h_a,
										FILE                                            *p_logfile, 
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
										DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBMatchKeyPassFn(   PO_LR_STRUCT_H *p_po_lr_struct_h, 
										DEAL_LR_STRUCT_H       *p_deal_lr_struct_h,
										DEAL_LR_STRUCT_I               *p_deal_lr_struct_i,
										DL_LOCALREPSPEC_STRUCT_H               *p_dl_localrepspec_struct_h_a,
										FILE                                            *p_logfile, 
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
										DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBPassLREntryFn(    PO_LR_STRUCT_H *p_po_lr_struct_h, 
										DEAL_LR_STRUCT_H       *p_deal_lr_struct_h,
										DL_LOCALREPSPEC_STRUCT_H               *p_dl_localrepspec_struct_h_a,
										FILE                                            *p_logfile, 
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
										DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBLrErrRepPrnFn(    PO_LR_STRUCT_H *p_po_lr_struct_h, 
										FILE                                            *p_logfile, 
										INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
										DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBAddLRSAFEKRecFn(  DL_LOCALREPSAFEK_STRUCT_H       *p_dl_localrepsafek_struct_h, 
											FILE                                            *p_logfile, 
											INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
											DEBUG_INFO_STRUCT_H                    **l_debug_info_ptr);

extern int CDBCusBalFn( PO_LR_STRUCT_H *p_po_lr_struct_h, 
								FILE                                            *p_logfile, 
								INTL_ENV_DATA_STRUCT_H      *p_intl_envdatastruct_h, 
								 DEBUG_INFO_STRUCT_H                   **l_debug_info_ptr);

extern int CBLROpBkFn(char * pprocdate,
							char *poprec_file_desc, 
							FILE *poprec_file_handle,
							short p_heading,
							short *pstatus,
							FILE  *p_logfile,
							INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRCusOpBkFn(short *pstatus,
								 char *pprocdate,
								 FILE *poprec_file_handle, 
								 FILE *p_logfile,
								 INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRMainOpBkFn( short *pstatus,
									char *pprocdate,
									FILE *poprec_file_handle, 
									FILE *p_logfile,
									INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRBalRepFn(char *pprocdate,
								FILE *poprec_file_handle ,
							   FILE *p_logfile,
								INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRErr_RepFn(char *perr_file_desc, 
								 FILE *perr_file_handle, 
								 char *p_errflg,
								 FILE *p_logfile,
								 INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
								 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLROpRecHdrPrnFn(char *psecdesc,
									  char *pisin, 
									  short ppagenum,
									  short p_heading,
									  char *poprec_file_desc,
									  FILE *poprec_file_handle,
									  FILE *p_logfile,
									  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRBalRecHdrPrnFn(char *pprocdate,
										char *psecode,
										short ppagenum,
										int     p_heading,
										FILE *poprec_file_handle, 
										FILE *p_logfile,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLREmptyHdrPrnFn(char *pprocdate,
									  char *poprec_file_desc,
									  FILE *poprec_file_handle,
									  FILE *p_logfile,
									  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRCusOpHdrPrnFn(char ptype, 
										char *pct_clt,
										char *pprocdate,
										char *pclient_a, 
										char *psecode,
										short ppagenum,
										FILE *poprec_file_handle, 
										FILE *p_logfile,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBLRErrRepHdrFn(char *perr_file_desc,
									FILE *perr_file_handle,
									short ppagenum, 
									FILE *p_logfile,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Def_LRErrEntCursor(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRErrEntCursor(short *peocursor, 
										DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h, 
										DL_LOCALREPPROC_STRUCT_I *p_dl_localrepproc_struct_i_a, 
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Proc_LRErrWordCursor( DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h,
										char *pwording , 
										char *pdclient, 
										char *pcclient, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRErrWord( DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h,
									char *pwording , 
									char *pdclient, 
									char *pcclient, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_EOFLR(short *pstatus, 
										short p_heading,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Def_LROpBkCursor(short p_heading,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LROpBkCursor(short *peocursor,
										 short p_heading, 
										 DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h, 
										 DL_LOCALREPPROC_STRUCT_I *p_dl_localrepproc_struct_i_a, 
										 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRSecDesc(char *psecode, char *psecdesc, char *pisin, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRCustEntCursor( DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRAccCursor(short *peocursor, 
											double *popenbal, 
											DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h, 
											DL_LOCALREPPROC_STRUCT_I *p_dl_localrepproc_struct_i_a , 
											DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Def_LRCursor( DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRCursor(short *peocursor, 
											double *popenbal, 
											DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h , 
											DL_LOCALREPPROC_STRUCT_I *p_dl_localrepproc_struct_i_a , 
											DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LROneSpecCursor(char *plrdealdateype, 
									char *ptrcode, 
									int pdatefld, 
									DL_LOCALREPSPEC_STRUCT_H *p_dl_localrepspec_struct_h, 
									DL_LOCALREPSPEC_STRUCT_I *p_dl_localrepspec_struct_i,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LROppCust(char pclttype, 
										char *pclient, 
										char *pdomcpac,
										DL_LOCALREPSPEC_STRUCT_H *p_dl_localrepspec_struct_h, 
										DL_LOCALREPSPEC_STRUCT_I *p_dl_localrepspec_struct_i,
										DL_LOCALREPPROC_STRUCT_H *p_dl_localrepproc_struct_h_a, 
										DL_LOCALREPPROC_STRUCT_I *p_dl_localrepproc_struct_i,
										char *pdbclt, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_LRCust(char *pclient_a, char *pcname, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Mod_LRProcDet(char *pprocdate, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdCustFn(MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h_a,char *p_row_id_cust,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBCustChrValFn(char *chr_p_acct, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValCustFn(char *p_client,char p_exist,char p_auth,char p_closed,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValCustAccFn(char *p_client,char p_exist,char p_cubk, char p_cltclass ,char p_auth,char p_del,char p_frozen,char p_closed,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBChkCustDetFn(MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h_b, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBUpdCustOthFn(char *chr_p_acct,char *chr_p_acct_time_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUsrAuthCustFn(char *chr_p_acct, char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdCustOthFn(char *chr_p_acct,char *p_row_id_cltt,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdRRLocFn(MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBRRLocChrValFn(char *chr_p_rrloc, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRLocFn(char *p_location,char p_exist,char p_auth,char p_closed,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRLocLocFn(char *p_location,char p_exist,char p_auth,char p_del,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBChkRRLocDetFn(MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBUpdRRLocOthFn(char *chr_p_rrloc,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUsrAuthRRLocFn(char *chr_p_rrloc,  char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdLocOthFn(char *chr_p_rrloc,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdRRProdFn(MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_b,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBRRProdChrValFn(char *chr_p_rrprod, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRProdFn(char *p_product, char p_exist,char p_auth, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBChkRRProdDetFn(MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_b, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CBUpdRRProdOthFn(char *chr_p_rrprod,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUsrAuthRRProdFn(char *chr_p_rrprod, char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdProdOthFn(char *chr_p_rrprod, char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUpdRRSRNFn(MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBRRSRNChrValFn(char *p_rrsrn, char *p_rrsecode, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRSRNFn(char *p_srn, char *p_securitycd, char p_exist,char p_auth, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRSRNRefnumFn(char *p_srn, char *p_securitycd, char *p_refnum, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBChkRRSRNDetFn(MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

 

extern int CDBUsrAuthRRSRNFn(char *p_rrsrn, char *p_rrsecode, char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);



extern int CDBUpdRRSecFn(MT_RUSEC_STRUCT_H *p_mt_rusec_struct_h,char *p_row_id_code,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBRRSecChrValFn(char *p_rrsec, char *p_link_val, char *p_field_val, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRSecFn(char *p_securitycd, char p_exist,char p_auth, char p_closed, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRSECSrnFn(char *p_securitycd, char *p_srn,  INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBChkRRSecDetFn(MT_RUSEC_STRUCT_H *p_mt_rusec_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CDBUsrAuthRRSecFn(char *p_rrsec, char *p_user, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int GDBValRRSRNOnlyFn(char *p_srn, char p_exist,char p_auth, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int DL_Chk_RRMMDL(char *p_client, char *p_secode, short *p_validity, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int EI_Mod_MQData(char *p_client,char *p_ident,char *p_secode,char *p_locncode,char *chr_trdholflg ,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


extern int DL_Proc_SetlSeqNoRst( char *p_deal_client, char *p_deal_ident, char *p_ora_rowid, double *p_dbl_settle_seq_no, char p_action, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

#endif
