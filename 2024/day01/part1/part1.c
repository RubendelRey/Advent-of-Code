#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"

int part1(int* list1, int* list2, int array_length) {
    sort_array(list1, array_length);
    sort_array(list2, array_length);

    int difference = 0;

    for (int i = 0; i < array_length; i++) {
        difference += abs(list1[i] - list2[i]);
    }

    return difference;
}