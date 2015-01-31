#ifndef DEVICE_H_
#define DEVICE_H_

#include <gcrypt.h>

typedef enum PairStatus
{
    PAIRED,
    NOT_PAIRED,
    PENDING_CLIENT,
    PENDING_HOST
} PairStatus;

typedef struct Device
{
    char* deviceID;
    char* name;
    PairStatus paired;
    gcry_sexp_t public_key;
} Device;

#endif // DEVICE_H_
