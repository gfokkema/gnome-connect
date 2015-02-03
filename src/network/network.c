#include "../gnome-connect.h"

G_DEFINE_INTERFACE (GconnNetwork, gconn_network, 0);

static void
gconn_network_default_init (GconnNetworkInterface *self)
{
}

void
gconn_network_debug (GconnNetwork *self)
{
    g_return_if_fail (GCONN_IS_NETWORK (self));

    GCONN_NETWORK_GET_INTERFACE (self)->debug (self);
}
