
/*  test2.c  */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 

/*  Note - use one-char lookahead. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 



void test(char *str) 
{ 
  char ret;               
  while ( *str != '\0' ) 
  {  
	 ret = *str;        
     printf("Str: %s \n", str); 
     printf("Ret: %c \n", ret);         
     str++;      
  }      
} 


/* Lookahead by n chars */ 
void lookahead(char *str1, int n)
{  
   char ch1, ch2; 
   char ch3[3] ; 
   char *str2;    
   /* Lookahead n chars */ 		
   str2 = str1 + n;    
   ch1 = *str1; 
   ch2 = *str2;    
   printf("Ch1: %c Ch2: %c \n", ch1, ch2); 	
   ch3[0] = ch1;  
   ch3[1] = ch2; 
   ch3[2] = '\0' ;    	 
   printf("ch3: %s \n", ch3); 	
} 	


/* Extract the first n chars from string. */ 
/* Easier to use this rather than use strncpy directly. */ 
void firstn(char *str, int n) 
{ 
   char ret[n+1]; 
   strncpy(ret, str, n); 
   ret[n] = '\0' ;     	
   printf("Ret: %s \n", ret) ; 				
} 	


char *firstn2(char *str, int n) 
{ 
   char *ret = malloc(n+1) ; 
   strncpy(ret, str, n); 
   ret[n] = '\0' ; 
   return ret;      
} 	



/*  Get a substring starting at s, of length l. */  
void substr(char *str, int s, int l) 
{ 
   char ret[l+1]; 
   char *str2;
   str2 = str + s; 
   
   strncpy(ret, str2, l); 
   ret[l] = '\0' ;     	
   printf("Ret: %s \n", ret) ; 				
} 	


typedef enum  { T_INT, T_STRLIT, T_KEYWORD, T_COLNAME, 
     T_TABLENAME, T_SYM1, T_SYM2, T_LPAREN, T_RPAREN, T_ERROR } 
       Type; 


char *gettype(char *str) 
{ 
   char *type = NULL; 
   	
	    if (isalpha(*str) )  type = "str" ; 
   else if (isdigit(*str) )  type = "digit" ; 
   else if (ispunct(*str) )  type = "punct" ; 
   else if (isspace(*str) )  type = "ws" ; 
   else type = "other" ; 		
   return type; 		
} 	



void test2(char *str) 
{    
    
  /* Get the types */ 
  char *typestr = NULL ; 
  while ( *str != '\0' ) 
  { 
	typestr = gettype(str);    	
	printf("Type is %s \n", typestr);          		        
    str++ ;  
  }  	    
  	
} 	






/* Function showing when the type of character changes */ 
/* while moving along a string. */ 
void charchange(char *str) 
{    
  char *next = NULL; 
  next = str + 1;   
  
  /* Get the types */ 
  char *typestr = NULL ; 
  char *typestr1 = NULL ;       
  int comp ;  /* comparison flag  */  
  
           
  while ( *next != '\0' ) 
  {  
	typestr = gettype(str); 
    typestr1 = gettype(next);      
	comp = strcmp(typestr, typestr1); 
	if (  comp != 0  )  
	   {
		    printf("Type now is %s, changing to %s \n", 
		        typestr, typestr1); 
       }  		        
    str++ ; 
    next++ ; 	    
  }  	    
  	
} 	



int main() 
{ 
   
 
char *foo = "select col1 from test where city = \"Auckland\" ;" ; 
/* test(foo);  */ 

lookahead(foo, 1); 
lookahead(foo, 2); 
lookahead(foo, 3); 

firstn(foo, 5);    
char *str = firstn2(foo, 5);  
printf("First 5 chars of foo: %s \n", str); 
free(str); 

substr(foo, 3, 3); 

char *bar; 
bar = gettype("test");  
puts(bar); 

char *baz; 
baz = gettype("*"); 
puts(baz); 

/* test2(foo);   */  

charchange(foo);  
   
                                             
return 0;
  
}  






