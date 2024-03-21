//E12-По возрастанию и по убыванию
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

void sortArrayUp(int array[], int size, int begin, int end) {
    int flag;
    for(int k = 0; k < size; ++k) {
        flag = 0;
        for(int i = begin; i < end; ++i) {
            if(array[i] > array[i + 1]) {
                swap(array, i, i+1);
                flag = 1;
            }
            
        }
        if(flag == 0) {
            return;
        }
    }
}

void sortArrayDown(int array[], int size, int begin, int end) {
    int flag;
    for(int k = 0; k < size; ++k) {
        flag = 0;
        for(int i = begin; i < end; ++i) {
            if(array[i] < array[i + 1]) {
                swap(array, i, i+1);
                flag = 1;
            }
            
        }
        if(flag == 0) {
            return;
        }
    }
}

int main(void) {

    const int SIZE = 10;
    int array[SIZE];
    
    inputArray(array, SIZE);
    int firstHalfStart = 0;
    int firstHalfEnd = (SIZE / 2)-1;
    int secondHalfStart = SIZE / 2;
    int secondHalfEnd = SIZE - 1;
    
    sortArrayUp(array, SIZE, firstHalfStart, firstHalfEnd);
    sortArrayDown(array, SIZE, secondHalfStart, secondHalfEnd);

    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}