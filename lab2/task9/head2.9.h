#ifndef UNTITLED4_HEAD2_9_H
#define UNTITLED4_HEAD2_9_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <float.h>


enum Errors{
    OK,
    INVALID_INPUT,
    INVALID_BASE
};

enum Errors Has_finite_representation(int base, double *answer, int *len_ans, int count_nums, ...);

#endif