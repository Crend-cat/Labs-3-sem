#ifndef UNTITLED4_HEAD2_4_H
#define UNTITLED4_HEAD2_4_H


#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

#define Capacity 100
#define Eps 1e10

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR
};

typedef struct Point{
    double x;
    double y;
}point;

double Find_component(point a, point b, point c);
int Is_convex(int count_corners, ...);
enum Errors Find_polynom(double *ans, double x, int n, ...);
enum Errors String_to_uint(const char *str, unsigned long *result, int base);
void Convert_to_xbase(unsigned long num, int base, char *result);
enum Errors Pow_base(char *number, int base);
enum Errors Sum_base(char *number_1, char *number_2, int base, unsigned long *res);
enum Errors Kaprekar(int count_numbers, char *ans, int base, ...);

#endif