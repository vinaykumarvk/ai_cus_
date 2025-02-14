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
 * File Name           :      MT_ProcDL_BCN.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 12/01/2006   1.0       Sundar        New file       HDFCDL_004
 *
 *********************************************************************/


#define PURE_C_SOURCE
#define APL_COUNTRY_CODE "IN"
#define APL_COUNTRY_CD    "XX"
#define APL_FUNC_NSCCL   "NSCCL"
#define APL_FUNC_BOISL   "BOISL"

#include "CO_HostStructdef.h" 
#include "Intellect_Common.h"

int DL_ModDL_BCN (DL_BCN_STRUCT_H *p_dl_bcn_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/*	Variable Declarations */
	int int_error_flag = APL_SUCCESS;

	char  *l_key_codes[9];
	char  *l_key_values[9];	
	char  chr_l_table_name[50];
        char l_str_mcscclcode[21]; //added by deependra
        char h_MapValue[11]; //added by deependra
     int  l_int_l_holexists;
	 int  l_int_l_datecmp;
	 int   l_int_retval;
	 double l_CurrPosn = 0;
	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	/* char  *l_linked_table_names[MAX_NO_OF_LINKED_TABLES]={APL_NULL_STRING};*/
	char l_mkt_type[21] = APL_NULL_STRING;

	int int_retval = APL_SUCCESS;
	int int_retval_mkrchkr  = APL_SUCCESS;
	/* Debug statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/*	Mandatory Data Missing Checks	- Generic */
/* added by amish-- no check in case of deletion of repair queue --09/05*/
	if(p_intl_env_data_struct_h->h_process[0] != 'D')
	{	
		printf("\n/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\\/\/\n");
	l_key_codes[0]="CONTRACT_CD";
                           /* chgs by amish --mkt type not mandatory for off market so considered seperatly */
	/*
	l_key_codes[1]="MKT_TYPE";
	*/
	l_key_codes[1]="DEAL_CD";
	l_key_codes[2]="SEBI_REG_NO";
	l_key_codes[3]="BROKER_CD";
	l_key_codes[4]="CLIENT_CD";
	l_key_codes[5]="INSTR_CD";
	l_key_codes[6]="ENTRY";
	/**l_key_codes[8]="COUNTER_PTY";**/
	l_key_codes[7]="OFF_MARKET";
	l_key_codes[8]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_bcn_struct_h -> h_contract_cd;
	/*
	l_key_values[1]=p_dl_bcn_struct_h -> h_mkt_type;
	*/
	l_key_values[1]=p_dl_bcn_struct_h -> h_deal_cd;
	l_key_values[2]=p_dl_bcn_struct_h -> h_sebi_reg_no;
	l_key_values[3]=p_dl_bcn_struct_h -> h_broker_cd;
	l_key_values[4]=p_dl_bcn_struct_h -> h_client_cd;
	l_key_values[5]=p_dl_bcn_struct_h -> h_instr_cd;
	l_key_values[6]=p_dl_bcn_struct_h -> h_entry;
	/**l_key_values[8]=p_dl_bcn_struct_h -> h_counter_pty;**/
	l_key_values[7]=p_dl_bcn_struct_h -> h_off_market;
	l_key_values[8] = APL_NULL_STRING;

	
		int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 8,
                                 l_debug_info_ptr);
 
	if (int_retval !=APL_SUCCESS) 
      APL_GOBACK_FAIL
	
		IF_COND_EXISTS("DL_BCN","TRAN_TYPE")
		{
			if(!strlen(p_dl_bcn_struct_h -> h_tran_type))
			{
			APL_DATA_MISSING("Tran_Type",APL_NULL_STRING,APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
			}
		}
		
      
     /*chgs by amish--since condition based so considered separetly  27/04*/   
		if(strcmp(p_dl_bcn_struct_h -> h_off_market,"Y"))	
		{	printf("\nAMISH**************\n");	
			if(!strlen(p_dl_bcn_struct_h -> h_mkt_type))
				{
					printf("\nAMISH**************22222222222222222\n");
					APL_DATA_MISSING("Mkt Type",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
		}
  	
	   if(!strcmp(p_dl_bcn_struct_h->h_entry,"S"))  /* chgd by amish--below check only for messages 27/04*/
		{
			if(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE)) /* changed by sundar - 050506 ****/
			{
				if(strncmp(p_dl_bcn_struct_h -> h_contract_cd,"A",1))
				{
					if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_CONTRACT_CD_DOESNOT_STARTS_A_B,
								APL_NULL_STRING, APL_NULL_STRING,
								APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
						APL_GOBACK_FAIL
					}
				}
			}
		}

  /* added by deependra - start */

        memset(l_str_mcscclcode,APL_NULL_CHAR,21);
        memset(h_MapValue,APL_NULL_CHAR,11);

strcpy(h_MapValue,"MCS_CCL_CD");

           if (  CO_Rtv_FldValChar(   "map_val",
                                      "PRO_SGENSTAT",
                                      "map_type",
                                       h_MapValue,
                                       l_str_mcscclcode,
                                       l_debug_info_ptr )==APL_FAILURE)
             APL_GOBACK_FAIL

printf("\n 174 l_str_mcscclcode = [%s] \n",l_str_mcscclcode);

/* added by deependra - end */

		if (strlen(p_dl_bcn_struct_h->h_counter_pty) != 0)
		{
			if (strcmp(p_dl_bcn_struct_h->h_clh_flg,"C") == 0 )
			{
				if((strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_NSCCL) != 0) &&
                                   (strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_BOISL)    != 0) && 
                                   (strcmp(p_dl_bcn_struct_h->h_counter_pty,l_str_mcscclcode) != 0)   )
				{
					if( CO_InsertErr(l_debug_info_ptr,ERR_BCN_MISMATCHED_DATA,
								APL_NULL_STRING, APL_NULL_STRING,
								APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
						APL_GOBACK_FAIL
					}
				}
			}
			if (strcmp(p_dl_bcn_struct_h->h_clh_flg,"D") == 0 )
			{
				if((strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_NSCCL) == 0) ||
                                   (strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_BOISL)    == 0) ||
                                   (strcmp(p_dl_bcn_struct_h->h_counter_pty,l_str_mcscclcode) == 0)   )
				{
					if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_MISMATCHED_DATA,
								APL_NULL_STRING, APL_NULL_STRING,
								APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
						APL_GOBACK_FAIL
					}
				}
			}
	
	
			if(strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_NSCCL) == 0)
			{
				if(strcmp(p_dl_bcn_struct_h->h_exch_cd,"BSE") == 0)
				{
					if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_BSE,
								APL_NULL_STRING, APL_NULL_STRING,
								APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
						APL_GOBACK_FAIL
					}
				}
			}
			if(strcmp(p_dl_bcn_struct_h->h_counter_pty,APL_FUNC_BOISL) == 0)
			{
				if(strcmp(p_dl_bcn_struct_h->h_exch_cd,"NSE") == 0)
				{
					if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_NSE,
								APL_NULL_STRING, APL_NULL_STRING,
								APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
						APL_GOBACK_FAIL
					}
				}
			}	

