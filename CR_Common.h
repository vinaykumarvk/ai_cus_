/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to 
 *    Polaris Software Lab Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or 
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
/*********************************************************************
 *
 * Module Name         : MASTERS MAINTAINANCE	
 *
 * File Name           : CR_Common.h
 *
 * Description         : Contains definitions related to Masters	
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description                                RFS NO.
 * ---------   --------	 ---------------  ---------------------------                          ---------
 *18/11/2005   1.1           Sonali        Changed signature for CO_Upd_AudLog_Chk_SysOnline   HDFCGN_001					
 *
 *********************************************************************/












 
#ifndef ROUTINES_HEADER_INCLUDED
#define ROUTINES_HEADER_INCLUDED


#include "Intellect_Interface.h"
#include "Intellect_Common.h"
#include "Intellect_Error.h"


#define SEQ_NAME_LEN				   20	
#define SEQ_ATTR_LEN					20	
#define RECYCLE_YES					'Y'
#define RECYCLE_NO					'N'
#define RECYCLE_EOD					'D'
#define RECYCLE_EOM					'M'
#define RECYCLE_EOY					'Z'

typedef struct 
{
	char	sequencename[SEQ_NAME_LEN+1];
	long	last_usednum;
	char	recycle_ind;
	int	seq_stepby;
	long	seq_start;
	long	last_seqnum;
	char	seq_attrb_a[SEQ_ATTR_LEN+1];
	char	seq_attrb_b[SEQ_ATTR_LEN+1];
	char	seq_attrb_c[SEQ_ATTR_LEN+1];
}PRO_GSEQNUM_STRUCT_H;

typedef struct 
{
	short		sequencename_ind;
	short		last_used_no_flag;
	short		recycle_ind;
	short		step_by_flag;
	short		start_at_flag;
	short		last_number_flag;
	short		sequence_attr1_ind;
	short		sequence_attr2_ind;
	short		sequence_attr3_ind;
}PRO_GSEQNUM_STRUCT_I;




extern	int	CO_ChkErr(DEBUG_INFO_STRUCT_H	*l_debug_infolist);
extern	void	CO_PrnErr(DEBUG_INFO_STRUCT_H	*l_debug_infolist);
extern	void	CO_OkWarning(DEBUG_INFO_STRUCT_H	*l_debug_infolist);
extern	int CO_InsertErr(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file
);
extern	int CO_InsertWarning(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file
);
extern	int	CO_ChkFatalErr(DEBUG_INFO_STRUCT_H *l_debug_info_ptr);
extern	int	CO_InsertMsg(DEBUG_INFO_STRUCT_H	*l_debug_infolist);
extern	int	CO_FreeErrLst(DEBUG_INFO_STRUCT_H **p_errorList);



extern	int	CO_RtvSysDt(
						char				*chr_p_sys_date,
						DEBUG_INFO_STRUCT_H	**l_debug_info_ptr
						);

extern	int	CO_RtvSysDtTime(
						char				*p_sys_date_time,
						DEBUG_INFO_STRUCT_H	**l_debug_info_ptr
						);


extern	int	CO_RtvSysParams(DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern	int	CO_Chk_CodeValid(
						char				*p_code_typ,
						char				*p_code_val,
						char				*chr_p_country_code,
						DEBUG_INFO_STRUCT_H	**l_debug_info_ptr
						);

extern	int	CO_RtvNxtSeqNum(
						PRO_GSEQNUM_STRUCT_H	*p_pro_gseqnum_struct_h,
						DEBUG_INFO_STRUCT_H			**l_debug_info_ptr
						);

extern	int	 CO_Chk_Holiday(char	*p_holi_date,
											int	*p_exist,
											DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
											char *p_exch_code);

extern	int	CO_Chk_CntryEnabled(char *p_mainfunc,
											char *p_condid,
											short *p_condexists,
											DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern	int	CO_ProcMonitor(FILE *fptr,
								char *p_charmessage,
								DEBUG_INFO_STRUCT_H **l_debuginfo_struct_h,
								INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_c); 

extern	int	CO_Int_CtxMgmt(char *p_db_user, char *p_db_passwd);
extern	int	CO_ReadToken(FILE*			p_fptr,
						char*				p_token,
						char*				p_value,
						DEBUG_INFO_STRUCT_H**	l_debug_info_ptr);
extern	int 	CO_Prnt(	char 						*nameof_file_a,
						char						*printername,
						INTL_ENV_DATA_STRUCT_H 	*p_intl_env_datastruct_h,
						DEBUG_INFO_STRUCT_H 			**l_debug_info_ptr) ;
/*Sonali Audit*/
extern   int  CO_Upd_AudLog_Chk_SysOnline( INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
                                char *p_audit_data,
                                char *p_key_value,
                                char *p_comments,
										 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

/*extern   int  CO_Upd_AudLog_Chk_SysOnline( INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
										 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);*/


extern	int	CO_GetDbCMCon(char *princiName,char *chr_db_id,char *chr_db_pwd);

extern	int 	CO_Chk_Acl(char *username,char *functionname,int *access);

#ifndef ORA_PROC
extern	int	CO_Rtv_Ctx(sql_context * p_ctx, int *p_ctx_num);
#endif
extern	int	CM_Rls_Ctx(int p_ctx_no);

#define INTL_WARNING\
	{\
		CO_InsertWarning( &l_debug_info_struct_h_tmp,\
							 APL_NOT_AN_ERROR,\
							 APL_NULL_STRING,\
							 APL_NULL_STRING,\
							 APL_NULL_STRING,\
							 __LINE__,\
							 __FILE__);\
		CO_OkWarning(l_debug_info_struct_h_tmp);\
		l_debug_info_struct_h_tmp->h_next = *l_debug_info_ptr;\
		*l_debug_info_ptr = l_debug_info_struct_h_tmp;\
	}

#define	S_ERASE_DUMMY_WARNING\
	{\
		l_debug_info_struct_h_tmp	=	(*l_debug_info_ptr)->h_next;\
		rpc_ss_free(*l_debug_info_ptr);\
		*l_debug_info_ptr = l_debug_info_struct_h_tmp;\
	}	

#define  S_NON_DCE_ERASE_DUMMY_WARNING\
   {\
      if (*l_debug_info_ptr != NULL) \
		  {\
       l_debug_info_struct_h_tmp =  (*l_debug_info_ptr)->h_next;\
			free(*l_debug_info_ptr);\
       *l_debug_info_ptr = l_debug_info_struct_h_tmp;\
		  }\
   }

extern	int GBDbInsIMSGENT(	 char *p_msgno, 
										 char *chr_p_key, 
		   							 char *p_client,
										char chr_p_autotransmit,
										char *chr_p_param_str, 
                   				DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

extern	int CO_Pro_BatchRestartLPC(char *p_progname,
						  char *chr_p_key_a,
						  char *p_funcparam,
						  int *int_p_funcreturnstate,
						  int *p_childpid,
						  DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
						  INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h);
#endif
