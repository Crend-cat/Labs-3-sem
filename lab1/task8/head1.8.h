#ifndef UNTITLED4_HEAD1_8_H
#define UNTITLED4_HEAD1_8_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


#define Capacity 50

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OPEN_FILE_ERROR
};

enum Errors Read_num(FILE *file, char *s, int *len, int *base);
enum Errors Base_to_10(const char *const s, int base, long long *answer);

#endif
