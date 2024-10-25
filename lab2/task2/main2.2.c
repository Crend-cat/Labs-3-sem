#include "head2.2.h"

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

        case INVALID_MEMORY:
            break;
    }


    switch(Fast_pow(2, 10, &answer)){

        case OVERFLOW_ERROR:{
            printf("Error: incorrect input\n");
            return OVERFLOW_ERROR;
        }

        case OK:{
            printf("Fast pow: %lf\n", answer);
            break;
        }

        case INVALID_MEMORY:
            break;

        case INVALID_INPUT:
            break;
    }

    return OK;

}