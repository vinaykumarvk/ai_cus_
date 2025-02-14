

 
   
   
   
   
   
   
   
   
   
   
   

#ifndef BATCH_HEADER_INCLUDED
#define BATCH_HEADER_INCLUDED
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
extern int CO_Pro_BatchRestart(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_progname,
     char *chr_p_key_a,
     char *p_funcparam,
     int *int_p_funcreturnstate,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
extern int DL_Pro_AutoBrkSetl(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_progname,
     char *chr_p_key_a,
     char *p_funcparam,
     int *int_p_funcreturnstate,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
typedef struct CM_Batch_v1_0_epv_t {
int (*CO_Pro_BatchRestart)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_progname,
     char *chr_p_key_a,
     char *p_funcparam,
     int *int_p_funcreturnstate,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
int (*DL_Pro_AutoBrkSetl)(
#ifdef IDL_PROTOTYPES
     handle_t IDL_handle,
     char *p_progname,
     char *chr_p_key_a,
     char *p_funcparam,
     int *int_p_funcreturnstate,
     char nameof_file[50],
     FILE_TYPE file_type,
     pipe_type data,
     DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
     INTL_ENV_DATA_STRUCT_H *p_intl_env_datastruct_h
#endif
);
} CM_Batch_v1_0_epv_t;

#ifdef __cplusplus
    }
#endif

#endif
