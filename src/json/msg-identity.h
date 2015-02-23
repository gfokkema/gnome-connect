#ifndef GCONN_MSG_IDENTITY_H_
#define GCONN_MSG_IDENTITY_H_

#include "message.h"

namespace Gconn {

class MsgIdentity : public MsgPayload {
public:
    MsgIdentity  (Json::Value data);
    MsgIdentity  (int protocol, std::string devicename, std::string devicetype, std::string deviceID, int tcpport);
    ~MsgIdentity ();

    Json::Value json ();

    int   protocol;
    int   tcpport;
    std::string devicename;
    std::string devicetype;
    std::string deviceID;
};

}

#endif // GCONN_MSG_IDENTITY_H_
