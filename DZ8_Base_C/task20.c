//E20-Составить наибольшее число
#include <stdio.h>


int main(void) {

    int n;
    scanf("%d", &n);
    int array[10] = {0};
    for(; n; n /= 10) {
        array[n%10]++;
    }
    for(int i = 9; i >= 0; i--) {
        for(int j = 0; j < array[i]; ++j) {
            printf("%d", i);
        }
    }
    printf("\n");
}