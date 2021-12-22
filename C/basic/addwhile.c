#include <stdio.h>

int main()
{
    double a, b, c;
    printf("Addition a + b, (a and b reel) !\n");
    printf("Ende mit a = 0 oder b = 0\n\n");
    do
    {
        printf("a = ");
        scanf("%lf\n", &a);
        printf("b = ");
        scanf("%lf\n", &b);
        c = a + b;
        printf("%8.2f + %8.2f = %8.2f\n", a, b, c);
    } while ((a != 0) && (b != 0));

    return 0;
}