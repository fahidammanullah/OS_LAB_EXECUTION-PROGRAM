#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    printf("LISTING THE DIRECTORY CONTENT\n");
    printf("THE CURRENT DIRECTORY FILES ARE:\n");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closedir(dir);
    return 0;
}
