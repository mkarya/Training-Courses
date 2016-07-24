#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>

int sock;

void signal_handler(int sig) {
	printf("received user interrupt \n");
	close(sock);
	raise(SIGKILL);
}


int main (int argc, char **argv) {

	/*structure of struct sockaddr_in 
 	 * struct sockaddr_in {
 	 * 		short sin_family; = AF_INET(for most purpose)
 	 * 		struct in_addr sin_addr; contain unsigned long field for address.
 	 * 		u_short sin_port; contain port number to connect to.
 	 * 		char sin_zero[8]; not used currently.
 	 */ 		


	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;
	
	signal(SIGINT, signal_handler);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("failed to create sockte");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);

	/* bind the socket */
	if(bind(sock, (struct sockaddr *)&server, sizeof(server))) {
		perror("socket bind error");
		exit(1);
	}

	/*listen*/
	listen(sock,5);

	/*accept */
	do {
		mysock = accept(sock,(struct sockaddr *)0, 0);
		if (mysock == -1) {
			perror("accept failed");
		}
		else {
			memset(buff,0,sizeof(buff));
			if ((rval = recv(mysock, buff, sizeof(buff),0)) < 0 ) {
				perror("reading failed on incoming connection");
			}
			else if(rval == 0) {
				printf("client ending connections\n");
			}
			else 
				printf("MSG : %s\n", buff);

			close(mysock);
		}
	} while(1);

	return 0;
}
