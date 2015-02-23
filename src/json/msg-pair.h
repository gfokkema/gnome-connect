#ifndef GCONN_MSG_PAIR_H_
#define GCONN_MSG_PAIR_H_

#include "message.h"

namespace Gconn {

class MsgPair : public MsgPayload {
public:
    MsgPair  (Json::Value data);
    MsgPair  (std::string publickey, bool pair);
    ~MsgPair ();

    Json::Value json();

    std::string publickey;
    bool pair;
};

}

#endif // GCONN_MSG_PAIR_H_
