#include <stdio.h>
#include <dirent.h>

void ls(const char* dir_name) {
    struct dirent* dir_entry;
    DIR* dir;

    if (dir_name == NULL) {
        dir = opendir(".");
    } else {
        dir = opendir(dir_name);
    }

    if (dir == NULL) {
        perror("Could not open dir");
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\t", dir_entry->d_name);
    }
}