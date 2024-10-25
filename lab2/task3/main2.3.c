#include "head2.3.h"


int main()
{
    Found *ans, *cur;
    char flag = '1';
    enum Errors stat = Search_str("str", 1, &ans, "text.txt");

    if (stat == INVALID_INPUT)
    {
        printf("Error: incorrect input\n");
        return INVALID_INPUT;
    }

    cur = ans;
    while (cur)
    {
        Found *next = (Found *) cur->next;
        flag = 0;
        printf("File: %s line: %d, char: %d;\n", cur->file_name, cur->n_line, cur->n_char);
        free(cur->file_name);
        free(cur);
        cur = next;
    }
    if (flag)
    {
        printf("Substring not found\n");
    }
    if (stat == OPEN_FILE_ERROR)
    {
        printf("Error with open file(s)\n");
        return OPEN_FILE_ERROR;
    }
    if (stat == INVALID_MEMORY)
    {
        printf("Error with memory\n");
        return INVALID_MEMORY;
    }
    return OK;
}