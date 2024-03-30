//F4-Цифры в строке

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_digit(char s[]) {
    size_t count = 0;
    int array[255] = {0};
    for(; *s; ++s) {
        if(isdigit(*s)) {
            array[*s-48] += 1;
        }
    }
    for(int i = 0; i < 255; ++i) {
        if(array[i] != 0) {
            printf("%d %d\n", i, array[i]);
        }
    }
}




int main(void) {

    char str[256];
    gets(str);
    print_digit(str);
}
