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
 * Module Name         :  MASTERS MAINTAINANCE
 *
 * File Name           :  MT_Procclntinstr.c
 *
 * Description         :  This file contains functions for Client Instrument Details .
 *                           It contains all functions related to Input/Modify/Authorize/Delete/Reset modes
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 *              1.0         ANIL                NEW FILE  RFSNo.HDFCMT_005
 *
 *********************************************************************/



#define PURE_C_SOURCE
#include "CO_HostStructdef.h"
#include "Intellect_Interface.h"
#include "Intellect_Error.h"
#include "Intellect_Common.h"

int MT_ModClninstr(MT_CLN_INSTR_STRUCT_H *p_mt_cln_instr_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{
  int int_error_flag=APL_SUCCESS;

APL_IF_DEBUG
       {
          CO_ProcMonitor(APL_OUT_FILE, "Entered Function MT_ModClninstr. Going for mandatory checks\n",
                NULL,p_intl_envdatastruct_h);
       }

   /**** Check For Existency of Mandatory Fields ****/
   if (!strlen(p_mt_cln_instr_struct_h->h_cln_code))
    {
      APL_DATA_MISSING("client Code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
    if (!strlen(p_mt_cln_instr_struct_h->h_instr_code))
    {
      APL_DATA_MISSING("Instrument code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
    if (!strlen(p_mt_cln_instr_struct_h->h_cln_instr_code))
    {
     APL_DATA_MISSING("Client instrument code",APL_NULL_STRING,APL_NULL_STRING);
      int_error_flag = APL_FAILURE;
    }
    if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
        {
   APL_IF_DEBUG
      {
         CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of MT_ModClninstr.Going for updation\n",
                NULL,p_intl_envdatastruct_h);
       }
      /***if (APL_SUCCESS ==  Cr_Chk_ValatClninstr(p_mt_cln_instr_struct_h,l_debug_info_ptr))
             { **/
             MT_UpdCln_Instr(p_mt_cln_instr_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
                if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
             /***}
            else 
				{
					if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_CLIENTINSTRUMENT_CANT_INP,
                APL_NULL_STRING,
                APL_NULL_STRING,
                APL_NULL_STRING,
                __LINE__,
                __FILE__
                ) != APL_SUCCESS)
                APL_GOBACK_FAIL
                APL_GOBACK_FAIL
				}**/
      }

 else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
        {
        APL_IF_DEBUG
              {
CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of MT_ModClninstr.Going for updation after validating client instrument details\n",NULL,p_intl_envdatastruct_h);
               }
     if (APL_SUCCESS == CRChkClnInstr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
     if (APL_SUCCESS ==  Cr_Chk_ValatClninstr(p_mt_cln_instr_struct_h,l_debug_info_ptr))
           {
            MT_UpdCln_Instr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
             if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
             } 
         else 
			{
				if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_CLIENTINSTRUMENT_CANT_MODIFY,
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
         CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of MT_ModClninstr.Going for updation after validating client instrument \n",NULL,p_intl_envdatastruct_h);
                       }
 if (APL_SUCCESS == CRChkClnInstr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValclninstrFn(p_mt_cln_instr_struct_h->h_cln_instr_code,p_mt_cln_instr_struct_h->h_cln_code,'Y','N',NULL,l_debug_info_ptr))
           {
      if (APL_SUCCESS ==  Cr_Chk_ValatClninstr(p_mt_cln_instr_struct_h,l_debug_info_ptr))
             {
        if(APL_SUCCESS == MTUsrAuthClnInstrFn(p_mt_cln_instr_struct_h->h_instr_code,p_mt_cln_instr_struct_h->h_cln_code,
                                      p_intl_envdatastruct_h->usr, l_debug_info_ptr))
                {
                MT_UpdCln_Instr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
                ERR_CLIENTINSTRUMENT_CANT_AUT,
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
 else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_DELETE))
        {
     APL_IF_DEBUG
           {
CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of MT_ModClninstr .Going for updation after validating \
                n",NULL,p_intl_envdatastruct_h);
            }
 if (APL_SUCCESS == CRChkClnInstr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  MTValclninstrFn(p_mt_cln_instr_struct_h->h_cln_instr_code,p_mt_cln_instr_struct_h->h_cln_code,'Y',NULL,'N',
                                                    l_debug_info_ptr))
           {
 if (APL_SUCCESS ==  Cr_Chk_ValatClninstr(p_mt_cln_instr_struct_h,l_debug_info_ptr))
           {
           MT_UpdCln_Instr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
               if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
                {
                APL_GOBACK_FAIL
                }
            }

              else
				  {
					  if(CO_InsertErr(
                l_debug_info_ptr,
                ERR_CLIENTINSTRUMENT_CANT_DEL,
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
else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
        {
       APL_IF_DEBUG
                      {
CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of MT_ModClninstr.Going for updation after validating \
                n",NULL,p_intl_envdatastruct_h);
                        }

if (APL_SUCCESS == CRChkClnInstr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
          {
if (APL_SUCCESS ==  Cr_Chk_ValatClninstr(p_mt_cln_instr_struct_h,l_debug_info_ptr))
{ 
if(APL_SUCCESS == MTUsrAuthClnInstrFn(p_mt_cln_instr_struct_h->h_instr_code,p_mt_cln_instr_struct_h->h_cln_code,p_intl_envdatastruct_h->usr,
l_debug_info_ptr))
                {
               MT_UpdCln_Instr(p_mt_cln_instr_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
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
                ERR_CLIENTINSTRUMENT_CANT_RESET,
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
APL_GOBACK_SUCCESS

  RETURN_SUCCESS :
        {
CO_ProcMonitor(APL_OUT_FILE, "Success in MT_ModClninstr.Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_SUCCESS);
        }

  RETURN_FAILURE :
        {
   CO_ProcMonitor(APL_OUT_FILE, "Failed in MT_ModClninstr. Getting out!!\n",NULL,p_intl_envdatastruct_h);
 return(APL_FAILURE);
        }

}
