#include "head2.7.h"

enum Errors The_dichotomy(double *answer, double left, double right, double eps, double (*f)(double)){

    if(eps <= 0.0){ // . тк работаем с double 0-целое 0.-с плавающей точкой
        return INVALID_INPUT;
    }


    if( f(left) * f(right) > 0.0){
        return NO_ROOTS;
    }

    double mid;
    while(fabs(right - left) >= eps){
        mid = (left + right) / 2;
        if(f(left) * f(mid) <= 0.0){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    *answer = (left + right) / 2; // просто берем середину тк эпсилон позволяет это сделать
    return OK;
}


double f1(double x)
{
    return x - 5.22;
}

double f2(double x)
{
    return x * x + 1;
}

double f3(double x)
{
    return x * x + 10 * x - 4;
}

double f4(double x)
{
    return x * x * x - x + 1;
}

double f5(double x)
{
    return sin(x) - 1/x;
}

double f6(double x)
{
    return 1.0;
}
