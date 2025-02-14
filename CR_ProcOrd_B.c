





#define PURE_C_SOURCE 
#include <math.h>

#include "CO_HostStructdef.h"



int CR_Mod_OrdExec(	DEAL_EXECDET_STRUCT_H *p_deal_execdet_struct_h_b,
						ORDERDETAILS_STRUCT_H		*p_orderdetails_struct_h,
						INTL_ENV_DATA_STRUCT_H	*p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H			**l_debug_info_ptr )
{
	char		chr_l_buf[BUFFER_LEN]						=	APL_NULL_STRING;
	char		chr_l_buysellflg[APL_FLAG_LENGTH]			=	APL_NULL_STRING;
	char		chr_l_ord_access_stamp[APL_DATE_LEN]	=	APL_NULL_STRING;
	char		chr_l_ord_rowid[APL_ROWID_LEN]			=	APL_NULL_STRING;
	char		chr_l_ord_instrcode[APL_INSTRUMENTCODE_LEN]		=	APL_NULL_STRING;
	char		chr_l_ord_maker[APL_USERID_LEN]		=	APL_NULL_STRING;
	char		chr_l_ord_checker[APL_USERID_LEN]		=	APL_NULL_STRING;
	char		chr_l_ord_lastexecdt[APL_DATE_LEN]	=	APL_NULL_STRING;
	char		chr_l_ord_islimit[APL_FLAG_LENGTH]		=	APL_NULL_STRING;
	char		chr_l_instr_ccycode[APL_CCYCODE_LEN]	=	APL_NULL_STRING;
	char		chr_l_typeofinstrofinstr[TYPEOF_INSTR_LEN]		=	APL_NULL_STRING;
	char		chr_l_sysdate_b[APL_DATE_LEN]				=	APL_NULL_STRING;
	char		int_l_exist_a									=	APL_NULL_CHAR;
	char		chr_l_auth									=	APL_NULL_CHAR;
	char		chr_l_del										=	APL_NULL_CHAR;
	char		chr_l_cancel									=	APL_NULL_CHAR;
	char		chr_l_exec									=	APL_NULL_CHAR;
	char		chr_l_exectyp								=	APL_NULL_CHAR;
	char		chr_l_expire									=	APL_NULL_CHAR;
	char		chr_l_cubk									=	APL_NULL_CHAR;
	char		chr_l_orderac								=	APL_NULL_CHAR;
	char		chr_l_mastacc								=	APL_NULL_CHAR;
	char		chr_l_frozen									=	APL_NULL_CHAR;
	char		chr_l_closed									=	APL_NULL_CHAR;
	char		chr_l_mothchld								=	APL_NULL_CHAR;
	char		chr_l_converted								=	APL_NULL_CHAR;
	char		int_l_type									=	APL_NULL_CHAR;
	double	l_ord_limitcost						=	0;
	double	l_totquantity									=	0;
	double	l_availquantity								=	0;
	double	l_limitprc_chkval						=	0;
	double	l_tmp1_limitprc						=	0;
	double	dbl_l_comm									=	0;
	double	l_tmp1_comm								=	0;
	double	l_tmp2_comm								=	0;
	double	l_tmp3_comm								=	0;
	double	l_tmp4_comm								=	0;
	double	l_total									=	0;
	double	l_totamount									=	0;
	double	l_tmp1_totamount							=	0;
	double	l_tmp2_totamount							=	0;
	double	l_tmp3_totamount							=	0;
	double	l_tmp4_totamount							=	0;
	double	l_tmp5_totamount							=	0;
	double	l_stexcomm								=	0;
	double	l_totcomm								=	0;
	double	l_taxamount									=	0;
	double	l_tmp1_taxamount							=	0;
	double	l_tmp2_taxamount							=	0;
	double	l_trdamount									=	0;
	double	l_trdcost								=	0;
	double	l_trd_brokercomm							=	0;
	double	l_tmp1_trdcost						=	0;
	double	l_instr_nominal_valueue							=	0;
	double	l_instr_min_fmt_dl_qty						=	0;
	double	l_ord_orderquantity							=	0;
	double	l_ord_execquantity							=	0;
	int		int_l_cnt										=	0;
	int		int_l_ccy_decimallen						=	0;
	int		int_l_date_diff								=	0;
	int		int_l_error_flg								=	APL_SUCCESS;
	short		int_l_condexists_A							=	0;
	short		l_rucondexists							=	0;
	DL_DEALAUDIT_STRUCT_H	*l_dl_dealaudit_struct_hb		=	NULL;

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE,
						"Entering Function CR_Mod_OrdExec\n",
						NULL,
						p_intl_envdatastruct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN); 
		sprintf(	chr_l_buf,
					"The Account is : %s\n",
					p_deal_execdet_struct_h_b->h_dl_client );
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN); 
		sprintf(	chr_l_buf,
					"The Order Refno is : %s\n",
					p_deal_execdet_struct_h_b->h_orderindentity_no );
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN); 
		sprintf(	chr_l_buf,
					"The Execution Qty is : %f\n",
					p_deal_execdet_struct_h_b->h_qty );
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_envdatastruct_h );
	}
		
	

	if ( strlen(p_deal_execdet_struct_h_b->h_dl_client) == 0 )
	{
		APL_DATA_MISSING(	"Account",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_indentity_no) == 0 )
	{
		APL_DATA_MISSING(	"Trade Ref. Number",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_orderindentity_no) == 0 )
	{
		APL_DATA_MISSING(	"Order Ref. Number",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_dlt) == 0 )
	{
		APL_DATA_MISSING(	"Trade Date",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_setldt) == 0 )
	{
		APL_DATA_MISSING(	"CSD",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_classofdl) == 0 )
	{
		APL_DATA_MISSING(	"Type Of Trade",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_gen_fxadv_ind) == 0 )
	{
		APL_DATA_MISSING(	"FX Advice Flag",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' )
	{
		if ( strlen(p_deal_execdet_struct_h_b->h_loccode) == 0 )
		{
			APL_DATA_MISSING(	"Location Code",
									APL_NULL_STRING,
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_isspotdl) == 0 )
	{
		APL_DATA_MISSING(	"Spot Trade Flag",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_domcpclt_cd) == 0 )
	{
		APL_DATA_MISSING(	"Dom. CP Account",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_dealcd) == 0 )
	{
		APL_DATA_MISSING(	"Trade Code",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_ex_arena) == 0 )
	{
		APL_DATA_MISSING(	"Exec. Arena",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen(p_deal_execdet_struct_h_b->h_tax_amount) == 0 )
	{
		APL_DATA_MISSING(	"Tax Included Flag",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' )
	{
		if ( strlen(p_deal_execdet_struct_h_b->h_ispymtlocal) == 0 )
		{
			APL_DATA_MISSING(	"Local Payment Flag",
									APL_NULL_STRING,
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}
		
		if ( strlen(p_deal_execdet_struct_h_b->h_pos_stat) == 0 )
		{
			APL_DATA_MISSING(	"Position Status",
									APL_NULL_STRING,
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}
	}

	if ( p_deal_execdet_struct_h_b->h_qty == 0 )
	{
		APL_DATA_MISSING(	"Execution Qty",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_deal_execdet_struct_h_b->h_amt == 0 )
	{
		APL_DATA_MISSING(	"Countervalue",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( strlen( p_orderdetails_struct_h->h_access_stamp) == 0 )
	{
		APL_DATA_MISSING(	"Access Stamp",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_orderdetails_struct_h->h_element_cnt == 0 )
	{
		APL_DATA_MISSING( "No. Of Elements",
								APL_NULL_STRING,
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( VAL_FREE_DEAL(p_deal_execdet_struct_h_b->h_dealcd[0]) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Free Trade",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_deal_execdet_struct_h_b->h_stex_comm < 0 )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_VALUE_CANT_NEGATIVE,
														"Stock Ex. Comm.",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_deal_execdet_struct_h_b->h_oth_comm < 0 )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_VALUE_CANT_NEGATIVE,
														"Other Comm.",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_deal_execdet_struct_h_b->h_amt < 0 )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_VALUE_CANT_NEGATIVE,
														"Countervalue",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	l_totquantity = 0;

	for ( int_l_cnt = 0; int_l_cnt < p_orderdetails_struct_h->h_element_cnt; int_l_cnt++ )
	{
		if ( *(p_orderdetails_struct_h->h_qty+int_l_cnt) <= 0 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_VAL_SHLDBERR_POS,
															"Indiv. Exec. Qty",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( *(p_orderdetails_struct_h->h_pr+int_l_cnt) <= 0 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_VAL_SHLDBERR_POS,
															"Indiv. Exec. Price",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( *(p_orderdetails_struct_h->h_brokercomm+int_l_cnt) < 0 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_VALUE_CANT_NEGATIVE,
															"Indiv. Brk Comm.",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		l_totquantity = l_totquantity + *(p_orderdetails_struct_h->h_qty + int_l_cnt);
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"rowid",
													chr_l_ord_rowid,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

		

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"access_stamp",
													chr_l_ord_access_stamp,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}
	else
	{
		if ( strcmp( p_orderdetails_struct_h->h_access_stamp, chr_l_ord_access_stamp ) )
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_ACCESSSTAMP_CHGD,
									p_deal_execdet_struct_h_b->h_dl_client,
									p_deal_execdet_struct_h_b->h_orderindentity_no,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );
			APL_GOBACK_FAIL;
		}
	}

	

	int_l_exist_a 		= 	'Y';
	chr_l_auth		=	APL_NULL_CHAR;
	chr_l_del			=	'N';
	chr_l_cancel		=	'N';
	chr_l_exec		=	'N';
	chr_l_exectyp	=	'F';
	chr_l_expire		=	'N';

	if ( APL_FAILURE == CR_Chk_Ord(	p_deal_execdet_struct_h_b->h_dl_client,
												p_deal_execdet_struct_h_b->h_orderindentity_no,
												int_l_exist_a,
												chr_l_auth,
												chr_l_del,
												chr_l_cancel,
												chr_l_exec,
												chr_l_exectyp,
												chr_l_expire,
												l_debug_info_ptr ) )
	{
		int_l_error_flg = APL_FAILURE;
	}

	

	int_l_exist_a		=	'Y';
	chr_l_cubk		=	'C';
	chr_l_orderac	=	'B';
	chr_l_mastacc	=	APL_NULL_CHAR;
	chr_l_auth		=	'Y';
	chr_l_del			=	'N';
	chr_l_frozen		=	'N';
	chr_l_closed		=	'N';

	if ( APL_FAILURE == CO_Chk_AccValid(	p_deal_execdet_struct_h_b->h_dl_client,
												int_l_exist_a,
												chr_l_cubk,
												chr_l_orderac,
												chr_l_mastacc,
												chr_l_auth,
												chr_l_del,
												chr_l_frozen,
												chr_l_closed,
												l_debug_info_ptr ) )
	{
		int_l_error_flg	= APL_FAILURE;
	}

	

	int_l_exist_a		=	'Y';
	chr_l_cubk		=	'B';
	chr_l_orderac	=	APL_NULL_CHAR;
	chr_l_mastacc	=	APL_NULL_CHAR;
	chr_l_auth		=	'Y';
	chr_l_del			=	'N';
	chr_l_frozen		=	'N';
	chr_l_closed		=	'N';

	if ( APL_FAILURE == CO_Chk_AccValid(	p_deal_execdet_struct_h_b->h_domcpclt_cd,
												int_l_exist_a,
												chr_l_cubk,
												chr_l_orderac,
												chr_l_mastacc,
												chr_l_auth,
												chr_l_del,
												chr_l_frozen,
												chr_l_closed,
												l_debug_info_ptr ) )
	{
		int_l_error_flg	= APL_FAILURE;
	}

	

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"instr_code",
													chr_l_ord_instrcode,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}
	else
	{
		int_l_exist_a		=	'Y';
		chr_l_auth		=	'Y';
		chr_l_del			=	'N';
		chr_l_frozen		=	'N';
		chr_l_mothchld	=	APL_NULL_CHAR;
		chr_l_converted	=	'N';
	
		if ( APL_FAILURE == CO_Chk_InstrValid(	chr_l_ord_instrcode,
													int_l_exist_a,
													chr_l_auth,
													chr_l_del,
													chr_l_frozen,
													chr_l_mothchld,
													chr_l_converted,
													l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}
	}

	
	 
	int_l_exist_a	=	'Y';
	chr_l_auth	=	'Y';
	chr_l_del		=	'N';

	if ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' )
	{
		if ( APL_FAILURE ==	MT_Chk_Loc(	p_deal_execdet_struct_h_b->h_loccode,
														int_l_exist_a,
														chr_l_auth,
														chr_l_del,
														l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}
	}

	

	if ( APL_FAILURE == CR_Rtv_InstrChrVal(	chr_l_ord_instrcode,
													"ccycode",
													chr_l_instr_ccycode,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}
	else
	{

		int_l_exist_a 	= 	'Y';
		int_l_type 	=	'M';

		if ( APL_FAILURE == CO_Chk_CcyValid(	chr_l_instr_ccycode,
													int_l_type,
													int_l_exist_a,
													l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( APL_FAILURE == CO_RtvSysDt( 	chr_l_sysdate_b,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	
	
	int_l_condexists_A = 0;
	
	if ( APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_EXECUTION",
														"MULTEXEC_SAMEDAY_YES",
														&int_l_condexists_A,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( int_l_condexists_A == 0 )
	{
		if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
														p_deal_execdet_struct_h_b->h_orderindentity_no,
														"lastexecdt",
														chr_l_ord_lastexecdt,
														l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
		else
		{
			if ( strlen( chr_l_ord_lastexecdt ) != 0 )
			{
				if ( APL_FAILURE == CO_Pro_DateComp(   chr_l_ord_lastexecdt,
																chr_l_sysdate_b,
																&int_l_date_diff,
																l_debug_info_ptr ) )
				{
					APL_GOBACK_FAIL;
				}

				if ( int_l_date_diff == 0 )
				{
					CO_InsertErr(	l_debug_info_ptr,
											ERR_ORD_EXEC_TODAY,
											p_deal_execdet_struct_h_b->h_dl_client,
											p_deal_execdet_struct_h_b->h_orderindentity_no,
											APL_NULL_STRING,
											__LINE__,
											__FILE__);
					APL_GOBACK_FAIL;
				}
			}
		}
	}


	

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"maker",
													chr_l_ord_maker,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"checker",
													chr_l_ord_checker,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( 	( strlen(chr_l_ord_checker) && 	
			( !strcmp(chr_l_ord_maker, chr_l_ord_checker) ) && 
			( !strcmp( chr_l_ord_maker, p_intl_envdatastruct_h->usr ) ) )
			||
			( !strlen(chr_l_ord_checker) &&
			( !strcmp( chr_l_ord_maker, p_intl_envdatastruct_h->usr ) ) ) )
	{
		CO_InsertErr(	l_debug_info_ptr,
								ERR_MAKER_CHECKER_SAME,
								APL_NULL_STRING,
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__ );
		APL_GOBACK_FAIL;
	}

	

	if ( l_totquantity != p_deal_execdet_struct_h_b->h_qty )
	{
		CO_InsertErr(	l_debug_info_ptr,
								ERR_DATA_INTEGRITY,
								"Exec Qty!=Sum(Indiv)",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__ );
		APL_GOBACK_FAIL;
	}

	

	if (APL_FAILURE == CR_Rtv_OrdNumVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"orderqty",
													&l_ord_orderquantity,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (APL_FAILURE == CR_Rtv_OrdNumVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"execqty",
													&l_ord_execquantity,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
	
	printf("Checking values :%lf:%lf:%lf:",l_ord_orderquantity , l_ord_execquantity, p_deal_execdet_struct_h_b->h_qty );
	if (( (l_ord_orderquantity - l_ord_execquantity) < p_deal_execdet_struct_h_b->h_qty)  &&
			((l_ord_orderquantity - l_ord_execquantity) !=  p_deal_execdet_struct_h_b->h_qty)  )
	{
		CO_InsertErr(	l_debug_info_ptr,
								ERR_DEAL_QTY_CANT_MORE_AVAILQTY,
								"Order Exec. Qty",
								p_deal_execdet_struct_h_b->h_dl_client,
								p_deal_execdet_struct_h_b->h_orderindentity_no,
								__LINE__,
								__FILE__ );
		APL_GOBACK_FAIL
	}

	

	if ( APL_FAILURE == CR_Rtv_InstrChrVal(	chr_l_ord_instrcode,
													"typeofinstr",
													chr_l_typeofinstrofinstr,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if (!strcmp(chr_l_typeofinstrofinstr, APL_INSTRU_FMT))
	{
		if (APL_FAILURE == CR_Rtv_InstrNumVal(	chr_l_ord_instrcode,
														"minfmttrdqty",
														&l_instr_min_fmt_dl_qty,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		for ( int_l_cnt = 0; int_l_cnt < p_orderdetails_struct_h->h_element_cnt; int_l_cnt++ )
		{
			if ( *(p_orderdetails_struct_h->h_qty+int_l_cnt) < l_instr_min_fmt_dl_qty )
			{	
				CO_InsertErr(	l_debug_info_ptr,
										ERR_QTY_CANT_LESS_MINFINQTY,
										"Partial Exec. Qtys",
										p_deal_execdet_struct_h_b->h_dl_client,
										p_deal_execdet_struct_h_b->h_orderindentity_no,
										__LINE__,
										__FILE__ );
				APL_GOBACK_FAIL
			}
		}

		
		
		if ((l_ord_orderquantity - l_ord_execquantity - p_deal_execdet_struct_h_b->h_qty)>0)
		{
			if ((l_ord_orderquantity - l_ord_execquantity - p_deal_execdet_struct_h_b->h_qty) < l_instr_min_fmt_dl_qty)
			{
				CO_InsertWarning(	l_debug_info_ptr,
										W_REM_QTY_LESS_MINFMTQTY,
										p_deal_execdet_struct_h_b->h_dl_client,
										p_deal_execdet_struct_h_b->h_orderindentity_no,
										APL_NULL_STRING,
										__LINE__,
										__FILE__ );
			}
		}
	}

	
	

	strcpy(chr_l_buysellflg, APL_NULL_STRING);

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"buysellflg",
													chr_l_buysellflg,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( ( chr_l_buysellflg[0] == SELL_ORD_IND && 
			 p_deal_execdet_struct_h_b->h_dealcd[0] == DEALCD_RVP )
		  ||
		  ( chr_l_buysellflg[0] == BUY_ORD && 
			 p_deal_execdet_struct_h_b->h_dealcd[0] == DEALCD_DVP ) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Trade Code",
														"Buy Sell Flag",
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	

	strcpy(p_deal_execdet_struct_h_b->h_confdate,chr_l_sysdate_b);


	if ( APL_FAILURE == DL_Proc_PosLock(	p_deal_execdet_struct_h_b->h_dl_client,
													chr_l_ord_instrcode,
													p_deal_execdet_struct_h_b->h_loccode,
													APL_NULL_STRING,"FREE",
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( VAL_DELIVER_DEAL(p_deal_execdet_struct_h_b->h_dealcd[0]) )
	{
		l_availquantity = 0;

		if ( APL_FAILURE == DL_Chk_AvlPos(	p_deal_execdet_struct_h_b->h_dl_client,
														chr_l_ord_instrcode,
														p_deal_execdet_struct_h_b->h_loccode,
														'Y','N','N','Y','Y','N','N','N',
														"FREE",
														&l_availquantity,
														l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
		else
		{
			if ( l_availquantity < p_deal_execdet_struct_h_b->h_qty )
			{
				int_l_condexists_A = 0;

				if ( APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_EXECUTION",
																	"NENUFPOSN_ERROR",
																	&int_l_condexists_A,
																	l_debug_info_ptr ) )
				{
					APL_GOBACK_FAIL;
				}
				else
				{
					if ( int_l_condexists_A > 0 )
					{
						CO_InsertErr(	l_debug_info_ptr,
												ERR_DEAL_NENUFPOSN,
												p_deal_execdet_struct_h_b->h_dl_client,
												chr_l_ord_instrcode,
												p_deal_execdet_struct_h_b->h_loccode,
												__LINE__,
												__FILE__ );
					}   
					else
					{
						CO_InsertWarning(	l_debug_info_ptr,
												ERR_DEAL_NENUFPOSN,
												p_deal_execdet_struct_h_b->h_dl_client,
												chr_l_ord_instrcode,
												p_deal_execdet_struct_h_b->h_loccode,
												__LINE__,
												__FILE__ );
						
						
					}   
				}
			}
		}
	}												

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( APL_FAILURE == CR_Rtv_OrdChrVal(	p_deal_execdet_struct_h_b->h_dl_client,
													p_deal_execdet_struct_h_b->h_orderindentity_no,
													"islimit",
													chr_l_ord_islimit,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( chr_l_ord_islimit[0] == 'Y' )
	{
		if ( APL_FAILURE == CR_Rtv_OrdNumVal(	p_deal_execdet_struct_h_b->h_dl_client,
														p_deal_execdet_struct_h_b->h_orderindentity_no,
														"limitprice",
														&l_ord_limitcost,
														l_debug_info_ptr ) ) 
		{
			APL_GOBACK_FAIL;
		}

		

		if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
		{
			l_limitprc_chkval = l_ord_limitcost * 100;
		}
		else
		{
			l_limitprc_chkval = l_ord_limitcost;
		}

		

		for ( int_l_cnt = 0; int_l_cnt<p_orderdetails_struct_h->h_element_cnt; int_l_cnt++ )
		{
			if ( VAL_DELIVER_DEAL( p_deal_execdet_struct_h_b->h_dealcd[0] ) )
			{

				
				 
				printf("Checking the limit price :%lf:%lf",*(p_orderdetails_struct_h->h_pr+int_l_cnt), l_limitprc_chkval);
				if ( ( *(p_orderdetails_struct_h->h_pr+int_l_cnt) < ( l_limitprc_chkval ) )  &&
					( *(p_orderdetails_struct_h->h_pr+int_l_cnt) !=  l_limitprc_chkval ) )
				{
					if ( APL_FAILURE ==	CO_InsertErr(	l_debug_info_ptr,
																		ERR_ORD_INSTRPRICE_CANT_LESS_LIMITPRICE,
																		p_deal_execdet_struct_h_b->h_dl_client,
																		p_deal_execdet_struct_h_b->h_orderindentity_no,
																		APL_NULL_STRING,
																		__LINE__,
																		__FILE__ ) )
					{
						APL_GOBACK_FAIL;
					}
					int_l_error_flg = APL_FAILURE;
				}
			}
			else
			{
				

				if ( *(p_orderdetails_struct_h->h_pr+int_l_cnt) > ( l_limitprc_chkval ) )
				{
					if ( APL_FAILURE ==	CO_InsertErr(	l_debug_info_ptr,
																		ERR_ORD_INSTRPRICE_CANT_MORE_LIMITPRICE,
																		p_deal_execdet_struct_h_b->h_dl_client,
																		p_deal_execdet_struct_h_b->h_orderindentity_no,
																		APL_NULL_STRING,
																		__LINE__,
																		__FILE__ ) )
					{
						APL_GOBACK_FAIL;
					}
					int_l_error_flg = APL_FAILURE;
				}
			}
		}
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL;
	}

	

	l_rucondexists = 0;

	if ( APL_FAILURE == CO_Chk_CntryEnabled(	"ORD_EXECUTION",
														"PROCESS_FOR_RU",
														&l_rucondexists,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	int_l_ccy_decimallen = 0;
	if ( APL_FAILURE == CR_Rtv_CCYFldVal(	chr_l_instr_ccycode,
													"decimallen",
													&int_l_ccy_decimallen,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}	

	if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
	{
		if ( APL_FAILURE == CR_Rtv_InstrNumVal(	chr_l_ord_instrcode,
														"nomval",
														&l_instr_nominal_valueue,
														l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
	}

	

	if ( l_rucondexists == 0 )
	{
		l_totamount = 	p_deal_execdet_struct_h_b->h_stex_comm +
						p_deal_execdet_struct_h_b->h_oth_comm;
	}
	else
	{
		l_totamount = 	p_deal_execdet_struct_h_b->h_oth_comm;
	}

	if ( VAL_DELIVER_DEAL( p_deal_execdet_struct_h_b->h_dealcd[0] ) )
	{
		l_totamount = l_totamount * -1;
	}

	

	for ( int_l_cnt = 0; int_l_cnt < p_orderdetails_struct_h->h_element_cnt; int_l_cnt++ )
	{
		l_tmp1_comm	= 0;
		l_tmp2_comm = 0;
		l_tmp3_comm = 0;

		if ( l_rucondexists > 0 )
		{
			if ( *(p_orderdetails_struct_h->h_brokercomm+int_l_cnt) == 0 )
			{
				l_tmp1_comm = *(p_orderdetails_struct_h->h_qty+int_l_cnt) *
						        ( *(p_orderdetails_struct_h->h_pr+int_l_cnt) / 100 ); 

				CO_Round( l_tmp1_comm, 0, &l_tmp2_comm );

				l_tmp2_comm = l_tmp2_comm * l_mt_core_sys_params_struct_h.custody_comm_rt / 100;

				CO_Round( l_tmp2_comm, int_l_ccy_decimallen, &l_tmp3_comm );

				dbl_l_comm = dbl_l_comm + l_tmp3_comm;
			}
			else
			{
				l_tmp1_comm = 	*(p_orderdetails_struct_h->h_qty+int_l_cnt) *
						  			( *(p_orderdetails_struct_h->h_pr+int_l_cnt) / 100 ); 

				CO_Round( l_tmp1_comm, 0, &l_tmp2_comm );

				l_tmp2_comm = l_tmp2_comm * (*(p_orderdetails_struct_h->h_brokercomm+int_l_cnt ) )/ 100;

				CO_Round( l_tmp2_comm, int_l_ccy_decimallen, &l_tmp3_comm );

				dbl_l_comm = dbl_l_comm + l_tmp3_comm;
			}
		}
		else
		{
			if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
			{
				l_tmp3_comm = (*(p_orderdetails_struct_h->h_qty+int_l_cnt)) * 
									( (*(p_orderdetails_struct_h->h_pr+int_l_cnt)) / 100 ) *
									( l_instr_nominal_valueue ) *
									(*(p_orderdetails_struct_h->h_brokercomm+int_l_cnt)) / 100;
				dbl_l_comm = dbl_l_comm + l_tmp3_comm;
			}
			else
			{
				l_tmp3_comm = (*(p_orderdetails_struct_h->h_qty+int_l_cnt)) * 
									(*(p_orderdetails_struct_h->h_pr+int_l_cnt)) *
									(*(p_orderdetails_struct_h->h_brokercomm+int_l_cnt)) / 100;
				dbl_l_comm = dbl_l_comm + l_tmp3_comm;
			}
		}

		if ( l_rucondexists > 0 )
		{
			l_total = l_total + ( (*(p_orderdetails_struct_h->h_qty+int_l_cnt)) *
										 (*(p_orderdetails_struct_h->h_pr+int_l_cnt)) /
										 100 ); 
		}
		else
		{
			if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
			{
				l_total = l_total + ( (*(p_orderdetails_struct_h->h_qty+int_l_cnt)) *
											 (*(p_orderdetails_struct_h->h_pr+int_l_cnt)) /
											 100 ) *
											 l_instr_nominal_valueue ; 
			}
			else
			{
				l_total = l_total + ( (*(p_orderdetails_struct_h->h_qty+int_l_cnt)) *
											 (*(p_orderdetails_struct_h->h_pr+int_l_cnt))); 
			}
		}

		if ( l_rucondexists > 0 )
		{
			l_tmp1_totamount = (*(p_orderdetails_struct_h->h_qty+int_l_cnt) ) *
								 (*(p_orderdetails_struct_h->h_pr+int_l_cnt) ) / 100;
			CO_Round( l_tmp1_totamount, int_l_ccy_decimallen, &l_tmp2_totamount );
			
			l_totamount = l_totamount + l_tmp2_totamount;

			CO_Round( l_tmp1_totamount, 0, &l_tmp3_totamount);

			l_tmp4_totamount = l_tmp3_totamount * l_mt_core_sys_params_struct_h.stk_exg_comm_rt / 100;
			CO_Round( l_tmp4_totamount, int_l_ccy_decimallen, &l_tmp5_totamount );

			if ( VAL_DELIVER_DEAL(p_deal_execdet_struct_h_b->h_dealcd[0] ) )
			{
				l_totamount = l_totamount - l_tmp5_totamount;
			}
			else
			{
				l_totamount = l_totamount + l_tmp5_totamount;
			}

			l_stexcomm = l_stexcomm + l_tmp5_totamount;
		}
		else
		{
			if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
			{
				l_totamount = l_totamount + ( (*(p_orderdetails_struct_h->h_qty+int_l_cnt) ) *
												(*(p_orderdetails_struct_h->h_pr+int_l_cnt) )
												/ 100 *
												l_instr_nominal_valueue );
			}
			else
			{
				l_totamount = l_totamount + ( (*(p_orderdetails_struct_h->h_qty+int_l_cnt) ) *
												(*(p_orderdetails_struct_h->h_pr+int_l_cnt) ));
			}
		}

		l_totcomm = l_totcomm + l_tmp3_comm;

		l_tmp1_taxamount = 0;
		l_tmp2_taxamount = 0;

		if ( l_rucondexists > 0 )
		{
			if ( p_deal_execdet_struct_h_b->h_tax_amount[0] == 'Y' )
			{
				l_tmp1_taxamount = l_tmp3_comm * 
									 l_mt_core_sys_params_struct_h.comm_tax_rt / 
									 100;
				CO_Round( l_tmp1_taxamount, int_l_ccy_decimallen, &l_tmp2_taxamount );

				l_taxamount = l_taxamount + l_tmp2_taxamount;
			}
		}
		else
		{
			if ( p_deal_execdet_struct_h_b->h_tax_amount[0] == 'Y' )
			{
				l_tmp1_taxamount = l_tmp3_comm * 
									 l_mt_core_sys_params_struct_h.comm_tax_rt / 
									 100;

				CO_Round( l_tmp1_taxamount, 0, &l_tmp2_taxamount );

				l_taxamount = l_taxamount + l_tmp2_taxamount;
			}
		}

		if ( VAL_DELIVER_DEAL( p_deal_execdet_struct_h_b->h_dealcd[0] ) )
		{
			l_totamount = l_totamount - l_tmp3_comm - l_tmp2_taxamount;
		}
		else
		{
			l_totamount = l_totamount + l_tmp3_comm + l_tmp2_taxamount;
		}
	}

	CO_Round( l_totamount, int_l_ccy_decimallen, &l_trdamount );
	CO_Round( l_totcomm, int_l_ccy_decimallen, &l_trd_brokercomm );

	if ( l_rucondexists > 0 )
	{
		l_tmp1_trdcost = l_total / p_deal_execdet_struct_h_b->h_qty;

		CO_Round(l_tmp1_trdcost, 5, &l_trdcost );
	}
	else
	{
		if ( !strcmp(chr_l_typeofinstrofinstr, APL_INSTRU_FMT) )
		{
			l_tmp1_trdcost = l_total * 100 / 
									( p_deal_execdet_struct_h_b->h_qty * l_instr_nominal_valueue );

			CO_Round(l_tmp1_trdcost, 3, &l_trdcost );
		}
		else
		{
			l_tmp1_trdcost = l_total / p_deal_execdet_struct_h_b->h_qty;

			CO_Round(l_tmp1_trdcost, int_l_ccy_decimallen, &l_trdcost );
		}
	}

	

	if (!(APL_DOUBLE_EQUAL(l_trdcost, p_deal_execdet_struct_h_b->h_pr) )) 
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Calc. Price != Price",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if (!(APL_DOUBLE_EQUAL(l_trdamount, p_deal_execdet_struct_h_b->h_amt) )) 
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Calc. Amt != Amt",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if (!(APL_DOUBLE_EQUAL(l_trd_brokercomm, p_deal_execdet_struct_h_b->h_brokercomm) ) ) 
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Calc BrkCom!=BrkCom",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( l_rucondexists > 0 )
	{
		if (!(APL_DOUBLE_EQUAL(l_stexcomm, p_deal_execdet_struct_h_b->h_stex_comm) ) ) 
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATA_INTEGRITY,
															"Calc StxCom!=StxCom",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}
	}

	if ( chr_l_ord_islimit[0] == 'Y' )
	{
		

		if ( l_rucondexists > 0 )
		{
			l_tmp1_limitprc	=	l_ord_limitcost /100;

			CO_Round(	l_tmp1_limitprc, 8, &l_limitprc_chkval );
		}
		else
		{
			if ( !strcmp( chr_l_typeofinstrofinstr, APL_INSTRU_FMT ) )
			{
				l_limitprc_chkval = l_ord_limitcost * 100;
			}
			else
			{
				l_limitprc_chkval = l_ord_limitcost;
			}
		}	

		

		if ( VAL_DELIVER_DEAL( p_deal_execdet_struct_h_b->h_dealcd[0] ) )
		{

			

			if ( l_trdcost < ( l_limitprc_chkval ) )
			{
				if ( APL_FAILURE ==	CO_InsertErr(	l_debug_info_ptr,
																	ERR_ORD_INSTRPRICE_CANT_LESS_LIMITPRICE,
																	p_deal_execdet_struct_h_b->h_dl_client,
																	p_deal_execdet_struct_h_b->h_orderindentity_no,
																	APL_NULL_STRING,
																	__LINE__,
																	__FILE__ ) )
				{
					APL_GOBACK_FAIL;
				}
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			

			if ( l_trdcost > ( l_limitprc_chkval ) )
			{
				if ( APL_FAILURE ==	CO_InsertErr(	l_debug_info_ptr,
																	ERR_ORD_INSTRPRICE_CANT_MORE_LIMITPRICE,
																	p_deal_execdet_struct_h_b->h_dl_client,
																	p_deal_execdet_struct_h_b->h_orderindentity_no,
																	APL_NULL_STRING,
																	__LINE__,
																	__FILE__ ) )
				{
					APL_GOBACK_FAIL;
				}
				int_l_error_flg = APL_FAILURE;
			}
		}
	}

	if ( int_l_error_flg == APL_FAILURE )
	{
		APL_GOBACK_FAIL;
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( APL_FAILURE == CR_Proc_OrdExec(	p_deal_execdet_struct_h_b,
													p_orderdetails_struct_h,
													chr_l_ord_rowid,
													p_intl_envdatastruct_h,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( APL_FAILURE == CR_Rtv_OrdTrd(	p_deal_execdet_struct_h_b,
													p_intl_envdatastruct_h,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	

	l_dl_dealaudit_struct_hb = (DL_DEALAUDIT_STRUCT_H*) calloc( 1, sizeof(DL_DEALAUDIT_STRUCT_H) );
	APL_MALLOC_FAIL(l_dl_dealaudit_struct_hb);

	strcpy( l_dl_dealaudit_struct_hb->h_dl_client, p_deal_execdet_struct_h_b->h_dl_client);
	strcpy( l_dl_dealaudit_struct_hb->h_indentity_no, p_deal_execdet_struct_h_b->h_orderindentity_no);
	l_dl_dealaudit_struct_hb->h_trail_for[0] = ORD_TRAIL_FOR;
	l_dl_dealaudit_struct_hb->h_trail_for[1] = '\0';
	strcpy( l_dl_dealaudit_struct_hb->h_processdetail, p_intl_envdatastruct_h->processtion );
	strcpy( l_dl_dealaudit_struct_hb->h_proc_usr, p_intl_envdatastruct_h->usr );
	strcpy( l_dl_dealaudit_struct_hb->h_subprocess, p_intl_envdatastruct_h->subprocess );
	strcpy( l_dl_dealaudit_struct_hb->h_logdate, APL_NULL_STRING );
	strcpy( l_dl_dealaudit_struct_hb->h_fail_cd, APL_NULL_STRING );
	l_dl_dealaudit_struct_hb->h_qty = p_deal_execdet_struct_h_b->h_qty;
	l_dl_dealaudit_struct_hb->h_dlfromord[0] = 'N';
	l_dl_dealaudit_struct_hb->h_dlfromord[1] = '\0';

	if ( APL_FAILURE == CR_Mod_CLHAudTrail( l_dl_dealaudit_struct_hb,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	APL_GOBACK_SUCCESS;

	RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor( 	APL_OUT_FILE,
							"Leaving Function CR_Mod_OrdExec with Success\n",
							NULL,
							p_intl_envdatastruct_h );
		}
		APL_FREE(l_dl_dealaudit_struct_hb);
		return(APL_SUCCESS);
	
	RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor( 	APL_OUT_FILE,
							"Leaving Function CR_Mod_OrdExec with Errors\n",
							NULL,
							p_intl_envdatastruct_h );
		}
		APL_FREE(l_dl_dealaudit_struct_hb);
		return(APL_FAILURE);
}

