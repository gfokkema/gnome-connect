#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "json-message.h"

#define SAFE( call)                                             \
{                                                               \
    int n;                                                      \
    SAFE_SOCKET( n, call)                                       \
}

#define SAFE_SOCKET( socket, call)                              \
{                                                               \
    socket = call;                                              \
    if (socket < 0)                                             \
    {                                                           \
        fprintf(stderr, "Error in file '%s' in line %i: %d.\n", \
                __FILE__, __LINE__, socket);                    \
                exit(EXIT_FAILURE);                             \
    }                                                           \
}

typedef struct sockaddr_in sockaddr_in;

char*
listen_udp (int portno)
{
    int sockfd;
    socklen_t clilen;
    sockaddr_in serv_addr, cli_addr;

    SAFE_SOCKET( sockfd, socket(AF_INET, SOCK_DGRAM, 0) );

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    SAFE( bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) );

    char *buffer = calloc(256, sizeof(char));
    clilen = sizeof(cli_addr);
    SAFE( recvfrom(sockfd, buffer, 256, 0,
                   (struct sockaddr *) &cli_addr, &clilen) );
    //         SAFE( sendto  (sockfd, buffer, strlen(buffer), 0,
    //                        (struct sockaddr *) &cli_addr, sizeof(cli_addr)) );
    return buffer;
}

int main()
{
    JsonMessage *msg = json_message_new(listen_udp(1714));
    printf("%ld %s\n", msg->id, msg->type);

    return 0;
}
