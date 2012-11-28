#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<wait.h>


int main( int argc, char *argv[] )
{
    pid_t pid = fork();
    if( pid == -1 ) {
        printf( "fork failed.\n" );
        exit( -1 );
    }
    if( pid == 0 ) {
        if( execlp( "/bin/ls", "ls", "/usr", NULL ) == -1 ) {
            printf( "Failed to run exec\n" );
            exit( 1 );
        }
    }

    int childStatus;
    waitpid( pid, &childStatus, WUNTRACED );
    printf( "Child's exit status is %d\n", childStatus );
    return 0;
}
