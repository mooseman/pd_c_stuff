

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


/* To do: work on attr list and method list. */ 

/* Attr list. Attribute names and their values. */ 
typedef struct attr { 
	char *attr_name;
	u attr_value    
    struct attr *next;   
} attr_list;

	 

/* Method list.  */ 
/* This will be a list of method names and their */ 
/* function pointers (it isn't yet). */ 
typedef struct meth { 
	char *methodname; 
	void *methodfuncptr;  
	struct meth *next; 
} method_list; 	



/* Objects. They have a name, type, attributes, values */ 
/* and methods.  */  
/* The methods can be function pointers.  */ 
typedef struct { 
	char *name; 
	char *type;  /* Always "object" */ 
	attr_list a_list; 	
	method_list m_list; 
} obj ; 



int main() 
{ 










return 0; 

} 










      

     
 







