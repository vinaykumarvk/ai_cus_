




#include "stdio_64.h"
#include <string.h>
#include <stdlib.h>

#define PURE_C_SOURCE

#include "IV_Control_A.h"



int IV_AccMnt(const IV_CLIENT_STRUCT *p_iv_client_struct,const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
	      DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	int IV_ChkValBIAccDigits(const char *chr_l_blacc, int *int_l_retstat, 
			      DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Rtv_IVACC(IV_CLIENT_STRUCT *l_iv_client_struct, int *int_l_retstat, 
				DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVACCLock(IV_CLIENT_STRUCT *l_iv_client_struct, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVACCNew(const IV_CLIENT_STRUCT *l_iv_client_struct, 
				const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVACCChg(const IV_CLIENT_STRUCT *l_iv_client_struct, 
				const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_usermode;
	int int_l_retstat = 0;
	IV_CLIENT_STRUCT l_iv_client_struct = *p_iv_client_struct, l_iv_client_struct_old;
	short int_l_cond_exists     = 0;
	short l_ccy_ibbsnoval = 0;
	short l_ibbs_10digits   = 0;
	short l_taxCondExists   = 0;

	

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("User Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE) )
	{
		chr_l_usermode = 'A';
	}

	memset(l_iv_client_struct_old.comm_a, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.tax_acc, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.payacc_a, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_b, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_c, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_d, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_e, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_f, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_g, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_h, APL_NULL_CHAR, APL_CLIENT_LENGTH);
	memset(l_iv_client_struct_old.comm_i, APL_NULL_CHAR, APL_CLIENT_LENGTH);

	memset(l_iv_client_struct_old.maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_client_struct_old.maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_client_struct_old.checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_iv_client_struct_old.checker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_iv_client_struct_old.access_stamp, APL_NULL_CHAR, APL_DATE_LEN);

	if(CO_Chk_CntryEnabled("ACC_MAINT",
                        "CCY_IBBSCODE_NO_VAL",
                        &l_ccy_ibbsnoval,
                        l_debug_info_ptr)==APL_FAILURE)
   {
   	APL_GOBACK_FAIL
   }
	if(CO_Chk_CntryEnabled("ACC_MAINT",
                        "IBBSACC_10_DIGITS",
                        &l_ibbs_10digits,
                        l_debug_info_ptr)==APL_FAILURE)
   {
   	APL_GOBACK_FAIL
   }

   
   if(APL_FAILURE == CO_Chk_CntryEnabled("BILL_ACC_ENTRIES",
                                       "FLEXCUBE_CASHACC",  
                                        &l_taxCondExists,
                                        l_debug_info_ptr))
   {
        APL_GOBACK_FAIL
   }
	
	
	if (l_taxCondExists)
		l_ccy_ibbsnoval=1; 

	int_l_retstat = 0;

	if ( chr_l_usermode == 'I' )
	{
		if ( APL_FAILURE == IV_Rtv_IVACC(&l_iv_client_struct_old, &int_l_retstat, 
						 l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_COLUMN_NULL_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_EXISTS, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}
		else
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
	else
	{
		if ( !strlen(l_iv_client_struct.access_stamp) )
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					  APL_NULL_STRING)

			APL_GOBACK_FAIL
		}

		strcpy(l_iv_client_struct_old.access_stamp, l_iv_client_struct.access_stamp);

		if ( APL_FAILURE == IV_Mod_IVACCLock(&l_iv_client_struct_old, &int_l_retstat, 
						  l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_FIRST, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	} 

	

	
	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') ) 
	{
		if ( !strlen(l_iv_client_struct.comm_a) )
		{
			APL_DATA_MISSING("Comm. Acc. 1", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}
		else if(l_ibbs_10digits > 0 && !l_taxCondExists )
		{
			if ( strlen(l_iv_client_struct.comm_a) != (APL_CLIENT_LENGTH-1)  )  
         {
         	CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
            	             l_iv_client_struct.comm_a, APL_NULL_STRING,
               	          APL_NULL_STRING, __LINE__,
                  	       __FILE__);
         }
		}

		if(l_ccy_ibbsnoval == 0)
		{
			int_l_retstat = 0;

			IV_ChkValBIAccDigits(l_iv_client_struct.comm_a, &int_l_retstat, 
					  	  l_debug_info_ptr);
		}

		int_l_cond_exists = 0; 
	   if(CO_Chk_CntryEnabled("BLACC_MNT",
		  						  "ACPAY1_NMAND",
		   					  &int_l_cond_exists,
								  l_debug_info_ptr)==APL_FAILURE)
		  		APL_GOBACK_FAIL

		if ( (!strlen(l_iv_client_struct.payacc_a)) && (int_l_cond_exists == 0) ) 
		{
			APL_DATA_MISSING("Pay. Acc. 1", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		int_l_cond_exists = 0;
	   if(CO_Chk_CntryEnabled("BLACC_MNT",
		  						  "ACTAX_NMAND",
		   					  &int_l_cond_exists,
								  l_debug_info_ptr)==APL_FAILURE)
		{
		  		APL_GOBACK_FAIL
		}
		if(int_l_cond_exists == 0)
		{
			if  ( !strlen(l_iv_client_struct.tax_acc) )
			{
				APL_DATA_MISSING("Tax Acc.", APL_NULL_STRING, 
						  APL_NULL_STRING)
			}
			else if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.tax_acc) != (APL_CLIENT_LENGTH-1)  )
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
										 l_iv_client_struct.tax_acc, APL_NULL_STRING,
										 APL_NULL_STRING, __LINE__,
										 __FILE__);
				}
			}

			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.tax_acc, &int_l_retstat, 
						  l_debug_info_ptr);
			}
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( strlen(l_iv_client_struct.comm_b) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
		
				if ( strlen(l_iv_client_struct.comm_b) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_b, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_b, &int_l_retstat, 
							  l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_c) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
	
				if ( strlen(l_iv_client_struct.comm_c) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
					       l_iv_client_struct.comm_c, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__,
					       __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_c, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_d) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
	
				if ( strlen(l_iv_client_struct.comm_d) !=(APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
					       l_iv_client_struct.comm_d, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__,
					       __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_d, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_e) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_e) != (APL_CLIENT_LENGTH-1))	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_e, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_e, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_f) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_f) !=(APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_f, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}

			}

         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_f, &int_l_retstat, 
				  	  l_debug_info_ptr);
			}
		}


		if ( strlen(l_iv_client_struct.comm_g) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_g) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_g, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_g, &int_l_retstat, 
				  	     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_h) )
		{
			if (l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_h) !=  (APL_CLIENT_LENGTH-1))	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_h, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_h, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_i) )
		{
			if (l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_i) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_i, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_i, &int_l_retstat, 
				   	  l_debug_info_ptr);
			}
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

	} 

	if ( chr_l_usermode == 'I' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVACCNew(&l_iv_client_struct, p_intl_envdatastruct_h, 
						 &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else
	{
		if ( chr_l_usermode == 'A' )
		{
			if ( strcmp(l_iv_client_struct_old.checker, " ") )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_AUTHORIZED, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			if ( !strcmp(l_iv_client_struct_old.maker, p_intl_envdatastruct_h->usr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVACCChg(&l_iv_client_struct, p_intl_envdatastruct_h, 
						 &int_l_retstat, l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	} 

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_AccMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_AccMnt().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



int IV_ChkValBIAccDigits(const char *p_blclt, int *int_p_retstat, 
		      DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	

	char chr_l_blacc[APL_CLIENT_LENGTH];

	memset(chr_l_blacc, APL_NULL_CHAR, APL_CLIENT_LENGTH);

	chr_l_blacc[0] = p_blclt[6];
	chr_l_blacc[1] = p_blclt[7];
	chr_l_blacc[2] = p_blclt[8];
	chr_l_blacc[3] = '\0';

	if ( strcmp(chr_l_blacc, "000") )
	{
		*int_p_retstat = IV_CRITCAL_ERROR_IND;

		CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_NOT_LOCCALCCY, 
			       (char *)p_blclt, APL_NULL_STRING, 
			       APL_NULL_STRING, __LINE__, __FILE__);//Changes done for AIX Migration

		APL_GOBACK_FAIL
	}

	*int_p_retstat = IV_SUCCESS;

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_ChkValBIAccDigits().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_ChkValBIAccDigits().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}



/********** Vedavati HDFCIV_002 ***************/
int IV_AccMntGL(const IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h,const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
	      DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
	
	extern int MT_UpdIV_CLIENTGL(IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h, int *int_l_retstat, 
				DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCLIENTGLLock(IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h, int *int_l_retstat, 
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCLIENTGLNew(const IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h, 
				const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	extern int IV_Mod_IVCLIENTGLChg(const IV_CLIENTGL_STRUCT_H *p_iv_clientgl_struct_h, 
				const INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h, 
				int *int_l_retstat, DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

	

	char chr_l_usermode;
	int int_l_retstat = 0;
	IV_CLIENTGL_STRUCT_H l_iv_clientgl_struct = *p_iv_clientgl_struct_h;
	IV_CLIENTGL_STRUCT_H l_ivclientgl_struct_old;
	short int_l_cond_exists     = 0;
	short l_ccy_ibbsnoval = 0;
	short l_ibbs_10digits   = 0;
	short l_taxCondExists   = 0;

	

	if ( !strlen(p_intl_envdatastruct_h->usr) )
	{
		APL_DATA_MISSING("Userid", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( !strlen(p_intl_envdatastruct_h->h_mode) )
	{
		APL_DATA_MISSING("User Mode", APL_NULL_STRING, APL_NULL_STRING)
	}

	if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
	{
		APL_GOBACK_FAIL
	}

	if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_INPUT) )
	{
		chr_l_usermode = 'I';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_MODIFY) )
	{
		chr_l_usermode = 'M';
	}
	else if ( !strcmp(p_intl_envdatastruct_h->h_mode, APL_FUNC_AUTHORISE) )
	{
		chr_l_usermode = 'A';
	}
        /* Bageshri -- HDFC Log 97 */
	memset(l_ivclientgl_struct_old.h_routac_a, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_routac_b, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_custsus, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_nseclh, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_bseclh, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_nsesetac, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_bsesetac, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_rtgssetac, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_fortrt, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_cmsrt, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_nsrsetac, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_brok_pay, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_stt_pay, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_tds_pay, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_tds_rec, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	
	memset(l_ivclientgl_struct_old.h_maker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_ivclientgl_struct_old.h_maker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_ivclientgl_struct_old.h_checker, APL_NULL_CHAR, APL_USERID_LEN);
	memset(l_ivclientgl_struct_old.h_checker_dt, APL_NULL_CHAR, APL_DATE_LEN);
	memset(l_ivclientgl_struct_old.h_access_stamp, APL_NULL_CHAR, APL_DATE_LEN);

	memset(l_ivclientgl_struct_old.h_payacc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_payacc1, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_casus, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_toleracc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_recacc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL);
	memset(l_ivclientgl_struct_old.h_taxacc, APL_NULL_CHAR, APL_CLIENT_LENGTH_GL); /* TAXACCOUNT added by chitrlekha for tax deduction KB_9306 */
    
        /***********************************/

	if(CO_Chk_CntryEnabled("ACC_MAINT",
                        "CCY_IBBSCODE_NO_VAL",
                        &l_ccy_ibbsnoval,
                        l_debug_info_ptr)==APL_FAILURE)
   {
   	APL_GOBACK_FAIL
   }
	if(CO_Chk_CntryEnabled("ACC_MAINT",
                        "IBBSACC_10_DIGITS",
                        &l_ibbs_10digits,
                        l_debug_info_ptr)==APL_FAILURE)
   {
   	APL_GOBACK_FAIL
   }

   
   if(APL_FAILURE == CO_Chk_CntryEnabled("BILL_ACC_ENTRIES",
                                       "FLEXCUBE_CASHACC",  
                                        &l_taxCondExists,
                                        l_debug_info_ptr))
   {
        APL_GOBACK_FAIL
   }
	
	
	if (l_taxCondExists)
		l_ccy_ibbsnoval=1; 

	int_l_retstat = 0;

	if ( chr_l_usermode == 'I' )
	{
		if ( APL_FAILURE == MT_UpdIV_CLIENTGL(&l_ivclientgl_struct_old, &int_l_retstat, 
						 l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_COLUMN_NULL_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_EXISTS, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}
		else
		{
			CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_EXISTS, 
				       APL_NULL_STRING, APL_NULL_STRING, 
				       APL_NULL_STRING, __LINE__, __FILE__);

			APL_GOBACK_FAIL
		}
	}
	else
	{
		if ( !strlen(l_iv_clientgl_struct.h_access_stamp) )
		{
			APL_DATA_MISSING("Access Stamp", APL_NULL_STRING, 
					  APL_NULL_STRING)

			APL_GOBACK_FAIL
		}

		strcpy(l_ivclientgl_struct_old.h_access_stamp, l_iv_clientgl_struct.h_access_stamp);

		if ( APL_FAILURE == IV_Mod_IVCLIENTGLLock(&l_ivclientgl_struct_old, &int_l_retstat, 
						  l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_FIRST, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	} 

	

/*	
	if ( (chr_l_usermode == 'I') || (chr_l_usermode == 'M') ) 
	{
		if ( !strlen(l_iv_client_struct.comm_a) )
		{
			APL_DATA_MISSING("Comm. Acc. 1", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}
		else if(l_ibbs_10digits > 0 && !l_taxCondExists )
		{
			if ( strlen(l_iv_client_struct.comm_a) != (APL_CLIENT_LENGTH-1)  )  
         {
         	CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
            	             l_iv_client_struct.comm_a, APL_NULL_STRING,
               	          APL_NULL_STRING, __LINE__,
                  	       __FILE__);
         }
		}

		if(l_ccy_ibbsnoval == 0)
		{
			int_l_retstat = 0;

			IV_ChkValBIAccDigits(l_iv_client_struct.comm_a, &int_l_retstat, 
					  	  l_debug_info_ptr);
		}

		int_l_cond_exists = 0; 
	   if(CO_Chk_CntryEnabled("BLACC_MNT",
		  						  "ACPAY1_NMAND",
		   					  &int_l_cond_exists,
								  l_debug_info_ptr)==APL_FAILURE)
		  		APL_GOBACK_FAIL

		if ( (!strlen(l_iv_client_struct.payacc_a)) && (int_l_cond_exists == 0) ) 
		{
			APL_DATA_MISSING("Pay. Acc. 1", APL_NULL_STRING, 
					  APL_NULL_STRING)
		}

		int_l_cond_exists = 0;
	   if(CO_Chk_CntryEnabled("BLACC_MNT",
		  						  "ACTAX_NMAND",
		   					  &int_l_cond_exists,
								  l_debug_info_ptr)==APL_FAILURE)
		{
		  		APL_GOBACK_FAIL
		}
		if(int_l_cond_exists == 0)
		{
			if  ( !strlen(l_iv_client_struct.tax_acc) )
			{
				APL_DATA_MISSING("Tax Acc.", APL_NULL_STRING, 
						  APL_NULL_STRING)
			}
			else if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.tax_acc) != (APL_CLIENT_LENGTH-1)  )
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
										 l_iv_client_struct.tax_acc, APL_NULL_STRING,
										 APL_NULL_STRING, __LINE__,
										 __FILE__);
				}
			}

			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.tax_acc, &int_l_retstat, 
						  l_debug_info_ptr);
			}
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

		if ( strlen(l_iv_client_struct.comm_b) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
		
				if ( strlen(l_iv_client_struct.comm_b) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_b, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_b, &int_l_retstat, 
							  l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_c) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
	
				if ( strlen(l_iv_client_struct.comm_c) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
					       l_iv_client_struct.comm_c, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__,
					       __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_c, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_d) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
	
				if ( strlen(l_iv_client_struct.comm_d) !=(APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
					       l_iv_client_struct.comm_d, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__,
					       __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
			{
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_d, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_e) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_e) != (APL_CLIENT_LENGTH-1))	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_e, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_e, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_f) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_f) !=(APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_f, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}

			}

         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_f, &int_l_retstat, 
				  	  l_debug_info_ptr);
			}
		}


		if ( strlen(l_iv_client_struct.comm_g) )
		{
			if(l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_g) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_g, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {
				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_g, &int_l_retstat, 
				  	     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_h) )
		{
			if (l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_h) !=  (APL_CLIENT_LENGTH-1))	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_h, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
			if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_h, &int_l_retstat, 
					     l_debug_info_ptr);
			}
		}

		if ( strlen(l_iv_client_struct.comm_i) )
		{
			if (l_ibbs_10digits > 0  && !l_taxCondExists )
			{
				if ( strlen(l_iv_client_struct.comm_i) != (APL_CLIENT_LENGTH-1) )	
				{
					CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_LEN_10DIGITS,
						       l_iv_client_struct.comm_i, APL_NULL_STRING,
					   	    APL_NULL_STRING, __LINE__,
					      	 __FILE__);

					APL_GOBACK_FAIL
				}
			}
         if(l_ccy_ibbsnoval == 0)
         {

				int_l_retstat = 0;

				IV_ChkValBIAccDigits(l_iv_client_struct.comm_i, &int_l_retstat, 
				   	  l_debug_info_ptr);
			}
		}

		if ( APL_SUCCESS == CO_ChkErr(*l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}

	} 
*/
	if ( chr_l_usermode == 'I' )
	{
		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVCLIENTGLNew(&l_iv_clientgl_struct, p_intl_envdatastruct_h, 
						 &int_l_retstat, l_debug_info_ptr) )
		{
			APL_GOBACK_FAIL
		}
	}
	else
	{
		if ( chr_l_usermode == 'A' )
		{
			if ( strcmp(l_ivclientgl_struct_old.h_checker, " ") )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_BILLACC_AUTHORIZED, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}

			if ( !strcmp(l_ivclientgl_struct_old.h_maker, p_intl_envdatastruct_h->usr) )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_MAKER_CHECKER_SAME, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

		int_l_retstat = 0;

		if ( APL_FAILURE == IV_Mod_IVCLIENTGLChg(&l_iv_clientgl_struct, p_intl_envdatastruct_h, 
						 &int_l_retstat, l_debug_info_ptr) )
		{
			if ( int_l_retstat == IV_CRITCAL_ERROR_IND )
			{
				APL_GOBACK_FAIL
			}
			else if ( int_l_retstat == IV_NO_DATA_FOUND_ERR )
			{
				CO_InsertErr(l_debug_info_ptr, ERR_ACCESSSTAMP_CHGD, 
					       APL_NULL_STRING, APL_NULL_STRING,
					       APL_NULL_STRING, __LINE__, 
					       __FILE__);

				APL_GOBACK_FAIL
			}
		}

	} 

	APL_GOBACK_SUCCESS

	RETURN_SUCCESS:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting successfully out of \
IV_AccMntGL().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_SUCCESS;

	RETURN_FAILURE:

		APL_IF_DEBUG
		{
			CO_ProcMonitor(APL_OUT_FILE, "Exiting unsuccessfully out of\
IV_AccMntGL().\n", (DEBUG_INFO_STRUCT_H **)NULL, (INTL_ENV_DATA_STRUCT_H *)NULL);
		}

		return APL_FAILURE;
}
/*******************************************************/
