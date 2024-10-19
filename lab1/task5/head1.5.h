#ifndef UNTITLED4_HEAD1_5_H
#define UNTITLED4_HEAD1_5_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <string.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR
};

enum Errors Str_to_d(const char *str, double *result);
enum Errors Sum_a(double x, double eps, double *result);
enum Errors Sum_b(double x, double eps, double *result);
enum Errors Sum_c(double x, double eps, double *result);
enum Errors Sum_d(double x, double eps, double *result);

#endif