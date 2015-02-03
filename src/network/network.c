#include "../gnome-connect.h"

G_DEFINE_INTERFACE (GconnNetwork, gconn_network, 0);

static void
gconn_network_default_init (GconnNetworkInterface *self)
{
}

void
gconn_network_bind (GconnNetwork *self, gint port)
{
    g_return_if_fail (GCONN_IS_NETWORK (self));
    GCONN_NETWORK_GET_INTERFACE (self)->bind (self, port);
}

void
gconn_network_listen (GconnNetwork *self)
{
    g_return_if_fail (GCONN_IS_NETWORK (self));
    GCONN_NETWORK_GET_INTERFACE (self)->listen (self);
}
