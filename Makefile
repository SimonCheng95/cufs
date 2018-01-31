CC = gcc
CFLAGS = -g -Wall `pkg-config fuse --cflags`
FUSE_LIB = -g -Wall `pkg-config --libs` -L/usr/lib

DEPS = *.h

all : init cufs

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cufs : ufs.o errorlog.o error.o op.o
	$(CC) $(CFLAGS) cufs.o errorlog.o error.o op.o $(FUSE_LIB) -o cufs

init : init.o
	$(CC) $(CFLAGS) init.o -o init

clean : 
	rm -f *.o init cufs
