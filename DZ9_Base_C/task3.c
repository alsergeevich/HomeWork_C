//F3-Цифры по возрастанию

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void swap(char *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sortArray(char array[], int size) {

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

int count (int num, char array[], int size) {
    int result = 0;
    for(int i = 0; i < size; ++i) {
        if(array[i] == num) {
            result += 1;
        }
    }
    return result;
}

void sortNumbers(char array[], int size) {
    if(size == 0) {
        printf("%d %d\n", size, 1);
        return;
    }
    int cnt = 0;

    int lastNum = -1;
    sortArray(array, size);
    for(int i = 0; i < size; ++i) {
        if(lastNum != array[i]) {
            printf("%d %d\n", array[i]-48, count(array[i], array, size));
            lastNum = array[i];
        }
    }
    
}




int main(void) {
    char num[1000];
    gets(num);
    int size = strlen(num);
    sortNumbers(num, size);
    
}