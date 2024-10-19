#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "stdio.h"
#include <errno.h>
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
enum Errors Integral(double eps, double *result, double (*function)(double), void (*method)(int, double *, double (*)(double)));
double F_a(double x);
double F_b(double x);
double F_c(double x);
double F_d(double x);
void Left_rect(int n, double *result, double (*function)(double));
void Right_rect(int n, double *result, double (*function)(double));

#endif