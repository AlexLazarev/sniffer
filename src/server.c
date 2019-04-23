#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

# define PORT 4455
#define MAX 80
void func(int sock)
{
	char buff[MAX];
	int n;
	// infinite loop for chat
	for (;;) {
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		read(sock, buff, sizeof(buff));
		// print buffer which contains the client contents
		printf("From client: %s\t To client : ", buff);
		bzero(buff, MAX);
		n = 0;
		// copy server message in the buffer
		while ((buff[n++] = getchar()) != '\n')
			;

		// and send that buffer to client
		write(sock, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
	}
}


int main(int argc, char **argv) {
	int sock;
	int connection;
	socklen_t len;
	struct sockaddr_in server;
	struct sockaddr_in cli;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sock < 0) {
		 perror("ERROR opening socket");
         exit(1);
	}
	
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET; 
    server.sin_addr.s_addr = htonl(INADDR_ANY); 
    server.sin_port = htons(PORT); 
	if ((bind(sock, (struct sockaddr*)&server, sizeof(server))) != 0) {
        printf("socket bind failed...\n"); 
        exit(1); 
    } else {
		printf("socket ...\n");
	}
	if ((listen(sock, 5)) != 0) {
        printf("Listen failed...\n"); 
        exit(1); 
    } else {
		printf("Server listening..\n");
	}
	len = sizeof(cli);
	connection = accept(sock, (struct sockaddr*)&cli, &len);
	if (connection < 0) {
		printf("server accept failed...");
		exit(1);	
	}

	// Function for chatting between client and server
	func(connection);

	close(sock);
	return 0;
}
