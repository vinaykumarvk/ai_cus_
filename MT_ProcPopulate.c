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
 * Module Name         :			Maintenance
 *
 * File Name           :			MT_ProcPopulate.c
 *
 * Description         :			This file populates the structure depending
	*										on the maintenance functions.
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author           Description							RFS No.
 * ---------   --------	 ---------------  -----------------------				--------
 * 10/10/2005	1.2			Smita Bhat		Added new functions to populate	HDFCMT_003
 *														Instrument Related Data					
 *
 * 10/11/2005	1.4			ANIL				Added new functions to populate	HDFCMT_002,HDFCMT_005,HDFCMT_006
 * 													Company,ClientInstrument & 
 * 													InstructionSlip related Data.
 * 14/14/2005   1.5         Manik Trivedi   New Funtion for Settlement Calender HDFCMT_008									
 * 20/12/2005   1.6        Dnyanesh        New Funtion for Daily Float Rate	HDFCMT_012									
 * 21/12/2005   1.7        Dnyanesh        New Funtion for RBI Monetarye		HDFCMT_014									
 * 22/12/2005   1.8        Dnyanesh        New Funtion for No Delivery		HDFCMT_007									
 * 26/12/2005   1.10        Sonali        New Funtion for Float rate Instrument		HDFCMT_013									
 * 26/12/2005   1.11        Sonali        New Funtion for Static Master		HDFCMT_016									
 * 03/01/2005	1.12		Smita Bhat	 Changes related to Instrument		HDFCMT_003
 * 15/12/2005	1.6         Kouser Begum      Added new functions to populate Client Related    HDFCMT_001                      
 * 	                                      Data. 
 * 10/01/2006	1.14			Pradeep			New functions for Index Fund Master	HDFCMT_017	
 * 30/12/2005   1.15        Kouser Begum          New Function for Depository Participant       HDFCMT_010 
 * 26/12/2005   1.16        Kouser Begum          New Function for Credit Rating Agency         HDFCMT_011    
 * 06/01/2006   1.17			Pradeep  		New Functions for Party Master			HDFCMT_004 
 * 07/01/2006   1.16        Sundar          New Funtion for Vendor Maintenance HDFCMT_GFU
 * 08/02/2006	 1.17			Smita Bhat			Chgs related to column names			HDFCCA_BaseVer
 * 21/02/2006   1.20       Kouser Begum      New Maintenance                     KB_001
 * AIX - Warnings Removal---  Commented the RETURN FAILURE and added APL_GOBACK_SUCCESS 13032010
 *********************************************************************/
 
#include "MT_Interface.h"
#include "Intellect_Common.h"

int	MT_Proc_ClientPopulate(MT_CLIENT_STRUCT_H *p_AccStruct,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
       CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_AccStruct->h_dl_client);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CURRENCY",p_AccStruct->h_currencycode);
         CO_Rtv_DataString(chr_p_param_str,"CLN_OUR_THEIR_IND",p_AccStruct->h_our_their_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_ISCC_IND",p_AccStruct->h_iscc_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_USE_ISIN_IND",p_AccStruct->h_instr_isinuseflg);
         CO_Rtv_DataString(chr_p_param_str,"CLN_TYPE",p_AccStruct->h_clnt_class);
         printf("Val of Client Class ==%s\n",p_AccStruct->h_clnt_class);

         CO_Rtv_DataString(chr_p_param_str,"CLN_REG_NAME",p_AccStruct->h_regclr_name);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CLAS",p_AccStruct->h_clt_class);
         CO_Rtv_DataString(chr_p_param_str,"CLN_BILLABLEIND",p_AccStruct->h_billableflag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CLASS",p_AccStruct->h_classofclt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_VTB_CLIENT",p_AccStruct->h_vtbclient);
         CO_Rtv_DataString(chr_p_param_str,"CLN_REG",p_AccStruct->h_cltreg);
         CO_Rtv_DataString(chr_p_param_str,"CLN_MEMO",p_AccStruct->h_cltmemo);
         CO_Rtv_DataString(chr_p_param_str,"CLN_INTERNAL",p_AccStruct->h_internal_clt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_POS_DT",p_AccStruct->h_posdt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_BASE_ID",p_AccStruct->h_base_id);
         CO_Rtv_DataInt(chr_p_param_str,"CLN_COUNT_SWF_MON",&(p_AccStruct->h_count_swf_mon));
         CO_Rtv_DataInt(chr_p_param_str,"CLN_COUNT_TLX_MON",&(p_AccStruct->h_tlxmonth_cnt));
         CO_Rtv_DataInt(chr_p_param_str,"CLN_COUNT_SWF_YR",&(p_AccStruct->h_count_swf_yr));
         CO_Rtv_DataInt(chr_p_param_str,"CLN_COUNT_TLX_YR",&(p_AccStruct->h_tlxyr_cnt));
         CO_Rtv_DataString(chr_p_param_str,"CLN_MASTER",p_AccStruct->h_mstclt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_NAME",p_AccStruct->h_clnt_clr_name);
         CO_Rtv_DataString(chr_p_param_str,"CLN_GL_ACCOUNT",p_AccStruct->h_ibbsclient);
         CO_Rtv_DataString(chr_p_param_str,"CLN_BRK_ALL",p_AccStruct->h_clt_brk_all);
         CO_Rtv_DataString(chr_p_param_str,"CLN_SHORTNM",p_AccStruct->h_shortclr_name);
         CO_Rtv_DataString(chr_p_param_str,"CLN_ORD_CLT",p_AccStruct->h_ord_clt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_SPOT_DL_IND",p_AccStruct->h_spotdlflg);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FX_SELL_IND",p_AccStruct->h_fx_sell_flag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FX_BUY_IND",p_AccStruct->h_fx_buy_flag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FX_INC_IND",p_AccStruct->h_fx_inc_flag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_DATEOF_INPUT",p_AccStruct->h_newdt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_BRNCHCODE",p_AccStruct->h_brnchcode);
         CO_Rtv_DataString(chr_p_param_str,"COUNTRY",p_AccStruct->h_nationcode);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FMT_RPTIND",p_AccStruct->h_fmt_rptflag);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",p_AccStruct->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_AccStruct->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_AccStruct->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_AccStruct->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_AccStruct->h_checker_dt);
         CO_Rtv_DataString(chr_p_param_str,"CLN_UNIQ_GCUSTODY_ID",p_AccStruct->h_uniq_gcustody_id);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CLTPROD_CD",p_AccStruct->h_cltprdcd);
         CO_Rtv_DataString(chr_p_param_str,"CLN_DOMICILE",p_AccStruct->h_domestic);
         CO_Rtv_DataString(chr_p_param_str,"CLN_PARTIAL_IND",p_AccStruct->h_part_flg);
         CO_Rtv_DataString(chr_p_param_str,"CLN_ALLOW_REGIND",p_AccStruct->h_allow_regflag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_REG_SETL_IND",p_AccStruct->h_regsetlflg);
         CO_Rtv_DataString(chr_p_param_str,"CLN_REG_BCL_IND",p_AccStruct->h_reg_bcl_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_STATUS",p_AccStruct->h_clt_status);
         CO_Rtv_DataString(chr_p_param_str,"CLN_CLH",p_AccStruct->h_clhclient);
         CO_Rtv_DataString(chr_p_param_str,"CLN_TAXABLE_IND",p_AccStruct->h_taxable_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_BRK_CD",p_AccStruct->brk_cd);
         CO_Rtv_DataString(chr_p_param_str,"CLN_TAX_ID",p_AccStruct->h_tax_id);
         CO_Rtv_DataString(chr_p_param_str,"CLN_ADD_1",p_AccStruct->h_contactinfo);
         CO_Rtv_DataString(chr_p_param_str,"CLN_EXT_CLH",p_AccStruct->h_extclhclient);
         CO_Rtv_DataString(chr_p_param_str,"CLN_GRP",p_AccStruct->h_clt_grp);
         CO_Rtv_DataString(chr_p_param_str,"CLN_SAT_OPER_CD",p_AccStruct->h_sat_oper_cd);
         CO_Rtv_DataInt(chr_p_param_str,"CLN_TOLERANCE",&(p_AccStruct->h_tolerance_val));
         CO_Rtv_DataString(chr_p_param_str,"CLN_AUTHBUNCH_IND",p_AccStruct->h_authbunch_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FX_BUY_CCY",p_AccStruct->h_fxpurchasecurrency);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FX_SELL_CCY",p_AccStruct->h_fxsalecurrency);
         CO_Rtv_DataString(chr_p_param_str,"CLN_SINGLE548_SUPPORT_IND",p_AccStruct->h_single548_support_ind);
         CO_Rtv_DataString(chr_p_param_str,"CLN_STAT_DL_IND",p_AccStruct->h_stat_tran_flag);
	      CO_Rtv_DataString(chr_p_param_str,"CLN_DEAL_SETL_IND",p_AccStruct->h_trad_sett_flag);
         CO_Rtv_DataString(chr_p_param_str,"CLN_RHTS_RET",p_AccStruct->h_rhts_ret);
         CO_Rtv_DataString(chr_p_param_str,"CLN_VALCREDIT",p_AccStruct->h_valcredit);
         CO_Rtv_DataString(chr_p_param_str,"CLN_FRACT_IND",p_AccStruct->h_keep_fracredit_flag); 
         CO_Rtv_DataString(chr_p_param_str,"CLN_AUTO_CANC_IND",p_AccStruct->h_auto_canc_ind); 
	      CO_Rtv_DataString(chr_p_param_str,"CLN_DESC",p_AccStruct->h_cltdetail);
         CO_Rtv_DataString(chr_p_param_str,"CLN_GENERATE_IND",p_AccStruct->h_generate_flag);	
         /* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */
			
	        CO_Rtv_DataString(chr_p_param_str,"CLN_ADD_2",p_AccStruct->h_cln_add_2);	
	        CO_Rtv_DataString(chr_p_param_str,"CITY",p_AccStruct->h_cln_add_city);	
		     CO_Rtv_DataString(chr_p_param_str,"STATE",p_AccStruct->h_cln_add_state);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_ADD_PIN",p_AccStruct->h_cln_add_pin);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_TEL",p_AccStruct->h_cln_tel);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_FAX",p_AccStruct->h_cln_fax);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_EMAIL",p_AccStruct->h_cln_email);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_CONTACT1",p_AccStruct->h_cln_cntact1);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_CONTACT2",p_AccStruct->h_cln_cntact2);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_SEBICTG",p_AccStruct->h_cln_sebi_ctg);	
	 		  CO_Rtv_DataString(chr_p_param_str,"CLN_PAN",p_AccStruct->h_cln_pan);	
	 	     CO_Rtv_DataDbl(chr_p_param_str,"CLN_TDS_RT",&(p_AccStruct->h_cln_tds_rate));	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_GLB_CUST",p_AccStruct->h_cln_glb_cust);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_START_DL",p_AccStruct->h_cln_start_dl);	
	        CO_Rtv_DataString(chr_p_param_str,"CLN_BCN_REQD",p_AccStruct->h_cln_bcn_req);
	        CO_Rtv_DataString(chr_p_param_str,"CLN_DEF_CR_AGENCY",p_AccStruct->h_cln_def_cr_agency);
           printf("Val of Tds Rate ==|%lf|\n",p_AccStruct->h_cln_tds_rate);
	        CO_Rtv_DataString(chr_p_param_str,"CLN_CUST_IDENT",p_AccStruct->h_cln_cust_id_ent);	
	        CO_Rtv_DataInt(chr_p_param_str,"CLN_MST_IND",&(p_AccStruct->h_cln_mst_ind));
	        CO_Rtv_DataString(chr_p_param_str,"CLN_SIGN_MEMO",p_AccStruct->h_cln_sign_memo);
			 /* Ramya - start */
               CO_Rtv_DataString(chr_p_param_str,"CLN_SEBI_SUBCAT",p_AccStruct->h_cln_sebi_subcat);
               CO_Rtv_DataString(chr_p_param_str,"CLN_COUNTRY",p_AccStruct->h_cln_country);
               CO_Rtv_DataString(chr_p_param_str,"CLNCITY_DESC",p_AccStruct->h_clncity_desc);
             /* Ramya - end */


           printf("Value of Memo ==%s\n",p_AccStruct->h_cln_sign_memo);

	        /*strcpy(p_AccStruct->h_cln_sign_img,p_blob);*/




APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientPopulate \n",NULL,NULL);
        return 1; */
}


int	MT_Proc_ClientOthPopulate(char *chr_p_acct, char *chr_p_acct_access_stamp, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
          CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientOthPopulate \n",NULL,NULL);

          CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",chr_p_acct_access_stamp);
          CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",chr_p_acct);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

          CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientOthPopulate \n",NULL,NULL);
          return 0;

/*RETURN_FAILURE:

          CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientOthPopulate \n",NULL,NULL);
          return 1; */
}

int	MT_Proc_ClientSignPopulate(char *chr_p_acct, char *chr_p_acct_sign_memo,int chr_p_acct_sign_id,int *chr_p_acct_sign_len, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientSignPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",chr_p_acct);
         CO_Rtv_DataString(chr_p_param_str,"CLN_SIGN_MEMO",chr_p_acct_sign_memo);
         CO_Rtv_DataInt(chr_p_param_str,"BLOBID",&chr_p_acct_sign_id); // AIX - Warnings Removal
         CO_Rtv_DataInt(chr_p_param_str,"CLN_SIGN_LEN",chr_p_acct_sign_len);
         printf("VALLLLLBLOBID ==%d\n",chr_p_acct_sign_id);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientSignPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientSignPopulate \n",NULL,NULL);
        return 1; */
}

int	MT_Proc_CustMemoPopulate(char *chr_p_acct, char *chr_p_memo, char *chr_p_acct_access_stamp, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CustMemoPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLIENT",chr_p_acct);
         CO_Rtv_DataString(chr_p_param_str,"CLT_MEMO",chr_p_memo);
         CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",chr_p_acct_access_stamp);

	

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CustMemoPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CustMemoPopulate \n",NULL,NULL);
        return 1; */
}

int	MT_Proc_CpyCustAddrPopulate(char *chr_p_from_acct, char *chr_p_to_acct, char *chr_p_from_acct_access_stamp,
										char *chr_p_to_acct_access_stamp, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CpyCustAddrPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"FROMACCESSSTAMP",chr_p_from_acct_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"FROMACCOUNT",chr_p_from_acct);
         CO_Rtv_DataString(chr_p_param_str,"TOACCESSSTAMP",chr_p_to_acct_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"TOACCOUNT",chr_p_to_acct);



APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CpyCustAddrPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CpyCustAddrPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_CommPopulate(MT_COMMON_SYS_PARAMS_STRUCT_H *p_mt_common_sys_params_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CommPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"CA_IDENTNAME",p_mt_common_sys_params_struct_h->ca_identname);
        CO_Rtv_DataString(chr_p_param_str,"CA_ADDRESS",p_mt_common_sys_params_struct_h->ca_address);
        CO_Rtv_DataString(chr_p_param_str,"NATION_CODE",p_mt_common_sys_params_struct_h->nation_code);
        CO_Rtv_DataString(chr_p_param_str,"BRNCH_CD",p_mt_common_sys_params_struct_h->brnch_cd);
        CO_Rtv_DataString(chr_p_param_str,"DOM_CCY",p_mt_common_sys_params_struct_h->dom_ccy);
         CO_Rtv_DataString(chr_p_param_str,"DOM_INSTRUMENT",p_mt_common_sys_params_struct_h->dom_instrument);
        CO_Rtv_DataString(chr_p_param_str,"GL_INTERFACE_MOD_IND",p_mt_common_sys_params_struct_h->gl_interface_mod_ind);
        CO_Rtv_DataString(chr_p_param_str,"BILL_MODULE_IND",p_mt_common_sys_params_struct_h->bill_module_ind);
        CO_Rtv_DataString(chr_p_param_str,"CA_MODULE_IND",p_mt_common_sys_params_struct_h->ca_module_ind);
        CO_Rtv_DataString(chr_p_param_str,"F_FILE_PATH",p_mt_common_sys_params_struct_h->f_file_path);
        CO_Rtv_DataString(chr_p_param_str,"B_FILE_PATH",p_mt_common_sys_params_struct_h->b_file_path);
        CO_Rtv_DataInt(chr_p_param_str,"MONTHSFOR_ARCH",&(p_mt_common_sys_params_struct_h->monthsfor_arch));
        CO_Rtv_DataString(chr_p_param_str,"EI_SMI_IND",p_mt_common_sys_params_struct_h->ei_smi_ind);	
        
        CO_Rtv_DataString(chr_p_param_str,"CCS_IND",p_mt_common_sys_params_struct_h->ccs_ind);
        CO_Rtv_DataString(chr_p_param_str,"OFFICE_FOR_BOOKING",p_mt_common_sys_params_struct_h->office_for_booking);
 		  CO_Rtv_DataString(chr_p_param_str,"INSTALLED_AT_BANK",p_mt_common_sys_params_struct_h->installed_at_bank);
        CO_Rtv_DataString(chr_p_param_str,"CUST_CODE",p_mt_common_sys_params_struct_h->cust_code);



APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CommPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CommPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_CorePopulate(MT_CORE_SYS_PARAMS_STRUCT_H  *p_mt_core_sys_params_struct_h,char *chr_p_param_str)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CorePopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"PART_CONFIRM",p_mt_core_sys_params_struct_h->part_confirm);
        CO_Rtv_DataString(chr_p_param_str,"MANIFLD_PRINT_IND",p_mt_core_sys_params_struct_h->manifld_print_ind);
        CO_Rtv_DataString(chr_p_param_str,"PROC_SPOT_DL_IND",p_mt_core_sys_params_struct_h->proc_spot_dl_ind);
        CO_Rtv_DataString(chr_p_param_str,"GSETL_IND",p_mt_core_sys_params_struct_h->gsetl_ind);
        CO_Rtv_DataString(chr_p_param_str,"SUB_CLT_PROC",p_mt_core_sys_params_struct_h->sub_clt_proc);
        CO_Rtv_DataString(chr_p_param_str,"ORD_PROC_IND",p_mt_core_sys_params_struct_h->ord_proc_ind);
        CO_Rtv_DataString(chr_p_param_str,"NO_STXDL_IND",p_mt_core_sys_params_struct_h->no_stxdl_ind);
        CO_Rtv_DataString(chr_p_param_str,"LOC_PROC_IND",p_mt_core_sys_params_struct_h->loc_proc_ind);
        CO_Rtv_DataString(chr_p_param_str,"AE_IND",p_mt_core_sys_params_struct_h->ae_ind);
        CO_Rtv_DataString(chr_p_param_str,"PROC_PR_FEED_IND",p_mt_core_sys_params_struct_h->proc_pr_feed_ind);
        CO_Rtv_DataString(chr_p_param_str,"DIR_INDIR_FXQT_IND",p_mt_core_sys_params_struct_h->dir_indir_fxqt_ind);
        CO_Rtv_DataString(chr_p_param_str,"PROC_REG_IND",p_mt_core_sys_params_struct_h->proc_reg_ind);
        CO_Rtv_DataString(chr_p_param_str,"PART_REG_IND",p_mt_core_sys_params_struct_h->part_reg_ind);
        CO_Rtv_DataInt(chr_p_param_str,"AMOUNT_DECIMAL_LEN",&(p_mt_core_sys_params_struct_h->amount_decimal_len));
        CO_Rtv_DataInt(chr_p_param_str,"QTY_DEC_LEN",&(p_mt_core_sys_params_struct_h->qty_dec_len));
        CO_Rtv_DataInt(chr_p_param_str,"MIN_CLT_LEN",&(p_mt_core_sys_params_struct_h->min_clt_len));
        CO_Rtv_DataInt(chr_p_param_str,"ALLOWED_AMTDIFF",&(p_mt_core_sys_params_struct_h->allowed_amtdiff));
        CO_Rtv_DataInt(chr_p_param_str,"AUTO_INACTIVE_DAYS",&(p_mt_core_sys_params_struct_h->auto_inactive_days));
        CO_Rtv_DataInt(chr_p_param_str,"ODD_LOT_QTY",&(p_mt_core_sys_params_struct_h->odd_lot_qty));
        CO_Rtv_DataInt(chr_p_param_str,"PROC_START_NO",&(p_mt_core_sys_params_struct_h->proc_start_no));
        CO_Rtv_DataInt(chr_p_param_str,"END_PROC_NO",&(p_mt_core_sys_params_struct_h->end_proc_no));
        CO_Rtv_DataDbl(chr_p_param_str,"CUSTODY_TAX_RT",&(p_mt_core_sys_params_struct_h->custody_tax_rt));
        CO_Rtv_DataDbl(chr_p_param_str,"FX_TAX_RT",&(p_mt_core_sys_params_struct_h->fx_tax_rt));
        CO_Rtv_DataDbl(chr_p_param_str,"COMM_TAX_RT",&(p_mt_core_sys_params_struct_h->comm_tax_rt));
        CO_Rtv_DataDbl(chr_p_param_str,"PAIDUPCAPITAL_LIMIT",&(p_mt_core_sys_params_struct_h->paidupcapital_limit));
        CO_Rtv_DataString(chr_p_param_str,"OP_OTH_STX_ERROR",p_mt_core_sys_params_struct_h->op_oth_stx_error);
        CO_Rtv_DataString(chr_p_param_str,"OP_OTH_TRD_ERROR",p_mt_core_sys_params_struct_h->op_oth_trd_error);
        CO_Rtv_DataInt(chr_p_param_str,"STX_REC_DL_DAYS",&(p_mt_core_sys_params_struct_h->stx_rec_dl_days));
        CO_Rtv_DataInt(chr_p_param_str,"STX_DEL_DL_DAYS",&(p_mt_core_sys_params_struct_h->stx_del_dl_days));
        CO_Rtv_DataInt(chr_p_param_str,"OTH_REC_DL_DAYS",&(p_mt_core_sys_params_struct_h->oth_rec_dl_days));
        CO_Rtv_DataInt(chr_p_param_str,"OTH_DEL_DL_DAYS",&(p_mt_core_sys_params_struct_h->oth_del_dl_days));
        CO_Rtv_DataInt(chr_p_param_str,"SPOT_DL_DAYS",&(p_mt_core_sys_params_struct_h->spot_dl_days));
        CO_Rtv_DataInt(chr_p_param_str,"SPOT_OTH_DL_DAYS",&(p_mt_core_sys_params_struct_h->spot_oth_dl_days));
        CO_Rtv_DataString(chr_p_param_str,"CUSTODY_CLT_CD",p_mt_core_sys_params_struct_h->custody_clt_cd);
        CO_Rtv_DataString(chr_p_param_str,"BROKERAGE_CD",p_mt_core_sys_params_struct_h->brokerage_cd);
        CO_Rtv_DataString(chr_p_param_str,"BRNCH_USD_CLT",p_mt_core_sys_params_struct_h->brnch_usd_clt);
        CO_Rtv_DataString(chr_p_param_str,"VTB_CLT_CODE",p_mt_core_sys_params_struct_h->vtb_clt_code);
        CO_Rtv_DataString(chr_p_param_str,"VTB_CLT_NAME",p_mt_core_sys_params_struct_h->vtb_clt_name);
        CO_Rtv_DataString(chr_p_param_str,"VTB_IDENTITY",p_mt_core_sys_params_struct_h->vtb_identity);
	CO_Rtv_DataString(chr_p_param_str,"VDP_IND",p_mt_core_sys_params_struct_h->vdp_ind);
        CO_Rtv_DataDbl(chr_p_param_str,"CUSTODY_COMM_RT",&(p_mt_core_sys_params_struct_h->custody_comm_rt));
        CO_Rtv_DataDbl(chr_p_param_str,"STK_EXG_COMM_RT",&(p_mt_core_sys_params_struct_h->stk_exg_comm_rt));
		  CO_Rtv_DataDbl(chr_p_param_str,"STTRATE",&(p_mt_core_sys_params_struct_h->sttrate));
		  CO_Rtv_DataDbl(chr_p_param_str,"BROKERAGE",&(p_mt_core_sys_params_struct_h->brokerage));
		  /* chgs by amish---02/05 ------- */
        CO_Rtv_DataString(chr_p_param_str,"MS_53X_ONLINE_EOD_IND",p_mt_core_sys_params_struct_h->ms_53x_online_eod_ind);




APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CorePopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CorePopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_MsgPopulate(MT_MESSAGE_SYS_PARAMS_STRUCT_H *p_mt_message_sys_params_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_MsgPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"SND_MSG_TO_ALLMAST",p_mt_message_sys_params_struct_h->snd_msg_to_allmast);
        CO_Rtv_DataString(chr_p_param_str,"MSG569_PREMATCH_IND",p_mt_message_sys_params_struct_h->msg569_prematch_ind);
        CO_Rtv_DataInt(chr_p_param_str,"ALLOWED_TLX_LEN",&(p_mt_message_sys_params_struct_h->allowed_tlx_len));
        CO_Rtv_DataInt(chr_p_param_str,"ALLOWED_RETENSION_PRD",&(p_mt_message_sys_params_struct_h->allowed_retension_prd));
        CO_Rtv_DataString(chr_p_param_str,"GEN_FX_ADV_IND",p_mt_message_sys_params_struct_h->gen_fx_adv_ind);
        CO_Rtv_DataString(chr_p_param_str,"SWIFT_CD",p_mt_message_sys_params_struct_h->swift_cd);
        CO_Rtv_DataString(chr_p_param_str,"GCN_CD",p_mt_message_sys_params_struct_h->gcn_cd);
        CO_Rtv_DataString(chr_p_param_str,"AUTO_MSG_RPR_IND",p_mt_message_sys_params_struct_h->auto_msg_rpr_ind);
        CO_Rtv_DataString(chr_p_param_str,"REG_FOLLOW_MSG_IND",p_mt_message_sys_params_struct_h->reg_follow_msg_ind);
        CO_Rtv_DataInt(chr_p_param_str,"MSG_FOLLOW_DAYS1",&(p_mt_message_sys_params_struct_h->msg_follow_days1));
        CO_Rtv_DataInt(chr_p_param_str,"MSG_FOLLOW_DAYS2",&(p_mt_message_sys_params_struct_h->msg_follow_days2));
        CO_Rtv_DataString(chr_p_param_str,"MS_VTB_MSG_ADDR",p_mt_message_sys_params_struct_h->ms_vtb_msg_addr);
        CO_Rtv_DataInt(chr_p_param_str,"RESPONSE_DAYS",&(p_mt_message_sys_params_struct_h->response_days));
        CO_Rtv_DataString(chr_p_param_str,"CCS_INT_IND",p_mt_message_sys_params_struct_h->ccs_int_ind);
        CO_Rtv_DataString(chr_p_param_str,"LINE_IND",p_mt_message_sys_params_struct_h->line_ind);



APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_MsgPopulate\n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_MsgPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_IVPopulate(INVOICE_SYSTEMPARAM_STRUCT_H *p_invoice_systemparam_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_IVPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"B_CCY",p_invoice_systemparam_struct_h_a->b_ccy);
        CO_Rtv_DataString(chr_p_param_str,"B_BASIS",p_invoice_systemparam_struct_h_a->b_basis);
        CO_Rtv_DataInt(chr_p_param_str,"LATE_DL_DAYS_A",&(p_invoice_systemparam_struct_h_a->late_dl_days_a));
        CO_Rtv_DataInt(chr_p_param_str,"ALLOWED_WRT_OFF_AMT",&(p_invoice_systemparam_struct_h_a->allowed_wrt_off_amt));
        CO_Rtv_DataInt(chr_p_param_str,"DB_TXNRCD",&(p_invoice_systemparam_struct_h_a->db_txnrcd));
        CO_Rtv_DataInt(chr_p_param_str,"CRED_TXNRCD",&(p_invoice_systemparam_struct_h_a->cred_txnrcd));
        CO_Rtv_DataInt(chr_p_param_str,"VAL_DAYS",&(p_invoice_systemparam_struct_h_a->val_days));
        CO_Rtv_DataInt(chr_p_param_str,"PERIODFOR_ARCH",&(p_invoice_systemparam_struct_h_a->periodfor_arch));
	CO_Rtv_DataInt(chr_p_param_str, "PYMT_GEN_DATE", &(p_invoice_systemparam_struct_h_a->pymt_gen_date));
	CO_Rtv_DataString(chr_p_param_str, "STATUS", p_invoice_systemparam_struct_h_a->status_pymt);
   CO_Rtv_DataString(chr_p_param_str,"LATETIME_A",p_invoice_systemparam_struct_h_a->latetime_a);
   CO_Rtv_DataInt(chr_p_param_str,"LATE_DL_DAYS_B",&(p_invoice_systemparam_struct_h_a->late_dl_days_b));
   CO_Rtv_DataString(chr_p_param_str,"LATETIME_B",p_invoice_systemparam_struct_h_a->latetime_b);
   CO_Rtv_DataInt(chr_p_param_str,"LATE_DL_DAYS_C",&(p_invoice_systemparam_struct_h_a->late_dl_days_c));
   CO_Rtv_DataString(chr_p_param_str,"LATETIME_C",p_invoice_systemparam_struct_h_a->latetime_c);
   CO_Rtv_DataInt(chr_p_param_str,"LATE_DL_DAYS_D",&(p_invoice_systemparam_struct_h_a->late_dl_days_d));
   CO_Rtv_DataString(chr_p_param_str,"LATETIME_D",p_invoice_systemparam_struct_h_a->latetime_d);

   CO_Rtv_DataInt(chr_p_param_str,"ACC_DIGITS",&(p_invoice_systemparam_struct_h_a->acc_digits));

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_IVPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_IVPopulate \n",NULL,NULL);
	return 1; */
}

int   MT_Proc_CASetupUpdPopulate(CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_a,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CASetupUpdPopulate \n",NULL,NULL);
	
	CO_Rtv_DataString(chr_p_param_str,"INSTR_TYPE",p_ca_casecevent_struct_h_a->h_typeofinstr);
        CO_Rtv_DataString(chr_p_param_str,"CA_EVENT",p_ca_casecevent_struct_h_a->h_ca_event);
        CO_Rtv_DataString(chr_p_param_str,"PAYOUT_FLAG",p_ca_casecevent_struct_h_a->h_pymtout_ind);
        CO_Rtv_DataString(chr_p_param_str,"ENTITL_BASE",p_ca_casecevent_struct_h_a->h_entitl_base);
        CO_Rtv_DataString(chr_p_param_str,"RATIO_PERC_IND",p_ca_casecevent_struct_h_a->h_ratio_perc_ind);
        CO_Rtv_DataString(chr_p_param_str,"AMOUNT_RATIO_FLG",p_ca_casecevent_struct_h_a->h_amt_rt_ind);
        CO_Rtv_DataString(chr_p_param_str,"AUTO_DLCRT_IND",p_ca_casecevent_struct_h_a->h_new_dl_ind);
        CO_Rtv_DataString(chr_p_param_str,"SNDMSG_TO_ALLMAST",p_ca_casecevent_struct_h_a->h_evtmsg_all_mstclt);
        CO_Rtv_DataString(chr_p_param_str,"GEN_ENRAREP_IND",p_ca_casecevent_struct_h_a->h_gen_enrarep_ind);
        CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_A",&(p_ca_casecevent_struct_h_a->h_enra_lapse_a));
        CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_B",&(p_ca_casecevent_struct_h_a->h_enra_lapse_b));
	CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_C",&(p_ca_casecevent_struct_h_a->h_enra_lapse_c));
        /* Added By Santhoshi for PEG-CA-ENH-2.3 - Retro done By Sana Bhatkar ---START - retro by Lakshmi Swetha */
	CO_Rtv_DataInt(chr_p_param_str,"CLOSURE_DT_DAYS",&(p_ca_casecevent_struct_h_a->h_closure_dt_days));
	printf("\n\nChk : Sana : Closure Days = |%d|",p_ca_casecevent_struct_h_a->h_closure_dt_days);
	/* Added By Santhoshi for PEG-CA-ENH-2.3 - Retro done By Sana Bhatkar ---END*/

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CASetupUpdPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CASetupUpdPopulate \n",NULL,NULL);
        return 1;  */
}

/* By Harvinder Singh for RFS_CLN_MAP_001 Date - 7/3/2007 */
int Populate_WI_CLIENT_MAP(WI_CLIENT_MAP_STRUCT_H *p_wi_client_map_struct_h,char *chr_p_param_str)
{

        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_WI_CLIENT_MAP \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_wi_client_map_struct_h->h_cln_code);
        CO_Rtv_DataString(chr_p_param_str,"CLN_MASTER",p_wi_client_map_struct_h->h_cln_master);
        CO_Rtv_DataString(chr_p_param_str,"WI_LOGIN",p_wi_client_map_struct_h->h_wi_login);
        CO_Rtv_DataString(chr_p_param_str,"LOGIN_RIGHTS",p_wi_client_map_struct_h->h_login_rights);
        CO_Rtv_DataString(chr_p_param_str,"AUTO_AUTH",p_wi_client_map_struct_h->h_auto_auth);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORIZER",p_wi_client_map_struct_h->h_authorizer);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_wi_client_map_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_wi_client_map_struct_h->h_access_stamp);

			printf("\n ******************************* BAWA ***********************************************\n");
     		printf("\n cln_code ->  |%s|\n",p_wi_client_map_struct_h->h_cln_code);
    	 	printf("\n cln_master ->  |%s|\n",p_wi_client_map_struct_h->h_cln_master);
     		printf("\n wi_login ->  |%s|\n",p_wi_client_map_struct_h->h_wi_login);
    	 	printf("\n login_rights ->  |%s|\n",p_wi_client_map_struct_h->h_login_rights);
   	 	printf("\n auto_auth ->  |%s|\n",p_wi_client_map_struct_h->h_auto_auth);
     		printf("\n authorizer ->  |%s|\n",p_wi_client_map_struct_h->h_authorizer);
     		printf("\n maker ->  |%s|\n",p_wi_client_map_struct_h->h_maker);
     		printf("\n access_stamp ->  |%s|\n",p_wi_client_map_struct_h->h_access_stamp);
     		printf("\n ******************************* BAWA ***********************************************\n");
    



        APL_GOBACK_SUCCESS 
        RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_WI_CLIENT_MAP \n",NULL,NULL);
        return 0;

      /*  RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_WI_CLIENT_MAP \n",NULL,NULL);
        return 1; */
}


int   MT_Proc_CASetupPopulate(CA_CASECEVENT_STRUCT_H *p_ca_casecevent_struct_h_f,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CASetupPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_TYPE",p_ca_casecevent_struct_h_f->h_typeofinstr);
        CO_Rtv_DataString(chr_p_param_str,"CA_EVENT",p_ca_casecevent_struct_h_f->h_ca_event);
        CO_Rtv_DataString(chr_p_param_str,"PAYOUT_FLAG",p_ca_casecevent_struct_h_f->h_pymtout_ind);
        CO_Rtv_DataString(chr_p_param_str,"ENTITL_BASE",p_ca_casecevent_struct_h_f->h_entitl_base);
        CO_Rtv_DataString(chr_p_param_str,"RATIO_PERC_IND",p_ca_casecevent_struct_h_f->h_ratio_perc_ind);
        CO_Rtv_DataString(chr_p_param_str,"AMOUNT_RATIO_FLG",p_ca_casecevent_struct_h_f->h_amt_rt_ind);
        CO_Rtv_DataString(chr_p_param_str,"AUTO_DLCRT_IND",p_ca_casecevent_struct_h_f->h_new_dl_ind);
        CO_Rtv_DataString(chr_p_param_str,"SNDMSG_TO_ALLMAST",p_ca_casecevent_struct_h_f->h_evtmsg_all_mstclt);
        CO_Rtv_DataString(chr_p_param_str,"GEN_ENRAREP_IND",p_ca_casecevent_struct_h_f->h_gen_enrarep_ind);
        CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_A",&(p_ca_casecevent_struct_h_f->h_enra_lapse_a));
        CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_B",&(p_ca_casecevent_struct_h_f->h_enra_lapse_b));
        CO_Rtv_DataInt(chr_p_param_str,"ENRA_LAPSE_C",&(p_ca_casecevent_struct_h_f->h_enra_lapse_c));
        /* Added By Santhoshi for PEG-CA-ENH-2.3 ---START - retro by Sana Bhatkar */
	CO_Rtv_DataInt(chr_p_param_str,"CLOSURE_DT_DAYS",&(p_ca_casecevent_struct_h_f->h_closure_dt_days));
	fflush(stdout);
        /* Added By Santhoshi for PEG-CA-ENH-2.3 --- END - retro by Sana Bhatkar */


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CASetupPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CASetupPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_AutoEvntUpdPopulate(CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_c,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_AutoEvntUpdPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"NATION_CD",p_ca_autoevent_struct_h_c->h_nation_code);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_TYPE",p_ca_autoevent_struct_h_c->h_typeofinstr);
        CO_Rtv_DataString(chr_p_param_str,"PROD_CLASS",p_ca_autoevent_struct_h_c->h_prodateype);
        CO_Rtv_DataString(chr_p_param_str,"EVENT_TYPE",p_ca_autoevent_struct_h_c->h_evt_class);
        CO_Rtv_DataInt(chr_p_param_str,"PAY_DT_DAYS",&(p_ca_autoevent_struct_h_c->h_no_days_pymtdt));
        CO_Rtv_DataInt(chr_p_param_str,"EXDATE_DAYS",&(p_ca_autoevent_struct_h_c->h_exdate_no_days));


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_AutoEvntUpdPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_AutoEvntUpdPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_AutoEvntPopulate(CA_AUTOEVENT_STRUCT_H *p_ca_autoevent_struct_h_b,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_AutoEvntPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"NATION_CD",p_ca_autoevent_struct_h_b->h_nation_code);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_TYPE",p_ca_autoevent_struct_h_b->h_typeofinstr);
        CO_Rtv_DataString(chr_p_param_str,"PROD_CLASS",p_ca_autoevent_struct_h_b->h_prodateype);
        CO_Rtv_DataString(chr_p_param_str,"EVENT_TYPE",p_ca_autoevent_struct_h_b->h_evt_class);
        CO_Rtv_DataInt(chr_p_param_str,"PAY_DT_DAYS",&(p_ca_autoevent_struct_h_b->h_no_days_pymtdt));
        CO_Rtv_DataInt(chr_p_param_str,"EXDATE_DAYS",&(p_ca_autoevent_struct_h_b->h_exdate_no_days));



APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_AutoEvntPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_AutoEvntPopulate \n",NULL,NULL);
        return 1; */
}

int MT_Proc_LocPopulate(MT_LOCATION_STRUCT_H *p_mt_location_struct_h_a, char *chr_p_param_str)
{
         void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_LocPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",p_mt_location_struct_h_a->h_loccode);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_location_struct_h_a->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_location_struct_h_a->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_location_struct_h_a->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_location_struct_h_a->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_location_struct_h_a->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"STATUS_POS",p_mt_location_struct_h_a->h_pos_stat);
        CO_Rtv_DataString(chr_p_param_str,"MANIFLD_IND",p_mt_location_struct_h_a->h_manifld_ind);
		  /*Smita - Changed h_loc_stat to Status - HDFCCA_Base Version*/
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_location_struct_h_a->h_status);
        CO_Rtv_DataString(chr_p_param_str,"LOCATION_DESC",p_mt_location_struct_h_a->h_locdetail);
        CO_Rtv_DataString(chr_p_param_str,"PHYSICAL_IND",p_mt_location_struct_h_a->h_physical_ind);
        CO_Rtv_DataString(chr_p_param_str,"ISO_LOCNCD",p_mt_location_struct_h_a->h_iso_loccode);
        CO_Rtv_DataString(chr_p_param_str,"AVAI_IND",p_mt_location_struct_h_a->h_avail_flag);
        
        CO_Rtv_DataString(chr_p_param_str,"DEPO",p_mt_location_struct_h_a->h_depo);




 APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_LocPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_LocPopulate \n",NULL,NULL);
        return 1;  */
		
}

int MT_Proc_HolPopulate(MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_b_c, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_HolPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"H_DATE",p_mt_holiday_struct_h_b_c->h_holi_dt);
        CO_Rtv_DataString(chr_p_param_str,"H_CLASS",p_mt_holiday_struct_h_b_c->h_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"H_REASON",p_mt_holiday_struct_h_b_c->h_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_holiday_struct_h_b_c->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_holiday_struct_h_b_c->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_holiday_struct_h_b_c->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_holiday_struct_h_b_c->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_holiday_struct_h_b_c->h_checker_dt);
		  /*Smita - Changed Col Variable to Status - HDFCCA_BaseVersion*/
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_holiday_struct_h_b_c->h_status);
        CO_Rtv_DataString(chr_p_param_str,"HOL_IND",p_mt_holiday_struct_h_b_c->h_hol_flag);
        CO_Rtv_DataString(chr_p_param_str,"OLD_CLASS",p_mt_holiday_struct_h_b_c->h_old_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"OLD_REASON",p_mt_holiday_struct_h_b_c->h_old_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"OLD_BRNCH_HOL_IND",p_mt_holiday_struct_h_b_c->h_old_hol_flag);
        CO_Rtv_DataString(chr_p_param_str,"BANK_IND",p_mt_holiday_struct_h_b_c->h_bank_ind);
        CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_mt_holiday_struct_h_b_c->h_exch_code);


 APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_HolPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_HolPopulate \n",NULL,NULL);
        return 1; */
}


