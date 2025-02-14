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
 * Module Name         :         WIM
 *
 * File Name           :         WI_CO_LenConstdef.h
 *
 * Description         :         Contains Structure Length Constants 
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author               Description       RFS No.
 * ---------   --------  ---------------  -------------------     ----------
 * 27/03/2007  1.0       Jiger             New file	
 * 29/11/2011  1.1       Mangesh         Web alleged enh          ISKB_4837		  
 *********************************************************************/

#define MT_INSTR_CODE_LEN			9
#define MT_CURRENCY_CD_LEN			4
#define MT_LOCATION_CD_LEN			5
#define MT_REG_BR_IND_LEN			3
#define MT_ALLOW_RF_LEN				2
#define MT_ALLOW_RVP_LEN			2
#define MT_ALLOW_DF_LEN				2
#define MT_ALLOW_DVP_LEN			2
#define MT_ORD_TYPE_LEN				2
#define MT_MOTHER_SEC_IND_LEN		2
#define MT_EX_ARENA_LEN				3
#define MT_LISTED_IND_LEN			2
#define MT_NEW_MAKER_LEN			15
#define MT_MAKER_LEN					15
#define MT_CHECKER_LEN				15
#define MT_STATUS_LEN				3
#define MT_NEW_ISSUE_LEN			2
#define MT_NEW_CHECKER_LEN			15
#define MT_CHNG_LST_IND_LEN		2
#define MT_CERT_OF_OWN_IN_LEN		2
#define MT_INSTR_NAME_LEN			131
#define MT_INSTR_ISIN_LEN			13
#define MT_TIPO_INV_LEN				3
#define MT_INSTR_TYPE_LEN			4
#define MT_INSTR_PARENT_LEN		9
#define MT_PROD_CLASS_LEN			3
#define MT_SEC_DL_CODE_LEN			4
#define MT_CLASSCD_LEN				5
#define MT_NEW_CD_LEN				9
#define MT_CHNG_ISIN_LEN			13
#define MT_CHG_MKR_LEN				15
#define MT_CA_NAME_LEN				61
#define MT_CHNG_CD_LEN				9
#define MT_INT_TYP_LEN				2
#define MT_FREQ_CODE_LEN			2
#define MT_INT_ACCTYP_LEN			2
#define MT_MOD_LAST_PAYDT_LEN		2
#define MT_TAXONMAT_IND_LEN		2
#define MT_DISCT_IND_LEN			2
#define MT_CA_ADDRDET_LEN			181
#define MT_INSTR_SHORTNM_LEN		16
#define MT_IPO_IND_LEN				2
#define MT_CMP_CODE_LEN				11
#define MT_INSTR_REG_CODE_LEN		11
#define MT_INSTR_SWF_NAME_LEN		21
#define MT_INSTR_PRIV_PLACED_LEN	2
#define MT_INSTR_CRISIL_CODE_LEN	7
#define MT_INSTR_IS_SECURED_LEN	2
#define MT_INSTR_PC_IND_LEN		2
#define MT_INSTR_PART_RD_FLG_LEN	2
#define MT_INSTR_RESET_FLG_LEN	2
#define MT_INSTR_IS_DEMAT_LEN		2
#define MT_INSTR_REMARK_LEN		101
#define MT_INSTR_ISIN_NAME_LEN	21
#define MT_INSTR_ATTACHED_LEN		9

#define MT_RD_CLIENT_ID_LEN		21
#define MT_RD_DP_ID_LEN				21
#define MT_RD_DEPO_CODE_LEN		21
#define MT_IPA_CODE_LEN				11

#define MT_EXCH_CODE_LEN			4
#define MT_SCRIP_GRP_LEN			3
#define MT_MKT_TYPE_LEN				3
#define MT_EXCH_INSTR_CODE_LEN	13
#define MT_LISTING_STATUS_LEN		4

#define MT_CR_AGENCY_CODE_LEN		9
#define MT_RATING_CODE_LEN			6

