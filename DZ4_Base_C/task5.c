#include <stdio.h>

void equation_of_a_line(int x1, int y1, int x2, int y2) {

    float k = 0.0;
    float b = 0.0;

    k = (float)(y2-y1) / (float)(x2-x1);
    b = (float)y2 - ((float)(y2-y1) / (float)(x2-x1)) * (float)x2;
    printf("%.2f %.2f\n", k, b);
}

int main(void) {
    int x1,y1,x2,y2;
    scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
    equation_of_a_line(x1,y1,x2,y2);
}