#include <stdio.h>

int main(void)
{
    double z; /* each number */
    double p; /* the product of all numbers */
    int i, n;

    printf("Product of n numbers \n");
    printf("n = ");
    scanf("%d", &n);

    printf(" 1: ");
    scanf("%lf", &z);
    p = z;
    for (i = 2; i <= n; i++)
    {
        printf("%2d: ", i);
        scanf("%lf", &z);
        p = p * z;
    }
    printf("The product of all th numbers is equal %10.5g\n", p);
    return 0;
}