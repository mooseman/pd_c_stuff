

/*  lexer4.c  */  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h> 


/* Our buffer to hold the input.  */  
char buf[80] ;    
 

/* A helper enum */  
enum chartype { LETTER, DIGIT, PUNCT, SPACE, OTHER };    


/* Helper function */ 
int testchar(char ch) 
{ 
  if (isalpha(ch))       return LETTER ; 
  else if (isdigit(ch))  return DIGIT  ; 
  else if (ispunct(ch))  return PUNCT  ;    
  else if (isspace(ch))  return SPACE  ; 
  else                   return OTHER  ;           
}     



/* Get a char and act accordingly. */ 
void getch(char ch)
{ 
   switch (testchar(ch))    
   {  
     case LETTER:  puts("Found a letter \n"); break;   
     case DIGIT:   puts("Found a digit \n");  break;    
     case PUNCT:   puts("Found a punctuation character \n");  break;   
     case SPACE:   puts("Found a space \n");  break;          
     default:      puts("Found something else \n"); break; 
   }  
                    
}     

 
/* Our tokenise function. */  
void tok(char *mystr) 
{ 
   int i=0;  
        
   while(*mystr != '\0') 
   { 
     buf[i] = *mystr;
     printf("%c " , buf[i]);  
     printf("%c " , *mystr);       
     getch(buf[i]);      
     mystr++;
     i++;        
   }            
              
}     




int main() 
{ 

 
 char *test = "select * from mytable;" ; 
  
 tok(test);     
                                      
 return 0;
 
 
}  







