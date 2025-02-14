

#define PURE_C_SOURCE
#include "IV_Control_A.h"
#include "CR_Common.h"


	static	int MT_Mod_BaseNoNew(	MS_BASENO_STRUCT_H			*p_ms_baseno_struct_h_a,
											INTL_ENV_DATA_STRUCT_H	*p_intlenv_data_struct_h,
											DEBUG_INFO_STRUCT_H			**l_debug_info_ptr);


int MT_Mod_BaseNo(	MS_BASENO_STRUCT_H			*p_ms_baseno_struct_h_a,
							INTL_ENV_DATA_STRUCT_H	*p_intlenv_data_struct_h,
							DEBUG_INFO_STRUCT_H			**l_debug_info_ptr)
{
	
	char chr_l_buf[BUFFER_LEN];
	FILE *recon;
	int	int_retstat =0;

	

	if (!strcmp(p_intlenv_data_struct_h->h_mode,APL_FUNC_INPUT))
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"\nInside MT_Mod_BaseNo, Mode is INPUT \n",NULL,NULL);
			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The Base Number passed to MT_Mod_BaseNo is %s\n",p_ms_baseno_struct_h_a->baseid);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The Address passed is %s\n",p_ms_baseno_struct_h_a->contact_details);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);


			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The swift_tlx_gcn passed is %c\n",p_ms_baseno_struct_h_a->swift_tlx_gcn);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		}

		if	(	APL_FAILURE == MT_Mod_BaseNoNew(	p_ms_baseno_struct_h_a,
														p_intlenv_data_struct_h,
														l_debug_info_ptr))
		{
				APL_GOBACK_FAIL
		}
	} 

			
	
	

	if (	(	!strcmp(p_intlenv_data_struct_h->h_mode,APL_FUNC_MODIFY)	)	)
	{
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"\nMode is MODIFY \n",NULL,NULL);
			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The access stamp passed is %s\n",p_ms_baseno_struct_h_a->access_stamp);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
		}

		if	(	APL_FAILURE == MT_Mod_BaseNoAlter(	p_ms_baseno_struct_h_a,
															p_intlenv_data_struct_h,
															l_debug_info_ptr))
		{
				APL_GOBACK_FAIL;
		}
	}
	
	

	APL_GOBACK_SUCCESS
	RETURN_SUCCESS  :
	
		 APL_IF_DEBUG
		 { 
			 CO_ProcMonitor(APL_OUT_FILE,"Exiting out of I_UpdbaseNo successfully",NULL,NULL);
		 }	
		return (APL_SUCCESS);
	
	RETURN_FAILURE  :
	
		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Exiting out of I_Updbaseno  unsuccessfully",NULL,NULL);
		}
		return (APL_FAILURE);
	
}	




	static	int MT_Mod_BaseNoNew(	MS_BASENO_STRUCT_H			*p_ms_baseno_struct_h_a,
											INTL_ENV_DATA_STRUCT_H	*p_intlenv_data_struct_h,
											DEBUG_INFO_STRUCT_H			**l_debug_info_ptr
										)
	{
		
		int int_retval =0;
		int int_retstat =0;
		char chr_l_buf[BUFFER_LEN];



		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE,"Entering MT_Mod_BaseNoNew\n",NULL,NULL);

		}

		memset(chr_l_buf,NULL,BUFFER_LEN);
		sprintf(chr_l_buf,"The Swftlx passed to MT_Mod_BaseNoNew is %c\n",p_ms_baseno_struct_h_a->swift_tlx_gcn);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		memset(chr_l_buf,NULL,BUFFER_LEN);
		sprintf(chr_l_buf,"The contact_details passed to MT_Mod_BaseNoNew is %s\n",p_ms_baseno_struct_h_a->contact_details);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		memset(chr_l_buf,NULL,BUFFER_LEN);
		sprintf(chr_l_buf,"The  baseid passed to MT_Mod_BaseNoNew is %s\n",p_ms_baseno_struct_h_a->baseid);
		CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

		

		if	(	APL_FAILURE == (MT_Chk_BaseNoMand(	p_ms_baseno_struct_h_a,
																	p_intlenv_data_struct_h,
																	l_debug_info_ptr)))

		{
				APL_GOBACK_FAIL
		}

		
		

		if ( APL_FAILURE == MT_Chk_SWFTlx(p_ms_baseno_struct_h_a,
													 l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;	
		}

		
		

		if (APL_FAILURE == MT_Chk_MsgAddr(p_ms_baseno_struct_h_a,l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}

		
		

	 APL_IF_DEBUG
	 {
			CO_ProcMonitor(APL_OUT_FILE,"\nAttempting to insert recoed ,checkingfor sql l_debuglist\n",NULL,NULL); 
	 }	


		if (APL_FAILURE == MT_Mod_BaseAdd(p_ms_baseno_struct_h_a,&int_retstat,l_debug_info_ptr))
			APL_GOBACK_FAIL	

		

		APL_GOBACK_SUCCESS;

		RETURN_SUCCESS :
		
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting MT_Mod_BaseNoNew successfully\n",NULL,NULL);
			}
		return APL_SUCCESS;

		RETURN_FAILURE :
		
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting MT_Mod_BaseNoNew unsuccessfully\n",NULL,NULL);
			}
			
		return APL_FAILURE;

	}	


	

	int MT_Mod_BaseNoAlter(	MS_BASENO_STRUCT_H			*p_ms_baseno_struct_h_a,
								INTL_ENV_DATA_STRUCT_H	*p_intlenv_data_struct_h,
								DEBUG_INFO_STRUCT_H			**l_debug_info_ptr
							)
	{
		

		char 			h_ora_rowid[APL_ROWID_LEN];
		char			h_access_stamp[APL_DATE_LEN];
		char 			chr_l_buf[BUFFER_LEN];
		int int_retval =0;


		 APL_IF_DEBUG
		 {
			CO_ProcMonitor(APL_OUT_FILE,"\nEntering MT_Mod_BaseNoAlter \n",NULL,NULL);
			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The Swftlx passed to MT_Mod_BaseNoNew is %c\n",p_ms_baseno_struct_h_a->swift_tlx_gcn);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The contact_details passed to MT_Mod_BaseNoNew is %s\n",p_ms_baseno_struct_h_a->contact_details);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);

			memset(chr_l_buf,NULL,BUFFER_LEN);
			sprintf(chr_l_buf,"The  baseid passed to MT_Mod_BaseNoNew is %s\n",p_ms_baseno_struct_h_a->baseid);
			CO_ProcMonitor(APL_OUT_FILE,chr_l_buf,NULL,NULL);
		 }

		
			
		if	(	APL_FAILURE == (MT_Chk_BaseNoMand(	p_ms_baseno_struct_h_a,
																	p_intlenv_data_struct_h,
																	l_debug_info_ptr)))
		{
				APL_GOBACK_FAIL
		}


		
		
		
		if (APL_FAILURE == MT_Chk_SWFTlx(p_ms_baseno_struct_h_a, l_debug_info_ptr ) )
		{

			APL_GOBACK_FAIL;
		}


		

		if (APL_FAILURE == MT_Chk_MsgAddr(p_ms_baseno_struct_h_a,l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL;
		}


		
		
		
		
		if (APL_FAILURE == MT_Mod_Base(p_ms_baseno_struct_h_a,&int_retval,l_debug_info_ptr) )
			APL_GOBACK_FAIL
	


		
	
		APL_GOBACK_SUCCESS
		RETURN_SUCCESS :
			 APL_IF_DEBUG
			 {
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting MT_Mod_BaseNoNew successfully\n",NULL,NULL);
			 }		
		return APL_SUCCESS;

		RETURN_FAILURE :
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting MT_Mod_BaseNoNew unsuccessfully\n",NULL,NULL);
			}
		return APL_FAILURE;

	}	





