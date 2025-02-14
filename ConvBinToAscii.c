#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
//#include "/usr/local/include/libol/io.h"
#include <sys/stat.h>
#include "ConvSplit.h"
#include <string.h>
//#include <curses.h>

FILE  *Inpfp, *Orderfp, *Obgfp, *Setlfp, *NoDelfp, *Delfp, *Cpfp, *Brkfp, *Seifp, *Outfp, *OrdOutfp ;
char  InputFile[100]="";
char InputDate[12]="", uid[4]="", delv_type[2]="", exch_code[4]="";
char  ErrFile[100]="";
char  OrdFile[100]="", ObgFile[100]="", SetlFile[100]="", SeiFile[100]="",NoDelFile[100]="", DelFile[100]="", BrkFile[100]="", CpFile[100] ="";
char  RecType, OpnType ;
int   TrdCnt = 0, TrdModCnt = 0, ObgCnt = 0, SetlCnt = 0, SeiCnt = 0, NoDelCnt = 0, DelCnt = 0, OrdCnt = 0, BrkCnt = 0, CpCnt = 0, OrderCnt = 0 ;
int   InpFp1;
long  Fsize, Fsize2 ;

FILE *FileOpen(char *,char *) ;
void CopyArgs(int, char *[]);
void OpenFiles();
void ReadFile();
void ReadHeader();
int  GetRecType();
long GetInputFileSize();
long GetFileSize( char * );
void CheckPartRec();
void CheckSysParam();
void GetSetlRec();
void GetNoDelSetl();
void CheckSysParam();
void GetObligationRec();
void GetDeliveryRec();
void GetTradingMember();
void GetCustPart();
void GetOrdRec();
void System();
void CloseFiles();

void ConvSetl(SetlRec *,AscSetlRec *);
void ConvNoDel1(NoDelRec_1 *,AscNoDelRec *);
void ConvNoDel2(NoDelRec_2 *,AscNoDelRec *);

void ConvObg(Obligation *,AscObligation *);

void ConvDel(DelOrder *,AscDelOrder *);
void ConvOrder(OrderRec *,AscOrderRec *);

void GetSeiRec();
void ConvSei();

void Pause();
/*void strcpy(char *,char *);*/
int  ReadRecord( void *, long, long, char * );
void NumFormat(char, void *, int, int , char *);
void ltrim(char *);

int main(argc, argv)
int argc; char *argv[] ;
{
	CopyArgs(argc, argv);
	OpenFiles();
	ReadFile();
	CloseFiles();
}

void CopyArgs(argc, argv)
int argc; char *argv[] ;
{
	if ( argc != 6 ) {
		printf( "Usage : %s <File Name> <Input Date - DDMMYY > <UID> <Delv Type> <Exch Cd>\n",		argv[0] );
		exit(0);
	}

	sprintf( InputFile, "%s", argv[1] );
	strcpy( InputDate, argv[2] );
	strcpy( uid, argv[3] );
	strcpy( delv_type, argv[4]);
	strcpy( exch_code, argv[5]);

//	sprintf( InputFile, "%s/%s/%s", getenv( "HOME" ), exch_code, argv[1] );
	sprintf( ErrFile, "%s%s.REP", exch_code, InputDate );
	sprintf( OrdFile, "%s%s.ORD", exch_code, InputDate );
	sprintf( ObgFile, "%s%s.OBG", exch_code, InputDate );
	sprintf( SetlFile, "%s%s.SETL", exch_code, InputDate );
	sprintf( NoDelFile, "%s%s.NODEL", exch_code, InputDate );
	sprintf( DelFile, "%s%s.DEL", exch_code, InputDate );
	sprintf( BrkFile, "%s%s.BRK", exch_code, InputDate );
	sprintf( CpFile, "%s%s.CPA", exch_code, InputDate );
	sprintf( SeiFile, "%s%s.SEI", exch_code, InputDate );
	//printf("%s\n",SetlFile);Pause();
}

void CloseFiles()
{
	fclose(Inpfp );
	fclose(Orderfp );
	fclose(Obgfp );
	fclose(Setlfp );
	fclose(NoDelfp );
	fclose(Delfp );
	fclose(Brkfp );
	fclose(Cpfp  );
	fclose(Seifp  );
	fclose(Outfp);
	fclose(OrdOutfp);
}

FILE *FileOpen(file, mode)
char *file, *mode;
{
	FILE *fp ;
	char tmpFile[100]="";

	//sprintf( tmpFile, "%s/%s/%s", getenv( "HOME" ), exch_code, file );
	sprintf( tmpFile, "%s/%s", exch_code, file );
	fp = fopen( tmpFile, mode );
	if ( fp == NULL ) {
		fprintf( stderr, "Error opening File : %s\n", tmpFile );
		fflush( stderr );
		perror("");
		exit(0);
	}

	return fp ;
}

void OpenFiles()
{
	printf("\n Inside OpenFiles:InputFile :|%s|\n",InputFile);
	//Inpfp1 = open( InputFile, O_RDONLY );
	Inpfp = FileOpen( InputFile, "rb" );
	Orderfp = FileOpen( OrdFile, "w" ) ;
	Obgfp = FileOpen( ObgFile, "w" ) ;
	Setlfp = FileOpen( SetlFile, "w" ) ;
	NoDelfp = FileOpen( NoDelFile, "w" ) ;
	Delfp = FileOpen( DelFile, "w" ) ;
	Brkfp = FileOpen( BrkFile, "w" );
	Cpfp  = FileOpen( CpFile, "w" );
	Seifp = FileOpen( SeiFile, "w" );
	Outfp = FileOpen( ErrFile, "w" );
	OrdOutfp = FileOpen( OrdFile, "w" ) ;
}

void ReadFile()
{
	int count;
	OldNoDelRec	OldNdel ;

	ReadHeader();
	count = 0 ;

	while( GetRecType() ) {
		//fprintf(Outfp,"\nRecType : %c   Opn Type : %c \n",RecType,OpnType) ;
		printf("\nRecType : %c   Opn Type : %c \n",RecType,OpnType) ;
		switch( RecType ) {
			case 'Z' :
				CheckPartRec();
				break ;
			case 'A' :
				CheckSysParam();
				break ;
			case 'B' :
				GetSetlRec();
				break ;
			case 'S' :
				GetNoDelSetl();
				break ;
			case 'C' :
				printf("Ignoring Record type 'C'\n") ;
				if ( fread( &OldNdel, OLDNODELRECSIZE, 1, Inpfp ) != 1 ) {
					fprintf( stderr, " Error reading old No Delivery Record\n" );
					perror("");
					exit(0) ;
				}
				break ;
			case 'F' :
				GetObligationRec();
				break ;
			case 'E' :
				GetDeliveryRec();
				break ;
			case 'T' :
				GetTradingMember();
				break ;
			case 'U' :
				GetCustPart();
				break ;
			case 'W' :
				GetOrdRec();
				break ;
			case 'Q' :
				GetSeiRec();
				break;
			default :
				fprintf(stderr,"Invalid Record Type found : %c %d at : %ld Octal %o\n",
				RecType, (int)RecType, ftell(Inpfp), ftell(Inpfp) );
				fprintf(Outfp,"Invalid Record Type found : %c %d at : %ld Octal %o\n",
				RecType, (int)RecType, ftell(Inpfp), ftell(Inpfp) );
				//if ( getchar() == 'q' )  return ;
				break ;
		}

		count++ ;

		if ( count % 50 == 0 )
			fprintf( stderr, " Record No : %d\n", count );

	}
}

