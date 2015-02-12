#ifndef GCONN_MSG_IDENTITY_H_
#define GCONN_MSG_IDENTITY_H_

#include "message.h"

namespace Gconn {

class MsgIdentity : public MsgPayload {
public:
    MsgIdentity  (JsonNode* data);
    MsgIdentity  (int protocol, char* devicename, char* devicetype, char* deviceID, int tcpport);
    ~MsgIdentity ();

    JsonNode* json ();

    int   protocol;
    int   tcpport;
    char* devicename;
    char* devicetype;
    char* deviceID;
};

}

#endif // GCONN_MSG_IDENTITY_H_
