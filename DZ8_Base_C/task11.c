//E11-Отсортировать по последней цифре
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

void sortArray(int array[], int size) {
    int flag;
    for(int k = 0; k < size; ++k) {
        flag = 0;
        for(int i = 0; i < size-1; ++i) {
            if(array[i]%10 > array[i + 1]%10) {
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
    sortArray(array, SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    
}