#include <gcrypt.h>

#define SAFE(call)                                              \
{                                                               \
    int err = call;                                             \
    if (err)                                                    \
    {                                                           \
        fprintf(stderr, "Error in file '%s' in line %i: %d.\n", \
                __FILE__, __LINE__, err);                       \
                exit(EXIT_FAILURE);                             \
    }                                                           \
}


void
progress (void *cb_data, const char *message,
          int printchar, int current, int total)
{
    printf ("Progress: %d %d\nWhat: %s\n", current, total, message);
}

void
sexpressioninfo (const gcry_sexp_t *key)
{
    int size = gcry_sexp_sprint(*key, GCRYSEXP_FMT_ADVANCED, NULL, 0);

    char* buffer = malloc(size);
    gcry_sexp_sprint (*key, GCRYSEXP_FMT_ADVANCED, buffer, size);

    printf("%s\n", buffer);
}

void
generate (gcry_sexp_t *private_key, gcry_sexp_t *public_key) {
    gcry_sexp_t keyparm, key;

    SAFE( gcry_sexp_new (&keyparm,
                         "(genkey\n"
                         "  (rsa\n"
                         "    (transient-key)\n"
                         "    (nbits 4:1024)\n"
                         "  )\n"
                         ")", 0, 1) );
    SAFE( gcry_pk_genkey (&key, keyparm) );
    gcry_sexp_release (keyparm);

    *public_key  = gcry_sexp_nth(key, 1);
    *private_key = gcry_sexp_nth(key, 2);
}

void
decrypt (gcry_sexp_t *plain,
         const gcry_sexp_t *key, gcry_sexp_t *cipher)
{
    SAFE( gcry_pk_decrypt(plain, *cipher, *key) );
}

void
encrypt (gcry_sexp_t *cipher,
         const gcry_sexp_t *key, const char* str)
{
    gcry_mpi_t msg;
    gcry_sexp_t data;

    SAFE( gcry_mpi_scan(&msg, GCRYMPI_FMT_USG, str, strlen(str), NULL) );
    SAFE( gcry_sexp_build(&data, NULL, "(data (flags raw) (value %m))", msg) );
    SAFE( gcry_pk_encrypt(cipher, data, *key) );
}

int main()
{
    if (!gcry_check_version (GCRYPT_VERSION))
    {
        fputs ("libgcrypt version mismatch\n", stderr);
        return 2;
    }
    SAFE( gcry_control (GCRYCTL_DISABLE_SECMEM, 0) );
    SAFE( gcry_control (GCRYCTL_INITIALIZATION_FINISHED, 0) );
    gcry_set_progress_handler (&progress, NULL);

    gcry_sexp_t private, public;
    generate(&private, &public);

    sexpressioninfo(&public);
    sexpressioninfo(&private);

    gcry_sexp_t cipher;
    encrypt(&cipher, &public, "test");
    sexpressioninfo(&cipher);

    gcry_sexp_t plain;
    decrypt(&plain, &private, &cipher);
    sexpressioninfo(&plain);
}
