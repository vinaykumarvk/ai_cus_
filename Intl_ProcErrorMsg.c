













 


#define PURE_C_SOURCE
#include "CR_Common.h"

static	int CO_InsertNode(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_err_warn,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file,
		int				ok_ind
);
static int	CO_Chk_WarnExistsAndOk(DEBUG_INFO_STRUCT_H	*l_debug_infolist,
														int h_code,
														char	*h_key1,
														char	*h_key2,
														char	*h_key3);

extern	char*	chr_g_error_messages[]; 



void CO_PrnErr(DEBUG_INFO_STRUCT_H   *l_debug_infolist)
{
	while (l_debug_infolist != NULL)
	{
		if (l_debug_infolist->h_err_warn == ERROR)
			printf("\nerror_warning %s\n", "ERROR");
		if (l_debug_infolist->h_err_warn == WARNING)
			printf("\nerror_warning %s\n", "WARNING");

		printf("code %d\n", l_debug_infolist->h_code);
		printf("key1 %s\n", l_debug_infolist->h_key1);
		printf("key2 %s\n", l_debug_infolist->h_key2);
		printf("key3 %s\n", l_debug_infolist->h_key3);
		printf("line %d\n", l_debug_infolist->h_line);
		printf("file %s\n", l_debug_infolist->h_file);
		if ( l_debug_infolist->msg != NULL)
			printf("message %s\n", l_debug_infolist->msg);

		if (l_debug_infolist->ok_ind == OK)
			printf("ok_flag %s\n", "OK");
		else
		if (l_debug_infolist->ok_ind == NOT_OK)
			printf("ok_flag %s\n", "NOT_OK");
		else
			printf("ok_flag %s\n", "NOT_SET");

		l_debug_infolist = l_debug_infolist->h_next;
	}
}



void	CO_OkWarning(DEBUG_INFO_STRUCT_H	*l_debug_infolist)
{
	while ( l_debug_infolist != NULL)
	{
		if ( l_debug_infolist->h_err_warn == WARNING)
			l_debug_infolist->ok_ind = OK;
		l_debug_infolist	=	l_debug_infolist->h_next;
	}
}



int	CO_ChkErr(DEBUG_INFO_STRUCT_H	*l_debug_infolist)
{
	while ( l_debug_infolist != NULL)
	{
		if ( (l_debug_infolist->h_err_warn == ERROR) ||
				((l_debug_infolist->h_err_warn == WARNING) &&
				 (l_debug_infolist->ok_ind == NOT_OK))
			)
			return APL_SUCCESS;
		l_debug_infolist	=	l_debug_infolist->h_next;
	}
	return APL_FAILURE;
}



static int	CO_Chk_WarnExistsAndOk(DEBUG_INFO_STRUCT_H	*l_debug_infolist,
														int	h_code,
														char	*h_key1,
														char	*h_key2,
														char	*h_key3)
{
	while ( l_debug_infolist != NULL)
	{
		if ( l_debug_infolist->h_err_warn == WARNING)
		{
			if ( 	(l_debug_infolist->h_code == h_code) && 
					(!strcmp(l_debug_infolist->h_key1,h_key1)) &&
					(!strcmp(l_debug_infolist->h_key2,h_key2)) &&
					(!strcmp(l_debug_infolist->h_key3,h_key3)) &&
					( l_debug_infolist->ok_ind == OK))
				return APL_SUCCESS;
		}
		l_debug_infolist	=	l_debug_infolist->h_next;
	}
	return APL_FAILURE;
}





int CO_InsertErr(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file
)
{
	//Alert("Debug Purpose : Inside CO_InsertErr");
	//fflush(stdout);
	/*
	printf("code %d\n", h_code);
	fflush(stdout);
	printf("file %s\n", h_file);
	fflush(stdout);
	printf("line %d\n", h_line);
	fflush(stdout);
	printf("key1 %s\n", h_key1);
	fflush(stdout);
	printf("key2 %s\n", h_key2);
	fflush(stdout);
	printf("key3 %s\n", h_key3);
	fflush(stdout);*/

	if(	CO_InsertNode(
								p_debug_info_struct_h_b,
								ERROR,
								h_code,
								h_key1,
								h_key2,
								h_key3,
								h_line,
								h_file,
								NOT_OK
							) != APL_SUCCESS)
		return APL_FAILURE;
	return APL_SUCCESS;
}



