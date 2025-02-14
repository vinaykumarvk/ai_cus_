/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2012 Polaris Financial Technology Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to 
 *    Polaris Financial Technology Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or 
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Financial Technology Limited.
 */
/*********************************************************************
 *
 * Module Name         :	Deal processing
 *
 * File Name           :	MT_ProcDL_A.c
 *
 * Description         :	File for processing Deal
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *					
 * 08/12/2010	1.0.4.8 	vivekananda.k	     Client Freezing Enhancement done by ramachandra, retrofit from Dev to Emerfix done by vivekananda.k
 *********************************************************************/

#define	PURE_C_SOURCE
#define  APL_FUNC_NSCCL "NSCCL"
#define  APL_FUNC_BOISL "BOISL"
#include "CO_HostStructdef.h"
#include "DL_Interface.h"
#include "Intellect_Common.h"
#include "CA_Common.h"





int DL_Proc_Trd(	SYS_DL_DEAL_STRUCT_H *p_sys_dl_deal_struct_h_a, 
						int *int_p_trdrepseqnum, 
						INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h, 
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{
	short int_l_error_flg = APL_SUCCESS, 
			int_l_condexists = 0, 
			l_ru_exists = 0, 
			l_locrefexists = 0;
	int		int_l_exists_flg = 0;
	char 	chr_l_fxrqflg = 'Y';
	char	chr_l_candropdt[APL_DATE_LEN]		=	APL_NULL_STRING;
	char	chr_l_acc_class[3]		=	APL_NULL_STRING;
	char 	chr_l_accspottrdflg[APL_FLAG_LENGTH] = APL_NULL_STRING; 
	char	chr_l_fieldname[20] = APL_NULL_STRING;
	char 	chr_l_canreg[APL_FLAG_LENGTH] = APL_NULL_STRING;
        char    l_str_mcscclcode[21]; //Added by deependra For MCS(KB_5878)
        char    h_MapValue[11];       //Added by deependra For MCS(KB_5878)
	char 	chr_l_regbrind[3] = APL_NULL_STRING; 
	char	chr_l_access_stamp[APL_DATE_LEN] = APL_NULL_STRING;
  	char	chr_l_trcodeinstrflg[APL_FLAG_LENGTH] = APL_NULL_STRING;
	char	chr_l_rowid_A[APL_ROWID_LEN] = APL_NULL_STRING;
 	char	chr_mainfuncarea[APL_MAINFUNCAREA_LEN] = APL_NULL_STRING; 
	char 	chr_l_condid[APL_CONDID_LEN] = APL_NULL_STRING;
	char 	chr_l_instrcode_b[APL_INSTRUMENTCODE_LEN] = APL_NULL_STRING;
	char	chr_l_trcode_b[APL_FLAG_LENGTH] = APL_NULL_STRING;
	char	chr_l_locncode[APL_LOCNCODE_LENGTH] = APL_NULL_STRING;
	char	chr_l_posnstatus[STATUS_POS_LEN] = APL_NULL_STRING;
	char	chr_l_sysdate[APL_DATE_LEN] = APL_NULL_STRING;
	char	chr_l_settle_err_cond[3] = APL_NULL_STRING;
	char 	chr_l_manifldflg[APL_FLAG_LENGTH] = APL_NULL_STRING;
	char	chr_l_clscode_a[CLSCD_LEN] = APL_NULL_STRING;
	char	chr_l_vdpdate[APL_DATE_LEN]	= APL_NULL_STRING;
	char	chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char	chr_l_typeofinstr[TYPEOF_INSTR_LEN]	= APL_NULL_STRING;
	char	chr_l_tmpdate[APL_DATE_LEN]		= APL_NULL_STRING;
	char chr_l_cubk_exttrd[2]				= APL_NULL_STRING;
	double l_trdquantity = 0;
	double l_availquantity = 0;
	double l_minfmttrdquantity = 0;
	int	int_l_datecmp = 0;
	int	int_l_holexists = 0;
	int	int_l_enufvdp = 0;
	int	int_l_flg = 0;
	int	int_l_exists = 0;
	int int_ret_val=0;
	char chr_l_interfii[2] = APL_NULL_STRING;
	char l_exch_code[4] =  APL_NULL_STRING;
        double chr_l_val = 0.0;    //Added by Gouse - Decimal Length for MF- 01/10/2011

	DL_DEALAUDIT_STRUCT_H *l_dl_dealaudit_struct_hb_a = NULL;	
	char	chr_spl_client[APL_CLIENT_LENGTH] = APL_NULL_STRING;
	short	l_ext_trd_check = 0;

	GN_AUDIT_LOG_STRUCT_H	*p_gn_audit_log_struct_h = NULL;
	CA_GN_AUDIT_LOG_STRUCT_H *p_ca_gn_audit_log_struct_h = NULL;
	char  chr_h_entity_name[100] = APL_NULL_STRING;/*HDFCGN_001 Sonali Audit*/
					

	char l_block_type[5] =	APL_NULL_STRING; 
	char l_evt_type[10], l_op_evt_type[10];

	double l_to_compare_availquantity = 0;  /* added by amish -- 27/02/2007 */
        // SantoshS - IB_2B_013
        double fractpart, intpart;//Added by Gouse - Decimal Length for MF- 01/10/2011 

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE,
						"Entering Function DL_Proc_Trd\n",
						NULL,
						p_intl_env_data_struct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(		chr_l_buf, 
						"The Account is : %s\n",
						p_sys_dl_deal_struct_h_a->h_dl_client );
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_env_data_struct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(		chr_l_buf, 
						"The Refno is : %s\n",
						p_sys_dl_deal_struct_h_a->h_indentity_no);
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_env_data_struct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(		chr_l_buf, 
						"The Mode is : %s\n",
						p_intl_env_data_struct_h->h_mode);
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_env_data_struct_h );
		memset(chr_l_buf, NULL, BUFFER_LEN);
		sprintf(		chr_l_buf, 
						"The Action is : %c\n",
						p_intl_env_data_struct_h->h_process[0] );
		CO_ProcMonitor(	APL_OUT_FILE,
						chr_l_buf,
						NULL,
						p_intl_env_data_struct_h );
	}
        /* Added by Gouse - Decimal Length for MF- 01/10/2011 - End */
	printf("\n chr_l_typeofinstr is |%s|\n",chr_l_typeofinstr);
	printf("Decimal Length Test\n");
	printf("h_origquantity is |%f|\n",p_sys_dl_deal_struct_h_a->h_origquantity);//Added by Gouse - 15/05/2012
        //if(!strcmp(chr_l_typeofinstr, APL_INSTRU_MTF))Commanted By Gouse - UAT Issue - 24/04/2012
        //{ Commanted By Gouse - UAT Issue - 24/04/2012
		printf("\n Here At 122 \n");
                /* Added  By Madhavi  as per RFSNO:SBI_ENH_003 */
				
				/* Production issues 2023*/
				
	     printf("\n Here At 160 \n");
		if(strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND))
		{		
			if(   (!strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"17") ||
		         !strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"19") ||
		         !strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"18") ||
		         !strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"20") )&& (strlen(p_sys_dl_deal_struct_h_a->h_indentity_no) > 5))
		   {
			   
			   char l_evt_type[10];
			char l_op_evt_type[10];
		   memset(l_evt_type,NULL,10);
			memset(l_op_evt_type,NULL,10);
		   
		      if(Rtv_Evt_Type(  p_sys_dl_deal_struct_h_a->h_indentity_no,
					               l_evt_type,
					               l_op_evt_type,
				               l_debug_info_ptr) == APL_FAILURE)
		      {
		         Alert("Failed In Rtv_Evt_Type");
		      }
			  
				if(strlen(l_evt_type)!=0){

						if( CO_InsertErr(l_debug_info_ptr,
                                                ERR_CA_IDENTIYNO,
                                                APL_NULL_STRING,
                                                APL_NULL_STRING,
                                                APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
                        	{
                                	APL_GOBACK_FAIL
                        	}
				
				
				}

		
			  
		}
		}	
				
                IF_COND_EXISTS("QTY_RND_MF_MKT","QTY_RND_FOR_MF_MKT")
		{
		    printf("\n Here At 126 \n");
                     CR_Proc_InstrQtyRound_Chk( p_sys_dl_deal_struct_h_a->h_qty, p_sys_dl_deal_struct_h_a->h_instr_code, &chr_l_val, l_debug_info_ptr );

                     p_sys_dl_deal_struct_h_a->h_qty = chr_l_val;
		    Alert("p_sys_dl_deal_struct_h_a->h_qty is |%f|\n",p_sys_dl_deal_struct_h_a->h_qty);

            //Added on 18092013 for ISKB_6288(Original quantity is not getting updated for shortage trade with the quantity of the original trade)-START
            chr_l_val = 0;		
			CR_Proc_InstrQtyRound_Chk(p_sys_dl_deal_struct_h_a->h_origquantity,p_sys_dl_deal_struct_h_a->h_instr_code, &chr_l_val, l_debug_info_ptr );	
            //Added on 18092013 for ISKB_6288(Original quantity is not getting updated for shortage trade with the quantity of the original trade)-END
            p_sys_dl_deal_struct_h_a->h_origquantity = chr_l_val;
		   Alert("p_sys_dl_deal_struct_h_a->h_origquantity is |%f|\n",p_sys_dl_deal_struct_h_a->h_origquantity);
		}
                 /* End of Madhavi changes  as per RFSNO:SBI_ENH_003 */
		
		else
		{
		if(strlen(p_sys_dl_deal_struct_h_a->h_exch_code))
		{
			intpart = 0;
			CO_Round(p_sys_dl_deal_struct_h_a->h_qty, l_mt_core_sys_params_struct_h.qty_dec_len, &intpart);
			p_sys_dl_deal_struct_h_a->h_qty = intpart;	
		}
        	else
        	{
                	fractpart = modf(p_sys_dl_deal_struct_h_a->h_qty, &intpart);
                	if(fractpart != 0)
                	{
			intpart = 0;
                        	CR_Proc_DlQtyRound(p_sys_dl_deal_struct_h_a->h_qty,
                                           APL_NULL_STRING,
                                           APL_NULL_STRING,
                                           p_sys_dl_deal_struct_h_a,
                                           &intpart,
                                           l_debug_info_ptr);
				p_sys_dl_deal_struct_h_a->h_qty = intpart;	
                	}
        	         
                        }
        	}
        //}Commanted By Gouse - UAT Issue - 24/04/2012
        /* Added by Gouse - Decimal Length for MF- 01/10/2011 - End */
        /* Added By Kalyan For Web Module -- 19/04/07 */

        if (( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "W")==0) || (strcmp(p_sys_dl_deal_struct_h_a->h_entry, "S")==0)) /* (h_entry, "S") condition added by deependra for handling settlement no. in case of deal addition via swift */
        {

		printf("KS -- Entry mode is Web ... Going for Settlement Calender Check \n");

                if (strcmp(p_sys_dl_deal_struct_h_a->h_clh_flg,"C") == 0 )
                {
                        if((strlen(p_sys_dl_deal_struct_h_a->h_settlement_no)==0)||
						     (strlen(p_sys_dl_deal_struct_h_a->h_trd_setl_no)==0)||    /*Changes by Tushar for KOTAK ISKB_12174 Interoperability*/
                                (strlen(p_sys_dl_deal_struct_h_a->h_payin_dt)==0)||
                                (strlen(p_sys_dl_deal_struct_h_a->h_payout_dt)==0))
                        {
                                printf("KS -- Settlement Details not Found  Retruning Failure\n");
                                if( CO_InsertErr(l_debug_info_ptr,
                                                ERR_STLMENTCAL_NOTFND,
                                                APL_NULL_STRING,
                                                APL_NULL_STRING,
                                                APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
                        	{
                                	APL_GOBACK_FAIL
                        	}
			}
		}
        }

        /* Added By Kalyan For Web Module -- Till here -- 19/04/07 */

  /* Added by deependra(KB_5878) - start */

        memset(l_str_mcscclcode,APL_NULL_CHAR,21);
        memset(h_MapValue,APL_NULL_CHAR,11);

strcpy(h_MapValue,"MCS_CCL_CD");

           if (  CO_Rtv_FldValChar(   "map_val",
                                      "PRO_SGENSTAT",
                                      "map_type",
                                       h_MapValue,
                                       l_str_mcscclcode,
                                       l_debug_info_ptr )==APL_FAILURE)
             APL_GOBACK_FAIL

printf("\n 174 l_str_mcscclcode = [%s] \n",l_str_mcscclcode);

/* Added by deependra(KB_5878) - end */

	if (strlen(p_sys_dl_deal_struct_h_a->h_countclt) != 0)	
	{
	if (strcmp(p_sys_dl_deal_struct_h_a->h_clh_flg,"C") == 0 )
	{
		if((strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_NSCCL) != 0) &&
				(strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_BOISL) != 0)  &&
                (strcmp(p_sys_dl_deal_struct_h_a->h_countclt,l_str_mcscclcode) != 0))
		{
			if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_MISMATCHED_DATA,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}
	/* changes by amish -- 19/05 */
	if ( !strcmp( p_intl_env_data_struct_h->h_mode,PMR_MODE))
		{
			if (strcmp(p_sys_dl_deal_struct_h_a->h_clh_flg,"D") == 0 )
			{
				if((strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_NSCCL) == 0) ||
				(strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_BOISL) == 0) ||
                (strcmp(p_sys_dl_deal_struct_h_a->h_countclt,l_str_mcscclcode) == 0))
		  		{
					if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_MISMATCHED_DATA,
						APL_NULL_STRING, APL_NULL_STRING,
							APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
					{
					APL_GOBACK_FAIL
					}
				}
			}
	}
	if(strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_NSCCL) == 0)
	{
		if(strcmp(p_sys_dl_deal_struct_h_a->h_exch_code,"BSE") == 0)
		{
			if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_BSE,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}
	if(strcmp(p_sys_dl_deal_struct_h_a->h_countclt,APL_FUNC_BOISL) == 0)
	{
		if(strcmp(p_sys_dl_deal_struct_h_a->h_exch_code,"NSE") == 0)
		{
			if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_NSE,
						APL_NULL_STRING, APL_NULL_STRING,
						APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
			{
				APL_GOBACK_FAIL
			}
		}
	}
        if(strcmp(p_sys_dl_deal_struct_h_a->h_countclt,l_str_mcscclcode) == 0)
        {
                if(strcmp(p_sys_dl_deal_struct_h_a->h_exch_code,"MCS") != 0)
                {
                        if( CO_InsertErr(l_debug_info_ptr, ERR_BCN_NOTVALID_EXCH_CD_OTHER_THAN_MCS,
                                                APL_NULL_STRING, APL_NULL_STRING,
                                                APL_NULL_STRING, __LINE__, __FILE__)==APL_FAILURE )
                        {
                                APL_GOBACK_FAIL
                        }
                }
        }


	}
   
	/* changes by amish -- 10/05 */
	
	  if ( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "S")==0)
	  	{
		
			if(strlen(p_sys_dl_deal_struct_h_a->h_clh_flg) == 0)
			{
				 APL_DATA_MISSING("CLH_FLG",APL_NULL_STRING,APL_NULL_STRING);
				  APL_GOBACK_FAIL;
			}
	
		}
	/*Changes by Tushar for KOTAK ISKB_12174 Interoperability Starts*/
	if((!strcmp(p_sys_dl_deal_struct_h_a->h_ex_arena,"1")) && (strcmp(p_sys_dl_deal_struct_h_a->h_trd_exch,APL_NULL_STRING)) &&  (!strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"1")))
    {	
		if (!strlen(p_sys_dl_deal_struct_h_a->h_trd_mkt_type))
	 	{
			APL_DATA_MISSING(	"Market Type Traded Exchange", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}
	}

	if((!strcmp(p_sys_dl_deal_struct_h_a->h_ex_arena,"1")) && (strcmp(p_sys_dl_deal_struct_h_a->h_exch_code,APL_NULL_STRING)) &&  (!strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"1")))
    {	
		if (!strlen(p_sys_dl_deal_struct_h_a->h_mkt_type))
	 	{
			APL_DATA_MISSING(	"Market Type", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}
	}
	/*Changes by Tushar for KOTAK ISKB_12174 Interoperability Ends*/
	strcpy(p_sys_dl_deal_struct_h_a->h_currencycode,"INR");
			
	if ( !strcmp( p_intl_env_data_struct_h->h_mode, RPR_MODE) &&
			( p_intl_env_data_struct_h->h_process[0] == 'D' ) )
	{
		if ( *int_p_trdrepseqnum == 0 )
		{
			APL_DATA_MISSING(	"Sequence Number",
									APL_NULL_STRING,
									APL_NULL_STRING );
			APL_GOBACK_FAIL;
		}
		
		
	
		strcpy(chr_l_fieldname, APL_NULL_STRING );
		strcpy(chr_l_fieldname, "access_stamp");

		if ( APL_FAILURE == DL_Rtv_TrdRprChrVal(	int_p_trdrepseqnum, 
															chr_l_fieldname, 
															chr_l_access_stamp, 
															l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}

		printf("\n Amit:BeforeDL_Mod_DL:cash_client=|%s| \n",p_sys_dl_deal_struct_h_a->h_cash_client);
		
		if ( APL_FAILURE == DL_Mod_DL( p_sys_dl_deal_struct_h_a,
													chr_l_rowid_A,
													int_p_trdrepseqnum,
													p_intl_env_data_struct_h,
													l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
		else
		{
			APL_GOBACK_SUCCESS;
		}
	}

	

	l_dl_dealaudit_struct_hb_a = (DL_DEALAUDIT_STRUCT_H*)calloc(1,sizeof(DL_DEALAUDIT_STRUCT_H));
	APL_MALLOC_FAIL(l_dl_dealaudit_struct_hb_a);

	p_gn_audit_log_struct_h = (GN_AUDIT_LOG_STRUCT_H*)calloc(1,sizeof(GN_AUDIT_LOG_STRUCT_H));
	APL_MALLOC_FAIL(p_gn_audit_log_struct_h);

	p_ca_gn_audit_log_struct_h = (CA_GN_AUDIT_LOG_STRUCT_H*)calloc(1,sizeof(CA_GN_AUDIT_LOG_STRUCT_H));
	APL_MALLOC_FAIL(p_ca_gn_audit_log_struct_h);
		
	if ( strcmp(p_intl_env_data_struct_h->h_mode, RPR_MODE)==0 )
	{
		printf("\n**************\n In REPAIR h_mode  entrytype = :%s: \n***************\n", p_sys_dl_deal_struct_h_a->h_entry);
		if ( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "Y")==0)
			{
				strcpy(p_sys_dl_deal_struct_h_a->h_entry,"M");
				strcpy(p_sys_dl_deal_struct_h_a->h_locchng_flg,"M");
			}
		else if ( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "M")==0)
			{
				strcpy(p_sys_dl_deal_struct_h_a->h_entry,"M");
				strcpy(p_sys_dl_deal_struct_h_a->h_locchng_flg,"N");
			}
		else if ( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "Z")==0)
			{
				strcpy(p_sys_dl_deal_struct_h_a->h_entry,"S");
				strcpy(p_sys_dl_deal_struct_h_a->h_locchng_flg,"M");
			}
		else if ( strcmp(p_sys_dl_deal_struct_h_a->h_entry, "S")==0)
			{
				strcpy(p_sys_dl_deal_struct_h_a->h_entry,"S");
				strcpy(p_sys_dl_deal_struct_h_a->h_locchng_flg,"N");
			}
		else
			{
				strcpy(p_sys_dl_deal_struct_h_a->h_entry,"S");
				strcpy(p_sys_dl_deal_struct_h_a->h_locchng_flg,"N");
			}
	} 
	
	

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_dl_client))
	{
     	APL_DATA_MISSING(	"Account", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	if (!strlen(p_sys_dl_deal_struct_h_a->h_indentity_no))
 	{ 
   	APL_DATA_MISSING( "Ref. No.", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_dlt))
 	{
    	APL_DATA_MISSING(	"Trade Date", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_setldt))
   {
  		APL_DATA_MISSING(	"CSD", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}
  /* Added by Ram for Equity Fund CS0169152 - START*/
  
	if ( !strcmp( p_intl_env_data_struct_h->h_mode, "MOD") &&
			( p_intl_env_data_struct_h->h_process[0] == 'B' ) || ( p_intl_env_data_struct_h->h_process[0] == 'R' ))
	{
		if ( APL_FAILURE ==  DL_Mod_DL( 	p_sys_dl_deal_struct_h_a, 
														chr_l_rowid_A, 
														int_p_trdrepseqnum, 
														p_intl_env_data_struct_h, 
														l_debug_info_ptr) ) 
		{
			printf("\n Directed from  DL_Proc_Trd to DL_Mod_DL for this action");
			APL_GOBACK_FAIL;
		}
		else
		{
			APL_GOBACK_SUCCESS;
		}
	}
  /* Added by Ram for Equity Fund CS0169152 - END*/
  
  	if (!strlen(p_sys_dl_deal_struct_h_a->h_ex_arena))
   {
  		APL_DATA_MISSING(	"Ex. Arena", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

  	if ((!p_sys_dl_deal_struct_h_a->h_qty) && (p_sys_dl_deal_struct_h_a->h_dealcd[0]!='5') && (p_sys_dl_deal_struct_h_a->h_dealcd[0]!='6'))
   {
	  	APL_DATA_MISSING(	"Quantity", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
		Alert(" \n **** unsuccessful Quantity not found %lf ", p_sys_dl_deal_struct_h_a->h_qty);
	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_domcpclt_cd))
   {  
		APL_DATA_MISSING(	"Dom. CP A/c", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
 	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_isspotdl))
   {
	  	APL_DATA_MISSING(	"Is Spot Trd", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}
	/* change by amish --10/05 */
  /*
  	if (!strlen(p_sys_dl_deal_struct_h_a->h_domcp_custodyclt))
   {  
		APL_DATA_MISSING(	"Dom. CP Bank A/c", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}
	*/
	
	/*kotak specific**/
	IF_COND_EXISTS("DL_DEAL","FX_REQD")
	{	

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_fx_reqd))
   {  
		APL_DATA_MISSING(	"FX Reqd.", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	}
  	
  	if (!strlen(p_sys_dl_deal_struct_h_a->h_dealcd))
   {  
		APL_DATA_MISSING(	"Txn. Code", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}
	
	if ( VAL_VP_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) )
	{
		if ( p_sys_dl_deal_struct_h_a->h_amt < 0 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_COUNTVAL_SHLD_POS,
															APL_NULL_STRING,
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

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_instr_code))
   {  
		APL_DATA_MISSING(	"Instrument Code", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_currencycode))
   {
  		APL_DATA_MISSING(	"Currency", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

  	if (!strlen(p_sys_dl_deal_struct_h_a->h_classofdl))
   {
  		APL_DATA_MISSING(	"Type Of Trade.", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}



	if(strcmp(p_sys_dl_deal_struct_h_a->h_loccode,APL_NULL_STRING)==0)
	strcpy(p_sys_dl_deal_struct_h_a->h_loccode,"NSDL");
  	if ( !strlen(p_sys_dl_deal_struct_h_a->h_loccode) && 
			(l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y'))
   {
  		APL_DATA_MISSING(	"Location", 
								APL_NULL_STRING, 
								APL_NULL_STRING );
		int_l_error_flg = APL_FAILURE;
	}

	printf("\n Amit:After Blank Check  Location=|%s| \n",p_sys_dl_deal_struct_h_a->h_loccode);

		l_ext_trd_check = 0;
	IF_COND_EXISTS("DL_DEAL","TRD_MAINT")
	{
		if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRD_MAINT",
															"EXT_TRD_CNTAC_ALWD",
															&l_ext_trd_check,
															l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

	if(l_ext_trd_check==0)
	{
			printf("\n the domcpdlt=|%s|, the custady cltcd =|%s| \n",p_sys_dl_deal_struct_h_a->h_domcpclt_cd,l_mt_core_sys_params_struct_h.custody_clt_cd);
		if ( strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd, l_mt_core_sys_params_struct_h.custody_clt_cd)
						&& strlen( p_sys_dl_deal_struct_h_a->h_countclt ) )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATA_INTEGRITY,
															"CP Acct Shld Be Null",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
		}
	}	
	}

  	if ( strlen(p_sys_dl_deal_struct_h_a->h_loccode) && 
			(l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'N'))
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr, 
														ERR_DATA_INTEGRITY, 
														p_sys_dl_deal_struct_h_a->h_loccode, 
														APL_NULL_STRING, 
														APL_NULL_STRING, 
														__LINE__, 
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}	
		int_l_error_flg = APL_FAILURE;
	}	

  	if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' )
	{
  		if ( !strlen(p_sys_dl_deal_struct_h_a->h_ispymtlocal) ) 
   	{  
			APL_DATA_MISSING(	"Is Pay Local", 
									APL_NULL_STRING, 
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}

  		if (!strlen(p_sys_dl_deal_struct_h_a->h_reginstr_ind) )
   	{
  			APL_DATA_MISSING(	"Is Reg. Instrurity", 
									APL_NULL_STRING, 
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}

 	 	if (!strlen(p_sys_dl_deal_struct_h_a->h_pos_stat) )
   	{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr, 
															ERR_DEAL_INVALID_POSNTYPE, 
															p_sys_dl_deal_struct_h_a->h_pos_stat, 
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
	else
	{
 	 	if (strlen(p_sys_dl_deal_struct_h_a->h_pos_stat) )
   	{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr, 
															ERR_DATA_INTEGRITY, 
															"Position Status",
															p_sys_dl_deal_struct_h_a->h_pos_stat, 
															APL_NULL_STRING, 
															__LINE__, 
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;
		}
	}	


	printf(" *** cash client before strlen is p_sys_dl_deal_struct_h_a->h_cash_client %s \n",p_sys_dl_deal_struct_h_a->h_cash_client);

/** Changes AmitB:27/09/06:For SplitCR trades:Skip Positon Check **/
  IF_COND_EXISTS("SPLIT_PROCESSING","SPCR_MULTITRD")
  {
    if(strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A)==0 && (strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1)==0 || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND))==0))
	{
		printf("\n Amit:Split/CR Deal .. So skipping CashClient Check \n");
	}
	else
	{
	 if (strlen(p_sys_dl_deal_struct_h_a->h_cash_client))
	 {
		
		
	
			
      	int_l_condexists = 0;
      	if (APL_FAILURE == CO_Chk_CntryEnabled(  "MULTI_CCY",
        	                                     "GL_CLT",
        	                                     &int_l_condexists,
        	                                     l_debug_info_ptr ))
      	{
         	APL_GOBACK_FAIL
      	}

      	if (!int_l_condexists || strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A))
      	{
/*				int_l_exists_flg = 0;
				if (APL_FAILURE == DL_Chk_GLAcc(	p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_cash_client,
															p_sys_dl_deal_struct_h_a->h_currencycode,
															p_sys_dl_deal_struct_h_a->h_dealcd,
															&int_l_exists_flg,
															l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}

				if (!int_l_exists_flg)
				{
					if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr, 
																ERR_INVALID_CASHACC_FORTRD, 
																p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_cash_client, 
																APL_NULL_STRING, 
																__LINE__, 
																__FILE__ ) )
					{
						APL_GOBACK_FAIL;
					}
					int_l_error_flg = APL_FAILURE;
				}
*/			}
		
	}	

	}
  }
  else
  {
   	if (strlen(p_sys_dl_deal_struct_h_a->h_cash_client))
	{
		
		
	
			
      	int_l_condexists = 0;
      	if (APL_FAILURE == CO_Chk_CntryEnabled(  "MULTI_CCY",
        	                                     "GL_CLT",
        	                                     &int_l_condexists,
        	                                     l_debug_info_ptr ))
      	{
         	APL_GOBACK_FAIL
      	}

      	if (!int_l_condexists || strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A))
      	{
/*				int_l_exists_flg = 0;
				if (APL_FAILURE == DL_Chk_GLAcc(	p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_cash_client,
															p_sys_dl_deal_struct_h_a->h_currencycode,
															p_sys_dl_deal_struct_h_a->h_dealcd,
															&int_l_exists_flg,
															l_debug_info_ptr ))
				{
					APL_GOBACK_FAIL
				}

				if (!int_l_exists_flg)
				{
					if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr, 
																ERR_INVALID_CASHACC_FORTRD, 
																p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_cash_client, 
																APL_NULL_STRING, 
																__LINE__, 
																__FILE__ ) )
					{
						APL_GOBACK_FAIL;
					}
					int_l_error_flg = APL_FAILURE;
				}
*/			}
		
	}
	
  }
  
   

printf(" *** cash client after strlen is p_sys_dl_deal_struct_h_a->h_cash_client %s \n",p_sys_dl_deal_struct_h_a->h_cash_client);
	int_l_exists_flg = 0;

	

	if ( APL_FAILURE == CO_RtvSysDt( 	chr_l_sysdate,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	#ifdef EMU_PROCESSING
		if (APL_FAILURE == CO_Chk_EMU_Period( chr_l_sysdate,
														&int_l_exists_flg,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if ( (int_l_exists_flg > 1) && 
			  (!strcmp(p_sys_dl_deal_struct_h_a->h_entry, "S") || 
			  !strcmp(p_sys_dl_deal_struct_h_a->h_entry, "M") ||
           !strcmp(p_intl_env_data_struct_h->h_mode, RPR_MODE)) )
		{
			int_l_exists = 0;
			strcpy(chr_mainfuncarea, APL_NULL_STRING);
      	strcpy(chr_l_condid, APL_NULL_STRING);
      	strcpy(chr_mainfuncarea, "EMUCONV");
      	strcpy(chr_l_condid, "EMU_CCY");

			if ( APL_SUCCESS == CO_Chk_SplVal( chr_mainfuncarea,
                                           chr_l_condid,
                                           p_sys_dl_deal_struct_h_a->h_currencycode,
                                           &int_l_exists,
                                           l_debug_info_ptr ) )
      	{
         	if ( int_l_exists == 0 )
         	{
					if ( CO_InsertErr( l_debug_info_ptr,
                                 ERR_TRDCCY_SHDBERR_EURO,
                                 p_sys_dl_deal_struct_h_a->h_currencycode,
                                 APL_NULL_STRING,
                                 APL_NULL_STRING,
                                 __LINE__,
                                 __FILE__ ) == APL_FAILURE )
            	{
               	APL_GOBACK_FAIL;
            	}
					int_l_error_flg = APL_FAILURE;
				}
			}
			else
			{
				APL_GOBACK_FAIL
			}
		}

		int_l_exists_flg = 0;
		int_l_exists = 0;
	#endif

	

	
	

	if(strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND) )
	{
		strcpy(chr_mainfuncarea, APL_NULL_STRING);
		strcpy(chr_l_condid, APL_NULL_STRING);
		strcpy(chr_mainfuncarea, "TRD_LRTRDTYP");
		strcpy(chr_l_condid, "LRTRDTYP_NOT_NULL");
		int_l_condexists = 0;

		if ( APL_SUCCESS == CO_Chk_CntryEnabled(	chr_mainfuncarea,
															chr_l_condid,
															&int_l_condexists,
															l_debug_info_ptr ) )
		{
			if ( int_l_condexists > 0  && 
				!strlen( p_sys_dl_deal_struct_h_a->h_lrdltype) )
			{
				APL_DATA_MISSING(	"LR Trd Type", 
										APL_NULL_STRING, 
										APL_NULL_STRING );
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			APL_GOBACK_FAIL;
		}
	}

	if ( p_sys_dl_deal_struct_h_a->h_brokercomm < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Broker Commission",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_sys_dl_deal_struct_h_a->h_stx_comm < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Stock Ex. Commission",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}
	
	if ( p_sys_dl_deal_struct_h_a->h_stamp_duty < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Stamp Duty Commission",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}
	
	
	/***Changes start by Rahul for Other charges validate ***/   
	printf("\n BEFORE VALIDATION CALLL----------------RAHUL-----Deal_cd------|%lf|\n", p_sys_dl_deal_struct_h_a-> h_other_charges);
		if ( p_sys_dl_deal_struct_h_a->h_other_charges < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Other Charges Commision",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}
	
	
printf("\nBEFORE FUNCTION CALLL----------------AMOL-----net_amt------|%lf|\n", p_sys_dl_deal_struct_h_a-> h_net_amt);
	printf("\nBEFORE FUNCTION CALLL----------------AMOL-----Deal_cd------|%s|\n", p_sys_dl_deal_struct_h_a-> h_dealcd);

	if (APL_FAILURE == DL_calGrossAmt( p_sys_dl_deal_struct_h_a->h_brokercomm,
									   p_sys_dl_deal_struct_h_a->h_stx_comm,
									   p_sys_dl_deal_struct_h_a->h_stamp_duty,
									   &p_sys_dl_deal_struct_h_a->h_amt,
									   p_sys_dl_deal_struct_h_a-> h_net_amt,
									   p_sys_dl_deal_struct_h_a-> h_dealcd,
									   l_debug_info_ptr ))
	{
		int_l_error_flg = APL_FAILURE;
		/* APL_GOBACK_FAIL Changes done by Dnyanesh to display multiple repair reasons */
	}
	
	printf("\n after FUNCTION CALLL----------------AMOL-----net_amt------%lf\n",p_sys_dl_deal_struct_h_a-> h_net_amt);
	printf("\n after FUNCTION CALLL----------------AMOL-----gross_amt------%lf\n",p_sys_dl_deal_struct_h_a-> h_amt);

printf("\nBEFORE FUNCTION CALLL-----------AMISH----h_brokercomm-------|%lf|\n",p_sys_dl_deal_struct_h_a->h_brokercomm);
printf("\nBEFORE FUNCTION CALLL----------------AMISH--h_stx_comm---------|%lf|\n",p_sys_dl_deal_struct_h_a->h_stx_comm);
printf("\nBEFORE FUNCTION CALLL----------------AMISH-----h_amt------|%lf|\n", p_sys_dl_deal_struct_h_a->h_amt);
printf("\n rahul1 \n");
 fflush(stdout);

/***********ADDED BY AMISH -----------08/05----*/
	if (APL_FAILURE == DL_chk_brkcom_stx( p_sys_dl_deal_struct_h_a->h_brokercomm,
										p_sys_dl_deal_struct_h_a->h_stx_comm,
										 p_sys_dl_deal_struct_h_a->h_amt,
													l_debug_info_ptr ))
	{
		int_l_error_flg = APL_FAILURE;
		/* APL_GOBACK_FAIL Changes done by Dnyanesh to display multiple repair reasons */
	}
   printf("\n rahul \n");
   fflush(stdout);
	
	printf("\n after FUNCTION CALLL----------------AMISH-----h_amt------\n");

	

	if ( p_sys_dl_deal_struct_h_a->h_custodycomm < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Bank Commission",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	if ( p_sys_dl_deal_struct_h_a->h_oth_comm < 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_VALUE_CANT_NEGATIVE,
									"Other Commission",
									APL_NULL_STRING,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ ) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	strcpy(chr_mainfuncarea, APL_NULL_STRING);
	strcpy(chr_l_condid, APL_NULL_STRING);
	strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
	strcpy(chr_l_condid, "CANRECINT000");
	int_l_condexists = 0;

	if ( APL_SUCCESS == CO_Chk_CntryEnabled(	chr_mainfuncarea,
														chr_l_condid,
														&int_l_condexists,
														l_debug_info_ptr ) )
	{
		if ( int_l_condexists > 0  && 
				( p_sys_dl_deal_struct_h_a->h_rec_int_000 > 0 ) )
		{	
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_CANT_RECINT000,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
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
		APL_GOBACK_FAIL;
	}

	if ( ( VAL_FREE_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) ) &&
			( strlen( p_sys_dl_deal_struct_h_a->h_moneydate ) ) )
	{
		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DATA_INTEGRITY,
														"Money Date",
														APL_NULL_STRING,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ) )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}	
/* Kotak Web UAT .. Registration Processing Code is not required ..
	if ( strlen( p_sys_dl_deal_struct_h_a->h_status_reg ) )
	{
		if ( ( VAL_DELIVER_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7') 
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATA_INTEGRITY,
															"Dlvr Trd. Cant Reg",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( !strlen( p_sys_dl_deal_struct_h_a->h_instrdate ) )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATA_INTEGRITY,
															"Not Instr Stl.Cant Reg",
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
*/
	if ( !strcmp(p_intl_env_data_struct_h->h_mode, RPR_MODE) )
	{
		if ( *int_p_trdrepseqnum == 0 )
		{
			APL_DATA_MISSING(	"Sequence Number",
									APL_NULL_STRING,
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}

  		if ( !strlen(p_sys_dl_deal_struct_h_a->h_newdt ) )  
   	{
  			APL_DATA_MISSING(	"Input Date", 
									APL_NULL_STRING, 
									APL_NULL_STRING );
			int_l_error_flg = APL_FAILURE;
		}	 
	}

 /**Changes Start by RAHUL For CSGL deal Valiadtion Ignore INVALID instrument ***/

     int_ret_val = chkAllowForSellCsgl(p_sys_dl_deal_struct_h_a, l_debug_info_ptr);
     if(!strcmp(p_sys_dl_deal_struct_h_a->h_loccode,"CSGL") && !int_ret_val)
     {
		 printf("\n Inside VALIDATION CALLL------ RAHUL-----int_ret_val------|%d|\n", int_ret_val);
	    if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_CSGL_INSTR_NOT_VALID,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{

				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;	  
     }

/**Changes Start by RAHUL For CSGL deal Valiadtion Ignore to On Market deal ***/
/*   commented for transfer position sit issue
   if((strcmp(p_sys_dl_deal_struct_h_a->h_loccode,"CSGL")==0) && (strcmp(p_sys_dl_deal_struct_h_a->h_trd_exch,APL_NULL_STRING)) && (strcmp(p_sys_dl_deal_struct_h_a->h_exch_code,APL_NULL_STRING)) && strlen(p_sys_dl_deal_struct_h_a->h_settlement_no))
    {	
       printf("\n After VALIDATION new CALLL-----RAHUL-----Location_cd------|%s|\n", p_sys_dl_deal_struct_h_a-> h_loccode);
	   		if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_CSGL_ONMARKET,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
   
				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;

	}
 */	
	/**Changes Start by RAHUL For CSGL deal Valiadtion Ignore to dela_code(1,2) **/   
	printf("\nBEFORE VALIDATION CALLL----RAHUL---Deal_cd------|%s|\n", p_sys_dl_deal_struct_h_a-> h_dealcd);
	/*
	if((!strcmp(p_sys_dl_deal_struct_h_a->h_loccode,"CSGL")) && (!strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"1") || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"2" )))
    {
		printf("\n INSIDE VALIDATION CALLL----------------RAHUL-----Deal_cd------|%s|\n", p_sys_dl_deal_struct_h_a-> h_dealcd);
		if( CO_InsertErr(l_debug_info_ptr,
                   	    ERR_CSGL_DLCD_NOT_ALLOWED,
						p_sys_dl_deal_struct_h_a->h_dl_client,
						APL_NULL_STRING,
						APL_NULL_STRING,
						__LINE__,
						__FILE__)==APL_FAILURE )
			{
				printf("\n INSIDE ERR_CSGL_DLCD_NOT_ALLOWED|%s|\n", p_sys_dl_deal_struct_h_a-> h_loccode);
				APL_GOBACK_FAIL
			}
			
		int_l_error_flg = APL_FAILURE;
	}
	*/
	if (strlen(p_sys_dl_deal_struct_h_a->h_locindentity_no))
	{
		strcpy(chr_mainfuncarea, APL_NULL_STRING);
   	strcpy(chr_l_condid, APL_NULL_STRING);
   	strcpy(chr_mainfuncarea, "BOGTXN");
   	strcpy(chr_l_condid, "LOC");
   	int_l_condexists = 0;

   	if ( APL_SUCCESS == CO_Chk_SplVal( chr_mainfuncarea,
     	                                       chr_l_condid,
															p_sys_dl_deal_struct_h_a->h_loccode,
                                             &int_l_exists_flg,
                                          	l_debug_info_ptr ) )
   	{
      	if ( int_l_exists_flg > 0)
			{
				if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
				{
						if(!strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND) )
						{
							if (!(  
								strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd,l_mt_core_sys_params_struct_h.vtb_clt_code)  &&
								((!strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd,l_mt_core_sys_params_struct_h.custody_clt_cd) && (!strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"1") || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"3" ) || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"5") || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"7" )) ) 
								|| ( strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd,l_mt_core_sys_params_struct_h.custody_clt_cd) && ( !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"2") || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"4")  || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"6") || !strcmp(p_sys_dl_deal_struct_h_a->h_dealcd,"8"))) ) 
							)
							)
							
							 
							 strcpy(p_sys_dl_deal_struct_h_a->h_locindentity_no,APL_NULL_STRING);
						}
				}
			}
			else
				if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT) && 
						!strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND) )
							 strcpy(p_sys_dl_deal_struct_h_a->h_locindentity_no,APL_NULL_STRING);
					
		}
   	else
		{
			APL_GOBACK_FAIL;
		}
	}


	IF_COND_EXISTS("DL_DEAL","BROKERNO")
	{	
	if (!strlen(p_sys_dl_deal_struct_h_a->h_brkrno ) )
	{
		strcpy(chr_mainfuncarea, APL_NULL_STRING);
   	strcpy(chr_l_condid, APL_NULL_STRING);
   	strcpy(chr_mainfuncarea, "TRADE_MAINT");
   	strcpy(chr_l_condid, "TRD_BOGTXNCODE");
   	int_l_condexists = 0;

   	if ( APL_SUCCESS == CO_Chk_CntryEnabled( chr_mainfuncarea,
     	                                       chr_l_condid,
                                             &int_l_condexists,
                                          	l_debug_info_ptr ) )
   	{
      	if ( int_l_condexists > 0)
			{
				if(!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_INPUT))
				{
						if(!strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND) )
							 strcpy(p_sys_dl_deal_struct_h_a->h_brkrno,MS_SWIFT_BOGNO_0731);
						else
						{
        					APL_DATA_MISSING( "Bog Txn Code",
                    	       				APL_NULL_STRING,
                           				APL_NULL_STRING );
				
							int_l_error_flg = APL_FAILURE;
						}
				}
				if (!strcmp(p_intl_env_data_struct_h->h_mode,APL_FUNC_MODIFY)||
						  !strcmp(p_intl_env_data_struct_h->h_mode,RPR_MODE) )
				{
				 	APL_DATA_MISSING("Bog Txn Code",
           								APL_NULL_STRING,
           								APL_NULL_STRING );

         		int_l_error_flg = APL_FAILURE;
			 	} 
			}
		}
   	else
		{
			APL_GOBACK_FAIL;
		}
	}
	}

