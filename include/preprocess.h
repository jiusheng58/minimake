#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <stdbool.h>

void process_line(char *line);
bool is_whitespace_line(const char *line);
void trim_trailing_spaces(char *line);
void remove_comments(char *line);

#endif