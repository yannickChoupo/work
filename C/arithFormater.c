#include <stdio.h>
#include <stdlib.h>

void arithFormater(char *str)
{
}
/**
 * @brief - continue to read the read after seeing white space character
 *        - it must reading the string after seeing the new line character
 *        - it must discard extra character
 *        - it must return the number of character it store
 *
 * @param limit the max length of the input
 * @return the number of character stored
 */
// Get input with getchar
char *abc()
{
    int ch;
    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        putchar(ch);
    }
    return 0;
}
int input(char *str, int limit)
{
    int i = 0;
    char ch;
    do
    {
        ch = getchar();
        if (i < limit)
            str[i++] = ch;
    } while (ch != '\n');
    return i;
}
int main()
{
    char *strArr[] = {"32 + 698", "3801 - 2", "45 + 43", "123 + 49"};
    char charArr[] = "Hello World!";
    printf("char : %s\n", *(strArr + 4));
    printf("size of arr : %i\n", sizeof(strArr) / sizeof(*strArr));
    char *ptr = charArr;
    while (*ptr != '\0')
    {
        printf("char : %c\n", *ptr);
        ptr++;
    }

    return 0;
}