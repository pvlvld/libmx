#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *p_start = dst;
    while (len-- > 0 && *src) *dst++ = *src++;
    return p_start;
}
