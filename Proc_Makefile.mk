#
# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5
# @(#)Module: Makefile $Revision:   1.0.1.17  $ $Date:   11 Dec 2009 14:52:02  $
#
#
#include 	${ORACLE_HOME}/precomp/lib/env_precomp.mk
IC_ENVPRECOMP_PATH	= ${PWD}
IC_GCC_PATH	= /icustody/gcc-4.0.2/ashdir
include   ${IC_ENVPRECOMP_PATH}/env_precomp.mk
include   ${INTL_ROOT_PATH}/intl_sun.cfg
.SUFFIXES: .pc .c .o

#Following 3 lines are used only for Linux Migration OS
INCLUDES=sys_include=$(ORACLE_HOME)/precomp/public  sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/include sys_include=/usr/include/linux sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/lib64 sys_include=/usr/include/c++/4.8.5/tr1 sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include ltype=short
PROCFLG = $(INCLUDES)
INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE CODE=ANSI DEFINE=__x86_64__ define=OS_LINUX proc

#Following line is used only for AIX OS
#INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE DEFINE=__64BIT__ proc

THREADS_OPTION = threads=no
#Following line is used only for AIX OS
#DEBUG		= -g -maix64 -B ${IC_GCC_PATH}/gcc
#Following line is used only for Linux Migration
DEBUG		= -g -m64 -B ${IC_GCC_PATH}/gcc

INCENV		= -I. -I${ORACLE_HOME}/precomp/public
CDEFS = -Dunix -D_ALL_SOURCE
#Following line is used only for AIX OS
#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT   -Wall
#Following line is used only for Linux Migration
CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT -DOS_LINUX -Wall
ANSI_FLAGS	= -Aa -D_POSIX_SOURCE
HP_FLAGS	= -D_REENTRANT -D_POSIX_D10_THREADS -D_HPUX_SOURCE
LIBS      = -L/usr/lib/64 -ldce -lm -L$(LIBHOME) $(PROLDLIBS)
NON_DCE_LIBS = -L$(LIBHOME) $(PROLDLIBS)
# Original MQ_LIBS PATH ... MQ_LIBS = -L$(LIBHOME) -L/opt/mqm/lib -lmqm $(PROLDLIBS) -L${SYBASE}/lib -ltccom -ltcpub -lct -lsrv -ltcl -linsck  -lcs -lcomn -lintl
MQ_LIBS = -L$(LIBHOME) -L/opt/mqm/lib -lmqm $(PROLDLIBS) -L${SYBASE}/lib -lintl
# When compiling/linking on HP-UXv9.X systems use:
#LDFLAGS         = ${DEBUG} -Wl,-Bimmediate -Wl,-Bnonfatal
# When compiling/linking on HP-UXv10.X systems, use the following:
LDFLAGS        = ${DEBUG} -D_REENTRANT
PROGRAMS	= MS_SCH DL_Setl_Rpt CA_GenEntitl IV_BillPrnt IV_BillDeliver IV_BillResend CA_ProcPymt CA_GenEvt_A CA_GenEvt_B CA_IntimateEvt CA_SplitPymt PROC_EOD PROC_BOD PROC_EOM IV_BillGenerate CA_AEGenetae CA_GenerateAlert CA_Arch CA_PymtGlobal MS_Transmitter  MS_TransmitterB CA_BODCastMsg  IV_AEGenerate IV_PayAEGenerate  IV_Arch  CM_BatchDaemon PROC_EOY EOD_CHECK MS_MsInterface CA_CustInstr DL_SetlDtRpt UpdDaemonStat IV_BillPrnt_EMINV IV_BillPrnt_DETINV  Proc_Eod   ExchgOrderMatch DL_BCN_MAP NIS_BID_Auth DL_AutoMarkShortage DL_EO_ReadyForOblig NIS_APPLN_Auth RegRept DL_FundObligGen DL_GenAE MS_EmailTransmitter GenReport dl_exchobligation_rpt DL_GenDPInst DL_PassDPInst DL_MAP_RESET DL_SETL_BLK_REL  IV_BillPrnt_HTML DL_ExchOblig_rec  GenerateConfFile SplitFiles CA_RecEntitl MS_Arch MS_IncomingMsRpt MS_MAnMsgRpt MS_MSG_RESEND MS_MsgStatRpt   MT_IntUpdt Msg548 MFRegReport CA_FloatRate DL_MarkShortAut IV_BillPrnt_DETHTML FundObligRep MS_MessageMover DLUNMAPPED548 RBIRept DL_SOH_Rec FundObligScrip DynamicReport DL_PassAE CA_PassAccEnt IV_ProvBill  IV_PrntSummary IV_PrntDetail IV_PrntTransDetail IV_PayAEPass IV_PassAE IV_Pymnt_Auth IV_PrntCustDetail DL_SLBREV EarlyPyinRpt  I_INCCOMMRPT EOD_Handover EPI_AccountEntries

#Removed from Proc_MakeFile as cleaning activity- 18th July 2019
#CA_ENRARpt CA_ProcConv CA_RedomEvt CM_ConvScheduler CR_DLDtPosRpt CR_DwHfDly C_AutoSettHU Conv_Dec_Len Conv_Excptn Conv_Safek Conv_Trade DL_BrkConfRpt DL_Mark_Recon Del_BaseNo EI_InitCCS EI_InitSMI EM_ConvAcc EM_ConvBilling EM_ConvPendTrans EM_ConvSec EOD_Recon GR_PASS INT_AUTOSYS IV_GPSSGenerate IV_PassHoff MS_Arch MS_CCSFailRpt NBHMonRep OBLIGATIONDUMP Rep_NCH_Hun Rtv_UniqRefno RuReconReport SAMPLE_CUR Setl_Info UP_GFCID UP_RmtDL

COMMON_OBJS =			Intl_ProcErrorMsg.o\
							Intl_ErrorMsg.o\
							RtvSysDt.o\
							CntryCondFun.o\
							CO_ReadToken.o\
							CO_ProcLog.o\
                                                        Intl_Customize.o\
							RtvSysParm.o\
							DateFunctions.o\
							HolidayFun.o\
							ChkCodeValid.o\
							CO_ProcPrnt.o\
							RtvNextSeqNumber.o\
							CO_Proc_DBRptIns.o\
							CA_Block_type.o\
							Intl_Common.o\
							EI_SMICommon.o\
							Co_Chkcompany.o\
							CO_Common.o\
							CO_ChkMastChldDet.o
MESSAGE_OBJS =			MS_FormaterCommon_A.o\
							IV_MessageEntry.o\
							IV_Common_A.o\
							IV_CntlParam.o\
							MS_FormaterCommon.o\
							MS_FormaterCommon_B.o\
							IV_BillGenFn_G.o

CR_DWTran_OFILES   =  CO_ProcLog.o\
								CO_ReadToken.o\
                                                                Intl_Customize.o\
								Intl_ProcErrorMsg.o\
								Intl_ErrorMsg.o\
								CO_Proc_DBRptIns.o\
								RtvSysDt.o\
								DateFunctions.o\
								Proc_RestartLogic.o\
								C_MsgQueue.o\
								Intl_Common.o\
								C_MsgQueue1.o

EPI_AccountEntries_OFILES     = EPI_AccountEntries.o\
                                                 DL_ProcDL_A.o\
                                                 DL_ProcDL_D.o\
                                                 DL_ProcDL_F.o\
                                                 CR_ModMQFn.o\
                                                 DL_ProcDL.o\
                                                 MT_ProcDL_A.o\
                                                 CO_ChkPty.o\
                                                 RtvAccFieldFn.o\
                                                 CO_RtvFldValFn.o\
                                                 IV_CntlParam.o\
                                                 CO_ValidationFn.o\
                                                 CR_CCSPendDLUpdate.o\
                                                 IV_MessageStat.o\
                                                 IV_Common_A.o\
                                                 CO_ChkLoc.o\
                                                 CR_ProcOrd.o\
                                                 DL_ChkDLDel.o\
                                                 CR_ProcInstrRound.o\
                                                 IV_MessageEntry.o\
                                                 MS_FormaterCommon_A.o\
                                                 MS_FormaterCommon_B.o\
                                                 RtvInstrFldVal.o\
                                                 IV_BillGenFn_G.o\
                                                 MS_FormaterCommon.o\
						 CR_ProgRestartFn.o\
                                                DL_Mod_BifDet.o\
                                                DL_Upd_BifDet.o\
                                                IV_IVAccEnt.o\
                                                $(COMMON_OBJS)

CA_GenEntitl_OFILES = 	CA_GenEntitl.o\
							CA_Common.o\
							CO_ChkAcc.o\
							CO_ChkInstr.o\
							CA_EntitlMod.o\
							CR_ProcInstrRound.o\
							RtvInstrFldVal.o\
							CR_ProgRestartFn.o\
							CA_FixRate.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)

EI_InitSMI_OFILES = 	EI_InitSMI.o\
							Function_Batch.o\
							$(COMMON_OBJS)

EI_InitCCS_OFILES = 	EI_InitCCS.o\
							Function_Batch.o\
							CR_CCSPendDLUpdate.o\
							$(COMMON_OBJS)

CA_CustInstr_OFILES   =  CA_CustInstruction.o\
								$(COMMON_OBJS)\
								$(MESSAGE_OBJS)


IV_BillPrnt_OFILES =  IV_ServChargeFn.o\
							IV_ServBasisFn.o\
							IV_ServicesFn.o\
							IV_OtherServ_B.o\
							IV_TransacFn.o\
							IV_ExgRtFn.o\
							IV_AccSetup.o\
							IV_PRO_SGENSTATFn.o\
							IV_RoundFn.o\
							IV_CRCommon_A.o\
							IV_Prnt.o\
							IV_PrntSctHdr.o\
							IV_PrntBillAcc.o\
							IV_PrntBill.o\
							IV_PrntHdr.o\
							IV_PrntCust.o\
							IV_PrntPos.o\
							IV_PrntDL.o\
							IV_PrntCash.o\
							IV_PrntOth.o\
							IV_PrntFtr.o\
							CO_PrntLine.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)\
							CO_ProcFileName.o\
							CR_AERpt.o

IV_BillPrnt_EMINV_OFILES =   IV_ServChargeFn.o\
									IV_ServBasisFn.o\
									IV_ServicesFn.o\
									IV_OtherServ_B.o\
									IV_TransacFn.o\
									IV_ExgRtFn.o\
									IV_AccSetup.o\
									IV_PRO_SGENSTATFn.o\
									IV_RoundFn.o\
									IV_CRCommon_A.o\
									IV_Prnt_Email.o\
									IV_PrntSctHdr_Email.o\
									IV_PrntBillAcc_Email.o\
									IV_PrntBill_Email.o\
									IV_PrntConvPg.o\
									IV_PrntHdr_Email.o\
									IV_PrntCust_Email.o\
									IV_PrntDL_Email.o\
									IV_PrntCash_Email.o\
									IV_PrntCA_Email.o\
									IV_PrntOth_Email.o\
									IV_PrntFtr_Email.o\
									CO_PrntLine.o\
									$(COMMON_OBJS)\
									$(MESSAGE_OBJS)\
									CO_ProcFileName.o\
									CR_AERpt.o

