#
# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5
# @(#)Module: Makefile $Revision:   1.0.1.6  $ $Date:   09 Jan 2010 15:35:28  $
#
#

IC_ENVPRECOMP_PATH	= ${PWD}
IC_GCC_PATH	= /icustody/gcc-4.0.2/ashdir
include   ${IC_ENVPRECOMP_PATH}/env_precomp.mk
include   ${INTL_ROOT_PATH}/intl_sun.cfg
#include 	${ORACLE_HOME}/precomp/lib/env_precomp.mk

.SUFFIXES: .pc .c .o

#Following 3 lines are used only for Linux Migration OS
INCLUDES=sys_include=$(ORACLE_HOME)/precomp/public  sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/include sys_include=/usr/include/linux sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/lib64 sys_include=/usr/include/c++/4.8.5/tr1 sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include ltype=short
PROCFLG = $(INCLUDES)
INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE CODE=ANSI DEFINE=__x86_64__ define=OS_LINUX proc

#Following line is used only for AIX OS
#INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE

THREADS_OPTION = threads=no
#Following line is used only for AIX OS
#DEBUG		= -g -maix64 -B ${IC_GCC_PATH}/gcc
#Following line is used only for Linux Migration
DEBUG		= -g -m64 -B ${IC_GCC_PATH}/gcc
INCENV		= -I.
CDEFS = -Dunix -D_ALL_SOURCE
#Following line is used only for AIX OS
#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT  -Wall
#Following line is used only for Linux Migration
CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT -DOS_LINUX -Wall

ANSI_FLAGS	= -Aa -D_POSIX_SOURCE
HP_FLAGS	= -D_REENTRANT -D_POSIX_D10_THREADS -D_HPUX_SOURCE

LIBS      = -L/usr/lib/64 -ldce -lm -L$(LIBHOME) $(PROLDLIBS)
NON_DCE_LIBS = -L$(LIBHOME) $(PROLDLIBS)
# When compiling/linking on HP-UXv9.X systems use:
#LDFLAGS         = ${DEBUG} -Wl,-Bimmediate -Wl,-Bnonfatal
# When compiling/linking on HP-UXv10.X systems, use the following:
LDFLAGS        = ${DEBUG} -D_REENTRANT

PROGRAMS	=  DL_BkDtDL DL_SetlGlobal DL_RstDL Seccodchg_Auth Posn_MoveToHis CpyData Monthly_State Chk_OpenBatch Mothly_Close M_Arch D_RstSeqNo M_RstSeqNo Y_RstSeqNo CA_Trans_Settle      

#Removed from MT_Makefile as cleaning activity- 18th July 2019
#PROGRAMS= CR_RstCLH CLHHof Prod_Hf CR_AuthSecConv DL_AutoConf Prnt_MF CR_IAAcc MarkDLFail CR_AE Rst_MF UP_MrktPr ExpBondDel TaxHf UP_CshBal ConGent_AE SCFRpt CustDetHof  Core_GrAccent LocalRep_PO DL_AutoSetl 

COMMON_OBJS = 	CntryCondFun.o\
					DateFunctions.o\
					Intl_ProcErrorMsg.o\
					Intl_ErrorMsg.o\
					RtvSysDt.o\
					RtvSysParm.o\
					CO_ReadToken.o\
					CO_ProcLog.o\
					RtvNextSeqNumber.o\
					HolidayFun.o\
					ChkCodeValid.o\
					CO_ProcPrnt.o\
					CO_Proc_DBRptIns.o\
					Intl_Customize.o\
					CO_PrntLine.o\
					Intl_Common.o\
            				CR_ProgRestartFn.o\
					EI_SMICommon.o

MESSAGE_OBJS =       MS_FormaterCommon_A.o\
                     IV_MessageEntry.o\
                     IV_Common_A.o\
                     IV_CntlParam.o\
                     MS_FormaterCommon.o\
                     MS_FormaterCommon_B.o\
                     IV_BillGenFn_G.o

CLH_RESET_OBJS =	CR_RstCLHGlobal.o\
						CR_ProcInstrRound.o\
						RtvInstrFldVal.o

BCKDTD_SETTLE_OBJS = DL_ProcHisBkDtSetl.o\
						CA_Block_type.o\
							DL_ProcBkDtSetl.o

