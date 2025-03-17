#include "preprocess.h"
#include <string.h>
#include <ctype.h>

bool is_whitespace_line(const char *line) {
    while (*line) {
        if (!isspace((unsigned char)*line)) return false;
        line++;
    }
    return true;
}

void trim_trailing_spaces(char *line) {
    char *end = line + strlen(line) - 1;
    while (end >= line && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

void remove_comments(char *line) {
    char *p = strchr(line, '#');
    if (p) *p = '\0';
}

void process_line(char *line) {
    remove_comments(line);
    trim_trailing_spaces(line);
}