#include "../gnome-connect.h"

Gconn::MsgIdentity::MsgIdentity(Json::Value data)
{
    this->protocol   = data["protocolVersion"].asInt();
    this->devicename = data["deviceName"].asString();
    this->devicetype = data["deviceType"].asString();
    this->deviceID   = data["devideId"].asString();
    this->tcpport    = data["tcpPort"].asInt();
}

Gconn::MsgIdentity::MsgIdentity(int protocol,
                                std::string devicename,
                                std::string devicetype,
                                std::string deviceID,
                                int tcpport)
: protocol(protocol),
  devicename(devicename),
  devicetype(devicetype),
  deviceID(deviceID),
  tcpport(tcpport)
{
}

Gconn::MsgIdentity::~MsgIdentity()
{
}

Json::Value
Gconn::MsgIdentity::json()
{
    Json::Value root;
    root["protocolVersion"] = 5;
    root["deviceName"]      = this->devicename;
    root["deviceType"]      = this->devicetype;
    root["deviceId"]        = this->deviceID;
    root["tcpPort"]         = this->tcpport;

    return root;
}
