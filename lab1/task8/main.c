#include "head1.8.h"

int main(int argc, char *argv[])
{
    if ((Validate_input(argc, argv)) != OK){
        printf("Error, uncorrect input\n");
        return INVALID_INPUT;
    }



    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if (input == NULL || output == NULL)
    {
        if (input != NULL)
            fclose(input);
        if (output != NULL)
            fclose(output);
        printf("Error with open file\n");
        return FILE_OPEN_ERROR;
    }

    char *num_random_base = malloc(Capacity * sizeof *num_random_base);

    if (num_random_base == NULL)
    {
        printf("Error with memory\n");
        fclose(input);
        fclose(output);
        return INVALID_MEMORY;
    }

    int base, len_word, minus = -1;
    long long num_base10;

    while (!feof(input))
    {
        if (Read_num(input, num_random_base, &len_word, &base, &minus) == INVALID_INPUT)
        {
            free(num_random_base);
            fclose(input);
            fclose(output);
            printf("Error, incorrect input\n");
            return INVALID_INPUT;
        }

        if (len_word > 0)
        {
            if (Convert(num_random_base, base, &num_base10) == INVALID_INPUT)
            {
                free(num_random_base);
                fclose(input);
                fclose(output);
                printf("Error, incorrect input\n");
                return INVALID_INPUT;
            }

            fprintf(output, "Входное число: %s\n", num_random_base);
            fprintf(output, "Минимальное основание: %d\n", base);
            fprintf(output, "Число в 10сс: %lld\n", num_base10 * minus);
            fprintf(output, "\n");
            minus = 1;
        }
    }

    free(num_random_base);
    fclose(input);
    fclose(output);
    printf("Complite\n");
    return OK;
}
