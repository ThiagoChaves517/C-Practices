#include "matematica.h"

int POW(int x, int y){
    if(y == 0){
        return 1;
    }

    return POW(x,--y) * x;
}

int square(int x){
    return x * x;
}