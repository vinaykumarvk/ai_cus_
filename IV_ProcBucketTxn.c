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
 * Module Name         :      Billing Maintenance
 *
 * File Name           :      IV_ProcBucketTxn.c
 *
 * Description         :      This file contains functions for updating
 *                            Basket Transaction Details.
 *
 *
 *            Version Control Block
 *
 * Date        Version     Author             Description       RFS No.
 * ---------   --------  ------------         -------------     ---------
 * 16/03/2006   1.0       Praveen Magdum       New file        HDFCIV_007
 *
 *********************************************************************/



#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"



int IV_Proc_BucketTxnMnt(const IV_BUCKET_TXN_STRUCT *p_ivBucketTxn_struct,const INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	
	int pass_value_seqno = 0;  
	char chr_l_usermode;
	int int_l_retstat = 0;
	int chr_l_seq_num = 0;
	IV_BUCKET_TXN_STRUCT l_ivBucketTxn_struct= *p_ivBucketTxn_struct;
	
	PRO_GSEQNUM_STRUCT_H   *l_progseqnum_struct_h     = NULL;


	if ( !strlen(p_intlenv_data_struct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( !strlen(p_intlenv_data_struct_h->h_mode) )
	{
		APL_DATA_MISSING("User Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( !strcmp(p_intlenv_data_struct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intlenv_data_struct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intlenv_data_struct_h->h_mode, APL_FUNC_DELETE) )
	{
		chr_l_usermode = 'D';
	}
   
    
	l_progseqnum_struct_h = (PRO_GSEQNUM_STRUCT_H *)calloc(1,sizeof(PRO_GSEQNUM_STRUCT_H));
   memset(l_progseqnum_struct_h,NULL,sizeof(PRO_GSEQNUM_STRUCT_H));
   APL_MALLOC_FAIL(l_progseqnum_struct_h);
   memset(l_progseqnum_struct_h,NULL,sizeof(PRO_GSEQNUM_STRUCT_H));

	int_l_retstat = 0;

	if ( chr_l_usermode == 'I' )
	{
	   if ( !strlen(l_ivBucketTxn_struct.identitylist) )
		{
			APL_DATA_MISSING("IDENTITYLIST", APL_NULL_STRING, 
				                  APL_NULL_STRING)
		}

  
	   if ( !strlen(l_ivBucketTxn_struct.client) )
		{
			APL_DATA_MISSING("CLIENT", APL_NULL_STRING, 
				                  APL_NULL_STRING)
		}
	   
	  	if (APL_FAILURE == IV_Mod_BucketTxnNew(l_ivBucketTxn_struct,p_intlenv_data_struct_h,l_debug_info_ptr))
			APL_GOBACK_FAIL 
                  
	}

   if ( chr_l_usermode == 'M' )
	{
		
		if ( !strlen(l_ivBucketTxn_struct.identitylist) )
		{
			APL_DATA_MISSING("IDENTITYLIST", APL_NULL_STRING, 
				         APL_NULL_STRING)
		}
     
      		
	   if ( l_ivBucketTxn_struct.sequence_no == 0 )
		{
			APL_DATA_MISSING("SEQUENCE_NO", APL_NULL_STRING, 
				         APL_NULL_STRING)
		}
		
		if (APL_FAILURE == IV_Mod_BucketTxnChg(l_ivBucketTxn_struct,p_intlenv_data_struct_h,l_debug_info_ptr))
			APL_GOBACK_FAIL
	}
   
	
   if ( chr_l_usermode == 'D' )
	{
	   
	
		if (l_ivBucketTxn_struct.sequence_no == 0 )
	   {
			APL_DATA_MISSING("SEQUENCE_NO", APL_NULL_STRING,
					      APL_NULL_STRING)
		}
		
		if (APL_FAILURE ==  IV_Mod_BucketTxnDel(l_ivBucketTxn_struct,p_intlenv_data_struct_h,l_debug_info_ptr))
		   APL_GOBACK_FAIL  
	}

	
	
					    
		APL_GOBACK_SUCCESS

   RETURN_SUCCESS:
//AIX Warning Removal - braces added
   { 
      APL_IF_DEBUG
      {
         CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_Proc_BucketTxnMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
      
      }
         return APL_SUCCESS;
		}

   RETURN_FAILURE:

    {
      APL_IF_DEBUG
      {
         CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_Proc_BucketTxnMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
      

		}

         return APL_FAILURE;
		}
}	



