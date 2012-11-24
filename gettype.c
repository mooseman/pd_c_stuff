

/*  gettype.c  */ 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 
	 
	 
#define intlen(x) ( sizeof(x) / sizeof(int) )	 
	 
/* Helper function. */ 
int max(int arr[]) 
{ 
   int m;     
   int i=0;	
   int len = intlen(arr); 
   	
   for (i=0; i<len; i++) 
   { 
	 if (m > arr[i]) m = m ;      
	 else m = arr[i] ; 
	 i++;
	 arr++;  	   
   } 	      
   return m;    	 
} 		 
	 

/* Helper function. */ 
int min(int arr[]) 
{ 
   int m;     
   int i=0;	
   int len = intlen(arr); 
	
   for (i=0; i<len; i++) 
   { 
	 if (m < arr[i]) m = m ;      
	 else m = arr[i] ; 
	 i++;
	 arr++;  	   
   } 	      
   return m;    	 
} 		 



char next(char *str) 
{ 
   char c;    	
   if ( *(str+1) != '\0')  c = *(str+1);     
   return c;  
} 

	




/* Helper function to get the type of a char.     */ 
/* What we mean by "type" here is the "type" that */ 
/* the char can be used to create.  */ 
/* For example: letters, digits, underscores can be used */ 
/* to create keywords or column names. */ 
/* digits can be used to create integers. */ 
/* Single chars are operators of some kind. */ 
/* Double chars are also operators. */   
int type(char c) 
{ 
		  
	 if ( ( isalpha(c) ) || ( c == '_' ) ) return 1; 
	 else if ( ( isdigit(c) ) )            return 2;   
	 else if ( c == (',')  )   return 3;  
	 else if ( c == (';')  )   return 4;  	
	 else if ( c == ('=')  )   return 5;  
	 else if ( c == ('<')  )   return 6;  
	 else if ( c == ('>')  )   return 7;  
	 else if ( c == ('"')  )   return 8;  
	 else if ( c == ('\0') )   return 9;  
     else return 10; 	   
}    	


char *whattype(char *str) 
{ 
  int len = strlen(str) ;		
  int types[len]; 	  
  int i=0; 
	
   while ( *str != '\0' ) 
   { 
      types[i] = type(*str); 
      printf("Types[i]: %d \n", types[i]); 
      i++; 
      str++;
   } 
   
   if ( ( types[0] == 1 ) && max(types) == 2 )  return "kw_colname" ; 
   else if ( (min(types) == 2) && (max(types) == 2) ) return "integer" ; 
   else return "other" ; 
} 




int main() 
{ 


char *str1 = "test_123" ; 
char *type1 = whattype(str1); 

char *str2 = "_123" ; 
char *type2 = whattype(str2); 

char *str3 = "12345" ; 
char *type3 = whattype(str3); 

printf("Type 1: %s \n", type1); 
printf("Type 2: %s \n", type2); 
printf("Type 3: %s \n", type3); 

printf("Next for str1: %c \n", next(str1) );
printf("Next for str2: %c \n", next(str2) );
printf("Next for str3: %c \n", next(str3) );


int arr1[5] = {5, 6, 7, 8, 9};
int arr2[5] = {42, 57, 63, 90, 94};
int m1 = min(arr1); 
int m2 = max(arr1); 
int m3 = min(arr2); 
int m4 = max(arr2); 

printf("Min arr1: %d \n", m1); 
printf("Max arr1: %d \n", m2); 
printf("Min arr2: %d \n", m3); 
printf("Max arr2: %d \n", m4); 

return 0; 


} 





