//E9-Циклический сдвиг вправо
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
    for(int i = SIZE-1; i > 0; --i) {
        swap(array, i, i-1);
    }

    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}