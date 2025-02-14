
/*-- Structures coming in the data from NSE --*/
/*-- There are two Sets of structures -
1. The binary record coming from NSE
2. The corresponding Ascii record with the Number fields( int, long, short, double) converted into their Ascii representations

The Ascii record types have the type name beginning with Asc
--*/

/*-- The sizes of the Binary records as they are in the NSE file
sizeof operator will return a different size. This is because the
C compiler on SGI/Pyramid does not have the switch to specify Byte Alignment.
So these sizes have to be hard coded.
--*/
/*-- Note on Modifications to Structures :
A change in any Binary structure will require the following to be done :
1. Change the size of the structure in the #define Macros that follow.
2. If the new field is a Number( double, long or short ) then
the field should be twiddled in the proper place in nsesplit.pc
3. A corresponding change in the Ascii record.
3. The field should be converted to Ascii in the conversion function
for that field.

WARNING :  To avoid Byte Alignment Problems the modification should
not disturb the clubbing of datatypes within the structures
i.e. all doubles should be at the beginning of the Structure,
followed by all longs, followed by all shorts and then chars.
If this is violated the splitting program will not work !!
--*/

/* Changed structure NoDelRec on 27/03/96 */
/* Changed avgprice from 17 to 18 on 12/06/96 by Giby  */
/*  Changed structure DelOrder and AscDelOrder on 02/04/98
/*****************************************************************************
Author     Modification                                      Date

Vinod      Structure NoDelRec split into NoDelRec_1 and      03/04/97
NoDelRec_2 so that NdsSetlNo which is a long,
appears as the first element of NoDelRec_2
/****************************************************************************/


#define	HDRSIZE		    100
#define	PARTRECSIZE 	  6
#define	PARTPARAMSIZE	 10
#define	SETLRECSIZE	     67
#define	OLDNODELRECSIZE	 33
#define	NODELRECSIZE1	 97
#define	NODELRECSIZE2	 56
#define	DELORDERSIZE	156
#define	OBLIGRECSIZE	121
#define	TRADEMODSIZE	 47
#define	DLYTRADESIZE	198
#define	ORDRECSIZE	    206
#define	ORDERRECSIZE	 96
#define SEIRECSIZE	     71
#define TRADEMEMSIZE     35
#define CUSTPARTSIZE     42

/* File Header */
typedef struct{
char sign[4] ;
char file_sent[1] ;
char gen_place[1] ;
char hp_creat_dt[3] ;		/* Date of creation */
char hp_creat_time[3] ;
char oth_creat_dt[3] ;
char oth_creat_time[3] ;
char expiry_dt[3] ;
char expiry_time[3] ;
char chk_sum[4] ;                /*-- File Size --*/
char filler1[12] ;
char cmclgVer[3];
char filler2[57] ;
} HdrRec ;


typedef struct {
char PartCode[5] ;
char PartType ;
} PartRec ;

// Added this structure - 13/09/2000 - Ravi
typedef struct {
char PartCode[6];
char PartType;
} AscPartRec;

typedef struct {
short ConfWindow ;
char    Date[8];      /* DDMMYYYY */
} PartParam ;

// Added this structure - 13/09/2000 - Ravi
typedef struct {
char    ConfWindow[6] ;
char    Date[9];      /* DDMMYYYY */
} AscPartParam ;

typedef struct {
long SetlNo ;
long SetlMergNo ;
char SetlStartDate[8] ;            /*-- All dates DDMMYYYY --*/
char SetlEndDate[8] ;
char SetlFundPayIn[8] ;
char SetlFundPayOut[8] ;
char SetlSecPayIn[8] ;
char SetlSecPayOut[8] ;
char SetlFinObgDate[8] ;            /*-- All dates DDMMYYYY --*/
char SetlType ;
char SetlActive ;
char SetlSplSetlFlag ;
} SetlRec ;

// Ravi - 10/09/2000 Increased all the character arrays by one for the null terminator.
typedef struct {
char SetlNo[8] ;
char SetlMergNo[8] ;
char SetlStartDate[9] ;            /*-- All dates DDMMYYYY --*/
char SetlEndDate[9] ;
char SetlFundPayIn[9] ;
char SetlFundPayOut[9] ;
char SetlSecPayIn[9] ;
char SetlSecPayOut[9] ;
char SetlFinObgDate[9] ;            /*-- All dates DDMMYYYY --*/
char SetlType ;
char SetlActive ;
char SetlSplSetlFlag ;
char nl ;
} AscSetlRec ;


typedef struct {
long    NdsSetlNo ;
char    NdSecSymbol[10] ;
char    NdSecSeries[2] ;
char    NdStartDate[8] ;
char    NdEndDate  [8] ;
char    NdSetlType ;
}  OldNoDelRec  ;

