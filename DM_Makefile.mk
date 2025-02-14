#
# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5 
# @(#)Module: Makefile $Revision:   1.0.1.21  $ $Date:   16 Apr 2008 19:44:06  $
#
#

#include 	${ORACLE_HOME}/precomp/lib/env_precomp.mk
IC_ENVPRECOMP_PATH	= .
IC_GCC_PATH	= /icustody/gcc-4.0.2/ashdir
include   ${IC_ENVPRECOMP_PATH}/env_precomp.mk	
include   ${INTL_ROOT_PATH}/intl_sun.cfg
#include 	${ORACLE_HOME}/rdbms/lib/env_rdbms.mk
.SUFFIXES: .pc .c .o

#Following 3 lines are used only for Linux Migration OS
INCLUDES=sys_include=$(ORACLE_HOME)/precomp/public  sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/include sys_include=/usr/include/linux sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include sys_include=/usr/lib64 sys_include=/usr/include/c++/4.8.5/tr1 sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include ltype=short
PROCFLG = $(INCLUDES)
INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE CODE=ANSI DEFINE=__x86_64__ define=OS_LINUX proc

#Following line is used only for AIX OS
#INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE DEFINE=__64BIT__ proc

THREADS_OPTION = threads=no LINES=YES
#Following line is used only for AIX OS
#DEBUG		= -g -maix64 -B ${IC_GCC_PATH}/gcc
#Following line is used only for linux and sun-solaris
DEBUG		= -g0 -m64 -B ${IC_GCC_PATH}/gcc

INCENV		= -I. -I${ORACLE_HOME}/precomp/public
CDEFS = -Dunix -D_ALL_SOURCE
#Following line is used only for AIX OS
#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT  -Wall
#Following line is used only for Linux Migration
CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT -DOS_LINUX -Wall
ANSI_FLAGS	= -Aa -D_POSIX_SOURCE
HP_FLAGS	= -D_REENTRANT -D_POSIX_D10_THREADS -D_HPUX_SOURCE

#Linene below is for CFLAGS......... 
LIBS		= -L/usr/lib/64 -ldce -lm -L$(LIBHOME) $(PROLDLIBS) -L/icustody/sureshk/lib 
NON_DCE_LIBS = -L$(LIBHOME) $(PROLDLIBS) -L/icustody/sureshk/lib/
MQ_LIBS = -L$(LIBHOME) -L/opt/mqm/lib -lmqm -L/icustody/sureshk/lib $(PROLDLIBS) -L${SESAM_LIB} -L${SYBASE}/lib -lintl -lpthread
# When compiling/linking on HP-UXv9.X systems use:
# When compiling/linking on HP-UXv10.X systems, use the following:
LDFLAGS        = ${DEBUG} -D_REENTRANT

#DL_WI_PMSProcess.o and DL_WebProcPopulate.o added for WEB PMS AUTH
#PROGRAMS	= Daemon_DL Daemon_MT Daemon_IV Daemon_CA Daemon_Batch Daemon_SMPTran Daemon_SMPResp Daemon_SMPIn Daemon_SFETran Daemon_CCSTran Daemon_CCSIn Daemon_SecRouterTran
PROGRAMS = Daemon_DL Daemon_MT Daemon_IV Daemon_CA Deformater Daemon_Batch DeformaterUp Rest_Deform_Serv

DEF_UP_OBJS =			DeformaterUp.o

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
							CO_Proc_DBRptIns.o

COMMON_DMN_OBJS = RtvSysDt.o\
               Intl_ErrorMsg.o\
               ChkCodeValid.o\
               Intl_ProcErrorMsg.o\
               HolidayFun.o\
               CO_ProcLog.o\
               CO_ReadToken.o\
               RtvNextSeqNumber.o\
               RtvSysParm.o\
               CntryCondFun.o\
               CO_ProcPrnt.o\
               DateFunctions.o\
               Intl_Customize.o\
               CO_Common.o\
               ChkAudSystemOnline.o

MESSAGE_OBJS=			MS_FormaterCommon_A.o\
				IV_MessageEntry.o\
				IV_Common_A.o\
				IV_CntlParam.o\
				MS_FormaterCommon.o\
				MS_FormaterCommon_B.o\
				IV_BillGenFn_G.o

