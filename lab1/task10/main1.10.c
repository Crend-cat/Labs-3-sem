#include "head1.10.h"

int main(int argc, char *argv[]){

    int base;
    if(!scanf("%d", &base) || base < 2 || base > 36){
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    char *num_arr = malloc( 70 * sizeof(char ));
    if(num_arr == NULL){
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }




    long long num_10base;
    long long max_num = LLONG_MIN;

    while(scanf("%69s", num_arr)){
        if(!strcmp(num_arr, "Stop")) {
            if (max_num == LLONG_MIN) {
                free(num_arr);
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            char *num_new_base = malloc(70 * sizeof(char));
            if (num_new_base == NULL) {
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            int bases[] = {base, 9, 18, 27, 36};
            for (int i = 0; i < 5; i++) {

                To_xbase(max_num, bases[i], num_new_base);
                printf("In %d: %s\n", bases[i], num_new_base);
            }

            free(num_new_base);
            break;

        }
        else{
            if(Str_to_llint(num_arr, &num_10base, base) == INVALID_INPUT){
                free(num_arr);
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }
            if(llabs(num_10base) > llabs(max_num)){
                max_num = num_10base;
            }

        }

    }
    free(num_arr);
    return OK;

}