#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8090
#define BUFFER_SIZE 1024

int main()
{
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	int opt = 1;
	char buffer[BUFFER_SIZE];

	// Create socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));

	// Configure server address
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);

	// Bind the socket to the specified port
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}

	printf("UDP server listening on port %d...\n", PORT);

	// Receive messages from clients
	while (1)
	{
		len = sizeof(cliaddr);
		memset(buffer, 0, sizeof(buffer));

		// Receive message from client and print it
		recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
		printf("Client: %s\n", buffer);

		// If the received message is "exit", break the loop
		if (strcmp(buffer, "exit\n") == 0)
			break;

		// Get server message input
		printf("Server: ");
		fgets(buffer, BUFFER_SIZE, stdin);

		// Send server message back to the client
		sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&cliaddr, len);
	}

	// Close the socket
	close(sockfd);

	return 0;
}
