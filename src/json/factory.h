#ifndef GCONN_MSG_FACTORY_H_
#define GCONN_MSG_FACTORY_H_

namespace Gconn {

class Message;

class MsgFactory {
public:
    MsgFactory();
    ~MsgFactory();

    Gconn::Message* message(std::string msg);
    std::string     json(Message* msg);
};

}

#endif // GCONN_MSG_FACTORY_H_
