#ifndef GCONN_MSG_PAIR_H_
#define GCONN_MSG_PAIR_H_

#include "msg-payload.h"

typedef struct _GconnMsgPair        GconnMsgPair;
typedef struct _GconnMsgPairClass   GconnMsgPairClass;

#define GCONN_TYPE_MSG_PAIR                  (gconn_msg_pair_get_type ())
#define GCONN_MSG_PAIR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_MSG_PAIR, GconnMsgPair))
#define GCONN_MSG_PAIR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_MSG_PAIR, GconnMsgPairClass))
#define GCONN_MSG_PAIR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_MSG_PAIR, GconnMsgPairClass))
#define GCONN_IS_MSG_PAIR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_MSG_PAIR))
#define GCONN_IS_MSG_PAIR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_MSG_PAIR))

struct _GconnMsgPair
{
    GconnMsgPayload parent;

    gchar *publickey;
    gboolean pair;
};

struct _GconnMsgPairClass
{
    GconnMsgPayloadClass parent;
};

GType         gconn_msg_pair_get_type (void);
GconnMsgPair* gconn_msg_pair_new      (JsonNode *data);


#endif // GCONN_MSG_PAIR_H_
