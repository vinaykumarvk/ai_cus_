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
 * Module Name         :                Deal
 *
 * File Name           :                DL_WebProc_Populate.c
 *
 * Description         :
 *
 *
 *            Version Control Block
 *
 * Date        Version          Author               Description                        RFS No.
 * ---------   --------  ---------------  --------------------- -----------
 *      06/03/2007      1.0                    Amit Kumar          Deal Upload
 * 29/11/2011 1.1        Mangesh            Web alleged enh      ISKB_4837
 *********************************************************************/




#include "MS_Swift.h"
#include "WI_Interface.h"
#include "Intellect_Common.h"




/*Added by amitk for Web module on 06-03-2007*/
int Populate_WEB_DEAL(WI_DEAL_STRUCT_H *p_wi_deal_struct_h,char * chr_p_param_str)
{
	char l_instr_cod_isi[131]; // Kalyan
	char l_tdeal_cd[4]; 	   // Kalyan
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);

        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
                   printf("\n HERE ..");
        //void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_WEB_DEAL \n",NULL,NULL);
                   printf("\n HERE0 ..");
		fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"CLIENT",p_wi_deal_struct_h -> h_client);
        CO_Rtv_DataString(chr_p_param_str,"IDENTIY_NO",p_wi_deal_struct_h -> h_identiy_no);
        //CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",p_wi_deal_struct_h -> h_deal_cd); Kalyan
        CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",l_tdeal_cd);

	printf("KS -- Deal_Cd selected is .. %s",l_tdeal_cd);
	if(strcmp(l_tdeal_cd,"RVP")==0)
	{
		strcpy(p_wi_deal_struct_h -> h_deal_cd,"4");
	}
	else if (strcmp(l_tdeal_cd,"DVP")==0)
	{
		strcpy(p_wi_deal_struct_h -> h_deal_cd,"3");
	}
	else if (strcmp(l_tdeal_cd,"RF")==0)
        {
                strcpy(p_wi_deal_struct_h -> h_deal_cd,"2");
        }
        else if (strcmp(l_tdeal_cd,"DF")==0)
        {
                strcpy(p_wi_deal_struct_h -> h_deal_cd,"1");
        }
	else
	{
		strcpy(p_wi_deal_struct_h -> h_deal_cd,l_tdeal_cd);
	}

        //CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",p_wi_deal_struct_h -> h_instr_code); Kalyan
       	//CO_Rtv_DataString(chr_p_param_str,"INSTR_NAME",p_wi_deal_struct_h -> h_instr_name); Kalyan
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CODE",l_instr_cod_isi); 
	if(strlen(l_instr_cod_isi)> 12)
	{
		printf("KS -- Given Instrument Code value is Greater than 12 .. Think it is Instrument Name\n");
		strcpy(p_wi_deal_struct_h -> h_instr_name,l_instr_cod_isi);
	}
	else
	{
		strcpy(p_wi_deal_struct_h -> h_instr_code,l_instr_cod_isi);
        	CO_Rtv_DataString(chr_p_param_str,"INSTR_NAME",p_wi_deal_struct_h -> h_instr_name);
	}
        CO_Rtv_DataDbl(chr_p_param_str,"QTY",&(p_wi_deal_struct_h -> h_qty));
                   printf("\n HERE1 ..");
		fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"EXCH_CODE",p_wi_deal_struct_h -> h_exch_code);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",p_wi_deal_struct_h -> h_deal_date);
        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_wi_deal_struct_h -> h_cost));
        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",p_wi_deal_struct_h -> h_setl_date);
        CO_Rtv_DataDbl(chr_p_param_str,"NET_AMT",&(p_wi_deal_struct_h -> h_net_amt));
	CO_Rtv_DataDbl(chr_p_param_str,"RATE",&(p_wi_deal_struct_h -> h_gross_rate)); /*JC21-04*/
                   printf("\n HERE2 ..");
		fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"MKT_TYPE",p_wi_deal_struct_h -> h_mkt_type);
        CO_Rtv_DataDbl(chr_p_param_str,"BROKERCOMM",&(p_wi_deal_struct_h -> h_brokercomm));
        CO_Rtv_DataDbl(chr_p_param_str,"STX_COMM",&(p_wi_deal_struct_h -> h_stx_comm));
        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",p_wi_deal_struct_h -> h_domestic_cpclt);
        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT_NAME",p_wi_deal_struct_h -> h_domestic_cpclt_name);
                   printf("\n HERE3 ..");
		fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"CLH_FLG",p_wi_deal_struct_h -> h_clh_flag);

        if(strcmp(p_wi_deal_struct_h ->h_clh_flag,"C") !=0 && strcmp(p_wi_deal_struct_h ->h_clh_flag,"D") !=0)
        {
        	printf("KS -- Going for clearing house check... \n");
                if(strcmp(p_wi_deal_struct_h ->h_clh_flag,"CH") ==0 )
                {
                	strcpy(p_wi_deal_struct_h ->h_clh_flag,"C");
                }
                else if(strcmp(p_wi_deal_struct_h ->h_clh_flag,"HD")==0)
                {
                	strcpy(p_wi_deal_struct_h ->h_clh_flag,"D");
                }
                else 
                {
                	strcpy(p_wi_deal_struct_h ->h_clh_flag,"C");
                } 
                printf("KS -- clearing house is  [%s]... \n",p_wi_deal_struct_h ->h_clh_flag);
                //strcpy(p_wi_deal_struct_h ->h_clh_flag,"C");
                printf("KS -- clearing house is  [%s]... \n",p_wi_deal_struct_h ->h_clh_flag);
       }

	printf("KS -- 113 clearing house flag is - [%s]\n",p_wi_deal_struct_h -> h_clh_flag);
        CO_Rtv_DataString(chr_p_param_str,"FX_REQD",p_wi_deal_struct_h -> h_fx_reqd);
	printf("KS -- 115 clearing house flag is - [%s]\n",p_wi_deal_struct_h -> h_clh_flag);
	printf("KS -- 117 fx reqd flag is - [%s]\n",p_wi_deal_struct_h -> h_fx_reqd);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",p_wi_deal_struct_h -> h_maker);
	printf("MAKER -- |%s|\n", p_wi_deal_struct_h -> h_maker);
		fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",p_wi_deal_struct_h -> h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",p_wi_deal_struct_h -> h_checker);
                   printf("\n HERE4 ..");
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",p_wi_deal_struct_h -> h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_STAT",p_wi_deal_struct_h -> h_deal_stat);
        CO_Rtv_DataString(chr_p_param_str,"PROC_FLAG",p_wi_deal_struct_h -> h_proc_flag);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",p_wi_deal_struct_h -> h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"CONTRACT_CD",p_wi_deal_struct_h -> h_contract_cd);
        /* Added by Mangesh for Alleged deal creation Enh*/
	CO_Rtv_DataDbl(chr_p_param_str,"STAMP_DUTY",&(p_wi_deal_struct_h -> h_stamp_duty));
         printf("\n Leaving Populate_WI_DEAL ..");

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_WEB_DEAL \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_WEB_DEAL \n",NULL,NULL);
        return 1;
}
/*Added by amitk for Web module on 06-03-2007*/

