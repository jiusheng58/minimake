#include "file_io.h"
#include "preprocess.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    bool verbose = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        }
    }

    FILE *file = open_makefile("makefile");
    char buffer[MAX_LINE];
    
    if (verbose) {
        FILE *out = fopen("Minimake_cleared.mk", "w");
        if (!out) {
            perror("无法创建输出文件");
            exit(EXIT_FAILURE);
        }

        while (fgets(buffer, MAX_LINE, file)) {
            process_line(buffer);
            if (!is_whitespace_line(buffer)) {
                fprintf(out, "%s\n", buffer);
            }
        }
        
        fclose(out);
    } else {
        while (fgets(buffer, MAX_LINE, file)) {
            process_line(buffer);
            if (!is_whitespace_line(buffer)) {
                printf("%s\n", buffer);
            }
        }
    }
    
    close_file(file);
    return 0;
}