typedef struct {
char    NdSecSymbol[10] ;
char    NdSecSeries[2] ;
char    NdSecDesc[30] ;
char    NdSecCode[6] ;
char    NdRecordDt[8] ;
char    NdBCStartDt[8] ;
char    NdBCEndDt[8] ;
char    NdStartDate[8] ;
char    NdEndDate  [8] ;
char    NdExDt[8] ;
char    NdSetlType ;
} NoDelRec_1 ;

typedef struct {
long    NdsSetlNo ;
char    NdcorpDesc[40] ;
char    Ndisin[12] ;
}  NoDelRec_2  ;

// 12/09/2000 Increased width of all the arrays.
typedef struct {
char    NdSecSymbol[11] ;  //from 10 to 11
char    NdSecSeries[3] ;   //from 2 to 3
char    NdSecDesc[31] ;    //from 30 to 31
char    NdSecCode[7] ;     //from 6 to 7
char    NdRecordDt[9] ;    //from 8 to 9
char    NdBCStartDt[9] ;   //from 8 to 9
char    NdBCEndDt[9] ;     //from 8 to 9
char    NdStartDate[9] ;   //from 8 to 9
char    NdEndDate  [9] ;   //from 8 to 9
char    NdExDt[9] ;        //from 8 to 9
char    NdSetlType;
char    NdsSetlNo[8];      //from 7 to 8
char    NdcorpDesc[41] ;   //from 40 to 41
char    Ndisin[13] ;       //from 12 to 13
char    nl ;
}  AscNoDelRec  ;

typedef struct {
double   DelQty ;
double   DelDqty ; // Prefixed Del.
double   DelPqty ; // Prefixed Del /*CR 856*/
double   DelEqty ; // Prefixed Del /*CR 856*/
double   RecQty ;
double   DelVal ;
double   DelNoCert ;
long     DelSetlNo ;
long     DelUid  ;
long     DelNo  ;
long     DelRecNo  ;
short    DelTrdMbrBrnCode ;
short    RecTrdMbrBrnCode ;
char     DelDate[8] ;
char     DelSecSymbol[10] ;
char     DelSecSeries[2] ;
char     DelSecCode[6] ;
char     DelCusCode[5] ;
char     DelTMCode[5] ;
char     RecCusCode[5] ;
char     RecTMCode[5] ;
char     DelSetlType ;
char     DelType ;
char     Delisin[12] ;
char     DelCen[10] ;
char     DelRecCen[10] ;
char     Pqty[16];          //Inc. from 9 to 16
char     Eqty[16];          //Inc. from 9 to 16
}  DelOrder ;

// Increased the width of all the arrays.
typedef struct {
char     DelQty[16];           //Inc. from 9 to 16
char     DelDqty[16];          //Inc. from 9 to 16
char     DelPqty[16];          //Inc. from 9 to 16
char     DelEqty[16];          //Inc. from 9 to 16
char     RecQty[16];           //Inc. from 9 to 16
char     DelVal[22];           //Inc. from 9 to 22
char     DelNoCert[16];        //Inc. from 9 to 16
char     DelSetlNo[8];         //Inc. from 7 to 8
char     DelUid[7];            //Inc. from 6 to 7
char     DelNo[7];             //Inc. from 6 to 7
char     DelRecNo[7];          //Inc. from 6 to 7
char     DelTrdMbrBrnCode[3];  //Inc. from 2 to 3
char     RecTrdMbrBrnCode[3];  //Inc. from 2 to 3
char     DelDate[9];           //Inc. from 8 to 9
char     DelSecSymbol[11];     //Inc. from 10 to 11
char     DelSecSeries[3];      //Inc. from 2 to 3
char     DelSecCode[7];        //Inc. from 6 to 7
char     DelCusCode[6];        //Inc. from 5 to 6
char     DelTMCode[6];         //Inc. from 5 to 6
char     RecCusCode[6];        //Inc. from 5 to 6
char     RecTMCode[6];         //Inc. from 5 to 6
char     DelSetlType;          //Inc. from 9 to 16
char     DelType;              //Inc. from 9 to 16
char     Delisin[13];          //Inc. from 12 to 13
char     DelCen[11];           //Inc. from 10 to 11
char     DelRecCen[11];        //Inc. from 10 to 11
char     nl;
char     Pqty[16];          //Inc. from 9 to 16
char     Eqty[16];          //Inc. from 9 to 16
}  AscDelOrder;

