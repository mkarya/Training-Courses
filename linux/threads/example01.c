#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long  sum = 0 ;

void * sum_of_number(void *argv) {
	long i = 0;
	long * limit_ptr = (long *) argv;
	long limit = *limit_ptr;
	for (; i <=limit ; i++ ) {
		sum += i;
	}

	pthread_exit(NULL);
}


int main (int argc, char ** argv) {
	if (argc < 2 ) {
		printf ("one agrument expected, provided 0\n");
		exit(0);
	}

	pthread_t pid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	long limit = atol(argv[1]);

	pthread_create(&pid, &attr, sum_of_number, &limit);

	pthread_join(pid, NULL);

	printf("sum of the number %d\n", sum);
	exit(0);
}
