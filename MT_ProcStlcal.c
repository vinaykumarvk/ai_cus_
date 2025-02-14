/*    Copyright 2005 Polaris Software Lab Limited. All rights reserved. 
      These materials are confidential and proprietary to
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
 * File Name           :   MT_ProcStlcal.c 
 *
 * Description         :   This file contains functions for Settlement Calendar Details .
 * It contains all functions related to Input/Modify/Authorize/Delete/Reset modes
 *
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description
 * ---------   --------  ---------------  ---------------------------
 * 01/12/2005              1.0          ANIL            NEW FILE RFSNo HDFCMT_008
 *********************************************************************/

#include "CO_HostStructdef.h"

int MT_ModSetCal(MT_SETTLCAL_STRUCT_H *p_mt_settlcal_struct_h,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
					 DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
		  int int_error_flag = APL_SUCCESS;
		  short int_ret_val = 0;

		  APL_IF_DEBUG
		  {
					 CO_ProcMonitor(APL_OUT_FILE, "Entered Function MT_ModSetCal. Going for mandatory checks\n",NULL,p_intl_envdatastruct_h);
		  }

		  int_ret_val = CO_Chk_CodeValid("EXCHANGE",p_mt_settlcal_struct_h->h_exch_code,"IN",l_debug_info_ptr);

		  if (int_ret_val != APL_SUCCESS)
					 APL_GOBACK_FAIL

								printf("|%s|\n", p_mt_settlcal_struct_h->h_settl_type);

        /*
		  int_ret_val = CO_Chk_CodeValid("MKT_TYP",p_mt_settlcal_struct_h->h_settl_type,"IN",l_debug_info_ptr);
		  if (int_ret_val != APL_SUCCESS)
					 APL_GOBACK_FAIL
			*/
								/**** Check For Existency of Mandatory Fields ****/
								printf("Manadator hecks startedi\n");
		  if (!strlen(p_mt_settlcal_struct_h->h_exch_code))
		  {
					 APL_DATA_MISSING("Exchange Code",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		
		  /* CHANGE BY AMISH --CC ID MADE NON MADATORY -- 09/05 */  
        /*
		  if (!strlen(p_mt_settlcal_struct_h->h_cc_id))
		  {
					 APL_DATA_MISSING("CC ID",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		  */
		  

		  if (!strlen(p_mt_settlcal_struct_h->h_settl_type))
		  {
					 APL_DATA_MISSING("Settlement type",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }


		  if (!strlen(p_mt_settlcal_struct_h->h_settl_no))
		  {
					 APL_DATA_MISSING("Settlement number",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }


		  if (!strlen(p_mt_settlcal_struct_h->h_start_date))
		  {
					 APL_DATA_MISSING("start date",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }

		  if (!strlen(p_mt_settlcal_struct_h->h_end_date))
		  {
					 APL_DATA_MISSING("end date",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		  /* chngs by amish --01/05--deadline dt made non mandatory in front end */
        /*
		  if (!strlen(p_mt_settlcal_struct_h->h_nsdl_deadline_dt))
		  {
					 APL_DATA_MISSING("nsdl deadline dt",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		  */

		  /*if (!strlen(p_mt_settlcal_struct_h->h_nsdl_deadline_tm))
		  {
					 APL_DATA_MISSING("nsdl_deadline_tm",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		  */

		  if (!strlen(p_mt_settlcal_struct_h->h_pay_in_dt))
		  {
					 APL_DATA_MISSING("pay_in_dt",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }

		  if (!strlen(p_mt_settlcal_struct_h->h_pay_out_dt))
		  {
					 APL_DATA_MISSING("pay_out_dt",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }

		  /*if (!strlen(p_mt_settlcal_struct_h->h_auction_dt))
		  {
					 APL_DATA_MISSING("auction_dt",APL_NULL_STRING,APL_NULL_STRING);
					 int_error_flag = APL_FAILURE;
		  }
		  */

		  if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
		  {
					 APL_IF_DEBUG
					 {

								CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of MT_ModSetCal.Going for updation\n",
													 NULL,p_intl_envdatastruct_h);
					 }

					 MT_UpdSetlCalFn(p_mt_settlcal_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);

					 if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
					 {
								APL_GOBACK_FAIL
					 }
		  }
		  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_MODIFY))
		  {
					 APL_IF_DEBUG
					 {
								CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of MT_ModSetCal.Going for updation after validating settlementdetails\n",NULL,p_intl_envdatastruct_h);
					 }

					 if (APL_SUCCESS == ChkStlmentCal(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
					 {
								MT_UpdSetlCalFn(p_mt_settlcal_struct_h ,p_intl_envdatastruct_h ,l_debug_info_ptr);
								if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
								{
										  APL_GOBACK_FAIL
								}
					 }
					 else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
					 { 
								APL_GOBACK_FAIL
					 }
		  }    
		  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE))
		  {
					 APL_IF_DEBUG
					 {
								CO_ProcMonitor(APL_OUT_FILE, "Entered Authorise h_mode of MT_ModSetCal.Going for updation after validating settlement calendar\n",NULL,p_intl_envdatastruct_h);
					 }

					 if (APL_SUCCESS == ChkStlmentCal(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
					 {
                              /* Retro with HDFC to add Settl Type in Query - Rahul - 01-Apr-2007 */
								if (APL_SUCCESS ==  MTValSetlCalFn(p_mt_settlcal_struct_h->h_settl_no,p_mt_settlcal_struct_h->h_exch_code,p_mt_settlcal_struct_h->h_settl_type,'Y','N',NULL,l_debug_info_ptr))
								{
										  if(APL_SUCCESS == MT_MkrChkr_Stlment(p_mt_settlcal_struct_h->h_settl_no,p_mt_settlcal_struct_h->h_exch_code,p_mt_settlcal_struct_h->h_settl_type,p_intl_envdatastruct_h->usr, l_debug_info_ptr))
										  {
													 MT_UpdSetlCalFn(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
													 if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
													 {
																APL_GOBACK_FAIL
													 }
										  }
										  else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
										  {
													 APL_GOBACK_FAIL
										  }
								}
								else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
								{
										  APL_GOBACK_FAIL
								}
					 }
					 else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
					 {
								APL_GOBACK_FAIL
					 }
		  }
		  else if(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))
		  {
					 APL_IF_DEBUG
					 {
								CO_ProcMonitor(APL_OUT_FILE, "Entered Reset h_mode of MT_ModSetCal.Going for updation after validating",NULL,p_intl_envdatastruct_h);
					 }
					 if (APL_SUCCESS == ChkStlmentCal(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
					 {
                              /* Retro with HDFC to add Settl Type in Query - Rahul - 01-Apr-2007 */
								if(APL_SUCCESS == MT_MkrChkr_Stlment(p_mt_settlcal_struct_h->h_settl_no,p_mt_settlcal_struct_h->h_exch_code,p_mt_settlcal_struct_h->h_settl_type,p_intl_envdatastruct_h->usr,l_debug_info_ptr))
								{
										  MT_UpdSetlCalFn(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
										  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
										  {
													 APL_GOBACK_FAIL
										  }
								}
								else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
								{
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
								CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of MT_ModSetCal.Going for updation after validating \n",NULL,p_intl_envdatastruct_h);
					 }

					 if (APL_SUCCESS == ChkStlmentCal(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr))
					 {
							  /* Retro with HDFC to add Settl Type in Query - Rahul - 01-Apr-2007 */
								if (APL_SUCCESS ==  MTValSetlCalFn(p_mt_settlcal_struct_h->h_settl_no,p_mt_settlcal_struct_h->h_exch_code,p_mt_settlcal_struct_h->h_settl_type,'Y',NULL,'N',l_debug_info_ptr))
								{
										  MT_UpdSetlCalFn(p_mt_settlcal_struct_h,p_intl_envdatastruct_h ,l_debug_info_ptr);
										  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
										  {
													 APL_GOBACK_FAIL
										  }
								}
								else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
								{
										  APL_GOBACK_FAIL
								}
					 }
					 else if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
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
										  CO_ProcMonitor(APL_OUT_FILE, "Success in MT_ModSetCal.Getting out!!\n",NULL,p_intl_envdatastruct_h);
										  return(APL_SUCCESS);
								}

RETURN_FAILURE :
		  {
					 CO_ProcMonitor(APL_OUT_FILE, "Failed in MT_ModSetCal. Getting out!!\n",NULL,p_intl_envdatastruct_h);
					 return(APL_FAILURE);
		  }

}              
