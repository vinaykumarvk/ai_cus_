/*  COPYRIGHT NOTICE

 *  Copyright 2005 Polaris Software Lab Limited. All rights reserved.
 *  These materials are confidential and proprietary to
 *  Polaris Software Lab Limited and no part of these materials should
 *  be reproduced, published, transmitted or distributed in any form or
 *  by any means, electronic, mechanical, photocopying, recording or
 *  otherwise, or stored in any information storage or retrieval system
 *  of any nature nor should the materials be disclosed to third parties
 *       or used in any other manner for which this is not authorized, without
 *    the prior express written authorization of Polaris Software Lab Limited.
 */
 /********************************************************************************
 *   File Name           :        CreateExcel.c 
 *
 *   Description         :         This file contains all functions to prepare .xls format Report
 *
 *     Version Control Block

 *  Date        Version     Author               Description
 *  ----------- --------  ---------------  ---------------------------
 *  02/04/2007   1.0      Harvinder Singh   This file contains all functions to prepare .xls format Report
 *
***************************************************************************************/

//#include<stdio.h>
#include<string.h>
#include "CO_IndStructdef.h"
#include "CA_Common.h"
#include "CO_OthStructdef.h"

FILE *xlfile=NULL;
//int report_field=0;

/* To open stream for creating .xls reprot */
int XLS_Strt_Page(char *Path, char *File_Name,char *worksheetname)
{
	printf("\n Entering XLS_Strt_Page");
	printf("\n Path = %s", Path);
	printf("\n File_Name = %s",File_Name);
	printf("\n worksheetname = %s",worksheetname);
	strcat(Path,File_Name);
	strcat(Path,".xls");
	printf("\n Complete path for opening stream |%s|",Path);
	if ((xlfile = fopen(Path,"w+")) == NULL)
	{
		printf("\n Stream can't open");
		return(APL_FAILURE);
	}

	printf("\n Stream opened successfully \n ");

	/* To strat the construction process of .xls report */

	fflush(xlfile); fprintf(xlfile,"<html xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:x=\"urn:schemas-microsoft-com:office:excel\" xmlns=\"http://www.w3.org/TR/REC-html40\">");
	fflush(xlfile); fprintf(xlfile,"\n<head>");
	fflush(xlfile); fprintf(xlfile,"\n<meta http-equiv=Content-Type content=\"text/html; charset=us-ascii\">");
	fflush(xlfile); fprintf(xlfile,"\n<meta name=ProgId content=Excel.Sheet>");
	fflush(xlfile); fprintf(xlfile,"\n<meta name=Generator content=\"Microsoft Excel 10\">");
	fflush(xlfile); fprintf(xlfile,"\n<style>");
	fflush(xlfile); fprintf(xlfile,"\n .xlflt \n {mso-number-format:Fixed;\n white-space:nowrap;}");
	fflush(xlfile); fprintf(xlfile,"\n .xlzro \n {mso-number-format:\"\@\";\n white-space:nowrap;}");
	fflush(xlfile); fprintf(xlfile,"\n .xldate \n {mso-Date-format:Fixed;\n white-space:nowrap;}");
	fflush(xlfile); fprintf(xlfile,"\n .xlflt_4 \n {mso-number-format:0\\.0000;\n white-space:nowrap;}");
	fflush(xlfile); fprintf(xlfile,"\n </style>");
	fflush(xlfile); fprintf(xlfile,"\n <!--[if gte mso 9]><xml> "); 
	fflush(xlfile); fprintf(xlfile,"\n <x:ExcelWorkbook> \n <x:ExcelWorksheets> \n <x:ExcelWorksheet>");
	fflush(xlfile); fprintf(xlfile,"\n <x:Name> %s </x:Name>", worksheetname);
	fflush(xlfile); fprintf(xlfile,"\n <x:WorksheetOptions> \n <x:Selected/> \n <x:DisplayGridlines/>");
	fflush(xlfile); fprintf(xlfile,"\n  <x:ProtectContents>False</x:ProtectContents> \n <x:ProtectObjects>False</x:ProtectObjects> \n <x:ProtectScenarios>False</x:ProtectScenarios> \n </x:WorksheetOptions>");
	fflush(xlfile); fprintf(xlfile,"\n </x:ExcelWorksheet> \n </x:ExcelWorksheets> \n <x:ProtectStructure>False</x:ProtectStructure> \n <x:ProtectWindows>False</x:ProtectWindows> \n </x:ExcelWorkbook> ");
	fflush(xlfile); fprintf(xlfile,"\n </xml><![endif]--> ");
	fflush(xlfile); fprintf(xlfile,"\n</head>");
    fflush(xlfile); fprintf(xlfile,"\n<body>");
	fflush(xlfile); fprintf(xlfile,"\n<table bordercolor=lightgrey cellSpacing=1 cellPadding=1 align=center border=1>");

	printf("\n Leaving XLS_Strt_Page() successfully\n");
	return(APL_SUCCESS);
}

