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
 * Module Name         :		Deal
 *
 * File Name           :		DL_Proc_Populate.h
 *
 * Description         :		
 *           
 *
 *            Version Control Block
 *
 * Date        Version   Author           Description             RFS No.
 * ---------   --------  ---------------  ----------------------- ---------
 * 23/11/2006  1.20      Amol Kulkarni    Depo Upload
 * -------------------------------------------------------------------------
 * 09-Jun-2010 1.0.1.13  Naren V          NSDL DP Ins File Format ISKB_3298
 *                                        Changes - Variable Type
 *                                        cast changes were incor
 *                                        porated accordingly bas
 *                                        ed on  NSDL  depository 
 *                                        revised file formats.
 *****************************************************************************/

   
#include "MS_Swift.h"   
#include "DL_Interface.h"
#include "Intellect_Common.h"

int	DL_Proc_DLPopulate(int *int_p_trdrepseqnum,SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
 
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DLPopulate \n",NULL,NULL);
		   printf("\n Entered DL_Proc_DLPopulate ..");
			CO_Rtv_DataInt(chr_p_param_str,"TRDREPSEQNUM",(int *)int_p_trdrepseqnum);	
         CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_sys_dl_deal_struct_h_a->h_dl_client);
         /*CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_sys_dl_deal_struct_h_a->h_dl_client);
          CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_sys_dl_deal_struct_h_a->h_indentity_no);*/
         CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_sys_dl_deal_struct_h_a->h_indentity_no);
         CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",(char *)p_sys_dl_deal_struct_h_a->h_dlt);
         CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_sys_dl_deal_struct_h_a->h_setldt);
         CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_sys_dl_deal_struct_h_a->h_pr));
         CO_Rtv_DataString(chr_p_param_str,"EX_ARENA",(char *)p_sys_dl_deal_struct_h_a->h_ex_arena);
         CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT",&(p_sys_dl_deal_struct_h_a->h_amt));
         CO_Rtv_DataDbl(chr_p_param_str,"CUSTODYCOMM",&(p_sys_dl_deal_struct_h_a->h_custodycomm));
         CO_Rtv_DataDbl(chr_p_param_str,"BROKERCOMM",&(p_sys_dl_deal_struct_h_a->h_brokercomm));
         CO_Rtv_DataDbl(chr_p_param_str,"STX_COMM",&(p_sys_dl_deal_struct_h_a->h_stx_comm));
         CO_Rtv_DataDbl(chr_p_param_str,"OTH_COMM",&(p_sys_dl_deal_struct_h_a->h_oth_comm));
         CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_DT",(char *)p_sys_dl_deal_struct_h_a->h_instrdate);
         CO_Rtv_DataString(chr_p_param_str,"MONEY_SETL_DT",(char *)p_sys_dl_deal_struct_h_a->h_moneydate);
			  printf("\n Before getting quantity .... |%lf|",p_sys_dl_deal_struct_h_a->h_qty);	
         CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_sys_dl_deal_struct_h_a->h_qty)); 
         
         CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",(char *)p_sys_dl_deal_struct_h_a->h_domcpclt_cd);
         CO_Rtv_DataString(chr_p_param_str,"SPOTTRD_IND",(char *)p_sys_dl_deal_struct_h_a->h_isspotdl);
         CO_Rtv_DataDbl(chr_p_param_str,"ORIG_QTY",&(p_sys_dl_deal_struct_h_a->h_origquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"ORIG_AMOUNT",&(p_sys_dl_deal_struct_h_a->h_origamount));
         CO_Rtv_DataString(chr_p_param_str,"DEAL_FRM_ORD",(char *)p_sys_dl_deal_struct_h_a->h_dlfromord);
         CO_Rtv_DataString(chr_p_param_str,"ENTRY",(char *)p_sys_dl_deal_struct_h_a->h_entry);
         CO_Rtv_DataString(chr_p_param_str,"REAPIRED_IND",(char *)p_sys_dl_deal_struct_h_a->h_reapired_ind);
         CO_Rtv_DataString(chr_p_param_str,"DOMCP_CUSTODYCLT",(char *)p_sys_dl_deal_struct_h_a->h_domcp_custodyclt);
         CO_Rtv_DataString(chr_p_param_str,"CP_CLT",(char *)p_sys_dl_deal_struct_h_a->h_countclt);
         CO_Rtv_DataString(chr_p_param_str,"CP_CLTNAME",(char *)p_sys_dl_deal_struct_h_a->h_countcltnm);
         CO_Rtv_DataString(chr_p_param_str,"CLIENTOF",(char *)p_sys_dl_deal_struct_h_a->h_clientof);
         CO_Rtv_DataString(chr_p_param_str,"CLIENT_NOTE",(char *)p_sys_dl_deal_struct_h_a->h_custinfo);
         CO_Rtv_DataString(chr_p_param_str,"FX_REQD",(char *)p_sys_dl_deal_struct_h_a->h_fx_reqd);
         CO_Rtv_DataString(chr_p_param_str,"PAYLOC_IND",(char *)p_sys_dl_deal_struct_h_a->h_ispymtlocal);
         CO_Rtv_DataString(chr_p_param_str,"VERFIED_WITH",(char *)p_sys_dl_deal_struct_h_a->h_verfied_with);
         CO_Rtv_DataDbl(chr_p_param_str,"AMT_DIFFER",&(p_sys_dl_deal_struct_h_a->h_diffamount));
         CO_Rtv_DataString(chr_p_param_str,"BRK_NO",(char *)p_sys_dl_deal_struct_h_a->h_brkrno);
         CO_Rtv_DataString(chr_p_param_str,"FAILREASON_CD",(char *)p_sys_dl_deal_struct_h_a->h_fail_cd);
         CO_Rtv_DataString(chr_p_param_str,"FAIL_DET",(char *)p_sys_dl_deal_struct_h_a->h_failinfo);
         CO_Rtv_DataString(chr_p_param_str,"ISPARTIAL",(char *)p_sys_dl_deal_struct_h_a->h_ispart_);
         CO_Rtv_DataDbl(chr_p_param_str,"FX_RT",&(p_sys_dl_deal_struct_h_a->h_fx_rt));
         CO_Rtv_DataInt(chr_p_param_str,"AMEND_COUNT",(int *)&(p_sys_dl_deal_struct_h_a->h_amend_count));
         CO_Rtv_DataInt(chr_p_param_str,"NUMBER_A",(int *)&(p_sys_dl_deal_struct_h_a->h_number_a));
         CO_Rtv_DataString(chr_p_param_str,"REPORT_AT_EOM_IND",(char *)p_sys_dl_deal_struct_h_a->h_report_at_eom_ind);
         CO_Rtv_DataString(chr_p_param_str,"DATEOFBILLING",(char *)p_sys_dl_deal_struct_h_a->h_billdate);
         CO_Rtv_DataString(chr_p_param_str,"LCL_IDENTNO",(char *)p_sys_dl_deal_struct_h_a->h_locindentity_no);
         CO_Rtv_DataString(chr_p_param_str,"INSTRUCT_PERSON",(char *)p_sys_dl_deal_struct_h_a->h_instruct_person);
         CO_Rtv_DataDbl(chr_p_param_str,"REC_INT_000",&(p_sys_dl_deal_struct_h_a->h_rec_int_000));
         CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",(char *)p_sys_dl_deal_struct_h_a->h_dealcd);
         CO_Rtv_DataString(chr_p_param_str,"INSTR_CD",(char *)p_sys_dl_deal_struct_h_a->h_instr_code); 
         CO_Rtv_DataString(chr_p_param_str,"CURRENCY_CD",(char *)p_sys_dl_deal_struct_h_a->h_currencycode); 
         CO_Rtv_DataString(chr_p_param_str,"DL_TYPE",(char *)p_sys_dl_deal_struct_h_a->h_classofdl);
			printf("\n\n ********** Pan ********** DL_TYPE=|%s\n\n",p_sys_dl_deal_struct_h_a->h_classofdl);
         CO_Rtv_DataString(chr_p_param_str,"ORIG_REFNO",(char *)p_sys_dl_deal_struct_h_a->h_origindentity_no);
         CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",(char *)p_sys_dl_deal_struct_h_a->h_newdt);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_sys_dl_deal_struct_h_a->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_sys_dl_deal_struct_h_a->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"DEAL_STAT",(char *)p_sys_dl_deal_struct_h_a->h_deal_status);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_sys_dl_deal_struct_h_a->h_access_stamp);
			printf("\n\n\n ****** Pan: param str acc stamp=|%s|\n\n", p_sys_dl_deal_struct_h_a->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"INFO1",(char *)p_sys_dl_deal_struct_h_a->h_info1);
         CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_sys_dl_deal_struct_h_a->h_loccode);
         CO_Rtv_DataString(chr_p_param_str,"REGINSTR_IND",(char *)p_sys_dl_deal_struct_h_a->h_reginstr_ind);
         CO_Rtv_DataString(chr_p_param_str,"STATUS_POS",(char *)p_sys_dl_deal_struct_h_a->h_pos_stat);
         CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_sys_dl_deal_struct_h_a->h_status_reg);
         CO_Rtv_DataString(chr_p_param_str,"VAL_FDT",(char *)p_sys_dl_deal_struct_h_a->h_confdate);
         CO_Rtv_DataString(chr_p_param_str,"COMPREFNO",(char *)p_sys_dl_deal_struct_h_a->h_matchindentity_no);
         CO_Rtv_DataString(chr_p_param_str,"DATEOF_MARKFAIL",(char *)p_sys_dl_deal_struct_h_a->h_markfaildate);
         CO_Rtv_DataString(chr_p_param_str,"ALLOW_DROPDT",(char *)p_sys_dl_deal_struct_h_a->h_candropdate);
         CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_sys_dl_deal_struct_h_a->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_sys_dl_deal_struct_h_a->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"INSTRCONV_IND",(char *)p_sys_dl_deal_struct_h_a->h_instrconv_ind);
         CO_Rtv_DataString(chr_p_param_str,"NDS_BLK_DT",(char *)p_sys_dl_deal_struct_h_a->h_ndsbldate);
         CO_Rtv_DataString(chr_p_param_str,"LR_DL_CLASS",(char *)p_sys_dl_deal_struct_h_a->h_lrdltype);
         CO_Rtv_DataString(chr_p_param_str,"NDS_DATE",(char *)p_sys_dl_deal_struct_h_a->h_ndsdate);
         CO_Rtv_DataString(chr_p_param_str,"UNBLK_DATE",(char *)p_sys_dl_deal_struct_h_a->h_ublckdate);
         CO_Rtv_DataDbl(chr_p_param_str,"DELTA_000",&(p_sys_dl_deal_struct_h_a->h_delta_000));
         CO_Rtv_DataDbl(chr_p_param_str,"DELTA_001",&(p_sys_dl_deal_struct_h_a->h_delta_001));
         CO_Rtv_DataDbl(chr_p_param_str,"DELTA_003",&(p_sys_dl_deal_struct_h_a->h_delta_002));
         CO_Rtv_DataString(chr_p_param_str,"DEL_REC_DATE",(char *)p_sys_dl_deal_struct_h_a->h_delrecdate);
         CO_Rtv_DataString(chr_p_param_str,"LAST_REG_DATE",(char *)p_sys_dl_deal_struct_h_a->h_lastregdate);
         CO_Rtv_DataString(chr_p_param_str,"LR_CHECK_DATE",(char *)p_sys_dl_deal_struct_h_a->h_lr_chkdate);
         CO_Rtv_DataString(chr_p_param_str,"LR_VALDATE",(char *)p_sys_dl_deal_struct_h_a->h_lr_confdate);
         CO_Rtv_DataString(chr_p_param_str,"LRINSTR_DATE",(char *)p_sys_dl_deal_struct_h_a->h_lr_instrdate);
         CO_Rtv_DataDbl(chr_p_param_str,"REG_MSG_QTY",&(p_sys_dl_deal_struct_h_a->h_regmsgquantity));
         CO_Rtv_DataString(chr_p_param_str,"TMP_OUT_DATE",(char *)p_sys_dl_deal_struct_h_a->h_tmpoutdate);
         CO_Rtv_DataString(chr_p_param_str,"TMP_OUT_DATE",(char *)p_sys_dl_deal_struct_h_a->h_tmpretdate);
         CO_Rtv_DataString(chr_p_param_str,"TRANS_DATE",(char *)p_sys_dl_deal_struct_h_a->h_transmitdate);
         CO_Rtv_DataDbl(chr_p_param_str,"TOT_QTY",&(p_sys_dl_deal_struct_h_a->h_complquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"QTY_LOST",&(p_sys_dl_deal_struct_h_a->h_lostquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"MRK_DL_FAILQTY",&(p_sys_dl_deal_struct_h_a->h_marktrfquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"DL_COMPLETEQTY",&(p_sys_dl_deal_struct_h_a->h_mcomplquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"OUT_REG_QTY",&(p_sys_dl_deal_struct_h_a->h_outregquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"PEND_REG_QTY",&(p_sys_dl_deal_struct_h_a->h_pendregquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"RET_REG_QTY",&(p_sys_dl_deal_struct_h_a->h_retregquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"STAMP_QTY",&(p_sys_dl_deal_struct_h_a->h_stampquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"TEMP_OUT_QUANTITY",&(p_sys_dl_deal_struct_h_a->h_tempoutquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"TEMP_RET_QUANTITY",&(p_sys_dl_deal_struct_h_a->h_tempretquantity));
         CO_Rtv_DataDbl(chr_p_param_str,"VAL_DEED_QTY",&(p_sys_dl_deal_struct_h_a->h_valdeedquantity));
         CO_Rtv_DataString(chr_p_param_str,"HOST_DATE",(char *)p_sys_dl_deal_struct_h_a->h_hostdate);
         CO_Rtv_DataString(chr_p_param_str,"LRNDS_BILLDT",(char *)p_sys_dl_deal_struct_h_a->h_lr_ndsbldate);
         CO_Rtv_DataString(chr_p_param_str,"LRNDS_DATE",(char *)p_sys_dl_deal_struct_h_a->h_lr_ndsdate);
         CO_Rtv_DataString(chr_p_param_str,"LR_UNBLK_DATE",(char *)p_sys_dl_deal_struct_h_a->h_lr_ublckdate);
         CO_Rtv_DataInt(chr_p_param_str,"NUMBER_B",(int *)&(p_sys_dl_deal_struct_h_a->h_number_b));
         CO_Rtv_DataString(chr_p_param_str,"CLT_REQDEL_IND",(char *)p_sys_dl_deal_struct_h_a->h_clt_reqdel_flag);
         CO_Rtv_DataString(chr_p_param_str,"MOD_HISPOS_IND",(char *)p_sys_dl_deal_struct_h_a->h_mod_hispos_ind);
         CO_Rtv_DataString(chr_p_param_str,"MOD_HISPOS_DATE",(char *)p_sys_dl_deal_struct_h_a->h_updhispos_date);
         CO_Rtv_DataString(chr_p_param_str,"GL_CLIENT",(char *)p_sys_dl_deal_struct_h_a->h_cash_client);
         CO_Rtv_DataDbl(chr_p_param_str,"CP_AMT",&(p_sys_dl_deal_struct_h_a->h_cpamt));
         CO_Rtv_DataString(chr_p_param_str,"MSG_STAT",(char *)p_sys_dl_deal_struct_h_a->h_msg_stat);
         CO_Rtv_DataInt(chr_p_param_str,"SUB_FAIL_CD",(int *)&(p_sys_dl_deal_struct_h_a->h_subfailreas_cd));
         CO_Rtv_DataString(chr_p_param_str,"ALLOW_PARTIAL",(char *)p_sys_dl_deal_struct_h_a->h_allow_part_s);
         CO_Rtv_DataString(chr_p_param_str,"LOC_CHNG_IND",(char *)p_sys_dl_deal_struct_h_a->h_locchng_flg);
         CO_Rtv_DataString(chr_p_param_str,"COMM_IDENT_NO",(char *)p_sys_dl_deal_struct_h_a->h_comm_indentity_no);
         CO_Rtv_DataString(chr_p_param_str,"INSTRUCT_PERSONNM",(char *)p_sys_dl_deal_struct_h_a->h_instruct_personnm);
         CO_Rtv_DataString(chr_p_param_str,"CLIENTOF_CD",(char *)p_sys_dl_deal_struct_h_a->h_clientofcode);
         CO_Rtv_DataString(chr_p_param_str,"INTER_MED_PERSON",(char *)p_sys_dl_deal_struct_h_a->h_inter_med_person);
         CO_Rtv_DataString(chr_p_param_str,"INTER_MED_PERSONNM",(char *)p_sys_dl_deal_struct_h_a->h_inter_med_personnm);
         CO_Rtv_DataString(chr_p_param_str,"FXCCY",(char *)p_sys_dl_deal_struct_h_a->h_fxccy);
			  printf("\n 1");
			CO_Rtv_DataString(chr_p_param_str,"UNIQ_IDENT_NO",(char *)p_sys_dl_deal_struct_h_a->h_uniq_ident_no);
			  printf("\n 2");
         
         CO_Rtv_DataString(chr_p_param_str,"INFORMATON",(char *)p_sys_dl_deal_struct_h_a->h_misinfo);
			  printf("\n 3");
			CO_Rtv_DataString(chr_p_param_str,"RELATED_IDENT_NO",(char *)p_sys_dl_deal_struct_h_a->h_related_indentity_no);
		   /* new Fields Added - HDFCDL_003 - Sundar */
			CO_Rtv_DataString(chr_p_param_str,"SETTLEMENT_NO",p_sys_dl_deal_struct_h_a-> h_settlement_no);
			CO_Rtv_DataString(chr_p_param_str,"MKT_TYPE",p_sys_dl_deal_struct_h_a-> h_mkt_type);
			CO_Rtv_DataString(chr_p_param_str,"CLH_FLG",p_sys_dl_deal_struct_h_a-> h_clh_flg);
			/* CO_Rtv_DataInt(chr_p_param_str,"INTEREST",(int *) &(p_sys_dl_deal_struct_h_a-> h_interest));commented by rahul int to double  */
			Alert("value of p_sys_dl_deal_struct_h_a-> h_interest %ld",p_sys_dl_deal_struct_h_a-> h_interest);
			CO_Rtv_DataDbl(chr_p_param_str,"INTEREST",&(p_sys_dl_deal_struct_h_a-> h_interest));
			CO_Rtv_DataDbl(chr_p_param_str,"NET_AMT",&(p_sys_dl_deal_struct_h_a-> h_net_amt));
			CO_Rtv_DataString(chr_p_param_str,"PAYIN_DT",p_sys_dl_deal_struct_h_a-> h_payin_dt);
			CO_Rtv_DataString(chr_p_param_str,"PAYOUT_DT",p_sys_dl_deal_struct_h_a-> h_payout_dt);
			CO_Rtv_DataDbl(chr_p_param_str,"DEMAT_QTY",&(p_sys_dl_deal_struct_h_a-> h_demat_qty));
			CO_Rtv_DataString(chr_p_param_str,"CONTRACT_REQ",p_sys_dl_deal_struct_h_a-> h_contract_req);
			CO_Rtv_DataString(chr_p_param_str,"EXCUM_FLG",p_sys_dl_deal_struct_h_a-> h_excum_flg);
			CO_Rtv_DataString(chr_p_param_str,"CRN_NO",p_sys_dl_deal_struct_h_a-> h_crn_no);
			CO_Rtv_DataString(chr_p_param_str,"INTERFII_FLG",p_sys_dl_deal_struct_h_a-> h_interfii_flg);
			CO_Rtv_DataString(chr_p_param_str,"PAY_MODE",p_sys_dl_deal_struct_h_a-> h_pay_mode);
			CO_Rtv_DataString(chr_p_param_str,"DL_SECSTATUS",p_sys_dl_deal_struct_h_a-> h_dl_secstatus);
			CO_Rtv_DataString(chr_p_param_str,"DL_MNYSTATUS",p_sys_dl_deal_struct_h_a-> h_dl_mnystatus);
			CO_Rtv_DataDbl(chr_p_param_str,"AVAIL_QTY",&(p_sys_dl_deal_struct_h_a-> h_avail_qty));
			CO_Rtv_DataDbl(chr_p_param_str,"ALLOT_QTY",&(p_sys_dl_deal_struct_h_a-> h_allot_qty));
			CO_Rtv_DataDbl(chr_p_param_str,"SHORTAGE_QTY",&(p_sys_dl_deal_struct_h_a-> h_shortage_qty));
			CO_Rtv_DataString(chr_p_param_str,"CLN_DEPOACC",p_sys_dl_deal_struct_h_a-> h_cln_depoacc);
			CO_Rtv_DataString(chr_p_param_str,"PLTOPL_FLG",p_sys_dl_deal_struct_h_a-> h_pltopl_flg);
			CO_Rtv_DataString(chr_p_param_str,"ORIG_STATUS",p_sys_dl_deal_struct_h_a-> h_orig_status);
			CO_Rtv_DataString(chr_p_param_str,"MAP_FAILCODE",p_sys_dl_deal_struct_h_a-> h_map_failcode);
			CO_Rtv_DataString(chr_p_param_str,"MATCH_FAILCODE",p_sys_dl_deal_struct_h_a-> h_match_failcode);
			CO_Rtv_DataString(chr_p_param_str,"IS_MATCHED",p_sys_dl_deal_struct_h_a-> h_is_matched);
			CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_sys_dl_deal_struct_h_a-> h_exch_code);
			CO_Rtv_DataString(chr_p_param_str,"CONTRACT_CD",p_sys_dl_deal_struct_h_a-> h_contract_cd);
         CO_Rtv_DataString(chr_p_param_str,"R_TRANS_CODE",p_sys_dl_deal_struct_h_a-> h_r_trans_code);
         CO_Rtv_DataString(chr_p_param_str,"R_SETT_CODE",p_sys_dl_deal_struct_h_a -> h_r_sett_code);
         CO_Rtv_DataString(chr_p_param_str,"R_DELAY",p_sys_dl_deal_struct_h_a-> h_r_delay);
         CO_Rtv_DataString(chr_p_param_str,"R_TYPE",p_sys_dl_deal_struct_h_a -> h_r_type);
         CO_Rtv_DataString(chr_p_param_str,"REPO_DATE",p_sys_dl_deal_struct_h_a -> h_repo_date);
         CO_Rtv_DataString(chr_p_param_str,"SEBI_REPORTED",p_sys_dl_deal_struct_h_a-> h_sebi_reported);
		 /*Retro from HDFC by Ekta for Interoperability Starts*/
	   	 CO_Rtv_DataString(chr_p_param_str,"TRD_EXCH",(char *)p_sys_dl_deal_struct_h_a-> h_trd_exch);
		 CO_Rtv_DataString(chr_p_param_str,"TRD_SETL_NO", (char *)p_sys_dl_deal_struct_h_a-> h_trd_setl_no);
		 CO_Rtv_DataString(chr_p_param_str,"TRD_MKT_TYPE", (char *)p_sys_dl_deal_struct_h_a-> h_trd_mkt_type);
		 /*Retro from HDFC by Ekta for Interoperability Ends*/
		 /* Added by Shradha for Stamp Duty Enh - Starts */
		 CO_Rtv_DataDbl(chr_p_param_str,"STAMP_DUTY",&(p_sys_dl_deal_struct_h_a->h_stamp_duty));
		 /* Added by Shradha for Stamp Duty Enh - Ends */

		  /* Added by Rahul For CSGL  Enh - Starts */
		  printf("Locatiom code afer capture |%s|",p_sys_dl_deal_struct_h_a-> h_dpm_trans_ref_no);
		  printf("Locatiom code afer capture |%ld|",p_sys_dl_deal_struct_h_a->h_other_charges);
		  printf("Locatiom code afer capture |%s|",p_sys_dl_deal_struct_h_a-> h_csgl_trade_type);
		 CO_Rtv_DataString(chr_p_param_str,"DPM_TRANS_REF_NO", (char *)p_sys_dl_deal_struct_h_a-> h_dpm_trans_ref_no);
		 CO_Rtv_DataDbl(chr_p_param_str,"OTHER_CHARGES",&(p_sys_dl_deal_struct_h_a->h_other_charges));
		 CO_Rtv_DataString(chr_p_param_str,"CSGL_TRADE_TYPE", (char *)p_sys_dl_deal_struct_h_a-> h_csgl_trade_type);
		 
		  printf("Locatiom code afer capture |%s|",p_sys_dl_deal_struct_h_a-> h_dpm_trans_ref_no);
		  printf("Locatiom code afer capture |%ld|",p_sys_dl_deal_struct_h_a->h_other_charges);
		  printf("Locatiom code afer capture |%s|",p_sys_dl_deal_struct_h_a-> h_csgl_trade_type);
		 
		 /* Added by Rahul For CSGL - Ends */

		   printf("\n Leaving DL_Proc_DLPopulate ..");

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DLPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DLPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_PmtDetPopulate(DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_e,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_PmtDetPopulate \n",NULL,NULL);
                        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_dl_deal_pmtdet_struct_h_e->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_indentity_no);
/*
								  printf("\n Retrieving DL_REF_NO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)l_refno1);
								  printf("\n Retrieving NEWREFNO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
                        CO_Rtv_DataString(chr_p_param_str,"NEWREFNO",(char *)l_refno2);
								  printf("\n After Retrieving NEWREFNO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
								  if (strlen(l_refno2) != 0)
									{
								  		printf("\n Inside If : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
										strcpy(p_dl_deal_pmtdet_struct_h_e->h_indentity_no,l_refno2);
									}
									else
									{
								  		printf("\n Inside Else : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
										strcpy(p_dl_deal_pmtdet_struct_h_e->h_indentity_no,l_refno1);
									}
								  		printf("\n After All : l_refno1=|%s|, l_refno2=|%s|,p_dl_deal_pmtdet_struct_h_e->h_indentity_no=|%s|",l_refno1,l_refno2,p_dl_deal_pmtdet_struct_h_e->h_indentity_no);
*/
                        CO_Rtv_DataString(chr_p_param_str,"CONFIRMDT",(char *)p_dl_deal_pmtdet_struct_h_e->h_confdate);
                        CO_Rtv_DataString(chr_p_param_str,"VERFIED_WITH",(char *)p_dl_deal_pmtdet_struct_h_e->h_verfied_with);
                        CO_Rtv_DataDbl(chr_p_param_str,"AMT_DIFFER",&(p_dl_deal_pmtdet_struct_h_e->h_diffamount));
                        CO_Rtv_DataString(chr_p_param_str,"INFO1",(char *)p_dl_deal_pmtdet_struct_h_e->h_info1);
                        CO_Rtv_DataString(chr_p_param_str,"PARTIAL_IND",(char *)p_dl_deal_pmtdet_struct_h_e->h_ispart_);
                        CO_Rtv_DataString(chr_p_param_str,"BRK_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_brkrno);
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWQTY",&(p_dl_deal_pmtdet_struct_h_e->h_newquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWAMT",&(p_dl_deal_pmtdet_struct_h_e->h_newamount));
                        CO_Rtv_DataString(chr_p_param_str,"NEWREFNO",(char *)p_dl_deal_pmtdet_struct_h_e->h_newindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"NEWLOCREFNO",(char *)p_dl_deal_pmtdet_struct_h_e->h_newlocindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_pmtdet_struct_h_e->h_access_stamp);
                        CO_Rtv_DataDbl(chr_p_param_str,"GROSS_AMOUNT",&(p_dl_deal_pmtdet_struct_h_e->h_grossamount));
                        CO_Rtv_DataDbl(chr_p_param_str,"CP_AMT",&(p_dl_deal_pmtdet_struct_h_e->h_cpamt));
                        CO_Rtv_DataString(chr_p_param_str,"COMM_IDENT_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_comm_indentity_no);
								CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_dl_deal_pmtdet_struct_h_e->h_exp_setl_date);
								printf("Locatiom code before capture |%s|",p_dl_deal_pmtdet_struct_h_e->h_newlocindentity_no);	
                        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_dl_deal_pmtdet_struct_h_e->h_newlocindentity_no);
								printf("Locatiom code afer capture |%s|",p_dl_deal_pmtdet_struct_h_e->h_newlocindentity_no);	
				
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_PmtDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_PmtDetPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_DLOthPopulate(DL_DEAL_OTH_STRUCT_H *p_dl_deal_oth_struct_h_b,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DLOthPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_dl_deal_oth_struct_h_b->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_dl_deal_oth_struct_h_b->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"LCL_IDENTNO",(char *)p_dl_deal_oth_struct_h_b->h_locindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"BRK_NO",(char *)p_dl_deal_oth_struct_h_b->h_brkrno);
                        CO_Rtv_DataString(chr_p_param_str,"CLT_REQDEL_IND",(char *)p_dl_deal_oth_struct_h_b->h_clt_reqdel_flag);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_oth_struct_h_b->h_access_stamp);
                        CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",(char *)p_dl_deal_oth_struct_h_b->h_dealcd);
                        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",(char *)p_dl_deal_oth_struct_h_b->h_dlt);
                        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_dl_deal_oth_struct_h_b->h_setldt);
                        CO_Rtv_DataString(chr_p_param_str,"DL_TYPE",(char *)p_dl_deal_oth_struct_h_b->h_classofdl);
                        CO_Rtv_DataString(chr_p_param_str,"LR_DL_CLASS",(char *)p_dl_deal_oth_struct_h_b->h_lrdltype);
                        CO_Rtv_DataDbl(chr_p_param_str,"DL_AMT",&(p_dl_deal_oth_struct_h_b->h_amt));
                        CO_Rtv_DataDbl(chr_p_param_str,"RATE",&(p_dl_deal_oth_struct_h_b->h_pr));
                        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",(char *)p_dl_deal_oth_struct_h_b->h_domcpclt_cd);
                        CO_Rtv_DataString(chr_p_param_str,"CLIENT_NOTE",(char *)p_dl_deal_oth_struct_h_b->h_custinfo);
                        CO_Rtv_DataString(chr_p_param_str,"FWDVALDT",(char *)p_dl_deal_oth_struct_h_b->h_lr_ndsdate);
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DLOthPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DLOthPopulate \n",NULL,NULL);
        return 1;
}


int	DL_Proc_DLPmtPopulate(DL_DEAL_PMTCHG_STRUCT_H *p_dl_deal_pmtchg_struct_h_c,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DLPmtPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_deal_pmtchg_struct_h_c->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_deal_pmtchg_struct_h_c->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",(char *)p_dl_deal_pmtchg_struct_h_c->h_dlt);
                        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_dl_deal_pmtchg_struct_h_c->h_setldt);
                        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_dl_deal_pmtchg_struct_h_c->h_pr));
                        CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT",&(p_dl_deal_pmtchg_struct_h_c->h_amt));
                        CO_Rtv_DataString(chr_p_param_str,"DOMCP_CUSTODYCLT",(char *)p_dl_deal_pmtchg_struct_h_c->h_domcp_custodyclt);
                        CO_Rtv_DataString(chr_p_param_str,"CP_CLT",(char *)p_dl_deal_pmtchg_struct_h_c->h_countclt);
                        CO_Rtv_DataString(chr_p_param_str,"CP_CLTNAME",(char *)p_dl_deal_pmtchg_struct_h_c->h_countcltnm);
                        CO_Rtv_DataString(chr_p_param_str,"CUSTCHGFLG",(char *)p_dl_deal_pmtchg_struct_h_c->h_cust_chgind);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_pmtchg_struct_h_c->h_access_stamp);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DLPmtPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DLPmtPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_SetlDetPopulate(char *p_eventid,DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_SetlDetPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"EVENT_ID",(char *)p_eventid);
                        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_dl_deal_sstdet_struct_h_a->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_dl_deal_sstdet_struct_h_a->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"PARTIAL_IND",(char *)p_dl_deal_sstdet_struct_h_a->h_ispart_);
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWQTY",&(p_dl_deal_sstdet_struct_h_a->h_newquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWAMT",&(p_dl_deal_sstdet_struct_h_a->h_newamount));
                        CO_Rtv_DataString(chr_p_param_str,"NEWREFNO",(char *)p_dl_deal_sstdet_struct_h_a->h_newindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_DT",(char *)p_dl_deal_sstdet_struct_h_a->h_instrdate);
                        CO_Rtv_DataString(chr_p_param_str,"MONEY_SETL_DT",(char *)p_dl_deal_sstdet_struct_h_a->h_moneydate);
                        CO_Rtv_DataDbl(chr_p_param_str,"RATE",&(p_dl_deal_sstdet_struct_h_a->h_pr));
                        CO_Rtv_DataDbl(chr_p_param_str,"BROKERCOMM",&(p_dl_deal_sstdet_struct_h_a->h_brokercomm));
                        CO_Rtv_DataString(chr_p_param_str,"SELFORREG",(char *)p_dl_deal_sstdet_struct_h_a->h_sel_forreg);
                        CO_Rtv_DataDbl(chr_p_param_str,"PEND_REG_QTY",&(p_dl_deal_sstdet_struct_h_a->h_pendregquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"MRK_DL_FAILQTY",&(p_dl_deal_sstdet_struct_h_a->h_marktrfquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"REC_INT_000",&(p_dl_deal_sstdet_struct_h_a->h_rec_int_000));
                        CO_Rtv_DataDbl(chr_p_param_str,"DL_COMPLETEQTY",&(p_dl_deal_sstdet_struct_h_a->h_mcomplquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_000",&(p_dl_deal_sstdet_struct_h_a->h_delta_000));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_001",&(p_dl_deal_sstdet_struct_h_a->h_delta_001));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_003",&(p_dl_deal_sstdet_struct_h_a->h_delta_002));
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_sstdet_struct_h_a->h_access_stamp);


RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_SetlDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_SetlDetPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RstPmPopulate(char *p_client, char *p_indentity_no, char *chr_p_access_stamp,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RstPmPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)chr_p_access_stamp);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RstPmPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RstPmPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RstSetlPopulate(char *p_client, char *p_indentity_no, char *chr_p_access_stamp,char *p_env_action,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RstSetlPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)chr_p_access_stamp);
                        CO_Rtv_DataString(chr_p_param_str,"ENV_ACTION",(char *)p_env_action);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RstSetlPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RstSetlPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RstCLHPopulate(char *p_client, char *p_indentity_no,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RstSetlPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"ACCOUNT",(char *)p_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_indentity_no);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RstCLHPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RstCLHPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_DLFailPopulate(DL_DEAL_FAIL_STRUCT_H *p_dl_deal_fail_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DLFailPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_deal_fail_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_deal_fail_struct_h->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"FAILREASON_CD",(char *)p_dl_deal_fail_struct_h->h_fail_cd);
                        CO_Rtv_DataString(chr_p_param_str,"CLIENT_NOTE",(char *)p_dl_deal_fail_struct_h->h_custinfo);
                        CO_Rtv_DataString(chr_p_param_str,"FAIL_DET",(char *)p_dl_deal_fail_struct_h->h_failinfo);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_fail_struct_h->h_access_stamp);
                        CO_Rtv_DataInt(chr_p_param_str,"SUB_FAIL_CD",(int *)&(p_dl_deal_fail_struct_h->h_subfailreas_cd));

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DLFailPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DLFailPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_DLNDSPopulate(DL_DEAL_NDS_STRUCT_H *p_dl_deal_nds_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DLNDSPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_dl_deal_nds_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_dl_deal_nds_struct_h->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"NDSDATE",(char *)p_dl_deal_nds_struct_h->h_ndsdate);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_nds_struct_h->h_access_stamp);


RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DLNDSPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DLNDSPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RUPrmtDetPopulate(DL_DEAL_PMTDET_STRUCT_H *p_dl_deal_pmtdet_struct_h_e,char *p_stregno,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RUPrmtDetPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"SRN_STR",(char *)p_stregno);
                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_deal_pmtdet_struct_h_e->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"VAL_FDT",(char *)p_dl_deal_pmtdet_struct_h_e->h_confdate);
                        CO_Rtv_DataString(chr_p_param_str,"VERFIED_WITH",(char *)p_dl_deal_pmtdet_struct_h_e->h_verfied_with);
                        CO_Rtv_DataDbl(chr_p_param_str,"AMT_DIFFER",&(p_dl_deal_pmtdet_struct_h_e->h_diffamount));
                        CO_Rtv_DataString(chr_p_param_str,"INFO1",(char *)p_dl_deal_pmtdet_struct_h_e->h_info1);
                        CO_Rtv_DataString(chr_p_param_str,"PARTIAL_IND",(char *)p_dl_deal_pmtdet_struct_h_e->h_ispart_);
                        CO_Rtv_DataString(chr_p_param_str,"BRK_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_brkrno);
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWQTY",&(p_dl_deal_pmtdet_struct_h_e->h_newquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWAMT",&(p_dl_deal_pmtdet_struct_h_e->h_newamount));
                        CO_Rtv_DataString(chr_p_param_str,"NEWREFNO",(char *)p_dl_deal_pmtdet_struct_h_e->h_newindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"NEWLOCREFNO",(char *)p_dl_deal_pmtdet_struct_h_e->h_newlocindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_pmtdet_struct_h_e->h_access_stamp);
                        CO_Rtv_DataDbl(chr_p_param_str,"GROSS_AMOUNT",&(p_dl_deal_pmtdet_struct_h_e->h_grossamount));
                        CO_Rtv_DataDbl(chr_p_param_str,"CP_AMT",&(p_dl_deal_pmtdet_struct_h_e->h_cpamt));
                        CO_Rtv_DataString(chr_p_param_str,"COMM_IDENT_NO",(char *)p_dl_deal_pmtdet_struct_h_e->h_comm_indentity_no);

				
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RUPrmtDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RUPrmtDetPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_RUSetlDetPopulate(char *p_eventid,char *p_stregno,DL_DEAL_SSTDET_STRUCT_H *p_dl_deal_sstdet_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RUSetlDetPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"GRUSSRN",(char *)p_stregno);
                        CO_Rtv_DataString(chr_p_param_str,"EVENT_ID",(char *)p_eventid);
                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_deal_sstdet_struct_h_a->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_deal_sstdet_struct_h_a->h_indentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"PARTIAL_IND",(char *)p_dl_deal_sstdet_struct_h_a->h_ispart_);
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWQTY",&(p_dl_deal_sstdet_struct_h_a->h_newquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"NEWAMT",&(p_dl_deal_sstdet_struct_h_a->h_newamount));
                        CO_Rtv_DataString(chr_p_param_str,"NEWREFNO",(char *)p_dl_deal_sstdet_struct_h_a->h_newindentity_no);
                        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_DT",(char *)p_dl_deal_sstdet_struct_h_a->h_instrdate);
                        CO_Rtv_DataString(chr_p_param_str,"MONEY_SETL_DT",(char *)p_dl_deal_sstdet_struct_h_a->h_moneydate);
                        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_dl_deal_sstdet_struct_h_a->h_pr));
                        CO_Rtv_DataDbl(chr_p_param_str,"BROKERCOMM",&(p_dl_deal_sstdet_struct_h_a->h_brokercomm));
                        CO_Rtv_DataString(chr_p_param_str,"SELFORREG",(char *)p_dl_deal_sstdet_struct_h_a->h_sel_forreg);
                        CO_Rtv_DataDbl(chr_p_param_str,"PEND_REG_QTY",&(p_dl_deal_sstdet_struct_h_a->h_pendregquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"MRK_DL_FAILQTY",&(p_dl_deal_sstdet_struct_h_a->h_marktrfquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"REC_INT_000",&(p_dl_deal_sstdet_struct_h_a->h_rec_int_000));
                        CO_Rtv_DataDbl(chr_p_param_str,"DL_COMPLETEQTY",&(p_dl_deal_sstdet_struct_h_a->h_mcomplquantity));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_000",&(p_dl_deal_sstdet_struct_h_a->h_delta_000));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_001",&(p_dl_deal_sstdet_struct_h_a->h_delta_001));
                        CO_Rtv_DataDbl(chr_p_param_str,"DELTA_003",&(p_dl_deal_sstdet_struct_h_a->h_delta_002));
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_sstdet_struct_h_a->h_access_stamp);


RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RUSetlDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RUSetlDetPopulate \n",NULL,NULL);
        return 1;
}

int DL_Proc_InstrConvInpPopulate(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

    p_dl_instrumentconv_oth_struct_h->h_cltt_arr =  (char *)calloc(2000,sizeof(char));
         
   if (p_dl_instrumentconv_oth_struct_h->h_cltt_arr==NULL)
   {
      APL_GOBACK_FAIL
   }

         memset(p_dl_instrumentconv_oth_struct_h->h_cltt_arr,NULL,sizeof(char));

   CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_InstrConvInpPopulate\n",NULL,NULL);

   CO_Rtv_DataInt(chr_p_param_str,"NOELEMENTS_ACCT_ARR",(int *)&(p_dl_instrumentconv_oth_struct_h->h_noelements_cltt_arr));
        CO_Rtv_DataString(chr_p_param_str,"FRM_SECCD",(char *)p_dl_instrumentconv_oth_struct_h->h_frm_instr_code);
        CO_Rtv_DataString(chr_p_param_str,"TO_SECURITY",(char *)p_dl_instrumentconv_oth_struct_h->h_to_instrurity);
        CO_Rtv_DataString(chr_p_param_str,"ACCOUNT",(char *)p_dl_instrumentconv_oth_struct_h->h_cltt_arr);

   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_InstrConvInpPopulate  \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_InstrConvInpPopulate  \n",NULL,NULL);
        return 1;
}

int DL_Proc_InstrChgPopulate(DL_INSTRUMENTCHG_STRUCT2_H *l_dl_instrumentchg_struct2_ha, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_InstrChgPopulate\n",NULL,NULL);

    CO_Rtv_DataString(chr_p_param_str,"OLD_INSTR_CODE",(char *)l_dl_instrumentchg_struct2_ha->h_oldinstr_code);
         CO_Rtv_DataString(chr_p_param_str,"NEW_INSTR_CODE",(char *)l_dl_instrumentchg_struct2_ha->h_newinstr_code);
         CO_Rtv_DataString(chr_p_param_str,"NEWISINCODE",(char *)l_dl_instrumentchg_struct2_ha->h_newinstr_isincode);
         CO_Rtv_DataString(chr_p_param_str,"LISTED_IND",(char *)l_dl_instrumentchg_struct2_ha->h_listed_ind);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)l_dl_instrumentchg_struct2_ha->h_access_stamp);

   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_InstrChgPopulate   \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_InstrChgPopulate  \n",NULL,NULL);
        return 1;
}

int   DL_Proc_LocChgPopulate(char *p_cseqno, DL_LOCNCHG_STRUCT_H *p_dl_locnchg_struct_h,char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_LocChgPopulate\n",NULL,NULL);
   CO_Rtv_DataString(chr_p_param_str,"NEW_SEQ_NUM",p_cseqno);
   CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_locnchg_struct_h->h_dl_client);
        CO_Rtv_DataString(chr_p_param_str,"IDEN_NO",(char *)p_dl_locnchg_struct_h->h_sequenceno);
        CO_Rtv_DataString(chr_p_param_str,"SECURITY_CD",(char *)p_dl_locnchg_struct_h->h_instr_code);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",(char *)p_dl_locnchg_struct_h->h_dlt);
        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_dl_locnchg_struct_h->h_setldt);
        CO_Rtv_DataString(chr_p_param_str,"DETAILS",(char *)p_dl_locnchg_struct_h->h_infos);
        CO_Rtv_DataString(chr_p_param_str,"FRM_LOC",(char *)p_dl_locnchg_struct_h->h_frm_loc);
        CO_Rtv_DataString(chr_p_param_str,"TO_LOCATION",(char *)p_dl_locnchg_struct_h->h_to_location);
        CO_Rtv_DataString(chr_p_param_str,"SENDMSG_IND",(char *)p_dl_locnchg_struct_h->h_sendmsg_ind);
        CO_Rtv_DataString(chr_p_param_str,"BILLABLE_IND",(char *)p_dl_locnchg_struct_h->h_billable_flag);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_dl_locnchg_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_dl_locnchg_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_dl_locnchg_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_dl_locnchg_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",(char *)p_dl_locnchg_struct_h->h_newdt);
        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_dl_locnchg_struct_h->h_qty));
        CO_Rtv_DataString(chr_p_param_str,"DF_TXNR_IDEN",(char *)p_dl_locnchg_struct_h->h_df_txnr_iden);
        CO_Rtv_DataString(chr_p_param_str,"RF_DL_IDENT",(char *)p_dl_locnchg_struct_h->h_rf_dl_ident);
        CO_Rtv_DataString(chr_p_param_str,"DEALSTAT",(char *)p_dl_locnchg_struct_h->h_dealstat);
        CO_Rtv_DataString(chr_p_param_str,"LOC_CHNG_STAT",(char *)p_dl_locnchg_struct_h->h_loc_chng_stat);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_locnchg_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"SETL",(char *)p_dl_locnchg_struct_h->h_setl);
        CO_Rtv_DataString(chr_p_param_str,"DF_SETLDATE",(char *)p_dl_locnchg_struct_h->h_dfsettdate);
        CO_Rtv_DataString(chr_p_param_str,"RF_SETL_DATE",(char *)p_dl_locnchg_struct_h->h_rfsettdate);
		CO_Rtv_DataString(chr_p_param_str,"FRM_TYPE",(char *)p_dl_locnchg_struct_h->h_frm_type);
		CO_Rtv_DataString(chr_p_param_str,"TO_TYPE",(char *)p_dl_locnchg_struct_h->h_to_type);
		CO_Rtv_DataString(chr_p_param_str,"CHANGE",(char *)p_dl_locnchg_struct_h->h_change);
		CO_Rtv_DataString(chr_p_param_str,"UNBLOCK_DATE",(char *)p_dl_locnchg_struct_h->h_unblock_date);
		CO_Rtv_DataString(chr_p_param_str,"TRANSFER_TYPE",(char *)p_dl_locnchg_struct_h->h_trans_type);


   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_LocChgPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_LocChgPopulate  \n",NULL,NULL);
        return 1;
}

int   DL_Proc_UpdMisPopulate(char *p_mistxnident, DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_UpdMisPopulate \n",NULL,NULL);
   CO_Rtv_DataString(chr_p_param_str,"NEW_REFNO",(char *)p_mistxnident);
   CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)l_dl_misdeal_struct_h->h_dl_client);
        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)l_dl_misdeal_struct_h->h_indentity_no);
        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",(char *)l_dl_misdeal_struct_h->h_domcpclt_cd);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",(char *)l_dl_misdeal_struct_h->h_dealcd);
        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)l_dl_misdeal_struct_h->h_setldt);
        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(l_dl_misdeal_struct_h->h_qty));
        CO_Rtv_DataString(chr_p_param_str,"SECURITY_CD",(char *)l_dl_misdeal_struct_h->h_instr_code);
        CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT",&(l_dl_misdeal_struct_h->h_amt));
        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(l_dl_misdeal_struct_h->h_pr));
        CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",(char *)l_dl_misdeal_struct_h->h_newdt);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)l_dl_misdeal_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)l_dl_misdeal_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)l_dl_misdeal_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)l_dl_misdeal_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"CP_CLTNAME",(char *)l_dl_misdeal_struct_h->h_countcltnm);
        CO_Rtv_DataString(chr_p_param_str,"MIS_DL_STAT",(char *)l_dl_misdeal_struct_h->h_misdeal_status);
        CO_Rtv_DataString(chr_p_param_str,"CP_CLT",(char *)l_dl_misdeal_struct_h->h_countclt);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)l_dl_misdeal_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"INFO",(char *)l_dl_misdeal_struct_h->h_info);
        CO_Rtv_DataString(chr_p_param_str,"PLACEOF_DEAL",(char *)l_dl_misdeal_struct_h->h_place_of_deal);
        CO_Rtv_DataString(chr_p_param_str,"MRKT_IND",(char *)l_dl_misdeal_struct_h->h_market_flag);
        CO_Rtv_DataString(chr_p_param_str,"DESCRIPTION",(char *)l_dl_misdeal_struct_h->h_description);
        CO_Rtv_DataString(chr_p_param_str,"DEALDT",(char *)l_dl_misdeal_struct_h->h_dealdt);
        CO_Rtv_DataString(chr_p_param_str,"CLIENTOF_CD",(char *)l_dl_misdeal_struct_h->h_clientofcode);
        CO_Rtv_DataString(chr_p_param_str,"CLIENTOF",(char *)l_dl_misdeal_struct_h->h_clientof);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUCT_PERSON",(char *)l_dl_misdeal_struct_h->h_instruct_person);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUCT_PERSONNM",(char *)l_dl_misdeal_struct_h->h_instruct_personnm);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_CLS",(char *)l_dl_misdeal_struct_h->h_deal_class);
        CO_Rtv_DataString(chr_p_param_str,"TRRF_REF",(char *)l_dl_misdeal_struct_h->h_trrf_ident);
        CO_Rtv_DataString(chr_p_param_str,"COMM_REF",(char *)l_dl_misdeal_struct_h->h_comm_ident);
        CO_Rtv_DataString(chr_p_param_str,"POOL_REF",(char *)l_dl_misdeal_struct_h->h_pool_ident);
        CO_Rtv_DataChar(chr_p_param_str,"SEND_MSG_IND",&(l_dl_misdeal_struct_h->h_send_msg_ind));
        CO_Rtv_DataString(chr_p_param_str,"PARTY_CON",(char *)l_dl_misdeal_struct_h->h_party_con);
		  CO_Rtv_DataString(chr_p_param_str,"DSNIDENT",(char *)l_dl_misdeal_struct_h->h_dsn_ident);

   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_UpdMisPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_UpdMisPopulate  \n",NULL,NULL);
        return 1;
}

