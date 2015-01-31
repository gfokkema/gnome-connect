#include <glib.h>
#include <stdio.h>

#include "network.h"

void
networkcb(char* msg)
{
    printf("%s\n", msg);
}

int
main()
{
    NetworkListener *server = network_listener_new(1714);
    network_listener_udp_listen(server, &networkcb);

    return 0;
}
