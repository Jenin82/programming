#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SIZE 100

void main()
{
	int sockfd;
	struct sockaddr_in server, client;
	char buffer[SIZE];
	socklen_t addr_size;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	memset(&server, '\0', sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(2000);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr *)&server, sizeof(server));
	addr_size = sizeof(client);
	recvfrom(sockfd, buffer, SIZE, 0, (struct sockaddr *)&client, &addr_size);
	printf("[+]Data Received: %s", buffer);
}