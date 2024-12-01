#ifndef UTILS_H
#define UTILS_H

char* read_file(const char *file_name);
char** split_lines(const char* input_string);
int count_lines(const char* input_string);
char** split_by_separator(const char* input_string, const char* separator, int count);
void sort_array(int* array, int size);
int char_array_to_int(const char* char_array, int length);

#endif