TRADE_OBJS =  DL_ChkDLDel.o\
            DL_ProcDL.o\
            DL_ProcDL_A.o\
            DL_ProcDL_B.o\
            DL_ProcDL_C.o\
            DL_ProcDL_D.o\
            DL_ProcDL_E.o\
            DL_ProcDL_F.o\
            MT_DbProcMisDL.o\
            EOD_ProcMkrtPr.o\
            DL_RstSetlSingle.o\
            CR_InstrConvFn.o\
            DL_DbRstDLConf.o\
            CR_ProcMoveToHis.o\
            Intl_Common.o\
            MT_ProcDL_A.o\
            MT_ProcDL_B.o\
            MT_ProcMisDL.o\
            CR_ProcAutoMrktPr.o\
            DL_RstDLSetl.o\
            DL_RstDLConf.o\
            CR_ProcInstrConv.o\
            CO_RtvFldValFn.o\
            CO_ChkAcc.o\
            CO_ChkPty.o\
            CO_ChkInstr.o\
            CO_ChkLoc.o\
            CO_ChkCcy.o\
            RtvAccFieldFn.o\
            RtvInstrFldVal.o\
            IV_Common_A.o\
            IV_CntlParam.o\
            CR_InstrCodeChg.o\
            CR_ProcInstrCdChng.o\
            CR_ProcOrd.o\
            CR_DbProcOrd_A.o\
            CR_ProcOrd_A.o\
            CR_ProcOrd_B.o\
            CR_DbProcOrd_B.o\
            RtvCcyFldVal.o\
            CR_ProcLocChg.o\
            CR_RstClhSing.o\
            CR_RstCLH.o\
            CR_ProcReg.o\
            MT_ProcBookClose.o\
            MT_DbProcBookClose.o\
            CO_Proc_DBRptIns.o\
            MS_FormaterCommon.o\
            IV_BillGenFn_G.o\
            MS_MsgCommon.o\
            MS_FormaterCommon_A.o\
            IV_MessageEntry.o\
            IV_MessageStat.o\
            MT_ProcLocChg.o\
            CR_ProcInstrRound.o\
            MS_FormaterCommon_B.o\
            EI_SMICommon.o\
            CR_ModMQFn.o\
				CR_CCSPendDLUpdate.o\
            EI_SMIChkModStat.o\
            DL_ProcPopulate.o\
				Co_Chkcompany.o\
				CO_ChkMastChldDet.o\
				CR_RstOrd.o\
				MT_UpdDL_BCN.o\
				MT_ProcDL_BCN.o\
				MT_ProcDL_BifDet.o\
				MT_UpdDL_BifDet.o\
				MT_ProcDL_TAKEOVER.o\
				MT_UpdDL_TAKEOVER.o\
				DL_ProcDefDeal.o\
				MT_ProcDL_MarkShortage.o\
				MT_UpdDL_MARKSHORTAGE.o\
				MT_ProcDL_SqOff.o\
				MT_UpdDL_SQOFF.o\
				MT_UpdDL_EXCHGORD_UPLD.o\
				DL_ProcExchgOrd_Upld.o\
				DL_InsDbRepairDeal.o\
				c_dbInsTables.o\
				MT_UpdDL_DPGEN_DET.o\
				DL_NSE_OBL.o\
				DL_POOLACCRECS.o\
            DL_DBProcIntrSchm.o\
            DL_ProcIntrSchm.o\
            DL_ProcForcMatch.o\
				MT_ProcDL_PoolAccDmp.o\
				MT_UpdDL_POOLACCDMP.o\
				pool_acc_gfu.o\
				DL_UpdDpInst.o\
				DL_Inst_COD.o\
				CA_Block_type.o\
				DL_MarkDvp.o\
				DL_Upd_CDSLDPInst.o\
				DL_Inst_COD_CDSL.o\
				DL_BSE_OBL.o\
				DL_UPL_SOH.o\
				BCN_FailUpd.o\
				DL_UpdDecimalAdj.o\
                                DL_ModDecimalAdj_Detail.o\
                                DL_ModSingle_Prematch_Detail.o\
	                        DL_UpdDL_Single_Prematch.o\
                                DL_WI_PMSProcess.o\
                                DL_WebProcPopulate.o\
								FPI_Repair_DL_Deal.o\
				Daemon_DL.o

