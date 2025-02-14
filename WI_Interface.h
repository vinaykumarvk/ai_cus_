/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *
 *    These materials are confidential and proprietary to
 *    Polaris Software Lab Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
/***********************************************************************************
 *
 * Module Name         :  Maintenence
 *
 * File Name           :  WI_Interface.h
 *
 * Description         :  Contains Structure Definitions for all WIM modules							
 *
 *
 *            Version Control Block
 *
 * Date        Version         Author          Description        RFS No.
 * ---------   --------  ---------------  -------------------    ----------
 *27/03/2007      1.0          Jiger 			New File
 *
 *29/11/2011      1.1       Mangesh       Web alleged deal Enh   ISKB_4837
***********************************************************************************/


#ifndef MT_HEADER_INCLUDED
#define MT_HEADER_INCLUDED
#endif
#ifndef IDL_DOUBLERR_USED
#define IDL_DOUBLERR_USED
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef COMMON_INTERFACEHEADER_INCLUDED
#include <Intellect_Interface.h>
#endif

#include "WI_CO_LenConstdef.h"
#include "WI_CO_IndStructdef.h"
#include "Intellect_Common.h"
#include "Intellect_Error.h"
#include "CR_Common.h"
#include "CO_Commdef.h"
#include "Intellect_Interface.h"

#define DATA_FIELD_SEPRTR           ''
#define DATA_VALUE_SEPRTR           ''

/*Code Added by amitk 05-03-2007*/
 typedef struct{
        char h_client[WI_CLIENT_LEN];
        char h_identiy_no[WI_IDENTIY_NO_LEN];
        char h_deal_cd[WI_DEAL_CD_LEN];
        char h_instr_code[WI_INSTR_CODE_LEN];
        char h_instr_name[WI_INSTR_NAME_LEN];
        double h_qty;
        char h_exch_code[WI_EXCH_CODE_LEN];
        char h_deal_date[APL_DATE_LEN];
        double h_cost;
        char h_setl_date[APL_DATE_LEN];
        double h_net_amt;
        char h_mkt_type[WI_MKT_TYPE_LEN];
        double h_brokercomm;
        double h_stx_comm;
        char h_domestic_cpclt[WI_DOMESTIC_CPCLT_NAME_LEN];
        char h_domestic_cpclt_name[WI_DOMESTIC_CPCLT_NAME_LEN];
        char h_clh_flag[WI_CLH_FLAG_LEN];
        char h_fx_reqd[WI_FX_REQD_LEN];
        char h_maker[WI_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[WI_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_deal_stat[WI_DEAL_STAT_LEN];
        char h_proc_flag[WI_PROC_FLAG_LEN];
        char h_access_stamp[APL_DATE_LEN];
	double h_gross_rate; /* JC - 21-04-2007 */
	char h_contract_cd[WI_CONTRACT_CD_LEN];  /* Added by Mangesh for Web alleged deal creation Enh*/
	char h_setl_exch_code[WI_EXCH_CODE_LEN]; //12174
	double h_stamp_duty;
}WI_DEAL_STRUCT_H;
/*Code Added by amitk 05-03-2007*/

/* JC - RFS_CA_020 -- Start */
typedef struct{
        char h_corp_id[CA_CORP_ID_LEN];
        char h_instr_code[CA_INSTR_CODE_LEN];
        char h_cln_code[CA_CLN_CODE_LEN];
        char h_ca_event[CA_CA_EVENT_LEN];
        char h_instruc_date[APL_DATE_LEN];
        double h_inp_qty;
        double h_over_sub;
        char h_maker[CA_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[CA_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_access_stamp[APL_DATE_LEN];
        char h_instructed[CA_CA_EVENT_LEN];
	char h_status[3];
	double h_no_action;
	int h_num_of_resolutions;
}CA_INSTRUCTION_STRUCT_H;
/* JC - RFS_CA_020 -- End */

// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - Start
typedef struct{
        char h_client_code[WE_CLIENT_CODE_LEN];
        int h_serial_no;
        char h_input_date[APL_DATE_LEN];
        char h_information[WE_INFORMATION_LEN];
        char h_maker[WE_MAKER_LEN];
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[WE_CHECKER_LEN];
        char h_checker_dt[APL_DATE_LEN];
        char h_access_stamp[APL_DATE_LEN];
        char h_status[WE_STATUS_LEN];
}WI_WEB_MANUAL_MSG_STRUCT_H;

// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - End

//Added For PMS - Start

 typedef struct{
        char h_sell_client[WI_CLIENT_LEN];
        char h_buy_client[WI_CLIENT_LEN];
        char h_instr_isin[13];
        char h_deal_date[APL_DATE_LEN];
        double h_qty;
        double h_cost;
        char h_domestic_cpclt[WI_DOMESTIC_CPCLT_NAME_LEN];
        char h_cpclt[WI_DOMESTIC_CPCLT_NAME_LEN];
        double h_origquantity;
        double h_amt;
        double h_net_amt;
        char h_clh_flg[DL_CLH_FLG_LEN];
        char h_ex_arena[3];
        char h_setldt[20];
        char h_dealcd[2];
        char h_access_stamp[20];
        char h_classofdl[3];
        char h_entry[2];
        char h_fx_reqd[2];
        char h_info1[261];
        char h_maker[15];
        char h_maker_dt[20];
        char h_checker[15];
        char h_checker_dt[20]; 
        char h_allow_part_s[2];
        char h_ispymtlocal[2];
        char h_reginstr_ind[2];
        char h_isspotdl[2];  
        char h_identiy_no[DL_IDENTIY_NO_LEN];  
	char h_trd_exch[4];
	char h_trd_mkt_type[4];
	char h_trd_setl_no[16];
	char h_payin_dt[APL_DATE_LEN];
	char h_payout_dt[APL_DATE_LEN];
}WI_DEAL_PMS_STRUCT_H;
//Added For PMS - End

