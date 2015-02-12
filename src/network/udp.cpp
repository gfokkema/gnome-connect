#include "../gnome-connect.h"

Gconn::Udp::Udp()
{
    try {
        this->socket = Gio::Socket::create(Gio::SOCKET_FAMILY_IPV4,
                                           Gio::SOCKET_TYPE_DATAGRAM,
                                           Gio::SOCKET_PROTOCOL_UDP);
    } catch (const Gio::Error& error) {
        std::cerr << error.what() << std::endl;
    }
}

Gconn::Udp::~Udp()
{
}

void
Gconn::Udp::bind(gint port)
{
    Glib::RefPtr<Gio::InetAddress>   inet_addr = Gio::InetAddress::create_any(Gio::SOCKET_FAMILY_IPV4);
    Glib::RefPtr<Gio::InetSocketAddress> sock_addr = Gio::InetSocketAddress::create(inet_addr, port);
    try {
        this->socket->bind(sock_addr, false);
    } catch (const Gio::Error& error) {
        std::cerr << error.what() << std::endl;
    }
}

void
Gconn::Udp::listen()
{
    gchar buffer[256];
    Glib::RefPtr<Gio::SocketAddress> sock_addr;
    socket->receive_from(sock_addr, buffer, sizeof(buffer));

    gchar *msg = g_strndup (buffer, strlen(buffer));
    Glib::RefPtr<Gio::InetAddress> inet_addr = Glib::RefPtr<Gio::InetSocketAddress>::cast_dynamic(sock_addr)->get_address();
    signal_connected(inet_addr, msg);

    g_free  (msg);
}

void
Gconn::Udp::send(Glib::RefPtr<Gio::InetAddress> sock_addr, gint port, gchar* msg)
{
    std::cout << "Stub from Udp class" << std::endl;
}
