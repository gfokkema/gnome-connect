#ifndef GCONN_NETWORK_H_
#define GCONN_NETWORK_H_

#include <giomm.h>
#include <gtkmm.h>

namespace Gconn {
    class Network {
    public:
        virtual void bind   (gint port) = 0;
        virtual void listen () = 0;
//        virtual void send   (Glib::RefPtr<Gio::InetAddress> sock_addr, gint port, std::string) = 0;

        sigc::signal<void, Glib::RefPtr<Gio::InetAddress>, std::string> signal_connected;
    };
};

#endif // GCONN_NETWORK_H_
