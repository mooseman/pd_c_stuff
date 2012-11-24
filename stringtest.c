


/* stringtest.c  */ 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 



void chartest(char *str, int i)
{
   printf("Char: %c \n", str[i]); 
} 


void test(char *str) 
{ 
   printf("Char: %c \n",  *str+3); 	
} 	



/* Token */ 
typedef struct { 
	    char *toktype ; 
	    char value[20]; 
} Token; 


Token *maketok(char *str, char val[20]) 
{
   Token *atok; 
   atok = (Token *) malloc(sizeof(Token)); 
   
   atok->toktype = str; 
   memcpy(atok->value, val, 20);   
   return atok;    
		
} 	


void printtok(Token *tok) 
{ 
   printf("Token type: %s \n", tok->toktype) ; 
   printf("Token value: %s \n", tok->value); 		
} 	





int main() 
{ 

char *str = "012345678" ; 

chartest(str, 0); 
chartest(str, 4);
test(str); 

char *str2 = "keyword" ; 
char arr[] = {"select"};  

Token *t ; 
t = maketok(str2, arr); 
printtok(t); 

printf("arr[0] %c \n", arr[0]); 
printf("arr[1] %c \n", arr[1]); 
printf("arr[2] %c \n", arr[2]); 

free(t);  

return 0; 


} 








