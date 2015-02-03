#ifndef GCONN_NETWORK_H_
#define GCONN_NETWORK_H_

#include <glib-object.h>
#include <gio/gio.h>

typedef struct _GconnNetwork          GconnNetwork;
typedef struct _GconnNetworkInterface GconnNetworkInterface;

#define GCONN_TYPE_NETWORK                  (gconn_network_get_type ())
#define GCONN_NETWORK(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj),   GCONN_TYPE_NETWORK, GconnNetwork))
#define GCONN_IS_NETWORK(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj),   GCONN_TYPE_NETWORK))
#define GCONN_NETWORK_GET_INTERFACE(obj)    (G_TYPE_INSTANCE_GET_INTERFACE((obj), GCONN_TYPE_NETWORK, GconnNetworkInterface))

struct _GconnNetworkInterface
{
    GTypeInterface parent;

    void (*bind)   (GconnNetwork *self, gint port);
    void (*listen) (GconnNetwork *self);
};

GType         gconn_network_get_type (void);
void          gconn_network_bind     (GconnNetwork *self, gint port);
void          gconn_network_listen   (GconnNetwork *self);

#endif // GCONN_NETWORK_H_
