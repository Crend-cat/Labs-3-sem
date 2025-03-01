#include "head2.8.h"

int main()
{
    char *res;
    int c = 0;

    printf("\n\ttest 1\n123 + FFFFFFFFFF + ABCFF; base = 16\n");
    switch (sum_any_base_all_numbers(&res, 16, 3, "123", "FFFFFFFFFF", "ABCFF"))
    {
        case INVALID_INPUT:
            printf("Input error\n");
            return INVALID_INPUT;

        case INVALID_MEMORY:
            printf("Memory error\n");
            return INVALID_MEMORY;

        case OK:
            sscanf(res, "%d", &c);
            printf("\t result: %s\n", res);
            free(res);
            break;
    }

    printf("\n\ttest 2\n00000008 + 0 + 0 + 2 + 1; base = 10\n");
    switch (sum_any_base_all_numbers(&res, 10, 5, "0000008", "0", "0", "2", "1"))
    {
        case INVALID_INPUT:
            printf("Input error\n");
            return INVALID_INPUT;

        case INVALID_MEMORY:
            printf("Memory error\n");
            return INVALID_MEMORY;

        case OK:
            sscanf(res, "%d", &c);
            printf("\t result: %d\n", c);
            free(res);
            break;
    }

    printf("\n\ttest 3\n5 + abc; base = 10;\n");
    switch (sum_any_base_all_numbers(&res, 10, 2, "5", "abc"))
    {
        case INVALID_INPUT:{
            printf("Input error\n");
            return INVALID_INPUT;
        }

        case INVALID_MEMORY:{
            printf("Memory error\n");
            return INVALID_MEMORY;
        }

        case OK:{
            sscanf(res, "%d", &c);
            printf("\t result: %d\n", c);
            free(res);
            break;
        }
    }

}