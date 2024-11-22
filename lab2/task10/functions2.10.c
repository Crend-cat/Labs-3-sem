#include "head2.10.h"

enum Errors Print_f(double *start_koefs, double *new_coefs, int degree, double a){
    if(start_koefs == NULL || new_coefs == NULL){
        return INVALID_INPUT;
    }

    for(int i = 0; i < 6; ++i){
        double f = 0.0, f_g = 0.0;


        for (int j = 0 ; j <= degree; ++j){ // f(x) = 1 + 2x + 3x^2
            f += start_koefs[j] * pow(i, j);
            f_g += new_coefs[j] * pow(i - a, j);
        }
        printf("f(%d) = %lf ", i, f);
        printf("g(%d) = %lf\n\n", i, f_g);
    }
    return OK;

}


double Calc_of_polynomial(double *coefs, double a, int max_degree)
{
    if(coefs == NULL){
        return INVALID_INPUT;
    }

    double multiplier = 1, answer = 0; // перем для степеней х, сумма
    int i;

    for (i = 0; i <= max_degree; ++i)
    {
        answer += multiplier * coefs[i];
        multiplier *= a;
    }
    return answer;
}


enum Errors Calc_coefs_polinom(double a, double **coefs, int degree, ...) // а - точка разложения
{
    if (degree < 0)
        return INVALID_INPUT;

    int i, j, flag = 1, cur_degree, multiply = 1;
    double *start_coefs = (double *)malloc((degree + 1) * sizeof(double));
    double *start_koefs = (double *)malloc((degree + 1) * sizeof(double));
    *coefs = NULL;
    if (!start_coefs)
        return INVALID_MEMORY;

    double *new_coefs = (double *)malloc((degree + 1) * sizeof(double));
    if (!new_coefs)
    {
        free(start_coefs);
        return INVALID_MEMORY;
    }

    va_list args;
    va_start(args, degree);
    for (i = 0; i <= degree; ++i)
    {
        double arg = va_arg(args, double);
        start_coefs[i] = arg;
        start_koefs[i] = arg;
    }
    va_end(args);

    cur_degree = degree; // сначала макс степень

    for (i = 0; i <= degree; ++i){

        new_coefs[i] = Calc_of_polynomial(start_coefs, a, cur_degree);

        if (i)
        {
            multiply *= i;
            new_coefs[i] /= (double)multiply;
        }
        cur_degree--;



        for (j = 0; j <= cur_degree; ++j)
        {
            start_coefs[j] = start_coefs[j + 1] * (j + 1);
        }
    }
    Print_f(start_koefs, new_coefs, degree, a);

    free(start_coefs);
    *coefs = new_coefs;
    return OK;
}