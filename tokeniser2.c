


/*  tokeniser2.c                                   */ 
/*  A simple tokeniser.                           */  
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Is a character a separator or not? */ 
/* NOTE - separators are still "valid" tokens (e.g. commas). */ 
int issep(int ch) 
{ 
   int ret ;    	
      
/*  Space = 32,  cmma = 44, newline = 10, tab = 9  */     
               
   if (    ( ch == 9  )  ||  ( ch == 10 ) 
        || ( ch == 32 )  ||  ( ch == 44 )  )  ret = 1;                               
   else ret = 0 ; 		
   
   return ret; 		
} 	



/* A simple tokenising function. */ 
/* TO DO: tweak this so we can have column names like */ 
/* col1, col2 etc. */ 
void tokenise(char *str) 
{
  char *ptr = NULL; 
  ptr = str; 
  	
  /* Forty tokens, max length of 79 (plus null). */   	
  char token[40][80] ; 
  
  /* Token "pointer" variable. */ 
  int tokptr = 0; 
  
  int numchars=0 ;	
		           
  /* Get the types - separator or not. */ 
  int ret ;  
  
  /* Move along the string. */            
  while ( *ptr != '\0' ) 
  { 	  	
	ret = issep(*ptr);  
	
	if ( ret == 0 ) 
	{ 	      		
      /* Increment numchars. */ 
       numchars++;         
    }    
	
	else if (  ret == 1  )  
	   {  
		  /* New token */  
		  strncpy(token[tokptr], str, numchars); 
		  token[tokptr][numchars+1] = '\0' ;  
          printf("Token: %s \n", token[tokptr]);  
          /* Reset numchars. */ 		  
		  numchars = 1; 
		  /* Increment tokptr */ 
		  tokptr++; 		  
		  str = ptr; 	
       }  
	 	
    ptr++ ; 			 
  }  	
    
      
} 	






int main() 
{ 
      
 
char *foo = NULL; 

foo = "select col1, col2, colC from test where city = \"Auckland\" ;" ; 

tokenise(foo);  

                                                
return 0;
  
}  




