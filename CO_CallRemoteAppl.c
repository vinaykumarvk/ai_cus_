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
 * File Name           : CO_CallRemoteAppl.c
 *
 * Description         : This program is used for calling the remote applications 
 *                       (JAVA/pc/sh) based  on the requirement, like getting the
 *                       decrypted values for the  database login  details or any
 *                       other specific task to be performed by caling the remote
 *                       applications.
 *
 *
 *            Version Control Block
 *
 * Date        Version   Author          Description             RFS NO
 * ----------- --------  --------------  ----------------------  ---------------
 * 08-Jun-2009 1.0       Naren V         New Doc
 *
 *********************************************************************************/

/*****                             Header File Inclusion                                *****/
#include "stdio_64.h"
#include <ctype.h>
#include <string.h>
#include "Intellect_Interface.h"
#include "Intellect_Common.h"
#include "Intellect_Error.h"

/*****                              Macro Definitions                                   *****/
#define  PURE_C_SOURCE
#define  PG_CALL_LEN   500
#define  BUFFER_LEN    150

/*****                              Global Variables                                    *****/


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

  APL_GOBACK_SUCCESS

  RETURN_SUCCESS :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_GetDBLoginDtls successfully", NULL, NULL);
   return (APL_SUCCESS);

  RETURN_FAILURE :
   CO_ProcMonitor(APL_OUT_FILE, "\n Leaving fn CO_GetDBLoginDtls with errors", NULL, NULL);
   return (APL_FAILURE);

} /* End Of CO_GetDBLoginDtls */
