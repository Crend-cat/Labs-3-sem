#include "head2.1.h"

enum Errors Validate(int argc, char *argv[]){

    if(argc < 3 || argv[1][0] != '-' || argv[1][2] != '\0'){
        return INVALID_INPUT;
    }
    return OK;
}

enum Errors Strlen(const char *str){
    const char *begin = str;
    while(*str++){
    }
    return str - begin - 1;
}

enum Errors Reverse_str(const char *str, char **r_str){
    int len = Strlen(str);
    *r_str = (char *)malloc((len + 1) * sizeof(char));
    if(!(*r_str)){
        return INVALID_MEMORY;
    }

    for(int i = 0; i < len; i++){

        (*r_str)[i] = str[len - i - 1];
    }
    (*r_str)[len] = '\0';
    return OK;
}

enum Errors Upp_str(const char *str, char **Str){
    int len = Strlen(str);
    *Str = (char *)malloc((len + 1) * sizeof(char));
    if(!(*Str)){
        return INVALID_MEMORY;
    }

    for(int i = 0; i < len; i++){
        if(i % 2 && isalpha(str[i])){
            (*Str)[i] = toupper(str[i]);
        }
        else{
            (*Str)[i] = str[i];
        }
    }
    (*Str)[len] = '\0';
    return OK;
}


enum Errors Transform_str(const char *str, char **n_str){
    int len = Strlen(str);
    (*n_str) = (char *)malloc( (len + 1) * sizeof(char));
    if(!(*n_str)){
        return INVALID_MEMORY;
    }

    char *c = *n_str; // если с *n_str все делать то мы потеряем указатель на начало строки и
                      // дальше не сможем ее очистить и вывести соответственно

    for(int i = 0; i < len; i++){
        if(isdigit(str[i])){
            *c++ = str[i];
        }
    }
    for(int i = 0; i < len; i++){
        if(isalpha(str[i])){
            *c++ = str[i];

        }
    }
    for(int i = 0; i < len; i++){
        if(!isalnum(str[i])){
            *c++ = str[i];
        }
    }

    *c = '\0';
    return OK;
}

enum Errors Str_to_ulint(const char *str, unsigned long *answer){
    if(str[0] == '-'){
        return INVALID_INPUT;
    }
    char *endptr;
    *answer = strtoul(str, &endptr, 10);
    if(*answer == ULONG_MAX){
        return INVALID_INPUT;
    }
    if(*endptr != '\0'){
        return INVALID_INPUT;
    }
    return OK;
}

enum Errors Random_concat(char **argv, int count_s, unsigned long seed, char **answer){

    int i, capasity = 0, rand_n, count_remained = count_s;

    for(i = 3; i < count_s + 3; i++){
        if(INT_MAX - Strlen(argv[i]) < capasity){
            return INVALID_MEMORY;
        }
        capasity += Strlen(argv[i]);
    }

    *answer = (char *)malloc((capasity + 1) * sizeof(char)); // ответ
    if(!(*answer)){
        return INVALID_MEMORY;
    }
    *answer[0] = '\0';

    char *used = (char *)malloc(count_s * sizeof(char)); // для использованных строк
    if(used == NULL){
        free(*answer);
        return INVALID_MEMORY;
    }
    for(i = 0; i < count_s; i++){
        used[i] = '\0';
    }

    srand(seed); // задаем начальное значение для rand, если не сделать, то постоянно одинаковое все будет

    while(count_remained){
        rand_n = rand() % count_s; // генерируем случайный индекс
        if(used[rand_n] == '1'){   // была ли уже использована строка
            continue;
        }
        Concat(argv[rand_n + 3], *answer);
        used[rand_n] = '1'; // 1 - этот индекс уже использовали
        count_remained--;
    }
    free(used);
    return OK;
}


void Concat(const char *str, char *answer){
    while(*answer++){

    }

    answer--; // на ласт знаке стоим

    for(int i = 0; str[i] != '\0'; ++i){
        *answer++ = str[i];
    }
    *answer = '\0';
}