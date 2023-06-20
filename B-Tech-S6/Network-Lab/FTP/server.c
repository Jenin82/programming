#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_file(FILE *fp, int sockfd)
{
	char data[BUFFER_SIZE] = {0};
	while (fgets(data, BUFFER_SIZE, fp) != NULL)
	{
		send(sockfd, data, strlen(data), 0);
		memset(data, 0, BUFFER_SIZE);
	}
}

int main()
{
	int sockfd, new_sockfd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	FILE *fp;
	char filename[BUFFER_SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(sockfd, 5);

	addr_size = sizeof(client_addr);
	new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);

	recv(new_sockfd, filename, BUFFER_SIZE, 0);
	fp = fopen(filename, "r");

	send_file(fp, new_sockfd);

	fclose(fp);
	close(new_sockfd);
	close(sockfd);

	return 0;
}
