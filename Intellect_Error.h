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
 * Module Name         :	Maintenance
 *
 * File Name           : 	Intellect_Error.h
 *
 * Description         :  	This file contains all Error Definitions 
 *          					related to the System.
 *
 *            Version Control Block
 *
 * Date        Version		Author           Description			RFS No.
 * ---------   --------	 ---------------  -------------------	------------
 * 10/10/2005  1.2 	 		Smita Bhat			New File				HDFCMT_003	
 * 10/10/2005  1.5 	  ANIL			        New File		HDFCMT_002,HDFCMT_005,HDFCMT_006	                                             added new error definitions 
   12/12/2005  1.6    Manik Trivedi           Error Macros FOr Settlement Calender HDFCMT_008
   16/12/2005  1.7    Anil                  Daily Quotations    HDFCMT_009

	03/01/2005	1.9	 Smita Bhat				  Instrument Changes	 HDFCMT_003
*15/12/2005	1.10        Kouser Begum      Contains Error Description Macros. HDFCMT_001
*10/01/2006	1.11		Pradeep				Added Macros for Index Fund Master	HDFCMT_017
*30/12/2005     1.12        Kouser Begum      Contains Error Description Macros. HDFCMT_010 *02/02/2006     1.13        Kouser Begum      Contains Error Description Macros for
                                                                Client Master  HDFCMT_001   
*07/02/2005     1.14        Kouser Begum     HDFC - New Requirement - Error Description 
                                                    Macros - HDFCMT_003
*30/01/2006     1.13		Smita Bhat			Added Error Defn for CA		HDFCCA_009
*06/02/2006     1.16    Kouser Begum         HDFC - New Requirement Changes  HDFCMT_003 
*21/02/2006     1.17    Kouser Begum         New Maintenance          KB_001
*02/03/2006     1.19    Vaibhav			  	 CA_NIS                  HDFCCA_013					
*05/06/2006     1.20    Bageshri           MAX_FEE for Billing ClientSteup     HDFCIV_001
 *********************************************************************/
 
#define  APL_NBR_ERRORS 1183 

