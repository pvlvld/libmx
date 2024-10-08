#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *p_b = b;
    while (len-- > 0) *p_b++ = c;
    return b;
}