MNT_OBJS =  MT_ProcCcy.o\
            MT_ProcWithHTaxRt.o\
            MT_ProcExgRt.o\
            MT_ProcLoc.o\
            MT_ProcHol.o\
            MT_DbProcCcy.o\
            MT_DbProcWithHTax.o\
            MT_DbProcExgRt.o\
            MT_DbProcLoc.o\
            MT_DbProcHol.o\
            CO_ChkCcy.o\
            MT_ProcACE.o\
            CO_ChkExgRt.o\
            CO_ChkWithTaxRt.o\
            CO_ChkLoc.o\
            CO_ChkHol.o\
            MT_ProcAcc.o\
            MT_DbProcAcc.o\
            RtvAccFieldFn.o\
				CO_ChkCrdRatAgn.o\
            MT_ProcInstrument.o\
            MT_DbProcInstrument.o\
            RtvInstrFldVal.o\
            RtvLocFldVal.o\
            Intl_Common.o\
            RtvLocRefFldVal.o\
            CO_ChkAcc.o\
            CO_ChkInstr.o\
            IV_ProcCustPara.o\
            IV_ProcServDep.o\
            IV_ProcCustFee.o\
            IV_CltParamFn_A.o\
            IV_CltParamFn_B.o\
        		IV_AccParamFn_C.o\
        		IV_Common_B.o\
        		IV_AccSetup.o\
        		IV_AccParamFn.o\
        		IV_ServicesFn.o\
        		IV_CntlParam.o\
        		IV_ServBasisFn.o\
        		IV_SServBasisFn.o\
        		IV_ParamTypeFn.o\
        		IV_AccSetup_A.o\
        		IV_ClientParamFn_A.o\
        		IV_ServBasisFn_A.o\
        		IV_ParamTypeFn_A.o\
        		IV_AccFeeFn.o\
        		IV_OtherServ_A.o\
        		IV_DbPymtFn_A.o\
        		CO_Prnt.o\
        		CO_Proc_DBRptIns.o\
        		CA_Setup.o\
        		CM_SysParams.o\
        		RtvHelpID.o\
        		CR_ProcInstrRound.o\
        		c_rusmaint.o\
        		c_rumaintchrval.o\
        		c_rucom.o\
        		c_rudbmaint.o\
        		MT_ProcAssis.o\
        		CR_ModBassis.o\
        		CR_ProcOrd.o\
        		CR_ModMQFn.o\
        		Convert_Msg.o\
        		CR_HdatMod.o\
        		CR_ProcHdat.o\
        		CR_ChkHdat.o\
        		MT_ProcPopulate.o\
				CO_ChkMastChldDet.o\
       MT_Dbcompany.o\
        MT_ProcCmp.o\
        Co_Chkcompany.o\
        MT_Updclntinstr.o\
        MT_Procclntinstr.o\
        Co_chk_clninstr.o\
        MT_UpdInsEntry.o\
        CoChk_instslip.o\
        MT_ProcInslEntry.o\
        MT_ProcStlcal.o\
        MT_DbUpdStlcal.o\
        CO_ChkStlCal.o\
		  MT_ProcDlyQtions.o\
		  MT_DbUpdDlyQtions.o\
		  CoChk_DlyQtions.o\
		  MT_ProcDlFlRate.o\
        MT_DbProcDlFlRate.o\
		  MT_ProcRBIMonDet.o\
        MT_DbProcRBIMonDet.o\
		   MT_ProcNoDlvDet.o\
          MT_DbProcNoDlvDet.o\
		   MT_ProcFlRateInst.o\
          MT_DbProcFlRateInst.o\
			 MT_DbProcStaticData.o\
			 CO_ChkPty.o\
				MT_ProcIndexFund.o\
				MT_DbProcIndexFund.o\
                         MT_ProcDepoPart.o\
                         MT_DbProcDepoPart.o\
                         MT_ProcCrRtAgency.o\
                         MT_DbProcCrRtAgency.o\
								 MT_ProcParty.o\
								 MT_DbProcParty.o\
								 MT_UpdMT_VENDOR.o\
								 MT_ProcVendor.o\
								 MT_UpdMT_GFU_FORMAT_SETUP.o\
								 MT_ProcGFU_FORMAT_SETUP.o\
								 MT_ProcAddLn_Det.o\
								 MT_UpdMT_CLN_ADDLN_DET.o\
								 MT_ProcPtyFundDet.o\
								 MT_DbProcPtyFundDet.o\
								MT_Populate_WI_CLIENT_MAP.o\
                        					MT_UpdCln_Mapping.o\
				MT_DbProcVARELM_Upld.o\
				Daemon_MT.o

