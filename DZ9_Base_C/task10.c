#include <stdio.h>

int count_between(int from, int to, int size, int array[]) {
    int count = 0;
    int uniqueElements[100] = {0};
    
    
    int temp;
    if (from > to) {
        temp = from;
        from = to;
        to = temp;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] >= from && array[i] <= to) {
            
            int isUnique = 1;
            for (int j = 0; j < count; j++) {
                if (uniqueElements[j] == array[i]) {
                    isUnique = 0;
                    break;
                }
            }
            
            if (isUnique) {
                uniqueElements[count] = array[i];
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int arr[] = {6, 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int from = 4, to = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = count_between(from, to, size, arr);
    printf("Number of unique elements in the range [%d, %d] is: %d\n", from, to, result);
    return 0;
}
