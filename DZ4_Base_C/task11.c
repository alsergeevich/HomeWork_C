#include <stdio.h>

int main(void) {

    unsigned a,b,c;
    scanf("%u%u%u", &a, &b, &c);

    (a+b) > c ? (a+c) > b ? (b+c) > a ? printf("YES\n") : printf("NO\n") : printf("NO\n") : printf("NO\n");
}