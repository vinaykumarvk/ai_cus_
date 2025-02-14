













 
typedef struct {
		char client[APL_CLIENT_LENGTH];
		long service_cd;
		char service_det[22];
		char b_prd[APL_DATE_LEN];
		int inden_num;
		double quantity;
		double fees;
		char b_ccycd[APL_CCYCODE_LEN];
		char purge_recall_ind;
		char access_stamp[APL_DATE_LEN];
	       } IV_CLIENT_OTHSERV_STRUCT_H;
