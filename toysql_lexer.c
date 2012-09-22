

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


char *toks[] = { "select", "from", "where", "and", 
  "or", "not", "in", "=", "<", ">", "<=", ">=", "!=", 
  "\"", ",", "(", ")", ";" }; 

/* This enum includes tokens for ints, string literals */ 
/* and variable (column) names. */ 
enum Toktype { TOK_SELECT, TOK_FROM, TOK_WHERE, TOK_AND, 
  TOK_IN, TOK_INT, TOK_STRING, TOK_COLNAME, TOK_EQ, TOK_LT, 
  TOK_GT, TOK_LE, TOK_GE, TOK_NE, TOK_DBLQUOTE, TOK_COMMA, 
  TOK_LPAREN, TOK_RPAREN, TOK_SEMI, TOK_EOF };    
   
    
/* Types. */ 
/* These are the broad category types of tokens.             */ 
/* They are used to narrow down the token type, like this -  */ 
/*   if type == T_KEYWORD                                    */ 
/* { if tok == "select" ( toktype = TOK_SELECT )             */  
/* Later on, the T_INT and T_STRING types will be used for   */  
/* doing functions.                                          */          
enum Type { T_INT, T_STRLIT, T_KWCOLNAME, T_SYM1, T_SYM2, 
     T_LPAREN, T_RPAREN, T_ERROR }; 

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
struct lexer { 
	    FILE *fname; 
	    char tokbuf[40];     /* Token buffer.  */   
	    char strbuf[1024];   /* Stream buffer. */ 	    
	    Value *val;          /* As defined above. */ 
} ;    	    


/* Look at the first char (or two) of a token.   */ 
/* Lexing rules -                                */ 
/* Char is a single char -                       */ 
/*      token is a symbol or operator.           */ 
/* Char is a double-char -                       */  
/*      token is a symbol or operator.           */   
/* Char is a letter or underscore -              */  
/*      token is a keyword or col name.          */    
/* Char is an integer -                          */ 
/*      token is an integer.                     */ 
/* Char is a double-quote -                      */ 
/*      token is a string-literal.               */  
/* Char is a left-paren -                        */ 
/*      start of value list for                  */ 
/*      "in-statement" or start of a             */ 
/*      paren-clause.                            */      
/* Char is a right-paren -                       */ 
/*      end of value list for                    */ 
/*      "in-statement" or end of a               */ 
/*      paren-clause.                            */      

/* Fchar function. */ 
/* Use this to call the tokenise function. */ 
/* Fchar looks at the first character of a token and */ 
/* uses that to determine how to call the tokenise function. */ 
/* For example:  */ 
/* fchar(let_uscore)  ->   tokenise(kw_colname)  */ 
/* fchar(dblquote)    ->   tokenise(strlit)      */ 
/* The tokenise function extracts characters until the first */ 
/* character that is NOT the type of the character it is called */ 
/* with (or until it reaches EOF). */  
/* Finally, the tokenise function returns the token. */  
/* The token is then used by the parser (not shown here).  */ 
   

void fchar(chartype) 
{
   switch(chartype)
    {
      case (singlechar):  tokenise(sym_op1) ;  
      case (dblchar):     tokenise(sym_op2) ;  
      case (let_uscore):  tokenise(kw_colname) ;  
      case (integer):     tokenise(integer) ;  
      case (dblquote):    tokenise(strlit) ;  
      case (leftparen):   tokenise(lparen) ;   
      case (rightparen):  tokenise(rparen) ;  
      default:            tokenise(error)  ; 
    }
    
}       


Toktype tokenise(enum Type) 
{ 
	
  switch(Type)  
  { 
	case (T_SYM1):     
	  	 	  
	  
  } 	   	
	
  	
	
			
} 	






int main() 
{ 
 
 
 
 
 
 
 
 
 
 
 char *test = "select \"foo\" from test;" ; 
  
 /* tok(test);   */   
                                               
 return 0;
 
 
}  


