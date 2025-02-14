/****
  This Program reads data from Input Text File and writes the data into
  Output File in binary form.
  Paramters : 1. <Input text file name>
	      2. <Output binary file name>

  Usage     : convbin <Input Text FileName> <Output Binary FileName>
****/

#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<mem.h>

// Header size in the text file (includes the newline character also)
#define HDRSIZE 128

// Detail record size in the text file (includes the newline character also)
#define DTLSIZE  22

/** Header Structure to be written in binary file **/
struct hdr_rec {
   char sign[4];
   char file_sent;
   char gen_place;
   char hp_creat_dt[3];
   char hp_creat_time[3];
   char oth_creat_dt[3];
   char oth_creat_time[3];
   char expiry_dt[3];
   char expiry_time[3];
   char chk_sum[4];
   char filler1[12];
   char nsecmclg_ver[3];
   char filler2[57];
} hdr_rec1;
/** Detail Structure to be written into binary file **/
struct cnf_rec {
   char rectyp;
   char acttyp;
   double ordno;
   char ordbuysellflg[1];
   char ordcnfflg[1];
} cnf_rec1;

/**
Temporary Variables ,corresponding to the header structure, in which the data read
from the text file is stored.
**/
char sign[9];
int  f_sent;
char file_sent[2]; //added by ravi - 14/09/2000
int  g_place;
char gen_place[2]; //added by ravi - 14/09/2000
char hp_creat_dt[7];
char hp_creat_time[7];
char oth_creat_dt[7];
char oth_creat_time[7];
char expiry_dt[7];
char expiry_time[7];
char chk_sum[9];
char filler1[13];
char nsecmclg_ver[4];
char filler2[58];

/**
Temporary Variables ,corresponding to the detail structure, in which the data read
from the text file is stored
**/
char ordno[17];

/**
header from the text file is read into this variable.
1 is added to the HDRSIZE to accomodate the null terminator.
**/
char linehdr[HDRSIZE + 1];

/**
detail record from the text file is read into this variable.
1 is added to the HDRSIZE to accomodate the null terminator.
**/
char linedtl[22];

void main(int argc, char *argv[]) {
     FILE *f1,*f2;

     if( argc < 3 ) {
	fprintf(stderr,"%-s : \nUsage :- convbin <Input Text FileName> <Output Binary FileName>\n",argv[0]);
	exit(0);
     }

     /** Open the text file in read mode **/
     if( (f1 = fopen(argv[1],"r")) == NULL ){
	fprintf(stderr,"%-s : Unable to open file %-s\n",argv[0],argv[1]);
	exit(0);
     }

     /** Open the binary file in write mode **/
     if( (f2 = fopen(argv[2],"wb")) == NULL ){
	fprintf(stderr,"%-s : Unable to open output file %-s\n",argv[0],argv[2]);
	exit(0);
     }

     fflush(stdin);

     /** Reading the header part from the text file **/
     fgets(linehdr, 128, f1);
     linehdr[128] = '\0';

     /**
	Storing the fields in temporary variables and compressing them,if
	neccessary and copying the required number of bytes of the formatted
	variable to the corresponding header structure variables.
     **/
     substr(linehdr, sign, 0, 8);sign[8]='\0';
     comprchar(sign);  //converts 8 byte string to 4 bytes.
     memcpy(hdr_rec1.sign,sign,4);

     /**
     Commented by ravi - 15/09/2000,the value in file_sent and gen_place
     couldnt be read properly
     hdr_rec1.file_sent = linehdr[8];
     hdr_rec1.gen_place = linehdr[9];
     ***/
     substr(linehdr, file_sent, 8, 9);file_sent[1] = '\0';
     f_sent = atoi(file_sent); printf("File Sent (Int) %d\n",f_sent);
     sprintf(&hdr_rec1.file_sent,"%c",f_sent);

     substr(linehdr, gen_place, 9,10);gen_place[1]='\0';
     g_place = atoi(gen_place); printf("Gen Place (Int) %d\n",g_place);
     sprintf(&hdr_rec1.gen_place,"%c",g_place);

     substr(linehdr, hp_creat_dt, 10, 16);hp_creat_dt[6] = '\0';
     convdt(hp_creat_dt); //converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.hp_creat_dt,hp_creat_dt,3);

     substr(linehdr, hp_creat_time, 16, 22);hp_creat_time[6] = '\0';
     convdt (hp_creat_time); //converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.hp_creat_time,hp_creat_time,3);

     substr(linehdr, oth_creat_dt, 22, 28);oth_creat_dt[6] = '\0';
     convdt (oth_creat_dt);  //converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.oth_creat_dt,oth_creat_dt,3);

     substr(linehdr, oth_creat_time, 28, 34);oth_creat_time[6] = '\0';
     convdt (oth_creat_time);//converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.oth_creat_time,oth_creat_time,3);

     substr(linehdr, expiry_dt, 34, 40);expiry_dt[6] = '\0';
     convdt (expiry_dt);     //converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.expiry_dt,expiry_dt,3);

     substr(linehdr, expiry_time, 40, 46);expiry_time[6] = '\0';
     convdt(expiry_time);    //converts 6 byte string to 3 bytes.
     memcpy(hdr_rec1.expiry_time,expiry_time,3);

     substr(linehdr, chk_sum, 46, 54);chk_sum[8] = '\0';
     comprchar(chk_sum);     //converts 8 byte string to 4 bytes.
     memcpy(hdr_rec1.chk_sum,chk_sum,4);

     substr(linehdr, filler1, 54, 66);filler1[12] = '\0';
     memcpy(hdr_rec1.filler1,filler1,12);

     substr(linehdr, nsecmclg_ver, 66, 69);nsecmclg_ver[3] = '\0';
     memcpy(hdr_rec1.nsecmclg_ver, nsecmclg_ver, 3);

     substr(linehdr, filler2, 69, 126);filler2[57]='\0';
     memcpy(hdr_rec1.filler2,filler2,57);

     /** Writing the header structure to the Output file **/
     fwrite(&hdr_rec1,sizeof(struct hdr_rec),1,f2);

     while(!feof(f1)) {
	/** Reading the detail records one by one into the array linedtl,until
	    the end of the file
	 **/
	fgets(linedtl, 22, f1);
	linedtl[22] = '\0';

	cnf_rec1.rectyp = linedtl[0];
	cnf_rec1.acttyp = linedtl[1];

	substr(linedtl, ordno, 2, 18);ordno[16]='\0';
	//cnf_rec1.ordno = atof(ordno);
	cnf_rec1.ordno = strtod(ordno,NULL);//converting the string to double
	printf("Order No : %16.0lf\n",cnf_rec1.ordno);

/***
	Commented by ravi - 15/09/2000,the change done on 13/09/2000
	is reverted.
	couldnt be read properly
	cnf_rec1.ordbuysellflg = linedtl[17];
	cnf_rec1.ordcnfflg     = linedtl[18];
***/
	substr(linedtl,cnf_rec1.ordbuysellflg,18,19);
	substr(linedtl,cnf_rec1.ordcnfflg,19,20);

	/** Writing the detail record to the output file **/
	fwrite(&cnf_rec1,sizeof(struct cnf_rec),1,f2);
     }
     fclose(f1);
     fclose(f2);
     exit(1);
}

