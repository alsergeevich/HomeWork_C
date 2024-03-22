// E15-Разложить по двум
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

int main(void)
{
    
    int array[SIZE] = {0};
    int arrayPositive[SIZE] = {0};
    int arrayNegative[SIZE] = {0};
    int j = 0;
    int k = 0;
    inputArray(array, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        if (array[i] > 0)
        {
            arrayPositive[j++] = array[i];
        }
        else if (array[i] < 0)
        {
            arrayNegative[k++] = array[i];
        }
        else
        {
            continue;
        }
    }
    for(int i = 0; i < SIZE; ++i) {
        if(arrayPositive[i] == 0) {
            break;
        }
        printf("%d ", arrayPositive[i]);
    }
    for(int i = 0; i < SIZE; ++i) {
        if(arrayNegative[i] == 0) {
            break;
        }
        printf("%d ", arrayNegative[i]);
    }
    printf("\n");
}    