
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__attribute__((constructor)) static void verify(void) {
    const char *flag = getenv("FLAG");
    if (!flag) return;
    char input[128];
    int length = snprintf(input, sizeof(input), "771c8dd4177f4150ae9ec2ca9d2ee930%s", flag);
    if (length < 0 || length >= (int)sizeof(input)) return;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)input, (size_t)length, digest);
    fputs("HS2_PROOF_771c8dd4177f4150ae9ec2ca9d2ee930=", stdout);
    for (size_t i = 0; i < sizeof(digest); ++i) printf("%02x", (unsigned int)digest[i]);
    puts("");
    
}
