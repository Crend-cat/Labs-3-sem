#include "head3.1.h"

int Add( int x, int y){
    int a = (x & y) << 1;
    int b = x ^ y;
    if( a == 0){
        return b;
    }
    return Add(a, b);
}

int Minus(int x){
    return Add(~x,1);
}

enum Errors To_xbase(int num, int a, char *answer, int *size){
    int mask;
    int d;
    char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV", flag = 0;
    *size = 0;

    if(!answer || a < 1 || a > 5){
        return INVALID_INPUT;
    }
    if(num < 0){
        num = Minus(num);
        flag = '1';
    }

    do{
        mask = Add(1 << a, -1); // 3
        d = num & mask;   // 13 & 3..
        num >>= a;
        answer[*size] = base[d];
        *size = Add(*size, 1);
    } while(num);

    if(flag){
        answer[*size] = '-';
        *size = Add(*size, 1);
    }
    return OK;
}

void Print_answer( char *answer, int size){
    int i;
    printf("Answer: ");
    for(i = Add(size, -1); i >= 0; i = Add(i, -1)){
        printf("%c", answer[i]);
    }
    printf("\n");
}