int CO_InsertWarning(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file
)
{
	if ( CO_Chk_WarnExistsAndOk(*p_debug_info_struct_h_b,
												h_code,
												h_key1,
												h_key2,
	
												h_key3 ) != APL_SUCCESS )
	  {
     //AIX - Warnings Removal -- changes in braces
		if(	CO_InsertNode(
									p_debug_info_struct_h_b,
									WARNING,
									h_code,
									h_key1,
									h_key2,
									h_key3,
									h_line,
									h_file,
									NOT_OK
								) == APL_SUCCESS)
			return APL_SUCCESS;
		else
			return APL_FAILURE;
}
	else
		return APL_SUCCESS;
}



static	int CO_InsertNode(
		DEBUG_INFO_STRUCT_H	**p_debug_info_struct_h_b,
		int				h_err_warn,
		int				h_code,
		char*				h_key1,
		char*				h_key2,
		char*				h_key3,
		int				h_line,
		char*				h_file,
		int				ok_ind
)
{

	DEBUG_INFO_STRUCT_H **temp 		= p_debug_info_struct_h_b;
	int	int_no_errors=	0;

	while ( (*temp) != NULL)
	{
		if (	((*temp)->h_err_warn	==	WARNING)	&&
				((*temp)->ok_ind			==	OK)
			)
			{  }
		else
			int_no_errors++;
		temp = &((*temp)->h_next);
	}

	if (	int_no_errors > APL_MAX_ERRORS	)
		return	APL_FAILURE;

	//Alert("Debugging : CO_InsertNode");
	//fflush(stdout);

	/* #ifdef DCE

	(*temp) = rpc_ss_allocate(sizeof(DEBUG_INFO_STRUCT_H));
	memset(*temp,NULL,sizeof(DEBUG_INFO_STRUCT_H));

	#else */

	//Alert("Allocating space");
	//fflush(stdout);

	if ( ( (*temp) = calloc(1,sizeof(DEBUG_INFO_STRUCT_H)) ) == NULL )
	//if((temp = (DEBUG_INFO_STRUCT_H**)(calloc(1,sizeof(DEBUG_INFO_STRUCT_H)))) == NULL)
		return APL_FAILURE ;

	//Alert("After Allocating space");
	//fflush(stdout);
	
	/* #endif */

	//Alert("Debugging : CO_InsertNode 1");
	//fflush(stdout);
	
	//Alert("h_err_warn = |%d|",h_err_warn);
	//fflush(stdout);

	(*temp)->h_err_warn	=	h_err_warn;
	//Alert("After assigning the structure");
	//fflush(stdout);
	(*temp)->h_code				=	h_code;
	//Alert("After assigning the structure");
	//fflush(stdout);
	(*temp)->h_line				=	h_line;
	//Alert("After assigning the structure");
	//fflush(stdout);
	(*temp)->ok_ind			=	ok_ind;
	//Alert("After assigning the structure");
	//fflush(stdout);
	(*temp)->debug_ind		=  APL_DEBUG_YES; 
	//Alert("After assigning the structure");
	//fflush(stdout);

	
		if (h_key1 != NULL)
		{
			//Alert("1");
			//fflush(stdout);
	 		strncpy((*temp)->h_key1,h_key1,19);
			strcat((*temp)->h_key1,APL_NULL_STRING);
		}
		else
		{
			//Alert("2");
			//fflush(stdout);
	 		strcpy((*temp)->h_key1,APL_NULL_STRING);
		}
		if (h_key2 != NULL)
		{
			//Alert("3");
			//fflush(stdout);
			strncpy((*temp)->h_key2,h_key2,99);
			strcat((*temp)->h_key2,APL_NULL_STRING);
		}
		else
		{
			//Alert("4");
			//fflush(stdout);
	 		strcpy((*temp)->h_key2,APL_NULL_STRING);
		}
		if (h_key3 != NULL)
		{
			//Alert("5");
			//fflush(stdout);
			strncpy((*temp)->h_key3,h_key3,19);
			strcat((*temp)->h_key3,APL_NULL_STRING);
		}
		else
		{
			//Alert("6");
			//fflush(stdout);
	 		strcpy((*temp)->h_key3,APL_NULL_STRING);
		}
			//Alert("OHO");
			//fflush(stdout);
		strncpy((*temp)->h_file,h_file,49);
		strcat((*temp)->h_file,APL_NULL_STRING);

	//Alert("Exiting from CO_InsertErr");
	//fflush(stdout);

	(*temp)->h_next =  NULL;
	return APL_SUCCESS;
}