#define MT_PC_FLAG_LEN				2

#define MT_PTC_PAID_FLG_LEN		2


#define MT_SETTL_TYPE_LEN 3
#define MT_CC_ID_LEN 21
#define MT_NSDL_DEADLINE_TM_LEN 10
#define MT_SETTL_NO_LEN 12
#define MT_BENCHMARKCODE_LEN 11
#define MT_RBI_INSTR_CODE_LEN 21
#define MT_CARRY_FW_STLNO_LEN 12
#define MT_MIBOR_CODE_LEN 9
#define CO_CODE_IDENT_LEN 21
#define CO_CODE_VALUE_LEN 21
#define CO_CODE_DESC_LEN 41
#define CO_COUNTRY_CODE_LEN 3
#define MT_INDEX_FUND_NUM_LEN   4
#define MT_INDEX_FUND_NAME_LEN  51

/* Kouser - Depository Participant */

#define MT_DEPO_CODE_LEN 5
#define MT_DEPO_PART_CODE_LEN 21
#define MT_DEPO_PART_CONTACT1_LEN 66
#define MT_DEPO_PART_ADD_1_LEN 66
#define MT_DEPO_PART_ADD_2_LEN 66
#define MT_DEPO_PART_ADD_CITY_LEN 3
#define MT_DEPO_PART_ADD_STATE_LEN 3
#define MT_DEPO_PART_ADD_CNT_LEN 3
#define MT_DEPO_PART_ADD_PIN_LEN 11
#define MT_DEPO_PART_TEL_LEN 21
#define MT_DEPO_PART_FAX_LEN 21
#define MT_DEPO_PART_EMAIL_LEN 61


#define MT_CM_CC_ID_LEN 29
#define MT_CLN_ID_LEN 14
#define MT_DP_ID_LEN 21
/* Kouser - Depository Participant - HDFCMT */

/*Vaibhav - Allotment Constants - HDFCCA_015*/

#define CA_CORP_ID_LEN 21
#define CA_CLN_CODE_LEN 11
#define CA_CANREFNO_LEN 11
#define CA_BLOCKFLG_LEN 2
/*Vaibhav - Allotment Constants - HDFCCA_015*/


/* Pradeep - Party Master - HDFCMT_004 */
#define MT_PTY_CODE_LEN 11
#define MT_PTY_NAME_LEN 66
#define MT_PTY_SHORTNM_LEN 13
#define MT_PTY_MAPINID_LEN 13
#define MT_PTY_TYPE_LEN 2
#define MT_PTY_ADD1_LEN 61
#define MT_PTY_ADD2_LEN 61
#define MT_CITY_LEN 21
#define MT_STATE_LEN 21
#define MT_COUNTRY_LEN 21
#define MT_PTY_ADD_PIN_LEN 11
#define MT_PTY_TEL_LEN 21
#define MT_PTY_FAX_LEN 21
#define MT_PTY_EMAIL_LEN 61
#define MT_PTY_CONTACT1_LEN 66
#define MT_PTY_CONTACT2_LEN 66
#define MT_PTY_SWF_NAME_LEN 21
#define MT_PTY_SWF_ADD_LEN 12
#define MT_PTY_SEBI_REG_NO_LEN 21
#define MT_PTY_PAN_LEN 21
#define MT_PTY_LC_NAME_LEN 66
#define MT_PTY_LC_ADD_LEN 201
#define MT_PTY_LC_TEL_LEN 21
#define MT_PTY_LC_EMAIL_LEN 61
#define MT_PTY_LC_FAX_LEN 21
#define MT_PTY_EXCH_MAP_CODE_LEN 21
#define MT_PTY_CMBP_ID_LEN 21
#define MT_PTY_CCCM_ID_LEN 21
#define MT_DEPO_CODE_LEN 5
#define MT_PTY_DEPO_MAP_CLIENT_ID_LEN 21
#define MT_PTY_DEPO_MAP_DP_ID_LEN 21
#define MT_CLN_CODE_LEN 11
#define MT_PTY_EXCH_CLN_MAP_CODE_LEN 21
#define MT_PTY_BIC_CODE_LEN 14
/* Pradeep - Party Master - HDFCMT_004 */