IV_BillPrnt_HTML_OFILES =   IV_ServChargeFn.o\
									 IV_ServBasisFn.o\
									 IV_ServicesFn.o\
									 IV_OtherServ_B.o\
									 IV_TransacFn.o\
									 IV_ExgRtFn.o\
									 IV_AccSetup.o\
									 IV_PRO_SGENSTATFn.o\
									 IV_RoundFn.o\
									 IV_CRCommon_A.o\
									 IV_Prnt_Web.o\
									 IV_PrntSctHdr_Web.o\
									 IV_PrntBillAcc_Web.o\
									 IV_PrntBill_Web.o\
									 IV_PrntCovPg_Web.o\
									 IV_PrntHdr_Web.o\
									 IV_PrntCust_Web.o\
									 IV_PrntDL_Web.o\
									 IV_PrntCash_Web.o\
									 IV_PrntCA_Web.o\
									 IV_PrntOth_Web.o\
									 IV_PrntFtr_Web.o\
									 CO_PrntLine.o\
									 IV_PrntDepo_Web.o\
									 $(COMMON_OBJS)\
									 $(MESSAGE_OBJS)\
									 CO_ProcFileName.o\
									 CR_AERpt.o

IV_BillPrnt_DETINV_OFILES =  IV_ServChargeFn.o\
									IV_ServBasisFn.o\
									IV_ServicesFn.o\
									IV_OtherServ_B.o\
									IV_TransacFn.o\
									IV_ExgRtFn.o\
									IV_AccSetup.o\
									IV_PRO_SGENSTATFn.o\
									IV_RoundFn.o\
									IV_CRCommon_A.o\
									IV_Prnt_Detail.o\
									IV_PrntSctHdr_Detail.o\
									IV_PrntBillAcc_Detail.o\
									IV_PrntBill_Detail.o\
									IV_PrntHdr_Detail.o\
							      IV_PrntPos_Detail.o\
									IV_PrntDL_Detail.o\
									IV_PrntFtr_Detail.o\
									CO_PrntLine.o\
									$(COMMON_OBJS)\
									$(MESSAGE_OBJS)\
									CO_ProcFileName.o\
									CR_AERpt.o

IV_BillPrnt_DETHTML_OFILES=IV_ServChargeFn.o\
									IV_ServBasisFn.o\
									IV_ServicesFn.o\
									IV_OtherServ_B.o\
									IV_TransacFn.o\
									IV_ExgRtFn.o\
									IV_AccSetup.o\
									IV_PRO_SGENSTATFn.o\
									IV_RoundFn.o\
									IV_CRCommon_A.o\
									IV_Prnt_DetailWeb.o\
									IV_PrntSctHdr_DetailWeb.o\
									IV_PrntBillAcc_DetailWeb.o\
									IV_PrntBill_DetailWeb.o\
									IV_PrntHdr_DetailWeb.o\
									IV_PrntPos_DetailWeb.o\
									IV_PrntDL_DetailWeb.o\
									IV_PrntFtr_DetailWeb.o\
									IV_PrntDepo_DetailWeb.o\
									CO_PrntLine.o\
									$(COMMON_OBJS)\
									$(MESSAGE_OBJS)\
									CO_ProcFileName.o\
									CR_AERpt.o

IV_AEGenerate_OFILES  =  IV_RtvSystemDt.o\
						RtvMaxBatchNo.o\
						IV_PymtFn_D.o\
						IV_PymtAcc.o\
						IV_IVAccEnt.o\
						IV_BatchNoGen.o\
						IV_CRCommon_A.o\
						IV_DecodeComAcc.o\
						IV_RoundFn.o\
						IV_ServicesFn.o\
						IV_AccSetup.o\
						IV_ServChargeFn.o\
						IV_AccFn.o\
						IV_AE.o\
						IV_GenAcc.o\
						B_BlGrAccGen.o\
						CM_GRAccEnt.o\
						IV_AEHoff.o\
						CR_AERpt.o\
						IV_CntlParam_A.o\
						IV_ServBasisFn.o\
						IV_Common.o\
						$(COMMON_OBJS)\
						$(MESSAGE_OBJS)


IV_GPSSGenerate_OFILES  =  IV_RtvSystemDt.o\
						MS_CommonRoutines.o\
						IV_CRCommon_A.o\
						IV_AccSetup.o\
						IV_GenerateGPSS.o\
						CR_CDVDFile.o\
						CO_ChkAcc.o\
						RtvAccFieldFn.o\
						CO_PrntLine.o\
						IV_RoundFn.o\
						$(MESSAGE_OBJS)\
						$(COMMON_OBJS)

IV_PayAEGenerate_OFILES   =  RtvMaxBatchNo.o\
						IV_PymtFn_D.o\
						IV_RoundFn.o\
						IV_CRCommon_A.o\
						IV_GeneratePayAE.o\
						IV_PymtAcc.o\
						IV_AccFn.o\
						IV_IVAccEnt.o\
						IV_AccSetup.o\
						IV_BatchNoGen.o\
						IV_Common.o\
						$(COMMON_OBJS)\
						$(MESSAGE_OBJS)

DL_SLBREV_OFILES   =  DL_SLBReversal.o\
                      MT_ProcDL_A.o\
                      DL_ProcDL.o\
                      CO_RtvFldValFn.o\
                      MS_FormaterCommon_B.o\
                      CO_ValidationFn.o\
                      DL_Mod_BifDet.o\
                      DL_ProcDL_A.o\
                      DL_ProcDL_B.o\
                      DL_ProcDL_C.o\
                      DL_ProcDL_E.o\
                      CR_ProcOrd.o\
                      CR_CCSPendDLUpdate.o\
                      RtvInstrFldVal.o\
                      DL_ChkDLDel.o\
                      CR_ProcInstrRound.o\
                      CO_ChkLoc.o\
                      DL_Upd_BifDet.o\
                      CR_ModMQFn.o\
                      IV_Common_A.o\
                      RtvAccFieldFn.o\
                      IV_CntlParam.o\
                      MS_FormaterCommon.o\
                      IV_MessageEntry.o\
                      MS_FormaterCommon_A.o\
                      CO_ChkPty.o\
                      IV_BillGenFn_G.o\
								$(COMMON_OBJS)


IV_Arch_OFILES = IV_Arch.o\
						$(COMMON_OBJS)

RBIRept_OFILES = RBI_Report.o\
					  CR_ProgRestartFn.o\
					  $(COMMON_OBJS)

EOD_Handover_OFILES        =  EOD_HandOver.o\
                                CR_ProgRestartFn.o\
                                 $(COMMON_OBJS)

INT_AUTOSYS_OFILES      =  Intellect_autosys.o\
			   $(COMMON_OBJS)

DL_SOH_Rec_OFILES = DL_SOH_Rec.o\
					  CO_ProcFileName.o\
					  CR_ProgRestartFn.o\
					  $(COMMON_OBJS)

IV_BillDeliver_OFILES =  IV_BillDel.o\
						IV_BillDelFn.o\
						IV_BillDelFn_A.o\
						IV_BillDelFn_B.o\
						IV_BillDelFn_C.o\
						IV_LedgerFn.o\
						IV_LedgerFn_A.o\
						IV_Common_B.o\
						IV_OtherServ_B.o\
						IV_AccSetup.o\
						IV_DbPymtFn_A.o\
						IV_DbPymtFn_B.o\
						$(COMMON_OBJS)\
						$(MESSAGE_OBJS)\
						IV_Tlx.o\
						IV_PrntBill.o\
						CO_ProcFileName.o\
						IV_PrntHdr.o\
						IV_PrntFtr.o\
						IV_RoundFn.o\
						IV_ServChargeFn.o\
						IV_ServicesFn.o\
						IV_ServBasisFn.o\
						IV_PRO_SGENSTATFn.o\
						IV_TransacFn.o\
						IV_PrntCust.o\
						IV_PrntCash.o\
						IV_PrntOth.o\
						IV_PrntDL.o\
						IV_PrntSctHdr.o\
						IV_PrntPos.o\
						IV_Base.o\
						IV_MessageStat.o\
						IV_MessageLog.o\
						CO_Rtv_Token.o\
						CO_PrntLine.o\
						CR_AERpt.o\
						IV_PymtFn_A.o\
						IV_PymtFn_B.o\
						IV_AccFn.o\
							IV_PrntBillAcc.o\
							IV_AccParamFn_C.o\
							IV_AccFeeFn.o\
							IV_AccParamFn.o\
							IV_Pymnt_Mnt_A.o\
						CO_ValidationFn.o\
						ChkAudSystemOnline.o



IV_BillResend_OFILES =  IV_BillPymtCntFn.o\
						IV_RsndBill.o\
						IV_RsndBillFn_A.o\
						IV_AccSetup.o\
						IV_TransacFn.o\
						$(COMMON_OBJS)\
						$(MESSAGE_OBJS)\
						IV_OtherServ_B.o\
						IV_Tlx.o\
						IV_PrntBill.o\
						CO_ProcFileName.o\
						IV_PrntHdr.o\
						IV_PrntFtr.o\
						IV_RoundFn.o\
						IV_ServChargeFn.o\
						IV_ServicesFn.o\
						IV_ServBasisFn.o\
						IV_PRO_SGENSTATFn.o\
						IV_PrntCust.o\
						IV_PrntCash.o\
						IV_PrntOth.o\
						IV_PrntDL.o\
						IV_PrntSctHdr.o\
						IV_PrntPos.o\
						IV_MessageStat.o\
						IV_MessageLog.o\
						CO_Rtv_Token.o\
						CO_PrntLine.o\
						IV_Base.o\
						IV_PrntBillAcc.o\
						CR_AERpt.o

SETL_OBJS      =  DL_Setl_Rpt.o\
						$(COMMON_OBJS)

NIS_BID_Auth_OFILES      =  MT_NIS_BID_Auth.o\
						MT_ProcCA_NIS_BID.o\
						MT_DbProcCA_NIS_BID.o\
						MT_DbProcCA_NIS_APPLICATION.o\
						CA_ProcPopulate.o\
						$(COMMON_OBJS)

NIS_APPLN_Auth_OFILES      =  CA_NIS_Appln_Auth.o\
						MT_ProcCA_NIS_APPLICATION.o\
						MT_DbProcCA_NIS_APPLICATION.o\
						CA_ProcPopulate.o\
						$(COMMON_OBJS)

ExchgOrderMatch_OFILES      =  DL_ExchgOrderMatch.o\
										 CO_CreateReport.o\
						CR_ProgRestartFn.o\
						$(COMMON_OBJS)

