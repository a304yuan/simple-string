#include "cstring.h"

string * string_new(const char * s) {
    string * str = malloc(sizeof(string));
    size_t len = strlen(s);
    void * dest = NULL;
    if (len >= STRING_INLINE_LEN) {
        str->data.ref = (dest = malloc(len + 1));
        str->cap = len;
    }
    else {
        dest = str->data.raw;
        str->cap = STRING_INLINE_LEN - 1;
    }
    memcpy(dest, s, len);
    *(char*)(dest+len) = '\0';
    str->len = len;
    return str;
}

string * string_new_blank() {
    string * str = malloc(sizeof(string));
    str->data.raw[0] = '\0';
    str->len = 0;
    str->cap = STRING_INLINE_LEN - 1;
    return str;
}

string * string_new_s(const char * s, size_t len) {
    string * str = malloc(sizeof(string));
    void * dest = NULL;
    if (len >= STRING_INLINE_LEN) {
        str->data.ref = (dest = malloc(len + 1));
        str->cap = len;
    }
    else {
        dest = str->data.raw;
        str->cap = STRING_INLINE_LEN - 1;
    }
    memcpy(dest, s, len);
    *(char*)(dest+len) = '\0';
    str->len = len;
    return str;
}
/*
void string_init(string * str, const char * s) {
    size_t len = strlen(s);
    void * dest = NULL;
    if (len >= STRING_INLINE_LEN) {
        str->data.ref = (dest = malloc(len));
    }
    else {
        dest = str->data.raw;
    }
    memcpy(dest, s, len);
    *(char*)(dest+len) = '\0';
    str->len = len;
}

void string_init_s(string * str, const char * s, size_t len) {
    void * dest = NULL;
    if (len >= STRING_INLINE_LEN) {
        str->data.ref = (dest = malloc(len));
    }
    else {
        dest = str->data.raw;
    }
    memcpy(dest, s, len);
    *(char*)(dest+len) = '\0';
    str->len = len;
}
*/
void string_free(string * str) {
    if (str->len >= STRING_INLINE_LEN) {
        free(str->data.ref);
    }
    free(str);
}

char * string_get_raw(string * str) {
    if (str->len >= STRING_INLINE_LEN) {
        return str->data.ref;
    }
    else {
        return str->data.raw;
    }
}

void string_append(string * str, const char * s) {
    size_t new_len = strlen(s) + str->len;
    if (new_len < STRING_INLINE_LEN) {
        strcpy(str->data.raw + str->len, s);
        str->data.raw[new_len] = '\0';
    }
    else {
        if (str->len >= STRING_INLINE_LEN) {
            void * ref = str->len > str->cap ? realloc(str->data.ref, new_len * 2 + 1) : str->data.ref;
            strcpy(ref + str->len, s);
            *(char*)(ref + new_len) = '\0';
            str->data.ref = ref;
        }
        else {
            void * ref = malloc(new_len * 2 + 1);
            memcpy(ref, str->data.raw, str->len);
            strcpy(ref + str->len, s);
            *(char*)(ref + new_len) = '\0';
            str->data.ref = ref;
        }
        str->cap = new_len * 2;
    }
    str->len = new_len;
}

void string_append_s(string * str, const char * s, size_t len) {
    size_t new_len = len + str->len;
    if (new_len < STRING_INLINE_LEN) {
        strncpy(str->data.raw + str->len, s, len);
        str->data.raw[new_len] = '\0';
    }
    else {
        if (str->len >= STRING_INLINE_LEN) {
            void * ref = str->len > str->cap ? realloc(str->data.ref, new_len * 2 + 1) : str->data.ref;
            strncpy(ref + str->len, s, len);
            *(char*)(ref + new_len) = '\0';
            str->data.ref = ref;
        }
        else {
            void * ref = malloc(new_len * 2 + 1);
            memcpy(ref, str->data.raw, str->len);
            strncpy(ref + str->len, s, len);
            *(char*)(ref + new_len) = '\0';
            str->data.ref = ref;
        }
        str->cap = new_len * 2;
    }
    str->len = new_len;
}
