#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"

int part2(int* list1, int* list2, int array_length) {
    int sum = 0;

    for (int i = 0; i < array_length; i++) {
        int counter = 0;
        for (int j = 0; j < array_length; j++) {
            if (list1[i] == list2[j]) {
                counter++;
            }
        }
        sum += list1[i] * counter;
    }

    return sum;
}