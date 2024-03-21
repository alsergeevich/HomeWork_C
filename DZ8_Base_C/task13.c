//E13-Вторая с конца ноль
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
    int j = 0;
    for(int i = 0; i < SIZE; ++i) {
        if((array[i]/10)%10 == 0) {
            
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}