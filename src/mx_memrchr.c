#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const size_t *p_s = (size_t *)s + n;
    const size_t delim = (size_t)c;

    while (n--) {
        p_s--;
        if (*p_s == delim) return (void *)p_s;
    }

    return NULL;
}
