#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void main()
{

	int sockfd;
	struct sockaddr_in server;
	char buffer[1024];
	socklen_t addr_size;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	memset(&server, '\0', sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(2000);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	strcpy(buffer, "Hello Server\n");
	sendto(sockfd, buffer, 1024, 0, (struct sockaddr *)&server, sizeof(server));
	printf("[+]Data Send: %s", buffer);
}