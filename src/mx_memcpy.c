#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    if (!src) return dst;
    char *p_d = dst;
    const char *p_s = src;
    for (size_t i = 0; i < n; i++) *p_d++ = *p_s++;
    return dst;
}
