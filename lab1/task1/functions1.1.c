#include "head1.1.h"


enum Errors Stroka_to_chisl(const char *str, long int * answer, int base){
    char *endptr;
    *answer = strtol(str, &endptr, base);
    if(*answer == LONG_MAX || *answer == LONG_MIN){
        return INVALID_INPUT;
    }
    else if(endptr == str){ //ниче не преобразовали
        return INVALID_INPUT;
    }
    else if(*endptr != '\0'){ //чето осталось
        return INVALID_INPUT;
    }
    else{
        return OK;
    }
}


enum Errors Nat_numbers_arr(const long int number, int** answer, int* size_arr_answer_h){
    if(number == 0){
        return INVALID_INPUT;
    }

    int capasity = 4;
    *answer = (int*)malloc(capasity * sizeof(int));
    if(answer == NULL){
        return INVALID_MEMORY;
    }

    for(int i = 1; i <= 100; ++i){
        if(i % number == 0){
            (*answer)[(*size_arr_answer_h)++] = i;//взяли массив на ласт место записали и увеличили размер
            if (capasity == *size_arr_answer_h){
                capasity *= 2;
                int *q_realloc = realloc(*answer, capasity * sizeof(int));
                if (q_realloc == NULL){
                    free(answer);
                    return INVALID_MEMORY;
                }
                *answer = q_realloc;
            }
        }
    }
    return OK;
}


int Isprime(long int n){
    if (n <= 1){
        return 0;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

enum Errors Ten_to_sixteen(long int n, char** answer_s, int* size_arr_answer_s){
    *answer_s = (char*)calloc((*size_arr_answer_s + 1), sizeof(char));
    if(*answer_s == NULL){
        return INVALID_MEMORY;
    }

    if (n == 0) {
        (*answer_s)[0] = '0';
        (*answer_s)[1] = '\0';
        return OK;
    }
    int i = 0;

    if(n < 0){
        n *= -1;
    }
    while (n > 0 && i < *size_arr_answer_s) {
        int rem = n % 16;
        if (rem < 10) {
            (*answer_s)[i++] = '0' + rem; // 0-9
        } else {
            (*answer_s)[i++] = 'A' + (rem - 10); // A-F
        }
        n /= 16;
    }

    (*answer_s)[i] = '\0'; // Завершающий ноль
    return OK;
}

enum Errors Table_of_degrees(long long int*** answer, long int n){

    *answer = (long long int **)malloc(11 * sizeof(long long int*));
    if((*answer) == NULL){
        return INVALID_MEMORY;
    }
    for (int i = 0; i <= 10; ++i)
    {
        (*answer)[i] = (long long int *)malloc((n + 1) * sizeof(long long int));
        if((*answer)[i] == NULL)
        {
            for(int j = 0; j < i; ++j)
            {
                free((*answer)[j]);
            }
            free(*answer);
            return INVALID_MEMORY;
        }
    }

    (*answer)[0][0] = 1;
    for(int i = 1; i < 11; ++i)
    {
        (*answer)[i][0] = 1;
        (*answer)[i][1] = i;
    }

    for(int i = 2; i <= n; ++i)
    {
        (*answer)[0][i] = 0;
        (*answer)[1][i] = 1;
    }
    (*answer)[0][1] = 0;
    for(int b = 0; b <= 10; ++b)
    {
        for(int degree = 2; degree <= n; ++degree)
        {
            (*answer)[b][degree] = (*answer)[b][degree - 1] * b;
        }
    }
    return OK;
}

enum Errors Sum_of_numbers(long int n, long long int * answer)
{
    if (n < 2)
    {
        *answer = 1;
        return OK;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(*answer > LLONG_MAX - i){
            return INVALID_MEMORY;
        }

        *answer += i;
    }
    return OK;
}

enum Errors Factorial_number(long int n, unsigned long long int* answer)
{
    *answer = 1;
    for(long int i = 2; i <= n; ++i)
    {
        if(*answer > ULLONG_MAX / i){
            return INVALID_MEMORY;
        }
        *answer *= i;
    }
    return OK;
}