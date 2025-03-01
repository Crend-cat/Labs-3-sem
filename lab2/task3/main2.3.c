#include "head2.3.h"

// gcc main2.3.c functions2.3.c -std=c99 -Wall -o task2.3

int main()
{
    char *sub = "n\n\nn";
    char *file_1 = "test.txt";

    if (strlen(sub) == 0) {
        printf("An empty substring is not allowed!\n");
        return INVALID_INPUT;
    }

    int count = 1;  // Количество файлов

    enum Errors result = Files_read(sub, count, file_1);

    if (result == INVALID_INPUT)
    {
        printf("There is a file(s) where the specified substring is not found\n");
        return INVALID_INPUT;
    }
    else if (result == FILE_OPEN_ERROR)
    {
        printf("Error wiht open file(s)\n");
        return FILE_OPEN_ERROR;
    }
    else
    {
        printf("Complite\n");
    }

    return OK;
}
