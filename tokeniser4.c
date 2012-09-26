


/*  tokeniser3.c                                   */ 
/*  A simple tokeniser.                           */  
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* See if we are moving from a "normal" character to a */ 
/* "separator" character (or vice versa).  */  
int issep(int ch)   
{ 
   int retval ;    	
      
/*  Space = 32,  comma = 44, newline = 10, tab = 9, 
    semicolon = 59.   */     
               
   if (    ( ch == 9  )  ||  ( ch == 10 ) 
        || ( ch == 32 )  ||  ( ch == 44 ) 
        || ( ch == 59 )  )  retval = 1;                               
   else retval = 0 ; 		
   
   return retval; 		
} 	


/* A change of chartype from sep to non-sep */ 
/* ( or vice versa. )                       */     
/* Ch2 should be the next char after ch1.   */                         
int ischange(char ch1, char ch2)
{ 
   int retval; 	
	
   int a = issep(ch1); 
   int b = issep(ch2); 
   
   if ( (a != b) )  retval = 1; 
   else retval = 0; 
   return retval;  	
} 	


/* Look at doing startswith(), endswith(), */ 
/* contains(), maycontain() functions.     */  

/* Special chars - Comma, semicolon, equals. */ 
/* Could include other ops in here too. */ 
int isspecial(int ch) 
{ 
   /* Comma = 44 decimal in ascii. */ 	
   /* Semicolon = 59, equals = 61. */ 
    
    if ( ( ch == 44 ) || ( ch == 59 ) 
      || ( ch == 61 ) )  return 1; 
   else return 0;  	 
} 	

/*  IF NEXT = SPECIAL OR CURR = SPECIAL OR  */ 
/* NEXT = WS THEN TOKENISE.  */ 




/* A simple tokenising function. */ 
/* TO DO: tweak this so we can have column names like */ 
/* col1, col2 etc. */ 
/* Tweak it again to separate on whitespace as the default, */ 
/* putting commas in their own tokens wherever they appear. */ 

void tokenise(char *str) 
{
  char *ptr1, *ptr2 = NULL; 
  ptr1 = str; 
  ptr2 = str + 1;   
  	
  /* Forty tokens, max length of 79 (plus null). */   	
  char token[40][80] ; 
  
  /* Token "pointer" variable. */ 
  int tokptr = 0; 
  
  int numchars=1 ;	
		           
  /* Get the types - separator or not. */ 
  int ret ;  
  
  /* Move along the string. */            
  while ( *ptr1 != '\0' ) 
  { 	  	
	ret = ischange(*ptr1, *ptr2);  
	
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
		  str = ptr1; 		 
       }  
	
    ptr1++ ; 
    ptr2 = ptr1 + 1; 			 
  }  	
 
 /* At EOF - is ptr-1 on a token?  */  
 if ( !(isspace(*ptr1) ) )  
   { 
	 strncpy(token[tokptr], str, numchars); 
	 token[tokptr][numchars+1] = '\0' ;  
     printf("Token: %s \n", token[tokptr]);    
   }     
         	           
} 	



int main() 
{ 
      
 
char *foo = NULL; 

foo = "select _col1, col2 ,colC from test where city = \"Auckland\" ;" ; 

tokenise(foo);  

                                                
return 0;
  
}  




