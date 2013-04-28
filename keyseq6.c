


/*  keyseq6.c                                      */  
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
char keys[8][3];  

	
void clear_keys(char keys[8][3]) 
{  
   int i; 
   
   for (i=0; i<7; i++)
   { 
	  snprintf(keys[i], 3, "%c", 0);    	  
   } 	
		
} 		
	 
	    
void add_data(char keys[8][3], int i, int a)
{       	   
   /* keys[i] = str; */ 
   snprintf(keys[i], 3, "%c", a); 	
} 	

	    
	    
	    
/* Print the keys data. */ 
void print_keys(char keys[8][3])
{  
   int i; 
   
   for (i=0; i<7; i++)
   {
	  printf("Key %d is %s \n", i, keys[i]) ;   
   }  	   	

}




/* Function to add data to keys array.  */ 
void test(char keys[8][3]) 
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
	 printf("Added %s \n", keys[i]);  
	 i++;
     c = getch(); 	     
  }	
  	        
  print_keys(keys);  
  
}   	    
	   
	
				    

int main() 
{ 


/* Create a new array. */ 
char mykeys[8][3] ; 


 while(1) 
 {                 
   test(mykeys) ;                             
 } 
 
  
return 0; 


} 














