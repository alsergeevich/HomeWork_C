/*
Ввести три числа, найти их  среднее арифметическое
Нужно напечатать среднее арифметическое чисел
Данные на входе:       Три целых целых числа через пробел
Данные на выходе:    Вещественное число в формате %.2f

*/

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d", &a, &b, &c);
    printf("%.2f\n", (a+b+c)/3.0);
}