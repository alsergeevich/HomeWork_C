/*
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе: 		Два целых положительных числа 
Данные на выходе: 	    Одно целое число - наибольший общий делитель. 
*/

#include <stdio.h>

int nod(int, int);

int main(void) {
    int a;
    int b;
    scanf("%d%d", &a, &b);
    printf("%d\n", nod(a, b));
}

int nod(int a, int b) {
    while (a > 0 && b > 0)
    {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
    
}