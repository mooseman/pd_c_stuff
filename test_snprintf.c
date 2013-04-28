

/*  test_snprintf.c  */ 




#include <string.h>  
#include <stdio.h> 
#include <stdlib.h>  



int main() 
{

int a = 97 ; 

char b[3]  ; 

snprintf(b, 3, "%c", a); 

puts(b); 


return 0;  

} 




