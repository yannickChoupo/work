#include <stdio.h>
int main(void)
{
    _Bool neu;
    char c1, c2;
    int i, j;
    float x;
    double y;

    i = 3;
    printf("j = ");
    scanf("%i ", &j);
    printf("i, j : %i %i\n", i, j);
    x = 3.0;
    y = 2E-5;
    printf("x, y: %f %f\n", x, y);
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("x, y : %f %f\n", x, y);
    c1 = 'A', c2 = '1';
    printf("c1, c2 : %c %c\n", c1, c2);
    neu = 1;
    printf("neu = %li\n", neu);

    return 0;
}