#include "../gnome-connect.h"

Gconn::Message::Message(unsigned long id, std::string type, MsgPayload* payload)
: id(id), type(type), payload(payload)
{
}

Gconn::Message::~Message()
{
    delete (payload);
}

Json::Value
Gconn::Message::json() {
    Json::Value root;
    root["type"] = this->type;
    root["id"]   = Json::Int64(g_get_real_time());
    root["body"] = payload->json();

    return root;
}
