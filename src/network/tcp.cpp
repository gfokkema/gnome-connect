#include "../gnome-connect.h"

Gconn::Tcp::Tcp()
{
    try {
        this->socket = Gio::Socket::create(Gio::SOCKET_FAMILY_IPV4,
                                           Gio::SOCKET_TYPE_STREAM,
                                           Gio::SOCKET_PROTOCOL_TCP);
    } catch (const Gio::Error& error) {
        std::cerr << error.what() << std::endl;
    }
}

Gconn::Tcp::~Tcp()
{
}

void
Gconn::Tcp::bind(gint port)
{
    std::cout << "Stub from Tcp class" << std::endl;
}

void
Gconn::Tcp::listen()
{
    std::cout << "Stub from Tcp class" << std::endl;
}

void
Gconn::Tcp::send(Glib::RefPtr<Gio::InetAddress> inet_addr, gint port, gchar* msg)
{
    Glib::RefPtr<Gio::SocketAddress> sock_addr = Gio::InetSocketAddress::create(inet_addr, port);
    this->socket->connect(sock_addr);
    this->socket->send(msg, strlen(msg) + 1);
}

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
