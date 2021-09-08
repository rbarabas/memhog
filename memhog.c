#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    size_t megabyte = 1024*1024;
    size_t size_allocated = 0;
    
    while (1) {
        if (malloc(megabyte) == NULL) {
            perror("malloc");
            break;
        }
        size_allocated += megabyte;
        printf("allocated %zu MB\n", size_allocated / megabyte);
    }
    sleep(600);

    return 0;
}
