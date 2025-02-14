/*
 * COPYRIGHT NOTICE
 * *
 * *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 * *
 * *   These materials are confidential and proprietary to
 * *    Polaris Software Lab Limited and no part of these materials should
 * *    be reproduced, published, transmitted or distributed in any form or
 * *    by any means, electronic, mechanical, photocopying, recording or
 * *    otherwise, or stored in any information storage or retrieval system
 * *    of any nature nor should the materials be disclosed to third parties
 * *    or used in any other manner for which this is not authorized, without
 * *    the prior express written authorization of Polaris Software Lab Limited.
 * */
/*******************************************************************************
 * *
 * * Module Name         :         Intellect Reports
 * *
 * * File Name           :         GenReport.pc
 * *
 * * Description         :         This file contains all functions for Reports.
 * *
 * *            Version Control Block
 * *
 * * Date        Version     Author              Description     RFS No.
 * * ---------   --------  ---------------  ----------------------------------
 * * 23/02/2006   1.0        Amit B              New File      HDFC_Reports1
 *
 * * *****************************************************************************/
#include "CR_Common.h"
#include "CO_Commdef.h"
#include "CO_OthStructdef.h"
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define APL_CLNREP_DESC "CLIENT REPORT"
extern FILE* g_logfile ;
char *l_chr_ptr=NULL;

int CO_CreateReport(char *p_rept_id,
					char *p_rep_type,
					char *p_rep_name,
					char *p_param_str,
					char *p_start_date,
					char *p_user,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{

	char p_command[4000] = APL_NULL_STRING;
	char *ptr_filename = APL_NULL_STRING;
	char l_repname[100]=APL_NULL_STRING;
	char file_ext[6]=APL_NULL_STRING;
	char **temp1;
	int i=0;
	int j=0;
	int k=0;
	int m=0;
	char *ptr=APL_NULL_STRING;
	char l_param_str[2000]=APL_NULL_STRING;
	char l_chr_ghrt_path[1000]=APL_NULL_STRING;
	char l_chr_clnreport_path[1000]=APL_NULL_STRING;
	char l_chr_logdir[PATH_LENGTH]   = APL_NULL_STRING;
	char  chr_sys_date_time    [APL_DATE_LEN]=APL_NULL_STRING;
	char  chr_l_inifile[1000] = APL_NULL_STRING;
	FILE  *l_ptr_ini_file = NULL;
	FILE  *p_fp_intl=NULL;
	char l_exename[15]= "GHRT " ;

	int numb1=0;
	INTL_REPT_STRUCT_H *l_intl_rept_struct_rp = NULL;


	ptr_filename = (char *) calloc(200,sizeof(char));	

	l_intl_rept_struct_rp = (INTL_REPT_STRUCT_H *)calloc(1, sizeof(INTL_REPT_STRUCT_H));
	APL_MALLOC_FAIL(l_intl_rept_struct_rp) ;
	
	strcpy(l_param_str,p_param_str);
	
		
	printf("\n********* Param String=|%s|********** ",l_param_str);
	printf("\n********* Param String=|%d|********** ",(int)strlen(l_param_str)); //AIX- Warnings Removal

	strcpy(chr_l_inifile,getenv("INTL_ROOT_PATH"));
	strcat(chr_l_inifile,"intl_sun.cfg");

	if ((l_ptr_ini_file = fopen(chr_l_inifile,"r")) == NULL)
		APL_GOBACK_FAIL

	if (CO_ReadToken(l_ptr_ini_file,"INTL_LOG_PATH",l_chr_logdir,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_ReadToken(l_ptr_ini_file,"GHRT_PATH",l_chr_ghrt_path,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_ReadToken(l_ptr_ini_file,"CREATE_REP_PATH",l_chr_clnreport_path,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL



	
	switch(atoi(p_rep_type))
	{	
		case 0:	strcpy(file_ext,".htm");
			break;
		case 1:   strcpy(file_ext,".txt");
			break;
		case 21:   strcpy(file_ext,".xls");
			break;
		case 22:   strcpy(file_ext,".csv");
			break;
		case 23:   strcpy(file_ext,".pdf");
			break;
	}


/*	Splitting param string	*/
	
		if(APL_FAILURE == CO_SplitStr(l_param_str,'',&numb1,&temp1))
		{
					CO_ProcMonitor(g_logfile, "Failure from CO_SplitStr", NULL, NULL);
			APL_GOBACK_FAIL
		}
		
		/* Here call GHRT Only Once	*/

			l_chr_ptr=strstr(temp1[0],"/");
			if(l_chr_ptr==NULL)	
				sprintf(l_repname,"%s-%s%s",p_rep_name,temp1[0],file_ext);
			else
				sprintf(l_repname,"%s-%s",p_rep_name,file_ext);
			strcpy(p_command,l_chr_ghrt_path);
			strcat(p_command,l_exename);
			strcat(p_command,p_rept_id);	
			strcat(p_command," 0 ");
			strcat(p_command,l_chr_clnreport_path );
			strcat(p_command,l_repname);
			strcat(p_command," rhDataSource ");
			strcat(p_command,getenv("ORACLE_SID"));
			strcat(p_command," sms123 ");
			strcat(p_command,p_rep_type);
			strcat(p_command," '"); 
			strcat(p_command,temp1[0]);
			strcat(p_command,"' "); 

	/*		Loop to add reamining parameters to argument list		*/

			for(j=1;j<numb1;j++)
			{
				if(strcmp(temp1[j],APL_NULL_STRING)==0)
				{
					strcat(p_command,"'@RHNULL' ");
				}
				else
				{
					strcat(p_command,"'");
					strcat(p_command,temp1[j]);
					strcat(p_command,"' "); 
				}
			}

			printf("\n Report p_command=\n %s\n",p_command);
/*			execl("/bin/sh","sh","-c",p_command);*/
		
			fflush(stdout);
			if(system(p_command)!=0)		
			{
				CO_ProcMonitor(g_logfile, "Failure from GHRT ", NULL, NULL);
				APL_GOBACK_FAIL
			} 
			fflush(stdout);

			strcpy(l_intl_rept_struct_rp->report_name, l_repname);
			strncpy(l_intl_rept_struct_rp->report_desc, APL_CLNREP_DESC, APL_REPDESC_LENGTH - 1);
			l_intl_rept_struct_rp->report_desc[APL_REPDESC_LENGTH - 1] = '\0';
			strcpy(l_intl_rept_struct_rp->report_date,p_start_date);
			l_intl_rept_struct_rp->report_width = 100;
			strcpy(l_intl_rept_struct_rp->task_desc,l_repname);
			strcpy(l_intl_rept_struct_rp->fe_be_ind, APL_BE_IND);
			strcpy(l_intl_rept_struct_rp->usr,p_user);
			CO_ProcMonitor(g_logfile, "Calling CO_Proc_RptInsNew", NULL, NULL);

			if (APL_FAILURE == CO_Proc_RptInsNew( l_intl_rept_struct_rp,"INTL_CLNREP_PATH", l_debug_info_ptr))
			{
				CO_ProcMonitor(g_logfile, "Failure from CO_Proc_RptInsNew", NULL, NULL);
				APL_GOBACK_FAIL
			}

		

	APL_GOBACK_SUCCESS

		RETURN_SUCCESS :
		{
			printf("\n CO_CreateReport Success");

			return(APL_SUCCESS);
		}


	RETURN_FAILURE :
		{
			printf("\n CO_CreateReport Failure");
			return(APL_FAILURE);
		}

}

