#include "head1.9.h"

int main(int argc, char* argv[]){

    switch(argc){

        long int a, b;
        case 3:

            if(Stroka_to_lint(argv[1], &a, 10) != OK ||
                    Stroka_to_lint(argv[2], &b, 10) != OK){

                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            long int* answer_arr = NULL;
            int size = 20;
            if(Arr_gen(a, b, &answer_arr, size) == INVALID_MEMORY)
            {
                printf("Error with memory\n");
                free(answer_arr);
                return INVALID_MEMORY;
            }
            else if(Arr_gen(a, b, &answer_arr, size) == INVALID_INPUT)
            {
                printf("Error with arrays sizeeee\n");
                free(answer_arr);
                return INVALID_INPUT;
            }

            else {

                printf("Our massive before:\n");
                for (int i = 0; i < size; ++i) {
                    printf("%ld ", answer_arr[i]);
                }
                printf("\n");

                Swap_min_max(&answer_arr, size);

                printf("Our massive after:\n");
                for (int i = 0; i < size; ++i) {
                    printf("%ld ", answer_arr[i]);
                }
                printf("\n");
                free(answer_arr);
                break;
            }

        case 1:

            srand(time(NULL)); // опять рандом для размеров
            int size_a = 10; //rand() % (10000 + 1 - 10) + 10; // от 0 до 9990 и потом +10 чтобы до 10000 число крафтли
            printf("%d\n", size_a);
            int size_b = 10; //rand() % (10000 + 1 - 10) + 10;
            printf("%d\n", size_b);

            short * arr_a = NULL;
            short * arr_b = NULL;
            short * arr_c = NULL;

            if (Arr_gen2(-1000, 1000, &arr_a, size_a) != OK) {
                printf("Error with memory for arr_a\n");
                return INVALID_MEMORY;
            }

            if (Arr_gen2(-1000, 1000, &arr_b, size_b) != OK) {
                printf("Error with memory for arr_b\n");
                free(arr_a);
                return INVALID_MEMORY;
            }

             printf("Massive A:\t");
            for (int i = 0; i < size_a; ++i)
            {
                printf("%d ", arr_a[i]);
            }
            printf("\nMassive B:\t");
            for (int i = 0; i < size_b; ++i)
            {
                printf("%d ", arr_b[i]);
            }

            if(Arr_gen_and_find_closest(&arr_a, size_a, &arr_b, size_b, &arr_c) != OK)
            {
                printf("Error with memory\n");
                free(arr_a);
                free(arr_b);
                if (arr_c != NULL) {
                    free(arr_c); // освобождаем только если arr_c инициализирован
                }
                return INVALID_MEMORY;
            }

            printf("\nMassive C\n");
            for (int i = 0; i < size_a; ++i)
            {
                printf("%d ", arr_c[i]);
            }
            printf("\n");
            free(arr_a);
            free(arr_b);
            free(arr_c);
            break;



        default:
            printf("Error uncorrect flag: %s\n", argv[1]);
            break;
    }
}