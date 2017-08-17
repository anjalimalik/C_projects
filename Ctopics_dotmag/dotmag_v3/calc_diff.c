// @author Anjali Malik

#include <stdio.h>
#include "dotheader.h"

void calc_diff(int vecsize, float *x, float *y, float *u){
    int i = 0;
    for(i = 0; i < vecsize; i++){
        u[i] = y[i] - x[i];
    }
    
}
