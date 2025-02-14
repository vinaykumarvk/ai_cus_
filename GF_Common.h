/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2010 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to Polaris Software Lab Ltd
 *   and no part of these materials should be reproduced,published,transmitted or
 *   distributed in any form or by any means, electronic,mechanical,photocopying,
 *   recording or otherwise, or  stored in any information storage  or  retrieval
 *   system of any nature nor should the  materials be disclosed to third parties
 *   or used in any  other manner for which  this is not authorized, without  the
 *   prior express written authorization of Polaris Software Lab Limited.
 */
/************************************************************************************
 *
 * Module Name         :         Generic File Upload 
 *
 * File Name           :         GF_Common.h        
 *
 * Description         :         This file contains all header definitions and the 
 *                               common parameters for the GF Upload functionality
 ************************************************************************************
 *
 * Version Control Block
 *
 * Date        Version          Author              Description         RFS No.
 * ---------   --------  ---------------  ---------------------------  --------------
 * 10-Aug-2010 1.0.1.3   Naren V          NSDL DP Ins File Format Cha  ISKB_3298
 *                                        nges -  File format  length
 *                                        changes  were  incorporated
 *                                        accordingly as per the revi
 *                                        sed formats of  Import  and
 *                                        Export files  to  and  from
 *                                        the NSDL depository.
 *                                        As the current max line len
 *                                        gth is  capable  of holding                           
 *                                        1000 and the revised format
 *                                        is having rec len  >  1000,     
 *                                        the value of line len macro      
 *                                        is extended to 3000.                
 ************************************************************************************/


#include <stdio.h>
#include <Intellect_Common.h>
#include <Intellect_Interface.h>

#define GFU_REFNO_LEN		51
#define GFU_FILENAME_LEN	51
#define GFU_MODULE_LEN		51
#define GFU_DELIMITER_LEN	11
#define GFU_USER_LEN		16
#define GFU_DATE_LEN		20
#define GFU_FIELD_LEN		51
#define GFU_TYPE_LEN		2
#define GFU_REM_SPACE_LEN	2
#define GFU_FUNCTION_LEN	21
#define GFU_CHECK_LEN		2
#define GFU_WRAPPER_LEN		51
#define GFU_MODE_LEN		4
#define GFU_SP_LEN			51
/* #define GFU_LINE_LEN	1000 * Modified for ISKB_3298 - Aug2010 - Naren V */
#define GFU_LINE_LEN	3000  
#define GFU_FILE_NAME_LEN 100
#define GFU_FILE_TYPE_LEN 2
#define GFU_VALUE_LEN 500
#define GFU_TOKEN_LEN 500
#define GFU_UPLOAD_DIR "./"
#define GFU_ERROR_LEN 4001
#define GFU_FLOAT	'F'
#define GFU_DOUBLE	'D'
#define GFU_CHAR	'C'
#define GFU_STRING	'S'
#define GFU_ASCII	'A'
#define GFU_BINARY	'B'
#define GFU_POSITION 'P'
#define GFU_COMMIT_COUNT 500

#define GFU_BINARY_FILE "B"
#define GFU_ASCII_FILE "A"
#define GFU_DATE_TYPE "D"
#define GFU_PARAM_DATA_LEN 4001
#define GFU_ENV_DATA_LEN 2001
#define GFU_ERR_DATA_LEN 4001

#define GFU_TYPE_DEFAULT APL_NULL_STRING
#define GFU_SEQ_DEFAULT	0
#define GFU_START_DEFAULT	0
#define GFU_END_DEFAULT	0
#define GFU_SIZE_DEFAULT	0
#define GFU_ROVE_SPACE_DEFAULT "Y"
#define GFU_IND_YES "Y"
#define GFU_DEFAULT_LEN 51
#define GFU_SKIP_LINE_LEN 51
#define GFU_SKIP_LINE_DEL ","
#define GFU_ACCESS_STAMP_TYPE "Q"

