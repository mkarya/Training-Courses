#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	int pipefd[2];
	pid_t chid;

	if (pipe(pipefd) < 0 ) {
		perror("pipe creation issues ");
		exit(1);
	}

	if ((chid = fork()) < 0 ) {
		perror("fork creation issues ");
		exit(1);
	}

	if (chid == 0) {
		char readbuf[1024];
		memset(readbuf,0,sizeof(readbuf));
		close(pipefd[1]);
		read(pipefd[0],readbuf,sizeof(readbuf));
		printf("child reads %s\n", readbuf);
		exit(0);
	} 
	else {
		char buf[1024];
		memset(buf,0,sizeof(buf));
		close(pipefd[0]);
		strcpy(buf, "hello from parent");
		write(pipefd[1],buf,sizeof(buf));
		wait(NULL);
		for(;;);
		exit(0);
	}	
		
}	

	

