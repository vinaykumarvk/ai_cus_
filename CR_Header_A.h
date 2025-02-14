/*
 *    COPYRIGHT NOTICE
 *
 *   Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *
 *   These materials are confidential and proprietary to 
 *    Polaris Software Lab Limited and no part of these materials should
 *    be reproduced, published, transmitted or distributed in any form or
 *    by any means, electronic, mechanical, photocopying, recording or 
 *    otherwise, or stored in any information storage or retrieval system
 *    of any nature nor should the materials be disclosed to third parties
 *    or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
/*********************************************************************
 *
 * Module Name         :	
 *
 * File Name           :
 *
 * Description         :	
 *
 *           
 *
 *            Version Control Block
 *
 * Date        Version		Author               Description
 * ---------   --------	 ---------------  ---------------------------
 *					
 *
 *********************************************************************/












 

#ifndef DEFINITION_HEADER_INCLUDED
#define DEFINITION_HEADER_INCLUDED
#define	RPR_MODE		"RPR"
#define	REP_MODE		"REP"
#define	CLS_MODE		"CLS"
#define 	OPEN_MODE		"OPN"
#define	SST_MODE		"SST"
#define	C_MODE_GST		"GST"
#define	C_MODE_PMT		"PMT"
#define	C_MODE_AMT		"AMOUNT"
#define	C_MODE_AST		"AST"
#define	CLH_MODE		"CLH"
#define	C_MODE_EXE		"EXE"
#define 	C_MODE_MAN		"MAN"
#define	C_MODE_URG		"URG"
#define	ALERT_MODE		"ALR"
#define  NDC_MODE		"NDC"
#define  NDB_MODE		"NDB"
#define  UFL_MODE		"UFL"
#define	 PMR_MODE		"PMR"
#define	C_MODE_SSR		"SSR"
#define	C_MODE_GSR		"GSR"
#define	C_MODE_RGR		"RGR"	
#define	MS_RSND_MODE		"MSR"	
#define	CANCEL_MODE		"CAN"	
#define	BOG_MODE		"BOG" 
#define  BOG_SEQ_RST_MODE		"BSR" 
#define  CHLD_RST_SETL_MODE		"SCR"




#define	STATUS_AUTH			"AA"
#define 	STATUS_CLS_AUTH		"CA"
#define	STATUS_CONF			"CC"
#define	STATUS_SETL			"CS"
#define	STATUS_CLS_UAUTH	"CU"
#define	STATUS_DEL_AUTH		"DD"
#define	STATUS_DEL_UAUTH	"DU"
#define	STATUS_SMI_DELUAUTH "DS" 
#define	STATUS_SMI_DELAUTH 	"DA" 	
#define	STATUS_EXEC			"EX"
#define	STATUS_FROZ_AUTH		"FA"
#define	STATUS_FROZ_UAUTH	"FU"
#define	STATUS_MON_SETL		"MS"
#define	STATUS_CANC_AUTH		"NA"
#define	STATUS_CANC_UAUTH	"NU"
#define	STATUS_OPEN_UAUTH	"OU"
#define	STATUS_PART_CONF		"PC"
#define	STATUS_PART_EXEC		"PX"
#define	STATUS_SEC_SETL		"SS"
#define	C_STS_UNREP			"UR"
#define	STATUS_UAUTH		"UU"
#define	STATUS_UNFROZ_UAUTH	"ZU"
#define	STATUS_CANC_REVUAUTH	"RU" 
#define MS_MSGNO_534N01   "534N01"  
#define STATUS_LOCCHNG      "IA"
#define INTLOC_CHNG_STAT      "II"



