#ifndef NETWORK_LISTENER_H_
#define NETWORK_LISTENER_H_

#include <gio/gio.h>

typedef struct NetworkListener
{
    GSocket *udp_socket, *tcp_socket;
    GSocket *udp_client_socket, *tcp_client_socket;
} NetworkListener;

typedef void (*NetworkCallback)(NetworkListener *server,
                                GInetAddress *inet_addr,
                                char* msg);

NetworkListener*    network_listener_new (int portno);
void                network_listener_udp_new(NetworkListener *server,
                                             int portno);
void                network_listener_udp_listen(NetworkListener *server,
                                                NetworkCallback ncb);
void                network_listener_tcp_connect(NetworkListener *server,
                                                 GInetAddress *sock_addr,
                                                 int portno);
void                network_listener_tcp_send(NetworkListener *server,
                                              char* msg);
void network_listener_udp_send (NetworkListener *server,
                                GInetAddress *inet_addr,
                                int portno,
                                char *msg);

#endif // NETWORK_LISTENER_H_
