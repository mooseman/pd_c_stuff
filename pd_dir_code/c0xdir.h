/*******************************************************************************
* c0xdir.h, <stddir.h>
*	Test implementation for the ISO C <stddir.h> proposal at:
*	<http://david.tribble.com/text/c0xdir.html>, Revision 1.7.
*
*	This code is designed to run reasonably well on POSIX and Win32 systems.
*
* Notes
*	Define the macro '_unix' when compiling on POSIX (Unix) systems.
*	Also define the macro '_linux' when compiling on Linux systems.
*
* Contains
*	macro __STDC_DIR__
*	macro __STDC_SETCURRDIR__
*	typedef DIR
*	struct dirent
*	closedir()
*	createdir()
*	getcurrdir()
*	getdirname()
*	getfilename()
*	getfiletype()
*	matchfilename()
*	mkdirname()
*	mkfilename()
*	opendir()
*	readdir()
*	rewinddir()
*	setcurrdir()
*
* Acknowledgments
*	This code was written by David R. Tribble, Oct 2003 thru Mar 2006.
*	It is hereby placed into the public domain, and may be used for all
*	purposes, both commercial and private.  No warranty is provided for this
*	source code, and the author cannot be held liable for its use in any
*	way.
*
* See also
*	<http://david.tribble.com/text/c0xdir.html>
*	<news:comp.std.c>
*	<http://groups.google.com/groups?q=comp.std.c>
*/

#ifndef c0x_c0xdir_h
#define c0x_c0xdir_h	109


/* Identification */

#ifndef NO_H_IDENT
static const char	c0x_c0xdir_h_REV[] =
    "@(#)drt/text/std/c0xdir.h $Revision: 1.9 $ $Date: 2006/03/11 04:23:07 $\n";
#endif


/* System includes */

#include <stddef.h>


/*==============================================================================
* Constants
*=============================================================================*/

#define __STDC_DIR__	20060310

#if defined(_unix)
 #define __STDC_SETCURRDIR__	1	/* setcurrdir() supported	*/
#elif defined(_WIN32)
 #define __STDC_SETCURRDIR__	1	/* setcurrdir() supported	*/
#else
 #error Unsupported OS
#endif


/*==============================================================================
* Types
*=============================================================================*/

/*------------------------------------------------------------------------------
* typedef DIR
*	Directory search context information.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#type-DIR>
*
* @since	1.1, 2003-10-25
*/

struct DirContext_c0x;
typedef struct DirContext_c0x	DIR_c0x;


/*------------------------------------------------------------------------------
* struct dirent
*	Directory entry information.
*
*	Note that the last member 'd_name' is actually a variable-length array,
*	and will contain more than one character.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#struct-dirent>
*
* @since	1.1, 2003-10-25
*/

#define dirent_c0x_VS	20060308	/* Struct version		*/
#define dirent_VS	dirent_c0x_VS

struct dirent_c0x
{
    size_t		d_namlen;	/* Entry name length		*/
    char		d_name[1];	/* Entry name			*/
};


/*==============================================================================
* Functions
*=============================================================================*/

/*------------------------------------------------------------------------------
* getcurrdir()
*	Determines the current directory associated with the execution unit.
*
* @param	dir
*	A string buffer that is to be filled with the name of the current
*	execution directory.
*
* @param	max
*	Maximum number of characters, including a terminating null character
*	('\0'), to be written into 'dir'.
*
* @return
*	If successful, the function returns a non-negative value after filling
*	the contents of string 'dir'.  On failure, the function returns a
*	negative value after modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-getcurrdir>
*
* @since	1.2, 2003-12-23
*/

extern int c0x_getcurrdir(char *dir, size_t max);


/*------------------------------------------------------------------------------
* setcurrdir()
*	Establishes the current directory associated with the execution unit.
*
* @param	dir
*	String containing the name of the new current execution directory.
*
* @return
*	If successful, the function returns a non-negative value; otherwise, it
*	modifies the value of 'errno' and returns a negative value.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-setcurrdir>
*
* @since	1.2, 2003-12-23
*/

extern int c0x_setcurrdir(const char *dir);


/*------------------------------------------------------------------------------
* createdir()
*	Create a new directory.
*
* @param	dir
*	String containing the name of the new directory to create.
*
* @return
*	If successful, the function returns a non-negative value; otherwise, it
*	modifies the value of 'errno' and returns a negative value.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-createdir>
*
* @since	1.1, 2003-10-25
*/

