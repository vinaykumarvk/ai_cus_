











#define PURE_C_SOURCE 
#include "CO_HostStructdef.h" 

int CR_Proc_InstrCdChg (DL_INSTRUMENTCHG_STRUCT2_H *l_dl_instrumentchg_struct2_ha, 
						INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
  char chr_l_sysdate_b[APL_DATE_LEN];
  char chr_l_listedflg[APL_FLAG_LENGTH];
  char chr_l_chgmaker[APL_USERID_LEN];

APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Entered Function CBCBInstrChgCdFn. Going for mandatory checks\n",
		NULL,p_intl_envdatastruct_h);
 }

  

  if (!strlen(l_dl_instrumentchg_struct2_ha->h_oldinstr_code)) {APL_DATA_MISSING("Old Instrode",APL_NULL_STRING,APL_NULL_STRING);}
  if (!strlen(l_dl_instrumentchg_struct2_ha->h_newinstr_code)) {APL_DATA_MISSING("New Instrode",APL_NULL_STRING,APL_NULL_STRING);}
  if (strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
  if (!strlen(l_dl_instrumentchg_struct2_ha->h_access_stamp)) {APL_DATA_MISSING("Access Stamp",APL_NULL_STRING,APL_NULL_STRING);}
  }



  if (!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_INPUT))
	{
	if (!strlen(l_dl_instrumentchg_struct2_ha->h_newinstr_isincode)) {APL_DATA_MISSING("New ISIN code",APL_NULL_STRING,APL_NULL_STRING);}
	if (!strlen(l_dl_instrumentchg_struct2_ha->h_listed_ind)) {APL_DATA_MISSING("Listed Flag",APL_NULL_STRING,APL_NULL_STRING);}
 	}

   

  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
        {
        APL_GOBACK_FAIL
        }



	if (strlen(l_dl_instrumentchg_struct2_ha->h_newinstr_isincode) <12)
	{
      if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_ISINCD_CANT_LESS_12CHAR,
          
          APL_NULL_STRING,
          APL_NULL_STRING,
          APL_NULL_STRING,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL
	}

	if (APL_FAILURE ==CO_Chk_InstrValid(l_dl_instrumentchg_struct2_ha->h_oldinstr_code,
											'Y','Y',
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											l_debug_info_ptr))
        {
        APL_GOBACK_FAIL
        }

   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
     	APL_GOBACK_FAIL
	   }

	if (APL_FAILURE ==CO_Chk_InstrValid(l_dl_instrumentchg_struct2_ha->h_newinstr_code,
											'N',
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											APL_NULL_STRING,
											l_debug_info_ptr))
        {
        APL_GOBACK_FAIL
        }

   if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
      {
     	APL_GOBACK_FAIL
	   }

	memset(chr_l_sysdate_b, APL_NULL_CHAR, APL_DATE_LEN);
	memset(chr_l_listedflg, APL_NULL_CHAR, APL_FLAG_LENGTH);
	memset(chr_l_chgmaker, APL_NULL_CHAR, APL_USERID_LEN);

   if ( APL_FAILURE == CR_Rtv_InstrChngDet(l_dl_instrumentchg_struct2_ha->h_oldinstr_code,
												  chr_l_sysdate_b,
												  chr_l_chgmaker,
												  chr_l_listedflg,
                                      l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }
 

  if(!strcmp(chr_l_listedflg,"Y"))
	{
   strcpy(l_dl_instrumentchg_struct2_ha->h_listed_ind,"Y");	
   }

   
  if((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))||
		(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE)))
	{
	if(!strlen(chr_l_chgmaker))
	  	{
	   if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_INSTR_NOTUNDERCHG,
          
          APL_NULL_STRING,
          APL_NULL_STRING,
          APL_NULL_STRING,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL	
	  	}
	}

   if(strcmp(chr_l_sysdate_b,l_dl_instrumentchg_struct2_ha->h_access_stamp))
	{
	   if (CO_InsertErr
         (l_debug_info_ptr,
          ERR_ACCESSSTAMP_CHGD,
          
          chr_l_sysdate_b,
          "User Access Stamp:",
          l_dl_instrumentchg_struct2_ha->h_access_stamp,
          __LINE__,
          __FILE__
         ) != APL_SUCCESS)
         APL_GOBACK_FAIL	
	}

  if((!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_RESET))||
		(!strcmp(p_intl_envdatastruct_h->h_mode,APL_FUNC_AUTHORISE)))
	{
   if ( APL_FAILURE == CR_Proc_InstrChngMkrChr(l_dl_instrumentchg_struct2_ha->h_oldinstr_code,
								  p_intl_envdatastruct_h->usr,
                          l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }
	}

 				
   if ( APL_FAILURE == CR_Mod_InstrChngDet(l_dl_instrumentchg_struct2_ha,
								  p_intl_envdatastruct_h,
                          l_debug_info_ptr))
      {
      APL_GOBACK_FAIL;
      }


  if (CO_ChkErr(*l_debug_info_ptr) ==APL_SUCCESS)
     	{
        APL_GOBACK_FAIL
   	}

  APL_GOBACK_SUCCESS
 
  RETURN_SUCCESS :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Successfully leaving CR_Proc_InstrCdChg\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_SUCCESS);
	}
  RETURN_FAILURE :
	{
APL_IF_DEBUG
 {
  CO_ProcMonitor(APL_OUT_FILE, "Leaving CR_Proc_InstrCdChg unsuccessfully\n",
		NULL,p_intl_envdatastruct_h);
 }

	return(APL_FAILURE);
	}
}

