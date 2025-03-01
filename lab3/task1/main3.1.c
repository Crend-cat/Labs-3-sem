#include "head3.1.h"

int main(){

    char answer[128];
    int size = 0;

    if(To_xbase(0, 2, answer, &size)){
        printf("Error, incorrect input\n");
        return INVALID_INPUT;
    }


    Print_answer(answer, size);
}