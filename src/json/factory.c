#include "../gnome-connect.h"

#include <stdio.h>

G_DEFINE_TYPE (GconnMsgFactory, gconn_msg_factory, G_TYPE_OBJECT)

static void
gconn_msg_factory_class_init (GconnMsgFactoryClass *klass)
{
}

static void
gconn_msg_factory_init (GconnMsgFactory *self)
{
}

GconnMsgFactory*
gconn_msg_factory_new (void)
{
    return g_object_new (GCONN_TYPE_MSG_FACTORY, 0);
}

GconnMessage*
gconn_msg_factory_message (GconnMsgFactory *self,
                           gchar *msg)
{
    JsonParser *parser;
    JsonNode *root, *body;
    JsonObject *object;
    GconnMessage *jsonmsg;

    parser = json_parser_new();
    SAFE( json_parser_load_from_data (parser, msg, strlen(msg), &error) );
    root = json_parser_get_root (parser);
    object = json_node_get_object (root);
    body = json_object_get_member (object, "body");

    const char *type = json_object_get_string_member (object, "type");
    jsonmsg = g_object_new (GCONN_TYPE_MESSAGE, 0);
    jsonmsg->id = json_object_get_int_member (object, "id");
    jsonmsg->type = g_strndup(type, strlen(type));

    printf("%s\n", type);
    if (strncmp (GCONN_MESSAGE_STRING_IDENTITY, type, strlen(type)) == 0)
    {
        jsonmsg->payload = GCONN_MSG_PAYLOAD (gconn_msg_identity_new (body));
        printf("%s\n", GCONN_MSG_IDENTITY(jsonmsg->payload)->devicename);
    }
    else if (strncmp (GCONN_MESSAGE_STRING_PAIR, type, strlen(type)) == 0)
    {
        jsonmsg->payload = GCONN_MSG_PAYLOAD (gconn_msg_pair_new     (body));
        printf("%s\n", GCONN_MSG_PAIR(jsonmsg->payload)->publickey);
    }

    g_object_unref (parser);
    free (msg);
    return jsonmsg;
}
