#include <stdio.h>
#include <stdlib.h>
#include "./part1/part1.h"
#include "./part2/part2.h"
#include "../utils/utils.h"

#define SEPARATOR "   "

int main() {
    //Read input
    char* input = read_file("input.txt");
    char** lines = split_lines(input);
    
    //Create arrays
    int lists_length = count_lines(input);
    int* list1 = (int*)malloc(lists_length * sizeof(int));
    int* list2 = (int*)malloc(lists_length * sizeof(int));
    
    //Fill arrays
    for (int i = 0; i < lists_length; i++) {
        char** numbers = split_by_separator(lines[i], SEPARATOR, 12);
        list1[i] = char_array_to_int(numbers[0], 5);
        list2[i] = char_array_to_int(numbers[1], 5);
    }

    //Print solutions
    printf("Part 1 solution: %d\n", part1(list1, list2, lists_length));
    printf("Part 2 solution: %d\n", part2(list1, list2, lists_length));
}