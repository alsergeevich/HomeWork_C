//Напечатать сумму максимума и минимума.


#include <stdio.h>

int min(int a, int b, int c, int d, int e);
int max(int a, int b, int c, int d, int e);



int main(void) {
    int a, b, c, d, e, result;
    scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
    result = min(a,b,c,d,e) + max(a,b,c,d,e);
    printf("%d\n", result);
}

int min(int a, int b, int c, int d, int e) {
    int min; 
    min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;
    return min;
}

int max(int a, int b, int c, int d, int e) {
    int max; 
    max = a > b ? a : b;
    max = max > c ? max : c;
    max = max > d ? max : d;
    max = max > e ? max : e;
    return max;
}