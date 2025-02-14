


   
   
   
   
   
   
   
   
   
   
   
   




#define PURE_C_SOURCE
#include <CO_HostStructdef.h>



 int CBUpdCustFn(MT_RUCLIENT_STRUCT_H *p_mt_ruclient_struct_h_a, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   int         int_retval;
   char        chr_l_field_val[40];
   short       int_l_condexists;
   char        chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char        chr_l_condid[APL_CONDID_LEN];
   char        chr_l_row_id_cust[APL_ROWID_LEN+1];
   char        chr_iexist,chr_iclosed,chr_icubk_a,chr_iaccclass,chr_iauthorised,chr_ifrozen;
   char        chr_l_buf[BUFFER_LEN];
   char     	chr_l_acctyp[3]            = APL_NULL_STRING;
   char        chr_l_nobaseacc[7]			  = APL_NULL_STRING;
   int         int_l_rowexists;
   char        chr_p_sys_date[APL_DATE_LEN];
   int         int_p_date_diff =0;		



   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdCustFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_cust,APL_NULL_CHAR,sizeof(chr_l_row_id_cust));

   if (strlen(p_mt_ruclient_struct_h_a->h_dl_client) == 0)
      APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Account is :%s: \n",p_mt_ruclient_struct_h_a->h_dl_client);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruclient_struct_h_a->h_cltnm) == 0)
      APL_DATA_MISSING("ACC NAME",APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Account Name is :%s: \n",p_mt_ruclient_struct_h_a->h_cltnm);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruclient_struct_h_a->h_synclt) == 0)
      APL_DATA_MISSING("SYNTHETIC ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Synacc is :%s: \n",p_mt_ruclient_struct_h_a->h_synclt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruclient_struct_h_a->h_clttyp) == 0)
      APL_DATA_MISSING("ACCOUNT TYPE",APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"ACCTYPE is :%s: \n",p_mt_ruclient_struct_h_a->h_clttyp);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
 
   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"base clt is :%d: \n",p_mt_ruclient_struct_h_a->h_baseclt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
 
   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"%d",p_mt_ruclient_struct_h_a->h_baseclt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
  
   if (strlen(chr_l_buf) == 0)
      APL_DATA_MISSING("BASE ACCOUNT",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(p_mt_ruclient_struct_h_a->h_cltopdt) == 0)
      APL_DATA_MISSING("ACCOUNT OPEN DATE",APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
 
  sprintf(chr_l_buf,"ACCOPDT is :%s: \n",p_mt_ruclient_struct_h_a->h_cltopdt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
      if (strlen(p_mt_ruclient_struct_h_a->h_access_stamp) == 0)
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"%d",p_mt_ruclient_struct_h_a->h_baseclt);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);


 
   
   if ((strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) ||  (strcmp(p_intl_env_data_struct_h_d->h_mode,CLS_MODE) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) == 0))
   {

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBCustChrValFn to obtain ROWID in Modify Mode",NULL,NULL);     

       
      int_retval = CDBCustChrValFn(p_mt_ruclient_struct_h_a->h_dl_client,"ROWID",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      strcpy(chr_l_row_id_cust,chr_l_field_val);
 
      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBCustChrValFn to check the access stamp in modify mode",NULL,NULL);
      
      
      int_retval = CDBCustChrValFn(p_mt_ruclient_struct_h_a->h_dl_client,"access_stamp",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      if (strcmp(chr_l_field_val,p_mt_ruclient_struct_h_a->h_access_stamp) != 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_ruclient_struct_h_a->h_dl_client,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
        
         APL_GOBACK_FAIL
      }
 
		if (strcmp(p_intl_env_data_struct_h_d->h_mode,CLS_MODE) != 0)
		{
			if (strcmp(p_mt_ruclient_struct_h_a->h_cltstatus,STATUS_CLS_UAUTH) == 0)
      		{
      		   CO_InsertErr(l_debug_info_ptr,ERR_ACCMARKED_FOR_CLOSE,p_mt_ruclient_struct_h_a->h_dl_client,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
         		APL_GOBACK_FAIL
			   }
		}
 
   }

   if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALCustfn in input to check the non -existence of the client in CRUACCOUNT",NULL,NULL);
      chr_iexist = 'N';
      int_retval = GDBValCustFn(p_mt_ruclient_struct_h_a->h_dl_client,chr_iexist, NULL,NULL,l_debug_info_ptr);
      
   }
   else if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALCustfn in modify to check the client in CRUACCOUNT is not closed",NULL,NULL);     

      chr_iexist = 'Y';
      chr_iclosed = 'N';
      
      int_retval = GDBValCustFn(p_mt_ruclient_struct_h_a->h_dl_client,chr_iexist,NULL,chr_iclosed,l_debug_info_ptr);

   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	
	if (strcmp(p_intl_env_data_struct_h_d->h_mode,CLS_MODE) != 0 && strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) != 0)
	{
 	  CO_ProcMonitor(APL_OUT_FILE,"Calling CDBChkCustDetFn to check the  validity of the data in any mode",NULL,NULL);

 	  int_retval = CDBChkCustDetFn(p_mt_ruclient_struct_h_a,p_intl_env_data_struct_h_d,l_debug_info_ptr);
	}

  	if (int_retval != APL_SUCCESS)
     	APL_GOBACK_FAIL 

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBUpdCustFn to update the table in any mode",NULL,NULL);

   int_retval = CDBUpdCustFn(p_mt_ruclient_struct_h_a,chr_l_row_id_cust,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdCustFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE  :
   {
      APL_IF_DEBUG

      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdCustFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}




int CBUpdCustOthFn(char *chr_p_acct,char *chr_p_acct_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int                     int_retval;
   short                   int_l_condexists;
   char                    chr_l_field_val[40];
   char                    chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char                    chr_l_condid[APL_CONDID_LEN];
   char                    chr_iexist,chr_ideleted,chr_ifrozen,chr_iclosed,chr_iauthorised,chr_iaccclass,chr_icubk_a;
   char                    chr_l_row_id_acct[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdCustOthFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_acct,APL_NULL_CHAR,sizeof(chr_l_row_id_acct));

   if (strlen(chr_p_acct) == 0)
      APL_DATA_MISSING("CLIENT",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(chr_p_acct_access_stamp) == 0)
      APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Account is %s \n",chr_p_acct);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h_d->usr);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);
      
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
   }

   
   int_retval = CDBCustChrValFn(chr_p_acct,"ROWID",chr_l_field_val,l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   strcpy(chr_l_row_id_acct,chr_l_field_val);

   
   int_retval = CDBCustChrValFn(chr_p_acct,"access_stamp",chr_l_field_val,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (strcmp(chr_l_field_val,chr_p_acct_access_stamp) != 0)
   {
      CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,chr_p_acct,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
      APL_GOBACK_FAIL
   }

   if ((strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_AUTHORISE) == 0))
   {
      chr_iexist = 'Y';
      chr_iauthorised = 'N';

      int_retval = GDBValCustFn(chr_p_acct,chr_iexist,chr_iauthorised,NULL,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      int_retval = CDBUsrAuthCustFn(chr_p_acct,p_intl_env_data_struct_h_d->usr,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
   }

	if (strcmp(p_intl_env_data_struct_h_d->h_mode,OPEN_MODE) == 0)
   {
      chr_iexist = 'Y';
      chr_iauthorised = 'Y';
      chr_iclosed = 'Y';

      int_retval = GDBValCustFn(chr_p_acct,chr_iexist,chr_iauthorised,chr_iclosed,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

		if (strlen(chr_p_acct) != 0)
 		 {
      	chr_iexist = 'Y';
     		chr_iaccclass = '2';
      	chr_iclosed ='N';
      	chr_icubk_a   = 'C';
      	chr_iauthorised = 'Y';
      	chr_ideleted = 'N';
	      chr_ifrozen = 'N';

   	   int_retval = GDBValCustAccFn(chr_p_acct,chr_iexist,chr_icubk_a,chr_iaccclass,chr_iauthorised,chr_ideleted, chr_ifrozen, chr_iclosed,l_debug_info_ptr);

      	if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL
  		}
   }


   int_retval = CDBUpdCustOthFn(chr_p_acct,chr_l_row_id_acct,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdCustOthFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdCustOthFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}



 int CBUpdRRLocFn(MT_RULOC_STRUCT_H *p_mt_ruloc_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
   int         int_retval;
   char        chr_l_field_val[40];
   short       int_l_condexists;
   char        chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char        chr_l_condid[APL_CONDID_LEN];
   char        chr_l_row_id_code[APL_ROWID_LEN+1];
	char        chr_iexist,chr_iauthorised,chr_iclosed;
   char        chr_l_buf[BUFFER_LEN];
   char        chr_l_accloctyp[3]            = APL_NULL_STRING;
   char        chr_l_nobasloc[7]         = APL_NULL_STRING;
   int         int_l_rowexists;
   char        chr_p_sys_date[APL_DATE_LEN];
   int         int_p_date_diff =0;
  
   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRLocFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));
	
	if (strlen(p_mt_ruloc_struct_h->h_loc) == 0)
		APL_DATA_MISSING("LOC",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Location is :%s: \n",p_mt_ruloc_struct_h->h_loc);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruloc_struct_h->h_locm) == 0)
		APL_DATA_MISSING("LOCATION NAME ",APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Location Name is :%s: \n",p_mt_ruloc_struct_h->h_locm);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruloc_struct_h->h_syn_location) == 0)
		APL_DATA_MISSING("SYNTHETIC LOCATION", APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Synthetic LOCATION is :%s: \n",p_mt_ruloc_struct_h->h_syn_location);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruloc_struct_h->h_license_no) == 0)
		APL_DATA_MISSING("LICENSE NO",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"License No. is :%s: \n",p_mt_ruloc_struct_h->h_license_no);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruloc_struct_h->h_loc_class) == 0)
   	APL_DATA_MISSING("LOCATION TYPE",APL_NULL_STRING,APL_NULL_STRING)

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Location Type is :%s: \n",p_mt_ruloc_struct_h->h_loc_class);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruloc_struct_h->h_depo_cd) == 0)
		APL_DATA_MISSING("DEPOSITORY CODE",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Depository Code is :%s: \n",p_mt_ruloc_struct_h->h_depo_cd);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"base loc is :%d: \n",p_mt_ruloc_struct_h->h_baseloc);	
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(chr_l_buf) == 0)
      APL_DATA_MISSING("BASE LOCATION",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(p_mt_ruloc_struct_h->h_locopdate) == 0)
		APL_DATA_MISSING("LOCATION OPEN DATE", APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Location Open chr_date is :%s: \n",p_mt_ruloc_struct_h->h_locopdate);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Loc CLose Dt is :%s: \n",p_mt_ruloc_struct_h->h_loccldate);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"NOSTRO A/C TYPE is :%s: \n",p_mt_ruloc_struct_h->h_nostr_clttyp);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(p_mt_ruloc_struct_h->h_nostr_clttyp) == 0)
		APL_DATA_MISSING("NOSTRO A/C TYPE",APL_NULL_STRING,APL_NULL_STRING)

   if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
      if (strlen(p_mt_ruloc_struct_h->h_access_stamp) == 0)
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"%d",p_mt_ruloc_struct_h->h_baseloc);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

  

	 
	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0 || strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) == 0)
   {

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRLocChrValFn to obtain ROWID in Modify Mode",NULL,NULL);

       
		int_retval = CDBRRLocChrValFn(p_mt_ruloc_struct_h->h_loc,"ROWID",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      strcpy(chr_l_row_id_code,chr_l_field_val);

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRLOCChrValFnto check the access stamp in modify mode",NULL,NULL);

      
      int_retval = CDBRRLocChrValFn(p_mt_ruloc_struct_h->h_loc,"access_stamp",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      if (strcmp(chr_l_field_val,p_mt_ruloc_struct_h->h_access_stamp) != 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_ruloc_struct_h->h_loc,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

         APL_GOBACK_FAIL
      }

		if (strcmp(p_mt_ruloc_struct_h->h_rulocstatus_ind,STATUS_CLS_UAUTH) == 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_LOCN_MARKED_CLOSE,p_mt_ruloc_struct_h->h_loc,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
         APL_GOBACK_FAIL
      }
   }
  
   if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRLOCFN in input to check the non -existence of the location in CRULOCATION",NULL,NULL);

		chr_iexist = 'N';
      int_retval = GDBValRRLocFn(p_mt_ruloc_struct_h->h_loc,chr_iexist, NULL,NULL, l_debug_info_ptr);

	}
   else if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRLocFn in modify to check the CRULOCATION is not closed",NULL,NULL);

      chr_iexist = 'Y';
      chr_iclosed = 'N'; 
		 
		int_retval = GDBValRRLocFn(p_mt_ruloc_struct_h->h_loc,chr_iexist,chr_iauthorised,chr_iclosed,l_debug_info_ptr);

   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBChkRRLocDetFn to check the  validity of the data in any mode",NULL,NULL);

   int_retval = CDBChkRRLocDetFn(p_mt_ruloc_struct_h,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBUpdRRLocFn to update the table in any mode",NULL,NULL);

   int_retval = CDBUpdRRLocFn(p_mt_ruloc_struct_h,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRLocFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE  :
   {
      APL_IF_DEBUG

      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRLocFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}




int CBUpdRRLocOthFn(char *chr_p_rrloc,char *chr_p_rrloc_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int                     int_retval;
   short                   int_l_condexists;
   char                    chr_l_field_val[40];
   char                    chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char                    chr_l_condid[APL_CONDID_LEN];
   char                    chr_iexist,chr_iclosed,chr_iauthorised; 
   char                    chr_l_row_id_code[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRLocOthFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));

   if (strlen(chr_p_rrloc) == 0)
      APL_DATA_MISSING("LOC",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(chr_p_rrloc_access_stamp) == 0)
      APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"LOCATION IS %s \n",chr_p_rrloc);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h_d->usr);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);

      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
   }

   
	int_retval = CDBRRLocChrValFn(chr_p_rrloc,"ROWID",chr_l_field_val,l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   strcpy(chr_l_row_id_code,chr_l_field_val);

   
   int_retval = CDBRRLocChrValFn(chr_p_rrloc,"access_stamp",chr_l_field_val,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (strcmp(chr_l_field_val,chr_p_rrloc_access_stamp) != 0)
   {
      CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,chr_p_rrloc,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
      APL_GOBACK_FAIL
   }

   if ((strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_AUTHORISE) == 0))
   {
      chr_iexist = 'Y';
      chr_iauthorised = 'N';

      int_retval = GDBValRRLocFn(chr_p_rrloc,chr_iexist,chr_iauthorised,NULL,l_debug_info_ptr);
		if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      int_retval = CDBUsrAuthRRLocFn(chr_p_rrloc,p_intl_env_data_struct_h_d->usr,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
   }

   

   int_retval = CDBUpdRRLocOthFn(chr_p_rrloc,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRLocOthFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRLocOthFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}



 int CBUpdRRProdFn(MT_RUPROD_STRUCT_H *p_mt_ruprod_struct_h_b, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
   int         int_retval;
   char        chr_l_field_val[40];
	short       int_l_condexists;
   char        chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char        chr_l_condid[APL_CONDID_LEN];
   char        chr_l_row_id_code[APL_ROWID_LEN+1];
   char        chr_iexist,chr_iauthorised;
   char        chr_l_buf[BUFFER_LEN];
	int         int_l_rowexists;
   char        chr_p_sys_date[APL_DATE_LEN];
   int         int_p_date_diff =0;
   int 	       int_l_count = 0;  

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRProdFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));

   if (strlen(p_mt_ruprod_struct_h_b->h_pr_code) == 0)
      APL_DATA_MISSING("PRODUCT",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Product is :%s: \n",p_mt_ruprod_struct_h_b->h_pr_code);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruprod_struct_h_b->h_prdetail) == 0)
      APL_DATA_MISSING("PRODUCT DESCRIPTION",APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"PRODUCT DESCRIPTION IS :%s: \n",p_mt_ruprod_struct_h_b->h_prdetail);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruprod_struct_h_b->h_ccy) == 0)
      APL_DATA_MISSING("CURRENCY", APL_NULL_STRING,APL_NULL_STRING)

    memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"CURRENCY IS :%s: \n",p_mt_ruprod_struct_h_b->h_ccy);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruprod_struct_h_b->h_daydate) == 0)
      APL_DATA_MISSING("DAY/DT",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"DAY/DT is :%s: \n",p_mt_ruprod_struct_h_b->h_daydate);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruprod_struct_h_b->h_day_yr) == 0)
      APL_DATA_MISSING("DAYS/YEAR",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Days/Year is :%s: \n",p_mt_ruprod_struct_h_b->h_day_yr);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruprod_struct_h_b->h_prdateyp) == 0)
      APL_DATA_MISSING("PRODUCT TYPE",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"PRODUCT TYPE is :%s: \n",p_mt_ruprod_struct_h_b->h_prdateyp);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(p_mt_ruprod_struct_h_b->h_loc) == 0)
      APL_DATA_MISSING("LOC",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"Location is :%s: \n",p_mt_ruprod_struct_h_b->h_loc);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
      if (strlen(p_mt_ruprod_struct_h_b->h_access_stamp) == 0)
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

	
	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0 || strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) == 0)
   {
      	

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRProdChrValFn to obtain ROWID in Modify Mode",NULL,NULL);

       
      int_retval = CDBRRProdChrValFn(p_mt_ruprod_struct_h_b->h_pr_code,"ROWID",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      strcpy(chr_l_row_id_code,chr_l_field_val);

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRProdChrValFnto check the access stamp in modify mode",NULL,NULL);

      
      int_retval = CDBRRProdChrValFn(p_mt_ruprod_struct_h_b->h_pr_code,"access_stamp",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      if (strcmp(chr_l_field_val,p_mt_ruprod_struct_h_b->h_access_stamp) != 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_ruprod_struct_h_b->h_pr_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

         APL_GOBACK_FAIL
      }

   }

   if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRProdFN in input to check the non -existence of the Product in CRUPRODUCT",NULL,NULL);

		chr_iexist = 'N';
      int_retval = GDBValRRProdFn(p_mt_ruprod_struct_h_b->h_pr_code,chr_iexist,NULL, l_debug_info_ptr);

   }
   else if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRProdFn in modify to check the CRUPRODUCT is existing or not",NULL,NULL);

      chr_iexist = 'Y';
	   
		int_retval = GDBValRRProdFn(p_mt_ruprod_struct_h_b->h_pr_code,chr_iexist,chr_iauthorised,l_debug_info_ptr);

   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	CO_ProcMonitor(APL_OUT_FILE,"Calling CDBChkRRProdFn to check the  validity of the data in any mode",NULL,NULL);

   int_retval = CDBChkRRProdDetFn(p_mt_ruprod_struct_h_b,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBUpdRRProdFn to update the table in any mode",NULL,NULL);

   int_retval = CDBUpdRRProdFn(p_mt_ruprod_struct_h_b,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRProdFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE  :
   {
      APL_IF_DEBUG

      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRProdFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}



int CBUpdRRProdOthFn(char *chr_p_rrprod,char *chr_p_rrprod_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d,
DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
 {
   int                     int_retval;
   short                   int_l_condexists;
   char                    chr_l_field_val[40];
   char                    chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char                    chr_l_condid[APL_CONDID_LEN];
   char                    chr_iexist,chr_iclosed,chr_iauthorised;
   char                    chr_l_row_id_code[APL_ROWID_LEN+1];
   char                    chr_l_buf[BUFFER_LEN];

   APL_IF_DEBUG
   CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRProdOthFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));

   if (strlen(chr_p_rrprod) == 0)
      APL_DATA_MISSING("PRODUCT",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(chr_p_rrprod_access_stamp) == 0)
      APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_IF_DEBUG
   {
      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"PRODUCTIS %s \n",chr_p_rrprod);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"User is %s \n",p_intl_env_data_struct_h_d->usr);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Mode is %s \n",p_intl_env_data_struct_h_d->h_mode);
      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);

      memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
      sprintf(chr_l_buf,"Country h_code is %s \n",g_mt_commonsys_params_struct_h.nation_code);

      CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,p_intl_env_data_struct_h_d);
   }
		

	int_retval = CDBRRProdChrValFn(chr_p_rrprod,"ROWID",chr_l_field_val,l_debug_info_ptr);

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   strcpy(chr_l_row_id_code,chr_l_field_val);

   
   int_retval = CDBRRProdChrValFn(chr_p_rrprod,"access_stamp",chr_l_field_val,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (strcmp(chr_l_field_val,chr_p_rrprod_access_stamp) != 0)
   {
      CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,chr_p_rrprod,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
      APL_GOBACK_FAIL
   }

   if ((strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_AUTHORISE) == 0))
   {
      chr_iexist = 'Y';
      chr_iauthorised = 'N';

      int_retval = GDBValRRProdFn(chr_p_rrprod,chr_iexist,chr_iauthorised,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      int_retval = CDBUsrAuthRRProdFn(chr_p_rrprod,p_intl_env_data_struct_h_d->usr,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL
   }

	int_retval = CDBUpdRRProdOthFn(chr_p_rrprod,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRProdOthFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRProdOthFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}



int CBUpdRRSRNFn(MT_RUSRN_STRUCT_H *p_mt_rusrn_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
   int         int_retval;
   char        chr_l_field_val[40];
   short       int_l_condexists;
   char        chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char        chr_l_condid[APL_CONDID_LEN];
   char        chr_l_row_id_code[APL_ROWID_LEN+1];
   char        chr_iexist,chr_iauthorised;
   char        chr_l_buf[BUFFER_LEN];
   int         int_l_rowexists;
   char        chr_p_sys_date[APL_DATE_LEN];
   int         int_p_date_diff =0;

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRSRNFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));

   if (strlen(p_mt_rusrn_struct_h->h_stat_reg_no) == 0)
      APL_DATA_MISSING("SRN",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"SRN is :%s: \n",p_mt_rusrn_struct_h->h_stat_reg_no);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_rusrn_struct_h->h_instr_code) == 0)
      APL_DATA_MISSING("INSTRUMENT",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT is :%s: \n",p_mt_rusrn_struct_h->h_instr_code);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"SEC DESC IS :%s: \n",p_mt_rusrn_struct_h->h_instr_name);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_rusrn_struct_h->h_identiy_num) == 0)
      APL_DATA_MISSING("REF NUM",APL_NULL_STRING,APL_NULL_STRING)

   if (strlen(p_mt_rusrn_struct_h->h_identiy_num));
   sprintf(chr_l_buf,"REF NUM IS :%s: \n",p_mt_rusrn_struct_h->h_identiy_num);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
      if (strlen(p_mt_rusrn_struct_h->h_access_stamp) == 0)
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)

   
   if ((strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) == 0))
   {

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRSRNChrValFn to obtain ROWID in Modify Mode",NULL,NULL);

       
		 int_retval = CDBRRSRNChrValFn(p_mt_rusrn_struct_h->h_stat_reg_no,p_mt_rusrn_struct_h->h_instr_code,"ROWID",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      strcpy(chr_l_row_id_code,chr_l_field_val);

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRSRNChrValFnto check the access stamp in modify mode",NULL,NULL);

      
      int_retval = CDBRRSRNChrValFn(p_mt_rusrn_struct_h->h_stat_reg_no,p_mt_rusrn_struct_h->h_instr_code,"access_stamp",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      if (strcmp(chr_l_field_val,p_mt_rusrn_struct_h->h_access_stamp) != 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_rusrn_struct_h->h_stat_reg_no,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

         APL_GOBACK_FAIL
      }
	}

	if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRSRNFN in input to check the non -existence of the srn in CRUSRN",NULL,NULL);

		chr_iexist = 'N';
      int_retval = GDBValRRSRNFn(p_mt_rusrn_struct_h->h_stat_reg_no, p_mt_rusrn_struct_h->h_instr_code,chr_iexist,NULL, l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

	int_retval = GDBValRRSRNRefnumFn(p_mt_rusrn_struct_h->h_stat_reg_no, p_mt_rusrn_struct_h->h_instr_code,p_mt_rusrn_struct_h->h_identiy_num,p_intl_env_data_struct_h_d,l_debug_info_ptr);

   }
   else if ((strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0))
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRSRNFn in modify to check the SRN AND INSTR_CODE is existing or not",NULL,NULL);

      chr_iexist = 'Y';
      
      if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0)
      chr_iauthorised = 'N';
      int_retval = GDBValRRSRNFn(p_mt_rusrn_struct_h->h_stat_reg_no,p_mt_rusrn_struct_h->h_instr_code,chr_iexist,chr_iauthorised,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

		if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0)
			int_retval = GDBValRRSRNRefnumFn(p_mt_rusrn_struct_h->h_stat_reg_no, p_mt_rusrn_struct_h->h_instr_code,p_mt_rusrn_struct_h->h_identiy_num,p_intl_env_data_struct_h_d,l_debug_info_ptr);
			if (int_retval != APL_SUCCESS)
         	APL_GOBACK_FAIL


	  if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0)
		 int_retval = CDBUsrAuthRRSRNFn(p_mt_rusrn_struct_h->h_stat_reg_no,p_mt_rusrn_struct_h->h_instr_code,p_intl_env_data_struct_h_d->usr,l_debug_info_ptr);
      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBChkRRSRNFn to check the  validity of the data in any mode",NULL,NULL);

  if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) != 0)
	{

 	  int_retval = CDBChkRRSRNDetFn(p_mt_rusrn_struct_h,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   	if (int_retval != APL_SUCCESS)
      	APL_GOBACK_FAIL
	}

 	CO_ProcMonitor(APL_OUT_FILE,"Calling CDBUpdRRSRNFn to update the table in any mode",NULL,NULL);

 	int_retval = CDBUpdRRSRNFn(p_mt_rusrn_struct_h,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
     	APL_GOBACK_FAIL

 	APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRSRNFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE  :
   {
      APL_IF_DEBUG

      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRSRNFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}



int CBUpdRRInstrFn(MT_RUINSTR_STRUCT_H *p_mt_ruinstr_struct_h, INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_d, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)

{
   int         int_retval;
   char        chr_l_field_val[40];
   short       int_l_condexists;
   char        chr_mainfuncarea[APL_MAINFUNCAREA_LEN];
   char        chr_l_condid[APL_CONDID_LEN];
	char        chr_l_row_id_code[APL_ROWID_LEN+1];
   char        chr_iexist,chr_iauthorisedi,chr_iclosed,chr_ideleted;
   char        chr_l_buf[BUFFER_LEN];
   int         int_l_rowexists;
   char        chr_p_sys_date[APL_DATE_LEN];
   int         int_p_date_diff =0;

   APL_IF_DEBUG
      CO_ProcMonitor(APL_OUT_FILE,"Entered processtion CBUpdRRInstrFn \n",NULL,p_intl_env_data_struct_h_d);

   memset(chr_l_row_id_code,APL_NULL_CHAR,sizeof(chr_l_row_id_code));

   if (strlen(p_mt_ruinstr_struct_h->h_stat_reg_no) == 0)
      APL_DATA_MISSING("INSTR_CODE",APL_NULL_STRING,APL_NULL_STRING)

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTR_CODE IS :%s: \n",p_mt_ruinstr_struct_h->h_instr_code);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(p_mt_ruinstr_struct_h->h_instr_code) == 0)
      APL_DATA_MISSING("INSTRUMENT NAME",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT NAME Is:%s: \n",p_mt_ruinstr_struct_h->h_instr_nm);
	CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruinstr_struct_h->h_snm_ind) == 0)
      APL_DATA_MISSING("ISSUER NAME",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"ISSUER  NAME Is:%s: \n",p_mt_ruinstr_struct_h->h_snm_ind);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruinstr_struct_h->h_stat_reg_no) == 0)
      APL_DATA_MISSING("STATE REG NO.",APL_NULL_STRING,APL_NULL_STRING)

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"STATREGNOIs:%s: \n",p_mt_ruinstr_struct_h->h_stat_reg_no);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(p_mt_ruinstr_struct_h->h_instr_opdate) == 0)
      APL_DATA_MISSING("INSTRUMENT OPEN DATE",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT OPEN DATE Is:%s: \n",p_mt_ruinstr_struct_h->h_instr_opdate);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT CLOSE DATE Is:%s: \n",p_mt_ruinstr_struct_h->h_instrcldate);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(p_mt_ruinstr_struct_h->h_instr_cldate) == 0)
      APL_DATA_MISSING("INSTRUMENT CLASS",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT CLASS IS :%s: \n",p_mt_ruinstr_struct_h->h_instr_cldate);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"base sec is :%d: \n",p_mt_ruinstr_struct_h->h_baseinstrument);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"%d",p_mt_ruinstr_struct_h->h_baseinstrument);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   if (strlen(chr_l_buf) == 0)
      APL_DATA_MISSING("BASE SEC",APL_NULL_STRING,APL_NULL_STRING)

	if (strlen(p_mt_ruinstr_struct_h->h_instr_class) == 0)
      APL_DATA_MISSING("INSTRUMENT TYPE",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"INSTRUMENT TYPEIS :%s: \n",p_mt_ruinstr_struct_h->h_instr_class);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strlen(p_mt_ruinstr_struct_h->h_pr_code) == 0)
      APL_DATA_MISSING("PRODUCT CODE",APL_NULL_STRING,APL_NULL_STRING)

   memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"PRODUCT CODE IS :%s: \n",p_mt_ruinstr_struct_h->h_pr_code);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

	if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0)
      if (strlen(p_mt_ruinstr_struct_h->h_access_stamp) == 0)
         APL_DATA_MISSING("ACCESS STAMP",APL_NULL_STRING,APL_NULL_STRING)
	
	memset(chr_l_buf,APL_NULL_CHAR,BUFFER_LEN);
   sprintf(chr_l_buf,"%d",p_mt_ruinstr_struct_h->h_baseinstrument);
   CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

   

	
	if ((strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_DELETE) == 0))
	{

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRInstrChrValFn to obtain ROWID in Modify Mode",NULL,NULL);

       

		 int_retval = CDBRRInstrChrValFn(p_mt_ruinstr_struct_h->h_instr_code,"ROWID",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      strcpy(chr_l_row_id_code,chr_l_field_val);

      CO_ProcMonitor(APL_OUT_FILE,"Calling CDBRRInstrChrValFn to check the access stamp in modify mode",NULL,NULL);

      
      int_retval = CDBRRInstrChrValFn(p_mt_ruinstr_struct_h->h_instr_code,"access_stamp",chr_l_field_val,l_debug_info_ptr);

      if (int_retval != APL_SUCCESS)
         APL_GOBACK_FAIL

      if (strcmp(chr_l_field_val,p_mt_ruinstr_struct_h->h_access_stamp) != 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCESSSTAMP_CHGD,p_mt_ruinstr_struct_h->h_instr_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);

         APL_GOBACK_FAIL
      }

		if (strcmp(p_mt_ruinstr_struct_h->h_ruinstrstatus_ind,STATUS_CLS_UAUTH) == 0)
      {
         CO_InsertErr(l_debug_info_ptr,ERR_ACCMARKED_FOR_CLOSE,p_mt_ruinstr_struct_h->h_instr_code,APL_NULL_STRING,APL_NULL_STRING,__LINE__,__FILE__);
               APL_GOBACK_FAIL
      }
	}

	if (strcmp(p_intl_env_data_struct_h_d->h_mode, APL_FUNC_INPUT) == 0)
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRInstr fn in input to check the non -existence of the instrument in CRUINSTRUMENT",NULL,NULL);
		
		chr_iexist = 'N';
      int_retval = GDBValRRInstrFn(p_mt_ruinstr_struct_h->h_instr_code,chr_iexist, NULL,NULL,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

		

   }
   else if ((strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_MODIFY) == 0) || (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0))
   {
      CO_ProcMonitor(APL_OUT_FILE,"Calling GDBVALRRInstrfn in modify to check the instrument in CRUINSTRUMENT is not closed",NULL,NULL);

      chr_iexist = 'Y';
      chr_iclosed = 'N';

      int_retval = GDBValRRInstrFn(p_mt_ruinstr_struct_h->h_instr_code,chr_iexist,NULL,chr_iclosed,l_debug_info_ptr);

		if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

		if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) != 0)
         
         if (int_retval != APL_SUCCESS)
            APL_GOBACK_FAIL

		if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) == 0)
      	int_retval = CDBUsrAuthRRInstrFn(p_mt_ruinstr_struct_h->h_instr_code,p_intl_env_data_struct_h_d->usr, l_debug_info_ptr);
	
   	   if (int_retval != APL_SUCCESS)
      	   APL_GOBACK_FAIL

   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   if (strcmp(p_intl_env_data_struct_h_d->h_mode,APL_FUNC_AUTHORISE) != 0)
   {
     CO_ProcMonitor(APL_OUT_FILE,"Calling CDBChkRRInstrDetFn to check the  validity of the data in any mode",NULL,NULL);

     int_retval = CDBChkRRInstrDetFn(p_mt_ruinstr_struct_h,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   }

   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   CO_ProcMonitor(APL_OUT_FILE,"Calling CDBUpdRRInstrFn to update the table in any mode",NULL,NULL);

   int_retval = CDBUpdRRInstrFn(p_mt_ruinstr_struct_h,chr_l_row_id_code,p_intl_env_data_struct_h_d,l_debug_info_ptr);
   if (int_retval != APL_SUCCESS)
      APL_GOBACK_FAIL

   APL_GOBACK_SUCCESS

   RETURN_SUCCESS :
   {
      APL_IF_DEBUG
         CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRInstrFn SUCCESS \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_SUCCESS);
   }

   RETURN_FAILURE  :
   {
      APL_IF_DEBUG

      CO_ProcMonitor(APL_OUT_FILE,"Leaving processtion CBUpdRRInstrFn FAILURE \n",NULL,p_intl_env_data_struct_h_d);
      return(APL_FAILURE);
   }
}





