#include "../gnome-connect.h"

static void gconn_network_interface_init (GconnNetworkInterface *self);

G_DEFINE_TYPE_WITH_CODE (GconnUdp, gconn_udp, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GCONN_TYPE_NETWORK,
                                                gconn_network_interface_init))

static void
gconn_udp_debug (GconnNetwork *self)
{
    g_print("Implementation from Udp class\n");
}

static void
gconn_network_interface_init (GconnNetworkInterface *self)
{
    self->debug = gconn_udp_debug;
}

static void
gconn_udp_init (GconnUdp *self)
{
    self = GCONN_UDP (self);
}

static void
gconn_udp_class_init (GconnUdpClass *self)
{
    self = GCONN_UDP_CLASS (self);
}

GconnUdp*
gconn_udp_new ()
{
    GconnUdp *server = g_object_new (GCONN_TYPE_UDP, 0);
    SAFE( server->socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
                                             G_SOCKET_TYPE_DATAGRAM,
                                             G_SOCKET_PROTOCOL_UDP,
                                             &error) );
    GInetAddress    *inet_addr = g_inet_address_new_any (G_SOCKET_FAMILY_IPV4);
    GSocketAddress  *sock_addr = g_inet_socket_address_new (inet_addr, 1714);
    SAFE( g_socket_bind (server->socket,
                         sock_addr,
                         TRUE,
                         &error) );
    g_object_unref (sock_addr);
    g_object_unref (inet_addr);

    return server;
}

//void
//network_listener_udp_listen(NetworkListener *server,
//                            NetworkCallback ncb)
//{
//    char buffer[256];
//    while (TRUE)
//    {
//        int size;
//        GSocketAddress *sock_addr;
//        GInetAddress *inet_addr;
//
//        SAFE( size = g_socket_receive_from (server->udp_socket,
//                                            &sock_addr,
//                                            buffer,
//                                            sizeof(buffer),
//                                            NULL,
//                                            &error) );
//        char* msg = g_strndup(buffer, size);
//        inet_addr = g_inet_socket_address_get_address ((GInetSocketAddress*)sock_addr);
//        ncb(server, inet_addr, msg);
//    }
//}
