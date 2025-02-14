# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5
# @(#)Module: Makefile $Revision:   1.0.1.7  $ $Date:   18 Dec 2007 16:54:02  $
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
#INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE DEFINE=__64BIT__ proc

THREADS_OPTION = threads=no

#Following line is used only for AIX OS
#DEBUG		= -g -maix64 -B ${IC_GCC_PATH}/gcc

#Following line is used only for Linux Migration
DEBUG		= -g -m64 -B ${IC_GCC_PATH}/gcc

INCENV		= -I. 
ANSI_FLAGS	= -Aa -D_POSIX_SOURCE
CDEFS = -Dunix -D_ALL_SOURCE
#Following line is used only for AIX OS
#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT  -Wall
#Following line is used only for Linux Migration
CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT -DOS_LINUX -Wall
HP_FLAGS	= -D_REENTRANT -D_POSIX_D10_THREADS -D_HPUX_SOURCE

LIBS          = -L/usr/lib/64 -ldce -lm -L$(LIBHOME) $(PROLDLIBS)
NON_DCE_LIBS = -L$(LIBHOME) $(PROLDLIBS)
# When compiling/linking on HP-UXv9.X systems use:
#LDFLAGS         = ${DEBUG} -Wl,-Bimmediate -Wl,-Bnonfatal
# When compiling/linking on HP-UXv10.X systems, use the following:
LDFLAGS        = ${DEBUG} -D_REENTRANT

PROGRAMS	= MS_ISOFormatter IV_GenPymt

#Removed from Mproc_Makefile as cleaning activity- 18th July 2019
#PROGRAMS= MS_OldFormatter CR_CDVMHf LocalRep_MO C_MaroPmtUpld Daemon_BidTran EgReconRpt CR_CIMSHf CR_WhtxRpt EI_SMIFeedFile UP_Hdat CA_StatRpt UP_OTC UP_EOC MS_578Resnd UP_IPO DL_AutoCancl 

CDVM_HANDOFF_OBJS  =    CR_ProcCdvmHf.o\
								Function_Batch.o\

LOCALREP_MO_OBJS  =  Function_Batch.o\
							c_locrepmor.o


UP_IPO_OFILES = Upd_IPO.o\
				CR_ModMQFn.o\
				CR_CCSPendDLUpdate.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				MT_ProcDL_B.o\
				MS_MsgCommon.o\
				CR_ProcMoveToHis.o\
				DL_ProcDL_B.o\
				DL_ProcDL_F.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_E.o\
				DL_ChkDLDel.o\
				CR_ProcInstrRound.o\
				RtvAccFieldFn.o\
				CO_ChkCcy.o\
				RtvInstrFldVal.o\
				CO_ChkAcc.o\
				CO_RtvFldValFn.o\
				CO_ChkLoc.o\
				CO_ChkInstr.o\
				CR_ProcOrd.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				EI_SMICommon.o\
				CO_Common.o\
               $(COMMON_OBJS)\
               $(MESSAGE_OBJS)

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
							Intl_Common.o\
							CO_Proc_DBRptIns.o

MESSAGE_OBJS=			MS_FormaterCommon_A.o\
							IV_MessageEntry.o\
							IV_Common_A.o\
							IV_CntlParam.o\
							MS_FormaterCommon.o\
							MS_FormaterCommon_B.o\
							IV_BillGenFn_G.o

I_MSGFN_OFILES = MS_ProcFn.o\
		MS_ProcFn_A.o\
		MS_ProcFn_B.o\
		MS_ProcFn_C.o\
		IV_Base.o\
		IV_MessageLog.o\
		IV_MessageStat.o\
		IV_MessageEntry.o\
		CO_Rtv_Token.o\
		Proc_RestartLogic.o\
		$(COMMON_OBJS)

CR_CIMSHf_OFILES = CR_CIMSHf.o\
                          $(COMMON_OBJS)

BID_TRANS_OFILES = MS_GcnFn.o\
      $(COMMON_OBJS)\
      Proc_RestartLogic.o\
      CO_FilterFn.o\
   $(MESSAGE_OBJS)

