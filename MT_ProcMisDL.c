












#define PURE_C_SOURCE

#include "CO_HostStructdef.h" 

int DL_Mod_MisTxn(DL_MISDEAL_STRUCT_H *l_dl_misdeal_struct_h, \
		char cmistxnident[17],\
		INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_b, \
		DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
   short l_send95r = 0;                                    
	short l_return = 0;
	int int_error_flag = APL_SUCCESS;
	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE, "Entered processtion CBUpdMisFN. \
			Mandatory validations will be carried out now\n",\
			NULL, p_intl_env_data_struct_h_b);
	}


	
	if (!strlen(l_dl_misdeal_struct_h->h_dl_client))
	{
		APL_DATA_MISSING("Account", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if ((!strlen(l_dl_misdeal_struct_h->h_indentity_no)) && (strcmp(p_intl_env_data_struct_h_b->h_mode,
					APL_FUNC_INPUT)))
	{
		APL_DATA_MISSING("Reference No.", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(l_dl_misdeal_struct_h->h_dealcd))
	{
		APL_DATA_MISSING("Trade Code", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(l_dl_misdeal_struct_h->h_setldt))
	{
		APL_DATA_MISSING("Settlement Date", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (l_dl_misdeal_struct_h->h_qty ==0)
	{
		APL_DATA_MISSING("Quantity", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if (!strlen(l_dl_misdeal_struct_h->h_instr_code))
	{
		APL_DATA_MISSING("Instrurity Code", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

	
	if((l_dl_misdeal_struct_h->h_amt ==0) && strlen(l_dl_misdeal_struct_h->h_dealcd) && \
		(!strcmp(l_dl_misdeal_struct_h->h_dealcd, "3") || !strcmp(l_dl_misdeal_struct_h->h_dealcd, "4") ||
			!strcmp(l_dl_misdeal_struct_h->h_dealcd, "5") || !strcmp(l_dl_misdeal_struct_h->h_dealcd, "6") ||
			!strcmp(l_dl_misdeal_struct_h->h_dealcd, "7") || !strcmp(l_dl_misdeal_struct_h->h_dealcd, "8")))
	{
		APL_DATA_MISSING("Counter Value", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}
                                          
    if (APL_FAILURE == CO_Chk_CntryEnabled(  "EOCMAINT",
                                          "SEND95R",
                                          &l_send95r,
                                          l_debug_info_ptr))
   {
      APL_GOBACK_FAIL
   }
   if (l_send95r)
      {
        printf("%s \n",l_dl_misdeal_struct_h->h_domcpclt_cd);
        printf("%s \n",l_dl_misdeal_struct_h->h_dsn_ident);
        fflush(stdout);
        if ((!strlen(l_dl_misdeal_struct_h->h_domcpclt_cd))&&(!strlen(l_dl_misdeal_struct_h->h_dsn_ident)))
            {
               APL_DATA_MISSING("Domestic CP Account", APL_NULL_STRING, APL_NULL_STRING);
               int_error_flag = APL_FAILURE; 
			   }
      }
   else
     {
	   
      if (!strlen(l_dl_misdeal_struct_h->h_domcpclt_cd))
       	{
		   APL_DATA_MISSING("Domestic CP Account", APL_NULL_STRING, APL_NULL_STRING);
		   int_error_flag = APL_FAILURE;
	      }
     }
	

	
	if ((!strlen(l_dl_misdeal_struct_h->h_access_stamp)) && (strcmp(p_intl_env_data_struct_h_b->h_mode,APL_FUNC_INPUT)))
	{
		APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, APL_NULL_STRING);
		int_error_flag = APL_FAILURE;
	}

   

	 
   if (!strcmp(l_dl_misdeal_struct_h->h_place_of_deal,"EXCHG"))
	{
		if (!strlen(l_dl_misdeal_struct_h->h_market_flag))
		{
			APL_DATA_MISSING("Market Indicator",APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
      }
   }

	
	if (!strcmp(l_dl_misdeal_struct_h->h_place_of_deal,"OTCO"))
	{
		if(!strlen(l_dl_misdeal_struct_h->h_description))
		{
			APL_DATA_MISSING("Narrative", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}
	}
   

		
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered Input Mode of CBUdpMisFn. Validating the Data Now.\n", NULL, p_intl_env_data_struct_h_b); 
		}
		

		if(APL_FAILURE == CO_Chk_AccValid(l_dl_misdeal_struct_h->h_dl_client,\
					'Y',\
					'C',\
					'C',\
					NULL,\
					'Y',\
					'N',\
					'N',\
					'N',\
					l_debug_info_ptr))
		{
			int_error_flag = APL_FAILURE;	
		}
		
      

		if(APL_FAILURE == CR_Chk_MsgAddr(l_dl_misdeal_struct_h->h_dl_client, l_debug_info_ptr))
		{
			int_error_flag = APL_FAILURE;
		}

		
    
      if ((l_send95r == 0)||(strlen(l_dl_misdeal_struct_h->h_domcpclt_cd)))         
         {
		      if(APL_FAILURE == CO_Chk_AccValid(l_dl_misdeal_struct_h->h_domcpclt_cd,\
					'Y',\
					'B',\
					NULL,\
					NULL,\
					'Y',\
					'N',\
					'N',\
					'N',\
					l_debug_info_ptr))
		           {
		           	int_error_flag = APL_FAILURE;	
		           }
        }
		
		if(strlen(l_dl_misdeal_struct_h->h_countclt))
		{

			if(APL_FAILURE == CO_Chk_AccValid(l_dl_misdeal_struct_h->h_countclt,
					'Y',
					'C',
					'C',
					NULL,
					'Y',
					'N',
					'N',
					'N',
					l_debug_info_ptr))
			{
				int_error_flag = APL_FAILURE;	
			}
		}

		

		if (strstr("1234",l_dl_misdeal_struct_h->h_dealcd) == NULL)
		{
			CO_InsertErr( l_debug_info_ptr,
					ERR_STATUS_TRANSTYP_INVALID,
					APL_NULL_STRING,
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
		}

		 
		if (l_dl_misdeal_struct_h->h_qty < 0 )               
		{
			CO_InsertErr( l_debug_info_ptr,
					ERR_VALUE_CANT_NEGATIVE,
					"Trade Quantity",
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

			int_error_flag = APL_FAILURE;
		}
		
			if (l_dl_misdeal_struct_h->h_amt < 0 )               
			{
				CO_InsertErr( l_debug_info_ptr,
					ERR_VALUE_CANT_NEGATIVE,
					"Counter Value of the Trade",
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

				int_error_flag = APL_FAILURE;
			}

		
		
			if (l_dl_misdeal_struct_h->h_pr < 0 )               
			{
				CO_InsertErr( l_debug_info_ptr,
					ERR_VALUE_CANT_NEGATIVE,
					"Instrurity Price",
					APL_NULL_STRING,
					APL_NULL_STRING,
					__LINE__,
					__FILE__);

				int_error_flag = APL_FAILURE;
			}

		

		if (APL_FAILURE == CO_Chk_InstrValid(l_dl_misdeal_struct_h->h_instr_code,
						'Y',
						'Y',
						'N',
						'N',
						NULL,
						NULL,
						l_debug_info_ptr))
		{
			int_error_flag = APL_FAILURE;
		}

	
	printf("\n The Send msg chr_flag :'%c': PACO :%s: Note :%s: \n", l_dl_misdeal_struct_h->h_send_msg_ind, l_dl_misdeal_struct_h->h_party_con, l_dl_misdeal_struct_h->h_info);
	if (l_dl_misdeal_struct_h->h_send_msg_ind != 'Y' && l_dl_misdeal_struct_h->h_send_msg_ind != 'N' )
		{
			printf("\n\n |error foun |%c| \n\n", l_dl_misdeal_struct_h->h_send_msg_ind);
			APL_DATA_MISSING("Send Msg Flag", APL_NULL_STRING, APL_NULL_STRING);
			int_error_flag = APL_FAILURE;
		}

  if (int_error_flag == APL_FAILURE)
	{
	APL_GOBACK_FAIL
	}

	if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered input h_mode of DL_Mod_MisTxn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}
		printf("\n now calling ****** \n");
		CR_Mod_MisTxnr(l_dl_misdeal_struct_h, cmistxnident, p_intl_env_data_struct_h_b, l_debug_info_ptr);
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	
	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_MODIFY))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered modify h_mode of DL_Mod_MisTxn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		CR_Mod_MisTxnr(l_dl_misdeal_struct_h, cmistxnident, p_intl_env_data_struct_h_b, l_debug_info_ptr);
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	
	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_DELETE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered delete h_mode of DL_Mod_MisTxn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		CR_Mod_MisTxnr(l_dl_misdeal_struct_h, cmistxnident, p_intl_env_data_struct_h_b, l_debug_info_ptr);
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	
	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, APL_FUNC_AUTHORISE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered authorise h_mode of DL_Mod_MisTxn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		
		
		if(!strcmp(l_dl_misdeal_struct_h->h_misdeal_status, STATUS_CANC_REVUAUTH) && l_dl_misdeal_struct_h->h_send_msg_ind == 'Y')
				{
					GBDbInsIMSGENT(MS_MSGNO_578R01, l_dl_misdeal_struct_h->h_indentity_no,
						l_dl_misdeal_struct_h->h_dl_client, 
						'Y', APL_NULL_STRING,
						l_debug_info_ptr);
				}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	   

		l_return = CR_Mod_MisTxnr(l_dl_misdeal_struct_h, cmistxnident, p_intl_env_data_struct_h_b, l_debug_info_ptr);
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}

		
		if(!strcmp(l_dl_misdeal_struct_h->h_misdeal_status, STATUS_AUTH) && l_dl_misdeal_struct_h->h_send_msg_ind == 'Y' )
		{
				printf("\n\n now calling GBDbInsIMSGENT ******* \n");
			if(strlen(l_dl_misdeal_struct_h->h_nameof_file)==0)                      
			{
			GBDbInsIMSGENT(MS_MSGNO_534N01, l_dl_misdeal_struct_h->h_indentity_no,
						l_dl_misdeal_struct_h->h_dl_client, 
						'Y', APL_NULL_STRING,
						l_debug_info_ptr);
			}
			else
			{
			l_return = GBDbInsIMSGENT("578N02", l_dl_misdeal_struct_h->h_indentity_no,    
						l_dl_misdeal_struct_h->h_dl_client, 
						'Y', APL_NULL_STRING,
						l_debug_info_ptr);
			
			}
		}
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	
	else if (!strcmp(p_intl_env_data_struct_h_b->h_mode, MS_RSND_MODE))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Entered msg resend h_mode of DL_Mod_MisTxn. Going for Updation \n", NULL, p_intl_env_data_struct_h_b);
		
		}

		CR_Mod_MisTxnr(l_dl_misdeal_struct_h, cmistxnident, p_intl_env_data_struct_h_b, l_debug_info_ptr);
		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
		
		if ( l_dl_misdeal_struct_h->h_send_msg_ind == 'Y' )
		{
		GBDbInsIMSGENT(MS_MSGNO_534N01, l_dl_misdeal_struct_h->h_indentity_no,
				l_dl_misdeal_struct_h->h_dl_client, 
				'Y', APL_NULL_STRING,
				l_debug_info_ptr);
		}

		if ( CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
			{
				APL_GOBACK_FAIL
			}
	}

	else
		{
		APL_GOBACK_FAIL
		}

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS :

		{

		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Success in DL_Mod_MisTxn. Quitting program.\n" , NULL, p_intl_env_data_struct_h_b);

			}
		return(APL_SUCCESS);
		}

	RETURN_FAILURE :

		{
		APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE, "Failed in CBUpdMisfn. Quitting Program. \n", NULL, p_intl_env_data_struct_h_b);
			}
		return(APL_FAILURE);
		}
}

