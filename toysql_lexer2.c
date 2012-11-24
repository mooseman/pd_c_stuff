

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


/* Token */ 
typedef struct { 
	    char *toktype ; 
	    char value[20]; 
} Token[50]; 



  
/* NOTE - need an array of tokens - not just one. */     	    

Token *tokenise(char *str) 
{ 
	
  /* An array of tokens. */ 	
  Token *mytok;  
  
 /*  mytok =  malloc(sizeof(Token) * 50 ) ;   */ 
  /* Mytok array counter. */ 
  int i=0; 
      	   
  /* Value counter. */       	   
  int j=0; 
   
  /* Char.  */ 
  char c;  
   
  while (c != '\0') 
  { 
	 c = str[j] ;   
	  
	  
	/* Whitespace. */ 
	if ( isspace(c) )  
	{ 
	   j++;    	
    } 		  
	  	  
	/* Keyword or colname */ 
	else if ( (isalpha(c) ) || ( c == '_' )  )
	{
	   while ( isalpha(c)  || isdigit(c)  
	     || ( c == '_' )  )   
	   { 
		  c = str[j] ;    
		  mytok[i]->value[j] = c; 
		  j++; 
	   }  
	   
	   mytok[i]->value[j] = '\0' ; 
	   /* Reset j. */ 
	   j=0; 
	   	   
	   /* Now check the value of the token. */ 
	   if ( (!strcmp(mytok[i]->value, "select") )  ) mytok[i]->toktype = "T_SELECT" ; 
     else if ( (!strcmp(mytok[i]->value, "from") )  ) mytok[i]->toktype = "T_FROM" ; 	   	       
	 else if ( (!strcmp(mytok[i]->value, "where") )  ) mytok[i]->toktype = "T_WHERE" ;  
	 else mytok[i]->toktype = "T_COLNAME" ; 	
	 
	 /* Increment the token counter. */ 
	 i++; 
	  
    }  /*  Keyword or colname  */ 
    
    
    /* String literals. */ 
    else if (  c == '"' )  
    { 
		 while (  ( c != '"' )  )     
		   { 
			 c = str[j] ;     
		     mytok[i]->value[j] = c ; 
		     j++; 
	       }  
	      mytok[i]->value[j] = '\0' ;   
      	        
	      /* Reset j. */ 
	      j=0;  	        	  
	      mytok[i]->toktype = "T_STRLIT" ; 	      
	      /* Increment the token counter. */ 
	      i++; 	       
     } 
	  
	  
	/* Integers */ 
	else if ( (isdigit(c) ) )  
	{ 
	   while ( isdigit(c) ) 
	   { 
		 c = str[j] ;     
		 mytok[i]->value[j] = c ; 
		 j++; 
	   }  
	   mytok[i]->value[j] = '\0' ; 
	   /* Reset j. */ 
	    j=0; 	   	  
        mytok[i]->toktype = "T_INTEGER" ;  
        /* Increment the token counter. */ 
	    i++; 	             		   	  
	} 
	
	/* Single symbols: ",", "=", ";"  */ 
	/* Comma. */ 
	else if ( ( c == ',' )  )   
	  { 
		 c = str[j] ;    
		 mytok[i]->value[j] = c ;  
		 j++;
		 mytok[i]->value[j] = '\0' ; 
		 /* Reset j. */ 
	     j=0;  		 		 
		 mytok[i]->toktype = "T_COMMA" ;     
		 /* Increment the token counter. */ 
	     i++;		         
	  } 
	  
	  /* Equals sign. */ 
	  else if ( ( c == '=' )  )  
	  { 
		 c = str[j] ;    
		 mytok[i]->value[j] = c ;  
		 j++; 
		 mytok[i]->value[j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 		
		 mytok[i]->toktype = "T_EQUALS" ;  
		 /* Increment the token counter. */ 
	     i++;		 		        
	  } 
	  
	  /* Semicolon. */  
	  else if (  ( c == ';' )  )   
	  { 
		 c = str[j] ;    
		 mytok[i]->value[j] = c ;  
		 j++; 
		 mytok[i]->value[j] = '\0' ; 
		 /* Reset j. */ 
	     j=0; 		 
		 mytok[i]->toktype = "T_SEMI" ;    
		 /* Increment the token counter. */ 
	     i++;		      
	  } 
	 
	/* Move the pointer. */ 
	j++;  
	  	  	  
  }  /*  *str != '\0'   */   	     
    	    
  return mytok;  
				
} 	




int main() 
{ 
 
 /* Array of tokens. */ 
 Token *atok; 
 
 char *test = "select mycol from test where city = \"Auckland\" ; " ; 
  
 atok = tokenise(test);   
 
 int i;  
 
 for ( i=0; i<50; i++) 
   { 
      printf("Toktype: %s \n", atok[i]->toktype); 
      printf("Value: %s \n", atok[i]->value); 
   } 
 
 free(atok) ;   
                                               
 return 0;
 
 
}  


