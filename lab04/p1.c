#include <stdio.h>

int main(void) {
    long val;
    long* ptr = &val;
    *ptr = 1UL;
    return 0;
}