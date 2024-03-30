//F2-Четные в начало
#include <stdio.h>

void sort_even_odd(int n, int a[]) {
    int arr_1[n];
    int arr_2[n];
    
    int arr1_size = 0;
    int arr2_size = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] % 2 == 0) {
            arr_1[arr1_size++] = a[i];
        }
        else if (a[i] % 2 != 0) {
            arr_2[arr2_size++] = a[i];
        }
        
    }
    for(int i = 0; i < arr1_size; ++i) {
        a[i] = arr_1[i];
    }
    int j = 0;
    for(int i = arr1_size; i < n; ++i) {
        a[i] = arr_2[j++];
    }
}