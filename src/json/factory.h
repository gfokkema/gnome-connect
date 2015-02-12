#ifndef GCONN_MSG_FACTORY_H_
#define GCONN_MSG_FACTORY_H_

#include "message.h"

namespace Gconn {

class MsgFactory {
public:
    MsgFactory();
    ~MsgFactory();

    Gconn::Message* message(gchar* msg);
};

}

#endif // GCONN_MSG_FACTORY_H_
