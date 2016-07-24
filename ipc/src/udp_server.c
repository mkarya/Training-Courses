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

void dieWithError(char * str) {
	perror(str);
	exit(1);
}

int main (int argc, char **argv) {

	/*structure of struct sockaddr_in 
 	 * struct sockaddr_in {
 	 * 		short sin_family; = AF_INET(for most purpose)
 	 * 		struct in_addr sin_addr; contain unsigned long field for address.
 	 * 		u_short sin_port; contain port number to connect to.
 	 * 		char sin_zero[8]; not used currently.
 	 */ 		


	struct sockaddr_in server,incoming_s;
	int sock_struct_length = sizeof(incoming_s);
	int mysock;
	char buff[1024];
	int rval;
	
	signal(SIGINT, signal_handler);

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); /* last parameter can be 0 as well, kernel willpick right protocol based on the family of socket used. in this case UDP protocol. */
	if (sock < 0) {
		dieWithError("failed to create sockte");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(5000);

	/* bind the socket */
	if(bind(sock, (struct sockaddr *)&server, sizeof(server))) {
		dieWithError("socket bind error");
	}

	/*accept */
	do {
		memset(buff,0,sizeof(buff));
		if ((rval = recvfrom(sock, buff, sizeof(buff),0,(struct sockaddr *)&incoming_s, &sock_struct_length)) < 0 ) {
				perror("failed to read data from incming  connection");
				close(sock);
			}
		else 
			printf("received MSG : %s\n from %l\n", buff,(incoming_s.sin_addr.s_addr));

	} while(1);

	return 0;
}
