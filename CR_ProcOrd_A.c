





#define  PURE_C_SOURCE
#include "CO_HostStructdef.h"
#include "CO_Externdef.h"


int CR_Rtv_OrdRefNo(	char	*chr_p_client,
							char	*p_orderident,
							DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	

	char	chr_l_buf[BUFFER_LEN]				= APL_NULL_STRING;

   int   int_l_count                    = 0;
   int   int_l_seqnum_a                   = 0;
   char  chr_l_final_orderrefno[16]     = APL_NULL_STRING;

	PRO_GSEQNUM_STRUCT_H *l_progseqnum_struct_h	= NULL;

	

	l_progseqnum_struct_h = (PRO_GSEQNUM_STRUCT_H *)calloc(1, sizeof(PRO_GSEQNUM_STRUCT_H));
	APL_MALLOC_FAIL(l_progseqnum_struct_h);

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE, "Entered processtion CBGenOrdRefNoFn", NULL, NULL);
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(chr_l_buf, "Account is : %s", chr_p_client);
		CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);
	}

	

	if (!strlen(chr_p_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		APL_GOBACK_FAIL
	}

	

	memset(l_progseqnum_struct_h, NULL, sizeof(PRO_GSEQNUM_STRUCT_H));
	strcpy(l_progseqnum_struct_h->sequencename, ORDER_REFNO_SEQNAME);
	l_progseqnum_struct_h->last_seqnum = 9999;

	 
   l_progseqnum_struct_h->recycle_ind = RECYCLE_EOD;

	int_l_seqnum_a = CO_RtvNxtSeqNum(	l_progseqnum_struct_h, l_debug_info_ptr );

	if (APL_FAILURE == int_l_seqnum_a)
	{
		APL_GOBACK_FAIL
	}
	if ( APL_FAILURE == CR_Proc_OrdRefNoFrmt( int_l_seqnum_a,chr_l_final_orderrefno,l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL
	}
	if ( APL_FAILURE == CR_Rtv_OrdCnt(&int_l_count,
												chr_p_client,
												chr_l_final_orderrefno,
												l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL
	}
	if ( int_l_count != 0 )
	{
		int_l_seqnum_a = CO_RtvNxtSeqNum(    l_progseqnum_struct_h, l_debug_info_ptr );
			if (APL_FAILURE == int_l_seqnum_a)
			{
				APL_GOBACK_FAIL
			}
			if ( APL_FAILURE == CR_Proc_OrdRefNoFrmt( int_l_seqnum_a,chr_l_final_orderrefno,l_debug_info_ptr ) )
			{
				APL_GOBACK_FAIL
			}
	}
	strcpy( p_orderident,chr_l_final_orderrefno);

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Leaving Function CR_Rtv_OrdRefNo with success", NULL, NULL);
		}
      return(APL_SUCCESS);

   RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Leaving Function CR_Rtv_OrdRefNo with errors", NULL, NULL);
		}
      return(APL_FAILURE);
}