/* JC - RFS_CA_020 -- Start */
int Populate_CA_INSTRUCTION(CA_INSTRUCTION_STRUCT_H *p_ca_instruction_struct_h,char * p_param_data)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);

        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_CA_INSTRUCTION\n",NULL,NULL);

        printf("\n\nPARAM DATA = |%s|\n",p_param_data);

        CO_Rtv_DataString(p_param_data,"CORP_ID",p_ca_instruction_struct_h -> h_corp_id);
        CO_Rtv_DataString(p_param_data,"INSTR_CODE",p_ca_instruction_struct_h -> h_instr_code);
        CO_Rtv_DataString(p_param_data,"SECURITIES_ACC",p_ca_instruction_struct_h -> h_cln_code);
        CO_Rtv_DataString(p_param_data,"EVENT_TYPE",p_ca_instruction_struct_h -> h_ca_event);
        CO_Rtv_DataString(p_param_data,"INSTRUC_DATE",p_ca_instruction_struct_h -> h_instruc_date);
        CO_Rtv_DataDbl(p_param_data,"APP_INSTRUCT_INP",&(p_ca_instruction_struct_h -> h_inp_qty));
        CO_Rtv_DataDbl(p_param_data,"OVERSUB_INSTRUCT_INP",&(p_ca_instruction_struct_h -> h_over_sub));
        CO_Rtv_DataString(p_param_data,"MAKER",p_ca_instruction_struct_h -> h_maker);
        CO_Rtv_DataString(p_param_data,"MAKER_DT",p_ca_instruction_struct_h -> h_maker_dt);
        CO_Rtv_DataString(p_param_data,"CHECKER",p_ca_instruction_struct_h -> h_checker);
        CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_ca_instruction_struct_h -> h_checker_dt);
        CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_ca_instruction_struct_h -> h_access_stamp);
        CO_Rtv_DataString(p_param_data,"INSTRUCTED",p_ca_instruction_struct_h -> h_instructed);
        CO_Rtv_DataDbl(p_param_data,"NOACT_INSTRUCT_INP",&(p_ca_instruction_struct_h -> h_no_action));
        CO_Rtv_DataInt(p_param_data,"NUM_OF_RESOLUTIONS",&(p_ca_instruction_struct_h -> h_num_of_resolutions));

                printf("\nCORP_ID = |%s|\n",p_ca_instruction_struct_h -> h_corp_id);
                printf("INSTR_CODE = |%s|\n",p_ca_instruction_struct_h -> h_instr_code);
                printf("CLN_CODE = |%s|\n",p_ca_instruction_struct_h -> h_cln_code);
                printf("CA_EVENT = |%s|\n",p_ca_instruction_struct_h -> h_ca_event);
                printf("INSTRUC_DATE = |%s|\n",p_ca_instruction_struct_h -> h_instruc_date);
                printf("INP_QTY = |%lf|\n",p_ca_instruction_struct_h -> h_inp_qty);
                printf("OVER_SUB = |%lf|\n",p_ca_instruction_struct_h -> h_over_sub);
                printf("MAKER = |%s|\n",p_ca_instruction_struct_h -> h_maker);
                printf("MAKER_DT = |%s|\n",p_ca_instruction_struct_h -> h_maker_dt);
                printf("ACCESS_STAMP = |%s|\n",p_ca_instruction_struct_h -> h_access_stamp);
                printf("INSTRUCTED = |%s|\n",p_ca_instruction_struct_h -> h_instructed);
                printf("NO_ACTION = |%lf|\n",p_ca_instruction_struct_h -> h_no_action);
                printf("NUM_OF_RESOLUTIONS = |%d|\n",p_ca_instruction_struct_h -> h_num_of_resolutions);


        RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_CA_INSTRUCTION\n",NULL,NULL);
        return 0;

        RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_CA_INSTRUCTION\n",NULL,NULL);
        return 1;
}
/* JC - RFS_CA_020 -- End */

// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - Start
int Populate_WEB_MANUAL_MSG(WI_WEB_MANUAL_MSG_STRUCT_H *p_web_manual_msg_struct_h,char *p_param_data)
{
			
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
        printf("\n\nPARAM DATA = |%s|\n",p_param_data);

        CO_Rtv_DataString(p_param_data,"CLIENT_CODE",p_web_manual_msg_struct_h -> h_client_code);
        CO_Rtv_DataInt(p_param_data,"SERIAL_NO",(int *) &(p_web_manual_msg_struct_h -> h_serial_no));
        CO_Rtv_DataString(p_param_data,"INPUT_DATE",p_web_manual_msg_struct_h -> h_input_date);
        CO_Rtv_DataString(p_param_data,"INFORMATION",p_web_manual_msg_struct_h -> h_information);
        CO_Rtv_DataString(p_param_data,"MAKER",p_web_manual_msg_struct_h -> h_maker);
        CO_Rtv_DataString(p_param_data,"MAKER_DT",p_web_manual_msg_struct_h -> h_maker_dt);
        CO_Rtv_DataString(p_param_data,"CHECKER",p_web_manual_msg_struct_h -> h_checker);
        CO_Rtv_DataString(p_param_data,"CHECKER_DT",p_web_manual_msg_struct_h -> h_checker_dt);
        CO_Rtv_DataString(p_param_data,"ACCESS_STAMP",p_web_manual_msg_struct_h -> h_access_stamp);
        CO_Rtv_DataString(p_param_data,"STATUS",p_web_manual_msg_struct_h -> h_status);

        printf("\n CLIENT_CODE = |%s|\n",p_web_manual_msg_struct_h -> h_client_code);
        printf(" SERIAL_NO = |%d|\n",p_web_manual_msg_struct_h -> h_serial_no);
        printf(" INPUT_DATE = |%s|\n",p_web_manual_msg_struct_h -> h_input_date);
        printf(" INFORMATION = |%s|\n",p_web_manual_msg_struct_h -> h_information);
        printf(" MAKER = |%s|\n",p_web_manual_msg_struct_h -> h_maker);
        printf(" MAKER_DT = |%s|\n",p_web_manual_msg_struct_h -> h_maker_dt);
        printf(" CHECKER = |%s|\n",p_web_manual_msg_struct_h -> h_checker);
        printf(" CHECKER_DT = |%s|\n",p_web_manual_msg_struct_h -> h_checker_dt);
        printf(" ACCESS_STAMP = |%s|\n",p_web_manual_msg_struct_h -> h_access_stamp);
        printf(" STATUS = |%s|\n",p_web_manual_msg_struct_h -> h_status); 

	RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_WEB_MANUAL_MSG \n",NULL,NULL);
        return 0;

        RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_WEB_MANUAL_MSG \n",NULL,NULL);
        return 1;

}
// By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - End

