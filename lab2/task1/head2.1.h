#ifndef UNTITLED4_HEAD2_1_H // против повторного включения
#define UNTITLED4_HEAD2_1_H

#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
};

enum Errors Validate(int argc, char *argv[]);

enum Errors Strlen(const char *str);
enum Errors Reverse_str(const char *str, char **r_str);
enum Errors Upp_str(const char *str, char **Str);
enum Errors Transform_str(const char *str, char **n_str);

enum Errors Str_to_ulint(const char *str, unsigned long *answer);
enum Errors Random_concat(char **argv, int count, unsigned long seed, char **answer);
void Concat(const char *str, char *answer);



#endif
