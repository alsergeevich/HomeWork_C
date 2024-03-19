/*Ввести три числа, найти их сумму. 
Нужно напечатать сумму трех чисел.
Данные на входе:       Три целых числа через пробел
Данные на выходе:    Строка вида %d+%d+%d=%d
*/
#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;
    int result = 0;
    scanf("%d%d%d", &a, &b, &c);
    result = a + b + c;
    printf("%d+%d+%d=%d\n", a, b, c, result);
}