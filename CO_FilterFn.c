













 
#define PURE_C_SOURCE
#include "CR_Common.h"
#include "stdio_64.h"
#include <ctype.h>
#include <errno.h>
#include <string.h>
int CO_Filter(FILE *fp,char msgtype) {
	int chr_ch;  
	char chr_chprev;
	char *telex="/()?'+-:.,";
	char *swift="/?:(),.+-{} ";
	fflush(fp);
	rewind(fp);
	if(msgtype=='T') {
        /* COndition in while loop changed for AIX Migration
        while((chr_ch=fgetc(fp))!=EOF)*/
	while((fgetc(fp))!=EOF) {
			fseek(fp,-1,SEEK_CUR);
                        chr_ch=fgetc(fp);
		if(islower(chr_ch))  {
			chr_ch=toupper(chr_ch);
			fflush(fp);
			fseek(fp,-1,SEEK_CUR);
			fputc(chr_ch,fp);
			fflush(fp);
			continue;
		}
		if(chr_ch==10||chr_ch==13||isalnum(chr_ch)||strchr(telex,chr_ch))
			continue;
		fflush(fp);
		fseek(fp,-1,SEEK_CUR);
		fputc(' ',fp);
		fflush(fp);
		continue;
	}
	} else {
        /* COndition in while loop changed for AIX Migration
        while((chr_ch=fgetc(fp))!=EOF)*/
	while((fgetc(fp))!=EOF) {
             fseek(fp,-1,SEEK_CUR);
             chr_ch=fgetc(fp);
		if(chr_ch==10||chr_ch==13||chr_ch==21||isalnum(chr_ch)||strchr(swift,chr_ch))
	 	{
	    if((chr_ch==45)&&(chr_chprev==10))
         {
             fflush(fp);
             fseek(fp,-1,SEEK_CUR);
             fputc(' ',fp);
             fflush(fp);
         } 	
			chr_chprev=chr_ch;
			continue;
		}
		fflush(fp);
		fseek(fp,-1,SEEK_CUR);
		fputc(' ',fp);
		fflush(fp);
		continue;
		}
	}
	return(APL_SUCCESS);
}
