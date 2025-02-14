













 

extern int   EL_PassGrAccEnt(char           chr_p_modident,
       		                char           *chr_p_batchno,
              			       char           *chr_p_batchdate,
                     		 char           **argv,
                     		 FILE           *fl_userlog,
									 FILE				 *chr_finifile,
                     		 INTL_ENV_DATA_STRUCT_H *p_intlenv_data_struct_h,
                     		 DEBUG_INFO_STRUCT_H   **l_debug_info_ptr);


extern int CM_DelIGRACCTENTFn(char *chr_p_batchno,
                       			char *chr_p_batchdate,
                       			char chr_p_modident,
                       			INTL_ENV_DATA_STRUCT_H *p_intl_envdatastruct_h,
                       			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

