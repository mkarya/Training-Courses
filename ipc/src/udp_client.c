#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>

#define DATA "welcome to world of UDP socket programming"
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
	struct hostent *hp;
	int rval;
	
	signal(SIGINT, signal_handler);

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); /* last parameter can be 0 as well, kernel willpick right protocol based on the family of socket used. in this case UDP protocol. */
	if (sock < 0) {
		dieWithError("failed to create sockte");
	}

	hp = gethostbyname(argv[1]);

	server.sin_family = AF_INET;
	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port = htons(5000);

	if ((rval = sendto(sock, DATA, sizeof(DATA),0,(struct sockaddr *)&server, sock_struct_length)) < 0 )   {
			perror("failed to read data from incming  connection");
			close(sock);
	}
	close(sock);

	return 0;
}
