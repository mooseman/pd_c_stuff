

/*  test.c  */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 

/*  Note - use one-char lookahead. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Function to find the first char of a token. */ 
/* (This assumes that tokens are separated by whitespace.)  */ 
char *isfirst(char *str)
{ 
  char *ret = malloc(80) ;  
  
  /* We use toknum for the case where we are at the start        */ 
  /* of the string and it has NO whitespace before it.           */ 
  /* In other words, a string like "foo" ( rather than " foo" ). */  
     
  int toknum = 0;     
  char *next = str + 1;   
  char *prev = str - 1;  
        
  while ( *str != '\0' ) 
  {       
     if ( !isspace(*str) && (isspace(*prev) || toknum == 0) ) 
         { ret[toknum] = *str; toknum++; }          
     str++;
     next++;
     prev++; 
  }      
     
  ret[toknum] = '\0' ;            
  return ret;                   
} 




/* Return the token-type using the first char in a token. */ 
char *toktype(char *str) 
{ 
   char *ret; 	
	
   if ( (str == '*') || (str == ',') || (str == ';') ) 
     { ret = "
   
} 	



/* Find the boundary of tokens (where there is a change from */ 
/* either whitespace or from one char-type to another). */ 
/* NOTE - need to make this cater for variable-names and */ 
/* strings with different char-types. */ 
void boundary(char *str)
{  
  /* TO DO - put enums here of the various token types. */ 	
	
	
	
	
  /* We use toknum for the case where we are at the start        */ 
  /* of the string and it has NO whitespace before it.           */ 
  /* In other words, a string like "foo" ( rather than " foo" ). */  
     
  int toknum = 0;     
  char *next = str + 1;   
  char *prev = str - 1;  
        
  while ( *str != '\0' ) 
  {       
     if ( !isspace(*str) && (isspace(*prev) || toknum == 0) ) 
         { ret[toknum] = *str; toknum++; }          
     str++;
     next++;
     prev++; 
  }      
     
        
} 

 	
	   


int main() 
{ 
   
 
char *test = "select col1 from test where city = \"Auckland\" ;" ; 
  
char *test2 = isfirst(test); 
printf("%s \n", test2); 
 
free(test2); 
                                               
return 0;
  
}  










