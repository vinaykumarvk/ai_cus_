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
 * File Name           :      CA_ProcPopulate.c
 *
 * Description         :      Contains Structure Population Functions Related to CA
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author           Description        RFS No.
 * ---------   --------  ---------------  ------------------   ---------
 * 20/01/2006   1.2        Pradeep        New File          HDFCCA_015
 * 20/01/2006   1.3		   Smita Bhat     Added Populate Fn HDFCCA_027
 *										  				Related to Event
 *										  				Changed Variable Names as per Coding Stds
 *	08/02/2006	 1.4		   Smita Bhat		Changes related to	HDFCCA Base Ver
 * 22/02/2006   1.7       Smita Bhat      Changes related to Entitlements HDFCCA_001,HDFCCA_002,HDFCCA_017
 *														Col Names
 * 02/03/2006   1.8       Vaibhav           CA_NIS_ALLOTMENT   
 *************************************************************************/

/** Changes done for AIX - Warnings Removal 
   RETURN FAILURE Is commented for all functions and APL_GOBACK_SUCCESS added ***/

#include "Intellect_Common.h"
#include "CA_InterFace.h"
DEBUG_INFO_STRUCT_H 			**l_debug_info_ptr; /*Smita - HDFCCA_027*/

 //AIX -Warning Removal
extern void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
extern void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
extern void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
extern int CO_ProcMonitor(FILE *fptr,char *p_charmessage,
                          DEBUG_INFO_STRUCT_H **l_debug_info_ptr,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_c);
int	CA_Proc_EvntAutPopulate(CA_CAEVNT_AUT_STRUCT_H *p_ca_caevnt_aut_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_EvntAutPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_caevnt_aut_struct_h->h_corp_id);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_caevnt_aut_struct_h->h_access_stamp);

APL_GOBACK_SUCCESS  
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_EvntAutPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_EvntAutPopulate \n",NULL,NULL);
        return 1;
 **/
}


