#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool touch(const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        char error_buffer[256];
        snprintf(error_buffer, sizeof(error_buffer), "Could not create file '%s'", filename);
        perror(error_buffer);
        return false;
    }

    fclose(file);
    return true;
}
