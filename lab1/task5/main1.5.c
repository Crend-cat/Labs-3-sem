#include "head1.5.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    double eps, x, result;
    int flag = 0;
    if (Str_to_d(argv[1], &eps) != OK || eps <= 0)
    {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }
    if (Str_to_d(argv[2], &x) != OK)
    {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    if (Sum_a(x, eps, &result) != OK)
    {
        printf("The value (a) could have been calculated incorrectly\n");
        flag = 1;
    }
    printf("a) %lf\n", result);

    if (Sum_b(x, eps, &result) != OK)
    {
        printf("The value (b) could have been calculated incorrectly\n");
        flag = 1;
    }
    printf("b) %lf\n", result);

    if (Sum_c(x, eps, &result) != OK)
    {
        printf("The value (c) could have been calculated incorrectly\n");
        flag = 1;
    }
    printf("c) %lf\n", result);

    if (Sum_d(x, eps, &result) != OK)
    {
        printf("The value (d) could have been calculated incorrectly\n");
        flag = 1;
    }
    printf("d) %lf\n", result);

    if (flag)
    {
        return INVALID_INPUT;
    }
    return 0;
}