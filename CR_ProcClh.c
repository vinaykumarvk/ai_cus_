


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CO_HostStructdef.h>

#define FILEPATH_LEN				70
#define FILENAME_LEN_A				80



#define DL_CB_CLH_CNTRY(nation_cd) \
\
	int_retval = CBClh##nation_cd##Fn(\
					argv,\
					l_ptr_log_file,\
					&l_intl_envdatastruct_h,\
					&l_debug_list);\



main(int argc,char **argv)
{
	DEBUG_INFO_STRUCT_H			*l_debug_list = NULL;
	FILE						*l_ptr_ini_file = NULL;
	FILE						*l_ptr_log_file = NULL;
	INTL_ENV_DATA_STRUCT_H	l_intl_envdatastruct_h;
	char						chr_l_inifile[FILENAME_LEN_A] 	= APL_NULL_STRING;
	char						chr_l_logdir[FILEPATH_LEN]		= APL_NULL_STRING;
	char						chr_l_logname[FILENAME_LEN_A]   = APL_NULL_STRING;
	char						chr_uname[APL_USERID_LEN]	= APL_NULL_STRING;
	char						chr_passwd[APL_USERID_LEN]	= APL_NULL_STRING;
	int						int_l_flg = 0;
	int						int_retval = 0;
	char						**temp = NULL;
	int						int_num = 0;
	char						chr_l_cntry_code[3];

	memset(&l_intl_envdatastruct_h,NULL,sizeof(INTL_ENV_DATA_STRUCT_H));
	memset(chr_l_logdir,NULL,sizeof(chr_l_logdir));	
	memset(chr_l_logname,NULL,sizeof(chr_l_logname));	
	memset(chr_l_inifile,NULL,sizeof(chr_l_inifile));	

	strcpy(chr_l_inifile,getenv("INTL_ROOT_PATH"));
	strcat(chr_l_inifile,"intl_sun.cfg");

	if ((l_ptr_ini_file = fopen(chr_l_inifile,"r")) == NULL)
		exit(-1);

	if (CO_ReadToken(l_ptr_ini_file,"DB_ID",chr_uname,&l_debug_list) != APL_SUCCESS)
		exit(-1);

	if (CO_ReadToken(l_ptr_ini_file,"DB_PWD",chr_passwd,&l_debug_list) != APL_SUCCESS)
		exit(-1);
	
	if (CO_ReadToken(l_ptr_ini_file,"INTL_LOG_PATH",chr_l_logdir,&l_debug_list) != APL_SUCCESS)
		exit(-1);

	

	strcpy(chr_l_logname, chr_l_logdir);
	strcat(chr_l_logname, "CLR_HOUSE.log");

	l_ptr_log_file = fopen(chr_l_logname, "w");

	if (l_ptr_log_file == NULL)
		exit(-1);

	
	if (CO_DB_Connection_O(chr_uname,chr_passwd,l_ptr_log_file,&l_debug_list) != APL_SUCCESS)
		exit(-1);

	

	if (CO_RtvSysParams(&l_debug_list) != APL_SUCCESS)
		exit(-1);

	

	if (CO_SplitStr(argv[9],'|',&int_num,&temp) != APL_SUCCESS)
		exit(-1);

	strcpy(chr_l_cntry_code,temp[0]);

	

	strcpy(l_intl_envdatastruct_h.usr, argv[3]);
	strcpy(l_intl_envdatastruct_h.h_mode, argv[4]);
	strcpy(l_intl_envdatastruct_h.processtion, argv[5]);
	strcpy(l_intl_envdatastruct_h.auth_req, argv[6]);
	strcpy(l_intl_envdatastruct_h.subprocess, argv[7]);
	strcpy(l_intl_envdatastruct_h.h_process, argv[8]);

	

	if (strcmp(chr_l_cntry_code, "PO") == 0)
		DL_CB_CLH_CNTRY( Po )
	else if (strcmp(chr_l_cntry_code, "CZ") == 0)
		DL_CB_CLH_CNTRY( Cz )
	else if (strcmp(chr_l_cntry_code, "HU") == 0)
		DL_CB_CLH_CNTRY( Hu )
	else if (strcmp(chr_l_cntry_code, "TR") == 0)
		DL_CB_CLH_CNTRY( Tr )

	
	fclose (l_ptr_ini_file);

	if (int_retval != APL_SUCCESS)
	{
		int_l_flg = 1;

		int_retval = DoFinalProcessingFn1(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			
			
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,&l_intl_envdatastruct_h);
			CO_FreeErrLst(&l_debug_list);
		}
			
		CO_ProcMonitor(l_ptr_log_file,"FAILURE from Clearing House hand-off h_file generation program \n",NULL,&l_intl_envdatastruct_h);

		
		fclose (l_ptr_log_file);
		
		exit(-1);
	}
	else
	{
		int_l_flg = 0;

		int_retval = DoFinalProcessingFn1(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		CO_ProcMonitor(l_ptr_log_file,"SUCCESS from Clearing House hand-off h_file generation program",NULL,&l_intl_envdatastruct_h);

		
		fclose (l_ptr_log_file);

		if (int_retval != APL_SUCCESS)
			exit(-1);
		else
			exit(0);
	}
}



