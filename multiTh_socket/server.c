#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<pthread.h>

char client_message[2000];
char buffer[1024];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * socket1_Thread(void *arg)
{
	int newSocket = *((int *)arg);
	recv(newSocket , client_message , 2000 , 0);
	printf("Received msg: %s\n", client_message);

	printf("Exit socketThread \n");
	close(newSocket);
	pthread_exit(NULL);
}

void * socket2_Thread(void *arg)
{
	int newSocket = *((int *)arg);
	send(newSocket,client_message,2000,0);
	printf("Exit socketThread \n");
	close(newSocket);
	pthread_exit(NULL);
}


int main()
{
	int i = 0, serverSocket, newSocket, count=0, addr_len=0;
	struct sockaddr_in serverAddr, client_addr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7799);
	serverAddr.sin_addr.s_addr = inet_addr("10.126.67.57");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(serverSocket,10)==0)
		printf("Listening\n");
	else
		printf("Error\n");
	
	pthread_t tid[2];
	
	while(1)
	{
		for(count=0; count<2; count++)
		{
			newSocket = accept(serverSocket, (struct sockaddr *) &client_addr, &addr_len);
			printf("Connection accepted from client : %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

			if(count == 0)
			{
				if( pthread_create(&tid[count], NULL, socket1_Thread, &newSocket) != 0 )
					printf("Failed to create thread\n");
			}
			else
			{
				pthread_join(tid[0],NULL);
				if( pthread_create(&tid[count], NULL, socket2_Thread, &newSocket) != 0 )
					printf("Failed to create thread\n");
			}
		}
		pthread_join(tid[1],NULL);
	}
	return 0;
}
