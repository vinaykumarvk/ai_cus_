


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CO_HostStructdef.h>

#define FILEPATH_LEN			70
#define FILENAME_LEN_A			80

main(int argc,char **argv)
{
	DEBUG_INFO_STRUCT_H			*l_debug_list = NULL;
	FILE						*l_ptr_ini_file = NULL;
	FILE						*l_ptr_log_file = NULL;
	char						**temp = NULL;
	INTL_ENV_DATA_STRUCT_H	l_intl_envdatastruct_h;
	char						chr_l_logdir[FILEPATH_LEN]   		  = APL_NULL_STRING;
	char						chr_l_logname[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_l_inifile[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_uname[APL_USERID_LEN]  		  = APL_NULL_STRING;
	char						chr_passwd[APL_USERID_LEN]       = APL_NULL_STRING;
	char						frm_instr_code[APL_INSTRUMENTCODE_LEN]     = APL_NULL_STRING;
	char						chr_auth_reset_flg[APL_FLAG_LENGTH] = APL_NULL_STRING;
	int						int_num = 0;
	int						int_l_flg = 0;
	int						int_retval = 0;

	memset(&l_intl_envdatastruct_h,NULL,sizeof(INTL_ENV_DATA_STRUCT_H));
	memset(frm_instr_code,NULL,sizeof(frm_instr_code));
	memset(chr_auth_reset_flg,NULL,sizeof(chr_auth_reset_flg));
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

	if (CO_ReadToken(l_ptr_ini_file,"INTL_LOG_PATH",chr_l_logdir,&l_debug_list)!= APL_SUCCESS)
		exit(-1);

	

	strcpy(chr_l_logname, chr_l_logdir);
	strcat(chr_l_logname, "INSTRCONV_AUTH.log");

	l_ptr_log_file = fopen(chr_l_logname, "w");

	if (l_ptr_log_file == NULL)
		exit(-1);	

	

	if (CA_DatabaseConnect(chr_uname,chr_passwd,l_ptr_log_file,&l_debug_list) != APL_SUCCESS)
		exit(-1);	

	
	
	if (CO_RtvSysParams(&l_debug_list) != APL_SUCCESS)
		exit(-1);	

	
	
	if (CO_SplitStr(argv[9],'|',&int_num,&temp) != APL_SUCCESS)
		exit(-1);	
	
	strcpy(frm_instr_code,temp[0]);
	strcpy(chr_auth_reset_flg,temp[1]);

	

	strcpy(l_intl_envdatastruct_h.usr, argv[3]);
	strcpy(l_intl_envdatastruct_h.h_mode, argv[4]);
	strcpy(l_intl_envdatastruct_h.processtion, argv[5]);
	strcpy(l_intl_envdatastruct_h.auth_req, argv[6]);
	strcpy(l_intl_envdatastruct_h.subprocess, argv[7]);
	strcpy(l_intl_envdatastruct_h.h_process, argv[8]);

	

	int_retval = CR_Proc_InstrConvAuth(frm_instr_code,chr_auth_reset_flg,argv,l_ptr_log_file,&l_intl_envdatastruct_h,&l_debug_list);

	
	fclose (l_ptr_ini_file);

	if (int_retval != APL_SUCCESS)
	{
		int_l_flg = 1;

		int_retval = CA_Proc_Final(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,&l_intl_envdatastruct_h);
			CO_FreeErrLst(&l_debug_list);
	
		}
			
		CO_ProcMonitor(l_ptr_log_file,"FAILURE from Instrurity Conversion Authorisation program \n",NULL,&l_intl_envdatastruct_h);
		
		
		fclose (l_ptr_log_file);

		exit(-1);	
	}
	else
	{
		int_l_flg = 0;

		int_retval = CA_Proc_Final(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,&l_intl_envdatastruct_h);
			CO_FreeErrLst(&l_debug_list);
	
		}

		CO_ProcMonitor(l_ptr_log_file,"SUCCESS from Instrurity Conversion Authorisation program \n",NULL,&l_intl_envdatastruct_h);

		
		fclose (l_ptr_log_file);

		if (int_retval != APL_SUCCESS)
			exit(-1);
		else
			exit(0);
	}
}




int CR_Proc_InstrConvAuth(char *p_from_instrode,char *p_auth_reset_flg,char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char							chr_iexist,chr_iauthorised,chr_iconverted;

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CR_Proc_InstrConvAuth \n",NULL,p_intl_env_data_struct_h_d);

	if (strlen(p_from_instrode) == 0)
		APL_DATA_MISSING("FROM INSTRUMENT CODE",APL_NULL_STRING,APL_NULL_STRING)
	if (strlen(p_auth_reset_flg) == 0)
		APL_DATA_MISSING("AUTHORIZE/RESET FLG",APL_NULL_STRING,APL_NULL_STRING)
	if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"From Instrurity is %s \n",p_from_instrode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
		
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Authorize/Reset chr_flag is %s \n",p_auth_reset_flg);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
	sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
	CO_ProcMonitor(p_ptr_log_file,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

	

	int_retval = CA_LockRec(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	chr_iexist = 'Y';
	chr_iauthorised = 'Y';
	chr_iconverted = 'Y';

	int_retval = CO_Chk_InstrValid(p_from_instrode,chr_iexist,chr_iauthorised,NULL,NULL,NULL,chr_iconverted,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = CR_Proc_DBInstrConvAuth(p_from_instrode,p_auth_reset_flg,argv,p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Proc_InstrConvAuth successfully \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Proc_InstrConvAuth with failure \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}
