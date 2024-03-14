/*
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 	Два целых положительных числа
Данные на выходе: 	Одно целое число n в степени p
*/

#include <stdio.h>

int recurs_power(int n, int p) {
    if (p == 0) {
        return 1;
        
    }
    return n * recurs_power(n, p-1);
}

int main(void) {
    int n;
    int p;
    scanf("%d%d", &n, &p);
    printf("%d", recurs_power(n, p));
}