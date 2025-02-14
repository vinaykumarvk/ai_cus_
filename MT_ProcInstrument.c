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
 * Module Name         :	Master Maintenance
 *
 * File Name           : 	MT_ProcInstrument.c
 *
 * Description         :	This file contains functions for Instrument Details 
 *									Maintenance. It contains all functions related to
 *									Input/Modify/Authorize/Delete Modes.
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description			RFS No.
 * ---------   --------	 ---------------  ---------------------   ----------
 * 10/10/2005   1.1          Smita Bhat     New file to Maintain	HDFCMT_003
 *														 Instrument	Details 
 * 03/01/2006	 1.2			  Smita Bhat	  Changes done as per 	HDFCMT_003
 *														 Client Discussions
 *
 * 07/02/2006   1.3          Kouser Begum   HDFC - New Requirement    HDFCMT_003
 *                                          Changes for InstrumentType 
 *                                          And Interest Type Validation
 *********************************************************************/

#define PURE_C_SOURCE
#include <CO_HostStructdef.h>

#define S_DATE_LENGTH		11

int CO_Chk_InstrValid(	char *p_instr_code, 
								char p_exist, 
								char p_auth, 
								char p_del, 
								char p_frozen, 
								char p_mothchld, 
								char p_converted, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

char     *g_chld_table_names[APL_INSTRUMENT_CHILD_CNT + 1] = {	"MT_RED_DP_DET",
																					"MT_INSTR_EXCH_DET",
																					"MT_INSTR_RATING_DET",
																					"MT_PC_DET",
																					"MT_PTC_DET",
																					"MT_RED_DET",
																					"MT_RESET_DET",
																					APL_NULL_STRING};

char		*g_mst_key_codes[2] = {"INSTR_CODE",APL_NULL_STRING};
char		*g_mst_key_values[2];		
char 		g_mst_table_name[25] = "MT_INSTRUMENT";
char		p_field_ind[5] = APL_NULL_STRING;
char     chr_chd_table_name[30] = APL_NULL_STRING;

/* AIX - Warnings removal - Start */
extern int CR_ChkPTCValNomVal( char* p_instr_code,
                               double p_instr_ptc_value,
                               double p_instr_ptc_prin_amt,
                               int p_instr_seq_num,
                               INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
                               DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Chk_InstrOth(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h,
                           INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
                           DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_Rtv_MastChldChrVal(char *p_key_codes[],
                                 char *p_key_values[],
                                 char *p_table_name,
                                 char *p_link_val,
                                 char *p_field_val,
                                 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
                                                                        
extern int MT_Chk_PtyVal(char *p_ptycode,char *p_ptytype,char p_exist,
                         char p_auth,char p_del, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CR_GetTotalPaidCap(double *p_total_paid_cap,
                                  char *p_cmp_code,
                                  DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int MT_Chk_CmpanyFn(char *p_cmp_code,char p_exist,char p_auth,char p_del,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern int CO_Pro_DateComp(char *p_from_date, char *p_to_date, int *int_p_diff,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
/* AIX - Warnings removal - End */
//AIX - Warnings Removal - Commented unused variables.
/******************************************************************************************
 *                                                                                        *
 * Function Name         : MT_Mod_Instr 	                                          		*
 *                                                                                        *
 * Description           : This Function Accepts Instrument Structure,Env String          *
 *                         and debug pointer.                                             *
 *                         returns Success/Failure depending upon validn.                 *
 *                                                                                        *
 *                                                                                        *
 * Parameter                  Type                       Mode     Description             *
 * ------------               --------                   -----    ---------------         *
 * p_mt_instrument_struct_h   MT_INSTRUMENT_STRUCT_H	 	I	  		Instrument Structure    *
 *											  																			*
 * p_intl_env_data_struct_h_d INTL_ENV_DATA_STRUCT_H *   I        Environment String      *
 *                                                                Structure               *
 *											  																			*	
 * l_debug_info_ptr     		DEBUG_INFO_STRUCT_H ** 		I        Debug Info Structure    *
 *                                                                                        *
 * Return Values        :                                                                 *
 *                                                                                        *
 *  APL_SUCCESS  - SUCCESS                                                                *
 *  APL_FAILURE  - FAILURE                                                                *
 *                                                                                        *
 ******************************************************************************************/
int MT_Mod_Instr(		MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h, 
							INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval;
	short							int_l_condexists;
	char							chr_l_field_val[40];
	DEAL_ORD_STRUCT_H			*l_deal_ord_struct_h = NULL;
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	char							chr_l_sys_date[S_DATE_LENGTH];
	int							int_l_diff;
	char							chr_iexist,chr_ideleted,chr_ifrozen;
 	char							chr_l_row_id_instr[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
	int 							int_l_holiday_flg = 0;		
	//char							chr_l_ccycode[3];
	double						dbl_l_tot_paid_cap = 0;
	char							chr_i_val_exists,chr_i_val_authorised,chr_i_val_deleted;

	//char                    chr_chd_iexist,chr_chd_iauthorised,chr_chd_ideleted; 
        //char                    l_field_name[25]=APL_NULL_STRING; 	
        	
	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_Instr \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	char *p_key_codes[2]; 
   char *p_key_values[2];
  
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]=APL_NULL_STRING;
  
	chr_i_val_exists = 'Y';
	chr_i_val_authorised = 'Y';
	chr_i_val_deleted = 'N';

	if (strlen(p_mt_instrument_struct_h->h_instr_code) == 0)
	{
		APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	}

	/*Smita - HDFCMT_003 - If Currency Code is Null, Pick the same from Bank Set up Parameters*/	
    	/* The below check is not required
	if (strlen(p_mt_instrument_struct_h->h_currency_cd) == 0)
	{
		APL_DATA_MISSING("CURRENCY CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	*/

	if (strlen(p_mt_instrument_struct_h->h_currency_cd) == 0)
	{
/* - Smita - Get Currency Code from Common Sys Parameters - HDFCMT_003 
int_retval = CR_GetCcyCode(chr_l_ccycode,l_debug_info_ptr);
		
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		strcpy(p_mt_instrument_struct_h->h_currency_cd,chr_l_ccycode);
*/
		strcpy(p_mt_instrument_struct_h->h_currency_cd,g_mt_commonsys_params_struct_h.dom_ccy);

		APL_IF_DEBUG
		{
			printf("Currency Code = |%s|\n",p_mt_instrument_struct_h->h_currency_cd);
		}
	}

	/**Smita - No Check for Location Required
	if (strcmp(l_mt_core_sys_params_struct_h.loc_proc_ind,"Y") == 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_location_cd) == 0)
		{
			APL_DATA_MISSING("LOCATION CODE",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	**/
	
	if (p_mt_instrument_struct_h->h_nominal_value <= 0)
	{	
		CO_InsertErr(	l_debug_info_ptr,
							ERR_VAL_SHLDBERR_POS,
							"NOMINAL_VALUE",
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
	}	

	/*Smita - If Regbrind = null, initialize it to RG */
	if (strlen(p_mt_instrument_struct_h->h_reg_br_ind) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_reg_br_ind,APL_INSTRU_REGD);
	}

	
	/*Smita - Check Tradable Flag */
	if ( 	(strlen(p_mt_instrument_struct_h->h_allow_rf)  == 0) ||
			(strlen(p_mt_instrument_struct_h->h_allow_rvp) == 0) ||
			(strlen(p_mt_instrument_struct_h->h_allow_df)  == 0) ||
			(strlen(p_mt_instrument_struct_h->h_allow_dvp) == 0)		)
	{
		APL_DATA_MISSING("TRADABLE",APL_NULL_STRING,APL_NULL_STRING)
	}	
			
	if (strlen(p_mt_instrument_struct_h->h_ord_type) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_ord_type,APL_ORDER_CLASS);
	}
		
	if (strlen(p_mt_instrument_struct_h->h_ex_arena) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_ex_arena,APL_EXARENA); /*1 indicates BSE - Default Value */
	}

	if (p_mt_instrument_struct_h->h_threshold_qty < 0)
	{		
		CO_InsertErr(	l_debug_info_ptr,
							ERR_VALUE_CANT_NEGATIVE,
							"THRESHOLD_QTY",
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
	}
	if(strcmp(p_intl_env_data_struct_h->subprocess, "API")){
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_access_stamp) == 0)
		{
			APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	}

	if (strlen(p_mt_instrument_struct_h->h_cmp_code) == 0)
	{	
		APL_DATA_MISSING("COMPANY CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
	{
		/**Smita - Total Paid Up Capital is taken from Company Master. If null ,it is initialized to 0 */
		/*Check whether the Company Exists in Authorised Status or not*/

		APL_IF_DEBUG
		{
			printf("Company Code to be checked 	= |%s|\n",p_mt_instrument_struct_h->h_cmp_code);
			printf("Company Exists 					= |%c|\n",chr_i_val_exists);
			printf("Company Authorised 			= |%c|\n",chr_i_val_authorised);
			printf("Company Deleted 				= |%c|\n",chr_i_val_deleted);
		}
	
		int_retval = MT_Chk_CmpanyFn (p_mt_instrument_struct_h->h_cmp_code,
												chr_i_val_exists,
												chr_i_val_authorised,
												chr_i_val_deleted,
												l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		else
		{
			if (p_mt_instrument_struct_h->h_total_pdcapita == 0)
			{
				int_retval = CR_GetTotalPaidCap(	&dbl_l_tot_paid_cap,
															p_mt_instrument_struct_h->h_cmp_code,
															l_debug_info_ptr);
				
				if (int_retval !=APL_SUCCESS)
				{	
					APL_GOBACK_FAIL
				}
				else
				{
					p_mt_instrument_struct_h->h_total_pdcapita = dbl_l_tot_paid_cap;
				}
			}
			APL_IF_DEBUG
			{
				printf("Total Paid Up Cap From Company Master = |%lf|\n",p_mt_instrument_struct_h->h_total_pdcapita);
			}	
		}
	}

	if (p_mt_instrument_struct_h->h_total_pdcapita < 0)
	{
		CO_InsertErr(	l_debug_info_ptr,
							ERR_VALUE_CANT_NEGATIVE,
							"TOTAL_PDCAPITA",
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
	}

	if (strlen(p_mt_instrument_struct_h->h_new_issue) == 0)
	{
		/*Initialize to N if null - Smita*/
		/*strcpy(p_mt_instrument_struct_h->h_new_issue,APL_NO_FLAG); */
		strcpy(p_mt_instrument_struct_h->h_new_issue,APL_NO_IND);
	}

	strcpy(chr_mainfuncarea,"INSTR_MAINT");
	strcpy(chr_l_condid,"CHK_CLSCODE_FOR_GR");
	
	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_classcd) == 0)
			APL_DATA_MISSING("INVESTMENT GROUP CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	strcpy(chr_mainfuncarea,"INSTR_MAINT");
	strcpy(chr_l_condid,"BOG_CODE");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if(int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
/*
	Commented by Smita - Instrument Master Maintenance - HDFCMT_003 

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_belongto) == 0)
			APL_DATA_MISSING("BOG CODE",APL_NULL_STRING,APL_NULL_STRING)
		
		else if (strlen(p_mt_instrument_struct_h->h_belongto) != 5)
		{	
			CO_InsertErr(	l_debug_info_ptr,
								ERR_BOGCODE_EQL5CHAR,
								p_mt_instrument_struct_h->h_belongto,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
	}

*/
	strcpy(chr_mainfuncarea, "INSTR_MAINT");
	strcpy(chr_l_condid, "CERTOFOWNFLG_FOR_EG");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_cert_of_own_in) == 0)
			APL_DATA_MISSING("CERT_OF_OWN_IND",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (strlen(p_mt_instrument_struct_h->h_instr_name) == 0)
		APL_DATA_MISSING("INSTRUMENT NAME",APL_NULL_STRING,APL_NULL_STRING)

	if (	(strlen(p_mt_instrument_struct_h->h_instr_isin) > 0) &&
	   	(strlen(p_mt_instrument_struct_h->h_instr_isin) < 12) 	) 
	{	
			CO_InsertErr(	l_debug_info_ptr,
								ERR_ISINCD_CANT_LESS_12CHAR,
								p_mt_instrument_struct_h->h_instr_isin,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
	}

	if (strlen(p_mt_instrument_struct_h->h_tipo_inv) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_tipo_inv,APL_TIPO_INV); /*If null, initialize to 03 */	
	}

	/*	Comments removed for validation of Instrument Type	ST1.0	*/	
	if (strlen(p_mt_instrument_struct_h->h_instr_type) == 0)
	{
		APL_DATA_MISSING("INSTRUMENT_TYPE",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
	{
		int_retval = CO_Chk_CodeValid	(	"INSTR_TYPE",
													p_mt_instrument_struct_h->h_instr_type,
													APL_DEF_COUNTRY_CODE,
													l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
		{
			CO_InsertErr(	l_debug_info_ptr,
								ERR_INVALID_CODE,	
								p_mt_instrument_struct_h->h_instr_type,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
			APL_GOBACK_FAIL
		}
	}

/*Srinivas: Instrument Sub Type    */
        if (strlen(p_mt_instrument_struct_h->h_instr_sub_type) == 0)
        {
                APL_DATA_MISSING("INSTRUMENT_SUB_TYPE",APL_NULL_STRING,APL_NULL_STRING)
        }
	/*	Comments for validation of Instrument Sub Type	ST1.0	*/	
	/*   else
        {
                int_retval = CO_Chk_CodeValid   (       "INSTR_TYPE",
                                                         p_mt_instrument_struct_h->h_instr_sub_type,
                                                         APL_DEF_COUNTRY_CODE,
                                                        l_debug_info_ptr);

                if (int_retval !=APL_SUCCESS)
                {
                        CO_InsertErr(   l_debug_info_ptr,
                                                                ERR_INVALID_CODE,
                                                                p_mt_instrument_struct_h->h_instr_sub_type,
                                                                APL_NULL_STRING,
                                                                APL_NULL_STRING,
                                                                __LINE__,
                                                                __FILE__);
                        APL_GOBACK_FAIL
                }
        }
	*/
/*Srinivas: Instrument Sub Type    */


	/*Smita - HDFCMT_003 - If Parent Isnrtument is NULL, it is same as INSTR_CODE. It is Mother Instrument*/
	if (strlen(p_mt_instrument_struct_h->h_instr_parent) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_mother_sec_ind,"Y");
	}	
	else if (strcmp(p_mt_instrument_struct_h->h_instr_parent,p_mt_instrument_struct_h->h_instr_code) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_mother_sec_ind,"Y");
	}
	else
	{
		strcpy(p_mt_instrument_struct_h->h_mother_sec_ind,"N");
	}

	APL_IF_DEBUG
	{
		printf("Instrument Code = |%s|\n",p_mt_instrument_struct_h->h_instr_code);
		printf("Parent Instrument Code = |%s|\n",p_mt_instrument_struct_h->h_instr_parent);
		printf("Mother Instrument Indicator = |%s|\n",p_mt_instrument_struct_h->h_mother_sec_ind);
	}

	/******** For Prod_Class Enhancement By : vinay kalaskar **********************/
	
	Alert("INSTR_TYPE:|%s|",p_mt_instrument_struct_h->h_instr_type);

	if(((!strcmp(p_mt_instrument_struct_h->h_instr_type,"SHS"))&&
		 (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,"AL")))||
		(!strcmp(p_mt_instrument_struct_h->h_instr_type,"WTS"))||
		(!strcmp(p_mt_instrument_struct_h->h_instr_type,"RTS")))
	{
		strcpy(p_mt_instrument_struct_h->h_prod_class,APL_PROD_SHS_TYPE);
	}
	else if((!strcmp(p_mt_instrument_struct_h->h_instr_type,"BON"))||
			  (!strcmp(p_mt_instrument_struct_h->h_instr_sub_type,"AL")))
	{
		strcpy(p_mt_instrument_struct_h->h_prod_class,APL_PROD_BON_TYPE);
	}
	
	Alert("h_prod_class:|%s|",p_mt_instrument_struct_h->h_prod_class);
	
	/*****************************************************************************/
	if (strlen(p_mt_instrument_struct_h->h_prod_class) == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_prod_class,APL_PROD_TYPE); /*Initialize to 1 if null*/
	}

	/**Sector Code is not mandatory - HDFCMT_003 - Smita --whether to pick it up from company master */	
	/**
	if (strlen(p_mt_instrument_struct_h->h_sec_dl_code) == 0)
	{		
			APL_DATA_MISSING("SECTOR CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	**/

	strcpy(chr_mainfuncarea, "INSTR_MAINT");
	strcpy(chr_l_condid, "CLASSCD");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_classcd) == 0)
		{	
			APL_DATA_MISSING("CLASSCD",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	
	if (	(strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && 
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_WARRANTS) != 0))
	{
		if (p_mt_instrument_struct_h->h_last_incom_rt < 0)
		{
			CO_InsertErr(	l_debug_info_ptr,
								ERR_VALUE_CANT_NEGATIVE,
								"LAST INCOME RATE",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
/*	
		if (((strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_FMT) == 0)) &&
			 (strcmp(p_mt_instrument_struct_h->h_disct_ind,"N") == 0))
		{ 
			if (p_mt_instrument_struct_h->h_instr_int_rate <= 0)
			{
 				CO_InsertErr(	l_debug_info_ptr,
									ERR_VAL_SHLDBERR_POS,
									"INSTR_INT_RATE",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
		}
*/
	}
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
/*
	if (	(strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && 
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_WARRANTS) != 0))
	{
		if ((strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_FMT) == 0))
	   {
			if (strlen(p_mt_instrument_struct_h->h_disct_ind) == 0)
				APL_DATA_MISSING("DISCT_IND",APL_NULL_STRING,APL_NULL_STRING)
			
			if (strlen(p_mt_instrument_struct_h->h_issue_date) == 0)
				APL_DATA_MISSING("ISSUE DT",APL_NULL_STRING,APL_NULL_STRING)

			if (strlen(p_mt_instrument_struct_h->h_mature_dt) == 0)
				APL_DATA_MISSING("MATURE DT ",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
*/
/*
	if (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) == 0 )
	{
    	int_l_condexists = 0;
    	strcpy(chr_mainfuncarea, "INSTR_MAINT");
    	strcpy(chr_l_condid, "LST_PAY_DT_ENB");

    	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
       
		if (int_retval != APL_SUCCESS)
   	APL_GOBACK_FAIL

    	if (!int_l_condexists)
    	{	
	 		if (strlen(p_mt_instrument_struct_h->h_last_pymt_date) == 0)
			{
				APL_DATA_MISSING("LAST_PAY_DATE",APL_NULL_STRING,APL_NULL_STRING)
			}
		}
	}
*/

	/*Smita - If Mother Sec Ind = N, then Parent Instrument Code is essential **/		
	if (strcmp(p_mt_instrument_struct_h->h_mother_sec_ind,"N") == 0)
	{
		if (strlen(p_mt_instrument_struct_h->h_instr_parent) == 0)
		{
			APL_DATA_MISSING("INSTR_PARENT",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
/*
	if (	(strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && 
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_WARRANTS) != 0)	)
	{
		if ((strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) == 0) ||
			 (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_FMT) == 0))
		{
			if (strcmp(p_mt_instrument_struct_h->h_disct_ind,"N") == 0)
			{
				if (strlen(p_mt_instrument_struct_h->h_int_typ) == 0)
					APL_DATA_MISSING("INT_TYPE",APL_NULL_STRING,APL_NULL_STRING)
				
				if (strlen(p_mt_instrument_struct_h->h_freq_code) == 0)
					APL_DATA_MISSING("FREQ_CODE",APL_NULL_STRING,APL_NULL_STRING)
				
				if (strlen(p_mt_instrument_struct_h->h_int_acctyp) == 0)
					APL_DATA_MISSING("INT_ACCTYP",APL_NULL_STRING,APL_NULL_STRING)
				
				if (strlen(p_mt_instrument_struct_h->h_next_pay_date) == 0)
					APL_DATA_MISSING("NEXT PAY DT",APL_NULL_STRING,APL_NULL_STRING)
			}
	
			if (strcmp(p_mt_instrument_struct_h->h_disct_ind,"Y") == 0)
			{
				if (strlen(p_mt_instrument_struct_h->h_taxonmat_ind) == 0)
					APL_DATA_MISSING("TAXONMAT_IND",APL_NULL_STRING,APL_NULL_STRING)
			}
		}
	}
*/
		
 	strcpy(chr_mainfuncarea,"INSTR_MAINT");
 	strcpy(chr_l_condid,"MIN_DENOM_DISABLE");
	
 	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
  
	if (int_retval != APL_SUCCESS)
     		APL_GOBACK_FAIL

  	if (int_l_condexists == 0)
  	{
		if (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_FMT) == 0)
		{
			if (p_mt_instrument_struct_h->h_min_fmt_dl_qty <= 0)
			{
				CO_InsertErr(	l_debug_info_ptr,	
									ERR_VAL_SHLDBERR_POS,
									"MIN_FMT_DL_QTY",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
		}
  	}
	
	if (strcmp(l_mt_core_sys_params_struct_h.no_stxdl_ind,"N") == 0)
	{
		if (strcmp(p_mt_instrument_struct_h->h_ex_arena,EX_ARENA_STX) != 0)
		{		
			CO_InsertErr(	l_debug_info_ptr,
								ERR_INVALID_ARGUMENT,
								"EX_ARENA",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
	}
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (	(strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && 
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_WARRANTS) != 0))
	{
		/*Smita - Check these dates if instrument type is not Equity**/
		if (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SHARE) !=0)
		{
			if (strlen(p_mt_instrument_struct_h->h_issue_date) != 0)
			{
				if (CO_Pro_DateComp(	chr_l_sys_date,
											p_mt_instrument_struct_h->h_issue_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

		/* Abhijeet (01/05/2006) : As this validation is not required for Kotak */
		/*
				if (int_l_diff > 0)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_DATE_CANT_GRT_TODAY,
										"ISSUE DT",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}*/
			}
		
			if (	(strlen(p_mt_instrument_struct_h->h_issue_date) 	!= 0) && 
					(strlen(p_mt_instrument_struct_h->h_last_pymt_date) 	!= 0))
			{
				if (CO_Pro_DateComp(	p_mt_instrument_struct_h->h_last_pymt_date,
											p_mt_instrument_struct_h->h_issue_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

				if (int_l_diff > 0)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_ISSUEDT_CANT_GRTR_LASTPAYDT,
										APL_NULL_STRING,
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}
	
			if (	(strlen(p_mt_instrument_struct_h->h_next_pay_date) != 0) && 
					(strlen(p_mt_instrument_struct_h->h_last_pymt_date) != 0))
			{
				if (CO_Pro_DateComp(	p_mt_instrument_struct_h->h_last_pymt_date,
											p_mt_instrument_struct_h->h_next_pay_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

				if (int_l_diff <= 0)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_LASTPAYDT_CANT_GRTR_NXTPAYDT,
										APL_NULL_STRING,
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}

			if (	(strlen(p_mt_instrument_struct_h->h_mature_dt) 	!= 0) && 
					(strlen(p_mt_instrument_struct_h->h_issue_date) 	!= 0))
			{
				if (CO_Pro_DateComp(	p_mt_instrument_struct_h->h_mature_dt,
											p_mt_instrument_struct_h->h_issue_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

				if (int_l_diff > 0)
				{	
					CO_InsertErr(	l_debug_info_ptr,
										ERR_ISSUEDT_CANT_GRTR_MATURITYDT,
										"ISSUE DT",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}
	
			if (	(strlen(p_mt_instrument_struct_h->h_issue_date) 	!= 0) && 
					(strlen(p_mt_instrument_struct_h->h_next_pay_date) != 0))
			{
				if (CO_Pro_DateComp(	p_mt_instrument_struct_h->h_issue_date,
											p_mt_instrument_struct_h->h_next_pay_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL
	
				if (int_l_diff < 0)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_ISSUEDT_CANT_GRTR_NXTPAYDT,
										"NEXT PAY DT",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}
	
			if (	(strlen(p_mt_instrument_struct_h->h_mature_dt) 	!= 0) && 
					(strlen(p_mt_instrument_struct_h->h_next_pay_date) != 0))
			{
				if (CO_Pro_DateComp(	p_mt_instrument_struct_h->h_mature_dt,
											p_mt_instrument_struct_h->h_next_pay_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL
	
				if (int_l_diff > 0)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_INSTR_NXTPYDT_CANT_GRTR_MATURITYDT,
										"NEXT PAY DT",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}

			/*Added Validations for Issue Date < first Int date <issue maturity date*/
			if (	(strlen(p_mt_instrument_struct_h->h_issue_date)  != 0) &&
					(strlen(p_mt_instrument_struct_h->h_instr_fst_pymt_dt) != 0)	)
			{
				if (CO_Pro_DateComp( p_mt_instrument_struct_h->h_instr_fst_pymt_dt,
											p_mt_instrument_struct_h->h_issue_date,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL
			
				if (int_l_diff > 0)
				{
					CO_InsertErr(  l_debug_info_ptr,
										ERR_INSTR_ISSUEDT_CANT_GRT_FSTPYMT_DT,
										"Issue Date",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}

			if (	(strlen(p_mt_instrument_struct_h->h_instr_fst_pymt_dt) != 0) &&
					(strlen(p_mt_instrument_struct_h->h_mature_dt	) != 0)	)
			{
				if (CO_Pro_DateComp( p_mt_instrument_struct_h->h_mature_dt,
											p_mt_instrument_struct_h->h_instr_fst_pymt_dt,
											&int_l_diff,
											l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL
			
				if (int_l_diff > 0)
				{
					CO_InsertErr(  l_debug_info_ptr,
										ERR_INSTR_FSTPYMT_DT_CANT_GRT_MATUREDT,
										"First Pay Dt",
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				}
			}
		} /**Smita**/
	}

	if ( strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind, "Y") == 0 ) 
	{
		if (strcmp(p_mt_instrument_struct_h->h_ipo_ind,"Y") == 0)
		{
			if (strlen(p_mt_instrument_struct_h->h_valid_ipo_date) == 0)
			{
				APL_DATA_MISSING("IPO VALID DATE", APL_NULL_STRING, APL_NULL_STRING)
			}
			else
			{
				int_l_holiday_flg = 0;

				if (CO_Chk_Holiday(	p_mt_instrument_struct_h->h_valid_ipo_date, 
											&int_l_holiday_flg, 
											l_debug_info_ptr,APL_NULL_STRING) == APL_FAILURE)
				{
					APL_GOBACK_FAIL
				}
				
				if ( int_l_holiday_flg )
				{
					CO_InsertWarning(	l_debug_info_ptr, 
											ERR_DATE_IS_HOLIDAY, 
											"IPO Valid Date", 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__,  
											__FILE__);
				}
				
				if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
					APL_GOBACK_FAIL

				if (strlen(p_mt_instrument_struct_h->h_valid_ipo_date) != 0)
				{
					if (CO_Pro_DateComp(	chr_l_sys_date, 
												p_mt_instrument_struct_h->h_valid_ipo_date, 
												&int_l_diff, 
												l_debug_info_ptr) != APL_SUCCESS)
						APL_GOBACK_FAIL

					if (int_l_diff <= 0)
					{
						CO_InsertErr(	l_debug_info_ptr, 
											ERR_DATE_CANT_LESS_TODAY, 
											"IPO VALID DATE", 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__);
					}
				}
			}
		}
	}
	/*validations for New Fields - Smita */
	if (strlen(p_mt_instrument_struct_h->h_instr_priv_placed) == 0)
	{
		APL_DATA_MISSING("PRIVATELY PLACED INSTRUMENT",APL_NULL_STRING,APL_NULL_STRING);
	}		

	if (	(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SHARE) 			!=0) &&	
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_PREF_SHARE) 	!=0) &&	
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_EXS_EQUITY_CD)!=0)	)
	{
		if (strlen(p_mt_instrument_struct_h->h_instr_is_secured) == 0)
		{
			APL_DATA_MISSING("SECURED INSTRUMENT",APL_NULL_STRING,APL_NULL_STRING);
		}
	}		

	/*If Instrument Exists in Demat Form, then Marketable Lot = 1 - Smita */
	if (strcmp(p_mt_instrument_struct_h->h_instr_is_demat,APL_YES_IND) == 0)
	{
		if (p_mt_instrument_struct_h->h_min_fmt_dl_qty > 1)
		{
			CO_InsertErr(	l_debug_info_ptr,
								ERR_MARKET_LOT_CANT_BE_GRT_ONE,
								"MARKETABLE LOT",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
	}	

	/*	Condition change from Warrents to Equity	UAT	Rohit */
	/*If Instrument Type is Warrants, then only Attached Instrument and Detach Date can be accepted*/
	if ((	(strlen(p_mt_instrument_struct_h->h_instr_attached)  						!=0)  ||
			(strlen(p_mt_instrument_struct_h->h_instr_detach_dt) 						!= 0) ) && 
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_SHARE) 	!=0) 		)
	{
		CO_InsertErr(  l_debug_info_ptr,
		               ERR_INSTRUMENT_TYPE_NOT_PROPER,
							"INSTRUMENT NOT SHARES",
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
	}

	/*If Instrument Type is Equity, then all the following will not be accepted.*/

	if (	(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND)	== 0) ||
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_FMT) 	== 0)		)
	{
		if (strlen(p_mt_instrument_struct_h->h_issue_date) == 0) 
			APL_DATA_MISSING("Issue Date",APL_NULL_STRING,APL_NULL_STRING);

	   if	(strlen(p_mt_instrument_struct_h->h_mature_dt) ==0 )
			APL_DATA_MISSING("Maturity Date",APL_NULL_STRING,APL_NULL_STRING);

		/*	Remove mandatory check for DB	UAT	Rohit */
	  if (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) != 0)	
	  	{
		if (strlen(p_mt_instrument_struct_h->h_instr_exdt_loa)==0) 
			APL_DATA_MISSING("Ex Date LOA",APL_NULL_STRING,APL_NULL_STRING);
		}

		if	(strlen(p_mt_instrument_struct_h->h_instr_is_secured)==0)
			APL_DATA_MISSING("IS Secured",APL_NULL_STRING,APL_NULL_STRING);

		/*	Remove mandatory check for DB	UAT	Rohit */
	  if (strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_SUB_BOND) != 0)	
	  	{
		if	(strlen(p_mt_instrument_struct_h->h_instr_secured_dt)==0)
			APL_DATA_MISSING("Secured Dt",APL_NULL_STRING,APL_NULL_STRING);
		}

		if (strlen(p_mt_instrument_struct_h->h_int_typ)==0)
			APL_DATA_MISSING("Int Typ",APL_NULL_STRING,APL_NULL_STRING);

		if	(strlen(p_mt_instrument_struct_h->h_instr_part_rd_flg)==0)
			APL_DATA_MISSING("Partial Redemp Flg",APL_NULL_STRING,APL_NULL_STRING);

		if (strlen(p_mt_instrument_struct_h->h_int_acctyp)==0)
			APL_DATA_MISSING("Int Acc Typ",APL_NULL_STRING,APL_NULL_STRING);

		if	(strlen(p_mt_instrument_struct_h->h_freq_code)==0)
			APL_DATA_MISSING("Int Freq Code",APL_NULL_STRING,APL_NULL_STRING);
	
		if	(strlen(p_mt_instrument_struct_h->h_instr_fst_pymt_dt)==0)
			APL_DATA_MISSING("First Pay Dt",APL_NULL_STRING,APL_NULL_STRING);

		if	(strlen(p_mt_instrument_struct_h->h_last_pymt_date)==0)
			APL_DATA_MISSING("Last Pay Dt",APL_NULL_STRING,APL_NULL_STRING);

		if	(strlen(p_mt_instrument_struct_h->h_next_pay_date)==0)
			APL_DATA_MISSING("Next Pay dt",APL_NULL_STRING,APL_NULL_STRING);

		if (strcmp(p_mt_instrument_struct_h->h_int_typ,APL_INSTRU_FLOATING) != 0) /*** SGS ***/
		{
			if	(p_mt_instrument_struct_h->h_instr_int_rate == 0) 
				APL_DATA_MISSING("Int Rate",APL_NULL_STRING,APL_NULL_STRING);
		}

		if	(p_mt_instrument_struct_h->h_instrshut_period == 0)
			APL_DATA_MISSING("Shut Period",APL_NULL_STRING,APL_NULL_STRING);
	}	

	/*Additional Validations - Smita - HDFCMT_003*/
	if (strlen(p_mt_instrument_struct_h->h_instr_crisil_code) !=0)
	{
		APL_IF_DEBUG
		{
			printf("Crisil Code = |%s|\n",p_mt_instrument_struct_h->h_instr_crisil_code);
			printf("Crisil Code Exists = |%c|\n",chr_i_val_exists);
			printf("Crisil Code Auth   = |%c|\n",chr_i_val_authorised);
			printf("Crisil Code Del    = |%c|\n",chr_i_val_deleted);
		}

		int_retval = CO_Chk_CrdRatAgnValid (	p_mt_instrument_struct_h->h_instr_crisil_code,
															chr_i_val_exists,
															chr_i_val_authorised,
															chr_i_val_deleted,
															l_debug_info_ptr);
	
		if (int_retval !=APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strlen(p_mt_instrument_struct_h->h_instr_reg_code) != 0)
	{
		APL_IF_DEBUG
		{
			printf("Registrar Code = |%s|\n",p_mt_instrument_struct_h->h_instr_reg_code);
			printf("Party Type = |%s|\n",APL_PARTY_REG);
			printf("Registrar Code Exists = |%c|\n",chr_i_val_exists);
			printf("Registrar Code Auth   = |%c|\n",chr_i_val_authorised);
			printf("Registrar Code Del		= |%c|\n",chr_i_val_deleted);
		}
		  /*UnComment after Party Master is checked in*/

		int_retval = MT_Chk_PtyVal 	(	p_mt_instrument_struct_h->h_instr_reg_code,
													APL_PARTY_REG,
													chr_i_val_exists,
													chr_i_val_authorised,
													chr_i_val_deleted,
													l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
			APL_GOBACK_FAIL

	}
	
	
	if (strlen(p_mt_instrument_struct_h->h_instr_pc_ind) !=0)
	{
		APL_IF_DEBUG
		{
			printf("Put Call Flag = |%s|\n",p_mt_instrument_struct_h->h_instr_pc_ind);
		}
	/*No Check for Put/Call/Daily Ind Reqd Here..Since Put/Call Indicator will be Yes/No now - Smita - HDFCMT_003*/
/*
		int_retval = CO_Chk_CodeValid (  "PUT_CALL_DLY",
													p_mt_instrument_struct_h->h_instr_pc_ind,
													g_mt_commonsys_params_struct_h.nation_code,
													l_debug_info_ptr);
		
		if (int_retval !=APL_SUCCESS)
		{
		   CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_instrument_struct_h->h_instr_pc_ind,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
			APL_GOBACK_FAIL
		}

		if (strcmp(p_mt_instrument_struct_h->h_instr_pc_ind,APL_PC_DAILY) != 0)
		{
			if (	(strlen(p_mt_instrument_struct_h->h_instr_pc_effdt) !=0) ||
					(strlen(p_mt_instrument_struct_h->h_instr_pc_cutofftime) !=0) )
			{
				CO_InsertErr	(	l_debug_info_ptr,
										ERR_PC_NOT_DAILY,
										APL_NULL_STRING,
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				APL_GOBACK_FAIL
			}
		}*/
	}

	if (	(p_mt_instrument_struct_h->h_instr_div_rate != 0) &&
			(strcmp(p_mt_instrument_struct_h->h_instr_sub_type,APL_INSTRU_PREF_SHARE) == 0)	)
	{
		CO_InsertErr   (  l_debug_info_ptr,
								ERR_DIV_RT_NOT_ALLOWED_PREF_SHS,
								"Dividend Rate",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		APL_GOBACK_FAIL
	}

   if (strlen(p_mt_instrument_struct_h->h_freq_code)!=0)
	{
	   int_retval = CO_Chk_CodeValid (  "PYMT_FREQUENCY",
                                       p_mt_instrument_struct_h->h_freq_code,
                                       APL_DEF_COUNTRY_CODE,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
      {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_instrument_struct_h->h_freq_code,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
         APL_GOBACK_FAIL
      }
	}

	if (strlen(p_mt_instrument_struct_h->h_int_acctyp)!=0)
	{
		int_retval = CO_Chk_CodeValid (  "INT_CALC_TYPE",
                                       p_mt_instrument_struct_h->h_int_acctyp,
                                       APL_DEF_COUNTRY_CODE,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
      {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_instrument_struct_h->h_int_acctyp,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
         APL_GOBACK_FAIL
      }
	}
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(p_mt_instrument_struct_h->h_chng_lst_ind,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h->h_chng_isin,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h->h_chg_mkr,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h->h_chng_cd,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h->h_old_lst_paydt,APL_NULL_STRING);
	strcpy(p_mt_instrument_struct_h->h_mod_last_paydt,APL_NULL_STRING);
	
	if (strcmp(p_mt_instrument_struct_h->h_mother_sec_ind,"Y") == 0)
	{
		strcpy(p_mt_instrument_struct_h->h_instr_parent,APL_NULL_STRING);
	}

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_struct_h->h_instr_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
	{
		chr_iexist = 'N';
	
		int_retval = CO_Chk_InstrValid	(	p_mt_instrument_struct_h->h_instr_code,
														chr_iexist,
														NULL,
														NULL,
														NULL,
														NULL,
														NULL,
														l_debug_info_ptr);
	}
	else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
	{
		p_key_values[0] = p_mt_instrument_struct_h->h_instr_code;
		p_key_values[1] = APL_NULL_STRING;

		int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
														p_key_values,
														g_mst_table_name,
														"ROWID",
														chr_l_field_val,
														l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

 		strcpy(chr_l_row_id_instr,chr_l_field_val);
		
		int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
														p_key_values,
														g_mst_table_name,
														"ACCESS_STAMP",
														chr_l_field_val,
														l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		APL_IF_DEBUG
      {
          printf("Access Stamp from Structure = |%s|\n",p_mt_instrument_struct_h->h_access_stamp);
          printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
      }

		if(strcmp(p_intl_env_data_struct_h->subprocess, "API") == 0)
		strcpy(p_mt_instrument_struct_h->h_access_stamp,chr_l_field_val);
	
		if (strcmp(chr_l_field_val,p_mt_instrument_struct_h->h_access_stamp) != 0)
		{
			CO_InsertErr(	l_debug_info_ptr,
								ERR_ACCESSSTAMP_CHGD,
								APL_NULL_STRING,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
			APL_GOBACK_FAIL
		}

		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_InstrValid(	p_mt_instrument_struct_h->h_instr_code,
													chr_iexist,
													NULL,
													chr_ideleted,chr_ifrozen,NULL,NULL,l_debug_info_ptr);

	}

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Chk_InstrOth(	p_mt_instrument_struct_h,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL


	l_deal_ord_struct_h = (DEAL_ORD_STRUCT_H *)calloc(1,sizeof(DEAL_ORD_STRUCT_H));
	APL_MALLOC_FAIL(l_deal_ord_struct_h)
	
	/*	Assign allow indicator to deal order structure	UAT Rohit	*/
	strcpy(l_deal_ord_struct_h->h_allow_rf,p_mt_instrument_struct_h->h_allow_rf);
	strcpy(l_deal_ord_struct_h->h_allow_rvp,p_mt_instrument_struct_h->h_allow_rvp);
	strcpy(l_deal_ord_struct_h->h_allow_df,p_mt_instrument_struct_h->h_allow_df);
	strcpy(l_deal_ord_struct_h->h_allow_dvp,p_mt_instrument_struct_h->h_allow_dvp);
		
	int_retval = MT_Rtv_DLOrdFldVal(	p_mt_instrument_struct_h->h_classcd,
												l_deal_ord_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(p_mt_instrument_struct_h->h_allow_rf,l_deal_ord_struct_h->h_allow_rf);
	strcpy(p_mt_instrument_struct_h->h_allow_rvp,l_deal_ord_struct_h->h_allow_rvp);
	strcpy(p_mt_instrument_struct_h->h_allow_df,l_deal_ord_struct_h->h_allow_df);
	strcpy(p_mt_instrument_struct_h->h_allow_dvp,l_deal_ord_struct_h->h_allow_dvp);
	strcpy(p_mt_instrument_struct_h->h_ord_type,l_deal_ord_struct_h->h_order_class);
	

 	int_retval = CR_Mod_Instr(	p_mt_instrument_struct_h,
										chr_l_row_id_instr,
										p_intl_env_data_struct_h,
										l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

 	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_FREE(l_deal_ord_struct_h)
		
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_Instr Success\n",NULL,p_intl_env_data_struct_h);
	
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_Instr Failure\n",NULL,p_intl_env_data_struct_h);

		return(APL_FAILURE);
	}
}


int MT_Upt_Instr(		MT_INST_CORP_GRP_STRUCT_H *p_mt_inst_corp_grp_struct_h, 
							INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int			int_retval;
	
	
		CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Upt_Instr \n",NULL,p_intl_env_data_struct_h);
  Alert("balaji1");
	
	if (strlen(p_mt_inst_corp_grp_struct_h->h_instr_code) == 0)
	{
		APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	
      int_retval = CR_Upt_Instr(	p_mt_inst_corp_grp_struct_h,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);


	if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

    APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Upt_Instr Success\n",NULL,p_intl_env_data_struct_h);
	
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Upt_Instr Failure\n",NULL,p_intl_env_data_struct_h);

		return(APL_FAILURE);
	}
}


/******************************************************************************************
 *                                                                                        *
 * Function Name         : MT_Mod_InstrOth 	                                          	*
 *                                                                                        *
 * Description           : This Function Accepts Instrument Code,Access Stamp,Env String  *
 *                         and debug pointer.                                             *
 *                         returns Success/Failure depending upon validn.                 *
 *                                                                                        *
 *                                                                                        *
 * Parameter                  Type                       Mode     Description             *
 * ------------               --------                   -----    ---------------         *
 * p_instrcode		      		char *			 				I	  		Instrument Code	  		*
 *											  																			*
 * p_instr_access_stamp	      char *			 				I	  		Access Stamp of Instr   *
 *											  																			*
 * p_intl_env_data_struct_h_d INTL_ENV_DATA_STRUCT_H *   I        Environment String      *
 *                                                                Structure               *
 *											  																			*	
 * l_debug_info_ptr           DEBUG_INFO_STRUCT_H **     I        Debug Info Structure    *
 *                                                                                        *
 * Return Values        :                                                                 *
 *                                                                                        *
 *  APL_SUCCESS  - SUCCESS                                                                *
 *  APL_FAILURE  - FAILURE                                                                *
 *                                                                                        *
 ******************************************************************************************/
int MT_Mod_InstrOth(	char *p_instr_code,
							char *p_instr_access_stamp,
							INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval;
	short							int_l_condexists;
	char							chr_l_field_val[40];
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	DEAL_ORD_STRUCT_H			*l_deal_ord_struct_h = NULL;
	char							chr_iexist,chr_iauthorised,chr_ideleted,chr_ifrozen;
	char							chr_l_row_id_instr[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
        char                    l_field_name[25]= APL_NULL_STRING;
	char                    p_field_ind[5]= APL_NULL_STRING;
	char                    l_int_type[3]= APL_NULL_STRING;
	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrOth \n",NULL,p_intl_env_data_struct_h);

 	memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	if (strlen(p_instr_code) == 0)
		APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	
	if(strcmp(p_intl_env_data_struct_h->subprocess, "API")){
	if (strlen(p_instr_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Instrument Code is |%s| \n",p_instr_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"User is |%s| \n",p_intl_env_data_struct_h->usr);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);	
		sprintf(chr_l_buf,"Country Code is |%s| \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

	}

   char *p_key_codes[2];
   char *p_key_values[2];

   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]=APL_NULL_STRING;

   p_key_values[0]=p_instr_code;
	p_key_values[1]=APL_NULL_STRING;

	int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
													p_key_values,
													g_mst_table_name,
													"ROWID",
													chr_l_field_val,
													l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

 	strcpy(chr_l_row_id_instr,chr_l_field_val);
	
	int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
													p_key_values,
													g_mst_table_name,
													"ACCESS_STAMP",
													chr_l_field_val,
													l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		printf("Access Stamp from Structure = |%s|\n",p_instr_access_stamp);
		printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
	}

	if(strcmp(p_intl_env_data_struct_h->subprocess, "API") == 0)
		strcpy(p_instr_access_stamp,chr_l_field_val);
	
	if (strcmp(chr_l_field_val,p_instr_access_stamp) != 0)
	{
		CO_InsertErr(	l_debug_info_ptr,
							ERR_ACCESSSTAMP_CHGD,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
		APL_GOBACK_FAIL
	}
       strcpy(l_field_name,"INT_TYP");     
       p_key_values[0] = p_instr_code;
       p_key_values[1] = APL_NULL_STRING;

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             p_key_codes,
					   	                       p_key_values,
								                    g_mst_table_name,
									                 p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

     printf("Value of Interest Type==|%s|\n",p_field_ind);
     strcpy(l_int_type,p_field_ind);   

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_InstrValid(	p_instr_code,
													chr_iexist,
													NULL,
													chr_ideleted,
													chr_ifrozen,
													NULL,
													NULL,
													l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
														p_key_values,	
														g_mst_table_name,
														"INSTR_SUB_TYPE",
														chr_l_field_val,
														l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
		
		if (	(strcmp(g_mt_commonsys_params_struct_h.ca_module_ind,"Y") == 0) && 
				(strcmp(chr_l_field_val,APL_INSTRU_SUB_WARRANTS) != 0)	)
		{
			int_retval = CR_Chk_InstrEvent(p_instr_code,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
			{
 				CO_InsertErr(	l_debug_info_ptr,
									ERR_EVNTEXIST_CANT_DEL,
									p_instr_code,
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}

		if (strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0)
		{
			int_retval = CR_Chk_InstrOrd(p_instr_code,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
 				CO_InsertErr(	l_debug_info_ptr,
									ERR_ORDEXIST_CANT_DEL_INSTR,
									p_instr_code,
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}
		
		int_retval = CR_Chk_ChldInstr(p_instr_code,l_debug_info_ptr);

		if (int_retval == APL_SUCCESS)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_CHILDINSTREXIST_CANTDEL_INSTR,
								p_instr_code,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		
		int_retval = CR_Chk_InstrTrd(p_instr_code,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_TRDEXIST_CANT_DEL_INSTR,
								p_instr_code,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrPos(p_instr_code,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_PYMNTTRDEXIST_CANT_DEL_INSTR,
								p_instr_code,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		strcpy(chr_mainfuncarea, "INSTR_MAINT");
		strcpy(chr_l_condid, "INSTR_IN_LRSFK_CANTDEL");

		int_retval = CO_Chk_CntryEnabled(	chr_mainfuncarea,
														chr_l_condid,
														&int_l_condexists,
														l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if (int_l_condexists > 0)
		{
			int_retval = CR_Chk_InstrLRRpt(p_instr_code,l_debug_info_ptr);
			if (int_retval == APL_RECS_EXIST)
			{
 				CO_InsertErr(	l_debug_info_ptr,
									ERR_LOCALREP_POSN_EXIST_CANTDEL_INSTR,
									p_instr_code,
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}
	
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"CAEVENT",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Event Image Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"DL_DEAL",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Log AutoEvnt Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"MT_INSTR_RATING_DET",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"RightsProcessing Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"MT_PC_DET",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Alert Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"MT_RESET_DET",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"DlyMarketPrice Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"CALOGAUTOEVENT",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"BackDatedSettlement Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		
		/****int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"CLOCNCHG",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Location Change Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL***/

		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"DL_MISDEAL",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Missing Txns",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL

		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"MT_RED_DP_DET",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Acct Entries Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		/**int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"DL_INSTRUMENTCONV",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Acct Entries Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL***/
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"MT_INSTR_EXCH_DET",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Acct Entries Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"DL_DEALREPAIR",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);
		
		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Acct Entries Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
		int_retval = CR_Chk_InstrCodeUnique(	p_instr_code,
															"DL_LOCNCHG",
															p_intl_env_data_struct_h,
															l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
 			CO_InsertErr(	l_debug_info_ptr,
								ERR_INSTREXIST_CANTDEL,
								"Acct Entries Recs",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL

		/*Smita - Before Deleting Master Details, all the Mapping Details should be deleted (Child tables should not contain data in them related to this Instrument Code - HDFCMT_003 */

		APL_IF_DEBUG
		{
			printf("Calling Func CR_Chk_CodeInChld with following Details...\n");
			printf("Key Code 0 = |%s|\n",p_key_codes[0]);
			printf("Key Code 1 = |%s|\n",p_key_codes[1]);
			printf("Key Value 0 = |%s|\n",p_key_values[0]);
			printf("Key Value 1 = |%s|\n",p_key_values[1]);
		}

		int_retval = CR_Chk_CodeInChld(		p_key_codes,
														p_key_values,
														g_chld_table_names,
														p_intl_env_data_struct_h,
														l_debug_info_ptr);	

		if (int_retval != APL_SUCCESS)
		{
			CO_InsertErr(  l_debug_info_ptr,
								MAP_INSTR_EXIST_CANTDEL,
								"Mapping Details Exist",
								p_instr_code,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
		}
		else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
	}

	if (	(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) || 
			(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0))
	{
		chr_iexist ='Y';
		chr_iauthorised = 'N';

		int_retval = CO_Chk_InstrValid(	p_instr_code,
													chr_iexist,
													chr_iauthorised,
													NULL,
													NULL,
													NULL,
													NULL,
													l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		int_retval = CR_Chk_InstrMkrChkr(	p_instr_code,
														p_intl_env_data_struct_h->usr,
														l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}

    /* Kouser - HDFC - New Requirement Changes */
    /* Start of Interest Type Validation Based on Valid Instrument Type */

   if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0)
   {
       strcpy(l_field_name,"INSTR_SUB_TYPE");     
       p_key_values[0] = p_instr_code;
       p_key_values[1] = APL_NULL_STRING;

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             p_key_codes,
					   	                       p_key_values,
								                    g_mst_table_name,
									                 p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

           printf("VALUE OF RERUTN IND ==|%s|\n",p_field_ind);

     if ((strcmp(p_field_ind,APL_INSTRU_DEBENTURES) == 0) || (strcmp(p_field_ind,APL_INSTRU_SUB_BOND) == 0) || (strcmp(p_field_ind,APL_INSTRU_LOYALTY_COUPONS) == 0) || (strcmp(p_field_ind,APL_INSTRU_GOVT_BOND) == 0) || (strcmp(p_field_ind,APL_INSTRU_GOVT_PAPERS) == 0) || (strcmp(p_field_ind,APL_INSTRU_FIXED_DEPO_RCP) == 0) || (strcmp(p_field_ind,APL_INSTRU_BOND_QNTY_BASED) == 0) || (strcmp(p_field_ind,APL_INSTRU_SAVINGS_CERT) == 0) || (strcmp(p_field_ind,APL_INSTRU_CERT_OF_DEPO) == 0) || (strcmp(p_field_ind,APL_INSTRU_ALLOT_LETTER) == 0) || (strcmp(p_field_ind,APL_INSTRU_COMM_PAPER) == 0) || (strcmp(p_field_ind,APL_INSTRU_PROMISSORY_NOTE) == 0) || (strcmp(p_field_ind,APL_INSTRU_SGL_VALUE_BONDS) == 0) || (strcmp(p_field_ind,APL_INSTRU_FRAC_COUPONS) == 0) || (strcmp(p_field_ind,APL_INSTRU_GOVT_SEC) == 0)) 
     { 

            if (strcmp(l_int_type,APL_INSTRU_FLOATING) == 0)
            {
               strcpy(l_field_name,"STATUS");     
               strcpy(chr_chd_table_name,"MT_FLRATE_INSTRUMENT");
	            p_key_values[0] = p_instr_code;
	            p_key_values[1] = APL_NULL_STRING;
					strcpy(p_field_ind,APL_NULL_STRING);

               int_retval = CR_Chk_MasterField( p_field_ind,
		                                          l_field_name,
					                                 p_key_codes,
					                                 p_key_values,
								                        chr_chd_table_name,
									                     p_intl_env_data_struct_h,
									                     l_debug_info_ptr);

               printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);
					if(strcmp(p_field_ind,APL_NULL_STRING)!=0)
					{
               if (strcmp(p_field_ind,APL_STS_AUTH) != 0) 
               {
                  CO_InsertErr(  l_debug_info_ptr,
                                 ERR_FLTRATE_INSTRU_UNAUTH_STATUS,
                                 p_instr_code,
                                 APL_NULL_STRING,
                                 APL_NULL_STRING,
                                 __LINE__,
                                 __FILE__);
                  APL_GOBACK_FAIL
               }
					}
              }
             }
            }

    /* Kouser - HDFC - New Requirement Changes */
    /* End of Interest Type Validation Based on Valid Instrument Type */

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';

		int_retval = CO_Chk_InstrValid(	p_instr_code,
													chr_iexist,
													chr_iauthorised,
													chr_ideleted,
													chr_ifrozen,
													NULL,
													NULL,
													l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_UNFREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'Y';
	
		int_retval = CO_Chk_InstrValid(	p_instr_code,
													chr_iexist,
													NULL,
													chr_ideleted,
													chr_ifrozen,
													NULL,
													NULL,
													l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	l_deal_ord_struct_h = (DEAL_ORD_STRUCT_H *)calloc(1,sizeof(DEAL_ORD_STRUCT_H));
	APL_MALLOC_FAIL(l_deal_ord_struct_h)
	
	int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
													p_key_values,
													g_mst_table_name,
													"CLASSCD",
													chr_l_field_val,
													l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = MT_Rtv_DLOrdFldVal(chr_l_field_val,l_deal_ord_struct_h,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrOth(	p_instr_code,
											chr_l_row_id_instr,
											l_deal_ord_struct_h,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrOth \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_FREE(l_deal_ord_struct_h)

		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrOth \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}

/******************************************************************************************
 *                                                                                        *
 * Function Name         : MT_Rtv_DLOrdFldVal 	                                          *
 *                                                                                        *
 * Description           : This Function Accepts Instrument Class Code,Deal Structure     *
 *                         and debug pointer.                                             *
 *                         returns Success/Failure depending upon validn.                 *
 *                                                                                        *
 *                                                                                        *
 * Parameter                  Type                       Mode     Description             *
 * ------------               --------                   -----    ---------------         *
 * p_cls_code		      		char *			 				I	  		Instrument Class Code   *
 *											  																			*
 * p_deal_ord_struct_h	      DEAL_ORD_STRUCT_H *	 		I	  		Deal Structure          *
 *											  																			*
 * p_intl_env_data_struct_h_d INTL_ENV_DATA_STRUCT_H *   I        Environment String      *
 *                                                                Structure               *
 *											  																			*
 * l_debug_info_ptr           DEBUG_INFO_STRUCT_H **     I        Debug Info Structure    *
 *                                                                                        *
 * Return Values        :                                                                 *
 *                                                                                        *
 *  APL_SUCCESS  - SUCCESS                                                                *
 *  APL_FAILURE  - FAILURE                                                                *
 *                                                                                        *
 ******************************************************************************************/
int MT_Rtv_DLOrdFldVal(		char *p_cls_code,
									DEAL_ORD_STRUCT_H *p_deal_ord_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	char				chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char				chr_l_condid[APL_CONDID_LEN];
	short				int_l_condexists;
	int				int_retval;
	char				chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Country h_code is |%s| \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		if (strlen(p_cls_code) != 0)
		{
			memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
			sprintf(chr_l_buf,"Classification h_code is |%s| \n",p_cls_code);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
		}
	}
	/*	No default allow indicator	UAT Rohit	*/
	/*	
	strcpy(p_deal_ord_struct_h->h_allow_rf,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_rvp,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_df,"Y");
	strcpy(p_deal_ord_struct_h->h_allow_dvp,"Y");
	*/	
	strcpy(p_deal_ord_struct_h->h_order_class,"A");
	
	strcpy(chr_mainfuncarea, "INSTR_MAINT");
	strcpy(chr_l_condid, "ORDER_TYPE_FOR_RU");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_cls_code, "MIN") == 0)
		{
			strcpy(p_deal_ord_struct_h->h_allow_dvp,"N");
			strcpy(p_deal_ord_struct_h->h_allow_rvp,"N");
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
		}
	}
	memset(chr_mainfuncarea,NULL,APL_MAINFUNCAREA_LEN);
	memset(chr_l_condid,NULL,APL_CONDID_LEN);
	int_l_condexists = 0;

	strcpy(chr_mainfuncarea, "TRADE_MAINT");
	strcpy(chr_l_condid, "NTRD_NODLT");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
      if (strcmp(p_cls_code, "NTRD") == 0)
      {
         strcpy(p_deal_ord_struct_h->h_allow_df,"N");
			strcpy(p_deal_ord_struct_h->h_allow_dvp,"N");
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
		}
   }	
	memset(chr_mainfuncarea,NULL,APL_MAINFUNCAREA_LEN);
   memset(chr_l_condid,NULL,APL_CONDID_LEN);
   int_l_condexists = 0;

	strcpy(chr_mainfuncarea, "INSTR_MAINT");
	strcpy(chr_l_condid, "ORDER_TYPE_FOR_TR");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_cls_code, "HS") != 0)
			strcpy(p_deal_ord_struct_h->h_order_class,"N");
	}
	
	APL_GOBACK_SUCCESS	

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Rtv_DLOrdFldVal \n",NULL,NULL);
		return(APL_FAILURE);
	}
}

/*Smita - HDFCMT_003 - Added new Functions */

/*********************************************************************************************************
 *                                                                                        					*
 * Function Name         : MT_Mod_InstrRedDepDet                                          					*
 *                                                                                        					*
 * Description           : This Function Accepts Instrument Structure for Redemption 	 						*
 *                         Mapping, Env String and debug pointer.                         					*
 *                         returns Success/Failure depending upon validn.                 					*
 *                                                                                        					*
 *                                                                                        					*
 * Parameter                  			Type                       		Mode   Description        			*
 * ------------               			--------                   		-----  ---------------    			*
 * p_mt_instrument_red_dep_struct_h  	MT_INSTRUMENT_RED_DEP_STRUCT_H	I      Instrument Redemption   	*
 *									       															 Structure  	       		*	
 *											  																								*
 * p_intl_env_data_struct_h_d 			INTL_ENV_DATA_STRUCT_H *   		I      Environment String			*
 *                                                                	  		    Structure      				*
 *											  																								*
 * l_debug_info_ptr           			DEBUG_INFO_STRUCT_H **     		I      Debug Info Structure		*
 *                                                                                        					*
 * Return Values        :                                                                 					*
 *                                                                                        					*
 *  APL_SUCCESS  - SUCCESS                                                                					*
 *  APL_FAILURE  - FAILURE                                                                					*
 *                                                                                        					*
 ********************************************************************************************************/
int MT_Mod_InstrRedDepDet(		MT_INSTRUMENT_RED_DEP_STRUCT_H *p_mt_instrument_red_dep_struct_h,
										INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int                     int_retval;
	//short                   int_l_condexists;
	//char                    chr_l_sys_date[S_DATE_LENGTH];
	char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
	char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
	char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
	char                    chr_l_buf[BUFFER_LEN];
	char                    chr_chld_table_name[50];
	char							chr_l_field_val[40];
   char                    l_field_name[25]=APL_NULL_STRING;	
	
	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrRedDepDet \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));
	
	/*In any mode updation for child, master rec should be existing and undeleted*/	
	chr_iexist = 'Y';	
 	chr_ideleted ='N';
	strcpy(chr_chld_table_name,"MT_RED_DP_DET");

   char  *p_key_codes[3];
   char  *p_key_values[3];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]=APL_NULL_STRING;

	/* Mandatory Data Checks*/
	if (strlen(p_mt_instrument_red_dep_struct_h->h_instr_code) == 0)
	{
		APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	}

	if (strlen(p_mt_instrument_red_dep_struct_h->h_rd_client_id) == 0)
	{
		APL_DATA_MISSING("CLIENT ID",APL_NULL_STRING,APL_NULL_STRING)
	}

	if (strlen(p_mt_instrument_red_dep_struct_h->h_rd_dp_id) == 0)
	{
		APL_DATA_MISSING("DEPOSITORY ID",APL_NULL_STRING,APL_NULL_STRING)
	}

	if (strlen(p_mt_instrument_red_dep_struct_h->h_rd_depo_code) == 0)
	{
		APL_DATA_MISSING("DEPOSITORY CODE",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (strlen(p_mt_instrument_red_dep_struct_h->h_ipa_code) == 0)
	{
		APL_DATA_MISSING("IPA AGENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
 	{
    	if (strlen(p_mt_instrument_red_dep_struct_h->h_access_stamp) == 0)
    	{
      		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
    	}
 	}	
	/*Mandatory Data Checks Over*/

	/*Static Code Validations*/
	if (strlen(p_mt_instrument_red_dep_struct_h->h_rd_depo_code) != 0)
	{
		int_retval = CO_Chk_CodeValid (  "DEPOSITORY",
													p_mt_instrument_red_dep_struct_h->h_rd_depo_code,
													(char *)g_mt_commonsys_params_struct_h.nation_code, // AIX - Warnings removal
													l_debug_info_ptr);
	
	   if (int_retval !=APL_SUCCESS)
      {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_instrument_red_dep_struct_h->h_rd_depo_code,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
			APL_GOBACK_FAIL
      }
	}

 /* Kouser - HDFCMT_003 - HDFC New Requirement - Check Valid InstrumentType */ 
/*	for RedemptionDepository Details */

           strcpy(l_field_name,"INSTR_SUB_TYPE");     
			  g_mst_key_values[0] = p_mt_instrument_red_dep_struct_h->h_instr_code;
			  g_mst_key_values[1] = APL_NULL_STRING;

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             g_mst_key_codes,
					   	                       g_mst_key_values,
								                    g_mst_table_name,
									                 p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

           printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);
/* Commented By Abhijeet To Process INSTUMENT SUB TYPE PTC */
// if ((strcmp(p_field_ind,APL_INSTRU_SHARE) == 0) || 
//					(strcmp(p_field_ind,APL_INSTRU_MISCELLANEOUS) == 0) || 
//					(strcmp(p_field_ind,APL_INSTRU_EXS_EQUITY_CD) == 0) ||
//			      (strcmp(p_field_ind,APL_INSTRU_RIGHTS_FORM) == 0) ||
//				   (strcmp(p_field_ind,APL_INSTRU_PRIVATE_PLACED) == 0) ||
//					(strcmp(p_field_ind,APL_INSTRU_PTC) == 0) ||
//					(strcmp(p_field_ind,APL_INSTRU_PREF_SHARE) == 0))
          
           if ((strcmp(p_field_ind,APL_INSTRU_SHARE) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_MISCELLANEOUS) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_EXS_EQUITY_CD) == 0) ||
			      (strcmp(p_field_ind,APL_INSTRU_RIGHTS_FORM) == 0) ||
				   (strcmp(p_field_ind,APL_INSTRU_PRIVATE_PLACED) == 0) ||
					(strcmp(p_field_ind,APL_INSTRU_PREF_SHARE) == 0))
            {
	  		            CO_InsertErr(  l_debug_info_ptr,
  	     		                        ERR_INVALID_INSTRU_TYPE_RED_DEPODET,
		        		                  APL_NULL_STRING,
		        		                  APL_NULL_STRING,
		             		            APL_NULL_STRING,
				       		            __LINE__,
				       		            __FILE__);
                     APL_GOBACK_FAIL
            }

 /* Kouser - HDFCMT_003 - HDFC New Requirement - Check Valid InstrumentType for RedemptionDepository Details */


	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_red_dep_struct_h->h_instr_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}

   p_key_values[0]=p_mt_instrument_red_dep_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_red_dep_struct_h->h_instr_seq_num);
	p_key_values[2] = APL_NULL_STRING;

	printf("HELLO CHANGED HERE\n");

	/*Check whether Instrument Master Details Exists in UU/AA/UA/AU Status only*/

	APL_IF_DEBUG
	{
		printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
		printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
		printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
	}

	int_retval = CO_Chk_InstrValid( p_mt_instrument_red_dep_struct_h->h_instr_code,
										 		chr_iexist,
												NULL,
												chr_ideleted,
												NULL,
												NULL,
												NULL,
												l_debug_info_ptr);			

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
	{
		chr_chld_iexist = 'N';
		chr_chld_ideleted = APL_NULL_CHAR;
		chr_chld_iauthorised = APL_NULL_CHAR;
	}	
	else if(	(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
				(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)	) 
	{
		chr_chld_iexist = 'Y';
		chr_chld_ideleted = 'N';
		chr_chld_iauthorised = APL_NULL_CHAR;
	}	
	else if (	(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
					(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
	{
		chr_chld_iexist = 'Y';
		chr_chld_ideleted = NULL;
		chr_chld_iauthorised = 'N';
	}	

	APL_IF_DEBUG
	{
		printf("Master Details Exists in Proper Status ... \n");
		printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
		printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
		printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
		printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);
		
		printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
		printf("Key Codes 1 = |%s|\n",p_key_codes[1]);
		printf("Key Codes 2 = |%s|\n",p_key_codes[2]);
		
		printf("Key Value 0 = |%s|\n",p_key_values[0]);
		printf("Key Value 1 = |%s|\n",p_key_values[1]);
		printf("Key Value 2 = |%s|\n",p_key_values[2]);
	}
	
	int_retval = CO_Chk_ChldValid(		p_key_codes,
													p_key_values,
													chr_chld_iexist,
													chr_chld_iauthorised,
													chr_chld_ideleted,
													NULL,
													NULL,
													NULL,
													chr_chld_table_name,
													l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (	(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
			(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
	{
			/*Check for same maker and checker */

		int_retval = CR_Chk_ChldMkrChkr(	p_key_codes,
													p_key_values,
													chr_chld_table_name,
													p_intl_env_data_struct_h->usr,
													l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
	{
		int_retval = CR_Rtv_MastChldChrVal	( 	p_key_codes,
															p_key_values,
															chr_chld_table_name,
  			                               		"ROWID",
  			                               		chr_l_field_val,
	  		                               		l_debug_info_ptr);

  		if (int_retval != APL_SUCCESS)
  			APL_GOBACK_FAIL

  		strcpy(chr_l_row_id_instr,chr_l_field_val);

  		int_retval = CR_Rtv_MastChldChrVal	(	p_key_codes,
															p_key_values,
															chr_chld_table_name,
  	  		                               		"ACCESS_STAMP",
  	  		                               		chr_l_field_val,
  	     		                            		l_debug_info_ptr);

  		if (int_retval != APL_SUCCESS)
  			APL_GOBACK_FAIL

		APL_IF_DEBUG
		{
			printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
			printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_red_dep_struct_h->h_access_stamp);
		}

  		if (strcmp(chr_l_field_val,p_mt_instrument_red_dep_struct_h->h_access_stamp) != 0)
  		{
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
  		}
	}

	int_retval = CR_Chk_InstrRedDep(	p_mt_instrument_red_dep_struct_h,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrRedDep(	p_mt_instrument_red_dep_struct_h,
												chr_l_row_id_instr,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
        	CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrRedDepDet SUCCESS\n",NULL,NULL);
     		return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
        	CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrRedDepDet FAILURE\n",NULL,NULL);
     		return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrExch		                                                         *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for Exchange	                     *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_exch_struct_h    	MT_INSTRUMENT_EXCH_STRUCT_H   	I      Instrument Exchange	 	   *
 *                                                                             Structure                 *
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrExch(		MT_INSTRUMENT_EXCH_STRUCT_H *p_mt_instrument_exch_struct_h,
									INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char	                  chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
	/* char							l_field_name[25]=APL_NULL_STRING; */ /* Defined twice - change by yogesh 0n 23-02-06  */
	char                    chr_l_field_val[40];
        char                    l_field_name[25]=APL_NULL_STRING;

   APL_IF_DEBUG
     	CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrExch \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));
     
   /*In any mode updation for child, master rec should be existing and undeleted*/ 
	chr_iexist = 'Y';
	chr_ideleted = 'N';
   strcpy(chr_chld_table_name,"MT_INSTR_EXCH_DET");

   char  *p_key_codes[4];
   char  *p_key_values[4];
   char  chr_l_mkt_type[12]=APL_NULL_STRING;
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]="EXCH_CODE";
   p_key_codes[3]=APL_NULL_STRING;

   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_exch_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_exch_struct_h->h_exch_code) == 0)
   {
      APL_DATA_MISSING("EXCHANGE CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_exch_struct_h->h_scrip_grp) == 0)
   {
      APL_DATA_MISSING("SCRIP GROUP",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_exch_struct_h->h_mkt_type) == 0)
   {
      APL_DATA_MISSING("MARKET TYPE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_exch_struct_h->h_exch_instr_code) == 0)
   {
      APL_DATA_MISSING("EXCHANGE INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   /*Check whether Instrument Master Details Exists in UU/AA/UA/AU Status only*/
   APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }

   int_retval = CO_Chk_InstrValid( 	p_mt_instrument_exch_struct_h->h_instr_code,
                           		   chr_iexist,
                             		   NULL,
                                 	chr_ideleted,
                                 	NULL,
                                 	NULL,
                                 	NULL,
                                 	l_debug_info_ptr);
   if (int_retval !=APL_SUCCESS)
      APL_GOBACK_FAIL

	APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_exch_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }
   
	/**Check for Listing Status as Mandatory if Listed Flag in Master Table is Y**/
	/** This Check is not Required at all - Smita - HDFCMT_003 - After Client Discussion **/
	
	strcpy(l_field_name,"LISTED_IND");
	g_mst_key_values[0] = p_mt_instrument_exch_struct_h->h_instr_code;
	g_mst_key_values[1] = APL_NULL_STRING;

	int_retval = CR_Chk_MasterField(	p_field_ind,	
												l_field_name,
												g_mst_key_codes,
												g_mst_key_values,
												g_mst_table_name,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	/*if (strcmp(p_field_ind,"Y") == 0)
	{
		if (strlen(p_mt_instrument_exch_struct_h->h_listing_status) == 0)
		{
			APL_DATA_MISSING("LISTING STATUS",APL_NULL_STRING,APL_NULL_STRING)
		}
		else
		{
			int_retval = CO_Chk_CodeValid	(	"LISTED_STATUS",
														p_mt_instrument_exch_struct_h->h_listing_status,
														APL_DEF_COUNTRY_CODE,
														l_debug_info_ptr);

			if (int_retval !=APL_SUCCESS)
			{
				CO_InsertErr(  l_debug_info_ptr,
									ERR_INVALID_CODE,
									p_mt_instrument_exch_struct_h->h_listing_status,
									APL_NULL_STRING,
									APL_NULL_STRING,
										__LINE__,
									 __FILE__);
				APL_GOBACK_FAIL
			}
		}
	}
	else
	{
		if (	(strlen(p_mt_instrument_exch_struct_h->h_listing_status) != 0) ||
				(strlen(p_mt_instrument_exch_struct_h->h_listing_date)   != 0) )
		{
     		CO_InsertErr(  l_debug_info_ptr,
        		            ERR_LIST_DET_NOT_ALLOW,
           		         APL_NULL_STRING,
              		      APL_NULL_STRING,
                 		   APL_NULL_STRING,
                    		__LINE__,
                    		__FILE__);
     		APL_GOBACK_FAIL
		}	
	}*/
	/* - Change Commented since the check for Listed Ind not Required - Smita - HDFCMT_003 */

	/*Check only Listed Status in Static Table - Smita - HDFCMT_003 */

	if (strlen(p_mt_instrument_exch_struct_h->h_listing_status) !=0)
	{
		int_retval = CO_Chk_CodeValid (  "LISTED_STATUS",
	  		                               p_mt_instrument_exch_struct_h->h_listing_status,
	  	  		                            APL_DEF_COUNTRY_CODE,
	        		                         l_debug_info_ptr);
	   
		if (int_retval !=APL_SUCCESS)
		{
	  		CO_InsertErr(  l_debug_info_ptr,
  	     		            ERR_INVALID_CODE,
	        		         p_mt_instrument_exch_struct_h->h_listing_status,
		        		      APL_NULL_STRING,
		             		APL_NULL_STRING,
				       		__LINE__,
				       		__FILE__);
	 		APL_GOBACK_FAIL
		}
	}
		
 /* Kouser - HDFCMT_003 - HDFC New Requirement */
 /* Check Valid Instrument Type Exchange Details */

           strcpy(l_field_name,"INSTR_SUB_TYPE");     

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             g_mst_key_codes,
					   	                       g_mst_key_values,
								                    g_mst_table_name,
									                 p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

           printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);

			   /*Abhijeet (01/05/2006) as For Instrument Type "Warrant" This validation is not required */
			  /*
           if ((strcmp(p_field_ind,APL_INSTRU_SUB_WARRANTS) == 0) || 
				*/
		  	  
		  		if ((strcmp(p_field_ind,APL_INSTRU_FIXED_DEPO_RCP) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_SAVINGS_CERT) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_PRIVATE_PLACED) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_PROMISSORY_NOTE) == 0))
           {

	  		        CO_InsertErr(  l_debug_info_ptr,
        	      		           ERR_INVALID_INSTRU_TYPE_EXCHDET,
		        		              APL_NULL_STRING,
		        		              APL_NULL_STRING,
		             		        APL_NULL_STRING,
				       		        __LINE__,
				       		        __FILE__);
                 APL_GOBACK_FAIL
           }
	
/* Kouser - HDFCMT_003 - HDFC New Requirement - Instrument Type Check for Exchage Details */

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
 	{
    	if (strlen(p_mt_instrument_exch_struct_h->h_access_stamp) == 0)
    	{
      	APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
    	}

      if (p_mt_instrument_exch_struct_h->h_instr_seq_num == 0)
      {
      	APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
      }
 	}
   /*Mandatory Data Checks Over*/

	/*Static Code Validations*/
	if (strlen(p_mt_instrument_exch_struct_h->h_exch_code) != 0)
	{
		int_retval = CO_Chk_CodeValid (  "EXCHANGE",
													p_mt_instrument_exch_struct_h->h_exch_code,
													(char *)g_mt_commonsys_params_struct_h.nation_code, // AIX - Warnings removal
													l_debug_info_ptr);
		if (int_retval !=APL_SUCCESS)
		{
			CO_InsertErr(  l_debug_info_ptr,
			               ERR_INVALID_CODE,
                        p_mt_instrument_exch_struct_h->h_exch_code,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
			APL_GOBACK_FAIL
      }
	}

        memset(chr_l_mkt_type,APL_NULL_CHAR,12);
        strcpy(chr_l_mkt_type,"MKT_TYP_");
        strcat(chr_l_mkt_type,p_mt_instrument_exch_struct_h -> h_exch_code);
        strcat(chr_l_mkt_type,APL_NULL_STRING);    	
	if (strlen(p_mt_instrument_exch_struct_h->h_mkt_type) != 0)
	{
		int_retval = CO_Chk_CodeValid ( chr_l_mkt_type,
													p_mt_instrument_exch_struct_h->h_mkt_type,
													(char *)g_mt_commonsys_params_struct_h.nation_code, // AIX - Warnings removal
													l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
      {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_instrument_exch_struct_h->h_mkt_type,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
			APL_GOBACK_FAIL
      }
	}

	if (strlen(p_mt_instrument_exch_struct_h->h_scrip_grp) !=0)
	{
		int_retval = CO_Chk_CodeValid (  "SCRIP_GRP",
													p_mt_instrument_exch_struct_h->h_scrip_grp,
													(char *)g_mt_commonsys_params_struct_h.nation_code, // AIX - Warnings removal
													l_debug_info_ptr);
		
		if (int_retval !=APL_SUCCESS)
		{
			CO_InsertErr(  l_debug_info_ptr,
								ERR_INVALID_CODE,
								p_mt_instrument_exch_struct_h->h_scrip_grp,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
			APL_GOBACK_FAIL
		}
	}

   p_key_values[0]=p_mt_instrument_exch_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_exch_struct_h->h_instr_seq_num);
   p_key_values[2]=p_mt_instrument_exch_struct_h->h_exch_code;
   p_key_values[3]=APL_NULL_STRING;

   if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

   APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);
      printf("Key Codes 2 = |%s|\n",p_key_codes[2]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
      printf("Key Value 2 = |%s|\n",p_key_values[2]);
   }
      
	int_retval = CO_Chk_ChldValid( 		p_key_codes,
  		                              	p_key_values,
     		                           	chr_chld_iexist,
        		                        	chr_chld_iauthorised,
           		                     	chr_chld_ideleted,
              		                  	NULL,
                		               	NULL,
                    		            	NULL,
                      		         	chr_chld_table_name,
                         		      	l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
	{
   	int_retval = CR_Rtv_MastChldChrVal(	p_key_codes,
     	                                    p_key_values,
                                         	chr_chld_table_name,
                                         	"ROWID",
                                         	chr_l_field_val,
                                         	l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
  			APL_GOBACK_FAIL

  		strcpy(chr_l_row_id_instr,chr_l_field_val);

  		int_retval = CR_Rtv_MastChldChrVal	(	p_key_codes,
     		                                    p_key_values,
        		                                 chr_chld_table_name,
           		                              "ACCESS_STAMP",
              		                           chr_l_field_val,
                 		                        l_debug_info_ptr);

  		if (int_retval != APL_SUCCESS)
  			APL_GOBACK_FAIL
         
		APL_IF_DEBUG
  		{
       	printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_exch_struct_h->h_access_stamp);
  		}

  		if (strcmp(chr_l_field_val,p_mt_instrument_exch_struct_h->h_access_stamp) != 0)
  		{
        		CO_InsertErr(  l_debug_info_ptr,
                       		ERR_ACCESSSTAMP_CHGD,
                       		APL_NULL_STRING,
                       		APL_NULL_STRING,
                       		APL_NULL_STRING,
                       		__LINE__,
                       		__FILE__);
        		APL_GOBACK_FAIL
		}
	}

	int_retval = CR_Chk_InstrExch(	p_mt_instrument_exch_struct_h,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
   	   APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrExch(	p_mt_instrument_exch_struct_h,
												chr_l_row_id_instr,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
   	   APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrExch with Success \n",NULL,NULL);
         return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrExch with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrCrd	                                                            *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for Credit Rating Agency           *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_cr_agency_struct_h  MT_INSTRUMENT_CR_AGENCY_STRUCT_H I      Instrument Credit Rating  *
 *                                                                             Agency Structure          *
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrCrd(		MT_INSTRUMENT_CR_AGENCY_STRUCT_H *p_mt_instrument_cr_agency_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
   int                     int_l_diff; 
  	char                    chr_l_field_val[40];
   char                    l_field_name[25]=APL_NULL_STRING;
   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrCrd \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	/*In any mode updation for child, master rec should be existing and undeleted*/
   chr_iexist = 'Y';
	chr_ideleted ='N';
   strcpy(chr_chld_table_name,"MT_INSTR_RATING_DET");

   char  *p_key_codes[4];
   char  *p_key_values[4];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]="CR_AGENCY_CODE";
   p_key_codes[3]=APL_NULL_STRING;

   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_cr_agency_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_cr_agency_struct_h->h_cr_agency_code) == 0)
   {
      APL_DATA_MISSING("CREDIT RATING AGENCY CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_cr_agency_struct_h->h_rating_code) == 0)
   {
      APL_DATA_MISSING("RATING CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

	if (	(strcmp(p_mt_instrument_cr_agency_struct_h->h_effdt_fr,APL_NULL_STRING) !=0) &&
			(strcmp(p_mt_instrument_cr_agency_struct_h->h_effdt_to,APL_NULL_STRING) !=0) )		
   {
      if (CO_Pro_DateComp( p_mt_instrument_cr_agency_struct_h->h_effdt_fr,
                           p_mt_instrument_cr_agency_struct_h->h_effdt_to,
     	                     &int_l_diff,
                          	l_debug_info_ptr) != APL_SUCCESS)
          APL_GOBACK_FAIL

      if (int_l_diff <= 0)
      {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_FRDATE_CANT_GRT_TODATE,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                       __FILE__);
      }
   }

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
    	if (strlen(p_mt_instrument_cr_agency_struct_h->h_access_stamp) == 0)
    	{
     		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
    	}

     	if (p_mt_instrument_cr_agency_struct_h->h_instr_seq_num == 0)
     	{
     		APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
     	}
   }
   /*Mandatory Data Checks Over*/

	
  /* Kouser - HDFCMT_003 - HDFC New Requirement  */
  /* Check Valid Instrument Type  for Credit Rating Details */

  g_mst_key_values[0]=p_mt_instrument_cr_agency_struct_h->h_instr_code;
  g_mst_key_values[1]=APL_NULL_STRING;
  strcpy(l_field_name,"INSTR_SUB_TYPE");     

        int_retval = CR_Chk_MasterField( p_field_ind,
		                                   l_field_name,
		                                   g_mst_key_codes,
			      	                       g_mst_key_values,
					                          g_mst_table_name,
						   						  p_intl_env_data_struct_h,
						   	                 l_debug_info_ptr);

       printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);

       if (strcmp(p_field_ind,APL_INSTRU_SUB_WARRANTS) == 0)
       {
	  		CO_InsertErr(  l_debug_info_ptr,
  	     		            ERR_INVALID_INSTRU_TYPE_CR_RATINGDET,
		        		      APL_NULL_STRING,
		        		      APL_NULL_STRING,
		             		APL_NULL_STRING,
				       		__LINE__,
				       		__FILE__);
         APL_GOBACK_FAIL
       }

 /* Kouser - HDFCMT_003 - HDFC New Requirement */
 /* Check Valid Instrument Type for Credit Rating Details */

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_cr_agency_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }
	
   p_key_values[0]=p_mt_instrument_cr_agency_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_cr_agency_struct_h->h_instr_seq_num);
   p_key_values[2]=p_mt_instrument_cr_agency_struct_h->h_cr_agency_code;
   p_key_values[3]=APL_NULL_STRING;

	APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }
   int_retval = CO_Chk_InstrValid(p_mt_instrument_cr_agency_struct_h->h_instr_code,
                            	    chr_iexist,
                             	    NULL,
                             	    chr_ideleted,
                             	    NULL,
                             	    NULL,
                             	    NULL,
                             	    l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL
   
	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

   APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);
      printf("Key Codes 2 = |%s|\n",p_key_codes[2]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
      printf("Key Value 2 = |%s|\n",p_key_values[2]);
   }

   int_retval = CO_Chk_ChldValid( 		p_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
      strcpy(chr_l_row_id_instr,chr_l_field_val);

      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ACCESS_STAMP",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      APL_IF_DEBUG
      {
         printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_cr_agency_struct_h->h_access_stamp);
      }

      if (strcmp(chr_l_field_val,p_mt_instrument_cr_agency_struct_h->h_access_stamp) != 0)
      {
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
      }
   }

	int_retval = CR_Chk_InstrCrd(	p_mt_instrument_cr_agency_struct_h,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
  	    APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrCrd(	p_mt_instrument_cr_agency_struct_h,
											chr_l_row_id_instr,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
   	   APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrCrd with Success \n",NULL,NULL);
         return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrCrd with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrPC                                                                *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for Put Call Details	            *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_pc_struct_h  			MT_INSTRUMENT_PC_STRUCT_H 			I      Instrument Put Call			*
 *                                                                             Details Structure         *
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrPC(		MT_INSTRUMENT_PC_STRUCT_H *p_mt_instrument_pc_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
 	char						  	l_field_name[25] = APL_NULL_STRING;	
	char                    chr_l_field_val[40];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrPC \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

   /*In any mode updation for child, master rec should be existing and undeleted*/ 
	chr_iexist = 'Y';
	chr_ideleted ='N';
   strcpy(chr_chld_table_name,"MT_PC_DET");

   char  *p_key_codes[3];
   char  *p_key_values[3];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]=APL_NULL_STRING;

   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_pc_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_pc_struct_h->h_pc_flag) == 0)
   {
      APL_DATA_MISSING("PUT/CALL FLAG",APL_NULL_STRING,APL_NULL_STRING)
   }
	
	/*	Daily Cut off condition for Daily PC	UAT Rohit	*/
	if (strcmp(p_mt_instrument_pc_struct_h->h_pc_flag,APL_PC_DAILY) == 0)
	{
		if(strlen(p_mt_instrument_pc_struct_h->h_instr_pc_cutofftime) == 0)
		{
			APL_DATA_MISSING("DAILY CUT OFF TIME",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	else
	{	
		if(strlen(p_mt_instrument_pc_struct_h->h_instr_pc_cutofftime) == 0)
		{
			APL_DATA_MISSING("DAILY CUT OFF TIME",APL_NULL_STRING,APL_NULL_STRING)
		}
		/*	Replace Daily Effective Date for PC flag as not daily for UAT Rohit*/
		if(strlen(p_mt_instrument_pc_struct_h->h_instr_pc_effdt) == 0)
		{
			APL_DATA_MISSING("DAILY EFFECTIVE DATE",APL_NULL_STRING,APL_NULL_STRING)
		}
   	if (strlen(p_mt_instrument_pc_struct_h->h_pc_date) == 0)
   	{
   		APL_DATA_MISSING("PUT/CALL DATE",APL_NULL_STRING,APL_NULL_STRING)
   	}
	}

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      if (strlen(p_mt_instrument_pc_struct_h->h_access_stamp) == 0)
      {
      	APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
      }

      if (p_mt_instrument_pc_struct_h->h_instr_seq_num == 0)
      {
      	APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
      }
   }
   /*Mandatory Data Checks Over*/


 /* Kouser - HDFCMT_003 - HDFC New Requirement */
 /* Check Valid Instrument Type for PutCall Details */
/*
  g_mst_key_values[0]=p_mt_instrument_pc_struct_h->h_instr_code;
  g_mst_key_values[1]=APL_NULL_STRING;
  strcpy(l_field_name,"INSTR_SUB_TYPE");     

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             g_mst_key_codes,
					   	                       g_mst_key_values,
								                    g_mst_table_name,
														  p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

        printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);
*/
		  /*	Addition of Debentures,PTC,BD at UAT	Rohit*/
	/*
    if ((strcmp(p_field_ind,APL_INSTRU_BOND_VALUE_BASED) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_GOVT_BOND) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_GOVT_PAPERS) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_BOND_QNTY_BASED) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_SGL_VALUE_BONDS) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_DEBENTURES) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_PTC) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_BOND_VALUE_BASED) != 0) ||
        (strcmp(p_field_ind,APL_INSTRU_GOVT_SEC) != 0))
        {
	  		CO_InsertErr(  l_debug_info_ptr,
  	     		            ERR_INVALID_INSTRU_TYPE_PCDET,
		        		      APL_NULL_STRING,
		        		      APL_NULL_STRING,
		             		APL_NULL_STRING,
				       		__LINE__,
				       		__FILE__);
         APL_GOBACK_FAIL
        }
	*/
 /* Kouser - HDFCMT_003 - HDFC New Requirement - Check Valid InstrumentType Check PutCall Details */

   p_key_values[0]=p_mt_instrument_pc_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_pc_struct_h->h_instr_seq_num);
   p_key_values[2]=APL_NULL_STRING;
	g_mst_key_values[0]=p_mt_instrument_pc_struct_h->h_instr_code;
	g_mst_key_values[1]=APL_NULL_STRING;

	APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_pc_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
      
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Put Call Indicator  is |%s| \n",p_mt_instrument_pc_struct_h->h_pc_flag);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }

   APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }

	if (strlen(p_mt_instrument_pc_struct_h->h_pc_flag) != 0)
	{
		int_retval = CO_Chk_CodeValid (  	"PUT_CALL_DLY",
	  	     		                           p_mt_instrument_pc_struct_h->h_pc_flag,
	  	  		                              (char *)g_mt_commonsys_params_struct_h.nation_code,
	  		                                	l_debug_info_ptr); // AIX - Warnings

		if (int_retval !=APL_SUCCESS)
		{
	    CO_InsertErr(  l_debug_info_ptr,
	                   ERR_INVALID_CODE,
	                   p_mt_instrument_pc_struct_h->h_pc_flag,
	                   APL_NULL_STRING,
	                   APL_NULL_STRING,
	                   __LINE__,
	                   __FILE__);
	    APL_GOBACK_FAIL
		}
	}

   int_retval = CO_Chk_InstrValid( 	p_mt_instrument_pc_struct_h->h_instr_code,
                                 	chr_iexist,
                                 	NULL,
                                 	chr_ideleted,
                                 	NULL,
                                 	NULL,
                                 	NULL,
                                 	l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(l_field_name,"INSTR_PC_IND");

	int_retval = CR_Chk_MasterField( p_field_ind,
												l_field_name,
												g_mst_key_codes,
												g_mst_key_values,
												g_mst_table_name,
  		                              p_intl_env_data_struct_h,
     		                           l_debug_info_ptr);

	/*if (	(strcmp(p_field_ind,"N") == 0) 	||
			(strcmp(p_field_ind,APL_PC_DAILY) == 0) 	) */
	if (strcmp(p_field_ind,"N") == 0)
	{
  	   CO_InsertErr(  l_debug_info_ptr,
                     ERR_PC_DET_NOT_ALLOW,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     __LINE__,
                     __FILE__);
      APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

 	APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
   }

	int_retval = CO_Chk_ChldValid( 		p_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
      strcpy(chr_l_row_id_instr,chr_l_field_val);

      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ACCESS_STAMP",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      APL_IF_DEBUG
      {
         printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_pc_struct_h->h_access_stamp);
      }

      if (strcmp(chr_l_field_val,p_mt_instrument_pc_struct_h->h_access_stamp) != 0)
      {
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
      }
   }


	int_retval = CR_Chk_InstrPC(	p_mt_instrument_pc_struct_h,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrPC(	p_mt_instrument_pc_struct_h,
											chr_l_row_id_instr,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPC with Success \n",NULL,NULL);
         return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPC with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrPartRed                                                           *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for Partial Redemption Details     *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_part_red_struct_h  	MT_INSTRUMENT_PART_RED_STRUCT_H 	I      Instrument Partial Redemp *
 *                                                                             Details Structure         *
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrPartRed(		MT_INSTRUMENT_PART_RED_STRUCT_H *p_mt_instrument_part_red_struct_h,
										INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
										DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
   char						  	l_field_name[25] = APL_NULL_STRING;
	char                    chr_l_field_val[40];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrPartRed \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	/*In any mode updation for child, master rec should be existing and undeleted*/	
	chr_iexist = 'Y';
	chr_ideleted ='N';
  	strcpy(chr_chld_table_name,"MT_RED_DET");

   char  *p_key_codes[3];
	char  *p_key_values[3];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]=APL_NULL_STRING;


   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_part_red_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_part_red_struct_h->h_red_dt) == 0)
   {
      APL_DATA_MISSING("REDEMPTION DATE",APL_NULL_STRING,APL_NULL_STRING)
   }

	if (p_mt_instrument_part_red_struct_h->h_red_pct !=0)
   {
		if (p_mt_instrument_part_red_struct_h->h_red_pct > 100)
		{
			CO_InsertErr (	l_debug_info_ptr,
								ERR_RED_PCT_CANT_GRT_HUN,
								APL_NULL_STRING,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
			APL_GOBACK_FAIL
		}
	}
   if (p_mt_instrument_part_red_struct_h->h_red_value == 0)
   {
      APL_DATA_MISSING("REDEMPTION VALUE",APL_NULL_STRING,APL_NULL_STRING)
   }
	else
	{
		printf("Red Value = ||%lf||\n",p_mt_instrument_part_red_struct_h->h_red_value);
		printf("InstrCode = ||%s||\n",p_mt_instrument_part_red_struct_h->h_instr_code);

		int_retval = CR_ChkInstrNomVal(	p_mt_instrument_part_red_struct_h->h_red_value,
													p_mt_instrument_part_red_struct_h->h_instr_code,
													p_intl_env_data_struct_h,
													l_debug_info_ptr);
			
		if(int_retval !=APL_SUCCESS)
		{
			CO_InsertErr ( l_debug_info_ptr,
								ERR_RED_VAL_GRT_NOM_VAL,
								APL_NULL_STRING,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__);
			APL_GOBACK_FAIL
		}
	}	

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      if (strlen(p_mt_instrument_part_red_struct_h->h_access_stamp) == 0)
      {
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
      }

      if (p_mt_instrument_part_red_struct_h->h_instr_seq_num == 0)
      {
         APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
      }
   }
   /*Mandatory Data Checks Over*/


 /* Kouser - HDFCMT_003 - HDFC New Requirement */
 /* Check Valid Instrument Type For Redemption Details */

  g_mst_key_values[0]=p_mt_instrument_part_red_struct_h->h_instr_code;
  g_mst_key_values[1]=APL_NULL_STRING;


           strcpy(l_field_name,"INSTR_SUB_TYPE");     

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             g_mst_key_codes,
					   	                       g_mst_key_values,
								                    g_mst_table_name,
														  p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

        printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);

           if ((strcmp(p_field_ind,APL_INSTRU_SHARE) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_MISCELLANEOUS) == 0) || 
					(strcmp(p_field_ind,APL_INSTRU_EXS_EQUITY_CD) == 0) ||
				   (strcmp(p_field_ind,APL_INSTRU_RIGHTS_FORM) == 0) ||
			    	(strcmp(p_field_ind,APL_INSTRU_PRIVATE_PLACED) == 0) ||
					(strcmp(p_field_ind,APL_INSTRU_PREF_SHARE) == 0) ||
					(strcmp(p_field_ind,APL_INSTRU_PTC) == 0))
           {

	  		       CO_InsertErr(  l_debug_info_ptr,
  	     		                   ERR_INVALID_INSTRU_TYPE_REDEMDET,
		        		             APL_NULL_STRING,
		        		             APL_NULL_STRING,
		                   	 	 APL_NULL_STRING,
				       		       __LINE__,
				       		       __FILE__);
                APL_GOBACK_FAIL
          }

 /* Kouser - HDFCMT_003 - HDFC New Requirement  */ 
 /* Check Valid Instrument Type for Redemption Details */

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_part_red_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }

   p_key_values[0]=p_mt_instrument_part_red_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_part_red_struct_h->h_instr_seq_num);
   p_key_values[2]=APL_NULL_STRING;
   g_mst_key_values[0]=p_mt_instrument_part_red_struct_h->h_instr_code;
   g_mst_key_values[1]=APL_NULL_STRING;

   APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }

   int_retval = CO_Chk_InstrValid( 	p_mt_instrument_part_red_struct_h->h_instr_code,
                            	     	chr_iexist,
                             	    	NULL,
                             	    	chr_ideleted,
                                 	NULL,
                                		NULL,
                                 	NULL,
                                 	l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(l_field_name,"INSTR_PART_RD_FLG");

	int_retval = CR_Chk_MasterField( p_field_ind,
												l_field_name,
												g_mst_key_codes,
												g_mst_key_values,
												g_mst_table_name,	
     	  		                        p_intl_env_data_struct_h,
     		                           l_debug_info_ptr);

	if (strcmp(p_field_ind,"N") == 0)
	{
      CO_InsertErr(  l_debug_info_ptr,
                     ERR_PART_RED_DET_NOT_ALLOW,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     __LINE__,
                     __FILE__);
      APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

   APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
   }

	int_retval = CO_Chk_ChldValid( 		p_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
      strcpy(chr_l_row_id_instr,chr_l_field_val);

      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ACCESS_STAMP",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      APL_IF_DEBUG
      {
         printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_part_red_struct_h->h_access_stamp);
      }

      if (strcmp(chr_l_field_val,p_mt_instrument_part_red_struct_h->h_access_stamp) != 0)
      {
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
      }
   }

	int_retval = CR_Chk_InstrPartRed(	p_mt_instrument_part_red_struct_h,
													p_intl_env_data_struct_h,
													l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrPartRed(	p_mt_instrument_part_red_struct_h,
													chr_l_row_id_instr,
													p_intl_env_data_struct_h,
													l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
	      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPartRed with Success \n",NULL,NULL);
  	      return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPartRed with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrPTC                                                               *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for PTC Details 			            *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_ptc_struct_h  		MT_INSTRUMENT_PTC_STRUCT_H 		I      Instrument PTC Details    *
 *                                                                             Structure          			*
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrPTC(		MT_INSTRUMENT_PTC_STRUCT_H *p_mt_instrument_ptc_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
   char						  	l_field_name[25]=APL_NULL_STRING;
	char                    chr_l_field_val[40];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrPTC \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	/*In any mode updation for child, master rec should be existing and undeleted*/
   chr_iexist = 'Y';
	chr_ideleted ='N';
   strcpy(chr_chld_table_name,"MT_PTC_DET");

   char  *p_key_codes[3];
   char  *p_key_values[3];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]=APL_NULL_STRING;

   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_ptc_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_ptc_struct_h->h_ptc_dt) == 0)
   {
      APL_DATA_MISSING("PTC DATE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (p_mt_instrument_ptc_struct_h->h_ptc_value == 0)
   {
      APL_DATA_MISSING("PTC VALUE",APL_NULL_STRING,APL_NULL_STRING)
   }
	else
	{
		if (	(p_mt_instrument_ptc_struct_h->h_ptc_prin_amt !=0) &&
				(p_mt_instrument_ptc_struct_h->h_ptc_int_amt  !=0) )
		{
				int_retval = CR_ChkPTCVal(	p_mt_instrument_ptc_struct_h->h_ptc_value,
													p_mt_instrument_ptc_struct_h->h_ptc_prin_amt,
													p_mt_instrument_ptc_struct_h->h_ptc_int_amt,
													p_intl_env_data_struct_h,
													l_debug_info_ptr);
			
				if (int_retval!=APL_SUCCESS)
				{
					CO_InsertErr(	l_debug_info_ptr,
										ERR_PTC_PRIN_INT_VALUE,
										APL_NULL_STRING,
										APL_NULL_STRING,
										APL_NULL_STRING,
										__LINE__,
										__FILE__);
				
					APL_GOBACK_FAIL
				}
		}
		APL_IF_DEBUG
		{
			printf("PTC Value = |%lf|\n",p_mt_instrument_ptc_struct_h->h_ptc_value);
		}

		/*Addition of Auhthorise cond and new parameter for CR_ChkPTCValNomVal UAT	Rohit	*/
   	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE) != 0)
		{

			int_retval = CR_ChkPTCValNomVal(	p_mt_instrument_ptc_struct_h->h_instr_code,
											p_mt_instrument_ptc_struct_h->h_ptc_value,
											p_mt_instrument_ptc_struct_h->h_ptc_prin_amt,/*ISKB-242 PTC Prin. Amt & Nominal Val comarision - Rahul 22-Aug-2007 */								
											p_mt_instrument_ptc_struct_h->h_instr_seq_num,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);
			
		if (int_retval!=APL_SUCCESS)
		{
		 /* Change:Check Principle Amt < Nom Val :06/11/2006 */
		 IF_COND_EXISTS("MT_PTC","PTC_PRINC>NOMINAL")
		 {
			 CO_InsertErr(	l_debug_info_ptr,
							ERR_PTC_PRINC_MORE_THAN_NOMVAL,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
				
			APL_GOBACK_FAIL
		 }
		 else
		 {
			CO_InsertErr(	l_debug_info_ptr,
							ERR_INSTR_PTC_MORE_THAN_NOMVAL,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__);
				
			APL_GOBACK_FAIL
		 }
		}
		}
	}	

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
    	if (strlen(p_mt_instrument_ptc_struct_h->h_access_stamp) == 0)
      {
      	APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
      }

      if (p_mt_instrument_ptc_struct_h->h_instr_seq_num == 0)
      {
         APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
      }
  	}
   /*Mandatory Data Checks Over*/

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_ptc_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }

   p_key_values[0]=p_mt_instrument_ptc_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_ptc_struct_h->h_instr_seq_num);
   p_key_values[2]=APL_NULL_STRING;
   g_mst_key_values[0]=p_mt_instrument_ptc_struct_h->h_instr_code;
   g_mst_key_values[1]=APL_NULL_STRING;

   APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }

   int_retval = CO_Chk_InstrValid( p_mt_instrument_ptc_struct_h->h_instr_code,
                                 chr_iexist,
                                 NULL,
                                 chr_ideleted,
                                 NULL,
                                 NULL,
                                 NULL,
                                 l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(l_field_name,"INSTR_SUB_TYPE");

	int_retval = CR_Chk_MasterField( p_field_ind,
												l_field_name,
												g_mst_key_codes,
												g_mst_key_values,
												g_mst_table_name,
                                    p_intl_env_data_struct_h,
                                    l_debug_info_ptr);

	if (strcmp(p_field_ind,APL_INSTRU_PTC) != 0)
	{
      CO_InsertErr(  l_debug_info_ptr,
                     ERR_PTC_DET_NOT_ALLOW,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     __LINE__,
                     __FILE__);
      APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

   APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);
      printf("Key Codes 2 = |%s|\n",p_key_codes[2]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
      printf("Key Value 2 = |%s|\n",p_key_values[2]);
   }

   int_retval = CO_Chk_ChldValid( 		p_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
      strcpy(chr_l_row_id_instr,chr_l_field_val);

      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ACCESS_STAMP",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      APL_IF_DEBUG
      {
         printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_ptc_struct_h->h_access_stamp);
      }

      if (strcmp(chr_l_field_val,p_mt_instrument_ptc_struct_h->h_access_stamp) != 0)
      {
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
      }
   }

	int_retval = CR_Chk_InstrPTC(	p_mt_instrument_ptc_struct_h,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
  	    APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrPTC(	p_mt_instrument_ptc_struct_h,
											chr_l_row_id_instr,
											p_intl_env_data_struct_h,
											l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPTC with Success \n",NULL,NULL);
         return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrPTC with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}

/*********************************************************************************************************
 *                                                                                                       *
 * Function Name         : MT_Mod_InstrReset                                                             *
 *                                                                                                       *
 * Description           : This Function Accepts Instrument Structure for Reset Details 		            *
 *                         Mapping, Env String and debug pointer.                                        *
 *                         returns Success/Failure depending upon validn.                                *
 *                                                                                                       *
 *                                                                                                       *
 * Parameter                           Type                             Mode   Description               *
 * ------------                        --------                         -----  ---------------           *
 * p_mt_instrument_reset_struct_h  		MT_INSTRUMENT_RESET_STRUCT_H 		I      Instrument Reset Details  *
 *                                                                             Structure          			*
 *                                                                                                       *
 * p_intl_env_data_struct_h_d          INTL_ENV_DATA_STRUCT_H *         I      Environment String        *
 *                                                                             Structure                 *
 *                                                                                                       *
 * l_debug_info_ptr                    DEBUG_INFO_STRUCT_H **           I      Debug Info Structure      *
 *                                                                                                       *
 * Return Values        :                                                                                *
 *                                                                                                       *
 *  APL_SUCCESS  - SUCCESS                                                                               *
 *  APL_FAILURE  - FAILURE                                                                               *
 *                                                                                                       *
 ********************************************************************************************************/
int MT_Mod_InstrReset(		MT_INSTRUMENT_RESET_STRUCT_H *p_mt_instrument_reset_struct_h,
									INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int                     int_retval;
   //short                   int_l_condexists;
   //char                    chr_l_sys_date[S_DATE_LENGTH];
   char                    chr_iexist,chr_ideleted; //,chr_ifrozen,chr_iauthorised;
   char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_iauthorised;
   char                    chr_l_row_id_instr[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];
   char                    chr_chld_table_name[50];
   char						  	l_field_name[25]=APL_NULL_STRING;
  	char                    chr_l_field_val[40];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered Process MT_Mod_InstrReset \n",NULL,p_intl_env_data_struct_h);

   memset(chr_l_row_id_instr,APL_NULL_CHAR,sizeof(chr_l_row_id_instr));

	/*In any mode updation for child, master rec should be existing and undeleted*/
   chr_iexist = 'Y';
	chr_ideleted ='N';
   strcpy(chr_chld_table_name,"MT_RESET_DET");

	char  *p_key_codes[3];
   char  *p_key_values[3];
   p_key_codes[0]="INSTR_CODE";
   p_key_codes[1]="INSTR_SEQ_NUM";
   p_key_codes[2]=APL_NULL_STRING;

   /*Mandatory Data Checks*/
   if (strlen(p_mt_instrument_reset_struct_h->h_instr_code) == 0)
   {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strlen(p_mt_instrument_reset_struct_h->h_reset_dt) == 0)
   {
      APL_DATA_MISSING("RESET DATE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (p_mt_instrument_reset_struct_h->h_reset_rate == 0)
   {
      APL_DATA_MISSING("RESET RATE",APL_NULL_STRING,APL_NULL_STRING)
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      if (strlen(p_mt_instrument_reset_struct_h->h_access_stamp) == 0)
      {
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
      }

      if (p_mt_instrument_reset_struct_h->h_instr_seq_num == 0)
      {
         APL_DATA_MISSING("SEQUENCE NUMBER",APL_NULL_STRING,APL_NULL_STRING)
      }
   }
   /*Mandatory Data Checks Over*/

     /* Kouser - HDFCMT_003 - HDFC New Requirement  */
	  /* Check Valid Instrument Type  For Reset Details */

	g_mst_key_values[0]=p_mt_instrument_reset_struct_h->h_instr_code;
	g_mst_key_values[1]=APL_NULL_STRING;

   strcpy(l_field_name,"INSTR_SUB_TYPE");     

           int_retval = CR_Chk_MasterField( p_field_ind,
		                                      l_field_name,
					                             g_mst_key_codes,
					   	                       g_mst_key_values,
								                    g_mst_table_name,
														  p_intl_env_data_struct_h,
									                 l_debug_info_ptr);

           printf("Val of p_field_ind From Function ==|%s|\n",p_field_ind);

       if ((strcmp(p_field_ind,APL_INSTRU_SUB_WARRANTS) == 0) || 
           (strcmp(p_field_ind,APL_INSTRU_PREF_SHARE) == 0) || 
			  (strcmp(p_field_ind,APL_INSTRU_PRIVATE_PLACED) == 0) || 
			  (strcmp(p_field_ind,APL_INSTRU_MISCELLANEOUS) == 0) ||
			  (strcmp(p_field_ind,APL_INSTRU_UNIT) == 0) ||
			  (strcmp(p_field_ind,APL_INSTRU_RIGHTS_FORM) == 0) ||
			  (strcmp(p_field_ind,APL_INSTRU_EXS_EQUITY_CD) == 0) ||
			  (strcmp(p_field_ind,APL_INSTRU_PTC) == 0) ||
			  (strcmp(p_field_ind,APL_INSTRU_SHARE) == 0))
       {
	  		CO_InsertErr(  l_debug_info_ptr,
  	     		            ERR_INVALID_INSTRU_TYPE_RESETDET,
		        		      APL_NULL_STRING,
		        		      APL_NULL_STRING,
		             		APL_NULL_STRING,
				       		__LINE__,
				       		__FILE__);
         APL_GOBACK_FAIL
      }

 /* Kouser - HDFCMT_003 - HDFC New Requirement */
 /* Check Valid Instrument Type for Reset Details */

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Instrument is |%s| \n",p_mt_instrument_reset_struct_h->h_instr_code);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is |%s| \n",p_intl_env_data_struct_h->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
   }

   p_key_values[0]=p_mt_instrument_reset_struct_h->h_instr_code;
   p_key_values[1]=ltoa(p_mt_instrument_reset_struct_h->h_instr_seq_num);
   p_key_values[2]=APL_NULL_STRING;
   g_mst_key_values[0]=p_mt_instrument_reset_struct_h->h_instr_code;
   g_mst_key_values[1]=APL_NULL_STRING;

	APL_IF_DEBUG
   {
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Master Check Conditions --> Exists - |%c|\n",chr_iexist);
      printf("Master Check Conditions --> Deleted - |%c|\n",chr_ideleted);
   }

   int_retval = CO_Chk_InstrValid( 	p_mt_instrument_reset_struct_h->h_instr_code,
                           	      chr_iexist,
                             	    	NULL,
                             	    	chr_ideleted,
                                 	NULL,
                                 	NULL,
                                 	NULL,
                                 	l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(l_field_name,"INSTR_RESET_FLG");

	int_retval = CR_Chk_MasterField( p_field_ind,
												l_field_name,
												g_mst_key_codes,
												g_mst_key_values,
												g_mst_table_name,
                                   	p_intl_env_data_struct_h,
                                   	l_debug_info_ptr);

	if (strcmp(p_field_ind,"N") == 0)
	{
      CO_InsertErr(  l_debug_info_ptr,
                     ERR_RESET_DET_NOT_ALLOW,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     APL_NULL_STRING,
                     __LINE__,
                     __FILE__);
      APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
   {
      chr_chld_iexist = 'N';
      chr_chld_ideleted = APL_NULL_CHAR;
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;
   }
   else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';
   }

   APL_IF_DEBUG
   {
      printf("Master Details Exists in Proper Status ... \n");
      printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
      printf("Child Check Conditions --> Exists - |%c|\n",chr_chld_iexist);
      printf("Child Check Conditions --> Deleted - |%c|\n",chr_chld_ideleted);
      printf("Child Check Conditions --> Authorised - |%c|\n",chr_chld_iauthorised);

      printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
      printf("Key Codes 1 = |%s|\n",p_key_codes[1]);

      printf("Key Value 0 = |%s|\n",p_key_values[0]);
      printf("Key Value 1 = |%s|\n",p_key_values[1]);
   }

   int_retval = CO_Chk_ChldValid( 		p_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
   {
         /*Check for same maker and checker */

      int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)
   {
      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
      strcpy(chr_l_row_id_instr,chr_l_field_val);

      int_retval = CR_Rtv_MastChldChrVal	(  p_key_codes,
                                             p_key_values,
                                             chr_chld_table_name,
                                             "ACCESS_STAMP",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      APL_IF_DEBUG
      {
         printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
         printf("Access Stamp from Parameter String = |%s|\n",p_mt_instrument_reset_struct_h->h_access_stamp);
      }

      if (strcmp(chr_l_field_val,p_mt_instrument_reset_struct_h->h_access_stamp) != 0)
      {
       CO_InsertErr(  l_debug_info_ptr,
                      ERR_ACCESSSTAMP_CHGD,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      APL_NULL_STRING,
                      __LINE__,
                      __FILE__);
       APL_GOBACK_FAIL
      }
   }
	
	int_retval = CR_Chk_InstrReset(	p_mt_instrument_reset_struct_h,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	int_retval = CR_Mod_InstrReset(	p_mt_instrument_reset_struct_h,
												chr_l_row_id_instr,
												p_intl_env_data_struct_h,
												l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrReset with Success \n",NULL,NULL);
         return(APL_SUCCESS);
  	}

	RETURN_FAILURE :
  	{
     APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving Process MT_Mod_InstrReset with Failure \n",NULL,NULL);
         return(APL_FAILURE);
  	}
}