/*Smita - Added Fields related to Event Structure to Populate all fields - HDFCCA_027*/
int	CA_Proc_EvntPopulate(CA_CAEVENT_STRUCT_H *p_ca_caevent_struct_h,char *chr_p_param_str)
{
/*   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);*/
        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_EvntPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"CORP_ID",p_ca_caevent_struct_h -> h_corp_id);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_ca_caevent_struct_h -> h_instr_code);
	CO_Rtv_DataString(chr_p_param_str,"CA_EVENT",p_ca_caevent_struct_h -> h_evt_class);
	CO_Rtv_DataString(chr_p_param_str,"DECLARE_DT",p_ca_caevent_struct_h -> h_decl_date);
	CO_Rtv_DataInt(chr_p_param_str,"EVNT_INDNT",(int *) &(p_ca_caevent_struct_h -> h_evt_nbr));
	CO_Rtv_DataInt(chr_p_param_str,"PRIORITY",(int *) &(p_ca_caevent_struct_h -> h_priority));
	CO_Rtv_DataString(chr_p_param_str,"PRELIMINARY_FLAG",p_ca_caevent_struct_h -> h_preliminary_flag);
	CO_Rtv_DataString(chr_p_param_str,"CA_CURRENCY",p_ca_caevent_struct_h -> h_ca_currency);
	CO_Rtv_DataString(chr_p_param_str,"EX_DATE",p_ca_caevent_struct_h -> h_ex_date);
	CO_Rtv_DataString(chr_p_param_str,"REC_DATE",p_ca_caevent_struct_h -> h_rec_date);
	CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",p_ca_caevent_struct_h -> h_pymt_dt);
	CO_Rtv_DataString(chr_p_param_str,"RESPONSE_DATE",p_ca_caevent_struct_h -> h_respons_date);
	CO_Rtv_DataString(chr_p_param_str,"EXPIRY_DATE",p_ca_caevent_struct_h -> h_expire_date);
	CO_Rtv_DataString(chr_p_param_str,"PART_PYMT_DT",p_ca_caevent_struct_h -> h_pp_date);
	CO_Rtv_DataString(chr_p_param_str,"PROXY_DATE",p_ca_caevent_struct_h -> h_proxy_date);
	CO_Rtv_DataString(chr_p_param_str,"MEETING_DATE",p_ca_caevent_struct_h -> h_meet_date);
	CO_Rtv_DataString(chr_p_param_str,"START_DATE",p_ca_caevent_struct_h -> h_start_date);
	CO_Rtv_DataString(chr_p_param_str,"EFFECTIVE_DATE",p_ca_caevent_struct_h -> h_effect_date);
	CO_Rtv_DataString(chr_p_param_str,"PROC_OTH",p_ca_caevent_struct_h -> h_proc_oth);
	CO_Rtv_DataString(chr_p_param_str,"OP_EVT_CLASS",p_ca_caevent_struct_h -> h_op_evt_class);
	CO_Rtv_DataString(chr_p_param_str,"RESP_DT_OPND",p_ca_caevent_struct_h -> h_respons_date_openend);
	CO_Rtv_DataString(chr_p_param_str,"EXP_DT_OPEN_IND",p_ca_caevent_struct_h -> h_expire_date_openend);
	CO_Rtv_DataString(chr_p_param_str,"EVT_SEND_MSG_IND",p_ca_caevent_struct_h -> h_evt_send_msg_ind);
	CO_Rtv_DataString(chr_p_param_str,"ENTL_SEND_MSG_IND",p_ca_caevent_struct_h -> h_entl_send_msg_ind);
	CO_Rtv_DataString(chr_p_param_str,"PYMT_SEND_MSG_IND",p_ca_caevent_struct_h -> h_pymt_send_msg_ind);
	CO_Rtv_DataDbl(chr_p_param_str,"EARNINGS",&(p_ca_caevent_struct_h -> h_earnings));
	CO_Rtv_DataDbl(chr_p_param_str,"EARNINGS_RATE",&(p_ca_caevent_struct_h -> h_earnings_rt));
	CO_Rtv_DataString(chr_p_param_str,"RES_INSTR_CODE",p_ca_caevent_struct_h -> h_res_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"NEW_SAFEK_QTY",(int *) &(p_ca_caevent_struct_h -> h_new_safek_quantity));
	CO_Rtv_DataInt(chr_p_param_str,"OLD_STK_QTY",(int *) &(p_ca_caevent_struct_h -> h_old_safek_quantity));
	CO_Rtv_DataString(chr_p_param_str,"DISP_OF_FRACT",p_ca_caevent_struct_h -> h_disp_of_fract);
	CO_Rtv_DataDbl(chr_p_param_str,"FRACT_PR",&(p_ca_caevent_struct_h -> h_f_pr));
	CO_Rtv_DataInt(chr_p_param_str,"SUB_BASE_QUANTITY",(int *) &(p_ca_caevent_struct_h -> h_sub_base_quantity));
	CO_Rtv_DataDbl(chr_p_param_str,"SUB_NEW_QUANTITY",&(p_ca_caevent_struct_h -> h_sub_new_quantity));
	CO_Rtv_DataDbl(chr_p_param_str,"SUB_PR",&(p_ca_caevent_struct_h -> h_sub_pr));
	CO_Rtv_DataString(chr_p_param_str,"RHTS_CLASS",p_ca_caevent_struct_h -> h_rights_class);
	CO_Rtv_DataDbl(chr_p_param_str,"NEW_SAFEK_RT",&(p_ca_caevent_struct_h -> h_new_safek_quantity_rt));
	CO_Rtv_DataString(chr_p_param_str,"CONTACT_DETAILS",p_ca_caevent_struct_h -> h_contactinfo);
	CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT_BAL",&(p_ca_caevent_struct_h -> h_amount_due));
	CO_Rtv_DataDbl(chr_p_param_str,"RECEIVED_AMT",&(p_ca_caevent_struct_h -> h_amount_recd));
	CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_BAL",&(p_ca_caevent_struct_h -> h_quantity_due));
	CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_RECEIVED",&(p_ca_caevent_struct_h -> h_quantity_recd));
	CO_Rtv_DataInt(chr_p_param_str,"EVT_MSG_COUNT",(int *) &(p_ca_caevent_struct_h -> h_evt_msg_count));
	CO_Rtv_DataInt(chr_p_param_str,"EVT_CLT_CNT",(int *) &(p_ca_caevent_struct_h -> h_evt_clt_cnt));
	CO_Rtv_DataInt(chr_p_param_str,"ENTL_MSG_CNT",(int *) &(p_ca_caevent_struct_h -> h_entl_msg_cnt));
	CO_Rtv_DataInt(chr_p_param_str,"ENTL_CLT_CNT",(int *) &(p_ca_caevent_struct_h -> h_entl_clt_cnt));
	CO_Rtv_DataInt(chr_p_param_str,"COUNT_ACS_PEND",(int *) &(p_ca_caevent_struct_h -> h_count_acs_pend));
	CO_Rtv_DataString(chr_p_param_str,"NREP_DATE_A",p_ca_caevent_struct_h -> h_nrepdate1);
	CO_Rtv_DataString(chr_p_param_str,"MSG_FOLLOWDAYS1",p_ca_caevent_struct_h -> h_follmsg1date);
	CO_Rtv_DataString(chr_p_param_str,"MSG_FOLLOWDAYS2",p_ca_caevent_struct_h -> h_follmsg2date);
	CO_Rtv_DataString(chr_p_param_str,"INFO_SEQ",p_ca_caevent_struct_h -> h_info_nbr);
	CO_Rtv_DataString(chr_p_param_str,"ENTITL_INFONO",p_ca_caevent_struct_h -> h_entinfo_no);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_ca_caevent_struct_h -> h_evt_stat);
	CO_Rtv_DataString(chr_p_param_str,"PROCESSED_DATE",p_ca_caevent_struct_h -> h_stat_date);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_ca_caevent_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_ca_caevent_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_ca_caevent_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_ca_caevent_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_ca_caevent_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"DEAL_FRM_DATE",p_ca_caevent_struct_h -> h_dealfrom_dt);
	CO_Rtv_DataString(chr_p_param_str,"DEAL_TO_DATE",p_ca_caevent_struct_h -> h_dealto_dt);
	CO_Rtv_DataString(chr_p_param_str,"SUBSCR_DATE",p_ca_caevent_struct_h -> h_subs_date);
	CO_Rtv_DataString(chr_p_param_str,"POST_DATE",p_ca_caevent_struct_h -> h_posting_date);
	CO_Rtv_DataString(chr_p_param_str,"OVER_SUBSCRP",p_ca_caevent_struct_h -> h_over_subscrp);
	CO_Rtv_DataString(chr_p_param_str,"DIVIDEND_TYPE",p_ca_caevent_struct_h -> h_div_class);
	CO_Rtv_DataDbl(chr_p_param_str,"REDEM_RT",&(p_ca_caevent_struct_h -> h_redem_rt));
	CO_Rtv_DataString(chr_p_param_str,"NSER_E_INFO",p_ca_caevent_struct_h -> h_nser_info);
	CO_Rtv_DataString(chr_p_param_str,"NSER_B_INFO",p_ca_caevent_struct_h -> h_nrep_date_a);
	CO_Rtv_DataString(chr_p_param_str,"COMP_INFO_A",p_ca_caevent_struct_h -> h_comp_info1);
	CO_Rtv_DataString(chr_p_param_str,"INCO_INFO_A",p_ca_caevent_struct_h -> h_inco_info1);
	CO_Rtv_DataString(chr_p_param_str,"RESPONSEDT_BUY",p_ca_caevent_struct_h -> h_buyresp_date);
	CO_Rtv_DataString(chr_p_param_str,"SELL_RESP_DATE",p_ca_caevent_struct_h -> h_sellresp_date);
	CO_Rtv_DataString(chr_p_param_str,"WWWADDR",p_ca_caevent_struct_h -> h_wwwaddr);
	CO_Rtv_DataString(chr_p_param_str,"TXNR_INFO_A",p_ca_caevent_struct_h -> h_txnr_info1);
	CO_Rtv_DataString(chr_p_param_str,"REQD_CERTIFY",p_ca_caevent_struct_h -> h_reqd_cert_ind);
	CO_Rtv_DataString(chr_p_param_str,"EX_DT_BSE",p_ca_caevent_struct_h -> h_ex_dt_bse);
	CO_Rtv_DataString(chr_p_param_str,"BC_FROM_DATE",p_ca_caevent_struct_h -> h_bc_from_date);
	CO_Rtv_DataString(chr_p_param_str,"BC_TO_DATE",p_ca_caevent_struct_h -> h_bc_to_date);
	CO_Rtv_DataString(chr_p_param_str,"RES_INSTR_CODE_2",p_ca_caevent_struct_h -> h_res_instr_code_2);
	CO_Rtv_DataString(chr_p_param_str,"TRANS_DT",p_ca_caevent_struct_h -> h_trans_dt);
	CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_ca_caevent_struct_h -> h_cln_code);
	CO_Rtv_DataString(chr_p_param_str,"PREV_INST_DATE",p_ca_caevent_struct_h -> h_prev_inst_date);
	CO_Rtv_DataString(chr_p_param_str,"NEXT_INST_DATE",p_ca_caevent_struct_h -> h_next_inst_date);
	CO_Rtv_DataString(chr_p_param_str,"INST_START_PERIOD",p_ca_caevent_struct_h -> h_inst_start_period);
	CO_Rtv_DataString(chr_p_param_str,"INST_END_PERIOD",p_ca_caevent_struct_h -> h_inst_end_period);
	CO_Rtv_DataString(chr_p_param_str,"LAST_PTC_DATE",p_ca_caevent_struct_h -> h_last_ptc_date);
	CO_Rtv_DataString(chr_p_param_str,"ALLOTMENT_LETTER",p_ca_caevent_struct_h -> h_allotment_letter);
	CO_Rtv_DataString(chr_p_param_str,"REDEM_OPTION",p_ca_caevent_struct_h -> h_redem_option);
	CO_Rtv_DataDbl(chr_p_param_str,"INST_AMOUNT",&(p_ca_caevent_struct_h -> h_inst_amount));
	CO_Rtv_DataString(chr_p_param_str,"SEND_SPLIT",p_ca_caevent_struct_h -> h_send_split);
	CO_Rtv_DataString(chr_p_param_str,"CMP_CODE",p_ca_caevent_struct_h -> h_cmp_code);
	CO_Rtv_DataString(chr_p_param_str,"RES_CMP_CODE",p_ca_caevent_struct_h -> h_res_cmp_code);
	CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_ca_caevent_struct_h -> h_exch_code);
	CO_Rtv_DataDbl(chr_p_param_str,"PREMIUM",&(p_ca_caevent_struct_h -> h_premium));
	CO_Rtv_DataDbl(chr_p_param_str,"FACE_VALUE",&(p_ca_caevent_struct_h -> h_face_value));
	CO_Rtv_DataString(chr_p_param_str,"INTEREST_TYPE",p_ca_caevent_struct_h -> h_interest_type);
	CO_Rtv_DataInt(chr_p_param_str,"RATIO_RCV2",(int *) &(p_ca_caevent_struct_h -> h_ratio_rcv2));
	CO_Rtv_DataInt(chr_p_param_str,"RATIO_HLD2",(int *) &(p_ca_caevent_struct_h -> h_ratio_hld2));
	CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_CODE",p_ca_caevent_struct_h -> h_depo_part_code);
	CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",p_ca_caevent_struct_h -> h_depo_code);
       /* Added by vaibhav HDFCCA_013*/
	CO_Rtv_DataString(chr_p_param_str,"BK_BUILD_IND",p_ca_caevent_struct_h -> h_bk_build_ind);
	CO_Rtv_DataString(chr_p_param_str,"ATTACH_CORP_ID",p_ca_caevent_struct_h -> h_attach_corp_id);
	CO_Rtv_DataString(chr_p_param_str,"SOURCE",p_ca_caevent_struct_h -> h_source);
	CO_Rtv_DataDbl(chr_p_param_str,"NEW_SAFEK_RT2",&(p_ca_caevent_struct_h -> h_new_safek_rt2));
	CO_Rtv_DataDbl(chr_p_param_str,"TICK_SIZE",&(p_ca_caevent_struct_h -> h_tick_size));
	CO_Rtv_DataDbl(chr_p_param_str,"ISSUE_SIZE",&(p_ca_caevent_struct_h -> h_issue_size)); /* changes done by punnamchander for ISKB_4994 - jul 08/08/2011 */
	CO_Rtv_DataDbl(chr_p_param_str,"QIB_MARGIN",&(p_ca_caevent_struct_h -> h_qib_margin));
	CO_Rtv_DataInt(chr_p_param_str,"MARKET_LOT",(int *) &(p_ca_caevent_struct_h -> h_market_lot));
	CO_Rtv_DataInt(chr_p_param_str,"MAX_RTL_QTY",(int *) &(p_ca_caevent_struct_h -> h_max_rtl_qty));
	CO_Rtv_DataInt(chr_p_param_str,"MIN_QTY",(int *) &(p_ca_caevent_struct_h -> h_min_qty));
	CO_Rtv_DataString(chr_p_param_str,"LEAD_MGR",p_ca_caevent_struct_h -> h_lead_mgr);
	CO_Rtv_DataString(chr_p_param_str,"SYND_MEM",p_ca_caevent_struct_h -> h_synd_membr);
	CO_Rtv_DataString(chr_p_param_str,"CO_MGR",p_ca_caevent_struct_h -> h_co_mgr);
	CO_Rtv_DataDbl(chr_p_param_str,"LWR_LIMIT",&(p_ca_caevent_struct_h -> h_lwr_limit));
	CO_Rtv_DataDbl(chr_p_param_str,"UPR_LIMIT",&(p_ca_caevent_struct_h -> h_upr_limit));
	CO_Rtv_DataDbl(chr_p_param_str,"FRACT_QTY_BAL",&(p_ca_caevent_struct_h -> h_fract_qty_bal));
	CO_Rtv_DataDbl(chr_p_param_str,"FRACT_QTY_RECD",&(p_ca_caevent_struct_h -> h_fract_qty_recd));
	CO_Rtv_DataString(chr_p_param_str,"BILAV_ID",p_ca_caevent_struct_h -> h_bilav_id);  /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */

	APL_IF_DEBUG
	{
		printf("Before Printing Event Structure ...........................\n");
		printf("CORP_ID    -  |%s|\n",p_ca_caevent_struct_h -> h_corp_id);
		printf("INSTR_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_instr_code);
		printf("CA_EVENT   -  |%s|\n",p_ca_caevent_struct_h -> h_evt_class);
		printf("DECLARE_DT -  |%s|\n",p_ca_caevent_struct_h -> h_decl_date);
		printf("EVNT_INDNT -  |%d|\n",p_ca_caevent_struct_h -> h_evt_nbr);
		printf("PRIORITY   -  |%d|\n",p_ca_caevent_struct_h -> h_priority);
		printf("PRELIMINARY_FLAG -  |%s|\n",p_ca_caevent_struct_h -> h_preliminary_flag);
		printf("CA_CURRENCY -  |%s|\n",p_ca_caevent_struct_h -> h_ca_currency);
		printf("EX_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_ex_date);
		printf("REC_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_rec_date);
		printf("DATEOF_PAYMENT -  |%s|\n",p_ca_caevent_struct_h -> h_pymt_dt);
		printf("RESPONSE_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_respons_date);
		printf("EXPIRY_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_expire_date);
		printf("PART_PYMT_DT -  |%s|\n",p_ca_caevent_struct_h -> h_pp_date);
		printf("PROXY_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_proxy_date);
		printf("MEETING_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_meet_date);
		printf("START_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_start_date);
		printf("EFFECTIVE_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_effect_date);
		printf("PROC_OTH -  |%s|\n",p_ca_caevent_struct_h -> h_proc_oth);
		printf("OP_EVT_CLASS -  |%s|\n",p_ca_caevent_struct_h -> h_op_evt_class);
		printf("RESP_DT_OPND -  |%s|\n",p_ca_caevent_struct_h -> h_respons_date_openend);
		printf("EXP_DT_OPEN_IND -  |%s|\n",p_ca_caevent_struct_h -> h_expire_date_openend);
		printf("EVT_SEND_MSG_IND -  |%s|\n",p_ca_caevent_struct_h -> h_evt_send_msg_ind);
		printf("ENTL_SEND_MSG_IND -  |%s|\n",p_ca_caevent_struct_h -> h_entl_send_msg_ind);
		printf("PYMT_SEND_MSG_IND -  |%s|\n",p_ca_caevent_struct_h -> h_pymt_send_msg_ind);
		printf("EARNINGS -  |%lf|\n",(p_ca_caevent_struct_h -> h_earnings));
		printf("EARNINGS_RATE -  |%lf|\n",(p_ca_caevent_struct_h -> h_earnings_rt));
		printf("RES_INSTR_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_res_instr_code);
		printf("NEW_SAFEK_QTY -  |%d|\n",(p_ca_caevent_struct_h -> h_new_safek_quantity));
		printf("OLD_STK_QTY -  |%d|\n",(p_ca_caevent_struct_h -> h_old_safek_quantity));
		printf("DISP_OF_FRACT -  |%s|\n",p_ca_caevent_struct_h -> h_disp_of_fract);
		printf("FRACT_PR -  |%lf|\n",(p_ca_caevent_struct_h -> h_f_pr));
		printf("SUB_BASE_QUANTITY -  |%d|\n",(p_ca_caevent_struct_h -> h_sub_base_quantity));
		printf("SUB_NEW_QUANTITY -  |%lf|\n",(p_ca_caevent_struct_h -> h_sub_new_quantity));
		printf("SUB_PR  -  |%lf|\n",(p_ca_caevent_struct_h -> h_sub_pr));
		printf("RHTS_CLASS  -  |%s|\n",p_ca_caevent_struct_h -> h_rights_class);
		printf("NEW_SAFEK_RT -  |%lf|\n",(p_ca_caevent_struct_h -> h_new_safek_quantity_rt));
		printf("CONTACT_DETAILS -  |%s|\n",p_ca_caevent_struct_h -> h_contactinfo);
		printf("AMOUNT_BAL -  |%lf|\n",(p_ca_caevent_struct_h -> h_amount_due));
		printf("RECEIVED_AMT -  |%lf|\n",(p_ca_caevent_struct_h -> h_amount_recd));
		printf("QUANTITY_BAL -  |%lf|\n",(p_ca_caevent_struct_h -> h_quantity_due));
		printf("QUANTITY_RECEIVED -  |%lf|\n",(p_ca_caevent_struct_h -> h_quantity_recd));
		printf("EVT_MSG_COUNT -  |%d|\n",(p_ca_caevent_struct_h -> h_evt_msg_count));
		printf("EVT_CLT_CNT -  |%d|\n",(p_ca_caevent_struct_h -> h_evt_clt_cnt));
		printf("ENTL_MSG_CNT -  |%d|\n",(p_ca_caevent_struct_h -> h_entl_msg_cnt));
		printf("ENTL_CLT_CNT -  |%d|\n",(p_ca_caevent_struct_h -> h_entl_clt_cnt));
		printf("COUNT_ACS_PEND -  |%d|\n",(p_ca_caevent_struct_h -> h_count_acs_pend));
		printf("NREP_DATE_A -  |%s|\n",p_ca_caevent_struct_h -> h_nrepdate1);
		printf("MSG_FOLLOWDAYS1 -  |%s|\n",p_ca_caevent_struct_h -> h_follmsg1date);
		printf("MSG_FOLLOWDAYS2 -  |%s|\n",p_ca_caevent_struct_h -> h_follmsg2date);
		printf("INFO_SEQ -  |%s|\n",p_ca_caevent_struct_h -> h_info_nbr);
		printf("ENTITL_INFONO -  |%s|\n",p_ca_caevent_struct_h -> h_entinfo_no);
		printf("STATUS -  |%s|\n",p_ca_caevent_struct_h -> h_evt_stat);
		printf("PROCESSED_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_stat_date);
		printf("MAKER -  |%s|\n",p_ca_caevent_struct_h -> h_maker);
		printf("MAKER_DT -  |%s|\n",p_ca_caevent_struct_h -> h_maker_dt);
		printf("CHECKER -  |%s|\n",p_ca_caevent_struct_h -> h_checker);
		printf("CHECKER_DT -  |%s|\n",p_ca_caevent_struct_h -> h_checker_dt);
		printf("ACCESS_STAMP -  |%s|\n",p_ca_caevent_struct_h -> h_access_stamp);
		printf("DEAL_FRM_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_dealfrom_dt);
		printf("DEAL_TO_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_dealto_dt);
		printf("SUBSCR_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_subs_date);
		printf("POST_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_posting_date);
		printf("OVER_SUBSCRP -  |%s|\n",p_ca_caevent_struct_h -> h_over_subscrp);
		printf("DIVIDEND_TYPE -  |%s|\n",p_ca_caevent_struct_h -> h_div_class);
		printf("REDEM_RT -  |%lf|\n",(p_ca_caevent_struct_h -> h_redem_rt));
		printf("NSER_E_INFO -  |%s|\n",p_ca_caevent_struct_h -> h_nser_info);
		printf("NSER_B_INFO -  |%s|\n",p_ca_caevent_struct_h -> h_nrep_date_a);
		printf("COMP_INFO_A -  |%s|\n",p_ca_caevent_struct_h -> h_comp_info1);
		printf("INCO_INFO_A -  |%s|\n",p_ca_caevent_struct_h -> h_inco_info1);
		printf("RESPONSEDT_BUY -  |%s|\n",p_ca_caevent_struct_h -> h_buyresp_date);
		printf("SELL_RESP_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_sellresp_date);
		printf("WWWADDR -  |%s|\n",p_ca_caevent_struct_h -> h_wwwaddr);
		printf("TXNR_INFO_A -  |%s|\n",p_ca_caevent_struct_h -> h_txnr_info1);
		printf("REQD_CERTIFY -  |%s|\n",p_ca_caevent_struct_h -> h_reqd_cert_ind);
		printf("EX_DT_BSE -  |%s|\n",p_ca_caevent_struct_h -> h_ex_dt_bse);
		printf("BC_FROM_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_bc_from_date);
		printf("BC_TO_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_bc_to_date);
		printf("RES_INSTR_CODE_2 -  |%s|\n",p_ca_caevent_struct_h -> h_res_instr_code_2);
		printf("TRANS_DT -  |%s|\n",p_ca_caevent_struct_h -> h_trans_dt);
		printf("CLN_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_cln_code);
		printf("PREV_INST_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_prev_inst_date);
		printf("NEXT_INST_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_next_inst_date);
		printf("INST_START_PERIOD -  |%s|\n",p_ca_caevent_struct_h -> h_inst_start_period);
		printf("INST_END_PERIOD -  |%s|\n",p_ca_caevent_struct_h -> h_inst_end_period);
		printf("LAST_PTC_DATE -  |%s|\n",p_ca_caevent_struct_h -> h_last_ptc_date);
		printf("ALLOTMENT_LETTER -  |%s|\n",p_ca_caevent_struct_h -> h_allotment_letter);
		printf("REDEM_OPTION -  |%s|\n",p_ca_caevent_struct_h -> h_redem_option);
		printf("INST_AMOUNT -  |%lf|\n",(p_ca_caevent_struct_h -> h_inst_amount));
		printf("SEND_SPLIT -  |%s|\n",p_ca_caevent_struct_h -> h_send_split);
		printf("CMP_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_cmp_code);
		printf("RES_CMP_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_res_cmp_code);
		printf("EXCH_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_exch_code);
		printf("PREMIUM -  |%lf|\n",(p_ca_caevent_struct_h -> h_premium));
		printf("FACE_VALUE -  |%lf|\n",(p_ca_caevent_struct_h -> h_face_value));
		printf("INTEREST_TYPE -  |%s|\n",p_ca_caevent_struct_h -> h_interest_type);
		printf("RATIO_RCV2 -  |%d|\n",(p_ca_caevent_struct_h -> h_ratio_rcv2));
		printf("RATIO_HLD2 -  |%d|\n",(p_ca_caevent_struct_h -> h_ratio_hld2));
		printf("DEPO_PART_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_depo_part_code);
		printf("DEPO_CODE -  |%s|\n",p_ca_caevent_struct_h -> h_depo_code);
		/*Added By Vaibhav HDFCCA_013*/
		printf("BK_BUILD_IND -  |%s|\n",p_ca_caevent_struct_h-> h_bk_build_ind);
		printf("ATTACH_CORP_ID -  |%s|\n",p_ca_caevent_struct_h -> h_attach_corp_id);
		printf("SOURCE -  |%s|\n",p_ca_caevent_struct_h -> h_source);
		printf("NEW_SAFEK_RT2-  |%lf|\n",(p_ca_caevent_struct_h -> h_new_safek_rt2));
		printf("TICK_SIZE -  |%lf|\n",(p_ca_caevent_struct_h -> h_tick_size));
		printf("ISSUE_SIZE -  |%lf|\n",(p_ca_caevent_struct_h ->  h_issue_size)); /* changes done by punnamchander for ISKB_4994 - jul 08/08/2011 */
		printf("QIB_MARGIN -  |%lf|\n",(p_ca_caevent_struct_h -> h_qib_margin));
		printf("MARKET_LOT -  |%d|\n",(p_ca_caevent_struct_h -> h_market_lot));
		printf("MAX_RTL_QTY -  |%d|\n",(p_ca_caevent_struct_h -> h_max_rtl_qty));
		printf("MIN_QTY -  |%d|\n",(p_ca_caevent_struct_h -> h_min_qty));
		printf("LEAD_MGR -  |%s|\n",p_ca_caevent_struct_h -> h_lead_mgr);
		printf("SYND_MEMBR -  |%s|\n",p_ca_caevent_struct_h ->  h_synd_membr);
		printf("CO_MGR -  |%s|\n",p_ca_caevent_struct_h -> h_co_mgr);
		printf("LWR_LIMIT -  |%lf|\n",(p_ca_caevent_struct_h -> h_lwr_limit));
		printf("UPR_LIMIT -  |%lf|\n",(p_ca_caevent_struct_h -> h_upr_limit));
		printf("FRACT_QTY_BAL -  |%lf|\n",(p_ca_caevent_struct_h -> h_fract_qty_bal));
		printf("FRACT_QTY_RECD -  |%lf|\n",(p_ca_caevent_struct_h -> h_fract_qty_recd));
		printf("BILAV_ID-  |%s|\n",(p_ca_caevent_struct_h -> h_bilav_id));	/* Added by Arunachalam for CS0074500 - New Bilav File upload changes */

		printf("After Printing Event Structure ...........................\n");
	}


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_EvntPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_EvntPopulate \n",NULL,NULL);
        return 1;
 **/
}
/*Smita - Added Fields related to Event Structure to Populate all fields - HDFCCA_027*/


int	CA_Proc_EntPopulate(CA_CAENTITLEMENT_STRUCT_H *p_ca_caentitlement_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_EntPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_caentitlement_struct_h->h_corp_id);
         CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ca_caentitlement_struct_h->h_dl_client);
         CO_Rtv_DataDbl(chr_p_param_str,"ELIG_ENTITL_POS",&(p_ca_caentitlement_struct_h->h_entitl_pos));
         CO_Rtv_DataString(chr_p_param_str,"CCY_FOR_ENTITL",(char *)p_ca_caentitlement_struct_h->h_entitl_ccy);
         CO_Rtv_DataDbl(chr_p_param_str,"INSTR_INC_BAL",&(p_ca_caentitlement_struct_h->h_instr_inc_bal));
         CO_Rtv_DataDbl(chr_p_param_str,"RECEIVED_AMT",&(p_ca_caentitlement_struct_h->h_amount_recd));
         CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_BAL",&(p_ca_caentitlement_struct_h->h_quantity_due));
         CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_RECEIVED",&(p_ca_caentitlement_struct_h->h_quantity_recd));
         CO_Rtv_DataString(chr_p_param_str,"NREP_DATE_B",(char *)p_ca_caentitlement_struct_h->h_nrepdate2);
         CO_Rtv_DataString(chr_p_param_str,"NREP_DATE_C",(char *)p_ca_caentitlement_struct_h->h_nrepdate3);
         CO_Rtv_DataString(chr_p_param_str,"DATEFORSEND550",(char *)p_ca_caentitlement_struct_h->h_sent550date);
			/*Smita - Changed Col Name - HDFCCA Base Version*/
         CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_ca_caentitlement_struct_h->h_entitl_stat);
         CO_Rtv_DataString(chr_p_param_str,"PROCESSED_DATE",(char *)p_ca_caentitlement_struct_h->h_stat_date);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ca_caentitlement_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_ca_caentitlement_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER",(char *)p_ca_caentitlement_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_caentitlement_struct_h->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_caentitlement_struct_h->h_access_stamp);
         CO_Rtv_DataDbl(chr_p_param_str,"CUSTODYTAX_RATE",&(p_ca_caentitlement_struct_h->h_tax_rate)); 
 	 	 CO_Rtv_DataDbl(chr_p_param_str,"FRACT_DUE",&(p_ca_caentitlement_struct_h -> h_fract_due));
	     CO_Rtv_DataDbl(chr_p_param_str,"FRACT_RCVD",&(p_ca_caentitlement_struct_h -> h_fract_rcvd));

		 APL_IF_DEBUG
		{
			 printf("CORP ID = |%s|\n",p_ca_caentitlement_struct_h->h_corp_id);
			 printf("CLIENT = |%s|\n",p_ca_caentitlement_struct_h->h_dl_client);
			 printf("ELIG_ENTITL_POS = |%lf|\n",p_ca_caentitlement_struct_h->h_entitl_pos);
			 printf("CCY_FOR_ENTITL = |%s|\n",p_ca_caentitlement_struct_h->h_entitl_ccy);
			 printf("INSTR_INC_BAL = |%lf|\n",p_ca_caentitlement_struct_h->h_instr_inc_bal);
 			 printf("RECEIVED_AMT = |%lf|\n",p_ca_caentitlement_struct_h->h_amount_recd);
 			 printf("QUANTITY_BAL = |%lf|\n",p_ca_caentitlement_struct_h->h_quantity_due);
 			 printf("QUANTITY_RECEIVED = |%lf|\n",p_ca_caentitlement_struct_h->h_quantity_recd);
 			 printf("NREP_DATE_B = |%s|\n",p_ca_caentitlement_struct_h->h_nrepdate2);
 			 printf("NREP_DATE_C = |%s|\n",p_ca_caentitlement_struct_h->h_nrepdate3);
 			 printf("DATEFORSEND550 = |%s|\n",p_ca_caentitlement_struct_h->h_sent550date);
 			 printf("STATUS = |%s|\n",p_ca_caentitlement_struct_h->h_entitl_stat);
 			 printf("MAKER = |%s|\n",p_ca_caentitlement_struct_h->h_maker);
 			 printf("MAKER_DT = |%s|\n",p_ca_caentitlement_struct_h->h_maker_dt);
 			 printf("CHECKER = |%s|\n",p_ca_caentitlement_struct_h->h_checker);
  			 printf("CHECKER_DT = |%s|\n",p_ca_caentitlement_struct_h->h_checker_dt);
  			 printf("ACCESS_STAMP = |%s|\n",p_ca_caentitlement_struct_h->h_access_stamp);
  			 printf("CUSTODYTAX_RATE = |%lf|\n",p_ca_caentitlement_struct_h->h_tax_rate);
  			 printf("FRACT_DUE = |%lf|\n",p_ca_caentitlement_struct_h -> h_fract_due);
  			 printf("FRACT_RCVD = |%lf|\n",p_ca_caentitlement_struct_h -> h_fract_rcvd);
		}

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_EntPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_EntPopulate \n",NULL,NULL);
        return 1;
 **/
}


int	CA_Proc_EntAutPopulate(CA_CAENTL_AUT_STRUCT_H *p_ca_caentl_aut_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_EntAutPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_caentl_aut_struct_h->h_corp_id);
        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ca_caentl_aut_struct_h->h_dl_client);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_caentl_aut_struct_h->h_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_EntAutPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_EntAutPopulate \n",NULL,NULL);
        return 1;
 **/
}

int	CA_Proc_PymtPopulate(CA_CACHEQUE_STRUCT_H *p_ca_cacheque_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
 /*  void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);*/
        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_PymtPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_cacheque_struct_h->h_corp_id);
        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ca_cacheque_struct_h->h_dl_client);
        CO_Rtv_DataInt(chr_p_param_str,"SEQNUM_PAY",(int *)&(p_ca_cacheque_struct_h->h_pymt_srl_nbr));
        CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",(char *)p_ca_cacheque_struct_h->h_pymt_dt);
        CO_Rtv_DataString(chr_p_param_str,"PAYMENT_CCY",(char *)p_ca_cacheque_struct_h->h_pymt_currency);
        CO_Rtv_DataDbl(chr_p_param_str,"CURR_PYMT",&(p_ca_cacheque_struct_h->h_curr_pymt));
        CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_RECEIVED",&(p_ca_cacheque_struct_h->h_quantity_recd));
        CO_Rtv_DataDbl(chr_p_param_str,"TAX_RATE",&(p_ca_cacheque_struct_h->h_tax_rate));
        CO_Rtv_DataString(chr_p_param_str,"PAYMENT_INFO",(char *)p_ca_cacheque_struct_h->h_pymt_inst);
        CO_Rtv_DataString(chr_p_param_str,"HF_DATE",(char *)p_ca_cacheque_struct_h->h_handoff_date);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_IDENTITY_NO",(char *)p_ca_cacheque_struct_h->h_txn_indentity_no);
        CO_Rtv_DataString(chr_p_param_str,"DATEOFBILLING",(char *)p_ca_cacheque_struct_h->h_billdate);
        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_ca_cacheque_struct_h->h_loccode);
        CO_Rtv_DataDbl(chr_p_param_str,"TAX_AMOUNT",&(p_ca_cacheque_struct_h->h_tax_amount));
        CO_Rtv_DataDbl(chr_p_param_str,"OTHER_CHRGS",&(p_ca_cacheque_struct_h->h_other_chrgs));
        CO_Rtv_DataString(chr_p_param_str,"STAT_PYMT",(char *)p_ca_cacheque_struct_h->h_pymt_stat);
        CO_Rtv_DataString(chr_p_param_str,"PROCESSED_DATE",(char *)p_ca_cacheque_struct_h->h_stat_date);
        CO_Rtv_DataString(chr_p_param_str,"DATE_OF_INPUT",(char *)p_ca_cacheque_struct_h->h_new_dt);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ca_cacheque_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_ca_cacheque_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_ca_cacheque_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_cacheque_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_cacheque_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"AE_PASSIND",(char *)p_ca_cacheque_struct_h->h_clt_pass_flg);
        CO_Rtv_DataString(chr_p_param_str,"CLT_SEQNUM",(char *)p_ca_cacheque_struct_h->h_clt_batch_no);
        CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_PAID",(double *)&(p_ca_cacheque_struct_h->h_quantity_paid));
		CO_Rtv_DataDbl(chr_p_param_str,"TAXABLE_DIVIDEND",(double *)&(p_ca_cacheque_struct_h->h_taxable_dividend));
		CO_Rtv_DataDbl(chr_p_param_str,"FRACT_QTY_BAL",(double *)&(p_ca_cacheque_struct_h->h_fract_qty_bal));
		CO_Rtv_DataDbl(chr_p_param_str,"FRACT_QTY_RECD",(double *)&(p_ca_cacheque_struct_h->h_fract_qty_recd));
        CO_Rtv_DataString(chr_p_param_str,"CPA_REPORTED",(char *)p_ca_cacheque_struct_h->h_cpa_reported);
	CO_Rtv_DataDbl(chr_p_param_str,"WRITEOFF_AMOUNT",(double *)&(p_ca_cacheque_struct_h->h_writeoff_amount));
	CO_Rtv_DataDbl(chr_p_param_str,"NET_AMOUNT",&(p_ca_cacheque_struct_h->h_net_amount));/*Changes done by Sunny for CS0020637*/

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_PymtPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_PymtPopulate \n",NULL,NULL);
        return 1;
 **/
}

int	CA_Proc_RhtsPopulate(CA_CARTSPROC_STRUCT_H *l_ca_cartsproc_struct_h_ptr,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
 /*  void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);*/

        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_RhtsPopulate \n",NULL,NULL);

			printf("\n chr_p_param_str is :%s:",chr_p_param_str);
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",(char *)l_ca_cartsproc_struct_h_ptr->h_instr_code);
        CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)l_ca_cartsproc_struct_h_ptr->h_dl_client);
        CO_Rtv_DataString(chr_p_param_str,"CA_EVENT",(char *)l_ca_cartsproc_struct_h_ptr->h_ca_event);
        CO_Rtv_DataString(chr_p_param_str,"DECLARE_DT",(char *)l_ca_cartsproc_struct_h_ptr->h_decl_date);
        CO_Rtv_DataInt(chr_p_param_str,"EVNT_INDNT",(int *)&(l_ca_cartsproc_struct_h_ptr->h_evt_nbr));
        CO_Rtv_DataString(chr_p_param_str,"INSTR_PARENT",(char *)l_ca_cartsproc_struct_h_ptr->h_instr_parent);
        CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)l_ca_cartsproc_struct_h_ptr->h_corp_id);
        CO_Rtv_DataDbl(chr_p_param_str,"TOTAL_QUANTITY",&(l_ca_cartsproc_struct_h_ptr->h_total_quantity));
        CO_Rtv_DataDbl(chr_p_param_str,"TAKEUP_QUANTITY",&(l_ca_cartsproc_struct_h_ptr->h_takeupquantity));
        CO_Rtv_DataDbl(chr_p_param_str,"LAPSE_QTY",&(l_ca_cartsproc_struct_h_ptr->h_lapsequenceuantity));
        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)l_ca_cartsproc_struct_h_ptr->h_loccode);
        CO_Rtv_DataInt(chr_p_param_str,"SUB_BASE_QUANTITY",(int *)&(l_ca_cartsproc_struct_h_ptr->h_sub_base_quantity));
        CO_Rtv_DataDbl(chr_p_param_str,"SUB_NEW_QUANTITY",&(l_ca_cartsproc_struct_h_ptr->h_sub_new_quantity));
        CO_Rtv_DataString(chr_p_param_str,"SUB_CURRENCY",(char *)l_ca_cartsproc_struct_h_ptr->h_sub_currency);
        CO_Rtv_DataDbl(chr_p_param_str,"SUB_PR",&(l_ca_cartsproc_struct_h_ptr->h_sub_pr));
        CO_Rtv_DataString(chr_p_param_str,"INFO_SEQ",(char *)l_ca_cartsproc_struct_h_ptr->h_info_nbr);
		  /*Smita - Changed Col Name - HDFCCA_BaseVer*/
        CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)l_ca_cartsproc_struct_h_ptr->h_evt_stat);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)l_ca_cartsproc_struct_h_ptr->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)l_ca_cartsproc_struct_h_ptr->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",(char *)l_ca_cartsproc_struct_h_ptr->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)l_ca_cartsproc_struct_h_ptr->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)l_ca_cartsproc_struct_h_ptr->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",(char *)l_ca_cartsproc_struct_h_ptr->h_pymt_dt);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_RhtsPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_RhtsPopulate \n",NULL,NULL);
        return 1;
 **/
}

int	CA_Proc_RhtsAutPopulate(CA_RHTS_SUTH_STRUCT_H *p_ca_rhts_suth_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
/*   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);*/

        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_RhtsAutPopulate \n",NULL,NULL);
			printf("\n chr_p_param_str is :%s:",chr_p_param_str);
         CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",(char *)p_ca_rhts_suth_struct_h->h_instr_code);
			printf("\n instr_code is :%s:",p_ca_rhts_suth_struct_h->h_instr_code);
         CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ca_rhts_suth_struct_h->h_dl_client);
			printf("\n accout is :%s:",p_ca_rhts_suth_struct_h->h_dl_client);
         CO_Rtv_DataString(chr_p_param_str,"CA_EVENT",(char *)p_ca_rhts_suth_struct_h->h_ca_event);
			printf("\n ce typ is :%s:",p_ca_rhts_suth_struct_h->h_ca_event);
         CO_Rtv_DataInt(chr_p_param_str,"EVNT_INDNT",(int *)&(p_ca_rhts_suth_struct_h->h_evt_nbr));
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_rhts_suth_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"DECLARE_DT",(char *)p_ca_rhts_suth_struct_h->h_decl_date);
			printf("\n decl dt is :%s:",p_ca_rhts_suth_struct_h->h_decl_date);
         CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_ca_rhts_suth_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_rhts_suth_struct_h->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",(char *)p_ca_rhts_suth_struct_h->h_pymt_dt);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_RhtsAutPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_RhtsAutPopulate \n",NULL,NULL);
        return 1;
 **/
}

int	CA_Proc_PayPopulate(CA_CAPYMT_AUT_STRUCT_H *p_ca_capymt_aut_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   /*void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);*/

        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_PayPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_capymt_aut_struct_h_a->h_corp_id);
         CO_Rtv_DataString(chr_p_param_str,"CLIENT",(char *)p_ca_capymt_aut_struct_h_a->h_dl_client);
         CO_Rtv_DataInt(chr_p_param_str,"SEQNUM_PAY",(int *)&(p_ca_capymt_aut_struct_h_a->h_pymt_srl_nbr));
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_capymt_aut_struct_h_a->h_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_PayPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_PayPopulate \n",NULL,NULL);
        return 1;
 **/
}

