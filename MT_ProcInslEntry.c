   /*COPYRIGHT NOTICE
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
 * Module Name         : Master Maintenance
 *
 * File Name           : MT_ProcInslEntry.c
 *
 * Description         : This file contains functions for Instruction slip Details .
 *                           It contains all functions related to Input/Modify/Authorize/Delete/Reset modes
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 *              1.0           ANIL              NEW FILE RFSNo HDFCMT_006
 *10/12/2005   1.1          Sonali              Added for failure ,HDFCMT_006
 *14/12/2005   1.2          Sonali              Added brace brkt for failure ,HDFCMT_006
 *14/12/2005   1.3          Sonali              Replaced Country IN by global var of common sys, HDFCMT_006
 *
 *********************************************************************/

#define PURE_C_SOURCE
#include "Intellect_Common.h"
#include "CO_HostStructdef.h"
#include "Intellect_Interface.h"
#include "Intellect_Error.h"

int MT_Mod_Inslentry(MT_INSL_ENTRY_STRUCT_H *p_mt_insl_entry_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
  int int_error_flag = APL_SUCCESS;
 short int_ret_val = 0;
 
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function MT_Mod_Inslentry. Going for mandatory checks\n",
                NULL,p_intl_envdatastruct_h);
 }

 int_ret_val = CO_Chk_CodeValid("DEPOSITORY",p_mt_insl_entry_struct_h->h_depo_code,(char *)g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr);//Changes done for AIX Migration

   if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL
    int_ret_val = CO_Chk_CodeValid("TRANSTYPE",p_mt_insl_entry_struct_h->h_trans_type,(char *)g_mt_commonsys_params_struct_h.nation_code,l_debug_info_ptr);//Changes done for AIX Migration
           if (int_ret_val != APL_SUCCESS)
         APL_GOBACK_FAIL

   /**** Check For Existency of Mandatory Fields ****/
 if (!strlen(p_mt_insl_entry_struct_h->h_depo_code))
    {
      APL_DATA_MISSING("Depository Code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
if (!strlen(p_mt_insl_entry_struct_h->h_depo_part_code))
    {
      APL_DATA_MISSING("Depository Participant Code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
    if (!strlen(p_mt_insl_entry_struct_h->h_cln_code))
    {
      APL_DATA_MISSING("CLIENT CODE",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

    if (!strlen(p_mt_insl_entry_struct_h->h_trans_type))
    {
      APL_DATA_MISSING("TRANSACTION TYPE",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
if (!strlen(p_mt_insl_entry_struct_h->h_slip_series))
    {
      APL_DATA_MISSING("SLIP SERIES",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

if (p_mt_insl_entry_struct_h->h_sr_no_from == 0)
    {
      APL_DATA_MISSING("SERIAL NO FROM",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

if (p_mt_insl_entry_struct_h->h_sr_no_to == 0)
    {
      APL_DATA_MISSING("SERIAL NO TO",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
if (p_mt_insl_entry_struct_h->h_sr_avl_qty == 0)
    {
      APL_DATA_MISSING("SERIAL AVAILABLE",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }

      if(p_mt_insl_entry_struct_h->h_sr_no_from > p_mt_insl_entry_struct_h->h_sr_no_to)
        {
           if (CO_InsertErr
                        (l_debug_info_ptr,
                         ERR_SRFROM_GREATER,
                         APL_NULL_STRING,
                         APL_NULL_STRING,
                         APL_NULL_STRING,
                         __LINE__,
                         __FILE__
                        ) != APL_SUCCESS)
                        APL_GOBACK_FAIL
                        APL_GOBACK_FAIL
             }
      if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
        {
          APL_IF_DEBUG
           {
  CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of MT_Mod_Inslentry.Going for updation\n",
                NULL,p_intl_envdatastruct_h);
             }
    if (APL_SUCCESS ==  CR_Chk_ValAtClient(p_mt_insl_entry_struct_h,l_debug_info_ptr))
             {
        MT_DbInslEntryFn(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);

         if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
               }
        }
	 
      else
		{
			if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_INSTRUCTIONSLIP_CANT_INP,
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
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
        {
        APL_IF_DEBUG
              {
CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of MT_Mod_Inslentry.Going for updation after validating client instrument details\n",NULL,p_intl_envdatastruct_h);
               }
     if (APL_SUCCESS == ChkInstrSlip(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
     if (APL_SUCCESS ==  CR_Chk_ValAtClient(p_mt_insl_entry_struct_h,l_debug_info_ptr))
           {
            MT_DbInslEntryFn(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
             if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
             }
         else 
			{	
				if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_INSTRUCTIONSLIP_CANT_MODIFY,
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
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
        {
            APL_IF_DEBUG
                   {
     CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of MT_Mod_Inslentry.Going for updation after validating instrument slip\n",NULL,p_intl_envdatastruct_h);
                       }
 if (APL_SUCCESS == ChkInstrSlip(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValinstrslipFn(p_mt_insl_entry_struct_h->h_depo_code,p_mt_insl_entry_struct_h->h_depo_part_code,p_mt_insl_entry_struct_h->h_cln_code,p_mt_insl_entry_struct_h->h_trans_type,'Y','N',NULL,l_debug_info_ptr))
           {
      if (APL_SUCCESS ==  CR_Chk_ValAtClient(p_mt_insl_entry_struct_h,l_debug_info_ptr))
             {
        if(APL_SUCCESS == MTMkrCkrInstrFn(p_mt_insl_entry_struct_h->h_depo_code,p_mt_insl_entry_struct_h->h_depo_part_code,p_mt_insl_entry_struct_h->h_cln_code,p_mt_insl_entry_struct_h->h_trans_type,p_intl_envdatastruct_h->usr, l_debug_info_ptr))
                {
                MT_DbInslEntryFn(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
 {
	 if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_INSTRUCTIONSLIP_CANT_AUT,
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
CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of MT_Mod_Inslentry.Going for updation after validating \
                n",NULL,p_intl_envdatastruct_h);
                        }

if (APL_SUCCESS == ChkInstrSlip(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  CR_Chk_ValAtClient(p_mt_insl_entry_struct_h,l_debug_info_ptr))
{
if(APL_SUCCESS == MTMkrCkrInstrFn(p_mt_insl_entry_struct_h->h_depo_code,p_mt_insl_entry_struct_h->h_depo_part_code,p_mt_insl_entry_struct_h->h_cln_code,p_mt_insl_entry_struct_h->h_trans_type,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
                {
               MT_DbInslEntryFn(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
{
  	if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_INSTRUCTIONSLIP_CANT_RESET,
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
else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
            {
            APL_GOBACK_FAIL
            }
}
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
        {
     APL_IF_DEBUG
           {
CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of MT_Mod_Inslentry .Going for updation after validating \
                n",NULL,p_intl_envdatastruct_h);
            }
 if (APL_SUCCESS == ChkInstrSlip(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValinstrslipFn(p_mt_insl_entry_struct_h->h_depo_code,p_mt_insl_entry_struct_h->h_depo_part_code,p_mt_insl_entry_struct_h->h_cln_code,p_mt_insl_entry_struct_h->h_trans_type,'Y',NULL,'N',l_debug_info_ptr))
           {
 if (APL_SUCCESS ==  CR_Chk_ValAtClient(p_mt_insl_entry_struct_h,l_debug_info_ptr))
           {
           MT_DbInslEntryFn(p_mt_insl_entry_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
               if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
            }

              else 
				  {
					 if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_INSTRUCTIONSLIP_CANT_DEL,
                "Safekeeping Table",
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
                APL_GOBACK_FAIL
				  }
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
CO_ProcMonitor(APL_OUT_FILE, "Success in MT_Mod_Inslentry.Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_SUCCESS);
        }

  RETURN_FAILURE :
        {
   CO_ProcMonitor(APL_OUT_FILE, "Failed in MT_Mod_Inslentry. Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_FAILURE);
        }

}

