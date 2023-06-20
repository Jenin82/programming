#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
	int sockfd, valread;
	struct sockaddr_in server;
	char buffer[SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server, '\0', sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}

	printf("Connected to TCP server.\n");

	printf("Enter a message to send: ");
	fgets(buffer, SIZE, stdin);

	send(sockfd, buffer, strlen(buffer), 0);
	printf("Client: %s\n", buffer);

	memset(buffer, '\0', SIZE);
	valread = read(sockfd, buffer, SIZE);
	printf("Server: %s\n", buffer);

	close(sockfd);

	return 0;
}