int MT_Chk_BaseNoMand(MS_BASENO_STRUCT_H 			*p_ms_baseno_struct_h_a,
								INTL_ENV_DATA_STRUCT_H 		*p_intlenv_data_struct_h,
								DEBUG_INFO_STRUCT_H				**l_debug_info_ptr)
{
	if (	!strlen(p_ms_baseno_struct_h_a->contact_details) )
		APL_DATA_MISSING("Address",APL_NULL_STRING,APL_NULL_STRING);
	

	if (	!strlen(p_ms_baseno_struct_h_a->baseid) )
		APL_DATA_MISSING("baseno",APL_NULL_STRING,APL_NULL_STRING);
		
		
	

	if (!strcmp(p_intlenv_data_struct_h->h_mode,APL_FUNC_MODIFY ) )
	{
		if (	!strlen(p_ms_baseno_struct_h_a->access_stamp) )
			APL_DATA_MISSING("Access_stamp",APL_NULL_STRING,APL_NULL_STRING); 

	}
 	  if (CO_ChkErr(*l_debug_info_ptr) == APL_SUCCESS)
		APL_GOBACK_FAIL

		APL_GOBACK_SUCCESS
		RETURN_SUCCESS  :
		
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting I_basenoMandDataChk successfully\n",NULL,NULL);
			}
			return (APL_SUCCESS);
		

		RETURN_FAILURE  :
		
		   APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting I_BaseMandDataChk unsuccessfully\n",NULL,NULL);
			}
		return (APL_FAILURE);
		
}




