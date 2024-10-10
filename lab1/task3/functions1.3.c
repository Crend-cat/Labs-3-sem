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


void Swap(long double* q, long double* w){
    long double e = *q;
    *q = *w;
    *w = e;
}

int Duplicate(long double*** answer, int *count_arr, long double* arr, long double eps){
    int count = 0;
    for(int i = 0; i < *count_arr; ++i){
        for(int j = 0; j < 3; ++j){
            if(fabsl((*answer)[i][j] - arr[j] < eps)){
                count++;
            }
        }
        if(count == 3){ //если есть дубликат то 1
            return 1;

        }
        count = 0;
    }
    return 0;
}

enum Errors Perestan(long double*** answer, int left, int right, int *count, long double* arr, long double eps){//*count ков-во перестан, arr - массив с коэф
    enum Errors stat; //возв ерроры
    if(left == right){//сделали перестановку -> проверка -> записываем
        if(Duplicate(answer, count, arr, eps)){// 1 - есть дубликат
            return OK;
        }
        (*answer)[*count] = (long double *)malloc(3 * sizeof(long double));
        if((*answer)[*count] == NULL){
            return INVALID_MEMORY;
        }
        stat = OK;
        for(int i = 0; i < 3; ++i){
            (*answer)[*count][i] = arr[i]; //запись перестановки
        }
        (*count)++;
    }
    else{
        stat = OK;
        for(int j = left; j <= right; j++){
            Swap(arr + left, arr + j);
            stat = Perestan(answer, left + 1, right, count, arr, eps);
            Swap(arr + left, arr + j);//поменяли обратно
        }
    }
    return stat;

}

int Overflow_ld(long double* n1, long double* n2, long double epss) {
    long double answer = *n1 * *n2;
    return (answer - DBL_MAX <= epss && answer + DBL_MAX >= epss);
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

