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
 * File Name           :      MT_ProcDepoPart.c
 *
 * Description         :      This file contains functions for updating
 *                            Master Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author         Description       RFS No.
 * ---------   --------  ------------     -------------     ---------
 * 30/12/2005   1.0       Kouser        New file          HDFCMT
 *
 *********************************************************************/


#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

#define APL_DEPOPART_CHILD_CNT 1

char     *g_l_chld_table_names[APL_DEPOPART_CHILD_CNT + 1] = {"MT_EXCH_DEPO",APL_NULL_STRING};
     char            *g_l_mst_key_codes[3] = {"DEPO_CODE","DEPO_PART_CODE",APL_NULL_STRING};
     char            *g_l_mst_key_values[3];
     char            g_l_mst_table_name[25] = "MT_DEPO_PART";


int MT_Mod_DepoPart(MT_DEPO_PART_STRUCT_H *p_mt_depo_part_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
        /*      Variable Declarations */

        int int_error_flag = APL_SUCCESS;

        char  *l_key_codes[3];
        char  *l_key_values[3];
        char  chr_l_table_name[50];
        char  *chr_l_country_code;
        char  *chr_l_g_country_code;
        char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
        char  chr_l_iexist,chr_l_ideleted,chr_l_iauthorized;

        strcpy(chr_l_table_name,"MT_DEPO_PART");

        chr_l_country_code=(char *)calloc(3,sizeof(char));
        chr_l_g_country_code=(char *)calloc(3,sizeof(char));

        strcpy(chr_l_country_code,APL_COUNTRY_CODE);
        strcpy(chr_l_g_country_code,g_mt_commonsys_params_struct_h.nation_code);

        int int_retval = APL_SUCCESS;

        APL_FUNCTION_ENTER(APL_OUT_FILE)

        /* Mandatory Data Missing Checks   - Generic */

        l_key_codes[0]="DEPO_CODE";
        l_key_codes[1]="DEPO_PART_CODE";
        l_key_codes[2]=APL_NULL_STRING;

        l_key_values[0]=p_mt_depo_part_struct_h -> h_depo_code;
        l_key_values[1]=p_mt_depo_part_struct_h -> h_depo_part_code;
        l_key_values[2] = APL_NULL_STRING;


        int_retval = CR_Chk_AllMandData( l_key_codes,
                                 l_key_values,
                                 2,
                                 l_debug_info_ptr);

        if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL


 /* Static Data Validation - Start */

 if (strlen(p_mt_depo_part_struct_h->h_depo_code))
 {
         int_retval = CO_Chk_CodeValid("DEPOSITORY",p_mt_depo_part_struct_h->h_depo_code,chr_l_g_country_code,l_debug_info_ptr);

         if (int_retval != APL_SUCCESS)
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

 if (strlen(p_mt_depo_part_struct_h->h_depo_part_add_cnt))
 {
         int_retval = CO_Chk_CodeValid("ISOCOUNTRY",p_mt_depo_part_struct_h->h_depo_part_add_cnt,chr_l_country_code,l_debug_info_ptr);
	       printf("Checking Country val\n");

       if (int_retval != APL_SUCCESS)
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

 if (strlen(p_mt_depo_part_struct_h->h_depo_part_add_city))
 {
         int_retval = CO_Chk_CodeValid("CITY",p_mt_depo_part_struct_h->h_depo_part_add_city,p_mt_depo_part_struct_h->h_depo_part_add_state,l_debug_info_ptr);

    if (int_retval != APL_SUCCESS)
    {
       CO_InsertErr(l_debug_info_ptr,
			           ERR_INVALID_CODE,
					     APL_NULL_STRING,
					     APL_NULL_STRING,
					     APL_NULL_STRING,
					     __LINE__,
					     __FILE__);
	                 APL_GOBACK_FAIL
   }
  }

 if(strlen(p_mt_depo_part_struct_h->h_depo_part_add_state))
 {
        int_retval = CO_Chk_CodeValid("STATE",p_mt_depo_part_struct_h->h_depo_part_add_state,chr_l_g_country_code,l_debug_info_ptr);

          if (int_retval != APL_SUCCESS)
          {
           CO_InsertErr(l_debug_info_ptr,
			               ERR_INVALID_CODE,
				      	   APL_NULL_STRING,
					         APL_NULL_STRING,
					         APL_NULL_STRING,
					         __LINE__,
					         __FILE__);
	                 APL_GOBACK_FAIL
			 }
 }

 /* Static Data Validation - End */


 /*      Mandatory Data Missing Checks   - Mode Specific */

 if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
 {	
			printf("HERE!!!!!!!!!!");
			printf("p_mt_depo_part_struct_h->h_access_stamp is %s**!!!!!!!!!!",p_mt_depo_part_struct_h->h_access_stamp);
			fflush(stdout);
     if (strlen(p_mt_depo_part_struct_h->h_access_stamp) == 0)
     {
             APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
             int_error_flag = APL_FAILURE;
     }
 }


 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
 {
			printf("HERE!!!!!!!!!!");
			fflush(stdout);
            APL_GOBACK_FAIL
 }

 if (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) == 0) 
 {
          chr_l_iexist = 'N';
          chr_l_ideleted = APL_NULL_CHAR;
          chr_l_iauthorized = APL_NULL_CHAR; 

          l_key_codes[0]="DEPO_CODE";
          l_key_codes[1]="DEPO_PART_CODE";
          l_key_codes[2]=APL_NULL_STRING;
   
          l_key_values[0]=p_mt_depo_part_struct_h -> h_depo_code;
          l_key_values[1]=p_mt_depo_part_struct_h -> h_depo_part_code;
          l_key_values[2] = APL_NULL_STRING;   

  
          int_retval = CO_Chk_ChldValid( l_key_codes,
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

  if( (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0) ||
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_DELETE) == 0) || 
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE) == 0) || 
      (strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_RESET) == 0)) 
  {
			printf("HERE!!!!!!!!!!");
			fflush(stdout);
      l_key_codes[0]="DEPO_CODE";
      l_key_codes[1]="DEPO_PART_CODE";
      l_key_codes[2]=APL_NULL_STRING;
  
          l_key_values[0]=p_mt_depo_part_struct_h -> h_depo_code;
          l_key_values[1]=p_mt_depo_part_struct_h -> h_depo_part_code;
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

 } 
 if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
 {
      APL_IF_DEBUG
      {
         CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
      }

         MT_Mod_DBDepoPart(p_mt_depo_part_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
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

            MT_Mod_DBDepoPart(p_mt_depo_part_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
 }
 else if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
 {

       /* Description of Child Table names */

             int_retval = CR_Chk_CodeInChld(l_key_codes,
                                            l_key_values,
                                            g_l_chld_table_names,
                                            p_intl_env_data_struct_h,
                                            l_debug_info_ptr);

            if (int_retval !=APL_SUCCESS)
            {
                       CO_InsertErr(l_debug_info_ptr,
                                    ERR_MAP_DEPO_PART_EXIST_CANTDEL,
                                    "Mapping Depository Participant Details Exist",
                                     p_mt_depo_part_struct_h -> h_depo_code,
                                     APL_NULL_STRING,
                                     __LINE__,
                                     __FILE__);
            } 
            else if (int_retval == APL_FAILURE)
            APL_GOBACK_FAIL 

         if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
         {
                     APL_GOBACK_FAIL
         }

         APL_IF_DEBUG
         {
            CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode ... \n",NULL,p_intl_env_data_struct_h);
         }
     
            MT_Mod_DBDepoPart(p_mt_depo_part_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

                l_key_codes[0]="DEPO_CODE";
                l_key_codes[1]="DEPO_PART_CODE";
                l_key_codes[2]=APL_NULL_STRING;

                l_key_values[0]=p_mt_depo_part_struct_h -> h_depo_code;
                l_key_values[1]=p_mt_depo_part_struct_h -> h_depo_part_code;
                l_key_values[2] = APL_NULL_STRING;

    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                     l_key_values,
                                     chr_l_table_name,
                                     p_intl_env_data_struct_h->usr,
                                     l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

           MT_Mod_DBDepoPart(p_mt_depo_part_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

                    l_key_codes[0]="DEPO_CODE";
                    l_key_codes[1]="DEPO_PART_CODE";
                    l_key_codes[2]=APL_NULL_STRING;
   
                    l_key_values[0]=p_mt_depo_part_struct_h -> h_depo_code;
                    l_key_values[1]=p_mt_depo_part_struct_h -> h_depo_part_code;
                    l_key_values[2] = APL_NULL_STRING;


                    int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                                     l_key_values,
                                                     chr_l_table_name,
                                                     p_intl_env_data_struct_h->usr,
                                                     l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

    if (strcmp(p_mt_depo_part_struct_h->h_status,STATUS_DEL_UAUTH) != 0)
    {
           CO_InsertErr(l_debug_info_ptr,ERR_DEPO_PART_RESET_CANT_ALLOWED,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
    }

    if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
    {
                  APL_GOBACK_FAIL
    }

    MT_Mod_DBDepoPart(p_mt_depo_part_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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

int MT_Mod_ExchDepo(MT_EXCH_DEPO_STRUCT_H *p_mt_exch_depo_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
        /*      Variable Declarations */

        int int_error_flag = APL_SUCCESS;

        char  *l_key_codes[8];
        char  *l_key_values[8];
        char  chr_l_table_name[50];
        char  chr_l_mst_table_name[50];
        char  *chr_l_country_code;
        char  *chr_l_g_country_code;

        char chr_iexist,chr_ideleted;

        char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;

        chr_iexist = 'Y';
        chr_ideleted = 'N';

        int int_retval = APL_SUCCESS;

        chr_l_country_code=(char *)calloc(3,sizeof(char));
	     chr_l_g_country_code=(char *)calloc(3,sizeof(char));
	
        strcpy(chr_l_country_code,APL_COUNTRY_CODE);
        strcpy(chr_l_g_country_code,g_mt_commonsys_params_struct_h.nation_code);

        /* Debug statements */

        APL_FUNCTION_ENTER(APL_OUT_FILE)

        /*  Mandatory Data Missing Checks   - Generic  */

        l_key_codes[0]="DEPO_CODE";
        l_key_codes[1]="DEPO_PART_CODE";
        l_key_codes[2]="EXCH_CODE";
        l_key_codes[3]="CC_ID";
        l_key_codes[4]="CM_CC_ID";
        l_key_codes[5]="CLN_ID";
        l_key_codes[6]="DP_ID";
        l_key_codes[7]=APL_NULL_STRING;
     
        
		  l_key_values[0]=p_mt_exch_depo_struct_h -> h_depo_code;     
        l_key_values[1]=p_mt_exch_depo_struct_h -> h_depo_part_code;     
        l_key_values[2]=p_mt_exch_depo_struct_h -> h_exch_code;     
        l_key_values[3]=p_mt_exch_depo_struct_h -> h_cc_id;     
        l_key_values[4]=p_mt_exch_depo_struct_h -> h_cm_cc_id;     
        l_key_values[5]=p_mt_exch_depo_struct_h -> h_cln_id;     
        l_key_values[6]=p_mt_exch_depo_struct_h -> h_dp_id;     
        l_key_values[7]= APL_NULL_STRING;

		  /*  CO_FreeErrLst(l_debug_info_ptr);	*/

        int_retval = CR_Chk_AllMandData( l_key_codes,
                                         l_key_values,
                                         7,
                                         l_debug_info_ptr);

        if (int_retval !=APL_SUCCESS)
               APL_GOBACK_FAIL

        /* Mandatory Data Missing Checks   - Mode Specific */

       if (strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
       {
                if (!strlen(p_mt_exch_depo_struct_h->h_access_stamp))
                {
                        APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
                int_error_flag = APL_FAILURE;
                }
       }
      

      if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
            APL_GOBACK_FAIL
      }


   if (strlen(p_mt_exch_depo_struct_h->h_exch_code))
   {
       int_retval = CO_Chk_CodeValid("EXCHANGE",p_mt_exch_depo_struct_h->h_exch_code,chr_l_g_country_code,l_debug_info_ptr);

       if (int_retval != APL_SUCCESS)
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

    /* Check  a Record Exist in Master Table */

    printf("********************************\n");
    printf("Val of Depo Code ==|%s|\n",p_mt_exch_depo_struct_h->h_depo_code);
    printf("Val of Exist Flag  ==|%c|\n",chr_iexist);
    printf("Val of Delete Flag  ==|%c|\n",chr_ideleted);
    printf("********************************\n");

    l_key_codes[0]="DEPO_CODE";
    l_key_codes[1]="DEPO_PART_CODE";
    l_key_codes[2]=APL_NULL_STRING;
  
    l_key_values[0]=p_mt_exch_depo_struct_h -> h_depo_code;
    l_key_values[1]=p_mt_exch_depo_struct_h -> h_depo_part_code;
    l_key_values[2] = APL_NULL_STRING;

    chr_l_rec_iauthorized = APL_NULL_CHAR;

    strcpy(chr_l_mst_table_name,"MT_DEPO_PART");

    int_retval = CO_Chk_ChldValid( l_key_codes,
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
	 {
        APL_GOBACK_FAIL
	 }

    /* Setting Values for Mode Specific Checks */

    strcpy(chr_l_table_name,"MT_EXCH_DEPO");

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

        l_key_codes[0]="DEPO_CODE";
        l_key_codes[1]="DEPO_PART_CODE";
        l_key_codes[2]="EXCH_CODE";
        l_key_codes[3]=APL_NULL_STRING;

        l_key_values[0]=p_mt_exch_depo_struct_h -> h_depo_code;
        l_key_values[1]=p_mt_exch_depo_struct_h -> h_depo_part_code;
        l_key_values[2]=p_mt_exch_depo_struct_h -> h_exch_code;
        l_key_values[3] = APL_NULL_STRING;

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
			 {
                APL_GOBACK_FAIL
			 }

 if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
        {
                APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
        }

         MT_Mod_DBExchDepo(p_mt_exch_depo_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
        }
 else if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY))
        {
        APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered modify mode ... \n",NULL,p_intl_env_data_struct_h);
        }
   
             MT_Mod_DBExchDepo(p_mt_exch_depo_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
        }
 else if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_DELETE))
        {
                APL_IF_DEBUG
        {
                CO_ProcMonitor(APL_OUT_FILE, "Entered delete mode ... \n",NULL,p_intl_env_data_struct_h);
        }

           MT_Mod_DBExchDepo(p_mt_exch_depo_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
         }
  else if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
         {
         APL_IF_DEBUG
         {
                CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
         }

     l_key_codes[0]="DEPO_CODE";
     l_key_codes[1]="DEPO_PART_CODE";
     l_key_codes[2]="EXCH_CODE";
     l_key_codes[2]=APL_NULL_STRING;

     l_key_values[0]=p_mt_exch_depo_struct_h -> h_depo_code;
     l_key_values[1]=p_mt_exch_depo_struct_h -> h_depo_part_code;
     l_key_values[2]=p_mt_exch_depo_struct_h -> h_exch_code;
     l_key_values[2] = APL_NULL_STRING;

     int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                      l_key_values,
                                      chr_l_table_name,
                                      p_intl_env_data_struct_h->usr,
                                      l_debug_info_ptr);

    if (int_retval !=APL_SUCCESS)
         APL_GOBACK_FAIL

        MT_Mod_DBExchDepo(p_mt_exch_depo_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
                APL_GOBACK_FAIL
        }
        }

  else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
        {
          APL_IF_DEBUG
        { 
          CO_ProcMonitor(APL_OUT_FILE, "Entered RESET  mode ... \n",NULL,p_intl_env_data_struct_h);
        }
             l_key_codes[0]="DEPO_CODE";
             l_key_codes[1]="DEPO_PART_CODE";
             l_key_codes[2]="EXCH_CODE";
             l_key_codes[3]=APL_NULL_STRING;

             l_key_values[0]=p_mt_exch_depo_struct_h -> h_depo_code;
             l_key_values[1]=p_mt_exch_depo_struct_h -> h_depo_part_code;
             l_key_values[2]=p_mt_exch_depo_struct_h -> h_exch_code;
             l_key_values[3] = APL_NULL_STRING;

             int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
                                              l_key_values,
                                              chr_l_table_name,
                                              p_intl_env_data_struct_h->usr,
                                              l_debug_info_ptr);

             if (int_retval !=APL_SUCCESS)
                   APL_GOBACK_FAIL

 if (strcmp(p_mt_exch_depo_struct_h->h_status,STATUS_DEL_UAUTH) != 0)
 {
        CO_InsertErr(l_debug_info_ptr,ERR_DEPO_PART_RESET_CANT_ALLOWED,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
 }
   
      if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
            APL_GOBACK_FAIL
      }

      MT_Mod_DBExchDepo(p_mt_exch_depo_struct_h ,p_intl_env_data_struct_h ,l_debug_info_ptr);

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