int	CA_Proc_GlblPymtPopulate(CA_CAGLPYMT_STRUCT_H *p_ca_caglpymt_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered CA_Proc_GlblPymtPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_caglpymt_struct_h->h_corp_id);
         CO_Rtv_DataDbl(chr_p_param_str,"ELIG_ENTITL_POS",&(p_ca_caglpymt_struct_h->h_entitl_pos));
         CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_BAL",&(p_ca_caglpymt_struct_h->h_quantity_due));
         CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT_BAL",&(p_ca_caglpymt_struct_h->h_amount_due));
         CO_Rtv_DataString(chr_p_param_str,"DATEOF_PAYMENT",(char *)p_ca_caglpymt_struct_h->h_pymt_dt);
         CO_Rtv_DataDbl(chr_p_param_str,"CURR_QTY_BAL",&(p_ca_caglpymt_struct_h->h_cur_quantity_due));
         CO_Rtv_DataDbl(chr_p_param_str,"CUR_AMT_BAL",&(p_ca_caglpymt_struct_h->h_cur_amount_due));
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ca_caglpymt_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_ca_caglpymt_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",(char *)p_ca_caglpymt_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_caglpymt_struct_h->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"STAT_PYMT",(char *)p_ca_caglpymt_struct_h->h_pymt_stat);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_caglpymt_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"DATE_OF_INPUT",(char *)p_ca_caglpymt_struct_h->h_new_dt);
         CO_Rtv_DataDbl(chr_p_param_str,"QUANTITY_PAID",&(p_ca_caglpymt_struct_h->h_quantity_paid));
		   CO_Rtv_DataDbl(chr_p_param_str,"TAXABLE_DIVIDEND",&(p_ca_caglpymt_struct_h->h_taxable_dividend)); 	
			CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",(char *)p_ca_caglpymt_struct_h->h_loccode);
			
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CA_Proc_GlblPymtPopulate \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CA_Proc_GlblPymtPopulate \n",NULL,NULL);
        return 1;
 **/
}
/* vaibhav - HDFCCA_015 - CA_NIS_Allotment */

