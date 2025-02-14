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
 * File Name           :      MT_ProcAddLn_Det.c
 *
 * Description         :      This file contains functions for updating
 *                            Client Additional Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author           Description       RFS No.
 * ---------   --------  ------------      -------------     ---------
 * 20/02/2006   1.0       Kouser Begum        New file        KB_001
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int MT_ProcAddLnDet (MT_CLN_ADDLN_DET_STRUCT_H *p_mt_cln_addln_det_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */

   #define NO_OF_PRIMARY_KEYS 1

	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[2];
	char  *l_key_values[2];	
	char  chr_l_table_name[50];
	char  chr_lst_table_name[25];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	short l_int_retval = 0;
	int int_retval_mkrchkr  = APL_SUCCESS;
	char l_field_name[30] = APL_NULL_STRING;
	char p_field_ind[5] = APL_NULL_STRING;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	l_key_codes[0]="CLN_CODE";
	l_key_codes[1]=APL_NULL_STRING;
	
	l_key_values[0]=p_mt_cln_addln_det_struct_h -> h_cln_code;
	l_key_values[1]=APL_NULL_STRING;

   strcpy(l_field_name,"STATUS");
	strcpy(chr_lst_table_name,"MT_CLIENT");


   if (strlen(p_mt_cln_addln_det_struct_h->h_cln_code) == 0)
   {
      APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
   }
   printf("Check value ==|%s|\n",p_mt_cln_addln_det_struct_h->h_fund_acc_mgr);

   /* Mandatoty check - FUND ACCOUNT MANAGER - Kouser */
	
   if (((strlen(p_mt_cln_addln_det_struct_h->h_fund_acc_mgr) == 0) && (!strcmp(p_intl_env_data_struct_h->h_process, "U") == 0)) ||
        ((strlen(p_mt_cln_addln_det_struct_h->h_fund_acc_mgr) == 0) && (strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))
      
   {
      APL_DATA_MISSING("FUND ACCOUNT MANAGER",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
   }


if ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) != 0))
	{


        if ((!strlen(p_mt_cln_addln_det_struct_h->h_cert_pub_acc)) && (strlen(p_mt_cln_addln_det_struct_h->h_sec_cert_pub_acc)))
			{
			  
					CO_InsertErr(  l_debug_info_ptr,
                                    PRIMARY_CERT_PUB_ACC_MANDATORY,  
                                     APL_NULL_STRING,
                                     APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    __LINE__,
                                   __FILE__);	
                         APL_GOBACK_FAIL

				
			}
			if (strlen(p_mt_cln_addln_det_struct_h->h_fatca1) != 0)
			{ 	
				if((strcmp(p_mt_cln_addln_det_struct_h->h_fatca1,"Y")) && (strcmp(p_mt_cln_addln_det_struct_h->h_fatca1,"N")))
				{
					CO_InsertErr(l_debug_info_ptr,
							INVALID_FATCA_RECEIVED,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ );
					APL_GOBACK_FAIL;
				}
				
			}
			if (strlen(p_mt_cln_addln_det_struct_h->h_fatca2) != 0)
			{ 	
				if((strcmp(p_mt_cln_addln_det_struct_h->h_fatca2,"Y")) && (strcmp(p_mt_cln_addln_det_struct_h->h_fatca2,"N")))
				{
					CO_InsertErr(l_debug_info_ptr,
							INVALID_FATCA_RECEIVED,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ );
					APL_GOBACK_FAIL;
				}
				
			}
			if (strlen(p_mt_cln_addln_det_struct_h->h_fatca3) != 0)
			{ 	
				if((strcmp(p_mt_cln_addln_det_struct_h->h_fatca3,"Y")) && (strcmp(p_mt_cln_addln_det_struct_h->h_fatca3,"N")))
				{
					CO_InsertErr(l_debug_info_ptr,
							INVALID_FATCA_RECEIVED,
							APL_NULL_STRING,
							APL_NULL_STRING,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ );
					APL_GOBACK_FAIL;
				}
				
			}   

	}

 

  	/*CHITRLEKHA Client Additional Details STARTS*/
	if (strlen(p_mt_cln_addln_det_struct_h->h_sec_cert_pub_acc) != 0)
	   {
		   
		if ((strlen(p_mt_cln_addln_det_struct_h->h_effective_dt) == 0 )&& ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) ||
            ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan*/
			{
			  APL_DATA_MISSING("EFFECTIVE DATE",APL_NULL_STRING,APL_NULL_STRING);
			  int_error_flag = APL_FAILURE;
			}
			if(strcmp(p_mt_cln_addln_det_struct_h -> h_cert_pub_acc,p_mt_cln_addln_det_struct_h -> h_sec_cert_pub_acc) == 0)
			{
				CO_InsertErr(l_debug_info_ptr,
							ERR_PCPA_SHLD_NTBE_CPCA,
							p_mt_cln_addln_det_struct_h -> h_cert_pub_acc,
							p_mt_cln_addln_det_struct_h -> h_sec_cert_pub_acc,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ );
				APL_GOBACK_FAIL
				Alert("PCPA |%s| should not be same as SPCA |%s|\n",p_mt_cln_addln_det_struct_h -> h_cert_pub_acc,p_mt_cln_addln_det_struct_h -> h_sec_cert_pub_acc);
			}
	   }

	
   /*CHITRLEKHA Client Additional Details ENDS*/
   
     if (strlen(p_mt_cln_addln_det_struct_h->h_cln_code) != 0)
	  {
          printf("Inside the Client Code Check\n");
			 printf("Val of client code ==%s\n",p_mt_cln_addln_det_struct_h->h_cln_code);
          int_retval = CR_Chk_MasterField( p_field_ind,
                                           l_field_name,
                                           l_key_codes,
                                           l_key_values,	
                                           chr_lst_table_name,
                                           p_intl_env_data_struct_h,
	                                        l_debug_info_ptr);
        
           if (strcmp(p_field_ind,APL_STS_AUTH) != 0)
			  {
			                           CO_InsertErr(  l_debug_info_ptr,
                                    ERR_CLNCD_UNAUTHED_CANT_INP,  
                                     APL_NULL_STRING,
                                     APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    __LINE__,
                                   __FILE__);	
                         APL_GOBACK_FAIL
            }
    }



     if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
     {
       if ((strlen(p_mt_cln_addln_det_struct_h->h_acc_opn_dt) !=0) && (strlen(p_mt_cln_addln_det_struct_h->h_acc_cls_dt) != 0))
	        {
             l_int_retval = CR_Chk_ExpDateValid(p_mt_cln_addln_det_struct_h->h_acc_opn_dt,p_mt_cln_addln_det_struct_h->h_acc_cls_dt,l_debug_info_ptr);
   
        if (l_int_retval == APL_RECS_EXIST)
        {
           CO_InsertErr(l_debug_info_ptr,
	                     ERR_OPNDT_GRTCLSDT_CANT_INP,
	                     APL_NULL_STRING,
	                     APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
	                     APL_GOBACK_FAIL
	     }
	     }	 

       if ((strlen(p_mt_cln_addln_det_struct_h->h_acc_actv_dt) !=0) && (strlen(p_mt_cln_addln_det_struct_h->h_acc_cls_dt) != 0))
	        {
             l_int_retval = CR_Chk_ExpDateValid(p_mt_cln_addln_det_struct_h->h_acc_actv_dt,p_mt_cln_addln_det_struct_h->h_acc_cls_dt,l_debug_info_ptr);
   
        if (l_int_retval == APL_RECS_EXIST)
        {
           CO_InsertErr(l_debug_info_ptr,
	                     ERR_ATDT_GRTCLSDT_CANT_INP,
	                     APL_NULL_STRING,
	                     APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
	                     APL_GOBACK_FAIL
	     }
	     }	 
     }

	/*	Mandatory Data Missing Checks	- Mode Specific */

 if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT)) & (strcmp(p_intl_env_data_struct_h->h_process, "U")))
	{
		if (!strlen(p_mt_cln_addln_det_struct_h->h_access_stamp)) 
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
 
	strcpy(chr_l_table_name,"MT_CLN_ADDLN_DET");

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
	 printf("Checking Inside the Reset\n");
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'Y';
    chr_l_rec_iauthorized = 'N';
 } 

	l_key_codes[0]="CLN_CODE";
	l_key_codes[1]=APL_NULL_STRING;
	/*l_key_codes[NO_OF_PRIMARY_KEYS + 1]=APL_NULL_STRING;*/
	
	l_key_values[0]=p_mt_cln_addln_det_struct_h -> h_cln_code;
	l_key_values[1] = APL_NULL_STRING;
	/*l_key_values[NO_OF_PRIMARY_KEYS + 1] = APL_NULL_STRING;*/

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


 if((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET) == 0))
	{
		 printf("Checking Inside the ResetII\n");
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
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ProcAddLnDet... \n",NULL,p_intl_env_data_struct_h);
 	}
     printf("INSERT CHK\n");
	  
		MT_UpdMT_CLN_ADDLN_DET(p_mt_cln_addln_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ProcAddLnDet... \n",NULL,p_intl_env_data_struct_h);
 	}

	   MT_UpdMT_CLN_ADDLN_DET(p_mt_cln_addln_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ProcAddLnDet... \n",NULL,p_intl_env_data_struct_h);
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
                   MAP_INSTR_EXIST_CANTDEL,	// Need to change this 
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   MT_UpdMT_CLN_ADDLN_DET(p_mt_cln_addln_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ProcAddLnDet... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_UpdMT_CLN_ADDLN_DET(p_mt_cln_addln_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ProcAddLnDet... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   MT_UpdMT_CLN_ADDLN_DET(p_mt_cln_addln_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
