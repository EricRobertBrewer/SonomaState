#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <stdlib.h>

extern int errno;
/*  Function "timestamp" return one of the following values:
    
    a non-zero value
    0

   a non-zero value means it did not encounter any "bad" errors.  A
   zeor value means an error occured.

   When the function returns a non-zero value (1 in this case), the
   value of 'time' is -1 if the file whose name is in 'fname' did not
   exist.  Otherwise, 'time' contains the time-stamp of 'name' in
   terms of number seconds elapsed  since January 1, 1997 (the epoch!)

*/

int timestamp( char *fname, long *time )
{
  struct stat finfo;

  if( stat( fname, &finfo ) == 0 ) {
      *time = finfo.st_mtime;
      return 1;
  } else if( errno == ENOENT ) {
      *time = -1L;
      return 1;
  } else {
      return 0;
  }
}


//  Executes the commond 'cmnd' and returns its status.
//  A return value of zero means that the command terminated 
//    successfully.

int executecommand( char *cmnd ) {  return 0 == system( cmnd ); }
