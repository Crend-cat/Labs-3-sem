#include "head1.6.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    double eps;
    if (Str_to_d(argv[1], &eps) != OK || eps <= 0.0)
    {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    double result;
    if (Integral(eps, &result, F_a, Right_rect))
    {
        printf("The epsilon is too high\n");
        return INVALID_INPUT;
    }

    printf("%lf\n", result);
    if (Integral(eps, &result, F_b, Right_rect))
    {
        printf("The epsilon is too high\n");
        return INVALID_INPUT;
    }
    printf("%lf\n", result);
    if (Integral(eps, &result, F_c, Left_rect))
    {
        printf("The epsilon is too high\n");
        return INVALID_INPUT;
    }
    printf("%lf\n", result);
    if (Integral(eps, &result, F_d, Right_rect))
    {
        printf("The epsilon is too high\n");
        return INVALID_INPUT;
    }
    printf("%lf\n", result);
}