#define   CUST_CHNG_IND                 "1"
#define   USERCHANGE                 "2"
#define   CUST_DEL_IND                 "3"
#define   USERDELETE                 "4"
#define   AUTH_DEL_IDENT                 "5"
#define   RESETDELETE                "6"
#define   AUTH_CANCL_IDENT                 "7"
#define   RESETCANCEL                "8"
#define   AUTOREPAIRED              "11"
#define   UNREPAIRED                "12"
#define   CANCELLATION              "13"
#define   REPAIRDELETE              "16"
#define	 ORDEXECRESET					"17"
#define   PARTIALCONFIRM            "21"
#define   TXNCHANGE                 "22"
#define   SETTLE_SD                 "31"
#define   SETTLE_MD                 "32"
#define   SETTLE_SD_MD              "33"
#define   SETTLE_PR                 "34"
#define   SETTLE_MT                 "35"
#define   SETTLE_C                  "36"
#define   SETTLE_BR                 "37"
#define   PARTIALEXECUTE            "38"
#define   MARKANOMALOUS             "41"
#define   RESETANOMALOUS            "42"
#define   DELV_TICKET             "51"
#define   RECEIVETICKET             "52"
#define   TEMPOUTTICKET             "53"
#define   TEMPRETURNTICKET          "54"
#define   AUD_MARKEDFORTRANSFER     "61"
#define   AUD_OUTTOTRANSFER         "62"
#define   AUD_RETURNFROMTRANSFER    "63"
#define   AUD_VALIDATIONOFDEED      "64"
#define   AUD_REGCOMPLETED          "65"
#define   STAMPMONEYREC					"66"                                    
#define   LOSTMISPLACED					"67"                                    
#define   AUD_MARKEDCOMPLETED       "68"
#define   INSTRULOCNREACH              "71"
#define   UNDOSECLOCN               "72"
#define   CHARGEDTOVALT					"73"                                     
#define   PRC_SETTLETRDPRN				"81"                                     
#define   PRC_STAMPMONEYRECPRN		"82"                                     
#define   RTSPROC          "91"
#define	 SENDMT508						"92" 
#define	 AUTH_RPR_INDENT							"93" 




#define 	 STMTCONFMSGNO            	"1"
#define 	 REC_DEL_MSG_NO_STR           	"2"
#define 	 CORPACTIONSMSGNO         	"3"
#define 	 HOLDINGSMSGNO            	"4"
#define 	 STMTTRANMSGNO            	"5"
#define 	 STMTPENDINGMSGNO         	"6"
#define 	 CASHPROJMSGNO            	"7"
#define 	 REGISTRATIONMSGNO        	"8"
#define 	 CANBLOCKTRDMSGNO         	"9"
#define 	 ORDEREXPMSGNO            	"10"
#define 	 FAILADVICEMSGNO          	"11"
#define 	 MANUALMSGNO              	"12"
#define 	 DATE_RNG_MSG_NO           	"13"
#define 	 EOMTELEXMSGNO            	"13"
#define 	 TELEXMSGNO               	"13"
#define 	 DEALCONFRPTMSGNO          	"14"
#define 	 IV_MSG_NO               	"15"
#define 	 PORTFOLRATIOMSGNO        	"16"
#define 	 VTBMESSAGENO             	"17"
#define 	 ORDEXECANMSGNO           	"18"
#define 	 VTBCANCELMSGNO           	"19"
#define 	 CANCELMSGNO              	"20"
#define 	 SETLPROBMSGNO            	"21"
#define 	 DEP_MGMT_ADV_NO          	"22"
#define 	 STMTALLEGMSGNO           	"36"
#define	STMTINTRAPOSADVNO          	"37"


#define  NORMALDEAL         "1"
#define  INITPURCHTRD      "2"
#define  TRFDEAL            "3"
#define  INSTRUCONVDEAL        "10"
#define  RTSPROCDEAL     "18"
#define  DEALTYPE_CORP_A        "19"
#define  NONBILLDEAL        "20"
#define  ENTRYDEALNONBILL   "21"
#define  EXITDEAL           "22"
#define  TURNAROUNDTRD     "25"
#define  DL_BOOKTRF_IND        "26"
#define  INTRAFIRM         "27"

#define  IPONORMALDEAL		"28"
#define  IPOBOOKTRFDEAL		"29"
#define  DL_BLOCK_INDENT          "99"
#define  EXTERNALDEAL       "30"
#define  EXTERNALTRFDEAL     "31"

