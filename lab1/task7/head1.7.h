#ifndef UNTITLED4_HEAD1_7_H
#define UNTITLED4_HEAD1_7_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


enum Errors
{
    OK,
    INVALID_INPUT,
    MEMORY_ERROR,
    FILE_OPEN_ERROR
};

enum Errors Read_file(FILE *file, char **word, int *len_word);
void Word_to_4(char **word, int len_word, int **result);
void Word_to_8(char **word, int len_word, int **result);
void To_lowercase(char **word, int len_word);
enum Errors Validate_input_r(int argc, char **argv);
enum Errors Validate_input_a(int argc, char **argv);

#endif