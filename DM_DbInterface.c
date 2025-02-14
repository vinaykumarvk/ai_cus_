
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "DM_DbInterface.pc"
};


static unsigned int sqlctx = 9672595;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[150];
   unsigned long  sqhstl[150];
            int   sqhsts[150];
            short *sqindv[150];
            int   sqinds[150];
   unsigned long  sqharm[150];
   unsigned long  *sqharc[150];
   unsigned short  sqadto[150];
   unsigned short  sqtdso[150];
} sqlstm = {12,150};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,911,0,3,161,0,0,82,82,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
348,0,0,2,186,0,3,294,0,0,16,16,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,
427,0,0,3,173,0,3,352,0,0,15,15,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,
502,0,0,4,143,0,3,422,0,0,12,12,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
565,0,0,5,313,0,3,520,0,0,29,29,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
696,0,0,6,195,0,3,612,0,0,17,17,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,
779,0,0,7,188,0,3,687,0,0,16,16,0,1,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,
858,0,0,8,83,0,4,737,0,0,2,1,0,1,0,2,3,0,0,1,5,0,0,
881,0,0,9,163,0,3,764,0,0,14,14,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,
952,0,0,10,133,0,3,828,0,0,11,11,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,4,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1011,0,0,11,172,0,3,897,0,0,15,15,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,
0,0,
1086,0,0,12,145,0,3,965,0,0,12,12,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1149,0,0,13,152,0,3,1030,0,0,12,12,0,1,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1212,0,0,14,213,0,3,1105,0,0,18,18,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,
0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1299,0,0,15,331,0,3,1218,0,0,31,31,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1438,0,0,16,188,0,3,1314,0,0,16,16,0,1,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,
1517,0,0,17,157,0,3,1372,0,0,13,13,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1584,0,0,18,170,0,3,1443,0,0,14,14,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1655,0,0,19,236,0,3,1520,0,0,21,21,0,1,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1754,0,0,20,166,0,3,1601,0,0,14,14,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1825,0,0,21,195,0,3,1680,0,0,17,17,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,
1908,0,0,22,155,0,3,1757,0,0,13,13,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1975,0,0,23,146,0,3,1824,0,0,12,12,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2038,0,0,24,152,0,3,1891,0,0,12,12,0,1,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2101,0,0,25,132,0,3,1955,0,0,10,10,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2156,0,0,26,118,0,3,2017,0,0,9,9,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2207,0,0,27,979,0,3,2224,0,0,88,88,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
2574,0,0,28,138,0,3,2366,0,0,11,11,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,
2633,0,0,29,138,0,3,2432,0,0,11,11,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,
2692,0,0,30,158,0,3,2501,0,0,13,13,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2759,0,0,31,205,0,3,2581,0,0,18,18,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2846,0,0,32,140,0,3,2662,0,0,12,12,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2909,0,0,33,1711,0,3,2951,0,0,150,150,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
4,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,4,0,0,
1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,
0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,4,0,0,1,
5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,
3524,0,0,34,161,0,3,3152,0,0,14,14,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,
3595,0,0,35,1337,0,3,3391,0,0,118,118,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,4,0,0,1,3,0,0,1,4,
0,0,1,4,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,5,0,0,
};


#line 1 "DM_DbInterface.pc"
#include <DM_Interface.h>
#include <sqlca.h>
#include <malloc.h>
#include <string.h>
int MT_UpdMT_INSTRUMENT(MT_INSTRUMENT_STRUCT_H *p_mt_instrument_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;
	MT_INSTRUMENT_STRUCT_I *l_mt_instrument_struct_i = (MT_INSTRUMENT_STRUCT_I *)NULL;

	l_mt_instrument_struct_i = (MT_INSTRUMENT_STRUCT_I *)calloc(1,sizeof(MT_INSTRUMENT_STRUCT_I));

	if(!strlen(p_mt_instrument_struct_h ->h_instr_code))
		l_mt_instrument_struct_i -> i_instr_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_currency_cd))
		l_mt_instrument_struct_i -> i_currency_cd= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_location_cd))
		l_mt_instrument_struct_i -> i_location_cd= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_reg_br_ind))
		l_mt_instrument_struct_i -> i_reg_br_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_allow_rf))
		l_mt_instrument_struct_i -> i_allow_rf= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_allow_rvp))
		l_mt_instrument_struct_i -> i_allow_rvp= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_allow_df))
		l_mt_instrument_struct_i -> i_allow_df= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_allow_dvp))
		l_mt_instrument_struct_i -> i_allow_dvp= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_ord_type))
		l_mt_instrument_struct_i -> i_ord_type= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_mother_sec_ind))
		l_mt_instrument_struct_i -> i_mother_sec_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_ex_arena))
		l_mt_instrument_struct_i -> i_ex_arena= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_listed_ind))
		l_mt_instrument_struct_i -> i_listed_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_dateof_input))
		l_mt_instrument_struct_i -> i_dateof_input= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_new_maker))
		l_mt_instrument_struct_i -> i_new_maker= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_maker))
		l_mt_instrument_struct_i -> i_maker= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_maker_dt))
		l_mt_instrument_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_access_stamp))
		l_mt_instrument_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_checker))
		l_mt_instrument_struct_i -> i_checker= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_checker_dt))
		l_mt_instrument_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_status))
		l_mt_instrument_struct_i -> i_status= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_new_issue))
		l_mt_instrument_struct_i -> i_new_issue= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_new_checker))
		l_mt_instrument_struct_i -> i_new_checker= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_chng_lst_ind))
		l_mt_instrument_struct_i -> i_chng_lst_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_cert_of_own_in))
		l_mt_instrument_struct_i -> i_cert_of_own_in= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_name))
		l_mt_instrument_struct_i -> i_instr_name= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_isin))
		l_mt_instrument_struct_i -> i_instr_isin= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_tipo_inv))
		l_mt_instrument_struct_i -> i_tipo_inv= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_type))
		l_mt_instrument_struct_i -> i_instr_type= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_parent))
		l_mt_instrument_struct_i -> i_instr_parent= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_prod_class))
		l_mt_instrument_struct_i -> i_prod_class= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_sec_dl_code))
		l_mt_instrument_struct_i -> i_sec_dl_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_classcd))
		l_mt_instrument_struct_i -> i_classcd= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_new_cd))
		l_mt_instrument_struct_i -> i_new_cd= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_chng_isin))
		l_mt_instrument_struct_i -> i_chng_isin= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_issue_date))
		l_mt_instrument_struct_i -> i_issue_date= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_chg_mkr))
		l_mt_instrument_struct_i -> i_chg_mkr= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_ca_name))
		l_mt_instrument_struct_i -> i_ca_name= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_chng_cd))
		l_mt_instrument_struct_i -> i_chng_cd= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_mature_dt))
		l_mt_instrument_struct_i -> i_mature_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_int_typ))
		l_mt_instrument_struct_i -> i_int_typ= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_freq_code))
		l_mt_instrument_struct_i -> i_freq_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_int_acctyp))
		l_mt_instrument_struct_i -> i_int_acctyp= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_last_pymt_date))
		l_mt_instrument_struct_i -> i_last_pymt_date= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_next_pay_date))
		l_mt_instrument_struct_i -> i_next_pay_date= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_old_lst_paydt))
		l_mt_instrument_struct_i -> i_old_lst_paydt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_mod_last_paydt))
		l_mt_instrument_struct_i -> i_mod_last_paydt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_taxonmat_ind))
		l_mt_instrument_struct_i -> i_taxonmat_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_disct_ind))
		l_mt_instrument_struct_i -> i_disct_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_ca_addrdet))
		l_mt_instrument_struct_i -> i_ca_addrdet= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_lr_setl_date_a))
		l_mt_instrument_struct_i -> i_lr_setl_date_a= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_lr_setl_date_b))
		l_mt_instrument_struct_i -> i_lr_setl_date_b= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_shortnm))
		l_mt_instrument_struct_i -> i_instr_shortnm= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_ipo_ind))
		l_mt_instrument_struct_i -> i_ipo_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_valid_ipo_date))
		l_mt_instrument_struct_i -> i_valid_ipo_date= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_lr_setl_date_c))
		l_mt_instrument_struct_i -> i_lr_setl_date_c= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_cmp_code))
		l_mt_instrument_struct_i -> i_cmp_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_reg_code))
		l_mt_instrument_struct_i -> i_instr_reg_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_swf_name))
		l_mt_instrument_struct_i -> i_instr_swf_name= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_priv_placed))
		l_mt_instrument_struct_i -> i_instr_priv_placed= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_crisil_code))
		l_mt_instrument_struct_i -> i_instr_crisil_code= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_is_secured))
		l_mt_instrument_struct_i -> i_instr_is_secured= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_secured_dt))
		l_mt_instrument_struct_i -> i_instr_secured_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_pc_ind))
		l_mt_instrument_struct_i -> i_instr_pc_ind= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_part_rd_flg))
		l_mt_instrument_struct_i -> i_instr_part_rd_flg= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_reset_flg))
		l_mt_instrument_struct_i -> i_instr_reset_flg= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_exdt_loa))
		l_mt_instrument_struct_i -> i_instr_exdt_loa= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_fst_pymt_dt))
		l_mt_instrument_struct_i -> i_instr_fst_pymt_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_is_demat))
		l_mt_instrument_struct_i -> i_instr_is_demat= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_remark))
		l_mt_instrument_struct_i -> i_instr_remark= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_isin_name))
		l_mt_instrument_struct_i -> i_instr_isin_name= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_attached))
		l_mt_instrument_struct_i -> i_instr_attached= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_detach_dt))
		l_mt_instrument_struct_i -> i_instr_detach_dt= -1;
	if(!strlen(p_mt_instrument_struct_h ->h_instr_sub_type))
		l_mt_instrument_struct_i -> i_instr_sub_type= -1;


	/* EXEC SQL INSERT INTO MT_INSTRUMENT VALUES(:p_mt_instrument_struct_h:l_mt_instrument_struct_i); */ 
#line 161 "DM_DbInterface.pc"

{
#line 161 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 161 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 161 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_INSTRUMENT  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:\
s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s\
23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,\
:s39:s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54\
 ,:s55:s56 ,:s57:s58 ,:s59:s60 ,:s61:s62 ,:s63:s64 ,:s65:s66 ,:s67:s68 ,:s69:s\
70 ,:s71:s72 ,:s73:s74 ,:s75:s76 ,:s77:s78 ,:s79:s80 ,:s81:s82 ,:s83:s84 ,:s85\
:s86 ,:s87:s88 ,:s89:s90 ,:s91:s92 ,:s93:s94 ,:s95:s96 ,:s97:s98 ,:s99:s100 ,:\
s101:s102 ,:s103:s104 ,:s105:s106 ,:s107:s108 ,:s109:s110 ,:s111:s112 ,:s113:s\
114 ,:s115:s116 ,:s117:s118 ,:s119:s120 ,:s121:s122 ,:s123:s124 ,:s125:s126 ,:\
s127:s128 ,:s129:s130 ,:s131:s132 ,:s133:s134 ,:s135:s136 ,:s137:s138 ,:s139:s\
140 ,:s141:s142 ,:s143:s144 ,:s145:s146 ,:s147:s148 ,:s149:s150 ,:s151:s152 ,:\
s153:s154 ,:s155:s156 ,:s157:s158 ,:s159:s160 ,:s161:s162 ,:s163:s164 )";
#line 161 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 161 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )5;
#line 161 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 161 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_instrument_struct_i->i_instr_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_instrument_struct_h->h_currency_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )4;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_instrument_struct_i->i_currency_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_instrument_struct_h->h_location_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )5;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_instrument_struct_i->i_location_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_instrument_struct_h->h_nominal_value;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_instrument_struct_i->i_nominal_value;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_instrument_struct_h->h_reg_br_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )3;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_instrument_struct_i->i_reg_br_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_instrument_struct_h->h_allow_rf;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_instrument_struct_i->i_allow_rf;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_instrument_struct_h->h_allow_rvp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_instrument_struct_i->i_allow_rvp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_instrument_struct_h->h_allow_df;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_instrument_struct_i->i_allow_df;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_instrument_struct_h->h_allow_dvp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_instrument_struct_i->i_allow_dvp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_instrument_struct_h->h_ord_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_instrument_struct_i->i_ord_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_instrument_struct_h->h_mother_sec_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_instrument_struct_i->i_mother_sec_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_instrument_struct_h->h_ex_arena;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_instrument_struct_i->i_ex_arena;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_instrument_struct_h->h_listed_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_instrument_struct_i->i_listed_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_instrument_struct_h->h_dateof_input;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_instrument_struct_i->i_dateof_input;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)&p_mt_instrument_struct_h->h_threshold_qty;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_instrument_struct_i->i_threshold_qty;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_instrument_struct_h->h_new_maker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )15;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_instrument_struct_i->i_new_maker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_instrument_struct_h->h_maker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )15;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_instrument_struct_i->i_maker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_mt_instrument_struct_h->h_maker_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_instrument_struct_i->i_maker_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)p_mt_instrument_struct_h->h_access_stamp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_mt_instrument_struct_i->i_access_stamp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)p_mt_instrument_struct_h->h_checker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )15;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_mt_instrument_struct_i->i_checker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)p_mt_instrument_struct_h->h_checker_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_mt_instrument_struct_i->i_checker_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[21] = (unsigned char  *)&p_mt_instrument_struct_h->h_total_pdcapita;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[21] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[21] = (         short *)&l_mt_instrument_struct_i->i_total_pdcapita;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[21] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[21] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[21] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[21] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[22] = (unsigned char  *)p_mt_instrument_struct_h->h_status;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[22] = (unsigned long )3;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[22] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[22] = (         short *)&l_mt_instrument_struct_i->i_status;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[22] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[22] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[22] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[22] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[23] = (unsigned char  *)p_mt_instrument_struct_h->h_new_issue;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[23] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[23] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[23] = (         short *)&l_mt_instrument_struct_i->i_new_issue;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[23] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[23] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[23] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[23] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[24] = (unsigned char  *)p_mt_instrument_struct_h->h_new_checker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[24] = (unsigned long )15;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[24] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[24] = (         short *)&l_mt_instrument_struct_i->i_new_checker;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[24] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[24] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[24] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[24] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[25] = (unsigned char  *)p_mt_instrument_struct_h->h_chng_lst_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[25] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[25] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[25] = (         short *)&l_mt_instrument_struct_i->i_chng_lst_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[25] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[25] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[25] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[25] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[26] = (unsigned char  *)p_mt_instrument_struct_h->h_cert_of_own_in;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[26] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[26] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[26] = (         short *)&l_mt_instrument_struct_i->i_cert_of_own_in;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[26] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[26] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[26] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[26] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[27] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[27] = (unsigned long )131;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[27] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[27] = (         short *)&l_mt_instrument_struct_i->i_instr_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[27] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[27] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[27] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[27] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[28] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_isin;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[28] = (unsigned long )13;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[28] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[28] = (         short *)&l_mt_instrument_struct_i->i_instr_isin;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[28] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[28] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[28] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[28] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[29] = (unsigned char  *)p_mt_instrument_struct_h->h_tipo_inv;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[29] = (unsigned long )3;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[29] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[29] = (         short *)&l_mt_instrument_struct_i->i_tipo_inv;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[29] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[29] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[29] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[29] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[30] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[30] = (unsigned long )4;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[30] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[30] = (         short *)&l_mt_instrument_struct_i->i_instr_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[30] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[30] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[30] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[30] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[31] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_parent;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[31] = (unsigned long )9;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[31] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[31] = (         short *)&l_mt_instrument_struct_i->i_instr_parent;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[31] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[31] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[31] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[31] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[32] = (unsigned char  *)p_mt_instrument_struct_h->h_prod_class;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[32] = (unsigned long )3;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[32] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[32] = (         short *)&l_mt_instrument_struct_i->i_prod_class;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[32] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[32] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[32] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[32] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[33] = (unsigned char  *)p_mt_instrument_struct_h->h_sec_dl_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[33] = (unsigned long )4;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[33] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[33] = (         short *)&l_mt_instrument_struct_i->i_sec_dl_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[33] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[33] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[33] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[33] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[34] = (unsigned char  *)p_mt_instrument_struct_h->h_classcd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[34] = (unsigned long )5;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[34] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[34] = (         short *)&l_mt_instrument_struct_i->i_classcd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[34] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[34] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[34] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[34] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[35] = (unsigned char  *)p_mt_instrument_struct_h->h_new_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[35] = (unsigned long )9;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[35] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[35] = (         short *)&l_mt_instrument_struct_i->i_new_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[35] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[35] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[35] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[35] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[36] = (unsigned char  *)p_mt_instrument_struct_h->h_chng_isin;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[36] = (unsigned long )13;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[36] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[36] = (         short *)&l_mt_instrument_struct_i->i_chng_isin;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[36] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[36] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[36] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[36] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[37] = (unsigned char  *)p_mt_instrument_struct_h->h_issue_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[37] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[37] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[37] = (         short *)&l_mt_instrument_struct_i->i_issue_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[37] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[37] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[37] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[37] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[38] = (unsigned char  *)p_mt_instrument_struct_h->h_chg_mkr;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[38] = (unsigned long )15;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[38] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[38] = (         short *)&l_mt_instrument_struct_i->i_chg_mkr;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[38] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[38] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[38] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[38] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[39] = (unsigned char  *)p_mt_instrument_struct_h->h_ca_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[39] = (unsigned long )61;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[39] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[39] = (         short *)&l_mt_instrument_struct_i->i_ca_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[39] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[39] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[39] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[39] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[40] = (unsigned char  *)p_mt_instrument_struct_h->h_chng_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[40] = (unsigned long )9;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[40] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[40] = (         short *)&l_mt_instrument_struct_i->i_chng_cd;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[40] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[40] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[40] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[40] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[41] = (unsigned char  *)p_mt_instrument_struct_h->h_mature_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[41] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[41] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[41] = (         short *)&l_mt_instrument_struct_i->i_mature_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[41] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[41] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[41] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[41] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[42] = (unsigned char  *)p_mt_instrument_struct_h->h_int_typ;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[42] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[42] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[42] = (         short *)&l_mt_instrument_struct_i->i_int_typ;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[42] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[42] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[42] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[42] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[43] = (unsigned char  *)&p_mt_instrument_struct_h->h_instr_int_rate;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[43] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[43] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[43] = (         short *)&l_mt_instrument_struct_i->i_instr_int_rate;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[43] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[43] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[43] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[43] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[44] = (unsigned char  *)p_mt_instrument_struct_h->h_freq_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[44] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[44] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[44] = (         short *)&l_mt_instrument_struct_i->i_freq_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[44] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[44] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[44] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[44] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[45] = (unsigned char  *)p_mt_instrument_struct_h->h_int_acctyp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[45] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[45] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[45] = (         short *)&l_mt_instrument_struct_i->i_int_acctyp;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[45] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[45] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[45] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[45] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[46] = (unsigned char  *)p_mt_instrument_struct_h->h_last_pymt_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[46] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[46] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[46] = (         short *)&l_mt_instrument_struct_i->i_last_pymt_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[46] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[46] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[46] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[46] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[47] = (unsigned char  *)&p_mt_instrument_struct_h->h_last_incom_rt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[47] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[47] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[47] = (         short *)&l_mt_instrument_struct_i->i_last_incom_rt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[47] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[47] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[47] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[47] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[48] = (unsigned char  *)p_mt_instrument_struct_h->h_next_pay_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[48] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[48] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[48] = (         short *)&l_mt_instrument_struct_i->i_next_pay_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[48] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[48] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[48] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[48] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[49] = (unsigned char  *)p_mt_instrument_struct_h->h_old_lst_paydt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[49] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[49] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[49] = (         short *)&l_mt_instrument_struct_i->i_old_lst_paydt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[49] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[49] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[49] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[49] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[50] = (unsigned char  *)p_mt_instrument_struct_h->h_mod_last_paydt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[50] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[50] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[50] = (         short *)&l_mt_instrument_struct_i->i_mod_last_paydt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[50] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[50] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[50] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[50] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[51] = (unsigned char  *)p_mt_instrument_struct_h->h_taxonmat_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[51] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[51] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[51] = (         short *)&l_mt_instrument_struct_i->i_taxonmat_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[51] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[51] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[51] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[51] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[52] = (unsigned char  *)p_mt_instrument_struct_h->h_disct_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[52] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[52] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[52] = (         short *)&l_mt_instrument_struct_i->i_disct_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[52] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[52] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[52] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[52] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[53] = (unsigned char  *)p_mt_instrument_struct_h->h_ca_addrdet;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[53] = (unsigned long )181;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[53] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[53] = (         short *)&l_mt_instrument_struct_i->i_ca_addrdet;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[53] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[53] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[53] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[53] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[54] = (unsigned char  *)&p_mt_instrument_struct_h->h_min_fmt_dl_qty;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[54] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[54] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[54] = (         short *)&l_mt_instrument_struct_i->i_min_fmt_dl_qty;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[54] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[54] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[54] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[54] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[55] = (unsigned char  *)p_mt_instrument_struct_h->h_lr_setl_date_a;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[55] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[55] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[55] = (         short *)&l_mt_instrument_struct_i->i_lr_setl_date_a;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[55] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[55] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[55] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[55] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[56] = (unsigned char  *)p_mt_instrument_struct_h->h_lr_setl_date_b;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[56] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[56] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[56] = (         short *)&l_mt_instrument_struct_i->i_lr_setl_date_b;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[56] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[56] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[56] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[56] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[57] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_shortnm;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[57] = (unsigned long )16;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[57] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[57] = (         short *)&l_mt_instrument_struct_i->i_instr_shortnm;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[57] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[57] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[57] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[57] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[58] = (unsigned char  *)p_mt_instrument_struct_h->h_ipo_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[58] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[58] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[58] = (         short *)&l_mt_instrument_struct_i->i_ipo_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[58] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[58] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[58] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[58] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[59] = (unsigned char  *)p_mt_instrument_struct_h->h_valid_ipo_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[59] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[59] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[59] = (         short *)&l_mt_instrument_struct_i->i_valid_ipo_date;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[59] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[59] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[59] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[59] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[60] = (unsigned char  *)p_mt_instrument_struct_h->h_lr_setl_date_c;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[60] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[60] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[60] = (         short *)&l_mt_instrument_struct_i->i_lr_setl_date_c;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[60] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[60] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[60] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[60] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[61] = (unsigned char  *)p_mt_instrument_struct_h->h_cmp_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[61] = (unsigned long )11;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[61] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[61] = (         short *)&l_mt_instrument_struct_i->i_cmp_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[61] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[61] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[61] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[61] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[62] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_reg_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[62] = (unsigned long )11;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[62] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[62] = (         short *)&l_mt_instrument_struct_i->i_instr_reg_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[62] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[62] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[62] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[62] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[63] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_swf_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[63] = (unsigned long )21;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[63] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[63] = (         short *)&l_mt_instrument_struct_i->i_instr_swf_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[63] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[63] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[63] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[63] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[64] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_priv_placed;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[64] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[64] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[64] = (         short *)&l_mt_instrument_struct_i->i_instr_priv_placed;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[64] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[64] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[64] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[64] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[65] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_crisil_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[65] = (unsigned long )7;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[65] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[65] = (         short *)&l_mt_instrument_struct_i->i_instr_crisil_code;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[65] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[65] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[65] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[65] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[66] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_is_secured;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[66] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[66] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[66] = (         short *)&l_mt_instrument_struct_i->i_instr_is_secured;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[66] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[66] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[66] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[66] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[67] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_secured_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[67] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[67] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[67] = (         short *)&l_mt_instrument_struct_i->i_instr_secured_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[67] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[67] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[67] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[67] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[68] = (unsigned char  *)&p_mt_instrument_struct_h->h_instr_tot_nom_val;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[68] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[68] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[68] = (         short *)&l_mt_instrument_struct_i->i_instr_tot_nom_val;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[68] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[68] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[68] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[68] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[69] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_pc_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[69] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[69] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[69] = (         short *)&l_mt_instrument_struct_i->i_instr_pc_ind;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[69] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[69] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[69] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[69] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[70] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_part_rd_flg;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[70] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[70] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[70] = (         short *)&l_mt_instrument_struct_i->i_instr_part_rd_flg;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[70] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[70] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[70] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[70] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[71] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_reset_flg;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[71] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[71] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[71] = (         short *)&l_mt_instrument_struct_i->i_instr_reset_flg;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[71] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[71] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[71] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[71] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[72] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_exdt_loa;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[72] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[72] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[72] = (         short *)&l_mt_instrument_struct_i->i_instr_exdt_loa;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[72] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[72] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[72] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[72] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[73] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_fst_pymt_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[73] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[73] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[73] = (         short *)&l_mt_instrument_struct_i->i_instr_fst_pymt_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[73] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[73] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[73] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[73] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[74] = (unsigned char  *)&p_mt_instrument_struct_h->h_instr_div_rate;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[74] = (unsigned long )sizeof(double);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[74] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[74] = (         short *)&l_mt_instrument_struct_i->i_instr_div_rate;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[74] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[74] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[74] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[74] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[75] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_is_demat;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[75] = (unsigned long )2;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[75] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[75] = (         short *)&l_mt_instrument_struct_i->i_instr_is_demat;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[75] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[75] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[75] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[75] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[76] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_remark;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[76] = (unsigned long )101;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[76] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[76] = (         short *)&l_mt_instrument_struct_i->i_instr_remark;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[76] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[76] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[76] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[76] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[77] = (unsigned char  *)&p_mt_instrument_struct_h->h_instrshut_period;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[77] = (unsigned long )sizeof(int);
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[77] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[77] = (         short *)&l_mt_instrument_struct_i->i_instrshut_period;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[77] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[77] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[77] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[77] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[78] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_isin_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[78] = (unsigned long )51;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[78] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[78] = (         short *)&l_mt_instrument_struct_i->i_instr_isin_name;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[78] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[78] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[78] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[78] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[79] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_attached;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[79] = (unsigned long )9;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[79] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[79] = (         short *)&l_mt_instrument_struct_i->i_instr_attached;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[79] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[79] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[79] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[79] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[80] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_detach_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[80] = (unsigned long )20;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[80] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[80] = (         short *)&l_mt_instrument_struct_i->i_instr_detach_dt;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[80] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[80] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[80] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[80] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstv[81] = (unsigned char  *)p_mt_instrument_struct_h->h_instr_sub_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhstl[81] = (unsigned long )4;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqhsts[81] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqindv[81] = (         short *)&l_mt_instrument_struct_i->i_instr_sub_type;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqinds[81] = (         int  )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqharm[81] = (unsigned long )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqadto[81] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqtdso[81] = (unsigned short )0;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 161 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 161 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 161 "DM_DbInterface.pc"
}

#line 161 "DM_DbInterface.pc"


	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_instrument_struct_h -> h_instr_code,l_mt_instrument_struct_i -> i_instr_code,strlen(p_mt_instrument_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CURRENCY_CD",p_mt_instrument_struct_h -> h_currency_cd,l_mt_instrument_struct_i -> i_currency_cd,strlen(p_mt_instrument_struct_h -> h_currency_cd),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LOCATION_CD",p_mt_instrument_struct_h -> h_location_cd,l_mt_instrument_struct_i -> i_location_cd,strlen(p_mt_instrument_struct_h -> h_location_cd),4);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","NOMINAL_VALUE",p_mt_instrument_struct_h -> h_nominal_value,l_mt_instrument_struct_i -> i_nominal_value);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REG_BR_IND",p_mt_instrument_struct_h -> h_reg_br_ind,l_mt_instrument_struct_i -> i_reg_br_ind,strlen(p_mt_instrument_struct_h -> h_reg_br_ind),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ALLOW_RF",p_mt_instrument_struct_h -> h_allow_rf,l_mt_instrument_struct_i -> i_allow_rf,strlen(p_mt_instrument_struct_h -> h_allow_rf),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ALLOW_RVP",p_mt_instrument_struct_h -> h_allow_rvp,l_mt_instrument_struct_i -> i_allow_rvp,strlen(p_mt_instrument_struct_h -> h_allow_rvp),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ALLOW_DF",p_mt_instrument_struct_h -> h_allow_df,l_mt_instrument_struct_i -> i_allow_df,strlen(p_mt_instrument_struct_h -> h_allow_df),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ALLOW_DVP",p_mt_instrument_struct_h -> h_allow_dvp,l_mt_instrument_struct_i -> i_allow_dvp,strlen(p_mt_instrument_struct_h -> h_allow_dvp),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ORD_TYPE",p_mt_instrument_struct_h -> h_ord_type,l_mt_instrument_struct_i -> i_ord_type,strlen(p_mt_instrument_struct_h -> h_ord_type),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MOTHER_SEC_IND",p_mt_instrument_struct_h -> h_mother_sec_ind,l_mt_instrument_struct_i -> i_mother_sec_ind,strlen(p_mt_instrument_struct_h -> h_mother_sec_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EX_ARENA",p_mt_instrument_struct_h -> h_ex_arena,l_mt_instrument_struct_i -> i_ex_arena,strlen(p_mt_instrument_struct_h -> h_ex_arena),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LISTED_IND",p_mt_instrument_struct_h -> h_listed_ind,l_mt_instrument_struct_i -> i_listed_ind,strlen(p_mt_instrument_struct_h -> h_listed_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEOF_INPUT",p_mt_instrument_struct_h -> h_dateof_input,l_mt_instrument_struct_i -> i_dateof_input);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","THRESHOLD_QTY",p_mt_instrument_struct_h -> h_threshold_qty,l_mt_instrument_struct_i -> i_threshold_qty);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NEW_MAKER",p_mt_instrument_struct_h -> h_new_maker,l_mt_instrument_struct_i -> i_new_maker,strlen(p_mt_instrument_struct_h -> h_new_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_instrument_struct_h -> h_maker,l_mt_instrument_struct_i -> i_maker,strlen(p_mt_instrument_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_instrument_struct_h -> h_maker_dt,l_mt_instrument_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_instrument_struct_h -> h_access_stamp,l_mt_instrument_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_instrument_struct_h -> h_checker,l_mt_instrument_struct_i -> i_checker,strlen(p_mt_instrument_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_instrument_struct_h -> h_checker_dt,l_mt_instrument_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","TOTAL_PDCAPITA",p_mt_instrument_struct_h -> h_total_pdcapita,l_mt_instrument_struct_i -> i_total_pdcapita);printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_instrument_struct_h -> h_status,l_mt_instrument_struct_i -> i_status,strlen(p_mt_instrument_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NEW_ISSUE",p_mt_instrument_struct_h -> h_new_issue,l_mt_instrument_struct_i -> i_new_issue,strlen(p_mt_instrument_struct_h -> h_new_issue),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NEW_CHECKER",p_mt_instrument_struct_h -> h_new_checker,l_mt_instrument_struct_i -> i_new_checker,strlen(p_mt_instrument_struct_h -> h_new_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHNG_LST_IND",p_mt_instrument_struct_h -> h_chng_lst_ind,l_mt_instrument_struct_i -> i_chng_lst_ind,strlen(p_mt_instrument_struct_h -> h_chng_lst_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CERT_OF_OWN_IN",p_mt_instrument_struct_h -> h_cert_of_own_in,l_mt_instrument_struct_i -> i_cert_of_own_in,strlen(p_mt_instrument_struct_h -> h_cert_of_own_in),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_NAME",p_mt_instrument_struct_h -> h_instr_name,l_mt_instrument_struct_i -> i_instr_name,strlen(p_mt_instrument_struct_h -> h_instr_name),130);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_ISIN",p_mt_instrument_struct_h -> h_instr_isin,l_mt_instrument_struct_i -> i_instr_isin,strlen(p_mt_instrument_struct_h -> h_instr_isin),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","TIPO_INV",p_mt_instrument_struct_h -> h_tipo_inv,l_mt_instrument_struct_i -> i_tipo_inv,strlen(p_mt_instrument_struct_h -> h_tipo_inv),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_TYPE",p_mt_instrument_struct_h -> h_instr_type,l_mt_instrument_struct_i -> i_instr_type,strlen(p_mt_instrument_struct_h -> h_instr_type),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_PARENT",p_mt_instrument_struct_h -> h_instr_parent,l_mt_instrument_struct_i -> i_instr_parent,strlen(p_mt_instrument_struct_h -> h_instr_parent),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PROD_CLASS",p_mt_instrument_struct_h -> h_prod_class,l_mt_instrument_struct_i -> i_prod_class,strlen(p_mt_instrument_struct_h -> h_prod_class),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SEC_DL_CODE",p_mt_instrument_struct_h -> h_sec_dl_code,l_mt_instrument_struct_i -> i_sec_dl_code,strlen(p_mt_instrument_struct_h -> h_sec_dl_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLASSCD",p_mt_instrument_struct_h -> h_classcd,l_mt_instrument_struct_i -> i_classcd,strlen(p_mt_instrument_struct_h -> h_classcd),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NEW_CD",p_mt_instrument_struct_h -> h_new_cd,l_mt_instrument_struct_i -> i_new_cd,strlen(p_mt_instrument_struct_h -> h_new_cd),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHNG_ISIN",p_mt_instrument_struct_h -> h_chng_isin,l_mt_instrument_struct_i -> i_chng_isin,strlen(p_mt_instrument_struct_h -> h_chng_isin),12);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ISSUE_DATE",p_mt_instrument_struct_h -> h_issue_date,l_mt_instrument_struct_i -> i_issue_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHG_MKR",p_mt_instrument_struct_h -> h_chg_mkr,l_mt_instrument_struct_i -> i_chg_mkr,strlen(p_mt_instrument_struct_h -> h_chg_mkr),14);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CA_NAME",p_mt_instrument_struct_h -> h_ca_name,l_mt_instrument_struct_i -> i_ca_name,strlen(p_mt_instrument_struct_h -> h_ca_name),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHNG_CD",p_mt_instrument_struct_h -> h_chng_cd,l_mt_instrument_struct_i -> i_chng_cd,strlen(p_mt_instrument_struct_h -> h_chng_cd),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MATURE_DT",p_mt_instrument_struct_h -> h_mature_dt,l_mt_instrument_struct_i -> i_mature_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INT_TYP",p_mt_instrument_struct_h -> h_int_typ,l_mt_instrument_struct_i -> i_int_typ,strlen(p_mt_instrument_struct_h -> h_int_typ),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","INSTR_INT_RATE",p_mt_instrument_struct_h -> h_instr_int_rate,l_mt_instrument_struct_i -> i_instr_int_rate);printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FREQ_CODE",p_mt_instrument_struct_h -> h_freq_code,l_mt_instrument_struct_i -> i_freq_code,strlen(p_mt_instrument_struct_h -> h_freq_code),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INT_ACCTYP",p_mt_instrument_struct_h -> h_int_acctyp,l_mt_instrument_struct_i -> i_int_acctyp,strlen(p_mt_instrument_struct_h -> h_int_acctyp),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LAST_PYMT_DATE",p_mt_instrument_struct_h -> h_last_pymt_date,l_mt_instrument_struct_i -> i_last_pymt_date);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","LAST_INCOM_RT",p_mt_instrument_struct_h -> h_last_incom_rt,l_mt_instrument_struct_i -> i_last_incom_rt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NEXT_PAY_DATE",p_mt_instrument_struct_h -> h_next_pay_date,l_mt_instrument_struct_i -> i_next_pay_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","OLD_LST_PAYDT",p_mt_instrument_struct_h -> h_old_lst_paydt,l_mt_instrument_struct_i -> i_old_lst_paydt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MOD_LAST_PAYDT",p_mt_instrument_struct_h -> h_mod_last_paydt,l_mt_instrument_struct_i -> i_mod_last_paydt,strlen(p_mt_instrument_struct_h -> h_mod_last_paydt),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","TAXONMAT_IND",p_mt_instrument_struct_h -> h_taxonmat_ind,l_mt_instrument_struct_i -> i_taxonmat_ind,strlen(p_mt_instrument_struct_h -> h_taxonmat_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DISCT_IND",p_mt_instrument_struct_h -> h_disct_ind,l_mt_instrument_struct_i -> i_disct_ind,strlen(p_mt_instrument_struct_h -> h_disct_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CA_ADDRDET",p_mt_instrument_struct_h -> h_ca_addrdet,l_mt_instrument_struct_i -> i_ca_addrdet,strlen(p_mt_instrument_struct_h -> h_ca_addrdet),180);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","MIN_FMT_DL_QTY",p_mt_instrument_struct_h -> h_min_fmt_dl_qty,l_mt_instrument_struct_i -> i_min_fmt_dl_qty);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_SETL_DATE_A",p_mt_instrument_struct_h -> h_lr_setl_date_a,l_mt_instrument_struct_i -> i_lr_setl_date_a);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_SETL_DATE_B",p_mt_instrument_struct_h -> h_lr_setl_date_b,l_mt_instrument_struct_i -> i_lr_setl_date_b);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_SHORTNM",p_mt_instrument_struct_h -> h_instr_shortnm,l_mt_instrument_struct_i -> i_instr_shortnm,strlen(p_mt_instrument_struct_h -> h_instr_shortnm),15);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","IPO_IND",p_mt_instrument_struct_h -> h_ipo_ind,l_mt_instrument_struct_i -> i_ipo_ind,strlen(p_mt_instrument_struct_h -> h_ipo_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","VALID_IPO_DATE",p_mt_instrument_struct_h -> h_valid_ipo_date,l_mt_instrument_struct_i -> i_valid_ipo_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_SETL_DATE_C",p_mt_instrument_struct_h -> h_lr_setl_date_c,l_mt_instrument_struct_i -> i_lr_setl_date_c);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_CODE",p_mt_instrument_struct_h -> h_cmp_code,l_mt_instrument_struct_i -> i_cmp_code,strlen(p_mt_instrument_struct_h -> h_cmp_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_REG_CODE",p_mt_instrument_struct_h -> h_instr_reg_code,l_mt_instrument_struct_i -> i_instr_reg_code,strlen(p_mt_instrument_struct_h -> h_instr_reg_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_SWF_NAME",p_mt_instrument_struct_h -> h_instr_swf_name,l_mt_instrument_struct_i -> i_instr_swf_name,strlen(p_mt_instrument_struct_h -> h_instr_swf_name),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_PRIV_PLACED",p_mt_instrument_struct_h -> h_instr_priv_placed,l_mt_instrument_struct_i -> i_instr_priv_placed,strlen(p_mt_instrument_struct_h -> h_instr_priv_placed),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CRISIL_CODE",p_mt_instrument_struct_h -> h_instr_crisil_code,l_mt_instrument_struct_i -> i_instr_crisil_code,strlen(p_mt_instrument_struct_h -> h_instr_crisil_code),6);printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_IS_SECURED",p_mt_instrument_struct_h -> h_instr_is_secured,l_mt_instrument_struct_i -> i_instr_is_secured,strlen(p_mt_instrument_struct_h -> h_instr_is_secured),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_SECURED_DT",p_mt_instrument_struct_h -> h_instr_secured_dt,l_mt_instrument_struct_i -> i_instr_secured_dt);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","INSTR_TOT_NOM_VAL",p_mt_instrument_struct_h -> h_instr_tot_nom_val,l_mt_instrument_struct_i -> i_instr_tot_nom_val);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_PC_IND",p_mt_instrument_struct_h -> h_instr_pc_ind,l_mt_instrument_struct_i -> i_instr_pc_ind,strlen(p_mt_instrument_struct_h -> h_instr_pc_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_PART_RD_FLG",p_mt_instrument_struct_h -> h_instr_part_rd_flg,l_mt_instrument_struct_i -> i_instr_part_rd_flg,strlen(p_mt_instrument_struct_h -> h_instr_part_rd_flg),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_RESET_FLG",p_mt_instrument_struct_h -> h_instr_reset_flg,l_mt_instrument_struct_i -> i_instr_reset_flg,strlen(p_mt_instrument_struct_h -> h_instr_reset_flg),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_EXDT_LOA",p_mt_instrument_struct_h -> h_instr_exdt_loa,l_mt_instrument_struct_i -> i_instr_exdt_loa);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_FST_PYMT_DT",p_mt_instrument_struct_h -> h_instr_fst_pymt_dt,l_mt_instrument_struct_i -> i_instr_fst_pymt_dt);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","INSTR_DIV_RATE",p_mt_instrument_struct_h -> h_instr_div_rate,l_mt_instrument_struct_i -> i_instr_div_rate);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_IS_DEMAT",p_mt_instrument_struct_h -> h_instr_is_demat,l_mt_instrument_struct_i -> i_instr_is_demat,strlen(p_mt_instrument_struct_h -> h_instr_is_demat),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_REMARK",p_mt_instrument_struct_h -> h_instr_remark,l_mt_instrument_struct_i -> i_instr_remark,strlen(p_mt_instrument_struct_h -> h_instr_remark),100);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTRSHUT_PERIOD",p_mt_instrument_struct_h -> h_instrshut_period,l_mt_instrument_struct_i -> i_instrshut_period);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_ISIN_NAME",p_mt_instrument_struct_h -> h_instr_isin_name,l_mt_instrument_struct_i -> i_instr_isin_name,strlen(p_mt_instrument_struct_h -> h_instr_isin_name),50);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_ATTACHED",p_mt_instrument_struct_h -> h_instr_attached,l_mt_instrument_struct_i -> i_instr_attached,strlen(p_mt_instrument_struct_h -> h_instr_attached),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_DETACH_DT",p_mt_instrument_struct_h -> h_instr_detach_dt,l_mt_instrument_struct_i -> i_instr_detach_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_SUB_TYPE",p_mt_instrument_struct_h -> h_instr_sub_type,l_mt_instrument_struct_i -> i_instr_sub_type,strlen(p_mt_instrument_struct_h -> h_instr_sub_type),3);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:
	APL_FREE(l_mt_instrument_struct_i);
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:
	APL_FREE(l_mt_instrument_struct_i);
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
}
//ADD BY ASP, FOR MT_REGDETAILS, 01sep
int MT_UpdMT_REGDETAILS(MT_REGDETAILS_STRUCT_H *p_mt_regdetails_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
     struct sqlca sqlca;
     MT_REGDETAILS_STRUCT_I *l_mt_regdetails_struct_i = (MT_REGDETAILS_STRUCT_I *)NULL;
     
     l_mt_regdetails_struct_i = (MT_REGDETAILS_STRUCT_I *)calloc(1,sizeof(MT_REGDETAILS_STRUCT_I));
     
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_code))
        l_mt_regdetails_struct_i -> i_cln_code= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_sebi_reg_no))
        l_mt_regdetails_struct_i -> i_cln_sebi_reg_no= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_sebi_reg_dt))
        l_mt_regdetails_struct_i -> i_cln_sebi_reg_dt= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_sebi_reg_expdt))
        l_mt_regdetails_struct_i -> i_cln_sebi_reg_expdt= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_rbi_reg_no))
        l_mt_regdetails_struct_i -> i_cln_rbi_reg_no= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_rbi_reg_dt))
        l_mt_regdetails_struct_i -> i_cln_rbi_reg_dt= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_rbi_expdt))
        l_mt_regdetails_struct_i -> i_cln_rbi_expdt= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_mapinid))
        l_mt_regdetails_struct_i -> i_cln_mapinid= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_cln_ucc_code))
        l_mt_regdetails_struct_i -> i_cln_ucc_code= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_access_stamp))
        l_mt_regdetails_struct_i -> i_access_stamp= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_maker))
        l_mt_regdetails_struct_i -> i_maker= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_maker_dt))
        l_mt_regdetails_struct_i -> i_maker_dt= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_checker))
        l_mt_regdetails_struct_i -> i_checker= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_checker_dt))
        l_mt_regdetails_struct_i -> i_checker_dt= -1; 
     if(!strlen(p_mt_regdetails_struct_h -> h_status))
        l_mt_regdetails_struct_i -> i_status= -1;
     if(!strlen(p_mt_regdetails_struct_h -> h_sebi_sub_acc))
        l_mt_regdetails_struct_i -> i_sebi_sub_acc= -1;

     /* EXEC SQL INSERT INTO MT_REGDETAILS VALUES(:p_mt_regdetails_struct_h:l_mt_regdetails_struct_i); */ 
#line 294 "DM_DbInterface.pc"

{
#line 294 "DM_DbInterface.pc"
     struct sqlexd sqlstm;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqlvsn = 12;
#line 294 "DM_DbInterface.pc"
     sqlstm.arrsiz = 82;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqladtp = &sqladt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqltdsp = &sqltds;
#line 294 "DM_DbInterface.pc"
     sqlstm.stmt = "insert into MT_REGDETAILS  values (:s1:s2 ,:s3:s4 ,:s5:s\
6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22\
 ,:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 )";
#line 294 "DM_DbInterface.pc"
     sqlstm.iters = (unsigned int  )1;
#line 294 "DM_DbInterface.pc"
     sqlstm.offset = (unsigned int  )348;
#line 294 "DM_DbInterface.pc"
     sqlstm.cud = sqlcud0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqlety = (unsigned short)256;
#line 294 "DM_DbInterface.pc"
     sqlstm.occurs = (unsigned int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[0] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_code;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[0] = (unsigned long )11;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[0] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[0] = (         short *)&l_mt_regdetails_struct_i->i_cln_code;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[0] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[0] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[0] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[0] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[1] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_sebi_reg_no;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[1] = (unsigned long )21;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[1] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[1] = (         short *)&l_mt_regdetails_struct_i->i_cln_sebi_reg_no;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[1] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[1] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[1] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[1] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[2] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_sebi_reg_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[2] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[2] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[2] = (         short *)&l_mt_regdetails_struct_i->i_cln_sebi_reg_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[2] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[2] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[2] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[2] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[3] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_sebi_reg_expdt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[3] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[3] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[3] = (         short *)&l_mt_regdetails_struct_i->i_cln_sebi_reg_expdt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[3] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[3] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[3] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[3] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[4] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_rbi_reg_no;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[4] = (unsigned long )21;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[4] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[4] = (         short *)&l_mt_regdetails_struct_i->i_cln_rbi_reg_no;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[4] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[4] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[4] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[4] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[5] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_rbi_reg_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[5] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[5] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[5] = (         short *)&l_mt_regdetails_struct_i->i_cln_rbi_reg_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[5] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[5] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[5] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[5] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[6] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_rbi_expdt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[6] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[6] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[6] = (         short *)&l_mt_regdetails_struct_i->i_cln_rbi_expdt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[6] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[6] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[6] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[6] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[7] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_mapinid;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[7] = (unsigned long )13;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[7] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[7] = (         short *)&l_mt_regdetails_struct_i->i_cln_mapinid;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[7] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[7] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[7] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[7] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[8] = (unsigned char  *)p_mt_regdetails_struct_h->h_cln_ucc_code;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[8] = (unsigned long )13;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[8] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[8] = (         short *)&l_mt_regdetails_struct_i->i_cln_ucc_code;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[8] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[8] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[8] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[8] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[9] = (unsigned char  *)p_mt_regdetails_struct_h->h_access_stamp;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[9] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[9] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[9] = (         short *)&l_mt_regdetails_struct_i->i_access_stamp;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[9] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[9] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[9] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[9] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[10] = (unsigned char  *)p_mt_regdetails_struct_h->h_maker;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[10] = (unsigned long )15;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[10] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[10] = (         short *)&l_mt_regdetails_struct_i->i_maker;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[10] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[10] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[10] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[10] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[11] = (unsigned char  *)p_mt_regdetails_struct_h->h_maker_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[11] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[11] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[11] = (         short *)&l_mt_regdetails_struct_i->i_maker_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[11] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[11] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[11] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[11] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[12] = (unsigned char  *)p_mt_regdetails_struct_h->h_checker;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[12] = (unsigned long )15;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[12] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[12] = (         short *)&l_mt_regdetails_struct_i->i_checker;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[12] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[12] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[12] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[12] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[13] = (unsigned char  *)p_mt_regdetails_struct_h->h_checker_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[13] = (unsigned long )20;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[13] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[13] = (         short *)&l_mt_regdetails_struct_i->i_checker_dt;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[13] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[13] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[13] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[13] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[14] = (unsigned char  *)p_mt_regdetails_struct_h->h_status;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[14] = (unsigned long )3;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[14] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[14] = (         short *)&l_mt_regdetails_struct_i->i_status;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[14] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[14] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[14] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[14] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstv[15] = (unsigned char  *)p_mt_regdetails_struct_h->h_sebi_sub_acc;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhstl[15] = (unsigned long )8;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqhsts[15] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqindv[15] = (         short *)&l_mt_regdetails_struct_i->i_sebi_sub_acc;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqinds[15] = (         int  )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqharm[15] = (unsigned long )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqadto[15] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqtdso[15] = (unsigned short )0;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqphsv = sqlstm.sqhstv;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqphsl = sqlstm.sqhstl;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqphss = sqlstm.sqhsts;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqpind = sqlstm.sqindv;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqpins = sqlstm.sqinds;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqparm = sqlstm.sqharm;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqparc = sqlstm.sqharc;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqpadto = sqlstm.sqadto;
#line 294 "DM_DbInterface.pc"
     sqlstm.sqptdso = sqlstm.sqtdso;
#line 294 "DM_DbInterface.pc"
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 294 "DM_DbInterface.pc"
}

#line 294 "DM_DbInterface.pc"


   IS_ANY_ORA_ERROR
      RETURN_SUCCESS:

      APL_FREE(l_mt_regdetails_struct_i);

   APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

      RETURN_FAILURE:

      APL_FREE(l_mt_regdetails_struct_i);

   APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
}
int MT_UpdMT_HOLIDAY(MT_HOLIDAY_STRUCT_H *p_mt_holiday_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_HOLIDAY_STRUCT_I *l_mt_holiday_struct_i = (MT_HOLIDAY_STRUCT_I *)NULL;

	l_mt_holiday_struct_i = (MT_HOLIDAY_STRUCT_I *)calloc(1,sizeof(MT_HOLIDAY_STRUCT_I));



	if(!strlen(p_mt_holiday_struct_h ->h_h_date))
		l_mt_holiday_struct_i -> i_h_date= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_h_class))
		l_mt_holiday_struct_i -> i_h_class= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_h_reason))
		l_mt_holiday_struct_i -> i_h_reason= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_maker))
		l_mt_holiday_struct_i -> i_maker= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_maker_dt))
		l_mt_holiday_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_access_stamp))
		l_mt_holiday_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_checker))
		l_mt_holiday_struct_i -> i_checker= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_checker_dt))
		l_mt_holiday_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_status))
		l_mt_holiday_struct_i -> i_status= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_hol_ind))
		l_mt_holiday_struct_i -> i_hol_ind= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_old_class))
		l_mt_holiday_struct_i -> i_old_class= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_old_reason))
		l_mt_holiday_struct_i -> i_old_reason= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_old_brnch_hol_ind))
		l_mt_holiday_struct_i -> i_old_brnch_hol_ind= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_bank_ind))
		l_mt_holiday_struct_i -> i_bank_ind= -1;
	if(!strlen(p_mt_holiday_struct_h ->h_exch_code))
		l_mt_holiday_struct_i -> i_exch_code= -1;


	/* EXEC SQL INSERT INTO MT_HOLIDAY VALUES(:p_mt_holiday_struct_h:l_mt_holiday_struct_i); */ 
#line 352 "DM_DbInterface.pc"

{
#line 352 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 352 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 352 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_HOLIDAY  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:\
s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:\
s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 )";
#line 352 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 352 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )427;
#line 352 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 352 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_holiday_struct_h->h_h_date;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )20;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_holiday_struct_i->i_h_date;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_holiday_struct_h->h_h_class;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )3;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_holiday_struct_i->i_h_class;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_holiday_struct_h->h_h_reason;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )31;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_holiday_struct_i->i_h_reason;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_holiday_struct_h->h_maker;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )15;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_holiday_struct_i->i_maker;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_holiday_struct_h->h_maker_dt;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_holiday_struct_i->i_maker_dt;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_holiday_struct_h->h_access_stamp;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_holiday_struct_i->i_access_stamp;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_holiday_struct_h->h_checker;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_holiday_struct_i->i_checker;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_holiday_struct_h->h_checker_dt;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_holiday_struct_i->i_checker_dt;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_holiday_struct_h->h_status;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )3;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_holiday_struct_i->i_status;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_holiday_struct_h->h_hol_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )2;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_holiday_struct_i->i_hol_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_holiday_struct_h->h_old_class;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )3;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_holiday_struct_i->i_old_class;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_holiday_struct_h->h_old_reason;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )31;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_holiday_struct_i->i_old_reason;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_holiday_struct_h->h_old_brnch_hol_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )2;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_holiday_struct_i->i_old_brnch_hol_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_holiday_struct_h->h_bank_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )2;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_holiday_struct_i->i_bank_ind;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_holiday_struct_h->h_exch_code;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )4;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_holiday_struct_i->i_exch_code;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 352 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 352 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 352 "DM_DbInterface.pc"
}

#line 352 "DM_DbInterface.pc"

	printf("Col |%s| Value |%s| Value Ind|%d|\n","H_DATE",p_mt_holiday_struct_h -> h_h_date,l_mt_holiday_struct_i -> i_h_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","H_CLASS",p_mt_holiday_struct_h -> h_h_class,l_mt_holiday_struct_i -> i_h_class,strlen(p_mt_holiday_struct_h -> h_h_class),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","H_REASON",p_mt_holiday_struct_h -> h_h_reason,l_mt_holiday_struct_i -> i_h_reason,strlen(p_mt_holiday_struct_h -> h_h_reason),30);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_holiday_struct_h -> h_maker,l_mt_holiday_struct_i -> i_maker,strlen(p_mt_holiday_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_holiday_struct_h -> h_maker_dt,l_mt_holiday_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_holiday_struct_h -> h_access_stamp,l_mt_holiday_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_holiday_struct_h -> h_checker,l_mt_holiday_struct_i -> i_checker,strlen(p_mt_holiday_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_holiday_struct_h -> h_checker_dt,l_mt_holiday_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_holiday_struct_h -> h_status,l_mt_holiday_struct_i -> i_status,strlen(p_mt_holiday_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","HOL_IND",p_mt_holiday_struct_h -> h_hol_ind,l_mt_holiday_struct_i -> i_hol_ind,strlen(p_mt_holiday_struct_h -> h_hol_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","OLD_CLASS",p_mt_holiday_struct_h -> h_old_class,l_mt_holiday_struct_i -> i_old_class,strlen(p_mt_holiday_struct_h -> h_old_class),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","OLD_REASON",p_mt_holiday_struct_h -> h_old_reason,l_mt_holiday_struct_i -> i_old_reason,strlen(p_mt_holiday_struct_h -> h_old_reason),30);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","OLD_BRNCH_HOL_IND",p_mt_holiday_struct_h -> h_old_brnch_hol_ind,l_mt_holiday_struct_i -> i_old_brnch_hol_ind,strlen(p_mt_holiday_struct_h -> h_old_brnch_hol_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BANK_IND",p_mt_holiday_struct_h -> h_bank_ind,l_mt_holiday_struct_i -> i_bank_ind,strlen(p_mt_holiday_struct_h -> h_bank_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_holiday_struct_h -> h_exch_code,l_mt_holiday_struct_i -> i_exch_code,strlen(p_mt_holiday_struct_h -> h_exch_code),3);

	IS_ANY_ORA_ERROR
		RETURN_SUCCESS:

		APL_FREE(l_mt_holiday_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_holiday_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
}



int MT_UpdMT_NO_DELV(MT_NO_DELV_STRUCT_H *p_mt_no_delv_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_NO_DELV_STRUCT_I *l_mt_no_delv_struct_i = (MT_NO_DELV_STRUCT_I *)NULL;

	l_mt_no_delv_struct_i = (MT_NO_DELV_STRUCT_I *)calloc(1,sizeof(MT_NO_DELV_STRUCT_I));



	if(!strlen(p_mt_no_delv_struct_h ->h_exch_code))
		l_mt_no_delv_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_instr_code))
		l_mt_no_delv_struct_i -> i_instr_code= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_no_del_from))
		l_mt_no_delv_struct_i -> i_no_del_from= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_no_del_to))
		l_mt_no_delv_struct_i -> i_no_del_to= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_mkt_type))
		l_mt_no_delv_struct_i -> i_mkt_type= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_carry_fw_stlno))
		l_mt_no_delv_struct_i -> i_carry_fw_stlno= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_maker))
		l_mt_no_delv_struct_i -> i_maker= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_maker_dt))
		l_mt_no_delv_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_access_stamp))
		l_mt_no_delv_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_checker))
		l_mt_no_delv_struct_i -> i_checker= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_checker_dt))
		l_mt_no_delv_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_no_delv_struct_h ->h_status))
		l_mt_no_delv_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_NO_DELV VALUES(:p_mt_no_delv_struct_h:l_mt_no_delv_struct_i); */ 
#line 422 "DM_DbInterface.pc"

{
#line 422 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 422 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 422 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_NO_DELV  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:\
s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:\
s24 )";
#line 422 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 422 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )502;
#line 422 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 422 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_no_delv_struct_h->h_exch_code;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )4;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_no_delv_struct_i->i_exch_code;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_no_delv_struct_h->h_instr_code;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )9;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_no_delv_struct_i->i_instr_code;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_no_delv_struct_h->h_no_del_from;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_no_delv_struct_i->i_no_del_from;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_no_delv_struct_h->h_no_del_to;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_no_delv_struct_i->i_no_del_to;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_no_delv_struct_h->h_mkt_type;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )4;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_no_delv_struct_i->i_mkt_type;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_no_delv_struct_h->h_carry_fw_stlno;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )12;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_no_delv_struct_i->i_carry_fw_stlno;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_no_delv_struct_h->h_maker;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_no_delv_struct_i->i_maker;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_no_delv_struct_h->h_maker_dt;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_no_delv_struct_i->i_maker_dt;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_no_delv_struct_h->h_access_stamp;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_no_delv_struct_i->i_access_stamp;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_no_delv_struct_h->h_checker;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_no_delv_struct_i->i_checker;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_no_delv_struct_h->h_checker_dt;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_no_delv_struct_i->i_checker_dt;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_no_delv_struct_h->h_status;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_no_delv_struct_i->i_status;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 422 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 422 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 422 "DM_DbInterface.pc"
}

#line 422 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_no_delv_struct_h -> h_exch_code,l_mt_no_delv_struct_i -> i_exch_code,strlen(p_mt_no_delv_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_no_delv_struct_h -> h_instr_code,l_mt_no_delv_struct_i -> i_instr_code,strlen(p_mt_no_delv_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NO_DEL_FROM",p_mt_no_delv_struct_h -> h_no_del_from,l_mt_no_delv_struct_i -> i_no_del_from);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NO_DEL_TO",p_mt_no_delv_struct_h -> h_no_del_to,l_mt_no_delv_struct_i -> i_no_del_to);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MKT_TYPE",p_mt_no_delv_struct_h -> h_mkt_type,l_mt_no_delv_struct_i -> i_mkt_type,strlen(p_mt_no_delv_struct_h -> h_mkt_type),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CARRY_FW_STLNO",p_mt_no_delv_struct_h -> h_carry_fw_stlno,l_mt_no_delv_struct_i -> i_carry_fw_stlno,strlen(p_mt_no_delv_struct_h -> h_carry_fw_stlno),11);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_no_delv_struct_h -> h_maker,l_mt_no_delv_struct_i -> i_maker,strlen(p_mt_no_delv_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_no_delv_struct_h -> h_maker_dt,l_mt_no_delv_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_no_delv_struct_h -> h_access_stamp,l_mt_no_delv_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_no_delv_struct_h -> h_checker,l_mt_no_delv_struct_i -> i_checker,strlen(p_mt_no_delv_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_no_delv_struct_h -> h_checker_dt,l_mt_no_delv_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_no_delv_struct_h -> h_status,l_mt_no_delv_struct_i -> i_status,strlen(p_mt_no_delv_struct_h -> h_status),2);

	IS_ANY_ORA_ERROR

RETURN_SUCCESS:

	APL_FREE(l_mt_no_delv_struct_i);
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_no_delv_struct_i);
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_COMPANY(MT_COMPANY_STRUCT_H *p_mt_company_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_COMPANY_STRUCT_I *l_mt_company_struct_i = (MT_COMPANY_STRUCT_I *)NULL;

	l_mt_company_struct_i = (MT_COMPANY_STRUCT_I *)calloc(1,sizeof(MT_COMPANY_STRUCT_I));



	if(!strlen(p_mt_company_struct_h ->h_cmp_code))
		l_mt_company_struct_i -> i_cmp_code= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_name))
		l_mt_company_struct_i -> i_cmp_name= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_shortnm))
		l_mt_company_struct_i -> i_cmp_shortnm= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_oldname))
		l_mt_company_struct_i -> i_cmp_oldname= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_add1))
		l_mt_company_struct_i -> i_cmp_add1= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_add2))
		l_mt_company_struct_i -> i_cmp_add2= -1;
	if(!strlen(p_mt_company_struct_h ->h_city))
		l_mt_company_struct_i -> i_city= -1;
	if(!strlen(p_mt_company_struct_h ->h_state))
		l_mt_company_struct_i -> i_state= -1;
	if(!strlen(p_mt_company_struct_h ->h_country))
		l_mt_company_struct_i -> i_country= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_add_pin))
		l_mt_company_struct_i -> i_cmp_add_pin= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_tel))
		l_mt_company_struct_i -> i_cmp_tel= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_fax))
		l_mt_company_struct_i -> i_cmp_fax= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_webadd))
		l_mt_company_struct_i -> i_cmp_webadd= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_swf_name))
		l_mt_company_struct_i -> i_cmp_swf_name= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_secnm))
		l_mt_company_struct_i -> i_cmp_secnm= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_sec_email))
		l_mt_company_struct_i -> i_cmp_sec_email= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_mdnm))
		l_mt_company_struct_i -> i_cmp_mdnm= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_industrycd))
		l_mt_company_struct_i -> i_cmp_industrycd= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_sectorcd))
		l_mt_company_struct_i -> i_cmp_sectorcd= -1;
	if(!strlen(p_mt_company_struct_h ->h_cmp_remarks))
		l_mt_company_struct_i -> i_cmp_remarks= -1;



	if(!strlen(p_mt_company_struct_h ->h_maker))
		l_mt_company_struct_i -> i_maker= -1;
	if(!strlen(p_mt_company_struct_h ->h_maker_dt))
		l_mt_company_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_company_struct_h ->h_access_stamp))
		l_mt_company_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_company_struct_h ->h_checker))
		l_mt_company_struct_i -> i_checker= -1;
	if(!strlen(p_mt_company_struct_h ->h_checker_dt))
		l_mt_company_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_company_struct_h ->h_status))
		l_mt_company_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_COMPANY VALUES(:p_mt_company_struct_h:l_mt_company_struct_i); */ 
#line 520 "DM_DbInterface.pc"

{
#line 520 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 520 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 520 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_COMPANY  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:\
s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:\
s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,:s3\
9:s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54 ,:\
s55:s56 ,:s57:s58 )";
#line 520 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 520 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )565;
#line 520 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 520 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_company_struct_h->h_cmp_code;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_company_struct_i->i_cmp_code;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_company_struct_h->h_cmp_name;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )66;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_company_struct_i->i_cmp_name;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_company_struct_h->h_cmp_shortnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )13;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_company_struct_i->i_cmp_shortnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_company_struct_h->h_cmp_oldname;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )66;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_company_struct_i->i_cmp_oldname;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_company_struct_h->h_cmp_add1;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )61;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_company_struct_i->i_cmp_add1;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_company_struct_h->h_cmp_add2;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )61;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_company_struct_i->i_cmp_add2;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_company_struct_h->h_city;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )4;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_company_struct_i->i_city;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_company_struct_h->h_state;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )3;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_company_struct_i->i_state;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_company_struct_h->h_country;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )3;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_company_struct_i->i_country;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_company_struct_h->h_cmp_add_pin;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )11;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_company_struct_i->i_cmp_add_pin;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_company_struct_h->h_cmp_tel;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )21;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_company_struct_i->i_cmp_tel;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_company_struct_h->h_cmp_fax;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )21;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_company_struct_i->i_cmp_fax;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_company_struct_h->h_cmp_webadd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )61;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_company_struct_i->i_cmp_webadd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_company_struct_h->h_cmp_swf_name;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )21;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_company_struct_i->i_cmp_swf_name;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_company_struct_h->h_cmp_secnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )51;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_company_struct_i->i_cmp_secnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_company_struct_h->h_cmp_sec_email;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )61;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_company_struct_i->i_cmp_sec_email;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_company_struct_h->h_cmp_mdnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )41;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_company_struct_i->i_cmp_mdnm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_mt_company_struct_h->h_cmp_industrycd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )4;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_company_struct_i->i_cmp_industrycd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)p_mt_company_struct_h->h_cmp_sectorcd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )4;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_mt_company_struct_i->i_cmp_sectorcd;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)p_mt_company_struct_h->h_cmp_remarks;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )201;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_mt_company_struct_i->i_cmp_remarks;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)&p_mt_company_struct_h->h_cmp_authcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_mt_company_struct_i->i_cmp_authcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[21] = (unsigned char  *)&p_mt_company_struct_h->h_cmp_issuedcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[21] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[21] = (         short *)&l_mt_company_struct_i->i_cmp_issuedcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[21] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[21] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[21] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[21] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[22] = (unsigned char  *)&p_mt_company_struct_h->h_cmp_tpcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[22] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[22] = (         short *)&l_mt_company_struct_i->i_cmp_tpcapital;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[22] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[22] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[22] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[22] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[23] = (unsigned char  *)p_mt_company_struct_h->h_maker;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[23] = (unsigned long )15;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[23] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[23] = (         short *)&l_mt_company_struct_i->i_maker;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[23] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[23] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[23] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[23] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[24] = (unsigned char  *)p_mt_company_struct_h->h_maker_dt;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[24] = (unsigned long )20;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[24] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[24] = (         short *)&l_mt_company_struct_i->i_maker_dt;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[24] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[24] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[24] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[24] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[25] = (unsigned char  *)p_mt_company_struct_h->h_access_stamp;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[25] = (unsigned long )20;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[25] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[25] = (         short *)&l_mt_company_struct_i->i_access_stamp;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[25] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[25] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[25] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[25] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[26] = (unsigned char  *)p_mt_company_struct_h->h_checker;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[26] = (unsigned long )15;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[26] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[26] = (         short *)&l_mt_company_struct_i->i_checker;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[26] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[26] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[26] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[26] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[27] = (unsigned char  *)p_mt_company_struct_h->h_checker_dt;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[27] = (unsigned long )20;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[27] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[27] = (         short *)&l_mt_company_struct_i->i_checker_dt;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[27] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[27] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[27] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[27] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstv[28] = (unsigned char  *)p_mt_company_struct_h->h_status;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhstl[28] = (unsigned long )3;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqhsts[28] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqindv[28] = (         short *)&l_mt_company_struct_i->i_status;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqinds[28] = (         int  )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqharm[28] = (unsigned long )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqadto[28] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqtdso[28] = (unsigned short )0;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 520 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 520 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 520 "DM_DbInterface.pc"
}

#line 520 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_CODE",p_mt_company_struct_h -> h_cmp_code,l_mt_company_struct_i -> i_cmp_code,strlen(p_mt_company_struct_h -> h_cmp_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_NAME",p_mt_company_struct_h -> h_cmp_name,l_mt_company_struct_i -> i_cmp_name,strlen(p_mt_company_struct_h -> h_cmp_name),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_SHORTNM",p_mt_company_struct_h -> h_cmp_shortnm,l_mt_company_struct_i -> i_cmp_shortnm,strlen(p_mt_company_struct_h -> h_cmp_shortnm),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_OLDNAME",p_mt_company_struct_h -> h_cmp_oldname,l_mt_company_struct_i -> i_cmp_oldname,strlen(p_mt_company_struct_h -> h_cmp_oldname),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_ADD1",p_mt_company_struct_h -> h_cmp_add1,l_mt_company_struct_i -> i_cmp_add1,strlen(p_mt_company_struct_h -> h_cmp_add1),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_ADD2",p_mt_company_struct_h -> h_cmp_add2,l_mt_company_struct_i -> i_cmp_add2,strlen(p_mt_company_struct_h -> h_cmp_add2),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CITY",p_mt_company_struct_h -> h_city,l_mt_company_struct_i -> i_city,strlen(p_mt_company_struct_h -> h_city),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATE",p_mt_company_struct_h -> h_state,l_mt_company_struct_i -> i_state,strlen(p_mt_company_struct_h -> h_state),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COUNTRY",p_mt_company_struct_h -> h_country,l_mt_company_struct_i -> i_country,strlen(p_mt_company_struct_h -> h_country),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_ADD_PIN",p_mt_company_struct_h -> h_cmp_add_pin,l_mt_company_struct_i -> i_cmp_add_pin,strlen(p_mt_company_struct_h -> h_cmp_add_pin),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_TEL",p_mt_company_struct_h -> h_cmp_tel,l_mt_company_struct_i -> i_cmp_tel,strlen(p_mt_company_struct_h -> h_cmp_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_FAX",p_mt_company_struct_h -> h_cmp_fax,l_mt_company_struct_i -> i_cmp_fax,strlen(p_mt_company_struct_h -> h_cmp_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_WEBADD",p_mt_company_struct_h -> h_cmp_webadd,l_mt_company_struct_i -> i_cmp_webadd,strlen(p_mt_company_struct_h -> h_cmp_webadd),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_SWF_NAME",p_mt_company_struct_h -> h_cmp_swf_name,l_mt_company_struct_i -> i_cmp_swf_name,strlen(p_mt_company_struct_h -> h_cmp_swf_name),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_SECNM",p_mt_company_struct_h -> h_cmp_secnm,l_mt_company_struct_i -> i_cmp_secnm,strlen(p_mt_company_struct_h -> h_cmp_secnm),40);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_SEC_EMAIL",p_mt_company_struct_h -> h_cmp_sec_email,l_mt_company_struct_i -> i_cmp_sec_email,strlen(p_mt_company_struct_h -> h_cmp_sec_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_MDNM",p_mt_company_struct_h -> h_cmp_mdnm,l_mt_company_struct_i -> i_cmp_mdnm,strlen(p_mt_company_struct_h -> h_cmp_mdnm),40);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_INDUSTRYCD",p_mt_company_struct_h -> h_cmp_industrycd,l_mt_company_struct_i -> i_cmp_industrycd,strlen(p_mt_company_struct_h -> h_cmp_industrycd),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_SECTORCD",p_mt_company_struct_h -> h_cmp_sectorcd,l_mt_company_struct_i -> i_cmp_sectorcd,strlen(p_mt_company_struct_h -> h_cmp_sectorcd),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_REMARKS",p_mt_company_struct_h -> h_cmp_remarks,l_mt_company_struct_i -> i_cmp_remarks,strlen(p_mt_company_struct_h -> h_cmp_remarks),200);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CMP_AUTHCAPITAL",p_mt_company_struct_h -> h_cmp_authcapital,l_mt_company_struct_i -> i_cmp_authcapital);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CMP_ISSUEDCAPITAL",p_mt_company_struct_h -> h_cmp_issuedcapital,l_mt_company_struct_i -> i_cmp_issuedcapital);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CMP_TPCAPITAL",p_mt_company_struct_h -> h_cmp_tpcapital,l_mt_company_struct_i -> i_cmp_tpcapital);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_company_struct_h -> h_maker,l_mt_company_struct_i -> i_maker,strlen(p_mt_company_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_company_struct_h -> h_maker_dt,l_mt_company_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_company_struct_h -> h_access_stamp,l_mt_company_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_company_struct_h -> h_checker,l_mt_company_struct_i -> i_checker,strlen(p_mt_company_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_company_struct_h -> h_checker_dt,l_mt_company_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_company_struct_h -> h_status,l_mt_company_struct_i -> i_status,strlen(p_mt_company_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_company_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_company_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}
int MT_UpdMT_SETTL_CAL(MT_SETTL_CAL_STRUCT_H *p_mt_settl_cal_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_SETTL_CAL_STRUCT_I *l_mt_settl_cal_struct_i = (MT_SETTL_CAL_STRUCT_I *)NULL;

	l_mt_settl_cal_struct_i = (MT_SETTL_CAL_STRUCT_I *)calloc(1,sizeof(MT_SETTL_CAL_STRUCT_I));



	if(!strlen(p_mt_settl_cal_struct_h ->h_exch_code))
		l_mt_settl_cal_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_settl_no))
		l_mt_settl_cal_struct_i -> i_settl_no= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_cc_id))
		l_mt_settl_cal_struct_i -> i_cc_id= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_settl_type))
		l_mt_settl_cal_struct_i -> i_settl_type= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_start_date))
		l_mt_settl_cal_struct_i -> i_start_date= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_end_date))
		l_mt_settl_cal_struct_i -> i_end_date= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_nsdl_deadline_dt))
		l_mt_settl_cal_struct_i -> i_nsdl_deadline_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_nsdl_deadline_tm))
		l_mt_settl_cal_struct_i -> i_nsdl_deadline_tm= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_pay_in_dt))
		l_mt_settl_cal_struct_i -> i_pay_in_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_pay_out_dt))
		l_mt_settl_cal_struct_i -> i_pay_out_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_auction_dt))
		l_mt_settl_cal_struct_i -> i_auction_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_maker))
		l_mt_settl_cal_struct_i -> i_maker= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_maker_dt))
		l_mt_settl_cal_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_access_stamp))
		l_mt_settl_cal_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_checker))
		l_mt_settl_cal_struct_i -> i_checker= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_checker_dt))
		l_mt_settl_cal_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_settl_cal_struct_h ->h_status))
		l_mt_settl_cal_struct_i -> i_status= -1;
	/* EXEC SQL INSERT INTO MT_SETTL_CAL VALUES(:p_mt_settl_cal_struct_h:l_mt_settl_cal_struct_i); */ 
#line 612 "DM_DbInterface.pc"

{
#line 612 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 612 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 612 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_SETTL_CAL  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s\
7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s2\
3:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 )";
#line 612 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 612 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )696;
#line 612 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 612 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_settl_cal_struct_h->h_exch_code;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )4;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_settl_cal_struct_i->i_exch_code;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_settl_cal_struct_h->h_settl_no;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )12;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_settl_cal_struct_i->i_settl_no;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_settl_cal_struct_h->h_cc_id;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )9;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_settl_cal_struct_i->i_cc_id;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_settl_cal_struct_h->h_settl_type;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )4;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_settl_cal_struct_i->i_settl_type;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_settl_cal_struct_h->h_start_date;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_settl_cal_struct_i->i_start_date;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_settl_cal_struct_h->h_end_date;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_settl_cal_struct_i->i_end_date;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_settl_cal_struct_h->h_nsdl_deadline_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_settl_cal_struct_i->i_nsdl_deadline_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_settl_cal_struct_h->h_nsdl_deadline_tm;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )9;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_settl_cal_struct_i->i_nsdl_deadline_tm;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_settl_cal_struct_h->h_pay_in_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_settl_cal_struct_i->i_pay_in_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_settl_cal_struct_h->h_pay_out_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_settl_cal_struct_i->i_pay_out_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_settl_cal_struct_h->h_auction_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_settl_cal_struct_i->i_auction_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_settl_cal_struct_h->h_maker;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )15;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_settl_cal_struct_i->i_maker;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_settl_cal_struct_h->h_maker_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_settl_cal_struct_i->i_maker_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_settl_cal_struct_h->h_access_stamp;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_settl_cal_struct_i->i_access_stamp;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_settl_cal_struct_h->h_checker;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )15;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_settl_cal_struct_i->i_checker;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_settl_cal_struct_h->h_checker_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )20;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_settl_cal_struct_i->i_checker_dt;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_settl_cal_struct_h->h_status;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )3;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_settl_cal_struct_i->i_status;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 612 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 612 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 612 "DM_DbInterface.pc"
}

#line 612 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_settl_cal_struct_h -> h_exch_code,l_mt_settl_cal_struct_i -> i_exch_code,strlen(p_mt_settl_cal_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SETTL_NO",p_mt_settl_cal_struct_h -> h_settl_no,l_mt_settl_cal_struct_i -> i_settl_no,strlen(p_mt_settl_cal_struct_h -> h_settl_no),11);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CC_ID",p_mt_settl_cal_struct_h -> h_cc_id,l_mt_settl_cal_struct_i -> i_cc_id,strlen(p_mt_settl_cal_struct_h -> h_cc_id),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SETTL_TYPE",p_mt_settl_cal_struct_h -> h_settl_type,l_mt_settl_cal_struct_i -> i_settl_type,strlen(p_mt_settl_cal_struct_h -> h_settl_type),3);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","START_DATE",p_mt_settl_cal_struct_h -> h_start_date,l_mt_settl_cal_struct_i -> i_start_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","END_DATE",p_mt_settl_cal_struct_h -> h_end_date,l_mt_settl_cal_struct_i -> i_end_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NSDL_DEADLINE_DT",p_mt_settl_cal_struct_h -> h_nsdl_deadline_dt,l_mt_settl_cal_struct_i -> i_nsdl_deadline_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NSDL_DEADLINE_TM",p_mt_settl_cal_struct_h -> h_nsdl_deadline_tm,l_mt_settl_cal_struct_i -> i_nsdl_deadline_tm,strlen(p_mt_settl_cal_struct_h -> h_nsdl_deadline_tm),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PAY_IN_DT",p_mt_settl_cal_struct_h -> h_pay_in_dt,l_mt_settl_cal_struct_i -> i_pay_in_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PAY_OUT_DT",p_mt_settl_cal_struct_h -> h_pay_out_dt,l_mt_settl_cal_struct_i -> i_pay_out_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","AUCTION_DT",p_mt_settl_cal_struct_h -> h_auction_dt,l_mt_settl_cal_struct_i -> i_auction_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_settl_cal_struct_h -> h_maker,l_mt_settl_cal_struct_i -> i_maker,strlen(p_mt_settl_cal_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_settl_cal_struct_h -> h_maker_dt,l_mt_settl_cal_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_settl_cal_struct_h -> h_access_stamp,l_mt_settl_cal_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_settl_cal_struct_h -> h_checker,l_mt_settl_cal_struct_i -> i_checker,strlen(p_mt_settl_cal_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_settl_cal_struct_h -> h_checker_dt,l_mt_settl_cal_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_settl_cal_struct_h -> h_status,l_mt_settl_cal_struct_i -> i_status,strlen(p_mt_settl_cal_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_settl_cal_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_settl_cal_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_RBI_MONITORY(MT_RBI_MONITORY_STRUCT_H *p_mt_rbi_monitory_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_RBI_MONITORY_STRUCT_I *l_mt_rbi_monitory_struct_i = (MT_RBI_MONITORY_STRUCT_I *)NULL;

	l_mt_rbi_monitory_struct_i = (MT_RBI_MONITORY_STRUCT_I *)calloc(1,sizeof(MT_RBI_MONITORY_STRUCT_I));



	if(!strlen(p_mt_rbi_monitory_struct_h ->h_instr_code))
		l_mt_rbi_monitory_struct_i -> i_instr_code= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_rbi_instr_code))
		l_mt_rbi_monitory_struct_i -> i_rbi_instr_code= -1;





	if(!strlen(p_mt_rbi_monitory_struct_h ->h_caution_flg))
		l_mt_rbi_monitory_struct_i -> i_caution_flg= -1;


	if(!strlen(p_mt_rbi_monitory_struct_h ->h_maker))
		l_mt_rbi_monitory_struct_i -> i_maker= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_maker_dt))
		l_mt_rbi_monitory_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_access_stamp))
		l_mt_rbi_monitory_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_checker))
		l_mt_rbi_monitory_struct_i -> i_checker= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_checker_dt))
		l_mt_rbi_monitory_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_rbi_monitory_struct_h ->h_status))
		l_mt_rbi_monitory_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_RBI_MONITORY VALUES(:p_mt_rbi_monitory_struct_h:l_mt_rbi_monitory_struct_i); */ 
#line 687 "DM_DbInterface.pc"

{
#line 687 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 687 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 687 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_RBI_MONITORY  values (:s1:s2 ,:s3:s4 ,:s5:s6 \
,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,\
:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 )";
#line 687 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 687 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )779;
#line 687 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 687 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_instr_code;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_rbi_monitory_struct_i->i_instr_code;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_rbi_instr_code;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )21;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_rbi_monitory_struct_i->i_rbi_instr_code;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_tpcapital;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_rbi_monitory_struct_i->i_tpcapital;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_sng_fii_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_rbi_monitory_struct_i->i_sng_fii_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_ovr_fii_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_rbi_monitory_struct_i->i_ovr_fii_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_sng_nriocb_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_rbi_monitory_struct_i->i_sng_nriocb_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_ovr_nriocb_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_rbi_monitory_struct_i->i_ovr_nriocb_limit;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_caution_flg;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )2;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_rbi_monitory_struct_i->i_caution_flg;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_caution_fii;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_rbi_monitory_struct_i->i_caution_fii;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)&p_mt_rbi_monitory_struct_h->h_caution_nriocb;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_rbi_monitory_struct_i->i_caution_nriocb;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_maker;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )15;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_rbi_monitory_struct_i->i_maker;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_maker_dt;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_rbi_monitory_struct_i->i_maker_dt;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_access_stamp;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_rbi_monitory_struct_i->i_access_stamp;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_checker;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )15;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_rbi_monitory_struct_i->i_checker;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_checker_dt;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_rbi_monitory_struct_i->i_checker_dt;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_rbi_monitory_struct_h->h_status;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )3;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_rbi_monitory_struct_i->i_status;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 687 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 687 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 687 "DM_DbInterface.pc"
}

#line 687 "DM_DbInterface.pc"


	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_rbi_monitory_struct_h -> h_instr_code,l_mt_rbi_monitory_struct_i -> i_instr_code,strlen(p_mt_rbi_monitory_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RBI_INSTR_CODE",p_mt_rbi_monitory_struct_h -> h_rbi_instr_code,l_mt_rbi_monitory_struct_i -> i_rbi_instr_code,strlen(p_mt_rbi_monitory_struct_h -> h_rbi_instr_code),20);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","TPCAPITAL",p_mt_rbi_monitory_struct_h -> h_tpcapital,l_mt_rbi_monitory_struct_i -> i_tpcapital);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","SNG_FII_LIMIT",p_mt_rbi_monitory_struct_h -> h_sng_fii_limit,l_mt_rbi_monitory_struct_i -> i_sng_fii_limit);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","OVR_FII_LIMIT",p_mt_rbi_monitory_struct_h -> h_ovr_fii_limit,l_mt_rbi_monitory_struct_i -> i_ovr_fii_limit);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","SNG_NRIOCB_LIMIT",p_mt_rbi_monitory_struct_h -> h_sng_nriocb_limit,l_mt_rbi_monitory_struct_i -> i_sng_nriocb_limit);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","OVR_NRIOCB_LIMIT",p_mt_rbi_monitory_struct_h -> h_ovr_nriocb_limit,l_mt_rbi_monitory_struct_i -> i_ovr_nriocb_limit);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CAUTION_FLG",p_mt_rbi_monitory_struct_h -> h_caution_flg,l_mt_rbi_monitory_struct_i -> i_caution_flg,strlen(p_mt_rbi_monitory_struct_h -> h_caution_flg),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CAUTION_FII",p_mt_rbi_monitory_struct_h -> h_caution_fii,l_mt_rbi_monitory_struct_i -> i_caution_fii);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CAUTION_NRIOCB",p_mt_rbi_monitory_struct_h -> h_caution_nriocb,l_mt_rbi_monitory_struct_i -> i_caution_nriocb);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_rbi_monitory_struct_h -> h_maker,l_mt_rbi_monitory_struct_i -> i_maker,strlen(p_mt_rbi_monitory_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_rbi_monitory_struct_h -> h_maker_dt,l_mt_rbi_monitory_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_rbi_monitory_struct_h -> h_access_stamp,l_mt_rbi_monitory_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_rbi_monitory_struct_h -> h_checker,l_mt_rbi_monitory_struct_i -> i_checker,strlen(p_mt_rbi_monitory_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_rbi_monitory_struct_h -> h_checker_dt,l_mt_rbi_monitory_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_rbi_monitory_struct_h -> h_status,l_mt_rbi_monitory_struct_i -> i_status,strlen(p_mt_rbi_monitory_struct_h -> h_status),2);
	IS_ANY_ORA_ERROR

RETURN_SUCCESS:

	APL_FREE(l_mt_rbi_monitory_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_rbi_monitory_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}
int MT_UpdMT_PTC_DET(MT_PTC_DET_STRUCT_H *p_mt_ptc_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;
	int l_seq_no = 0;

	MT_PTC_DET_STRUCT_I *l_mt_ptc_det_struct_i = (MT_PTC_DET_STRUCT_I *)NULL;

	l_mt_ptc_det_struct_i = (MT_PTC_DET_STRUCT_I *)calloc(1,sizeof(MT_PTC_DET_STRUCT_I));



	if(!strlen(p_mt_ptc_det_struct_h ->h_instr_code))
		l_mt_ptc_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_ptc_det_struct_h ->h_ptc_dt))
		l_mt_ptc_det_struct_i -> i_ptc_dt= -1;

	/* EXEC SQL select nvl(max(instr_seq_num),0) + 1 INTO :l_seq_no 
	from mt_ptc_det where instr_code =: p_mt_ptc_det_struct_h ->h_instr_code; */ 
#line 738 "DM_DbInterface.pc"

{
#line 737 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 737 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 737 "DM_DbInterface.pc"
 sqlstm.stmt = "select (nvl(max(instr_seq_num),0)+1) into :b0  from mt_ptc_d\
et where instr_code=:b1";
#line 737 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 737 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )858;
#line 737 "DM_DbInterface.pc"
 sqlstm.selerr = (unsigned short)1;
#line 737 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 737 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)&l_seq_no;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)(p_mt_ptc_det_struct_h->h_instr_code);
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )9;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 737 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 737 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 737 "DM_DbInterface.pc"
}

#line 738 "DM_DbInterface.pc"

		
	IS_ANY_ORA_ERROR

	printf("Sequnce Local :|%d|",l_seq_no);
	p_mt_ptc_det_struct_h ->h_instr_seq_num = l_seq_no;
	printf("Sequnce Global :|%d|",p_mt_ptc_det_struct_h ->h_instr_seq_num);


	if(!strlen(p_mt_ptc_det_struct_h ->h_ptc_paid_flg))
		l_mt_ptc_det_struct_i -> i_ptc_paid_flg= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_access_stamp))
		l_mt_ptc_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_maker))
		l_mt_ptc_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_maker_dt))
		l_mt_ptc_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_checker))
		l_mt_ptc_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_checker_dt))
		l_mt_ptc_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_ptc_det_struct_h ->h_status))
		l_mt_ptc_det_struct_i -> i_status= -1;



	/* EXEC SQL INSERT INTO MT_PTC_DET VALUES(:p_mt_ptc_det_struct_h:l_mt_ptc_det_struct_i); */ 
#line 764 "DM_DbInterface.pc"

{
#line 764 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 764 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 764 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PTC_DET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:\
s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:\
s24 ,:s25:s26 ,:s27:s28 )";
#line 764 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 764 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )881;
#line 764 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 764 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_ptc_det_struct_h->h_instr_code;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_ptc_det_struct_i->i_instr_code;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_ptc_det_struct_h->h_instr_seq_num;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_ptc_det_struct_i->i_instr_seq_num;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_ptc_det_struct_h->h_ptc_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_ptc_det_struct_h->h_ptc_prin_amt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_prin_amt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_mt_ptc_det_struct_h->h_ptc_int_amt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_int_amt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_mt_ptc_det_struct_h->h_ptc_value;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_value;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_ptc_det_struct_h->h_ptc_paid_flg;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )2;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_paid_flg;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_ptc_det_struct_h->h_access_stamp;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_ptc_det_struct_i->i_access_stamp;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_ptc_det_struct_h->h_maker;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )15;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_ptc_det_struct_i->i_maker;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_ptc_det_struct_h->h_maker_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_ptc_det_struct_i->i_maker_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_ptc_det_struct_h->h_checker;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )15;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_ptc_det_struct_i->i_checker;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_ptc_det_struct_h->h_checker_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_ptc_det_struct_i->i_checker_dt;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_ptc_det_struct_h->h_status;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )3;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_ptc_det_struct_i->i_status;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)&p_mt_ptc_det_struct_h->h_ptc_bal_val;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
#line 764 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_ptc_det_struct_i->i_ptc_bal_val;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 764 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 764 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 764 "DM_DbInterface.pc"
}

#line 764 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_ptc_det_struct_h -> h_instr_code,l_mt_ptc_det_struct_i -> i_instr_code,strlen(p_mt_ptc_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_ptc_det_struct_h -> h_instr_seq_num,l_mt_ptc_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PTC_DT",p_mt_ptc_det_struct_h -> h_ptc_dt,l_mt_ptc_det_struct_i -> i_ptc_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","PTC_PRIN_AMT",p_mt_ptc_det_struct_h -> h_ptc_prin_amt,l_mt_ptc_det_struct_i -> i_ptc_prin_amt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","PTC_INT_AMT",p_mt_ptc_det_struct_h -> h_ptc_int_amt,l_mt_ptc_det_struct_i -> i_ptc_int_amt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","PTC_VALUE",p_mt_ptc_det_struct_h -> h_ptc_value,l_mt_ptc_det_struct_i -> i_ptc_value);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTC_PAID_FLG",p_mt_ptc_det_struct_h -> h_ptc_paid_flg,l_mt_ptc_det_struct_i -> i_ptc_paid_flg,strlen(p_mt_ptc_det_struct_h -> h_ptc_paid_flg),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_ptc_det_struct_h -> h_access_stamp,l_mt_ptc_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_ptc_det_struct_h -> h_maker,l_mt_ptc_det_struct_i -> i_maker,strlen(p_mt_ptc_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_ptc_det_struct_h -> h_maker_dt,l_mt_ptc_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_ptc_det_struct_h -> h_checker,l_mt_ptc_det_struct_i -> i_checker,strlen(p_mt_ptc_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_ptc_det_struct_h -> h_checker_dt,l_mt_ptc_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_ptc_det_struct_h -> h_status,l_mt_ptc_det_struct_i -> i_status,strlen(p_mt_ptc_det_struct_h -> h_status),2);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","PTC_BAL_VAL",p_mt_ptc_det_struct_h -> h_ptc_bal_val,l_mt_ptc_det_struct_i -> i_ptc_bal_val);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_ptc_det_struct_i);
	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_ptc_det_struct_i);
	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_RED_DET(MT_RED_DET_STRUCT_H *p_mt_red_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_RED_DET_STRUCT_I *l_mt_red_det_struct_i = (MT_RED_DET_STRUCT_I *)NULL;

	l_mt_red_det_struct_i = (MT_RED_DET_STRUCT_I *)calloc(1,sizeof(MT_RED_DET_STRUCT_I));



	if(!strlen(p_mt_red_det_struct_h ->h_instr_code))
		l_mt_red_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_red_det_struct_h ->h_red_dt))
		l_mt_red_det_struct_i -> i_red_dt= -1;


	if(!strlen(p_mt_red_det_struct_h ->h_access_stamp))
		l_mt_red_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_red_det_struct_h ->h_maker))
		l_mt_red_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_red_det_struct_h ->h_maker_dt))
		l_mt_red_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_red_det_struct_h ->h_checker))
		l_mt_red_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_red_det_struct_h ->h_checker_dt))
		l_mt_red_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_red_det_struct_h ->h_status))
		l_mt_red_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_RED_DET VALUES(:p_mt_red_det_struct_h:l_mt_red_det_struct_i); */ 
#line 828 "DM_DbInterface.pc"

{
#line 828 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 828 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 828 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_RED_DET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:\
s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 )";
#line 828 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 828 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )952;
#line 828 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 828 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_red_det_struct_h->h_instr_code;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_red_det_struct_i->i_instr_code;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_red_det_struct_h->h_instr_seq_num;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_red_det_struct_i->i_instr_seq_num;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_red_det_struct_h->h_red_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_red_det_struct_i->i_red_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_red_det_struct_h->h_red_pct;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_red_det_struct_i->i_red_pct;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_mt_red_det_struct_h->h_red_value;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_red_det_struct_i->i_red_value;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_red_det_struct_h->h_access_stamp;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_red_det_struct_i->i_access_stamp;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_red_det_struct_h->h_maker;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_red_det_struct_i->i_maker;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_red_det_struct_h->h_maker_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_red_det_struct_i->i_maker_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_red_det_struct_h->h_checker;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )15;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_red_det_struct_i->i_checker;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_red_det_struct_h->h_checker_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_red_det_struct_i->i_checker_dt;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_red_det_struct_h->h_status;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )3;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_red_det_struct_i->i_status;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 828 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 828 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 828 "DM_DbInterface.pc"
}

#line 828 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_red_det_struct_h -> h_instr_code,l_mt_red_det_struct_i -> i_instr_code,strlen(p_mt_red_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_red_det_struct_h -> h_instr_seq_num,l_mt_red_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RED_DT",p_mt_red_det_struct_h -> h_red_dt,l_mt_red_det_struct_i -> i_red_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","RED_PCT",p_mt_red_det_struct_h -> h_red_pct,l_mt_red_det_struct_i -> i_red_pct);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","RED_VALUE",p_mt_red_det_struct_h -> h_red_value,l_mt_red_det_struct_i -> i_red_value);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_red_det_struct_h -> h_access_stamp,l_mt_red_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_red_det_struct_h -> h_maker,l_mt_red_det_struct_i -> i_maker,strlen(p_mt_red_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_red_det_struct_h -> h_maker_dt,l_mt_red_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_red_det_struct_h -> h_checker,l_mt_red_det_struct_i -> i_checker,strlen(p_mt_red_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_red_det_struct_h -> h_checker_dt,l_mt_red_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_red_det_struct_h -> h_status,l_mt_red_det_struct_i -> i_status,strlen(p_mt_red_det_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_red_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_red_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_PC_DET(MT_PC_DET_STRUCT_H *p_mt_pc_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_PC_DET_STRUCT_I *l_mt_pc_det_struct_i = (MT_PC_DET_STRUCT_I *)NULL;

	l_mt_pc_det_struct_i = (MT_PC_DET_STRUCT_I *)calloc(1,sizeof(MT_PC_DET_STRUCT_I));



	if(!strlen(p_mt_pc_det_struct_h ->h_instr_code))
		l_mt_pc_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_pc_det_struct_h ->h_pc_flag))
		l_mt_pc_det_struct_i -> i_pc_flag= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_pc_date))
		l_mt_pc_det_struct_i -> i_pc_date= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_pc_notice_date))
		l_mt_pc_det_struct_i -> i_pc_notice_date= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_instr_pc_effdt))
		l_mt_pc_det_struct_i -> i_instr_pc_effdt= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_instr_pc_cutofftime))
		l_mt_pc_det_struct_i -> i_instr_pc_cutofftime= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_maker))
		l_mt_pc_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_maker_dt))
		l_mt_pc_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_access_stamp))
		l_mt_pc_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_checker))
		l_mt_pc_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_checker_dt))
		l_mt_pc_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_pc_det_struct_h ->h_status))
		l_mt_pc_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_PC_DET VALUES(:p_mt_pc_det_struct_h:l_mt_pc_det_struct_i); */ 
#line 897 "DM_DbInterface.pc"

{
#line 897 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 897 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 897 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PC_DET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s\
8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s\
24 ,:s25:s26 ,:s27:s28 ,:s29:s30 )";
#line 897 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 897 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1011;
#line 897 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 897 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pc_det_struct_h->h_instr_code;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_pc_det_struct_i->i_instr_code;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_pc_det_struct_h->h_instr_seq_num;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_pc_det_struct_i->i_instr_seq_num;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_pc_det_struct_h->h_pc_flag;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )2;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_pc_det_struct_i->i_pc_flag;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pc_det_struct_h->h_pc_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_pc_det_struct_i->i_pc_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pc_det_struct_h->h_pc_notice_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_pc_det_struct_i->i_pc_notice_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pc_det_struct_h->h_instr_pc_effdt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_pc_det_struct_i->i_instr_pc_effdt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pc_det_struct_h->h_instr_pc_cutofftime;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_pc_det_struct_i->i_instr_pc_cutofftime;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pc_det_struct_h->h_maker;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_pc_det_struct_i->i_maker;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pc_det_struct_h->h_maker_dt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_pc_det_struct_i->i_maker_dt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pc_det_struct_h->h_access_stamp;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_pc_det_struct_i->i_access_stamp;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_pc_det_struct_h->h_checker;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )15;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_pc_det_struct_i->i_checker;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_pc_det_struct_h->h_checker_dt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_pc_det_struct_i->i_checker_dt;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_pc_det_struct_h->h_status;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )3;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_pc_det_struct_i->i_status;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)&p_mt_pc_det_struct_h->h_instr_pc_noofday;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_pc_det_struct_i->i_instr_pc_noofday;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_pc_det_struct_h->h_call_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_pc_det_struct_i->i_call_date;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 897 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 897 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 897 "DM_DbInterface.pc"
}

#line 897 "DM_DbInterface.pc"


	IS_ANY_ORA_ERROR

	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_pc_det_struct_h -> h_instr_code,l_mt_pc_det_struct_i -> i_instr_code,strlen(p_mt_pc_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_pc_det_struct_h -> h_instr_seq_num,l_mt_pc_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PC_FLAG",p_mt_pc_det_struct_h -> h_pc_flag,l_mt_pc_det_struct_i -> i_pc_flag,strlen(p_mt_pc_det_struct_h -> h_pc_flag),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PC_DATE",p_mt_pc_det_struct_h -> h_pc_date,l_mt_pc_det_struct_i -> i_pc_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PC_NOTICE_DATE",p_mt_pc_det_struct_h -> h_pc_notice_date,l_mt_pc_det_struct_i -> i_pc_notice_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_PC_EFFDT",p_mt_pc_det_struct_h -> h_instr_pc_effdt,l_mt_pc_det_struct_i -> i_instr_pc_effdt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTR_PC_CUTOFFTIME",p_mt_pc_det_struct_h -> h_instr_pc_cutofftime,l_mt_pc_det_struct_i -> i_instr_pc_cutofftime);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_pc_det_struct_h -> h_maker,l_mt_pc_det_struct_i -> i_maker,strlen(p_mt_pc_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_pc_det_struct_h -> h_maker_dt,l_mt_pc_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_pc_det_struct_h -> h_access_stamp,l_mt_pc_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_pc_det_struct_h -> h_checker,l_mt_pc_det_struct_i -> i_checker,strlen(p_mt_pc_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_pc_det_struct_h -> h_checker_dt,l_mt_pc_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_pc_det_struct_h -> h_status,l_mt_pc_det_struct_i -> i_status,strlen(p_mt_pc_det_struct_h -> h_status),2);


RETURN_SUCCESS:

	APL_FREE(l_mt_pc_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_pc_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_RESET_DET(MT_RESET_DET_STRUCT_H *p_mt_reset_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_RESET_DET_STRUCT_I *l_mt_reset_det_struct_i = (MT_RESET_DET_STRUCT_I *)NULL;

	l_mt_reset_det_struct_i = (MT_RESET_DET_STRUCT_I *)calloc(1,sizeof(MT_RESET_DET_STRUCT_I));



	if(!strlen(p_mt_reset_det_struct_h ->h_instr_code))
		l_mt_reset_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_reset_det_struct_h ->h_reset_dt))
		l_mt_reset_det_struct_i -> i_reset_dt= -1;

	if(!strlen(p_mt_reset_det_struct_h ->h_reset_frdt))
		l_mt_reset_det_struct_i -> i_reset_frdt= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_reset_todt))
		l_mt_reset_det_struct_i -> i_reset_todt= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_access_stamp))
		l_mt_reset_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_maker))
		l_mt_reset_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_maker_dt))
		l_mt_reset_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_checker))
		l_mt_reset_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_checker_dt))
		l_mt_reset_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_reset_det_struct_h ->h_status))
		l_mt_reset_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_RESET_DET VALUES(:p_mt_reset_det_struct_h:l_mt_reset_det_struct_i); */ 
#line 965 "DM_DbInterface.pc"

{
#line 965 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 965 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 965 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_RESET_DET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s\
7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s2\
3:s24 )";
#line 965 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 965 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1086;
#line 965 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 965 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_reset_det_struct_h->h_instr_code;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_reset_det_struct_i->i_instr_code;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_reset_det_struct_h->h_instr_seq_num;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_reset_det_struct_i->i_instr_seq_num;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_reset_det_struct_h->h_reset_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_reset_det_struct_i->i_reset_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_reset_det_struct_h->h_reset_rate;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_reset_det_struct_i->i_reset_rate;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_reset_det_struct_h->h_reset_frdt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_reset_det_struct_i->i_reset_frdt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_reset_det_struct_h->h_reset_todt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_reset_det_struct_i->i_reset_todt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_reset_det_struct_h->h_access_stamp;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_reset_det_struct_i->i_access_stamp;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_reset_det_struct_h->h_maker;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_reset_det_struct_i->i_maker;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_reset_det_struct_h->h_maker_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_reset_det_struct_i->i_maker_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_reset_det_struct_h->h_checker;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_reset_det_struct_i->i_checker;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_reset_det_struct_h->h_checker_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_reset_det_struct_i->i_checker_dt;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_reset_det_struct_h->h_status;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_reset_det_struct_i->i_status;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 965 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 965 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 965 "DM_DbInterface.pc"
}

#line 965 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_reset_det_struct_h -> h_instr_code,l_mt_reset_det_struct_i -> i_instr_code,strlen(p_mt_reset_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_reset_det_struct_h -> h_instr_seq_num,l_mt_reset_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RESET_DT",p_mt_reset_det_struct_h -> h_reset_dt,l_mt_reset_det_struct_i -> i_reset_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","RESET_RATE",p_mt_reset_det_struct_h -> h_reset_rate,l_mt_reset_det_struct_i -> i_reset_rate);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RESET_FRDT",p_mt_reset_det_struct_h -> h_reset_frdt,l_mt_reset_det_struct_i -> i_reset_frdt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RESET_TODT",p_mt_reset_det_struct_h -> h_reset_todt,l_mt_reset_det_struct_i -> i_reset_todt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_reset_det_struct_h -> h_access_stamp,l_mt_reset_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_reset_det_struct_h -> h_maker,l_mt_reset_det_struct_i -> i_maker,strlen(p_mt_reset_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_reset_det_struct_h -> h_maker_dt,l_mt_reset_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_reset_det_struct_h -> h_checker,l_mt_reset_det_struct_i -> i_checker,strlen(p_mt_reset_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_reset_det_struct_h -> h_checker_dt,l_mt_reset_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_reset_det_struct_h -> h_status,l_mt_reset_det_struct_i -> i_status,strlen(p_mt_reset_det_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_reset_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_reset_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_DAILY_FLOAT_RATE(MT_DAILY_FLOAT_RATE_STRUCT_H *p_mt_daily_float_rate_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_DAILY_FLOAT_RATE_STRUCT_I *l_mt_daily_float_rate_struct_i = (MT_DAILY_FLOAT_RATE_STRUCT_I *)NULL;

	l_mt_daily_float_rate_struct_i = (MT_DAILY_FLOAT_RATE_STRUCT_I *)calloc(1,sizeof(MT_DAILY_FLOAT_RATE_STRUCT_I));



	if(!strlen(p_mt_daily_float_rate_struct_h ->h_benchmark_code))
		l_mt_daily_float_rate_struct_i -> i_benchmark_code= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_rate_date))
		l_mt_daily_float_rate_struct_i -> i_rate_date= -1;




	if(!strlen(p_mt_daily_float_rate_struct_h ->h_maker))
		l_mt_daily_float_rate_struct_i -> i_maker= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_maker_dt))
		l_mt_daily_float_rate_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_access_stamp))
		l_mt_daily_float_rate_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_checker))
		l_mt_daily_float_rate_struct_i -> i_checker= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_checker_dt))
		l_mt_daily_float_rate_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_daily_float_rate_struct_h ->h_status))
		l_mt_daily_float_rate_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_DAILY_FLOAT_RATE VALUES(:p_mt_daily_float_rate_struct_h:l_mt_daily_float_rate_struct_i); */ 
#line 1030 "DM_DbInterface.pc"

{
#line 1030 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1030 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1030 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_DAILY_FLOAT_RATE  values (:s1:s2 ,:s3:s4 ,:s5\
:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s\
22 ,:s23:s24 )";
#line 1030 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1030 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1149;
#line 1030 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1030 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_benchmark_code;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_daily_float_rate_struct_i->i_benchmark_code;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_rate_date;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )20;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_daily_float_rate_struct_i->i_rate_date;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)&p_mt_daily_float_rate_struct_h->h_float_rate1;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_daily_float_rate_struct_i->i_float_rate1;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_daily_float_rate_struct_h->h_float_rate2;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_daily_float_rate_struct_i->i_float_rate2;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_mt_daily_float_rate_struct_h->h_float_rate3;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_daily_float_rate_struct_i->i_float_rate3;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_mt_daily_float_rate_struct_h->h_std_deviation;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_daily_float_rate_struct_i->i_std_deviation;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_maker;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_daily_float_rate_struct_i->i_maker;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_maker_dt;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_daily_float_rate_struct_i->i_maker_dt;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_access_stamp;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_daily_float_rate_struct_i->i_access_stamp;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_checker;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_daily_float_rate_struct_i->i_checker;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_checker_dt;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_daily_float_rate_struct_i->i_checker_dt;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_daily_float_rate_struct_h->h_status;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_daily_float_rate_struct_i->i_status;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1030 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1030 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1030 "DM_DbInterface.pc"
}

#line 1030 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BENCHMARK_CODE",p_mt_daily_float_rate_struct_h -> h_benchmark_code,l_mt_daily_float_rate_struct_i -> i_benchmark_code,strlen(p_mt_daily_float_rate_struct_h -> h_benchmark_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RATE_DATE",p_mt_daily_float_rate_struct_h -> h_rate_date,l_mt_daily_float_rate_struct_i -> i_rate_date);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FLOAT_RATE1",p_mt_daily_float_rate_struct_h -> h_float_rate1,l_mt_daily_float_rate_struct_i -> i_float_rate1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FLOAT_RATE2",p_mt_daily_float_rate_struct_h -> h_float_rate2,l_mt_daily_float_rate_struct_i -> i_float_rate2);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FLOAT_RATE3",p_mt_daily_float_rate_struct_h -> h_float_rate3,l_mt_daily_float_rate_struct_i -> i_float_rate3);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","STD_DEVIATION",p_mt_daily_float_rate_struct_h -> h_std_deviation,l_mt_daily_float_rate_struct_i -> i_std_deviation);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_daily_float_rate_struct_h -> h_maker,l_mt_daily_float_rate_struct_i -> i_maker,strlen(p_mt_daily_float_rate_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_daily_float_rate_struct_h -> h_maker_dt,l_mt_daily_float_rate_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_daily_float_rate_struct_h -> h_access_stamp,l_mt_daily_float_rate_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_daily_float_rate_struct_h -> h_checker,l_mt_daily_float_rate_struct_i -> i_checker,strlen(p_mt_daily_float_rate_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_daily_float_rate_struct_h -> h_checker_dt,l_mt_daily_float_rate_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_daily_float_rate_struct_h -> h_status,l_mt_daily_float_rate_struct_i -> i_status,strlen(p_mt_daily_float_rate_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_daily_float_rate_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_daily_float_rate_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_FLRATE_INSTRUMENT(MT_FLRATE_INSTRUMENT_STRUCT_H *p_mt_flrate_instrument_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_FLRATE_INSTRUMENT_STRUCT_I *l_mt_flrate_instrument_struct_i = (MT_FLRATE_INSTRUMENT_STRUCT_I *)NULL;

	l_mt_flrate_instrument_struct_i = (MT_FLRATE_INSTRUMENT_STRUCT_I *)calloc(1,sizeof(MT_FLRATE_INSTRUMENT_STRUCT_I));



	if(!strlen(p_mt_flrate_instrument_struct_h ->h_instr_code))
		l_mt_flrate_instrument_struct_i -> i_instr_code= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_daily_compound))
		l_mt_flrate_instrument_struct_i -> i_daily_compound= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_excl_holidays))
		l_mt_flrate_instrument_struct_i -> i_excl_holidays= -1;

	if(!strlen(p_mt_flrate_instrument_struct_h ->h_compounding_wdays))
		l_mt_flrate_instrument_struct_i -> i_compounding_wdays= -1;


	if(!strlen(p_mt_flrate_instrument_struct_h ->h_prefd_seq))
		l_mt_flrate_instrument_struct_i -> i_prefd_seq= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_default_float_rate))
		l_mt_flrate_instrument_struct_i -> i_default_float_rate= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_benchmark_code))
		l_mt_flrate_instrument_struct_i -> i_benchmark_code= -1;

	if(!strlen(p_mt_flrate_instrument_struct_h ->h_fixed_bench))
		l_mt_flrate_instrument_struct_i -> i_fixed_bench= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_maker))
		l_mt_flrate_instrument_struct_i -> i_maker= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_maker_dt))
		l_mt_flrate_instrument_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_access_stamp))
		l_mt_flrate_instrument_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_checker))
		l_mt_flrate_instrument_struct_i -> i_checker= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_checker_dt))
		l_mt_flrate_instrument_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_flrate_instrument_struct_h ->h_status))
		l_mt_flrate_instrument_struct_i -> i_status= -1;
	/* EXEC SQL INSERT INTO MT_FLRATE_INSTRUMENT VALUES(:p_mt_flrate_instrument_struct_h:l_mt_flrate_instrument_struct_i); */ 
#line 1105 "DM_DbInterface.pc"

{
#line 1105 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1105 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1105 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_FLRATE_INSTRUMENT  values (:s1:s2 ,:s3:s4 ,:s\
5:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:\
s22 ,:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 )";
#line 1105 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1105 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1212;
#line 1105 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1105 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_instr_code;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_flrate_instrument_struct_i->i_instr_code;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_daily_compound;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )2;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_flrate_instrument_struct_i->i_daily_compound;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_excl_holidays;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )2;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_flrate_instrument_struct_i->i_excl_holidays;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)&p_mt_flrate_instrument_struct_h->h_int_pay_days;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_flrate_instrument_struct_i->i_int_pay_days;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_compounding_wdays;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )2;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_flrate_instrument_struct_i->i_compounding_wdays;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_mt_flrate_instrument_struct_h->h_floor_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_flrate_instrument_struct_i->i_floor_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)&p_mt_flrate_instrument_struct_h->h_cap_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_flrate_instrument_struct_i->i_cap_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_prefd_seq;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_flrate_instrument_struct_i->i_prefd_seq;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_default_float_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )2;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_flrate_instrument_struct_i->i_default_float_rate;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_benchmark_code;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )9;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_flrate_instrument_struct_i->i_benchmark_code;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)&p_mt_flrate_instrument_struct_h->h_base_margin;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_flrate_instrument_struct_i->i_base_margin;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_fixed_bench;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )2;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_flrate_instrument_struct_i->i_fixed_bench;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_maker;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )15;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_flrate_instrument_struct_i->i_maker;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_maker_dt;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_flrate_instrument_struct_i->i_maker_dt;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_access_stamp;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_flrate_instrument_struct_i->i_access_stamp;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_checker;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )15;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_flrate_instrument_struct_i->i_checker;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_checker_dt;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )20;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_flrate_instrument_struct_i->i_checker_dt;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_mt_flrate_instrument_struct_h->h_status;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )3;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_flrate_instrument_struct_i->i_status;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1105 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1105 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1105 "DM_DbInterface.pc"
}

#line 1105 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_flrate_instrument_struct_h -> h_instr_code,l_mt_flrate_instrument_struct_i -> i_instr_code,strlen(p_mt_flrate_instrument_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DAILY_COMPOUND",p_mt_flrate_instrument_struct_h -> h_daily_compound,l_mt_flrate_instrument_struct_i -> i_daily_compound,strlen(p_mt_flrate_instrument_struct_h -> h_daily_compound),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCL_HOLIDAYS",p_mt_flrate_instrument_struct_h -> h_excl_holidays,l_mt_flrate_instrument_struct_i -> i_excl_holidays,strlen(p_mt_flrate_instrument_struct_h -> h_excl_holidays),1);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INT_PAY_DAYS",p_mt_flrate_instrument_struct_h -> h_int_pay_days,l_mt_flrate_instrument_struct_i -> i_int_pay_days);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COMPOUNDING_WDAYS",p_mt_flrate_instrument_struct_h -> h_compounding_wdays,l_mt_flrate_instrument_struct_i -> i_compounding_wdays,strlen(p_mt_flrate_instrument_struct_h -> h_compounding_wdays),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FLOOR_RATE",p_mt_flrate_instrument_struct_h -> h_floor_rate,l_mt_flrate_instrument_struct_i -> i_floor_rate);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CAP_RATE",p_mt_flrate_instrument_struct_h -> h_cap_rate,l_mt_flrate_instrument_struct_i -> i_cap_rate);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PREFD_SEQ",p_mt_flrate_instrument_struct_h -> h_prefd_seq,l_mt_flrate_instrument_struct_i -> i_prefd_seq,strlen(p_mt_flrate_instrument_struct_h -> h_prefd_seq),14);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEFAULT_FLOAT_RATE",p_mt_flrate_instrument_struct_h -> h_default_float_rate,l_mt_flrate_instrument_struct_i -> i_default_float_rate,strlen(p_mt_flrate_instrument_struct_h -> h_default_float_rate),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BENCHMARK_CODE",p_mt_flrate_instrument_struct_h -> h_benchmark_code,l_mt_flrate_instrument_struct_i -> i_benchmark_code,strlen(p_mt_flrate_instrument_struct_h -> h_benchmark_code),8);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","BASE_MARGIN",p_mt_flrate_instrument_struct_h -> h_base_margin,l_mt_flrate_instrument_struct_i -> i_base_margin);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FIXED_BENCH",p_mt_flrate_instrument_struct_h -> h_fixed_bench,l_mt_flrate_instrument_struct_i -> i_fixed_bench,strlen(p_mt_flrate_instrument_struct_h -> h_fixed_bench),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_flrate_instrument_struct_h -> h_maker,l_mt_flrate_instrument_struct_i -> i_maker,strlen(p_mt_flrate_instrument_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_flrate_instrument_struct_h -> h_maker_dt,l_mt_flrate_instrument_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_flrate_instrument_struct_h -> h_access_stamp,l_mt_flrate_instrument_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_flrate_instrument_struct_h -> h_checker,l_mt_flrate_instrument_struct_i -> i_checker,strlen(p_mt_flrate_instrument_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_flrate_instrument_struct_h -> h_checker_dt,l_mt_flrate_instrument_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_flrate_instrument_struct_h -> h_status,l_mt_flrate_instrument_struct_i -> i_status,strlen(p_mt_flrate_instrument_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_flrate_instrument_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_flrate_instrument_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_PARTY(MT_PARTY_STRUCT_H *p_mt_party_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_PARTY_STRUCT_I *l_mt_party_struct_i = (MT_PARTY_STRUCT_I *)NULL;

	l_mt_party_struct_i = (MT_PARTY_STRUCT_I *)calloc(1,sizeof(MT_PARTY_STRUCT_I));



	if(!strlen(p_mt_party_struct_h ->h_pty_code))
		l_mt_party_struct_i -> i_pty_code= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_name))
		l_mt_party_struct_i -> i_pty_name= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_shortnm))
		l_mt_party_struct_i -> i_pty_shortnm= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_mapinid))
		l_mt_party_struct_i -> i_pty_mapinid= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_type))
		l_mt_party_struct_i -> i_pty_type= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_add1))
		l_mt_party_struct_i -> i_pty_add1= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_add2))
		l_mt_party_struct_i -> i_pty_add2= -1;
	if(!strlen(p_mt_party_struct_h ->h_city))
		l_mt_party_struct_i -> i_city= -1;
	if(!strlen(p_mt_party_struct_h ->h_state))
		l_mt_party_struct_i -> i_state= -1;
	if(!strlen(p_mt_party_struct_h ->h_country))
		l_mt_party_struct_i -> i_country= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_add_pin))
		l_mt_party_struct_i -> i_pty_add_pin= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_tel))
		l_mt_party_struct_i -> i_pty_tel= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_fax))
		l_mt_party_struct_i -> i_pty_fax= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_email))
		l_mt_party_struct_i -> i_pty_email= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_contact1))
		l_mt_party_struct_i -> i_pty_contact1= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_contact2))
		l_mt_party_struct_i -> i_pty_contact2= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_swf_name))
		l_mt_party_struct_i -> i_pty_swf_name= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_swf_add))
		l_mt_party_struct_i -> i_pty_swf_add= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_pan))
		l_mt_party_struct_i -> i_pty_pan= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_lc_name))
		l_mt_party_struct_i -> i_pty_lc_name= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_lc_add))
		l_mt_party_struct_i -> i_pty_lc_add= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_lc_tel))
		l_mt_party_struct_i -> i_pty_lc_tel= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_lc_email))
		l_mt_party_struct_i -> i_pty_lc_email= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_lc_fax))
		l_mt_party_struct_i -> i_pty_lc_fax= -1;
	if(!strlen(p_mt_party_struct_h ->h_maker))
		l_mt_party_struct_i -> i_maker= -1;
	if(!strlen(p_mt_party_struct_h ->h_maker_dt))
		l_mt_party_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_party_struct_h ->h_access_stamp))
		l_mt_party_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_party_struct_h ->h_checker))
		l_mt_party_struct_i -> i_checker= -1;
	if(!strlen(p_mt_party_struct_h ->h_checker_dt))
		l_mt_party_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_party_struct_h ->h_status))
		l_mt_party_struct_i -> i_status= -1;
	if(!strlen(p_mt_party_struct_h ->h_pty_bic_code))
		l_mt_party_struct_i -> i_pty_bic_code= -1;


	/* EXEC SQL INSERT INTO MT_PARTY VALUES(:p_mt_party_struct_h:l_mt_party_struct_i); */ 
#line 1218 "DM_DbInterface.pc"

{
#line 1218 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1218 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1218 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PARTY  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8\
 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s2\
4 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,:s39:\
s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54 ,:s5\
5:s56 ,:s57:s58 ,:s59:s60 ,:s61:s62 )";
#line 1218 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1218 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1299;
#line 1218 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1218 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_party_struct_h->h_pty_code;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_party_struct_i->i_pty_code;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_party_struct_h->h_pty_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )66;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_party_struct_i->i_pty_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_party_struct_h->h_pty_shortnm;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )13;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_party_struct_i->i_pty_shortnm;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_party_struct_h->h_pty_mapinid;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )13;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_party_struct_i->i_pty_mapinid;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_party_struct_h->h_pty_type;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )2;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_party_struct_i->i_pty_type;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_party_struct_h->h_pty_add1;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )61;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_party_struct_i->i_pty_add1;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_party_struct_h->h_pty_add2;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )61;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_party_struct_i->i_pty_add2;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_party_struct_h->h_city;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_party_struct_i->i_city;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_party_struct_h->h_state;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_party_struct_i->i_state;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_party_struct_h->h_country;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_party_struct_i->i_country;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_party_struct_h->h_pty_add_pin;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )11;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_party_struct_i->i_pty_add_pin;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_party_struct_h->h_pty_tel;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_party_struct_i->i_pty_tel;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_party_struct_h->h_pty_fax;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_party_struct_i->i_pty_fax;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_party_struct_h->h_pty_email;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )61;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_party_struct_i->i_pty_email;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_party_struct_h->h_pty_contact1;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )66;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_party_struct_i->i_pty_contact1;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_party_struct_h->h_pty_contact2;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )66;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_party_struct_i->i_pty_contact2;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_party_struct_h->h_pty_swf_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_party_struct_i->i_pty_swf_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_mt_party_struct_h->h_pty_swf_add;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )12;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_party_struct_i->i_pty_swf_add;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)p_mt_party_struct_h->h_pty_pan;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_mt_party_struct_i->i_pty_pan;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)p_mt_party_struct_h->h_pty_lc_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )66;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_mt_party_struct_i->i_pty_lc_name;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)p_mt_party_struct_h->h_pty_lc_add;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )201;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_mt_party_struct_i->i_pty_lc_add;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[21] = (unsigned char  *)p_mt_party_struct_h->h_pty_lc_tel;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[21] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[21] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[21] = (         short *)&l_mt_party_struct_i->i_pty_lc_tel;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[21] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[21] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[21] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[21] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[22] = (unsigned char  *)p_mt_party_struct_h->h_pty_lc_email;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[22] = (unsigned long )61;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[22] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[22] = (         short *)&l_mt_party_struct_i->i_pty_lc_email;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[22] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[22] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[22] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[22] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[23] = (unsigned char  *)p_mt_party_struct_h->h_pty_lc_fax;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[23] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[23] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[23] = (         short *)&l_mt_party_struct_i->i_pty_lc_fax;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[23] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[23] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[23] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[23] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[24] = (unsigned char  *)p_mt_party_struct_h->h_maker;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[24] = (unsigned long )15;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[24] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[24] = (         short *)&l_mt_party_struct_i->i_maker;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[24] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[24] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[24] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[24] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[25] = (unsigned char  *)p_mt_party_struct_h->h_maker_dt;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[25] = (unsigned long )20;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[25] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[25] = (         short *)&l_mt_party_struct_i->i_maker_dt;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[25] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[25] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[25] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[25] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[26] = (unsigned char  *)p_mt_party_struct_h->h_access_stamp;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[26] = (unsigned long )20;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[26] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[26] = (         short *)&l_mt_party_struct_i->i_access_stamp;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[26] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[26] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[26] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[26] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[27] = (unsigned char  *)p_mt_party_struct_h->h_checker;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[27] = (unsigned long )21;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[27] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[27] = (         short *)&l_mt_party_struct_i->i_checker;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[27] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[27] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[27] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[27] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[28] = (unsigned char  *)p_mt_party_struct_h->h_checker_dt;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[28] = (unsigned long )20;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[28] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[28] = (         short *)&l_mt_party_struct_i->i_checker_dt;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[28] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[28] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[28] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[28] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[29] = (unsigned char  *)p_mt_party_struct_h->h_status;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[29] = (unsigned long )3;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[29] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[29] = (         short *)&l_mt_party_struct_i->i_status;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[29] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[29] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[29] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[29] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstv[30] = (unsigned char  *)p_mt_party_struct_h->h_pty_bic_code;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhstl[30] = (unsigned long )14;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqhsts[30] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqindv[30] = (         short *)&l_mt_party_struct_i->i_pty_bic_code;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqinds[30] = (         int  )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqharm[30] = (unsigned long )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqadto[30] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqtdso[30] = (unsigned short )0;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1218 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1218 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1218 "DM_DbInterface.pc"
}

#line 1218 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CODE",p_mt_party_struct_h -> h_pty_code,l_mt_party_struct_i -> i_pty_code,strlen(p_mt_party_struct_h -> h_pty_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_NAME",p_mt_party_struct_h -> h_pty_name,l_mt_party_struct_i -> i_pty_name,strlen(p_mt_party_struct_h -> h_pty_name),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SHORTNM",p_mt_party_struct_h -> h_pty_shortnm,l_mt_party_struct_i -> i_pty_shortnm,strlen(p_mt_party_struct_h -> h_pty_shortnm),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_MAPINID",p_mt_party_struct_h -> h_pty_mapinid,l_mt_party_struct_i -> i_pty_mapinid,strlen(p_mt_party_struct_h -> h_pty_mapinid),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_TYPE",p_mt_party_struct_h -> h_pty_type,l_mt_party_struct_i -> i_pty_type,strlen(p_mt_party_struct_h -> h_pty_type),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_ADD1",p_mt_party_struct_h -> h_pty_add1,l_mt_party_struct_i -> i_pty_add1,strlen(p_mt_party_struct_h -> h_pty_add1),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_ADD2",p_mt_party_struct_h -> h_pty_add2,l_mt_party_struct_i -> i_pty_add2,strlen(p_mt_party_struct_h -> h_pty_add2),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CITY",p_mt_party_struct_h -> h_city,l_mt_party_struct_i -> i_city,strlen(p_mt_party_struct_h -> h_city),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATE",p_mt_party_struct_h -> h_state,l_mt_party_struct_i -> i_state,strlen(p_mt_party_struct_h -> h_state),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COUNTRY",p_mt_party_struct_h -> h_country,l_mt_party_struct_i -> i_country,strlen(p_mt_party_struct_h -> h_country),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_ADD_PIN",p_mt_party_struct_h -> h_pty_add_pin,l_mt_party_struct_i -> i_pty_add_pin,strlen(p_mt_party_struct_h -> h_pty_add_pin),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_TEL",p_mt_party_struct_h -> h_pty_tel,l_mt_party_struct_i -> i_pty_tel,strlen(p_mt_party_struct_h -> h_pty_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_FAX",p_mt_party_struct_h -> h_pty_fax,l_mt_party_struct_i -> i_pty_fax,strlen(p_mt_party_struct_h -> h_pty_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_EMAIL",p_mt_party_struct_h -> h_pty_email,l_mt_party_struct_i -> i_pty_email,strlen(p_mt_party_struct_h -> h_pty_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CONTACT1",p_mt_party_struct_h -> h_pty_contact1,l_mt_party_struct_i -> i_pty_contact1,strlen(p_mt_party_struct_h -> h_pty_contact1),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CONTACT2",p_mt_party_struct_h -> h_pty_contact2,l_mt_party_struct_i -> i_pty_contact2,strlen(p_mt_party_struct_h -> h_pty_contact2),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SWF_NAME",p_mt_party_struct_h -> h_pty_swf_name,l_mt_party_struct_i -> i_pty_swf_name,strlen(p_mt_party_struct_h -> h_pty_swf_name),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SWF_ADD",p_mt_party_struct_h -> h_pty_swf_add,l_mt_party_struct_i -> i_pty_swf_add,strlen(p_mt_party_struct_h -> h_pty_swf_add),11);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_PAN",p_mt_party_struct_h -> h_pty_pan,l_mt_party_struct_i -> i_pty_pan,strlen(p_mt_party_struct_h -> h_pty_pan),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_LC_NAME",p_mt_party_struct_h -> h_pty_lc_name,l_mt_party_struct_i -> i_pty_lc_name,strlen(p_mt_party_struct_h -> h_pty_lc_name),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_LC_ADD",p_mt_party_struct_h -> h_pty_lc_add,l_mt_party_struct_i -> i_pty_lc_add,strlen(p_mt_party_struct_h -> h_pty_lc_add),200);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_LC_TEL",p_mt_party_struct_h -> h_pty_lc_tel,l_mt_party_struct_i -> i_pty_lc_tel,strlen(p_mt_party_struct_h -> h_pty_lc_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_LC_EMAIL",p_mt_party_struct_h -> h_pty_lc_email,l_mt_party_struct_i -> i_pty_lc_email,strlen(p_mt_party_struct_h -> h_pty_lc_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_LC_FAX",p_mt_party_struct_h -> h_pty_lc_fax,l_mt_party_struct_i -> i_pty_lc_fax,strlen(p_mt_party_struct_h -> h_pty_lc_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_party_struct_h -> h_maker,l_mt_party_struct_i -> i_maker,strlen(p_mt_party_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_party_struct_h -> h_maker_dt,l_mt_party_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_party_struct_h -> h_access_stamp,l_mt_party_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_party_struct_h -> h_checker,l_mt_party_struct_i -> i_checker,strlen(p_mt_party_struct_h -> h_checker),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_party_struct_h -> h_checker_dt,l_mt_party_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_party_struct_h -> h_status,l_mt_party_struct_i -> i_status,strlen(p_mt_party_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_BIC_CODE",p_mt_party_struct_h -> h_pty_bic_code,l_mt_party_struct_i -> i_pty_bic_code,strlen(p_mt_party_struct_h -> h_pty_bic_code),13);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_party_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_party_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

/* ADD BY ASP, PARTY FUND DETAILS - 07SEP-06*/

int MT_UpdMT_PTY_FUND_DET(MT_PTY_FUND_DET_STRUCT_H *p_mt_pty_fund_det_struct_h,DEBUG_INFO_STRUCT_H **l_debug_info_ptr)
{
     struct sqlca sqlca;
     MT_PTY_FUND_DET_STRUCT_I *l_mt_pty_fund_det_struct_i = (MT_PTY_FUND_DET_STRUCT_I *)NULL;

     l_mt_pty_fund_det_struct_i = (MT_PTY_FUND_DET_STRUCT_I *)calloc(1,sizeof(MT_PTY_FUND_DET_STRUCT_I));


   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pty_code))
	l_mt_pty_fund_det_struct_i -> i_pty_code = -1;
   /*
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pay_in_day))
	p_mt_pty_fund_det_struct_h -> i_pay_in_day = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pay_out_day))
	p_mt_pty_fund_det_struct_h -> i_pay_out_day = -1;
   */
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_acc_typ))
	l_mt_pty_fund_det_struct_i -> i_acc_typ = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pay_in_acc))
	l_mt_pty_fund_det_struct_i -> i_pay_in_acc = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pay_out_acc))
	l_mt_pty_fund_det_struct_i -> i_pay_out_acc = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_acc_code1))
	l_mt_pty_fund_det_struct_i -> i_acc_code1 = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_acc_code2))
	l_mt_pty_fund_det_struct_i -> i_acc_code2 = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_acc_code2desc))
	l_mt_pty_fund_det_struct_i -> i_acc_code2desc = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_access_stamp))
	l_mt_pty_fund_det_struct_i -> i_access_stamp = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_maker))
	l_mt_pty_fund_det_struct_i -> i_maker = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_maker_dt))
	l_mt_pty_fund_det_struct_i -> i_maker_dt = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_checker))
	l_mt_pty_fund_det_struct_i -> i_checker = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_checker_dt))
	l_mt_pty_fund_det_struct_i -> i_checker_dt = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_status))
	l_mt_pty_fund_det_struct_i -> i_status = -1;
   if(!strlen(p_mt_pty_fund_det_struct_h -> h_pty_bnk_acc))
	l_mt_pty_fund_det_struct_i -> i_pty_bnk_acc = -1;

    /* EXEC SQL INSERT INTO MT_PTY_FUND_DET VALUES(:p_mt_pty_fund_det_struct_h:l_mt_pty_fund_det_struct_i); */ 
#line 1314 "DM_DbInterface.pc"

{
#line 1314 "DM_DbInterface.pc"
    struct sqlexd sqlstm;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqlvsn = 12;
#line 1314 "DM_DbInterface.pc"
    sqlstm.arrsiz = 82;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqladtp = &sqladt;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1314 "DM_DbInterface.pc"
    sqlstm.stmt = "insert into MT_PTY_FUND_DET  values (:s1:s2 ,:s3:s4 ,:s5:\
s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s2\
2 ,:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 )";
#line 1314 "DM_DbInterface.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1314 "DM_DbInterface.pc"
    sqlstm.offset = (unsigned int  )1438;
#line 1314 "DM_DbInterface.pc"
    sqlstm.cud = sqlcud0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1314 "DM_DbInterface.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_pty_code;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[0] = (unsigned long )11;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[0] = (         short *)&l_mt_pty_fund_det_struct_i->i_pty_code;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[0] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_pty_fund_det_struct_h->h_pay_in_day;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[1] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[1] = (         short *)&l_mt_pty_fund_det_struct_i->i_pay_in_day;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[1] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[1] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[1] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[1] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[2] = (unsigned char  *)&p_mt_pty_fund_det_struct_h->h_pay_out_day;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[2] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[2] = (         short *)&l_mt_pty_fund_det_struct_i->i_pay_out_day;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[2] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[2] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[2] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[2] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_acc_typ;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[3] = (unsigned long )2;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[3] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[3] = (         short *)&l_mt_pty_fund_det_struct_i->i_acc_typ;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[3] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[3] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[3] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[3] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_pay_in_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[4] = (unsigned long )24;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[4] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[4] = (         short *)&l_mt_pty_fund_det_struct_i->i_pay_in_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[4] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[4] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[4] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[4] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_pay_out_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[5] = (unsigned long )24;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[5] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[5] = (         short *)&l_mt_pty_fund_det_struct_i->i_pay_out_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[5] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[5] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[5] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[5] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_acc_code1;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[6] = (unsigned long )24;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[6] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[6] = (         short *)&l_mt_pty_fund_det_struct_i->i_acc_code1;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[6] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[6] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[6] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[6] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_acc_code2;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[7] = (unsigned long )24;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[7] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[7] = (         short *)&l_mt_pty_fund_det_struct_i->i_acc_code2;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[7] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[7] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[7] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[7] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_acc_code2desc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[8] = (unsigned long )66;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[8] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[8] = (         short *)&l_mt_pty_fund_det_struct_i->i_acc_code2desc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[8] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[8] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[8] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[8] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_access_stamp;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[9] = (unsigned long )20;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[9] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[9] = (         short *)&l_mt_pty_fund_det_struct_i->i_access_stamp;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[9] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[9] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[9] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[9] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[10] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_maker;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[10] = (unsigned long )15;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[10] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[10] = (         short *)&l_mt_pty_fund_det_struct_i->i_maker;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[10] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[10] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[10] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[10] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[11] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_maker_dt;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[11] = (unsigned long )20;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[11] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[11] = (         short *)&l_mt_pty_fund_det_struct_i->i_maker_dt;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[11] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[11] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[11] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[11] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[12] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_checker;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[12] = (unsigned long )15;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[12] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[12] = (         short *)&l_mt_pty_fund_det_struct_i->i_checker;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[12] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[12] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[12] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[12] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[13] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_checker_dt;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[13] = (unsigned long )20;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[13] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[13] = (         short *)&l_mt_pty_fund_det_struct_i->i_checker_dt;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[13] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[13] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[13] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[13] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[14] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_status;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[14] = (unsigned long )3;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[14] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[14] = (         short *)&l_mt_pty_fund_det_struct_i->i_status;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[14] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[14] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[14] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[14] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstv[15] = (unsigned char  *)p_mt_pty_fund_det_struct_h->h_pty_bnk_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhstl[15] = (unsigned long )24;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqhsts[15] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqindv[15] = (         short *)&l_mt_pty_fund_det_struct_i->i_pty_bnk_acc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqinds[15] = (         int  )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqharm[15] = (unsigned long )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqadto[15] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqtdso[15] = (unsigned short )0;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1314 "DM_DbInterface.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1314 "DM_DbInterface.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1314 "DM_DbInterface.pc"
}

#line 1314 "DM_DbInterface.pc"


   IS_ANY_ORA_ERROR
      RETURN_SUCCESS:

      APL_FREE(l_mt_pty_fund_det_struct_i);

   APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

      RETURN_FAILURE:

      APL_FREE(l_mt_pty_fund_det_struct_i);

   APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)
}

/* END OF PARTY FUND*/


int MT_UpdMT_PTY_BANKDET(MT_PTY_BANKDET_STRUCT_H *p_mt_pty_bankdet_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{

	struct sqlca sqlca;

	MT_PTY_BANKDET_STRUCT_I *l_mt_pty_bankdet_struct_i = (MT_PTY_BANKDET_STRUCT_I *)NULL;

	l_mt_pty_bankdet_struct_i = (MT_PTY_BANKDET_STRUCT_I *)calloc(1,sizeof(MT_PTY_BANKDET_STRUCT_I));



	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_code))
		l_mt_pty_bankdet_struct_i -> i_pty_code= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_bank_acc))
		l_mt_pty_bankdet_struct_i -> i_pty_bank_acc= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_main_acc))
		l_mt_pty_bankdet_struct_i -> i_pty_main_acc= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_bank_sys_code))
		l_mt_pty_bankdet_struct_i -> i_pty_bank_sys_code= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_sub_cat))
		l_mt_pty_bankdet_struct_i -> i_pty_sub_cat= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_acc_typ))
		l_mt_pty_bankdet_struct_i -> i_pty_acc_typ= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_pty_isfc_micr))
		l_mt_pty_bankdet_struct_i -> i_pty_isfc_micr= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_access_stamp))
		l_mt_pty_bankdet_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_maker))
		l_mt_pty_bankdet_struct_i -> i_maker= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_maker_dt))
		l_mt_pty_bankdet_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_checker))
		l_mt_pty_bankdet_struct_i -> i_checker= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_checker_dt))
		l_mt_pty_bankdet_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_pty_bankdet_struct_h ->h_status))
		l_mt_pty_bankdet_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_PTY_BANKDET VALUES(:p_mt_pty_bankdet_struct_h:l_mt_pty_bankdet_struct_i); */ 
#line 1372 "DM_DbInterface.pc"

{
#line 1372 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1372 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1372 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PTY_BANKDET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,\
:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:\
s23:s24 ,:s25:s26 )";
#line 1372 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1372 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1517;
#line 1372 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1372 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_code;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_code;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_bank_acc;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )16;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_bank_acc;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_main_acc;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )16;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_main_acc;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_bank_sys_code;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )4;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_bank_sys_code;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_sub_cat;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )4;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_sub_cat;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_acc_typ;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )4;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_acc_typ;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_pty_isfc_micr;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )16;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_pty_bankdet_struct_i->i_pty_isfc_micr;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_access_stamp;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_pty_bankdet_struct_i->i_access_stamp;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_maker;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )15;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_pty_bankdet_struct_i->i_maker;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_maker_dt;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_pty_bankdet_struct_i->i_maker_dt;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_checker;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )21;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_pty_bankdet_struct_i->i_checker;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_checker_dt;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_pty_bankdet_struct_i->i_checker_dt;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_pty_bankdet_struct_h->h_status;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )3;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_pty_bankdet_struct_i->i_status;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1372 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1372 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1372 "DM_DbInterface.pc"
}

#line 1372 "DM_DbInterface.pc"


		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CODE",p_mt_pty_bankdet_struct_h -> h_pty_code,l_mt_pty_bankdet_struct_i -> i_pty_code,strlen(p_mt_pty_bankdet_struct_h -> h_pty_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_BANK_ACC",p_mt_pty_bankdet_struct_h -> h_pty_bank_acc,l_mt_pty_bankdet_struct_i -> i_pty_bank_acc,strlen(p_mt_pty_bankdet_struct_h -> h_pty_bank_acc),15);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_MAIN_ACC",p_mt_pty_bankdet_struct_h -> h_pty_main_acc,l_mt_pty_bankdet_struct_i -> i_pty_main_acc,strlen(p_mt_pty_bankdet_struct_h -> h_pty_main_acc),15);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_BANK_SYS_CODE",p_mt_pty_bankdet_struct_h -> h_pty_bank_sys_code,l_mt_pty_bankdet_struct_i -> i_pty_bank_sys_code,strlen(p_mt_pty_bankdet_struct_h -> h_pty_bank_sys_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SUB_CAT",p_mt_pty_bankdet_struct_h -> h_pty_sub_cat,l_mt_pty_bankdet_struct_i -> i_pty_sub_cat,strlen(p_mt_pty_bankdet_struct_h -> h_pty_sub_cat),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_ACC_TYP",p_mt_pty_bankdet_struct_h -> h_pty_acc_typ,l_mt_pty_bankdet_struct_i -> i_pty_acc_typ,strlen(p_mt_pty_bankdet_struct_h -> h_pty_acc_typ),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_ISFC_MICR",p_mt_pty_bankdet_struct_h -> h_pty_isfc_micr,l_mt_pty_bankdet_struct_i -> i_pty_isfc_micr,strlen(p_mt_pty_bankdet_struct_h -> h_pty_isfc_micr),15);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_pty_bankdet_struct_h -> h_access_stamp,l_mt_pty_bankdet_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_pty_bankdet_struct_h -> h_maker,l_mt_pty_bankdet_struct_i -> i_maker,strlen(p_mt_pty_bankdet_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_pty_bankdet_struct_h -> h_maker_dt,l_mt_pty_bankdet_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_pty_bankdet_struct_h -> h_checker,l_mt_pty_bankdet_struct_i -> i_checker,strlen(p_mt_pty_bankdet_struct_h -> h_checker),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_pty_bankdet_struct_h -> h_checker_dt,l_mt_pty_bankdet_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_pty_bankdet_struct_h -> h_status,l_mt_pty_bankdet_struct_i -> i_status,strlen(p_mt_pty_bankdet_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_pty_bankdet_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_pty_bankdet_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_INSTR_EXCH_DET(MT_INSTR_EXCH_DET_STRUCT_H *p_mt_instr_exch_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_INSTR_EXCH_DET_STRUCT_I *l_mt_instr_exch_det_struct_i = (MT_INSTR_EXCH_DET_STRUCT_I *)NULL;

	l_mt_instr_exch_det_struct_i = (MT_INSTR_EXCH_DET_STRUCT_I *)calloc(1,sizeof(MT_INSTR_EXCH_DET_STRUCT_I));



	if(!strlen(p_mt_instr_exch_det_struct_h ->h_instr_code))
		l_mt_instr_exch_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_instr_exch_det_struct_h ->h_exch_code))
		l_mt_instr_exch_det_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_scrip_grp))
		l_mt_instr_exch_det_struct_i -> i_scrip_grp= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_mkt_type))
		l_mt_instr_exch_det_struct_i -> i_mkt_type= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_exch_instr_code))
		l_mt_instr_exch_det_struct_i -> i_exch_instr_code= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_listing_status))
		l_mt_instr_exch_det_struct_i -> i_listing_status= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_listing_date))
		l_mt_instr_exch_det_struct_i -> i_listing_date= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_access_stamp))
		l_mt_instr_exch_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_maker))
		l_mt_instr_exch_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_maker_dt))
		l_mt_instr_exch_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_checker))
		l_mt_instr_exch_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_checker_dt))
		l_mt_instr_exch_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_instr_exch_det_struct_h ->h_status))
		l_mt_instr_exch_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_INSTR_EXCH_DET VALUES(:p_mt_instr_exch_det_struct_h:l_mt_instr_exch_det_struct_i); */ 
#line 1443 "DM_DbInterface.pc"

{
#line 1443 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1443 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1443 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_INSTR_EXCH_DET  values (:s1:s2 ,:s3:s4 ,:s5:s\
6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22\
 ,:s23:s24 ,:s25:s26 ,:s27:s28 )";
#line 1443 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1443 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1584;
#line 1443 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1443 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_instr_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_instr_exch_det_struct_i->i_instr_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_instr_exch_det_struct_h->h_instr_seq_num;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_instr_exch_det_struct_i->i_instr_seq_num;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_exch_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )4;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_instr_exch_det_struct_i->i_exch_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_scrip_grp;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )3;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_instr_exch_det_struct_i->i_scrip_grp;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_mkt_type;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )3;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_instr_exch_det_struct_i->i_mkt_type;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_exch_instr_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )13;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_instr_exch_det_struct_i->i_exch_instr_code;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_listing_status;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )4;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_instr_exch_det_struct_i->i_listing_status;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_listing_date;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_instr_exch_det_struct_i->i_listing_date;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_access_stamp;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_instr_exch_det_struct_i->i_access_stamp;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_maker;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_instr_exch_det_struct_i->i_maker;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_maker_dt;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_instr_exch_det_struct_i->i_maker_dt;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_checker;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )15;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_instr_exch_det_struct_i->i_checker;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_checker_dt;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_instr_exch_det_struct_i->i_checker_dt;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_instr_exch_det_struct_h->h_status;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )3;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_instr_exch_det_struct_i->i_status;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1443 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1443 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1443 "DM_DbInterface.pc"
}

#line 1443 "DM_DbInterface.pc"


		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_instr_exch_det_struct_h -> h_instr_code,l_mt_instr_exch_det_struct_i -> i_instr_code,strlen(p_mt_instr_exch_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_instr_exch_det_struct_h -> h_instr_seq_num,l_mt_instr_exch_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_instr_exch_det_struct_h -> h_exch_code,l_mt_instr_exch_det_struct_i -> i_exch_code,strlen(p_mt_instr_exch_det_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SCRIP_GRP",p_mt_instr_exch_det_struct_h -> h_scrip_grp,l_mt_instr_exch_det_struct_i -> i_scrip_grp,strlen(p_mt_instr_exch_det_struct_h -> h_scrip_grp),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MKT_TYPE",p_mt_instr_exch_det_struct_h -> h_mkt_type,l_mt_instr_exch_det_struct_i -> i_mkt_type,strlen(p_mt_instr_exch_det_struct_h -> h_mkt_type),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_INSTR_CODE",p_mt_instr_exch_det_struct_h -> h_exch_instr_code,l_mt_instr_exch_det_struct_i -> i_exch_instr_code,strlen(p_mt_instr_exch_det_struct_h -> h_exch_instr_code),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LISTING_STATUS",p_mt_instr_exch_det_struct_h -> h_listing_status,l_mt_instr_exch_det_struct_i -> i_listing_status,strlen(p_mt_instr_exch_det_struct_h -> h_listing_status),3);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LISTING_DATE",p_mt_instr_exch_det_struct_h -> h_listing_date,l_mt_instr_exch_det_struct_i -> i_listing_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_instr_exch_det_struct_h -> h_access_stamp,l_mt_instr_exch_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_instr_exch_det_struct_h -> h_maker,l_mt_instr_exch_det_struct_i -> i_maker,strlen(p_mt_instr_exch_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_instr_exch_det_struct_h -> h_maker_dt,l_mt_instr_exch_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_instr_exch_det_struct_h -> h_checker,l_mt_instr_exch_det_struct_i -> i_checker,strlen(p_mt_instr_exch_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_instr_exch_det_struct_h -> h_checker_dt,l_mt_instr_exch_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_instr_exch_det_struct_h -> h_status,l_mt_instr_exch_det_struct_i -> i_status,strlen(p_mt_instr_exch_det_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_instr_exch_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_instr_exch_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}



int MT_UpdCAENTITLEMENT(CAENTITLEMENT_STRUCT_H *p_caentitlement_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	CAENTITLEMENT_STRUCT_I *l_caentitlement_struct_i = (CAENTITLEMENT_STRUCT_I *)NULL;

	l_caentitlement_struct_i = (CAENTITLEMENT_STRUCT_I *)calloc(1,sizeof(CAENTITLEMENT_STRUCT_I));



	if(!strlen(p_caentitlement_struct_h ->h_corp_id))
		l_caentitlement_struct_i -> i_corp_id= -1;
	if(!strlen(p_caentitlement_struct_h ->h_client))
		l_caentitlement_struct_i -> i_client= -1;

	if(!strlen(p_caentitlement_struct_h ->h_ccy_for_entitl))
		l_caentitlement_struct_i -> i_ccy_for_entitl= -1;




	if(!strlen(p_caentitlement_struct_h ->h_nrep_date_b))
		l_caentitlement_struct_i -> i_nrep_date_b= -1;
	if(!strlen(p_caentitlement_struct_h ->h_nrep_date_c))
		l_caentitlement_struct_i -> i_nrep_date_c= -1;
	if(!strlen(p_caentitlement_struct_h ->h_dateforsend550))
		l_caentitlement_struct_i -> i_dateforsend550= -1;
	if(!strlen(p_caentitlement_struct_h ->h_status))
		l_caentitlement_struct_i -> i_status= -1;
	if(!strlen(p_caentitlement_struct_h ->h_processed_date))
		l_caentitlement_struct_i -> i_processed_date= -1;
	if(!strlen(p_caentitlement_struct_h ->h_maker))
		l_caentitlement_struct_i -> i_maker= -1;
	if(!strlen(p_caentitlement_struct_h ->h_maker_dt))
		l_caentitlement_struct_i -> i_maker_dt= -1;
	if(!strlen(p_caentitlement_struct_h ->h_checker))
		l_caentitlement_struct_i -> i_checker= -1;
	if(!strlen(p_caentitlement_struct_h ->h_checker_dt))
		l_caentitlement_struct_i -> i_checker_dt= -1;
	if(!strlen(p_caentitlement_struct_h ->h_access_stamp))
		l_caentitlement_struct_i -> i_access_stamp= -1;

	/* EXEC SQL INSERT INTO CAENTITLEMENT VALUES(:p_caentitlement_struct_h:l_caentitlement_struct_i); */ 
#line 1520 "DM_DbInterface.pc"

{
#line 1520 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1520 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1520 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into CAENTITLEMENT  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:\
s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s\
23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,\
:s39:s40 ,:s41:s42 )";
#line 1520 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1520 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1655;
#line 1520 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1520 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_caentitlement_struct_h->h_corp_id;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )21;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_caentitlement_struct_i->i_corp_id;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_caentitlement_struct_h->h_client;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )11;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_caentitlement_struct_i->i_client;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)&p_caentitlement_struct_h->h_elig_entitl_pos;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_caentitlement_struct_i->i_elig_entitl_pos;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_caentitlement_struct_h->h_ccy_for_entitl;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )4;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_caentitlement_struct_i->i_ccy_for_entitl;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_caentitlement_struct_h->h_instr_inc_bal;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_caentitlement_struct_i->i_instr_inc_bal;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_caentitlement_struct_h->h_received_amt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_caentitlement_struct_i->i_received_amt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)&p_caentitlement_struct_h->h_quantity_bal;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_caentitlement_struct_i->i_quantity_bal;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)&p_caentitlement_struct_h->h_quantity_received;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_caentitlement_struct_i->i_quantity_received;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_caentitlement_struct_h->h_nrep_date_b;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_caentitlement_struct_i->i_nrep_date_b;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_caentitlement_struct_h->h_nrep_date_c;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_caentitlement_struct_i->i_nrep_date_c;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_caentitlement_struct_h->h_dateforsend550;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_caentitlement_struct_i->i_dateforsend550;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_caentitlement_struct_h->h_status;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_caentitlement_struct_i->i_status;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_caentitlement_struct_h->h_processed_date;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_caentitlement_struct_i->i_processed_date;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_caentitlement_struct_h->h_maker;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )15;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_caentitlement_struct_i->i_maker;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_caentitlement_struct_h->h_maker_dt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_caentitlement_struct_i->i_maker_dt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_caentitlement_struct_h->h_checker;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )15;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_caentitlement_struct_i->i_checker;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_caentitlement_struct_h->h_checker_dt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_caentitlement_struct_i->i_checker_dt;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_caentitlement_struct_h->h_access_stamp;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )20;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_caentitlement_struct_i->i_access_stamp;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)&p_caentitlement_struct_h->h_custodytax_rate;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_caentitlement_struct_i->i_custodytax_rate;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)&p_caentitlement_struct_h->h_fract_due;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_caentitlement_struct_i->i_fract_due;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)&p_caentitlement_struct_h->h_fract_rcvd;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_caentitlement_struct_i->i_fract_rcvd;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1520 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1520 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1520 "DM_DbInterface.pc"
}

#line 1520 "DM_DbInterface.pc"



	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CORP_ID",p_caentitlement_struct_h -> h_corp_id,l_caentitlement_struct_i -> i_corp_id,strlen(p_caentitlement_struct_h -> h_corp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENT",p_caentitlement_struct_h -> h_client,l_caentitlement_struct_i -> i_client,strlen(p_caentitlement_struct_h -> h_client),10);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","ELIG_ENTITL_POS",p_caentitlement_struct_h -> h_elig_entitl_pos,l_caentitlement_struct_i -> i_elig_entitl_pos);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CCY_FOR_ENTITL",p_caentitlement_struct_h -> h_ccy_for_entitl,l_caentitlement_struct_i -> i_ccy_for_entitl,strlen(p_caentitlement_struct_h -> h_ccy_for_entitl),3);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","INSTR_INC_BAL",p_caentitlement_struct_h -> h_instr_inc_bal,l_caentitlement_struct_i -> i_instr_inc_bal);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","RECEIVED_AMT",p_caentitlement_struct_h -> h_received_amt,l_caentitlement_struct_i -> i_received_amt);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","QUANTITY_BAL",p_caentitlement_struct_h -> h_quantity_bal,l_caentitlement_struct_i -> i_quantity_bal);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","QUANTITY_RECEIVED",p_caentitlement_struct_h -> h_quantity_received,l_caentitlement_struct_i -> i_quantity_received);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NREP_DATE_B",p_caentitlement_struct_h -> h_nrep_date_b,l_caentitlement_struct_i -> i_nrep_date_b);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NREP_DATE_C",p_caentitlement_struct_h -> h_nrep_date_c,l_caentitlement_struct_i -> i_nrep_date_c);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEFORSEND550",p_caentitlement_struct_h -> h_dateforsend550,l_caentitlement_struct_i -> i_dateforsend550);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_caentitlement_struct_h -> h_status,l_caentitlement_struct_i -> i_status,strlen(p_caentitlement_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PROCESSED_DATE",p_caentitlement_struct_h -> h_processed_date,l_caentitlement_struct_i -> i_processed_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_caentitlement_struct_h -> h_maker,l_caentitlement_struct_i -> i_maker,strlen(p_caentitlement_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_caentitlement_struct_h -> h_maker_dt,l_caentitlement_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_caentitlement_struct_h -> h_checker,l_caentitlement_struct_i -> i_checker,strlen(p_caentitlement_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_caentitlement_struct_h -> h_checker_dt,l_caentitlement_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_caentitlement_struct_h -> h_access_stamp,l_caentitlement_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CUSTODYTAX_RATE",p_caentitlement_struct_h -> h_custodytax_rate,l_caentitlement_struct_i -> i_custodytax_rate);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FRACT_DUE",p_caentitlement_struct_h -> h_fract_due,l_caentitlement_struct_i -> i_fract_due);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FRACT_RCVD",p_caentitlement_struct_h -> h_fract_rcvd,l_caentitlement_struct_i -> i_fract_rcvd);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_caentitlement_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_caentitlement_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}




int MT_UpdMT_INSL_ENTRY(MT_INSL_ENTRY_STRUCT_H *p_mt_insl_entry_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_INSL_ENTRY_STRUCT_I *l_mt_insl_entry_struct_i = (MT_INSL_ENTRY_STRUCT_I *)NULL;

	l_mt_insl_entry_struct_i = (MT_INSL_ENTRY_STRUCT_I *)calloc(1,sizeof(MT_INSL_ENTRY_STRUCT_I));



	if(!strlen(p_mt_insl_entry_struct_h ->h_depo_code))
		l_mt_insl_entry_struct_i -> i_depo_code= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_depo_part_code))
		l_mt_insl_entry_struct_i -> i_depo_part_code= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_cln_code))
		l_mt_insl_entry_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_trans_type))
		l_mt_insl_entry_struct_i -> i_trans_type= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_slip_series))
		l_mt_insl_entry_struct_i -> i_slip_series= -1;



	if(!strlen(p_mt_insl_entry_struct_h ->h_maker))
		l_mt_insl_entry_struct_i -> i_maker= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_maker_dt))
		l_mt_insl_entry_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_access_stamp))
		l_mt_insl_entry_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_checker))
		l_mt_insl_entry_struct_i -> i_checker= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_checker_dt))
		l_mt_insl_entry_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_insl_entry_struct_h ->h_status))
		l_mt_insl_entry_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_INSL_ENTRY VALUES(:p_mt_insl_entry_struct_h:l_mt_insl_entry_struct_i); */ 
#line 1601 "DM_DbInterface.pc"

{
#line 1601 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1601 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1601 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_INSL_ENTRY  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:\
s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s\
23:s24 ,:s25:s26 ,:s27:s28 )";
#line 1601 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1601 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1754;
#line 1601 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1601 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_insl_entry_struct_h->h_depo_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )5;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_insl_entry_struct_i->i_depo_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_insl_entry_struct_h->h_depo_part_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )21;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_insl_entry_struct_i->i_depo_part_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_insl_entry_struct_h->h_cln_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )11;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_insl_entry_struct_i->i_cln_code;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_insl_entry_struct_h->h_trans_type;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )4;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_insl_entry_struct_i->i_trans_type;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_insl_entry_struct_h->h_slip_series;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )6;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_insl_entry_struct_i->i_slip_series;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_mt_insl_entry_struct_h->h_sr_no_from;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_insl_entry_struct_i->i_sr_no_from;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)&p_mt_insl_entry_struct_h->h_sr_no_to;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_insl_entry_struct_i->i_sr_no_to;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)&p_mt_insl_entry_struct_h->h_sr_avl_qty;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_insl_entry_struct_i->i_sr_avl_qty;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_insl_entry_struct_h->h_maker;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )15;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_insl_entry_struct_i->i_maker;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_insl_entry_struct_h->h_maker_dt;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_insl_entry_struct_i->i_maker_dt;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_insl_entry_struct_h->h_access_stamp;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_insl_entry_struct_i->i_access_stamp;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_insl_entry_struct_h->h_checker;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )15;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_insl_entry_struct_i->i_checker;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_insl_entry_struct_h->h_checker_dt;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_insl_entry_struct_i->i_checker_dt;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_insl_entry_struct_h->h_status;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )3;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_insl_entry_struct_i->i_status;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1601 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1601 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1601 "DM_DbInterface.pc"
}

#line 1601 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_CODE",p_mt_insl_entry_struct_h -> h_depo_code,l_mt_insl_entry_struct_i -> i_depo_code,strlen(p_mt_insl_entry_struct_h -> h_depo_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_CODE",p_mt_insl_entry_struct_h -> h_depo_part_code,l_mt_insl_entry_struct_i -> i_depo_part_code,strlen(p_mt_insl_entry_struct_h -> h_depo_part_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_insl_entry_struct_h -> h_cln_code,l_mt_insl_entry_struct_i -> i_cln_code,strlen(p_mt_insl_entry_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","TRANS_TYPE",p_mt_insl_entry_struct_h -> h_trans_type,l_mt_insl_entry_struct_i -> i_trans_type,strlen(p_mt_insl_entry_struct_h -> h_trans_type),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SLIP_SERIES",p_mt_insl_entry_struct_h -> h_slip_series,l_mt_insl_entry_struct_i -> i_slip_series,strlen(p_mt_insl_entry_struct_h -> h_slip_series),5);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","SR_NO_FROM",p_mt_insl_entry_struct_h -> h_sr_no_from,l_mt_insl_entry_struct_i -> i_sr_no_from);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","SR_NO_TO",p_mt_insl_entry_struct_h -> h_sr_no_to,l_mt_insl_entry_struct_i -> i_sr_no_to);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","SR_AVL_QTY",p_mt_insl_entry_struct_h -> h_sr_avl_qty,l_mt_insl_entry_struct_i -> i_sr_avl_qty);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_insl_entry_struct_h -> h_maker,l_mt_insl_entry_struct_i -> i_maker,strlen(p_mt_insl_entry_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_insl_entry_struct_h -> h_maker_dt,l_mt_insl_entry_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_insl_entry_struct_h -> h_access_stamp,l_mt_insl_entry_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_insl_entry_struct_h -> h_checker,l_mt_insl_entry_struct_i -> i_checker,strlen(p_mt_insl_entry_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_insl_entry_struct_h -> h_checker_dt,l_mt_insl_entry_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_insl_entry_struct_h -> h_status,l_mt_insl_entry_struct_i -> i_status,strlen(p_mt_insl_entry_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_insl_entry_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_insl_entry_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_CR_AGENCY(MT_CR_AGENCY_STRUCT_H *p_mt_cr_agency_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_CR_AGENCY_STRUCT_I *l_mt_cr_agency_struct_i = (MT_CR_AGENCY_STRUCT_I *)NULL;

	l_mt_cr_agency_struct_i = (MT_CR_AGENCY_STRUCT_I *)calloc(1,sizeof(MT_CR_AGENCY_STRUCT_I));



	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_code))
		l_mt_cr_agency_struct_i -> i_agency_code= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_name))
		l_mt_cr_agency_struct_i -> i_agency_name= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_add_1))
		l_mt_cr_agency_struct_i -> i_agency_add_1= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_add_2))
		l_mt_cr_agency_struct_i -> i_agency_add_2= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_city))
		l_mt_cr_agency_struct_i -> i_city= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_state))
		l_mt_cr_agency_struct_i -> i_state= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_country))
		l_mt_cr_agency_struct_i -> i_country= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_add_pin))
		l_mt_cr_agency_struct_i -> i_agency_add_pin= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_tel))
		l_mt_cr_agency_struct_i -> i_agency_tel= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_fax))
		l_mt_cr_agency_struct_i -> i_agency_fax= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_agency_email))
		l_mt_cr_agency_struct_i -> i_agency_email= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_maker))
		l_mt_cr_agency_struct_i -> i_maker= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_maker_dt))
		l_mt_cr_agency_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_access_stamp))
		l_mt_cr_agency_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_checker))
		l_mt_cr_agency_struct_i -> i_checker= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_checker_dt))
		l_mt_cr_agency_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_cr_agency_struct_h ->h_status))
		l_mt_cr_agency_struct_i -> i_status= -1;
	/* EXEC SQL INSERT INTO MT_CR_AGENCY VALUES(:p_mt_cr_agency_struct_h:l_mt_cr_agency_struct_i); */ 
#line 1680 "DM_DbInterface.pc"

{
#line 1680 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1680 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1680 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_CR_AGENCY  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s\
7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s2\
3:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 )";
#line 1680 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1680 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1825;
#line 1680 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1680 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_code;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_cr_agency_struct_i->i_agency_code;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_name;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )61;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_cr_agency_struct_i->i_agency_name;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_add_1;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )61;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_cr_agency_struct_i->i_agency_add_1;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_add_2;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )61;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_cr_agency_struct_i->i_agency_add_2;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_cr_agency_struct_h->h_city;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )4;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_cr_agency_struct_i->i_city;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_cr_agency_struct_h->h_state;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )3;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_cr_agency_struct_i->i_state;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_cr_agency_struct_h->h_country;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )3;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_cr_agency_struct_i->i_country;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_add_pin;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )11;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_cr_agency_struct_i->i_agency_add_pin;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_tel;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )21;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_cr_agency_struct_i->i_agency_tel;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_fax;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )21;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_cr_agency_struct_i->i_agency_fax;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_cr_agency_struct_h->h_agency_email;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )61;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_cr_agency_struct_i->i_agency_email;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_cr_agency_struct_h->h_maker;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )15;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_cr_agency_struct_i->i_maker;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_cr_agency_struct_h->h_maker_dt;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_cr_agency_struct_i->i_maker_dt;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_cr_agency_struct_h->h_access_stamp;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_cr_agency_struct_i->i_access_stamp;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_cr_agency_struct_h->h_checker;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )15;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_cr_agency_struct_i->i_checker;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_cr_agency_struct_h->h_checker_dt;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )20;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_cr_agency_struct_i->i_checker_dt;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_cr_agency_struct_h->h_status;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )3;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_cr_agency_struct_i->i_status;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1680 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1680 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1680 "DM_DbInterface.pc"
}

#line 1680 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_CODE",p_mt_cr_agency_struct_h -> h_agency_code,l_mt_cr_agency_struct_i -> i_agency_code,strlen(p_mt_cr_agency_struct_h -> h_agency_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_NAME",p_mt_cr_agency_struct_h -> h_agency_name,l_mt_cr_agency_struct_i -> i_agency_name,strlen(p_mt_cr_agency_struct_h -> h_agency_name),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_ADD_1",p_mt_cr_agency_struct_h -> h_agency_add_1,l_mt_cr_agency_struct_i -> i_agency_add_1,strlen(p_mt_cr_agency_struct_h -> h_agency_add_1),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_ADD_2",p_mt_cr_agency_struct_h -> h_agency_add_2,l_mt_cr_agency_struct_i -> i_agency_add_2,strlen(p_mt_cr_agency_struct_h -> h_agency_add_2),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CITY",p_mt_cr_agency_struct_h -> h_city,l_mt_cr_agency_struct_i -> i_city,strlen(p_mt_cr_agency_struct_h -> h_city),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATE",p_mt_cr_agency_struct_h -> h_state,l_mt_cr_agency_struct_i -> i_state,strlen(p_mt_cr_agency_struct_h -> h_state),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COUNTRY",p_mt_cr_agency_struct_h -> h_country,l_mt_cr_agency_struct_i -> i_country,strlen(p_mt_cr_agency_struct_h -> h_country),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_ADD_PIN",p_mt_cr_agency_struct_h -> h_agency_add_pin,l_mt_cr_agency_struct_i -> i_agency_add_pin,strlen(p_mt_cr_agency_struct_h -> h_agency_add_pin),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_TEL",p_mt_cr_agency_struct_h -> h_agency_tel,l_mt_cr_agency_struct_i -> i_agency_tel,strlen(p_mt_cr_agency_struct_h -> h_agency_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_FAX",p_mt_cr_agency_struct_h -> h_agency_fax,l_mt_cr_agency_struct_i -> i_agency_fax,strlen(p_mt_cr_agency_struct_h -> h_agency_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","AGENCY_EMAIL",p_mt_cr_agency_struct_h -> h_agency_email,l_mt_cr_agency_struct_i -> i_agency_email,strlen(p_mt_cr_agency_struct_h -> h_agency_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_cr_agency_struct_h -> h_maker,l_mt_cr_agency_struct_i -> i_maker,strlen(p_mt_cr_agency_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_cr_agency_struct_h -> h_maker_dt,l_mt_cr_agency_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_cr_agency_struct_h -> h_access_stamp,l_mt_cr_agency_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_cr_agency_struct_h -> h_checker,l_mt_cr_agency_struct_i -> i_checker,strlen(p_mt_cr_agency_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_cr_agency_struct_h -> h_checker_dt,l_mt_cr_agency_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_cr_agency_struct_h -> h_status,l_mt_cr_agency_struct_i -> i_status,strlen(p_mt_cr_agency_struct_h -> h_status),2);



	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_cr_agency_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_cr_agency_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_EXCH_DEPO(MT_EXCH_DEPO_STRUCT_H *p_mt_exch_depo_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_EXCH_DEPO_STRUCT_I *l_mt_exch_depo_struct_i = (MT_EXCH_DEPO_STRUCT_I *)NULL;

	l_mt_exch_depo_struct_i = (MT_EXCH_DEPO_STRUCT_I *)calloc(1,sizeof(MT_EXCH_DEPO_STRUCT_I));



	if(!strlen(p_mt_exch_depo_struct_h ->h_depo_code))
		l_mt_exch_depo_struct_i -> i_depo_code= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_depo_part_code))
		l_mt_exch_depo_struct_i -> i_depo_part_code= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_exch_code))
		l_mt_exch_depo_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_cc_id))
		l_mt_exch_depo_struct_i -> i_cc_id= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_cm_cc_id))
		l_mt_exch_depo_struct_i -> i_cm_cc_id= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_cln_id))
		l_mt_exch_depo_struct_i -> i_cln_id= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_dp_id))
		l_mt_exch_depo_struct_i -> i_dp_id= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_maker))
		l_mt_exch_depo_struct_i -> i_maker= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_maker_dt))
		l_mt_exch_depo_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_access_stamp))
		l_mt_exch_depo_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_checker))
		l_mt_exch_depo_struct_i -> i_checker= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_checker_dt))
		l_mt_exch_depo_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_exch_depo_struct_h ->h_status))
		l_mt_exch_depo_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_EXCH_DEPO VALUES(:p_mt_exch_depo_struct_h:l_mt_exch_depo_struct_i); */ 
#line 1757 "DM_DbInterface.pc"

{
#line 1757 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1757 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1757 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_EXCH_DEPO  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s\
7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s2\
3:s24 ,:s25:s26 )";
#line 1757 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1757 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1908;
#line 1757 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1757 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_exch_depo_struct_h->h_depo_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )5;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_exch_depo_struct_i->i_depo_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_exch_depo_struct_h->h_depo_part_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )21;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_exch_depo_struct_i->i_depo_part_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_exch_depo_struct_h->h_exch_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )4;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_exch_depo_struct_i->i_exch_code;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_exch_depo_struct_h->h_cc_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )9;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_exch_depo_struct_i->i_cc_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_exch_depo_struct_h->h_cm_cc_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )29;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_exch_depo_struct_i->i_cm_cc_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_exch_depo_struct_h->h_cln_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )14;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_exch_depo_struct_i->i_cln_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_exch_depo_struct_h->h_dp_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )21;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_exch_depo_struct_i->i_dp_id;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_exch_depo_struct_h->h_maker;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_exch_depo_struct_i->i_maker;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_exch_depo_struct_h->h_maker_dt;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_exch_depo_struct_i->i_maker_dt;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_exch_depo_struct_h->h_access_stamp;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_exch_depo_struct_i->i_access_stamp;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_exch_depo_struct_h->h_checker;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )15;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_exch_depo_struct_i->i_checker;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_exch_depo_struct_h->h_checker_dt;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_exch_depo_struct_i->i_checker_dt;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_exch_depo_struct_h->h_status;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )3;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_exch_depo_struct_i->i_status;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1757 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1757 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1757 "DM_DbInterface.pc"
}

#line 1757 "DM_DbInterface.pc"


	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_CODE",p_mt_exch_depo_struct_h -> h_depo_code,l_mt_exch_depo_struct_i -> i_depo_code,strlen(p_mt_exch_depo_struct_h -> h_depo_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_CODE",p_mt_exch_depo_struct_h -> h_depo_part_code,l_mt_exch_depo_struct_i -> i_depo_part_code,strlen(p_mt_exch_depo_struct_h -> h_depo_part_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_exch_depo_struct_h -> h_exch_code,l_mt_exch_depo_struct_i -> i_exch_code,strlen(p_mt_exch_depo_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CC_ID",p_mt_exch_depo_struct_h -> h_cc_id,l_mt_exch_depo_struct_i -> i_cc_id,strlen(p_mt_exch_depo_struct_h -> h_cc_id),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CM_CC_ID",p_mt_exch_depo_struct_h -> h_cm_cc_id,l_mt_exch_depo_struct_i -> i_cm_cc_id,strlen(p_mt_exch_depo_struct_h -> h_cm_cc_id),28);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ID",p_mt_exch_depo_struct_h -> h_cln_id,l_mt_exch_depo_struct_i -> i_cln_id,strlen(p_mt_exch_depo_struct_h -> h_cln_id),13);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DP_ID",p_mt_exch_depo_struct_h -> h_dp_id,l_mt_exch_depo_struct_i -> i_dp_id,strlen(p_mt_exch_depo_struct_h -> h_dp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_exch_depo_struct_h -> h_maker,l_mt_exch_depo_struct_i -> i_maker,strlen(p_mt_exch_depo_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_exch_depo_struct_h -> h_maker_dt,l_mt_exch_depo_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_exch_depo_struct_h -> h_access_stamp,l_mt_exch_depo_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_exch_depo_struct_h -> h_checker,l_mt_exch_depo_struct_i -> i_checker,strlen(p_mt_exch_depo_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_exch_depo_struct_h -> h_checker_dt,l_mt_exch_depo_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_exch_depo_struct_h -> h_status,l_mt_exch_depo_struct_i -> i_status,strlen(p_mt_exch_depo_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_exch_depo_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_exch_depo_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_RED_DP_DET(MT_RED_DP_DET_STRUCT_H *p_mt_red_dp_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_RED_DP_DET_STRUCT_I *l_mt_red_dp_det_struct_i = (MT_RED_DP_DET_STRUCT_I *)NULL;

	l_mt_red_dp_det_struct_i = (MT_RED_DP_DET_STRUCT_I *)calloc(1,sizeof(MT_RED_DP_DET_STRUCT_I));



	if(!strlen(p_mt_red_dp_det_struct_h ->h_instr_code))
		l_mt_red_dp_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_red_dp_det_struct_h ->h_rd_client_id))
		l_mt_red_dp_det_struct_i -> i_rd_client_id= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_rd_dp_id))
		l_mt_red_dp_det_struct_i -> i_rd_dp_id= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_rd_depo_code))
		l_mt_red_dp_det_struct_i -> i_rd_depo_code= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_ipa_code))
		l_mt_red_dp_det_struct_i -> i_ipa_code= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_maker))
		l_mt_red_dp_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_maker_dt))
		l_mt_red_dp_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_access_stamp))
		l_mt_red_dp_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_checker))
		l_mt_red_dp_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_checker_dt))
		l_mt_red_dp_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_red_dp_det_struct_h ->h_status))
		l_mt_red_dp_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_RED_DP_DET VALUES(:p_mt_red_dp_det_struct_h:l_mt_red_dp_det_struct_i); */ 
#line 1824 "DM_DbInterface.pc"

{
#line 1824 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1824 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1824 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_RED_DP_DET  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:\
s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s\
23:s24 )";
#line 1824 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1824 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )1975;
#line 1824 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1824 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_instr_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_red_dp_det_struct_i->i_instr_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_red_dp_det_struct_h->h_instr_seq_num;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_red_dp_det_struct_i->i_instr_seq_num;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_rd_client_id;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )21;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_red_dp_det_struct_i->i_rd_client_id;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_rd_dp_id;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )21;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_red_dp_det_struct_i->i_rd_dp_id;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_rd_depo_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )21;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_red_dp_det_struct_i->i_rd_depo_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_ipa_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )11;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_red_dp_det_struct_i->i_ipa_code;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_maker;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_red_dp_det_struct_i->i_maker;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_maker_dt;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_red_dp_det_struct_i->i_maker_dt;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_access_stamp;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_red_dp_det_struct_i->i_access_stamp;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_checker;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_red_dp_det_struct_i->i_checker;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_checker_dt;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_red_dp_det_struct_i->i_checker_dt;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_red_dp_det_struct_h->h_status;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_red_dp_det_struct_i->i_status;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1824 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1824 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1824 "DM_DbInterface.pc"
}

#line 1824 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_red_dp_det_struct_h -> h_instr_code,l_mt_red_dp_det_struct_i -> i_instr_code,strlen(p_mt_red_dp_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_red_dp_det_struct_h -> h_instr_seq_num,l_mt_red_dp_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RD_CLIENT_ID",p_mt_red_dp_det_struct_h -> h_rd_client_id,l_mt_red_dp_det_struct_i -> i_rd_client_id,strlen(p_mt_red_dp_det_struct_h -> h_rd_client_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RD_DP_ID",p_mt_red_dp_det_struct_h -> h_rd_dp_id,l_mt_red_dp_det_struct_i -> i_rd_dp_id,strlen(p_mt_red_dp_det_struct_h -> h_rd_dp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RD_DEPO_CODE",p_mt_red_dp_det_struct_h -> h_rd_depo_code,l_mt_red_dp_det_struct_i -> i_rd_depo_code,strlen(p_mt_red_dp_det_struct_h -> h_rd_depo_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","IPA_CODE",p_mt_red_dp_det_struct_h -> h_ipa_code,l_mt_red_dp_det_struct_i -> i_ipa_code,strlen(p_mt_red_dp_det_struct_h -> h_ipa_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_red_dp_det_struct_h -> h_maker,l_mt_red_dp_det_struct_i -> i_maker,strlen(p_mt_red_dp_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_red_dp_det_struct_h -> h_maker_dt,l_mt_red_dp_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_red_dp_det_struct_h -> h_access_stamp,l_mt_red_dp_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_red_dp_det_struct_h -> h_checker,l_mt_red_dp_det_struct_i -> i_checker,strlen(p_mt_red_dp_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_red_dp_det_struct_h -> h_checker_dt,l_mt_red_dp_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_red_dp_det_struct_h -> h_status,l_mt_red_dp_det_struct_i -> i_status,strlen(p_mt_red_dp_det_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_red_dp_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_red_dp_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_INSTR_RATING_DET(MT_INSTR_RATING_DET_STRUCT_H *p_mt_instr_rating_det_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_INSTR_RATING_DET_STRUCT_I *l_mt_instr_rating_det_struct_i = (MT_INSTR_RATING_DET_STRUCT_I *)NULL;

	l_mt_instr_rating_det_struct_i = (MT_INSTR_RATING_DET_STRUCT_I *)calloc(1,sizeof(MT_INSTR_RATING_DET_STRUCT_I));



	if(!strlen(p_mt_instr_rating_det_struct_h ->h_instr_code))
		l_mt_instr_rating_det_struct_i -> i_instr_code= -1;

	if(!strlen(p_mt_instr_rating_det_struct_h ->h_cr_agency_code))
		l_mt_instr_rating_det_struct_i -> i_cr_agency_code= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_rating_code))
		l_mt_instr_rating_det_struct_i -> i_rating_code= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_effdt_fr))
		l_mt_instr_rating_det_struct_i -> i_effdt_fr= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_effdt_to))
		l_mt_instr_rating_det_struct_i -> i_effdt_to= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_access_stamp))
		l_mt_instr_rating_det_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_maker))
		l_mt_instr_rating_det_struct_i -> i_maker= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_maker_dt))
		l_mt_instr_rating_det_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_checker))
		l_mt_instr_rating_det_struct_i -> i_checker= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_checker_dt))
		l_mt_instr_rating_det_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_instr_rating_det_struct_h ->h_status))
		l_mt_instr_rating_det_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_INSTR_RATING_DET VALUES(:p_mt_instr_rating_det_struct_h:l_mt_instr_rating_det_struct_i); */ 
#line 1891 "DM_DbInterface.pc"

{
#line 1891 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1891 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1891 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_INSTR_RATING_DET  values (:s1:s2 ,:s3:s4 ,:s5\
:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s\
22 ,:s23:s24 )";
#line 1891 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1891 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2038;
#line 1891 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1891 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_instr_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )9;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_instr_rating_det_struct_i->i_instr_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)&p_mt_instr_rating_det_struct_h->h_instr_seq_num;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_instr_rating_det_struct_i->i_instr_seq_num;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_cr_agency_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )7;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_instr_rating_det_struct_i->i_cr_agency_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_rating_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )6;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_instr_rating_det_struct_i->i_rating_code;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_effdt_fr;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_instr_rating_det_struct_i->i_effdt_fr;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_effdt_to;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_instr_rating_det_struct_i->i_effdt_to;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_access_stamp;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_instr_rating_det_struct_i->i_access_stamp;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_maker;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_instr_rating_det_struct_i->i_maker;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_maker_dt;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_instr_rating_det_struct_i->i_maker_dt;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_checker;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )15;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_instr_rating_det_struct_i->i_checker;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_checker_dt;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_instr_rating_det_struct_i->i_checker_dt;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_instr_rating_det_struct_h->h_status;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )3;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_instr_rating_det_struct_i->i_status;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1891 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1891 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1891 "DM_DbInterface.pc"
}

#line 1891 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_instr_rating_det_struct_h -> h_instr_code,l_mt_instr_rating_det_struct_i -> i_instr_code,strlen(p_mt_instr_rating_det_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","INSTR_SEQ_NUM",p_mt_instr_rating_det_struct_h -> h_instr_seq_num,l_mt_instr_rating_det_struct_i -> i_instr_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CR_AGENCY_CODE",p_mt_instr_rating_det_struct_h -> h_cr_agency_code,l_mt_instr_rating_det_struct_i -> i_cr_agency_code,strlen(p_mt_instr_rating_det_struct_h -> h_cr_agency_code),6);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RATING_CODE",p_mt_instr_rating_det_struct_h -> h_rating_code,l_mt_instr_rating_det_struct_i -> i_rating_code,strlen(p_mt_instr_rating_det_struct_h -> h_rating_code),5);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EFFDT_FR",p_mt_instr_rating_det_struct_h -> h_effdt_fr,l_mt_instr_rating_det_struct_i -> i_effdt_fr);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EFFDT_TO",p_mt_instr_rating_det_struct_h -> h_effdt_to,l_mt_instr_rating_det_struct_i -> i_effdt_to);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_instr_rating_det_struct_h -> h_access_stamp,l_mt_instr_rating_det_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_instr_rating_det_struct_h -> h_maker,l_mt_instr_rating_det_struct_i -> i_maker,strlen(p_mt_instr_rating_det_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_instr_rating_det_struct_h -> h_maker_dt,l_mt_instr_rating_det_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_instr_rating_det_struct_h -> h_checker,l_mt_instr_rating_det_struct_i -> i_checker,strlen(p_mt_instr_rating_det_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_instr_rating_det_struct_h -> h_checker_dt,l_mt_instr_rating_det_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_instr_rating_det_struct_h -> h_status,l_mt_instr_rating_det_struct_i -> i_status,strlen(p_mt_instr_rating_det_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_instr_rating_det_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_instr_rating_det_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_PTY_EXCH_CLN_MAP(MT_PTY_EXCH_CLN_MAP_STRUCT_H *p_mt_pty_exch_cln_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_PTY_EXCH_CLN_MAP_STRUCT_I *l_mt_pty_exch_cln_map_struct_i = (MT_PTY_EXCH_CLN_MAP_STRUCT_I *)NULL;

	l_mt_pty_exch_cln_map_struct_i = (MT_PTY_EXCH_CLN_MAP_STRUCT_I *)calloc(1,sizeof(MT_PTY_EXCH_CLN_MAP_STRUCT_I));



	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_pty_code))
		l_mt_pty_exch_cln_map_struct_i -> i_pty_code= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_exch_code))
		l_mt_pty_exch_cln_map_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_cln_code))
		l_mt_pty_exch_cln_map_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_pty_exch_cln_map_code))
		l_mt_pty_exch_cln_map_struct_i -> i_pty_exch_cln_map_code= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_access_stamp))
		l_mt_pty_exch_cln_map_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_maker))
		l_mt_pty_exch_cln_map_struct_i -> i_maker= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_maker_dt))
		l_mt_pty_exch_cln_map_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_checker))
		l_mt_pty_exch_cln_map_struct_i -> i_checker= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_checker_dt))
		l_mt_pty_exch_cln_map_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_pty_exch_cln_map_struct_h ->h_status))
		l_mt_pty_exch_cln_map_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_PTY_EXCH_CLN_MAP VALUES(:p_mt_pty_exch_cln_map_struct_h:l_mt_pty_exch_cln_map_struct_i); */ 
#line 1955 "DM_DbInterface.pc"

{
#line 1955 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 1955 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1955 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PTY_EXCH_CLN_MAP  values (:s1:s2 ,:s3:s4 ,:s5\
:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 )";
#line 1955 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1955 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2101;
#line 1955 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1955 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_pty_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_pty_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_exch_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )5;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_exch_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_cln_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )11;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_cln_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_pty_exch_cln_map_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )21;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_pty_exch_cln_map_code;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_access_stamp;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_access_stamp;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_maker;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )15;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_maker;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_maker_dt;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_maker_dt;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_checker;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )21;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_checker;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_checker_dt;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_checker_dt;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pty_exch_cln_map_struct_h->h_status;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )3;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_pty_exch_cln_map_struct_i->i_status;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1955 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1955 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1955 "DM_DbInterface.pc"
}

#line 1955 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CODE",p_mt_pty_exch_cln_map_struct_h -> h_pty_code,l_mt_pty_exch_cln_map_struct_i -> i_pty_code,strlen(p_mt_pty_exch_cln_map_struct_h -> h_pty_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_pty_exch_cln_map_struct_h -> h_exch_code,l_mt_pty_exch_cln_map_struct_i -> i_exch_code,strlen(p_mt_pty_exch_cln_map_struct_h -> h_exch_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_pty_exch_cln_map_struct_h -> h_cln_code,l_mt_pty_exch_cln_map_struct_i -> i_cln_code,strlen(p_mt_pty_exch_cln_map_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_EXCH_CLN_MAP_CODE",p_mt_pty_exch_cln_map_struct_h -> h_pty_exch_cln_map_code,l_mt_pty_exch_cln_map_struct_i -> i_pty_exch_cln_map_code,strlen(p_mt_pty_exch_cln_map_struct_h -> h_pty_exch_cln_map_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_pty_exch_cln_map_struct_h -> h_access_stamp,l_mt_pty_exch_cln_map_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_pty_exch_cln_map_struct_h -> h_maker,l_mt_pty_exch_cln_map_struct_i -> i_maker,strlen(p_mt_pty_exch_cln_map_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_pty_exch_cln_map_struct_h -> h_maker_dt,l_mt_pty_exch_cln_map_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_pty_exch_cln_map_struct_h -> h_checker,l_mt_pty_exch_cln_map_struct_i -> i_checker,strlen(p_mt_pty_exch_cln_map_struct_h -> h_checker),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_pty_exch_cln_map_struct_h -> h_checker_dt,l_mt_pty_exch_cln_map_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_pty_exch_cln_map_struct_h -> h_status,l_mt_pty_exch_cln_map_struct_i -> i_status,strlen(p_mt_pty_exch_cln_map_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_pty_exch_cln_map_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_pty_exch_cln_map_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}



int MT_UpdMT_CLN_INST_MAP(MT_CLN_INST_MAP_STRUCT_H *p_mt_cln_inst_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_CLN_INST_MAP_STRUCT_I *l_mt_cln_inst_map_struct_i = (MT_CLN_INST_MAP_STRUCT_I *)NULL;

	l_mt_cln_inst_map_struct_i = (MT_CLN_INST_MAP_STRUCT_I *)calloc(1,sizeof(MT_CLN_INST_MAP_STRUCT_I));



	if(!strlen(p_mt_cln_inst_map_struct_h ->h_cln_code))
		l_mt_cln_inst_map_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_instr_code))
		l_mt_cln_inst_map_struct_i -> i_instr_code= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_cln_instr_code))
		l_mt_cln_inst_map_struct_i -> i_cln_instr_code= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_maker))
		l_mt_cln_inst_map_struct_i -> i_maker= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_maker_dt))
		l_mt_cln_inst_map_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_access_stamp))
		l_mt_cln_inst_map_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_checker))
		l_mt_cln_inst_map_struct_i -> i_checker= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_checker_dt))
		l_mt_cln_inst_map_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_cln_inst_map_struct_h ->h_status))
		l_mt_cln_inst_map_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_CLN_INST_MAP VALUES(:p_mt_cln_inst_map_struct_h:l_mt_cln_inst_map_struct_i); */ 
#line 2017 "DM_DbInterface.pc"

{
#line 2017 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2017 "DM_DbInterface.pc"
 sqlstm.arrsiz = 82;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2017 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_CLN_INST_MAP  values (:s1:s2 ,:s3:s4 ,:s5:s6 \
,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 )";
#line 2017 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2017 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2156;
#line 2017 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2017 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_cln_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_cln_inst_map_struct_i->i_cln_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_instr_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )9;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_cln_inst_map_struct_i->i_instr_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_cln_instr_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )21;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_cln_inst_map_struct_i->i_cln_instr_code;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_maker;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )15;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_cln_inst_map_struct_i->i_maker;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_maker_dt;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_cln_inst_map_struct_i->i_maker_dt;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_access_stamp;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_cln_inst_map_struct_i->i_access_stamp;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_checker;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_cln_inst_map_struct_i->i_checker;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_checker_dt;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_cln_inst_map_struct_i->i_checker_dt;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_cln_inst_map_struct_h->h_status;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )3;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_cln_inst_map_struct_i->i_status;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2017 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2017 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2017 "DM_DbInterface.pc"
}

#line 2017 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_cln_inst_map_struct_h -> h_cln_code,l_mt_cln_inst_map_struct_i -> i_cln_code,strlen(p_mt_cln_inst_map_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_mt_cln_inst_map_struct_h -> h_instr_code,l_mt_cln_inst_map_struct_i -> i_instr_code,strlen(p_mt_cln_inst_map_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_INSTR_CODE",p_mt_cln_inst_map_struct_h -> h_cln_instr_code,l_mt_cln_inst_map_struct_i -> i_cln_instr_code,strlen(p_mt_cln_inst_map_struct_h -> h_cln_instr_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_cln_inst_map_struct_h -> h_maker,l_mt_cln_inst_map_struct_i -> i_maker,strlen(p_mt_cln_inst_map_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_cln_inst_map_struct_h -> h_maker_dt,l_mt_cln_inst_map_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_cln_inst_map_struct_h -> h_access_stamp,l_mt_cln_inst_map_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_cln_inst_map_struct_h -> h_checker,l_mt_cln_inst_map_struct_i -> i_checker,strlen(p_mt_cln_inst_map_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_cln_inst_map_struct_h -> h_checker_dt,l_mt_cln_inst_map_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_cln_inst_map_struct_h -> h_status,l_mt_cln_inst_map_struct_i -> i_status,strlen(p_mt_cln_inst_map_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_cln_inst_map_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_cln_inst_map_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_CLIENT(MT_CLIENT_STRUCT_H *p_mt_client_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_CLIENT_STRUCT_I *l_mt_client_struct_i = (MT_CLIENT_STRUCT_I *)NULL;

	l_mt_client_struct_i = (MT_CLIENT_STRUCT_I *)calloc(1,sizeof(MT_CLIENT_STRUCT_I));



	if(!strlen(p_mt_client_struct_h ->h_cln_code))
		l_mt_client_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_currency))
		l_mt_client_struct_i -> i_cln_currency= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_our_their_ind))
		l_mt_client_struct_i -> i_cln_our_their_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_iscc_ind))
		l_mt_client_struct_i -> i_cln_iscc_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_use_isin_ind))
		l_mt_client_struct_i -> i_cln_use_isin_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_type))
		l_mt_client_struct_i -> i_cln_type= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_reg_name))
		l_mt_client_struct_i -> i_cln_reg_name= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_clas))
		l_mt_client_struct_i -> i_cln_clas= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_billableind))
		l_mt_client_struct_i -> i_cln_billableind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_class))
		l_mt_client_struct_i -> i_cln_class= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_vtb_client))
		l_mt_client_struct_i -> i_cln_vtb_client= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_reg))
		l_mt_client_struct_i -> i_cln_reg= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_memo))
		l_mt_client_struct_i -> i_cln_memo= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_internal))
		l_mt_client_struct_i -> i_cln_internal= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_pos_dt))
		l_mt_client_struct_i -> i_cln_pos_dt= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_base_id))
		l_mt_client_struct_i -> i_cln_base_id= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_master))
		l_mt_client_struct_i -> i_cln_master= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_name))
		l_mt_client_struct_i -> i_cln_name= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_gl_account))
		l_mt_client_struct_i -> i_cln_gl_account= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_brk_all))
		l_mt_client_struct_i -> i_cln_brk_all= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_shortnm))
		l_mt_client_struct_i -> i_cln_shortnm= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_ord_clt))
		l_mt_client_struct_i -> i_cln_ord_clt= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_spot_dl_ind))
		l_mt_client_struct_i -> i_cln_spot_dl_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fx_sell_ind))
		l_mt_client_struct_i -> i_cln_fx_sell_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fx_buy_ind))
		l_mt_client_struct_i -> i_cln_fx_buy_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fx_inc_ind))
		l_mt_client_struct_i -> i_cln_fx_inc_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_dateof_input))
		l_mt_client_struct_i -> i_cln_dateof_input= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_brnchcode))
		l_mt_client_struct_i -> i_cln_brnchcode= -1;
	if(!strlen(p_mt_client_struct_h ->h_country))
		l_mt_client_struct_i -> i_country= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fmt_rptind))
		l_mt_client_struct_i -> i_cln_fmt_rptind= -1;
	if(!strlen(p_mt_client_struct_h ->h_maker))
		l_mt_client_struct_i -> i_maker= -1;
	if(!strlen(p_mt_client_struct_h ->h_maker_dt))
		l_mt_client_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_client_struct_h ->h_access_stamp))
		l_mt_client_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_client_struct_h ->h_checker))
		l_mt_client_struct_i -> i_checker= -1;
	if(!strlen(p_mt_client_struct_h ->h_checker_dt))
		l_mt_client_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_uniq_gcustody_id))
		l_mt_client_struct_i -> i_cln_uniq_gcustody_id= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_cltprod_cd))
		l_mt_client_struct_i -> i_cln_cltprod_cd= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_domicile))
		l_mt_client_struct_i -> i_cln_domicile= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_partial_ind))
		l_mt_client_struct_i -> i_cln_partial_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_allow_regind))
		l_mt_client_struct_i -> i_cln_allow_regind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_reg_setl_ind))
		l_mt_client_struct_i -> i_cln_reg_setl_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_reg_bcl_ind))
		l_mt_client_struct_i -> i_cln_reg_bcl_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_status))
		l_mt_client_struct_i -> i_status= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_clh))
		l_mt_client_struct_i -> i_cln_clh= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_taxable_ind))
		l_mt_client_struct_i -> i_cln_taxable_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_brk_cd))
		l_mt_client_struct_i -> i_cln_brk_cd= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_tax_id))
		l_mt_client_struct_i -> i_cln_tax_id= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_add_1))
		l_mt_client_struct_i -> i_cln_add_1= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_ext_clh))
		l_mt_client_struct_i -> i_cln_ext_clh= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_grp))
		l_mt_client_struct_i -> i_cln_grp= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_sat_oper_cd))
		l_mt_client_struct_i -> i_cln_sat_oper_cd= -1;

	if(!strlen(p_mt_client_struct_h ->h_cln_authbunch_ind))
		l_mt_client_struct_i -> i_cln_authbunch_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fx_buy_ccy))
		l_mt_client_struct_i -> i_cln_fx_buy_ccy= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fx_sell_ccy))
		l_mt_client_struct_i -> i_cln_fx_sell_ccy= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_single548_support_ind))
		l_mt_client_struct_i -> i_cln_single548_support_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_stat_dl_ind))
		l_mt_client_struct_i -> i_cln_stat_dl_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_deal_setl_ind))
		l_mt_client_struct_i -> i_cln_deal_setl_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_rhts_ret))
		l_mt_client_struct_i -> i_cln_rhts_ret= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_valcredit))
		l_mt_client_struct_i -> i_cln_valcredit= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fract_ind))
		l_mt_client_struct_i -> i_cln_fract_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_auto_canc_ind))
		l_mt_client_struct_i -> i_cln_auto_canc_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_desc))
		l_mt_client_struct_i -> i_cln_desc= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_generate_ind))
		l_mt_client_struct_i -> i_cln_generate_ind= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_add_2))
		l_mt_client_struct_i -> i_cln_add_2= -1;
	if(!strlen(p_mt_client_struct_h ->h_city))
		l_mt_client_struct_i -> i_city= -1;
	if(!strlen(p_mt_client_struct_h ->h_state))
		l_mt_client_struct_i -> i_state= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_add_pin))
		l_mt_client_struct_i -> i_cln_add_pin= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_tel))
		l_mt_client_struct_i -> i_cln_tel= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_fax))
		l_mt_client_struct_i -> i_cln_fax= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_email))
		l_mt_client_struct_i -> i_cln_email= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_contact1))
		l_mt_client_struct_i -> i_cln_contact1= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_contact2))
		l_mt_client_struct_i -> i_cln_contact2= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_sebictg))
		l_mt_client_struct_i -> i_cln_sebictg= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_pan))
		l_mt_client_struct_i -> i_cln_pan= -1;

	if(!strlen(p_mt_client_struct_h ->h_cln_glb_cust))
		l_mt_client_struct_i -> i_cln_glb_cust= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_start_dl))
		l_mt_client_struct_i -> i_cln_start_dl= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_bcn_reqd))
		l_mt_client_struct_i -> i_cln_bcn_reqd= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_def_cr_agency))
		l_mt_client_struct_i -> i_cln_def_cr_agency= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_cust_ident))
		l_mt_client_struct_i -> i_cln_cust_ident= -1;

	if(!strlen(p_mt_client_struct_h ->h_cln_sign_memo))
		l_mt_client_struct_i -> i_cln_sign_memo= -1;
	if(!strlen(p_mt_client_struct_h ->h_cln_sign_img))
		l_mt_client_struct_i -> i_cln_sign_img= -1;


	/* EXEC SQL INSERT INTO MT_CLIENT VALUES(:p_mt_client_struct_h:l_mt_client_struct_i); */ 
#line 2224 "DM_DbInterface.pc"

{
#line 2224 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2224 "DM_DbInterface.pc"
 sqlstm.arrsiz = 88;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2224 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_CLIENT  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s\
8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s\
24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,:s39\
:s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54 ,:s\
55:s56 ,:s57:s58 ,:s59:s60 ,:s61:s62 ,:s63:s64 ,:s65:s66 ,:s67:s68 ,:s69:s70 ,\
:s71:s72 ,:s73:s74 ,:s75:s76 ,:s77:s78 ,:s79:s80 ,:s81:s82 ,:s83:s84 ,:s85:s86\
 ,:s87:s88 ,:s89:s90 ,:s91:s92 ,:s93:s94 ,:s95:s96 ,:s97:s98 ,:s99:s100 ,:s101\
:s102 ,:s103:s104 ,:s105:s106 ,:s107:s108 ,:s109:s110 ,:s111:s112 ,:s113:s114 \
,:s115:s116 ,:s117:s118 ,:s119:s120 ,:s121:s122 ,:s123:s124 ,:s125:s126 ,:s127\
:s128 ,:s129:s130 ,:s131:s132 ,:s133:s134 ,:s135:s136 ,:s137:s138 ,:s139:s140 \
,:s141:s142 ,:s143:s144 ,:s145:s146 ,:s147:s148 ,:s149:s150 ,:s151:s152 ,:s153\
:s154 ,:s155:s156 ,:s157:s158 ,:s159:s160 ,:s161:s162 ,:s163:s164 ,:s165:s166 \
,:s167:s168 ,:s169:s170 ,:s171:s172 ,:s173:s174 ,:s175:s176 )";
#line 2224 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2224 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2207;
#line 2224 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2224 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_client_struct_h->h_cln_code;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_client_struct_i->i_cln_code;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_client_struct_h->h_cln_currency;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )4;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_client_struct_i->i_cln_currency;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_client_struct_h->h_cln_our_their_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_client_struct_i->i_cln_our_their_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_client_struct_h->h_cln_iscc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_client_struct_i->i_cln_iscc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_client_struct_h->h_cln_use_isin_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_client_struct_i->i_cln_use_isin_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_client_struct_h->h_cln_type;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )5;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_client_struct_i->i_cln_type;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_client_struct_h->h_cln_reg_name;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )81;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_client_struct_i->i_cln_reg_name;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_client_struct_h->h_cln_clas;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )3;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_client_struct_i->i_cln_clas;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_client_struct_h->h_cln_billableind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_client_struct_i->i_cln_billableind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_client_struct_h->h_cln_class;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_client_struct_i->i_cln_class;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_client_struct_h->h_cln_vtb_client;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_client_struct_i->i_cln_vtb_client;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_client_struct_h->h_cln_reg;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )13;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_client_struct_i->i_cln_reg;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_client_struct_h->h_cln_memo;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )201;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_client_struct_i->i_cln_memo;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_client_struct_h->h_cln_internal;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_client_struct_i->i_cln_internal;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_client_struct_h->h_cln_pos_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_client_struct_i->i_cln_pos_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_client_struct_h->h_cln_base_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )7;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_client_struct_i->i_cln_base_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)&p_mt_client_struct_h->h_cln_count_swf_mon;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_client_struct_i->i_cln_count_swf_mon;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)&p_mt_client_struct_h->h_cln_count_tlx_mon;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_client_struct_i->i_cln_count_tlx_mon;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)&p_mt_client_struct_h->h_cln_count_swf_yr;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_mt_client_struct_i->i_cln_count_swf_yr;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)&p_mt_client_struct_h->h_cln_count_tlx_yr;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_mt_client_struct_i->i_cln_count_tlx_yr;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)p_mt_client_struct_h->h_cln_master;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_mt_client_struct_i->i_cln_master;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[21] = (unsigned char  *)p_mt_client_struct_h->h_cln_name;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[21] = (unsigned long )131;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[21] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[21] = (         short *)&l_mt_client_struct_i->i_cln_name;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[21] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[21] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[21] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[21] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[22] = (unsigned char  *)p_mt_client_struct_h->h_cln_gl_account;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[22] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[22] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[22] = (         short *)&l_mt_client_struct_i->i_cln_gl_account;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[22] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[22] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[22] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[22] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[23] = (unsigned char  *)p_mt_client_struct_h->h_cln_brk_all;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[23] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[23] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[23] = (         short *)&l_mt_client_struct_i->i_cln_brk_all;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[23] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[23] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[23] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[23] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[24] = (unsigned char  *)p_mt_client_struct_h->h_cln_shortnm;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[24] = (unsigned long )13;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[24] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[24] = (         short *)&l_mt_client_struct_i->i_cln_shortnm;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[24] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[24] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[24] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[24] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[25] = (unsigned char  *)p_mt_client_struct_h->h_cln_ord_clt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[25] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[25] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[25] = (         short *)&l_mt_client_struct_i->i_cln_ord_clt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[25] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[25] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[25] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[25] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[26] = (unsigned char  *)p_mt_client_struct_h->h_cln_spot_dl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[26] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[26] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[26] = (         short *)&l_mt_client_struct_i->i_cln_spot_dl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[26] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[26] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[26] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[26] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[27] = (unsigned char  *)p_mt_client_struct_h->h_cln_fx_sell_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[27] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[27] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[27] = (         short *)&l_mt_client_struct_i->i_cln_fx_sell_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[27] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[27] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[27] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[27] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[28] = (unsigned char  *)p_mt_client_struct_h->h_cln_fx_buy_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[28] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[28] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[28] = (         short *)&l_mt_client_struct_i->i_cln_fx_buy_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[28] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[28] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[28] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[28] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[29] = (unsigned char  *)p_mt_client_struct_h->h_cln_fx_inc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[29] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[29] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[29] = (         short *)&l_mt_client_struct_i->i_cln_fx_inc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[29] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[29] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[29] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[29] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[30] = (unsigned char  *)p_mt_client_struct_h->h_cln_dateof_input;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[30] = (unsigned long )20;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[30] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[30] = (         short *)&l_mt_client_struct_i->i_cln_dateof_input;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[30] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[30] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[30] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[30] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[31] = (unsigned char  *)p_mt_client_struct_h->h_cln_brnchcode;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[31] = (unsigned long )4;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[31] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[31] = (         short *)&l_mt_client_struct_i->i_cln_brnchcode;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[31] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[31] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[31] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[31] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[32] = (unsigned char  *)p_mt_client_struct_h->h_country;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[32] = (unsigned long )3;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[32] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[32] = (         short *)&l_mt_client_struct_i->i_country;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[32] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[32] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[32] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[32] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[33] = (unsigned char  *)p_mt_client_struct_h->h_cln_fmt_rptind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[33] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[33] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[33] = (         short *)&l_mt_client_struct_i->i_cln_fmt_rptind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[33] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[33] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[33] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[33] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[34] = (unsigned char  *)p_mt_client_struct_h->h_maker;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[34] = (unsigned long )15;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[34] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[34] = (         short *)&l_mt_client_struct_i->i_maker;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[34] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[34] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[34] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[34] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[35] = (unsigned char  *)p_mt_client_struct_h->h_maker_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[35] = (unsigned long )20;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[35] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[35] = (         short *)&l_mt_client_struct_i->i_maker_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[35] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[35] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[35] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[35] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[36] = (unsigned char  *)p_mt_client_struct_h->h_access_stamp;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[36] = (unsigned long )20;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[36] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[36] = (         short *)&l_mt_client_struct_i->i_access_stamp;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[36] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[36] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[36] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[36] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[37] = (unsigned char  *)p_mt_client_struct_h->h_checker;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[37] = (unsigned long )15;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[37] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[37] = (         short *)&l_mt_client_struct_i->i_checker;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[37] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[37] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[37] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[37] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[38] = (unsigned char  *)p_mt_client_struct_h->h_checker_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[38] = (unsigned long )20;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[38] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[38] = (         short *)&l_mt_client_struct_i->i_checker_dt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[38] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[38] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[38] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[38] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[39] = (unsigned char  *)p_mt_client_struct_h->h_cln_uniq_gcustody_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[39] = (unsigned long )13;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[39] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[39] = (         short *)&l_mt_client_struct_i->i_cln_uniq_gcustody_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[39] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[39] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[39] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[39] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[40] = (unsigned char  *)p_mt_client_struct_h->h_cln_cltprod_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[40] = (unsigned long )6;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[40] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[40] = (         short *)&l_mt_client_struct_i->i_cln_cltprod_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[40] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[40] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[40] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[40] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[41] = (unsigned char  *)p_mt_client_struct_h->h_cln_domicile;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[41] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[41] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[41] = (         short *)&l_mt_client_struct_i->i_cln_domicile;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[41] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[41] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[41] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[41] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[42] = (unsigned char  *)p_mt_client_struct_h->h_cln_partial_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[42] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[42] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[42] = (         short *)&l_mt_client_struct_i->i_cln_partial_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[42] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[42] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[42] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[42] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[43] = (unsigned char  *)p_mt_client_struct_h->h_cln_allow_regind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[43] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[43] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[43] = (         short *)&l_mt_client_struct_i->i_cln_allow_regind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[43] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[43] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[43] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[43] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[44] = (unsigned char  *)p_mt_client_struct_h->h_cln_reg_setl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[44] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[44] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[44] = (         short *)&l_mt_client_struct_i->i_cln_reg_setl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[44] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[44] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[44] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[44] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[45] = (unsigned char  *)p_mt_client_struct_h->h_cln_reg_bcl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[45] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[45] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[45] = (         short *)&l_mt_client_struct_i->i_cln_reg_bcl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[45] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[45] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[45] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[45] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[46] = (unsigned char  *)p_mt_client_struct_h->h_status;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[46] = (unsigned long )3;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[46] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[46] = (         short *)&l_mt_client_struct_i->i_status;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[46] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[46] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[46] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[46] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[47] = (unsigned char  *)p_mt_client_struct_h->h_cln_clh;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[47] = (unsigned long )16;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[47] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[47] = (         short *)&l_mt_client_struct_i->i_cln_clh;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[47] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[47] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[47] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[47] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[48] = (unsigned char  *)p_mt_client_struct_h->h_cln_taxable_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[48] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[48] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[48] = (         short *)&l_mt_client_struct_i->i_cln_taxable_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[48] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[48] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[48] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[48] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[49] = (unsigned char  *)p_mt_client_struct_h->h_cln_brk_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[49] = (unsigned long )13;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[49] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[49] = (         short *)&l_mt_client_struct_i->i_cln_brk_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[49] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[49] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[49] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[49] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[50] = (unsigned char  *)p_mt_client_struct_h->h_cln_tax_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[50] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[50] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[50] = (         short *)&l_mt_client_struct_i->i_cln_tax_id;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[50] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[50] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[50] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[50] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[51] = (unsigned char  *)p_mt_client_struct_h->h_cln_add_1;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[51] = (unsigned long )61;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[51] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[51] = (         short *)&l_mt_client_struct_i->i_cln_add_1;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[51] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[51] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[51] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[51] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[52] = (unsigned char  *)p_mt_client_struct_h->h_cln_ext_clh;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[52] = (unsigned long )13;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[52] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[52] = (         short *)&l_mt_client_struct_i->i_cln_ext_clh;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[52] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[52] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[52] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[52] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[53] = (unsigned char  *)p_mt_client_struct_h->h_cln_grp;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[53] = (unsigned long )5;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[53] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[53] = (         short *)&l_mt_client_struct_i->i_cln_grp;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[53] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[53] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[53] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[53] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[54] = (unsigned char  *)p_mt_client_struct_h->h_cln_sat_oper_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[54] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[54] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[54] = (         short *)&l_mt_client_struct_i->i_cln_sat_oper_cd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[54] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[54] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[54] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[54] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[55] = (unsigned char  *)&p_mt_client_struct_h->h_cln_tolerance;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[55] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[55] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[55] = (         short *)&l_mt_client_struct_i->i_cln_tolerance;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[55] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[55] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[55] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[55] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[56] = (unsigned char  *)p_mt_client_struct_h->h_cln_authbunch_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[56] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[56] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[56] = (         short *)&l_mt_client_struct_i->i_cln_authbunch_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[56] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[56] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[56] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[56] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[57] = (unsigned char  *)p_mt_client_struct_h->h_cln_fx_buy_ccy;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[57] = (unsigned long )4;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[57] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[57] = (         short *)&l_mt_client_struct_i->i_cln_fx_buy_ccy;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[57] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[57] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[57] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[57] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[58] = (unsigned char  *)p_mt_client_struct_h->h_cln_fx_sell_ccy;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[58] = (unsigned long )4;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[58] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[58] = (         short *)&l_mt_client_struct_i->i_cln_fx_sell_ccy;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[58] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[58] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[58] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[58] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[59] = (unsigned char  *)p_mt_client_struct_h->h_cln_single548_support_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[59] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[59] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[59] = (         short *)&l_mt_client_struct_i->i_cln_single548_support_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[59] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[59] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[59] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[59] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[60] = (unsigned char  *)p_mt_client_struct_h->h_cln_stat_dl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[60] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[60] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[60] = (         short *)&l_mt_client_struct_i->i_cln_stat_dl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[60] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[60] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[60] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[60] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[61] = (unsigned char  *)p_mt_client_struct_h->h_cln_deal_setl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[61] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[61] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[61] = (         short *)&l_mt_client_struct_i->i_cln_deal_setl_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[61] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[61] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[61] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[61] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[62] = (unsigned char  *)p_mt_client_struct_h->h_cln_rhts_ret;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[62] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[62] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[62] = (         short *)&l_mt_client_struct_i->i_cln_rhts_ret;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[62] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[62] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[62] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[62] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[63] = (unsigned char  *)p_mt_client_struct_h->h_cln_valcredit;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[63] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[63] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[63] = (         short *)&l_mt_client_struct_i->i_cln_valcredit;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[63] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[63] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[63] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[63] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[64] = (unsigned char  *)p_mt_client_struct_h->h_cln_fract_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[64] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[64] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[64] = (         short *)&l_mt_client_struct_i->i_cln_fract_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[64] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[64] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[64] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[64] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[65] = (unsigned char  *)p_mt_client_struct_h->h_cln_auto_canc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[65] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[65] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[65] = (         short *)&l_mt_client_struct_i->i_cln_auto_canc_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[65] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[65] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[65] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[65] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[66] = (unsigned char  *)p_mt_client_struct_h->h_cln_desc;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[66] = (unsigned long )201;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[66] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[66] = (         short *)&l_mt_client_struct_i->i_cln_desc;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[66] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[66] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[66] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[66] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[67] = (unsigned char  *)p_mt_client_struct_h->h_cln_generate_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[67] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[67] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[67] = (         short *)&l_mt_client_struct_i->i_cln_generate_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[67] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[67] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[67] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[67] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[68] = (unsigned char  *)p_mt_client_struct_h->h_cln_add_2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[68] = (unsigned long )61;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[68] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[68] = (         short *)&l_mt_client_struct_i->i_cln_add_2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[68] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[68] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[68] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[68] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[69] = (unsigned char  *)p_mt_client_struct_h->h_city;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[69] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[69] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[69] = (         short *)&l_mt_client_struct_i->i_city;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[69] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[69] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[69] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[69] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[70] = (unsigned char  *)p_mt_client_struct_h->h_state;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[70] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[70] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[70] = (         short *)&l_mt_client_struct_i->i_state;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[70] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[70] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[70] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[70] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[71] = (unsigned char  *)p_mt_client_struct_h->h_cln_add_pin;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[71] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[71] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[71] = (         short *)&l_mt_client_struct_i->i_cln_add_pin;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[71] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[71] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[71] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[71] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[72] = (unsigned char  *)p_mt_client_struct_h->h_cln_tel;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[72] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[72] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[72] = (         short *)&l_mt_client_struct_i->i_cln_tel;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[72] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[72] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[72] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[72] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[73] = (unsigned char  *)p_mt_client_struct_h->h_cln_fax;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[73] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[73] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[73] = (         short *)&l_mt_client_struct_i->i_cln_fax;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[73] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[73] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[73] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[73] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[74] = (unsigned char  *)p_mt_client_struct_h->h_cln_email;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[74] = (unsigned long )61;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[74] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[74] = (         short *)&l_mt_client_struct_i->i_cln_email;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[74] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[74] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[74] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[74] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[75] = (unsigned char  *)p_mt_client_struct_h->h_cln_contact1;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[75] = (unsigned long )66;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[75] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[75] = (         short *)&l_mt_client_struct_i->i_cln_contact1;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[75] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[75] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[75] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[75] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[76] = (unsigned char  *)p_mt_client_struct_h->h_cln_contact2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[76] = (unsigned long )66;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[76] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[76] = (         short *)&l_mt_client_struct_i->i_cln_contact2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[76] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[76] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[76] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[76] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[77] = (unsigned char  *)p_mt_client_struct_h->h_cln_sebictg;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[77] = (unsigned long )5;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[77] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[77] = (         short *)&l_mt_client_struct_i->i_cln_sebictg;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[77] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[77] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[77] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[77] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[78] = (unsigned char  *)p_mt_client_struct_h->h_cln_pan;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[78] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[78] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[78] = (         short *)&l_mt_client_struct_i->i_cln_pan;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[78] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[78] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[78] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[78] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[79] = (unsigned char  *)&p_mt_client_struct_h->h_cln_tds_rt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[79] = (unsigned long )sizeof(double);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[79] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[79] = (         short *)&l_mt_client_struct_i->i_cln_tds_rt;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[79] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[79] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[79] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[79] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[80] = (unsigned char  *)p_mt_client_struct_h->h_cln_glb_cust;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[80] = (unsigned long )11;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[80] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[80] = (         short *)&l_mt_client_struct_i->i_cln_glb_cust;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[80] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[80] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[80] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[80] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[81] = (unsigned char  *)p_mt_client_struct_h->h_cln_start_dl;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[81] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[81] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[81] = (         short *)&l_mt_client_struct_i->i_cln_start_dl;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[81] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[81] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[81] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[81] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[82] = (unsigned char  *)p_mt_client_struct_h->h_cln_bcn_reqd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[82] = (unsigned long )2;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[82] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[82] = (         short *)&l_mt_client_struct_i->i_cln_bcn_reqd;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[82] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[82] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[82] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[82] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[83] = (unsigned char  *)p_mt_client_struct_h->h_cln_def_cr_agency;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[83] = (unsigned long )7;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[83] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[83] = (         short *)&l_mt_client_struct_i->i_cln_def_cr_agency;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[83] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[83] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[83] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[83] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[84] = (unsigned char  *)p_mt_client_struct_h->h_cln_cust_ident;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[84] = (unsigned long )21;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[84] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[84] = (         short *)&l_mt_client_struct_i->i_cln_cust_ident;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[84] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[84] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[84] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[84] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[85] = (unsigned char  *)&p_mt_client_struct_h->h_cln_mst_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[85] = (unsigned long )sizeof(int);
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[85] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[85] = (         short *)&l_mt_client_struct_i->i_cln_mst_ind;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[85] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[85] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[85] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[85] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[86] = (unsigned char  *)p_mt_client_struct_h->h_cln_sign_memo;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[86] = (unsigned long )201;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[86] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[86] = (         short *)&l_mt_client_struct_i->i_cln_sign_memo;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[86] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[86] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[86] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[86] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstv[87] = (unsigned char  *)p_mt_client_struct_h->h_cln_sign_img;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhstl[87] = (unsigned long )501;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqhsts[87] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqindv[87] = (         short *)&l_mt_client_struct_i->i_cln_sign_img;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqinds[87] = (         int  )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqharm[87] = (unsigned long )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqadto[87] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqtdso[87] = (unsigned short )0;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2224 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2224 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2224 "DM_DbInterface.pc"
}

#line 2224 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_client_struct_h -> h_cln_code,l_mt_client_struct_i -> i_cln_code,strlen(p_mt_client_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CURRENCY",p_mt_client_struct_h -> h_cln_currency,l_mt_client_struct_i -> i_cln_currency,strlen(p_mt_client_struct_h -> h_cln_currency),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_OUR_THEIR_IND",p_mt_client_struct_h -> h_cln_our_their_ind,l_mt_client_struct_i -> i_cln_our_their_ind,strlen(p_mt_client_struct_h -> h_cln_our_their_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ISCC_IND",p_mt_client_struct_h -> h_cln_iscc_ind,l_mt_client_struct_i -> i_cln_iscc_ind,strlen(p_mt_client_struct_h -> h_cln_iscc_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_USE_ISIN_IND",p_mt_client_struct_h -> h_cln_use_isin_ind,l_mt_client_struct_i -> i_cln_use_isin_ind,strlen(p_mt_client_struct_h -> h_cln_use_isin_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_TYPE",p_mt_client_struct_h -> h_cln_type,l_mt_client_struct_i -> i_cln_type,strlen(p_mt_client_struct_h -> h_cln_type),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_REG_NAME",p_mt_client_struct_h -> h_cln_reg_name,l_mt_client_struct_i -> i_cln_reg_name,strlen(p_mt_client_struct_h -> h_cln_reg_name),80);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CLAS",p_mt_client_struct_h -> h_cln_clas,l_mt_client_struct_i -> i_cln_clas,strlen(p_mt_client_struct_h -> h_cln_clas),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BILLABLEIND",p_mt_client_struct_h -> h_cln_billableind,l_mt_client_struct_i -> i_cln_billableind,strlen(p_mt_client_struct_h -> h_cln_billableind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CLASS",p_mt_client_struct_h -> h_cln_class,l_mt_client_struct_i -> i_cln_class,strlen(p_mt_client_struct_h -> h_cln_class),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_VTB_CLIENT",p_mt_client_struct_h -> h_cln_vtb_client,l_mt_client_struct_i -> i_cln_vtb_client,strlen(p_mt_client_struct_h -> h_cln_vtb_client),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_REG",p_mt_client_struct_h -> h_cln_reg,l_mt_client_struct_i -> i_cln_reg,strlen(p_mt_client_struct_h -> h_cln_reg),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_MEMO",p_mt_client_struct_h -> h_cln_memo,l_mt_client_struct_i -> i_cln_memo,strlen(p_mt_client_struct_h -> h_cln_memo),200);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_INTERNAL",p_mt_client_struct_h -> h_cln_internal,l_mt_client_struct_i -> i_cln_internal,strlen(p_mt_client_struct_h -> h_cln_internal),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CLN_POS_DT",p_mt_client_struct_h -> h_cln_pos_dt,l_mt_client_struct_i -> i_cln_pos_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BASE_ID",p_mt_client_struct_h -> h_cln_base_id,l_mt_client_struct_i -> i_cln_base_id,strlen(p_mt_client_struct_h -> h_cln_base_id),6);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_COUNT_SWF_MON",p_mt_client_struct_h -> h_cln_count_swf_mon,l_mt_client_struct_i -> i_cln_count_swf_mon);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_COUNT_TLX_MON",p_mt_client_struct_h -> h_cln_count_tlx_mon,l_mt_client_struct_i -> i_cln_count_tlx_mon);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_COUNT_SWF_YR",p_mt_client_struct_h -> h_cln_count_swf_yr,l_mt_client_struct_i -> i_cln_count_swf_yr);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_COUNT_TLX_YR",p_mt_client_struct_h -> h_cln_count_tlx_yr,l_mt_client_struct_i -> i_cln_count_tlx_yr);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_MASTER",p_mt_client_struct_h -> h_cln_master,l_mt_client_struct_i -> i_cln_master,strlen(p_mt_client_struct_h -> h_cln_master),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_NAME",p_mt_client_struct_h -> h_cln_name,l_mt_client_struct_i -> i_cln_name,strlen(p_mt_client_struct_h -> h_cln_name),130);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_GL_ACCOUNT",p_mt_client_struct_h -> h_cln_gl_account,l_mt_client_struct_i -> i_cln_gl_account,strlen(p_mt_client_struct_h -> h_cln_gl_account),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BRK_ALL",p_mt_client_struct_h -> h_cln_brk_all,l_mt_client_struct_i -> i_cln_brk_all,strlen(p_mt_client_struct_h -> h_cln_brk_all),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SHORTNM",p_mt_client_struct_h -> h_cln_shortnm,l_mt_client_struct_i -> i_cln_shortnm,strlen(p_mt_client_struct_h -> h_cln_shortnm),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ORD_CLT",p_mt_client_struct_h -> h_cln_ord_clt,l_mt_client_struct_i -> i_cln_ord_clt,strlen(p_mt_client_struct_h -> h_cln_ord_clt),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SPOT_DL_IND",p_mt_client_struct_h -> h_cln_spot_dl_ind,l_mt_client_struct_i -> i_cln_spot_dl_ind,strlen(p_mt_client_struct_h -> h_cln_spot_dl_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FX_SELL_IND",p_mt_client_struct_h -> h_cln_fx_sell_ind,l_mt_client_struct_i -> i_cln_fx_sell_ind,strlen(p_mt_client_struct_h -> h_cln_fx_sell_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FX_BUY_IND",p_mt_client_struct_h -> h_cln_fx_buy_ind,l_mt_client_struct_i -> i_cln_fx_buy_ind,strlen(p_mt_client_struct_h -> h_cln_fx_buy_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FX_INC_IND",p_mt_client_struct_h -> h_cln_fx_inc_ind,l_mt_client_struct_i -> i_cln_fx_inc_ind,strlen(p_mt_client_struct_h -> h_cln_fx_inc_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CLN_DATEOF_INPUT",p_mt_client_struct_h -> h_cln_dateof_input,l_mt_client_struct_i -> i_cln_dateof_input);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BRNCHCODE",p_mt_client_struct_h -> h_cln_brnchcode,l_mt_client_struct_i -> i_cln_brnchcode,strlen(p_mt_client_struct_h -> h_cln_brnchcode),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COUNTRY",p_mt_client_struct_h -> h_country,l_mt_client_struct_i -> i_country,strlen(p_mt_client_struct_h -> h_country),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FMT_RPTIND",p_mt_client_struct_h -> h_cln_fmt_rptind,l_mt_client_struct_i -> i_cln_fmt_rptind,strlen(p_mt_client_struct_h -> h_cln_fmt_rptind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_client_struct_h -> h_maker,l_mt_client_struct_i -> i_maker,strlen(p_mt_client_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_client_struct_h -> h_maker_dt,l_mt_client_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_client_struct_h -> h_access_stamp,l_mt_client_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_client_struct_h -> h_checker,l_mt_client_struct_i -> i_checker,strlen(p_mt_client_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_client_struct_h -> h_checker_dt,l_mt_client_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_UNIQ_GCUSTODY_ID",p_mt_client_struct_h -> h_cln_uniq_gcustody_id,l_mt_client_struct_i -> i_cln_uniq_gcustody_id,strlen(p_mt_client_struct_h -> h_cln_uniq_gcustody_id),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CLTPROD_CD",p_mt_client_struct_h -> h_cln_cltprod_cd,l_mt_client_struct_i -> i_cln_cltprod_cd,strlen(p_mt_client_struct_h -> h_cln_cltprod_cd),5);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DOMICILE",p_mt_client_struct_h -> h_cln_domicile,l_mt_client_struct_i -> i_cln_domicile,strlen(p_mt_client_struct_h -> h_cln_domicile),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_PARTIAL_IND",p_mt_client_struct_h -> h_cln_partial_ind,l_mt_client_struct_i -> i_cln_partial_ind,strlen(p_mt_client_struct_h -> h_cln_partial_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ALLOW_REGIND",p_mt_client_struct_h -> h_cln_allow_regind,l_mt_client_struct_i -> i_cln_allow_regind,strlen(p_mt_client_struct_h -> h_cln_allow_regind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_REG_SETL_IND",p_mt_client_struct_h -> h_cln_reg_setl_ind,l_mt_client_struct_i -> i_cln_reg_setl_ind,strlen(p_mt_client_struct_h -> h_cln_reg_setl_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_REG_BCL_IND",p_mt_client_struct_h -> h_cln_reg_bcl_ind,l_mt_client_struct_i -> i_cln_reg_bcl_ind,strlen(p_mt_client_struct_h -> h_cln_reg_bcl_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_client_struct_h -> h_status,l_mt_client_struct_i -> i_status,strlen(p_mt_client_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CLH",p_mt_client_struct_h -> h_cln_clh,l_mt_client_struct_i -> i_cln_clh,strlen(p_mt_client_struct_h -> h_cln_clh),15);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_TAXABLE_IND",p_mt_client_struct_h -> h_cln_taxable_ind,l_mt_client_struct_i -> i_cln_taxable_ind,strlen(p_mt_client_struct_h -> h_cln_taxable_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BRK_CD",p_mt_client_struct_h -> h_cln_brk_cd,l_mt_client_struct_i -> i_cln_brk_cd,strlen(p_mt_client_struct_h -> h_cln_brk_cd),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_TAX_ID",p_mt_client_struct_h -> h_cln_tax_id,l_mt_client_struct_i -> i_cln_tax_id,strlen(p_mt_client_struct_h -> h_cln_tax_id),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ADD_1",p_mt_client_struct_h -> h_cln_add_1,l_mt_client_struct_i -> i_cln_add_1,strlen(p_mt_client_struct_h -> h_cln_add_1),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_EXT_CLH",p_mt_client_struct_h -> h_cln_ext_clh,l_mt_client_struct_i -> i_cln_ext_clh,strlen(p_mt_client_struct_h -> h_cln_ext_clh),12);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_GRP",p_mt_client_struct_h -> h_cln_grp,l_mt_client_struct_i -> i_cln_grp,strlen(p_mt_client_struct_h -> h_cln_grp),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SAT_OPER_CD",p_mt_client_struct_h -> h_cln_sat_oper_cd,l_mt_client_struct_i -> i_cln_sat_oper_cd,strlen(p_mt_client_struct_h -> h_cln_sat_oper_cd),10);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_TOLERANCE",p_mt_client_struct_h -> h_cln_tolerance,l_mt_client_struct_i -> i_cln_tolerance);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_AUTHBUNCH_IND",p_mt_client_struct_h -> h_cln_authbunch_ind,l_mt_client_struct_i -> i_cln_authbunch_ind,strlen(p_mt_client_struct_h -> h_cln_authbunch_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FX_BUY_CCY",p_mt_client_struct_h -> h_cln_fx_buy_ccy,l_mt_client_struct_i -> i_cln_fx_buy_ccy,strlen(p_mt_client_struct_h -> h_cln_fx_buy_ccy),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FX_SELL_CCY",p_mt_client_struct_h -> h_cln_fx_sell_ccy,l_mt_client_struct_i -> i_cln_fx_sell_ccy,strlen(p_mt_client_struct_h -> h_cln_fx_sell_ccy),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SINGLE548_SUPPORT_IND",p_mt_client_struct_h -> h_cln_single548_support_ind,l_mt_client_struct_i -> i_cln_single548_support_ind,strlen(p_mt_client_struct_h -> h_cln_single548_support_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_STAT_DL_IND",p_mt_client_struct_h -> h_cln_stat_dl_ind,l_mt_client_struct_i -> i_cln_stat_dl_ind,strlen(p_mt_client_struct_h -> h_cln_stat_dl_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEAL_SETL_IND",p_mt_client_struct_h -> h_cln_deal_setl_ind,l_mt_client_struct_i -> i_cln_deal_setl_ind,strlen(p_mt_client_struct_h -> h_cln_deal_setl_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_RHTS_RET",p_mt_client_struct_h -> h_cln_rhts_ret,l_mt_client_struct_i -> i_cln_rhts_ret,strlen(p_mt_client_struct_h -> h_cln_rhts_ret),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_VALCREDIT",p_mt_client_struct_h -> h_cln_valcredit,l_mt_client_struct_i -> i_cln_valcredit,strlen(p_mt_client_struct_h -> h_cln_valcredit),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FRACT_IND",p_mt_client_struct_h -> h_cln_fract_ind,l_mt_client_struct_i -> i_cln_fract_ind,strlen(p_mt_client_struct_h -> h_cln_fract_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_AUTO_CANC_IND",p_mt_client_struct_h -> h_cln_auto_canc_ind,l_mt_client_struct_i -> i_cln_auto_canc_ind,strlen(p_mt_client_struct_h -> h_cln_auto_canc_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DESC",p_mt_client_struct_h -> h_cln_desc,l_mt_client_struct_i -> i_cln_desc,strlen(p_mt_client_struct_h -> h_cln_desc),200);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_GENERATE_IND",p_mt_client_struct_h -> h_cln_generate_ind,l_mt_client_struct_i -> i_cln_generate_ind,strlen(p_mt_client_struct_h -> h_cln_generate_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ADD_2",p_mt_client_struct_h -> h_cln_add_2,l_mt_client_struct_i -> i_cln_add_2,strlen(p_mt_client_struct_h -> h_cln_add_2),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CITY",p_mt_client_struct_h -> h_city,l_mt_client_struct_i -> i_city,strlen(p_mt_client_struct_h -> h_city),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATE",p_mt_client_struct_h -> h_state,l_mt_client_struct_i -> i_state,strlen(p_mt_client_struct_h -> h_state),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_ADD_PIN",p_mt_client_struct_h -> h_cln_add_pin,l_mt_client_struct_i -> i_cln_add_pin,strlen(p_mt_client_struct_h -> h_cln_add_pin),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_TEL",p_mt_client_struct_h -> h_cln_tel,l_mt_client_struct_i -> i_cln_tel,strlen(p_mt_client_struct_h -> h_cln_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_FAX",p_mt_client_struct_h -> h_cln_fax,l_mt_client_struct_i -> i_cln_fax,strlen(p_mt_client_struct_h -> h_cln_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_EMAIL",p_mt_client_struct_h -> h_cln_email,l_mt_client_struct_i -> i_cln_email,strlen(p_mt_client_struct_h -> h_cln_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CONTACT1",p_mt_client_struct_h -> h_cln_contact1,l_mt_client_struct_i -> i_cln_contact1,strlen(p_mt_client_struct_h -> h_cln_contact1),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CONTACT2",p_mt_client_struct_h -> h_cln_contact2,l_mt_client_struct_i -> i_cln_contact2,strlen(p_mt_client_struct_h -> h_cln_contact2),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SEBICTG",p_mt_client_struct_h -> h_cln_sebictg,l_mt_client_struct_i -> i_cln_sebictg,strlen(p_mt_client_struct_h -> h_cln_sebictg),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_PAN",p_mt_client_struct_h -> h_cln_pan,l_mt_client_struct_i -> i_cln_pan,strlen(p_mt_client_struct_h -> h_cln_pan),20);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","CLN_TDS_RT",p_mt_client_struct_h -> h_cln_tds_rt,l_mt_client_struct_i -> i_cln_tds_rt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_GLB_CUST",p_mt_client_struct_h -> h_cln_glb_cust,l_mt_client_struct_i -> i_cln_glb_cust,strlen(p_mt_client_struct_h -> h_cln_glb_cust),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_START_DL",p_mt_client_struct_h -> h_cln_start_dl,l_mt_client_struct_i -> i_cln_start_dl,strlen(p_mt_client_struct_h -> h_cln_start_dl),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_BCN_REQD",p_mt_client_struct_h -> h_cln_bcn_reqd,l_mt_client_struct_i -> i_cln_bcn_reqd,strlen(p_mt_client_struct_h -> h_cln_bcn_reqd),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEF_CR_AGENCY",p_mt_client_struct_h -> h_cln_def_cr_agency,l_mt_client_struct_i -> i_cln_def_cr_agency,strlen(p_mt_client_struct_h -> h_cln_def_cr_agency),6);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CUST_IDENT",p_mt_client_struct_h -> h_cln_cust_ident,l_mt_client_struct_i -> i_cln_cust_ident,strlen(p_mt_client_struct_h -> h_cln_cust_ident),20);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_MST_IND",p_mt_client_struct_h -> h_cln_mst_ind,l_mt_client_struct_i -> i_cln_mst_ind);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SIGN_MEMO",p_mt_client_struct_h -> h_cln_sign_memo,l_mt_client_struct_i -> i_cln_sign_memo,strlen(p_mt_client_struct_h -> h_cln_sign_memo),200);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_SIGN_IMG",p_mt_client_struct_h -> h_cln_sign_img,l_mt_client_struct_i -> i_cln_sign_img,strlen(p_mt_client_struct_h -> h_cln_sign_img),500);

	IS_ANY_ORA_ERROR

RETURN_SUCCESS:

	APL_FREE(l_mt_client_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_mt_client_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_CLI_EXCH_MAP(MT_CLI_EXCH_MAP_STRUCT_H *p_mt_cli_exch_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_CLI_EXCH_MAP_STRUCT_I *l_mt_cli_exch_map_struct_i = (MT_CLI_EXCH_MAP_STRUCT_I *)NULL;

	l_mt_cli_exch_map_struct_i = (MT_CLI_EXCH_MAP_STRUCT_I *)calloc(1,sizeof(MT_CLI_EXCH_MAP_STRUCT_I));



	if(!strlen(p_mt_cli_exch_map_struct_h ->h_cln_code))
		l_mt_cli_exch_map_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_cln_exch_code))
		l_mt_cli_exch_map_struct_i -> i_cln_exch_code= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_cln_exch_map_code))
		l_mt_cli_exch_map_struct_i -> i_cln_exch_map_code= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_cln_hdfc_cm_id))
		l_mt_cli_exch_map_struct_i -> i_cln_hdfc_cm_id= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_access_stamp))
		l_mt_cli_exch_map_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_maker))
		l_mt_cli_exch_map_struct_i -> i_maker= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_maker_dt))
		l_mt_cli_exch_map_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_checker))
		l_mt_cli_exch_map_struct_i -> i_checker= -1;
	if(!strlen(p_mt_cli_exch_map_struct_h ->h_checker_dt))
		l_mt_cli_exch_map_struct_i -> i_checker_dt= -1;

	if(!strlen(p_mt_cli_exch_map_struct_h ->h_status))
		l_mt_cli_exch_map_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_CLI_EXCH_MAP VALUES(:p_mt_cli_exch_map_struct_h:l_mt_cli_exch_map_struct_i); */ 
#line 2366 "DM_DbInterface.pc"

{
#line 2366 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2366 "DM_DbInterface.pc"
 sqlstm.arrsiz = 88;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2366 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_CLI_EXCH_MAP  values (:s1:s2 ,:s3:s4 ,:s5:s6 \
,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 )";
#line 2366 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2366 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2574;
#line 2366 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2366 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_cln_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_cli_exch_map_struct_i->i_cln_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_cln_exch_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )4;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_cli_exch_map_struct_i->i_cln_exch_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_cln_exch_map_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )21;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_cli_exch_map_struct_i->i_cln_exch_map_code;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_cln_hdfc_cm_id;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )21;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_cli_exch_map_struct_i->i_cln_hdfc_cm_id;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_access_stamp;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_cli_exch_map_struct_i->i_access_stamp;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_maker;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )15;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_cli_exch_map_struct_i->i_maker;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_maker_dt;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_cli_exch_map_struct_i->i_maker_dt;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_checker;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_cli_exch_map_struct_i->i_checker;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_checker_dt;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_cli_exch_map_struct_i->i_checker_dt;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)&p_mt_cli_exch_map_struct_h->h_cln_seq_num;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_cli_exch_map_struct_i->i_cln_seq_num;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_cli_exch_map_struct_h->h_status;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )3;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_cli_exch_map_struct_i->i_status;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2366 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2366 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2366 "DM_DbInterface.pc"
}

#line 2366 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_cli_exch_map_struct_h -> h_cln_code,l_mt_cli_exch_map_struct_i -> i_cln_code,strlen(p_mt_cli_exch_map_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_EXCH_CODE",p_mt_cli_exch_map_struct_h -> h_cln_exch_code,l_mt_cli_exch_map_struct_i -> i_cln_exch_code,strlen(p_mt_cli_exch_map_struct_h -> h_cln_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_EXCH_MAP_CODE",p_mt_cli_exch_map_struct_h -> h_cln_exch_map_code,l_mt_cli_exch_map_struct_i -> i_cln_exch_map_code,strlen(p_mt_cli_exch_map_struct_h -> h_cln_exch_map_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_HDFC_CM_ID",p_mt_cli_exch_map_struct_h -> h_cln_hdfc_cm_id,l_mt_cli_exch_map_struct_i -> i_cln_hdfc_cm_id,strlen(p_mt_cli_exch_map_struct_h -> h_cln_hdfc_cm_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_cli_exch_map_struct_h -> h_access_stamp,l_mt_cli_exch_map_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_cli_exch_map_struct_h -> h_maker,l_mt_cli_exch_map_struct_i -> i_maker,strlen(p_mt_cli_exch_map_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_cli_exch_map_struct_h -> h_maker_dt,l_mt_cli_exch_map_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_cli_exch_map_struct_h -> h_checker,l_mt_cli_exch_map_struct_i -> i_checker,strlen(p_mt_cli_exch_map_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_cli_exch_map_struct_h -> h_checker_dt,l_mt_cli_exch_map_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_SEQ_NUM",p_mt_cli_exch_map_struct_h -> h_cln_seq_num,l_mt_cli_exch_map_struct_i -> i_cln_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_cli_exch_map_struct_h -> h_status,l_mt_cli_exch_map_struct_i -> i_status,strlen(p_mt_cli_exch_map_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_cli_exch_map_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_cli_exch_map_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}



int MT_UpdMT_CLI_DEPO_MAP(MT_CLI_DEPO_MAP_STRUCT_H *p_mt_cli_depo_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_CLI_DEPO_MAP_STRUCT_I *l_mt_cli_depo_map_struct_i = (MT_CLI_DEPO_MAP_STRUCT_I *)NULL;

	l_mt_cli_depo_map_struct_i = (MT_CLI_DEPO_MAP_STRUCT_I *)calloc(1,sizeof(MT_CLI_DEPO_MAP_STRUCT_I));



	if(!strlen(p_mt_cli_depo_map_struct_h ->h_cln_code))
		l_mt_cli_depo_map_struct_i -> i_cln_code= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_cln_depo_code))
		l_mt_cli_depo_map_struct_i -> i_cln_depo_code= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_cln_depo_map_client_id))
		l_mt_cli_depo_map_struct_i -> i_cln_depo_map_client_id= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_cln_depo_map_dp_id))
		l_mt_cli_depo_map_struct_i -> i_cln_depo_map_dp_id= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_access_stamp))
		l_mt_cli_depo_map_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_maker))
		l_mt_cli_depo_map_struct_i -> i_maker= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_maker_dt))
		l_mt_cli_depo_map_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_checker))
		l_mt_cli_depo_map_struct_i -> i_checker= -1;
	if(!strlen(p_mt_cli_depo_map_struct_h ->h_checker_dt))
		l_mt_cli_depo_map_struct_i -> i_checker_dt= -1;

	if(!strlen(p_mt_cli_depo_map_struct_h ->h_status))
		l_mt_cli_depo_map_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_CLI_DEPO_MAP VALUES(:p_mt_cli_depo_map_struct_h:l_mt_cli_depo_map_struct_i); */ 
#line 2432 "DM_DbInterface.pc"

{
#line 2432 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2432 "DM_DbInterface.pc"
 sqlstm.arrsiz = 88;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2432 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_CLI_DEPO_MAP  values (:s1:s2 ,:s3:s4 ,:s5:s6 \
,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 )";
#line 2432 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2432 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2633;
#line 2432 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2432 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_cln_code;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_cli_depo_map_struct_i->i_cln_code;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_cln_depo_code;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )5;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_cli_depo_map_struct_i->i_cln_depo_code;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_cln_depo_map_client_id;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )21;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_cli_depo_map_struct_i->i_cln_depo_map_client_id;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_cln_depo_map_dp_id;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )21;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_cli_depo_map_struct_i->i_cln_depo_map_dp_id;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_access_stamp;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )20;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_cli_depo_map_struct_i->i_access_stamp;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_maker;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )15;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_cli_depo_map_struct_i->i_maker;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_maker_dt;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )20;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_cli_depo_map_struct_i->i_maker_dt;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_checker;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )15;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_cli_depo_map_struct_i->i_checker;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_checker_dt;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_cli_depo_map_struct_i->i_checker_dt;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)&p_mt_cli_depo_map_struct_h->h_cln_seq_num;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_cli_depo_map_struct_i->i_cln_seq_num;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_cli_depo_map_struct_h->h_status;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )3;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_cli_depo_map_struct_i->i_status;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2432 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2432 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2432 "DM_DbInterface.pc"
}

#line 2432 "DM_DbInterface.pc"


		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_mt_cli_depo_map_struct_h -> h_cln_code,l_mt_cli_depo_map_struct_i -> i_cln_code,strlen(p_mt_cli_depo_map_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEPO_CODE",p_mt_cli_depo_map_struct_h -> h_cln_depo_code,l_mt_cli_depo_map_struct_i -> i_cln_depo_code,strlen(p_mt_cli_depo_map_struct_h -> h_cln_depo_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEPO_MAP_CLIENT_ID",p_mt_cli_depo_map_struct_h -> h_cln_depo_map_client_id,l_mt_cli_depo_map_struct_i -> i_cln_depo_map_client_id,strlen(p_mt_cli_depo_map_struct_h -> h_cln_depo_map_client_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEPO_MAP_DP_ID",p_mt_cli_depo_map_struct_h -> h_cln_depo_map_dp_id,l_mt_cli_depo_map_struct_i -> i_cln_depo_map_dp_id,strlen(p_mt_cli_depo_map_struct_h -> h_cln_depo_map_dp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_cli_depo_map_struct_h -> h_access_stamp,l_mt_cli_depo_map_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_cli_depo_map_struct_h -> h_maker,l_mt_cli_depo_map_struct_i -> i_maker,strlen(p_mt_cli_depo_map_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_cli_depo_map_struct_h -> h_maker_dt,l_mt_cli_depo_map_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_cli_depo_map_struct_h -> h_checker,l_mt_cli_depo_map_struct_i -> i_checker,strlen(p_mt_cli_depo_map_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_cli_depo_map_struct_h -> h_checker_dt,l_mt_cli_depo_map_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","CLN_SEQ_NUM",p_mt_cli_depo_map_struct_h -> h_cln_seq_num,l_mt_cli_depo_map_struct_i -> i_cln_seq_num);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_cli_depo_map_struct_h -> h_status,l_mt_cli_depo_map_struct_i -> i_status,strlen(p_mt_cli_depo_map_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
		RETURN_SUCCESS:

		APL_FREE(l_mt_cli_depo_map_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_cli_depo_map_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_PTY_EXCH_MAP(MT_PTY_EXCH_MAP_STRUCT_H *p_mt_pty_exch_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_PTY_EXCH_MAP_STRUCT_I *l_mt_pty_exch_map_struct_i = (MT_PTY_EXCH_MAP_STRUCT_I *)NULL;

	l_mt_pty_exch_map_struct_i = (MT_PTY_EXCH_MAP_STRUCT_I *)calloc(1,sizeof(MT_PTY_EXCH_MAP_STRUCT_I));



	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_code))
		l_mt_pty_exch_map_struct_i -> i_pty_code= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_exch_code))
		l_mt_pty_exch_map_struct_i -> i_exch_code= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_exch_map_code))
		l_mt_pty_exch_map_struct_i -> i_pty_exch_map_code= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_cmbp_id))
		l_mt_pty_exch_map_struct_i -> i_pty_cmbp_id= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_cccm_id))
		l_mt_pty_exch_map_struct_i -> i_pty_cccm_id= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_access_stamp))
		l_mt_pty_exch_map_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_maker))
		l_mt_pty_exch_map_struct_i -> i_maker= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_maker_dt))
		l_mt_pty_exch_map_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_checker))
		l_mt_pty_exch_map_struct_i -> i_checker= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_checker_dt))
		l_mt_pty_exch_map_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_status))
		l_mt_pty_exch_map_struct_i -> i_status= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_sebi_reg_no_1))
		l_mt_pty_exch_map_struct_i -> i_pty_sebi_reg_no_1= -1;
	if(!strlen(p_mt_pty_exch_map_struct_h ->h_pty_sebi_reg_no_2))
		l_mt_pty_exch_map_struct_i -> i_pty_sebi_reg_no_2= -1;


	/* EXEC SQL INSERT INTO MT_PTY_EXCH_MAP VALUES(:p_mt_pty_exch_map_struct_h:l_mt_pty_exch_map_struct_i); */ 
#line 2501 "DM_DbInterface.pc"

{
#line 2501 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2501 "DM_DbInterface.pc"
 sqlstm.arrsiz = 88;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2501 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_PTY_EXCH_MAP  values (:s1:s2 ,:s3:s4 ,:s5:s6 \
,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,\
:s23:s24 ,:s25:s26 )";
#line 2501 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2501 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2692;
#line 2501 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2501 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )11;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_exch_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )4;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_pty_exch_map_struct_i->i_exch_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_exch_map_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_exch_map_code;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_cmbp_id;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_cmbp_id;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_cccm_id;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_cccm_id;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_access_stamp;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )20;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_pty_exch_map_struct_i->i_access_stamp;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_maker;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )15;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_pty_exch_map_struct_i->i_maker;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_maker_dt;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )20;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_pty_exch_map_struct_i->i_maker_dt;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_checker;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_pty_exch_map_struct_i->i_checker;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_checker_dt;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_pty_exch_map_struct_i->i_checker_dt;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_status;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )3;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_pty_exch_map_struct_i->i_status;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_sebi_reg_no_1;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_sebi_reg_no_1;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_pty_exch_map_struct_h->h_pty_sebi_reg_no_2;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )21;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_pty_exch_map_struct_i->i_pty_sebi_reg_no_2;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2501 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2501 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2501 "DM_DbInterface.pc"
}

#line 2501 "DM_DbInterface.pc"


	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CODE",p_mt_pty_exch_map_struct_h -> h_pty_code,l_mt_pty_exch_map_struct_i -> i_pty_code,strlen(p_mt_pty_exch_map_struct_h -> h_pty_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_mt_pty_exch_map_struct_h -> h_exch_code,l_mt_pty_exch_map_struct_i -> i_exch_code,strlen(p_mt_pty_exch_map_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_EXCH_MAP_CODE",p_mt_pty_exch_map_struct_h -> h_pty_exch_map_code,l_mt_pty_exch_map_struct_i -> i_pty_exch_map_code,strlen(p_mt_pty_exch_map_struct_h -> h_pty_exch_map_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CMBP_ID",p_mt_pty_exch_map_struct_h -> h_pty_cmbp_id,l_mt_pty_exch_map_struct_i -> i_pty_cmbp_id,strlen(p_mt_pty_exch_map_struct_h -> h_pty_cmbp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_CCCM_ID",p_mt_pty_exch_map_struct_h -> h_pty_cccm_id,l_mt_pty_exch_map_struct_i -> i_pty_cccm_id,strlen(p_mt_pty_exch_map_struct_h -> h_pty_cccm_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_pty_exch_map_struct_h -> h_access_stamp,l_mt_pty_exch_map_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_pty_exch_map_struct_h -> h_maker,l_mt_pty_exch_map_struct_i -> i_maker,strlen(p_mt_pty_exch_map_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_pty_exch_map_struct_h -> h_maker_dt,l_mt_pty_exch_map_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_pty_exch_map_struct_h -> h_checker,l_mt_pty_exch_map_struct_i -> i_checker,strlen(p_mt_pty_exch_map_struct_h -> h_checker),20);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_pty_exch_map_struct_h -> h_checker_dt,l_mt_pty_exch_map_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_pty_exch_map_struct_h -> h_status,l_mt_pty_exch_map_struct_i -> i_status,strlen(p_mt_pty_exch_map_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SEBI_REG_NO_1",p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no_1,l_mt_pty_exch_map_struct_i -> i_pty_sebi_reg_no_1,strlen(p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no_1),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PTY_SEBI_REG_NO_2",p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no_2,l_mt_pty_exch_map_struct_i -> i_pty_sebi_reg_no_2,strlen(p_mt_pty_exch_map_struct_h -> h_pty_sebi_reg_no_2),20);


	IS_ANY_ORA_ERROR
		RETURN_SUCCESS:

		APL_FREE(l_mt_pty_exch_map_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_pty_exch_map_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdMT_DEPO_PART(MT_DEPO_PART_STRUCT_H *p_mt_depo_part_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	MT_DEPO_PART_STRUCT_I *l_mt_depo_part_struct_i = (MT_DEPO_PART_STRUCT_I *)NULL;

	l_mt_depo_part_struct_i = (MT_DEPO_PART_STRUCT_I *)calloc(1,sizeof(MT_DEPO_PART_STRUCT_I));



	if(!strlen(p_mt_depo_part_struct_h ->h_depo_code))
		l_mt_depo_part_struct_i -> i_depo_code= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_code))
		l_mt_depo_part_struct_i -> i_depo_part_code= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_contact))
		l_mt_depo_part_struct_i -> i_depo_part_contact= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_add1))
		l_mt_depo_part_struct_i -> i_depo_part_add1= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_add2))
		l_mt_depo_part_struct_i -> i_depo_part_add2= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_city))
		l_mt_depo_part_struct_i -> i_city= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_state))
		l_mt_depo_part_struct_i -> i_state= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_country))
		l_mt_depo_part_struct_i -> i_country= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_add_pin))
		l_mt_depo_part_struct_i -> i_depo_part_add_pin= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_tel))
		l_mt_depo_part_struct_i -> i_depo_part_tel= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_fax))
		l_mt_depo_part_struct_i -> i_depo_part_fax= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_depo_part_email))
		l_mt_depo_part_struct_i -> i_depo_part_email= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_maker))
		l_mt_depo_part_struct_i -> i_maker= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_maker_dt))
		l_mt_depo_part_struct_i -> i_maker_dt= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_access_stamp))
		l_mt_depo_part_struct_i -> i_access_stamp= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_checker))
		l_mt_depo_part_struct_i -> i_checker= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_checker_dt))
		l_mt_depo_part_struct_i -> i_checker_dt= -1;
	if(!strlen(p_mt_depo_part_struct_h ->h_status))
		l_mt_depo_part_struct_i -> i_status= -1;


	/* EXEC SQL INSERT INTO MT_DEPO_PART VALUES(:p_mt_depo_part_struct_h:l_mt_depo_part_struct_i); */ 
#line 2581 "DM_DbInterface.pc"

{
#line 2581 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 2581 "DM_DbInterface.pc"
 sqlstm.arrsiz = 88;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 2581 "DM_DbInterface.pc"
 sqlstm.stmt = "insert into MT_DEPO_PART  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s\
7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s2\
3:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 )";
#line 2581 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 2581 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )2759;
#line 2581 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 2581 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_code;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )5;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_mt_depo_part_struct_i->i_depo_code;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_code;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )21;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_code;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_contact;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )66;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_contact;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_add1;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )66;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_add1;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_add2;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )66;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_add2;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)p_mt_depo_part_struct_h->h_city;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )4;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_mt_depo_part_struct_i->i_city;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_mt_depo_part_struct_h->h_state;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )3;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_mt_depo_part_struct_i->i_state;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_mt_depo_part_struct_h->h_country;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )3;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_mt_depo_part_struct_i->i_country;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_add_pin;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )11;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_add_pin;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_tel;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )21;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_tel;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_fax;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )21;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_fax;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_mt_depo_part_struct_h->h_depo_part_email;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )61;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_mt_depo_part_struct_i->i_depo_part_email;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_mt_depo_part_struct_h->h_maker;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )15;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_mt_depo_part_struct_i->i_maker;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_mt_depo_part_struct_h->h_maker_dt;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_mt_depo_part_struct_i->i_maker_dt;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_mt_depo_part_struct_h->h_access_stamp;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_mt_depo_part_struct_i->i_access_stamp;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_mt_depo_part_struct_h->h_checker;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )15;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_mt_depo_part_struct_i->i_checker;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_mt_depo_part_struct_h->h_checker_dt;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )20;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_mt_depo_part_struct_i->i_checker_dt;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_mt_depo_part_struct_h->h_status;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )3;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_mt_depo_part_struct_i->i_status;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 2581 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 2581 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2581 "DM_DbInterface.pc"
}

#line 2581 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_CODE",p_mt_depo_part_struct_h -> h_depo_code,l_mt_depo_part_struct_i -> i_depo_code,strlen(p_mt_depo_part_struct_h -> h_depo_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_CODE",p_mt_depo_part_struct_h -> h_depo_part_code,l_mt_depo_part_struct_i -> i_depo_part_code,strlen(p_mt_depo_part_struct_h -> h_depo_part_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_CONTACT",p_mt_depo_part_struct_h -> h_depo_part_contact,l_mt_depo_part_struct_i -> i_depo_part_contact,strlen(p_mt_depo_part_struct_h -> h_depo_part_contact),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_ADD1",p_mt_depo_part_struct_h -> h_depo_part_add1,l_mt_depo_part_struct_i -> i_depo_part_add1,strlen(p_mt_depo_part_struct_h -> h_depo_part_add1),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_ADD2",p_mt_depo_part_struct_h -> h_depo_part_add2,l_mt_depo_part_struct_i -> i_depo_part_add2,strlen(p_mt_depo_part_struct_h -> h_depo_part_add2),65);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CITY",p_mt_depo_part_struct_h -> h_city,l_mt_depo_part_struct_i -> i_city,strlen(p_mt_depo_part_struct_h -> h_city),3);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATE",p_mt_depo_part_struct_h -> h_state,l_mt_depo_part_struct_i -> i_state,strlen(p_mt_depo_part_struct_h -> h_state),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COUNTRY",p_mt_depo_part_struct_h -> h_country,l_mt_depo_part_struct_i -> i_country,strlen(p_mt_depo_part_struct_h -> h_country),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_ADD_PIN",p_mt_depo_part_struct_h -> h_depo_part_add_pin,l_mt_depo_part_struct_i -> i_depo_part_add_pin,strlen(p_mt_depo_part_struct_h -> h_depo_part_add_pin),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_TEL",p_mt_depo_part_struct_h -> h_depo_part_tel,l_mt_depo_part_struct_i -> i_depo_part_tel,strlen(p_mt_depo_part_struct_h -> h_depo_part_tel),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_FAX",p_mt_depo_part_struct_h -> h_depo_part_fax,l_mt_depo_part_struct_i -> i_depo_part_fax,strlen(p_mt_depo_part_struct_h -> h_depo_part_fax),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_EMAIL",p_mt_depo_part_struct_h -> h_depo_part_email,l_mt_depo_part_struct_i -> i_depo_part_email,strlen(p_mt_depo_part_struct_h -> h_depo_part_email),60);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_mt_depo_part_struct_h -> h_maker,l_mt_depo_part_struct_i -> i_maker,strlen(p_mt_depo_part_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_mt_depo_part_struct_h -> h_maker_dt,l_mt_depo_part_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_mt_depo_part_struct_h -> h_access_stamp,l_mt_depo_part_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_mt_depo_part_struct_h -> h_checker,l_mt_depo_part_struct_i -> i_checker,strlen(p_mt_depo_part_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_mt_depo_part_struct_h -> h_checker_dt,l_mt_depo_part_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_mt_depo_part_struct_h -> h_status,l_mt_depo_part_struct_i -> i_status,strlen(p_mt_depo_part_struct_h -> h_status),2);


	IS_ANY_ORA_ERROR
RETURN_SUCCESS:

	APL_FREE(l_mt_depo_part_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

		RETURN_FAILURE:

		APL_FREE(l_mt_depo_part_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdMT_PTY_DEPO_MAP(MT_PTY_DEPO_MAP_STRUCT_H *p_mt_pty_depo_map_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr){

struct sqlca sqlca;

MT_PTY_DEPO_MAP_STRUCT_I *l_mt_pty_depo_map_struct_i = (MT_PTY_DEPO_MAP_STRUCT_I *)NULL;

l_mt_pty_depo_map_struct_i = (MT_PTY_DEPO_MAP_STRUCT_I *)calloc(1,sizeof(MT_PTY_DEPO_MAP_STRUCT_I));



	if(!strlen(p_mt_pty_depo_map_struct_h ->h_pty_code))  l_mt_pty_depo_map_struct_i -> i_pty_code= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_pty_code= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_depo_code))  l_mt_pty_depo_map_struct_i -> i_depo_code= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_depo_code= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_pty_depo_map_client_id))  l_mt_pty_depo_map_struct_i -> i_pty_depo_map_client_id= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_pty_depo_map_client_id= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_pty_depo_map_dp_id))  l_mt_pty_depo_map_struct_i -> i_pty_depo_map_dp_id= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_pty_depo_map_dp_id= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_access_stamp)) l_mt_pty_depo_map_struct_i -> i_access_stamp= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_access_stamp= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_maker))  l_mt_pty_depo_map_struct_i -> i_maker= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_maker= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_maker_dt)) l_mt_pty_depo_map_struct_i -> i_maker_dt= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_maker_dt= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_checker))  l_mt_pty_depo_map_struct_i -> i_checker= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_checker= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_checker_dt)) l_mt_pty_depo_map_struct_i -> i_checker_dt= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_checker_dt= 0;
	if(!strlen(p_mt_pty_depo_map_struct_h ->h_status))  l_mt_pty_depo_map_struct_i -> i_status= -1;
	else
		l_mt_pty_depo_map_struct_i -> i_status= 0;


/* EXEC SQL INSERT INTO MT_PTY_DEPO_MAP VALUES(:p_mt_pty_depo_map_struct_h:l_mt_pty_depo_map_struct_i); */ 
#line 2662 "DM_DbInterface.pc"

{
#line 2662 "DM_DbInterface.pc"
struct sqlexd sqlstm;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqlvsn = 12;
#line 2662 "DM_DbInterface.pc"
sqlstm.arrsiz = 88;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqladtp = &sqladt;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqltdsp = &sqltds;
#line 2662 "DM_DbInterface.pc"
sqlstm.stmt = "insert into MT_PTY_DEPO_MAP  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,\
:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21 ,:s22 \
)";
#line 2662 "DM_DbInterface.pc"
sqlstm.iters = (unsigned int  )1;
#line 2662 "DM_DbInterface.pc"
sqlstm.offset = (unsigned int  )2846;
#line 2662 "DM_DbInterface.pc"
sqlstm.cud = sqlcud0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqlety = (unsigned short)256;
#line 2662 "DM_DbInterface.pc"
sqlstm.occurs = (unsigned int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[0] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_pty_code;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[0] = (unsigned long )11;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[0] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[0] = (         short *)&l_mt_pty_depo_map_struct_i->i_pty_code;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[0] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[0] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[0] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[0] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[1] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_depo_code;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[1] = (unsigned long )5;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[1] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[1] = (         short *)&l_mt_pty_depo_map_struct_i->i_depo_code;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[1] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[1] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[1] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[1] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[2] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_pty_depo_map_client_id;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[2] = (unsigned long )21;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[2] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[2] = (         short *)&l_mt_pty_depo_map_struct_i->i_pty_depo_map_client_id;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[2] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[2] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[2] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[2] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[3] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_pty_depo_map_dp_id;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[3] = (unsigned long )21;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[3] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[3] = (         short *)&l_mt_pty_depo_map_struct_i->i_pty_depo_map_dp_id;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[3] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[3] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[3] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[3] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[4] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_access_stamp;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[4] = (unsigned long )20;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[4] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[4] = (         short *)&l_mt_pty_depo_map_struct_i->i_access_stamp;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[4] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[4] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[4] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[4] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[5] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_maker;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[5] = (unsigned long )15;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[5] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[5] = (         short *)&l_mt_pty_depo_map_struct_i->i_maker;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[5] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[5] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[5] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[5] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[6] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_maker_dt;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[6] = (unsigned long )20;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[6] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[6] = (         short *)&l_mt_pty_depo_map_struct_i->i_maker_dt;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[6] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[6] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[6] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[6] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[7] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_checker;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[7] = (unsigned long )21;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[7] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[7] = (         short *)&l_mt_pty_depo_map_struct_i->i_checker;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[7] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[7] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[7] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[7] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[8] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_checker_dt;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[8] = (unsigned long )20;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[8] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[8] = (         short *)&l_mt_pty_depo_map_struct_i->i_checker_dt;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[8] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[8] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[8] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[8] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[9] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_status;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[9] = (unsigned long )3;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[9] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[9] = (         short *)&l_mt_pty_depo_map_struct_i->i_status;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[9] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[9] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[9] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[9] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[10] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_exch_code;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[10] = (unsigned long )4;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[10] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[10] = (         short *)0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[10] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[10] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[10] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[10] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstv[11] = (unsigned char  *)p_mt_pty_depo_map_struct_h->h_cmbp_id;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhstl[11] = (unsigned long )21;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqhsts[11] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqindv[11] = (         short *)0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqinds[11] = (         int  )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqharm[11] = (unsigned long )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqadto[11] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqtdso[11] = (unsigned short )0;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqphsv = sqlstm.sqhstv;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqphsl = sqlstm.sqhstl;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqphss = sqlstm.sqhsts;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqpind = sqlstm.sqindv;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqpins = sqlstm.sqinds;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqparm = sqlstm.sqharm;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqparc = sqlstm.sqharc;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqpadto = sqlstm.sqadto;
#line 2662 "DM_DbInterface.pc"
sqlstm.sqptdso = sqlstm.sqtdso;
#line 2662 "DM_DbInterface.pc"
sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2662 "DM_DbInterface.pc"
}

#line 2662 "DM_DbInterface.pc"


IS_ANY_ORA_ERROR

RETURN_SUCCESS:

APL_FREE(l_mt_pty_depo_map_struct_i);

APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

APL_FREE(l_mt_pty_depo_map_struct_i);

APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}



int MT_UpdDL_DEAL(DL_DEAL_STRUCT_H *p_dl_deal_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)	{

struct sqlca sqlca;

DL_DEAL_STRUCT_I *l_dl_deal_struct_i = (DL_DEAL_STRUCT_I *)NULL;

l_dl_deal_struct_i = (DL_DEAL_STRUCT_I *)calloc(1,sizeof(DL_DEAL_STRUCT_I));



	if(!strlen(p_dl_deal_struct_h ->h_client))
l_dl_deal_struct_i -> i_client= -1;
	if(!strlen(p_dl_deal_struct_h ->h_identiy_no))
l_dl_deal_struct_i -> i_identiy_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_deal_date))
l_dl_deal_struct_i -> i_deal_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_setl_date))
l_dl_deal_struct_i -> i_setl_date= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_ex_arena))
l_dl_deal_struct_i -> i_ex_arena= -1;
	
	
	
	
	
	if(!strlen(p_dl_deal_struct_h ->h_instrument_dt))
l_dl_deal_struct_i -> i_instrument_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_money_setl_dt))
l_dl_deal_struct_i -> i_money_setl_dt= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_domestic_cpclt))
l_dl_deal_struct_i -> i_domestic_cpclt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_spottrd_ind))
l_dl_deal_struct_i -> i_spottrd_ind= -1;
	
	
	if(!strlen(p_dl_deal_struct_h ->h_deal_frm_ord))
l_dl_deal_struct_i -> i_deal_frm_ord= -1;
	if(!strlen(p_dl_deal_struct_h ->h_entry))
l_dl_deal_struct_i -> i_entry= -1;
	if(!strlen(p_dl_deal_struct_h ->h_reapired_ind))
l_dl_deal_struct_i -> i_reapired_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_domcp_custodyclt))
l_dl_deal_struct_i -> i_domcp_custodyclt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_cp_clt))
l_dl_deal_struct_i -> i_cp_clt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_cp_cltname))
l_dl_deal_struct_i -> i_cp_cltname= -1;
	if(!strlen(p_dl_deal_struct_h ->h_clientof))
l_dl_deal_struct_i -> i_clientof= -1;
	if(!strlen(p_dl_deal_struct_h ->h_client_note))
l_dl_deal_struct_i -> i_client_note= -1;
	if(!strlen(p_dl_deal_struct_h ->h_fx_reqd))
l_dl_deal_struct_i -> i_fx_reqd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_payloc_ind))
l_dl_deal_struct_i -> i_payloc_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_verfied_with))
l_dl_deal_struct_i -> i_verfied_with= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_brk_no))
l_dl_deal_struct_i -> i_brk_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_failreason_cd))
l_dl_deal_struct_i -> i_failreason_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_fail_det))
l_dl_deal_struct_i -> i_fail_det= -1;
	if(!strlen(p_dl_deal_struct_h ->h_partial_ind_b))
l_dl_deal_struct_i -> i_partial_ind_b= -1;
	
	
	
	if(!strlen(p_dl_deal_struct_h ->h_report_at_eom_ind))
l_dl_deal_struct_i -> i_report_at_eom_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dateofbilling))
l_dl_deal_struct_i -> i_dateofbilling= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lcl_identno))
l_dl_deal_struct_i -> i_lcl_identno= -1;
	if(!strlen(p_dl_deal_struct_h ->h_instruct_person))
l_dl_deal_struct_i -> i_instruct_person= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_deal_cd))
l_dl_deal_struct_i -> i_deal_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_instr_code))
l_dl_deal_struct_i -> i_instr_code= -1;
	if(!strlen(p_dl_deal_struct_h ->h_currency_cd))
l_dl_deal_struct_i -> i_currency_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dl_class))
l_dl_deal_struct_i -> i_dl_class= -1;
	if(!strlen(p_dl_deal_struct_h ->h_orig_refno))
l_dl_deal_struct_i -> i_orig_refno= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dateof_input))
l_dl_deal_struct_i -> i_dateof_input= -1;
	if(!strlen(p_dl_deal_struct_h ->h_maker))
l_dl_deal_struct_i -> i_maker= -1;
	if(!strlen(p_dl_deal_struct_h ->h_maker_dt))
l_dl_deal_struct_i -> i_maker_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_deal_stat))
l_dl_deal_struct_i -> i_deal_stat= -1;
	if(!strlen(p_dl_deal_struct_h ->h_access_stamp))
l_dl_deal_struct_i -> i_access_stamp= -1;
	if(!strlen(p_dl_deal_struct_h ->h_info1))
l_dl_deal_struct_i -> i_info1= -1;
	if(!strlen(p_dl_deal_struct_h ->h_location_cd))
l_dl_deal_struct_i -> i_location_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_reginstr_ind))
l_dl_deal_struct_i -> i_reginstr_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_status_pos))
l_dl_deal_struct_i -> i_status_pos= -1;
	if(!strlen(p_dl_deal_struct_h ->h_status))
l_dl_deal_struct_i -> i_status= -1;
	if(!strlen(p_dl_deal_struct_h ->h_val_fdt))
l_dl_deal_struct_i -> i_val_fdt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_comprefno))
l_dl_deal_struct_i -> i_comprefno= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dateof_markfail))
l_dl_deal_struct_i -> i_dateof_markfail= -1;
	if(!strlen(p_dl_deal_struct_h ->h_allow_dropdt))
l_dl_deal_struct_i -> i_allow_dropdt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_checker))
l_dl_deal_struct_i -> i_checker= -1;
	if(!strlen(p_dl_deal_struct_h ->h_checker_dt))
l_dl_deal_struct_i -> i_checker_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_instrconv_ind))
l_dl_deal_struct_i -> i_instrconv_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_nds_blk_dt))
l_dl_deal_struct_i -> i_nds_blk_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lr_dl_class))
l_dl_deal_struct_i -> i_lr_dl_class= -1;
	if(!strlen(p_dl_deal_struct_h ->h_nds_date))
l_dl_deal_struct_i -> i_nds_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_unblk_date))
l_dl_deal_struct_i -> i_unblk_date= -1;
	
	
	
	if(!strlen(p_dl_deal_struct_h ->h_del_rec_date))
l_dl_deal_struct_i -> i_del_rec_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_last_reg_date))
l_dl_deal_struct_i -> i_last_reg_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lr_check_date))
l_dl_deal_struct_i -> i_lr_check_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lr_valdate))
l_dl_deal_struct_i -> i_lr_valdate= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lrinstr_date))
l_dl_deal_struct_i -> i_lrinstr_date= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_tmp_out_dt))
l_dl_deal_struct_i -> i_tmp_out_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_tmp_out_date))
l_dl_deal_struct_i -> i_tmp_out_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_trans_date))
l_dl_deal_struct_i -> i_trans_date= -1;
	
	
	
	
	
	
	
	
	
	
	
	if(!strlen(p_dl_deal_struct_h ->h_host_date))
l_dl_deal_struct_i -> i_host_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lrnds_billdt))
l_dl_deal_struct_i -> i_lrnds_billdt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lrnds_date))
l_dl_deal_struct_i -> i_lrnds_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_lr_unblk_date))
l_dl_deal_struct_i -> i_lr_unblk_date= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_clt_reqdel_ind))
l_dl_deal_struct_i -> i_clt_reqdel_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_mod_hispos_ind))
l_dl_deal_struct_i -> i_mod_hispos_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_mod_hispos_date))
l_dl_deal_struct_i -> i_mod_hispos_date= -1;
	if(!strlen(p_dl_deal_struct_h ->h_gl_client))
l_dl_deal_struct_i -> i_gl_client= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_msg_stat))
l_dl_deal_struct_i -> i_msg_stat= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_partial_ind_a))
l_dl_deal_struct_i -> i_partial_ind_a= -1;
	if(!strlen(p_dl_deal_struct_h ->h_loc_chng_ind))
l_dl_deal_struct_i -> i_loc_chng_ind= -1;
	if(!strlen(p_dl_deal_struct_h ->h_comm_ident_no))
l_dl_deal_struct_i -> i_comm_ident_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_instruct_personnm))
l_dl_deal_struct_i -> i_instruct_personnm= -1;
	if(!strlen(p_dl_deal_struct_h ->h_clientof_cd))
l_dl_deal_struct_i -> i_clientof_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_inter_med_person))
l_dl_deal_struct_i -> i_inter_med_person= -1;
	if(!strlen(p_dl_deal_struct_h ->h_inter_med_personnm))
l_dl_deal_struct_i -> i_inter_med_personnm= -1;
	if(!strlen(p_dl_deal_struct_h ->h_fxccy))
l_dl_deal_struct_i -> i_fxccy= -1;
	if(!strlen(p_dl_deal_struct_h ->h_uniq_ident_no))
l_dl_deal_struct_i -> i_uniq_ident_no= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_exp_setldate))
l_dl_deal_struct_i -> i_exp_setldate= -1;
	if(!strlen(p_dl_deal_struct_h ->h_related_ident_no))
l_dl_deal_struct_i -> i_related_ident_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_informaton))
l_dl_deal_struct_i -> i_informaton= -1;
	if(!strlen(p_dl_deal_struct_h ->h_settlement_no))
l_dl_deal_struct_i -> i_settlement_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_mkt_type))
l_dl_deal_struct_i -> i_mkt_type= -1;
	if(!strlen(p_dl_deal_struct_h ->h_clh_flg))
l_dl_deal_struct_i -> i_clh_flg= -1;
	
	
	if(!strlen(p_dl_deal_struct_h ->h_payin_dt))
l_dl_deal_struct_i -> i_payin_dt= -1;
	if(!strlen(p_dl_deal_struct_h ->h_payout_dt))
l_dl_deal_struct_i -> i_payout_dt= -1;
	
	if(!strlen(p_dl_deal_struct_h ->h_contract_req))
l_dl_deal_struct_i -> i_contract_req= -1;
	if(!strlen(p_dl_deal_struct_h ->h_excum_flg))
l_dl_deal_struct_i -> i_excum_flg= -1;
	if(!strlen(p_dl_deal_struct_h ->h_crn_no))
l_dl_deal_struct_i -> i_crn_no= -1;
	if(!strlen(p_dl_deal_struct_h ->h_interfii_flg))
l_dl_deal_struct_i -> i_interfii_flg= -1;
	if(!strlen(p_dl_deal_struct_h ->h_pay_mode))
l_dl_deal_struct_i -> i_pay_mode= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dl_secstatus))
l_dl_deal_struct_i -> i_dl_secstatus= -1;
	if(!strlen(p_dl_deal_struct_h ->h_dl_mnystatus))
l_dl_deal_struct_i -> i_dl_mnystatus= -1;
	
	
	
	if(!strlen(p_dl_deal_struct_h ->h_cln_depoacc))
l_dl_deal_struct_i -> i_cln_depoacc= -1;
	if(!strlen(p_dl_deal_struct_h ->h_pltopl_flg))
l_dl_deal_struct_i -> i_pltopl_flg= -1;
	if(!strlen(p_dl_deal_struct_h ->h_orig_status))
l_dl_deal_struct_i -> i_orig_status= -1;
	if(!strlen(p_dl_deal_struct_h ->h_map_failcode))
l_dl_deal_struct_i -> i_map_failcode= -1;
	if(!strlen(p_dl_deal_struct_h ->h_match_failcode))
l_dl_deal_struct_i -> i_match_failcode= -1;
	if(!strlen(p_dl_deal_struct_h ->h_is_matched))
l_dl_deal_struct_i -> i_is_matched= -1;
	if(!strlen(p_dl_deal_struct_h ->h_exch_code))
l_dl_deal_struct_i -> i_exch_code= -1;
	if(!strlen(p_dl_deal_struct_h ->h_contract_cd))
l_dl_deal_struct_i -> i_contract_cd= -1;
	if(!strlen(p_dl_deal_struct_h ->h_r_delay))
l_dl_deal_struct_i -> i_r_delay= -1;
	if(!strlen(p_dl_deal_struct_h ->h_sebi_reported))
l_dl_deal_struct_i -> i_sebi_reported= -1;
	if(!strlen(p_dl_deal_struct_h ->h_r_sett_code))
l_dl_deal_struct_i -> i_r_sett_code= -1;
	if(!strlen(p_dl_deal_struct_h ->h_r_trans_code))
l_dl_deal_struct_i -> i_r_trans_code= -1;
	if(!strlen(p_dl_deal_struct_h ->h_r_type))
l_dl_deal_struct_i -> i_r_type= -1;
	if(!strlen(p_dl_deal_struct_h ->h_repo_date))
l_dl_deal_struct_i -> i_repo_date= -1;


/* EXEC SQL INSERT INTO DL_DEAL VALUES(:p_dl_deal_struct_h:l_dl_deal_struct_i); */ 
#line 2951 "DM_DbInterface.pc"

{
#line 2951 "DM_DbInterface.pc"
struct sqlexd sqlstm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqlvsn = 12;
#line 2951 "DM_DbInterface.pc"
sqlstm.arrsiz = 150;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqladtp = &sqladt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqltdsp = &sqltds;
#line 2951 "DM_DbInterface.pc"
sqlbuft((void **)0, 
#line 2951 "DM_DbInterface.pc"
  "insert into DL_DEAL  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s1\
1:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s24 ,:s25:s26 \
,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,:s39:s40 ,:s41:\
s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54 ,:s55:s56 ,:\
s57:s58 ,:s59:s60 ,:s61:s62 ,:s63:s64 ,:s65:s66 ,:s67:s68 ,:s69:s70 ,:s71:s7\
2 ,:s73:s74 ,:s75:s76 ,:s77:s78 ,:s79:s80 ,:s81:s82 ,:s83:s84 ,:s85:s86 ,:s8\
7:s88 ,:s89:s90 ,:s91:s92 ,:s93:s94 ,:s95:s96 ,:s97:s98 ,:s99:s100 ,:s101:s1\
02 ,:s103:s104 ,:s105:s106 ,:s107:s108 ,:s109:s110 ,:s111:s112 ,:s113:s114 ,\
:s115:s116 ,:s117:s118 ,:s119:s120 ,:s121:s122 ,:s123:s124 ,:s125:s126 ,:s12\
7:s128 ,:s129:s130 ,:s131:s132 ,:s133:s134 ,:s135:s136 ,:s137:s138 ,:s139:s1\
40 ,:s141:s142 ,:s143:s144 ,:s145:s146 ,:s147:s148 ,:s149:s150 ,:s151:s152 ,\
:s153:s154 ,:s155:s156 ,:s157:s158 ,:s159:s160 ,:s161:s162 ,:s163:s164 ,:s16\
5:s166 ,:s167:s168 ,:s169:s170 ,:s171:s172 ,:s173:s174 ,:s175:s176 ,:s177:s1\
78 ,:s179:s180 ,:s181:s182 ,:s183:s184 ");
#line 2951 "DM_DbInterface.pc"
sqlstm.stmt = ",:s185:s186 ,:s187:s188 ,:s189:s190 ,:s191:s192 ,:s193:s194 ,\
:s195:s196 ,:s197:s198 ,:s199:s200 ,:s201:s202 ,:s203:s204 ,:s205:s206 ,:s207:\
s208 ,:s209:s210 ,:s211:s212 ,:s213:s214 ,:s215:s216 ,:s217:s218 ,:s219:s220 ,\
:s221:s222 ,:s223:s224 ,:s225:s226 ,:s227:s228 ,:s229:s230 ,:s231:s232 ,:s233:\
s234 ,:s235:s236 ,:s237:s238 ,:s239:s240 ,:s241:s242 ,:s243:s244 ,:s245:s246 ,\
:s247:s248 ,:s249:s250 ,:s251:s252 ,:s253:s254 ,:s255:s256 ,:s257:s258 ,:s259:\
s260 ,:s261:s262 ,:s263:s264 ,:s265:s266 ,:s267:s268 ,:s269:s270 ,:s271:s272 ,\
:s273:s274 ,:s275:s276 ,:s277:s278 ,:s279:s280 ,:s281:s282 ,:s283:s284 ,:s285:\
s286 ,:s287:s288 ,:s289:s290 ,:s291:s292 ,:s293:s294 ,:s295:s296 ,:s297 ,:s298\
 )";
#line 2951 "DM_DbInterface.pc"
sqlstm.iters = (unsigned int  )1;
#line 2951 "DM_DbInterface.pc"
sqlstm.offset = (unsigned int  )2909;
#line 2951 "DM_DbInterface.pc"
sqlstm.cud = sqlcud0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqlety = (unsigned short)256;
#line 2951 "DM_DbInterface.pc"
sqlstm.occurs = (unsigned int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[0] = (unsigned char  *)p_dl_deal_struct_h->h_client;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[0] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[0] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[0] = (         short *)&l_dl_deal_struct_i->i_client;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[0] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[0] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[0] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[0] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[1] = (unsigned char  *)p_dl_deal_struct_h->h_identiy_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[1] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[1] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[1] = (         short *)&l_dl_deal_struct_i->i_identiy_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[1] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[1] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[1] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[1] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[2] = (unsigned char  *)p_dl_deal_struct_h->h_deal_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[2] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[2] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[2] = (         short *)&l_dl_deal_struct_i->i_deal_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[2] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[2] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[2] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[2] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[3] = (unsigned char  *)p_dl_deal_struct_h->h_setl_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[3] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[3] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[3] = (         short *)&l_dl_deal_struct_i->i_setl_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[3] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[3] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[3] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[3] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[4] = (unsigned char  *)&p_dl_deal_struct_h->h_cost;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[4] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[4] = (         short *)&l_dl_deal_struct_i->i_cost;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[4] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[4] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[4] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[4] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[5] = (unsigned char  *)p_dl_deal_struct_h->h_ex_arena;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[5] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[5] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[5] = (         short *)&l_dl_deal_struct_i->i_ex_arena;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[5] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[5] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[5] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[5] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[6] = (unsigned char  *)&p_dl_deal_struct_h->h_amount;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[6] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[6] = (         short *)&l_dl_deal_struct_i->i_amount;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[6] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[6] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[6] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[6] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[7] = (unsigned char  *)&p_dl_deal_struct_h->h_custodycomm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[7] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[7] = (         short *)&l_dl_deal_struct_i->i_custodycomm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[7] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[7] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[7] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[7] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[8] = (unsigned char  *)&p_dl_deal_struct_h->h_brokercomm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[8] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[8] = (         short *)&l_dl_deal_struct_i->i_brokercomm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[8] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[8] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[8] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[8] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[9] = (unsigned char  *)&p_dl_deal_struct_h->h_stx_comm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[9] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[9] = (         short *)&l_dl_deal_struct_i->i_stx_comm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[9] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[9] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[9] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[9] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[10] = (unsigned char  *)&p_dl_deal_struct_h->h_oth_comm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[10] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[10] = (         short *)&l_dl_deal_struct_i->i_oth_comm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[10] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[10] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[10] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[10] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[11] = (unsigned char  *)p_dl_deal_struct_h->h_instrument_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[11] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[11] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[11] = (         short *)&l_dl_deal_struct_i->i_instrument_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[11] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[11] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[11] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[11] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[12] = (unsigned char  *)p_dl_deal_struct_h->h_money_setl_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[12] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[12] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[12] = (         short *)&l_dl_deal_struct_i->i_money_setl_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[12] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[12] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[12] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[12] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[13] = (unsigned char  *)&p_dl_deal_struct_h->h_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[13] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[13] = (         short *)&l_dl_deal_struct_i->i_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[13] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[13] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[13] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[13] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[14] = (unsigned char  *)p_dl_deal_struct_h->h_domestic_cpclt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[14] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[14] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[14] = (         short *)&l_dl_deal_struct_i->i_domestic_cpclt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[14] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[14] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[14] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[14] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[15] = (unsigned char  *)p_dl_deal_struct_h->h_spottrd_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[15] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[15] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[15] = (         short *)&l_dl_deal_struct_i->i_spottrd_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[15] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[15] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[15] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[15] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[16] = (unsigned char  *)&p_dl_deal_struct_h->h_orig_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[16] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[16] = (         short *)&l_dl_deal_struct_i->i_orig_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[16] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[16] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[16] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[16] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[17] = (unsigned char  *)&p_dl_deal_struct_h->h_orig_amount;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[17] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[17] = (         short *)&l_dl_deal_struct_i->i_orig_amount;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[17] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[17] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[17] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[17] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[18] = (unsigned char  *)p_dl_deal_struct_h->h_deal_frm_ord;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[18] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[18] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[18] = (         short *)&l_dl_deal_struct_i->i_deal_frm_ord;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[18] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[18] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[18] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[18] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[19] = (unsigned char  *)p_dl_deal_struct_h->h_entry;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[19] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[19] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[19] = (         short *)&l_dl_deal_struct_i->i_entry;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[19] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[19] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[19] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[19] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[20] = (unsigned char  *)p_dl_deal_struct_h->h_reapired_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[20] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[20] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[20] = (         short *)&l_dl_deal_struct_i->i_reapired_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[20] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[20] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[20] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[20] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[21] = (unsigned char  *)p_dl_deal_struct_h->h_domcp_custodyclt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[21] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[21] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[21] = (         short *)&l_dl_deal_struct_i->i_domcp_custodyclt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[21] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[21] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[21] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[21] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[22] = (unsigned char  *)p_dl_deal_struct_h->h_cp_clt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[22] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[22] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[22] = (         short *)&l_dl_deal_struct_i->i_cp_clt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[22] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[22] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[22] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[22] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[23] = (unsigned char  *)p_dl_deal_struct_h->h_cp_cltname;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[23] = (unsigned long )66;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[23] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[23] = (         short *)&l_dl_deal_struct_i->i_cp_cltname;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[23] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[23] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[23] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[23] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[24] = (unsigned char  *)p_dl_deal_struct_h->h_clientof;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[24] = (unsigned long )66;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[24] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[24] = (         short *)&l_dl_deal_struct_i->i_clientof;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[24] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[24] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[24] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[24] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[25] = (unsigned char  *)p_dl_deal_struct_h->h_client_note;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[25] = (unsigned long )71;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[25] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[25] = (         short *)&l_dl_deal_struct_i->i_client_note;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[25] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[25] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[25] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[25] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[26] = (unsigned char  *)p_dl_deal_struct_h->h_fx_reqd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[26] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[26] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[26] = (         short *)&l_dl_deal_struct_i->i_fx_reqd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[26] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[26] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[26] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[26] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[27] = (unsigned char  *)p_dl_deal_struct_h->h_payloc_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[27] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[27] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[27] = (         short *)&l_dl_deal_struct_i->i_payloc_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[27] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[27] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[27] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[27] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[28] = (unsigned char  *)p_dl_deal_struct_h->h_verfied_with;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[28] = (unsigned long )26;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[28] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[28] = (         short *)&l_dl_deal_struct_i->i_verfied_with;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[28] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[28] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[28] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[28] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[29] = (unsigned char  *)&p_dl_deal_struct_h->h_amt_differ;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[29] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[29] = (         short *)&l_dl_deal_struct_i->i_amt_differ;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[29] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[29] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[29] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[29] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[30] = (unsigned char  *)p_dl_deal_struct_h->h_brk_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[30] = (unsigned long )13;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[30] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[30] = (         short *)&l_dl_deal_struct_i->i_brk_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[30] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[30] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[30] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[30] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[31] = (unsigned char  *)p_dl_deal_struct_h->h_failreason_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[31] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[31] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[31] = (         short *)&l_dl_deal_struct_i->i_failreason_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[31] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[31] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[31] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[31] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[32] = (unsigned char  *)p_dl_deal_struct_h->h_fail_det;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[32] = (unsigned long )36;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[32] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[32] = (         short *)&l_dl_deal_struct_i->i_fail_det;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[32] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[32] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[32] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[32] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[33] = (unsigned char  *)p_dl_deal_struct_h->h_partial_ind_b;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[33] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[33] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[33] = (         short *)&l_dl_deal_struct_i->i_partial_ind_b;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[33] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[33] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[33] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[33] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[34] = (unsigned char  *)&p_dl_deal_struct_h->h_fx_rt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[34] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[34] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[34] = (         short *)&l_dl_deal_struct_i->i_fx_rt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[34] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[34] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[34] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[34] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[35] = (unsigned char  *)&p_dl_deal_struct_h->h_amend_count;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[35] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[35] = (         short *)&l_dl_deal_struct_i->i_amend_count;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[35] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[35] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[35] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[35] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[36] = (unsigned char  *)&p_dl_deal_struct_h->h_number_a;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[36] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[36] = (         short *)&l_dl_deal_struct_i->i_number_a;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[36] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[36] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[36] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[36] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[37] = (unsigned char  *)p_dl_deal_struct_h->h_report_at_eom_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[37] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[37] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[37] = (         short *)&l_dl_deal_struct_i->i_report_at_eom_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[37] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[37] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[37] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[37] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[38] = (unsigned char  *)p_dl_deal_struct_h->h_dateofbilling;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[38] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[38] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[38] = (         short *)&l_dl_deal_struct_i->i_dateofbilling;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[38] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[38] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[38] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[38] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[39] = (unsigned char  *)p_dl_deal_struct_h->h_lcl_identno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[39] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[39] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[39] = (         short *)&l_dl_deal_struct_i->i_lcl_identno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[39] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[39] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[39] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[39] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[40] = (unsigned char  *)p_dl_deal_struct_h->h_instruct_person;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[40] = (unsigned long )36;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[40] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[40] = (         short *)&l_dl_deal_struct_i->i_instruct_person;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[40] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[40] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[40] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[40] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[41] = (unsigned char  *)&p_dl_deal_struct_h->h_rec_int_000;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[41] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[41] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[41] = (         short *)&l_dl_deal_struct_i->i_rec_int_000;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[41] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[41] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[41] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[41] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[42] = (unsigned char  *)p_dl_deal_struct_h->h_deal_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[42] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[42] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[42] = (         short *)&l_dl_deal_struct_i->i_deal_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[42] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[42] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[42] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[42] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[43] = (unsigned char  *)p_dl_deal_struct_h->h_instr_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[43] = (unsigned long )9;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[43] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[43] = (         short *)&l_dl_deal_struct_i->i_instr_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[43] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[43] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[43] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[43] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[44] = (unsigned char  *)p_dl_deal_struct_h->h_currency_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[44] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[44] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[44] = (         short *)&l_dl_deal_struct_i->i_currency_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[44] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[44] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[44] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[44] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[45] = (unsigned char  *)p_dl_deal_struct_h->h_dl_class;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[45] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[45] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[45] = (         short *)&l_dl_deal_struct_i->i_dl_class;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[45] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[45] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[45] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[45] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[46] = (unsigned char  *)p_dl_deal_struct_h->h_orig_refno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[46] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[46] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[46] = (         short *)&l_dl_deal_struct_i->i_orig_refno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[46] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[46] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[46] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[46] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[47] = (unsigned char  *)p_dl_deal_struct_h->h_dateof_input;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[47] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[47] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[47] = (         short *)&l_dl_deal_struct_i->i_dateof_input;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[47] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[47] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[47] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[47] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[48] = (unsigned char  *)p_dl_deal_struct_h->h_maker;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[48] = (unsigned long )15;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[48] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[48] = (         short *)&l_dl_deal_struct_i->i_maker;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[48] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[48] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[48] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[48] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[49] = (unsigned char  *)p_dl_deal_struct_h->h_maker_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[49] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[49] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[49] = (         short *)&l_dl_deal_struct_i->i_maker_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[49] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[49] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[49] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[49] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[50] = (unsigned char  *)p_dl_deal_struct_h->h_deal_stat;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[50] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[50] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[50] = (         short *)&l_dl_deal_struct_i->i_deal_stat;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[50] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[50] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[50] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[50] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[51] = (unsigned char  *)p_dl_deal_struct_h->h_access_stamp;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[51] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[51] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[51] = (         short *)&l_dl_deal_struct_i->i_access_stamp;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[51] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[51] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[51] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[51] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[52] = (unsigned char  *)p_dl_deal_struct_h->h_info1;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[52] = (unsigned long )261;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[52] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[52] = (         short *)&l_dl_deal_struct_i->i_info1;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[52] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[52] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[52] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[52] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[53] = (unsigned char  *)p_dl_deal_struct_h->h_location_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[53] = (unsigned long )5;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[53] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[53] = (         short *)&l_dl_deal_struct_i->i_location_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[53] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[53] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[53] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[53] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[54] = (unsigned char  *)p_dl_deal_struct_h->h_reginstr_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[54] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[54] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[54] = (         short *)&l_dl_deal_struct_i->i_reginstr_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[54] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[54] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[54] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[54] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[55] = (unsigned char  *)p_dl_deal_struct_h->h_status_pos;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[55] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[55] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[55] = (         short *)&l_dl_deal_struct_i->i_status_pos;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[55] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[55] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[55] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[55] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[56] = (unsigned char  *)p_dl_deal_struct_h->h_status;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[56] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[56] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[56] = (         short *)&l_dl_deal_struct_i->i_status;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[56] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[56] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[56] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[56] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[57] = (unsigned char  *)p_dl_deal_struct_h->h_val_fdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[57] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[57] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[57] = (         short *)&l_dl_deal_struct_i->i_val_fdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[57] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[57] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[57] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[57] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[58] = (unsigned char  *)p_dl_deal_struct_h->h_comprefno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[58] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[58] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[58] = (         short *)&l_dl_deal_struct_i->i_comprefno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[58] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[58] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[58] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[58] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[59] = (unsigned char  *)p_dl_deal_struct_h->h_dateof_markfail;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[59] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[59] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[59] = (         short *)&l_dl_deal_struct_i->i_dateof_markfail;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[59] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[59] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[59] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[59] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[60] = (unsigned char  *)p_dl_deal_struct_h->h_allow_dropdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[60] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[60] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[60] = (         short *)&l_dl_deal_struct_i->i_allow_dropdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[60] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[60] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[60] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[60] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[61] = (unsigned char  *)p_dl_deal_struct_h->h_checker;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[61] = (unsigned long )15;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[61] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[61] = (         short *)&l_dl_deal_struct_i->i_checker;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[61] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[61] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[61] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[61] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[62] = (unsigned char  *)p_dl_deal_struct_h->h_checker_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[62] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[62] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[62] = (         short *)&l_dl_deal_struct_i->i_checker_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[62] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[62] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[62] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[62] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[63] = (unsigned char  *)p_dl_deal_struct_h->h_instrconv_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[63] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[63] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[63] = (         short *)&l_dl_deal_struct_i->i_instrconv_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[63] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[63] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[63] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[63] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[64] = (unsigned char  *)p_dl_deal_struct_h->h_nds_blk_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[64] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[64] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[64] = (         short *)&l_dl_deal_struct_i->i_nds_blk_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[64] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[64] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[64] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[64] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[65] = (unsigned char  *)p_dl_deal_struct_h->h_lr_dl_class;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[65] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[65] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[65] = (         short *)&l_dl_deal_struct_i->i_lr_dl_class;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[65] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[65] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[65] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[65] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[66] = (unsigned char  *)p_dl_deal_struct_h->h_nds_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[66] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[66] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[66] = (         short *)&l_dl_deal_struct_i->i_nds_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[66] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[66] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[66] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[66] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[67] = (unsigned char  *)p_dl_deal_struct_h->h_unblk_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[67] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[67] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[67] = (         short *)&l_dl_deal_struct_i->i_unblk_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[67] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[67] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[67] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[67] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[68] = (unsigned char  *)&p_dl_deal_struct_h->h_delta_000;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[68] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[68] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[68] = (         short *)&l_dl_deal_struct_i->i_delta_000;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[68] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[68] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[68] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[68] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[69] = (unsigned char  *)&p_dl_deal_struct_h->h_delta_001;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[69] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[69] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[69] = (         short *)&l_dl_deal_struct_i->i_delta_001;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[69] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[69] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[69] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[69] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[70] = (unsigned char  *)&p_dl_deal_struct_h->h_delta_003;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[70] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[70] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[70] = (         short *)&l_dl_deal_struct_i->i_delta_003;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[70] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[70] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[70] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[70] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[71] = (unsigned char  *)p_dl_deal_struct_h->h_del_rec_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[71] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[71] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[71] = (         short *)&l_dl_deal_struct_i->i_del_rec_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[71] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[71] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[71] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[71] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[72] = (unsigned char  *)p_dl_deal_struct_h->h_last_reg_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[72] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[72] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[72] = (         short *)&l_dl_deal_struct_i->i_last_reg_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[72] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[72] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[72] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[72] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[73] = (unsigned char  *)p_dl_deal_struct_h->h_lr_check_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[73] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[73] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[73] = (         short *)&l_dl_deal_struct_i->i_lr_check_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[73] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[73] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[73] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[73] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[74] = (unsigned char  *)p_dl_deal_struct_h->h_lr_valdate;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[74] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[74] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[74] = (         short *)&l_dl_deal_struct_i->i_lr_valdate;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[74] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[74] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[74] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[74] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[75] = (unsigned char  *)p_dl_deal_struct_h->h_lrinstr_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[75] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[75] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[75] = (         short *)&l_dl_deal_struct_i->i_lrinstr_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[75] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[75] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[75] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[75] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[76] = (unsigned char  *)&p_dl_deal_struct_h->h_reg_msg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[76] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[76] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[76] = (         short *)&l_dl_deal_struct_i->i_reg_msg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[76] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[76] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[76] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[76] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[77] = (unsigned char  *)p_dl_deal_struct_h->h_tmp_out_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[77] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[77] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[77] = (         short *)&l_dl_deal_struct_i->i_tmp_out_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[77] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[77] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[77] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[77] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[78] = (unsigned char  *)p_dl_deal_struct_h->h_tmp_out_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[78] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[78] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[78] = (         short *)&l_dl_deal_struct_i->i_tmp_out_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[78] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[78] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[78] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[78] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[79] = (unsigned char  *)p_dl_deal_struct_h->h_trans_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[79] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[79] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[79] = (         short *)&l_dl_deal_struct_i->i_trans_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[79] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[79] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[79] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[79] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[80] = (unsigned char  *)&p_dl_deal_struct_h->h_tot_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[80] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[80] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[80] = (         short *)&l_dl_deal_struct_i->i_tot_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[80] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[80] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[80] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[80] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[81] = (unsigned char  *)&p_dl_deal_struct_h->h_qty_lost;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[81] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[81] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[81] = (         short *)&l_dl_deal_struct_i->i_qty_lost;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[81] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[81] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[81] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[81] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[82] = (unsigned char  *)&p_dl_deal_struct_h->h_mrk_dl_failqty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[82] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[82] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[82] = (         short *)&l_dl_deal_struct_i->i_mrk_dl_failqty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[82] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[82] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[82] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[82] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[83] = (unsigned char  *)&p_dl_deal_struct_h->h_dl_completeqty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[83] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[83] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[83] = (         short *)&l_dl_deal_struct_i->i_dl_completeqty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[83] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[83] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[83] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[83] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[84] = (unsigned char  *)&p_dl_deal_struct_h->h_out_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[84] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[84] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[84] = (         short *)&l_dl_deal_struct_i->i_out_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[84] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[84] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[84] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[84] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[85] = (unsigned char  *)&p_dl_deal_struct_h->h_pend_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[85] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[85] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[85] = (         short *)&l_dl_deal_struct_i->i_pend_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[85] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[85] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[85] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[85] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[86] = (unsigned char  *)&p_dl_deal_struct_h->h_ret_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[86] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[86] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[86] = (         short *)&l_dl_deal_struct_i->i_ret_reg_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[86] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[86] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[86] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[86] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[87] = (unsigned char  *)&p_dl_deal_struct_h->h_stamp_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[87] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[87] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[87] = (         short *)&l_dl_deal_struct_i->i_stamp_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[87] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[87] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[87] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[87] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[88] = (unsigned char  *)&p_dl_deal_struct_h->h_temp_out_quantity;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[88] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[88] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[88] = (         short *)&l_dl_deal_struct_i->i_temp_out_quantity;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[88] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[88] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[88] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[88] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[89] = (unsigned char  *)&p_dl_deal_struct_h->h_temp_ret_quantity;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[89] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[89] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[89] = (         short *)&l_dl_deal_struct_i->i_temp_ret_quantity;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[89] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[89] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[89] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[89] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[90] = (unsigned char  *)&p_dl_deal_struct_h->h_val_deed_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[90] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[90] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[90] = (         short *)&l_dl_deal_struct_i->i_val_deed_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[90] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[90] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[90] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[90] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[91] = (unsigned char  *)p_dl_deal_struct_h->h_host_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[91] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[91] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[91] = (         short *)&l_dl_deal_struct_i->i_host_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[91] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[91] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[91] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[91] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[92] = (unsigned char  *)p_dl_deal_struct_h->h_lrnds_billdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[92] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[92] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[92] = (         short *)&l_dl_deal_struct_i->i_lrnds_billdt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[92] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[92] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[92] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[92] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[93] = (unsigned char  *)p_dl_deal_struct_h->h_lrnds_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[93] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[93] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[93] = (         short *)&l_dl_deal_struct_i->i_lrnds_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[93] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[93] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[93] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[93] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[94] = (unsigned char  *)p_dl_deal_struct_h->h_lr_unblk_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[94] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[94] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[94] = (         short *)&l_dl_deal_struct_i->i_lr_unblk_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[94] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[94] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[94] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[94] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[95] = (unsigned char  *)&p_dl_deal_struct_h->h_number_b;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[95] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[95] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[95] = (         short *)&l_dl_deal_struct_i->i_number_b;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[95] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[95] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[95] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[95] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[96] = (unsigned char  *)p_dl_deal_struct_h->h_clt_reqdel_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[96] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[96] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[96] = (         short *)&l_dl_deal_struct_i->i_clt_reqdel_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[96] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[96] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[96] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[96] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[97] = (unsigned char  *)p_dl_deal_struct_h->h_mod_hispos_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[97] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[97] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[97] = (         short *)&l_dl_deal_struct_i->i_mod_hispos_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[97] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[97] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[97] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[97] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[98] = (unsigned char  *)p_dl_deal_struct_h->h_mod_hispos_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[98] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[98] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[98] = (         short *)&l_dl_deal_struct_i->i_mod_hispos_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[98] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[98] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[98] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[98] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[99] = (unsigned char  *)p_dl_deal_struct_h->h_gl_client;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[99] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[99] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[99] = (         short *)&l_dl_deal_struct_i->i_gl_client;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[99] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[99] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[99] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[99] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[100] = (unsigned char  *)&p_dl_deal_struct_h->h_cp_amt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[100] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[100] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[100] = (         short *)&l_dl_deal_struct_i->i_cp_amt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[100] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[100] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[100] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[100] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[101] = (unsigned char  *)p_dl_deal_struct_h->h_msg_stat;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[101] = (unsigned long )51;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[101] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[101] = (         short *)&l_dl_deal_struct_i->i_msg_stat;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[101] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[101] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[101] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[101] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[102] = (unsigned char  *)&p_dl_deal_struct_h->h_sub_fail_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[102] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[102] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[102] = (         short *)&l_dl_deal_struct_i->i_sub_fail_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[102] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[102] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[102] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[102] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[103] = (unsigned char  *)p_dl_deal_struct_h->h_partial_ind_a;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[103] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[103] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[103] = (         short *)&l_dl_deal_struct_i->i_partial_ind_a;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[103] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[103] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[103] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[103] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[104] = (unsigned char  *)p_dl_deal_struct_h->h_loc_chng_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[104] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[104] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[104] = (         short *)&l_dl_deal_struct_i->i_loc_chng_ind;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[104] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[104] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[104] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[104] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[105] = (unsigned char  *)p_dl_deal_struct_h->h_comm_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[105] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[105] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[105] = (         short *)&l_dl_deal_struct_i->i_comm_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[105] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[105] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[105] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[105] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[106] = (unsigned char  *)p_dl_deal_struct_h->h_instruct_personnm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[106] = (unsigned long )66;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[106] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[106] = (         short *)&l_dl_deal_struct_i->i_instruct_personnm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[106] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[106] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[106] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[106] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[107] = (unsigned char  *)p_dl_deal_struct_h->h_clientof_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[107] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[107] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[107] = (         short *)&l_dl_deal_struct_i->i_clientof_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[107] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[107] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[107] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[107] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[108] = (unsigned char  *)p_dl_deal_struct_h->h_inter_med_person;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[108] = (unsigned long )36;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[108] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[108] = (         short *)&l_dl_deal_struct_i->i_inter_med_person;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[108] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[108] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[108] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[108] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[109] = (unsigned char  *)p_dl_deal_struct_h->h_inter_med_personnm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[109] = (unsigned long )66;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[109] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[109] = (         short *)&l_dl_deal_struct_i->i_inter_med_personnm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[109] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[109] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[109] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[109] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[110] = (unsigned char  *)p_dl_deal_struct_h->h_fxccy;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[110] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[110] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[110] = (         short *)&l_dl_deal_struct_i->i_fxccy;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[110] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[110] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[110] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[110] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[111] = (unsigned char  *)p_dl_deal_struct_h->h_uniq_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[111] = (unsigned long )15;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[111] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[111] = (         short *)&l_dl_deal_struct_i->i_uniq_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[111] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[111] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[111] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[111] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[112] = (unsigned char  *)&p_dl_deal_struct_h->h_cnt_548;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[112] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[112] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[112] = (         short *)&l_dl_deal_struct_i->i_cnt_548;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[112] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[112] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[112] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[112] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[113] = (unsigned char  *)p_dl_deal_struct_h->h_exp_setldate;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[113] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[113] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[113] = (         short *)&l_dl_deal_struct_i->i_exp_setldate;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[113] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[113] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[113] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[113] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[114] = (unsigned char  *)p_dl_deal_struct_h->h_related_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[114] = (unsigned long )21;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[114] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[114] = (         short *)&l_dl_deal_struct_i->i_related_ident_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[114] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[114] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[114] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[114] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[115] = (unsigned char  *)p_dl_deal_struct_h->h_informaton;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[115] = (unsigned long )201;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[115] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[115] = (         short *)&l_dl_deal_struct_i->i_informaton;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[115] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[115] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[115] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[115] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[116] = (unsigned char  *)p_dl_deal_struct_h->h_settlement_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[116] = (unsigned long )16;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[116] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[116] = (         short *)&l_dl_deal_struct_i->i_settlement_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[116] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[116] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[116] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[116] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[117] = (unsigned char  *)p_dl_deal_struct_h->h_mkt_type;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[117] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[117] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[117] = (         short *)&l_dl_deal_struct_i->i_mkt_type;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[117] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[117] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[117] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[117] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[118] = (unsigned char  *)p_dl_deal_struct_h->h_clh_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[118] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[118] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[118] = (         short *)&l_dl_deal_struct_i->i_clh_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[118] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[118] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[118] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[118] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[119] = (unsigned char  *)&p_dl_deal_struct_h->h_interest;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[119] = (unsigned long )sizeof(int);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[119] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[119] = (         short *)&l_dl_deal_struct_i->i_interest;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[119] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[119] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[119] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[119] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[120] = (unsigned char  *)&p_dl_deal_struct_h->h_net_amt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[120] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[120] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[120] = (         short *)&l_dl_deal_struct_i->i_net_amt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[120] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[120] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[120] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[120] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[121] = (unsigned char  *)p_dl_deal_struct_h->h_payin_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[121] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[121] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[121] = (         short *)&l_dl_deal_struct_i->i_payin_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[121] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[121] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[121] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[121] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[122] = (unsigned char  *)p_dl_deal_struct_h->h_payout_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[122] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[122] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[122] = (         short *)&l_dl_deal_struct_i->i_payout_dt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[122] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[122] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[122] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[122] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[123] = (unsigned char  *)&p_dl_deal_struct_h->h_demat_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[123] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[123] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[123] = (         short *)&l_dl_deal_struct_i->i_demat_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[123] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[123] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[123] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[123] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[124] = (unsigned char  *)p_dl_deal_struct_h->h_contract_req;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[124] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[124] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[124] = (         short *)&l_dl_deal_struct_i->i_contract_req;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[124] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[124] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[124] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[124] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[125] = (unsigned char  *)p_dl_deal_struct_h->h_excum_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[125] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[125] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[125] = (         short *)&l_dl_deal_struct_i->i_excum_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[125] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[125] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[125] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[125] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[126] = (unsigned char  *)p_dl_deal_struct_h->h_crn_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[126] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[126] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[126] = (         short *)&l_dl_deal_struct_i->i_crn_no;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[126] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[126] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[126] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[126] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[127] = (unsigned char  *)p_dl_deal_struct_h->h_interfii_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[127] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[127] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[127] = (         short *)&l_dl_deal_struct_i->i_interfii_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[127] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[127] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[127] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[127] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[128] = (unsigned char  *)p_dl_deal_struct_h->h_pay_mode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[128] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[128] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[128] = (         short *)&l_dl_deal_struct_i->i_pay_mode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[128] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[128] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[128] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[128] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[129] = (unsigned char  *)p_dl_deal_struct_h->h_dl_secstatus;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[129] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[129] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[129] = (         short *)&l_dl_deal_struct_i->i_dl_secstatus;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[129] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[129] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[129] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[129] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[130] = (unsigned char  *)p_dl_deal_struct_h->h_dl_mnystatus;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[130] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[130] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[130] = (         short *)&l_dl_deal_struct_i->i_dl_mnystatus;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[130] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[130] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[130] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[130] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[131] = (unsigned char  *)&p_dl_deal_struct_h->h_avail_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[131] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[131] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[131] = (         short *)&l_dl_deal_struct_i->i_avail_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[131] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[131] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[131] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[131] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[132] = (unsigned char  *)&p_dl_deal_struct_h->h_allot_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[132] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[132] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[132] = (         short *)&l_dl_deal_struct_i->i_allot_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[132] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[132] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[132] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[132] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[133] = (unsigned char  *)&p_dl_deal_struct_h->h_shortage_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[133] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[133] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[133] = (         short *)&l_dl_deal_struct_i->i_shortage_qty;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[133] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[133] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[133] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[133] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[134] = (unsigned char  *)p_dl_deal_struct_h->h_cln_depoacc;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[134] = (unsigned long )11;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[134] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[134] = (         short *)&l_dl_deal_struct_i->i_cln_depoacc;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[134] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[134] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[134] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[134] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[135] = (unsigned char  *)p_dl_deal_struct_h->h_pltopl_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[135] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[135] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[135] = (         short *)&l_dl_deal_struct_i->i_pltopl_flg;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[135] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[135] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[135] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[135] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[136] = (unsigned char  *)p_dl_deal_struct_h->h_orig_status;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[136] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[136] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[136] = (         short *)&l_dl_deal_struct_i->i_orig_status;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[136] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[136] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[136] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[136] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[137] = (unsigned char  *)p_dl_deal_struct_h->h_map_failcode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[137] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[137] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[137] = (         short *)&l_dl_deal_struct_i->i_map_failcode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[137] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[137] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[137] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[137] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[138] = (unsigned char  *)p_dl_deal_struct_h->h_match_failcode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[138] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[138] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[138] = (         short *)&l_dl_deal_struct_i->i_match_failcode;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[138] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[138] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[138] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[138] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[139] = (unsigned char  *)p_dl_deal_struct_h->h_is_matched;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[139] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[139] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[139] = (         short *)&l_dl_deal_struct_i->i_is_matched;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[139] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[139] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[139] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[139] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[140] = (unsigned char  *)p_dl_deal_struct_h->h_exch_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[140] = (unsigned long )4;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[140] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[140] = (         short *)&l_dl_deal_struct_i->i_exch_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[140] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[140] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[140] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[140] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[141] = (unsigned char  *)p_dl_deal_struct_h->h_contract_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[141] = (unsigned long )17;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[141] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[141] = (         short *)&l_dl_deal_struct_i->i_contract_cd;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[141] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[141] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[141] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[141] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[142] = (unsigned char  *)p_dl_deal_struct_h->h_r_delay;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[142] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[142] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[142] = (         short *)&l_dl_deal_struct_i->i_r_delay;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[142] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[142] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[142] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[142] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[143] = (unsigned char  *)p_dl_deal_struct_h->h_sebi_reported;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[143] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[143] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[143] = (         short *)&l_dl_deal_struct_i->i_sebi_reported;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[143] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[143] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[143] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[143] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[144] = (unsigned char  *)p_dl_deal_struct_h->h_r_sett_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[144] = (unsigned long )2;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[144] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[144] = (         short *)&l_dl_deal_struct_i->i_r_sett_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[144] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[144] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[144] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[144] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[145] = (unsigned char  *)p_dl_deal_struct_h->h_r_trans_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[145] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[145] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[145] = (         short *)&l_dl_deal_struct_i->i_r_trans_code;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[145] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[145] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[145] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[145] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[146] = (unsigned char  *)p_dl_deal_struct_h->h_r_type;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[146] = (unsigned long )3;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[146] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[146] = (         short *)&l_dl_deal_struct_i->i_r_type;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[146] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[146] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[146] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[146] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[147] = (unsigned char  *)p_dl_deal_struct_h->h_repo_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[147] = (unsigned long )20;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[147] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[147] = (         short *)&l_dl_deal_struct_i->i_repo_date;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[147] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[147] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[147] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[147] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[148] = (unsigned char  *)&p_dl_deal_struct_h->h_comm_amt;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[148] = (unsigned long )sizeof(double);
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[148] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[148] = (         short *)0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[148] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[148] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[148] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[148] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstv[149] = (unsigned char  *)p_dl_deal_struct_h->h_mf_seqno;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhstl[149] = (unsigned long )6;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqhsts[149] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqindv[149] = (         short *)0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqinds[149] = (         int  )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqharm[149] = (unsigned long )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqadto[149] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqtdso[149] = (unsigned short )0;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqphsv = sqlstm.sqhstv;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqphsl = sqlstm.sqhstl;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqphss = sqlstm.sqhsts;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqpind = sqlstm.sqindv;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqpins = sqlstm.sqinds;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqparm = sqlstm.sqharm;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqparc = sqlstm.sqharc;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqpadto = sqlstm.sqadto;
#line 2951 "DM_DbInterface.pc"
sqlstm.sqptdso = sqlstm.sqtdso;
#line 2951 "DM_DbInterface.pc"
sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 2951 "DM_DbInterface.pc"
}

#line 2951 "DM_DbInterface.pc"



printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENT",p_dl_deal_struct_h -> h_client,l_dl_deal_struct_i -> i_client,strlen(p_dl_deal_struct_h -> h_client),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","IDENTIY_NO",p_dl_deal_struct_h -> h_identiy_no,l_dl_deal_struct_i -> i_identiy_no,strlen(p_dl_deal_struct_h -> h_identiy_no),16);
printf("Col |%s| Value |%s| Value Ind|%d|\n","DEAL_DATE",p_dl_deal_struct_h -> h_deal_date,l_dl_deal_struct_i -> i_deal_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","SETL_DATE",p_dl_deal_struct_h -> h_setl_date,l_dl_deal_struct_i -> i_setl_date);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","COST",p_dl_deal_struct_h -> h_cost,l_dl_deal_struct_i -> i_cost);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EX_ARENA",p_dl_deal_struct_h -> h_ex_arena,l_dl_deal_struct_i -> i_ex_arena,strlen(p_dl_deal_struct_h -> h_ex_arena),2);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","AMOUNT",p_dl_deal_struct_h -> h_amount,l_dl_deal_struct_i -> i_amount);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","CUSTODYCOMM",p_dl_deal_struct_h -> h_custodycomm,l_dl_deal_struct_i -> i_custodycomm);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","BROKERCOMM",p_dl_deal_struct_h -> h_brokercomm,l_dl_deal_struct_i -> i_brokercomm);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","STX_COMM",p_dl_deal_struct_h -> h_stx_comm,l_dl_deal_struct_i -> i_stx_comm);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","OTH_COMM",p_dl_deal_struct_h -> h_oth_comm,l_dl_deal_struct_i -> i_oth_comm);
printf("Col |%s| Value |%s| Value Ind|%d|\n","INSTRUMENT_DT",p_dl_deal_struct_h -> h_instrument_dt,l_dl_deal_struct_i -> i_instrument_dt);
printf("Col |%s| Value |%s| Value Ind|%d|\n","MONEY_SETL_DT",p_dl_deal_struct_h -> h_money_setl_dt,l_dl_deal_struct_i -> i_money_setl_dt);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","QTY",p_dl_deal_struct_h -> h_qty,l_dl_deal_struct_i -> i_qty);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DOMESTIC_CPCLT",p_dl_deal_struct_h -> h_domestic_cpclt,l_dl_deal_struct_i -> i_domestic_cpclt,strlen(p_dl_deal_struct_h -> h_domestic_cpclt),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SPOTTRD_IND",p_dl_deal_struct_h -> h_spottrd_ind,l_dl_deal_struct_i -> i_spottrd_ind,strlen(p_dl_deal_struct_h -> h_spottrd_ind),1);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","ORIG_QTY",p_dl_deal_struct_h -> h_orig_qty,l_dl_deal_struct_i -> i_orig_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","ORIG_AMOUNT",p_dl_deal_struct_h -> h_orig_amount,l_dl_deal_struct_i -> i_orig_amount);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEAL_FRM_ORD",p_dl_deal_struct_h -> h_deal_frm_ord,l_dl_deal_struct_i -> i_deal_frm_ord,strlen(p_dl_deal_struct_h -> h_deal_frm_ord),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ENTRY",p_dl_deal_struct_h -> h_entry,l_dl_deal_struct_i -> i_entry,strlen(p_dl_deal_struct_h -> h_entry),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REAPIRED_IND",p_dl_deal_struct_h -> h_reapired_ind,l_dl_deal_struct_i -> i_reapired_ind,strlen(p_dl_deal_struct_h -> h_reapired_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DOMCP_CUSTODYCLT",p_dl_deal_struct_h -> h_domcp_custodyclt,l_dl_deal_struct_i -> i_domcp_custodyclt,strlen(p_dl_deal_struct_h -> h_domcp_custodyclt),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CP_CLT",p_dl_deal_struct_h -> h_cp_clt,l_dl_deal_struct_i -> i_cp_clt,strlen(p_dl_deal_struct_h -> h_cp_clt),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CP_CLTNAME",p_dl_deal_struct_h -> h_cp_cltname,l_dl_deal_struct_i -> i_cp_cltname,strlen(p_dl_deal_struct_h -> h_cp_cltname),65);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENTOF",p_dl_deal_struct_h -> h_clientof,l_dl_deal_struct_i -> i_clientof,strlen(p_dl_deal_struct_h -> h_clientof),65);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENT_NOTE",p_dl_deal_struct_h -> h_client_note,l_dl_deal_struct_i -> i_client_note,strlen(p_dl_deal_struct_h -> h_client_note),70);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FX_REQD",p_dl_deal_struct_h -> h_fx_reqd,l_dl_deal_struct_i -> i_fx_reqd,strlen(p_dl_deal_struct_h -> h_fx_reqd),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PAYLOC_IND",p_dl_deal_struct_h -> h_payloc_ind,l_dl_deal_struct_i -> i_payloc_ind,strlen(p_dl_deal_struct_h -> h_payloc_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","VERFIED_WITH",p_dl_deal_struct_h -> h_verfied_with,l_dl_deal_struct_i -> i_verfied_with,strlen(p_dl_deal_struct_h -> h_verfied_with),25);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","AMT_DIFFER",p_dl_deal_struct_h -> h_amt_differ,l_dl_deal_struct_i -> i_amt_differ);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BRK_NO",p_dl_deal_struct_h -> h_brk_no,l_dl_deal_struct_i -> i_brk_no,strlen(p_dl_deal_struct_h -> h_brk_no),12);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FAILREASON_CD",p_dl_deal_struct_h -> h_failreason_cd,l_dl_deal_struct_i -> i_failreason_cd,strlen(p_dl_deal_struct_h -> h_failreason_cd),2);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FAIL_DET",p_dl_deal_struct_h -> h_fail_det,l_dl_deal_struct_i -> i_fail_det,strlen(p_dl_deal_struct_h -> h_fail_det),35);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PARTIAL_IND_B",p_dl_deal_struct_h -> h_partial_ind_b,l_dl_deal_struct_i -> i_partial_ind_b,strlen(p_dl_deal_struct_h -> h_partial_ind_b),1);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","FX_RT",p_dl_deal_struct_h -> h_fx_rt,l_dl_deal_struct_i -> i_fx_rt);
printf("Col |%s| Value |%d| Value Ind|%d|\n","AMEND_COUNT",p_dl_deal_struct_h -> h_amend_count,l_dl_deal_struct_i -> i_amend_count);
printf("Col |%s| Value |%d| Value Ind|%d|\n","NUMBER_A",p_dl_deal_struct_h -> h_number_a,l_dl_deal_struct_i -> i_number_a);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REPORT_AT_EOM_IND",p_dl_deal_struct_h -> h_report_at_eom_ind,l_dl_deal_struct_i -> i_report_at_eom_ind,strlen(p_dl_deal_struct_h -> h_report_at_eom_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEOFBILLING",p_dl_deal_struct_h -> h_dateofbilling,l_dl_deal_struct_i -> i_dateofbilling);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LCL_IDENTNO",p_dl_deal_struct_h -> h_lcl_identno,l_dl_deal_struct_i -> i_lcl_identno,strlen(p_dl_deal_struct_h -> h_lcl_identno),16);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTRUCT_PERSON",p_dl_deal_struct_h -> h_instruct_person,l_dl_deal_struct_i -> i_instruct_person,strlen(p_dl_deal_struct_h -> h_instruct_person),35);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","REC_INT_000",p_dl_deal_struct_h -> h_rec_int_000,l_dl_deal_struct_i -> i_rec_int_000);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEAL_CD",p_dl_deal_struct_h -> h_deal_cd,l_dl_deal_struct_i -> i_deal_cd,strlen(p_dl_deal_struct_h -> h_deal_cd),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_dl_deal_struct_h -> h_instr_code,l_dl_deal_struct_i -> i_instr_code,strlen(p_dl_deal_struct_h -> h_instr_code),8);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CURRENCY_CD",p_dl_deal_struct_h -> h_currency_cd,l_dl_deal_struct_i -> i_currency_cd,strlen(p_dl_deal_struct_h -> h_currency_cd),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DL_CLASS",p_dl_deal_struct_h -> h_dl_class,l_dl_deal_struct_i -> i_dl_class,strlen(p_dl_deal_struct_h -> h_dl_class),2);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ORIG_REFNO",p_dl_deal_struct_h -> h_orig_refno,l_dl_deal_struct_i -> i_orig_refno,strlen(p_dl_deal_struct_h -> h_orig_refno),16);
printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEOF_INPUT",p_dl_deal_struct_h -> h_dateof_input,l_dl_deal_struct_i -> i_dateof_input);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_dl_deal_struct_h -> h_maker,l_dl_deal_struct_i -> i_maker,strlen(p_dl_deal_struct_h -> h_maker),14);
printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_dl_deal_struct_h -> h_maker_dt,l_dl_deal_struct_i -> i_maker_dt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEAL_STAT",p_dl_deal_struct_h -> h_deal_stat,l_dl_deal_struct_i -> i_deal_stat,strlen(p_dl_deal_struct_h -> h_deal_stat),2);
printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_dl_deal_struct_h -> h_access_stamp,l_dl_deal_struct_i -> i_access_stamp);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INFO1",p_dl_deal_struct_h -> h_info1,l_dl_deal_struct_i -> i_info1,strlen(p_dl_deal_struct_h -> h_info1),260);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LOCATION_CD",p_dl_deal_struct_h -> h_location_cd,l_dl_deal_struct_i -> i_location_cd,strlen(p_dl_deal_struct_h -> h_location_cd),4);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REGINSTR_IND",p_dl_deal_struct_h -> h_reginstr_ind,l_dl_deal_struct_i -> i_reginstr_ind,strlen(p_dl_deal_struct_h -> h_reginstr_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS_POS",p_dl_deal_struct_h -> h_status_pos,l_dl_deal_struct_i -> i_status_pos,strlen(p_dl_deal_struct_h -> h_status_pos),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_dl_deal_struct_h -> h_status,l_dl_deal_struct_i -> i_status,strlen(p_dl_deal_struct_h -> h_status),1);
printf("Col |%s| Value |%s| Value Ind|%d|\n","VAL_FDT",p_dl_deal_struct_h -> h_val_fdt,l_dl_deal_struct_i -> i_val_fdt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COMPREFNO",p_dl_deal_struct_h -> h_comprefno,l_dl_deal_struct_i -> i_comprefno,strlen(p_dl_deal_struct_h -> h_comprefno),16);
printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEOF_MARKFAIL",p_dl_deal_struct_h -> h_dateof_markfail,l_dl_deal_struct_i -> i_dateof_markfail);
printf("Col |%s| Value |%s| Value Ind|%d|\n","ALLOW_DROPDT",p_dl_deal_struct_h -> h_allow_dropdt,l_dl_deal_struct_i -> i_allow_dropdt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_dl_deal_struct_h -> h_checker,l_dl_deal_struct_i -> i_checker,strlen(p_dl_deal_struct_h -> h_checker),14);
printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_dl_deal_struct_h -> h_checker_dt,l_dl_deal_struct_i -> i_checker_dt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTRCONV_IND",p_dl_deal_struct_h -> h_instrconv_ind,l_dl_deal_struct_i -> i_instrconv_ind,strlen(p_dl_deal_struct_h -> h_instrconv_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d|\n","NDS_BLK_DT",p_dl_deal_struct_h -> h_nds_blk_dt,l_dl_deal_struct_i -> i_nds_blk_dt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LR_DL_CLASS",p_dl_deal_struct_h -> h_lr_dl_class,l_dl_deal_struct_i -> i_lr_dl_class,strlen(p_dl_deal_struct_h -> h_lr_dl_class),2);
printf("Col |%s| Value |%s| Value Ind|%d|\n","NDS_DATE",p_dl_deal_struct_h -> h_nds_date,l_dl_deal_struct_i -> i_nds_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","UNBLK_DATE",p_dl_deal_struct_h -> h_unblk_date,l_dl_deal_struct_i -> i_unblk_date);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DELTA_000",p_dl_deal_struct_h -> h_delta_000,l_dl_deal_struct_i -> i_delta_000);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DELTA_001",p_dl_deal_struct_h -> h_delta_001,l_dl_deal_struct_i -> i_delta_001);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DELTA_003",p_dl_deal_struct_h -> h_delta_003,l_dl_deal_struct_i -> i_delta_003);
printf("Col |%s| Value |%s| Value Ind|%d|\n","DEL_REC_DATE",p_dl_deal_struct_h -> h_del_rec_date,l_dl_deal_struct_i -> i_del_rec_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LAST_REG_DATE",p_dl_deal_struct_h -> h_last_reg_date,l_dl_deal_struct_i -> i_last_reg_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_CHECK_DATE",p_dl_deal_struct_h -> h_lr_check_date,l_dl_deal_struct_i -> i_lr_check_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_VALDATE",p_dl_deal_struct_h -> h_lr_valdate,l_dl_deal_struct_i -> i_lr_valdate);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LRINSTR_DATE",p_dl_deal_struct_h -> h_lrinstr_date,l_dl_deal_struct_i -> i_lrinstr_date);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","REG_MSG_QTY",p_dl_deal_struct_h -> h_reg_msg_qty,l_dl_deal_struct_i -> i_reg_msg_qty);
printf("Col |%s| Value |%s| Value Ind|%d|\n","TMP_OUT_DT",p_dl_deal_struct_h -> h_tmp_out_dt,l_dl_deal_struct_i -> i_tmp_out_dt);
printf("Col |%s| Value |%s| Value Ind|%d|\n","TMP_OUT_DATE",p_dl_deal_struct_h -> h_tmp_out_date,l_dl_deal_struct_i -> i_tmp_out_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","TRANS_DATE",p_dl_deal_struct_h -> h_trans_date,l_dl_deal_struct_i -> i_trans_date);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","TOT_QTY",p_dl_deal_struct_h -> h_tot_qty,l_dl_deal_struct_i -> i_tot_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","QTY_LOST",p_dl_deal_struct_h -> h_qty_lost,l_dl_deal_struct_i -> i_qty_lost);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","MRK_DL_FAILQTY",p_dl_deal_struct_h -> h_mrk_dl_failqty,l_dl_deal_struct_i -> i_mrk_dl_failqty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DL_COMPLETEQTY",p_dl_deal_struct_h -> h_dl_completeqty,l_dl_deal_struct_i -> i_dl_completeqty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","OUT_REG_QTY",p_dl_deal_struct_h -> h_out_reg_qty,l_dl_deal_struct_i -> i_out_reg_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","PEND_REG_QTY",p_dl_deal_struct_h -> h_pend_reg_qty,l_dl_deal_struct_i -> i_pend_reg_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","RET_REG_QTY",p_dl_deal_struct_h -> h_ret_reg_qty,l_dl_deal_struct_i -> i_ret_reg_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","STAMP_QTY",p_dl_deal_struct_h -> h_stamp_qty,l_dl_deal_struct_i -> i_stamp_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","TEMP_OUT_QUANTITY",p_dl_deal_struct_h -> h_temp_out_quantity,l_dl_deal_struct_i -> i_temp_out_quantity);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","TEMP_RET_QUANTITY",p_dl_deal_struct_h -> h_temp_ret_quantity,l_dl_deal_struct_i -> i_temp_ret_quantity);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","VAL_DEED_QTY",p_dl_deal_struct_h -> h_val_deed_qty,l_dl_deal_struct_i -> i_val_deed_qty);
printf("Col |%s| Value |%s| Value Ind|%d|\n","HOST_DATE",p_dl_deal_struct_h -> h_host_date,l_dl_deal_struct_i -> i_host_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LRNDS_BILLDT",p_dl_deal_struct_h -> h_lrnds_billdt,l_dl_deal_struct_i -> i_lrnds_billdt);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LRNDS_DATE",p_dl_deal_struct_h -> h_lrnds_date,l_dl_deal_struct_i -> i_lrnds_date);
printf("Col |%s| Value |%s| Value Ind|%d|\n","LR_UNBLK_DATE",p_dl_deal_struct_h -> h_lr_unblk_date,l_dl_deal_struct_i -> i_lr_unblk_date);
printf("Col |%s| Value |%d| Value Ind|%d|\n","NUMBER_B",p_dl_deal_struct_h -> h_number_b,l_dl_deal_struct_i -> i_number_b);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLT_REQDEL_IND",p_dl_deal_struct_h -> h_clt_reqdel_ind,l_dl_deal_struct_i -> i_clt_reqdel_ind,strlen(p_dl_deal_struct_h -> h_clt_reqdel_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MOD_HISPOS_IND",p_dl_deal_struct_h -> h_mod_hispos_ind,l_dl_deal_struct_i -> i_mod_hispos_ind,strlen(p_dl_deal_struct_h -> h_mod_hispos_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d|\n","MOD_HISPOS_DATE",p_dl_deal_struct_h -> h_mod_hispos_date,l_dl_deal_struct_i -> i_mod_hispos_date);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","GL_CLIENT",p_dl_deal_struct_h -> h_gl_client,l_dl_deal_struct_i -> i_gl_client,strlen(p_dl_deal_struct_h -> h_gl_client),10);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","CP_AMT",p_dl_deal_struct_h -> h_cp_amt,l_dl_deal_struct_i -> i_cp_amt);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MSG_STAT",p_dl_deal_struct_h -> h_msg_stat,l_dl_deal_struct_i -> i_msg_stat,strlen(p_dl_deal_struct_h -> h_msg_stat),50);
printf("Col |%s| Value |%d| Value Ind|%d|\n","SUB_FAIL_CD",p_dl_deal_struct_h -> h_sub_fail_cd,l_dl_deal_struct_i -> i_sub_fail_cd);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PARTIAL_IND_A",p_dl_deal_struct_h -> h_partial_ind_a,l_dl_deal_struct_i -> i_partial_ind_a,strlen(p_dl_deal_struct_h -> h_partial_ind_a),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LOC_CHNG_IND",p_dl_deal_struct_h -> h_loc_chng_ind,l_dl_deal_struct_i -> i_loc_chng_ind,strlen(p_dl_deal_struct_h -> h_loc_chng_ind),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COMM_IDENT_NO",p_dl_deal_struct_h -> h_comm_ident_no,l_dl_deal_struct_i -> i_comm_ident_no,strlen(p_dl_deal_struct_h -> h_comm_ident_no),16);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTRUCT_PERSONNM",p_dl_deal_struct_h -> h_instruct_personnm,l_dl_deal_struct_i -> i_instruct_personnm,strlen(p_dl_deal_struct_h -> h_instruct_personnm),65);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENTOF_CD",p_dl_deal_struct_h -> h_clientof_cd,l_dl_deal_struct_i -> i_clientof_cd,strlen(p_dl_deal_struct_h -> h_clientof_cd),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INTER_MED_PERSON",p_dl_deal_struct_h -> h_inter_med_person,l_dl_deal_struct_i -> i_inter_med_person,strlen(p_dl_deal_struct_h -> h_inter_med_person),35);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INTER_MED_PERSONNM",p_dl_deal_struct_h -> h_inter_med_personnm,l_dl_deal_struct_i -> i_inter_med_personnm,strlen(p_dl_deal_struct_h -> h_inter_med_personnm),65);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","FXCCY",p_dl_deal_struct_h -> h_fxccy,l_dl_deal_struct_i -> i_fxccy,strlen(p_dl_deal_struct_h -> h_fxccy),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","UNIQ_IDENT_NO",p_dl_deal_struct_h -> h_uniq_ident_no,l_dl_deal_struct_i -> i_uniq_ident_no,strlen(p_dl_deal_struct_h -> h_uniq_ident_no),14);
printf("Col |%s| Value |%d| Value Ind|%d|\n","CNT_548",p_dl_deal_struct_h -> h_cnt_548,l_dl_deal_struct_i -> i_cnt_548);
printf("Col |%s| Value |%s| Value Ind|%d|\n","EXP_SETLDATE",p_dl_deal_struct_h -> h_exp_setldate,l_dl_deal_struct_i -> i_exp_setldate);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RELATED_IDENT_NO",p_dl_deal_struct_h -> h_related_ident_no,l_dl_deal_struct_i -> i_related_ident_no,strlen(p_dl_deal_struct_h -> h_related_ident_no),20);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INFORMATON",p_dl_deal_struct_h -> h_informaton,l_dl_deal_struct_i -> i_informaton,strlen(p_dl_deal_struct_h -> h_informaton),200);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SETTLEMENT_NO",p_dl_deal_struct_h -> h_settlement_no,l_dl_deal_struct_i -> i_settlement_no,strlen(p_dl_deal_struct_h -> h_settlement_no),15);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MKT_TYPE",p_dl_deal_struct_h -> h_mkt_type,l_dl_deal_struct_i -> i_mkt_type,strlen(p_dl_deal_struct_h -> h_mkt_type),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLH_FLG",p_dl_deal_struct_h -> h_clh_flg,l_dl_deal_struct_i -> i_clh_flg,strlen(p_dl_deal_struct_h -> h_clh_flg),1);
printf("Col |%s| Value |%d| Value Ind|%d|\n","INTEREST",p_dl_deal_struct_h -> h_interest,l_dl_deal_struct_i -> i_interest);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","NET_AMT",p_dl_deal_struct_h -> h_net_amt,l_dl_deal_struct_i -> i_net_amt);
printf("Col |%s| Value |%s| Value Ind|%d|\n","PAYIN_DT",p_dl_deal_struct_h -> h_payin_dt,l_dl_deal_struct_i -> i_payin_dt);
printf("Col |%s| Value |%s| Value Ind|%d|\n","PAYOUT_DT",p_dl_deal_struct_h -> h_payout_dt,l_dl_deal_struct_i -> i_payout_dt);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DEMAT_QTY",p_dl_deal_struct_h -> h_demat_qty,l_dl_deal_struct_i -> i_demat_qty);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CONTRACT_REQ",p_dl_deal_struct_h -> h_contract_req,l_dl_deal_struct_i -> i_contract_req,strlen(p_dl_deal_struct_h -> h_contract_req),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCUM_FLG",p_dl_deal_struct_h -> h_excum_flg,l_dl_deal_struct_i -> i_excum_flg,strlen(p_dl_deal_struct_h -> h_excum_flg),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CRN_NO",p_dl_deal_struct_h -> h_crn_no,l_dl_deal_struct_i -> i_crn_no,strlen(p_dl_deal_struct_h -> h_crn_no),16);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INTERFII_FLG",p_dl_deal_struct_h -> h_interfii_flg,l_dl_deal_struct_i -> i_interfii_flg,strlen(p_dl_deal_struct_h -> h_interfii_flg),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PAY_MODE",p_dl_deal_struct_h -> h_pay_mode,l_dl_deal_struct_i -> i_pay_mode,strlen(p_dl_deal_struct_h -> h_pay_mode),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DL_SECSTATUS",p_dl_deal_struct_h -> h_dl_secstatus,l_dl_deal_struct_i -> i_dl_secstatus,strlen(p_dl_deal_struct_h -> h_dl_secstatus),2);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DL_MNYSTATUS",p_dl_deal_struct_h -> h_dl_mnystatus,l_dl_deal_struct_i -> i_dl_mnystatus,strlen(p_dl_deal_struct_h -> h_dl_mnystatus),2);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","AVAIL_QTY",p_dl_deal_struct_h -> h_avail_qty,l_dl_deal_struct_i -> i_avail_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","ALLOT_QTY",p_dl_deal_struct_h -> h_allot_qty,l_dl_deal_struct_i -> i_allot_qty);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","SHORTAGE_QTY",p_dl_deal_struct_h -> h_shortage_qty,l_dl_deal_struct_i -> i_shortage_qty);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_DEPOACC",p_dl_deal_struct_h -> h_cln_depoacc,l_dl_deal_struct_i -> i_cln_depoacc,strlen(p_dl_deal_struct_h -> h_cln_depoacc),10);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PLTOPL_FLG",p_dl_deal_struct_h -> h_pltopl_flg,l_dl_deal_struct_i -> i_pltopl_flg,strlen(p_dl_deal_struct_h -> h_pltopl_flg),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ORIG_STATUS",p_dl_deal_struct_h -> h_orig_status,l_dl_deal_struct_i -> i_orig_status,strlen(p_dl_deal_struct_h -> h_orig_status),2);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAP_FAILCODE",p_dl_deal_struct_h -> h_map_failcode,l_dl_deal_struct_i -> i_map_failcode,strlen(p_dl_deal_struct_h -> h_map_failcode),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MATCH_FAILCODE",p_dl_deal_struct_h -> h_match_failcode,l_dl_deal_struct_i -> i_match_failcode,strlen(p_dl_deal_struct_h -> h_match_failcode),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","IS_MATCHED",p_dl_deal_struct_h -> h_is_matched,l_dl_deal_struct_i -> i_is_matched,strlen(p_dl_deal_struct_h -> h_is_matched),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_dl_deal_struct_h -> h_exch_code,l_dl_deal_struct_i -> i_exch_code,strlen(p_dl_deal_struct_h -> h_exch_code),3);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CONTRACT_CD",p_dl_deal_struct_h -> h_contract_cd,l_dl_deal_struct_i -> i_contract_cd,strlen(p_dl_deal_struct_h -> h_contract_cd),16);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","R_DELAY",p_dl_deal_struct_h -> h_r_delay,l_dl_deal_struct_i -> i_r_delay,strlen(p_dl_deal_struct_h -> h_r_delay),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SEBI_REPORTED",p_dl_deal_struct_h -> h_sebi_reported,l_dl_deal_struct_i -> i_sebi_reported,strlen(p_dl_deal_struct_h -> h_sebi_reported),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","R_SETT_CODE",p_dl_deal_struct_h -> h_r_sett_code,l_dl_deal_struct_i -> i_r_sett_code,strlen(p_dl_deal_struct_h -> h_r_sett_code),1);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","R_TRANS_CODE",p_dl_deal_struct_h -> h_r_trans_code,l_dl_deal_struct_i -> i_r_trans_code,strlen(p_dl_deal_struct_h -> h_r_trans_code),2);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","R_TYPE",p_dl_deal_struct_h -> h_r_type,l_dl_deal_struct_i -> i_r_type,strlen(p_dl_deal_struct_h -> h_r_type),2);
printf("Col |%s| Value |%s| Value Ind|%d|\n","REPO_DATE",p_dl_deal_struct_h -> h_repo_date,l_dl_deal_struct_i -> i_repo_date);

IS_ANY_ORA_ERROR

RETURN_SUCCESS:

APL_FREE(l_dl_deal_struct_i);

APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

APL_FREE(l_dl_deal_struct_i);

APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}


int MT_UpdDL_SAFEK(DL_SAFEK_STRUCT_H *p_dl_safek_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr)	{

struct sqlca sqlca;

DL_SAFEK_STRUCT_I *l_dl_safek_struct_i = (DL_SAFEK_STRUCT_I *)NULL;

l_dl_safek_struct_i = (DL_SAFEK_STRUCT_I *)calloc(1,sizeof(DL_SAFEK_STRUCT_I));



	if(!strlen(p_dl_safek_struct_h ->h_instr_code))
l_dl_safek_struct_i -> i_instr_code= -1;
	if(!strlen(p_dl_safek_struct_h ->h_location_cd))
l_dl_safek_struct_i -> i_location_cd= -1;
	if(!strlen(p_dl_safek_struct_h ->h_client))
l_dl_safek_struct_i -> i_client= -1;
	if(!strlen(p_dl_safek_struct_h ->h_access_stamp))
l_dl_safek_struct_i -> i_access_stamp= -1;
	if(!strlen(p_dl_safek_struct_h ->h_status))
l_dl_safek_struct_i -> i_status= -1;
	
	
	
	
	
	
	
	
	if(!strlen(p_dl_safek_struct_h ->h_block_type))
l_dl_safek_struct_i -> i_block_type= -1;


/* EXEC SQL INSERT INTO DL_SAFEK VALUES(:p_dl_safek_struct_h:l_dl_safek_struct_i); */ 
#line 3152 "DM_DbInterface.pc"

{
#line 3152 "DM_DbInterface.pc"
struct sqlexd sqlstm;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqlvsn = 12;
#line 3152 "DM_DbInterface.pc"
sqlstm.arrsiz = 150;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqladtp = &sqladt;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqltdsp = &sqltds;
#line 3152 "DM_DbInterface.pc"
sqlstm.stmt = "insert into DL_SAFEK  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 \
,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s24\
 ,:s25:s26 ,:s27:s28 )";
#line 3152 "DM_DbInterface.pc"
sqlstm.iters = (unsigned int  )1;
#line 3152 "DM_DbInterface.pc"
sqlstm.offset = (unsigned int  )3524;
#line 3152 "DM_DbInterface.pc"
sqlstm.cud = sqlcud0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqlety = (unsigned short)256;
#line 3152 "DM_DbInterface.pc"
sqlstm.occurs = (unsigned int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[0] = (unsigned char  *)p_dl_safek_struct_h->h_instr_code;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[0] = (unsigned long )9;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[0] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[0] = (         short *)&l_dl_safek_struct_i->i_instr_code;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[0] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[0] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[0] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[0] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[1] = (unsigned char  *)p_dl_safek_struct_h->h_location_cd;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[1] = (unsigned long )5;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[1] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[1] = (         short *)&l_dl_safek_struct_i->i_location_cd;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[1] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[1] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[1] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[1] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[2] = (unsigned char  *)p_dl_safek_struct_h->h_client;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[2] = (unsigned long )11;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[2] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[2] = (         short *)&l_dl_safek_struct_i->i_client;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[2] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[2] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[2] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[2] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[3] = (unsigned char  *)p_dl_safek_struct_h->h_access_stamp;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[3] = (unsigned long )20;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[3] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[3] = (         short *)&l_dl_safek_struct_i->i_access_stamp;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[3] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[3] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[3] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[3] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[4] = (unsigned char  *)p_dl_safek_struct_h->h_status;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[4] = (unsigned long )4;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[4] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[4] = (         short *)&l_dl_safek_struct_i->i_status;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[4] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[4] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[4] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[4] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[5] = (unsigned char  *)&p_dl_safek_struct_h->h_start_safek;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[5] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[5] = (         short *)&l_dl_safek_struct_i->i_start_safek;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[5] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[5] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[5] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[5] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[6] = (unsigned char  *)&p_dl_safek_struct_h->h_safekeep_pos;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[6] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[6] = (         short *)&l_dl_safek_struct_i->i_safekeep_pos;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[6] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[6] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[6] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[6] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[7] = (unsigned char  *)&p_dl_safek_struct_h->h_nvalreceive;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[7] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[7] = (         short *)&l_dl_safek_struct_i->i_nvalreceive;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[7] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[7] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[7] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[7] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[8] = (unsigned char  *)&p_dl_safek_struct_h->h_nvaldeliver;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[8] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[8] = (         short *)&l_dl_safek_struct_i->i_nvaldeliver;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[8] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[8] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[8] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[8] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[9] = (unsigned char  *)&p_dl_safek_struct_h->h_val_rec;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[9] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[9] = (         short *)&l_dl_safek_struct_i->i_val_rec;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[9] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[9] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[9] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[9] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[10] = (unsigned char  *)&p_dl_safek_struct_h->h_val_del;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[10] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[10] = (         short *)&l_dl_safek_struct_i->i_val_del;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[10] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[10] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[10] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[10] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[11] = (unsigned char  *)&p_dl_safek_struct_h->h_dp_rec;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[11] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[11] = (         short *)&l_dl_safek_struct_i->i_dp_rec;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[11] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[11] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[11] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[11] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[12] = (unsigned char  *)&p_dl_safek_struct_h->h_dp_del;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[12] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[12] = (         short *)&l_dl_safek_struct_i->i_dp_del;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[12] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[12] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[12] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[12] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstv[13] = (unsigned char  *)p_dl_safek_struct_h->h_block_type;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhstl[13] = (unsigned long )5;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqhsts[13] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqindv[13] = (         short *)&l_dl_safek_struct_i->i_block_type;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqinds[13] = (         int  )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqharm[13] = (unsigned long )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqadto[13] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqtdso[13] = (unsigned short )0;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqphsv = sqlstm.sqhstv;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqphsl = sqlstm.sqhstl;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqphss = sqlstm.sqhsts;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqpind = sqlstm.sqindv;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqpins = sqlstm.sqinds;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqparm = sqlstm.sqharm;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqparc = sqlstm.sqharc;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqpadto = sqlstm.sqadto;
#line 3152 "DM_DbInterface.pc"
sqlstm.sqptdso = sqlstm.sqtdso;
#line 3152 "DM_DbInterface.pc"
sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 3152 "DM_DbInterface.pc"
}

#line 3152 "DM_DbInterface.pc"




printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_dl_safek_struct_h -> h_instr_code,l_dl_safek_struct_i -> i_instr_code,strlen(p_dl_safek_struct_h -> h_instr_code),8);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LOCATION_CD",p_dl_safek_struct_h -> h_location_cd,l_dl_safek_struct_i -> i_location_cd,strlen(p_dl_safek_struct_h -> h_location_cd),4);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLIENT",p_dl_safek_struct_h -> h_client,l_dl_safek_struct_i -> i_client,strlen(p_dl_safek_struct_h -> h_client),10);
printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_dl_safek_struct_h -> h_access_stamp,l_dl_safek_struct_i -> i_access_stamp);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_dl_safek_struct_h -> h_status,l_dl_safek_struct_i -> i_status,strlen(p_dl_safek_struct_h -> h_status),3);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","START_SAFEK",p_dl_safek_struct_h -> h_start_safek,l_dl_safek_struct_i -> i_start_safek);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","SAFEKEEP_POS",p_dl_safek_struct_h -> h_safekeep_pos,l_dl_safek_struct_i -> i_safekeep_pos);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","NVALRECEIVE",p_dl_safek_struct_h -> h_nvalreceive,l_dl_safek_struct_i -> i_nvalreceive);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","NVALDELIVER",p_dl_safek_struct_h -> h_nvaldeliver,l_dl_safek_struct_i -> i_nvaldeliver);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","VAL_REC",p_dl_safek_struct_h -> h_val_rec,l_dl_safek_struct_i -> i_val_rec);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","VAL_DEL",p_dl_safek_struct_h -> h_val_del,l_dl_safek_struct_i -> i_val_del);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DP_REC",p_dl_safek_struct_h -> h_dp_rec,l_dl_safek_struct_i -> i_dp_rec);
printf("Col |%s| Value |%lf| Value Ind|%d|\n","DP_DEL",p_dl_safek_struct_h -> h_dp_del,l_dl_safek_struct_i -> i_dp_del);
printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BLOCK_TYPE",p_dl_safek_struct_h -> h_block_type,l_dl_safek_struct_i -> i_block_type,strlen(p_dl_safek_struct_h -> h_block_type),4);

IS_ANY_ORA_ERROR

RETURN_SUCCESS:

APL_FREE(l_dl_safek_struct_i);

APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

APL_FREE(l_dl_safek_struct_i);

APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}

int MT_UpdCAEVENT(CAEVENT_STRUCT_H *p_caevent_struct_h, DEBUG_INFO_STRUCT_H **l_debug_info_ptr) {

	struct sqlca sqlca;

	CAEVENT_STRUCT_I *l_caevent_struct_i = (CAEVENT_STRUCT_I *)NULL;

	l_caevent_struct_i = (CAEVENT_STRUCT_I *)calloc(1,sizeof(CAEVENT_STRUCT_I));



	if(!strlen(p_caevent_struct_h ->h_corp_id))
		l_caevent_struct_i -> i_corp_id= -1;
	if(!strlen(p_caevent_struct_h ->h_instr_code))
		l_caevent_struct_i -> i_instr_code= -1;
	if(!strlen(p_caevent_struct_h ->h_ca_event))
		l_caevent_struct_i -> i_ca_event= -1;
	if(!strlen(p_caevent_struct_h ->h_declare_dt))
		l_caevent_struct_i -> i_declare_dt= -1;


	if(!strlen(p_caevent_struct_h ->h_preliminary_flag))
		l_caevent_struct_i -> i_preliminary_flag= -1;
	if(!strlen(p_caevent_struct_h ->h_ca_currency))
		l_caevent_struct_i -> i_ca_currency= -1;
	if(!strlen(p_caevent_struct_h ->h_ex_date))
		l_caevent_struct_i -> i_ex_date= -1;
	if(!strlen(p_caevent_struct_h ->h_rec_date))
		l_caevent_struct_i -> i_rec_date= -1;
	if(!strlen(p_caevent_struct_h ->h_dateof_payment))
		l_caevent_struct_i -> i_dateof_payment= -1;
	if(!strlen(p_caevent_struct_h ->h_response_date))
		l_caevent_struct_i -> i_response_date= -1;
	if(!strlen(p_caevent_struct_h ->h_expiry_date))
		l_caevent_struct_i -> i_expiry_date= -1;
	if(!strlen(p_caevent_struct_h ->h_part_pymt_dt))
		l_caevent_struct_i -> i_part_pymt_dt= -1;
	if(!strlen(p_caevent_struct_h ->h_proxy_date))
		l_caevent_struct_i -> i_proxy_date= -1;
	if(!strlen(p_caevent_struct_h ->h_meeting_date))
		l_caevent_struct_i -> i_meeting_date= -1;
	if(!strlen(p_caevent_struct_h ->h_start_date))
		l_caevent_struct_i -> i_start_date= -1;
	if(!strlen(p_caevent_struct_h ->h_effective_date))
		l_caevent_struct_i -> i_effective_date= -1;
	if(!strlen(p_caevent_struct_h ->h_proc_oth))
		l_caevent_struct_i -> i_proc_oth= -1;
	if(!strlen(p_caevent_struct_h ->h_op_evt_class))
		l_caevent_struct_i -> i_op_evt_class= -1;
	if(!strlen(p_caevent_struct_h ->h_resp_dt_opnd))
		l_caevent_struct_i -> i_resp_dt_opnd= -1;
	if(!strlen(p_caevent_struct_h ->h_exp_dt_open_ind))
		l_caevent_struct_i -> i_exp_dt_open_ind= -1;
	if(!strlen(p_caevent_struct_h ->h_evt_send_msg_ind))
		l_caevent_struct_i -> i_evt_send_msg_ind= -1;
	if(!strlen(p_caevent_struct_h ->h_entl_send_msg_ind))
		l_caevent_struct_i -> i_entl_send_msg_ind= -1;
	if(!strlen(p_caevent_struct_h ->h_pymt_send_msg_ind))
		l_caevent_struct_i -> i_pymt_send_msg_ind= -1;


	if(!strlen(p_caevent_struct_h ->h_res_instr_code))
		l_caevent_struct_i -> i_res_instr_code= -1;


	if(!strlen(p_caevent_struct_h ->h_disp_of_fract))
		l_caevent_struct_i -> i_disp_of_fract= -1;




	if(!strlen(p_caevent_struct_h ->h_rhts_class))
		l_caevent_struct_i -> i_rhts_class= -1;

	if(!strlen(p_caevent_struct_h ->h_contact_details))
		l_caevent_struct_i -> i_contact_details= -1;









	if(!strlen(p_caevent_struct_h ->h_nrep_date_a))
		l_caevent_struct_i -> i_nrep_date_a= -1;
	if(!strlen(p_caevent_struct_h ->h_msg_followdays1))
		l_caevent_struct_i -> i_msg_followdays1= -1;
	if(!strlen(p_caevent_struct_h ->h_msg_followdays2))
		l_caevent_struct_i -> i_msg_followdays2= -1;
	if(!strlen(p_caevent_struct_h ->h_info_seq))
		l_caevent_struct_i -> i_info_seq= -1;
	if(!strlen(p_caevent_struct_h ->h_entitl_infono))
		l_caevent_struct_i -> i_entitl_infono= -1;
	if(!strlen(p_caevent_struct_h ->h_status))
		l_caevent_struct_i -> i_status= -1;
	if(!strlen(p_caevent_struct_h ->h_processed_date))
		l_caevent_struct_i -> i_processed_date= -1;
	if(!strlen(p_caevent_struct_h ->h_maker))
		l_caevent_struct_i -> i_maker= -1;
	if(!strlen(p_caevent_struct_h ->h_maker_dt))
		l_caevent_struct_i -> i_maker_dt= -1;
	if(!strlen(p_caevent_struct_h ->h_checker))
		l_caevent_struct_i -> i_checker= -1;
	if(!strlen(p_caevent_struct_h ->h_checker_dt))
		l_caevent_struct_i -> i_checker_dt= -1;
	if(!strlen(p_caevent_struct_h ->h_access_stamp))
		l_caevent_struct_i -> i_access_stamp= -1;
	if(!strlen(p_caevent_struct_h ->h_deal_frm_date))
		l_caevent_struct_i -> i_deal_frm_date= -1;
	if(!strlen(p_caevent_struct_h ->h_deal_to_date))
		l_caevent_struct_i -> i_deal_to_date= -1;
	if(!strlen(p_caevent_struct_h ->h_subscr_date))
		l_caevent_struct_i -> i_subscr_date= -1;
	if(!strlen(p_caevent_struct_h ->h_post_date))
		l_caevent_struct_i -> i_post_date= -1;
	if(!strlen(p_caevent_struct_h ->h_over_subscrp))
		l_caevent_struct_i -> i_over_subscrp= -1;
	if(!strlen(p_caevent_struct_h ->h_dividend_type))
		l_caevent_struct_i -> i_dividend_type= -1;

	if(!strlen(p_caevent_struct_h ->h_nser_e_info))
		l_caevent_struct_i -> i_nser_e_info= -1;
	if(!strlen(p_caevent_struct_h ->h_nser_b_info))
		l_caevent_struct_i -> i_nser_b_info= -1;
	if(!strlen(p_caevent_struct_h ->h_comp_info_a))
		l_caevent_struct_i -> i_comp_info_a= -1;
	if(!strlen(p_caevent_struct_h ->h_inco_info_a))
		l_caevent_struct_i -> i_inco_info_a= -1;
	if(!strlen(p_caevent_struct_h ->h_responsedt_buy))
		l_caevent_struct_i -> i_responsedt_buy= -1;
	if(!strlen(p_caevent_struct_h ->h_sell_resp_date))
		l_caevent_struct_i -> i_sell_resp_date= -1;
	if(!strlen(p_caevent_struct_h ->h_wwwaddr))
		l_caevent_struct_i -> i_wwwaddr= -1;
	if(!strlen(p_caevent_struct_h ->h_txnr_info_a))
		l_caevent_struct_i -> i_txnr_info_a= -1;
	if(!strlen(p_caevent_struct_h ->h_reqd_certify))
		l_caevent_struct_i -> i_reqd_certify= -1;
	if(!strlen(p_caevent_struct_h ->h_ex_dt_bse))
		l_caevent_struct_i -> i_ex_dt_bse= -1;
	if(!strlen(p_caevent_struct_h ->h_bc_from_date))
		l_caevent_struct_i -> i_bc_from_date= -1;
	if(!strlen(p_caevent_struct_h ->h_bc_to_date))
		l_caevent_struct_i -> i_bc_to_date= -1;
	if(!strlen(p_caevent_struct_h ->h_res_instr_code_2))
		l_caevent_struct_i -> i_res_instr_code_2= -1;
	if(!strlen(p_caevent_struct_h ->h_trans_dt))
		l_caevent_struct_i -> i_trans_dt= -1;
	if(!strlen(p_caevent_struct_h ->h_cln_code))
		l_caevent_struct_i -> i_cln_code= -1;
	if(!strlen(p_caevent_struct_h ->h_prev_inst_date))
		l_caevent_struct_i -> i_prev_inst_date= -1;
	if(!strlen(p_caevent_struct_h ->h_next_inst_date))
		l_caevent_struct_i -> i_next_inst_date= -1;
	if(!strlen(p_caevent_struct_h ->h_inst_start_period))
		l_caevent_struct_i -> i_inst_start_period= -1;
	if(!strlen(p_caevent_struct_h ->h_inst_end_period))
		l_caevent_struct_i -> i_inst_end_period= -1;
	if(!strlen(p_caevent_struct_h ->h_last_ptc_date))
		l_caevent_struct_i -> i_last_ptc_date= -1;
	if(!strlen(p_caevent_struct_h ->h_allotment_letter))
		l_caevent_struct_i -> i_allotment_letter= -1;
	if(!strlen(p_caevent_struct_h ->h_redem_option))
		l_caevent_struct_i -> i_redem_option= -1;

	if(!strlen(p_caevent_struct_h ->h_send_split))
		l_caevent_struct_i -> i_send_split= -1;
	if(!strlen(p_caevent_struct_h ->h_cmp_code))
		l_caevent_struct_i -> i_cmp_code= -1;
	if(!strlen(p_caevent_struct_h ->h_res_cmp_code))
		l_caevent_struct_i -> i_res_cmp_code= -1;
	if(!strlen(p_caevent_struct_h ->h_exch_code))
		l_caevent_struct_i -> i_exch_code= -1;


	if(!strlen(p_caevent_struct_h ->h_interest_type))
		l_caevent_struct_i -> i_interest_type= -1;


	if(!strlen(p_caevent_struct_h ->h_depo_part_code))
		l_caevent_struct_i -> i_depo_part_code= -1;
	if(!strlen(p_caevent_struct_h ->h_depo_code))
		l_caevent_struct_i -> i_depo_code= -1;
	if(!strlen(p_caevent_struct_h ->h_bk_build_ind))
		l_caevent_struct_i -> i_bk_build_ind= -1;
	if(!strlen(p_caevent_struct_h ->h_attach_corp_id))
		l_caevent_struct_i -> i_attach_corp_id= -1;
	if(!strlen(p_caevent_struct_h ->h_source))
		l_caevent_struct_i -> i_source= -1;







	if(!strlen(p_caevent_struct_h ->h_lead_mgr))
		l_caevent_struct_i -> i_lead_mgr= -1;
	if(!strlen(p_caevent_struct_h ->h_synd_membr))
		l_caevent_struct_i -> i_synd_membr= -1;
	if(!strlen(p_caevent_struct_h ->h_co_mgr))
		l_caevent_struct_i -> i_co_mgr= -1;

	/* EXEC SQL INSERT INTO CAEVENT VALUES(:p_caevent_struct_h:l_caevent_struct_i); */ 
#line 3391 "DM_DbInterface.pc"

{
#line 3391 "DM_DbInterface.pc"
 struct sqlexd sqlstm;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqlvsn = 12;
#line 3391 "DM_DbInterface.pc"
 sqlstm.arrsiz = 150;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqladtp = &sqladt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqltdsp = &sqltds;
#line 3391 "DM_DbInterface.pc"
 sqlbuft((void **)0, 
#line 3391 "DM_DbInterface.pc"
   "insert into CAEVENT  values (:s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s\
11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:s21:s22 ,:s23:s24 ,:s25:s26\
 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 ,:s37:s38 ,:s39:s40 ,:s41\
:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s52 ,:s53:s54 ,:s55:s56 ,\
:s57:s58 ,:s59:s60 ,:s61:s62 ,:s63:s64 ,:s65:s66 ,:s67:s68 ,:s69:s70 ,:s71:s\
72 ,:s73:s74 ,:s75:s76 ,:s77:s78 ,:s79:s80 ,:s81:s82 ,:s83:s84 ,:s85:s86 ,:s\
87:s88 ,:s89:s90 ,:s91:s92 ,:s93:s94 ,:s95:s96 ,:s97:s98 ,:s99:s100 ,:s101:s\
102 ,:s103:s104 ,:s105:s106 ,:s107:s108 ,:s109:s110 ,:s111:s112 ,:s113:s114 \
,:s115:s116 ,:s117:s118 ,:s119:s120 ,:s121:s122 ,:s123:s124 ,:s125:s126 ,:s1\
27:s128 ,:s129:s130 ,:s131:s132 ,:s133:s134 ,:s135:s136 ,:s137:s138 ,:s139:s\
140 ,:s141:s142 ,:s143:s144 ,:s145:s146 ,:s147:s148 ,:s149:s150 ,:s151:s152 \
,:s153:s154 ,:s155:s156 ,:s157:s158 ,:s159:s160 ,:s161:s162 ,:s163:s164 ,:s1\
65:s166 ,:s167:s168 ,:s169:s170 ,:s171:s172 ,:s173:s174 ,:s175:s176 ,:s177:s\
178 ,:s179:s180 ,:s181:s182 ,:s183:s184 ");
#line 3391 "DM_DbInterface.pc"
 sqlstm.stmt = ",:s185:s186 ,:s187:s188 ,:s189:s190 ,:s191:s192 ,:s193:s194 \
,:s195:s196 ,:s197:s198 ,:s199:s200 ,:s201:s202 ,:s203:s204 ,:s205:s206 ,:s207\
:s208 ,:s209:s210 ,:s211:s212 ,:s213:s214 ,:s215:s216 ,:s217:s218 ,:s219:s220 \
,:s221:s222 ,:s223:s224 ,:s225:s226 ,:s227:s228 ,:s229:s230 ,:s231:s232 ,:s233\
:s234 ,:s235:s236 )";
#line 3391 "DM_DbInterface.pc"
 sqlstm.iters = (unsigned int  )1;
#line 3391 "DM_DbInterface.pc"
 sqlstm.offset = (unsigned int  )3595;
#line 3391 "DM_DbInterface.pc"
 sqlstm.cud = sqlcud0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 3391 "DM_DbInterface.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)p_caevent_struct_h->h_corp_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[0] = (unsigned long )21;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[0] = (         short *)&l_caevent_struct_i->i_corp_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[1] = (unsigned char  *)p_caevent_struct_h->h_instr_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[1] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[1] = (         short *)&l_caevent_struct_i->i_instr_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[1] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[2] = (unsigned char  *)p_caevent_struct_h->h_ca_event;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[2] = (unsigned long )3;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[2] = (         short *)&l_caevent_struct_i->i_ca_event;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[2] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[3] = (unsigned char  *)p_caevent_struct_h->h_declare_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[3] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[3] = (         short *)&l_caevent_struct_i->i_declare_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[3] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[4] = (unsigned char  *)&p_caevent_struct_h->h_evnt_indnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[4] = (         short *)&l_caevent_struct_i->i_evnt_indnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[4] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[5] = (unsigned char  *)&p_caevent_struct_h->h_priority;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[5] = (         short *)&l_caevent_struct_i->i_priority;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[5] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[6] = (unsigned char  *)p_caevent_struct_h->h_preliminary_flag;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[6] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[6] = (         short *)&l_caevent_struct_i->i_preliminary_flag;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[6] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[7] = (unsigned char  *)p_caevent_struct_h->h_ca_currency;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[7] = (unsigned long )4;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[7] = (         short *)&l_caevent_struct_i->i_ca_currency;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[7] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[8] = (unsigned char  *)p_caevent_struct_h->h_ex_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[8] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[8] = (         short *)&l_caevent_struct_i->i_ex_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[8] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[9] = (unsigned char  *)p_caevent_struct_h->h_rec_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[9] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[9] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[9] = (         short *)&l_caevent_struct_i->i_rec_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[9] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[9] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[9] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[9] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[10] = (unsigned char  *)p_caevent_struct_h->h_dateof_payment;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[10] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[10] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[10] = (         short *)&l_caevent_struct_i->i_dateof_payment;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[10] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[10] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[10] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[10] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[11] = (unsigned char  *)p_caevent_struct_h->h_response_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[11] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[11] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[11] = (         short *)&l_caevent_struct_i->i_response_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[11] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[11] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[11] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[11] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[12] = (unsigned char  *)p_caevent_struct_h->h_expiry_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[12] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[12] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[12] = (         short *)&l_caevent_struct_i->i_expiry_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[12] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[12] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[12] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[12] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[13] = (unsigned char  *)p_caevent_struct_h->h_part_pymt_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[13] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[13] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[13] = (         short *)&l_caevent_struct_i->i_part_pymt_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[13] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[13] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[13] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[13] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[14] = (unsigned char  *)p_caevent_struct_h->h_proxy_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[14] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[14] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[14] = (         short *)&l_caevent_struct_i->i_proxy_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[14] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[14] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[14] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[14] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[15] = (unsigned char  *)p_caevent_struct_h->h_meeting_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[15] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[15] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[15] = (         short *)&l_caevent_struct_i->i_meeting_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[15] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[15] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[15] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[15] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[16] = (unsigned char  *)p_caevent_struct_h->h_start_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[16] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[16] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[16] = (         short *)&l_caevent_struct_i->i_start_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[16] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[16] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[16] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[16] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[17] = (unsigned char  *)p_caevent_struct_h->h_effective_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[17] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[17] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[17] = (         short *)&l_caevent_struct_i->i_effective_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[17] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[17] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[17] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[17] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[18] = (unsigned char  *)p_caevent_struct_h->h_proc_oth;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[18] = (unsigned long )106;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[18] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[18] = (         short *)&l_caevent_struct_i->i_proc_oth;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[18] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[18] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[18] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[18] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[19] = (unsigned char  *)p_caevent_struct_h->h_op_evt_class;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[19] = (unsigned long )3;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[19] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[19] = (         short *)&l_caevent_struct_i->i_op_evt_class;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[19] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[19] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[19] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[19] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[20] = (unsigned char  *)p_caevent_struct_h->h_resp_dt_opnd;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[20] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[20] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[20] = (         short *)&l_caevent_struct_i->i_resp_dt_opnd;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[20] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[20] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[20] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[20] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[21] = (unsigned char  *)p_caevent_struct_h->h_exp_dt_open_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[21] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[21] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[21] = (         short *)&l_caevent_struct_i->i_exp_dt_open_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[21] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[21] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[21] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[21] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[22] = (unsigned char  *)p_caevent_struct_h->h_evt_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[22] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[22] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[22] = (         short *)&l_caevent_struct_i->i_evt_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[22] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[22] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[22] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[22] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[23] = (unsigned char  *)p_caevent_struct_h->h_entl_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[23] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[23] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[23] = (         short *)&l_caevent_struct_i->i_entl_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[23] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[23] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[23] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[23] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[24] = (unsigned char  *)p_caevent_struct_h->h_pymt_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[24] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[24] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[24] = (         short *)&l_caevent_struct_i->i_pymt_send_msg_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[24] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[24] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[24] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[24] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[25] = (unsigned char  *)&p_caevent_struct_h->h_earnings;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[25] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[25] = (         short *)&l_caevent_struct_i->i_earnings;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[25] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[25] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[25] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[25] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[26] = (unsigned char  *)&p_caevent_struct_h->h_earnings_rate;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[26] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[26] = (         short *)&l_caevent_struct_i->i_earnings_rate;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[26] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[26] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[26] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[26] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[27] = (unsigned char  *)p_caevent_struct_h->h_res_instr_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[27] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[27] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[27] = (         short *)&l_caevent_struct_i->i_res_instr_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[27] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[27] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[27] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[27] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[28] = (unsigned char  *)&p_caevent_struct_h->h_new_safek_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[28] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[28] = (         short *)&l_caevent_struct_i->i_new_safek_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[28] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[28] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[28] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[28] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[29] = (unsigned char  *)&p_caevent_struct_h->h_old_stk_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[29] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[29] = (         short *)&l_caevent_struct_i->i_old_stk_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[29] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[29] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[29] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[29] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[30] = (unsigned char  *)p_caevent_struct_h->h_disp_of_fract;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[30] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[30] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[30] = (         short *)&l_caevent_struct_i->i_disp_of_fract;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[30] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[30] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[30] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[30] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[31] = (unsigned char  *)&p_caevent_struct_h->h_fract_pr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[31] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[31] = (         short *)&l_caevent_struct_i->i_fract_pr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[31] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[31] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[31] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[31] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[32] = (unsigned char  *)&p_caevent_struct_h->h_sub_base_quantity;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[32] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[32] = (         short *)&l_caevent_struct_i->i_sub_base_quantity;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[32] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[32] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[32] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[32] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[33] = (unsigned char  *)&p_caevent_struct_h->h_sub_new_quantity;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[33] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[33] = (         short *)&l_caevent_struct_i->i_sub_new_quantity;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[33] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[33] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[33] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[33] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[34] = (unsigned char  *)&p_caevent_struct_h->h_sub_pr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[34] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[34] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[34] = (         short *)&l_caevent_struct_i->i_sub_pr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[34] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[34] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[34] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[34] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[35] = (unsigned char  *)p_caevent_struct_h->h_rhts_class;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[35] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[35] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[35] = (         short *)&l_caevent_struct_i->i_rhts_class;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[35] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[35] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[35] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[35] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[36] = (unsigned char  *)&p_caevent_struct_h->h_new_safek_rt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[36] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[36] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[36] = (         short *)&l_caevent_struct_i->i_new_safek_rt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[36] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[36] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[36] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[36] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[37] = (unsigned char  *)p_caevent_struct_h->h_contact_details;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[37] = (unsigned long )241;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[37] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[37] = (         short *)&l_caevent_struct_i->i_contact_details;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[37] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[37] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[37] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[37] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[38] = (unsigned char  *)&p_caevent_struct_h->h_amount_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[38] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[38] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[38] = (         short *)&l_caevent_struct_i->i_amount_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[38] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[38] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[38] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[38] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[39] = (unsigned char  *)&p_caevent_struct_h->h_received_amt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[39] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[39] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[39] = (         short *)&l_caevent_struct_i->i_received_amt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[39] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[39] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[39] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[39] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[40] = (unsigned char  *)&p_caevent_struct_h->h_quantity_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[40] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[40] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[40] = (         short *)&l_caevent_struct_i->i_quantity_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[40] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[40] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[40] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[40] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[41] = (unsigned char  *)&p_caevent_struct_h->h_quantity_received;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[41] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[41] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[41] = (         short *)&l_caevent_struct_i->i_quantity_received;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[41] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[41] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[41] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[41] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[42] = (unsigned char  *)&p_caevent_struct_h->h_evt_msg_count;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[42] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[42] = (         short *)&l_caevent_struct_i->i_evt_msg_count;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[42] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[42] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[42] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[42] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[43] = (unsigned char  *)&p_caevent_struct_h->h_evt_clt_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[43] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[43] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[43] = (         short *)&l_caevent_struct_i->i_evt_clt_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[43] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[43] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[43] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[43] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[44] = (unsigned char  *)&p_caevent_struct_h->h_entl_msg_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[44] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[44] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[44] = (         short *)&l_caevent_struct_i->i_entl_msg_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[44] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[44] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[44] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[44] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[45] = (unsigned char  *)&p_caevent_struct_h->h_entl_clt_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[45] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[45] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[45] = (         short *)&l_caevent_struct_i->i_entl_clt_cnt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[45] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[45] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[45] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[45] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[46] = (unsigned char  *)&p_caevent_struct_h->h_count_acs_pend;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[46] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[46] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[46] = (         short *)&l_caevent_struct_i->i_count_acs_pend;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[46] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[46] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[46] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[46] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[47] = (unsigned char  *)p_caevent_struct_h->h_nrep_date_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[47] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[47] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[47] = (         short *)&l_caevent_struct_i->i_nrep_date_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[47] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[47] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[47] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[47] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[48] = (unsigned char  *)p_caevent_struct_h->h_msg_followdays1;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[48] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[48] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[48] = (         short *)&l_caevent_struct_i->i_msg_followdays1;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[48] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[48] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[48] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[48] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[49] = (unsigned char  *)p_caevent_struct_h->h_msg_followdays2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[49] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[49] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[49] = (         short *)&l_caevent_struct_i->i_msg_followdays2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[49] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[49] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[49] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[49] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[50] = (unsigned char  *)p_caevent_struct_h->h_info_seq;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[50] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[50] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[50] = (         short *)&l_caevent_struct_i->i_info_seq;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[50] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[50] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[50] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[50] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[51] = (unsigned char  *)p_caevent_struct_h->h_entitl_infono;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[51] = (unsigned long )5;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[51] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[51] = (         short *)&l_caevent_struct_i->i_entitl_infono;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[51] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[51] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[51] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[51] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[52] = (unsigned char  *)p_caevent_struct_h->h_status;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[52] = (unsigned long )3;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[52] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[52] = (         short *)&l_caevent_struct_i->i_status;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[52] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[52] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[52] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[52] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[53] = (unsigned char  *)p_caevent_struct_h->h_processed_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[53] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[53] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[53] = (         short *)&l_caevent_struct_i->i_processed_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[53] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[53] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[53] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[53] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[54] = (unsigned char  *)p_caevent_struct_h->h_maker;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[54] = (unsigned long )15;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[54] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[54] = (         short *)&l_caevent_struct_i->i_maker;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[54] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[54] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[54] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[54] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[55] = (unsigned char  *)p_caevent_struct_h->h_maker_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[55] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[55] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[55] = (         short *)&l_caevent_struct_i->i_maker_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[55] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[55] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[55] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[55] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[56] = (unsigned char  *)p_caevent_struct_h->h_checker;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[56] = (unsigned long )15;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[56] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[56] = (         short *)&l_caevent_struct_i->i_checker;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[56] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[56] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[56] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[56] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[57] = (unsigned char  *)p_caevent_struct_h->h_checker_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[57] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[57] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[57] = (         short *)&l_caevent_struct_i->i_checker_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[57] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[57] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[57] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[57] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[58] = (unsigned char  *)p_caevent_struct_h->h_access_stamp;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[58] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[58] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[58] = (         short *)&l_caevent_struct_i->i_access_stamp;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[58] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[58] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[58] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[58] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[59] = (unsigned char  *)p_caevent_struct_h->h_deal_frm_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[59] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[59] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[59] = (         short *)&l_caevent_struct_i->i_deal_frm_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[59] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[59] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[59] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[59] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[60] = (unsigned char  *)p_caevent_struct_h->h_deal_to_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[60] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[60] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[60] = (         short *)&l_caevent_struct_i->i_deal_to_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[60] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[60] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[60] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[60] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[61] = (unsigned char  *)p_caevent_struct_h->h_subscr_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[61] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[61] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[61] = (         short *)&l_caevent_struct_i->i_subscr_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[61] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[61] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[61] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[61] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[62] = (unsigned char  *)p_caevent_struct_h->h_post_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[62] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[62] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[62] = (         short *)&l_caevent_struct_i->i_post_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[62] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[62] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[62] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[62] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[63] = (unsigned char  *)p_caevent_struct_h->h_over_subscrp;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[63] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[63] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[63] = (         short *)&l_caevent_struct_i->i_over_subscrp;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[63] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[63] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[63] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[63] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[64] = (unsigned char  *)p_caevent_struct_h->h_dividend_type;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[64] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[64] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[64] = (         short *)&l_caevent_struct_i->i_dividend_type;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[64] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[64] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[64] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[64] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[65] = (unsigned char  *)&p_caevent_struct_h->h_redem_rt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[65] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[65] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[65] = (         short *)&l_caevent_struct_i->i_redem_rt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[65] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[65] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[65] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[65] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[66] = (unsigned char  *)p_caevent_struct_h->h_nser_e_info;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[66] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[66] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[66] = (         short *)&l_caevent_struct_i->i_nser_e_info;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[66] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[66] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[66] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[66] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[67] = (unsigned char  *)p_caevent_struct_h->h_nser_b_info;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[67] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[67] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[67] = (         short *)&l_caevent_struct_i->i_nser_b_info;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[67] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[67] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[67] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[67] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[68] = (unsigned char  *)p_caevent_struct_h->h_comp_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[68] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[68] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[68] = (         short *)&l_caevent_struct_i->i_comp_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[68] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[68] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[68] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[68] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[69] = (unsigned char  *)p_caevent_struct_h->h_inco_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[69] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[69] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[69] = (         short *)&l_caevent_struct_i->i_inco_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[69] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[69] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[69] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[69] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[70] = (unsigned char  *)p_caevent_struct_h->h_responsedt_buy;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[70] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[70] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[70] = (         short *)&l_caevent_struct_i->i_responsedt_buy;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[70] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[70] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[70] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[70] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[71] = (unsigned char  *)p_caevent_struct_h->h_sell_resp_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[71] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[71] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[71] = (         short *)&l_caevent_struct_i->i_sell_resp_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[71] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[71] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[71] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[71] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[72] = (unsigned char  *)p_caevent_struct_h->h_wwwaddr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[72] = (unsigned long )101;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[72] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[72] = (         short *)&l_caevent_struct_i->i_wwwaddr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[72] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[72] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[72] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[72] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[73] = (unsigned char  *)p_caevent_struct_h->h_txnr_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[73] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[73] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[73] = (         short *)&l_caevent_struct_i->i_txnr_info_a;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[73] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[73] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[73] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[73] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[74] = (unsigned char  *)p_caevent_struct_h->h_reqd_certify;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[74] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[74] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[74] = (         short *)&l_caevent_struct_i->i_reqd_certify;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[74] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[74] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[74] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[74] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[75] = (unsigned char  *)p_caevent_struct_h->h_ex_dt_bse;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[75] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[75] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[75] = (         short *)&l_caevent_struct_i->i_ex_dt_bse;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[75] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[75] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[75] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[75] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[76] = (unsigned char  *)p_caevent_struct_h->h_bc_from_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[76] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[76] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[76] = (         short *)&l_caevent_struct_i->i_bc_from_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[76] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[76] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[76] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[76] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[77] = (unsigned char  *)p_caevent_struct_h->h_bc_to_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[77] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[77] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[77] = (         short *)&l_caevent_struct_i->i_bc_to_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[77] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[77] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[77] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[77] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[78] = (unsigned char  *)p_caevent_struct_h->h_res_instr_code_2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[78] = (unsigned long )9;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[78] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[78] = (         short *)&l_caevent_struct_i->i_res_instr_code_2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[78] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[78] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[78] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[78] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[79] = (unsigned char  *)p_caevent_struct_h->h_trans_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[79] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[79] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[79] = (         short *)&l_caevent_struct_i->i_trans_dt;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[79] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[79] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[79] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[79] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[80] = (unsigned char  *)p_caevent_struct_h->h_cln_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[80] = (unsigned long )11;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[80] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[80] = (         short *)&l_caevent_struct_i->i_cln_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[80] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[80] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[80] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[80] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[81] = (unsigned char  *)p_caevent_struct_h->h_prev_inst_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[81] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[81] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[81] = (         short *)&l_caevent_struct_i->i_prev_inst_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[81] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[81] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[81] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[81] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[82] = (unsigned char  *)p_caevent_struct_h->h_next_inst_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[82] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[82] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[82] = (         short *)&l_caevent_struct_i->i_next_inst_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[82] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[82] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[82] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[82] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[83] = (unsigned char  *)p_caevent_struct_h->h_inst_start_period;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[83] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[83] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[83] = (         short *)&l_caevent_struct_i->i_inst_start_period;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[83] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[83] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[83] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[83] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[84] = (unsigned char  *)p_caevent_struct_h->h_inst_end_period;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[84] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[84] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[84] = (         short *)&l_caevent_struct_i->i_inst_end_period;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[84] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[84] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[84] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[84] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[85] = (unsigned char  *)p_caevent_struct_h->h_last_ptc_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[85] = (unsigned long )20;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[85] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[85] = (         short *)&l_caevent_struct_i->i_last_ptc_date;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[85] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[85] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[85] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[85] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[86] = (unsigned char  *)p_caevent_struct_h->h_allotment_letter;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[86] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[86] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[86] = (         short *)&l_caevent_struct_i->i_allotment_letter;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[86] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[86] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[86] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[86] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[87] = (unsigned char  *)p_caevent_struct_h->h_redem_option;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[87] = (unsigned long )4;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[87] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[87] = (         short *)&l_caevent_struct_i->i_redem_option;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[87] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[87] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[87] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[87] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[88] = (unsigned char  *)&p_caevent_struct_h->h_inst_amount;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[88] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[88] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[88] = (         short *)&l_caevent_struct_i->i_inst_amount;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[88] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[88] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[88] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[88] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[89] = (unsigned char  *)p_caevent_struct_h->h_send_split;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[89] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[89] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[89] = (         short *)&l_caevent_struct_i->i_send_split;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[89] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[89] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[89] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[89] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[90] = (unsigned char  *)p_caevent_struct_h->h_cmp_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[90] = (unsigned long )11;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[90] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[90] = (         short *)&l_caevent_struct_i->i_cmp_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[90] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[90] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[90] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[90] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[91] = (unsigned char  *)p_caevent_struct_h->h_res_cmp_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[91] = (unsigned long )11;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[91] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[91] = (         short *)&l_caevent_struct_i->i_res_cmp_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[91] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[91] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[91] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[91] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[92] = (unsigned char  *)p_caevent_struct_h->h_exch_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[92] = (unsigned long )4;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[92] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[92] = (         short *)&l_caevent_struct_i->i_exch_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[92] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[92] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[92] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[92] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[93] = (unsigned char  *)&p_caevent_struct_h->h_premium;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[93] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[93] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[93] = (         short *)&l_caevent_struct_i->i_premium;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[93] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[93] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[93] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[93] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[94] = (unsigned char  *)&p_caevent_struct_h->h_face_value;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[94] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[94] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[94] = (         short *)&l_caevent_struct_i->i_face_value;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[94] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[94] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[94] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[94] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[95] = (unsigned char  *)p_caevent_struct_h->h_interest_type;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[95] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[95] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[95] = (         short *)&l_caevent_struct_i->i_interest_type;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[95] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[95] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[95] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[95] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[96] = (unsigned char  *)&p_caevent_struct_h->h_ratio_rcv2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[96] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[96] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[96] = (         short *)&l_caevent_struct_i->i_ratio_rcv2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[96] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[96] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[96] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[96] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[97] = (unsigned char  *)&p_caevent_struct_h->h_ratio_hld2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[97] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[97] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[97] = (         short *)&l_caevent_struct_i->i_ratio_hld2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[97] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[97] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[97] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[97] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[98] = (unsigned char  *)p_caevent_struct_h->h_depo_part_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[98] = (unsigned long )21;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[98] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[98] = (         short *)&l_caevent_struct_i->i_depo_part_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[98] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[98] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[98] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[98] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[99] = (unsigned char  *)p_caevent_struct_h->h_depo_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[99] = (unsigned long )5;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[99] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[99] = (         short *)&l_caevent_struct_i->i_depo_code;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[99] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[99] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[99] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[99] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[100] = (unsigned char  *)p_caevent_struct_h->h_bk_build_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[100] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[100] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[100] = (         short *)&l_caevent_struct_i->i_bk_build_ind;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[100] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[100] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[100] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[100] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[101] = (unsigned char  *)p_caevent_struct_h->h_attach_corp_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[101] = (unsigned long )21;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[101] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[101] = (         short *)&l_caevent_struct_i->i_attach_corp_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[101] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[101] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[101] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[101] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[102] = (unsigned char  *)p_caevent_struct_h->h_source;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[102] = (unsigned long )2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[102] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[102] = (         short *)&l_caevent_struct_i->i_source;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[102] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[102] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[102] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[102] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[103] = (unsigned char  *)&p_caevent_struct_h->h_new_safek_rt2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[103] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[103] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[103] = (         short *)&l_caevent_struct_i->i_new_safek_rt2;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[103] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[103] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[103] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[103] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[104] = (unsigned char  *)&p_caevent_struct_h->h_tick_size;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[104] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[104] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[104] = (         short *)&l_caevent_struct_i->i_tick_size;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[104] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[104] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[104] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[104] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[105] = (unsigned char  *)&p_caevent_struct_h->h_issue_size;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[105] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[105] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[105] = (         short *)&l_caevent_struct_i->i_issue_size;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[105] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[105] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[105] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[105] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[106] = (unsigned char  *)&p_caevent_struct_h->h_qib_margin;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[106] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[106] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[106] = (         short *)&l_caevent_struct_i->i_qib_margin;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[106] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[106] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[106] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[106] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[107] = (unsigned char  *)&p_caevent_struct_h->h_market_lot;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[107] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[107] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[107] = (         short *)&l_caevent_struct_i->i_market_lot;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[107] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[107] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[107] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[107] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[108] = (unsigned char  *)&p_caevent_struct_h->h_max_rtl_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[108] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[108] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[108] = (         short *)&l_caevent_struct_i->i_max_rtl_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[108] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[108] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[108] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[108] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[109] = (unsigned char  *)&p_caevent_struct_h->h_min_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[109] = (unsigned long )sizeof(int);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[109] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[109] = (         short *)&l_caevent_struct_i->i_min_qty;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[109] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[109] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[109] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[109] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[110] = (unsigned char  *)p_caevent_struct_h->h_lead_mgr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[110] = (unsigned long )106;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[110] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[110] = (         short *)&l_caevent_struct_i->i_lead_mgr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[110] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[110] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[110] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[110] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[111] = (unsigned char  *)p_caevent_struct_h->h_synd_membr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[111] = (unsigned long )106;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[111] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[111] = (         short *)&l_caevent_struct_i->i_synd_membr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[111] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[111] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[111] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[111] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[112] = (unsigned char  *)p_caevent_struct_h->h_co_mgr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[112] = (unsigned long )106;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[112] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[112] = (         short *)&l_caevent_struct_i->i_co_mgr;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[112] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[112] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[112] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[112] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[113] = (unsigned char  *)&p_caevent_struct_h->h_lwr_limit;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[113] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[113] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[113] = (         short *)&l_caevent_struct_i->i_lwr_limit;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[113] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[113] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[113] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[113] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[114] = (unsigned char  *)&p_caevent_struct_h->h_upr_limit;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[114] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[114] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[114] = (         short *)&l_caevent_struct_i->i_upr_limit;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[114] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[114] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[114] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[114] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[115] = (unsigned char  *)&p_caevent_struct_h->h_fract_qty_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[115] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[115] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[115] = (         short *)&l_caevent_struct_i->i_fract_qty_bal;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[115] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[115] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[115] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[115] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[116] = (unsigned char  *)&p_caevent_struct_h->h_fract_qty_recd;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[116] = (unsigned long )sizeof(double);
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[116] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[116] = (         short *)&l_caevent_struct_i->i_fract_qty_recd;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[116] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[116] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[116] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[116] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstv[117] = (unsigned char  *)p_caevent_struct_h->h_bilav_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhstl[117] = (unsigned long )11;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqhsts[117] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqindv[117] = (         short *)&l_caevent_struct_i->i_bilav_id;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqinds[117] = (         int  )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqharm[117] = (unsigned long )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqadto[117] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqtdso[117] = (unsigned short )0;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 3391 "DM_DbInterface.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 3391 "DM_DbInterface.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 3391 "DM_DbInterface.pc"
}

#line 3391 "DM_DbInterface.pc"



		printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CORP_ID",p_caevent_struct_h -> h_corp_id,l_caevent_struct_i -> i_corp_id,strlen(p_caevent_struct_h -> h_corp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INSTR_CODE",p_caevent_struct_h -> h_instr_code,l_caevent_struct_i -> i_instr_code,strlen(p_caevent_struct_h -> h_instr_code),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CA_EVENT",p_caevent_struct_h -> h_ca_event,l_caevent_struct_i -> i_ca_event,strlen(p_caevent_struct_h -> h_ca_event),2);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DECLARE_DT",p_caevent_struct_h -> h_declare_dt,l_caevent_struct_i -> i_declare_dt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","EVNT_INDNT",p_caevent_struct_h -> h_evnt_indnt,l_caevent_struct_i -> i_evnt_indnt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","PRIORITY",p_caevent_struct_h -> h_priority,l_caevent_struct_i -> i_priority);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PRELIMINARY_FLAG",p_caevent_struct_h -> h_preliminary_flag,l_caevent_struct_i -> i_preliminary_flag,strlen(p_caevent_struct_h -> h_preliminary_flag),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CA_CURRENCY",p_caevent_struct_h -> h_ca_currency,l_caevent_struct_i -> i_ca_currency,strlen(p_caevent_struct_h -> h_ca_currency),3);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EX_DATE",p_caevent_struct_h -> h_ex_date,l_caevent_struct_i -> i_ex_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","REC_DATE",p_caevent_struct_h -> h_rec_date,l_caevent_struct_i -> i_rec_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DATEOF_PAYMENT",p_caevent_struct_h -> h_dateof_payment,l_caevent_struct_i -> i_dateof_payment);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RESPONSE_DATE",p_caevent_struct_h -> h_response_date,l_caevent_struct_i -> i_response_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EXPIRY_DATE",p_caevent_struct_h -> h_expiry_date,l_caevent_struct_i -> i_expiry_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PART_PYMT_DT",p_caevent_struct_h -> h_part_pymt_dt,l_caevent_struct_i -> i_part_pymt_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PROXY_DATE",p_caevent_struct_h -> h_proxy_date,l_caevent_struct_i -> i_proxy_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MEETING_DATE",p_caevent_struct_h -> h_meeting_date,l_caevent_struct_i -> i_meeting_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","START_DATE",p_caevent_struct_h -> h_start_date,l_caevent_struct_i -> i_start_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EFFECTIVE_DATE",p_caevent_struct_h -> h_effective_date,l_caevent_struct_i -> i_effective_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PROC_OTH",p_caevent_struct_h -> h_proc_oth,l_caevent_struct_i -> i_proc_oth,strlen(p_caevent_struct_h -> h_proc_oth),105);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","OP_EVT_CLASS",p_caevent_struct_h -> h_op_evt_class,l_caevent_struct_i -> i_op_evt_class,strlen(p_caevent_struct_h -> h_op_evt_class),2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RESP_DT_OPND",p_caevent_struct_h -> h_resp_dt_opnd,l_caevent_struct_i -> i_resp_dt_opnd,strlen(p_caevent_struct_h -> h_resp_dt_opnd),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXP_DT_OPEN_IND",p_caevent_struct_h -> h_exp_dt_open_ind,l_caevent_struct_i -> i_exp_dt_open_ind,strlen(p_caevent_struct_h -> h_exp_dt_open_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EVT_SEND_MSG_IND",p_caevent_struct_h -> h_evt_send_msg_ind,l_caevent_struct_i -> i_evt_send_msg_ind,strlen(p_caevent_struct_h -> h_evt_send_msg_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ENTL_SEND_MSG_IND",p_caevent_struct_h -> h_entl_send_msg_ind,l_caevent_struct_i -> i_entl_send_msg_ind,strlen(p_caevent_struct_h -> h_entl_send_msg_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","PYMT_SEND_MSG_IND",p_caevent_struct_h -> h_pymt_send_msg_ind,l_caevent_struct_i -> i_pymt_send_msg_ind,strlen(p_caevent_struct_h -> h_pymt_send_msg_ind),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","EARNINGS",p_caevent_struct_h -> h_earnings,l_caevent_struct_i -> i_earnings);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","EARNINGS_RATE",p_caevent_struct_h -> h_earnings_rate,l_caevent_struct_i -> i_earnings_rate);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RES_INSTR_CODE",p_caevent_struct_h -> h_res_instr_code,l_caevent_struct_i -> i_res_instr_code,strlen(p_caevent_struct_h -> h_res_instr_code),8);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","NEW_SAFEK_QTY",p_caevent_struct_h -> h_new_safek_qty,l_caevent_struct_i -> i_new_safek_qty);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","OLD_STK_QTY",p_caevent_struct_h -> h_old_stk_qty,l_caevent_struct_i -> i_old_stk_qty);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DISP_OF_FRACT",p_caevent_struct_h -> h_disp_of_fract,l_caevent_struct_i -> i_disp_of_fract,strlen(p_caevent_struct_h -> h_disp_of_fract),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FRACT_PR",p_caevent_struct_h -> h_fract_pr,l_caevent_struct_i -> i_fract_pr);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","SUB_BASE_QUANTITY",p_caevent_struct_h -> h_sub_base_quantity,l_caevent_struct_i -> i_sub_base_quantity);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","SUB_NEW_QUANTITY",p_caevent_struct_h -> h_sub_new_quantity,l_caevent_struct_i -> i_sub_new_quantity);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","SUB_PR",p_caevent_struct_h -> h_sub_pr,l_caevent_struct_i -> i_sub_pr);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RHTS_CLASS",p_caevent_struct_h -> h_rhts_class,l_caevent_struct_i -> i_rhts_class,strlen(p_caevent_struct_h -> h_rhts_class),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","NEW_SAFEK_RT",p_caevent_struct_h -> h_new_safek_rt,l_caevent_struct_i -> i_new_safek_rt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CONTACT_DETAILS",p_caevent_struct_h -> h_contact_details,l_caevent_struct_i -> i_contact_details,strlen(p_caevent_struct_h -> h_contact_details),240);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","AMOUNT_BAL",p_caevent_struct_h -> h_amount_bal,l_caevent_struct_i -> i_amount_bal);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","RECEIVED_AMT",p_caevent_struct_h -> h_received_amt,l_caevent_struct_i -> i_received_amt);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","QUANTITY_BAL",p_caevent_struct_h -> h_quantity_bal,l_caevent_struct_i -> i_quantity_bal);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","QUANTITY_RECEIVED",p_caevent_struct_h -> h_quantity_received,l_caevent_struct_i -> i_quantity_received);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","EVT_MSG_COUNT",p_caevent_struct_h -> h_evt_msg_count,l_caevent_struct_i -> i_evt_msg_count);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","EVT_CLT_CNT",p_caevent_struct_h -> h_evt_clt_cnt,l_caevent_struct_i -> i_evt_clt_cnt);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","COUNT_ACS_PEND",p_caevent_struct_h -> h_count_acs_pend,l_caevent_struct_i -> i_count_acs_pend);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NREP_DATE_A",p_caevent_struct_h -> h_nrep_date_a,l_caevent_struct_i -> i_nrep_date_a);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MSG_FOLLOWDAYS1",p_caevent_struct_h -> h_msg_followdays1,l_caevent_struct_i -> i_msg_followdays1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MSG_FOLLOWDAYS2",p_caevent_struct_h -> h_msg_followdays2,l_caevent_struct_i -> i_msg_followdays2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INFO_SEQ",p_caevent_struct_h -> h_info_seq,l_caevent_struct_i -> i_info_seq,strlen(p_caevent_struct_h -> h_info_seq),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ENTITL_INFONO",p_caevent_struct_h -> h_entitl_infono,l_caevent_struct_i -> i_entitl_infono,strlen(p_caevent_struct_h -> h_entitl_infono),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","STATUS",p_caevent_struct_h -> h_status,l_caevent_struct_i -> i_status,strlen(p_caevent_struct_h -> h_status),2);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PROCESSED_DATE",p_caevent_struct_h -> h_processed_date,l_caevent_struct_i -> i_processed_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","MAKER",p_caevent_struct_h -> h_maker,l_caevent_struct_i -> i_maker,strlen(p_caevent_struct_h -> h_maker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","MAKER_DT",p_caevent_struct_h -> h_maker_dt,l_caevent_struct_i -> i_maker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CHECKER",p_caevent_struct_h -> h_checker,l_caevent_struct_i -> i_checker,strlen(p_caevent_struct_h -> h_checker),14);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","CHECKER_DT",p_caevent_struct_h -> h_checker_dt,l_caevent_struct_i -> i_checker_dt);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","ACCESS_STAMP",p_caevent_struct_h -> h_access_stamp,l_caevent_struct_i -> i_access_stamp);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DEAL_FRM_DATE",p_caevent_struct_h -> h_deal_frm_date,l_caevent_struct_i -> i_deal_frm_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","DEAL_TO_DATE",p_caevent_struct_h -> h_deal_to_date,l_caevent_struct_i -> i_deal_to_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","SUBSCR_DATE",p_caevent_struct_h -> h_subscr_date,l_caevent_struct_i -> i_subscr_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","POST_DATE",p_caevent_struct_h -> h_post_date,l_caevent_struct_i -> i_post_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","OVER_SUBSCRP",p_caevent_struct_h -> h_over_subscrp,l_caevent_struct_i -> i_over_subscrp,strlen(p_caevent_struct_h -> h_over_subscrp),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DIVIDEND_TYPE",p_caevent_struct_h -> h_dividend_type,l_caevent_struct_i -> i_dividend_type,strlen(p_caevent_struct_h -> h_dividend_type),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","REDEM_RT",p_caevent_struct_h -> h_redem_rt,l_caevent_struct_i -> i_redem_rt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NSER_E_INFO",p_caevent_struct_h -> h_nser_e_info,l_caevent_struct_i -> i_nser_e_info,strlen(p_caevent_struct_h -> h_nser_e_info),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","NSER_B_INFO",p_caevent_struct_h -> h_nser_b_info,l_caevent_struct_i -> i_nser_b_info,strlen(p_caevent_struct_h -> h_nser_b_info),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","COMP_INFO_A",p_caevent_struct_h -> h_comp_info_a,l_caevent_struct_i -> i_comp_info_a,strlen(p_caevent_struct_h -> h_comp_info_a),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INCO_INFO_A",p_caevent_struct_h -> h_inco_info_a,l_caevent_struct_i -> i_inco_info_a,strlen(p_caevent_struct_h -> h_inco_info_a),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","RESPONSEDT_BUY",p_caevent_struct_h -> h_responsedt_buy,l_caevent_struct_i -> i_responsedt_buy);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","SELL_RESP_DATE",p_caevent_struct_h -> h_sell_resp_date,l_caevent_struct_i -> i_sell_resp_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","WWWADDR",p_caevent_struct_h -> h_wwwaddr,l_caevent_struct_i -> i_wwwaddr,strlen(p_caevent_struct_h -> h_wwwaddr),100);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","TXNR_INFO_A",p_caevent_struct_h -> h_txnr_info_a,l_caevent_struct_i -> i_txnr_info_a,strlen(p_caevent_struct_h -> h_txnr_info_a),8);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REQD_CERTIFY",p_caevent_struct_h -> h_reqd_certify,l_caevent_struct_i -> i_reqd_certify,strlen(p_caevent_struct_h -> h_reqd_certify),1);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","EX_DT_BSE",p_caevent_struct_h -> h_ex_dt_bse,l_caevent_struct_i -> i_ex_dt_bse);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","BC_FROM_DATE",p_caevent_struct_h -> h_bc_from_date,l_caevent_struct_i -> i_bc_from_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","BC_TO_DATE",p_caevent_struct_h -> h_bc_to_date,l_caevent_struct_i -> i_bc_to_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RES_INSTR_CODE_2",p_caevent_struct_h -> h_res_instr_code_2,l_caevent_struct_i -> i_res_instr_code_2,strlen(p_caevent_struct_h -> h_res_instr_code_2),8);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","TRANS_DT",p_caevent_struct_h -> h_trans_dt,l_caevent_struct_i -> i_trans_dt);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CLN_CODE",p_caevent_struct_h -> h_cln_code,l_caevent_struct_i -> i_cln_code,strlen(p_caevent_struct_h -> h_cln_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","PREV_INST_DATE",p_caevent_struct_h -> h_prev_inst_date,l_caevent_struct_i -> i_prev_inst_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","NEXT_INST_DATE",p_caevent_struct_h -> h_next_inst_date,l_caevent_struct_i -> i_next_inst_date);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INST_START_PERIOD",p_caevent_struct_h -> h_inst_start_period,l_caevent_struct_i -> i_inst_start_period);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","INST_END_PERIOD",p_caevent_struct_h -> h_inst_end_period,l_caevent_struct_i -> i_inst_end_period);
	printf("Col |%s| Value |%s| Value Ind|%d|\n","LAST_PTC_DATE",p_caevent_struct_h -> h_last_ptc_date,l_caevent_struct_i -> i_last_ptc_date);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ALLOTMENT_LETTER",p_caevent_struct_h -> h_allotment_letter,l_caevent_struct_i -> i_allotment_letter,strlen(p_caevent_struct_h -> h_allotment_letter),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","REDEM_OPTION",p_caevent_struct_h -> h_redem_option,l_caevent_struct_i -> i_redem_option,strlen(p_caevent_struct_h -> h_redem_option),3);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","INST_AMOUNT",p_caevent_struct_h -> h_inst_amount,l_caevent_struct_i -> i_inst_amount);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SEND_SPLIT",p_caevent_struct_h -> h_send_split,l_caevent_struct_i -> i_send_split,strlen(p_caevent_struct_h -> h_send_split),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CMP_CODE",p_caevent_struct_h -> h_cmp_code,l_caevent_struct_i -> i_cmp_code,strlen(p_caevent_struct_h -> h_cmp_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","RES_CMP_CODE",p_caevent_struct_h -> h_res_cmp_code,l_caevent_struct_i -> i_res_cmp_code,strlen(p_caevent_struct_h -> h_res_cmp_code),10);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","EXCH_CODE",p_caevent_struct_h -> h_exch_code,l_caevent_struct_i -> i_exch_code,strlen(p_caevent_struct_h -> h_exch_code),3);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","PREMIUM",p_caevent_struct_h -> h_premium,l_caevent_struct_i -> i_premium);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FACE_VALUE",p_caevent_struct_h -> h_face_value,l_caevent_struct_i -> i_face_value);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","INTEREST_TYPE",p_caevent_struct_h -> h_interest_type,l_caevent_struct_i -> i_interest_type,strlen(p_caevent_struct_h -> h_interest_type),1);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","RATIO_RCV2",p_caevent_struct_h -> h_ratio_rcv2,l_caevent_struct_i -> i_ratio_rcv2);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","RATIO_HLD2",p_caevent_struct_h -> h_ratio_hld2,l_caevent_struct_i -> i_ratio_hld2);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_PART_CODE",p_caevent_struct_h -> h_depo_part_code,l_caevent_struct_i -> i_depo_part_code,strlen(p_caevent_struct_h -> h_depo_part_code),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","DEPO_CODE",p_caevent_struct_h -> h_depo_code,l_caevent_struct_i -> i_depo_code,strlen(p_caevent_struct_h -> h_depo_code),4);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","BK_BUILD_IND",p_caevent_struct_h -> h_bk_build_ind,l_caevent_struct_i -> i_bk_build_ind,strlen(p_caevent_struct_h -> h_bk_build_ind),1);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","ATTACH_CORP_ID",p_caevent_struct_h -> h_attach_corp_id,l_caevent_struct_i -> i_attach_corp_id,strlen(p_caevent_struct_h -> h_attach_corp_id),20);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SOURCE",p_caevent_struct_h -> h_source,l_caevent_struct_i -> i_source,strlen(p_caevent_struct_h -> h_source),1);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","NEW_SAFEK_RT2",p_caevent_struct_h -> h_new_safek_rt2,l_caevent_struct_i -> i_new_safek_rt2);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","TICK_SIZE",p_caevent_struct_h -> h_tick_size,l_caevent_struct_i -> i_tick_size);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","ISSUE_SIZE",p_caevent_struct_h -> h_issue_size,l_caevent_struct_i -> i_issue_size);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","QIB_MARGIN",p_caevent_struct_h -> h_qib_margin,l_caevent_struct_i -> i_qib_margin);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","MARKET_LOT",p_caevent_struct_h -> h_market_lot,l_caevent_struct_i -> i_market_lot);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","MAX_RTL_QTY",p_caevent_struct_h -> h_max_rtl_qty,l_caevent_struct_i -> i_max_rtl_qty);
	printf("Col |%s| Value |%d| Value Ind|%d|\n","MIN_QTY",p_caevent_struct_h -> h_min_qty,l_caevent_struct_i -> i_min_qty);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","LEAD_MGR",p_caevent_struct_h -> h_lead_mgr,l_caevent_struct_i -> i_lead_mgr,strlen(p_caevent_struct_h -> h_lead_mgr),105);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","SYND_MEMBR",p_caevent_struct_h -> h_synd_membr,l_caevent_struct_i -> i_synd_membr,strlen(p_caevent_struct_h -> h_synd_membr),105);
	printf("Col |%s| Value |%s| Value Ind|%d| Len |%d| Max Len|%d|\n","CO_MGR",p_caevent_struct_h -> h_co_mgr,l_caevent_struct_i -> i_co_mgr,strlen(p_caevent_struct_h -> h_co_mgr),105);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","LWR_LIMIT",p_caevent_struct_h -> h_lwr_limit,l_caevent_struct_i -> i_lwr_limit);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","UPR_LIMIT",p_caevent_struct_h -> h_upr_limit,l_caevent_struct_i -> i_upr_limit);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FRACT_QTY_BAL",p_caevent_struct_h -> h_fract_qty_bal,l_caevent_struct_i -> i_fract_qty_bal);
	printf("Col |%s| Value |%lf| Value Ind|%d|\n","FRACT_QTY_RECD",p_caevent_struct_h -> h_fract_qty_recd,l_caevent_struct_i -> i_fract_qty_recd);

	IS_ANY_ORA_ERROR

RETURN_SUCCESS:

	APL_FREE(l_caevent_struct_i);

	APL_FUNCTION_RET_SUCCESS(APL_OUT_FILE)

RETURN_FAILURE:

	APL_FREE(l_caevent_struct_i);

	APL_FUNCTION_RET_FAILURE(APL_OUT_FILE)

}