/* Validation of instrument code & broker code is already present.. here it is again repeated */
 if (strlen(p_sys_dl_deal_struct_h_a->h_instr_code) != 0)
	{
	if ( APL_FAILURE == CO_Chk_InstrValid(	p_sys_dl_deal_struct_h_a->h_instr_code, 
												'Y', 'Y', 'N', 'N', 
												NULL, NULL, 
												l_debug_info_ptr ) )
   {
      int_l_error_flg = APL_FAILURE;
   }
	}

/* Changes identified during WEB UAT. Deal Instruction with Unauthorized broker code should not STP with status 'AA' */
/* Changed by Dnyanesh 28/04/2007 Issue Log No. 148 */

 if (strlen(p_sys_dl_deal_struct_h_a->h_domcpclt_cd) != 0)
	{
 /*if (strcmp(p_sys_dl_deal_struct_h_a->h_entry, "W") == 0) Commented BY Kalyan ... We need to validate broker code irrespective of Entry Type */
	{
 	printf("\n Now validating domcpac for deal |%s| \n",p_sys_dl_deal_struct_h_a->h_domcpclt_cd);

 	if (APL_SUCCESS != MT_Chk_PtyVal    (  p_sys_dl_deal_struct_h_a->h_domcpclt_cd,
                                       "B",
                                       'Y',
                                       'Y',
                                       'N',
                                       l_debug_info_ptr))
		{
			printf("\n Domcpac is not valid ...\n");		
      int_l_error_flg = APL_FAILURE;
		}
	}	
 }

  	if (APL_FAILURE == int_l_error_flg)
	{
		 APL_GOBACK_FAIL;
 	}

	if ( !strcmp(APL_FUNC_MODIFY, p_intl_env_data_struct_h->h_mode) )
	{
		

		strcpy(chr_l_fieldname, "rowid");
		if ( APL_FAILURE == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														chr_l_rowid_A, 
														l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}

		
	
		strcpy(chr_l_fieldname, "access_stamp");
		//ADDED BY USMAN FOR ACCESS SKIP FOR API CALL
		if(strcmp(p_sys_dl_deal_struct_h_a->h_checker,"SYSTEM"))
		if ( APL_SUCCESS == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														chr_l_access_stamp, 
														l_debug_info_ptr) )
		{
			if ( strcmp(p_sys_dl_deal_struct_h_a->h_access_stamp, chr_l_access_stamp ) )
			{
				CO_InsertErr(	l_debug_info_ptr, 
										ERR_ACCESSSTAMP_CHGD, 
										p_sys_dl_deal_struct_h_a->h_dl_client, 
										p_sys_dl_deal_struct_h_a->h_indentity_no, 
										APL_NULL_STRING, 
										__LINE__, 
										__FILE__ );	
				APL_GOBACK_FAIL;
			}
		}
		else
		{
			APL_GOBACK_FAIL;
		}

	}

	if ( !strcmp(RPR_MODE, p_intl_env_data_struct_h->h_mode) )
	{
		
	
		strcpy(chr_l_fieldname, APL_NULL_STRING );
		strcpy(chr_l_fieldname, "access_stamp");

		if ( APL_FAILURE == DL_Rtv_TrdRprChrVal(	int_p_trdrepseqnum, 
															chr_l_fieldname, 
															chr_l_access_stamp, 
															l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}
	}

	

	if ( !strcmp( p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT ) || 
			!strcmp( p_intl_env_data_struct_h->h_mode, RPR_MODE ) ) 
	{
		if ( APL_FAILURE == DL_Chk_DLDet(	p_sys_dl_deal_struct_h_a->h_dl_client, 
													p_sys_dl_deal_struct_h_a->h_indentity_no, 
													'N', NULL,NULL, NULL, NULL, NULL, NULL, NULL, 
													l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;	
		}
	}
	else if ( !strcmp( p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY ) )
	{
		if(   (  !strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"17") ||
					!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"19") ||
					!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"18") ||
					!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"20") )&& (strlen(p_sys_dl_deal_struct_h_a-> h_indentity_no) > 5))
		{
			if(Rtv_Evt_Type(  p_sys_dl_deal_struct_h_a-> h_indentity_no,
						l_evt_type,
						l_op_evt_type,
						l_debug_info_ptr) == APL_FAILURE)
			{
				Alert("Failed In Rtv_Evt_Type");
			}
			Alert("Deal Code|%s|evet |%s| Op |%s|",p_sys_dl_deal_struct_h_a-> h_classofdl,l_evt_type,l_op_evt_type)
			if(strcmp(l_evt_type,"SP")==0)
			{

					if ( APL_FAILURE == DL_Chk_DLDet(	p_sys_dl_deal_struct_h_a->h_dl_client, 
													p_sys_dl_deal_struct_h_a->h_indentity_no, 
													'Y', NULL,'N', 'Y', 'N', 
													NULL, NULL, NULL, 
													l_debug_info_ptr) )
					{
					APL_GOBACK_FAIL;
					}	
			}
			if(strcmp(l_evt_type,"CR")==0)
			{

					if ( APL_FAILURE == DL_Chk_DLDet(	p_sys_dl_deal_struct_h_a->h_dl_client, 
													p_sys_dl_deal_struct_h_a->h_indentity_no, 
													'Y', NULL,'N', 'Y', 'N', 
													NULL, NULL, NULL, 
													l_debug_info_ptr) )
					{
					APL_GOBACK_FAIL;
					}	
			}
		}
		else
		{
		if ( APL_FAILURE == DL_Chk_DLDet(	p_sys_dl_deal_struct_h_a->h_dl_client, 
													p_sys_dl_deal_struct_h_a->h_indentity_no, 
													'Y', NULL,'N', 'N', 'N', 
													NULL, NULL, NULL, 
													l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}	
	}
	}


	/*************OVERRIDE CHK********************************/
	/*
	if ( !strcmp( p_intl_env_data_struct_h->h_mode, APL_FUNC_AUTHORISE ))
		{
	
			if(!strcmp(p_sys_dl_deal_struct_h_a->h_interfii_flg,APL_INTER_FII_IND))
			{	
				strcpy(chr_l_fieldname, "INSTR_CODE");
				if ( APL_FAILURE == DL_Chk_OverRide(p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_indentity_no, 
																chr_l_fieldname, 
																chr_l_interfii, 
																l_debug_info_ptr) )
				{
					int_l_error_flg = APL_FAILURE;
				}
			}
		}
	*/
	/*************OVERRIDE CHK********************************/
	
	if ( p_sys_dl_deal_struct_h_a->h_dlfromord[0] == 'Y' )
	{
		if ( APL_FAILURE == CO_Chk_AccValid(	p_sys_dl_deal_struct_h_a->h_dl_client, 
													'Y', 'C', 'B', NULL, 'Y', 'N', 
													'N', 'N', 
													l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}
   }
   else if (p_intl_env_data_struct_h->h_process[0] == 'S')
   {
       if ( APL_FAILURE == CO_Chk_AccValid(   p_sys_dl_deal_struct_h_a->h_dl_client,
                                       'Y', 'C', 'C', NULL,'Y', 'N',
                                       'N', 'N',
                                       l_debug_info_ptr ) )
      {
         int_l_error_flg = APL_FAILURE;
      }
	}
	else
	{
		if (strcmp(p_sys_dl_deal_struct_h_a->h_entry,SYSTEM_GEN_DEAL_IND)==0)
		{
			//Changed by Swapnil for freezed client  isolve ISKB-2188   //
			if ( APL_FAILURE == CO_Chk_AccValid_CA(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														'Y','C',NULL,NULL,'Y','N',
														'N','N',
														l_debug_info_ptr))
			{
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			if ( APL_FAILURE == CO_Chk_AccValid(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														'Y', 'C', 'C', NULL, 'Y', 'N', 
														'N', 'N', 
														l_debug_info_ptr ) )
			{
				int_l_error_flg = APL_FAILURE;
			}
		}
	}

	
	IF_COND_EXISTS("DL_DEAL","DOMCPAC")
	{

		if ( APL_FAILURE == CO_Chk_AccValid(	p_sys_dl_deal_struct_h_a->h_domcpclt_cd, 
													'Y', 'B', NULL, NULL, 'Y', 'N', 
													'N', 'N', 
													l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}


	


		if ( APL_FAILURE == CO_Chk_AccValid(	p_sys_dl_deal_struct_h_a->h_domcp_custodyclt, 
													'Y', 'B', NULL, NULL, 'Y', 'N', 
													'N', 'N', 
													l_debug_info_ptr ) )
		{
			int_l_error_flg = APL_FAILURE;
		}


	

	if((l_ext_trd_check==0) || (strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd, l_mt_core_sys_params_struct_h.custody_clt_cd)==0))
	{
		if ( strcmp(p_sys_dl_deal_struct_h_a->h_countclt, APL_NULL_STRING) )
		{
			if ( APL_FAILURE == CO_Chk_AccValid(	p_sys_dl_deal_struct_h_a->h_countclt, 
														'Y', 'C', 'C', NULL, 'Y', 'N', 
														'N', 'N', 
														l_debug_info_ptr ) )
			{
				int_l_error_flg = APL_FAILURE;
			}
		}
	}

   

   if ( strcmp(p_sys_dl_deal_struct_h_a->h_clientofcode, APL_NULL_STRING) 	&& (strcmp(p_sys_dl_deal_struct_h_a->h_domcpclt_cd,l_mt_core_sys_params_struct_h.custody_clt_cd)==0 ))
   {
      if ( APL_FAILURE == CO_Chk_AccValid( p_sys_dl_deal_struct_h_a->h_clientofcode,
                                       'Y', NULL,NULL,NULL,'Y', 'N',
                                       'N', 'N',
                                       l_debug_info_ptr ) )
      {
         int_l_error_flg = APL_FAILURE;
      }
   }

	
	}

	if ( APL_FAILURE == CO_Chk_InstrValid(	p_sys_dl_deal_struct_h_a->h_instr_code, 
												'Y', 'Y', 'N', 'N', 
												NULL, NULL, 
												l_debug_info_ptr ) )
   {
      int_l_error_flg = APL_FAILURE;
   }

/* Changes identified during WEB UAT. Deal Instruction with Unauthorized broker code should not STP with status 'AA' */
/* Changed by Dnyanesh 28/04/2007 Issue Log No. 148 */

 if (strcmp(p_sys_dl_deal_struct_h_a->h_entry, "W") == 0)
	{
 	printf("\n Now validating domcpac for web deal |%s| \n",p_sys_dl_deal_struct_h_a->h_domcpclt_cd);

 	if (APL_SUCCESS != MT_Chk_PtyVal    (  p_sys_dl_deal_struct_h_a->h_domcpclt_cd,
                                       "B",
                                       'Y',
                                       'Y',
                                       'N',
                                       l_debug_info_ptr))
		{
			printf("\n Domcpac is not valid ...\n");		
 		APL_GOBACK_FAIL
		}
	}	

	if ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' )
	{
		if ( APL_FAILURE == MT_Chk_Loc(	p_sys_dl_deal_struct_h_a->h_loccode, 
													'Y', 'Y', 'N', 
													l_debug_info_ptr ) )
   	{
      	int_l_error_flg = APL_FAILURE;
   	}
	}

	

	if ( APL_FAILURE == CO_Chk_CcyValid(	p_sys_dl_deal_struct_h_a->h_currencycode,
												'M', 'Y', 
												l_debug_info_ptr) )
	{
		int_l_error_flg = APL_FAILURE;
	}

	

	

   
   
   

   
	


	

	if ( (VAL_FREE_DEAL(p_sys_dl_deal_struct_h_a->h_dealcd[0]) ) &&
		  (p_sys_dl_deal_struct_h_a->h_isspotdl[0] == 'Y') )
	{
		if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
														ERR_DEAL_FREETDL_CANT_SPOTDEAL,
														p_sys_dl_deal_struct_h_a->h_dl_client,
														p_sys_dl_deal_struct_h_a->h_indentity_no,
														APL_NULL_STRING,
														__LINE__,
														__FILE__ ))
		{
			APL_GOBACK_FAIL
		}
		int_l_error_flg = APL_FAILURE;
	}


	

	if ( l_mt_core_sys_params_struct_h.proc_spot_dl_ind[0] == 'Y' )
	{
		strcpy(chr_l_fieldname, "spottrdflg");
		if ( APL_SUCCESS == MT_Rtv_AccFldVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															chr_l_fieldname, 
															chr_l_accspottrdflg, 
															l_debug_info_ptr ) )
		{
			if ( ( chr_l_accspottrdflg[0] ==  'N' ) && 
					( p_sys_dl_deal_struct_h_a->h_isspotdl[0] == 'Y') )
			{
				if ( CO_InsertErr(	l_debug_info_ptr, 
											ERR_SPOTTRD_NOTALLOWED_FORACC, 
											p_sys_dl_deal_struct_h_a->h_dl_client, 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__ ) == APL_FAILURE )
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			APL_GOBACK_FAIL;
		}
	} 	

	

	if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' )
	{

		

		strcpy(chr_l_fieldname, "canregflg");
		if ( APL_SUCCESS == MT_Rtv_AccFldVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															chr_l_fieldname, 
															chr_l_canreg, 
															l_debug_info_ptr ) )
		{
			if ( ( chr_l_canreg[0] == 'N') && 
						( strcmp(p_sys_dl_deal_struct_h_a->h_pos_stat, "000") && 
							strcmp(p_sys_dl_deal_struct_h_a->h_pos_stat, "001") ) )
			{
				if ( CO_InsertErr(	l_debug_info_ptr, 
											ERR_ACCOUNT_CANT_REGSTR, 
											p_sys_dl_deal_struct_h_a->h_dl_client, 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__ ) == APL_FAILURE )
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			APL_GOBACK_FAIL;
		}

	

		strcpy(chr_l_fieldname, "regbrind");
		if ( APL_SUCCESS == CR_Rtv_InstrChrVal(	p_sys_dl_deal_struct_h_a->h_instr_code, 
														chr_l_fieldname, 
														chr_l_regbrind, 
														l_debug_info_ptr ) )
		{
			if ( !strcmp(chr_l_regbrind, "RG")  &&  
					(p_sys_dl_deal_struct_h_a->h_reginstr_ind[0] == 'N' ) )
			{
				if ( CO_InsertErr(	l_debug_info_ptr, 
											ERR_REGDINSTR, 
											p_sys_dl_deal_struct_h_a->h_instr_code, 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__ ) == APL_FAILURE )
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}

			if ( !strcmp(chr_l_regbrind, "BR")  &&  
							( p_sys_dl_deal_struct_h_a->h_reginstr_ind[0] == 'Y' ) )
			{
				if ( CO_InsertErr(	l_debug_info_ptr, 
											ERR_NOTREGDINSTR, 
											p_sys_dl_deal_struct_h_a->h_instr_code, 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__ ) == APL_FAILURE )
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}

			if ( !strcmp(chr_l_regbrind, "BR")  &&  
							strcmp(p_sys_dl_deal_struct_h_a->h_pos_stat, "000") )
			{
				if ( CO_InsertErr(	l_debug_info_ptr, 
											ERR_DEAL_INVALID_POSNTYPE, 
											p_sys_dl_deal_struct_h_a->h_pos_stat, 
											APL_NULL_STRING, 
											APL_NULL_STRING, 
											__LINE__, 
											__FILE__ ) == APL_FAILURE )
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}
		}
		else
		{
			APL_GOBACK_FAIL;
		}

		
	
		if ( ( !strcmp(p_sys_dl_deal_struct_h_a->h_pos_stat, "002") ) && 
					( VAL_DELIVER_DEAL(p_sys_dl_deal_struct_h_a->h_dealcd[0]) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7') ) 
		{
			if ( CO_InsertErr(	l_debug_info_ptr, 
										ERR_DEAL_INVALID_POSNTYPE, 
										p_sys_dl_deal_struct_h_a->h_pos_stat, 
										APL_NULL_STRING, 
										APL_NULL_STRING, 
										__LINE__, 
										__FILE__ ) == APL_FAILURE )
			{
				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;
		}
	}

	

	if ( APL_SUCCESS == DL_Chk_TrCdInstr(	p_sys_dl_deal_struct_h_a->h_instr_code, 
													p_sys_dl_deal_struct_h_a->h_dealcd[0], 
													&chr_l_trcodeinstrflg[0], 
													l_debug_info_ptr ) )
	{
		if ( chr_l_trcodeinstrflg[0] == 'N' ) 
		{
			if ( CO_InsertErr(	l_debug_info_ptr, 
										ERR_DEAL_DEALTYP_NVALFORINSTR_A, 
										p_sys_dl_deal_struct_h_a->h_dealcd, 
										p_sys_dl_deal_struct_h_a->h_instr_code, 
										APL_NULL_STRING, 
										__LINE__, 
										__FILE__ ) == APL_FAILURE )
			{
				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;
		}
	}
	else
	{
		APL_GOBACK_FAIL;
 	}	



	strcpy(chr_mainfuncarea, APL_NULL_STRING);
	strcpy(chr_l_condid, APL_NULL_STRING);
	strcpy(chr_mainfuncarea, "TRD_LOCREFNO"); 
	

	strcpy(chr_l_condid, "LOCREFNO_NOT_NULL");
	int_l_condexists = 0;

	if ( APL_SUCCESS == CO_Chk_CntryEnabled(	chr_mainfuncarea, 
														chr_l_condid, 
														&int_l_condexists, 
														l_debug_info_ptr ) )
	{
		if ( int_l_condexists > 0 && !strlen(p_sys_dl_deal_struct_h_a->h_locindentity_no) )     
		{
			if ( CO_InsertErr(	l_debug_info_ptr, 
										ERR_DEAL_LOCREFNO_CANTEMPTY, 
										APL_NULL_STRING, 
										APL_NULL_STRING, 
										APL_NULL_STRING, 
										__LINE__, 
										__FILE__ ) == APL_FAILURE )
			{
				APL_GOBACK_FAIL;
			}	
			int_l_error_flg = APL_FAILURE;
		}
	}
	else
	{
		APL_GOBACK_FAIL;
	} 

	

	if (APL_FAILURE == CR_Rtv_InstrChrVal(	p_sys_dl_deal_struct_h_a->h_instr_code,
													"typeofinstr",
													chr_l_typeofinstr,
													l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	if (!strcmp(chr_l_typeofinstr, "FMT"))
	{
		if (APL_FAILURE == CR_Rtv_InstrNumVal(	p_sys_dl_deal_struct_h_a->h_instr_code,
														"minfmttrdqty",
														&l_minfmttrdquantity,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

		if (p_sys_dl_deal_struct_h_a->h_qty < l_minfmttrdquantity)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_QTY_CANT_LESS_MINFINQTY,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															p_sys_dl_deal_struct_h_a->h_instr_code,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE; 
		}
	}

	strcpy(chr_mainfuncarea, APL_NULL_STRING);
	strcpy(chr_l_condid, APL_NULL_STRING);
	strcpy(chr_mainfuncarea, "TRD_LOCREFNO");
	strcpy(chr_l_condid, "LOCREFNO_UNIQUE");
	int_l_condexists = 0;

	if ( APL_SUCCESS == CO_Chk_CntryEnabled(	chr_mainfuncarea, 
														chr_l_condid, 
														&int_l_condexists, 
														l_debug_info_ptr ) )
	{
		if ( int_l_condexists > 0 && strlen(p_sys_dl_deal_struct_h_a->h_locindentity_no) && (strcmp(p_sys_dl_deal_struct_h_a->h_entry,"S") != 0) )     
		{
			if ( APL_SUCCESS == DL_Chk_LRRefTrd(	p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_indentity_no,
																p_sys_dl_deal_struct_h_a->h_locindentity_no,
															 	&l_locrefexists, 
																l_debug_info_ptr) )
			{
				if ( l_locrefexists > 0 )
				{
					if ( CO_InsertErr(	l_debug_info_ptr, 
												ERR_DEAL_LOCREFNO_EXIST, 
												p_sys_dl_deal_struct_h_a->h_locindentity_no, 
												APL_NULL_STRING, 
												APL_NULL_STRING, 
												__LINE__, 
												__FILE__ ) == APL_FAILURE )
					{
						APL_GOBACK_FAIL;
					}	
					int_l_error_flg = APL_FAILURE;
				}	
			}
			else
			{
				APL_GOBACK_FAIL;
			}
		}
	}
	else
	{
		int_l_error_flg = APL_FAILURE;
	} 

	



		

	
	int_l_condexists = 0;
   if (APL_FAILURE == CO_Chk_CntryEnabled(  "INCOMING_MSG",
                                          "TRDT_CAN_BE_FUTURE",
                                          &int_l_condexists,
                                          l_debug_info_ptr ))
   {
      APL_GOBACK_FAIL
   }

   if (!int_l_condexists)
   {

		int_l_datecmp = 0;
		if ( APL_SUCCESS == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_dlt,
														chr_l_sysdate,
														&int_l_datecmp,
														l_debug_info_ptr ) )
		{
			if ( int_l_datecmp < 0 )
			{
				if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_DLDT_CANT_FUTURE,
															p_sys_dl_deal_struct_h_a->h_dlt,
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
		else
		{
			APL_GOBACK_FAIL;
		} 
	}


	

	int_l_datecmp = 0;
	if ( APL_SUCCESS == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_dlt,
													p_sys_dl_deal_struct_h_a->h_setldt,
													&int_l_datecmp,
													l_debug_info_ptr ) )
	{
		if ( int_l_datecmp < 0 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_CSD_CANT_BEFORE_DEALDT,
															p_sys_dl_deal_struct_h_a->h_dlt,
															p_sys_dl_deal_struct_h_a->h_setldt,
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
		APL_GOBACK_FAIL;
	}

	
	/*Added by Prateek on 16062014 For ISKB_6755(Unable to settle trades prior to one year)-START*/
	/*Country condition added to exclude this part while doing Partial Prematch*/
	int_l_condexists = 0;
	if (APL_FAILURE == CO_Chk_CntryEnabled(	"TRDT_PRIOR_1YEAR",
											"TRDT_CANT_BE_PRIOR_1YEAR",
											&int_l_condexists,
											l_debug_info_ptr ))
		{
		APL_GOBACK_FAIL
		}

	if (int_l_condexists)
	{
	/*Added by Prateek on 16062014 For ISKB_6755(Unable to settle trades prior to one year)-END*/
	int_l_datecmp = 0;
	if ( APL_SUCCESS == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_dlt,
													chr_l_sysdate,
													&int_l_datecmp,
													l_debug_info_ptr ) )
	{
		if ( int_l_datecmp > 365 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_TRDDT_CANT_LESS_1YR,
															p_sys_dl_deal_struct_h_a->h_dlt,
															chr_l_sysdate,
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
		APL_GOBACK_FAIL;
	}

	int_l_datecmp = 0;
	if ( APL_SUCCESS == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_setldt,
													chr_l_sysdate,
													&int_l_datecmp,
													l_debug_info_ptr ) )
	{
		if ( int_l_datecmp > 365 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_SETTLEDT_CANT_LESS_1YR,
															p_sys_dl_deal_struct_h_a->h_setldt,
															chr_l_sysdate,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}
		else if ( int_l_datecmp < -365 )
		{
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_SETTLEDT_CANT_LATER_1YR,
															p_sys_dl_deal_struct_h_a->h_setldt,
															chr_l_sysdate,
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
		APL_GOBACK_FAIL;
	}

	/*Added by Prateek on 16062014 For ISKB_6755(Unable to settle trades prior to one year)-START*/
	}
	/*Added by Prateek on 16062014 For ISKB_6755(Unable to settle trades prior to one year)-END*/



	

	if ( strlen(p_sys_dl_deal_struct_h_a->h_confdate) )
	{
		int_l_datecmp = 0;
		if ( APL_SUCCESS == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_dlt,
														p_sys_dl_deal_struct_h_a->h_confdate,
														&int_l_datecmp,
														l_debug_info_ptr ) )
		{
			if ( int_l_datecmp < 0 )
			{
				if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_CONFDT_NO_DEALDT,
																p_sys_dl_deal_struct_h_a->h_dlt,
																p_sys_dl_deal_struct_h_a->h_confdate,
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
			APL_GOBACK_FAIL;
		}
	}

	if ( 	strlen( p_sys_dl_deal_struct_h_a->h_instrdate) ||
			strlen(p_sys_dl_deal_struct_h_a->h_moneydate) ||
			strlen(p_sys_dl_deal_struct_h_a->h_delrecdate) ||
			strlen(p_sys_dl_deal_struct_h_a->h_tmpoutdate) ||
			strlen(p_sys_dl_deal_struct_h_a->h_tmpretdate) )
	{

   l_ru_exists = 0 ;

   if(CO_Chk_CntryEnabled("PAY_PROC","RUSTAT_TRDAUTH",&l_ru_exists,l_debug_info_ptr)==APL_FAILURE)
    APL_GOBACK_FAIL
      if(CO_Rtv_FldValChar("cln_clas", "mt_client", "cln_code",
                             p_sys_dl_deal_struct_h_a->h_dl_client,
                             chr_l_acc_class,
                             l_debug_info_ptr) == APL_FAILURE)
      {
        APL_GOBACK_FAIL;
      }	

   if( (l_ru_exists>0) && !(strncmp(chr_l_acc_class,"2",1)) )
   {
	}
	else
	{
		if ( !strlen( p_sys_dl_deal_struct_h_a->h_confdate ) )
		{
			CO_InsertErr(	l_debug_info_ptr,
									ERR_DEAL_NCONF,
									p_sys_dl_deal_struct_h_a->h_dl_client,
									p_sys_dl_deal_struct_h_a->h_indentity_no,
									APL_NULL_STRING,
									__LINE__,
									__FILE__ );

			APL_GOBACK_FAIL;
		}
	}
	}

	if ( l_mt_core_sys_params_struct_h.manifld_print_ind[0] == 'Y' )
	{
		

		if ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' )
		{
			if ( APL_FAILURE == CO_Rtv_FldValChar(	"manifld_ind",
																"mt_location", 
																"location_cd",
																p_sys_dl_deal_struct_h_a->h_loccode,
																chr_l_manifldflg,
																l_debug_info_ptr ) )
			{		
				APL_GOBACK_FAIL;
			}

			if ( chr_l_manifldflg[0] == 'N' )
			{
				if ( ( strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) ) ||
					  ( strlen( p_sys_dl_deal_struct_h_a->h_tmpoutdate ) ) ||
					  ( strlen( p_sys_dl_deal_struct_h_a->h_tmpretdate ) ) )
				{	
					if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
																	ERR_DEAL_MANI_NOT_REQD,
																	APL_NULL_STRING,
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
			else
			{
				strcpy(chr_mainfuncarea, APL_NULL_STRING);
				strcpy(chr_l_condid, APL_NULL_STRING);
				strcpy(chr_mainfuncarea, "TRD_MANIFOLD");
				strcpy(chr_l_condid, "MANI_NOTREQD_FOR_MIN");
				int_l_condexists = 0;
	
				if ( APL_FAILURE == CO_Chk_CntryEnabled(	chr_mainfuncarea,
																	chr_l_condid,
																	&int_l_condexists,
																	l_debug_info_ptr ) )
				{	
					APL_GOBACK_FAIL;
				}

				strcpy(chr_l_fieldname, "clscode");
				if ( APL_FAILURE == CR_Rtv_InstrChrVal(	p_sys_dl_deal_struct_h_a->h_instr_code, 
																chr_l_fieldname, 
																chr_l_clscode_a, 
																l_debug_info_ptr ) )
				{	
					APL_GOBACK_FAIL;
				}

				if ( ( !strcmp(chr_l_clscode_a, "MIN") && int_l_condexists > 0 )
							&& strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) )
				{
					if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
																	ERR_DEAL_MANI_NOT_REQD,
																	APL_NULL_STRING,
																	APL_NULL_STRING,
																	APL_NULL_STRING,
																	__LINE__,
																	__FILE__ ) )
					{
						APL_GOBACK_FAIL;
					}
					int_l_error_flg = APL_FAILURE;
				}

				if ( ( ( !strcmp( chr_l_clscode_a, "MIN" ) &&
								int_l_condexists == 0 ) ||
					  ( strcmp( chr_l_clscode_a, "MIN" ) ) ) &&
				  	  ( !strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) && 
								strlen( p_sys_dl_deal_struct_h_a->h_instrdate ) ) )
				{
					if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
																	ERR_DEAL_MANIFLD_NPRINT,
																	APL_NULL_STRING,
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
		}
		else
		{
			strcpy(chr_mainfuncarea, APL_NULL_STRING);
			strcpy(chr_l_condid, APL_NULL_STRING);
			strcpy(chr_mainfuncarea, "TRD_MANIFOLD");
			strcpy(chr_l_condid, "MANI_NOTREQD_FOR_MIN");
			int_l_condexists = 0;
	
			if ( APL_FAILURE == CO_Chk_CntryEnabled(	chr_mainfuncarea,
																chr_l_condid,
																&int_l_condexists,
																l_debug_info_ptr ) )
			{
				APL_GOBACK_FAIL;
			}

			strcpy(chr_l_fieldname, "clscode");
			if ( APL_FAILURE == CR_Rtv_InstrChrVal(	p_sys_dl_deal_struct_h_a->h_instr_code, 
															chr_l_fieldname, 
															chr_l_clscode_a, 
															l_debug_info_ptr ) )
			{		
				APL_GOBACK_FAIL;
			}

			if ( ( !strcmp(chr_l_clscode_a, "MIN") && int_l_condexists > 0 )
						&& strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) )
			{
				if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
																ERR_DEAL_MANI_NOT_REQD,
																APL_NULL_STRING,
																APL_NULL_STRING,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ) )
				{
					APL_GOBACK_FAIL;
				}
				int_l_error_flg = APL_FAILURE;
			}


			if ( ( ( !strcmp( chr_l_clscode_a, "MIN" ) && int_l_condexists == 0 ) ||
				  ( strcmp( chr_l_clscode_a, "MIN" ) ) ) &&
					( !strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) && 
						strlen( p_sys_dl_deal_struct_h_a->h_instrdate ) ) )
			{	
				if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
																ERR_DEAL_MANIFLD_NPRINT,
																APL_NULL_STRING,
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

		if ( ( VAL_DELIVER_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7') &&
				( strlen( p_sys_dl_deal_struct_h_a->h_tmpoutdate ) || 
					strlen( p_sys_dl_deal_struct_h_a->h_tmpretdate ) ) )
		{	
			if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_NVAL_TKTTYP,
															"Deliver Trade",
															APL_NULL_STRING,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ) )
			{
				APL_GOBACK_FAIL;
			}
		}
	}
	else
	{
		if	(	( strlen( p_sys_dl_deal_struct_h_a->h_delrecdate ) ) ||
				( strlen( p_sys_dl_deal_struct_h_a->h_tmpoutdate ) ) ||
				( strlen( p_sys_dl_deal_struct_h_a->h_tmpretdate ) ) )
		{
			if ( APL_FAILURE == CO_InsertErr( l_debug_info_ptr,
															ERR_DEAL_MANI_NOT_REQD,
															APL_NULL_STRING,
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


	if ( strlen(p_sys_dl_deal_struct_h_a->h_instrdate) || strlen(p_sys_dl_deal_struct_h_a->h_moneydate) )
	{
		

		strcpy(chr_mainfuncarea, APL_NULL_STRING);
		strcpy(chr_l_condid, APL_NULL_STRING);
		strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
		strcpy(chr_l_condid, "CSD>TODAY_OK");	
		int_l_condexists = 0;

		if (APL_FAILURE == CO_Chk_CntryEnabled(	chr_mainfuncarea,
															chr_l_condid,
															&int_l_condexists,
															l_debug_info_ptr ))
		{	
			APL_GOBACK_FAIL;
		}

		int_l_datecmp = 0;

		if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_setldt,
													chr_l_sysdate,
													&int_l_datecmp,
													l_debug_info_ptr ))
		{	
			APL_GOBACK_FAIL;
		}	

		if ((int_l_condexists == 0) && (int_l_datecmp < 0))
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_NO_SETL_BEFORE_CSD,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		

		strcpy(chr_mainfuncarea, APL_NULL_STRING);
		strcpy(chr_l_condid, APL_NULL_STRING);
		strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
		strcpy(chr_l_condid, "CSD-10<TODAY");	
		int_l_condexists = 0;

 		if (APL_FAILURE == CO_Chk_CntryEnabled(  chr_mainfuncarea,
   	                                       chr_l_condid,
     		                                    &int_l_condexists,
        		                                 l_debug_info_ptr ))
		{  			
			APL_GOBACK_FAIL;
		}	

		if ((int_l_condexists) && (int_l_datecmp < -10))
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_CSD_MINUS_10_CANT_GT_TODAY,
															p_sys_dl_deal_struct_h_a->h_dl_client,	
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		

		if (strlen(p_sys_dl_deal_struct_h_a->h_instrdate))
		{

			

			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_instrdate,
														chr_l_sysdate,
														&int_l_datecmp,
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL;
			}

			if (int_l_datecmp < 0)
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_INSTR_DT_CANT_FUTURE,
																p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_indentity_no,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ))
				{
					APL_GOBACK_FAIL;
				}	
				int_l_error_flg = APL_FAILURE;
			}

			
	
			strcpy(chr_mainfuncarea, APL_NULL_STRING);
			strcpy(chr_l_condid, APL_NULL_STRING);
			strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
			strcpy(chr_l_condid, "INSTR_DT<CSD");	
			int_l_condexists = 0;

			if (APL_FAILURE == CO_Chk_CntryEnabled(	chr_mainfuncarea,
																chr_l_condid,
																&int_l_condexists,
																l_debug_info_ptr ))
			{		
				APL_GOBACK_FAIL;
			}

			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp( p_sys_dl_deal_struct_h_a->h_instrdate,
     		                                 p_sys_dl_deal_struct_h_a->h_setldt,
        		                              &int_l_datecmp,
           		                           l_debug_info_ptr ))
     		{
        		APL_GOBACK_FAIL;
     		}

			if ((!int_l_condexists) && (int_l_datecmp > 0))
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_INSTR_DT_CANT_BEFORE_CSD,
																p_sys_dl_deal_struct_h_a->h_dl_client,
                 		                           p_sys_dl_deal_struct_h_a->h_indentity_no,
                    		                        APL_NULL_STRING,
                       		                     __LINE__,
                          		                  __FILE__ ))
        		{
           		APL_GOBACK_FAIL;
        		}
         	int_l_error_flg = APL_FAILURE;
  	   	}

			

			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_instrdate,
														p_sys_dl_deal_struct_h_a->h_confdate,
														&int_l_datecmp,
														l_debug_info_ptr ))
			{	
				APL_GOBACK_FAIL;
			}
	
			if (int_l_datecmp > 0)
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_INSTR_DT_CANT_BEFORE_CONFDT,
																p_sys_dl_deal_struct_h_a->h_dl_client,
                 		                           p_sys_dl_deal_struct_h_a->h_indentity_no,
                    		                        APL_NULL_STRING,
                       		                     __LINE__,
                          		                  __FILE__ ))
        		{
           		APL_GOBACK_FAIL;
     			}
        		int_l_error_flg = APL_FAILURE;
     		}
		}



		if (strlen(p_sys_dl_deal_struct_h_a->h_moneydate))
		{

			

			strcpy(chr_mainfuncarea, APL_NULL_STRING);
			strcpy(chr_l_condid, APL_NULL_STRING);
			strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
			strcpy(chr_l_condid, "MONEYDT>TODAY");	
			int_l_condexists = 0;

			if (APL_FAILURE == CO_Chk_CntryEnabled( 	chr_mainfuncarea, 
     	   			                              chr_l_condid,
        	         			                     &int_l_condexists,
           	               			            l_debug_info_ptr ))
     		{
        		APL_GOBACK_FAIL;
     		}

			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_moneydate,
														chr_l_sysdate,
														&int_l_datecmp,
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL;
			}

			if ((!int_l_condexists) && (int_l_datecmp < 0))
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_MONEYDT_CANT_FUTURE,
																p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_indentity_no,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ))
				{
					APL_GOBACK_FAIL;
				}
				int_l_error_flg = APL_FAILURE;
			}

			

			if ((int_l_condexists) && (int_l_datecmp < -9))
			{
     		   if (APL_FAILURE == CO_InsertErr(  l_debug_info_ptr,
        		                                    ERR_DEAL_MONEYDT_MINUS_9_CANT_AFTER_TODAY,
           		                                 p_sys_dl_deal_struct_h_a->h_dl_client,
              		                              p_sys_dl_deal_struct_h_a->h_indentity_no,
                 		                           APL_NULL_STRING,
                    		                        __LINE__,
                       		                     __FILE__ ))
        		{	
           		APL_GOBACK_FAIL;
        		}
        		int_l_error_flg = APL_FAILURE;
     		}

			

			strcpy(chr_mainfuncarea, APL_NULL_STRING);
			strcpy(chr_l_condid, APL_NULL_STRING);
			strcpy(chr_mainfuncarea, "TRD_SETTLEMENT");
			strcpy(chr_l_condid, "MONEYDT<CSD");	
			int_l_condexists = 0;

			if (APL_FAILURE == CO_Chk_CntryEnabled(	chr_mainfuncarea,	
																chr_l_condid,
																&int_l_condexists,
																l_debug_info_ptr ))
			{	
				APL_GOBACK_FAIL;
			}

			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp( p_sys_dl_deal_struct_h_a->h_moneydate,
     		                                 p_sys_dl_deal_struct_h_a->h_setldt,
        		                              &int_l_datecmp,
           		                           l_debug_info_ptr ))
     		{	
        		APL_GOBACK_FAIL;
     		}

			if ((!int_l_condexists) && (int_l_datecmp > 0))
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_MONEYDT_CANT_BEFORE_CSD,
																p_sys_dl_deal_struct_h_a->h_dl_client,
              	   	                           p_sys_dl_deal_struct_h_a->h_indentity_no,
                 	   	                        APL_NULL_STRING,
                    	   	                     __LINE__,
                       	   	                  __FILE__ ))
        		{	
           		APL_GOBACK_FAIL;
        		}
 	        	int_l_error_flg = APL_FAILURE;
   		}

			

			int_l_datecmp = 0;
	
			if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_moneydate,
														p_sys_dl_deal_struct_h_a->h_confdate,
														&int_l_datecmp,
														l_debug_info_ptr ))
			{	
				APL_GOBACK_FAIL;
			}
	
			if (int_l_datecmp > 0)
			{
				if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_MONEYDT_CANT_BEFORE_CONFDT,
																p_sys_dl_deal_struct_h_a->h_dl_client,
                 		                           p_sys_dl_deal_struct_h_a->h_indentity_no,
                    		                        APL_NULL_STRING,
                       		                     __LINE__,
                          		                  __FILE__ ))
        		{
           		APL_GOBACK_FAIL;
        		}
        		int_l_error_flg = APL_FAILURE;
     		}
		}

		

		if ((p_sys_dl_deal_struct_h_a->h_isspotdl[0] == 'Y') &&
			 (strcmp(p_sys_dl_deal_struct_h_a->h_instrdate, p_sys_dl_deal_struct_h_a->h_moneydate)))
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_INSTR_DT_NOTEQUAL_MONEYDT,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( strlen(p_sys_dl_deal_struct_h_a->h_instrdate) &&
			strlen(p_sys_dl_deal_struct_h_a->h_moneydate) )
		{
			int_l_datecmp = 0;

			if (APL_FAILURE == CO_Pro_DateComp(	p_sys_dl_deal_struct_h_a->h_instrdate,	
													   p_sys_dl_deal_struct_h_a->h_moneydate,	
														&int_l_datecmp,
														l_debug_info_ptr ))
			{
				APL_GOBACK_FAIL;
			}
		}

		if ( p_sys_dl_deal_struct_h_a->h_ex_arena[0] == '1' )
		{
			strcpy(chr_l_settle_err_cond, l_mt_core_sys_params_struct_h.op_oth_stx_error);
		}
		else
		{
			strcpy(chr_l_settle_err_cond, l_mt_core_sys_params_struct_h.op_oth_trd_error);
		}

		if ( (!strcmp(chr_l_settle_err_cond, "<") ) && 
			( (int_l_datecmp > 0) ||
				( strlen(p_sys_dl_deal_struct_h_a->h_instrdate) && 
					( !strlen(p_sys_dl_deal_struct_h_a->h_moneydate) && 
							( VAL_VP_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0]) ) ) ) ) )
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_MONEYDT_CANT_AFTER_INSTR_DT,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( (!strcmp(chr_l_settle_err_cond, ">") ) && 
				( (int_l_datecmp < 0) ||
				( !strlen(p_sys_dl_deal_struct_h_a->h_instrdate) && 
					strlen(p_sys_dl_deal_struct_h_a->h_moneydate) ) ) )
		{	
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_MONEYDT_CANT_BEFORE_INSTR_DT,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}

		if ( (!strcmp(chr_l_settle_err_cond, "<>") ) && 
				( (int_l_datecmp) ||
				( !strlen(p_sys_dl_deal_struct_h_a->h_instrdate) && strlen(p_sys_dl_deal_struct_h_a->h_moneydate) ) ||
				( strlen(p_sys_dl_deal_struct_h_a->h_instrdate) && !strlen(p_sys_dl_deal_struct_h_a->h_moneydate) && ( VAL_VP_DEAL(p_sys_dl_deal_struct_h_a->h_dealcd[0]) ) ) ) )
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DEAL_INSTR_DT_NOTEQUAL_MONEYDT,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}
	}

	

	int_l_holexists = 0;

	if ( APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_dlt,
														&int_l_holexists,
														l_debug_info_ptr,p_sys_dl_deal_struct_h_a->h_exch_code ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( int_l_holexists > 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_DATE_IS_HOLIDAY,
									"Trade Date",
									p_sys_dl_deal_struct_h_a->h_dlt,
									APL_NULL_STRING,
									__LINE__,
									__FILE__) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	

	int_l_holexists = 0;
	/* added by AmitB - 23/01/2007 to skip exchange holiday Check for HandDeliv*/

	printf("\n deal_stat=|%s| \n",p_sys_dl_deal_struct_h_a->h_deal_status);
	printf("\n identiy_no=|%s| \n",p_sys_dl_deal_struct_h_a->h_indentity_no);
	printf("\n orig_refno=|%s| \n",p_sys_dl_deal_struct_h_a->h_origindentity_no);
	if(!strcmp(p_sys_dl_deal_struct_h_a->h_clh_flg,"D") && !strcmp(p_intl_env_data_struct_h->h_mode,"INP") && !strcmp(p_sys_dl_deal_struct_h_a->h_deal_status,"CC") && strcmp(p_sys_dl_deal_struct_h_a->h_indentity_no,p_sys_dl_deal_struct_h_a->h_origindentity_no))
	{
		printf("\n Passing Blank ExchCode \n");
		strcpy(l_exch_code,APL_NULL_STRING);
	}
	else
	{
		printf("\n As it is \n");
		strcpy(l_exch_code,p_sys_dl_deal_struct_h_a->h_exch_code);
	}
	if ( APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_setldt,
														&int_l_holexists,
														l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/l_exch_code ) )
	{
		APL_GOBACK_FAIL;
	}

	if ( int_l_holexists > 0 )
	{
		if ( CO_InsertErr(	l_debug_info_ptr,
									ERR_DATE_IS_HOLIDAY,
									"CSD",
									p_sys_dl_deal_struct_h_a->h_setldt,
									APL_NULL_STRING,
									__LINE__,
									__FILE__) == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}
		int_l_error_flg = APL_FAILURE;
	}

	

	if ( strlen( p_sys_dl_deal_struct_h_a->h_confdate) )
	{
		int_l_holexists = 0;

		if ( APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_confdate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/l_exch_code ) )
		{
			APL_GOBACK_FAIL;
		}

		if ( int_l_holexists > 0 )
		{
			if ( CO_InsertErr(	l_debug_info_ptr,
										ERR_DATE_IS_HOLIDAY,
										"Confirmation Date",
										p_sys_dl_deal_struct_h_a->h_confdate,
										APL_NULL_STRING,
										__LINE__,
										__FILE__) == APL_FAILURE )
			{
				APL_GOBACK_FAIL;
			}
			int_l_error_flg = APL_FAILURE;
		}
	}

	
	
	if (strlen(p_sys_dl_deal_struct_h_a->h_instrdate))
	{
		int_l_holexists = 0;
		if (APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_instrdate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/l_exch_code ))
		{
			APL_GOBACK_FAIL;
		}
	
		if (int_l_holexists)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATE_IS_HOLIDAY,
															p_sys_dl_deal_struct_h_a->h_instrdate,
															"Instr. Settle Date",
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE;
		} 
	}				

	if (strlen(p_sys_dl_deal_struct_h_a->h_moneydate))
	{
		int_l_holexists = 0;
		if (APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_moneydate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/l_exch_code ))
		{
			APL_GOBACK_FAIL;
		}
	
		if (int_l_holexists)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATE_IS_HOLIDAY,
															p_sys_dl_deal_struct_h_a->h_moneydate,
															"Money Settle Date",
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE;
		} 
	}

	

	if (strlen(p_sys_dl_deal_struct_h_a->h_delrecdate))
	{
		int_l_holexists = 0;
		if (APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_delrecdate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code */l_exch_code))
		{
			APL_GOBACK_FAIL;
		}
	
		if (int_l_holexists)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATE_IS_HOLIDAY,
															p_sys_dl_deal_struct_h_a->h_delrecdate,
															"Del./Rec. Tkt Date",
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE;
		} 
	}


	if (strlen(p_sys_dl_deal_struct_h_a->h_tmpoutdate))
	{
		int_l_holexists = 0;
		if (APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_tmpoutdate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/l_exch_code ))
		{
			APL_GOBACK_FAIL;
		}
	
		if (int_l_holexists)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATE_IS_HOLIDAY,
															p_sys_dl_deal_struct_h_a->h_tmpoutdate,
															"Temp Out Tkt Date",
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE;
		} 
	}


	if (strlen(p_sys_dl_deal_struct_h_a->h_tmpretdate))
	{
		int_l_holexists = 0;
		if (APL_FAILURE == CO_Chk_Holiday(	p_sys_dl_deal_struct_h_a->h_tmpretdate,
															&int_l_holexists,
															l_debug_info_ptr,/*p_sys_dl_deal_struct_h_a->h_exch_code*/ l_exch_code))
		{
			APL_GOBACK_FAIL;
		}
	
		if (int_l_holexists)
		{
			if (APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
															ERR_DATE_IS_HOLIDAY,
															p_sys_dl_deal_struct_h_a->h_tmpretdate,
															"Temp Return Tkt Date",
															APL_NULL_STRING,
															__LINE__,
															__FILE__ ))
			{
				APL_GOBACK_FAIL
			}
			int_l_error_flg = APL_FAILURE;
		} 
	}


	IF_COND_EXISTS("SPLIT_PROCESSING","SPCR_MULTITRD")
	{
	  if(strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A)==0 && (strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1)==0 || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND))==0) && strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,"STKSPA",6) != 0)/* Exclude Amalgamation event Chirag 20-11-06 */ 
		{
			strcpy(l_block_type,p_sys_dl_deal_struct_h_a->h_cash_client);	
			printf("\n Amit:l_block_type=|%s| p_sys_dl_deal_struct_h_a->h_cash_client=|%s| \n",l_block_type,p_sys_dl_deal_struct_h_a->h_cash_client);
		}

	}
	
	printf("\n Amit:Inside DL_Proc_Trd:p_sys_dl_deal_struct_h_a->h_loccode=|%s|\n",p_sys_dl_deal_struct_h_a->h_loccode);
	
	printf("\n Amit:l_block_type=|%s| \n",l_block_type);
	
	/** This Function should Always create in FREE**/
	if(!strlen(l_block_type))
		strcpy(l_block_type,"FREE");
	if ( APL_FAILURE == DL_Proc_PosLock(	p_sys_dl_deal_struct_h_a->h_dl_client,
													p_sys_dl_deal_struct_h_a->h_instr_code,
													p_sys_dl_deal_struct_h_a->h_loccode,
													APL_NULL_STRING,l_block_type,
													l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	
	l_availquantity = 0;
   
	/* chgs by amish 04/05 */
	if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"C")==0)
	{
		strcpy(l_block_type,"CABL");
	}
  printf("\nLOC CHANGE FLAG IS **************|%s|\n",p_sys_dl_deal_struct_h_a->h_locchng_flg);
	if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"X")==0)
	{
		strcpy(l_block_type,"BLCK");
	}
	
	
  printf("\nBLOCK TYPE ISSSSSSSSSSSSSSSSSSSSSSSSSSS|%s|\n",l_block_type); 	
	printf("!!!!HERE before checkp_sys_dl_deal_struct_h_a->h_dealcd[0] is %c\n",p_sys_dl_deal_struct_h_a->h_dealcd[0]);

	if ( VAL_DELIVER_DEAL(p_sys_dl_deal_struct_h_a->h_dealcd[0]) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7')
	{
		if ( strcmp(p_sys_dl_deal_struct_h_a->h_instrdate, APL_NULL_STRING) ) 
		{
			if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' && !strcmp(chr_l_regbrind, "RG") )
			{
				printf("\nchr_l_regbrind---|%s|\n",chr_l_regbrind);
				if ( p_sys_dl_deal_struct_h_a->h_delta_000 > 0  )
				{
					printf("\n BS:h_delta_000---|%lf|\n",p_sys_dl_deal_struct_h_a->h_delta_000);
					l_trdquantity = 0;
					if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																	p_sys_dl_deal_struct_h_a->h_instr_code, 
																	p_sys_dl_deal_struct_h_a->h_loccode, 
																	"000", 
																	APL_NULL_STRING, 
																	"SFK", 
																	&l_trdquantity, l_block_type,
																	l_debug_info_ptr) )
					{
						printf("\n BS---l_trdquantity1 ----");
						printf("\n l_trdquantity--1----=|%lf|",l_trdquantity);
						if ( p_sys_dl_deal_struct_h_a->h_delta_000 > l_trdquantity )
						{	
							if ( CO_InsertErr(	l_debug_info_ptr, 
														ERR_DEAL_NENUFPOSN, 
														p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_instr_code, 
														"000 Position Status", 
														__LINE__, 
														__FILE__ ) == APL_FAILURE )
							{
								APL_GOBACK_FAIL;
							}	
							int_l_error_flg = APL_FAILURE;
						}
					}
					else 
					{
						APL_GOBACK_FAIL;
					}
				}

				if ( p_sys_dl_deal_struct_h_a->h_delta_001 > 0 )
				{
					l_trdquantity = 0;
					if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																	p_sys_dl_deal_struct_h_a->h_instr_code, 
																	p_sys_dl_deal_struct_h_a->h_loccode, 
																	"001", 
																	APL_NULL_STRING, 
																	"SFK", 
																	&l_trdquantity, l_block_type,
																	l_debug_info_ptr) )
					{	
						if ( p_sys_dl_deal_struct_h_a->h_delta_001 > l_trdquantity )
						{		
							if ( CO_InsertErr(	l_debug_info_ptr, 
														ERR_DEAL_NENUFPOSN, 
														p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_instr_code, 
														"001 Position Status", 
														__LINE__, 
														__FILE__ ) == APL_FAILURE )
							{
								APL_GOBACK_FAIL;
							}	
							int_l_error_flg = APL_FAILURE;
						}
					}
					else 
					{
						APL_GOBACK_FAIL;
					}
				}

				if ( p_sys_dl_deal_struct_h_a->h_delta_002 > 0 )
				{
					l_trdquantity = 0;
					if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																	p_sys_dl_deal_struct_h_a->h_instr_code, 
																	p_sys_dl_deal_struct_h_a->h_loccode, 
																	"003", 
																	APL_NULL_STRING, 
																	"SFK", 
																	&l_trdquantity, l_block_type,
																	l_debug_info_ptr) )
					{		
						if ( p_sys_dl_deal_struct_h_a->h_delta_002 > l_trdquantity )
						{	
							if ( CO_InsertErr(	l_debug_info_ptr, 
														ERR_DEAL_NENUFPOSN, 
														p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_instr_code, 
														"003 Position Status", 
														__LINE__, 
														__FILE__ ) == APL_FAILURE )
							{
								APL_GOBACK_FAIL;
							}	
							int_l_error_flg = APL_FAILURE;
						}
					}
					else 
					{
						APL_GOBACK_FAIL;
					}
				}
			}		
			else
			{
				l_trdquantity = 0;
			{
				if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																p_sys_dl_deal_struct_h_a->h_loccode, 
																p_sys_dl_deal_struct_h_a->h_pos_stat,	
																APL_NULL_STRING, 
																"SFK", 
																&l_trdquantity, l_block_type,
																l_debug_info_ptr) )
				{

					//if ( p_sys_dl_deal_struct_h_a->h_qty > l_trdquantity )
					if (APL_DOUBLE_LESS(l_trdquantity,p_sys_dl_deal_struct_h_a->h_qty))
					{
						printf("\n Could not find positions in NSDL ... Now looking for CDSL \n");
						printf("\n Amit:Original Location=|%s| \n",p_sys_dl_deal_struct_h_a->h_loccode);
						
						strcpy(p_sys_dl_deal_struct_h_a->h_loccode,"CDSL");
						
						if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																p_sys_dl_deal_struct_h_a->h_loccode, 
																p_sys_dl_deal_struct_h_a->h_pos_stat,	
																APL_NULL_STRING, 
																"SFK", 
																&l_trdquantity, l_block_type,
																l_debug_info_ptr) )
					
						{	printf("\n BS---h_qty ----");
							//if ( p_sys_dl_deal_struct_h_a->h_qty > l_trdquantity )
						if (APL_DOUBLE_LESS(l_trdquantity,p_sys_dl_deal_struct_h_a->h_qty))
							{
								
								
								printf("\n Could not find positions in CDSL ... Now looking for CSGL \n");
								strcpy(p_sys_dl_deal_struct_h_a->h_loccode,"CSGL");		
								
								if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																p_sys_dl_deal_struct_h_a->h_loccode, 
																p_sys_dl_deal_struct_h_a->h_pos_stat,
																APL_NULL_STRING, 
																"SFK", 
																&l_trdquantity, l_block_type,
																l_debug_info_ptr) )
							
							  {	
							  printf("\n h_qty ----=|%lf|",p_sys_dl_deal_struct_h_a->h_qty);
							  printf("\n l_trdquantity ----=|%lf|",l_trdquantity);
							  if (APL_DOUBLE_LESS(l_trdquantity,p_sys_dl_deal_struct_h_a->h_qty))
							{
									
								printf("\n Could not find positions in CSGL ... Now looking for VAULT \n");
								strcpy(p_sys_dl_deal_struct_h_a->h_loccode,"VAUL");		
								
								if ( APL_SUCCESS == DL_Proc_PosCalc(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																p_sys_dl_deal_struct_h_a->h_loccode, 
																p_sys_dl_deal_struct_h_a->h_pos_stat,
																APL_NULL_STRING, 
																"SFK", 
																&l_trdquantity, l_block_type,
																l_debug_info_ptr) )
							
							  {	
							  printf("\n h_qty ----=|%lf|",p_sys_dl_deal_struct_h_a->h_qty);
							  printf("\n l_trdquantity ----=|%lf|",l_trdquantity);
							  
								//if ( p_sys_dl_deal_struct_h_a->h_qty > l_trdquantity )
				 if(APL_DOUBLE_LESS(l_trdquantity,p_sys_dl_deal_struct_h_a->h_qty))
								{
									printf("\n Could Not Find Positions in All Depositories \n");

									#ifdef EMU_PROCESSING
									if ( DL_Rtv_SplAcc(chr_spl_client,l_debug_info_ptr) == APL_FAILURE )
									{
										APL_GOBACK_FAIL		
									}
									
									if ( strcmp(chr_spl_client,p_sys_dl_deal_struct_h_a->h_dl_client) )
									{
										printf("\n BS--4 \n");
										if ( CO_InsertErr(	l_debug_info_ptr, 
																ERR_DEAL_NENUFPOSN, 
																p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																APL_NULL_STRING, 
																__LINE__, 
																__FILE__ ) == APL_FAILURE )
											{
												APL_GOBACK_FAIL;
											}	
											int_l_error_flg = APL_FAILURE;
									}
									#else
										if ( CO_InsertErr(	l_debug_info_ptr, 
																ERR_DEAL_NENUFPOSN, 
																p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																APL_NULL_STRING, 
																__LINE__, 
																__FILE__ ) == APL_FAILURE )
											{
												APL_GOBACK_FAIL;
											}	
											int_l_error_flg = APL_FAILURE;
									#endif	
								}//qty in VAULT innermost depo > 	

							}
							else //else of VAULT if
							{printf("\n BS--5 \n");
								APL_GOBACK_FAIL;
							}
							} //CSGL FOUND QUNTITY
							}else{
								APL_GOBACK_FAIL;  // CSGL
							}
						  }//qty in CDSL depo > 	

						} 
						else //else of CDSL if
						{
							APL_GOBACK_FAIL;
						}

					}//qty in FIRST depo > 	
					}
					else //else of NSDL if
					{
						printf("\n BS--6 \n");
						APL_GOBACK_FAIL;
					}
									
				}
			 }
			}
 	   
		else if ( strlen(p_sys_dl_deal_struct_h_a->h_confdate) && ( p_sys_dl_deal_struct_h_a->h_dlfromord[0] != 'Y' ))
		{	printf("\n 11:Amit:l_block_type=|%s| \n",l_block_type);
			
			Alert("\n baba1");
			if ( APL_FAILURE == DL_Chk_AvlPos(	p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_instr_code,
															p_sys_dl_deal_struct_h_a->h_loccode,
															'Y','N','N','Y','Y','N','N','N',
															l_block_type,
															&l_availquantity,
															l_debug_info_ptr ) )
			{	
				APL_GOBACK_FAIL;
			}
						printf("l_availquantity is **************%lf,p_sys_dl_deal_struct_h_a->h_qty is ***%lf\n",l_availquantity,p_sys_dl_deal_struct_h_a->h_qty);
		
			//if ( l_availquantity < p_sys_dl_deal_struct_h_a->h_qty )
			if(APL_DOUBLE_LESS(l_availquantity,p_sys_dl_deal_struct_h_a->h_qty))
			{
				printf("\nBS---l_availquantity---%lf\n",l_availquantity);
				if ( APL_FAILURE == CO_InsertErr(	l_debug_info_ptr,
																ERR_DEAL_NENUFPOSN,
																p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_instr_code,
																APL_NULL_STRING,
																__LINE__,
																__FILE__ ) )
				{	
					APL_NULL_STRING;
				}
				int_l_error_flg = APL_FAILURE;
			}

			
			printf("\n Amit:Oh here 3\n");
			if ( l_mt_core_sys_params_struct_h.vdp_ind[0] == 'N' )
			{
				int_l_datecmp = 0;

				if ( APL_FAILURE == CO_Pro_DateComp( 	p_sys_dl_deal_struct_h_a->h_confdate,
																p_sys_dl_deal_struct_h_a->h_setldt,
																&int_l_datecmp,
																l_debug_info_ptr ) )
				{	
					APL_GOBACK_FAIL;
				}
	
				if ( int_l_datecmp < 0 )
				{
					strcpy( chr_l_vdpdate, p_sys_dl_deal_struct_h_a->h_confdate );
				}	
				else
				{
					strcpy( chr_l_vdpdate, p_sys_dl_deal_struct_h_a->h_setldt );
				}
/** Change by AmitB 270906:For SplitCR Trade Creation  **/

				IF_COND_EXISTS("SPLIT_PROCESSING","SPCR_MULTITRD")
				{
					if(strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A)==0 && (strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1)==0 || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND))==0))
					{
							printf("\n Skip Below Check for Split Multiple Trades\n");
					}
					else
					{printf("\n Amit:Oh here 1\n");
						if ( APL_FAILURE == DL_Chk_VDPPos(	p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_instr_code,
																p_sys_dl_deal_struct_h_a->h_loccode,
																p_sys_dl_deal_struct_h_a->h_pos_stat,
																p_sys_dl_deal_struct_h_a->h_qty,
																chr_l_vdpdate,
																&int_l_enufvdp,
																l_debug_info_ptr ) )
						 {
							 APL_GOBACK_FAIL;
						}
			
					}

				}
				else
				{printf("\n Amit:Oh here 2\n");
				  if ( APL_FAILURE == DL_Chk_VDPPos(	p_sys_dl_deal_struct_h_a->h_dl_client,
																p_sys_dl_deal_struct_h_a->h_instr_code,
																p_sys_dl_deal_struct_h_a->h_loccode,
																p_sys_dl_deal_struct_h_a->h_pos_stat,
																p_sys_dl_deal_struct_h_a->h_qty,
																chr_l_vdpdate,
																&int_l_enufvdp,
																l_debug_info_ptr ) )
				  {
				 	 APL_GOBACK_FAIL;
				  }
			
				}
				
			}
		}
		else  if (( strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) ==0) || ( strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT)==0))
		{
			if(   (	!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"17") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"19") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"18") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"20") )&& (strlen(p_sys_dl_deal_struct_h_a-> h_indentity_no) > 5))
		{
				if(Rtv_Evt_Type(  p_sys_dl_deal_struct_h_a-> h_indentity_no,
							l_evt_type,
							l_op_evt_type,
							l_debug_info_ptr) == APL_FAILURE)
				{
					Alert("Failed In Rtv_Evt_Type");
				}
				Alert("Deal Code|%s|evet |%s| Op |%s|",p_sys_dl_deal_struct_h_a-> h_classofdl,l_evt_type,l_op_evt_type)
				if(!strcmp(l_evt_type,"SP") )
				{
			
			Alert("\n baba2");
			if ( APL_FAILURE == DL_Chk_AvlPos(  p_sys_dl_deal_struct_h_a->h_dl_client,
						p_sys_dl_deal_struct_h_a->h_instr_code,
						p_sys_dl_deal_struct_h_a->h_loccode,
									                           'Y','Y','Y','Y','Y','N','N','N',l_block_type,
							 		                           &l_availquantity,
									                           l_debug_info_ptr ) )
						{
						   APL_GOBACK_FAIL;
						}
			
			
				}
				else if(!strcmp(l_evt_type,"CR") )
				{
					Alert("\n baba3");
					if ( APL_FAILURE == DL_Chk_AvlPos(  p_sys_dl_deal_struct_h_a->h_dl_client,
								p_sys_dl_deal_struct_h_a->h_instr_code,
								p_sys_dl_deal_struct_h_a->h_loccode,
								'Y','Y','Y','Y','Y','N','N','N',l_block_type,
								&l_availquantity,
								l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				}
				else
				{
					Alert("Calling aval");
					
					Alert("\n baba4");
					if ( APL_FAILURE == DL_Chk_AvlPos(  p_sys_dl_deal_struct_h_a->h_dl_client,
								p_sys_dl_deal_struct_h_a->h_instr_code,
								p_sys_dl_deal_struct_h_a->h_loccode,
								'Y','N','Y','N','Y','N','N','N',l_block_type,
								&l_availquantity,
								l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				}
			}
			else
			{
				printf("JC::: Considering the DP_DEL bucket to calculate available positions... [ISKB 1597]\n");
				
				/*Changes done by Dipak for PMS deals T+0 cnfirmation start - New function DL_Call_Avl_Pos_Chk is added to check the master client parameter which will decide if sub client position need to consider in sell deal */
				
					Alert("Calling function DL_Call_Avl_Pos_Chk \n");
					if ( APL_FAILURE == DL_Call_Avl_Pos_Chk(  p_sys_dl_deal_struct_h_a,
								l_block_type,
								&l_availquantity,
								l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				
				
					  
			}

			//printf("l_availquantity is **************%lf,p_sys_dl_deal_struct_h_a->h_qty is ***%lf\n",l_availquantity,p_sys_dl_deal_struct_h_a->h_qty);
			printf("\n p_sys_dl_deal_struct_h_a->h_classofdl = |%s|", p_sys_dl_deal_struct_h_a->h_classofdl);
			
/** Changes AmitB:27/09/06:For SplitCR trades:Skip Positon Check **/	
	
			/* changes by amish --- 27/02/2007 */
			l_to_compare_availquantity = 0;
			printf("AMISH ====== DEAL CODE IS |%s|",p_sys_dl_deal_struct_h_a->h_dealcd);
			printf("\n Status is |%s| \n",p_sys_dl_deal_struct_h_a->h_deal_status);
			strcpy(chr_l_fieldname, "qty");
			l_trdquantity = 0;

			if(strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) == 0)
			 {
				if ( APL_FAILURE == DL_Rtv_TrdNumVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														&l_trdquantity, 
														l_debug_info_ptr) )
   			{
					int_l_error_flg = APL_FAILURE;
					}
			}
	         else
			 l_trdquantity = 0;

			printf("\nl_trdquantity is *********|%lf|\n",l_trdquantity);/* changes by amish --- 27/02/2007 */
			l_to_compare_availquantity = l_availquantity + l_trdquantity; /* changes by amish --- 27/02/2007 */
			printf("\n Ignoring qty of the deal l_availquantity=|%lf| , l_to_compare_availquantity =|%lf|\n",l_availquantity,l_to_compare_availquantity);/* changes by amish --- 27/02/2007 */

			IF_COND_EXISTS("SPLIT_PROCESSING","SPCR_MULTITRD")
			{
			
			/*
			 if ( l_availquantity < p_sys_dl_deal_struct_h_a->h_qty && strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL)  && (strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A) &&(strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1) || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND)))) )
			 
			 if ( l_to_compare_availquantity < p_sys_dl_deal_struct_h_a->h_qty && strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL)  && (strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A) &&(strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1) || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND)))) ) changes by amish --- 27/02/2007 */
			 
			 int_ret_val = chkAllowForSellCsgl(p_sys_dl_deal_struct_h_a, l_debug_info_ptr);
			
			 if( APL_DOUBLE_LESS(l_to_compare_availquantity,p_sys_dl_deal_struct_h_a->h_qty) && int_ret_val && !strcmp(p_sys_dl_deal_struct_h_a->h_loccode,"CSGL"))
			 {
				 printf("\n RAHUL :Deal is CSGL .. So dealclass =40 \n");
				strcpy( p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL);				
			 }
			 
			 
			 if ( APL_DOUBLE_LESS(l_to_compare_availquantity,p_sys_dl_deal_struct_h_a->h_qty) && strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL)  && (strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,DEALTYPE_CORP_A) &&(strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,STOCK_SPLIT,strlen(STOCK_SPLIT) - 1) || strncmp(p_sys_dl_deal_struct_h_a->h_indentity_no,CACR_IND,strlen(CACR_IND)))) ) /* added by akshay for ISKB_11454*/
			 {
				printf("\n Amit: Error1 \n");
				
							/*ERR_DEAL_NENUFPOSN, TUX */
				if ( APL_FAILURE == CO_InsertErr(   l_debug_info_ptr,
							ERR_DEAL_NENUFPOSN_SHORT_SELL,
							p_sys_dl_deal_struct_h_a->h_dl_client,
							p_sys_dl_deal_struct_h_a->h_instr_code,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ ) )
				{
					APL_GOBACK_FAIL;
				}
			 }
			 else
			 {
				printf("\n AMit:Deal is Split/CR .. So skiping \n");
			 }
				
			}
			else
			{
				
			/*
			 if ( l_availquantity < p_sys_dl_deal_struct_h_a->h_qty && strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL) )
			 */
			 if ( APL_DOUBLE_LESS(l_to_compare_availquantity,p_sys_dl_deal_struct_h_a->h_qty) && strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,SHORTSELLDEAL) )/* changes by amish --- 27/02/2007 */
			 {
				printf("\n Amit: Error2 \n");
							/*ERR_DEAL_NENUFPOSN, TUX */
				if ( APL_FAILURE == CO_InsertErr(   l_debug_info_ptr,
							ERR_DEAL_NENUFPOSN_SHORT_SELL,
							p_sys_dl_deal_struct_h_a->h_dl_client,
							p_sys_dl_deal_struct_h_a->h_instr_code,
							APL_NULL_STRING,
							__LINE__,
							__FILE__ ) )
				{
					APL_GOBACK_FAIL;
				}
			 }
					
			}
			
		}

	}
