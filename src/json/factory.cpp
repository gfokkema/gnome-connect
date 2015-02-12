#include "../gnome-connect.h"

Gconn::MsgFactory::MsgFactory() {}
Gconn::MsgFactory::~MsgFactory() {}

Gconn::Message*
Gconn::MsgFactory::message(gchar *text)
{
    JsonParser *parser;
    JsonNode *root, *body;
    JsonObject *rootobject;
    Gconn::Message *msg;

    parser = json_parser_new();
    SAFE( json_parser_load_from_data (parser, text, strlen(text), &error) );
    root = json_parser_get_root (parser);
    rootobject = json_node_get_object (root);
    body = json_object_get_member (rootobject, "body");

    const gchar *type = json_object_get_string_member (rootobject, "type");
    msg = new Gconn::Message;
    msg->id = json_object_get_int_member (rootobject, "id");
    msg->type = g_strndup(type, strlen(type));

    std::cout << type << std::endl;
    if (strncmp (GCONN_MESSAGE_STRING_IDENTITY, type, strlen(type)) == 0)
    {
        msg->payload = new MsgIdentity(body);
        std::cout << ((MsgIdentity*)msg->payload)->devicename << std::endl;
    }
    else if (strncmp (GCONN_MESSAGE_STRING_PAIR, type, strlen(type)) == 0)
    {
        msg->payload = new MsgPair(body);
        std::cout << ((MsgPair*)msg->payload)->publickey << std::endl;
    }

    g_object_unref (parser);
    return msg;
}
