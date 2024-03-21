//E6-Среднее арифметическое 2
#include <stdio.h>

void inputArray(int array[], int size) {
    int inputVar;

    for(int i = 0; i < size; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
}

int main(void) {

    const int SIZE = 12;
    int array[SIZE];
    float result = 0.0;
    inputArray(array, SIZE);
    int sum = 0;
    for(int i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    result = (float)sum / (float)SIZE;
    printf("%.2f\n", result);
}