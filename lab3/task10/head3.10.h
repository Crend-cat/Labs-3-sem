//
// Created by User on 08.11.2024.
//

#ifndef UNTITLED4_HEAD3_10_H
#define UNTITLED4_HEAD3_10_H


#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
    OVERFLOW_ERROR,
    OPEN_FILE_ERROR
};

typedef struct Node
{
    char data;
    struct Node *son, *brother, *prev;
} Node;

enum Errors Build_tree(FILE *input, FILE *output);
void Init_tree(Node *root);
void Print_tree(Node *root, int level, FILE *output);
void Delete_tree(Node *root);
enum Errors Validate_input(int argc, char **argv);

#endif