C_CZAUTOSETTLE_OBJS	= 	DL_ProcAutoSetl.o\
								DL_ProcDL_D.o\
								CO_ChkLoc.o\
								DL_ProcDL.o\
								CO_ValidationFn.o\
								CR_ProcInstrRound.o\
								IV_Common_A.o\
								DL_ChkDLDel.o\
								IV_MessageStat.o\
								DL_ProcDL_A.o\
								IV_Base.o\
								DL_ProcDL_E.o\
								DL_ProcDL_F.o\
								IV_CntlParam.o\
								IV_MessageEntry.o\
								MS_FormaterCommon.o\
								IV_MessageLog.o\
								RtvInstrFldVal.o\
								CO_Rtv_Token.o\
								MS_FormaterCommon_A.o\
								MS_FormaterCommon_B.o\
								IV_BillGenFn_G.o\
								CR_ProcOrd.o\
								MT_ProcDL_A.o\
                                                                CO_ChkAcc.o\
								CO_ChkPty.o\
								RtvAccFieldFn.o\
								CO_RtvFldValFn.o\
								CR_ModMQFn.o\
								CA_CreateDL.o\
								CA_Block_type.o\
								CA_Common.o\
								CO_ChkMastChldDet.o\
								Co_Chkcompany.o\
								CO_Common.o\
								CR_CCSPendDLUpdate.o

CLH_HANDOFF_OBJS	=	CR_GenCLHf.o\
							c_bdbclh_tr.o\
							c_bdbclh_hu.o

EOD_PROD_HOFF_OBJS	=	c_bdbeodpro.o\
							Function_Batch.o

SECCONV_AUTH_OBJS	=	CR_ProcInstrCodAuth.o\
							RtvAccFieldFn.o\
							DL_ProcDL.o\
							DL_ProcDL_A.o\
							DL_ProcDL_E.o\
							RtvInstrFldVal.o\
							MT_ProcDL_A.o\
							CO_ChkPty.o\
							CO_RtvFldValFn.o\
							CO_ChkAcc.o\
							CO_ChkCcy.o\
							CO_ChkLoc.o\
							CO_ChkInstr.o\
							DL_ChkDLDel.o\
							MS_FormaterCommon_A.o\
							MS_FormaterCommon_B.o\
							IV_MessageEntry.o\
							IV_Common_A.o\
							IV_CntlParam.o\
							MS_FormaterCommon.o\
							IV_BillGenFn_G.o\
							IV_MessageStat.o\
							CR_ProcInstrRound.o\
							DL_ProcDL_F.o\
							CR_ProcOrd.o\
							CR_ModMQFn.o\
							CO_Common.o\
							CA_CreateDL.o\
							CA_Block_type.o\
							CA_Common.o\
							CO_ChkMastChldDet.o\
							Co_Chkcompany.o\
							CR_CCSPendDLUpdate.o

GST_OBJS =	DL_ProcSetlGlobal.o\
				CO_ChkHol.o\
				CO_ChkAcc.o\
				CO_ChkInstr.o\
				CO_ChkCcy.o\
				CO_ChkLoc.o\
				CO_RtvFldValFn.o\
				IV_Common_A.o\
				IV_CntlParam.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_C.o\
				DL_ProcDL_D.o\
				DL_ProcDL_E.o\
				DL_ProcDL_F.o\
				RtvAccFieldFn.o\
				RtvInstrFldVal.o\
				DL_ChkDLDel.o\
				MS_FormaterCommon.o\
				MS_FormaterCommon_A.o\
				MS_FormaterCommon_B.o\
				IV_MessageEntry.o\
				IV_MessageStat.o\
				IV_BillGenFn_G.o\
				CR_ProcInstrRound.o\
				CR_ProcOrd.o\
				CR_ModMQFn.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				CR_CCSPendDLUpdate.o

CTS_OBJS =  CA_trans_Settle.o\
					CO_ChkPty.o\
            CO_ChkHol.o\
            CO_ChkAcc.o\
            CO_ChkInstr.o\
            CO_ChkCcy.o\
            CO_ChkLoc.o\
            CO_RtvFldValFn.o\
            IV_Common_A.o\
            IV_CntlParam.o\
            MT_ProcDL_A.o\
            DL_ProcDL.o\
            DL_ProcDL_A.o\
            DL_ProcDL_C.o\
            DL_ProcDL_D.o\
            DL_ProcDL_E.o\
            DL_ProcDL_F.o\
            RtvAccFieldFn.o\
            RtvInstrFldVal.o\
            DL_ChkDLDel.o\
            MS_FormaterCommon.o\
            MS_FormaterCommon_A.o\
            MS_FormaterCommon_B.o\
            IV_MessageEntry.o\
            IV_MessageStat.o\
            IV_BillGenFn_G.o\
            CR_ProcInstrRound.o\
            CR_ProcOrd.o\
            CR_ModMQFn.o\
            CA_CreateDL.o\
            CA_Block_type.o\
            CA_Common.o\
            CO_Common.o\
            CO_ChkMastChldDet.o\
            Co_Chkcompany.o\
				MT_ProcLocChg.o\
            DL_ProcDL_B.o\
            CR_ProcLocChg.o\
            CR_CCSPendDLUpdate.o

