/*
 *   COPYRIGHT NOTICE
 *
 *   Copyright 2009 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to Polaris Software Lab Ltd
 *   and no part of these materials should be reproduced, published,  transmitted
 *   or distributed in any form or by  any means, electronic, mechanical, photoco
 *   pying, recording or otherwise, or stored in any information storage or retri
 *   eval system of  any nature  nor should the  materials be disclosed to  third
 *   parties or used in any other manner for which this is not authorized,without
 *   the prior express written authorization of Polaris Software Lab Limited.
 *
 */
/********************************************************************************
 *
 * Module Name         : Common Objects
 *
 * File Name           : Intl_Customize.c
 *
 * Description         : This program is used to get the db login details from th
 *                       e file (config file) for the passed parameter.
 *
 *
 *            Version Control Block
 *
 * Date        Version   Author          Description           RFS NO
 * ----------- --------  --------------  --------------------  ------------------
 * 15/06/2009  1.1       Naren V         Program is modified
 *                                       to get the DB login
 *                                       details in preceden
 *                                       ce order first from
 *                                       configuration  file
 *                                       and if unavailable,
 *                                       then a decrypted va
 *                                       lue from an encrypt
 *                                       ed file by  calling
 *                                       the remote applicat
 *                                       ion.
 *********************************************************************************/
 
#define PURE_C_SOURCE
#include "Intellect_Interface.h"
#include "Intellect_Common.h"
char chr_ora_id[APL_USERID_LEN],chr_ora_pwd[100];
char chr_globaldbpwd[100];
char chr_applname[PATH_LENGTH];

int CO_Rtv_LoginHandle() {

  //commented for AIX migration to remove the warning **/
	//int int_csf_ret_cod,int_ret_cod=APL_SUCCESS;

	int int_ret_cod=APL_SUCCESS;
		return int_ret_cod;
		} 

int CO_Rls_Context(){
return 1;
		}
int CO_Chk_Acl(char *username,char *functionname,int *access) {
	*access=APL_SUCCESS;
	return APL_SUCCESS;
}

/* int	CO_GetDbCMCon(char *princiName,char *chr_db_id,char *chr_db_pwd) { ** Commented for Web Intellect Encryption - Decryption Changes ** Naren V */

