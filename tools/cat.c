#include <stdio.h>
#include <stdlib.h>
#define FILE_BUFFER_SIZE 256

void cat(char *filename) {
    FILE *file = fopen(filename, "r");

        if (file == NULL) {
            char errorMsg[256];
            snprintf(errorMsg, sizeof(errorMsg), "Failed to open file '%s'", filename);
            perror(errorMsg);
            exit(EXIT_FAILURE);
        }

        char buffer[FILE_BUFFER_SIZE];

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
    
}