/* To construct the cell when the type of value is string */
/* CPI (Cell Position Indicator) */
int Cell_Str(char *alignment,int width,char *value,char *cpi)
{
	printf("\n Entering Cell_Str()");
	printf("\n alignment = %s", alignment);
	printf("\n width = %d",width);
	printf("\n value = %s", value);
	printf("\n cpi = %s", cpi);

        //report_field++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr>");
		//printf("\n Record row started with report field No. %d",report_field);
	}

	fflush(xlfile); fprintf(xlfile,"\n<td align=%s class=xlzro width=%d height=17> %s </td>",alignment,width,value);

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		//printf("\n Record row ended with report field No. %d",report_field);
	}
	printf("\n Leaving Cell_Str()  successfully");
	return(APL_SUCCESS);
}

/* To construct the cell when the type of value is Float */
/* CPI (Cell Position Indicator) */
int Cell_Flt(char *alignment,int width,double value,char *cpi)
{
	printf("\n Entering Cell_Flt()");
	printf("\n alignment = %s", alignment);
	printf("\n width = %d",width);
	printf("\n value = %.2lf", value);
	printf("\n cpi = %s", cpi);

	//report_field++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr>");
		//printf("\n Record row started with report field No. %d",report_field);
	}

	fflush(xlfile); fprintf(xlfile,"\n<td align=%s class=xlflt width=%d height=17> %.2lf </td>",alignment,width,value);

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		//printf("\n Record row ended with report field No. %d",report_field);
	}

	printf("\n Leaving Cell_Flt() successfully");
	return(APL_SUCCESS);	
}

/* To construct the cell when the type of value is Integer */
/* CPI (Cell Position Indicator) */
int Cell_Intgr(char *alignment,int width,long int value,char *cpi)
{
	printf("\n Entering Cell_Intgr() ");
	printf("\n alignment = %s", alignment);
	printf("\n width = %d",width);
	printf("\n value = %ld", value);
	printf("\n cpi = %s", cpi);

	//report_field++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr>");
		//printf("\n Record row started with report field No. %d",report_field);
	}

	fflush(xlfile); fprintf(xlfile,"\n<td align=%s width=%d height=17> %ld </td>",alignment,width,value);

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		//printf("\n Record row ended with report field No. %d",report_field);
	}
	printf("\n Leaving Cell_Intgr()  successfully");
	return(APL_SUCCESS);
}

/* To construct the header row of report */
/* CPI (Cell Position Indicator) */
int Header_Row_Cell(char *alignment,int width,char *value,char *cpi)
{
	int report_Hfield=0;
	printf("\n Entering Header_Row_Cell() ");
	printf("\n alignment = %s", alignment);
	printf("\n width = %d",width);
	printf("\n value = %s", value);
	printf("\n cpi = %s", cpi);

	report_Hfield++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr bgcolor=silver>");
		printf("\n Header row started with report field No. %d",report_Hfield);
	}

	fflush(xlfile); fprintf(xlfile,"\n<th align=%s width=%d height=17> %s </th>",alignment,width,value);

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		printf("\n Header row ended with report field No. %d",report_Hfield);
	}
	printf("\n Leaving Header_Row_Cell() successfully");
	return(APL_SUCCESS);
}

/* To End the constrcution porcess of .xls reprot */
int XLS_End_Page()
{
	printf("\n Entering XLS_End_Page()");

	printf("\n Stream Destroyed successfully");

	fflush(xlfile); fprintf(xlfile,"\n</table>\n</body>\n</html>");
	fclose(xlfile);
	printf("\n Leaving XLS_End_Page() successfully");
	return(APL_SUCCESS);
}


/* To construct the .xls report when no record is there */
int No_Rec_Cell(char *message)
{
	printf("\n Entering No_Rec_Cell() ");
	printf("\n message = %s", message);
	fflush(xlfile); fprintf(xlfile,"\n<tr><strong> %s </strong></tr>",message);
	printf("\n Leaving No_Rec_Cell() successfully");
	return(APL_SUCCESS);
}

