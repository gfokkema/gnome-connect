#ifndef GCONN_MSG_PAYLOAD_H_
#define GCONN_MSG_PAYLOAD_H_

#include <glib-object.h>
#include <json-glib/json-glib.h>

typedef struct _GconnMsgPayload        GconnMsgPayload;
typedef struct _GconnMsgPayloadClass   GconnMsgPayloadClass;

#define GCONN_TYPE_MSG_PAYLOAD                  (gconn_msg_payload_get_type ())
#define GCONN_MSG_PAYLOAD(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_MSG_PAYLOAD, GconnMsgPayload))
#define GCONN_MSG_PAYLOAD_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_MSG_PAYLOAD, GconnMsgPayloadClass))
#define GCONN_MSG_PAYLOAD_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_MSG_PAYLOAD, GconnMsgPayloadClass))
#define GCONN_IS_MSG_PAYLOAD(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_MSG_PAYLOAD))
#define GCONN_IS_MSG_PAYLOAD_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_MSG_PAYLOAD))

struct _GconnMsgPayload
{
    GObject parent;
};

struct _GconnMsgPayloadClass
{
    GObjectClass parent;
};

GType            gconn_msg_payload_get_type (void);
GconnMsgPayload* gconn_msg_payload_new      (void);

#endif // GCONN_MSG_PAYLOAD_H_
