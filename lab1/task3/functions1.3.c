#include "head1.3.h"

enum Errors Stroka_to_lint(const char *str, long int * answer, int base){
    char *endptr;
    *answer = strtol(str, &endptr, base);
    if(*answer == LONG_MAX || *answer == LONG_MIN){
        return INVALID_INPUT;
    }
    else if(endptr == str){ //ниче не преобразовали
        return INVALID_INPUT;
    }
    else if(*endptr != '\0'){ //чето осталось
        return INVALID_INPUT;
    }
    else{
        return OK;
    }
}

enum Errors Stroka_to_ldouble(const char *str, long double * answer){
    char *endptr;
    *answer = strtold(str, &endptr);
    if(*answer == HUGE_VAL || *answer == -HUGE_VAL){
        return INVALID_INPUT;
    }
    else if(endptr == str){ //ниче не преобразовали
        return INVALID_INPUT;
    }
    else if(*endptr != '\0'){ //чето осталось
        return INVALID_INPUT;
    }
    else{
        return OK;
    }
}


enum Errors GeneratePermutation(long double*** answer, int q, int w, int e){
    *answer = (long double**)malloc(6 * sizeof(long double*));
    if (*answer == NULL) {
        return INVALID_MEMORY;
    }

    for (int i = 0; i < 6; i++) {
        (*answer)[i] = (long double*)malloc(3 * sizeof(long double));
        if ((*answer)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*answer)[j]);
            }
            free(*answer);
            return INVALID_MEMORY;
        }
    }

    long double coefficients[3] = {q, w, e};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && i != k && j != k) { // Проверка на уникальность индексов
                    (*answer)[index][0] = coefficients[i];
                    (*answer)[index][1] = coefficients[j];
                    (*answer)[index][2] = coefficients[k];
                    index++;
                }
            }
        }
    }

    return OK;
}

int Overflow_ld(long double* n1, long double* n2, long double epss) {
    long double answer = *n1 * *n2;
    return (answer - LDBL_MAX <= epss && answer + LDBL_MAX >= epss);
}


enum Errors Treygolnic(long double epss, long double a1, long double a2, long double a3, int * ded){
    if(!Overflow_ld(&a1, &a1, epss) || !Overflow_ld(&a2, &a2, epss) ||!Overflow_ld(&a3, &a3, epss)){
        return OVERFLOW_ERROR;
    }
    if(a1 <= epss || a2 <= epss || a3 <= epss){
        return INVALID_INPUT;
    }

    if(fabsl(a1 * a1 + a2 * a2 - a3 * a3) <= epss || fabsl(a1 * a1 + a3 * a3 - a2 * a2) <= epss ||
    fabsl(a2 * a2 + a3 * a3 - a1 * a1) <= epss){
        *ded = 1;
    }
    else{
        *ded = 0;
    }
    return OK;
}