int MT_Proc_HolBothPopulate(MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h_b,MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_HolBothPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"H_DATE",p_mt_holiday_struct_h_b->h_holi_dt);
        CO_Rtv_DataString(chr_p_param_str,"H_CLASS",p_mt_holiday_struct_h_b->h_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"H_REASON",p_mt_holiday_struct_h_b->h_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_holiday_struct_h_b->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_holiday_struct_h_b->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_holiday_struct_h_b->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_holiday_struct_h_b->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_holiday_struct_h_b->h_checker_dt);
		  /*Smita - Changed h_stat to Status - HDFCCA_Base Version*/
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_holiday_struct_h_b->h_status);
        CO_Rtv_DataString(chr_p_param_str,"HOL_IND",p_mt_holiday_struct_h_b->h_hol_flag);
        CO_Rtv_DataString(chr_p_param_str,"OLD_CLASS",p_mt_holiday_struct_h_b->h_old_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"OLD_REASON",p_mt_holiday_struct_h_b->h_old_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"OLD_BRNCH_HOL_IND",p_mt_holiday_struct_h_b->h_exch_code);
		  /* chk by amish -- 0505 */
		   CO_Rtv_DataString(chr_p_param_str,"EXCHANG_CODE",p_mt_holiday_struct_h_b->h_exch_code);
			CO_Rtv_DataString(chr_p_param_str,"BANK_IND",p_mt_holiday_struct_h_b->h_bank_ind);
         printf("\n******EXCHANGE CODE IS |%s|\n",p_mt_holiday_struct_h_b->h_exch_code);
        CO_Rtv_DataString(chr_p_param_str,"H_DATE1",p_mt_holiday_struct_h->h_holi_dt);
        CO_Rtv_DataString(chr_p_param_str,"H_CLASS1",p_mt_holiday_struct_h->h_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"H_REASON1",p_mt_holiday_struct_h->h_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"MAKER1",p_mt_holiday_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT1",p_mt_holiday_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP1",p_mt_holiday_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER1",p_mt_holiday_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT1",p_mt_holiday_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS1",p_mt_holiday_struct_h->h_status);
        CO_Rtv_DataString(chr_p_param_str,"HOL_IND1",p_mt_holiday_struct_h->h_hol_flag);
        CO_Rtv_DataString(chr_p_param_str,"OLD_CLASS1",p_mt_holiday_struct_h->h_old_holi_class);
        CO_Rtv_DataString(chr_p_param_str,"OLD_REASON1",p_mt_holiday_struct_h->h_old_h_reas);
        CO_Rtv_DataString(chr_p_param_str,"OLD_BRNCH_HOL_IND1",p_mt_holiday_struct_h->h_old_hol_flag);
		  /* added by amish --05/05 */
		   CO_Rtv_DataString(chr_p_param_str,"EXCHANG_CODE1",p_mt_holiday_struct_h->h_exch_code);
			CO_Rtv_DataString(chr_p_param_str,"BANK_IND1",p_mt_holiday_struct_h->h_bank_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_HolBothPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_HolBothPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_CcyPopulate(DL_CURRENCY_STRUCT_H *p_dl_currency_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CcyPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CURRENCY_CD",p_dl_currency_struct_h->h_currencycode);
         CO_Rtv_DataString(chr_p_param_str,"CURRENCY_DESC",p_dl_currency_struct_h->h_ccydetail);
         CO_Rtv_DataString(chr_p_param_str,"MAKER",p_dl_currency_struct_h->h_maker);
         CO_Rtv_DataInt(chr_p_param_str,"DEC_LEN",&(p_dl_currency_struct_h->h_dec_len));
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_dl_currency_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_dl_currency_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"GL_CD",p_dl_currency_struct_h->h_gl_cd);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CcyPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CcyPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_CustEntryPopulate(MT_CLIENT_ENTRIES_STRUCT_H *p_mt_client_entries_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CustEntryPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_client_entries_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_client_entries_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_client_entries_struct_h->h_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"STX_CLIENT",p_mt_client_entries_struct_h->h_stx_client);
         CO_Rtv_DataString(chr_p_param_str,"COMM_CLT",p_mt_client_entries_struct_h->h_commn_client);
         CO_Rtv_DataString(chr_p_param_str,"TPAY_CLIENT",p_mt_client_entries_struct_h->h_tpymt_client);
         CO_Rtv_DataString(chr_p_param_str,"TEXP_CLIENT",p_mt_client_entries_struct_h->h_texp_client);
         CO_Rtv_DataString(chr_p_param_str,"CUSTODY_CLT",p_mt_client_entries_struct_h->h_bnk_client);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CustEntryPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CustEntryPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_ExgRtPopulate(MT_EXCHRATE_STRUCT_H *p_mt_exchrate_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ExgRtPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CURRENCY_CD",p_mt_exchrate_struct_h->h_currencycode);
         CO_Rtv_DataString(chr_p_param_str,"DENOM_CCY",p_mt_exchrate_struct_h->h_denom_currencycode);
         CO_Rtv_DataString(chr_p_param_str,"RATE_DATE",p_mt_exchrate_struct_h->h_rtdt);
         CO_Rtv_DataDbl(chr_p_param_str,"EXCHGRT",&(p_mt_exchrate_struct_h->h_exchgrt));
         CO_Rtv_DataDbl(chr_p_param_str,"RATE_BUY",&(p_mt_exchrate_struct_h->h_rate_buy));
         CO_Rtv_DataDbl(chr_p_param_str,"SELL_RT",&(p_mt_exchrate_struct_h->h_sellae_rate));
         CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_exchrate_struct_h->h_maker);
         CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_exchrate_struct_h->h_maker_dt);
         CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_exchrate_struct_h->h_access_stamp);
			/*Smita - Changed Authoriser to Checker - HDFCCA_Base Version*/
         CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_exchrate_struct_h->h_checker);
         CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_exchrate_struct_h->h_checker_dt);
			/*Smita - Changed h_exchg_stat to Status - HDFCCA_Base Version*/
         CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_exchrate_struct_h->h_status);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ExgRtPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ExgRtPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_IVCustPopulate(IV_CLIENTPARAM_STRUCT *l_iv_clientparam_struct,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		  void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_IVCustPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT3",l_iv_clientparam_struct->client);	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"B_CCYCD",(char *)l_iv_clientparam_struct->b_ccycd);
                        CO_Rtv_DataString(chr_p_param_str,"FEES_CCY",l_iv_clientparam_struct->fees_ccy);
                        CO_Rtv_DataChar(chr_p_param_str,"SEND_TO_MASTER_IND",&(l_iv_clientparam_struct->send_to_master_ind));
                        CO_Rtv_DataChar(chr_p_param_str,"B_GEN_IND",&(l_iv_clientparam_struct->b_gen_ind));
                        CO_Rtv_DataDbl(chr_p_param_str,"MINIMUMFEE",&(l_iv_clientparam_struct->minimumfee));
                        CO_Rtv_DataChar(chr_p_param_str,"MINIMUMFEE_TO",&(l_iv_clientparam_struct->minimumfee_to));
                        CO_Rtv_DataChar(chr_p_param_str,"MIN_HLD_ADJ",&(l_iv_clientparam_struct->min_hld_adj));
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",l_iv_clientparam_struct->bcustsetup_access_stamp);	/* Bageshri */
						      CO_Rtv_DataChar(chr_p_param_str,"DB_DIRECT_FLAG",&(l_iv_clientparam_struct->dir_db_ind));	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"SPL_CLT_CD",l_iv_clientparam_struct->spl_clt_cd);
                        CO_Rtv_DataString(chr_p_param_str,"COMM_CLT",l_iv_clientparam_struct->comm_clt);
                        CO_Rtv_DataString(chr_p_param_str,"REC_CLT",l_iv_clientparam_struct->rec_clt);
                        CO_Rtv_DataString(chr_p_param_str,"INFORMATION",l_iv_clientparam_struct->information);
                        CO_Rtv_DataString(chr_p_param_str,"DEFAULT_FEECLT",l_iv_clientparam_struct->default_feeclt);
                        CO_Rtv_DataDbl(chr_p_param_str,"COMM_TAX_AMT",&(l_iv_clientparam_struct->comm_tax_amt));
                        CO_Rtv_DataString(chr_p_param_str,"VAT_CD",l_iv_clientparam_struct->vat_cd); 
                        CO_Rtv_DataString(chr_p_param_str,"VAT_NOTE",l_iv_clientparam_struct->vat_note); 
								printf("111111 Param String :|%s|\n",chr_p_param_str);
		                  /***************** Bageshri ****************************/
                        CO_Rtv_DataDbl(chr_p_param_str,"TOTAL_OSAMOUNT",&(l_iv_clientparam_struct->total_osamount));
						      CO_Rtv_DataString(chr_p_param_str,"OBLG_LVL",l_iv_clientparam_struct->oblg_lvl);
                        CO_Rtv_DataString(chr_p_param_str,"OBLG_TYP",l_iv_clientparam_struct->oblg_typ);
                        CO_Rtv_DataInt(chr_p_param_str,"PAY_IN_DAY",&(l_iv_clientparam_struct->pay_in_day));
                        CO_Rtv_DataInt(chr_p_param_str,"PAY_OUT_DAY",&(l_iv_clientparam_struct->pay_out_day));
                        CO_Rtv_DataChar(chr_p_param_str,"B_FREQ",&(l_iv_clientparam_struct->b_freq));
                        CO_Rtv_DataDbl(chr_p_param_str,"PAY_OUT_LMT",&(l_iv_clientparam_struct->pay_out_lmt));
                        CO_Rtv_DataChar(chr_p_param_str,"DVP_IND",&(l_iv_clientparam_struct->dvp_ind));
                        CO_Rtv_DataChar(chr_p_param_str,"ACC_TYP",&(l_iv_clientparam_struct->acc_typ));
                        CO_Rtv_DataString(chr_p_param_str,"PAY_IN_ACC",l_iv_clientparam_struct->pay_in_acc);
                        CO_Rtv_DataString(chr_p_param_str,"PAY_OUT_ACC",l_iv_clientparam_struct->pay_out_acc);
                        CO_Rtv_DataString(chr_p_param_str,"ACC_CODE1",l_iv_clientparam_struct->acc_code1);
                        CO_Rtv_DataString(chr_p_param_str,"ACC_CODE2",l_iv_clientparam_struct->acc_code2);
                        CO_Rtv_DataString(chr_p_param_str,"ACC_CODE2DESC",l_iv_clientparam_struct->acc_code2desc);
                        CO_Rtv_DataString(chr_p_param_str,"OBLIG_REP_FLG",l_iv_clientparam_struct->oblig_rep_flg);
                        CO_Rtv_DataChar(chr_p_param_str,"CALC_BASIS",&(l_iv_clientparam_struct->calc_basis));
						      CO_Rtv_DataChar(chr_p_param_str,"PORTFOLIO_EVAL",&(l_iv_clientparam_struct->portfolio_eval));
						      CO_Rtv_DataChar(chr_p_param_str,"NAV_IND",&(l_iv_clientparam_struct->nav_ind));	
						      CO_Rtv_DataString(chr_p_param_str,"ANN_FEE_MONTH",l_iv_clientparam_struct->ann_fee_month); // AIX - Warnings Removal
								CO_Rtv_DataString(chr_p_param_str,"BNK_ACC",l_iv_clientparam_struct->bnk_acc);
								CO_Rtv_DataString(chr_p_param_str,"BNK_FCY_ACC",l_iv_clientparam_struct->bnk_fcy_acc); /* YOG 211206*/
								CO_Rtv_DataDbl(chr_p_param_str,"MAXIMUMFEE",&(l_iv_clientparam_struct->maximumfee));
								CO_Rtv_DataChar(chr_p_param_str,"MAXIMUMFEE_TO",&(l_iv_clientparam_struct->maximumfee_to));
								CO_Rtv_DataChar(chr_p_param_str,"MAX_HLD_ADJ",&(l_iv_clientparam_struct->max_hld_adj));
								CO_Rtv_DataDbl(chr_p_param_str,"TXNMINFEE",&(l_iv_clientparam_struct->txnminfee));
								CO_Rtv_DataDbl(chr_p_param_str,"TXNMAXFEE",&(l_iv_clientparam_struct->txnmaxfee));
								CO_Rtv_DataString(chr_p_param_str,"PYMT_ACC",l_iv_clientparam_struct->pymt_acc);
   /* Bageshri HB_IV_001 */
	CO_Rtv_DataString(chr_p_param_str,"DIR_DB_DATE",l_iv_clientparam_struct->dir_db_date);
	CO_Rtv_DataString(chr_p_param_str,"B_BASIS",l_iv_clientparam_struct->b_basis);
	CO_Rtv_DataString(chr_p_param_str,"B_DLV_DATE",l_iv_clientparam_struct->b_dlv_date);
	CO_Rtv_DataInt(chr_p_param_str,"REP_PAY_IN_DAY",&(l_iv_clientparam_struct->rep_pay_in_day));
	CO_Rtv_DataInt(chr_p_param_str,"REP_PAY_OUT_DAY",&(l_iv_clientparam_struct->rep_pay_out_day));
	CO_Rtv_DataString(chr_p_param_str,"B_BASIS_CUST",l_iv_clientparam_struct->b_basis_cust);
   /* Bageshri HB_IV_001 END */
        CO_Rtv_DataDbl(chr_p_param_str,"ANN_MIN_CHRG",&(l_iv_clientparam_struct->ann_min_chrg));/*added by shruthi kumbla for ISKB_1737*/





APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_IVCustPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_IVCustPopulate \n",NULL,NULL);
	return 1; */
}
int   MT_Proc_IVCustServDepPopulate(IV_CLIENTSERVDEP_STRUCT_H *p_iv_clientservdep_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		  void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value);	/* Bageshri */

        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_IVCustServDepPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT3",p_iv_clientservdep_struct_h->client);	/* Bageshri */
                        CO_Rtv_DataLong(chr_p_param_str,"SERVICE_CD",&(p_iv_clientservdep_struct_h->service_cd));	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"PARAMETER_CD",p_iv_clientservdep_struct_h->parameter_cd);
                        CO_Rtv_DataDbl(chr_p_param_str,"MIN_FEE",&(p_iv_clientservdep_struct_h->minimumfee)); /* Bageshri */
                        CO_Rtv_DataDbl(chr_p_param_str,"NIL_FEE",&(p_iv_clientservdep_struct_h->nil_fees)); /* Bageshri */
                        CO_Rtv_DataDbl(chr_p_param_str,"MAX_FEE",&(p_iv_clientservdep_struct_h->maximum_fee)); /* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"FEES_BASE",p_iv_clientservdep_struct_h->fees_base);
                        CO_Rtv_DataString(chr_p_param_str,"CHRG_BASE",p_iv_clientservdep_struct_h->chrg_base);
                        CO_Rtv_DataChar(chr_p_param_str,"FEE_FLAGS",&(p_iv_clientservdep_struct_h->fees_class));	/* Bageshri */
                        CO_Rtv_DataChar(chr_p_param_str,"CHARGE_BASIS",&(p_iv_clientservdep_struct_h->chrg_clas));	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_iv_clientservdep_struct_h->bcustsetup_access_stamp);	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"SERVICE_FEE_CURRENCY",p_iv_clientservdep_struct_h->dealadm_feeccy);	/* Bageshri */
						      CO_Rtv_DataString(chr_p_param_str,"BILL_ACC",p_iv_clientservdep_struct_h->bill_acc);	/* Bageshri */
                        CO_Rtv_DataChar(chr_p_param_str,"B_FREQ",&(p_iv_clientservdep_struct_h->b_freq));	/* Bageshri */
			CO_Rtv_DataChar(chr_p_param_str,"INCLD_IN_ANN_MIN_FEE",&(p_iv_clientservdep_struct_h->incld_in_ann_min_fee));/*added by shruthi kumbla for ISKB_1737*/
                 	CO_Rtv_DataString(chr_p_param_str,"PLS_MONTH",p_iv_clientservdep_struct_h->pls_month); /*added for kotak ISKB_1737*/
			CO_Rtv_DataString(chr_p_param_str,"APL_FRM_DATE",p_iv_clientservdep_struct_h->apl_frm_date); /*added for kotak ISKB_1737*/

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_IVCustServDepPopulate \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_IVCustServDepPopulate \n",NULL,NULL);
	return 1; */
}

int   MT_Proc_IVCustFeePopulate(IV_CUSTFEE_STRUCT_H *l_iv_custfee_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value);	/* Bageshri */
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_IVCustFeePopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT3",l_iv_custfee_struct_h->client);		/* Bageshri */
                        CO_Rtv_DataLong(chr_p_param_str,"SERVICE_CD",&(l_iv_custfee_struct_h->service_cd));	/* Bageshri */
                        CO_Rtv_DataString(chr_p_param_str,"PROC_DATA_VAL",l_iv_custfee_struct_h->proc_data_val);
                        CO_Rtv_DataString(chr_p_param_str,"GROUP_ID",l_iv_custfee_struct_h->group_id);
                        CO_Rtv_DataDbl(chr_p_param_str,"CHARGE_BASIS_FR",&(l_iv_custfee_struct_h->frm_cbase));	/* Bageshri */
                        CO_Rtv_DataDbl(chr_p_param_str,"FEE_BASIS_FR",&(l_iv_custfee_struct_h->frm_fbase));	/* Bageshri */
                        CO_Rtv_DataDbl(chr_p_param_str,"FEE",&(l_iv_custfee_struct_h->schdl_fee));	/* Bageshri */
	                CO_Rtv_DataChar(chr_p_param_str,"FEE_TYPE",&(l_iv_custfee_struct_h->fee_type));/*** vinay ***/
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",l_iv_custfee_struct_h->bcustsetup_access_stamp);	/* Bageshri */
	CO_Rtv_DataString(chr_p_param_str,"APL_FRM_DATE",l_iv_custfee_struct_h->apl_frm_date); /*added for kotak ISKB_1737*/
						CO_Rtv_DataDbl(chr_p_param_str,"CHARGE_BASIS_TO",&(l_iv_custfee_struct_h->toc_base));	/* Added for Billing Structure Upload */

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_IVCustFeePopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_IVCustFeePopulate \n",NULL,NULL);
	return 1; */
}

int   MT_Proc_ClientSchPopulate(MT_SCHDET_STRUCT_H *p_mt_schdet_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered Into MT_Proc_ClientSchPopulate \n");

  CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_schdet_struct_h->h_dl_client);
  CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_NO",p_mt_schdet_struct_h->h_msg_ident_no);
  CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",&(p_mt_schdet_struct_h->h_schsequence_num));
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_EOM",p_mt_schdet_struct_h->h_eom_msg_ind);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_GEN_ON_DAY",p_mt_schdet_struct_h->h_generate_day);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_NOPOSTXNFLG",p_mt_schdet_struct_h->h_pos_txn_ind);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_ZEROMOV",p_mt_schdet_struct_h->h_nil_mov_ind);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_MSGOPTION",p_mt_schdet_struct_h->h_msg_opt);
  printf("Message Option = |%s|\n",p_mt_schdet_struct_h->h_msg_opt);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_DEPO_STAT",p_mt_schdet_struct_h->h_loc_stat);
  printf("Message Option 2 = |%s|\n",p_mt_schdet_struct_h->h_msg_opt);
  CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_schdet_struct_h->h_access_stamp);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_NOPEND",p_mt_schdet_struct_h->h_pend_ind);
  CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_WEEKSTM",p_mt_schdet_struct_h->h_weeklystmt);
CO_Rtv_DataString(chr_p_param_str,"CLN_SCH_EVALUATE_FLG",p_mt_schdet_struct_h->h_validate_flag);

   /* Kouser - RFSNo -  HDFCMT_001 - Client Master Maintenance */

	         	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_schdet_struct_h->h_maker);
	         	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_schdet_struct_h->h_maker_dt);
	         	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_schdet_struct_h->h_checker);
	         	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_schdet_struct_h->h_checker_dt);
	         	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_schdet_struct_h->h_status);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientSchPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientSchPopulate \n",NULL,NULL);
        return 1; */
}

/* RFSNo - HDFCMT_001 - Kouser - Client Master Maintenance */

int   MT_Proc_ClientExchMapPopulate(MT_CLTEXCHMAP_STRUCT_H *p_mt_cltexchmap_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientExchMapPopulate \n",NULL,NULL);

                       CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_cltexchmap_struct_h->h_dl_client);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_EXCH_CODE",p_mt_cltexchmap_struct_h->h_cln_exch_code);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_EXCH_MAP_CODE",p_mt_cltexchmap_struct_h->h_cln_exch_map_code);
                       /* SLB CHGS Aashish 01-04-2008 */ 
                       CO_Rtv_DataString(chr_p_param_str,"SLB_EXCH_MAP_CODE",p_mt_cltexchmap_struct_h->h_slb_exch_map_code);
                       printf("\n SLB_EXCH_MAP_CODE = |%s| \n",p_mt_cltexchmap_struct_h->h_slb_exch_map_code);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_HDFC_CM_ID",p_mt_cltexchmap_struct_h->h_cln_hdfc_cm_id);
                       CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cltexchmap_struct_h->h_access_stamp);
                       CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cltexchmap_struct_h->h_maker);
                       CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cltexchmap_struct_h->h_maker_dt);
                       CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cltexchmap_struct_h->h_checker);
                       CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cltexchmap_struct_h->h_checker_dt);
                  CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",&(p_mt_cltexchmap_struct_h->h_cln_exchseq_num));
                       CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cltexchmap_struct_h->h_status);
                         printf("Value of Seq Number ==%d\n",p_mt_cltexchmap_struct_h->h_cln_exchseq_num);
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientExchMapPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientExchMapPopulate \n",NULL,NULL);
        return 1; */
}

