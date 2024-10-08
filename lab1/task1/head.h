#ifndef UNTITLED4_HEAD_H
#define UNTITLED4_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>

enum Errors{
    OK,
    INVALID_MEMORY,
    INVALID_INPUT,
};

enum Errors Stroka_to_chisl(const char *str, long int * answer, int base);

enum Errors Nat_numbers_arr(long int number, int** answer, int* size_arr_answer_h);
int Isprime(long int n);
enum Errors Ten_to_sixteen(long int n, char** answer_s, int* size_arr_answer_s);
enum Errors Table_of_degrees(long long int*** answer, long int number);
enum Errors Sum_of_numbers(long int number, long long int * answer);
enum Errors Factorial_number(long int number, unsigned long long int* answer);


#endif