int DL_Proc_MktPrcPopulate(MT_DLYMKTPRC_STRUCT_H *p_mt_dlymktprc_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_MktPrcPopulate\n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"PRICE_DATE",(char *)p_mt_dlymktprc_struct_h->h_prdt);
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",(char *)p_mt_dlymktprc_struct_h->h_instr_code);
        CO_Rtv_DataDbl(chr_p_param_str,"CLOSING_PR",&(p_mt_dlymktprc_struct_h->h_closing_pr));
        CO_Rtv_DataString(chr_p_param_str,"MODIFYMODE",(char *)p_mt_dlymktprc_struct_h->h_updtmode);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_mt_dlymktprc_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_mt_dlymktprc_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_mt_dlymktprc_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"MKRTPR_STAT",(char *)p_mt_dlymktprc_struct_h->h_mkrtpr_stat);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_mt_dlymktprc_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_mt_dlymktprc_struct_h->h_checker_dt);

   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_MktPrcPopulate   \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_MktPrcPopulate  \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RegDetPopulate(DL_REGDET_STRUCT_H *p_dl_regdet_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RegDetPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_regdet_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_regdet_struct_h->h_indentity_no);
                        CO_Rtv_DataInt(chr_p_param_str,"SRL_NO",(int *)&(p_dl_regdet_struct_h->h_srl_no));
                        CO_Rtv_DataString(chr_p_param_str,"REG_ST_CD",(char *)p_dl_regdet_struct_h->h_reg_st_cd);
                        CO_Rtv_DataString(chr_p_param_str,"DEAL_DT",(char *)p_dl_regdet_struct_h->h_txndate);
                        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_dl_regdet_struct_h->h_qty));
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_regdet_struct_h->h_access_stamp);
                        CO_Rtv_DataDbl(chr_p_param_str,"MOVED_QTY",&(p_dl_regdet_struct_h->h_quantitymoved));
                        CO_Rtv_DataDbl(chr_p_param_str,"MANIFOLD_QTY",&(p_dl_regdet_struct_h->h_quantitymanifld));
                        CO_Rtv_DataString(chr_p_param_str,"DT_CLIENT_FOR",(char *)p_dl_regdet_struct_h->h_dtcltfor);
                        CO_Rtv_DataString(chr_p_param_str,"PRC_SMR_DATE",(char *)p_dl_regdet_struct_h->h_prcsmrdate);
                        CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_dl_regdet_struct_h->h_status_prc);
                        CO_Rtv_DataString(chr_p_param_str,"PRC_SETL_DATE",(char *)p_dl_regdet_struct_h->h_prcstldate);
                        CO_Rtv_DataDbl(chr_p_param_str,"AMR_AMOUNT",&(p_dl_regdet_struct_h->h_smramount));

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RegDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RegDetPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RegArrPopulate(REQDETAILS_STRUCT_H *p_reqdetails_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	int	int_l_int_loop = 0;
	int	int_l_int_temp = 0;
	double	l_debit_indl_temp = 0;
	char chr_l_str_temp[APL_DATE_LEN];
	char chr_l_search_lbl[20];

	long        *l_lng_TmpSrno;
	double      *l_dbl_tmpquantity;
	char        *chr_l_str_tmpacstr;

        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RegArrPopulate\n",NULL,NULL);

         CO_Rtv_DataInt(chr_p_param_str,"NOELEMENTS",&int_l_int_temp);
			p_reqdetails_struct_h->h_element_cnt = int_l_int_temp;
			
		   if ( ( l_lng_TmpSrno = calloc(int_l_int_temp,sizeof(long)) ) == NULL )
   		{
      		return APL_FAILURE;
   		}
   		if ( ( l_dbl_tmpquantity = calloc(int_l_int_temp,sizeof(double)) ) == NULL )
   		{
      		free(l_lng_TmpSrno );
      		return APL_FAILURE;
   		}
   		if ( ( chr_l_str_tmpacstr = calloc(int_l_int_temp*20,sizeof(char)) ) == NULL )
   		{
      		free(l_lng_TmpSrno );
      		free(l_dbl_tmpquantity );
      		return APL_FAILURE;
   		}

   		p_reqdetails_struct_h->h_srl_no = l_lng_TmpSrno;
   		p_reqdetails_struct_h->h_qty = l_dbl_tmpquantity;
   		p_reqdetails_struct_h->h_access_stamp = chr_l_str_tmpacstr;


		   for(int_l_int_loop  = 0; (int_l_int_loop  < p_reqdetails_struct_h->h_element_cnt ); int_l_int_loop  ++)
   		{

				strcpy(chr_l_search_lbl,APL_NULL_STRING);
				int_l_int_temp = 0;
				l_debit_indl_temp = 0;
				strcpy(chr_l_str_temp,APL_NULL_STRING);

				sprintf(chr_l_search_lbl,"ARR_SRL%d",int_l_int_loop);
				CO_Rtv_DataInt(chr_p_param_str,chr_l_search_lbl,&int_l_int_temp);
				*(p_reqdetails_struct_h->h_srl_no+int_l_int_loop) = int_l_int_temp;

				strcpy(chr_l_search_lbl,APL_NULL_STRING);
		
				sprintf(chr_l_search_lbl,"ARR_QTY%d",int_l_int_loop);
				CO_Rtv_DataDbl(chr_p_param_str,chr_l_search_lbl,&l_debit_indl_temp);
				*(p_reqdetails_struct_h->h_qty+int_l_int_loop) = l_debit_indl_temp;
		
				strcpy(chr_l_search_lbl,APL_NULL_STRING);

				sprintf(chr_l_search_lbl,"ARR_ACCST%d",int_l_int_loop);
				CO_Rtv_DataString(chr_p_param_str,chr_l_search_lbl,(char *)chr_l_str_temp);
				strcpy((p_reqdetails_struct_h->h_access_stamp+(int_l_int_loop * APL_DATE_LEN)),chr_l_str_temp);

   		}

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RegArrPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RegArrPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RegTrfDetPopulate(REG_TRF_STRUCT_H *p_reg_trf_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RegTrfDetPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_reg_trf_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",(char *)p_reg_trf_struct_h->h_instr_code);
                        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_reg_trf_struct_h->h_loccode);
                        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_reg_trf_struct_h->h_qty));
                        CO_Rtv_DataString(chr_p_param_str,"LOCREFNO_RF",(char *)p_reg_trf_struct_h->h_locindentity_no_rf);
                        CO_Rtv_DataString(chr_p_param_str,"LOCREFNO_DF",(char *)p_reg_trf_struct_h->h_locindentity_no_df);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RegTrfDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RegTrfDetPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_RstRegDetPopulate(DL_REGDET_STRUCT_H *p_dl_regdet_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_RstRegDetPopulate\n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_dl_regdet_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_dl_regdet_struct_h->h_indentity_no);
                        CO_Rtv_DataInt(chr_p_param_str,"SRL_NO",(int *)&(p_dl_regdet_struct_h->h_srl_no));
                        CO_Rtv_DataString(chr_p_param_str,"REG_ST_CD",(char *)p_dl_regdet_struct_h->h_reg_st_cd);
                        CO_Rtv_DataString(chr_p_param_str,"DEAL_DT",(char *)p_dl_regdet_struct_h->h_txndate);
                        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_dl_regdet_struct_h->h_qty));
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_regdet_struct_h->h_access_stamp);
                        CO_Rtv_DataDbl(chr_p_param_str,"MOVED_QTY",&(p_dl_regdet_struct_h->h_quantitymoved));
                        CO_Rtv_DataDbl(chr_p_param_str,"MANIFOLD_QTY",&(p_dl_regdet_struct_h->h_quantitymanifld));
                        CO_Rtv_DataString(chr_p_param_str,"DT_CLIENT_FOR",(char *)p_dl_regdet_struct_h->h_dtcltfor);
                        CO_Rtv_DataString(chr_p_param_str,"PRC_SMR_DATE",(char *)p_dl_regdet_struct_h->h_prcsmrdate);
                        CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_dl_regdet_struct_h->h_status_prc);
                        CO_Rtv_DataString(chr_p_param_str,"PRC_SETL_DATE",(char *)p_dl_regdet_struct_h->h_prcstldate);
                        CO_Rtv_DataDbl(chr_p_param_str,"AMR_AMOUNT",&(p_dl_regdet_struct_h->h_smramount));

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_RstRegDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_RstRegDetPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_OrdDetPopulate(OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b, char *p_ord_ident, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_OrdDetPopulate\n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_or_orderdetails_struct_h_b->h_dl_client);
         CO_Rtv_DataString(chr_p_param_str,"ORD_REFNO",(char *)p_or_orderdetails_struct_h_b->h_orderindentity_no);
         CO_Rtv_DataString(chr_p_param_str,"BUY_SELL_IND",(char *)p_or_orderdetails_struct_h_b->h_buy_sell_flag);
         CO_Rtv_DataString(chr_p_param_str,"ORD_DATE",(char *)p_or_orderdetails_struct_h_b->h_orderdate);
         CO_Rtv_DataDbl(chr_p_param_str,"ORD_QTY",&(p_or_orderdetails_struct_h_b->h_orderquantity));
         CO_Rtv_DataString(chr_p_param_str,"LIMIT_IND",(char *)p_or_orderdetails_struct_h_b->h_limit_ind);
         CO_Rtv_DataString(chr_p_param_str,"ISGTE_IND",(char *)p_or_orderdetails_struct_h_b->h_isgte_ind);
         CO_Rtv_DataString(chr_p_param_str,"ALL_NONE_IND",(char *)p_or_orderdetails_struct_h_b->h_all_none_ind);
         CO_Rtv_DataString(chr_p_param_str,"EX_ARENA",(char *)p_or_orderdetails_struct_h_b->h_ex_arena);
         CO_Rtv_DataString(chr_p_param_str,"ORD_STAT",(char *)p_or_orderdetails_struct_h_b->h_ord_stat);
         CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",(char *)p_or_orderdetails_struct_h_b->h_instr_code);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_or_orderdetails_struct_h_b->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_or_orderdetails_struct_h_b->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_or_orderdetails_struct_h_b->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_or_orderdetails_struct_h_b->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_or_orderdetails_struct_h_b->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"EXP_DATE",(char *)p_or_orderdetails_struct_h_b->h_expirydate);
         CO_Rtv_DataDbl(chr_p_param_str,"LIMIT_PR",&(p_or_orderdetails_struct_h_b->h_limitpr));
         CO_Rtv_DataString(chr_p_param_str,"DATEOF_CANCEL",(char *)p_or_orderdetails_struct_h_b->h_canceleddate);
         CO_Rtv_DataDbl(chr_p_param_str,"EXEC_QTY",&(p_or_orderdetails_struct_h_b->h_execquantity));
         CO_Rtv_DataString(chr_p_param_str,"ALLOW_DROPDT",(char *)p_or_orderdetails_struct_h_b->h_candropdate);
         CO_Rtv_DataString(chr_p_param_str,"BROKER_CD",(char *)p_or_orderdetails_struct_h_b->h_broker_cd);
         CO_Rtv_DataString(chr_p_param_str,"LCL_IDENTNO",(char *)p_or_orderdetails_struct_h_b->h_locindentity_no);
         CO_Rtv_DataString(chr_p_param_str,"LR_DL_CLASS",(char *)p_or_orderdetails_struct_h_b->h_lrdltype);
         CO_Rtv_DataString(chr_p_param_str,"LR_CHECK_DATE",(char *)p_or_orderdetails_struct_h_b->h_lr_chkdate);
         CO_Rtv_DataString(chr_p_param_str,"LR_UNBLK_DATE",(char *)p_or_orderdetails_struct_h_b->h_lr_ublckdate);
         CO_Rtv_DataString(chr_p_param_str,"UNBLK_DATE",(char *)p_or_orderdetails_struct_h_b->h_ublckdate);
         CO_Rtv_DataString(chr_p_param_str,"LAST_EXEC_DATE",(char *)p_or_orderdetails_struct_h_b->h_lastexecdate);
         CO_Rtv_DataString(chr_p_param_str,"LAST_DL_DATE",(char *)p_or_orderdetails_struct_h_b->h_lastdeal);
         CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",p_ord_ident);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_OrdDetPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_OrdDetPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_ResOrdPopulate(char *p_ord_client, char *p_deal_ident, char *p_deal_access_stamp, char *p_ord_access_stamp,char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_ResOrdPopulate\n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLIENT",p_ord_client);
         CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",p_deal_ident);
         CO_Rtv_DataString(chr_p_param_str,"ORDACCSTAMP",p_ord_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"TRDACCSTAMP",p_deal_access_stamp);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_ResOrdPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_ResOrdPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_OrdArrPopulate(ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

   int   int_l_int_loop = 0;
   int   int_l_int_temp = 0;
   double   l_debit_indl_temp = 0;
   char chr_l_search_lbl[20];

   double *l_dbl_tmpquantity;
   double *l_dbl_tmpcost;
   double *l_dbl_tmpbrokercomm;

        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_OrdArrPopulate\n",NULL,NULL);

         CO_Rtv_DataInt(chr_p_param_str,"NOELEMENTS",&int_l_int_temp);
         p_or_orderdetails_struct_h_b->h_element_cnt = int_l_int_temp;

         if ( ( l_dbl_tmpquantity = calloc(int_l_int_temp,sizeof(double)) ) == NULL )
         {
            return APL_FAILURE;
         }

         if ( ( l_dbl_tmpcost = calloc(int_l_int_temp,sizeof(double)) ) == NULL )
         {
            free(l_dbl_tmpquantity);
            return APL_FAILURE;
         }

         if ( ( l_dbl_tmpbrokercomm = calloc(int_l_int_temp,sizeof(double)) ) == NULL )
         {
            free(l_dbl_tmpquantity);
            free(l_dbl_tmpcost);
            return APL_FAILURE;
         }

         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_or_orderdetails_struct_h_b->h_access_stamp);
         p_or_orderdetails_struct_h_b->h_qty = l_dbl_tmpquantity;
         p_or_orderdetails_struct_h_b->h_pr = l_dbl_tmpcost;
         p_or_orderdetails_struct_h_b->h_brokercomm = l_dbl_tmpbrokercomm;

         for(int_l_int_loop  = 0; (int_l_int_loop  < p_or_orderdetails_struct_h_b->h_element_cnt ); int_l_int_loop  ++)
         {

            strcpy(chr_l_search_lbl,APL_NULL_STRING);
            l_debit_indl_temp = 0;

            strcpy(chr_l_search_lbl,APL_NULL_STRING);
            sprintf(chr_l_search_lbl,"QTY%d",int_l_int_loop);
            CO_Rtv_DataDbl(chr_p_param_str,chr_l_search_lbl,&l_debit_indl_temp);
            *(p_or_orderdetails_struct_h_b->h_qty+int_l_int_loop) = l_debit_indl_temp;

            strcpy(chr_l_search_lbl,APL_NULL_STRING);
            sprintf(chr_l_search_lbl,"PRICE%d",int_l_int_loop);
            CO_Rtv_DataDbl(chr_p_param_str,chr_l_search_lbl,&l_debit_indl_temp);
            *(p_or_orderdetails_struct_h_b->h_pr+int_l_int_loop) = l_debit_indl_temp;

            strcpy(chr_l_search_lbl,APL_NULL_STRING);
            sprintf(chr_l_search_lbl,"BRKCOMM%d",int_l_int_loop);
            CO_Rtv_DataDbl(chr_p_param_str,chr_l_search_lbl,&l_debit_indl_temp);
            *(p_or_orderdetails_struct_h_b->h_brokercomm+int_l_int_loop) = l_debit_indl_temp;
         }

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_OrdArrPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_OrdArrPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_OrdPopulate(DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_b,char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_OrdPopulate\n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_deal_execdet_struct_h_b->h_dl_client);
        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",(char *)p_deal_execdet_struct_h_b->h_indentity_no);
        CO_Rtv_DataString(chr_p_param_str,"ORD_REFNO",(char *)p_deal_execdet_struct_h_b->h_orderindentity_no);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",(char *)p_deal_execdet_struct_h_b->h_dlt);
        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_deal_execdet_struct_h_b->h_setldt);
        CO_Rtv_DataString(chr_p_param_str,"DL_CLASS",(char *)p_deal_execdet_struct_h_b->h_classofdl);
        CO_Rtv_DataString(chr_p_param_str,"GENFXADV",(char *)p_deal_execdet_struct_h_b->h_gen_fxadv_ind);
        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_deal_execdet_struct_h_b->h_loccode);
        CO_Rtv_DataString(chr_p_param_str,"SPOTTRD_IND",(char *)p_deal_execdet_struct_h_b->h_isspotdl);
        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",(char *)p_deal_execdet_struct_h_b->h_domcpclt_cd);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",(char *)p_deal_execdet_struct_h_b->h_dealcd);
        CO_Rtv_DataString(chr_p_param_str,"TAX",(char *)p_deal_execdet_struct_h_b->h_tax_amount);
        CO_Rtv_DataString(chr_p_param_str,"PAYLOC_IND",(char *)p_deal_execdet_struct_h_b->h_ispymtlocal);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_deal_execdet_struct_h_b->h_pos_stat);
        CO_Rtv_DataString(chr_p_param_str,"VAL_FDT",(char *)p_deal_execdet_struct_h_b->h_confdate);
        CO_Rtv_DataString(chr_p_param_str,"EX_ARENA",(char *)p_deal_execdet_struct_h_b->h_ex_arena);
        CO_Rtv_DataDbl(chr_p_param_str,"STEXCOMM",&(p_deal_execdet_struct_h_b->h_stex_comm));
        CO_Rtv_DataDbl(chr_p_param_str,"OTH_COMM",&(p_deal_execdet_struct_h_b->h_oth_comm));
        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_deal_execdet_struct_h_b->h_qty));
        CO_Rtv_DataDbl(chr_p_param_str,"BROKERCOMM",&(p_deal_execdet_struct_h_b->h_brokercomm));
        CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT",&(p_deal_execdet_struct_h_b->h_amt));
        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_deal_execdet_struct_h_b->h_pr));
        CO_Rtv_DataString(chr_p_param_str,"BRK_NO",(char *)p_deal_execdet_struct_h_b->h_brkrno);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_OrdPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_OrdPopulate \n",NULL,NULL);
        return 1;
}

int   DL_Proc_SMIAmdCanUpdStatPopulate(char *p_client, char *p_indentity_no, char *p_clt_rej_flag, char *p_amd_can_flag,char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_SMIAmdCanUpdStatPopulate\n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLIENT",p_client);
         CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NUM",p_indentity_no);
         CO_Rtv_DataString(chr_p_param_str,"ACC_REJ_FLAG",p_clt_rej_flag);
         CO_Rtv_DataString(chr_p_param_str,"AMD_CAN_FLAG",p_amd_can_flag);

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_SMIAmdCanUpdStatPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_SMIAmdCanUpdStatPopulate \n",NULL,NULL);
        return 1;
}

int	DL_Proc_MultReasPopulate(char *chr_p_param_str,int *p_snd_msg)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	DL_MULT_REAS_CODES_STRUCT_H		l_dl_mult_reas_codes_struct_ha ;
	DEBUG_INFO_STRUCT_H				*l_debug_info_ptr		 			 = (DEBUG_INFO_STRUCT_H *) NULL; 
	char							chr_l_label[20]			 			 =	APL_NULL_STRING;
	int 							i									 = 0	;
	int 							j									 =		0	;
	char 							chr_h_param_str[4000]	 			 =	 	APL_NULL_STRING;
	char							h_dl_client[11]		 			 = 	APL_NULL_STRING;
	char							h_indentity_no[17]			 			 =		APL_NULL_STRING;
	char							chr_l_failcode_A[3]	 				 =	APL_NULL_STRING;
	char							l_subfailreason_cd[3]				=	APL_NULL_STRING;
	int 							int_l_ccseligfail_flg   = 0;
	int							h_subfailreas_cd		 			 =		0;
	char							h_fail_cd[3]		 			 =		APL_NULL_STRING;
   char  						chr_l_current_date_time[APL_DATE_LEN]    = 	APL_NULL_STRING;
	int							int_l_count				 			 =		0;
	DL_MULT_REAS_CODES_STRUCT_H		*h_multreas_struct  			 = (DL_MULT_REAS_CODES_STRUCT_H *)NULL;
	int							int_l_value_found					 =		0	;
	int							z									 =		0	;
	int							h_send_msg_ind						 =		0	;
	int							int_l_reascode_found				 =		0	;
	int							int_l_reasqual_found				 =		0	;
	int							int_l_statreas_found				 =		0	;
	int							int_l_statqual_found				 =		0	;
	int							int_l_note_found					 =		0	;
	int							int_l_no_of_rows					 =		0	;

	memset(&l_dl_mult_reas_codes_struct_ha,NULL,sizeof(DL_MULT_REAS_CODES_STRUCT_H));
   CO_ProcMonitor(APL_OUT_FILE,"Entered CPopulateMultReasStruct\n",NULL,NULL);

	

	

	strcpy(chr_h_param_str,chr_p_param_str);
	strcpy(chr_l_current_date_time, APL_NULL_STRING);

   

   if ( APL_FAILURE == CO_RtvSysDtTime( chr_l_current_date_time,
                                             &l_debug_info_ptr) )
   {
      APL_GOBACK_FAIL;
   }
   CO_Rtv_DataString(chr_h_param_str,"CLIENT",h_dl_client);
   CO_Rtv_DataString(chr_h_param_str,"IDENTIY_NO",h_indentity_no);
   CO_Rtv_DataString(chr_h_param_str,"FAILREASON_CD",h_fail_cd);
	CO_Rtv_DataInt(chr_p_param_str,"SUB_FAIL_CD",(int *)&h_subfailreas_cd);


	if(APL_FAILURE	==	DL_Rtv_MultReas(h_dl_client,
													h_indentity_no,
													&h_multreas_struct,&int_l_count,&l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}
   for(i=1;i<=2;i++)
	{
		memset(&l_dl_mult_reas_codes_struct_ha,NULL,sizeof(DL_MULT_REAS_CODES_STRUCT_H));
		strcpy(chr_h_param_str,chr_p_param_str);

		strcpy(l_dl_mult_reas_codes_struct_ha.h_dl_client,h_dl_client);
		strcpy(l_dl_mult_reas_codes_struct_ha.h_indentity_no,h_indentity_no);
		strcpy(l_dl_mult_reas_codes_struct_ha.h_fail_cd,h_fail_cd);
		l_dl_mult_reas_codes_struct_ha.h_subfailreas_cd = h_subfailreas_cd;

		strcpy(l_dl_mult_reas_codes_struct_ha.h_access_stamp,chr_l_current_date_time);
		memset(chr_l_label,APL_NULL_CHAR,20);
		sprintf(chr_l_label,"%s%d","STATQUAL",i);
     	CO_Rtv_DataString(chr_h_param_str,chr_l_label,l_dl_mult_reas_codes_struct_ha.h_stat_qual);
		memset(chr_l_label,APL_NULL_CHAR,20);
		sprintf(chr_l_label,"%s%d","STATREAS",i);
     	CO_Rtv_DataString(chr_h_param_str,chr_l_label,l_dl_mult_reas_codes_struct_ha.h_stat_reas);
		memset(chr_l_label,APL_NULL_CHAR,20);
		sprintf(chr_l_label,"%s%d","REASQUAL",i);
     	CO_Rtv_DataString(chr_h_param_str,chr_l_label,l_dl_mult_reas_codes_struct_ha.h_failreas_qual);

		for(j=1;j<=3;j++)
		{
			
				sprintf(l_dl_mult_reas_codes_struct_ha.h_blck_no,"%d%d",i,j);

				memset(chr_l_label,APL_NULL_CHAR,20);
				sprintf(chr_l_label,"%s%d%d","REASCODE",i,j);
     	  		CO_Rtv_DataString(chr_h_param_str,chr_l_label,l_dl_mult_reas_codes_struct_ha.h_failreas_cd);
			
				memset(chr_l_label,APL_NULL_CHAR,20);
				sprintf(chr_l_label,"%s%d%d","INFO",i,j);
     			CO_Rtv_DataString(chr_h_param_str,chr_l_label,l_dl_mult_reas_codes_struct_ha.h_info);

				if ((strcmp(l_dl_mult_reas_codes_struct_ha.h_stat_qual,APL_NULL_STRING)!=0) && (strcmp(l_dl_mult_reas_codes_struct_ha.h_stat_reas,APL_NULL_STRING)!=0) && (strcmp(l_dl_mult_reas_codes_struct_ha.h_failreas_cd,APL_NULL_STRING)!=0) || (strcmp(l_dl_mult_reas_codes_struct_ha.h_blck_no,"11")==0))
				{
				if (((strcmp(l_dl_mult_reas_codes_struct_ha.h_fail_cd,h_multreas_struct[0].h_fail_cd)==0) || (l_dl_mult_reas_codes_struct_ha.h_subfailreas_cd==h_multreas_struct[0].h_subfailreas_cd)) && (int_l_count!=0))
				{

					int_l_note_found =0;
					int_l_statqual_found =0;
					int_l_statreas_found=0;
					int_l_reasqual_found=0;
					int_l_reascode_found=0;
					if(h_send_msg_ind ==0)
					{
						for(z=0;z<int_l_count;z++)
						{
							if(strcmp(l_dl_mult_reas_codes_struct_ha.h_info,h_multreas_struct[z].h_info)==0)
							{
								int_l_note_found =	1;
							}
						}
						
					}
					if(h_send_msg_ind ==0)
					{
						for(z=0;z<int_l_count;z++)
						{
							if(strcmp(l_dl_mult_reas_codes_struct_ha.h_stat_qual,h_multreas_struct[z].h_stat_qual)==0)
							{
								int_l_statqual_found =1;
							}
						}
						
					}

					if(h_send_msg_ind ==0)
					{
						for(z=0;z<int_l_count;z++)
						{
							if(strcmp(l_dl_mult_reas_codes_struct_ha.h_stat_reas,h_multreas_struct[z].h_stat_reas)==0)
							{
								int_l_statreas_found =	1;
							}
						}
					
					}

					if(h_send_msg_ind ==0)
					{
						for(z=0;z<int_l_count;z++)
						{
							if(strcmp(l_dl_mult_reas_codes_struct_ha.h_failreas_qual,h_multreas_struct[z].h_failreas_qual)==0)
							{
								int_l_reasqual_found =	1;
							}
						}
						
					}
					if(h_send_msg_ind ==0)
					{
						for(z=0;z<int_l_count;z++)
						{
							if(strcmp(l_dl_mult_reas_codes_struct_ha.h_failreas_cd,h_multreas_struct[z].h_failreas_cd)==0)
							{
								int_l_reascode_found =	1;
							}
						}
						
					}

					if((int_l_reascode_found==1) && (int_l_reasqual_found==1) && (int_l_statreas_found==1) && (int_l_statqual_found==1) && (int_l_note_found==1))
						h_send_msg_ind=0;
					else
						h_send_msg_ind=1;
				}
				else
				h_send_msg_ind=1;
					if(APL_FAILURE== DL_Mod_MultReasNew(&l_dl_mult_reas_codes_struct_ha,&l_debug_info_ptr))/* Anjaneyulu added & for ISKB_1621 */
					{
						APL_GOBACK_FAIL
					}
					else
					{
						int_l_no_of_rows=int_l_no_of_rows+1;
					}

				
				if((i==1) && (j==1))
				{
					int_l_ccseligfail_flg = 0;
					if (APL_FAILURE == DL_Chk_DLFailCd(l_dl_mult_reas_codes_struct_ha.h_fail_cd,&int_l_ccseligfail_flg,&l_debug_info_ptr))
					{
						APL_GOBACK_FAIL
					}
						printf("flag |%d|\n",int_l_ccseligfail_flg); 
					if (int_l_ccseligfail_flg)
					{
   					if ( APL_FAILURE ==  DL_Mod_CCSPendDL(h_dl_client,
                        						h_indentity_no,
                        						MS_CCS_FC,
														l_dl_mult_reas_codes_struct_ha.h_fail_cd, 
														l_dl_mult_reas_codes_struct_ha.h_subfailreas_cd,
														l_dl_mult_reas_codes_struct_ha.h_info,
                        						&l_debug_info_ptr) )
   					{
       					APL_GOBACK_FAIL
   					}
					}
				}
				else
				{
					memset(chr_l_failcode_A,APL_NULL_CHAR,3);
					memset(l_subfailreason_cd,APL_NULL_CHAR,3);
					if (APL_FAILURE == DL_Rtv_DLFailCd(l_dl_mult_reas_codes_struct_ha.h_stat_qual,
																	l_dl_mult_reas_codes_struct_ha.h_stat_reas,
																	l_dl_mult_reas_codes_struct_ha.h_stat_reas,
																	l_dl_mult_reas_codes_struct_ha.h_failreas_cd,
																	&chr_l_failcode_A,&l_subfailreason_cd,
																	&l_debug_info_ptr))
					{ 
						APL_GOBACK_FAIL
					}
					if (strcmp(chr_l_failcode_A,APL_NULL_STRING))
					{
   					if ( APL_FAILURE ==  DL_Mod_CCSPendDL(h_dl_client,
                        						h_indentity_no,
                        						MS_CCS_FC,
														chr_l_failcode_A, l_subfailreason_cd, l_dl_mult_reas_codes_struct_ha.h_info,   
                        						&l_debug_info_ptr) )
   					{
       					APL_GOBACK_FAIL    
   					}
					}
				}
			 }
				
			 
		 }
	}
	printf("reached till her -- testing biju\n");
	if(int_l_count!=int_l_no_of_rows)
	{
		h_send_msg_ind=1;
	}
	printf("reached till her -- 1 testing biju\n");
   if ( APL_SUCCESS == CO_ChkErr(l_debug_info_ptr) )
   {
		printf("Failed in DL_Proc_MultReasPopulate\n");
		
      APL_GOBACK_FAIL
   }

	*p_snd_msg=h_send_msg_ind;
	printf("reached till her --  2 testing biju\n");
	
	APL_FREE(h_multreas_struct);
	printf("reached till her --  3 testing biju\n");

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_MultReasPopulate \n",NULL,NULL);
        return 1;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_MultReasPopulate \n",NULL,NULL);
        return 0;
}



