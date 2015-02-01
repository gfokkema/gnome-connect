#include "message.h"

G_DEFINE_TYPE (GconnMessage, gconn_message, G_TYPE_OBJECT)

static void
gconn_message_class_init (GconnMessageClass *klass)
{
}

static void
gconn_message_init (GconnMessage *self)
{
}

GconnMessage*
gconn_message_new (void)
{
    return g_object_new (GCONN_TYPE_MESSAGE, 0);
}
