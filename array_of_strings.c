

/*  array_of_strings.c  */  



#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 


int main() 
{ 
 
 char *test1 = "foo" ; 
 char *test2 = "bar" ; 
 char *test3 = "baz" ; 
  
 char*  myarr[3] ; 
 
 myarr[0] = test1 ;   
 myarr[1] = test2 ;   
 myarr[2] = test3 ;             
 
 int i; 
 for (i=0; i<3; i++) 
 {                                
   printf("myarr[%d] : %s \n", i, myarr[i]);     
 }        
                                               
 return 0;
 
}  







