

/*  dir.c   */  
/*  List files in the current directory.  */ 
/*  This code is based on the public-domain code here - */ 
/*  http://www.utoronto.ca/web/HTMLdocs/Book/Book-3ed/chap9/nph-doit2.c  */ 
/*  Many thanks to Rob McCool for that!  */  
/*  This code is released to the public domain.  */ 
/*  "Share and enjoy......"  ;)    */  


#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h>



int main()
{

/* Declare a directory struct. */ 
struct dirent *dp;

/* Declare a directory stream. */ 
DIR *dirp = NULL ;  

/* Point it at the current directory. */ 
dirp = opendir(".");

/* While the dir struct is not NULL...  */  
while ( (dp = readdir(dirp)) != NULL )   
{ 
   /*  ... print the file names.  */  	
   puts(dp->d_name); 
}  

/* Close the directory. */ 
closedir(dirp);


return 0;

}





