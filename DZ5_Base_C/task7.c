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
    printf("%d\n", sum);
}