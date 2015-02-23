#include "gnome-connect.h"

Gconn::MsgFactory *msgfactory = NULL;
Gconn::Network* udp_server = NULL;
Gconn::Network* tcp_server = NULL;
std::vector<Gconn::Device*> devices;

void
client_connected(Glib::RefPtr<Gio::InetAddress> inet_addr, std::string text)
{
    Gconn::Message* msg;
    Gconn::Device* device;

    msg    = msgfactory->message(text);
    device = new Gconn::Device((Gconn::MsgIdentity*)msg->payload, inet_addr);
    devices.push_back(device);

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

    Gconn::MsgPayload* payload = new Gconn::MsgIdentity(5, "arch-laptop", "desktop", "debug-id", 1714);
    Gconn::Message* msg = new Gconn::Message(1, GCONN_MESSAGE_STRING_IDENTITY, payload);
    Gconn::MsgPayload* payloadpair = new Gconn::MsgPair("-----BEGIN PUBLIC KEY-----\n"
                                                        "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAu0YYysfLJUBk/V3CcDS+RtDEvUj"
                                                        "J657D\n4Q/GUBUC8PIsoHiusj5o3O8mPa2PjVKW25NETfretTcNV7T3hVVhWcPCcvn2uGQ0"
                                                        "RhsON4hYCaKo\nocHGzpfB/03a+Mn1eeDIyZFlb4vWQC+IQOtGR0HVG/uvVJJF9ySM1oX7C"
                                                        "ne+wBl+zSEUcqR7hAQC\nbECOmbXswSsn7K70aj5kvGbj7nOtC5HO+RvUKbJeblfIFslqhk"
                                                        "qzMfxCHsdnMvDdBbu2Vp2kX3R4\nM/P7Y0G4mlbEMTd7x8iYd/dg3YGy2neDRjAoR03y6xj"
                                                        "ZEPLwFwERYgqmz9ihEU9+NcxN6+0k2B/J\nebM/aQIDAQAB\n"
                                                        "-----END PUBLIC KEY-----\n", true);
    Gconn::Message* msg_pair = new Gconn::Message(1, GCONN_MESSAGE_STRING_PAIR, payloadpair);
    udp_server->bind(1714);
    while (true) {
        udp_server->listen();
//        udp_server->send(devices.front()->inet_addr, devices.front()->port, msgfactory->json(msg).c_str());
        devices.front()->send(msgfactory->json(msg).c_str());
        devices.front()->receive();
        devices.front()->send(msgfactory->json(msg_pair).c_str());
    }

    delete (msg);
    delete (udp_server);
    delete (tcp_server);

    return 0;
}
