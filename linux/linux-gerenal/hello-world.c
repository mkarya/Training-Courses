#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main (void) {
	//printf("hello, world\n");
	syscall(SYS_write,1, "hello, world\n", 14);

	return 0;
}
