#include <stdio.h>
#include <math.h>

int main(void)
{
    double xmin, xmax, dx;
    double x, y;

    printf("Tabelle der Sinusfunction \ny = sin(X) \n");
    printf("-----------------------------\n");

    printf("xmin : ");
    scanf("%lf", &xmin);

    printf("xmax : ");
    scanf("%lf", &xmax);

    printf("dx : ");
    scanf("%lf", &dx);
    printf("-----------------------------\n");
    x = xmin;
    while (x < xmax)
    {
        y = sin(x);
        printf("%7.3f %8.3f \n", x, y);
        x = x + dx;
    }
    printf("-----------------------------\n");
    return 0;
}
