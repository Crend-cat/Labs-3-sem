#ifndef UNTITLED4_HEAD2_3_H
#define UNTITLED4_HEAD2_3_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


 enum Errors{
    OK,
    WRONG_INPUT_ERROR,
    MEMORY_ERROR,
    FILE_OPEN_ERROR
};

int Strlen(const char * s);
void ComputeLPSArray(char* pattern, int M, int* lps);
char* KMPsearch(char* pattern, char* text);
enum Errors Files_read(char *substring, int count, ...);
enum Errors Find_substr(char *substring, FILE* file, char *file_name);

#endif
