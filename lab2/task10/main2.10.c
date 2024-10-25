#include "head2.10.h"


double Calc_of_polynomial(double *coefs, double a, int max_degree)
{
    double multiplier = 1, answer = 0;
    int i;

    for (i = 0; i <= max_degree; ++i)
    {
        answer += multiplier * coefs[i];
        multiplier *= a;
    }
    return answer;
}


enum Errors Calc_coefs_polinom(double a, double **coefs, int degree, ...)
{
    if (degree < 0)
        return INVALID_INPUT;

    int i, j, cur_degree, multiply = 1;
    double *start_coefs = (double *)malloc((degree + 1) * sizeof(double));
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
        start_coefs[i] = va_arg(args, double);
    }
    va_end(args);

    cur_degree = degree;
    for (i = 0; i <= degree; ++i)
    {
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
    free(start_coefs);
    *coefs = new_coefs;
    return OK;
}