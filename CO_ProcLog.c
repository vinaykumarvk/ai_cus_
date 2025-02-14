













 
#define PURE_C_SOURCE

#include <string.h>
#include "CR_Common.h"
#include <time.h>
#define  S_TIME_LEN  9



int CO_ProcMonitor(FILE *fptr,char *p_charmessage,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_c) 
{
	DEBUG_INFO_STRUCT_H *l_debuginfo_struct_h;
	char chr_tempforuserid[APL_USERID_LEN+3];
	char chr_errwartag;
   
	struct tm      sys_time;
	time_t         t;
	char           chr_time_buf[S_TIME_LEN];

	memset(&sys_time,'\0',sizeof(sys_time)); //AIX- Warnings Removal

	t = time(NULL);

	gmtime_r(&t, &sys_time);

	sprintf(chr_time_buf, "%02d:%02d:%02d",sys_time.tm_hour, sys_time.tm_min, sys_time.tm_sec);

	if(l_debug_info_ptr)
	  l_debuginfo_struct_h=*l_debug_info_ptr;
	else 
	  l_debuginfo_struct_h=NULL;

memset(chr_tempforuserid,'\0',sizeof(chr_tempforuserid)); //AIX- Warnings Removal
	if(p_intl_env_data_struct_h_c)
		sprintf(chr_tempforuserid,"%s:",p_intl_env_data_struct_h_c->usr);
	else
		//sprintf(chr_tempforuserid,"");AIX - Warnings Removal
		sprintf(chr_tempforuserid,"%s","");
	if(p_charmessage) 
		fprintf(fptr,"%s<%s>%s\n",chr_tempforuserid,chr_time_buf,p_charmessage);
	if(!l_debuginfo_struct_h)
		APL_GOBACK_SUCCESS
	if(l_debuginfo_struct_h == (DEBUG_INFO_STRUCT_H *)NULL)
		APL_GOBACK_SUCCESS
	CO_InsertMsg(l_debuginfo_struct_h);
	for(;(l_debuginfo_struct_h);(l_debuginfo_struct_h)=(l_debuginfo_struct_h)->h_next)
	{
		if((l_debuginfo_struct_h)->h_err_warn==ERROR)
			chr_errwartag='E';
		else
			chr_errwartag='W';
		fprintf(fptr,"%s%c : %s : %d : %s",chr_tempforuserid,chr_errwartag,(l_debuginfo_struct_h)->h_file,(l_debuginfo_struct_h)->h_line,(l_debuginfo_struct_h)->msg);
		if( strlen(l_debuginfo_struct_h->h_key1) ) 
			fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key1);
		if( strlen(l_debuginfo_struct_h->h_key2) ) 
			fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key2);
		if( strlen(l_debuginfo_struct_h->h_key3) ) 
			fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key3);
		fprintf(fptr,"\n");
	}

	APL_GOBACK_SUCCESS
	RETURN_SUCCESS:
	{
		fflush(fptr);
		return APL_SUCCESS;
	}
	RETURN_FAILURE:
	{
		fflush(fptr);
		return APL_FAILURE;
	}
}

int CO_WrLog_WODtTime(FILE *fptr,char *p_charmessage,DEBUG_INFO_STRUCT_H **l_debug_info_ptr,INTL_ENV_DATA_STRUCT_H *p_intl_env_data_struct_h_c)
{
   DEBUG_INFO_STRUCT_H *l_debuginfo_struct_h;
   char chr_tempforuserid[APL_USERID_LEN+3];
   char chr_errwartag;

   if(l_debug_info_ptr)
     l_debuginfo_struct_h=*l_debug_info_ptr;
   else
     l_debuginfo_struct_h=NULL;

memset(chr_tempforuserid,'\0',sizeof(chr_tempforuserid)); //AIX- Warnings Removal
   if(p_intl_env_data_struct_h_c)
      sprintf(chr_tempforuserid,"%s:",p_intl_env_data_struct_h_c->usr);
   else
      //sprintf(chr_tempforuserid,"");AIX- Warnings Removal
      sprintf(chr_tempforuserid,"%s","");
   if(p_charmessage)
      fprintf(fptr,"%s%s\n",chr_tempforuserid,p_charmessage);
   if(!l_debuginfo_struct_h)
      APL_GOBACK_SUCCESS
   CO_InsertMsg(l_debuginfo_struct_h);
   for(;(l_debuginfo_struct_h);(l_debuginfo_struct_h)=(l_debuginfo_struct_h)->h_next)
   {
      if((l_debuginfo_struct_h)->h_err_warn==ERROR)
         chr_errwartag='E';
      else
         chr_errwartag='W';
      fprintf(fptr,"%s%c : %s : %d : %s",chr_tempforuserid,chr_errwartag,(l_debuginfo_struct_h)->h_file,(l_debuginfo_struct_h)->h_line,(l_debuginfo_struct_h)->msg);
      if( strlen(l_debuginfo_struct_h->h_key1) )
         fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key1);
      if( strlen(l_debuginfo_struct_h->h_key2) )
         fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key2);
      if( strlen(l_debuginfo_struct_h->h_key3) )
         fprintf(fptr," :%s",(l_debuginfo_struct_h)->h_key3);
      fprintf(fptr,"\n");
   }
 APL_GOBACK_SUCCESS
   RETURN_SUCCESS:
   {
      fflush(fptr);
      return APL_SUCCESS;
   }
   RETURN_FAILURE:
   {
      fflush(fptr);
      return APL_FAILURE;
   }
}

