#include "../gnome-connect.h"

static void gconn_network_interface_init (GconnNetworkInterface *self);

G_DEFINE_TYPE_WITH_CODE (GconnTcp, gconn_tcp, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GCONN_TYPE_NETWORK,
                                                gconn_network_interface_init))

static void
gconn_tcp_debug (GconnNetwork *self)
{
    g_print("Implementation from Tcp class\n");
}

static void
gconn_network_interface_init (GconnNetworkInterface *self)
{
    self->debug = gconn_tcp_debug;
}

static void
gconn_tcp_init (GconnTcp *self)
{
    self = GCONN_TCP (self);
}

static void
gconn_tcp_class_init (GconnTcpClass *self)
{
    self = GCONN_TCP_CLASS (self);
}

//void
//network_listener_tcp_connect (NetworkListener *server,
//                              GInetAddress *inet_addr,
//                              int portno)
//{
//    SAFE( server->tcp_socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
//                                             G_SOCKET_TYPE_STREAM,
//                                             G_SOCKET_PROTOCOL_TCP,
//                                             &error) );
//    GSocketAddress *sock_addr = g_inet_socket_address_new (inet_addr, portno);
//    SAFE( g_socket_connect (server->tcp_socket,
//                            sock_addr,
//                            NULL,
//                            &error) );
//}
//
//void
//network_listener_tcp_send (NetworkListener *server,
//                           char *msg)
//{
//    SAFE( g_socket_send (server->tcp_socket,
//                         msg,
//                         strlen(msg) + 1,
//                         NULL,
//                         &error) );
//
//}
//
//void
//network_listener_tcp_listen (NetworkListener *server)
//{
//    GSocketAddress *sock_addr;
//    GInetAddress *inet_addr;
//    char buffer[2048];
//    int size;
//
//    SAFE( size = g_socket_receive_from (server->tcp_socket,
//                                        &sock_addr,
//                                        buffer,
//                                        sizeof(buffer),
//                                        NULL,
//                                        &error) );
//    printf("msg: %s\n", buffer);
//}