BILL_OBJS =	MS_ManualMsg.o\
                 CR_ProcBaseMnt.o\
                 IV_Base.o\
                 IV_MessageAddr.o\
		 IV_Common_B.o\
                 IV_ProcPymt.o\
                 IV_PymtFn_A.o\
                 IV_ProcPymt_A.o\
                 IV_ProcPymt_B.o\
                 IV_PymtFn_B.o\
                 IV_DbPymtFn_B.o\
                 IV_PymtDetFn.o\
                 IV_PymtDetFn_A.o\
                 IV_AccSetup.o\
                 IV_ServicesFn.o\
                 IV_LedgerFn.o\
                 IV_LedgerFn_A.o\
                 IV_BillDelFn_A.o\
                 IV_BillDelFn_B.o\
                 IV_BillGenFn_G.o\
                 CO_ChkAcc.o\
		 IV_ProcServ.o\
		 IV_ServFn_A.o\
		 IV_ProcChgServ.o\
		 IV_ServicesFn_A.o\
		 IV_ProcBillAcc.o\
		 IV_AccFn.o\
		 IV_AccFn_A.o\
		 IV_ProcOthServ.o\
		 IV_OthServFn.o\
		 IV_ProcServMode.o\
		 IV_CntlParam.o\
		 IV_OtherServ_B.o\
		 IV_MessageLog.o\
		 IV_CntlPram_B.o\
		 IV_OtherServ_C.o\
		 IV_ProcBillCntlParm.o\
		MS_FormaterCommon_B.o\
		CA_note.o\
		Intl_Common.o\
		Daemon_IV.o\
		IV_ProcBucketTxn.o\
		IV_ProcPopulate.o\
		IV_ProcBucketTxnMnt.o\
		IV_ProcMutualFund.o\
		IV_ProcMutualFundMnt.o\
		IV_UpdManual_Msg.o\
		Manual_Msg_Detail.o\
                IV_NRI_TDS_MNT.o\
                IV_NRI_TDS.o\
		IV_Pymnt_Mnt_A.o\
		IV_RoundFn.o\
		CO_ChkMastChldDet.o

CA_OBJS  =  CA_EvtMod.o\
            CA_EvtAuth.o\
            CA_PymtMod.o\
            CA_PymtAuth.o\
            CA_PymtGlobal.o\
            CA_RightEvt.o\
            CA_Common.o\
            CA_CreateDL.o\
			CO_DateFuns.o\
			CA_Block_type.o\
            DL_ProcDL.o\
            DL_ProcDL_A.o\
            DL_ProcDL_E.o\
            Intl_Common.o\
            MT_ProcDL_A.o\
				CO_ChkPty.o\
            RtvAccFieldFn.o\
            RtvInstrFldVal.o\
            CO_RtvFldValFn.o\
            CO_ChkCcy.o\
            CO_ChkLoc.o\
            CO_ChkInstr.o\
            CO_ChkAcc.o\
            CA_note.o\
            CA_EntitlMod.o\
            CA_EntitlAuth.o\
            IV_Common_A.o\
            IV_CntlParam.o\
            MS_FormaterCommon.o\
            IV_BillGenFn_G.o\
            DL_ChkDLDel.o\
            MS_FormaterCommon_A.o\
            IV_MessageEntry.o\
            CR_ProcInstrRound.o\
            CA_MTRedomEvt.o\
            MS_FormaterCommon_B.o\
            CR_ProcOrd.o\
            CR_ModMQFn.o\
            CR_CCSPendDLUpdate.o\
            EI_SMICommon.o\
            CA_ProcPopulate.o\
		  		Co_Chkcompany.o\
		  		MT_ProcCA_NIS_BID.o\
		  		MT_DbProcCA_NIS_BID.o\
				MT_DbProcCA_NIS_APPLICATION.o\
				MT_ProcCA_NIS_APPLICATION.o\
				CO_ChkMastChldDet.o\
				CA_RTBB_ALLOTMENT.o\
				MT_Populate_CA_RTBB_ALLOTMENT.o\
				MT_Populate_CA_APPLICATION.o\
				CA_APPLICATION.o\
				MT_ProcCA_NIS_ALLOTMENT.o\
 			        MT_DbProcCA_NIS_ALLOTMENT.o\
					CA_PUTCALL_APP.o\
					MT_Populate_CA_PUTCALL_APP.o\
					CR_ProgRestartFn.o\
					FPI_Repair_CA_Deal.o\
            Daemon_CA.o

