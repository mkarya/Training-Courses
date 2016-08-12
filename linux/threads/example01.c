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

	pthread_exit(NULL);
}


int main (int argc, char ** argv) {
	if (argc < 2 ) {
		printf ("one agrument expected, provided 0\n");
		exit(0);
	}

	pthread_t pid01,pid02;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	long limit = atol(argv[1]);

	pthread_create(&pid01, &attr, sum_of_number, &limit);
	sleep(2);
	limit = limit + 100;
	pthread_create(&pid02, &attr, sum_of_number, &limit);

	pthread_join(pid01, NULL);
	pthread_join(pid02, NULL);

	printf("type ctrl-c to kill the process \n");

	for(;;);
	exit(0);
}
