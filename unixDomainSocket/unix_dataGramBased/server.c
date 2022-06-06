#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<ctype.h>
#include<unistd.h>

#define SOCKET_NAME "/tmp/demoSocket"
#define MAXLINE 1024

int main()
{
	int n=0, socket_conn=0, ret=0, len=0;
	char buffer[MAXLINE];
#if 0
        struct sockaddr_un 
        {
                sa_family_t sun_family;               /* AF_UNIX */
                char        sun_path[108];            /* Pathname */
        };
#endif
	struct sockaddr_un servaddr, cliaddr;
	len = sizeof(cliaddr);

        //In the case program exited inadvertently on the last run, remove the socket.
        unlink(SOCKET_NAME);

	//create the socket for server
        socket_conn = socket(AF_UNIX, SOCK_DGRAM, 0);
        if(socket_conn == -1)
        {
                printf("Error, while creating socket inside server\n");
                return 1;
        }
        printf("socket, its been created\n");

        //clear the struct contains
        memset(&servaddr, 0, sizeof(struct sockaddr_un));
        memset(&cliaddr, 0, sizeof(struct sockaddr_un));

	//add the socket creadentials
        servaddr.sun_family = AF_UNIX;
        strncpy(servaddr.sun_path, SOCKET_NAME, strlen(SOCKET_NAME));

	//to bind the socket to a well-known address
        ret = bind(socket_conn, (const struct sockaddr *) &servaddr, sizeof(struct sockaddr_un));
        if(ret == -1)
        {
                printf("Error, while binding the socket to an addess\n");
                return 1;
        }
        printf("binded the socket to an addess\n");

	while(1)
	{
		n = recvfrom(socket_conn, (char *)buffer, MAXLINE, 0, ( struct sockaddr *)&cliaddr, &len);
		buffer[n] = '\0';
		printf("Client : %s\n", buffer);

		if( sendto(socket_conn, (const char *)"hello", strlen("hello"), 0, (const struct sockaddr *)&cliaddr, len) != strlen("hello"))
		{
			printf("Error, while send msg to client\n");
                	return 2;
		}
		printf("Hello message sent.\n");
	}
	return 0;
	close(socket_conn);
}

