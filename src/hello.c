#include "notify.h"

void main () {
    Notify* android_notify = new_notify();
    notify();
    destroy_notify();
}
