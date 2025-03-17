#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <stdbool.h>

typedef struct {
    bool show_help;
    bool has_errors;
    char *error_msg;
} ParseResult;

ParseResult parse_arguments(int argc, char *argv[]);
void print_help();

#endif