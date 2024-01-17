#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int64_t laske_kertoma(int8_t n);

int64_t laske_kertoma(int8_t n){
    if(n > 20) return -1;

    int64_t summa = n;
    for(int8_t i = n-1; i > 1; i--){
        summa *= i;
    }
    return summa;
}

