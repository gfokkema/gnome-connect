#include "../gnome-connect.h"

Gconn::MsgPair::MsgPair(Json::Value data)
{
    this->publickey = data["publickey"].asString();
    this->pair      = data["pair"].asBool();
}

Gconn::MsgPair::MsgPair(std::string publickey,
                        bool pair)
: publickey(publickey),
  pair(pair)
{
}

Gconn::MsgPair::~MsgPair()
{
}

Json::Value
Gconn::MsgPair::json()
{
    Json::Value root;
    root["publickey"] = this->publickey;
    root["pair"] = this->pair;

    return root;
}
