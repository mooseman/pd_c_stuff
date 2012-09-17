

/*  toysql_lexer.c                                */  
/*  The beginnings of a lexer for "toy SQL".      */ 
/*  This code is released to the public domain.   */ 
/*  "Share and enjoy...."  ;)                     */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <malloc.h> 
#include <stdbool.h> 


char *toks[] = { "select", "from", "where", "and", 
  "or", "not", "in", "=", "<", ">", "<=", ">=", "!=", 
  "\"", ",", ";" }; 

/* This enum includes tokens for ints, string literals */ 
/* and variable (column) names. */ 
enum Toktype { TOK_SELECT, TOK_FROM, TOK_WHERE, TOK_AND, 
  TOK_IN, TOK_INT, TOK_STRING, TOK_COLNAME, TOK_EQ, TOK_LT, 
  TOK_GT, TOK_LE, TOK_GE, TOK_NE, TOK_DBLQUOTE, TOK_COMMA, 
  TOK_SEMI, TOK_EOF };    
   
    
/* Types. */ 
/* These are the broad category types of tokens.             */ 
/* They are used to narrow down the token type, like this -  */ 
/*   if type == T_KEYWORD                                    */ 
/* { if tok == "select" ( toktype = TOK_SELECT )             */  
/* Later on, the T_INT and T_STRING types will be used for   */  
/* doing functions.                                          */          
enum Type { T_INT, T_STRING, T_KEYWORD, T_COLNAME, T_SYM }; 

/* Value */ 
typedef struct Value { 
	    enum Type type;           /* Broad category of token. */ 
	    enum Toktype tokentype;   /* The exact token type.    */ 
	    union  { 
			     int integer; 
			     char *string; 
			   } v;               /* The token value. */   
} Value; 


/* Lexer */ 
/* ( Look at including a token-buffer and stream-buffer here. ) */ 
struct lexer { 
	    FILE *fname; 
	    int colnum; 
	    int linenum; 	   
	    Value *val;    /* As defined above. */ 
} ;    	    











int main() 
{ 
 
 
 
 
 
 
 
 
 
 
 char *test = "select \"foo\" from test;" ; 
  
 /* tok(test);   */   
                                               
 return 0;
 
 
}  