int	CO_InsertMsg(DEBUG_INFO_STRUCT_H	*l_debug_infolist)
{
	while ( l_debug_infolist != NULL)
	{
		if ( l_debug_infolist->msg == NULL )
			 {
			  #ifdef DCE
			  l_debug_infolist->msg = rpc_ss_allocate(MSG_LENGTH);
			  
			  if(l_debug_infolist->msg == NULL)
			  {
				 printf("RPC Memory Allocation Failed\n");
				 return APL_FAILURE ;
			  }
			  
			  #else
			  if ( ( (l_debug_infolist->msg) =calloc(1,MSG_LENGTH)) == NULL )
				  return APL_FAILURE ;
			  #endif
			  memset(l_debug_infolist->msg,NULL,MSG_LENGTH);
			  
				
				 
			  if(l_debug_infolist->h_code < 0 || l_debug_infolist->h_code > APL_NBR_ERRORS - 1)
			  {

				  printf("Code for Error Message  |%d | display is not within the proper limits\n",l_debug_infolist->h_code);
				  return APL_FAILURE ;
			  }
			  
			  strcpy(l_debug_infolist->msg,
							  chr_g_error_messages[l_debug_infolist->h_code]);
			 }
		l_debug_infolist	=	l_debug_infolist->h_next;
	}
	return APL_SUCCESS;
}


int CO_FreeErrLst(DEBUG_INFO_STRUCT_H **l_debug_info_ptr) 
{
	DEBUG_INFO_STRUCT_H *temp;
	while(*l_debug_info_ptr) 
	{
		if((*l_debug_info_ptr)->msg)
			free((*l_debug_info_ptr)->msg);
		temp=(*l_debug_info_ptr)->h_next;
		free((*l_debug_info_ptr));
		(*l_debug_info_ptr)=temp;
	}
	return APL_SUCCESS;
}

int CO_ChkFatalErr(DEBUG_INFO_STRUCT_H *l_debug_info_ptr)
{
	int	int_fatal_errors[] = {DB_ERR_NO,
									ERR_NO_MEMORY,
									-1};
	int i = 0;
	DEBUG_INFO_STRUCT_H *l_debug = NULL;

	for (	l_debug = l_debug_info_ptr; l_debug != NULL; l_debug = l_debug->h_next )
	{
		for(i=0;int_fatal_errors[i] != -1;i++)
			if ( l_debug->h_code == int_fatal_errors[i])
				return APL_SUCCESS;
	}
	return APL_FAILURE;
}

int CO_InsertOraErr(	DEBUG_INFO_STRUCT_H **l_debug_info_ptr,
								char *ora_msg,
								char *h_key1,
								char *h_key2,
								char *h_key3,
								int h_line,
								char *h_file )
{
	DEBUG_INFO_STRUCT_H *l_debug_info_struct_h_tmp=NULL;

	CO_InsertErr(	l_debug_info_ptr,
							DB_ERR_NO,
							h_key1,
							h_key2,
							h_key3,
							h_line,
							h_file );
	for (l_debug_info_struct_h_tmp=*l_debug_info_ptr;l_debug_info_struct_h_tmp->h_next != NULL;l_debug_info_struct_h_tmp=l_debug_info_struct_h_tmp->h_next);

  	#ifdef DCE
  	l_debug_info_struct_h_tmp->msg = rpc_ss_allocate(MSG_LENGTH);
  	#else
  	if ( ( (l_debug_info_struct_h_tmp->msg) =calloc(1,MSG_LENGTH)) == NULL )
		  return APL_FAILURE ;
  	#endif
  	memset(l_debug_info_struct_h_tmp->msg,NULL,MSG_LENGTH);

	strcpy(l_debug_info_struct_h_tmp->msg, ora_msg);
	return 0;
}

int CO_ScanErrCode(DEBUG_INFO_STRUCT_H *l_debug_infolist,
							int p_error_code)
{
		  while ( l_debug_infolist != NULL)
		  {
			 if (l_debug_infolist->h_code == p_error_code)
				  return APL_SUCCESS;
			  l_debug_infolist  =  l_debug_infolist->h_next;
		  }
		  return APL_FAILURE;
}