#define ERR_MAKER_CHECKER_SAME 							1 
#define ERR_MAND_DATA_MISSING								2 
#define ERR_REC_NOTFND 										3 
#define ERR_VALUE_CANT_NEGATIVE 							4 
#define ERR_VAL_SHLDBERR_POS 								5 
#define ERR_DATE_CANT_LESS_TODAY 						6 
#define ERR_DATE_CANT_GRT_TODAY 							7 
#define E_NVAL_DATE 											8 
#define ERR_FRMDT_CANT_GRTR_TODT 						9 
#define ERR_FILE_NOTFND 									10 
#define E_FILE_EMPTY 										11 
#define E_FILE_NTXTFORMAT 									12 
#define ERR_TIME_NOTPOS_FUTURE 							13 
#define ERR_NOTHING_RESET 									14 
#define ERR_DATE_IS_HOLIDAY 								15 
#define E_DT_CANT_EMPTY 									16 
#define ERR_CANT_GEN_SEQNO 								17 
#define E_FROMVAL_GREATER_TOVAL 							18 
#define ERR_VAL_NF 											19 
#define ERR_VALUES_Y_N_BLANK_A 							20 
#define ERR_DATE_CANT_FUTURE 								21 
#define ERR_ACCESSSTAMP_CHGD 								22 
#define DB_ERR_NO												23 
#define ERR_DATA_INTEGRITY 								24 
#define ERR_ACCNOT_FND 										25 
#define ERR_ACCNOT_CUSTOMER 								26 
#define ERR_ACCOUNT_CANT_REGSTR 							27 
#define ERR_ACCOUNT_MARKEDFORDEL 						28 
#define ERR_ACCOUNT_UNAUTH 								29 
#define ERR_ACCOUNT_FRZN 									30 
#define ERR_ACCOUNT_CLOSED 								31 
#define E_NVAL_IBBSACC 										32 
#define ERR_ACCOUNT_EXST 									33 
#define ERR_SUBACC_EXISTS_FORMASTACC 					34
#define E_ACC_INPCBACC_FIRST 								35
#define E_ACC_INPCBBRKG_FIRST 							36
#define E_ACC_BASENUM_NRANGE 								37 
#define E_ACC_REGNUM_CANT_EMPTY 							38 
#define ERR_VTB_CLI_CANT_EMPTY 							39 
#define ERR_CLHACCOUNT_CANT_EMPTY 						40 
#define E_ACC_CNTRYCD_CANT_EMPTY 						41 
#define E_ACC_DOMI_CANT_EMPTY 							42 
#define DUMMY_ERR_NO12										43 
#define E_ACC_CLSCD_CANT_EMPTY 							44 
#define E_ACC_SHRTNM_CANT_EMPTY 							45 
#define ERROR_CLIENT_OT_CANT_EMPTY 						46 
#define E_ACC_CUSTBROKALL_CANT_EMPTY 					47 
#define E_ACC_IBBSACC_CANT_EMPTY 						48 
#define E_ACC_CANT_EMPTY 									49 
#define ERR_MASTACC_CANT_EMPTY 							50 
#define E_ACC_CORPNM_CANT_EMPTY 							51 
#define E_ACC_CLNTTYP_CANT_EMPTY 						52 
#define E_ACC_CUSTBRKGALL_CANT_EMPTY 					53 
#define E_ACC_NVAL_MSGNM 									54 
#define ERR_CLT_VALMSTYP_S_T_C_F 						55 
#define E_ACC_MSGFREQ_DLYMNTH 							56 
#define E_ACC_MSGADDR_CANT_EMPTY 						57 
#define ERR_ACCNOT_VALIDMSG_CATEGORY 					58 
#define ERR_ACCNOT_BRK 										59 
#define ERR_ACCNOT_DEALER 									60 
#define ERR_ACCNOT_CUSTODYCLIENT 						61 
#define ERR_ACCNOT_BRKCLIENT 								62 
#define ERR_ACCNOT_BRKANDCUSTODYCLIENT 				63 
#define ERR_ACCNOT_MASTER 									64 
#define ERR_ACCOUNT_ISMASTER 								65 
#define ERR_MSG_ACCOUNT_AUTH 								66 
#define ERR_ACCNOT_MARKEDFORDEL 							67 
#define ERR_ACCNOT_FRZN 									68 
#define ERR_ACCNOT_CLOSED 									69 
#define ERR_ACCORD_EXISTS_CANTCHGTO_CUSTODY 			70 
#define ERR_TRDSEXIST_CANTCHGTO_BRKCLIENT 			71 
#define ERR_ACCOUNT_ISCNTRPARTY_CANT_CHG_TOCUST 	72 
#define ERR_TRDSEXIST_CANTCHGTO_BRK 					73 
#define ERR_ORDEXIST_CANT_CHGTO_BRK 					74 
#define ERR_POSNEXIST_CANT_CHGTO_BRK 					75 
#define ERR_ENTITLEEXISTS_CANTCHG_TOBRK 				76 
#define ERR_BILL_FORACC_CANTCHG_BRKCLIENT 			77 
#define ERR_ACCOUNT_BTWN_GEN_AND_DELV_CANTCHG_FLAG 78 
#define ERR_BILL_FORACC_CANTCHG_BILLFLAG 				79 
#define ERR_INTRNL_ACC_CANT_DEL 							80 
#define ERR_INTRNL_BRKACC_CANT_DEL 						81 
#define ERR_VTBACC_CANTDEL 								82 
#define ERR_ACCOUNT_MARKEDFORUNFRZN 					83 
#define ERR_ACCOUNT_MARKEDFORREPON 						84 
#define ERR_ENTITLE_EXSTINACC_CANT_DEL 				85 
#define ERR_BILL_FORACC_CANT_DEL 						86 
#define ERR_TRDSEXIST_CANTDEL 							87 
#define ERR_ACCPOSN_EXISTS_CANTDEL 						88 
#define ERR_ACCORD_EXISTS_CANTDEL 						89 
#define ERR_CNTRPARTY_ACC_CANT_DEL 						90 
#define ERR_SUBACC_EXISTS_CANTDEL 						91 
#define ERR_INTRNL_ACC_CANT_CLOSE 						92 
#define ERR_INTRNL_BRKACC_CANT_CLOSE 					93 
#define ERR_VTBACC_CANTCLOSE 								94 
#define ERR_ENTITLE_EXSTINACC_CANT_CLOSE 				95 
#define ERR_BILL_FORACC_CANT_CLOSE 						96 
#define ERR_ACCPOSN_EXISTS_CANTCLOSE 					97 
#define ERR_ACCORD_EXISTS_CANTCLOSE 					98 
#define ERR_TRDSEXIST_CANTCLOSE 							99 
#define ERR_CNTRPARTY_ACC_CANT_CLOSE 					100 
#define ERR_SUBACC_EXISTS_CANTCLOSE 					101 
#define ERR_INTRNL_ACC_CANT_FREEZE 						102 
#define ERR_INTRNL_BRKACC_CANT_FREEZE 					103 
#define ERR_VTBACC_CANTFRZN 								104 
#define E_ACC_MSGTYP_CANT_TLX 							105 
#define ERR_ACCOUNT_ADV_NTALLOWED 						106 
#define ERR_SPOTTRD_NOTALLOWED_FORACC 					107 
#define ERR_ACCOUNT_BRK_ORD_CANT_CLOSE 				108 
#define ERR_ACCOUNT_BRK_ORD_CANT_DEL 					109 
#define ERR_INSTR_NOTFND									110 
#define ERR_UNAUTH_INSTR									111 
#define ERR_INSTRUMENT_FRZN 								112 
#define ERR_INSTR_MARKEDDEL 								113 
#define ERR_NOTREGDINSTR 									114 
#define E_INSTR_FROMINSTR_CANT_TOINSTR 				115 
#define ERR_INSTR_CANT_CONVERT 							116 
#define ERR_ORDEXIST_CANT_CONV_INSTR 					117 
#define ERR_PYMNTTRDEXIST_CANT_CONV_INSTR 			118 
#define ERR_DLVTRDEXIST_CANT_CONVERTINSTR 			119 
#define ERR_INSTRUMENT_EXIST 								120 
#define ERR_INSTR_AUTHORIZED 								121 
#define ERR_INSTR_NOTMARKEDDEL 							122 
#define ERR_INSTR_NOTFRZN 									123 
#define ERR_INSTR_NOTMOTHERINSTR 						124 
#define ERR_INSTR_MOTHERINSTR 							125 
#define E_INSTR_NAME_CANT_EMPTY 							126 
#define E_INSTR_NOMVAL_SHLD_POS 							127 
#define E_INSTR_PAIDUPCA_SHLD_POS 						128 
#define E_INSTR_THRSHOLD_CANT_NEG 						129 
#define E_INSTR_RGBRIND_CANT_EMPTY 						130 
#define ERR_INSTR_RG_BR 									131 
#define E_INSTR_TIPOINV_CANT_EMPTY 						132 
#define E_TYPEOFINSTROFINSTR_CANT_EMPTY 				133 
#define E_INSTR_PRODTYP_CANT_EMPTY 						134 
#define E_INSTR_ISINCD_CANT_EMPTY 						135 
#define E_INSTR_PARENTINSTR_CANT_EMPTY 				136 
#define E_INSTR_NEWISSUE_CANT_EMPTY 					137 
#define E_INSTR_COMPNM_CANT_EMPTY 						138 
#define E_INSTR_COMPADDR_CANT_EMPTY 					139 
#define ERR_ISSUEDT_CANT_GRTR_LASTPAYDT 				140 
#define ERR_ISSUEDT_CANT_GRTR_MATURITYDT 				141 
#define E_INSTR_INTTYP_CANT_EMPTY 						142 
#define E_INSTR_PAYFREQ_CANT_EMPTY 						143 
#define E_INSTR_INTCALCTYP_CANT_EMPTY 					144 
#define E_INSTR_LSTPYDT_CANT_AFTER_MATURDT 			145 
#define ERR_LASTPAYDT_CANT_GRTR_NXTPAYDT 				146 
#define ERR_ISSUEDT_CANT_GRTR_NXTPAYDT 				147 
#define ERR_INSTR_NXTPYDT_CANT_GRTR_MATURITYDT 		148 
#define ERR_ISINCD_CANT_LESS_12CHAR 					149 
#define E_INSTR_NVAL_INVTYP_INSTRTYPCOMBO 			150 
#define E_INSTR_NVAL_INSTRTYP_PRODTYPCOMBO 			151 
#define E_INSTR_PARENTINSTR_CANT_SAME_INSTR 			152 
#define ERR_INSTR_NOTUNDERCONV 							153 
#define ERR_UNDERCONV_INSTR 								154 
#define ERR_TRDEXIST_CANTCHG_BR_INSTR 					155 
#define ERR_POSNEXIST_CANTCHG_BR_INSTR 				156 
#define ERR_ORDEXIST_CANT_CLSCODE 						157 
#define ERR_EVNTEXIST_CANTCHG_CLSCODE 					158 
#define ERR_PYMNTTRDEXIST_CANT_CLSCODE 				159 
#define E_INSTR_SELLORDEXIST_CANTCHG_CLSCD 			160 
#define ERR_DLVTRDEXIST_CANT_CHGCLSCODE 				161 
#define ERR_EVNTEXIST_CANTCHG_TYPEOFINSTR			 	162 
#define ERR_BTWNGENDELV_CANTCHG_PRODTYPE 				163 
#define ERR_BTWNGENDELV_CANTCHG_INSTRCCY 				164 
#define ERR_EVNTEXIST_CANT_DEL 							165 
#define ERR_CHILDINSTREXIST_CANTDEL_INSTR 			166 
#define ERR_TRDEXIST_CANT_DEL_INSTR 					167 
#define ERR_PYMNTTRDEXIST_CANT_DEL_INSTR 				168 
#define ERR_EVNTEXIST_CANTCHG_ISSUEDT 					169 
#define ERR_EVNTEXIST_CANTCHG_NOMVAL				 	170 
#define ERR_EVNTEXIST_CANTCHG_INTCALCTYPE 			171 
#define ERR_LOCALREP_POSN_EXIST_CANTDEL_INSTR 		172 
#define ERR_REGDINSTR 										173 
#define E_INSTR_CANT_EMPTY 								174 
#define ERR_LOCN_NOTFND 									175 
#define ERR_LOCN_NOT_AUTHORIZED 							176 
#define ERR_LOCN_EXISTS 									177 
#define ERR_LOCN_MARKED_DEL 								178 
#define ERR_LOCN_CANT_DEL 									179 
#define ERR_LOCN_AUTHORIZED 								180 
#define ERR_LOCN_NOTMARKED_DEL 							181 
#define E_LOC_CANT_EMPTY 									182 
#define ERR_CCY_EXISTS 										183 
#define ERR_CANTDEL_DOMCCY 								184 
#define ERR_CCY_CANTDEL_USD 								185 
#define ERR_DFLT_BILLCCY_CANT_DELETE 					186 
#define ERR_CANTDEL_CCYINUSE 								187 
#define E_CCY_NVAL_ISOCCY 									188 
#define ERR_CCY_NOTFND 										189 
#define E_CCY_NOT_EMPTY 									190 
#define ERR_EXCHGRATE_EXISTS 								191 
#define ERR_EXCHGRATE_AUTHORIZED 						192 
#define ERR_EXCHGRATE_NOTFND 								193 
#define ERR_EXCHGRATE_UNAUTHORIZED 						194 
#define E_ACCEN_NRST 										195 
#define E_SECTR_CANT_EMPTY								 	196 
#define ERR_WHT_EXIST 										197 
#define E_WHT_NF 												198 
#define ERR_WHT_MARKDEL 									199 
#define ERR_WHT_AUTH 										200 
#define ERR_WHT_NMARKDEL 									201 
#define ERR_WHT_UNAUTH 										202 
#define ERR_BILLACC_EXISTS 								203 
#define ERR_BILLACC_FIRST 									204 
#define ERR_BILLACC_AUTHORIZED 							205 
#define ERR_BILLACC_NOT_LOCCALCCY 						206 
#define ERR_ORD_EXECUTED 									207 
#define ERR_ORD_NOTEXECUTED 								208 
#define E_ORD_QTY_CANTMORE_ORDQTY 						209 
#define E_ORD_TRDDT_CANTLESS_ORDDT 						210 
#define E_ORD_BREAKDNQTY_CANTMORE_TOTALQTY 			211 
#define ERR_ORD_INSTRPRICE_CANT_MORE_LIMITPRICE 	212 
#define ERR_ORD_INSTRPRICE_CANT_LESS_LIMITPRICE 	213 
#define E_ORD_CALCCOUNTVAL_NEG 							214 
#define ERR_ORD_INSUFF_CASHBAL 							215 
#define ERR_ORD_INSUFF_CASHBAL_CANT_RESET 			216 
#define ERR_ORD_NOTFND 										217 
#define ERR_ORD_EXISTS 										218 
#define ERR_ORD_NOT_AUTHORIZED 							219 
#define ERR_ORD_AUTHORIZED 								220 
#define ERR_ORD_NOTMARKEDDEL 								221 
#define ERR_ORD_MARKEDDEL 									222 
#define E_ORD_NMARKCANCEL 									223 
#define E_ORD_MARKCANCEL 									224 
#define ERR_ORD_NOT_CANC 									225 
#define ERR_ORD_CANC 										226 
#define DUMMY_ERR_NO11 										227 
#define DUMMY_ERR_NO10 										228 
#define ERR_ORD_NOTFULLY_EXECUTED 						229 
#define ERR_ORD_FULLY_EXECUTED 							230 
#define E_ORD_NPARTEXEC 									231 
#define ERR_ORD_PARTLY_EXECUTED 							232 
#define ERR_ORD_NOTEXPIRED	 								233 
#define ERR_ORD_EXPIRE 										234 
#define ERR_ORD_VAL_B_S 									235 
#define ERR_DEAL_NENUFPOSN 								236 
#define ERR_DEAL_LOCREFNO_EXIST 							237 
#define ERR_DEAL_INVALID_POSNTYPE 						238 
#define ERR_DEAL_NF	 										239 
#define ERR_DEAL_EXIST 										240 
#define ERR_DEAL_NO_RESET_CHLD_CONF 					241 
#define ERR_DEAL_SETLDT_BEFORE_DEALDT 					242 
#define ERR_DEAL_NENUFPOSN_CANTRST 						243 
#define ERR_DEAL_UNAUTH 									244 
#define ERR_DEAL_AUTH 										245 
#define ERR_DEAL_NMARKDEL 									246 
#define ERR_DEAL_MARKDEL 									247 
#define ERR_DEAL_NCONF 										248 
#define ERR_DEAL_CONF 										249 
#define ERR_DEAL_NSETL 										250 
#define ERR_DEAL_MONSETL 									251 
#define ERR_DEAL_INSTRSETL 								252 
#define ERR_DEAL_NINSTRSETL 								253 
#define ERR_DEAL_NMONSETL 									254 
#define ERR_DEAL_NPARTCONF 								255 
#define ERR_DEAL_PARTCONF 									256 
#define ERR_DEAL_RCVTKT_NPRINT 							257 
#define ERR_DEAL_DELTKT_NPRINT 							258 
#define ERR_DEAL_TMPOUTTKT_NPRINT 						259 
#define ERR_DEAL_TMPRETTKT_NPRINT 						260 
#define ERR_DEAL_DOMCP_LOCAL 								261 
#define ERR_DEAL_DOMCP_FOREIGN 							262 
#define ERR_DEAL_DEALTYP_NVALFORINSTR_A 				263 
#define ERR_DEAL_NO_RESET_CHLD_EXISTS 					264 
#define ERR_DEAL_LOCREFNO_CANTEMPTY 					265 
#define ERR_DEAL_REFNO_CANTEMPTY 						266 
#define ERR_DEAL_DEALDT_CANTEMPTY 						267 
#define ERR_DEAL_SETLDT_CANTEMPTY 						268 
#define ERR_DEAL_DEALTYP_NVALFORINSTR 					269 
#define ERR_DEAL_DEALTYP_NVALFORTRANSTYP 				270 
#define ERR_TRDL_LRDEALTYP_NVALFORTRANSTYP 			271 
#define ERR_DEAL_LRDEALTYP_NVALFORACC 					272 
#define ERR_DEAL_COUNTVAL_SHLD_POS 						273 
#define ERR_DEAL_SETL 										274 
#define ERR_DEAL_CP_CANTSAME_CLI 						275 
#define ERR_DEAL_FAILCD_CANT_EMPTY 						276 
#define ERR_DEAL_CONFDT_MAND 								277 
#define ERR_DEAL_CONFDT_NO_DEALDT 						278 
#define ERR_DEAL_DIFFAMT_MORE_SETUP 					279 
#define ERR_DEAL_QTY_CANT_EMPTY 							280 
#define ERR_DEAL_QTY_SHLD_LESS_ORIGQTY 				281 
#define ERR_DEAL_AMT_MUST_LESS_ORIGAMT 				282 
#define ERR_DEAL_VERWITH_CANT_EMPTY 					283 
#define ERR_DEAL_NVAL_VERWITH_CZ 						284 
#define ERR_DEAL_NENUF_VDP 								285 
#define ERR_DEAL_NDSDT_CANT_LESS_FINALEXECDT 		286 
#define ERR_DEAL_BLKCONF_CANTLESS_EXECCONF 			287 
#define ERR_DEAL_MANIFLD_NPRINT 							288 
#define ERR_DEAL_DT_CANT_LESS_DLDTOFPARENT 			289 
#define ERR_DEAL_QTY_CANT_MORE_AVAILQTY 				290 
#define ERR_DEAL_INSTR_DT_CANT_EMPTY 					291 
#define ERR_DEAL_MONEYDT_CANT_EMPTY 					292 
#define ERR_DEAL_INSTR_DT_CANT_BEFORE_CSD 			293 
#define ERR_DEAL_MONEYDT_CANT_BEFORE_CSD 				294 
#define ERR_DEAL_INSTR_DT_CANT_BEFORE_CONFDT 		295 
#define ERR_DEAL_MONEYDT_CANT_BEFORE_CONFDT 			296 
#define ERR_DEAL_TOTQTY_CANT_MORE_DEALQTY 			297 
#define ERR_DEAL_QTY_CANT_MORE_TRDQTY 					298 
#define ERR_DEAL_MONEYDT_CANT_AFTER_INSTR_DT 		299 
#define ERR_DEAL_MONEYDT_CANT_BEFORE_INSTR_DT 		300 
#define ERR_DEAL_ONLYPAYTRD_ALLOW 						301 
#define ERR_DEAL_NVAL_TKTTYP	 							302 
#define ERR_STATUS_CLSCD_MAND 							303 
#define ERR_STATUS_CLSCD_NOTFND 							304 
#define ERR_STATUS_RGBR_VALS 								305 
#define ERR_STATUS_TIPOENV_NOTFND 						306 
#define ERR_STATUS_EX_ARENA_MAND 						307 
#define ERR_STATUS_EX_ARENA_NOTFND 						308 
#define ERR_STATUS_NEWISSUECD_NOTFND 					309 
#define ERR_STATUS_INTERESTTYP_NOTFND 					310 
#define ERR_STATUS_PAYFRQ_NOTFND 						311 
#define ERR_STATUS_INTERESTCALCTYP_MAND 				312 
#define ERR_STATUS_TRANSTYP_INVALID 					313 
#define ERR_STATUS_TRDTYP_INVALID 						314 
#define ERR_STATUS_LRTRDTYP_INVALID 					315 
#define ERR_STATUS_FAILCODE_INVALID 					316 
#define ERR_STATUS_REGSTATUS_INVALID 					317 
#define DUMMY_ERR_NO9										318 
#define ERR_LASTBILLDT_CANT_IN_FUTURE 					319 
#define E_MAKER_SAME  										320 
#define E_LST_BDT_MAND 										321 
#define E_NXT_BDT_MAND 										322 
#define E_DEL_DT_MAND  										323 
#define ERR_BILLCNTRL_PARAM_EXIST 						324 
#define ERR_NXTBILLDT_CANT_LESS_LASTBILLDT 			325 
#define ERR_PROCDT_LESS_LASTBILLDT     				326 
#define ERR_PROCDT_GRTR_NXTBILLDT 						327 
#define ERR_BILLDELVDT_CANT_LESS_NXTBILLDT 			328 
#define ERR_FEES_EXIST 										329 
#define ERR_BILL_BTWGENDELV_CANTCHG_CCY   			330 
#define ERR_SERVCODE_GRTR_ZERO   						331 
#define ERR_SRVCODE_EXISTS  								332 
#define ERR_SERVDESC_CANT_EMPTY 							333 
#define ERR_INVALID_FEE   									334 
#define ERR_ACCTYPE_INVALID   							335 
#define DUMMY_ERR_NO8 										336 
#define E_CHG_FEE_IN_TYPE 									337 
#define ERR_INVALID_SERVCODE   							338 
#define E_FEE_TYPE_MISMATCH 								339 
#define ERR_SERV_STANDARD 									340 
#define ERR_SERV_FEE_EXISTS 								341 
#define ERR_SERV_NO_BILL    								342 
#define ERR_OSAMT_GRTR_ZERO  								343 
#define ERR_BILLPARAM_NOTFND  							344 
#define ERR_UB_OB_NA 										345 
#define ERR_AMT_CANTNEGATIVE  							346 
#define ERR_SERV_POS_QTY  									347 
#define ERR_MINFEE_GRTR_ZERO  							348 
#define ERR_FEE_SLAB_EXISTS 								349 
#define ERR_BILLCNTRL_PARAM_NOTFND 						350 
#define E_CUST_NBL   										351 
#define E_CUST_NPERIOD 										352 
#define DUMMY_ERR_NO7										353 
#define DUMMY_ERR_NO6										354 
#define ERR_INTRNL_BILLTYPE  								355 
#define ERR_BILLDLV_NOTDUE  								356 
#define ERR_GPSSFILE_NOTGEN 								357 
#define ERR_ACTGENTRY_NOTGEN  							358 
#define ERR_UNAUTH_CLIENT  								359 
#define ERR_NILFEE_GRTR_ZERO 								360 
#define ERR_MAXFEE_GTR_ZERO 								361 
#define ERR_BILLLEDGER_DATA_INTEGRITY 					362 
#define DUMMY_ERR_NO5										363 
#define ERR_BILLACC_NOTAUTHORIZED 						364 
#define E_ACCT_CITIBRK  									365 
#define ERR_CUST_CANT_PAYMNTS 							366 
#define ERR_INVALID_PAYMNT  								367 
#define DUMMY_ERR_NO4										368 
#define ERR_BILLCCY_PAYMNTCCY_MISMATCH 				369 
#define ERR_PAYAMT_GRTR_ZERO  							370 
#define DUMMY_ERR_NO3										371 
#define E_FEE_NF 												372 
#define DUMMY_ERR_NO2										373 
#define ERR_SCHFEE_GRTR_ZERO 								374 
#define ERR_MSTACC_NOTBILL 								375 
#define E_BTM_NCHG 											376 
#define ERR_BILLS_NOT_DELVD 								377 
#define ERR_CHRGFEE_CANTBE_FORSERV 						378 
#define E_OSAMT_NPOSITIVE 									379 
#define ERR_ACCC_NOTSELF    								380 
#define ERR_UNAUTH_CLI_EXISTS 							381 
#define ERR_UNAUTH_PAY_EXISTS    						382 
#define DUMMY_ERR_NO1										383 
#define ERR_BILLS_NOT_GENERATED 							384 
#define ERR_ACTGENTRY_GEN  								385 
#define DUMMY_ERR_NO											386 
#define ERR_BILLTOMAST_EXISTS_CANT_DELACC  			387 
#define ERR_RGENBILLS_FORACCOUNT 						388 
#define E_BGEN_NDUE  										389 
#define ERR_MRKTPRICE_NOTFND 								390 
#define ERR_NO_MEMORY										391
#define ERR_DATE_NOT_SET									392
#define ERR_FOOTNOTE_NOTFND								393
#define E_DUP_EX_DATE										394
#define ERR_INVALID_ARGUMENT								395
#define ERR_INVALID_CODE									396
#define ERR_DUPLICATE_EVENT								397
#define ERR_NO_NXT_SEQNO									398
#define ERR_HOLIDAY_NOTFND 								399	
#define ERR_HOLIDAY_UNAUTHORIZED 						400	
#define ERR_HOLIDAY_EXISTS 								401	
#define ERR_HOLIDAY_MARKEDDEL 							402	
#define ERR_HOLIDAY_AUTHORIZED 							403	
#define ERR_HOLIDAY_NOTMARKEDDEL 						404	
#define ERR_DEAL_NVAL_NDSCONF 							405
#define ERR_DEAL_NVAL_NDSBLCK								406
#define ERR_DEAL_LRDEALTYP_EMPTY 						407
#define ERR_DEAL_NDSCONF 									408
#define ERR_DEAL_NDSBLCKCONF 								409
#define ERR_REC_EXIST 										410
#define ERR_PARTIAL_NOTALLOWED 							411
#define ERR_EVNT_NOTFND_A									412
#define	ERR_INVALID_EVNTINSTR_COMB						413
#define ERR_DUPLICATE_EVENTIMG							414
#define ERR_RES_INSTR_INVALID								415
#define ERR_NOINT_DISCOUNT_BOND							416
#define ERR_EVNTIMG_NOTFND									417
#define ERR_DECLDT_CANT_FUTURE							418
#define ERR_MEETDT_CANT_PAST								419
#define ERR_MEETDT_CANT_BEFORE_PROXYDT					420
#define E_EX_DT_CANT_BEFORE_DECL_DT						421
#define E_PAY_DT_CANT_BEFORE_DECL_DT					422
#define ERR_RESPDT_CANT_BEFORE_RECDT					423
#define ERR_EXPIRYDT_CANT_LESS_RESPONSEDT				424
#define E_DUP_PAY_DATE										425
#define ERR_EVNT_STS_INVALIDCHG							426
#define ERR_EVNT_STS_INVALIDDEL							427
#define ERR_EVNT_STS_INVALIDREVERSE						428
#define ERR_EVNT_STS_INVALIDFRZ							429
#define ERR_EVNT_STS_INVALIDUNFRZ						430
#define ERR_EVNT_AUTHORIZED								431
#define	ERR_TIPOINSTRU_NOTFND							432
#define ERR_DISFLAG_NOTFND									433
#define ERR_RECMOD_DIFFUSER								434
#define ERR_EVNTSTS_INVALID								435
#define ERR_ENTITLESTS_INVALID							436
#define ERR_EVNT_FOR_PAYMNT_NOTFND						437
#define ERR_ENTITLE_FORPYMNT_NOTFND						438
#define ERR_DUPLICATE_PYMNT								439
#define ERR_PAYMNT_NOTFND_A								440
#define ERR_DUPLICATE_PYMNTIMG							441
#define ERR_PAYMNTSTS_INVALIDREVERSE					442
#define ERR_PAYMNTSTS_INVALIDDEL							443
#define ERR_NOPAY_INCDUE									444
#define ERR_NOPAY_QTYDUE									445
#define ERR_PAYDT_CANT_BEFORE_RECDT						446
#define ERR_PAY_MORE_DUES_CASH_SUM						447
#define ERR_PAY_MORE_DUES_STOCK_SUM						448
#define ERR_CASH_PYMT_GRTR_ENTITLE_DUE					449
#define ERR_PAY_MORE_DUES_STOCK							450
#define E_CANT_SEND_EVNT_REV_MSG							451
#define E_CANT_SEND_ENTITL_REV_MSG						452
#define ERR_UNREV_ENTITL_CANT_REV_EVNT					453
#define ERR_UNREV_PYMT_CANT_REV_EVNT					454
#define ERR_DEAL_NVAL_VERWITH_HU 						455	
#define ERR_DEAL_NVAL_NOTE1_HU							456
#define E_HOL_WKLYOFFS_EXIST								457
#define ERR_DEAL_CSD_MINUS_10_CANT_GT_TODAY 			458
#define ERR_DEAL_MONEYDT_MINUS_9_CANT_AFTER_TODAY 	459
#define ERR_DEAL_NO_SETL_BEFORE_CSD 					460
#define ERR_DEAL_INSTR_DT_CANT_FUTURE 					461
#define ERR_DEAL_MONEYDT_CANT_FUTURE 					462
#define ERR_DEAL_INSTR_DT_CANT_BEFORE_TRDT 			463
#define ERR_DEAL_MONEYDT_CANT_BEFORE_DLDT 			464
#define ERR_DEAL_INSTR_DT_NOTEQUAL_MONEYDT 			465
#define ERR_DEAL_INSTR_DT_CANTEQUAL_MONEYDT 			466
#define ERR_DEAL_MANIFLD_PRINTED 						467
#define ERR_DEAL_PARENT_CONF 								468
#define ERR_PAYMNT_AUTHORIZED_A							469
#define ERR_PAYMNTIMG_NOTFND								470
#define ERR_PAYMNTSTS_INVALIDCHG							471
#define ERR_DEAL_APL_GEN_CANTDEL							472
#define ERR_DEAL_REP_TO_CLH_CANTDEL						473
#define ERR_DEAL_NO_DEL_CONFFROMORD						474
#define ERR_HOLIDAY_UNAUTH_WKLYOFF_EXIST				475
#define ERR_SERV_EXISTS 									476
#define E_PAY_DT_MAND 										477
#define ERR_PAYDT_CANT_FUTURE 							478
#define E_CUST_NPAY 											479
#define ERR_SEQNO_GRTR_ZERO 								480
#define ERR_PAYMNT_NOTFND 									481
#define ERR_PAYMNT_AUTHORIZED 							482 
#define ERR_PAYMNT_MARKEDDEL 								483
#define ERR_DEAL_DLDT_CANT_FUTURE						484
#define ERR_DEAL_CSD_CANT_BEFORE_DEALDT				485
#define ERR_DEAL_MANI_NOT_REQD							486
#define ERR_DEAL_NNDSBLCKCONF 							487
#define ERR_DEAL_NENUFPOSN_RST_NALLOW					488
#define ERR_DEAL_TXNINREG_RST_NALLOW					489
#define ERR_DEAL_INSTRCONV_RST_NALLOW					490
#define ERR_DEAL_SPOTDEAL_RST_NALLOW					491
#define ERR_DEAL_EXECERR_NEQUAL_RST_NALLOW			492
#define ERR_DEAL_EXECERR_GRTR_RST_NALLOW				493
#define ERR_DEAL_FREEDEAL_RST_NALLOW					494
#define ERR_DEAL_QTYREG_NEQUAL_TOTQTY					495
#define ERR_DEAL_QTYMCL_NEQUAL_TOTQTY					496
#define ERR_DEAL_QTYPND_NEQUAL_TOTQTY	 				497
#define ERR_DEAL_CANT_PARSETL								498
#define ERR_DEAL_CANT_RECINT000							499
#define ERR_NO_DR_CTX										500
#define ERR_WHT_SHLD_BETN_0_AND_100						501
#define ERR_CANT_RESET										502
#define ERR_WKLYOFFDT_SAME									503
#define ERR_INSTR_ISIN_EXISTS								504
#define ERR_DEAL_EXECERR_LESS_RST_NALLOW 				505
#define ERR_BILLPARAM_EXISTS 								506
#define ERR_INVALID_COMMACC 								507
#define ERR_INVALID_APACODE 								508
#define ERR_BILLTO_SORM  									509
#define E_MIN_FEE_VAL 										510
#define ERR_MINCONSO_VALID 								511
#define ERR_MSTACC_BILLTYPE 								512
#define ERR_FEES_EXIST_CANTDEL_ACC 						513
#define ERR_BILL_CANT_MODIFY_CCY 						514
#define E_CHG_FEE_BASIS_NF 								515
#define ERR_INVALID_CHRGFEE_TYPE 						516
#define ERR_INVALID_CHRGFEE_BASIS 						517
#define ERR_INVALID_SERVDEP 								518
#define ERR_INVALID_FROMVAL_FORCHRG 					519
#define ERR_SRVBASIS_NOTFND 								520
#define ERR_BTWGENDELV_CANTDEL_FEE 						521
#define ERR_INSTRCYCLIC_CONV 								522
#define ERR_DEAL_LOC_MAN_NALLOW							523
#define ERR_DEAL_MANIFLD_PRINT							524
#define ERR_DEAL_CANT_MANI_RUMIN							525
#define ERR_DEAL_CANT_MANI_DLV							526
#define ERR_DEAL_MANQTY_NAVAIL							527
#define ERR_DEAL_MANQTY_NEQ_AVAILQTY					528
#define ERR_DEAL_NOTHING_REG	         				529
#define ERR_DEAL_SYSGEN_CANT_RST      					530
#define ERR_DLVRTRD_CANT_RESET      					531
#define ERR_RECVTRD_CANT_RESET      					532
#define ERR_DUPLICATE_SWIFTTLX_ADDR 					533
#define ERR_TOTAL_SERVICE_PAY_IN 						534
#define ERR_PURGE_RECALL_PR 								535
#define ERR_SERV_PAY_NOTFND 								536
#define ERR_INVALID_PAYCCY 								537
#define ERR_MSGADDR_NOTFND 								538
#define ERR_PAYMNT_EXISTS 									539
#define ERR_DEL_TOTPYMT_NOTALLOWED  					540
#define ERR_SERVPYMNT_NOTALLOWED 						541
#define ERR_FIRSTSERV_PAYMNTVAL 							542
#define ERR_SERV_NO_DEL_PAY 								543
#define ERR_REC_LEDGER_EXIST  							544
#define ERR_LOCN_SAME 										545
#define ERR_NOTHING_REPORT 								546
#define ERR_BILLSYSSETUP_PARAMS_NOTFND 				547
#define ERR_EVNT_NOTFND										548
#define ERR_SNDVAL_S_M  									549
#define ERR_SERVDEP_NOTFND  								550
#define ERR_OTHRSERV_NOTBILLED_CANT_DELACC 			551
#define ERR_UNAUTH_PAYM_CLI_NDEL 						552
#define ERR_OSAMT_EXIST_CANT_DELACC 					553
#define ERR_BTWNGENDELV_CANTCHG_BILLSND  				554
#define E_FEE_SLB_CHG_IN  									555
#define E_FEE_SLB_DEL_IN  									556
#define ERR_ACCOUNT_BTWN_GEN_AND_DELV_CANT_DEL 		557
#define ERR_UNAUTH_PAYM_CURR_NCHG  						558
#define ERR_INVALID_FROMVAL_FORFEE 						559
#define E_OS_AMT_CURR_NCHG  								560
#define E_OTH_SRV_CURR_NCHG  								561
#define ERR_INVALID_DIRDR 									562
#define ERR_SERV_PAYMENT_EXISTS 							563
#define ERR_MRKTPRICE_EXISTS        					564 
#define ERR_MRKTPRICE_AUTHORIZED							565 
#define ERR_INVALID_DATAVAL								566
#define ERR_INSTR_NOTUNDERCHG								567
#define ERR_ORD_EXEC_TODAY									568
#define ERR_OTHERSERV_CANT_DEFINEFOR_INTRNLACC  	569
#define ERR_OTHRSERV_DELETED  							570
#define ERR_OTHRSERV_AUTHORIZED  						571
#define E_OTH_SRV_MRK_DEL 									572
#define ERR_OTHRSRVCCY_INVALID 							573
#define ERR_FDFILE_NOTVALID								574
#define ERR_FDFILE_NCURR_PRC								575
#define ERR_BILLACC_CANT_DEFINE 							576
#define ERR_SERVDESC_NOTCHGD 								577
#define ERR_INVALID_FEETYPE 								578
#define ERR_OTHRSERV_NOTFND 								579
#define ERR_ENTITLESTS_INVALIDCHG						580
#define ERR_ENTITLESTS_INVALIDDEL						581
#define ERR_ENTITLESTS_INVALIDREVERSE  				582
#define ERR_ENTITLESTS_INVALIDFRZ						583
#define ERR_ENTITLESTS_INVALIDUNFRZ						584
#define ERR_ENTITLE_AUTHORIZED					   	585
#define E_RECDT_NOT_OVER									586
#define ERR_INCDUE_LESS_AMTRECED    					587
#define ERR_QTYDUE_LESS_QTYRECED    					588
#define ERR_INCDUE_LESS_SUMCASHPAYMNT    				589
#define ERR_QTYDUE_LESS_SUM_STKPAYMNT     			590
#define ERR_UNREV_PYMT_CANT_REV_ENT		  				591	
#define W_UNREV_UNCLOSED_EVNT_EXIST	  					592	
#define W_UNAUTH_RTS_EXIST		  		  					593	
#define ERR_UNREV_UNCLOSED_EVNT_EXIST	  				594	
#define ERR_UNAUTH_RTS_EXIST		  		  				595	
#define ERR_DUPLICATE_FOOTNOTE						  	596
#define ERR_DUPLICATE_ENTITLE							  	597
#define ERR_DUPLICATE_ENTITLEIMG						  	598
#define ERR_EVNT_FOR_ENTITL_NOTFND					  	599
#define ERR_ENTITLE_NOTFND					 			  	600 
#define ERR_ENTITLEIMG_NOTFND			 			  		601
#define ERR_REC_MARKEDDEL			 			  			602
#define ERR_REC_AUTHORIZED									603
#define ERR_BILLCCY_ACCRECEVCCY_MISMATCH 				604
#define ERR_INVALID_RECEABLEACC 							605
#define ERR_FEE_SLAB_NOTFND 								606
#define ERR_BATCHNO_NOTFND 								607
#define ERR_MSG_CREFNO_NOTFND 							608
#define ERR_MSG_NOTGENERATED 								609
#define ERR_HANDOFFFILE_NOTGEN 							610
#define ERR_ORDEXIST_CANT_DEL_INSTR 					611
#define ERR_INSTREXIST_CANTDEL 							612
#define ERR_MINFEE_HLD_VALID 								613
#define ERR_MINFEE_CONSO_VALID 							614
#define ERR_EVNT_BNDREDM							  		615
#define ERR_PAYDT_CANT_BEFORE_MATUREDT  				616
#define ERR_MATUREDT_PAST					  				617
#define ERR_RECDT_CANT_BEFORE_EXDT      				618
#define ERR_PAYDT_CANT_BEFORE_RECORDDT  				619
#define ERR_RECDT_CANT_BEFORE_DECLDT    				620
#define E_EX_DT_CANT_BEFORE_PAY_DT      				621
#define E_PP_DT_CANT_BEFORE_EXP_DT	  	  				622
#define ERR_INVALID_MODE						  			623
#define ERR_PRVBILLDT_CANT_MODIFY 						624
#define ERR_BTWGENDELV_CANTMOD_NXTBILLDT 				625
#define ERR_BTWNGENDELV_CANTMOD_PROCDT 				626
#define ERR_BILLPROCDT_CANT_HOLIDAY 					627
#define ERR_NXTBILLDT_CANT_PAST 							628
#define ERR_QTY_CANT_LESS_MINFINQTY 					629
#define W_REM_QTY_LESS_MINFMTQTY 						630
#define ERR_DEAL_SETTLED_PAST_RST_NALLOW 				631
#define ERR_DEAL_ACENTRIES_PASSED 						632
#define ERR_DEAL_REPATEOM_RST_NALLOW 					633
#define ERR_DEAL_MSGSNT_RST_NALLOW 						634
#define ERR_SERV_DETAILS_NC 								635
#define ERR_ACCNOTGENDLV_CANTDEL 						636
#define ERR_INTRNL_SERV_DEP_MANDATORY 					637
#define ERR_INTRNL_SERV_CHRG_MANDATORY 				638
#define ERR_EOD_STARTED 									639
#define E_BOD_NOT_OVER 										640
#define ERR_DB_CANT_LOG_AUDIT  							641
#define ERR_DB_CANT_LOG_AUDITTIME  						642
#define ERR_USER_UNAUTHN 									643
#define ERR_DEAL_FREETDL_CANT_SPOTDEAL 				644
#define ERR_EFFDT_CANT_BEFORE_DECLDT 					645
#define ERR_RES_OPENEND 									646
#define ERR_EXP_OPENEND 									647
#define ERR_ACCOUNT_MARKEDFORFRZN 						648
#define ERR_DUPLICATE_GLBLPYMNT 							649
#define ERR_INVALID_EVNT_GLBLPAYMNT 					650
#define ERR_INVALID_INSTR_GLBLPAYMNT 					651
#define ERR_INVALID_STATUS 								652
#define ERR_PAYDT_BTWN_REC_SYSDT 						653
#define ERR_UNAUTH_ENT_NO_GP 								654
#define ERR_GLBLPAYMNT_VAL_CHG 							655
#define ERR_GLBLPAYMNT_DEL_AUTHORIZED 					656
#define E_GP_AUTH 											657
#define ERR_GLBLPAYMNT_NOTFND 							658
#define ERR_UNAUT_GPPYMT_CANT_REV_ENT					659	
#define ERR_UNAUT_GPPYMT_CANT_REV_EVNT					660	
#define ERR_MSGDEL_CANT_RESET 							661
#define ERR_BASENO_NOTEXIST 								662
#define ERR_MSGNOTIN_CORRECT_STS 						663
#define ERR_MSG_CANT_GENERATE 							664
#define ERR_ORD_VALID_VALUEC 								665
#define ERR_ORD_VALID_VALUEBSC 							666
#define ERR_VALID_VALUES_Y_N 								667
#define ERROR_COLUMN_SHUD_NULL 							668
#define ERR_VALID_VALUES_T_R_S 							669
#define E_VALUES_Y_N_BLANK 								670
#define ERR_ORD_VALID_VALUEBS 							671
#define ERR_VALID_VALUES_R_P 								672
#define ERR_VALID_VALUES_A_R 								673
#define ERR_VALUERR_BETWEEN_1_999 						674
#define ERR_NOEVNT_RECORD_FOR_ENRA_GEN 				675
#define W_ENT_GLB_PYMT_EXIST 								676
#define W_PAY_GLB_PYMT_EXIST 								677
#define ERR_DEAL_TYPE_DEP 									678
#define ERR_DEPND_AFMATCH_MAINSERV 						679
#define ERR_DEPND_MAINSERV_NOTDEFINED 					680
#define ERR_INVALID_SERVDEPEND 							681
#define ERR_INVALIDGRP_VALUE 								682
#define ERR_RFDF_SLAB_NOTALLOWED_FORADMNTXNFEE 		683
#define ERR_TIERSLIDE_IN_TXNADM 							684
#define ERR_PAYINP_NOT_FOR_DIRDBCUST 					685
#define ERR_DIRDR_NALLOW_FORACC_OSAMT 					686
#define ERR_INVALID_DEPND_LOCPROC 						687
#define ERR_DFLT_FEEACC_NOTFND 							688
#define ERR_CYCLIC_DFLTFEE_NOTALLOWED 					689
#define ERR_INVALID_DEFLTACC_FEE 						690
#define ERR_PAYDT_CANT_BEFORE_RESPONSEDT 				691
#define ERR_BILLREGN_NOTCOMPLETE 						692
#define ERR_BOGCODE_EQL5CHAR 								693
#define ERR_ACCOUNT_BOGCODE_NULL 						694
#define ERR_GLACCOUNT_EQL_DGTS 							695
#define ERR_ACCSAT_CANTBE_MORE_10DIGITS 				696
#define ERR_ACCSAT_CANTBE_NULLFOR_BRK 					697
#define ERR_ACCSATCODE_CANTBE_MORE_10DIGITS 			698
#define ERR_ACCSATCODE_CANTBE_NULLFOR_BRK 			699
#define ERR_TYPEOFDEAL_NOTEQTO_26 						700
#define ERR_DOMCP_EQLTO_INTRNLACC 						701
#define ERR_COUNTACCFLD_CANT_EMPTY 						702
#define ERR_STATUS_DEAL_DU 								703
#define ERR_MARKED_AUTHORIZED 							704
#define ERR_CANT_DELETE 									705
#define ERR_CANT_AUTHORIZE 								706
#define ERR_PAY_MORE_DUES_ENT_SUM 						707
#define ERR_DEAL_CONF_NOTALLOWED 						708 
#define ERR_ENTITLE_NOTALLOWED_DMYACC 					709 
#define ERR_INVALID_GROSS_AMT 							710
#define ERR_BILLACC_LEN_10DIGITS 						711
#define ERR_BOGREFNO_CANT_EMPTY 							712
#define ERR_DOMCP_CANT_BE_INTRNLACC 					713
#define ERR_TYPEOFCLI_OF_ACCT_AND_CUST_SAME 			714
#define ERR_INVALID_LOCATION 								715
#define ERR_SATACC_EXISTS 									716
#define ERR_SATCD_EXIST 									717
#define ERR_RECDT_CANT_GRTR_EXDT  						718
#define ERR_PAYDT_CANT_BEFORE_EXDT  					719
#define ERR_EFFDT_CANT_BEFORE_RECDT  					720
#define ERR_PAYDT_CANT_LESS_EXDT  						721
#define ERR_MULTI_TRDS_ORD_EXECUTION_FND  			722
#define ERR_INVALID_CASHACC_FORTRD  					723
#define ERR_CASHACC_NOTALLOWED_FORCSD  				724
#define ERR_TRDCCY_SHDBERR_EURO							725
#define ERR_REDNEXIST_RESET_NOTALLOWED 				726
#define ERR_DEAL_EMUCONV 									727
#define ERR_REDN_EVNTENTITLE_MNT_NOTALLOWED 			728
#define ERR_REDN_EVNTPAY_MNT_NOTALLOWED 				729
#define ERR_DEAL_CURRENCY_NOT_ALLOWED 					730
#define ERR_CANTGEN_CA_REFNO 								731
#define ERR_GLACCOUNT_CANT_MORE_1CCY					732
#define ERR_DEAL_NVAL_VERWITH_HU_FREE_A 				733
#define ERR_DEAL_NVAL_VERWITH_HU_VP 					734
#define ERR_DEAL_NVAL_NOTE1_HU_OURTHEIR_T 			735
#define ERR_INVALID_CNTRPARTYAMT 						736
#define ERR_VTBCLI_CANT_BEG_ZERO 						737 
#define ERR_BASENO_EQL_6DIGITS 							738
#define ERR_BASENO_NOTALLOWED 							739
#define ERR_INVALID_SYNACC   								740
#define ERR_ACCTYPE_NOTVALID  							741
#define ERR_ACCMARKED_FOR_CLOSE  						742
#define ERR_COREACC_NOTPROP  								743
#define ERR_CANT_MODIFY  									744
#define ERR_INVALID_CORRES_TYPE 							745
#define ERR_LOCN_MARKED_CLOSE 							746
#define ERR_LOCN_NOTCLOSED 								747 
#define ERR_LOCN_CLOSED 									748
#define ERR_PROD_NOTFND 									749
#define ERR_PROD_NOTAUTHORIZED 							750 
#define ERR_PROD_AUTHORIZED 								751
#define ERR_SRN_NOTFND 										752
#define ERR_SRN_NOTAUTHORIZED 							753
#define ERR_SRN_AUTHORIZED 								754
#define ERR_SRN_ALREADY_EXIST 							755
#define ERR_REFNUM_EXISTS 									756
#define ERR_INSTR_NOTCLOSED 								757
#define ERR_INSTR_CLOSED 									758
#define ERR_INVALID_SYNLOCN 								759 
#define ERR_INVALID_LOCNTYPE  							760
#define ERR_INVALID_PRODTYPE 								761
#define ERR_INVALID_INTTYPE 								762
#define ERR_NOT_VALID_DAYDATE 							763
#define ERR_NOT_VALID_DAYYEAR 							764
#define ERR_INVALID_INSTRCLASS 							765
 #define ERR_INVALID_TYPEOFINSTR 						766