DL_BCN_MAP_OFILES      =  DL_BCN_MAP.o\
								  CO_CreateReport.o\
						CR_ProgRestartFn.o\
							$(MESSAGE_OBJS)\
						$(COMMON_OBJS)
EarlyPyinRpt_OFILES	= EarlyPyinRpt.o\
				CR_ProgRestartFn.o\
				$(COMMON_OBJS)


DLUNMAPPED548_OFILES      =  DL_Unmap548.o\
						CR_ProgRestartFn.o\
							$(MESSAGE_OBJS)\
						$(COMMON_OBJS)

DL_MAP_RESET_OFILES      =  DL_MAP_RESET.o\
						CR_ProgRestartFn.o\
						$(COMMON_OBJS)

DL_SETL_BLK_REL_OFILES      =  DL_SETL_BLK_REL.o\
						CR_ProgRestartFn.o\
						$(COMMON_OBJS)

DL_Mark_Recon_OFILES      =  DL_Mark_Recon.o\
						CR_ProgRestartFn.o\
						$(COMMON_OBJS)


DL_Setl_Rpt_OFILES = $(SETL_OBJS)

Proc_Eod_OFILES =  Proc_EOD.o\
						 $(COMMON_OBJS)

AUTOJOB_MON_OBJS      =  AutoProcMonitor.o\
								 $(COMMON_OBJS)

autojob_mon_OFILES = $(AUTOJOB_MON_OBJS)

CA_ProcPymt_OFILES = 	CA_ProcPymt.o\
							CA_Common.o\
							CA_CreateDL.o\
							DL_ProcDL.o\
							DL_ProcDL_A.o\
							DL_ProcDL_B.o\
							DL_ProcDL_E.o\
							MT_ProcDL_A.o\
							CO_ChkAcc.o\
							CO_ChkPty.o\
							CO_ChkInstr.o\
							CO_ChkLoc.o\
							CO_ChkCcy.o\
							RtvAccFieldFn.o\
							RtvInstrFldVal.o\
							CO_RtvFldValFn.o\
							DL_ChkDLDel.o\
							CR_ProcInstrRound.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)\
							CR_ProcOrd.o\
							CR_ModMQFn.o\
							CR_CCSPendDLUpdate.o

CA_GenEvt_A_OFILES = 	CA_GenEvt_A.o\
							CA_Common.o\
							CO_ChkInstr.o\
							CR_ProgRestartFn.o\
							$(COMMON_OBJS)

CA_GenEvt_B_OFILES =  CA_GenEvt_B.o\
							CA_EvtMod.o\
							CO_ChkInstr.o\
							CA_Common.o\
							CR_ProgRestartFn.o\
							CA_FixRate.o\
							CO_DateFuns.o\
							$(COMMON_OBJS)

CA_SplitPymt_OFILES = CA_SplitEvt.o\
							CA_Common.o\
							CA_CreateDL.o\
							DL_ProcDL.o\
							DL_ProcDL_A.o\
							DL_ProcDL_E.o\
							DL_ProcDL_F.o\
							MT_ProcDL_A.o\
							CO_ChkPty.o\
							MT_ProcDL_B.o\
							DL_ProcDL_B.o\
							MS_MsgCommon.o\
							CR_ProcMoveToHis.o\
							CR_ProgRestartFn.o\
							CO_ChkAcc.o\
							CO_ChkInstr.o\
							CO_ChkLoc.o\
							CO_ChkCcy.o\
							RtvAccFieldFn.o\
							RtvInstrFldVal.o\
							CO_RtvFldValFn.o\
							DL_ChkDLDel.o\
							CA_GeneratePendOrdRpt.o\
							CO_PrntLine.o\
							CR_ProcInstrRound.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)\
							CR_ProcOrd.o\
							CR_ModMQFn.o\
							CR_CCSPendDLUpdate.o

CA_IntimateEvt_OFILES = CA_IntimateEvt.o\
							CA_Common.o\
							CO_ChkInstr.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)

Conv_Safek_OFILES = Conv_Safek.o\
							CA_Common.o\
							CO_ChkInstr.o\
							$(COMMON_OBJS)

Conv_Trade_OFILES = Conv_Trade.o\
							CA_Common.o\
							CO_ChkInstr.o\
							$(COMMON_OBJS)

Conv_Excptn_OFILES = Conv_Excptn.o\
							CA_Common.o\
							CO_ChkInstr.o\
							$(COMMON_OBJS)

Conv_Dec_Len_OFILES = Conv_Dec_Len.o\
							CA_Common.o\
							CO_ChkInstr.o\
							$(COMMON_OBJS)

PROC_EOD_OFILES = EodFunctions.o\
									BatchRestartLPC.o\
									$(COMMON_OBJS)

PROC_BOD_OFILES = Proc_BOD.o\
									BatchRestartLPC.o\
									$(COMMON_OBJS)

PROC_EOM_OFILES = EomFunction.o\
									BatchRestartLPC.o\
									$(COMMON_OBJS)

PROC_EOY_OFILES = EoyFunction.o\
									BatchRestartLPC.o\
									$(COMMON_OBJS)

CM_ConvScheduler_OFILES = CM_CONV.o\
									BatchRestartLPC.o\
									$(COMMON_OBJS)

CM_BatchDaemon_OFILES = CM_BatchDaemon.o\
								CR_ProgRestartFn.o\
								$(COMMON_OBJS)

IV_BillGenerate_OFILES = IV_BillGenFn.o\
							IV_BillGenFn_A.o\
							IV_BillGenFn_B.o\
							IV_BillGenFn_C.o\
							IV_BillGenFn_D.o\
							IV_BillGenFn_E.o\
							IV_BillGenFn_F.o\
							IV_BillGenFn_G.o\
							IV_PreBillProc.o\
							IV_CRCommon.o\
							IV_ServChargeFn.o\
							IV_TransacFn.o\
							IV_ServBasisFn.o\
							IV_AccParamFn.o\
							IV_AccSetup.o\
							IV_ServicesFn.o\
							IV_CntlParam.o\
							IV_SServBasisFn.o\
							IV_ParamTypeFn.o\
							IV_ExgRtFn.o\
							IV_RoundFn.o\
							$(COMMON_OBJS)\
							RtvCcyFldVal.o

GTUpload_OFILES = $(COMMON_OBJS)\
                   GTUpload.o

Daemon_Armor_OFILES = $(COMMON_OBJS)\
			Daemon_Armor.o

CA_AEGenetae_OFILES = CA_GenAE.o\
						IV_IVAccEnt.o\
						IV_BatchNoGen.o\
						RtvMaxBatchNo.o\
						CA_Common.o\
						CO_ChkInstr.o\
						CO_PrntLine.o\
						CO_Get_Narrative.o\
						CR_ProgRestartFn.o\
						$(COMMON_OBJS)

IV_PassHoff_OFILES = CA_PassAE.o\
					CR_RstContigentAE.o\
					CR_RstAEntries.o\
					IV_RtvSystemDt.o\
					IV_PymtFn_D.o\
					IV_AEHoff.o\
					IV_IVAccEnt.o\
					IV_PassAE.o\
					IV_PayPassAE.o\
					CM_PassAccEntFn.o\
					CR_AEHf.o\
					CR_AERpt.o\
					IV_RoundFn.o\
					IV_CntlParam_A.o\
					$(COMMON_OBJS)\
					$(MESSAGE_OBJS)

Del_BaseNo_OFILES		=MS_Base_Del.o\
			MS_BaseNoDel.o\
			CR_ProcBaseMnt.o\
			IV_Base.o\
			IV_MessageAddr.o\
			$(COMMON_OBJS)
			
BODAlerts_OFILES = BODAlerts.o\
				   CO_DateFuns.o\
		           CR_ProgRestartFn.o\
	               $(COMMON_OBJS)

I_MSGSCH_OFILES = MS_Schedule.o\
		$(COMMON_OBJS)\
	$(MESSAGE_OBJS)

I_MSGENT_OFILES = MS_EntryFn.o\
		CO_Rtv_Token.o\
		CR_ProcInstrRound.o\
		RtvInstrFldVal.o\
		$(COMMON_OBJS)\
	$(MESSAGE_OBJS)

MS_Arch_OFILES = MS_Arch.o\
		$(COMMON_OBJS)\
	$(MESSAGE_OBJS)

I_MSGTRAN_OFILES = MS_Trans.o\
		$(COMMON_OBJS)\
      Proc_RestartLogic.o\
		CO_FilterFn.o\
	$(MESSAGE_OBJS)

I_EMAILTRAN_OFILES = MS_Email.o\
		$(COMMON_OBJS)\
      Proc_RestartLogic.o\
		CO_FilterFn.o

I_MOVEMSG_OFILES = MS_MoveMessage.o\
		$(COMMON_OBJS)\
      Proc_RestartLogic.o\
		CO_FilterFn.o


I_MSGTRANB_OFILES = MS_Trans.o\
		$(COMMON_OBJS)\
      Proc_RestartLogic.o\
		CO_FilterFn.o\
	$(MESSAGE_OBJS)

CA_GenerateAlert_OFILES = CA_Alerts.o\
							$(COMMON_OBJS)

CA_Arch_OFILES = CA_Arch.o\
						  CA_MsgArch.o\
							 $(COMMON_OBJS)

CA_PymtGlobal_OFILES = CA_GlobalPymt.o\
                      CA_Common.o\
                      CO_ChkInstr.o\
                      $(COMMON_OBJS)

CA_BODCastMsg_OFILES = CA_Proc562Msg.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)

CA_RedomEvt_OFILES = CA_BatchRedomEvt.o\
			   CA_Common.o\
                           CO_ChkInstr.o\
				CO_PrntLine.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)

I_MANMSGREP_OFILES	=	MS_ManualMsgRpt.o\
								Proc_RestartLogic.o\
								$(COMMON_OBJS)

CA_ENRARpt_OFILES = CA_GenENRARpt.o\
								CO_PrntLine.o\
								CR_ProcInstrRound.o\
								RtvInstrFldVal.o\
								$(COMMON_OBJS)

EOD_CHECK_OFILES = CM_NeverFails.o

GR_PASS_OFILES =		CM_PassGrAE.o\
             		  	CM_GRAccEnt.o\
							CR_RstAEntries.o\
							IV_RtvSystemDt.o\
							IV_AEHoff.o\
							IV_CntlParam_A.o\
							CR_AERpt.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)

MS_IncomingMsRpt_OFILES	=	MS_IncomingRpt.o\
								CO_ProcFileName.o\
								$(COMMON_OBJS)

MS_CCSFailRpt_OFILES      = CR_CCSFailRpt.o\
				CO_ProcFileName.o\
				$(COMMON_OBJS)

RegRept_OFILES      = RR_ClntInstruction.o\
				CO_ProcFileName.o\
				CR_ProgRestartFn.o\
				CreateExcel.o\
				$(COMMON_OBJS)

DL_FundObligGen_OFILES      = DL_FundObligGen.o\
										DL_Inst_OblDtls.o\
										CR_ProgRestartFn.o\
				$(COMMON_OBJS)

