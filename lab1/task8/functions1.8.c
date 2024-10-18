#include "head1.8.h"

enum Errors Read_num(FILE *file, char *num, int *len, int *base){

    *len = 0;
    *base = 2; // начинаем с минимальной
    char c = fgetc(file);
    int flag = 0;

    while( c == ' ' || c == '\t' || c == '\n'){
        if(c == EOF) {
            return OK;
        }
        c = fgetc(file);
    }

    while(c != ' ' && c != '\t' && c != '\n' && c != EOF){ // идем от начала до первого числа
        if(c == '-' || c == '+') {
            if (*len != 0) { // если знак не первый
                return INVALID_INPUT;
            }
        }
        else if(!isalnum(c)){ // если не буква и не число
            return INVALID_INPUT;
        }

        if(isalpha(c)){
            c = toupper(c); // в верхний регистр
            flag = 1;
            if(c - 'A' + 10 >= *base){

                *base = c - 'A' + 10 + 1; // минимум 11 тк встретили А
                if(*base > 36){
                    return INVALID_INPUT;
                }
            }
        }
        else if(isdigit(c)){
            if(c - '0' >= *base){
                *base = c - '0' + 1;
            }
            if(c != '0'){
                flag = 1;
            }
        }
        if(c != '0' || flag == 1){ // игнор ведущих нулей
            num[(*len)++] = c;
        }
        c = fgetc(file);

        if(*len == Capacity){
            return INVALID_INPUT;
        }
    }

    num[*len] = '\0';
    return OK;
}


enum Errors Base_to_10(const char *const s, int base, long long *answer){

    char *endptr;
    *answer = strtoll(s, &endptr, base);
    if (*answer == LLONG_MAX || *answer == LLONG_MIN) {
        return INVALID_INPUT;
    } else if (*endptr != '\000') { // указывает не на конец строки
        return INVALID_INPUT;
    }

    return OK;
}
