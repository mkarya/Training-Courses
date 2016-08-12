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

	shmid = shmget(key_value,SHARED_SIZE, IPC_CREAT | 0666);
	if (shmid < 0 )  {
		perror("shared memory creation has failed \n");
		exit(-1);
	}
	
	shared_ptr = shmat(shmid, NULL, 0);

	memcpy(shared_ptr, "server says hello", 17);
	
	while (*shared_ptr != '*') sleep (1);

	shmdt(shared_ptr);
	
	return 0;
}

	