GenReport_OFILES      = GenReport.o\
										IntlReports.o\
										CO_CreateReport.o\
										CR_ProgRestartFn.o\
				$(COMMON_OBJS)
DL_GenAE_OFILES      = DL_GenAE.o\
						IV_IVAccEnt.o\
						IV_BatchNoGen.o\
						RtvMaxBatchNo.o\
						CO_DateFuns.o\
						CR_ProgRestartFn.o\
						DL_ProcDL_A.o\
						 DL_ProcDL_D.o\
						 DL_ProcDL_F.o\
						 CR_ModMQFn.o\
						 DL_ProcDL.o\
						 MT_ProcDL_A.o\
						 CO_ChkPty.o\
						 RtvAccFieldFn.o\
						 CO_RtvFldValFn.o\
						 IV_CntlParam.o\
                                                 CO_ValidationFn.o\
						 CR_CCSPendDLUpdate.o\
						 IV_MessageStat.o\
						 IV_Common_A.o\
						 CO_ChkLoc.o\
						 CR_ProcOrd.o\
						 DL_ChkDLDel.o\
						 CR_ProcInstrRound.o\
						 IV_MessageEntry.o\
						 MS_FormaterCommon_A.o\
						 MS_FormaterCommon_B.o\
						 RtvInstrFldVal.o\
						 IV_BillGenFn_G.o\
						 MS_FormaterCommon.o\
				$(COMMON_OBJS)

DL_AutoMarkShortage_OFILES  = DL_AutoMarkShortage.o\
			      CR_ProgRestartFn.o\
                              MT_UpdDL_POOLACCDMP.o\
                              CR_ProcInstrRound.o\
                              RtvInstrFldVal.o\
								$(COMMON_OBJS)

DL_EO_ReadyForOblig_OFILES = DL_EO_ReadyForOblig.o\
									  DL_ProcDL.o\
									  DL_ProcDL_E.o\
									  CR_ProcInstrRound.o\
									  CR_ProcOrd.o\
									  RtvInstrFldVal.o\
									  CR_ModMQFn.o\
									  CO_ValidationFn.o\
									  CO_ChkLoc.o\
									  CR_ProgRestartFn.o\
									  CA_CreateDL.o\
									  MT_ProcDL_A.o\
									  CO_ChkPty.o\
									  RtvAccFieldFn.o\
									  DL_ProcDL_A.o\
									  CR_CCSPendDLUpdate.o\
									  DL_ChkDLDel.o\
									  CO_RtvFldValFn.o\
									  IV_Common_A.o\
									  IV_CntlParam.o\
									  IV_MessageEntry.o\
									  MS_FormaterCommon_B.o\
									  MS_FormaterCommon.o\
									  MS_FormaterCommon_A.o\
									  IV_BillGenFn_G.o\
									  CA_Common.o\
									  $(COMMON_OBJS)


CR_DLDtPosRpt_OFILES   = CR_DLDtPosRpt.o\
                      CR_AERpt.o\
                      IV_BillGenFn_G.o\
                      $(COMMON_OBJS)

DL_SetlDtRpt_OFILES =  CR_SetlDtRangeRpt.o\
                        CR_AERpt.o\
                        IV_BillGenFn_G.o\
                        $(COMMON_OBJS)

NBHMonRep_OFILES    = NBHMonRep.o\
                      CR_AERpt.o\
                      IV_BillGenFn_G.o\
                      $(COMMON_OBJS)


EM_ConvAcc_OFILES	=	$(COMMON_OBJS)\
				IV_BillGenFn_G.o\
				EM_ConvAcc.o

EM_ConvSec_OFILES	=	$(COMMON_OBJS)\
				IV_BillGenFn_G.o\
				EM_ConvInstr.o

EM_ConvPendTrans_OFILES =  EM_ConvPendTrans.o\
											IV_BillGenFn_G.o\
											Function_Batch.o\
											$(COMMON_OBJS)

EM_ConvBilling_OFILES = EM_ConvBilling.o\
												IV_BillDelFn_C.o\
												IV_BillGenFn_G.o\
												Function_Batch.o\
												IV_DbPymtFn_B.o\
												IV_LedgerFn.o\
												IV_LedgerFn_A.o\
												IV_BillDelFn_B.o\
												IV_BillDelFn_A.o\
												IV_PymtFn_B.o\
												IV_PymtFn_A.o\
                                                                                                IV_Pymnt_Mnt_A.o\
                                                                                                IV_RoundFn.o\
                                                                                                ChkAudSystemOnline.o\
												CO_ValidationFn.o\
												IV_AccFn.o\
												IV_Common_B.o\
												$(COMMON_OBJS)

Rep_NCH_Hun_OFILES = c_bdbeodnchpos.o\
			$(COMMON_OBJS)

DL_BrkConfRpt_OFILES = DL_BrkConfRpt.o\
			Function_Batch.o\
			$(COMMON_OBJS)

UP_RmtDL_OFILES = UP_RemoteDL.o\
											RtvInstrFldVal.o\
											CO_RtvFldValFn.o\
											MT_ProcDL_A.o\
											CO_ChkPty.o\
											MT_ProcDL_B.o\
											CR_ProcMoveToHis.o\
											MS_CommonRoutines.o\
											DL_ProcDL_B.o\
											DL_ProcDL_C.o\
											DL_ProcDL_D.o\
											DL_ProcDL_E.o\
											DL_ProcDL_F.o\
											RtvAccFieldFn.o\
											DL_ChkDLDel.o\
											DL_ProcDL.o\
											DL_ProcDL_A.o\
											CO_ChkAcc.o\
											CO_ChkCcy.o\
											CO_ChkLoc.o\
											CO_ChkInstr.o\
											MS_MsgCommon.o\
											Proc_RestartLogic.o\
											CO_ProcFileName.o\
											IV_MessageStat.o\
											CR_ProcInstrRound.o\
											Function_Batch.o\
				 							CR_ProcOrd.o\
											CR_ModMQFn.o\
											CR_CCSPendDLUpdate.o\
											MT_ProcMisDL.o\
											MT_DbProcMisDL.o\
											CA_CreateDL.o\
											CA_Common.o\
											$(COMMON_OBJS)\
											$(MESSAGE_OBJS)

CR_DwHfDly_OFILES = RtvDwDump.o\
                          $(COMMON_OBJS)

MS_MsgStatRpt_OFILES = MS_MsgStatRpt.o\
						  $(COMMON_OBJS)


C_AutoSettHU_OFILES = C_AutoSettHU.o\
											RtvInstrFldVal.o\
											CO_RtvFldValFn.o\
											MT_ProcDL_A.o\
											CO_ChkPty.o\
											MT_ProcDL_B.o\
											CR_ProcMoveToHis.o\
											MS_CommonRoutines.o\
											DL_ProcDL_B.o\
											DL_ProcDL_C.o\
											DL_ProcDL_D.o\
											DL_ProcDL_E.o\
											DL_ProcDL_F.o\
											RtvAccFieldFn.o\
											DL_ChkDLDel.o\
											DL_ProcDL.o\
											DL_ProcDL_A.o\
											CO_ChkAcc.o\
											CO_ChkCcy.o\
											CO_ChkLoc.o\
											CO_ChkInstr.o\
											MS_MsgCommon.o\
											Proc_RestartLogic.o\
											CO_ProcFileName.o\
											IV_MessageStat.o\
											CR_ProcInstrRound.o\
             $(COMMON_OBJS)\
             $(MESSAGE_OBJS)\
				 CR_ProcOrd.o\
				 CR_ModMQFn.o\
				 CR_CCSPendDLUpdate.o\
				 CA_Common.o\
				 CA_CreateDL.o

RuReconReport_OFILES = c_posnrecon_ru.o\
								IV_BillGenFn_G.o\
								CR_AERpt.o\
								$(COMMON_OBJS)

UpdDaemonStat_OFILES = ProgStatusUpdateFn.o\
                     $(COMMON_OBJS)
UP_GFCID_OFILES = CR_ProcGFCID.o\
				 $(COMMON_OBJS)

CA_RecEntitl_OFILES = CA_RecEntitl.o\
				 $(COMMON_OBJS)

EOD_Recon_OFILES = CR_ReconPlus.o\
				 $(COMMON_OBJS)

Setl_Info_OFILES = DL_ProcSetlData.o\
		 $(COMMON_OBJS)

Rtv_UniqRefno_OFILES = RtvUniqueRefno.o\
		 $(COMMON_OBJS)

I_INCCOMMRPT_OFILES = I_IncCommRpt.o\
		 CO_ProcFileName.o\
		 BT_Common.o\
     CR_ProgRestartFn.o\
		 $(COMMON_OBJS)

dl_exchobligation_rpt_OFILES = dl_exchobligation_rpt.o\
										 CO_ProcFileName.o\
										 CR_ProgRestartFn.o\
										 $(COMMON_OBJS)


DL_ExchOblig_rec_OFILES = DL_ExchOblig_rec.o\
								  CO_ProcFileName.o\
								  CR_ProgRestartFn.o\
								  $(COMMON_OBJS)


OBLIGATIONDUMP_OFILES = OBLIGATIONDUMP.o\
								CO_ProcFileName.o\
								CR_ProgRestartFn.o\
								$(COMMON_OBJS)


DL_PassAE_OFILES = DL_PassAE.o\
						 DL_ProcDL_A.o\
						 DL_ProcDL_D.o\
						 DL_ProcDL_F.o\
						 CR_ModMQFn.o\
						 DL_ProcDL.o\
						 MT_ProcDL_A.o\
						 CO_ChkPty.o\
						 RtvAccFieldFn.o\
						 CO_RtvFldValFn.o\
						 IV_CntlParam.o\
                                                 CO_ValidationFn.o\
						 CR_CCSPendDLUpdate.o\
						 IV_MessageStat.o\
						 IV_Common_A.o\
						 CO_ChkLoc.o\
						 CR_ProcOrd.o\
						 DL_ChkDLDel.o\
						 CR_ProcInstrRound.o\
						 IV_MessageEntry.o\
						 MS_FormaterCommon_A.o\
						 MS_FormaterCommon_B.o\
						 RtvInstrFldVal.o\
						 IV_BillGenFn_G.o\
						 MS_FormaterCommon.o\
                                                 IV_IVAccEnt.o\
										 CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

DL_GenDPInst_OFILES = DL_GenDPInstrn.o\
							 DL_ProcDL.o\
							 CR_ProcOrd.o\
							 CR_ProcInstrRound.o\
							 CO_ChkCcy.o\
							 CR_ModMQFn.o\
							 CO_ChkInstr.o\
							 CO_ChkAcc.o\
							 CO_ChkLoc.o\
							 RtvInstrFldVal.o\
										 CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