void ReadHeader()
{
	HdrRec Hdr ;
	char *p="", *sum="", CreateDate[12]="";

	/*	if ( fread( &Hdr, sizeof( Hdr ), 1, Inpfp ) == 0 ) {	*/
	//if ( read( Inpfp1, &Hdr, HDRSIZE ) <= 0 ) {
	if ( fread( &Hdr, HDRSIZE, 1, Inpfp ) == 0 ) {
		fprintf( stderr, "Error reading from file : %s\n", InputFile );
		fflush( stderr );
		perror("");
		CloseFiles();
		exit(0);
	}

	Fsize = GetInputFileSize();

	sum = Hdr.chk_sum;

	printf("Sign          : %s \n",Hdr.sign);
	printf("File Sent     : %d \n",(int)Hdr.file_sent[0]);
	printf("Gen Place     : %d \n",(int)Hdr.gen_place[0]);
	printf("Create Dt     : %02d/%02d/%02d \n",(int)Hdr.hp_creat_dt[0],(int)Hdr.hp_creat_dt[1],(int)Hdr.hp_creat_dt[2]);		/* Date of creation */
	printf("Create Tm     : %02d:%02d:%02d \n",(int)Hdr.hp_creat_time[0],(int)Hdr.hp_creat_time[1],(int)Hdr.hp_creat_time[2]);
	printf("Oth Create Dt : %02d/%02d/%02d \n",(int)Hdr.oth_creat_dt[0],(int)Hdr.oth_creat_dt[1],(int)Hdr.oth_creat_dt[2]);
	printf("Oth Create Tm : %02d:%02d:%02d \n",(int)Hdr.oth_creat_time[0],(int)Hdr.oth_creat_time[1],(int)Hdr.oth_creat_time[2]);
	printf("Expiry Date   : %02d/%02d/%02d \n",(int)Hdr.expiry_dt[0],(int)Hdr.expiry_dt[1],(int)Hdr.expiry_dt[2]);
	printf("Expiry Time   : %02d:%02d:%02d \n",(int)Hdr.expiry_time[0],(int)Hdr.expiry_time[1],(int)Hdr.expiry_time[2]);
	printf("Check Sum     : %02d%02d%02d%02d \n",(int)Hdr.chk_sum[0],(int)Hdr.chk_sum[1],(int)Hdr.chk_sum[2],(int)Hdr.chk_sum[3]);
	printf("Filler1       : %12s \n",Hdr.filler1);
	printf("Filler2       : %3s \n",Hdr.cmclgVer);
	printf("Filler3       : %57s \n",Hdr.filler2);

	/*********/
	fprintf(Outfp,"Header Data \n");
	fprintf(Outfp,"Sign          : %s \n",Hdr.sign);
	fprintf(Outfp,"File Sent     : %d \n",(int)Hdr.file_sent[0]);
	fprintf(Outfp,"Gen Place     : %d \n",(int)Hdr.gen_place[0]);
	fprintf(Outfp,"Create Dt     : %02d/%02d/%02d \n",(int)Hdr.hp_creat_dt[0],(int)Hdr.hp_creat_dt[1],(int)Hdr.hp_creat_dt[2]);		/* Date of creation */
	fprintf(Outfp,"Create Tm     : %02d:%02d:%02d \n",(int)Hdr.hp_creat_time[0],(int)Hdr.hp_creat_time[1],(int)Hdr.hp_creat_time[2]);
	fprintf(Outfp,"Oth Create Dt : %02d/%02d/%02d \n",(int)Hdr.oth_creat_dt[0],(int)Hdr.oth_creat_dt[1],(int)Hdr.oth_creat_dt[2]);
	fprintf(Outfp,"Oth Create Tm : %02d:%02d:%02d \n",(int)Hdr.oth_creat_time[0],(int)Hdr.oth_creat_time[1],(int)Hdr.oth_creat_time[2]);
	fprintf(Outfp,"Expiry Date   : %02d/%02d/%02d \n",(int)Hdr.expiry_dt[0],(int)Hdr.expiry_dt[1],(int)Hdr.expiry_dt[2]);
	fprintf(Outfp,"Expiry Time   : %02d:%02d:%02d \n",(int)Hdr.expiry_time[0],(int)Hdr.expiry_time[1],(int)Hdr.expiry_time[2]);
	fprintf(Outfp,"Check Sum     : %02d%02d%02d%02d \n",(int)Hdr.chk_sum[0],(int)Hdr.chk_sum[1],(int)Hdr.chk_sum[2],(int)Hdr.chk_sum[3]);
	fprintf(Outfp,"Filler1       : %12s \n",Hdr.filler1);
	fprintf(Outfp,"Filler2       : %3s \n",Hdr.cmclgVer);
	fprintf(Outfp,"Filler3       : %57s \n",Hdr.filler2);

	/*********/
	sum = Hdr.chk_sum ;
	Fsize2 = (1000000L * sum[0]) + (10000L * sum[1]) + (100L *sum[2]) + sum[3] ;
	printf("Size : %ld  Read Size : %ld\n", Fsize, Fsize2 );
	if ( Fsize != Fsize2 ) {
		fprintf( stderr, "Error in file size in Header record\n" );
		fprintf( stderr, "Actual Size : %ld  Size in Header : %ld\n",
		Fsize, Fsize2 );
		CloseFiles();
		exit(0);
	}

	p = Hdr.sign ;
	if ( p[0] != '' || p[1] != '' || p[2] != '' || p[3] != '' ) {
		fprintf( stderr, "Error in Sign in Header record\n" );
		CloseFiles();
		exit(0);
	}

	/*-- hp_creat_dt is in DD-MM-YY format as INTEGERS --*/
	sprintf( CreateDate, "%02d%02d%02d", (int)Hdr.hp_creat_dt[0],
	(int)Hdr.hp_creat_dt[1],  (int)Hdr.hp_creat_dt[2] );
	fprintf( stderr, "Date was : %s\n", CreateDate );
	//CheckLog(CreateDate);
}

int GetRecType()
{
   if ( ftell(Inpfp) == 1892L ) {
      fprintf(Outfp,"Cur Pos: %ld\n",ftell(Inpfp));
      //fseek(Inpfp,1893L,SEEK_SET);
      //fprintf(Outfp,"Cur Pos: %ld\n",ftell(Inpfp));
   }


   //if( (RecType = getc(Inpfp)) == EOF ) {
   //if( !ReadRecord((char *)&RecType, 1, ftell(Inpfp), "End Of File occured ,reading RecType  .......") ) {
     // return 0;
   if ( fread( (char *)&RecType, 1, 1, Inpfp ) == 0 ) {
      perror("End Of File occurred ,reading RecType .......");
      return 0;
   }

   fprintf(Outfp,"\nRecType : %c Cur Pos: %ld ",RecType,ftell(Inpfp));

   if ( fread( (char *)&OpnType, 1, 1, Inpfp ) == 0 ) {
      perror("End Of File occurred ,reading Opn Type .......");
      return 0;
   }
   //if( !ReadRecord((char *)&OpnType, 1, ftell(Inpfp), "End Of File occured ,reading OpnType  .......") ) {
   //   return 0;
   //}

   fprintf(Outfp," OpnType : %c Cur Pos: %ld\n",OpnType,ftell(Inpfp));

   return 1;
}

