#include <stdio.h>
#include <stdlib.h>

struct name {
    char first[12];
    char last[12];
};

long main(void) {
    long i = 3;
    long* pi = &i;
    long arr[10];

    struct name* n = (struct name*) malloc(sizeof(struct name));

    *pi = 1;
    arr[3] = 0x30;
    arr[i] = 0x31;
    n -> last[0] = 0x32;
    free(n);

    return 0;
}