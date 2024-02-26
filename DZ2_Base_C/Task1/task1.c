//Перевести из 10 в 16 систему 12345678, 1000000

#include <stdio.h>

void dec_to_hex(unsigned num); //прототип функции для перевода из 10 в 16
void hex_to_dec(unsigned num); //прототип функции для перевода из 16 в 10
unsigned mypow(unsigned num, unsigned e); //прототип функции для возведения в степень

int main(void) {
    unsigned a = 12345678;
    unsigned b = 1000000;
    puts("> 12345678(10) -> (16) <\n");
    puts("Решение: \n");
    dec_to_hex(a);
    printf("\n");
    puts("-----------------------\n");
    puts("> 1000000(10) -> (16) <\n");
    puts("Решение: \n");
    dec_to_hex(b);    
}

void dec_to_hex(unsigned num) {

    unsigned array[32];
    char i = 0;
    while (num != 0)
    {        
        printf("%d / 16 = %d\n", num, num / 16);
        puts("------------");
        printf("%d // 16 = %d\n", num, num % 16);
        array[i] = num % 16;
        puts("============");                
        num = num / 16;
        ++i;
    }
    printf("\n");
    printf("Ответ: ");
    for(char j = i-1; j >= 0; --j) {
        switch (array[j])
        {
        case 10:
            printf("%c", 'A');
            break;
        case 11:
            printf("%c", 'B');
            break;
        case 12:
            printf("%c", 'C');
            break;
        case 13:
            printf("%c", 'D');
            break;
        case 14:
            printf("%c", 'E');
            break;
        case 15:
            printf("%c", 'F');
            break;
        
        default:
            printf("%d", array[j]);
            break;
        }
    }
    printf("\n");
    printf("\n");
}

unsigned mypow(unsigned num, unsigned e) {
    if(e == 0) {return 1;}
    if(e == 1) {return num;}
    unsigned result = 1;
    for(char i = 0; i < e; ++i) {
        result *= num;
    }
    return result;
}

void hex_to_dec(unsigned num) {
    unsigned result = 0;
    unsigned i = 0;
    unsigned array[32];
    while (num != 0)
    {        
        array[i] = num % 16;
        num /= 16;
        ++i;
    }
    
    for(char j = 0; j < i; ++j) {
        printf("%d * 16^%d\n", array[j], j);
        result += ((array[j] * mypow(16, j)));
    }
    puts("\n");
    printf("Ответ: %d\n", result);
    
}