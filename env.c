

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


/* To do: work on attr list, val list and */ 
/* method list. */ 



/* Objects. They have a name, type, attributes, values */ 
/* and methods.  */  
/* The methods can be function pointers.  */ 
typedef struct { 
	char *name; 
	char *type;  /* Always "object" */ 
	void *attr_list;
	void *val_list; 	
	void *method_list; 
} obj ; 



int main() 
{ 










return 0; 

} 










      

     
 







