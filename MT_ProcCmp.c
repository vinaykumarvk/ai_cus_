/******************************************************************
COPYRIGHT NOTICE
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
 * Module Name         :  Master Maintenance
 *
 * File Name           :  MT_ProcCmp.c
 *
 * Description         : This file contains functions for Company Details .
 *                           It contains all functions related to Input/Modify/Authorize/Delete/Reset modes
 *
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 *              1.0          ANIL               NEW FILE  RFSNo.HDFCMT_002
 * 07/12/2005   1.1          Anil		   		HDFCMT_002
 * 09/12/2005   1.2          	Sonali		    changed country code from IN to XX where relevant,HDFCMT_002
 * 09/12/2005   1.3          	Sonali		    Added lines for failure, HDFCMT_002
 * 14/12/2005   1.4          	Sonali		    check for presence of codes befor calling CO_Chk_CodeValid,HDFCMT_002
 *
 *********************************************************************/

#define PURE_C_SOURCE
#include "Intellect_Common.h"
#include "CO_HostStructdef.h"
#include "Intellect_Interface.h"
#include "Intellect_Error.h"
int CR_Mod_company(MT_COMPANY_STRUCT_H *p_mt_company_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
  int int_error_flag = APL_SUCCESS;
 short int_ret_val =0; 
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Mod_company. Going for mandatory checks\n",
                NULL,p_intl_envdatastruct_h);
 }

   /* Start - Added by Gouse for (Auto Comapny Code Generation) */
   /**** Check For Existency of Mandatory Fields ****/
   if (!strlen(p_mt_company_struct_h->h_cmp_code))
    {
      APL_DATA_MISSING("company Code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

	/* End - Added by Gouse for (Auto Comapny Code Generation) */ 
    if (!strlen(p_mt_company_struct_h->h_cmp_name))
    {
      APL_DATA_MISSING("Company Name",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
	 /*Changed country from "IN" to "XX", Sonali */
	 if(strlen(p_mt_company_struct_h->h_cmp_add_cnt))
	 {
    int_ret_val = CO_Chk_CodeValid("ISOCOUNTRY",p_mt_company_struct_h->h_cmp_add_cnt,"XX",l_debug_info_ptr);
   if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL
	 }

	 if(strlen(p_mt_company_struct_h->h_cmp_industrycd))
	 {
int_ret_val = CO_Chk_CodeValid("INDUSTRY",p_mt_company_struct_h->h_cmp_industrycd,"XX",l_debug_info_ptr);
           if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL
	 }

	 if(strlen(p_mt_company_struct_h->h_cmp_sectorcd))
	 {
		 int_ret_val = CO_Chk_CodeValid("SECTOR",p_mt_company_struct_h->h_cmp_sectorcd,"XX",l_debug_info_ptr);
		 if (int_ret_val != APL_SUCCESS)
			 APL_GOBACK_FAIL
	 }

	if(strlen(p_mt_company_struct_h->h_cmp_add_city))
	{	
int_ret_val = CO_Chk_CodeValid("CITY",p_mt_company_struct_h->h_cmp_add_city,p_mt_company_struct_h->h_cmp_add_state,l_debug_info_ptr);
   if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL
	}

	if(strlen(p_mt_company_struct_h->h_cmp_add_state))
	{
int_ret_val = CO_Chk_CodeValid("STATE",p_mt_company_struct_h->h_cmp_add_state,(char *)g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr);//Changes done for AIX Migration
    if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL
	}	
      if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
        {
          APL_IF_DEBUG
           { 
  CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of CR_Mod_company.Going for updation\n",
                NULL,p_intl_envdatastruct_h);
             }
        MT_Mod_DbCompanyFn(p_mt_company_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
         if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
               } 
        }
         else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
        {
        APL_IF_DEBUG
         { 
CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of CR_Mod_company.Going for updation after validating company details\n",NULL,p_intl_envdatastruct_h);

}
if (APL_SUCCESS == MT_Chk_CmpanyFn(p_mt_company_struct_h->h_cmp_code,'Y',NULL,NULL,l_debug_info_ptr))//Changes done for AIX Migration
      { 
            MT_Mod_DbCompanyFn(p_mt_company_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
               }
           }      
else
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
}
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
        {
     APL_IF_DEBUG
       {
         CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of CR_Mod_company.Going for updation after validating company \n",NULL,p_intl_envdatastruct_h);
       }

      if (APL_SUCCESS ==  MT_Chk_CmpanyFn(p_mt_company_struct_h->h_cmp_code,'Y','N',NULL,l_debug_info_ptr))
           {
       if(APL_SUCCESS == MT_Chk_MkrChkr_Company(p_mt_company_struct_h->h_cmp_code,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
                {
                MT_Mod_DbCompanyFn(p_mt_company_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
                  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
               }
                }
                else
           if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
            }
            else
        if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
            APL_GOBACK_FAIL
            }
        }
  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
        {
APL_IF_DEBUG
 {
CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of CR_Mod_company.Going for updation after validating company\
                n",NULL,p_intl_envdatastruct_h);

 }
        if (APL_SUCCESS ==  MT_Chk_CmpanyFn(p_mt_company_struct_h->h_cmp_code,'Y',NULL,'N',l_debug_info_ptr))
           {   
             if (APL_SUCCESS ==  MTCompanyInInstruFn(p_mt_company_struct_h->h_cmp_code,l_debug_info_ptr))
               {  
                        MT_Mod_DbCompanyFn(p_mt_company_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
                  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
               }
             }

else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_COMPANY_CANT_DEL,
                "Securities Table",
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
                int_error_flag = APL_FAILURE;
   }
else
if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
            APL_GOBACK_FAIL
            }
         }
  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
        {
APL_IF_DEBUG
 {
CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of CR_Mod_company.Going for updation after validating \
                n",NULL,p_intl_envdatastruct_h);
}

if (APL_SUCCESS == MT_Chk_CmpanyFn(p_mt_company_struct_h->h_cmp_code,'Y',NULL,NULL,l_debug_info_ptr)) //Changes done for AIX Migration
{
 if(APL_SUCCESS == MT_Chk_MkrChkr_Company(p_mt_company_struct_h->h_cmp_code,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
                {
               MT_Mod_DbCompanyFn(p_mt_company_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
                if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
               } 
              
                else
           {
               if (CO_InsertErr
                        (l_debug_info_ptr,
                         ERR_RESET_NOTALLOWED,
                         APL_NULL_STRING,
                         APL_NULL_STRING,
                         APL_NULL_STRING,
                         __LINE__,
                         __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        APL_GOBACK_FAIL
              }
}
else
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
          } 
if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
            APL_GOBACK_FAIL
            }
else
APL_GOBACK_SUCCESS;

  RETURN_SUCCESS :
        {
CO_ProcMonitor(APL_OUT_FILE, "Success in CR_Mod_company.Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_SUCCESS);
        }
  RETURN_FAILURE :
        {
   CO_ProcMonitor(APL_OUT_FILE, "Failed in CR_Mod_company. Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_FAILURE);
        }

}
