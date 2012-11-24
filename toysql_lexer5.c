

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
} Token; 


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
	
  /* NOTE - column names can have letters, digits or */ 
  /* underscores. We separate the digit test out so that */ 
  /* in order for a char to fit the column-name pattern, */ 
  /* the test will simply be - */ 
  /* while ( (type == 1) || (type == 2) )   */   	
   if ( ( isalpha(c) ) || ( c == '_' ) ) return 1; 
	 else if ( ( isdigit(c) ) )                return 2;   
	 else if ( c == (',')  )   return 3;  
	 else if ( c == (';')  )   return 4;  
	 else if ( c == ('"')  )   return 5;  
	 else if ( c == ('=')  )   return 6;  
	 else if ( c == ('<')  )  return 7;  
	 else if ( c == ('>')  )   return 8;  
	 else if ( c == ('\0') )   return 9;  
     else return 10; 	   	
	   	   
}    	
	

/* Function to map char type to token type. */ 

/* while c is alpha, digit, underscore - */ 
/*   - append to value array.  */ 
/*   - token type = keyword or colname.  */ 
/* while c is digit - */ 
/*   - append to token array */ 
/*   - token type is integer. */ 
/* while c is single-op (=, ',', ';') */ 
/*   - append to token array. */ 
/*   - token type is '=', ',', ';'  */        
 
Token *maketok(char c) 
{ 
   Token *tok; 
   tok = (Token *) malloc(sizeof(Token)); 
   
   int t = type(c); 
   
   int i=0; 
         
   while( ( t == 1 ) || ( t == 2 )  ) 
   { 
	  {  
		 t = type(c);  
		 tok->value[i] = c;  
		 i++;  
	  } 
	    /* Now check the value of the token. */ 
	      if ( (!strcmp(tok->value, "select") )  ) tok->toktype = "T_SELECT" ; 
     else if ( (!strcmp(tok->value, "from") )  )   tok->toktype = "T_FROM" ; 	   	       
	 else if ( (!strcmp(tok->value, "where") )  )  tok->toktype = "T_WHERE" ;  
	 else tok->toktype = "T_COLNAME" ; 
	 tok->value[i] = '\0' ; 	 
	 i=0;  	 
	 printf("Tok->type:  %s \n", tok->toktype); 
	 printf("Tok->value: %s \n", tok->value); 	
   } 		  	
	
	   
   while( t == 2 ) 
   { 
	  { 
		 t = type(c);  
		 tok->value[i] = c;  
		 i++;  
      } 
      tok->toktype = "T_INTEGER" ;    
      tok->value[i] = '\0' ; 	 
	  i=0;  	  
	  printf("Tok->type:  %s \n", tok->toktype); 
	  printf("Tok->value: %s \n", tok->value); 	 		  
   } 
   
   return tok; 
		 
} 	 




/*  Lexer. This has buffers and indexes for tokens and */ 
/*  the string being lexed. */ 
typedef struct { 
	    char c; 
	    char tokarray[50];  
	    char *toktype; 
	    int tokindex;	   
	    char tokval[20]; 
	    int stmtindex; 
	    char stmtarray[200];  
} Lex; 

  
  
/* NOTE - need an array of tokens. */     	    

void tokenise(char *str) 
{ 
	
  /* Token *atok; 
  atok = (Token *) malloc(sizeof(Token));  */ 
  
  Lex *lexer; 
  lexer = (Lex *) malloc(sizeof(Lex)); 
   
  /* Initialise the lexer. */ 
  lexer->tokindex = 0; 
  lexer->stmtindex = 0; 
  lexer->c = str[lexer->stmtindex]; 
   
  char c = str[0] ;  
           
  while ( c != '\0') 
  { 
	c = str[lexer->stmtindex];    
    lexer->c = str[lexer->stmtindex];      	  		
	maketok(lexer->c); 	
	lexer->stmtindex++ ;
	
  }  /*  *str != '\0'   */   	     
          	  	       	      		
} 	




int main() 
{ 
  
 char *test = "select foo" ;   
 tokenise(test);   
                                               
 return 0;
 
 
}  


