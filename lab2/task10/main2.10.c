#include "head2.10.h"

int main()
{
    double *coefs = NULL;
    int i, degree;
    double a;

    degree = 2; // степнь многочлена
    a = 2.0; // точка разложения

    switch (Calc_coefs_polinom(a, &coefs, degree, 1., 2., 3.))
    {
        case INVALID_MEMORY:
            printf("Error with memory\n");
            return INVALID_MEMORY;

        case INVALID_INPUT:
            printf("Error: degree < 0\n");
            return INVALID_INPUT;

        case OK:
            puts("Coefs of g(x-a):");
            for (i = 0; i <= degree; i++)
            {
                printf("g_%d = %lf\n", i, coefs[i]);
            }
            free(coefs);
    }
}