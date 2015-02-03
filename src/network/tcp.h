#ifndef GCONN_TCP_H_
#define GCONN_TCP_H_

#include "network.h"

typedef struct _GconnTcp        GconnTcp;
typedef struct _GconnTcpClass   GconnTcpClass;

#define GCONN_TYPE_TCP                  (gconn_tcp_get_type ())
#define GCONN_TCP(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_TCP, GconnTcp))
#define GCONN_TCP_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_TCP, GconnTcpClass))
#define GCONN_TCP_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_TCP, GconnTcpClass))
#define GCONN_IS_TCP(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_TCP))
#define GCONN_IS_TCP_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_TCP))

struct _GconnTcp
{
    GObject parent;

    GSocket *socket;
};

struct _GconnTcpClass
{
    GObjectClass parent;
};

GType       gconn_tcp_get_type (void);
GconnTcp*   gconn_tcp_new      (void);

#endif // GCONN_TCP_H_
