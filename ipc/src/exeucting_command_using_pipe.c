#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	
    FILE *pf;
    char command[1024];
    char data[1024];
    pid_t pd = getpid();

    sprintf(command, "cat /proc/%d/status | grep State",pd); 
	system(command);

     //Execute a process listing
    //sprintf(command, "ps -e "); 
    
    //Setup our pipe for reading and execute our command.
      pf = popen(command,"r"); 
    
     //Error handling
    
     //Get the data from the process execution
     fgets(data, 1024 , pf);
    
     //the data is now in 'data'
   printf("%s",data); 
     fgets(data, 1024 , pf);
    
     //the data is now in 'data'
   printf("%s",data); 
      if (pclose(pf) != 0)
          fprintf(stderr," Error: Failed to close command stream \n");
    
     return 0;
}