long GetInputFileSize(){
   char TmpFile[100]="";

   //sprintf( TmpFile, "%s/%s/%s", getenv( "HOME" ),exch_code,InputFile );
   sprintf( TmpFile, "%s/%s", exch_code,InputFile );
   return( GetFileSize(TmpFile) );
}

long GetFileSize( s )
char *s;
{
	struct stat buf ;

	stat( s, &buf );
	return buf.st_size ;
}

/*-- A participant Details Record --*/
void CheckPartRec()
{
	PartRec	Prec ;

	/*	if ( fread( &Prec, sizeof( PartRec ), 1, Inpfp ) != 1 ) {	*/
	if ( fread( &Prec, PARTRECSIZE, 1, Inpfp ) != 1 ) {
		fprintf( stderr, " Error reading Participant Record\n" );
		perror("");
		CloseFiles();
		exit(0) ;
	}

	fprintf(Outfp,"Prec.PartCode : %.5s  Prec.PartType : %c \n",Prec.PartCode,Prec.PartType);
	printf("Prec.PartCode : %.5s  Prec.PartType : %c \n",Prec.PartCode,Prec.PartType);
}

/*-- A System Parameters Record --*/
void CheckSysParam()
{
	PartParam Prec ;

	/*	if ( fread( &Prec, sizeof( PartParam ), 1, Inpfp ) != 1 ) {	*/
	if ( fread( &Prec, PARTPARAMSIZE, 1, Inpfp ) != 1 ) {
		fprintf( stderr, " Error reading Participant Parameters Record\n" );
		perror("");
		CloseFiles();
		exit(0) ;
	}

	fprintf(Outfp,"Conf Window : %d Current Date : %.8s\n", (short)Prec.ConfWindow,Prec.Date );

	//fprintf(Outfp,"Conf Window : %d Current Date : %02d/%02d/%2d%2d\n", (short)Prec.ConfWindow,Prec.Date );
}

void GetSetlRec()
{
	#define MAX_REC_STRUCT 16
	#define ASCSETLRECSIZE 74  //Size of the Order Record in the output file
	#define SETLRECDELIM 12     //No of delimiters printed in the Order Recor
	SetlRec	Srec ;
	AscSetlRec	ASrec ;

	char SetlArr[ASCSETLRECSIZE+SETLRECDELIM]="";


	if( !ReadRecord( (SetlRec *)&Srec,(long)SETLRECSIZE,ftell(Inpfp),"Error Reading Order Record \n" )) {
	   return;
	}

	ConvSetl( &Srec, &ASrec ) ;

	sprintf(SetlArr,"%7.7s|%7.7s|%8.8s|%8.8s|%8.8s|%8.8s|%8.8s|%8.8s|%8.8s|%c|%c|%c|",
		      ASrec.SetlNo,ASrec.SetlMergNo,ASrec.SetlStartDate,ASrec.SetlEndDate,ASrec.SetlFundPayIn,
		      ASrec.SetlFundPayOut,ASrec.SetlSecPayIn,ASrec.SetlSecPayOut,ASrec.SetlFinObgDate,ASrec.SetlType,
		      ASrec.SetlActive,ASrec.SetlSplSetlFlag);
	SetlArr[ASCSETLRECSIZE+SETLRECDELIM] = '\0';

	fprintf(Setlfp,"%-s\n",SetlArr);
	fprintf(Outfp,"Setl No: %7.7s   MergNo: %7.7s  Start Dt: %8.8s    EndDate: %8.8s FPayin: %8.8s \n",
				   ASrec.SetlNo,ASrec.SetlMergNo,ASrec.SetlStartDate,ASrec.SetlEndDate,ASrec.SetlFundPayIn);

	fprintf(Outfp,"FPayout: %8.8s SPayIn: %8.8s SPayOut: %8.8s FinObgDate: %8.8s   Type: %c \n",
				   ASrec.SetlFundPayOut,ASrec.SetlSecPayIn,ASrec.SetlSecPayOut,ASrec.SetlFinObgDate,ASrec.SetlType);

	fprintf(Outfp," Active: %c  SplFlag: %c \n",ASrec.SetlActive,ASrec.SetlSplSetlFlag);
/***/




    /*********
	putc( OpnType, Setlfp );

	if ( fwrite( &ASrec, sizeof( ASrec ), 1, Setlfp ) != 1 ) {
		fprintf( stderr, " Error writing Settlement Record\n" );
		perror("");
		CloseFiles();
		exit(0) ;
	}
    *********/

}

void ConvSetl( Bin, Asc )
SetlRec *Bin;
AscSetlRec *Asc;
{
    //sprintf( Asc->SetlNo, "%7ld", Bin->SetlNo );
    //sprintf( Asc->SetlMergNo, "%7ld", Bin->SetlMergNo );
    NumFormat('L',&Bin->SetlNo,7,0,Asc->SetlNo);
    NumFormat('L',&Bin->SetlMergNo,7,0,Asc->SetlMergNo);
    if(Asc->SetlMergNo[0] == '\0') {
       strncpy(Asc->SetlMergNo," ",6);
       Asc->SetlMergNo[6] = 0;
       Asc->SetlMergNo[7] = '\0';
    }
    memcpy(Asc->SetlStartDate,Bin->SetlStartDate,8);Asc->SetlStartDate[8] = '\0';
    memcpy(Asc->SetlEndDate,Bin->SetlEndDate,8);Asc->SetlEndDate[8] = '\0';
    memcpy(Asc->SetlFundPayIn,Bin->SetlFundPayIn,8);Asc->SetlFundPayIn[8] = '\0';
    memcpy(Asc->SetlFundPayOut,Bin->SetlFundPayOut,8);Asc->SetlFundPayOut[8] = '\0';
    memcpy(Asc->SetlSecPayIn,Bin->SetlSecPayIn,8);Asc->SetlSecPayIn[8] = '\0';
    memcpy(Asc->SetlSecPayOut,Bin->SetlSecPayOut,8);Asc->SetlSecPayOut[8] = '\0';
    memcpy(Asc->SetlFinObgDate,Bin->SetlFinObgDate,8);Asc->SetlFinObgDate[8] = '\0';
    Asc->SetlType = Bin->SetlType;
    Asc->SetlActive = Bin->SetlActive;
    Asc->SetlSplSetlFlag = Bin->SetlSplSetlFlag;
    if ( Asc->SetlSplSetlFlag == '\0' )
       Asc->SetlSplSetlFlag = ' ' ;
    Asc->nl = '\n' ;


    //memcpy( Asc->SetlStartDate, Bin->SetlStartDate,
    //	sizeof( SetlRec ) - ((char *)(Bin->SetlStartDate) - (char *)Bin ) );
}


