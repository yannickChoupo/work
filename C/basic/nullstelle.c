#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, xmin, xmax, dx;
    double y;
    char curSign, oldSign;
    printf("Tabelle einer Funktion, Nullstellen entdecken \n");
    printf("xmin, xmax, dx : ");
    scanf("%lf %lf %lf", &xmin, &xmax, &dx);
    x = xmin;
    y = exp(0.1 * x) * cos(x);
    printf("%8.2f %8.2f \n", x, y);
    if (y < 0.0)
        oldSign = '-';
    else
        oldSign = '+';

    do
    {
        x = x + dx;
        y = exp(0.1 * x) * cos(x);
        if (y < 0.0)
            curSign = '-';
        else
            curSign = '+';

        if (oldSign != curSign)
            printf("Nullstelle vorhande !\n");

        printf("%8.2f %8.2f \n", x, y);
        oldSign = curSign;
    } while (x <= xmax);

    return 0;
}
