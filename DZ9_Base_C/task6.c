#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b) {
    return (*(int*)a - *((int*)b));
}

int is_two_same(int size, int a[]) {
    int result = 0;
    qsort(a, size, sizeof(int), compare);
    for(int i = 0; i < size-1; ++i) {
        if(a[i] == a[i+1]) {
            result = 1;
            break;
        }
    }
    return result;
}


int main(void) {

    int a[] = {1,3,9,6,8,9};
    if(is_two_same(6, a)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}