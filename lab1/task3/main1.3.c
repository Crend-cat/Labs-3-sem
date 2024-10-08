#include "head1.3.h"

int main(int argc, char* argv[]){

    if( argc < 4){
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    if(!((argv[1][0] == '-' || argv[1][0] == '/') && argv[1][2] == '\0') ) {
        printf("Error: uncorrect input\n");
        return INVALID_INPUT;
    }

    switch(argv[1][1]) {

        case 'q':
            if (argc != 6) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            long double eps, coef1, coef2, coef3;
            if (Stroka_to_ldouble(argv[2], &eps) != OK || Stroka_to_ldouble(argv[3], &coef1) != OK ||
                Stroka_to_ldouble(argv[4], &coef2) != OK || Stroka_to_ldouble(argv[5], &coef3) != OK || eps <= 0) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            int size_arr = 3;
            int count_p = 0;
            long double **answer = (long double **) malloc(6 * sizeof(long double *));
            // массив с указателями на массивы (6* на размер 1 указателя на вариант перестановки) 6 патаму что сущ 6 вариантов перестановки 3 элементов
            long double *arr_coef = (long double *) malloc(3 * sizeof(long double));
            if ((answer == NULL) || (arr_coef == NULL)) {
                free(answer);
                free(arr_coef);
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            arr_coef[0] = coef1;
            arr_coef[1] = coef2;
            arr_coef[2] = coef3;
            enum Errors stat = Perestan(&answer, 0, size_arr - 1, &count_p, arr_coef, eps);
            if (stat != OK) {
                for (int i = 0; i < count_p; ++i) {
                    free(answer[i]);
                }
                free(arr_coef);
                free(answer);
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            for (int i = 0; i < count_p; ++i) {
                printf("Квадратное уравнение (%d) %Lfx^2 + %Lfx + %Lf\n", i + 1, answer[i][0], answer[i][1],
                       answer[i][2]);
                long double a = answer[i][0];
                long double b = answer[i][1];
                long double c = answer[i][2];

                long double disc = b * b - 4.0 * a * c;
                if (disc < 0) {
                    printf("Действительных корней нет\n");
                } else {
                    disc = sqrt(disc);
                    b *= -1.0;
                    long double x1 = (b - disc) / (2.0 * a);
                    long double x2 = (b + disc) / (2.0 * a);
                    printf("x1 = %Lf\t", x1);
                    printf("x2 = %Lf\n", x2);
                }
                printf("\n");
            }

            for (int i = 0; i < count_p; ++i) {
                free(answer[i]);
            }
            free(answer);
            free(arr_coef);
            break;

        case 'm':
            if (argc != 4) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            long int x1, x2;
            if (Stroka_to_lint(argv[2], &x1, 10) != OK || (Stroka_to_lint(argv[3], &x2, 10) != OK)) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }
            if (x1 == 0 || x2 == 0) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            if (x1 % x2 == 0) {
                printf("Число %ld делится на %ld без остатка\n", x1, x2);
            } else {
                printf("Число %ld не делится на %ld без остатка\n", x1, x2);
            }
            break;

        case 't':
            if (argc != 6) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }
            long double a1, a2, a3, epss;
            if (Stroka_to_ldouble(argv[2], &epss) != OK || Stroka_to_ldouble(argv[3], &a1) != OK ||
                Stroka_to_ldouble(argv[4], &a2) != OK || Stroka_to_ldouble(argv[5], &a3) != OK) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }

            int ded = 0;
            enum Errors stat_t = Treygolnic(epss, a1, a2, a3, &ded);
            if (stat_t == OVERFLOW_ERROR) {
                printf("Error: overflow\n");
                return OVERFLOW_ERROR;
            } else if (stat_t == INVALID_INPUT) {
                printf("Error: uncorrect input\n");
                return INVALID_INPUT;
            }
            if (ded == 1) {
                printf("Treygolnic pryamoygolnyi\n");
            } else {
                printf("Treygolnic ne pryamoygolnyi\n");
            }
            break;

        default:
            printf("Error uncorrect flag: %s\n", argv[1]);
            break;
    }
    return 0;

}

// 0.1 1 2 1
