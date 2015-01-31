#include "network.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NetworkListener*
network_listener_new (int portno)
{
    NetworkListener *server = malloc (sizeof(NetworkListener));
    network_listener_udp_new(server, portno);

    return server;
}

void
network_listener_udp_new(NetworkListener *server,
                         int portno)
{
    SAFE( server->udp_socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
                                             G_SOCKET_TYPE_DATAGRAM,
                                             G_SOCKET_PROTOCOL_UDP,
                                             &error) );
    GInetAddress    *inet_addr = g_inet_address_new_any (G_SOCKET_FAMILY_IPV4);
    GSocketAddress  *sock_addr = g_inet_socket_address_new (inet_addr, 1714);
    SAFE( g_socket_bind (server->udp_socket,
                         sock_addr,
                         TRUE,
                         &error) );
}

void
network_listener_udp_listen(NetworkListener *server,
                            NetworkCallback ncb)
{
    char buffer[256];
    while (TRUE)
    {
        int size;
        SAFE( size = g_socket_receive (server->udp_socket,
                                       buffer,
                                       sizeof(buffer),
                                       NULL,
                                       &error) );
        char* msg = g_strndup(buffer, size);
        ncb(msg);
    }
}
