#ifndef CSTRING_H
#define CSTRING_H

#include <string.h>
#include <stdlib.h>

#define STRING_INLINE_LEN 16

typedef struct string string;

struct string {
    size_t len;
    union {
        void * ref;
        char raw[STRING_INLINE_LEN];
    } data;
};

extern string * string_new(const char * s);
extern string * string_new_blank();
extern string * string_new_s(const char * s, size_t len);
extern void string_init(string * str, const char * s);
extern void string_init_s(string * str, const char * s, size_t len);
extern void string_free(string * str);
extern char * string_get_raw(string * str);
extern void string_append(string * str, const char * s);
extern void string_append_s(string * str, const char * s, size_t len);

static inline size_t string_len(const string * str) {
    return str->len;
}

#endif /* end of include guard: CSTRING_H */