/* Kouser - REFNo - HDFCMT_001 - Client Master Maintenance */

int   MT_Proc_ClientDepoMapPopulate(MT_CLTDEPOMAP_STRUCT_H *p_mt_cltdepomap_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientDepoMapPopulate \n",NULL,NULL);

                       CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_cltdepomap_struct_h->h_dl_client);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_DEPO_CODE",p_mt_cltdepomap_struct_h->h_cln_depo_code);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_DEPO_MAP_CLIENT_ID",p_mt_cltdepomap_struct_h->h_cln_depo_map_clnt_id);
                       CO_Rtv_DataString(chr_p_param_str,"CLN_DEPO_MAP_DP_ID",p_mt_cltdepomap_struct_h->h_cln_depo_map_dp_id);
                       CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cltdepomap_struct_h->h_access_stamp);
                       CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cltdepomap_struct_h->h_maker);
                       CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cltdepomap_struct_h->h_maker_dt);
                       CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cltdepomap_struct_h->h_checker);
                       CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cltdepomap_struct_h->h_checker_dt);
                      CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",&(p_mt_cltdepomap_struct_h->h_cln_deposeq_num));
                       CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cltdepomap_struct_h->h_status);
		       CO_Rtv_DataString(chr_p_param_str,"CMBP_ID",p_mt_cltdepomap_struct_h->h_cmbp_id); /* ADDED BY SIMAR FOR PMS UPLOAD ISKB_12434 */



 APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
           CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientDepoMapPopulate\n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
           CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientDepoMapPopulate\n",NULL,NULL);
        return 1; */
}


int   MT_Proc_ClientAddrPopulate(MT_MSGADDRESS_STRUCT_H    *p_mt_msgaddress_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientAddrPopulate \n",NULL,NULL);


                         CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_msgaddress_struct_h->h_dl_client);

                        CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",&(p_mt_msgaddress_struct_h->h_addrsequence_num));
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_NO",p_mt_msgaddress_struct_h->h_msg_ident_no);

                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_TYP",p_mt_msgaddress_struct_h->h_swift_tlx_gcn);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_PRIORITY",p_mt_msgaddress_struct_h->h_priority_ind);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_GCN_ADDR",p_mt_msgaddress_struct_h->h_gcn_addr);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_SWF_ADDR",p_mt_msgaddress_struct_h->h_swift_addr);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_TLX_ADDR",p_mt_msgaddress_struct_h->h_infolex);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_CATEGORY",p_mt_msgaddress_struct_h->h_schedule);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_CONSMSG",p_mt_msgaddress_struct_h->h_comb_msg);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_FAX",p_mt_msgaddress_struct_h->h_fax_addr);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_REFER",p_mt_msgaddress_struct_h->h_identify);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_msgaddress_struct_h->h_access_stamp);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_NOHOLDINGS",p_mt_msgaddress_struct_h->h_holdings);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_ISO15022FORMAT",p_mt_msgaddress_struct_h->h_iso_msg_format);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_EVALUATE_FLG",p_mt_msgaddress_struct_h->h_validate_flag);
                        CO_Rtv_DataInt(chr_p_param_str,"CLN_MSG_SCHSEQ_NUM",&(p_mt_msgaddress_struct_h->h_schsequence_num));

                        /* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */
 
                     CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_RESP_CONS54X",p_mt_msgaddress_struct_h->h_cln_msg_resp_cons54x);
                        CO_Rtv_DataString(chr_p_param_str,"CLN_MSG_GEN_REC_DP",p_mt_msgaddress_struct_h->h_cln_msg_gen_rec_dp);
                        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_msgaddress_struct_h->h_maker);
                        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_msgaddress_struct_h->h_maker_dt);
                        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_msgaddress_struct_h->h_checker);
                        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_msgaddress_struct_h->h_checker_dt);

                        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_msgaddress_struct_h->h_status);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientAddrPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientAddrPopulate \n",NULL,NULL);
        return 1; */
}

/* Include for - REGDETAILS  - RFSNo - HDFCMT_001 - Kouser */

int   MT_Proc_ClientRegPopulate(MT_REGDETAILS_STRUCT_H   *p_mt_regdetails_struct_h,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientRegPopulate \n",NULL,NULL);
               printf("Entered Into Reg Populate\n");

               CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_regdetails_struct_h->h_dl_client);
               CO_Rtv_DataString(chr_p_param_str,"CLN_SEBI_REG_NO",p_mt_regdetails_struct_h->h_cln_sebi_reg_no);
               CO_Rtv_DataString(chr_p_param_str,"CLN_SEBI_REG_DT",p_mt_regdetails_struct_h->h_cln_sebi_reg_dt);
               CO_Rtv_DataString(chr_p_param_str,"CLN_SEBI_REG_EXPDT",p_mt_regdetails_struct_h->h_cln_sebi_reg_expdt);
               CO_Rtv_DataString(chr_p_param_str,"CLN_RBI_REG_NO",p_mt_regdetails_struct_h->h_cln_rbi_reg_no);
               CO_Rtv_DataString(chr_p_param_str,"CLN_RBI_REG_DT",p_mt_regdetails_struct_h->h_cln_rbi_reg_dt);
               CO_Rtv_DataString(chr_p_param_str,"CLN_RBI_REG_EXPDT",p_mt_regdetails_struct_h->h_cln_rbi_reg_expdt);
               CO_Rtv_DataString(chr_p_param_str,"CLN_MAPINID",p_mt_regdetails_struct_h->h_cln_mapinid);
               CO_Rtv_DataString(chr_p_param_str,"CLN_UCC_CODE",p_mt_regdetails_struct_h->h_cln_ucc_code);
               CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_regdetails_struct_h->h_access_stamp);
               CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_regdetails_struct_h->h_maker);
               CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_regdetails_struct_h->h_maker_dt);
               CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_regdetails_struct_h->h_checker);
               CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_regdetails_struct_h->h_checker_dt);

               CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_regdetails_struct_h->h_status);
               CO_Rtv_DataString(chr_p_param_str,"SEBI_SUB_ACC",p_mt_regdetails_struct_h->h_sebi_sub_acc);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
               CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientRegPopulate \n",NULL,NULL);
               return 0;
/* RETURN_FAILURE:

               CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_ClientRegPopulate \n",NULL,NULL);

        return 1; */
}

 /* End Of - Definition - RFSNo - HDFCMT_001 - Kouser */

 /*Added by Prateek on 19052014 for ISKB_XXXX(FPI Maintenance)-START*/
 int   MT_Proc_ClientFpiMapPopulate(MT_CLTFPIMAP_STRUCT_H *p_mt_cltfpimap_struct_h,char *chr_p_param_str)
{
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
		CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_ClientFpiMapPopulate \n",NULL,NULL);

						CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_cltfpimap_struct_h->h_dl_client);
						CO_Rtv_DataString(chr_p_param_str,"NSDL_GRP_ID",p_mt_cltfpimap_struct_h->h_nsdl_grp_id);
						CO_Rtv_DataString(chr_p_param_str,"NSDL_GRP_NAME",p_mt_cltfpimap_struct_h->h_nsdl_grp_name);
						CO_Rtv_DataString(chr_p_param_str,"CUSTOMER_ID",p_mt_cltfpimap_struct_h->h_customer_id);
						CO_Rtv_DataString(chr_p_param_str,"HOLDERS",p_mt_cltfpimap_struct_h->h_holders);
						CO_Rtv_DataString(chr_p_param_str,"OTHER_HOLDERS",p_mt_cltfpimap_struct_h->h_other_holders);
						CO_Rtv_DataString(chr_p_param_str,"KYC_EXPIRY_DT",p_mt_cltfpimap_struct_h->h_kyc_exp_dt);
						CO_Rtv_DataString(chr_p_param_str,"REMARK",p_mt_cltfpimap_struct_h->h_remark);
						CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cltfpimap_struct_h->h_access_stamp);
						CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cltfpimap_struct_h->h_maker);
						CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cltfpimap_struct_h->h_maker_dt);
						CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cltfpimap_struct_h->h_checker);
						CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cltfpimap_struct_h->h_checker_dt);
						CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",&(p_mt_cltfpimap_struct_h->h_cln_exchseq_num));
						CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cltfpimap_struct_h->h_status);
						Alert("Value of Client Code ==%s\n",p_mt_cltfpimap_struct_h->h_dl_client);
						//Alert("Value of Client Name ==%s\n",p_mt_cltfpimap_struct_h->h_cln_name);
						Alert("Value of NSDL Grp ID ==%s\n",p_mt_cltfpimap_struct_h->h_nsdl_grp_id);
						Alert("Value of NSDL Grp Name ==%s\n",p_mt_cltfpimap_struct_h->h_nsdl_grp_name);
						Alert("Value of Customer ID ==%s\n",p_mt_cltfpimap_struct_h->h_customer_id);
						Alert("Value of Holders ==%s\n",p_mt_cltfpimap_struct_h->h_holders);
						Alert("Value of Seq Number ==%d\n",p_mt_cltfpimap_struct_h->h_cln_exchseq_num);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

		CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_ClientFpiMapPopulate \n",NULL,NULL);
		return 0;

}
 /*Added by Prateek on 19052014 for ISKB_XXXX(FPI Maintenance)-END*/



/* Kouser - RFSNo - KB_001 */

int Populate_MT_CLN_ADDLN_DET(MT_CLN_ADDLN_DET_STRUCT_H *p_mt_cln_addln_det_struct_h,char *p_param_data) 
{ 
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	      CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_Populate_MT_CLN_ADDLN_DET \n",NULL,NULL);

 CO_Rtv_DataString(p_param_data,"CLN_CODE",p_mt_cln_addln_det_struct_h -> h_cln_code);
 CO_Rtv_DataString(p_param_data,"ACC_OPN_DT",p_mt_cln_addln_det_struct_h -> h_acc_opn_dt);
 CO_Rtv_DataString(p_param_data,"ACC_ACTV_DT",p_mt_cln_addln_det_struct_h -> h_acc_actv_dt);

  CO_Rtv_DataString(p_param_data,"ACC_CLS_DT",p_mt_cln_addln_det_struct_h -> h_acc_cls_dt);
     CO_Rtv_DataString(p_param_data,"CERT_PUB_ACC",p_mt_cln_addln_det_struct_h -> h_cert_pub_acc);
		      CO_Rtv_DataString(p_param_data,"FUND_ACC_MGR",p_mt_cln_addln_det_struct_h -> h_fund_acc_mgr);
				      CO_Rtv_DataString(p_param_data,"SPF_FLG",p_mt_cln_addln_det_struct_h -> h_spf_flg);
  CO_Rtv_DataString(p_param_data,"SPF_DET",p_mt_cln_addln_det_struct_h -> h_spf_det);
   CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_cln_addln_det_struct_h -> h_access_stamp);
  CO_Rtv_DataString(p_param_data,"MAKER",p_mt_cln_addln_det_struct_h -> h_maker);
    CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_cln_addln_det_struct_h -> h_maker_dt);
	  CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_cln_addln_det_struct_h -> h_checker);
	   CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_cln_addln_det_struct_h -> h_checker_dt);
	   CO_Rtv_DataString(p_param_data,"STATUS",p_mt_cln_addln_det_struct_h -> h_status);
	   CO_Rtv_DataDbl(p_param_data,"TOL_LMT",&(p_mt_cln_addln_det_struct_h -> h_tolerance_limit));/* Added By Vijay */
	/*CHITRLEKHA Client Additional Details */
	CO_Rtv_DataString(p_param_data,"EFFECTIVE_DT",p_mt_cln_addln_det_struct_h -> h_effective_dt);	
	CO_Rtv_DataString(p_param_data,"SEC_CERT_PUB_ACC",p_mt_cln_addln_det_struct_h -> h_sec_cert_pub_acc);
	CO_Rtv_DataString(p_param_data,"FATCA1",p_mt_cln_addln_det_struct_h -> h_fatca1);
	CO_Rtv_DataString(p_param_data,"FATCA2",p_mt_cln_addln_det_struct_h -> h_fatca2);
	CO_Rtv_DataString(p_param_data,"FATCA3",p_mt_cln_addln_det_struct_h -> h_fatca3);
	/*CHITRLEKHA Client Additional Details */
	/*PANITH CSGL STARTS*/
	CO_Rtv_DataString(p_param_data,"LEI_NUMBER",p_mt_cln_addln_det_struct_h -> h_lei_number);
	CO_Rtv_DataString(p_param_data,"CKYC_NUMBER",p_mt_cln_addln_det_struct_h -> h_ckyc_number);
	CO_Rtv_DataString(p_param_data,"LEI_DATE",p_mt_cln_addln_det_struct_h -> h_lei_date);
	CO_Rtv_DataString(p_param_data,"LEI_EXP_DATE",p_mt_cln_addln_det_struct_h -> h_lei_exp_date);
	/*PANITH CSGL ENDS*/

			printf("VAl of status populate==%s\n",p_mt_cln_addln_det_struct_h->h_status);
APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_MT_CLN_ADDLN_DET \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_MT_CLN_ADDLN_DET \n",NULL,NULL);
        return 1; */
 }
/* Kouser - KB_001 - Maintenance */

int   MT_Proc_CustCashPopulate(DL_CASHACC_STRUCT_H    *l_dl_cashacc_struct_ha,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CustCashPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",l_dl_cashacc_struct_ha->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"CURRENCY_CD",l_dl_cashacc_struct_ha->h_currencycode);
                        CO_Rtv_DataString(chr_p_param_str,"GL_ACCOUNT",l_dl_cashacc_struct_ha->h_ibbsclient);
                        CO_Rtv_DataString(chr_p_param_str,"DEFAULT_CCY",l_dl_cashacc_struct_ha->h_defcurrency_flg);
                        CO_Rtv_DataString(chr_p_param_str,"IBAN_CLT",l_dl_cashacc_struct_ha->h_ibanclient);
								CO_Rtv_DataString(chr_p_param_str,"ADDITION_ACC",l_dl_cashacc_struct_ha->h_addnlclient);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CustCashPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CustCashPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_AssisPopulate(MHLP_CODE_STRUCT_H      *l_mhlp_code_struct_hc,char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_AssisPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"MHLP_CODE",l_mhlp_code_struct_hc->h_mhlp_code);
                        CO_Rtv_DataString(chr_p_param_str,"LCL_BRKCD",l_mhlp_code_struct_hc->h_lcl_brkcd);
                        CO_Rtv_DataString(chr_p_param_str,"LBRK_OPCODE",l_mhlp_code_struct_hc->h_lcl_opcd);
                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",l_mhlp_code_struct_hc->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"MASTER_CLT",l_mhlp_code_struct_hc->h_mstclt);
                        CO_Rtv_DataString(chr_p_param_str,"CUSTODIAN_CLT",l_mhlp_code_struct_hc->h_custodian_clt);
                        CO_Rtv_DataString(chr_p_param_str,"MANUAL_IND",l_mhlp_code_struct_hc->h_manual_ind_intn);
                        CO_Rtv_DataString(chr_p_param_str,"MAKER",l_mhlp_code_struct_hc->h_maker);
                        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",l_mhlp_code_struct_hc->h_maker_dt);
                        CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",l_mhlp_code_struct_hc->h_checker);
                        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",l_mhlp_code_struct_hc->h_checker_dt);
                        CO_Rtv_DataString(chr_p_param_str,"MHLP_STAT",l_mhlp_code_struct_hc->h_mhlp_stat);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",l_mhlp_code_struct_hc->h_access_stamp);
                        CO_Rtv_DataString(chr_p_param_str,"LCL_BRK_MAST",l_mhlp_code_struct_hc->h_lbrk_mstclt);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_AssisPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_AssisPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_AssisOthPopulate(char *chr_p_assiscode, char *chr_p_lbrkcode, char *chr_l_access_stamp, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_AssisOthPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"ASSISCODE",chr_p_assiscode);
         CO_Rtv_DataString(chr_p_param_str,"LBRKCODE",chr_p_lbrkcode);
         CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",chr_l_access_stamp);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_AssisOthPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_AssisOthPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_MsgConvPopulate(MS_MSGCONV_STRUCT_H    *p_ms_msgconv_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_MsgConvPopulate \n",NULL,NULL);

                        CO_Rtv_DataString(chr_p_param_str,"CLIENT",p_ms_msgconv_struct_h->h_dl_client);
                        CO_Rtv_DataString(chr_p_param_str,"SETL_EFFECTIVE_DATE",p_ms_msgconv_struct_h->h_setl_eff_date);
                        CO_Rtv_DataString(chr_p_param_str,"STAT_EFF_DATE",p_ms_msgconv_struct_h->h_stat_eff_date);
                        CO_Rtv_DataString(chr_p_param_str,"CA_EFFECTIVE_DT",p_ms_msgconv_struct_h->h_ca_eff_date);
                        CO_Rtv_DataString(chr_p_param_str,"STMSG_EFFECT_DATE",p_ms_msgconv_struct_h->h_stmsg_eff_date);
                        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_ms_msgconv_struct_h->h_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_MsgConvPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_MsgConvPopulate \n",NULL,NULL);
        return 1; */
}

int	MT_Proc_CpyCustSchPopulate(char *chr_p_from_acct, char *chr_p_to_acct, char *chr_p_from_acct_access_stamp,
										char *chr_p_to_acct_access_stamp, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CpyCustSchPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"FROMACCESSSTAMP",chr_p_from_acct_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"FROMACCOUNT",chr_p_from_acct);
         CO_Rtv_DataString(chr_p_param_str,"TOACCESSSTAMP",chr_p_to_acct_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"TOACCOUNT",chr_p_to_acct);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CpyCustSchPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CpyCustSchPopulate \n",NULL,NULL);
        return 1; */
}

int	MT_Proc_CpyCustMemoPopulate(char *chr_p_from_acct, char *chr_p_to_acct, char *chr_p_from_acct_access_stamp,
										 char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CpyCustMemoPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"FROMACCESSSTAMP",chr_p_from_acct_access_stamp);
         CO_Rtv_DataString(chr_p_param_str,"FROMACCOUNT",chr_p_from_acct);
         CO_Rtv_DataString(chr_p_param_str,"TOACCOUNT",chr_p_to_acct);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CpyCustMemoPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CpyCustMemoPopulate \n",NULL,NULL);
        return 1; */
}

int MT_Proc_CustPopulate(MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CustPopulate \n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"CLIENT",p_mt_ruclient_struct_h->h_dl_client);
   CO_Rtv_DataString(chr_p_param_str,"CLIENT_NAME",p_mt_ruclient_struct_h->h_cltnm);
   CO_Rtv_DataString(chr_p_param_str,"SYN_CLIENT",p_mt_ruclient_struct_h->h_synclt);
   CO_Rtv_DataString(chr_p_param_str,"CLTTYP",p_mt_ruclient_struct_h->h_clttyp);
   CO_Rtv_DataString(chr_p_param_str,"CLT_TYP",p_mt_ruclient_struct_h->h_clt_typ);
   CO_Rtv_DataInt(chr_p_param_str,"BASECLT",&(p_mt_ruclient_struct_h->h_baseclt));
   CO_Rtv_DataString(chr_p_param_str,"CLIENT_OPDT",p_mt_ruclient_struct_h->h_cltopdt);
   CO_Rtv_DataString(chr_p_param_str,"CLIENT_CLOSE_DT",p_mt_ruclient_struct_h->h_cltcldt);
   CO_Rtv_DataString(chr_p_param_str,"NOSTR_CLTTYP",p_mt_ruclient_struct_h->h_nostr_cltptyp);
   CO_Rtv_DataString(chr_p_param_str,"NOSTR_CLTTYP",p_mt_ruclient_struct_h->h_nostr_clttyp);
   CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_ruclient_struct_h->h_maker);
   CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_ruclient_struct_h->h_maker_dt);
   CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_ruclient_struct_h->h_checker);
   CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_ruclient_struct_h->h_checker_dt);
   CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",p_mt_ruclient_struct_h->h_access_stamp);
   CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",p_mt_ruclient_struct_h->h_newdt);
   CO_Rtv_DataString(chr_p_param_str,"ACCSTATUS",p_mt_ruclient_struct_h->h_cltstatus);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CustPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CustPopulate \n",NULL,NULL);
        return 1; */
}

int   MT_Proc_CustOthPopulate(char *chr_p_acct, char *chr_p_acct_access_stamp, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CustOthPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"CLIENT",chr_p_acct);
         CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",chr_p_acct_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CustOthPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CustOthPopulate \n",NULL,NULL);
        return 1; */
}

