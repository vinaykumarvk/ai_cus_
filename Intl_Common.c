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
 * Module Name         :	Maintenance
 *
 * File Name           :	Intl_Common.c
 *
 * Description         :	This File contains Common Functions Related to
 *									Data Type Conversion
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author            Description			RFS No.
 * ---------   --------	 ---------------  ------------------	---------
 * 10/10/2005	1.0			Smita Bhat			New File				HDFCMT_003
 * 24/03/2022   1.1         kotubabu          Linux Migration    Kotak Implementation
 *
 *********************************************************************/

#define PURE_C_SOURCE
#include "CR_Common.h"
#include "CA_Common.h" 
#include <math.h>
#include <time.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/time.h>
	#ifdef __linux__
		#include<unistd.h>
		#include<limits.h>
	#endif

#define START_TIME	11
#define END_TIME		19
#define DELV_FREE 				"1"
#define RECEIVE_FREE				"2"
#define	TEMP_BUFF_LEN	200



int CO_Round(	double chr_p_val,
					int	 p_prec,
					double *int_p_retval)
{
   double   p_prec_double  =  0.0;
   double   p_statval      =  10.0;
   p_prec_double = p_prec * 1.0;
   

   *int_p_retval = ( floor(chr_p_val*pow(p_statval, p_prec_double) + 0.5) / pow(p_statval, p_prec_double) );
   return(APL_SUCCESS);
}



int CO_ToStr(	double chr_p_val,
						int	 p_totlen,
						int	 p_declen,
						char	*int_p_retval)
{
	char	chr_l_tgt1[30] = APL_NULL_STRING;
	char	chr_l_tgt2[30] = APL_NULL_STRING;
	char	chr_l_fmt[6]	  = APL_NULL_STRING;
	memset(chr_l_tgt1, APL_NULL_CHAR, 30);
	memset(chr_l_tgt2, APL_NULL_CHAR, 30);	
	memset(chr_l_fmt, APL_NULL_CHAR, 6);
	sprintf(chr_l_fmt, "%%.%dlf", p_declen);
	sprintf(chr_l_tgt1, chr_l_fmt, chr_p_val);
	memset(chr_l_fmt, '\0', 6); //AIX - Warnings Removal
	sprintf(chr_l_fmt, "%%%ds", p_totlen);
	sprintf(chr_l_tgt2, chr_l_fmt, chr_l_tgt1);
	strcpy(int_p_retval, chr_l_tgt2);
	return(APL_SUCCESS);
}




int CO_SplitStr(	char *p_src, 
						char p_separator, 
						int *int_p_noelem, 
						char ***p_retstr )
{
	int i=0; 
	int j=0;

	*int_p_noelem = 0;
	for (i=0;i<strlen(p_src);)
	{
		if (p_src[i++] == p_separator) (*int_p_noelem)++;
	}

	i = 0;
   /** AIX -change -- can fail if nothing is passed **/ 
  
   if (*int_p_noelem ==0 ) 
	   {
		   *p_retstr=(char **)calloc(1, sizeof(char *));
		    if (strlen(p_src)==0)
		  {
			  *(*p_retstr+0) = (char *)calloc(1, 2);
			  strcpy(*(*p_retstr+0), APL_NULL_STRING);
		  }
		 else
		  {
			*(*p_retstr+0) = (char *)calloc(1, strlen(p_src));
			strcpy(*(*p_retstr+0), p_src);
		  }
		  return APL_SUCCESS;
	   }
  /*** End **/  
	*p_retstr=(char **)calloc(*int_p_noelem, sizeof(char *));
	if (*p_retstr == NULL) 
return APL_FAILURE;
	while (1)
	{
		if (NULL == strchr(p_src, p_separator)) break;
		j = strlen(p_src) - strlen(strchr(p_src, p_separator));
		if (!j) 
		{
			*(*p_retstr+i) = (char *)calloc(1, 1+j);
			*(*(*p_retstr+i)) = '\0'; //AIX - Warnings Removal
			p_src++;
		}
		else
		{ 
			*(*p_retstr+i) = (char *)calloc(1, 1+j);
			if (*(*p_retstr+i) == NULL) return APL_FAILURE;
			strncpy(*(*p_retstr+i), p_src, j);
			(*(*p_retstr+i))[j] = '\0';
			p_src += j+1;
		} 
		i++;
		j = 0;
	}
	return APL_SUCCESS;
}


