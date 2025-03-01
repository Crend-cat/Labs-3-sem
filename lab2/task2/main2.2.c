#include "head2.2.h"
//  gcc main2.2.c functions2.2.c -std=c99 -Wall -o task2.2 -lm

int main(){
    double answer;

    switch(Sr_geometric(&answer, 4, 1.2, 1.3, 1.8, 5.5)){

        case INVALID_INPUT:{
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }

        case OVERFLOW_ERROR:{
            printf("Overflow error\n");
            return OVERFLOW_ERROR;
        }

        case OK:{
            printf("Geometric mean: %lf\n", answer);
            break;
        }

        default:
            break;

    }


    switch(Fast_pow(2, 5, &answer)){

        case OVERFLOW_ERROR:{
            printf("Error: incorrect input\n");
            return OVERFLOW_ERROR;
        }

        case OK:{
            printf("Fast pow: %lf\n", answer);
            break;
        }

        default:
            break;
    }

    return OK;

}