DL_PassDPInst_OFILES = DL_PassDPInstrn.o\
							 DL_ProcDL.o\
							 CR_ProcOrd.o\
							 CR_ProcInstrRound.o\
							 CO_ChkCcy.o\
							 CR_ModMQFn.o\
							 CO_ChkInstr.o\
							 CO_ChkAcc.o\
							 CO_ChkLoc.o\
							 CO_CreateReport.o\
							 RtvInstrFldVal.o\
							 CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

Msg548_OFILES	=	Msg548.o\
						CR_ProgRestartFn.o\
							$(MESSAGE_OBJS)\
										 $(COMMON_OBJS)

MFRegReport_OFILES	=	MF_ClntInstruction.o\
								CO_ProcFileName.o\
								CR_ProgRestartFn.o\
								CreateExcel.o\
										 $(COMMON_OBJS)

PROCGENS	=	CM_GetSystemDate.c\
				CM_CntryCondChk.c\
				aduef_s.c\
				A_BEntlGen.c

FundObligRep_OFILES	=	FundOblig.o\
						CO_ProcFileName.o\
						CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

FundObligScrip_OFILES	=	FundObligScrip.o\
						CO_ProcFileName.o\
						CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

CA_PassAccEnt_OFILES	=	CA_PassAccEnt.o\
						CR_ProgRestartFn.o\
										 $(COMMON_OBJS)

GenerateConfFile_OFILES      =  dl_cnffilegen.o\
										  CR_ProgRestartFn.o\
										  CO_ProcFileName.o\
										$(COMMON_OBJS)

SplitFiles_OFILES      =  SplitFiles.o\
								  CR_ProgRestartFn.o\
								$(COMMON_OBJS)




CA_ProcConv_OFILES = CA_ProcConv.o\
							CA_Common.o\
							CA_CreateDL.o\
							DL_ProcDL.o\
							DL_ProcDL_A.o\
							DL_ProcDL_E.o\
							DL_ProcDL_F.o\
							MT_ProcDL_A.o\
							CO_ChkPty.o\
							CO_ChkAcc.o\
							CO_ChkInstr.o\
							CO_ChkLoc.o\
							CO_ChkCcy.o\
							RtvAccFieldFn.o\
							RtvInstrFldVal.o\
							CO_RtvFldValFn.o\
							DL_ChkDLDel.o\
							CR_ProcInstrRound.o\
							$(COMMON_OBJS)\
							$(MESSAGE_OBJS)\
							CR_ProcOrd.o\
							CR_ModMQFn.o\
							CR_ProgRestartFn.o\
							CR_CCSPendDLUpdate.o

CA_FloatRate_OFILES      =  CA_FloatRate.o\
								  CO_DateFuns.o\
								  CR_ProgRestartFn.o\
								$(COMMON_OBJS)

DL_MarkShortAut_OFILES  = DL_MarkShortAut.o\
								  DL_ProcDefDeal.o\
								  FPI_Repair_DL_Deal.o\
								  DL_InsDbRepairDeal.o\
								  DL_ProcDL.o\
								  DL_ProcDL_A.o\
								  DL_ProcDL_B.o\
								  DL_ProcDL_E.o\
								  MT_ProcDL_A.o\
								  CO_ChkPty.o\
								  CO_ChkAcc.o\
								  CO_ChkInstr.o\
								  CO_ChkLoc.o\
								  CO_ChkCcy.o\
								  RtvAccFieldFn.o\
								  RtvInstrFldVal.o\
								  CO_RtvFldValFn.o\
								  DL_ChkDLDel.o\
								  CR_ProcInstrRound.o\
								  CR_ProcOrd.o\
								  CR_ModMQFn.o\
								  CR_CCSPendDLUpdate.o\
								  CR_ProgRestartFn.o\
								  MT_UpdDL_MARKSHORTAGE.o\
								  $(MESSAGE_OBJS)\
								  $(COMMON_OBJS)

DynamicReport_OFILES  = DynamicReport.o\
								IntlReportsNew.o\
								CR_ProgRestartFn.o\
								$(COMMON_OBJS)

IV_PrntSummary_OFILES = IV_PrntSumBill.o\
                        IV_Add_Bill_Prnt_Det.o\
		        IV_PrntSumBillFn.o\
			IV_PrntSumAcc_Web.o\
			IV_PrntSumBill_Web.o\
			IV_PrntSumFtr_web.o\
			IV_PrntSumCovPg_Web.o\
			IV_ServChargeFn.o\
			IV_TransacFn.o\
			IV_ServBasisFn.o\
			IV_AccParamFn.o\
			IV_AccSetup.o\
			IV_ServicesFn.o\
			IV_SServBasisFn.o\
			IV_ParamTypeFn.o\
			IV_ExgRtFn.o\
			IV_RoundFn.o\
			RtvCcyFldVal.o\
			CO_ProcFileName.o\
			CR_AERpt.o\
			CR_ProgRestartFn.o\
			$(COMMON_OBJS)\
			$(MESSAGE_OBJS)

IV_PrntDetail_OFILES = IV_PrntDetail.o\
		        IV_PrntDetBillFn.o\
                        IV_Add_Bill_Prnt_Det.o\
			IV_PrntDetAcc_Web.o\
			IV_PrntDetBill_Web.o\
			IV_PrntDetCovPg_Web.o\
			IV_PrntDetAnnexures.o\
			IV_ServChargeFn.o\
			IV_TransacFn.o\
			IV_ServBasisFn.o\
			IV_AccParamFn.o\
			IV_AccSetup.o\
			IV_ServicesFn.o\
			IV_SServBasisFn.o\
			IV_ParamTypeFn.o\
			IV_ExgRtFn.o\
			IV_RoundFn.o\
			RtvCcyFldVal.o\
			CO_ProcFileName.o\
			CR_AERpt.o\
                        IV_PrntCustDetBill_Web.o\
			$(COMMON_OBJS)\
			$(MESSAGE_OBJS)

IV_PrntTransDetail_OFILES = IV_PrntTransDetail.o\
		        IV_PrntTransDetBillFn.o\
			IV_PrntTransDetAcc_Web.o\
			IV_PrntTransDetBill_Web.o\
			IV_PrntTransDetCovPg_Web.o\
			IV_ServChargeFn.o\
			IV_TransacFn.o\
			IV_ServBasisFn.o\
			IV_AccParamFn.o\
			IV_AccSetup.o\
			IV_ServicesFn.o\
			IV_SServBasisFn.o\
			IV_ParamTypeFn.o\
			IV_ExgRtFn.o\
			IV_RoundFn.o\
			RtvCcyFldVal.o\
			CO_ProcFileName.o\
			CR_AERpt.o\
			$(COMMON_OBJS)\
			$(MESSAGE_OBJS)



IV_PrntCustDetail_OFILES = IV_PrntCustDetail.o\
                        IV_PrntCustDetBill_Web.o\
		        IV_PrntCustDetBillFn.o\
			IV_PrntCustDetAcc_Web.o\
			IV_PrntCustDetCovPg_Web.o\
			IV_ServChargeFn.o\
			IV_TransacFn.o\
			IV_ServBasisFn.o\
			IV_AccParamFn.o\
			IV_AccSetup.o\
			IV_ServicesFn.o\
			IV_SServBasisFn.o\
			IV_ParamTypeFn.o\
			IV_ExgRtFn.o\
			IV_RoundFn.o\
			RtvCcyFldVal.o\
			CO_ProcFileName.o\
			CR_AERpt.o\
			$(COMMON_OBJS)\
			$(MESSAGE_OBJS)



IV_ProvBill_OFILES  = IV_ProvBill.o\
							 IV_ProvBillGenFn.o\
							 IV_ProvBillPrntFn.o\
							 IV_ProvCalcBillFn.o\
							 IV_ProvBillAcc_Web.o\
							 IV_ProvCovPg_Web.o\
							 IV_ProvBill_Web.o\
							 IV_ProvFtr_Web.o\
							IV_BillGenFn_B.o\
							IV_BillGenFn_C.o\
							IV_BillGenFn_D.o\
							IV_BillGenFn_E.o\
							IV_BillGenFn_F.o\
							IV_PreBillProc.o\
							IV_CRCommon.o\
							IV_ServChargeFn.o\
							IV_TransacFn.o\
							IV_ServBasisFn.o\
							IV_AccParamFn.o\
							IV_AccSetup.o\
							IV_ServicesFn.o\
							IV_SServBasisFn.o\
							IV_ParamTypeFn.o\
							IV_ExgRtFn.o\
							IV_RoundFn.o\
							$(COMMON_OBJS)\
							RtvCcyFldVal.o\
									 IV_OtherServ_B.o\
									 IV_PRO_SGENSTATFn.o\
									 IV_PrntSctHdr_Web.o\
									 IV_PrntHdr_Web.o\
									 IV_PrntCust_Web.o\
									 IV_PrntDL_Web.o\
									 IV_PrntCash_Web.o\
									 IV_PrntCA_Web.o\
									 IV_PrntOth_Web.o\
									 CO_PrntLine.o\
									 IV_PrntDepo_Web.o\
									 $(MESSAGE_OBJS)\
									 CO_ProcFileName.o\
									 CR_AERpt.o


IV_PayAEPass_OFILES     =       IV_PayAEPass.o\
                                CR_ProgRestartFn.o\
                                IV_Common.o\
                                 $(COMMON_OBJS)

IV_PassAE_OFILES        =       IV_BillAEPass.o\
                                IV_CntlParam.o\
                                IV_Common.o\
                                CR_ProgRestartFn.o\
                                 $(COMMON_OBJS)

IV_Pymnt_Auth_OFILES   =        IV_Pymnt_Mnt.o\
				IV_Pymnt_Mnt_A.o\
				IV_ProcPymt_B.o\
				IV_LedgerFn_A.o\
				IV_LedgerFn.o\
				IV_DbPymtFn_B.o\
				IV_AccSetup.o\
				IV_BillGenFn_G.o\
				IV_BillDelFn_B.o\
				IV_PymtFn_A.o\
				IV_PymtFn_B.o\
				IV_BillDelFn_A.o\
				IV_PymtDetFn_A.o\
				IV_PymtDetFn.o\
				IV_AccFn.o\
				IV_AccFn_A.o\
				IV_Common_B.o\
				CO_ChkAcc.o\
				IV_Base.o\
				CR_ProgRestartFn.o\
				IV_RoundFn.o\
				ChkAudSystemOnline.o\
				$(COMMON_OBJS)


MT_IntUpdt_OFILES = EOD_MTInstrIntDates.o\
			CA_Common.o\
			CO_ChkInstr.o\
		  CR_ProgRestartFn.o\
                   $(COMMON_OBJS)

MS_MSG_RESEND_OFILES  = MS_MSG_RESEND.o\
                CR_ProgRestartFn.o\
                ChkAudSystemOnline.o\
                $(COMMON_OBJS)

SAMPLE_CUR_OFILES = sample_cur.o

