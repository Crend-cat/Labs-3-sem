#include "head2.3.h"

int Strlen(const char * s)
{
    int k =0;
    while (*s != '\0')
    {
        s++;
        k++;
    }
    return k;
}

// префикс функция
void ComputeLPSArray(char* pattern, int M, int* lps)
{
    int length = 0; // длина текущего префикса (с начала слова по буквам), который также является суффиксом (с конца).
    lps[0] = 0;
    int i = 1;

    while (i < M) // длина подстроки
    {
        if (pattern[i] == pattern[length]) // совпало (текущий символ расширяет префик)
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {

                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0; // lenght = 0 -> совпадений нет
                i++;
            }
        }
    }
}

// КМП
char* KMPsearch(char* pattern, char* text) // возвращает указатель на первое вхождение подстроки в тексте
{
    int M = Strlen(pattern); // подстрока
    int N = Strlen(text);
    int* lps = (int*)malloc(M * sizeof(int)); // для избеганий повторов
    if (!lps)
    {
        return NULL;
    }


    ComputeLPSArray(pattern, M, lps); // заполняем массив

    int i = 0; // индекс в тексте
    int j = 0; // индекс в подстроке
    while (i < N)
    {
        if (pattern[j] == text[i]) // совпало -> сравниваем след. символы
        {
            i++;
            j++;
        }

        if (j == M) // нашли
        {

            free(lps);
            return &text[i - j]; // возврат указателя на начало вхождения
        }
        else if (i < N && pattern[j] != text[i]) // если символы не совпадают
        {
            if (j != 0)
                j = lps[j - 1]; // переместили (избегаем повторов)
            else
                i++;
        }
    }


    free(lps); // если не нашли
    return NULL;
}

enum Errors Find_substr(char *substring, FILE* file, char *file_name){

    // Определяем размер файла
    fseek(file, 0, SEEK_END); // указатель в конец
    long file_size = ftell(file); // позиция указателя - 0 = размер в байтах
    rewind(file); // указатель в начало файла

    // Выделяем память для содержимого файла
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        return INVALID_MEMORY;
    }

    // Чтение файла в память
    fread(file_content, 1, file_size, file); // куда, по скоко ( по 1 байту), размер, указатель на файл
    file_content[file_size] = '\0'; // чтобы работать как со строкой

    // Удаление всех символов '\r' из file_content
    char *src = file_content, *dst = file_content;
    while (*src) {
        if (*src != '\r') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';  // Завершаем строку

    // Начало поиска подстроки
    char *current_pos = file_content; // позиция ( изначально это начало файла )
    int found = 0; // флаг
    int line = 1;
    long global_offset = 0; // хранит глобальное смещение от начала файла до текущей позиции поиска
    char *line_start = file_content; // строка

    // Основной цикл поиска совпадений
    while ((current_pos = KMPsearch(substring, current_pos)) != NULL){ // получисли указатель на начало подстр в тексте
        found = 1; // хотя бы 1 нашли

        // Подсчет номера строки и позиции в строке
        while (line_start < current_pos)
        {
            if (*line_start == '\n') { // считаем сколько строк прошли
                line++;
                global_offset = line_start - file_content + 1; // вроде адрес начала новой строки
            }
            line_start++;
        }

        int position_in_line = (current_pos - (file_content + global_offset)) + 1; // позиция - адрес начала строки + 1(тк с 1 нумеруем) = позиция в строке

        printf("File %s: line %d position %d\n", file_name, line, position_in_line);

        // Переход к следующему символу
        current_pos++;
    }

    free(file_content);

    if (!found) {
        printf("The substring was not found in the file %s\n", file_name);
        return INVALID_INPUT;
    }

    return OK;
}

enum Errors Files_read(char *substring, int count, ...)
{
    va_list ptr;
    va_start(ptr, count);

    for (int i = 0; i < count; i++){

        char *file_name = va_arg(ptr, char*);
        FILE *file = fopen(file_name, "r");
        if (!file)
        {
            return FILE_OPEN_ERROR;
        }

        if (Find_substr(substring, file, file_name) != OK)
        {
            fclose(file);
            return INVALID_INPUT;
        }
        fclose(file);
    }
    va_end(ptr);

    return OK;
}