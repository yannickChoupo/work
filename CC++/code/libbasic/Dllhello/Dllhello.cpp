/* addbasic.c

   Demonstrates creating a DLL with an exported function, the inflexible way.


__declspec(dllexport) int __cdecl Add(int a, int b)
{
    return (a + b);
}*/
extern "C" char const *__cdecl GetGreeting()
{
    return "hello, C++ Programmer";
}