/*Smita - Added Event Constants - HDFCCA_027*/
#define CA_CA_EVENT_LEN					3
#define CA_PRELIMINARY_FLAG_LEN		2
#define CA_CA_CURRENCY_LEN				4
#define CA_PROC_OTH_LEN					106
#define CA_OP_EVT_CLASS_LEN			3
#define CA_RESP_DT_OPND_LEN			2
#define CA_EXP_DT_OPEN_IND_LEN		2
#define CA_EVT_SEND_MSG_IND_LEN		2
#define CA_ENTL_SEND_MSG_IND_LEN		2
#define CA_PYMT_SEND_MSG_IND_LEN		2
#define CA_DISP_OF_FRACT_LEN		 	2
#define CA_RHTS_CLASS_LEN				2
#define CA_CONTACT_DETAILS_LEN		241
#define CA_INFO_SEQ_LEN				   9
#define CA_ENTITL_INFONO_LEN			9
#define CA_OVER_SUBSCRP_LEN			2
#define CA_DIVIDEND_TYPE_LEN			2
#define CA_NSER_E_INFO_LEN				9	
#define CA_NSER_B_INFO_LEN				9	
#define CA_COMP_INFO_A_LEN				9	
#define CA_INCO_INFO_A_LEN				9	
#define CA_WWWADDR_LEN					101
#define CA_TXNR_INFO_A_LEN				9	
#define CA_REQD_CERTIFY_LEN			2
#define CA_ALLOTMENT_LETTER_LEN		2
#define CA_REDEM_OPTION_LEN			4
#define CA_SEND_SPLIT_LEN				2
#define CA_INTEREST_TYPE_LEN			2
/*Added by Vaibhav HDFCCA_013*/
#define CA_BK_BUILD_IND_LEN 2
#define CA_ATTACH_CORP_ID_LEN 21
#define CA_SOURCE_LEN 2
#define CA_LEAD_MGR_LEN 106
#define CA_SYND_MEMBR_LEN 106
#define CA_CO_MGR_LEN 106
/*Smita - Added Event Constants - HDFCCA_027*/

/* HDFCMT_GFU - Vendor Maintenance - Sundar */
#define MT_VENDOR_CODE_LEN 11
#define MT_VENDOR_NAME_LEN 66
#define MT_ADD_LINE1_LEN 61
#define MT_ADD_LINE2_LEN 61
#define MT_COUNTRY_CODE_LEN 21
#define MT_STATE_CODE_LEN 21

#define MT_CITY_CODE_LEN 21
#define MT_PIN_CODE_LEN 11
#define MT_FAX_NO_LEN 21
#define MT_TEL_NO_LEN 21
#define MT_WEB_ADDRESS_LEN 61
#define MT_MAKER_LEN 15
#define MT_CHECKER_LEN 15
#define MT_VENDOR_ID_LEN 11
#define MT_FUNCTION_ID_LEN 51
#define MT_FILE_TYPE_LEN 4
#define MT_COPY_EXIST_LEN 2
#define MT_DELIMETER_LEN 2
#define MT_EXCEL_REF_TYPE_LEN 2
#define MT_REF_NO_LEN 13
#define MT_REF_NO_LEN 13
#define MT_EXCEL_FIELD_NAME_LEN 21
#define MT_EXCEL_REFERENCE_VALUE_LEN 41
#define MT_MAKER_LEN 15
#define MT_CHECKER_LEN 15
#define MT_REF_NO_LEN 13
#define MT_TXT_FIELD_NAME_LEN 21
#define MT_MAKER_LEN 15
#define MT_CHECKER_LEN 15
#define MT_REF_NO_LEN 13
#define MT_CSV_FIELD_NAME_LEN 21
#define MT_CSV_REFERENCE_VALUE_LEN 21
#define MT_MAKER_LEN 15
#define MT_CHECKER_LEN 15
/* HDFCMT_GFU - Vendor Maintenance - Sundar */
/* changes by bageshri for 10G migration */
#define C_COMMITSIZE             25
#define COMMITSIZE               25
/* Kouser - KB_001 - Client Additional Details */

