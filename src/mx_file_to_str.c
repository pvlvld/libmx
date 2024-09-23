#include "../inc/libmx.h"
// Sheeeeeesh

static inline char *read_error(char *content) {
    mx_strdel(&content);
    return NULL;
}

static inline char *realloc_content(char *content, int total_size, char *buffer, signed long bytes_read) {
    char *temp = mx_realloc(content, total_size + bytes_read);
    if (temp == NULL) return read_error(content);

    mx_strncpy(temp + total_size, buffer, bytes_read);

    return temp;
}

static inline int read_file(int fd, char **content) {
    char buffer[BUFFER_SIZE_READ_FILE];
    int total_size = 0;
    signed long bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE_READ_FILE)) > 0) {
        *content = realloc_content(*content, total_size, buffer, bytes_read);
        if (*content == NULL) return -1;
        total_size += bytes_read;
    }

    return bytes_read == -1 ? -1 : total_size;
}

char *mx_file_to_str(const char *file) {
    if (file == NULL) return NULL;
    int fd = open(file, O_CLOEXEC | O_RDONLY);
    if (fd == -1) return NULL;

    char *content = NULL;
    int bytes_read = read_file(fd, &content);
    if (bytes_read == -1) return read_error(content);
    if (bytes_read == 0) return mx_strnew(0);

    return content;
}