int CO_PadString(char *pc_str_to_conv, char pc_l_or_r, int p_itot_len,\
					char p_cpad_char[2], DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int int_p_ipad_len=0;
	int int_p_i_ind=0;
	//char chr_p_control_str[6]; //AIX - Warnings Removal
	//char p_pad_len[2]; //AIX - Warnings Removal
	char p_pad_char[2];
	char chr_p_creturn_str[201]={""}; /** TUX Changed it to 201 from 150 **/

	

	p_pad_char[0] = p_cpad_char[0];
	p_pad_char[1] = '\0';
	int_p_ipad_len = p_itot_len - strlen(pc_str_to_conv);

	
	if (!strcmp(pc_str_to_conv,APL_NULL_STRING))
			APL_GOBACK_FAIL;

       //AIX - Warnings Removal
	if(pc_l_or_r == '\0' )
			pc_l_or_r='L';

	if(pc_l_or_r != 'L' && pc_l_or_r != 'R' && pc_l_or_r != 'C')
				pc_l_or_r = 'L';

	if(p_itot_len == 0)
			APL_GOBACK_FAIL;

	if (!strcmp(p_pad_char , APL_NULL_STRING))
			strcpy(p_pad_char, "0");


	switch(pc_l_or_r)
	{
		case 'L':
			for (int_p_i_ind=0;int_p_i_ind<int_p_ipad_len;int_p_i_ind++)
			{
				strcat(chr_p_creturn_str, p_pad_char);
			}
			strcat(chr_p_creturn_str, pc_str_to_conv);
			strcpy(pc_str_to_conv, chr_p_creturn_str);
			APL_GOBACK_SUCCESS;
		case 'R':
			strcat(chr_p_creturn_str, pc_str_to_conv);
			for (int_p_i_ind=0;int_p_i_ind<int_p_ipad_len;int_p_i_ind++)
			{
				strcat(chr_p_creturn_str, p_pad_char);
			}
			strcpy(pc_str_to_conv, chr_p_creturn_str);
			APL_GOBACK_SUCCESS;
		case 'C':
			if(int_p_ipad_len == (int_p_ipad_len/2)*2)
			{
				for (int_p_i_ind=0;int_p_i_ind<(int_p_ipad_len/2);int_p_i_ind++)
				{
					strcat(chr_p_creturn_str, p_pad_char);
				}
				strcat(chr_p_creturn_str, pc_str_to_conv);

				for (int_p_i_ind=0;int_p_i_ind<(int_p_ipad_len/2);int_p_i_ind++)
				{
					strcat(chr_p_creturn_str, p_pad_char);
				}
			strcpy(pc_str_to_conv, chr_p_creturn_str);
			APL_GOBACK_SUCCESS;

			}
			else
			{
				for (int_p_i_ind=0;int_p_i_ind<((int_p_ipad_len+1)/2);int_p_i_ind++)
				{
					strcat(chr_p_creturn_str, p_pad_char);
				}
				strcat(chr_p_creturn_str, pc_str_to_conv);

				for (int_p_i_ind=0;int_p_i_ind<((int_p_ipad_len-1)/2);int_p_i_ind++)
				{
					strcat(chr_p_creturn_str, p_pad_char);
				}
			strcpy(pc_str_to_conv, chr_p_creturn_str);
			APL_GOBACK_SUCCESS;

			}
		default:
			APL_GOBACK_FAIL;
	}


	RETURN_SUCCESS :

		{

		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Success in GBPad_StrFn. Quitting program.\n" , NULL, NULL);
			}
		return(APL_SUCCESS);
		}

	RETURN_FAILURE :

		{
		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Failed in GBPAD_STRFn. Quitting Program. \n", NULL, NULL);
			}
		return(APL_FAILURE);//AIX Warning Removal 
		}
}



