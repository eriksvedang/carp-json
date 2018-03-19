#include <core.h>
#include <carp_string.h>
#include "json.h"

typedef struct {
    struct json_token *toks;
    size_t num;
} JsonParsed;

JsonParsed Json_parse(String *s) {
    size_t len = strlen(*s);
    int read = 0;
    JsonParsed parsed;
    parsed.num = json_num(*s, len);
    parsed.toks = calloc(parsed.num, sizeof(struct json_token));
    json_load(parsed.toks, parsed.num, &read, *s, len);
    return parsed;
}

String Json_string(JsonParsed parsed, String *path) {
    int size;
    const int max_size = 1024;
    char *buffer = malloc(max_size);
    json_query_string(buffer, max_size, &size, parsed.toks, parsed.num, *path);
    return buffer;
}

double Json_double(JsonParsed parsed, String *path) {
    json_number num;
    json_query_number(&num, parsed.toks, parsed.num, *path);
    return num;
}

int Json_int(JsonParsed parsed, String *path) {
    json_number num;
    json_query_number(&num, parsed.toks, parsed.num, *path);
    return num;
}

struct json_token *Json_query(JsonParsed parsed, String *path) {
    return json_query(parsed.toks, parsed.num, *path);
}

int Json_type(JsonParsed parsed, String *path) {
    return json_query_type(parsed.toks, parsed.num, *path);
}
