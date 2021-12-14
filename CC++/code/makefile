CC=g++
CFLAGS=-g -Wall
PWD=C:/Users/Thinkpad_T460s/Programming/work/CC++/code
SRC=src
OBJ=obj

all:
	g++ -g -Wall -c -o main.o main_static.cpp



obj/bitwise.o: ./src/bitwise/bitwise.cpp ./src/bitwise/bitwise.cpp
	$(CC) $(CFLAGS) -c ./src/bitwise/bitwise.cpp -o obj/bitwise.o

obj/pointer.o: ./src/pointer/pointer.cpp ./src/pointer/pointer.h
	$(CC) $(CFLAGS) -c ./src/pointer/pointer.cpp -o obj/pointer.o

obj/test.o: ./src/test/sayHallo.cpp 
	$(CC) $(CFLAGS) -c ./src/test/sayHallo.cpp -o obj/test.o

obj/main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o 

testx: obj/bitwise.o obj/pointer.o obj/test.o obj/main.o
	$(CC) $(CFLAGS) obj/bitwise.o obj/pointer.o obj/test.o obj/main.o

    
utils: obj/bitwise.o obj/pointer.o obj/test.o

static:
	ar rcs -o obj/static.c obj/bitwise.o obj/pointer.o obj/test.o 


build_dll: 
    # compile the source file tom produce an object file under obj/utils.o
	$(CC) $(CFLAGS) -c src/utils.cpp -o obj/utils.o -D UTILS_EXPORTS

share_dll: build_dll
	$(CC) $(CFLAGS) -o utils.dll obj/utils.o -shared -Wl,--subsystem,windows


dynamic_test: share_dll
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -o main.exe -s main.o -L. utils.dll

link: 
	g++ obj/utils.o -shared -o utils.dll

test_lib:
	g++ $(CFLAGS) main.o obj/utils.a

clean: 
	rm *.o *.exe *.a *.dll

	
test:
#build the lib Flag UTILS_EXPORTS -> UTILSAPI = __declspec(dllexport)
	g++ -g -Wall -c -o utils.o ./src/test/sayHallo.cpp -D UTILS_EXPORTS
#
	g++ -g -Wall -o utils.dll -shared  utils.o -Wl,--out-implib,utils.a
	g++ -g -Wall -o main main.cpp -L. lutils.a
	./static.exe
	./main.exe
test_st:
	g++ -g -Wall -c -o static.o ./src/test/static.cpp
	g++ -g -Wall -c -o main.o main_static.cpp
	g++ -g -Wall -o static main.o static.o
	
	

