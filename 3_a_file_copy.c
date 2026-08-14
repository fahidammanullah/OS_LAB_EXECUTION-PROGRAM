#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("Source file");
        return 1;
    }

    FILE *dst = fopen(argv[2], "w");
    if (dst == NULL) {
        perror("Destination file");
        fclose(src);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), src) != NULL)
        fputs(line, dst);

    fclose(src);
    fclose(dst);

    printf("FILE HAS BEEN COPIED SUCCESSFULLY\n");
    return 0;
}
