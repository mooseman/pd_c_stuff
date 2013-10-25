

/*  kbtest.c  */ 
/*  Try to read keyboard memory.  */ 
/*  This page was used for the memory location */ 
/*  of the keyboard buffer -  */ 
/*  http://wiki.osdev.org/Memory_Map_%28x86%29  */  



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





int main() 
{ 


/*  Keyboard buffer at 0x041E   */ 


while(1)
{
	
  //  getch(); 	
	
  /* int a = getch() ; 
  int *b = &a ;  */ 
  
  char x[10];
  void *ptr;
 
  fgets( x, 10, stdin );
 
  ptr = stdin->_IO_buf_base;
 
  memcpy( ptr, "HAHAHA", 6 );
 
  stdin->_IO_read_ptr = ptr;
 
  fgets( x, 7, stdin );
 
  printf( "%s\n", x ); 
  
  
  /* const char* p = 0x041E ; 
  const char* pEnd = p + 32 ;   */ 
    
  
 /* printf("Value: %d \n", p );    
  printf("Location: %X \n", &p );  
        
  printf("Value: %X \n", pEnd );    
  printf("Location: %p \n", &pEnd );  */            
        
      
} 


return 0; 

}







