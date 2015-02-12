#ifndef GCONN_MESSAGE_H_
#define GCONN_MESSAGE_H_

#include <glib-2.0/glib.h>
#include <json-glib/json-glib.h>

#define GCONN_MESSAGE_STRING_IDENTITY "kdeconnect.identity"
#define GCONN_MESSAGE_STRING_PAIR     "kdeconnect.pair"

namespace Gconn {

class MsgPayload {
public:
    virtual JsonNode* json() = 0;
};

class Message {
public:
    Message  () {};
    ~Message () {};

    char* json() {
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
        json_builder_add_value        (builder, payload->json());
        json_builder_end_object       (builder);

        generator = json_generator_new ();
        root = json_builder_get_root (builder);
        json_generator_set_root (generator, root);

        gsize size;
        char* json = json_generator_to_data (generator, &size);
        std::cout << json << std::endl;
        g_strlcat (json, "\n", size + 2);

        json_node_free (root);
        g_object_unref (generator);
        g_object_unref (builder);

        return json;
    }

    const gchar* type;
    guint64 id;
    MsgPayload* payload;
};

}

#endif // GCONN_MESSAGE_H_
