

 
   
   
   
   
   
   
   
   
   
   
   

#ifndef EI_SMI_HEADER_INCLUDED
#define EI_SMI_HEADER_INCLUDED
#ifndef IDL_DOUBLERR_USED
#define IDL_DOUBLERR_USED
#endif
#ifndef IDLBASE_H
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#endif
#ifndef COMMON_INTERFACEHEADER_INCLUDED
#include <Intellect_Interface.h>
#endif
typedef struct  {
char h_dl_client[11];
char h_indentity_no[17];
char h_dealcd[2];
char h_classofdl[3];
char h_ex_arena[3];
char h_dlt[20];
char h_setldt[20];
char h_loccode[5];
char h_instr_code[9];
char h_currencycode[4];
char h_domcpclt_cd[11];
char h_countclt[11];
char h_info1[261];
char h_fail_cd[3];
char h_failinfo[36];
char h_verfied_with[26];
char h_deal_status[3];
char h_countcltnm[66];
char h_clientof[66];
double h_qty;
double h_net_setlval;
double h_grs_setlval;
char h_trans_status_ind[3];
char h_smi_req_class[3];
char h_smi_reject_reason[201];
char h_access_stamp[20];
int h_subfailreas_cd;
char h_commonindentity_no[17];
char h_maker[15];
char h_maker_dt[20];
char h_checker[15];
char h_checker_dt[20];
char h_confdate[20];
} EI_SMI_PEND_DEAL_STRUCT_H;
extern int wrp_SMI_GetAwtT(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     EI_SMI_PEND_DEAL_STRUCT_H *p_ei_smi_pend_deal_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_SMI_SetTrmFlag(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_refnum,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_SMI_AmdCanUpdStat(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_refnum,
     char *p_clt_rej_flag,
     char *p_amd_can_flag,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_SMI_UpdEodFlg(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct core_smi_v1_0_epv_t {
int (*wrp_SMI_GetAwtT)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     EI_SMI_PEND_DEAL_STRUCT_H *p_ei_smi_pend_deal_struct_h,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_SMI_SetTrmFlag)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_refnum,
     char *chr_p_access_stamp,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_SMI_AmdCanUpdStat)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *chr_p_client,
     char *p_refnum,
     char *p_clt_rej_flag,
     char *p_amd_can_flag,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_SMI_UpdEodFlg)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
} core_smi_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