#define MT_CERT_PUB_ACC_LEN 11
#define MT_FUND_ACC_MGR_LEN 11
#define MT_SPF_FLG_LEN 2
#define MT_SPF_DET_LEN 201
/*CHITRLEKHA Client Additional Details*/
#define MT_SEC_CERT_PUB_ACC_LEN 11 
#define MT_FATCA1 2 
#define MT_FATCA2 2 
#define MT_FATCA3 2 
/*CHITRLEKHA Client Additional Details*/
/* Kouser - KB_001 - Client Additional Details */

/*****************************************/

/*********************************************************************************************/
#define DL_IS_NODELV_LEN 2 /* vinay */
#define DL_ORDER_DATA_LEN 501 /* vinay */

#define DL_SETTLEMENT_NO_LEN 16
/* #define DL_MKT_TYPE_LEN 4 */
#define DL_CLH_FLG_LEN 2
#define DL_CONTRACT_REQ_LEN 2
#define DL_EXCUM_FLG_LEN 2
#define DL_CRN_NO_LEN 17
#define DL_INTERFII_FLG_LEN 2
#define DL_PAY_MODE_LEN 2
#define DL_DL_SECSTATUS_LEN 3
#define DL_DL_MNYSTATUS_LEN 3
#define DL_CLN_DEPOACC_LEN 11
#define DL_PLTOPL_FLG_LEN 2
#define DL_ORIG_STATUS_LEN 3
#define DL_MAP_FAILCODE_LEN 4
#define DL_MATCH_FAILCODE_LEN 4
#define DL_IS_MATCHED_LEN 2
#define DL_IDENTIY_NO_LEN 17
/* #define DL_DEAL_CD_LEN 2 */
#define DL_INSTR_CODE_LEN 9
#define DL_CURRENCY_CD_LEN 4
#define DL_DOMESTIC_CPCLT_LEN 11
#define DL_DL_CLASS_LEN 3
#define DL_EX_ARENA_LEN 3
#define DL_SPOTTRD_IND_LEN 2
#define DL_ENTRY_LEN 2
#define DL_DEAL_STAT_LEN 3
#define DL_DOMCP_CUSTODYCLT_LEN 11
#define DL_CP_CLT_LEN 11
#define DL_CP_CLTNAME_LEN 66
#define DL_CLIENTOF_LEN 66
#define DL_INFO1_LEN 261
#define DL_FX_REQD_LEN 2
#define DL_LOCATION_CD_LEN 5
#define DL_STATUS_POS_LEN 4
#define DL_INSTR_NAME_LEN 121
#define DL_CLT_NAME_LEN 66
#define DL_DOMESTICCP_NAME_LEN 66
#define DL_BRK_NO_LEN 13
#define DL_GL_CLIENT_LEN 11
#define DL_PARTIAL_IND_A_LEN 2
#define DL_INSTRUCT_PERSON_LEN 36
#define DL_CLIENTOF_CD_LEN 11
#define DL_INTER_MED_PERSON_LEN 36
#define DL_INTER_MED_PERSONNM_LEN 66
#define DL_FXCCY_LEN 4
#define DL_LCL_IDENTNO_LEN 17
#define DL_UNIQ_IDENT_NO_LEN 15
#define DL_RELATED_IDENT_NO_LEN 21
#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_MSG_IN_OUT_IND_LEN 2
#define DL_SWIFT_MSG_NO_LEN 7
#define DL_INFORMATION_LEN 31
#define DL_MESSAGE_DET_A_LEN 2001
#define DL_MESSAGE_DET_B_LEN 2001
#define DL_MESSAGE_DET_C_LEN 2001
#define DL_MESSAGE_DET_D_LEN 2001
#define DL_MESSAGE_DET_E_LEN 2001
#define DL_PSETPARTY_LEN 161
#define DL_PLACE_CD_LEN 5
#define DL_NARRATIVE_LEN 41
#define DL_IDENTIY_NO_LEN 17
#define DL_TRAIL_FOR_LEN 2
#define DL_TASK_DESC_LEN 61
#define DL_PROC_USR_LEN 15
#define DL_SUBPROCESS_LEN 4
#define DL_FAILREASON_CD_LEN 3
#define DL_DEAL_FRM_ORD_LEN 2
#define DL_SEQUENCE_NAME_LEN 6
#define DL_LINK_VAL_LEN 6
#define DL_LINK_TAG_LEN 51
#define DL_MSG_TAG_LEN 6
#define PR_SEQUENCE_NAME_LEN 21
#define PR_RECYCLE_IND_LEN 2
#define PR_SEQ_ATTRB_A_LEN 21
#define PR_SEQ_ATTRB_B_LEN 21
#define PR_SEQ_ATTRB_C_LEN 21
/**********************************************************************************************/
/******************DL_BIFDET*********************************/
#define DL_CLIENT_LEN 11
#define DL_IDENTIY_NO_LEN 17
#define DL_DP_ID_LEN 21
/*****************BCN CHGS ****************************/
#define DL_CONTRACT_CD_LEN 17
#define DL_MKT_TYPE_LEN 4
#define DL_TRAN_TYPE_LEN 4
#define DL_EXCH_CD_LEN 4
#define DL_DEAL_CD_LEN 3
#define DL_CLH_FLG_LEN 2
#define DL_SEBI_REG_NO_LEN 21
#define DL_BROKER_CD_LEN 11
#define DL_CLIENT_CD_LEN 11
#define DL_INSTR_CD_LEN 9
#define DL_SETTLEMENT_NO_LEN 16
#define DL_DL_REF_NO_LEN 17
#define DL_INTER_FII_FLG_LEN 2
#define DL_SEBI_REPORTED_LEN 2
#define DL_ENTRY_LEN 2
#define DL_REPAIRED_IND_LEN 2
#define DL_STATUS_LEN 3
#define DL_NARRATIVE_LEN 41

