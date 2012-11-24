

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

  /* Character. */       
  char c;        
      
  /* Mytok array counter. */ 
  int i=0; 
      	   
  /* Value counter. */       	   
  int j=0; 
   
  while ( c != '\0') 
  { 
    c = str[j]; 	  
	  
	/* Whitespace. */ 
	if ( isspace(c) )  
	{ 
	 while ( isspace(c) )  	
	  {	
	    j++;  
	  } 
	    j=0;   
    } 		  
	  	  
	/* Keyword or colname */ 
	/* Underscore is ascii 95. */ 
	else if ( (isalpha(c) ) || ( c == '_' ) )  
	{ 
	   j=0;	
	   while ( isalpha(c)  || isdigit(c)  
	      || ( c == '_' )  )
	   { 
		  c = str[j]; 	   
		  mytok[i][j] = c; 
		  j++; 
	   }  
	   
	   mytok[i][j] = '\0' ; 
	   /* Reset j. */ 
	   j=0; 	   	   		 
	   /* Increment the token counter. */ 
	   i++; 
	  
    }  /*  Keyword or colname  */ 
    
    
    /* String literals. */ 
    /* Double-quote is ascii 34. */ 
    else if ( ( c == '"' )  )  
    {  
		j=0;	
		 while (  (c != '"' )  )     
		   { 
			 c = str[j]; 	    
		     mytok[i][j] = c ; 
		     j++; 
	       }  
	      mytok[i][j] = '\0' ;         	       
	      /* Reset j. */ 
	      j=0;  	        	  	   
	      /* Increment the token counter. */ 
	      i++; 	       
     } 
	  
	  
	/* Integers */ 
	else if ( (isdigit(c) ) )  
	{ 
	   j=0;		
	   while ( isdigit(c) ) 
	   { 
		 c = str[j]; 	    
		 mytok[i][j] = c; 
		 j++; 
	   }  
	   mytok[i][j] = '\0' ; 
	   /* Reset j. */ 
	   j=0; 	   	         
       /* Increment the token counter. */ 
	   i++; 	             		   	  
	} 
	
	/* Single symbols: ",", "=", ";"  */ 
	/* Comma - ascii 44. */ 
	else if ( ( c == ',' )  )   
	  { 
		 c = str[j]; 	   
		 mytok[i][j] = c ;  
		 j++;
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0;  		 		 		 
		 /* Increment the token counter. */ 
	     i++;		         
	  } 
	  
	  /* Equals sign - ascii 61. */ 
	  else if ( ( c == '=' )  )  
	  { 
		 c = str[j]; 	   
		 mytok[i][j] = c ;  
		 j++; 
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 				 
		 /* Increment the token counter. */ 
	     i++;		 		        
	  } 
	  
	  /* Semicolon - ascii 59. */  
	  else if (  ( c == ';' )  )   
	  { 
		 c = str[j]; 	   
		 mytok[i][j] = c ;  
		 j++; 
		 mytok[i][j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 		
		 /* Increment the token counter. */ 
	     i++;		      
	  } 
	 
	/* Move the pointer. */ 
	j++ ;  
	
	  	  	  
  }  /*  *str != '\0'   */   	     
    
  int k; 
   
   printf("Toktype: %s \n", mytok[0] );    
      
  for(k=0; k<5; k++) 
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


