#include "../gnome-connect.h"

Gconn::MsgFactory::MsgFactory() {}
Gconn::MsgFactory::~MsgFactory() {}

Gconn::Message*
Gconn::MsgFactory::message(gchar *text)
{
    JsonParser *parser;
    JsonNode *root;
    Gconn::Message *msg;

    parser = json_parser_new();
    SAFE( json_parser_load_from_data (parser, text, strlen(text), &error) );
    root = json_parser_get_root (parser);
    msg = new Gconn::Message(root);

    g_object_unref (parser);
    return msg;
}
