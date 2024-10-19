#include "head1.8.h"

enum Errors Read_num(FILE *file, char *num, int *len, int *base) {
    *len = 0;
    *base = 2; // начинаем с минимальной системы счисления
    char c;
    int flag = 0;

    // Пропускаем разделители (пробелы, табуляции, новые строки)
    do {
        c = fgetc(file);
        if (c == EOF) {
            return EOF_REACHED; // Если достигнут конец файла
        }
    } while (c == ' ' || c == '\t' || c == '\n');

    // Чтение числа до следующего разделителя или конца файла
    while (c != ' ' && c != '\t' && c != '\n' && c != EOF) {
        if(c == '-' || c == '+') {
            if (*len != 0) {
                return INVALID_INPUT; // Знак не может быть не первым символом
            }
        } else if (!isalnum(c)) {
            return INVALID_INPUT; // Некорректный символ
        }

        if (isalpha(c)) {
            c = toupper(c); // Переводим в верхний регистр
            flag = 1; // Флаг, чтобы игнорировать ведущие нули
            if (c - 'A' + 10 >= *base) {
                *base = c - 'A' + 10 + 1; // Увеличение минимального основания
                if (*base > 36) {
                    return INVALID_INPUT; // Некорректная система счисления
                }
            }
        } else if (isdigit(c)) {
            if (c - '0' >= *base) {
                *base = c - '0' + 1;
            }
            if (c != '0') {
                flag = 1; // Число не является нулем
            }
        }

        // Добавляем символ к числу, если он не является ведущим нулем
        if (c != '0' || flag == 1) {
            num[(*len)++] = c;
        }

        // Читаем следующий символ
        c = fgetc(file);

        // Если длина числа превышает Capacity, возвращаем ошибку
        if (*len == Capacity) {
            return INVALID_INPUT;
        }
    }

    num[*len] = '\0'; // Завершаем строку

    return OK;
}


enum Errors Base_to_10(const char *const s, int base, long long *answer){

    char *endptr;
    *answer = strtoll(s, &endptr, base);
    if (*answer == LLONG_MAX || *answer == LLONG_MIN) {
        return INVALID_INPUT;
    } else if (*endptr != '\0') { // указывает не на конец строки
        return INVALID_INPUT;
    }

    return OK;
}


enum Errors Validate_input(int argc, char **argv){
    char full_path_1[BUFSIZ], full_path_2[BUFSIZ];

    if (!realpath(argv[1], full_path_1) || !realpath(argv[2], full_path_2))
        return INVALID_INPUT;
    if (!strcmp(full_path_1, full_path_2))
        return INVALID_INPUT;
    return OK;
}