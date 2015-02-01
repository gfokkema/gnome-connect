#ifndef GCONN_MSG_FACTORY_H_
#define GCONN_MSG_FACTORY_H_

#include "message.h"

typedef struct _GconnMsgFactory        GconnMsgFactory;
typedef struct _GconnMsgFactoryClass   GconnMsgFactoryClass;

#define GCONN_TYPE_MSG_FACTORY                  (gconn_msg_factory_get_type ())
#define GCONN_MSG_FACTORY(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_MSG_FACTORY, GconnMsgFactory))
#define GCONN_MSG_FACTORY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_MSG_FACTORY, GconnMsgFactoryClass))
#define GCONN_MSG_FACTORY_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_MSG_FACTORY, GconnMsgFactoryClass))
#define GCONN_IS_MSG_FACTORY(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_MSG_FACTORY))
#define GCONN_IS_MSG_FACTORY_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_MSG_FACTORY))

struct _GconnMsgFactory
{
    GObject parent;
};

struct _GconnMsgFactoryClass
{
    GObjectClass parent;
};

GType             gconn_msg_factory_get_type (void);
GconnMsgFactory*  gconn_msg_factory_new      (void);
GconnMessage*     gconn_msg_factory_message  (GconnMsgFactory *self, gchar *msg);

#endif // GCONN_MSG_FACTORY_H_
