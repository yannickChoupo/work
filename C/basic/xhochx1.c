#include <stdio.h>

int main(void)
{
    double x, g; /*Exponent, precition */
    int n;       /* Nenner */
    double z;    /* Zaheler */
    double si;   /* EInzelnen SUmmanden */
    double s;    /* DIe SUmme */
    int i;       /* Nummer der aktuellen Summanden */
    printf("Berechnung von e^^x \n\n");
    printf("x = ");
    scanf("%lf", &x);
    printf("The Precision g = ");
    scanf("%lf", &g);
    printf("  i    summand     summe\n");
    printf("-------------------------\n");

    s = 1.0;
    i = 0;
    n = 1;
    z = 1.0;
    do
    {
        i++;
        n = n * i;
        z = z * x;
        si = z / n;
        s = s + si;
        printf("%3d %12.6f %12.6f\n", i, si, s);
    } while (si > g);

    return 0;
}