void GetNoDelSetl()
{
NoDelRec_1	Ndel1 ;
NoDelRec_2	Ndel2 ;
AscNoDelRec	ANdel ;

NoDelCnt++ ;
/*	if ( fread( &Ndel, sizeof( NoDelRec ), 1, Inpfp ) != 1 ) {	*/
if ( fread( &Ndel1, NODELRECSIZE1, 1, Inpfp ) != 1 ) {
fprintf( stderr, " Error reading 1st part of No Delivery Record\n" );
perror("");
exit(0) ;
}

if ( fread( &Ndel2, NODELRECSIZE2, 1, Inpfp ) != 1 ) {
fprintf( stderr, " Error reading 2nd part of No Delivery Record\n" );
perror("");
exit(0) ;
}

ConvNoDel1 ( &Ndel1, &ANdel );
ConvNoDel2 ( &Ndel2, &ANdel );
putc( OpnType, NoDelfp ) ;
if ( fwrite( &ANdel, sizeof( ANdel ), 1, NoDelfp ) != 1 ) {
fprintf( stderr, " Error writing No Delivery Record\n" );
perror("");
exit(0) ;
}
}

void ConvNoDel1( Bin, Asc )
NoDelRec_1	*Bin ;
AscNoDelRec	*Asc ;
{
memcpy( Asc->NdSecSymbol, Bin->NdSecSymbol, 97 );
}

void ConvNoDel2( Bin, Asc )
NoDelRec_2	*Bin ;
AscNoDelRec	*Asc ;
{
sprintf( Asc->NdsSetlNo, "%7ld", Bin->NdsSetlNo );
memcpy( Asc->NdcorpDesc, Bin->NdcorpDesc, 52) ;
/* sizeof( NoDelRec ) - ((char *)(Bin->NdcorpDesc) - (char *)Bin) ); */
Asc->nl = '\n' ;
}

void GetObligationRec()
{
   #define MAXOBGRECSIZE 205
   #define OBGRECDELIM   20
   Obligation	Obg ;
   AscObligation  AObg ;
   char ObgArr[MAXOBGRECSIZE + OBGRECDELIM]="";

   ObgCnt++ ;

   if( !ReadRecord( (Obligation *)&Obg,(long)OBLIGRECSIZE,ftell(Inpfp),"Error Reading Order Record \n" )) {
      return;
   }

   ConvObg( &Obg, &AObg );

   sprintf(ObgArr,"%15.15s|%15.15s|%21.21s|%21.21s|%15.15s|%15.15s|%21.21s|%21.21s|%7.7s|%-2.2s|%8.8s|%12.12s|%10.10s|%-2.2s|%6.6s|%5.5s|%5.5s|%c|%c|%c|",
		 AObg.ObgDayBuyVol,AObg.ObgDaySalVol,AObg.ObgDayBuyAmt,AObg.ObgDaySalAmt,
		 AObg.ObgCumBuyVol,AObg.ObgCumSalVol,AObg.ObgCumBuyAmt,AObg.ObgCumSalAmt,
		 AObg.ObgSetlNo,AObg.ObgTMBrnCode,AObg.ObgDate,AObg.ObgCupCode,
		 AObg.ObgSecSymbol,AObg.ObgSecSeries,AObg.ObgSecCode,AObg.ObgTMCode,
		 AObg.ObgCusCode,AObg.ObgSetlType,AObg.ObgNDFlag,AObg.ObgFnlObg);

   fprintf(Obgfp,"%-s\n",ObgArr);

   fprintf(Outfp,"DayBuyVol: %lf  DaySaleVol: %lf  DayBuyAmt: %lf  DaySaleAmt: %lf \n",
		 Obg.ObgDayBuyVol,Obg.ObgDaySalVol,Obg.ObgDayBuyAmt,Obg.ObgDaySalAmt);

   fprintf(Outfp,"CumBuyVol: %lf  CumSaleVol: %lf  CumBuyAmt: %lf  CumSaleAmt: %lf \n",
		 Obg.ObgCumBuyVol,Obg.ObgCumSalVol,Obg.ObgCumBuyAmt,Obg.ObgCumSalAmt);

   fprintf(Outfp,"SetlNo: %ld  TMBrnCode: %d  Date: %.8s  ObgCupCode: %.12s \n",
		 Obg.ObgSetlNo,Obg.ObgTMBrnCode,Obg.ObgDate,Obg.ObgCupCode);

   fprintf(Outfp,"SecSymbol: %.10s  SecSeries: %.2s  SecCode: %.6s  TMCode: %.5s \n",
		 Obg.ObgSecSymbol,Obg.ObgSecSeries,Obg.ObgSecCode,Obg.ObgTMCode);

   fprintf(Outfp,"CusCode: %.5s  SetlType: %c  NDFlag: %c  FnlObg: %c \n",
		 Obg.ObgCusCode,Obg.ObgSetlType,Obg.ObgNDFlag,Obg.ObgFnlObg);

 /***
   putc( OpnType, Obgfp );
   if ( fwrite( &AObg,  sizeof( AObg ), 1, Obgfp ) != 1 ) {
      fprintf( stderr, " Error writing Obligation Record\n" );
      perror("");
      exit(0) ;
   }
  ***/
}

void ConvObg( Bin, Asc )
Obligation *Bin;
AscObligation *Asc;
{
   NumFormat( 'D',&Bin->ObgDayBuyVol,15,0,Asc->ObgDayBuyVol );
   NumFormat( 'D',&Bin->ObgDaySalVol,15,0,Asc->ObgDaySalVol );
   NumFormat( 'D',&Bin->ObgDayBuyAmt,14,6,Asc->ObgDayBuyAmt );
   NumFormat( 'D',&Bin->ObgDaySalAmt,14,6,Asc->ObgDaySalAmt );
   NumFormat( 'D',&Bin->ObgCumBuyVol,14,6,Asc->ObgCumBuyVol );
   NumFormat( 'D',&Bin->ObgCumSalVol,14,6,Asc->ObgCumSalVol );
   NumFormat( 'D',&Bin->ObgCumBuyAmt,14,6,Asc->ObgCumBuyAmt );
   NumFormat( 'D',&Bin->ObgCumSalAmt,14,6,Asc->ObgCumSalAmt );
   NumFormat( 'D',&Bin->ObgSetlNo,7,0,Asc->ObgSetlNo );
   NumFormat( 'S',&Bin->ObgTMBrnCode,2,0,Asc->ObgTMBrnCode );

   memcpy(Asc->ObgDate,Bin->ObgDate,8);Asc->ObgDate[8] = '\0';
   memcpy(Asc->ObgCupCode,Bin->ObgCupCode,12);Asc->ObgCupCode[12] = '\0';
   memcpy(Asc->ObgSecSymbol,Bin->ObgSecSymbol,10);Asc->ObgSecSymbol[10] = '\0';
   memcpy(Asc->ObgSecSeries,Bin->ObgSecSeries,2);Asc->ObgSecSeries[2] = '\0';
   memcpy(Asc->ObgSecCode,Bin->ObgSecCode,6);Asc->ObgSecCode[6] = '\0';
   memcpy(Asc->ObgTMCode,Bin->ObgTMCode,5);Asc->ObgTMCode[5] = '\0';
   memcpy(Asc->ObgCusCode,Bin->ObgCusCode,5);Asc->ObgCusCode[5] = '\0';

   Asc->ObgSetlType = Bin->ObgSetlType;
   Asc->ObgNDFlag   = Bin->ObgNDFlag;
   Asc->ObgFnlObg   = Bin->ObgFnlObg;

   //memcpy( Asc->ObgDate, Bin->ObgDate,
   //sizeof( Obligation ) - ((char *)(Bin->ObgDate) - (char *)Bin ) );

   Asc->nl = '\n' ;
}


