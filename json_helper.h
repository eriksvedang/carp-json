json_token* Json_parse(String *s, int *num) {
    size_t len = strlen(*s);
    size_t read = 0;
    *num = json_num(*s, len);
    struct json_token *toks = calloc(*num, sizeof(struct json_token));
    json_load(toks, *num, &read, *s, len);
    return toks;
}

String Json_string(json_token *toks) {

}
