

/* union.c  */ 
/* Playing around with unions. */ 
/*  This code is released to the public domain.  */  
/*  "Share and enjoy....." ;)   */   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef union { 
    int i; 
    char *str; 
    float f; 
} test; 




int main()
{ 

test t; 

t.i = 123 ; 
printf("%d \n", t.i); 

t.str = "Just a test...." ; 
printf("%s \n", t.str); 

t.f = 23.42 ; 
printf("%f \n", t.f); 


return 0 ; 

} 




    
