#ifndef GCONN_UDP_H_
#define GCONN_UDP_H_

#include "network.h"

namespace Gconn {

class Udp : public Network {
public:
    Udp();
    ~Udp();

    void bind(gint port);
    void listen();
    void send(Glib::RefPtr<Gio::InetAddress> sock_addr, gint port, gchar* msg);
private:
    Glib::RefPtr<Gio::Socket> socket;
};

}

#endif // GCONN_UDP_H_
