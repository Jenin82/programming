#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};

	// Create socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Socket created successfully\n");

	// Set socket options
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("Setsockopt failed");
		exit(EXIT_FAILURE);
	}
	printf("Socket options set successfully\n");

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Bind the socket to the specified port
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Socket binding successful\n");

	// Listen for incoming connections
	if (listen(server_fd, 3) < 0)
	{
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Listening for incoming connections...\n");

	// Accept incoming connection
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("Accept failed");
		exit(EXIT_FAILURE);
	}
	printf("Connection accepted\n");

	// Bidirectional communication loop
	while (1)
	{
		// Receive data from the client
		valread = read(new_socket, buffer, BUFFER_SIZE);
		printf("Client: %s\n", buffer);

		// If the received message is "exit", break the loop
		if (strcmp(buffer, "exit\n") == 0)
			break;

		// Get server message input
		printf("Server: ");
		fgets(buffer, BUFFER_SIZE, stdin);

		// Send server message to the client
		send(new_socket, buffer, strlen(buffer), 0);
	}

	// Close the socket
	close(new_socket);

	return 0;
}
