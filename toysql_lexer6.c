

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


/* Helper function to get the type of a char.     */ 
/* What we mean by "type" here is the "type" that */ 
/* the char can be used to create.  */ 
/* For example: letters, digits, underscores can be used */ 
/* to create keywords or column names. */ 
/* digits can be used to create integers. */ 
/* Single chars are operators of some kind. */ 
/* Double chars are also operators. */   
int type(char c) 
{ 
	
  /* NOTE - column names can have letters, digits or */ 
  /* underscores. We separate the digit test out so that */ 
  /* in order for a char to fit the column-name pattern, */ 
  /* the test will simply be - */ 
  /* while ( (type == 1) || (type == 2) )   */   	
   if ( ( isalpha(c) ) || ( c == '_' ) ) return 1; 
	 else if ( ( isdigit(c) ) )                return 2;   
	 else if ( c == (',')  )   return 3;  
	 else if ( c == (';')  )   return 4;  
	 else if ( c == ('"')  )   return 5;  
	 else if ( c == ('=')  )   return 6;  
	 else if ( c == ('<')  )  return 7;  
	 else if ( c == ('>')  )   return 8;  
	 else if ( c == ('\0') )   return 9;  
     else return 10; 	   	
	   	   
}    	
	

char *test(char *str) 
{ 
   int i=0;    
   char tok[20]; 	
   
   int type; 
   
   
   
   
		
} 	




  
/* NOTE - need an array of tokens. */     	    

void tokenise(char *str) 
{ 
	
  int i=0;    
  char c; 
           
  while ( c != '\0') 
  { 
	c = str[i];    
	printf("c: %c \n", c);  
	i++;   		
  }  /*  *str != '\0'   */   	     
          	  	       	      		
} 	




int main() 
{ 
  
 char *test = "select foo" ;   
 tokenise(test);   
                                               
 return 0;
 
 
}  