int Populate_DL_DEALREPAIR(DL_DEALREPAIR_STRUCT_H *p_dl_dealrepair_struct_h,char * p_param_data)
{
	char l_cpclt[65] = APL_NULL_STRING; /* JC - ISKB_532 */
	   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

		   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataInt(p_param_data,"TRDREPSEQNUM",(int *) &(p_dl_dealrepair_struct_h -> h_dl_rep_identno));	
    CO_Rtv_DataString(p_param_data,"DL_CLIENT",(char *)p_dl_dealrepair_struct_h -> h_client);
    CO_Rtv_DataString(p_param_data,"DL_REF_NO",(char *)p_dl_dealrepair_struct_h -> h_identiy_no);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_dealrepair_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_dealrepair_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_dealrepair_struct_h -> h_setl_date);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_dealrepair_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"SECURITY_CD",p_dl_dealrepair_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CURRENCY_CD",p_dl_dealrepair_struct_h -> h_currency_cd);
	/* Commented by JC - ISKB_532
	CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT",p_dl_dealrepair_struct_h -> h_domestic_cpclt);
        */
        /* JC - ISKB_532 - Start */
        CO_Rtv_DataString(p_param_data,"DOMESTIC_CPCLT", l_cpclt);
        if(strlen(l_cpclt) > 10)
        {
                printf("JC::: CPCLT > 10\n");
                strncpy(p_dl_dealrepair_struct_h -> h_domestic_cpclt, l_cpclt, 10);
        }
        else
        {
                printf("JC::: CPCLT < 10\n");
                strcpy(p_dl_dealrepair_struct_h -> h_domestic_cpclt, l_cpclt);
        }
        /* JC - ISKB_532 - End */

	CO_Rtv_DataString(p_param_data,"DL_CLASS",p_dl_dealrepair_struct_h -> h_dl_class);
	CO_Rtv_DataDbl(p_param_data,"COST",&(p_dl_dealrepair_struct_h -> h_cost));
	CO_Rtv_DataString(p_param_data,"EX_ARENA",p_dl_dealrepair_struct_h -> h_ex_arena);
	CO_Rtv_DataString(p_param_data,"SPOTTRD_IND",p_dl_dealrepair_struct_h -> h_spottrd_ind);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_dealrepair_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"DATEOF_INPUT",p_dl_dealrepair_struct_h -> h_dateof_input);
	CO_Rtv_DataString(p_param_data,"CREATER",p_dl_dealrepair_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"CREATE_DT",p_dl_dealrepair_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"DEAL_STAT",p_dl_dealrepair_struct_h -> h_deal_stat);
	CO_Rtv_DataString(p_param_data,"ACCESSSTAMP",p_dl_dealrepair_struct_h -> h_access_stamp);
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
	CO_Rtv_DataString(p_param_data,"SEC_DET",p_dl_dealrepair_struct_h -> h_instr_name);
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
	/************************************* New Fields Added by Sundar - 090506**********************/

	CO_Rtv_DataString(p_param_data,"SETTLEMENT_NO",p_dl_dealrepair_struct_h-> h_settlement_no);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_dealrepair_struct_h-> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"CLH_FLG",p_dl_dealrepair_struct_h-> h_clh_flg);
	CO_Rtv_DataString(p_param_data,"PAYIN_DT",p_dl_dealrepair_struct_h-> h_payin_dt);
	CO_Rtv_DataString(p_param_data,"PAYOUT_DT",p_dl_dealrepair_struct_h-> h_payout_dt);
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_dl_dealrepair_struct_h-> h_exch_code);
	CO_Rtv_DataString(p_param_data,"INTERFII_FLG",p_dl_dealrepair_struct_h-> h_interfii_flg);
	CO_Rtv_DataString(p_param_data,"INSTR_CD",(char *)p_dl_dealrepair_struct_h->h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"NET_AMT",&(p_dl_dealrepair_struct_h-> h_net_amt));
	/************************************* New Fields Added by Sundar - 090506**********************/
	/*Retro from HDFC by Ekta for Interoperability Starts*/
	CO_Rtv_DataString(p_param_data,"TRD_EXCH",p_dl_dealrepair_struct_h-> h_trd_exch);
	CO_Rtv_DataString(p_param_data,"TRD_SETL_NO",p_dl_dealrepair_struct_h-> h_trd_setl_no);
	CO_Rtv_DataString(p_param_data,"TRD_MKT_TYPE",p_dl_dealrepair_struct_h-> h_trd_mkt_type);
	/*Retro from HDFC by Ekta for Interoperability Ends*/
	/* Added by Shradha for Stamp Duty Enh - Starts */
	CO_Rtv_DataDbl(p_param_data,"STAMP_DUTY",&(p_dl_dealrepair_struct_h->h_stamp_duty));
	/* Added by Shradha for Stamp Duty Enh - Ends */
}
/*
 int CPopulateDfCommonMsgrptStruct(char * p_misinfo, DF_COMMON_MSGRPT_STRUCT_H *p_df_common_msgrptStruct)
 {
 	
    void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
    void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value); 
    void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
    CO_Rtv_DataString(p_misinfo,"CLIENT",(char *)p_df_common_msgrptStruct->h_account);
    CO_Rtv_DataString(p_misinfo,"IDENTIY_NO",(char *)p_df_common_msgrptStruct->h_ref_no);
    
    CO_Rtv_DataString(p_misinfo,"SECURITY_CD",(char *)p_df_common_msgrptStruct->h_secode);
    CO_Rtv_DataString(p_misinfo,"MSG_NAME",(char *)p_df_common_msgrptStruct->h_msg_no);
 
    CO_Rtv_DataString(p_misinfo,"COMMON_DT",(char *)p_df_common_msgrptStruct->h_received_on);
    CO_Rtv_DataString(p_misinfo,"MSG_FUNC",(char *)p_df_common_msgrptStruct->h_msg_func);
    CO_Rtv_DataString(p_misinfo,"NAMEOF_FILE",(char *)p_df_common_msgrptStruct->h_file_name);
   
    
    strcpy(p_df_common_msgrptStruct->h_rep_flg , "N");
    CO_Rtv_DataString(p_misinfo,"REC_FROM_SENT_TO",(char *)p_df_common_msgrptStruct->h_rec_from_sent_to);
    CO_Rtv_DataString(p_misinfo,"SWIFT_MSG_IDENT",(char *)p_df_common_msgrptStruct->h_msg_refno);
    CO_Rtv_DataString(p_misinfo,"EVENT_TYPE",(char *)p_df_common_msgrptStruct->h_event_type);
 
    if( (strcmp(p_df_common_msgrptStruct->h_msg_no,"540")==0) || (strcmp(p_df_common_msgrptStruct->h_msg_no,"541")==0) || (strcmp(p_df_common_msgrptStruct->h_msg_no,"542")==0)|| (strcmp(p_df_common_msgrptStruct->h_msg_no,"543")==0))
 		strcpy(p_df_common_msgrptStruct->h_in_out,"I");
 			else
 		strcpy(p_df_common_msgrptStruct->h_in_out,"X");
 		
 	 APL_GOBACK_SUCCESS
 
 RETURN_SUCCESS:
 
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CPopulateCmsglinkStruct \n",NULL,NULL);
         return APL_SUCCESS;
 
 RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CPopulateCmsglinkStruct \n",NULL,NULL);
         return APL_FAILURE;
 
 }
*/


int CPopulateDfCommonMsgrptStruct(char * p_misinfo, DF_COMMON_MSGRPT_STRUCT_H *p_df_common_msgrptStruct)
{

	char l_char_msg_no[4] = APL_NULL_STRING;
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_misinfo,"CLIENT",(char *)p_df_common_msgrptStruct->h_account);
	CO_Rtv_DataString(p_misinfo,"IDENTIY_NO",(char *)p_df_common_msgrptStruct->h_ref_no);

	CO_Rtv_DataString(p_misinfo,"SECURITY_CD",(char *)p_df_common_msgrptStruct->h_secode);
	CO_Rtv_DataString(p_misinfo,"MSG_NAME",(char *)p_df_common_msgrptStruct->h_msg_no);

	CO_Rtv_DataString(p_misinfo,"COMMON_DT",(char *)p_df_common_msgrptStruct->h_received_on);
	CO_Rtv_DataString(p_misinfo,"MSG_FUNC",(char *)p_df_common_msgrptStruct->h_msg_func);
	CO_Rtv_DataString(p_misinfo,"NAMEOF_FILE",(char *)p_df_common_msgrptStruct->h_file_name);
	CO_Rtv_DataString(p_misinfo,"MSG_REFNO",(char *)p_df_common_msgrptStruct->h_msg_refno);
	strncpy(l_char_msg_no,p_df_common_msgrptStruct->h_msg_no,3);
	memset(p_df_common_msgrptStruct->h_msg_no,NULL,sizeof(p_df_common_msgrptStruct->h_msg_no));
	strcpy(p_df_common_msgrptStruct->h_msg_no,l_char_msg_no);


	strcpy(p_df_common_msgrptStruct->h_rep_flg , "N");
	CO_Rtv_DataString(p_misinfo,"REC_FROM_SENT_TO",(char *)p_df_common_msgrptStruct->h_rec_from_sent_to);
	/*
	 *     CO_Rtv_DataString(p_misinfo,"SWIFT_MSG_IDENT",(char *)p_df_common_msgrptStruct->h_msg_refno);
	 *         CO_Rtv_DataString(p_misinfo,"EVENT_TYPE",(char *)p_df_common_msgrptStruct->h_event_type);
	 *             */

	if( (strcmp(p_df_common_msgrptStruct->h_msg_no,"540")==0) || (strcmp(p_df_common_msgrptStruct->h_msg_no,"541")==0) || (strcmp(p_df_common_msgrptStruct->h_msg_no,"542")==0)|| (strcmp(p_df_common_msgrptStruct->h_msg_no,"543")==0))
	{
		strcpy(p_df_common_msgrptStruct->h_in_out,"I");
	}
	else
	{
		strcpy(p_df_common_msgrptStruct->h_in_out,"X");
	}

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CPopulateCmsglinkStruct \n",NULL,NULL);
	return APL_SUCCESS;

	RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CPopulateCmsglinkStruct \n",NULL,NULL);
	return APL_FAILURE;

}
 int CPopulateCmsglinkStruct(char **p_misinfo, DL_MSGLINK_STRUCT_H *p_cmsglinkStruct)
 {
 	
    void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
    void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value); 
    void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
    
    
    CO_Rtv_DataString(*p_misinfo,"CLIENT",(char *)p_cmsglinkStruct->h_dl_client);
    
    if (!strlen(p_cmsglinkStruct->h_dl_client))
    {
    	strcpy(p_cmsglinkStruct->h_dl_client,APL_NULL_STRING);
    }
    
    CO_Rtv_DataString(p_misinfo,"IDENTIY_NO",(char *)p_cmsglinkStruct->h_indentity_no);
    
    if (!strlen(p_cmsglinkStruct->h_indentity_no))
    	strcpy(p_cmsglinkStruct->h_indentity_no,APL_NULL_STRING);
 
    CO_Rtv_DataString(p_misinfo,"MSG_NAME", (char *)p_cmsglinkStruct->h_swift_msg_no);
    p_cmsglinkStruct->h_swift_msg_no[3]=APL_NULL_CHAR;	
 
    CO_Rtv_DataString(p_misinfo,"COMMON_DT",(char *)p_cmsglinkStruct->h_new_dt);
    
     printf("p_cmsglinkStruct->h_swift_msg_no = %s \n",p_cmsglinkStruct->h_swift_msg_no);
 	if( (strcmp(p_cmsglinkStruct->h_swift_msg_no,"540")==0) || (strcmp(p_cmsglinkStruct->h_swift_msg_no,"541")==0) || (strcmp(p_cmsglinkStruct->h_swift_msg_no,"542")==0)|| (strcmp(p_cmsglinkStruct->h_swift_msg_no,"543")==0)) 
    		strcpy(p_cmsglinkStruct->h_msg_in_out_ind,"I");
 	else
 		strcpy(p_cmsglinkStruct->h_msg_in_out_ind,"X");
    
    CO_Rtv_DataString(p_misinfo,"PSETPARTY" ,(char *)p_cmsglinkStruct->h_psetparty);
 
    CO_Rtv_DataString(p_misinfo,"PLACE_CD",(char *)p_cmsglinkStruct->h_place_cd);
    CO_Rtv_DataString(p_misinfo,"DETAIL",(char *)p_cmsglinkStruct->h_description);
 
 
 
 	APL_GOBACK_SUCCESS
 RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CPopulateCmsglinkStruct \n",NULL,NULL);
         return APL_SUCCESS;
 
 RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CPopulateCmsglinkStruct \n",NULL,NULL);
         return APL_FAILURE;
 
 }
 
 
 int CPopulateCmsglinkdetStruct(char *p_misinfo , DL_MSGLINKDET_STRUCT_H *p_cmsglinkdetStruct)
 {
 	
    void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
    void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value); 
    void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
    CO_Rtv_DataString(p_misinfo,"SEQUENCE_NAME",(char *)p_cmsglinkdetStruct->h_sequence_name);
    if (!strlen(p_cmsglinkdetStruct->h_sequence_name))
    strcpy(p_cmsglinkdetStruct->h_sequence_name,APL_NULL_STRING);
 
    CO_Rtv_DataString(p_misinfo,"LINK_VAL",(char *)p_cmsglinkdetStruct->h_link_val);
    CO_Rtv_DataString(p_misinfo,"LINK_TAG",(char *)p_cmsglinkdetStruct->h_link_msg_tag);
    CO_Rtv_DataString(p_misinfo,"MSG_TAG",(char *)p_cmsglinkdetStruct->h_msg_tag);
    
    if (!strlen(p_cmsglinkdetStruct->h_msg_tag))
    strcpy(p_cmsglinkdetStruct->h_msg_tag,APL_NULL_STRING);
    
    
    p_cmsglinkdetStruct->h_msg_line_no = 0;
    
    
    p_cmsglinkdetStruct->h_msg_tag_rep_no = 0;
    
    APL_GOBACK_SUCCESS 
  
 RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CPopulateCmsglinkdetStruct \n",NULL,NULL);
         return APL_SUCCESS;
 
 RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CPopulateCmsglinkdetStruct \n",NULL,NULL);
         return APL_FAILURE;
 
 }


int Populate_DL_BIFDET(DL_BIFDET_STRUCT_H *p_dl_bifdet_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"DL_CLIENT",p_dl_bifdet_struct_h -> h_client);
	CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_dl_bifdet_struct_h -> h_identiy_no);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_bifdet_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"DP_ID",p_dl_bifdet_struct_h -> h_dp_id);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_bifdet_struct_h -> h_access_stamp);
}


