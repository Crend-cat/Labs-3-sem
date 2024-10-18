#ifndef UNTITLED4_HEAD1_10_H
#define UNTITLED4_HEAD1_10_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
};

void To_xbase(long long num, int base, char *result);
enum Errors Str_to_llint(const char *str, long long *answer, int base);


#endif
