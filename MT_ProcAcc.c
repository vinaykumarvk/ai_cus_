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
	
 * File Name           :      MT_ProcAcc.c
 *
 * Description         :      This file contains functions for Client Details Maintenance.           *                                   It contains all functions related to                            *                                  Input/Modify/Delete/Authorise/Freeze/Unfreeze/Open/Close 	
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *10/10/2005	1.0       Kouser Begum    New file to Maintain Client Details	
 *18/01/2006   1.1       Kouser Begum    Static Data for STATECODE Changed to STATE
 *05/02/2006   1.2       Kouser Begum    Validation for Respective Modes
 *22/05/2014   1.3		Prateek Singh		ISKB_198(FPI Maintenance)
 *********************************************************************/
#define PURE_C_SOURCE
#include <CO_HostStructdef.h>
//Name of MT_CLI_FPI_MAP added in child tables name by Prateek for ISKB_198(FPI Mapping)
//char     *g_cln_chld_table_names[APL_CLIENT_CHILD_CNT + 1] = {"MT_REGDETAILS","MT_MSGADDRESS","MT_SCHDET","MT_CLI_EXCH_MAP","MT_CLI_DEPO_MAP","MT_CLI_FPI_MAP",APL_NULL_STRING};
char     *g_cln_chld_table_names[7] = {"MT_REGDETAILS","MT_MSGADDRESS","MT_SCHDET","MT_CLI_EXCH_MAP","MT_CLI_DEPO_MAP","MT_CLI_FPI_MAP",APL_NULL_STRING};

char            *g_cln_mst_key_codes[2] = {"CLN_CODE",APL_NULL_STRING};
char            *g_mst_key_values[2];
char            g_cln_mst_table_name[25] = "MT_CLIENT";

/* Kouser - HDFCMT_001 - Client Master Maintenance */

