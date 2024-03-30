#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b) {
    return (*(int*)a - *((int*)b));
}

void sort(int size, int a[]) {
    qsort(a, size, sizeof(int), compare);
}

int main(void) {

    int countNum = 0;
    int num = -1;
    int a[1000] = {0};
    while (1)
    {
        scanf("%d", &num);
        if(num == 0) break;
        a[countNum++] = num;
    }
    
    sort(countNum, a);
    for(int i = 0; i < countNum-1; ++i) {
        if(a[i+1] - a[i] >=2 ) {
            printf("%d\n", a[i] + 1);
            break;
        }
    }    
}