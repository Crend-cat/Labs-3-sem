#include "head2.3.h"



int main()
{
    char *sub = "n\n\nn";
    char *file_1 = "test.txt";

    int count = 1;  // Количество файлов

    enum Errors result = Files_read(sub, count, file_1);

    if (result == WRONG_INPUT_ERROR)
    {
        printf("Внимание, есть файл(ы), где заданная подстрока не найдена\n");
        return WRONG_INPUT_ERROR;
    }
    else if (result == FILE_OPEN_ERROR)
    {
        printf("Ошибка открытия файла\n");
        return FILE_OPEN_ERROR;
    }
    else
    {
        printf("Збс\n");
    }

    return OK;
}
