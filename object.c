

/*  object.c  */ 




#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 


/* The type of a value.  */ 
typedef union type { 
        char *s ; 
        char  c ; 
        int   i ; 
} t;  


/*  Attributes for an "object" */ 
typedef struct attr { 
	    char *aname ; 
	    t  value ; 
} a; 	     


/* attr myattrarray[10];   */ 


/*  An "object".  */ 

typedef struct object { 	   
	    a arr[10] ; 
} o;   
 


/* Create an instance of an object */ 
o myobj ;   

int foo = 123 ; 

char *mystr = "Just a test..." ; 

char ch = '5' ; 	




int main() 
{ 
	
			
/* Define an object. */ 

o.arr[0].value.s = mystr ;    

o.arr[0].value.i = foo ; 

o.arr[0].value.c = ch ; 
  

printf("o.arr[0].value.s: %s \n", o.arr[0].value.s ); 
printf("o.arr[0].value.i: %i \n", o.arr[0].value.i ); 
printf("o.arr[0].value.c: %c \n", o.arr[0].value.c ); 
	
	
return 0; 	

} 	
	
	
	
	
	


	              
         
         
        


