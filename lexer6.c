

/*  lexer6.c  */  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Our buffer to hold the input.  */  
char buf[80] ;    
 

/* A helper enum */  
enum toktype { SELECT, STAR, FROM, WHERE, AND, OR, NOT, IN, 
   SEMI, SPACE, DBLQUOTE };    


/* Helper function */ 
int gettoktype(char *str) 
{ 
       if (strcmp(str, "select" ) )    return SELECT  ; 
  else if (strcmp(str, "from"   ) )    return FROM    ; 
  else if (strcmp(str, "where"  ) )    return WHERE   ; 
  else if (strcmp(str, "and"    ) )    return AND     ; 
  else if (strcmp(str, "or"     ) )    return OR      ; 
  else if (strcmp(str, "not"    ) )    return NOT     ; 
  else if (strcmp(str, "in"     ) )    return IN      ;    
  else return -1; 
  
}     




int main() 
{ 
 
 char str[] = "select \"foo\" from test;" ; 
 char delim[] = " "  ;  
 char *result = NULL;  
 result = strtok(str, delim ); 
  
 while( result != NULL ) {
    printf( "result is \"%s\"\n", result );
    result = strtok( NULL, delim );
} 
  
  
 /* gettoktype(test);   */   
                                               
 return 0;
 
 
}  


