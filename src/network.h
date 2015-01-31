#ifndef NETWORK_H_
#define NETWORK_H_

#include <glib.h>
#include <gio/gio.h>

#define MAX_THREADS 10

#define SAFE( call)                                             \
{                                                               \
    GError *error = NULL;                                       \
    call;                                                       \
    if (error != NULL)                                          \
        g_error (error->message);                               \
}

typedef struct NetworkListener
{
    GSocket *udp_socket, *tcp_socket;
} NetworkListener;

typedef void (*NetworkCallback)(char* msg);

NetworkListener*    network_listener_new (int portno);
void                network_listener_udp_new(NetworkListener *server,
                                             int portno);
void                network_listener_udp_listen(NetworkListener *server,
                                                NetworkCallback ncb);


#endif // NETWORK_H_
