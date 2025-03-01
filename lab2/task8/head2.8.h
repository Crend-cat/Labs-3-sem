#ifndef UNTITLED4_HEAD2_3_H
#define UNTITLED4_HEAD2_3_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

enum Errors{
    OK,
    INVALID_INPUT,
    INVALID_MEMORY,
};

enum Errors sum_any_base_all_numbers(char **result, int base, int count_numbers, ...);
enum Errors validate_base(char *number, int base, int len);
void str_reverse(char *str, int len);
void sum_any_base_two_numbers(char *number1_res, char *number2, int base, int *len_res, int len_number);
#endif