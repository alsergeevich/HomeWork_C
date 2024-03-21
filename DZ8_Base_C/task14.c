//E14-Более одного раза
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



int main(void) {

    const int SIZE = 10;
    int j = 0;
    int array[SIZE];
    int outArray[SIZE];    
    inputArray(array, SIZE);    
    sortArray(array, SIZE);
    for(int i = 0; i < SIZE-1; ++i) {
        if(array[i] == array[i+1]) {
            outArray[j++] = array[i];
        }
    }
    int lastNum = -1;
    for(int i = 0; i < j; ++i) {
        if(outArray[i] != lastNum) {
            printf("%d ", outArray[i]);
        }
        lastNum = outArray[i];
    }
    printf("\n");
}