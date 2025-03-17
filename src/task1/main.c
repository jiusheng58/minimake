#include "arg_parse.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    ParseResult result = parse_arguments(argc, argv);
    
    if (result.show_help) {
        print_help();
        return 0;
    }
    
    if (result.has_errors) {
        fprintf(stderr, "%s", result.error_msg);
        free(result.error_msg);
        return 1;
    }
    
    printf("参数解析成功!\n");
    return 0;
}