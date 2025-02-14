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
 * File Name           : CO_ReadToken.c
 *
 * Description         : This program is used to read the  assigned  value from a 
 *                       file (config file) for the passed parameter.
 *
 *
 *            Version Control Block
 *
 * Date        Version   Author          Description           RFS NO
 * ----------- --------  --------------  --------------------  ------------------
 * 21/12/2011  1.1       Naren V         Program is modified
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
 
#include "stdio_64.h"
#include <ctype.h>
#include <string.h>
#define	PURE_C_SOURCE
#include "Intellect_Interface.h"
#include	"Intellect_Common.h"
#include "Intellect_Error.h"
/*
#define	S_LINE_SIZE			80
#define	S_FILE_SIZE			80	
*/

#define	S_LINE_SIZE			300
#define	S_FILE_SIZE			300	

#define  PURE_C_SOURCE
#define  PG_CALL_LEN   500
#define  BUFFER_LEN    150

int	CO_ReadToken(FILE*			p_fptr,
						char*				p_token,
						char*				chr_p_val,
						DEBUG_INFO_STRUCT_H  **l_debug_info_ptr)
{
		char*					chr_file_contents[S_FILE_SIZE];
	char								l_debug_info_struct_h_tmp[S_LINE_SIZE+1];
	int								i=0,j=0;
	char 								chr_tokeninfile[S_LINE_SIZE+1];
	int		k=0; /* Added for Web Intellect Encryption - Decryption Changes - Naren V */ 

	/* Alert("In CO_ReadToken p_token = |%s|",p_token);
	fflush(stdout); */
	
		rewind(p_fptr);

		memset(l_debug_info_struct_h_tmp, APL_NULL_CHAR, sizeof(l_debug_info_struct_h_tmp));
		memset(chr_tokeninfile, APL_NULL_CHAR, sizeof(chr_tokeninfile));

		while(i < S_FILE_SIZE)
		{

			fgets(l_debug_info_struct_h_tmp,S_LINE_SIZE+1,p_fptr);
			sscanf(l_debug_info_struct_h_tmp," %[^ =]",chr_tokeninfile);
			if(chr_tokeninfile[0]==';') continue;
			chr_file_contents[i] = calloc(strlen(l_debug_info_struct_h_tmp)+1,sizeof(char));
			APL_MALLOC_FAIL(chr_file_contents[i]);
			j = i;

			if (feof(p_fptr))
				break;
			if (ferror(p_fptr))
				APL_GOBACK_FAIL
			strcpy(chr_file_contents[i],l_debug_info_struct_h_tmp);
			fflush(stdout);
			i++;
                        k++;  /* Added for Web Intellect Encryption - Decryption Changes - Naren V */
		}

	

	/* for (i=0; i<S_FILE_SIZE; i++) */ /* Commented for Web Intellect Encryption - Decryption Changes - Naren V */
	for (i=0; i<k; i++) /* Added for Web Intellect Encryption - Decryption Changes - Naren V */
	{
		sscanf(chr_file_contents[i]," %[^ =]",chr_tokeninfile);
		if (!strncmp(p_token,chr_tokeninfile,strlen(p_token)))
		{
		  sscanf(chr_file_contents[i], "%*[^=]= %[^\n]", chr_p_val);
   	  for(;isspace(chr_p_val[strlen(chr_p_val)-1]);chr_p_val[strlen(chr_p_val)-1]='\0');
		  break;
		}
	}
	if(i==S_FILE_SIZE)
		strcpy(chr_p_val,APL_NULL_STRING);

	/*printf("\n In CO_ReadToken chr_p_val = |%s| \n ",chr_p_val);
	fflush(stdout); */
	
	APL_GOBACK_SUCCESS
	RETURN_SUCCESS	:
		for (i=0;i<=j;)
		{
			APL_FREE(chr_file_contents[i]);
			i++;
		}
		return (APL_SUCCESS);
	RETURN_FAILURE	:
		for (i=0;i<=j;)
		{
			APL_FREE(chr_file_contents[i]);
			i++;
		}
		return (APL_FAILURE);
}

