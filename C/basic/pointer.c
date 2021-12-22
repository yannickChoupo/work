#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Addition a + b\n");
    printf("a = ");
    scanf("%i", &a);
    printf("b = ");
    scanf("%i", &b);
    c = a + b;
    printf("%i + %i = %i", a, b, c);
    return 0;
}
