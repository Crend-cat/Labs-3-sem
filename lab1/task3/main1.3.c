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


            long double **answer = (long double **)malloc(6 * sizeof(long double *));
            // массив с указателями на массивы (6* на размер 1 указателя на вариант перестановки) 6 патаму что сущ 6 вариантов перестановки 3 элементов
            if (answer == NULL){
                free(answer);
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }

            enum Errors stat;
            stat = GeneratePermutation(&answer, coef1, coef2, coef3);
            if (stat != OK) {
                printf("Error with memory\n");
                return INVALID_MEMORY;
            }


            for (int i = 0; i < 6; ++i) {
                printf("The quadratic equation (%d) %Lfx^2 + %Lfx + %Lf\n", i + 1, answer[i][0], answer[i][1],
                       answer[i][2]);
                 double a = answer[i][0];
                 double b = answer[i][1];
                 double c = answer[i][2];

                if (fabsl(a) <= eps) {  // Если коэффициент при x^2 равен 0
                    if (fabsl(b) <= eps) {
                        if (fabsl(c) <= eps) {
                            printf("Infinite number of solutions\n");
                            printf("\n");
                        } else {
                            printf("No solutions\n");
                            printf("\n");
                        }
                    } else {  //линейное уравнение bx + c = 0
                        double x = -c / b;
                        if(fabs(x) == 0){
                            printf("Linear equation: x = 0\n");
                            printf("\n");
                        }
                        else {
                            printf("Linear equation: x = %f\n", x);
                            printf("\n");
                        }
                    }
                }
                else{

                    double disc = b * b - 4.0 * a * c;
                    if (disc < 0.0) {
                        printf("There are no valid roots\n");
                    } else {
                        disc = sqrt(disc);
                        b *= -1.0;
                        double x1 = (b - disc) / (2.0 * a);
                        double x2 = (b + disc) / (2.0 * a);

                        if((fabs(x1) == 0) && (fabs(x2) == 0)){
                            printf("Linear equation: x = 0\n");
                        }
                        else {
                            printf("x1 = %f\t", x1);
                            printf("x2 = %f\n", x2);
                        }
                    }
                    printf("\n");
                }
            }


            for (int i = 0; i < 6; ++i) {
                free(answer[i]);
            }
            free(answer);
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
                printf("The number %ld is divided by %ld without remainder\n", x1, x2);
            } else {
                printf("The number %ld is not divided by %ld without remainder\n", x1, x2);
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