AMT_OBJS =	DL_ProcAutoConf.o\
				CO_ChkHol.o\
				CO_ChkAcc.o\
				CO_ChkInstr.o\
				CO_ChkCcy.o\
				CO_ChkLoc.o\
				CO_RtvFldValFn.o\
				IV_CntlParam.o\
				IV_Common_A.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_B.o\
				DL_ProcDL_E.o\
				RtvAccFieldFn.o\
				RtvInstrFldVal.o\
				DL_ChkDLDel.o\
				MS_FormaterCommon.o\
				MS_FormaterCommon_A.o\
				MS_FormaterCommon_B.o\
				IV_BillGenFn_G.o\
				IV_MessageEntry.o\
				CR_ProcInstrRound.o\
				DL_ProcDL_F.o\
				CR_ProcOrd.o\
				CR_ModMQFn.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				CO_Common.o\
				CR_CCSPendDLUpdate.o

GST_RESET_OBJS =	DL_RstDLSetl.o\
						DL_RstSetlSingle.o\
						DL_RstSetlGlobal.o\
						CR_ProcMoveToHis.o\
						DL_ProcDL.o\
						DL_ProcDL_B.o\
						DL_ProcDL_E.o\
						DL_ProcDL_F.o\
						CO_ChkAcc.o\
						CO_ChkInstr.o\
						CO_ChkCcy.o\
						CO_ChkLoc.o\
						IV_CntlParam.o\
						IV_Common_A.o\
						MS_FormaterCommon.o\
						MS_FormaterCommon_A.o\
						MS_FormaterCommon_B.o\
						IV_MessageEntry.o\
						IV_BillGenFn_G.o\
						RtvAccFieldFn.o\
						MT_ProcDL_A.o\
						CO_ChkPty.o\
						DL_ChkDLDel.o\
						RtvInstrFldVal.o\
						CO_RtvFldValFn.o\
						DL_ProcDL_A.o\
						CR_ProcInstrRound.o\
						CR_ProcOrd.o\
						CR_ModMQFn.o\
						CA_CreateDL.o\
						CA_Block_type.o\
						CA_Common.o\
						CO_ChkMastChldDet.o\
						Co_Chkcompany.o\
						CO_Common.o\
						CR_CCSPendDLUpdate.o

MANI_OBJS	=	DL_ManifoldPrnt.o\
					DL_ProcDL.o\
					DL_ProcDL_E.o\
					CO_ChkAcc.o\
					CO_ChkInstr.o\
					CO_ChkCcy.o\
					CO_ChkLoc.o\
					CR_ProcInstrRound.o\
					RtvInstrFldVal.o\
					CR_ProcOrd.o\
					CA_CreateDL.o\
					CR_ModMQFn.o\
					MT_ProcDL_A.o\
					CO_ChkPty.o\
					RtvAccFieldFn.o\
					DL_ProcDL_A.o\
					CR_CCSPendDLUpdate.o\
					DL_ChkDLDel.o\
					IV_Common_A.o\
					IV_CntlParam.o\
					CO_RtvFldValFn.o\
					IV_MessageEntry.o\
					MS_FormaterCommon_B.o\
					MS_FormaterCommon.o\
					MS_FormaterCommon_A.o\
					CA_Block_type.o\
					CA_Common.o\
					CO_ChkMastChldDet.o\
					Co_Chkcompany.o\
					CO_Common.o\
					IV_BillGenFn_G.o

SECCODCHG_AUTH_OBJS	= 	CO_ChkAcc.o\
								CO_ChkLoc.o\
								CO_ChkCcy.o\
								CO_ChkInstr.o\
								DL_ProcDL_E.o\
								DL_ProcDL.o\
								CR_DbInstrCodeChg.o\
								CR_InstrCodeChg.o\
								CR_ModAuditHis.o\
								CR_ProcInstrRound.o\
								RtvInstrFldVal.o\
								CR_ProcOrd.o\
								CA_CreateDL.o\
								CR_ModMQFn.o\
					MT_ProcDL_A.o\
					CO_ChkPty.o\
					RtvAccFieldFn.o\
					DL_ProcDL_A.o\
					CR_CCSPendDLUpdate.o\
					DL_ChkDLDel.o\
					IV_Common_A.o\
					IV_CntlParam.o\
					CO_RtvFldValFn.o\
					IV_MessageEntry.o\
					MS_FormaterCommon_B.o\
					MS_FormaterCommon.o\
					MS_FormaterCommon_A.o\
					CA_Block_type.o\
					CA_Common.o\
					CO_ChkMastChldDet.o\
					Co_Chkcompany.o\
					CO_Common.o\
					IV_BillGenFn_G.o

