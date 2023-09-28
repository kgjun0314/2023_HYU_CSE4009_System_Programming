#include<stdio.h>
int main(void) {
    float inf, nan;
    *((int*) &inf) = 0b01111111100000000000000000000000;
    *((int*) &nan) = 0b01111111100000000000000000000001;
    printf("%d\n", nan < nan);
    printf("%d\n", nan > nan);
    printf("%d\n", nan == nan);
    printf("%d\n", inf > nan);
    printf("%d\n", inf < nan);
    printf("%d\n", inf == nan);
    printf("%d\n", inf < inf);
    printf("%d\n", inf > inf);
    printf("%d\n", inf == inf);
    return 0;
}