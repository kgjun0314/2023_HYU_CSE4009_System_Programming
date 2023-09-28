#include <stdio.h>
void show_bytes(char* start, size_t len) {
    size_t i;
    for(int i = 0; i < len; i++)
        printf("%p\t%.2x\n", start + i, start[i]);
    printf("\n");
}

int main(void) {
    int val = 0x1234567;
    show_bytes((char*) &val, sizeof(val));
    return 0;
}