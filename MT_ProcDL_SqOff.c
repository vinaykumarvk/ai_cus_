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
 * Module Name         :      Master Maintenance
 *
 * File Name           :      MT_ProcDL_SqOff.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 11/01/2006   1.0       Sundar        New file       HDFCDL_015
 *
 *********************************************************************/


#define PURE_C_SOURCE
#define APL_COUNTRY_CODE "IN"

#include "CO_HostStructdef.h" 

int DL_ModSqOff (DL_SQOFF_STRUCT_H *p_dl_sqoff_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[17];
	char  *l_key_values[17];	
	char  chr_l_table_name[50];
	int   l_int_l_holexists = 0;
	int   l_int_l_datecmp = 0;
	int   l_int_retval = 0;

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */
		/* changes by amish --24/05 */
  /*
	l_key_codes[0]="EXCH_CODE";
	*/
	l_key_codes[0]="SETTLEMT_NO";
	l_key_codes[1]="PAYIN_DT";
	l_key_codes[2]="PAYOUT_DT";
	l_key_codes[3]="DL_REF_NO";
	l_key_codes[4]="CLN_CODE";
	l_key_codes[5]="INSTR_CODE";
	/* changes by amish --24/05 */
	/*
	l_key_codes[7]="CHQ_NO";
	l_key_codes[8]="CHQ_DT";
	*/
	l_key_codes[6]=APL_NULL_STRING;
	/* changes by amish --24/05 */
	/*
	l_key_values[0]=p_dl_sqoff_struct_h -> h_exch_code;
	*/
	l_key_values[0]=p_dl_sqoff_struct_h -> h_settlemt_no;
	l_key_values[1]=p_dl_sqoff_struct_h -> h_payin_dt;
	l_key_values[2]=p_dl_sqoff_struct_h -> h_payout_dt;
	l_key_values[3]=p_dl_sqoff_struct_h -> h_dl_ref_no;
	l_key_values[4]=p_dl_sqoff_struct_h -> h_cln_code;
	l_key_values[5]=p_dl_sqoff_struct_h -> h_instr_code;
	/* changes by amish --24/05 */
	/*
	l_key_values[7]=p_dl_sqoff_struct_h -> h_chq_no;
	l_key_values[8]=p_dl_sqoff_struct_h -> h_chq_dt;
	*/
	l_key_values[6] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 6,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

			/*	Mandatory Data Missing Checks	- For Numbers */
			if (p_dl_sqoff_struct_h->h_deal_qty == 0)
			{
				APL_DATA_MISSING("DEAL_QTY cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
			if (p_dl_sqoff_struct_h->h_bal_qty == 0)
			{
				APL_DATA_MISSING("BAL_QTY cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
			if (p_dl_sqoff_struct_h->h_sqoff_qty == 0)
			{
				APL_DATA_MISSING("SQOFF_QTY cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
			if (p_dl_sqoff_struct_h->h_sqoff_amt == 0)
			{
				APL_DATA_MISSING("SQOFF_AMT cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
			/* changes by amish --24/05 */
			/*
			if (p_dl_sqoff_struct_h->h_prn_amt == 0)
			{
				APL_DATA_MISSING("PRN_AMT cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
		*/
	 
		  /* l_int_retval = CO_Chk_CodeValid ("EXCHANGE",p_dl_sqoff_struct_h->h_exch_code,APL_COUNTRY_CODE,l_debug_info_ptr);

		  if (l_int_retval !=APL_SUCCESS)
		  {
			  if( CO_InsertErr(l_debug_info_ptr, ERR_SQOFF_EXCH_CD_NOT_EXIST,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			  {
				  APL_GOBACK_FAIL
			  }
			  int_error_flag = APL_FAILURE;
		  }*/

          l_int_retval = 0;
		  l_int_retval = CR_Chk_ValAtSqOff(p_dl_sqoff_struct_h,l_debug_info_ptr);

		  if(l_int_retval !=APL_SUCCESS)
		  {
			  APL_GOBACK_FAIL
		  }

		  if(int_error_flag ==APL_FAILURE)
		  {
			  APL_GOBACK_FAIL
		  }
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_sqoff_struct_h->h_access_stamp)) 
		{
			APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;
		}
	}

 if ((int_retval !=APL_SUCCESS) || (int_error_flag == APL_FAILURE))	
      APL_GOBACK_FAIL

 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 {
 	APL_GOBACK_FAIL
 }

	/*	Setting Values for Mode Specific Checks	*/  
	strcpy(chr_l_table_name,"DL_SQOFF");

 if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
 {
    chr_l_rec_iexist = 'N';
    chr_l_rec_ideleted = APL_NULL_CHAR;
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 }
 else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)  )
 {
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'N';
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 }
 else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0)) 
 {
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = APL_NULL_CHAR;
    chr_l_rec_iauthorized = 'N';
 }
 else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0)) 
 {
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'Y';
    chr_l_rec_iauthorized = 'N';
 }

 printf("\n amish----------------------------------------------------------\n");
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
 {
	 l_key_codes[0]="DL_REF_NO";
	 l_key_codes[1]="CLN_CODE";
	 l_key_codes[2]=APL_NULL_STRING;

	 l_key_values[0]=p_dl_sqoff_struct_h -> h_dl_ref_no;
	 l_key_values[1]=p_dl_sqoff_struct_h -> h_cln_code;
 	l_key_values[2] = APL_NULL_STRING;

 	int_retval = CO_Chk_ChldValid(      l_key_codes,
                                     l_key_values,
                                     chr_l_rec_iexist,
                                     chr_l_rec_iauthorized,
                                     chr_l_rec_ideleted,
                                     NULL,
                                     NULL,
                                     NULL,
                                     chr_l_table_name,
                                     l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
      APL_GOBACK_FAIL
 }
 else
 {
		l_key_codes[0]="DL_REF_NO";	
		l_key_codes[1]="CLN_CODE";
		l_key_codes[2]="SQOFF_REF_NO";
		l_key_codes[3]=APL_NULL_STRING;

		l_key_values[0]=p_dl_sqoff_struct_h -> h_dl_ref_no;
		l_key_values[1]=p_dl_sqoff_struct_h -> h_cln_code;
		l_key_values[2]=p_dl_sqoff_struct_h -> h_sqoff_ref_no;
		l_key_values[3] = APL_NULL_STRING;
		
  	
 	int_retval = CO_Chk_ChldValid(      l_key_codes,
                                     l_key_values,
                                     chr_l_rec_iexist,
                                     chr_l_rec_iauthorized,
                                     chr_l_rec_ideleted,
                                     NULL,
                                     NULL,
                                     NULL,
                                     chr_l_table_name,
                                     l_debug_info_ptr);
 	 
 }	 
if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)))
	{
		printf("\nin authorise mode********************************8\n");
		l_key_codes[0]="DL_REF_NO";
		l_key_codes[1]="CLN_CODE";
		l_key_codes[2]="SQOFF_REF_NO";
		l_key_codes[3]=APL_NULL_STRING;

		l_key_values[0]=p_dl_sqoff_struct_h -> h_dl_ref_no;
		l_key_values[1]=p_dl_sqoff_struct_h -> h_cln_code;
		l_key_values[2]=p_dl_sqoff_struct_h -> h_sqoff_ref_no;
		l_key_values[3] = APL_NULL_STRING;
		
       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);



	}

 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModSqOff... \n",NULL,p_intl_env_data_struct_h);
 	}

		DL_ModDB_SqOff(p_dl_sqoff_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModSqOff... \n",NULL,p_intl_env_data_struct_h);
 	}

	   DL_ModDB_SqOff(p_dl_sqoff_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModSqOff... \n",NULL,p_intl_env_data_struct_h);
 	}
		/******** Following code checks for presence of records in other tables......
		l_key_codes[0]="BENCHMARK_CODE";
		l_key_codes[1]=APL_NULL_STRING;
		
		l_key_values[0]=p_mt_dlflrate_struct_h->h_benchmark_code;
		l_key_values[1] = APL_NULL_STRING;

		int_retval = CR_Chk_CodeInChld(l_key_codes,
	                                l_key_values,
	                                l_linked_table_names,
	                                p_intl_env_data_struct_h,
	                                l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
    {
    	CO_InsertErr(  l_debug_info_ptr,
                   MAP_INSTR_EXIST_CANTDEL,								
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   DL_ModDB_SqOff(p_dl_sqoff_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModSqOff... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDB_SqOff(p_dl_sqoff_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModSqOff... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDB_SqOff(p_dl_sqoff_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
  {
  	APL_GOBACK_FAIL
  }

 APL_GOBACK_SUCCESS

 RETURN_SUCCESS :
	{
 	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
		return(APL_SUCCESS);
	}
 RETURN_FAILURE :
	{
		APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
		return(APL_FAILURE);
	}

} 
