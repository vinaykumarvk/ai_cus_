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
 * File Name           :      MT_ModDbDL_TAKEOVER.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 23/01/2006   1.0       Sonal        New file       HDFCDL_025
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 
#include <strings.h> 

int MT_UpdDL_TAKEOVER (DL_TAKEOVER_STRUCT_H *p_dl_takeover_struct_h,DL_TAKEOVER_SEQ_STRUCT_H *p_dl_takeover_seq_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[4] ;
	char  *l_key_values[4];	
	char  chr_l_table_name[50]=APL_NULL_STRING;
	char self[10]=APL_NULL_STRING;
	
	char chr_l_rec_iexist=APL_NULL_CHAR;
	char chr_l_rec_ideleted=APL_NULL_CHAR;
	char chr_l_rec_iauthorized=APL_NULL_CHAR;

	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */
	/*	
	l_key_codes[0]="CI_NO";
	*/
	printf("\nuser is |%s|\n",p_intl_env_data_struct_h->usr);
if(!(!(strcmp(p_intl_env_data_struct_h->h_process,"U")) && !(strcmp(p_intl_env_data_struct_h->h_mode , APL_FUNC_INPUT))))              /* Upload Takeover - [Retrofit HDFC]  */
	{
		printf("\n BEFORE MANDATORY CHKS \n");
	l_key_codes[0]="REF_NO";
	l_key_codes[1]="INSTR_CD";
	l_key_codes[2]="DEPOSITORY";
	l_key_codes[3]=APL_NULL_STRING;

	l_key_values[0]=p_dl_takeover_struct_h->h_ref_no;
	l_key_values[1]=p_dl_takeover_struct_h->h_instr_cd;
	l_key_values[2]=p_dl_takeover_struct_h->h_depository;
	l_key_values[3] =APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
									 l_key_values,
									 3,
									l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
		APL_GOBACK_FAIL
	}

	/*	Mandatory Data Missing Checks	- For Numbers */
   printf("\n the qty is |%f| \n",p_dl_takeover_struct_h->h_qty);
   if (p_dl_takeover_struct_h->h_qty == 0)
	{
      APL_DATA_MISSING("Qty cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
	

if(!(strcmp(p_intl_env_data_struct_h->h_process,"U")) && !(strcmp(p_intl_env_data_struct_h->h_mode , APL_FUNC_INPUT)))    /* Upload Takeover - [Retrofit HDFC] */
	{

		if (p_dl_takeover_struct_h->h_takeover_qty == 0)
		p_dl_takeover_struct_h->h_takeover_qty  = p_dl_takeover_struct_h->h_qty;
	}

	if (p_dl_takeover_struct_h->h_takeover_qty == 0)
	{
      APL_DATA_MISSING("Takeover Qty cannot be 0",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
	
   printf("\n The mode is %s \n",p_intl_env_data_struct_h->h_mode);	
	/*	Mandatory Data Missing Checks	- Mode Specific */
	/*
   strcpy(self,p_intl_env_data_struct_h->h_mode);
*/

	
/*************SONAL***********************/
	/*	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT)==0)
	{
		printf("\n I have entered the inp mode\n");
      chr_l_rec_iexist = 'Y';
      chr_l_rec_ideleted = 'N';
	   chr_l_rec_iauthorized = APL_NULL_CHAR;	 	
		
		if (!strlen(p_dl_takeover_struct_h->h_accesstamp)) 
		{
			APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;
		}
     APL_IF_DEBUG
		{
		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
		}
       printf("\n I am about to call MT_ModDbDL_TAKEOVER\n");
       MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);
		printf("\n I have called MT_ModDbDL_TAKEOVER\n");
		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		{
			APL_FAILURE;
		}
                                                           
		
	}*/

/***************ADDED BY AMISH******************/

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_takeover_struct_h->h_accesstamp)) 
		{
			APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;
		}
	}
/************************************************************/

	if ((int_retval !=APL_SUCCESS) || (int_error_flag == APL_FAILURE))	
      APL_GOBACK_FAIL

	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
	{
 		APL_FAILURE;
	 }
	printf("\n AFTER MANDATORY CHECKS \n");
	/*	Setting Values for Mode Specific Checks	*/  
	strcpy(chr_l_table_name,"DL_TAKEOVER");

/**************************COMMENTED BY AMISH ********************/
/*
    if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	  {
        	printf("rakesh \n");
			printf("ACCESS STAMP |%s|\n",p_dl_takeover_struct_h->h_accesstamp);
			if (!strlen(p_dl_takeover_struct_h->h_accesstamp))
			   {
					APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
            if (int_error_flag ==APL_FAILURE)
					APL_GOBACK_FAIL
			 
	  }	
*/

/*************************************************************************/                                                              
  
	 if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0) 
	
	  {
		    /*  
   			printf("to test %c | %c | %c\n",chr_l_rec_iexist,chr_l_rec_iauthorized,chr_l_rec_ideleted); 
			*/
		  		chr_l_rec_iexist = 'N';
				chr_l_rec_ideleted = APL_NULL_CHAR;
				chr_l_rec_iauthorized = APL_NULL_CHAR;
			/*
   			printf("to test %c | %c | %c\n",chr_l_rec_iexist,chr_l_rec_iauthorized,chr_l_rec_ideleted); 
			*/
	  }
 
    if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)  )
     {
			chr_l_rec_iexist = 'Y';
			chr_l_rec_ideleted = 'N';
			chr_l_rec_iauthorized = APL_NULL_CHAR;
	/*
	 printf("\nI have entered modify of .c file\n");
	 */

	 
	 }
	else if (   (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE) == 0)) 
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

	/*
   			printf("to test %c | %c | %c\n",chr_l_rec_iexist,chr_l_rec_iauthorized,chr_l_rec_ideleted); 
			*/

	
	/*  
 	l_key_values[0]=p_dl_takeover_struct_h->h_ref_no;
	l_key_values[1]=APL_NULL_STRING;
   l_key_codes[0]="REF_NO";
	l_key_codes[0]="CI_NO";
	*/
