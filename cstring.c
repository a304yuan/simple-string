#include "cstring.h"

string * string_new(const char * s) {
    size_t len = strlen(s);
    string * str = malloc(sizeof(string) + len + 1);
    strcpy(str->raw, s);
    str->raw[len] = '\0';
    str->len = len;
    return str;
}

string * string_new_s(const char * s, size_t len) {
    string * str = malloc(sizeof(string) + len + 1);
    strncpy(str->raw, s, len);
    str->raw[len] = '\0';
    str->len = len;
    return str;
}

void string_append(string ** str, const char * s) {
    size_t len = strlen(s) + (*str)->len;
    string * newstr = malloc(sizeof(string) + len + 1);
    strcpy(newstr->raw, (*str)->raw);
    strcpy(newstr->raw + (*str)->len, s);
    newstr->raw[len] = '\0';
    newstr->len = len;
    free(*str);
    *str = newstr;
}

void string_append_s(string ** str, const char * s, size_t len) {
    size_t nlen = strlen(s) + (*str)->len;
    string * newstr = malloc(sizeof(string) + nlen + 1);
    strcpy(newstr->raw, (*str)->raw);
    strncpy(newstr->raw + (*str)->len, s, len);
    newstr->raw[nlen] = '\0';
    newstr->len = nlen;
    free(*str);
    *str = newstr;
}

void string_concat(string ** str1, const string * str2) {
    return string_append(str1, str2->raw);
}