int MT_Proc_RRLocPopulate(MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h_a, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRLocPopulate \n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"LOC",p_mt_ruloc_struct_h_a->h_loc);
   CO_Rtv_DataString(chr_p_param_str,"LOC_NAME",p_mt_ruloc_struct_h_a->h_locm);
   CO_Rtv_DataString(chr_p_param_str,"SYN_LOCATION",p_mt_ruloc_struct_h_a->h_syn_location);
   CO_Rtv_DataString(chr_p_param_str,"LICENSE_NO",p_mt_ruloc_struct_h_a->h_license_no);
   CO_Rtv_DataString(chr_p_param_str,"LOC_TYPE",p_mt_ruloc_struct_h_a->h_loc_class);
   CO_Rtv_DataString(chr_p_param_str,"DEPO_CD",p_mt_ruloc_struct_h_a->h_depo_cd);
   CO_Rtv_DataInt(chr_p_param_str,"BASELOCATION",&(p_mt_ruloc_struct_h_a->h_baseloc));
   CO_Rtv_DataString(chr_p_param_str,"LOC_OPDATE",p_mt_ruloc_struct_h_a->h_locopdate);
   CO_Rtv_DataString(chr_p_param_str,"LOC_CLOSE_DT",p_mt_ruloc_struct_h_a->h_loccldate);
   CO_Rtv_DataString(chr_p_param_str,"NOSTR_CLTTYP",p_mt_ruloc_struct_h_a->h_nostr_cltptyp);
   CO_Rtv_DataString(chr_p_param_str,"NOSTR_CLTTYP",p_mt_ruloc_struct_h_a->h_nostr_clttyp);
   CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_ruloc_struct_h_a->h_maker);
   CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_ruloc_struct_h_a->h_maker_dt);
   CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_ruloc_struct_h_a->h_checker);
   CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_ruloc_struct_h_a->h_checker_dt);
   CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",p_mt_ruloc_struct_h_a->h_access_stamp);
   CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",p_mt_ruloc_struct_h_a->h_newdt);
   CO_Rtv_DataString(chr_p_param_str,"RULOCSTATUS",p_mt_ruloc_struct_h_a->h_rulocstatus_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RRLocPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRLocPopulate \n",NULL,NULL);
        return 1; */
}

 int   MT_Proc_RRLocOthPopulate(char *chr_p_rrloc, char *chr_p_rrloc_access_stamp, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRLocOthPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"LOC",chr_p_rrloc);
         CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",chr_p_rrloc_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_Proc_RRLocOthPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRLocOthPopulate \n",NULL,NULL);
        return 1; */
}

int MT_Proc_RRProdPopulate(MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_c, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRProdPopulate \n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"PR_CODE",p_mt_ruprod_struct_h_c->h_pr_code);
   CO_Rtv_DataString(chr_p_param_str,"PR_DET",p_mt_ruprod_struct_h_c->h_prdetail);
   CO_Rtv_DataString(chr_p_param_str,"CURRENCY",p_mt_ruprod_struct_h_c->h_ccy);
   CO_Rtv_DataString(chr_p_param_str,"DAYDT",p_mt_ruprod_struct_h_c->h_daydate);
   CO_Rtv_DataString(chr_p_param_str,"DAY_YEAR",p_mt_ruprod_struct_h_c->h_day_yr);
   CO_Rtv_DataString(chr_p_param_str,"PRD_TYPE",p_mt_ruprod_struct_h_c->h_prdateyp);
   CO_Rtv_DataString(chr_p_param_str,"INTTYPE",p_mt_ruprod_struct_h_c->h_intclass);
   CO_Rtv_DataString(chr_p_param_str,"LOC",p_mt_ruprod_struct_h_c->h_loc);
   CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_ruprod_struct_h_c->h_maker);
   CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_ruprod_struct_h_c->h_maker_dt);
   CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_ruprod_struct_h_c->h_checker);
   CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_ruprod_struct_h_c->h_checker_dt);
   CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",p_mt_ruprod_struct_h_c->h_access_stamp);
   CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",p_mt_ruprod_struct_h_c->h_newdt);
   CO_Rtv_DataString(chr_p_param_str,"PRODSTATUS",p_mt_ruprod_struct_h_c->h_prodstatus_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RRProdPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRProdPopulate \n",NULL,NULL);
        return 1; */
}

 int   MT_Proc_RRProdOthPopulate(char *chr_p_rrprod, char *chr_p_rrprod_access_stamp, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRProdOthPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"PR_CODE",chr_p_rrprod);
        CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",chr_p_rrprod_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RRProdOthPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRProdOthPopulate \n",NULL,NULL);
        return 1; */
}


int MT_Proc_WTRPopulate(MT_WHTRATE_STRUCT_H *p_mt_whtrate_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_WTRPopulate\n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"CNTRYCODE",p_mt_whtrate_struct_h->h_nationcode);
   CO_Rtv_DataString(chr_p_param_str,"PROD_CLASS",p_mt_whtrate_struct_h->h_prodateype);
   CO_Rtv_DataDbl(chr_p_param_str,"CUSTODYTAXRT",&(p_mt_whtrate_struct_h->h_custodytaxrt));
   CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_whtrate_struct_h->h_maker);
   CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_whtrate_struct_h->h_maker_dt);
   CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_whtrate_struct_h->h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_whtrate_struct_h->h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_whtrate_struct_h->h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_whtrate_struct_h->h_status_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_WTRPopulate   \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_WTRPopulate  \n",NULL,NULL);
        return 1; */
}


int MT_Proc_RRSrnPopulate(MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRSrnPopulate\n",NULL,NULL);

      CO_Rtv_DataString(chr_p_param_str,"STAT_REG_NO",p_mt_rusrn_struct_h->h_stat_reg_no);
      CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_rusrn_struct_h->h_instr_code);
      CO_Rtv_DataString(chr_p_param_str,"INSTR_NAME",p_mt_rusrn_struct_h->h_instr_name);
      CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NUM",p_mt_rusrn_struct_h->h_identiy_num);
      CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_rusrn_struct_h->h_maker);
      CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_rusrn_struct_h->h_maker_dt);
      CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_mt_rusrn_struct_h->h_checker);
      CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_rusrn_struct_h->h_checker_dt);
      CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",p_mt_rusrn_struct_h->h_access_stamp);
      CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",p_mt_rusrn_struct_h->h_newdt);
      CO_Rtv_DataString(chr_p_param_str,"SRNSTATUS",p_mt_rusrn_struct_h->h_srnstatus_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RRSrnPopulate   \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRSrnPopulate  \n",NULL,NULL);
        return 1; */
}


int MT_Proc_RRInstrPopulate(MT_RUINSTR_STRUCT_H *l_mt_ruinstr_struct_ha_a, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RRInstrPopulate\n",NULL,NULL);

   CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",l_mt_ruinstr_struct_ha_a->h_instr_code);
  CO_Rtv_DataString(chr_p_param_str,"INSTR_NM",l_mt_ruinstr_struct_ha_a->h_instr_nm);
  CO_Rtv_DataString(chr_p_param_str,"SNM_IND",l_mt_ruinstr_struct_ha_a->h_snm_ind);
  CO_Rtv_DataString(chr_p_param_str,"STAT_REG_NO",l_mt_ruinstr_struct_ha_a->h_stat_reg_no);
  CO_Rtv_DataString(chr_p_param_str,"INSTRUMENT_OPDT",l_mt_ruinstr_struct_ha_a->h_instr_opdate);
  CO_Rtv_DataString(chr_p_param_str,"SEC_CLDATE",l_mt_ruinstr_struct_ha_a->h_instrcldate);
  CO_Rtv_DataString(chr_p_param_str,"SEC_CLDATE",l_mt_ruinstr_struct_ha_a->h_instr_cldate);
  CO_Rtv_DataInt(chr_p_param_str,"BASEINSTRUMENT",&(l_mt_ruinstr_struct_ha_a->h_baseinstrument));
  CO_Rtv_DataString(chr_p_param_str,"TYPEOFINSTR",l_mt_ruinstr_struct_ha_a->h_instr_class);
  CO_Rtv_DataString(chr_p_param_str,"PR_CODE",l_mt_ruinstr_struct_ha_a->h_pr_code);
  CO_Rtv_DataString(chr_p_param_str,"MAKER",l_mt_ruinstr_struct_ha_a->h_maker);
  CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",l_mt_ruinstr_struct_ha_a->h_maker_dt);
  CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",l_mt_ruinstr_struct_ha_a->h_checker);
  CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",l_mt_ruinstr_struct_ha_a->h_checker_dt);
  CO_Rtv_DataString(chr_p_param_str,"ACCESSSTAMP",l_mt_ruinstr_struct_ha_a->h_access_stamp);
  CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",l_mt_ruinstr_struct_ha_a->h_newdt);
  CO_Rtv_DataString(chr_p_param_str,"RUINSTRSTATUS",l_mt_ruinstr_struct_ha_a->h_ruinstrstatus_ind);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RRInstrPopulate   \n",NULL,NULL);
        return 0;

/*RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RRInstrPopulate  \n",NULL,NULL);
        return 1; */

}

int MT_Proc_InstrPopulate(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h, char *chr_p_param_str)
{
  	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
  	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
  	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
  	CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrPopulate \n",NULL,NULL);

	/*Smita - HDFCMT_003 - Instrument Master Maintenance */ 
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_struct_h -> h_instr_code);
	CO_Rtv_DataString(chr_p_param_str,"CURRENCY_CD",p_mt_instrument_struct_h -> h_currency_cd);
	CO_Rtv_DataString(chr_p_param_str,"LOCATION_CD",p_mt_instrument_struct_h -> h_location_cd);
	CO_Rtv_DataDbl(chr_p_param_str,"NOMINAL_VALUE",&(p_mt_instrument_struct_h -> h_nominal_value));
	CO_Rtv_DataString(chr_p_param_str,"REG_BR_IND",p_mt_instrument_struct_h -> h_reg_br_ind);
	/*Smita - HDFCMT_003 - All the 4 fields ALLOW_RF,ALLOW_RVP,ALLOW_DF,ALLOW_DVP will be 
 	updated with the value for TRADABLE */
		
	CO_Rtv_DataString(chr_p_param_str,"TRADABLE",p_mt_instrument_struct_h->h_allow_rf);
	strcpy(p_mt_instrument_struct_h->h_allow_rvp,p_mt_instrument_struct_h->h_allow_rf);
	strcpy(p_mt_instrument_struct_h->h_allow_df,p_mt_instrument_struct_h->h_allow_rf);
	strcpy(p_mt_instrument_struct_h->h_allow_dvp,p_mt_instrument_struct_h->h_allow_rf);
	 
	CO_Rtv_DataString(chr_p_param_str,"ORD_TYPE",p_mt_instrument_struct_h -> h_ord_type);
	CO_Rtv_DataString(chr_p_param_str,"MOTHER_SEC_IND",p_mt_instrument_struct_h -> h_mother_sec_ind);
	CO_Rtv_DataString(chr_p_param_str,"EX_ARENA",p_mt_instrument_struct_h -> h_ex_arena);
	CO_Rtv_DataString(chr_p_param_str,"LISTED_IND",p_mt_instrument_struct_h -> h_listed_ind);
	CO_Rtv_DataString(chr_p_param_str,"DATEOF_INPUT",p_mt_instrument_struct_h -> h_dateof_input);
	CO_Rtv_DataInt(chr_p_param_str,"THRESHOLD_QTY",(int *) &(p_mt_instrument_struct_h -> h_threshold_qty));
	CO_Rtv_DataString(chr_p_param_str,"NEW_MAKER",p_mt_instrument_struct_h -> h_new_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_struct_h -> h_checker_dt);
	CO_Rtv_DataDbl(chr_p_param_str,"TOTAL_PDCAPITA",&(p_mt_instrument_struct_h -> h_total_pdcapita));
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_struct_h -> h_status);
	CO_Rtv_DataString(chr_p_param_str,"NEW_ISSUE",p_mt_instrument_struct_h -> h_new_issue);
	CO_Rtv_DataString(chr_p_param_str,"NEW_CHECKER",p_mt_instrument_struct_h -> h_new_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHNG_LST_IND",p_mt_instrument_struct_h -> h_chng_lst_ind);
	CO_Rtv_DataString(chr_p_param_str,"CERT_OF_OWN_IN",p_mt_instrument_struct_h -> h_cert_of_own_in);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_NAME",p_mt_instrument_struct_h -> h_instr_name);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_ISIN",p_mt_instrument_struct_h -> h_instr_isin);
	CO_Rtv_DataString(chr_p_param_str,"TIPO_INV",p_mt_instrument_struct_h -> h_tipo_inv);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_TYPE",p_mt_instrument_struct_h -> h_instr_type);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PARENT",p_mt_instrument_struct_h -> h_instr_parent);
	CO_Rtv_DataString(chr_p_param_str,"PROD_CLASS",p_mt_instrument_struct_h -> h_prod_class);
	CO_Rtv_DataString(chr_p_param_str,"SEC_DL_CODE",p_mt_instrument_struct_h -> h_sec_dl_code);
	CO_Rtv_DataString(chr_p_param_str,"CLASSCD",p_mt_instrument_struct_h -> h_classcd);
	CO_Rtv_DataString(chr_p_param_str,"NEW_CD",p_mt_instrument_struct_h -> h_new_cd);
	CO_Rtv_DataString(chr_p_param_str,"CHNG_ISIN",p_mt_instrument_struct_h -> h_chng_isin);
	CO_Rtv_DataString(chr_p_param_str,"ISSUE_DATE",p_mt_instrument_struct_h -> h_issue_date);
	CO_Rtv_DataString(chr_p_param_str,"CHG_MKR",p_mt_instrument_struct_h -> h_chg_mkr);
	CO_Rtv_DataString(chr_p_param_str,"CA_NAME",p_mt_instrument_struct_h -> h_ca_name);
	CO_Rtv_DataString(chr_p_param_str,"CHNG_CD",p_mt_instrument_struct_h -> h_chng_cd);
	CO_Rtv_DataString(chr_p_param_str,"MATURE_DT",p_mt_instrument_struct_h -> h_mature_dt);
	CO_Rtv_DataString(chr_p_param_str,"INT_TYP",p_mt_instrument_struct_h -> h_int_typ);
	CO_Rtv_DataDbl(chr_p_param_str,"INSTR_INT_RATE",&(p_mt_instrument_struct_h -> h_instr_int_rate));
	CO_Rtv_DataString(chr_p_param_str,"FREQ_CODE",p_mt_instrument_struct_h -> h_freq_code);
	CO_Rtv_DataString(chr_p_param_str,"INT_ACCTYP",p_mt_instrument_struct_h -> h_int_acctyp);
	CO_Rtv_DataString(chr_p_param_str,"LAST_PYMT_DATE",p_mt_instrument_struct_h -> h_last_pymt_date);
	CO_Rtv_DataDbl(chr_p_param_str,"LAST_INCOM_RT",&(p_mt_instrument_struct_h -> h_last_incom_rt));
	CO_Rtv_DataString(chr_p_param_str,"NEXT_PAY_DATE",p_mt_instrument_struct_h -> h_next_pay_date);
	CO_Rtv_DataString(chr_p_param_str,"OLD_LST_PAYDT",p_mt_instrument_struct_h -> h_old_lst_paydt);
	CO_Rtv_DataString(chr_p_param_str,"MOD_LAST_PAYDT",p_mt_instrument_struct_h -> h_mod_last_paydt);
	CO_Rtv_DataString(chr_p_param_str,"TAXONMAT_IND",p_mt_instrument_struct_h -> h_taxonmat_ind);
	CO_Rtv_DataString(chr_p_param_str,"DISCT_IND",p_mt_instrument_struct_h -> h_disct_ind);
	CO_Rtv_DataString(chr_p_param_str,"CA_ADDRDET",p_mt_instrument_struct_h -> h_ca_addrdet);
	CO_Rtv_DataDbl(chr_p_param_str,"MIN_FMT_DL_QTY",&(p_mt_instrument_struct_h -> h_min_fmt_dl_qty));
	CO_Rtv_DataString(chr_p_param_str,"LR_SETL_DATE_A",p_mt_instrument_struct_h -> h_lr_setl_date_a);
	CO_Rtv_DataString(chr_p_param_str,"LR_SETL_DATE_B",p_mt_instrument_struct_h -> h_lr_setl_date_b);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_SHORTNM",p_mt_instrument_struct_h -> h_instr_shortnm);
	CO_Rtv_DataString(chr_p_param_str,"IPO_IND",p_mt_instrument_struct_h -> h_ipo_ind);
	CO_Rtv_DataString(chr_p_param_str,"VALID_IPO_DATE",p_mt_instrument_struct_h -> h_valid_ipo_date);
	CO_Rtv_DataString(chr_p_param_str,"LR_SETL_DATE_C",p_mt_instrument_struct_h -> h_lr_setl_date_c);
	CO_Rtv_DataString(chr_p_param_str,"CMP_CODE",p_mt_instrument_struct_h -> h_cmp_code);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_REG_CODE",p_mt_instrument_struct_h -> h_instr_reg_code);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_SWF_NAME",p_mt_instrument_struct_h -> h_instr_swf_name);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PRIV_PLACED",p_mt_instrument_struct_h -> h_instr_priv_placed);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CRISIL_CODE",p_mt_instrument_struct_h -> h_instr_crisil_code);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_IS_SECURED",p_mt_instrument_struct_h -> h_instr_is_secured);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_SECURED_DT",p_mt_instrument_struct_h -> h_instr_secured_dt);
	CO_Rtv_DataDbl(chr_p_param_str,"INSTR_TOT_NOM_VAL",&(p_mt_instrument_struct_h -> h_instr_tot_nom_val));
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PC_IND",p_mt_instrument_struct_h -> h_instr_pc_ind);
	/* - Smita - Commented Effective Date & Cut Off Time - HDFCMT_003 
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PC_EFFDT",p_mt_instrument_struct_h -> h_instr_pc_effdt);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PC_CUTOFFTIME",p_mt_instrument_struct_h -> h_instr_pc_cutofftime);
	*/
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PART_RD_FLG",p_mt_instrument_struct_h -> h_instr_part_rd_flg);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_RESET_FLG",p_mt_instrument_struct_h -> h_instr_reset_flg);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_EXDT_LOA",p_mt_instrument_struct_h -> h_instr_exdt_loa);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_FST_PYMT_DT",p_mt_instrument_struct_h -> h_instr_fst_pymt_dt);
	CO_Rtv_DataDbl(chr_p_param_str,"INSTR_DIV_RATE",&(p_mt_instrument_struct_h -> h_instr_div_rate));
	CO_Rtv_DataString(chr_p_param_str,"INSTR_IS_DEMAT",p_mt_instrument_struct_h -> h_instr_is_demat);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_REMARK",p_mt_instrument_struct_h -> h_instr_remark);
	CO_Rtv_DataInt(chr_p_param_str,"INSTRSHUT_PERIOD",(int *) &(p_mt_instrument_struct_h -> h_instrshut_period));
	CO_Rtv_DataString(chr_p_param_str,"INSTR_ISIN_NAME",p_mt_instrument_struct_h -> h_instr_isin_name);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_ATTACHED",p_mt_instrument_struct_h -> h_instr_attached);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_DETACH_DT",p_mt_instrument_struct_h -> h_instr_detach_dt);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_SUB_TYPE",p_mt_instrument_struct_h -> h_instr_sub_type);
	//Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- Start 
	CO_Rtv_DataString(chr_p_param_str,"INSTR_TIER_1",p_mt_instrument_struct_h -> h_instr_tier_1);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_TIER_2",p_mt_instrument_struct_h -> h_instr_tier_2);
	// Added by Bawa -- 8/11/2008 -- RBI Monthly Investment Report -- End 
	/* Added  by Gouse For Decimal Length of MF- Start - 31/10/2011 */
        CO_Rtv_DataInt(chr_p_param_str,"DEC_LEN_MF",(int*)&(p_mt_instrument_struct_h->h_dec_len_mf));	
        /* Added  by Gouse For Decimal Length of MF- End - 31/10/2011 */
		//Retro from ICICI for CLM by Bhuvana 
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CORPORATE_GRP",&(p_mt_instrument_struct_h -> h_instr_corporate_grp));
	printf("**** h_instr_corporate_grp : %s\n",p_mt_instrument_struct_h -> h_instr_corporate_grp);
	CO_Rtv_DataDbl(chr_p_param_str,"INSTR_DILUTED_RATIO_NEW",&(p_mt_instrument_struct_h -> h_instr_diluted_ratio_new));
	CO_Rtv_DataDbl(chr_p_param_str,"INSTR_DILUTED_RATIO_OLD",&(p_mt_instrument_struct_h -> h_instr_diluted_ratio_old));
    //Retro from ICICI for CLM by Bhuvana
	printf("**** h_allow_rf : %s\n",p_mt_instrument_struct_h->h_allow_rf);
	printf("**** h_allow_rvp: %s\n",p_mt_instrument_struct_h->h_allow_rvp);
	printf("**** h_allow_df : %s\n",p_mt_instrument_struct_h->h_allow_df);
	printf("**** h_allow_dvp : %s\n",p_mt_instrument_struct_h->h_allow_dvp);
	printf("**** DEC_LEN_MF : %d\n",p_mt_instrument_struct_h->h_dec_len_mf);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrPopulate \n",NULL,NULL);
        return 1; */
}


