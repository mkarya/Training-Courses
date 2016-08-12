#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
long int sum = 0;

void * sum_of_number(void *argv) {
	long i = 0;
	long * limit_ptr = (long *) argv;
	long limit = *limit_ptr;
	sem_wait(&mutex);
	sum = 0;
	for (; i <=limit ; i++ ) {
		sum += i;
	}
		sleep(1);
	printf("thread =  %d calculated sum = %ld for numnber = %ld \n",pthread_self(),sum,limit);
	sem_post(&mutex);

	//free(limit_ptr);
	
	long * return_value = malloc(sizeof(*return_value));
	
	*return_value = sum;

	pthread_exit(return_value);
}


int main (int argc, char ** argv) {
	short int num_of_arg = 0, counter;
	if (argc < 2 ) {
		printf ("one agrument expected, provided 0\n");
		exit(0);
	}

	num_of_arg = argc - 1;
	pthread_t pid[num_of_arg];
	long limit;

	sem_init(&mutex, 0, 1 );

	for (counter =1; counter <= num_of_arg; counter++) {
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		limit = atol(argv[counter]);

		long *limit_ptr = malloc(sizeof(*limit_ptr));
		*limit_ptr = limit; 

		pthread_create(&pid[counter - 1], &attr, sum_of_number, limit_ptr);
	}

	for (counter = 1; counter <= num_of_arg; counter++) {
		long *return_value = NULL ;
		pthread_join(pid[counter-1], (void **) &return_value);
	//	printf("value of sum of %d is     %d\n", atol(argv[counter]),*return_value);
		free(return_value);
	}

	sem_destroy(&mutex);

	exit(0);
}