INACTIVE_ACC_OBJS = 	CR_ChkAccInactive.o

MarkDLFail_OBJS	=	DL_MissingDLFail.o\
						CO_ChkAcc.o\
						CO_ChkInstr.o\
						CO_ChkLoc.o\
						CO_RtvFldValFn.o\
						CO_ChkCcy.o\
						RtvAccFieldFn.o\
						RtvInstrFldVal.o\
						IV_Common_A.o\
						IV_CntlParam.o\
						MS_FormaterCommon.o\
						MS_FormaterCommon_A.o\
						MS_FormaterCommon_B.o\
						IV_BillGenFn_G.o\
						IV_MessageEntry.o\
						DL_ProcDL.o\
						DL_ProcDL_E.o\
						CR_ProcInstrRound.o\
						CR_ProcOrd.o\
						CR_ModMQFn.o\
						CA_CreateDL.o\
						CR_CCSPendDLUpdate.o\
					MT_ProcDL_A.o\
					CO_ChkPty.o\
					RtvAccFieldFn.o\
					DL_ProcDL_A.o\
					CR_CCSPendDLUpdate.o\
					DL_ChkDLDel.o\
					IV_Common_A.o\
					IV_CntlParam.o\
					CO_RtvFldValFn.o\
					IV_MessageEntry.o\
					MS_FormaterCommon_B.o\
					MS_FormaterCommon.o\
					MS_FormaterCommon_A.o\
					CA_Block_type.o\
					CA_Common.o\
					CO_ChkMastChldDet.o\
					Co_Chkcompany.o\
					CO_Common.o\
					IV_BillGenFn_G.o

CORE_ACCENT_OBJS	=	CR_GenAEntries.o\
							RtvCcyFldVal.o\
							CM_PassAccEntFn.o\
							CR_AEHf.o\
							IV_IVAccEnt.o\
							IV_BatchNoGen.o\
							IV_RtvSystemDt.o\
							IV_AEHoff.o\
							RtvMaxBatchNo.o\
							CR_AERpt.o\
						   $(MESSAGE_OBJS)

CAE_OBJS				= 	IV_CEParamFn_B.o\
							IV_IVAccEnt.o\
							IV_BatchNoGen.o\
							RtvMaxBatchNo.o\
							CM_PassAccEntFn.o\
							CR_AEHf.o\
							IV_AEHoff.o\
							CR_AERpt.o\
							IV_RtvSystemDt.o\
							$(MESSAGE_OBJS)

MOVE_POSNHIST_OBJS	=	EOD_PosToHis.o

MANI_RESET_OBJS		=	CR_RstManiPrnt.o\
								CR_DbRstManiPrnt.o\
								CR_ManPrntFn.o\
								DL_ProcDL.o\
								DL_ProcDL_E.o\
								CO_ChkLoc.o\
								CO_ChkInstr.o\
								CO_ChkAcc.o\
								CO_ChkCcy.o\
								CR_ProcInstrRound.o\
								RtvInstrFldVal.o\
								CR_ProcOrd.o\
								CA_CreateDL.o\
								CR_ModMQFn.o\
					MT_ProcDL_A.o\
					CO_ChkPty.o\
					RtvAccFieldFn.o\
					DL_ProcDL_A.o\
					CR_CCSPendDLUpdate.o\
					DL_ChkDLDel.o\
					IV_Common_A.o\
					IV_CntlParam.o\
					CO_RtvFldValFn.o\
					IV_MessageEntry.o\
					MS_FormaterCommon_B.o\
					MS_FormaterCommon.o\
					MS_FormaterCommon_A.o\
					CA_Block_type.o\
					CA_Common.o\
					CO_ChkMastChldDet.o\
					Co_Chkcompany.o\
					CO_Common.o\
					IV_BillGenFn_G.o

AUTO_MKTPRC_OBJS		=	CR_DbProcAutoMrktPr.o

EOM_CPYDATA_OBJS		=	EOM_ProcCpy.o

