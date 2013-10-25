


/*  encode.c  */ 

/*  Encoding an 8-digit numeric array. */ 


#include <string.h>  
#include <stdio.h> 
#include <stdlib.h>  


/* Convert a decimal integer to hexadecimal. */ 
void dec2hex(int i)
{
   /* 	
   char retval; 	
	
   char hexdigits[16] = {0,1,2,3,4,5,6,7,8,9,
      'A','B','C','D','E','F'}  ;  
   
   if (i < 16) retval = hexdigits[i] ; 
   */  
   
   printf("%X \n", i); 
     
}    
   	
	
	
	
	
	
int main()
{
	
int a = 12; 
dec2hex(a);

int b = 34; 
dec2hex(b); 

int c = 75;
dec2hex(c); 

	
	
return 0; 

}		









 


