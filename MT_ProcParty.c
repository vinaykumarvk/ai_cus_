/************************************************************************************
 *    COPYRIGHT NOTICE                                                              *
 *                                                                                  *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.              *
 *                                                                                  *
 *   These materials are confidential and proprietary to                            *
 *    Polaris Software Lab Limited and no part of these materials should            *
 *    be reproduced, published, transmitted or distributed in any form or           *
 *    by any means, electronic, mechanical, photocopying, recording or              *
 *    otherwise, or stored in any information storage or retrieval system           *
 *    of any nature nor should the materials be disclosed to third parties          *
 *    or used in any other manner for which this is not authorized, without         *
 *    the prior express written authorization of Polaris Software Lab Limited.      *
 */
/************************************************************************************
 *
 * Module Name         :        Master Maintenance
 *
 * File Name           :        MT_ProcParty.c
 *
 * Description         :        This file contains functions for master and
 *                              child tables' records insertion and updation
 *                              in all modes business validations check functions.
 *
 *
 *                      Version Control Block
 *
 * Date        Version     Author               Description
 * ---------   --------  ---------------  ---------------------------------------------
 * 10-10-2005   1.0       S Pradeep       New file to validate Master and child tables
 * 27-01-2006	 1.1		  S.Pradeep			Added Some Changes in Base version.
 *************************************************************************************/

#define PURE_C_SOURCE

#include "CO_HostStructdef.h"

