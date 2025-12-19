#include <stdio.h>
#include <dirent.h>

void ls(const char* dir_name) {
    DIR* dir = opendir(dir_name);
    struct dirent* dir_entry;

    if (dir == NULL) {
        perror("Could not open dir");
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\t", dir_entry->d_name);
    }
}