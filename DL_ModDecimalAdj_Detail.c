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
 * File Name           :      DL_ModDecimalAdj_Detail.c
 *
 * Description         :		This file contains functions for mandatory data checks and 
 *									calls function to Update record.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author				Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 17/10/2007   1.0       Jiger					New file			  ISKB_487
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int DL_ModDecimalAdj(DL_DEAL_DECI_ADJ_STRUCT_H *p_dl_deal_deci_adj_struct_h, 
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[3];
	char  *l_key_values[3];	
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */

	l_key_codes[0] = "CLIENT";
	l_key_codes[1] = "IDENTIY_NO";
	l_key_codes[2] = "APL_NULL_STRING";

	l_key_values[0] = p_dl_deal_deci_adj_struct_h -> h_dl_client;
	l_key_values[1] = p_dl_deal_deci_adj_struct_h -> h_identiy_no;
	l_key_values[2] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
	l_key_values,
	2,
	l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS) 
	APL_GOBACK_FAIL

	/*	Mandatory Data Missing Checks	- For Numbers */
	if (strlen(p_dl_deal_deci_adj_struct_h->h_dl_client) == 0)
	{
		APL_DATA_MISSING("Client code cannot be null",APL_NULL_STRING,APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}
	if (strlen(p_dl_deal_deci_adj_struct_h->h_identiy_no) == 0)
	{
		APL_DATA_MISSING("Reference number cannot be null",APL_NULL_STRING,APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	/*	Mandatory Data Missing Checks	- Mode Specific */

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_deal_deci_adj_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name, "DL_DEAL_DECI_ADJ");

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
	else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0)) 
	{
		chr_l_rec_iexist = 'Y';
		chr_l_rec_ideleted = APL_NULL_CHAR;
		chr_l_rec_iauthorized = 'N';
	}
	else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0)) 
	{
		chr_l_rec_iexist = 'Y';
		chr_l_rec_ideleted = 'Y';
		chr_l_rec_iauthorized = 'N';
	}

	l_key_codes[0] = "CLIENT";
	l_key_codes[1] = "IDENTIY_NO";
	l_key_codes[2] = APL_NULL_STRING;

	l_key_values[0] = p_dl_deal_deci_adj_struct_h -> h_dl_client;
	l_key_values[1] = p_dl_deal_deci_adj_struct_h -> h_identiy_no;
	l_key_values[2] = APL_NULL_STRING;

	int_retval = CO_Chk_ChldValid( l_key_codes,
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

	if((!strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)))
	{
		int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
																l_key_values,
																chr_l_table_name,
																p_intl_env_data_struct_h->usr,
																l_debug_info_ptr);
	}

	if(!strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModDecimalAdj... \n",NULL,p_intl_env_data_struct_h);
		}

		DL_UpdDecimalAdj(p_dl_deal_deci_adj_struct_h, p_intl_env_data_struct_h, l_debug_info_ptr);

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModDecimalAdj... \n",NULL,p_intl_env_data_struct_h);
		}

		DL_UpdDecimalAdj(p_dl_deal_deci_adj_struct_h, p_intl_env_data_struct_h, l_debug_info_ptr);	

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
		{
		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModDecimalAdj... \n",NULL,p_intl_env_data_struct_h);
		}

		DL_UpdDecimalAdj(p_dl_deal_deci_adj_struct_h, p_intl_env_data_struct_h, l_debug_info_ptr);	

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModDecimalAdj... \n",NULL,p_intl_env_data_struct_h);
		}

		if (int_retval_mkrchkr != APL_SUCCESS)
			APL_GOBACK_FAIL

		DL_UpdDecimalAdj(p_dl_deal_deci_adj_struct_h, p_intl_env_data_struct_h, l_debug_info_ptr);	

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}

	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModDecimalAdj... \n",NULL,p_intl_env_data_struct_h);
		}

		if (int_retval_mkrchkr != APL_SUCCESS)
		APL_GOBACK_FAIL

		DL_UpdDecimalAdj(p_dl_deal_deci_adj_struct_h, p_intl_env_data_struct_h, l_debug_info_ptr);	

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
