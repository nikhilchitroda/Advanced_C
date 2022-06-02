/****************************************************
Filename: server.c
==================
 
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
	int socket_conn = 0, data_socket = 0, ret = 0, result = 0, num = 0;
#if 0
	struct sockaddr_un 
	{
		sa_family_t sun_family;               /* AF_UNIX */
		char        sun_path[108];            /* Pathname */
	};
#endif
	struct sockaddr_un name; 

	//In the case program exited inadvertently on the last run, remove the socket.
	unlink(SOCKET_NAME);

	//create the socket for server
	socket_conn = socket(AF_UNIX, SOCK_STREAM, 0);
	if(socket_conn == -1)
	{
		printf("Error, while creating socket inside server\n");
		return 1;
	}
	printf("Master socket its been created\n");

	//clear the struct contains
	memset(&name, 0, sizeof(struct sockaddr_un));

	//add the socket creadentials
	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, strlen(SOCKET_NAME));

	//to bind the socket to a well-known address
	ret = bind(socket_conn, (const struct sockaddr *) &name, sizeof(struct sockaddr_un));
	if(ret == -1)
        {
                printf("Error, while binding the socket to an addess\n");
                return 1;
        }
        printf("binded the socket to an addess\n");

	//to notify the kernel of its willingness to accept incoming connections
	ret = listen(socket_conn, 3);
	if(ret == -1)
        {
                printf("Error, while notifying the kernel of its willingness\n");
                return 1;
        }
        printf("notified the kernel of its willingness\n");

	while(1)
	{
		//create the data socket using accept() sys call
		printf("waiting to get request from client1 \n");
		data_socket = accept(socket_conn,NULL, NULL);
		if(data_socket == -1)
		{
			printf("Error, while binding the socket to an addess\n");
			return 1;
		}
		printf("accepted connection from client\n");

		//receive the num, until client sent num='0'
		result = 0;
		while(1)
		{
			printf("waiting to read data from client\n");
			ret = read(data_socket, &num, sizeof(int));
			printf("received data from client: %d\n", num);
			if(ret == -1)
			{
				printf("Error, while reading the data from client\n");
				return 1;
			}
			if(num == 0)
			{
				break;
			}
			result = result + num;
		}
		close(data_socket);

		//create the data socket using accept() sys call
                printf("\nwaiting to get request from client2\n");
                data_socket = accept(socket_conn,NULL, NULL);
                if(data_socket == -1)
                {
                        printf("Error, while binding the socket to an addess\n");
                        return 1;
                }
                printf("accepted connection from client\n");

		//sent the result to client
		ret = write(data_socket, &result, sizeof(int));
		if(ret == -1)
		{
			printf("Error, while writing the data from server\n");
			return 1;
		}
		//close the data socket 
		close(data_socket);
	}
	//close the master socket
	close(socket_conn);
	return 0;
}
