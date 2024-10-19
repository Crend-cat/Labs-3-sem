#include "head1.10.h"

enum Errors Str_to_llint(const char *str, long long *answer, int base){

    char *endptr;
    int flag = 0;

    for(int i = 0; i < strlen(str); i++){
        if(base < 10){
            if(str[i] == '+' || str[i] == '-') {
                if (flag || i != 0) {
                    return INVALID_INPUT;
                }
                flag = 1;
            }
            else if((str[i] < '0' || str[i] > base + '0')){
                return INVALID_INPUT;
            }
        }
        else{
            if(str[i] == '+' || str[i] == '-'){
                if(flag || i != 0){
                    return INVALID_INPUT;
                }
                flag = 1;
            }
            else if((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > base - 10 + 'A')){
                return INVALID_INPUT;
            }
        }

    }

    *answer = strtoll(str, &endptr, base);
    if(*answer == LLONG_MAX|| *answer == LLONG_MIN){
        return INVALID_INPUT;
    }
    if(*endptr != '\0'){
        return INVALID_INPUT;
    }
    return OK;
}

void To_xbase(long long num, int base, char *answer)
{
    int i, flag_minus = 0;
    char temp;
    int len_result = 0;
    if (num < 0)
    {
        num = llabs(num);
        flag_minus = 1;
    }
    while (num)
    {
        if(num % base > 9){
            answer[len_result++] = (num % base - 10 + 'A');
        }
        else{
            answer[len_result++] = (num % base + '0');
        }

        num /= base;
    }
    if (flag_minus)
        answer[len_result++] = '-';
    for (i = 0; i < len_result / 2; i++) // разворачиваем строку тк разряды в обратном порядке записаны
    {
        temp = answer[i];
        answer[i] = answer[len_result - 1 - i];
        answer[len_result - 1 - i] = temp;
    }
    answer[len_result] = '\0';
}
