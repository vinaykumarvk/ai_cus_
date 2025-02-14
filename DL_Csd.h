

#define DEBUG_FLAG 1
#define DEBUG_INFO if(DEBUG_FLAG)

#define RPT_FMRT "%-12s\t%-20s\n"
#define REPORT_HEADER_LEN  60


#define BUFFER_SIZE		50
#define COMMIT_COUNT_H		20
#define FILEPATH_LEN            100
#define FILENAME_LEN_A            80
#define INSTR_CD_LEN_C       	11
#define RECORD_TEMP_LEN  	20
#define CSD_STR_LEN    	15000
#define  TEMP_STR_LEN  	100
#define NO_OF_CASE_LEN         	20
#define NO_OF_SHS_LEN         	20
#define INSTR_ISIN_LEN_F         	13
#define INFO_FIELD_LEN    	260
#define OP_CD_LEN 		10
#define SATCLIENT_LEN   	11
#define SAT_CD_LEN   	11
#define FORMAT_STR_LEN 	50
#define SEQ_LEN 			5

typedef struct {
	char h_msg_ident_no[4];
	char c_recordateype[11];
	int  h_srl_number;
	char h_infosrc[11];
	char h_src[21];
	char h_typeof_link[2];
	int h_max_len;
        char c_padateype[2];
        char h_csd_padstr[3];
}DL_CSDMAP_STRUCT_H;

typedef struct {
   char h_msg_ident_no[4];
   char c_recordateype[11];
   int  h_srl_number;
   char h_infosrc[11];
   char h_src[21];
   char h_typeof_link[2];
   int h_max_len;
}DL_SAT_RECON_STRUCT_H;

typedef struct {
	short i_msg_ident_no;
	short i_recordateype;
	short i_srl_number;
	short i_infosrc;
	short i_src;
	short i_typeof_link;
	short i_max_len;
        short i_padateype;
        short i_csd_padstr;
}DL_CSDMAP_STRUCT_I;

typedef struct {
   short i_msg_ident_no;
   short i_recordateype;
   short i_srl_number;
   short i_infosrc;
   short i_src;
   short i_typeof_link;
   short i_max_len;
}DL_SAT_RECON_STRUCT_I;

