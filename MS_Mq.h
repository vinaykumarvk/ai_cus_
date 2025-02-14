













 
#include "Intellect_Interface.h"
#define MQ_PUT_DATA_LEN		4035
#define MQ_MGER_NAMERR_LEN	48
#define QNAME_LEN          48

#define MQ_INSTRUMENT			"CS" 
#define MQ_CLIENT			"CA" 
#define MQ_MKTPRC 			"MP"	
#define MQ_DEALHLD			"TX"	
#define	MQ_EOD 				"ED"
#define MQ_BOD				"BD"

typedef struct{
		char		h_evt_typ[3];
		char		h_business_date[APL_DATE_LEN];
		int		h_sequence_no;
		char		h_status_ind[2];
		char		h_proc_data[4000];
	      } EI_MQ_DATA_STRUCT_H; 	

typedef struct{
                short            i_evt_typ;
                short            i_business_date;
                short            i_sequence_no;
                short            i_status_ind;
                short            i_info;
              } EI_MQ_DATA_STRUCT_I;	

