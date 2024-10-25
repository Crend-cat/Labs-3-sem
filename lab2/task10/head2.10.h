#ifndef UNTITLED4_HEAD2_10_H
#define UNTITLED4_HEAD2_10_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR
};

enum Errors Calc_coefs_polinom(double a, double **coefs, int degree, ...);

#endif
