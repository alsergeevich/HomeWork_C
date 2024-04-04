#include <stdio.h>

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    char buf[1000];
    char c;
    int len = 0;

    FILE *f;

    f = fopen(input, "r");
    if(f != NULL) {
        while(((c = getc(f)) != EOF) && (c != '\n')) {
            buf[len++] = c;
        }
    }
    fclose(f);

    c = buf[len-1];
    f = fopen(output, "w");
    for(int i = 0; i < len-1; ++i) {
        if(c == buf[i]) {
            fprintf(f, "%d ", i);
        }
    }
    fclose(f);
}