void GetDeliveryRec()
{
   DelOrder Del   ;
   AscDelOrder ADel   ;

   DelCnt++ ;
/***
   if ( fread( &Del, sizeof( DelOrder ), 1, Inpfp ) != 1 ) {
   if ( fread( &Del, DELORDERSIZE, 1, Inpfp ) != 1 ) {
      fprintf( stderr, " Error reading Delivery Record\n" );
      perror("");
      exit(0) ;
   }
***/
   if( !ReadRecord( (DelOrder *)&Del, (long)DELORDERSIZE, ftell(Inpfp), "Error Reading Delivery Record") ) {
      return;
   }

   ConvDel( &Del, &ADel );

/***
   putc( OpnType, Delfp );
   if ( fwrite( &ADel, sizeof( ADel ), 1, Delfp ) != 1 ) {
      fprintf( stderr, " Error writing Delivery Record\n" );
      perror("");
      exit(0) ;
   }
***/
}

void ConvDel( Bin, Asc )
DelOrder *Bin   ;
AscDelOrder *Asc   ;
{
   sprintf( Asc->DelQty, "%9.0lf", Bin->DelQty );
   sprintf( Asc->Pqty, "%9.0lf", Bin->Pqty ); /*CR 856*/
   sprintf( Asc->Eqty, "%9.0lf", Bin->Eqty ); /*CR 856*/
   sprintf( Asc->RecQty, "%9.0lf", Bin->RecQty );
   sprintf( Asc->DelVal,  "%16.2lf", Bin->DelVal );
   sprintf( Asc->DelNoCert, "%9.0lf", Bin->DelNoCert );
   sprintf( Asc->DelSetlNo, "%7ld", Bin->DelSetlNo );
   sprintf( Asc->DelUid, "%6ld", Bin->DelUid );
   sprintf( Asc->DelNo, "%6ld", Bin->DelNo );
   sprintf( Asc->DelRecNo, "%6ld", Bin->DelRecNo );
   sprintf( Asc->DelTrdMbrBrnCode, "%2d", (int)Bin->DelTrdMbrBrnCode ); sprintf( Asc->RecTrdMbrBrnCode, "%2d", (int)Bin->RecTrdMbrBrnCode );

   //memcpy( Asc->DelDate, Bin->DelDate,sizeof( DelOrder ) - ((char *)(Bin->DelDate) - (char *)Bin ) );

   Asc->nl = '\n' ;
}

void GetTradingMember()
{
TradingMember  TrdMem ;

BrkCnt++ ;
if ( fread( &TrdMem, sizeof(TrdMem), 1, Inpfp ) != 1 ) {
fprintf( stderr, " Error reading Broker Record\n" );
perror("");
exit(0) ;
}

if ( fwrite( &TrdMem, sizeof(TrdMem), 1, Brkfp ) != 1 ) {
fprintf( stderr, " Error writing Broker Record\n" );
perror("");
exit(0) ;
}
putc( '\n', Brkfp );
}

/*-- Get record for a Custodial Prticipant --*/
void GetCustPart()
{
CustPart	CP ;

CpCnt++ ;
if ( fread( &CP, sizeof( CP ), 1, Inpfp ) != 1 ) {
fprintf( stderr, " Error reading Custodial Participant Record\n" );
perror("");
exit(0) ;
}

if ( fwrite( &CP, sizeof( CP ), 1, Cpfp ) != 1 ) {
fprintf( stderr, " Error writing Custodial Participant Record\n" );
perror("");
exit(0) ;
}
putc( '\n', Cpfp );
}

