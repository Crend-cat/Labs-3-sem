#include "head1.8.h"

enum Errors Validate_input(int argc, char **argv){
    if (argc != 3)
        return INVALID_INPUT;

    char full_path_1[BUFSIZ], full_path_2[BUFSIZ];
    if (!realpath(argv[1], full_path_1) || !realpath(argv[2], full_path_2))
        return INVALID_INPUT;
    else if (!strcmp(full_path_1, full_path_2))
        return INVALID_INPUT;
    return OK;
}


enum Errors Read_num(FILE *file, char *word, int *len_word, int *base, int *minus){

    *len_word = 0;
    *base = 2;
    char symbol = fgetc(file);

    while (symbol == ' ' || symbol == '\t' || symbol == '\n'){// до числа

        symbol = fgetc(file);
    }


    while (symbol != ' ' && symbol != '\t' && symbol != '\n' && symbol != EOF){ // число

        if (symbol == '-' || symbol == '+')
        {
            if (*len_word != 0){
                return INVALID_INPUT;
            }
            *minus = 1;
        }
        else if (!isalnum(symbol) && symbol != '-' && symbol != '+') // fucking /r
        {
            symbol = fgetc(file);
            continue;
        }


        if (isalpha(symbol))
        {
            symbol = toupper(symbol);
            if (symbol - 'A' + 10 >= *base)
            {
                *base = symbol - 'A' + 10 + 1;
                if (*base > 36)
                    return INVALID_INPUT;
            }
        }

        else if (isdigit(symbol))
        {
            if (symbol - '0' >= *base)
                *base = symbol - '0' + 1;
        }
            word[(*len_word)++] = symbol;


        symbol = fgetc(file);
        if (*len_word == Capacity)
            return INVALID_INPUT;
    }

    word[*len_word] = '\0';
    return OK;
}

enum Errors Convert(char *word, int base, long long *result)
{

    char *endptr;
    *result = strtoll(word, &endptr, base);
    if (*result == LLONG_MAX || *result == LLONG_MIN) {
        printf("%c", *word);
        return INVALID_INPUT;
    }
    else if (*endptr != '\0') {
        printf("%c", *word);
        return INVALID_INPUT;
    }

    return OK;
}