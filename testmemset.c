

/*  testmemset.c  */  

/* Play around with memset.  */  



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Our buffer to hold the input.  */  
char buf[80] ;    
 

/* A helper enum for char types. */  
enum chartype { LETTER, DIGIT, USCORE, COMMA, 
    PUNCT, SPACE, SEMI, _NULL, OTHER };    



/* Function to get the type of a char. */ 
int testchar(char ch) 
{ 
  if (isalpha(ch))        return LETTER ; 
  else if (isdigit(ch))   return DIGIT  ; 
  else if ( ch == '_' )   return USCORE ; 
  else if ( ch == ',' )   return COMMA  ; 
  else if ( ispunct(ch))  return PUNCT  ;    
  else if ( isspace(ch))  return SPACE  ; 
  else if ( ch == ';'  )  return SEMI   ; 
  else if ( ch == '\0' )  return _NULL  ;  
  else                    return OTHER  ;           
}     


          

int main() 
{ 

 
 char test[80] = "select foo, bar ,baz from mytable ; " ;  
 printf("%s \n", test);   
  
 memset(test, 1, 6);              
  
 printf("%s \n", test);  
  
 memset(test, 7, 12);  
                         
 printf("%s \n", test);                           
                                     
 memset(test, 13, 20);  
                         
 printf("%s \n", test);   
                                                              
                                     
 return 0;
 
 
}  







