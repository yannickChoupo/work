all:
#//////////////////   Explicit LINKING   ////////////////////////////////////////////
dll: 
# Compile source fikle to an object file 
    cl /c Dllhello.cpp
    
# /DLL -> to DLL File and not to exe as it is default 
# /NOENTRY -> 
# /EXPORT -> what the API will expose
    link Dllhello.obj /DLL /NOENTRY /EXPORT:GetGreeting

dllbasic: dll
# SAME DLL BUT -> extern "C" char const *_cdecl GetGreeting();
# Compile test main
    cl main.cpp

# Run the exe
    .\main.exe
#///////////////////     IMPLICIT LINKING    //////////////////////////////////////

dllimplicit: dll
# SAME DLL BUT -> extern "C" char const *_cdecl GetGreeting();
    cl /c main_imp.cpp

# Link the Objject test file with the dynamic linked library
    cl main_imp.obj Dllhello.lib
# Run the exe
    .\main_imp.exe
#////////////////////////////////////////////////////////////////////////////////
clean: 
    rm *.obj *.dll *.exe *.exp *.lib