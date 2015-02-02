#include "gnome-connect.h"

#include <stdio.h>

NetworkListener*
network_listener_new (int portno)
{
    NetworkListener *server = malloc (sizeof(NetworkListener));
    network_listener_udp_new(server, portno);

    return server;
}

void
network_listener_delete (NetworkListener *server)
{
    g_object_unref (server->udp_socket);
    free (server);
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
    g_object_unref (sock_addr);
    g_object_unref (inet_addr);
}

void
network_listener_udp_listen(NetworkListener *server,
                            NetworkCallback ncb)
{
    char buffer[256];
//    while (TRUE)
//    {
        int size;
        GSocketAddress *sock_addr;
        GInetAddress *inet_addr;

        SAFE( size = g_socket_receive_from (server->udp_socket,
                                            &sock_addr,
                                            buffer,
                                            sizeof(buffer),
                                            NULL,
                                            &error) );
        char* msg = g_strndup(buffer, size);
        inet_addr = g_inet_socket_address_get_address ((GInetSocketAddress*)sock_addr);
        ncb(server, inet_addr, msg);
//    }
}

void
network_listener_tcp_connect (NetworkListener *server,
                              GInetAddress *inet_addr,
                              int portno)
{
    SAFE( server->tcp_socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
                                             G_SOCKET_TYPE_STREAM,
                                             G_SOCKET_PROTOCOL_TCP,
                                             &error) );
    GSocketAddress *sock_addr = g_inet_socket_address_new (inet_addr, portno);
    SAFE( g_socket_connect (server->tcp_socket,
                            sock_addr,
                            NULL,
                            &error) );
}

void
network_listener_tcp_send (NetworkListener *server,
                           char *msg)
{
    SAFE( g_socket_send (server->tcp_socket,
                         msg,
                         strlen(msg) + 1,
                         NULL,
                         &error) );

}

void
network_listener_tcp_listen (NetworkListener *server)
{
    GSocketAddress *sock_addr;
    GInetAddress *inet_addr;
    char buffer[2048];
    int size;

    SAFE( size = g_socket_receive_from (server->tcp_socket,
                                        &sock_addr,
                                        buffer,
                                        sizeof(buffer),
                                        NULL,
                                        &error) );
    printf("msg: %s\n", buffer);
}

void
network_listener_udp_connect (NetworkListener *server)
{
    SAFE( server->udp_client_socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
                                                    G_SOCKET_TYPE_DATAGRAM,
                                                    G_SOCKET_PROTOCOL_UDP,
                                                    &error) );
    GInetAddress    *inet_addr = g_inet_address_new_any (G_SOCKET_FAMILY_IPV4);
    GSocketAddress  *sock_addr = g_inet_socket_address_new (inet_addr, 22354);
    SAFE( g_socket_bind (server->udp_client_socket,
                         sock_addr,
                         TRUE,
                         &error) );
    g_socket_set_blocking (server->udp_client_socket, TRUE);
    g_object_unref (sock_addr);
    g_object_unref (inet_addr);

}

void
network_listener_udp_send (NetworkListener *server,
                           GInetAddress *inet_addr,
                           int portno,
                           char *msg)
{
    GSocketAddress *sock_addr = g_inet_socket_address_new (inet_addr, portno);
    SAFE( g_socket_send_to (server->udp_client_socket,
                            sock_addr,
                            msg,
                            strlen(msg) + 1,
                            NULL,
                            &error) );
    g_object_unref (sock_addr);
}
