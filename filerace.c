#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];

    printf("Swapping %s with %s periodically...\n", file1, file2);
    fflush(stdout);

    while (1)
    {
        if (-1 == renameat2(AT_FDCWD, file1, AT_FDCWD, file2, RENAME_EXCHANGE))
        {
            perror("renameat2");
            return 1;
        }
    }
}
