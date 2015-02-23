#include "gnome-connect.h"

Gconn::Device::Device(std::string devicename,
                      std::string deviceid,
                      int port,
                      std::string devicetype,
                      int protocol)
: protocol(protocol),
  devicename(devicename),
  devicetype(devicetype),
  deviceid(deviceid),
  port(port),
  paired(false),
  publickey("")
{
}

Gconn::Device::Device(MsgIdentity* msg, Glib::RefPtr<Gio::InetAddress> inet_addr)
: protocol(msg->protocol),
  devicename(msg->devicename),
  devicetype(msg->devicetype),
  deviceid(msg->deviceID),
  port(msg->tcpport),
  inet_addr(inet_addr),
  paired(false),
  publickey("")
{
}

Gconn::Device::~Device()
{
    socket->close();
}

void
Gconn::Device::pair(MsgPair* msg)
{
    this->publickey = msg->publickey;
}

void
Gconn::Device::connect()
{
    if (socket && socket->is_connected()) return;

    std::cout << "Connecting..." << std::endl;
    try
    {
        Glib::RefPtr<Gio::SocketAddress> sock_addr = Gio::InetSocketAddress::create(inet_addr, port);
        socket = Gio::Socket::create(Gio::SOCKET_FAMILY_IPV4,
                                     Gio::SOCKET_TYPE_STREAM,
                                     Gio::SOCKET_PROTOCOL_TCP);
        socket->set_keepalive(true);
        socket->connect(sock_addr);
    }
    catch (Glib::Error e)
    {
        std::cout << e.what() << std::endl;
        socket->close();
    }
}

void
Gconn::Device::receive()
{
    connect();

    char buf[1024] = { 0 };
    try
    {
        socket->receive(buf, sizeof(buf));
        printf("%s\n", buf);
    }
    catch (Glib::Error e)
    {
        std::cout << e.what() << std::endl;
        socket->close();
    }
}

void
Gconn::Device::send(std::string msg)
{
    connect();

    try
    {
        socket->send(msg.c_str(), msg.size());
    }
    catch (Glib::Error e)
    {
        std::cout << e.what() << std::endl;
        socket->close();
    }

}