int CR_Mod_Ord(	OR_ORDERDETAILS_STRUCT_H *p_or_orderdetails_struct_h_b,
						char *p_orderident,
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{

	

	char 		chr_l_buf[BUFFER_LEN] 						= APL_NULL_STRING;
	char		chr_l_access_stamp[APL_DATE_LEN]		= APL_NULL_STRING;
	char		chr_l_rowid_A[APL_ROWID_LEN]				= APL_NULL_STRING;
	char		chr_l_ord_status[APL_STATUS_LEN]		= APL_NULL_STRING;
	char		chr_l_instr_locncode[APL_LOCNCODE_LENGTH]	= APL_NULL_STRING;
	char		chr_l_maker[APL_USERID_LEN]				= APL_NULL_STRING;
	char  	chr_l_typeofinstr[TYPEOF_INSTR_LEN]			= APL_NULL_STRING;
	double	l_minfmttrdquantity							= 0;

	short		l_iflag							= 0;

	int		int_l_flag							= 0;
	int 		int_l_error_flag 					= APL_SUCCESS;

	double	l_availquantity						= 0.0;
	double	l_quantitytoupd						= 0.0;
	double	l_oldquantity							= 0.0;
	double	l_oldlmtprc						= 0.0;
	double	dbl_l_brkgcomm						= 0.0;

	DL_DEALAUDIT_STRUCT_H	 *l_dl_dealaudit_struct_h = NULL;

	

	l_dl_dealaudit_struct_h = (DL_DEALAUDIT_STRUCT_H *)calloc(1, sizeof(DL_DEALAUDIT_STRUCT_H));
	APL_MALLOC_FAIL(l_dl_dealaudit_struct_h);

	

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE, 
						"Entered Function CR_Mod_Ord\n",
						NULL,
						p_intl_envdatastruct_h);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Account is : %s\n", 
						p_or_orderdetails_struct_h_b->h_dl_client);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						p_intl_envdatastruct_h);
		memset( chr_l_buf, NULL, BUFFER_LEN );
                /*Added %s for AIX Migration*/
		sprintf(		chr_l_buf, 
						"The Instrurity is : %s\n", 
						p_or_orderdetails_struct_h_b->h_instr_code);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						p_intl_envdatastruct_h);
	}
	
	

	if (!strlen(p_or_orderdetails_struct_h_b->h_dl_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	if ((strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT)) && 
		 (!strlen(p_or_orderdetails_struct_h_b->h_orderindentity_no)))
	{
		APL_DATA_MISSING("Order Refno", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_buy_sell_flag))
	{
		APL_DATA_MISSING("Buy/Sell Flag", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_orderdate))
	{
		APL_DATA_MISSING("Order Date", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!p_or_orderdetails_struct_h_b->h_orderquantity)
	{
		APL_DATA_MISSING("Order Qty", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_limit_ind))
	{
		APL_DATA_MISSING("IsLimit Flag", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_isgte_ind))
	{
		APL_DATA_MISSING("IsGTE flag", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_all_none_ind))
	{
		APL_DATA_MISSING("IsAllOrNone flag", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_ex_arena))
	{
		APL_DATA_MISSING("Ex. Arena", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 
	if (!strlen(p_or_orderdetails_struct_h_b->h_instr_code))
	{
		APL_DATA_MISSING("Instrode", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	if ((p_or_orderdetails_struct_h_b->h_limit_ind[0] == 'Y') &&
		 (p_or_orderdetails_struct_h_b->h_limitpr <= 0))
	{
		APL_DATA_MISSING("Limit Price", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	if ((p_or_orderdetails_struct_h_b->h_isgte_ind[0] == 'Y') &&
		 (!strlen(p_or_orderdetails_struct_h_b->h_expirydate)))
	{
		APL_DATA_MISSING("Expiry Dt.", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 

	

	l_iflag = 0;
	if (APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_MAINT",
														"LR_TYPOFTRD_MANDY",
														&l_iflag,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if ((l_iflag) && (!strlen(p_or_orderdetails_struct_h_b->h_lrdltype)))
	{
		APL_DATA_MISSING("LR TypeofTrd", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	}

	

	l_iflag = 0;
	if (APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_MAINT",
														"BROK_CODE_MANDY",
														&l_iflag,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if ((l_iflag) && (!strlen(p_or_orderdetails_struct_h_b->h_broker_cd)))
	{
		APL_DATA_MISSING("Broker Code", APL_NULL_STRING, APL_NULL_STRING);
		int_l_error_flag = APL_FAILURE;
	} 


	if (APL_FAILURE == int_l_error_flag) APL_GOBACK_FAIL

	

	

	if (strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT))
	{
		if (APL_FAILURE == CR_Rtv_OrdChrVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"rowid",
														(char *)&chr_l_rowid_A,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (APL_FAILURE == CR_Rtv_OrdChrVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"access_stamp",
														(char *)&chr_l_access_stamp,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (strcmp(chr_l_access_stamp, p_or_orderdetails_struct_h_b->h_access_stamp))
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_ACCESSSTAMP_CHGD,
									APL_NULL_STRING,
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
		}
	}

	

	if (APL_FAILURE == CO_Chk_AccValid(	p_or_orderdetails_struct_h_b->h_dl_client,
												'Y',
												'C',
												'B',
												NULL,
												'Y',
												'N',
												'N',
												'N',
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (strlen(p_or_orderdetails_struct_h_b->h_broker_cd))
	{
		if (APL_FAILURE == CO_Chk_AccValid(	p_or_orderdetails_struct_h_b->h_broker_cd,
													'Y',
													'B',
													NULL,
													NULL,
													'Y',
													'N',
													'N',
													'N',
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	

	if (APL_FAILURE == CO_Chk_InstrValid(	p_or_orderdetails_struct_h_b->h_instr_code,
												'Y',
												'Y',
												'N',
												'N',
												NULL,
												'N',
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if (APL_FAILURE == CR_Rtv_InstrChrVal(	p_or_orderdetails_struct_h_b->h_instr_code,
													"typeofinstr",
													chr_l_typeofinstr,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (!strcmp(chr_l_typeofinstr, "FMT"))
	{
		if (APL_FAILURE == CR_Rtv_InstrNumVal(	p_or_orderdetails_struct_h_b->h_instr_code,
														"minfmttrdqty",
														&l_minfmttrdquantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (p_or_orderdetails_struct_h_b->h_orderquantity < l_minfmttrdquantity)
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_QTY_CANT_LESS_MINFINQTY,
									p_or_orderdetails_struct_h_b->h_dl_client,
									p_or_orderdetails_struct_h_b->h_instr_code,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
		}
	}

	

	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT)) ||
		 (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY)))
	{
		if (APL_FAILURE == CO_Chk_Holiday(	p_or_orderdetails_struct_h_b->h_orderdate,
															&int_l_flag,
															l_debug_info_ptr,APL_NULL_STRING ))
		{
			APL_GOBACK_FAIL
		}

		if (int_l_flag)
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_DATE_IS_HOLIDAY,
									"Order Date",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
		}
	}

	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE)) ||
		 (!strcmp(p_intl_envdatastruct_h->h_mode, CANCEL_MODE)))
	{
		if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
													p_or_orderdetails_struct_h_b->h_orderindentity_no,
													'Y',
													NULL,
													'N',
													'N',
													'N',
													NULL,
													'N',
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY))
	{
		if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
													p_or_orderdetails_struct_h_b->h_orderindentity_no,
													'Y',
													NULL,
													'N',
													'N',
													'N',
													NULL,
													'N',
													l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE))
	{
		
		
		if (APL_FAILURE == CR_Rtv_OrdChrVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"order_status",
														chr_l_ord_status,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		

		if (!strcmp(chr_l_ord_status, STATUS_UAUTH))
		{
			if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														'Y',
														'N',
														'N',
														'N',
														'N',
														NULL,
														'N',
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
		}

		

		else if (!strcmp(chr_l_ord_status, STATUS_DEL_UAUTH))
		{
			if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														'Y',
														'N',
														'Y',
														'N',
														'N',
														NULL,
														'N',
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
		}

		

		else if (!strcmp(chr_l_ord_status, STATUS_CANC_UAUTH))
		{
			if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														'Y',
														'N',
														'N',
														'Y',
														'N',
														NULL,
														'N',
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
		}
		else 
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_DATA_INTEGRITY,
									"Improper Status",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
		}
	}

	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET))
	{
		
		
		if (APL_FAILURE == CR_Rtv_OrdChrVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"order_status",
														chr_l_ord_status,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		

		if (!strcmp(chr_l_ord_status, STATUS_DEL_UAUTH))
		{
			if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														'Y',
														'N',
														'Y',
														NULL,
														'N',
														NULL,
														NULL,
														l_debug_info_ptr ))
			{	
				APL_GOBACK_FAIL
			}
		}										

		

		else if (!strcmp(chr_l_ord_status, STATUS_CANC_UAUTH))
		{
			if (APL_FAILURE == CR_Chk_Ord(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														'Y',
														'N',
														NULL,
														'Y',
														'N',
														NULL,
														NULL,
														l_debug_info_ptr ))
			{	
				APL_GOBACK_FAIL
			}
		}										
		else 
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_DATA_INTEGRITY,
									"Improper Status",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL
		}
	}

	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT)) ||
		 (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY)) ||
		 (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET)))
	{
		

		if (p_or_orderdetails_struct_h_b->h_buy_sell_flag[0] == BUY_ORD)
		{
			l_iflag = 0;
			if (APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_MAINT",
																"ACCBAL_CHK_FOR_BUY",
																&l_iflag,
																l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}

			if (l_iflag)
			{
				l_iflag = 0;
				if (APL_FAILURE == CR_Chk_CustCashBal(	p_or_orderdetails_struct_h_b->h_dl_client,
																&p_or_orderdetails_struct_h_b->h_orderquantity,
																&p_or_orderdetails_struct_h_b->h_limitpr,
																&l_iflag,
																l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}

				if (l_iflag == APL_FAILURE)
				{
					CO_InsertErr(	l_debug_info_ptr,
											ERR_ORD_INSUFF_CASHBAL_CANT_RESET,
											p_or_orderdetails_struct_h_b->h_dl_client,
											APL_NULL_STRING,
											APL_NULL_STRING,
											__LINE__,
											__FILE__ );
					APL_GOBACK_FAIL

				}
			}
		}

		

		if (p_or_orderdetails_struct_h_b->h_buy_sell_flag[0] == SELL_ORD_IND)
		{
			

			if (APL_FAILURE == CR_Rtv_InstrChrVal(	p_or_orderdetails_struct_h_b->h_instr_code,
															"locncode",
															chr_l_instr_locncode,
															l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}

			if (APL_FAILURE == DL_Chk_Pos(	p_or_orderdetails_struct_h_b->h_dl_client,
															p_or_orderdetails_struct_h_b->h_instr_code,
															chr_l_instr_locncode,
															&l_availquantity,"FREE",
															l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL
			}
			
			if (l_availquantity < p_or_orderdetails_struct_h_b->h_orderquantity)
			{
				CO_InsertWarning(	l_debug_info_ptr,
										ERR_DEAL_NENUFPOSN,
										p_or_orderdetails_struct_h_b->h_dl_client,
										p_or_orderdetails_struct_h_b->h_instr_code,
										APL_NULL_STRING,
										__LINE__,
										__FILE__ );
			}
		}
	}

	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET)) || 
		 (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE)))
	{
		if (APL_FAILURE == CR_Rtv_OrdChrVal(  p_or_orderdetails_struct_h_b->h_dl_client,
      	                                 p_or_orderdetails_struct_h_b->h_orderindentity_no,
         	                              "maker",
            	                           chr_l_maker,
               	                        l_debug_info_ptr ))
   	{
      	APL_GOBACK_FAIL
   	}
   	if (!strcmp(p_intl_envdatastruct_h->usr, chr_l_maker))
   	{
      	
	
   	   CO_InsertErr(  	l_debug_info_ptr,
       	              		ERR_MAKER_CHECKER_SAME,
                        	p_or_orderdetails_struct_h_b->h_dl_client,
                       		p_or_orderdetails_struct_h_b->h_orderindentity_no,
                       		APL_NULL_STRING,
           	           		__LINE__,
              	         	__FILE__ );
        	APL_GOBACK_FAIL
   	}
	}

	

	if (APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr)) APL_GOBACK_FAIL

	

	

	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT))
	{
		

		if (APL_FAILURE == CR_Rtv_OrdRefNo(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_orderident,
														l_debug_info_ptr ))
		{	
			APL_GOBACK_FAIL
		}
		strcpy(p_or_orderdetails_struct_h_b->h_orderindentity_no, p_orderident);
	}

	

	if (APL_FAILURE == CR_Mod_DBOrd(	p_or_orderdetails_struct_h_b,
												chr_l_rowid_A,
												p_intl_envdatastruct_h,
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT)) ||
		 (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET)))
	{
		l_quantitytoupd = p_or_orderdetails_struct_h_b->h_orderquantity;
		l_oldquantity   = 0.0;
		l_oldlmtprc = 0.0;
		dbl_l_brkgcomm = 0.0;
	}
	else if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY))
	{
		l_quantitytoupd = p_or_orderdetails_struct_h_b->h_orderquantity;
		dbl_l_brkgcomm = 0.0;

		if (APL_FAILURE == CR_Rtv_OrdNumVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"orderqty",
														&l_oldquantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (APL_FAILURE == CR_Rtv_OrdNumVal(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														"limitprice",
														&l_oldlmtprc,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}	
	else if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_DELETE)) ||
				(!strcmp(p_intl_envdatastruct_h->h_mode, CANCEL_MODE)))
	{
		l_quantitytoupd = -p_or_orderdetails_struct_h_b->h_orderquantity;
		l_oldquantity   = 0.0;
		l_oldlmtprc = 0.0;
		dbl_l_brkgcomm = 0.0;
	}
	else 
	{
		l_quantitytoupd = 0.0;
		l_oldquantity   = 0.0;
		l_oldlmtprc = 0.0;
		dbl_l_brkgcomm = 0.0;
	}

	

	l_iflag = 0;
	if (APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_MAINT",
														"UPDATE_ACCBAL",
														&l_iflag,
														l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if ((l_iflag) && (strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE)))
	{
		if (APL_FAILURE == CR_Mod_CustCashBal(	p_or_orderdetails_struct_h_b->h_dl_client,
														&l_quantitytoupd,
														&l_oldquantity,
														&p_or_orderdetails_struct_h_b->h_limitpr,
														&l_oldlmtprc,
														p_or_orderdetails_struct_h_b->h_buy_sell_flag[0],
														&dbl_l_brkgcomm,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	

	memset(l_dl_dealaudit_struct_h, NULL, sizeof(DL_DEALAUDIT_STRUCT_H));
	strcpy(l_dl_dealaudit_struct_h->h_dl_client, p_or_orderdetails_struct_h_b->h_dl_client);
	strcpy(l_dl_dealaudit_struct_h->h_indentity_no, p_or_orderdetails_struct_h_b->h_orderindentity_no);
	strcpy(l_dl_dealaudit_struct_h->h_trail_for, "O");
	strcpy(l_dl_dealaudit_struct_h->h_processdetail, p_intl_envdatastruct_h->processtion);
	strcpy(l_dl_dealaudit_struct_h->h_proc_usr, p_intl_envdatastruct_h->usr);
	if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE))
	{
		if (!strcmp(chr_l_ord_status, STATUS_DEL_UAUTH))
		{
			strcpy(l_dl_dealaudit_struct_h->h_subprocess, AUTH_DEL_IDENT);
		}
		else if (!strcmp(chr_l_ord_status, STATUS_CANC_UAUTH))
		{
			strcpy(l_dl_dealaudit_struct_h->h_subprocess, AUTH_CANCL_IDENT);
		}
		else  
		{
			strcpy(l_dl_dealaudit_struct_h->h_subprocess, APL_NULL_STRING);
		}
	}
	else if (!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_RESET))
	{
		if (!strcmp(chr_l_ord_status, STATUS_DEL_UAUTH))
		{
			strcpy(l_dl_dealaudit_struct_h->h_subprocess, RESETDELETE);
		}
		else if (!strcmp(chr_l_ord_status, STATUS_CANC_UAUTH))
		{
			strcpy(l_dl_dealaudit_struct_h->h_subprocess, RESETCANCEL);
		}
	}
	else
	{
		strcpy(l_dl_dealaudit_struct_h->h_subprocess, APL_NULL_STRING);
	}
   strcpy(l_dl_dealaudit_struct_h->h_logdate, APL_NULL_STRING);
   strcpy(l_dl_dealaudit_struct_h->h_fail_cd, APL_NULL_STRING);
   l_dl_dealaudit_struct_h->h_qty = p_or_orderdetails_struct_h_b->h_orderquantity;
   strcpy(l_dl_dealaudit_struct_h->h_dlfromord, "N");

   if (APL_FAILURE == CR_Mod_CLHAudTrail(l_dl_dealaudit_struct_h, l_debug_info_ptr))
   {
      APL_GOBACK_FAIL
   }
			  
	

	if ((!strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE)) &&
		 (!strcmp(chr_l_ord_status, STATUS_DEL_UAUTH)))
	{
		if (APL_FAILURE == CR_Proc_MvToHisOrd(	p_or_orderdetails_struct_h_b->h_dl_client,
														p_or_orderdetails_struct_h_b->h_orderindentity_no,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	
	
	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CR_Mod_Ord with success\n",
							NULL,
							NULL);
		}
      return(APL_SUCCESS);

   RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CR_Mod_Ord with errors\n",
							NULL,
							NULL);
		}
      return(APL_FAILURE);

}