typedef struct {
double  ObgDayBuyVol         ;
double  ObgDaySalVol         ;
double     ObgDayBuyAmt    ;
double     ObgDaySalAmt    ;
double     ObgCumBuyVol    ;
double     ObgCumSalVol    ;
double     ObgCumBuyAmt    ;
double     ObgCumSalAmt    ;
long    ObgSetlNo    ;
short    ObgTMBrnCode    ;
char    ObgDate			[8];
char    ObgCupCode		[12];				/** ?? **/
char    ObgSecSymbol	[10];
char    ObgSecSeries	[2];
char    ObgSecCode		[6];
char    ObgTMCode		[5];
char    ObgCusCode		[5];				/** ?? **/
char    ObgSetlType;
char    ObgNDFlag;
char    ObgFnlObg;					/** ?? **/
/*	    char     Obgisin[12] ;              16-dec-96	*/
}  Obligation ;

// Ravi 11/09/2000 changed the sizes of all the arrays
typedef struct {
char    ObgDayBuyVol[16];  //increased from 9 to 16
char    ObgDaySalVol[16];  //increased from 9 to 16
char    ObgDayBuyAmt[22]; //increased from 16 to 22
char    ObgDaySalAmt[22]; //increased from 16 to 22
char    ObgCumBuyVol[16];  //increased from 9 to 16
char    ObgCumSalVol[16];  //increased from 9 to 16
char    ObgCumBuyAmt[22]; //increased from 16 to 22
char    ObgCumSalAmt[22]; //increased from 16 to 22
char    ObgSetlNo[8];     //increased from 7 to 8
char    ObgTMBrnCode[3];  //increased from 2 to 3
char    ObgDate		[9];  //increased from 8 to 9
char    ObgCupCode	[13]; //increased from 12 to 13			/** ?? **/
char    ObgSecSymbol[11]; //increased from 10 to 11
char    ObgSecSeries[3];  //increased from 2 to 3
char    ObgSecCode	[7];  //increased from 6 to 7
char    ObgTMCode	[6];  //increased from 5 to 6
char    ObgCusCode	[6];  //increased from 5 to 6				/** ?? **/
char    ObgSetlType;
char    ObgNDFlag;
char    ObgFnlObg;					/** ?? **/
/*	    char     Obgisin[12] ;	16-dec-96*/
char    nl;
}  AscObligation ;


typedef struct {
double    TradeNo ;
short     TradeActType ;
char 	  TrdCupCd[12] ;
char 	  TrdOCupCd[12] ;
char 	  TrdCusCd[5] ;
char 	  TrdOCusCd[5] ;
char 	  TrdBuySellFlag ;
char 	  TrdCnfFlag ;
char 	  TrdMktType ;
}  TradeModify ;

typedef struct {
char    TradeNo[13] ;
char     TradeActType[2] ;
char 	  TrdCupCd[12] ;
char 	  TrdOCupCd[12] ;
char 	  TrdCusCd[5] ;
char 	  TrdOCusCd[5] ;
char 	  TrdBuySellFlag ;
char 	  TrdCnfFlag ;
char 	  TrdMktType ;
char 	  nl ;
}  AscTradeModify ;


typedef struct {
double TradeNo ;
double TradePrice ;
double TradeQty ;
double TradeBuyOrdNo ;
double TradeSalOrdNo ;
long   TradeAuctionNo ;
short  TradeActType ;
short  BuyTrdMemBrnCode ;
short  SalTrdMemBrnCode ;
char    TradeDate[8] ;
char    TradeTime[6] ;
char    TradeSecSymbol[10] ;
char    TradeSecSeries[2] ;
char    TradeSecCode[6] ;
char     Tradeisin[12] ;
char    TradeSecType[2] ;
char    TradeBuyCP[12] ;
char    TradeSalCP[12] ;
char    TradeOBuyCP[12] ;
char    TradeOSalCP[12] ;
char    TradeBuyAcc[10] ;
char    TradeSalAcc[10] ;
char    TradeIsincd[12] ;
char    TradeBuyTMCode[5] ;
char    TradeSalTMCode[5] ;
char    TradeSoCusCd[5] ;			/** ?? **/
char    TradeBoCusCd[5] ;			/** ?? **/
char    TradeBuyCus[5] ;			/** ?? **/
char    TradeSalCus[5] ;			/** ?? **/
char 	TradeMktType;
char 	TradeNDFlag ;
char	TradeBcnflag;
char	TradeScnflag;
}  DailyTrade ;


