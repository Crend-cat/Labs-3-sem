#include "head1.9.h"

enum Errors Stroka_to_lint(const char *str, long int * answer, int base){
    char *endptr;
    *answer = strtol(str, &endptr, base);
    if(*answer == LONG_MAX || *answer == LONG_MIN){
        return INVALID_INPUT;
    }
    else if(endptr == str){ //ниче не преобразовали
        return INVALID_INPUT;
    }
    else if(*endptr != '\0'){ //чето осталось
        return INVALID_INPUT;
    }
    else{
        return OK;
    }
}

enum Errors Arr_gen(long int begin, long int end, long int ** answer, int size){

    (*answer) = (long int *) malloc(size * sizeof(long int));
    if ((*answer) == NULL)
    {
        return INVALID_MEMORY;
    }
    srand(time(NULL)); // иниц генератора. time для rand() иначе одна и та же пос-ть будет всегда гененриться
    for(int i = 0; i < size; ++i)
    {
        (*answer)[i] = rand() % (labs(end) + 1 - labs(begin)) + begin; // % целое число = от 0 до разницы между begin и end
    }
    return OK;
}


void Swap_min_max(long int **answer_arr, int size) {

    int min_ind = 0;
    int max_ind = 0;
    for (int i = 0; i < size; ++i) {
        if ((*answer_arr)[i] < (*answer_arr)[min_ind]) {
            min_ind = i;
        }
        if ((*answer_arr)[i] > (*answer_arr)[max_ind]) {
            max_ind = i;
        }
    }
    long int temp = (*answer_arr)[max_ind];
    (*answer_arr)[max_ind] = (*answer_arr)[min_ind];
    (*answer_arr)[min_ind] = temp;
}


enum Errors Arr_gen2(int begin_2, int end_2, short ** answer_arr_2, int size_2){
    (*answer_arr_2) = (short *) malloc(size_2 * sizeof(short));
    if ((*answer_arr_2) == NULL)
    {
        return INVALID_MEMORY;
    }
    //srand(time(NULL));
    for(int i = 0; i < size_2; ++i)
    {                   // опять от 0 до end - begin (+begin чтобы с begin начало было)
        (*answer_arr_2)[i] = (short )(rand() % (end_2 + 1 - begin_2) + begin_2);
    }                       // short для экономии памяти 2 байта us 4 байта
    return OK;
}

enum Errors Arr_gen_and_find_closest(short ** arr_a, int size_a, short ** arr_b, int size_b, short ** arr_c){

    (*arr_c) = (short*)malloc(sizeof(short) * size_a);
    if (arr_c == NULL)
    {
        free(arr_a);
        return INVALID_MEMORY;
    }
    (*arr_c) = (short*) malloc(sizeof(short) * size_a);
    bubble_sort(arr_b, size_b);

    for(int i = 0; i < size_a; ++i)
    {
        (*arr_c)[i] = (*arr_a)[i] + find_closest(arr_b, size_b, (*arr_a)[i]);
    }
    return OK;
}


void bubble_sort(short** arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((*arr)[j] > (*arr)[j+1]) {
                short temp = (*arr)[j];
                (*arr)[j] = (*arr)[j+1];
                (*arr)[j+1] = temp;
            }
        }
    }
}

short find_closest(short **arr, int size, short number)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // средний индекс

        if ((*arr)[mid] == number)
        {
            return (*arr)[mid];
        }


        if ((*arr)[mid] < number)
        {
            low = mid + 1; // сдвигаем границу
        }

        else
        {
            high = mid - 1;
        }
    }

    // Теперь мы между arr[low] и arr[high]
    if (low >= size)
        return (*arr)[size - 1];
    if (high < 0)
        return (*arr)[0];

    if (abs((*arr)[low] - number) < abs((*arr)[high] - number))
    {
        return (*arr)[low];
    }
    else
    {
        return (*arr)[high];
    }
}
 // из while выходим когда нижняя граница уезжает дальше вершней
// если разница первого - число меньше второго - число значит первый иначе второй



