#include<stdio.h> 
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>

// Save it in pipe_demo.c and compile it using "gcc pipe_demo.c". 
void syserror( char * );

int main(void)
{
  int pfd[2], pid;

  if ( pipe (pfd) == -1 )
      syserror( "Could not create a pipe" );
  switch ( pid = fork() ) {
      case -1: 
          syserror( "Fork failed." );
          break;
      case  0: 
          if ( close( 0 ) == -1 )
              syserror( "Could not close stdin I" );
          dup(pfd[0]);
          if ( close (pfd[0]) == -1 || close (pfd[1]) == -1 )
              syserror( "Could not close pfds I" );
          execlp("wc", "wc", NULL);
          syserror( "unsuccessfull execlp I!!");
  }
  fprintf(stderr, "The first child's pid is: %d\n", pid);
  switch ( pid = fork() ) {
      case -1: 
          syserror( "Could not fork successfully II" );
          break;
      case  0: 
          if ( close( 1 ) == -1 )
              syserror( "Could not close stdout" );
          dup(pfd[1]);
          if ( close (pfd[0]) == -1 || close (pfd[1]) == -1 )
              syserror( "Could not close pfds II" );
          execlp("who", "who", NULL);
          syserror( "Execlp error" );
  }
  fprintf(stderr, "The second child's pid is: %d\n", pid);
  if ( close (pfd[0]) == -1 || close (pfd[1]) == -1 )
    syserror( "parent could not close file descriptors!!");
  while ( (pid = wait( (int *) 0 ) ) != -1) 
    ;    /* fprintf(stderr,"%d\n", pid) */ 
}

void syserror(char *s)
{
  extern int errno;

  fprintf( stderr, "%s\n", s );
  fprintf( stderr, " (%s)\n", strerror(errno) );
  exit( 1 );
}
