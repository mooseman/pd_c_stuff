

/*  closures.c                                        */ 
/*  Playing around with closures (using callbacks).   */ 
/*  This code is released to the public domain.       */ 
/*  "Share and enjoy...."  ;)                         */  
 

#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 


void cb1( char *(*foo)(void) )  
{ 
   printf("Result: %s \n", foo() );   
}  



void cb2( int(*bar)(void) ) 
{ 
   printf("Result: %d \n", bar() );  
} 



/* Functions to call.  */ 
char *f1(void) 
{    	
   return "Just a test..." ;  
} 	


int f2(void) 
{ 
   return 42;  	
} 	



int main() 
{ 


cb1(f1);   

cb2(f2); 


return 0; 

} 




 
    






