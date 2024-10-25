#ifndef UNTITLED4_HEAD2_2_H
#define UNTITLED4_HEAD2_2_H


#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR
};


enum Errors Sr_geometric(double *answer, int count, ...);

enum Errors Fast_pow(double base, int degree, double *answer);
enum Errors Overflow(double x);

#endif
