#include "../gnome-connect.h"

static void gconn_network_interface_init (GconnNetworkInterface *self);

G_DEFINE_TYPE_WITH_CODE (GconnUdp, gconn_udp, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GCONN_TYPE_NETWORK,
                                                gconn_network_interface_init))

static void
gconn_udp_dispose (GObject *gobject)
{
    GconnUdp *self = GCONN_UDP (gobject);
    g_clear_object (&self->socket);
}

static void
gconn_udp_bind (GconnUdp *self, gint port)
{
    g_print("Implementation from Udp class\n");

    SAFE( self->socket = g_socket_new (G_SOCKET_FAMILY_IPV4,
                                       G_SOCKET_TYPE_DATAGRAM,
                                       G_SOCKET_PROTOCOL_UDP,
                                       &error) );
    GInetAddress   *inet_addr = g_inet_address_new_any    (G_SOCKET_FAMILY_IPV4);
    GSocketAddress *sock_addr = g_inet_socket_address_new (inet_addr, port);
    SAFE( g_socket_bind (self->socket,
                         sock_addr,
                         TRUE,
                         &error) );
    g_object_unref (sock_addr);
    g_object_unref (inet_addr);
}

void
gconn_udp_listen (GconnUdp *self)
{
    gchar buffer[256];
    int size;
    SAFE( size = g_socket_receive (self->socket,
                                   buffer,
                                   sizeof(buffer),
                                   NULL,
                                   &error) );
    gchar *msg = g_strndup (buffer, size);
    g_print (msg);
    g_free  (msg);
}

static void
gconn_network_interface_init (GconnNetworkInterface *self)
{
    self->bind   = gconn_udp_bind;
    self->listen = gconn_udp_listen;
}

static void
gconn_udp_init (GconnUdp *self)
{
}

static void
gconn_udp_class_init (GconnUdpClass *self)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS (self);

    gobject_class->dispose = gconn_udp_dispose;
}
