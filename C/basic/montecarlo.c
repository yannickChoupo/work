#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i; /* counter */
    int n; /* number of random number */
    int treffer;
    double x, y;
    double pi;

    printf("Berrechnung von pi, Anzahl der zufahlzahlen = ");
    scanf("%i", &n);
    treffer = 0;
    for (i = 0; i < n; i++)
    {
        x = 1.0 * rand() / RAND_MAX;
        y = 1.0 * rand() / RAND_MAX;
        if (sqrt(x * x + y * y) < 1)
        {
            treffer = treffer + 1;
        }
    }
    pi = 4.0 * treffer / n;
    printf("pi = %3.6f", pi);

    return 0;
}