int CBClhPoFn(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CBClhPoFn \n",NULL,p_intl_env_data_struct_h_d);
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	

	int_retval = LockRecFn1(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = DL_Proc_ClrHs_po(p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhPoFn successfully\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhPoFn with failure\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_FAILURE);
	}
}



int CR_Prnt_CLHHf(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char							chr_l_sys_date[APL_DATE_LEN];
	int							int_l_diff;
	char							chr_l_conf_dt[APL_DATE_LEN] = APL_NULL_STRING;
	int							int_num = 0;
	char							**temp = NULL;

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CR_Prnt_CLHHf \n",NULL,p_intl_env_data_struct_h_d);
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	

	if (CO_SplitStr(argv[9],'|',&int_num,&temp) != APL_SUCCESS)
		exit(-1);

	strcpy(chr_l_conf_dt,temp[1]);
	
	if (strlen(chr_l_conf_dt) == 0)
		APL_DATA_MISSING("CONF DT",APL_NULL_STRING,APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_Pro_DateComp(chr_l_sys_date,chr_l_conf_dt,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_diff > 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_DATE_CANT_GRT_TODAY,"CONF DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}

	

	int_retval = LockRecFn1(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = DL_Proc_ClrHs_cz(chr_l_conf_dt,p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Prnt_CLHHf successfully\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Prnt_CLHHf with failure\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_FAILURE);
	}
}



int CBClhHuFn(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char							chr_l_conf_dt[APL_DATE_LEN] = APL_NULL_STRING;
	int							int_num = 0;
	char							**temp = NULL;

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CBClhHuFn \n",NULL,p_intl_env_data_struct_h_d);
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
	
	

	if (CO_SplitStr(argv[9],'|',&int_num,&temp) != APL_SUCCESS)
		exit(-1);

	strcpy(chr_l_conf_dt,temp[1]);

	if (strlen(chr_l_conf_dt) == 0)
		APL_DATA_MISSING("CONF DT",APL_NULL_STRING,APL_NULL_STRING)

	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	

	int_retval = LockRecFn1(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = DL_Proc_ClrHs_hu(chr_l_conf_dt,p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhHuFn successfully\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhHuFn with failure\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_FAILURE);
	}
}



int CBClhTrFn(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char							chr_l_conf_dt[APL_DATE_LEN] = APL_NULL_STRING;
	int							int_num = 0;
	char							**temp = NULL;
	char							chr_l_gen_handoff_file_flg[2];
	char							chr_l_incl_amt_flg[2];
	int							int_l_diff;
	char							chr_l_sys_date[APL_DATE_LEN];

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CBClhTrFn \n",NULL,p_intl_env_data_struct_h_d);
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
	
	

	if (CO_SplitStr(argv[9],'|',&int_num,&temp) != APL_SUCCESS)
		exit(-1);

	strcpy(chr_l_conf_dt,temp[1]);
	strcpy(chr_l_gen_handoff_file_flg,temp[2]);
	strcpy(chr_l_incl_amt_flg,temp[3]);

	if (strlen(chr_l_conf_dt) == 0)
		APL_DATA_MISSING("CONF DT",APL_NULL_STRING,APL_NULL_STRING)
	
	if (strlen(chr_l_gen_handoff_file_flg) == 0)
		APL_DATA_MISSING("GEN HANDOFF FILE FLG",APL_NULL_STRING,APL_NULL_STRING)
	if (strlen(chr_l_incl_amt_flg) == 0)
		APL_DATA_MISSING("INCLUDE AMOUNT FLG",APL_NULL_STRING,APL_NULL_STRING)
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_RtvSysDt(chr_l_sys_date,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (CO_Pro_DateComp(chr_l_sys_date,chr_l_conf_dt,&int_l_diff,l_debug_info_ptr) != APL_SUCCESS)
		APL_GOBACK_FAIL

	if (int_l_diff > 0)
	{
		CO_InsertErr(l_debug_info_ptr,ERR_DATE_CANT_GRT_TODAY,"CONF DT",APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
		APL_GOBACK_FAIL
	}

	

	int_retval = LockRecFn1(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = DL_Clh_DlFn(chr_l_conf_dt,chr_l_gen_handoff_file_flg,chr_l_incl_amt_flg,p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhTrFn successfully\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CBClhTrFn with failure\n",NULL,p_intl_env_data_struct_h_d);

		return(APL_FAILURE);
	}
}
