#include "../gnome-connect.h"

G_DEFINE_TYPE (GconnMsgPair, gconn_msg_pair, G_TYPE_OBJECT)

static void
gconn_msg_pair_class_init (GconnMsgPairClass *klass)
{
}

static void
gconn_msg_pair_init (GconnMsgPair *self)
{
}

GconnMsgPair*
gconn_msg_pair_new (JsonNode *data)
{
    JsonObject *object = json_node_get_object (data);
    const char *publickey = json_object_get_string_member (object, "publickey");

    GconnMsgPair* msg = g_object_new (GCONN_TYPE_MSG_PAIR, 0);
    msg->publickey = g_strndup(publickey, strlen(publickey));
    msg->pair      = json_object_get_boolean_member (object, "pair");

    return msg;
}
