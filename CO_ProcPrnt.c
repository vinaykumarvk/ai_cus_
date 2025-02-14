


   
   
   
   
   
   
   
   
   
   
   
   

	

	#define	PURE_C_SOURCE
	#include "CR_Common.h"
	
	int CO_Prnt(	char 						*nameof_file_a,
						char						*printername,
						INTL_ENV_DATA_STRUCT_H 	*p_intl_env_datastruct_h,
						DEBUG_INFO_STRUCT_H 			**l_debug_info_ptr) 
	{
		FILE *fptr=NULL;
		char chr_inifile_a[PATH_LENGTH];
		char chr_printer[PATH_LENGTH+1];
		char chr_compr[4*PATH_LENGTH]="lp -d";
		
		if (strlen(printername))
		{	
			strcpy(chr_printer, printername);
		}
		else
		{
			if(!(fptr=fopen(strcat(strcpy(chr_inifile_a,getenv("INTL_ROOT_PATH")),
																		"intl_sun.cfg"),"r")))
				APL_GOBACK_FAIL
			if(CO_ReadToken(fptr,"INTL_PRINTER",chr_printer,l_debug_info_ptr)==APL_FAILURE)
				APL_GOBACK_FAIL
		}
		printf("File Name is : %s\n", nameof_file_a);
		if(system(strcat(strcat(chr_compr,strcat(chr_printer," -oc -onb ")),nameof_file_a)))
			APL_GOBACK_FAIL
	

               APL_GOBACK_SUCCESS //AIX -Warning Removal
  
		RETURN_SUCCESS :
		{
			#ifdef SYS_DEBUG
			fprintf(APL_OUT_FILE,"Exiting From CO_Prnt successfully\n");
			#endif
			fclose(fptr);
			return(APL_SUCCESS);
		}

		RETURN_FAILURE :
		{
			fclose(fptr);
			#ifdef SYS_DEBUG
			fprintf(APL_OUT_FILE,"Exiting From CM_prnt with errors\n");
			#endif
			return(APL_FAILURE);
		}
	}
