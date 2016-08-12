#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * sum_of_number(void *argv) {
	long  sum = 0 ;
	long i = 0;
	long * limit_ptr = (long *) argv;
	long limit = *limit_ptr;
	for (; i <=limit ; i++ ) {
		sum += i;
	}

	printf("received data = %d, calculated sum = %d\n",limit,sum);
	printf("my pid is  = %d,  and my parent pid is  = %d\n",getpid(), getppid());
	sleep(100);

	pthread_exit(NULL);
}


int main (int argc, char ** argv) {
	if (argc < 2 ) {
		printf ("one agrument expected, provided 0\n");
		exit(0);
	}

	printf("main function pid is  = %d,  and my parent pid is  = %d\n",getpid(), getppid());

/* below function are to deal with control structure
       int pthread_attr_init(pthread_attr_t *attr);
       int pthread_attr_destroy(pthread_attr_t *attr);
*/

	pthread_t pid01,pid02;
	pthread_attr_t attr;
	if (pthread_attr_init(&attr) != 0 ) {
		perror("thread control structure initialization error");
		exit(-1);
	}

	long limit = atol(argv[1]);

	if ((pthread_create(&pid01, &attr, sum_of_number, &limit)) < 0) { 
		perror ("thread creation error");
		exit(-1);
	}
	else { 
		printf("thread id created with id = %d", pid01);
	}

	
	sleep(2);
	limit = limit + 100;
	if ((pthread_create(&pid02, &attr, sum_of_number, &limit)) < 0) { 
		perror ("thread creation error");
		exit(-1);
	}
	else { 
		printf("thread id created with id = %d", pid02);
	}

	pthread_join(pid01, NULL);
	pthread_join(pid02, NULL);

	printf("type ctrl-c to kill the process \n");
	
	pthread_attr_destroy(&attr);
	if (pthread_attr_destroy(&attr) != 0 ) {
		perror("thread control structure destroy error");
		exit(-1);
	}

	for(;;);
	exit(0);
}