int MT_Chk_SWFTlx(MS_BASENO_STRUCT_H	*p_ms_baseno_struct_h_a,
						DEBUG_INFO_STRUCT_H	   **l_debug_info_ptr )

{
	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entered MT_Chk_SWFTlx processtion\n",NULL,NULL);
	}

	if (	(p_ms_baseno_struct_h_a->swift_tlx_gcn != 'S' ) &&
			(p_ms_baseno_struct_h_a->swift_tlx_gcn != 'T' ) &&
			(p_ms_baseno_struct_h_a->swift_tlx_gcn != 'C') &&
			(p_ms_baseno_struct_h_a->swift_tlx_gcn != 'F' ))
	{

	  CO_InsertErr(l_debug_info_ptr,55,APL_NULL_STRING,APL_NULL_STRING,
						  APL_NULL_STRING,__LINE__,__FILE__);	
	  APL_GOBACK_FAIL;
	}

	APL_GOBACK_SUCCESS;

	
	RETURN_SUCCESS:
	{
		CO_ProcMonitor(APL_OUT_FILE,"Exiting out of MT_Chk_SWFTlx successfully\n",NULL,NULL);
	}
	return APL_SUCCESS;

	RETURN_FAILURE:
	{
		CO_ProcMonitor(APL_OUT_FILE,"exiting out of MT_Chk_SWFTlx unsuccessfully\n",NULL,NULL);
	}
	return APL_FAILURE;
}




int MT_Chk_MsgAddr(MS_BASENO_STRUCT_H	*p_ms_baseno_struct_h_a,
										DEBUG_INFO_STRUCT_H	**l_debug_info_ptr)
{
int	int_retstat =0;
char	h_swift_tlx_gcn = APL_NULL_CHAR;
char	h_contactinfo[15];

	APL_IF_DEBUG
	{
		CO_ProcMonitor(APL_OUT_FILE,"Entered I_ValSwftlxAddCmsgaddressFn processtion\n",NULL,NULL);
	}

		h_swift_tlx_gcn = p_ms_baseno_struct_h_a->swift_tlx_gcn;
		strcpy(h_contactinfo,p_ms_baseno_struct_h_a->contact_details);

		if (h_swift_tlx_gcn == 'S' )
		{
			if (APL_FAILURE == MS_Rtv_SWFMsgAddr(h_swift_tlx_gcn,h_contactinfo,
																  &int_retstat,l_debug_info_ptr ) )
			{


				APL_GOBACK_FAIL;

			}
		}
		
		if (h_swift_tlx_gcn == 'T' )
		{
			if (APL_FAILURE == MS_Rtv_TelxMsgAddr(h_swift_tlx_gcn,h_contactinfo,
																 		&int_retstat,l_debug_info_ptr ) )
			{


				APL_GOBACK_FAIL;

			}
		}
		if (h_swift_tlx_gcn == 'C' )
		{
			if (APL_FAILURE == MS_Rtv_GCNMsgAddr(h_swift_tlx_gcn,h_contactinfo,
																  &int_retstat,l_debug_info_ptr ) )
			{
				APL_GOBACK_FAIL;

			}
		}

		if (h_swift_tlx_gcn =='F' )
		{
			if (APL_FAILURE == MS_Rtv_FaxMsgAddr(h_swift_tlx_gcn,h_contactinfo,
																  &int_retstat,l_debug_info_ptr ) )
			{

				APL_GOBACK_FAIL;

			}
		}
		APL_GOBACK_SUCCESS

		


		RETURN_SUCCESS  :
		
			APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting I_ValSWFTLXADDCMSG successfully\n",NULL,NULL);
			}
			return (APL_SUCCESS);
		

		RETURN_FAILURE  :
		
		   APL_IF_DEBUG
			{
				CO_ProcMonitor(APL_OUT_FILE,"\nExiting I_ValSWFTLXADDCMSG unsuccessfully\n",NULL,NULL);
			}
		return (APL_FAILURE);

} 



int MT_Prnt_ReconRpt( 	FILE				*reconrpt, 
										int 				*count,
										char 				*p_swftlx,
										char 				*p_address,
										char 				*p_baseno)
{

	fprintf(reconrpt,"%3s%s%6s"," ",p_baseno," ");
	fprintf(reconrpt,"%s%9s",p_swftlx," "); //AIX -Warnings Removal
	fprintf(reconrpt,"%s\n",p_address);

	return (APL_SUCCESS); //AIX -Warnings Removal
}
	
	