#define PROPREMOTEDEAL       "50"
#define NONPROPREMOTEDEAL    "35"



#define STATUS_POS_LEN		4 
#define FAILREAS_CD_LEN 		3
#define DEALTYPE_LEN_A		3 
#define CLSCD_LEN		5
#define TYPEOF_SEC_LEN		4
#define PR_DEC_LEN		8
#define	BUFFER_LEN		 261
#define	RECORD_STAT_LEN	3
#define  DOMCPCLIENT_LEN    11



#define 	DEALCD_DF	'1'
#define	DEALCD_RF	'2'
#define 	DEALCD_DVP	'3'
#define 	DEALCD_RVP	'4'
#define 	DEALCD_CD	'5'
#define	DEALCD_CR	'6'
#define 	DEALCD_DCD	'7'
#define 	DEALCD_RCR	'8'



#define VAL_RECDEAL(chr_p_key_a)	chr_p_key_a == '2' || chr_p_key_a == '4'
#define VAL_DELIVER_DEAL(chr_p_key_a)	chr_p_key_a == '1' || chr_p_key_a == '3' 
#define VAL_FREE_DEAL(chr_p_key_a)		chr_p_key_a == '1' || chr_p_key_a == '2'
#define VAL_VP_DEAL(chr_p_key_a)			chr_p_key_a == '3' || chr_p_key_a == '4' || chr_p_key_a == '5' || chr_p_key_a == '6' || chr_p_key_a == '7' || chr_p_key_a == '8'


#define FAILREASON_539_SECSETL		"69"
#define FAILREASON_539_MONEYSETL		"64"



#define	EX_ARENA_STX	"1"



#define 	MANIFOLD_REG_STAT(chr_p_key_a)		chr_p_key_a == 'O' || chr_p_key_a == 'R'
#define	TEMP_OUTREG_STAT(chr_p_key_a)	chr_p_key_a == 'O'
#define	TEMP_RETREG_STAT(chr_p_key_a)	chr_p_key_a == 'R'
#define	TEMP_OUTREG_CD			'O'
#define	TEMP_RETREG_CD			'R'



#define	PEND_REG_CODE			'0'
#define	DL_MARKCOMPL_REGSTCODE			'C'
#define	DL_MARKTRF_REGSTCODE			'1'



#define STATUS_POS_000	"000"
#define	STATUS_POS_001	"001"
#define	STATUS_POS_002	"002"
#define	STATUS_POS_003	"003"
#define	STATUS_POS_004	"004"



#define	BUY_IND	'B'
#define	SELL_IND	'S'



#define	COMMIT_COUNT_I		20
#define 	TKTTYPE_REC		'R'
#define 	TKTTYPE_DEL		'D'
#define	TEMP_OUTTKT_IND  	'O'
#define	TEMP_RET_IND		'T'
#define	POS_DET_LEN		50
#define	DEALDET_LEN		4
#define	LOCDET_LEN		31
#define	SEC_DET_LEN_D		131
#define	SHORT_NAME_LEN	13
#define	REG_NAME_LEN		81
#define	CLH_CLIENT_LEN_A	16
#define	CNAME_LEN_A			66
#define  EX_ARENA_LEN		3
#define  SEQ_NO_LEN			5
#define  FLD_UP_DATE_LEN			21
#define 	FILE_NAME_LEN		13



#define	BUY_ORD				'B'
#define	SELL_ORD_IND			'S'
#define	ORDER_REFNO_SEQNAME	"ORDER_REFNO"
#define	SEQNUM_PAD_CHAR		'0'
#define	SEQNUM_LEN				5
#define	JULDATERR_LEN				4
#define	YR_LEN					3
#define	SYSTEM_GEN_DEAL_IND	"G"
#define	LR_DEALTYPE_LEN		3
#define	REG_BR_IND_LEN			3
#define	REG_SEC_IND				"RG"



