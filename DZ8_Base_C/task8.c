//E8-Инверсия каждой трети
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

    const int SIZE = 12;
    int array[SIZE];
    
    inputArray(array, SIZE);
    int firstHalfStart = 0;
    int firstHalfEnd = (SIZE / 3) - 1;
    int secondHalfStart = SIZE / 3;
    int secondHalfEnd = SIZE / 3 + 3;
    int threeHalfStart = SIZE / 3 + SIZE / 3;
    int threeHalfEnd = SIZE - 1;
    while(firstHalfStart - firstHalfEnd != 1) {
        swap(array, firstHalfStart, firstHalfEnd);
        ++firstHalfStart;
        --firstHalfEnd;
    }
    while(secondHalfStart - secondHalfEnd != 1) {
        swap(array, secondHalfStart, secondHalfEnd);
        ++secondHalfStart;
        --secondHalfEnd;
    }
    while(threeHalfStart - threeHalfEnd != 1) {
        swap(array, threeHalfStart, threeHalfEnd);
        ++threeHalfStart;
        --threeHalfEnd;
    }

    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}