int MT_Mod_Client(MT_CLIENT_STRUCT_H *p_mt_ruclient_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int CR_Rtv_CashAccFldVal(char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          DEBUG_INFO_STRUCT_H **);


	int			int_retval;
   int         chr_link_val = 0; 
	char			chr_l_field_val[40];
   char        chr_l_ccycode[3]; 
	short			int_l_condexists;
	short			l_gronexchangecond=0;   
	char			chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char			chr_l_condid[APL_CONDID_LEN];
	char			chr_l_row_id_acct[APL_ROWID_LEN+1];
	char			chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed;
	char			chr_l_buf[BUFFER_LEN];
   char        chr_l_domicile[21]; 
   char 			chr_l_currcode[4];

	/**char  *chr_l_clnt_country_code;
   char  *chr_l_g_clnt_country_code;	
 	
   chr_l_clnt_country_code=(char *)calloc(3,sizeof(char));
   chr_l_g_clnt_country_code=(char *)calloc(3,sizeof(char));

	strcpy(chr_l_clnt_country_code,APL_COUNTRY_CODE);
	strcpy(chr_l_g_clnt_country_code,g_mt_commonsys_params_struct_h.nation_code);**/

   char        chr_l_main_funcarea[APL_MAINFUNCAREA_LEN]  =  APL_NULL_STRING;
   char        chr_l_subfunc[APL_MAINFUNCAREA_LEN]        =  APL_NULL_STRING;
   char        chr_l_defflg[APL_MAINFUNCAREA_LEN]         =  APL_NULL_STRING;
	short 		l_truedvp   =	 0;	
	short 		l_hdat	 =	 0;
        //Added for ISKB_6285 - Validation for PAN (as per general nomenclature) & E-mail ID (with '@' sign and '.' Special character)-START
       	 char chr_l_pan_no[11] = APL_NULL_STRING;
         int i=0,j=0;
        //Added for ISKB_6285 - Validation for PAN (as per general nomenclature) & E-mail ID (with '@' sign and '.' Special character)-END				

	APL_IF_DEBUG

		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_Client\n",NULL,p_intl_env_data_struct_h);
	   memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));



	if (strlen(p_mt_ruclient_struct_h->h_dl_client) == 0)
   {
		APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING)
   }


	/**if (strlen(p_mt_ruclient_struct_h->h_currencycode) == 0)
   {
		APL_DATA_MISSING("CURRENCY CODE",APL_NULL_STRING,APL_NULL_STRING)
   }
	else
   {
	         int_retval = CO_Chk_CodeValid("ISOCURRENCY",
                                         p_mt_ruclient_struct_h->h_currencycode,
                                         APL_COUNTRY_CODE,   
			                      	          l_debug_info_ptr);
               
           if (int_retval !=APL_SUCCESS)
           {
                CO_InsertErr(  l_debug_info_ptr,
                               ERR_INVALID_CODE,
                               p_mt_ruclient_struct_h->h_currencycode,
                               APL_NULL_STRING,
                               APL_NULL_STRING,
                               __LINE__,
                               __FILE__);
                APL_GOBACK_FAIL
           }
   }**/    

	if ((strlen(p_mt_ruclient_struct_h->h_currencycode) == 0) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
   {
		APL_DATA_MISSING("CURRENCY CODE",APL_NULL_STRING,APL_NULL_STRING)
   }
    else
    {
      if(strcmp(p_mt_ruclient_struct_h->h_currencycode,"INR") == 0) 
      {
	        int_retval = CO_Chk_CodeValid("ISOCURRENCY",
                                          p_mt_ruclient_struct_h->h_currencycode,
                                          APL_COUNTRY_CODE,   
			                    	            l_debug_info_ptr);
               
           if (int_retval !=APL_SUCCESS)
            {
                CO_InsertErr(  l_debug_info_ptr,
                               ERR_INVALID_CODE,
                               p_mt_ruclient_struct_h->h_currencycode,
                               APL_NULL_STRING,
                               APL_NULL_STRING,
                               __LINE__,
                               __FILE__);
                APL_GOBACK_FAIL
           }
      } 
      else
      {  
        if(strlen(p_mt_ruclient_struct_h->h_currencycode) != 0) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
        {
            printf("Value of DEF_cntry Code ==|%s|\n",APL_DEF_COUNTRY_CODE);

	           int_retval = CO_Chk_CodeValid("ISOCURRENCY",
                                           p_mt_ruclient_struct_h->h_currencycode,
                                           APL_DEF_COUNTRY_CODE,   
			                      	            l_debug_info_ptr);
               
           if (int_retval !=APL_SUCCESS)
           {
                CO_InsertErr(  l_debug_info_ptr,
                               ERR_INVALID_CODE,
                               p_mt_ruclient_struct_h->h_currencycode,
                               APL_NULL_STRING,
                               APL_NULL_STRING,
                               __LINE__,
                               __FILE__);
                APL_GOBACK_FAIL
           }
       }
    }
    }   


    if ((strlen(p_mt_ruclient_struct_h->h_nationcode) == 0) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
    {
        APL_DATA_MISSING("COUNTRY CODE",APL_NULL_STRING,APL_NULL_STRING)
    }
    else
    {
          if (strcmp(p_mt_ruclient_struct_h->h_nationcode,"IN") == 0)
          {
           printf("Val of Only In ==|%s|\n",p_mt_ruclient_struct_h->h_nationcode); 
           int_retval = CO_Chk_CodeValid("ISOCOUNTRY",
                                          p_mt_ruclient_struct_h->h_nationcode,
                                          APL_COUNTRY_CODE,
                                          l_debug_info_ptr);
           if (int_retval !=APL_SUCCESS)
           {
                     CO_InsertErr(  l_debug_info_ptr,
                                    ERR_INVALID_CODE,
                                    p_mt_ruclient_struct_h->h_nationcode,
                                    APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    __LINE__,
                                    __FILE__);
                                    APL_GOBACK_FAIL
           }
           } 
           else
           {
             if(strlen(p_mt_ruclient_struct_h->h_nationcode) != 0) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
             {    
               int_retval = CO_Chk_CodeValid("ISOCOUNTRY",
                                              p_mt_ruclient_struct_h->h_nationcode,
                                               APL_DEF_COUNTRY_CODE,
                                              l_debug_info_ptr);
               if (int_retval !=APL_SUCCESS)
               {
               CO_InsertErr(  l_debug_info_ptr,
                              ERR_INVALID_CODE,
                              p_mt_ruclient_struct_h->h_nationcode,
                              APL_NULL_STRING,
                              APL_NULL_STRING,
                              __LINE__,
                              __FILE__);
                              APL_GOBACK_FAIL
               }
             }
           }
           }
   printf("VAL Of Master Account ==|%s|\n",p_mt_ruclient_struct_h->h_mstclt);
		if(strcmp(p_mt_ruclient_struct_h->h_mstclt,"--SELF--")==0)
		{
			strcpy(p_mt_ruclient_struct_h->h_mstclt,p_mt_ruclient_struct_h->h_dl_client);
		}

   printf("VAL Of Master Account ==|%s|\n",p_mt_ruclient_struct_h->h_mstclt);
		fflush(stdout);


   if ((strlen(p_mt_ruclient_struct_h->h_mstclt) == 0 ) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
   {
       APL_DATA_MISSING("MASTER ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)
   }

   if ((strlen(p_mt_ruclient_struct_h->h_clnt_clr_name) == 0) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
   {
       APL_DATA_MISSING("CLIENT LONG NAME",APL_NULL_STRING,APL_NULL_STRING)
   }

   
   if((strcmp(p_intl_env_data_struct_h->h_process, "U")== 0)&&(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)) /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-Start*/ 
		{       
   if (strlen(p_mt_ruclient_struct_h->h_shortclr_name) == 0)
   {
       APL_DATA_MISSING("CLIENT SHORT NAME",APL_NULL_STRING,APL_NULL_STRING)
   }
		} /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-End*/
  
   /*CGSL:MANDATORY FOR MT_CLIENT UPLOAD  --START */
   if((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0))
   { 
		if (strlen(p_mt_ruclient_struct_h->h_contactinfo) == 0)
		{
		   APL_DATA_MISSING("CLIENT ADDRESS1",APL_NULL_STRING,APL_NULL_STRING)
		}
	   

	    if (strlen(p_mt_ruclient_struct_h->h_cln_pan) == 0)
		{
		   APL_DATA_MISSING("PAN",APL_NULL_STRING,APL_NULL_STRING)
		}
		
		
		if (strlen(p_mt_ruclient_struct_h->h_cln_bcn_req) == 0)
		{
		   APL_DATA_MISSING("BCN REQUIRED",APL_NULL_STRING,APL_NULL_STRING)
		}
   }	
   /*CGSL:MANDATORY FOR MT_CLIENT UPLOAD  --end */

   if ((strlen(p_mt_ruclient_struct_h->h_clnt_class) == 0) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
   {
       APL_DATA_MISSING("CLIENTCAT",APL_NULL_STRING,APL_NULL_STRING)
   }
   else
   {
        if(strlen(p_mt_ruclient_struct_h->h_clnt_class) != 0) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
        {
            int_retval = CO_Chk_CodeValid("CLIENTCAT",
                                           p_mt_ruclient_struct_h->h_clnt_class,
                                           APL_COUNTRY_CODE,
                                           l_debug_info_ptr);
            if (int_retval !=APL_SUCCESS)
            {
                         CO_InsertErr(  l_debug_info_ptr,
                                        ERR_INVALID_CODE,
                                        APL_NULL_STRING,
                                        APL_NULL_STRING,
                                        APL_NULL_STRING,
                                        __LINE__,
                                        __FILE__);
                        APL_GOBACK_FAIL
            }
         }
       }

 /**if (strlen(p_mt_ruclient_struct_h->h_domestic) == 0)
 {
     APL_DATA_MISSING("DOMICILE FLAG",APL_NULL_STRING,APL_NULL_STRING)
 }
 else
 {
     int_retval = CO_Chk_CodeValid("DOMICILE",
                                    p_mt_ruclient_struct_h->h_domestic,
                                    APL_COUNTRY_CODE,
                                    l_debug_info_ptr);
              if (int_retval !=APL_SUCCESS)
               {
                        CO_InsertErr(  l_debug_info_ptr,
                                       ERR_INVALID_CODE,
                                         p_mt_ruclient_struct_h->h_domestic,
                                        APL_NULL_STRING,
                                        APL_NULL_STRING,
                                        __LINE__,
                                        __FILE__);
                       APL_GOBACK_FAIL
              }
  }**/

  /*  Checking For Local & Foreign */

   if ((strlen(p_mt_ruclient_struct_h->h_domestic) == 0 ) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
   {
	  
         APL_DATA_MISSING("SEBI CATEGORY",APL_NULL_STRING,APL_NULL_STRING)
		
   }

   strcpy(chr_l_domicile,p_mt_ruclient_struct_h->h_domestic);

   //if (chr_l_domicile) AIX Migration Changes
   if (strlen(chr_l_domicile)>0)
   {
          printf("VAL Of Domicile ==|%s|\n",p_mt_ruclient_struct_h->h_domestic);

          int_retval = CO_Chk_CodeValid("DOMICILE",
                                        p_mt_ruclient_struct_h->h_domestic,
                                        APL_COUNTRY_CODE,
                                        l_debug_info_ptr);
                  if (int_retval !=APL_SUCCESS)
                  {
                            CO_InsertErr(  l_debug_info_ptr,
                                            ERR_INVALID_CODE,
                                            p_mt_ruclient_struct_h->h_domestic,
                                            APL_NULL_STRING,
                                            APL_NULL_STRING,
                                            __LINE__,
                                            __FILE__);
                           APL_GOBACK_FAIL
                 }

    }
    else
    {
     if (strlen(p_mt_ruclient_struct_h->h_domestic) != 0) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
     {
     int_retval = CO_Chk_CodeValid("DOMICILE",
                                    p_mt_ruclient_struct_h->h_domestic,
                                    APL_DEF_COUNTRY_CODE,
                                    l_debug_info_ptr);
                  if (int_retval !=APL_SUCCESS)
                  {
                             CO_InsertErr(  l_debug_info_ptr,
                                            ERR_INVALID_CODE,
                                            p_mt_ruclient_struct_h->h_domestic,
                                            APL_NULL_STRING,
                                            APL_NULL_STRING,
                                            __LINE__,
                                            __FILE__);
                             APL_GOBACK_FAIL
                  } 
      }
     } 


 if ((strlen(p_mt_ruclient_struct_h->h_cln_sebi_ctg) == 0 ) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
 { 
		APL_DATA_MISSING("SEBI CATEGORY",APL_NULL_STRING,APL_NULL_STRING)

 } 
 else 
 {
      if(strlen(p_mt_ruclient_struct_h->h_cln_sebi_ctg) != 0) /*DataPatch-CS0181192-Mandatory for Add-Pavan*/
      {
         int_retval = CO_Chk_CodeValid("SEBICAT",
                                        p_mt_ruclient_struct_h->h_cln_sebi_ctg,
                                        APL_COUNTRY_CODE,
                                        l_debug_info_ptr);

                if (int_retval !=APL_SUCCESS)
                {
                    CO_InsertErr(  l_debug_info_ptr,
                                   ERR_INVALID_CODE,
                                    APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    __LINE__,
                                    __FILE__);
                    APL_GOBACK_FAIL
                }
      }
 } 
    
	if (strlen(p_mt_ruclient_struct_h->h_our_their_ind) == 0)
   {
          strcpy(p_mt_ruclient_struct_h->h_our_their_ind,APL_CLIENT_OURTHEIR_IND);
   }
	
	if (strlen(p_mt_ruclient_struct_h->h_clt_brk_all) == 0)
   {
	strcpy(p_mt_ruclient_struct_h->h_clt_brk_all,APL_CLIENT_BRKALL_IND); 	
   }	
  
   if (strlen(p_mt_ruclient_struct_h->h_cln_add_state) != 0)
   {
       int_retval = CO_Chk_CodeValid("STATE",
                                    p_mt_ruclient_struct_h->h_cln_add_state,
                                    APL_COUNTRY_CODE,
                                    l_debug_info_ptr);
       if (int_retval !=APL_SUCCESS)
       {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
         APL_GOBACK_FAIL
       }
   } 
    
   if (strlen(p_mt_ruclient_struct_h->h_cln_add_city) != 0)
   {
       int_retval = CO_Chk_CodeValid("CITY",
                                      p_mt_ruclient_struct_h->h_cln_add_city,
                                      p_mt_ruclient_struct_h->h_cln_add_state,
                                      l_debug_info_ptr);
       if (int_retval !=APL_SUCCESS)
       {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
         APL_GOBACK_FAIL
       }
   }
//Added for ISKB_6285 - Validation for PAN (as per general nomenclature) & E-mail ID (with '@' sign and '.' Special character)-START
	if (strlen(p_mt_ruclient_struct_h->h_cln_pan) != 0)
	{	
		if (strlen(p_mt_ruclient_struct_h->h_cln_pan) != 10)
		   {
				 CO_InsertErr(  l_debug_info_ptr,
		                           ERR_PAN_LENGTH,
		                           p_mt_ruclient_struct_h->h_cln_pan,
		                           APL_NULL_STRING,
		                           APL_NULL_STRING,
		                           __LINE__,
		                           __FILE__);
		            APL_GOBACK_FAIL
		  }
		  else
		  {
			strcpy(chr_l_pan_no,p_mt_ruclient_struct_h->h_cln_pan);
			printf("PAN No is |%s| \n",chr_l_pan_no);
			for(i=0;i<5;i++)
			  {
				if( (chr_l_pan_no[i] >= 48 && chr_l_pan_no[i] <= 57)||
		                       (chr_l_pan_no[i] >= 33 && chr_l_pan_no[i] <= 47) ||
		                       (chr_l_pan_no[i] >= 58 && chr_l_pan_no[i] <= 64) ||
		                       (chr_l_pan_no[i] >= 91 && chr_l_pan_no[i] <= 96) ||
		                       (chr_l_pan_no[i] >= 123 && chr_l_pan_no[i] <= 126))
				  {
		                           printf("Inside Alphabet check \n");
				      CO_InsertErr(  l_debug_info_ptr,
		                                          ERR_INVALID_PAN,
		                                          p_mt_ruclient_struct_h->h_cln_pan,
		                                          APL_NULL_STRING,
		                                          APL_NULL_STRING,
		                                                 __LINE__,
		                                                  __FILE__);
		                           APL_GOBACK_FAIL
				  }
			  }
			  for (j=5;j<9; j++)
			  {
				if( (chr_l_pan_no[j] >= 65 && chr_l_pan_no[j] <= 90) ||
			        	(chr_l_pan_no[j] >= 97 && chr_l_pan_no[j] <= 122)||
		                            (chr_l_pan_no[j] >= 33 && chr_l_pan_no[j] <= 47) ||
		                            (chr_l_pan_no[j] >= 58 && chr_l_pan_no[j] <= 64) ||
		                            (chr_l_pan_no[j] >= 91 && chr_l_pan_no[j] <= 96) ||
		                            (chr_l_pan_no[j] >= 123 && chr_l_pan_no[j] <= 126))
				  {
		                           printf("Inside Numeric Check \n");
					CO_InsertErr(  l_debug_info_ptr,
		                           ERR_INVALID_PAN,
		                            p_mt_ruclient_struct_h->h_cln_pan,
		                           APL_NULL_STRING,
		                           APL_NULL_STRING,
		                           __LINE__,
		                           __FILE__);
		            APL_GOBACK_FAIL
				  }
			  }
			  if( (chr_l_pan_no[9] >= 48 && chr_l_pan_no[9] <= 57)||
		                 (chr_l_pan_no[9] >= 33 && chr_l_pan_no[9] <= 47) ||
		                 (chr_l_pan_no[9] >= 58 && chr_l_pan_no[9] <= 64) ||
		                 (chr_l_pan_no[9] >= 91 && chr_l_pan_no[9] <= 96) ||
		                 (chr_l_pan_no[9] >= 123 && chr_l_pan_no[9] <= 126))
			  {
		                           printf("Inside Last PAN Check \n");
					CO_InsertErr(  l_debug_info_ptr,
		                           ERR_INVALID_PAN,
		                           p_mt_ruclient_struct_h->h_cln_pan,
		                           APL_NULL_STRING,
		                           APL_NULL_STRING,
		                           __LINE__,
		                           __FILE__);
		            APL_GOBACK_FAIL
			  }
		  }
		
	}
//Added for ISKB_6285 - Validation for PAN (as per general nomenclature) & E-mail ID (with '@' sign and '.' Special character)-END
 
  if (strlen(p_mt_ruclient_struct_h->h_iscc_ind) == 0)
  { 
     strcpy(p_mt_ruclient_struct_h->h_iscc_ind,APL_CLIENT_ISCC_IND);
  }
            
 if (strlen(p_mt_ruclient_struct_h->h_instr_isinuseflg) == 0)
 { 
     strcpy(p_mt_ruclient_struct_h->h_instr_isinuseflg,APL_CLIENT_USE_IND);
 } 

 if (strlen(p_mt_ruclient_struct_h->h_spotdlflg) == 0)
 { 
     strcpy(p_mt_ruclient_struct_h->h_spotdlflg,APL_CLIENT_SPOT_IND);
 } 
/** No Check for 'B' flag Required
	if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
	{
		if (strlen(p_mt_ruclient_struct_h->h_iscc_ind) == 0)
			APL_DATA_MISSING("ISCC FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_iscc_ind, "N");**/
	/** No Check for Isinuseflg is Required 
	if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
	{
		if (strlen(p_mt_ruclient_struct_h->h_instr_isinuseflg) == 0)
			APL_DATA_MISSING("ISINUSE FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_instr_isinuseflg, "N");**/
	
        if(strlen(p_mt_ruclient_struct_h->h_billableflag) == 0)
       { 
        strcpy(p_mt_ruclient_struct_h->h_billableflag,APL_CLIENT_BILL_IND); 
       } 

	/**Commonsys_param check not required if ((strcmp(g_mt_commonsys_params_struct_h.bill_module_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_billableflag) == 0)
			APL_DATA_MISSING("BILLABLE FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_billableflag, "N");**/
	
	/** CoreSys Parms not required if ((strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_ord_clt) == 0)
			APL_DATA_MISSING("ORD_CLT",APL_NULL_STRING,APL_NULL_STRING)
	}**/
	
	/**CoreSysParam check not Required if ((strcmp(l_mt_core_sys_params_struct_h.proc_spot_dl_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_spotdlflg) == 0)
			APL_DATA_MISSING("SPOT TRADES FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_spotdlflg, "N");**/
	
	/** No Check for MessageSysParams is Requiredif ((strcmp(l_mt_message_sys_params_struct_h.gen_fx_adv_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_fx_sell_flag) == 0)
			APL_DATA_MISSING("FX SALES FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_fx_sell_flag, "N");**/
	
 if (strlen(p_mt_ruclient_struct_h->h_fx_sell_flag) == 0)
 {   
    strcpy(p_mt_ruclient_struct_h->h_fx_sell_flag,APL_CLIENT_SELL_IND);
 }
 
 if (strlen(p_mt_ruclient_struct_h->h_fx_buy_flag) == 0)
 { 
     strcpy(p_mt_ruclient_struct_h->h_fx_buy_flag,APL_CLIENT_BUY_IND);
 } 

/** No Check for MessageSysParams Required	if ((strcmp(l_mt_message_sys_params_struct_h.gen_fx_adv_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_fx_buy_flag) == 0)
			APL_DATA_MISSING("FX PURCHASE FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_fx_buy_flag, "N"); **/
	
 if (strlen(p_mt_ruclient_struct_h->h_fx_inc_flag) == 0)
  {
    strcpy(p_mt_ruclient_struct_h->h_fx_inc_flag,APL_CLIENT_INC_IND);
  } 
	/** MessageSysParam Check not Required if ((strcmp(l_mt_message_sys_params_struct_h.gen_fx_adv_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_fx_inc_flag) == 0)
			APL_DATA_MISSING("FX INC FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_fx_inc_flag, "N"); **/

if (strlen(p_mt_ruclient_struct_h->h_single548_support_ind) == 0)
 { 
    strcpy(p_mt_ruclient_struct_h->h_single548_support_ind,APL_CLIENT_SUPPORT_IND);                  }  
 if (strlen(p_mt_ruclient_struct_h->h_stat_tran_flag) == 0)
 { 
    strcpy(p_mt_ruclient_struct_h->h_stat_tran_flag,APL_CLIENT_DL_IND);
 }
 if (strlen(p_mt_ruclient_struct_h->h_fmt_rptflag) == 0)
 { 
    strcpy(p_mt_ruclient_struct_h->h_fmt_rptflag,APL_CLIENT_FMTRPT_IND);
 } 
 
 if (strlen(p_mt_ruclient_struct_h->h_cln_start_dl) == 0)
 { 
    strcpy(p_mt_ruclient_struct_h->h_cln_start_dl,APL_CLIENT_STARTDL_IND);
 }
    printf("Val of StartDl Ind ==%s\n",p_mt_ruclient_struct_h->h_cln_start_dl); 


	/** Check for 'B' is not Required if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
	{
		if (strlen(p_mt_ruclient_struct_h->h_fmt_rptflag) == 0)
			APL_DATA_MISSING("FMTRPT FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_fmt_rptflag, "N"); **/
	
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
        {
       printf("ACCESS STAMP ==%s\n",p_mt_ruclient_struct_h->h_access_stamp);
		if (strlen(p_mt_ruclient_struct_h->h_access_stamp) == 0)
			APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
        }
	
/*if (strlen(p_mt_ruclient_struct_h->h_domestic) == 0)
		APL_DATA_MISSING("DOMICILE FLAG",APL_NULL_STRING,APL_NULL_STRING)*/
	
 if (strlen(p_mt_ruclient_struct_h->h_part_flg) == 0)
 { 
     strcpy(p_mt_ruclient_struct_h->h_part_flg,APL_CLIENT_PARTIAL_IND);
 } 

/** CoreSysParam Check not Required if ((strcmp(l_mt_core_sys_params_struct_h.part_confirm, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
	{
		if (strlen(p_mt_ruclient_struct_h->h_part_flg) == 0)
			APL_DATA_MISSING("PARTIAL FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
		strcpy(p_mt_ruclient_struct_h->h_part_flg, "N");  **/

	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "EI_SMI_IND");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if ( int_l_condexists > 0 )	
	{
	
		if (strlen(p_mt_ruclient_struct_h->h_clt_grp) == 0)
			APL_DATA_MISSING("ACCOUNT GROUP", APL_NULL_STRING, APL_NULL_STRING)

		if (strcmp(p_mt_ruclient_struct_h->h_clt_grp, "LBRK") == 0)
		{
			if (strlen(p_mt_ruclient_struct_h->h_sat_oper_cd) == 0)
				APL_DATA_MISSING("OPERATOR CODE", APL_NULL_STRING, APL_NULL_STRING)
		}

	}

	int_retval = 0;
	int_retval=CO_Chk_CntryEnabled("ACC_MAINT", "TRUE_DVP_FLAG", &l_truedvp, l_debug_info_ptr);

	if(int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	int_retval = 0;
	int_retval=CO_Chk_CntryEnabled("ACC_MAINT", "PROC_HDAT_INST",&l_hdat, l_debug_info_ptr);
	if(int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	int_retval = 0;
	
	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "TAXABLE_FLG");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CO_Chk_CntryEnabled("MIS_INSTXN","GR_ON_EXCHANGE",&l_gronexchangecond,l_debug_info_ptr); 
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

     if (strlen(p_mt_ruclient_struct_h->h_allow_regflag) == 0)
            { 
            strcpy(p_mt_ruclient_struct_h->h_allow_regflag,APL_CLIENT_ALLREG_IND);
            }        

            if (strlen(p_mt_ruclient_struct_h->h_regsetlflg) == 0)
            { 
            strcpy(p_mt_ruclient_struct_h->h_regsetlflg,APL_CLIENT_SETL_IND);
            } 

            if (strlen(p_mt_ruclient_struct_h->h_reg_bcl_ind) == 0)
            { 
            strcpy(p_mt_ruclient_struct_h->h_reg_bcl_ind,APL_CLIENT_BCL_IND);
            }
 /**No Check Required for LocationBased */
	/*if ( int_l_condexists == 0 )
	{
		if ((strcmp(l_mt_core_sys_params_struct_h.proc_reg_ind, "Y") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
		{
			if (strlen(p_mt_ruclient_struct_h->h_allow_regflag) == 0)
				APL_DATA_MISSING("CANREG FLAG",APL_NULL_STRING,APL_NULL_STRING)
		}
		else
			strcpy(p_mt_ruclient_struct_h->h_allow_regflag, "N");

		if (strcmp(p_mt_ruclient_struct_h->h_allow_regflag, "Y") == 0)
		{	
			if (strlen(p_mt_ruclient_struct_h->h_regsetlflg) == 0)
				APL_DATA_MISSING("REGSETTLE FLAG",APL_NULL_STRING,APL_NULL_STRING)
		}
		else
		{
			if ( l_gronexchangecond == 0 ) 
				strcpy(p_mt_ruclient_struct_h->h_regsetlflg, "N");
		}                                                            
	
		
		if (strcmp(p_mt_ruclient_struct_h->h_allow_regflag, "Y") == 0) 
		{	
			if (strlen(p_mt_ruclient_struct_h->h_reg_bcl_ind) == 0)
				APL_DATA_MISSING("REGBCL FLAG",APL_NULL_STRING,APL_NULL_STRING)
		}
		else if(l_truedvp)
		{	
			if (strlen(p_mt_ruclient_struct_h->h_reg_bcl_ind) == 0)
				APL_DATA_MISSING("TRUE DVP FLAG",APL_NULL_STRING,APL_NULL_STRING)
		}
		else if(l_hdat)
		{	
			if (strlen(p_mt_ruclient_struct_h->h_reg_bcl_ind) == 0)
				APL_DATA_MISSING("PROCESS HDAT INST",APL_NULL_STRING,APL_NULL_STRING)
		}
		else 
		{
			strcpy(p_mt_ruclient_struct_h->h_reg_bcl_ind, "N");
		}
		
	}*/

 /** Check for BrkAll Flag not Required if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
	{
		if (strlen(p_mt_ruclient_struct_h->h_clnt_class) == 0)
			APL_DATA_MISSING("CLIENT TYPE",APL_NULL_STRING,APL_NULL_STRING)
	}**/
	
	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "CLT_CLAS");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
		{
			if (strlen(p_mt_ruclient_struct_h->h_clt_class) == 0)
				APL_DATA_MISSING("ACCOUNT CLASS",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "REG_NAME");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	/**Check for CoreSysParam Check not Required if (int_l_condexists > 0)
	{
		if ((strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") == 0) && 
			 (strcmp(p_mt_ruclient_struct_h->h_dl_client,l_mt_core_sys_params_struct_h.custody_clt_cd) != 0) &&
			 (strcmp(p_mt_ruclient_struct_h->h_dl_client,l_mt_core_sys_params_struct_h.brokerage_cd) != 0) &&
			 (strcmp(l_mt_core_sys_params_struct_h.proc_reg_ind,"N") == 0))
		{
			if (strlen(p_mt_ruclient_struct_h->h_regclr_name) == 0)
				APL_DATA_MISSING("REG_NAME",APL_NULL_STRING,APL_NULL_STRING)
		}
	}

	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "VTB_PROCESSING"); **/

	/**No Check Location Required int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
		{
			if (strlen(p_mt_ruclient_struct_h->h_vtbclient) == 0)
				APL_DATA_MISSING("VTB ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)

			if (p_mt_ruclient_struct_h->h_vtbclient[0] == '0')
				CO_InsertErr(l_debug_info_ptr,ERR_VTBCLI_CANT_BEG_ZERO,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				
		}
	}
	
	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "CUST_REG_NO");**/

     /**No Check for Location Required 	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
		{
			if (strlen(p_mt_ruclient_struct_h->h_cltreg) == 0)
				APL_DATA_MISSING("CLTREG",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	
	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "BROKMAST_CLG_HOUSE");**/

	/** int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		
			if (strlen(p_mt_ruclient_struct_h->h_clhclient) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_CLHACCOUNT_CANT_EMPTY,p_mt_ruclient_struct_h->h_clhclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

	}

	strcpy(chr_mainfuncarea, "ACC_MAINT");
	strcpy(chr_l_condid, "CLG_HOUSE_ACC_BE");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
		{
			if (strlen(p_mt_ruclient_struct_h->h_clhclient) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_CLHACCOUNT_CANT_EMPTY,p_mt_ruclient_struct_h->h_clhclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}
	
	strcpy(chr_mainfuncarea,"ACC_MAINT");
	strcpy(chr_l_condid,"CHK_BOGCODE");

   int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (int_l_condexists > 0)
   {

		if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"C"))
		{
			if(strlen(p_mt_ruclient_struct_h->h_vtbclient) != 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_BOGCODE_NULL,p_mt_ruclient_struct_h->h_vtbclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		
		if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"B"))
		{
      	if (strlen(p_mt_ruclient_struct_h->h_vtbclient) == 0)
         	APL_DATA_MISSING("BOG CODE",APL_NULL_STRING,APL_NULL_STRING)
      	else if (strlen(p_mt_ruclient_struct_h->h_vtbclient) != 5)
				CO_InsertErr(l_debug_info_ptr,ERR_BOGCODE_EQL5CHAR,p_mt_ruclient_struct_h->h_vtbclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}
   
   strcpy(chr_mainfuncarea,"ACC_MAINT");
   strcpy(chr_l_condid,"IBBSACC_10_DIGITS");
   
   int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (int_l_condexists > 0)
   {
      if (strlen(p_mt_ruclient_struct_h->h_ibbsclient) != 0)
      {
         if (strlen(p_mt_ruclient_struct_h->h_ibbsclient) != 10)
            CO_InsertErr(l_debug_info_ptr,ERR_GLACCOUNT_EQL_DGTS,p_mt_ruclient_struct_h->h_ibbsclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
      }
   }

	strcpy(chr_mainfuncarea,"ACC_MAINT");
	strcpy(chr_l_condid,"SAT_ACCOUNT");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if(int_l_condexists > 0)
	{
		if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"C"))
		{
			
			if(strlen(p_mt_ruclient_struct_h->h_clhclient) >11)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCSAT_CANTBE_MORE_10DIGITS,p_mt_ruclient_struct_h->h_clhclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		
	   if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"B")) 
		{
			if(strlen(p_mt_ruclient_struct_h->h_clhclient) != 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCSAT_CANTBE_NULLFOR_BRK,p_mt_ruclient_struct_h->h_clhclient,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}

	strcpy(chr_mainfuncarea,"ACC_MAINT");
	strcpy(chr_l_condid,"SAT_CODE");**/

	/**int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if(int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if(int_l_condexists > 0)
	{
		if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"C"))
		{
			
			if(strlen(p_mt_ruclient_struct_h->h_cltreg) >11)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCSATCODE_CANTBE_MORE_10DIGITS,p_mt_ruclient_struct_h->h_cltreg,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
		if(!strcmp(p_mt_ruclient_struct_h->h_clt_brk_all,"B"))
		{
			if(strlen(p_mt_ruclient_struct_h->h_cltreg) != 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCSATCODE_CANTBE_NULLFOR_BRK,p_mt_ruclient_struct_h->h_cltreg,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}**/

	
    /**No Check for BrkAll flag is Required  	if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0)
	{
		if (strlen(p_mt_ruclient_struct_h->h_taxable_ind) == 0)
			APL_DATA_MISSING("TAXABLE FLAG",APL_NULL_STRING,APL_NULL_STRING)
	}
	else
	{	
		
		strcpy(p_mt_ruclient_struct_h->h_taxable_ind,APL_NULL_STRING);
	}

	if (strcmp(l_mt_core_sys_params_struct_h.sub_clt_proc, "N") == 0)
	{
		if (strcmp(p_mt_ruclient_struct_h->h_dl_client, p_mt_ruclient_struct_h->h_mstclt) != 0)
			CO_InsertErr(l_debug_info_ptr,ERR_DATA_INTEGRITY,p_mt_ruclient_struct_h->h_dl_client,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
	}**/
	
		int_l_condexists = 0 ;	
		int_retval = CO_Chk_CntryEnabled("ACC_MAINT","EXT_CLH_ACCOUNT",&int_l_condexists,l_debug_info_ptr);
	
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if ((int_l_condexists == 0) && (strlen(p_mt_ruclient_struct_h->h_extclhclient)))
			CO_InsertErr(l_debug_info_ptr,ERROR_COLUMN_SHUD_NULL,p_mt_ruclient_struct_h->h_extclhclient,"Ext. Clearing House ",APL_NULL_STRING,__LINE__,__FILE__);

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Account is %s \n",p_mt_ruclient_struct_h->h_dl_client);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

	}
	
	if ((strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "N") == 0) && (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") != 0))
		strcpy((char *)p_mt_ruclient_struct_h->h_ord_clt,"C");
	
	if (strcmp(p_mt_ruclient_struct_h->h_clt_brk_all, "B") == 0)
		strcpy((char *)p_mt_ruclient_struct_h->h_ord_clt,APL_NULL_STRING);
		
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
	{
		
		int_retval = MT_Rtv_AccFldVal(p_mt_ruclient_struct_h->h_dl_client,"ROWID",chr_l_field_val,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		strcpy(chr_l_row_id_acct,chr_l_field_val); 

      memset(chr_l_main_funcarea,APL_NULL_CHAR,APL_MAINFUNCAREA_LEN);
      memset(chr_l_subfunc,APL_NULL_CHAR,APL_MAINFUNCAREA_LEN);
      memset(chr_l_defflg,APL_NULL_CHAR,APL_MAINFUNCAREA_LEN);

      strcpy(chr_l_main_funcarea,"DEF_CASHACC_FLG");
      strcpy(chr_l_subfunc,SETTLEMENT);

      /** if(APL_FAILURE == CO_Rtv_FldVal(chr_l_main_funcarea,chr_l_subfunc,chr_l_defflg,l_debug_info_ptr))
      {
         APL_GOBACK_FAIL
      }	**/

	/** No Check forCashBased is Required int_retval = CR_Rtv_CashAccFldVal(p_mt_ruclient_struct_h->h_dl_client,p_mt_ruclient_struct_h->h_ibbsclient,p_mt_ruclient_struct_h->h_currencycode,chr_l_defflg,chr_l_defflg,"ROWID",chr_l_field_val,l_debug_info_ptr);
	
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL **/
	
		
		int_retval = MT_Rtv_AccFldVal(p_mt_ruclient_struct_h->h_dl_client,"access_stamp",chr_l_field_val,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	/* CGSL:fix for table access time and param string access time is differ for MT_CLIENT upload :START*/	
	if( strcmp(p_intl_env_data_struct_h->h_process, "U") == 0)
		    {
	           strcpy(p_mt_ruclient_struct_h->h_access_stamp,chr_l_field_val);	
			}
    /* CGSL:fix for table access time and param string access time is differ for MT_CLIENT upload :end*/		

 APL_IF_DEBUG
 {
    printf("Access Stamp  From Table :%s\n",chr_l_field_val); 
    printf("Access Stamp  From Param String :%s\n",p_mt_ruclient_struct_h->h_access_stamp); 
 } 

		if (strcmp(chr_l_field_val,p_mt_ruclient_struct_h->h_access_stamp) != 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_ruclient_struct_h->h_dl_client,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}

		if (strcmp(p_mt_ruclient_struct_h->h_clt_status,STATUS_UNFROZ_UAUTH) == 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_MARKEDFORUNFRZN,p_mt_ruclient_struct_h->h_dl_client,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}
	}
	
	if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode, REP_MODE) == 0))
	{
		chr_iexist = 'N';

		int_retval = CO_Chk_AccValid(p_mt_ruclient_struct_h->h_dl_client,chr_iexist,NULL,NULL,NULL,NULL,NULL,NULL,NULL,l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
          APL_GOBACK_FAIL

	}
	else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';
		chr_iclosed = 'N';
		
		int_retval = CO_Chk_AccValid(p_mt_ruclient_struct_h->h_dl_client,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

          }
		if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
      
  if ((strlen(p_mt_ruclient_struct_h->h_dl_client) != 0) && (strlen(p_mt_ruclient_struct_h->h_mstclt) != 0))
  {
                    int_retval = CR_Chk_AccIndSet(p_mt_ruclient_struct_h->h_dl_client,p_mt_ruclient_struct_h->h_mstclt,&chr_link_val,l_debug_info_ptr);
        
                    if(int_retval != APL_SUCCESS)
                        APL_GOBACK_FAIL

                    p_mt_ruclient_struct_h->h_cln_mst_ind = chr_link_val;
  }
      printf("Valu offfff chr_link_val ==%d\n",chr_link_val);

      if ((strlen(p_mt_ruclient_struct_h->h_dl_client) != 0) && (strlen(p_mt_ruclient_struct_h->h_mstclt) != 0)) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
      { 
       int_retval = CR_Chk_IsMaster(p_mt_ruclient_struct_h->h_dl_client,p_mt_ruclient_struct_h->h_mstclt,chr_link_val,l_debug_info_ptr);

                     if(int_retval != APL_SUCCESS)
                           APL_GOBACK_FAIL
      }
		
	int_retval = CR_Chk_Acc(p_mt_ruclient_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
		
	 int_retval = MT_Mod_DBClient(p_mt_ruclient_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
        printf("p_mt_ruclient_struct_h->h_cln_mst_ind =%d\n",p_mt_ruclient_struct_h->h_cln_mst_ind);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_Client SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_Client FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}

 /* Kouser - HDFCMT_001 - Client Master Maintenance */

 int CR_Proc_AccMsgAddrCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_access_stamp,char *chr_p_to_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	char							chr_iexist,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed;
	char							chr_l_field_val[40];
	char							chr_l_row_id_to_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Proc_AccMsgAddrCpy \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_to_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_to_acct));

	if (strlen(chr_p_from_acct) == 0)
		APL_DATA_MISSING("FROM ACCT",APL_NULL_STRING,APL_NULL_STRING)

	if (strlen(chr_p_to_acct) == 0)
		APL_DATA_MISSING("TO ACCT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_from_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP","FROM ACCT",APL_NULL_STRING)
	
	if (strlen(chr_p_to_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP","TO ACCT",APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"From client is %s \n",chr_p_from_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"To client is %s \n",chr_p_to_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}

	
	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = MT_Rtv_AccFldVal(chr_p_to_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	strcpy(chr_l_row_id_to_acct,chr_l_field_val);
	
	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_from_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"FROM ACCT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}
	
	int_retval = MT_Rtv_AccFldVal(chr_p_to_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_to_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"TO ACCT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}
	
	chr_iexist = 'Y';
	chr_iauthorised = 'Y';
	chr_ideleted = 'N';
	chr_ifrozen = 'N';
	chr_iclosed = 'N';
	
	int_retval = CO_Chk_AccValid(chr_p_from_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = CO_Chk_AccValid(chr_p_to_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Proc_DBAccMsgAddrCpy(chr_p_from_acct,chr_p_to_acct,chr_l_row_id_to_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccMsgAddrCpy SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccMsgAddrCpy FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}


 int CR_Proc_AccSchCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_access_stamp,char *chr_p_to_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	char							chr_iexist,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed;
	char							chr_l_field_val[40];
	char							chr_l_row_id_to_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Proc_AccSchCpy \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_to_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_to_acct));

	if (strlen(chr_p_from_acct) == 0)
		APL_DATA_MISSING("FROM ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)

	if (strlen(chr_p_to_acct) == 0)
		APL_DATA_MISSING("TO ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_from_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP","FROM ACCT",APL_NULL_STRING)
	
	if (strlen(chr_p_to_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP","TO ACCT",APL_NULL_STRING)
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"From client is %s \n",chr_p_from_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"To client is %s \n",chr_p_to_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}
	
	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = MT_Rtv_AccFldVal(chr_p_to_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_to_acct,chr_l_field_val);

	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_from_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"FROM ACCT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}
	
	
	int_retval = MT_Rtv_AccFldVal(chr_p_to_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_to_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"TO ACCT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}
	
	chr_iexist = 'Y';
	chr_iauthorised = 'Y';
	chr_ideleted = 'N';
	chr_ifrozen = 'N';
	chr_iclosed = 'N';

	int_retval = CO_Chk_AccValid(chr_p_from_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = CO_Chk_AccValid(chr_p_to_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Proc_DBAccSchCpy(chr_p_from_acct,chr_p_to_acct,chr_l_row_id_to_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccSchCpy SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccSchCpy FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}

 int CR_Proc_AccMemoCpy(char *chr_p_from_acct,char *chr_p_to_acct,char *chr_p_from_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	char							chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed,chr_iauthorised;
	char							chr_l_field_val[40];
	char							chr_l_row_id_to_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Proc_AccMemoCpy \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_to_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_to_acct));

	if (strlen(chr_p_from_acct) == 0)
		APL_DATA_MISSING("FROM ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)

	if (strlen(chr_p_to_acct) == 0)
		APL_DATA_MISSING("TO ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_from_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP","FROM ACCT",APL_NULL_STRING)
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"From client is %s \n",chr_p_from_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"To client is %s \n",chr_p_to_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}

	
	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	 
	int_retval = MT_Rtv_AccFldVal(chr_p_to_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_to_acct,chr_l_field_val);

	
	int_retval = MT_Rtv_AccFldVal(chr_p_from_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_from_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"FROM ACCT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}

	chr_iexist = 'Y';
	chr_ideleted = 'N';
	chr_ifrozen = 'N';
	chr_iclosed = 'N';
	chr_iauthorised = 'Y';

	int_retval = CO_Chk_AccValid(chr_p_from_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CO_Chk_AccValid(chr_p_to_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Proc_DBAccMemoCpy(chr_p_from_acct,chr_p_to_acct,chr_l_row_id_to_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccMemoCpy SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Proc_AccMemoCpy FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}




 int CR_Mod_AccMemo(char *chr_p_acct,char *chr_p_memo,char *chr_p_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	char							chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed;
	char							chr_l_field_val[40];
	char							chr_l_row_id_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Mod_AccMemo \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

	if (strlen(chr_p_acct) == 0)
		APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Account is %s \n",chr_p_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}
	
	
	int_retval = MT_Rtv_AccFldVal(chr_p_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_acct,chr_l_field_val);

	
	int_retval = MT_Rtv_AccFldVal(chr_p_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(chr_l_field_val,chr_p_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,chr_p_acct,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}

	chr_iexist = 'Y';
	chr_ideleted = 'N';
	chr_ifrozen = 'N';
	chr_iclosed = 'N';

	int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = MT_Rtv_AccFldVal(chr_p_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_acct,chr_l_field_val);

	int_retval = CR_Mod_DBAccMemo(chr_p_acct,chr_l_row_id_acct,chr_p_memo,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_AccMemo SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_AccMemo FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}

/* Kouser - HDFCMT_001 - Client Master Maintenance */

 int MT_Mod_ClientSch(MT_SCHDET_STRUCT_H *p_mt_schdet_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	/*char							chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed,chr_icubk;*/
	char							chr_l_field_val[40];
	char							chr_l_row_id_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
 char                    chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
 char                    chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;
 char 							seq_num[5];
 char 							chr_chld_table_name[50];
	
	APL_IF_DEBUG

     CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientSch \n",NULL,p_intl_env_data_struct_h);
     memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

   strcpy(chr_chld_table_name,"MT_SCHDET");
     chr_iexist = 'Y';
     chr_ideleted = 'N';

     char  *p_cln_key_codes[4];
     char  *p_key_values[4];

     p_cln_key_codes[0]="CLN_CODE";
     p_cln_key_codes[1]="SCHIDEN_NO";
     p_cln_key_codes[2]="MSG_IDENT_NO";
     p_cln_key_codes[3]=APL_NULL_STRING;

 /* Start - Mandatory Data Check */


	if (strlen(p_mt_schdet_struct_h->h_dl_client) == 0)
		APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	  	
   if (strlen(p_mt_schdet_struct_h->h_eom_msg_ind) == 0)
		APL_DATA_MISSING("EOM_MSG_IND",APL_NULL_STRING,APL_NULL_STRING)

	if (strlen(p_mt_schdet_struct_h->h_generate_day) == 0)
		APL_DATA_MISSING("GENERATE_DAY",APL_NULL_STRING,APL_NULL_STRING) 

   if (strlen(p_mt_schdet_struct_h->h_pos_txn_ind) == 0)
      APL_DATA_MISSING("POST_ON_DAY",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(p_mt_schdet_struct_h->h_nil_mov_ind) == 0)
    APL_DATA_MISSING("ZERO_MOVE_FLAG",APL_NULL_STRING,APL_NULL_STRING)
    
       printf("\n *****Vaibhav Message Number is |%s|",p_mt_schdet_struct_h->h_msg_ident_no);
       /* VaibhavK Kotak-Uat LOC_STATUS Mandatory only for msg_no ='4' Internal Issue:INCUS135 */
 /* SWAMY COMMENTED BELOW CODE FOR --INCUS137 */
       /* if(strcmp(p_mt_schdet_struct_h->h_msg_ident_no,"4") == 0)
       {
	if (strlen(p_mt_schdet_struct_h->h_loc_stat) == 0)
           { 
                printf("\n inside the Mandatory data chk loop.......\n");
		APL_DATA_MISSING("LOC_STATUS",APL_NULL_STRING,APL_NULL_STRING)
           }
       } */ 

	if (strlen(p_mt_schdet_struct_h->h_msg_ident_no) == 0)
   {
		APL_DATA_MISSING("MSG_IDENT_NO",APL_NULL_STRING,APL_NULL_STRING)
   }
   else
   {                      int_retval = CO_Chk_CodeValid("MSGNAME",
                                       p_mt_schdet_struct_h->h_msg_ident_no,
                                       APL_DEF_COUNTRY_CODE,
                                       l_debug_info_ptr);
     if (int_retval !=APL_SUCCESS)
     {
         CO_InsertErr(  l_debug_info_ptr,
                        ERR_INVALID_CODE,
                        p_mt_schdet_struct_h->h_msg_ident_no,
                        APL_NULL_STRING,
                        APL_NULL_STRING,
                        __LINE__,
                        __FILE__);
         APL_GOBACK_FAIL
     }
 } 
 
 if(strcmp(p_mt_schdet_struct_h->h_msg_ident_no,"6")==0)
{
 	if (strlen(p_mt_schdet_struct_h->h_msg_opt) == 0)
 	{  
			APL_DATA_MISSING("MSG_OPTION",APL_NULL_STRING,APL_NULL_STRING)
 	}
 	else 
 	{   
    	printf("p_mt_schdet_struct_h->h_msg_opt ==|%s|\n",p_mt_schdet_struct_h->h_msg_opt);
    	printf("APL_COUNTRY_CODE ==|%s|\n",APL_COUNTRY_CODE);
     	     int_retval = CO_Chk_CodeValid("MSGOPTION",
                                         p_mt_schdet_struct_h->h_msg_opt,
                                         APL_DEF_COUNTRY_CODE,
                                         l_debug_info_ptr);
          if (int_retval !=APL_SUCCESS)
          {
            CO_InsertErr(  l_debug_info_ptr,
                           ERR_INVALID_CODE,
                           p_mt_schdet_struct_h->h_msg_opt,
                           APL_NULL_STRING,
                           APL_NULL_STRING,
                           __LINE__,
                           __FILE__);
            APL_GOBACK_FAIL
          } 
  	} 
}
 /* End - Mandatory Data Check */

	/*if (!((strcmp(p_mt_schdet_struct_h->h_msg_ident_no,HOLDINGSMSGNO) == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_ident_no,STMTTRANMSGNO) == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_ident_no,STMTPENDINGMSGNO) == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_ident_no,STMTALLEGMSGNO) == 0)|| (strcmp(p_mt_schdet_struct_h->h_msg_ident_no,STMTINTRAPOSADVNO) == 0)))
		CO_InsertErr(l_debug_info_ptr,ERR_INVALID_ARGUMENT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);*/
	
if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) != 0)) 
 {
		if (p_mt_schdet_struct_h->h_schsequence_num == 0)
			APL_DATA_MISSING("SCHSEQUENCE_NO",APL_NULL_STRING,APL_NULL_STRING)

		if (p_mt_schdet_struct_h->h_access_stamp == 0)
			APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
 }

if (strcmp(p_mt_schdet_struct_h->h_msg_ident_no,STMTPENDINGMSGNO) == 0)
{ 	
    printf(" Value of MsgOption ===%s\n",p_mt_schdet_struct_h->h_msg_opt);
		if (strlen(p_mt_schdet_struct_h->h_msg_opt) == 0)
			APL_DATA_MISSING("MSG_OPT",APL_NULL_STRING,APL_NULL_STRING)
	
		/*if (!( (strcmp(p_mt_schdet_struct_h->h_msg_opt,"1") == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_opt,"2") == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_opt,"3") == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_opt,"4") == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_opt,"5") == 0) || (strcmp(p_mt_schdet_struct_h->h_msg_opt,"6") == 0) ) )
			CO_InsertErr(l_debug_info_ptr,ERR_INVALID_ARGUMENT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
}
else
strcpy(p_mt_schdet_struct_h->h_msg_opt,APL_NULL_STRING);*/
}
	
	if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0))
   {
		if (strlen(p_mt_schdet_struct_h->h_pend_ind) == 0)
			APL_DATA_MISSING("NOPEND FLAG",APL_NULL_STRING,APL_NULL_STRING)

		if (strlen(p_mt_schdet_struct_h->h_weeklystmt) == 0)
			APL_DATA_MISSING("WEEKSTMT FLAG",APL_NULL_STRING,APL_NULL_STRING)

   }

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Client Code is %s \n",p_mt_schdet_struct_h->h_dl_client);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}
	
	
	/** int_retval = MT_Rtv_AccFldVal(p_mt_schdet_struct_h->h_dl_client,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_acct,chr_l_field_val);**/
	
 /*p_key_values[0]=p_mt_schdet_struct_h->h_dl_client;
 p_key_values[1]=ltoa(p_mt_schdet_struct_h->h_schsequence_num);
 p_key_values[2]=p_mt_schdet_struct_h->h_msg_ident_no;
 p_key_values[3]=p_mt_schdet_struct_h->h_msg_opt;
 p_key_values[4]=APL_NULL_STRING;*/
 
 APL_IF_DEBUG
 {
   printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
   printf("Master Check Conditions  Exists - |%c|\n",chr_iexist);
   printf("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
 }

 int_retval = CO_Chk_AccValid(p_mt_schdet_struct_h->h_dl_client,
                              chr_iexist,
                              NULL,
                              NULL,
                              NULL,
                              NULL,
                              chr_ideleted,
                              NULL,
                              NULL,
                              l_debug_info_ptr);

 if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
 {
    chr_chld_iexist = 'N';
    chr_chld_ideleted = APL_NULL_CHAR;
    chr_chld_iauthorised = APL_NULL_CHAR;
 }
 else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
        {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = 'N';
          chr_chld_iauthorised = APL_NULL_CHAR;
        }
        else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
        {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = NULL;
          chr_chld_iauthorised = 'N';
        }
        
        /*APL_IF_DEBUG
        {
        printf("Master Details Exists in Proper Status ... \n");
        printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
        printf("Child Check Conditions Exists - |%c|\n",chr_chld_iexist);
        printf("Child Check Conditions Deleted - |%c|\n",chr_chld_ideleted);
        printf("Child Check Conditions Authorised - |%c|\n",chr_chld_iauthorised);

        printf("Key Codes 0 = |%s|\n",p_cln_key_codes[0]);
        printf("Key Codes 1 = |%s|\n",p_cln_key_codes[1]);
        printf("Key Codes 2 = |%s|\n",p_cln_key_codes[2]);

        printf("Key Value 0 = |%s|\n",p_key_values[0]);
        printf("Key Value 1 = |%s|\n",p_key_values[1]);
        printf("Key Value 2 = |%s|\n",p_key_values[2]);
       }*/

     p_key_values[0]=p_mt_schdet_struct_h->h_dl_client;
     p_key_values[1]=ltoa(p_mt_schdet_struct_h->h_schsequence_num);
     p_key_values[2]=p_mt_schdet_struct_h->h_msg_ident_no;
     p_key_values[3]=APL_NULL_STRING;
       
        int_retval = CO_Chk_ChldValid( p_cln_key_codes,
                                      p_key_values,
                                      chr_chld_iexist,
                                      chr_chld_iauthorised,
                                      chr_chld_ideleted,
                                      NULL,
                                      NULL,
                                      NULL,
                                      chr_chld_table_name,
                                      l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL

 /* Check for Same Maker and Checker */

 if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
       (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
 {
	
	 	 printf("p_intl_env_data_struct_h->usr is |%s|\n",p_intl_env_data_struct_h->usr);
       int_retval = CR_Chk_ChldMkrChkr( p_cln_key_codes,
                                        p_key_values,
                                        chr_chld_table_name,
                                        p_intl_env_data_struct_h->usr,
                                        l_debug_info_ptr);

       if (int_retval !=APL_SUCCESS)
           APL_GOBACK_FAIL
 }       



       if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
       {
         int_retval = CR_Rtv_MastChldChrVal  (   p_cln_key_codes,
                                                 p_key_values,
                                                 chr_chld_table_name,
                                                 "ROWID",
                                                 chr_l_field_val,
                                                 l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        strcpy(chr_l_row_id_acct,chr_l_field_val);

        int_retval = CR_Rtv_MastChldChrVal  (   p_cln_key_codes,
                                                p_key_values,
                                                chr_chld_table_name,
                                                "access_stamp",
                                                chr_l_field_val,
                                                l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL



    APL_IF_DEBUG
    {
       printf("Access Stamp  From Table :%s\n",chr_l_field_val);
       printf("Access Stamp  From Param String :%s\n",p_mt_schdet_struct_h->h_access_stamp);
    } 

		if (strcmp(chr_l_field_val,p_mt_schdet_struct_h->h_access_stamp) != 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"SCHEDULE REC",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}
	}
	
	int_retval = MT_Mod_DBClientSch(p_mt_schdet_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientSch SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientSch FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}
 int MT_Mod_ClientMsgAddr(MT_MSGADDRESS_STRUCT_H *p_mt_msgaddress_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	/*char							chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed,chr_icubk;*/
	char							chr_l_field_val[40];
	char							chr_l_row_id_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
	char							chr_l_mstclient[APL_CLIENT_LENGTH] = APL_NULL_STRING;

 char       					chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
 char 							chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;
 char 							chr_chld_table_name[50];
 char 							chr_seq_num;
	char        ch_mainfuncarea[APL_MAINFUNCAREA_LEN]   =  APL_NULL_STRING;
	char        chr_l_condid[APL_CONDID_LEN];
	short       int_l_condexists;

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientMsgAddr \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));
	memset(ch_mainfuncarea, APL_NULL_CHAR, APL_MAINFUNCAREA_LEN);
   memset(chr_l_condid, APL_NULL_CHAR, APL_CONDID_LEN);

   strcpy(chr_chld_table_name,"MT_MSGADDRESS");
   chr_iexist = 'Y';
   chr_ideleted = 'N';
   char  *p_cln_key_codes[4];
   char  *p_key_values[4];

    p_cln_key_codes[0]="CLN_CODE";
    p_cln_key_codes[1]="CONTACTSEQ";
    p_cln_key_codes[2]="MSG_IDENT_NO";
    p_cln_key_codes[3]=APL_NULL_STRING;

    /* Start - Mandatory Data Check */ 

	if (strlen(p_mt_msgaddress_struct_h->h_dl_client) == 0)
		APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(p_mt_msgaddress_struct_h->h_msg_ident_no) == 0)
        {
		APL_DATA_MISSING("MSG_IDENT_NO",APL_NULL_STRING,APL_NULL_STRING)
	}
        else
        {
          int_retval = CO_Chk_CodeValid("MSGNAME",
                                       p_mt_msgaddress_struct_h->h_msg_ident_no,
                                       APL_DEF_COUNTRY_CODE,
                                       l_debug_info_ptr);
        if (int_retval !=APL_SUCCESS)
        {
                     CO_InsertErr(     l_debug_info_ptr,
                                       ERR_INVALID_CODE,
                                       p_mt_msgaddress_struct_h->h_msg_ident_no, 
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       __LINE__,
                                        __FILE__);
                     APL_GOBACK_FAIL  
        } 
    }

     if ((strlen(p_mt_msgaddress_struct_h->h_priority_ind) == 0 ) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
     {
	 APL_DATA_MISSING("PRIORITY_IND",APL_NULL_STRING,APL_NULL_STRING)
  } 
  else
  {
   if(strlen(p_mt_msgaddress_struct_h->h_priority_ind) != 0)
   { 
   int_retval = CO_Chk_CodeValid("PRIORITY",
                                  p_mt_msgaddress_struct_h->h_priority_ind,
                                  APL_DEF_COUNTRY_CODE,
                                  l_debug_info_ptr);
   if (int_retval !=APL_SUCCESS)
   {
                       CO_InsertErr(l_debug_info_ptr,
                                    ERR_INVALID_CODE,
                                    p_mt_msgaddress_struct_h->h_priority_ind,
                                    APL_NULL_STRING,
                                    APL_NULL_STRING,
                                    __LINE__,
                                    __FILE__);
                      APL_GOBACK_FAIL
   }
   }
   }  
   
    if (strlen(p_mt_msgaddress_struct_h->h_swift_tlx_gcn) == 0)
        {    
            strcpy(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,APL_CLIENT_MSGTYPE);
        }  
        else
        {
            int_retval = CO_Chk_CodeValid("MSGTYPE",
                                           p_mt_msgaddress_struct_h->h_swift_tlx_gcn,
                                           APL_DEF_COUNTRY_CODE,
                                           l_debug_info_ptr);
                if (int_retval !=APL_SUCCESS)
                {
                    CO_InsertErr(  l_debug_info_ptr,
                                   INVALID_MESSAGE_TYPE,
                                   p_mt_msgaddress_struct_h->h_swift_tlx_gcn,
                                   APL_NULL_STRING,
                                   APL_NULL_STRING,
                                   __LINE__,
                                   __FILE__);
                   APL_GOBACK_FAIL
                } 
       } 

       if((strcmp(p_intl_env_data_struct_h->h_process,"U")== 0)&& (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) != 0))/*DataPatch-CS0181192-ClientUpload upload-Kotubabu-Start*/
       {
        if((strlen(p_mt_msgaddress_struct_h->h_iso_msg_format) == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0))
        {
           APL_DATA_MISSING("ISO_MSG_FORMAT",APL_NULL_STRING,APL_NULL_STRING)
        }

       if (strlen(p_mt_msgaddress_struct_h->h_msg_ident_no) != 0) {
       if((strcmp(p_mt_msgaddress_struct_h->h_msg_ident_no,"3")!=0)&&(strcmp(p_mt_msgaddress_struct_h->h_msg_ident_no,"31")!=0))
       {
            if (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"S"))
            {
              Alert("\n Message Type should be S for message Number %s",p_mt_msgaddress_struct_h->h_msg_ident_no);
              CO_InsertErr(l_debug_info_ptr,INVALID_MESSAGE_TYPE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
              APL_GOBACK_FAIL
            }
      }
      }
        if(strlen(p_mt_msgaddress_struct_h->h_swift_addr) != 0)
        {
        if ( ((strlen(p_mt_msgaddress_struct_h->h_swift_addr) != 11)&&(strlen(p_mt_msgaddress_struct_h->h_swift_addr) !=8)) && (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"S") == 0) )
        {
                        Alert("Address details length should be 8 or 11 digits only \n");
                        CO_InsertErr(l_debug_info_ptr,ADDR_LEN_CORRECT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                        APL_GOBACK_FAIL
         }
        }
       }   /*DataPatch-CS0181192-ClientMessage upload-Kotubabu-End*/

    /* End - Mandatory Data Check */

    if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
    {  
        if (p_mt_msgaddress_struct_h->h_access_stamp == 0)
        {
            APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
        }

     	 if (p_mt_msgaddress_struct_h->h_addrsequence_num == 0)
  		 {
	     	     APL_DATA_MISSING("SEQUENCE_NUMBER",APL_NULL_STRING,APL_NULL_STRING)
		    }
    }

        if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                      APL_GOBACK_FAIL
/* Commented by Chirag ISKB 644 removed scheduled for all type of messages 
	if (strcmp(p_mt_msgaddress_struct_h->h_msg_ident_no,SETLPROBMSGNO) == 0)
	{
		if (strlen(p_mt_msgaddress_struct_h->h_schedule) == 0)
			APL_DATA_MISSING("SCHEDULE",APL_NULL_STRING,APL_NULL_STRING)
	}
Chirag 14032008 */
	if ( (strlen(p_mt_msgaddress_struct_h->h_swift_addr)>11) && ((strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"S") == 0) || (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"Q") == 0)))
	{
			CO_InsertErr(l_debug_info_ptr,ADDR_LEN_INCORRECT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
	}
	
	if ((strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"S") == 0)&&((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
	{
		if (strlen(p_mt_msgaddress_struct_h->h_swift_addr) == 0)
			APL_DATA_MISSING("SWIFT ADDR",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"C") == 0)
	{
		if (strlen(p_mt_msgaddress_struct_h->h_swift_addr) == 0)
		{
			if (strlen(p_mt_msgaddress_struct_h->h_gcn_addr) == 0)
				APL_DATA_MISSING("SWIFT ADDR/GCN",APL_NULL_STRING,APL_NULL_STRING)
		}
	}
	
	if (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"F") == 0)
	{
		if (strlen(p_mt_msgaddress_struct_h->h_fax_addr) == 0)
			APL_DATA_MISSING("FAX_ADDR",APL_NULL_STRING,APL_NULL_STRING)
	}
	
	if (strcmp(p_mt_msgaddress_struct_h->h_swift_tlx_gcn,"T") == 0)
	{
		if (strlen(p_mt_msgaddress_struct_h->h_infolex) == 0)
			APL_DATA_MISSING("TELEX NO",APL_NULL_STRING,APL_NULL_STRING)
		
	  /**No Check require for GCN Address 
        if (strlen(p_mt_msgaddress_struct_h->h_gcn_addr) == 0)
	     APL_DATA_MISSING("GCN_ADDR",APL_NULL_STRING,APL_NULL_STRING)**/
	}

	if (APL_FAILURE == MT_Rtv_AccFldVal(	p_mt_msgaddress_struct_h->h_dl_client,
													"mstacc",
													chr_l_mstclient,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}
   printf("WWWWWWWWWWWWWWWWWWWWWWWW\n");
   printf("Val of CLINET CODE == %s\n",p_mt_msgaddress_struct_h->h_dl_client);
   printf("Val of MASTER ACCOUNT ==%s\n",chr_l_mstclient);
   printf("Val HOLD_FLAG ==%s\n",p_mt_msgaddress_struct_h->h_holdings);//AIX Migration Changes
   printf("Val of h_msg_ident_no ==%s\n",p_mt_msgaddress_struct_h->h_msg_ident_no);
   printf("Val MSGNO MACRO ==%s\n",HOLDINGSMSGNO);//AIX Migration Changes
   printf("WWWWWWWWWWWWWWWWWWWWWWWW\n");
	if ((!strcmp(p_mt_msgaddress_struct_h->h_dl_client, chr_l_mstclient)) &&
		 (!strcmp(p_mt_msgaddress_struct_h->h_msg_ident_no, HOLDINGSMSGNO)) &&
		 (!strlen(p_mt_msgaddress_struct_h->h_holdings)))
	{
			strcpy(p_mt_msgaddress_struct_h->h_holdings,"N");
	}
   printf("Value checking2\n");

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	if (strcmp(p_mt_msgaddress_struct_h->h_msg_ident_no,SETLPROBMSGNO) == 0)
	{
		if (strcmp(p_mt_msgaddress_struct_h->h_schedule,"NNNN") == 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCNOT_VALIDMSG_CATEGORY,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}
	}
			
	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Client Code  Is %s \n",p_mt_msgaddress_struct_h->h_dl_client);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	}


        p_key_values[0]=p_mt_msgaddress_struct_h->h_dl_client;
    p_key_values[1]=ltoa(p_mt_msgaddress_struct_h->h_addrsequence_num);
    p_key_values[2]=p_mt_msgaddress_struct_h->h_msg_ident_no;
    p_key_values[3]=APL_NULL_STRING;

    APL_IF_DEBUG
    {
        printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
        printf("Master Check Conditions  Exists - |%c|\n",chr_iexist);
        printf("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
    }

    int_retval = CO_Chk_AccValid(p_mt_msgaddress_struct_h->h_dl_client,chr_iexist,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    chr_ideleted,
                                    NULL,
                                    NULL,
                                    l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL

	   /*int_retval = MT_Rtv_AccFldVal(p_mt_msgaddress_struct_h->h_dl_client,"ROWID",chr_l_field_val,l_debug_info_ptr);
	   if (int_retval != APL_SUCCESS)
	   	APL_GOBACK_FAIL
  	strcpy(chr_l_row_id_acct,chr_l_field_val);*/

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
    {
          chr_chld_iexist = 'N';
          chr_chld_ideleted = APL_NULL_CHAR;
          chr_chld_iauthorised = APL_NULL_CHAR;
    }
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
    {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = 'N';
          chr_chld_iauthorised = APL_NULL_CHAR;
    }
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = NULL;
          chr_chld_iauthorised = 'N';
    }
    APL_IF_DEBUG
    {
          printf("Master Details Exists in Proper Status ... \n");
          printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
          printf("Child Check Conditions Exists - |%c|\n",chr_chld_iexist);
          printf("Child Check Conditions Deleted - |%c|\n",chr_chld_ideleted);
          printf("Child Check Conditions Authorised - |%c|\n",chr_chld_iauthorised);

          printf("Key Codes 0 = |%s|\n",p_cln_key_codes[0]);
          printf("Key Codes 1 = |%s|\n",p_cln_key_codes[1]);
          printf("Key Codes 2 = |%s|\n",p_cln_key_codes[2]);

          printf("Key Value 0 = |%s|\n",p_key_values[0]);
          printf("Key Value 1 = |%s|\n",p_key_values[1]);
          printf("Key Value 2 = |%s|\n",p_key_values[2]);
    }


    int_retval = CO_Chk_ChldValid( p_cln_key_codes,
                                   p_key_values,
                                   chr_chld_iexist,
                                   chr_chld_iauthorised,
                                   chr_chld_ideleted,
                                   NULL,
                                   NULL,
                                   NULL,
                                   chr_chld_table_name,
                                   l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
           APL_GOBACK_FAIL

/* Check for Same Maker and Checker */

    if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
          int_retval = CR_Chk_ChldMkrChkr( p_cln_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

          if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL
   }

   if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) !=0)
   { 

		     int_retval = CR_Chk_AccMsgAddr(p_mt_msgaddress_struct_h->h_dl_client,p_mt_msgaddress_struct_h->h_msg_ident_no,p_mt_msgaddress_struct_h->h_addrsequence_num,"ROWID",chr_l_field_val,l_debug_info_ptr);

		     if (int_retval != APL_SUCCESS)
			        APL_GOBACK_FAIL

           strcpy(chr_l_row_id_acct,chr_l_field_val);

		     int_retval = CR_Chk_AccMsgAddr(p_mt_msgaddress_struct_h->h_dl_client,p_mt_msgaddress_struct_h->h_msg_ident_no,p_mt_msgaddress_struct_h->h_addrsequence_num,"access_stamp",chr_l_field_val,l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

         /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-Start*/
         if( strcmp(p_intl_env_data_struct_h->h_process, "U") == 0)
          {
             strcpy(p_mt_msgaddress_struct_h->h_access_stamp,chr_l_field_val);
          } /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-End*/

 APL_IF_DEBUG
           {
             printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
             printf("Access Stamp from Parameter String = |%s|\n",p_mt_msgaddress_struct_h->h_access_stamp);
           } 

		    if (strcmp(chr_l_field_val,p_mt_msgaddress_struct_h->h_access_stamp) != 0)
	     	 {
			      CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,"MSG ADDRESS REC",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			      APL_GOBACK_FAIL
		    }
    }
	
 /** Commentd Country Check strcpy(ch_mainfuncarea, "ACC_MAINT");
   strcpy(chr_l_condid, "BROKER_ADDR_ENABLE");
	int_l_condexists =0;	

   if(CO_Chk_CntryEnabled(ch_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr)==APL_FAILURE)
      APL_GOBACK_FAIL

   if (int_l_condexists == 0)
   {
	int_retval = CO_Chk_AccValid(p_mt_msgaddress_struct_h->h_dl_client,chr_iexist,chr_icubk,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
	}
	else
	{
	int_retval = CO_Chk_AccValid(p_mt_msgaddress_struct_h->h_dl_client,chr_iexist,chr_icubk,'Z',NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
	}
	

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL**/
	
	int_retval = MT_Mod_DBClientMsgAddr(p_mt_msgaddress_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
  	          		CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientMsgAddr SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientMsgAddr FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}


 /* Kouser - HDFCMT_001 - Added New Functions  */ 

 int MT_Mod_ClientReg(MT_REGDETAILS_STRUCT_H *p_mt_regdetails_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
    int							 int_retval;
    char                     chr_l_field_val[40];
    char                     chr_l_row_id_acct[APL_ROWID_LEN+1];
    char                     chr_l_buf[BUFFER_LEN];
    char                     chr_l_mstclient[APL_CLIENT_LENGTH]      =  APL_NULL_STRING;
    char                     ch_mainfuncarea[APL_MAINFUNCAREA_LEN]   =  APL_NULL_STRING;
    char                     chr_l_condid[APL_CONDID_LEN];
    short                    int_l_condexists;
    char                  	  chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
    char	  						  chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;
    char      		        	  chr_seq_num[5];
    char 		   			  chr_chld_table_name[50];

    APL_IF_DEBUG
              CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientReg\n",NULL,p_intl_env_data_struct_h);
        
    memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));
    memset(ch_mainfuncarea, APL_NULL_CHAR, APL_MAINFUNCAREA_LEN);
    memset(chr_l_condid, APL_NULL_CHAR, APL_CONDID_LEN);

    strcpy(chr_chld_table_name,"MT_REGDETAILS");
    chr_iexist = 'Y';
    chr_ideleted = 'N';

    char  *p_key_codes[2];
    char  *p_key_values[2];

    p_key_codes[0]="CLN_CODE";
    p_key_codes[1]=APL_NULL_STRING; 

    /* Start - Mandatory Data Check */

    if (strlen(p_mt_regdetails_struct_h->h_dl_client) == 0)
    { 
        APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING)
    }
 
     if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
    {
       if ((strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_no) == 0) &&  ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
       { 
           APL_DATA_MISSING("SEBI_REGNO",APL_NULL_STRING,APL_NULL_STRING)
       }
    
       if ((strcmp(p_intl_env_data_struct_h->h_process, "U")== 0)&&(strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)) /*DataPatch-CS0181192-Regreport upload-Kotubabu-Start*/
       { 
        if (strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_dt) == 0)
        {
           APL_DATA_MISSING("SEBI_REGDT",APL_NULL_STRING,APL_NULL_STRING)
        }
       
        if (strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_expdt) == 0)
        {
           APL_DATA_MISSING("SEBI_REGEXPDT",APL_NULL_STRING,APL_NULL_STRING)
        }
       }   /*DataPatch-CS0181192-Regreport upload-Kotubabu-End*/ 
		/*	Remove Mandatory cond for RBI Reg Detail	*/ 
		/** 
       if (strlen(p_mt_regdetails_struct_h->h_cln_rbi_reg_no) == 0)
       {
           APL_DATA_MISSING("RBI_REGNO",APL_NULL_STRING,APL_NULL_STRING)
       }
		 **/
     }

  /* Kouser - HDFCMT_001 - SEBI No,RBI No Check for related Modes */
	/*
    if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
    {
          int_retval = CR_Chk_SebiNoValid(p_mt_regdetails_struct_h->h_cln_sebi_reg_no,p_mt_regdetails_struct_h->h_dl_client,l_debug_info_ptr);
			 printf("\n after CR_Chk_SebiNoValid ret val is |%d|",int_retval);

          if (int_retval == APL_RECS_EXIST)
          {
			 printf("\n Inside rec exists after CR_Chk_SebiNoValid ret val is |%d|",int_retval);

          if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)
          {
			 printf("\n Inside rec exists inside input after CR_Chk_SebiNoValid ret val is |%d|",int_retval);
                       printf("Val of Mode p_intl_env_data_struct_h->h_mode ==|%s|\n",p_intl_env_data_struct_h->h_mode);
                       CO_InsertErr(l_debug_info_ptr,ERR_SEBINO_EXIST_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
           }
                 else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
					  {
			 				printf("\n Inside rec exists inside modify after CR_Chk_SebiNoValid ret val is |%d|",int_retval);
                          CO_InsertErr(l_debug_info_ptr,ERR_SEBINO_EXIST_OTHER_MODIFY,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
					  }
          }


			 printf("\n Outside  rec exists after CR_Chk_SebiNoValid ret val is |%d|",int_retval);
                if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
					 {
			 				printf("\n Inside  error check returning now ... after CR_Chk_SebiNoValid ret val is |%d|",int_retval);
                      APL_GOBACK_FAIL
					 }

          int_retval = CR_Chk_RbiNoValid(p_mt_regdetails_struct_h->h_cln_rbi_reg_no,p_mt_regdetails_struct_h->h_dl_client,l_debug_info_ptr);
          if (int_retval == APL_RECS_EXIST)
          {
           
          if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)
          {
                       printf("Val of Mode p_intl_env_data_struct_h->h_mode ==|%s|\n",p_intl_env_data_struct_h->h_mode);
             CO_InsertErr(l_debug_info_ptr,ERR_RBINO_EXIST_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
           }
                 else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
                 CO_InsertErr(l_debug_info_ptr,ERR_RBINO_EXIST_OTHER_MODIFY,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
          } 
                  
        if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                      APL_GOBACK_FAIL

 
     }
 		*/
        /* Kouser - HDFCMT_001 - SEBI No,RBI No Check for related Modes */

    if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
    {
      printf(" Val of  Reg SEBI DATE ==%s\n",p_mt_regdetails_struct_h->h_cln_sebi_reg_dt);
      if (strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_dt) != 0)
      {
         int_retval = CR_Chk_RegDateValid(p_mt_regdetails_struct_h->h_cln_sebi_reg_dt,l_debug_info_ptr);
        if (int_retval == APL_RECS_EXIST)
        {
                  CO_InsertErr(l_debug_info_ptr,ERR_SEBI_REGDATE_PASSED,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                      APL_GOBACK_FAIL
        }

      } 

      printf(" Val of  Reg RBI DATE ==%s\n",p_mt_regdetails_struct_h->h_cln_rbi_reg_dt);
      if (strlen(p_mt_regdetails_struct_h->h_cln_rbi_reg_dt) != 0)
      {
         int_retval = CR_Chk_RegDateValid(p_mt_regdetails_struct_h->h_cln_rbi_reg_dt,l_debug_info_ptr);


      if (int_retval == APL_RECS_EXIST)
      {
             CO_InsertErr(l_debug_info_ptr,ERR_RBI_REGDATE_PASSED,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                     APL_GOBACK_FAIL
      }

      } 

       if ((strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_dt) !=0) && (strlen(p_mt_regdetails_struct_h->h_cln_sebi_reg_expdt) != 0))
       {
          int_retval = CR_Chk_ExpDateValid(p_mt_regdetails_struct_h->h_cln_sebi_reg_dt,p_mt_regdetails_struct_h->h_cln_sebi_reg_expdt,l_debug_info_ptr);

          if (int_retval == APL_RECS_EXIST)
          {
              CO_InsertErr(l_debug_info_ptr,ERR_SEBIREGDT_GRTEXPDT_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                  APL_GOBACK_FAIL
          }
      }

      if ((strlen(p_mt_regdetails_struct_h->h_cln_rbi_reg_dt) !=0) && (strlen(p_mt_regdetails_struct_h->h_cln_rbi_reg_expdt) != 0))
      {
            int_retval = CR_Chk_ExpDateValid(p_mt_regdetails_struct_h->h_cln_rbi_reg_dt,p_mt_regdetails_struct_h->h_cln_rbi_reg_expdt,l_debug_info_ptr);

             if( int_retval == APL_RECS_EXIST)
             {
                     CO_InsertErr(l_debug_info_ptr,ERR_RBIREGDT_GRTEXPDT_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                         APL_GOBACK_FAIL
             }
      }
       /* Kouser - HDFCMT_001 - MapInId,UccCode Check for respective Modes */

      if (strlen(p_mt_regdetails_struct_h->h_cln_mapinid) != 0)
      {
            int_retval = CR_Chk_MapInValid(p_mt_regdetails_struct_h->h_cln_mapinid,p_mt_regdetails_struct_h->h_dl_client,l_debug_info_ptr);
            if (int_retval == APL_RECS_EXIST)
            {
              if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)
               {
                    CO_InsertErr(l_debug_info_ptr,ERR_MAPINID_EXSTINACC_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
               }
               else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
                     CO_InsertErr(l_debug_info_ptr,ERR_MAPIN_EXIST_OTHER_MODIFY,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

            }

                 if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                     APL_GOBACK_FAIL
      }

      if (strlen(p_mt_regdetails_struct_h->h_cln_ucc_code) != 0)
      {
            int_retval = CR_Chk_UccCodeValid(p_mt_regdetails_struct_h->h_cln_ucc_code,p_mt_regdetails_struct_h->h_dl_client,l_debug_info_ptr);
            if (int_retval == APL_RECS_EXIST)
            {
               if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)
                {
                   CO_InsertErr(l_debug_info_ptr,ERR_UCC_CODE_EXSTINACC_CANT_INP,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
                 }
                  else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
                         CO_InsertErr(l_debug_info_ptr,
												 ERR_UCCCODE_EXIST_OTHER_MODIFY,
                                     APL_NULL_STRING,
                                     APL_NULL_STRING,
                                     APL_NULL_STRING,__LINE__,__FILE__);

            }

                    if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                     APL_GOBACK_FAIL 

      }
       /* Kouser - HDFCMT_001 - MapInId,UccCode Check for respective Modes */
    }

    APL_IF_DEBUG
    {
         memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
         sprintf(chr_l_buf,"Client Code =%s\n",p_mt_regdetails_struct_h->h_dl_client);
         CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
    
         memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
         sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h->h_mode);
         CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
    }

    if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0))
     {
                if (p_mt_regdetails_struct_h->h_access_stamp == 0)
                {
                        APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
                }

     }
     
	 /* Status 'DU' - Invalid Status for Modify  Mode - Kouser  */

    if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
    {
         if(strcmp(p_mt_regdetails_struct_h->h_status,STATUS_DEL_UAUTH) == 0)
			{			
		         CO_InsertErr(l_debug_info_ptr,
               MAP_DET_MARKEDDEL, 
               APL_NULL_STRING,
               APL_NULL_STRING,
               APL_NULL_STRING,
					__LINE__,
					__FILE__);
					APL_GOBACK_FAIL
         }
    
	  }

    APL_IF_DEBUG
    {
        memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
        sprintf(chr_l_buf,"Account is %s \n",p_mt_regdetails_struct_h->h_dl_client);
        CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
    }

        p_key_values[0]=p_mt_regdetails_struct_h->h_dl_client;
        p_key_values[1]=APL_NULL_STRING;

    APL_IF_DEBUG
    {
        printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
        printf("Master Check Conditions  Exists - |%c|\n",chr_iexist);
        printf("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
    }

        int_retval = CO_Chk_AccValid(p_mt_regdetails_struct_h->h_dl_client,chr_iexist,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    chr_ideleted,
                                    NULL,
                                    NULL,
                                    l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
               APL_GOBACK_FAIL

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
    {
        chr_chld_iexist = 'N';
        chr_chld_ideleted = APL_NULL_CHAR;
        chr_chld_iauthorised = APL_NULL_CHAR;
    }

    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
               (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
    {
             chr_chld_iexist = 'Y';
             chr_chld_ideleted = 'N';
             chr_chld_iauthorised = APL_NULL_CHAR;
    }
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
         chr_chld_iexist = 'Y';
         chr_chld_ideleted = NULL;
         chr_chld_iauthorised = 'N';
    }

    APL_IF_DEBUG
    {
         printf("Master Details Exists in Proper Status ... \n");
         printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
         printf("Child Check Conditions Exists - |%c|\n",chr_chld_iexist);
         printf("Child Check Conditions Deleted - |%c|\n",chr_chld_ideleted);
         printf("Child Check Conditions Authorised - |%c|\n",chr_chld_iauthorised);

         printf("Key Codes 0 = |%s|\n",p_key_codes[0]);
         printf("Key Codes 1 = |%s|\n",p_key_codes[1]);
         printf("Key Value 0 = |%s|\n",p_key_values[0]);
         printf("Key Value 1 = |%s|\n",p_key_values[1]);
    }

     int_retval = CO_Chk_ChldValid( p_key_codes,
                                      p_key_values,
                                      chr_chld_iexist,
                                      chr_chld_iauthorised,
                                      chr_chld_ideleted,
                                      NULL,
                                      NULL,
                                      NULL,
                                      chr_chld_table_name,
                                      l_debug_info_ptr);

     if (int_retval != APL_SUCCESS)
	  {
		  if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0)
		  {

				strcpy(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT);
                                CO_FreeErrLst(l_debug_info_ptr);


                        /**   chr_chld_iexist = 'N';
     			int_retval = CO_Chk_ChldValid( p_key_codes,
                                      p_key_values,
                                      chr_chld_iexist,
                                      APL_NULL_CHAR,
                                      APL_NULL_CHAR,
                                      NULL,
                                      NULL,
                                      NULL,
                                      chr_chld_table_name,
                                      l_debug_info_ptr);

     if (int_retval != APL_SUCCESS)
	  	 {
				CO_FreeErrLst(l_debug_info_ptr);
				strcpy(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT);
		 }**/			
	  	}
     }


    /* Check for Same Maker and Checker */

    if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
          int_retval = CR_Chk_ChldMkrChkr( p_key_codes,
                                           p_key_values,
                                           chr_chld_table_name,
                                           p_intl_env_data_struct_h->usr,
                                           l_debug_info_ptr);

          if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL
    }

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
    {
         int_retval = CR_Rtv_MastChldChrVal  (   p_key_codes,
                                                 p_key_values,
                                                 chr_chld_table_name,
                                                 "ROWID",
                                                 chr_l_field_val,
                                                 l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        strcpy(chr_l_row_id_acct,chr_l_field_val);

        int_retval = CR_Rtv_MastChldChrVal  (   p_key_codes,
                                                p_key_values,
                                                chr_chld_table_name,
                                                "access_stamp",
                                                chr_l_field_val,
                                                l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-Start*/
        if( strcmp(p_intl_env_data_struct_h->h_process, "U") == 0)
        {
          strcpy(p_mt_regdetails_struct_h->h_access_stamp,chr_l_field_val);
        } /*DataPatch-CS0181192-ClientUpload upload-Kotubabu-End*/

       APL_IF_DEBUG
       {
          printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
          printf("Access Stamp from Parameter String = |%s|\n",p_mt_regdetails_struct_h->h_access_stamp);
       }

      if (strcmp(chr_l_field_val,p_mt_regdetails_struct_h->h_access_stamp) != 0)
      {
                        CO_InsertErr(  l_debug_info_ptr,
                                       ERR_ACCESSSTAMP_CHGD,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       __LINE__,
                                       __FILE__);
                       APL_GOBACK_FAIL
      }
    }

    int_retval = MT_Mod_DBClientRegDetails(p_mt_regdetails_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

    APL_GOBACK_SUCCESS

    RETURN_SUCCESS :
    {
          APL_IF_DEBUG
                      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientReg SUCCESS \n",NULL,p_intl_env_data_struct_h);
          return(APL_SUCCESS);
    }

    RETURN_FAILURE :
    {
          APL_IF_DEBUG
                      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientReg FAILURE \n",NULL,p_intl_env_data_struct_h);
    return(APL_FAILURE);
    }
  } 

 int MT_Mod_ClientOth(char *chr_p_acct,char *chr_p_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int							int_retval;
	short							int_l_condexists;
	char							chr_l_field_val[40];
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	char							chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed,chr_iauthorised;
	char							chr_l_row_id_acct[APL_ROWID_LEN+1];
	char							chr_l_buf[BUFFER_LEN];
        
 char *p_cln_key_codes[2];
 char *p_key_values[2];

 p_cln_key_codes[0]="CLN_CODE";
 p_cln_key_codes[1]=APL_NULL_STRING;
 p_key_values[0]=chr_p_acct;
 p_key_values[1]=APL_NULL_STRING;

	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientOth \n",NULL,p_intl_env_data_struct_h);

	memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

	if (strlen(chr_p_acct) == 0)
		APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_p_acct_access_stamp) == 0)
		APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL
	
	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Account is %s \n",chr_p_acct);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h->usr);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
	
      /**Commonsys ParamCommented 	
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);**/
   
    }	
  
  if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) != 0) 
  { 
	int_retval = MT_Rtv_AccFldVal(chr_p_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_acct,chr_l_field_val);
   printf("Val of client\n");	
	
	
	int_retval = MT_Rtv_AccFldVal(chr_p_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
      {
             printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
             printf("Access Stamp from Parameter String = |%s|\n",chr_p_acct_access_stamp);
     }

		
	strcpy(chr_p_acct_access_stamp,chr_l_field_val);	
		
	if (strcmp(chr_l_field_val,chr_p_acct_access_stamp) != 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,chr_p_acct,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}
   }
	
	if (strcmp(chr_p_acct, l_mt_core_sys_params_struct_h.custody_clt_cd) == 0)
	{
		if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
			CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_ACC_CANT_DEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
			CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_ACC_CANT_CLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
			CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_ACC_CANT_FREEZE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		
	}
	
	if (strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0)
	{
		if (strcmp(chr_p_acct, l_mt_core_sys_params_struct_h.brokerage_cd) == 0)
		{
			if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_BRKACC_CANT_DEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_BRKACC_CANT_CLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_INTRNL_BRKACC_CANT_FREEZE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		}
	}
   printf("Chek for l_mt_core_sys_params_struct_h.ord_proc_ind\n"); 
	
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

   printf("Before Enter Into DELETE Mode\n");

	if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)
	{
		chr_iexist = 'Y';
		chr_ideleted = 'N';
		chr_ifrozen = 'N';
		chr_iclosed = 'N';

		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		int_retval = MT_Rtv_AccFldVal(chr_p_acct,"status",chr_l_field_val,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
		
		if (strcmp(chr_l_field_val, STATUS_UNFROZ_UAUTH) == 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_MARKEDFORUNFRZN,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}
		else if (strcmp(chr_l_field_val, STATUS_OPEN_UAUTH) == 0)
		{
			CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_MARKEDFORREPON,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			APL_GOBACK_FAIL
		}
	
      APL_IF_DEBUG
		    {
			   printf("Calling Func CR_Chk_CodeInChld with following Details...\n");
			   printf("Key Code 0 = |%s|\n",p_cln_key_codes[0]);
		   	printf("Key Code 1 = |%s|\n",p_cln_key_codes[1]);
		   	printf("Key Value 0 = |%s|\n",p_key_values[0]);
		   	printf("Key Value 1 = |%s|\n",p_key_values[1]);
		    }

		    int_retval = CR_Chk_CodeInChld(		p_cln_key_codes,
                                           p_key_values,
                                           g_cln_chld_table_names,
                                           p_intl_env_data_struct_h,
                                           l_debug_info_ptr); 

		    if (int_retval != APL_SUCCESS)
		    {
		       	      CO_InsertErr(  l_debug_info_ptr,
       			       	         MAP_CLIENT_EXIST_CANTDEL,
			                           "Mapping Details Exist",
			                           chr_p_acct,
				                        APL_NULL_STRING,
		                        	   __LINE__,
	                        			__FILE__);

		       	      /*if( (APL_FAILURE == CO_InsertErr(  l_debug_info_ptr,
       			       	         MAP_CLIENT_EXIST_CANTDEL,
			                           "Mapping Details Exist",
			                           chr_p_acct,
				                        APL_NULL_STRING,
		                        	   __LINE__,
	                        			__FILE__)))*/
        } 
        else if (int_retval == APL_FAILURE)
              APL_GOBACK_FAIL
      } 

	if ((strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0))
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'N';

		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,NULL,NULL,NULL,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
		
		int_retval = CR_Chk_AccAuth(chr_p_acct,p_intl_env_data_struct_h->usr,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_ifrozen = 'N';
		chr_iclosed = 'N';

		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,NULL,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
		
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	if (strcmp(p_intl_env_data_struct_h->h_mode,OPEN_MODE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_iclosed = 'Y';

		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,NULL,NULL,chr_iclosed,l_debug_info_ptr);
		
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_ifrozen = 'N';
		chr_iclosed = 'N';
		
		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,NULL,chr_ifrozen,chr_iclosed,l_debug_info_ptr);
		
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}
	
	if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_UNFREEZE) == 0)
	{
		chr_iexist = 'Y';
		chr_iauthorised = 'Y';
		chr_ifrozen = 'Y';

		int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,chr_iauthorised,NULL,chr_ifrozen,NULL,l_debug_info_ptr);
		
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL
	}


	if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0))
	{
		if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
		{
			strcpy(chr_mainfuncarea, "ACCDEL_VTBACCOUNT");
			strcpy(chr_l_condid, "VTBACCOUNT_CANT_DEL");
		}
		else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
		{
			strcpy(chr_mainfuncarea, "ACCCLS_VTBACCOUNT");
			strcpy(chr_l_condid, "VTBACCOUNT_CANT_CLS");
		}
		else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
		{
			strcpy(chr_mainfuncarea, "ACCFRZ_VTBACCOUNT");
			strcpy(chr_l_condid, "VTBACCOUNT_CANT_FRZ");
		}

		int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if (int_l_condexists > 0)
		{
			if (strcmp(chr_p_acct, l_mt_core_sys_params_struct_h.vtb_clt_code) == 0)
			{
				if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_VTBACC_CANTDEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_VTBACC_CANTCLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				else if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_FREEZE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_VTBACC_CANTFRZN,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			
			}
		}

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			APL_GOBACK_FAIL
	}


	if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0))
	{
		if (strcmp(g_mt_commonsys_params_struct_h.ca_module_ind, "Y") == 0)
		{
			int_retval = CR_Chk_AccEntl(chr_p_acct,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
			{
				if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_ENTITLE_EXSTINACC_CANT_DEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_ENTITLE_EXSTINACC_CANT_CLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
		}

		

		int_retval = CR_Chk_AccTrd(chr_p_acct,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_TRDSEXIST_CANTDEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_TRDSEXIST_CANTCLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL

		int_retval = CR_Chk_AccPos(chr_p_acct,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCPOSN_EXISTS_CANTDEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_ACCPOSN_EXISTS_CANTCLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL
	
		if (strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0)
		{
			int_retval = CR_Chk_AccOrd(chr_p_acct,l_debug_info_ptr);

			if (int_retval == APL_RECS_EXIST)
			{
				if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_ACCORD_EXISTS_CANTDEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
					CO_InsertErr(l_debug_info_ptr,ERR_ACCORD_EXISTS_CANTCLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
   	}

		int_retval = CR_Chk_AccDomPtyTrd(chr_p_acct,l_debug_info_ptr);

		if (int_retval == APL_RECS_EXIST)
		{
			if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_CNTRPARTY_ACC_CANT_DEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
				CO_InsertErr(l_debug_info_ptr,ERR_CNTRPARTY_ACC_CANT_CLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
			
		}
		else if (int_retval == APL_FAILURE)
			APL_GOBACK_FAIL

		int_retval = MT_Rtv_AccFldVal(chr_p_acct,"mstacc",chr_l_field_val,l_debug_info_ptr);
		if (int_retval == APL_SUCCESS)
		{
			if (strcmp(chr_p_acct,chr_l_field_val) == 0)
			{
				int_retval = CR_Chk_SubAcc(chr_p_acct,l_debug_info_ptr);
		
				if (int_retval == APL_SUCCESS)
				{
					if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
						CO_InsertErr(l_debug_info_ptr,ERR_SUBACC_EXISTS_CANTDEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
					else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
						CO_InsertErr(l_debug_info_ptr,ERR_SUBACC_EXISTS_CANTCLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		
				}
			}
		}

		if (strcmp(l_mt_core_sys_params_struct_h.ord_proc_ind, "Y") == 0)
		{
			if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
			{
				strcpy(chr_mainfuncarea, "ACCDEL_BROKINORD_CHK");
				strcpy(chr_l_condid, "BROK_IN_ORD_CANT_DEL");
			}
			else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
			{
				strcpy(chr_mainfuncarea, "ACCCLS_BROKINORD_CHK");
				strcpy(chr_l_condid, "BROK_IN_ORD_CANT_CLS");
			}
	
			int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
				APL_GOBACK_FAIL
		
			if (int_l_condexists > 0)	
			{
				int_retval = CR_Chk_AccBrkOrd(chr_p_acct,l_debug_info_ptr);

				if (int_retval == APL_RECS_EXIST)
				{
					if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0)
						CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_BRK_ORD_CANT_DEL,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
					else if (strcmp(p_intl_env_data_struct_h->h_mode,CLS_MODE) == 0)
						CO_InsertErr(l_debug_info_ptr,ERR_ACCOUNT_BRK_ORD_CANT_CLOSE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
				
				}
				else if (int_retval == APL_FAILURE)
					APL_GOBACK_FAIL
			}
		}

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			APL_GOBACK_FAIL
	}

	int_retval = MT_Mod_DBClientOth(chr_p_acct,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientOth SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}
	
	RETURN_FAILURE :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientOth FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
}

int MT_Mod_ClientSign(char *chr_p_acct, int chr_p_acct_sign_id, char *chr_p_acct_sign_memo,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
    char                    chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed;
    char                    chr_l_row_id_acct[APL_ROWID_LEN+1];
    char                    chr_l_buf[BUFFER_LEN];
    int 						   int_retval;										


    char *p_cln_key_codes[2];
    char *p_key_values[2];
   
    p_cln_key_codes[0]="CLN_CODE";
    p_cln_key_codes[1]=APL_NULL_STRING;

    p_key_values[0]=chr_p_acct;
    p_key_values[1]=APL_NULL_STRING;


   APL_IF_DEBUG
                CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientSign \n",NULL,p_intl_env_data_struct_h);
        memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));
        printf("Before checking length of code\n");
        printf("Before checking length of code is ===%s\n",chr_p_acct);

        if (strlen(chr_p_acct) == 0)
                APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)

        printf("Before checking Sign Id\n");

        printf("Before checking Sign Id is ===%d\n",chr_p_acct_sign_id);

        if (chr_p_acct_sign_id == 0)
	{
	printf("I am HERE inside ==0\n");
	fflush(stdout);
                APL_DATA_MISSING("SIGN ID",APL_NULL_STRING,APL_NULL_STRING)
	}

          printf("After checking Sign Id is ===%d\n",chr_p_acct_sign_id);

        if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                APL_GOBACK_FAIL

         APL_IF_DEBUG
         {
                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"Account is %s \n",chr_p_acct);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h->usr);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h->h_mode);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);

        }

        if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0) || (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
        {
                chr_iexist = 'Y';
                chr_ideleted = 'N';
                chr_ifrozen = 'N';
                chr_iclosed = 'N';

                int_retval = CO_Chk_AccValid(chr_p_acct,chr_iexist,NULL,NULL,NULL,NULL,chr_ideleted,chr_ifrozen,chr_iclosed,l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        }

        int_retval = MT_Mod_DBClientSign(chr_p_acct,chr_p_acct_sign_id,chr_p_acct_sign_memo,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        APL_GOBACK_SUCCESS

    RETURN_SUCCESS :
        {
                APL_IF_DEBUG
                        CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientSign SUCCESS \n",NULL,p_intl_env_data_struct_h);
                return(APL_SUCCESS);
        }            

      RETURN_FAILURE :
        {
                APL_IF_DEBUG
                        CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientSign FAILURE \n",NULL,p_intl_env_data_struct_h);
                return(APL_FAILURE);
        }
}

  
int MT_Mod_ClientExchMap(MT_CLTEXCHMAP_STRUCT_H *p_mt_cltexchmap_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int							 int_retval;
   char                   chr_l_row_id_acct[APL_ROWID_LEN+1];
   char                   chr_l_buf[BUFFER_LEN];
   char	     			  	 chr_l_field_val[40];
   char		    			 chr_chld_tab_name[50];
   char 	                chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
   char 						 chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;			 
   char  						 chr_seq_num[5];
   char			    		 chr_chld_table_name[50];

   APL_IF_DEBUG
        CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientExchMap \n",NULL,p_intl_env_data_struct_h);

        memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

        strcpy(chr_chld_table_name,"MT_CLI_EXCH_MAP");
        chr_iexist = 'Y';
        chr_ideleted = 'N';

        char  *p_cln_key_codes[4];
        char  *p_key_values[4];

        p_cln_key_codes[0]="CLN_CODE";
        p_cln_key_codes[1]="CLN_SEQ_NUM"; /* Common Name for All Sub Tabs */
        p_cln_key_codes[2]="CLN_EXCH_CODE";
        p_cln_key_codes[3]=APL_NULL_STRING;

        /* Start - Mandatory Data Check */

        if (strlen(p_mt_cltexchmap_struct_h->h_dl_client) == 0)
                APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)

        if (strlen(p_mt_cltexchmap_struct_h->h_cln_exch_code) == 0)
        { 
                APL_DATA_MISSING("EXCH_CODE",APL_NULL_STRING,APL_NULL_STRING)
         }
         else
         {
           int_retval = CO_Chk_CodeValid("EXCHANGE",
                                          p_mt_cltexchmap_struct_h->h_cln_exch_code, 
                                          APL_COUNTRY_CODE,
                                          l_debug_info_ptr);

                if (int_retval !=APL_SUCCESS)
                {
                    CO_InsertErr(  l_debug_info_ptr,
                                   ERR_INVALID_CODE,
                                   p_mt_cltexchmap_struct_h->h_cln_exch_code,
                                   APL_NULL_STRING,
                                   APL_NULL_STRING,
                                   __LINE__,
                                   __FILE__);
                    APL_GOBACK_FAIL 
                }
			} 


        /**if (strlen(p_mt_cltexchmap_struct_h->h_cln_exch_code) == 0)
        { 
                APL_DATA_MISSING("EXCH_CODE",APL_NULL_STRING,APL_NULL_STRING)
         }
         else
         {
           int_retval = CO_Chk_CodeValid("EXCHANGE",
                                          p_mt_cltexchmap_struct_h->h_cln_exch_code, 
                                          g_mt_commonsys_params_struct_h.nation_code,  
                                          l_debug_info_ptr);

                if (int_retval !=APL_SUCCESS)
                {
                    CO_InsertErr(  l_debug_info_ptr,
                                   ERR_INVALID_CODE,
                                   p_mt_cltexchmap_struct_h->h_cln_exch_code,
                                   APL_NULL_STRING,
                                   APL_NULL_STRING,
                                   __LINE__,
                                   __FILE__);
                    APL_GOBACK_FAIL 
                }
        }**/ 

	 IF_COND_EXISTS("CLN_MAINT","CM_ID_MAND")
	 {
     if (strlen(p_mt_cltexchmap_struct_h->h_cln_hdfc_cm_id) == 0)
     { 
                APL_DATA_MISSING("HDFC_CM_ID",APL_NULL_STRING,APL_NULL_STRING)
     } 
     else
     {
          int_retval = CO_Chk_CodeValid("HDFCID",
                                          p_mt_cltexchmap_struct_h->h_cln_hdfc_cm_id,
                                          APL_COUNTRY_CODE,
                                          l_debug_info_ptr);

           if (int_retval !=APL_SUCCESS)
           {
             CO_InsertErr(  l_debug_info_ptr,
                            ERR_INVALID_CODE,
                            p_mt_cltexchmap_struct_h->h_cln_hdfc_cm_id,
                            APL_NULL_STRING,
                            APL_NULL_STRING,
                            __LINE__,
                            __FILE__);
             APL_GOBACK_FAIL
           }
    }
	 }


        if (strlen(p_mt_cltexchmap_struct_h->h_cln_exch_map_code) == 0)
                APL_DATA_MISSING("EXCH_MAP_CODE",APL_NULL_STRING,APL_NULL_STRING)

        /* End - Mandatory Data Check */

        if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
        { 
                if (p_mt_cltexchmap_struct_h->h_access_stamp == 0)
                { 
                        APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
                } 

                if (p_mt_cltexchmap_struct_h->h_cln_exchseq_num == 0)
                { 
                        APL_DATA_MISSING("SEQUENCE_NUMBER",APL_NULL_STRING,APL_NULL_STRING)
                } 
        }           
                if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                        APL_GOBACK_FAIL

        APL_IF_DEBUG
        {
                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"Account is %s \n",p_mt_cltexchmap_struct_h->h_dl_client);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
        }

        p_key_values[0]=p_mt_cltexchmap_struct_h->h_dl_client;
        p_key_values[1]=ltoa(p_mt_cltexchmap_struct_h->h_cln_exchseq_num);
        p_key_values[2]=p_mt_cltexchmap_struct_h->h_cln_exch_code;
        p_key_values[3]=APL_NULL_STRING;

        APL_IF_DEBUG
        {
            printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
            printf("Master Check Conditions  Exists - |%c|\n",chr_iexist);
            printf("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
        }
        
        int_retval = CO_Chk_AccValid(p_mt_cltexchmap_struct_h->h_dl_client,chr_iexist,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    chr_ideleted,
                                    NULL,
                                    NULL,
                                    l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL
 
        if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
        {
            chr_chld_iexist = 'N';
            chr_chld_ideleted = APL_NULL_CHAR;
            chr_chld_iauthorised = APL_NULL_CHAR;

        APL_IF_DEBUG
        {
            printf("Key Codes 0 = |%s|\n",p_cln_key_codes[0]);
            printf("Key Codes 1 = |%s|\n",p_cln_key_codes[1]);
            printf("Key Codes 2 = |%s|\n",p_cln_key_codes[2]);

            printf("Key Value 0 = |%s|\n",p_key_values[0]);
            printf("Key Value 1 = |%s|\n",p_key_values[1]);
            printf("Key Value 2 = |%s|\n",p_key_values[2]); 
        }

        int_retval = CO_Chk_ChldValid( p_cln_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);   
        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL
        } 

   else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;

      int_retval = CO_Chk_ChldValid(          p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_iexist,
                                              chr_chld_iauthorised,
                                              chr_chld_ideleted,
                                              NULL,
                                              NULL,
                                              NULL,
                                              chr_chld_table_name,
                                              l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
               APL_GOBACK_FAIL
    } 
      
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';

      int_retval = CO_Chk_ChldValid(          p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_iexist,
                                              chr_chld_iauthorised,
                                              chr_chld_ideleted,
                                              NULL,
                                              NULL,
                                              NULL,
                                              chr_chld_table_name,
                                              l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
          APL_GOBACK_FAIL
     }

     /* Check for Same Maker and Checker */
  
     if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
     {

          int_retval = CR_Chk_ChldMkrChkr( p_cln_key_codes,
                                           p_key_values,
                                           chr_chld_table_name,
                                           p_intl_env_data_struct_h->usr,
                                           l_debug_info_ptr);

          if (int_retval !=APL_SUCCESS)
              APL_GOBACK_FAIL
     }


     if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
     {
         int_retval = CR_Rtv_MastChldChrVal  (   p_cln_key_codes,
                                                 p_key_values,
                                                 chr_chld_table_name,
                                                 "ROWID",
                                                 chr_l_field_val,
                                                 l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

         strcpy(chr_l_row_id_acct,chr_l_field_val);

         int_retval = CR_Rtv_MastChldChrVal  (p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_table_name,
                                              "access_stamp",
                                              chr_l_field_val,
                                              l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
                 APL_GOBACK_FAIL

         APL_IF_DEBUG
         {
            printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
            printf("Access Stamp from Parameter String = |%s|\n",p_mt_cltexchmap_struct_h->h_access_stamp);
         }
 

         if (strcmp(chr_l_field_val,p_mt_cltexchmap_struct_h->h_access_stamp) != 0)
         {
                        CO_InsertErr(  l_debug_info_ptr,
                                       ERR_ACCESSSTAMP_CHGD,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       __LINE__,
                                       __FILE__);
                        APL_GOBACK_FAIL
         }
     }


    int_retval = MT_Mod_DBClientExchMap(p_mt_cltexchmap_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL
    printf("Val of Sequeeeeeeeeeeen No ==%d\n",p_mt_cltexchmap_struct_h->h_cln_exchseq_num);


    APL_GOBACK_SUCCESS

    RETURN_SUCCESS :
    {
                APL_IF_DEBUG
                        CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientExchMap SUCCESS \n",NULL,p_intl_env_data_struct_h);
                        return(APL_SUCCESS);
    }

    RETURN_FAILURE :
    {
                APL_IF_DEBUG
                        CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientExchMap FAILURE \n",NULL,p_intl_env_data_struct_h);
                        return(APL_FAILURE);
    }
} 

 /* Kouser - RFSNo - HDFCMT_001 - Client Master Maintenance */

 int MT_Mod_ClientDepoMap(MT_CLTDEPOMAP_STRUCT_H *p_mt_cltdepomap_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int							 int_retval;
   char                   chr_l_row_id_acct[APL_ROWID_LEN+1];
   char                   chr_l_buf[BUFFER_LEN];
   char                   chr_l_field_val[40];
   char                   chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
   char                   chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;
   char                   chr_seq_num[5];
   char		             chr_chld_table_name[50];			
      
   APL_IF_DEBUG
             CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientDepoMap \n",NULL,p_intl_env_data_struct_h);

    memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));
 
    
    strcpy(chr_chld_table_name,"MT_CLI_DEPO_MAP");
    chr_iexist = 'Y';
    chr_ideleted = 'N';
    char  *p_cln_key_codes[4];
    char  *p_key_values[4];

    p_cln_key_codes[0]="CLN_CODE";
    p_cln_key_codes[1]="CLN_SEQ_NUM";
    p_cln_key_codes[2]="CLN_DEPO_CODE";
    p_cln_key_codes[3]=APL_NULL_STRING;

    /* Start - Mandatory Data Check */ 

    if (strlen(p_mt_cltdepomap_struct_h->h_dl_client) == 0)
        APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING)

    if (strlen(p_mt_cltdepomap_struct_h->h_cln_depo_code) == 0)
    { 
        APL_DATA_MISSING("DEPO_CODE",APL_NULL_STRING,APL_NULL_STRING)
    }
    else
    { 
        int_retval = CO_Chk_CodeValid("DEPOSITORY",
                                       p_mt_cltdepomap_struct_h->h_cln_depo_code,
                                       APL_COUNTRY_CODE,
                                       l_debug_info_ptr);

        if (int_retval !=APL_SUCCESS)
        {
           CO_InsertErr(  l_debug_info_ptr,
                          ERR_INVALID_CODE,
                          p_mt_cltdepomap_struct_h->h_cln_depo_code,
                          APL_NULL_STRING,
                          APL_NULL_STRING,
                          __LINE__,
                          __FILE__);
           APL_GOBACK_FAIL    
        } 
    }
    
/*Start- ISKB-328 -For Vault maintenance mandatory check not required -Rahul*/
    if ((strlen(p_mt_cltdepomap_struct_h->h_cln_depo_code) != 0) && (strcmp(p_mt_cltdepomap_struct_h->h_cln_depo_code,"VAUL") != 0))
{
    if((strcmp(p_mt_cltdepomap_struct_h->h_cln_depo_code,"CSGL")) && ((strcmp(p_intl_env_data_struct_h->h_process, "U") != 0) || ((strcmp(p_intl_env_data_struct_h->h_process, "U") == 0) && (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) == 0)))) /*DataPatch-CS0181192-Mandatory for Add-Pavan */
	{
    if (strlen(p_mt_cltdepomap_struct_h->h_cln_depo_map_clnt_id) == 0)
        APL_DATA_MISSING("DEPO_CLIENT_ID",APL_NULL_STRING,APL_NULL_STRING)

    if (strlen(p_mt_cltdepomap_struct_h->h_cln_depo_map_dp_id) == 0)
        APL_DATA_MISSING("DEPO_DP_ID",APL_NULL_STRING,APL_NULL_STRING)
}
}
/* End- ISKB-328 -For Vault maintenance mandatory check not required -Rahul*/
    /* End - Mandatory Data Check */ 

    if ((strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE) == 0) || 
        (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0))
    { 
	    
        if (p_mt_cltdepomap_struct_h->h_cln_deposeq_num == 0)
        { 
            APL_DATA_MISSING("SEQUENCE_NUMBER",APL_NULL_STRING,APL_NULL_STRING)
        } 

        if (p_mt_cltdepomap_struct_h->h_access_stamp == 0)
        { 
            APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
        } 

   }

        if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                        APL_GOBACK_FAIL

    APL_IF_DEBUG
       {
           memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
           sprintf(chr_l_buf,"Account is %s \n",p_mt_cltdepomap_struct_h->h_dl_client);
           CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
       }

    p_key_values[0]=p_mt_cltdepomap_struct_h->h_dl_client;
    p_key_values[1]=ltoa(p_mt_cltdepomap_struct_h->h_cln_deposeq_num);
    p_key_values[2]=p_mt_cltdepomap_struct_h->h_cln_depo_code;
    p_key_values[3]=APL_NULL_STRING;

    APL_IF_DEBUG
    {
     printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
     printf("Master Check Conditions  Exists - |%c|\n",chr_iexist);
     printf("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
    }
       
    int_retval = CO_Chk_AccValid(p_mt_cltdepomap_struct_h->h_dl_client,chr_iexist,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    chr_ideleted,  
                                    NULL,
                                    NULL,
                                    l_debug_info_ptr); 
           
    if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
    {
          chr_chld_iexist = 'N';
          chr_chld_ideleted = APL_NULL_CHAR;
          chr_chld_iauthorised = APL_NULL_CHAR;
    }
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
           (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
    {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = 'N';
          chr_chld_iauthorised = APL_NULL_CHAR;
    }
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
              (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
          chr_chld_iexist = 'Y';
          chr_chld_ideleted = NULL;
          chr_chld_iauthorised = 'N';
    } 
 
    APL_IF_DEBUG
    {
          printf("Master Details Exists in Proper Status ... \n");
          printf("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
          printf("Child Check Conditions Exists - |%c|\n",chr_chld_iexist);
          printf("Child Check Conditions Deleted - |%c|\n",chr_chld_ideleted);
          printf("Child Check Conditions Authorised - |%c|\n",chr_chld_iauthorised);

          printf("Key Codes 0 = |%s|\n",p_cln_key_codes[0]);
          printf("Key Codes 1 = |%s|\n",p_cln_key_codes[1]);
          printf("Key Codes 2 = |%s|\n",p_cln_key_codes[2]);

          printf("Key Value 0 = |%s|\n",p_key_values[0]);
          printf("Key Value 1 = |%s|\n",p_key_values[1]);
          printf("Key Value 2 = |%s|\n",p_key_values[2]);
    } 
    int_retval = CO_Chk_ChldValid( p_cln_key_codes,
                                  p_key_values,
                                  chr_chld_iexist,
                                  chr_chld_iauthorised,
                                  chr_chld_ideleted,
                                  NULL,
                                  NULL,
                                  NULL,
                                  chr_chld_table_name,
                                  l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
       APL_GOBACK_FAIL 

  /* Check for Same Maker and Checker */

    if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
       {
          int_retval = CR_Chk_ChldMkrChkr( p_cln_key_codes,
                                       p_key_values,
                                       chr_chld_table_name,
                                       p_intl_env_data_struct_h->usr,
                                       l_debug_info_ptr);

          if (int_retval !=APL_SUCCESS)
          APL_GOBACK_FAIL
       }

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
    {
           int_retval = CR_Rtv_MastChldChrVal  (   p_cln_key_codes,
                                            p_key_values,
                                            chr_chld_table_name,
                                            "ROWID",
                                             chr_l_field_val,
                                             l_debug_info_ptr);

           if (int_retval != APL_SUCCESS)
               APL_GOBACK_FAIL

           strcpy(chr_l_row_id_acct,chr_l_field_val);

           int_retval = CR_Rtv_MastChldChrVal  (               p_cln_key_codes,
                                                    p_key_values,
                                                         chr_chld_table_name,
                                                      "access_stamp",
                                                   chr_l_field_val,
                                                        l_debug_info_ptr);

           if (int_retval != APL_SUCCESS)
                        APL_GOBACK_FAIL

           APL_IF_DEBUG
           {
                 printf("Access Stamp from Table = |%s|\n",chr_l_field_val);
                 printf("Access Stamp from Parameter String = |%s|\n",p_mt_cltdepomap_struct_h->h_access_stamp);
           }
 
          if (strcmp(chr_l_field_val,p_mt_cltdepomap_struct_h->h_access_stamp) != 0)
          {
                        CO_InsertErr(  l_debug_info_ptr,
                                ERR_ACCESSSTAMP_CHGD,
                                APL_NULL_STRING,
                                APL_NULL_STRING,
                                APL_NULL_STRING,
                                __LINE__,
                                __FILE__);
                        APL_GOBACK_FAIL
          }
    }

    int_retval = MT_Mod_DBClientDepoMap(p_mt_cltdepomap_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);
        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

    APL_GOBACK_SUCCESS

    RETURN_SUCCESS :
    {
       APL_IF_DEBUG
                   CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientDepoMap SUCCESS \n",NULL,p_intl_env_data_struct_h);
       return(APL_SUCCESS);
    }

    RETURN_FAILURE :
    {
       APL_IF_DEBUG
                    CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientDepoMap FAILURE \n",NULL,p_intl_env_data_struct_h);
       return(APL_FAILURE);
   } 
}

 /* Kouser - HDFCMT_001 - Client Master Maintenance */
    
/*Added by Prateek on 19052014 for ISKB_198(FPI Maintenance)-START*/
int MT_Mod_ClientFpiMap(MT_CLTFPIMAP_STRUCT_H *p_mt_cltfpimap_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int					int_retval;
   char					chr_l_row_id_acct[APL_ROWID_LEN+1];
   char					chr_l_buf[BUFFER_LEN];
   char					chr_l_field_val[40];
   char					chr_chld_tab_name[50];
   char					chr_iexist,chr_ideleted,chr_ifrozen,chr_iauthorised;
   char					chr_chld_iexist,chr_chld_ideleted,chr_chld_ifrozen,chr_chld_iauthorised;			 
   char					chr_seq_num[5];
   char					chr_chld_table_name[50];

   APL_IF_DEBUG
        CO_ProcMonitor(APL_OUT_FILE,"Entered processtion MT_Mod_ClientFpiMap \n",NULL,p_intl_env_data_struct_h);

        memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

        strcpy(chr_chld_table_name,"MT_CLI_FPI_MAP");
        chr_iexist = 'Y';
        chr_ideleted = 'N';

        char  *p_cln_key_codes[4];
        char  *p_key_values[4];

        p_cln_key_codes[0]="CLN_CODE";
        p_cln_key_codes[1]="CLN_SEQ_NUM";
        p_cln_key_codes[2]="CUSTOMER_ID";
        p_cln_key_codes[3]=APL_NULL_STRING;

        /* Start - Mandatory Data Check */

		Alert("Value of Client Code|%s|",p_mt_cltfpimap_struct_h->h_dl_client);
		//Alert("Value of Client Name ==%s\n",p_mt_cltfpimap_struct_h->h_cln_name);
		Alert("Value of NSDL Grp ID ==%s\n",p_mt_cltfpimap_struct_h->h_nsdl_grp_id);
		Alert("Value of NSDL Grp Name ==%s\n",p_mt_cltfpimap_struct_h->h_nsdl_grp_name);
		Alert("Value of Customer ID ==%s\n",p_mt_cltfpimap_struct_h->h_customer_id);
		Alert("Value of Holders ==%s\n",p_mt_cltfpimap_struct_h->h_holders);
		

		if (strlen(p_mt_cltfpimap_struct_h->h_dl_client) == 0)
			{
				APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)
			}


		if (strlen(p_mt_cltfpimap_struct_h->h_customer_id) == 0)
			{ 
				APL_DATA_MISSING("CUSTOMER_ID",APL_NULL_STRING,APL_NULL_STRING)
			}

		
        /* End - Mandatory Data Check */

        if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY) == 0)
        { 
                if (p_mt_cltfpimap_struct_h->h_access_stamp == 0)
                { 
                        APL_DATA_MISSING("ACCESS_STAMP",APL_NULL_STRING,APL_NULL_STRING)
                } 

                if (p_mt_cltfpimap_struct_h->h_cln_exchseq_num == 0)
                { 
                        APL_DATA_MISSING("SEQUENCE_NUMBER",APL_NULL_STRING,APL_NULL_STRING)
                } 
        }           
                if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                        APL_GOBACK_FAIL

        APL_IF_DEBUG
        {
                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"Account is %s \n",p_mt_cltfpimap_struct_h->h_dl_client);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
        }

        p_key_values[0]=p_mt_cltfpimap_struct_h->h_dl_client;
        p_key_values[1]=ltoa(p_mt_cltfpimap_struct_h->h_cln_exchseq_num);
        p_key_values[2]=p_mt_cltfpimap_struct_h->h_customer_id;
        p_key_values[3]=APL_NULL_STRING;

        APL_IF_DEBUG
        {
            Alert("Mode is |%s|\n",p_intl_env_data_struct_h->h_mode);
            Alert("Master Check Conditions  Exists - |%c|\n",chr_iexist);
            Alert("Master Check Conditions  Deleted - |%c|\n",chr_ideleted);
        }
        
        int_retval = CO_Chk_AccValid(p_mt_cltfpimap_struct_h->h_dl_client,chr_iexist,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    chr_ideleted,
                                    NULL,
                                    NULL,
                                    l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL
 
        if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0)
        {
            chr_chld_iexist = 'N';
            chr_chld_ideleted = APL_NULL_CHAR;
            chr_chld_iauthorised = APL_NULL_CHAR;

        APL_IF_DEBUG
        {
            Alert("Key Codes 0 = |%s|\n",p_cln_key_codes[0]);
            Alert("Key Codes 1 = |%s|\n",p_cln_key_codes[1]);
            Alert("Key Codes 2 = |%s|\n",p_cln_key_codes[2]);

            Alert("Key Value 0 = |%s|\n",p_key_values[0]);
            Alert("Key Value 1 = |%s|\n",p_key_values[1]);
            Alert("Key Value 2 = |%s|\n",p_key_values[2]); 
        }

        int_retval = CO_Chk_ChldValid( p_cln_key_codes,
                                       p_key_values,
                                       chr_chld_iexist,
                                       chr_chld_iauthorised,
                                       chr_chld_ideleted,
                                       NULL,
                                       NULL,
                                       NULL,
                                       chr_chld_table_name,
                                       l_debug_info_ptr);   
        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL
        } 

   else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
            (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)   )
   {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = 'N';
      chr_chld_iauthorised = APL_NULL_CHAR;

      int_retval = CO_Chk_ChldValid(          p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_iexist,
                                              chr_chld_iauthorised,
                                              chr_chld_ideleted,
                                              NULL,
                                              NULL,
                                              NULL,
                                              chr_chld_table_name,
                                              l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
               APL_GOBACK_FAIL
    } 
      
    else if ( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
             (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
    {
      chr_chld_iexist = 'Y';
      chr_chld_ideleted = NULL;
      chr_chld_iauthorised = 'N';

      int_retval = CO_Chk_ChldValid(          p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_iexist,
                                              chr_chld_iauthorised,
                                              chr_chld_ideleted,
                                              NULL,
                                              NULL,
                                              NULL,
                                              chr_chld_table_name,
                                              l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
          APL_GOBACK_FAIL
     }

     /* Check for Same Maker and Checker */
  
     if (  (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) ||
         (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0) )
     {

          int_retval = CR_Chk_ChldMkrChkr( p_cln_key_codes,
                                           p_key_values,
                                           chr_chld_table_name,
                                           p_intl_env_data_struct_h->usr,
                                           l_debug_info_ptr);

          if (int_retval !=APL_SUCCESS)
              APL_GOBACK_FAIL
     }


     if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) !=0)
     {
         int_retval = CR_Rtv_MastChldChrVal  (   p_cln_key_codes,
                                                 p_key_values,
                                                 chr_chld_table_name,
                                                 "ROWID",
                                                 chr_l_field_val,
                                                 l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

         strcpy(chr_l_row_id_acct,chr_l_field_val);

         int_retval = CR_Rtv_MastChldChrVal  (p_cln_key_codes,
                                              p_key_values,
                                              chr_chld_table_name,
                                              "access_stamp",
                                              chr_l_field_val,
                                              l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
                 APL_GOBACK_FAIL

         APL_IF_DEBUG
         {
            Alert("Access Stamp from Table = |%s|\n",chr_l_field_val);
            Alert("Access Stamp from Parameter String = |%s|\n",p_mt_cltfpimap_struct_h->h_access_stamp);
         }
 

         if (strcmp(chr_l_field_val,p_mt_cltfpimap_struct_h->h_access_stamp) != 0)
         {
                        CO_InsertErr(  l_debug_info_ptr,
                                       ERR_ACCESSSTAMP_CHGD,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       APL_NULL_STRING,
                                       __LINE__,
                                       __FILE__);
                         APL_GOBACK_FAIL
         }
     }


	int_retval = MT_Mod_DBClientFpiMap(p_mt_cltfpimap_struct_h,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
	APL_GOBACK_FAIL
	Alert("Value of Sequence No ==%d\n",p_mt_cltfpimap_struct_h->h_cln_exchseq_num);


	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientFpiMap SUCCESS \n",NULL,p_intl_env_data_struct_h);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE :
	{
		APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion MT_Mod_ClientFpiMap FAILURE \n",NULL,p_intl_env_data_struct_h);
		return(APL_FAILURE);
	}
} 

/*Added by Prateek on 19052014 for ISKB_198(FPI Maintenance)-END*/


    
 int CR_Mod_CashAcc(DL_CASHACC_STRUCT_H *l_dl_cashacc_struct_ha,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
	int CR_Rtv_CashAccFldVal(char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          char *,
                          DEBUG_INFO_STRUCT_H **);


        int                                                     int_retval;
        char                                                   chr_l_field_val[40];
        char                                                    chr_l_row_id_acct[APL_ROWID_LEN+1];
        char                                                    chr_l_buf[BUFFER_LEN];

        char  chr_l_defflg[APL_MAINFUNCAREA_LEN]             =  APL_NULL_STRING;
        char  chr_l_nondefflg[APL_MAINFUNCAREA_LEN]             =  APL_NULL_STRING;

        APL_IF_DEBUG
                CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Mod_CashAcc \n",NULL,p_intl_env_data_struct_h);

        memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

        if (strlen(l_dl_cashacc_struct_ha->h_dl_client) == 0)
                APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)

        if (strlen(l_dl_cashacc_struct_ha->h_ibbsclient) == 0)
                APL_DATA_MISSING("GL_ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)


                if (strlen(l_dl_cashacc_struct_ha->h_currencycode) == 0)
                        APL_DATA_MISSING("CCY CODE",APL_NULL_STRING,APL_NULL_STRING)

   


        if ((strcmp(p_intl_env_data_struct_h->h_process,ACTION_DEL_IND) == 0) || (strcmp(p_intl_env_data_struct_h->h_process, ACTION_MOD_IND) == 0))
        if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
                APL_GOBACK_FAIL


        APL_IF_DEBUG
        {
                memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
                sprintf(chr_l_buf,"Account is %s \n",l_dl_cashacc_struct_ha->h_dl_client);
                CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h);
        }

        
        int_retval =  MT_Rtv_AccFldVal(l_dl_cashacc_struct_ha->h_dl_client,"ROWID",chr_l_field_val,l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        strcpy(chr_l_row_id_acct,chr_l_field_val);

        if ((strcmp(p_intl_env_data_struct_h->h_process,ACTION_DEL_IND) == 0) || (strcmp(p_intl_env_data_struct_h->h_process, ACTION_MOD_IND) == 0))
        {
                
 

			if((strcmp(p_intl_env_data_struct_h->h_process,ACTION_DEL_IND) == 0))
      	{
        		strcpy(chr_l_defflg,l_dl_cashacc_struct_ha->h_defcurrency_flg);
         	strcpy(chr_l_nondefflg,l_dl_cashacc_struct_ha->h_defcurrency_flg);
      	}
      	else
      	{
         	strcpy(chr_l_defflg,l_dl_cashacc_struct_ha->h_defcurrency_flg);
         	strcpy(chr_l_nondefflg,APL_NULL_STRING);
      	}

                int_retval = CR_Rtv_CashAccFldVal(l_dl_cashacc_struct_ha->h_dl_client,l_dl_cashacc_struct_ha->h_ibbsclient,l_dl_cashacc_struct_ha->h_currencycode,chr_l_defflg,chr_l_nondefflg,"ROWID",chr_l_field_val,l_debug_info_ptr);



                if (int_retval != APL_SUCCESS)
                        APL_GOBACK_FAIL
        }

       int_retval = CR_Mod_DBCashAcc(l_dl_cashacc_struct_ha,chr_l_row_id_acct,p_intl_env_data_struct_h,l_debug_info_ptr);

        if (int_retval != APL_SUCCESS)
                APL_GOBACK_FAIL

        APL_GOBACK_SUCCESS



 
        RETURN_SUCCESS :
        {
                APL_IF_DEBUG
                        CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_CashAcc SUCCESS \n",NULL,p_intl_env_data_struct_h);
                return(APL_SUCCESS);
        }

        RETURN_FAILURE :
        {
                APL_IF_DEBUG
    CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_CashAcc  FAILURE \n", NULL, p_intl_env_data_struct_h);
                return(APL_FAILURE);
        }
}