#define ERR_DEAL_SRNNENUFPOSN 							767
#define ERR_DFLT_ACCOUNT_FIRST 							768
#define ERR_CANTDEL_DFLTCASHACC 							769
#define ERR_DFLTCASHACC_MANDATORY 						770
#define E_REC_NOT_FD 										771
#define ERR_INSTRCONV_RESET_NOTALLOWED 				772 
#define ERR_SPLIT_RESET_NOTALLOWED 						773
#define E_ISO_LOCNCODE 										774
#define ERR_TRD_NOTFND_INRRMM 							775
#define ERR_INVALID_VALUE1									776
#define ERR_DEAL_NVAL_VERWITH_HU_FREE 					777
#define ERR_REPO_BLOCK 										778
#define ERR_MULTI_FIAC_BLKFND 							779
#define E_CPY_RUNNING 										780
#define ERR_INVALID_VALUE   								781
#define ERR_FXTRDTYPE_MISMATCH 							782
#define ERR_DMY_CASHACC_EXIST 							783
#define ERR_ASSISCD_EXISTS  								784
#define ERR_ASSISCD_NOTFND 								785
#define ERR_ASSISCD_AUTHORIZED 							786
#define ERR_INVALID_ACCGRP_FOR_LOCALBRK 				787
#define ERR_INVALID_ACCGRP_FOR_OPRCODE 				788
#define ERR_SMIEOD_FLG_UPDATED 							789
#define ERR_CANT_RESET_AGAIN 								790
#define ERR_ASSISCD_MARKEDFORDEL 						791
#define ERR_DEAL_PARENT_SETTL 							792
#define ERR_INVALID_TRD_STATUS 							793
#define ERR_TXN_FEERR_ONLY_TXN_ADM 						794
#define ERR_EUROMSG_NOTSENT 								795
#define E_MULTIPLE_RECORDS_FOUND 						796
#define ERR_BEFOAFTE_ENCNTRD_INLINKBLK  				797
#define ERR_FRMDT_CANT_GRTREQL_TODAYDT   				798
#define ERR_DOMCP_FOREXTRNL_CANT_BE_BRK   			799
#define ERR_NTRDTYPE_INSTR_NOTALLOWED 					800
#define ERR_DLVTRDS_NOTALLOWED 							801
#define ERR_DEAL_DECU_CANTSAME_CLI    					802
#define FUNC_NF    											803
#define ERR_MSG_PREA_NOTSUPPORTED    					804
#define ERR_DIRDB_PAYMNTGEN_BTWN_1TO28					805
#define ERR_PAYMNT_STS_UA									806
#define ERR_DUPLICATE_INSTR								807
#define ERR_INVALID_IBANACC								808
#define ERR_UNPRO_PAY_EXST 								809
#define ERR_UNPRO_EVNT_MOD_EXST  						810
#define ERR_HDATID_NOTFND 									811
#define ERR_HDATID_EXISTS 									812
#define ERR_HDATID_AUTHORIZED 							813
#define ERR_HDATID_UNAUTHORIZED 							814
#define ERR_HDATID_MARKEDDEL 								815
 #define ERR_NOTPOSN_INSTRLOCN 816