int	CO_GetDbCMCon(char *chr_db_ind, char *chr_db_id, char *chr_db_pwd) 
{

	FILE *chr_finifile;
	DEBUG_INFO_STRUCT_H *l_debuglist;
	DEBUG_INFO_STRUCT_H **l_debug_info_ptr;
	char nameof_file_a[PATH_LENGTH];
	char *chr_filer;
	chr_filer=getenv("INTL_ROOT_PATH");
	sprintf(nameof_file_a,"%s/intl_sun.cfg",chr_filer);
	chr_finifile=fopen(nameof_file_a,"r");
	l_debug_info_ptr=&l_debuglist;
	if(!chr_finifile)
		return APL_FAILURE;
	if(CO_ReadToken(chr_finifile,"INTL_NAME",chr_applname,l_debug_info_ptr)==APL_FAILURE){
		fclose(chr_finifile);
		return APL_FAILURE;
		}
	printf("Name of the appl is %s\n",chr_applname);

		printf("file|%s|\n",nameof_file_a);
	
	/* if(CO_ReadToken(chr_finifile,"INTL_DB_USR",chr_ora_id,l_debug_info_ptr)==APL_FAILURE){
		printf("usr|%s|\n",chr_ora_id);
		fclose(chr_finifile);
		return APL_FAILURE;
		}
	strcpy(chr_db_id,chr_ora_id);
	fclose(chr_finifile);
	strcpy(chr_db_id,chr_ora_id);
	printf("Oracle ID is %s\n",chr_ora_id);
	chr_finifile=fopen(nameof_file_a,"r");
	if(CO_ReadToken(chr_finifile,"INTL_DB_PWD",chr_ora_pwd,l_debug_info_ptr)==APL_FAILURE){
		printf("passwd|%s|\n",chr_ora_pwd);
		fclose(chr_finifile);
		return APL_FAILURE;
		}
	strcpy(chr_db_pwd,chr_ora_pwd);
	fclose(chr_finifile);
	strcpy(chr_db_pwd,chr_ora_pwd); ** Commented for Web Intellect Encryption - Decryption Changes ** Naren V */

	/** Web Intellect Encryption - Decryption Changes - Start - Naren V **/
	printf("\n chr_db_ind |%s|",chr_db_ind);

	if ( !strcasecmp(chr_db_ind, "W") )
	{

	   /* Get The User Id Value for WEB Custody DB */
	   if(CO_PrecedReadToken(chr_finifile,"WEB_INTL_DB_USR",chr_ora_id,l_debug_info_ptr)==APL_FAILURE)
      	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB User Id for Web Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
	   strcpy(chr_db_id,chr_ora_id);
	   fclose(chr_finifile);

	   /* Get The Password Value for WEB Custody DB */
	   chr_finifile=fopen(nameof_file_a,"r");
	   if(CO_PrecedReadToken(chr_finifile,"WEB_INTL_DB_PWD",chr_ora_pwd,l_debug_info_ptr)==APL_FAILURE)
	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB Password for Web Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
	   strcpy(chr_db_pwd,chr_ora_pwd);
	   fclose(chr_finifile);

	} /* End Of getting WEB Custody Login details */

	else 
	{

	   /* Get The User Id Value for Intellect Custody DB (Added for WEB Custody related sources) */
	   if(CO_PrecedReadToken(chr_finifile,"INTL_DB_USR",chr_ora_id,l_debug_info_ptr)==APL_FAILURE)
	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB User Id for Int Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
	   strcpy(chr_db_id,chr_ora_id);
	   fclose(chr_finifile);

	   /* Get The Password Value for Intellect Custody DB (other than WEB Custody) */
	   chr_finifile=fopen(nameof_file_a,"r");
	   if(CO_PrecedReadToken(chr_finifile,"INTL_DB_PWD",chr_ora_pwd,l_debug_info_ptr)==APL_FAILURE)
	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB Password for Int Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
		strcpy(chr_db_pwd,chr_ora_pwd);
	    fclose(chr_finifile);

	} /* End Of getting Intellect Custody Login details */
	printf("\n chr_db_id |%s|",chr_db_id);

	if(!strcmp(chr_db_id,APL_NULL_STRING))	//fix - SIT issue - 6th May 2011
	{

	   /* Get The User Id Value for Intellect Custody DB (Retained for back office related sources) */
	   if(CO_ReadToken(chr_finifile,"INTL_DB_USR",chr_ora_id,l_debug_info_ptr)==APL_FAILURE)
	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB User Id for Int Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
	   strcpy(chr_db_id,chr_ora_id);
	   fclose(chr_finifile);

	   /* Get The Password Value for Intellect Custody DB */
	   chr_finifile=fopen(nameof_file_a,"r");
	   if(CO_ReadToken(chr_finifile,"INTL_DB_PWD",chr_ora_pwd,l_debug_info_ptr)==APL_FAILURE)
	   {
		printf("\n Error in fn CO_GetDbCMCon while getting the DB Password for Int Custody");
		fclose(chr_finifile);
		return APL_FAILURE;
	   }
	   strcpy(chr_db_pwd,chr_ora_pwd);
	   fclose(chr_finifile);

	} /* End of getting back office Intellect Custody Login details */
	/** Web Intellect Encryption - Decryption Changes - End   - Naren V **/

	return APL_SUCCESS;
} /* End Of fn CO_GetDbCMCon() */
/* Retrofit done by swamy for Back End Encryption & Decryption of DB User Name & Password Ends here */
