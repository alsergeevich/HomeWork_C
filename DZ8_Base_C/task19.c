//E19-Цифры по возрастанию
#include <stdio.h>

void directNumber(int n) {
    if (n / 10 > 0) {
        directNumber(n / 10);
    }

    printf("%d ", n % 10);
}

int main(void) {

    int n;
    scanf("%d", &n);
    directNumber(n);
    printf("\n");
}