#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(char *filename) {
    FILE *file = fopen(filename, "r");

        if (file == NULL) {
            char errorMsg[256];
            snprintf(errorMsg, sizeof(errorMsg), "Failed to open file '%s'", filename);
            perror(errorMsg);
            exit(EXIT_FAILURE);
        }

        char buffer[BUFSIZ];

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
    
}