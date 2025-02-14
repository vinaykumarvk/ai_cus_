


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CO_HostStructdef.h>

#define FILEPATH_LEN			70
#define FILENAME_LEN_A			80

main(int argc,char **argv)
{
	DEBUG_INFO_STRUCT_H			*l_debug_list = NULL;
	FILE						*l_ptr_ini_file = NULL;
	FILE						*l_ptr_log_file = NULL;
	char						chr_l_logdir[FILEPATH_LEN]   		  = APL_NULL_STRING;
	char						chr_l_logname[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_l_inifile[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_uname[APL_USERID_LEN]  		  = APL_NULL_STRING;
	char						chr_passwd[APL_USERID_LEN]       = APL_NULL_STRING;
	int						int_l_flg = 0;
	int						int_retval = 0;

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
	strcat(chr_l_logname, "DEL_EXP_BOND.log");

	l_ptr_log_file = fopen(chr_l_logname, "w");

	if (l_ptr_log_file == NULL)
		exit(-1);	

	

	if (CO_DB_Connection_D(chr_uname,chr_passwd,l_ptr_log_file,&l_debug_list) != APL_SUCCESS)
		exit(-1);	

	
	
	if (CO_RtvSysParams(&l_debug_list) != APL_SUCCESS)
		exit(-1);	

	

	int_retval = CR_Mod_ExpBondDel(argv,l_ptr_log_file,&l_debug_list);

	
	fclose (l_ptr_ini_file);

	if (int_retval != APL_SUCCESS)
	{
		int_l_flg = 1;

		int_retval = CO_Proc_Exit(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,NULL);

			CO_FreeErrLst(&l_debug_list);
		}
		
		CO_ProcMonitor(l_ptr_log_file,"FAILURE from Deletion of Expired Bonds program\n",NULL,NULL);
		
		
		fclose (l_ptr_log_file);

		exit(-1);	
	}
	else
	{
		int_l_flg = 0;

		int_retval = CO_Proc_Exit(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,NULL);

			CO_FreeErrLst(&l_debug_list);
		}
		
		CO_ProcMonitor(l_ptr_log_file,"SUCCESS from Deletion of Expired Bonds program\n",NULL,NULL);

		
		fclose (l_ptr_log_file);

		if (int_retval != APL_SUCCESS)
			exit(-1);
		else
			exit(0);
	}
}




int CR_Mod_ExpBondDel(char **argv,FILE *p_ptr_log_file,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion CR_Mod_ExpBondDel \n",NULL,NULL);
	

	int_retval = CO_Proc_BtchLock(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = EOM_Mod_ExpBondDel(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Mod_ExpBondDel successfully \n",NULL,NULL);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion CR_Mod_ExpBondDel with failure \n",NULL,NULL);
		return(APL_FAILURE);
	}
}