#define GFU_VALID_LEN		2
#define GFU_HEADER_TEXT_LEN 2
#define GFU_FIELD_TYPE_LEN  51
#define GFU_LABEL_LEN       51
#define GFU_SEQ_LEN			500
#define GFU_START_LEN		500
#define GFU_END_LEN			500
#define GFU_REM_CHAR_LEN	500
#define GFU_REM_LAST_CHAR_LEN 500
#define GFU_STATIC_VAL_LEN  50
#define GFU_VAL_TYPE_LEN    50
#define GFU_REPEAT_LEN		2
#define GFU_QUERY_LEN		4001
#define GFU_PATH_LEN 501
#define GF_DELIM_CHAR_HASH '#'
#define GF_DELIM_STR_HASH "#"
#define GF_DELIM_STR_SPACE " "
#define GF_DELIM_CHAR_SPACE ' '

#define GFU_DEFAULT_DATE_FORMAT "DD-MON-YY"
#define GFU_DATE_FORMAT_LEN 51
#define GFU_VENDOR_LEN 11
typedef struct{
int		h_seq_num;
char	h_refno[GFU_REFNO_LEN];
char	h_file_name[GFU_FILENAME_LEN];
char	h_file_type[GFU_FILE_TYPE_LEN];
char	h_module[GFU_MODULE_LEN];
char	h_delimiter[GFU_DELIMITER_LEN];
int		h_header;
char	h_check_header[2];
int		h_format_no;
char	h_skip_line[GFU_SKIP_LINE_LEN];
char	h_vendor[GFU_VENDOR_LEN];
char	h_maker[GFU_USER_LEN];
char	h_maker_dt[GFU_DATE_LEN];
char	h_access_stamp[GFU_DATE_LEN];
char h_module_name[20];	/** Added by Sana for GFU Setup **/
}GFU_FILE_MAP_STRUCT_H;
typedef struct{
short	i_seq_num;
short	i_refno;
short	i_file_name;
short	i_file_type;
short	i_module;
short	i_delimiter;
short	i_header;
short	i_check_header;
short	i_format_no;
short	i_skip_line;
short	i_vendor;
short	i_maker;
short	i_maker_dt;
short	i_access_stamp;
short   i_module_name;  /** Added by Sana for GFU Setup **/
}GFU_FILE_MAP_STRUCT_I;

typedef struct {
	char	h_refno[GFU_REFNO_LEN];
	char	h_valid[GFU_VALID_LEN];
	char	h_header_text[GFU_HEADER_TEXT_LEN];
	char	h_field_type[GFU_FIELD_TYPE_LEN];
	char	h_label[GFU_LABEL_LEN];
	char	h_seq[GFU_SEQ_LEN];
	char	h_start[GFU_START_LEN];
	char	h_end[GFU_END_LEN];
	char	h_remove_char[GFU_REM_CHAR_LEN];
	char	h_remove_last_char[GFU_REM_LAST_CHAR_LEN];
	char	h_static_val[GFU_STATIC_VAL_LEN];
	char	h_val_type[GFU_VAL_TYPE_LEN];
	char	h_date_format[GFU_DATE_FORMAT_LEN];
	char	h_header[GFU_VAL_TYPE_LEN];
	int		h_srl_no;
	char	h_repeat[GFU_REPEAT_LEN];
	char	h_query[GFU_QUERY_LEN];
	/** Added by Sana for GFU Setup -- start **/
	char h_maker[14];
	char h_maker_dt[APL_DATE_LEN];
	char h_checker[14];
	char h_checker_dt[APL_DATE_LEN];
	char h_status[2];
	char h_ref_no[GFU_REFNO_LEN];
	char h_function_id[GFU_REFNO_LEN];
	/** Added by Sana for GFU Setup -- end **/
}GFU_FORMAT_MAP_STRUCT_H;

