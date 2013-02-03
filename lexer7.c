

/*  lexer5.c  */  

/* Funcs for recognising transitions from one chartype */ 
/* to another, e.g. alpha->ws, ws->alpha, digit->ws. */ 
 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Our buffer to hold the input.  */  
char buf[80] ;    
 

/* A helper enum */  
enum chartype { LETTER, DIGIT, PUNCT, SPACE, OTHER };    



/* Function to get the type of a char. */ 
int testchar(char ch) 
{ 
  if (isalpha(ch))       return LETTER ; 
  else if (isdigit(ch))  return DIGIT  ; 
  else if (ispunct(ch))  return PUNCT  ;    
  else if (isspace(ch))  return SPACE  ; 
  else                   return OTHER  ;           
}     



/* Get a char and act accordingly. */ 
int typechange(char ch, char next)
{ 
   if (  (testchar(ch) == testchar(next) )  ) 
      return 0;  /* Same type.  */  
   else return -1;  /* Different type */  
} 	
	

 
/* Our tokenise function. */  
void tok(char *mystr) 
{ 
   int i=0;     
   int type; 
           
   char a, b;     
                
   while(*mystr != '\0') 
   { 
	 a = *mystr;
	 b = *mystr+1;
   	   
     buf[i] = a;  
     
     type = typechange(a, b);  
     
     if ( ( type == -1 ) && 
          ( testchar(a) == SPACE  
         || testchar(b) != SPACE 
         || testchar(b) == PUNCT         
         || testchar(b) == '\0' ) ) 
       { printf("%s \n", buf);  
         /* memset(buf, '\0', 80);  */ 
         /* i=0; */ 
       } 
              
        
     /* printf("%d \n", type); */ 
     i++;              
     mystr++; 
     
   }            
              
}     




int main() 
{ 

 
 char *test = "select * from mytable ; " ; 
 char *test2 = "select foo, bar ,baz from mytable ; " ;  
  
 tok(test);     
 tok(test2); 
                                      
 return 0;
 
 
}  







