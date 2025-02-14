
#include "Prog_Common.h"
#include "CR_Common.h"
#include "MS_Swift.h" 
#include "DL_Interface.h" 

#define APL_LINE_LEN 100
#define BT_DEBUG 1
#define BT_IF_DEBUG if(BT_DEBUG)
/* retro by Lakshmi Swetha - start*/

// AIX -Warnings Removal -- Redefined in Intellect_Interface.h 
   
/*** #define APL_FUNCTION_ENTER(fp)\
{\
	char l_line[APL_LINE_LEN];\
	sprintf(l_line,"Entered Function\t\t|%s|",__func__);\
	BT_IF_DEBUG\
		CO_ProcMonitor(fp,l_line,NULL,NULL);\
}

#define APL_FUNCTION_RET_SUCCESS(fp)\
{\
	char l_line[APL_LINE_LEN];\
	sprintf(l_line,"Success From Function\t\t|%s|",__func__);\
	BT_IF_DEBUG\
		CO_ProcMonitor(fp,l_line,NULL,NULL);\
	return APL_SUCCESS;\
}
	
#define APL_FUNCTION_RET_FAILURE(fp)\
{\
	char l_line[APL_LINE_LEN];\
	sprintf(l_line,"Failure From Function\t\t|%s|",__func__);\
	BT_IF_DEBUG\
		CO_ProcMonitor(fp,l_line,NULL,NULL);\
	return APL_FAILURE;\
}



#define APL_CLOSE_FILE(fp) \
	if(fp != (FILE *)NULL)fclose(fp);    ***/
 /** retro by Lakshmi Swetha - end **/

#define BT_RESTART 10
#define BT_START 11
#define BT_CANNOT_EXECUTE 12
#define BT_CONFLICT 13
#define BT_PREDECESSOR 14

#define BT_EOD_SCH_PROG		"INTL_EODScheduler"
#define BT_BOD_SCH_PROG		 "INTL_BODScheduler"


#define BT_REQ_PARAMDATA_LEN 4001	/**Biju**/
#define BT_REQ_ERRDESC_LEN 4001		/**Biju **/
#define BT_REQ_ENVSTR_LEN 2001		/**Biju **/
#define BT_REQ_WRP_LEN	201			/**Biju **/
#define BT_DATA_FLD_SEP_LEN	2		/**Biju **/
#define BT_PROCESS_NAME_LEN	100		/**Biju **/
#define BT_PROCESS_KEY_LEN	100		/**Biju **/
#define APL_TRUE		1

#define CONV_SCH_PROG "CM_ConvScheduler"
#define APL_DB_PWD_LEN	100		/**Biju **/
#define ERROR_LENGTH 200
#define BT_NOTGOTLOCK sqlca.sqlcode==-54

/** Function Declarations **/
int CO_Get_DBConnect(DEBUG_INFO_STRUCT_H **);
int BT_Lock_Rec(	char **,
					FILE *,
					DEBUG_INFO_STRUCT_H **);

int BT_Mod_Process_Status(	char **,
							FILE *,
							DEBUG_INFO_STRUCT_H **,
							int);
int BT_MarkAbort(	INTL_ENV_DATA_STRUCT_H *,
					DEBUG_INFO_STRUCT_H  **);

int BT_Chk_Conflicts(	char **,
						char *,
						int *,
						DEBUG_INFO_STRUCT_H **,
						INTL_ENV_DATA_STRUCT_H *);

int BT_Chk_Predecessors(	char **,
							char *,
							int *,
							DEBUG_INFO_STRUCT_H **,
							INTL_ENV_DATA_STRUCT_H *);

int BT_Chk_Aborted(	char *,
					char *,
					char *,
					int *,
					DEBUG_INFO_STRUCT_H **,
					INTL_ENV_DATA_STRUCT_H *);

int BT_Chk_Duplicate(	char *,
						char *,
						char *,
						int *,
						DEBUG_INFO_STRUCT_H **,
						INTL_ENV_DATA_STRUCT_H *);

int CO_Pro_FreeArray(char **);

int BT_Restart_Process(	char *,
						char *,
						char *,
						int *,
						DEBUG_INFO_STRUCT_H **,
						INTL_ENV_DATA_STRUCT_H *);