printf("\n Amit:Oh here 4\n");

	if ( strlen( p_sys_dl_deal_struct_h_a->h_instrdate ) != 0 )
	{
		if ( strcmp( p_sys_dl_deal_struct_h_a->h_instrdate, chr_l_sysdate ) != 0 )
		{printf("\n BS:Oh here 2\n");
			p_sys_dl_deal_struct_h_a->h_mod_hispos_ind[0] = 'Y';
			p_sys_dl_deal_struct_h_a->h_mod_hispos_ind[1] = '\0';
		}
		else
		{printf("\n BS:Oh here 3\n");
			strcpy( p_sys_dl_deal_struct_h_a->h_mod_hispos_ind, APL_NULL_STRING );
		}
	}
	else
	{printf("\n BS:Oh here 4\n");
		strcpy( p_sys_dl_deal_struct_h_a->h_mod_hispos_ind, APL_NULL_STRING );
	}

	if ( int_l_error_flg == APL_FAILURE )
	{printf("\n Amit:Oh here 5\n");
		APL_GOBACK_FAIL;
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{printf("\n Amit:Oh here 6\n");
		APL_GOBACK_FAIL;
	}

	

	if ( !strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_MODIFY) )
	{

		strcpy(chr_l_fieldname, "instr_code");
		if ( APL_FAILURE == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														chr_l_instrcode_b, 
														l_debug_info_ptr) )
   	{
			int_l_error_flg = APL_FAILURE;
		}

		if ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' )
		{
			strcpy(chr_l_fieldname, "locncode");
			if ( APL_FAILURE == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_indentity_no, 
															chr_l_fieldname, 
															chr_l_locncode, 
															l_debug_info_ptr) )
   		{
				int_l_error_flg = APL_FAILURE;
			}
		}

		if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' )
		{
			strcpy(chr_l_fieldname, "posn_status");
			if ( APL_FAILURE == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_indentity_no, 
															chr_l_fieldname, 
															chr_l_posnstatus, 
															l_debug_info_ptr) )
   		{
				int_l_error_flg = APL_FAILURE;
			}
		}

		strcpy(chr_l_fieldname, "trcode");
		if ( APL_FAILURE == DL_Rtv_TrdChrVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														chr_l_trcode_b, 
														l_debug_info_ptr) )
   	{
			int_l_error_flg = APL_FAILURE;
		}

		strcpy(chr_l_fieldname, "qty");
		l_trdquantity = 0;
		if ( APL_FAILURE == DL_Rtv_TrdNumVal(	p_sys_dl_deal_struct_h_a->h_dl_client, 
														p_sys_dl_deal_struct_h_a->h_indentity_no, 
														chr_l_fieldname, 
														&l_trdquantity, 
														l_debug_info_ptr) )
   	{
			int_l_error_flg = APL_FAILURE;
		}

		if ( int_l_error_flg == APL_FAILURE )
		{
			APL_GOBACK_FAIL;
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}

		if ( ( strcmp(chr_l_instrcode_b, p_sys_dl_deal_struct_h_a->h_instr_code) ) ||
			  ( strcmp(chr_l_posnstatus, p_sys_dl_deal_struct_h_a->h_pos_stat) && 
					 ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y') ) ||
			  ( ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' ) && 
					strcmp(chr_l_locncode, p_sys_dl_deal_struct_h_a->h_loccode) ) ||
			  ( ( VAL_DELIVER_DEAL( chr_l_trcode_b[0] ) || chr_l_trcode_b[0]=='5' || chr_l_trcode_b[0]=='7') && 
						( VAL_RECDEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='6' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='8') ) ||
			  ( ( VAL_RECDEAL( chr_l_trcode_b[0] ) || chr_l_trcode_b[0]=='6' || chr_l_trcode_b[0]=='8') &&
						( VAL_DELIVER_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7') ) ||
			  ( p_sys_dl_deal_struct_h_a->h_qty != l_trdquantity ) ) 
		{
			if(   (  !strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"17") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"19") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"18") ||
						!strcmp(p_sys_dl_deal_struct_h_a-> h_classofdl,"20") )&& (strlen(p_sys_dl_deal_struct_h_a-> h_indentity_no) > 5))
			{
				if(Rtv_Evt_Type(  p_sys_dl_deal_struct_h_a-> h_indentity_no,
							l_evt_type,
							l_op_evt_type,
							l_debug_info_ptr) == APL_FAILURE)
				{
					Alert("Failed In Rtv_Evt_Type");
				}
				Alert("Deal Code|%s|evet |%s| Op |%s|",p_sys_dl_deal_struct_h_a-> h_classofdl,l_evt_type,l_op_evt_type)
			}
			if(!strcmp(l_evt_type,"SP") && !strcmp(p_sys_dl_deal_struct_h_a->h_deal_status,"CC"))
			{

			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															chr_l_instrcode_b, 
															chr_l_locncode, 
															chr_l_posnstatus, 
															'C', 
															chr_l_trcode_b[0], 
															&l_trdquantity, 
															'D', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
			}
			else if(!strcmp(l_evt_type,"CR") && !strcmp(p_sys_dl_deal_struct_h_a->h_deal_status,"CC"))
			{

			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															chr_l_instrcode_b, 
															chr_l_locncode, 
															chr_l_posnstatus, 
															'C', 
															chr_l_trcode_b[0], 
															&l_trdquantity, 
															'D', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
			}
			else
			{
			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															chr_l_instrcode_b, 
															chr_l_locncode, 
															chr_l_posnstatus, 
															'U', 
															chr_l_trcode_b[0], 
															&l_trdquantity, 
															'D', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}

			}





         if ( ( strcmp(chr_l_instrcode_b, p_sys_dl_deal_struct_h_a->h_instr_code) ) ||
              ( ( l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y' ) &&
                  strcmp(chr_l_locncode, p_sys_dl_deal_struct_h_a->h_loccode) ) )
         {

            if ( APL_FAILURE == EI_Mod_MQData(  p_sys_dl_deal_struct_h_a->h_dl_client,
                                                p_sys_dl_deal_struct_h_a->h_indentity_no,
                                                NULL,
                                                NULL,
                                                "B",
                                                l_debug_info_ptr) )
            {
               APL_GOBACK_FAIL;
            }

         }



			if(!strcmp(l_evt_type,"SP") && !strcmp(p_sys_dl_deal_struct_h_a->h_deal_status,"CC"))
			{
			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															 'C', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
			}
			else if(!strcmp(l_evt_type,"CR") && !strcmp(p_sys_dl_deal_struct_h_a->h_deal_status,"CC"))
			{
			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															 'C', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
			}
			else
			{
			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															 'U', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
		}	
	}
	}

	 

	if ( !strcmp( p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT ) || 
			!strcmp( p_intl_env_data_struct_h->h_mode, RPR_MODE ) ) 
	{
		if ( strcmp(p_sys_dl_deal_struct_h_a->h_instrdate, APL_NULL_STRING) && 
				( VAL_RECDEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='6' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='8') )
		{
            if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"X")==0)
            {
			              printf("\n*********************************AMISH******************\n");
			               if ( APL_FAILURE == DL_Mod_Posn( p_sys_dl_deal_struct_h_a->h_dl_client,
				                                             p_sys_dl_deal_struct_h_a->h_instr_code,
				                                          p_sys_dl_deal_struct_h_a->h_loccode,
				                                          p_sys_dl_deal_struct_h_a->h_pos_stat,
				                                          'S',
				                                          p_sys_dl_deal_struct_h_a->h_dealcd[0],
		                                          &p_sys_dl_deal_struct_h_a->h_qty,
		                                          'I', "BLCK",
	                                          l_debug_info_ptr) )

			               {
		                     APL_GOBACK_FAIL
			               }
				 }
				 /* chgs by amish ---for blk and releases of CA deals safek---04/05 */
				else if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"C")==0)
	  			{
	                    			
			              printf("\n******************callin func for CA BLOCK******************\n");
			               if ( APL_FAILURE == DL_Mod_Posn( p_sys_dl_deal_struct_h_a->h_dl_client,
				                                             p_sys_dl_deal_struct_h_a->h_instr_code,
				                                          p_sys_dl_deal_struct_h_a->h_loccode,
				                                          p_sys_dl_deal_struct_h_a->h_pos_stat,
				                                          'S',
				                                          p_sys_dl_deal_struct_h_a->h_dealcd[0],
		                                          &p_sys_dl_deal_struct_h_a->h_qty,
		                                          'I', "CABL",
	                                          l_debug_info_ptr) )

			               {
		                     APL_GOBACK_FAIL
			               }
     					
				}
				 else
				 {


					if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															'S', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
					{
						APL_GOBACK_FAIL;
					}
				 }
		}
		else if ( strcmp(p_sys_dl_deal_struct_h_a->h_instrdate, APL_NULL_STRING) && 
					( VAL_DELIVER_DEAL( p_sys_dl_deal_struct_h_a->h_dealcd[0] ) || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='5' || p_sys_dl_deal_struct_h_a->h_dealcd[0]=='7') )
		{
			if ( l_mt_core_sys_params_struct_h.proc_reg_ind[0] == 'Y' && 
						!strcmp(chr_l_regbrind, "RG") )
			{
				if ( p_sys_dl_deal_struct_h_a->h_delta_000 > 0 )
				{
					if ( APL_FAILURE == DL_Mod_Posn( 	p_sys_dl_deal_struct_h_a->h_dl_client,
																	p_sys_dl_deal_struct_h_a->h_instr_code,																				
																	p_sys_dl_deal_struct_h_a->h_loccode,
																	"000",
																	'S',
																	p_sys_dl_deal_struct_h_a->h_dealcd[0],
																	&p_sys_dl_deal_struct_h_a->h_delta_000,
																	'D',l_block_type,
																	l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				}

				if ( p_sys_dl_deal_struct_h_a->h_delta_001 > 0 )
				{
					if ( APL_FAILURE == DL_Mod_Posn( 	p_sys_dl_deal_struct_h_a->h_dl_client,
																	p_sys_dl_deal_struct_h_a->h_instr_code,																				
																	p_sys_dl_deal_struct_h_a->h_loccode,
																	"001",
																	'S',
																	p_sys_dl_deal_struct_h_a->h_dealcd[0],
																	&p_sys_dl_deal_struct_h_a->h_delta_001,
																	'D',l_block_type,
																	l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				}

				if ( p_sys_dl_deal_struct_h_a->h_delta_002 > 0 )
				{
					if ( APL_FAILURE == DL_Mod_Posn( 	p_sys_dl_deal_struct_h_a->h_dl_client,
																	p_sys_dl_deal_struct_h_a->h_instr_code,																				
																	p_sys_dl_deal_struct_h_a->h_loccode,
																	"003",
																	'S',
																	p_sys_dl_deal_struct_h_a->h_dealcd[0],
																	&p_sys_dl_deal_struct_h_a->h_delta_002,
																	'D',l_block_type,
																	l_debug_info_ptr ) )
					{
						APL_GOBACK_FAIL;
					}
				}
			}
			else
			{
				   if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"X")==0)
            	{
				      if ( APL_FAILURE == DL_Mod_Posn( p_sys_dl_deal_struct_h_a->h_dl_client,
                                                p_sys_dl_deal_struct_h_a->h_instr_code,
													          p_sys_dl_deal_struct_h_a->h_loccode,
													         p_sys_dl_deal_struct_h_a->h_pos_stat,
													         'S',
													         p_sys_dl_deal_struct_h_a->h_dealcd[0],
													         &p_sys_dl_deal_struct_h_a->h_qty,
													         'D', "BLCK",
													         l_debug_info_ptr) )
               	{
					      APL_GOBACK_FAIL;
					   }
					 }
					/* chgs by amish ---for blk and releases of CA deals safek---04/05 */
					else if(strcmp(p_sys_dl_deal_struct_h_a->h_locchng_flg,"C")==0)
					{ 
                   
	             printf("\nCALLING FUNCTION FOR CA BLOCK**********8\n");    				  	
				      if ( APL_FAILURE == DL_Mod_Posn( p_sys_dl_deal_struct_h_a->h_dl_client,
                                                p_sys_dl_deal_struct_h_a->h_instr_code,
													          p_sys_dl_deal_struct_h_a->h_loccode,
													         p_sys_dl_deal_struct_h_a->h_pos_stat,
													         'S',
													         p_sys_dl_deal_struct_h_a->h_dealcd[0],
													         &p_sys_dl_deal_struct_h_a->h_qty,
													         'D', "CABL",
													         l_debug_info_ptr) )
               	{
					      APL_GOBACK_FAIL;
					   }
						
					}
					else
					{
						if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
																p_sys_dl_deal_struct_h_a->h_instr_code, 
																p_sys_dl_deal_struct_h_a->h_loccode, 
																p_sys_dl_deal_struct_h_a->h_pos_stat,
																'S', 
																p_sys_dl_deal_struct_h_a->h_dealcd[0], 
																&p_sys_dl_deal_struct_h_a->h_qty, 
																'D', l_block_type,
																l_debug_info_ptr) )
						{	
							APL_GOBACK_FAIL;
						}
					}
			}
		}
		else if ( strcmp(p_sys_dl_deal_struct_h_a->h_confdate, APL_NULL_STRING) )
		{
			if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															'C', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			}
		}
		else 
		{
			Alert("\n Commented for good reasons");
			/*Changes done by Dipak for PMS deals T+0 cnfirmation start - New function DL_Call_DL_Mod_Posn is added to check the master client parameter which will decide if sub client position need to consider in sell deal */
			/* if ( APL_FAILURE == DL_Mod_Posn(	p_sys_dl_deal_struct_h_a->h_dl_client, 
															p_sys_dl_deal_struct_h_a->h_instr_code, 
															p_sys_dl_deal_struct_h_a->h_loccode, 
															p_sys_dl_deal_struct_h_a->h_pos_stat,
															'U', 
															p_sys_dl_deal_struct_h_a->h_dealcd[0], 
															&p_sys_dl_deal_struct_h_a->h_qty, 
															'I', l_block_type,
															l_debug_info_ptr) )
			{
				APL_GOBACK_FAIL;
			} */			
				Alert("Calling function DL_Call_DL_Mod_Posn \n");
				if ( APL_FAILURE == DL_Call_DL_Mod_Posn(  p_sys_dl_deal_struct_h_a,
							l_block_type,
							&l_availquantity,
							l_debug_info_ptr ) )
				{
					APL_GOBACK_FAIL;
				}
			/*Changes done by Dipak for PMS deals T+0 cnfirmation End */ 
		}
	}

	if ( APL_FAILURE ==  DL_Mod_DL( 	p_sys_dl_deal_struct_h_a, 
													chr_l_rowid_A, 
													int_p_trdrepseqnum, 
													p_intl_env_data_struct_h, 
													l_debug_info_ptr) ) 
	{
		APL_GOBACK_FAIL;
	}

	

	strcpy(l_dl_dealaudit_struct_hb_a->h_dl_client, p_sys_dl_deal_struct_h_a->h_dl_client);
	strcpy(l_dl_dealaudit_struct_hb_a->h_indentity_no, p_sys_dl_deal_struct_h_a->h_indentity_no);
	strcpy(l_dl_dealaudit_struct_hb_a->h_trail_for, "T");
	strcpy(l_dl_dealaudit_struct_hb_a->h_processdetail, p_intl_env_data_struct_h->processtion);
	strcpy(l_dl_dealaudit_struct_hb_a->h_proc_usr, p_intl_env_data_struct_h->usr);
	strcpy(l_dl_dealaudit_struct_hb_a->h_subprocess, p_intl_env_data_struct_h->subprocess);

   

   if ( !strcmp(p_intl_env_data_struct_h->h_mode, APL_FUNC_INPUT) &&
        !strcmp(p_sys_dl_deal_struct_h_a->h_entry, "S") )
   {
      if ( APL_FAILURE == CO_RtvMachDtTime(l_dl_dealaudit_struct_hb_a->h_logdate,
                                                l_debug_info_ptr) )
      {
         APL_GOBACK_FAIL
      }
   }
   else
   {
      strcpy(l_dl_dealaudit_struct_hb_a->h_logdate,APL_NULL_STRING);
   }

	strcpy(l_dl_dealaudit_struct_hb_a->h_fail_cd, p_sys_dl_deal_struct_h_a->h_fail_cd);
	l_dl_dealaudit_struct_hb_a->h_qty = p_sys_dl_deal_struct_h_a->h_qty;
	strcpy(l_dl_dealaudit_struct_hb_a->h_dlfromord, p_sys_dl_deal_struct_h_a->h_dlfromord);

	if ( APL_FAILURE ==  CR_Mod_CLHAudTrail( 	l_dl_dealaudit_struct_hb_a, 
														l_debug_info_ptr) ) 
   {
      APL_GOBACK_FAIL;
   }

	/* PJ Insert into GN_AUDIT_LOG */
	if(	strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"19") == 0 
			|| strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"18") == 0
	  )
	{
	strcpy(p_gn_audit_log_struct_h->h_userid,p_intl_env_data_struct_h->usr );
	strcpy(p_gn_audit_log_struct_h->h_rec_mode, p_intl_env_data_struct_h->h_mode);
	strcpy(chr_h_entity_name,"DL_DEAL");
	strcpy(p_gn_audit_log_struct_h->h_entity_name, chr_h_entity_name);
	strcpy(p_gn_audit_log_struct_h->h_log_time, APL_NULL_STRING);
	strcpy(p_gn_audit_log_struct_h->h_comments, "CORPORATE ACTION TRADE");
	
	strcpy(p_ca_gn_audit_log_struct_h->h_dl_client,p_sys_dl_deal_struct_h_a->h_dl_client);
	strcpy(p_ca_gn_audit_log_struct_h->h_cln_refno,p_sys_dl_deal_struct_h_a->h_indentity_no);
	strcpy(p_ca_gn_audit_log_struct_h->h_instr_code,p_sys_dl_deal_struct_h_a->h_instr_code);
	strcpy(p_ca_gn_audit_log_struct_h->h_deal_cd,p_sys_dl_deal_struct_h_a->h_dealcd);
	p_ca_gn_audit_log_struct_h->h_qty = p_sys_dl_deal_struct_h_a->h_qty;
	p_ca_gn_audit_log_struct_h->h_amount = p_sys_dl_deal_struct_h_a->h_amt;
	strcpy(p_ca_gn_audit_log_struct_h->h_deal_date,p_sys_dl_deal_struct_h_a->h_dlt);
	strcpy(p_ca_gn_audit_log_struct_h->h_setl_date,p_sys_dl_deal_struct_h_a->h_setldt);
	
		if ( APL_FAILURE ==  CA_InsAudLog( 	p_gn_audit_log_struct_h, p_ca_gn_audit_log_struct_h,
				l_debug_info_ptr) ) 
		{
			APL_GOBACK_FAIL;
		}
	}
	/* Added by Shradha for Kotak Phase 2 IOP Starts */
	if(	strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"59") == 0 || strcmp(p_sys_dl_deal_struct_h_a->h_misinfo,"PARTIAL PREMATCH") == 0 )  
	{
	strcpy(p_gn_audit_log_struct_h->h_userid,p_intl_env_data_struct_h->usr );
	strcpy(p_gn_audit_log_struct_h->h_rec_mode, p_intl_env_data_struct_h->h_mode);
	strcpy(chr_h_entity_name,"DL_DEAL");
	strcpy(p_gn_audit_log_struct_h->h_entity_name, chr_h_entity_name);
	strcpy(p_gn_audit_log_struct_h->h_log_time, APL_NULL_STRING);
        if(strcmp(p_sys_dl_deal_struct_h_a->h_classofdl,"59") == 0)
	strcpy(p_gn_audit_log_struct_h->h_comments, "SHORTAGE TRADE");
	
	if(strcmp(p_sys_dl_deal_struct_h_a->h_misinfo,"PARTIAL PREMATCH") == 0)
	     strcpy(p_gn_audit_log_struct_h->h_comments, "PARTIAL PREMATCH TRADE");
	
		if ( APL_FAILURE ==  DL_InsAuditLog( 	p_gn_audit_log_struct_h, p_sys_dl_deal_struct_h_a,
				l_debug_info_ptr) ) 
		{
			APL_GOBACK_FAIL;
		}
	}
        /* Added by Shradha for Kotak Phase 2 IOP Starts */

