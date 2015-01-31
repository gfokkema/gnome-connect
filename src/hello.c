#include <gcrypt.h>

#include "notify.h"

/*
void generate_key () {
	gcrypt_init ();

    /* Generate a new RSA key pair. *
    printf("RSA key generation can take a few minutes. Your computer \n"
           "needs to gather random entropy. Please wait... \n\n");

    gcry_error_t err = 0;
    gcry_sexp_t rsa_parms;
    gcry_sexp_t rsa_keypair;

    err = gcry_sexp_build(&rsa_parms, NULL, "(genkey (rsa (nbits 4:2048)))");
    if (err) {
        xerr("gcrypt: failed to create rsa params");
    }

    err = gcry_pk_genkey(&rsa_keypair, rsa_parms);
    if (err) {
        xerr("gcrypt: failed to create rsa key pair");
    }
}
*/

void main () {
	Notify* android_notify = new_notify();
	notify();
	destroy_notify();
}
