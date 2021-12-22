#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NMAX 100

int main(void)
{
    int sorted;
    int i, n;
    int x[NMAX];
    int h;

    /* Einlesen der Zahlen */

    printf("Bubble sortiert maximal %3d Zahlen !\n", NMAX);
    printf("Wieviele Zahlen sollen sortiert werden ? ");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        printf("%2i : ", i + 1);
        scanf("%2i", &x[i]);
    }

    /* Sortieren */

    do
    {
        sorted = TRUE;
        for (i = 0; i < n - 1; i++)
            if (x[i + 1] < x[i])
            {
                h = x[i];
                x[i] = x[i + 1];
                x[i + 1] = h;
                sorted = FALSE;
            }
    } while (sorted == FALSE);

    /* Sorted Number */
    printf("------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%2i : %3i\n", i + 1, x[i]);
    }

    return 0;
}