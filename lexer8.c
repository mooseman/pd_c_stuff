

/*  lexer8.c  */  

/* Funcs for recognising transitions from one chartype */ 
/* to another, e.g. alpha->ws, ws->alpha, digit->ws. */ 
 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 

/* Functions -  */ 
/* sleep(n)  */ 
/* take(*inputbuf)   */ 
/* peek(*inputbuf+1)   */  
/* typechange(ch1, ch2)  */  
/* append(arr, c)  */ 
/* clear(buf)  */  

/* Parse functions  */  
/* iskeyword(buf)  */ 
/* isop(buf) */ 
/* isvarname(buf) */ 
/* isstrlit(buf)  */ 
/* isnumber(buf)  */ 
/* isEOI(buf)  */      






/* Our buffer to hold the input.  */  
char buf[80] ;    
 



int main() 
{ 

 
 char *test = "select foo, bar ,baz from mytable ; " ;  
  
 char a , b; 
  
  
   while(*test != '\0') 
   { 	
	 a = *test;  
	 printf("%c" , a);	 
	 b = a++;  	   		
     printf("\n");	    
     printf("%c" , b);        	      
     test++; 
   } 
                                      
 return 0;
 
 
}  