int	CO_Rtv_JulDt(	int *int_p_jul_date,
								DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	char	chr_l_now[APL_DATE_LEN]				= APL_NULL_STRING;
	char	chr_l_first_jan[APL_DATE_LEN]		= APL_NULL_STRING;
	/** Added for Staging Issue -- Evt Intimate **/
	memset(chr_l_first_jan,APL_NULL_CHAR,sizeof(chr_l_first_jan));
	memset(chr_l_now,APL_NULL_CHAR,sizeof(chr_l_now));
	/** Added for Staging Issue -- Evt Intimate **/
	
	//short int_l_flag = 0; //AIX - Warnings Removal

	


	Alert("chr_l_now before = |%s|",chr_l_now);
	fflush(stdout);

	if (APL_FAILURE == CO_RtvSysDtTime(	chr_l_now,
															l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	Alert("chr_l_now after = |%s|",chr_l_now);
	fflush(stdout);

	Alert("chr_l_first_jan before |%s|",chr_l_first_jan);
	fflush(stdout);

	strcpy(chr_l_first_jan, chr_l_now);

	Alert("chr_l_first_jan after |%s|",chr_l_first_jan);
	fflush(stdout);
	
	chr_l_first_jan[0] = '0';
	chr_l_first_jan[1] = '1';
	chr_l_first_jan[3] = '0';
	chr_l_first_jan[4] = '1';

	
	
	     
	
		if (APL_FAILURE == CO_Pro_DateComp( chr_l_first_jan,
                                    chr_l_now,
                                    int_p_jul_date, 
                                    l_debug_info_ptr ))
      {
         APL_GOBACK_FAIL
      }
			*int_p_jul_date = *int_p_jul_date + 1;
	
	APL_GOBACK_SUCCESS

	RETURN_SUCCESS : return(APL_SUCCESS);
	RETURN_FAILURE : return(APL_FAILURE);
}

int CO_Trim(	char	*p_in_str,
						char	p_char_to_be_removed,
						char	p_left_right_ind,
						char	*p_out_str,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	int int_n1=0,int_l_in_str_len=0;	
	char temp[2] = APL_NULL_STRING;

	
	if ( (p_left_right_ind != 'L') &&
		  (p_left_right_ind != 'R') )
		p_left_right_ind = 'L';

	
	if	(p_char_to_be_removed == APL_NULL_CHAR)
	{
		APL_DATA_MISSING("Char to be removed",APL_NULL_STRING,APL_NULL_STRING)
		APL_GOBACK_FAIL
	}
	
	if	(strcmp(p_in_str,APL_NULL_STRING) == 0)
	{
		APL_DATA_MISSING("Input String",APL_NULL_STRING,APL_NULL_STRING)
		APL_GOBACK_FAIL
	}
	strcpy(p_out_str,p_in_str);
	if (p_left_right_ind == 'R')
	{
		int_l_in_str_len = strlen(p_in_str) - 1;
		while(p_in_str[int_l_in_str_len] == p_char_to_be_removed)
		{
			p_out_str[int_l_in_str_len] = '\0';
			int_l_in_str_len--;
			if(int_l_in_str_len <0)
			{
				break;
			}
		}
	}
	if (p_left_right_ind == 'L')
	{
		int_l_in_str_len = strlen(p_out_str);
		temp[0]=p_char_to_be_removed;
		temp[1]='\0';
		int_n1 = strspn(p_in_str,temp);
		strncpy(p_out_str,p_in_str+int_n1,int_l_in_str_len-int_n1);
		p_out_str[int_l_in_str_len-int_n1] = '\0';
	}
	APL_GOBACK_SUCCESS

	RETURN_SUCCESS : return(APL_SUCCESS);
	RETURN_FAILURE : return(APL_FAILURE);
}




   

int CO_GenRefno(char *event_type,
		char *p_op_evt_type,
		char *deal_cd,char *p_txn_ident,DEBUG_INFO_STRUCT_H **l_debug_info_ptr )
{
	int   i=0,j=0;
	char  chr_l_now[APL_DATE_LEN]           = APL_NULL_STRING;
           /*** commented for AIX migration to remove warnings  -- Unused variable **/
	//char  chr_l_first_jan[APL_DATE_LEN]     = APL_NULL_STRING;
	int   int_p_jul_date	 						= 0; 
	
	
	char  chr_jul_date_string[100] = APL_NULL_STRING;
	char  h_txn_indentity_no[APL_TXNREFNO_LEN]	= APL_NULL_STRING;
	char chr_l_time[8]        					= APL_NULL_STRING;
	char chr_last_digit_year[2]					= APL_NULL_STRING;
	char  chr_seq_no[10] = APL_NULL_STRING; // Retro from HDFC by Ekta for ISHB_8740 on 07/08/2019
	//char l_temp_arr[30]					= APL_NULL_STRING;
	memset(h_txn_indentity_no,APL_NULL_CHAR,17);

	/* Ekta :: Retro from SBI ISSB-4122 for IB_12352 on 07/08/2019 - Start */
	long int int_return_val = 0;
	int ijk = 0;
	char chr_l_seq_num[7] = APL_NULL_STRING;
	char chr_l_zero_appender[6] = APL_NULL_STRING;

	PRO_GSEQNUM_STRUCT_H    l_pro_gseqno_struct_h;
	/* Ekta :: Retro from SBI ISSB-4122 for IB_12352 on 07/08/2019 - End */

	
	if (!strcmp(event_type,LOCN_CHANGE))
	{
		strcpy(h_txn_indentity_no,LOCN_CHANGE);
		printf("till here 7 -- Biju \n");
		if (!strcmp(deal_cd,RECEIVE_FREE))
			strcat(h_txn_indentity_no,"R");
		else if (!strcmp(deal_cd,DELV_FREE))
			strcat(h_txn_indentity_no,"D");
		printf("till here 8 -- Biju \n");
	}
	else if (!strcmp(event_type,CA_BONUS_IND))
			strcpy(h_txn_indentity_no,CA_BONUS_IND);
	else if (!strcmp(event_type,CA_BONDRD_IND))
			strcpy(h_txn_indentity_no,CA_BONDRD_IND);
	else if (!strcmp(event_type,RTS_ISSUE))
			strcpy(h_txn_indentity_no,RTS_ISSUE);
	else if (!strcmp(event_type,STOCK_DIVIDEND))
			strcpy(h_txn_indentity_no,STOCK_DIVIDEND);
	else if (!strcmp(event_type,STOCK_SPLIT))
	{
			strcpy(h_txn_indentity_no,STOCK_SPLIT);

		/** We change 6th character of ref according to sub events **/

		if (!strcmp(p_op_evt_type,"SP"))
			h_txn_indentity_no[5] = 'S';
		else if (!strcmp(p_op_evt_type,"AM"))
			h_txn_indentity_no[5] = 'A';
		else if (!strcmp(p_op_evt_type,"TO"))
			h_txn_indentity_no[5] = 'T';
		else if (!strcmp(p_op_evt_type,"SR"))
			h_txn_indentity_no[5] = 'R';
	}
	else if ( !strcmp(event_type,REV_STOCK_SPLIT))		/*** RVSL HDFCCA_035 ***/
			strcpy(h_txn_indentity_no,REV_STOCK_SPLIT);
	else if ( !strcmp(event_type,AMALGAMATION))			/*** AMAL HDFCCA_035 ***/
			strcpy(h_txn_indentity_no,AMALGAMATION);
	else if ( !strcmp(event_type,TAKEOVER)) /** TAKO HDFCCA_035 ***/
			strcpy(h_txn_indentity_no,TAKEOVER);
	else if ( !strcmp(event_type,CACR_IND)) /**For Payment Proc Of CR **/
			strcpy(h_txn_indentity_no,CACR_IND);
	else if ( !strcmp(event_type,CACV_IND))
			{	/**For Payment Proc Of CV Std 6 chracter upfront PJ**/
			/**strcpy(h_txn_indentity_no,"CA"); **/
			strcat(h_txn_indentity_no,CACV_IND);
			}
	

	else if (!strncmp(event_type,OFFER_PRIVELEGE,5))
	{
		
			strcpy(h_txn_indentity_no,event_type);
			
			
	}
	else if (!strcmp(event_type,RTS_PROC))
			strcpy(h_txn_indentity_no,RTS_PROC);
	else if ( !strcmp(event_type,"REDNOM"))
			strcpy(h_txn_indentity_no,event_type);
	/** AddedBy Biju , Applicationn and Allotment -- Begin**/
	else if(!strcmp(event_type,CA_RT_APPL_IND))
		strcpy(h_txn_indentity_no,CA_RT_APPL_IND);
	else if(!strcmp(event_type,CA_RT_ALLOT_IND))
		strcpy(h_txn_indentity_no,CA_RT_ALLOT_IND);
	else if(!strcmp(event_type,CA_BB_ALLOT_IND))
		strcpy(h_txn_indentity_no,CA_BB_ALLOT_IND);
	else if(!strcmp(event_type,CA_IPO_ALLOT_IND))
		strcpy(h_txn_indentity_no,CA_IPO_ALLOT_IND);
	else if(!strcmp(event_type,CA_PUTCALL_IND))
		strcpy(h_txn_indentity_no,CA_PUTCALL_IND);
	/** AddedBy Biju , Applicationn and Allotment -- End**/
	
	if ( !strcmp(event_type,CACV_IND)) /**For Payment Proc Of CV add deal_cd to indentity_no**/
	{
			strcat(h_txn_indentity_no,deal_cd);
	}

	if (APL_FAILURE == CO_RtvSysDtTime(chr_l_now,l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	printf("till here 9 -- Biju \n");
	i=0;						
	for (i=START_TIME;i<END_TIME;i++)
	{
		if (chr_l_now[i]!=':')
			chr_l_time[j++]=chr_l_now[i];
	}
	chr_l_time[j]='\0';
							
	i=0;
	while (chr_l_now[i]!=' ')
	{
		i++;
	}
	printf("till here 20 -- Biju \n");
	chr_last_digit_year[0]=chr_l_now[i-1];
	chr_last_digit_year[1]='\0';

   		
	printf("till here 20A -- Biju \n");

	if (APL_FAILURE==CO_Rtv_JulDt(&int_p_jul_date,
												l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	/* Ekta :: Retro from SBI ISSB-4122 for IB_12352 - Unique deal ref no. for Location change trades on 07/08/2019 - Start */
	/***** Commented by Ekta for IB_12352
	if (!strcmp(event_type,LOCN_CHANGE))
		chr_l_time[5]='\0';      
	printf("till here 21A -- Biju \n");
	***/

	if(strcmp(event_type, LOCN_CHANGE) == 0)
	{
		strcpy(l_pro_gseqno_struct_h.sequencename, "LOCCHNG_DEAL_REF_NO");
		strcpy(l_pro_gseqno_struct_h.seq_attrb_a, APL_NULL_STRING);
		strcpy(l_pro_gseqno_struct_h.seq_attrb_b, APL_NULL_STRING);
		strcpy(l_pro_gseqno_struct_h.seq_attrb_c, APL_NULL_STRING);
		l_pro_gseqno_struct_h.seq_stepby = 1;
		l_pro_gseqno_struct_h.seq_start = 1;
		l_pro_gseqno_struct_h.last_seqnum = 99999;
		l_pro_gseqno_struct_h.recycle_ind = RECYCLE_YES;

		int_return_val = CO_RtvNxtSeqNum(&l_pro_gseqno_struct_h,l_debug_info_ptr);

		if (int_return_val != APL_FAILURE)
			sprintf(chr_l_seq_num, "%d", int_return_val);
		else
			APL_GOBACK_FAIL

		if(strlen(chr_l_seq_num) < 5)
		{
			strcpy(chr_l_zero_appender, "0");
			for(ijk = 1; ijk < (5 - strlen(chr_l_seq_num)); ijk++)
			{
				strcat(chr_l_zero_appender, "0");
			}
		}

		strcpy(chr_l_time, APL_NULL_STRING);
		strcpy(chr_l_time, chr_l_zero_appender);
		strcat(chr_l_time, chr_l_seq_num);
		strcat(chr_l_time, "\0");
		printf("JC::: Sequence number used instead of date time for loc change trades is - [%s]\n", chr_l_time);
	}
	/* Ekta :: Retro from SBI ISSB-4122 for IB_12352 - Unique deal ref no. for Location change trades on 07/08/2019 - End */
	
	
	/* Ekta :: Retro from HDFC for ISHB_8740 Changes done w.r.t ref no gen so that sleep time can be remove on 07/08/2019 - START */
	if(APL_FAILURE==CO_RtvNxtEventSeqNum(chr_seq_no, l_debug_info_ptr))
	{
		APL_GOBACK_FAIL
	}
 
	Alert("\n Ekta :: chr_seq_no |%s|\n",chr_seq_no);
	/* Ekta :: Retro from HDFC for ISHB_8740 Changes done w.r.t ref no gen so that sleep time can be remove on 07/08/2019 - END */
	
 
        sprintf(chr_jul_date_string,"%d",int_p_jul_date);/*Added for AIX - Migration*/ 	
//	strcpy(chr_jul_date_string,lltostr(int_p_jul_date,l_temp_arr));	 
	printf("till here 21B -- Biju \n");

	strcat(h_txn_indentity_no,chr_last_digit_year);
	strcat(h_txn_indentity_no,chr_jul_date_string);
	
	// Ekta :: Retro from HDFC for ISHB_8740 on 07/08/2019 - START
	if (!strcmp(event_type,LOCN_CHANGE))
	strcat(h_txn_indentity_no,chr_l_time);
	else
		strcat(h_txn_indentity_no,chr_seq_no);
    // Ekta :: Retro from HDFC for ISHB_8740 on 07/08/2019 - END
	
	strcpy(p_txn_ident,h_txn_indentity_no);
	printf("till here 21 -- Biju \n");

	printf("\nREF NO = %s\n",h_txn_indentity_no);
	printf("till here 11 -- Biju \n");

	//return APL_SUCCESS;
	APL_GOBACK_SUCCESS;//AIX Warning Removal 

	printf("till here still here \n");
   RETURN_SUCCESS : return(APL_SUCCESS);
	RETURN_FAILURE:
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of CO_GenRefno().\n",
					  (DEBUG_INFO_STRUCT_H **) NULL,(INTL_ENV_DATA_STRUCT_H *)NULL );  
		}
		return APL_FAILURE;
}


int   CO_Rtv_Time( unsigned long *p_seconds, long *p_microsecs)
{
	struct timeval currtime;
	struct timezone tzp;
	if(p_seconds==NULL || p_microsecs == NULL)
		{
		 APL_GOBACK_FAIL
	   }
	 
	 if (gettimeofday(&currtime, &tzp) != 0)    
		 {
		  APL_GOBACK_FAIL
	    }
	  *p_seconds = currtime.tv_sec;  		
	  *p_microsecs = currtime.tv_usec;		
	  return APL_SUCCESS;

  RETURN_FAILURE:
	  return APL_FAILURE;
} 



void CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[8001];
        char    chr_l_str_temp2[8001];
        char    chr_l_str_temp3[8001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[8001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;


        int_l_int_len_p_str =       strlen(chr_p_str);

			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,8001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,8001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,8001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,8001);
        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

        strcpy(p_data_value,chr_l_data_value);
}
else
{
        strcpy(p_data_value,APL_NULL_STRING);

}
printf("\n Return Values is |%s|",p_data_value);
}


void CO_Rtv_DataLongString(char *chr_p_str, char *p_lbl,char *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[12001];
        char    chr_l_str_temp2[12001];
        char    chr_l_str_temp3[12001];
        char    chr_l_data_value[12001];
        char    chr_l_str_before_lbl[12001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);

			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,12001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,12001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,12001);
			memset(chr_l_data_value,APL_NULL_CHAR,12001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,12001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);
if ( strstr(chr_p_str,chr_search_lbl) != NULL)
	{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

        strcpy(p_data_value,chr_l_data_value);
}
else
{
        strcpy(p_data_value,APL_NULL_STRING);
}
}


void CO_Rtv_DataChar(char *chr_p_str, char *p_lbl,char *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);

			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

        
		  *p_data_value = chr_l_data_value[0];
}
else
{
		  *p_data_value = APL_NULL_CHAR;
}
}


