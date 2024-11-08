#include "head1.8.h"

enum Errors Read_num(FILE *file, char *word, int *len_word, int *base){

    *len_word = 0;
    *base = 2;
    char symbol = fgetc(file);

    while (symbol == ' ' || symbol == '\t' || symbol == '\n'){// до числа

        symbol = fgetc(file);
    }

    int flag = 0;

    while (symbol != ' ' && symbol != '\t' && symbol != '\n' && symbol != EOF){ // число

        if (symbol == '-' || symbol == '+')
        {
            if (*len_word != 0){
                return INVALI_INPUT;
            }
        }
        else if (!isalnum(symbol) && symbol != '-' && symbol != '+') // fucking /r
        {
            symbol = fgetc(file);
            continue;
        }


        if (isalpha(symbol))
        {
            symbol = toupper(symbol);
            flag = 1;
            if (symbol - 'A' + 10 >= *base)
            {
                *base = symbol - 'A' + 10 + 1;
                if (*base > 36)
                    return INVALI_INPUT;
            }
        }

        else if (isdigit(symbol))
        {
            if (symbol - '0' >= *base)
                *base = symbol - '0' + 1;
            if (symbol != '0')
                flag = 1;
        }

        if (symbol != '0' || flag == 1)
            word[(*len_word)++] = symbol;


        symbol = fgetc(file);
        if (*len_word == Capacity)
            return INVALI_INPUT;
    }

    word[*len_word] = '\0';
    return OK;
}

enum Errors Convert(const char *const word, int base, long long *result)
{

    char *endptr;
    *result = strtoll(word, &endptr, base);
    if (*result == LLONG_MAX || *result == LLONG_MIN)
        return INVALI_INPUT;
    else if (*endptr != '\0')
        return INVALI_INPUT;

    return OK;
}