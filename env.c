

/*  env.c  */ 
/*  An environment with objects and variables */ 
/*  that can be queried.  */ 
/*  This code is released to the public domain.  */  
/*  "Share and enjoy....." ;)   */   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* A union.  */ 
typedef union { 
    int i; 
    char *str; 
    float f; 
    char c; 
} u; 


/* Variables  */ 
typedef struct { 
    char *name; 
    char *type; 
    u  value; 
} var;  


/* Environment.  */ 
typedef struct {  
    var  *v; 
    var  *next;  
} env; 




int main() 
{ 










return 0; 

} 










      

     
 







