

/*  tokeniser.c                                   */ 
/*  A simple tokeniser.                           */  
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Get the type of a character. */ 
char *gettype(char *str) 
{ 
   char *type = NULL;    	
   
        if (isalpha(*str) )  type = "str" ; 
   else if (isdigit(*str) )  type = "digit" ; 
   else if (ispunct(*str) )  type = "punct" ; 
   else if (isspace(*str) )  type = "ws" ; 
   else type = "other" ; 		
   return type; 		
} 	



/* Helper function showing when the type of character changes */ 
/* while moving along a string. */ 
void charchange(char *str) 
{    
  char *next = NULL; 
  next = str + 1;   
  
  /* Get the types */ 
  char *typestr = NULL ; 
  char *typestr1 = NULL ;       
  int comp ;  /* comparison flag  */  
  
  /* Move along the string. */            
  while ( *next != '\0' ) 
  {  
	typestr = gettype(str); 
    typestr1 = gettype(next);      
	comp = strcmp(typestr, typestr1); 
	if (  comp != 0  )  
	   {
		    printf("Type now is %s, changing to %s \n", 
		        typestr, typestr1); 
       }  		        
    str++ ; 
    next++ ; 	    
  }  	     	
} 	



/* A simple tokenising function. */ 
/* TO DO: tweak this so we can have column names like */ 
/* col1, col2 etc. */ 
void tokenise(char *str) 
{
  char *ptr = NULL; 
  ptr = str+1;   
  
  int numchars=1;  
  char token[80] ;  
  
  /* Get the types */ 
  char *typestr = NULL ; 
  char *typestr1 = NULL ;       
  int comp ;  /* comparison flag  */  
  
  /* Move along the string. */            
  while ( *str != '\0' ) 
  { 	  	
	typestr = gettype(str); 
    typestr1 = gettype(ptr);      
	comp = strcmp(typestr, typestr1); 
	/* A tweak to allow numeric suffixes and colnames starting */ 
	/* with an underscore. */ 
	/* if ( ( strcmp(typestr, "uscore" ) )  
	   &&  (  ( strcmp(typestr1, "alpha" ) )    
	   ||     ( strcmp(typestr1, "digit" ) )  )  )  comp = 0;  */  
	
	if ( comp == 0 ) 
	{ 	      		
      /* Increment numchars. */ 
       numchars++;         
    }    		         
		
	else if (  comp != 0  )  
	   {  
		  /* New token */  
		  strncpy(token, str, numchars); 
          printf("Token: %s \n", token);  
          /* Reset numchars. */ 		  
		  numchars = 1; 
		  /* Move the str pointer to the same place */ 
		  /* as our scanning pointer. */ 
		  str = ptr; 		  
       }  
    /* Clear token array. */      
    memset(&token[0], 0, sizeof(token));
    ptr++ ; 
    		  
  }  	
      
} 	






int main() 
{ 
   
 
char *foo = "select _col1, col2, colC from test \
     where city = \"Auckland\" ;" ; 

tokenise(foo);  

                                                
return 0;
  
}  






