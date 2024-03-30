#include <stdio.h>

void inputArray(int array[], int size) {
    int inputVar;

    for(int i = 0; i < size; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;        
    }
}


void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void print_digit(int a[], int size) {
    
    int oneIndex = 0;
    int twoIndex = 1;
    
    if(a[oneIndex] > a[twoIndex]) {
        swap(&oneIndex, &twoIndex);
    }

    for(int i = 2; i < size; ++i) {
        if(a[i] < a[oneIndex]) {
            swap(&oneIndex, &twoIndex);
            oneIndex = i;
            continue;
        }
        if(a[i] < a[twoIndex]) {
            twoIndex = i;
        }        
    }
    if(oneIndex > twoIndex) swap(&oneIndex, &twoIndex);
    printf("%d %d\n", oneIndex, twoIndex);
    

}




int main(void) {

    int a[30] = {0};
    inputArray(a, 30);
    print_digit(a, 30);
}