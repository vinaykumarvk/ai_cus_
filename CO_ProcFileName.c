


	
   
   
   
   
   
   
   
   
   
   
						
	
   	

#include <unistd.h>
#include <string.h>
#include "stdio_64.h"
#include <dirent.h>
#ifdef OS_LINUX     /*Added by kotubabu for Linux Migration -Start*/
 #include <stdlib.h> 
#endif              /*Added by kotubabu for Linux Migration -End*/
#include <sys/stat.h> /* Bageshri --10GM */
#include <sys/types.h>
#include "CR_Common.h"
#include <Intellect_Common.h>
#include <fcntl.h>


int CO_Rtv_FileNm_From_Pointer(FILE *fp,char *directorypath,char	*chr_fl_name) 
{
	DIR *dp;
	struct dirent *dir;
	struct stat chr_buff; /* Bageshri --10GM */
	/*Commented and Rewritten by kotubabu for Linux Migration - START
	#ifdef OS_SUN
	if((!(dp=opendir(directorypath)))||(fstat(fp->_file,&chr_buff)==-1)){
		closedir(dp);
		return APL_FAILURE;
		}
	#else
	if((!(dp=opendir(directorypath)))||(fstat(fp->__fileL,&chr_buff)==-1)){
		closedir(dp);
		return APL_FAILURE;
		}
	#endif */
	#ifdef OS_LINUX
		if(!(dp=opendir(directorypath))){	
		closedir(dp);
        Alert("failure from first block....");
		return APL_FAILURE;
		}
	#else
	if((!(dp=opendir(directorypath)))||(fstat(fp->_file,&chr_buff)==-1)){
		closedir(dp);
       Alert("failure from second block....");
		return APL_FAILURE;
		}
	#endif
	/*Commented and Rewritten by kotubabu for Linux Migration - End */
	
	/* changes start for Linux migration 
	while((dir=readdir(dp))&&(dir->d_ino!=chr_buff.st_ino));
	if(dir) {
		strcpy(chr_fl_name, dir->d_name);
		return APL_SUCCESS;
		}
	*/        	
	while(dir=readdir(dp))
	{
		if(dir->d_ino!=chr_buff.st_ino)
		{
			strcpy(chr_fl_name, dir->d_name);
		} 
	}
	//changes end for Linux migration

return APL_SUCCESS;/** Added FOr AIX Migration to remove Warnings***/ 
}

/** Function Added By AMISH for Conf_File_Gene - This Function gives size of file ***/

int CO_Rtv_FileSize_From_Pointer(char *directorypath,int *fsize)
{
	printf("\n in function CO_Rtv_FileSize_From_Pointer **********start\n");
	struct stat chr_buff1;
	int l_fsize = 0;
	int status;
	char l_logfile_name[30] = APL_NULL_STRING;
	char l_fname_path[1000] = APL_NULL_STRING;
	memset(l_logfile_name,APL_NULL_CHAR,30);
	memset(l_fname_path,APL_NULL_CHAR,1000);


	strcpy(l_fname_path,directorypath);
	strcat(l_fname_path,l_logfile_name);

	stat(l_fname_path,&chr_buff1);
	l_fsize = chr_buff1.st_size;
	*fsize = l_fsize ;

	/*Added by kotubabu for Linux Migration - Start*/
	#ifdef OS_LINUX
    return(APL_SUCCESS);      //AIX- Warnings Removal  
    #endif
	/*Added by kotubabu for Linux Migration - End*/ 	
}

/** END **/



