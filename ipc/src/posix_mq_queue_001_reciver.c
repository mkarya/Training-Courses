#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>


// user below command to compile
// // gcc -D_XOPEN_SOURCE=700 -o server posix_shmserver.c -lrt
// //

int main()
{
	mqd_t mqid;
	pid_t pid;
	const char *mq_name = "/mymsgqu";
	char kk[100];
	int msg_len;

	if ( (mqid = mq_open(mq_name, O_RDWR)) < 0 ) perror("mq_open");

	if ( mqid < 0 ) perror("mq_open");

	if ( mq_receive(mqid,kk,8192,NULL) < 0 ) perror("mq_receive");
	if (kk != NULL) 
	 printf("%s\n",kk);
	
	return 0;
}

