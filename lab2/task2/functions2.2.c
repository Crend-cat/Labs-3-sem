#include "head2.2.h"

enum Errors Sr_geometric(double *answer, int count, ...){

    if(count < 1){
        return INVALID_INPUT;
    }

    va_list args;
    va_start(args, count);
    *answer = 1;
    double cur;
    for(int i = 0; i < count; ++i){
        cur = va_arg(args, double);
        if(cur < 0){
            va_end(args);
            return INVALID_INPUT;
        }

        *answer *= cur;
        if(Overflow(*answer)){
            va_end(args);
            return OVERFLOW_ERROR;
        }
    }
    *answer = pow(*answer, 1.0 / count);
    va_end(args);
    return OK;
}


enum Errors Fast_pow(double base, int degree, double *answer){

    enum Errors status = OK;

    if(degree < 0){
        return Fast_pow(1.0 / base, -degree, answer);
    }

    else if(!degree){
        *answer = 1.0;
        status = OK;
    }

    else if(degree % 2 != 0){ // если нечетная степ
        status = Fast_pow(base, degree - 1, answer);
        *answer *= base;
        return Overflow(*answer);
    }
    else{

        status = Fast_pow(base, degree / 2, answer); // четная
        *answer *= *answer;
        return Overflow(*answer);
    }

    return status;

}

enum Errors Overflow(double x){
    if(isnan(x) || isinf(x)){ // is not a number / является ли бесконечностью
        return OVERFLOW_ERROR;
    }
    return OK;
}