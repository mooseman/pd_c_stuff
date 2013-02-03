

/*  tree.c  */ 
/*  Play around with tree structures.  */ 
/*  We create a "toy" directory tree. */ 


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <malloc.h>  
#include <ctype.h>

/* Funcs. */ 
/* mkdir(name) */ 
/* cd(name) */ 
/* ls */   


/* A list.  */  
/* Must be able to contain dirs too.  */ 
typedef struct f { 
	char *name;  
	struct f *next;  /* Could be file or dir. */  
} flist ; 



/* A directory struct. */ 
typedef struct d { 	
	char *parent;    /* Parent directory name (if any).  */ 
	char *name;      /*  Dir name.  */ 	
	flist *f;        /*  File and dir list.  */ 
} dir ; 	



/* Create a new dir. */
dir mkdir(char *parent, char *name)
{ 
   dir *mydir = NULL; 	
   mydir = malloc(sizeof(dir));  
      
   mydir->parent = parent; 
   mydir->name = name; 	
   mydir->f = NULL;  		
   return *mydir; 
} 
	

/* Save a file in a dir.  */ 
dir save(dir *d, flist *name)
{ 
   d->f = name; 				
   return *d;  	
} 	
	




 
struct flist *mylist = NULL; 



/* Function to add data to end of a list  */ 
void list_append(void *data)
{  
   
   /* A pointer to iterate along the list */ 
   struct flist *ptr = NULL; 
   
   /* Now, create a new node using the data. */ 
   struct flist *newnode = NULL; 
   newnode = malloc(sizeof(struct flist));  
   
   newnode->name = data; 
   newnode->next = NULL;  
   
  
  /* Is our existing list null? */ 
  /* If so, our "list" is just the newly-created node. */ 
   if(mylist == NULL) 
     {  
		mylist = newnode; 		
     }  		   
		   
   else 
     {  
		
	     for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 
	       { 
		     /* Iterate through the list until we find the last node */   
	       } 	    
	  
	   /* Add the new node to the end of the list. */ 
	   /* In other words: the last ptr->next WAS null, but it is */ 
	   /* now pointing to newnode. */  
	   ptr->next = newnode; 
	
	 }     
	   
}  /* End of list_append  */  

	
	
/* Free the list memory. */ 
void free_list(void) 
{ 
  /* We create TWO pointers. */ 
  /* ptr is used to iterate through the list. */ 
  /* tmp (which points to the same place) is used to */ 
  /* actually free the memory. */    
   struct node *ptr, *tmp = NULL;  	  
  		
  /* Check that the list is non-null. */   
   if(mylist != NULL) 
     {  
		          		
	     for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 
	       { 
			 /* Iterate through the list */   
			  printf( "Freeing %s\n",  (char *) (ptr->name) );  
			  tmp = ptr; 			 
		      free(tmp); 			      
	       } 	    
	  
	   /* Free the last element of the list */ 
	   /* (where ptr->next IS null). */ 	   
	    printf( "Freeing %s\n",  (char *) (ptr->name) ); 
	    free(ptr);   
	
	 }     
	
} 	
		
	    
	    

void print_list(void)
{ 
   /* A pointer for iterating. */ 
   struct node *ptr	= NULL;  
	
   /* Iterate along the list.  */ 
    for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 	
	   { 
		  printf( "mylist->name = %s\n",  (char *) (ptr->name) );   		 		
	   } 	    
	
	/* For the last nore (where ->next IS NULL), we need to print */ 
	/* it outside the loop. */ 
	printf( "mylist->name = %s\n",  (char *) (ptr->name) ); 
    
}



int main() 
{ 






list_append("foo");  
list_append("bar");  
list_append("baz");   
list_append("one");   
list_append("two");   
list_append("three");   


print_list(); 

free_list();  


return 0;  

 
} 







	
	





