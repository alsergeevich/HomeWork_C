//E1-Среднее арифметическое
#include <stdio.h>

int main(void) {
    const int SIZE = 5;
    int array[SIZE];
    int inputVar;
    int sum = 0;
    float result = 0;
    for(int i = 0; i < SIZE; ++i) {
        scanf("%d", &inputVar);
        array[i] = inputVar;
        sum += inputVar;
    }
    result = ((float)sum / (float)SIZE);
    printf("%.3f\n", result);

}