typedef struct GFU_FORMAT_MAP_STRUCT{
	char	h_refno[GFU_REFNO_LEN];
	char	h_valid[GFU_VALID_LEN];
	char	h_header_text[GFU_HEADER_TEXT_LEN];
	char	h_field_type[GFU_FIELD_TYPE_LEN];
	char	h_label[GFU_LABEL_LEN];
	char	h_seq[GFU_SEQ_LEN];
	char	h_start[GFU_START_LEN];
	char	h_end[GFU_END_LEN];
	char	h_remove_char[GFU_REM_CHAR_LEN];
	char	h_remove_last_char[GFU_REM_LAST_CHAR_LEN];
	char	h_static_val[GFU_STATIC_VAL_LEN];
	char	h_val_type[GFU_VAL_TYPE_LEN];
	char	h_date_format[GFU_DATE_FORMAT_LEN];
	char	h_header[GFU_VAL_TYPE_LEN];
	int		h_srl_no;
	char	h_repeat[GFU_REPEAT_LEN];
	char	h_query[GFU_QUERY_LEN];
	 /** Added by Sana for GFU Setup -- start **/
        char h_maker[14];
        char h_maker_dt[APL_DATE_LEN];
        char h_checker[14];
        char h_checker_dt[APL_DATE_LEN];
        char h_status[2];
        char h_ref_no[GFU_REFNO_LEN];
        char h_function_id[GFU_REFNO_LEN];
        /** Added by Sana for GFU Setup -- end **/
	struct GFU_FORMAT_MAP_STRUCT *h_next;
}GFU_FORMAT_MAP_STRUCT_LST;

typedef struct {
	short	i_refno;
	short	i_valid;
	short	i_header_text;
	short	i_field_type;
	short	i_label;
	short	i_seq;
	short	i_start;
	short	i_end;
	short	i_remove_char;
	short	i_remove_last_char;
	short	i_static_val;
	short	i_val_type;
	short	i_date_format;
	short   i_header;
	short	i_srl_no;
	short	i_repeat;
	short	i_query;
	 /** Added by Sana for GFU Setup -- start **/
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_status;
        short i_ref_no;
        short i_function_id;
        /** Added by Sana for GFU Setup -- end **/
}GFU_FORMAT_MAP_STRUCT_I;


typedef struct VAL_MAP{
	int h_seq_num;
	char h_module[GFU_MODULE_LEN];
	char h_function[GFU_FUNCTION_LEN];
	char h_token[GFU_TOKEN_LEN];
	char h_check[GFU_CHECK_LEN];
	struct VAL_MAP *h_next;
}GFU_VAL_MAP_STRUCT_LST;

typedef struct {
	int h_seq_num;
	char h_module[GFU_MODULE_LEN];
	char h_function[GFU_FUNCTION_LEN];
	char h_token[GFU_TOKEN_LEN];
	char h_check[GFU_CHECK_LEN];
}GFU_VAL_MAP_STRUCT_H;

typedef struct {
	short i_seq_num;
	short i_module;
	short i_function;
	short i_token;
	short i_check;
}GFU_VAL_MAP_STRUCT_I;

typedef struct{
	char h_module[GFU_MODULE_LEN];
	char h_wrapper[GFU_WRAPPER_LEN];
	char h_user[GFU_MODE_LEN];
	char h_sp_name[GFU_SP_LEN];
}GFU_REQ_MAP_STRUCT_H;

typedef struct{
	short i_module;
	short i_wrapper;
	short i_user;
	short i_sp_name;
}GFU_REQ_MAP_STRUCT_I;


typedef struct GFU_TOKEN_VAL_STRUCT{
	char h_token[GFU_TOKEN_LEN];
	char h_value[GFU_VALUE_LEN];
	struct GFU_TOKEN_VAL_STRUCT *h_next;
}GFU_TOKEN_VAL_STRUCT_LST;

typedef struct {
	char h_module[GFU_MODULE_LEN];
	char h_token[GFU_TOKEN_LEN];
	char h_value[GFU_VALUE_LEN];
}GFU_ENV_MAP_STRUCT_H;

typedef struct {
	short i_module;
	short i_token;
	short i_value;
}GFU_ENV_MAP_STRUCT_I;
typedef struct GFU_TOKEN_VAL_STRUCT_L
{
	int h_rec_no;
	int h_line_no;
	GFU_TOKEN_VAL_STRUCT_LST **h_token_val;
	struct GFU_TOKEN_VAL_STRUCT_L *h_next;
	char h_error[GFU_ERROR_LEN];
}GFU_FILE_LST;

