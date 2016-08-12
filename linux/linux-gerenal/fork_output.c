#include <stdio.h>
#include <sys/types.h>

int main(void) 
{ 
   int i;   
   pid_t id[3];
   id[0] = fork();
   id[1] = fork();
   printf("Hello World!\n"); 
   id[2] = fork();
   for(i=0;i<3;i++) {
	wait(id[i]);
    } 
}