/* ADDED BY DEEPENDRA - START */

                        if(strcmp(p_dl_bcn_struct_h->h_counter_pty,l_str_mcscclcode) == 0)
                        {
                                if(strcmp(p_dl_bcn_struct_h->h_exch_cd,"MCS") != 0)
                                {
                                        if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_OTHER_THAN_MCS,
                                                                APL_NULL_STRING, APL_NULL_STRING,
                                                                APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
                                        {
                                                APL_GOBACK_FAIL
                                        }
                                }
/* ADDED BY DEEPENDRA - END */

                        }
		}
	 /*	
		if(!strcmp(p_dl_bcn_struct_h -> h_off_market,"Y"))
		*/
		 /*chgs by amish--since settlement no is non mandatory for clh fld "D" 27/04 */       
		if(!strcmp(p_dl_bcn_struct_h ->h_clh_flg,"D"))																 
			{
				if (!strlen(p_dl_bcn_struct_h->h_dl_date)) 
				{
					APL_DATA_MISSING("deal date",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
				if (!strlen(p_dl_bcn_struct_h->h_sett_dt)) 
				{
					APL_DATA_MISSING("Settlement date",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
			}
			else
			{
				if (!strlen(p_dl_bcn_struct_h->h_clh_flg)) 
				{
					APL_DATA_MISSING("clearing house flag",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
				if (!strlen(p_dl_bcn_struct_h->h_settlement_no)) 
				{
					APL_DATA_MISSING("settlement no",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
				if (!strlen(p_dl_bcn_struct_h->h_exch_cd)) 
				{
					APL_DATA_MISSING("Exchange code",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}

    		  l_int_retval = CO_Chk_CodeValid ("EXCHANGE",p_dl_bcn_struct_h->h_exch_cd,APL_COUNTRY_CODE,l_debug_info_ptr);

		      if (l_int_retval !=APL_SUCCESS)
		      {
			       if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_EXCH_CD_NOT_EXIST,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			      {
				    APL_GOBACK_FAIL
			      }
		      }
			}
	  


	/*	Mandatory Data Missing Checks	- For Numbers */

			if((!strcmp(p_dl_bcn_struct_h->h_deal_cd,APL_DEAL_DVP)) || (!strcmp(p_dl_bcn_struct_h->h_deal_cd,APL_DEAL_RVP)))
			{
      if (p_dl_bcn_struct_h->h_dl_price==0) {APL_DATA_MISSING("deal price",APL_NULL_STRING,APL_NULL_STRING);
	      int_error_flag = APL_FAILURE;}
			}

			if((!strcmp(p_dl_bcn_struct_h->h_deal_cd,APL_DEAL_DVP)) || (!strcmp(p_dl_bcn_struct_h->h_deal_cd,APL_DEAL_RVP)))
			{
				if (p_dl_bcn_struct_h->h_dl_amt==0) 
				{
					APL_DATA_MISSING("deal ammount",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
/*			if (p_dl_bcn_struct_h->h_brokerage_amt==0) 
				{
					APL_DATA_MISSING("Brokerage ammount",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
				if (p_dl_bcn_struct_h->h_stt_amt==0) 
				{
					APL_DATA_MISSING("settlement tax amt",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
*/
				if (p_dl_bcn_struct_h->h_settlment_amt==0) 
				{
					APL_DATA_MISSING("settlement ammount",APL_NULL_STRING,APL_NULL_STRING);
					int_error_flag = APL_FAILURE;
				}
			}

		  l_int_retval=0;

		  l_int_retval = CR_Chk_ValAtBCN(p_dl_bcn_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

		  if(l_int_retval !=APL_SUCCESS)
		  {
			  APL_GOBACK_FAIL

				  int_error_flag = APL_FAILURE;
		  }


          if (APL_FAILURE ==CO_Chk_Holiday(p_dl_bcn_struct_h->h_dl_date,&l_int_l_holexists,l_debug_info_ptr,p_dl_bcn_struct_h->h_exch_cd))
		  {
			  APL_GOBACK_FAIL
		  }

		  if ( l_int_l_holexists > 0)
		  {
			  if( CO_InsertErr(l_debug_info_ptr, ERR_DEAL_DATE_IS_HOLIDAY,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			  {
				  APL_GOBACK_FAIL
			  }
		  }

		  l_int_l_holexists = 0;
		  if (APL_FAILURE ==CO_Chk_Holiday(p_dl_bcn_struct_h->h_sett_dt,&l_int_l_holexists,l_debug_info_ptr,p_dl_bcn_struct_h->h_exch_cd))
		  {
			  APL_GOBACK_FAIL
		  }

		  if ( l_int_l_holexists > 0)
		  {
			  if( CO_InsertErr(l_debug_info_ptr, ERR_SETT_DATE_IS_HOLIDAY,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			  {
				  APL_GOBACK_FAIL
			  }
		  }
		  if(APL_SUCCESS != CO_Pro_DateComp(p_dl_bcn_struct_h->h_sett_dt,p_dl_bcn_struct_h->h_dl_date,&l_int_l_datecmp,l_debug_info_ptr))
		  {
			  APL_GOBACK_FAIL
		  }

		  if(l_int_l_datecmp > 0)
		  {
			  if( CO_InsertErr(l_debug_info_ptr, ERR_DEALDT_GREATER_SETTDT,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			  {
				  APL_GOBACK_FAIL
			  }
		  }


		  /*
		  l_int_retval = 0;
		  l_int_retval = CO_Chk_CodeValid ("TRANSTYPE",p_dl_bcn_struct_h->h_tran_type,APL_COUNTRY_CODE,l_debug_info_ptr);

		  if (l_int_retval !=APL_SUCCESS)
		  {
			  if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_TRANS_TYPE_NOT_EXIST,
						  APL_NULL_STRING, APL_NULL_STRING,
						  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			  {
				  APL_GOBACK_FAIL
			  }
		  } */
		  l_int_retval = 0;

        if(strcmp(p_dl_bcn_struct_h -> h_off_market,"Y")) /*chngs by amish-mkt type null for off market--27/04 */
		  {
			  memset(l_mkt_type,APL_NULL_CHAR,21);
		 	  strcpy(l_mkt_type,"MKT_TYP_");
			  strcat(l_mkt_type,p_dl_bcn_struct_h->h_exch_cd);
			  strcat(l_mkt_type,APL_NULL_STRING);
			  printf("l_mkt_type is %s\n",l_mkt_type);
			  l_int_retval = CO_Chk_CodeValid (l_mkt_type,p_dl_bcn_struct_h->h_mkt_type,
					  APL_COUNTRY_CODE,l_debug_info_ptr);

			  if (l_int_retval !=APL_SUCCESS)
			  {
				  if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_MKT_TYP_NOT_EXIST,
							  APL_NULL_STRING, APL_NULL_STRING,
							  APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			 	 {
					  APL_GOBACK_FAIL
			 	 }
		  	 }
		  }


	}
	/*	Mandatory Data Missing Checks	- Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		if (!strlen(p_dl_bcn_struct_h->h_access_stamp)) 
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
	strcpy(chr_l_table_name,"DL_BCN");

/* printf("\n $$$$$$$$$$$$$$$$ MODE = |%s|  $$$$$$$$$$$$$$$$$\n",p_intl_env_data_struct_h->h_mode);  */
 if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0) ||
	 (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_REPAIR) == 0))
 {
    chr_l_rec_iexist = 'N';
    chr_l_rec_ideleted = APL_NULL_CHAR;
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 }
 else if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0) )
		/*	 (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_SEBI) == 0) ) */
 {
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'N';
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 }
 /*** Vedavati - Changes made for RegReports ***/
 else if((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_SEBI) == 0) )
 {
    printf("\n*********inside if veda **********\n");
	 chr_l_rec_iexist = 'Y';
    printf("\n ***********exist flag : |%c|\n", chr_l_rec_iexist);
	 chr_l_rec_ideleted = APL_NULL_CHAR;
    printf("\n **********deleted flag : |%c|\n", chr_l_rec_ideleted);
    chr_l_rec_iauthorized = APL_NULL_CHAR;
    printf("\n **********authorized flag : |%c|\n", chr_l_rec_iauthorized);
 }
 /*******************/
/**********Chirag *****For DVP***********************************/
 else if((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MRK_DVP) == 0) )
 {
	 printf("*******************Calling Function For Mark DVP***************************\n");
 }
/************Chirag FOr DVP Mark***********************************/	 
 else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) || 
		       (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_OVERRIDE) == 0)) 
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
/* added by amish-- no check in case of deletion of repair queue --09/05 */
 if(p_intl_env_data_struct_h->h_process[0] != 'D')
 {
	l_key_codes[0]="CONTRACT_CD";
	l_key_codes[1]="DL_DATE";
	l_key_codes[2]="BROKER_CD";
	l_key_codes[3]=APL_NULL_STRING;
	
	l_key_values[0]=p_dl_bcn_struct_h -> h_contract_cd;
	l_key_values[1]=p_dl_bcn_struct_h -> h_dl_date;
	l_key_values[2]=p_dl_bcn_struct_h -> h_broker_cd;
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
	}

 if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)) || (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_OVERRIDE)))
	{
       int_retval_mkrchkr = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);



	}

  /* commented by amish --02/05 --position chk not require for BCN */
	/* No posistion check for Deletion  UAT Sundar  */
	/*
	if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	{
		
		if(strcmp(p_dl_bcn_struct_h->h_status,"DU"))
		{
			if((p_dl_bcn_struct_h->h_deal_cd[0] == '1') || (p_dl_bcn_struct_h->h_deal_cd[0] == '3'))
			{
				printf("\n**************AMISH********ENTERIN POSITION CHK FUNCTION\n");
				if ( APL_FAILURE == DL_Chk_AvlPos(  p_dl_bcn_struct_h->h_client_cd,
							p_dl_bcn_struct_h->h_instr_cd,
							"NSDL",
							'Y','N','Y','N','Y','N','N','N',"FREE",
							&l_CurrPosn,
							l_debug_info_ptr) )
				{
					APL_GOBACK_FAIL;
				}

				if ( l_CurrPosn < p_dl_bcn_struct_h->h_qty )
				{
					if (  CO_InsertErr(  l_debug_info_ptr,
								ERR_DEAL_NENUFPOSN,
								p_dl_bcn_struct_h->h_client_cd,
								p_dl_bcn_struct_h->h_instr_cd,
								APL_NULL_STRING,
								__LINE__,
								__FILE__ ) == APL_FAILURE )
					{
						APL_GOBACK_FAIL;
					}
					int_error_flag = APL_FAILURE;
				}
			}
		}
	}
*/
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered input mode of DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
 	}
		/* Changes:Isolve-306:AmitB:280507	*/
		if(DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr)==APL_FAILURE)
		{
			APL_GOBACK_FAIL
		}

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MRK_DVP))
 {
	 APL_IF_DEBUG
	 {
		 CO_ProcMonitor(APL_OUT_FILE, "Entered DVP mode of  DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
	 }
 		DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
 	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 	{
		 APL_GOBACK_FAIL
 	}
}
 else if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))||(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_SEBI)))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode of DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
 	}
		/* Changes:Isolve-306:AmitB:040607	*/
	   if(DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr)==APL_FAILURE)
		{
			APL_GOBACK_FAIL
		}

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	}
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode of DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
 	}
		
	   DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }
  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode of DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
 	}


    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	 {
		APL_IF_DEBUG
 	{
  		CO_ProcMonitor(APL_OUT_FILE, "Entered reset mode of DL_ModDL_BCN... \n",NULL,p_intl_env_data_struct_h);
 	}

    if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

  	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
   	{
   		APL_GOBACK_FAIL
   	}
	 }

	 	if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_REPAIR))
	{

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered  reapire h_mode of DL_ModDL_BCN... \n",
					NULL,p_intl_env_data_struct_h);
		}

		  DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}

		if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_OVERRIDE))
	{

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered  override h_mode of DL_ModDL_BCN... \n",
					NULL,p_intl_env_data_struct_h);
		}

		if (int_retval_mkrchkr !=APL_SUCCESS)
         APL_GOBACK_FAIL

	   DL_ModDbDL_BCN(p_dl_bcn_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);	

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
