#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define Capacity 70

enum Errors
{
    OK,
    INVALID_INPUT,
    INVALID_MEMORY,
    FILE_OPEN_ERROR
};

enum Errors Read_num(FILE *file, char *word, int *len_word, int *base, int *minus);
enum Errors Convert(char *const word, int base, long long *result);
enum Errors Validate_input(int argc, char **argv);

#endif