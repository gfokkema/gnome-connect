#include "../gnome-connect.h"

Gconn::Message::Message(JsonNode *root)
{
    JsonObject* data  = json_node_get_object          (root);
    this->id          = json_object_get_int_member    (data, "id");
    const char *type  = json_object_get_string_member (data, "type");
    JsonNode* body    = json_object_get_member        (data, "body");
    this->type        = g_strndup(type, strlen(type));

    std::cout << type << std::endl;
    if (strncmp (GCONN_MESSAGE_STRING_IDENTITY, type, strlen(type)) == 0)
    {
        this->payload = new MsgIdentity(body);
        std::cout << ((MsgIdentity*)this->payload)->devicename << std::endl;
    }
    else if (strncmp (GCONN_MESSAGE_STRING_PAIR, type, strlen(type)) == 0)
    {
        this->payload = new MsgPair(body);
        std::cout << ((MsgPair*)this->payload)->publickey << std::endl;
    }
}

Gconn::Message::Message(int id, char* type, MsgPayload* payload)
: id(id), type(type), payload(payload)
{
}

Gconn::Message::~Message()
{
    g_free (this->type);
    delete (payload);
}

char*
Gconn::Message::json() {
    JsonBuilder   *builder;
    JsonGenerator *generator;
    JsonNode      *root;

    builder = json_builder_new    ();
    json_builder_begin_object     (builder);
    json_builder_set_member_name  (builder, "type");
    json_builder_add_string_value (builder, type);
    json_builder_set_member_name  (builder, "id");
    json_builder_add_int_value    (builder, g_get_real_time ());
    json_builder_set_member_name  (builder, "body");
    json_builder_add_value        (builder, payload->json());
    json_builder_end_object       (builder);

    root = json_builder_get_root   (builder);
    generator = json_generator_new ();
    json_generator_set_root (generator, root);

    gsize size;
    char* json = json_generator_to_data (generator, &size);
    g_strlcat (json, "\n", size + 2);

    json_node_free (root);
    g_object_unref (generator);
    g_object_unref (builder);

    return json;
}
