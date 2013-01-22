

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

struct dirent *dp;

DIR *dirp = NULL ;  

dirp = opendir(".");


while ( (dp = readdir(dirp)) != NULL )   
{ 
   puts(dp->d_name); 
}  

closedir(dirp);


return 0;

}





