#include <stdio.h>

int main(void)
{
    int a, b;

    printf("\n   /");
    for (b = 1; b <= 10; b++)
        printf("%3i ", b);

    printf("\n");
    for (b = 1; b <= 11; b++)
        printf("---+");
    printf("\n");

    for (a = 1; a <= 10; a++)
    {
        printf("%2i /", a);
        for (b = 1; b <= 10; b++)
            printf("%3i ", a * b);
        printf("\n\n");
    }
    return 0;
}