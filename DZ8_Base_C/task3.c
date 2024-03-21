//E3-Максимум и минимум и их номера
#include <stdio.h>

int main(void) {
    const int SIZE = 10;
    int array[SIZE];
    int inputVar;

    for(int i = 0; i < SIZE; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
    int min = array[0];
    int max = array[0];
    int min_el = 0;
    int max_el = 0;
    for(int i = 0; i < SIZE; ++i) {
        if(array[i] < min) {
            min = array[i];
            min_el = i;
        }
        if(array[i] > max) {
            max = array[i];
            max_el = i;
        }        
    }
    printf("%d %d %d %d\n", max_el+1, max, min_el+1, min);
}