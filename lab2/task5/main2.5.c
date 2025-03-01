#include "stdio.h"

int fastpow(int a, int step){
    int res = 1;
    while(step > 0){
        if(step & 1){
            res *= a;
        }
        else{
            res *= res;
        }
    }
    return res;
}


int main(){
    int r = fastpow(2, 5);
    printf("%d", r);
    return 0;
}




