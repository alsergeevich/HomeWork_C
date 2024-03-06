/*
Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д. 

Данные на входе:		Целое неотрицательное число 
Данные на выходе:	Целое не отрицательное число наоборот
*/

#include <stdio.h>

int main(void) {
    unsigned num;
    unsigned reverseNum = 0;
    scanf("%u", &num);

    do {
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    } while(num != 0);

    printf("%d\n", reverseNum);    
}