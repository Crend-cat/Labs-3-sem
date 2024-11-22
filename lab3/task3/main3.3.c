#include "head3.3.h"

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

    Read_file(input, &data, &size_data);
    qsort(data, size_data, sizeof(Employee), p);
    for (int i = 0; i < size_data; i++)
    {
        fprintf(output, "%u %s %s %lf\n", data[i].id, data[i].name, data[i].surname, data[i].money);
    }

    free(data);
    fclose(input);
    fclose(output);
}