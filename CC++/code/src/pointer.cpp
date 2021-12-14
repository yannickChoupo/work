#include "utils.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(long *a, long *b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}
long double summe(long double *f, int n)
{
    long double summe = 0;
    for (int i = 0; i < n; i++)
    {
        summe += *(f + i);
    }
    return summe;
}
long double durchnitt(long double *f, int n)
{
    return summe(f, n) / n;
}
bool input(long double *f, int n)
{
    if (n < 1)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Wert " << i + 1 << ":";
        cin >> f[i];
    }
    return true;
}
bool output(long *f, long n)
{
    if (n < 1)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Wert " << i + 1 << ":" << f[i] << endl;
    }
    return true;
}
long maximum(long *f, long n)
{
    long max = *f;
    long maxPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i] > max)
        {
            max = f[i];
            maxPos = i;
        }
    }
    return maxPos;
}
long double maximum(long double *f, int n)
{
    long double max = *f;
    long double maxPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i] > max)
        {
            max = f[i];
            maxPos = i;
        }
    }
    return maxPos;
}
void sort(long double *f, int n)
{
    long maxPos;
    for (int i = n - 1; i >= 0; i--)
    {
        maxPos = maximum(f, i + 1);
        swap(f[maxPos], f[i]);
    }
}