/* To construct the cell when the type of value is Float */
/* fields should display the decimal values only incase of the Quantity is in decimal  - Rahul 01Apr07*/
/* CPI (Cell Position Indicator) */
int Cell_Decimal(char *alignment,int width,double value,char *cpi)
{
	printf("\n Entering Cell_Decimal()");
	printf("\n alignment = %s", alignment);
	printf("\n width = %d",width);
	printf("\n value = %.2lf", value);
	printf("\n cpi = %s", cpi);

	//report_field++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr>");
		//printf("\n Record row started with report field No. %d",report_field);
	}

	fflush(xlfile); fprintf(xlfile,"\n<td align=%s width=%d height=17> %.2lf </td>",alignment,width,value);

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		//printf("\n Record row ended with report field No. %d",report_field);
	}

	printf("\n Leaving Cell_Decimal() successfully");
	return(APL_SUCCESS);	
}

/* ISKB 342 - End - Common Function call for all datatype - Rahul 18June2007*/
/* To construct the cell for any type of value  -Rahul - 18June2007 */
/* CPI (Cell Position Indicator) */
int Cell_Common(char *alignment,int width,char *char_value,long int int_value,double flt_value,char *cpi,char *class_name,FILE *l_logfile)
{
	fflush(l_logfile); fprintf(l_logfile,"\nEntering Function Cell_Common().......\n");
	fflush(l_logfile); fprintf(l_logfile,"Cell_Common: Class Passed is  --> |%s| \n",class_name);
	//report_field++;

	if(strcmp(cpi,"S")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n<tr>");
		//fprintf(l_logfile,"Record row started with report field No. %d\n",report_field);
	}

	if(!strcmp(class_name,"xlzro") || !strcmp(class_name,"xldate"))
	{
		    /* For Strings & Date formate */
			fflush(l_logfile); fprintf(l_logfile,"Cell_Common: String Value --> |%s| \n",char_value);
			fflush(xlfile); fprintf(xlfile,"\n<td class=%s align=%s width=%d height=17> %s </td>",class_name,alignment,width,char_value);
	}
	else if(!strcmp(class_name,"xlflt") )
	{
		    /* For Normal Float value with 2 decimal */
			fflush(l_logfile); fprintf(l_logfile,"Cell_Common: Float Value --> |%.2lf| \n",flt_value);
			fflush(xlfile); fprintf(xlfile,"\n<td  class=%s align=%s width=%d height=17> %.2lf </td>",class_name,alignment,width,flt_value);					
	}
	else if(!strcmp(class_name,"xlflt_4") )
	{
		    /* For Normal Float value with 4 decimal */		    
			fflush(l_logfile); fprintf(l_logfile,"Cell_Common: Float Value --> |%.4lf| \n",flt_value);
			fflush(xlfile); fprintf(xlfile,"\n<td  class=%s align=%s width=%d height=17> %.4lf </td>",class_name,alignment,width,flt_value);		
	}
	else if (!strcmp(class_name,"decimal") )
	{
		 /* For float value where decimal part display only for non-zero digit */
		 fflush(l_logfile); fprintf(l_logfile,"Cell_Common: Float Value --> |%.2lf| \n",flt_value);
		 fflush(xlfile); fprintf(xlfile,"\n<td align=%s width=%d height=17> %.2lf </td>",alignment,width,flt_value);
	}
	else
	{
		    /* For Integer  Value */
			fflush(l_logfile); fprintf(l_logfile,"Cell_Common: Int Value --> |%ld| \n",int_value);
			fflush(xlfile); fprintf(xlfile,"\n<td align=%s width=%d height=17> %ld </td>",alignment,width,int_value);
	}

	if(strcmp(cpi,"E")==0)
	{
		fflush(xlfile); fprintf(xlfile,"\n</tr>");
		//fprintf(l_logfile,"Record row started with report field No. %d\n",report_field);
	}

	RETURN_SUCCES :
		fflush(l_logfile); fprintf(l_logfile,"Leaving Function Cell_Common() with Success");
		return(APL_SUCCESS);

	RETURN_FAILURE :
		fflush(l_logfile); fprintf(l_logfile,"Leaving Function Cell_Common() with Failure");
		return(APL_FAILURE);

}
/* ISKB 342 - End - Common Function call for all datatype - Rahul - 18June2007*/
