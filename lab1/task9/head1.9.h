#ifndef UNTITLED4_HEAD1_4_H
#define UNTITLED4_HEAD1_4_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

enum Errors
{
    OK,
    INVALID_INPUT,
    INVALID_MEMORY
};

enum Errors Stroka_to_lint(const char *str, long int * answer, int base);

enum Errors Arr_gen(long int begin, long int end, long int ** answer, int size);
void Swap_min_max(long int **answer_arr, int size);

enum Errors Arr_gen2(int begin_2, int end_1, short ** answer_arr_2, int size_2);
enum Errors Arr_gen_and_find_closest(short ** arr_a, int size_a, short ** arr_b, int size_b, short ** arr_c);
void bubble_sort(short** arr, int size);
short find_closest(short ** arr, int size, short number);

#endif