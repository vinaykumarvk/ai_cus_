#
# (c) Copyright 1992, 1993, 1994 Hewlett-Packard Co.
#
# @(#)HP DCE/9000 1.5
# @(#)Module: Makefile $Revision:   1.0.1.4  $ $Date:   15 Jun 2007 15:40:04  $
#
#
IC_ENVPRECOMP_PATH   = ${PWD}
IC_GCC_PATH = /icustody/gcc-4.0.2/ashdir
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
#Following line is used only for LINUX OS
DEBUG		= -g -m64 -B ${IC_GCC_PATH}/gcc
INCENV		= -I. -I${ORACLE_HOME}/precomp/public
CDEFS = -Dunix -D_ALL_SOURCE
#Following line is used only for AIX OS
#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -DDATA_MIGRATION -D_REENTRANT  -Wall#CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT  -Wall
#Following line is used only for LINUX OS
CFLAGS  = ${DEBUG} ${CDEFS} ${INCDIRS} ${INCENV} -DORA_PROC -D_REENTRANT -DOS_LINUX -Wall
ANSI_FLAGS	= -Aa -D_POSIX_SOURCE
HP_FLAGS	= -D_REENTRANT -D_POSIX_D10_THREADS -D_HPUX_SOURCE

#Linene below is for CFLAGS.........
LIBS		= -L/usr/lib/64 -ldce -lm -L$(LIBHOME) $(PROLDLIBS)
NON_DCE_LIBS = -L$(LIBHOME) $(PROLDLIBS)
# When compiling/linking on HP-UXv9.X systems use:
# When compiling/linking on HP-UXv10.X systems, use the following:
LDFLAGS        = ${DEBUG} -D_REENTRANT

#PROGRAMS	= Daemon_MT_DM Daemon_BT_DM GF_Upload
#PROGRAMS	=  Daemon_BT_DM GF_Upload Daemon_MT_DM
PROGRAMS        =GF_Upload

COMMON_DMN_OBJS	=	Intl_ProcErrorMsg.o\
	Intl_ErrorMsg.o\
	RtvSysDt.o\
	CO_ReadToken.o\
	CO_ProcLog.o\
	Intl_Customize.o\
	RtvSysParm.o\
	DateFunctions.o\
	ChkCodeValid.o\
	CO_ProcPrnt.o\
	Intl_Common.o\
	ChkAudSystemOnline.o

BATCH_OBJS = Intl_Common.o\
            Daemon_BT.o\
				CR_ProgRestartFn.o\
            BT_Common.o

MNT_OBJS = Daemon_MT_DM.o\
            DM_Interface.o\
            CR_ProgRestartFn.o\
            DM_DbInterface.o\
            HolidayFun.o

Batch_Dmn_OFILES =  $(BATCH_OBJS)\
							$(COMMON_DMN_OBJS)\
							HolidayFun.o

GF_Upload_OFILES = GF_Upload.o\
						 GF_Common.o\
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
						 CO_Common.o\
						 ChkAudSystemOnline.o\
						 EI_SMICommon.o

MNT_Dmn_OFILES =  $(MNT_OBJS)\
							$(COMMON_DMN_OBJS)

all:		objects ${PROGRAMS}
objects:
fresh:	clean all

#PROCFLG is added for linux migration in .c and .o
.pc.c:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc

.pc.o:
	#$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) iname=$*.pc
	$(PROC) $(PROCFLAGS) $(THREADS_OPTION) USERID=${INTL_DB_USR}/${INTL_DB_PWD} SQLCHECK=SYNTAX $(INTL_PROC_OPTION) $(PROCFLG) iname=$*.pc
	$(CC) $(CFLAGS) -c $*.c

clean:;
	rm -f ${PROGRAMS}

clobber:	clean
	rm -f a.out core ERRS make.out *~

Daemon_BT_DM	:	${Batch_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${Batch_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

Daemon_MT_DM	:	${MNT_Dmn_OFILES}
	$(CC) ${LDFLAGS} ${MNT_Dmn_OFILES} ${NON_DCE_LIBS} -o $@

GF_Upload	:	${GF_Upload_OFILES}
	$(CC) ${LDFLAGS} ${GF_Upload_OFILES} ${NON_DCE_LIBS} -o $@
