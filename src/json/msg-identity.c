#include "../gnome-connect.h"

G_DEFINE_TYPE (GconnMsgIdentity, gconn_msg_identity, G_TYPE_OBJECT)

static void
gconn_msg_identity_class_init (GconnMsgIdentityClass *klass)
{
}

static void
gconn_msg_identity_init (GconnMsgIdentity *self)
{
}

GconnMsgIdentity*
gconn_msg_identity_new (JsonNode *data)
{
    JsonObject *object = json_node_get_object (data);
    const char *devicename = json_object_get_string_member (object, "deviceName");
    const char *devicetype = json_object_get_string_member (object, "deviceType");
    const char *deviceID = json_object_get_string_member (object, "deviceId");

    GconnMsgIdentity* msg = g_object_new (GCONN_TYPE_MSG_IDENTITY, 0);
    msg->protocol = json_object_get_int_member (object, "protocolVersion");
    msg->tcpport =  json_object_get_int_member (object, "tcpPort");
    msg->devicename = g_strndup(devicename, strlen(devicename));
    msg->devicetype = g_strndup(devicetype, strlen(devicetype));
    msg->deviceID =   g_strndup(deviceID, strlen(deviceID));

    return msg;
}
