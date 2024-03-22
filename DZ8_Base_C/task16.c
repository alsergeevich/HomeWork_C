//E16-Чаще всего
#include <stdio.h>
#define SIZE 10

void inputArray(int array[], int size)
{
    int inputVar;

    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &inputVar);
        array[i] = inputVar;
    }
}

int countElement(int array[], int size, int element) {
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if(array[i] == element) {
            ++count;
        }
    }
    return count;
}

int main(void)
{
    
    int array[SIZE] = {0};
    int el = 0;
    int count = 0;
    int max = 0;
    inputArray(array, SIZE);
    for(int i = 0; i < SIZE; ++i) {
        count = countElement(array, SIZE, array[i]);
        if (count > max)
        {
            max = count;
            el = array[i];
        }        
    }
    printf("%d\n", el);    
} 