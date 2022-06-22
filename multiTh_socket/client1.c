#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<pthread.h>

void * cient1_Thread(void *arg)
{
	printf("In thread\n");
	char message[1000];
	char buffer[1024];
	int clientSocket;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	// Create the socket. 
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	//Configure settings of the server address
	// Address family is Internet 
	serverAddr.sin_family = AF_INET;

	//Set port number, using htons function 
	serverAddr.sin_port = htons(7799);

	//Set IP address to localhost
	serverAddr.sin_addr.s_addr = inet_addr("10.126.67.57");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	//Connect the socket to the server using the address
	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	
	printf("Enter msg to be send: \n");
	scanf("%[^\n]", message);

	printf("Tring to send msg..\n");
	if( send(clientSocket , message , strlen(message) , 0) < 0)
	{
		printf("Send failed\n");
	}
	else
		printf("msg sent..\n");

	close(clientSocket);
	pthread_exit(NULL);
}

int main()
{
	int i = 0;
	pthread_t tid;
	if( pthread_create(&tid, NULL, cient1_Thread, NULL) != 0 )
	{
		printf("Failed to create thread\n");
	}
	pthread_join(tid,NULL);
	return 0;
}
