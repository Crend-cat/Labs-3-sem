#include "head1.7.h"

enum Errors Validate_input_r(int argc, char **argv)
{
    if (argc != 5 || (argv[1][0] != '/' && argv[1][0] != '-') || argv[1][2] != '\0')
        return INVALID_INPUT;

    char full_path_1[BUFSIZ], full_path_2[BUFSIZ], full_path_3[BUFSIZ];
    if (!realpath(argv[2], full_path_1) || !realpath(argv[3], full_path_2) || !realpath(argv[argc - 1], full_path_3))
        return INVALID_INPUT;
    else if (!strcmp(full_path_1, full_path_2))
        return INVALID_INPUT;
    else if(!strcmp(full_path_1, full_path_3))
        return INVALID_INPUT;
    else if(!strcmp(full_path_2, full_path_3))
        return INVALID_INPUT;

    return OK;
}

enum Errors Validate_input_a(int argc, char **argv){
    if (argc != 4 || (argv[1][0] != '/' && argv[1][0] != '-') || argv[1][2] != '\0')
        return INVALID_INPUT;

    char full_path_1[BUFSIZ], full_path_2[BUFSIZ];
    if (!realpath(argv[2], full_path_1) || !realpath(argv[argc - 1], full_path_2))
        return INVALID_INPUT;
    if (!strcmp(full_path_1, full_path_2))
        return INVALID_INPUT;
    return OK;
}

enum Errors Read_file(FILE *file, char **word, int *len_word)
{
    int capacity = 20;
    *len_word = 0;
    char symbol = fgetc(file);
    while (symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '\r')
    {
        if (symbol == EOF)
            return OK;
        symbol = fgetc(file);
    }

    *word = (char *)malloc(capacity * sizeof(char));
    if (*word == NULL)
    {
        return MEMORY_ERROR;
    }

    while (symbol != ' ' && symbol != '\t' && symbol != '\n' && symbol != '\r')
    {
        if (*len_word + 1 == capacity)
        {
            capacity *= 2;
            char *for_resize = (char *)realloc(*word, capacity);
            if (for_resize == NULL)
            {
                free(word);
                return MEMORY_ERROR;
            }
            *word = for_resize;
        }
        (*word)[(*len_word)++] = symbol;
        symbol = fgetc(file);
        if (symbol == EOF)
        {
            (*word)[*len_word] = '\0';
            return OK;
        }
    }
    (*word)[*len_word] = '\0';
    return OK;
}

void Word_to_4(char **word, int len_word, int **result)
{
    int symbol_4 = 0;
    for (int i = 0; i < len_word; i++)
    {
        if (isalpha((*word)[i]))
            (*word)[i] = tolower((*word)[i]);

        int shift = 1, symbol = (int)(*word)[i];
        while (symbol)
        {
            symbol_4 += (symbol % 4) * shift;
            shift *= 10;
            symbol /= 4;
        }
        (*result)[i] = symbol_4;

        symbol_4 = 0;
    }
}

void To_lowercase(char **word, int len_word)
{
    for (int i = 0; i < len_word; i++)
    {
        if (isalpha((*word)[i]))
            (*word)[i] = tolower((*word)[i]);
    }
}

void Word_to_8(char **word, int len_word, int **result)
{
    int symbol_8 = 0;
    for (int i = 0; i < len_word; i++)
    {
        int shift = 1, symbol = (int)(*word)[i];
        while (symbol)
        {
            symbol_8 += (symbol % 8) * shift;
            shift *= 10;
            symbol /= 8;
        }
        (*result)[i] = symbol_8;
        symbol_8 = 0;
    }
}