int Populate_CA_NIS_ALLOTMENT(CA_NIS_ALLOTMENT_STRUCT_H *p_ca_nis_allotment_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_NIS_ALLOTMENT \n",NULL,NULL);

	CO_Rtv_DataString(p_param_data,"CORP_ID",p_ca_nis_allotment_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_ca_nis_allotment_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CANREFNO",p_ca_nis_allotment_struct_h -> h_canrefno);
	CO_Rtv_DataString(p_param_data,"CANDATE",p_ca_nis_allotment_struct_h -> h_candate);
	CO_Rtv_DataString(p_param_data,"CANRECDATE",p_ca_nis_allotment_struct_h -> h_canrecdate);
	CO_Rtv_DataDbl(p_param_data,"QTYSHALLOT", &(p_ca_nis_allotment_struct_h -> h_qtyshallot));
	CO_Rtv_DataString(p_param_data,"BLOCKFLG",p_ca_nis_allotment_struct_h -> h_blockflg);
	CO_Rtv_DataDbl(p_param_data,"PRICE",&(p_ca_nis_allotment_struct_h -> h_price));
	CO_Rtv_DataDbl(p_param_data,"MMPAID",&(p_ca_nis_allotment_struct_h -> h_mmpaid));
	CO_Rtv_DataDbl(p_param_data,"MONEY_PAYABLE",&(p_ca_nis_allotment_struct_h -> h_money_payable));
	CO_Rtv_DataDbl(p_param_data,"AMOUNTPAY",&(p_ca_nis_allotment_struct_h -> h_amountpay));
	CO_Rtv_DataString(p_param_data,"LASTDATETIME",p_ca_nis_allotment_struct_h -> h_lastdatetime);
    CO_Rtv_DataString(p_param_data,"CLASTDATETIME",p_ca_nis_allotment_struct_h -> h_clastdatetime);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ca_nis_allotment_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ca_nis_allotment_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_ca_nis_allotment_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_ca_nis_allotment_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ca_nis_allotment_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS",p_ca_nis_allotment_struct_h -> h_status);
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_NIS_ALLOTMEN \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_NIS_ALLOTMEN \n",NULL,NULL);
        return 1;
 **/
}
/* Vaibhav - HDFCCA_015 - CA_NIS_Allotment */
/*Added by Chirag for HDFCCA_016 CA_Bidding*/
int   Populate_CA_NIS_BID(CA_NIS_BID_STRUCT_H *p_ca_nis_bid_struct_h,char * chr_p_param_str)
{
  void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_NIS_BID \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_nis_bid_struct_h->h_corp_id);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",(char *)p_ca_nis_bid_struct_h->h_cln_code);
         CO_Rtv_DataInt(chr_p_param_str,"BREVNO",(int *)&(p_ca_nis_bid_struct_h->h_brevno));
         CO_Rtv_DataString(chr_p_param_str,"BDATE",(char *)p_ca_nis_bid_struct_h->h_bdate);
         CO_Rtv_DataDbl(chr_p_param_str,"BQTY1",&(p_ca_nis_bid_struct_h->h_bqty1));
         CO_Rtv_DataDbl(chr_p_param_str,"BRATE1",&(p_ca_nis_bid_struct_h->h_brate1));
         CO_Rtv_DataDbl(chr_p_param_str,"BQTY2",&(p_ca_nis_bid_struct_h->h_bqty2));
         CO_Rtv_DataDbl(chr_p_param_str,"BRATE2",&(p_ca_nis_bid_struct_h->h_brate2));
         CO_Rtv_DataDbl(chr_p_param_str,"BQTY3",&(p_ca_nis_bid_struct_h->h_bqty3));
         CO_Rtv_DataDbl(chr_p_param_str,"BRATE3",&(p_ca_nis_bid_struct_h->h_brate3));
         CO_Rtv_DataString(chr_p_param_str,"FILEGENFLAG",(char *)p_ca_nis_bid_struct_h->h_filegenflg);
         CO_Rtv_DataString(chr_p_param_str,"PAYCOMM",(char *)p_ca_nis_bid_struct_h->h_paycomm);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ca_nis_bid_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_ca_nis_bid_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER",(char *)p_ca_nis_bid_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_nis_bid_struct_h->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_nis_bid_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_ca_nis_bid_struct_h->h_status);
         CO_Rtv_DataString(chr_p_param_str,"APPLFRMNO",(char *)p_ca_nis_bid_struct_h->h_applfrmno);
         CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",(char *)p_ca_nis_bid_struct_h->h_depo_code);
         CO_Rtv_DataString(chr_p_param_str,"DEPO_CLN_ID",(char *)p_ca_nis_bid_struct_h->h_depo_cln_id);
         CO_Rtv_DataString(chr_p_param_str,"DP_ID",(char *)p_ca_nis_bid_struct_h->h_dp_id);
         CO_Rtv_DataString(chr_p_param_str,"SYND_MEMBR",(char *)p_ca_nis_bid_struct_h->h_synd_membr);
         CO_Rtv_DataDbl(chr_p_param_str,"MMPAYNW",&(p_ca_nis_bid_struct_h->h_mmpaynw));

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_NIS_BID \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_NIS_BID \n",NULL,NULL);
        return 1;
 **/
}
int   Populate_CA_NIS_APPLICATION(CA_NIS_APPLICATION_STRUCT_H *p_ca_nis_application_struct_h,char * chr_p_param_str)
{
  void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_NIS_Application \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CORP_ID",(char *)p_ca_nis_application_struct_h->h_corp_id);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",(char *)p_ca_nis_application_struct_h->h_cln_code);
         CO_Rtv_DataInt(chr_p_param_str,"BREVNO",(int *)&(p_ca_nis_application_struct_h->h_brevno));
         CO_Rtv_DataString(chr_p_param_str,"ADATE",(char *)p_ca_nis_application_struct_h->h_adate);
         CO_Rtv_DataDbl(chr_p_param_str,"AQTY",&(p_ca_nis_application_struct_h->h_aqty));
         CO_Rtv_DataDbl(chr_p_param_str,"ARATE",&(p_ca_nis_application_struct_h->h_arate));
         CO_Rtv_DataString(chr_p_param_str,"FILEGENFLG",(char *)p_ca_nis_application_struct_h->h_filegenflg);
         CO_Rtv_DataString(chr_p_param_str,"PAYCOMM",(char *)p_ca_nis_application_struct_h->h_paycomm);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_ca_nis_application_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_ca_nis_application_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER",(char *)p_ca_nis_application_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_ca_nis_application_struct_h->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_ca_nis_application_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"STATUS",(char *)p_ca_nis_application_struct_h->h_status);
         CO_Rtv_DataString(chr_p_param_str,"APPLNCODE",(char *)p_ca_nis_application_struct_h->h_applncode);
         CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",(char *)p_ca_nis_application_struct_h->h_depo_code);
         CO_Rtv_DataString(chr_p_param_str,"DEPO_CLN_ID",(char *)p_ca_nis_application_struct_h->h_depo_cln_id);
         CO_Rtv_DataString(chr_p_param_str,"DP_ID",(char *)p_ca_nis_application_struct_h->h_dp_id);
         CO_Rtv_DataString(chr_p_param_str,"SYND_MEMBR",(char *)p_ca_nis_application_struct_h->h_synd_membr);
         CO_Rtv_DataDbl(chr_p_param_str,"MMPAID",&(p_ca_nis_application_struct_h->h_mmpaid));
         CO_Rtv_DataString(chr_p_param_str,"BK_BUILD_IND",(char *)p_ca_nis_application_struct_h->h_bk_build_ind);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_NIS_APPLICATION\n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_NIS_APPLICATION \n",NULL,NULL);
        return 1;
 **/
}
	/*Added by Chirag for HDFCCA_016 CA_NIS_Application*/

