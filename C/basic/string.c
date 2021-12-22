#include <stdio.h>

#define NMAX 10

/* Get Keyboard input up to neu line */
void getString1()
{
    char zeile[NMAX];
    char c;
    int i;

    i = 0;
    c = getchar();
    while (c != '\n')
    {
        zeile[i] = c;
        i++;
        c = getchar();
    }

    zeile[i] = '\0';

    printf("Eingegebene Zeile : \n%s\n", zeile);
}
void copyStr()
{
    char s1[NMAX], s2[NMAX], s3[NMAX];
    int i, j;

    printf("string 1 = ");
    gets(s1);
    printf("string 2 = ");
    gets(s2);

    /* Zeichenkette s1 auf s3 */
    for (i = 0; s1[i] != '\0'; i++)
        s3[i] = s1[i];

    /* Zeichenkette s2 auf s3 */
    j = i;
    for (i = 0; s2[i] != '\0'; i++)
    {
        s3[j] = s2[i];
        j++;
    }

    s3[j] = '\0';

    puts(s3);
}
int main(void)
{
    copyStr();
    return 0;
}