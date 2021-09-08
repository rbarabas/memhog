#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(){
    printf("Usage: ./memhog <size_in_MB>\n");
    exit(1);
}

int main(int argc, char **argv) {
    size_t megabyte = 1024*1024;
    size_t size_allocated = 0;
    size_t mb_requested;
    size_t size_requested;
    
    if (argc != 2) {
        usage();
    }

    if (sscanf(argv[1], "%zu", &mb_requested) == 0) {
        perror("sscanf");
        return 2;
    }
    size_requested = mb_requested * megabyte;

    printf("Allocating up to %zu\n", size_requested);

    while (1) {
        if (size_allocated > size_requested) {
            sleep(600);
            return 0;
        }

        if (malloc(megabyte) == NULL) {
            perror("malloc");
            sleep(600);
            return 3;
        }
        size_allocated += megabyte;

        printf("allocated %zu MB\n", size_allocated / megabyte);
    }

    return 0;
}