void GetOrdRec()
{
   #define MAX_REC_STRUCT 16
   #define ASCORDERRECSIZE 138  //Size of the Order Record in the output file
   #define ORDERRECDELIM 16     //No of delimiters printed in the Order Record
   OrderRec Order;
   AscOrderRec AscOrder;

   char OrderArr[ASCORDERRECSIZE+ORDERRECDELIM]="";

	//memset(&Order,NULL,sizeof(OrderRec));
/*****
   char sOrderNo[16];
   char sOrderQty[17];
   char sOrderVal[22];
   char sWtAvgPrice[22];
   char ErrStr[101];
   int  i;

   typedef struct {
			   char *name;
			   char type;
			   int size;
			   double d;
			   long l;
			   int i;
			   short s;
			   char str[31];
			   char chr;
			   char BinRecTyp;
	       } RECST;
	  RECST RecSt[] = {
			      {"Order No ",'D',8,0,0,0,0,"",' ','S'},//&Order.OrderNo,
			      {"Trade Qty ",'D',8,0,0,0,0,"",' ','S'},//&Order.OrderQty,
			      {"Trade Val ",'D',8,0,0,0,0,"",' ','S'},//&Order.OrderValue,
			      {"WtAvg Price ",'D',8,0,0,0,0,"",' ','S'},//&Order.AvgPrice,
			      {"Mkt Type ",'S',1,0,0,0,0,"",' ','S'},//&Order.MktType,
			      {"Dt ",'S',8,0,0,0,0,"",' ','S'},//Order.OrderDate,
			      {"Buy Sell",'S',1,0,0,0,0,"",' ','S'},//&Order.BuySellFlag,
			      {"Sec Sym",'S',10,0,0,0,0,"",' ','S'},//Order.SecSymbol,
			      {"Sec Series",'S',2,0,0,0,0,"",' ','S'},//Order.SecSeries,
			      {"Sec Code ",'S',6,0,0,0,0,"",' ','S'},//Order.SecCode,
			      {"TMCd ",'S',5,0,0,0,0,"",' ','S'},//Order.TrdMemCode,
			      {"Cup Cd",'S',12,0,0,0,0,"",' ','S'},//Order.CustPart,
			      {"Cus Cd",'S',5,0,0,0,0,"",' ','S'},//Order.CustCode,
			      {"ND Flag ",'S',1,0,0,0,0,"",' ','S'},//&Order.NoDelFlag,
			      {"StlMode ",'S',1,0,0,0,0,"",' ','S'},//&Order.setlmode,
			      {"IsinCd ",'S',12,0,0,0,0,"",' ','S'}//Order.isin,
	   };


	//Added By Ravi For reading the attributes of the order structure
	//one by one

	for( i = 0; i < MAX_REC_STRUCT; i++ ) {
	   switch( RecSt[i].type ) {
	      case 'D' :
		     sprintf(ErrStr,"Error in Reading %c : %s \n",RecSt[i].BinRecTyp,RecSt[i].name);
		     if( !ReadRecord( (double *)&RecSt[i].d, sizeof(double), ftell(Inpfp), ErrStr )) {
			RecSt[i].d = 0.0;
			//continue;
		     }

		     switch( i ) {
			case 0 : NumFormat(&RecSt[i].d,15,0,AscOrder.OrderNo);break;
			case 1 : NumFormat(&RecSt[i].d,12,3,AscOrder.OrderQty);break;
			case 2 :
				 if( ftell(Inpfp) > 5400L ){
				    printf("Value : %lf\n",RecSt[i].d);
				    Pause();
				 }
				 if(RecSt[i].d < 0.000000) {
				    RecSt[i].d = 0.0;
				    printf("Value : %lf\n",RecSt[i].d);
				    Pause();
				 }
				 NumFormat(&RecSt[i].d,14,6,AscOrder.OrderValue);break;
			case 3 :
				 if( ftell(Inpfp) > 5400L ){
				    printf("Value : %lf\n",RecSt[i].d);
				    Pause();
				 }
				 if(RecSt[i].d < 0.000000) {
				    RecSt[i].d = 0.0;
				    printf("Value : %lf\n",RecSt[i].d);
				    Pause();
				 }
				 NumFormat(&RecSt[i].d,14,6,AscOrder.AvgPrice);break;
		     }
		 break;
	      case 'S' :
		 if( RecSt[i].size == 1 ) {
		    sprintf(ErrStr,"Error in Reading %c : %s \n",RecSt[i].BinRecTyp,RecSt[i].name);
		    if ( !ReadRecord( (char *)&RecSt[i].chr, 1, ftell(Inpfp), ErrStr ) ) {
		       RecSt[i].chr = ' ';
		       //continue;
		    }

		    switch(i) {
		       case 4 : AscOrder.MktType = RecSt[i].chr;break;
		       case 6 : AscOrder.BuySellFlag = RecSt[i].chr;break;
		       case 13: AscOrder.NoDelFlag = (RecSt[i].chr == '\0')? 'N' : RecSt[i].chr;break;
		       case 14: AscOrder.setlmode = RecSt[i].chr;break;
		    }
		 }
		 else {
		    sprintf(ErrStr,"Error in Reading %c : %s \n",RecSt[i].BinRecTyp,RecSt[i].name);
		    if ( !ReadRecord( (char *)RecSt[i].str, RecSt[i].size , ftell(Inpfp), ErrStr ) ) {
		       RecSt[i].str[0] = ' '; RecSt[i].str[1] = '\0';
		       //continue;
		    }
		    RecSt[i].str[RecSt[i].size] = '\0';

		    switch( i ) {
			case 5 : strcpy(AscOrder.OrderDate,RecSt[i].str);break;
			case 7 : strcpy(AscOrder.SecSymbol,RecSt[i].str);break;
			case 8 : strcpy(AscOrder.SecSeries,RecSt[i].str);break;
			case 9 : strcpy(AscOrder.SecCode,RecSt[i].str);break;
			case 10: strcpy(AscOrder.TrdMemCode,RecSt[i].str);break;
			case 11: strcpy(AscOrder.CustPart,RecSt[i].str);break;
			case 12: strcpy(AscOrder.CustCode,RecSt[i].str);break;
			case 15: strcpy(AscOrder.isin,RecSt[i].str);break;
		    }
		 }
		 break;
	   }
	}

	sprintf(OrderArr,"%15.15s|%16.16s|%21.21s|%21.21s|%c|%8.8s|%c|%10.10s|%-2.2s|%6.6s|%5.5s|%12.12s|%5.5s|%c|%c|%12.12s|",
			     AscOrder.OrderNo,AscOrder.OrderQty,AscOrder.OrderValue,AscOrder.AvgPrice,
			     AscOrder.MktType,AscOrder.OrderDate,AscOrder.BuySellFlag,AscOrder.SecSymbol,
			     AscOrder.SecSeries,AscOrder.SecCode,AscOrder.TrdMemCode,AscOrder.CustPart,
			     AscOrder.CustCode,AscOrder.NoDelFlag,AscOrder.setlmode,AscOrder.isin);

	OrderArr[ASCORDERRECSIZE+ORDERRECDELIM]='\0';

	fprintf(OrdOutfp,"%s\n",OrderArr);
	fprintf(Outfp,"%s\n",OrderArr);
  ***/
	OrderCnt++;


   if( !ReadRecord( (OrderRec *)&Order,(long)ORDERRECSIZE,ftell(Inpfp),"Error Reading Order Record \n" )) {
      return;
   }
   /*if( !ReadOrderRecord( &Order,(long)ORDERRECSIZE,ftell(Inpfp),"Error Reading Order Record \n" )) {
      return; 
   } */

   ConvOrder( &Order, &AscOrder );

   if( Order.NoDelFlag == '\0' || Order.NoDelFlag == NULL ) {
      Order.NoDelFlag = ' ';
   }


   sprintf(OrderArr,"%16.16s|%16.16s|%21.21s|%21.21s|%c|%8.8s|%c|%10.10s|%-2.2s|%6.6s|%5.5s|%12.12s|%5.5s|%c|%c|%12.12s|",
		     AscOrder.OrderNo,AscOrder.OrderQty,AscOrder.OrderValue,AscOrder.AvgPrice,
		     AscOrder.MktType,AscOrder.OrderDate,AscOrder.BuySellFlag,AscOrder.SecSymbol,
		     AscOrder.SecSeries,AscOrder.SecCode,AscOrder.TrdMemCode,AscOrder.CustPart,
		     AscOrder.CustCode,AscOrder.NoDelFlag,AscOrder.setlmode,AscOrder.isin);

   OrderArr[ASCORDERRECSIZE+ORDERRECDELIM]='\0';

   fprintf(OrdOutfp,"%s\n",OrderArr);
   printf("%s\n",OrderArr);

   fprintf(Outfp,"No : %s  Qty : %16.16s  Value : %21.21s  AvgPrice : %21.21s  MktType : %c \n",
	   AscOrder.OrderNo,AscOrder.OrderQty,AscOrder.OrderValue,AscOrder.AvgPrice,AscOrder.MktType);
   fprintf(Outfp,"Date : %8.8s  BuySellFlag : %c  SecSymbol : %10.10s  SecSeries : %-2.2s \n",
	   AscOrder.OrderDate,AscOrder.BuySellFlag,AscOrder.SecSymbol,AscOrder.SecSeries);
   fprintf(Outfp,"SecCode : %6.6s TrdMemCode : %5.5s CustPartCd : %12.12s CustCode : %5.5s \n",
	   AscOrder.SecCode,AscOrder.TrdMemCode,AscOrder.CustPart,AscOrder.CustCode);
   fprintf(Outfp,"NoDelFlag : %c  SetlMode : %c  ISIN Cd : %12.12s \n",
	   AscOrder.NoDelFlag,AscOrder.setlmode,AscOrder.isin);

   printf("No : |%s|  Qty : |%16.16s|  Value : |%21.21s|  AvgPrice : |%21.21s|  MktType : |%c| \n",
	   AscOrder.OrderNo,AscOrder.OrderQty,AscOrder.OrderValue,AscOrder.AvgPrice,AscOrder.MktType);
   printf("Date : |%8.8s|  BuySellFlag : |%c|  SecSymbol : |%10.10s|  SecSeries : |%-2.2s| \n",
	   AscOrder.OrderDate,AscOrder.BuySellFlag,AscOrder.SecSymbol,AscOrder.SecSeries);
   printf("SecCode : |%6.6s| TrdMemCode : |%5.5s| CustPartCd : |%12.12s| CustCode : |%5.5s| \n",
	   AscOrder.SecCode,AscOrder.TrdMemCode,AscOrder.CustPart,AscOrder.CustCode);
   printf("NoDelFlag : |%c|  SetlMode : |%c|  ISIN Cd : |%12.12s| \n",
	   AscOrder.NoDelFlag,AscOrder.setlmode,AscOrder.isin);

}

