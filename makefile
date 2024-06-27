all:
	gcc -c choco.c init.c
	gcc choco.o init.o -o choco.exe