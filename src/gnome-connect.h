#ifndef GNOME_CONNECT_H_
#define GNOME_CONNECT_H_

#define SAFE( call)                                             \
{                                                               \
    GError *error = NULL;                                       \
    call;                                                       \
    if (error != NULL)                                          \
        g_error (error->message);                               \
}

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <string>
#include <vector>

#include "device.h"
#include "json/factory.h"
#include "json/msg-identity.h"
#include "json/msg-pair.h"
#include "network/network.h"
#include "network/udp.h"
#include "network/tcp.h"

#endif // GNOME_CONNECT_H_
