/*
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
*/

#include <stdio.h>

int main(void) {

    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    c > b ? b > a ? printf("YES\n") : printf("NO\n") : printf("NO\n");
}