/* Kotak Web UAT .. Registration Processing Code is not required ..
	if ( strlen( p_sys_dl_deal_struct_h_a->h_status_reg ) )
	{
		if ( APL_FAILURE == DL_Proc_Reg(	p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															p_sys_dl_deal_struct_h_a->h_delrecdate,
															p_sys_dl_deal_struct_h_a->h_instrdate,
															&p_sys_dl_deal_struct_h_a->h_qty,
															&p_sys_dl_deal_struct_h_a->h_qty,
															p_sys_dl_deal_struct_h_a->h_status_reg[0],
															p_intl_env_data_struct_h,
															l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
	}
*/

	

	if ( APL_FAILURE == DL_Rtv_DLDropToHis( 	p_sys_dl_deal_struct_h_a->h_instrdate,
														p_sys_dl_deal_struct_h_a->h_moneydate,
														p_sys_dl_deal_struct_h_a->h_pos_stat,
														p_sys_dl_deal_struct_h_a->h_dealcd[0],
														&p_sys_dl_deal_struct_h_a->h_mcomplquantity,
														&p_sys_dl_deal_struct_h_a->h_complquantity,
														&p_sys_dl_deal_struct_h_a->h_qty,
														chr_l_candropdt,
														l_debug_info_ptr ) )
	{
		APL_GOBACK_FAIL;
	}

	

	if ( strlen( chr_l_candropdt ) != 0 )
	{
		if ( APL_FAILURE == DL_Chk_TrdCanDrop(	chr_l_candropdt,
															p_sys_dl_deal_struct_h_a->h_dl_client,
															p_sys_dl_deal_struct_h_a->h_indentity_no,
															l_debug_info_ptr ) )
		{
			APL_GOBACK_FAIL;
		}
	}

	if ( APL_FAILURE == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_SUCCESS;
	}
	else
	{
		APL_GOBACK_FAIL;
	}

	RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE,
							"Exiting DL_Proc_Trd with Success\n",
							NULL,
							p_intl_env_data_struct_h );
		}
		APL_FREE(l_dl_dealaudit_struct_hb_a);
		APL_FREE(p_ca_gn_audit_log_struct_h);
		APL_FREE(p_gn_audit_log_struct_h);
		return(APL_SUCCESS);

	RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE,
							"Exiting DL_Proc_Trd with Errors\n",
							NULL,
							p_intl_env_data_struct_h );
		}
		APL_FREE(l_dl_dealaudit_struct_hb_a);
		APL_FREE(p_ca_gn_audit_log_struct_h);
		APL_FREE(p_gn_audit_log_struct_h);
		return(APL_FAILURE);
}

/******************************* NEW COADING FOR DL_BIFDET *************************************************/





/******************************* NEW COADING FOR DL_BIFDET *************************************************/
