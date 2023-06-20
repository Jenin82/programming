#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char message[BUFFER_SIZE] = {0};
	char buffer[BUFFER_SIZE] = {0};

	// Create socket
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	// Connect to the server
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	// Bidirectional communication loop
	while (1)
	{
		// Get user input
		printf("Client: ");
		fgets(message, BUFFER_SIZE, stdin);

		// Send data to the server
		send(sock, message, strlen(message), 0);

		// If the sent message is "exit", break the loop
		if (strcmp(message, "exit\n") == 0)
			break;

		// Receive response from the server
		valread = read(sock, buffer, BUFFER_SIZE);
		printf("Server: %s\n", buffer);
	}

	// Close the socket
	close(sock);

	return 0;
}