BATCH_OBJS =  Intl_Common.o\
            CR_ProgRestartFn.o\
            Daemon_Batch.o

 DEF_OFILES =   Deformater.o\
					 DFParamString.o\
					 DFCommon.o\
					 DF_InsTables.o\
					 c_dbInsTables.o\
					 DFRecCommon.o\
					 Intl_Common.o\
					 DF_ProcessMessage_54x.o\
					 DF_ProcessMessage_515.o\
					 $(COMMON_OBJS)\
					 $(MESSAGE_OBJS)\
					 $(MESSAGE_FUN_FILES)


Trade_Dmn_OFILES =  $(TRADE_OBJS)\
							$(COMMON_DMN_OBJS)

Mnt_Dmn_OFILES =  $(MNT_OBJS)\
							$(COMMON_DMN_OBJS)

Bill_Dmn_OFILES =  $(BILL_OBJS)\
							$(COMMON_DMN_OBJS)

CA_Dmn_OFILES =  $(CA_OBJS)\
							$(COMMON_DMN_OBJS)

Batch_Dmn_OFILES =  $(BATCH_OBJS)\
							$(COMMON_DMN_OBJS)

Def_Up_Dmn_OFILES =	$(DEF_UP_OBJS)
 

all:		objects ${PROGRAMS}
objects:	${Trade_Dmn_OFILES} ${Mnt_Dmn_OFILES} ${Bill_Dmn_OFILES} $(CA_Dmn_OFILES) ${Batch_Dmn_OFILES} 
fresh:	clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${PROGRAMS} ${Trade_Dmn_OFILES} ${Mnt_Dmn_OFILES} ${Bill_Dmn_OFILES} $(CA_Dmn_OFILES) ${Batch_Dmn_OFILES} 

clobber:	clean
	rm -f a.out core ERRS make.out *~

Daemon_DL	:	${Trade_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${Trade_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_MT	:	${Mnt_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${Mnt_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_IV	:	${Bill_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${Bill_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_CA	:	${CA_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${CA_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_Batch	:	${Batch_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${Batch_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Deformater            :   ${DEF_OFILES}
	        $(CC) ${LDFLAGS} ${DEF_OFILES} ${NON_DCE_LIBS} -o $@
		
DeformaterUp            :   ${Def_Up_Dmn_OFILES}
	        $(CC) ${LDFLAGS} ${Def_Up_Dmn_OFILES} ${NON_DCE_LIBS} -o $@
			
Rest_Deform_Serv	:	${DEF_UP_OBJS}
			  $(CC) ${LDFLAGS} ${Def_Up_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

$(Trade_Dmn_OFILES) :  CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h MS_Swift.h SMI_InterFace.h DL_Interface.h
$(Mnt_Dmn_OFILES) :  CO_HostStructdef.h Intellect_Common.h Intellect_Interface.h MS_Swift.h SMI_InterFace.h DL_Interface.h
$(Bill_Dmn_OFILES) : IV_Control_A.h IV_InterFace.h MS_Swift.h 
$(Batch_Dmn_OFILES) : Intellect_Interface.h Intellect_Common.h Prog_Common.h 
CO_HostStructdef.h            : CO_IndStructdef.h CO_OthStructdef.h CO_Externdef.h CO_Commdef.h MT_Interface.h DL_Interface.h CR_Common.h
CA_Common.h : Intellect_Interface.h CA_InterFace.h MT_Interface.h DL_Interface.h CR_Common.h Intellect_Common.h
IV_Control_A.h       :       Intellect_Common.h CR_Common.h Intellect_Interface.h
