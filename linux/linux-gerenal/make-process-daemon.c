#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	char kk[80];
	printf("i am running as normal process\n");
	printf("enter anything to kill me \n");
	scanf("%s",kk);
	if (daemon(0,0) < 0) 
		perror("demonise is not successful\n");
	for(;;);
		//sleep(1);
	exit(0);
}
	
