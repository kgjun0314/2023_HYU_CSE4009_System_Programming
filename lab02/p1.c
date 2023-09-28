#include <stdio.h>
#include <stdlib.h>

void printb(char ch) {
    int val = (int)ch;
    for(int i = 7; i > -1; i--) {
        printf("%d", (val >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char op;
    int num1, num2;

    scanf("%d %c %d", &num1, &op, &num2);

    if(op == '&')
    {
        printf("  ");
        printb((char)num1);
        printf("%c ", op);
        printb((char)num2);
        printf("----------\n  ");
        printb((char)(num1 & num2));
    }
    else if(op == '|')
    {
        printf("  ");
        printb((char)num1);
        printf("%c ", op);
        printb((char)num2);
        printf("----------\n  ");
        printb((char)(num1 | num2));
    }
    else if(op == '^')
    {
        printf("  ");
        printb((char)num1);
        printf("%c ", op);
        printb((char)num2);
        printf("----------\n  ");
        printb((char)(num1 ^ num2));
    }
    else if(op == '~')
    {
        printf("%c ", op);
        printb((char)num2);
        printf("----------\n  ");
        printb((char)(~num2));
    }

    return 0;
}