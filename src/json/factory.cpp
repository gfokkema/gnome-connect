#include "../gnome-connect.h"

Gconn::MsgFactory::MsgFactory() {}
Gconn::MsgFactory::~MsgFactory() {}

Gconn::Message*
Gconn::MsgFactory::message(std::string text)
{
    Json::Value root;
    Json::Reader reader;
    Gconn::Message *msg;
    Gconn::MsgPayload *payload;

    reader.parse(text, root, false);
    if (root["type"].compare(GCONN_MESSAGE_STRING_IDENTITY) == 0)
    {
        payload = new Gconn::MsgIdentity(root["body"]);
    }
    else if (root["type"].compare(GCONN_MESSAGE_STRING_PAIR) == 0)
    {
        payload = new Gconn::MsgPair(root["body"]);
    }
    else
    {
        std::cout << "something strange happened" << std::endl;
    }
    msg = new Gconn::Message(root["id"].asInt64(), root["type"].asString(), payload);

    return msg;
}

std::string
Gconn::MsgFactory::json(Gconn::Message* msg)
{
    Json::FastWriter writer;
    return writer.write(msg->json());
}
