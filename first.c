

/* first.c  */  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 
#include <stddef.h> 


/* Print the first char of each token. */ 
void first(char *str) 
{ 
  char ret;   
  /* We use toknum for the case where we are at the start        */ 
  /* of the string and it has NO whitespace before it.           */ 
  /* In other words, a string like "foo" ( rather than " foo" ). */     
  int toknum = 0; 
  
  char *next = str + 1; 
  char *prev = str - 1;   
        
  while ( *str != '\0' ) 
  {       
     if ( !isspace(*str) && (isspace(*prev) || toknum == 0) ) 
             { toknum++; ret = *str;  printf("%c \n", ret);  }          
     str++;
     next++;
     prev++; 
  }      
             
} 


/* Print the first char of each token. */ 
char *first2(char *str) 
{ 
  char *ret = malloc(80);   
  /* We use toknum for the case where we are at the start        */ 
  /* of the string and it has NO whitespace before it.           */ 
  /* In other words, a string like "foo" ( rather than " foo" ). */     
  int toknum = 0; 
  
  char *next = str + 1; 
  char *prev = str - 1;  
        
  while ( *str != '\0' ) 
  {       
     if ( !isspace(*str) && (isspace(*prev) || toknum == 0) ) 
             { ret[toknum] = *str; toknum++;  }          
     str++;
     next++;
     prev++;  
  }      
   
  ret[toknum] = '\0' ;            
  return ret;          
             
} 




int main() 
{ 
 
 char *test = "select * from mytable where city = \"Auckland\" ;" ;                
 first(test) ; 
 
 char *test2 = first2(test); 
 printf("%s \n", test2); 
 
 free(test2); 
 
 return 0;
 
 
}  



