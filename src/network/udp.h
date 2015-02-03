#ifndef GCONN_UDP_H_
#define GCONN_UDP_H_

#include <glib-object.h>
#include <gio/gio.h>

typedef struct _GconnUdp        GconnUdp;
typedef struct _GconnUdpClass   GconnUdpClass;

#define GCONN_TYPE_UDP                  (gconn_udp_get_type ())
#define GCONN_UDP(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCONN_TYPE_UDP, GconnUdp))
#define GCONN_UDP_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GCONN_TYPE_UDP, GconnUdpClass))
#define GCONN_UDP_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj),  GCONN_TYPE_UDP, GconnUdpClass))
#define GCONN_IS_UDP(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCONN_TYPE_UDP))
#define GCONN_IS_UDP_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass),  GCONN_TYPE_UDP))

struct _GconnUdp
{
    GObject parent;

    GSocket *socket;
};

struct _GconnUdpClass
{
    GObjectClass parent;
};

GType       gconn_udp_get_type (void);

#endif // GCONN_UDP_H_
