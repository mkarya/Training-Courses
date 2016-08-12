#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


// user below command to compile
// // gcc -D_XOPEN_SOURCE=700 -o server posix_shmserver.c -lrt
// //

int main()
{
	sem_t sem;
	const int SIZE = 1024;
	const char *name = "OS";
	const char *message0= "Studying ";
	const char *message1= "Operating Systems ";
	const char *message2= "Is Fun!";
	pid_t pid;
	int fileFd;

	fileFd = open("/home/ec2-user/Training-Courses/ipc/src/race",O_RDWR);
	if (fileFd < 0) {
		perror("open");
		exit(1);
	}
	int shm_fd, temp;
	void *ptr;
	char user_input[100];

 	temp = sem_init(&sem, 1, 1);
		
	if (temp < 0) {
		perror("sem_init");
	}
	/* create the shared memory segment */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	/* configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}

	/**
 * 	 * Now write to the shared memory region.
 * 	  	 *
 * 	  	 	 * Note we must increment the value of ptr after each write.
 * 	  	 	 	 */
	pid = fork();
	if (pid < 0) {
		perror("fork");
	}
	if (pid > 0 ) {
		sem_wait(&sem);
		printf("enter string to put in share memory");
		scanf("%s", user_input);
		sprintf(ptr,"%s",message0);
		ptr += strlen(message0);
		sprintf(ptr,"%s",message1);
		ptr += strlen(message1);
		sprintf(ptr,"%s",message2);
		ptr += strlen(message2);
		sprintf(ptr,"%s", user_input);
		sem_post(&sem);
	}
	if (pid == 0 ) {
		sem_wait(&sem);
		printf("reading content of shared memory ...... \n");
		printf("%s\n", ptr);
		shm_unlink(ptr);
		sem_post(&sem);
	} 
	

	return 0;
}
