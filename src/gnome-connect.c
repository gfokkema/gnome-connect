#include "gnome-connect.h"

#include <stdio.h>

GconnMsgFactory *msgfactory = NULL;

void
networkcb (NetworkListener *server,
           GInetAddress *inet_addr,
           char* msg)
{
    GconnMessage* json = gconn_msg_factory_message(msgfactory, msg);
    printf("id: %ld msg: %s\n", json->id, json->type);

//    network_listener_udp_connect (server);
//    network_listener_udp_send    (server, inet_addr, 1714, json_message_create_identity ());
    network_listener_tcp_connect(server, inet_addr, GCONN_MSG_IDENTITY(json->payload)->tcpport);
    network_listener_tcp_send(server, json_message_create_identity ());

    g_object_unref (json);
}

int
main()
{
    msgfactory = g_object_new (GCONN_TYPE_MSG_FACTORY, 0);

    NetworkListener *server = network_listener_new (1714);
    while (TRUE)
        network_listener_udp_listen (server, &networkcb);
    network_listener_delete (server);

    return 0;
}
