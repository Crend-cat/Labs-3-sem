#include "head2.1.h"

int main(int argc, char* argv[]){

    if(Validate(argc, argv) == INVALID_INPUT){
        printf("Error: incorrect input\n");
        return INVALID_INPUT;
    }

    switch(argv[1][1]){

        case 'l':{
            if(argc != 3){
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }
            printf("String lenght: %d\n", Strlen(argv[2]));
            break;
        }

        case 'r': {
            if (argc != 3) {
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            char *reverse_str = NULL;
            if (Reverse_str(argv[2], &reverse_str) != OK) {
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            printf("Reversed string: %s\n", reverse_str);
            free(reverse_str);
            break;
        }

        case 'u': {
            if (argc != 3) {
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            char *Str = NULL;
            if (Upp_str(argv[2], &Str) != OK) {
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            printf("New string: %s\n", Str);
            free(Str);
            break;
        }

        case 'n':{
            if(argc != 3){
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            char *new_str = NULL;
            if(Transform_str(argv[2], &new_str) != OK){
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }
            printf("New string: %s\n", new_str);
            free(new_str);
            break;
        }


        case 'c': {

            if(argc < 5){
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            int count_s = argc - 3;
            unsigned long seed;
            if (Str_to_ulint(argv[2], &seed) != OK || seed == 0) {
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            char *concat_str = NULL;
            if (Random_concat(argv, count_s, seed, &concat_str) != OK) {
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            printf("New string: %s\n", concat_str);
            free(concat_str);
            break;
        }

        default:
            printf("Error incorrect flag: %s\n", argv[1]);
            break;
    }

}