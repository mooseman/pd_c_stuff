

/*  toysql_lexer.c                                */  
/*  The beginnings of a lexer for "toy SQL".      */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 

/*  Note - use one-char lookahead. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 




  
/* NOTE - need an array of tokens. */     	    

void tokenise(char *str) 
{ 
	
  /* An array of tokens. */ 	
  char mytok[50][80];  
      
  /* Mytok array counter. */ 
  int i=0; 
      	   
  /* Value counter. */       	   
  int j=0; 
   
  while (*str != '\0') 
  { 
	  
	/* Whitespace. */ 
	if ( isspace(*str) )  
	{ 
	   str++;    	
    } 		  
	  	  
	/* Keyword or colname */ 
	else if ( (isalpha(*str) ) || ( !(strcmp( (char*)str, "_")  )  )  )  
	{
	   while ( isalpha(*str)  || isdigit(*str)  
	     || !(strcmp( (char*)str, "_")  )  )
	   { 
		  mytok[i][j] = *str; 
		  j++; 
	   }  
	   
	   mytok[i][j] = '\0' ; 
	   /* Reset j. */ 
	   j=0; 	   	   		 
	   /* Increment the token counter. */ 
	   i++; 
	  
    }  /*  Keyword or colname  */ 
    
    
    /* String literals. */ 
    else if ( !(strcmp( (char*)str, "\"" ) )  )  
    { 
		 while (  (strcmp( (char*)str, "\"" ) )  )     
		   { 
		     mytok[i][j] = *str; 
		     j++; 
	       }  
	      mytok[i][j] = '\0' ;         	       
	      /* Reset j. */ 
	      j=0;  	        	  	   
	      /* Increment the token counter. */ 
	      i++; 	       
     } 
	  
	  
	/* Integers */ 
	else if ( (isdigit(*str) ) )  
	{ 
	   while ( isdigit(*str) ) 
	   { 
		 mytok[i][j] = *str; 
		 j++; 
	   }  
	   mytok[i][j] = '\0' ; 
	   /* Reset j. */ 
	   j=0; 	   	         
       /* Increment the token counter. */ 
	   i++; 	             		   	  
	} 
	
	/* Single symbols: ",", "=", ";"  */ 
	/* Comma. */ 
	else if ( !(strcmp( (char*)str, "," ) )  )   
	  { 
		 mytok[i][j] = *str;  
		 j++;
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0;  		 		 		 
		 /* Increment the token counter. */ 
	     i++;		         
	  } 
	  
	  /* Equals sign. */ 
	  else if ( !(strcmp( (char*)str, "=" ) )  )  
	  { 
		 mytok[i][j] = *str;  
		 j++; 
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 				 
		 /* Increment the token counter. */ 
	     i++;		 		        
	  } 
	  
	  /* Semicolon. */  
	  else if (  !(strcmp( (char*)str, "\"" ) )  )   
	  { 
		 mytok[i][j] = *str;  
		 j++; 
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 		
		 /* Increment the token counter. */ 
	     i++;		      
	  } 
	 
	/* Move the pointer. */ 
	str++;  
	  	  	  
  }  /*  *str != '\0'   */   	     
    
  int k; 
      
  for(k=0; k<50; k++) 
  { 	
     printf("Toktype: %s \n", mytok[k] );      
  }   
	  	       	      		
} 	




int main() 
{ 
  
 
 char *test = "select mycol from test where city = \"Auckland\" ; " ; 
  
 tokenise(test);   
  
                                               
 return 0;
 
 
}  