/**
  Accepts a 6 byte array and then converts it into a 3 byte array.
  stores the 6 byte array into 3 arrays of 2 bytes each and then each of
  these 2 byte arrays are converted into integers.
  Finally the ascii constants of these 3 integers are stored into the
  original array as 3 bytes and the array is null terminated.
**/

convdt ( char *rdate ) {
   int  dt[3] = {0,0,0};
   char dd[3] = "";
   char mm[3] = "";
   char yy[3] = "";

   dd[0] = rdate[0];
   dd[1] = rdate[1];
   dd[2] = '\0';
   dt[0] = atoi(dd);

   mm[0] = rdate[2];
   mm[1] = rdate[3];
   mm[2] = '\0';
   dt[1] = atoi(mm);

   yy[0] = rdate[4];
   yy[1] = rdate[5];
   yy[2] = '\0';
   dt[2] = atoi(yy);

   sprintf(rdate,"%c%c%c",dt[0],dt[1],dt[2]);
   rdate[3]='\0';
   //printf("Read Back : %02d%02d%02d \n",rdate[0],rdate[1],rdate[2]);
   return ;
}

/**
  Accepts a 8 byte array and then converts it into a 4 byte array.
  stores the 8 byte array into 4 arrays of 2 bytes each and then each of
  these 2 byte arrays are converted into integers .
  Finally the ascii constants of these 3 integers are stored into the
  original array as 4 bytes and the array is null terminated.
**/
comprchar ( char *rdate ) {
   int dt[4];
   //char pdate[9] = "";
   char dd[3] = "";
   char mm[3] = "";
   char yy[3] = "";
   char xx[3] = "";

   dd[0]=rdate[0];
   dd[1]=rdate[1];
   dd[2]='\0';
   dt[0] = atoi(dd);

   mm[0]=rdate[2];
   mm[1]=rdate[3];
   mm[2]='\0';
   dt[1] = atoi(mm);

   yy[0]=rdate[4];
   yy[1]=rdate[5];
   yy[2]='\0';
   dt[2]=atoi(yy);

   xx[0]=rdate[6];
   xx[1]=rdate[7];
   xx[2]='\0';
   dt[3]=atoi(xx);

   sprintf(rdate,"%c%c%c%c",dt[0],dt[1],dt[2],dt[3]);
   rdate[4] = '\0';
   //printf("Sign : %s\n",rdate);
   //printf("Read Back : %02d%02d%02d%02d\n",rdate[0],rdate[1],rdate[2],rdate[3]);
   return;
}

substr(const char pstr[], char rstr[], int st, int en) {
   int m=0;
   int i=0;
   for ( i=st; i<en; i++ ) {
       rstr[m] = pstr[i];
       m++;
       if (i == en) break;
   }
   rstr[m] = '\0';
   return;
   //return *rstr;
}
