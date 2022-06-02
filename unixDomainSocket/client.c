/*****************************************************
Filename: client.c
==================
1. create socket
2. connect
3. read/write
4. close data_socket
5. close master_socket

Note: client will send the numbers & server will count the all number which are sent by the client..
If client sent '0' then, server will stop to count & sent the Result to client ..
And client will receive the Result & print it in the console.
 
*******************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>

#define SOCKET_NAME "/tmp/demoSocket"  

int main()
{
	int data_socket = 0, ret = 0, result = 0, num = 0;
#if 0
	struct sockaddr_un 
	{
		sa_family_t sun_family;               /* AF_UNIX */
		char        sun_path[108];            /* Pathname */
	};
#endif
	struct sockaddr_un name; 

	//create the socket for client
	data_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	if(data_socket == -1)
	{
		printf("Error, while creating socket inside client\n");
		return 1;
	}
	printf("socket its been created\n");

	//clear the struct contains
	memset(&name, 0, sizeof(struct sockaddr_un));

	//add the socket creadentials
	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, strlen(SOCKET_NAME));

	//sent connection request to socket addr
	ret = connect(data_socket, (const struct sockaddr *) &name, sizeof(struct sockaddr_un));
	if(ret == -1)
        {
                printf("Error, while adding connection request\n");
                return 1;
        }
        printf("sent the connection request\n");

	//sent number='0' to server, to get total sum from server
	do
	{
		printf("Enter number to send: ");
		scanf("%d", &num);
		ret=write(data_socket, &num, sizeof(int));
                if(ret == -1)
                {
                        printf("Error, while writing the data from client\n");
                        return 1;
                }
		printf("Num is: %d sent\n", num);
	}while(num!=0);

	//read the total sum value from server
	ret=read(data_socket, &num, sizeof(int));
	if(ret == -1)
	{
		printf("Error, while reading from server\n");
		return 1;
	}
	printf("Received from server: %d\n", num);

	//close the socket connection
	close(data_socket);
	return 0;
}
