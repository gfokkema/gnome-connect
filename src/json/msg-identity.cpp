#include "../gnome-connect.h"

Gconn::MsgIdentity::MsgIdentity(JsonNode *data)
{
    JsonObject *object = json_node_get_object (data);
    const char *devicename = json_object_get_string_member (object, "deviceName");
    const char *devicetype = json_object_get_string_member (object, "deviceType");
    const char *deviceID = json_object_get_string_member (object, "deviceId");

    this->protocol = json_object_get_int_member (object, "protocolVersion");
    this->tcpport =  json_object_get_int_member (object, "tcpPort");
    this->devicename = g_strndup(devicename, strlen(devicename));
    this->devicetype = g_strndup(devicetype, strlen(devicetype));
    this->deviceID =   g_strndup(deviceID, strlen(deviceID));
}

Gconn::MsgIdentity::MsgIdentity(int protocol,
                                char* devicename,
                                char* devicetype,
                                char* deviceID,
                                int tcpport)
: protocol(protocol), devicename(devicename), devicetype(devicetype), deviceID(deviceID), tcpport(tcpport)
{
}

Gconn::MsgIdentity::~MsgIdentity()
{
    g_free (this->devicename);
    g_free (this->devicetype);
    g_free (this->deviceID);
}

JsonNode*
Gconn::MsgIdentity::json()
{
    JsonBuilder *builder;
    JsonNode *root;

    builder = json_builder_new    ();
    json_builder_begin_object     (builder);
    json_builder_set_member_name  (builder, "protocolVersion");
    json_builder_add_int_value    (builder, protocol);
    json_builder_set_member_name  (builder, "deviceName");
    json_builder_add_string_value (builder, devicename);
    json_builder_set_member_name  (builder, "deviceType");
    json_builder_add_string_value (builder, devicetype);
    json_builder_set_member_name  (builder, "deviceId");
    json_builder_add_string_value (builder, deviceID);
    json_builder_set_member_name  (builder, "tcpPort");
    json_builder_add_int_value    (builder, tcpport);
    json_builder_end_object       (builder);
    root = json_builder_get_root  (builder);

    g_object_unref (builder);
    return root;
}
