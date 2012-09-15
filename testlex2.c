

/* testlex.c  */ 

/* Startswith, endswith funcs. */    
/* Use on current token. */               
/* Keyword - they start and end with a letter. */ 
/* Fieldname - start with letter or underscore, end with letter, number, */ 
/* or underscore, and is not a keyword. */ 
/* String value - starts and ends with double quotes. */  
/* Int value - starts and ends with digit. */ 
/* Op - Single or double character. */        
/* This code is released to the public domain.  */ 
/* "Share and enjoy..... "  ;)    */            



#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 



/* A helper function to test for an underscore.  */ 
int isuscoreoralpha(char ch)  
{ 
   return ( (ch == '_') || isalpha(ch) ) ; 
} 

int isuscoreoralnum(char ch) 
{ 
   return ( (ch == '_') || isalnum(ch) ) ;    
} 


/* See if an array is a valid name.  */ 
int validname(const char* str)
{ 
  int i;   
  int err = 0;   
  int len = strlen(str); 
    
  for (i=0; i<len; i++) 
  {     
     if (!isuscoreoralpha(str[0]) ) 
        { err += 1; 
          break; } 
     else if (!isuscoreoralnum(str[i]) ) 
        { err += 1;       
          break; }                           
  }     
   if (err == 0) return 1; 
   else return -1;
}

  
  
typedef enum toktype { KEYWORD, COLNAME, STRING, PUNCT, OTHER } t_type;   
  
  
t_type lexer(char token[20])
{ 
   /* Find the length of the token. */ 
   int len = strlen(token);  
   t_type t;    
    
   if ( (strcmp(token, "select" ) == 0) 
     || (strcmp(token, "from"   ) == 0) 
     || (strcmp(token, "where"  ) == 0) ) t = KEYWORD ; 
   
   else if ( token[0] == '\"' && token[len] == '\"') t = STRING ; 
   
   else if ( validname(token) )  t = COLNAME ; 
   
   else if ( ispunct(token) )  t = PUNCT ;           
    
   else t = OTHER ;  
   
   return t; 
        
}     



void tokenize(char *data)
{
    
  int i=0; int j=0; 
  char retval[20][80]; 
    
  while ( *data != '\0' )  
  { 
    if (!isspace(*data))  
      { 
         retval[i][j] = *data;       
         data++;   
         j++;         
      } 
      
    else 
      {     
         data++; 
         j=0;        
         i++;       
      } 
      
   retval[i][j] = '\0' ;   
      
  }     
    
  int k;               
  for (k=0; k<9; k++)   
     {   
        int len = strlen(retval[k]);                    
        printf("Token: %s Length: %d Type: %d \n", retval[k], len, lexer(retval[k]) ) ;   
     } 
     
} 

  

  
  
  
  
  
  
void test(char *data)
{ 
    
  /* Our token */ 
  char tok[20] ;  
  int i=0; 
   
  if ( isalpha(*data) ||  *data == '_' ) 
     { 
       while ( isalnum(*data) || *data == '_' ) 
        { 
          tok[i] = *data; 
          i++; 
          data++; 
        } 
     }   
     
   else data++;    

  printf("Token: %s \n", tok) ;   

} 


void test2(char *data) 
{  
  
  /* Our token */ 
  char tok2[20] ;  
  int i=0;   
   
  while ( *data != '\0' )  
  { 
    data++;   
    if ( *data == '\'' ) 
      {    
        data++;               
        while ( *data != '\'' )           
        { 
          tok2[i] = *data;           
          data++; 
          i++; 
        }         
        break;               
      }             
  } 
   
  tok2[i] = '\0' ;      
  printf("Token: %s \n", tok2) ;   

} 



void test3(char *data) 
{ 
  printf("Data: %s \n", data); 
  printf("*data: %c \n", *data); 
  
  data+=3;
  printf("Data: %s \n", data); 
  printf("*data: %c \n", *data); 
         
}     






int main() 
{ 
 
 char *str = "select * from mytable where city = 'Auckland' ;" ; 
 
 test(str) ;    
 
 test2(str);      
 
 test3(str);       
 
 tokenize(str); 
                        
 return 0;
 
 
}  











