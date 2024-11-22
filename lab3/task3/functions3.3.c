#include "head3.3.h"

enum Errors Validate_input(int argc, char **argv)
{
    if (argc != 4 || (argv[2][0] != '/' && argv[2][0] != '-') || argv[2][2] != '\0')
        return INVALID_INPUT;

    char full_path_1[BUFSIZ], full_path_2[BUFSIZ];
    if (!realpath(argv[1], full_path_1) || !realpath(argv[3], full_path_2))
        return INVALID_INPUT;
    if (!strcmp(full_path_1, full_path_2))
        return INVALID_INPUT;
    return OK;
}

enum Errors Validate_data(Employee data)
{
    int len = strlen(data.name);
    int i;

    for (i = 0; i < len; ++i)
    {
        if (!((data.name[i] >= 'a' && data.name[i] <= 'z') || (data.name[i] >= 'A' && data.name[i] <= 'Z')))
            return INVALID_INPUT;
    }
    len = strlen(data.surname);
    for (i = 0; i < len; ++i)
    {
        if (!((data.surname[i] >= 'a' && data.surname[i] <= 'z') || (data.surname[i] >= 'A' && data.surname[i] <= 'Z')))
            return INVALID_INPUT;
    }
    if (data.money < EPS)
    {
        return INVALID_INPUT;
    }
    return OK;
}

enum Errors Read_file(FILE *in, Employee **data1, int *size_data)
{

    if(size_data == NULL){
        return INVALID_INPUT;
    }
    
    int cap = 2;
    int count;
    *size_data = 0;

    *data1 = NULL;

    Employee *data = (Employee *)malloc(sizeof(Employee) * cap);
    Employee *realoc;

    if (!data)
        return INVALID_MEMORY;

    while ((count = fscanf(in, "%u%s%s%lf\n", &data[*size_data].id, data[*size_data].name, data[*size_data].surname, &data[*size_data].money)) == 4)
    {
        if (Validate_data(data[(*size_data)]))
        {
            free(data);
            return INVALID_INPUT;
        }
        (*size_data)++;
        if (*size_data == cap)
        {
            cap *= 2;
            realoc = (Employee *)realloc(data, cap * sizeof(Employee));
            if (!realoc)
            {
                free(data);
                return INVALID_MEMORY;
            }
            data = realoc;
        }
    }

    if (count < 4 && count > 0)
    {
        free(data);
        return INVALID_INPUT;
    }
    *data1 = data;
    return OK;
}

int Sort_a(const void *A, const void *B)
{

    if(A == NULL || B == NULL){
        return INVALID_INPUT;
    }

    const Employee *a = (const Employee *)A;
    const Employee *b = (const Employee *)B;
    int temp;

    if (a->money - b->money > EPS)
    {
        return 1;
    }
    if (b->money - a->money > EPS)
    {
        return -1;
    }

    temp = strcmp(a->surname, b->surname);
    if (temp)
        return temp;

    temp = strcmp(a->name, b->name);
    if (temp)
        return temp;

    return a->id - b->id;
}


int Sort_d(const void *A, const void *B)
{

    if(A == NULL || B == NULL){
        return INVALID_INPUT;
    }

    return Sort_a(A, B) * -1;
}