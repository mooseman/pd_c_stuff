
 
/* lexer9.c  */  

/* A lexer for simple SQL statements. */ 
/* This code is released to the public domain. */ 
/* "Share and enjoy...."  ;)    */  

/* End of token is when - */ 
/* next char is space, or -  */ 
/* next char is nul, or -  */ 
/* next char is punct, or - */ 
/* curr char is punct and next char is not punct. */ 


/* TO DO:  Need to lex the table-name, column names, */ 
/* and values (ints, strings, floats, other column names).  */  
/* Table-name and column-name are both identifiers.  */ 
/* The other values are datatypes.  */ 
/* Functions to use -   */  
/* isidentifier(buf)  */ 
/* iskeyword(buf)  */ 
/* If an identifier is not a keyword then it must be a */ 
/* table-name or column-name.  */ 
/* isop(buf) */ 
/* isstrlit(buf)  */ 
/* isint(buf)  */ 
/* isfloat(buf)  */ 
/* isEOI(buf)  */      





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
    
enum chartype { ALPHA, DIGIT, USCORE, PUNCT, WSPACE, EOI, OTHER } ; 
        
     
       
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


/* Find char type of a character. */ 
chartype type(char c)
{ 
   if ( isalpha(c) )  return ALPHA ; 
   else if ( isdigit(c) )  return DIGIT ; 
   else if ( c == '_' )    return USCORE ; 
   else if ( ispunct(c) )  return PUNCT ; 
   else if ( isspace(c) )  return WSPACE ; 
   else if ( c == '\0' )   return EOI ; 
   else return OTHER ; 	
} 	


/* isfirst() function. Return whether or not the char */ 
/* is the first character of a valid identifier, keyword */ 
/* integer or string.  */ 
int isfirst(char ch1, char ch2)
{
	
	
	
	
} 	



/* Show the transition (if any) from one 
/* character type to the next.  */ 
int transition(char ch1, char ch2)
{ 
   	
	
	

	
} 	





/* Test to see if two consecutive chars are part */ 
/* of a valid identifier or string. */ 
int isvalid(char ch, char next)
{




} 


	
	


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
    
 char *test2 = "select foo, bar , baz ,test from mytable ; " ; 
 lexer(test2);     
    
                         
 return 0;
 
 
}




