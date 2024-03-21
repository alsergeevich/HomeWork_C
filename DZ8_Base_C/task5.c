//E5-Сумма положительных элементов
#include <stdio.h>

void inputArray(int array[], int size) {
    int inputVar;

    for(int i = 0; i < size; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
}

int main(void) {

    const int SIZE = 10;
    int array[SIZE];

    inputArray(array, SIZE);
    int sum = 0;
    for(int i = 0; i < SIZE; ++i) {
        if(array[i] > 0) {
            sum += array[i];
        }
    }
    printf("%d\n", sum);
}