int MT_Proc_CorpGrpPopulate(MT_INST_CORP_GRP_STRUCT_H *p_mt_inst_corp_grp_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
  	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
  	
	CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CorpGrpPopulate \n",NULL,NULL);
	
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_inst_corp_grp_struct_h -> h_instr_code);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_CORPORATE_GRP",p_mt_inst_corp_grp_struct_h -> h_instr_corporate_grp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_inst_corp_grp_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_inst_corp_grp_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_inst_corp_grp_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_inst_corp_grp_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_inst_corp_grp_struct_h -> h_checker_dt);
   
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CorpGrpPopulate \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CorpGrpPopulate \n",NULL,NULL);
        return 1;
}




 int MT_Proc_InstrOthPopulate(char *p_instr_code,char *chr_p_access_stamp, char *chr_p_param_str)
{
  void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
  void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
  void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
  CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrOthPopulate \n",NULL,NULL);

  CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_instr_code);
  CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",chr_p_access_stamp);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
  		 CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrOthPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrOthPopulate \n",NULL,NULL);
        return 1; */
}

/*Smita - Instrument Master Maintenance - HDFCMT_003*/
int MT_Proc_InstrRedDepPopulate(MT_INSTRUMENT_RED_DEP_STRUCT_H *p_mt_instrument_red_dep_struct_h, char *chr_p_param_str)
{
  	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
  	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
 	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
  	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

  	CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrRedDepPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_red_dep_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_red_dep_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"RD_CLIENT_ID",p_mt_instrument_red_dep_struct_h -> h_rd_client_id);
	CO_Rtv_DataString(chr_p_param_str,"RD_DP_ID",p_mt_instrument_red_dep_struct_h -> h_rd_dp_id);
	CO_Rtv_DataString(chr_p_param_str,"RD_DEPO_CODE",p_mt_instrument_red_dep_struct_h -> h_rd_depo_code);
	CO_Rtv_DataString(chr_p_param_str,"IPA_CODE",p_mt_instrument_red_dep_struct_h -> h_ipa_code);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_red_dep_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_red_dep_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_red_dep_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_red_dep_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_red_dep_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_red_dep_struct_h -> h_status);
	
	APL_GOBACK_SUCCESS 
	RETURN_SUCCESS:
		CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrRedDepPopulate \n",NULL,NULL);
		return 0;

	/* RETURN_FAILURE:
		CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrRedDepPopulate \n",NULL,NULL);
		return 1; */
}

int MT_Proc_InstrExchPopulate(MT_INSTRUMENT_EXCH_STRUCT_H *p_mt_instrument_exch_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrExchPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_exch_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_exch_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_mt_instrument_exch_struct_h -> h_exch_code);
	CO_Rtv_DataString(chr_p_param_str,"SCRIP_GRP",p_mt_instrument_exch_struct_h -> h_scrip_grp);
 CO_Rtv_DataString(chr_p_param_str,"MKT_TYPE",p_mt_instrument_exch_struct_h -> h_mkt_type);
	CO_Rtv_DataString(chr_p_param_str,"EXCH_INSTR_CODE",p_mt_instrument_exch_struct_h -> h_exch_instr_code);
	CO_Rtv_DataString(chr_p_param_str,"LISTING_STATUS",p_mt_instrument_exch_struct_h -> h_listing_status);
	CO_Rtv_DataString(chr_p_param_str,"LISTING_DATE",p_mt_instrument_exch_struct_h -> h_listing_date);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_exch_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_exch_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_exch_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_exch_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_exch_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_exch_struct_h -> h_status);
	CO_Rtv_DataString(chr_p_param_str,"SCRIP_CODE",p_mt_instrument_exch_struct_h -> h_scrip_code); /* Chages by rahul6 for T0 Enhancement */

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrExchPopulate \n",NULL,NULL);
        return 0;

  /*  RETURN_FAILURE:
		 CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrExchPopulate \n",NULL,NULL);
  	    return 1; */
}

int MT_Proc_InstrCRAgencyPopulate(MT_INSTRUMENT_CR_AGENCY_STRUCT_H *p_mt_instrument_cr_agency_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrCRAgencyPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_cr_agency_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_cr_agency_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"CR_AGENCY_CODE",p_mt_instrument_cr_agency_struct_h -> h_cr_agency_code);
	CO_Rtv_DataString(chr_p_param_str,"RATING_CODE",p_mt_instrument_cr_agency_struct_h -> h_rating_code);
	CO_Rtv_DataString(chr_p_param_str,"EFFDT_FR",p_mt_instrument_cr_agency_struct_h -> h_effdt_fr);
	CO_Rtv_DataString(chr_p_param_str,"EFFDT_TO",p_mt_instrument_cr_agency_struct_h -> h_effdt_to);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_cr_agency_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_cr_agency_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_cr_agency_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_cr_agency_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_cr_agency_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_cr_agency_struct_h -> h_status);

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrCRAgencyPopulate \n",NULL,NULL);
         return 0;

  /*  RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrCRAgencyPopulate \n",NULL,NULL);
         return 1; */
}

int MT_Proc_InstrPCPopulate(MT_INSTRUMENT_PC_STRUCT_H *p_mt_instrument_pc_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrPCPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_pc_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_pc_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"PC_FLAG",p_mt_instrument_pc_struct_h -> h_pc_flag);
	CO_Rtv_DataString(chr_p_param_str,"PC_DATE",p_mt_instrument_pc_struct_h -> h_pc_date);
	CO_Rtv_DataString(chr_p_param_str,"PC_NOTICE_DATE",p_mt_instrument_pc_struct_h ->h_pc_notice_date);
	/*Smita - Added Effective Date and Cut Off Time = HDFCMT_003*/
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PC_EFFDT",p_mt_instrument_pc_struct_h -> h_instr_pc_effdt);
	CO_Rtv_DataString(chr_p_param_str,"INSTR_PC_CUTOFFTIME",p_mt_instrument_pc_struct_h -> h_instr_pc_cutofftime);
	/*Smita - Added Effective Date and Cut Off Time = HDFCMT_003*/
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_pc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_pc_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_pc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_pc_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_pc_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_pc_struct_h -> h_status);

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrPCPopulate \n",NULL,NULL);
         return 0;

 /*   RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrPCPopulate \n",NULL,NULL);
         return 1; */
}

int MT_Proc_InstrPartRedPopulate(MT_INSTRUMENT_PART_RED_STRUCT_H *p_mt_instrument_part_red_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrPartRedPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_part_red_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_part_red_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"RED_DT",p_mt_instrument_part_red_struct_h -> h_red_dt);
        CO_Rtv_DataDbl(chr_p_param_str,"RED_PCT",&(p_mt_instrument_part_red_struct_h -> h_red_pct));
	CO_Rtv_DataDbl(chr_p_param_str,"RED_VALUE",&(p_mt_instrument_part_red_struct_h -> h_red_value));
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_part_red_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_part_red_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_part_red_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_part_red_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_part_red_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_part_red_struct_h -> h_status);

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrPartRedPopulate \n",NULL,NULL);
         return 0;

   /* RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrPartRedPopulate \n",NULL,NULL);
         return 1; */
}

int MT_Proc_InstrPTCPopulate(MT_INSTRUMENT_PTC_STRUCT_H *p_mt_instrument_ptc_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrPTCPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_ptc_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_ptc_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"PTC_DT",p_mt_instrument_ptc_struct_h -> h_ptc_dt);
	CO_Rtv_DataDbl(chr_p_param_str,"PTC_PRIN_AMT",&(p_mt_instrument_ptc_struct_h -> h_ptc_prin_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"PTC_INT_AMT",&(p_mt_instrument_ptc_struct_h -> h_ptc_int_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"PTC_VALUE",&(p_mt_instrument_ptc_struct_h -> h_ptc_value));
	CO_Rtv_DataString(chr_p_param_str,"PTC_PAID_FLG",p_mt_instrument_ptc_struct_h -> h_ptc_paid_flg);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_ptc_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_ptc_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_ptc_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_ptc_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_ptc_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_ptc_struct_h -> h_status);
	CO_Rtv_DataDbl(chr_p_param_str,"PTC_BAL_VAL",&(p_mt_instrument_ptc_struct_h -> h_ptc_bal_val));

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrPTCPopulate \n",NULL,NULL);
         return 0;

  /*  RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrPTCPopulate \n",NULL,NULL);
         return 1; */
}

int MT_Proc_InstrResetPopulate(MT_INSTRUMENT_RESET_STRUCT_H *p_mt_instrument_reset_struct_h, char *chr_p_param_str)
{
   void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
   void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
   void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);

   CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_InstrResetPopulate \n",NULL,NULL);

  	CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_instrument_reset_struct_h -> h_instr_code);
	CO_Rtv_DataInt(chr_p_param_str,"INSTR_SEQ_NUM",(int *) &(p_mt_instrument_reset_struct_h -> h_instr_seq_num));
	CO_Rtv_DataString(chr_p_param_str,"RESET_DT",p_mt_instrument_reset_struct_h -> h_reset_dt);
	CO_Rtv_DataDbl(chr_p_param_str,"RESET_RATE",&(p_mt_instrument_reset_struct_h -> h_reset_rate));
	CO_Rtv_DataString(chr_p_param_str,"RESET_FRDT",p_mt_instrument_reset_struct_h -> h_reset_frdt);
	CO_Rtv_DataString(chr_p_param_str,"RESET_TODT",p_mt_instrument_reset_struct_h -> h_reset_todt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_instrument_reset_struct_h -> h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_instrument_reset_struct_h -> h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_instrument_reset_struct_h -> h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_instrument_reset_struct_h -> h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_instrument_reset_struct_h -> h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_instrument_reset_struct_h -> h_status);

   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_InstrResetPopulate \n",NULL,NULL);
         return 0;

   /* RETURN_FAILURE:
         CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_InstrResetPopulate \n",NULL,NULL);
         return 1; */
}
/*Smita - Instrument Master Maintenance - HDFCMT_003*/

int MT_Proc_RptPopulate(char *chr_p_filename_a,char *p_repdesc, int *p_repwidateh, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        char chr_l_temp_repdesc[100]=APL_NULL_STRING; 
        memset(chr_l_temp_repdesc,APL_NULL_CHAR,100);

        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_RptPopulate \n",NULL,NULL);

         CO_Rtv_DataString(chr_p_param_str,"NAMEOF_FILE",chr_p_filename_a);
         
	   	CO_Rtv_DataString(chr_p_param_str,"REPORT_DESC",chr_l_temp_repdesc);
         strncpy(p_repdesc,chr_l_temp_repdesc,APL_REPDESC_LENGTH - 1); 

         CO_Rtv_DataInt(chr_p_param_str,"REPORT_WIDTH",p_repwidateh);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_RptPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_RptPopulate \n",NULL,NULL);
        return 1; */
}

int MT_Proc_HDATPopulate(PRO_HDAT_STATIC_STRUCT_H *p_pro_hdat_static_struct_h, char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_HDATPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"MEM_IDENT",p_pro_hdat_static_struct_h->h_mem_ident);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_pro_hdat_static_struct_h->h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_pro_hdat_static_struct_h->h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"AUTHORISOR",p_pro_hdat_static_struct_h->h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_pro_hdat_static_struct_h->h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_pro_hdat_static_struct_h->h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_pro_hdat_static_struct_h->h_status_ind);
	CO_Rtv_DataString(chr_p_param_str,"INSTRUCT_CLT",p_pro_hdat_static_struct_h->h_instr_clt);
	CO_Rtv_DataString(chr_p_param_str,"BRKCD",p_pro_hdat_static_struct_h->h_brkcd);
	CO_Rtv_DataString(chr_p_param_str,"ALTERNATE_BIDCD",p_pro_hdat_static_struct_h->h_alternate_bidcd);
	CO_Rtv_DataString(chr_p_param_str,"DETAIL",p_pro_hdat_static_struct_h->h_detailription);
	CO_Rtv_DataString(chr_p_param_str,"MTCH_INFO",p_pro_hdat_static_struct_h->h_mtch_detail);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_HDATPopulate \n",NULL,NULL);
	return 0;

/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_HDATPopulate \n",NULL,NULL);
	return 1; */
}

int   CPopulateDealStruct(DEAL_STRUCT_H  *p_deal_struct,char *chr_p_param_str)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered CPopulateDealStruct \n",NULL,NULL);

			 CO_Rtv_DataString(chr_p_param_str,"CLIENTCODE",p_deal_struct->client_code);
        CO_Rtv_DataString(chr_p_param_str,"CLIENTREFERENCENO",p_deal_struct->client_reference_no);
        CO_Rtv_DataInt(chr_p_param_str,"MARKETTYPE",&(p_deal_struct->market_type));
        CO_Rtv_DataString(chr_p_param_str,"DEALDATE",p_deal_struct->deal_date);
        CO_Rtv_DataString(chr_p_param_str,"RECEIVEDDATE",p_deal_struct->received_date);
        CO_Rtv_DataString(chr_p_param_str,"BUYSALE",p_deal_struct->buy_sale);
        CO_Rtv_DataString(chr_p_param_str,"CLHDVP",p_deal_struct->clh_dvp);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENTCODE",p_deal_struct->instrument_code);
        CO_Rtv_DataString(chr_p_param_str,"INSTRUMENTTYPE",p_deal_struct->instrument_type);
        CO_Rtv_DataString(chr_p_param_str,"SCRIPGROUP",p_deal_struct->scrip_group);
        CO_Rtv_DataString(chr_p_param_str,"PARTYCODE",p_deal_struct->party_code);
        CO_Rtv_DataString(chr_p_param_str,"EXCHANGECODE",p_deal_struct->exchange_code);
        CO_Rtv_DataString(chr_p_param_str,"COUNTERPARTY",p_deal_struct->counter_party);
        CO_Rtv_DataString(chr_p_param_str,"COUNTERPARTYCUSTODIAN",p_deal_struct->counter_party_custodian);
        CO_Rtv_DataString(chr_p_param_str,"SETTLEMENTPARTY",p_deal_struct->settlement_party);
        CO_Rtv_DataDbl(chr_p_param_str,"BROKERAGERATE",&(p_deal_struct->brokerage_rate));
        CO_Rtv_DataDbl(chr_p_param_str,"DEALRATE",&(p_deal_struct->deal_rate));
        CO_Rtv_DataString(chr_p_param_str,"UNIT",p_deal_struct->unit);
        CO_Rtv_DataDbl(chr_p_param_str,"BROKERAGE",&(p_deal_struct->brokerage));
        CO_Rtv_DataString(chr_p_param_str,"SEBIAPPLICABLE",p_deal_struct->sebi_applicable);
        CO_Rtv_DataString(chr_p_param_str,"STREETREGISTERED",p_deal_struct->street_registered);
        CO_Rtv_DataDbl(chr_p_param_str,"DEMATQTY",&(p_deal_struct->demat_qty)); // AIX - Warnings Removal
        CO_Rtv_DataString(chr_p_param_str,"CONTRACTREQUIRED",p_deal_struct->contract_required);
        CO_Rtv_DataString(chr_p_param_str,"MATCHINGDATE",p_deal_struct->matching_date);
        CO_Rtv_DataString(chr_p_param_str,"SETTLEMENTNO",p_deal_struct->settlement_no);
        CO_Rtv_DataString(chr_p_param_str,"SETTLEMENTDATE",p_deal_struct->settlement_date);
        CO_Rtv_DataString(chr_p_param_str,"PAYINDATE",p_deal_struct->payin_date);
        CO_Rtv_DataString(chr_p_param_str,"PAYOUTDATE",p_deal_struct->payout_date);
        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_deal_struct->quantity));
        CO_Rtv_DataDbl(chr_p_param_str,"INTEREST",&(p_deal_struct->interest));
        CO_Rtv_DataDbl(chr_p_param_str,"GROSSVALUE",&(p_deal_struct->gross_value));
        CO_Rtv_DataDbl(chr_p_param_str,"NETVALUE",&(p_deal_struct->net_value));
        CO_Rtv_DataDbl(chr_p_param_str,"NETRATE",&(p_deal_struct->net_rate));
        CO_Rtv_DataString(chr_p_param_str,"SEBINO",p_deal_struct->sebi_no);
        CO_Rtv_DataDbl(chr_p_param_str,"STTAMOUNT",&(p_deal_struct->stt_amount));
        CO_Rtv_DataString(chr_p_param_str,"BENEFITSTATUS",p_deal_struct->benefit_status);
        CO_Rtv_DataString(chr_p_param_str,"LOTCATEGORY",p_deal_struct->lot_category);
        CO_Rtv_DataString(chr_p_param_str,"BCFROM",p_deal_struct->bcfrom);
        CO_Rtv_DataString(chr_p_param_str,"BCTO",p_deal_struct->bcto);
		 	 CO_Rtv_DataString(chr_p_param_str,"STTNETVALUE",p_deal_struct->Stt_net_value);
        CO_Rtv_DataString(chr_p_param_str,"GISNNO",p_deal_struct->gisn_no);
        CO_Rtv_DataString(chr_p_param_str,"GBSNNO",p_deal_struct->gbsn_no);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CPopulateDealStruct \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CPopulateDealStruct \n",NULL,NULL);
        return 1; */
}

/* ANIL HDFCMT_002 Company Master */
int MT_Proc_CompanyPopulate(MT_COMPANY_STRUCT_H *p_mt_company_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Proc_CompanyPopulate \n",NULL,NULL);
 
        CO_Rtv_DataString(chr_p_param_str,"CMP_CODE",p_mt_company_struct_h->h_cmp_code);
        CO_Rtv_DataString(chr_p_param_str,"CMP_NAME",p_mt_company_struct_h->h_cmp_name);
        CO_Rtv_DataString(chr_p_param_str,"CMP_SHORTNM",p_mt_company_struct_h->h_cmp_shortnm);
        CO_Rtv_DataString(chr_p_param_str,"CMP_OLDNAME",p_mt_company_struct_h->h_cmp_oldname);
        CO_Rtv_DataString(chr_p_param_str,"CMP_ADD1",p_mt_company_struct_h->h_cmp_add1);
        CO_Rtv_DataString(chr_p_param_str,"CMP_ADD2",p_mt_company_struct_h->h_cmp_add2);
        CO_Rtv_DataString(chr_p_param_str,"CITY",p_mt_company_struct_h->h_cmp_add_city);
        CO_Rtv_DataString(chr_p_param_str,"STATE",p_mt_company_struct_h->h_cmp_add_state);
        CO_Rtv_DataString(chr_p_param_str,"COUNTRY",p_mt_company_struct_h->h_cmp_add_cnt);
        CO_Rtv_DataString(chr_p_param_str,"CMP_ADD_PIN",p_mt_company_struct_h->h_cmp_add_pin);
        CO_Rtv_DataString(chr_p_param_str,"CMP_TEL",p_mt_company_struct_h->h_cmp_tel);
        CO_Rtv_DataString(chr_p_param_str,"CMP_FAX",p_mt_company_struct_h->h_cmp_fax);
        CO_Rtv_DataString(chr_p_param_str,"CMP_WEBADD",p_mt_company_struct_h->h_cmp_webadd);
        CO_Rtv_DataString(chr_p_param_str,"CMP_SWF_NAME",p_mt_company_struct_h->h_cmp_swf_name);
        CO_Rtv_DataString(chr_p_param_str,"CMP_SECNM",p_mt_company_struct_h->h_cmp_secnm);
        CO_Rtv_DataString(chr_p_param_str,"CMP_SEC_EMAIL",p_mt_company_struct_h->h_cmp_sec_email);
        CO_Rtv_DataString(chr_p_param_str,"CMP_MDNM",p_mt_company_struct_h->h_cmp_mdnm);
        CO_Rtv_DataString(chr_p_param_str,"CMP_INDUSTRYCD",p_mt_company_struct_h->h_cmp_industrycd);
        CO_Rtv_DataString(chr_p_param_str,"CMP_SECTORCD",p_mt_company_struct_h->h_cmp_sectorcd);
        CO_Rtv_DataString(chr_p_param_str,"CMP_REMARKS",p_mt_company_struct_h->h_cmp_remarks);
        CO_Rtv_DataDbl(chr_p_param_str,"CMP_AUTHCAPITAL",&(p_mt_company_struct_h->h_cmp_authcapital));
        CO_Rtv_DataDbl(chr_p_param_str,"CMP_ISSUEDCAPITAL",&(p_mt_company_struct_h->h_cmp_issuedcapital));
        CO_Rtv_DataDbl(chr_p_param_str,"CMP_TPCAPITAL",&(p_mt_company_struct_h->h_cmp_tpcapital));
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_company_struct_h->h_cmp_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_company_struct_h->h_cmp_maker_dt);
		  CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_company_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_company_struct_h->h_cmp_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_company_struct_h->h_cmp_checker_dt);
		  CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_company_struct_h->h_cmp_status);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_Proc_CompanyPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_Proc_CompanyPopulate \n",NULL,NULL);
        return 1; */
}
/* ANIL HDFCMT_002 Company Master */

