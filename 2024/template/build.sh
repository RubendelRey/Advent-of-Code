gcc -I../utils -c ../utils/utils.c -o utils.o
gcc -I../utils -c main.c -o main.o
gcc utils.o main.o -o main -lm