#include<stdio.h>
 
   int main()
   {
       int fd[3],count;
       if (pipe(fd) != 0)
           perror("pipe");
       count = write(fd[1],"Hello",6);
       printf("%d\n",count);
       return 0;
   }

