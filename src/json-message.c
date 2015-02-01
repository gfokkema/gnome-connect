#include "gnome-connect.h"

char*
json_message_create_identity ()
{
    JsonBuilder *builder;
    JsonNode *root;
    JsonGenerator *generator;

    builder = json_builder_new ();
    json_builder_begin_object (builder);
    json_builder_set_member_name  (builder, "type");
    json_builder_add_string_value (builder, GCONN_MESSAGE_STRING_IDENTITY);
    json_builder_set_member_name  (builder, "id");
    json_builder_add_int_value    (builder, g_get_real_time ());
    json_builder_set_member_name  (builder, "body");
        json_builder_begin_object     (builder);
        json_builder_set_member_name  (builder, "protocolVersion");
        json_builder_add_int_value    (builder, 5);
        json_builder_set_member_name  (builder, "deviceName");
        json_builder_add_string_value (builder, "arch-laptop");
        json_builder_set_member_name  (builder, "deviceType");
        json_builder_add_string_value (builder, "desktop");
        json_builder_set_member_name  (builder, "deviceId");
        json_builder_add_string_value (builder, "debug");
        json_builder_end_object       (builder);
    json_builder_end_object       (builder);

    generator = json_generator_new ();
    root = json_builder_get_root (builder);
    json_generator_set_root (generator, root);

    gsize size;
    char* json = json_generator_to_data (generator, &size);
    g_strlcat (json, "\n", size + 2);

    json_node_free (root);
    g_object_unref (generator);
    g_object_unref (builder);

    return json;
}
