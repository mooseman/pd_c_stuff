

/*  search.c  */ 

/*  Function to search an array of strings */
/*  to find a given string. */ 

/*  This code is released to the public domain. */ 
/*  "Share and enjoy...."  :)    */ 


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 



/* Array of strings. */ 
char *kw_strings[] = { 
   "select", "from", "where", "and", "or", "not", "in", "is", "null" 
    } ; 
   
    
/*  Search function.  */ 
int search(char *arr[], int dim, char *str) { 
	
	int i; 	 	
	int found_match;
	
	for (i=0; i<dim; i++) { 
		if ( !strcmp(arr[i] , str ) )  {   
	        found_match = 1;		
	        break; 
    }   else found_match = 0;    
 }  /* For */     

    return found_match; 
}  /* search */ 



int main() { 
 
  int i = search(kw_strings, 9, "select") ;   
  
  int j = search(kw_strings, 9, "from") ;   
  
  int k = search(kw_strings, 9, "null") ;   
  
  int l = search(kw_strings, 9, "foobar") ; 
  
  int m = search(kw_strings, 9, "I like moose") ; 
 
  printf("%d %d %d %d %d \n", i,j,k,l,m); 
        
  return 0; 
    
} 







