
 
/* lexer9.c  */  

/* A lexer for simple SQL statements. */ 
/* This code is released to the public domain. */ 
/* "Share and enjoy...."  ;)    */  


#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 


/* Enum for token types. */  
enum toktype { SELECT_, FROM, WHERE, AND, OR, IS, IN, NOT, NULL_, 
    LPAREN, RPAREN, EQ, NE, GT, LT, GE, LE, COMMA, SEMI, STAR,
    VARNAME, STRINGVAL, INTVAL, UNKNOWN } ;    
       
/* Union for data type. */ 
typedef union datatype { 
       int integer; 
       char varname[20]; 
       char *string; 
} u;               
          

/* Token struct. */  
typedef struct token { 
       enum toktype tokentype; 
       union datatype dtype;    
} token_t; 



/* Helper function for variable (column) names. */ 


/* Helper function for string values.  */ 


/* Helper function for integer values. */ 


/* Declare a token. */ 
token_t mytok ; 



/* The lexer */  
int lexer(char *str) 
{ 
	
  char *tok = malloc(80) ; 
            
  int toklen = 0; 
  
  
  /* Pointer to character after *str. */ 
  /* Used to find first character of string. */  
  char *next; 
  next = str + 1;       
          
  while ( *str != '\0' ) 
  {                      
     if ( *str != ' ' )               
     {  
        tok[toklen] = *str;      
        toklen++;   
        
        /* We have reached the end of the token */                  
        if ( ( *next == ' ' ) || ( next == '\0' ) ) 
        {
        
           /* Find the type of the token */ 
           if (!strcmp(tok, "select")) mytok.tokentype = SELECT_ ; 
           else if (!strcmp(tok, "*")) mytok.tokentype = STAR ; 
           else if (!strcmp(tok, "from")) mytok.tokentype = FROM ; 
           else if (!strcmp(tok, "where")) mytok.tokentype = WHERE ; 
           else if (!strcmp(tok, "=")) mytok.tokentype = EQ ; 
           else if (!strcmp(tok, "!=")) mytok.tokentype = NE ; 
           else if (!strcmp(tok, ">=")) mytok.tokentype = GE ; 
           else if (!strcmp(tok, "<=")) mytok.tokentype = LE ; 
           else if (!strcmp(tok, ">"))  mytok.tokentype = GT ; 
           else if (!strcmp(tok, "<"))  mytok.tokentype = LT ; 
           else if (!strcmp(tok, ","))  mytok.tokentype = COMMA ; 
           else if (!strcmp(tok, ";"))  mytok.tokentype = SEMI ; 
           else if (!strcmp(tok, "and")) mytok.tokentype = AND ; 
           else if (!strcmp(tok, "or"))  mytok.tokentype = OR ; 
           else if (!strcmp(tok, "not")) mytok.tokentype = NOT ; 
           else if (!strcmp(tok, "in"))  mytok.tokentype = IN ; 
           else if (!strcmp(tok, "is"))  mytok.tokentype = IS ; 
           else if (!strcmp(tok, "null")) mytok.tokentype = NULL_ ; 
           /* TO DO: Need a couple of helper functions to take care of */ 
           /* variable (column) names, string values, integer values. */ 
           else mytok.tokentype = UNKNOWN; 
           
       printf("Token is %s, token type is %d, length is %d \n", tok, mytok.tokentype, toklen );                 
           
         }   
        
        
        /* Move the pointer along. */  
        str++; 
        next = str + 1;         
     } 
     else if ( *str == ' ' ) 
     {  
        toklen = 0;  
        memset(tok, 0, 79);                
        str++; 
        next = str + 1;    
         
     }    
     
  }  
           
  
  free(tok); 
  
  return mytok.tokentype; 
                    
} 



int main() 
{ 
 
 char *test = "select * from mytable where city = \"Auckland\" and \
           var1 = 123 and var2 = \"test\" ; " ;   
 
 lexer(test) ;           
    
                      
 return 0;
 
 
}




