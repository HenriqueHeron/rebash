#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include "tools/cat.h"
#include "tools/rm.h"
#include "tools/touch.h"

#define ARG_BEGIN_IDX 2

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Insufficient arguments.\nUsage: %s <command> [...args]\n", argv[0]);
        return 1;
    }
    
    char command[256];

    int cmd_idx = 0;
    while (argv[1][cmd_idx] != '\0') {
        command[cmd_idx] = tolower(argv[1][cmd_idx]);
        cmd_idx++;
    }

    command[cmd_idx] = '\0';

    // Run cat
    if (strcmp(command, "cat") == 0) {   
        for (int i = ARG_BEGIN_IDX; i < argc; i++) {
            cat(argv[i]);
        }
        return 0;
    }

    // Run rm
    if (strcmp(command, "rm") == 0) {
        for (int i = ARG_BEGIN_IDX; i < argc; i++) {
            rm(argv[i]);
        }
        return 0;
    }

    // Run touch
    if (strcmp(command, "touch") == 0) {
        for (int i = ARG_BEGIN_IDX; i < argc; i++) {
            bool success = touch(argv[i]);
            if (success == false) {
                char error_buffer[256];
                snprintf(error_buffer, sizeof(error_buffer), "Could not create file '%s'", argv[i]);
                perror(error_buffer);
                exit(EXIT_FAILURE);
            }
        }
        return 0;
    }

    char error_buffer[256];
    snprintf(error_buffer, sizeof(error_buffer), "Unknown command: %s\n", command);
    fprintf(stderr, error_buffer);
    return 1;
}