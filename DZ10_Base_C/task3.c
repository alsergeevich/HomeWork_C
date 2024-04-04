#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char inputString[1001];
    
    FILE *input = fopen("input.txt", "r");
    fgets(inputString, sizeof(inputString), input);
    fclose(input);
    
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == 'a') {
            inputString[i] = 'b';
        } else if (inputString[i] == 'b') {
            inputString[i] = 'a';
        } else if (inputString[i] == 'A') {
            inputString[i] = 'B';
        } else if (inputString[i] == 'B') {
            inputString[i] = 'A';
        }
    }

    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%s", inputString);
    fclose(output);

    return 0;
}