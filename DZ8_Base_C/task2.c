//E2-Найти минимум
#include <stdio.h>

int main(void) {
    const int SIZE = 5;
    int array[SIZE];
    int inputVar;

    for(int i = 0; i < SIZE; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
    int min = array[0];
    for(int i = 1; i < SIZE; ++i) {
        if(array[i] < min) {
            min = array[i];
        }        
    }
    printf("%d\n", min);
}