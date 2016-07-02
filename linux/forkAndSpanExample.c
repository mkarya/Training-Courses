#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* compile this program with gcc -o forkExperiment forkAndSpanExample.c */ 
int main (int argc, char ** argv) {
	pid_t pid;
  	pid = fork();
	if ( pid < 0 ) {
		perror("fork failed");
		return(-1);
	}
	if (pid > 0) {
		printf (" I am parent with id %d, and my child pid = %d\n", getpid(), pid);
		wait(NULL);
	}
	else {
		printf (" I am child with id %d, and my parent child pid = %d\n", pid, getppid());
		execl("/bin/ls", "ls", "-ltr", NULL);
	}

	return(0);
}
			
