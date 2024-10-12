#ifndef UNTITLED4_HEAD1_3_H
#define UNTITLED4_HEAD1_3_H


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR
};

enum Errors Stroka_to_lint(const char *str, long int * answer, int base);
enum Errors Stroka_to_ldouble(const char *str, long double * answer);

enum Errors GeneratePermutation(long double*** answer, int a, int b, int c);

enum Errors Treygolnic(long double epss, long double a1, long double a2, long double a3, int* ded);
int Overflow_ld(long double* n1, long double* n2, long double epss);

#endif