int MT_ModParty(	MT_PARTY_STRUCT_H *p_mt_party_struct_h,
						INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	/* Variable Decleration */
	int int_error_flag = APL_SUCCESS;

	char *l_key_codes[4];
	char *l_key_values[4];
	char *l_link_table_names[7];
	char chr_l_table_name[50] = APL_NULL_STRING;

	char chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	int int_retval = APL_SUCCESS;
	/* Debug Statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/* Mandatory Data Missing Checks - Generic */

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]="PTY_NAME";
	l_key_codes[2]="PTY_TYPE";
	l_key_codes[3]=APL_NULL_STRING;

	l_key_values[0]=p_mt_party_struct_h->h_pty_code;
	l_key_values[1]=p_mt_party_struct_h->h_pty_name;
	l_key_values[2]=p_mt_party_struct_h->h_pty_type;
	l_key_values[3]=APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
												l_key_values,
												3,
												l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (strcmp(p_mt_party_struct_h->h_pty_pan,APL_NULL_STRING))
	{
		if (!strlen(p_mt_party_struct_h->h_pty_pan))
		{
			if (CO_InsertErr(l_debug_info_ptr,ERR_PAN_LENGTH,"Party Main Details Table",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__) != APL_SUCCESS)
				APL_GOBACK_FAIL
					int_error_flag = APL_FAILURE;
		}
	}

	int_retval = CO_Chk_CodeValid("PARTYTYPE",
											p_mt_party_struct_h->h_pty_type,
											"IN",
											l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}


	if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}
	/* Setting Values for Mode Specific Checks   */
	strcpy(chr_l_table_name,"MT_PARTY");
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

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]=APL_NULL_STRING;

	l_key_values[0]=p_mt_party_struct_h->h_pty_code;
	l_key_values[1]=APL_NULL_STRING;

	int_retval = CO_Chk_ChldValid(   l_key_codes,
												l_key_values,
												chr_l_rec_iexist,
												chr_l_rec_iauthorized,
												chr_l_rec_ideleted,
												APL_NULL_CHAR,
												APL_NULL_CHAR,
												APL_NULL_CHAR,
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
			MT_ModDBParty(p_mt_party_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

		if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr))
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
			MT_ModDBParty(p_mt_party_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

		if (APL_SUCCESS == MT_Chk_PtyVal(	p_mt_party_struct_h->h_pty_code,
														p_mt_party_struct_h->h_pty_type,
														'Y',
														NULL,
														'N',
														l_debug_info_ptr))
		{
			/******** Following code checks for presence of records in other tables...... ********/
			l_key_codes[0]="PTY_CODE";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;

			l_link_table_names[0]="MT_PTY_EXCH_MAP";
			l_link_table_names[1]="MT_PTY_DEPO_MAP";
			l_link_table_names[2]="MT_PTY_EXCH_CLN_MAP";
			l_link_table_names[3]=APL_NULL_STRING;

			int_retval = CR_Chk_CodeInChld(  l_key_codes,
														l_key_values,
														l_link_table_names,
														p_intl_env_data_struct_h,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
			{
				CO_InsertErr(  l_debug_info_ptr,
									ERR_PARTY_CANT_DEL,
									"Mapping Exists",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL
/********** Check in DL_Deal table : Domcpac ***********/
			l_key_codes[0]="DOMESTIC_CPCLT";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;
			l_link_table_names[0]="DL_DEAL";
			l_link_table_names[1]=APL_NULL_STRING;

			int_retval = CR_Chk_CodeInChld(  l_key_codes,
														l_key_values,
														l_link_table_names,
														p_intl_env_data_struct_h,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
			{
				CO_InsertErr(  l_debug_info_ptr,
									ERR_PARTY_CANT_DEL,
									"DEAL:Domestic CP",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL

/********** Check in DL_Deal table : Counterparty ***********/
			l_key_codes[0]="CP_CLT";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;
			l_link_table_names[0]="DL_DEAL";
			l_link_table_names[1]=APL_NULL_STRING;

			int_retval = CR_Chk_CodeInChld(  l_key_codes,
														l_key_values,
														l_link_table_names,
														p_intl_env_data_struct_h,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
			{
				CO_InsertErr(  l_debug_info_ptr,
									ERR_PARTY_CANT_DEL,
									"DEAL:Counter Party",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL

/********** Check in DL_BCN table : Broker ***********/
			l_key_codes[0]="BROKER_CD";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;
			l_link_table_names[0]="DL_BCN";
			l_link_table_names[1]=APL_NULL_STRING;

			int_retval = CR_Chk_CodeInChld(  l_key_codes,
														l_key_values,
														l_link_table_names,
														p_intl_env_data_struct_h,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
			{
				CO_InsertErr(  l_debug_info_ptr,
									ERR_PARTY_CANT_DEL,
									"BCN:Broker Code",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__);
			}
			else if (int_retval == APL_FAILURE)
				APL_GOBACK_FAIL

				MT_ModDBParty(p_mt_party_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
		}
		else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

		if (APL_SUCCESS == MT_Chk_PtyVal(p_mt_party_struct_h->h_pty_code,
													p_mt_party_struct_h->h_pty_type,
													'Y',
													'N',
													NULL,
													l_debug_info_ptr))
		{
			l_key_codes[0]="PTY_CODE";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;

			int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
														l_key_values,
														chr_l_table_name,
														p_intl_env_data_struct_h->usr,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
				APL_GOBACK_FAIL

			MT_ModDBParty(p_mt_party_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
		}

		else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}
	else if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorize mode ... \n",NULL,p_intl_env_data_struct_h);
		}

		if (APL_SUCCESS == MT_Chk_PtyVal(p_mt_party_struct_h->h_pty_code,
													p_mt_party_struct_h->h_pty_type,
													'Y',
													'N',
													NULL,
													l_debug_info_ptr))
		{
			l_key_codes[0]="PTY_CODE";
			l_key_codes[1]=APL_NULL_STRING;

			l_key_values[0]=p_mt_party_struct_h->h_pty_code;
			l_key_values[1]=APL_NULL_STRING;

			int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
														l_key_values,
														chr_l_table_name,
														p_intl_env_data_struct_h->usr,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
				APL_GOBACK_FAIL

			MT_ModDBParty(p_mt_party_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);
		}

		else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
	}
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}
	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:
	{
		APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)
			//return(APL_SUCCESS);Commented for AIX migration Chnages
	}
	RETURN_FAILURE:
	{
		APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
			//return(APL_FAILURE);Commented for AIX migration Chnages
	}
}

int MT_ModPtyExchMap(MT_PTY_EXCH_MAP_STRUCT_H   *p_mt_pty_exch_map_struct_h,
							INTL_ENV_DATA_STRUCT_H     *p_intl_env_data_struct_h,
							DEBUG_INFO_STRUCT_H        **l_debug_info_ptr)
{
	/* Variable Declerations */
	int   int_error_flag;

	char  *l_key_codes[4];
	char  *l_key_values[4];
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	int   int_retval = APL_SUCCESS;

	/* Debug Statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/* Mandatory Data Missing Checks - Generic */

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]="EXCH_CODE";
	l_key_codes[2]="PTY_EXCH_MAP_CODE";
	l_key_codes[3]=APL_NULL_STRING;

	l_key_values[0]=p_mt_pty_exch_map_struct_h->h_pty_code;
	l_key_values[1]=p_mt_pty_exch_map_struct_h->h_exch_code;
	l_key_values[2]=p_mt_pty_exch_map_struct_h->h_pty_exch_map_code;
	l_key_values[3]=APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
												l_key_values,
												3,
												l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	int_retval = CO_Chk_CodeValid("EXCHANGE",
											p_mt_pty_exch_map_struct_h->h_exch_code,
											"IN",
											l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	/* Setting Values for Mode Specific Checks   */
	strcpy(chr_l_table_name,"MT_PTY_EXCH_MAP");
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

		l_key_codes[0]="PTY_CODE";
		l_key_codes[1]="EXCH_CODE";
		l_key_codes[2]="PTY_EXCH_MAP_CODE";
		l_key_codes[3]=APL_NULL_STRING;

		l_key_values[0]=p_mt_pty_exch_map_struct_h->h_pty_code;
		l_key_values[1]=p_mt_pty_exch_map_struct_h->h_exch_code;
		l_key_values[2]=p_mt_pty_exch_map_struct_h->h_pty_exch_map_code;
		l_key_values[3]=APL_NULL_STRING;

		int_retval = CO_Chk_ChldValid(l_key_codes,
												l_key_values,
												chr_l_rec_iexist,
												chr_l_rec_iauthorized,
												chr_l_rec_ideleted,
												NULL,
												NULL,
												NULL,
												chr_l_table_name,
												l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
			}

				MT_ModDBPtyExchMap(p_mt_pty_exch_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

				MT_ModDBPtyExchMap(p_mt_pty_exch_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

				MT_ModDBPtyExchMap(p_mt_pty_exch_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
		}
		else if((!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) ||
		(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
			}

				l_key_codes[0]="PTY_CODE";
				l_key_codes[1]="EXCH_CODE";
				l_key_codes[2]="PTY_EXCH_MAP_CODE";
				l_key_codes[3]=APL_NULL_STRING;

				l_key_values[0]=p_mt_pty_exch_map_struct_h->h_pty_code;
				l_key_values[1]=p_mt_pty_exch_map_struct_h->h_exch_code;
				l_key_values[2]=p_mt_pty_exch_map_struct_h->h_pty_exch_map_code;
				l_key_values[3]=APL_NULL_STRING;

				int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
															l_key_values,
															chr_l_table_name,
															p_intl_env_data_struct_h->usr,
															l_debug_info_ptr);
				if (int_retval != APL_SUCCESS)
					APL_GOBACK_FAIL

						MT_ModDBPtyExchMap(p_mt_pty_exch_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
		}
		/*(
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
			}

			if (APL_SUCCESS == MT_Chk_PtyExchMapVal(  p_mt_pty_exch_map_struct_h->h_pty_code,
																p_mt_pty_exch_map_struct_h->h_exch_code,
																p_mt_pty_exch_map_struct_h->h_pty_exch_map_code,
																'Y',
																NULL,
																'N',
																l_debug_info_ptr))
			{
				l_key_codes[0]="PTY_CODE";
				l_key_codes[1]="EXCH_CODE";
				l_key_codes[2]="PTY_EXCH_MAP_CODE";
				l_key_codes[3]=APL_NULL_STRING;

				l_key_values[0]=p_mt_pty_exch_map_struct_h->h_pty_code;
				l_key_values[1]=p_mt_pty_exch_map_struct_h->h_exch_code;
				l_key_values[2]=p_mt_pty_exch_map_struct_h->h_pty_exch_map_code;
				l_key_values[3]=APL_NULL_STRING;

				int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
															l_key_values,
															chr_l_table_name,
															p_intl_env_data_struct_h->usr,
															l_debug_info_ptr);
				if (int_retval != APL_SUCCESS)
					APL_GOBACK_FAIL

				MT_ModDBPtyExchMap(p_mt_pty_exch_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
			}
			else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		}
		*/
		else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		{
			APL_GOBACK_FAIL
		}
		APL_GOBACK_SUCCESS

		RETURN_SUCCESS :
		{
			APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE);
				//return(APL_SUCCESS);Commented for AIX migration Chnages
		}
		RETURN_FAILURE :
      {
			APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
				//return(APL_FAILURE);Commented for AIX migration Chnages
		}
}

int MT_ModPtyDepoMap(MT_PTY_DEPO_MAP_STRUCT_H   *p_mt_pty_depo_map_struct_h,
							INTL_ENV_DATA_STRUCT_H     *p_intl_env_data_struct_h,
							DEBUG_INFO_STRUCT_H        **l_debug_info_ptr)
{
	/* Variable Declerations */
	int   int_error_flag;

	char  *l_key_codes[4];
	char  *l_key_values[4];
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist,chr_l_rec_ideleted,chr_l_rec_iauthorized;
	int   int_retval = APL_SUCCESS;

	/* Debug Statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/* Mandatory Data Missing Checks - Generic */

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]="DEPO_CODE";
	/*l_key_codes[2]="PTY_DEPO_MAP_CLIENT_ID";  --Rahul */
	l_key_codes[2]="CMBP_ID";
	l_key_codes[3]=APL_NULL_STRING;

	l_key_values[0]=p_mt_pty_depo_map_struct_h->h_pty_code;
	l_key_values[1]=p_mt_pty_depo_map_struct_h->h_depo_code;
	/*l_key_values[2]=p_mt_pty_depo_map_struct_h->h_pty_depo_map_client_id;--Rahul */
	l_key_values[2]=p_mt_pty_depo_map_struct_h->h_cmbp_id;
	l_key_values[3]=APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
												l_key_values,
												3,
												l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	int_retval = CO_Chk_CodeValid("DEPOSITORY",
											p_mt_pty_depo_map_struct_h->h_depo_code,
											"IN",
											l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	/* Setting Values for Mode Specific Checks   */
	strcpy(chr_l_table_name,"MT_PTY_DEPO_MAP");
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

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]="DEPO_CODE";
	/*l_key_codes[2]="PTY_DEPO_MAP_CLIENT_ID";  --Rahul*/
	l_key_codes[2]="CMBP_ID";	
	l_key_codes[3]=APL_NULL_STRING;

	l_key_values[0]=p_mt_pty_depo_map_struct_h->h_pty_code;
	l_key_values[1]=p_mt_pty_depo_map_struct_h->h_depo_code;
	/*l_key_values[2]=p_mt_pty_depo_map_struct_h->h_pty_depo_map_client_id;  --Rahul*/
	l_key_values[2]=p_mt_pty_depo_map_struct_h->h_cmbp_id;	
	l_key_values[3]=APL_NULL_STRING;

	int_retval = CO_Chk_ChldValid(l_key_codes,
											l_key_values,
											chr_l_rec_iexist,
											chr_l_rec_iauthorized,
											chr_l_rec_ideleted,
											NULL,
											NULL,
											NULL,
											chr_l_table_name,
											l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
		}

		MT_ModDBPtyDepoMap(p_mt_pty_depo_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

		MT_ModDBPtyDepoMap(p_mt_pty_depo_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

		if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

			MT_ModDBPtyDepoMap(p_mt_pty_depo_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
		}

			l_key_codes[0]="PTY_CODE";
			l_key_codes[1]="DEPO_CODE";
			/*l_key_codes[2]="PTY_DEPO_MAP_CLIENT_ID";  - Rahul*/
			l_key_codes[2]="CMBP_ID";	
			l_key_codes[3]=APL_NULL_STRING;

			l_key_values[0]=p_mt_pty_depo_map_struct_h->h_pty_code;
			l_key_values[1]=p_mt_pty_depo_map_struct_h->h_depo_code;
			/*l_key_values[2]=p_mt_pty_depo_map_struct_h->h_pty_depo_map_client_id;*/
			l_key_values[2]=p_mt_pty_depo_map_struct_h->h_cmbp_id;
			l_key_values[3]=APL_NULL_STRING;

			int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
														l_key_values,
														chr_l_table_name,
														p_intl_env_data_struct_h->usr,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
				APL_GOBACK_FAIL

			MT_ModDBPtyDepoMap(p_mt_pty_depo_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}
	else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
		}

			l_key_codes[0]="PTY_CODE";
			l_key_codes[1]="DEPO_CODE";
			/*l_key_codes[2]="PTY_DEPO_MAP_CLIENT_ID";*/
			l_key_codes[2]="CMBP_ID";
			l_key_codes[3]=APL_NULL_STRING;

			l_key_values[0]=p_mt_pty_depo_map_struct_h->h_pty_code;
			l_key_values[1]=p_mt_pty_depo_map_struct_h->h_depo_code;
			/*l_key_values[2]=p_mt_pty_depo_map_struct_h->h_pty_depo_map_client_id;  --Rahul*/
			l_key_values[2]=p_mt_pty_depo_map_struct_h->h_cmbp_id;
			l_key_values[3]=APL_NULL_STRING;

			int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
														l_key_values,
														chr_l_table_name,
														p_intl_env_data_struct_h->usr,
														l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
				APL_GOBACK_FAIL

			MT_ModDBPtyDepoMap(p_mt_pty_depo_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

			if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}
	else if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}
	APL_GOBACK_SUCCESS
		RETURN_SUCCESS :
		{
			APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE);
			return(APL_SUCCESS);
		}
		RETURN_FAILURE :
		{
			APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
			return(APL_FAILURE);
		}
}

int MT_ModPtyExchClnMap(MT_PTY_EXCH_CLN_MAP_STRUCT_H  *p_mt_pty_exch_cln_map_struct_h,
							INTL_ENV_DATA_STRUCT_H        *p_intl_env_data_struct_h,
							DEBUG_INFO_STRUCT_H           **l_debug_info_ptr)
{
	/* Variable Declerations */
	int   int_error_flag;

	char  *l_key_codes[5];
	char  *l_key_values[5];
	char  chr_l_table_name[50];

	char  chr_l_rec_iexist='Y';
	char	chr_l_rec_ideleted='N';
	char	chr_l_rec_iauthorized='Y';
	int   int_retval = APL_SUCCESS;

	/* Debug Statements */

	APL_FUNCTION_ENTER(APL_OUT_FILE)

	/* Mandatory Data Missing Checks - Generic */

	l_key_codes[0]="PTY_CODE";
	l_key_codes[1]="EXCH_CODE";
	l_key_codes[2]="CLN_CODE";
	l_key_codes[3]="PTY_EXCH_CLN_MAP_CODE";
	l_key_codes[4]=APL_NULL_STRING;

	l_key_values[0]=p_mt_pty_exch_cln_map_struct_h->h_pty_code;
	l_key_values[1]=p_mt_pty_exch_cln_map_struct_h->h_exch_code;
	l_key_values[2]=p_mt_pty_exch_cln_map_struct_h->h_cln_code;
	l_key_values[3]=p_mt_pty_exch_cln_map_struct_h->h_pty_exch_cln_map_code;
	l_key_values[4]=APL_NULL_STRING;

	int_retval = CR_Chk_AllMandData( l_key_codes,
												l_key_values,
												4,
												l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	int_retval = CO_Chk_CodeValid("EXCHANGE",
											p_mt_pty_exch_cln_map_struct_h->h_exch_code,
											"IN",
											l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	l_key_codes[0]="CLN_CODE";
	l_key_codes[1]=APL_NULL_STRING;

	l_key_values[0]=p_mt_pty_exch_cln_map_struct_h->h_cln_code;
	l_key_values[1]=APL_NULL_STRING;

	strcpy(chr_l_table_name,"MT_CLIENT");

	int_retval = CO_Chk_ChldValid(l_key_codes,
											l_key_values,
											chr_l_rec_iexist,
											chr_l_rec_iauthorized,
											chr_l_rec_ideleted,
											NULL,
											NULL,
											NULL,
											chr_l_table_name,
											l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
	{
		APL_GOBACK_FAIL
	}

	/* Setting Values for Mode Specific Checks   */
	strcpy(chr_l_table_name,APL_NULL_STRING);
	strcpy(chr_l_table_name,"MT_PTY_EXCH_CLN_MAP");
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
		l_key_codes[0]="PTY_CODE";
		l_key_codes[1]="EXCH_CODE";
		l_key_codes[2]="CLN_CODE";
		l_key_codes[3]="PTY_EXCH_CLN_MAP_CODE";
		l_key_codes[4]=APL_NULL_STRING;

		l_key_values[0]=p_mt_pty_exch_cln_map_struct_h->h_pty_code;
		l_key_values[1]=p_mt_pty_exch_cln_map_struct_h->h_exch_code;
		l_key_values[2]=p_mt_pty_exch_cln_map_struct_h->h_cln_code;
		l_key_values[3]=p_mt_pty_exch_cln_map_struct_h->h_pty_exch_cln_map_code;
		l_key_values[4]=APL_NULL_STRING;

		int_retval = CO_Chk_ChldValid(l_key_codes,
												l_key_values,
												chr_l_rec_iexist,
												chr_l_rec_iauthorized,
												chr_l_rec_ideleted,
												NULL,
												NULL,
												NULL,
												chr_l_table_name,
												l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
			APL_GOBACK_FAIL

		if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered input mode ... \n",NULL,p_intl_env_data_struct_h);
			}

				MT_ModDBPtyExchClnMap(p_mt_pty_exch_cln_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

				MT_ModDBPtyExchClnMap(p_mt_pty_exch_cln_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
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

				MT_ModDBPtyExchClnMap(p_mt_pty_exch_cln_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
		}
		else if(	(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_AUTHORISE)) ||
					(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET)))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
			}

				l_key_codes[0]="PTY_CODE";
				l_key_codes[1]="EXCH_CODE";
				l_key_codes[2]="CLN_CODE";
				l_key_codes[3]="PTY_EXCH_CLN_MAP_CODE";
				l_key_codes[4]=APL_NULL_STRING;

				l_key_values[0]=p_mt_pty_exch_cln_map_struct_h->h_pty_code;
				l_key_values[1]=p_mt_pty_exch_cln_map_struct_h->h_exch_code;
				l_key_values[2]=p_mt_pty_exch_cln_map_struct_h->h_cln_code;
				l_key_values[3]=p_mt_pty_exch_cln_map_struct_h->h_pty_exch_cln_map_code;
				l_key_values[4]=APL_NULL_STRING;

				int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
															l_key_values,
															chr_l_table_name,
															p_intl_env_data_struct_h->usr,
															l_debug_info_ptr);
				if (int_retval != APL_SUCCESS)
					APL_GOBACK_FAIL

				MT_ModDBPtyExchClnMap(p_mt_pty_exch_cln_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
		}
		/*
		else if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_RESET))
		{
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Entered authorise mode ... \n",NULL,p_intl_env_data_struct_h);
			}

				l_key_codes[0]="PTY_CODE";
				l_key_codes[1]="EXCH_CODE";
				l_key_codes[2]="CLN_CODE";
				l_key_codes[3]="PTY_EXCH_CLN_MAP_CODE";
				l_key_codes[4]=APL_NULL_STRING;

				l_key_values[0]=p_mt_pty_exch_cln_map_struct_h->h_pty_code;
				l_key_values[1]=p_mt_pty_exch_cln_map_struct_h->h_exch_code;
				l_key_values[2]=p_mt_pty_exch_cln_map_struct_h->h_cln_code;
				l_key_values[3]=p_mt_pty_exch_cln_map_struct_h->h_pty_exch_cln_map_code;
				l_key_values[4]=APL_NULL_STRING;

				int_retval = CR_Chk_ChldMkrChkr( l_key_codes,
															l_key_values,
															chr_l_table_name,
															p_intl_env_data_struct_h->usr,
															l_debug_info_ptr);
				if (int_retval != APL_SUCCESS)
					APL_GOBACK_FAIL

				MT_ModDBPtyExchClnMap(p_mt_pty_exch_cln_map_struct_h,p_intl_env_data_struct_h,l_debug_info_ptr);

				if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
				{
					APL_GOBACK_FAIL
				}
		}
		*/
		APL_GOBACK_SUCCESS

		RETURN_SUCCESS :
		{
			APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE);
				return(APL_SUCCESS);
		}
		RETURN_FAILURE :
		{
			APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
				return(APL_FAILURE);
		}
}


