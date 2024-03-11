/*
Среднее арифметическое чисел
Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
int middle(int a, int b)
Данные на входе: 		Два целых неотрицательных числа 
Данные на выходе: 	    Одно целое число
*/


#include <stdio.h>

int middle(int, int);

int main(void) {
    int a;
    int b;
    scanf("%d%d", &a, &b);
    printf("%d\n", middle(a, b));
}

int middle(int a, int b) {
    return (a + b) / 2;
}