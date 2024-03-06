/*
Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные. 
Данные на входе:		Одно целое число 
Данные на выходе:	YES или NO 
*/

#include <stdio.h>

int main(void) {
    int num;
    char flag = 0;
    scanf("%d", &num);

    while (num != 0)
    {
        if((num % 10) % 2 != 0) {
            flag = 0;
            break;
        }
        else {
            num /= 10;
            flag = 1;
        }
    }
    if(flag) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    
}