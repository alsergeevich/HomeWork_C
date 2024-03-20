#include <stdio.h>


int main(void) {
    int num;
    scanf("%d", &num);

    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    if(sum == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    static int a [10] = {0};
    
}

