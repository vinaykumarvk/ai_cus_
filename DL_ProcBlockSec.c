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
 * File Name           :      DL_ProcBlockSec.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 27/01/2006   1.0       Manik_Trivedi        New file       HDFCDL-026
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

#define APL_DL_INTR_SCH_CHLD 1

char 	*g_blk_chld_table_names[APL_DL_INTR_SCH_CHLD + 1] = {"DL_BLK_SEC_DET",APL_NULL_STRING};
char 	*g_blk_mst_key_codes[3] = {"BLK_REF_NO",APL_NULL_STRING};
char 	g_blk_mst_table_name[25] = "DL_BLK_SEC"; 

int DL_ModBlockSec (DL_BLK_SEC_STRUCT_H *p_dl_blk_sec_struct_h, char *p_blk_ref_no,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
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


   l_key_codes[0]="CLIENT";
	l_key_codes[1]="REMARKS";
	l_key_codes[2]=APL_NULL_STRING;
	
	l_key_values[0]= p_dl_blk_sec_struct_h -> h_client;
	l_key_values[1]= p_dl_blk_sec_struct_h -> h_remarks;
	l_key_values[2] = APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( 
			                        l_key_codes,
                                 l_key_values,
                                 2,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	int_retval = CO_Chk_ValidBlk(p_dl_blk_sec_struct_h,l_debug_info_ptr);
			
 	/*	Mandatory Data Missing Checks	- Mode Specific */

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_blk_sec_struct_h->h_access_stamp)) 
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
 	strcpy(chr_l_table_name,"DL_BLK_SEC");

 	if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0))
 	{
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'N';
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 	}
 	else if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0)) 
 	{
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = APL_NULL_CHAR;
    chr_l_rec_iauthorized = 'N';
 	}
 	else if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0)) 
 	{
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'Y';
    chr_l_rec_iauthorized = 'N';
 	}

	l_key_codes[0]="BLK_REF_NO";
	l_key_codes[1]=APL_NULL_STRING;
	
	l_key_values[0]= p_dl_blk_sec_struct_h->h_blk_ref_no;
	l_key_values[1] = APL_NULL_STRING;

 	int_retval = CO_Chk_ChldValid(    l_key_codes,
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
       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( 
				                         l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);



	}

 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModBlockSec... \n",NULL,p_intl_env_data_struct_h);
 	}

		DL_ModDBBlockSec(p_dl_blk_sec_struct_h,p_blk_ref_no,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
   else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	   {
  			CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModBlockSec... \n",NULL,p_intl_env_data_struct_h);
 		}

	   DL_ModDBBlockSec(p_dl_blk_sec_struct_h,p_blk_ref_no,p_intl_env_data_struct_h ,l_debug_info_ptr);	

	  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 		{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModBlockSec... \n",NULL,p_intl_env_data_struct_h);
 		}
	   
		int_retval = CR_Chk_CodeInChld(
				l_key_codes,
				l_key_values,
				g_blk_chld_table_names,
				p_intl_env_data_struct_h,
				l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
		{
			CO_InsertErr(
					l_debug_info_ptr,
					ERR_MAP_BLK_SEC_CHLD_EXIST_CANTDEL,
					"Mapping Block Securities Child Details Exist",
					p_dl_blk_sec_struct_h->h_blk_ref_no,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL				  
		
		DL_ModDBBlockSec(p_dl_blk_sec_struct_h,p_blk_ref_no,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
    else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModBlockSec... \n",NULL,p_intl_env_data_struct_h);
 		}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDBBlockSec(p_dl_blk_sec_struct_h,p_blk_ref_no,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
  {
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModBlockSec... \n",NULL,p_intl_env_data_struct_h);
 		}

      if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDBBlockSec(p_dl_blk_sec_struct_h,p_blk_ref_no,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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


int DL_ModBlockSecDet(DL_BLK_SEC_DET_STRUCT_H *p_dl_blk_sec_det_struct_h,char *p_access_stamp, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/* Variable Declarations */
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

		/* Mandatory Data Missing Checks - Generic */
 	
	 g_blk_chld_table_names[0] = "DL_BLK_SEC_DET";
 	 g_blk_chld_table_names[1] = APL_NULL_STRING;
 	 g_blk_mst_key_codes[0] = "BLK_REF_NO";
 	 g_blk_mst_key_codes[1] = APL_NULL_STRING;
	 strcpy(g_blk_mst_table_name,"DL_BLK_SEC"); 
	

	 l_key_codes[0]="INSTR_CODE";
	 l_key_codes[1]="DEPO_CODE";
	 l_key_codes[2]="BLK_DATE";
	 l_key_codes[3]="BLK_TYPE";
	 l_key_codes[4]=APL_NULL_STRING;

	 l_key_values[0]=p_dl_blk_sec_det_struct_h->h_instr_code;
	 l_key_values[1]=p_dl_blk_sec_det_struct_h->h_depo_code;
	 l_key_values[2]=p_dl_blk_sec_det_struct_h->h_blk_date;
	 l_key_values[3]=p_dl_blk_sec_det_struct_h->h_blk_type;
	 l_key_values[4]=APL_NULL_STRING;

	 int_retval = CR_Chk_AllMandData( l_key_codes,
			l_key_values,
			4,
			l_debug_info_ptr);

		
	int_retval = CO_Chk_ValidBlkDet(p_dl_blk_sec_det_struct_h,l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL
		
			
	/* Mandatory Data Missing Checks - For Numbers */
		
	if (p_dl_blk_sec_det_struct_h->h_qty == 0)
	{
		APL_DATA_MISSING("Qty cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	/* Mandatory Data Missing Checks - Mode Specific */

	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_blk_sec_det_struct_h->h_access_stamp))
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

		/* Setting Values for Mode Specific Checks   */
		strcpy(chr_l_table_name,"DL_BLOCK_SEC_DET");

		if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
				(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)  )
		{
			chr_l_rec_iexist = 'Y';
			chr_l_rec_ideleted = 'N';
			chr_l_rec_iauthorized = APL_NULL_CHAR;
		}
		else if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0))
		{
			chr_l_rec_iexist = 'Y';
			chr_l_rec_ideleted = APL_NULL_CHAR;
			chr_l_rec_iauthorized = 'N';
		}
		else if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0))
		{
			chr_l_rec_iexist = 'Y';
			chr_l_rec_ideleted = 'Y';
			chr_l_rec_iauthorized = 'N';
		}

		l_key_codes[0]= "BLK_REF_NO";
		l_key_codes[1]= APL_NULL_STRING;

		l_key_values[0]= p_dl_blk_sec_det_struct_h->h_blk_ref_no;
		l_key_values[1]= APL_NULL_STRING;
		
			
		if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT))
		{

			int_retval = CO_Chk_ChldValid(l_key_codes,
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
				CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModBlockSecDet... \n",NULL,p_intl_env_data_struct_h);
			}

			DL_ModDBlockSecDet(p_dl_blk_sec_det_struct_h,p_access_stamp,p_intl_env_data_struct_h ,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModBlockSecDet... \n",NULL,p_intl_env_data_struct_h);
			}

			DL_ModDBlockSecDet(p_dl_blk_sec_det_struct_h,p_access_stamp,p_intl_env_data_struct_h ,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModBlockSecDet... \n",NULL,p_intl_env_data_struct_h);
			}
			
			DL_ModDBlockSecDet(p_dl_blk_sec_det_struct_h,p_access_stamp,p_intl_env_data_struct_h ,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModBlockSecDet... \n",NULL,p_intl_env_data_struct_h);
			}

			if (int_retval_mkrchkr !=APL_SUCCESS)
				APL_GOBACK_FAIL

			DL_ModDBlockSecDet(p_dl_blk_sec_det_struct_h,p_access_stamp,p_intl_env_data_struct_h ,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModBlockSecDet... \n",NULL,p_intl_env_data_struct_h);

			}

			if (int_retval_mkrchkr !=APL_SUCCESS)
				APL_GOBACK_FAIL

					DL_ModDBlockSecDet(p_dl_blk_sec_det_struct_h,p_access_stamp,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

