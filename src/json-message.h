#ifndef JSON_MESSAGE_H_
#define JSON_MESSAGE_H_

typedef struct JsonMessage
{
    long    id;
    char*   type;
} JsonMessage;

JsonMessage*    json_message_new (char *msg);

#endif
