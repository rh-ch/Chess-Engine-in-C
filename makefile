all:
	gcc -c choco.c init.c bitboards.c
	gcc choco.o init.o bitboards.c -o choco.exe