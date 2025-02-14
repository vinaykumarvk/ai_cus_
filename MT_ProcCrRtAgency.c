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
 * File Name           :      MT_ProcCrRtAgency.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 26/12/2005   1.0       Kouser        New file          HDFCMT_011
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

#define APL_AGENCY_CHILD_CNT 1

char     *g_crt_chld_table_names[APL_AGENCY_CHILD_CNT + 1] = {"MT_CR_AGENCY_DET",APL_NULL_STRING};
     char            *g_crt_mst_key_codes[2] = {"AGENCY_CODE",APL_NULL_STRING};
     char            *g_mst_key_values[2];
     char            g_crt_mst_table_name[25] = "MT_CR_AGENCY";


int MT_Mod_CrRtAgency(MT_CR_AGENCY_STRUCT_H *p_mt_cr_agency_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
        /*      Variable Declarations */
        int int_error_flag = APL_SUCCESS;

        char  *l_key_codes[3];
        char  *l_key_values[3];
        char  chr_l_table_name[50];

        char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
        char  chr_l_iexist,chr_l_ideleted,chr_l_iauthorized;

		  char  *chr_l_cntry_code;
		  char  *chr_l_g_cntry_code;

        chr_l_cntry_code=(char *)calloc(3,sizeof(char));
		  chr_l_g_cntry_code=(char *)calloc(3,sizeof(char));
	
        strcpy(chr_l_cntry_code,APL_COUNTRY_CODE);
        strcpy(chr_l_g_cntry_code,g_mt_commonsys_params_struct_h.nation_code);


        strcpy(chr_l_table_name,"MT_CR_AGENCY");

        /*char  *l_linked_table_names[2]={"MT_FLRATE_INSTRUMENT",APL_NULL_STRING};*/

        int int_retval = APL_SUCCESS;

        APL_FUNCTION_ENTER(APL_OUT_FILE)

        /*      Mandatory Data Missing Checks   - Generic */

        l_key_codes[0]="AGENCY_CODE";
        l_key_codes[1]="AGENCY_NAME";
        l_key_codes[2]=APL_NULL_STRING;

        l_key_values[0]=p_mt_cr_agency_struct_h -> h_agency_code;
        l_key_values[1]=p_mt_cr_agency_struct_h -> h_agency_name;
        l_key_values[2] = APL_NULL_STRING;


        printf("Val of Agency Code ==|%s|\n",p_mt_cr_agency_struct_h -> h_agency_code);
        printf("Val of Agency Code ==|%s|\n",p_mt_cr_agency_struct_h -> h_agency_name);
		   printf("RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");

        int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 2,
                                 l_debug_info_ptr);

        if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL

     printf("Check Mandatory Dataffffffffffffffffff\n");

    /* Check for Static Data  Validation */

    printf("Val of city ==|%s|\n",p_mt_cr_agency_struct_h->h_agency_city);						   
    if (strlen(p_mt_cr_agency_struct_h->h_agency_city))
    {
		    printf("Inside Code valid check ==|%s|\n",p_mt_cr_agency_struct_h->h_agency_city);

          printf(" val of string ==|%s|\n",chr_l_g_cntry_code); 
          int_retval = CO_Chk_CodeValid("CITY",
                                         p_mt_cr_agency_struct_h->h_agency_city,
                                         p_mt_cr_agency_struct_h->h_agency_state,
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


 printf("Val of State  ==|%s|\n",p_mt_cr_agency_struct_h->h_agency_state);
    
         if (strlen(p_mt_cr_agency_struct_h->h_agency_state))
         {
		  printf("Inside the code check =|%s|\n",p_mt_cr_agency_struct_h->h_agency_state); 
        printf("Val of string =|%s|\n",chr_l_g_cntry_code); 
               int_retval = CO_Chk_CodeValid("STATE",
                                            p_mt_cr_agency_struct_h->h_agency_state,
                                            chr_l_g_cntry_code, 
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
    printf("Val of Country =|%s|\n",p_mt_cr_agency_struct_h->h_aadr_cnt);

    
         if (strlen(p_mt_cr_agency_struct_h->h_aadr_cnt))
         {
				 printf("Inside the count check\n");
				  printf(" Cpy strincg =|%s|\n",chr_l_cntry_code);
               int_retval = CO_Chk_CodeValid("ISOCOUNTRY",
                                              p_mt_cr_agency_struct_h->h_aadr_cnt,
                                           chr_l_cntry_code,
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

       /*  Static Data Validation End */
   

        /*      Mandatory Data Missing Checks   - Mode Specific */

       if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
        {
                if (!strlen(p_mt_cr_agency_struct_h->h_access_stamp))
                {
                        APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
                        int_error_flag = APL_FAILURE;
                }
        }

 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 {
            APL_GOBACK_FAIL
 }

    if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0) 
    {
          chr_l_iexist = 'N';
          chr_l_ideleted = APL_NULL_CHAR;
          chr_l_iauthorized = APL_NULL_CHAR; 

          l_key_codes[0]="AGENCY_CODE";
          l_key_codes[1]=APL_NULL_STRING;
   
          l_key_values[0]=p_mt_cr_agency_struct_h -> h_agency_code;
          l_key_values[1] = APL_NULL_STRING;   

  
     int_retval = CO_Chk_ChldValid(      l_key_codes,
                                         l_key_values,
                                         chr_l_iexist,
                                         chr_l_iauthorized,
                                         chr_l_ideleted,
                                         NULL,
                                         NULL,
                                         NULL,
                                         chr_l_table_name,
                                         l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
           APL_GOBACK_FAIL

   } 

 /* Setting Values for Mode Specific Checks */

 /*strcpy(chr_l_table_name,"MT_CR_AGENCY");*/

 if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
          (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0)  )
 {
   printf("entered Into Functiom1\n");
    chr_l_rec_iexist = 'Y';
    chr_l_rec_ideleted = 'N';
    chr_l_rec_iauthorized = APL_NULL_CHAR;
 }
 else if (   (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0))
 {  
    printf("Entered In to Func2\n");
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

        /*l_key_codes[0]="AGENCY_CODE";
        l_key_codes[1]=APL_NULL_STRING;

        l_key_values[0]=p_mt_cr_agency_struct_h -> h_agency_code;
        l_key_values[1] = APL_NULL_STRING;*/


  if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0) || 
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) || 
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0)) 
{
      l_key_codes[0] = "AGENCY_CODE";
      l_key_codes[1] = APL_NULL_STRING;
  
      l_key_values[0] = p_mt_cr_agency_struct_h -> h_agency_code;
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

 } 
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
        {
                APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
        }

         MT_Mod_DBCrRt_Agency(p_mt_cr_agency_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
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

           MT_Mod_DBCrRt_Agency(p_mt_cr_agency_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
        }
 else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
   {

             int_retval = CR_Chk_CodeInChld(l_key_codes,
                                          l_key_values,
                                          g_crt_chld_table_names,
                                          p_intl_env_data_struct_h,
                                          l_debug_info_ptr);

            if (int_retval !=APL_SUCCESS)
            {
                       if(APL_FAILURE == CO_InsertErr(l_debug_info_ptr,
                                    ERR_MAP_RATING_EXIST_CANTDEL,
                                       "Mapping Credit Rating Details Exist",
                                       p_mt_cr_agency_struct_h -> h_agency_code,
                                       APL_NULL_STRING,
                                        __LINE__,
                                       __FILE__))
			/*{
				printf("Failed in insert error\n");
                                     APL_GOBACK_FAIL  
			}*/
			APL_GOBACK_FAIL
            }


         if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
                     APL_GOBACK_FAIL
            }

        APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode ... \n",NULL,p_intl_env_data_struct_h);
        }
     
           MT_Mod_DBCrRt_Agency(p_mt_cr_agency_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

                l_key_codes[0]="AGENCY_CODE";
                l_key_codes[1]=APL_NULL_STRING;

                l_key_values[0]=p_mt_cr_agency_struct_h -> h_agency_code;
                l_key_values[1] = APL_NULL_STRING;

    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

           MT_Mod_DBCrRt_Agency(p_mt_cr_agency_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
        }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
  {
        APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered Reset mode ... \n",NULL,p_intl_env_data_struct_h);
        }

                l_key_codes[0]="AGENCY_CODE";
                l_key_codes[1]=APL_NULL_STRING;

                l_key_values[0]=p_mt_cr_agency_struct_h -> h_agency_code;
                l_key_values[1] = APL_NULL_STRING;

    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    printf("Checker RESET Maker & Checker\n");

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

           MT_Mod_DBCrRt_Agency(p_mt_cr_agency_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

  int MT_Mod_CrRtAgencyDet(MT_CR_AGENCY_DET_STRUCT_H *p_mt_cr_agency_det_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
        /*      Variable Declarations */
        int int_error_flag = APL_SUCCESS;

        char  *l_key_codes[3];
        char  *l_key_values[3];
        char  chr_l_table_name[50];
        char  chr_l_mst_table_name[50];

        char chr_iexist,chr_ideleted;

        char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;

        chr_iexist = 'Y';
        chr_ideleted = 'N';

        /*char  *l_linked_table_names[2]={"MT_FLRATE_INSTRUMENT",APL_NULL_STRING};*/

        int int_retval = APL_SUCCESS;

        /* Debug statements */

        APL_FUNCTION_ENTER(APL_OUT_FILE)

        /*      Mandatory Data Missing Checks   - Generic */

        l_key_codes[0]="AGENCY_CODE";
        l_key_codes[1]="RATING_CODE";
        l_key_codes[2]=APL_NULL_STRING;

        /*l_key_codes[2]="ACCESS_STAMP";
        l_key_codes[3]="AGENCY_SEQ_NUM";*/

        l_key_values[0]=p_mt_cr_agency_det_struct_h -> h_agency_code;
        l_key_values[1]=p_mt_cr_agency_det_struct_h -> h_rating_code;
        l_key_values[2] = APL_NULL_STRING;

        /*l_key_values[2]=p_mt_cr_agency_det_struct_h -> h_access_stamp;
        l_key_values[3]=ltoa(p_mt_cr_agency_det_struct_h -> h_cr_seq_num);*/

        int_retval = CR_Chk_AllMandData( l_key_codes,
                                         l_key_values,
                                         2,
                                         l_debug_info_ptr);

        if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL

        /*      Mandatory Data Missing Checks   - Mode Specific */

       if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
        {
                if (!strlen(p_mt_cr_agency_det_struct_h->h_access_stamp))
                {
                        APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
                int_error_flag = APL_FAILURE;
                }
        }
      

        /*if (int_retval !=APL_SUCCESS)
             APL_GOBACK_FAIL*/

 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 {
            APL_GOBACK_FAIL
 }

 /* Check  a Record Exist in Master Table */


    printf("********************************\n");
    printf("Val of Agency Code ==|%s|\n",p_mt_cr_agency_det_struct_h -> h_agency_code);
    printf("Val of Exist Flag  ==|%c|\n",chr_iexist);
    printf("Val of Delete Flag  ==|%c|\n",chr_ideleted);
    printf("********************************\n");

    l_key_codes[0]="AGENCY_CODE";
    l_key_codes[1]=APL_NULL_STRING;
  
    l_key_values[0]=p_mt_cr_agency_det_struct_h -> h_agency_code;
    l_key_values[1] = APL_NULL_STRING;

    chr_l_rec_iauthorized = APL_NULL_CHAR;

    strcpy(chr_l_mst_table_name,"MT_CR_AGENCY");

  int_retval = CO_Chk_ChldValid(      l_key_codes,
                                      l_key_values,
                                      chr_iexist,
                                      chr_l_rec_iauthorized,
                                      chr_ideleted,
                                      NULL,
                                      NULL,
                                      NULL,
                                      chr_l_mst_table_name,
                                      l_debug_info_ptr);

   
    if (int_retval != APL_SUCCESS)
               APL_GOBACK_FAIL

    //printf("Val of Exist Flag  ==|%c|\n",chr_l_mst_table_name); AIX Migration Changes
    printf("Val of Exist Flag  ==|%s|\n",chr_l_mst_table_name);

    /* Setting Values for Mode Specific Checks */

 strcpy(chr_l_table_name,"MT_CR_AGENCY_DET");

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

        l_key_codes[0]="AGENCY_CODE";
        /*l_key_codes[1]="RATING_CODE";*/
        l_key_codes[1]="CR_SEQ_NUM";
        l_key_codes[2]=APL_NULL_STRING;

        l_key_values[0]=p_mt_cr_agency_det_struct_h -> h_agency_code;
        /*l_key_values[1]=p_mt_cr_agency_det_struct_h -> h_rating_code; */
        l_key_values[1]=ltoa(p_mt_cr_agency_det_struct_h -> h_cr_seq_num);
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

 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
        {
                APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
        }

         MT_Mod_DBCrRt_AgencyDet(p_mt_cr_agency_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
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
   
             MT_Mod_DBCrRt_AgencyDet(p_mt_cr_agency_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
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

           MT_Mod_DBCrRt_AgencyDet(p_mt_cr_agency_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
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

            l_key_codes[0]="AGENCY_CODE";
            /*l_key_codes[1]="RATING_CODE";*/
            l_key_codes[1]="CR_SEQ_NUM";
            l_key_codes[2]=APL_NULL_STRING;
    
            l_key_values[0]=p_mt_cr_agency_det_struct_h -> h_agency_code;
            /*l_key_values[1]=p_mt_cr_agency_det_struct_h -> h_rating_code;*/
            l_key_values[1]=ltoa(p_mt_cr_agency_det_struct_h -> h_cr_seq_num);
            l_key_values[2] = APL_NULL_STRING;

    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

           MT_Mod_DBCrRt_AgencyDet(p_mt_cr_agency_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
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


           l_key_codes[0]="AGENCY_CODE";
           /*l_key_codes[1]="RATING_CODE";*/
           l_key_codes[1]="CR_SEQ_NUM";
           l_key_codes[2]=APL_NULL_STRING;
   
           l_key_values[0]=p_mt_cr_agency_det_struct_h -> h_agency_code;
           /*l_key_values[1]=p_mt_cr_agency_det_struct_h -> h_rating_code;*/
           l_key_values[1]=ltoa(p_mt_cr_agency_det_struct_h -> h_cr_seq_num);
           l_key_values[2] = APL_NULL_STRING;

    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

           MT_Mod_DBCrRt_AgencyDet(p_mt_cr_agency_det_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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
