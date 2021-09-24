all: main

main: main.c
	gcc main.c utility.c operations.c -o prog -w -lm
