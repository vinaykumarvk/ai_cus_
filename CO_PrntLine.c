













 
#include "CO_HostStructdef.h"
#define PURE_C_SOURCE

int CO_NewLine(char *p_line) {  //AIX- Warnings Removal
	char *temp=p_line;
 	while((p_line=(strchr(p_line,'\n')))&&((*p_line)=' '));

 	while((temp=(strchr(temp,'\r')))){
		p_line=temp;
		while((*p_line++)=(*(p_line+1)));
	}
		
		return (APL_SUCCESS); //AIX -Warning Removal
	}
