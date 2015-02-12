#ifndef GCONN_MSG_PAIR_H_
#define GCONN_MSG_PAIR_H_

#include "message.h"

namespace Gconn {

class MsgPair : public MsgPayload {
public:
    MsgPair  (JsonNode* data);
    MsgPair  (char* publickey, bool pair);
    ~MsgPair ();

    JsonNode* json();

    char* publickey;
    bool pair;
};

}

#endif // GCONN_MSG_PAIR_H_
