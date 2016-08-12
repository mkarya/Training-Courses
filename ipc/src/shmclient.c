#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHARED_SIZE 1000

int main (int argc, char ** argv) {
	int shmid;
	key_t key_value = 5550;
	char * shared_ptr = NULL;
	char * temp_ptr = NULL; 
	short counter = 0;

	shmid = shmget(key_value,SHARED_SIZE, 0666);
	if (shmid < 0 )  {
		perror("shared memory creation has failed \n");
		exit(-1);
	}
	
	shared_ptr = shmat(shmid, NULL, 0);

	for(;counter < 17; counter++) {
		printf("%c",shared_ptr[counter]); 
		printf("\n"); 
	}
 		
	printf("hit enter if you like to kill server program\n");
	scanf("%s",temp_ptr);
	*shared_ptr =  '*';
	shmdt(shared_ptr);
	
	return 0;
}

	
