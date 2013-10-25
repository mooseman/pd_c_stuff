/*******************************************************************************
* c0xdirtest.c
*	Test implementation for the ISO C <stddir.h> proposal at:
*	<http://david.tribble.com/text/c0xdir.html>, Revision 1.7.
*
*	This code is designed to run reasonably well on ISO C compliant systems.
*
* Contains
*	main()
*
* Acknowledgments
*	This code was written by David R. Tribble, Dec 2003 thru Mar 2006.
*	It is hereby placed into the public domain, and may be used for all
*	purposes, both commercial and private.  No warranty is provided for this
*	source code, and the author cannot be held liable for its use in any
*	way.
*
* See also
*	<http://david.tribble.com/text/c0xdir.html>
*	<news:comp.std.c>
*	<http://groups.google.com/groups?q=comp.std.c>
*
* Since	2003-12-27
*/


/* Identification */

static const char	REV[] =
    "@(#)drt/text/std/c0xdirtest.c $Revision: 1.6 $ $Date: 2006/03/11 04:23:56 $\n";


/* System includes */

#include <errno.h>
#include <iso646.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Local includes */

#include "c0xdir.h"


/*==============================================================================
* Functions
*=============================================================================*/

static void print_pfx(const char *path)
{
    char	name[4*1024+1];

    // Print leading directory components
    if (getdirname(name, sizeof(name), path) > 0)
        print_pfx(name);
    else
        printf("[%s]", path);

    // Print trailing component
    if (getfilename(name, sizeof(name), path) > 0)
        printf("[%s]", name);
}


static void print_dir(const char *path)
{
    // Print leading directory components
    printf("  ");
    print_pfx(path);
    printf("\n");
}


/*------------------------------------------------------------------------------
* main()
*	Test driver for the proposed <stddir.h> functions.
*
* Param		argc
*	Number of command line arguments, i.e., the number of elements in
*	'argv[]'.
*
* Param		argv
*	Command line arguments.
*
* Returns
*	'EXIT_SUCCESS' on success, otherwise 'EXIT_FAILURE'.
*
* Since		1.1, 2003-12-27
*/

int main(int argc, char **argv)
{
#if __STDC_DIR__ > 0
    const char *	prog;
    const char *	dirname;
    const char *	pattern;
    char		path[4*1024+1];
    DIR *		dp;
    struct dirent *	ent;
    int			details;
    int			i;
    int			n;

    /* Parse option args */
    prog = argv[0];
    details = 0;
    i = 1;

    for (i = 1;  i < argc  and  argv[i][0] == '-';  i++)
    {
        if (strcmp(argv[i], "-v") == 0)
            details = 1;
        else
            goto usage;
    }

    /* Check args */
    if (i >= argc)
    {
usage:
        printf("Test driver for the proposed <stddir.h> functions.\n\n");
        printf("usage:  %s [-v] dir pattern...\n\n", prog);
        printf("Displays matching entries in a directory.\n");

        return (EXIT_FAILURE);
    }

    /* Display the current directory */
    if (getcurrdir(path, sizeof(path)) < 0)
        printf("*** Can't get current directory, %s\n", strerror(errno));
    else
        printf("Current directory: %s\n", path);

    /* Search the specified directory */
    dirname = argv[i++];

    pattern = NULL;
    if (i < argc)
        pattern = argv[i++];

    /* Search the directory */
    printf("\n");
    printf("[%s]\n", dirname);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        int		err;

        err = errno;
        printf("  *** Can't search: %s\n", dirname);
        printf("  *** %s\n", strerror(err));
        return (EXIT_FAILURE);
    }

    /* Find entries within the directory */
    n = 0;
    while (ent = readdir(dp), ent != NULL)
    {
        const char *	fname;

#if DEBUGS
        printf("\n");
        printf("-----------------------------------------------------------\n");
#endif

        /* Found a directory entry */
        fname = ent->d_name;
        if (pattern != NULL  and  matchfilename(fname, pattern) < 0)
            continue;

        n++;
        printf("%d %s\n", n, fname);

        if (details)
        {
            printf("  fullname: [%s]\n", fname);
            printf("  name:     [%s] %u\n",
                fname, (unsigned)ent->d_namlen);
        }

        mkfilename(path, sizeof(path), dirname, fname);
        printf("  %s\n", path);

        if (details)
        {
            char	name[4*1024+1];

            printf("  ");

            getdirname(name, sizeof(name), path);
            printf("[%s]", name);

            getfilename(name, sizeof(name), path);
            printf("[%s]", name);
            printf("\n");

            print_dir(path);
            printf("\n");
        }
    }

    /* Clean up */
    closedir(dp);
    printf("Entries: %d\n", n);
    return (EXIT_SUCCESS);

#else
    /* <stddir.h> directory functions are not supported */
    printf("<stddir.h> directory functions are not supported\n");
    return (EXIT_FAILURE);

#endif
}

/* End c0xdirtest.c */


