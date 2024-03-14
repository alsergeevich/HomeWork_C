/*
От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, 
в порядке возрастания, если A < B, или в порядке убывания в противном случае.

Данные на входе: 		Два целых числа через пробел. 
Данные на выходе: 	    Последовательность целых чисел. 
*/

#include <stdio.h>

void outputNum(int a, int b) {
    if (a == b) {
        printf("%d ", a);
    }
    if (a < b) {        
        outputNum(a, b-1);
        printf("%d ", b);
    }
    if (a > b) {
        printf("%d ", a);
        outputNum(a-1, b);
    }
}

int main(void) {
    int a;
    int b;
    scanf("%d%d", &a, &b);
    outputNum(a, b);
}