/***
  Accepts a double nummber and converts into a string and stores it in RetFormat
  taking the number of digits before decimal from dig and no of digits after
  decimal from dec
***/

void NumFormat(char type, void *num, int dig, int dec, char *RetFormat) {
   char StrFormat[101]="";
   char Format[21]="";
//   char NumForm[5]="";
//   char *Rstr="";
   int  cnt=0, len=0;

   switch( type ) {
      case 'D' :
		  sprintf(Format,"%%%d.%dlf",dig,dec);
		  sprintf(StrFormat,Format,*(double *)num);
		  break;
      case 'L' :
		  //strcpy(NumForm,"ld");
		  sprintf(Format,"%%%d.%dld",dig,dec);
		  sprintf(StrFormat,Format,*(long *)num);
		  break;

      case 'S' :
		  sprintf(Format,"%%%d.%dd",dig,dec);
		  sprintf(StrFormat,Format,*(short *)num);
		  break;
      case 'I' :
		  //strcpy(NumForm,"s");
		  sprintf(Format,"%%%d.%dd",dig,dec);
		  sprintf(StrFormat,Format,*(int *)num);
		  break;
   }

   if( dec )
      len = dig + dec + 1;
   else
      len = dig + dec;

   /** Storing the digits before the decimal point into RetFormat **/
   for(cnt=0;cnt < len;cnt ++) {
      RetFormat[cnt] = StrFormat[cnt];
   }
   RetFormat[cnt] = '\0';

   /*****
   if( dig != strlen(RetFormat) ) {
      ltrim(RetFormat);

      Rstr = RetFormat;
      for(cnt = 0; cnt < (dig - strlen(RetFormat)) {
	 RetFormat[cnt] = ' ';
      }
      for(i = 0;cnt < dig;cnt ++,i++ ) {
	 RetFormat[cnt] = Rstr[i];
      }
   }
   *****/
}
/***
  trims all the spaces from the string
***/
void NumFormat_Double(char type, double *num, int dig, int dec, char *RetFormat) {
   char StrFormat[101]="";
   char Format[21]="";
//   char NumForm[5]="";
//   char *Rstr="";
   int  cnt=0, len=0;

   switch( type ) {
      case 'D' :
		  sprintf(Format,"%%%d.%dlf",dig,dec);
		  sprintf(StrFormat,Format,*num);
		  break;
      case 'L' :
		  //strcpy(NumForm,"ld");
		  sprintf(Format,"%%%d.%dld",dig,dec);
		  sprintf(StrFormat,Format,*(long *)num);
		  break;

      case 'S' :
		  sprintf(Format,"%%%d.%dd",dig,dec);
		  sprintf(StrFormat,Format,*(short *)num);
		  break;
      case 'I' :
		  //strcpy(NumForm,"s");
		  sprintf(Format,"%%%d.%dd",dig,dec);
		  sprintf(StrFormat,Format,*(int *)num);
		  break;
   }

   if( dec )
      len = dig + dec + 1;
   else
      len = dig + dec;

   /** Storing the digits before the decimal point into RetFormat **/
   for(cnt=0;cnt < len;cnt ++) {
      RetFormat[cnt] = StrFormat[cnt];
   }
   RetFormat[cnt] = '\0';

   /*****
   if( dig != strlen(RetFormat) ) {
      ltrim(RetFormat);

      Rstr = RetFormat;
      for(cnt = 0; cnt < (dig - strlen(RetFormat)) {
	 RetFormat[cnt] = ' ';
      }
      for(i = 0;cnt < dig;cnt ++,i++ ) {
	 RetFormat[cnt] = Rstr[i];
      }
   }
   *****/
}
void ltrim(char *str) {
   char *rstr="";
   int i = 0;

   rstr = str;

   while( rstr[i] != '\0' ) {
      if( rstr[i] != ' ' ) {
	 str[i] = rstr[i];
      }
      i ++;
   }
   str[i] = '\0';
}

/**
  Generic Read function accepts a void pointer and reads Len bytes into the
  location to which the pointer points.

  Prevpos gives the position in the file before the read is done.This is used
  to rollback to the previous position in case the read fails.

  In case the read fails the function rollsback to the previous position in
  the file and then skips Len bytes and then returns to the calling function.

  If the read is successful but the number of bytes read is less than or more
  than the actual bytes to be read then this function again jumps to the
  correct position and then returns to the calling function.
**/

int ReadRecord( Rec, Len, PrevPos, Err )
void *Rec;
long  Len;
long  PrevPos;
char *Err;
{
   if ( fread( Rec, Len, 1, Inpfp ) != 1 ) {
      if( (ftell(Inpfp)) != (GetInputFileSize()) ) {
	     fprintf(Outfp,"Error in reading data starting at position %ld \n",ftell(Inpfp));
	     fseek(Inpfp,PrevPos,SEEK_SET);
	     fprintf(Outfp,"Pos after rolling back : %ld \n",ftell(Inpfp));
	     fseek(Inpfp,Len,SEEK_CUR);
	     fprintf(Outfp,"Pos after skipping : %ld \n",ftell(Inpfp));
	     return 0;
      }
      else {
	 if( Err != NULL ) {
	    perror( Err );
	 }
	 CloseFiles();
	 exit(0);
      }
   }
   //fprintf(Outfp,"position after read %ld \n",ftell(Inpfp));

   /***
     If Bytes read by the above fread statement is not equal to the actual no
     of bytes that were to be read,then forcibly jump to the correct position


   if( ftell(Inpfp) - ( PrevPos + Len ) != 0L ) {
      fseek(Inpfp,PrevPos+Len,SEEK_SET);
      fprintf(Outfp,"position after forcible skip %ld \n",ftell(Inpfp));
   }
   ***/
   return 1;
}

