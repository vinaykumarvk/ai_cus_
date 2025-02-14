












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int CR_Proc_DLSetlRst (char *p_client,char *p_indentity_no,char *chr_p_action,char *chr_p_access_stamp,INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{

 

  char chr_p_prntconfdt[APL_DATE_LEN];
  char p_dt[APL_DATE_LEN];
  char chr_p_errcond_stx[3];
  char chr_p_errcond_oth[3];
  char chr_p_processregflg[APL_FLAG_LENGTH];

  char chr_p_msgno_a[6];

  char chr_l_buf[BUFFER_LEN];

  double p_retposn =0;

  short int_p_condexists = 0;

  int int_p_setlqty =0;
  int int_error_flag = APL_SUCCESS;
  int int_p_enuf = APL_SUCCESS;

  DL_DEAL_RSTSST_STRUCT_H *l_dl_deal_rstsst_struct_h;

  l_dl_deal_rstsst_struct_h = (DL_DEAL_RSTSST_STRUCT_H *)calloc(1,sizeof(DL_DEAL_RSTSST_STRUCT_H));



  strcpy(l_dl_deal_rstsst_struct_h->p_ora_rowid, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_maker, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_cltstmp_cmp, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_status_ind, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_status_reg, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_instrdate, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_moneydate, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_dealcd, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_isspotdl, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_instrconv_ind, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_updhispos_date, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_mod_hispos_ind, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_client, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_instr_code, APL_NULL_STRING);
  strcpy(l_dl_deal_rstsst_struct_h->p_indentity_no, APL_NULL_STRING);

  strcpy(p_dt, APL_NULL_STRING);

  strcpy(chr_p_errcond_stx , APL_NULL_STRING);
  strcpy(chr_p_errcond_oth , APL_NULL_STRING);
  strcpy(chr_p_processregflg , APL_NULL_STRING);
 
  
	memset(chr_p_msgno_a,APL_NULL_CHAR,6);

  l_dl_deal_rstsst_struct_h->p_recinto000 =0;
  l_dl_deal_rstsst_struct_h->p_pendregquantity =0;
  l_dl_deal_rstsst_struct_h->p_mcomplquantity =0;


  APL_IF_DEBUG
	{
	CO_ProcMonitor(APL_OUT_FILE, "Entered Function CR_Proc_DLSetlRst. Going for mandatory checks\n",NULL,p_intl_envdatastruct_h);
   }



	if (!strlen(p_client)) {APL_DATA_MISSING("Account",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}
  	if (!strlen(p_indentity_no)) {APL_DATA_MISSING("Reference Number",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 
  	if (!strlen(chr_p_action)) {APL_DATA_MISSING("Action",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 
  	if (!strlen(chr_p_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);
  		int_error_flag = APL_FAILURE;}                 



  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}
 





  strcpy(chr_p_errcond_stx,l_mt_core_sys_params_struct_h.op_oth_stx_error);
  strcpy(chr_p_errcond_oth,l_mt_core_sys_params_struct_h.op_oth_trd_error);
  strcpy(chr_p_processregflg ,l_mt_core_sys_params_struct_h.proc_reg_ind);



  if (*chr_p_action =='S')
     {
     if (APL_SUCCESS == DL_Chk_DLDet(p_client, p_indentity_no,
					'Y','Y','N','Y',APL_NULL_CHAR,
					'Y',APL_NULL_CHAR,APL_NULL_CHAR,
					l_debug_info_ptr))
       	{ 
    	if (APL_SUCCESS == DL_Rtv_DLSetlRst(p_client,p_indentity_no,l_dl_deal_rstsst_struct_h
					,l_debug_info_ptr))
	   {


		

		

		
				
			int_p_condexists = 0;		

		    if (APL_SUCCESS != CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET",
                             "RU_SCV_SPT_RST_NALLW",
                             &int_p_condexists,
                             l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}
					if (int_p_condexists > 0 ) 
             	{
			      	  if (APL_SUCCESS != DL_Chk_DLInstrRst(l_dl_deal_rstsst_struct_h->p_indentity_no,
																			 l_dl_deal_rstsst_struct_h->p_client,
        																	 l_dl_deal_rstsst_struct_h->p_instr_code,
																			 l_dl_deal_rstsst_struct_h->p_instrdate,
        																	 p_intl_envdatastruct_h,
        																	 l_debug_info_ptr))
        					{
               			 APL_GOBACK_FAIL
        					}
					 }
	  

      


     

	    if ((((l_dl_deal_rstsst_struct_h->p_ex_arena[0] == '1') && (!strcmp(chr_p_errcond_stx,">")))
		  || ((l_dl_deal_rstsst_struct_h->p_ex_arena[0] != '1') && (!strcmp(chr_p_errcond_oth,">"))))
 	          && (strlen(l_dl_deal_rstsst_struct_h->p_moneydate))
 	          && ((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DVP) 
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CD)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DCD)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))
		  {
	          if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_DEAL_EXECERR_GRTR_RST_NALLOW, 
				
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                  APL_GOBACK_FAIL

		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     			{APL_GOBACK_FAIL }
        }

	       if ((((l_dl_deal_rstsst_struct_h->p_ex_arena[0] == '1') && (!strcmp(chr_p_errcond_stx,"<>")))
		  || ((l_dl_deal_rstsst_struct_h->p_ex_arena[0] != '1') && (!strcmp(chr_p_errcond_oth,"<>"))))
 	          && ((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DVP) 
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CD)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DCD)
				 || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))
		  {
	          if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_DEAL_EXECERR_NEQUAL_RST_NALLOW, 
				
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                  APL_GOBACK_FAIL

		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     			{APL_GOBACK_FAIL }
		  }

     if (l_dl_deal_rstsst_struct_h->p_isspotdl[0] !='Y')
		  {
            if (l_dl_deal_rstsst_struct_h->p_instrconv_ind[0] !='Y')
			      {
			      if (APL_SUCCESS == CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET", 	
						      		"RECINTO000_GT_0",
						      		&int_p_condexists,
						      		l_debug_info_ptr)) 
				{
				if ((int_p_condexists ==0) 
 	          && ((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RF) 
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))
						
				{
				int_p_condexists = 0;
				if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,l_dl_deal_rstsst_struct_h->p_instr_code,
								l_dl_deal_rstsst_struct_h->p_loccode,
								l_dl_deal_rstsst_struct_h->p_status_ind,
							        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
				   		      && (p_retposn - l_dl_deal_rstsst_struct_h->p_quantity <0))
				   {
	         	    	   if(CO_InsertErr(
                    			l_debug_info_ptr,
                       			ERR_DEAL_NENUFPOSN_RST_NALLOW, 
					
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		__LINE__,
                        		__FILE__
                        		) != APL_SUCCESS)
                		   APL_GOBACK_FAIL
				   }
				 } 

				

 				else if (int_p_condexists >0) 
				 {
				 int_p_condexists = 0;
				 if (l_dl_deal_rstsst_struct_h->p_recinto000>0)
 				    {
				    if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,l_dl_deal_rstsst_struct_h->p_instr_code,
								l_dl_deal_rstsst_struct_h->p_loccode,"000",
							        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
				   		      && (p_retposn - l_dl_deal_rstsst_struct_h->p_recinto000<0))
				      {
	         	    	      if(CO_InsertErr(
                    			l_debug_info_ptr,
                       			ERR_DEAL_NENUFPOSN_RST_NALLOW, 
					
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		__LINE__,
                        		__FILE__
                        		) != APL_SUCCESS)
                		      APL_GOBACK_FAIL
				      }
				    }

				 

			         else if ((l_dl_deal_rstsst_struct_h->p_pendregquantity >0) || (l_dl_deal_rstsst_struct_h->p_mcomplquantity >0)) 	
				    {
				    int_p_setlqty =0;
				    int_p_setlqty = l_dl_deal_rstsst_struct_h->p_pendregquantity + l_dl_deal_rstsst_struct_h->p_mcomplquantity;
			      	    if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,
								l_dl_deal_rstsst_struct_h->p_instr_code, 
								l_dl_deal_rstsst_struct_h->p_loccode,
								"001",
							        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
				   		      && (p_retposn - int_p_setlqty <0))
					{
	         	    	      	if(CO_InsertErr(
                    				l_debug_info_ptr,
                       				ERR_DEAL_NENUFPOSN_RST_NALLOW, 
						
                        			APL_NULL_STRING,
                        			APL_NULL_STRING,
                        			APL_NULL_STRING,
                        			__LINE__,
                        			__FILE__
                        			) != APL_SUCCESS)
                		      	APL_GOBACK_FAIL
					}
				    }
				  } 
				}

			   if (chr_p_processregflg[0] =='Y' && 
				((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RF) 
			        || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))	
				{
				int_p_condexists =0;
			        if (APL_SUCCESS == CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET", 	
						      		"MCOMPL_AND_PENDREG",
						      		&int_p_condexists,
						      		l_debug_info_ptr)) 
			 	   {
				   

						  

					if (strlen(l_dl_deal_rstsst_struct_h->p_status_reg) && (int_p_condexists ==0) &&
						(l_dl_deal_rstsst_struct_h->p_mcomplquantity +l_dl_deal_rstsst_struct_h->p_pendregquantity  	
						!= l_dl_deal_rstsst_struct_h->p_quantity ))
						{
	         	    	      		if(CO_InsertErr(
                    					l_debug_info_ptr,
                       					ERR_DEAL_TXNINREG_RST_NALLOW, 
							
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				__LINE__,
                        				__FILE__
                        				) != APL_SUCCESS)
                		      		APL_GOBACK_FAIL
						}
				   }
				  if (int_p_condexists >0) 
				    {
				     if (strlen(l_dl_deal_rstsst_struct_h->p_status_reg) &&
					  (l_dl_deal_rstsst_struct_h->p_pendregquantity + 
					 l_dl_deal_rstsst_struct_h->p_mcomplquantity  +
					 l_dl_deal_rstsst_struct_h->p_recinto000 != 
					 l_dl_deal_rstsst_struct_h->p_quantity ))
						{
	         	    	      		if(CO_InsertErr(
                    					l_debug_info_ptr,
                       					ERR_DEAL_TXNINREG_RST_NALLOW, 
							
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				__LINE__,
                        				__FILE__
                        				) != APL_SUCCESS)
                		      		APL_GOBACK_FAIL
				      		}
				     }
				}
  				if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     					{APL_GOBACK_FAIL }

  APL_IF_DEBUG
	{
	CO_ProcMonitor(APL_OUT_FILE, "Checks successful. Calling DL_Proc_DLSetlRst\n",NULL,p_intl_envdatastruct_h);
   }

  				if (APL_SUCCESS == DL_Proc_DLSetlRst (l_dl_deal_rstsst_struct_h,
				  				chr_p_action,
				  				chr_p_access_stamp,
				  				p_intl_envdatastruct_h,
				  				l_debug_info_ptr))
					{APL_GOBACK_SUCCESS}

			      }
	         	    else {if(CO_InsertErr(
                    			l_debug_info_ptr,
                       			ERR_DEAL_INSTRCONV_RST_NALLOW, 
					
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		__LINE__,
                        		__FILE__
                        		) != APL_SUCCESS)
                		APL_GOBACK_FAIL}

			   }
	         	   else {if(CO_InsertErr(
                    			l_debug_info_ptr,
                       			ERR_DEAL_SPOTDEAL_RST_NALLOW, 
					
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		__LINE__,
                        		__FILE__
                        		) != APL_SUCCESS)
                		APL_GOBACK_FAIL}

         }  
      } 
   }
	  


  if (*chr_p_action =='M')
     {
     if (APL_SUCCESS == DL_Chk_DLDet(p_client, p_indentity_no,
					'Y','Y','N','Y',APL_NULL_CHAR,
					APL_NULL_CHAR,'Y',APL_NULL_CHAR,
					l_debug_info_ptr))
       	{ 
    	if (APL_SUCCESS == DL_Rtv_DLSetlRst(p_client,p_indentity_no,l_dl_deal_rstsst_struct_h
					,l_debug_info_ptr))
	   {

		

		

			int_p_condexists = 0;

			

		    if (APL_SUCCESS != CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET",
                             "RU_SCV_SPT_RST_NALLW",
                             &int_p_condexists,
                             l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}
					if (int_p_condexists > 0) 
             	{
			      	  if (APL_SUCCESS != DL_Chk_DLInstrRst(l_dl_deal_rstsst_struct_h->p_indentity_no,
  																	       l_dl_deal_rstsst_struct_h->p_client,
        																	 l_dl_deal_rstsst_struct_h->p_instr_code,
																			 l_dl_deal_rstsst_struct_h->p_instrdate,
        																	 p_intl_envdatastruct_h,
        																	 l_debug_info_ptr))
        					{
               			 APL_GOBACK_FAIL
        					}
					 }
	  

	

      


     

	   if ((((l_dl_deal_rstsst_struct_h->p_ex_arena[0] == '1') && (!strcmp(chr_p_errcond_stx,"<")))
		  || ((l_dl_deal_rstsst_struct_h->p_ex_arena[0] != '1') && (!strcmp(chr_p_errcond_oth,"<"))))
 	          && (strlen(l_dl_deal_rstsst_struct_h->p_instrdate)))
		      {
	          if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_DEAL_EXECERR_LESS_RST_NALLOW, 
				
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                  APL_GOBACK_FAIL
  		  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     			{APL_GOBACK_FAIL }

                 }

	      if ((((l_dl_deal_rstsst_struct_h->p_ex_arena[0] == '1') && (!strcmp(chr_p_errcond_stx,"<>")))
	         || ((l_dl_deal_rstsst_struct_h->p_ex_arena[0] != '1') && (!strcmp(chr_p_errcond_oth,"<>")))))
		 {
	         if(CO_InsertErr(
                    		l_debug_info_ptr,
                       		ERR_DEAL_EXECERR_NEQUAL_RST_NALLOW, 
				
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	APL_NULL_STRING,
                        	__LINE__,
                        	__FILE__
                        	) != APL_SUCCESS)
                APL_GOBACK_FAIL
  		if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     			{APL_GOBACK_FAIL }

		}
         if (l_dl_deal_rstsst_struct_h->p_isspotdl[0] !='Y')
			   {
			   if (chr_p_processregflg[0] =='Y' && 
				((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RF) 
			        || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
						|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))	
				{
				int_p_condexists =0;
			        if (APL_SUCCESS == CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET", 	
						      		"MCOMPL_AND_PENDREG",
						      		&int_p_condexists,
						      		l_debug_info_ptr)) 
			 	   {
				   

						  

					if (strlen(l_dl_deal_rstsst_struct_h->p_status_reg) && (int_p_condexists ==0) &&
						(l_dl_deal_rstsst_struct_h->p_mcomplquantity +l_dl_deal_rstsst_struct_h->p_pendregquantity  	
						!= l_dl_deal_rstsst_struct_h->p_quantity ))
						{
	         	    	      		if(CO_InsertErr(
                    					l_debug_info_ptr,
                       					ERR_DEAL_TXNINREG_RST_NALLOW, 
							
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				__LINE__,
                        				__FILE__
                        				) != APL_SUCCESS)
                		      		APL_GOBACK_FAIL
						}
				   }
				  if (int_p_condexists >0) 
				    {
				     if (l_dl_deal_rstsst_struct_h->p_pendregquantity + 
					 l_dl_deal_rstsst_struct_h->p_mcomplquantity  +
					 l_dl_deal_rstsst_struct_h->p_recinto000 != 
					 l_dl_deal_rstsst_struct_h->p_quantity )
						{
	         	    	      		if(CO_InsertErr(
                    					l_debug_info_ptr,
                       					ERR_DEAL_TXNINREG_RST_NALLOW, 
							
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				APL_NULL_STRING,
                        				__LINE__,
                        				__FILE__
                        				) != APL_SUCCESS)
                		      		APL_GOBACK_FAIL
				      		}
				     }
				 }
  				if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     					{APL_GOBACK_FAIL }

  APL_IF_DEBUG
	{
	CO_ProcMonitor(APL_OUT_FILE, "Checks successful. Calling DL_Proc_DLSetlRst\n",NULL,p_intl_envdatastruct_h);
   }

  				if (APL_SUCCESS == DL_Proc_DLSetlRst (l_dl_deal_rstsst_struct_h,
				  				chr_p_action,
				 				chr_p_access_stamp,
				  				p_intl_envdatastruct_h,
				  				l_debug_info_ptr))
					{APL_GOBACK_SUCCESS}

			   }
	         	   else {if(CO_InsertErr(
                    			l_debug_info_ptr,
                       			ERR_DEAL_SPOTDEAL_RST_NALLOW, 
					
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
   }
	  


  if (*chr_p_action =='B')
     {
     if (APL_SUCCESS == DL_Chk_DLDet(p_client, p_indentity_no,
					'Y','Y','N','Y',APL_NULL_CHAR,
					'Y','Y',APL_NULL_CHAR,
					l_debug_info_ptr))
       	{ 
    	if (APL_SUCCESS == DL_Rtv_DLSetlRst(p_client,p_indentity_no,l_dl_deal_rstsst_struct_h
					,l_debug_info_ptr))
	   {

		
		 if ((strcmp(p_intl_envdatastruct_h->h_mode,CHLD_RST_SETL_MODE) == 0) && (g_mt_commonsys_params_struct_h.ei_smi_ind[0] == 'Y'))
		 {
			if (APL_FAILURE == DL_Chk_DLSetlSCR(p_client,p_indentity_no,p_intl_envdatastruct_h,l_debug_info_ptr))
			{
				APL_GOBACK_FAIL
			}
		}
		

		

			int_p_condexists = 0;
			
		    if (APL_SUCCESS != CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET",
                             "RU_SCV_SPT_RST_NALLW",
                             &int_p_condexists,
                             l_debug_info_ptr))
				{
					APL_GOBACK_FAIL
				}
					if (int_p_condexists > 0)
             	{
			      	  if (APL_SUCCESS != DL_Chk_DLInstrRst(l_dl_deal_rstsst_struct_h->p_indentity_no,
  																	       l_dl_deal_rstsst_struct_h->p_client,
        																	 l_dl_deal_rstsst_struct_h->p_instr_code,
																			 l_dl_deal_rstsst_struct_h->p_instrdate,
        																	 p_intl_envdatastruct_h,
        																	 l_debug_info_ptr))
        					{
               			 APL_GOBACK_FAIL
        					}
				 	}
	  

	

      


     

	    if ((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DVP) 
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CD)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_DCD)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR))
		{
                if (l_dl_deal_rstsst_struct_h->p_instrconv_ind[0] !='Y')
		   {



		  
	    if ((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RF) 
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
				|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR))
		{
		   if (APL_SUCCESS == CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET", 	
				      		"RECINTO000_GT_0",
				      		&int_p_condexists,
				      		l_debug_info_ptr))
			{
			if (int_p_condexists ==0) 
			   {
			int_p_condexists = 0;
			if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,l_dl_deal_rstsst_struct_h->p_instr_code,
							l_dl_deal_rstsst_struct_h->p_loccode,
							l_dl_deal_rstsst_struct_h->p_status_ind,
						        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
			   		      && (p_retposn - l_dl_deal_rstsst_struct_h->p_quantity <0))
			   {
	             	   if(CO_InsertErr(
                 		l_debug_info_ptr,
                       		ERR_DEAL_NENUFPOSN_RST_NALLOW, 
				
                       		APL_NULL_STRING,
                       		APL_NULL_STRING,
                       		APL_NULL_STRING,
                       		__LINE__,
                       		__FILE__
                       		) != APL_SUCCESS)
                	   APL_GOBACK_FAIL
			   }
  			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     				{APL_GOBACK_FAIL }

			 } 

			

 			else if (int_p_condexists >0) 
			 {
			 int_p_condexists = 0;
			 if (l_dl_deal_rstsst_struct_h->p_recinto000>0)
 			    {
			    if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,l_dl_deal_rstsst_struct_h->p_instr_code,
							l_dl_deal_rstsst_struct_h->p_loccode,"000",
						        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
			   		      && (p_retposn - l_dl_deal_rstsst_struct_h->p_recinto000<0))
			      {
	             	      if(CO_InsertErr(
                 			l_debug_info_ptr,
                       			ERR_DEAL_NENUFPOSN_RST_NALLOW, 
					
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		APL_NULL_STRING,
                        		__LINE__,
                        		__FILE__
                        		) != APL_SUCCESS)
                		      APL_GOBACK_FAIL
			      }
  			      if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     					{APL_GOBACK_FAIL }

			    }

			 

		         else if ((l_dl_deal_rstsst_struct_h->p_pendregquantity >0) || (l_dl_deal_rstsst_struct_h->p_mcomplquantity >0)) 	
			    {
			    int_p_setlqty =0;
			    int_p_setlqty = l_dl_deal_rstsst_struct_h->p_pendregquantity + l_dl_deal_rstsst_struct_h->p_mcomplquantity;
		      	    if ((APL_SUCCESS == DL_Proc_PosCalc(p_client,
							l_dl_deal_rstsst_struct_h->p_instr_code, 
							l_dl_deal_rstsst_struct_h->p_loccode,
							"001",
						        p_dt,"SFK",&p_retposn,"FREE",l_debug_info_ptr))	
			   		      && (p_retposn - int_p_setlqty <0))
				{
	             	      	if(CO_InsertErr(
                 			l_debug_info_ptr,
                       			ERR_DEAL_NENUFPOSN_RST_NALLOW, 
					
                       			APL_NULL_STRING,
                       			APL_NULL_STRING,
                       			APL_NULL_STRING,
                       			__LINE__,
                       			__FILE__
                       			) != APL_SUCCESS)
                	      	APL_GOBACK_FAIL
				}
  		 	   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     				{APL_GOBACK_FAIL }

			    }
			  } 
			}
			} 

		   if (chr_p_processregflg[0] == 'Y' && 
			((l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RF) 
		        || (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RVP)
					|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_CR)
					|| (l_dl_deal_rstsst_struct_h->p_dealcd[0] == DEALCD_RCR)))	
			{
			int_p_condexists =0;
		        if (APL_SUCCESS == CO_Chk_CntryEnabled ("TRD_SETTLEMENT_RESET", 	
					      		"MCOMPL+PENDREG",
					      		&int_p_condexists,
					      		l_debug_info_ptr)) 
		 	   {
			   

					  

					if (strlen(l_dl_deal_rstsst_struct_h->p_status_reg) && (int_p_condexists ==0) &&
						(l_dl_deal_rstsst_struct_h->p_mcomplquantity +l_dl_deal_rstsst_struct_h->p_pendregquantity  	
						!= l_dl_deal_rstsst_struct_h->p_quantity ))
					{
	             	      		if(CO_InsertErr(
                 				l_debug_info_ptr,
                       				ERR_DEAL_TXNINREG_RST_NALLOW, 
						
                       				APL_NULL_STRING,
                       				APL_NULL_STRING,
                       				APL_NULL_STRING,
                       				__LINE__,
                       				__FILE__
                       				) != APL_SUCCESS)
                	      		APL_GOBACK_FAIL
					}
			   }
			  if (int_p_condexists >0) 
			    {
			     if (l_dl_deal_rstsst_struct_h->p_pendregquantity + 
				 l_dl_deal_rstsst_struct_h->p_mcomplquantity  +
				 l_dl_deal_rstsst_struct_h->p_recinto000 != 
				 l_dl_deal_rstsst_struct_h->p_quantity )
					{
	             	      		if(CO_InsertErr(
                 				l_debug_info_ptr,
                       				ERR_DEAL_TXNINREG_RST_NALLOW, 
						
                       				APL_NULL_STRING,
                       				APL_NULL_STRING,
                       				APL_NULL_STRING,
                       				__LINE__,
                       				__FILE__
                       				) != APL_SUCCESS)
                	      		APL_GOBACK_FAIL
			      		}
			     }
			}
  			if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     				{APL_GOBACK_FAIL }

  APL_IF_DEBUG
	{
	CO_ProcMonitor(APL_OUT_FILE, "Checks successful. Calling DL_Proc_DLSetlRst\n",NULL,p_intl_envdatastruct_h);
   }

  		if (APL_SUCCESS == DL_Proc_DLSetlRst (l_dl_deal_rstsst_struct_h,
		  				chr_p_action,
		  				chr_p_access_stamp,
		  				p_intl_envdatastruct_h,
		  				l_debug_info_ptr))
			{APL_GOBACK_SUCCESS}

	      }
	    else {if(CO_InsertErr(
         		l_debug_info_ptr,
                       	ERR_DEAL_INSTRCONV_RST_NALLOW, 
			
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
      else {if(CO_InsertErr(
               	l_debug_info_ptr,
                ERR_DEAL_FREEDEAL_RST_NALLOW, 
		
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
         }  
      } 
  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     {APL_GOBACK_FAIL }

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
	free(l_dl_deal_rstsst_struct_h); 
	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
	free(l_dl_deal_rstsst_struct_h); 
	return(APL_FAILURE);
	}
}

