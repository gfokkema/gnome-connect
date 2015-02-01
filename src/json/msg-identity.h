#ifndef GCONN_MSG_IDENTITY_H_
#define GCONN_MSG_IDENTITY_H_

#include "msg-payload.h"

typedef struct _GconnMsgIdentity        GconnMsgIdentity;
typedef struct _GconnMsgIdentityClass   GconnMsgIdentityClass;

#define GCONN_TYPE_MSG_IDENTITY                  (gconn_msg_identity_get_type ())
#define GCONN_MSG_IDENTITY(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_MSG_IDENTITY, GconnMsgIdentity))
#define GCONN_MSG_IDENTITY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_MSG_IDENTITY, GconnMsgIdentityClass))
#define GCONN_MSG_IDENTITY_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_MSG_IDENTITY, GconnMsgIdentityClass))
#define GCONN_IS_MSG_IDENTITY(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_MSG_IDENTITY))
#define GCONN_IS_MSG_IDENTITY_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_MSG_IDENTITY))

struct _GconnMsgIdentity
{
    GconnMsgPayload parent;

    int protocol;
    int tcpport;
    char* devicename;
    char* devicetype;
    char* deviceID;
};

struct _GconnMsgIdentityClass
{
    GconnMsgPayloadClass parent;
};

GType             gconn_msg_identity_get_type (void);
GconnMsgIdentity* gconn_msg_identity_new      (JsonNode *data);

#endif // GCONN_MSG_IDENTITY_H_
