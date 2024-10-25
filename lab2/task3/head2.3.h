#ifndef UNTITLED4_HEAD2_3_H
#define UNTITLED4_HEAD2_3_H


#include "stdio.h"
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>


enum Errors{
    OK,
    INVALID_INPUT,
    INVALID_MEMORY,
    OPEN_FILE_ERROR
};

typedef struct Found{
    char *file_name;
    int n_line;
    int n_char;
    struct Fount *next;
} Found;

enum Errors Search_str(char *substr, int count_files, Found **answer, ...);

#endif
