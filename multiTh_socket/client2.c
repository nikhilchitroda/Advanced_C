#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<pthread.h>

void * cient2_Thread(void *arg)
{
	printf("In thread\n");
	char message[1000];
	char buffer[1024];
	int clientSocket;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7799);
	serverAddr.sin_addr.s_addr = inet_addr("10.126.67.57");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

	if(recv(clientSocket, buffer, 1024, 0) < 0)
	{
		printf("Receive failed\n");
	}
	printf("Data received: %s\n",buffer);

	close(clientSocket);
	pthread_exit(NULL);
}

int main()
{
	int i = 0;
	pthread_t tid;
	if(pthread_create(&tid, NULL, cient2_Thread, NULL) != 0)
	{
		printf("Failed to create thread\n");
	}
	pthread_join(tid,NULL);
	return 0;
}