EOM_STM_OBJS 			=	EOM_GenMonthlyStat.o\
								CR_AERpt.o\
								IV_BillGenFn_G.o

EOD_OPNBTCH_OBJS		=	ChkOpenBatch.o

EOM_MCL_OBJS			=	CR_MonthlyClose.o\
								CR_ProcMoveToHis.o\
								DL_ProcDL.o\
								DL_ProcDL_E.o\
								CO_ChkAcc.o\
								CO_ChkInstr.o\
								CO_ChkLoc.o\
								CO_ChkCcy.o\
								CR_ProcInstrRound.o\
								RtvInstrFldVal.o\
								CR_ProcOrd.o\
								CA_CreateDL.o\
								CR_ModMQFn.o\
					MT_ProcDL_A.o\
					CO_ChkPty.o\
					RtvAccFieldFn.o\
					DL_ProcDL_A.o\
					CR_CCSPendDLUpdate.o\
					DL_ChkDLDel.o\
					IV_Common_A.o\
					IV_CntlParam.o\
					CO_RtvFldValFn.o\
					IV_MessageEntry.o\
					MS_FormaterCommon_B.o\
					MS_FormaterCommon.o\
					MS_FormaterCommon_A.o\
					CA_Block_type.o\
					CA_Common.o\
					CO_ChkMastChldDet.o\
					Co_Chkcompany.o\
					CO_Common.o\
					IV_BillGenFn_G.o

EOM_ARCH_OBJS			=	CR_Archival.o

EOM_DELEXPBOND_OBJS	=	CR_ProcExpBonds.o\
								MT_ProcInstrument.o\
								CO_ChkPty.o\
								MT_DbProcInstrument.o\
								CO_ChkInstr.o\
								CO_ChkLoc.o\
								CO_ChkCcy.o\
								IV_Common.o\
								RtvInstrFldVal.o\
								CR_ModMQFn.o\
								CO_ChkMastChldDet.o\
								CO_ChkCrdRatAgn.o\
								Co_Chkcompany.o

EOM_TAX_HOFF_OBJS	=	EOM_ProcMisDL.o

UP_CshBal_OBJS =	UP_CashBalance.o

EOD_RSTSEQNO_OBJS	=	EOD_DbRstSeqNo.o\
							CR_ModMQFn.o

EOM_RSTSEQNO_OBJS	=	EOM_DbRstSeqNo.o

EOY_RSTSEQNO_OBJS	=	EOY_DbRstSeqNo.o

SCFREPORTGEN_OBJS =  CR_SetlCashFlRpt.o\
							CR_AERpt.o\
							IV_BillGenFn_G.o

CUST_DETFILE_OBJS =  CR_GenCustDetHf.o

CORE_GRACCENT_OBJS=  c_bdbgracc.o\
							CM_GRAccEnt.o\
							IV_AEHoff.o\
							CR_AERpt.o\
							IV_BillGenFn_G.o

LOCALREP_PO_OBJS	=	CR_ModLRPos.o\
							CR_LocalRpt.o\
							CR_ProcLocalRpt.o\
							CO_RtvFldValFn.o\
							CR_ProcInstrRound.o\
							RtvInstrFldVal.o

CR_RstCLH_OFILES		=	$(CLH_RESET_OBJS)\
								$(COMMON_OBJS)

DL_BkDtDL_OFILES	= 	$(BCKDTD_SETTLE_OBJS)\
								$(COMMON_OBJS)

DL_AutoSetl_OFILES	= 	$(C_CZAUTOSETTLE_OBJS)\
								$(COMMON_OBJS)


CLHHof_OFILES	= 	$(CLH_HANDOFF_OBJS)\
								$(COMMON_OBJS)

Prod_Hf_OFILES	= 	$(EOD_PROD_HOFF_OBJS)\
								$(COMMON_OBJS)

CR_AuthSecConv_OFILES	= 	$(SECCONV_AUTH_OBJS)\
								$(COMMON_OBJS)

DL_SetlGlobal_OFILES	= 	$(GST_OBJS)\
								$(COMMON_OBJS)

CA_Trans_Settle_OFILES  =  $(CTS_OBJS)\
                        $(COMMON_OBJS)

DL_AutoConf_OFILES	= 	$(AMT_OBJS)\
							$(COMMON_OBJS)

DL_RstDL_OFILES	= 	$(GST_RESET_OBJS)\
							$(COMMON_OBJS)

Prnt_MF_OFILES =  $(MANI_OBJS)\
							$(COMMON_OBJS)

