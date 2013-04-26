

/*  seq.c  */ 
/* Sequences of types.  */ 



#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 



/* Return the chartype of a char. */ 
int alpha(int c) 
{        
   return isalpha(c) ;   
} 


int digit(int c)
{
   return isdigit(c) ;   
}


int punct(int c)
{
   return ispunct(c) ;   
}


int space(int c)
{
   return isspace(c) ;   
}


char type(char c)
{ 
   char ret; 		
   
        if ( isalpha(c) ) ret = 'a' ; 
   else if ( isdigit(c) ) ret = 'd' ;  
   else if ( ispunct(c) ) ret = 'p' ;  
   else if ( isspace(c) ) ret = 's' ;  
   
   return ret; 

} 



typedef struct foo { 
       char c; 
       char (*myfuncptr)(char) ;  /* Func pointer returning a char */ 
} a_foo ;  



/*  Sequence function.  */  
/*  Sequences of foos, each with their type.  */ 
 




int main() 
{ 


int a = alpha('h') ; 
printf("Result: %d \n",  a )  ;  

char z = type('h') ; 
printf("Result: %c \n",  z )  ;  

char q = type('5') ; 
printf("Result: %c \n",  q )  ;  

char r = type('#') ; 
printf("Result: %c \n",  r )  ;  

char t = type(' ') ; 
printf("Result: %c \n",  t )  ;  




int b = alpha('5') ; 
printf("Result: %d \n",  b )  ;  

int c = digit('5') ; 
printf("Result: %d \n",  c )  ;  

int d = digit('a') ; 
printf("Result: %d \n",  d )  ;  

int e = punct('*') ; 
printf("Result: %d \n",  e )  ;  

int f = punct('8') ; 
printf("Result: %d \n",  f )  ;  

int g = space(' ') ; 
printf("Result: %d \n",  g )  ;  

int h = space('@') ; 
printf("Result: %d \n",  h )  ;  



return 0; 

} 









