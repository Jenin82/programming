#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void receive_file(int sockfd, FILE *fp)
{
	char data[BUFFER_SIZE] = {0};
	while (recv(sockfd, data, BUFFER_SIZE, 0) > 0)
	{
		fputs(data, fp);
		memset(data, 0, BUFFER_SIZE);
	}
}

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;
	FILE *fp;
	char *filename;
	char server_ip[BUFFER_SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	printf("Enter server IP address: ");
	fgets(server_ip, BUFFER_SIZE, stdin);
	server_ip[strcspn(server_ip, "\n")] = 0;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(server_ip);

	connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	printf("Enter the filename to request: ");
	filename = (char *)malloc(BUFFER_SIZE * sizeof(char));
	fgets(filename, BUFFER_SIZE, stdin);
	filename[strcspn(filename, "\n")] = 0;

	send(sockfd, filename, BUFFER_SIZE, 0);

	fp = fopen(filename, "w");
	receive_file(sockfd, fp);

	fclose(fp);
	close(sockfd);

	return 0;
}
