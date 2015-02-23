#ifndef GCONN_DEVICE_H_
#define GCONN_DEVICE_H_

#include <string>

namespace Gconn {

class MsgIdentity;
class MsgPair;

class Device {
public:
    Device  (std::string devicename,
             std::string deviceid,
             int port = 1714,
             std::string devicetype = "desktop",
             int protocol = 5);
    Device  (Gconn::MsgIdentity* identitymsg, Glib::RefPtr<Gio::InetAddress> inet_addr);
    ~Device ();

    void connect ();
    void receive ();
    void send    (std::string msg);
    void pair    (Gconn::MsgPair* pairmsg);
//private:
    int         protocol;
    int         port;
    bool        paired;
    std::string devicename;
    std::string devicetype;
    std::string deviceid;
    std::string publickey;
    Glib::RefPtr<Gio::InetAddress> inet_addr;
    Glib::RefPtr<Gio::Socket> socket;
};

}

#endif // GCONN_DEVICE_H_
