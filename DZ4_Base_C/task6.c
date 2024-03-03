#include <stdio.h>

int main(void) {

    int a, b;
    scanf("%d%d", &a, &b);
    a > b ? printf("Above\n") : a < b ? printf("Less\n") : printf("Equal\n");

}