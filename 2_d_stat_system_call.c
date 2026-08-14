#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
    struct stat sfile;

    if (stat("2_d_stat_system_call.c", &sfile) == -1) {
        perror("stat");
        return 1;
    }

    printf("file st_uid: %ld\n", (long)sfile.st_uid);
    printf("file st_gid: %ld\n", (long)sfile.st_gid);
    printf("file st_size: %ld\n", (long)sfile.st_size);
    printf("file st_blocks: %ld\n", (long)sfile.st_blocks);
    printf("file serialno: %ld\n", (long)sfile.st_ino);
    printf("file recent access time: %ld\n", (long)sfile.st_atime);
    printf("file permission change time: %ld\n", (long)sfile.st_ctime);
    printf("file recent modified time: %ld\n", (long)sfile.st_mtime);

    return 0;
}
