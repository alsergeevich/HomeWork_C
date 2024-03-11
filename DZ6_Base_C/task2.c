/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
*/

#include <stdio.h>

int sumNumbers(int);

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%d\n", sumNumbers(n));
}

int sumNumbers(int n) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}