#define ERR_SYSDATE_LESS_CONVDATE 						817
#define ERR_TRDDT_CANT_LESS_1YR 							818
#define ERR_SETTLEDT_CANT_LESS_1YR 						819
#define ERR_SETTLEDT_CANT_LATER_1YR 					820
#define ERR_PRODCODE_CANT_DEL 							821
#define ERR_MARKET_LOT_CANT_BE_GRT_ONE 				822/*"Marketable Lot Cannot be Greater Than 1 for Demat Instruments"*/
#define ERR_INSTRUMENT_TYPE_NOT_PROPER 				823/*"Instrument Type Is Not Proper"*/
#define ERR_PC_DET_NOT_ALLOW 								824/*"Put Call Details Not Allowed for Instrument"*/
#define ERR_PART_RED_DET_NOT_ALLOW 						825/*"Part Redemption Not Allowed for Instrument"*/
#define ERR_RESET_DET_NOT_ALLOW 							826/*"Reset Details Not Allowed for Instrument"*/
#define ERR_PTC_DET_NOT_ALLOW 							827/*"PTC Details Not allowed for Instrument"*/
#define ERR_LIST_DET_NOT_ALLOW 							828/*"Listing Details Not allowed for Instrument"*/
#define ERR_RED_PCT_CANT_GRT_HUN 						829/*"Redemption Percentage Cannot be Greater than 100"*/
#define ERR_RED_VAL_GRT_NOM_VAL 							830/*"Redemption Value Exceeds Nominal Value of Instrument"*/
#define ERR_PTC_PRIN_INT_VALUE 							831/*"Principal and Interest do not match PTC Value"*/
#define ERR_FRDATE_CANT_GRT_TODATE 						832/*"Effective From Date Cannot be Greater Than Effective To Date"*/
#define MAP_INSTR_EXIST_CANTDEL 							833/*"Mapping Details Exists for Instrument Cannot Delete"*/
#define MAP_DET_NOTFND 										834/*"Mapping Details Not Found"*/
#define MAP_DET_EXIST 										835/*"Mapping Details Already Exist"*/
#define MAP_DET_UNAUTH 										836/*"Mapping Details Unauthorized"*/
#define MAP_DET_AUTHORIZED 								837/*"Mapping Details Already Authorized"*/
#define MAP_DET_NOTMARKEDDEL 								838/*"Mapping Details Not Marked Delete"*/
#define MAP_DET_MARKEDDEL 									839/*"Mapping Details Already Marked Delete"*/
#define MAP_DET_NOTFRZN 									840/*"Mapping Details Not Frozen"*/
#define MAP_DET_FRZN 										841/*"Mapping Details Already Frozen"*/
#define ERR_CODE_VAL_MISMATCH								842/*"Key Codes and Key Values MisMatched"*/
#define ERR_PTC_PAID_FLG_CANT_MOD						843/*"PTC Has Been Paid..Cannot Modify PTC Details"*/
#define ERR_PC_NOT_DAILY									844/*"Put Call Flag Not Daily; Details Not Accepted"*/
#define ERR_INSTR_ISSUEDT_CANT_GRT_FSTPYMT_DT		845/*"Issue Dt Cant Be > First Pay Dt for Instrument"*/
#define ERR_INSTR_FSTPYMT_DT_CANT_GRT_MATUREDT		846/*"First Pay Dt Can Be > Maturity Dt for Instrument"*/
#define ERR_DIV_RT_NOT_ALLOWED_PREF_SHS				847/*"Div Rate Not Allowed For Pref Shares"*/
#define ERR_CHAR_VALUE_NOT_PROPER						848/*"Character Value Not Proper"*/
#define ERR_COMPANY_EXISTS 		849 /*"Company Already Exists"*/
#define ERR_COMPANY_NOTFND              850 /*"Company Not Found"*/
#define ERR_COMPANY_AUTHORIZED			851 /*"Company Already Authorised"*/
#define ERR_COMPANY_NOT_AUTHORIZED 		852 /*"Company Not Authorised"*/
#define ERR_COMPANY_MARKED_DEL 			853 /*"Company Already Marked Deleted"*/
#define ERR_COMPANY_CANT_DEL 			854 /*"Company Cannot Be Deleted"*/
#define ERR_MODIFY_NOTALLOWED 			855 /*"Company Cannot Be Modified"*/
#define ERR_RESET_NOTALLOWED 			856 /*"Company Cannot Be Reset"*/
#define ERR_PARTY_EXISTS 									857
#define ERR_PARTY_CANT_DEL 								858
#define ERR_PARTY_MARKED_DEL 								859
#define ERR_PARTY_NOT_FOUND 								860
#define ERR_PARTY_AUTHORIZED 								861
#define ERR_PARTY_NOT_AUTHORIZED 						862
#define ERR_PAN_LENGTH  									863
#define ERR_PARTY_BANKDET_EXISTS 						864
#define ERR_BANK_ACC_LENGTH 								865
#define ERR_MAIN_ACC_LENGTH								866
#define ERR_PARTY_BANKDET_MARKED_DEL 					867
#define ERR_PARTY_EXCHMAP_EXISTS 						868
#define ERR_PARTY_EXCHMAP_MARKED_DEL 					869
#define ERR_PARTY_DEPOMAP_EXISTS 						870
#define ERR_PARTY_DEPOMAP_MARKED_DEL 					871
#define ERR_PARTY_EXCHCLNMAP_EXISTS 					872
#define ERR_PARTY_EXCHCLNMAP_MARKED_DEL 				873
#define ERR_PARTY_BANKDET_NOTFND 						874
#define ERR_PARTY_EXCHMAP_NOTFND 						875
#define ERR_PARTY_DEPOMAP_NOTFND 						876
#define ERR_PARTY_EXCHCLNMAP_NOTFND 					877
#define ERR_PARTY_BANKDET_AUTHORIZED 					878
#define ERR_PARTY_BANKDET_NOT_AUTHORIZED 				879
#define ERR_PARTY_EXCHMAP_AUTHORIZED 					880
#define ERR_PARTY_EXCHMAP_NOT_AUTHORIZED 				881
#define ERR_PARTY_DEPOMAP_AUTHORIZED 					882
#define ERR_PARTY_DEPOMAP_NOT_AUTHORIZED 				883
#define ERR_PARTY_EXCHCLNMAP_AUTHORIZED 				884
#define ERR_PARTY_EXCHCLNMAP_NOT_AUTHORIZED 			885
#define ERR_CR_AGENCY_NOTFND								886/*"Credit Rating Agency Not Found"*/
#define ERR_CR_AGENCY_EXIST								887/*"Credit Rating Agency Already Exists"*/
#define ERR_UNAUTH_CR_AGENCY								888/*"Credit Rating Agency Not Authorised"*/
#define ERR_CR_AGENCY_AUTHORIZED							889/*"Credit Rating Agency Already Authorised"*/
#define ERR_CR_AGENCY_NOTMARKEDDEL						890/*"Credit Rating Agency Not Marked Deleted"*/
#define ERR_CR_AGENCY_MARKEDDEL							891/*"Credit Rating Agency Already Marked Deleted"*/
#define ERR_RATING_CODE_NOTFND							892/*"Rating Code Not Found"*/
#define ERR_RATING_CODE_EXIST								893/*"Rating Code Already Exists"*/
#define ERR_CLIENTINSTRUMENT_NOTFND 894 /*"Client instrument not found "*/
#define ERR_CLIENTINSTRUMENT_EXISTS 895 /*"Client instrument already exists"*/
#define ERR_CLIENTINSTRUMENT_AUTHORIZED 896 /*"Client instrument already authorized"*/
#define ERR_CLIENTINSTRUMENT_NOT_AUTHORIZED 897 /*"Client instrument not authorized"*/
#define ERR_CLIENTINSTRUMENT_MARKED_DEL 898 /*"Client instrument marked deleted"*/
#define ERR_RECORD_EXISTS 899 /*"Client Instrument record exists"*/
#define ERR_CLIENTINSTRUMENT_CANT_DEL 900 /*"Client instrument can not be deleted.Invalid status"*/
#define ERR_CLIENTINSTRUMENT_CANT_AUT 901 /*"Client instrument can not be authorized.Invalid status"*/
#define ERR_CLIENTINSTRUMENT_CANT_RESET 902 /*"Client instrument can not be reset.Invalid status"*/
#define ERR_CLIENTINSTRUMENT_CANT_INP 903 /*"Client instrument can not input.Invalid status"*/
#define ERR_CLIENTINSTRUMENT_CANT_MODIFY 904 /*"Client instrument can not modify.Invalid status"*/
#define ERR_CLNTINSTMODIFY_NOTALLOWED 905 /*"Client instrument can not be modified"*/
#define ERR_CLNTINSTRESET_NOTALLOWED 906 /*"Client instrument can not reset"*/
#define ERR_INSTRUCTIONSLIP_NOTFND 907 /*"Instruction slip not found"*/
#define ERR_SRFROM_GREATER 908 /*"Instruction Slip series from is greater"*/
#define ERR_INSTRUCTIONSLIP_CANT_INP 909 /*"Instruction slip can not input"*/
#define ERR_INSTRUCTIONSLIP_CANT_MODIFY 910 /*"Instruction slip can not be modified"*/
#define ERR_INSTRUCTIONSLIP_CANT_AUT 911 /*"Instruction slip can not be authorised"*/
#define ERR_INSTRUCTIONSLIP_CANT_DEL 912 /*"Instruction slip can not be deleted"*/ 
#define ERR_INSTRUCTIONSLIP_EXISTS 913 /*"Instruction slip already exists"*/
#define ERR_INSTRUCTIONSLIP_AUTHORIZED 914 /*"Instruction slip is authorised"*/
#define ERR_INSTRUCTIONSLIP_NOT_AUTHORIZED 915 /*"Instruction slip not authorised"*/
#define ERR_INSTRUCTIONSLIP_MARKED_DEL 916 /*"Instruction slip marked deleted"*/
#define ERR_INSTRUCTIONSLIP_CANT_RESET 917 /*"Instruction slip can not reset"*/
#define ERR_INSLIPMODIFY_NOTALLOWED 918 /*"Modify not allowed for instruction slip"*/
#define ERR_INSLIPRESET_NOTALLOWED 919 /*"Reset not allowed for instruction slip"*/
#define ERR_STLMENTCAL_NOTFND 920 /* "Settlement calendar not found"*/
#define ERR_STLMENTCAL_EXISTS 921 /* "Settlement calendar exists" */
#define ERR_STLMENTCAL_AUTHORIZED 922 /* "Settlement calendar authorised" */
#define ERR_STLMENTCAL_NOT_AUTHORIZED 923 /*  "Settlement calendar not   authorised" */
#define ERR_STLMENTCAL_MARKED_DEL 924 /* "Settlement calendar marked deleted" */
#define ERR_STLMENTCALRESET_NOTALLOWED 925 /* "Settlement calendar can not reset" */
#define ERR_STLMENTCALMOD_NOTALLOWED 926 /*  "Settlement calendar can not be modified" */
#define ERR_DAILYQUOTATION_NOTFND  927
#define ERR_DAILYQUOTATION_CANT_INP 928
#define ERR_DAILYQUOTATION_CANT_MODIFY 929
#define ERR_DAILYQUOTATION_CANT_AUT 930
#define ERR_DAILYQUOTATION_CANT_DEL 931
#define ERR_DAILYQUOTATION_EXISTS 932
#define ERR_DAILYQUOTATION_AUTHORIZED 933
#define ERR_DAILYQUOTATION_NOT_AUTHORIZED 934
#define ERR_DAILYQUOTATION_MARKED_DEL 935
#define ERR_DAILYQUOTATION_CANT_RESET 936
#define ERR_INSTRUMENT_NOT_AUTHORIZED 937
#define ERR_DAILYQUOTATION_NOTMARKED_DEL 938
#define ERR_PARTY_NOT_MARKED_DEL 						939 /* "Party not Marked as deleted" */
#define ERR_PTY_BANKDET_NOT_MARKED_DEL  				940 /* "Party Bank Details not marked as deleted" */
#define ERR_PTY_EXCH_MAP_NOT_MARKED_DEL 				941 /* "Party Exchange Details not marked as deleted" */
#define ERR_PTY_DEPO_MAP_NOT_MARKED_DEL 				942 /* "Party Depository Details not marked as deleted" */
#define ERR_PTY_EXCH_CLN_MAP_NOT_MARKED_DEL 			943 /* "Party Exchange Client map details not marked as deleted" */
#define ERR_INSTR_PTC_MORE_THAN_NOMVAL					944/*PTC Value Cannot Exceed Nominal Value of Instrument*/
#define ERR_SEBINO_EXIST_CANT_INP                945/* "SEBI Registration Number Already Exists." */ 
#define ERR_RBINO_EXIST_CANT_INP                 946/* "RBI Registration  Number Already Exists". */ 
#define ERR_MAPINID_EXSTINACC_CANT_INP 			 947/* "Mapinid Already Exists." */ 
#define ERR_UCC_CODE_EXSTINACC_CANT_INP 			 948/* "UccCode Already Exists." */
#define ERR_SEBIREGDT_GRTEXPDT_CANT_INP 			 949/* "SEBI Reg Date Is Greater Than SEBI Reg Exp Date." */
#define ERR_RBIREGDT_GRTEXPDT_CANT_INP 			 950/* "RBI Reg Date Is Greater Than RBI Reg Exp Date."*/
#define ERR_OUTOF_IND_LIMIT 							 951/* "Invalid Master Account Level Creation."*/ 
#define ERR_INVALID_SIGNATURE                    952/* "Invalid Signature Passed." */ 
#define MAP_CLIENT_EXIST_CANTDEL						 953/* "Mapping Details Exist for Client Cannot Delete"*/
#define ERR_MASTER_ACCT_PASSED                   954/* "Invalid Master Account Passed." */
#define ERR_SEBI_REGDATE_PASSED                       955/* "SEBI Reg Date should not be in Future." */
#define ERR_RBI_REGDATE_PASSED                       956/* "RBI Reg Date should not be in Future." */
#define ERR_INSTR_EXISTS_CANTDEL 957
#define ERR_MOD_NOT_ALWD 958
#define ERR_MAP_DEPO_PART_EXIST_CANTDEL 959 /* "Mapping Depository Participant Details Exist." */
#define ERR_DEPO_PART_RESET_CANT_ALLOWED 960 /* "Depository Participant Reset cannot be Allowed." */
#define ERR_MAP_RATING_EXIST_CANTDEL 961  /* "Mapping Credit Rating Details Exist." */
#define ERR_SEBINO_EXIST_OTHER_MODIFY 962 /* "SEBINo Exists for Other User." */
#define ERR_RBINO_EXIST_OTHER_MODIFY 963 /* "RBINo Exists for Other User." */
#define ERR_MAPIN_EXIST_OTHER_MODIFY 964 /* "MapInId Exists for Other User." */
#define ERR_UCCCODE_EXIST_OTHER_MODIFY 965 /* "UccCode Exists for Other User." */
#define ERR_INVALID_INSTRU_TYPE_EXCHDET 966 /* "Invalid Instrument Type passed for Exchange Details." */
#define ERR_INVALID_INSTRU_TYPE_RED_DEPODET 967 /* "Invalid Instrument Type passed for Redemption Depo Details." */
#define ERR_INVALID_INSTRU_TYPE_REDEMDET 968 /* "Invalid Instrument Type passed for Redemption Details." */
#define ERR_INVALID_INSTRU_TYPE_CR_RATINGDET 969 /* "Invalid Instrument Type passed for Credit Rating Details." */
#define ERR_INVALID_INSTRU_TYPE_RESETDET 970 /* "Invalid Instrument Type passed for Reset Details." */
#define ERR_INVALID_INSTRU_TYPE_PCDET 971 /* "Invalid Instrument Type passed for PutCall Details." */
#define ERR_INVALID_INSTRU_TYPE_PTCDET 972 /* "Invalid Instrument Type passed for PTC Details." */
#define ERR_DEPO_PART_NOTFND 973 /*Depo Participant For the Depository Not Found*/
#define ERR_DEPO_PART_UNAUTH 974 /*Depo Participant for the Depository UnAuthorised*/
#define ERR_FLTRATE_INSTRU_UNAUTH_STATUS 975 /* "Float Rate Instrument for the passed Instrument is Unauthorised." */
#define ERR_INVALID_STATE_CITY_ISOCNTRY_EXIST 976 /* "Invalid Combination of State,City for the Passed Country." */
#define ERR_STARTDT_GRTENDDT_CANT_INP 977 /* "Settlement Calendar Start Date Cannot Be Greater Than End Date." */
#define ERR_AUCTIONDT_GRTENDDT_CANT_INP 978 /* "Settlement Calendar Auction Date Cannot Be Greater Than End Date." */
#define ERR_DEADLINEDT_GRTENDDT_CANT_INP 979 /* "Settlement Calendar NSDL Deadline Date Cannot Be Greater Than End Date." */
#define ERR_PAYINDT_GRTDEADLINEDT_CANT_INP 980 /* "Settlement Calendar PayIn Date Cannot Be Greater Than NSDL Deadline Date." */
#define ERR_PAYOUTDT_GRTDEADLINEDT_CANT_INP 981 /* "Settlement Calendar PayOut Date Cannot Be Greater Than NSDL Deadline Date." */
#define ERR_PAYINDT_GRTPAYOUTDT_CANT_INP 982 /* "Settlement Calendar PayIn Date Cannot Be Greater Than PayOut Date." */
#define ERR_OPNDT_GRTCLSDT_CANT_INP 983     /* "Open Date Cannot be Greater Than Close Date." */
#define ERR_ATDT_GRTCLSDT_CANT_INP 984    /* "Active Date Cannot be Greater Than Close Date." */
#define ERR_CLNCD_UNAUTHED_CANT_INP 985 /* "ClientCode Passed Is Unauthorise Status." */
#define ERR_ISSUEPRICE_LESS 986 /*Issue price is less than Face Value*/
#define ERR_LOWERLIMIT_LESS 987 /*Lower Limit is less then Face Value*/
#define ERR_ISSUEFROM_DATE_GREATER 988 /*Issue Start date greater than end date*/
#define ERR_MAXQTY_LESS 989 /*Max Quantity is less*/
#define ERR_ISSUESIZE_LESS 990 /*Issue Size is less*/
#define ERR_BCN_NOTFND 								 991 /*BCN related*/
#define ERR_BCN_CONTRACT_CD_DOESNOT_STARTS_A_B  992
#define ERR_BCN_EXISTS      						 993
#define ERR_BCN_MARKED_DEL   						 994   
#define ERR_BCN_CANT_DEL      					 995
#define ERR_BCN_AUTHORIZED      					 996
#define ERR_BCN_NOTMARKED_DEL   					 997
#define ERR_MODIFY_NOT_ALLOWED  					 998
#define ERR_RESET_NOT_POSSIBLE  					 999 
#define ERR_AUTHORISE_NOT_ALLOWED  				 1000 
#define ERR_OVERRIDE_NOT_ALLOWED   				 1001
#define ERR_BCN_EXCH_CD_NOT_EXIST  				 1002
#define ERR_BCN_INSTRU_CD_NOT_AUTH 				 1003
#define ERR_BCN_CLN_CD_NOT_AUTH    				 1004
#define ERR_BCN_SETT_NO_NOT_AUTH   				 1005
#define ERR_BCN_EXISTS_REPAIR      				 1006
#define ERR_DEALDT_GREATER_SETTDT  				 1007
#define ERR_DEAL_DATE_IS_HOLIDAY   				 1008
#define ERR_SETT_DATE_IS_HOLIDAY   				 1009
#define ERR_BCN_MKT_TYP_NOT_EXIST  				 1010
#define ERR_PARTY_TYPE_NOT_VALID   				 1011
#define ERR_BCN_OVERRIDE           				 1012
#define ERR_BCN_NOT_OVERRIDE       				 1013
#define ERR_BCN_TRANS_TYPE_NOT_EXIST 			 1014
#define ERR_DEALDT_LESSTHAN_SYSDATE 			 1015
#define ERR_BCN_QTY_MORE            			 1016
#define ERR_BCN_DL_PRICE_NOTIN_BAND 			 1017
#define ERR_BCN_STTAMT_HIGH 			 1018 /*End of BDN*/
#define ERR_DL_TAKEOVER_DEPO_INST_INVALID 	 1019 /*TAKEOVER-AMISH*/
#define ERR_DL_MARKSHORTAGE_QTY_INVALID 		 1020  /*MARKSHORTAGE-AMISH*/
#define ERR_SQOFF_EXCH_CD_NOT_EXIST     		 1021 /* Exchange code is invalid */
#define ERR_SQOFF_INSTRU_CD_NOT_AUTH    		 1022 /* Instrument code is not Authourized */
#define ERR_SQOFF_CLN_CD_NOT_AUTH       		 1023/* Client code is not Authourized */
#define ERR_SQOFF_SETT_NO_NOT_AUTH      		 1024/* Settlement code is notAuthourized */
#define ERR_EXCHORDUP_CLN_CD_NOT_AUTH            1025 /* "ExchOrd Upload client code not authorised" */
#define ERR_EXCHORDUP_INSTRU_CD_NOT_AUTH         1026 /* "ExchOrd Upload instrument code not authorised" */
#define ERR_EXCHORDUP_SETT_NO_NOT_AUTH           1027 /* "ExchOrd Upload settlment number not authorised" */
#define ERR_DEAL_DATE_IS_HOLIDAY_EXCH            1028 /* "ExchOrd Upload Dealdate is Holiday " */
#define ERR_EXCHORDUP_MKT_TYP_NOT_EXIST          1029 /* "ExchOrd Upload market type not exists in static data" */
#define ERR_EXCHORDUP_SCRIP_GRP_NOT_EXIST        1030 /* "ExchOrd Upload Scrip group not exists in static data" */
#define DEAL_INFO_MISSING                        1031 /* "Deal Information Is missing" */       
#define ORDER_INFO_MISSING                       1032 /* "Exchange Order Information Is Missing" */
#define EXCH_ORDER_NOT_IN_PROPER_STATUS          1033 /* "Deal Not In Proper status " */
#define DEAL_NOT_IN_PROPER_STATUS                1034 /* "Order Not In Proper status  " */
#define ERR_BUCKET_EXIST                         1035 /*Bucket Already Exist*/
#define ADDR_LEN_INCORRECT                	1036 /* "Address Length validation " */
#define ERR_DEALDT_LESSTHAN_ENDDATE       1037 /* "deal date should be less than enddate"*/
#define ERR_BCN_MISMATCHED_DATA           1038
#define ERR_BCN_NOTVALID_EXCH_CD_BSE      1039
#define ERR_BCN_NOTVALID_EXCH_CD_NSE      1040
#define ERR_BCN_BROKERAGE_HIGH          1041 /*End of BCN*/
#define ERR_MAP_INTR_SCH_EXIST_CANTDEL           1042 /* "Mapping  InterScheme Details Exist" */
#define ERR_MAP_INTR_SCH_CHLD_EXIST_CANTDEL      1043 /* "Mapping  Interscheme Child Details Exist" */
#define ERR_UNAUTH_PARTY                         1044 /* Party Unauthorised */
#define ERR_MAP_BLK_SEC_CHLD_EXIST_CANTDEL       1045 /* Block Child Security  */
#define ERR_POOLACC_INSTRU_CD_NOT_AUTH 1046 /* "Instrument code not Authourize "*/
#define ERR_POOLACC_SETT_NO_NOT_AUTH  1047  /* "settlement number not Authourized " */
#define ERR_FORMAT_CANT_DEL           1048  
#define ERR_DT_GRT_SEBIEXDT 			  1049
#define ERR_DT_GRT_RBIEXDT            1050
#define ERR_ENTRY_S_NSE_23            1051
#define ERR_ENTRY_S_BSE_01            1052
#define ERR_ENTRY_M_NSE_23            1053
#define ERR_ENTRY_M_BSE_01            1054
#define ERR_CLIENT_EXIST				  1055
#define ERR_SAME_APPLICATION_FORM_NUMBER		1056
#define ERR_BCN_INTERFII_CAU_MISMATCHED    1057
#define ERR_DEAL_NENUFPOSN_SHORT_SELL		1058
#define ERR_ATTACH_ENTITL_NOT_CLOSED		1059
#define ERR_POOLQTY_NOTEQUAL_MARKQ        1060
#define ERR_MAXFEE_CONSO_VALID            1061
#define ERR_MAXCONSO_VALID                1062
#define ERR_MAXFEE_HLD_VALID              1063
#define ERR_DEAL_MNYSETL_PEND              1064
#define ERR_DEAL_SECSETL_PEND              1065
#define ERR_INSTR_NO_DEL                  1066   /*Instrument under no delivery period*/
#define ERR_INSTR_CAUTIONFLG_S            1067
#define ERR_ENDDT_LESS_SETTDT             1068
#define ERR_MUTUAL_FUND_EXIST             1069	/**** "Mutual Fund Already Exists" ****/
#define ERR_PTC_PRINC_MORE_THAN_NOMVAL    1070	/*PTC Principle Cannot Exceed Nominal Value of Instrument*/
#define ERR_RECORD_EXIST		1071   /* RFS_CLN_MAP_001 */
#define ERR_CRN_MAPPED			1072   /* RFS_CLN_MAP_001 */
#define ERR_DOMESTIC_CPCLT_NOTFOUND     1073	/*Domestic CPCLT CODE not Found*/
#define ERR_INP_CLIENT_NOT_VALID	1074  /* User Cant Input Deals of Other Clients */
#define ERR_SUB_ACNT_CHECKER            1075  /* Harvinder Singh - 26/04/2007 - Log 1 Web discussion */
#define ERR_AUTHRZR_HAV_CHECKER_RGT     1076  /* Harvinder Singh - 26/04/2007 - Log 1 Web discussion */
#define ERR_IDENTY_NO_LEN_MORE	  	1077  /* Deal Reference Number should not be more than 16 Characters */
#define ERR_DEAL_CODE_LEN_MORE	  	1078  /*Deal Code should not be more than 1 character */
#define ERR_EXCH_CODE_LEN_MORE	  	1079  /*Exchange code should not be more than 3 characters */
#define ERR_MKT_TYPE_LEN_MORE	  	1080  /*Market Type should not be more than 3 characters */
#define ERR_INSTR_NAME_LEN_MORE	  	1081  /*Instrument Name is Incorrect */
#define ERR_CPCLT_NAME_LEN_MORE	  	1082  /*Broker Name is Incorrect */
#define ERR_DEAL_TRANSFER	  	1083  /*Failed to Transfer Deal */
#define ERR_NETAMT_FOR_FREE_DEAL  	1084  /*Net Rate / Net Amount is not allowed for RF /DF Deals */
#define ERR_UNAUTH_SQRAUTH  	1085
#define ERR_DLREFNO_NFND	1086	/* DL Ref No does not correspond to selected Client */
#define ERR_INCORRECT_DT_FRMT	1087	/* Date format should be DD/MM/YYYY */
#define ERR_NO_MAST_OBLG_DET              1088 /* "Obligation Details not Defined for Master Account" */
#define ERR_NO_GROUP_OBLG_DET             1089  /* "Obligation Details not Defined for Group Account" */
#define ERR_MAST_OBLG_LVL_SELF            1090 /* "Master Account Should Have Obligation Level 'SELF'" */
#define ERR_NO_MAST_BILL_DET              1091 /* "Billing Parameters not Defined for Master Account" */
#define ERR_NO_GROUP_BILL_DET             1092  /* "Billing Parameters  not Defined for Group Account" */
#define ERR_AEGENERATED			1093/*Shailesh - Account Entry generated*/
#define ERR_ZERO_POS			1094 /* Safekeep positions becoming less than zero. Hence cannot proceed. */
#define ERR_PAYMENT_S_ALREADYDONE 1095/*Shailesh - Payment for this service is already made -ISKB_430_08 Chgs*/ 
#define ERR_PAY_GREATERTHAN_BILL 1096/*Shailesh - Payment amount exceeds the bill amount - ISKB_430_08 Chgs*/ 
#define ERR_PAYMENTSTARTEDSERVICEWISE 1097/*Shailesh - Payment already started servicewise - ISKB_430_08 Chgs*/ 
#define ERR_PAYMENTALREADYDONE 1098/*Shailesh - Payment for this billing period is already made - ISKB_430_08 Chgs*/ 
#define ERR_CANNOTUPDATECLIENTSETUP 1099 /*Shailesh The client setup OS amount cannot beupdated - ISKB_430_08 Chgs*/
#define ERR_PYMTAMTGREATER 1100 /*Shailesh BillAmt greater than sum(auth payment,unauthpayment) - ISKB_430_08 Chgs*/
#define ERR_INVALID_DEC_LEN_INST   1101 /* Added by Gouse - Decimal Length for MF- 01/10/2011 */
#define ERR_CUTOVER_DT_PASS 1102 /* Added By Sana for CutOver Date error */
#define ERR_DEAL_RESTRICT_PURCHASE  1103 /* added by shyam to restrict FII/NRI client from purchasing */
#define ERR_BCN_NOTVALID_EXCH_CD_OTHER_THAN_MCS      1104  /* MCS enhancement deependra */
#define ERR_USED_SETTLNO        1105 /*Priyanka - IB5881 CC calender changes*/
#define ERR_OBL_REC_EXISTS      1106 /*Manasi- Obligation Recon*/
#define ERR_PARTY_CNTRY_NOTFND    1107  /* Charuta - Party Master - country code missing */
#define ERR_PARTY_CNTRY_STATE_NOTFND    1108  /* Charuta - Party Master - country or state code missing */ 
#define ERR_EXCEED_CPCODE_LEN   1109  /*Priyanka - Custodian Participant Master file upload*/
#define ERR_CNTRY_STATE_CITY_INVALID  1110  /* Charuta MCS Party Master Upload */
#define ERR_INVALID_DP_CODE	1111            /* Added By Jeevan for Party Depository Mapping upload */
#define ERR_INVALID_EXCH_CODE 1112         /* Added By Jeevan for Party Depository Mapping upload */
#define ERR_MASTER_CLIENT_CODE 1113			/*Added By Vamshi for Party Exchange Client Mapping */
#define ERR_INVALID_PAN 1114                        /*Added for ISKB_6285 - Validation for PAN (as per general nomenclature) & E-mail ID (with '@' sign and '.' Special character)*/
#define ERR_HOLDER_ALREADY_EXIST 1115 /*Added by Prateek on 28052014 for ISKB_198(FPI MAPPING)*/
#define ERR_CUST_ID_MAPPED 1116 /*Added by Prateek on 28052014 for ISKB_198(FPI MAPPING)*/
#define ERR_CLIENTCD_NSDLID_COMB 1117 /*Added by Venkat on 18072014 for ISKB_198(FPI MAPPING)*/
#define ERR_PMS_MSTR_SUBACCT 1118 /* Added For PMS Validations*/
#define ERR_PMS_CLIENT_INVALID 1119 /* Added For PMS Validations 28072015 */
#define ERR_CA_ENTGEN_NOMOD_RPPP 1120/*Retrofit by Kiran ISKB_7977 - CA Server Down */ 
#define ERR_BILL_CNF_AMT_EQ 1121
#define ERR_ZERO_BILL_AMT 1122
#define ERR_LARGER_SIZE 1123/*Retrofitted from IB1185 by Anjaneyulu for ISKB_1737 */
#define ERR_BILL_ALRDY_GENERATED 1124/*Added by monica for ISKB_1737*/
#define ERR_INVALID_QTY 1125 /*added by aditya for for Global Pre-Match Extract*/
#define ERR_PYMTAMT_GRT_BILLAMT 1126 /*ISKB_1737 Billing Upload and Download*/ 
#define ERR_INVALID_PYMTYPE 1127 /*ISKB_1737 Billing Upload and Download*/ 
#define ERR_SRVCE_QTY_SHLD_GRT_THAN_0 1128/*added by Pallavi for Other Services Upload - ISKB_1737*/
#define ERR_BILL_PERIOD_SHLD_NOTBE_FUTURE 1129/*added by Pallavi for Other Services Upload - ISKB_1737*/
#define ERR_PCPA_SHLD_NTBE_CPCA 1130/*added by CHITRLEKHA for ADDITIONAL CLIENT DETAILS*/
#define ERR_DEAL_NOT_DELETE 1131 
#define ERR_PAYMENT_ADD 1132/*added by akshay for kotak_10958*/
#define ERR_EXCH_CD_MISSING 1133/*added by asmeet for kotak_12434*/
#define ERR_MKT_TYPE_MISSING 1134/*added by asmeet for kotak_12434*/
#define ERR_SETTL_NO_MISSING 1135/*added by asmeet for kotak_12434*/
#define ERR_PMS_CLN_NOTPROPER 1136/*added by asmeet for kotak_12434*/
#define ERR_DECIMAL_LENGTH 1137 /* Changes done by Sunny for CS0020637*/
#define ERR_NONCD_PAY_UPLD 1138 /* Changes done by Sunny for CS0020637*/
#define ERR_LINK_EVT_EXIST 1139 /*   CHANGE BY SWAPNIL JAMBLE FOR ISSB-11606 -New Bilav file format changes    */
#define ERR_LINK_EVT_MISS 1140  /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */
#define ERR_POST_EX_DT_MOD 1141  /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */
#define ERR_ISSUE_CLOSE_DT_SMALL 1142  /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */
#define ERR_POST_MEET_DT_MOD 1143   /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */
#define ERR_ISIN_NOT_MAPED	1144    /* Added by Arunachalam for CS0074500 - New Bilav File upload changes */
#define ERR_RESOURCE_BUSY   1145
#define ERR_CA_IDENTIYNO   1146    
#define ERR_BILL_AMNT_ZERO   1147  
#define ERR_NOTFOUND_CLIENT 1148  /* Added for Billing Client Upload */
#define ERR_DUPLICATE_SERVCD_CLIENT 1149 /* Added for Billing Service Upload */
#define ERR_NOTFOUND_SERVCD_CLIENT 1150 /* Added for Billing Service Upload */
#define ERR_CSGL_ONMARKET   1151        /* Added for CSGL Enhancecement by parveen pichoai */
#define ERR_CSGL_DLCD_NOT_ALLOWED   1152 /* Added for CSGL Enhancecement by parveen pichoai */
#define ERR_CSGL_INSTR_NOT_VALID   1153  /* Added for CSGL Enhancecement by parveen pichoai */
#define ERR_NO_EXST_CORP   1154
#define ERR_EVT_TYP_NOT_BI_RD   1155
#define GREATER_THAN_PURCHASE_DATE_ERROR 1156
#define GREATER_THAN_RES_PUR_DATE_ERROR 1157
#define DISCLOSER_DATE_ERROR 1158
#define ERROR_RESTRICTON_ON_OTHER 1159
#define ERR_SEBIFUTURE_DATE   1160 /*Added For Data Patch by Kotubabu*/
#define ERR_RBIFUTURE_DATE 1161 /*Added For Data Patch by Kotubabu*/
#define NOT_VALID_PRIMARY_CPA 1162 /*Added For Data Patch by Ram*/
#define NOT_VALID_SECONDARY_CPA 1163 /*Added For Data Patch by Ram*/
#define NOT_VALID_FUNDACC_MNGR 1164 /*Added For Data Patch by Ram*/
#define INVALID_FATCA_RECEIVED 1165 /*Added For Data Patch by Ram*/
#define PRIMARY_CERT_PUB_ACC_MANDATORY 1166 /*Added For Data Patch by Ram*/
#define ERR_ISO_MSG_FORMAT   1167 /*Added For Data Patch by Kotubabu*/
#define ADDR_LEN_CORRECT 1168 /*Added For Data Patch by Kotubabu*/
#define DEPO_CLNID_LEN_CORRECT 1169 /*Added For Data Patch by Kotubabu*/
#define CLNMAP_DEPOID_INVALID 1170 /*Added For Data Patch by Kotubabu*/
#define INVALID_MESSAGE_TYPE 1171 /*Added For Data Patch by Kotubabu*/
#define GREATER_THAN_PUR_DATE_ERROR 1172 /*Added by Rahul company Limit*/
#define LESS_THAN_COOLING_DATE 1173 /* Added by Anuradha.S for Company Level Limit Monitoring on 19/06/2024*/
#define LESS_THAN_REALLIGN_DATE 1174 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define BETWEEN_REALLIGN_DISCLOSURE_DATE 1175 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define GREATER_THAN_SURRENDER_DATE 1176 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define BETWEEN_DISCLOSURE_SURRENDER_DATE 1177 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define ERROR_RESTRICTON_ON_OTHINST 1178 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define ERROR_REST_SURRENDER_PERIOD 1179 /* Added by Anuradha.S for Company Level Limit Monitoring on 20/06/2024*/
#define ERR_SCRPT_LIMIT_VAL 1180 /*T0 changes BY rahul6*/
#define ERR_SETL_TY_BLK 1181  /*T0 changes BY Denish*/
#define ERR_NT_INS_EXCH 1182  /*T0 changes BY Denish*/