extern int c0x_createdir(const char *dir);


/*------------------------------------------------------------------------------
* getdirname()
*	Extract the directory component from a path name.
*
* @param	dir
*	Points to a string buffer into which is written the directory component
*	of the given path name.  No more that 'max' characters, including a
*	terminating null character, will be written.  If 'path' has no directory
*	component, this is set to an empty string ("") and zero is returned.
*
* @param	max
*	The maximum number of characters, including a terminating null
*	character, to write into string 'dir'.  If the directory component of
*	the given path name exceeds 'max', this function fails.
*
* @param	path
*	A path name.  This must not be null.
*
* @return
*	If successful, the function returns a positive value indicating the
*	length of the resulting file name component (i.e., the number of
*	characters, excluding the terminating null character, written into
*	'file').  On failure, the function returns a negative value after
*	possibly modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-getdirname>
*
* @since	1.1, 2003-10-25
*/

extern int c0x_getdirname(char *dir, size_t max, const char *path);


/*------------------------------------------------------------------------------
* getfilename()
*	Extract the file name component from a path name.
*
* @param	file
*	Points to a string buffer into which is written the file component of
*	the given path name.  No more that 'max' characters, including a
*	terminating null character, will be written.
*
* @param	max
*	The maximum number of characters, including a terminating null
*	character, to write into string 'file'.  If the file component of the
*	given path name exceeds 'max', this function fails.
*
* @param	path
*	A path name.  This must not be null.
*
* @return
*	If successful, the function returns a positive value indicating the
*	length of the resulting file name component (i.e., the number of
*	characters, excluding the terminating null character, written into
*	'file').  On failure, the function returns a negative value after
*	possibly modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-getfilename>
*
* @since	1.1, 2003-10-25
*/

extern int c0x_getfilename(char *file, size_t max, const char *path);


/*------------------------------------------------------------------------------
* mkdirname()
*	Create a directory name from a given directory name and a given
*	subdirectory name within that directory.
*
* @param	path
*	Points to a character array that is to be filled with the file name
*	resulting from combining the given directory name 'dir' and file name
*	'file' components.  If the components cannot be combined into a valid
*	file name, the function fails.  If this pointer is null, the behavior is
*	undefined.
*
* @param	max
*	The maximum number of characters, including a terminating null character
*	('\0'), to write into string 'path'.  If the resulting file name
*	contains more than 'max' characters, the function fails.
*
* @param	dir
*	A string containing the name of a directory.  If the string is empty
*	(""), it is assumed to specify the name of the current execution
*	directory.  If this pointer is null, the behavior is undefined.
*
* @param	sub
*	A string containing the name of a subdirectory located within the
*	directory designated by the 'dir' string.  If this pointer is null, the
*	behavior is undefined.
*
* @return
*	If successful, the function returns a positive value indicating the
*	length of the resulting subdirectory name (i.e., the number of
*	characters, excluding the terminating null character, written into
*	string 'path').  On failure, the function returns a negative value after
*	possibly modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-mkdirname>
*
* @since	1.5, 2004-01-10
*/

extern int c0x_mkdirname(char *path, size_t max, const char *dir,
    const char *sub);


/*------------------------------------------------------------------------------
* mkfilename()
*	Create a filename from a given directory name and a given file name
*	within that directory.
*
* @param	path
*	Points to a character array that is to be filled with the file name
*	resulting from combining the given directory name 'dir' and file name
*	'file' components.  If the components cannot be combined into a valid
*	file name, the function fails.  If this pointer is null, the behavior is
*	undefined.
*
* @param	max
*	The maximum number of characters, including a terminating null character
*	('\0'), to write into string 'path'.  If the resulting file name
*	contains more than 'max' characters, the function fails.
*
* @param	dir
*	A string containing the name of a directory.  If the string is empty
*	(""), it is assumed to specify the name of the current execution
*	directory.  If this pointer is null, the behavior is undefined.
*
* @param	file
*	A string containing the name of a file located within the directory
*	designated by the 'dir' string.  If this pointer is null, the behavior
*	is undefined.
*
* @return
*	If successful, the function returns a positive value indicating the
*	length of the resulting file name (i.e., the number of characters,
*	excluding the terminating null character, written into string 'path').
*	On failure, the function returns a negative value after possibly
*	modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-mkfilename>
*
* @since	1.1, 2003-10-25
*/

