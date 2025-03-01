#ifndef UNTITLED4_HEAD3_1_H
#define UNTITLED4_HEAD3_1_H

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


int Add( int x, int y);
int Minus(int x);
enum Errors To_xbase(int num, int a, char *answer, int *size);
void Print_answer( char *answer, int size);

#endif
