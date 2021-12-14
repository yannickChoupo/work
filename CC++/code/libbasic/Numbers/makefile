dll:
	cl /c Numbers.cpp
#   LINK Numbers.obj /DLL /NOENTRY /DEF:Numbers.def -> Module definition file (LiST of exports)
#	link Numbers.obj /DLL /NOENTRY /EXPORT:getOne /EXPORT:getTwo /EXPORT:getThree /Export:getOnePlusTwo=getThree 
#				     /EXPORT:One,DATA
#	#pragma(linker,"export/:getOne")
	link Numbers.obj /DLL /NOENTRY /EXPORT:getOne /EXPORT:getTwo /EXPORT:getThree

test:
# 	Compile the test
	link NumbersTest.cpp
	
# 	link with the dll
	link NumbersTest.obj Numbers.dll

clean: 
    rm *.obj *.dll *.exe *.exp *.lib