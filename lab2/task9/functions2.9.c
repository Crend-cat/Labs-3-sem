#include "head2.9.h"

unsigned long long Nod(unsigned long long a, unsigned long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if(a > 0){
        return a;
    }
    else{
        return b;
    }
}

int Has_representation(int base, double num){
    unsigned long long numerator, denominator = 1;
    int i;

    while(fabs(num - floor(num)) > DBL_EPSILON && ULLONG_MAX / 10 >= denominator){
        num *= 10;
        denominator *= 10;
    }

    numerator = (unsigned long long)num; // num из double в unsigned long long
    denominator = denominator / Nod(numerator, denominator);
    i = 2;

    if((denominator % 2 == 0) && (base % 2 != 0)){
        return 0;
    }

    while(denominator % 2 == 0){
        denominator = denominator / 2;
    }

    for(i = 3; i < base; i +=2){
        if(denominator % i == 0 && base % i != 0){
            return 0;
        }
        while(denominator % i == 0){
            denominator = denominator / i;
        }
    }
    if(denominator != 1){
        return 0;
    }
    return 1;
}

enum Errors Has_finite_representation(int base, double *answer, int *len_ans, int count_nums, ...){

    if(base < 2){
        return INVALID_BASE;
    }

    enum Errors stat = OK;
    double num;

    va_list args;
    va_start(args, count_nums);

    for(int i = 0; i < count_nums; ++i){
        num = va_arg(args, double);
        if(num > 1.0 - DBL_EPSILON || num < DBL_EPSILON){
            stat = INVALID_INPUT;
            continue;
        }
        if(Has_representation(base, num)){
            answer[(*len_ans)++] = num;
        }
    }
    va_end(args);
    return stat;
}