all:		objects ${PROGRAMS}
objects:	${EntlGen_OFILES}
fresh:		clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
       #$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=kbaix_dev/kbaix_dev DYNAMIC=ANSI SQLCHECK=SEMANTICS $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=kbaix_dev/kbaix_dev DYNAMIC=ANSI SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI  $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=kbaix_dev/kbaix_dev DYNAMIC=ANSI SQLCHECK=SEMANTICS  $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

CtxManagenment.o:CM_CtxMgmt.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=kbaix_dev/kbaix_dev@CUSTMENT SQLCHECK=SEMANTICS $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX  $(INTL_PROC_OPTION) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${PROCGENS} ${CR_DWTran_OFILES} ${PROGRAMS}

clobber:	clean
	rm -f a.out core ERRS make.out *~

CA_IntimateEvt:	${CA_IntimateEvt_OFILES}
	$(CC) ${LDFLAGS} ${CA_IntimateEvt_OFILES} ${NON_DCE_LIBS} -o $@

Conv_Safek:	${Conv_Safek_OFILES}
	$(CC) ${LDFLAGS} ${Conv_Safek_OFILES} ${NON_DCE_LIBS} -o $@

Conv_Trade:	${Conv_Trade_OFILES}
	$(CC) ${LDFLAGS} ${Conv_Trade_OFILES} ${NON_DCE_LIBS} -o $@

Conv_Excptn:	${Conv_Excptn_OFILES}
	$(CC) ${LDFLAGS} ${Conv_Excptn_OFILES} ${NON_DCE_LIBS} -o $@

Conv_Dec_Len:	${Conv_Dec_Len_OFILES}
	$(CC) ${LDFLAGS} ${Conv_Dec_Len_OFILES} ${NON_DCE_LIBS} -o $@

DL_SLBREV 	:	${DL_SLBREV_OFILES}
	$(CC) ${LDFLAGS} ${DL_SLBREV_OFILES} ${NON_DCE_LIBS} -o $@

CA_GenEvt_A		:	${CA_GenEvt_A_OFILES}
	$(CC) ${LDFLAGS} ${CA_GenEvt_A_OFILES} ${NON_DCE_LIBS} -o $@

CA_GenEvt_B		:	${CA_GenEvt_B_OFILES}
	$(CC) ${LDFLAGS} ${CA_GenEvt_B_OFILES} ${NON_DCE_LIBS} -o $@

CA_GenEntitl		:	${CA_GenEntitl_OFILES}
	$(CC) ${LDFLAGS} ${CA_GenEntitl_OFILES} ${NON_DCE_LIBS} -o $@

EPI_AccountEntries            :       ${EPI_AccountEntries_OFILES}
	$(CC) ${LDFLAGS} ${EPI_AccountEntries_OFILES} ${NON_DCE_LIBS} -o $@

EI_InitSMI		:	${EI_InitSMI_OFILES}
	$(CC) ${LDFLAGS} ${EI_InitSMI_OFILES} ${NON_DCE_LIBS} -o $@

EI_InitCCS		:	${EI_InitCCS_OFILES}
	$(CC) ${LDFLAGS} ${EI_InitCCS_OFILES} ${NON_DCE_LIBS} -o $@

