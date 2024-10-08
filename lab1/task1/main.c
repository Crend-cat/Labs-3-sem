#include "head.h"

int main(int argc, char* argv[]) { // кол-во арг и их массив ( 1 в массиве это имя программы )
    if(argc != 3 ){
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }
    if( !((argv[1][0] == '-' || argv[1][0] == '/') && argv[1][2] == '\0') ) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

        long int number = 0;
        if (Stroka_to_chisl(argv[2], &number, 10) != OK) {
            printf("Error: uncorrect input\n");
            return INVALID_INPUT;
        }

        switch (argv[1][1]) { // задаем что будем чекать

            case 'h': {
                int *answer_h = NULL;
                int size_arr_answer_h = 0;
                enum Errors status_h = Nat_numbers_arr(number, &answer_h, &size_arr_answer_h);

                if (status_h == INVALID_MEMORY) {
                    printf("Error with memore\n");
                    if (answer_h != NULL) {
                        free(answer_h);
                        return INVALID_MEMORY;
                    }
                } else if (status_h == INVALID_INPUT) {
                    printf("Error: devision by zero\n");
                    if (answer_h != NULL) {
                        free(answer_h);
                        return INVALID_INPUT;
                    }
                }
                if (size_arr_answer_h == 0) {
                    printf("No numbers\n");
                } else {
                    printf("Numbers:\n");
                    for (int i = 0; i < size_arr_answer_h; ++i) {
                        printf("%d, ", answer_h[i]);
                    }
                }
                if (answer_h != NULL) {
                    free(answer_h);
                }
                break;
            }

            case 'p': {
                if (Isprime(number)) {
                    printf("The number is simple\n");
                } else {
                    printf("The number isnt simple\n");
                }
                break;
            }
            case 's': {
                int size_arr_answer_s = (number == 0) ? 1 : (int) (log10l(labs(number)) / log10l(16)) + 1;
                char *answer_s = NULL;
                enum Errors status_s = Ten_to_sixteen(number, &answer_s, &size_arr_answer_s);
                if (status_s == INVALID_MEMORY) {
                    printf("Error with memory\n");
                    if (answer_s != NULL) {
                        free(answer_s);
                    }
                    return INVALID_MEMORY;

                } else if (status_s == OK) {
                    if(number < 0){
                        printf("%c", '-');
                    }

                    for(int i = size_arr_answer_s - 1; i >= 0; --i) {
                        printf("%c", answer_s[i]);
                    }

                    printf("\n");
                }
                if (answer_s != NULL) {
                    free(answer_s);
                }
                break;
            }
            case 'e': {
                if (number > 10 || number < 0) {
                    printf("Error uncorrect number\n");
                    return INVALID_INPUT;
                }

                long long int** answer_e = NULL;
                if (Table_of_degrees(&answer_e, number) == INVALID_MEMORY) {
                    printf("Error with memory\n");
                    //очистка уже в функции была тк надо очищать все указатели
                    return INVALID_MEMORY;
                }


                for (int i = 0; i <= 10; i++) {
                    for (int j = 0; j <= number; ++j) {
                        printf("%d^%d = %lld\n", i, j, answer_e[i][j]);
                    }
                    printf("\n");
                }

                for (int i = 0; i <= 10; ++i){
                    if (answer_e[i] != NULL){
                        free(answer_e[i]);
                    }
                }
                if (answer_e != NULL){
                    free(answer_e);
                }
                break;
            }

            case 'a': {

                long long int answer_a = 0;
                if (Sum_of_numbers(number, &answer_a) == INVALID_MEMORY) {
                    printf("Error with memory\n");
                    return INVALID_MEMORY;
                }
                printf("%lld\n", answer_a);
                break;
            }

            case 'f': {
                if (number < 0) {
                    printf("Error: there can only be a positive number\n");
                    return INVALID_INPUT;
                }

                unsigned long long int result_f = 1;
                if (Factorial_number(number, &result_f) == INVALID_MEMORY) {
                    printf("Error with memory\n");
                    return INVALID_MEMORY;
                }
                printf("%llu\n", result_f);
                break;
            }

            default:
                printf("Error uncorrect flag: %s\n", argv[1]);
                break;
            }
            return 0;

    }