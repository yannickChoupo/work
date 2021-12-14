#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
#define ADDAPI __declspec(dllimport)
extern "C"
{
#endif

    ADDAPI char const *_cdecl GetGreeting();

#ifdef __cplusplus
} // __cplusplus defined.
#endif

int main()
{
    puts(GetGreeting());
}