/*Commented and Rewritten by kotubabu for Linux Migration -No Need for separated Code - START
#ifdef OS_SUN
void CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value)
#else
void CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value)
#endif */
void CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value)
/*Commented and Rewritten by kotubabu for Linux Migration -No Need for separated Code - END*/
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;


        int_l_int_len_p_str =       strlen(chr_p_str);

	
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

		  sscanf(chr_l_data_value,"%lf",p_data_value);	


}
else
{
	*p_data_value = 0.0;
}
printf("\n Return Values from double is |%s||%lf|",chr_l_data_value,*p_data_value);
}

void GetFloatData(char *chr_p_str, char *p_lbl,float *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);

	
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

		  sscanf(chr_l_data_value,"%f",p_data_value);	
}
else
{
	*p_data_value = 0.0;
}
printf("\n Return Values from float is |%f|",*p_data_value);
}


void CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);

			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

		  sscanf(chr_l_data_value,"%d",p_data_value);	
}
else
{
			*p_data_value = 0;
}
}


void CO_Rtv_DataLong(char *chr_p_str, char *p_lbl,long *p_data_value)
{
        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);

			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);
if ( strstr(chr_p_str,chr_search_lbl) != NULL)
{
        strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        
        strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        strcat(chr_l_data_value,APL_NULL_STRING);

        strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 

		  

		  sscanf(chr_l_data_value,"%ld",p_data_value);	
}
else
{
		*p_data_value = 0;
}
}


