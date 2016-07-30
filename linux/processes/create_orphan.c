#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
	pid_t chid;
	char buf[10];
	
	if ((chid = fork()) < 0 )
		perror ("fork failed :");

	if (chid > 0) {
		printf("i am parent process with id = %d\n i am dying now leaving child orphan\n",getpid());
		sleep(1);
		exit(0);
	}

	else if (chid == 0 ) {
		printf("i am child process with id = %d\n my parent process id =%d \n",getpid(),getppid());
		printf("enter your name hit enter \n");
		scanf("%s\n",buf);
		printf("i am orphan now and adopted by init process\n");
		printf("my parent id = %d \n",getppid());
		scanf("%s\n",buf);
	}

	return 0;
}
