













 
#include "stdio_64.h"
#include <ctype.h>
#include <string.h>
#define	PURE_C_SOURCE
#include "Intellect_Interface.h"
#include	"Intellect_Common.h"
#include "Intellect_Error.h"
#define	S_LINE_SIZE			80
#define	S_FILE_SIZE			3000	 


int	CO_Rtv_Token(int         p_seq_num, FILE*			p_fptr,
						char*				p_token,
						char*				chr_p_val,
						DEBUG_INFO_STRUCT_H  **l_debug_info_ptr)
{
	
	char								l_debug_info_struct_h_tmp[S_LINE_SIZE+1];
	int								i=0;
	char 								chr_tokeninfile[S_LINE_SIZE+1];
	
	int								int_tok = 0;
	char*                      chr_p_seq_num_str;     
	char 								chr_p_tokstr[10] = "";
	int 								int_l_passed_pos = 0;			
	int 								l_return = 0;
	/*Changes done for linux migration */
	#ifdef OS_LINUX
	long long fl_passed_pos = 0;
        #else
        fpos_t fl_passed_pos = 0;
	#endif
	/* fpos_t fl_passed_pos = 0; */
        int msg_line_no=0;
		/* l_return = fgetpos(p_fptr,&int_l_passed_pos); PJ	*/
		l_return = fgetpos(p_fptr,&fl_passed_pos);
		chr_p_seq_num_str=ltoa(p_seq_num);                  
		while(1)
		{
			fgets(l_debug_info_struct_h_tmp,S_LINE_SIZE+1,p_fptr);
			sscanf(l_debug_info_struct_h_tmp," %[^ =]",chr_tokeninfile);
			if(chr_tokeninfile[0]==';') continue;
			

			for(i=0; ;i++)
			{
				if(isdigit(chr_tokeninfile[i]))
					continue;
				else
					break;
			}

			strncpy(chr_p_tokstr,chr_tokeninfile,i);
			chr_p_tokstr[i+1]='\0';
			int_tok = atof(chr_p_tokstr);					 
				
		   if ( (int_tok == (p_seq_num +1 )) && p_seq_num != 0)
			{
				
		       break;
			}		
				
		   
  		   if (!strncmp(p_token,chr_tokeninfile,strlen(p_token)))
		   {
				 
				 if( strstr(l_debug_info_struct_h_tmp,"NEW_NOTE") !=NULL )
		         sscanf(l_debug_info_struct_h_tmp, "%*[^=]=%[^\n]", chr_p_val);
				 else
		         sscanf(l_debug_info_struct_h_tmp, "%*[^=]= %[^\n]", chr_p_val);
   	       for(;isspace(chr_p_val[strlen(chr_p_val)-1]);chr_p_val[strlen(chr_p_val)-1]='\0');
		           break;
		   }

			if (feof(p_fptr))
			{  
			
				break;
			}
			if (ferror(p_fptr))
				APL_GOBACK_FAIL
			i++;
		}
                msg_line_no = i;
	
	APL_GOBACK_SUCCESS
	RETURN_SUCCESS	:
	{
		return (APL_SUCCESS);
	}
	RETURN_FAILURE	:
	{
		return (APL_FAILURE);
	}
}
