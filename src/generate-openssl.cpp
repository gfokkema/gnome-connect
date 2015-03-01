#include <cstdio>
#include <cstring>
#include <iostream>

#include <openssl/pem.h>
#include <openssl/x509.h>

const char * pubkey =
"-----BEGIN PUBLIC KEY-----\n"
"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAu0YYysfLJUBk/V3CcDS+RtDEvUjJ657D\n"
"4Q/GUBUC8PIsoHiusj5o3O8mPa2PjVKW25NETfretTcNV7T3hVVhWcPCcvn2uGQ0RhsON4hYCaKo\n"
"ocHGzpfB/03a+Mn1eeDIyZFlb4vWQC+IQOtGR0HVG/uvVJJF9ySM1oX7Cne+wBl+zSEUcqR7hAQC\n"
"bECOmbXswSsn7K70aj5kvGbj7nOtC5HO+RvUKbJeblfIFslqhkqzMfxCHsdnMvDdBbu2Vp2kX3R4\n"
"M/P7Y0G4mlbEMTd7x8iYd/dg3YGy2neDRjAoR03y6xjZEPLwFwERYgqmz9ihEU9+NcxN6+0k2B/J\n"
"ebM/aQIDAQAB\n"
"-----END PUBLIC KEY-----\n";

/* Generates a 2048-bit RSA key. */
EVP_PKEY *
generate_key()
{
    /* Allocate memory for the EVP_PKEY structure. */
    EVP_PKEY * pkey = EVP_PKEY_new();
    if(!pkey)
    {
        std::cerr << "Unable to create EVP_PKEY structure." << std::endl;
        return NULL;
    }

    /* Generate the RSA key and assign it to pkey. */
    RSA * rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (!EVP_PKEY_assign_RSA(pkey, rsa))
    {
        std::cerr << "Unable to generate 2048-bit RSA key." << std::endl;
        EVP_PKEY_free(pkey);
        return NULL;
    }

    return pkey;
}

EVP_PKEY *
import_key(const char * pubkey)
{
    BIO *bio;
    EVP_PKEY * pkey = EVP_PKEY_new ();

    bio = BIO_new( BIO_s_mem ());
    BIO_puts(bio, pubkey);
    if (!PEM_read_bio_PUBKEY(bio, &pkey, NULL, NULL))
    {
        std::cerr << "Unable to import RSA key." <<std::endl;
        EVP_PKEY_free (pkey);
        BIO_free (bio);
        return NULL;
    }

    BIO_free (bio);
    return pkey;
}

bool
print_key(EVP_PKEY * pkey)
{
    BIO * bio_out = BIO_new_fp (stdout, BIO_NOCLOSE);
    BIO * temp_bio = BIO_new ( BIO_s_mem() );

    PEM_write_bio_PrivateKey (bio_out, pkey, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_PUBKEY (bio_out, pkey);
}

char *
decrypt (EVP_PKEY * pkey, char * encryptmsg, size_t inlen)
{
    EVP_PKEY_CTX * ctx;
    ctx = EVP_PKEY_CTX_new (pkey, NULL);

    size_t outlen;
    EVP_PKEY_decrypt_init (ctx);
    EVP_PKEY_decrypt (ctx, NULL, &outlen, (unsigned char*)encryptmsg, inlen);
    char * msg = (char*)malloc (sizeof (char) * outlen);
    EVP_PKEY_decrypt (ctx, (unsigned char*)msg, &outlen, (unsigned char*)encryptmsg, inlen);

    return msg;
}

char *
encrypt (EVP_PKEY * pkey, size_t & len)
{
    EVP_PKEY_CTX *ctx;
    ctx = EVP_PKEY_CTX_new (pkey, NULL);

    char msg[2048/8];
    printf("Message to encrypt: ");
    fgets(msg, 2048/8, stdin);
    msg[strlen(msg)-1] = '\0';

    // Encrypt the message
    size_t inlen = strlen(msg) + 1;
    size_t outlen;
    EVP_PKEY_encrypt_init (ctx);
    EVP_PKEY_encrypt(ctx, NULL, &outlen, (unsigned char*)msg, inlen);
    char * encryptmsg = (char*)malloc (sizeof (char) * outlen);
    EVP_PKEY_encrypt(ctx, (unsigned char*)encryptmsg, &outlen, (unsigned char*)msg, inlen);

    len = outlen;
    return encryptmsg;
}

int main(int argc, char ** argv)
{
    size_t len;

    EVP_PKEY * pkey = generate_key();
    print_key (pkey);
    char * encmsg = encrypt (pkey, len);
    char * decmsg = decrypt (pkey, encmsg, len);
    printf("%d %s\n", len, decmsg);

    EVP_PKEY * importpkey = import_key (pubkey);
    print_key (importpkey);

    free (encmsg);
    free (decmsg);
    EVP_PKEY_free (pkey);
    EVP_PKEY_free (importpkey);
}