Seccodchg_Auth_OFILES = $(SECCODCHG_AUTH_OBJS)\
								$(COMMON_OBJS)

CR_IAAcc_OFILES = 	$(INACTIVE_ACC_OBJS)\
								$(COMMON_OBJS)

MarkDLFail_OFILES = 	$(MarkDLFail_OBJS)\
						$(COMMON_OBJS)

CR_AE_OFILES = 	$(CORE_ACCENT_OBJS)\
								$(COMMON_OBJS)

CAE_OFILES = 	$(CAE_OBJS)\
					$(COMMON_OBJS)

Posn_MoveToHis_OFILES	=	$(MOVE_POSNHIST_OBJS)\
								$(COMMON_OBJS)

Rst_MF_OFILES =	$(MANI_RESET_OBJS)\
							$(COMMON_OBJS)

Auto_Mktprc_OFILES = $(AUTO_MKTPRC_OBJS)\
							$(COMMON_OBJS)

CpyData_OFILES =	$(EOM_CPYDATA_OBJS)\
							$(COMMON_OBJS)

Monthly_State_OFILES		 = $(EOM_STM_OBJS)\
							$(COMMON_OBJS)

Chk_OpenBatch_OFILES = $(EOD_OPNBTCH_OBJS)\
							$(COMMON_OBJS)

Mothly_Close_OFILES		 = $(EOM_MCL_OBJS)\
							$(COMMON_OBJS)

M_Arch_OFILES	 = $(EOM_ARCH_OBJS)\
							$(COMMON_OBJS)

ExpBondDel_OFILES = $(EOM_DELEXPBOND_OBJS)\
								$(COMMON_OBJS)

TaxHf_OFILES	=	$(EOM_TAX_HOFF_OBJS)\
								$(COMMON_OBJS)

UP_CshBal_OFILES	=	$(UP_CshBal_OBJS)\
								$(COMMON_OBJS)

D_RstSeqNo_OFILES	=	$(EOD_RSTSEQNO_OBJS)\
								$(COMMON_OBJS)

M_RstSeqNo_OFILES	=	$(EOM_RSTSEQNO_OBJS)\
								$(COMMON_OBJS)

Y_RstSeqNo_OFILES	=	$(EOY_RSTSEQNO_OBJS)\
								$(COMMON_OBJS)

SCFRpt_OFILES  =  $(SCFREPORTGEN_OBJS)\
								$(COMMON_OBJS)

CustDetHof_OFILES  =  $(CUST_DETFILE_OBJS)\
								$(COMMON_OBJS)


Core_GrAccent_OFILES =  $(CORE_GRACCENT_OBJS)\
								$(COMMON_OBJS)

LocalRep_PO_OFILES	=	$(LOCALREP_PO_OBJS)\
								$(COMMON_OBJS)


all:		objects ${PROGRAMS}
objects:	${CR_RstCLH_OFILES} ${DL_BkDtDL_OFILES} ${CLHHof_OFILES} ${CR_AuthSecConv_OFILES} ${DL_SetlGlobal_OFILES} ${DL_AutoConf_OFILES} ${DL_RstDL_OFILES} ${Prnt_MF_OFILES} ${Seccodchg_Auth_OFILES} ${CR_IAAcc_OFILES} ${MarkDLFail_OFILES} ${CR_AE_OFILES} ${CAE_OFILES} ${Posn_MoveToHis_OFILES} ${Rst_MF_OFILES} ${Auto_Mktprc_OFILES} ${CpyData_OFILES} ${Chk_OpenBatch_OFILES} ${E OM_Mcl_OFILES} ${M_Arch_OFILES} ${ExpBondDel_OFILES} ${TaxHf_OFILES} ${UP_CshBal_OFILES} ${D_RstSeqNo_OFILES} ${M_RstSeqNo_OFILES} ${Y_RstSeqNo_OFILES} ${SCFRpt_OFILES} ${CustDetHof_OFILES} ${Prod_Hf_OFILES} ${Core_GrAccent_OFILES} ${LOCALREP_PO_OBJS} ${DL_AutoSetl_OFILES} ${CA_Trans_Settle_OFILES}

fresh:		clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
       #$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