/* ANIL HDFCMT_005 client_instrument */
int MT_CLN_INSTRPopulate(MT_CLN_INSTR_STRUCT_H *p_mt_cln_instr_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered MT_CLN_INSTRPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_cln_instr_struct_h->h_cln_code);
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_cln_instr_struct_h->h_instr_code);

        CO_Rtv_DataString(chr_p_param_str,"CLN_INSTR_CODE",p_mt_cln_instr_struct_h->h_cln_instr_code);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cln_instr_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cln_instr_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cln_instr_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cln_instr_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cln_instr_struct_h->h_checker_dt);
 		  CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cln_instr_struct_h->h_status);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_CLN_INSTRPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_CLN_INSTRPopulate \n",NULL,NULL);
        return 1; */
}
/* ANIL HDFCMT_005 client_instrument */

/* HDFCMT_006 ANIL INSTRUCTION SLIP */
int MT_InslEntryPopulate(MT_INSL_ENTRY_STRUCT_H *p_mt_insl_entry_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"MT_InslEntryPopulate \n",NULL,NULL);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",p_mt_insl_entry_struct_h->h_depo_code);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_CODE",p_mt_insl_entry_struct_h->h_depo_part_code);
        CO_Rtv_DataString(chr_p_param_str,"CLN_CODE",p_mt_insl_entry_struct_h->h_cln_code);
        CO_Rtv_DataString(chr_p_param_str,"TRANS_TYPE",p_mt_insl_entry_struct_h->h_trans_type);
        CO_Rtv_DataString(chr_p_param_str,"SLIP_SERIES",p_mt_insl_entry_struct_h->h_slip_series);
        CO_Rtv_DataInt(chr_p_param_str,"SR_NO_FROM",&(p_mt_insl_entry_struct_h->h_sr_no_from));
        CO_Rtv_DataInt(chr_p_param_str,"SR_NO_TO",&(p_mt_insl_entry_struct_h->h_sr_no_to));
        CO_Rtv_DataInt(chr_p_param_str,"SR_AVL_QTY",&(p_mt_insl_entry_struct_h->h_sr_avl_qty));
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_insl_entry_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_insl_entry_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_insl_entry_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_insl_entry_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_insl_entry_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_insl_entry_struct_h->h_status);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_InslEntryPopulate \n",NULL,NULL);
        return 0;

/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_InslEntryPopulate \n",NULL,NULL);
        return 1; */
}
/* HDFCMT_006 ANIL INSTRUCTION SLIP */

/* HDFCMT_008 : Manik Trivedi for  SETTLEMENT CALENDAR */

int MT_SettlCalPopulate(MT_SETTLCAL_STRUCT_H *p_mt_settlcal_struct_h, char *chr_p_param_str)
{

        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"MT_SettlCalPopulate \n",NULL,NULL);

        CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_mt_settlcal_struct_h->h_exch_code);
        CO_Rtv_DataString(chr_p_param_str,"CC_ID",p_mt_settlcal_struct_h->h_cc_id);
        CO_Rtv_DataString(chr_p_param_str,"SETTL_TYPE",p_mt_settlcal_struct_h->h_settl_type);
        CO_Rtv_DataString(chr_p_param_str,"SETTL_NO",p_mt_settlcal_struct_h->h_settl_no);
        CO_Rtv_DataString(chr_p_param_str,"START_DATE",p_mt_settlcal_struct_h->h_start_date);
        CO_Rtv_DataString(chr_p_param_str,"END_DATE",p_mt_settlcal_struct_h->h_end_date);
        CO_Rtv_DataString(chr_p_param_str,"NSDL_DEADLINE_DT",p_mt_settlcal_struct_h->h_nsdl_deadline_dt);
        CO_Rtv_DataString(chr_p_param_str,"NSDL_DEADLINE_TM",p_mt_settlcal_struct_h->h_nsdl_deadline_tm);
        CO_Rtv_DataString(chr_p_param_str,"PAY_IN_DT",p_mt_settlcal_struct_h->h_pay_in_dt);
        CO_Rtv_DataString(chr_p_param_str,"PAY_OUT_DT",p_mt_settlcal_struct_h->h_pay_out_dt);
        CO_Rtv_DataString(chr_p_param_str,"AUCTION_DT",p_mt_settlcal_struct_h->h_auction_dt);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_settlcal_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_settlcal_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_settlcal_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_settlcal_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_settlcal_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_settlcal_struct_h->h_status);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_SettlCalPopulate \n",NULL,NULL);
       return 0;
/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_SettlCalPopulate \n",NULL,NULL);
        return 1; */
}

/* HDFCMT_009 ANIL Daily Quotations */
int MT_DlyQuotationsPopulate(MT_DLYQTIONS_STRUCT_H *p_mt_dlyqtions_struct_h, char *chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"MT_DlyQuotationsPopulate \n",NULL,NULL);
        CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_mt_dlyqtions_struct_h->h_exch_code);
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_dlyqtions_struct_h->h_instr_code);
        CO_Rtv_DataString(chr_p_param_str,"QUOT_DATE",p_mt_dlyqtions_struct_h->h_quot_date);
        CO_Rtv_DataDbl(chr_p_param_str,"QUOT_PREV_DATE",&(p_mt_dlyqtions_struct_h->h_quot_prev_date));
        CO_Rtv_DataDbl(chr_p_param_str,"OPEN_AT",&(p_mt_dlyqtions_struct_h->h_open_at));
        CO_Rtv_DataDbl(chr_p_param_str,"HIGH_AT",&(p_mt_dlyqtions_struct_h->h_high_at));
        CO_Rtv_DataDbl(chr_p_param_str,"LOW_AT",&(p_mt_dlyqtions_struct_h->h_low_at));
        CO_Rtv_DataDbl(chr_p_param_str,"CLOSE_AT",&(p_mt_dlyqtions_struct_h->h_close_at));
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_dlyqtions_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_dlyqtions_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_dlyqtions_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_dlyqtions_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_dlyqtions_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_dlyqtions_struct_h->h_status);





APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_DlyQuotationsPopulate \n",NULL,NULL);
        return 0;
/* RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_DlyQuotationsPopulate \n",NULL,NULL);
        return 1; */
}
/* HDFCMT_009 ANIL Daily Quotations */

/* HDFCMT_012 Dnyanesh Daily Float Rate */

int MT_DlFlRatePopulate(MT_DLFLRATE_STRUCT_H *p_mt_dlflrate_struct_h,char *chr_p_param_str)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

		CO_Rtv_DataString(chr_p_param_str,"BENCHMARK_CODE",p_mt_dlflrate_struct_h->h_benchmark_code);
	CO_Rtv_DataString(chr_p_param_str,"RATE_DATE",p_mt_dlflrate_struct_h->h_rate_date);
   CO_Rtv_DataDbl(chr_p_param_str,"FLOAT_RATE_I",&(p_mt_dlflrate_struct_h->h_float_rate1));
   CO_Rtv_DataDbl(chr_p_param_str,"FLOAT_RATE_II",&(p_mt_dlflrate_struct_h->h_float_rate2));
   CO_Rtv_DataDbl(chr_p_param_str,"FLOAT_RATE_III",&(p_mt_dlflrate_struct_h->h_float_rate3));
	printf("\n After fetching.. float rate is |%lf| \n",p_mt_dlflrate_struct_h->h_float_rate1);
	CO_Rtv_DataDbl(chr_p_param_str,"STD_DEVIATION",&(p_mt_dlflrate_struct_h->h_std_deviation));
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_dlflrate_struct_h->h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_dlflrate_struct_h->h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_dlflrate_struct_h->h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_dlflrate_struct_h->h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_dlflrate_struct_h->h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_dlflrate_struct_h->h_status);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}
/* RBI Monetary, HDFCMT_014 */
int MT_RBIMonDetPopulate(MT_RBIMONDET_STRUCT_H *p_mt_rbimondet_struct_h,char *chr_p_param_str)
{

	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

		CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_mt_rbimondet_struct_h->h_instr_code);
	CO_Rtv_DataString(chr_p_param_str,"RBI_INSTR_CODE",p_mt_rbimondet_struct_h->h_rbi_instr_code);
	CO_Rtv_DataDbl(chr_p_param_str,"TPCAPITAL",&(p_mt_rbimondet_struct_h->h_tpcapital));
	CO_Rtv_DataDbl(chr_p_param_str,"SNG_FII_LIMIT",&(p_mt_rbimondet_struct_h->h_sng_fii_limit));
	CO_Rtv_DataDbl(chr_p_param_str,"OVR_FII_LIMIT",&(p_mt_rbimondet_struct_h->h_ovr_fii_limit));
	CO_Rtv_DataDbl(chr_p_param_str,"SNG_NRIOCB_LIMIT",&(p_mt_rbimondet_struct_h->h_sng_nriocb_limit));
	CO_Rtv_DataDbl(chr_p_param_str,"OVR_NRIOCB_LIMIT",&(p_mt_rbimondet_struct_h->h_ovr_nriocb_limit));
	CO_Rtv_DataString(chr_p_param_str,"CAUTION_FLG",p_mt_rbimondet_struct_h->h_caution_flg);
	CO_Rtv_DataDbl(chr_p_param_str,"CAUTION_FII",&(p_mt_rbimondet_struct_h->h_caution_fii));
	CO_Rtv_DataDbl(chr_p_param_str,"CAUTION_NRIOCB",&(p_mt_rbimondet_struct_h->h_caution_nriocb));
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_rbimondet_struct_h->h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_rbimondet_struct_h->h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_rbimondet_struct_h->h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_rbimondet_struct_h->h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_rbimondet_struct_h->h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_rbimondet_struct_h->h_status);
	CO_Rtv_DataString(chr_p_param_str,"DEF_CLN_TYPE",p_mt_rbimondet_struct_h->h_def_cln_type);
        CO_Rtv_DataString(chr_p_param_str,"FAR",p_mt_rbimondet_struct_h->h_far); /* Chages by rahul6 for T0 Enhancement */

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}
/*Dnyanesh , No Delivery HDFCMT_007*/
int MT_NoDlvDetPopulate(MT_NO_DELV_STRUCT_H *p_mt_no_delv_struct_h,char *p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_str,"EXCH_CODE",p_mt_no_delv_struct_h -> h_exch_code);
	CO_Rtv_DataString(p_param_str,"INSTR_CODE",p_mt_no_delv_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_str,"NO_DEL_FROM",p_mt_no_delv_struct_h -> h_no_del_from);
	CO_Rtv_DataString(p_param_str,"NO_DEL_TO",p_mt_no_delv_struct_h -> h_no_del_to);
	CO_Rtv_DataString(p_param_str,"MKT_TYPE",p_mt_no_delv_struct_h -> h_mkt_type);
	CO_Rtv_DataString(p_param_str,"CARRY_FW_STLNO",p_mt_no_delv_struct_h -> h_carry_fw_stlno);
	CO_Rtv_DataString(p_param_str,"MAKER",p_mt_no_delv_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_str,"MAKER_DT",p_mt_no_delv_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_str,"ACCESS_STAMP",p_mt_no_delv_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_str,"CHECKER",p_mt_no_delv_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_str,"CHECKER_DT",p_mt_no_delv_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_str,"STATUS",p_mt_no_delv_struct_h -> h_status);
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}

/*Sonali, Float Rate Instrument HDFCMT_013*/
int MT_FlRateInstPopulate(MT_FLRATEINST_STRUCT_H *p_mt_flrateinst_struct_h,char *p_param_str)
{
		void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
		void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
		void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
   CO_Rtv_DataString(p_param_str,"INSTR_CODE",p_mt_flrateinst_struct_h->h_instr_code);
   CO_Rtv_DataString(p_param_str,"DAILY_COMPOUND",p_mt_flrateinst_struct_h->h_daily_compound);
   CO_Rtv_DataString(p_param_str,"EXCL_HOLIDAYS",p_mt_flrateinst_struct_h->h_excl_holidays);
   CO_Rtv_DataInt(p_param_str,"INT_PAY_DAYS",&(p_mt_flrateinst_struct_h->h_int_pay_days));
   CO_Rtv_DataString(p_param_str,"COMPOUNDING_WDAYS",p_mt_flrateinst_struct_h->h_compounding_wdays);
   CO_Rtv_DataDbl(p_param_str,"FLOOR_RATE",&(p_mt_flrateinst_struct_h->h_floor_rate));
   CO_Rtv_DataDbl(p_param_str,"CAP_RATE",&(p_mt_flrateinst_struct_h->h_cap_rate));
   CO_Rtv_DataString(p_param_str,"PREFD_SEQ",p_mt_flrateinst_struct_h->h_prefd_seq);
   CO_Rtv_DataDbl(p_param_str,"BASE_MARGIN",&(p_mt_flrateinst_struct_h->h_base_margin));
   CO_Rtv_DataString(p_param_str,"DEFAULT_BENCHM_CODE",p_mt_flrateinst_struct_h->h_benchmark_code);
   CO_Rtv_DataString(p_param_str,"DEFAULT_FL_RATE",p_mt_flrateinst_struct_h->h_default_float_rate);
   CO_Rtv_DataString(p_param_str,"FIXED_BENCH",p_mt_flrateinst_struct_h->h_fixed_bench);
   CO_Rtv_DataString(p_param_str,"MAKER",p_mt_flrateinst_struct_h->h_maker);
   CO_Rtv_DataString(p_param_str,"MAKER_DT",p_mt_flrateinst_struct_h->h_maker_dt);
   CO_Rtv_DataString(p_param_str,"CHECKER",p_mt_flrateinst_struct_h->h_checker);
   CO_Rtv_DataString(p_param_str,"CHECKER_DT",p_mt_flrateinst_struct_h->h_checker_dt);
   CO_Rtv_DataString(p_param_str,"STATUS",p_mt_flrateinst_struct_h->h_status);
   CO_Rtv_DataString(p_param_str,"ACCESS_STAMP",p_mt_flrateinst_struct_h->h_access_stamp);


APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_FlRateInstPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_FlRateInstPopulate \n",NULL,NULL);
	return 1; */
}
/*Sonali, Float Rate Instrument HDFCMT_013*/

/*Sonali, Static Master HDFCMT_016*/
int MT_StaticDataPopulate(CO_STATIC_DATA_STRUCT_H *p_co_static_data_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"CODE_IDENT",p_co_static_data_struct_h -> h_code_ident);
	CO_Rtv_DataString(p_param_data,"CODE_VALUE",p_co_static_data_struct_h -> h_code_value);
	CO_Rtv_DataString(p_param_data,"CODE_DESC",p_co_static_data_struct_h -> h_code_desc);
	CO_Rtv_DataString(p_param_data,"COUNTRY_CODE",p_co_static_data_struct_h -> h_country_code);

	APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_StaticDataPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_StaticDataPopulate \n",NULL,NULL);
	return 1; */
}
/*Sonali, Static Master HDFCMT_016*/

/* HDFCMT_017 - INDEX FUND MASTER - PRADEEP */

int MT_Proc_IndexFundPopulate(MT_INDEX_FUND_STRUCT_H *p_mt_index_fund_struct_h,char *p_param_str)
{
	void  CO_Rtv_DataString(char *chr_param_str, char *p_lbl,char *p_data_value);
	APL_FUNCTION_ENTER(APL_OUT_FILE)


		CO_Rtv_DataString(p_param_str,"INDEX_FUND_NUM",p_mt_index_fund_struct_h->h_index_fund_num);
	CO_Rtv_DataString(p_param_str,"INDEX_FUND_NAME",p_mt_index_fund_struct_h->h_index_fund_name);
	CO_Rtv_DataString(p_param_str,"MAKER",p_mt_index_fund_struct_h->h_maker);
	CO_Rtv_DataString(p_param_str,"MAKER_DT",p_mt_index_fund_struct_h->h_maker_dt);
	CO_Rtv_DataString(p_param_str,"ACCESS_STAMP",p_mt_index_fund_struct_h->h_access_stamp);
	CO_Rtv_DataString(p_param_str,"CHECKER",p_mt_index_fund_struct_h->h_checker);
	CO_Rtv_DataString(p_param_str,"CHECKER_DT",p_mt_index_fund_struct_h->h_checker_dt);
	CO_Rtv_DataString(p_param_str,"STATUS",p_mt_index_fund_struct_h->h_status);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_Proc_IndexFundPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_Proc_IndexFundPopulate \n",NULL,NULL);
	return 1; */
}

int MT_Proc_IndexFundDetPopulate(MT_INDEX_FUNDDET_STRUCT_H *p_mt_index_funddet_struct_h,char *p_param_str)
{
	void  CO_Rtv_DataString(char *chr_param_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataInt(p_param_str,"INDEX_SEQ_NUM",&(p_mt_index_funddet_struct_h->h_index_seq_num));
	CO_Rtv_DataString(p_param_str,"INDEX_FUND_NUM",p_mt_index_funddet_struct_h -> h_index_fund_num);
	CO_Rtv_DataString(p_param_str,"INSTR_CODE",p_mt_index_funddet_struct_h -> h_instr_code);
	CO_Rtv_DataString(p_param_str,"MAKER",p_mt_index_funddet_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_str,"MAKER_DT",p_mt_index_funddet_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_str,"ACCESS_STAMP",p_mt_index_funddet_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_str,"CHECKER",p_mt_index_funddet_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_str,"CHECKER_DT",p_mt_index_funddet_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_str,"STATUS",p_mt_index_funddet_struct_h -> h_status);

APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_Proc_IndexFundPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_Proc_IndexFundPopulate \n",NULL,NULL);
	return 1; */
}

/* HDFCMT_017 - INDEX FUND MASTER - PRADEEP */

/* Kouser - Depository Participant - HDFCMT_010 */

int MT_DepoPartPopulate(char *chr_p_param_str,MT_DEPO_PART_STRUCT_H *p_mt_depo_part_struct_h)
{

		  void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

        APL_FUNCTION_ENTER(APL_OUT_FILE)

        CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",p_mt_depo_part_struct_h->h_depo_code);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_CODE",p_mt_depo_part_struct_h->h_depo_part_code);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_CONTACT1",p_mt_depo_part_struct_h->h_depo_part_contact1);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_ADD_1",p_mt_depo_part_struct_h->h_depo_part_add_1);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_ADD_2",p_mt_depo_part_struct_h->h_depo_part_add_2);
        CO_Rtv_DataString(chr_p_param_str,"CITY",p_mt_depo_part_struct_h->h_depo_part_add_city);
        CO_Rtv_DataString(chr_p_param_str,"STATE",p_mt_depo_part_struct_h->h_depo_part_add_state);
        CO_Rtv_DataString(chr_p_param_str,"COUNTRY",p_mt_depo_part_struct_h -> h_depo_part_add_cnt);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_ADD_PIN",p_mt_depo_part_struct_h -> h_depo_part_add_pin);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_TEL",p_mt_depo_part_struct_h -> h_depo_part_tel);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_FAX",p_mt_depo_part_struct_h -> h_depo_part_fax);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_EMAIL",p_mt_depo_part_struct_h -> h_depo_part_email);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_depo_part_struct_h -> h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_depo_part_struct_h -> h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_depo_part_struct_h -> h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_depo_part_struct_h -> h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_depo_part_struct_h -> h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_depo_part_struct_h -> h_status);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_NAME",p_mt_depo_part_struct_h->h_depo_name); /* Depo Participant Name in Depo Participant Master - by Gouse */
}

int MT_ExchDepoPopulate(char *chr_p_param_str,MT_EXCH_DEPO_STRUCT_H *p_mt_exch_depo_struct_h)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
			 
        APL_FUNCTION_ENTER(APL_OUT_FILE)

        CO_Rtv_DataString(chr_p_param_str,"DEPO_CODE",p_mt_exch_depo_struct_h -> h_depo_code);
        CO_Rtv_DataString(chr_p_param_str,"DEPO_PART_CODE",p_mt_exch_depo_struct_h -> h_depo_part_code);
        CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_mt_exch_depo_struct_h -> h_exch_code);
        CO_Rtv_DataString(chr_p_param_str,"CC_ID",p_mt_exch_depo_struct_h -> h_cc_id);
        CO_Rtv_DataString(chr_p_param_str,"CM_CC_ID",p_mt_exch_depo_struct_h -> h_cm_cc_id);
        CO_Rtv_DataString(chr_p_param_str,"CLN_ID",p_mt_exch_depo_struct_h -> h_cln_id);
        CO_Rtv_DataString(chr_p_param_str,"DP_ID",p_mt_exch_depo_struct_h -> h_dp_id);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_exch_depo_struct_h -> h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_exch_depo_struct_h -> h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_exch_depo_struct_h -> h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_exch_depo_struct_h -> h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_exch_depo_struct_h -> h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_exch_depo_struct_h -> h_status);

		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_ExchDepoPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_ExchDepoPopulate \n",NULL,NULL);
	return 1; */
}