typedef union {
	char h_char;
	char h_string[GFU_VALUE_LEN];
	float h_float;
	double h_double;
}GFU_UNION_TYPE;



typedef struct{
int h_seq;
char h_refno_map[GFU_REFNO_LEN];
char h_field[GFU_FIELD_LEN];
char h_value[GFU_VALUE_LEN];
char h_refno[GFU_REFNO_LEN];
char h_wrapper[GFU_WRAPPER_LEN];
char h_sp_name[GFU_SP_LEN];
}GFU_FORMAT_REF_MAP_STRUCT_H;


typedef struct GFU_FORMAT_REF_MAP_STRUCT_LST_T{
int h_seq;
char h_refno_map[GFU_REFNO_LEN];
char h_field[GFU_FIELD_LEN];
char h_value[GFU_VALUE_LEN];
char h_refno[GFU_REFNO_LEN];
char h_wrapper[GFU_WRAPPER_LEN];
char h_sp_name[GFU_SP_LEN];
struct GFU_FORMAT_REF_MAP_STRUCT_LST_T *h_next;
}GFU_FORMAT_REF_MAP_STRUCT_LST;


typedef struct{
short i_seq;
short i_refno_map;
short i_field;
short i_value;
short i_refno;
short i_wrapper;
short i_sp_name;
}GFU_FORMAT_REF_MAP_STRUCT_I;





