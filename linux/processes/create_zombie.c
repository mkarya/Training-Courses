#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
	pid_t chid;
	char buf[10];
	
	if ((chid = fork()) < 0 )
		perror ("fork failed :");

	if (chid == 0) {
		printf("i am child process with id = %d\n becoming zombie now\n",getpid());
		exit(0);
	}

	else if (chid > 0 ) {
		printf("i am parent process with id = %d\n please check for zombie process using \n command ps aux | grep Z\n",getpid());
		printf("enter your name hit enter \n");
		scanf("%s",buf);
		wait(chid);
		printf(" check for zombie process one more time using command ps aux | grep z \n");
		printf("hit enter\n");
	}

	return 0;
}