int CO_Rtv_ErrString(DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *p_error_desc)
{
	char *chr_l_single_error_record;

	CO_InsertMsg(*l_debug_info_ptr);

  	

  	chr_l_single_error_record =  (char *)calloc(300,sizeof(char));
  	APL_MALLOC_FAIL(chr_l_single_error_record);
  	//memset(chr_l_single_error_record,NULL,sizeof(char));
  	memset(chr_l_single_error_record,APL_NULL_CHAR,sizeof(char)); // AIX - Warnings

	strcpy(p_error_desc,APL_NULL_STRING);
	strcpy(chr_l_single_error_record,APL_NULL_STRING);

	while((*l_debug_info_ptr) != NULL)
	{

		/* Kalyan */
		
		printf("(*l_debug_info_ptr)->h_err_warn -- %d\n(*l_debug_info_ptr)->h_code -- %d\n(*l_debug_info_ptr)->h_key1 -- %s\n(*l_debug_info_ptr)->h_key2 -- %s\n(*l_debug_info_ptr)->h_key3 --  %s\n(*l_debug_info_ptr)->h_file -- %s\n (*l_debug_info_ptr)->h_line -- %d\n(*l_debug_info_ptr)->ok_ind -- %d\n (*l_debug_info_ptr)->debug_ind  -- %d\n (*l_debug_info_ptr)->msg) -- %s\n\n",(*l_debug_info_ptr)->h_err_warn,(*l_debug_info_ptr)->h_code,(*l_debug_info_ptr)->h_key1,(*l_debug_info_ptr)->h_key2,(*l_debug_info_ptr)->h_key3,(*l_debug_info_ptr)->h_file,(*l_debug_info_ptr)->h_line,(*l_debug_info_ptr)->ok_ind,(*l_debug_info_ptr)->debug_ind,(*l_debug_info_ptr)->msg);	
		sprintf(chr_l_single_error_record,"%d%c%d%c%s%c%s%c%s%c%s%c%d%c%d%c%d%c%s%c%c",(*l_debug_info_ptr)->h_err_warn,ERR_FLD_SEP,(*l_debug_info_ptr)->h_code,ERR_FLD_SEP,(*l_debug_info_ptr)->h_key1,ERR_FLD_SEP,(*l_debug_info_ptr)->h_key2,ERR_FLD_SEP,(*l_debug_info_ptr)->h_key3,ERR_FLD_SEP,(*l_debug_info_ptr)->h_file,ERR_FLD_SEP,(*l_debug_info_ptr)->h_line,ERR_FLD_SEP,(*l_debug_info_ptr)->ok_ind,ERR_FLD_SEP,(*l_debug_info_ptr)->debug_ind,ERR_FLD_SEP ,(*l_debug_info_ptr)->msg,ERR_FLD_SEP,ERR_REC_SEP);	
		if(strlen(p_error_desc) < 3700)
			strcat(p_error_desc,chr_l_single_error_record);	

		strcpy(chr_l_single_error_record,APL_NULL_STRING);
		(*l_debug_info_ptr) = (*l_debug_info_ptr)->h_next;
	}
	strcpy(chr_l_single_error_record,APL_NULL_STRING);
	
	

	APL_GOBACK_SUCCESS ;
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CO_Rtv_ErrString \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CO_Rtv_ErrString \n",NULL,NULL);
        return 1;
}


