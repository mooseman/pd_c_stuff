


/*  keyseq.c                                      */  
/*  Code to get the sequence of codes for keys.   */ 
/*  Useful for getting codes for keys with        */ 
/*  more than one character (e.g. arrow keys)     */ 
/*  This code is released to the public domain.   */  
/*  "Share and enjoy....... "  ;)                 */   
  

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



/* An array to hold key sequence data. */ 
int keys[8] ;  

	
void clear_keys(int keys[8]) 
{  
   int i; 
   
   for (i=0; i<8; i++)
   {
	  keys[i] = 0; 
   } 	
		
} 		
	
	    
void add_data(int keys[8], int i, int data)
{       	   
   keys[i] = data; 
} 	

	    
	    
	    
/* Print the keys data. */ 
void print_keys(int keys[8])
{  
   int i; 
   
   for (i=0; i<8; i++)
   {
	  printf("Key %d is %d \n", i, keys[i]) ;   
   }  	   	

}




/* Function to add data to keys array.  */ 
void test(int keys[8]) 
{  
  puts("Press Ctrl-C to quit...."); 	
  puts("Press Ctrl-D to show keys...."); 	 	
	
  /* Clear existing flags */ 
  clear_keys(keys) ; 
    
			
  int c = getch();  	
	
  int i=0;	
	
  while( (c != 4 )  )	/* Ctrl-D */ 
  { 	  	  
	 add_data(keys, i, c);  	
	 printf("Added %d \n", c);  
	 i++;
     c = getch(); 	     
  }	
  	        
  print_keys(keys);  
  
}   	    
	   
	
				    

int main() 
{ 


/* Create a new list and set it to NULL. */ 
int mykeys[8] ; 

 while(1) 
 {                 
   test(mykeys) ;                             
 } 
 
  
return 0; 


} 














