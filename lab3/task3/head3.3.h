#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

#define EPS 1e-10

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR,
    OPEN_FILE_ERROR
};

typedef struct Employee
{
    unsigned int id;
    char name[64];
    char surname[64];
    double money;
} Employee;


enum Errors Validate_input(int argc, char **argv);
enum Errors Read_file(FILE *in,Employee **out_data, int *size_data);
int Sort_a(const void *a, const void *b);
int Sort_d(const void *a, const void *b);

#endif