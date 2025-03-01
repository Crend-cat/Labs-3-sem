#include <stdio.h>

int binpow(int base, int step){
    int res = 1;
    while(step){
        if(step & 1){
            res *= base;
            --step;
        }
        base *= base;
        step >>= 1;
    }
    return res;
}

int main(){
    printf("%d\n", binpow(2, 5));
}