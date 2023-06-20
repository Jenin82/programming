#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define SIZE 1024

int main()
{
	int server_fd, client_fd, valread;
	struct sockaddr_in server, client;
	char buffer[SIZE];
	socklen_t addr_size;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server, '\0', sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(server_fd, (struct sockaddr *)&server, sizeof(server));

	listen(server_fd, 5);
	
	addr_size = sizeof(client);
	client_fd = accept(server_fd, (struct sockaddr *)&client, &addr_size);

	valread = read(client_fd, buffer, SIZE);
	printf("Client: %s\n", buffer);

	char server_message[SIZE] = "Hello from server!";
	send(client_fd, server_message, strlen(server_message), 0);
	printf("Server: %s\n", server_message);

	close(client_fd);
	close(server_fd);

	return 0;
}
