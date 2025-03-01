#include "head1.6.h"

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

double F_a(double x)
{
    return log(1 + x) / x;
}

double F_b(double x)
{
    return exp(-x * x / 2);
}

double F_c(double x)
{
    return log(1 / (1 - x));
}

double F_d(double x)
{
    return pow(x, x);
}

void Right_rect(int n, double *result, double (*function)(double))
{
    double h = 1.0 / n, sum = 0; // h - длина основания прямоугольников (длина интервалов)
    for (int i = 1; i <= n; i++)
    {
        sum += function((double)i * h);
    }
    *result = sum * h;
}

void Left_rect(int n, double *result, double (*function)(double))
{
    double h = 1.0 / n, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += function((double)i * h);
    }
    *result = sum * h;
}

enum Errors Integral(double eps, double *result, double (*function)(double), void (*method)(int, double *, double (*)(double)))
{
    double prev = 0.0, cur = 0.0, n = 1; // предудущее / нынешнее значение интеграла
    do
    {
        if (INT_MAX / 2 < n)
            return INVALID_INPUT;
        n *= 2;
        prev = cur;
        method(n, &cur, function);

    } while (fabs(prev - cur) >= eps);

    *result = cur;
    return OK;
}