/* added by amish-takeover */
#define DL_REF_NO_LEN 17
#define DL_CI_NO_LEN 17
#define DL_INSTR_CD_LEN 9
#define DL_PHY_FLG_LEN 2
#define DL_DEPOSITORY_LEN 11
#define DL_STATUS_LEN 3
#define DL_COMMENTS_LEN 81
/* added by amish takeover */
/******************************** SQoff details - sundar **********************/
#define DL_EXCH_CODE_LEN 4
#define DL_SETTLEMT_NO_LEN 16
#define DL_DL_REF_NO_LEN 17
#define DL_CLN_CODE_LEN 11
#define DL_SQOFF_REF_NO_LEN 17
#define DL_INSTR_CODE_LEN 9
#define DL_BANK_CODE_LEN 15
#define DL_CHQ_NO_LEN 25
#define DL_CA_REF_NO_LEN 17
#define DL_STATUS_LEN 3

/******************************** SQoff details - sundar **********************/

/*Manik Trivedi : HDFCDL_005 */
#define DL_ORDER_NO_LEN 26
#define DL_EXCHG_CODE_LEN 4
#define DL_CLN_CODE_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_BROKER_CD_LEN 11
#define DL_SETTL_NO_LEN 12
/* #define DL_MKT_TYPE_LEN 3 */
#define DL_SCRIP_GRP_LEN 4
#define DL_CREATION_TYPE_LEN 2
#define DL_DEAL_REF_NO_LEN 17
#define DL_BUY_SELL_FLG_LEN 2
#define DL_MATCHED_LEN 2
#define DL_STATUS_LEN 3
#define DL_CHECKER_LEN 15
#define DL_MAKER_LEN 15

