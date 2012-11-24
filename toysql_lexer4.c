

/*  toysql_lexer.c                                */  
/*  The beginnings of a lexer for "toy SQL".      */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 

/*  Note - use one-char lookahead. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 




/* Token */ 
typedef struct { 
	    char *toktype ; 
	    char value[20]; 
} Token; 


  
/* NOTE - need an array of tokens. */     	    

void tokenise(char *str) 
{ 
	
  Token *atok; 
  atok = (Token *) malloc(sizeof(Token)); 
   		
  /* An array of tokens. */ 	
  Token *tokarray[80];  

  /* Character. */       
  char c;        
      
  /* Mytok array counter. */ 
  int i=0;    
  
  /* String counter */ 
  int j=0;   	   
  
  /* Value array counter. */ 
  int k=0; 
   
  while ( c != '\0') 
  { 
     c = str[j]; 
	  
	 if ( ( isspace(c) )  ) 
	 {  
	    j++ ;    
	 }  
	  	  	 
	/* Keyword or colname */ 	
    else if ( (isalpha(c) ) || isdigit(c) || ( c == '_' ) )  
	{	
	   while ( (isalpha(c) ) || isdigit(c) || ( c == '_' ) )	   
	   {  	 
         c = str[j];  
	     atok->value[k] = c; 
	     k++; 	  
       }  /*  Keyword or colname  */ 
       
       atok->value[k] = '\0' ;        
       k=0; 
                  
        /* Find the token type */ 
         if ( (!strcmp(atok->value, "select") )  ) atok->toktype = "T_SELECT" ; 
     else if ( (!strcmp(atok->value, "from") )  ) atok->toktype = "T_FROM" ; 	   	       
	 else if ( (!strcmp(atok->value, "where") )  ) atok->toktype = "T_WHERE" ;  
	 else atok->toktype = "T_COLNAME" ; 	
	 
	 tokarray[i] = atok; 
       
    }     
        	 
	/* Move the pointer. */ 
	i++; 
	j++;	   		 	  	
	  	  
  }  /*  *str != '\0'   */   	     
       
   int l; 
   for (l=0; l<4; l++) 
   { 
	  printf("Type: %s \n", tokarray[l]->toktype );    
	  printf("Type: %s \n", tokarray[l]->value );     
	   
      /* printf("Type: %s \n", atok[k].toktype );   
      printf("Value: %s \n", atok[k].value );  */  
   }   
   	  	       	      		
} 	




int main() 
{ 
  
 char *test = "select foo" ;   
 tokenise(test);   
                                               
 return 0;
 
 
}  


