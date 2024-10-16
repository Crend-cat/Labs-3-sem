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


    (*answer)[0][0] = q; (*answer)[0][1] = w; (*answer)[0][2] = e;  // 1 2 3
    (*answer)[1][0] = q; (*answer)[1][1] = e; (*answer)[1][2] = w;  // 1 3 2
    (*answer)[2][0] = w; (*answer)[2][1] = q; (*answer)[2][2] = e;  // 2 1 3
    (*answer)[3][0] = w; (*answer)[3][1] = e; (*answer)[3][2] = q;  // 2 3 1
    (*answer)[4][0] = e; (*answer)[4][1] = q; (*answer)[4][2] = w;  // 3 1 2
    (*answer)[5][0] = e; (*answer)[5][1] = w; (*answer)[5][2] = q;  // 3 2 1
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

