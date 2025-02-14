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
 * File Name           :      MT_ProcDL_BifDet.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 19/01/2006   1.0       Sundar        New file       HDFCDL_003
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "DL_Interface.h"
#include "CO_HostStructdef.h" 

int DL_ModDL_BifDet (DL_BIFDET_STRUCT_H *p_dl_bifdet_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
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

	/* l_key_codes[0]="DL_CLIENT";
	l_key_codes[1]="DL_REF_NO";
	l_key_codes[2]="DP_ID";
	l_key_codes[3]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_bifdet_struct_h -> h_client;
	l_key_values[1]=p_dl_bifdet_struct_h -> h_identiy_no;
	l_key_values[2]=p_dl_bifdet_struct_h -> h_dp_id;
	l_key_values[3] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 3,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	Mandatory Data Missing Checks	- For Numbers */
   if (p_dl_bifdet_struct_h->h_qty == 0)
   {
      APL_DATA_MISSING("qty cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
   }
	
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_bifdet_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"DL_BIFDET");

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
/* 
	l_key_codes[0]="CLIENT";
	l_key_codes[1]="IDENTIY_NO";
	l_key_codes[2]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_bifdet_struct_h -> h_client;
	l_key_values[1]=p_dl_bifdet_struct_h -> h_identiy_no;
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

*/
 
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModDL_BifDet... \n",NULL,p_intl_env_data_struct_h);
 	}

		DL_ModDbDL_BifDet(p_dl_bifdet_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModDL_BifDet... \n",NULL,p_intl_env_data_struct_h);
 	}

	   DL_ModDbDL_BifDet(p_dl_bifdet_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModDL_BifDet... \n",NULL,p_intl_env_data_struct_h);
 	}
	   DL_ModDbDL_BifDet(p_dl_bifdet_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