CtxManagenment.o:CM_CtxMgmt.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${CR_RstCLH_OFILES} ${DL_BkDtDL_OFILES} ${CLHHof_OFILES} ${Prod_Hf_OFILES} ${CR_AuthSecConv_OFILES} ${DL_SetlGlobal_OFILES} ${DL_AutoConf_OFILES} ${DL_RstDL_OFILES} ${Prnt_MF_OFILES} ${Seccodchg_Auth_OFILES} ${CR_IAAcc_OFILES} ${MarkDLFail_OFILES} ${CR_AE_OFILES} ${CAE_OFILES} ${Posn_MoveToHis_OFILES} ${Rst_MF_OFILES} ${Auto_Mktprc_OFILES} ${CpyData_OFILES} ${E OD_OpnBtch_OFILES} ${Mothly_Close_OFILES} ${M_Arch_OFILES} ${ExpBondDel_OFILES} ${TaxHf_OFILES} ${UP_CshBal_OFILES} ${D_RstSeqNo_OFILES} ${M_RstSeqNo_OFILES} ${Y_RstSeqNo_OFILES} ${SCFRpt_OFILES} ${CustDetHof_OFILES} ${PROGRAMS} ${Core_GrAccent_OFILES} ${LocalRep_PO_OFILES} ${DL_AutoSetl_OFILES} ${CA_Trans_Settle_OFILES}

clobber:	clean
	rm -f a.out core ERRS make.out *~

CR_RstCLH:	${CR_RstCLH_OFILES}
	$(CC) ${LDFLAGS} ${CR_RstCLH_OFILES} ${NON_DCE_LIBS} -o $@
DL_BkDtDL:	${DL_BkDtDL_OFILES}
	$(CC) ${LDFLAGS} ${DL_BkDtDL_OFILES} ${NON_DCE_LIBS} -o $@
DL_AutoSetl:	${DL_AutoSetl_OFILES}
	$(CC) ${LDFLAGS} ${DL_AutoSetl_OFILES} ${NON_DCE_LIBS} -o $@
CLHHof:	${CLHHof_OFILES}
	$(CC) ${LDFLAGS} ${CLHHof_OFILES} ${NON_DCE_LIBS} -o $@
Prod_Hf:	${Prod_Hf_OFILES}
	$(CC) ${LDFLAGS} ${Prod_Hf_OFILES} ${NON_DCE_LIBS} -o $@
CR_AuthSecConv:	${CR_AuthSecConv_OFILES}
	$(CC) ${LDFLAGS} ${CR_AuthSecConv_OFILES} ${NON_DCE_LIBS} -o $@
DL_SetlGlobal:	${DL_SetlGlobal_OFILES}
	$(CC) ${LDFLAGS} ${DL_SetlGlobal_OFILES} ${NON_DCE_LIBS} -o $@
CA_Trans_Settle:  ${CA_Trans_Settle_OFILES}
	$(CC) ${LDFLAGS} ${CA_Trans_Settle_OFILES} ${NON_DCE_LIBS} -o $@
DL_AutoConf:	${DL_AutoConf_OFILES}
	$(CC) ${LDFLAGS} ${DL_AutoConf_OFILES} ${NON_DCE_LIBS} -o $@
DL_RstDL:	${DL_RstDL_OFILES}
	$(CC) ${LDFLAGS} ${DL_RstDL_OFILES} ${NON_DCE_LIBS} -o $@
Prnt_MF:	${Prnt_MF_OFILES}
	$(CC) ${LDFLAGS} ${Prnt_MF_OFILES} ${NON_DCE_LIBS} -o $@
Seccodchg_Auth:	${Seccodchg_Auth_OFILES}
	$(CC) ${LDFLAGS} ${Seccodchg_Auth_OFILES} ${NON_DCE_LIBS} -o $@
CR_IAAcc:	${CR_IAAcc_OFILES}
	$(CC) ${LDFLAGS} ${CR_IAAcc_OFILES} ${NON_DCE_LIBS} -o $@
MarkDLFail:	${MarkDLFail_OFILES}
	$(CC) ${LDFLAGS} ${MarkDLFail_OFILES} ${NON_DCE_LIBS} -o $@
CR_AE:	${CR_AE_OFILES}
	$(CC) ${LDFLAGS} ${CR_AE_OFILES} ${NON_DCE_LIBS} -o $@
ConGent_AE:	${CAE_OFILES}
	$(CC) ${LDFLAGS} ${CAE_OFILES} ${NON_DCE_LIBS} -o $@
Posn_MoveToHis:	${Posn_MoveToHis_OFILES}
	$(CC) ${LDFLAGS} ${Posn_MoveToHis_OFILES} ${NON_DCE_LIBS} -o $@
Rst_MF:	${Rst_MF_OFILES}
	$(CC) ${LDFLAGS} ${Rst_MF_OFILES} ${NON_DCE_LIBS} -o $@
