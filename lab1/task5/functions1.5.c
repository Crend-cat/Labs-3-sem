#include "head1.5.h"

enum Errors Str_to_d(const char *str, double *result)
{
    int flag = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            if (flag)
                return INVALID_INPUT;
            flag = 1;
        }

        else if ((str[i] < '0' || str[i] > '9') && !(str[i] == '-' && i == 0))
            return INVALID_INPUT;
    }
    if (sscanf(str, "%lf", result) != 1)
        return INVALID_INPUT;
    return OK;
}

enum Errors Sum_a(double x, double eps, double *result)
{
    int n = 0;
    *result = 0;
    double cur = 1;
    while (fabs(cur) >= eps)
    {
        (*result) += cur;
        if (n == INT_MAX)
            return INVALID_INPUT;
        n++;
        cur *= x / n;
    }
    return OK;
}

enum Errors Sum_b(double x, double eps, double *result)
{
    int n = 0;
    *result = 0;
    double cur = 1;
    while (fabs(cur) >= eps)
    {
        (*result) += cur;
        if (n == INT_MAX)
            return INVALID_INPUT;
        n++;
        cur *= (-1.0) * x * x / (2 * n * (2 * n - 1.0));
    }
    return OK;
}

enum Errors Sum_c(double x, double eps, double *result)
{
    int n = 0;
    *result = 0;
    double cur = 1;
    while (fabs(cur) >= eps)
    {
        (*result) += cur;
        if (n == INT_MAX)
            return INVALID_INPUT;
        n++;
        cur *= (x * x * 9.0 * n * n) / (9 * n * (n - 1) + 2);
        if (cur + eps >= 1.0)
        {
            *result = INFINITY;
            return OK;
        }
    }
    return OK;
}

enum Errors Sum_d(double x, double eps, double *result)
{
    int n = 1;
    *result = 0;
    double cur = -1.0 * x * x / 2.0;
    while (fabs(cur) >= eps)
    {
        (*result) += cur;
        if (n == INT_MAX)
            return INVALID_INPUT;
        n++;
        cur *= (-1.0 * x * x * (2.0 * n - 1.0)) / (2.0 * n);
    }
    return OK;
}