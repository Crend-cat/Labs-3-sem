#include "head1.2.h"
// gcc main1.2.c functions1.2.c -std=c99 -Wall -o task1.2 -lm
int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Error, invalid input\n");
        return INVALID_INPUT;
    }

    double eps;

    if (Str_to_double(argv[1], &eps) != OK || eps <= 0.0)
    {
        printf("Error, invalid input\n");
        return INVALID_INPUT;
    }

    double answers[15];
    char types[5][10] = {"e", "pi", "ln2", "sqrt(2)", "y"};

    e_limit(eps, &answers[0]);
    pi_limit(eps, &answers[1]);
    ln2_limit(eps, &answers[2]);
    sqrt_limit(eps, &answers[3]);
    y_limit(eps, &answers[4]);

    e_row(eps, &answers[5]);
    pi_row(eps, &answers[6]);
    ln2_row(eps, &answers[7]);
    sqrt_row(eps, &answers[8]);
    y_row(eps, &answers[9]);

    e_equation(eps, &answers[10]);
    pi_equation(eps, &answers[11]);
    ln2_equation(eps, &answers[12]);
    sqrt_equation(eps, &answers[13]);
    y_equation(eps, &answers[14]);

    printf("\nLimit:\n");
    for (int i = 0; i < 5; i++)
    {
        if (answers[i] != INFINITY)
        {
            printf("%s: %lf\n", types[i], answers[i]);
        }
    }
    printf("\nRow:\n");
    for (int i = 5; i < 10; i++)
    {
        if (answers[i] != INFINITY)
        {
            printf("%s: %lf\n", types[i % 5], answers[i]);
        }
    }
    printf("\nEquation:\n");
    for (int i = 10; i < 15; i++)
    {
        if (answers[i] != INFINITY)
        {
            printf("%s: %lf\n", types[i % 5], answers[i]);
        }
    }
    return 0;
}