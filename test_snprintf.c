

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

int c[5] ; 
c[0] = 97; 
c[1] = 98;
c[2] = 99; 
c[3] = 100; 
c[4] = 101; 

char d[5][3] ; 

int i; 

for(i=0; i<5; i++) 
{ 
  snprintf(d[i], 3, "%c", c[i]);    	
} 	 


for(i=0; i<5; i++) 
{ 
  puts(d[i]);  
}


return 0;  

} 




