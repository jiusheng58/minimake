#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

FILE* open_makefile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("无法打开makefile");
        exit(EXIT_FAILURE);
    }
    return file;
}

void close_file(FILE *file) {
    if (file) fclose(file);
}