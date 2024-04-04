#include <stdio.h>
#include <ctype.h>

int main() {
    char inputString[10001];
    int lowercaseCount = 0, uppercaseCount = 0;

    FILE *input = fopen("input.txt", "r");
    fgets(inputString, sizeof(inputString), input);
    fclose(input);

    for (int i = 0; inputString[i] != '\0'; i++) {
        if (isalpha(inputString[i])) {
            if (islower(inputString[i])) {
                lowercaseCount++;
            } else if (isupper(inputString[i])) {
                uppercaseCount++;
            }
        }
    }

    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%d %d", lowercaseCount, uppercaseCount);
    fclose(output);

    return 0;
}