int CO_Rtv_ErrStruct(char *p_error_desc,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	char **chr_l_single_error_record;
	char **chr_l_values;
	int	int_noelem = 0;
	int	i = 0;
	int	int_l_temp = 0;

	CO_SplitStr(p_error_desc,ERR_REC_SEP, &int_noelem, &chr_l_single_error_record);

   for (i=0;i<int_noelem;++i)
   {
      CO_SplitStr(chr_l_single_error_record[i],ERR_FLD_SEP,&int_l_temp,&chr_l_values  );

	   if(   CO_Ins_NodeErrorLst(
                        l_debug_info_ptr,
                        atoi(chr_l_values[0]),
                        atoi(chr_l_values[1]),
                        chr_l_values[2],
                        chr_l_values[3],
                        chr_l_values[4],
                        atoi(chr_l_values[6]),
                        chr_l_values[5],
                        atoi(chr_l_values[7])
                     ) != APL_SUCCESS)
      return APL_FAILURE;	



   }

	APL_GOBACK_SUCCESS ;
RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CO_Rtv_ErrStruct \n",NULL,NULL);
        return 0;

/** commente for AIX migration to remove the warning-- 'RETURN_FAILURE' defined but not used **/
/** RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CO_Rtv_ErrStruct \n",NULL,NULL);
        return 1; **/
}


int   CO_Rtv_EnvStruct(INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,char *p_env_str)
{
	void  CO_Rtv_DataString(char *chr_p_str, char *p_lbl,char *p_data_value);
	void  CO_Rtv_DataDbl(char *chr_p_str, char *p_lbl,double *p_data_value);
	void  CO_Rtv_DataInt(char *chr_p_str, char *p_lbl,int *p_data_value);
printf("\n 1|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"USER",(char *)p_intl_envdatastruct_h->usr);
printf("\n 2|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"MODE",(char *)p_intl_envdatastruct_h->h_mode);
printf("\n 3|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"FUNCTIONNAME",(char *)p_intl_envdatastruct_h->processtion);
printf("\n 4|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"AUTHREQ",(char *)p_intl_envdatastruct_h->auth_req);
printf("\n 5|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"SUBPROCESS",(char *)p_intl_envdatastruct_h->subprocess);
printf("\n 6|%s|",p_env_str);
			CO_Rtv_DataString(p_env_str,"ACTION",(char *)p_intl_envdatastruct_h->h_process); 
printf("\n 7|%s|",p_env_str);

		APL_GOBACK_SUCCESS;

RETURN_SUCCESS:

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CO_Rtv_EnvStruct \n",NULL,NULL);
        return 0;

/** commente for AIX migration to remove the warning-- 'RETURN_FAILURE' defined but not used **/

/** RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CO_Rtv_EnvStruct \n",NULL,NULL);
        return 1; **/
		 
}


int CO_Ins_NodeErrorLst(
      DEBUG_INFO_STRUCT_H   **p_debug_info_struct_h_b,
      int            h_err_warn,
      int            h_code,
      char*          h_key1,
      char*          h_key2,
      char*          h_key3,
      int            h_line,
      char*          h_file,
      int            ok_ind
)
{

   DEBUG_INFO_STRUCT_H **temp     = p_debug_info_struct_h_b;
   int            int_no_errors=  0;

   while ( (*temp) != NULL)
   {
      temp = &((*temp)->h_next);
      if (  ((*temp)->h_err_warn == WARNING) &&
            ((*temp)->ok_ind       == OK)
         )
         continue;
      else
         int_no_errors++;
   }

   if (  int_no_errors > APL_MAX_ERRORS )
      return   APL_FAILURE;

   if ( ( (*temp) = calloc(1,sizeof(DEBUG_INFO_STRUCT_H)) ) == NULL )
      return APL_FAILURE ;

   (*temp)->h_err_warn  =  h_err_warn;
   (*temp)->h_code           =  h_code;
   (*temp)->h_line           =  h_line;
   (*temp)->ok_ind        =  ok_ind;
   (*temp)->debug_ind     =  APL_DEBUG_YES; 

   strcpy((*temp)->h_key1,h_key1);
   strcpy((*temp)->h_key2,h_key2);
   strcpy((*temp)->h_key3,h_key3);
   strcpy((*temp)->h_file,h_file);

	(*temp)->h_next =  NULL;
   return APL_SUCCESS;
}



int CO_RemoveNewLine(char *p_str_to_rep, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   char  chr_l_buf[TEMP_BUFF_LEN] =  APL_NULL_STRING;
   char  chr_l_carriage_return =  13;
   char  chr_l_line_feed       =  10;
   int   int_l_prev_space      =  0;
   int   i                 =  0;
   int   int_l_skips           =  0;

   printf("Entered processtion CO_RemoveNewLine \n");
   for(i=0; i < strlen(p_str_to_rep); i++)
   {
      if((chr_l_carriage_return == p_str_to_rep[i]) || (chr_l_line_feed == p_str_to_rep[i]) || (' ' == p_str_to_rep[i]))
      {
         if(i > (int_l_prev_space + 1) )
         {
            chr_l_buf[i - int_l_skips] = ' ';
         }
         else
         {
            int_l_skips++;
         }
         int_l_prev_space = i;
      }
      else
      {
         chr_l_buf[i - int_l_skips] = p_str_to_rep[i];
      }
   }
   strcpy(p_str_to_rep, chr_l_buf);

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS:
   {
      printf("Exiting processtion CO_RemoveNewLine with success \n");
      return(APL_SUCCESS);
   }
}



void CO_Rtv_FldFromMisc(char *chr_p_str, char *p_lbl,char *p_data_value)
{
//AIX - Warnings Removal
#ifdef DATA_FIELD_SEPRTR
#undef DATA_FIELD_SEPRTR
#endif
#ifdef DATA_VALUE_SEPRTR
#undef DATA_VALUE_SEPRTR
#endif
#define DATA_FIELD_SEPRTR '#'
#define DATA_VALUE_SEPRTR '|'

        char    chr_search_lbl[100];
        char    chr_l_str_temp1[4001];
        char    chr_l_str_temp2[4001];
        char    chr_l_str_temp3[4001];
        char    chr_l_data_value[4001];
        char    chr_l_str_before_lbl[4001];
        int     int_l_int_len_p_str =       0;
        int     int_l_int_len_strtemp1      =       0;
        int     int_l_int_len_strtemp2      =       0;
        int     int_l_int_len_strtemp3      =       0;

        int_l_int_len_p_str =       strlen(chr_p_str);
			
			memset(chr_search_lbl,APL_NULL_CHAR,100);
			memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
			memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
			memset(chr_l_data_value,APL_NULL_CHAR,4001);

			memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

        strcpy(chr_search_lbl,APL_NULL_STRING);
        strcpy(chr_l_str_temp1,APL_NULL_STRING);
        strcpy(chr_l_str_temp2,APL_NULL_STRING);
        strcpy(chr_l_str_temp3,APL_NULL_STRING);
        strcpy(chr_l_data_value,APL_NULL_STRING);
        strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

        sprintf(chr_search_lbl,"%c%s%c",DATA_FIELD_SEPRTR,p_lbl,DATA_VALUE_SEPRTR);

        if (strstr(chr_p_str,chr_search_lbl) != NULL)
			 {
        	strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));

        	strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));

        	strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));

        	int_l_int_len_strtemp1      =       strlen(chr_l_str_temp1);
        	int_l_int_len_strtemp2      =       strlen(chr_l_str_temp2);
        	int_l_int_len_strtemp3      =       strlen(chr_l_str_temp3);

        	strncpy(chr_l_data_value,chr_l_str_temp2+1,int_l_int_len_strtemp2-int_l_int_len_strtemp3-1);
        	strcat(chr_l_data_value,APL_NULL_STRING);

        	strncpy(chr_l_str_before_lbl,chr_p_str,int_l_int_len_p_str-int_l_int_len_strtemp1);
        	strcpy(chr_p_str,strcat(chr_l_str_before_lbl,chr_l_str_temp3)); 
		  		printf("\n Leaving CO_Rtv_FldFromMisc searching with chr_value :%s: ",chr_l_data_value); 

        	strcpy(p_data_value,chr_l_data_value);
			 }
			 else
			 {
        	strcpy(p_data_value,APL_NULL_STRING);
			 }
}