/* Retrofit done by swamy for Back End Encryption & Decryption of DB User Name & Password Starts here */

/** Web Intellect Encryption - Decryption Changes - Start - Naren V **/
/*********************************************************************************************
 *                                                                                           *
 * Function Name         : CO_PrecedReadToken                                                *
 *                                                                                           *
 * Description           : This function will try to get the DB Login details for the passed *
 *                         parameters from the config file on precedence. If the values  are *
 *                         not available in the file,then the fn will try to call the remote *
 *                         application to get the decrypted login  values  for the passed db *
 *                         (Web Intellect/Custody Intellect) parameters (User Id/Password).  *
 *                                                                                           *
 *                                                                                           *
 * Parameter                         Type               Mode     Description                 *
 * ------------                     --------            -----    ---------------             *
 * p_fptr                            FILE *              NA      Config File Pointer         *
 * p_token                           char *              NA      Login Parameter Value       *
 * p_ret_val                         char *              NA      Return Value from file/appl *
 * l_debug_info_ptr                  STRUCTURE           NA      Debug Info Structure        *
 *                                                                                           *
 * Return Values        :                                                                    *
 * APL_SUCCESS  - SUCCESS                                                                    *
 * APL_FAILURE  - FAILURE                                                                    *
 *                                                                                           *
 *********************************************************************************************/

int CO_PrecedReadToken(FILE*                p_fptr            ,
                       char*                p_token           ,
                       char*                p_ret_val         ,
                       DEBUG_INFO_STRUCT_H  **l_debug_info_ptr)
{
  char    l_chr_buf       [S_LINE_SIZE   ]  =  APL_NULL_STRING;
  char    l_chr_ret_val   [APL_USERID_LEN]  =  APL_NULL_STRING;
  char    l_chr_token_val [APL_USERID_LEN]  =  APL_NULL_STRING;

  CO_ProcMonitor(APL_OUT_FILE, "\n Entered into fn CO_PrecedReadToken", NULL, NULL);
  sprintf(l_chr_buf, "\n Passed Token Parameter: [%s]", p_token);
  CO_ProcMonitor(APL_OUT_FILE, l_chr_buf, NULL, NULL);

  memset(l_chr_ret_val, '\0', sizeof(l_chr_ret_val));

  if (CO_ReadToken(p_fptr, p_token, l_chr_ret_val, l_debug_info_ptr) == APL_FAILURE)
  {
     CO_ProcMonitor(APL_OUT_FILE, "\n Error while getting DB User Id/Password from config file..", NULL, NULL);
     APL_GOBACK_FAIL 

  }                                                         /* End of getting values from file */

  if ( strlen(l_chr_ret_val) == 0 )
  {
     CO_ProcMonitor(APL_OUT_FILE, "\n Could not find DB User Id/Password in config file..", NULL, NULL);

     memset(l_chr_token_val, '\0', sizeof(l_chr_token_val));

     if ( !strcmp(p_token     , "WEB_INTL_DB_USR") )   /* Parameter for WEB Intellect User Id  */
     {
       strcpy(l_chr_token_val , "WEBUSER");
     } 
     else if ( !strcmp(p_token, "WEB_INTL_DB_PWD") )   /* Parameter for WEB Intellect Password */
     {
       strcpy(l_chr_token_val , "WEBPASSWORD");
     }
     else if ( !strcmp(p_token, "INTL_DB_USR") )       /* Parameter for CUST Intellect User Id */
     {
       strcpy(l_chr_token_val , "USER");
     }
     else if ( !strcmp(p_token, "INTL_DB_PWD") )       /* Parameter for CUST Intellect Password*/
     {
       strcpy(l_chr_token_val , "PASSWORD");
     }

     sprintf(l_chr_buf, "\n Calling remote appl for decrypted value of %s..", l_chr_token_val);
     CO_ProcMonitor(APL_OUT_FILE, l_chr_buf, NULL, NULL);

     memset(l_chr_ret_val, '\0', sizeof(l_chr_ret_val));

     if ( CO_GetDBLoginDtls(l_chr_token_val, l_chr_ret_val, l_debug_info_ptr) == APL_FAILURE )
     {
       sprintf(l_chr_buf, "\n Error while geting decrypted val for parameter %s", l_chr_token_val);
       CO_ProcMonitor(APL_OUT_FILE, l_chr_buf, NULL, NULL);
       APL_GOBACK_FAIL
     }                                                      /* End of getting decrypted values */

     if ( strlen(l_chr_ret_val) == 0 )
     {
        sprintf(l_chr_buf, "\n Unable to get the decrypted val for parameter %s..", l_chr_token_val);
        CO_ProcMonitor(APL_OUT_FILE, l_chr_buf, NULL, NULL);
        APL_GOBACK_FAIL
     }
  }                                                         /* End of file return value is null*/

  strcpy(p_ret_val, l_chr_ret_val);         /* Returning the arrived values to calling program */

  APL_GOBACK_SUCCESS

  RETURN_SUCCESS :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_PrecedReadToken successfully", NULL, NULL);
   return (APL_SUCCESS);

  RETURN_FAILURE :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_PrecedReadToken with errors", NULL, NULL);
   return (APL_FAILURE);

} /* End Of fn CO_PrecedReadToken() */

