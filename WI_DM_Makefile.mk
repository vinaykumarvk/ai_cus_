#
# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5 
# @(#)Module: Makefile $Revision:   1.0.1.4  $ $Date:   24 Oct 2007 09:41:14  $
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
INCLUDES=sys_include=$(ORACLE_HOME)/precomp/public  sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.3/include sys_include=/usr/include sys_include=/usr/include/linux sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.3/include sys_include=/usr/lib64 sys_include=/usr/include/c++/4.8.3/tr1 sys_include=/usr/lib/gcc/x86_64-redhat-linux/4.8.3/include ltype=short
PROCFLG = $(INCLUDES)
INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE CODE=ANSI DEFINE=__x86_64__ define=OS_LINUX proc

#Following line is used only for AIX OS
#INTL_PROC_OPTION = CHAR_MAP=STRING LINES=YES define=PC_COMPILE DEFINE=__64BIT__ proc

THREADS_OPTION = threads=no LINES=YES

#Following line is used only for AIX OS
#DEBUG		= -g -maix64 -B ${IC_GCC_PATH}/gcc
#Following line is used only for Linux Migration
DEBUG		= -g -m64 -B ${IC_GCC_PATH}/gcc

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

#PROGRAMS	= Daemon_Web WI_CA_SMInstruct WI_CA_SMInst_Auth WI_GF_Upload DynamicReport 
PROGRAMS = Daemon_Web WI_CA_SMInstruct WI_CA_SMInst_Auth WI_GF_Upload DynamicReport WI_BulkDealAuth

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
				Intl_Common.o\
                                RtvNextSeqNumber.o\
				CO_Proc_DBRptIns.o


WEB_OBJS = CR_ProgRestartFn.o\
            DL_WebProcPopulate.o\
            CO_ChkMastChldDet.o\
            DL_dbWI_DEAL.o\
            DL_WI_DEAL.o\
		CA_UpdCA_Instruction.o\
		CA_Instruction_Detail.o\
		WI_UpdWEB_MANUAL_MSG.o\
		$(COMMON_OBJS)\
            Daemon_Web.o

 
WI_CA_SMInstruct_OFILES   = CA_SM_Instruct.o\
								$(COMMON_OBJS)

WI_CA_SMInst_Auth_OFILES   = CA_Instruct_Auth.o\
								$(COMMON_OBJS)

WI_BulkDealAuth_OFILES   = WI_BulkDealAuth.o\
                        DL_dbWI_DEAL.o\
            		CO_ChkMastChldDet.o\
                        DL_WI_DEAL.o\
								$(COMMON_OBJS)
DynamicReport_OFILES  = DynamicReport.o\
                        IntlReportsNew.o\
                        CR_ProgRestartFn.o\
                        $(COMMON_OBJS)

WI_GF_Upload_OFILES = WI_GF_Upload.o\
                                                 WI_GF_Common.o\
                                                 Intl_ProcErrorMsg.o\
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
                                                 CR_ProgRestartFn.o\
                                                 RtvNextSeqNumber.o\
                                                 CO_Proc_DBRptIns.o\
                                                 Intl_Common.o\
                                                 BT_Common.o\
                                                 CO_ProcFileName.o\
                                                 EI_SMICommon.o



all:		objects ${PROGRAMS}
objects:	${Trade_Dmn_OFILES} ${Mnt_Dmn_OFILES} ${Bill_Dmn_OFILES} $(CA_Dmn_OFILES) ${Batch_Dmn_OFILES} 
fresh:	clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
       #	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${WEB_INTL_DB_USR}/${WEB_INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${WEB_INTL_DB_USR}/${WEB_INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${WEB_INTL_DB_USR}/${WEB_INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${WEB_INTL_DB_USR}/${WEB_INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${PROGRAMS} ${Trade_Dmn_OFILES} ${Mnt_Dmn_OFILES} ${Bill_Dmn_OFILES} $(CA_Dmn_OFILES) ${Batch_Dmn_OFILES} 

clobber:	clean
	rm -f a.out core ERRS make.out *~

DynamicReport 	:	${DynamicReport_OFILES}
	$(CC) ${LDFLAGS} ${DynamicReport_OFILES} ${NON_DCE_LIBS} -o $@

WI_CA_SMInstruct	:	${WI_CA_SMInstruct_OFILES}
	$(CC) ${LDFLAGS} ${WI_CA_SMInstruct_OFILES} ${NON_DCE_LIBS} -o $@

WI_CA_SMInst_Auth	:	${WI_CA_SMInst_Auth_OFILES}
	$(CC) ${LDFLAGS} ${WI_CA_SMInst_Auth_OFILES} ${NON_DCE_LIBS} -o $@

WI_BulkDealAuth	:	${WI_BulkDealAuth_OFILES}
	$(CC) ${LDFLAGS} ${WI_BulkDealAuth_OFILES} ${NON_DCE_LIBS} -o $@


WI_GF_Upload	:	${WI_GF_Upload_OFILES}
	$(CC) ${LDFLAGS} ${WI_GF_Upload_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_Web	:	${WEB_OBJS}
	$(CC) ${LDFLAGS} ${WEB_OBJS} ${NON_DCE_LIBS} -o $@
