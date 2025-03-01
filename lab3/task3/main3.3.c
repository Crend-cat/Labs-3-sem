#include "head3.3.h"
//gcc main3.3.c functions3.3.c -std=c99 -Wall -o task3.3
//./task3.3 input.txt -a output.txt
int main(int argc, char **argv)
{
    int size_data;
    if (Validate_input(argc, argv))
    {
        printf("Error, uncorrect input\n");
        return INVALID_INPUT;
    }

    Employee *data = NULL;

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[3], "w");
    if (!input || !output)
    {
        if (!input)
            fclose(input);
        if (!output)
            fclose(output);
        printf("Error with open file(s)\n");
        return OPEN_FILE_ERROR;
    }

    int (*p) (const void*, const void*);
    if(argv[2][1] == 'a'){
        p = Sort_a;
    }
    else{
        p = Sort_d;
    }

    switch (Read_file(input, &data, &size_data)){
        case INVALID_INPUT:
            printf("Error incorrect input");
            return INVALID_INPUT;

        case INVALID_MEMORY:
            printf("Error with memory");
            return INVALID_MEMORY;

        case OK:
            qsort(data, size_data, sizeof(Employee), p);
            for (int i = 0; i < size_data; i++)
            {
                fprintf(output, "%u %s %s %lf\n", data[i].id, data[i].name, data[i].surname, data[i].money);
            }

            free(data);
            fclose(input);
            fclose(output);

        case OVERFLOW_ERROR:
            break;

        case OPEN_FILE_ERROR:
            break;
    }
    return 0;

}