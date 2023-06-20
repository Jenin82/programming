#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
	int sockfd;
	struct sockaddr_in servaddr;
	char buffer[BUFFER_SIZE];

	// Create socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));

	// Configure server address
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;

	// Bidirectional communication loop
	while (1)
	{
		// Get user message input
		printf("Client: ");
		fgets(buffer, BUFFER_SIZE, stdin);

		// Send message to server
		sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

		// If the sent message is "exit", break the loop
		if (strcmp(buffer, "exit") == 0)
			break;

		memset(buffer, 0, sizeof(buffer));

		// Receive server message
		ssize_t n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, NULL, NULL);
		buffer[n] = '\0';

		// Print received message
		printf("Server: %s\n", buffer);
	}

	// Close the socket
	close(sockfd);

	return 0;
}