EgReconRpt_OFILES = c_recon_eg.o\
                        $(COMMON_OBJS)

I_MSGFN_15022_OFILES = MS_ProcFn_ISO.o\
		MS_ProcFnA_ISO.o\
		MS_ProcFnB_ISO.o\
		MS_ProcFnC_ISO.o\
		IV_Base.o\
		IV_MessageLog.o\
		IV_MessageStat.o\
		IV_MessageEntry.o\
		CO_Rtv_Token.o\
		CR_ProgRestartFn.o\
		Proc_RestartLogic.o\
		$(COMMON_OBJS)

CR_CDVMHf_OFILES   =  $(CDVM_HANDOFF_OBJS)\
                        $(COMMON_OBJS)

LocalRep_MO_OFILES   =  $(LOCALREP_MO_OBJS)\
                        $(COMMON_OBJS)


UP_Hdat_OFILES = UP_Hdat.o\
				CR_ModMQFn.o\
				CR_CCSPendDLUpdate.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_E.o\
				DL_ChkDLDel.o\
				CR_ProcInstrRound.o\
				RtvAccFieldFn.o\
				CO_ChkCcy.o\
				RtvInstrFldVal.o\
				CO_ChkAcc.o\
				CO_RtvFldValFn.o\
				CO_ChkLoc.o\
				CO_ChkInstr.o\
				CR_ProcOrd.o\
				EI_SMICommon.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				CO_Common.o\
            $(COMMON_OBJS)\
            $(MESSAGE_OBJS)

DL_AutoCancl_OFILES =DL_ProcAutoCancalFn.o\
				DL_ProcDL_B.o\
				EI_SMICommon.o\
				RtvAccFieldFn.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_E.o\
				CO_ValidationFn.o\
				CR_CCSPendDLUpdate.o\
				CR_ProcInstrRound.o\
				CO_ChkLoc.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				CR_ModMQFn.o\
				DL_ChkDLDel.o\
				RtvInstrFldVal.o\
				CO_RtvFldValFn.o\
				CR_ProcOrd.o\
                                CO_ChkAcc.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				CO_Common.o\
               $(COMMON_OBJS)\
               $(MESSAGE_OBJS)

UP_OTC_OFILES = UP_Otc.o\
				CR_ModMQFn.o\
				CR_CCSPendDLUpdate.o\
				MT_ProcDL_A.o\
				CO_ChkPty.o\
				DL_ProcDL.o\
				DL_ProcDL_A.o\
				DL_ProcDL_E.o\
				DL_ChkDLDel.o\
				CR_ProcInstrRound.o\
				RtvAccFieldFn.o\
				CO_ChkCcy.o\
				RtvInstrFldVal.o\
				CO_ChkAcc.o\
				CO_RtvFldValFn.o\
				CO_ChkLoc.o\
				CO_ChkInstr.o\
				CR_ProcOrd.o\
				EI_SMICommon.o\
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
				CO_Common.o\
               $(COMMON_OBJS)\
               $(MESSAGE_OBJS)

UP_EOC_OFILES = c_eocupload.o\
               $(COMMON_OBJS)\
               $(MESSAGE_OBJS)

C_MaroPmtUpld_OFILES = C_MaroPmtUpld.o\
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
				CA_CreateDL.o\
				CA_Block_type.o\
				CA_Common.o\
				CO_ChkMastChldDet.o\
				Co_Chkcompany.o\
            $(COMMON_OBJS)\
            $(MESSAGE_OBJS)\
				EI_SMICommon.o\
				CR_ProcOrd.o\
				CR_ModMQFn.o\
				CO_Common.o\
				CR_CCSPendDLUpdate.o

WITTAXREP_OFILES	=	CR_ProcWithTaxRpt.o\
							$(COMMON_OBJS)\
							Function_Batch.o

EI_SMIFeedFile_OFILES	=	EI_SFEFeedFile.o\
									Function_Batch.o\
									$(COMMON_OBJS)

