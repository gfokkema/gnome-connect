#include "notify.h"

int main () {
    Notify* android_notify = new_notify();
    notify();
    destroy_notify();
}
