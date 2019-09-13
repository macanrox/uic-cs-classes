all: mainC mainC.i func2C.i mainC.s func2C.s mainC.o func2C.o

mainC: 
	gcc -g -o mainC mainC.c

mainC.i:
	gcc -o mainC.i -E mainC.c

func2C.i:
	gcc -o func2C.i -E func2C.c

mainC.s:
	gcc -S mainC.i

func2C.s:
	gcc -S func2C.i

mainC.o:
	gcc -c mainC.s

func2C.o:
	gcc -c func2C.s