IV_GenPymt_OFILES	=	IV_PayGenDirDebit.o\
							Function_Batch.o\
							IV_BillDelFn_C.o\
							IV_AccSetup.o\
							IV_BillDelFn_B.o\
							IV_DbPymtFn_B.o\
							IV_LedgerFn.o\
							IV_LedgerFn_A.o\
							IV_PymtFn_A.o\
							CR_ProcInstrRound.o\
							CR_ProcMoveToHis.o\
							DL_ProcDL.o\
							DL_ProcDL_A.o\
							DL_ProcDL_B.o\
							DL_ProcDL_E.o\
							CA_CreateDL.o\
							CR_ProcOrd.o\
							CO_ChkCcy.o\
							CO_ChkLoc.o\
							CO_ChkInstr.o\
							CR_ModMQFn.o\
							RtvInstrFldVal.o\
							CO_ChkAcc.o\
							IV_Common_B.o\
							IV_AccFn.o\
							IV_PymtFn_B.o\
							RtvAccFieldFn.o\
							DL_ChkDLDel.o\
							EI_SMICommon.o\
							CR_CCSPendDLUpdate.o\
							MT_ProcDL_A.o\
							CO_ChkPty.o\
							CO_RtvFldValFn.o\
							CO_Common.o\
							CO_ChkMastChldDet.o\
							Co_Chkcompany.o\
							CA_Block_type.o\
							CA_Common.o\
							IV_Pymnt_Mnt_A.o\
							ChkAudSystemOnline.o\
							IV_RoundFn.o\
							$(MESSAGE_OBJS)\
							$(COMMON_OBJS)

CA_StatRpt_OFILES = CA_StatusRpt.o\
$(COMMON_OBJS)\
$(MESSAGE_OBJS)

MS_578Resnd_OFILES = MS_Resend578.o\
				Function_Batch.o\
$(COMMON_OBJS)\
$(MESSAGE_OBJS)

all:		objects ${PROGRAMS}
objects:	${I_MSGFN_OFILES} ${I_MSGFN_15022_OFILES}	${CR_CDVMHf_OFILES} ${LOCALREP_MO_OBJS} ${WITTAXREP_OFILES} ${EI_SMIFeedFile_OFILES} ${IV_GenPymt_OFILES} ${CA_StatRpt_OFILES} ${UP_OTCOFILES} ${UP_EOCOFILES} ${MS_578ResndOFILES}
fresh:		clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI  $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} DYNAMIC=ANSI SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc 
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${I_MSGFN_OFILES} ${I_MSGFN_15022_OFILES} ${PROGRAMS} ${CR_CDVMHf_OFILES} ${LocalRep_MO_OFILES} ${WITTAXREP_OFILES}

clobber:	clean
	rm -f a.out core ERRS make.out *~

MS_OldFormatter     :	${I_MSGFN_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGFN_OFILES} ${NON_DCE_LIBS} -o $@

MS_ISOFormatter     :	${I_MSGFN_15022_OFILES}
	$(CC) ${LDFLAGS} ${I_MSGFN_15022_OFILES} ${NON_DCE_LIBS} -o $@

