/*
Ввести пять чисел и  вывести наименьшее из них 
Нужно напечатать наименьшее число
*/

#include <stdio.h>

int min(int a, int b, int c, int d, int e) {
    int min; 
    min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;
    return min;
}

int main(void) {

    int a,b,c,d,e,result;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    result = min(a,b,c,d,e);
    printf("%d\n", result);
}