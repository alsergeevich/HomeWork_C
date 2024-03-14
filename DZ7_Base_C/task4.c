/*
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 	Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа.
*/

#include <stdio.h>

int countUnit(unsigned n) {
    static int count = 0;
    if(n != 0) {
       count += n % 2;
       countUnit(n / 2); 
    }
    return count;
    
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", countUnit(n));
}