int CR_Proc_OrdRefNoFrmt(int int_l_seqnum_a,
                                                                char *p_final_orderident,
                                                                DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
   char  chr_l_pad_seqnum[SEQNUM_LEN]   = APL_NULL_STRING;
        char  chr_l_pad_juldate[JULDATERR_LEN] = APL_NULL_STRING;
        char  chr_l_pad_char[APL_FLAG_LENGTH]   = APL_NULL_STRING;
        char  chr_l_now[APL_DATE_LEN]        = APL_NULL_STRING;
        char  chr_l_yr[YR_LEN]               = APL_NULL_STRING;
        int   int_l_jul_date                 = 0;

        
        sprintf(chr_l_pad_seqnum, "%d", int_l_seqnum_a);
        chr_l_pad_char[0] = SEQNUM_PAD_CHAR;
        chr_l_pad_char[1] = '\0';
        if (APL_FAILURE == CO_PadString( chr_l_pad_seqnum,
                                        'L',
                                         4,
                                         chr_l_pad_char,
                                         l_debug_info_ptr ))
        {
                return(APL_FAILURE);
        }

        

        if (APL_FAILURE == CO_Rtv_JulDt( &int_l_jul_date,
                                            l_debug_info_ptr ))
        {
                return(APL_FAILURE);
        }
   	
   	int_l_jul_date += 1;
    

        sprintf(chr_l_pad_juldate, "%d", int_l_jul_date);
        chr_l_pad_char[0] = SEQNUM_PAD_CHAR;
        chr_l_pad_char[1] = '\0';
  		  if (APL_FAILURE == CO_PadString( chr_l_pad_juldate,
                                   'L',
                                    3,
                                    chr_l_pad_char,
                                    l_debug_info_ptr ))
        {
                return(APL_FAILURE);
        }

        

        if (APL_FAILURE == CO_RtvSysDtTime(chr_l_now, l_debug_info_ptr))
        {
                return(APL_FAILURE);
        }

        

        chr_l_yr[0] = chr_l_now[8];
        chr_l_yr[1] = chr_l_now[9];
        chr_l_yr[2] = '\0';

        

        

        sprintf(p_final_orderident, "ORX%s%s%s", chr_l_yr, chr_l_pad_juldate, chr_l_pad_seqnum);
        return(APL_SUCCESS);
}
