


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include "CO_HostStructdef.h"

#define FILEPATH_LEN			70
#define FILENAME_LEN_A			80

int main(int argc,char **argv)   //AIX - Warnings Removal
{
	DEBUG_INFO_STRUCT_H			*l_debug_list = NULL;
	FILE						*l_ptr_ini_file = NULL;
	FILE						*l_ptr_log_file = NULL;
       /*** commented for AIX migration to remove warnings  -- Unused variable **/ 
	// char						**temp = NULL;
	INTL_ENV_DATA_STRUCT_H	l_intl_envdatastruct_h;
	char						chr_l_logdir[FILEPATH_LEN]   		  = APL_NULL_STRING;
	char						chr_l_logname[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_l_inifile[FILENAME_LEN_A]  		  = APL_NULL_STRING;
	char						chr_uname[APL_USERID_LEN]  		  = APL_NULL_STRING;
	char						chr_custody_id_b[APL_USERID_LEN]  	  = APL_NULL_STRING;
	char						chr_passwd[APL_PASSWD_LEN]       = APL_NULL_STRING;
        /*** commented for AIX migration to remove warnings  -- Unused variable **/ 
	// int						int_num = 0;
	int						int_l_flg = 0;
	int						int_retval = 0;

	memset(&l_intl_envdatastruct_h,NULL,sizeof(INTL_ENV_DATA_STRUCT_H));
	memset(chr_l_logdir,NULL,sizeof(chr_l_logdir));
	memset(chr_l_logname,NULL,sizeof(chr_l_logname));
	memset(chr_l_inifile,NULL,sizeof(chr_l_inifile));

	strcpy(chr_l_inifile,getenv("INTL_ROOT_PATH"));
	strcat(chr_l_inifile,"intl_sun.cfg");

	if ((l_ptr_ini_file = fopen(chr_l_inifile,"r")) == NULL)
		APL_GOBACK_FAIL

	

	

	APL_FETCH_DB_LOGIN_DETAILS(l_ptr_ini_file, chr_custody_id_b, chr_uname, chr_passwd, APL_OUT_FILE, &l_debug_list)

	

	if (CO_DB_Connection_A(chr_uname,chr_passwd,&l_debug_list) != APL_SUCCESS)
		APL_GOBACK_FAIL

	

	if (APL_FAILURE == CO_Rtv_RptFileName(	"3H",
													APL_LOGFILE_DESC,
													100,
													argv[5],
													argv,
													&l_ptr_log_file,
													&l_debug_list ) )
	{
		APL_GOBACK_FAIL
	}

	

	if (CO_Proc_Commit() != APL_SUCCESS)
	{
		CO_ProcMonitor(l_ptr_log_file, "Could Not commit after opening Log file", NULL, NULL);
		CO_Proc_RptClose(l_ptr_log_file, &l_debug_list);
		APL_GOBACK_FAIL
	}

	
	
	if (CO_RtvSysParams(&l_debug_list) != APL_SUCCESS)
	{
		CO_ProcMonitor(l_ptr_log_file, "Could Not Read System Parameters", NULL, NULL);
		CO_Proc_RptClose(l_ptr_log_file, &l_debug_list);
		APL_GOBACK_FAIL
	}

	

	strcpy(l_intl_envdatastruct_h.usr, argv[3]);
	strcpy(l_intl_envdatastruct_h.h_mode, argv[4]);
	strcpy(l_intl_envdatastruct_h.processtion, argv[5]);
	strcpy(l_intl_envdatastruct_h.auth_req, argv[6]);
	strcpy(l_intl_envdatastruct_h.subprocess, argv[7]);
	strcpy(l_intl_envdatastruct_h.h_process, argv[8]);

	

	int_retval = EOD_Mod_HisPosBkSetl(argv,l_ptr_log_file,&l_intl_envdatastruct_h,&l_debug_list);

	
	fclose (l_ptr_ini_file);

	if (int_retval != APL_SUCCESS)
	{
		int_l_flg = 1;

		int_retval = CO_Proc_Exit(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		fprintf(l_ptr_log_file," F int_retval=|%d|\n",int_retval);
		if (CO_ChkErr(l_debug_list) == APL_SUCCESS)
		{
			fprintf(l_ptr_log_file,"Inside CO_ChkErr\n");
			CO_ProcMonitor(l_ptr_log_file,APL_NULL_STRING,&l_debug_list,&l_intl_envdatastruct_h);
			CO_FreeErrLst(&l_debug_list);
			fprintf(l_ptr_log_file," 2 Inside CO_ChkErr\n");
	
		}
			
		CO_ProcMonitor(l_ptr_log_file,"FAILURE from updation of history positions for Back Dated Settlements program \n",NULL,&l_intl_envdatastruct_h);
		
		
		CO_Proc_RptClose(l_ptr_log_file, &l_debug_list);

		APL_GOBACK_FAIL
	}
	else
	{
		int_l_flg = 0;

		fprintf(l_ptr_log_file," S int_l_flg=|%d|\n",int_l_flg);
		int_retval = CO_Proc_Exit(argv,l_ptr_log_file,&l_debug_list,int_l_flg);
		fprintf(l_ptr_log_file," S int_retval=|%d|\n",int_retval);
		CO_ProcMonitor(l_ptr_log_file,"SUCCESS from updation of history positions for Back Dated Settlements program \n",NULL,&l_intl_envdatastruct_h);

		fprintf(l_ptr_log_file,"before  CO_Proc_RptClose\n");
		CO_Proc_RptClose(l_ptr_log_file, &l_debug_list);
		fprintf(l_ptr_log_file,"After  CO_Proc_RptClose\n");
		if (int_retval != APL_SUCCESS)
		{
			printf("\n Going for Fail \n");
			APL_GOBACK_FAIL
		}
		else
		{	
			printf("\n Going for Success \n");
			APL_GOBACK_SUCCESS
		}
	}

	RETURN_SUCCESS : {
						printf("\n Going for Success Final \n");
						exit(0);
					}
			
	RETURN_FAILURE : 
	{
			printf("\n Going for Fail Final \n");
			exit(-1); 
	}
			
}




int EOD_Mod_HisPosBkSetl(char **argv,FILE *p_ptr_log_file,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	int							int_retval = 0;
        /*** commented for AIX migration to remove warnings  -- Unused variable **/
/**	char							chr_l_buf[BUFFER_LEN] = APL_NULL_STRING;
	char							chr_iexist,chr_iauthorised,chr_iconverted;***/

	CO_ProcMonitor(p_ptr_log_file,"Entered processtion EOD_Mod_HisPosBkSetl \n",NULL,p_intl_env_data_struct_h_d);

	

	int_retval = CO_Proc_BtchLock(argv,p_ptr_log_file,l_debug_info_ptr);

	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	int_retval = DL_Proc_BkSetl(argv, p_ptr_log_file,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	if (int_retval != APL_SUCCESS)
		APL_GOBACK_FAIL

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion EOD_Mod_HisPosBkSetl \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_SUCCESS);
	}

	RETURN_FAILURE  :
	{
		CO_ProcMonitor(p_ptr_log_file,"Leaving processtion EOD_Mod_HisPosBkSetl \n",NULL,p_intl_env_data_struct_h_d);
		return(APL_FAILURE);
	}
}
