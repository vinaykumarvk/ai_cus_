




	








#define PURE_C_SOURCE
#include "CO_HostStructdef.h" 

extern int DL_Rtv_DLPmtRst(char *,char *,DL_DEAL_RSTPMT_STRUCT_H *,DEBUG_INFO_STRUCT_H **);

int CR_Proc_DLPmtRst (char *p_client,char *p_indentity_no,char *chr_p_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

 

  DL_DEALAUDIT_STRUCT_H *l_dl_dealaudit_struct_hd;
  DL_DEAL_RSTPMT_STRUCT_H *l_dl_deal_rstpmt_struct_h;
  DL_DEAL_OTH_STRUCT_H *l_dl_deal_oth_struct_ha_a;

  char chr_p_prntconfdt[APL_DATE_LEN];
  char chr_l_h_origrefno[17];

  double	l_avquantity = 0.0;


  int int_error_flag = APL_SUCCESS;
  int int_p_enuf = APL_SUCCESS;
  int int_l_flg = 0;
  int int_l_ruclscodechk=0;     
  char  chr_l_buf[31]=APL_NULL_STRING;

	int 	int_p_smieligibility_flg = 0;
	char	chr_l_be_locncode[APL_LOCNCODE_LENGTH] = APL_NULL_STRING;	
	char  chr_l_be_trdt[20]                   = APL_NULL_STRING;
	char  chr_l_be_typeoftrd[3]               = APL_NULL_STRING;
	char  chr_l_be_instrcode[APL_INSTRUMENTCODE_LEN]     = APL_NULL_STRING;
	char  chr_l_be_locnchng_flg[2]            = APL_NULL_STRING;
	char  chr_l_be_rowid[APL_ROWID_LEN]       = APL_NULL_STRING;

	char chr_mainfuncarea[APL_MAINFUNCAREA_LEN] = APL_NULL_STRING;
	char chr_l_condid[APL_CONDID_LEN] = APL_NULL_STRING;
	short int_l_condexists = 0;
	char l_block_type[5] = APL_NULL_STRING;

  l_dl_dealaudit_struct_hd = (DL_DEALAUDIT_STRUCT_H *)calloc(1,sizeof(DL_DEALAUDIT_STRUCT_H));
  APL_MALLOC_FAIL(l_dl_dealaudit_struct_hd);
  l_dl_deal_rstpmt_struct_h = (DL_DEAL_RSTPMT_STRUCT_H *)calloc(1,sizeof(DL_DEAL_RSTPMT_STRUCT_H));
  APL_MALLOC_FAIL(l_dl_deal_rstpmt_struct_h);
  l_dl_deal_oth_struct_ha_a = (DL_DEAL_OTH_STRUCT_H *)calloc(1,sizeof(DL_DEAL_OTH_STRUCT_H));
  APL_MALLOC_FAIL(l_dl_deal_oth_struct_ha_a);



  strcpy(l_dl_deal_rstpmt_struct_h->p_ora_rowid, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_maker, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_cltstmp_cmp, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_loccode, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_status_ind, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_dt, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_orefretval, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_delrecdate, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_instrdate, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_moneydate, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_instr_code, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_currencycode, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_posnstatus_ind, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_dealcd, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_failreas_cd, APL_NULL_STRING);
  strcpy(l_dl_deal_rstpmt_struct_h->p_dlfromord, APL_NULL_STRING);

  l_dl_deal_rstpmt_struct_h->p_quantity =0;

#ifdef SYS_DEBUG
	fprintf(APL_OUT_FILE, "Entered Function CR_Proc_DLPmtRst. Going for mandatory checks\n");
#endif



	if (!strlen(p_client)) {APL_DATA_MISSING("Account",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  	if (!strlen(p_indentity_no)) {APL_DATA_MISSING("Reference Number",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 
  	if (!strlen(chr_p_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 



  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}
 





		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"instr_code",
														chr_l_be_instrcode,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}

	if ( strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind,"Y") == 0 )
	{
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"locncode",
														chr_l_be_locncode,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"trdt",
														chr_l_be_trdt,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"typeoftrd",
														chr_l_be_typeoftrd,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"locnchng_flg",
														chr_l_be_locnchng_flg,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"rowid",
														chr_l_be_rowid,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (EI_Chk_SMIElg(chr_l_be_locncode,
										  chr_l_be_trdt,
										  chr_l_be_typeoftrd,
										  chr_l_be_instrcode,
										  chr_l_be_locnchng_flg,
										  chr_l_be_rowid,
										  &int_p_smieligibility_flg,
										  p_intl_envdatastruct_h,
										  l_debug_info_ptr
										  ) == APL_FAILURE)
		{
			CO_ProcMonitor(APL_OUT_FILE,"Failure from SMI_CheckSMIEligibility", NULL,p_intl_envdatastruct_h);
			APL_GOBACK_FAIL;
		}
	}
	else
	{
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"typeoftrd",
														chr_l_be_typeoftrd,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
		if (APL_FAILURE == DL_Rtv_TrdChrVal(  p_client,
														p_indentity_no,
														"trcode",
														l_dl_deal_rstpmt_struct_h->p_dealcd,
														l_debug_info_ptr ))
		{
			APL_GOBACK_FAIL
		}
	}

	strcpy(chr_l_buf,"RU CHK: instr_code=");
	strcat(chr_l_buf,chr_l_be_instrcode);
   CO_ProcMonitor(   APL_OUT_FILE, chr_l_buf, NULL, NULL);

   if (APL_FAILURE == DL_Proc_RstPmtSkip(chr_l_be_instrcode, &int_l_ruclscodechk, l_debug_info_ptr))	
		APL_GOBACK_FAIL          
	
	fprintf(APL_OUT_FILE, "RU CHK: ruclschk=(%d)\n",int_l_ruclscodechk);

   if (APL_SUCCESS == DL_Rtv_DLPmtRst(	p_client,p_indentity_no,l_dl_deal_rstpmt_struct_h
					,l_debug_info_ptr))
	{
		if ( (!strcmp(l_dl_deal_rstpmt_struct_h->p_cltstmp_cmp,chr_p_access_stamp)) ||
			  ( (int_p_smieligibility_flg) &&
				 (strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind,"Y") == 0)) )
		{
  			if (APL_SUCCESS == DL_Chk_DLDet(p_client, p_indentity_no,'Y','Y','N','Y',APL_NULL_CHAR,'N','N',APL_NULL_CHAR,l_debug_info_ptr))
    		{ 
       	if (!strlen(l_dl_deal_rstpmt_struct_h->p_delrecdate))
          {	
	  if(	(APL_SUCCESS == CO_Chk_AccValid(	p_client,'Y',APL_NULL_CHAR,
						APL_NULL_CHAR,APL_NULL_CHAR,
						'Y','N','N','N',l_debug_info_ptr))
		 && (APL_SUCCESS == CO_Chk_InstrValid(l_dl_deal_rstpmt_struct_h->p_instr_code,
						'Y','Y','N','N',
						APL_NULL_CHAR,APL_NULL_CHAR,
						l_debug_info_ptr)		)  
		 && (APL_SUCCESS == CO_Chk_CcyValid(l_dl_deal_rstpmt_struct_h->p_currencycode,
						'M','Y',l_debug_info_ptr)) )
		{
		 if(l_mt_core_sys_params_struct_h.loc_proc_ind[0] == 'Y')
		 {
		 if(APL_SUCCESS != MT_Chk_Loc(l_dl_deal_rstpmt_struct_h->p_loccode,
						'Y','Y','N',
						l_debug_info_ptr)		) APL_GOBACK_FAIL;
		  }

		

		if (strcmp(p_indentity_no,l_dl_deal_rstpmt_struct_h->p_orefretval) &&
			(l_dl_deal_rstpmt_struct_h->p_dlfromord[0] == 'N'))
		{
			if(APL_SUCCESS != DL_Rtv_TrdChrVal(p_client,l_dl_deal_rstpmt_struct_h->p_orefretval,
									"confdt",chr_p_prntconfdt,l_debug_info_ptr)) APL_GOBACK_FAIL;
		}
		if (!strcmp(p_indentity_no,l_dl_deal_rstpmt_struct_h->p_orefretval) ||
			(!strlen(chr_p_prntconfdt)) ||
			(l_dl_deal_rstpmt_struct_h->p_dlfromord[0] == 'Y'))
		{
			if(CA_Rtv_Block_Type(  p_indentity_no,
						chr_l_be_typeoftrd,
						l_dl_deal_rstpmt_struct_h->p_dealcd,
						l_block_type,
						l_debug_info_ptr) == APL_FAILURE)
			{
					APL_GOBACK_FAIL
			}
                 if (APL_SUCCESS == DL_Proc_PosLock(p_client,l_dl_deal_rstpmt_struct_h->p_instr_code, 
							 l_dl_deal_rstpmt_struct_h->p_loccode,
							 l_dl_deal_rstpmt_struct_h->p_posnstatus_ind,l_block_type,
							 l_debug_info_ptr))
 			{

				

			if ((VAL_DELIVER_DEAL(l_dl_deal_rstpmt_struct_h->p_dealcd[0]) || l_dl_deal_rstpmt_struct_h->p_dealcd[0]=='5' || l_dl_deal_rstpmt_struct_h->p_dealcd[0]=='7') ||
				 (APL_SUCCESS == DL_Chk_AvlPos(	p_client,
															l_dl_deal_rstpmt_struct_h->p_instr_code,
															l_dl_deal_rstpmt_struct_h->p_loccode,
															'Y','N','N','Y','Y','N','N','N',
															l_block_type,
															&l_avquantity,
															l_debug_info_ptr )))
			{
				if ((VAL_RECDEAL(l_dl_deal_rstpmt_struct_h->p_dealcd[0]) || l_dl_deal_rstpmt_struct_h->p_dealcd[0]=='6' || l_dl_deal_rstpmt_struct_h->p_dealcd[0]=='8') && 
					 (l_avquantity < l_dl_deal_rstpmt_struct_h->p_quantity))
				{
					if( int_l_ruclscodechk==1 )    
					{
					
					}
					else
					{
					CO_InsertErr(	l_debug_info_ptr,
											ERR_DEAL_NENUFPOSN,
											p_client,
											p_indentity_no,
											APL_NULL_STRING,
											__LINE__,
											__FILE__ );
					APL_GOBACK_FAIL
					}
				}
											
	    		if( (l_dl_deal_rstpmt_struct_h->p_dealcd[0] == DEALCD_DF || l_dl_deal_rstpmt_struct_h->p_dealcd[0] == DEALCD_DVP || l_dl_deal_rstpmt_struct_h->p_dealcd[0] == DEALCD_CD || l_dl_deal_rstpmt_struct_h->p_dealcd[0] == DEALCD_DCD ) || ( int_l_ruclscodechk || ( APL_SUCCESS == DL_Chk_VDPPos(p_client,l_dl_deal_rstpmt_struct_h->p_instr_code,
						l_dl_deal_rstpmt_struct_h->p_loccode,l_dl_deal_rstpmt_struct_h->p_posnstatus_ind,
						l_dl_deal_rstpmt_struct_h->p_quantity,l_dl_deal_rstpmt_struct_h->p_dt,&int_p_enuf,
						l_debug_info_ptr) ) ))     
	      	{
			if ( (!strcmp(l_dl_deal_rstpmt_struct_h->p_cltstmp_cmp,chr_p_access_stamp)) ||
           	  ( (int_p_smieligibility_flg) &&
                (strcmp(g_mt_commonsys_params_struct_h.ei_smi_ind,"Y") == 0)) )
		   	{
					

					#ifdef EMU_PROCESSING
					
					#endif

		   	strcpy(l_dl_deal_oth_struct_ha_a->h_dl_client,p_client);
		   	strcpy(l_dl_deal_oth_struct_ha_a->h_indentity_no,p_indentity_no);

			   if (APL_SUCCESS != DL_Mod_DLPos(l_dl_deal_oth_struct_ha_a,
						l_dl_deal_rstpmt_struct_h->p_ora_rowid,
						p_intl_envdatastruct_h, l_debug_info_ptr))
		      { APL_GOBACK_FAIL }
				if(CA_Rtv_Block_Type(  p_indentity_no,
						chr_l_be_typeoftrd,
						l_dl_deal_rstpmt_struct_h->p_dealcd,
							l_block_type,
							l_debug_info_ptr) == APL_FAILURE)
				{
						APL_GOBACK_FAIL
				}

	 	   if(APL_SUCCESS != DL_Mod_Posn(p_client,l_dl_deal_rstpmt_struct_h->p_instr_code,
						l_dl_deal_rstpmt_struct_h->p_loccode,
						l_dl_deal_rstpmt_struct_h->p_posnstatus_ind,
						'C',l_dl_deal_rstpmt_struct_h->p_dealcd[0],
						&l_dl_deal_rstpmt_struct_h->p_quantity,
						'D',l_block_type,l_debug_info_ptr))
		      { APL_GOBACK_FAIL }

	 	   if(APL_SUCCESS != DL_Mod_Posn(p_client,l_dl_deal_rstpmt_struct_h->p_instr_code,
						l_dl_deal_rstpmt_struct_h->p_loccode,l_dl_deal_rstpmt_struct_h->p_posnstatus_ind,
						'U',l_dl_deal_rstpmt_struct_h->p_dealcd[0],&l_dl_deal_rstpmt_struct_h->p_quantity,
						'I',l_block_type,l_debug_info_ptr))
		      { APL_GOBACK_FAIL }

			

         memset(l_dl_dealaudit_struct_hd,NULL,sizeof(DL_DEALAUDIT_STRUCT_H));

		   strcpy(l_dl_dealaudit_struct_hd->h_dl_client,p_client);
		   strcpy(l_dl_dealaudit_struct_hd->h_indentity_no,p_indentity_no);
		   strcpy(l_dl_dealaudit_struct_hd->h_trail_for,"T");
		   strcpy(l_dl_dealaudit_struct_hd->h_processdetail,p_intl_envdatastruct_h->processtion);
		   strcpy(l_dl_dealaudit_struct_hd->h_proc_usr,p_intl_envdatastruct_h->usr);
		   strcpy(l_dl_dealaudit_struct_hd->h_subprocess,APL_NULL_STRING);
		   strcpy(l_dl_dealaudit_struct_hd->h_fail_cd,l_dl_deal_rstpmt_struct_h->p_failreas_cd);
		   strcpy(l_dl_dealaudit_struct_hd->h_dlfromord,l_dl_deal_rstpmt_struct_h->p_dlfromord);

		   l_dl_dealaudit_struct_hd->h_qty =l_dl_deal_rstpmt_struct_h->p_quantity;

	 	   if(APL_SUCCESS != CR_Mod_CLHAudTrail(l_dl_dealaudit_struct_hd,l_debug_info_ptr))
						
		      { APL_GOBACK_FAIL }
         
        

         if (APL_FAILURE==EI_Mod_MQData(p_client,
                                        p_indentity_no,
                                        NULL,
                                        NULL,
                                        "B",
                                         l_debug_info_ptr))
             APL_GOBACK_FAIL 

			if(APL_SUCCESS != DL_Rtv_TrdChrVal(p_client,p_indentity_no,"origrefno",chr_l_h_origrefno,l_debug_info_ptr))

             APL_GOBACK_FAIL;

         if (strcmp(p_indentity_no,chr_l_h_origrefno) != 0)
            {
               if (APL_FAILURE==EI_Mod_MQData(p_client,
                                              chr_l_h_origrefno,
                                              NULL,
                                              NULL,
                                              "B",
                                               l_debug_info_ptr))
                  APL_GOBACK_FAIL
            }


		
		
		

		   if (strcmp(l_dl_deal_rstpmt_struct_h->p_orefretval,p_indentity_no) &&
				(l_dl_deal_rstpmt_struct_h->p_dlfromord[0] == 'N'))				
		      {
		        strcpy(l_dl_dealaudit_struct_hd->h_indentity_no,l_dl_deal_rstpmt_struct_h->p_orefretval);
	 	      	if(APL_SUCCESS != CR_Mod_CLHAudTrail(l_dl_dealaudit_struct_hd,l_debug_info_ptr))
							
		      		{ APL_GOBACK_FAIL }
			
			if(APL_SUCCESS != CR_Proc_MvToHisTrd(p_client,p_indentity_no,l_debug_info_ptr))
		      		{ APL_GOBACK_FAIL }
		      }		
                    }
	       else {if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_ACCESSSTAMP_CHGD, 
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                	APL_GOBACK_FAIL}

	   	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		    {APL_GOBACK_FAIL }

			}

	   	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		    {APL_GOBACK_FAIL }

			}

	   	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		    {APL_GOBACK_FAIL }

         
         strcpy(chr_mainfuncarea, "TRD_PMT_CHK");
         strcpy(chr_l_condid, "RU_REG_CHK");
         int_l_condexists = 0;

         if ( APL_SUCCESS != CO_Chk_CntryEnabled( chr_mainfuncarea,
                                                chr_l_condid,
                                                &int_l_condexists,
                                                l_debug_info_ptr ) )
			{
				APL_GOBACK_FAIL
			}
         if ( int_l_condexists > 0 )
         {
				if (CRUDBRstPmtFn(p_client,
										p_indentity_no,
										l_dl_deal_rstpmt_struct_h,
										chr_p_access_stamp,
										l_debug_info_ptr
										) == APL_FAILURE)
					{	APL_GOBACK_FAIL	}
         }
         

			}

	   	if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
		    {APL_GOBACK_FAIL }

			}
	       else {if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_DEAL_PARENT_CONF, 
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                	APL_GOBACK_FAIL}

	     if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
	        {APL_GOBACK_FAIL }
	     }

	  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
	     {APL_GOBACK_FAIL }
	}

        else {if(CO_InsertErr(
              		l_debug_info_ptr,
              		ERR_DEAL_MANIFLD_PRINTED, 
                      	APL_NULL_STRING,
                       	APL_NULL_STRING,
                       	APL_NULL_STRING,
                       	__LINE__,
                       	__FILE__
                       	) != APL_SUCCESS)
               	APL_GOBACK_FAIL}

      		}

    if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
       {APL_GOBACK_FAIL }

       }
	    else 
		 {
			CO_InsertErr( l_debug_info_ptr,
                       		ERR_ACCESSSTAMP_CHGD, 
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__);
		    APL_GOBACK_FAIL 
		 }
     }

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
	free(l_dl_deal_rstpmt_struct_h); 
	free (l_dl_dealaudit_struct_hd);
	free (l_dl_deal_oth_struct_ha_a);
   CO_PrnErr(*l_debug_info_ptr) ;
	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
	free(l_dl_deal_rstpmt_struct_h); 
	free (l_dl_dealaudit_struct_hd);
	free (l_dl_deal_oth_struct_ha_a);
	CO_PrnErr(*l_debug_info_ptr) ;
	return(APL_FAILURE);
	}
}