int Populate_DL_BCN(DL_BCN_STRUCT_H *p_dl_bcn_struct_h,char * p_param_data)
{
	   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
			   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"CONTRACT_CD",p_dl_bcn_struct_h -> h_contract_cd);
	CO_Rtv_DataString(p_param_data,"OFF_MARKET",p_dl_bcn_struct_h -> h_off_market);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_bcn_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"TRAN_TYPE",p_dl_bcn_struct_h -> h_tran_type);
	CO_Rtv_DataString(p_param_data,"DL_DATE",p_dl_bcn_struct_h -> h_dl_date);
	CO_Rtv_DataDbl(p_param_data,"DL_PRICE",&(p_dl_bcn_struct_h -> h_dl_price));
	CO_Rtv_DataDbl(p_param_data,"BROKERCOMM",&(p_dl_bcn_struct_h -> h_brokercomm));
	CO_Rtv_DataString(p_param_data,"EXCH_CD",p_dl_bcn_struct_h -> h_exch_cd);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_bcn_struct_h -> h_deal_cd);
	CO_Rtv_DataString(p_param_data,"CLH_FLG",p_dl_bcn_struct_h -> h_clh_flg);
	CO_Rtv_DataString(p_param_data,"SEBI_REG_NO",p_dl_bcn_struct_h -> h_sebi_reg_no);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_dl_bcn_struct_h -> h_broker_cd);
	CO_Rtv_DataString(p_param_data,"CLIENT_CD",p_dl_bcn_struct_h -> h_client_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_bcn_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"INSTR_CD",p_dl_bcn_struct_h -> h_instr_cd);
	CO_Rtv_DataString(p_param_data,"SETTLEMENT_NO",p_dl_bcn_struct_h -> h_settlement_no);
	CO_Rtv_DataDbl(p_param_data,"DL_AMT",&(p_dl_bcn_struct_h -> h_dl_amt));
	CO_Rtv_DataDbl(p_param_data,"BROKERAGE_AMT",&(p_dl_bcn_struct_h -> h_brokerage_amt));
	CO_Rtv_DataDbl(p_param_data,"STT_AMT",&(p_dl_bcn_struct_h -> h_stt_amt));
	CO_Rtv_DataDbl(p_param_data,"SETTLMENT_AMT",&(p_dl_bcn_struct_h -> h_settlment_amt));
	CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_dl_bcn_struct_h -> h_dl_ref_no);
	CO_Rtv_DataString(p_param_data,"INTER_FII_FLG",p_dl_bcn_struct_h -> h_inter_fii_flg);
	CO_Rtv_DataString(p_param_data,"COUNTER_PTY",p_dl_bcn_struct_h -> h_counter_pty);
	CO_Rtv_DataString(p_param_data,"SEBI_REPORTED",p_dl_bcn_struct_h -> h_sebi_reported);
	CO_Rtv_DataString(p_param_data,"ENTRY",p_dl_bcn_struct_h -> h_entry);
	CO_Rtv_DataString(p_param_data,"REPAIRED_IND",p_dl_bcn_struct_h -> h_repaired_ind);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_bcn_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_bcn_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_bcn_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_bcn_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_bcn_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_dl_bcn_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"SETT_DT",p_dl_bcn_struct_h -> h_sett_dt);
	CO_Rtv_DataString(p_param_data,"NARRATIVE",p_dl_bcn_struct_h -> h_narrative);
	CO_Rtv_DataString(p_param_data,"R_TRANS_CODE",p_dl_bcn_struct_h -> h_r_trans_code);
	CO_Rtv_DataString(p_param_data,"R_SETT_CODE",p_dl_bcn_struct_h -> h_r_sett_code);
	CO_Rtv_DataString(p_param_data,"R_DELAY",p_dl_bcn_struct_h -> h_r_delay);
	CO_Rtv_DataString(p_param_data,"R_TYPE",p_dl_bcn_struct_h -> h_r_type);
	CO_Rtv_DataString(p_param_data,"REPO_DATE",p_dl_bcn_struct_h -> h_repo_date);
	CO_Rtv_DataString(p_param_data,"AMEND_DT",p_dl_bcn_struct_h -> h_ammend_dt);
	/* Added by Veda*/
	CO_Rtv_DataString(p_param_data,"ADDR_FRM",p_dl_bcn_struct_h -> h_addr_frm);
	CO_Rtv_DataString(p_param_data,"ADDR_TO",p_dl_bcn_struct_h -> h_addr_to);
	/* Added by Veda*/
	/* Added by Shradha for Stamp Duty - Starts */
	CO_Rtv_DataDbl(p_param_data,"STAMP_DUTY",&(p_dl_bcn_struct_h -> h_stamp_duty));
	/* Added by Shradha for Stamp Duty - Ends */
}

/*************************TAKE OVER*****************************/
int Populate_DL_TAKEOVER(DL_TAKEOVER_STRUCT_H *p_dl_takeover_struct_h,char *p_param_data)
{   
		printf("enterin populate struct of takeover %s\n",p_param_data);
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		  void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

		CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",(char *)p_dl_takeover_struct_h -> h_accesstamp);
		CO_Rtv_DataString(p_param_data,"SERIAL_NO",(char *)p_dl_takeover_struct_h->h_serial_no);
	   printf("\n serial no is |%d|",p_dl_takeover_struct_h->h_serial_no );
		CO_Rtv_DataString(p_param_data,"REF_NO",(char *)p_dl_takeover_struct_h -> h_ref_no);
	   CO_Rtv_DataString(p_param_data,"CI_NO",(char *)p_dl_takeover_struct_h -> h_ci_no);
		
		CO_Rtv_DataString(p_param_data,"INSTR_CD",(char *)p_dl_takeover_struct_h -> h_instr_cd);
		CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_takeover_struct_h -> h_qty));
		CO_Rtv_DataString(p_param_data,"PHY_FLG",(char *)p_dl_takeover_struct_h -> h_phy_flg);	
		CO_Rtv_DataDbl(p_param_data,"TAKEOVER_QTY",&(p_dl_takeover_struct_h -> h_takeover_qty));
		CO_Rtv_DataString(p_param_data,"DEPOSITORY",(char *)p_dl_takeover_struct_h -> h_depository);
		CO_Rtv_DataString(p_param_data,"STATUS",(char *)p_dl_takeover_struct_h -> h_status);
		CO_Rtv_DataString(p_param_data,"COMMENTS",(char *)p_dl_takeover_struct_h -> h_comments);
		CO_Rtv_DataString(p_param_data,"MAKER",(char *)p_dl_takeover_struct_h -> h_maker);
		CO_Rtv_DataString(p_param_data,"MAKERDT",(char *)p_dl_takeover_struct_h -> h_makerdt);
		CO_Rtv_DataString(p_param_data,"CHECKER",(char *)p_dl_takeover_struct_h -> h_checker);
		CO_Rtv_DataString(p_param_data,"CHECKERDT",(char *)p_dl_takeover_struct_h -> h_checkerdt); 
		/*
		CO_Rtv_DataString(p_param_data,"COMMENTS",(char *)p_dl_takeover_struct_h -> h_comments);		 
		*/
	   printf("\n  to test comment  is |%s|",p_dl_takeover_struct_h->h_comments );	

	   RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_TAKEOVER \n",NULL,NULL);
        return 0;

		RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_TAKEOVER \n",NULL,NULL);
        return 1;
} 
int Populate_DL_TAKEOVER_SEQ(DL_TAKEOVER_SEQ_STRUCT_H *p_dl_takeover_seq_struct_h,char *p_param_data)
{
		
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		CO_Rtv_DataString(p_param_data,"REF_NO",(char *)p_dl_takeover_seq_struct_h->h_ref_no);
		CO_Rtv_DataString(p_param_data,"CLN_CODE",(char *)p_dl_takeover_seq_struct_h->h_cln_code);
		CO_Rtv_DataString(p_param_data,"TAKEOVER_DATE",(char *)p_dl_takeover_seq_struct_h->h_takeover_date);
        CO_Rtv_DataString(p_param_data,"TAKEOVER_COMMENTS",(char *)p_dl_takeover_seq_struct_h->h_takeover_comments);  		

		RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_TAKEOVER_SEQ\n",NULL,NULL);
        return 0;

		RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_TAKEOVER_SEQ \n",NULL,NULL);
        return 1;

}


/***********************MARK SHORTAGE***********************************/
int Populate_DL_MARKSHORTAGE(DL_MARKSHORTAGE_STRUCT_H *p_dl_markshortage_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
/* changes by amish --25/05 */	 

	CO_Rtv_DataString(p_param_data,"SETTLEMENT_NO",(char *)p_dl_markshortage_struct_h -> h_settlement_no);
	CO_Rtv_DataString(p_param_data,"DL_CLIENT",(char *)p_dl_markshortage_struct_h -> h_dl_client);
	CO_Rtv_DataString(p_param_data,"DL_REF_NO",(char *)p_dl_markshortage_struct_h -> h_dl_ref_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",(char *)p_dl_markshortage_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_markshortage_struct_h -> h_qty));
	CO_Rtv_DataDbl(p_param_data,"AVAIL_QTY",&(p_dl_markshortage_struct_h -> h_avail_qty));
	CO_Rtv_DataDbl(p_param_data,"ALLOT_QTY",&(p_dl_markshortage_struct_h -> h_allot_qty));
	CO_Rtv_DataDbl(p_param_data,"SHORTAGE_QTY",&(p_dl_markshortage_struct_h -> h_shortage_qty));
	CO_Rtv_DataString(p_param_data,"POOL_TRANS",(char *)p_dl_markshortage_struct_h -> h_pool_trans);
	CO_Rtv_DataString(p_param_data,"STATUS",(char *)p_dl_markshortage_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",(char *)p_dl_markshortage_struct_h -> h_access_stamp);
	CO_Rtv_DataInt(p_param_data,"FILEBATCH_NO",(int *)&(p_dl_markshortage_struct_h ->h_filebatch_no));
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",(char *)p_dl_markshortage_struct_h -> h_mkt_type);//T1 Settlement changes CS0083803
 /* changes by amish --25/05 */
 	
	
	RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_MARKSHORTAGE \n",NULL,NULL);
        return 0;

	RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_MARKSHORTAGE \n",NULL,NULL);
        return 1;
}


/* HDFCDL_015 DL_SQOFF Table Populate structure - Sundar */

int Populate_DL_SQOFF(DL_SQOFF_STRUCT_H *p_dl_sqoff_struct_h,char *p_param_data)
{
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_dl_sqoff_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"SETTLEMT_NO",p_dl_sqoff_struct_h -> h_settlemt_no);
	CO_Rtv_DataString(p_param_data,"PAYIN_DT",p_dl_sqoff_struct_h -> h_payin_dt);
	CO_Rtv_DataString(p_param_data,"PAYOUT_DT",p_dl_sqoff_struct_h -> h_payout_dt);
	CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_dl_sqoff_struct_h -> h_dl_ref_no);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_dl_sqoff_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"SQOFF_REF_NO",p_dl_sqoff_struct_h -> h_sqoff_ref_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_sqoff_struct_h -> h_instr_code);
	CO_Rtv_DataDbl(p_param_data,"DEAL_QTY",&(p_dl_sqoff_struct_h -> h_deal_qty));
	CO_Rtv_DataDbl(p_param_data,"BAL_QTY",&(p_dl_sqoff_struct_h -> h_bal_qty));
	CO_Rtv_DataDbl(p_param_data,"SQOFF_QTY",&(p_dl_sqoff_struct_h -> h_sqoff_qty));
	CO_Rtv_DataDbl(p_param_data,"SQOFF_AMT",&(p_dl_sqoff_struct_h -> h_sqoff_amt));
	CO_Rtv_DataString(p_param_data,"BANK_CODE",p_dl_sqoff_struct_h -> h_bank_code);
	CO_Rtv_DataString(p_param_data,"CHQ_NO",p_dl_sqoff_struct_h -> h_chq_no);
	CO_Rtv_DataString(p_param_data,"CHQ_DT",p_dl_sqoff_struct_h -> h_chq_dt);
	CO_Rtv_DataDbl(p_param_data,"PRN_AMT",&(p_dl_sqoff_struct_h -> h_prn_amt));
	CO_Rtv_DataString(p_param_data,"CA_REF_NO",p_dl_sqoff_struct_h -> h_ca_ref_no);
	CO_Rtv_DataDbl(p_param_data,"CA_AMT",&(p_dl_sqoff_struct_h -> h_ca_amt));
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_sqoff_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_sqoff_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_sqoff_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_sqoff_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_sqoff_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS",p_dl_sqoff_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"DEAL_CD",p_dl_sqoff_struct_h -> h_deal_cd);
/* changes by amish --24/05 */
	
	RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_SQOFF\n",NULL,NULL);
        return 0;

	RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_SQOFF\n",NULL,NULL);
        return 1;
}

int Populate_DL_EXCHGORD_UPLD(DL_EXCHGORD_UPLD_STRUCT_H *p_dl_exchgord_upld_struct_h,char * p_param_data)
{
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	CO_Rtv_DataString(p_param_data,"ORDER_NO",p_dl_exchgord_upld_struct_h -> h_order_no);
	CO_Rtv_DataString(p_param_data,"EXCHG_CODE",p_dl_exchgord_upld_struct_h -> h_exchg_code);
	CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_exchgord_upld_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_exchgord_upld_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"BROKER_CD",p_dl_exchgord_upld_struct_h -> h_broker_cd);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_exchgord_upld_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"SETTL_NO",p_dl_exchgord_upld_struct_h -> h_settl_no);
	CO_Rtv_DataDbl(p_param_data,"DL_PRICE",&(p_dl_exchgord_upld_struct_h -> h_dl_price));
	CO_Rtv_DataDbl(p_param_data,"DL_AMT",&(p_dl_exchgord_upld_struct_h -> h_dl_amt));
	CO_Rtv_DataString(p_param_data,"DEAL_DATE",p_dl_exchgord_upld_struct_h -> h_deal_date);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_exchgord_upld_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"SCRIP_GRP",p_dl_exchgord_upld_struct_h -> h_scrip_grp);
	CO_Rtv_DataString(p_param_data,"CREATION_TYPE",p_dl_exchgord_upld_struct_h -> h_creation_type);
	CO_Rtv_DataString(p_param_data,"DEAL_REF_NO",p_dl_exchgord_upld_struct_h -> h_deal_ref_no);
	CO_Rtv_DataString(p_param_data,"BUY_SELL_FLG",p_dl_exchgord_upld_struct_h -> h_buy_sell_flg);
	CO_Rtv_DataString(p_param_data,"MATCHED",p_dl_exchgord_upld_struct_h -> h_matched);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_exchgord_upld_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS",p_dl_exchgord_upld_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_exchgord_upld_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_exchgord_upld_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_exchgord_upld_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_exchgord_upld_struct_h -> h_checker_dt);
	CO_Rtv_DataInt(p_param_data,"FILELINKINFO",&(p_dl_exchgord_upld_struct_h -> h_filelinkinfo));
	CO_Rtv_DataInt(p_param_data,"ROWSEQUENCE",&(p_dl_exchgord_upld_struct_h -> h_rowsequence));
	CO_Rtv_DataString(p_param_data,"IS_NODELV",p_dl_exchgord_upld_struct_h -> h_is_nodelv);/* vinay */
	CO_Rtv_DataString(p_param_data,"NODELV_REPDATE",p_dl_exchgord_upld_struct_h -> h_nodelv_repdate);
	CO_Rtv_DataString(p_param_data,"ORDER_DATA",p_dl_exchgord_upld_struct_h -> h_order_data);
	CO_Rtv_DataString(p_param_data,"EXCH_INSTR_CODE",p_dl_exchgord_upld_struct_h -> h_exch_instr_code);/*Rahul*/
	CO_Rtv_DataString(p_param_data,"CP_CODE",p_dl_exchgord_upld_struct_h -> h_cp_code); /* Chages by rahul6 */

RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_EXCHGORD_UPLD \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_EXCHGORD_UPLD \n",NULL,NULL);
        return 1;
}


int Populate_DL_DPGEN_DET(DL_DPGEN_DET_STRUCT_H *p_dl_dpgen_det_struct_h,char * p_param_data)
{
	printf("\nentering Populate_DL_DPGEN_DET\n");
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	printf("\nCHK AMISH---PARAM STRING IS |%s|\n",p_param_data);


	char l_refno1[17] = APL_NULL_STRING;
	char l_refno2[17] = APL_NULL_STRING;


	printf("\n Retrieving DL_REF_NO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
 CO_Rtv_DataString(p_param_data,"DL_REF_NO",(char *)l_refno1);
 printf("\n Retrieving NEWREFNO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
 CO_Rtv_DataString(p_param_data,"NEWREFNO",(char *)l_refno2);
 printf("\n After Retrieving NEWREFNO : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
 if (strlen(l_refno2) != 0)
	{
		printf("\n Inside If : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
		strcpy(p_dl_dpgen_det_struct_h->h_dl_ref_no,l_refno2);
	}
	else
	{
		printf("\n Inside Else : l_refno1=|%s|, l_refno2=|%s|",l_refno1,l_refno2);
		strcpy(p_dl_dpgen_det_struct_h->h_dl_ref_no,l_refno1);
	}

	printf("\n After All : l_refno1=|%s|, l_refno2=|%s|,p_dl_dpgen_det_struct_h->h_dl_ref_no=|%s|",l_refno1,l_refno2,p_dl_dpgen_det_struct_h->h_dl_ref_no);

	
	CO_Rtv_DataString(p_param_data,"DL_CLIENT",p_dl_dpgen_det_struct_h->h_dl_client);
	
	printf("client is |%s|\n",p_dl_dpgen_det_struct_h -> h_dl_client);
	
/*	CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_dl_dpgen_det_struct_h->h_dl_ref_no);*/
	
	CO_Rtv_DataString(p_param_data,"BROK_DP_ID",p_dl_dpgen_det_struct_h -> h_broker_dpid);
	CO_Rtv_DataString(p_param_data,"BROK_CMBP_ID",p_dl_dpgen_det_struct_h -> h_broker_cmbpid);
	CO_Rtv_DataString(p_param_data,"CP_DPID",p_dl_dpgen_det_struct_h -> h_cp_dpid);
	CO_Rtv_DataString(p_param_data,"CP_CLNID",p_dl_dpgen_det_struct_h -> h_cp_clnid);
	
	CO_Rtv_DataString(p_param_data,"GENDP_FLG",p_dl_dpgen_det_struct_h -> h_gendp_flg);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_dpgen_det_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_dpgen_det_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_dpgen_det_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_dpgen_det_struct_h -> h_mkt_type);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_dpgen_det_struct_h -> h_qty));
	/* changes by amish --12/05 */
	CO_Rtv_DataString(p_param_data,"EXEC_DATE",p_dl_dpgen_det_struct_h -> h_exec_dt);

	RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_DPGEN_DET \n",NULL,NULL);
        return 0;

	RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_DPGEN_DET \n",NULL,NULL);
        return 1;

}

int Populate_DL_POOLACCRECS(DL_POOLACCRECS_STRUCT_H *p_dl_poolaccrecs_struct_h,char * p_param_data)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	/*CO_Rtv_DataInt(p_param_data,"SYSTEM_SEQ_NO",p_dl_poolaccrecs_struct_h-> h_system_seq_no);*/
	CO_Rtv_DataString(p_param_data,"FILE_BATCH_NO",p_dl_poolaccrecs_struct_h->h_file_batch_no);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_poolaccrecs_struct_h->h_instr_code);
	CO_Rtv_DataString(p_param_data,"BENEFACTYP",p_dl_poolaccrecs_struct_h->h_benefactyp);
	CO_Rtv_DataInt(p_param_data,"BENEF_ACCPOSN",&(p_dl_poolaccrecs_struct_h-> h_benef_accposn));
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_poolaccrecs_struct_h->h_mkt_type);
	CO_Rtv_DataString(p_param_data,"SETTLEMT_NO",p_dl_poolaccrecs_struct_h->h_settlemt_no);
	CO_Rtv_DataString(p_param_data,"BL_LC_CODE",p_dl_poolaccrecs_struct_h->h_bl_lc_code);
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_dl_poolaccrecs_struct_h->h_depo_code);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_poolaccrecs_struct_h-> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_poolaccrecs_struct_h-> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_poolaccrecs_struct_h-> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_poolaccrecs_struct_h-> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_poolaccrecs_struct_h-> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_dl_poolaccrecs_struct_h-> h_status);

RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_POOLACCRECS\n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_POOLACCRECS\n",NULL,NULL);
	return 1;
}


