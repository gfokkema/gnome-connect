#include <json-glib/json-glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "json-message.h"

JsonMessage*
json_message_new (char* msg)
{
    JsonParser* parser;
    JsonReader* reader;

    parser = json_parser_new();
    GError *err;
    if (!json_parser_load_from_data (parser, msg, strlen(msg), &err))
    {
        fprintf(stderr, "Error in file '%s' in line %i: %s.\n",
                __FILE__, __LINE__, err->message);
                exit(EXIT_FAILURE);
    }

    reader = json_reader_new (json_parser_get_root (parser));

    json_reader_read_member (reader, "type");
    const char *type = json_reader_get_string_value (reader);
    json_reader_end_member (reader);

    json_reader_read_member (reader, "id");
    const long id = json_reader_get_int_value(reader);
    json_reader_end_member (reader);

    JsonMessage* jsonmsg = malloc(sizeof(JsonMessage));
    jsonmsg->id = id;
    jsonmsg->type = malloc((strlen(type) + 1) * sizeof(char));
    strncpy(jsonmsg->type, type, strlen(type));

    g_object_unref(reader);
    g_object_unref(parser);

    return jsonmsg;
}
