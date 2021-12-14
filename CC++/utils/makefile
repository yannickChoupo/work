CC=g++
CFLAGS=-g -Wall
OBJS=xxxxx.o xxxxxx.o
BIN=utils
SUBMITNAME=utils.zip

all:$(BIN)

utils: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< o $@

clean:
	$(RM) -r main *.o