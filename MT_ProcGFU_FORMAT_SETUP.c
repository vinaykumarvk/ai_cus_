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
 * File Name           :      MT_ProcGFU_FORMAT_SETUP
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 07/01/2006   1.0       Sundar        New file       HDFCMT_GF1
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int MT_ModGFU_FORMAT_SETUP (MT_GFU_FORMAT_SETUP_STRUCT_H *p_mt_gfu_format_setup_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[5];
	char  *l_key_values[5];	
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
   char  *l_linked_table_names[4]={APL_NULL_STRING};

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */

	l_key_codes[0]="VENDOR_ID";
	l_key_codes[1]="FUNCTION_ID";
	l_key_codes[2]="FILE_TYPE";
	l_key_codes[3]="REF_NO";
	l_key_codes[4]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_format_setup_struct_h -> h_vendor_id;
	l_key_values[1]=p_mt_gfu_format_setup_struct_h -> h_function_id;
	l_key_values[2]=p_mt_gfu_format_setup_struct_h -> h_file_type;
	l_key_values[3]=p_mt_gfu_format_setup_struct_h -> h_ref_no;
	l_key_values[4] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 4,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	/*	Mandatory Data Missing Checks	- For Numbers */
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_mt_gfu_format_setup_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"MT_GFU_FORMAT_SETUP");

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

	l_key_codes[0]="REF_NO";
	l_key_codes[1]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_format_setup_struct_h -> h_ref_no;
	l_key_values[1] = APL_NULL_STRING;

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
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModGFU_FORMAT_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

		MT_ModDB_GFU_FORMAT_SETUP(p_mt_gfu_format_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ModGFU_FORMAT_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

	   MT_ModDB_GFU_FORMAT_SETUP(p_mt_gfu_format_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ModGFU_FORMAT_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}
		/******** Following code checks for presence of records in other tables......*/
	l_key_codes[0]="REF_NO";
	l_key_codes[1]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_format_setup_struct_h -> h_ref_no;
	l_key_values[1] = APL_NULL_STRING;

	l_linked_table_names[0]="MT_GFU_EXCEL_SETUP";
	l_linked_table_names[1]="MT_GFU_TXT_SETUP";
	l_linked_table_names[2]="MT_GFU_CSV_SETUP";
	l_linked_table_names[3]=APL_NULL_STRING;

	int_retval = CR_Chk_CodeInChld(l_key_codes,
			l_key_values,
			l_linked_table_names,
			p_intl_env_data_struct_h,
			l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
	{
		CO_InsertErr(  l_debug_info_ptr,
				ERR_FORMAT_CANT_DEL,
				"Mapping Exists",
				p_mt_gfu_format_setup_struct_h->h_ref_no,
				APL_NULL_STRING,
				__LINE__,
				__FILE__);
	}
	else if (int_retval == APL_FAILURE)
		APL_GOBACK_FAIL
	
	/*************************************************************************************/	
	   MT_ModDB_GFU_FORMAT_SETUP(p_mt_gfu_format_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ModGFU_FORMAT_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDB_GFU_FORMAT_SETUP(p_mt_gfu_format_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ModGFU_FORMAT_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDB_GFU_FORMAT_SETUP(p_mt_gfu_format_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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

int MT_ModGfu_Excel_SETUP (MT_GFU_EXCEL_SETUP_STRUCT_H *p_mt_gfu_excel_setup_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[4];
	char  *l_key_values[4];	
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */

	l_key_codes[0]="REF_NO";
	l_key_codes[1]="EXCEL_FIELD_NAME";
	l_key_codes[2]="EXCEL_REFERENCE_VALUE";
	l_key_codes[3]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_excel_setup_struct_h -> h_ref_no;
	l_key_values[1]=p_mt_gfu_excel_setup_struct_h -> h_excel_field_name;
	l_key_values[2]=p_mt_gfu_excel_setup_struct_h -> h_excel_reference_value;
	l_key_values[3] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
											3,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	/*	Mandatory Data Missing Checks	- For Numbers */
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_mt_gfu_excel_setup_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"MT_GFU_EXCEL_SETUP");

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

 l_key_codes[0]="REF_NO";
 l_key_codes[1]="EXCEL_FIELD_NAME";
 l_key_codes[2]=APL_NULL_STRING;

 l_key_values[0]=p_mt_gfu_excel_setup_struct_h -> h_ref_no;
 l_key_values[1]=p_mt_gfu_excel_setup_struct_h -> h_excel_field_name;
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
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModGfu_Excel_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

		MT_ModDB_Gfu_Excel_Setup(p_mt_gfu_excel_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ModGfu_Excel_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

	   MT_ModDB_Gfu_Excel_Setup(p_mt_gfu_excel_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ModGfu_Excel_SETUP... \n",NULL,p_intl_env_data_struct_h);
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
AIX - Warnings Removal - removed comment with comment
		if (int_retval != APL_SUCCESS)
    {
    	CO_InsertErr(  l_debug_info_ptr,
                   MAP_INSTR_EXIST_CANTDEL,								 Need to change this 
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   MT_ModDB_Gfu_Excel_Setup(p_mt_gfu_excel_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ModGfu_Excel_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDB_Gfu_Excel_Setup(p_mt_gfu_excel_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ModGfu_Excel_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDB_Gfu_Excel_Setup(p_mt_gfu_excel_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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


int MT_ModGfu_Txt_SETUP (MT_GFU_TXT_SETUP_STRUCT_H *p_mt_gfu_txt_setup_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
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

	l_key_codes[0]="REF_NO";
	l_key_codes[1]="TXT_FIELD_NAME";
	l_key_codes[2]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_txt_setup_struct_h -> h_ref_no;
	l_key_values[1]=p_mt_gfu_txt_setup_struct_h -> h_txt_field_name;
	l_key_values[2] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 2,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	/*	Mandatory Data Missing Checks	- For Numbers */
			if (p_mt_gfu_txt_setup_struct_h->h_start_pos == 0)
			{
				APL_DATA_MISSING("start_pos cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
	if (p_mt_gfu_txt_setup_struct_h->h_end_pos == 0)
	{
		APL_DATA_MISSING("end_pos cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}
	
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_mt_gfu_txt_setup_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"MT_GFU_TXT_SETUP");

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


 l_key_codes[0]="REF_NO";
 l_key_codes[1]="TXT_FIELD_NAME";
 l_key_codes[2]=APL_NULL_STRING;

 l_key_values[0]=p_mt_gfu_txt_setup_struct_h -> h_ref_no;
 l_key_values[1]=p_mt_gfu_txt_setup_struct_h -> h_txt_field_name;
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
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModGfu_Txt_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

		MT_ModDBGfu_Txt_Setup(p_mt_gfu_txt_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ModGfu_Txt_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

	   MT_ModDBGfu_Txt_Setup(p_mt_gfu_txt_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ModGfu_Txt_SETUP... \n",NULL,p_intl_env_data_struct_h);
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
                   MAP_INSTR_EXIST_CANTDEL,								 Need to change this 
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   MT_ModDBGfu_Txt_Setup(p_mt_gfu_txt_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ModGfu_Txt_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDBGfu_Txt_Setup(p_mt_gfu_txt_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ModGfu_Txt_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDBGfu_Txt_Setup(p_mt_gfu_txt_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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


int MT_ModGfu_Csv_SETUP (MT_GFU_CSV_SETUP_STRUCT_H *p_mt_gfu_csv_setup_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[4];
	char  *l_key_values[4];	
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */

	l_key_codes[0]="REF_NO";
	l_key_codes[1]="CSV_FIELD_NAME";
	l_key_codes[2]="CSV_REFERENCE_VALUE";
	l_key_codes[3]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_gfu_csv_setup_struct_h -> h_ref_no;
	l_key_values[1]=p_mt_gfu_csv_setup_struct_h -> h_csv_field_name;
	l_key_values[2]=p_mt_gfu_csv_setup_struct_h -> h_csv_reference_value;
	l_key_values[3] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 4 - 1,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	/*	Mandatory Data Missing Checks	- For Numbers */
	
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_mt_gfu_csv_setup_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"MT_GFU_CSV_SETUP");

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

 l_key_codes[0]="REF_NO";
 l_key_codes[1]="CSV_FIELD_NAME";
 l_key_codes[2]=APL_NULL_STRING;

 l_key_values[0]=p_mt_gfu_csv_setup_struct_h -> h_ref_no;
 l_key_values[1]=p_mt_gfu_csv_setup_struct_h -> h_csv_field_name;
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
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModGfu_Csv_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

		MT_ModDBGfu_Csv_Setup(p_mt_gfu_csv_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ModGfu_Csv_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

	   MT_ModDBGfu_Csv_Setup(p_mt_gfu_csv_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ModGfu_Csv_SETUP... \n",NULL,p_intl_env_data_struct_h);
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
                   MAP_INSTR_EXIST_CANTDEL,								 Need to change this 
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   MT_ModDBGfu_Csv_Setup(p_mt_gfu_csv_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ModGfu_Csv_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDBGfu_Csv_Setup(p_mt_gfu_csv_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ModGfu_Csv_SETUP... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_ModDBGfu_Csv_Setup(p_mt_gfu_csv_setup_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