if(!(!(strcmp(p_intl_env_data_struct_h->h_process,"U")) && !(strcmp(p_intl_env_data_struct_h->h_mode , APL_FUNC_INPUT))))             /* Upload Takeover - [Retrofit HDFC] */
	{
 	l_key_codes[0]="REF_NO";
	l_key_codes[1]="SERIAL_NO";
	l_key_codes[2]=APL_NULL_STRING;
				
	l_key_values[0]=p_dl_takeover_struct_h->h_ref_no;
	l_key_values[1]=p_dl_takeover_struct_h->h_serial_no;
	l_key_values[2] =APL_NULL_STRING;
	  
		   

	CO_Chk_ChldValid(l_key_codes,
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

 if((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)==0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)==0))
	{
       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);



	}

	printf("\n MODE IS p_intl_env_data_struct_h->h_mode |%s|\n",p_intl_env_data_struct_h->h_mode);

	
 	
  		
 if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT)==0)
	{
	     APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
			}
		 printf("\n before calling  MT_ModDbDL_TAKEOVER\n");
		 MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);
		 printf("\n after  MT_ModDbDL_TAKEOVER\n");
		 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_FAILURE;
			}

	}  	
   	
   	
	
 if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY)==0)
	{

		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
		}

		printf("\n before calling  MT_ModDbDL_TAKEOVER\n");
	    MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h ,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);
	   	printf("\n after  MT_ModDbDL_TAKEOVER\n");


  		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
				 
   					APL_GOBACK_FAIL
   		}

	}
 
 else if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE)==0)
	{
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
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
            AIX - Warnings Removal - removed comment with in comment
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
	   MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h ,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);	
 /* DL_TAKEOVER_SEQ_STRUCT_H *l_dl_takeover_seq_struct_h;*/

		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{
   			APL_GOBACK_FAIL
   		}
	}
   else if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)==0)
	{
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
		}

	    if (int_retval_mkrchkr !=APL_SUCCESS)
		     APL_GOBACK_FAIL

	   MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h ,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);	
  	   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   		{		
			APL_GOBACK_FAIL
	   	}
 
	}

  else if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)==0)
	 {
		APL_IF_DEBUG
 		{
  			CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of MT_ModDbDL_TAKEOVER... \n",NULL,p_intl_env_data_struct_h);
 		}

		if (int_retval_mkrchkr !=APL_SUCCESS)
			 APL_GOBACK_FAIL

		printf("\n before calling  reset mode \n");		
    	MT_ModDbDL_TAKEOVER(p_dl_takeover_struct_h ,p_dl_takeover_seq_struct_h,p_intl_env_data_struct_h ,l_debug_info_ptr);	
		printf("\n after   reset mode \n");		
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
