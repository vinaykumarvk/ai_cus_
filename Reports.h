

 
   
   
   
   
   
   
   
   
   
   
   

#ifndef REPORT_HEADER_INCLUDED
#define REPORT_HEADER_INCLUDED
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
#define CLT_ALL_VALID_IND (0)
#define CLT_BRKR_IND (1)
#define CLT_CA_IND (2)
#define CLT_CB_IND (3)
#define CLT_CC_IND (4)
#define CLT_CI_IND (5)
#define CLT_CM_IND (6)
#define CLT_ALL_MSG_AUTH_IND (7)
#define CLT_NOT_INTERNAL_BRK_IND (8)
#define CLT_BL_IND (9)
#define CLT_B_OTHSERV_IND (10)
#define CLT_ALL_NOTCLOSED_IND (11)
#define CLT_AU_BRK_ONLY_IND (12)
#define CLT_ENT_IND (13)
#define CLT_CCI_IND (14)
#define CLT_ALL_IMAST_AUTH_IND (15)
#define CLT_REPL_IND (16)
#define CLT_BILLABLE_IND (17)
#define CLT_ALL_IND (18)
#define CLT_ALL_MAST_IND (19)
#define ACCOUNT_INQ_HIS_MST_ACC (19)
#define CLT_ALL_MAST_NOTBRK_CC_IND (20)
#define ACCOUNT_INQ_HIS_MST_ACC_CC (20)
#define CLT_ALL_NOTBRKR_IND (21)
#define ACCOUNT_INQ_TRD_HIS_ACC_CC (21)
#define CLT_ALL_NOTCUSD_IND (22)
#define ACCOUNT_INQ_TRD_HIS_ACC_B (22)
#define CLT_ALL_MAST_AUTH_IND (23)
#define CLT_ALL_MAST_NOTBRK_IND (24)
#define NPNB (49)
#define CLT_CUSTD_IND (68)
#define EURO_MESSAGE (69)
#define CLT_CMA_IND (70)
#define CLH_CLIENT_IND (74)
#define RUCLIENT_ALL_IND (50)
#define RULOC_ALL_IND (51)
#define RUPROD_ALL_IND (52)
#define RUSRN_ALL_IND (53)
#define RUINSTR_ALL_IND (54)
#define RUCLIENT_UAUTH_IND (55)
#define RULOC_UAUTH_IND (56)
#define RUPROD_UAUTH_IND (57)
#define RUSRN_UAUTH_IND (58)
#define RUINSTR_UAUTH_IND (59)
#define RUCLIENT_AUTH_IND (60)
#define RULOC_IND (61)
#define RUPROD_AUTH_IND (62)
#define RUSRN_AUTHL_IND (63)
#define RUINSTR_AUTH_IND (64)
#define RUSRN_DIST_IND (65)
#define LOC_NOTIN_RULOC (66)
#define SEC_NOTIN_RUINSTR (67)
#define INSTRUMENT_INSTRU_ALL (25)
#define INSTRUMENT_RSW (26)
#define INSTRUMENT_CHILD (27)
#define INSTRUMENT_PARENT (28)
#define INSTRUMENT_SCC (29)
#define INSTRUMENT_REG (30)
#define INSTRUMENT_FROM_INSTRU_CONV_INP (31)
#define INSTRUMENT_TO_INSTRU_CONV_INP (32)
#define INSTRUMENT_INSTRUCONAUT (33)
#define INSTRUMENT_AU (34)
#define INSTRUMENT_INQ_ALL_INSTRU (35)
#define INSTRUMENT_INQ_HIS_ALL_INSTRU (35)
#define INSTRUMENT_ENT_INSTR (36)
#define INSTRUMENT_AINQ (45)
#define INSTRUMENT_REDEN_TYPE (46)
#define INSTRUMENT_REDEN (47)
#define INSTRUMENT_REDEN_TYPE_AUTH (48)
#define INSTRUMENT_FROM_INSTRU_CONV_INPTRD (71)
#define INSTRUMENT_INSTRU_ALL_DEAL (72)
#define INSTRUMENT_RSW_DEAL (73)
#define INSTRUMENT_ISSUER (75)
#define LOCATION_NULL (37)
#define LOCATION_AUTHLOCN (37)
#define LOCATION_ELSE (38)
#define CCYNULL_IND (39)
#define CCYELSE_IND (40)
#define FAILCODES_NULL (41)
#define FAILCODES_ELSE (42)
#define STAT_COUNTRY (43)
#define STAT_ELSE (44)
extern int CO_ReadReport(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type *data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int CO_Upld_File(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
extern int wrp_GetCodeDescFn(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     int *p_type_num,
     char p_param[40],
     int *p_row_count,
     pipe_type *data,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
typedef struct read_report_v1_0_epv_t {
int (*CO_ReadReport)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type *data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*CO_Upld_File)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
int (*wrp_GetCodeDescFn)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     int *p_type_num,
     char p_param[40],
     int *p_row_count,
     pipe_type *data,
     INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr
#endif
);
} read_report_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
