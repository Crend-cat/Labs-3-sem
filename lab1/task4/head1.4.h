#ifndef UNTITLED4_HEAD1_4_H
#define UNTITLED4_HEAD1_4_H


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include <ctype.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OPEN_FILE_ERROR
};

int Compare_paths(const char *path1, const char *path2);
enum Errors Delete_a(const char *in, const char *out);
enum Errors Count_l(const char *in, const char *out);
enum Errors Count_s(const char *in, const char *out);
enum Errors Ascii(const char *in, const char *out);


#endif
