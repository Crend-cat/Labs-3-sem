#include "head2.9.h"

int main(){

    double answer[128];
    int len_ans = 0;

    switch(Has_finite_representation(10, answer, &len_ans, 3, 0.125, 0.5, 0.4)){

        case INVALID_INPUT:{
            printf("Error: incorrect input number(s)\n");
            return INVALID_INPUT;
        }
        case INVALID_BASE:{
            printf("Error: incorrect base\n");
            return INVALID_BASE;
        }
        case OK:{
            if(len_ans){
                printf("Answer: ");
                for(int i = 0; i < len_ans; ++i){
                    printf("%lf ", answer[i]);
                }
                printf("\n");
            }
            else{
                printf("There no such numbers\n");
            }
        }
    }
    return 0;
}