

/*  lexer5.c  */  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


/* Our buffer to hold the input.  */  
char buf[80] ;    
 
 
/* Test for a single character.  */  
int testchar(char ch1, char ch2) 
{ 
   if (ch1 == ch2) return 1; 
   return 0; 
} 


/* A union for the token value. */ 
typedef union tokval_u { 
      int int_tok;   
      float float_tok; 
      char *string_tok;
      char op_tok; 
} tokval;         


/* Token. It has a type and a value. */ 
typedef struct token_t { 
     char    *toktype; 
     tokval  tokvalue; 
} token;         



/* A helper enum */  
enum chartype { LETTER, DIGIT, SGLQUOTE, DBLQUOTE, STAR, 
   SEMI, SPACE, OTHER };    


/* Helper function */ 
int getchartype(char ch) 
{ 
  if (isalpha(ch))               return LETTER   ; 
  else if (isdigit(ch))          return DIGIT    ; 
  else if (testchar(ch, '\'' ))  return SGLQUOTE ; 
  else if (testchar(ch, '"'  ))  return DBLQUOTE ; 
  else if (testchar(ch, '*'  ))  return STAR     ;   
  else if (testchar(ch, ';'  ))  return SEMI     ;   
  else if (isspace(ch))          return SPACE    ; 
  else                           return OTHER    ;           
}     


/* Function to aggregate chars into a token. */ 
/* E.g. for string, go until maxlen or "     */ 
/* For identifier, go until non-alnum.       */ 
/* For digit, go until non-digit.            */ 
      
char *tokenise(char ch, char endch) 
{ 
   if isalpha(ch) { 
       
   } 
   
   else if isdigit(ch) { 
       
       
   }           
   
   
              
    
   return retval;   
}      
  







/* Get a char and act accordingly. */ 
void getch(char ch)
{ 
   switch (getchartype(ch))    
   {  
     case LETTER:    puts("Found a letter \n");        break;   
     case DIGIT:     puts("Found a digit \n");         break;    
     case SGLQUOTE:  puts("Found a single quote \n");  break;  
     case DBLQUOTE:  puts("Found a double quote \n");  break;       
     case STAR:      puts("Found a star \n");          break;   
     case SEMI:      puts("Found a semicolon \n");     break;   
     case SPACE:     puts("Found a space \n");         break;          
     default:        puts("Found something else \n");  break; 
   }  
                    
}     

 
/* Our tokenise function. */  
void tok(char *mystr) 
{ 
   int i=0;  
        
   while(*mystr != '\0') 
   { 
     buf[i] = *mystr;    
     getch(buf[i]);      
     mystr++;
     i++;        
   }            
              
}     



int main() 
{ 
 
 char *test = "select \"foo\" from test;" ; 
  
 tok(test);     
                                               
 return 0;
 
 
}  


