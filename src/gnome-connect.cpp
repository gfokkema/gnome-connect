#include "gnome-connect.h"

Gconn::MsgFactory *msgfactory = NULL;
Gconn::Network* udp_server = NULL;
Gconn::Network* tcp_server = NULL;

void
client_connected(Glib::RefPtr<Gio::InetAddress> inet_addr, gchar* text)
{
    Gconn::Message* msg;
    char* json;

    msg  = msgfactory->message(text);
    json = msg->json();

    std::cout << "echo: " << json << std::endl;
    tcp_server->send(inet_addr, ((Gconn::MsgIdentity*)msg->payload)->tcpport, json);

    free   (json);
    delete (msg);
}

int
main(int argc, gchar** argv)
{
    Gtk::Main kit(argc, argv);
    msgfactory = new Gconn::MsgFactory;

    udp_server = new Gconn::Udp;
    tcp_server = new Gconn::Tcp;
    udp_server->signal_connected.connect( sigc::ptr_fun(&client_connected) );

    udp_server->bind(1714);
    udp_server->listen();

    delete (udp_server);
    delete (tcp_server);

    return 0;
}
