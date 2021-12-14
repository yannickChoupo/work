#include <stdio.h>

extern "C" __declspec(dllimport) int __cdecl getOne();
extern "C" __declspec(dllimport) int __cdecl getTwo();
extern "C" __declspec(dllimport) int __cdecl getThree();
int main()
{
    int one = getOne();
    int two = getTwo();
    int three = getThree();
    printf("programm gestartet....\n");
    printf("call one : %d\n", one);
    printf("call two : %d\n", two);
    printf("call Three : %d\n", three);
}