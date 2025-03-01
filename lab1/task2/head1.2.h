#ifndef UNTITLED4_HEAD1_2_H
#define UNTITLED4_HEAD1_2_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <float.h>

#define PI 3.141592653589793

enum Errors
{
    OK,
    INVALID_INPUT,
    OVERFLOW_ERROR
};

enum Errors Str_to_double(const char *str, double *result);
enum Errors e_limit(double eps, double *result);
enum Errors pi_limit(double eps, double *result);
enum Errors ln2_limit(double eps, double *result);
enum Errors sqrt_limit(double eps, double *result);
enum Errors e_row(double eps, double *result);
enum Errors pi_row(double eps, double *result);
enum Errors ln2_row(double eps, double *result);
enum Errors sqrt_row(double eps, double *result);
enum Errors e_equation(double eps, double *result);
enum Errors pi_equation(double eps, double *result);
enum Errors ln2_equation(double eps, double *result);
enum Errors sqrt_equation(double eps, double *result);
enum Errors y_limit(double eps, double *result);
enum Errors y_row(double eps, double *result);
enum Errors y_equation(double eps, double *result);

#endif