/** Web Intellect Encryption - Decryption Changes - End  - Naren V **/

/*****                             Function Definitions                                 *****/

/*********************************************************************************************
 *                                                                                           *
 * Function Name         : CO_GetDBLoginDtls                                                 *
 *                                                                                           *
 * Description           : This function will get the decrypted value of User Id & Password  * 
 *                         for the  given  database (Web Intellect/Custody Intellect)  from  *
 *                         the respective encrypted file by calling the related application  *
 *                         program (JAVA/pc/sh).                                             * 
 *                                                                                           *
 *                                                                                           *
 * Parameter                         Type               Mode     Description                 *
 * ------------                     --------            -----    ---------------             *
 * p_chr_token                       char *              NA      Login Parameter Value       *
 * p_chr_param_val                   char *              NA      Return Decrypted Value      *
 * l_debug_info_ptr                  STRUCTURE           NA      Debug Info Structure        *
 *                                                                                           *
 * Return Values        :                                                                    *
 * APL_SUCCESS  - SUCCESS                                                                    *
 * APL_FAILURE  - FAILURE                                                                    *
 *                                                                                           *
 *********************************************************************************************/

int CO_GetDBLoginDtls(char*                p_token           ,
                      char*                chr_p_val         ,
                      DEBUG_INFO_STRUCT_H  **l_debug_info_ptr)
{
  FILE    *l_finifile                                        ;
  FILE    *l_call_ret_val                  =  NULL           ;
  char    chr_l_buf         [BUFFER_LEN ]  =  APL_NULL_STRING;
  char    l_chr_inifile     [PATH_LENGTH]  =  APL_NULL_STRING;
  char    l_chr_enc_file_pth[PATH_LENGTH]  =  APL_NULL_STRING;
  char    l_chr_pg_call_str [PG_CALL_LEN]  =  APL_NULL_STRING;
  /* ISKB_9343 - Fix for Java defunct/zombies process getting created. Changes retro from BOJ. By Prateek P- Starts */
  int status = 0;
/* ISKB_9343 - Fix for Java defunct/zombies process getting created. Changes retro from BOJ. By Prateek P- Ends */



  CO_ProcMonitor(APL_OUT_FILE, "\n Entered into fn CO_GetDBLoginDtls", NULL, NULL);

  memset(chr_l_buf         , '\0', sizeof(chr_l_buf)         );
  memset(l_chr_inifile     , '\0', sizeof(l_chr_inifile)     );
  memset(l_chr_pg_call_str , '\0', sizeof(l_chr_pg_call_str) );
  memset(l_chr_enc_file_pth, '\0', sizeof(l_chr_enc_file_pth));

  strcpy(l_chr_inifile, getenv("INTL_ROOT_PATH"));
  strcat(l_chr_inifile, "intl_sun.cfg");

  /*  Opening the config file in 'read' mode */
  if ( ( l_finifile = fopen(l_chr_inifile,"r") ) == NULL)
  {
     sprintf(chr_l_buf, "\n Error while openning the config file [%s]", l_chr_inifile);
     CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);

     APL_GOBACK_FAIL
  }

  /*  Getting the Encryption Path from config file */
  if ( CO_ReadToken(l_finifile,"ENC_FILE_PATH",l_chr_enc_file_pth, l_debug_info_ptr) == APL_FAILURE)
  {
     CO_ProcMonitor(APL_OUT_FILE, "\n Error while getting the encryption file path from config file", NULL, NULL);
     APL_GOBACK_FAIL
  }

  strcat(l_chr_enc_file_pth, "\0");

  if ( !strlen(l_chr_enc_file_pth) )
  {
     CO_ProcMonitor(APL_OUT_FILE, "\n Could not get the value for encryption path from config file.. pls retry post maintaining the value..", NULL, NULL);
     APL_GOBACK_FAIL
  }

  /* Framing the application call */
  sprintf(l_chr_pg_call_str, "java KeyReaderWeb %s %s", p_token, l_chr_enc_file_pth); 
  strcat(l_chr_pg_call_str, "\0");

  memset(chr_l_buf, '\0', sizeof(chr_l_buf));
  sprintf(chr_l_buf, "\n Program Call:[%s]", l_chr_pg_call_str);
  CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);

  /* Calling the utility appl to retrive the Decrypted Value */
  if ((l_call_ret_val = popen(l_chr_pg_call_str, "r")) == NULL) 
  {
    memset(chr_l_buf, '\0', sizeof(chr_l_buf));
    sprintf(chr_l_buf, "\n Error while calling the java appl to get decrypted value for %s", p_token);
    CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);

    APL_GOBACK_FAIL
  }

  fscanf(l_call_ret_val, "%s", chr_p_val);

  if (!strlen(chr_p_val))                     /* Checking if decrypted return value is NULL */
  {
    memset(chr_l_buf, '\0', sizeof(chr_l_buf));
    sprintf(chr_l_buf, "\n Error: Returned Decrypted value for |%s| is empty", p_token);
    CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);

    APL_GOBACK_FAIL
  }
/* ISKB_9343 - Fix for Java defunct/zombies process getting created. Changes retro from BOJ. By Prateek P- Starts */
 status = pclose(l_call_ret_val);
 if(status == -1)
  {
    memset(chr_l_buf, '\0', sizeof(chr_l_buf));
    sprintf(chr_l_buf, "\n Error: Returned failure from pclose ");
    CO_ProcMonitor(APL_OUT_FILE, chr_l_buf, NULL, NULL);
    APL_GOBACK_FAIL
  }
/* ISKB_9343 - Fix for Java defunct/zombies process getting created. Changes retro from BOJ. By Prateek P- Ends */
  APL_GOBACK_SUCCESS

  RETURN_SUCCESS :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_GetDBLoginDtls successfully", NULL, NULL);
   return (APL_SUCCESS);

  RETURN_FAILURE :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_GetDBLoginDtls with errors", NULL, NULL);
   return (APL_FAILURE);

} /* End Of CO_GetDBLoginDtls */

/* Retrofit done by swamy for Back End Encryption & Decryption of DB User Name & Password Ends here */
