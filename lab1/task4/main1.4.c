#include "head1.4.h"

int main(int argc, char* argv[]) // имя  -nd (-d) input out (нет out)
{
    if (argc < 3 || (argv[1][0] != '-' && argv[1][0] != '/')) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    const char *in = argv[2];
    char *out = NULL;
    char flag;
    int free_out = 0;
    if (argv[1][1] == 'n' && (argc < 4 || strlen(argv[1]) != 3 || (strcmp(argv[2], argv[3]) == 0))) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    } else if (argv[1][1] != 'n' && (argc != 3 || strlen(argv[1]) != 2)) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    if (argv[1][1] == 'n') {
        flag = argv[1][2];
        out = argv[3];
        if (Compare_paths(in, out) == 1) {
            printf("Error: uncorrect input\n");
            return INVALID_INPUT;
        }
    }
    else {
        flag = argv[1][1];
        char *name = strrchr(in, '/');
        if (name == NULL) {
            name = (char *) in;
        }
        else name++;
        free_out = 1;
        out = (char *)malloc(sizeof(char) * (strlen(name) + 5));
        if (out == NULL) {
            printf("Error with memory\n");
            return INVALID_MEMORY;
        }
        sprintf(out, "out_%s", name); // out_ + file.txt
    }

        printf("Complite, check out_file\n");


        switch (flag) {
            case 'd':
                if (Delete_a(in, out) != OK) {
                    printf("Error with open file\n");
                    return OPEN_FILE_ERROR;
                }
                break;
            case 'i':
                if (Count_l(in, out) != OK) {
                    printf("Error with open file\n");
                    return OPEN_FILE_ERROR;
                }
                break;
            case 's':
                if (Count_s(in, out) != OK) {
                    printf("Error with open file\n");
                    return OPEN_FILE_ERROR;
                }
                break;
            case 'a':
                if (Ascii(in, out) != OK) {
                    printf("Error with open file\n");
                    return OPEN_FILE_ERROR;
                }
                break;
            default:
                printf("Error uncorrect flag: %s\n", argv[1]);
                break;
        }

        if (free_out) {
            free(out);
            return OK;
        }

}

