#include <stdio.h>
#include "windows.h"
int main(int argc, char **argv)
{
    printf("programm startet");
    // LoadLibraryExW : goes, find the dll loads into the memery and gives
    // gives back a handle back called HMODULE that can be use to refer to the
    // DLL that's have been loaded into the memory

    HMODULE const HelloDll = LoadLibraryExW(L"Dllhello.dll", nullptr, 0);

    // Create a function pointer type that match the type of the function
    // of the fucntion exported

    using GetGreetingType = char const *(__cdecl *)();

    // GetProcAddress :
    // call GetProcAddress on the GretGreeting function
    // ask the loader to us the ADDRESS OF THE GetGreeting FUNCTION INSIDE the DLL

    // Reinterpret cast the ADDRESS send back from the GetProcAddress on the
    // function GetGreeting to the APPROPRIATE TYPE

    GetGreetingType const GetGreeting = reinterpret_cast<GetGreetingType>(
        GetProcAddress(HelloDll, "GetGreeting"));

    // call pts to print the string out
    puts(GetGreeting());

    // free Library because we are done using the the DLL
    FreeLibrary(HelloDll);
}