UP_MrktPr: ${Auto_Mktprc_OFILES}
	$(CC) ${LDFLAGS} ${Auto_Mktprc_OFILES} ${NON_DCE_LIBS} -o $@
CpyData: ${CpyData_OFILES}
	$(CC) ${LDFLAGS} ${CpyData_OFILES} ${NON_DCE_LIBS} -o $@
Monthly_State:	${Monthly_State_OFILES}
	$(CC) ${LDFLAGS} ${Monthly_State_OFILES} ${NON_DCE_LIBS} -o $@
Chk_OpenBatch: ${Chk_OpenBatch_OFILES}
	$(CC) ${LDFLAGS} ${Chk_OpenBatch_OFILES} ${NON_DCE_LIBS} -o $@
Mothly_Close: ${Mothly_Close_OFILES}
	$(CC) ${LDFLAGS} ${Mothly_Close_OFILES} ${NON_DCE_LIBS} -o $@
M_Arch: ${M_Arch_OFILES}
	$(CC) ${LDFLAGS} ${M_Arch_OFILES} ${NON_DCE_LIBS} -o $@
ExpBondDel: ${ExpBondDel_OFILES}
	$(CC) ${LDFLAGS} ${ExpBondDel_OFILES} ${NON_DCE_LIBS} -o $@
TaxHf:	${TaxHf_OFILES}
	$(CC) ${LDFLAGS} ${TaxHf_OFILES} ${NON_DCE_LIBS} -o $@
UP_CshBal:	${UP_CshBal_OFILES}
	$(CC) ${LDFLAGS} ${UP_CshBal_OFILES} ${NON_DCE_LIBS} -o $@
D_RstSeqNo:	${D_RstSeqNo_OFILES}
	$(CC) ${LDFLAGS} ${D_RstSeqNo_OFILES} ${NON_DCE_LIBS} -o $@
M_RstSeqNo:	${M_RstSeqNo_OFILES}
	$(CC) ${LDFLAGS} ${M_RstSeqNo_OFILES} ${NON_DCE_LIBS} -o $@
Y_RstSeqNo:	${Y_RstSeqNo_OFILES}
	$(CC) ${LDFLAGS} ${Y_RstSeqNo_OFILES} ${NON_DCE_LIBS} -o $@
SCFRpt:	${SCFRpt_OFILES}
	$(CC) ${LDFLAGS} ${SCFRpt_OFILES} ${NON_DCE_LIBS} -o $@
CustDetHof:	${CustDetHof_OFILES}
	$(CC) ${LDFLAGS} ${CustDetHof_OFILES} ${NON_DCE_LIBS} -o $@
Core_GrAccent:	${Core_GrAccent_OFILES}
	$(CC) ${LDFLAGS} ${Core_GrAccent_OFILES} ${NON_DCE_LIBS} -o $@
LocalRep_PO:	${LocalRep_PO_OFILES}
	$(CC) ${LDFLAGS} ${LocalRep_PO_OFILES} ${NON_DCE_LIBS} -o $@

$(CR_RstCLH_OFILES)		: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h CA_InterFace.h
$(DL_BkDtDL_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(DL_AutoSetl_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h CA_InterFace.h SMI_InterFace.h
$(CLHHof_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h CA_InterFace.h
$(Prod_Hf_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CR_AuthSecConv_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h SMI_InterFace.h
$(DL_SetlGlobal_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h SMI_InterFace.h
$(CA_Trans_Settle_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h SMI_InterFace.h
$(DL_AutoConf_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h SMI_InterFace.h
$(DL_RstDL_OFILES) 		: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h SMI_InterFace.h
$(Prnt_MF_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Seccodchg_Auth_OFILES): CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CR_IAAcc_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(MarkDLFail_OFILES) 		: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CR_AE_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CAE_OFILES) 				: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Posn_MoveToHis_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Rst_MF_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Auto_Mktprc_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CpyData_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Chk_OpenBatch_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Mothly_Close_OFILES) 		: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Monthly_State_OFILES)			: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(M_Arch_OFILES) 		: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(ExpBondDel_OFILES): CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(TaxHf_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(UP_CshBal_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(D_RstSeqNo_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(M_RstSeqNo_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Y_RstSeqNo_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(SCFRpt_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(CustDetHof_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(Core_GrAccent_OFILES) : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h
$(LocalRep_PO_OFILES) 	: CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h

CO_HostStructdef.h	: CO_IndStructdef.h CO_OthStructdef.h CO_Externdef.h CO_Commdef.h MT_Interface.h DL_Interface.h CR_Common.h