void CO_Mod_Misinfo(char *chr_p_str, char *p_lbl,char *p_data_value)
{
#define DATA_FIELD_SEPRTR '#'
#define DATA_VALUE_SEPRTR '|'

	char chr_search_lbl[100];
	char chr_l_str_temp1[4001];
	char chr_l_str_temp2[4001];
	char chr_l_str_temp3[4001];
	char chr_l_data_value[4001];
	char chr_l_str_before_lbl[4001];

	int int_l_int_len_strtemp2=0;
	int int_l_int_len_strtemp3=0;
	int int_l_int_len_p_str=0;
	int int_l_int_len_new_val=0;
	int int_l_int_len_strtemp1=0;
   int x=0;
	int int_found=0;

	memset(chr_search_lbl,APL_NULL_CHAR,100);
	memset(chr_l_str_temp1,APL_NULL_CHAR,4001);
	memset(chr_l_str_temp2,APL_NULL_CHAR,4001);
	memset(chr_l_str_temp3,APL_NULL_CHAR,4001);
	memset(chr_l_data_value,APL_NULL_CHAR,4001);

	memset(chr_l_str_before_lbl,APL_NULL_CHAR,4001);

	strcpy(chr_search_lbl,APL_NULL_STRING);
	strcpy(chr_l_str_temp1,APL_NULL_STRING);
	strcpy(chr_l_str_temp2,APL_NULL_STRING);
	strcpy(chr_l_str_temp3,APL_NULL_STRING);
	strcpy(chr_l_data_value,APL_NULL_STRING);
	strcpy(chr_l_str_before_lbl,APL_NULL_STRING);

   sprintf(chr_search_lbl,"%s%c",p_lbl,DATA_VALUE_SEPRTR);

	if (strstr(chr_p_str,chr_search_lbl)  != NULL)
 {
	strcpy(chr_l_str_temp1,strstr(chr_p_str,chr_search_lbl));
   strcpy(chr_l_str_temp2,strchr(chr_l_str_temp1,DATA_VALUE_SEPRTR));
	strcpy(chr_l_str_temp3,strchr(chr_l_str_temp2,DATA_FIELD_SEPRTR));
 }
 else
 {
		strcpy(chr_l_str_temp1,APL_NULL_STRING);
		strcpy(chr_l_str_temp2,APL_NULL_STRING);
		strcpy(chr_l_str_temp3,APL_NULL_STRING);
 }
	if (strlen(chr_l_str_temp1)==0)
	{
	     printf ("\nNo Match Found\n");
	     int_found=1;
	}
	else
   {
	     int_found=0;
	}

   if (!int_found)
	{
	  int_l_int_len_strtemp2=strlen(chr_l_str_temp2);
     int_l_int_len_strtemp3=strlen(chr_l_str_temp3);
	  int_l_int_len_new_val=strlen(chr_l_data_value);
     int_l_int_len_p_str=strlen(chr_p_str);
	  int_l_int_len_strtemp1=strlen(chr_l_str_temp1);

     strncpy(chr_l_str_temp2+1,chr_l_data_value,int_l_int_len_new_val); 

	  x=int_l_int_len_new_val+1;
	  strncpy(chr_l_str_temp2+x,chr_l_str_temp3,int_l_int_len_strtemp3); 
	  int_l_int_len_strtemp2=strlen(chr_l_str_temp2);

	  x=strlen(p_lbl);

	  strncpy(p_lbl+x,chr_l_str_temp2,int_l_int_len_strtemp2); 

	  x=int_l_int_len_p_str-int_l_int_len_strtemp1;
	  strcpy(chr_p_str+x,p_lbl);
	  printf("%s\n",chr_p_str);
   } 
}

