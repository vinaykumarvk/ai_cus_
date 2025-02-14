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
 * Module Name         :	
 *
 * File Name           :
 *
 * Description         :	
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *					
 *
 *********************************************************************/










#define PURE_C_SOURCE 
#include "CR_Header_C.h" 

int CR_Proc_SecCdChg (DL_INSTRUMENTCHG_STRUCT2_H *l_dl_instrumentchg_struct2_ha, 
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  char chr_l_sysdate_b[APL_DATE_LEN];
  char chr_l_listedflg[APL_FLAG_LENGTH];
  char chr_l_chgmaker[APL_USERID_LEN];

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CBCBSecChgCdFn. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  

  if (!strlen(l_dl_instrumentchg_struct2_ha->h_oldsecuritycd)) {APL_DATA_MISSING("Old Secode",APL_NULL_STRING,APL_NULL_STRING);}
  if (!strlen(l_dl_instrumentchg_struct2_ha->h_newsecuritycd)) {APL_DATA_MISSING("New Secode",APL_NULL_STRING,APL_NULL_STRING);}
  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
  if (!strlen(l_dl_instrumentchg_struct2_ha->h_timestamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);}
  }



  if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(l_dl_instrumentchg_struct2_ha->h_newsec_isincode)) {APL_DATA_MISSING("New ISIN code",APL_NULL_STRING,APL_NULL_STRING);}
	if (!strlen(l_dl_instrumentchg_struct2_ha->h_listed_ind)) {APL_DATA_MISSING("Listed Flag",APL_NULL_STRING,APL_NULL_STRING);}
 	}

   

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
        APL_GOBACK_FAIL
        }



	if (strlen(l_dl_instrumentchg_struct2_ha->h_newsec_isincode) <12)
	{
      if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_ISINCD_CANT_LESS_12CHAR,
          
          APL_NULL_STRING,
          APL_NULL_STRING,
          APL_NULL_STRING,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL
	}

	if (APL_FAILURE ==CO_Chk_SecValid(l_dl_instrumentchg_struct2_ha->h_oldsecuritycd,
											'Y','Y',
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											l_debug_info_ptr))
        {
        APL_GOBACK_FAIL
        }

   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
     	APL_GOBACK_FAIL
	   }

	if (APL_FAILURE ==CO_Chk_SecValid(l_dl_instrumentchg_struct2_ha->h_newsecuritycd,
											'N',
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											l_debug_info_ptr))
        {
        APL_GOBACK_FAIL
        }

   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
     	APL_GOBACK_FAIL
	   }

	memset(chr_l_sysdate_b, APL_NULL_CHAR, APL_DATE_LEN);
	memset(chr_l_listedflg, APL_NULL_CHAR, APL_FLAG_LENGTH);
	memset(chr_l_chgmaker, APL_NULL_CHAR, APL_USERID_LEN);

   if ( APL_FAILURE == CR_Rtv_SecChngDet(l_dl_instrumentchg_struct2_ha->h_oldsecuritycd,
												  chr_l_sysdate_b,
												  chr_l_chgmaker,
												  chr_l_listedflg,
                                      l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }
 

  if(!strcmp(chr_l_listedflg,"Y"))
	{
   strcpy(l_dl_instrumentchg_struct2_ha->h_listed_ind,"Y");	
   }

   
  if((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))||
		(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE)))
	{
	if(!strlen(chr_l_chgmaker))
	  	{
	   if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_SEC_NOTUNDERCHG,
          
          APL_NULL_STRING,
          APL_NULL_STRING,
          APL_NULL_STRING,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL	
	  	}
	}

   if(strcmp(chr_l_sysdate_b,l_dl_instrumentchg_struct2_ha->h_timestamp))
	{
	   if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_ACCESSSTAMP_CHGD,
          
          chr_l_sysdate_b,
          "User Access Stamp:",
          l_dl_instrumentchg_struct2_ha->h_timestamp,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL	
	}

  if((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))||
		(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE)))
	{
   if ( APL_FAILURE == CR_Proc_SecChngMkrChr(l_dl_instrumentchg_struct2_ha->h_oldsecuritycd,
								  p_intl_envdatastruct_h->usr,
                          l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }
	}

 				
   if ( APL_FAILURE == CR_Mod_SecChngDet(l_dl_instrumentchg_struct2_ha,
								  p_intl_envdatastruct_h,
                          l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }


  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     	{
        APL_GOBACK_FAIL
   	}

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Successfully leaving CR_Proc_SecCdChg\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Proc_SecCdChg unsuccessfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_FAILURE);
	}
}

