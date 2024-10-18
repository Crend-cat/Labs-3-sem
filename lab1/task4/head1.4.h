#ifndef UNTITLED4_HEAD1_4_H
#define UNTITLED4_HEAD1_4_H


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OPEN_FILE_ERROR
};

void Delete_n(FILE *in, FILE *out);
void Count_l(FILE *in, FILE *out);
void Count_s(FILE *in, FILE *out);
void Ascii(FILE *in, FILE *out);


#endif