/* Kouser - Depository Participant - HDFCMT_010 */

/* Kouser - Credit Rating Agency - HDFCMT_011  */
int MT_CrRt_AgencyPopulate(MT_CR_AGENCY_STRUCT_H *p_mt_cr_agency_struct_h,char *chr_p_param_str) 
{       
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

        APL_FUNCTION_ENTER(APL_OUT_FILE)
        
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_CODE",p_mt_cr_agency_struct_h -> h_agency_code);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_NAME",p_mt_cr_agency_struct_h -> h_agency_name);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_ADD_1",p_mt_cr_agency_struct_h -> h_agency_addr1);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_ADD_2",p_mt_cr_agency_struct_h -> h_agency_addr2);
        CO_Rtv_DataString(chr_p_param_str,"CITY",p_mt_cr_agency_struct_h -> h_agency_city);
        CO_Rtv_DataString(chr_p_param_str,"STATE",p_mt_cr_agency_struct_h -> h_agency_state);
        CO_Rtv_DataString(chr_p_param_str,"COUNTRY",p_mt_cr_agency_struct_h -> h_aadr_cnt);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_ADD_PIN",p_mt_cr_agency_struct_h -> h_addr_pin);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_TEL",p_mt_cr_agency_struct_h -> h_agency_tel);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_FAX",p_mt_cr_agency_struct_h -> h_agency_fax);
        CO_Rtv_DataString(chr_p_param_str,"AGENCY_EMAIL",p_mt_cr_agency_struct_h -> h_agency_email);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cr_agency_struct_h -> h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cr_agency_struct_h -> h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cr_agency_struct_h -> h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cr_agency_struct_h -> h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cr_agency_struct_h -> h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cr_agency_struct_h -> h_status);

    APL_GOBACK_SUCCESS 
    RETURN_SUCCESS:

           APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
           return 0;
  /*   RETURN_FAILURE:

           APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
           return 1; */
}

int MT_CrRt_AgencyDetPopulate(MT_CR_AGENCY_DET_STRUCT_H *p_mt_cr_agency_det_struct_h,char *chr_p_param_str)
  {
          void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
          void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);  

          APL_FUNCTION_ENTER(APL_OUT_FILE)

          CO_Rtv_DataString(chr_p_param_str,"AGENCY_CODE",p_mt_cr_agency_det_struct_h -> h_agency_code);
          CO_Rtv_DataString(chr_p_param_str,"RATING_CODE",p_mt_cr_agency_det_struct_h -> h_rating_code);
          CO_Rtv_DataString(chr_p_param_str,"RATING_DESC",p_mt_cr_agency_det_struct_h -> h_rating_desc);

           /*CO_Rtv_DataInt(chr_p_param_str,"CLN_SEQ_NUM",(int *)&(p_mt_cr_agency_det_struct_h -> h_cr_seq_num));*/
          CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_cr_agency_det_struct_h -> h_maker);
          CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_cr_agency_det_struct_h -> h_maker_dt);
          CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_cr_agency_det_struct_h -> h_checker);
          CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_cr_agency_det_struct_h -> h_checker_dt);
          CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_cr_agency_det_struct_h -> h_status);
          CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_cr_agency_det_struct_h -> h_access_stamp);
          CO_Rtv_DataInt(chr_p_param_str,"CR_SEQ_NUM",&(p_mt_cr_agency_det_struct_h -> h_cr_seq_num));
   APL_GOBACK_SUCCESS 
   RETURN_SUCCESS:

           APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
           return 0;

  /*  RETURN_FAILURE:

           APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
           return 1; */
 }

/* Kouser -  Credit Rating Agency - HDFCMT_011*/

/* Pradeep - Party Master - HDFCMT_004 */
int MT_PartyPopulate(MT_PARTY_STRUCT_H *p_mt_party_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

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
	CO_Rtv_DataString(p_param_data,"PTY_BIC_CODE",p_mt_party_struct_h -> h_pty_bic_code);
	CO_Rtv_DataString(p_param_data,"SET_EXCH_CODE",p_mt_party_struct_h -> h_set_exch_code);     //Added for INTEROPERABILITY - 12174
	CO_Rtv_DataString(p_param_data,"CSGL_APPLICABLE",p_mt_party_struct_h -> h_csgl_apl);
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}

int MT_PtyExchMapPopulate(MT_PTY_EXCH_MAP_STRUCT_H *p_mt_pty_exch_map_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

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
   /* Added Cols - SebiRegNo1,SebiRegNo2 - HDFCMT_004 - Kouser */
   CO_Rtv_DataString(p_param_data,"PTY_SEBI_REG_NO1",p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no1);
   CO_Rtv_DataString(p_param_data,"PTY_SEBI_REG_NO2",p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no2);
   /* Added Cols - SebiRegNo1,SebiRegNo2 - HDFCMT_004 - Kouser */
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;

/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}

int MT_PtyDepoMapPopulate(MT_PTY_DEPO_MAP_STRUCT_H *p_mt_pty_depo_map_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

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
        CO_Rtv_DataString(p_param_data,"EXCH_CODE",p_mt_pty_depo_map_struct_h -> h_exch_code);
        CO_Rtv_DataString(p_param_data,"CMBP_ID",p_mt_pty_depo_map_struct_h -> h_cmbp_id);
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}

int MT_PtyExchClnMapPopulate(MT_PTY_EXCH_CLN_MAP_STRUCT_H *p_mt_pty_exch_cln_map_struct_h,char *p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

	APL_FUNCTION_ENTER(APL_OUT_FILE)

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
APL_GOBACK_SUCCESS 
RETURN_SUCCESS:
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return 0;
/* RETURN_FAILURE:
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return 1; */
}

/* Sundar Vendor Maintenance HDFCMT_GFU */

int Populate_MT_VENDOR(MT_GFU_VENDOR_SETUP_STRUCT_H *p_mt_gfu_vendor_setup_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"VENDOR_CODE",p_mt_gfu_vendor_setup_struct_h -> h_vendor_code);
	CO_Rtv_DataString(p_param_data,"VENDOR_NAME",p_mt_gfu_vendor_setup_struct_h -> h_vendor_name);
	CO_Rtv_DataString(p_param_data,"ADD_LINE1",p_mt_gfu_vendor_setup_struct_h -> h_add_line1);
	CO_Rtv_DataString(p_param_data,"ADD_LINE2",p_mt_gfu_vendor_setup_struct_h -> h_add_line2);
	CO_Rtv_DataString(p_param_data,"COUNTRY_CODE",p_mt_gfu_vendor_setup_struct_h -> h_country_code);
	CO_Rtv_DataString(p_param_data,"STATE_CODE",p_mt_gfu_vendor_setup_struct_h -> h_state_code);
	CO_Rtv_DataString(p_param_data,"CITY_CODE",p_mt_gfu_vendor_setup_struct_h -> h_city_code);
	CO_Rtv_DataString(p_param_data,"PIN_CODE",p_mt_gfu_vendor_setup_struct_h -> h_pin_code);
	CO_Rtv_DataString(p_param_data,"FAX_NO",p_mt_gfu_vendor_setup_struct_h -> h_fax_no);
	CO_Rtv_DataString(p_param_data,"TEL_NO",p_mt_gfu_vendor_setup_struct_h -> h_tel_no);
	CO_Rtv_DataString(p_param_data,"WEB_ADDRESS",p_mt_gfu_vendor_setup_struct_h -> h_web_address);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_gfu_vendor_setup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_gfu_vendor_setup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_gfu_vendor_setup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_gfu_vendor_setup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_gfu_vendor_setup_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_gfu_vendor_setup_struct_h -> h_status);

		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of Populate_MT_VENDOR \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of Populate_MT_VENDOR \n",NULL,NULL);
	return 1; */

}


int Populate_MT_GFU_FORMAT_SETUP(MT_GFU_FORMAT_SETUP_STRUCT_H *p_mt_gfu_format_setup_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"VENDOR_ID",p_mt_gfu_format_setup_struct_h -> h_vendor_id);
	CO_Rtv_DataString(p_param_data,"FUNCTION_ID",p_mt_gfu_format_setup_struct_h -> h_function_id);
	CO_Rtv_DataString(p_param_data,"FILE_TYPE",p_mt_gfu_format_setup_struct_h -> h_file_type);
	CO_Rtv_DataString(p_param_data,"COPY_EXIST",p_mt_gfu_format_setup_struct_h -> h_copy_exist);
	CO_Rtv_DataString(p_param_data,"DELIMETER",p_mt_gfu_format_setup_struct_h -> h_delimeter);
	CO_Rtv_DataString(p_param_data,"REF_NO",p_mt_gfu_format_setup_struct_h -> h_ref_no);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_gfu_format_setup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_gfu_format_setup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_gfu_format_setup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_gfu_format_setup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_gfu_format_setup_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_gfu_format_setup_struct_h -> h_status);
	CO_Rtv_DataString(p_param_data,"SKIP_LINE",p_mt_gfu_format_setup_struct_h -> h_skip_line);
	CO_Rtv_DataInt(p_param_data,"HEADER_POS",(int *) &(p_mt_gfu_format_setup_struct_h -> h_header_pos));
	CO_Rtv_DataInt(p_param_data,"FORMAT_LINE",(int *) &(p_mt_gfu_format_setup_struct_h -> h_format_line));
	CO_Rtv_DataString(p_param_data,"HEADER_CHK",p_mt_gfu_format_setup_struct_h -> h_header_chk);
	/** Added By Sana for GFU Setup **/
	CO_Rtv_DataString(p_param_data,"MODULE_NAME",p_mt_gfu_format_setup_struct_h -> h_module_name);


	
		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of Populate_MT_GFU_FORMAT_SETUP \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of Populate_MT_GFU_FORMAT_SETUP \n",NULL,NULL);
	return 1; */
}

int Populate_MT_GFU_EXCEL_SETUP(MT_GFU_EXCEL_SETUP_STRUCT_H *p_mt_gfu_excel_setup_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"REF_NO",p_mt_gfu_excel_setup_struct_h -> h_ref_no);
	CO_Rtv_DataString(p_param_data,"EXCEL_FIELD_NAME",p_mt_gfu_excel_setup_struct_h -> h_excel_field_name);
	CO_Rtv_DataString(p_param_data,"EXCEL_REFERENCE_VALUE",p_mt_gfu_excel_setup_struct_h -> h_excel_reference_value);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_gfu_excel_setup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_gfu_excel_setup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_gfu_excel_setup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_gfu_excel_setup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_gfu_excel_setup_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_gfu_excel_setup_struct_h -> h_status);

	
		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of Populate_MT_GFU_EXCEL_SETUP \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of Populate_MT_GFU_EXCEL_SETUP \n",NULL,NULL);
	return 1; */
}

int Populate_MT_GFU_TXT_SETUP(MT_GFU_TXT_SETUP_STRUCT_H *p_mt_gfu_txt_setup_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"REF_NO",p_mt_gfu_txt_setup_struct_h -> h_ref_no);
	CO_Rtv_DataString(p_param_data,"TXT_FIELD_NAME",p_mt_gfu_txt_setup_struct_h -> h_txt_field_name);
	CO_Rtv_DataInt(p_param_data,"START_POS",(int *) &(p_mt_gfu_txt_setup_struct_h -> h_start_pos));
	CO_Rtv_DataInt(p_param_data,"END_POS",(int *) &(p_mt_gfu_txt_setup_struct_h -> h_end_pos));
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_gfu_txt_setup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_gfu_txt_setup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_gfu_txt_setup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_gfu_txt_setup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_gfu_txt_setup_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_gfu_txt_setup_struct_h -> h_status);

	
		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of Populate_MT_GFU_TXT_SETUP \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of Populate_MT_GFU_TXT_SETUP \n",NULL,NULL);
	return 1; */
}

int Populate_MT_GFU_CSV_SETUP(MT_GFU_CSV_SETUP_STRUCT_H *p_mt_gfu_csv_setup_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	CO_Rtv_DataString(p_param_data,"REF_NO",p_mt_gfu_csv_setup_struct_h -> h_ref_no);
	CO_Rtv_DataString(p_param_data,"CSV_FIELD_NAME",p_mt_gfu_csv_setup_struct_h -> h_csv_field_name);
	CO_Rtv_DataString(p_param_data,"CSV_REFERENCE_VALUE",p_mt_gfu_csv_setup_struct_h -> h_csv_reference_value);
	CO_Rtv_DataString(p_param_data,"MAKER",p_mt_gfu_csv_setup_struct_h -> h_maker);
	CO_Rtv_DataString(p_param_data,"MAKER_DT",p_mt_gfu_csv_setup_struct_h -> h_maker_dt);
	CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_mt_gfu_csv_setup_struct_h -> h_access_stamp);
	CO_Rtv_DataString(p_param_data,"CHECKER",p_mt_gfu_csv_setup_struct_h -> h_checker);
	CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_mt_gfu_csv_setup_struct_h -> h_checker_dt);
	CO_Rtv_DataString(p_param_data,"STATUS",p_mt_gfu_csv_setup_struct_h -> h_status);

	
		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of Populate_MT_GFU_CSV_SETUP \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of Populate_MT_GFU_CSV_SETUP \n",NULL,NULL);
	return 1; */
}

/* Sundar Vendor Maintenance HDFCMT_GFU */

/* Bageshri  - MT Party Fund Details 27/04/06 */
int MT_PtyFundDetPopulate(MT_PTY_FUND_DET_STRUCT_H *p_mt_pty_fund_det_struct_h,char *chr_p_param_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	void  CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value);
	
	CO_ProcMonitor(APL_OUT_FILE,"Entered MT_PtyFundDetPopulate \n",NULL,NULL);

	CO_Rtv_DataString(chr_p_param_str,"PTY_CODE",p_mt_pty_fund_det_struct_h->h_pty_code);
	CO_Rtv_DataInt(chr_p_param_str,"PAY_IN_DAY",&(p_mt_pty_fund_det_struct_h->h_pay_in_day));
	CO_Rtv_DataInt(chr_p_param_str,"PAY_OUT_DAY",&(p_mt_pty_fund_det_struct_h->h_pay_out_day));
	CO_Rtv_DataChar(chr_p_param_str,"ACC_TYP",&(p_mt_pty_fund_det_struct_h->h_acc_typ));
	CO_Rtv_DataString(chr_p_param_str,"PAY_IN_ACC",p_mt_pty_fund_det_struct_h->h_pay_in_acc);
	CO_Rtv_DataString(chr_p_param_str,"PAY_OUT_ACC",p_mt_pty_fund_det_struct_h->h_pay_out_acc);
	CO_Rtv_DataString(chr_p_param_str,"ACC_CODE1",p_mt_pty_fund_det_struct_h->h_acc_code1);
	CO_Rtv_DataString(chr_p_param_str,"ACC_CODE2",p_mt_pty_fund_det_struct_h->h_acc_code2);
	CO_Rtv_DataString(chr_p_param_str,"ACC_CODE2DESC",p_mt_pty_fund_det_struct_h->h_acc_code2desc);
	CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_mt_pty_fund_det_struct_h->h_access_stamp);
	CO_Rtv_DataString(chr_p_param_str,"MAKER",p_mt_pty_fund_det_struct_h->h_maker);
	CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_mt_pty_fund_det_struct_h->h_maker_dt);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_mt_pty_fund_det_struct_h->h_checker);
	CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_mt_pty_fund_det_struct_h->h_checker_dt);
	CO_Rtv_DataString(chr_p_param_str,"STATUS",p_mt_pty_fund_det_struct_h->h_status);
	CO_Rtv_DataString(chr_p_param_str,"PTY_BNK_ACC",p_mt_pty_fund_det_struct_h->h_pty_bnk_acc);

   CO_ProcMonitor(APL_OUT_FILE,"Leaving MT_PtyFundDetPopulate \n",NULL,NULL);

   
		APL_GOBACK_SUCCESS 
 RETURN_SUCCESS:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully out of MT_PtyFundDetPopulate \n",NULL,NULL);
	return 0;
/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccessfully out of MT_PtyFundDetPopulate \n",NULL,NULL);
	return 1; */
}

/* Bageshri  - MT Party Fund Details 27/04/06 */

int MT_VarlemUploadNsePopulate(VARELM_UPLOAD_NSE_STRUCT_H *p_varelm_upload_nse_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	
	printf("\n|%s|\n",p_param_data);
	CO_Rtv_DataString(p_param_data,"UPLD_DATETIME",p_varelm_upload_nse_struct_h -> h_upld_datetime);
	CO_Rtv_DataString(p_param_data,"UPLD_FILENAME",p_varelm_upload_nse_struct_h -> h_upld_filename);
	CO_Rtv_DataString(p_param_data,"SCRIP_SYMBOL",p_varelm_upload_nse_struct_h -> h_scrip_symbol);
	CO_Rtv_DataString(p_param_data,"EXCH_INSTR_CODE",p_varelm_upload_nse_struct_h -> h_exch_instr_code);
	CO_Rtv_DataString(p_param_data,"SCRIP_GRP",p_varelm_upload_nse_struct_h -> h_scrip_grp);
	CO_Rtv_DataString(p_param_data,"ISIN",p_varelm_upload_nse_struct_h -> h_isin);
	CO_Rtv_DataDbl(p_param_data,"SECURITY_VAR",&(p_varelm_upload_nse_struct_h -> h_security_var));
	CO_Rtv_DataDbl(p_param_data,"INDEX_VAR",&(p_varelm_upload_nse_struct_h -> h_index_var));
	CO_Rtv_DataDbl(p_param_data,"VAR_RATE",&(p_varelm_upload_nse_struct_h -> h_var_rate));
	CO_Rtv_DataDbl(p_param_data,"ELM_RATE",&(p_varelm_upload_nse_struct_h -> h_elm_rate));
	CO_Rtv_DataDbl(p_param_data,"ADDITIONAL_RATE",&(p_varelm_upload_nse_struct_h -> h_additional_rate));
	CO_Rtv_DataDbl(p_param_data,"TOT_RATE",&(p_varelm_upload_nse_struct_h -> h_tot_rate));
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_varelm_upload_nse_struct_h -> h_instr_code);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_VarlemUploadNsePopulate \n",NULL,NULL);
	return 0;

/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_VarlemUploadNsePopulate \n",NULL,NULL);
	return 1; */

}

int MT_VarlemUploadBsePopulate(VARELM_UPLOAD_BSE_STRUCT_H *p_varelm_upload_bse_struct_h,char * p_param_data)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
	
	printf("\n|%s|\n",p_param_data);
	CO_Rtv_DataString(p_param_data,"UPLD_DATETIME",p_varelm_upload_bse_struct_h -> h_upld_datetime);
	CO_Rtv_DataString(p_param_data,"UPLD_FILENAME",p_varelm_upload_bse_struct_h -> h_upld_filename);
	CO_Rtv_DataString(p_param_data,"SR_NO",p_varelm_upload_bse_struct_h -> h_sr_no);
	CO_Rtv_DataString(p_param_data,"SCRIP_CODE",p_varelm_upload_bse_struct_h -> h_scrip_code);
	CO_Rtv_DataString(p_param_data,"SCRIP_NAME",p_varelm_upload_bse_struct_h -> h_scrip_name);
	CO_Rtv_DataString(p_param_data,"ISIN",p_varelm_upload_bse_struct_h -> h_isin);
	CO_Rtv_DataDbl(p_param_data,"VAR_PER",&(p_varelm_upload_bse_struct_h -> h_var_per));
	CO_Rtv_DataDbl(p_param_data,"FIVAR_PER",&(p_varelm_upload_bse_struct_h -> h_fivar_per));
	CO_Rtv_DataString(p_param_data,"PROCESSON",p_varelm_upload_bse_struct_h -> h_processon);
	CO_Rtv_DataString(p_param_data,"APPLI_ON",p_varelm_upload_bse_struct_h -> h_appli_on);
	CO_Rtv_DataDbl(p_param_data,"VAR_RATE",&(p_varelm_upload_bse_struct_h -> h_var_rate));
	CO_Rtv_DataDbl(p_param_data,"ELM_PER",&(p_varelm_upload_bse_struct_h -> h_elm_per));
	CO_Rtv_DataDbl(p_param_data,"ELM_RATE",&(p_varelm_upload_bse_struct_h -> h_elm_rate));
	CO_Rtv_DataDbl(p_param_data,"TOT_VARELM",&(p_varelm_upload_bse_struct_h -> h_tot_varelm));
	CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_varelm_upload_bse_struct_h -> h_instr_code);


APL_GOBACK_SUCCESS 
RETURN_SUCCESS:

	CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of MT_VarlemUploadBsePopulate \n",NULL,NULL);
	return 0;

/* RETURN_FAILURE:
	CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of MT_VarlemUploadBsePopulate \n",NULL,NULL);
	return 1;*/

}
