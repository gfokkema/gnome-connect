#include "../gnome-connect.h"

Gconn::MsgPair::MsgPair(JsonNode *data)
{
    JsonObject *object = json_node_get_object (data);
    const char *publickey = json_object_get_string_member (object, "publickey");

    this->publickey = g_strndup(publickey, strlen(publickey));
    this->pair      = json_object_get_boolean_member (object, "pair");
}

Gconn::MsgPair::MsgPair(char* publickey, bool pair)
: publickey(publickey), pair(pair)
{
}

Gconn::MsgPair::~MsgPair()
{
    g_free (this->publickey);
}

JsonNode*
Gconn::MsgPair::json()
{
    JsonBuilder *builder;
    JsonNode *root;

    builder = json_builder_new ();
    json_builder_begin_object     (builder);
    json_builder_set_member_name  (builder, "publickey");
    json_builder_add_string_value (builder, publickey);
    json_builder_set_member_name  (builder, "pair");
    json_builder_add_boolean_value(builder, pair);
    json_builder_end_object       (builder);
    root = json_builder_get_root  (builder);

    g_object_unref (builder);
    return root;
}