typedef struct {
char TradeNo[13];
char TradePrice[10];
char TradeQty[9] ;
char TradeBuyOrdNo[13] ;
char TradeSalOrdNo[13] ;
char   TradeAuctionNo[6] ;
char  TradeActType[2] ;
char  BuyTrdMemBrnCode[2] ;
char  SalTrdMemBrnCode[2] ;
char    TradeDate[8] ;
char    TradeTime[6] ;
char    TradeSecSymbol[10] ;
char    TradeSecSeries[2] ;
char    TradeSecCode[6] ;
char     Tradeisin[12] ;
char    TradeSecType[2] ;
char    TradeBuyCP[12] ;
char    TradeSalCP[12] ;
char    TradeOBuyCP[12] ;
char    TradeOSalCP[12] ;
char    TradeBuyAcc[10] ;
char    TradeSalAcc[10] ;
char    TradeIsincd[12] ;
char    TradeBuyTMCode[5] ;
char    TradeSalTMCode[5] ;
char    TradeSoCusCd[5] ;			/** ?? **/
char    TradeBoCusCd[5] ;			/** ?? **/
char    TradeBuyCus[5] ;			/** ?? **/
char    TradeSalCus[5] ;			/** ?? **/
char 	TradeMktType;
char 	TradeNDFlag ;
char	TradeBcnflag;
char	TradeScnflag;
char	nl;
}  AscDailyTrade ;


typedef struct {
double DblDummy[11] ;
long    LongDummy;
short    ShortDummy[6] ;
char    Dummy[102] ;
}  OrdRec ;


typedef struct {
char	MemberCode[5];
char	MemberName[30];
} TradingMember ;

// Added on 11/09/2000 - Ravi
typedef struct {
char	MemberCode[6];
char	MemberName[31];
} AscTradingMember ;


typedef struct {
char	PartCode[12];
char	PartName[30];
} CustPart ;

// Added on 11/09/2000 - Ravi
typedef struct {
char	PartCode[13];
char	PartName[31];
} AscCustPart ;

typedef struct {
double   SeiOpenPrice ;
double   SeiHighPrice ;
double   SeiLowPrice ;
double   SeiClosePrice ;
char     SeiSecSymbol[10] ;
char     SeiSecSeries[2] ;
char     SeiSecCode[6] ;
char     SeiDate[8] ;
char     SeiMktType ;
char     Seiisin[12] ;
}  SeiRec ;

//Increased the width of all the arrays.
typedef struct {
char     SeiOpenPrice[22]; //Inc from 10 to 22
char     SeiHighPrice[22]; //Inc from 10 to 22
char     SeiLowPrice[22];  //Inc from 10 to 22
char     SeiClosePrice[22];//Inc from 10 to 22
char     SeiSecSymbol[11]; //Inc from 10 to 11
char     SeiSecSeries[3];  //Inc from  2 to  3
char     SeiSecCode[7];    //Inc from  6 to  7
char     SeiDate[9];       //Inc from  8 to  9
char     SeiMktType;
char     Seiisin[13];      //Inc from 12 to 13
char     nl ;
}  AscSeiRec ;

typedef struct {
double	OrderNo;
double	OrderQty;
double	OrderValue;
double	AvgPrice;
char	MktType;
char	OrderDate[8];
char	BuySellFlag;
char	SecSymbol[10];
char	SecSeries[2];
char	SecCode[6];
char	TrdMemCode[5];
char	CustPart[12];
char	CustCode[5];
char	NoDelFlag;
char    setlmode ;
char     isin[12] ;
} OrderRec;

typedef struct {
char	OrderNo[16];        // increased the array size from 13 to 16 - 09/09/2000 Ravi
char	OrderQty[17];       // increased the array size from 13 to 16 - 09/09/2000 Ravi
char	OrderValue[22];     // increased the array size from 13 to 16 - 09/09/2000 Ravi
char	AvgPrice[22];       // increased the array size from 13 to 16 - 09/09/2000 Ravi
char	MktType;
char	OrderDate[9];
char	BuySellFlag;
char	SecSymbol[11];
char	SecSeries[3];
char	SecCode[7];
char	TrdMemCode[6];
char	CustPart[13];
char	CustCode[6];
char	NoDelFlag;
char    setlmode ;
char     isin[13] ;
char	nl;
} AscOrderRec;

/*-- The other Order structure

typedef struct {
double	OrderNo;
char	MktType;
char	OrderDate[8];
char	BuySellFlag;
char	SecSymbol[10];
char	SecSeries[2];
char	SecCode[6];
double	OrderQty;
double	OrderValue;
double	AvgPrice;
char	TrdMemCode[5];
char	CustPart[12];
char	CustCode[5];
char	NoDelFlag;
} OrderRec;

typedef struct {
char	OrderNo[13];
char	MktType;
char	OrderDate[8];
char	BuySellFlag;
char	SecSymbol[10];
char	SecSeries[2];
char	SecCode[6];
char	OrderQty[9];
char	OrderValue[16];
char	AvgPrice[18];
char	TrdMemCode[5];
char	CustPart[12];
char	CustCode[5];
char	NoDelFlag;
char	nl;
} AscOrderRec;

*/

