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
 * File Name           :      MT_ProcDL_MarkShortage.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 23/02/2006   1.0       Rahul        New file       HDFCDL_013
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int  DL_ProcMARKSHORTAGE(DL_MARKSHORTAGE_STRUCT_H *p_dl_markshortage_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[5];
	char  *l_key_values[5];	
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */
/*
	l_key_codes[0]="ALLOT_QTY";
*/
	l_key_codes[0]="POOL_TRANS";
	l_key_codes[1]=APL_NULL_STRING;
	/*
	l_key_values[0]=p_dl_markshortage_struct_h -> h_allot_qty;
	*/
	l_key_values[0]=p_dl_markshortage_struct_h -> h_pool_trans;
	l_key_values[1] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 1,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL


	/*	Mandatory Data Missing Checks	- For Numbers */
   if (p_dl_markshortage_struct_h->h_avail_qty == 0)
   {
      APL_DATA_MISSING("AVAILABLE QTY cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
   }
	

	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
/*		if (!strlen(p_dl_markshortage_struct_h->h_access_stamp)) 
		{
			APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;
		}*/
	}

 if ((int_retval !=APL_SUCCESS) || (int_error_flag == APL_FAILURE))	
      APL_GOBACK_FAIL

 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 {
 	APL_GOBACK_FAIL
 }

	/*	Setting Values for Mode Specific Checks	*/  
	strcpy(chr_l_table_name,"DL_MARKSHORTAGE");

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
 /* changes by amish --16/05 */

 printf("\n in c ................FILE BATCH NO IS |%d|\n",p_dl_markshortage_struct_h ->h_filebatch_no);
	l_key_codes[0]="DL_REF_NO";
   l_key_codes[1]="DL_CLIENT";
	l_key_codes[2]="FILEBATCH_NO";
	l_key_codes[3]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_markshortage_struct_h ->h_dl_ref_no;
	l_key_values[1]=p_dl_markshortage_struct_h ->h_dl_client;
	l_key_values[2]= ltoa(p_dl_markshortage_struct_h ->h_filebatch_no);
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

	if (int_retval !=APL_SUCCESS)
      APL_GOBACK_FAIL


 if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)))
	{
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
	  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_MARKSHORTAGE_STRUCT_H... \n",NULL,p_intl_env_data_struct_h);
 		}

		DL_ModDbDL_MARKSHORTAGE(p_dl_markshortage_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   			APL_GOBACK_FAIL
   		}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_MARKSHORTAGE_STRUCT_H... \n",NULL,p_intl_env_data_struct_h);
 		}
	    DL_ModDbDL_MARKSHORTAGE(p_dl_markshortage_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
		
	  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   			APL_GOBACK_FAIL
   		}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_MARKSHORTAGE_STRUCT_H... \n",NULL,p_intl_env_data_struct_h);
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

                   AIX - Warnings Removal - Romoved comment with in comment
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
	   DL_ModDbDL_MARKSHORTAGE(p_dl_markshortage_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   			APL_GOBACK_FAIL
   		}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_MARKSHORTAGE_STRUCT_H... \n",NULL,p_intl_env_data_struct_h);
 		}


		if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDbDL_MARKSHORTAGE(p_dl_markshortage_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

	  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   			APL_GOBACK_FAIL
   		}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_MARKSHORTAGE_STRUCT_H... \n",NULL,p_intl_env_data_struct_h);
 		}

		if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDbDL_MARKSHORTAGE(p_dl_markshortage_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