/*Vaibhav CA_APPLICATION*/
int Populate_CA_APPLICATION(CA_APPLICATION_STRUCT_H *p_ca_application_struct_h,char * p_param_data)
{
    void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	 void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
    void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);

    CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_APPLICATION \n",NULL,NULL);

    CO_Rtv_DataString(p_param_data,"CORP_ID",p_ca_application_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_ca_application_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"APPLICATION_DATE",p_ca_application_struct_h -> h_application_date);
	CO_Rtv_DataDbl(p_param_data,"APPLIED_QTY",&(p_ca_application_struct_h -> h_applied_qty));
	CO_Rtv_DataDbl(p_param_data,"AVL_QTY",&(p_ca_application_struct_h -> h_avl_qty));
	CO_Rtv_DataDbl(p_param_data,"ADDQTY_APP",&(p_ca_application_struct_h -> h_addqty_app));
	CO_Rtv_DataDbl(p_param_data,"PRICE",&(p_ca_application_struct_h -> h_price));
	CO_Rtv_DataDbl(p_param_data,"AMT_PAYABLE",&(p_ca_application_struct_h -> h_amt_payable));
	CO_Rtv_DataDbl(p_param_data,"AMT_DUE",&(p_ca_application_struct_h -> h_amt_due));
	CO_Rtv_DataString(p_param_data,"REMARK",p_ca_application_struct_h -> h_remark);
	CO_Rtv_DataString(p_param_data,"STATUS",p_ca_application_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ca_application_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ca_application_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ca_application_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_ca_application_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_ca_application_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_ca_application_struct_h -> h_depo_code);
	CO_Rtv_DataString(p_param_data,"DEPO_CLN_ID",p_ca_application_struct_h -> h_depo_cln_id);
	CO_Rtv_DataString(p_param_data,"DP_ID",p_ca_application_struct_h -> h_dp_id);
	CO_Rtv_DataString(p_param_data,"CLN_REFNO",p_ca_application_struct_h -> h_cln_refno);
	CO_Rtv_DataInt(p_param_data,"CLN_SRNO",(int *) &(p_ca_application_struct_h -> h_cln_srno));




   APL_IF_DEBUG
	{
			 printf("CORP ID = |%s|\n",p_ca_application_struct_h->h_corp_id);
			 printf("CLN_CODE = |%s|\n",p_ca_application_struct_h->h_cln_code);
			 printf("APPLICATION_DATE = |%s|\n",p_ca_application_struct_h->h_application_date);
			 printf("APPLIED_QTY = |%lf|\n",p_ca_application_struct_h->h_applied_qty);
 			 printf("AVL_QTY = |%lf|\n",p_ca_application_struct_h->h_avl_qty);
 			 printf("ADDQTY_APP = |%lf|\n",p_ca_application_struct_h->h_addqty_app);
 			 printf("PRICE = |%lf|\n",p_ca_application_struct_h->h_price);
 			 printf("AMT_PAYABLE = |%lf|\n",p_ca_application_struct_h->h_amt_payable);
 			 printf("AMT_DUE = |%lf|\n",p_ca_application_struct_h->h_amt_due);
 			 printf("REMARK = |%s|\n",p_ca_application_struct_h->h_remark);
 			 printf("STATUS = |%s|\n",p_ca_application_struct_h->h_status);
 			 printf("MAKER = |%s|\n",p_ca_application_struct_h->h_maker);
 			 printf("MAKER_DT = |%s|\n",p_ca_application_struct_h->h_maker_dt);
 			 printf("CHECKER = |%s|\n",p_ca_application_struct_h->h_checker);
  			 printf("CHECKER_DT = |%s|\n",p_ca_application_struct_h->h_checker_dt);
  			 printf("ACCESS_STAMP = |%s|\n",p_ca_application_struct_h->h_access_stamp);
  			 printf("DEPO_CODE = |%s|\n",p_ca_application_struct_h->h_depo_code);
  			 printf("DEPO_CLN_ID = |%s|\n",p_ca_application_struct_h ->h_depo_cln_id);
  			 printf("DP_ID = |%s|\n",p_ca_application_struct_h ->h_dp_id);
			 printf("CLN_REFNO = |%s|\n",p_ca_application_struct_h ->h_cln_refno);
  			 printf("CLN_SRNO = |%d|\n",p_ca_application_struct_h ->h_cln_srno);

	}
	printf("In Proc_Populate Access Stamp = |%s|\n",p_ca_application_struct_h -> h_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_APPLICATION \n",NULL,NULL);
        return 0;

/** 
RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_APPLICATION \n",NULL,NULL);
        return 1;
 **/

}
/*Vaibhav CA_APPLICATION*/
/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/
int Populate_CA_RTBB_ALLOTMENT(CA_RTBB_ALLOTMENT_STRUCT_H *p_ca_rtbb_allotment_struct_h,char * p_param_data)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

    CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_RTBB_ALLOTMENT \n",NULL,NULL);

	CO_Rtv_DataString(p_param_data,"CORP_ID",p_ca_rtbb_allotment_struct_h -> h_corp_id);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_ca_rtbb_allotment_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"CA_EVENT",p_ca_rtbb_allotment_struct_h -> h_ca_event);
	CO_Rtv_DataString(p_param_data,"ALLOT_DT",p_ca_rtbb_allotment_struct_h -> h_allot_dt);
	CO_Rtv_DataDbl(p_param_data,"ALLOTED_QTY",&(p_ca_rtbb_allotment_struct_h -> h_alloted_qty));
	CO_Rtv_DataDbl(p_param_data,"ADD_ALLOT_QTY",&(p_ca_rtbb_allotment_struct_h -> h_add_allot_qty));
	CO_Rtv_DataDbl(p_param_data,"AMT_PAY",&(p_ca_rtbb_allotment_struct_h -> h_amt_pay));
	CO_Rtv_DataDbl(p_param_data,"AMT_REC",&(p_ca_rtbb_allotment_struct_h -> h_amt_rec));
	CO_Rtv_DataString(p_param_data,"TYPEOF_INFO",p_ca_rtbb_allotment_struct_h -> h_typeof_info);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ca_rtbb_allotment_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKET_DT",p_ca_rtbb_allotment_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_ca_rtbb_allotment_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_ca_rtbb_allotment_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ca_rtbb_allotment_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"STATUS",p_ca_rtbb_allotment_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"DEPO_CODE",p_ca_rtbb_allotment_struct_h -> h_depo_cd);
	CO_Rtv_DataString(p_param_data,"DP_ID",p_ca_rtbb_allotment_struct_h -> h_dp_id);
	CO_Rtv_DataString(p_param_data,"DEPO_CLN_ID",p_ca_rtbb_allotment_struct_h -> h_cln_id);
	/* Added By Chirag For RT 23-01-2007 */	
	CO_Rtv_DataDbl(p_param_data,"AMT_PAYABLE",&(p_ca_rtbb_allotment_struct_h -> h_amt_payable));
	CO_Rtv_DataDbl(p_param_data,"ADDQTY_APP",&(p_ca_rtbb_allotment_struct_h -> h_addqty_app));
	CO_Rtv_DataDbl(p_param_data,"APPLIED_QTY",&(p_ca_rtbb_allotment_struct_h -> h_applied_qty));
	CO_Rtv_DataString(p_param_data,"ORIG_DEPO_CD",p_ca_rtbb_allotment_struct_h -> h_orig_depo_cd);
	/* Added By Chirag For RT 23-01-2007 */	
   
	APL_IF_DEBUG
		{
			 printf("CORP ID = |%s|\n",p_ca_rtbb_allotment_struct_h->h_corp_id);
			 printf("CLIENT = |%s|\n",p_ca_rtbb_allotment_struct_h->h_cln_code);
			 printf("CA_EVENT = |%s|\n",p_ca_rtbb_allotment_struct_h->h_ca_event);
			 printf("ALLOT_DT = |%s|\n",p_ca_rtbb_allotment_struct_h->h_allot_dt);
			 printf("ALLOTED_QTY = |%lf|\n",p_ca_rtbb_allotment_struct_h->h_alloted_qty);
			 printf("ADD_ALLOT_QTY = |%lf|\n",p_ca_rtbb_allotment_struct_h->h_add_allot_qty);
			 printf("AMT_PAY = |%lf|\n",p_ca_rtbb_allotment_struct_h->h_amt_pay);
			 printf("AMT_REC = |%lf|\n",p_ca_rtbb_allotment_struct_h->h_amt_rec);
			 printf("TYPEOF_INFO = |%s|\n",p_ca_rtbb_allotment_struct_h->h_typeof_info);
			 printf("STATUS = |%s|\n",p_ca_rtbb_allotment_struct_h->h_status);
			 printf("MAKER = |%s|\n",p_ca_rtbb_allotment_struct_h->h_maker);
			 printf("MAKER_DT = |%s|\n",p_ca_rtbb_allotment_struct_h->h_maker_dt);
			 printf("CHECKER = |%s|\n",p_ca_rtbb_allotment_struct_h->h_checker);
			 printf("CHECKER_DT = |%s|\n",p_ca_rtbb_allotment_struct_h->h_checker_dt);
			 printf("ACCESS_STAMP = |%s|\n",p_ca_rtbb_allotment_struct_h->h_access_stamp);
			 printf("DEPO_CODE = |%s|\n",p_ca_rtbb_allotment_struct_h->h_depo_cd);
			 printf("DP_ID = |%s|\n",p_ca_rtbb_allotment_struct_h->h_dp_id);
			 printf("CLN_ID = |%s|\n",p_ca_rtbb_allotment_struct_h->h_cln_id);
			 
           }
		APL_GOBACK_SUCCESS 
		RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_RTBB_ALLOTMENT \n",NULL,NULL);
        return 0;

		/** 
		RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_RTBB_ALLOTMENT \n",NULL,NULL);
        return 1;
 **/
		

}

