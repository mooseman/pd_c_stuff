


/*  keyseq.c                                              */  
/*  Code to get the sequence of codes for keys.           */ 
/*  Very useful for getting codes for keys with           */ 
/*  more than one character (e.g. arrow keys)             */ 
/*  This code is released to the public domain.           */  
/*  "Share and enjoy....... "  ;)                         */   
  

#include <string.h>  
#include <stdio.h> 
#include <stdlib.h>  
#include <termios.h>  


/* Getch() from here - */ 
/* http://wesley.vidiqatch.org/   */ 
/* Thanks, Wesley!   */  
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void) {
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
    return getch_(1);
} 


/* A struct to hold key sequence data. */ 
struct keyseq { 
	int ctrl;      
    int shf; 
    int esc;  
    int lbrack;
    int del;
    int key;     
} ;



/* Create a new struct and set it to NULL. */ 
struct keyseq *k = NULL; 

	    
/* Print the struct data. */ 
void print_seq(struct keyseq *k)
{    
    printf( "k->ctrl = %d\n",   (k->ctrl) );   		 		
	printf( "k->shf  = %d\n",   (k->shf) );   		 		
	printf( "k->esc = %d\n",    (k->esc) );   		 		
	printf( "k->lbrack = %d\n", (k->lbrack) );   		 		
	printf( "k->del = %d\n",    (k->del) );   		 		
	printf( "k->key = %d\n",    (k->key) );   		 		
	    
}




/* Function to add data to struct.  */ 
void add_data(struct keyseq *k, int i) 
{  
	
  /* Clear existing flags */ 
  k->ctrl = k->del = k->esc = k->key = k->lbrack = k->shf = 0; 		
			
            
  switch (i)
	{
	   case  1 ... 27:  k->key = i;  break;	   
	   case 32 ... 127: k->key = i;  break;       
       default:                      break; 
    }           
                        
            					
  /* Set flags.  */  
  switch (i)
	{
	   case  1 ... 26:  k->ctrl = 1;    break;
	   case 27:         k->esc = 1;     break;	   
       case 65 ... 90:  k->shf = 1;     break;
       case 91:         k->lbrack = 1;  break;       
       case 127:        k->del = 1;     break;
       default:                         break; 
    } 
				     
     print_seq(k); 	
       	   	
} 		
		
	

/*  Call the add_data function while we have data to add. */ 
void run( char (*func)(void) )     
{ 
   
   char c = func() ; 	   	
	
   while(c != '\0') 
   {    	
	  add_data(k, c) ; 	
   }
	
   print_seq(k); 	
	
} 	
	
	
	
	
			    

int main() 
{ 



 while(1) 
 { 
         
   int c = getch() ;  
    
   add_data(k, c); 
                
            
 } 
 

  
return 0; 


} 














