#ifndef GCONN_MESSAGE_H_
#define GCONN_MESSAGE_H_

#include <json/json.h>
#include <string>

static const std::string GCONN_MESSAGE_STRING_IDENTITY = "kdeconnect.identity";
static const std::string GCONN_MESSAGE_STRING_PAIR = "kdeconnect.pair";

namespace Gconn {

class MsgPayload {
public:
    virtual ~MsgPayload() = 0;
    virtual Json::Value json() = 0;
};
inline MsgPayload::~MsgPayload() {};

class Message {
public:
    Message  (unsigned long id, std::string type, MsgPayload* payload);
    ~Message ();

    Json::Value json ();

    std::string   type;
    unsigned long id;
    MsgPayload*   payload;
};

}

#endif // GCONN_MESSAGE_H_