extern int c0x_mkfilename(char *path, size_t max, const char *dir,
    const char *file);


/*------------------------------------------------------------------------------
* matchfilename()
*	Determine if a path name matches a filename pattern.
*
* @param	path
*	A string containing the name of a file or directory.  This name is
*	matched against pattern 'pattern'.  An empty string ("") is only matched
*	by an empty pattern string ("").  If this pointer is null, the behavior
*	is implementation-defined.
*
* @param	pattern
*	A string containing a filename pattern, which may consist of special
*	pattern-matching (wildcard) characters.  The format of this string and
*	whether or not alphabetic characters are case-sensitive are both
*	implementation-defined.  An empty string ("") only matches an empty
*	filename string ("").  If this pointer is null, the behavior is
*	implementation-defined.
*
* @return
*	If the given path name matches the filename pattern, the function
*	returns a non-negative value; otherwise, it modifies the value of
*	'errno' and returns a negative value.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-matchfilename>
*
* @since	1.9, 2006-03-10
*/

extern int c0x_matchfilename(const char *path, const char *pattern);


/*------------------------------------------------------------------------------
* opendir()
*	Initiate a search within a directory.
*
* @param	dir
*	The name of a directory to search.
*
* @return
*	On success, the function creates and returns a pointer to an object
*	containing context information for searching the specified directory.
*	This object can subsequently be passed to the other directory searching
*	functions, and is destroyed by a subsequent call to 'closedir()'.  On
*	failure, the function returns null after modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-opendir>
*
* @since	1.2, 2003-12-23
*/

extern DIR_c0x * c0x_opendir(const char *dir);


/*------------------------------------------------------------------------------
* closedir()
*	Terminate the directory search initiated by a previous call to
*	'opendir()'.
*
* @param	dp
*	Points to the directory search context information that was returned by
*	a previous call to 'opendir()'.  If the pointer is null, the behavior is
*	undefined.
*
* @return
*	If successful, the context information pointed to by 'dp' is destroyed
*	and the function returns a non-negative value.  On failure, the function
*	returns a negative value after modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-closedir>
*
* @since	1.2, 2003-12-23
*/

extern int c0x_closedir(DIR_c0x *dp);


/*------------------------------------------------------------------------------
* readdir()
*	Read the next entry contained within a directory being searched.
*
* @param	dp
*	Points to the directory search context information that was returned by
*	a previous call to 'opendir()'.  If the pointer is null, the behavior is
*	undefined.
*
* @return
*	If successful, a pointer to a structure is returned, where the structure
*	contains information about the next directory entry within the directory
*	search context.  The position of the search is advanced to the next
*	directory entry.  On failure, or if there are no more entries to be
*	found in the directory search, the function returns a null pointer after
*	modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-readdir>
*
* @since	1.2, 2003-12-23
*/

extern struct dirent_c0x * c0x_readdir(DIR_c0x *dp);


/*------------------------------------------------------------------------------
* rewinddir()
*	Reset the search position of a given directory search to its initial
*	position.
*
* @param	dp
*	Points to the directory search context information that was returned by
*	a previous call to 'opendir()'.  If the pointer is null, the behavior is
*	undefined.
*
* @return
*	If successful, the directory search context is modified and the function
*	returns a non-negative value.  On failure, the function returns a
*	negative value after modifying the value of 'errno'.
*
* @see
*	<http://david.tribble.com/text/c0xdir.html#func-rewinddir>
*
* @since	1.4, 2003-12-29
*/

extern int c0x_rewinddir(DIR_c0x *dp);


/*==============================================================================
* Aliases
*=============================================================================*/

/* Type aliases */
#ifndef c0x_c0xdir_c
 #define DIR		DIR_c0x
 #define dirent		dirent_c0x
#endif

/* Function aliases */
#ifndef c0x_c0xdir_c
 #define getcurrdir	c0x_getcurrdir
 #define setcurrdir	c0x_setcurrdir
 #define createdir	c0x_createdir
 #define getdirname	c0x_getdirname
 #define getfilename	c0x_getfilename
 #define mkdirname	c0x_mkdirname
 #define mkfilename	c0x_mkfilename
 #define matchfilename	c0x_matchfilename
 #define opendir	c0x_opendir
 #define closedir	c0x_closedir
 #define readdir	c0x_readdir
 #define rewinddir	c0x_rewinddir
#endif


#endif /* c0x_c0xdir_h */

/* End c0xdir.h */


