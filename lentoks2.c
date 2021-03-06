

/* lentoks.c  */  

/* Return the length of tokens in a string.  */ 
/* This code is released to the public domain.     */ 
/* "Share and enjoy...."  ;)    */  


#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 


/*  A union for token values.  */ 
typedef union tok_v { 
       char  *string_val; 
       int   int_val; 
       float float_val; 
       char  char_val;       
} token_v;    


/*  Tokens  */  
typedef struct tok_t { 
     char     *type; 
     token_v  value;             
} token_t;   




void lentoks(char *str) 
{ 
  /* Token text */ 
  char *tok = malloc(80);             
                 
  /* Token length */ 
  int toklen=0;    
  
  /* Token number */ 
  int toknum=0; 
            
  char *next; 
  next = str + 1;          
            
  while ( *str != '\0' ) 
  {                      
     if ( *str != ' ' )               
     {  tok[toklen] = *str;      
        toklen++;                              
        if ( ( *next == ' ' ) || ( next == '\0' ) ) 
           {  toknum++;           
              tok[toklen] = '\0' ;      
              printf("Token %d (%s) is %d long. \n", toknum, tok, toklen);  }         
        str++;         
        next++;              
     } 
     else if ( *str == ' ' ) 
     {  
        toklen=0;                  
        str++;         
        next++;              
     }   
  }  
 
  free(tok);      
    
} 




int main() 
{ 
 
 char *test = "  The quick brown fox   "; 
 char *test2 = "  select * from mytable where city = \"Auckland\" ; " ;          
          
 lentoks(test) ;   
 lentoks(test2) ;   
                                   
 return 0;
 
}  


