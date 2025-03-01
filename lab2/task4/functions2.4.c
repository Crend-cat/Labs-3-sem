#include "head2.4.h"

double Find_component(point a, point b, point c)
{
    double answeeer = a.x * b.y + a.y * c.x + b.x * c.y - c.x * b.y - b.x * a.y - a.x * c.y;
    return answeeer;
}

int Is_convex(int count_corners, ...)
{
    if (count_corners < 0)
        return 0;
    if (count_corners <= 3)
        return 1;

    point first, second, s1, s2, s3;
    int component;
    va_list args;
    va_start(args, count_corners);
    first = va_arg(args, point);
    second = va_arg(args, point);
    s3 = va_arg(args, point);
    component = (Find_component(first, second, s3) - Eps > 0.0) ? 1 : 0;

    s1 = first;
    s2 = second;
    for (int i = 0; i < count_corners - 3; i++)
    {
        s1 = s2;
        s2 = s3;
        s3 = va_arg(args, point);


        if (((Find_component(s1, s2, s3) - Eps > 0.0) ? 1 : 0) != component)
        {
            va_end(args);
            return 0;
        }
    }


    if (((Find_component(s2, s3, first) - Eps > 0.0) ? 1 : 0) != component)
    {
        return 0;
        va_end(args);
    }
    if (((Find_component(s3, first, second) - Eps > 0.0) ? 1 : 0) != component)
    {
        return 0;
        va_end(args);
    }
    return 1;
}

enum Errors Find_polynom(double *ans, double x, int n, ...)
{
    if(ans == NULL){
        return INVALID_INPUT;
    }


    *ans = 0;
    if (n < 0)
        return INVALID_INPUT;

    va_list coef;
    va_start(coef, n);

    for (int i = 0; i <= n; ++i)
    {
        // 3x^3+5x^2+7x+4
        // (((0*x + 3) * x + 5) * x + 7) * x + 4

        if(i == 0){
            *ans = va_arg(coef, double) * x;
        }
        else {
            *ans = (*ans + va_arg(coef, double)) * x;
        }

        //*ans += pow(x, i) * va_arg(coef, double);
        if (isinf(*ans) || isnan(*ans))
        {
            va_end(coef);
            return OVERFLOW_ERROR;
        }
    }
    //*ans /= x;
    va_end(coef);
    return OK;
}

enum Errors String_to_uint(const char *str, unsigned long *answer, int base)
{
    if(str == NULL || answer == NULL){
        return INVALID_INPUT;
    }

    if (str[0] == '-')
        return INVALID_INPUT;
    char *endinp;
    *answer = strtoul(str, &endinp, base);
    if (*answer == ULONG_MAX)
        return INVALID_INPUT;
    if (*endinp != '\0')
        return INVALID_INPUT;
    return OK;
}

void Convert_to_xbase(unsigned long num, int base, char *answer)
{

    int i, flag_minus = 0;
    char temp;
    int len_answer = 0;
    if (num < 0)
    {
        num = llabs(num);
        flag_minus = 1;
    }
    while (num)
    {
        answer[len_answer++] = ((num % base > 9) ? (num % base - 10 + 'A') : (num % base + '0'));
        num /= base;
    }
    if (flag_minus)
        answer[len_answer++] = '-';
    for (i = 0; i < len_answer / 2; i++)
    {
        temp = answer[i];
        answer[i] = answer[len_answer - 1 - i];
        answer[len_answer - 1 - i] = temp;
    }
    answer[len_answer] = '\0';
}

enum Errors Pow_base(char *number, int base)
{
    if(number == NULL){
        return INVALID_INPUT;
    }

    long int num_10;
    if (String_to_uint(number, &num_10, base) != OK || ULONG_MAX / num_10 < num_10)
        return INVALID_INPUT;
    num_10 *= num_10;
    Convert_to_xbase(num_10, base, number);
    return OK;
}

enum Errors Sum_base(char *number_1, char *number_2, int base, unsigned long *ans)
{
    if(number_1 == NULL || number_2 == NULL || ans == NULL){
        return INVALID_INPUT;
    }

    long int a_10, b_10;
    if (String_to_uint(number_1, &a_10, base) != OK)
        return INVALID_INPUT;
    if (String_to_uint(number_2, &b_10, base) != OK)
        return INVALID_INPUT;
    if (a_10 == 0 || b_10 == 0)
    {
        *ans = 0;
        return OK;
    }
    if (ULONG_MAX - b_10 < a_10)
        return INVALID_INPUT;
    *ans = a_10 + b_10;
    return OK;
}

enum Errors Kaprekar(int count_numbers, char *ans, int base, ...)
{
    if(ans == NULL){
        return INVALID_INPUT;
    }

    if (base < 2 || base > 36)
        return INVALID_INPUT;
    va_list args;
    va_start(args, base);
    char number[Capacity], left[Capacity];
    int len, flag = 0;
    unsigned long x, sum;

    for (int i = 0; i < count_numbers; i++)
    {
        strcpy(number, va_arg(args, char *));
        if (String_to_uint(number, &x, base) != OK || Pow_base(number, base) != OK || ULONG_MAX / x < x)
        {
            va_end(args);
            return INVALID_INPUT;
        }

        len = strlen(number);
        flag = 0;
        if (len == 1 && number[0] == '1')
            flag = 1;
        for (int j = 1; j < len; j++) // разбиваем число на 2 части и постепенно увеличиваем левую
        {
            strncpy(left, number, j);
            left[j] = '\0';
            if (Sum_base(left, &(number[j]), base, &sum) != OK)
            {
                va_end(args);
                return INVALID_INPUT;
            }
            if (sum == x) // х - исходное число
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {


            ans[i] = '-';
        }
        else
        {

            ans[i] = '+';
        }
    }
    va_end(args);
    return OK;
}