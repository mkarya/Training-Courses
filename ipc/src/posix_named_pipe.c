#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <linux/stat.h>

#define FIFO_FILE "/tmp/myfifo"
#define FIFO_FILE1 "/tmp/mkfifo01"


int main(void) {

	int fd;
	char buf[1024];

	fd = open(FIFO_FILE, O_WRONLY);

	while (1){
		if (write(fd,"creator is writing to file\n",50) <= 0 ) {
			perror("file writing error :");
			close(fd);
			exit(-1);
		}
		

	close(fd);
	return 0;
}
