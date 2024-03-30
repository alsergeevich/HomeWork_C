#include <stdio.h>

void swap_negmax_last(int size, int a[]) {
    int maxNegativeNum = -100000;
    int indexEl = -1;
    for(int i = 0; i < size; ++i) {
        if(a[i] < 0 && a[i] > maxNegativeNum ) {
            maxNegativeNum = a[i];
            indexEl = i;
        }
    }
    if(indexEl >= 0) {
        int temp = a[indexEl];
        a[indexEl] = a[size-1];
        a[size-1] = temp;
    }
}

int main(void) {
    int a[10] = {1, 2, 3, -4, 5, 6, 7, 8, 9, 10};
    swap_negmax_last(10, a);
    for(int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}