#define  DEAL_TRAILFOR_IND	'T'
#define  ORD_TRAIL_FOR	'O'



#define MAX_PR 9999999999.99999999



#define	TIME_LEN					7
#define	JULDATERR_PAD_CHAR			'0'
#define	REG_BCL_IND  'R'
#define	BCL_IDENT_REC_PREFIX	"BCR"
#define	BCL_IDENT_DEL_PREFIX	"BCD"
#define	BLC_REC_IDENT_PRE	"TRR"
#define	BLC_DEL_IDENT_PRE	"TRD"
 


#define AE_NEWENTRY_IND 		'F'
#define AE_CHNG_ENTRY			'C'
#define AE_REVENTRY			'R'
#define STX_EX_ARENA_IND		'1'
#define NON_STX_EX_ARENA_IND	'2'
#define OTH_EX_ARENA		'3'
#define GL_ACCOUNT_LEN	11
#define BRANCH_CD_LEN	4
#define AE_CCYCD   "000"
#define AE_CREDIT_DLCD	"505"
#define AE_DEBIT_DLCD 	"504"
#define AE_CREDIT_DLCD_PK   "913"
#define AE_DEBIT_DLCD_PK   "912"
#define AE_DLCD_PO_A 	"952"
#define AE_REV_DLCD	"645"
#define AE_COMMON_DLCD	"59"
#define AE_TAX_DEALCD	"524"
#define AE_CREDIT_IND	'1'
#define AE_DEBIT_IND	'0'
#define LOC_IDENT_LEN		17
#define SETL_DATE_LEN		9
#define AE_NORMAL_IND		'2'
#define AE_SUMMARY_IND	'4'
#define AE_GEN_IND_CHAR	'G'



#define	MS_MSGNO_520		"520"
#define	MS_MSGNO_521		"521"
#define	MS_MSGNO_522		"522"
#define	MS_MSGNO_523		"523"
#define	MS_MSGNO_530		"530"
#define	MS_MSGNO_531		"531"
#define	MS_MSGNO_532		"532"
#define	MS_MSGNO_533		"533"
#define	MS_MSGNO_534		"534"
#define	MS_MSGNO_53X		"53x"
#define	MS_MSGNO_572		"572"
#define	MS_MSGNO_592		"592"
#define	MS_MSGNO_596		"596"
#define	MS_MSGNO_596P		"596P"
#define MS_MSGNO_53XN01	"53xN01"	
#define MS_MSGNO_508		"508"		
#define	MS_MSGNO_578R01	"578R01" 




#define	MS_SEND53X_ONLINE_IND	'O'
#define	C_SEND_53X_EOD_FLG		'E'



#define	APL_FE_IND			"F"
#define	APL_BE_IND			"B"



#define	MS_STATUS_UNSEND	'D'
#define	NOT_EXIST_IND				0
#define	MS_NOTSENT				1
#define	SENT_IND				2
#define	LOCK_REC_IND			1
#define	MS_MSGNO_LEN			4



#define	CAE_IND	"CAE"
#define	CAE_MODIDENT_IND	'T'


#define CORE_MOD_IND					    'C'
#define C_SEQNAME					 "ACCENTRIES"
#define DEALCD_215				 "215"
#define DEALCD_267				 "267"
#define DEALCD_047				 "047"
#define DEALCD_097				 "097"
#define DEBIT_IND					 "D"
#define CREDIT_IND_B					 "C"
#define MS_SWIFT_BOGNO_0050			 "00050"
#define MS_SWIFT_BOGNO_0731			 "00731"
#define MS_SWIFT_BOGNO_0332			 "00332"
#define CCY_GRD_IND						 "GRD"
#define SEC_TYPE_FMT						 "FMT"
#define TYPOF_SEC_SHS						 "SHS"
#define DEALCD_RTS						 "RTS"
#define SEC_TYPE_BOND						 "BON"
#define DL_REC_DET					 "DET"


#define PROP_CLI        '1'
#define NON_PROP_ACC    '2'
 
#endif