/* Manik Trivedi, HDFCDL_024 */

#define DL_TRANSFER_REF_NO_LEN 11
#define DL_FROM_CLIENT_LEN 11
#define DL_TO_CLIENT_LEN 11
#define DL_CUSTODY_INTERNAL_LEN 2
#define DL_CP_CUSTO_LEN 11
#define DL_CP_DP_ID_LEN 21
#define DL_CP_CLIENT_ID_LEN 11
#define DL_INSTR_CODE_LEN 9
#define DL_DEPO_CODE_LEN 11
#define DL_BLK_REF_NO_LEN 11
#define DL_CUSTO_REF_NO_LEN 21

#define DL_BLK_TYPE_LEN 2
#define DL_REMARKS_LEN 201

/*Vaibhav CA_APPLICATION*/
#define CA_REMARK_LEN 106
#define CA_DEPO_CLN_ID_LEN 21
#define CA_CLN_REFNO_LEN 21
/*Vaibhav CA_APPLICATION*/

/*Added by Chirag HDFCCA_010_007 for CA_RTBB_Allotment*/
#define CA_TYPEOF_INFO_LEN 11
/*Added by Chirag HDFCCA_010_007 for CA_RTBB_Allotment*/

/* JC - RFS_CA_020 Client Instruction -- Start */
#define CA_MAKER_LEN 15
#define CA_CHECKER_LEN 15
#define CA_INSTR_CODE_LEN 9
/* JC - RFS_CA_020 Client Instruction -- End */

/**added by sundar--pre match***/
#define DL_DL_CLIENT_LEN 11
#define DL_DL_REF_NO_LEN 17
#define DL_BROKER_DPID_LEN 21
/* changes by amish --13/05 */
#define DL_BROKER_CMBPID_LEN 42
#define DL_CP_DPID_LEN 21
#define DL_CP_CLNID_LEN 21
#define DL_GENDP_FLG_LEN 2

/*** Pool Account DUMP Maintenance *********/

#define DL_BENEF_ACCTYPE_LEN 7

/* #define DL_MKT_TYPE_LEN 3 */
#define DL_SETTLEMT_NO_LEN 16
#define DL_BL_LC_CODE_LEN 2
#define DL_STATUS_LEN 3
#define DL_INSTR_CODE_LEN 9
/*** Pool Account DUMP Maintenance *********/

/* For new field EXCH_INSTR_CODE for table DL_EXCHGORD_UPLD - Rahul*/
#define DL_EXCH_INSTR_CODE_LEN 13
 /*Added by amitk for Web module on 06-03-2007*/
#define WI_CLIENT_LEN 11
#define WI_IDENTIY_NO_LEN 17
#define WI_DEAL_CD_LEN 2
#define WI_INSTR_CODE_LEN 13
#define WI_INSTR_NAME_LEN 131
#define WI_EXCH_CODE_LEN 4
#define WI_MKT_TYPE_LEN 4
#define WI_DOMESTIC_CPCLT_LEN 11
#define WI_DOMESTIC_CPCLT_NAME_LEN 70
#define WI_CLH_FLAG_LEN 2
#define WI_FX_REQD_LEN 2
#define WI_MAKER_LEN 15
#define WI_CHECKER_LEN 15
#define WI_DEAL_STAT_LEN 3
#define WI_PROC_FLAG_LEN 2
 /*Added by amitk for Web module on 06-03-2007*/
#define WI_CONTRACT_CD_LEN 17  /* Added by Mangesh for Web alleged deal creation */

// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - Start
#define WE_CLIENT_CODE_LEN 11
#define WE_INFORMATION_LEN 4001
#define WE_MAKER_LEN 15
#define WE_CHECKER_LEN 15
#define WE_STATUS_LEN 3
// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - End

