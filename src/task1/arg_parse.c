#include "arg_parse.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ParseResult parse_arguments(int argc, char *argv[]) {
    ParseResult result = {false, false, NULL};
    
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--help") == 0) {
            result.show_help = true;
        } else {
            result.has_errors = true;
            const char *fmt = "错误参数: %s\n";
            result.error_msg = malloc(snprintf(NULL, 0, fmt, argv[i]) + 1);
            sprintf(result.error_msg, fmt, argv[i]);
        }
    }
    return result;
}

void print_help() {
    printf("用法: minimake [选项]\n");
    printf("选项:\n");
    printf("  --help\t显示帮助信息\n");
    printf("  -v, --verbose\t详细模式输出\n");
}