CR_CIMSHf    :	${CR_CIMSHf_OFILES}
	$(CC) ${LDFLAGS} ${CR_CIMSHf_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_BidTran : ${BID_TRANS_OFILES}
	$(CC) ${LDFLAGS} ${BID_TRANS_OFILES} ${NON_DCE_LIBS} -o $@

EgReconRpt:	$(EgReconRpt_OFILES)
	$(CC) ${LDFLAGS} ${EgReconRpt_OFILES} ${NON_DCE_LIBS} -o $@

UP_IPO: $(UP_IPO_OFILES)
	$(CC) ${LDFLAGS} ${UP_IPO_OFILES} ${NON_DCE_LIBS} -o $@

UP_Hdat: $(UP_Hdat_OFILES)
	$(CC) ${LDFLAGS} ${UP_Hdat_OFILES} ${NON_DCE_LIBS} -o $@

DL_AutoCancl: $(DL_AutoCancl_OFILES)
	$(CC) ${LDFLAGS} ${DL_AutoCancl_OFILES} ${NON_DCE_LIBS} -o $@

UP_OTC: $(UP_OTC_OFILES)
	$(CC) ${LDFLAGS} ${UP_OTC_OFILES} ${NON_DCE_LIBS} -o $@

UP_EOC: $(UP_EOC_OFILES)
	$(CC) ${LDFLAGS} ${UP_EOC_OFILES} ${NON_DCE_LIBS} -o $@

C_MaroPmtUpld: $(C_MaroPmtUpld_OFILES)
	$(CC) ${LDFLAGS} ${C_MaroPmtUpld_OFILES} ${NON_DCE_LIBS} -o $@

CR_CDVMHf: ${CR_CDVMHf_OFILES}
	$(CC) ${LDFLAGS} ${CR_CDVMHf_OFILES} ${NON_DCE_LIBS} -o $@
LocalRep_MO: ${LocalRep_MO_OFILES}
	$(CC) ${LDFLAGS} ${LocalRep_MO_OFILES} ${NON_DCE_LIBS} -o $@

CR_WhtxRpt	:	${WITTAXREP_OFILES}
	$(CC) ${LDFLAGS} ${WITTAXREP_OFILES} ${NON_DCE_LIBS} -o $@

EI_SMIFeedFile	:	${EI_SMIFeedFile_OFILES}
	$(CC) ${LDFLAGS} ${EI_SMIFeedFile_OFILES} ${NON_DCE_LIBS} -o $@

IV_GenPymt	:	${IV_GenPymt_OFILES}
	$(CC) ${LDFLAGS} ${IV_GenPymt_OFILES} ${NON_DCE_LIBS} -o $@

CA_StatRpt	:	${CA_StatRpt_OFILES}
	$(CC) ${LDFLAGS} ${CA_StatRpt_OFILES} ${NON_DCE_LIBS} -o $@

MS_578Resnd	:	${MS_578Resnd_OFILES}
	$(CC) ${LDFLAGS} ${MS_578Resnd_OFILES} ${NON_DCE_LIBS} -o $@

$(I_MSGFN_OFILES)		: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h
$(I_MSGFN_15022_OFILES)		: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h
$(BID_TRANS_OFILES)  : Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h
$(EgReconRpt_OFILES)     : Intellect_Common.h Intellect_Interface.h CO_HostStructdef.h DL_Interface.h MT_Interface.h CA_InterFace.h
$(CR_CIMSHf_OFILES):Intellect_Interface.h MT_Interface.h DL_Interface.h CA_InterFace.h
$(CR_CDVMHf_OFILES)  : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h CA_InterFace.h DL_Interface.h MT_Interface.h
$(LocalRep_MO_OFILES)   : CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h CA_InterFace.h
$(UP_Hdat_OFILES)		: Intellect_Common.h CO_HostStructdef.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h
$(UP_IPO_OFILES)		: Intellect_Common.h CO_HostStructdef.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h DL_Ipo.h
$(DL_AutoCancl_OFILES)		: Intellect_Common.h CO_HostStructdef.h Intellect_Interface.h MS_Swift.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h
$(UP_OTC_OFILES)		: Intellect_Common.h CO_HostStructdef.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h
$(UP_EOC_OFILES)		: Intellect_Common.h CO_HostStructdef.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h
$(C_MaroPmtUpld_OFILES)		: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h SMI_InterFace.h CA_InterFace.h
$(MESSAGE_OBJS)		: MS_Swift.h
$(WITTAXREP_OFILES)		: Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h CA_InterFace.h
${EI_SMIFeedFile_OFILES}		:	Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h CA_InterFace.h SMI_InterFace.h
${IV_GenPymt_OFILES}		:	Intellect_Common.h Intellect_Interface.h MS_Swift.h IV_Control_A.h DL_Interface.h MT_Interface.h CA_InterFace.h SMI_InterFace.h
${CA_StatRpt_OFILES}		:	Intellect_Common.h Intellect_Interface.h MS_Swift.h CA_InterFace.h
${MS_578Resnd_OFILES}		:	Intellect_Common.h Intellect_Interface.h MS_Swift.h CA_InterFace.h

