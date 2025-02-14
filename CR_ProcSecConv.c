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
#include <CR_Header_C.h>



int CR_Mod_NewSecConv(DL_INSTRUMENTCONV_OTH_STRUCT_H *p_dl_instrumentconv_oth_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval;
	short							int_l_condexists;
	char							chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
	char							chr_l_condid[APL_CONDID_LEN];
	char							chr_iexist,chr_iauthorised,chr_iconverted;
	char							chr_l_buf[BUFFER_LEN];
	char							chr_l_field_val[40];
	char							chr_l_row_id_from_sec[APL_ROWID_LEN+1];
	char							chr_l_row_id_to_sec[APL_ROWID_LEN+1];
	char 							chr_l_h_from_tiposec[TYPEOF_SEC_LEN] = APL_NULL_STRING,
									chr_l_h_to_tiposec[TYPEOF_SEC_LEN] = APL_NULL_STRING;
   double      			   int_l_retval = 0,
									l_h_from_minfmttrdquantity = 0,
						       	l_h_to_minfmttrdquantity = 0;
	
	APL_IF_DEBUG
		CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CR_Mod_NewSecConv \n",NULL,p_intl_env_data_struct_h_d);

	memset(chr_l_row_id_from_sec,APL_NULL_CHAR,sizeof(chr_l_row_id_from_sec));
	memset(chr_l_row_id_to_sec,APL_NULL_CHAR,sizeof(chr_l_row_id_to_sec));

	if (strlen(p_dl_instrumentconv_oth_struct_h->h_frm_seccd) == 0)
		APL_DATA_MISSING("FROM SECURITY CODE",APL_NULL_STRING,APL_NULL_STRING)
	if (strlen(p_dl_instrumentconv_oth_struct_h->h_to_security) == 0)
		APL_DATA_MISSING("TO SECURITY CODE",APL_NULL_STRING,APL_NULL_STRING)
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_IF_DEBUG
	{
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"From Security is %s \n",p_dl_instrumentconv_oth_struct_h->h_frm_seccd);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"To Security is %s \n",p_dl_instrumentconv_oth_struct_h->h_to_security);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

		memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
		sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
	}

	chr_iexist = 'Y';
	chr_iauthorised = 'Y';
	chr_iconverted = 'N';

	int_retval = CO_Chk_SecValid(p_dl_instrumentconv_oth_struct_h->h_frm_seccd,chr_iexist,chr_iauthorised,NULL,NULL,NULL,chr_iconverted,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = CO_Chk_SecValid(p_dl_instrumentconv_oth_struct_h->h_to_security,chr_iexist,chr_iauthorised,NULL,NULL,NULL,NULL,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL
	
	int_retval = CR_Rtv_SecChrVal(p_dl_instrumentconv_oth_struct_h->h_frm_seccd,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_from_sec,chr_l_field_val);
	 
	int_retval = CR_Rtv_SecChrVal(p_dl_instrumentconv_oth_struct_h->h_to_security,"ROWID",chr_l_field_val,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_row_id_to_sec,chr_l_field_val);
	
	int_retval = CR_Chk_SecConvCyclic(p_dl_instrumentconv_oth_struct_h->h_frm_seccd,chr_l_row_id_to_sec,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		CO_InsertErr(l_debug_info_ptr,ERR_SEC_CANT_CONVERT,p_dl_instrumentconv_oth_struct_h->h_frm_seccd,p_dl_instrumentconv_oth_struct_h->h_to_security,APL_NULL_STRING,__LINE__,__FILE__);
	
	strcpy(chr_mainfuncarea, "SEC_CONV");
	strcpy(chr_l_condid, "CHK_CLSCODE");

	int_retval = CO_Chk_CntryEnabled(chr_mainfuncarea,chr_l_condid,&int_l_condexists,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_condexists > 0)
	{
		int_retval = CR_Chk_SecConvClass(p_dl_instrumentconv_oth_struct_h,chr_l_row_id_from_sec,chr_l_row_id_to_sec,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
			CO_InsertErr(l_debug_info_ptr,ERR_SEC_CANT_CONVERT,APL_NULL_STRING,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		
	}

	
	
	
	int_retval = CR_Rtv_SecChrVal(p_dl_instrumentconv_oth_struct_h->h_frm_seccd,"tiposec",chr_l_field_val,l_debug_info_ptr);
	
   if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_h_from_tiposec,chr_l_field_val);


	int_retval = CR_Rtv_SecChrVal(p_dl_instrumentconv_oth_struct_h->h_to_security,"tiposec",chr_l_field_val,l_debug_info_ptr);
		
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	strcpy(chr_l_h_to_tiposec,chr_l_field_val);


	int_retval = CR_Rtv_SecNumVal(p_dl_instrumentconv_oth_struct_h->h_frm_seccd,"minfmttrdqty",&int_l_retval,l_debug_info_ptr);
		
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	l_h_from_minfmttrdquantity = int_l_retval;

	int_retval = CR_Rtv_SecNumVal(p_dl_instrumentconv_oth_struct_h->h_to_security,"minfmttrdqty",&int_l_retval,l_debug_info_ptr);
		
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	l_h_to_minfmttrdquantity = int_l_retval;

	if (strcmp(chr_l_h_to_tiposec,APL_INSTRU_FMT) == 0)
	{
		if(strcmp(chr_l_h_from_tiposec,APL_INSTRU_FMT) == 0)
		{
			if(l_h_from_minfmttrdquantity != l_h_to_minfmttrdquantity)
			{
				CO_InsertErr(l_debug_info_ptr,
									ERR_SEC_CANT_CONVERT,
									"Min Denom Different",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,__FILE__);
				 APL_GOBACK_FAIL
			}
		}
		else
		{	
			CO_InsertErr(l_debug_info_ptr,
						 		ERR_SEC_CANT_CONVERT,
			 					"Non-FMT to FMT CONV",
					 		   APL_NULL_STRING,
			 		         APL_NULL_STRING,
								__LINE__,__FILE__);
			 APL_GOBACK_FAIL
		}
	}	


	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Mod_SecConv(p_dl_instrumentconv_oth_struct_h,chr_l_row_id_from_sec,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_NewSecConv \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		APL_IF_DEBUG
			CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CR_Mod_NewSecConv \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}