int Format_Value(char *p_value,char *p_value_type,char *p_date_format,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_PosStr( char *p_line,
					int  p_start,
					int  p_end,
					char *p_value,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Remove_Char( char *p_value,
				 char *p_remove_chars,
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);


int Remove_Last_Char(char *p_value,			 
				char *p_remove_last_chars,
				 DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_DelStr(	char *p_line, 
					char *p_delim, 
					int p_index,
					char *p_value,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Rtv_Data_Direct(	char *p_line,
			char *p_file_type,
			int p_sequence,
			int p_start_pos,
			int p_end_pos,
			char *p_delimiter,
			char *p_remove_char,
			char *p_remove_lastchar,
			char *p_value_type,
			char *p_date_format,
			char *p_value,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int Rtv_Data_Replace(	char *p_line,
int p_line_no,
			char *p_file_type,
			char *p_label,
			int p_sequence,
			int p_start_pos,
			int p_end_pos,
			char *p_delimiter,
			char *p_remove_char,
			char *p_remove_lastchar,
			char *p_value_type,
			char *p_date_format,
			char *p_static_val,
			char *p_value,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Rtv_Data_Static(	char *p_line,
						char *p_static_val,
						char *p_value,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Rtv_Data_MapVal(	char *p_line,
			char *p_refno,	
			char *p_file_type,
					int p_sequence,
						int p_start_pos,
						int p_end_pos,
						char *p_delimiter,
						char *p_remove_char,
						char *p_remove_last_char,
						char *p_value_type,
						char *p_date_format,
						char *p_value,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Rtv_Data_Other(char *p_value);

int DynamicQuery(	char *p_sql_query, 
					char *p_output, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Replace_In_Str(	char *p_line,
					char *p_old,
					char *p_new, 
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int Rtv_Data_Query(	char *p_line,
int p_line_no,
			char *p_file_type,
			char *p_label,
			char *p_refno,
			char *p_field_type,
					char *p_sequence,
					char *p_start_pos,
					char *p_end_pos,
					char *p_delimiter,
					char *p_remove_char,
					char *p_remove_last_char,
					char *p_static_val,
					char *p_value_type,
					char *p_date_format,
					int p_srl_no,
					char *p_repeat,
					char *p_query,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int Rtv_Data_Value( char *p_line,
int p_line_no,
			char *p_file_type,
			char *p_label,
					char *p_refno,
					char *p_field_type,
					char *p_sequence,
					char *p_start,
					char *p_end,
					char *p_delimiter,
					char *p_remove_char,
					char *p_remove_last_char,
					char *p_static_val,
					char *p_value_type,
					char *p_date_format,
					int p_srl_no,
					char *p_repeat,
					char *p_query,
					char *p_value,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Call_Stored_Proc(	GFU_REQ_MAP_STRUCT_H *p_gfu_req_map_h,
			char *p_env_data, 
			char *p_param_data,
			int p_line_no,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Lst_To_Data(GFU_TOKEN_VAL_STRUCT_LST **p_token_value_lst, char *p_data,DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Process_Rec(	GFU_TOKEN_VAL_STRUCT_LST **p_gfu_env_map_lst,
						GFU_VAL_MAP_STRUCT_LST **p_gfu_val_map_lst,
						GFU_REQ_MAP_STRUCT_H *p_gfu_req_map_h,
						GFU_TOKEN_VAL_STRUCT_LST **p_gfu_param_data_lst,
						int p_line_no,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);
int GFU_Process_Lst(GFU_FILE_LST **p_file_lst,
					char *,
				char *,
				char *,
					GFU_VAL_MAP_STRUCT_LST **p_gfu_val_map_lst,
					GFU_REQ_MAP_STRUCT_H *p_gfu_req_map_h,
					GFU_TOKEN_VAL_STRUCT_LST **p_gfu_env_map_lst,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int Read_Ascii(	char *p_line,
				int p_line_no,
				GFU_FILE_MAP_STRUCT_H *p_gfu_file_map_h,
				GFU_FORMAT_MAP_STRUCT_LST **p_gfu_format_map_lst,
				GFU_TOKEN_VAL_STRUCT_LST **p_token_value,
				DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Conv_Lnk_Lst(	FILE *p_file,
		char *p_process_name,
		char *p_process_key,
		char *p_start_date,
						GFU_FILE_MAP_STRUCT_H *p_gfu_file_map,
		/**GFU_FILE_LST **p_file_lst,**/
		GFU_TOKEN_VAL_STRUCT_LST **p_gfu_env_map_lst,
		GFU_VAL_MAP_STRUCT_LST **p_gfu_val_map_lst,
		GFU_REQ_MAP_STRUCT_H *p_gfu_req_map_h,
						DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_Format(	char *p_format_refno,
					GFU_FILE_MAP_STRUCT_H *p_gfu_file_map_h,
					GFU_FORMAT_MAP_STRUCT_LST **p_gfu_format_map_lst,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_File(	GFU_FILE_MAP_STRUCT_H *p_gfu_file_map_h,
					FILE **p_file,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_ReqMap(	char *p_module, 
					GFU_REQ_MAP_STRUCT_H *p_gfu_req_map_h,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Rtv_Env(	char *p_module,
					GFU_TOKEN_VAL_STRUCT_LST **p_gfu_val_map_lst,
					DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_Process_File(	char *,
				char *,
				char *,
				char *,
				FILE *,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

int GFU_UpdErrorDet(	int p_line_no,
			char *p_skipped,
			char *p_status,
			char *p_token,
			char *p_value,
			char *p_reason,
			DEBUG_INFO_STRUCT_H **l_debug_info_ptr);

#define CSV "CSV"
#define TEXT "TXT"
#define EXCEL "XLS"


typedef struct C_E_T
{
	char h_label[500];
	char h_seq[500];
	int  h_start_pos;
	int  h_end_pos;
	struct C_E_T *h_next;
}C_E_T_STRUCT_H;
#define Lst_rtvValue(p_token_value,\
	                     p_token,\
	                     p_value)\
   if(Rtv_Value_Frm_Lst(p_token_value,\
				                        p_token,\
				                        p_value,\
				                        l_debug_info_ptr) == APL_FAILURE)\
   APL_GOBACK_FAIL

#define Lst_AddValue(p_token_value,\
		                     p_token,\
		                     p_value)\
   if(Add_Value_To_Lst(p_token_value,\
				                        p_token,\
				                        p_value,\
				                        l_debug_info_ptr) == APL_FAILURE)\
   APL_GOBACK_FAIL
