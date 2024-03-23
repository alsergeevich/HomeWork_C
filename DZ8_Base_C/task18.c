//E18-Кратность от 2 до 99
#include <stdio.h>


int main(void)
{
   int arrayNumbersCount[8] = {0};
   int n;
   scanf("%d", &n);
   for(int i = 2; i < 10; ++i) {
    for(int j = i; j <= n; j += i) {
        
        arrayNumbersCount[i-2] += 1;        
    }
   }
   for(int i = 0; i < 8; ++i) {
    printf("%d %d\n", i+2, arrayNumbersCount[i]);
   } 
            
} 