/*Added by Chirag on HDFCCA_010 & 007 for CA_RTBB_Allotment*/




int Populate_CA_PUTCALL_APP(CA_PUTCALL_APP_STRUCT_H *p_ca_putcall_app_struct_h,char * p_param_data)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

    CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_PUTCALL_APP \n",NULL,NULL);


	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_ca_putcall_app_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_data,"CLN_CODE",p_ca_putcall_app_struct_h -> h_cln_code);
	CO_Rtv_DataString(p_param_data,"NOTICE_DATE",p_ca_putcall_app_struct_h -> h_notice_date);
	CO_Rtv_DataString(p_param_data,"INSTR_TYPE",p_ca_putcall_app_struct_h -> h_instr_type);
	CO_Rtv_DataString(p_param_data,"VALUE_DATE",p_ca_putcall_app_struct_h -> h_value_date);
	CO_Rtv_DataDbl(p_param_data,"AVL_QTY",&(p_ca_putcall_app_struct_h -> h_avl_qty));
	CO_Rtv_DataDbl(p_param_data,"PUT_CALL_QTY",&(p_ca_putcall_app_struct_h -> h_put_call_qty));
	CO_Rtv_DataDbl(p_param_data,"PUT_CALL_VALUE",&(p_ca_putcall_app_struct_h -> h_put_call_value));
	CO_Rtv_DataDbl(p_param_data,"PUT_CALL_RATE",&(p_ca_putcall_app_struct_h -> h_put_call_rate));
	CO_Rtv_DataString(p_param_data,"STATUS",p_ca_putcall_app_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"MAKER",p_ca_putcall_app_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ca_putcall_app_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ca_putcall_app_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_ca_putcall_app_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_ca_putcall_app_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"INFO_SEQ",p_ca_putcall_app_struct_h -> h_info_seq);
	CO_Rtv_DataString(p_param_data,"PYMT_SEND_MSG_IND",p_ca_putcall_app_struct_h -> h_pymt_send_msg_ind);
	CO_Rtv_DataString(p_param_data,"PROCESSED_DATE",p_ca_putcall_app_struct_h -> h_processed_date);
	CO_Rtv_DataString(p_param_data,"R_CORP_ID",p_ca_putcall_app_struct_h -> h_r_corp_id);

     APL_IF_DEBUG
		{
			 printf("INSTR_CODE = |%s|\n",p_ca_putcall_app_struct_h->h_instr_code);
			 printf("CLN_CODE = |%s|\n",p_ca_putcall_app_struct_h->h_cln_code);
			 printf("NOTICE_DATE = |%s|\n",p_ca_putcall_app_struct_h->h_notice_date);
			 printf("INSTR_TYPE = |%s|\n",p_ca_putcall_app_struct_h->h_instr_type);
			 printf("VALUE_DATE = |%s|\n",p_ca_putcall_app_struct_h->h_value_date);
			 printf("AVL_QTY = |%lf|\n",p_ca_putcall_app_struct_h->h_avl_qty);
			 printf("PUT_CALL_QTY = |%lf|\n",p_ca_putcall_app_struct_h->h_put_call_qty);
			 printf("PUT_CALL_VALUE = |%lf|\n",p_ca_putcall_app_struct_h->h_put_call_value);
			 printf("PUT_CALL_RATE = |%lf|\n",p_ca_putcall_app_struct_h->h_put_call_rate);
			 printf("STATUS = |%s|\n",p_ca_putcall_app_struct_h->h_status);
			 printf("MAKER = |%s|\n",p_ca_putcall_app_struct_h->h_maker);
			 printf("MAKER_DT = |%s|\n",p_ca_putcall_app_struct_h->h_maker_dt);
			 printf("CHECKER = |%s|\n",p_ca_putcall_app_struct_h->h_checker);
			 printf("CHECKER_DT = |%s|\n",p_ca_putcall_app_struct_h->h_checker_dt);
			 printf("ACCESS_STAMP = |%s|\n",p_ca_putcall_app_struct_h->h_access_stamp);
			 printf("INFO_SEQ = |%s|\n",p_ca_putcall_app_struct_h->h_info_seq);
			 printf("PYMT_SEND_MSG_IND = |%s|\n",p_ca_putcall_app_struct_h->h_pymt_send_msg_ind);
			 printf("PROCESSED_DATE = |%s|\n",p_ca_putcall_app_struct_h->h_processed_date);
			 printf("R_CORP_ID = |%s|\n",p_ca_putcall_app_struct_h->h_r_corp_id);
        }
		APL_GOBACK_SUCCESS 
		RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_PUTCALL_APP \n",NULL,NULL);
        return 0;

		/** 
		RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_PUTCALL_APP \n",NULL,NULL);
        return 1;
**/
}
