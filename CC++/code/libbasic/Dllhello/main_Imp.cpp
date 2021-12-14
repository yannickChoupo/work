#include <stdio.h>
extern "C" char const *_cdecl GetGreeting();
int main()
{
    printf("programm gestartet\n");
    puts(GetGreeting());
}