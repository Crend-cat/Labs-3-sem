#include "head1.4.h"

int main(int argc, char *argv[]) {  // имя  -nd (-d) input out (нет out)
    if (argc < 3) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }
    if (!((argv[1][0] == '-' || argv[1][0] == '/') && (argv[1][2] == '\0' || argv[1][3] == '\0')) ||
        strlen(argv[1]) < 2 || strlen(argv[1]) > 3) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    FILE *input = fopen(argv[2], "r"); // возвр указатель на структуру FILE (где вся инфа о файле)
    if (input == NULL) { // NULL это указатель на нулевой адрес
        printf("Error with open file\n");
        return OPEN_FILE_ERROR;
    }


    FILE *output = NULL;
    char *outfile_path = NULL;
    int len_flag = strlen(argv[1]);

    if (len_flag == 3) { // есть n
        if (argc != 4) {
            printf("Error: uncorrect input\n");
            fclose(input);
            return INVALID_INPUT;
        } else if (argv[1][1] == 'n') {
            outfile_path = (char *) malloc((strlen(argv[3])) * sizeof(char));
            if (outfile_path == NULL) {
                printf("Error with memory\n");
                fclose(input);
                return INVALID_MEMORY;
            }

            if (argv[1][1] == 'n') {
                char *last_slesh = strrchr(argv[2], '/');
                char *last_slesh_2 = strrchr(argv[3], '/');
                if (strcmp(last_slesh + 1, last_slesh_2 + 1) == 0) {
                    printf("Error: uncorrect input\n");
                    fclose(input);
                    return INVALID_INPUT;
                }
            }


            strcpy(outfile_path, argv[3]);
            output = fopen(argv[3], "w");
            if (output == NULL) {
                printf("Error with open file\n");
                fclose(input);
                return OPEN_FILE_ERROR;
            }
        } else {
            printf("Error: uncorrect input\n");
            fclose(input);
            return INVALID_INPUT;
        }
    } else {
        if (argc != 3) {
            printf("Error: uncorrect input\n");
            fclose(input);
            return INVALID_INPUT;
        }
        outfile_path = (char *) malloc((strlen(argv[2]) + 6) * sizeof(char));
        if (outfile_path == NULL) {
            printf("Error with memory\n");
            fclose(input);
            return INVALID_MEMORY;
        }


        char *last_slesh = strrchr(argv[2], '/');
        if (last_slesh == NULL) {
            strcpy(outfile_path, "out_"); // копирование строки
            strcat(outfile_path, argv[2]); // конкатенация path + argv[2]
        } else {
            int len_end = strlen(last_slesh);
            strncpy(outfile_path, argv[2], strlen(argv[2]) - len_end); // копируем весь путь кроме того что после последнего слеша
            outfile_path[strlen(argv[2]) - len_end] = '\000'; // для завершения копирования добавляем \0 в конец
            strcat(outfile_path, "/out_"); // + out_
            strcat(outfile_path, last_slesh + 1); // + filename.txt
        }


        output = fopen(outfile_path, "w");
        if (output == NULL) {
            printf("Error with open file\n");
            fclose(input);
            return OPEN_FILE_ERROR;
        }
    }


    switch (argv[1][len_flag - 1]) {
        case 'd':
            Delete_n(input, output);
            printf("Complite:\nthe address of the file with the result: %s\n", outfile_path);
            break;

        case 'i':
            Count_l(input, output);
            printf("Complite:\nthe address of the file with the result: %s\n", outfile_path);
            break;

        case 's':
            Count_s(input, output);
            printf("Complite:\nthe address of the file with the result: %s\n", outfile_path);
            break;

        case 'a':
            Ascii(input, output);
            printf("Complite:\nthe address of the file with the result: %s\n", outfile_path);
            break;

        default:
            printf("Error uncorrect flag: %s\n", argv[1]);
            fclose(input);
            fclose(output);
            return INVALID_INPUT;
    }

    fclose(input);
    fclose(output);
    free(outfile_path);
    return 0;
}


