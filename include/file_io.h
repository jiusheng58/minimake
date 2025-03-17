#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

FILE* open_makefile(const char *filename);
void close_file(FILE *file);

#endif