/*Smita - HDFCMT_003 - Instrument Master*/
char * ltoa(long p_long)
{
	char * l_temp_arr;
	l_temp_arr = calloc(30,sizeof(char));
 sprintf(l_temp_arr,"%ld",p_long);
 return l_temp_arr;
}
/*Smita - HDFCMT_003 - Instrument Master*/

int ltoa_r(long p_long,char *p_return, int p_length)
{
	char l_temp_arr[30]=APL_NULL_STRING;
//strncpy(p_return,lltostr(p_long,l_temp_arr),p_length); 
 sprintf (l_temp_arr, "%ld", p_long);
  strncpy(p_return,l_temp_arr,p_length);
 strcat(p_return,APL_NULL_STRING);
 return (1);
}

double round(double x)
{
	return (double)((int)(x + .5));
}
/* Kalyan */
int CO_Rtv_Error(DEBUG_INFO_STRUCT_H **l_debug_info_ptr,char *p_error_desc)
{
	char *chr_l_single_error_record;

	CO_InsertMsg(*l_debug_info_ptr);

  	

  	chr_l_single_error_record =  (char *)calloc(300,sizeof(char));
  	APL_MALLOC_FAIL(chr_l_single_error_record);
  	memset(chr_l_single_error_record,'\0',sizeof(char)); //AIX - Warnings Removal

	strcpy(p_error_desc,APL_NULL_STRING);
	strcpy(chr_l_single_error_record,APL_NULL_STRING);

	/* Web UAT Fixes ... Changes have been done to properly show error message in INFO1 field of deal */
	while((*l_debug_info_ptr) != NULL)
	{
		if ( 	( strcmp((*l_debug_info_ptr)->h_key1,APL_NULL_STRING)!=0) &&
				( strcmp((*l_debug_info_ptr)->h_key2,APL_NULL_STRING)!=0) &&
				( strcmp((*l_debug_info_ptr)->h_key3,APL_NULL_STRING)!=0) 
			)
			{
				sprintf(chr_l_single_error_record,"[%s][%s][%s]-%s%c%c",(*l_debug_info_ptr)->h_key1,(*l_debug_info_ptr)->h_key2,(*l_debug_info_ptr)->h_key3,(*l_debug_info_ptr)->msg,ERR_FLD_SEP,ERR_REC_SEP);	
			}
		else if (( strcmp((*l_debug_info_ptr)->h_key1,APL_NULL_STRING)!=0) &
					( strcmp((*l_debug_info_ptr)->h_key2,APL_NULL_STRING)!=0) &&
					( strcmp((*l_debug_info_ptr)->h_key3,APL_NULL_STRING)==0)
					)
			{
				sprintf(chr_l_single_error_record,"[%s][%s]-%s%c%c",(*l_debug_info_ptr)->h_key1,(*l_debug_info_ptr)->h_key2,(*l_debug_info_ptr)->msg,ERR_FLD_SEP,ERR_REC_SEP);	

			}	
		else if (( strcmp((*l_debug_info_ptr)->h_key1,APL_NULL_STRING)!=0) &
					( strcmp((*l_debug_info_ptr)->h_key2,APL_NULL_STRING)==0) &&
					( strcmp((*l_debug_info_ptr)->h_key3,APL_NULL_STRING)==0)
					)
			{
				sprintf(chr_l_single_error_record,"[%s]-%s%c%c",(*l_debug_info_ptr)->h_key1,(*l_debug_info_ptr)->msg,ERR_FLD_SEP,ERR_REC_SEP);	

			}	
		else if (( strcmp((*l_debug_info_ptr)->h_key1,APL_NULL_STRING)==0) &
					( strcmp((*l_debug_info_ptr)->h_key2,APL_NULL_STRING)==0) &&
					( strcmp((*l_debug_info_ptr)->h_key3,APL_NULL_STRING)==0)
					)
			{
				sprintf(chr_l_single_error_record,"%s%c%c",(*l_debug_info_ptr)->msg,ERR_FLD_SEP,ERR_REC_SEP);	
			}	


		if(strlen(p_error_desc) < 3700)
			strcat(p_error_desc,chr_l_single_error_record);	

		printf("KS --- %s \n",chr_l_single_error_record);

		strcpy(chr_l_single_error_record,APL_NULL_STRING);
		(*l_debug_info_ptr) = (*l_debug_info_ptr)->h_next;
	}
	strcpy(chr_l_single_error_record,APL_NULL_STRING);
	
	

	APL_GOBACK_SUCCESS ;
RETURN_SUCCESS:

	printf("KS -- Returning --- [%s] \n",p_error_desc);

        CO_ProcMonitor(APL_OUT_FILE,"Exiting successfully  out of CO_Rtv_ErrString \n",NULL,NULL);
        return 0;

RETURN_FAILURE:
        CO_ProcMonitor(APL_OUT_FILE,"Exiting unsuccesfully out of CO_Rtv_ErrString \n",NULL,NULL);
        return 1;
}
