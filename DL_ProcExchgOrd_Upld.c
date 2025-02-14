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
 * File Name           :      DL_ProcExchgOrd_Upld.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 03/01/2006   1.0       Sundar        New file       HDFCDL_005
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 
#define APL_EXCHORD_NSE  "NSE"
#define APL_EXCHORD_BSE  "BSE"
#define APL_COUNTRY_CODE "IN"
#define APL_COUNTRY_CD   "XX"

int DL_ModExchgOrd_Upld (DL_EXCHGORD_UPLD_STRUCT_H *p_dl_exchgord_upld_struct_h,char *p_order_no,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;
	int l_int_l_holexists = 0;
	char l_exch_code[4];
	char  *l_key_codes[10];
	char  *l_key_values[10];	
	char  chr_l_table_name[50];
   char  *p_chr_orderno;
	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	int l_retval =0;

	p_chr_orderno = (char *)calloc(26,sizeof(char));

	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */

	l_key_codes[0]="EXCHG_CODE";
	l_key_codes[1]="DEAL_DATE";
	l_key_codes[2]="SETTL_NO";
	l_key_codes[3]="BUY_SELL_FLG";
	l_key_codes[4]="CLIENT";
	l_key_codes[5]="INSTR_CODE";
	l_key_codes[6]="CREATION_TYPE";
	l_key_codes[7]="BROKER_CD";/*Priyanka added*/
	l_key_codes[8]="EXCH_INSTR_CODE";/*Priyanka added*/
	l_key_codes[9]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_exchg_code;
	l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_deal_date;
	l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_settl_no;
	l_key_values[3]=p_dl_exchgord_upld_struct_h -> h_buy_sell_flg;
	l_key_values[4]=p_dl_exchgord_upld_struct_h -> h_cln_code;
	l_key_values[5]=p_dl_exchgord_upld_struct_h -> h_instr_code;
	l_key_values[6]=p_dl_exchgord_upld_struct_h -> h_creation_type;
	l_key_values[7]=p_dl_exchgord_upld_struct_h -> h_broker_cd;/*Priyanka added*/
	l_key_values[8]=p_dl_exchgord_upld_struct_h -> h_exch_instr_code;/*Priyanka added*/
	l_key_values[9] = APL_NULL_STRING;

	strcpy(l_exch_code,p_dl_exchgord_upld_struct_h -> h_exchg_code);
	if(!strcmp(p_dl_exchgord_upld_struct_h -> h_exchg_code,"OTR"))
	{
		l_int_l_holexists = 0;
		printf("\nMode=|%s|\n",p_intl_env_data_struct_h->h_mode);
		strcpy(p_dl_exchgord_upld_struct_h -> h_exchg_code,"NSE");
		if (APL_FAILURE ==CO_Chk_Holiday(p_dl_exchgord_upld_struct_h -> h_access_stamp,&l_int_l_holexists,l_debug_info_ptr,p_dl_exchgord_upld_struct_h -> h_exchg_code))
		{
			APL_GOBACK_FAIL
		}

		if ( l_int_l_holexists > 0)
		{
			if( CO_InsertErr(l_debug_info_ptr, ERR_DEAL_DATE_IS_HOLIDAY_EXCH,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}
	
	int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 8,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL

	int_retval=0;
	int_retval = CO_Chk_ValAtExchOrdUpld(p_dl_exchgord_upld_struct_h,l_debug_info_ptr);

	if(int_retval !=APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	printf("After CO_Chk_ValAtExchOrdUpld ");
	if (APL_FAILURE ==CO_Chk_Holiday(p_dl_exchgord_upld_struct_h -> h_deal_date,&l_int_l_holexists,l_debug_info_ptr,p_dl_exchgord_upld_struct_h -> h_exchg_code))
	{
		APL_GOBACK_FAIL
	}

	if ( l_int_l_holexists > 0)
	{
		if( CO_InsertErr(l_debug_info_ptr, ERR_DEAL_DATE_IS_HOLIDAY_EXCH,
					APL_NULL_STRING, APL_NULL_STRING,
					APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
		{
			APL_GOBACK_FAIL
		}
	}
	printf("After CO_Chk_Holiday ");
	int_retval=0;
	int_retval = CO_Chk_CodeValid ("EXCHANGE",p_dl_exchgord_upld_struct_h -> h_exchg_code,APL_COUNTRY_CODE,l_debug_info_ptr);

	if (int_retval !=APL_SUCCESS)
	{
			APL_GOBACK_FAIL
	}
/*Priyanka - UAT ISSUE - mandatory check exch_instr_code */

		if (!strlen(p_dl_exchgord_upld_struct_h->h_exch_instr_code))
		{
			APL_DATA_MISSING("Exchange Instr Code",APL_NULL_STRING,APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
/*Priyanka - UAT ISSUE - mandatory check exch_instr_code*/

	if(!strcmp(p_dl_exchgord_upld_struct_h -> h_exchg_code,APL_EXCHORD_NSE))
	{
		if (!strlen(p_dl_exchgord_upld_struct_h->h_mkt_type))
		{
			APL_DATA_MISSING("Market Type",APL_NULL_STRING,APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
		if(int_error_flag == APL_FAILURE)
		{
			APL_GOBACK_FAIL
		}

		int_retval=0;
		char code_ident[50];
	   strcpy(code_ident,"MKT_TYP_");
		strcat(code_ident,p_dl_exchgord_upld_struct_h -> h_exchg_code);	
		
		/* int_retval = CO_Chk_CodeValid (code_ident,p_dl_exchgord_upld_struct_h->h_mkt_type,g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr); OPT:AIX */
		int_retval = CO_Chk_CodeValid (code_ident,p_dl_exchgord_upld_struct_h->h_mkt_type,(char *)g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
		{
			if( CO_InsertErr(l_debug_info_ptr, ERR_EXCHORDUP_MKT_TYP_NOT_EXIST,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}
	if(!strcmp(p_dl_exchgord_upld_struct_h -> h_exchg_code,APL_EXCHORD_NSE))
	{
		if (strlen(p_dl_exchgord_upld_struct_h->h_scrip_grp)==0)
		{
			APL_DATA_MISSING("Scrip Group",APL_NULL_STRING,APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
		if(int_error_flag == APL_FAILURE)
		{
			APL_GOBACK_FAIL
		}

		int_retval=0;
		int_retval = CO_Chk_CodeValid("SCRIP_GRP",p_dl_exchgord_upld_struct_h->h_scrip_grp,APL_COUNTRY_CD,l_debug_info_ptr);

		if (int_retval !=APL_SUCCESS)
		{
			if( CO_InsertErr(l_debug_info_ptr,ERR_EXCHORDUP_SCRIP_GRP_NOT_EXIST,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}

	/*	Mandatory Data Missing Checks	- For Numbers */
	/*	Mandatory Data Missing Checks	- Mode Specific */
printf("\nAccess Stamp Checking\n");
 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_exchgord_upld_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"DL_EXCHGORD_UPLD");

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
	 /* Added by Vedavati for reset Menu in Exchange Order */
	 if(!strcmp(p_dl_exchgord_upld_struct_h->h_status,"PM"))
	 {
		 chr_l_rec_ideleted = 'N';
		 chr_l_rec_iauthorized = APL_NULL_CHAR;
	 }
 }

/* ************************changes by jeoti***************************************** */
   

 if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) != 0)
 {

	 IF_COND_EXISTS("DL_DEAL","EXCH")     //bank specific condition added by jeoti

	 {
			if(strcmp(p_dl_exchgord_upld_struct_h->h_exchg_code,"BSE") != 0)
			{

	                    l_key_codes[0]="ORDER_NO";
						l_key_codes[1]="DEAL_DATE";	   
						l_key_codes[2]="BROKER_CD";   
	                     l_key_codes[3]=APL_NULL_STRING;
	
	                    l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
						l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_deal_date;	
						l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_broker_cd;
	                    l_key_values[3] = APL_NULL_STRING;


		  
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

 else 
	 {

	l_key_codes[0]="ORDER_NO";
			l_key_codes[1]="SETTL_NO";	     
			l_key_codes[2]="BROKER_CD";      
			l_key_codes[3]=APL_NULL_STRING;  
	
	l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
			l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_settl_no;
			l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_broker_cd;
			l_key_values[3] = APL_NULL_STRING;





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


	 }



	 else

 
 {

                        l_key_codes[0]="ORDER_NO";
						l_key_codes[1]="DEAL_DATE";	   
						l_key_codes[2]="EXCHG_CODE";   
						l_key_codes[3]=APL_NULL_STRING;
						
						l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
						l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_deal_date;	
						l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_exchg_code;
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


 }


	if (int_retval !=APL_SUCCESS)
      APL_GOBACK_FAIL


 if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)))
	{

   IF_COND_EXISTS("DL_DEAL","EXCH")     //bank specific condition added by jeoti

		{

     if(strcmp(p_dl_exchgord_upld_struct_h->h_exchg_code,"BSE") != 0)

		{


                l_key_codes[0]="ORDER_NO";
				l_key_codes[1]="DEAL_DATE";	   
				l_key_codes[2]="BROKER_CD";   
				l_key_codes[3]=APL_NULL_STRING;
				
				l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
				l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_deal_date;	
				l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_broker_cd;
				l_key_values[3] = APL_NULL_STRING;






       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);



	}



	
else 
		{ 


            l_key_codes[0]="ORDER_NO";         
			l_key_codes[1]="SETTL_NO";	     
			l_key_codes[2]="BROKER_CD";      
			l_key_codes[3]=APL_NULL_STRING;  

			l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
			l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_settl_no;
			l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_broker_cd;
			l_key_values[3] = APL_NULL_STRING;



	
       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

		}

		}

		else

		{

                l_key_codes[0]="ORDER_NO";
				l_key_codes[1]="DEAL_DATE";	   
				l_key_codes[2]="EXCHG_CODE";   
				l_key_codes[3]=APL_NULL_STRING;
				
				l_key_values[0]=p_dl_exchgord_upld_struct_h -> h_order_no;
				l_key_values[1]=p_dl_exchgord_upld_struct_h -> h_deal_date;	
				l_key_values[2]=p_dl_exchgord_upld_struct_h -> h_exchg_code;
				l_key_values[3] = APL_NULL_STRING;






            int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
													 l_key_values,
													 chr_l_table_name,
													 p_intl_env_data_struct_h->usr,
													 l_debug_info_ptr);

	}

	}
/* ******************************** changes by jeoti end here **************************************** */

	/*
	if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT)) && (strstr(p_dl_exchgord_upld_struct_h->h_maker,"GFU")!=0))
	{

		int_retval = CR_Chk_If_Exists(p_dl_exchgord_upld_struct_h,l_retval,p_intl_env_data_struct_h,l_debug_info_ptr);
		printf("Return Val of Exists: |%d|\n",l_retval);
		if(l_retval==1)
		{
			strcpy(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY);

		}
	}
	*/
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModExchgOrd_Upld... \n",NULL,p_intl_env_data_struct_h);
 	}

		DL_ModDBExchgOrd_Upld(p_dl_exchgord_upld_struct_h,p_chr_orderno,l_exch_code,p_intl_env_data_struct_h ,l_debug_info_ptr);
	
	strcpy(p_order_no,p_chr_orderno);


  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModExchgOrd_Upld... \n",NULL,p_intl_env_data_struct_h);
 	}

	   DL_ModDBExchgOrd_Upld(p_dl_exchgord_upld_struct_h, p_chr_orderno ,l_exch_code, p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModExchgOrd_Upld... \n",NULL,p_intl_env_data_struct_h);
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
                   MAP_INSTR_EXIST_CANTDEL,								/* Need to change this 
    	            "Record exists in Float Rate Instrument master",
                    p_mt_dlflrate_struct_h->h_benchmark_code,
                   APL_NULL_STRING,
                   __LINE__,
                   __FILE__);
     }
     else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL
	
		*************************************************************************************/	
	   DL_ModDBExchgOrd_Upld(p_dl_exchgord_upld_struct_h,p_chr_orderno,l_exch_code,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModExchgOrd_Upld... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDBExchgOrd_Upld(p_dl_exchgord_upld_struct_h,p_chr_orderno,l_exch_code,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModExchgOrd_Upld... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL
	   DL_ModDBExchgOrd_Upld(p_dl_exchgord_upld_struct_h,p_chr_orderno,l_exch_code ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
