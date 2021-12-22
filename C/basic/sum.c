#include <stdio.h>

int main()
{
    int n = 100, sum = 0;
    for (int i = 0; i <= n; i++)
        sum = sum + i;

    printf("The sum of 1 + 2 + 3 + ...+ %d = %d\n", n, sum);
    return 0;
}