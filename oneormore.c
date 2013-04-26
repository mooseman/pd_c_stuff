

/*  oneormore.c  */ 

/*  Test input to see the type of chars that it */
/*  is made up of. */
/*  For example -  */ 
/*  abc35*ghj+*+   = a3d2p1a3p3   */  
/*  3 letters, 2 digits, 1 punct, 3 letters, 3 punct. */ 
/*  Spaces can be donoted by s.  */ 


#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h>
#include <ctype.h> 


char *test(char *s, char *c)
{ 
   char *res = strcat(s, c); 	
   
   puts(res); 
   
   return res; 
		
} 	



char *analyse(char *str) 
{ 
 
  char *res = "" ; 
   
  int a, d, p, s; 
  a = d = p = s = 0;  
   
   
  while ( *str != '\0' ) 	
  { 	       	
	  if (!isalpha(*str))  a += 1; test(res, "a") ; 
	  if (!isdigit(*str))  d += 1; test(res, "d") ; 
      if (!ispunct(*str))  p += 1; test(res, "p") ; 
      if (!isspace(*str))  s += 1; test(res, "s") ;             			  	
	  
	   str++; 	  	  
  }
  
  return res;    	  	
		
}	
	 
	 
	 
int main() 
{ 
	
	
char *mystr = "abc35*ghj+*+" ; 

char *a = analyse(mystr); 	
	
printf("Result: %s \n", a) ; 	
		
	
return 0;  	
	
	
} 	
		 
	 
	 
