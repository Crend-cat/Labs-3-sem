#include "head1.8.h"

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Error: incorrect input\n");
        return INVALID_INPUT;
    }

    if(Validate_input(argc, argv) != OK) {
        printf("Error: incorrect input\n");
        return INVALID_INPUT;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if(input == NULL || output == NULL) {
        if(input != NULL) {
            fclose(input);
        }
        if(output != NULL) {
            fclose(output);
        }
        printf("Error with open file\n");
        return OPEN_FILE_ERROR;
    }

    char *num_base = malloc(Capacity * sizeof(char)); // для числа с произвольной системой счисления
    if(num_base == NULL) {
        fclose(input);
        fclose(output);
        printf("Error with memory\n");
        return INVALID_MEMORY;
    }

    int base, len;
    long long num_10;

    enum Errors read_error;
    // Используем корректную проверку конца файла
    while ((read_error = Read_num(input, num_base, &len, &base)) == OK || read_error == EOF_REACHED) {

        if (len > 0) {
            if (Base_to_10(num_base, base, &num_10) == INVALID_INPUT) {
                free(num_base);
                fclose(input);
                fclose(output);
                printf("Error: incorrect input\n");
                return INVALID_INPUT;
            }

            fprintf(output, "Число: %s\n", num_base);
            fprintf(output, "Минимальная система счисления: %d\n", base);
            fprintf(output, "Число в десятичной системе счисления: %10lld\n", num_10);
            fprintf(output, "\n");
        }

        if (read_error == EOF_REACHED) {
            break; // Завершение после обработки конца файла
        }
    }

    printf("Completed\n");

    free(num_base);
    fclose(input);
    fclose(output);
    return OK;
}
