#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

/* МАССИВЫ
int f1(int *x, int a){
    for(int i = 0; i < a; ++i){
        printf("%d", x[i]);
    }
    printf("\n");
    return 0;
}

int f2(int y[][3], int a, int b){
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < b; ++j){
            printf("%d", y[i][j]);
        }
    }
    printf("\n");
    return 0;
}

int f3(int z[][3][2], int a, int b, int c){
    for(int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < c; ++k) {
                printf("%d", z[i][j][k]);
            }
        }
    }
    return 0;
}

int main(){
    int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int y[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int z[2][3][2] = {0, 1, 2, 3,4, 5, 6, 7, 8, 9};
    f1(x, 10);
    f2(y, 3, 3);
    f3(z, 2, 3, 2);
    return 0;
}*/

/* КОНКАТЕНАЦИЯ СТРОК
char* Concat(char *s, char* first, ...){
    s[0] = '\0';
    char *conc;
    va_list p;
    va_start(p, first);
    strcat(s, first);
    while((conc = va_arg(p, char*))!= NULL){
        strcat(s, conc);
    }
    va_end(p);
    return s;
}

int main(){
    char s[BUFSIZ];
    printf("%s", Concat(s, "fer", "ra", "ri", NULL));
    printf("\n");
    return 0;
}*/


/* ГОРНЕР
int str_to_int(char *s, int base){
    int result = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        int num = 0;
        if(s[i] >= '0' && s[i] <= '9') num = s[i] - '0';
        else if(s[i] >= 'A' && s[i] <= 'Z') num = s[i] - 'A' + 10;
        else if(s[i] >= 'a' && s[i] <= 'z') num = s[i] - 'a' + 10;
        result = result * base + num;
    }
    return result;
}

// ОБРАТНЫЙ ГОРНЕР
void reverse(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}


void int_to_str(int num, int base, char *result)
{
    int i = 0;
    while (num > 0)
    {
        int digit = num % base;
        if (digit < 10) {
            result[i++] = '0' + digit;
        } else {
            result[i++] = 'A' + digit - 10;
        }
        num /= base;
    }
    result[i] = '\0';
    reverse(result); // переворачиваем строку, так как мы добавляли символы в обратном порядке
}


int main(){
    char* s = "1235";
    char t[30];
    printf("%d\n", str_to_int(s, 10));
    int_to_str(10341, 10, t);
    printf("%s\n", t);
}*/

int Replace(int num, int p1, int p2){
    int bit1 = (num >> p1) & 1;
    int bit2 = (num >> p2) & 1;

    int x = bit1 ^ bit2;
    x = (x << p1) | (x << p2);
    int r = num ^ x;
    return r;
}

int main(){
    printf("%d\n", Replace(23, 1, 3));
    return 0;
}
