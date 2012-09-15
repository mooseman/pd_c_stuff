


/*  str2array.c                                   */ 
/*  Put the contents of a string into an array.   */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */  


#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>


/* Get length of string. Create array of that length. */ 
/* Copy contents into the array.                      */ 
void str2array(char *str)
{ 
  int len = strlen(str); 
  
/* Strlen does not include the null-terminator, so we */ 
/* make the array 1 char longer to include it. */   
  char arr[len+1]; 
  memcpy(arr, str, len+1);  
  puts(arr);   
} 


char *test(char str[])
{ 
  return str ; 
}   



int main()
{ 

char *foo = "This is a test" ; 

str2array(foo); 

char bar[10] = "Test" ;  

puts(test(bar)); 

return 0; 

} 