CA_CustInstr 	:	${CA_CustInstr_OFILES}
	$(CC) ${LDFLAGS} ${CA_CustInstr_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillPrnt		:	${IV_BillPrnt_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillPrnt_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillPrnt_EMINV		:	${IV_BillPrnt_EMINV_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillPrnt_EMINV_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillPrnt_HTML     : ${IV_BillPrnt_HTML_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillPrnt_HTML_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillPrnt_DETINV		:	${IV_BillPrnt_DETINV_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillPrnt_DETINV_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillPrnt_DETHTML     : ${IV_BillPrnt_DETHTML_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillPrnt_DETHTML_OFILES} ${NON_DCE_LIBS} -o $@

MS_SCH :	${I_MSGSCH_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGSCH_OFILES} ${NON_DCE_LIBS} -o $@
	cp -f MS_SCH MS_SCHHoldg
	cp -f MS_SCH MS_SCHPendg
	cp -f MS_SCH MS_SCHTrans

DL_Setl_Rpt: ${DL_Setl_Rpt_OFILES}
	$(CC) ${LDFLAGS} ${DL_Setl_Rpt_OFILES} ${NON_DCE_LIBS} -o $@

NIS_BID_Auth: ${NIS_BID_Auth_OFILES}
	$(CC) ${LDFLAGS} ${NIS_BID_Auth_OFILES} ${NON_DCE_LIBS} -o $@

NIS_APPLN_Auth: ${NIS_APPLN_Auth_OFILES}
	$(CC) ${LDFLAGS} ${NIS_APPLN_Auth_OFILES} ${NON_DCE_LIBS} -o $@

Proc_Eod: ${Proc_Eod_OFILES}
	$(CC) ${LDFLAGS} ${Proc_Eod_OFILES} ${NON_DCE_LIBS} -o $@

AUTOJOB_MON: ${autojob_mon_OFILES}
	$(CC) ${LDFLAGS} ${autojob_mon_OFILES} ${NON_DCE_LIBS} -o $@

MS_Arch :	${MS_Arch_OFILES}
	$(CC) ${LDFLAGS} ${MS_Arch_OFILES} ${NON_DCE_LIBS} -o $@

MS_Transmitter :	${I_MSGTRAN_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGTRAN_OFILES} ${NON_DCE_LIBS} -o $@
MS_TransmitterB :	${I_MSGTRANB_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGTRAN_OFILES} ${NON_DCE_LIBS} -o $@
MS_EmailTransmitter :	${I_EMAILTRAN_OFILES}
	$(CC) ${LDFLAGS} ${I_EMAILTRAN_OFILES} ${NON_DCE_LIBS} -o $@
MS_MAnMsgRpt :	${I_MANMSGREP_OFILES}
	$(CC) ${LDFLAGS} ${I_MANMSGREP_OFILES} ${NON_DCE_LIBS} -o $@
MS_MessageMover :	${I_MOVEMSG_OFILES}
	$(CC) ${LDFLAGS} ${I_MOVEMSG_OFILES} ${NON_DCE_LIBS} -o $@

MS_MsInterface :	${I_MSGENT_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGENT_OFILES} ${NON_DCE_LIBS} -o $@

DLUNMAPPED548 :	${DLUNMAPPED548_OFILES}
	$(CC) ${LDFLAGS} ${DLUNMAPPED548_OFILES} ${NON_DCE_LIBS} -o $@

MS_MSG_RESEND: $(MS_MSG_RESEND_OFILES)
	$(CC) ${LDFLAGS} ${MS_MSG_RESEND_OFILES} ${NON_DCE_LIBS} -o $@

IV_AEGenerate		:	${IV_AEGenerate_OFILES}
	$(CC) ${LDFLAGS} ${IV_AEGenerate_OFILES} ${NON_DCE_LIBS} -o $@

IV_GPSSGenerate		:	${IV_GPSSGenerate_OFILES}
	$(CC) ${LDFLAGS} ${IV_GPSSGenerate_OFILES} ${NON_DCE_LIBS} -o $@

IV_PayAEGenerate		:	${IV_PayAEGenerate_OFILES}
	$(CC) ${LDFLAGS} ${IV_PayAEGenerate_OFILES} ${NON_DCE_LIBS} -o $@

IV_Arch :	${IV_Arch_OFILES}
	$(CC) ${LDFLAGS} ${IV_Arch_OFILES} ${NON_DCE_LIBS} -o $@

RBIRept :   ${RBIRept_OFILES}
	   $(CC) ${LDFLAGS} ${RBIRept_OFILES} ${NON_DCE_LIBS} -o $@

EOD_Handover :	${EOD_Handover_OFILES}
	$(CC) ${LDFLAGS} ${EOD_Handover_OFILES} ${NON_DCE_LIBS} -o $@
DL_SOH_Rec :   ${DL_SOH_Rec_OFILES}
	   $(CC) ${LDFLAGS} ${DL_SOH_Rec_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillDeliver		:	${IV_BillDeliver_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillDeliver_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillResend		:	${IV_BillResend_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillResend_OFILES} ${NON_DCE_LIBS} -o $@

CA_ProcPymt	:	${CA_ProcPymt_OFILES}
	$(CC) ${LDFLAGS} ${CA_ProcPymt_OFILES} ${NON_DCE_LIBS} -o $@

CA_SplitPymt:	${CA_SplitPymt_OFILES}
	$(CC) ${LDFLAGS} ${CA_SplitPymt_OFILES} ${NON_DCE_LIBS} -o $@

PROC_EOD:	${PROC_EOD_OFILES}
	$(CC) ${LDFLAGS} ${PROC_EOD_OFILES} ${NON_DCE_LIBS} -o $@

PROC_BOD:	${PROC_BOD_OFILES}
	$(CC) ${LDFLAGS} ${PROC_BOD_OFILES} ${NON_DCE_LIBS} -o $@

PROC_EOM:	${PROC_EOM_OFILES}
	$(CC) ${LDFLAGS} ${PROC_EOM_OFILES} ${NON_DCE_LIBS} -o $@

PROC_EOY:	${PROC_EOY_OFILES}
	$(CC) ${LDFLAGS} ${PROC_EOY_OFILES} ${NON_DCE_LIBS} -o $@

CM_ConvScheduler:	${CM_ConvScheduler_OFILES}
	$(CC) ${LDFLAGS} ${CM_ConvScheduler_OFILES} ${NON_DCE_LIBS} -o $@

CM_BatchDaemon: ${CM_BatchDaemon_OFILES}
	$(CC) ${LDFLAGS} ${CM_BatchDaemon_OFILES} ${NON_DCE_LIBS} -o $@

IV_BillGenerate:	${IV_BillGenerate_OFILES}
	$(CC) ${LDFLAGS} ${IV_BillGenerate_OFILES} ${NON_DCE_LIBS} -o $@

CA_AEGenetae:	${CA_AEGenetae_OFILES}
	$(CC) ${LDFLAGS} ${CA_AEGenetae_OFILES} ${NON_DCE_LIBS} -o $@

IV_PassHoff:	${IV_PassHoff_OFILES}
	$(CC) ${LDFLAGS} ${IV_PassHoff_OFILES} ${NON_DCE_LIBS} -o $@

Del_BaseNo:	${Del_BaseNo_OFILES}
	$(CC) ${LDFLAGS} ${Del_BaseNo_OFILES} ${NON_DCE_LIBS} -o $@

CA_GenerateAlert:	${CA_GenerateAlert_OFILES}
	$(CC) ${LDFLAGS} ${CA_GenerateAlert_OFILES} ${NON_DCE_LIBS} -o $@

CA_Arch:	${CA_Arch_OFILES}
	$(CC) ${LDFLAGS} ${CA_Arch_OFILES} ${NON_DCE_LIBS} -o $@

CA_PymtGlobal:	${CA_PymtGlobal_OFILES}
	$(CC) ${LDFLAGS} ${CA_PymtGlobal_OFILES} ${NON_DCE_LIBS} -o $@

CA_BODCastMsg:	${CA_BODCastMsg_OFILES}
	$(CC) ${LDFLAGS} ${CA_BODCastMsg_OFILES} ${NON_DCE_LIBS} -o $@

CA_RedomEvt:	${CA_RedomEvt_OFILES}
	$(CC) ${LDFLAGS} ${CA_RedomEvt_OFILES} ${NON_DCE_LIBS} -o $@

CA_ENRARpt:	${CA_ENRARpt_OFILES}
	$(CC) ${LDFLAGS} ${CA_ENRARpt_OFILES} ${NON_DCE_LIBS} -o $@

EOD_CHECK:	${EOD_CHECK_OFILES}
	$(CC) ${LDFLAGS} ${EOD_CHECK_OFILES} ${NON_DCE_LIBS} -o $@

GR_PASS:  ${GR_PASS_OFILES}
	$(CC)  ${LDFLAGS} ${GR_PASS_OFILES} ${NON_DCE_LIBS} -o $@

MS_IncomingMsRpt:	$(MS_IncomingMsRpt_OFILES)
	$(CC) ${LDFLAGS} ${MS_IncomingMsRpt_OFILES} ${NON_DCE_LIBS} -o $@

MS_CCSFailRpt: $(MS_CCSFailRpt_OFILES)
	$(CC) $(LDFLAGS) $(MS_CCSFailRpt_OFILES) $(NON_DCE_LIBS) -o $@

RegRept: $(RegRept_OFILES)
	$(CC) $(LDFLAGS) $(RegRept_OFILES) $(NON_DCE_LIBS) -o $@

DL_FundObligGen: $(DL_FundObligGen_OFILES)
	$(CC) $(LDFLAGS) $(DL_FundObligGen_OFILES) $(NON_DCE_LIBS) -o $@

FundObligRep: $(FundObligRep_OFILES)
	$(CC) $(LDFLAGS) $(FundObligRep_OFILES) $(NON_DCE_LIBS) -o $@

FundObligScrip: $(FundObligScrip_OFILES)
	$(CC) $(LDFLAGS) $(FundObligScrip_OFILES) $(NON_DCE_LIBS) -o $@

CA_PassAccEnt: $(CA_PassAccEnt_OFILES)
	$(CC) $(LDFLAGS) $(CA_PassAccEnt_OFILES) $(NON_DCE_LIBS) -o $@

GenReport: $(GenReport_OFILES)
	$(CC) $(LDFLAGS) $(GenReport_OFILES) $(NON_DCE_LIBS) -o $@

DL_GenAE: $(DL_GenAE_OFILES)
	$(CC) $(LDFLAGS) $(DL_GenAE_OFILES) $(NON_DCE_LIBS) -o $@

DL_AutoMarkShortage: $(DL_AutoMarkShortage_OFILES)
	$(CC) $(LDFLAGS) $(DL_AutoMarkShortage_OFILES) $(NON_DCE_LIBS) -o $@

DL_EO_ReadyForOblig:$(DL_EO_ReadyForOblig_OFILES)
	$(CC) $(LDFLAGS) $(DL_EO_ReadyForOblig_OFILES) $(NON_DCE_LIBS) -o $@

ExchgOrderMatch: $(ExchgOrderMatch_OFILES)
	$(CC) $(LDFLAGS) $(ExchgOrderMatch_OFILES) $(NON_DCE_LIBS) -o $@

DL_BCN_MAP: $(DL_BCN_MAP_OFILES)
	$(CC) $(LDFLAGS) $(DL_BCN_MAP_OFILES) $(NON_DCE_LIBS) -o $@

EarlyPyinRpt: $(EarlyPyinRpt_OFILES)
	$(CC) $(LDFLAGS) $(EarlyPyinRpt_OFILES) $(NON_DCE_LIBS) -o $@

DL_MAP_RESET: $(DL_MAP_RESET_OFILES)
	$(CC) $(LDFLAGS) $(DL_MAP_RESET_OFILES) $(NON_DCE_LIBS) -o $@

DL_SETL_BLK_REL: $(DL_SETL_BLK_REL_OFILES)
	$(CC) $(LDFLAGS) $(DL_SETL_BLK_REL_OFILES) $(NON_DCE_LIBS) -o $@

DL_Mark_Recon: $(DL_Mark_Recon_OFILES)
	$(CC) $(LDFLAGS) $(DL_Mark_Recon_OFILES) $(NON_DCE_LIBS) -o $@

CR_DLDtPosRpt: $(CR_DLDtPosRpt_OFILES)
	$(CC) ${LDFLAGS} ${CR_DLDtPosRpt_OFILES} ${NON_DCE_LIBS} -o $@

DL_SetlDtRpt: $(DL_SetlDtRpt_OFILES)
	$(CC) ${LDFLAGS} $(DL_SetlDtRpt_OFILES) ${NON_DCE_LIBS} -o $@

NBHMonRep: $(NBHMonRep_OFILES)
	$(CC) ${LDFLAGS} ${NBHMonRep_OFILES} ${NON_DCE_LIBS} -o $@

EM_ConvAcc:	$(EM_ConvAcc_OFILES)
	$(CC) ${LDFLAGS} ${EM_ConvAcc_OFILES} ${NON_DCE_LIBS} -o $@

EM_ConvSec:	$(EM_ConvSec_OFILES)
	$(CC) ${LDFLAGS} ${EM_ConvSec_OFILES} ${NON_DCE_LIBS} -o $@

EM_ConvPendTrans     :  ${EM_ConvPendTrans_OFILES}
	$(CC) ${LDFLAGS} ${EM_ConvPendTrans_OFILES} ${NON_DCE_LIBS} -o $@

EM_ConvBilling    :  ${EM_ConvBilling_OFILES}
	$(CC) ${LDFLAGS} ${EM_ConvBilling_OFILES} ${NON_DCE_LIBS} -o $@

Rep_NCH_Hun     :  ${Rep_NCH_Hun_OFILES}
	$(CC) ${LDFLAGS} ${Rep_NCH_Hun_OFILES} ${NON_DCE_LIBS} -o $@

DL_BrkConfRpt     :  ${DL_BrkConfRpt_OFILES}
	$(CC) ${LDFLAGS} ${DL_BrkConfRpt_OFILES} ${NON_DCE_LIBS} -o $@

UP_RmtDL     :  ${UP_RmtDL_OFILES}
	$(CC) ${LDFLAGS} ${UP_RmtDL_OFILES} ${NON_DCE_LIBS} -o $@

CR_DwHfDly    :  ${CR_DwHfDly_OFILES}
	$(CC) ${LDFLAGS} ${CR_DwHfDly_OFILES} ${NON_DCE_LIBS} -o $@

MS_MsgStatRpt: ${MS_MsgStatRpt_OFILES}
	$(CC) ${LDFLAGS} ${MS_MsgStatRpt_OFILES} ${NON_DCE_LIBS} -o $@

CR_DWTran: ${CR_DWTran_OFILES}
	$(CC) ${LDFLAGS} ${CR_DWTran_OFILES} ${MQ_LIBS} -o $@

C_AutoSettHU: $(C_AutoSettHU_OFILES)
	$(CC) ${LDFLAGS} ${C_AutoSettHU_OFILES} ${NON_DCE_LIBS} -o $@

RuReconReport: $(RuReconReport_OFILES)
	$(CC) ${LDFLAGS} ${RuReconReport_OFILES} ${NON_DCE_LIBS} -o $@

UpdDaemonStat: ${UpdDaemonStat_OFILES}
	$(CC) ${LDFLAGS} ${UpdDaemonStat_OFILES} ${NON_DCE_LIBS} -o $@
UP_GFCID:  ${UP_GFCID_OFILES}
	$(CC) ${LDFLAGS} ${UP_GFCID_OFILES} ${NON_DCE_LIBS} -o $@
CA_RecEntitl:  ${CA_RecEntitl_OFILES}
	$(CC) ${LDFLAGS} ${CA_RecEntitl_OFILES} ${NON_DCE_LIBS} -o $@
EOD_Recon:  ${EOD_Recon_OFILES}
	$(CC) ${LDFLAGS} ${EOD_Recon_OFILES} ${NON_DCE_LIBS} -o $@
Setl_Info:  ${Setl_Info_OFILES}
	$(CC) ${LDFLAGS} ${Setl_Info_OFILES} ${NON_DCE_LIBS} -o $@
Rtv_UniqRefno:  ${Rtv_UniqRefno_OFILES}
	$(CC) ${LDFLAGS} ${Rtv_UniqRefno_OFILES} ${NON_DCE_LIBS} -o $@
I_INCCOMMRPT:  ${I_INCCOMMRPT_OFILES}
	$(CC) ${LDFLAGS} ${I_INCCOMMRPT_OFILES} ${NON_DCE_LIBS} -o $@
dl_exchobligation_rpt: $(dl_exchobligation_rpt_OFILES)
	$(CC) $(LDFLAGS) $(dl_exchobligation_rpt_OFILES) $(NON_DCE_LIBS) -o $@
DL_ExchOblig_rec: $(DL_ExchOblig_rec_OFILES)
	$(CC) $(LDFLAGS) $(DL_ExchOblig_rec_OFILES) $(NON_DCE_LIBS) -o $@

OBLIGATIONDUMP: $(OBLIGATIONDUMP_OFILES)
	$(CC) $(LDFLAGS) $(OBLIGATIONDUMP_OFILES) $(NON_DCE_LIBS) -o $@

DL_PassAE: $(DL_PassAE_OFILES)
	$(CC) $(LDFLAGS) $(DL_PassAE_OFILES) $(NON_DCE_LIBS) -o $@

DL_GenDPInst: $(DL_GenDPInst_OFILES)
	$(CC) $(LDFLAGS) $(DL_GenDPInst_OFILES) $(NON_DCE_LIBS) -o $@

DL_PassDPInst: $(DL_PassDPInst_OFILES)
	$(CC) $(LDFLAGS) $(DL_PassDPInst_OFILES) $(NON_DCE_LIBS) -o $@

GenerateConfFile: $(GenerateConfFile_OFILES)
	   $(CC) $(LDFLAGS) $(GenerateConfFile_OFILES) $(NON_DCE_LIBS) -o $@

SplitFiles: $(SplitFiles_OFILES)
	   $(CC) $(LDFLAGS) $(SplitFiles_OFILES) $(NON_DCE_LIBS) -o $@

CA_ProcConv: $(CA_ProcConv_OFILES)
	   $(CC) $(LDFLAGS) $(CA_ProcConv_OFILES) $(NON_DCE_LIBS) -o $@

Msg548: $(Msg548_OFILES)
	   $(CC) $(LDFLAGS) $(Msg548_OFILES) $(NON_DCE_LIBS) -o $@

MFRegReport: $(MFRegReport_OFILES)
	   $(CC) $(LDFLAGS) $(MFRegReport_OFILES) $(NON_DCE_LIBS) -o $@

DL_MarkShortAut: $(DL_MarkShortAut_OFILES)
		$(CC) $(LDFLAGS) $(DL_MarkShortAut_OFILES) $(NON_DCE_LIBS) -o $@

GTUpload: $(GTUpload_OFILES)
		$(CC) $(LDFLAGS) $(GTUpload_OFILES) $(NON_DCE_LIBS) -o $@

Daemon_Armor :   ${Daemon_Armor_OFILES}
	   $(CC) ${LDFLAGS} ${Daemon_Armor_OFILES} ${NON_DCE_LIBS} -o $@


CA_FloatRate: $(CA_FloatRate_OFILES)
	   $(CC) $(LDFLAGS) $(CA_FloatRate_OFILES) $(NON_DCE_LIBS) -o $@

DynamicReport: 	$(DynamicReport_OFILES)
	$(CC) $(LDFLAGS) $(DynamicReport_OFILES) $(NON_DCE_LIBS) -o $@

IV_PrntSummary: $(IV_PrntSummary_OFILES)
	$(CC) $(LDFLAGS) $(IV_PrntSummary_OFILES) $(NON_DCE_LIBS) -o $@

IV_PrntDetail: $(IV_PrntDetail_OFILES)
	$(CC) $(LDFLAGS) $(IV_PrntDetail_OFILES) $(NON_DCE_LIBS) -o $@

IV_PrntTransDetail: $(IV_PrntTransDetail_OFILES)
	$(CC) $(LDFLAGS) $(IV_PrntTransDetail_OFILES) $(NON_DCE_LIBS) -o $@

IV_PrntCustDetail: $(IV_PrntCustDetail_OFILES)
	$(CC) $(LDFLAGS) $(IV_PrntCustDetail_OFILES) $(NON_DCE_LIBS) -o $@

IV_ProvBill: 	$(IV_ProvBill_OFILES)
	$(CC) $(LDFLAGS) $(IV_ProvBill_OFILES) $(NON_DCE_LIBS) -o $@

INT_AUTOSYS:    $(INT_AUTOSYS_OFILES)
		 $(CC) $(LDFLAGS) $(INT_AUTOSYS_OFILES) $(NON_DCE_LIBS) -o $@

IV_PayAEPass:	${IV_PayAEPass_OFILES}
	$(CC) ${LDFLAGS} ${IV_PayAEPass_OFILES} ${NON_DCE_LIBS} -o $@

IV_PassAE:	${IV_PassAE_OFILES}
	$(CC) ${LDFLAGS} ${IV_PassAE_OFILES} ${NON_DCE_LIBS} -o $@
	
	
BODAlerts:	${BODAlerts_OFILES}
	$(CC) ${LDFLAGS} ${BODAlerts_OFILES} ${NON_DCE_LIBS} -o $@

IV_Pymnt_Auth:	${IV_Pymnt_Auth_OFILES}
	$(CC) ${LDFLAGS} ${IV_Pymnt_Auth_OFILES} ${NON_DCE_LIBS} -o $@

SAMPLE_CUR : $(SAMPLE_CUR_OFILES)
	$(CC) ${LDFLAGS} ${SAMPLE_CUR_OFILES} ${NON_DCE_LIBS} -o $@

MT_IntUpdt: $(MT_IntUpdt_OFILES)
		$(CC) $(LDFLAGS) $(MT_IntUpdt_OFILES) $(NON_DCE_LIBS) -o $@

#Batch Server & Common

$(PROC_EOD_OFILES) : Prog_Common.h Intellect_Common.h Intellect_Interface.h
$(PROC_EOM_OFILES) : Prog_Common.h Intellect_Common.h Intellect_Interface.h
$(PROC_EOY_OFILES) : Prog_Common.h Intellect_Common.h Intellect_Interface.h
$(PROC_BOD_OFILES) : Prog_Common.h Intellect_Common.h Intellect_Interface.h
$(CM_ConvScheduler_OFILES): Prog_Common.h Intellect_Common.h Intellect_Interface.h
$(DL_BrkConfRpt_OFILES)   : Intellect_Common.h Intellect_Interface.h CO_HostStructdef.h DL_Interface.h MT_Interface.h
$(RuReconReport_OFILES)   : Intellect_Common.h Intellect_Interface.h CO_HostStructdef.h DL_Interface.h MT_Interface.h
$(UP_RmtDL_OFILES)  : Intellect_Common.h Intellect_Interface.h CO_HostStructdef.h DL_Interface.h MT_Interface.h SMI_InterFace.h
#EMU Conversion

$(EM_ConvAcc_OFILES)	:	Intellect_Interface.h Intellect_Common.h Prog_Common.h CR_Common.h
$(EM_ConvSec_OFILES)	:	Intellect_Interface.h Intellect_Common.h Prog_Common.h CR_Common.h
$(EM_ConvPendTrans_OFILES) : Intellect_Interface.h Intellect_Common.h Prog_Common.h CR_Common.h
$(EM_ConvBilling_OFILES) : Intellect_Interface.h Intellect_Common.h Prog_Common.h CR_Common.h
$(DL_SLBREV_OFILES)    : Intellect_Interface.h DL_Interface.h MT_Interface.h

#Corporate Actions.

$(CA_GenEntitl_OFILES)	: CA_Common.h
$(CA_ProcPymt_OFILES)	: CA_Common.h SMI_InterFace.h
$(CA_GenEvt_A_OFILES)	: CA_Common.h
$(CA_GenEvt_B_OFILES)	: CA_Common.h
$(CA_SplitPymt_OFILES): CA_Common.h SMI_InterFace.h
$(CA_IntimateEvt_OFILES)	: CA_Common.h
$(Conv_Safek_OFILES)	: CA_Common.h
$(Conv_Excptn_OFILES)	: CA_Common.h
$(Conv_Dec_Len_OFILES)	: CA_Common.h
$(CA_GenerateAlert_OFILES)	: CA_Common.h
$(CA_Arch_OFILES)	: CA_Common.h
$(CA_PymtGlobal_OFILES)  : CA_Common.h
$(CA_BODCastMsg_OFILES)	: CA_Common.h
$(CA_RedomEvt_OFILES)	: CA_Common.h
$(CA_ENRARpt_OFILES)	: CA_Common.h
$(CA_CustInstr_OFILES)	: CA_Common.h
$(EI_InitSMI_OFILES)	: CA_Common.h SMI_InterFace.h

CA_Common.h				: Intellect_Interface.h CA_InterFace.h MT_Interface.h DL_Interface.h CR_Common.h Intellect_Common.h

#Billing & Messages.

$(I_MSGTRAN_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(I_EMAILTRAN_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(I_MSGSCH_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h
$(MS_Arch_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(I_MSGENT_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(MS_IncomingMsRpt_OFILES): Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(MS_CCSFailRpt_OFILES): Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(MS_MsgStatRpt_OFILES) : Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(DL_Setl_Rpt_OFILES)    : Intellect_Interface.h DL_Interface.h MT_Interface.h
$(autojob_mon_OFILES): Intellect_Interface.h DL_Interface.h MT_Interface.h
$(CA_AEGenetae_OFILES)  : Intellect_Interface.h CA_InterFace.h DL_Interface.h  MT_Interface.h
$(Del_BaseNo_OFILES)     : Intellect_Interface.h
$(I_MANMSGREP_OFILES): Intellect_Interface.h
$(I_MSGENT_OFILES)   : DL_Interface.h MT_Interface.h
$(CR_DLDtPosRpt_OFILES) : Intellect_Interface.h DL_Interface.h MT_Interface.h
$(NBHMonRep_OFILES)  : Intellect_Interface.h DL_Interface.h MT_Interface.h
$(Rep_NCH_Hun_OFILES): Intellect_Interface.h DL_Interface.h MT_Interface.h
$(CR_DwHfDly_OFILES):Intellect_Interface.h MT_Interface.h DL_Interface.h
$(MESSAGE_OBJS)		: MS_Swift.h
$(ExchgOrderMatch_OFILES): Intellect_Common.h Intellect_Interface.h
$(MS_DL_BCN_MAP_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DLUNMAPPED548_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DL_MAP_RESET_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DL_SETL_BLK_REL_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DL_Mark_Recon_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DL_FundObligGen_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(FundObligRep_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(FundObligScrip_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(CA_PassAccEnt_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(GenReport_OFILES): Intellect_Common.h Intellect_Interface.h
$(DL_GenAE_OFILES): Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(IV_PassHoff_OFILES)		: Intellect_Common.h Intellect_Interface.h IV_Control_A.h CA_InterFace.h MT_Interface.h DL_Interface.h
$(IV_PayAEGenerate_OFILES)		: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillGenerate_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillResend_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillDeliver_OFILES)		: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillPrnt_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillPrnt_EMINV_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillPrnt_HTML_OFILES)   : Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillPrnt_DETINV_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_BillPrnt_DETHTML_OFILES)   : Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_Arch_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(RBIRept_OFILES) : Intellect_Common.h Intellect_Interface.h

$(DynamicReport_OFILES): Reports_Common.h Intellect_Interface.h

$(EPI_AccountEntries_OFILES) : Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(IV_PrntSummary_OFILES): Intellect_Common.h Intellect_Interface.h
$(IV_ProvBill_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_PrntDetail_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_PrntTransDetail_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(IV_PrntCustDetail_OFILES)	: Intellect_Common.h Intellect_Interface.h IV_Control_A.h

$(IV_AEGenerate_OFILES)		: Intellect_Common.h Intellect_Interface.h IV_Control_A.h
$(GR_PASS_OFILES)		: Intellect_Common.h Intellect_Interface.h IV_Control_A.h DL_Interface.h MT_Interface.h
$(IV_GPSSGenerate_OFILES) : Intellect_Common.h Intellect_Interface.h IV_Control_A.h DL_Interface.h MT_Interface.h
$(C_AutoSettHU_OFILES)	: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h
$(DL_SetlDtRpt_OFILES)	: Intellect_Interface.h DL_Interface.h MT_Interface.h
$(CR_DWTran_OFILES)   : MS_Mq.h Intellect_Interface.h Intellect_Common.h
$(UpdDaemonStat_OFILES)	: Intellect_Common.h Intellect_Interface.h MT_Interface.h
$(DL_PassAE_OFILES)	: Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(DL_GenDPInst_OFILES)	: Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(Msg548_OFILES)	: CA_Common.h CO_HostStructdef.h DL_Interface.h
$(DL_PassDPInst_OFILES)	: Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(I_MOVEMSG_OFILES)	: Intellect_Common.h Intellect_Interface.h DL_Interface.h
$(MS_MSG_RESEND_OFILES) : Intellect_Common.h CR_Common.h MS_Swift.h
$(EOD_Handover_OFILES)  : Intellect_Common.h
$(MT_IntUpdt_OFILES) : Intellect_Common.h MT_Interface.h
$(INT_AUTOSYS_OFILES)   : Intellect_Common.h
