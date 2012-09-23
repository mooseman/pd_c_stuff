


/* issep.c  */ 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Is a character a separator or not? */ 
/* NOTE - separators are still "valid" tokens (e.g. commas). */ 
int issep(char *ch) 
{ 
   int ret ;    	
   
   /* if  (   ( strcmp(*ch, " " )  == 0 ) 
        || ( strcmp(*ch, "," )  == 0 )  )  ret = 1 ;   */ 
        
        
   if (    ( ch == ' '  )  ||  ( ch == ','  ) 
        || ( ch == '\n' )  ||  ( ch == '\t' )  )  ret = 1;                        
   else ret = 0 ; 		
   return ret; 		
} 	



/* Helper function showing when the type of character changes */ 
/* while moving along a string. */ 
void charchange(char *str) 
{    
    
  /* Get the types */ 
  int ret ; 
  
  /* Move along the string. */            
  while ( *str != '\0' ) 
  {  
	ret = issep(*str); 
      	
	if (  ret == 1  )  
	   {
		    printf("Separator: %s\n", str ); 
       }  		        
    str++ ; 
   
  }  	     	
} 	



/* A simple tokenising function. */ 
/* TO DO: tweak this so we can have column names like */ 
/* col1, col2 etc. */ 
void tokenise(char *str) 
{
	
  char *ptr = NULL; 
  ptr = str;   
  
  int numchars=1;  
  char token[80] ;   
          
  /* Get the types - separator or not. */ 
  int ret ;  
  
  /* Move along the string. */            
  while ( *str != '\0' ) 
  { 	  	
	ret = issep(ptr);   
	
	if ( ret == 0 ) 
	{ 	      		
      /* Increment numchars. */ 
       numchars++;         
    }    		  
	 
	else if (  ret == 1  )  
	   {  
		  /* New token */  
		  strncpy(token, str, numchars); 
		  token[numchars+1] = '\0' ;    
          printf("Token: %s \n", token);  
          /* Reset numchars. */ 		  
		  numchars = 1; 
		  str = ptr; 	
       }  
	
   /* Clear token array. */      
    memset(&token[0], 0, sizeof(token));
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




