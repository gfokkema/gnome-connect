#ifndef GCONN_MESSAGE_H_
#define GCONN_MESSAGE_H_

#include <json-glib/json-glib.h>

#define GCONN_MESSAGE_STRING_IDENTITY "kdeconnect.identity"
#define GCONN_MESSAGE_STRING_PAIR     "kdeconnect.pair"

namespace Gconn {

class MsgPayload {
public:
    virtual ~MsgPayload() = 0;
    virtual JsonNode* json() = 0;
};
inline MsgPayload::~MsgPayload() {};

class Message {
public:
    Message  (JsonNode* data);
    Message  (int id, char* type, MsgPayload* payload);
    ~Message ();

    char* json ();

    char*  type;
    unsigned long id;
    MsgPayload*   payload;
};

}

#endif // GCONN_MESSAGE_H_
