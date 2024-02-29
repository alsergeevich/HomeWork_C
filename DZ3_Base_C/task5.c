/*
На вход подается произвольное трехзначное число. 
Нужно напечатать произведение цифр.
*/

#include <stdio.h>

int main(void) {

    int num = 0;
    scanf("%d", &num);
    int result = 1;

    while (num != 0)
    {
        result *= num % 10;
        num /= 10;
    }
    printf("%d\n", result);
}