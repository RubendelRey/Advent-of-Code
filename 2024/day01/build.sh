gcc -I../utils -c ../utils/utils.c -o utils.o
gcc -I../utils -c ./part1/part1.c -o part1.o
gcc -I../utils -c ./part2/part2.c -o part2.o
gcc -I../utils -c main.c -o main.o
gcc utils.o part1.o part2.o main.o -o main.program -lm