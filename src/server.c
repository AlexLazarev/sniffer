#include "sniffer.h"

static void listener(int sock, t_node *root)
{
    char buf[MAX];

    while (1) {
        bzero(buf, MAX);

        read(sock, buf, sizeof(buf));

        if (strcmp("stop", buf) == 0) {
            printf("Server Exit...\n");
            break;
        }
        if (strcmp("show", buf) == 0) {
            bzero(buf, MAX);
            read(sock, buf, sizeof(buf));
            printf("lel: %s\n", buf);
            t_node *node = search(buf, root);
            if (node) {
                printf("%s %d\n", node->key, node->count);
            }
            write(sock, "$end$", 5);
        }
    }
}

void create_server(t_node *root) {
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

	listener(connection, root);

	close(sock);
}
