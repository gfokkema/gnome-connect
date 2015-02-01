#ifndef GCONN_MESSAGE_H_
#define GCONN_MESSAGE_H_

#include "msg-payload.h"

typedef struct _GconnMessage        GconnMessage;
typedef struct _GconnMessageClass   GconnMessageClass;

#define GCONN_TYPE_MESSAGE                  (gconn_message_get_type ())
#define GCONN_MESSAGE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_MESSAGE, GconnMessage))
#define GCONN_MESSAGE_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_MESSAGE, GconnMessageClass))
#define GCONN_MESSAGE_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_MESSAGE, GconnMessageClass))
#define GCONN_IS_MESSAGE(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_MESSAGE))
#define GCONN_IS_MESSAGE_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_MESSAGE))

#define GCONN_MESSAGE_STRING_IDENTITY "kdeconnect.identity"
#define GCONN_MESSAGE_STRING_PAIR     "kdeconnect.pair"

struct _GconnMessage
{
    GObject parent;

    const gchar *type;
    guint64 id;
    GconnMsgPayload *payload;
};

struct _GconnMessageClass
{
    GObjectClass parent;
};

GType         gconn_message_get_type (void);
GconnMessage* gconn_message_new      (void);

#endif // GCONN_MESSAGE_H_
