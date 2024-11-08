#include "head3.10.h"

int main(int argc, char **argv){

    if (Validate_input(argc, argv)){

        puts("Error, uncorrect input\n");
        return INVALID_INPUT;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (Build_tree(input, output) == INVALID_MEMORY)
    {
        puts("Error with memory\n");
        return INVALID_MEMORY;
    }
    fclose(input);
    fclose(output);

    return 0;
}