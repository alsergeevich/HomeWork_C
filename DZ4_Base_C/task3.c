//Дано трехзначное число, напечатать максимальную цифру

#include <stdio.h>

int max(int a, int b, int c) {
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

int main(void) {
    int num, a, b, c;
    scanf("%d", &num);
    a = num % 10;
    num /= 10;
    b = num % 10;
    num /= 10;
    c = num % 10;
    printf("%d\n", max(a,b,c));
}