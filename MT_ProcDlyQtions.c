 /*  Copyright 2005 Polaris Software Lab Limited. All rights reserved.
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
 * Module Name         :  MASTERS MAINTAINANCE
 *
 * File Name           :   MT_ProcDlyQtions.c
 *
 * Description         :   This file contains functions for Daily Quotations Details .
 * It contains all functions related to Input/Modify/Authorize/Delete/Reset modes

 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 * 26/11/2005   1.0          ANIL             NEW FILE  RFS No HDFCMT_009
 * 07/02/2006   1.1          Kouser Begum     New Changes for Quotation Date 
 *                                            Validation
 *
 *********************************************************************/

#include "CO_HostStructdef.h"
#include "Intellect_Interface.h"
#include "Intellect_Error.h"
#include "Intellect_Common.h"
int MT_Moddlyqtions(MT_DLYQTIONS_STRUCT_H *p_mt_dlyqtions_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
  int int_error_flag = APL_SUCCESS;
  short int_ret_val = 0;
  APL_IF_DEBUG
   {
   CO_ProcMonitor(APL_OUT_FILE, "Entered Function MT_Moddlyqtions. Going for mandatory checks\n",NULL,p_intl_envdatastruct_h);
   }


   /**** Check For Existency of Mandatory Fields ****/
 
 if (!strlen(p_mt_dlyqtions_struct_h->h_exch_code))
    {
      APL_DATA_MISSING("Exchange Code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

 if (!strlen(p_mt_dlyqtions_struct_h->h_instr_code))
    {
      APL_DATA_MISSING("INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
 
 if (!strlen(p_mt_dlyqtions_struct_h->h_quot_date))
    {
      APL_DATA_MISSING("Quotation date",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
/** IsolveID-:AmitB:160407:Removed Mandatory Check

 if (p_mt_dlyqtions_struct_h->h_quot_prev_date == 0)
    {
      APL_DATA_MISSING("Previous Close",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
**/
 if (p_mt_dlyqtions_struct_h->h_open_at == 0)
    {
      APL_DATA_MISSING("OPEN AT",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

 if (p_mt_dlyqtions_struct_h->h_low_at == 0)
    {
      APL_DATA_MISSING("LOW AT",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
 if (p_mt_dlyqtions_struct_h->h_high_at == 0)
    {
      APL_DATA_MISSING("HIGH AT",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

 if (p_mt_dlyqtions_struct_h->h_close_at == 0)
    {
      APL_DATA_MISSING("CLOSE AT",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

 int_ret_val = CO_Chk_CodeValid("EXCHANGE",p_mt_dlyqtions_struct_h->h_exch_code,(char *)g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr);//Changes done for AIX Migration

   if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL

  /** Kouser - HDFCMT_009 - Check for the Quotation Date Cannot be Future Date **/

  if (strlen(p_mt_dlyqtions_struct_h->h_quot_date) != 0)
  {
  printf("Value of Date from struct ==|%s|\n",p_mt_dlyqtions_struct_h->h_quot_date);

	 int_ret_val = CR_Chk_RegDateValid(p_mt_dlyqtions_struct_h->h_quot_date,l_debug_info_ptr);
     printf("Value of int_retval == |%d|\n",int_ret_val);

	 if (int_ret_val == APL_RECS_EXIST)
	  {
  		 printf("Value of Date from struct ==|%s|\n",p_mt_dlyqtions_struct_h->h_quot_date);

	    CO_InsertErr(l_debug_info_ptr,ERR_DATE_CANT_FUTURE,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		 APL_GOBACK_FAIL
	  }
  }

  /** Kouser - HDFCMT_009 - Check for the Quotation Date Cannot be Future Date **/

 if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
        {
     APL_IF_DEBUG
           {
  CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of MT_Moddlyqtions.Going for updation\n",
                NULL,p_intl_envdatastruct_h);
            }
    if (APL_SUCCESS ==  CR_Chk_ValAtInstrument(p_mt_dlyqtions_struct_h,l_debug_info_ptr))
             {
        MT_ModDlyQtionsFn(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);

         if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
             }
               else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_DAILYQUOTATION_CANT_INP,
                APL_NULL_STRING,
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
        }
 else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
        {
     APL_IF_DEBUG
              {
CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of MT_Moddlyqtions.Going for updation after validating client instrument details\n",NULL,p_intl_envdatastruct_h);
               }
     if (APL_SUCCESS == ChkDlyQtions(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))  
          {
     if (APL_SUCCESS ==  CR_Chk_ValAtInstrument(p_mt_dlyqtions_struct_h,l_debug_info_ptr))
           {
            MT_ModDlyQtionsFn(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
             if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
           }
                else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_DAILYQUOTATION_CANT_MODIFY,
                APL_NULL_STRING,
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
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
CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of MT_Moddlyqtions.Going for updation after validating instruction slip\n",NULL,p_intl_envdatastruct_h);
                    }
 if (APL_SUCCESS == ChkDlyQtions(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValDlyQtionsFn(p_mt_dlyqtions_struct_h->h_exch_code,p_mt_dlyqtions_struct_h->h_instr_code,p_mt_dlyqtions_struct_h->h_quot_date,'Y','N',NULL,l_debug_info_ptr))
           {
      if (APL_SUCCESS ==  CR_Chk_ValAtInstrument(p_mt_dlyqtions_struct_h,l_debug_info_ptr))
             {
   if(APL_SUCCESS == MTMkrCkrDlyQtionsFn(p_mt_dlyqtions_struct_h->h_exch_code,p_mt_dlyqtions_struct_h->h_instr_code,p_mt_dlyqtions_struct_h->h_quot_date,p_intl_envdatastruct_h->usr, l_debug_info_ptr))
              {
          MT_ModDlyQtionsFn(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
                else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_DAILYQUOTATION_CANT_AUT,
                APL_NULL_STRING,
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
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
 else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
        {
       APL_IF_DEBUG
          {
CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of MT_Moddlyqtions.Going for updation after validating \n",NULL,p_intl_envdatastruct_h);
          }

if (APL_SUCCESS == ChkDlyQtions(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  CR_Chk_ValAtInstrument(p_mt_dlyqtions_struct_h,l_debug_info_ptr))
            {
if(APL_SUCCESS == MTMkrCkrDlyQtionsFn(p_mt_dlyqtions_struct_h->h_exch_code,p_mt_dlyqtions_struct_h->h_instr_code,p_mt_dlyqtions_struct_h->h_quot_date,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
                {
               MT_ModDlyQtionsFn(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
                else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_DAILYQUOTATION_CANT_RESET,
                APL_NULL_STRING,
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
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
CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of MT_Moddlyqtions.Going for updation after validating \n",NULL,p_intl_envdatastruct_h);
            }
 if (APL_SUCCESS == ChkDlyQtions(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValDlyQtionsFn(p_mt_dlyqtions_struct_h->h_exch_code,p_mt_dlyqtions_struct_h->h_instr_code,p_mt_dlyqtions_struct_h->h_quot_date,'Y',NULL,'N',l_debug_info_ptr)) //Changes done for AIX Migration
           {
 if (APL_SUCCESS ==  CR_Chk_ValAtInstrument(p_mt_dlyqtions_struct_h,l_debug_info_ptr))
             {
           MT_ModDlyQtionsFn(p_mt_dlyqtions_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
               if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
             }
                else if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_DAILYQUOTATION_CANT_DEL,
                "Safekeeping Table",
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
         }
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
if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
            APL_GOBACK_FAIL
            }
else
APL_GOBACK_SUCCESS

  RETURN_SUCCESS :
        {
CO_ProcMonitor(APL_OUT_FILE, "Success in MT_Moddlyqtions.Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_SUCCESS);
        }

  RETURN_FAILURE :
        {
CO_ProcMonitor(APL_OUT_FILE, "Failed in MT_Moddlyqtions. Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_FAILURE);
        }
}
