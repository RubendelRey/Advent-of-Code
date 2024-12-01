#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* read_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char*)malloc(fileSize + 1);
    if (content == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';

    fclose(file);
    return content;
}

char** split_lines(const char* input_string) {
    return split_by_separator(input_string, "\n", count_lines(input_string));
}

int count_lines(const char* input_string) {
    int count = 0;
    const char* temp = input_string;

    while (*temp) {
        if (*temp == '\n') {
            count++;
        }
        temp++;
    }

    if (temp != input_string && *(temp - 1) != '\n') {
        count++;
    }

    return count;
}

char** split_by_separator(const char* input_string, const char* separator, int count) {
    char* str_copy = strdup(input_string);
    char* token = strtok(str_copy, separator);
    int token_count = 0;
    char** tokens = NULL;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (token_count + 1));
        tokens[token_count] = strdup(token);
        token_count++;
        token = strtok(NULL, separator);
    }

    count = token_count;
    free(str_copy);
    return tokens;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); 
}

void sort_array(int* array, int size) { 
    qsort(array, size, sizeof(int), compare);
}

int char_array_to_int(const char* char_array, int length) {
    int number = 0;

    for (int i = 0; i < length; i++) {
        number += ((int)char_array[i] - 48) * pow(10, length - i - 1);
    }

    return number;
}
