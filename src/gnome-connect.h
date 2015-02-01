#ifndef GNOME_CONNECT_H_
#define GNOME_CONNECT_H_

#define SAFE( call)                                             \
{                                                               \
    GError *error = NULL;                                       \
    call;                                                       \
    if (error != NULL)                                          \
        g_error (error->message);                               \
}


#include <stdlib.h>
#include <string.h>

#include "json-message.h"
#include "network-listener.h"
#include "json/factory.h"
#include "json/msg-identity.h"
#include "json/msg-pair.h"
#include "json/msg-payload.h"

#endif // GNOME_CONNECT_H_
