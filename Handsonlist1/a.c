#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello from a.out!\n");
    if (argc > 1) {
        printf("Received argument: %s\n", argv[1]);
    }
    return 0;
}

