#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void cd(const char* path) {
    int result = chdir(path);
    if (result != 0) {
        fprintf(stderr, "Error: %s\nInvalid path: %s\n", strerror(errno), path);
        exit(EXIT_FAILURE);
    }
}