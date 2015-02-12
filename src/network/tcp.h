#ifndef GCONN_TCP_H_
#define GCONN_TCP_H_

#include "network.h"

namespace Gconn {

class Tcp : public Network {
public:
    Tcp();
    ~Tcp();

    void bind(gint port);
    void listen();
    void send(Glib::RefPtr<Gio::InetAddress> sock_addr, gint port, gchar* msg);
private:
    Glib::RefPtr<Gio::Socket> socket;
};

}

#endif // GCONN_TCP_H_
