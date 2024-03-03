//Ввести пять чисел и  вывести наибольшее из них 
//Нужно напечатать наибольшее число


#include <stdio.h>

int max(int a, int b, int c, int d, int e) {
    int max; 
    max = a > b ? a : b;
    max = max > c ? max : c;
    max = max > d ? max : d;
    max = max > e ? max : e;
    return max;
}

int main(void) {

    int a,b,c,d,e,result;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    result = max(a,b,c,d,e);
    printf("%d\n", result);
}