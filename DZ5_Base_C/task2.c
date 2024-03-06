/*
Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры. 
*/

#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    num /= 100;
    if(num != 0 && (num >= -9 && num <= 9)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}