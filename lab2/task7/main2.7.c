#include "head2.7.h"


int main(int argc, char *argv[]){

    double answer;
    printf("\n\ttest 1\nx - 5.22, eps = 1e-7, left = 5.0, right = 5.5\nExepcted answer: 5.220000\n");

    switch (The_dichotomy(&answer, 5.0, 5.5, 1.e-7, f1)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("Answer: %lf\n", answer);
            break;
    }

    printf("\n\t test 2\nx^2 + 1, eps = 1e-7, left = 1.0, right = 3.0\nExepcted answer: No roots in this interval\n");

    switch (The_dichotomy(&answer, 1.0, 3.0, 1.e-7, f2)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
            break;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }

    printf("\n\ttest 3\n x^2 + 10*x - 4, eps = 1e-7, left = -10.0, right = -12.5\nExepcted answer: -10.385165\n");

    switch (The_dichotomy(&answer, -10.0, -12.5, 1.e-7, f3)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }
    printf("\n\ttest 4\nx^3 - x + 1, eps = 1e-7, left = -2.0, right = -1.0\nExepcted answer: -1.324718\n");

    switch (The_dichotomy(&answer, -2.0, -1.0, 1.e-7, f4)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
            break;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }
    printf("\n\ttest 5\nsin(x) - 1/x, eps = 1e-7, left = 1.0, right = 2.5\nExepcted answer: 1.114157\n");

    switch (The_dichotomy(&answer, 1.0, 2.5, 1.e-7, f5)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
            break;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }
    printf("\n\ttest 6\n x - 5.22, eps = 1e-7, left = 5.22, right = 5.22\nExepcted answer: 5.220000\n");

    switch (The_dichotomy(&answer, 5.22, 5.22, 1.e-7, f1)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }

    printf("\n\ttest 7\n 1.0, eps = 1e-7, left = 1.0, right = 2.0\nExepcted answer: No roots in this interval\n");
    switch (The_dichotomy(&answer, 1.0, 2.0, 1.e-7, f6)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }
        case NO_ROOTS:{
            printf("No roots in this interval\n");
            break;
        }
        case OK:
            printf("answer: %lf\n", answer);
            break;
    }

}