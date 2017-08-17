// @author Anjali Malik

#include <stdio.h>
#include "dotheader.h"

void calc_diff(int vecsize, float *x, float *y, float **u){
    int i = 0;

    // Using for loop to get difference of elements in x & y vectors
    for(i = 0; i < vecsize; i++){
        ((*u)[i]) = y[i] - x[i];
    }
    
}
