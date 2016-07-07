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
//struct mq_attr {
//    long mq_flags;       /* Flags: 0 or O_NONBLOCK */
//    long mq_maxmsg;      /* Max. # of messages on queue */
//    long mq_msgsize;     /* Max. message size (bytes) */
//    long mq_curmsgs;     /* # of messages currently in queue */
//   };
//



int main()
{
	mqd_t mqid;
	pid_t pid;
	const char *mq_name = "/mymsgqu";
	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 128;

	mqid = mq_open(mq_name, O_RDWR | O_CREAT , 0666, &attr);

	if ( mqid < 0 ) perror("mq_open");

	const char *msg = "parent sending message to child using msg_queue\n";
	if ( mq_send(mqid,msg,strlen(msg),10) < 0 ) perror("mq_send");
	
	return 0;
}

