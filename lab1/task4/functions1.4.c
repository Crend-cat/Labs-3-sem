#include "head1.4.h"

int Compare_paths(const char *path1, const char *path2){
    int a1 = 0, a2 = 0;
    if (path1[0] == '.' && path1[1] == '.') {
        a1 = 2;
    } else if (path1[0] == '.') {
        a1 = 1;
    }
    if (path2[0] == '.' && path2[1] == '.') {
        a2 = 2;
    }
    else if (path2[0] == '.') {
        a2 = 1;
    }

    int len1 = strlen(path1);
    int len2 = strlen(path2);

    while (len1 > 0 && path1[len1 - 1] == '/') len1--;
    while (len2 > 0 && path2[len2 - 1] == '/') len2--;


    while (len1 > a1 && len2 > a2) {
        if (path1[len1 - 1] != path2[len2 - 1]){
            return 0;
        }
        len1--;
        len2--;
    }

    return (len1 == a1 || len2 == a2);
}

enum Errors Delete_a(const char *in, const char *out)
{

    FILE *f1 = fopen(in, "r");
    FILE *f2 = fopen(out, "w");
    if (!f1 || !f2)
    {
        if (f1) {
            fclose(f1);
        }
        if (f2) {
            fclose(f2);
        }
        return OPEN_FILE_ERROR;
    }

    char c;
    while ((c = fgetc(f1)) != EOF)
    {
        if (c < '0' || c > '9') {
            fputc(c, f2);
        }
    }

    fclose(f1);
    fclose(f2);
    return OK;
}

enum Errors Count_l(const char *in, const char *out)
{
    FILE *f1 = fopen(in, "r");
    FILE *f2 = fopen(out, "w");
    char c;
    int k = 0;
    if (!f1 || !f2)
    {
        if (f1) {
            fclose(f1);
        }
        if (f2) {
            fclose(f2);
        }
        return OPEN_FILE_ERROR;
    }

    while ((c = fgetc(f1)) != EOF)
    {
        if (isalpha(c))
        {
            k++;
        }
        if (c == '\n')
        {
            fprintf(f2, "%d\n", k);
            k = 0;
        }
    }

    fclose(f1);
    fclose(f2);
    return OK;
}

enum Errors Count_s(const char *in, const char *out)
{
    FILE *f1 = fopen(in, "r");
    FILE *f2 = fopen(out, "w");
    char c;
    int k = 0;
    if (!f1 || !f2)
    {
        if (f1) {
            fclose(f1);
        }
        if (f2) {
            fclose(f2);
        }
        return OPEN_FILE_ERROR;
    }
    while ((c = fgetc(f1)) != EOF)
    {
        fputc(c, f2);
        if (!isalpha(c) && !isdigit(c) && c != ' ')
        {
            k++;
        }
        if (c == '\n')
        {
            fprintf(f2, "%d\n\n", k - 2);
            k = 0;
        }
    }

    fclose(f1);
    fclose(f2);
    return OK;
}

enum Errors Ascii(const char *in, const char *out)
{
    FILE *f1 = fopen(in, "r");
    FILE *f2 = fopen(out, "w");
    char c;
    if (!f1 || !f2)
    {
        if (f1) {
            fclose(f1);
        }
        if (f2) {
            fclose(f2);
        }
        return OPEN_FILE_ERROR;
    }
    while ((c = fgetc(f1)) != EOF)
    {
        if ((c >= '0' && c <= '9') || c == '\n')
        {
            fputc(c, f2);
        }
        else
        {
            fprintf(f2, "%X", c);
        }
    }

    fclose(f1);
    fclose(f2);
    return OK;
}