







#define PURE_C_SOURCE
#include "CO_HostStructdef.h"



int CO_Proc_RePrint(	char *p_rep_name, 
						char *p_prn_name, 
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

	

	char 	chr_l_buf[BUFFER_LEN] 				= APL_NULL_STRING;
	char	chr_l_inifile[PATH_LENGTH]		= APL_NULL_STRING;
	char	chr_l_rep_path[PATH_LENGTH]		= APL_NULL_STRING;
	char	chr_l_rep_name[PATH_LENGTH]		= APL_NULL_STRING;

	FILE 		*l_finifile		= NULL;
	FILE 		*l_fptr			= NULL;

	

	APL_IF_DEBUG
	{
		CO_ProcMonitor(	APL_OUT_FILE, 
						"Entered Function CO_Proc_RePrint\n",
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Report Name is : %s\n", 
						p_rep_name);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
		memset( chr_l_buf, NULL, BUFFER_LEN );
		sprintf(		chr_l_buf, 
						"The Printer name is : %s\n", 
						p_prn_name);
		CO_ProcMonitor(	APL_OUT_FILE, 
						chr_l_buf,	
						NULL,
						NULL);
	}

	
	

	if (!strlen(p_rep_name))
	{
		APL_DATA_MISSING("Report Name", APL_NULL_STRING, APL_NULL_STRING);
		APL_GOBACK_FAIL
	} 

	

	

   strcpy(chr_l_inifile,getenv("INTL_ROOT_PATH"));
   strcat(chr_l_inifile,"intl_sun.cfg");

   if ( ( l_finifile=fopen(chr_l_inifile,"r") ) == NULL)
   {
      APL_GOBACK_FAIL
   }

   if ( APL_FAILURE == CO_ReadToken(   l_finifile,
                                       "INTL_REP_PATH",
                                       chr_l_rep_path,
                                       l_debug_info_ptr ))
   {
      APL_GOBACK_FAIL
   }

	sprintf(chr_l_rep_name, "%s%s", chr_l_rep_path, p_rep_name);

	

	if (!(l_fptr = fopen(chr_l_rep_name, "r")))
	{
		CO_InsertErr(	l_debug_info_ptr,
								ERR_FILE_NOTFND,
								"Report File",
								APL_NULL_STRING,
								APL_NULL_STRING,
								__LINE__,
								__FILE__ );
		APL_GOBACK_FAIL
	}

	

	fclose(l_fptr);

	

	if (APL_FAILURE == CO_Prnt(	chr_l_rep_name,
											p_prn_name,
											p_intl_envdatastruct_h,
											l_debug_info_ptr ))
	{
		APL_GOBACK_FAIL
	}

	
	
	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CO_Proc_RePrint with success\n",
							NULL,
							NULL);
		}
      return(APL_SUCCESS);

   RETURN_FAILURE :
		APL_IF_DEBUG
		{
			CO_ProcMonitor(	APL_OUT_FILE, 
							"Leaving Function CO_Proc_RePrint with errors\n",
							NULL,
							NULL);
		}
      return(APL_FAILURE);

}

