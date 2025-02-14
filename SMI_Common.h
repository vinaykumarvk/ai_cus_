













 
#include "SMI_InterFace.h"

typedef struct {
   short  i_dl_client;
   short  i_indentity_no;
   short  i_dealcd;
   short  i_classofdl;
   short  i_ex_arena;
   short  i_dlt;
   short  i_setldt;
   short  i_loccode;
   short  i_instr_code;
   short  i_currencycode;
   short  i_domcpclt_cd;
   short  i_countclt;
   short  i_info1;
   short  i_failreas_cd;
   short  i_failinfo;
   short  i_verfied_with;
   short  i_deal_status;
   short  i_countcltnm;
   short  i_clientof;
   short  i_qty;
   short  i_net_setlval;
   short  i_grs_setlval;
   short  i_trans_status_ind;
   short  i_smi_req_class;
   short  i_smi_reject_reason;
   short  i_access_stamp;
   short  i_subfailreas_cd;
   short  i_commonindentity_no;
   short  i_maker;
   short  i_maker_dt;
   short  i_checker;
   short  i_checker_dt;
   short  i_confdate;
}EI_SMI_PEND_DEAL_STRUCT_I;

extern int   EI_Rtv_SMIAwt(EI_SMI_PEND_DEAL_STRUCT_H	*p_ei_smi_pend_deal_struct_h,
                         INTL_ENV_DATA_STRUCT_H 		*p_intlenv_data_struct_h,
                         DEBUG_INFO_STRUCT_H   			**l_debug_info_ptr);

extern int   EI_Proc_SMITrimFlagSet(char							*chr_p_client,
									char 							*p_refnum,
									char 							*chr_p_access_stamp,
                         	INTL_ENV_DATA_STRUCT_H 		*p_intlenv_data_struct_h,
                         	DEBUG_INFO_STRUCT_H   			**l_debug_info_ptr);

extern int 		EI_Chk_SMICanModStat(char                      	*chr_p_client,
											char                       *chr_p_refno,
											char                       *p_clt_rej_flag,
											char                       *p_amd_can_flag,
											INTL_ENV_DATA_STRUCT_H         *p_intlenv_data_struct_h,
											DEBUG_INFO_STRUCT_H               **l_debug_info_ptr );

extern int 		EI_Proc_SMIEODFlgSet(INTL_ENV_DATA_STRUCT_H      *p_intlenv_data_struct_h,
                  			  DEBUG_INFO_STRUCT_H            **l_debug_info_ptr );

