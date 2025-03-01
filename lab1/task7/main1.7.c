#include "head1.7.h"

int main(int argc, char *argv[])
{
    if (!((argv[1][0] == '-' || argv[1][0] == '/') && argv[1][2] == '\0'))
    {
        printf("Error, invalid input\n");
        return INVALID_INPUT;
    }

    char *word = NULL;
    int len_word = 0;

    switch (argv[1][1])
    {
        case 'r': {

            if ((Validate_input_r(argc, argv)) != OK){
                printf("Error, uncorrect input\n");
                return INVALID_INPUT;
            }

            FILE *file1 = fopen(argv[2], "r");
            FILE *file2 = fopen(argv[3], "r");
            FILE *file_result = fopen(argv[argc - 1], "w");
            if (file1 == NULL || file2 == NULL || file_result == NULL) {
                printf("Error with open file(s)\n");
                if (file1 != NULL)
                    fclose(file1);
                if (file2 != NULL)
                    fclose(file2);
                if (file_result != NULL)
                    fclose(file_result);
                return FILE_OPEN_ERROR;
            }

            while (!feof(file1) && !feof(file2)) {
                if (Read_file(file1, &word, &len_word) == MEMORY_ERROR) {
                    printf("Error, invalid memory\n");
                    if (word != NULL)
                        free(word);
                    fclose(file1);
                    fclose(file2);
                    fclose(file_result);
                    return MEMORY_ERROR;
                }

                if (len_word > 0) {
                    fprintf(file_result, "%s ", word);
                    free(word);
                    word = NULL;
                }

                if (Read_file(file2, &word, &len_word) == MEMORY_ERROR) {
                    printf("Error, invalid memory\n");
                    if (word != NULL)
                        free(word);
                    fclose(file1);
                    fclose(file2);
                    fclose(file_result);
                    return MEMORY_ERROR;
                }

                if (len_word > 0) {
                    fprintf(file_result, "%s ", word);
                    free(word);
                    word = NULL;
                }
            }

            while (!feof(file1)) {
                if (Read_file(file1, &word, &len_word) == MEMORY_ERROR) {
                    printf("Error, invalid memory\n");
                    if (word != NULL)
                        free(word);
                    fclose(file1);
                    fclose(file2);
                    fclose(file_result);
                    return MEMORY_ERROR;
                }

                if (len_word > 0) {
                    fprintf(file_result, "%s ", word);
                    free(word);
                    word = NULL;
                }
            }

            while (!feof(file2)) {
                if (Read_file(file2, &word, &len_word) == MEMORY_ERROR) {
                    printf("Error, invailid memory\n");
                    if (word != NULL)
                        free(word);
                    fclose(file1);
                    fclose(file2);
                    fclose(file_result);
                    return MEMORY_ERROR;
                }

                if (len_word > 0) {
                    fprintf(file_result, "%s ", word);
                    free(word);
                    word = NULL;
                }
            }

            fclose(file1);
            fclose(file2);
            fclose(file_result);
            printf("Complited: check %s\n", argv[argc - 1]);
            break;
        }

        case 'a': {

            if ((Validate_input_a(argc, argv)) != OK){
                printf("Error, uncorrect input\n");
                return INVALID_INPUT;
            }

            FILE *input = fopen(argv[2], "r");
            FILE *output = fopen(argv[argc - 1], "w");

            if (input == NULL || output == NULL) {
                printf("Error with open file\n");
                if (input != NULL)
                    fclose(input);
                if (output != NULL)
                    fclose(output);
                return FILE_OPEN_ERROR;
            }

            char *word_a = NULL;
            int *result_a = NULL;
            int count_world = 1;
            while (!feof(input)) {
                if (Read_file(input, &word_a, &len_word) == MEMORY_ERROR) {
                    printf("Error, invailid memory\n");
                    if (word != NULL)
                        free(word);
                    fclose(input);
                    fclose(output);
                    return MEMORY_ERROR;
                }

                if (len_word > 0) {
                    if (count_world % 10 == 0) { // в каждой 10-й
                        if (result_a != NULL) // в строчные -> в ASCII коды -> коды в 4 ричную
                            result_a = realloc(result_a, (len_word + 1) * sizeof(int));
                        else
                            result_a = (int *)malloc((len_word + 1) * sizeof(int));

                        if (result_a == NULL) {
                            printf("Error, invailid memory\n");
                            if (word != NULL)
                                free(word);
                            fclose(input);
                            fclose(output);
                            return MEMORY_ERROR;
                        }

                        Word_to_4(&word_a, len_word, &result_a);
                        for (int i = 0; i < len_word; ++i) {
                            fprintf(output, "'%d'", result_a[i]);
                        }
                        fprintf(output, " ");
                    }

                    if (count_world % 10 != 0 && count_world % 2 == 0) { // в каждой 2-й и не 10-й
                        if (result_a != NULL) // просто в строчные буквы
                            result_a = realloc(result_a, (len_word + 1) * sizeof(int));
                        else
                            result_a = (int *) malloc((len_word + 1) * sizeof(int));

                        if (result_a == NULL) {
                            printf("Error, invailid memory\n");
                            if (word != NULL)
                                free(word);
                            fclose(input);
                            fclose(output);
                            return MEMORY_ERROR;
                        }

                        To_lowercase(&word_a, len_word);
                        fprintf(output, "%s ", word_a);

                    } else if (count_world % 10 != 0 && count_world % 5 == 0) { // каждой 5-й и не 10-й
                        if (result_a != NULL) // в ASCII код и его в 8 ричную
                            result_a = realloc(result_a, (len_word + 1) * sizeof(int));
                        else
                            result_a = (int *) malloc((len_word + 1) * sizeof(int));

                        if (result_a == NULL) {
                            printf("Error, invailid memory\n");
                            if (word != NULL)
                                free(word);
                            fclose(input);
                            fclose(output);
                            return MEMORY_ERROR;
                        }

                        Word_to_8(&word_a, len_word, &result_a);
                        for (int i = 0; i < len_word; ++i) {
                            fprintf(output, "'%d'", result_a[i]);
                        }
                        fprintf(output, " ");
                    } else {
                        fprintf(output, "%s ", word_a);
                    }

                    free(word_a);
                    word_a = NULL;
                }
                count_world++;
            }

            fclose(input);
            fclose(output);
            printf("Complited, file %s transformed to file %s\n", argv[2], argv[argc - 1]);
            break;
        }

        default: {
            printf("Error: incorrect flag %s\n", argv[1]);
            return INVALID_INPUT;
        }

    }
    return 0;
}