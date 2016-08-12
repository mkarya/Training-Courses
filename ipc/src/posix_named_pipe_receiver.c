#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <linux/stat.h>

#define FIFO_FILE "/tmp/myfifo"


int main(void) {

	int fd;
	char buf[1024];

	fd = open(FIFO_FILE, O_RDONLY);

	if (read(fd,buf,50) <= 0 ) {
		perror("file writing error :");
		close(fd);
		exit(-1);
	}

	printf("%s\n",buf);

	close(fd);
	return 0;
}