int ReadOrderRecord( Rec, Len, PrevPos, Err )
OrderRec *Rec;
long  Len;
long  PrevPos;
char *Err;
{
   if ( fread( Rec, Len, 1, Inpfp ) != 1 ) {
      if( (ftell(Inpfp)) != (GetInputFileSize()) ) {
	     fprintf(Outfp,"Error in reading data starting at position %ld \n",ftell(Inpfp));
	     fseek(Inpfp,PrevPos,SEEK_SET);
	     fprintf(Outfp,"Pos after rolling back : %ld \n",ftell(Inpfp));
	     fseek(Inpfp,Len,SEEK_CUR);
	     fprintf(Outfp,"Pos after skipping : %ld \n",ftell(Inpfp));
	     return 0;
      }
      else {
	 if( Err != NULL ) {
	    perror( Err );
	 }
	 CloseFiles();
	 exit(0);
      }
   }
   //fprintf(Outfp,"position after read %ld \n",ftell(Inpfp));

   /***
     If Bytes read by the above fread statement is not equal to the actual no
     of bytes that were to be read,then forcibly jump to the correct position


   if( ftell(Inpfp) - ( PrevPos + Len ) != 0L ) {
      fseek(Inpfp,PrevPos+Len,SEEK_SET);
      fprintf(Outfp,"position after forcible skip %ld \n",ftell(Inpfp));
   }
   ***/
   return 1;
}
void ConvOrder( Bin, Asc )
OrderRec *Bin   ;
AscOrderRec *Asc   ;
{
	//memset(Asc,NULL,sizeof(AscOrderRec));
    NumFormat('D',&Bin->OrderNo,16,0,Asc->OrderNo);
   //NumFormat_Double('D',&Bin->OrderNo,15,0,Asc->OrderNo);
   NumFormat('D',&Bin->OrderQty,12,3,Asc->OrderQty);
   NumFormat('D',&Bin->OrderValue,14,6,Asc->OrderValue);
   NumFormat('D',&Bin->AvgPrice,14,6,Asc->AvgPrice);

   Asc->MktType     = Bin->MktType;
   memcpy(Asc->OrderDate,Bin->OrderDate,8);Asc->OrderDate[8]='\0';
   Asc->BuySellFlag = Bin->BuySellFlag;
   memcpy(Asc->SecSymbol,Bin->SecSymbol,10);Asc->SecSymbol[10]='\0';
   memcpy(Asc->SecSeries,Bin->SecSeries,2);Asc->SecSeries[2]='\0';
   memcpy(Asc->SecCode,Bin->SecCode,6);Asc->SecCode[6]='\0';
   memcpy(Asc->TrdMemCode,Bin->TrdMemCode,5);Asc->TrdMemCode[5]='\0';
   memcpy(Asc->CustPart,Bin->CustPart,12);Asc->CustPart[12]='\0';
   memcpy(Asc->CustCode,Bin->CustCode,5);Asc->CustCode[5]='\0';
   Asc->NoDelFlag   = Bin->NoDelFlag;
   if(Asc->NoDelFlag == '\0') Asc->NoDelFlag = ' ';
   Asc->setlmode     = Bin->setlmode;
   memcpy(Asc->isin,Bin->isin,12);Asc->isin[12]='\0';

   Asc->nl = '\n' ;

/***
sprintf( Asc->OrderNo, "%13.0lf", Bin->OrderNo );
sprintf( Asc->OrderQty, "%9.0lf", Bin->OrderQty );
sprintf( Asc->OrderValue, "%16.2lf", Bin->OrderValue );
sprintf( Asc->AvgPrice, "%18.6lf", Bin->AvgPrice );
***/

/*
sprintf( Asc->OrderQty, "%9.0lf", *(double *)(p + 36 ));
sprintf( Asc->OrderValue, "%16.2lf", *(double *)(p + 44 ));
sprintf( Asc->AvgPrice, "%18.6lf", *(double *)(p + 52 ));
*/

   //memcpy( &(Asc->MktType), &(Bin->MktType),
   //sizeof( OrderRec ) - ((char *)&(Bin->MktType) - (char *)Bin ) );
}

void GetSeiRec()
{
   SeiRec Sei   ;
   AscSeiRec ASei   ;

   SeiCnt++ ;
   if ( fread( &Sei, SEIRECSIZE, 1, Inpfp ) != 1 ) {
      fprintf( stderr, " Error reading Quatation Record\n" );
      perror("");
      exit(0) ;
   }

   ConvSei( &Sei, &ASei );

   putc( RecType, Seifp );
   if ( fwrite( &ASei, sizeof( ASei ), 1, Seifp ) != 1 ) {
      fprintf( stderr, " Error writing Quatation Record\n" );
      perror("");
      exit(0) ;
   }
}

void ConvSei( Bin, Asc )
SeiRec *Bin   ;
AscSeiRec *Asc   ;
{
   sprintf( Asc->SeiOpenPrice, "%10.2lf", Bin->SeiOpenPrice );
   sprintf( Asc->SeiHighPrice, "%10.2lf", Bin->SeiHighPrice );
   sprintf( Asc->SeiLowPrice, "%10.2lf", Bin->SeiLowPrice );
   sprintf( Asc->SeiClosePrice, "%10.2lf", Bin->SeiClosePrice );

   memcpy( Asc->SeiSecSymbol, Bin->SeiSecSymbol,
   sizeof( SeiRec ) - ((char *)(Bin->SeiSecSymbol) - (char *)Bin ) );
   Asc->nl = '\n' ;
}

/*-- Call the respective loading programs --*/
void CallLoad()
{
char  Program[100]="";

printf( "\n\tCalling Loading programs....\n\n" );

if ( SetlCnt > 0 ) {
sprintf( Program, "%s/bin/setl_load %s %s %s",
getenv( "HOME" ), SetlFile, ErrFile, exch_code );
printf( "\t\tCalling Settlement Loading program....\n\n" );
System( Program );
Pause();
}

if ( NoDelCnt > 0 ) {
sprintf( Program, "%s/bin/nodel_load %s %s %s",
getenv( "HOME" ), NoDelFile, ErrFile, exch_code );
printf( "\t\tCalling No Deliveries Loading program....\n\n" );
System( Program );
Pause();
}

/*
if ( BrkCnt > 0 ) {
sprintf( Program, "%s/bin/brok_load %s %s",
getenv( "HOME" ), BrkFile, ErrFile );
printf( "\t\tCalling Broker Loading program....\n\n" );
System( Program );
Pause();
}
*/

if ( OrderCnt > 0 ) {
sprintf( Program, "%s/bin/ord_upload %s %s %s",
getenv( "HOME" ), OrdFile, ErrFile, exch_code );
printf( "\t\tCalling Trades Loading program....\n\n" );
System( Program );
Pause();
}

if ( ObgCnt > 0 ) {
sprintf( Program, "%s/bin/obgload %s I %s %s %s",
getenv( "HOME" ), ObgFile, ErrFile, delv_type, exch_code );
printf( "\t\tCalling Obligations Loading program....\n\n" );
System( Program );
Pause();
}

if ( DelCnt > 0 ) {
sprintf( Program, "%s/bin/del_upload I %s %s %s",
getenv( "HOME" ), DelFile, ErrFile, exch_code );
printf( "\t\tCalling Deliveries Loading program....\n\n" );
System( Program );
Pause();
}

if ( SeiCnt > 0 ) {
sprintf( Program, "%s/bin/sei_upload %s %s %s %s",
getenv( "HOME" ), SeiFile, uid, ErrFile, exch_code );
printf( "\t\tCalling Quotation Loading program....\n\n" );
System( Program );
Pause();
}
}

void System( p )
char *p;
{
system(p);
}


void Pause()
{
puts( "HIT RETURN TO CONTINUE....");
//getch();
}
//char	Message[100];
