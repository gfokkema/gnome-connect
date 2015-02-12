#include "notify.h"

#include <libnotify/notify.h>
#include <stdlib.h>

Notify* new_notify()
{
    notify_init ("Hello world!");

    Notify* notify = (Notify*)malloc(sizeof(Notify));
    if (!notify)
    {
        exit(EXIT_FAILURE);
    }

    return notify;
}


void notify() {
    NotifyNotification * hello = notify_notification_new ("Hello world", "This is an example notification.", "dialog-information");
    notify_notification_show (hello, NULL);
    g_object_unref(G_OBJECT(hello));
}

void destroy_notify()
{
    notify_uninit();
}
