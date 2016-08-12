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
// gcc -D SEM_ON -o server posix_semaphore_file_operations.c -lrt -lpthread
// //

int main(int argc, char ** argv)
{
	sem_t sem;
	const int SIZE = 1024;
	const char *name = "OS";
	const char *message0= "Studying ";
	const char *message1= "Operating Systems ";
	const char *message2= "Is Fun!";
	pid_t pid;
	int fileFd;

	sem_init(&sem,1,1);
	fileFd = open("/home/ec2-user/Training-Courses/ipc/src/race",O_RDWR);
	if (fileFd < 0) {
		perror("open");
		exit(1);
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
		char *p = "parent is wrtiting to file \n";
		short counter = 0;
		int max_value = atoi(argv[1]);
		#ifdef SEM_ON
		sem_wait(&sem);
		#endif
		for (;counter < max_value; counter++) {
			if ( write(fileFd, p, strlen(p)) < 0 ){
				 perror("write");
			}
		}
		#ifdef SEM_ON
		sem_post(&sem);
		#endif
		close(fileFd);
	}
	if (pid == 0 ) {
		char *p = "child is wrtiting to file \n";
		short counter = 0;
		int max_value = atoi(argv[1]);
		#ifdef SEM_ON
		sem_wait(&sem);
		#endif
		for (;counter < max_value; counter++) {
			if ( write(fileFd, p, strlen(p)) < 0 ) perror("write");
		}
		#ifdef SEM_ON
		sem_post(&sem);
		#endif
		close(fileFd);
	} 
	

	return 0;
}