//Added For PMS - start
int Populate_WEB_PMS_DEAL(WI_DEAL_PMS_STRUCT_H *p_wi_pms_deal_struct_h,char * chr_p_param_str)
{
        void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
        void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
        void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
                   printf("\n HERE ..");
        CO_ProcMonitor(APL_OUT_FILE,"Entered Populate_WEB_PMS_DEAL \n",NULL,NULL);
                   printf("\n HERE0 ..");
                fflush(stdout);
        CO_Rtv_DataString(chr_p_param_str,"DL_CLIENT",p_wi_pms_deal_struct_h -> h_sell_client);
        CO_Rtv_DataString(chr_p_param_str,"CLN_DEPOACC",p_wi_pms_deal_struct_h -> h_buy_client);
        CO_Rtv_DataString(chr_p_param_str,"INSTR_CD",p_wi_pms_deal_struct_h ->h_instr_isin);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_DATE",p_wi_pms_deal_struct_h ->h_deal_date);
        CO_Rtv_DataDbl(chr_p_param_str,"ORIG_QTY",&(p_wi_pms_deal_struct_h -> h_qty));
        CO_Rtv_DataDbl(chr_p_param_str,"COST",&(p_wi_pms_deal_struct_h -> h_cost));
        CO_Rtv_DataString(chr_p_param_str,"DOMESTIC_CPCLT",p_wi_pms_deal_struct_h -> h_domestic_cpclt);
        CO_Rtv_DataString(chr_p_param_str,"CP_CLT",p_wi_pms_deal_struct_h -> h_cpclt);
        CO_Rtv_DataDbl(chr_p_param_str,"ORIG_QTY",&(p_wi_pms_deal_struct_h->h_origquantity));
        CO_Rtv_DataDbl(chr_p_param_str,"AMOUNT",&(p_wi_pms_deal_struct_h->h_amt));
        CO_Rtv_DataDbl(chr_p_param_str,"NET_AMT",&(p_wi_pms_deal_struct_h-> h_net_amt));
        CO_Rtv_DataString(chr_p_param_str,"CLH_FLG",p_wi_pms_deal_struct_h-> h_clh_flg);
        CO_Rtv_DataString(chr_p_param_str,"EX_ARENA",(char *)p_wi_pms_deal_struct_h->h_ex_arena);
        CO_Rtv_DataString(chr_p_param_str,"SETL_DATE",(char *)p_wi_pms_deal_struct_h->h_setldt);
        CO_Rtv_DataString(chr_p_param_str,"DEAL_CD",(char *)p_wi_pms_deal_struct_h->h_dealcd);
        CO_Rtv_DataString(chr_p_param_str,"ACCESS_STAMP",(char *)p_wi_pms_deal_struct_h->h_access_stamp);
        CO_Rtv_DataString(chr_p_param_str,"DL_CLASS",(char *)p_wi_pms_deal_struct_h->h_classofdl);
        CO_Rtv_DataString(chr_p_param_str,"ENTRY",(char *)p_wi_pms_deal_struct_h->h_entry);
        CO_Rtv_DataString(chr_p_param_str,"FX_REQD",(char *)p_wi_pms_deal_struct_h->h_fx_reqd);
        CO_Rtv_DataString(chr_p_param_str,"INFO1",(char *)p_wi_pms_deal_struct_h->h_info1);
        CO_Rtv_DataString(chr_p_param_str,"MAKER",(char *)p_wi_pms_deal_struct_h->h_maker);
        CO_Rtv_DataString(chr_p_param_str,"MAKER_DT",(char *)p_wi_pms_deal_struct_h->h_maker_dt);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER",(char *)p_wi_pms_deal_struct_h->h_checker);
        CO_Rtv_DataString(chr_p_param_str,"CHECKER_DT",(char *)p_wi_pms_deal_struct_h->h_checker_dt);
        CO_Rtv_DataString(chr_p_param_str,"PARTIAL_IND_A",(char *)p_wi_pms_deal_struct_h->h_allow_part_s);
        CO_Rtv_DataString(chr_p_param_str,"PAYLOC_IND",(char *)p_wi_pms_deal_struct_h->h_ispymtlocal);
        CO_Rtv_DataString(chr_p_param_str,"REGINSTR_IND",(char *)p_wi_pms_deal_struct_h->h_reginstr_ind);
        CO_Rtv_DataString(chr_p_param_str,"SPOTTRD_IND",(char *)p_wi_pms_deal_struct_h->h_isspotdl);
        CO_Rtv_DataString(chr_p_param_str,"TRD_EXCH",(char *)p_wi_pms_deal_struct_h->h_trd_exch);
        CO_Rtv_DataString(chr_p_param_str,"TRD_MKT_TYPE",(char *)p_wi_pms_deal_struct_h->h_trd_mkt_type);
        CO_Rtv_DataString(chr_p_param_str,"TRD_SETL_NO",(char *)p_wi_pms_deal_struct_h->h_trd_setl_no);
        CO_Rtv_DataString(chr_p_param_str,"PAYIN_DT",(char *)p_wi_pms_deal_struct_h->h_payin_dt);
        CO_Rtv_DataString(chr_p_param_str,"PAYOUT_DT",(char *)p_wi_pms_deal_struct_h->h_payout_dt);
  
         printf("\n Leaving Populate_WEB_PMS_DEAL ..");

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of Populate_WEB_PMS_DEAL \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of Populate_WEB_PMS_DEAL \n",NULL,NULL);
        return 1;
}
//Added For PMS - End
