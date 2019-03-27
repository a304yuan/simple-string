#ifndef CSTRING_H
#define CSTRING_H

#include <string.h>
#include <stdlib.h>

typedef struct string string;

struct string {
    size_t len;
    char raw[];
};

extern string * string_new(const char * s);
extern string * string_new_s(const char * s, size_t len);
static inline void string_free(string * str) {
    free(str);
}
static inline char * string_get_raw(string * str) {
    return str->raw;
}
extern string * string_append(const string * str, const char * s);
extern string * string_append_s(const string * str, const char * s, size_t len);
extern string * string_concat(const string * str1, const string * str2);
static inline size_t string_len(const string * str) {
    return str->len;
}

#endif /* end of include guard: CSTRING_H */