int Populate_DL_NSE_OBL(DL_NSC_OBL_STRUCT_H *p_dl_nse_obl_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	CO_Rtv_DataString(p_param_data,"OBGDAYBUYVOL",p_dl_nse_obl_struct_h->h_obgdaybuyvol );
	CO_Rtv_DataString(p_param_data,"OBGDAYSALVOL",p_dl_nse_obl_struct_h->h_obgdaysalvol );
	CO_Rtv_DataString(p_param_data,"OBGDAYBUYAMT",p_dl_nse_obl_struct_h->h_obgdaybuyamt );
	CO_Rtv_DataString(p_param_data,"OBGDAYSALAMT",p_dl_nse_obl_struct_h->h_obgdaysalamt );
	CO_Rtv_DataString(p_param_data,"OBGCUMBUYVOL",p_dl_nse_obl_struct_h->h_obgcumbuyvol );
	CO_Rtv_DataString(p_param_data,"OBGCUMSALVOL",p_dl_nse_obl_struct_h->h_obgcumsalvol );
	CO_Rtv_DataString(p_param_data,"OBGCUMBUYAMT",p_dl_nse_obl_struct_h->h_obgcumbuyamt );
	CO_Rtv_DataString(p_param_data,"OBGCUMSALAMT",p_dl_nse_obl_struct_h->h_obgcumsalamt );
	CO_Rtv_DataString(p_param_data,"OBGSETLNO",p_dl_nse_obl_struct_h->h_obgsetlno );
	CO_Rtv_DataString(p_param_data,"OBGTMBRNCODE",p_dl_nse_obl_struct_h->h_obgtmbrncode );
	CO_Rtv_DataString(p_param_data,"OBGDATE",p_dl_nse_obl_struct_h->h_obgdate );
	CO_Rtv_DataString(p_param_data,"OBGCUPCODE",p_dl_nse_obl_struct_h->h_obgcupcode );
	CO_Rtv_DataString(p_param_data,"OBGSECSYMBOL",p_dl_nse_obl_struct_h->h_obgsecsymbol );
	CO_Rtv_DataString(p_param_data,"OBGSECSERIES",p_dl_nse_obl_struct_h->h_obgsecseries );
	CO_Rtv_DataString(p_param_data,"OBGSECCODE",p_dl_nse_obl_struct_h->h_obgseccode );
	CO_Rtv_DataString(p_param_data,"OBGTMCODE",p_dl_nse_obl_struct_h->h_obgtmcode );
	CO_Rtv_DataString(p_param_data,"OBGCUSCODE",p_dl_nse_obl_struct_h->h_obgcuscode );
	CO_Rtv_DataString(p_param_data,"OBGSETLTYPE",p_dl_nse_obl_struct_h->h_obgsetltype );
	CO_Rtv_DataString(p_param_data,"OBGNDFLAG",p_dl_nse_obl_struct_h->h_obgndflag );
	CO_Rtv_DataString(p_param_data,"OBGFNLOBG",p_dl_nse_obl_struct_h->h_obgfnlobg );

RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_NSC_OBL \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_NSC_OBL \n",NULL,NULL);
	return 1;
}

int Populate_DL_INTR_SCH(DL_INTR_SCH_STRUCT_H *p_dl_intr_sch_struct_h,char * p_param_data)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

   CO_Rtv_DataString(p_param_data,"TRANSFER_REF_NO",p_dl_intr_sch_struct_h -> h_transfer_ref_no);
   CO_Rtv_DataString(p_param_data,"FROM_CLIENT",p_dl_intr_sch_struct_h -> h_from_client);
   CO_Rtv_DataString(p_param_data,"TO_CLIENT",p_dl_intr_sch_struct_h -> h_to_client);
   CO_Rtv_DataString(p_param_data,"CUSTODY_INTERNAL",p_dl_intr_sch_struct_h -> h_custody_internal);
   CO_Rtv_DataString(p_param_data,"CP_CUSTO",p_dl_intr_sch_struct_h -> h_cp_custo);
   CO_Rtv_DataString(p_param_data,"CP_DP_ID",p_dl_intr_sch_struct_h -> h_cp_dp_id);
   CO_Rtv_DataString(p_param_data,"CP_CLIENT_ID",p_dl_intr_sch_struct_h -> h_cp_client_id);
   CO_Rtv_DataString(p_param_data,"STATUS",p_dl_intr_sch_struct_h -> h_status);
   CO_Rtv_DataString(p_param_data,"MAKER",p_dl_intr_sch_struct_h -> h_maker);
   CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_intr_sch_struct_h -> h_maker_dt);
   CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_intr_sch_struct_h -> h_access_stamp);
   CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_intr_sch_struct_h -> h_checker);
   CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_intr_sch_struct_h -> h_checker_dt);

RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_INTR_SCH \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_INTR_SCH \n",NULL,NULL);
        return 1;
}

int Populate_DL_INTR_SCH_DET(DL_INTR_SCH_DET_STRUCT_H *p_dl_intr_sch_det_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   CO_Rtv_DataString(p_param_data,"TRANSFER_REF_NO",p_dl_intr_sch_det_struct_h -> h_transfer_ref_no);
   CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_intr_sch_det_struct_h -> h_instr_code);
   CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_dl_intr_sch_det_struct_h -> h_depo_code);
   CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_intr_sch_det_struct_h -> h_qty));
   CO_Rtv_DataDbl(p_param_data,"BAL_QTY",&(p_dl_intr_sch_det_struct_h -> h_bal_qty));
   CO_Rtv_DataString(p_param_data,"TRANSFER_DT",p_dl_intr_sch_det_struct_h -> h_transfer_dt);
   CO_Rtv_DataString(p_param_data,"STATUS",p_dl_intr_sch_det_struct_h -> h_status);
   CO_Rtv_DataString(p_param_data,"MAKER",p_dl_intr_sch_det_struct_h -> h_maker);
   CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_intr_sch_det_struct_h -> h_maker_dt);
   CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_intr_sch_det_struct_h -> h_access_stamp);
   CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_intr_sch_det_struct_h -> h_checker);
   CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_intr_sch_det_struct_h -> h_checker_dt);


RETURN_SUCCESS:
   CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_INTR_SCH_DET \n",NULL,NULL);
   return 0;

RETURN_FAILURE:
   CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_INTR_SCH_DET \n",NULL,NULL);
   return 1;
}

int Populate_DL_BLK_SEC_DET(DL_BLK_SEC_DET_STRUCT_H *p_dl_blk_sec_det_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   CO_Rtv_DataString(p_param_data,"BLK_REF_NO",p_dl_blk_sec_det_struct_h -> h_blk_ref_no);
   CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_blk_sec_det_struct_h -> h_instr_code);
   CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_dl_blk_sec_det_struct_h -> h_depo_code);
   CO_Rtv_DataString(p_param_data,"BLK_DATE",p_dl_blk_sec_det_struct_h -> h_blk_date);
   CO_Rtv_DataString(p_param_data,"BLK_TYPE",p_dl_blk_sec_det_struct_h -> h_blk_type);
   CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_blk_sec_det_struct_h -> h_qty));
   CO_Rtv_DataDbl(p_param_data,"BAL_QTY",&(p_dl_blk_sec_det_struct_h -> h_bal_qty));
   CO_Rtv_DataString(p_param_data,"UN_BLK_DATE",p_dl_blk_sec_det_struct_h -> h_un_blk_date);
   CO_Rtv_DataDbl(p_param_data,"UN_BLK_QTY",&(p_dl_blk_sec_det_struct_h -> h_un_blk_qty));
   CO_Rtv_DataString(p_param_data,"CUSTO_REF_NO",p_dl_blk_sec_det_struct_h -> h_custo_ref_no);
   CO_Rtv_DataString(p_param_data,"STATUS",p_dl_blk_sec_det_struct_h -> h_status);
   CO_Rtv_DataString(p_param_data,"MAKER",p_dl_blk_sec_det_struct_h -> h_maker);
   CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_blk_sec_det_struct_h -> h_maker_dt);
   CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_blk_sec_det_struct_h -> h_access_stamp);
   CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_blk_sec_det_struct_h -> h_checker);
   CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_blk_sec_det_struct_h -> h_checker_dt);
}

int Populate_DL_BLK_SEC(DL_BLK_SEC_STRUCT_H *p_dl_blk_sec_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   CO_Rtv_DataString(p_param_data,"BLK_REF_NO",p_dl_blk_sec_struct_h -> h_blk_ref_no);
   CO_Rtv_DataString(p_param_data,"CLIENT",p_dl_blk_sec_struct_h -> h_client);
   CO_Rtv_DataString(p_param_data,"REMARKS",p_dl_blk_sec_struct_h -> h_remarks);
   CO_Rtv_DataString(p_param_data,"STATUS",p_dl_blk_sec_struct_h -> h_status);
   CO_Rtv_DataString(p_param_data,"MAKER",p_dl_blk_sec_struct_h -> h_maker);
   CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_blk_sec_struct_h -> h_maker_dt);
   CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_blk_sec_struct_h -> h_access_stamp);
   CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_blk_sec_struct_h -> h_checker);
   CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_blk_sec_struct_h -> h_checker_dt);
}


 /****************************Force Match ****************************/
 int Populate_FORCE_MATCHING(char *p_chr_deal,char *p_chr_order,char *p_param_data)
 {
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

    CO_Rtv_DataString(p_param_data,"DLD",p_chr_deal);
    CO_Rtv_DataString(p_param_data,"ORD",p_chr_order);


    printf("p_chr_deal%s\n",p_chr_deal);
    printf("p_chr_order%s\n",p_chr_order);

 RETURN_SUCCESS:
       CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_FORCE_MATCHING \n",NULL,NULL);
       return 0;

 RETURN_FAILURE:
       CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_FORCE_MATCHING \n",NULL,NULL);
       return 1;
 }
		
/**** vinay kalaskar HDFCDL_011 *****/

 int Populate_DL_POOLACCDMP(DL_POOLACCDMP_STRUCT_H *p_dl_poolaccdmp_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	CO_Rtv_DataInt(p_param_data,"SEQ_NO",(int *) &(p_dl_poolaccdmp_struct_h -> h_seq_no));
	CO_Rtv_DataInt(p_param_data,"FILEBATCH_NO",(int *) &(p_dl_poolaccdmp_struct_h -> h_filebatch_no));
	CO_Rtv_DataString(p_param_data,"BENEF_ACCTYPE",p_dl_poolaccdmp_struct_h -> h_benef_acctype);
	CO_Rtv_DataDbl(p_param_data,"QTY",&(p_dl_poolaccdmp_struct_h -> h_qty));
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_poolaccdmp_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"SETTLEMT_NO",p_dl_poolaccdmp_struct_h -> h_settlemt_no);
	CO_Rtv_DataString(p_param_data,"BL_LC_CODE",p_dl_poolaccdmp_struct_h -> h_bl_lc_code);
	CO_Rtv_DataString(p_param_data,"ICREL_DATE",p_dl_poolaccdmp_struct_h -> h_icrel_date);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_poolaccdmp_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"MAKER",p_dl_poolaccdmp_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_poolaccdmp_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_poolaccdmp_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_poolaccdmp_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_dl_poolaccdmp_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_poolaccdmp_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_dl_poolaccdmp_struct_h -> h_depo_code);
	CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_dl_poolaccdmp_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_data,"DP_ID",p_dl_poolaccdmp_struct_h -> h_dp_id);
	

RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_POOLACCDMP \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_POOLACCDMP \n",NULL,NULL);
	return 1;


}


int Populate_POOLACDET(POOLACDET_STRUCT_H *p_poolacdet_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  
	CO_Rtv_DataInt(p_param_data,"FILELINKINFO",(int *) &(p_poolacdet_struct_h -> h_filelinkinfo));
	CO_Rtv_DataString(p_param_data,"FILE_NAME",p_poolacdet_struct_h -> h_file_name);
	CO_Rtv_DataString(p_param_data,"UPLD_DATE",p_poolacdet_struct_h -> h_upld_date);
	CO_Rtv_DataString(p_param_data,"F_CODE",p_poolacdet_struct_h -> h_f_code);
	CO_Rtv_DataInt(p_param_data,"BATCH_NO",(int *) &(p_poolacdet_struct_h -> h_batch_no));


RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_POOLACDET \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_POOLACDET \n",NULL,NULL);
	return 1;

}

int   DL_Proc_DPInstPopulate(DL_UPDDPINST_STRUCT_H *p_dl_upddpinst_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

         /*Modified  by siva.ganapathi for ISKB_2495 on 26/10/2009 -- started*/
        printf("\n Siva Pram String is %s",chr_p_param_str);

//	CO_Rtv_DataInt(chr_p_param_str,"BATCH_NO",(int *) &(p_dl_upddpinst_struct_h ->h_batch_no));
	CO_Rtv_DataString(chr_p_param_str,"BATCH_NO",(char *)p_dl_upddpinst_struct_h ->h_batch_no);
        /*Modified  by siva.ganapathi for ISKB_2495 on 26/10/2009 -- Ended*/
	CO_Rtv_DataString(chr_p_param_str,"SERIAL_NO",(char *)p_dl_upddpinst_struct_h->h_serial_no);
	CO_Rtv_DataString(chr_p_param_str,"TRANS_TYPE",(char *)p_dl_upddpinst_struct_h->h_trans_type);
	CO_Rtv_DataString(chr_p_param_str,"TRANS_FLG",(char *)p_dl_upddpinst_struct_h->h_trans_flg);
	CO_Rtv_DataString(chr_p_param_str,"INTERNAL_REF_NO",(char *)p_dl_upddpinst_struct_h->h_internal_ref_no);
	/* CO_Rtv_DataInt(chr_p_param_str,"DPM_TRANS_NO",(int *) &(p_dl_upddpinst_struct_h ->h_dpm_trans_no)); 
	** Modified For ISKB_3298 Changes - Jun2010 - Naren V */

	CO_Rtv_DataLong(chr_p_param_str,"DPM_TRANS_NO",(long *) &(p_dl_upddpinst_struct_h ->h_dpm_trans_no));
	
 //printf("\n  In DL_Proc_DPInstPopulate() Batch number is %s",p_dl_upddpinst_struct_h ->h_batch_no);
 //printf("\n In DL_Proc_DPInstPopulate() internal reference nubmer is %s",p_dl_upddpinst_struct_h->h_internal_ref_no); 
 //printf("\n In DL_Proc_DPInstPopulate() DPM Trans nubmer is %d",p_dl_upddpinst_struct_h ->h_dpm_trans_no); 
	
RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DPInstPopulate \n",NULL,NULL);
	return 0;

RETURN_FAILURE:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DPInstPopulate \n",NULL,NULL);
	return 1;
	
}	

int   DL_Proc_CODPopulate(DL_INST_COD_STRUCT_H *p_dl_inst_cod_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	
	CO_Rtv_DataInt(chr_p_param_str,"RECORD_TYPE",(int *) &(p_dl_inst_cod_struct_h ->h_record_type));
   CO_Rtv_DataString(chr_p_param_str,"BRANCH_CD",(char *)p_dl_inst_cod_struct_h->h_branch_cd);
   CO_Rtv_DataInt(chr_p_param_str,"LINE_NO",(int *)&(p_dl_inst_cod_struct_h->h_line_no));
   CO_Rtv_DataString(chr_p_param_str,"TRANS_TYPE",(char *)p_dl_inst_cod_struct_h->h_trans_type);

   /* CO_Rtv_DataInt(chr_p_param_str,"DPM_TRANSACTION_NO",(int *) &(p_dl_inst_cod_struct_h ->h_dpm_transaction_no));
   ** Modified For ISKB_3298 Changes - Jun2010 - Naren V */

   CO_Rtv_DataLong(chr_p_param_str,"DPM_TRANSACTION_NO",(long *) &(p_dl_inst_cod_struct_h ->h_dpm_transaction_no));

   CO_Rtv_DataInt(chr_p_param_str,"ORD_STAT_FROM",(int *) &(p_dl_inst_cod_struct_h ->h_ord_stat_from));
   CO_Rtv_DataInt(chr_p_param_str,"ORD_STAT_TO",(int *) &(p_dl_inst_cod_struct_h ->h_ord_stat_to));
   CO_Rtv_DataString(chr_p_param_str,"STAT_CHNG_USER",(char *)p_dl_inst_cod_struct_h->h_stat_chng_user);
   CO_Rtv_DataInt(chr_p_param_str,"CANCEL_STAT_FROM",(int *) &(p_dl_inst_cod_struct_h ->h_cancel_stat_from));
   CO_Rtv_DataInt(chr_p_param_str,"CANCEL_STAT_TO",(int *) &(p_dl_inst_cod_struct_h ->h_cancel_stat_to));
   CO_Rtv_DataInt(chr_p_param_str,"STAT_CHNG_DT",(int *)p_dl_inst_cod_struct_h->h_stat_chng_dt);
   CO_Rtv_DataString(chr_p_param_str,"CLIENT_CD",(char *)p_dl_inst_cod_struct_h->h_client_cd);
   CO_Rtv_DataString(chr_p_param_str,"ISIN",(char *)p_dl_inst_cod_struct_h->h_isin);

	CO_Rtv_DataDbl(chr_p_param_str,"QTY", &(p_dl_inst_cod_struct_h ->h_qty));
   CO_Rtv_DataString(chr_p_param_str,"MKT_TYPE",(char *)p_dl_inst_cod_struct_h->h_mkt_type);
   CO_Rtv_DataString(chr_p_param_str,"SETTLEMENT_NO",(char *)p_dl_inst_cod_struct_h ->h_settlement_no);
   CO_Rtv_DataString(chr_p_param_str,"EXEC_DT",(char *)p_dl_inst_cod_struct_h->h_exec_dt);
   CO_Rtv_DataString(chr_p_param_str,"OTHER_DPID",(char *)p_dl_inst_cod_struct_h->h_other_dpid);
   CO_Rtv_DataString(chr_p_param_str,"OTHER_CLIENT",(char *)p_dl_inst_cod_struct_h->h_other_client);
   CO_Rtv_DataString(chr_p_param_str,"BENF_ACC_CTGRY",(char *)p_dl_inst_cod_struct_h->h_benf_acc_ctgry);
   CO_Rtv_DataString(chr_p_param_str,"OTHER_CMBP_ID",(char *)p_dl_inst_cod_struct_h->h_other_cmbp_id);
   CO_Rtv_DataString(chr_p_param_str,"INTERNAL_REF_NO",(char *)p_dl_inst_cod_struct_h->h_internal_ref_no);

RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_CODPopulate \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_CODPopulate \n",NULL,NULL);
	return 1;
}


int   DL_Proc_CDSLDPInstPopulate(DL_UPDDPINST_STRUCT_H *p_dl_upddpinst_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);


	CO_Rtv_DataString(chr_p_param_str,"INTERNAL_REF_NO",(char *)p_dl_upddpinst_struct_h->h_internal_ref_no);
	/* CO_Rtv_DataInt(chr_p_param_str,"DPM_TRANS_NO",(int *) &(p_dl_upddpinst_struct_h ->h_dpm_trans_no));
	** Modified For ISKB_3298 Changes - Jun2010 - Naren V */

	CO_Rtv_DataLong(chr_p_param_str,"DPM_TRANS_NO",(long *) &(p_dl_upddpinst_struct_h ->h_dpm_trans_no));


	/* printf("\n Amit:InsideProcPopulate:h_dpm_transaction_no=|%d| \n",p_dl_upddpinst_struct_h->h_dpm_trans_no);
	** Modified For ISKB_3298 Changes - Jun2010 - Naren V */
	
	printf("\n Amit:InsideProcPopulate:h_dpm_transaction_no=|%ld| \n",p_dl_upddpinst_struct_h->h_dpm_trans_no);
	printf("\n Amit:InsideProcPopulate:h_internal_ref_no=|%s|\n",p_dl_upddpinst_struct_h ->h_internal_ref_no);
	fflush(stdout); /* Added For ISKB_3298 Changes - Jun2010 - Naren V */

RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_CODPopulate \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_CODPopulate \n",NULL,NULL);
	return 1;
}


int   DL_Proc_CDSLCODPopulate(DL_INST_COD_STRUCT_H *p_dl_inst_cod_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	/* CO_Rtv_DataInt(chr_p_param_str,"DPM_TRANSACTION_NO",(int *) &(p_dl_inst_cod_struct_h ->h_dpm_transaction_no));
	** Modified For ISKB_3298 Changes - Jun2010 - Naren V */

	CO_Rtv_DataLong(chr_p_param_str,"DPM_TRANSACTION_NO",(long *) &(p_dl_inst_cod_struct_h ->h_dpm_transaction_no));

	CO_Rtv_DataInt(chr_p_param_str,"STATUS",(int *) &(p_dl_inst_cod_struct_h ->h_ord_stat_to));

	/* printf("\n DPM_TRANSACTION_NO=|%d| \n",p_dl_inst_cod_struct_h ->h_dpm_transaction_no);
	** Modified For ISKB_3298 Changes - Jun2010 - Naren V */

	printf("\n DPM_TRANSACTION_NO=|%ld| \n",p_dl_inst_cod_struct_h ->h_dpm_transaction_no);
	printf("\n STATUS=|%d| \n",p_dl_inst_cod_struct_h ->h_ord_stat_to);
	fflush(stdout); /* Added For ISKB_3298 Changes - Jun2010 - Naren V */

RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_CDSLCODPopulate \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_CDSLCODPopulate \n",NULL,NULL);
	return 1;
}

/*Code added by Amol 03082006*/
int Populate_DL_BSE_OBL(DL_BSE_OBL_STRUCT_H *p_dl_bse_obl_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_dl_bse_obl_struct_h->h_instr_code );
	CO_Rtv_DataString(p_param_data,"BUY_QTY",p_dl_bse_obl_struct_h->h_buy_qty );
	CO_Rtv_DataString(p_param_data,"BUY_VAL",p_dl_bse_obl_struct_h->h_buy_val );
	CO_Rtv_DataString(p_param_data,"SELL_QTY",p_dl_bse_obl_struct_h->h_sell_qty );
	CO_Rtv_DataString(p_param_data,"SELL_VAL",p_dl_bse_obl_struct_h->h_sell_val );
	CO_Rtv_DataString(p_param_data,"NET_QTY",p_dl_bse_obl_struct_h->h_net_qty );
	CO_Rtv_DataString(p_param_data,"NET_VAL",p_dl_bse_obl_struct_h->h_net_val );
	CO_Rtv_DataString(p_param_data,"STD_RATE",p_dl_bse_obl_struct_h->h_std_rate );
	CO_Rtv_DataString(p_param_data,"NET_STD_DIFF",p_dl_bse_obl_struct_h->h_net_std_diff );
	CO_Rtv_DataString(p_param_data,"STD_RATE_DIFF",p_dl_bse_obl_struct_h->h_std_rate_diff );
	CO_Rtv_DataString(p_param_data,"NET_AMT",p_dl_bse_obl_struct_h->h_net_amt );
	CO_Rtv_DataString(p_param_data,"CFQTY",p_dl_bse_obl_struct_h->h_cfqty );
	CO_Rtv_DataString(p_param_data,"CALLDIVFLAG",p_dl_bse_obl_struct_h->h_calldivflag );
	CO_Rtv_DataString(p_param_data,"CALLDIVAMT",p_dl_bse_obl_struct_h->h_calldivamt );
	CO_Rtv_DataString(p_param_data,"BANK_QTY",p_dl_bse_obl_struct_h->h_bank_qty );
	CO_Rtv_DataString(p_param_data,"BANK_VAL",p_dl_bse_obl_struct_h->h_bank_val );
	CO_Rtv_DataString(p_param_data,"SETTLEMENT_NO",p_dl_bse_obl_struct_h->h_settlement_no);
	CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_bse_obl_struct_h->h_mkt_type);
	CO_Rtv_DataString(p_param_data,"DEAL_DT",p_dl_bse_obl_struct_h->h_deal_dt);

RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_BSE_OBL \n",NULL,NULL);
	return 0;

RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_BSE_OBL \n",NULL,NULL);
	return 1;
}

/*Code added by Amol 15092006*/
int Populate_DL_UPL_SOH(DL_UPL_SOH_STRUCT_H *p_dl_upl_soh_struct_h,char * p_param_data)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	 void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	 CO_Rtv_DataString(p_param_data,"REC_TYPE",p_dl_upl_soh_struct_h->h_rec_type );
	 CO_Rtv_DataString(p_param_data,"LINE_NO",p_dl_upl_soh_struct_h->h_line_no );
	 CO_Rtv_DataString(p_param_data,"BRANCH_CD",p_dl_upl_soh_struct_h->h_branch_cd );
	 CO_Rtv_DataString(p_param_data,"BEN_ACC_NO",p_dl_upl_soh_struct_h->h_ben_acc_no );
	 CO_Rtv_DataString(p_param_data,"BEN_CAT",p_dl_upl_soh_struct_h->h_ben_cat );
	 CO_Rtv_DataString(p_param_data,"ISIN",p_dl_upl_soh_struct_h->h_isin );
	 CO_Rtv_DataString(p_param_data,"BEN_ACC_TYPE",p_dl_upl_soh_struct_h->h_ben_acc_type );
	 CO_Rtv_DataString(p_param_data,"BEN_ACC_POS",p_dl_upl_soh_struct_h->h_ben_acc_pos );
	 CO_Rtv_DataString(p_param_data,"CC_ID",p_dl_upl_soh_struct_h->h_cc_id );
	 CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_upl_soh_struct_h->h_mkt_type );
	 CO_Rtv_DataString(p_param_data,"SETL_NO",p_dl_upl_soh_struct_h->h_setl_no );
	 CO_Rtv_DataString(p_param_data,"BLFLAG",p_dl_upl_soh_struct_h->h_blflag );
	 CO_Rtv_DataString(p_param_data,"BLCODE",p_dl_upl_soh_struct_h->h_blcode );
	 CO_Rtv_DataString(p_param_data,"LOCK_REL_DATE",p_dl_upl_soh_struct_h->h_lock_rel_date );
	 CO_Rtv_DataString(p_param_data,"FILLER",p_dl_upl_soh_struct_h->h_filler );
	 CO_Rtv_DataString(p_param_data,"DP_ID",p_dl_upl_soh_struct_h->h_dp_id );
	 CO_Rtv_DataString(p_param_data,"UPL_DATE",p_dl_upl_soh_struct_h->h_upl_date);
	 CO_Rtv_DataString(p_param_data,"STATUS",p_dl_upl_soh_struct_h->h_status );
	 CO_Rtv_DataString(p_param_data,"COMMENTS",p_dl_upl_soh_struct_h->h_comments );


RETURN_SUCCESS:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_UPL_SOH \n",NULL,NULL);
		 return 0;

RETURN_FAILURE:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_UPL_SOH \n",NULL,NULL);
		 return 1;
}

/*Code added by Amol 15092006*/
int Populate_DL_CDSL_UPL_A(CDSL_UPL_A_STRUCT_H *p_cdsl_upl_a_struct_h,char * p_param_data)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	 void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	 CO_Rtv_DataString(p_param_data,"LINE_IND",p_cdsl_upl_a_struct_h->h_line_ind );
	 CO_Rtv_DataString(p_param_data,"DP_ID",p_cdsl_upl_a_struct_h->h_dp_id );
	 CO_Rtv_DataString(p_param_data,"CLIENT_CD",p_cdsl_upl_a_struct_h->h_client_cd );
	 CO_Rtv_DataString(p_param_data,"UPL_DATE",p_cdsl_upl_a_struct_h->h_upl_date );
	 CO_Rtv_DataString(p_param_data,"STATUS",p_cdsl_upl_a_struct_h->h_status );
RETURN_SUCCESS:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_CDSL_UPL_A \n",NULL,NULL);
		 return 0;

RETURN_FAILURE:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_CDSL_UPL_A \n",NULL,NULL);
		 return 1;
}

/*Code added by Amol 15092006*/
int Populate_DL_CDSL_UPL_B(CDSL_UPL_B_STRUCT_H *p_cdsl_upl_b_struct_h,char * p_param_data)
{
	 void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	 void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	 void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

	 CO_Rtv_DataString(p_param_data,"LINE_IND",p_cdsl_upl_b_struct_h->h_line_ind );
	 CO_Rtv_DataString(p_param_data,"ISIN",p_cdsl_upl_b_struct_h->h_isin );
	 CO_Rtv_DataString(p_param_data,"CUR_BAL",p_cdsl_upl_b_struct_h->h_cur_bal );
	 CO_Rtv_DataString(p_param_data,"FREE_BAL",p_cdsl_upl_b_struct_h->h_free_bal);
	 CO_Rtv_DataString(p_param_data,"EMARK_BAL",p_cdsl_upl_b_struct_h->h_emark_bal );
	 CO_Rtv_DataString(p_param_data,"PLEDGE_BAL",p_cdsl_upl_b_struct_h->h_pledge_bal );
	 CO_Rtv_DataString(p_param_data,"REMAT_PEND",p_cdsl_upl_b_struct_h->h_remat_pend );
	 CO_Rtv_DataString(p_param_data,"ISIN_NAME",p_cdsl_upl_b_struct_h->h_isin_name );
	 CO_Rtv_DataString(p_param_data,"ISIN_DESC",p_cdsl_upl_b_struct_h->h_isin_desc );
	 CO_Rtv_DataString(p_param_data,"ISSUER_NAME",p_cdsl_upl_b_struct_h->h_issuer_name );
	 CO_Rtv_DataString(p_param_data,"ISSUER_ADD1",p_cdsl_upl_b_struct_h->h_issuer_add1 );
	 CO_Rtv_DataString(p_param_data,"ISSUER_ADD2",p_cdsl_upl_b_struct_h->h_issuer_add2 );
	 CO_Rtv_DataString(p_param_data,"ISSUER_ADD3",p_cdsl_upl_b_struct_h->h_issuer_add3 );
	 CO_Rtv_DataString(p_param_data,"ISSUER_CITY",p_cdsl_upl_b_struct_h->h_issuer_city );
	 CO_Rtv_DataString(p_param_data,"ISSUER_STATE",p_cdsl_upl_b_struct_h->h_issuer_state );
	 CO_Rtv_DataString(p_param_data,"PIN_CD",p_cdsl_upl_b_struct_h->h_pin_cd );
	 CO_Rtv_DataString(p_param_data,"UPL_DATE",p_cdsl_upl_b_struct_h->h_upl_date );
RETURN_SUCCESS:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_DL_CDSL_UPL_B \n",NULL,NULL);
		 return 0;

RETURN_FAILURE:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_DL_CDSL_UPL_B \n",NULL,NULL);
		 return 1;
}

/***** JC - ISKB 487 -- Start *****/
int	DL_Proc_DecimalAdjPopulate(DL_DEAL_DECI_ADJ_STRUCT_H *p_dl_deal_deci_adj_struct_h_a, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl, char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl, int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl, double *p_data_value);

	CO_ProcMonitor(APL_OUT_FILE,"Entered DL_Proc_DecimalAdj \n",NULL,NULL);
	printf("\n JC:::::Entered DL_Proc_DecimalAdj ..\n");

//	CO_Rtv_DataInt(chr_p_param_str,"TRDREPSEQNUM",(int *)int_p_trdrepseqnum);	
	CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",(char *)p_dl_deal_deci_adj_struct_h_a->h_dl_client);
	CO_Rtv_DataString(chr_p_param_str,"DL_REF_NO",(char *)p_dl_deal_deci_adj_struct_h_a->h_identiy_no);
	CO_Rtv_DataDbl(chr_p_param_str,"RATE",&(p_dl_deal_deci_adj_struct_h_a->h_price));
	CO_Rtv_DataDbl(chr_p_param_str,"DL_AMT",&(p_dl_deal_deci_adj_struct_h_a->h_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"TOTAL",&(p_dl_deal_deci_adj_struct_h_a->h_net_amt));

	printf("Before getting quantity .... |%lf|\n", p_dl_deal_deci_adj_struct_h_a->h_qty);

	CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_dl_deal_deci_adj_struct_h_a->h_qty)); 
	CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_dl_deal_deci_adj_struct_h_a->h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_dl_deal_deci_adj_struct_h_a->h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_dl_deal_deci_adj_struct_h_a->h_status);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_dl_deal_deci_adj_struct_h_a->h_access_stamp);

	printf("****** Pan: param str acc stamp=|%s|\n\n", p_dl_deal_deci_adj_struct_h_a->h_access_stamp);

	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_dl_deal_deci_adj_struct_h_a->h_checker_dt);

	printf("JC::::: Client -- [%s]\n", p_dl_deal_deci_adj_struct_h_a->h_dl_client);
	printf("JC::::: Ref No -- [%s]\n", p_dl_deal_deci_adj_struct_h_a->h_identiy_no);
	printf("JC::::: Rate   -- [%f]\n", p_dl_deal_deci_adj_struct_h_a->h_price);
	printf("JC::::: Amount -- [%f]\n", p_dl_deal_deci_adj_struct_h_a->h_amt);
	printf("JC::::: Net Amt-- [%f]\n", p_dl_deal_deci_adj_struct_h_a->h_net_amt);

	printf("JC::::: Leaving DL_Proc_DecimalAdj ..\n");


RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of DL_Proc_DecimalAdj \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of DL_Proc_DecimalAdj \n",NULL,NULL);
        return 1;
}
/***** JC - ISKB 487 -- End *****/

/* Gouse - Single Prematch [Start] */
int Populate_DL_SINGLE_PREMATCH(DL_SINGLE_PREMATCH_STRUCT_H *p_dl_single_prematch_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl, char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl, int *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl, double *p_data_value);
	
	printf("\nGouse::: In function Populate_DL_SINGLE_PREMATCH\n");
    CO_Rtv_DataString(p_param_data,"DL_CLIENT",p_dl_single_prematch_struct_h -> h_dl_client);
    CO_Rtv_DataString(p_param_data,"CONFIRMDT",p_dl_single_prematch_struct_h -> h_confdate);
	CO_Rtv_DataString(p_param_data,"SETL_DATE",p_dl_single_prematch_struct_h -> h_exp_settl_date);
    CO_Rtv_DataString(p_param_data,"VERFIED_WITH",p_dl_single_prematch_struct_h -> h_verified_with);
	CO_Rtv_DataString(p_param_data,"INFO1",p_dl_single_prematch_struct_h -> h_info1);
    CO_Rtv_DataDbl(p_param_data,"AMT_DIFF",&(p_dl_single_prematch_struct_h -> h_diffamount));
    CO_Rtv_DataString(p_param_data,"ALLOW_PARTIAL",p_dl_single_prematch_struct_h -> h_ispartial);
    CO_Rtv_DataString(p_param_data,"BRK_NO",p_dl_single_prematch_struct_h -> h_broker_ord_no);
    CO_Rtv_DataString(p_param_data,"DL_REF_NO",p_dl_single_prematch_struct_h -> h_orig_identiy_no);
    CO_Rtv_DataString(p_param_data,"LOCREFNO",p_dl_single_prematch_struct_h -> h_loc_ref_no);
	CO_Rtv_DataDbl(p_param_data,"NEWQTY",&(p_dl_single_prematch_struct_h -> h_newquantity));
    CO_Rtv_DataDbl(p_param_data,"NEWAMT",&(p_dl_single_prematch_struct_h -> h_newamount));
    CO_Rtv_DataDbl(p_param_data,"CP_AMT",&(p_dl_single_prematch_struct_h -> h_cpamt));
    CO_Rtv_DataString(p_param_data,"BROK_CMBP_ID",p_dl_single_prematch_struct_h -> h_brok_cmbp_id);
    CO_Rtv_DataString(p_param_data,"BROK_DP_ID",p_dl_single_prematch_struct_h -> h_brok_dp_id);
    CO_Rtv_DataString(p_param_data,"CP_DPID",p_dl_single_prematch_struct_h -> h_cp_dp_id);
    CO_Rtv_DataString(p_param_data,"CP_CLNID",p_dl_single_prematch_struct_h -> h_cp_client_id);
    CO_Rtv_DataString(p_param_data,"MKT_TYPE",p_dl_single_prematch_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_data,"LOCATION_CD",p_dl_single_prematch_struct_h -> h_location_cd);
    CO_Rtv_DataString(p_param_data,"EXEC_DATE",p_dl_single_prematch_struct_h -> h_execution_date);
	CO_Rtv_DataString(p_param_data,"GENDP_FLG",p_dl_single_prematch_struct_h -> h_dp_instr_flag);
	CO_Rtv_DataString(p_param_data,"INTERDP_FLG",p_dl_single_prematch_struct_h -> h_inter_dp_flag);
	CO_Rtv_DataString(p_param_data,"DEFER_SEC_SETT",p_dl_single_prematch_struct_h -> h_defer_sec_sett_flg);
	CO_Rtv_DataString(p_param_data,"DEFER_MONEY_SETT",p_dl_single_prematch_struct_h -> h_defer_mon_sett_flg);
    CO_Rtv_DataString(p_param_data,"MAKER",p_dl_single_prematch_struct_h -> h_maker);
    CO_Rtv_DataString(p_param_data,"MAKER_DT",p_dl_single_prematch_struct_h -> h_maker_dt);
    CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_dl_single_prematch_struct_h -> h_access_stamp);
    CO_Rtv_DataString(p_param_data,"CHECKER",p_dl_single_prematch_struct_h -> h_checker);
    CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_dl_single_prematch_struct_h -> h_checker_dt);
    CO_Rtv_DataString(p_param_data,"STATUS",p_dl_single_prematch_struct_h -> h_status);
    CO_Rtv_DataString(p_param_data,"NEWREFNO",p_dl_single_prematch_struct_h -> h_identiy_no);   

	/*** 
	For adding and updating the record for Global Prematch processing the param string 
	received has different value of reference no. So, populating that value for dl_single_prematch 
	***/
	printf("\n::: IDENTIY_NO = [%s]\n", p_dl_single_prematch_struct_h -> h_identiy_no);
	printf("::: ORIG_IDENTIY_NO = [%s]\n", p_dl_single_prematch_struct_h -> h_orig_identiy_no);
	if(strlen(p_dl_single_prematch_struct_h -> h_identiy_no) == 0) 
	{
		printf("::: Identiy No is null. So assigning orig identiy to identiy for GPM\n");
		strcpy(p_dl_single_prematch_struct_h -> h_identiy_no, p_dl_single_prematch_struct_h -> h_orig_identiy_no);
	}
	printf("::: IDENTIY_NO = [%s]\n", p_dl_single_prematch_struct_h -> h_identiy_no);
	/*** ***/
}
/* Gouse - Single Prematch [End] */

