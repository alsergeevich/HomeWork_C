//E7-Инверсия половин
#include <stdio.h>

void inputArray(int array[], int size) {
    int inputVar;

    for(int i = 0; i < size; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main(void) {

    const int SIZE = 10;
    int array[SIZE];
    
    inputArray(array, SIZE);
    int firstHalfStart = 0;
    int firstHalfEnd = (SIZE / 2) - 1;
    int secondHalfStart = SIZE / 2;
    int secondHalfEnd = SIZE - 1;
    while(firstHalfEnd - firstHalfStart != 0) {
        swap(array, firstHalfStart, firstHalfEnd);
        ++firstHalfStart;
        --firstHalfEnd;
    }
    while(secondHalfEnd - secondHalfStart != 0) {
        swap(array, secondHalfStart, secondHalfEnd);
        ++secondHalfStart;
        --secondHalfEnd;
    }

    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}