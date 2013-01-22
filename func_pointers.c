

/* func_pointers.c  */ 
/* Playing around with function pointers. */ 
/*  This code is released to the public domain.  */  
/*  "Share and enjoy....." ;)   */   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int plus5(int i)
{ 
   return i+5; 
} 


int max(int a, int b) 
{ 
  if (a > b) return a; 
    return b;  
} 


/* Create an object. Then, create a subtype of the object. */ 
/* Each subtype will have a DIFFERENT set of methods.  */ 
/* A list of function pointers is **NOT** a good approach here. */  
/* NOTE - Python and Ruby use hashtables for their objects.  */ 
/* The keys are the names of the members and methods.  */ 
/* The values are POINTERS to the member or method.  */ 

typedef struct fp { 
	char *fname; 
	void * func;  /*  Change this to the correct signature. */ 
	struct fp *next;
} fp_list; 	






int main()
{ 








return 0; 

} 













