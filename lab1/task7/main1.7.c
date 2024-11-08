#include "stdio.h"

union Un{
    int a;
    double b;
    char c;
};

long long fast_pow(long long base, int step){
    long long answer = 1;
    while(step > 0){
        if(step % 2 == 1){
            answer *= base;
        }
        base *= base;
        step /= 2;

    }
    return answer;
}


int main(){
    union Un ptr;
    ptr.a = 2;

    printf("%lld", fast_pow(ptr.a, 5));

}