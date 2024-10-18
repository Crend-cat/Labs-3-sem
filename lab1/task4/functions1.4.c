#include "head1.4.h"

void Delete_n(FILE *in, FILE *out)
{
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        if (c >= '0' && c <= '9')
            continue;
        fputc(c, out);
    }
}

void Count_l(FILE *in, FILE *out)
{
    int c, count_letters = 0;

    while ((c = fgetc(in)) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            count_letters++;
        }
        else if (c == '\n')
        {
            fprintf(out, "%d\n", count_letters);
            count_letters = 0;
        }
    }
    if (count_letters)
        fprintf(out, "%d\n", count_letters);
}

void Count_s(FILE *in, FILE *out)
{
    int c, count_letters = 0;

    while ((c = fgetc(in)) != EOF)
    {
        if (c == '\n')
        {
            fprintf(out, "%d\n", count_letters + 1);
            count_letters = 0;
        }
        else if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' '))
        {
            count_letters++;
        }
    }
    if (count_letters)
        fprintf(out, "%d\n", count_letters);
}

void Ascii(FILE *in, FILE *out)
{
    int c, i;
    char num_base16[2];
    while ((c = fgetc(in)) != EOF)
    {
        if (isdigit(c))
            fputc(c, out);

        else if(c == '\n'){
            fputc('\n', out);
        }
        else
        {
            i = 0;
            while (c)
            {
                if(c % 16 > 9){
                    num_base16[i++] = (c % 16 - 10 + 'A');
                }
                else{
                    num_base16[i++] = (c % 16 + '0');
                }
                c /= 16;
            }
            if (i > 0)
                fputc(num_base16[1], out); // если 1> символа то записываем второй
            if (i > 1)
                fputc(num_base16[0], out); //
        }
    }
}