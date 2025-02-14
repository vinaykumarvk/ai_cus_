
/************************************************************************************
 *    COPYRIGHT NOTICE                                                              *
 *                                                                                  *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.              *
 *                                                                                  *
 *   These materials are confidential and proprietary to                            *
 *    Polaris Software Lab Limited and no part of these materials should            *
 *    be reproduced, published, transmitted or distributed in any form or           *
 *    by any means, electronic, mechanical, photocopying, recording or              *
 *    otherwise, or stored in any information storage or retrieval system           *
 *    of any nature nor should the materials be disclosed to third parties          *
 *    or used in any other manner for which this is not authorized, without         *
 *    the prior express written authorization of Polaris Software Lab Limited.      *
 */
/************************************************************************************
 *
 * Module Name         :        Master Maintenance
 *
 * File Name           :        MT_ProcIndexFund.c
 *
 * Description         :        This file contains functions for master and
 *                              child tables' records insertion and updation
 *                              in all modes business validations check functions.
 *
 *
 *                      Version Control Block
 *
 * Date        Version     Author               Description											RFS NO
 * ---------   --------  ---------------  ---------------------------------------------	------
 * 26-12-2005   1.0       S Pradeep       New file to validate Master and child tables		HDFCMT_017
 *************************************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h"

int MT_ModIndexFund(MT_INDEX_FUND_STRUCT_H *p_mt_index_fund_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/* Variable Decleration */
	int int_error_flag = APL_SUCCESS;

	char *l_key_codes[3];	
	char *l_key_values[3];
	char *l_link_table_names[2];
	char chr_l_table_name[50];

	char chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	int int_retval = APL_SUCCESS;
	/* Debug Statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/* Mandatory Data Missing Checks - Generic */

	l_key_codes[0]="INDEX_FUND_NUM";
	l_key_codes[1]="INDEX_FUND_NAME";
	l_key_codes[2]=APL_NULL_STRING;

	l_key_values[0]=p_mt_index_fund_struct_h->h_index_fund_num;
	l_key_values[1]=p_mt_index_fund_struct_h->h_index_fund_name;
	l_key_values[2]=APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData(l_key_codes,
											  l_key_values,
											  2,
											  l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	/* Mandatory Data Missing Checks - Mode Specific */
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
   {
      if (!strlen(p_mt_index_fund_struct_h->h_access_stamp))
      {
         APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
      	int_error_flag = APL_FAILURE;
      }
   }

   if (int_retval !=APL_SUCCESS)
      APL_GOBACK_FAIL

 	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 	{
   	APL_GOBACK_FAIL
 	}
	/* Setting Values for Mode Specific Checks   */
   strcpy(chr_l_table_name,"MT_INDEX_FUND");
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
	
		l_key_codes[0]="INDEX_FUND_NUM";
		l_key_codes[1]=APL_NULL_STRING;

		l_key_values[0]=p_mt_index_fund_struct_h->h_index_fund_num;
		l_key_values[1]=APL_NULL_STRING;

		int_retval = CO_Chk_ChldValid(	l_key_codes,
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

 	if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
   {
      APL_IF_DEBUG
   {
      CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
   }	

		MT_ModDBIndexFund(p_mt_index_fund_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
         APL_GOBACK_FAIL
      }
   }
 	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
   {
      APL_IF_DEBUG
   {
      CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode ... \n",NULL,p_intl_env_data_struct_h);
   }

      MT_ModDBIndexFund(p_mt_index_fund_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);

   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
         APL_GOBACK_FAIL
      }
   }
 	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
   {
      APL_IF_DEBUG
   {
      CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode ... \n",NULL,p_intl_env_data_struct_h);
   }
		/******** Following code checks for presence of records in other tables...... ********/
		l_key_codes[0]="INDEX_FUND_NUM";
		l_key_codes[1]=APL_NULL_STRING;

		l_key_values[0]=p_mt_index_fund_struct_h->h_index_fund_num;
		l_key_values[1]=APL_NULL_STRING;

		l_link_table_names[0]="MT_INDEX_FUNDDET";
		l_link_table_names[1]=APL_NULL_STRING;


		int_retval = CR_Chk_CodeInChld(	l_key_codes,
													l_key_values,
													l_link_table_names,
													p_intl_env_data_struct_h,
													l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
		{
			CO_InsertErr(	l_debug_info_ptr,
					ERR_INSTR_EXISTS_CANTDEL,
					p_intl_env_data_struct_h->h_mode,
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);
		}
		else if (int_retval ==APL_FAILURE)
			APL_GOBACK_FAIL

		MT_ModDBIndexFund(p_mt_index_fund_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
		
		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
	 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
    {
      APL_IF_DEBUG
   	{
      	CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
   	}

		l_key_codes[0]="INDEX_FUND_NUM";
		l_key_codes[1]=APL_NULL_STRING;

		l_key_values[0]=p_mt_index_fund_struct_h->h_index_fund_num;
		l_key_values[1]=APL_NULL_STRING;

		int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    	if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

		MT_ModDBIndexFund(p_mt_index_fund_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
		
		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
         {
            APL_GOBACK_FAIL
         }
    }
	 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
    {
      APL_IF_DEBUG
   	{
         CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
      }

      l_key_codes[0]="INDEX_FUND_NUM";
      l_key_codes[1]=APL_NULL_STRING;

      l_key_values[0]=p_mt_index_fund_struct_h->h_index_fund_num;
      l_key_values[1]=APL_NULL_STRING;

      int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

      if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

      MT_ModDBIndexFund(p_mt_index_fund_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

      if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
         {
            APL_GOBACK_FAIL
         }
    }
	 if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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
							
	int MT_ModIndexFundDet(	MT_INDEX_FUNDDET_STRUCT_H *p_mt_index_funddet_struct_h,
									INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
									DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
	{
		/* Variable Declerations */
		int int_error_flag = APL_SUCCESS;

		char *l_key_codes[3];
		char *l_key_values[3];
		char chr_l_table_name[50];
		char chr_l_exist = 'Y'; //AIX Warnings
		char chr_l_auth = 'Y';  //AIX Warnings
		char chr_l_del = 'N';   //AIX Warnings
		char chr_l_frozen = 'N';//AIX Warnings
		char chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
		int int_retval = APL_SUCCESS;
		/* Debug statements */
		APL_FUNCTION_ENTER(APL_OUT_FILE)

		/* Mandatory Data Missing Checks */
		l_key_codes[0]="INDEX_FUND_NUM";
		l_key_codes[1]="INSTR_CODE";
		l_key_codes[2]=APL_NULL_STRING;

		l_key_values[0]=p_mt_index_funddet_struct_h->h_index_fund_num;
		l_key_values[1]=p_mt_index_funddet_struct_h->h_instr_code;
		l_key_values[2]=APL_NULL_STRING;

		int_retval = CR_Chk_AllMandData( l_key_codes,
													l_key_values,
													2,
													l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		/* Mandatory Data Missing Checks - Mode Specific */
		if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
		{
			if (!strlen(p_mt_index_funddet_struct_h->h_access_stamp))
			{
				APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
				int_error_flag = APL_FAILURE;
			}
		}

		if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL

		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}

		int_retval = CO_Chk_InstrValid(	p_mt_index_funddet_struct_h->h_instr_code,
													chr_l_exist,
													chr_l_auth,
													chr_l_del,
													chr_l_frozen,
													NULL,
													NULL,
													l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	
		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
		/* Setting Values for Mode Specific Checks   */
		strcpy(chr_l_table_name,"MT_INDEX_FUNDDET");
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

		l_key_codes[0]="INDEX_FUND_NUM";
		l_key_codes[1]="INSTR_CODE";
		l_key_codes[2]=APL_NULL_STRING;

		l_key_values[0]=p_mt_index_funddet_struct_h->h_index_fund_num;
		l_key_values[1]=p_mt_index_funddet_struct_h->h_instr_code;
		l_key_values[2]=APL_NULL_STRING;

		int_retval = CO_Chk_ChldValid(   l_key_codes,
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

				if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
				{
					APL_IF_DEBUG
					{
						CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
					}

					MT_ModDBIndexFundDet(p_mt_index_funddet_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
					if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
					{
						APL_GOBACK_FAIL
					}
				}

				else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
				{
					APL_IF_DEBUG
					{
						CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode ... \n",NULL,p_intl_env_data_struct_h);
					}

					MT_ModDBIndexFundDet(p_mt_index_funddet_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);

					if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
					{
						APL_GOBACK_FAIL
					}
				}

				else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
				{
					APL_IF_DEBUG
					{
						CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode ... \n",NULL,p_intl_env_data_struct_h);
					}

					MT_ModDBIndexFundDet(p_mt_index_funddet_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);

					if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
					{
						APL_GOBACK_FAIL
					}
				}

				else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
				{
					APL_IF_DEBUG
					{
						CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
					}

					l_key_codes[0]="INDEX_FUND_NUM";
					l_key_codes[1]="INSTR_CODE";
					l_key_codes[2]=APL_NULL_STRING;

					l_key_values[0]=p_mt_index_funddet_struct_h->h_index_fund_num;
					l_key_values[1]=p_mt_index_funddet_struct_h->h_instr_code;
					l_key_values[2]=APL_NULL_STRING;

					int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
							l_key_values,
							chr_l_table_name,
							p_intl_env_data_struct_h->usr,
							l_debug_info_ptr);

					if (int_retval !=APL_SUCCESS)
						APL_GOBACK_FAIL

					MT_ModDBIndexFundDet(p_mt_index_funddet_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

					if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
					{
						APL_GOBACK_FAIL
					}
				}
				
				else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
				{
					APL_IF_DEBUG
					{
						CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
					}

					l_key_codes[0]="INDEX_FUND_NUM";
					l_key_codes[1]="INSTR_CODE";
					l_key_codes[2]=APL_NULL_STRING;

					l_key_values[0]=p_mt_index_funddet_struct_h->h_index_fund_num;
					l_key_values[1]=p_mt_index_funddet_struct_h->h_instr_code;
					l_key_values[2]=APL_NULL_STRING;

					int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
							l_key_values,
							chr_l_table_name,
							p_intl_env_data_struct_h->usr,
							l_debug_info_ptr);

					if (int_retval !=APL_SUCCESS)
						APL_GOBACK_FAIL

					MT_ModDBIndexFundDet(p_mt_index_funddet_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

					if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
					{
						APL_GOBACK_FAIL
					}
				}

				else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

