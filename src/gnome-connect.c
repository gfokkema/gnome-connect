#include "gnome-connect.h"

#include <stdio.h>

GconnMsgFactory *msgfactory = NULL;

int
main()
{
    msgfactory = g_object_new (GCONN_TYPE_MSG_FACTORY, 0);

    GconnNetwork *udp_server = g_object_new (GCONN_TYPE_UDP, 0);
//    GconnNetwork *tcp_server = g_object_new (GCONN_TYPE_TCP, 0);

    GCONN_NETWORK_GET_INTERFACE (udp_server)->bind(udp_server, 1714);
    GCONN_NETWORK_GET_INTERFACE (udp_server)->listen(udp_server);
//    GCONN_NETWORK_GET_INTERFACE (tcp_server)->listen(tcp_server, 1714);

    g_object_unref (udp_server);

    return 0;
}
