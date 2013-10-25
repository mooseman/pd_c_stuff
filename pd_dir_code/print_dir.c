
/* print_dir.h  */ 
/* Print the contents of a directory (file sizes and names). */ 
/* Acknowledgment - Most of this code is by David Tribble and  */ 
/* comes from his Example 1 here -  */ 
/* http://david.tribble.com/text/c0xdir.html#Example-1  */ 
/* I have removed the call to stddir.h and have added the */ 
/* code for file sizes.  */ 
/* As with David's code on that page, this code is released to */ 
/* the public domain.   */ 
/* "Share and enjoy....."  ;)   */ 


#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> 


int print_dir(const char *dir)
{
    DIR *                   dp;
    const struct dirent *   ent;
    int                     cnt;
    struct stat             s;  

    // Open the given directory
    dp = opendir(dir);
    if (dp == NULL)
        return -1;

    // Search the directory
    printf("%s:\n", dir);
    cnt = 0;
    int fsize; 

    while (ent = readdir(dp), ent != NULL)
    {
        cnt++;
        stat(ent->d_name, &s);
        fsize = s.st_size; 
        printf("%10d %s \n", fsize, ent->d_name);
    }
    
   // Terminate the search
    closedir(dp);
    dp = NULL;

    printf("Entries: %d\n", cnt);
    return cnt;
}
    
    
int main()
{

print_dir(".") ; 

return 0 ; 

} 
    
    
    
    
