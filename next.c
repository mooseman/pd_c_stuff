

/*  next.c  */ 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


typedef struct t { 
    int foo ; 
    char *bar ; 
    char baz ; 
}  thing ; 


int first(thing t) 
{ 
   return t.foo;
} 
    
    
char *second(thing t) 
{ 
   return t.bar;
} 
    
    
char third(thing t) 
{
   return t.baz;     
}     
    
    
    
int main() 
{ 

thing t;  
t.foo = 42; 
t.bar = "A string..." ; 
t.baz = '*' ; 

int a = first(t);
char *b = second(t); 
char c = third(t); 

printf("First - %d \n", a); 
printf("Second - %s \n", b); 
printf("Third - %c \n", c);  


return 0; 

} 
    






