#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char ch) {
    return (ch >= '0' && ch <= '9');
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char inputString[1001];
    int numbers[1001], count = 0;

    FILE *input = fopen("input.txt", "r");
    fgets(inputString, sizeof(inputString), input);
    fclose(input);

    int i = 0;
    while (inputString[i] != '\0') {
        if (isNumber(inputString[i])) {
            numbers[count++] = atoi(&inputString[i]);
            while (isNumber(inputString[i])) {
                i++;
            }
        } else {
            i++;
        }
    }

    qsort(numbers, count, sizeof(int), compare);

    FILE *output = fopen("output.txt", "w");
    for (i = 0; i < count; i++) {
        fprintf(output, "%d ", numbers[i]);
    }
    fclose(output);

    return 0;
}
