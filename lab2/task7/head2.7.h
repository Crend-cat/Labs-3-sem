#ifndef UNTITLED4_HEAD2_7_H
#define UNTITLED4_HEAD2_7_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

enum Errors{
    OK,
    INVALID_INPUT,
    NO_ROOTS
};


enum Errors The_dichotomy(double *answer, double left, double right, double eps, double (*f)(double));

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);


#endif
